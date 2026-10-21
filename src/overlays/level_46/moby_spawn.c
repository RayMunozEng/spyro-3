#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_46_8008812C:
* SCUS-94467 USA Rev0, 1422 original words; original assembly SHA256
* 263e383f5f823a4bebb6a7e39fb94ce8c885728306e91549733cbfbf699d13b4.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Existing43/44 class197, credited84/common/fragments and35
* class92 are reused. Original197 fallback5,102 helper selector1 and fragment
* selectors306/308/630/631 remain exact. Observed frame B0/save88 and all
* SP10/20/30/40/58 object fields/padding stay intact. Only whole unused type
* views may be pruned; stack fields must never be mistaken for unused locals.
* New245 preserves original signed table/address producers, calls and packed
* color SW constants. Original960 converts0..255 index to0..510 byte offset.
* Signed16*16>>8 equals signed16>>4; intermediate[-524288,524272] fits32 bits.
* Vectors -32768:-2048,-1:-1,0:0,15:0,16:1,32767:2047. No physical conversion
* is inferred. No additional table alias is needed. Class1000 uses linked
* tag70;1005 uses original1020/13A0 scan, payload14 and9D0 ring bound owner8.
* Empty initialized/dead-register constraints preserve original index s0,
* cosine a0 and size s2 producers; cached scan endpoint remains ordinary C.
* Full helper/table/asset/units/frame contracts remain open. No nonempty
* CPU instruction assembly or acceptance change is used.
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
#include "ovl_header.h"
extern int D_8006C5BC;
extern unsigned char D_80071A04;
extern CollisionData D_80071900;
int func_8004EDE8(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004ECF4(SHORTMATRIX*, void*);
void func_80034F80(Moby*, int);
typedef struct {
    Vector3D vector0;
    short wordC;
    unsigned char byteE, padF;
    short timer10, pad12;
    Moby* child14;
} Spawn46Tag197;
static __inline__ int Spawn46LinkIndex(int byteOffset) {
    return (int)(0U - (unsigned int)byteOffset * 0x45D1745DU) >> 3;
}
typedef struct {
    short word0, word2;
    int* buffer4;
    int word8, wordC;
    Moby* parent10;
    short word14, word16;
} Spawn46Tag1000;
typedef struct {
    Vector3D unk0;
    int unkC;
    int unk10;
} Spawn46Tag92;
typedef struct {
    Vector3D vector0;
    int timerC, word10, word14;
} Spawn46Tag245;
void func_8004F110(Vector3D*, int);
Moby* func_level_46_8008812C(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    struct {
        Vector3D vector10;
        int gap1C;
        Vector3D vector20;
        int gap2C;
        Vector3D vector30;
        int gap3C;
        union {
            SHORTMATRIX matrix;
            Vector3D vector;
        } work40;
        int gap54;
        SHORTMATRIX matrix58;
        int gap6C;
        int gap70[6];
    } frame;
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
        case 84: {
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
            azimuth = (linkedMoby->angle.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius = 0x78;
            mobyTag->unk0.x =
                ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y =
                ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
            radius2 = 0x96;
            mobyTag->unk0.z = (func_8004E9E4(elevation) * radius2) >> 0xC;
            if ((linkedMoby->unkb) && (linkedMoby->damageFlags & 0x100000)) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->unkb] * 0x4B) >> 0xB;
                mobyTag->unk0.z += func_8003636C(0x28, 0x46);
            }
            if (linkedMoby->damageFlags & 0x20000) {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x37) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x37) >> 0xA;
            } else {
                mobyTag->unk0.x += (D_80065920[linkedMoby->angle.yaw] * 0x23) >> 0xA;
                mobyTag->unk0.y += (D_800658A0[linkedMoby->angle.yaw] * 0x23) >> 0xA;
            }
            if ((newMoby->mobyClass != 10) && (newMoby->mobyClass != 29)) {
                newMoby->angle.roll = rand();
                newMoby->angle.pitch = rand();
                newMoby->angle.yaw = rand();
                newMoby->position.x += mobyTag->unk0.x * 2;
                newMoby->position.y += mobyTag->unk0.y * 2;
                newMoby->position.z += mobyTag->unk0.z * 2;
            } else {
                newMoby->angle.roll = linkedMoby->angle.roll;
                newMoby->angle.pitch = linkedMoby->angle.pitch;
                newMoby->angle.yaw = linkedMoby->angle.yaw;
            }
            mobyTag->unk6.x = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.y = (rand() & 0x1F) - 0x10;
            mobyTag->unk6.z = (rand() & 0x1F) - 0x10;
            mobyTag->unkC = func_8003636C(0x78, 0x96);
            mobyTag->unkE = 1;
            mobyTag->unk12 = 0;
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
        case 92: {
            Spawn46Tag92* tag = newMoby->mobyTag;
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
        case 102:
            newMoby->angle.roll = linkedMoby->angle.roll;
            newMoby->angle.pitch = linkedMoby->angle.pitch;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055F14(linkedMoby, 1, &newMoby->position);
            func_80055C24(newMoby);
            newMoby->state = 0;
            newMoby->unknown4 = 3;
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
                frame.vector10.x = (D_80065920[yaw] * 0x7D) >> 9;
                frame.vector10.y = (D_800658A0[yaw] * 0x7D) >> 9;
                frame.vector10.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &frame.vector10);
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
        case 197: {
            Spawn46Tag197* tag = newMoby->mobyTag;
            register Moby* child __asm__("$17");
            if (linkedMoby && linkedMoby->mobyClass != mobyClass) {
                if (linkedMoby->mobyClass == 99 &&
                    (camera.cameraState == 31 || camera.cameraState == 40)) {
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    if (camera.cameraState == 40)
                        newMoby->position.z -= 128;
                    func_8004F178(&frame.vector20, &newMoby->position);
                } else {
                    func_80055D24(linkedMoby, 5);
                    func_80055F14(linkedMoby, 0, &frame.vector20);
                    frame.vector10.x = 600;
                    frame.vector10.y = 0;
                    frame.vector10.z = 0;
                    func_8004ED6C(&linkedMoby->rotationMatrix, &frame.vector10, &frame.vector10);
                    func_8004F194(&newMoby->position, &frame.vector20, &frame.vector10);
                }
            } else
                func_8004F178(&newMoby->position, &spyro.position);
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 40;
            newMoby->updateDistance = 255;
            if (linkedMoby) {
                if (linkedMoby->mobyClass == 197) {
                    unsigned int link = linkedMoby->linkedMoby;
                    if (link < 255) {
                        register unsigned int byteOffset __asm__("$4") = link * 0x58;
                        __asm__("" : " = r"(byteOffset) : "0"(byteOffset));
                        newMoby->linkedMoby = Spawn46LinkIndex(byteOffset);
                    }
                }
                if (linkedMoby && linkedMoby->mobyClass != 197) {
                    int roll, pitch, yaw;
                    register int alpha __asm__("$2");
                    unsigned short pitchWord;
                    func_8003BABC(newMoby, 0, 0);
                    newMoby->size = 60;
                    tag->timer10 = 300;
                    tag->wordC = 600;
                    tag->vector0.x = 600;
                    tag->vector0.y = 0;
                    tag->vector0.z = 0;
                    newMoby->colour.r = 255;
                    newMoby->colour.g = 255;
                    newMoby->colour.b = 255;
                    newMoby->colour.a = 63;
                    if (linkedMoby->mobyClass == 99) {
                        if (D_8006C5BC == 44 && D_80071A04) {
                            Moby* candidate;
                            Vector3D* position;
                            Vector3D* workVector;
                            for (candidate = mobyArrayPtr; candidate < D_8006C704; candidate++) {
                                if (candidate->mobyClass == 962)
                                    break;
                            }
                            workVector = &frame.vector30;
                            func_8004F178(workVector,
                                          (Vector3D*)((unsigned char*)candidate->mobyTag + 0x1C));
                            child = 0;
                            position = &newMoby->position;
                            newMoby->position.z -= 256;
                            tag->wordC = 4096;
                            newMoby->state = 0;
                            newMoby->angle.roll = (unsigned short)camera.unk44 >> 4;
                            newMoby->angle.pitch = -(int)camera.unk46 >> 4;
                            newMoby->angle.yaw = (unsigned short)camera.unk48 >> 4;
                            if (func_80013E38(position, workVector, 0))
                                func_8004F1C8(workVector, workVector, position);
                            else
                                func_8004F1C8(workVector, &D_80071900.D_80071900, position);
                            func_8004F08C(workVector, func_8004EDE8(workVector, 1), tag->wordC);
                            func_8004F178(&tag->vector0, workVector);
                            newMoby->angle.pitch =
                                func_8004E880(func_8004EDE8(&tag->vector0, 1), tag->vector0.z, 0);
                            newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                        } else if (linkedMoby->mobyClass == 99) {
                            SHORTMATRIX* matrix;
                            int* modePointer;
                            int vectorX;
                            unsigned short yawWord;
                            modePointer = &camera.cameraState;
                            if (*modePointer == 40) {
                                vectorX = 600;
                                matrix = &frame.work40.matrix;
                                goto cameraMatrix197;
                            }
                            if (*modePointer == 31) {
                                tag->wordC = 4096;
                                vectorX = 4096;
                                matrix = &frame.matrix58;
                            cameraMatrix197:
                                tag->vector0.x = vectorX;
                                newMoby->state = 0;
                                newMoby->angle.roll = (unsigned short)camera.unk44 >> 4;
                                newMoby->angle.pitch = -(int)camera.unk46 >> 4;
                                yawWord = camera.unk48;
                                __asm__("" : : : "$17", "memory");
                                child = 0;
                                newMoby->angle.yaw = yawWord >> 4;
                                func_8004ECF4(matrix, (unsigned char*)modePointer - 0x38);
                                func_8004ED6C(matrix, &tag->vector0, &tag->vector0);
                            } else {
                                newMoby->state = 5;
                                goto rotated197;
                            }
                        } else
                            goto ordinary197;
                    } else {
                    ordinary197:
                        newMoby->state = 0;
                        tag->byteE = 1;
                    rotated197:
                        newMoby->angle.yaw = linkedMoby->angle.yaw;
                        func_8004ED6C(&linkedMoby->rotationMatrix, &tag->vector0, &tag->vector0);
                        newMoby->angle.pitch =
                            func_8004E880(func_8004EDE8(&tag->vector0, 1), tag->vector0.z, 0);
                        newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                        child = SpawnMoby(197, newMoby);
                    }
                    __asm__("" : " = r"(child) : "0"(child));
                    if (child) {
                        Spawn46Tag197* childTag = child->mobyTag;
                        Moby* second;
                        childTag->timer10 = 3;
                        roll = func_8003636C(0, 255);
                        child->angle.roll = roll;
                        yaw = (((short)camera.unk48 >> 4) + 128) & 255;
                        child->angle.yaw = yaw;
                        pitchWord = camera.unk46;
                        child->state = 1;
                        pitch = (pitchWord >> 4) & 255;
                        child->angle.pitch = pitch;
                        if (linkedMoby->mobyClass == 99) {
                            alpha = 255;
                            child->colour.r = alpha;
                            alpha = 13;
                            child->colour.g = 0;
                        } else {
                            alpha = 255;
                            child->colour.g = alpha;
                            alpha = 12;
                            child->colour.r = 0;
                        }
                        __asm__("" : " = r"(alpha) : "0"(alpha));
                        child->colour.b = 0;
                        child->colour.a = alpha;
                        __asm__("" : : : "$4", "$5", "memory");
                        func_8004F178(&child->position, &frame.vector20);
                        func_8004F178(&childTag->vector0, &frame.vector20);
                        func_80034F80(child, 1);
                        second = SpawnMoby(197, newMoby);
                        if (second) {
                            Spawn46Tag197* secondTag = second->mobyTag;
                            secondTag->timer10 = 3;
                            second->colour.r = 255;
                            second->colour.g = 255;
                            second->colour.b = 255;
                            second->colour.a = 15;
                            second->angle.roll = roll;
                            second->angle.pitch = pitch;
                            second->angle.yaw = yaw;
                            second->state = 3;
                            func_8004F178(&second->position, &frame.vector20);
                            func_8004F178(&secondTag->vector0, &frame.vector20);
                            func_80034F80(second, 3);
                        }
                    }
                    if (linkedMoby->mobyClass == 99 && camera.cameraState == 31) {
                        child = SpawnMoby(197, 0);
                        __asm__("" : " = r"(child) : "0"(child));
                        tag->child14 = child;
                        if (child) {
                            unsigned char childYaw;
                            child->angle.pitch = newMoby->angle.pitch;
                            childYaw = newMoby->angle.yaw;
                            child->state = 2;
                            child->angle.yaw = childYaw;
                            func_8004F178(&child->position, &newMoby->position);
                            child->colour.r = 255;
                            child->colour.g = 0;
                            child->colour.b = 0;
                            child->colour.a = 13;
                            func_80034F80(child, 3);
                        }
                    } else {
                        child = SpawnMoby(197, 0);
                        __asm__("" : " = r"(child) : "0"(child));
                        tag->child14 = child;
                        if (child) {
                            unsigned char childYaw;
                            child->angle.pitch = newMoby->angle.pitch;
                            childYaw = newMoby->angle.yaw;
                            child->state = 2;
                            child->angle.yaw = childYaw;
                            func_8004F178(&child->position, &newMoby->position);
                            func_80034F80(child, 4);
                            if (linkedMoby->mobyClass == 99) {
                                alpha = 255;
                                child->colour.r = alpha;
                                alpha = 56;
                                child->colour.g = 0;
                            } else {
                                alpha = 255;
                                child->colour.g = alpha;
                                alpha = 56;
                                child->colour.r = 0;
                            }
                            __asm__("" : " = r"(alpha) : "0"(alpha));
                            child->colour.b = 0;
                            child->colour.a = alpha;
                        }
                    }
                }
            }
            break;
        }
        case 245: {
            Spawn46Tag245* tag = newMoby->mobyTag;
            register int azimuth __asm__("$16");
            int elevation;
            register short* cosine __asm__("$4");
            if (linkedMoby)
                func_8004F178(&newMoby->position, &linkedMoby->position);
            else
                func_8004F178(&newMoby->position, &spyro.position);
            azimuth = rand() & 255;
            elevation = rand() & 255;
            /* Original960 changes the masked table index to a byte offset. */
            azimuth *= 2;
            __asm__("" : " = r"(azimuth), " = r"(elevation) : "0"(azimuth), "1"(elevation) : "$4");
            cosine = D_80065920;
            __asm__("" : " = r"(cosine) : "0"(cosine));
            cosine = (short*)((unsigned int)(elevation * 2) + (unsigned int)cosine);
            tag->vector0.x =
                (((*(short*)((unsigned char*)D_80065920 + azimuth) * 16) >> 8) * *cosine) >> 12;
            tag->vector0.y =
                (((*(short*)((unsigned char*)D_800658A0 + azimuth) * 16) >> 8) * *cosine) >> 12;
            tag->vector0.z = (D_800658A0[elevation] * 16) >> 8;
            tag->timerC = func_8003636C(90, 150);
            func_8004F194(&newMoby->position, &newMoby->position, &tag->vector0);
            func_8004F110(&tag->vector0, 1);
            newMoby->angle.yaw = rand();
            func_80055C24(newMoby);
            switch (rand() & 3) {
                case 0:
                    *(unsigned int*)&newMoby->colour = 0x3C0000FF;
                    break;
                case 1:
                    *(unsigned int*)&newMoby->colour = 0x3C00A0B0;
                    break;
                case 2:
                    *(unsigned int*)&newMoby->colour = 0x3C0080FF;
                    break;
                case 3:
                    *(unsigned int*)&newMoby->colour = 0x3C000000;
                    break;
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
        case 308:
        case 630:
        case 631:
        case 306: {
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
                frame.work40.vector.x =
                    D_80065920[func_8004E880(newMoby->position.x - spyro.position.x,
                                             newMoby->position.y - spyro.position.y, 0)];
                frame.work40.vector.x = (short)frame.work40.vector.x >> 4;
                frame.work40.vector.y =
                    D_800658A0[func_8004E880(newMoby->position.x - spyro.position.x,
                                             newMoby->position.y - spyro.position.y, 0)];
                frame.work40.vector.y = (short)frame.work40.vector.y >> 4;
                frame.work40.vector.z = 0;
                mobyTag->linearVel.x += frame.work40.vector.x;
                mobyTag->linearVel.y += frame.work40.vector.y;
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
        case 1000: {
            Spawn46Tag1000* tag = newMoby->mobyTag;
            int sourceIndex;
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
            sourceIndex = ((int*)linkedMoby->mobyTag)[0x70 / 4];
            if (sourceIndex >= 0) {
                Moby* sourceMoby = mobyArrayPtr + sourceIndex;
                tag->buffer4 = (int*)((unsigned char*)sourceMoby->mobyTag + 0x14);
                func_8004E7AC(tag->buffer4, 0, 0xEB0);
                tag->word0 = 32;
                tag->word2 = 25;
                tag->word14 = 15;
                tag->word16 = 30;
                tag->parent10 = sourceMoby;
            }
            break;
        }
        case 1005: {
            Spawn46Tag1000* tag = newMoby->mobyTag;
            Moby* sourceMoby;
            Moby* end;
            register int allocationSize __asm__("$18");
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
            sourceMoby = mobyArrayPtr;
            end = D_8006C704;
            __asm__("" : " = r"(end) : "0"(end), "r"(sourceMoby) : "$18");
            allocationSize = 0x9D0;
            for (; sourceMoby < end; sourceMoby++) {
                if (sourceMoby->mobyClass == 1020 && ((int*)sourceMoby->mobyTag)[2] == 0x13A0)
                    break;
            }
            if (sourceMoby) {
                int* owner = sourceMoby->mobyTag;
                __asm__("" : " = r"(allocationSize) : "0"(allocationSize));
                tag->buffer4 = (int*)((unsigned char*)owner + (owner[0] + 0x14));
                owner[0] += allocationSize;
                if (owner[0] >= owner[2])
                    owner[0] = 0;
                func_8004E7AC(tag->buffer4, 0, allocationSize);
                tag->word0 = 200;
                tag->parent10 = sourceMoby;
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
