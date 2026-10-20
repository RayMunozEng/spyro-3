#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_23_8008B7B0:
* SCUS-94467 USA Rev0, 844 original words; original assembly SHA256
* a3f2f1405207ce00bee09e1526e6e8dd1cff1e627d287ce1f46234978aa5c038.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Level22 class29 keeps the common class84 body; SP10 is class90
* work and SP20 common work. Its dispatch excludes310. Level23 classes8/84
* share common C. The1000/1015 tag views preserve byte offsets and original
* buffer counts/ring update; they do not assert complete object layouts.
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
typedef struct {
    Vector3D16 unk0;
    Vector3D16 unk6;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
}
Spawn14Tag84;
typedef struct {
    short unk0;
    short unk2;
    void* unk4;
    int unk8;
    int unkC;
    Moby* unk10;
}
Spawn14Tag1015;
typedef struct {
    int word0, word4, word8;
    unsigned char byteC;
    unsigned char padD[3];
    int word10;
}
Spawn23Tag80;
typedef struct {
    short word0, word2;
    void* buffer4;
    int word8, wordC;
    Moby* linked10;
    short word14, word16;
}
Spawn23Tag1000;
Moby* func_level_23_8008B7B0(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    Vector3D v;
    newMoby  =  func_80055A7C();
    if (newMoby == 0) return 0;
    newMobyTag  =  newMoby->mobyTag;
    func_8004E790(newMoby, 0, 0x58);
    newMoby->mobyTag  =  newMobyTag;
    func_8004E790(newMobyTag, 0, 0x18);
    newMoby->mobyClass  =  mobyClass;
    if (linkedMoby != 0) {
        if (linkedMoby - mobyArrayPtr < 0x100U) {
            newMoby->linkedMoby  =  linkedMoby - mobyArrayPtr;
        }
        else {
            newMoby->linkedMoby  =  0xFF;
        }
    }
    else {
        newMoby->linkedMoby  =  0xFF;
    }
    func_80034FEC(newMoby);
    switch (mobyClass) {
    case 1:
        func_80055C24(newMoby);
        newMoby->lowDrawDistance  =  0x18;
        newMoby->updateDistance  =  0x40;
        newMoby->unknown  =  -1;
        break;
    case 8:
    case 84:
        {
            Spawn14Tag84* mobyTag;
            int elevation;
            int azimuth;
            int radius;
            int radius2;
            mobyTag  =  newMoby->mobyTag;
            newMoby->lowDrawDistance  =  0x20;
            newMoby->highDrawDistance  =  0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            elevation  =  func_8003636C(0x12C, 0x834);
            azimuth  =  (linkedMoby->angle.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius  =  0x78;
            mobyTag->unk0.x  =  ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y  =  ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2  =  0x96;
            mobyTag->unk0.z  =   (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.z += func_8003636C(0x28, 0x46);
            }
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x37) >> 0xA;
            }
            else {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x23) >> 0xA;
            }
            if ((newMoby->mobyClass != 10) && (newMoby->mobyClass != 29)) {
                newMoby->angle.roll   =  rand();
                newMoby->angle.pitch  =  rand();
                newMoby->angle.yaw    =  rand();
                newMoby->position.x += mobyTag->unk0.x * 2;
                newMoby->position.y += mobyTag->unk0.y * 2;
                newMoby->position.z += mobyTag->unk0.z * 2;
            }
            else {
                newMoby->angle.roll   =  linkedMoby->angle.roll;
                newMoby->angle.pitch  =  linkedMoby->angle.pitch;
                newMoby->angle.yaw    =  linkedMoby->angle.yaw;
            }
            mobyTag->unk6.x  =  (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y  =  (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z  =  (rand() & 0x1F) - 0x10;
            mobyTag->unkC  =  func_8003636C(0x78, 0x96);
            mobyTag->unkE  =  1;
            mobyTag->unk12  =  0;
            break;
        }
    case 80:
        {
            Spawn23Tag80* tag = newMoby->mobyTag;
            if (linkedMoby) func_8004F178(&newMoby->position, &linkedMoby->position);
            else func_8004F178(&newMoby->position, &spyro.position);
            func_80055C24(newMoby);
            tag->word10 = -1;
            tag->byteC = 6;
            break;
        }
    case 16:
    case 211:
        {
            MobyTag_16* mobyTag;
            int extraLifeThreshold;
            mobyTag  =  newMoby->mobyTag;
            if (newMoby->mobyClass == 0x10) {
                extraLifeThreshold  =  10;
                if (D_8006C784 < 4)      extraLifeThreshold  =  7;
                else if (D_8006C784 < 7) extraLifeThreshold  =  9;
                sparx.butterflyCount++;
                if (sparx.butterflyCount >= extraLifeThreshold) {
                    sparx.butterflyCount  =  0;
                    newMoby->mobyClass  =  0xD3;
                }
            }
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            newMoby->position.z += 0x200;
            func_8004F178(&mobyTag->unk0, &newMoby->position);
            newMoby->unknown  =  -1;
            newMoby->unknown4  =  2;
            mobyTag->unkE  =  0x708;
            mobyTag->unk11  =  0;
            mobyTag->unk12  =  (char) (rand() & 0xFC);
            break;
        }
    case 120:
        {
            MobyTag_120* mobyTag;
            char yaw;
            if (linkedMoby->mobyClass != mobyClass) {
                newMoby->mobyTag  =  &D_8006E394;
                func_8004E790(&D_8006E394, 0, 0x1C);
            }
            mobyTag  =  newMoby->mobyTag;
            func_80055C24(newMoby);
            newMoby->substate  =  0;
            mobyTag->unk0  =  0;
            mobyTag->unk8  =  0;
            mobyTag->unk6  =  0;
            mobyTag->unk4  =  0;
            mobyTag->unkD  =  0x78;
            mobyTag->unk10  =  0;
            mobyTag->unk14  =  0;
            if (linkedMoby != 0) {
                func_8004F178(&newMoby->position, &linkedMoby->position);
            }
            else {
                yaw  =  spyro.bodyRotation.yaw - 0x80;
                v.x  =  (D_80065920[yaw] * 0x7D) >> 9;
                v.y  =  (D_800658A0[yaw] * 0x7D) >> 9;
                v.z  =  0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &v);
            }
            mobyTag->unk2  =  0xFF;
            break;
        }
    case 132:
        {
            int ground;
            newMoby->angle.yaw  =  linkedMoby->angle.yaw;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            ground  =  func_80035D38(newMoby);
            if (ground) newMoby->position.z  =  ground;
            newMoby->state  =  6;
            break;
        }
    case 260:
        func_80055C24(newMoby);
        newMoby->colour.r  =  2;
        if (linkedMoby != 0) {
            ((MobyTag_260*)newMoby->mobyTag)->unk0  =  linkedMoby;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->updateDistance  =  10;
            newMoby->lowDrawDistance  =  8;
            newMoby->position.z += 0x400;
        }
        else {
            newMoby->unknown  =  -1;
        }
        break;
    case 272:
        {
            MobyTag_272* mobyTag;
            mobyTag  =  newMoby->mobyTag;
            func_8004F178(&newMoby->position, &spyro.position);
            newMoby->position.z += 0x400;
            newMoby->angle.yaw  =  spyro.bodyRotation.yaw;
            func_80055C24(newMoby);
            mobyTag->unk2  =  2;
            mobyTag->unk3  =  spyro.bodyRotation.yaw;
            mobyTag->unk4  =  spyro.bodyRotation.yaw;
            mobyTag->unk10  =  -1;
            newMoby->unknown3[0]  =  0;
            newMoby->lowDrawDistance  =  0;
            newMoby->drawn  =  0;
            break;
        }
    case 306:
    case 307:
    case 308:
        {
            MobyTag_Fragment* mobyTag;
            int azimuth;
            int elevation;
            mobyTag  =  newMoby->mobyTag;
            newMoby->lowDrawDistance  =  0x20;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            func_80055C24(newMoby);
            azimuth  =  rand() & 0xFFF;
            elevation  =  rand() & 0x7FF;
            mobyTag->linearVel.x  =  (func_8004EA2C(elevation) * func_8004EA2C(azimuth) * linkedMoby->substate) >> 0x18;
            mobyTag->linearVel.y  =  (func_8004EA2C(elevation) * func_8004E9E4(azimuth) * linkedMoby->substate) >> 0x18;
            mobyTag->linearVel.z  =  (func_8004E9E4(elevation) * linkedMoby->substate) >> 0xC;
            if (linkedMoby->damageFlags & 0x02000000) {
                v.x  =  D_80065920[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                v.x  =  (short)v.x >> 4;
                v.y  =  D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
                v.y  =  (short)v.y >> 4;
                v.z  =  0;
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
            newMoby->angle.pitch  =  rand();
            newMoby->angle.yaw  =  rand();
            mobyTag->angularVel.x  =  (rand() & 0x1F) - 0x10;
            mobyTag->angularVel.y  =  (rand() & 0x1F) - 0x10;
            mobyTag->angularVel.z  =  (rand() & 0x1F) - 0x10;
            mobyTag->unk10  =  linkedMoby->position.z - 0x40;
            mobyTag->timer  =  func_8003636C(0x32, 0x50);
            break;
        }
    case 1000:
        {
            Spawn23Tag1000* tag = newMoby->mobyTag;
            int link;
            Moby* arenaMoby;
            int* arena;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->updateDistance = 255;
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->position.z += 256;
            link = ((int*)linkedMoby->mobyTag)[4];
            if (link >= 0) {
                arenaMoby = &mobyArrayPtr[link];
                arena = arenaMoby->mobyTag;
                tag->buffer4 = (char*)arena+(*arena+0x14);
                *arena += 0xEB0;
                if (*arena >= 0x2C10) *arena = 0;
                func_8004E7AC(tag->buffer4, 0, 0xEB0);
                tag->word0 = 32;
                tag->word2 = 25;
                tag->word14 = 15;
                tag->word16 = 30;
                tag->linked10 = arenaMoby;
            }
            break;
        }
    case 1015:
        {
            Spawn14Tag1015* tag = newMoby->mobyTag;
            int link;
            Moby* arenaMoby;
            void* buffer;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            newMoby->state = linkedMoby->substate;
            newMoby->updateDistance = 255;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            newMoby->position.z += 256;
            link = ((int*)linkedMoby->mobyTag)[5];
            if (link >= 0) {
                arenaMoby = &mobyArrayPtr[link];
                buffer = (char*)arenaMoby->mobyTag+0x14;
                tag->unk4 = buffer;
                func_8004E7AC(buffer, 0, 0x9C0);
                tag->unk0 = 200;
                tag->unk2 = 200;
                tag->unk10 = arenaMoby;
            }
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
