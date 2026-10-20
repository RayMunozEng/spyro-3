#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_34_8008ECE0:
* SCUS-94467 USA Rev0, 891 original words; original assembly SHA256
* 2bfc6052b22e2a777b890102c5e92e50ba914fc2c3134fbcc4079a018b51bff3.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Class90/326 reuse original repository C;482/541 reuse the
* accepted level45 source. Class483 keeps original camera/player branches,
* the three camera-vector additions, distinct matrix/angle stack objects,
* arena guards and allocation-size producer. Caller4E7D4 uses the original
* raw copy count8. Fresh color-byte reads are staged in ordinary C. Final
* vector calls remain inside their original branches, preserving the
* original common call tail and both pointer producers. Offset views do
* not assert complete object/helper contracts or matrix units.
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
typedef struct {
    Vector3D16 vector0;
    unsigned char byte6, byte7;
    int* buffer8;
    int wordC;
    int words10[2];
}
Spawn34Tag483;
Moby* func_level_34_8008ECE0(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D v2;
    Vector3D v;
    SHORTMATRIX matrix30;
    Angle angle48;
    SHORTMATRIX matrix50;
    Angle angle68;
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
    case 90:
        {
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
            }
            else {
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
    case 482:
        {
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
    case 483:
        {
            Spawn34Tag483* tag = newMoby->mobyTag;
            Vector3D* addDestination;
            Vector3D* addLeft;
            Vector3D* addSource;
            int greenByte;
            Moby* arenaMoby;
            int allocationBytes;
            int* arena;
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            if (!linkedMoby) {
                v.x = 440;
                v.y = 0;
                v.z = 0;
                if (camera.cameraState==7 && camera.unk50==3) {
                    Vector3D* cameraPosition = &newMoby->position;
                    func_8004F178(cameraPosition, &camera.nextCameraPosCartesian);
                    angle48.roll = 0;
                    angle48.pitch = -((short)camera.unk46>>4);
                    angle48.yaw = (unsigned short)camera.unk48>>4;
                    func_8004EA90(&angle48, &matrix30, 0);
                    func_8004ED6C(&matrix30, &v, &v);
                    func_8004F194(cameraPosition, cameraPosition, &v);
                    func_8004F194(cameraPosition, cameraPosition, &v);
                    func_8004F194(cameraPosition, cameraPosition, &v);
                }
                else {
                    Vector3D* actorPosition;
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    angle68.roll = 0;
                    angle68.pitch = spyro.bodyRotation.pitch;
                    if (spyro.ticksSinceLastSurfaceTouch==0 && (unsigned char)(spyro.bodyRotation.pitch-4) >= 249) angle68.pitch = 0;
                    angle68.yaw = spyro.bodyRotation.yaw;
                    func_8004EA90(&angle68, &matrix50, 0);
                    func_8004ED6C(&matrix50, &v, &v);
                    actorPosition = &newMoby->position;
                    actorPosition->x = 500;
                    actorPosition->y = 0;
                    actorPosition->z = 0;
                    func_8004ED6C(&matrix50, actorPosition, actorPosition);
                    func_8004F194(actorPosition, actorPosition, &spyro.position);
                }
                newMoby->angle.pitch = func_8004E880(func_8004EDE8(&v, 0), v.z, 0);
                newMoby->angle.yaw = func_8004E880(v.x, v.y, 0);
                arenaMoby = mobyArrayPtr;
                tag->vector0.x = v.x;
                tag->vector0.y = v.y;
                tag->vector0.z = v.z;
                allocationBytes = 0x144;
                for (;arenaMoby<D_8006C704;arenaMoby++) {
                    if (arenaMoby->mobyClass==1020) break;
                }
                if (arenaMoby) {
                    arena = arenaMoby->mobyTag;
                    if (arena[1]>allocationBytes) allocationBytes = arena[1];
                    arena[0] += allocationBytes;
                    if (arena[0]+allocationBytes >= arena[2]) arena[0] = 0;
                    tag->buffer8 = (int*)((char*)arena+(arena[0]+0x14));
                    *tag->buffer8 = 0;
                    func_8004E7D4(tag->words10, arena+3, 8);
                }
                tag->byte7 = 110;
                newMoby->unknown5 = 1;
                func_8003BABC(newMoby, 0, 0);
                return newMoby;
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            tag->byte7 = 48;
            newMoby->size = 127;
            newMoby->colour.r = (tag->byte7*3)>>1;
            greenByte = tag->byte7;
            newMoby->colour.b = 0;
            newMoby->colour.a = 63;
            newMoby->colour.g = greenByte;
            break;
        }
    case 541:
        {
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
