#include "common.h"

// this one scares me

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_25_8007F7A4:
* SCUS-94467 USA Rev0, 678 original words; original assembly SHA256
* 37cea0d53d9ab09b5fe7d7ea44ad127cb5896405b1ab19a034116a59c8460991.
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
    Vector3D unk0;
    int unkC;
    int unk10;
} Spawn45Tag92;
typedef struct {
    short unk0, index2;
    int unk4, unk8;
    PathNode* nodesC;
} Spawn45PathView;
void func_80055F14(Moby*, int, Vector3D*);
void func_8003BABC(Moby*, int, int);
int func_8004EDE8(Vector3D*, int);
typedef struct {
    Moby* target0;
    short timer4, timer6;
} Spawn25Tag671;
typedef struct {
    unsigned char pad0[0x50];
    Vector3D target50;
    unsigned char pad5C[0x18];
    Moby* target74;
} Spawn25Linked671;
typedef struct {
    Moby* parent0;
    int word4;
} Spawn25Tag672;
typedef struct {
    Moby* parent0;
    Moby* target4;
    int word8;
} Spawn25Tag673;
static __inline__ int Spawn25BlendAngle(int requested, int base) {
    int difference = (requested - base) & 255;
    int twice;
    if (difference >= 129)
        difference -= 256;
    twice = difference * 2;
    difference = (twice + difference) >> 2;
    return base + difference;
}
Moby* func_level_25_8007F7A4(int mobyClass, Moby* linkedMoby) {
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
        case 92: {
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
        case 303: {
            Moby** tag = newMoby->mobyTag;
            func_80055F14(linkedMoby, 0, &newMoby->position);
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            newMoby->unknownCollision = 0;
            func_80034F80(newMoby, 1);
            newMoby->state = 6;
            newMoby->updateDistance = 255;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            *tag = linkedMoby;
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
        case 364:
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            func_80034F80(newMoby, 1);
            newMoby->state = 4;
            break;
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
        case 671: {
            Vector3D* position = &newMoby->position;
            Spawn25Tag671* tag = newMoby->mobyTag;
            Spawn25Linked671* linkedTag = linkedMoby->mobyTag;
            func_80055F14(linkedMoby, 0, position);
            if (linkedTag->target74 != 0) {
                Moby* target;
                newMoby->angle.roll = 0;
                newMoby->angle.pitch =
                    func_8004E880(func_8004F334(position, &linkedTag->target74->position),
                                  linkedTag->target74->position.z - newMoby->position.z, 0);
                target = linkedTag->target74;
                newMoby->angle.yaw = func_8004E880(target->position.x - newMoby->position.x,
                                                   target->position.y - newMoby->position.y, 0);
                tag->target0 = linkedTag->target74;
            } else {
                newMoby->angle.roll = 0;
                newMoby->angle.pitch =
                    Spawn25BlendAngle(func_8004E880(func_8004F334(position, &linkedTag->target50),
                                                    linkedTag->target50.z - newMoby->position.z, 0),
                                      linkedMoby->angle.pitch);
                newMoby->angle.yaw =
                    Spawn25BlendAngle(func_8004E880(linkedTag->target50.x - newMoby->position.x,
                                                    linkedTag->target50.y - newMoby->position.y, 0),
                                      linkedMoby->angle.yaw);
                tag->target0 = 0;
            }
            newMoby->lowDrawDistance = 63;
            newMoby->highDrawDistance = 63;
            func_80055C24(newMoby);
            tag->timer4 = 90;
            tag->timer6 = 10;
            func_8003BABC(newMoby, 0, 0);
            break;
        }
        case 672: {
            short linkedClass = linkedMoby->mobyClass;
            Spawn25Tag672* tag = newMoby->mobyTag;
            if (linkedClass == 653 || linkedClass == 673) {
                func_80055F14(linkedMoby, 2, &newMoby->position);
            } else {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            newMoby->angle.yaw = ((short)camera.unk48 >> 4) - 128;
            newMoby->angle.pitch = (unsigned short)camera.unk46 >> 4;
            func_80055C24(newMoby);
            tag->parent0 = linkedMoby;
            tag->word4 = 0;
            break;
        }
        case 673: {
            Vector3D* position = &newMoby->position;
            Spawn25Tag673* tag = newMoby->mobyTag;
            int* linkedTag = linkedMoby->mobyTag;
            int sizeWord;
            func_80055F14(linkedMoby, 0, position);
            func_80055C24(newMoby);
            func_80034F80(newMoby, 4);
            newMoby->state = 4;
            newMoby->unknownCollision = 0;
            tag->parent0 = linkedMoby;
            tag->target4 = &mobyArrayPtr[*linkedTag];
            tag->word8 = 0;
            func_8004F178(&v, &tag->target4->position);
            v.z += 1024;
            newMoby->angle.roll = 0;
            newMoby->angle.pitch =
                func_8004E880(func_8004F334(position, &v), v.z - newMoby->position.z, 0);
            newMoby->angle.yaw =
                func_8004E880(v.x - newMoby->position.x, v.y - newMoby->position.y, 0);
            func_8004F1C8(&v, &v, position);
            sizeWord = 0xAF60 / func_8004EDE8(&v, 1);
            if (sizeWord >= 128)
                sizeWord = 127;
            if (sizeWord <= 0)
                sizeWord = 1;
            newMoby->size = sizeWord;
            newMoby->lowDrawDistance = 63;
            newMoby->highDrawDistance = 63;
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


INCLUDE_RODATA("asm/nonmatchings/overlays/level_25/moby", D_level_25_80074674);