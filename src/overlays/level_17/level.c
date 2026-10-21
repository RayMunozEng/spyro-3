#include "matching.h"
#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
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
int func_level_17_8007F3E8(Moby* actor, Vector3D* center, int radius, int heading, int tolerance,
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

int func_level_17_8007F704(Vector3D* position, int value, Moby* whirlwind) {
    int previousState = spyro.unk17c == 2;
    spyro.unk17a = 0x10000040;
    spyro.m_WhirlwindPointer = whirlwind;
    func_8004F178(&spyro.unk19, position);
    spyro.unk20[0] = value;
    return previousState;
}

int func_level_17_8007F778(Vector3D* position) {
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
void func_level_17_8007F7CC(int count, int childClass, Moby* sourceMoby, Vector3D* offsets,
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

/*
 * USA SCUS-94467 Rev 0: representative func_level_11_80086468,
 * 0x80086468..0x800869E4 (352 instructions). Per-copy evidence is
 * recorded in overlay-batch-2026-10-04-1268.md.
 * Packet fields follow the retail store offsets, including byte colour
 * truncation and signed halfword coordinates. Empty asm constraints emit
 * no instructions; they retain GCC 2.7.2 register allocation/store order.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct {
    unsigned int tag;
    unsigned char red, green, blue, code;
    short x0, y0, x1, y1;
} DecodedHudLine;
typedef struct {
    unsigned int tag;
    unsigned char red0, green0, blue0, code;
    short x0, y0;
    unsigned char red1, green1, blue1, reserved0F;
    short x1, y1;
    unsigned char red2, green2, blue2, reserved17;
    short x2, y2;
    unsigned char red3, green3, blue3, reserved1F;
    short x3, y3;
} DecodedHudQuad;
extern unsigned char* DecodedHudPacketCursor __asm__("D_8006C664");
int DecodedHudSprite(SpriteData*, int, int) __asm__("func_800289C8");
int func_level_17_8007FEBC(HudEntry* argument) {
    int x, y, verticalOffset, reserved1C, barY, reserved24;
    HudEntry* hud = argument;
    register int top __asm__("$20");
    register int bottom __asm__("$17");
    register unsigned int lineTag __asm__("$18");
    register int lineCode __asm__("$19");
    register int colour __asm__("$16");
    register DecodedHudLine* line __asm__("$22");
    register DecodedHudLine* lineArgument __asm__("$4");
    register SpriteData* sprite __asm__("$23");
    register DecodedHudQuad* quad __asm__("$19");
    register DecodedHudQuad* quadArgument __asm__("$4");
    register int width __asm__("$21");
    register int result __asm__("$3");
    register int centredY __asm__("$16");
    register int* xArgument __asm__("$5") = &x;
    register int* yArgument __asm__("$6");
    MATCHING_OBSERVE(xArgument);
    {
        register int frame __asm__("$2") = (unsigned char)hud->unk1C.frame;
        register int initialX __asm__("$3");
        register int initialY __asm__("$7");
        register SpriteData* sprites __asm__("$3");
        MATCHING_KEEP(frame);
        initialX = hud->unk0;
        initialY = hud->unk2;
        MATCHING_OBSERVE2_CLOBBER(initialX, initialY, "$6");
        yArgument = &y;
        MATCHING_OBSERVE3(initialX, initialY, yArgument);
        x = initialX;
        sprites = D_8006C788;
        __asm__("" : "=r"(frame) : "0"(frame), "r"(sprites));
        frame *= 8;
        MATCHING_KEEP(frame);
        y = initialY;
        __asm__ volatile("" : : "m"(y));
        sprite = (SpriteData*)((int)sprites + frame);
    }
    /* Apply the existing HUD position and movement helpers. */
    func_80029674(hud, xArgument, yArgument);
    if ((unsigned char)hud->movementFrame) {
        verticalOffset = ((unsigned char)hud->movementFrame + 10) >> 1;
    } else {
        verticalOffset = 0;
    }
    func_80029708(hud, &verticalOffset, &x, &y);
    {
        register int height __asm__("$2") = sprite->unk5;
        register int low __asm__("$3") = sprite->unk1;
        register int storedY __asm__("$3");
        MATCHING_OBSERVE2(height, low);
        height -= low;
        MATCHING_KEEP(height);
        storedY = y;
        centredY = storedY - (height >> 1);
        y = centredY;
    }
    /* Select the retail bar origin from the sprite bounds. */
    if (hud->displayMode & 1) {
        centredY++;
        MATCHING_KEEP(centredY);
        barY = centredY;
    } else {
        register int edge __asm__("$2") = centredY + sprite->unk5;
        edge -= sprite->unk1;
        edge -= 7;
        MATCHING_KEEP(edge);
        barY = edge;
    }
    /* Bit 3 places the bordered bar before the sprite. */
    if (hud->displayMode & 8) {
        lineCode = 64;
        colour = 192;
        lineTag = 0x03000000;
        line = (DecodedHudLine*)DecodedHudPacketCursor;
        top = barY - 1;
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(line);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->y0 = top;
        MATCHING_BARRIER_VOLATILE("memory");
        bottom = barY + 6;
        MATCHING_KEEP(bottom);
        line->y1 = bottom;
        line->x1 = x + 96;
        line->x0 = x + 96;
        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->y1 = bottom;
        line->y0 = bottom;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(lineArgument);
        line++;
        MATCHING_KEEP(line);
        {
            register DecodedHudLine* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            MATCHING_KEEP(lastLine);
            lastLine->code = lineCode;

            lastLine->red = colour;
            lastLine->green = colour;
            lastLine->blue = 0;
            MATCHING_BARRIER_VOLATILE("memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (DecodedHudQuad*)(lastLine + 1);
            MATCHING_KEEP(quad);
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = bottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        /* Four border lines are followed by one gradient quad. */
        quad->tag = 0x08000000;
        quad->code = 56;
        {
            int channel = -32 - hud->unk40 * 224 / 96;
            MATCHING_KEEP(channel);
            quad->red0 = quad->red2 = channel;
            __asm__ volatile("" : : "m"(quad->red0), "m"(quad->red2));
        }
        {
            register int numerator __asm__("$3") = hud->unk40 * 224;
            int greenChannel;
            __asm__("" : "=r"(quad) : "0"(quad), "r"(numerator));
            greenChannel = numerator / 96;
            quad->blue0 = quad->blue2 = 0;
            quad->green1 = quad->green3 = 0;
            quad->blue1 = quad->blue3 = 0;
            MATCHING_KEEP(quad);
            quadArgument = quad;
            MATCHING_OBSERVE(quadArgument);
            quad->red1 = quad->red3 = 224;
            quad->green0 = quad->green2 = greenChannel;
        }
        MATCHING_BARRIER_VOLATILE("memory");
        {
            register int value __asm__("$3") = hud->unk40;
            register int barCoordinate __asm__("$2");
            register int coordinate __asm__("$2");
            MATCHING_BARRIER_VOLATILE("memory");
            barCoordinate = (unsigned short)barY;
            MATCHING_KEEP(barCoordinate);
            quad->y2 = quad->y3 = bottom;
            quad->y0 = quad->y1 = barCoordinate;
            MATCHING_BARRIER_VOLATILE("memory");
            coordinate = x;
            __asm__("" : "=r"(value) : "0"(value), "r"(coordinate));
            value -= 96;
            value = coordinate - value;
            MATCHING_KEEP(value);
            coordinate += 96;
            quad->x0 = quad->x2 = value;
            quad->x1 = quad->x3 = coordinate;
            func_8004E758(quadArgument);
        }
        quad++;
        DecodedHudPacketCursor = (unsigned char*)quad;
        x += 106;
        DecodedHudSprite(sprite, x, y);
        {
            register int spriteWidth __asm__("$2") = sprite->unk4;
            register int left __asm__("$3") = sprite->unk0;
            MATCHING_OBSERVE2(spriteWidth, left);
            spriteWidth -= left;
            MATCHING_KEEP(spriteWidth);
            result = spriteWidth + 106;
        }
    } else {
        /* The other branch draws the sprite before the bordered bar. */
        register int defaultColour __asm__("$17");
        register int defaultBottom __asm__("$16");
        {
            register SpriteData* spriteArgument __asm__("$4") = sprite;
            register int callX __asm__("$5");
            int origin;
            register int callY __asm__("$6");
            MATCHING_OBSERVE(spriteArgument);
            callX = x;
            MATCHING_KEEP(callX);
            origin = barY;
            callY = y;
            top = origin - 1;
            DecodedHudSprite(spriteArgument, callX, callY);
        }
        lineCode = 64;
        defaultColour = 192;
        lineTag = 0x03000000;
        MATCHING_OBSERVE3(lineCode, defaultColour, lineTag);
        width = sprite->unk4;
        MATCHING_KEEP(width);
        {
            register int left __asm__("$2") = sprite->unk0;
            line = (DecodedHudLine*)DecodedHudPacketCursor;
            __asm__("" : "=r"(left) : "0"(left), "r"(line));
            width -= left;
        }
        {
            register int currentX __asm__("$2") = x;
            register int offset __asm__("$3");
            __asm__("" : "=r"(width) : "0"(width), "r"(currentX));
            offset = width + 10;
            MATCHING_KEEP(offset);
            x = currentX + offset;
        }

        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(line);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->y0 = top;
        MATCHING_BARRIER_VOLATILE("memory");
        defaultBottom = barY + 6;
        MATCHING_KEEP(defaultBottom);
        line->y1 = defaultBottom;
        line->x1 = x + 96;
        line->x0 = x + 96;
        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        MATCHING_KEEP(lineArgument);
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->y1 = defaultBottom;
        line->y0 = defaultBottom;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(lineArgument);
        line++;
        MATCHING_KEEP(line);
        {
            register DecodedHudLine* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            MATCHING_KEEP(lastLine);
            lastLine->code = lineCode;

            lastLine->red = 0;
            lastLine->green = 0;
            lastLine->blue = defaultColour;
            MATCHING_BARRIER_VOLATILE("memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (DecodedHudQuad*)(lastLine + 1);
            MATCHING_KEEP(quad);
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = defaultBottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        /* Four border lines are followed by one gradient quad. */
        quad->tag = 0x08000000;
        quad->code = 56;
        quad->red0 = quad->red2 = 224;
        quad->green0 = quad->green2 = 0;
        quad->blue0 = quad->blue2 = 0;
        {
            int channel = -32 - hud->unk40 * 224 / 96;
            MATCHING_KEEP(channel);
            quad->red1 = quad->red3 = channel;
            __asm__ volatile("" : : "m"(quad->red1), "m"(quad->red3));
        }
        {
            register int numerator __asm__("$2") = hud->unk40 * 224;
            int greenChannel;
            __asm__("" : "=r"(quad) : "0"(quad), "r"(numerator));
            greenChannel = numerator / 96;
            quad->blue1 = quad->blue3 = 0;
            MATCHING_KEEP(quad);
            quad->green1 = quad->green3 = greenChannel;
        }
        MATCHING_BARRIER_VOLATILE("memory");
        {
            register int currentX __asm__("$5") = x;
            register DecodedHudQuad* argument __asm__("$4");
            register int coordinate __asm__("$2");
            register int barCoordinate __asm__("$2");
            register int value __asm__("$3");
            MATCHING_OBSERVE_CLOBBER(currentX, "$4");
            argument = quad;
            MATCHING_OBSERVE(argument);
            coordinate = currentX;
            quad->x0 = quad->x2 = coordinate;
            MATCHING_BARRIER_VOLATILE("memory");
            value = hud->unk40;
            MATCHING_BARRIER_VOLATILE("memory");
            barCoordinate = (unsigned short)barY;
            MATCHING_KEEP(barCoordinate);
            quad->y2 = quad->y3 = defaultBottom;
            value += currentX;
            MATCHING_KEEP_VOLATILE_CLOBBER(value, "memory");
            quad->y0 = quad->y1 = barCoordinate;
            quad->x1 = quad->x3 = value;
            func_8004E758(argument);
        }
        quad++;
        DecodedHudPacketCursor = (unsigned char*)quad;
        result = width + 116;
    }
    MATCHING_KEEP(result);
    return result;
}

void func_level_17_8008043C(HudEntry* hud) {
    int value, maximum;
    func_80027D60(hud);
    hud->unk3C += 0x6A;
    if (hud->unk28 != 0) {
        value = *hud->unk28;
        maximum = hud->unk26;
        if (value > maximum)
            value = maximum;
        if (value < 0)
            value = 0;
        hud->unk40 = hud->unk42 = value * 96 / maximum;
    }
}

void func_level_17_800804E4(HudEntry* hud) {
    int value, maximum, current;
    if (hud->unk28 != 0) {
        value = *hud->unk28;
        maximum = hud->unk26;
        if (value > maximum)
            value = maximum;
        if (value < 0)
            value = 0;
        value = value * 96 / maximum;
        if (value < 0)
            value = 0;
        current = hud->unk40;
        hud->unk42 = value;
        if ((unsigned short)current < hud->unk42)
            hud->unk40 = current + 1;
        else if (hud->unk42 < (unsigned short)current)
            hud->unk40 = current - 1;
        if (*hud->unk28 > 0 && hud->unk40 == 0)
            hud->unk40 = 1;
    }
    func_8002798C(hud);
}
