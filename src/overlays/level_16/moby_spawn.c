#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baselines: credited upstream-linked PGLtI/oR4Tl/gpXPY common
* spawn C and the accepted original-specific spawn implementations. This
* level's selectors, adapters/additions, cleanup and provenance are AI
* generated and have not been human reviewed. func_level_16_8007EBDC:
* SCUS-94467 USA Rev0, 820 original words; original assembly SHA256
* a4a9fbfba604955da619c4921989e3710bd127c159bbaa37cd599744b248a104.
* Original byte/halfword/word widths, shifts, masks and signed arithmetic
* are retained. Level16 class8/class162 use original scalar coefficients
* and input selectors. Level31 keeps class120 on SP10, class244 SP10/SP20,
* and fragment work on SP30;71A04 is the original LBU-only caller view.
* Level41 retains the actual original default path omitted by raw m2c.
* Views describe observed offsets only. Complete helper/producer/asset/SFX
* meanings, physical units/full fixed-point domains, frame cadence and
* synchronized runtime validation remain open. Cadence per invocation only.
* Confidence requires every native/linked word/target and full EXE plus
* every-overlay retail hashes. No engine/browser or subsystem-complete claim.
* AI additions are not human reviewed.
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
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
}
Spawn14Tag84;
Moby* func_level_16_8007EBDC(int mobyClass, Moby* linkedMoby) {
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
    case 8:
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
    case 162:
        {
            Spawn14Tag84* tag = newMoby->mobyTag;
            int elevation;
            int azimuth;
            int coefficient150;
            newMoby->lowDrawDistance = 32;
            newMoby->highDrawDistance = 32;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation = rand() & 4095;
            azimuth = (linkedMoby->unkb + func_8003636C(-1500, 1500)) & 4095;
            coefficient150 = 150;
            tag->unk0.x = ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * coefficient150)) >> 18;
            tag->unk0.y = ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * coefficient150)) >> 18;
            {
                int coefficient180 = 180;
                tag->unk0.z = (func_8004E9E4(elevation) * coefficient180) >> 12;
            }
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
            tag->unk12 = 0;
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
