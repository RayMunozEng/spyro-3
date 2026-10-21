#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_36_8007F52C:
* SCUS-94467 USA Rev0, 654 original words; original assembly SHA256
* 91f758f7fd1ff640043658812528ccb0371bb966a480a3df3a31093b0e404529.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Level36 reuses existing31 common and41 class65 C. Its
* original69/116/147 retain selector0 calls, signed byte wrap and clamp,
* source-vector stack objects and tag offsets. The empty constraint in116
* consumes the initialized absolute-value copy and emits no CPU instruction;
* it preserves the original copy-then-negate producer without register binding.
* Level42 reuses37 effect327 as467/504/648/748, existing20 common/fragments,
* original348 and482/541. Original131/503/529 retain call/store order.
* In503, (signed16 * 16) >> 8 is exactly signed16 >> 4: the intermediate
* range [-524288,524272] fits signed32. It preserves original LH/SRA4;
* vectors -32768:-2048, -1:-1, 0:0, 15:0, 16:1, 32767:2047.
* This compiler expression does not establish a physical conversion.
* Whole unused views may be removed; retained layout fields stay intact.
* Every native/linked instruction/target plus EXE and all overlay hashes
* must match. Full helper/producer/asset/SFX meanings, physical units and
* fixed-point domains, frame cadence and synchronized runtime verification
* remain open. Invocation cadence only. No engine/browser or subsystem
* completion claim. AI changes have not been human reviewed.
*/
extern unsigned char Spawn31Byte71A04 __asm__("D_80071A04");
void func_80055F14(Moby*, int, Vector3D*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_80034F80(Moby*, int);
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
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
int func_8004F334(Vector3D*, Vector3D*);
typedef struct {
    Moby* linked0;
    int word4, word8, wordC, word10;
} Spawn36Tag69;
typedef struct {
    Vector3D vector0;
    int wordC;
    Moby* linked10;
} Spawn36VectorTag;
Moby* func_level_36_8007F52C(int mobyClass, Moby* linkedMoby) {
    Vector3D vector10;
    Vector3D vector20;
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
        case 65:
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            break;
        case 69: {
            Spawn36Tag69* tag = newMoby->mobyTag;
            Spawn36Tag69* linkedTag = linkedMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->position.z += 1536;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            newMoby->highDrawDistance = linkedMoby->highDrawDistance;
            tag->linked0 = linkedMoby;
            tag->word4 = -1;
            tag->word10 = linkedTag->word10;
            func_80055C24(newMoby);
            newMoby->state = 2;
            break;
        }
        case 116: {
            Spawn36VectorTag* tag = newMoby->mobyTag;
            Vector3D* position;
            int difference;
            int absolute;
            func_80055F14(linkedMoby, 0, &vector10);
            func_80055F14(linkedMoby, 0, &vector20);
            position = &newMoby->position;
            func_8004F194(position, &vector10, &vector20);
            func_8004F110(position, 1);
            newMoby->position.z -= 256;
            func_8004F1C8(&vector10, &spyro.position, position);
            difference = (func_8004E880(vector10.x, vector10.y, 0) - linkedMoby->angle.yaw) & 255;
            if (difference >= 129)
                difference -= 256;
            absolute = difference;
            if (difference < 0) {
                __asm__("" : " = r"(absolute) : "0"(absolute));
                absolute = -absolute;
            }
            if (absolute < 32) {
                newMoby->angle.pitch = func_8004E880(func_8004F334(position, &spyro.position),
                                                     spyro.position.z - newMoby->position.z, 0);
            } else {
                newMoby->angle.pitch = 251;
            }
            if (difference < -8)
                difference = -8;
            if (difference > 8)
                difference = 8;
            newMoby->angle.yaw = linkedMoby->angle.yaw + difference;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            newMoby->highDrawDistance = linkedMoby->highDrawDistance;
            func_80055C24(newMoby);
            tag->vector0.x = 256;
            tag->vector0.y = 0;
            tag->vector0.z = 0;
            func_8004ED6C(&newMoby->rotationMatrix, &tag->vector0, &tag->vector0);
            tag->wordC = 120;
            newMoby->unknown = -1;
            break;
        }
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
        case 147: {
            Spawn36VectorTag* tag = newMoby->mobyTag;
            func_80055F14(linkedMoby, 0, &newMoby->position);
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            tag->vector0.x = 128;
            tag->vector0.y = 0;
            tag->vector0.z = 96;
            func_8004ED6C(&newMoby->rotationMatrix, &tag->vector0, &tag->vector0);
            tag->wordC = 120;
            tag->linked10 = linkedMoby;
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
