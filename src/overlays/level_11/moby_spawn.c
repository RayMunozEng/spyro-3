#include "common.h"

/**
 * ???() - func_level_11_80084A5C()
 * Very very close - one small register thing (class 0xF5)
 * decomp.me/scratch/FAXkz
 */
/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baselines: accepted upstream-linked PGLtI common spawn C;
* original include/moby/moby_spawn.h cases245/326; accepted gpXPY class84
* supplies level45's class715. Original-specific adapters and additions,
* cleanup and this provenance are AI generated and not human reviewed.
* func_level_11_80084A5C, SCUS-94467 USA Rev0: 655 original words;
* original assembly SHA256 fa49a4b3a3ec60b762065941e3784e65e0d0676c3981983d278a06525b199438.
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
extern CollisionData D_80071900;
void func_8004F110(Vector3D*, int);
int func_8004EDE8(Vector3D*, int);
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
// MobyTag_Fragment updated
int func_8004E9E4(int);
int func_8004EA2C(int);
void* func_80050844(Vector3D*, char, int, int);
Moby* func_level_11_80084A5C(int mobyClass, Moby* linkedMoby) {
    Vector3D vector;
    int y;
    Moby* newMoby;
    Vector3D* copyDestination;
    Vector3D* copySource;
    int randomAngleB;
    int randomAngleA;
    int helperReturn;
    char yawByte;
    int threshold;
    void* newTag;
    MobyTag_120* tag120;
    MobyTag_272* tag272;
    MobyTag_16* tag16;
    MobyTag_Fragment* fragmentTag;
    newMoby = func_80055A7C();
    if (newMoby == 0)
        return 0;
    newTag = newMoby->mobyTag;
    func_8004E790(newMoby, 0, 0x58);
    newMoby->mobyTag = newTag;
    func_8004E790(newTag, 0, 0x18);
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
        case 0x1:
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 0x18;
            newMoby->updateDistance = 0x40;
            newMoby->unknown = -1;
            break;
        case 0x10:
        case 0xD3:
            tag16 = newMoby->mobyTag;
            if (newMoby->mobyClass == 0x10) {
                threshold = 10;
                if (D_8006C784 < 4)
                    threshold = 7;
                else if (D_8006C784 < 7)
                    threshold = 9;
                sparx.butterflyCount++;
                if (sparx.butterflyCount >= threshold) {
                    sparx.butterflyCount = 0;
                    newMoby->mobyClass = 0xD3;
                }
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            newMoby->position.z += 0x200;
            func_8004F178(&tag16->unk0, &newMoby->position);
            newMoby->unknown = -1;
            newMoby->unknown4 = 2;
            tag16->unkE = 0x708;
            tag16->unk11 = 0;
            tag16->unk12 = (char)(rand() & 0xFC);
            break;
        case 0x78:
            if (linkedMoby->mobyClass != mobyClass) {
                newMoby->mobyTag = &D_8006E394;
                func_8004E790(&D_8006E394, 0, 0x1C);
            }
            tag120 = newMoby->mobyTag;
            func_80055C24(newMoby);
            newMoby->substate = 0;
            tag120->unk0 = 0;
            tag120->unk8 = 0;
            tag120->unk6 = 0;
            tag120->unk4 = 0;
            tag120->unkD = 0x78;
            tag120->unk10 = 0;
            tag120->unk14 = 0;
            if (linkedMoby != 0) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            } else {
                yawByte = spyro.bodyRotation.yaw - 0x80;
                vector.x = (D_80065920[yawByte] * 0x7D) >> 9;
                vector.y = (D_800658A0[yawByte] * 0x7D) >> 9;
                vector.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &vector);
            }
            tag120->unk2 = 0xFF;
            break;
        case 0x84:
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            helperReturn = func_80035D38(newMoby);
            if (helperReturn != 0) {
                newMoby->position.z = helperReturn;
            }
            newMoby->state = 6;
            break;
        case 0xAA:
            newMoby->unknown3[0] = 0;
            newMoby->animationProgress = 0;
            newMoby->animationState.frame = 0;
            newMoby->animationState.nextFrame = 0;
            if (linkedMoby != 0) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            newMoby->size = 0x18;
            newMoby->lowDrawDistance = 0x28;
            func_80055C24(newMoby);
            break;
        case 245: {
            MobyTag_245* mobyTag;
            int rand1;
            int rand2;
            int randomPart;
            mobyTag = newMoby->mobyTag;
            if (linkedMoby)
                func_8004F178(&newMoby->position, &linkedMoby->position);
            else
                func_8004F178(&newMoby->position, &spyro.position);
            randomPart = (rand() & 31) + 112;
            rand1 = (linkedMoby->angle.yaw + randomPart) & 255;
            rand2 = (rand() & 15) + 8;
            newMoby->position.z += 1536;
            mobyTag->unk0.x = (((D_80065920[rand1] * 3) >> 4) * D_80065920[rand2]) >> 0xC;
            mobyTag->unk0.y = (((D_800658A0[rand1] * 3) >> 4) * D_80065920[rand2]) >> 0xC;
            mobyTag->unk0.z = (D_800658A0[rand2] * 3) >> 4;
            mobyTag->unkC = func_8003636C(0x78, 0xB4);
            func_8004F194(&newMoby->position, &newMoby->position, &mobyTag->unk0);
            func_8004F110(&mobyTag->unk0, 1);
            newMoby->angle.yaw = rand();
            func_80055C24(newMoby);
            switch (rand() & 3) {
                case 0:
                    *(int*)&newMoby->colour = 0x3C0000FF;
                    break;
                case 1:
                    *(int*)&newMoby->colour = 0x3C00A0B0;
                    break;
                case 2:
                    *(int*)&newMoby->colour = 0x3C0080FF;
                    break;
                case 3:
                    *(int*)&newMoby->colour = 0x3C000000;
                    break;
                default:
                    break;
            }
            break;
        }
        case 0x104:
            func_80055C24(newMoby);
            newMoby->colour.r = 2;
            if (linkedMoby != 0) {
                ((MobyTag_260*)newMoby->mobyTag)->unk0 = linkedMoby;
                func_8004F178(&newMoby->position, &linkedMoby->position);
                newMoby->updateDistance = 0xA;
                newMoby->lowDrawDistance = 8;
                newMoby->position.z += 0x400;
            } else {
                newMoby->unknown = -1;
                break;
            }
            break;
        case 0x110:
            tag272 = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &spyro.position);
            newMoby->position.z += 0x400;
            newMoby->angle.yaw = spyro.bodyRotation.yaw;
            func_80055C24(newMoby);
            tag272->unk2 = 2;
            tag272->unk3 = spyro.bodyRotation.yaw;
            tag272->unk4 = spyro.bodyRotation.yaw;
            tag272->unk10 = -1;
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            break;
        case 0x132:
        case 0x134:
        case 0x133:
        case 0x238:
            fragmentTag = newMoby->mobyTag;
            newMoby->lowDrawDistance = 0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            randomAngleA = rand() & 0xFFF;
            randomAngleB = rand() & 0x7FF;
            fragmentTag->linearVel.x = (func_8004EA2C(randomAngleB) * func_8004EA2C(randomAngleA) *
                                        linkedMoby->substate) >>
                                       0x18;
            fragmentTag->linearVel.y = (func_8004EA2C(randomAngleB) * func_8004E9E4(randomAngleA) *
                                        linkedMoby->substate) >>
                                       0x18;
            fragmentTag->linearVel.z = (func_8004E9E4(randomAngleB) * linkedMoby->substate) >> 0xC;
            if (linkedMoby->damageFlags & 0x02000000) {
                vector.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x,
                                                    newMoby->position.y - spyro.position.y, 0)];
                vector.x = (short)vector.x >> 4;
                vector.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x,
                                                    newMoby->position.y - spyro.position.y, 0)];
                vector.y = (short)vector.y >> 4;
                vector.z = 0;
                fragmentTag->linearVel.x += vector.x;
                fragmentTag->linearVel.y += vector.y;
            } else if ((linkedMoby->damageFlags & 0x20000) &&
                       ((spyro.movementState == 4) || (spyro.movementState == 0xC))) {
                fragmentTag->linearVel.x += spyro.unk7a[2].x >> 6;
                fragmentTag->linearVel.y += spyro.unk7a[2].y >> 6;
            }
            if ((linkedMoby->unkb != 0) && (linkedMoby->damageFlags & 0x100000)) {
                fragmentTag->linearVel.x += (D_80065920[linkedMoby->unkb] * 0x4B) >> 0xB;
                fragmentTag->linearVel.y += (D_800658A0[linkedMoby->unkb] * 0x4B) >> 0xB;
                fragmentTag->linearVel.z += func_8003636C(0x28, 0x46);
            }
            newMoby->position.x += fragmentTag->linearVel.x * 4;
            newMoby->position.y += fragmentTag->linearVel.y * 4;
            newMoby->position.z += fragmentTag->linearVel.z * 4;
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            fragmentTag->angularVel.x = (rand() & 0x1F) - 0x10;
            fragmentTag->angularVel.y = (rand() & 0x1F) - 0x10;
            fragmentTag->angularVel.z = (rand() & 0x1F) - 0x10;
            fragmentTag->unk10 = linkedMoby->position.z - 0x40;
            fragmentTag->timer = func_8003636C(0x32, 0x50);
            break;
        case 356: {
            int value;
            if (linkedMoby != 0) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            } else {
                func_8004F178(&newMoby->position, &spyro.position);
            }
            func_80055C24(newMoby);
            value = func_80035D38(newMoby);
            newMoby->position.z = value;
            if (value != 0) {
                newMoby->angle.yaw =
                    func_8004E880(D_80071900.D_80071918.x, D_80071900.D_80071918.y, 0);
                newMoby->angle.pitch = func_8004E880(func_8004EDE8(&D_80071900.D_80071918, 0),
                                                     D_80071900.D_80071918.z, 0) -
                                       64;
            }
            newMoby->size = 127;
            break;
        }
        default:
            if (linkedMoby != 0) {
                copyDestination = &newMoby->position;
                copySource = &linkedMoby->position;
            } else {
                copyDestination = &newMoby->position;
                copySource = &spyro.position;
            }
            func_8004F178(copyDestination, copySource);
            func_80055C24(newMoby);
            break;
    }
    return newMoby;
}
