#include "matching.h"
#include "common.h"

/**
 * MobySpawn_level_15() - func_level_15_8007E9F8()
 * Lots of work to do
 * https://decomp.me/scratch/EHKov
 */
/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baselines: accepted upstream-linked PGLtI/oR4Tl common spawn C,
* original moby_spawn.h class326 and class76 pattern; gpXPY class84 supplies
* class715. Attribution remains with those original contributors. Per-level
* adapters/additions, cleanup and provenance are AI generated and have not
* been human reviewed. func_level_15_8007E9F8, SCUS-94467 USA Rev0:
* 721 original words; assembly SHA256
* 16110cf60f1440715a0d9950787d6d3948b7f3f3b08aa1fa288979f66c1309ef.
* Selectors/shared entries and physical body order are original. Level35
* class322 guards76/322/348 and helper-only645/128 follow original branches.
* Level15 preserves descriptor bytes10/13, three child slotsC/10/14, original
* child-tag and literal20 producers, and separate table yaw/pitch byte reads.
* Byte arithmetic and table stride2 are original domains. Empty boundaries
* preserve original memory order and consume initialized actual producers;
* no CPU asm or incoming register/HI/LO assumption is introduced. Views name
* observed offsets only. Complete helper/descriptor/asset/SFX meanings,
* physical units/full fixed-point domains, frame cadence and synchronized
* runtime verification remain unresolved. Cadence is per invocation only.
* Confidence requires every native/linked word/target and full EXE plus
* every-overlay retail hashes. No engine/browser or subsystem-complete claim.
* AI additions are not human reviewed.
*/
#include "ovl_header.h"
int func_8001A358(Vector3D*, int);
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
int func_8004E9E4(int);
int func_8004EA2C(int);
extern Moby* mobyArrayPtr;
extern Sparx sparx;
extern Spyro spyro;
#include "camera.h"
extern void* func_80050844(Vector3D*, int, int, int);
int func_8004F334(Vector3D*, Vector3D*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
void func_80034F80(Moby*, int);
void func_80055D10(Moby*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
typedef struct {
    Vector3D16 unk0, unk6;
    short unkC, unkE, unk10, unk12;
} Spawn45Tag715;
typedef struct {
    short unk0, index2;
    int unk4, unk8;
    PathNode* nodesC;
} Spawn45PathView;
void* func_8002EC50(int, int, int);
void func_80055F14(Moby*, int, Vector3D*);
typedef struct {
    int unk0, unk4;
} Spawn15Tag224;
typedef struct {
    unsigned char* table0;
    int unk4;
    int index8;
} Spawn15LinkedTag611;
Moby* func_level_15_8007E9F8(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D v;
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
            Spawn45Tag715* mobyTag;
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
                v.x = (D_80065920[yaw] * 0x7D) >> 9;
                v.y = (D_800658A0[yaw] * 0x7D) >> 9;
                v.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &v);
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
        case 224: {
            Spawn15Tag224* tag = newMoby->mobyTag;
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
        case 383: {
            Moby** tag = newMoby->mobyTag;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            *tag = linkedMoby;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            newMoby->highDrawDistance = linkedMoby->highDrawDistance;
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
            unsigned char* tag = newMoby->mobyTag;
            if (linkedMoby != 0) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            } else {
                func_8004F178(&newMoby->position, &spyro.position);
            }
            func_80055C24(newMoby);
            if (linkedMoby != 0) {
                unsigned char* descriptor;
                unsigned char* slotBase;
                int index;
                newMoby->updateDistance = 255;
                newMoby->lowDrawDistance = 63;
                newMoby->state = 10;
                newMoby->size = 254;
                *(int*)&newMoby->colour = 0x3FFFFFFF;
                descriptor = func_8002EC50(1, 16, 0x20FFFF);
                index = 0;
                slotBase = tag;
                *(void**)(slotBase + 8) = descriptor;
                descriptor[16] = 4;
                (*(unsigned char**)(slotBase + 8))[19] = 8;
                do {
                    Moby* child = SpawnMoby(604, 0);
                    if (child != 0) {
                        register short* childTag __asm__("$3");
                        register int stateWord __asm__("$2");
                        func_8004F178(&child->position, &newMoby->position);
                        childTag = child->mobyTag;
                        MATCHING_BARRIER_VOLATILE("memory");
                        stateWord = 20;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(stateWord, childTag, "memory");
                        child->state = stateWord;
                        child->updateDistance = 255;
                        child->substate = index + 1;
                        child->unknown3[0] = 0;
                        child->lowDrawDistance = 0;
                        child->drawn = 0;
                        child->unknownCollision = 0;
                        *childTag = 10;
                        *(Moby**)(slotBase + 12) = child;
                    }
                    index += 1;
                    slotBase += 4;
                } while (index < 3);
            }
            break;
        }
        case 611: {
            Moby** newTag = newMoby->mobyTag;
            Spawn15LinkedTag611* linkedTag = linkedMoby->mobyTag;
            register Moby* callActor __asm__("$4");
            register unsigned char* address __asm__("$3");
            register int yawWord __asm__("$2");
            int pitchWord;
            *newTag = linkedMoby;
            func_80055F14(linkedMoby, 0, &newMoby->position);
            address = linkedTag->table0 + linkedTag->index8 * 2;
            yawWord = *address;
            MATCHING_BARRIER_VOLATILE("memory");
            callActor = newMoby;
            MATCHING_KEEP2(callActor, yawWord);
            newMoby->angle.yaw = yawWord;
            MATCHING_BARRIER_VOLATILE("memory");
            pitchWord = linkedTag->table0[linkedTag->index8 * 2 + 1];
            newMoby->state = 1;
            newMoby->lowDrawDistance = 32;
            newMoby->highDrawDistance = 32;
            newMoby->angle.pitch = pitchWord;
            func_80055C24(callActor);
            func_80034F80(newMoby, 1);
            break;
        }
        default: {
            Vector3D* mobyPos;
            Vector3D* newPos;
            if (linkedMoby != 0) {
                mobyPos = &newMoby->position;
                newPos = &linkedMoby->position;
            } else {
                mobyPos = &newMoby->position;
                newPos = &spyro.position;
            }
            func_8004F178(mobyPos, newPos);
            func_80055C24(newMoby);
            break;
        }
    }
    return newMoby;
}
