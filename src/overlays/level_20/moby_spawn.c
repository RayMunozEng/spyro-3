#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_20_80084218:
* SCUS-94467 USA Rev0, 1001 original words; original assembly SHA256
* b2d915da16ff5b5b45c2af1da3caf3409ccc837f1a3120e812057f44196f75c5.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Class483 reuses accepted level34 C;426/427 and their complete
* offset views reuse level10. Class522 retains original linked499 and
* random-table paths, fresh signed halfword reads and original timers.
* Its final Z expression uses (signed16 *64)>>12 to reproduce original
* LH/SRA6/SH. Signed16*64 fits signed32 [-2097152,2097088], and shifting12
* equals signed16>>6 for every input. Falsifiable examples: -32768->-512,
* -1->-1,0->0,63->0,64->1,32767->511. This is the original shift's compiler
* expression. Original SP10 vector and matrix/angle objects SP20/SP38 and
* SP40/SP58 are retained. Views identify observed offsets only.
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
typedef struct {
    int unk0;
    int unk4;
} Spawn10Tag426;
typedef struct {
    int unk0;
    int unk4;
    void* unk8;
} Spawn10Tag427;
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
} Spawn10Tag54View;
void func_80055F14(Moby*, int, Vector3D*);
void* func_80050844(Vector3D*, char, int, int);
typedef struct {
    Vector3D vector0;
    int wordC;
    Moby* linked10;
} Spawn20Tag522;
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
} Spawn14Tag84;
Moby* func_level_20_80084218(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D v;
    SHORTMATRIX matrix30;
    Angle angle48;
    SHORTMATRIX matrix50;
    Angle angle68;
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
        case 310:
        case 568:
        case 306:
        case 307:
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
        case 426: {
            Spawn10Tag426* tag426 = newMoby->mobyTag;
            Spawn10Tag54View* linkedTag54A = linkedMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.pitch = 32;
            func_80055C24(newMoby);
            tag426->unk0 = 0;
            tag426->unk4 = linkedTag54A->unk54;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            break;
        }
        case 427: {
            Vector3D* position = &newMoby->position;
            Spawn10Tag427* tag427 = newMoby->mobyTag;
            Spawn10Tag54View* linkedTag54B = linkedMoby->mobyTag;
            func_8004F178(position, &linkedMoby->position);
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            func_80055C24(newMoby);
            tag427->unk0 = 0;
            tag427->unk4 = linkedTag54B->unk54;
            tag427->unk8 = func_80050844(position, 6, 6, 0xFFFFFF);
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
                v.x = 440;
                v.y = 0;
                v.z = 0;
                if (camera.cameraState == 7 && camera.unk50 == 3) {
                    Vector3D* cameraPosition = &newMoby->position;
                    func_8004F178(cameraPosition, &camera.nextCameraPosCartesian);
                    angle48.roll = 0;
                    angle48.pitch = -((short)camera.unk46 >> 4);
                    angle48.yaw = (unsigned short)camera.unk48 >> 4;
                    func_8004EA90(&angle48, &matrix30, 0);
                    func_8004ED6C(&matrix30, &v, &v);
                    func_8004F194(cameraPosition, cameraPosition, &v);
                    func_8004F194(cameraPosition, cameraPosition, &v);
                    func_8004F194(cameraPosition, cameraPosition, &v);
                } else {
                    Vector3D* actorPosition;
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    angle68.roll = 0;
                    angle68.pitch = spyro.bodyRotation.pitch;
                    if (spyro.ticksSinceLastSurfaceTouch == 0 &&
                        (unsigned char)(spyro.bodyRotation.pitch - 4) >= 249)
                        angle68.pitch = 0;
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
        case 522: {
            if (linkedMoby->mobyClass == 499) {
                Spawn20Tag522* tag = newMoby->mobyTag;
                int xWord, yWord;
                func_80055F14(linkedMoby, 0, &newMoby->position);
                newMoby->angle.yaw = linkedMoby->angle.yaw;
                func_80055C24(newMoby);
                tag->linked10 = linkedMoby;
                xWord = D_80065920[newMoby->angle.yaw];
                tag->vector0.x = (short)xWord >> 5;
                yWord = D_800658A0[newMoby->angle.yaw];
                tag->vector0.z = 96;
                tag->vector0.y = (short)yWord >> 5;
                newMoby->state = 0;
            } else {
                Spawn14Tag84* tag = newMoby->mobyTag;
                int azimuth, elevation;
                short* elevationWord;
                short* cosineTable;
                azimuth = rand() & 255;
                elevation = rand() & 127;
                cosineTable = D_80065920;
                elevationWord = (short*)((char*)cosineTable + elevation * 2);
                tag->unk0.x = (*elevationWord * (cosineTable[azimuth] << 6)) >> 24;
                tag->unk0.y = (*elevationWord * (D_800658A0[azimuth] << 6)) >> 24;
                tag->unk0.z = (D_800658A0[elevation] * 64) >> 12;
                newMoby->position.x = linkedMoby->position.x + tag->unk0.x * 4;
                newMoby->position.y = linkedMoby->position.y + tag->unk0.y * 4;
                newMoby->position.z = linkedMoby->position.z + tag->unk0.z * 4;
                newMoby->angle.pitch = rand();
                newMoby->angle.yaw = rand();
                tag->unk6.x = (rand() & 14) - 7;
                tag->unk6.y = (rand() & 14) - 7;
                tag->unk6.z = (rand() & 14) - 7;
                tag->unkC = func_8003636C(30, 50);
                tag->unk10 = 8;
                tag->unk12 = 128;
                func_80055C24(newMoby);
                newMoby->size = 80;
                newMoby->unknownCollision = 0;
                newMoby->state = 7;
            }
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
