#include "matching.h"
#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_50_8009012C:
* SCUS-94467 USA Rev0, 2373 original words; original assembly SHA256
* a527c8c320f2588259917c5d2378eb4883109472bd6010058727c0cbfe6e1269.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Accepted44 class197,20 common/fragments/426/427,32 effects/
*92/364,15 class224 and34 classes482/483/541 are reused. Original physical
*715/364/427 order and fragment308 only retained. Frame110/saveE8 keeps all
*SP10/20/30/40/58/70/78/88/A0/B8/C0/D0 views and intervening raw gaps. Local
*unions describe disjoint storage, not complete object layout contracts.
* New604 retains original packed3FFFFFFF SW, effect bytes10/13, three child
*slots atC+4*i and child tag0 SH. New716 keeps original352 max, ownerC source,
*payload14/cursor1C/copy8/vector10 offsets, signed440 quotient and raw player
*98 source. New751 retains original child setup, halfword timers and yaw
*producers. Its timer is ordinary C with no fixed-fp or empty timer binding.
*1000 keeps linked tagC source, EB0/five-slot4970 ring;1015 keeps sourceC and
*9C0/owner8 ring plus original state/yaw/height snapshots. They are distinct
*from44 direct-buffer variants. Initialized argument/value and dead-register
*constraints preserve original producers, never overwrite live predicates,
*and emit no CPU instructions. No acceptance or compiler flag is changed.
*Whole unused views/locals only may be removed; all used fields and frame
*padding stay. Full helper/physical units/frame contracts remain unresolved.
* Every native/linked instruction/target plus EXE and all overlay hashes
* must match. Full helper/producer/asset/SFX meanings, physical units and
* fixed-point domains, frame cadence and synchronized runtime verification
* remain open. Invocation cadence only. No engine/browser or subsystem
* completion claim. AI changes have not been human reviewed.
*/
#include "moby/mobytag.h"
#include "mobyutil.h"
#include "spyro.h"
#include "stdutil.h"
extern Moby* func_80055A7C(void);
extern void func_80055C24(Moby*);
extern Moby* mobyArrayPtr;
extern short D_800658A0[256], D_80065920[256];
extern int D_8006C784;
extern Sparx sparx;
extern MobyTag_120 D_8006E394;
extern int rand(void);
#include "camera.h"
int func_8004E9E4(int);
int func_8004EA2C(int);
void func_8004E7AC(int* dest, int set, int len);
void func_80055D10(Moby*);
void func_8004ED6C(void*, Vector3D*, Vector3D*);
extern Moby* D_8006C704;
void func_8004EA90(Angle*, SHORTMATRIX*, int);
int func_8004EDE8(Vector3D*, int);
void func_8003BABC(Moby*, int, int);
void func_80055F14(Moby*, int, Vector3D*);
void* func_80050844(Vector3D*, char, int, int);
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
} Spawn14Tag84;
#include "ovl_header.h"
extern int D_8006C5BC;
extern unsigned char D_80071A04;
extern CollisionData D_80071900;
int func_8004EDE8(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004ECF4(SHORTMATRIX*, void*);
void func_80034F80(Moby*, int);
typedef struct {
    Vector3D vector0;
    short wordC;
    unsigned char byteE, padF;
    short timer10, pad12;
    Moby* child14;
} Spawn50Tag197;
static __inline__ int Spawn50LinkIndex(int byteOffset) {
    return (int)(0U - (unsigned int)byteOffset * 0x45D1745DU) >> 3;
}
#include "mobyfunc.h"
void func_8004F110(Vector3D*, int);
typedef struct {
    unsigned char pad0[0x10];
    unsigned char byte10, pad11[2], byte13;
} Spawn50EffectView;
typedef struct {
    int word0, word4;
    Spawn50EffectView* effect8;
    Moby* childrenC[3];
} Spawn50Tag604;
typedef struct {
    short word0, word2;
    int word4;
    Moby* child8;
    int wordC;
    int word10, word14;
} Spawn50Tag751;
typedef struct {
    int* cursor0;
    int word4;
    int words8[2];
    Vector3D vector10;
} Spawn50Payload716;
typedef struct {
    Vector3D vector0;
    Spawn50Payload716* bufferC;
    short word10, word12, word14, pad16;
} Spawn50Tag716;
typedef struct {
    short word0, word2;
    int* buffer4;
    int word8, wordC;
    Moby* parent10;
    short word14, word16;
} Spawn50FactoryTag;
typedef struct {
    int unk0;
    int unk4;
} Spawn10Tag426;
typedef struct {
    int unk0;
    int unk4;
    void* unk8;
} Spawn10Tag427;
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
} Spawn10Tag54View;
typedef struct {
    Vector3D unk0;
    int unkC;
    int unk10;
} Spawn50Tag92;
typedef struct {
    Vector3D16 vector0;
    unsigned char byte6, byte7;
    int* buffer8;
    int wordC;
    int words10[2];
} Spawn50Tag483;
typedef struct {
    int unk0, unk4;
} Spawn50Tag224;
Moby* func_level_50_8009012C(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    register Moby* finishMoby __asm__("$4");
    register int finishArg1 __asm__("$5"), finishArg2 __asm__("$6");
    struct {
        Vector3D vector10;
        int gap1C;
        Vector3D vector20;
        int gap2C;
        Vector3D vector30;
        int gap3C;
        union {
            SHORTMATRIX matrix;
            Vector3D vector;
        } work40;
        int gap54;
        union {
            SHORTMATRIX matrix;
            Vector3D vector;
        } work58;
        int gap6C;
        Angle angle70;
        unsigned char gap73[8 - sizeof(Angle)];
        Vector3D vector78;
        int gap84;
        SHORTMATRIX matrix88;
        int gap9C;
        SHORTMATRIX matrixA0;
        int gapB4;
        Angle angleB8;
        unsigned char gapBB[8 - sizeof(Angle)];
        Vector3D vectorC0;
        int gapCC;
        Vector3D vectorD0;
        int gapDC;
        int gapE0[2];
    } frame;
    newMoby = func_80055A7C();
    if (newMoby == 0)
        return 0;
    newMobyTag = newMoby->mobyTag;
    func_8004E790(newMoby, 0, 0x58);
    newMoby->mobyTag = newMobyTag;
    func_8004E790(newMobyTag, 0, 0x18);
    newMoby->mobyClass = mobyClass;
    if (linkedMoby != 0) {
        if (linkedMoby - mobyArrayPtr < 0x100U) {
            newMoby->linkedMoby = linkedMoby - mobyArrayPtr;
        } else {
            newMoby->linkedMoby = 0xFF;
        }
    } else {
        newMoby->linkedMoby = 0xFF;
    }
    func_80034FEC(newMoby);
    switch (mobyClass) {
        case 1:
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 0x18;
            newMoby->updateDistance = 0x40;
            newMoby->unknown = -1;
            break;
        case 715: {
            Spawn14Tag84* mobyTag;
            int elevation;
            int azimuth;
            int radius;
            int radius2;
            mobyTag = newMoby->mobyTag;
            newMoby->lowDrawDistance = 0x20;
            newMoby->highDrawDistance = 0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = func_8003636C(0x12C, 0x834);
            azimuth = (linkedMoby->angle.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius = 0x78;
            mobyTag->unk0.x =
                ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y =
                ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2 = 0x96;
            mobyTag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.z += func_8003636C(0x28, 0x46);
            }
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x37) >> 0xA;
            } else {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x23) >> 0xA;
            }
            if ((newMoby->mobyClass != 10) && (newMoby->mobyClass != 29)) {
                newMoby->angle.roll = rand();
                newMoby->angle.pitch = rand();
                newMoby->angle.yaw = rand();
                newMoby->position.x += mobyTag->unk0.x * 2;
                newMoby->position.y += mobyTag->unk0.y * 2;
                newMoby->position.z += mobyTag->unk0.z * 2;
            } else {
                newMoby->angle.roll = linkedMoby->angle.roll;
                newMoby->angle.pitch = linkedMoby->angle.pitch;
                newMoby->angle.yaw = linkedMoby->angle.yaw;
            }
            mobyTag->unk6.x = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z = (rand() & 0x1F) - 0x10;
            mobyTag->unkC = func_8003636C(0x78, 0x96);
            mobyTag->unkE = 1;
            mobyTag->unk12 = 0;
            break;
        }
        case 92: {
            Spawn50Tag92* tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 127;
            newMoby->highDrawDistance = 127;
            tag->unk10 = 64;
            tag->unk0.x = 64;
            tag->unk0.y = 0;
            tag->unk0.z = 0;
            func_8004ED6C(&newMoby->rotationMatrix, &tag->unk0, &tag->unk0);
            break;
        }
        case 120: {
            MobyTag_120* mobyTag;
            char yaw;
            if (linkedMoby->mobyClass != mobyClass) {
                newMoby->mobyTag = &D_8006E394;
                func_8004E790(&D_8006E394, 0, 0x1C);
            }
            mobyTag = newMoby->mobyTag;
            func_80055C24(newMoby);
            newMoby->substate = 0;
            mobyTag->unk0 = 0;
            mobyTag->unk8 = 0;
            mobyTag->unk6 = 0;
            mobyTag->unk4 = 0;
            mobyTag->unkD = 0x78;
            mobyTag->unk10 = 0;
            mobyTag->unk14 = 0;
            if (linkedMoby != 0) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            } else {
                yaw = spyro.bodyRotation.yaw - 0x80;
                frame.vector10.x = (D_80065920[yaw] * 0x7D) >> 9;
                frame.vector10.y = (D_800658A0[yaw] * 0x7D) >> 9;
                frame.vector10.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &frame.vector10);
            }
            mobyTag->unk2 = 0xFF;
            break;
        }
        case 132: {
            int ground;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            ground = func_80035D38(newMoby);
            if (ground)
                newMoby->position.z = ground;
            newMoby->state = 6;
            break;
        }
        case 142: {
            Spawn14Tag84* tag = newMoby->mobyTag;
            int elevation, azimuth;
            int radius, radius2;
            newMoby->lowDrawDistance = 32;
            newMoby->highDrawDistance = 32;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = rand() & 4095;
            azimuth = (linkedMoby->unkb + func_8003636C(-1500, 1500)) & 4095;
            radius = 150;
            tag->unk0.x =
                ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 18;
            tag->unk0.y =
                ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 18;
            radius2 = 180;
            tag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 12;
            tag->unk0.x += (D_80065920[linkedMoby->unkb] * 35) >> 10;
            tag->unk0.y += (D_800658A0[linkedMoby->unkb] * 35) >> 10;
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            tag->unk6.x = (rand() & 31) - 16;
            tag->unk6.y = (rand() & 31) - 16;
            tag->unk6.z = (rand() & 31) - 16;
            tag->unkC = func_8003636C(120, 150);
            tag->unkE = 1;
            tag->unk12 = 3;
            break;
        }
        case 170:
            newMoby->unknown3[0] = 0;
            newMoby->animationProgress = 0;
            newMoby->animationState.frame = 0;
            newMoby->animationState.nextFrame = 0;
            if (linkedMoby) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            newMoby->size = 0x18;
            newMoby->lowDrawDistance = 0x28;
            func_80055C24(newMoby);
            break;
        case 197: {
            Spawn50Tag197* tag = newMoby->mobyTag;
            register Moby* child __asm__("$17");
            if (linkedMoby && linkedMoby->mobyClass != mobyClass) {
                if (linkedMoby->mobyClass == 99 &&
                    (camera.cameraState == 31 || camera.cameraState == 40)) {
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    if (camera.cameraState == 40)
                        newMoby->position.z -= 128;
                    func_8004F178(&frame.vector20, &newMoby->position);
                } else {
                    func_80055D24(linkedMoby, 5);
                    func_80055F14(linkedMoby, 0, &frame.vector20);
                    frame.vector10.x = 600;
                    frame.vector10.y = 0;
                    frame.vector10.z = 0;
                    func_8004ED6C(&linkedMoby->rotationMatrix, &frame.vector10, &frame.vector10);
                    func_8004F194(&newMoby->position, &frame.vector20, &frame.vector10);
                }
            } else
                func_8004F178(&newMoby->position, &spyro.position);
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 40;
            newMoby->updateDistance = 255;
            if (linkedMoby) {
                if (linkedMoby->mobyClass == 197) {
                    unsigned int link = linkedMoby->linkedMoby;
                    if (link < 255) {
                        register unsigned int byteOffset __asm__("$4") = link * 0x58;
                        MATCHING_KEEP(byteOffset);
                        newMoby->linkedMoby = Spawn50LinkIndex(byteOffset);
                    }
                }
                if (linkedMoby && linkedMoby->mobyClass != 197) {
                    int roll, pitch, yaw;
                    register int alpha __asm__("$2");
                    unsigned short pitchWord;
                    func_8003BABC(newMoby, 0, 0);
                    newMoby->size = 60;
                    tag->timer10 = 300;
                    tag->wordC = 600;
                    tag->vector0.x = 600;
                    tag->vector0.y = 0;
                    tag->vector0.z = 0;
                    newMoby->colour.r = 255;
                    newMoby->colour.g = 255;
                    newMoby->colour.b = 255;
                    newMoby->colour.a = 63;
                    if (linkedMoby->mobyClass == 99) {
                        if (D_8006C5BC == 44 && D_80071A04) {
                            Moby* candidate;
                            Vector3D* position;
                            Vector3D* workVector;
                            for (candidate = mobyArrayPtr; candidate < D_8006C704; candidate++) {
                                if (candidate->mobyClass == 962)
                                    break;
                            }
                            workVector = &frame.vector30;
                            func_8004F178(workVector,
                                          (Vector3D*)((unsigned char*)candidate->mobyTag + 0x1C));
                            child = 0;
                            position = &newMoby->position;
                            newMoby->position.z -= 256;
                            tag->wordC = 4096;
                            newMoby->state = 0;
                            newMoby->angle.roll = (unsigned short)camera.unk44 >> 4;
                            newMoby->angle.pitch = -(int)camera.unk46 >> 4;
                            newMoby->angle.yaw = (unsigned short)camera.unk48 >> 4;
                            if (func_80013E38(position, workVector, 0))
                                func_8004F1C8(workVector, workVector, position);
                            else
                                func_8004F1C8(workVector, &D_80071900.D_80071900, position);
                            func_8004F08C(workVector, func_8004EDE8(workVector, 1), tag->wordC);
                            func_8004F178(&tag->vector0, workVector);
                            newMoby->angle.pitch =
                                func_8004E880(func_8004EDE8(&tag->vector0, 1), tag->vector0.z, 0);
                            newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                        } else if (linkedMoby->mobyClass == 99) {
                            SHORTMATRIX* matrix;
                            int* modePointer;
                            int vectorX;
                            unsigned short yawWord;
                            modePointer = &camera.cameraState;
                            if (*modePointer == 40) {
                                vectorX = 600;
                                matrix = &frame.work40.matrix;
                                goto cameraMatrix197;
                            }
                            if (*modePointer == 31) {
                                tag->wordC = 4096;
                                vectorX = 4096;
                                matrix = &frame.work58.matrix;
                            cameraMatrix197:
                                tag->vector0.x = vectorX;
                                newMoby->state = 0;
                                newMoby->angle.roll = (unsigned short)camera.unk44 >> 4;
                                newMoby->angle.pitch = -(int)camera.unk46 >> 4;
                                yawWord = camera.unk48;
                                __asm__("" : : : "$17", "memory");
                                child = 0;
                                newMoby->angle.yaw = yawWord >> 4;
                                func_8004ECF4(matrix, (unsigned char*)modePointer - 0x38);
                                func_8004ED6C(matrix, &tag->vector0, &tag->vector0);
                            } else {
                                newMoby->state = 5;
                                goto rotated197;
                            }
                        } else
                            goto ordinary197;
                    } else {
                    ordinary197:
                        newMoby->state = 0;
                        tag->byteE = 1;
                    rotated197:
                        newMoby->angle.yaw = linkedMoby->angle.yaw;
                        func_8004ED6C(&linkedMoby->rotationMatrix, &tag->vector0, &tag->vector0);
                        newMoby->angle.pitch =
                            func_8004E880(func_8004EDE8(&tag->vector0, 1), tag->vector0.z, 0);
                        newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                        child = SpawnMoby(197, newMoby);
                    }
                    MATCHING_KEEP(child);
                    if (child) {
                        Spawn50Tag197* childTag = child->mobyTag;
                        Moby* second;
                        childTag->timer10 = 3;
                        roll = func_8003636C(0, 255);
                        child->angle.roll = roll;
                        yaw = (((short)camera.unk48 >> 4) + 128) & 255;
                        child->angle.yaw = yaw;
                        pitchWord = camera.unk46;
                        child->state = 1;
                        pitch = (pitchWord >> 4) & 255;
                        child->angle.pitch = pitch;
                        if (linkedMoby->mobyClass == 99) {
                            alpha = 255;
                            child->colour.r = alpha;
                            alpha = 13;
                            child->colour.g = 0;
                        } else {
                            alpha = 255;
                            child->colour.g = alpha;
                            alpha = 12;
                            child->colour.r = 0;
                        }
                        MATCHING_KEEP(alpha);
                        child->colour.b = 0;
                        child->colour.a = alpha;
                        __asm__("" : : : "$4", "$5", "memory");
                        func_8004F178(&child->position, &frame.vector20);
                        func_8004F178(&childTag->vector0, &frame.vector20);
                        func_80034F80(child, 1);
                        second = SpawnMoby(197, newMoby);
                        if (second) {
                            Spawn50Tag197* secondTag = second->mobyTag;
                            secondTag->timer10 = 3;
                            second->colour.r = 255;
                            second->colour.g = 255;
                            second->colour.b = 255;
                            second->colour.a = 15;
                            second->angle.roll = roll;
                            second->angle.pitch = pitch;
                            second->angle.yaw = yaw;
                            second->state = 3;
                            func_8004F178(&second->position, &frame.vector20);
                            func_8004F178(&secondTag->vector0, &frame.vector20);
                            func_80034F80(second, 3);
                        }
                    }
                    if (linkedMoby->mobyClass == 99 && camera.cameraState == 31) {
                        child = SpawnMoby(197, 0);
                        MATCHING_KEEP(child);
                        tag->child14 = child;
                        if (child) {
                            unsigned char childYaw;
                            child->angle.pitch = newMoby->angle.pitch;
                            childYaw = newMoby->angle.yaw;
                            child->state = 2;
                            child->angle.yaw = childYaw;
                            func_8004F178(&child->position, &newMoby->position);
                            child->colour.r = 255;
                            child->colour.g = 0;
                            child->colour.b = 0;
                            child->colour.a = 13;
                            func_80034F80(child, 3);
                        }
                    } else {
                        child = SpawnMoby(197, 0);
                        MATCHING_KEEP(child);
                        tag->child14 = child;
                        if (child) {
                            unsigned char childYaw;
                            child->angle.pitch = newMoby->angle.pitch;
                            childYaw = newMoby->angle.yaw;
                            child->state = 2;
                            child->angle.yaw = childYaw;
                            func_8004F178(&child->position, &newMoby->position);
                            func_80034F80(child, 4);
                            if (linkedMoby->mobyClass == 99) {
                                alpha = 255;
                                child->colour.r = alpha;
                                alpha = 56;
                                child->colour.g = 0;
                            } else {
                                alpha = 255;
                                child->colour.g = alpha;
                                alpha = 56;
                                child->colour.r = 0;
                            }
                            MATCHING_KEEP(alpha);
                            child->colour.b = 0;
                            child->colour.a = alpha;
                        }
                    }
                }
            }
            break;
        }
        case 224: {
            Spawn50Tag224* tag = newMoby->mobyTag;
            func_80055C24(newMoby);
            func_8004F178(&newMoby->position, &linkedMoby->position);
            tag->unk4 = 32;
            newMoby->size = 127;
            newMoby->colour.r = tag->unk4;
            MATCHING_BARRIER_VOLATILE("memory");
            newMoby->colour.g = tag->unk4;
            MATCHING_BARRIER_VOLATILE("memory");
            {
                int blueWord = tag->unk4;
                MATCHING_BARRIER_VOLATILE("memory");
                newMoby->colour.a = 63;
                newMoby->colour.b = blueWord;
            }
            break;
        }
        case 260:
            func_80055C24(newMoby);
            newMoby->colour.r = 2;
            if (linkedMoby != 0) {
                ((MobyTag_260*)newMoby->mobyTag)->unk0 = linkedMoby;
                func_8004F178(&newMoby->position, &linkedMoby->position);
                newMoby->updateDistance = 10;
                newMoby->lowDrawDistance = 8;
                newMoby->position.z += 0x400;
            } else {
                newMoby->unknown = -1;
            }
            break;
        case 272: {
            MobyTag_272* mobyTag;
            mobyTag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &spyro.position);
            newMoby->position.z += 0x400;
            newMoby->angle.yaw = spyro.bodyRotation.yaw;
            func_80055C24(newMoby);
            mobyTag->unk2 = 2;
            mobyTag->unk3 = spyro.bodyRotation.yaw;
            mobyTag->unk4 = spyro.bodyRotation.yaw;
            mobyTag->unk10 = -1;
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            break;
        }
        case 308: {
            MobyTag_Fragment* mobyTag;
            int azimuth;
            int elevation;
            mobyTag = newMoby->mobyTag;
            newMoby->lowDrawDistance = 0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            azimuth = rand() & 0xFFF;
            elevation = rand() & 0x7FF;
            mobyTag->linearVel.x =
                (func_8004EA2C(elevation) * func_8004EA2C(azimuth) * linkedMoby->substate) >> 0x18;
            mobyTag->linearVel.y =
                (func_8004EA2C(elevation) * func_8004E9E4(azimuth) * linkedMoby->substate) >> 0x18;
            mobyTag->linearVel.z = (func_8004E9E4(elevation) * linkedMoby->substate) >> 0xC;
            if (linkedMoby->damageFlags & 0x02000000) {
                frame.work40.vector.x =
                    D_80065920[func_8004E880(newMoby->position.x - spyro.position.x,
                                             newMoby->position.y - spyro.position.y, 0)];
                frame.work40.vector.x = (short)frame.work40.vector.x >> 4;
                frame.work40.vector.y =
                    D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x,
                                             newMoby->position.y - spyro.position.y, 0)];
                frame.work40.vector.y = (short)frame.work40.vector.y >> 4;
                frame.work40.vector.z = 0;
                mobyTag->linearVel.x += frame.work40.vector.x;
                mobyTag->linearVel.y += frame.work40.vector.y;
            } else if ((linkedMoby->damageFlags & 0x20000) &&
                       ((spyro.movementState == 4) || (spyro.movementState == 0xC))) {
                mobyTag->linearVel.x += spyro.unk7a[2].x >> 6;
                mobyTag->linearVel.y += spyro.unk7a[2].y >> 6;
            }
            if ((linkedMoby->unkb != 0) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->linearVel.x += (D_80065920[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->linearVel.y += (D_800658A0[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->linearVel.z += func_8003636C(0x28, 0x46);
            }
            newMoby->position.x += mobyTag->linearVel.x * 4;
            newMoby->position.y += mobyTag->linearVel.y * 4;
            newMoby->position.z += mobyTag->linearVel.z * 4;
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            mobyTag->angularVel.x = (rand() & 0x1F) - 0x10;
            mobyTag->angularVel.y = (rand() & 0x1F) - 0x10;
            mobyTag->angularVel.z = (rand() & 0x1F) - 0x10;
            mobyTag->unk10 = linkedMoby->position.z - 0x40;
            mobyTag->timer = func_8003636C(0x32, 0x50);
            break;
        }
        case 326: {
            MobyTag_326* mobyTag;
            mobyTag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            mobyTag->unk0 = 0x10;
            newMoby->colour.a = 0x3B;
            newMoby->colour.r = 0x80;
            newMoby->colour.g = 0x80;
            newMoby->colour.b = 0;
            if ((linkedMoby->mobyClass == 0x198) || (linkedMoby->mobyClass == 0x2C2)) {
                mobyTag->unk2 = 1;
                mobyTag->unk3 = 1;
                newMoby->size = 0x7F;
            } else {
                if (linkedMoby->mobyClass == 0x270) {
                    mobyTag->unk2 = 2;
                    newMoby->colour.r = 0xE0;
                    newMoby->colour.g = 0xE0;
                    newMoby->colour.b = 0xE0;
                    newMoby->colour.a = 0x3B;
                    mobyTag->unk3 = 0;
                    newMoby->size = 0x60;
                } else {
                    mobyTag->unk2 = 0;
                    mobyTag->unk3 = 0;
                    newMoby->size = 0x60;
                }
            }
            newMoby->unknown4 = 0xFE;
            newMoby->angle.pitch =
                func_8004E880(func_8004F334(&newMoby->position, &camera.nextCameraPosCartesian),
                              camera.nextCameraPosCartesian.z - newMoby->position.z, 0) -
                0x40;
            newMoby->angle.yaw =
                func_8004E880(camera.nextCameraPosCartesian.x - newMoby->position.x,
                              camera.nextCameraPosCartesian.y - newMoby->position.y, 0);
            break;
        }
        case 491: {
            register Spawn14Tag84* mobyTag __asm__("$20");
            int elevation;
            int azimuth;
            int radius;
            int radius2;
            mobyTag = newMoby->mobyTag;
            newMoby->lowDrawDistance = 0x20;
            newMoby->highDrawDistance = 0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = func_8003636C(0x12C, 0x834);
            azimuth = (spyro.bodyRotation.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius = 0x78;
            mobyTag->unk0.x =
                ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y =
                ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2 = 0x96;
            mobyTag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0xF) >> 9;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0xF) >> 9;
                mobyTag->unk0.z += func_8003636C(70, 100);
            }
            frame.work58.vector.x = 0;
            frame.work58.vector.y = 0;
            frame.work58.vector.z = 256;
            frame.angle70.roll = linkedMoby->angle.roll;
            frame.angle70.pitch = linkedMoby->angle.pitch;
            frame.angle70.yaw = linkedMoby->angle.yaw;
            func_8004EA90(&frame.angle70, &frame.work40.matrix, 0);
            func_8004ED6C(&frame.work40.matrix, &frame.work58.vector, &frame.work58.vector);
            func_8004F194(&newMoby->position, &newMoby->position, &frame.work58.vector);
            frame.work58.vector.x = mobyTag->unk0.x;
            frame.work58.vector.y = mobyTag->unk0.y;
            frame.work58.vector.z = mobyTag->unk0.z;
            func_8004ED6C(&frame.work40.matrix, &frame.work58.vector, &frame.work58.vector);
            mobyTag->unk0.x = frame.work58.vector.x;
            mobyTag->unk0.y = frame.work58.vector.y;
            mobyTag->unk0.z = frame.work58.vector.z;
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x37) >> 0xA;
            } else {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
            }
            newMoby->angle.roll = rand();
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->position.x += mobyTag->unk0.x * 2;
            newMoby->position.y += mobyTag->unk0.y * 2;
            newMoby->position.z += mobyTag->unk0.z * 2;
            mobyTag->unk6.x = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z = (rand() & 0x1F) - 0x10;
            mobyTag->unkC = func_8003636C(90, 150);
            mobyTag->unkE = 1;
            break;
        }
        case 364:
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            func_80034F80(newMoby, 1);
            newMoby->state = 4;
            break;
        case 426: {
            Spawn10Tag426* tag426 = newMoby->mobyTag;
            Spawn10Tag54View* linkedTag54A = linkedMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.pitch = 32;
            func_80055C24(newMoby);
            tag426->unk0 = 0;
            tag426->unk4 = linkedTag54A->unk54;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            break;
        }
        case 427: {
            Vector3D* position = &newMoby->position;
            Spawn10Tag427* tag427 = newMoby->mobyTag;
            Spawn10Tag54View* linkedTag54B = linkedMoby->mobyTag;
            func_8004F178(position, &linkedMoby->position);
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            func_80055C24(newMoby);
            tag427->unk0 = 0;
            tag427->unk4 = linkedTag54B->unk54;
            tag427->unk8 = func_80050844(position, 6, 6, 0xFFFFFF);
            break;
        }
        case 482: {
            int* tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            *tag = 16;
            newMoby->colour.a = 63;
            newMoby->colour.r = 128;
            newMoby->colour.g = 64;
            newMoby->colour.b = 0;
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->size = 70;
            newMoby->unknown4 = 4;
            break;
        }
        case 483: {
            Spawn50Tag483* tag = newMoby->mobyTag;
            int greenByte;
            Moby* arenaMoby;
            int allocationBytes;
            int* arena;
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            if (!linkedMoby) {
                frame.vector78.x = 440;
                frame.vector78.y = 0;
                frame.vector78.z = 0;
                if (camera.cameraState == 7 && camera.unk50 == 3) {
                    Vector3D* cameraPosition = &newMoby->position;
                    func_8004F178(cameraPosition, &camera.nextCameraPosCartesian);
                    frame.angle70.roll = 0;
                    frame.angle70.pitch = -((short)camera.unk46 >> 4);
                    frame.angle70.yaw = (unsigned short)camera.unk48 >> 4;
                    func_8004EA90(&frame.angle70, &frame.matrix88, 0);
                    func_8004ED6C(&frame.matrix88, &frame.vector78, &frame.vector78);
                    func_8004F194(cameraPosition, cameraPosition, &frame.vector78);
                    func_8004F194(cameraPosition, cameraPosition, &frame.vector78);
                    func_8004F194(cameraPosition, cameraPosition, &frame.vector78);
                } else {
                    Vector3D* actorPosition;
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    frame.angleB8.roll = 0;
                    frame.angleB8.pitch = spyro.bodyRotation.pitch;
                    if (spyro.ticksSinceLastSurfaceTouch == 0 &&
                        (unsigned char)(spyro.bodyRotation.pitch - 4) >= 249)
                        frame.angleB8.pitch = 0;
                    frame.angleB8.yaw = spyro.bodyRotation.yaw;
                    func_8004EA90(&frame.angleB8, &frame.matrixA0, 0);
                    func_8004ED6C(&frame.matrixA0, &frame.vector78, &frame.vector78);
                    actorPosition = &newMoby->position;
                    actorPosition->x = 500;
                    actorPosition->y = 0;
                    actorPosition->z = 0;
                    func_8004ED6C(&frame.matrixA0, actorPosition, actorPosition);
                    func_8004F194(actorPosition, actorPosition, &spyro.position);
                }
                newMoby->angle.pitch =
                    func_8004E880(func_8004EDE8(&frame.vector78, 0), frame.vector78.z, 0);
                newMoby->angle.yaw = func_8004E880(frame.vector78.x, frame.vector78.y, 0);
                arenaMoby = mobyArrayPtr;
                tag->vector0.x = frame.vector78.x;
                tag->vector0.y = frame.vector78.y;
                tag->vector0.z = frame.vector78.z;
                allocationBytes = 0x144;
                for (; arenaMoby < D_8006C704; arenaMoby++) {
                    if (arenaMoby->mobyClass == 1020)
                        break;
                }
                if (arenaMoby) {
                    arena = arenaMoby->mobyTag;
                    if (arena[1] > allocationBytes)
                        allocationBytes = arena[1];
                    arena[0] += allocationBytes;
                    if (arena[0] + allocationBytes >= arena[2])
                        arena[0] = 0;
                    tag->buffer8 = (int*)((char*)arena + (arena[0] + 0x14));
                    *tag->buffer8 = 0;
                    func_8004E7D4(tag->words10, arena + 3, 8);
                }
                finishMoby = newMoby;
                finishArg1 = 0;
                finishArg2 = 0;
                MATCHING_KEEP3_CLOBBER(finishMoby, finishArg1, finishArg2, "$2");
                tag->byte7 = 110;
                goto finishSpawn50;
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            tag->byte7 = 48;
            newMoby->size = 127;
            newMoby->colour.r = (tag->byte7 * 3) >> 1;
            greenByte = tag->byte7;
            newMoby->colour.b = 0;
            newMoby->colour.a = 63;
            newMoby->colour.g = greenByte;
            break;
        }
        case 541: {
            int* tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            *tag = 24;
            newMoby->colour.a = 48;
            newMoby->colour.r = 0;
            newMoby->colour.g = 0;
            newMoby->colour.b = 0;
            newMoby->size = 100;
            newMoby->unknown4 = 0;
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            break;
        }
        case 604: {
            Spawn50Tag604* tag = newMoby->mobyTag;
            Spawn50Tag604* cursor;
            Spawn50EffectView* effect;
            int count;
            if (linkedMoby)
                func_8004F178(&newMoby->position, &linkedMoby->position);
            else
                func_8004F178(&newMoby->position, &spyro.position);
            func_80055C24(newMoby);
            if (linkedMoby) {
                newMoby->updateDistance = 255;
                newMoby->lowDrawDistance = 63;
                newMoby->state = 10;
                newMoby->size = 254;
                *(unsigned int*)&newMoby->colour = 0x3FFFFFFF;
                effect = (Spawn50EffectView*)func_8002EC50(1, 16, 0x20FFFF);
                count = 0;
                cursor = tag;
                cursor->effect8 = effect;
                effect->byte10 = 4;
                cursor->effect8->byte13 = 8;
                do {
                    Moby* child = SpawnMoby(604, 0);
                    register int initialState __asm__("$2");
                    register short* childTag __asm__("$3");
                    if (child) {
                        func_8004F178(&child->position, &newMoby->position);
                        childTag = child->mobyTag;
                        MATCHING_OBSERVE_CLOBBER(childTag, "$2");
                        initialState = 20;
                        MATCHING_KEEP(initialState);
                        child->state = initialState;
                        child->updateDistance = 255;
                        child->substate = count + 1;
                        child->unknown3[0] = 0;
                        child->lowDrawDistance = 0;
                        child->drawn = 0;
                        *(int*)((unsigned char*)child + 8) = 0;
                        *childTag = 10;
                        cursor->childrenC[0] = child;
                    }
                    count++;
                    cursor = (Spawn50Tag604*)((unsigned char*)cursor + 4);
                } while (count < 3);
                return newMoby;
            }
            break;
        }
        case 716: {
            int allocationBytes = 352;
            Vector3D* position = &newMoby->position;
            Spawn50Tag716* tag = newMoby->mobyTag;
            int* owner;
            register Vector3D* callPosition __asm__("$4");
            register Vector3D* linkedPosition __asm__("$5");
            Vector3D* player98;
            int angleStep;
            int distance, multiplier;
            register Spawn50Payload716* payload __asm__("$3");
            register int z __asm__("$2");
            callPosition = position;
            MATCHING_OBSERVE(callPosition);
            linkedPosition = &linkedMoby->position;
            MATCHING_OBSERVE(linkedPosition);
            owner = (mobyArrayPtr + ((int*)linkedMoby->mobyTag)[3])->mobyTag;
            angleStep = 16;
            func_8004F178(callPosition, linkedPosition);
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            frame.vectorC0.x = 440;
            frame.vectorC0.y = 0;
            frame.vectorC0.z = 0;
            frame.angleB8.roll = 0;
            frame.angleB8.pitch = func_8004E880(func_8004F334(position, &spyro.position),
                                                spyro.position.z - newMoby->position.z, 0);
            frame.angleB8.yaw = func_8004E880(spyro.position.x - newMoby->position.x,
                                              spyro.position.y - newMoby->position.y, 0);
            distance = func_8004F334(position, &spyro.position);
            if (distance < 20000)
                angleStep = 8;
            if (rand() & 1)
                frame.angleB8.yaw += angleStep;
            else
                frame.angleB8.yaw -= angleStep;
            func_8004EA90(&frame.angleB8, &frame.matrix88, 0);
            func_8004ED6C(&frame.matrix88, &frame.vectorC0, &tag->vector0);
            newMoby->angle.roll = frame.angleB8.roll;
            newMoby->angle.pitch = frame.angleB8.pitch;
            newMoby->angle.yaw = frame.angleB8.yaw;
            if (owner[1] > allocationBytes)
                allocationBytes = owner[1];
            if (owner[0] + allocationBytes >= owner[2])
                owner[0] = 0;
            tag->bufferC = (Spawn50Payload716*)((unsigned char*)owner + (owner[0] + 0x14));
            tag->bufferC->cursor0 = (int*)((unsigned char*)tag->bufferC + 0x1C);
            *tag->bufferC->cursor0 = 0;
            func_8004E7D4(tag->bufferC->words8, owner + 3, 8);
            owner[0] += allocationBytes;
            tag->bufferC->word4 = 0;
            multiplier = (distance / 440) * 2;
            player98 = (Vector3D*)((unsigned char*)&spyro + 0x98);
            func_8004F178(&tag->bufferC->vector10, player98);
            tag->bufferC->vector10.x *= multiplier;
            tag->bufferC->vector10.y *= multiplier;
            tag->bufferC->vector10.z *= multiplier;
            func_8004F110(&tag->bufferC->vector10, 6);
            func_8004F194(&tag->bufferC->vector10, &tag->bufferC->vector10,
                          (Vector3D*)((unsigned char*)player98 - 0x98));
            finishMoby = newMoby;
            payload = tag->bufferC;
            MATCHING_OBSERVE_CLOBBER(payload, "$5");
            finishArg1 = 0;
            z = payload->vector10.z;
            MATCHING_OBSERVE_CLOBBER(z, "$6");
            finishArg2 = 0;
            payload->vector10.z = z + 512;
            tag->word10 = 110;
            tag->word14 = 30;
            tag->word12 = 10;
            MATCHING_KEEP3(finishMoby, finishArg1, finishArg2);
        finishSpawn50:
            newMoby->unknown5 = 1;
            func_8003BABC(finishMoby, finishArg1, finishArg2);
            return newMoby;
        }
        case 751: {
            Spawn50Tag751* tag = newMoby->mobyTag;
            int timer = 1000;
            register int yaw __asm__("$3");
            register int alpha __asm__("$2");
            if (linkedMoby) {
                int* linkedTag = linkedMoby->mobyTag;
                Moby* child;
                func_80055D24(linkedMoby, 4);
                frame.vectorD0.x = 1024;
                frame.vectorD0.y = 0;
                frame.vectorD0.z = 0;
                func_8004ED6C(&linkedMoby->rotationMatrix, &frame.vectorD0, &frame.vectorD0);
                func_8004F194(&newMoby->position, &linkedMoby->position, &frame.vectorD0);
                func_80055C24(newMoby);
                func_8003BABC(newMoby, 1, 0);
                newMoby->updateDistance = 255;
                newMoby->lowDrawDistance = 63;
                newMoby->size = 96;
                newMoby->angle.roll = linkedMoby->angle.roll;
                newMoby->angle.pitch = linkedMoby->angle.pitch;
                __asm__("" : : : "$2", "$3", "memory");
                alpha = 58;
                MATCHING_KEEP_CLOBBER(alpha, "$3");
                yaw = linkedMoby->angle.yaw;
                MATCHING_KEEP(yaw);
                newMoby->colour.a = alpha;
                newMoby->colour.r = 255;
                newMoby->angle.yaw = yaw;
                tag->word2 = timer;
                tag->word0 = 200;
                tag->word4 = 0;
                tag->wordC = linkedTag[5];
                func_80055D24(newMoby, 4);
                child = SpawnMoby(751, 0);
                if (child) {
                    Spawn50Tag751* childTag = child->mobyTag;
                    tag->child8 = child;
                    child->updateDistance = 255;
                    child->lowDrawDistance = 63;
                    child->size = 128;
                    func_8004F178(&child->position, &newMoby->position);
                    child->angle.roll = newMoby->angle.roll;
                    child->angle.pitch = newMoby->angle.pitch;
                    yaw = newMoby->angle.yaw;
                    MATCHING_KEEP(yaw);
                    child->substate = 1;
                    child->colour.a = 63;
                    child->colour.r = 255;
                    child->colour.g = 255;
                    child->colour.b = 64;
                    child->angle.yaw = yaw;
                    childTag->word2 = timer;
                    childTag->word0 = 200;
                    childTag->word4 = 0;
                    func_80055D24(child, 4);
                    return newMoby;
                }
                break;
            }
            goto defaultSpawn50;
        }
        case 1000: {
            Spawn50FactoryTag* tag = newMoby->mobyTag;
            int sourceIndex;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->updateDistance = 255;
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->position.z += 256;
            sourceIndex = ((int*)linkedMoby->mobyTag)[3];
            if (sourceIndex >= 0) {
                Moby* sourceMoby = mobyArrayPtr + sourceIndex;
                int* owner = sourceMoby->mobyTag;
                tag->buffer4 = (int*)((unsigned char*)owner + (owner[0] + 0x14));
                owner[0] += 0xEB0;
                if (owner[0] >= 0x4970)
                    owner[0] = 0;
                func_8004E7AC(tag->buffer4, 0, 0xEB0);
                tag->word0 = 32;
                tag->word2 = 25;
                tag->word14 = 15;
                tag->word16 = 30;
                tag->parent10 = sourceMoby;
            }
            break;
        }
        case 1015: {
            Spawn50FactoryTag* tag = newMoby->mobyTag;
            int sourceIndex, state, yaw, z;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            state = linkedMoby->substate;
            newMoby->updateDistance = 255;
            z = newMoby->position.z;
            newMoby->state = state;
            yaw = linkedMoby->angle.yaw;
            newMoby->position.z = z + 256;
            newMoby->angle.yaw = yaw;
            sourceIndex = ((int*)linkedMoby->mobyTag)[3];
            if (sourceIndex >= 0) {
                Moby* sourceMoby = mobyArrayPtr + sourceIndex;
                int* owner = sourceMoby->mobyTag;
                tag->buffer4 = (int*)((unsigned char*)owner + (owner[0] + 0x14));
                owner[0] += 0x9C0;
                if (owner[0] >= owner[2])
                    owner[0] = 0;
                func_8004E7AC(tag->buffer4, 0, 0x9C0);
                tag->word0 = 200;
                tag->word2 = 200;
                tag->parent10 = sourceMoby;
            }
            break;
        }
        default:
        defaultSpawn50:
            {
                if (linkedMoby) {
                    func_8004F178(&newMoby->position, &linkedMoby->position);
                } else {
                    func_8004F178(&newMoby->position, &spyro.position);
                }
                func_80055C24(newMoby);
                break;
            }
    }
    return newMoby;
}
