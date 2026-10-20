#include "common.h"

/**
 * MobySpawn_level_14() - func_level_14_8008CB2C() - MATCHING
 * Most recent MobySpawn as of 2025-08-21
 * Need to figure out if v2 should be included / use defines, if I put it in it messes up some of the stack usage
 * Note that level 13 will be added first, so when this is added I should check any tags / content for accuracy
 * https://decomp.me/scratch/gpXPY
 */
/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: upstream-linked https://decomp.me/scratch/gpXPY,
* Hwd405; exported C SHA256
* 9f1401cce0721f7354d3deb50cf490894ab06a9f24008217c99242a36d5676ee.
* AI-generated repository type adapters, local names, cleanup and provenance;
* not human reviewed. SCUS-94467 USA Rev0 8008CB2C:926 instruction words;
* original source SHA256
* f2e552407b215d123d89e753b493dce8556d594da466aff3f09cb65ebe057360.
* Scratch target words equal the original. Acceptance requires all native
* and linked words/targets plus full EXE and every-overlay retail hashes.
* Callback743B0 is an extern caller-register projection of the original
* header slot, not a new variable or a complete helper-contract assertion.
* The 1020 tag block begins at byte14 and is cleared for9C0 original bytes.
* Tags expose observed byte offsets; no semantic layout guesses are added.
* Original signed/unsigned widths, shifts, masks, division and update order
* are retained. Physical units/full fixed-point domains, complete helper,
* asset/SFX chains, frame cadence and synchronized runtime verification
* remain unresolved. Invocation cadence only. Binary identity establishes
* no engine/browser parity or subsystem completion. Not human reviewed.
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
void func_8004E7AC(int *dest,int set,int len);
void func_80055D10(Moby*);
extern void (*Spawn14Callback743B0)(Moby*, int, int, int) __asm__("unk_ovlheader_800743B0");
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
}
Spawn14Tag84;
typedef struct {
    int unk0;
}
Spawn14Tag100;
typedef struct {
    short unk0;
    short unk2;
    int unk4;
    int unk8;
    char unkC;
    char unkD;
    char unkE;
    char unkF;
    int unk10;
    int unk14;
}
Spawn14Tag421;
typedef struct {
    int unk0;
    int unk4;
}
Spawn14Tag534;
typedef struct {
    short unk0;
    short unk2;
    void* unk4;
    int unk8;
    int unkC;
    Moby* unk10;
}
Spawn14Tag1015;
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
}
Spawn14Tag299;
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    char unk14[0x9C0];
}
Spawn14Tag1020;
Moby* func_level_14_8008CB2C(int mobyClass, Moby* linkedMoby) {
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
    case 84:
        {
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
    case 16:
    case 211:
        {
            MobyTag_16* mobyTag;
            int extraLifeThreshold;
            mobyTag = newMoby->mobyTag;
            if (newMoby->mobyClass == 0x10) {
                extraLifeThreshold = 10;
                if (D_8006C784 < 4)      extraLifeThreshold = 7;
                else if (D_8006C784 < 7) extraLifeThreshold = 9;
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
            mobyTag->unk12 = (char) (rand() & 0xFC);
            break;
        }
    case 100:
        {
            Spawn14Tag100* mobyTag;
            mobyTag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            mobyTag->unk0 = 0x14;
            newMoby->colour.a = 0x3B;
            newMoby->colour.r = 0xFF;
            newMoby->colour.g = 0xFF;
            newMoby->colour.b = 0x40;
            newMoby->size = 0x60;
            newMoby->unknown4 = 0xFE;
            newMoby->angle.pitch = func_8004E880(func_8004F334(&newMoby->position, &camera.nextCameraPosCartesian), camera.nextCameraPosCartesian.z - newMoby->position.z, 0) - 0x40;
            newMoby->angle.yaw = func_8004E880(camera.nextCameraPosCartesian.x - newMoby->position.x, camera.nextCameraPosCartesian.y - newMoby->position.y, 0);
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
    case 568:
    case 306:
    case 307:
    case 308:
    case 310:
        {
            MobyTag_Fragment* mobyTag;
            int azimuth;
            int elevation;
            mobyTag = newMoby->mobyTag;
            newMoby->lowDrawDistance = 0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            azimuth = rand() & 0xFFF;
            elevation = rand() & 0x7FF;
            mobyTag->linearVel.x = (func_8004EA2C(elevation) * func_8004EA2C(azimuth) * linkedMoby->substate) >> 0x18;
            mobyTag->linearVel.y = (func_8004EA2C(elevation) * func_8004E9E4(azimuth) * linkedMoby->substate) >> 0x18;
            mobyTag->linearVel.z = (func_8004E9E4(elevation) * linkedMoby->substate) >> 0xC;
            if (linkedMoby->damageFlags & 0x02000000) {
                v.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                v.x = (short)v.x >> 4;
                v.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                v.y = (short)v.y >> 4;
                v.z = 0;
                mobyTag->linearVel.x += v.x;
                mobyTag->linearVel.y += v.y;
            }
            else if ((linkedMoby->damageFlags & 0x20000) && ((spyro.movementState == 4) || (spyro.movementState == 0xC))) {
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
    case 470:
    case 471:
    case 472:
    case 473:
        {
            Spawn14Tag421* mobyTag;
            Spawn14Tag421* linkedMobyTag;
            mobyTag = newMoby->mobyTag;
            linkedMobyTag = linkedMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->state = linkedMoby->state;
            newMoby->unknown4 = 0;
            newMoby->lowDrawDistance = 0x20;
            newMoby->updateDistance = 0x20;
            mobyTag->unk0 = linkedMobyTag->unk0;
            mobyTag->unk2 = linkedMobyTag->unk2;
            mobyTag->unk4 = linkedMobyTag->unk4;
            mobyTag->unkE = linkedMobyTag->unkE;
            mobyTag->unk14 = linkedMobyTag->unk14;
            Spawn14Callback743B0(newMoby, 0, 0, newMoby - mobyArrayPtr);
            break;
        }
    case 534:
        {
            Spawn14Tag534* mobyTag;
            mobyTag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            newMoby->size = 0x40;
            mobyTag->unk0 = 0xC8;
            mobyTag->unk4 = 0x23;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055D24(linkedMoby, 4);
            v.x = 0x708;
            v.y = 0;
            v.z = 0x12C;
            func_8004ED6C(&linkedMoby->rotationMatrix, &v, &v);
            func_8004F194(&newMoby->position, &linkedMoby->position, &v);
            break;
        }
    case 1015:
        {
            Spawn14Tag1015* mobyTag;
            int moby1020link;
            Moby* moby1020;
            void* moby1020block;
            mobyTag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->state = linkedMoby->substate;
            newMoby->updateDistance = 0xFF;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->position.z += 0x100;
            moby1020link = ((Spawn14Tag299*)linkedMoby->mobyTag)->unkC;
            if (moby1020link >= 0) {
                moby1020 = &mobyArrayPtr[moby1020link];
                moby1020block = &((Spawn14Tag1020*)moby1020->mobyTag)->unk14;
                mobyTag->unk4 = moby1020block;
                func_8004E7AC(moby1020block, 0, sizeof(((Spawn14Tag1020*)moby1020->mobyTag)->unk14));
                mobyTag->unk0 = 200;
                mobyTag->unk2 = 200;
                mobyTag->unk10 = moby1020;
            }
            break;
        }
    default:
        {
            if (linkedMoby) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            else {
                func_8004F178(&newMoby->position, &spyro.position);
            }
            func_80055C24(newMoby);
            break;
        }
    }
    return newMoby;
}
