#include "common.h"

// this one scares me

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baselines: accepted upstream-linked PGLtI common spawn C;
* original include/moby/moby_spawn.h cases245/326; accepted gpXPY class84
* supplies level45's class715. Original-specific adapters and additions,
* cleanup and this provenance are AI generated and not human reviewed.
* func_level_45_8007EBE8, SCUS-94467 USA Rev0: 678 original words;
* original assembly SHA256 48b122b86a792dbc127cb046a0601729c207a165ca1bf930f5ceb0ddd0aa2cf8.
* This level's selectors, shared entries and physical case order follow
* original instructions. Level11 retains the masked random-word producer
* before its addition to the linked yaw byte, coefficient3, original timers
* and full-word color stores. Level45 PathView exposes signed half2,
* wordC node pointer and original16-byte record stride only. No broader
* layout or helper-contract meaning is asserted. Arithmetic retains
* original byte/halfword/word widths, masks, signed shifts and divisions.
* Physical units/full fixed-point domains, complete helper/asset/SFX chains,
* frame cadence and synchronized runtime verification remain unresolved.
* Per-invocation cadence only. Confidence requires every native/linked word
* and target plus full EXE and every-overlay retail hashes. No engine/browser
* parity or subsystem-complete claim. Not human reviewed.
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
int func_8004E9E4(int);
int func_8004EA2C(int);
extern Moby* mobyArrayPtr;
extern Sparx sparx;
extern Spyro spyro;
#include "camera.h"
extern void* func_80050844(Vector3D*, int, int, int);
int func_8004F334(Vector3D*, Vector3D*);
void func_8004ED6C(SHORTMATRIX*,Vector3D*,Vector3D*);
void func_80034F80(Moby*,int);
void func_80055D10(Moby*);
void func_8004F1C8(Vector3D*,Vector3D*,Vector3D*);
typedef struct {
    Vector3D unk0;
    int unkC;
    int unk10;
}
Spawn45Tag92;
typedef struct {
    Vector3D16 unk0,unk6;
    short unkC,unkE,unk10,unk12;
}
Spawn45Tag715;
typedef struct {
    short unk0, index2;
    int unk4,unk8;
    PathNode* nodesC;
}
Spawn45PathView;
typedef struct {
    int unk0;
    Spawn45PathView* path4;
}
Spawn45LinkedTag954;
Moby* func_level_45_8007EBE8(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D v;
    newMoby = func_80055A7C();
    if (newMoby == 0) return 0;
    newMobyTag = newMoby->mobyTag;
    func_8004E790(newMoby, 0, 0x58);
    newMoby->mobyTag = newMobyTag;
    func_8004E790(newMobyTag, 0, 0x18);
    newMoby->mobyClass = mobyClass;
    if (linkedMoby != 0) {
        if (linkedMoby - mobyArrayPtr < 0x100U) {
            newMoby->linkedMoby = linkedMoby - mobyArrayPtr;
        }
        else {
            newMoby->linkedMoby = 0xFF;
        }
    }
    else {
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
    case 715:
        {
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
            mobyTag->unk0.x = ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y = ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2 = 0x96;
            mobyTag->unk0.z =  (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.z += func_8003636C(0x28, 0x46);
            }
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x37) >> 0xA;
            }
            else {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x23) >> 0xA;
            }
            if ((newMoby->mobyClass != 10) && (newMoby->mobyClass != 29)) {
                newMoby->angle.roll  = rand();
                newMoby->angle.pitch = rand();
                newMoby->angle.yaw   = rand();
                newMoby->position.x += mobyTag->unk0.x * 2;
                newMoby->position.y += mobyTag->unk0.y * 2;
                newMoby->position.z += mobyTag->unk0.z * 2;
            }
            else {
                newMoby->angle.roll  = linkedMoby->angle.roll;
                newMoby->angle.pitch = linkedMoby->angle.pitch;
                newMoby->angle.yaw   = linkedMoby->angle.yaw;
            }
            mobyTag->unk6.x = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z = (rand() & 0x1F) - 0x10;
            mobyTag->unkC = func_8003636C(0x78, 0x96);
            mobyTag->unkE = 1;
            mobyTag->unk12 = 0;
            break;
        }
    case 92:
        {
            Spawn45Tag92* tag = newMoby->mobyTag;
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
    case 120:
        {
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
            }
            else {
                yaw = spyro.bodyRotation.yaw - 0x80;
                v.x = (D_80065920[yaw] * 0x7D) >> 9;
                v.y = (D_800658A0[yaw] * 0x7D) >> 9;
                v.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &v);
            }
            mobyTag->unk2 = 0xFF;
            break;
        }
    case 132:
        {
            int ground;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            ground = func_80035D38(newMoby);
            if (ground) newMoby->position.z = ground;
            newMoby->state = 6;
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
        }
        else {
            newMoby->unknown = -1;
        }
        break;
    case 272:
        {
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
    case 326:
        {
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
            }
            else {
                if (linkedMoby->mobyClass == 0x270) {
                    mobyTag->unk2 = 2;
                    newMoby->colour.r = 0xE0;
                    newMoby->colour.g = 0xE0;
                    newMoby->colour.b = 0xE0;
                    newMoby->colour.a = 0x3B;
                    mobyTag->unk3 = 0;
                    newMoby->size = 0x60;
                }
                else {
                    mobyTag->unk2 = 0;
                    mobyTag->unk3 = 0;
                    newMoby->size = 0x60;
                }
            }
            newMoby->unknown4 = 0xFE;
            newMoby->angle.pitch = func_8004E880(func_8004F334(&newMoby->position, &camera.nextCameraPosCartesian), camera.nextCameraPosCartesian.z - newMoby->position.z, 0) - 0x40;
            newMoby->angle.yaw = func_8004E880(camera.nextCameraPosCartesian.x - newMoby->position.x, camera.nextCameraPosCartesian.y - newMoby->position.y, 0);
            break;
        }
    case 364:
        func_8004F178(&newMoby->position, &linkedMoby->position);
        newMoby->angle.roll = linkedMoby->angle.roll;
        newMoby->angle.pitch = linkedMoby->angle.pitch;
        newMoby->angle.yaw = linkedMoby->angle.yaw;
        func_80055C24(newMoby);
        func_80034F80(newMoby,1);
        newMoby->state = 4;
        break;
    case 383:
        {
            Moby** tag = newMoby->mobyTag;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            *tag = linkedMoby;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            newMoby->highDrawDistance = linkedMoby->highDrawDistance;
            break;
        }
    case 482:
        {
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
    case 541:
        {
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
    case 954:
        {
            int* tag = newMoby->mobyTag;
            Spawn45LinkedTag954* linkedTag = linkedMoby->mobyTag;
            Spawn45PathView* path;
            Vector3D* position = &newMoby->position;
            int index;
            func_8004F178(position, &linkedMoby->position);
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            *tag = 0;
            path = linkedTag->path4;
            func_8004F178(position, &path->nodesC[path->index2-1].pos);
            path = linkedTag->path4;
            index = path->index2;
            func_8004F1C8(&v, &path->nodesC[index].pos, &path->nodesC[index-1].pos);
            newMoby->angle.roll = 0;
            newMoby->angle.pitch = 0;
            newMoby->angle.yaw = func_8004E880(v.x,v.y,0);
            break;
        }
    default:
        {
            Vector3D* mobyPos;
            Vector3D* newPos;
            if (linkedMoby != 0) {
                mobyPos = &newMoby->position;
                newPos = &linkedMoby->position;
            }
            else {
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


INCLUDE_RODATA("asm/nonmatchings/overlays/level_45/moby", D_level_45_80074644);