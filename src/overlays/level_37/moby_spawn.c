#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_37_800841C8:
* SCUS-94467 USA Rev0, 1082 original words; original assembly SHA256
* 322c7b57e523cc1459a4c42f76a7ffc545f36ad3128ff48f00257a36694c444b.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Existing20/34 common/matrix483 and original326/482/541 C
* are reused. Class327 adapts credited gpXPY/Hwd40584 with the original
* Spyro yaw producer, hit coefficients, two local matrix operations and
* timer arguments. Original181/447/448 widths, clamps, masks and fields
* are retained. Class448 timer has only an unsigned byte consumer; a byte
* temporary preserves the original SUBU/byteD=8/byteC/halfE=4 sequence.
* Stack objects remain SP10/20/38/40/50/68/80. Whole unused type views may
* be removed; every field within a retained view stays at its original
* observed offset. No complete object/helper contract is inferred.
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
} Spawn34Tag483;
void func_80055F14(Moby*, int, Vector3D*);
void* func_80050844(Vector3D*, char, int, int);
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
} Spawn14Tag84;
typedef struct {
    Vector3D16 vector0, vector6;
    int timerC;
} Spawn37Tag181;
typedef struct {
    Vector3D vector0;
    short timerC, padE;
    unsigned char byte10, byte11, byte12, byte13;
    int word14;
} Spawn37Tag447;
typedef struct {
    Vector3D16 vector0, vector6;
    unsigned char byteC, byteD;
    short wordE;
    int word10;
} Spawn37Tag448;
Moby* func_level_37_800841C8(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D vector10;
    SHORTMATRIX matrix20;
    Angle angle38;
    Vector3D vector40;
    SHORTMATRIX matrix50;
    SHORTMATRIX matrix68;
    Angle angle80;
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
        case 65:
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            break;
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
                vector10.x = (D_80065920[yaw] * 0x7D) >> 9;
                vector10.y = (D_800658A0[yaw] * 0x7D) >> 9;
                vector10.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &vector10);
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
        case 181: {
            if (linkedMoby && linkedMoby->mobyClass == mobyClass) {
                Spawn37Tag181* tag = newMoby->mobyTag;
                int azimuth, elevation, coefficient180, coefficient240;
                newMoby->lowDrawDistance = 40;
                func_8004F178(&newMoby->position, &linkedMoby->position);
                func_80055C24(newMoby);
                azimuth = rand() & 4095;
                elevation = func_8003636C(200, 1024);
                coefficient180 = 180;
                tag->vector0.x =
                    ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * coefficient180)) >>
                    18;
                tag->vector0.y =
                    ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * coefficient180)) >>
                    18;
                coefficient240 = 240;
                tag->vector0.z = (func_8004E9E4(elevation) * coefficient240) >> 12;
                newMoby->position.x += tag->vector0.x * 2;
                newMoby->position.y += tag->vector0.y * 2;
                newMoby->position.z += tag->vector0.z * 2;
                tag->vector6.x = (rand() & 31) - 16;
                tag->vector6.y = (rand() & 31) - 16;
                tag->vector6.z = (rand() & 31) - 16;
                tag->timerC = func_8003636C(120, 160);
            } else {
                if (linkedMoby)
                    func_8004F178(&newMoby->position, &linkedMoby->position);
                else
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
        case 327: {
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
            azimuth = (spyro.bodyRotation.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius = 0x78;
            mobyTag->unk0.x =
                ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y =
                ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2 = 0x96;
            mobyTag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0xF) >> 9;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0xF) >> 9;
                mobyTag->unk0.z += func_8003636C(70, 100);
            }
            vector10.x = 0;
            vector10.y = 0;
            vector10.z = 256;
            angle38.roll = linkedMoby->angle.roll;
            angle38.pitch = linkedMoby->angle.pitch;
            angle38.yaw = linkedMoby->angle.yaw;
            func_8004EA90(&angle38, &matrix20, 0);
            func_8004ED6C(&matrix20, &vector10, &vector10);
            func_8004F194(&newMoby->position, &newMoby->position, &vector10);
            vector10.x = mobyTag->unk0.x;
            vector10.y = mobyTag->unk0.y;
            vector10.z = mobyTag->unk0.z;
            func_8004ED6C(&matrix20, &vector10, &vector10);
            mobyTag->unk0.x = vector10.x;
            mobyTag->unk0.y = vector10.y;
            mobyTag->unk0.z = vector10.z;
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x37) >> 0xA;
            } else {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
            }
            newMoby->angle.roll = rand();
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->position.x += mobyTag->unk0.x * 2;
            newMoby->position.y += mobyTag->unk0.y * 2;
            newMoby->position.z += mobyTag->unk0.z * 2;
            mobyTag->unk6.x = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z = (rand() & 0x1F) - 0x10;
            mobyTag->unkC = func_8003636C(90, 150);
            mobyTag->unkE = 1;
            break;
        }
        case 447: {
            Vector3D* linkedPosition = &linkedMoby->position;
            Spawn37Tag447* tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, linkedPosition);
            func_80055C24(newMoby);
            func_8004F178(&tag->vector0, linkedPosition);
            tag->timerC = 200;
            tag->byte10 = 70;
            tag->byte11 = 3;
            tag->byte12 = 48;
            break;
        }
        case 448: {
            Spawn37Tag448* tag = newMoby->mobyTag;
            int azimuth, elevation, vertical;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            azimuth = rand() & 4095;
            elevation = func_8003636C(300, 2048);
            tag->vector0.x = (func_8004EA2C(elevation) >> 5) * (func_8004EA2C(azimuth) >> 12);
            tag->vector0.y = (func_8004EA2C(elevation) >> 5) * (func_8004E9E4(azimuth) >> 12);
            vertical = func_8004E9E4(elevation) >> 5;
            tag->vector0.z = vertical;
            if ((short)vertical < 32)
                tag->vector0.z = 32;
            tag->vector0.z += 32;
            newMoby->angle.yaw = rand();
            if ((rand() & 255) >= 129) {
                newMoby->angle.pitch = (rand() & 28) - 16;
                tag->word10 = 1;
                if (tag->vector0.z >= 33)
                    tag->vector0.z = 32;
            }
            newMoby->position.x += tag->vector0.x * 4;
            newMoby->position.y += tag->vector0.y * 4;
            newMoby->position.z += tag->vector0.z * 4;
            tag->vector6.x = (rand() & 31) - 16;
            tag->vector6.y = (rand() & 31) - 16;
            tag->vector6.z = (rand() & 31) - 16;
            {
                unsigned char timer = 50 - func_8003636C(0, 20);
                tag->byteD = 8;
                tag->byteC = timer;
            }
            tag->wordE = 4;
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
        case 483: {
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
                vector40.x = 440;
                vector40.y = 0;
                vector40.z = 0;
                if (camera.cameraState == 7 && camera.unk50 == 3) {
                    Vector3D* cameraPosition = &newMoby->position;
                    func_8004F178(cameraPosition, &camera.nextCameraPosCartesian);
                    angle38.roll = 0;
                    angle38.pitch = -((short)camera.unk46 >> 4);
                    angle38.yaw = (unsigned short)camera.unk48 >> 4;
                    func_8004EA90(&angle38, &matrix50, 0);
                    func_8004ED6C(&matrix50, &vector40, &vector40);
                    func_8004F194(cameraPosition, cameraPosition, &vector40);
                    func_8004F194(cameraPosition, cameraPosition, &vector40);
                    func_8004F194(cameraPosition, cameraPosition, &vector40);
                } else {
                    Vector3D* actorPosition;
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    angle80.roll = 0;
                    angle80.pitch = spyro.bodyRotation.pitch;
                    if (spyro.ticksSinceLastSurfaceTouch == 0 &&
                        (unsigned char)(spyro.bodyRotation.pitch - 4) >= 249)
                        angle80.pitch = 0;
                    angle80.yaw = spyro.bodyRotation.yaw;
                    func_8004EA90(&angle80, &matrix68, 0);
                    func_8004ED6C(&matrix68, &vector40, &vector40);
                    actorPosition = &newMoby->position;
                    actorPosition->x = 500;
                    actorPosition->y = 0;
                    actorPosition->z = 0;
                    func_8004ED6C(&matrix68, actorPosition, actorPosition);
                    func_8004F194(actorPosition, actorPosition, &spyro.position);
                }
                newMoby->angle.pitch = func_8004E880(func_8004EDE8(&vector40, 0), vector40.z, 0);
                newMoby->angle.yaw = func_8004E880(vector40.x, vector40.y, 0);
                arenaMoby = mobyArrayPtr;
                tag->vector0.x = vector40.x;
                tag->vector0.y = vector40.y;
                tag->vector0.z = vector40.z;
                allocationBytes = 0x144;
                for (; arenaMoby < D_8006C704; arenaMoby++) {
                    if (arenaMoby->mobyClass == 1020)
                        break;
                }
                if (arenaMoby) {
                    arena = arenaMoby->mobyTag;
                    if (arena[1] > allocationBytes)
                        allocationBytes = arena[1];
                    arena[0] += allocationBytes;
                    if (arena[0] + allocationBytes >= arena[2])
                        arena[0] = 0;
                    tag->buffer8 = (int*)((char*)arena + (arena[0] + 0x14));
                    *tag->buffer8 = 0;
                    func_8004E7D4(tag->words10, arena + 3, 8);
                }
                tag->byte7 = 110;
                newMoby->unknown5 = 1;
                func_8003BABC(newMoby, 0, 0);
                return newMoby;
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            tag->byte7 = 48;
            newMoby->size = 127;
            newMoby->colour.r = (tag->byte7 * 3) >> 1;
            greenByte = tag->byte7;
            newMoby->colour.b = 0;
            newMoby->colour.a = 63;
            newMoby->colour.g = greenByte;
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
