#include "common.h"

/* AI-adapted from attributed upstream source below; not human reviewed. Verified against this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Source baseline: gpXPY, Hwd405, credited level14 common spawn C;
* class90/326 also reuse original include/moby/moby_spawn.h. This level's
* original-specific additions, type adapters, cleanup and provenance are
* AI generated and not human reviewed. func_level_47_8008580C:
* SCUS-94467 USA Rev0, 2236 original words; original assembly SHA256
* 9099c5f5c47206025bc95224fa92ad5898658f6ede71b60ba0148cdd46c01204.
* Original widths, masks, signed shifts, table reads and call ordering are
* retained. Accepted44 class197/common,32 class194,50 effect84/751/
*factories and34/43 common bodies are reused. This original has no class1
*special case. Its197 target58/class745 branch and765 height selectors retain
*exact table products. New750 retains the original random-yaw call. Shared
*156/763 copy/initialize and755 final-call tails,272/964 draw clears and751's
*800 timer/linked tag2C remain exact. Both factory ring sizes are EB0 here.
* Frame160/save138 and SP18/28/38/48/60/68/78/88/98/A8/B0/B8/C8/D8/E8/F8/
*108/118 views retain all observed offsets. The explicit11C gap plus compiler
*reservation together retain the original space before save138. Nested unions
*describe disjoint local storage; all fields/padding are kept. The five-arg
*365E4 call writes to118.755 writes only pitch61/yaw62 before using angle60;
*there is no roll60 producer on this path. No zero default is invented; its
*retail stack-context dependency remains explicit and unresolved semantically.
*760 uses the original full signed rand/modulo, not m2c's guessed byte return.
*Scoped C products restore original t0 scratch allocation; no fixed-t0 binding
*is used. Initialized v0 random/product and a0 argument producers, dead-v1
*boundary and memory ordering retain every instruction. Product inputs are
*consumed before outputs reuse v0; no overlapping live input is overwritten.
*No CPU instruction assembly, acceptance, flags or shared-symbol change used.
*Full helper/units/caller-frame contracts and synchronized runtime remain open.
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
}
Spawn47Tag197;
static __inline__ int Spawn47LinkIndex(int byteOffset) {
    return (int)(0U-(unsigned int)byteOffset*0x45D1745DU)>>3;
}
extern unsigned char D_8006C40B, D_8007158F;
extern int D_8006C7C4;
void func_8004F0E8(Vector3D*, int);
void func_8004F110(Vector3D*, int);
int func_800365E4(Vector3D*, Vector3D*, int, int, int*);
int func_8001A358(Vector3D*, int);
typedef struct {
    Vector3D vector0;
    unsigned char padC[0x10];
    void* data1C;
    unsigned char pad20[0x2C];
    int index4C;
    Moby* source50;
    short state54, pad56;
    Moby* target58;
    Vector3D vector5C, vector68, vector74;
}
Spawn47LinkedView;
typedef struct {
    Moby* owner0;
    void* light4;
    void* light8;
    void* lightC;
    unsigned char red10, green11, blue12, pad13;
    int word14;
}
Spawn47Tag759;
typedef struct {
    Moby* owner0;
    Moby* child4;
    int words8[4];
}
Spawn47Tag765;
typedef struct {
    Vector3D vector0;
    int wordC, word10;
    Moby* owner14;
}
Spawn47Tag760;
typedef struct {
    Vector3D vector0;
    short wordC, wordE, timer10;
    unsigned char byte12, byte13;
    Moby* parent14;
}
Spawn47Tag194;
typedef struct {
    int* cursor0;
    int word4;
    int words8[2];
    Vector3D vector10;
}
Spawn47Payload755;
typedef struct {
    Vector3D vector0;
    Spawn47Payload755* bufferC;
    short word10, word12, word14, pad16;
}
Spawn47Tag755;
typedef struct {
    short word0, word2;
    int word4;
    Moby* child8;
    int wordC;
    int word10, word14;
}
Spawn47Tag751;
typedef struct {
    short word0, word2;
    int* buffer4;
    int word8, wordC;
    Moby* parent10;
    short word14, word16;
}
Spawn47FactoryTag;
Moby* func_level_47_8008580C(int mobyClass, Moby* linkedMoby) {
    Moby* newMoby;
    void* newMobyTag;
    register Vector3D* copyDestination __asm__("$4");
    register Vector3D* copySource __asm__("$5");
    struct {
        Vector3D vector18;
        int gap24;
        Vector3D vector28;
        int gap34;
        Vector3D vector38;
        int gap44;
        SHORTMATRIX matrix48;
        int gap5C;
        Angle angle60;
        unsigned char gap63[8-sizeof(Angle)];
        Vector3D vector68;
        int gap74;
        Vector3D vector78;
        int gap84;
        Vector3D vector88;
        int gap94;
        union {
            SHORTMATRIX matrix98;
            Vector3D vector98;
            struct {
                unsigned char pad0[0x10];
                Vector3D vectorA8;
            }
            a8;
            struct {
                unsigned char pad0[0x18];
                SHORTMATRIX matrixB0;
            }
            b0;
            struct {
                unsigned char pad0[0x20];
                SHORTMATRIX matrixB8;
            }
            b8;
            struct {
                unsigned char pad0[0x30];
                Vector3D vectorC8;
            }
            c8;
        }
        work98;
        int gapD4;
        Vector3D vectorD8;
        int gapE4;
        Vector3D vectorE8;
        int gapF4;
        Vector3D vectorF8;
        int gap104;
        Vector3D vector108;
        int gap114;
        int outSteps118;
        int gap11C[3];
    }
    frame;
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
    case 84:
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
            azimuth = (linkedMoby->angle.yaw + func_8003636C(-0x5DC, 0x5DC)) & 0xFFF;
            radius = 0x78;
            mobyTag->unk0.x = ((func_8004EA2C(elevation) >> 6) * (func_8004EA2C(azimuth) * radius)) >> 0x12;
            mobyTag->unk0.y = ((func_8004EA2C(elevation) >> 6) * (func_8004E9E4(azimuth) * radius)) >> 0x12;
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
            }
            else {
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
            }
            else {
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
    case 77:
        func_8004F178(&newMoby->position, &linkedMoby->position);
        newMoby->angle.yaw = linkedMoby->angle.yaw;
        func_80055C24(newMoby);
        break;
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
                frame.vector18.x = (D_80065920[yaw] * 0x7D) >> 9;
                frame.vector18.y = (D_800658A0[yaw] * 0x7D) >> 9;
                frame.vector18.z = 0x3E8;
                func_8004F194(&newMoby->position, &spyro.position, &frame.vector18);
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
    case 156:
        copyDestination = &newMoby->position;
        copySource = &linkedMoby->position;
        newMoby->lowDrawDistance = 64;
        newMoby->highDrawDistance = 64;
        *(int*)newMoby->mobyTag = 266;
        goto copyInitialize47;
    case 194:
        {
            Spawn47Tag194* tag = newMoby->mobyTag;
            int radius;
            int yProduct, vertical;
            int count = 0;
            tag->parent14 = linkedMoby;
            newMoby->updateDistance = 255;
            newMoby->lowDrawDistance = 64;
            newMoby->unknown = -1;
            frame.vector18.x = 1800;
            frame.vector18.y = 0;
            frame.vector18.z = (linkedMoby->animationProgress<<5)+512;
            func_8004ED6C(&linkedMoby->rotationMatrix, &frame.vector18, &frame.vector18);
            func_8004F194(&newMoby->position, &frame.vector18, &linkedMoby->position);
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            tag->wordE = 5;
            tag->wordC = -7;
            radius = linkedMoby->animationProgress*16+240;
            tag->vector0.x = (D_80065920[newMoby->angle.yaw]*radius)>>12;
            yProduct = D_800658A0[newMoby->angle.yaw]*radius;
            ((volatile Spawn47Tag194*)tag)->vector0.z = 0;
            tag->byte12 = 1;
            tag->vector0.y = yProduct>>12;
            vertical = linkedMoby->animationProgress;
            tag->byte13 = 0;
            tag->vector0.z = vertical*15+120;
            frame.angle60.roll = rand();
            frame.angle60.pitch = newMoby->angle.pitch;
            frame.angle60.yaw = newMoby->angle.yaw;
            do {
                frame.angle60.roll += 32;
                func_8004EA90(&frame.angle60, &frame.matrix48, 0);
                frame.vector28.x = 30;
                frame.vector28.y = (rand()&15)+32;
                frame.vector28.z = 0;
                func_8004ED6C(&frame.matrix48, &frame.vector28, &frame.vector28);
                func_8004F178(&frame.vector38, &frame.vector28);
                func_8004F0E8(&frame.vector38, 2);
                func_8004F194(&frame.vector38, &frame.vector38, &newMoby->position);
                SpawnParticle(1, 13, &frame.vector38, &frame.vector28);
                count++;
            }
            while(count<8);
            func_80055C24(newMoby);
            tag->timer10 = 180;
            break;
        }
    case 197:
        {
            Spawn47Tag197* tag = newMoby->mobyTag;
            register Moby* child __asm__("$17");
            if (linkedMoby && linkedMoby->mobyClass!=mobyClass) {
                if (linkedMoby->mobyClass==99 && (camera.cameraState==31 || camera.cameraState==40)) {
                    func_8004F178(&newMoby->position, &camera.nextCameraPosCartesian);
                    if (camera.cameraState==40) newMoby->position.z-=128;
                    func_8004F178(&frame.vector78, &newMoby->position);
                }
                else {
                    func_80055D24(linkedMoby, 5);
                    func_80055F14(linkedMoby, 0, &frame.vector78);
                    frame.vector68.x = 600;
                    frame.vector68.y = 0;
                    frame.vector68.z = 0;
                    func_8004ED6C(&linkedMoby->rotationMatrix, &frame.vector68, &frame.vector68);
                    func_8004F194(&newMoby->position, &frame.vector78, &frame.vector68);
                }
            }
            else func_8004F178(&newMoby->position, &spyro.position);
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 40;
            newMoby->updateDistance = 255;
            if (linkedMoby) {
                if (linkedMoby->mobyClass==197) {
                    unsigned int link = linkedMoby->linkedMoby;
                    if (link<255) {
                        register unsigned int byteOffset __asm__("$4") = link*0x58;
                        __asm__("" : "=r"(byteOffset) : "0"(byteOffset));
                        newMoby->linkedMoby = Spawn47LinkIndex(byteOffset);
                    }
                }
                if (linkedMoby && linkedMoby->mobyClass!=197) {
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
                    if (linkedMoby->mobyClass==99) {
                        if (D_8006C5BC==44 && D_80071A04) {
                            Moby* candidate;
                            Vector3D* position;
                            Vector3D* workVector;
                            for(candidate = mobyArrayPtr;candidate<D_8006C704;candidate++) {
                                if (candidate->mobyClass==962) break;
                            }
                            workVector = &frame.vector88;
                            func_8004F178(workVector, (Vector3D*)((unsigned char*)candidate->mobyTag+0x1C));
                            child = 0;
                            position = &newMoby->position;
                            newMoby->position.z-=256;
                            tag->wordC = 4096;
                            newMoby->state = 0;
                            newMoby->angle.roll = (unsigned short)camera.unk44>>4;
                            newMoby->angle.pitch = -(int)camera.unk46>>4;
                            newMoby->angle.yaw = (unsigned short)camera.unk48>>4;
                            if (func_80013E38(position, workVector, 0)) func_8004F1C8(workVector, workVector, position);
                            else func_8004F1C8(workVector, &D_80071900.D_80071900, position);
                            func_8004F08C(workVector, func_8004EDE8(workVector, 1), tag->wordC);
                            func_8004F178(&tag->vector0, workVector);
                            newMoby->angle.pitch = func_8004E880(func_8004EDE8(&tag->vector0, 1), tag->vector0.z, 0);
                            newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                        }
                        else if (linkedMoby->mobyClass==99) {
                            SHORTMATRIX* matrix;
                            int* modePointer;
                            int vectorX;
                            unsigned short yawWord;
                            modePointer = &camera.cameraState;
                            if (*modePointer==40) {
                                vectorX = 600;
                                matrix = &frame.work98.matrix98;
                                goto cameraMatrix197;
                            }
                            if (*modePointer==31) {
                                tag->wordC = 4096;
                                vectorX = 4096;
                                matrix = &frame.work98.b0.matrixB0;
                            cameraMatrix197:
                                tag->vector0.x = vectorX;
                                newMoby->state = 0;
                                newMoby->angle.roll = (unsigned short)camera.unk44>>4;
                                newMoby->angle.pitch = -(int)camera.unk46>>4;
                                yawWord = camera.unk48;
                                __asm__("" : : : "$17", "memory");
                                child = 0;
                                newMoby->angle.yaw = yawWord>>4;
                                func_8004ECF4(matrix, (unsigned char*)modePointer-0x38);
                                func_8004ED6C(matrix, &tag->vector0, &tag->vector0);
                            }
                            else {
                                newMoby->state = 5;
                                goto rotated197;
                            }
                        }
                        else goto ordinary197;
                    }
                    else {
                    ordinary197:
                        newMoby->state = 0;
                        tag->byteE = 1;
                    rotated197:
                        newMoby->angle.yaw = linkedMoby->angle.yaw;
                        if(linkedMoby->mobyClass==745 && ((Spawn47LinkedView*)linkedMoby->mobyTag)->target58) {
                            Spawn47LinkedView* linkedTag = linkedMoby->mobyTag;
                            int azimuth, elevation;
                            func_8004F178(&frame.work98.c8.vectorC8, &linkedTag->target58->position);
                            if(linkedTag->target58->mobyClass==765)frame.work98.c8.vectorC8.z += 1280;
                            else frame.work98.c8.vectorC8.z += 2560;
                            azimuth = func_8004E880(frame.work98.c8.vectorC8.x-newMoby->position.x, frame.work98.c8.vectorC8.y-newMoby->position.y, 0);
                            elevation = func_8004E880(func_8004F334(&newMoby->position, &frame.work98.c8.vectorC8), frame.work98.c8.vectorC8.z-newMoby->position.z, 0);
                            tag->vector0.x = (((D_80065920[azimuth]*tag->wordC)>>12)*D_80065920[elevation])>>12;
                            tag->vector0.y = (((D_800658A0[azimuth]*tag->wordC)>>12)*D_80065920[elevation])>>12;
                            tag->vector0.z = (D_800658A0[elevation]*tag->wordC)>>12;
                        }
                        else func_8004ED6C(&linkedMoby->rotationMatrix, &tag->vector0, &tag->vector0);
                        newMoby->angle.pitch = func_8004E880(func_8004EDE8(&tag->vector0, 1), tag->vector0.z, 0);
                        newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
                        child = SpawnMoby(197, newMoby);
                    }
                    __asm__("" : "=r"(child) : "0"(child));
                    if (child) {
                        Spawn47Tag197* childTag = child->mobyTag;
                        Moby* second;
                        childTag->timer10 = 3;
                        roll = func_8003636C(0, 255);
                        child->angle.roll = roll;
                        yaw = (((short)camera.unk48>>4)+128)&255;
                        child->angle.yaw = yaw;
                        pitchWord = camera.unk46;
                        child->state = 1;
                        pitch = (pitchWord>>4)&255;
                        child->angle.pitch = pitch;
                        if(linkedMoby->mobyClass==99) {
                            alpha = 255;
                            child->colour.r = alpha;
                            alpha = 13;
                            child->colour.g = 0;
                        }
                        else {
                            alpha = 255;
                            child->colour.g = alpha;
                            alpha = 12;
                            child->colour.r = 0;
                        }
                        __asm__("" : "=r"(alpha) : "0"(alpha));
                        child->colour.b = 0;
                        child->colour.a = alpha;
                        __asm__("" : : : "$4", "$5", "memory");
                        func_8004F178(&child->position, &frame.vector78);
                        func_8004F178(&childTag->vector0, &frame.vector78);
                        func_80034F80(child, 1);
                        second = SpawnMoby(197, newMoby);
                        if (second) {
                            Spawn47Tag197* secondTag = second->mobyTag;
                            secondTag->timer10 = 3;
                            second->colour.r = 255;
                            second->colour.g = 255;
                            second->colour.b = 255;
                            second->colour.a = 15;
                            second->angle.roll = roll;
                            second->angle.pitch = pitch;
                            second->angle.yaw = yaw;
                            second->state = 3;
                            func_8004F178(&second->position, &frame.vector78);
                            func_8004F178(&secondTag->vector0, &frame.vector78);
                            func_80034F80(second, 3);
                        }
                    }
                    if (linkedMoby->mobyClass==99 && camera.cameraState==31) {
                        child = SpawnMoby(197, 0);
                        __asm__("" : "=r"(child) : "0"(child));
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
                    }
                    else {
                        child = SpawnMoby(197, 0);
                        __asm__("" : "=r"(child) : "0"(child));
                        tag->child14 = child;
                        if (child) {
                            unsigned char childYaw;
                            child->angle.pitch = newMoby->angle.pitch;
                            childYaw = newMoby->angle.yaw;
                            child->state = 2;
                            child->angle.yaw = childYaw;
                            func_8004F178(&child->position, &newMoby->position);
                            func_80034F80(child, 4);
                            if(linkedMoby->mobyClass==99) {
                                alpha = 255;
                                child->colour.r = alpha;
                                alpha = 56;
                                child->colour.g = 0;
                            }
                            else {
                                alpha = 255;
                                child->colour.g = alpha;
                                alpha = 56;
                                child->colour.r = 0;
                            }
                            __asm__("" : "=r"(alpha) : "0"(alpha));
                            child->colour.b = 0;
                            child->colour.a = alpha;
                        }
                    }
                }
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
            goto clearDraw47;
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
    case 596:
        {
            Vector3D* position = &newMoby->position;
            Vector3D* linkedPosition = &linkedMoby->position;
            int* tag = newMoby->mobyTag;
            func_8004F178(position, linkedPosition);
            func_80055C24(newMoby);
            newMoby->size = 64;
            tag[0] = 200;
            tag[1] = 35;
            newMoby->angle.yaw = linkedMoby->angle.yaw;
            func_80055D24(linkedMoby, 4);
            frame.work98.vector98.x = 2000;
            frame.work98.vector98.y = 0;
            frame.work98.vector98.z = 300;
            func_8004ED6C(&linkedMoby->rotationMatrix, &frame.work98.vector98, &frame.work98.vector98);
            func_8004F194(position, linkedPosition, &frame.work98.vector98);
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
    case 750:
        {
            Moby** tag = newMoby->mobyTag;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->angle.yaw = func_8003636C(0, 255);
            func_80055C24(newMoby);
            newMoby->updateDistance = linkedMoby->updateDistance;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            newMoby->highDrawDistance = linkedMoby->highDrawDistance;
            *tag = linkedMoby;
            break;
        }
    case 751:
        {
            Spawn47Tag751* tag = newMoby->mobyTag;
            int timer = 800;
            register int yaw __asm__("$3");
            register int alpha __asm__("$2");
            if(linkedMoby) {
                int* linkedTag = linkedMoby->mobyTag;
                Moby* child;
                func_80055D24(linkedMoby, 4);
                frame.work98.a8.vectorA8.x = 1024;
                frame.work98.a8.vectorA8.y = 0;
                frame.work98.a8.vectorA8.z = 0;
                func_8004ED6C(&linkedMoby->rotationMatrix, &frame.work98.a8.vectorA8, &frame.work98.a8.vectorA8);
                func_8004F194(&newMoby->position, &linkedMoby->position, &frame.work98.a8.vectorA8);
                func_80055C24(newMoby);
                func_8003BABC(newMoby, 1, 0);
                newMoby->updateDistance = 255;
                newMoby->lowDrawDistance = 63;
                newMoby->size = 96;
                newMoby->angle.roll = linkedMoby->angle.roll;
                newMoby->angle.pitch = linkedMoby->angle.pitch;
                __asm__("" : : : "$2", "$3", "memory");
                alpha = 58;
                __asm__("" : "=r"(alpha) : "0"(alpha) : "$3");
                yaw = linkedMoby->angle.yaw;
                __asm__("" : "=r"(yaw) : "0"(yaw));
                newMoby->colour.a = alpha;
                newMoby->colour.r = 255;
                newMoby->angle.yaw = yaw;
                tag->word2 = timer;
                tag->word0 = 200;
                tag->word4 = 0;
                tag->wordC = linkedTag[11];
                func_80055D24(newMoby, 4);
                child = SpawnMoby(751, 0);
                if(child) {
                    Spawn47Tag751* childTag = child->mobyTag;
                    tag->child8 = child;
                    child->updateDistance = 255;
                    child->lowDrawDistance = 63;
                    child->size = 128;
                    func_8004F178(&child->position, &newMoby->position);
                    child->angle.roll = newMoby->angle.roll;
                    child->angle.pitch = newMoby->angle.pitch;
                    yaw = newMoby->angle.yaw;
                    __asm__("" : "=r"(yaw) : "0"(yaw));
                    child->substate = 1;
                    child->colour.a = 63;
                    child->colour.r = 255;
                    child->colour.g = 255;
                    child->colour.b = 64;
                    child->angle.yaw = yaw;
                    childTag->word2 = timer;
                    childTag->word0 = 200;
                    childTag->word4 = 0;
                    func_80055D24(child, 4);
                    return newMoby;
                }
                break;
            }
            goto defaultSpawn47;
        }
    case 755:
        {
            Spawn47LinkedView* linkedTag = linkedMoby->mobyTag;
            int adjustment = D_8006C40B;
            Spawn47Tag755* tag = newMoby->mobyTag;
            int* owner = (mobyArrayPtr+linkedTag->index4C)->mobyTag;
            int allocationBytes;
            int remaining;
            Vector3D* position;
            __asm__("" : : : "$23");
            allocationBytes = 352;
            if(D_8006C7C4==2) {
                adjustment--;
                if(adjustment<0)adjustment = 0;
            }
            else if(D_8006C7C4==1)adjustment += 3;
            else if(D_8006C7C4==0)adjustment += 5;
            if(D_8007158F)adjustment = 0;
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            frame.vectorD8.x = 440;
            frame.vectorD8.y = 0;
            frame.vectorD8.z = 0;
            func_80055D24(linkedMoby, 4);
            position = &newMoby->position;
            func_80055F14(linkedMoby, 10, position);
            func_80055F14(linkedMoby, 9, &frame.vectorE8);
            /* Original755 writes only pitch/yaw at61/62 before this call. Roll60
            * has no producer on this path; preserve that retail stack gap. */
            frame.angle60.yaw = func_8004E880(newMoby->position.x-frame.vectorE8.x, newMoby->position.y-frame.vectorE8.y, 0);
            frame.angle60.pitch = func_8004E880(func_8004F334(&frame.vectorE8, position), newMoby->position.z-frame.vectorE8.z, 0);
            func_8004EA90(&frame.angle60, &frame.work98.b8.matrixB8, 0);
            func_8004ED6C(&frame.work98.b8.matrixB8, &frame.vectorD8, &frame.vectorD8);
            newMoby->angle.pitch = func_8004E880(func_8004EDE8(&frame.vectorD8, 0), frame.vectorD8.z, 0);
            newMoby->angle.yaw = func_8004E880(frame.vectorD8.x, frame.vectorD8.y, 0);
            tag->vector0.x = frame.vectorD8.x;
            tag->vector0.y = frame.vectorD8.y;
            tag->vector0.z = frame.vectorD8.z;
            func_80055F14(linkedTag->target58, 0, position);
            if(owner[1]>allocationBytes)allocationBytes = owner[1];
            if(owner[0]+allocationBytes >= owner[2])owner[0] = 0;
            tag->bufferC = (Spawn47Payload755*)((unsigned char*)owner+(owner[0]+0x14));
            tag->bufferC->cursor0 = (int*)((unsigned char*)tag->bufferC+0x1C);
            *tag->bufferC->cursor0 = 0;
            func_8004E7D4(tag->bufferC->words8, owner+3, 8);
            owner[0] += allocationBytes;
            tag->bufferC->word4 = 0;
            if(linkedTag->source50)func_8004F178(&tag->bufferC->vector10, &linkedTag->source50->position);
            else {
                int multiplier = (func_8004F334(position, &spyro.position)/440)*2;
                func_8004F178(&tag->bufferC->vector10, (Vector3D*)((unsigned char*)&spyro+0x98));
                tag->bufferC->vector10.x*=multiplier;
                tag->bufferC->vector10.y*=multiplier;
                tag->bufferC->vector10.z*=multiplier;
                func_8004F110(&tag->bufferC->vector10, 6);
                func_8004F194(&tag->bufferC->vector10, &tag->bufferC->vector10, &spyro.position);
                if(adjustment >= 6) {
                    int count = adjustment-5;
                    if(count >= 6)count = 5;
                    func_8004F1C8(&frame.vectorF8, &spyro.position, &tag->bufferC->vector10);
                    func_8004F08C(&frame.vectorF8, 5, count);
                    func_8004F194(&tag->bufferC->vector10, &tag->bufferC->vector10, &frame.vectorF8);
                }
                tag->bufferC->vector10.z += 512;
                tag->bufferC->vector10.z = func_8001A358(&tag->bufferC->vector10, 8192);
            }
            tag->word10 = 110;
            tag->word14 = 30;
            remaining = 50-(func_8004F334(&newMoby->position, &tag->bufferC->vector10)>>9);
            tag->word12 = remaining;
            if((short)remaining<0)tag->word12 = 0;
            newMoby->unknown5 = 1;
            goto finishShared47;
        }
    case 759:
        {
            Vector3D* position = &newMoby->position;
            Spawn47Tag759* tag = newMoby->mobyTag;
            Spawn47LinkedView* linkedTag = linkedMoby->mobyTag;
            int colour;
            func_8004F178(position, &linkedMoby->position);
            func_80055D24(linkedMoby, 4);
            func_80055F14(linkedMoby, 9, position);
            func_80055F14(linkedMoby, 10, &linkedTag->vector5C);
            newMoby->angle.yaw = func_8004E880(newMoby->position.x-linkedTag->vector5C.x, newMoby->position.y-linkedTag->vector5C.y, 0);
            newMoby->angle.pitch = func_8004E880(func_8004F334(&linkedTag->vector5C, position), newMoby->position.z-linkedTag->vector5C.z, 0)-64;
            func_80055C24(newMoby);
            newMoby->updateDistance = linkedMoby->updateDistance;
            newMoby->lowDrawDistance = linkedMoby->lowDrawDistance;
            newMoby->highDrawDistance = linkedMoby->lowDrawDistance;
            tag->owner0 = linkedMoby;
            func_8004F178(&linkedTag->vector68, &linkedTag->vector5C);
            func_8004F178(&linkedTag->vector74, &linkedTag->vector5C);
            tag->red10 = 150;
            tag->green11 = 51;
            tag->blue12 = 160;
            colour = tag->red10|(tag->green11<<8)|0xA00000;
            tag->light4 = func_80050844(&linkedTag->vector5C, 10, 10, colour);
            tag->light8 = func_80050844(&linkedTag->vector68, 10, 10, colour);
            tag->lightC = func_80050844(&linkedTag->vector74, 10, 10, colour);
            break;
        }
    case 760:
        {
            register Spawn47Tag760* tag __asm__("$21");
            register Spawn47LinkedView* linkedTag __asm__("$17");
            register Moby* ownerArgument __asm__("$4");
            int speed, yaw;
            register int quotientProduct __asm__("$2");
            ownerArgument = linkedMoby;
            __asm__("" : : "r"(ownerArgument) : "memory");
            tag = newMoby->mobyTag;
            __asm__("" : : : "memory");
            linkedTag = linkedMoby->mobyTag;
            func_80055D24(ownerArgument, 4);
            func_80055F14(linkedMoby, 10, &newMoby->position);
            func_80055C24(newMoby);
            newMoby->unknown = -1;
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            if(linkedTag->state54==2 && (rand()&7)!=0) {
                register int randomValue __asm__("$2");
                register int coefficient __asm__("$19");
                int distance;
                do {
                    int distance;
                    newMoby->angle.yaw = rand();
                    distance = rand()%13312;
                    frame.vector108.x = (D_80065920[newMoby->angle.yaw]*distance)>>12;
                    {
                        int loopYProduct = D_800658A0[newMoby->angle.yaw]*distance;
                        frame.vector108.z = 0;
                        frame.vector108.y = loopYProduct>>12;
                    }
                    func_8004F194(&frame.vector108, &frame.vector108, &linkedTag->vector0);
                }
                while(func_8004F334(&frame.vector108, &linkedMoby->position)<3072);
                randomValue = rand();
                __asm__("" : "=r"(randomValue) : "0"(randomValue));
                coefficient = randomValue%75+150;
                distance = func_8004F334(&newMoby->position, &frame.vector108)+5120;
                quotientProduct = coefficient*distance;
                __asm__("" : "=r"(quotientProduct) : "0"(quotientProduct) : "$3");
                speed = quotientProduct/18432;
                yaw = func_8004E880(frame.vector108.x-newMoby->position.x, frame.vector108.y-newMoby->position.y, 0);
            }
            else {
                int multiplier = (func_8004F334(&newMoby->position, &spyro.position)/300)*2+30;
                func_8004F178(&frame.vector108, (Vector3D*)((unsigned char*)&spyro+0x98));
                frame.vector108.x*=multiplier;
                frame.vector108.y*=multiplier;
                frame.vector108.z*=multiplier;
                speed = 300;
                func_8004F110(&frame.vector108, 6);
                func_8004F194(&frame.vector108, &frame.vector108, &spyro.position);
                yaw = func_8004E880(frame.vector108.x-newMoby->position.x, frame.vector108.y-newMoby->position.y, 0);
                newMoby->substate = 1;
                if(func_8004F334(&frame.vector108, &linkedMoby->position)<3072) {
                    register int vectorX __asm__("$3") = D_80065920[yaw];
                    int vectorY;
                    frame.vector108.x = vectorX;
                    __asm__("" : : : "memory");
                    vectorY = D_800658A0[yaw];
                    frame.vector108.z = 0;
                    frame.vector108.y = vectorY;
                    func_8004F194(&frame.vector108, &frame.vector108, &linkedMoby->position);
                }
            }
            tag->vector0.x = (D_80065920[yaw]*speed)>>12;
            {
                int tagYProduct = D_800658A0[yaw]*speed;
                ((volatile Spawn47Tag760*)tag)->vector0.z = 0;
                tag->owner14 = linkedMoby;
                tag->wordC = -10;
                tag->vector0.y = tagYProduct>>12;
            }
            tag->vector0.z = func_800365E4(&newMoby->position, &frame.vector108, speed, tag->wordC, &frame.outSteps118);
            tag->word10 = linkedMoby->position.z;
            newMoby->angle.pitch = func_8004E880(func_8004EDE8(&tag->vector0, 0), tag->vector0.z, 0);
            newMoby->angle.yaw = func_8004E880(tag->vector0.x, tag->vector0.y, 0);
            newMoby->unknown5 = 1;
            func_8003BABC(newMoby, 0, 0);
            return newMoby;
        }
    case 763:
        {
            int* tag = newMoby->mobyTag;
            int* linkedTag = linkedMoby->mobyTag;
            newMoby->lowDrawDistance = 64;
            newMoby->highDrawDistance = 64;
            tag[0] = 400;
            tag[1] = linkedTag[5];
            copyDestination = &newMoby->position;
            copySource = &linkedMoby->position;
        copyInitialize47:
            func_8004F178(copyDestination, copySource);
            func_80055C24(newMoby);
        finishShared47:
            func_8003BABC(newMoby, 0, 0);
            return newMoby;
        }
    case 765:
        {
            Spawn47Tag765* tag = newMoby->mobyTag;
            Spawn47LinkedView* linkedTag = linkedMoby->mobyTag;
            int index, sine;
            Moby* child;
            *(short*)((unsigned char*)newMoby+0x38) = 256;
            tag->owner0 = linkedMoby;
            index = rand()&255;
            newMoby->position.x = D_80065920[index]*8;
            sine = D_800658A0[index];
            newMoby->position.z = 8192;
            newMoby->position.y = sine*8;
            func_8004F194(&newMoby->position, &newMoby->position, *(Vector3D**)((unsigned char*)linkedTag->data1C+0xC));
            func_80055C24(newMoby);
            newMoby->lowDrawDistance = 64;
            newMoby->unknown = -1;
            child = SpawnMoby(111, newMoby);
            tag->child4 = child;
            if(child)child->lowDrawDistance = 64;
            break;
        }
    case 964:
        func_8004F178(&newMoby->position, &spyro.position);
        func_80055D10(newMoby);
    clearDraw47:
        newMoby->unknown3[0] = 0;
        newMoby->lowDrawDistance = 0;
        newMoby->drawn = 0;
        break;
    case 1000:
        {
            Spawn47FactoryTag* tag = newMoby->mobyTag;
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
            sourceIndex = ((int*)linkedMoby->mobyTag)[3];
            if(sourceIndex >= 0) {
                Moby* sourceMoby = mobyArrayPtr+sourceIndex;
                int* owner = sourceMoby->mobyTag;
                tag->buffer4 = (int*)((unsigned char*)owner+(owner[0]+0x14));
                owner[0] += 0xEB0;
                if(owner[0] >= 0x4970)owner[0] = 0;
                func_8004E7AC(tag->buffer4, 0, 0xEB0);
                tag->word0 = 32;
                tag->word2 = 25;
                tag->word14 = 15;
                tag->word16 = 30;
                tag->parent10 = sourceMoby;
            }
            break;
        }
    case 1015:
        {
            Spawn47FactoryTag* tag = newMoby->mobyTag;
            int sourceIndex, state, yaw, z;
            func_8004F178(&newMoby->position, &linkedMoby->position);
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            func_80055D10(newMoby);
            newMoby->unknown3[0] = 0;
            newMoby->lowDrawDistance = 0;
            newMoby->drawn = 0;
            state = linkedMoby->substate;
            newMoby->updateDistance = 255;
            z = newMoby->position.z;
            newMoby->state = state;
            yaw = linkedMoby->angle.yaw;
            newMoby->position.z = z+256;
            newMoby->angle.yaw = yaw;
            sourceIndex = ((int*)linkedMoby->mobyTag)[3];
            if(sourceIndex >= 0) {
                Moby* sourceMoby = mobyArrayPtr+sourceIndex;
                int* owner = sourceMoby->mobyTag;
                tag->buffer4 = (int*)((unsigned char*)owner+(owner[0]+0x14));
                owner[0] += 0xEB0;
                if(owner[0] >= owner[2])owner[0] = 0;
                func_8004E7AC(tag->buffer4, 0, 0xEB0);
                tag->word0 = 200;
                tag->word2 = 200;
                tag->parent10 = sourceMoby;
            }
            break;
        }
    default:
    defaultSpawn47:
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
