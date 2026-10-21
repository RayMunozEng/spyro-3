#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_44_80087CDC:
* SCUS-94467 USA Rev0, 1146 original words; original assembly SHA256
* 8349d260ebbf78905b45bfabdf8a207cf8a162bb60abcb502a3e6ce69d3531a4.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Existing20 common/fragments and credited effect C are reused.
* Original197/740/1005/1015 retain branch conditions, exact selectors,
* counts and layouts. Stack adapter preserves original SP10/20/30/40/58
* objects, the observed70..77 gap and first saved register at78. The SP40
* matrix/vector union is only a local storage view of disjoint paths.
* In197, byteOffset=a0 is the original index*88 producer; the inline link
* calculation retains88*0x45D1745D=-8 modulo2^32, recovering0..254 exactly.
* Original signed camera-pitch load/negation/shift, collision branches,
* matrix source and repeated child stores remain exact. Empty constraints
* keep original initialized child s1 and color v0 producers. Color values
* are defined only after their conditions; no live predicate is overwritten.
* Empty dead-register/memory boundaries retain original store scheduling
* and emit no CPU instructions. All used type fields are retained; no
* complete game/helper/asset/units/frame contract is inferred.
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
} Spawn44Tag197;
typedef struct {
    short word0, word2;
    void* buffer4;
    int word8, wordC;
    Moby* parent10;
    int word14;
} Spawn44FactoryTag;
static __inline__ int Spawn44LinkIndex(int byteOffset) {
    return (int)(0U - (unsigned int)byteOffset * 0x45D1745DU) >> 3;
}
Moby* func_level_44_80087CDC(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
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
        SHORTMATRIX matrix58;
        int gap6C;
        int gap70[2];
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
        case 16:
        case 211: {
            MobyTag_16* mobyTag;
            int extraLifeThreshold;
            mobyTag = newMoby->mobyTag;
            if (newMoby->mobyClass == 0x10) {
                extraLifeThreshold = 10;
                if (D_8006C784 < 4)
                    extraLifeThreshold = 7;
                else if (D_8006C784 < 7)
                    extraLifeThreshold = 9;
                sparx.butterflyCount++;
                if (sparx.butterflyCount >= extraLifeThreshold) {
                    sparx.butterflyCount = 0;
                    newMoby->mobyClass = 0xD3;
                }
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            newMoby->position.z += 0x200;
            func_8004F178(&mobyTag->unk0, &newMoby->position);
            newMoby->unknown = -1;
            newMoby->unknown4 = 2;
            mobyTag->unkE = 0x708;
            mobyTag->unk11 = 0;
            mobyTag->unk12 = (char)(rand() & 0xFC);
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
            Spawn44Tag197* tag = newMoby->mobyTag;
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
                        __asm__("" : " = r"(byteOffset) : "0"(byteOffset));
                        newMoby->linkedMoby = Spawn44LinkIndex(byteOffset);
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
                                matrix = &frame.matrix58;
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
                    __asm__("" : " = r"(child) : "0"(child));
                    if (child) {
                        Spawn44Tag197* childTag = child->mobyTag;
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
                        __asm__("" : " = r"(alpha) : "0"(alpha));
                        child->colour.b = 0;
                        child->colour.a = alpha;
                        __asm__("" : : : "$4", "$5", "memory");
                        func_8004F178(&child->position, &frame.vector20);
                        func_8004F178(&childTag->vector0, &frame.vector20);
                        func_80034F80(child, 1);
                        second = SpawnMoby(197, newMoby);
                        if (second) {
                            Spawn44Tag197* secondTag = second->mobyTag;
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
                        __asm__("" : " = r"(child) : "0"(child));
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
                        __asm__("" : " = r"(child) : "0"(child));
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
                            __asm__("" : " = r"(alpha) : "0"(alpha));
                            child->colour.b = 0;
                            child->colour.a = alpha;
                        }
                    }
                }
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
        case 310:
        case 568:
        case 306:
        case 307:
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
        case 740: {
            Spawn14Tag84* tag = newMoby->mobyTag;
            int elevation, azimuth, coefficient100;
            newMoby->lowDrawDistance = 32;
            newMoby->highDrawDistance = 32;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = func_8003636C(0, 1023);
            azimuth = rand() & 4095;
            coefficient100 = 100;
            tag->unk0.x =
                ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * coefficient100)) >> 18;
            tag->unk0.y =
                ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * coefficient100)) >> 18;
            tag->unk0.z = (func_8004E9E4(elevation) * coefficient100) >> 12;
            newMoby->angle.roll = rand();
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->position.x += tag->unk0.x * 2;
            newMoby->position.y += tag->unk0.y * 2;
            newMoby->position.z += tag->unk0.z * 2;
            tag->unk6.x = (rand() & 31) - 16;
            tag->unk6.y = (rand() & 31) - 16;
            tag->unk6.z = (rand() & 31) - 16;
            tag->unkC = func_8003636C(90, 150);
            tag->unkE = 1;
            tag->unk12 = 0;
            break;
        }
        case 1005: {
            Spawn44FactoryTag* tag = newMoby->mobyTag;
            Moby* sourceMoby;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->updateDistance = 255;
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            sourceMoby = mobyArrayPtr + ((int*)linkedMoby->mobyTag)[2];
            if (sourceMoby) {
                tag->buffer4 = (unsigned char*)sourceMoby->mobyTag + 0x14;
                func_8004E7AC(tag->buffer4, 0, 0x9D0);
                tag->word0 = 200;
                tag->parent10 = sourceMoby;
            }
            break;
        }
        case 1015: {
            Spawn44FactoryTag* tag = newMoby->mobyTag;
            int sourceIndex;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->state = linkedMoby->substate;
            newMoby->updateDistance = 255;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->position.z += 256;
            sourceIndex = *(int*)linkedMoby->mobyTag;
            if (sourceIndex >= 0) {
                Moby* sourceMoby = mobyArrayPtr + sourceIndex;
                tag->buffer4 = (unsigned char*)sourceMoby->mobyTag + 0x14;
                func_8004E7AC(tag->buffer4, 0, 0x9C0);
                tag->word0 = 200;
                tag->word2 = 200;
                tag->parent10 = sourceMoby;
            }
            break;
        }
        default: {
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
