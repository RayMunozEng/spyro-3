#include "matching.h"
#include "common.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_62_80074780(void) {
}

extern short D_800658A0[], D_80065920[];
extern int DecodedParticleColour __asm__("D_80065868");
extern void* func_8002EC50(int, int, int);
void func_cutscene_62_80074788(Moby* moby) {
    Vector3D offset, middle;
    void* effect;
    int angle = func_8003636C(0, 0xFF);
    func_80055D24(moby, 4);
    *(int*)&moby->colour = DecodedParticleColour;
    func_80055F14(moby, 1, &middle);
    func_80055F14(moby, 0, &offset);
    func_8004F194(&middle, &middle, &offset);
    func_8004F110(&middle, 1);
    offset.x = D_80065920[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.y = D_800658A0[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.z = 0;
    func_8004F194(&offset, &middle, &offset);
    SpawnParticle(2, 0x42, &offset, (Vector3D*)1);
    func_80055F14(moby, 2, &middle);
    func_80055F14(moby, 0, &offset);
    func_8004F194(&middle, &middle, &offset);
    func_8004F110(&middle, 1);
    angle = func_8003636C(0, 0xFF);
    offset.x = D_80065920[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.y = D_800658A0[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.z = 0;
    func_8004F194(&offset, &middle, &offset);
    SpawnParticle(2, 0x42, &offset, (Vector3D*)1);
    if (!moby->mobyTag) {
        moby->mobyTag = func_8002EC50(1, 0x40, 0x489090);
        if (!moby->mobyTag)
            return;
    }
    {
        effect = moby->mobyTag;
        *((unsigned char*)effect + 0x10) = 1;
        func_80055F14(moby, 0, effect);
    }
}

/* AI generated; not yet human reviewed. Original SCUS-94467 USA Rev 0
 * cutscene controller: eight byte-indexed slots, preserved access widths and
 * integer operations. Physical units, helper semantics and caller cadence are
 * unresolved. Empty constraints preserve allocation/scheduling without opcodes.
 * Helper aliases describe argument producers visible at each original call;
 * the second 4EA90 call does not establish a new fourth argument.
 */
#define Cutscene74788Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Cutscene74788BuildPackedAngleBasisMatrixFour(void*, void*, int, int) __asm__("func_8004EA90");
int Cutscene74788BuildPackedAngleBasisMatrix(void*, void*, int) __asm__("func_8004EA90");
int Cutscene74788TransformVectorByBasis(void*, void*, void*) __asm__("func_8004ED6C");
int Cutscene74788ClearVector(void*) __asm__("func_8004F168");
int Cutscene74788CopyVector(void*, void*) __asm__("func_8004F178");
int Cutscene74788AddVector(void*, void*, void*) __asm__("func_8004F194");
int Cutscene74788ExpandSignedHalfwordVector(void*, void*, int) __asm__("func_8004F554");
int Cutscene74788RefreshMobySpatialGridAndBasis(void*, int) __asm__("func_80055D24");
int Cutscene74788InterpolateMobyVertex(void*, int, void*) __asm__("func_80055F14");
extern unsigned char Cutscene74788D_800695F8[] __asm__("D_800695F8");
extern unsigned char Cutscene74788D_800698B8[] __asm__("D_800698B8");
extern unsigned char Cutscene74788D_80069C58[] __asm__("D_80069C58");
extern unsigned char Cutscene74788D_80069C68[] __asm__("D_80069C68");
extern unsigned char Cutscene74788D_8007179C[] __asm__("D_8007179C");
extern unsigned char Cutscene74788D_800717A8[] __asm__("D_800717A8");
extern unsigned char Cutscene74788D_800717BC[] __asm__("D_800717BC");
extern unsigned char Cutscene74788D_800717C4[] __asm__("D_800717C4");
extern unsigned char Cutscene74788D_800717CC[] __asm__("D_800717CC");
extern unsigned char Cutscene74788D_80071835[] __asm__("D_80071835");
extern int Cutscene74788D_8006C648 __asm__("D_8006C648");
extern int Cutscene74788D_8006EDDC __asm__("D_8006EDDC");
extern unsigned char Cutscene74788D_800717A9 __asm__("D_800717A9");
extern unsigned char Cutscene74788D_800717AA __asm__("D_800717AA");
extern unsigned char Cutscene74788D_80071834 __asm__("D_80071834");
extern int (*Cutscene74788SpawnParticle)(int, int, void*, void*) __asm__("SpawnParticle");
void func_cutscene_62_800749DC(void* input) {
    register unsigned char* owner __asm__("$22") = input;
    struct {
        unsigned char colour[8];
        struct {
            int x, y, z;
        } first;
        int pad24;
        struct {
            int x, y, z;
        } second;
        int pad34;
        int inactive;
        int pad3C[3];
    } frame;
    register unsigned char* keyframeTable __asm__("$2");
    register int startThreshold __asm__("$4");
    register int expiryThreshold __asm__("$4");
    register int tickIndex __asm__("$6");
    register int keyframeCount __asm__("$6");
    register int keyframeOffset __asm__("$9");
    register int slotIndex __asm__("$18");
    register int slotByteOffset __asm__("$23");
    register unsigned char* previousPosition __asm__("$20");
    register unsigned char* slotTimer __asm__("$16");
    register unsigned char* slotState __asm__("$19");
    unsigned char currentFrame;
    unsigned char ownerState;
    void* sharedTransform;
    register void* slotKeyframes __asm__("$3");

    register unsigned char* timerBytes __asm__("$5");
    register unsigned char* selectors __asm__("$7");
    register int step __asm__("$4");
    register int thirtyTwo __asm__("$8");
    register int colour __asm__("$7");
    register void* firstVector __asm__("$17");
    register void* secondVector __asm__("$21");
    register int inactiveCount __asm__("$9");
    frame.inactive = 0;
    ownerState = Cutscene74788Field(owner, unsigned char*, 0x48);
    if (ownerState != 2) {
        startThreshold = 0x954;
        if (ownerState == 0) {
            if (Cutscene74788Field(owner, short*, 0x38) == 0x2711) {
                startThreshold = 0xD16;
            }
            colour = 0xC0;
            MATCHING_KEEP(colour);
            if (Cutscene74788D_8006EDDC >= startThreshold) {
                frame.colour[0] = 0;
                frame.colour[1] = 0;
                frame.colour[2] = colour;
                Cutscene74788D_800717A8[0] = 0;
                Cutscene74788D_800717A9 = 0;
                Cutscene74788D_800717AA = 0xC0;
                Cutscene74788BuildPackedAngleBasisMatrixFour(
                    &frame.colour[0], Cutscene74788D_800717A8 + 0x90, 0, colour);
                Cutscene74788BuildPackedAngleBasisMatrix(&frame.colour[0],
                                                         Cutscene74788D_800717A8 + 0xA4, 0);
                Cutscene74788ClearVector(Cutscene74788D_800717A8 + 0x118);
                Cutscene74788D_80071834 = 1;
                Cutscene74788Field(Cutscene74788D_80071835, unsigned char*, 0) = 0U;
                Cutscene74788Field(owner, unsigned char*, 0x48) = 1U;
                goto updateSlots;
            }
        } else {
        updateSlots:
            step = Cutscene74788D_8006C648;
            tickIndex = 0;
            if (step > 0) {
                timerBytes = Cutscene74788D_80071835;
                selectors = Cutscene74788D_80069C58;
                thirtyTwo = 32;
                MATCHING_KEEP3(timerBytes, selectors, thirtyTwo);
                do {
                    if ((unsigned char)Cutscene74788Field(timerBytes, unsigned char*, 0) < 8U) {
                        {
                            register int selected __asm__("$3") =
                                *((Cutscene74788Field(timerBytes, unsigned char*, 2) * 8) +
                                  selectors + Cutscene74788Field(timerBytes, unsigned char*, 0));
                            register int value __asm__("$2");
                            MATCHING_KEEP2_CLOBBER(selected, step, "$2");
                            value = step - tickIndex;
                            Cutscene74788D_800717BC[selected] = value;
                        }
                        *(Cutscene74788D_800717C4 +
                          *((Cutscene74788Field(timerBytes, unsigned char*, 2) * 8) + selectors +
                            Cutscene74788Field(timerBytes, unsigned char*, 0))) = thirtyTwo;
                        *(Cutscene74788D_800717CC +
                          *((Cutscene74788Field(timerBytes, unsigned char*, 2) * 8) + selectors +
                            Cutscene74788Field(timerBytes, unsigned char*, 0))) = 0;
                    }
                    tickIndex += 1;
                    __asm__ volatile("" : "=r"(tickIndex) : "0"(tickIndex) : "$2", "memory");
                    {
                        register int count __asm__("$2") =
                            Cutscene74788Field(timerBytes, unsigned char*, 0);
                        step = Cutscene74788D_8006C648;
                        MATCHING_KEEP2(count, step);
                        count += 1;
                        Cutscene74788Field(timerBytes, unsigned char*, 0) = count;
                    }
                } while (tickIndex < step);
            }
            Cutscene74788RefreshMobySpatialGridAndBasis(owner, 4);
            Cutscene74788InterpolateMobyVertex(owner, 0, Cutscene74788D_8007179C);
            slotIndex = 0;
            firstVector = &frame.first.x;
            MATCHING_KEEP(firstVector);
            sharedTransform = Cutscene74788D_8007179C + 0x9C;
            secondVector = &frame.second.x;
            MATCHING_KEEP(secondVector);
            slotByteOffset = 0;
            previousPosition = Cutscene74788D_8007179C + 0xC4;
            slotState = Cutscene74788D_8007179C + 0x30;
            slotTimer = Cutscene74788D_8007179C + 0x20;
            do {
                if (*slotTimer != 0) {
                    keyframeCount = 0x16;
                    if (slotIndex < 4) {
                        expiryThreshold = 0x1E;
                    } else {
                        keyframeCount = 0x1C;
                        expiryThreshold = 0x24;
                    }
                    if (*slotState != 0) {
                        *slotTimer += Cutscene74788D_8006C648;
                    }
                    if ((int)*slotTimer >= expiryThreshold) {
                        *slotTimer = 0;
                        goto advanceSlot;
                    }
                    if (*slotState != 2) {
                        if (slotIndex < 4) {
                            keyframeOffset = slotIndex * keyframeCount;
                            keyframeTable = Cutscene74788D_800695F8;
                        } else {
                            {
                                register int offset __asm__("$2") = slotIndex - 4;
                                MATCHING_KEEP(offset);
                                keyframeOffset = offset * keyframeCount;
                            }
                            keyframeTable = Cutscene74788D_800698B8;
                        }
                        MATCHING_KEEP2(keyframeOffset, keyframeTable);
                        slotKeyframes = (keyframeOffset * 8);
                        MATCHING_KEEP(slotKeyframes);
                        slotKeyframes += (int)keyframeTable;
                        currentFrame = *slotTimer;
                        if ((int)currentFrame < (keyframeCount - 1)) {
                            Cutscene74788ExpandSignedHalfwordVector(
                                firstVector, slotKeyframes + ((currentFrame + 1) * 8),
                                keyframeCount);
                            Cutscene74788TransformVectorByBasis(sharedTransform, firstVector,
                                                                firstVector);
                            Cutscene74788AddVector(firstVector, firstVector,
                                                   sharedTransform - 0x9C);
                            if (*slotState == 0) {
                                Cutscene74788CopyVector(&frame.second.x, owner + 0xC);
                                *slotState = 1;
                            } else {
                                Cutscene74788CopyVector(&frame.second.x, previousPosition);
                            }
                            Cutscene74788CopyVector(previousPosition, &frame.first.x);
                            slotByteOffset += 0xC;
                        } else if ((keyframeCount < (currentFrame + Cutscene74788D_8006C648)) &&
                                   (keyframeCount >= (int)currentFrame) &&
                                   (Cutscene74788ExpandSignedHalfwordVector(
                                        firstVector, slotKeyframes + ((keyframeCount - 2) * 8),
                                        keyframeCount),
                                    Cutscene74788TransformVectorByBasis(sharedTransform,
                                                                        firstVector, firstVector),
                                    Cutscene74788AddVector(firstVector, firstVector,
                                                           sharedTransform - 0x9C),
                                    Cutscene74788ClearVector(secondVector),
                                    (Cutscene74788SpawnParticle != 0))) {
                            Cutscene74788SpawnParticle(1, 0, firstVector, secondVector);
                            Cutscene74788SpawnParticle(4, 0x4E, firstVector, 0);
                            Cutscene74788TransformVectorByBasis(
                                0, slotByteOffset + Cutscene74788D_80069C68, secondVector);
                            Cutscene74788SpawnParticle(5, 0x4F, firstVector, secondVector);
                            slotByteOffset += 0xC;
                        } else {
                            goto advanceSlot;
                        }
                    } else {
                        goto advanceSlot;
                    }
                } else {
                    inactiveCount = frame.inactive;
                    MATCHING_KEEP(inactiveCount);
                    inactiveCount += 1;
                    frame.inactive = inactiveCount;
                advanceSlot:
                    slotByteOffset += 0xC;
                }
                previousPosition += 0xC;
                slotState += 1;
                slotIndex += 1;
                slotTimer += 1;
            } while (slotIndex < 8);
            inactiveCount = frame.inactive;
            MATCHING_KEEP(inactiveCount);
            if (inactiveCount == 8) {
                Cutscene74788D_80071834 = 0;
                Cutscene74788Field(owner, unsigned char*, 0x48) = 2U;
            }
        }
    }
}

#undef Cutscene74788Field


#define P74E60_FIELD(type, base, offset) (*(type*)((unsigned char*)(base) + (offset)))
extern int D_8006EDDC;
extern Moby* D_8006C550;
void* P74E60Allocate(int, int, int) __asm__("func_8002EC50");
void P74E60Scale(Vector3D*, int, int) __asm__("func_8004F08C");
void P74E60Vector(Moby*, int, Vector3D*) __asm__("func_80055F14");
/* USA Rev 0, 0x80074E60..0x800751F4: 230 original instructions.
 * Two vectors, exact raw field widths and original helper call arguments.
 * Register bindings and empty constraints preserve compiler scheduling.
 * Complete helper/field semantics, physical units and caller cadence unresolved.
 * AI generated; not yet human reviewed. */
void func_cutscene_62_80074E60(Moby* moby) {
    register int clock3 __asm__("$3") = D_8006EDDC;
    register Moby* owner __asm__("$19") = moby;
    register int gate2 __asm__("$2"), allocate6 __asm__("$6");
    register int random2 __asm__("$2"), word3 __asm__("$3");
    register int call4 __asm__("$4"), call5 __asm__("$5");
    register Vector3D *call6 __asm__("$6"), *call7 __asm__("$7");
    register char* (*particle8)(int, int, Vector3D*, Vector3D*)__asm__("$8");
    Vector3D samplePosition;
    Vector3D difference;
    Vector3D* entry;
    Vector3D* otherEntry;
    Vector3D* activeEntry;
    Vector3D* otherActiveEntry;
    register Vector3D* privateVector17 __asm__("$17");
    Vector3D* firstEntry;
    Vector3D* secondEntry;
    register int iteration16 __asm__("$16");
    unsigned char firstByte11;
    unsigned char secondByte11;
    register void* privateData18 __asm__("$18");
    register void* privateData18Later __asm__("$18");
    register void* allocation2 __asm__("$2");
    void* secondAllocation;
    register void* activeData18 __asm__("$18");

    gate2 = clock3 < 0x79E;
    if (!gate2) {
        MATCHING_KEEP(owner);
        privateData18 = owner->mobyTag;
        firstEntry = P74E60_FIELD(Vector3D*, privateData18, 0);
        if (firstEntry != 0) {
            P74E60_FIELD(signed char, firstEntry, 0x10) = 0;
            P74E60_FIELD(Vector3D*, privateData18, 0) = 0;
        }
        secondEntry = P74E60_FIELD(Vector3D*, privateData18, 4);
        if (secondEntry != 0) {
            P74E60_FIELD(signed char, secondEntry, 0x10) = 0;
            P74E60_FIELD(Vector3D*, privateData18, 4) = 0;
        }
    } else {
        MATCHING_KEEP(owner);
        MATCHING_KEEP(clock3);
        if (clock3 >= 0x76B) {
            privateData18Later = owner->mobyTag;
            SpawnParticle(2, 0x42, P74E60_FIELD(Vector3D*, privateData18Later, 4), (Vector3D*)2);
            privateVector17 = privateData18Later + 8;
            func_8004F1C8(&difference, privateVector17,
                          P74E60_FIELD(Vector3D*, privateData18Later, 4));
            P74E60Scale(&difference, func_8004EDE8(&difference, 1), 0xC8);
            entry = P74E60_FIELD(Vector3D*, privateData18Later, 4);
            func_8004F194(entry, entry, &difference);
            SpawnParticle(2, 0x42, P74E60_FIELD(Vector3D*, privateData18Later, 0), (Vector3D*)2);
            func_8004F1C8(&difference, privateVector17,
                          P74E60_FIELD(Vector3D*, privateData18Later, 0));
            P74E60Scale(&difference, func_8004EDE8(&difference, 1), 0xC8);
            otherEntry = P74E60_FIELD(Vector3D*, privateData18Later, 0);
            func_8004F194(otherEntry, otherEntry, &difference);
            return;
        }
        gate2 = clock3 < 0x732;
        MATCHING_KEEP(gate2);
        if (!gate2) {
            if (owner->state == 0) {
                allocation2 = SpawnMoby(0x2C3A, owner);
                call4 = 1;
                call5 = 0x10;
                allocate6 = 0x480000;
                __asm__(""
                        : "=r"(allocation2)
                        : "0"(allocation2), "r"(call4), "r"(call5), "r"(allocate6));
                allocation2 = P74E60_FIELD(void*, allocation2, 0);
                MATCHING_KEEP(allocation2);
                allocate6 |= 0x9090;
                __asm__("" : "=r"(allocate6) : "0"(allocate6), "r"(allocation2));
                activeData18 = allocation2;
                owner->mobyTag = activeData18;
                allocation2 = P74E60Allocate(call4, call5, allocate6);
                P74E60_FIELD(void*, activeData18, 0) = allocation2;
                P74E60_FIELD(signed char, allocation2, 0x10) = 4;
                P74E60_FIELD(signed char, P74E60_FIELD(void*, activeData18, 0), 0x13) = 8;
                secondAllocation = P74E60Allocate(1, 0x10, 0x489090);
                P74E60_FIELD(void*, activeData18, 4) = secondAllocation;
                P74E60_FIELD(signed char, secondAllocation, 0x10) = 4;
                P74E60_FIELD(signed char, P74E60_FIELD(void*, activeData18, 4), 0x13) = 8;
                func_8004F178(activeData18 + 8, (Vector3D*)((unsigned char*)D_8006C550 + 0xBC));
                owner->state = 1;
            } else {
                activeData18 = owner->mobyTag;
            }
            func_80055D24(owner, 4);
            P74E60Vector(owner, 0, &samplePosition);
            activeEntry = P74E60_FIELD(Vector3D*, activeData18, 0);
            firstByte11 = P74E60_FIELD(unsigned char, activeEntry, 0x11);
            if (firstByte11 < 0xF4U) {
                P74E60_FIELD(unsigned char, activeEntry, 0x11) = (unsigned char)(firstByte11 + 0xC);
            }
            call4 = (int)P74E60_FIELD(Vector3D*, activeData18, 0);
            call5 = (int)&samplePosition;
            MATCHING_OBSERVE2(call4, call5);
            iteration16 = 0;
            func_8004F178((Vector3D*)call4, (Vector3D*)call5);
            do {
                random2 = func_8003636C(0, 0xC8);
                call4 = 0;
                call5 = 0xC8;
                MATCHING_OBSERVE3(call4, call5, random2);
                word3 = samplePosition.x;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                iteration16++;
                __asm__("" : "=r"(iteration16) : "0"(iteration16), "r"(word3));
                word3 -= 0x64;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 += random2;
                samplePosition.x = word3;
                random2 = func_8003636C(call4, call5);
                call4 = 0;
                MATCHING_OBSERVE2(call4, random2);
                word3 = samplePosition.y;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                call5 = 0xC8;
                __asm__("" : "=r"(call5) : "0"(call5), "r"(word3));
                word3 -= 0x64;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 += random2;
                samplePosition.y = word3;
                random2 = func_8003636C(call4, call5);
                call4 = 2;
                call5 = 0x42;
                call6 = &samplePosition;
                call7 = (Vector3D*)2;
                MATCHING_OBSERVE5(call4, call5, call6, call7, random2);
                word3 = samplePosition.z;
                particle8 = SpawnParticle;
                __asm__("" : "=r"(particle8) : "0"(particle8), "r"(word3));
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 -= 0x64;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 += random2;
                samplePosition.z = word3;
                particle8(call4, call5, call6, call7);
            } while (iteration16 < 3);
            P74E60Vector(owner, 1, &samplePosition);
            otherActiveEntry = P74E60_FIELD(Vector3D*, activeData18, 4);
            secondByte11 = P74E60_FIELD(unsigned char, otherActiveEntry, 0x11);
            if (secondByte11 < 0xF4U) {
                P74E60_FIELD(unsigned char, otherActiveEntry, 0x11) =
                    (unsigned char)(secondByte11 + 0xC);
            }
            call4 = (int)P74E60_FIELD(Vector3D*, activeData18, 4);
            call5 = (int)&samplePosition;
            MATCHING_OBSERVE2(call4, call5);
            iteration16 = 0;
            func_8004F178((Vector3D*)call4, (Vector3D*)call5);
            do {
                random2 = func_8003636C(0, 0xC8);
                call4 = 0;
                call5 = 0xC8;
                MATCHING_OBSERVE3(call4, call5, random2);
                word3 = samplePosition.x;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                iteration16++;
                __asm__("" : "=r"(iteration16) : "0"(iteration16), "r"(word3));
                word3 -= 0x64;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 += random2;
                samplePosition.x = word3;
                random2 = func_8003636C(call4, call5);
                call4 = 0;
                MATCHING_OBSERVE2(call4, random2);
                word3 = samplePosition.y;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                call5 = 0xC8;
                __asm__("" : "=r"(call5) : "0"(call5), "r"(word3));
                word3 -= 0x64;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 += random2;
                samplePosition.y = word3;
                random2 = func_8003636C(call4, call5);
                call4 = 2;
                call5 = 0x42;
                call6 = &samplePosition;
                call7 = (Vector3D*)2;
                MATCHING_OBSERVE5(call4, call5, call6, call7, random2);
                word3 = samplePosition.z;
                particle8 = SpawnParticle;
                __asm__("" : "=r"(particle8) : "0"(particle8), "r"(word3));
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 -= 0x64;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(random2));
                word3 += random2;
                samplePosition.z = word3;
                particle8(call4, call5, call6, call7);
            } while (iteration16 < 3);
        }
    }
}

void func_cutscene_62_800751F8(void) {
}

extern Moby* D_8006C550;
Moby* func_80055A7C(void);
void func_80034FEC(Moby*);
int func_80055D10(Moby*);
int func_80055C24(Moby*);
void func_8004F178(Vector3D*, Vector3D*);
Moby* func_cutscene_62_80075200(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C();
    void* tag;
    if (!moby)
        return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, sizeof(Moby));
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        int index = parent - D_8006C550;
        if ((unsigned int)index < 0x100)
            moby->linkedMoby = index;
        else
            moby->linkedMoby = 0xFF;
    } else
        moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    if (mobyClass == 0x2C3A) {
        func_8004F178(&moby->position, &parent->position);
        moby->mobyClass = 0xFF;
        moby->distanceToGround = 0x2C3A;
        func_80055D10(moby);
        moby->updateDistance = 0xFF;
    } else {
        if (parent)
            func_8004F178(&moby->position, &parent->position);
        else
            func_8004F178(&moby->position, &spyro.position);
        func_80055C24(moby);
    }
    return moby;
}
