#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class76/90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_26_800846B4:
* SCUS-94467 USA Rev0, 898 original words; original assembly SHA256
* d821eac692515adc5e8a5c36c52691f7fe0a4d99b8a1576a73f0aacb78a59471.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Class76/90/326 reuse original repository C;104/149/356/1005
* preserve this original's offsets and calls. Class149 angle remains32-bit
* after its signed adjustment. The5th argument is the original SP38 address;
* SP18 and SP28 vector allocations are original. Class1005 keeps original
* arena scan guards and9D0-byte clear. Views identify observed offsets only.
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
void func_8004E7AC(int* dest, int set, int len);
void func_80055D10(Moby*);
void func_8004ED6C(void*, Vector3D*, Vector3D*);
#include "ovl_header.h"
int func_8001A358(Vector3D*, int);
int func_8004EDE8(Vector3D*, int);
void func_80055F14(Moby*, int, Vector3D*);
int func_800365E4(Vector3D*, Vector3D*, int, int, int*);
extern CollisionData D_80071900;
extern Moby* D_8006C704;
typedef struct {
    Vector3D vector0;
    Moby* linkedC;
} Spawn26Tag149;
typedef struct {
    short unk0;
    short unk2;
    void* unk4;
    int unk8;
    int unkC;
    Moby* unk10;
} Spawn14Tag1015;
Moby* func_level_26_800846B4(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D v2;
    Vector3D v;
    int output38;
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
        case 76: {
            MobyTag_76* mobyTag;
            if ((linkedMoby->mobyClass == mobyClass) || (linkedMoby->mobyClass == 0x142) ||
                (linkedMoby->mobyClass == 0x15C)) {
                mobyTag = linkedMoby->mobyTag;
                unk_ovlheader_800743E4(&newMoby->position, (rand() & 0xFF) - 0x7F,
                                       (rand() & 0xFF) - 0x7F, &mobyTag->unk0);
            } else {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            newMoby->position.z += 0x80;
            newMoby->position.z = func_8001A358(&newMoby->position, 0x1000);
            newMoby->state = 2;
            newMoby->substate = 0;
            func_80055C24(newMoby);
            break;
        }
        case 90: {
            MobyTag_89* byrdTag;
            MobyTag_90* mobyTag;
            byrdTag = linkedMoby->mobyTag;
            mobyTag = newMoby->mobyTag;
            v2.x = 0;
            v2.y = 0xC0;
            if (byrdTag->unk28 != 0) {
                v2.y = -0xC0;
            }
            if (camera.cameraState == 7 && camera.unk50 != 1) {
                v2.z = 0;
                func_8004ED6C(&camera.unk14, &v2, &v2);
                func_8004F194(&newMoby->position, &camera.nextCameraPosCartesian, &v2);
                newMoby->angle.roll = camera.unk44 >> 4;
                newMoby->angle.pitch = -camera.unk46 >> 4;
                newMoby->angle.yaw = camera.unk48 >> 4;
            } else {
                v2.z = 0x180;
                func_8004ED6C(&linkedMoby->rotationMatrix, &v2, &v2);
                func_8004F194(&newMoby->position, &linkedMoby->position, &v2);
                newMoby->angle.roll = linkedMoby->angle.roll;
                newMoby->angle.pitch = linkedMoby->angle.pitch;
                newMoby->angle.yaw = linkedMoby->angle.yaw;
            }
            mobyTag->unk14 = byrdTag->unk5C;
            func_80055C24(newMoby);
            newMoby->state = 0;
            break;
        }
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
        case 104: {
            Moby** tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->distanceToGround = 150;
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch + 64;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            *tag = linkedMoby;
            func_80055C24(newMoby);
            newMoby->state = 1;
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
        case 149: {
            Spawn26Tag149* tag;
            int angle;
            if (linkedMoby) {
                if (linkedMoby->mobyClass == newMoby->mobyClass) {
                    func_8004F178(&newMoby->position, &linkedMoby->position);
                    func_80055C24(newMoby);
                } else {
                    tag = newMoby->mobyTag;
                    func_80055F14(linkedMoby, 0, &newMoby->position);
                    func_80055C24(newMoby);
                    angle = func_8004E880(spyro.position.x - newMoby->position.x,
                                          spyro.position.y - newMoby->position.y, 0);
                    if (linkedMoby->mobyClass == 148 && ((int*)linkedMoby->mobyTag)[9] == 0) {
                        if (rand() & 1)
                            angle += 8;
                        else
                            angle -= 8;
                    }
                    tag->vector0.x = (D_80065920[angle] * 75) >> 10;
                    tag->vector0.y = (D_800658A0[angle] * 75) >> 10;
                    tag->vector0.z = 0;
                    tag->vector0.z =
                        func_800365E4(&newMoby->position, &spyro.position, 300, -10, &output38);
                    if (tag->vector0.z >= 201)
                        tag->vector0.z = 200;
                    if (tag->vector0.z < -70)
                        tag->vector0.z = -70;
                    tag->linkedC = linkedMoby;
                }
            } else {
                func_8004F178(&newMoby->position, &spyro.position);
                func_80055C24(newMoby);
            }
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
        case 630:
        case 631:
        case 568:
        case 306:
        case 308: {
            MobyTag_Fragment* mobyTag;
            int azimuth;
            int elevation;
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
        case 356: {
            Vector3D* position;
            Vector3D* source;
            if (linkedMoby) {
                position = &newMoby->position;
                source = &linkedMoby->position;
            } else {
                position = &newMoby->position;
                source = &spyro.position;
            }
            func_8004F178(position, source);
            func_80055C24(newMoby);
            newMoby->position.z = func_80035D38(newMoby);
            if (newMoby->position.z) {
                newMoby->angle.yaw =
                    func_8004E880(D_80071900.D_80071918.x, D_80071900.D_80071918.y, 0);
                newMoby->angle.pitch = func_8004E880(func_8004EDE8(&D_80071900.D_80071918, 0),
                                                     D_80071900.D_80071918.z, 0) -
                                       64;
            }
            newMoby->size = 127;
            break;
        }
        case 1005: {
            Spawn14Tag1015* tag = newMoby->mobyTag;
            Moby* arenaMoby;
            void* buffer;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->updateDistance = 255;
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            for (arenaMoby = mobyArrayPtr; arenaMoby < D_8006C704; arenaMoby++) {
                if (arenaMoby->mobyClass == 1020 && ((int*)arenaMoby->mobyTag)[2] == 0x13A0)
                    break;
            }
            if (arenaMoby) {
                buffer = (char*)arenaMoby->mobyTag + 0x14;
                tag->unk4 = buffer;
                func_8004E7AC(buffer, 0, 0x9D0);
                tag->unk0 = 200;
                tag->unk10 = arenaMoby;
            }
            break;
        }
        default: {
            if (linkedMoby) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            } else {
                func_8004F178(&newMoby->position, &spyro.position);
            }
            func_80055C24(newMoby);
            break;
        }
    }
    return newMoby;
}
