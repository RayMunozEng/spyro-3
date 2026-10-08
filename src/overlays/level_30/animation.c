#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_30/animation", func_level_30_800882B4);

/* AI generated; not human reviewed. SCUS-94467 8008A0CC..8008A774.
 * Newly hash-verified44_800902B4 supplies scalar/clamp and descriptor-table
 * producers; its source chain is verified43 and verified50. Original30 adds
 * case1C and removes case39. Exact original30 instructions control acceptance.
 * Original30 supplies every selector and numeric access; byte offsets and helper
 * names establish no units, meanings or caller cadence. All code/table words,
 * strict complete translation unit and every retail hash required for acceptance.
 */
extern int Callback30Step __asm__("D_80070328+0x144");
extern int Callback30Z __asm__("D_80070328+8");
extern int Callback30Limit __asm__("D_80070328+0x280");
extern Spyro Callback30Player __asm__("D_80070328");
int Callback30Call80037058(int x, int y) __asm__("func_80037058");
int Callback30Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback30Call80041930(void) __asm__("func_80041930");
void Callback30Call80041AE8(void) __asm__("func_80041AE8");
void Callback30Call80041C20(void) __asm__("func_80041C20");
void Callback30Call80042A44(void) __asm__("func_80042A44");
void Callback30Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback30Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback30Query(Vector3D*,int) __asm__("func_8001A358");
int Callback30Length(Vector3D*, int) __asm__("func_8004EDE8");
extern int Callback30Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback30Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback30Values[] __asm__("D_8006FCF0");
void Callback30Call80049590(void) __asm__("func_80049590");
void func_level_30_8008A0CC(void) {
    struct {Vector3D first; int reserved1C;} local;
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback30Player.animationState) {
    case 0x73:
    case 0x78:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7E:
        if (func_800438F4() == 0) {
            func_80043728();
        }
        Callback30Call80041C20();
        Callback30Player.unk9a = 0;
        Callback30Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x80:
        Callback30Call80041C20();
        Callback30Call80042A44();
        goto clearSharedValue;
    case 0x79:
        Callback30Call80041C20();
        Callback30Call80042A44();
        goto queryC00;
    case 0x1C:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041930();
        if (Callback30Player.unk7a[3].z < 0 && Callback30Player.animationStateFrames >= 4)
            Callback30Player.unk5=1;
        goto clearSharedValue;
        case 0x81: {
            register int* zWord __asm__("$5")=&Callback30Z;
            register int velocity __asm__("$6")=Callback30Step;
            register int scalarPosition __asm__("$2")=*zWord;
            register int tick __asm__("$3")=D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            __asm__("" : "=r"(velocity) : "0"(velocity));
            __asm__("" : "=r"(scalarPosition) : "0"(scalarPosition));
            __asm__("" : "=r"(tick) : "0"(tick));
            increment=velocity>>6;
            __asm__("" : "=r"(increment) : "0"(increment));
            scalarPosition+=increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(scalarPosition));
            tick<<=9;
            *zWord=scalarPosition;
            status=Callback30Limit;
            velocity+=tick;
            Callback30Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback30Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback30Step=0x2580;
            }
        limitsDone:
            Callback30Call80041C20();
            Callback30Call80042A44();
            func_8004F178(&local.first,&Callback30Player.position);
            local.first.z+=0x400;
            Callback30Player.unk4[0]=Callback30Query(&local.first,0xC00);
            positionDelta=(int)Callback30Player.union144.a.unk13cb;
            positionValue=Callback30Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
    case 0x28:
    case 0x29:
        Callback30Call80041C20();
        Callback30Call80042A44();
        descriptor=&Callback30Player.unk22[2];
        if (Callback30Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback30Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=decreasingValue-0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
        }
        goto clearSharedValue;
    case 0x2A:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80049590();
        descriptor=&Callback30Player.unk22[2];
        if (Callback30Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback30Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback30Player.unk22[2];
        }
        if (Callback30Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback30Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback30Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback30Flags[flagOffset] = Callback30Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041AE8();
        if ((unsigned char) Callback30Player.unk10[4] != 0) {
            computedValue = -Callback30Player.unk9ha[4] - Callback30Call80037058(Callback30Player.position.x, Callback30Player.position.y);
            positionValue = Callback30Player.unk4a - computedValue;
            Callback30Player.unk4[0] = computedValue;
            positionDelta = (int) Callback30Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback30Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback30Player.unk7a[3].z << 2);
        Callback30Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)((unsigned int)ABS(numerator) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 0x10;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 0x10;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
    case 0x33:
    case 0x34:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041930();
        func_80042F64();
        Callback30Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback30Length((Vector3D *) ((unsigned char*)Callback30Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 8;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 8;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
compareUpperLimit:
        belowLimit=clampedValue<0x41;
applyUpperLimit:
        if(!belowLimit)clampedValue=0x40;
        func_800443A4(clampedValue);
        return;
    case 0x76:
    case 0x77:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041930();
        if (Callback30Player.unk5 != 0x7F) {
            if ((Callback30Player.unk7a[3].z < 0) && (Callback30Player.animationStateFrames >= 4)) {
                Callback30Player.unk5 = 1;
            } else {
                goto checkSecondFlag;
            }
        }
        goto clearSharedValue;
    case 0x82:
        if (Callback30Player.movementState != MOVEMENT_STATE_WALK) goto other82;
    case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback30Call80041C20();
            Callback30Call80042A44();
            Callback30Call80041930();
queryC00:
            Callback30Call80043A38(0xC00);
            goto clearSharedValue;
other82:
        Callback30Call80041C20();
        Callback30Call80042A44();
        Callback30Call80041930();
        if ((Callback30Player.unk7a[3].z < 0) && (Callback30Player.animationStateFrames >= 4)) {
            Callback30Player.unk5 = 1;
        } else {
checkSecondFlag:
                if ((Callback30Player.unk5 == 0) && !(Callback30Word8006E538 & 0x40) && (Callback30Player.union144.a.unk13cb == 0)) {
                    Callback30Player.unk5 = 2;
                }
        }
clearSharedValue:
        Callback30Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 30
#define PlaySpyroSounds_level_30 func_level_30_8008A778
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_30_8008A9B4(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x1c:
    case 0x76:
    case 0x77:
        func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    case 0x82:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state) func_80043ABC(0);
            else func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0x2b:
    case 0x2c:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x78:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x7e:
    case 0x80:
    case 0x81:
    case 0x83:
    case 0x84:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008AA5C.
 * Reuses verified43 surface and33/46 special-state routes. Original30 supplies
 * independent stack10/20 underwater vectors, stack30 surface vector, selector1C
 * and a single ladder block. Byte offsets: scalar60; helper vectors14C/98;
 * second helper vectors14C/98 from animation48; stores130=20000 and158=0.
 * The scalar wraps with FFF, subtracts1000 for values>=801, then clamps positives
 * to zero. Falsifiable inputs800/801/FFF yield0/-7FF/-1 before helper callbacks.
 * Signed words/halfwords, shifts, pointer byte arithmetic and callback reloads
 * follow original instructions. Unused stack words preserve original spacing;
 * they do not establish source variables. Empty constraints emit no opcodes.
 * Acceptance requires every code/local jump/owned dispatch word, strict full TU,
 * and complete EXE/every overlay hashes. Helper meanings, numeric conversions,
 * audio semantics, caller cadence and live runtime parity remain unverified.
 */

extern Spyro Transition30_D_80070328 __asm__("D_80070328");
int Transition30_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition30_func_800441F0(void) __asm__("func_800441F0");
void Transition30_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition30_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition30RawUnion[] __asm__("D_80070328+0x144");
extern int Transition30RawMovement __asm__("D_80070328+0x50");
extern int Raw30Movement __asm__("D_80070328+0x50");
extern int Raw30Union __asm__("D_80070328+0x144");
void Call30ED6C(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
extern void (*Call30Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw30State[] __asm__("D_80070328+0x50");
extern Spyro Special30_D_80070328 __asm__("D_80070328");
extern short Signed30TableA[] __asm__("D_800658A0");
extern short Signed30TableB[] __asm__("D_80065920");
int Special30_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special30_func_80043A38(int scale) __asm__("func_80043A38");
void Special30_func_800441F0(void) __asm__("func_800441F0");
void Special30_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special30_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call30A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw30NegativeWord __asm__("D_80070328+0x28");
void func_level_30_8008AA5C(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int previousMovement __asm__("$3");
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int groundValue __asm__("$2");
    switch(arg0){
    case 0x1C:
        previousMovement = Transition30RawMovement;
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        Transition30RawMovement = MOVEMENT_STATE_HURT;
        Transition30_D_80070328.unk5 = 0;
        Transition30_D_80070328.union144.a.unk13cb = previousMovement;
        Transition30_func_800441F0();
        Transition30_D_80070328.unk7a[2].z = 0xDC0;
        Transition30_D_80070328.grounded = 0;
        Transition30_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition30_D_80070328.damageFlags & 0x200) {
            Transition30_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition30_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition30_D_80070328.movementState - 0xB) >= 2U) && (Transition30_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition30_D_80070328.movementState - 0x50));
                if ((Transition30_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw30NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition30_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call30A358(&vectors.first, 0x800);
                    vectors.first.z = firstResult;
                    if (firstResult != 0) {
                        firstParticleKind = 6;
                        if (D_80071934 != 0) {
                            firstParticleSubtype = 0x2E;
emitFirstParticle:
                            SpawnParticle(firstParticleKind, firstParticleSubtype, &vectors.first, 0);
                        }
                    }
                }
            }
            firstWrappedWord = Transition30_D_80070328.rotation.pitch & 0xFFF;
            Transition30_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition30_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition30_D_80070328.rotation.pitch > 0) {
                Transition30_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition30_D_80070328.unk5 = 1;
            }
            Transition30_func_8004F168((Vector3D *) ((unsigned char*)&Transition30_D_80070328.rotation.pitch + 0xEC));
            Transition30_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition30_D_80070328.unk8[0] = Transition30_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition30_D_80070328.rotation.pitch + 0x38), 0);
            Transition30_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition30_D_80070328.animationState == 0x2A) {
            Transition30_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition30_D_80070328.union144.a.unk13da = 0;
        }
        Transition30_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition30_D_80070328.unk20a = 0;
        Transition30_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw30State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw30NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition30_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call30A358(localVector, 0x800);
                    vectors.second.z = secondResult;
                    if (secondResult != 0) {
                        secondParticleKind = 6;
                        if (D_80071934 != 0) {
                            secondParticleSubtype = 0x2E;
emitSecondParticle:
                            SpawnParticle(secondParticleKind, secondParticleSubtype, localVector, 0);
                        }
                    }
                }
            }
            if (Transition30_D_80070328.animationState == 0x2E) {
                Transition30_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition30_D_80070328.rotation.pitch & 0xFFF;
            Transition30_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition30_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition30_D_80070328.rotation.pitch > 0) {
                Transition30_D_80070328.rotation.pitch = 0;
            }
            Transition30_D_80070328.unk5 = 1;
            Transition30_func_8004F168((Vector3D *) ((unsigned char*)&Transition30_D_80070328.animationState + 0x104));
            Transition30_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition30_D_80070328.unk8[0] = Transition30_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition30_D_80070328.animationState + 0x50), 0);
            Transition30_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition30_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition30_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition30RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition30RawUnion;
            *(int*)unionPointer=(-Transition30_D_80070328.unk7a[2].z)>>2;
            if(Transition30RawMovement!=8){Transition30_D_80070328.union144.a.unk13cc=0x5900;Transition30RawMovement=10;}
            Transition30_D_80070328.unk5=0;
            Transition30_D_80070328.unk8[0]=Transition30_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition30_D_80070328.grounded=1;
            Transition30_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call30A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition30RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition30_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition30_D_80070328.grounded=1;
        }
clearPointers:
        Transition30_D_80070328.unk20a=0;
        Transition30_D_80070328.critterMobyPtr=0;
        return;
    case 0x73:
    case 0x78:
    case 0x7E:
        Special30_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Special30_D_80070328.unk5 = 0;
        Special30_func_800441F0();
        Special30_D_80070328.grounded = 1;
        return;
    case 0x74:
    case 0x75:
    case 0x83:
    case 0x84:
        walkBase=Raw30State;
        walkFlag=1;
        __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
        *(int*)walkBase=walkFlag;
        if(arg0==0x57 && Special30_D_80070328.ticksSinceLastSurfaceTouch!=0) {
            __asm__ volatile("" : : : "memory");
            destination=(Vector3D*)(walkBase+0x3C);
            goto copyWalkVector;
        }
        goto clearWalkFlag;
    case 0x80:
        Special30_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Special30_D_80070328.unk5 = 0;
        Special30_func_80043A38(0xC00);
        Special30_D_80070328.grounded = 1;
        Special30_D_8006E524 = 0xF;
        return;
    case 0x81: {
        register int oldState __asm__("$3")=Raw30Movement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Raw30Movement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Special30_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Special30_D_8006E524=value;
        Special30_D_80070328.unk5=0;
        stateWord=&Raw30Union;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Special30_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Special30_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        Special30_D_80070328.unk22[3]=(int)D_8006C654->drown;
        return;
    }
    case 0x79:
        Special30_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special30_D_80070328.unk5 = 0;
        if (Special30_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special30_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed30TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special30_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed30TableA + tableOffsetOrValue);
            Special30_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special30_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special30_func_8004F168((Vector3D *) ((unsigned char*)&Special30_D_80070328.movementState + 0x3C));
        }
        Special30_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special30_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special30_D_80070328.unk7a[2].z - 8));
        Special30_D_80070328.grounded = 1;
        Special30_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x7A: {
        register unsigned char* privateData __asm__("$17")=Special30_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* state __asm__("$18")=Raw30State;
        register Vector3D* vector __asm__("$16");
        *(int*)state=0;
        Special30_D_80070328.unk5=0;
        vector=(Vector3D*)(privateData+0x64);
        Special30_func_800441F0();
        Special30_D_80070328.grounded=1;
        Special30_D_80070328.idle=0;
        Special30_D_80070328.unk15g=0;
        *(int*)(privateData+0x5C)=0x180;
        *(int*)(privateData+0x64)=0x1800;
        *(int*)(privateData+0x68)=0;
        *(int*)(privateData+0x6C)=0;
        Call30ED6C((Vector3D*)(state-0x20),vector,vector);
        func_8004F194(vector,vector,(Vector3D*)(state-0x50));
        Call30Header(Special30_D_80070328.critterMobyPtr);
        return;
    }
    case 0x7B:
        Special30_D_80070328.movementState=0;
        Special30_func_800441F0();
        groundValue=1;
        goto sharedGround;
    case 0x7C: {
        register unsigned char* privateData __asm__("$16")=Special30_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* child __asm__("$4");
        Special30_D_80070328.movementState=0;
        Special30_func_800441F0();
        Special30_D_80070328.grounded=1;
        Special30_D_80070328.idle=0;
        Special30_D_80070328.unk15g=0;
        child=*(unsigned char**)(privateData+0x78);
        if(child) {
            if(*(short*)(privateData+0x74)==0x22A)child[0x48]=0x50;
            else child[0x48]=1;
        }
        return;
    }
    case 0x76:
        stateBaseA = Raw30State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special30_D_80070328.unk8[0] = Special30_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special30_D_80070328.unk7a[2].z = 0xDC0;
        Special30_D_80070328.unk5 = 0;
        if(Special30_D_80070328.animationState==0x81)Special30_D_80070328.union144.a.unk13cb=1;
        else Special30_D_80070328.union144.a.unk13cb=0;
        Special30_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x77: {
        register unsigned char* state __asm__("$6")=Raw30State;
        if(*(int*)state!=2) {
            *(int*)state=3;
            Special30_D_80070328.unk8[0]=Special30_func_8004EDE8((Vector3D*)(state+0x48),0);
            Special30_D_80070328.grounded=0;
            Special30_D_80070328.unk15b=1;
            goto clearTail;
        }
        return;
    }
    case 0x82: {
        walkBase=Raw30State;
        if(*(int*)walkBase!=2) {
            walkFlag=1;
            __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
            *(int*)walkBase=walkFlag;
            if(arg0==0x57 && Special30_D_80070328.ticksSinceLastSurfaceTouch!=0) {
                destination=(Vector3D*)(walkBase+0x3C);
copyWalkVector:
                func_8004F178(destination,(Vector3D*)(walkBase+0x48));
                Special30_D_80070328.unk5=walkFlag;
            } else {
clearWalkFlag:
                Special30_D_80070328.unk5=0;
            }
            Special30_D_80070328.unk8[0]=Special30_func_8004EDE8((Vector3D*)((unsigned char*)&Special30_D_80070328.movementState+0x48),0);
            Special30_func_80043A38(0xC00);
            groundValue=1;
            __asm__("" : "=r"(groundValue) : "0"(groundValue));
            Special30_D_80070328.union144.a.unk13cb=0;
sharedGround:
            Special30_D_80070328.grounded=groundValue;
clearTail:
            Special30_D_80070328.idle=0;
            Special30_D_80070328.unk15g=0;
        }
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_30/animation", func_level_30_8008B568);
