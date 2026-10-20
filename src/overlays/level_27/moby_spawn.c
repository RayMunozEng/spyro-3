#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_27_80083B34:
* SCUS-94467 USA Rev0, 1074 original words; original assembly SHA256
* e317087476d64f9a3d81ed4bed0d0e72d8916817a384ce69b4fedcccd27a8d3b.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Common and447/448 reuse accepted37 C. Original386/413/
* 989/990/992/994 retain signed selector adjustment, cursor7C/payload110,
* exact buffer lengths, tables and child loop counts. SP18/SP28 vectors
* stay distinct. Named386/992 union views share only offset0; this is a
* local raw-field adapter, not a complete game object contract.
* Original413 word467 uses s1 for the initialized copy pointer. A register
* constraint preserves that producer; an empty initialized-Moby boundary
* after55D24 preserves both original address calculations. The divisor180
* empty constraint retains the original DIV and exception guards rather
* than reciprocal lowering. No nonempty CPU assembly is used. Original
* duplicate byte stores are observable volatile accesses. All used type
* fields remain intact. Complete helper and frame contracts remain open.
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
    Vector3D vector0;
    short timerC, padE;
    unsigned char byte10, byte11, byte12, byte13;
    int word14;
}
Spawn37Tag447;
typedef struct {
    Vector3D16 vector0, vector6;
    unsigned char byteC, byteD;
    short wordE;
    int word10;
}
Spawn37Tag448;
#include "ovl_header.h"
extern unsigned char D_8006C409, D_8007158D;
extern int D_8006C7C4;
extern int D_8006EE2C[];
int func_8004F334(Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8003BB10(Moby*, int, int);
typedef struct {
    unsigned char pad0[0x7C];
    int cursor7C;
    unsigned char pad80[0x90];
    unsigned char arena110[1];
}
Spawn27ArenaOwner;
typedef struct {
    Vector3D* buffer0;
    int word4, word8, wordC;
    Moby* parent10;
    short timer14, word16;
}
Spawn27Tag386;
typedef struct {
    Moby* parent0;
    int timer4, word8;
    unsigned char byteC, byteD, byteE, yawF;
    int word10;
}
Spawn27Tag413;
typedef struct {
    Vector3D vector0, vectorC;
    int radius18, word1C;
    Vector3D vector20;
    unsigned char byte2C, byte2D, byte2E, byte2F;
    int word30;
    Moby* children34[7];
}
Spawn27Arena992;
typedef struct {
    Spawn27Arena992* buffer0;
    Moby* source4;
    Moby* parent8;
    int wordC, timer10, word14;
}
Spawn27Tag992;
typedef struct {
    int timer0;
    void* buffer4;
    Moby* parent8;
    int wordC, word10, word14;
}
Spawn27Tag994;
typedef union {
    Spawn27Tag386 spawn386;
    Spawn27Tag992 spawn992;
}
Spawn27ArenaTag;
Moby* func_level_27_80083B34(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Spawn27ArenaTag* arenaTag;
    Vector3D vector18;
    Vector3D vector28;
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
                vector18.x = (D_80065920[yaw] * 0x7D) >> 9;
                vector18.y = (D_800658A0[yaw] * 0x7D) >> 9;
                vector18.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &vector18);
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
    case 386:
        {
            int selector = D_8006C409;
            int allocationSize = 0x1DC4;
            Vector3D* position;
            Spawn27ArenaOwner* owner;
            arenaTag = newMoby->mobyTag;
            if (D_8006C7C4==2) {
                selector-=4;
                if (selector<0) selector = 0;
            }
            else if (D_8006C7C4==1) selector += 2;
            else if (D_8006C7C4==0) selector += 5;
            if (D_8007158D) selector = 0;
            func_80055D24(linkedMoby, 4);
            position = &newMoby->position;
            func_80055F14(linkedMoby, 12, position);
            func_80055C24(newMoby);
            newMoby->updateDistance = 255;
            *(volatile unsigned char*)&newMoby->lowDrawDistance = 0;
            newMoby->lowDrawDistance = 127;
            newMoby->highDrawDistance = 63;
            newMoby->size = 64;
            newMoby->drawn = 0;
            arenaTag->spawn386.parent10 = linkedMoby;
            arenaTag->spawn386.word16 = 8;
            owner = linkedMoby->mobyTag;
            if (owner->cursor7C+allocationSize>0x9C3F) owner->cursor7C = 0;
            arenaTag->spawn386.buffer0 = (Vector3D*)((unsigned char*)owner+(owner->cursor7C+0x110));
            owner->cursor7C += allocationSize;
            func_8004E790(arenaTag->spawn386.buffer0, 0, allocationSize);
            func_8004F178(position, &spyro.position);
            func_80055C24(newMoby);
            func_8004F178(arenaTag->spawn386.buffer0, &spyro.position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->angle.roll = 0;
            newMoby->angle.pitch = 0;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            arenaTag->spawn386.timer14 = 300;
            if (selector <= 0) arenaTag->spawn386.timer14 = 420;
            else if (selector >= 6) arenaTag->spawn386.timer14 = 210;
            break;
        }
    case 413:
        {
            Spawn27Tag413* tag = newMoby->mobyTag;
            register Vector3D* position __asm__("$17") = &newMoby->position;
            if (linkedMoby->mobyClass!=newMoby->mobyClass) {
                Vector3D* sourcePosition;
                Vector3D* playerPosition;
                int distanceScale;
                int divisor;
                int yaw;
                int i;
                func_80055D24(linkedMoby, 4);
                __asm__("" : " = r"(newMoby) : "0"(newMoby));
                sourcePosition = &newMoby->position;
                func_80055F14(linkedMoby, 12, sourcePosition);
                func_80055C24(newMoby);
                func_80034F80(newMoby, 1);
                newMoby->updateDistance = 255;
                newMoby->lowDrawDistance = 127;
                func_80035EE0(newMoby, linkedMoby->angle.yaw, 1024, 0, 0, 0);
                distanceScale = func_8004F334(sourcePosition, &spyro.position);
                divisor = 180;
                __asm__("" : " = r"(divisor) : "0"(divisor));
                distanceScale/=divisor;
                playerPosition = &spyro.position;
                func_8004F178(&vector18, (Vector3D*)((unsigned char*)playerPosition+0x98));
                distanceScale/=2;
                vector18.x*=distanceScale;
                vector18.y*=distanceScale;
                vector18.z*=distanceScale;
                func_8004F110(&vector18, 6);
                func_8004F194(&vector18, &vector18, playerPosition);
                tag->yawF = func_8004E880(vector18.x-newMoby->position.x, vector18.y-newMoby->position.y, 0);
                yaw = func_8004E880(playerPosition->x-newMoby->position.x, playerPosition->y-newMoby->position.y, 0);
                if (func_8004F264(yaw, tag->yawF) >= 65) tag->yawF = yaw;
                newMoby->angle.yaw = ((short)camera.unk48>>4)-128;
                newMoby->angle.pitch = (unsigned short)camera.unk46>>4;
                i = 0;
                do {
                    SpawnMoby(413, newMoby);
                    i++;
                }
                while (i<12);
                func_8003BB10(newMoby, 3, 0);
                tag->byteC = 1;
            }
            else {
                Vector3D* linkedPosition = &linkedMoby->position;
                int animation;
                func_8004F178(position, linkedPosition);
                func_80055C24(newMoby);
                newMoby->updateDistance = 255;
                newMoby->lowDrawDistance = 127;
                newMoby->unknown4 = 0;
                animation = rand()%**(unsigned char**)(D_8006EE2C[newMoby->mobyClass]+0x3C);
                newMoby->animationState.frame = animation;
                newMoby->animationState.nextFrame = ((animation&255)+1)%**(unsigned char**)(D_8006EE2C[newMoby->mobyClass]+0x3C);
                newMoby->angle.pitch = rand();
                newMoby->angle.yaw = rand();
                tag->byteD = (rand()&15)-8;
                tag->byteE = (rand()&15)-8;
                func_80055D24(newMoby, 4);
                func_80055F14(newMoby, 0, &vector28);
                func_8004F1C8(&vector28, position, &vector28);
                func_8004F194(position, linkedPosition, &vector28);
            }
            tag->parent0 = linkedMoby;
            tag->timer4 = 300;
            break;
        }
    case 447:
        {
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
    case 448:
        {
            Spawn37Tag448* tag = newMoby->mobyTag;
            int azimuth, elevation, vertical;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            azimuth = rand()&4095;
            elevation = func_8003636C(300, 2048);
            tag->vector0.x = (func_8004EA2C(elevation)>>5)*(func_8004EA2C(azimuth)>>12);
            tag->vector0.y = (func_8004EA2C(elevation)>>5)*(func_8004E9E4(azimuth)>>12);
            vertical = func_8004E9E4(elevation)>>5;
            tag->vector0.z = vertical;
            if ((short)vertical<32) tag->vector0.z = 32;
            tag->vector0.z += 32;
            newMoby->angle.yaw = rand();
            if ((rand()&255) >= 129) {
                newMoby->angle.pitch = (rand()&28)-16;
                tag->word10 = 1;
                if (tag->vector0.z >= 33) tag->vector0.z = 32;
            }
            newMoby->position.x += tag->vector0.x*4;
            newMoby->position.y += tag->vector0.y*4;
            newMoby->position.z += tag->vector0.z*4;
            tag->vector6.x = (rand()&31)-16;
            tag->vector6.y = (rand()&31)-16;
            tag->vector6.z = (rand()&31)-16;
            {
                unsigned char timer = 50-func_8003636C(0, 20);
                tag->byteD = 8;
                tag->byteC = timer;
            }
            tag->wordE = 4;
            break;
        }
    case 989:
        {
            int* tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &spyro.position);
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            *tag = 180;
            break;
        }
    case 990:
        {
            int* tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055D10(newMoby);
            newMoby->updateDistance = 255;
            *(volatile unsigned char*)&newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->unknown3[0] = 0;
            *tag = 90;
            break;
        }
    case 992:
        {
            int selector = D_8006C409;
            int allocationSize = 0x278;
            Moby* source;
            Spawn27ArenaOwner* owner;
            Spawn27Arena992* buffer;
            int angle, yWord, yProduct;
            int randomStep;
            int i;
            arenaTag = newMoby->mobyTag;
            if (D_8006C7C4==2) {
                selector-=4;
                if (selector<0) selector = 0;
            }
            else if (D_8006C7C4==1) selector += 2;
            else if (D_8006C7C4==0) selector += 5;
            if (D_8007158D) selector = 0;
            source = linkedMoby;
            if (linkedMoby->mobyClass!=351) source = ((Spawn27Tag992*)linkedMoby->mobyTag)->source4;
            owner = source->mobyTag;
            func_8004F178(&newMoby->position, &source->position);
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->updateDistance = 255;
            newMoby->angle.yaw = source->angle.yaw;
            if (owner->cursor7C+allocationSize>0x9C40) owner->cursor7C = 0;
            arenaTag->spawn992.buffer0 = (Spawn27Arena992*)((unsigned char*)owner+(owner->cursor7C+0x110));
            owner->cursor7C += allocationSize;
            func_8004E790(arenaTag->spawn992.buffer0, 0, allocationSize);
            buffer = arenaTag->spawn992.buffer0;
            buffer->vector0.x = 0x9400;
            buffer->vector0.y = 0x9400;
            buffer->vector0.z = 0x1400;
            buffer->radius18 = 0x3400;
            angle = func_8004E880(newMoby->position.x-buffer->vector0.x, newMoby->position.y-buffer->vector0.y, 0);
            buffer->vectorC.x = D_80065920[angle]*2;
            yWord = D_800658A0[angle];
            buffer->vectorC.z = 0;
            buffer->word1C = 0x1000;
            buffer->vectorC.y = yWord*2;
            buffer->byte2C = rand();
            if (rand()&4) buffer->byte2D = 1;
            else buffer->byte2D = 255;
            buffer->byte2E = rand();
            randomStep = rand();
            if (randomStep&4) buffer->byte2F = 16;
            else buffer->byte2F = 240;
            buffer->vector20.x = (D_80065920[buffer->byte2C]*buffer->radius18)>>12;
            yProduct = D_800658A0[buffer->byte2C]*buffer->radius18;
            buffer->vector20.z = 0;
            buffer->vector20.y = yProduct>>12;
            func_8004F194(&buffer->vector20, &buffer->vector20, &buffer->vector0);
            arenaTag->spawn992.timer10 = 360;
            if (selector <= 0) arenaTag->spawn992.timer10 = 480;
            else if (selector >= 6) arenaTag->spawn992.timer10 = 270;
            arenaTag->spawn992.source4 = source;
            i = 0;
            if (linkedMoby->mobyClass==351) {
                arenaTag->spawn992.parent8 = 0;
                do {
                    buffer->children34[0] = SpawnMoby(992, newMoby);
                    i++;
                    buffer = (Spawn27Arena992*)((unsigned char*)buffer+4);
                }
                while (i<7);
            }
            else arenaTag->spawn992.parent8 = linkedMoby;
            break;
        }
    case 994:
        {
            Spawn27ArenaOwner* owner = linkedMoby->mobyTag;
            Spawn27Tag994* tag = newMoby->mobyTag;
            int allocationSize = 0x12C8;
            func_80055D24(linkedMoby, 4);
            func_80055F14(linkedMoby, 12, &newMoby->position);
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->updateDistance = 255;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->position.z = linkedMoby->position.z+500;
            if (owner->cursor7C+allocationSize>0x9C40) owner->cursor7C = 0;
            tag->buffer4 = (unsigned char*)owner+(owner->cursor7C+0x110);
            owner->cursor7C += allocationSize;
            func_8004E790(tag->buffer4, 0, allocationSize);
            tag->timer0 = 500;
            tag->parent8 = linkedMoby;
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
