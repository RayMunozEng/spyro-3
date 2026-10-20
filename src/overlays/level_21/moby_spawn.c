#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_21_8008549C:
* SCUS-94467 USA Rev0, 924 original words; original assembly SHA256
* 5e6a0dda0d819bee900f97d0b2c4bd6c48b95803179f613dc21c2ecd0194e100.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Level21 reuses existing credited common/effect C and original
* 56/357/733 blocks. Its original animation descriptor/ID/frame/flag sequence
* is expressed as a local inline C helper. This preserves the original
* post-call LBU/MOVE/BEQ operand order without any compiler assembly.
* Level25 reuses common and original303/364/383/671/672/673 C. Its repeated
* signed byte-angle wrap/blend is a local inline C helper: delta is masked
* by255, values129..255 subtract256, and the signed three-quarter delta
* is added to the original byte. Pitch/yaw base reads remain after each
* angle helper return. Raw branch/table units and full helper meanings
* remain unresolved. Whole unused views may be removed, used fields intact.
* No new assembly or explicit register binding is used by these functions.
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
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
}
Spawn14Tag84;
void func_8004ED6C(void*, Vector3D*, Vector3D*);
extern Moby* D_8006C704;
extern int D_8006C770;
extern int D_8006EE2C[];
void func_80055D24(Moby*, int);
int func_8004EDE8(Vector3D*, int);
typedef struct {
    Vector3D16 vector0;
    unsigned char pad6[2];
    unsigned char byte8;
    signed char byte9;
    unsigned char padA[2];
    int* bufferC;
    int word10;
    Moby* linked14;
}
Spawn21Tag357;
static __inline__ void Spawn21SetAnimation(Moby* moby, int animation) {
    if (moby->animationState.id!=animation) {
        unsigned char* descriptor = *(unsigned char**)(D_8006EE2C[moby->mobyClass]+animation*4+0x3C);
        unsigned int first;
        unsigned int flag;
        D_8006C770 = 0;
        first = *descriptor;
        moby->animationState.id = animation;
        moby->animationState.nextId = animation;
        moby->animationState.frame = 0;
        moby->animationState.nextFrame = 1;
        flag = first<2;
        flag^=1;
        flag = -flag;
        moby->animationProgress = flag&0x30;
    }
}
Moby* func_level_21_8008549C(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    int coefficient120;
    Vector3D v2;
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
    case 56:
        {
            Spawn14Tag84* tag = newMoby->mobyTag;
            int elevation, azimuth;
            int coefficient90;
            coefficient120 = 120;
            newMoby->lowDrawDistance = 32;
            newMoby->highDrawDistance = 32;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = func_8003636C(-1500, 1800);
            azimuth = (linkedMoby->angle.yaw+func_8003636C(-1500, 1500))&4095;
            coefficient90 = 90;
            Spawn21SetAnimation(newMoby, func_8003636C(0, 2));
            newMoby->colour.a = 45;
            newMoby->colour.r = 80;
            newMoby->colour.g = 80;
            newMoby->colour.b = 114;
            tag->unk0.x = ((func_8004EA2C(elevation)>>6)*(func_8004EA2C(azimuth)*coefficient120))>>18;
            tag->unk0.y = ((func_8004EA2C(elevation)>>6)*(func_8004E9E4(azimuth)*coefficient120))>>18;
            tag->unk0.z = (func_8004E9E4(elevation)*coefficient90)>>12;
            tag->unk0.x += (D_80065920[linkedMoby->angle.yaw]*15)>>9;
            tag->unk0.y += (D_800658A0[linkedMoby->angle.yaw]*15)>>9;
            newMoby->angle.roll = rand();
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->position.x += tag->unk0.x*2;
            newMoby->position.y += tag->unk0.y*2;
            newMoby->position.z += tag->unk0.z*2;
            tag->unk6.x = (rand()&31)-16;
            tag->unk6.y = (rand()&31)-16;
            tag->unk6.z = (rand()&31)-16;
            tag->unkC = func_8003636C(70, 110);
            tag->unkE = 1;
            tag->unk12 = 2;
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
                v2.x = (D_80065920[yaw] * 0x7D) >> 9;
                v2.y = (D_800658A0[yaw] * 0x7D) >> 9;
                v2.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &v2);
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
                v2.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                v2.x = (short)v2.x >> 4;
                v2.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                v2.y = (short)v2.y >> 4;
                v2.z = 0;
                mobyTag->linearVel.x += v2.x;
                mobyTag->linearVel.y += v2.y;
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
    case 357:
        {
            Vector3D* position = &newMoby->position;
            Vector3D* linkedPosition = &linkedMoby->position;
            Spawn21Tag357* tag = newMoby->mobyTag;
            Moby* arenaMoby;
            int* arena;
            int arenaBytes;
            int coefficient700;
            func_8004F178(position, linkedPosition);
            func_80055C24(newMoby);
            newMoby->updateDistance = 255;
            newMoby->lowDrawDistance = 127;
            newMoby->highDrawDistance = 63;
            newMoby->position.z += 800;
            tag->linked14 = linkedMoby;
            tag->byte8 = 0;
            func_80055D24(linkedMoby, 4);
            v2.x = 2500-linkedMoby->animationProgress*10;
            v2.y = 0;
            v2.z = linkedMoby->animationProgress*51+200;
            func_8004ED6C(&linkedMoby->rotationMatrix, &v2, &v2);
            func_8004F194(position, &v2, linkedPosition);
            coefficient700 = 700;
            tag->vector0.x = (D_80065920[linkedMoby->angle.yaw]*coefficient700)>>12;
            tag->vector0.y = (D_800658A0[linkedMoby->angle.yaw]*coefficient700)>>12;
            tag->vector0.z = 0;
            tag->vector0.z = linkedMoby->animationProgress*15-35;
            v.x = tag->vector0.x;
            v.y = tag->vector0.y;
            v.z = tag->vector0.z;
            newMoby->angle.pitch = func_8004E880(func_8004EDE8(&v, 0), v.z, 0);
            newMoby->angle.yaw = func_8004E880(v.x, v.y, 0);
            arenaBytes = 0x470;
            tag->byte9 = 5;
            if (rand()&1) tag->byte9 = -tag->byte9;
            for (arenaMoby = mobyArrayPtr;arenaMoby<D_8006C704;arenaMoby++) {
                if (arenaMoby->mobyClass==1020) break;
            }
            if (arenaMoby) {
                arena = arenaMoby->mobyTag;
                arena[0] += arenaBytes;
                if (arena[0]+arenaBytes >= arena[2]) arena[0] = 0;
                tag->bufferC = (int*)((char*)arena+(arena[0]+0x14));
                *tag->bufferC = 0;
            }
            break;
        }
    case 733:
        {
            int* tag = newMoby->mobyTag;
            int pitch;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.yaw = func_8003636C(0, 255);
            func_80055C24(newMoby);
            *tag = func_8003636C(120, 180);
            pitch = (short)D_800658A0[((*tag*8)&0x1F8)>>1]>>7;
            newMoby->angle.pitch = pitch;
            if (newMoby->mobyClass!=730) newMoby->angle.pitch = pitch+64;
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
