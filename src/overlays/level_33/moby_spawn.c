#include "matching.h"
#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_33_80091DAC:
* SCUS-94467 USA Rev0, 1479 original words; original assembly SHA256
* 66ffe9cb1e9ebf8ca26082de8d4751d8ae05fb8e90e3f49e3daee293ad4b9983.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Accepted44 class197, original20 class326 and accepted34
* classes482/483/541 are reused. Original33 selectors306/307/308/568 and
* fallback197 state5 remain exact. Observed frameF8/saveD0 retains all
* SP10/20/30/40/58/70/88/90/A8/B0 views and intervening raw padding. Matrix/
* vector unions describe local storage on disjoint paths, not game objects.
* New352 retains signed/unsigned camera loads and original child stores.
* New712 retains its linked-angle matrix and shares483's original1020 scan,
* payload14/max144 ring, byte7=110 and common final call. Full3-vector camera
* additions in483 are preserved. Initialized pointer/value constraints keep
* original s2/s3 positions, s6/s5 distance bytes and a0/a1/a2 call producers;
* empty dead-v0 boundaries preserve order and emit zero CPU instructions.
* No live predicate is overwritten. Cached position is recomputed only at
* the original separate linked-path producer. Raw used type fields and all
* frame padding are retained; only whole unused views/locals are removed.
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
} Spawn33Tag197;
static __inline__ int Spawn33LinkIndex(int byteOffset) {
    return (int)(0U - (unsigned int)byteOffset * 0x45D1745DU) >> 3;
}
typedef struct {
    Vector3D vector0;
    short wordC, wordE;
    Moby* child10;
    int word14;
} Spawn33Tag352;
typedef struct {
    Vector3D16 vector0;
    unsigned char byte6, byte7;
    int* buffer8;
    int wordC;
    int words10[2];
} Spawn33Tag483;
Moby* func_level_33_80091DAC(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    register Moby* finishMoby __asm__("$4");
    register int finishArg1 __asm__("$5");
    register int finishArg2 __asm__("$6");
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
        union {
            SHORTMATRIX matrix;
            Vector3D vector;
        } work70;
        int gap84;
        Angle angle88;
        unsigned char gap8B[8 - sizeof(Angle)];
        SHORTMATRIX matrix90;
        int gapA4;
        Angle angleA8;
        unsigned char gapAB[8 - sizeof(Angle)];
        SHORTMATRIX matrixB0;
        int gapC4;
        int gapC8[2];
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
        case 197: {
            Spawn33Tag197* tag = newMoby->mobyTag;
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
                        newMoby->linkedMoby = Spawn33LinkIndex(byteOffset);
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
                        Spawn33Tag197* childTag = child->mobyTag;
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
                            Spawn33Tag197* secondTag = second->mobyTag;
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
        case 352: {
            register Vector3D* position __asm__("$18") = &newMoby->position;
            register Vector3D* cameraPosition __asm__("$19");
            register Vector3D* callPosition __asm__("$4");
            Spawn33Tag352* tag;
            Moby* child;
            int yaw;
            callPosition = position;
            MATCHING_OBSERVE(callPosition);
            cameraPosition = &camera.nextCameraPosCartesian;
            tag = newMoby->mobyTag;
            func_8004F178(callPosition, cameraPosition);
            func_80055C24(newMoby);
            if (linkedMoby) {
                register int updateDistance __asm__("$22") = 255;
                register int lowDrawDistance __asm__("$21") = 63;
                MATCHING_KEEP2_CLOBBER(updateDistance, lowDrawDistance, "$2");
                newMoby->state = 1;
                newMoby->updateDistance = updateDistance;
                newMoby->lowDrawDistance = lowDrawDistance;
                newMoby->size = 32;
                newMoby->angle.yaw = ((short)camera.unk48 >> 4) - 128;
                newMoby->angle.pitch = (unsigned short)camera.unk46 >> 4;
                newMoby->angle.roll = func_8003636C(0, 255);
                tag->vector0.x = 999;
                tag->wordC = 200;
                tag->vector0.y = 0;
                tag->vector0.z = 0;
                tag->wordE = 1;
                func_8004ECF4(&frame.work40.matrix, (unsigned char*)cameraPosition - 0x14);
                func_8004ED6C(&frame.work40.matrix, &tag->vector0, &tag->vector0);
                child = SpawnMoby(197, 0);
                if (child) {
                    func_8004F178(&child->position, position);
                    child->angle.roll = newMoby->angle.roll;
                    child->angle.pitch = newMoby->angle.pitch;
                    yaw = newMoby->angle.yaw;
                    child->size = 48;
                    child->updateDistance = updateDistance;
                    child->lowDrawDistance = lowDrawDistance;
                    child->state = 3;
                    child->angle.yaw = yaw;
                    func_80034F80(child, 3);
                    *(unsigned int*)&child->colour = 0x3FFFFFFF;
                    ((Spawn33Tag197*)child->mobyTag)->timer10 = 1000;
                    tag->child10 = child;
                }
            }
            return newMoby;
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
            Spawn33Tag483* tag = newMoby->mobyTag;
            int greenByte;
            Moby* arenaMoby;
            int allocationBytes;
            int* arena;
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            if (!linkedMoby) {
                frame.work58.vector.x = 440;
                frame.work58.vector.y = 0;
                frame.work58.vector.z = 0;
                if (camera.cameraState == 7 && camera.unk50 == 3) {
                    Vector3D* cameraPosition = &newMoby->position;
                    func_8004F178(cameraPosition, &camera.nextCameraPosCartesian);
                    frame.angle88.roll = 0;
                    frame.angle88.pitch = -((short)camera.unk46 >> 4);
                    frame.angle88.yaw = (unsigned short)camera.unk48 >> 4;
                    func_8004EA90(&frame.angle88, &frame.work70.matrix, 0);
                    func_8004ED6C(&frame.work70.matrix, &frame.work58.vector, &frame.work58.vector);
                    func_8004F194(cameraPosition, cameraPosition, &frame.work58.vector);
                    func_8004F194(cameraPosition, cameraPosition, &frame.work58.vector);
                    func_8004F194(cameraPosition, cameraPosition, &frame.work58.vector);
                } else {
                    Vector3D* actorPosition;
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    frame.angleA8.roll = 0;
                    frame.angleA8.pitch = spyro.bodyRotation.pitch;
                    if (spyro.ticksSinceLastSurfaceTouch == 0 &&
                        (unsigned char)(spyro.bodyRotation.pitch - 4) >= 249)
                        frame.angleA8.pitch = 0;
                    frame.angleA8.yaw = spyro.bodyRotation.yaw;
                    func_8004EA90(&frame.angleA8, &frame.matrix90, 0);
                    func_8004ED6C(&frame.matrix90, &frame.work58.vector, &frame.work58.vector);
                    actorPosition = &newMoby->position;
                    actorPosition->x = 500;
                    actorPosition->y = 0;
                    actorPosition->z = 0;
                    func_8004ED6C(&frame.matrix90, actorPosition, actorPosition);
                    func_8004F194(actorPosition, actorPosition, &spyro.position);
                }
                newMoby->angle.pitch =
                    func_8004E880(func_8004EDE8(&frame.work58.vector, 0), frame.work58.vector.z, 0);
                newMoby->angle.yaw = func_8004E880(frame.work58.vector.x, frame.work58.vector.y, 0);
                arenaMoby = mobyArrayPtr;
                tag->vector0.x = frame.work58.vector.x;
                tag->vector0.y = frame.work58.vector.y;
                tag->vector0.z = frame.work58.vector.z;
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
                goto finishSpawn33;
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
        case 712: {
            Spawn33Tag483* tag = newMoby->mobyTag;
            register Vector3D* position __asm__("$18");
            register Vector3D* linkedPosition __asm__("$19");
            register Vector3D* callPosition __asm__("$4");
            int greenByte;
            Moby* arenaMoby;
            int allocationBytes;
            int* arena;
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            position = &newMoby->position;
            if (linkedMoby->mobyClass != mobyClass) {
                callPosition = position;
                MATCHING_OBSERVE(callPosition);
                linkedPosition = &linkedMoby->position;
                frame.work70.vector.x = 440;
                frame.work70.vector.y = 0;
                frame.work70.vector.z = 0;
                func_8004F178(callPosition, linkedPosition);
                frame.angleA8.roll = 0;
                frame.angleA8.pitch = linkedMoby->angle.pitch;
                frame.angleA8.yaw = linkedMoby->angle.yaw;
                func_8004EA90(&frame.angleA8, &frame.matrixB0, 0);
                func_8004ED6C(&frame.matrixB0, &frame.work70.vector, &frame.work70.vector);
                position->x = 500;
                position->y = 0;
                position->z = 0;
                func_8004ED6C(&frame.matrixB0, position, position);
                func_8004F194(position, position, linkedPosition);
                newMoby->angle.pitch =
                    func_8004E880(func_8004EDE8(&frame.work70.vector, 0), frame.work70.vector.z, 0);
                newMoby->angle.yaw = func_8004E880(frame.work70.vector.x, frame.work70.vector.y, 0);
                arenaMoby = mobyArrayPtr;
                tag->vector0.x = frame.work70.vector.x;
                tag->vector0.y = frame.work70.vector.y;
                tag->vector0.z = frame.work70.vector.z;
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
            finishSpawn33:
                newMoby->unknown5 = 1;
                func_8003BABC(finishMoby, finishArg1, finishArg2);
                return newMoby;
            }
            MATCHING_KEEP(newMoby);
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
