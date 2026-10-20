#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_42_800839A8:
* SCUS-94467 USA Rev0, 1092 original words; original assembly SHA256
* 80fa5b636151a06ede85f05e1603a72bbde4e7163939c04da96409de0dc73f29.
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
void func_80055F14(Moby*, int, Vector3D*);
void* func_80050844(Vector3D*, char, int, int);
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
}
Spawn14Tag84;
#include "ovl_header.h"
int func_8001A358(Vector3D*, int);
void func_80034F80(Moby*, int);
typedef struct {
    Vector3D vector0;
    unsigned short timerC;
    unsigned char padE[3];
    unsigned char pitch11, yaw12, pad13;
    int word14;
}
Spawn42Tag131;
typedef struct {
    Vector3D vector0;
    int timerC;
    Moby* linked10;
}
Spawn42Tag503;
Moby* func_level_42_800839A8(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D vector10;
    SHORTMATRIX matrix20;
    Angle angle38;
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
    case 348:
        {
            MobyTag_76* mobyTag;
            if ((linkedMoby->mobyClass == 0x4C) || (linkedMoby->mobyClass == 0x142) || (linkedMoby->mobyClass == mobyClass)) {
                mobyTag = linkedMoby->mobyTag;
                unk_ovlheader_800743E4(&newMoby->position, (rand() & 0xFF) - 0x7F, (rand() & 0xFF) - 0x7F, &mobyTag->unk0);
            }
            else {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            newMoby->position.z += 0x80;
            newMoby->position.z = func_8001A358(&newMoby->position, 0x1000);
            newMoby->state = 2;
            newMoby->substate = 0;
            func_80055C24(newMoby);
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
                vector10.x = (D_80065920[yaw] * 0x7D) >> 9;
                vector10.y = (D_800658A0[yaw] * 0x7D) >> 9;
                vector10.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &vector10);
            }
            mobyTag->unk2 = 0xFF;
            break;
        }
    case 131:
        {
            Spawn42Tag131* tag = newMoby->mobyTag;
            int redWord, greenWord, blueWord;
            func_80055C24(newMoby);
            if (linkedMoby->mobyClass!=newMoby->mobyClass) {
                tag->vector0.x = 400;
                tag->vector0.y = 0;
                tag->vector0.z = 0;
                func_80055D24(linkedMoby, 4);
                func_8004ED6C(&linkedMoby->rotationMatrix, &tag->vector0, &tag->vector0);
                tag->pitch11 = func_8004E880(func_8004EDE8(&tag->vector0, 0), tag->vector0.z, 0);
                tag->yaw12 = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                tag->timerC = 180;
                newMoby->unknown5 = 1;
                func_8003BABC(newMoby, 0, 0);
                return newMoby;
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            tag->timerC = 48;
            newMoby->size = 127;
            redWord = tag->timerC;
            newMoby->colour.r = redWord;
            greenWord = tag->timerC;
            newMoby->colour.g = greenWord;
            blueWord = tag->timerC;
            newMoby->colour.a = 63;
            newMoby->colour.b = blueWord;
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
    case 310:
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
                vector10.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                vector10.x = (short)vector10.x >> 4;
                vector10.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                vector10.y = (short)vector10.y >> 4;
                vector10.z = 0;
                mobyTag->linearVel.x += vector10.x;
                mobyTag->linearVel.y += vector10.y;
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
    case 467:
    case 504:
    case 648:
    case 748:
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
            azimuth = (spyro.bodyRotation.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius = 0x78;
            mobyTag->unk0.x = ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y = ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
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
            }
            else {
                mobyTag->unk0.x += (D_80065920[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[spyro.bodyRotation.yaw] * 0x23) >> 0xA;
            }
            newMoby->angle.roll = rand();
            newMoby->angle.pitch = rand();
            newMoby->angle.yaw = rand();
            newMoby->position.x += mobyTag->unk0.x*2;
            newMoby->position.y += mobyTag->unk0.y*2;
            newMoby->position.z += mobyTag->unk0.z*2;
            mobyTag->unk6.x = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z = (rand() & 0x1F) - 0x10;
            mobyTag->unkC = func_8003636C(90, 150);
            mobyTag->unkE = 1;
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
    case 503:
        {
            Vector3D* position = &newMoby->position;
            Spawn42Tag503* tag = newMoby->mobyTag;
            Vector3D* linkedPosition;
            int playerDistance, height, angle, linkedZ, playerZ, xWord, yWord;
            func_80055F14(linkedMoby, 4, position);
            linkedPosition = &linkedMoby->position;
            playerDistance = func_8004F334(linkedPosition, &spyro.position);
            if (playerDistance<func_8004F334(linkedPosition, position)) {
                linkedZ = linkedMoby->position.z;
                playerZ = spyro.position.z;
                height = linkedZ-playerZ;
                if (height >= 0) {
                    if (height<1024) goto redirect503;
                }
                else if (playerZ-linkedZ<1024) {
                redirect503:
                    angle = func_8004E880(linkedMoby->position.x-newMoby->position.x, linkedMoby->position.y-newMoby->position.y, 0);
                    xWord = D_80065920[angle];
                    newMoby->position.x = (xWord*16)>>8;
                    yWord = D_800658A0[angle];
                    newMoby->position.z = 0;
                    newMoby->position.y = (yWord*16)>>8;
                    func_8004F194(&newMoby->position, &newMoby->position, &spyro.position);
                }
            }
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055C24(newMoby);
            tag->vector0.x = 256;
            tag->vector0.y = 0;
            tag->vector0.z = 0;
            func_8004ED6C(&newMoby->rotationMatrix, &tag->vector0, &tag->vector0);
            tag->timerC = 120;
            tag->linked10 = linkedMoby;
            break;
        }
    case 529:
        {
            Moby** tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->state = 5;
            func_80034F80(newMoby, 5);
            func_80055C24(newMoby);
            *tag = linkedMoby;
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
