#include "common.h"

/**
 * MobySpawn_Level12() - func_level_12_800842D0() - MATCHING
 * This should probably serve as the basis for how I do moby spawn going forwards
 * Preferably should be implemented as a totally separate file and included into the relevant one
 * https://decomp.me/scratch/oR4Tl
 */
/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: upstream-linked https://decomp.me/scratch/oR4Tl,
* Hwd405; exported C SHA256
* 99e4b6dea881ef2a25b53a014b879733473e0def3e906829123738c9e97000e8.
* AI-generated repository type adapters, cleanup and provenance; unreviewed.
* SCUS-94467 USA Rev0 800842D0: 519 instruction words; original source
* SHA256 c3e18fe22719531e425941e284276c3c1e72f8b42a3fb7040a466e6382cc2e04.
* Scratch target words equal the original. Acceptance requires native and
* linked words/targets plus full EXE and every-overlay retail hashes.
* Existing tag704 exposes original bytes14/16/17. All tag layouts and
* arithmetic preserve original byte/halfword/word widths, masks, shifts
* and signed divisions. Physical units/full fixed-point domains, complete
* helper/asset/SFX chains, frame cadence and synchronized runtime validation
* remain unresolved. Invocation cadence only; binary identity establishes
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
int func_8004E9E4(int);
int func_8004EA2C(int);
extern Moby* mobyArrayPtr;
extern Sparx sparx;
extern Spyro spyro;
Moby* func_level_12_800842D0(int mobyClass, Moby* linkedMoby) {
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
        case 306:
        case 307:
        case 568: {
            int azimuth;
            int elevation;
            MobyTag_Fragment* mobyTag;
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
                v.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x,
                                               newMoby->position.y - spyro.position.y, 0)];
                v.x = (short)v.x >> 4;
                v.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x,
                                               newMoby->position.y - spyro.position.y, 0)];
                v.y = (short)v.y >> 4;
                v.z = 0;
                mobyTag->linearVel.x += v.x;
                mobyTag->linearVel.y += v.y;
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
        case 704: {
            MobyTag_704* mobyTag;
            mobyTag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &spyro.position);
            mobyTag->unk17 = 0x18;
            mobyTag->unk16 = 0x18;
            mobyTag->unk14 = -6;
            newMoby->colour.a = 0x30;
            newMoby->colour.r = 0;
            newMoby->colour.g = 0;
            newMoby->colour.b = 0;
            newMoby->size = 0x64;
            newMoby->unknown4 = 0;
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->lowDrawDistance = 0x30;
            newMoby->highDrawDistance = 0x3F;
            func_80055C24(newMoby);
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
