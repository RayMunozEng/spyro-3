#include "matching.h"
#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "spu.h"
#include "hud.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

extern short D_80065920[], D_800658A0[];
extern int D_8006C648;
int func_8004E880(int, int, int);
int func_8003613C(int, int);
int func_8004F264(int, int);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003585C(Moby*, int, int, int, int, int);
int func_80035EE0(Moby*, int, int, int, int, int);
int func_80035DDC(Moby*, int, int, int, int);
int func_level_30_800837BC(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
                           int speed, int turnA, int turnB, int avoidA, int avoidB, int argA,
                           int argB, int flags) {
    register Moby* current __asm__("$19");
    register Vector3D* target __asm__("$20");
    register int range __asm__("$23");
    register int rate __asm__("$22");
    register int limit __asm__("$17");
    int avoid;
    register int angle __asm__("$18");
    register int error __asm__("$21");
    register int absolute __asm__("$2");
    register int distance __asm__("$3");
    register int initialHeading __asm__("$16");
    int result;
    register int lowAngle __asm__("$16");
    Vector3D destination;
    current = actor;
    MATCHING_KEEP(current);
    target = center;
    MATCHING_KEEP(target);
    range = radius;
    MATCHING_KEEP(range);
    initialHeading = heading;
    MATCHING_KEEP(initialHeading);
    rate = speed;
    MATCHING_KEEP(rate);
    limit = tolerance;
    avoid = avoidA;
    angle = func_8004E880(current->position.x - target->x, current->position.y - target->y, 0);
    error = func_8003613C(initialHeading, angle & 0xFF);
    distance = func_8004F334(&current->position, target);
    absolute = error;
    if (error < 0)
        absolute = -absolute;
    if (absolute < limit) {
        int radial = distance - range;
        if (radial < 0)
            radial = range - distance;
        if (radial < 0xC8)
            goto done;
    }
    if (avoid != 0xFF) {
        lowAngle = angle & 0xFF;
        if (func_8004F264(lowAngle, avoid) < 5) {
            result = func_8003613C(avoid, lowAngle);
            if (error < 0 && result < 0)
                return 0x100;
            if (error > 0 && result > 0)
                return 0x100;
        }
    }
    if (avoidB != 0xFF) {
        lowAngle = angle & 0xFF;
        if (func_8004F264(lowAngle, avoidB) < 5) {
            result = func_8003613C(avoidB, lowAngle);
            if (error < 0 && result < 0)
                return 0x100;
            if (error > 0 && result > 0)
                return 0x100;
        }
    }
    if (error < 0)
        angle += 3;
    else
        angle -= 3;
    {
        register int lookup __asm__("$3") = angle & 0xFF;
        register int x __asm__("$7");
        MATCHING_KEEP(lookup);
        {
            register int product __asm__("$2") = (D_80065920[lookup] * range) >> 12;
            x = target->x;
            MATCHING_KEEP2(product, x);
            x += product;
        }
        destination.x = x;
        destination.y = target->y + ((D_800658A0[lookup] * range) >> 12);
        heading = func_8004E880(x - current->position.x, destination.y - current->position.y, 0);
    }
    if (D_8006C648 == 3)
        rate += rate >> 1;
    else if (D_8006C648 == 4)
        rate <<= 1;
    if (flags & 8) {
        result = func_8004E880(target->x - current->position.x, target->y - current->position.y, 0);
        func_8003585C(current, result, turnA, 0, 0, 0);
        result = func_80035EE0(current, heading, rate, argA, argB, flags);
    } else {
        if (!func_8003585C(current, heading, turnA, turnB, 1, 0))
            goto done;
        result = func_80035DDC(current, rate, argA, argB, flags);
    }
    if (result)
        return -result;
done:
    return ABS(error);
}

/* Only the retail pointer array at +0x3C is described here. */
typedef struct {
    unsigned char reserved00[0x3C];
    unsigned char* frames[1];
} DecodedFrameTable;
extern DecodedFrameTable* D_8006EE2C[];
void func_level_30_80083AD8(Moby* moby, int increment, int* accumulator) {
    if (moby->animationState.id != moby->animationState.nextId) {
        *accumulator = 0;
    } else {
        *accumulator += increment;
        moby->animationState.frame =
            (*accumulator >> 4) % D_8006EE2C[moby->mobyClass]->frames[moby->animationState.id][0];
        moby->animationState.nextFrame =
            (moby->animationState.frame + 1) %
            D_8006EE2C[moby->mobyClass]->frames[moby->animationState.id][0];
        moby->animationProgress = *accumulator & 0xF;
    }
}

int func_level_30_80083BE8(Vector3D* position, int value, Moby* whirlwind) {
    int previousState = spyro.unk17c == 2;
    spyro.unk17a = 0x10000040;
    spyro.m_WhirlwindPointer = whirlwind;
    func_8004F178(&spyro.unk19, position);
    spyro.unk20[0] = value;
    return previousState;
}

int func_level_30_80083C5C(Vector3D* position) {
    int previousState = spyro.unk17c == 2;
    spyro.unk17a = 0x10000100;
    func_8004F178(&spyro.unk19, position);
    return previousState;
}

extern int D_8006C578, D_8006C574;
extern short D_80065920[], D_800658A0[];
extern unsigned char DecodedBatchPlayer[] __asm__("D_80070328");
void DecodedBatchZero(Vector3D*) __asm__("func_8004F168");
void DecodedBatchCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DecodedBatchAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedBatchRotate(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int DecodedBatchLength(Vector3D*, int) __asm__("func_8004EDE8");
void DecodedBatchScale(Vector3D*, int, int) __asm__("func_8004F08C");
void DecodedBatchMode(Moby*, int) __asm__("func_80055D24");
int DecodedBatchRandom(int, int) __asm__("func_8003636C");
int DecodedBatchAngle(int, int, int) __asm__("func_8004E880");
void DecodedBatchAnimation(Moby*, int) __asm__("func_80034F80");
int rand(void);
/* Rev 0 representative: level_10 0x80084418..0x80084B04.
 * Preserve the original signed divisions, halfword truncation, class/flag
 * branches and ordered random calls. Empty asm constraints emit no code;
 * they retain the original compiler's argument and temporary lifetimes.
 * AI generated; not yet human reviewed. See the batch provenance document.
 */
void func_level_30_80083CB0(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
                            int firstAnimation, int argument5) {
    Vector3D average;
    int reserved1C;
    Vector3D temporary;
    int reserved2C;
    Vector3D impulse;
    int reserved3C;
    struct {
        int childClass;
        int reserved44;
        Vector3D* offsets;
    } saved;
    int reservedStack[4];
    register int index __asm__("$19");
    register Moby* source __asm__("$18") = sourceMoby;
    register Moby* child __asm__("$17");
    register short* tag __asm__("$16");
    register Vector3D* temporaryPtr __asm__("$20");
    register unsigned char* player __asm__("$22");
    register short* sine __asm__("$23");
    short* cosine;
    Vector3D* cursor;
    int averageX, averageY, averageZ;
    int randomLow, randomHigh, angle;
    register int impulseX __asm__("$3");
    register int sample0 __asm__("$2");
    register int sample4 __asm__("$4");
    register short* samplePointer __asm__("$4");
    register unsigned int trigByteOffset __asm__("$4");
    register Vector3D* averageArgument __asm__("$4");
    register int offsetArgument __asm__("$5");
    register Vector3D* copyArgument __asm__("$4");
    register Vector3D* offsetBase __asm__("$8");
    register int stackArgument4 __asm__("$8");
    register unsigned int stackArgument5 __asm__("$8");
    MATCHING_KEEP(source);
    averageArgument = &average;
    MATCHING_OBSERVE(averageArgument);
    saved.childClass = childClass;
    saved.offsets = offsets;
    DecodedBatchZero(averageArgument);
    __asm__("" : "=m"(saved) : "m"(saved));
    index = 0;
    if (count > 0) {
        cursor = saved.offsets;
        do {
            DecodedBatchAdd(&average, &average, cursor);
            index++;
            cursor++;
        } while (index < count);
    }
    /* Native division retains the retail zero and overflow traps. */
    averageX = average.x / count;
    averageY = average.y / count;
    averageZ = average.z / count;
    average.x = averageX;
    average.y = averageY;
    average.z = averageZ;
    {
        register int modeArgument __asm__("$5") = 4;
        __asm__("" : "=r"(index) : "0"(0), "r"(modeArgument));
        DecodedBatchMode(source, modeArgument);
    }
    temporaryPtr = &temporary;
    if (count <= 0)
        return;
    cosine = D_80065920;
    sine = D_800658A0;
    player = DecodedBatchPlayer;
    __asm__("" : "=r"(cosine) : "0"(cosine), "r"(sine), "r"(player), "r"(temporaryPtr));
    do {
        /* Capacity exhaustion ends the whole spawn request. */
        if (D_8006C578 - D_8006C574 < 21)
            return;
        __asm__("" : "=m"(saved) : "m"(saved));
        child = SpawnMoby(saved.childClass, source);
        MATCHING_KEEP(child);
        copyArgument = temporaryPtr;
        if (child != 0) {
            offsetArgument = index * 12;
            __asm__("" : "=r"(offsetArgument) : "0"(offsetArgument), "r"(copyArgument));
            offsetBase = saved.offsets;
            tag = child->mobyTag;
            DecodedBatchCopy(copyArgument, (Vector3D*)((char*)offsetBase + offsetArgument));
            DecodedBatchRotate(&source->rotationMatrix, temporaryPtr, temporaryPtr);
            tag[0] = (temporary.x - average.x) >> 2;
            tag[1] = (temporary.y - average.y) >> 2;
            tag[2] = (temporary.z - average.z) >> 2;
            DecodedBatchAdd(&child->position, temporaryPtr, &source->position);
            if (source->mobyClass == 254) {
                child->size = 20;
                child->position.z += 1000;
                tag[0] = (unsigned short)tag[0] + ((cosine[source->unkb] * 5) >> 8);
                tag[1] = (unsigned short)tag[1] + ((sine[source->unkb] * 5) >> 8);
                randomLow = 250;
                randomHigh = 350;
                goto randomZ;
            } else if (source->mobyClass == 132) {
                tag[0] = tag[0] * 3 / 2;
                tag[1] = tag[1] * 3 / 2;
                tag[2] = tag[2] * 2;
                goto finish;
            } else if (source->mobyClass == 999) {
                if (*(int*)(DecodedBatchPlayer + 0x48) == 42) {
                    DecodedBatchCopy(temporaryPtr, (Vector3D*)(DecodedBatchPlayer + 0x8C));
                    DecodedBatchScale(temporaryPtr, DecodedBatchLength(temporaryPtr, 0), 300);
                    tag[0] = (unsigned short)tag[0] + temporary.x;
                    tag[1] = (unsigned short)tag[1] + temporary.y;
                } else {
                    temporary.x = 140;
                    temporary.y = 0;
                    temporary.z = 0;
                    /* The original class-999 branch passes a null matrix. */
                    DecodedBatchRotate(0, temporaryPtr, temporaryPtr);
                    tag[0] = (unsigned short)tag[0] + temporary.x;
                    tag[1] = (unsigned short)tag[1] + temporary.y;
                    tag[2] = (unsigned short)tag[2] + temporary.z;
                }
                goto finish;
            } else if (source->unkb != 0 && (source->damageFlags & 0x100000)) {
                tag[0] = (unsigned short)tag[0] + ((cosine[source->unkb] * 75) >> 11);
                tag[1] = (unsigned short)tag[1] + ((sine[source->unkb] * 75) >> 11);
                randomLow = 40;
                randomHigh = 70;
            randomZ:
                tag[2] = (unsigned short)tag[2] + DecodedBatchRandom(randomLow, randomHigh);
                goto finish;
            } else if (source->damageFlags & 0x40000) {
                tag[0] = (unsigned short)tag[0] + (*(int*)(DecodedBatchPlayer + 0x8C) >> 5);
                tag[1] = (unsigned short)tag[1] + (*(int*)(DecodedBatchPlayer + 0x90) >> 5);
                goto finish;
            } else if (source->damageFlags & 0x2000000) {
                sample0 = cosine[DecodedBatchAngle(child->position.x - *(int*)player,
                                                   child->position.y - *(int*)(player + 4), 0)];
                MATCHING_KEEP(sample0);
                impulse.x = sample0 >> 4;
                sample0 = sine[DecodedBatchAngle(child->position.x - *(int*)player,
                                                 child->position.y - *(int*)(player + 4), 0)];
                MATCHING_KEEP(sample0);
                impulseX = impulse.x;
                impulse.y = sample0 >> 4;
                impulse.z = 0;
                __asm__("" : : "m"(impulse.z), "r"(impulseX));
            } else if ((source->damageFlags & 0x20000) &&
                       (*(int*)(DecodedBatchPlayer + 0x50) == 4 ||
                        *(int*)(DecodedBatchPlayer + 0x50) == 12)) {
                tag[0] = (unsigned short)tag[0] + (*(int*)(DecodedBatchPlayer + 0x8C) >> 6);
                tag[1] = (unsigned short)tag[1] + (*(int*)(DecodedBatchPlayer + 0x90) >> 6);
                goto finish;
            } else {
                if (source->mobyClass == 132)
                    goto finish;
                angle = source->unkb;
                if (angle == 0)
                    angle = DecodedBatchAngle(child->position.x - *(int*)player,
                                              child->position.y - *(int*)(player + 4), 0);
                trigByteOffset = angle * 2;
                MATCHING_KEEP(trigByteOffset);
                sample0 = *(short*)(trigByteOffset + (unsigned int)cosine);
                __asm__("" : "=r"(trigByteOffset) : "0"(trigByteOffset), "r"(sample0));
                samplePointer = (short*)(trigByteOffset + (unsigned int)sine);
                MATCHING_KEEP2(sample0, samplePointer);
                impulseX = (sample0 * 35) >> 10;
                impulse.x = impulseX;
                sample4 = *samplePointer;
                MATCHING_KEEP(sample4);
                impulse.y = (sample4 * 35) >> 10;
                impulse.z = 0;
                __asm__("" : : "m"(impulse.z), "r"(impulseX));
            }
            tag[0] = (unsigned short)tag[0] + impulseX;
            tag[1] = (unsigned short)tag[1] + impulse.y;
        finish:
            child->angle.roll = source->angle.roll;
            child->angle.pitch = source->angle.pitch;
            child->angle.yaw = source->angle.yaw;
            /* Keep the random calls in their original order. */
            tag[3] = (rand() & 6) - 3;
            tag[4] = (rand() & 6) - 3;
            tag[5] = (rand() & 6) - 3;
            tag[7] = source->position.z - 64;
            {
                int lifetime = DecodedBatchRandom(30, 50);
                register int animationArgument __asm__("$5");
                __asm__(""
                        : "=m"(firstAnimation), "=m"(argument5)
                        : "m"(firstAnimation), "m"(argument5));
                stackArgument4 = *(int*)&firstAnimation;
                tag[6] = lifetime;
                tag[8] = 8;
                animationArgument = stackArgument4 + index;
                stackArgument5 = *(unsigned short*)&argument5;
                MATCHING_KEEP(stackArgument5);
                tag[9] = stackArgument5;
                DecodedBatchAnimation(child, animationArgument);
            }
            *(int*)(tag + 10) = 1;
            child->unknownCollision = 0;
        }
        index++;
    } while (index < count);
}

typedef struct {
    short count, index, reserved04[3], step;
    unsigned char* records;
} DecodedSteerPath;
typedef struct {
    int speed, roll, pitch, yaw;
    int rollStep, pitchStep, yawStep, rollCoupling, rollLimit;
} DecodedSteerMotion;
void DecodedSteerSubtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
int DecodedSteerLength(Vector3D*, int) __asm__("func_8004EDE8");
int DecodedSteerAngle(int, int, int) __asm__("func_8004E880");
void DecodedSteerPrepare(Moby*, int) __asm__("func_80055D24");
void DecodedSteerRotate(SHORTMATRIX*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
void DecodedSteerAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
/*
 * USA SCUS-94467 Rev 0: representative func_level_15_800832AC,
 * 0x800832AC..0x80083604 (214 words). Per-copy original sources and
 * word digests are recorded in overlay-batch-2026-10-04-1315.md.
 * Keep the original signed record-index remainder, wrapped 12-bit
 * angular words, signed shifts and low-word product. Byte-angle writes
 * use the original right shift by 4; vector/helper domains remain raw.
 * Empty asm constraints emit no instructions and retain the compiler's
 * register lifetimes and intermediate arithmetic destinations.
 * AI-generated reconstruction; not yet human reviewed. Caller cadence,
 * source table producers and browser/runtime interpretation are unresolved.
 */
void func_level_30_800843A0(Moby* mobyArgument, DecodedSteerPath* pathArgument,
                            DecodedSteerMotion* motionArgument) {
    Vector3D vector;
    int reserved1C;
    register Moby* moby __asm__("$19") = mobyArgument;
    register DecodedSteerPath* path __asm__("$16");
    register DecodedSteerMotion* motion __asm__("$17");
    register Vector3D* position __asm__("$18");
    register int error __asm__("$6");
    register int product __asm__("$7");
    MATCHING_KEEP(moby);
    path = pathArgument;
    MATCHING_KEEP(path);
    motion = motionArgument;
    MATCHING_KEEP(motion);
    position = &moby->position;
    /* The first difference is used for the original 1024 distance test. */
    DecodedSteerSubtract(&vector, position, (Vector3D*)(path->records + path->index * 16));
    if (DecodedSteerLength(&vector, 1) < 1024) {
        path->index = (path->index + path->step + path->count) % path->count;
    }
    DecodedSteerSubtract(&vector, (Vector3D*)(path->records + path->index * 16), position);
    error = (DecodedSteerAngle(vector.x, vector.y, 1) - motion->yaw) & 0xFFF;
    if (error > 2048)
        error -= 4096;
    /* A heading difference greater than 800 advances the record once more. */
    {
        register int magnitude __asm__("$2") = error;
        if (error < 0)
            magnitude = -magnitude;
        MATCHING_KEEP(magnitude);
        if (magnitude > 800) {
            path->index = (path->index + path->step + path->count) % path->count;
            DecodedSteerSubtract(&vector, (Vector3D*)(path->records + path->index * 16), position);
            error = (DecodedSteerAngle(vector.x, vector.y, 1) - motion->yaw) & 0xFFF;
            if (error > 2048)
                error -= 4096;
        }
    }
    /* Retain the distinct yaw and roll/pitch integration equations. */
    {
        register int step __asm__("$4") = motion->yawStep;
        register int angle __asm__("$3") = motion->yaw;
        step += ((error - step * 9) * 2) >> 6;
        angle = (angle + step) & 0xFFF;
        motion->yaw = angle;
        motion->yawStep = step;
        moby->angle.yaw = angle >> 4;
    }
    {
        register int gain __asm__("$2") = motion->rollCoupling;
        gain = -gain;
        MATCHING_KEEP(gain);
        product = gain * error;
        {
            register int roll __asm__("$2") = motion->roll;
            error = product >> 6;
            roll = error - roll;
            MATCHING_KEEP(roll);
            error = roll & 0xFFF;
        }
    }
    if (error > 2048)
        error -= 4096;
    {
        register int step __asm__("$4") = motion->rollStep;
        register int change __asm__("$3") = (error * 2 - step * 24) >> 6;
        MATCHING_KEEP(change);
        step += change;
        motion->rollStep = step;
        motion->roll = (motion->roll + step) & 0xFFF;
        if (motion->roll > 2048)
            motion->roll -= 4096;
    }
    /* Clamp the signed roll word with the original fresh field reads. */
    if (motion->roll > motion->rollLimit)
        motion->roll = motion->rollLimit;
    if (motion->roll < -motion->rollLimit)
        motion->roll = -motion->rollLimit;
    moby->angle.roll = motion->roll >> 4;
    error =
        (DecodedSteerAngle(DecodedSteerLength(&vector, 0), vector.z, 1) - motion->pitch) & 0xFFF;
    if (error > 2048)
        error -= 4096;
    {
        register int step __asm__("$5") = motion->pitchStep;
        register int change __asm__("$3") = (error * 2 - step * 24) >> 6;
        MATCHING_KEEP(change);
        step += change;
        motion->pitchStep = step;
        motion->pitch = (motion->pitch + step) & 0xFFF;
        moby->angle.pitch = motion->pitch >> 4;
    }
    /* Prepare, rotate and add the original local forward vector. */
    vector.x = motion->speed;
    vector.y = 0;
    vector.z = 0;
    DecodedSteerPrepare(moby, 6);
    DecodedSteerRotate(&moby->rotationMatrix, &vector, &vector);
    DecodedSteerAdd(&moby->position, &moby->position, &vector);
}

void func_level_30_800846F8(HudEntry* hud) {
    int frame, height;
    SpriteData* sprite;
    func_80027D60(hud);
    hud->unk3D = 0x18;
    frame = D_8006C738[func_80027934(7)].frame;
    sprite = &D_8006C788[frame];
    hud->unk4C = frame;
    hud->unk3C = sprite->unk4 - sprite->unk0;
    height = hud->unk3D + (sprite->unk5 - sprite->unk1);
    hud->unk3D = height;
    sprite = &D_8006C788[hud->unk4C + 2];
    height += (sprite->unk5 - sprite->unk1) * 6;
    hud->unk3D = height;
    sprite = &D_8006C788[hud->unk4C + 1];
    height += sprite->unk5 - sprite->unk1;
    hud->unk3D = height;
}

extern int* DecodedDrawClipped(SpriteData*, int, int, int) __asm__("func_80028D30");
int func_level_30_800847F0(HudEntry* hud) {
    Vector3D position;
    register SpriteData* sprite __asm__("$18");
    SpriteData* previous;
    register SpriteData* sprites __asm__("$4");
    register int firstRight __asm__("$6");
    register int firstLeft __asm__("$5");
    register int oldTop __asm__("$3");
    register int oldBottom __asm__("$7");
    register int secondBottom __asm__("$5");
    register int drawX __asm__("$5");
    register int drawY __asm__("$6");
    int secondRight, secondLeft;
    register SpriteData* firstDraw __asm__("$4");
    register int baseIndex __asm__("$2");
    register int frameIndex __asm__("$3");
    register int x __asm__("$2");
    register int y __asm__("$3");
    register int width __asm__("$17");
    int height, remaining, fill, index;
    register int endIndex __asm__("$2");
    register int clipFlags __asm__("$7");
    register SpriteData* endBase __asm__("$3");
    /* Empty constraints retain retail allocation and ordering; emit no instructions. */
    x = hud->unk0;
    y = hud->unk2;
    MATCHING_KEEP2(x, y);
    position.x = x;
    position.y = y;
    if (*(unsigned char*)&hud->movementFrame)
        position.z = (*(unsigned char*)&hud->movementFrame + 10) >> 1;
    else
        position.z = 0;
    func_80029674(hud, &position.x, &position.y);
    func_80029708(hud, &position.z, &position.x, &position.y);
    /* Select the original sprite records and retain their byte dimensions. */
    baseIndex = hud->unk4C;
    sprites = D_8006C788;
    frameIndex = (unsigned char)hud->unk1C.frame;
    MATCHING_KEEP3(baseIndex, sprites, frameIndex);
    sprite = &sprites[baseIndex];
    MATCHING_KEEP(sprite);
    firstRight = sprite->unk4;
    frameIndex *= sizeof(SpriteData);
    firstLeft = sprite->unk0;
    MATCHING_KEEP2(firstRight, firstLeft);
    sprite = (SpriteData*)((char*)sprites + frameIndex);
    MATCHING_KEEP(sprite);
    firstDraw = sprite;
    MATCHING_KEEP(firstDraw);
    secondRight = sprite->unk4;
    secondLeft = sprite->unk0;
    MATCHING_KEEP2_CLOBBER(firstRight, firstLeft, "memory");
    width = firstRight - firstLeft;
    MATCHING_KEEP(width);
    width = (width - (secondRight - secondLeft)) >> 1;
    MATCHING_KEEP_CLOBBER(width, "memory");
    position.y += 22 - (sprite->unk5 - sprite->unk1);
    func_800289C8(firstDraw, position.x + width, position.y);
    baseIndex = hud->unk4C;
    drawX = position.x;
    oldTop = sprite->unk5;
    sprites = D_8006C788;
    oldBottom = sprite->unk1;
    drawY = position.y;
    MATCHING_KEEP5_CLOBBER(baseIndex, sprites, oldTop, oldBottom, drawX, "memory");
    sprite = &sprites[baseIndex];
    firstDraw = sprite;
    MATCHING_KEEP(firstDraw);
    drawY += 2;
    MATCHING_KEEP2(drawY, oldTop);
    oldTop -= oldBottom;
    drawY += oldTop;
    position.y = drawY;
    func_800289C8(firstDraw, drawX, drawY);
    baseIndex = hud->unk4C;
    oldTop = sprite->unk5;
    sprites = D_8006C788;
    secondBottom = sprite->unk1;
    MATCHING_KEEP4(baseIndex, sprites, oldTop, secondBottom);
    sprite = &sprites[baseIndex + 2];
    position.y += oldTop - secondBottom;
    height = sprite->unk5 - sprite->unk1;
    /* Six segments; signed division and the original trap paths are retained. */
    remaining = height * 6;
    fill = *hud->unk28 * remaining / hud->unk26;
    remaining -= height;
    for (index = 0; index < 6; index++) {
        if (fill >= remaining)
            break;
        func_800289C8(sprite, position.x, position.y);
        remaining -= height;
        position.y += height;
    }
    /* Two clipped draws split the transition between sprite records. */
    fill -= remaining;
    DecodedDrawClipped(sprite, position.x, position.y, ((fill - height) << 16) | 8);
    clipFlags = ((height - fill) << 16) | 8;
    drawX = position.x;
    endIndex = hud->unk4C;
    MATCHING_KEEP2_VOLATILE_CLOBBER(clipFlags, drawX, "memory");
    drawY = position.y;
    endBase = D_8006C788;
    MATCHING_KEEP4(endIndex, endBase, drawX, drawY);
    sprite = &endBase[endIndex + 3];
    DecodedDrawClipped(sprite, drawX, drawY, clipFlags);
    goto advance;
    do {
        func_800289C8(sprite, position.x, position.y);
    advance:
        position.y += height;
        index++;
        MATCHING_BARRIER_VOLATILE("memory");
    } while (index < 6);
    func_800289C8(&D_8006C788[hud->unk4C + 1], position.x, position.y);
    return 0;
}

void func_level_30_80084AC0(HudEntry* hud) {
    int value, step;
    func_80027A60(hud);
    value = *hud->unk28;
    step = value / 30;
    if (step < hud->unk50 && value != 0 && (step < 8 || (step < 16 && (step & 1)))) {
        PlaySound(D_8006C654->timerRunOut, 0, 0);
    }
    hud->unk50 = step;
    if (*hud->unk28 == 0)
        func_80028154(hud->unk1A);
}

typedef struct {
    Vector3D position;
    int reserved0C;
} DecodedBlendPoint;
typedef struct {
    short count, index;
    short reserved04[3], step;
    DecodedBlendPoint* points;
} DecodedBlendPath;
typedef struct {
    short current, previous;
} DecodedBlendWeight;
extern DecodedBlendWeight DecodedBlendWeights[] __asm__("D_80066F0C");
extern DecodedBlendWeight DecodedSingleWeight __asm__("D_8006C410");
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004F1FC(Vector3D*, Vector3D*, int);
void func_8004F110(Vector3D*, int);
int func_8004EDE8(Vector3D*, int);
void func_80037014(Moby*);
void func_80055D24(Moby*, int);
int func_level_30_80084B84(Moby* moby, DecodedBlendPath* path, Vector3D* previous, int* timer,
                           int period, int flags) {
    struct {
        Vector3D delta;
        int reserved1C;
        Vector3D weightedPrevious;
        int reserved2C;
    } work;
    DecodedBlendWeight* weights;
    int threshold;
    int result = 0;
    int flat;
    /* Retail selects weight-table blocks by the supplied period. */
    if (period >= 9) {
        weights = DecodedBlendWeights + 10;
        threshold = 7;
    } else if (period >= 7) {
        weights = DecodedBlendWeights + 4;
        threshold = 5;
    } else if (period >= 5) {
        weights = DecodedBlendWeights;
        threshold = 3;
    } else {
        weights = &DecodedSingleWeight;
        threshold = 1;
    }
    if (*timer >= period) {
        short next;
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        func_8004F178(previous, &work.delta);
        next = (path->index + path->step + path->count) % path->count;
        path->index = next;
        result = 1;
        if ((path->step < 0 && next == path->count - 1) || (path->step > 0 && next == 0))
            result |= 2;
        *timer = 0;
    } else if (*timer > threshold) {
        int divisor;
        register int elapsed __asm__("$2");
        register int x __asm__("$4"), y __asm__("$3"), z __asm__("$2");
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        /* Empty constraints retain the original subtraction and division allocation. */
        elapsed = *timer - 1;
        MATCHING_KEEP(elapsed);
        divisor = period - elapsed;
        x = work.delta.x / divisor;
        y = work.delta.y / divisor;
        z = work.delta.z / divisor;
        MATCHING_KEEP3(x, y, z);
        work.delta.x = x;
        work.delta.y = y;
        work.delta.z = z;
        (*timer)++;
    } else {
        int divisor;
        register int elapsed __asm__("$2");
        register int x __asm__("$4"), y __asm__("$3"), z __asm__("$2");
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        /* Empty constraints retain the original subtraction and division allocation. */
        elapsed = *timer - 1;
        MATCHING_KEEP(elapsed);
        divisor = period - elapsed;
        x = work.delta.x / divisor;
        y = work.delta.y / divisor;
        z = work.delta.z / divisor;
        MATCHING_KEEP3(x, y, z);
        work.delta.x = x;
        work.delta.y = y;
        work.delta.z = z;
        func_8004F1FC(&work.delta, &work.delta, weights[*timer].current);
        func_8004F1FC(&work.weightedPrevious, previous, weights[*timer].previous);
        func_8004F194(&work.delta, &work.delta, &work.weightedPrevious);
        func_8004F110(&work.delta, 10);
        (*timer)++;
    }
    /* Bit 2 clears the vertical displacement and gates the extra actor helper. */
    flat = flags & 4;
    if (flat)
        work.delta.z = 0;
    moby->angle.yaw = func_8004E880(work.delta.x, work.delta.y, 0);
    moby->angle.pitch = -func_8004E880(work.delta.z, func_8004EDE8(&work.delta, 0), 0) + 0x40;
    func_8004F194(&moby->position, &moby->position, &work.delta);
    if (flat)
        func_80037014(moby);
    func_80055D24(moby, 2);
    return result;
}

typedef struct {
    short packetIndex, selector;
    int x, y, z;
    int nextX, nextY, nextZ;
} DecodedPackedPosition;
extern int D_8006C77C;
extern DecodedPackedPosition* D_8006C724;
extern unsigned int** D_8006D048;
void func_level_30_80084F8C(int selectorArg, Vector3D* positionArg) {
    register Vector3D* position __asm__("$10") = positionArg;
    register int selector __asm__("$13") = selectorArg;
    register int index __asm__("$12");
    register unsigned int byteOffset __asm__("$11");
    int reservedStack[2];
    /* Empty constraints preserve retail allocation and emit no instructions. */
    MATCHING_KEEP(position);
    MATCHING_KEEP(selector);
    index = 0;
    if (D_8006C77C > 0) {
        byteOffset = 0;
        do {
            DecodedPackedPosition* entry =
                (DecodedPackedPosition*)(byteOffset + (unsigned int)D_8006C724);
            if (entry->selector == (selector & 255)) {
                register unsigned int mask __asm__("$7") = 0x1FFFF;
                register unsigned int* packet __asm__("$6");
                int nextX;
                int offsetZ;
                unsigned int preservedHalf;
                unsigned int packedXY;
                register DecodedPackedPosition* firstEntry __asm__("$5");
                int nextZ;
                unsigned int packetFlags;
                int firstZ;
                register unsigned int retainedWord __asm__("$8");
                MATCHING_KEEP(mask);
                packet = D_8006D048[entry->packetIndex];
                nextX = entry->nextX;
                offsetZ = position->z >> 4;
                packedXY = ((nextX + (position->x >> 4)) << 16) |
                           ((entry->nextY + (position->y >> 4)) & 65535);
                preservedHalf = *(unsigned short*)((char*)packet + 4);
                nextZ = entry->nextZ;
                packet[0] = packedXY;
                preservedHalf |= (nextZ + offsetZ) << 16;
                /* Retail rereads the table base between these packet stores. */
                firstEntry = D_8006C724;
                packetFlags = packet[3];
                MATCHING_BARRIER_VOLATILE("memory");
                firstEntry = (DecodedPackedPosition*)(byteOffset + (unsigned int)firstEntry);
                MATCHING_KEEP2_CLOBBER(firstEntry, preservedHalf, "memory");
                __asm__ volatile("" : "=r"(retainedWord) : "0"(packedXY));
                packet[1] = preservedHalf;
                /* Preserve the low 17 bits when packing the first Z value. */
                preservedHalf = packetFlags & mask;
                packedXY = ((firstEntry->x + (position->x >> 4)) << 16) |
                           ((firstEntry->y + (position->y >> 4)) & 65535);
                firstZ = firstEntry->z + (position->z >> 5);
                packet[2] = packedXY;
                preservedHalf |= firstZ << 17;
                packet[3] = preservedHalf;
            }
            byteOffset += 28;
        } while (++index < D_8006C77C);
    }
}
