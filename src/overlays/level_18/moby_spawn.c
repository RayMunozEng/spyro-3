#include "matching.h"
#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Common source baselines: Hwd405's upstream-linked level12/oR4Tl
* (https://decomp.me/scratch/oR4Tl) and original include/moby/moby_spawn.h
* class326; scalar coefficient lifetime follows the linked level14/gpXPY
* source pattern. Original per-level cases, adapters and provenance are
* AI generated and have not been human reviewed. SCUS-94467 USA Rev0:
* func_level_18_8008309C, 652 original words, assembly SHA256
* 1e2bbad1a7b2e7a5d6033681eb410627af77c680ffdc387ddef11040520bea2d.
* Tag fields expose only original byte/halfword/word offsets. Signed table
* loads, shifts, divisions, masks, coefficient200 and store order retain
* the original producer/consumer sequence. Saved tag pointers are captured
* before the original helpers, including both level38 class593/700 paths.
* Empty constraints observe initialized original caller4 and yaw3 producers;
* no incoming register or HI/LO value is assumed and no CPU asm is emitted.
* Full helper contracts, physical units/full fixed-point domains, asset/SFX
* mappings, frame cadence and synchronized runtime validation remain open.
* Invocation cadence only. Confidence requires every native/linked word,
* branch/internal target, full EXE and every-overlay retail hash. No
* engine/browser parity or subsystem-complete claim. Not human reviewed.
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
typedef struct {
    short unk0;
    unsigned short unk2;
    int unk4;
    int unk8;
} SparxSpawnTag151;
typedef struct {
    int unk0;
    int unk4;
    void* unk8;
} SparxSpawnTag187;
typedef struct {
    Vector3D unk0;
    int unkC;
} SparxSpawnVectorTag;
Moby* func_level_18_8008309C(int mobyClass, Moby* linkedMoby) {
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
        case 151: {
            SparxSpawnTag151* tag = newMoby->mobyTag;
            Vector3D* position = &newMoby->position;
            if (linkedMoby->mobyClass == mobyClass) {
                SparxSpawnTag151* linkedTag = linkedMoby->mobyTag;
                func_8004F178(position, &linkedMoby->position);
                tag->unk2 = linkedTag->unk2 - 1;
                newMoby->state = 1;
            } else {
                newMoby->position.x = (D_80065920[spyro.bodyRotation.yaw] * 225) >> 11;
                newMoby->position.y = (D_800658A0[spyro.bodyRotation.yaw] * 225) >> 11;
                newMoby->position.z = 0;
                func_8004F194(position, position, &spyro.position);
                tag->unk2 = 2;
                newMoby->state = 0;
            }
            {
                register Moby* callActor __asm__("$4") = newMoby;
                register int yawWord __asm__("$3");
                MATCHING_KEEP(callActor);
                tag->unk8 = -1;
                yawWord = spyro.bodyRotation.yaw;
                MATCHING_KEEP(yawWord);
                newMoby->angle.pitch = 64;
                newMoby->angle.yaw = yawWord;
                func_80055C24(callActor);
            }
            tag->unk4 = 0;
            tag->unk0 = 120;
            break;
        }
        case 187: {
            SparxSpawnTag187* tag;
            Vector3D* position = &newMoby->position;
            newMoby->position.x = (D_80065920[spyro.bodyRotation.yaw] * 225) >> 11;
            newMoby->position.y = (D_800658A0[spyro.bodyRotation.yaw] * 225) >> 11;
            newMoby->position.z = 0;
            tag = newMoby->mobyTag;
            func_8004F194(position, position, &spyro.position);
            newMoby->angle.pitch = 0;
            newMoby->angle.yaw = spyro.bodyRotation.yaw;
            func_80055C24(newMoby);
            newMoby->state = 0;
            tag->unk0 = 180;
            tag->unk8 = func_80050844(position, -12, 12, 0x4080);
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
        case 373: {
            SparxSpawnVectorTag* tag;
            Vector3D* position = &newMoby->position;
            newMoby->position.x = (D_80065920[spyro.bodyRotation.yaw] * 225) >> 11;
            newMoby->position.y = (D_800658A0[spyro.bodyRotation.yaw] * 225) >> 11;
            newMoby->position.z = 0;
            tag = newMoby->mobyTag;
            func_8004F194(position, position, &spyro.position);
            newMoby->angle.roll = 64;
            func_80055C24(newMoby);
            tag->unk0.x = (D_80065920[spyro.bodyRotation.yaw] * 75) >> 10;
            tag->unk0.y = (D_800658A0[spyro.bodyRotation.yaw] * 75) >> 10;
            tag->unk0.z = 0;
            tag->unkC = 120;
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
        case 590: {
            SparxSpawnVectorTag* tag = newMoby->mobyTag;
            newMoby->angle.roll = 64;
            func_80055C24(newMoby);
            tag->unkC = 120;
            break;
        }
        case 591: {
            int* tag = newMoby->mobyTag;
            func_80055C24(newMoby);
            newMoby->state = 0;
            *tag = 180;
            break;
        }
        case 593: {
            SparxSpawnVectorTag* tag;
            Vector3D* position = &newMoby->position;
            {
                int tableWord = D_80065920[spyro.bodyRotation.yaw];
                newMoby->position.x = (short)tableWord >> 3;
            }
            {
                int tableWord = D_800658A0[spyro.bodyRotation.yaw];
                newMoby->position.y = (short)tableWord >> 3;
            }
            newMoby->position.z = 0;
            tag = newMoby->mobyTag;
            func_8004F194(position, position, &spyro.position);
            newMoby->angle.pitch = 64;
            func_80055C24(newMoby);
            tag->unkC = 90;
            break;
        }
        default: {
            Vector3D* mobyPos;
            Vector3D* newPos;
            if (linkedMoby != 0) {
                mobyPos = &newMoby->position;
                newPos = &linkedMoby->position;
            } else {
                case 163:
                    mobyPos = &newMoby->position;
                    newPos = &spyro.position;
            }
            func_8004F178(mobyPos, newPos);
        }
        case 601:
            func_80055C24(newMoby);
            break;
    }
    return newMoby;
}
