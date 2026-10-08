#include "common.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_61_80074780(void) {}

/* AI generated; not yet human reviewed. Original SCUS-94467 USA Rev 0
 * cutscene controller: eight byte-indexed slots, preserved access widths and
 * integer operations. Physical units, helper semantics and caller cadence are
 * unresolved. Empty constraints preserve allocation/scheduling without opcodes.
 * Helper aliases describe argument producers visible at each original call;
 * the second 4EA90 call does not establish a new fourth argument.
 */
#define Cutscene74788Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Cutscene74788Helper4EA90Four(void*,void*,int,int) __asm__("func_8004EA90");
int Cutscene74788Helper4EA90(void*,void*,int) __asm__("func_8004EA90");
int Cutscene74788Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Cutscene74788Helper4F168(void*) __asm__("func_8004F168");
int Cutscene74788Helper4F178(void*,void*) __asm__("func_8004F178");
int Cutscene74788Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Cutscene74788Helper4F554(void*,void*,int) __asm__("func_8004F554");
int Cutscene74788Helper55D24(void*,int) __asm__("func_80055D24");
int Cutscene74788Helper55F14(void*,int,void*) __asm__("func_80055F14");
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
extern int (*Cutscene74788SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
void func_cutscene_61_80074788(void *input) {
    register unsigned char *owner __asm__("$22")=input;
    struct {unsigned char colour[8]; struct {int x,y,z;} first;int pad24; struct {int x,y,z;} second;int pad34;int inactive;int pad3C[3];} frame;
    register unsigned char *keyframeTable __asm__("$2");
    register int startThreshold __asm__("$4");
    register int expiryThreshold __asm__("$4");
    register int tickIndex __asm__("$6");
    register int keyframeCount __asm__("$6");
    register int keyframeOffset __asm__("$9");
    register int slotIndex __asm__("$18");
    register int slotByteOffset __asm__("$23");
    register unsigned char *previousPosition __asm__("$20");
    register unsigned char *slotTimer __asm__("$16");
    register unsigned char *slotState __asm__("$19");
    unsigned char currentFrame;
    unsigned char ownerState;
    void *sharedTransform;
    register void *slotKeyframes __asm__("$3");

    register unsigned char *timerBytes __asm__("$5");
    register unsigned char *selectors __asm__("$7");
    register int step __asm__("$4");
    register int thirtyTwo __asm__("$8");
    register int colour __asm__("$7");
    register void *firstVector __asm__("$17");
    register void *secondVector __asm__("$21");
    register int inactiveCount __asm__("$9");
    frame.inactive = 0;
    ownerState = Cutscene74788Field(owner, unsigned char *, 0x48);
    if (ownerState != 2) {
        startThreshold = 0x954;
        if (ownerState == 0) {
            if (Cutscene74788Field(owner, short *, 0x38) == 0x2711) {
                startThreshold = 0xD16;
            }
            colour=0xC0;
            __asm__("" : "=r"(colour) : "0"(colour));
            if (Cutscene74788D_8006EDDC >= startThreshold) {
                frame.colour[0] = 0;
                frame.colour[1] = 0;
                frame.colour[2] = colour;
                Cutscene74788D_800717A8[0] = 0;
                Cutscene74788D_800717A9 = 0;
                Cutscene74788D_800717AA = 0xC0;
                Cutscene74788Helper4EA90Four(&frame.colour[0], Cutscene74788D_800717A8 + 0x90, 0, colour);
                Cutscene74788Helper4EA90(&frame.colour[0], Cutscene74788D_800717A8 + 0xA4, 0);
                Cutscene74788Helper4F168(Cutscene74788D_800717A8 + 0x118);
                Cutscene74788D_80071834 = 1;
                Cutscene74788Field(Cutscene74788D_80071835, unsigned char *, 0) = 0U;
                Cutscene74788Field(owner, unsigned char *, 0x48) = 1U;
                goto updateSlots;
            }
        } else {
updateSlots:
            step=Cutscene74788D_8006C648;
            tickIndex=0;
            if(step>0) {
                timerBytes=Cutscene74788D_80071835;
                selectors=Cutscene74788D_80069C58;
                thirtyTwo=32;
                __asm__("" : "=r"(timerBytes),"=r"(selectors),"=r"(thirtyTwo) : "0"(timerBytes),"1"(selectors),"2"(thirtyTwo));
                do {
                    if ((unsigned char) Cutscene74788Field(timerBytes, unsigned char *, 0) < 8U) {
                        {register int selected __asm__("$3")=*((Cutscene74788Field(timerBytes,unsigned char*,2)*8)+selectors+Cutscene74788Field(timerBytes,unsigned char*,0));
                         register int value __asm__("$2");
                         __asm__("" : "=r"(selected),"=r"(step) : "0"(selected),"1"(step) : "$2");
                         value=step-tickIndex;Cutscene74788D_800717BC[selected]=value;}
                        *(Cutscene74788D_800717C4 + *((Cutscene74788Field(timerBytes, unsigned char *, 2) * 8) + selectors + Cutscene74788Field(timerBytes, unsigned char *, 0))) = thirtyTwo;
                        *(Cutscene74788D_800717CC + *((Cutscene74788Field(timerBytes, unsigned char *, 2) * 8) + selectors + Cutscene74788Field(timerBytes, unsigned char *, 0))) = 0;
                    }
                    tickIndex += 1;
                    __asm__ volatile("" : "=r"(tickIndex) : "0"(tickIndex) : "$2", "memory");
                    {register int count __asm__("$2")=Cutscene74788Field(timerBytes,unsigned char*,0);
                     step=Cutscene74788D_8006C648;
                     __asm__("" : "=r"(count),"=r"(step) : "0"(count),"1"(step));
                     count+=1;Cutscene74788Field(timerBytes,unsigned char*,0)=count;}
                } while (tickIndex < step);
            }
            Cutscene74788Helper55D24(owner, 4);
            Cutscene74788Helper55F14(owner, 0, Cutscene74788D_8007179C);
            slotIndex = 0;
            firstVector=&frame.first.x;
            __asm__("" : "=r"(firstVector) : "0"(firstVector));
            sharedTransform = Cutscene74788D_8007179C + 0x9C;
            secondVector=&frame.second.x;
            __asm__("" : "=r"(secondVector) : "0"(secondVector));
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
                    if ((int) *slotTimer >= expiryThreshold) {
                        *slotTimer = 0;
                        goto advanceSlot;
                    }
                    if (*slotState != 2) {
                        if (slotIndex < 4) {
                            keyframeOffset=slotIndex*keyframeCount;
                            keyframeTable = Cutscene74788D_800695F8;
                        } else {
                            {register int offset __asm__("$2")=slotIndex-4;
                             __asm__("" : "=r"(offset) : "0"(offset));
                             keyframeOffset=offset*keyframeCount;}
                            keyframeTable = Cutscene74788D_800698B8;
                        }
                        __asm__("" : "=r"(keyframeOffset),"=r"(keyframeTable) : "0"(keyframeOffset),"1"(keyframeTable));
                        slotKeyframes = (keyframeOffset * 8);
                        __asm__("" : "=r"(slotKeyframes) : "0"(slotKeyframes));
                        slotKeyframes+= (int)keyframeTable;
                        currentFrame = *slotTimer;
                        if ((int) currentFrame < (keyframeCount - 1)) {
                            Cutscene74788Helper4F554(firstVector, slotKeyframes + ((currentFrame + 1) * 8), keyframeCount);
                            Cutscene74788Helper4ED6C(sharedTransform, firstVector, firstVector);
                            Cutscene74788Helper4F194(firstVector, firstVector, sharedTransform - 0x9C);
                            if (*slotState == 0) {
                                Cutscene74788Helper4F178(&frame.second.x, owner + 0xC);
                                *slotState = 1;
                            } else {
                                Cutscene74788Helper4F178(&frame.second.x, previousPosition);
                            }
                            Cutscene74788Helper4F178(previousPosition, &frame.first.x);
                            slotByteOffset += 0xC;
                        } else if ((keyframeCount < (currentFrame + Cutscene74788D_8006C648)) && (keyframeCount >= (int) currentFrame) && (Cutscene74788Helper4F554(firstVector, slotKeyframes + ((keyframeCount - 2) * 8), keyframeCount), Cutscene74788Helper4ED6C(sharedTransform, firstVector, firstVector), Cutscene74788Helper4F194(firstVector, firstVector, sharedTransform - 0x9C), Cutscene74788Helper4F168(secondVector), (Cutscene74788SpawnParticle != 0))) {
                            Cutscene74788SpawnParticle(1, 0, firstVector, secondVector);
                            Cutscene74788SpawnParticle(4, 0x4E, firstVector, 0);
                            Cutscene74788Helper4ED6C(0, slotByteOffset + Cutscene74788D_80069C68, secondVector);
                            Cutscene74788SpawnParticle(5, 0x4F, firstVector, secondVector);
                            slotByteOffset += 0xC;
                        } else {
                            goto advanceSlot;
                        }
                    } else {
                        goto advanceSlot;
                    }
                } else {
                    inactiveCount=frame.inactive;
                    __asm__("" : "=r"(inactiveCount) : "0"(inactiveCount));
                    inactiveCount+=1;frame.inactive=inactiveCount;
advanceSlot:
                    slotByteOffset += 0xC;
                }
                previousPosition += 0xC;
                slotState += 1;
                slotIndex += 1;
                slotTimer += 1;
            } while (slotIndex < 8);
            inactiveCount=frame.inactive;
            __asm__("" : "=r"(inactiveCount) : "0"(inactiveCount));
            if (inactiveCount == 8) {
                Cutscene74788D_80071834 = 0;
                Cutscene74788Field(owner, unsigned char *, 0x48) = 2U;
            }
        }
    }
}

#undef Cutscene74788Field


/**
 * MobySpawn_level_61() - func_cutscene_61_80074C0C() - MATCHING
 * Doesn't use v at all. Could be that the cutscenes use a different spawn function, but who knows.
 * https://decomp.me/scratch/ybz0b
 */
Moby* func_80055A7C(int, Moby*);
void func_80055C24(Moby*);
extern Moby* D_8006C550;
Moby* func_cutscene_61_80074C0C(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C(mobyClass, parent);
    void* tag;
    if (!moby) return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, 0x58);
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        int index = parent - D_8006C550;
        if ((unsigned int)index < 0x100) moby->linkedMoby = index;
        else moby->linkedMoby = 0xFF;
    } else moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    if (parent) func_8004F178(&moby->position, &parent->position);
    else func_8004F178(&moby->position, &spyro.position);
    func_80055C24(moby);
    return moby;
}
