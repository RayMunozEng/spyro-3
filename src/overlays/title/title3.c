#include "matching.h"
#include "common.h"
#include "loaders.h"
#include "stdutil.h"
#include "str.h"
typedef struct {
    int offset, length;
} DecodedArchiveEntry;
typedef struct {
    int count;
    unsigned int reserved04[12];
    unsigned int offset34, offset38;
    unsigned int records[1];
} DecodedRelocationHeader;
typedef struct {
    unsigned int reserved00[3];
    unsigned int offset0C, offset10, offset14;
    int unk18, unk1C;
    unsigned int offset20;
} DecodedRelocationRecord;

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
void SharedEnvironmentFinish(char*, int) __asm__("func_8002C9F4");
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
char* func_title_80079744(char* input) {
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
    SharedEnvironmentFinish(block + 4, 1);
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
void func_title_80079B94(void) {
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

extern int D_8006EDEC, D_8006EDF0, D_8006EDFC, D_8006EE00, D_8006EE04;
extern int D_8006C58C, D_8006E470;
extern int* D_8006EDF4;
extern int* D_8006EDF8;
extern int* D_8006EE10;
extern unsigned char* D_8006EE08;
extern unsigned char* D_8006EE0C;
extern DecodedRelocationHeader* D_8006EE2C[];
extern Moby* D_8006C550;
extern WadHeader D_8006D8D8;
void func_title_80079D30(unsigned char* base, int load) {
    int* cursor = (int*)base;
    int firstCount, offset, length;
    register int byteLength __asm__("$6");
    int index;
    register int* copyStart __asm__("$4");
    register int actorOffset __asm__("$2");
    DecodedRelocationHeader** modelTable;
    /* Eight unused retail stack bytes; original purpose remains unknown. */
    int reservedStack[2];
    D_8006EDEC = *cursor++ * 2;
    firstCount = *cursor++;
    D_8006EDF0 = firstCount;
    D_8006EDFC = *cursor++;
    offset = *cursor++;
    D_8006EE00 = offset;
    length = *cursor++;
    D_8006EDF4 = cursor;
    cursor += firstCount;
    D_8006EDF8 = cursor;
    D_8006EE08 = base + offset;
    D_8006EE04 = length;
    D_8006EE0C = base + offset + length;
    cursor += firstCount;
    if (load) {
        CDLoadSync(D_8006E470, base + 0x800, offset + *D_8006EDF8 - 0x800,
                   D_8006D8D8.cutscene[D_8006C58C].mdls.offset + 0x800);
    }
    actorOffset = *cursor++;
    MATCHING_KEEP2_VOLATILE_CLOBBER(cursor, actorOffset, "memory");
    modelTable = D_8006EE2C;
    {
        register int copyOffset __asm__("$4") = D_8006EE00;
        MATCHING_OBSERVE_VOLATILE_CLOBBER(copyOffset, "memory");
        byteLength = D_8006EDFC * 4;
        copyStart = (int*)(base + copyOffset - byteLength);
    }
    __asm__ volatile("" : "=r"(actorOffset) : "0"(actorOffset), "r"(copyStart));
    D_8006C550 = (Moby*)(base + actorOffset);
    D_8006EE10 = copyStart;
    func_8004E7D4(copyStart, (int*)modelTable, byteLength);
    index = 0;
    if (D_8006EDFC > 0) {
        unsigned int byteOffset = 0;
        DecodedRelocationHeader** entry = modelTable;
        do {
            DecodedRelocationHeader* header = (DecodedRelocationHeader*)(base + *cursor++);
            int retainedHalfword;
            Moby* actor;
            *entry = header;
            if (header->count < 0) {
                func_8002AF9C((int*)header, index, (int*)0x80800000);
            } else {
                if (header->offset34 != 0)
                    header->offset34 = (unsigned int)header + header->offset34;
                if ((*entry)->offset38 != 0)
                    (*entry)->offset38 = (unsigned int)*entry + (*entry)->offset38;
            }
            actor = (Moby*)(byteOffset + (unsigned int)D_8006C550);
            retainedHalfword = actor->distanceToGround;
            func_8004E790(actor, 0, sizeof(Moby));
            {
                register int lowDistance __asm__("$2") = 0x20;
                __asm__ volatile("" : "=r"(lowDistance) : "0"(lowDistance), "r"(retainedHalfword));
                entry++;
                {
                    register Moby* current __asm__("$3") =
                        (Moby*)(byteOffset + (unsigned int)D_8006C550);
                    current->lowDrawDistance = lowDistance;
                    current->mobyClass = index;
                }
            }
            ((Moby*)(byteOffset + (unsigned int)D_8006C550))->highDrawDistance = 0x40;
            {
                register Moby* current __asm__("$3") =
                    (Moby*)(byteOffset + (unsigned int)D_8006C550);
                current->subtype = 0xFF;
            }
            {
                register Moby* current __asm__("$2") = D_8006C550;
                __asm__ volatile("" : "=r"(index) : "0"(index), "r"(current));
                index++;
                current = (Moby*)(byteOffset + (unsigned int)current);
                current->distanceToGround = retainedHalfword;
            }
            MATCHING_BARRIER_VOLATILE("memory");
            byteOffset += sizeof(Moby);
        } while (index < D_8006EDFC);
    }
    D_8006C550[D_8006EDFC].state = 0xFF;
}

extern int D_8006C76C, D_8006EDE8, D_8006EDFC;
extern DecodedRelocationHeader* D_8006EE2C[];
void func_80064A2C(unsigned int);
void func_80064A8C(void*, int);
int func_80064AEC(int);
void func_title_80079FE0(unsigned char* base, int recordIndex, int mode) {
    DecodedArchiveEntry* archive;
    int length;
    register int address __asm__("$4");
    /* Retail reserves these eight unused stack bytes; their original purpose is unknown. */
    int reservedStack[2];
    int index;
    DecodedRelocationHeader** entry;
    register int* initialCount __asm__("$3");
    D_8006EDE8 = recordIndex;
    archive = (DecodedArchiveEntry*)(base + D_8006C76C * 8);
    length = archive->length;
    if (mode != 0)
        address = length * (recordIndex & 1) + 0x1010;
    else {
        address = 0x21010;
        address += length * recordIndex;
    }
    func_80064A2C(address);
    func_80064A8C(base + archive->offset, length);
    while (func_80064AEC(0) == 0) {
    }
    index = 0;
    initialCount = &D_8006EDFC;
    if (*initialCount > 0) {
        register volatile int* count __asm__("$8");
        register int recordByteOffset __asm__("$6") = recordIndex * 4;
        int currentCount;
        __asm__ volatile("" : "=r"(initialCount) : "0"(initialCount), "r"(recordByteOffset));
        count = initialCount;
        entry = D_8006EE2C;
        do {
            if ((int)*entry < 0 && recordIndex < (*entry)->count) {
                (*entry)->records[recordIndex] =
                    (unsigned int)base + (*entry)->records[recordIndex];
                ((DecodedRelocationRecord*)(*entry)->records[recordIndex])->offset0C =
                    (unsigned int)base +
                    ((DecodedRelocationRecord*)(*entry)->records[recordIndex])->offset0C;
                {
                    DecodedRelocationHeader* header = *entry;
                    DecodedRelocationRecord* record =
                        (DecodedRelocationRecord*)header->records[recordIndex];
                    record->offset10 = (unsigned int)header + record->offset10;
                }
                {
                    DecodedRelocationHeader* header = *entry;
                    DecodedRelocationRecord* record =
                        (DecodedRelocationRecord*)header->records[recordIndex];
                    record->offset14 = (unsigned int)header + record->offset14;
                }
                ((DecodedRelocationRecord*)(*entry)->records[recordIndex])->unk18 = 0;
                ((DecodedRelocationRecord*)(*entry)->records[recordIndex])->unk1C = 0;
                ((DecodedRelocationRecord*)(*entry)->records[recordIndex])->offset20 =
                    (unsigned int)base +
                    ((DecodedRelocationRecord*)(*entry)->records[recordIndex])->offset20;
            }
            currentCount = *count;
            /* Preserve the retail load before the loop increment, without emitting code. */
            __asm__ volatile("" : "=r"(index) : "0"(index), "r"(currentCount));
            index++;
            entry++;
        } while (index < currentCount);
    }
}

typedef struct {
    Vector3D first;
    int reserved1C;
    Vector3D second;
    int reserved2C;
    Vector3D difference;
    int reserved3C;
    Vector3D firstAngles;
    int reserved4C;
    Vector3D temporary;
    int reserved5C;
    Vector3D secondAngles;
    int reserved6C;
} DecodedCutsceneSamples;
extern int DecodedCutsceneDelta __asm__("D_8006C648");
extern volatile int DecodedCutsceneFrame __asm__("D_8006EDE0");
extern volatile int DecodedCutsceneTick __asm__("D_8006EDE4");
extern volatile int DecodedCutsceneCount __asm__("D_8006EDFC");
extern unsigned char* DecodedCutsceneModels[] __asm__("D_8006EE2C");
extern unsigned char* DecodedCutsceneBanks[] __asm__("D_8006EE08");
extern Moby* volatile DecodedCutsceneMobys __asm__("D_8006C550");
extern Moby* DecodedCutsceneSecondary __asm__("D_8006C704");
extern void (**DecodedCutsceneCallbacks)(Moby*) __asm__("MobyUpdate");
extern void (*DecodedCutsceneParticles)(int) __asm__("UpdateParticles");
extern unsigned char DecodedCutsceneCamera[] __asm__("D_8006E020");
void DecodedCutsceneBegin(int) __asm__("func_80020E74");
void DecodedCutsceneBeginActors(void) __asm__("func_80021FF4");
void DecodedCutsceneBeginFrames(void) __asm__("func_80022158");
void DecodedCutsceneBeginModels(void) __asm__("func_80022260");
void DecodedCutsceneEndActors(void) __asm__("func_800509F0");
void DecodedCutsceneCopy(void*, const void*) __asm__("func_8004F178");
void DecodedCutsceneSubtract(Vector3D*, const Vector3D*, const Vector3D*) __asm__("func_8004F1C8");
void DecodedCutsceneAdd(Vector3D*, const Vector3D*, const Vector3D*) __asm__("func_8004F194");
int DecodedCutsceneLength(const Vector3D*, int) __asm__("func_8004EDE8");
void DecodedCutsceneShift(Vector3D*, int) __asm__("func_8004F110");
void DecodedCutsceneUnpackPosition(Vector3D*, const void*) __asm__("func_8004F52C");
void DecodedCutsceneUnpackAngles(Vector3D*, const void*) __asm__("func_8004F554");
int DecodedCutsceneAngleDifference(int, int) __asm__("func_8004F2C8");
void DecodedCutsceneWriteAngles(void*, const Vector3D*) __asm__("func_8004F570");
#define DECODED_CUTSCENE_ACTOR ((Moby*)(actorOffset + (unsigned int)DecodedCutsceneMobys))
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0 original camera
* instructions are the authority. Actor byte stride 0x58, archive offsets,
* masks, signed shifts, stack slots and branch nesting are retained exactly.
* Helper semantics, coordinate units, record producers and cadence are not
* established here. Empty constraints preserve original compiler lifetimes;
* they emit no instructions. Acceptance requires complete linked words and
* every EXE/overlay hash, independently of this relocation-masked probe.
*/
void func_title_8007A1C0(void) {
    DecodedCutsceneSamples sample;
    int reservedStack[4];
    register int actorIndex __asm__("$21");
    register unsigned int actorOffset __asm__("$17");
    register int tableOffset __asm__("$20");
    register unsigned char** modelCursor __asm__("$19");
    register volatile int* tick __asm__("$22");
    register Vector3D* second __asm__("$18");
    register void* scratch __asm__("$16");
    DecodedCutsceneBegin(DecodedCutsceneDelta);
    DecodedCutsceneBeginActors();
    actorIndex = 0;
    DecodedCutsceneBeginFrames();
    DecodedCutsceneBeginModels();
    {
        register volatile int* count __asm__("$3") = &DecodedCutsceneCount;
        MATCHING_KEEP(count);
        actorOffset = 0;
        if (*count > 0) {
            int loopCount;
            tick = (volatile int*)((char*)count - 0x18);
            tableOffset = 0;
            modelCursor = DecodedCutsceneModels;
            do {
                register int model __asm__("$2") = (int)*modelCursor;
                if (model < 0) {
                    register unsigned char* header __asm__("$5");
                    register unsigned char* record __asm__("$4");
                    register int last __asm__("$8");
                    register int selected __asm__("$6");
                    register int elapsed __asm__("$7");
                    register int duration __asm__("$5");
                    {
                        register volatile int* frame __asm__("$4") = &DecodedCutsceneFrame;
                        MATCHING_KEEP(frame);
                        DECODED_CUTSCENE_ACTOR->animationState.id = *frame;
                        DECODED_CUTSCENE_ACTOR->animationState.nextId = *frame;
                        header = *modelCursor;
                        if (*frame >= *(int*)header) {
                            DECODED_CUTSCENE_ACTOR->animationState.id = 0;
                            DECODED_CUTSCENE_ACTOR->animationState.nextId = 0;
                            DECODED_CUTSCENE_ACTOR->animationState.frame = 0;
                            DECODED_CUTSCENE_ACTOR->animationState.nextFrame = 0;
                            DECODED_CUTSCENE_ACTOR->animationProgress = 0;
                            DECODED_CUTSCENE_ACTOR->lowDrawDistance = 0;
                            DECODED_CUTSCENE_ACTOR->drawn = 0;
                            goto nextEntity;
                        }
                    }
                    record = *(unsigned char**)(header + DecodedCutsceneFrame * 4 + 0x3C);
                    elapsed = 0;
                    if (*record == 1) {
                        DECODED_CUTSCENE_ACTOR->animationState.frame = 0;
                        DECODED_CUTSCENE_ACTOR->animationState.nextFrame = 0;
                        goto clearProgress;
                    } else {
                        register int frameTick __asm__("$9");
                        register int countMinusOne __asm__("$2") = *record - 1;
                        MATCHING_KEEP(countMinusOne);
                        selected = 0;
                        if (countMinusOne > 0) {
                            frameTick = *tick;
                            last = countMinusOne;
                            __asm__("" : "=r"(last) : "0"(last), "r"(frameTick));
                            do {
                                {
                                    register int packedDuration __asm__("$2") =
                                        *(int*)(record + 0x28) & 0x1E00;
                                    MATCHING_KEEP(packedDuration);
                                    duration = (packedDuration >> 9) + 1;
                                }
                                if (frameTick < elapsed + duration) {
                                    DECODED_CUTSCENE_ACTOR->animationState.frame = selected;
                                    {
                                        register Moby* frameActor __asm__("$2") =
                                            DecodedCutsceneMobys;
                                        register int nextFrame __asm__("$3");
                                        __asm__ __volatile__("" : : : "$3", "memory");
                                        nextFrame = selected + 1;
                                        MATCHING_KEEP(nextFrame);
                                        frameActor =
                                            (Moby*)(actorOffset + (unsigned int)frameActor);
                                        frameActor->animationState.nextFrame = nextFrame;
                                    }
                                    {
                                        register int progress __asm__("$2") =
                                            ((*tick - elapsed) * 16) / duration;
                                        register Moby* actor __asm__("$3") = DECODED_CUTSCENE_ACTOR;
                                        __asm__("" : "=r"(actor) : "0"(actor), "r"(progress));
                                        actor->animationProgress = progress;
                                    }
                                    goto checkLastRecord;
                                }
                                elapsed += duration;
                                selected++;
                                record += 8;
                            } while (selected < last);
                        }
                    checkLastRecord:
                        {
                            register unsigned char* lastRecord __asm__("$2") =
                                *(unsigned char**)(*modelCursor + DecodedCutsceneFrame * 4 + 0x3C);
                            MATCHING_KEEP(lastRecord);
                            if (selected == *lastRecord - 1) {
                                DECODED_CUTSCENE_ACTOR->animationState.frame = selected;
                                DECODED_CUTSCENE_ACTOR->animationState.nextFrame = selected;
                            clearProgress:
                                DECODED_CUTSCENE_ACTOR->animationProgress = 0;
                            }
                        }
                    }
                    {
                        /* First/second bank producers and packed XYZ loads retain
                        * original interleaving; no source-domain conversion inferred. */
                        register Moby* moby __asm__("$5");
                        register int yMask __asm__("$9") = 0xF0000;
                        register int xMask __asm__("$8") = 0x3FF00000;
                        register volatile int* volatile firstRecord __asm__("$4");
                        register volatile int* volatile secondRecord __asm__("$6");
                        register int index __asm__("$2");
                        register int frame __asm__("$3");
                        register int secondOffset __asm__("$7");
                        register Vector3D* subtractFirst __asm__("$5");
                        register Vector3D* subtractDestination __asm__("$4");
                        MATCHING_KEEP2(yMask, xMask);
                        yMask |= 0xFC00;
                        __asm__ __volatile__("" : "=r"(yMask) : "0"(yMask), "r"(xMask) : "memory");
                        moby = DECODED_CUTSCENE_ACTOR;
                        index = moby->animationState.id;
                        __asm__ __volatile__("" : : : "$16", "memory");
                        scratch = &sample.difference;
                        index = (index & 1) * 4;
                        firstRecord =
                            *(volatile int**)((unsigned char*)DecodedCutsceneBanks + index);
                        __asm__ __volatile__("" : : : "$3", "memory");
                        frame = moby->animationState.frame;
                        index = tableOffset + (int)firstRecord;
                        MATCHING_KEEP(index);
                        index = *(int*)(index + 12);
                        frame *= 4;
                        firstRecord = (volatile int*)((unsigned char*)firstRecord + index);
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(firstRecord, "memory");
                        index = *(volatile unsigned char*)&moby->animationState.nextId;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(frame, "memory");
                        firstRecord = (volatile int*)((unsigned char*)firstRecord + frame);
                        MATCHING_KEEP(firstRecord);
                        index = (index & 1) * 4;
                        secondRecord =
                            *(volatile int**)((unsigned char*)DecodedCutsceneBanks + index);
                        index = *firstRecord;
                        frame = tableOffset + (int)secondRecord;
                        MATCHING_KEEP(frame);
                        index &= xMask;
                        secondOffset = *(int*)(frame + 12);
                        frame = moby->animationState.nextFrame;
                        index >>= 12;
                        sample.first.x = index;
                        index = *firstRecord;
                        __asm__ __volatile__("" : : : "$18", "memory");
                        second = &sample.second;
                        index &= yMask;
                        index >>= 2;
                        secondRecord = (volatile int*)((unsigned char*)secondRecord + secondOffset);
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(frame, "memory");
                        frame *= 4;
                        sample.first.y = index;
                        index = *firstRecord;
                        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(frame, "memory");
                        secondRecord = (volatile int*)((unsigned char*)secondRecord + frame);
                        MATCHING_KEEP(secondRecord);
                        index = (index & 0x3FF) << 8;
                        sample.first.z = index;
                        index = *secondRecord;
                        __asm__ __volatile__("" : : : "$5", "memory");
                        subtractFirst = &sample.first;
                        MATCHING_KEEP(subtractFirst);
                        sample.second.x = (index & xMask) >> 12;
                        index = *secondRecord;
                        __asm__ __volatile__("" : : : "$4", "memory");
                        subtractDestination = scratch;
                        sample.second.y = (index & yMask) >> 2;
                        sample.second.z = (*secondRecord & 0x3FF) << 8;
                        DecodedCutsceneSubtract(subtractDestination, subtractFirst, second);
                        if (DecodedCutsceneLength(scratch, 1) >= 2048) {
                            Moby* actor = DECODED_CUTSCENE_ACTOR;
                            if (actor->animationProgress >= 8) {
                                actor->animationState.frame = actor->animationState.nextFrame;
                                DecodedCutsceneCopy(&sample.first, second);
                            }
                            DECODED_CUTSCENE_ACTOR->animationProgress = 0;
                        }
                    }
                    {
                        register Moby* moby __asm__("$4") = DecodedCutsceneMobys;
                        register int limit __asm__("$5");
                        __asm__ __volatile__("" : : : "$5", "memory");
                        limit = 16;
                        MATCHING_KEEP(limit);
                        moby = (Moby*)(actorOffset + (unsigned int)moby);
                        sample.first.x *= limit - moby->animationProgress;
                        sample.first.y *= limit - moby->animationProgress;
                        limit -= moby->animationProgress;
                        sample.first.z *= limit;
                        sample.second.x *= moby->animationProgress;
                        sample.second.y *= moby->animationProgress;
                        sample.second.z *= moby->animationProgress;
                        DecodedCutsceneAdd(&sample.first, &sample.first, &sample.second);
                        DecodedCutsceneShift(&sample.first, 4);
                        {
                            register Moby* copyActor __asm__("$4") = DecodedCutsceneMobys;
                            register Vector3D* copySource __asm__("$5");
                            __asm__ __volatile__("" : : : "$5", "memory");
                            copySource = &sample.first;
                            MATCHING_KEEP(copySource);
                            copyActor = (Moby*)((unsigned char*)copyActor + actorOffset);
                            DecodedCutsceneCopy(&copyActor->position, copySource);
                        }
                    }
                }
                {
                    Moby* moby = DECODED_CUTSCENE_ACTOR;
                    register int packedSelector __asm__("$4") = (moby->distanceToGround % 1000)
                                                                << 16;
                    MATCHING_KEEP_CLOBBER(packedSelector, "memory");
                    {
                        register void (**callbacks)(Moby*) __asm__("$3") = DecodedCutsceneCallbacks;
                        if (callbacks) {
                            void (*callback)(Moby*) = callbacks[packedSelector >> 16];
                            MATCHING_OBSERVE(packedSelector);
                            if (callback)
                                callback(moby);
                        }
                    }
                }
            nextEntity:
                actorOffset += 0x58;
                tableOffset += 4;
                loopCount = DecodedCutsceneCount;
                MATCHING_BARRIER("memory");
                actorIndex++;
                modelCursor++;
            } while (actorIndex < loopCount);
        }
    }
    {
        register Moby* moby __asm__("$17") = DecodedCutsceneSecondary;
        register unsigned char* state __asm__("$16");
        register int currentState __asm__("$4") = moby->state;
        register int endState __asm__("$2");
        __asm__ __volatile__("" : : : "$2", "memory");
        endState = 255;
        __asm__("" : "=r"(currentState) : "0"(currentState), "r"(endState));
        if ((currentState & 255) != endState) {
            state = &moby->state;
            do {
                {
                    register int flags __asm__("$2") = currentState & 0x80;
                    MATCHING_KEEP(flags);
                    if (!flags) {
                        register int packedSelector __asm__("$4") = (*(short*)(state - 0x10) % 1000)
                                                                    << 16;
                        MATCHING_KEEP_CLOBBER(packedSelector, "memory");
                        {
                            register void (**callbacks)(Moby*) __asm__("$3") =
                                DecodedCutsceneCallbacks;
                            if (callbacks) {
                                void (*callback)(Moby*) = callbacks[packedSelector >> 16];
                                MATCHING_OBSERVE(packedSelector);
                                if (callback)
                                    callback(moby);
                            }
                        }
                    }
                }
                state += 0x58;
                currentState = *state;
                endState = 255;
                __asm__("" : "=r"(currentState) : "0"(currentState), "r"(endState));
                moby++;
            } while ((currentState & 255) != endState);
        }
    }
    if (DecodedCutsceneParticles)
        DecodedCutsceneParticles(DecodedCutsceneDelta);
    DecodedCutsceneEndActors();
    {
        register unsigned char* samples __asm__("$17");
        register volatile int* frame __asm__("$3") = &DecodedCutsceneFrame;
        register unsigned char* archive __asm__("$5");
        register int packedTick __asm__("$2");
        register int byteOffset __asm__("$5");
        int current;
        register Vector3D* unpackDestination __asm__("$4");
        MATCHING_KEEP(frame);
        second = &sample.second;
        MATCHING_KEEP(second);
        {
            register int slot __asm__("$2") = *frame;
            __asm__ __volatile__("" : : : "$4", "memory");
            unpackDestination = second;
            __asm__("" : "=r"(slot) : "0"(slot), "r"(unpackDestination));
            slot &= 1;
            MATCHING_KEEP(slot);
            frame = (volatile int*)((unsigned char*)frame + slot * 4);
            MATCHING_KEEP(frame);
            archive = *(unsigned char* volatile*)((unsigned char*)frame + 0x28);
        }
        {
            register int archiveOffset __asm__("$3");
            packedTick = DecodedCutsceneTick;
            archiveOffset = *(volatile int*)(archive + 8);
            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(packedTick, "memory");
            packedTick >>= 1;
            MATCHING_KEEP(packedTick);
            samples = archive + archiveOffset;
        }
        byteOffset = packedTick * 12;
        MATCHING_KEEP(byteOffset);
        DecodedCutsceneUnpackPosition(unpackDestination, samples + byteOffset);
        packedTick = DecodedCutsceneTick >> 1;
        MATCHING_KEEP(packedTick);
        byteOffset = packedTick * 12;
        MATCHING_KEEP(byteOffset);
        DecodedCutsceneUnpackAngles(&sample.firstAngles, samples + byteOffset + 6);
        current = DecodedCutsceneTick;
        if ((current & 1) && current + 1 < 120) {
            scratch = &sample.temporary;
            unpackDestination = scratch;
            packedTick = current >> 1;
            __asm__("" : "=r"(packedTick) : "0"(packedTick), "r"(unpackDestination));
            byteOffset = packedTick * 12;
            MATCHING_KEEP(byteOffset);
            DecodedCutsceneUnpackPosition(unpackDestination, samples + byteOffset + 12);
            DecodedCutsceneSubtract(scratch, scratch, second);
            packedTick = DecodedCutsceneTick >> 1;
            MATCHING_KEEP(packedTick);
            byteOffset = packedTick * 12;
            MATCHING_KEEP(byteOffset);
            DecodedCutsceneUnpackAngles(&sample.secondAngles, samples + byteOffset + 18);
            sample.secondAngles.x =
                DecodedCutsceneAngleDifference(sample.secondAngles.x, sample.firstAngles.x);
            sample.secondAngles.y =
                DecodedCutsceneAngleDifference(sample.secondAngles.y, sample.firstAngles.y);
            sample.secondAngles.z =
                DecodedCutsceneAngleDifference(sample.secondAngles.z, sample.firstAngles.z);
            if (DecodedCutsceneLength(scratch, 1) < 256 &&
                (unsigned int)(sample.secondAngles.z + 255) < 511) {
                DecodedCutsceneShift(scratch, 1);
                {
                    register Vector3D* destination __asm__("$4") = second;
                    MATCHING_KEEP(destination);
                    DecodedCutsceneAdd(destination, destination, scratch);
                }
                sample.firstAngles.x += sample.secondAngles.x >> 1;
                sample.firstAngles.y += sample.secondAngles.y >> 1;
                sample.firstAngles.z += sample.secondAngles.z >> 1;
            }
        }
    }
    scratch = DecodedCutsceneCamera;
    DecodedCutsceneCopy(scratch, &sample.second);
    DecodedCutsceneWriteAngles((unsigned char*)scratch + 0x1C, &sample.firstAngles);
}
#undef DECODED_CUTSCENE_ACTOR
