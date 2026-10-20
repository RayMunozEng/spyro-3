#include "common.h"

/**
 * MobySpawn_Level10() - func_level_10_8008368C() - MATCHING
 * Ready to implement, but review the struct updates and put the macros somewhere in common maybe
 * https://decomp.me/scratch/PGLtI
 */
/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: upstream-linked https://decomp.me/scratch/PGLtI,
* exported source SHA256 96ef5ed525659c449b0db3718378ce7d10b19b2df32f6955d910d1a68602425a.
* Attribution: Strong Sandpiper (anon), public scratch. Repository type-name
* adapters, local names, formatting and this provenance note are AI generated
* and not human reviewed. Original SCUS-94467 USA Rev0 entry 8008368C:
* 618 instruction words; source SHA256
* 2ae7d8fe67ae459b53e834dce2679a6142d9807d71ac94bd87aa9b516c17b778.
* Scratch target words equal the original. Acceptance requires every native
* and linked word/target plus full EXE and every-overlay retail hashes.
* Local tags expose observed byte offsets; their object meanings remain
* unresolved. Arithmetic retains original word/halfword/byte widths, shifts,
* masks and signed divisions. Physical units and full fixed-point domains
* remain unresolved. Cadence is per invocation; frame timing, helper/asset/SFX
* chains and synchronized runtime verification remain open. This establishes
* binary identity only, with no engine/browser or subsystem completion claim.
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
// MobyTag_Fragment updated
typedef struct {
    int unk0;
    int unk4;
    void* unk8;
}
Spawn10Tag427;
typedef struct {
    int unk0;
    int unk4;
}
Spawn10Tag426;
typedef struct {
    Moby* unk0;
    int unk4;
}
Spawn10Tag486;
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
}
Spawn10Tag514;
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
}
Spawn10Tag54View;
int func_8004E9E4(int);
int func_8004EA2C(int);
void* func_80050844(Vector3D*, char, int, int);
Moby* func_level_10_8008368C(int mobyClass, Moby* linkedMoby) {
    Vector3D vector;
    int y;
    Moby* newMoby;
    Vector3D* newPosition;
    Vector3D* copyDestination;
    Vector3D* copySource;
    int randomAngleB;
    int randomAngleA;
    int helperReturn;
    char yawByte;
    int threshold;
    char temp_v1_4;
    Spawn10Tag486* tag486;
    void* newTag;
    MobyTag_120* tag120;
    Spawn10Tag427* tag427;
    Spawn10Tag426* tag426;
    MobyTag_272* tag272;
    MobyTag_16* tag16;
    Spawn10Tag54View* linkedTag54A;
    Spawn10Tag54View* linkedTag54B;
    MobyTag_Fragment* fragmentTag;
    newMoby = func_80055A7C();
    if (newMoby == 0) return 0;
    newTag = newMoby->mobyTag;
    func_8004E790(newMoby, 0, 0x58);
    newMoby->mobyTag = newTag;
    func_8004E790(newTag, 0, 0x18);
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
            if (D_8006C784 < 4)      threshold = 7;
            else if (D_8006C784 < 7) threshold = 9;
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
        tag16->unk12 = (char) (rand() & 0xFC);
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
        }
        else {
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
    case 0x104:
        func_80055C24(newMoby);
        newMoby->colour.r = 2;
        if (linkedMoby != 0) {
            ((MobyTag_260*)newMoby->mobyTag)->unk0 = linkedMoby;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->updateDistance = 0xA;
            newMoby->lowDrawDistance = 8;
            newMoby->position.z += 0x400;
        }
        else {
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
    case 0x133:
    case 0x136:
    case 0x238:
        fragmentTag = newMoby->mobyTag;
        newMoby->lowDrawDistance = 0x20;
        func_8004F178(&newMoby->position, &linkedMoby->position);
        func_80055C24(newMoby);
        randomAngleA = rand() & 0xFFF;
        randomAngleB = rand() & 0x7FF;
        fragmentTag->linearVel.x = (func_8004EA2C(randomAngleB) * func_8004EA2C(randomAngleA) * linkedMoby->substate) >> 0x18;
        fragmentTag->linearVel.y = (func_8004EA2C(randomAngleB) * func_8004E9E4(randomAngleA) * linkedMoby->substate) >> 0x18;
        fragmentTag->linearVel.z = (func_8004E9E4(randomAngleB) * linkedMoby->substate) >> 0xC;
        if (linkedMoby->damageFlags & 0x02000000) {
            vector.x = D_80065920[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
            vector.x = (short)vector.x >> 4;
            vector.y = D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x, newMoby->position.y - spyro.position.y, 0)];
            vector.y = (short)vector.y >> 4;
            vector.z = 0;
            fragmentTag->linearVel.x += vector.x;
            fragmentTag->linearVel.y += vector.y;
        }
        else if ((linkedMoby->damageFlags & 0x20000) && ((spyro.movementState == 4) || (spyro.movementState == 0xC))) {
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
    case 0x1AA:
        tag426 = newMoby->mobyTag;
        linkedTag54A = linkedMoby->mobyTag;
        func_8004F178(&newMoby->position, &linkedMoby->position);
        newMoby->angle.pitch = 0x20;
        func_80055C24(newMoby);
        tag426->unk0 = 0;
        tag426->unk4 = (int) linkedTag54A->unk54;
        newMoby->lowDrawDistance = 0;
        newMoby->drawn = 0;
        break;
    case 0x1AB:
        newPosition = &newMoby->position;
        tag427 = newMoby->mobyTag;
        linkedTag54B = linkedMoby->mobyTag;
        func_8004F178(newPosition, &linkedMoby->position);
        newMoby->angle.pitch = rand();
        newMoby->angle.yaw = rand();
        func_80055C24(newMoby);
        tag427->unk0 = 0;
        tag427->unk4 = linkedTag54B->unk54;
        tag427->unk8 = func_80050844(newPosition, 6, 6, 0xFFFFFF);
        break;
    case 0x1E6:
        tag486 = newMoby->mobyTag;
        tag486->unk4 = (((Spawn10Tag514*)linkedMoby->mobyTag)->unk4 << 8) / 5;
        tag486->unk0 = linkedMoby;
        y = (tag486->unk4 + linkedMoby->angle.yaw) & 0xFF;
        newMoby->angle.yaw = y;
        newMoby->position.x = (D_80065920[y] * 187) >> 10;
        newMoby->position.y = (D_800658A0[y] * 187) >> 10;
        newMoby->position.z = 0x29A;
        func_8004F194(&newMoby->position, &newMoby->position, &linkedMoby->position);
        func_80055C24(newMoby);
        break;
    default:
        if (linkedMoby != 0) {
            copyDestination = &newMoby->position;
            copySource = &linkedMoby->position;
        }
        else {
            copyDestination = &newMoby->position;
            copySource = &spyro.position;
        }
        func_8004F178(copyDestination, copySource);
        func_80055C24(newMoby);
        break;
    }
    return newMoby;
}
