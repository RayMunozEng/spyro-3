#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_32_8008E988:
* SCUS-94467 USA Rev0, 1364 original words; original assembly SHA256
* 7c02d1b26e6cf736b1e43bbc9f680ed7feefd372ba31d34c163592807c19c100.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Existing20 common/fragments,35 class92/364/715-as215 and37
* class327 are reused. The original215 block physically precedes16/211.
* Original fragment selectors310/568/306/308 only. Observed frameB0/save90
* retains every SP10/20/30/40/58/60/70/88 local view and raw gap. Matrices are
*20 bytes; gaps54/84 and the disjoint58 angle/vector union remain intact.
* New142 preserves original150/180 multiply producers. New194 reads byte40
* (animationProgress), not drawn byte4D; original duplicate z0 store is
* retained with a volatile view. The second product and following byte40
* snapshot preserve original write ordering. The eight-call particle loop
* counts after the call in C, reproducing the original header increment.
* New730 retains original table index and signed SLL16/SRA23 pitch producer.
* The initialized class327 tag s4 binding restores the original saved-register
* allocation; no instruction assembly or new empty constraints are needed.
* Only whole unused donor views/locals are removed; all used fields and frame
* padding remain. No complete helper/layout/units/cadence contract inferred.
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
void func_8004E7AC(int *dest, int set, int len);
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
}
Spawn14Tag84;
#include "ovl_header.h"
void func_8004F0E8(Vector3D*, int);
typedef struct {
    Vector3D vector0;
    short wordC, wordE, timer10;
    unsigned char byte12, byte13;
    Moby* parent14;
}
Spawn32Tag194;
typedef struct {
    Vector3D unk0;
    int unkC;
    int unk10;
}
Spawn32Tag92;
Moby* func_level_32_8008E988(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    struct {
        Vector3D vector10;
        int gap1C;
        Vector3D vector20;
        int gap2C;
        Vector3D vector30;
        int gap3C;
        SHORTMATRIX matrix40;
        int gap54;
        union {
            struct {
                Angle angle58;
                unsigned char gap5B[5];
                Vector3D vector60;
            }
            parts;
            Vector3D vector58;
        }
        work58;
        int gap6C;
        SHORTMATRIX matrix70;
        int gap84;
        Angle angle88;
        unsigned char gap8B[8-sizeof(Angle)];
    }
    frame;
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
    case 215:
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
            mobyTag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 0xC;
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
                newMoby->angle.roll = rand();
                newMoby->angle.pitch = rand();
                newMoby->angle.yaw = rand();
                newMoby->position.x += mobyTag->unk0.x * 2;
                newMoby->position.y += mobyTag->unk0.y * 2;
                newMoby->position.z += mobyTag->unk0.z * 2;
            }
            else {
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
    case 92:
        {
            Spawn32Tag92* tag = newMoby->mobyTag;
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
                frame.vector10.x = (D_80065920[yaw] * 0x7D) >> 9;
                frame.vector10.y = (D_800658A0[yaw] * 0x7D) >> 9;
                frame.vector10.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &frame.vector10);
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
    case 142:
        {
            Spawn14Tag84* tag = newMoby->mobyTag;
            int elevation, azimuth;
            int radius, radius2;
            newMoby->lowDrawDistance = 32;
            newMoby->highDrawDistance = 32;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = rand()&4095;
            azimuth = (linkedMoby->unkb+func_8003636C(-1500, 1500))&4095;
            radius = 150;
            tag->unk0.x = ((func_8004EA2C(elevation)>>6)*(func_8004EA2C(azimuth)*radius))>>18;
            tag->unk0.y = ((func_8004EA2C(elevation)>>6)*(func_8004E9E4(azimuth)*radius))>>18;
            radius2 = 180;
            tag->unk0.z = (func_8004E9E4(elevation)*radius2)>>12;
            tag->unk0.x += (D_80065920[linkedMoby->unkb]*35)>>10;
            tag->unk0.y += (D_800658A0[linkedMoby->unkb]*35)>>10;
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            tag->unk6.x = (rand()&31)-16;
            tag->unk6.y = (rand()&31)-16;
            tag->unk6.z = (rand()&31)-16;
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
    case 194:
        {
            Spawn32Tag194* tag = newMoby->mobyTag;
            int radius;
            int yProduct, vertical;
            int count = 0;
            tag->parent14 = linkedMoby;
            newMoby->updateDistance = 255;
            newMoby->lowDrawDistance = 64;
            newMoby->unknown = -1;
            frame.vector10.x = 1800;
            frame.vector10.y = 0;
            frame.vector10.z = (linkedMoby->animationProgress<<5)+512;
            func_8004ED6C(&linkedMoby->rotationMatrix, &frame.vector10, &frame.vector10);
            func_8004F194(&newMoby->position, &frame.vector10, &linkedMoby->position);
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            tag->wordE = 5;
            tag->wordC = -7;
            radius = linkedMoby->animationProgress*16+240;
            tag->vector0.x = (D_80065920[newMoby->angle.yaw]*radius)>>12;
            yProduct = D_800658A0[newMoby->angle.yaw]*radius;
            ((volatile Spawn32Tag194*)tag)->vector0.z = 0;
            tag->byte12 = 1;
            tag->vector0.y = yProduct>>12;
            vertical = linkedMoby->animationProgress;
            tag->byte13 = 0;
            tag->vector0.z = vertical*15+120;
            frame.work58.parts.angle58.roll = rand();
            frame.work58.parts.angle58.pitch = newMoby->angle.pitch;
            frame.work58.parts.angle58.yaw = newMoby->angle.yaw;
            do {
                frame.work58.parts.angle58.roll += 32;
                func_8004EA90(&frame.work58.parts.angle58, &frame.matrix40, 0);
                frame.vector20.x = 30;
                frame.vector20.y = (rand()&15)+32;
                frame.vector20.z = 0;
                func_8004ED6C(&frame.matrix40, &frame.vector20, &frame.vector20);
                func_8004F178(&frame.vector30, &frame.vector20);
                func_8004F0E8(&frame.vector30, 2);
                func_8004F194(&frame.vector30, &frame.vector30, &newMoby->position);
                SpawnParticle(1, 13, &frame.vector30, &frame.vector20);
                count++;
            }
            while(count<8);
            func_80055C24(newMoby);
            tag->timer10 = 180;
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
    case 310:
    case 568:
    case 306:
    case 308:
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
                frame.work58.parts.vector60.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                frame.work58.parts.vector60.x = (short)frame.work58.parts.vector60.x >> 4;
                frame.work58.parts.vector60.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                frame.work58.parts.vector60.y = (short)frame.work58.parts.vector60.y >> 4;
                frame.work58.parts.vector60.z = 0;
                mobyTag->linearVel.x += frame.work58.parts.vector60.x;
                mobyTag->linearVel.y += frame.work58.parts.vector60.y;
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
    case 327:
        {
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
            mobyTag->unk0.x = ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y = ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2 = 0x96;
            mobyTag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0xF) >> 9;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0xF) >> 9;
                mobyTag->unk0.z += func_8003636C(70, 100);
            }
            frame.work58.vector58.x = 0;
            frame.work58.vector58.y = 0;
            frame.work58.vector58.z = 256;
            frame.angle88.roll = linkedMoby->angle.roll;
            frame.angle88.pitch = linkedMoby->angle.pitch;
            frame.angle88.yaw = linkedMoby->angle.yaw;
            func_8004EA90(&frame.angle88, &frame.matrix70, 0);
            func_8004ED6C(&frame.matrix70, &frame.work58.vector58, &frame.work58.vector58);
            func_8004F194(&newMoby->position, &newMoby->position, &frame.work58.vector58);
            frame.work58.vector58.x = mobyTag->unk0.x;
            frame.work58.vector58.y = mobyTag->unk0.y;
            frame.work58.vector58.z = mobyTag->unk0.z;
            func_8004ED6C(&frame.matrix70, &frame.work58.vector58, &frame.work58.vector58);
            mobyTag->unk0.x = frame.work58.vector58.x;
            mobyTag->unk0.y = frame.work58.vector58.y;
            mobyTag->unk0.z = frame.work58.vector58.z;
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x37) >> 0xA;
            }
            else {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
            }
            newMoby->angle.roll = rand();
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->position.x += mobyTag->unk0.x*2;
            newMoby->position.y += mobyTag->unk0.y*2;
            newMoby->position.z += mobyTag->unk0.z*2;
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
    case 730:
        {
            int* tag = newMoby->mobyTag;
            int timer, pitch;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.yaw = func_8003636C(0, 255);
            func_80055C24(newMoby);
            timer = func_8003636C(120, 180);
            tag[0] = timer;
            pitch = (int)((unsigned int)(unsigned short)D_800658A0[(timer*4)&252]<<16)>>23;
            newMoby->angle.pitch = pitch;
            if(newMoby->mobyClass!=mobyClass)newMoby->angle.pitch = pitch+64;
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
