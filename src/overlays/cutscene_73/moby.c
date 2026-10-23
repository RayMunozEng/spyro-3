#include "matching.h"
#include "common.h"
#include "spyro.h"
#include "stdutil.h"
#include "ovl_header.h"

void func_cutscene_73_80074800(void) {
}

extern short D_800658A0[], D_80065920[];
extern int DecodedParticleColour __asm__("D_80065868");
extern void* func_8002EC50(int, int, int);
void func_cutscene_73_80074808(Moby* moby) {
    Vector3D offset, middle;
    void* effect;
    int angle = func_8003636C(0, 0xFF);
    func_80055D24(moby, 4);
    *(int*)&moby->colour = DecodedParticleColour;
    func_80055F14(moby, 1, &middle);
    func_80055F14(moby, 0, &offset);
    func_8004F194(&middle, &middle, &offset);
    func_8004F110(&middle, 1);
    offset.x = D_80065920[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.y = D_800658A0[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.z = 0;
    func_8004F194(&offset, &middle, &offset);
    SpawnParticle(2, 0x42, &offset, (Vector3D*)1);
    func_80055F14(moby, 2, &middle);
    func_80055F14(moby, 0, &offset);
    func_8004F194(&middle, &middle, &offset);
    func_8004F110(&middle, 1);
    angle = func_8003636C(0, 0xFF);
    offset.x = D_80065920[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.y = D_800658A0[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.z = 0;
    func_8004F194(&offset, &middle, &offset);
    SpawnParticle(2, 0x42, &offset, (Vector3D*)1);
    if (!moby->mobyTag) {
        moby->mobyTag = func_8002EC50(1, 0x40, 0x489090);
        if (!moby->mobyTag)
            return;
    }
    {
        effect = moby->mobyTag;
        *((unsigned char*)effect + 0x10) = 1;
        func_80055F14(moby, 0, effect);
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * cutscene73 0x80074A5C..0x80074D94: 206 original instructions.
 * Original 88-byte frame, 88-byte pool stride, table identities, signed
 * halfword products (sample*25)>>9 or >>10, byte/word widths and post-call
 * rereads preserved. Units, helper contracts and caller cadence unresolved.
 * Empty constraints retain argument and stack-store scheduling without CPU
 * instructions. Acceptance requires original linked words and all hashes.
 */
extern Moby* P74A5C_D_8006C550 __asm__("D_8006C550");
extern short P74A5C_D_800658A0[] __asm__("D_800658A0");
extern short P74A5C_D_80065920[] __asm__("D_80065920");
void P74A5CRefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");
int P74A5CClearVector(Vector3D*) __asm__("func_8004F168");
int P74A5CInterpolateMobyVertex(Moby*, int, int*) __asm__("func_80055F14");
extern int P74A5C_D_8006C598 __asm__("D_8006C598");
extern int P74A5C_D_8006EDDC __asm__("D_8006EDDC");

void func_cutscene_73_80074A5C(Moby* moby) {
    register Moby* owner __asm__("$17") = moby;
    Vector3D vector10;
    Vector3D vector20;
    register Moby* selectedMoby __asm__("$16");
    register Vector3D* ownerPosition __asm__("$18");
    register Vector3D* privateState19 __asm__("$19");
    register int globalWord __asm__("$20");
    register int scanOffset __asm__("$4");
    register int condition __asm__("$2");
    register int tableSample __asm__("$3");
    register Vector3D* vectorArgument __asm__("$6");
    register Vector3D *argument4 __asm__("$4"), *argument5Pointer __asm__("$5");
    register int scanClass __asm__("$6"), scanOne __asm__("$5"), linkedIndex __asm__("$3"),
        argument5 __asm__("$5");
    signed char* effect0;
    signed char* effect1;
    register int scanIndex __asm__("$3");
    register int stateByte __asm__("$3");
    register void* privateState16 __asm__("$16");

    MATCHING_KEEP(owner);
    stateByte = owner->state;
    globalWord = P74A5C_D_8006EDDC;
    switch (stateByte) {
        case 0:
            MATCHING_BARRIER("$3");
            if (P74A5C_D_8006C598 == 0) {
                scanIndex = 0;
                scanClass = 0x279C;
                scanOne = 1;
                MATCHING_KEEP2_CLOBBER(scanClass, scanOne, "$4");
                scanOffset = 0;
                do {
                    if ((*(short*)((unsigned char*)((scanOffset + (int)P74A5C_D_8006C550)) +
                                   0x38)) == scanClass) {
                        owner->state = scanOne;
                        owner->linkedMoby = scanIndex;
                    }
                    scanIndex += 1;
                    scanOffset += 0x58;
                } while (scanIndex < 4);
                return;
            }
            break;
        case 1:
            condition = globalWord < 0x1E0;
            MATCHING_KEEP(condition);
            if (!condition) {
                argument5 = 4;
                linkedIndex = (unsigned char)owner->linkedMoby;
                MATCHING_OBSERVE2_CLOBBER(argument5, linkedIndex, "$2");
                owner->state = 2;
                selectedMoby = P74A5C_D_8006C550;
                __asm__("" : "=r"(selectedMoby) : "0"(selectedMoby), "r"(linkedIndex));
                selectedMoby += linkedIndex;
                P74A5CRefreshMobySpatialGridAndBasis(selectedMoby, argument5);
                P74A5CInterpolateMobyVertex(selectedMoby, 0, &vector10);
                func_8004F178(&owner->position, (Vector3D*)&vector10);
                owner->angle.yaw = selectedMoby->angle.yaw;
                SpawnMoby(0x28F0, owner);
                privateState16 = owner->mobyTag;
                func_8004F178((Vector3D*)privateState16, (Vector3D*)&vector10);
                vector20.x = 0x1397A;
                vector20.y = 0x11828;
                vector20.z = owner->position.z;
                (*(int*)((unsigned char*)(privateState16) + 0xC)) = 0xC4;
                return;
            }
            break;
        case 2:
            ownerPosition = &owner->position;
            privateState19 = owner->mobyTag;
            func_8004F178(ownerPosition, privateState19);
            owner->angle.yaw = (unsigned char)(*(int*)((unsigned char*)(privateState19) + 0xC));
            P74A5CClearVector(&vector10);
            effect0 = SpawnParticle(1, 0x37, ownerPosition, &vector10);
            if (effect0 != 0) {
                (*(signed char*)((unsigned char*)(effect0) + 0xA)) = 3;
            }
            tableSample = P74A5C_D_80065920[owner->angle.yaw];
            __asm__("" : "=r"(tableSample) : "0"(tableSample) : "$4", "$5", "$6");
            argument4 = ownerPosition;
            MATCHING_OBSERVE(argument4);
            vector10.x = (tableSample * 0x19) >> 9;
            MATCHING_BARRIER("memory");
            argument5Pointer = ownerPosition;
            tableSample = P74A5C_D_800658A0[owner->angle.yaw];
            __asm__("" : "=r"(tableSample) : "0"(tableSample), "r"(argument5Pointer) : "$6");
            vectorArgument = &vector10;
            __asm__("" : "=m"(vector10.z) : "r"(tableSample), "r"(vectorArgument));
            *(volatile int*)&vector10.z = 0;
            __asm__("" : "=r"(tableSample) : "0"(tableSample), "m"(vector10.z));
            vector10.y = (tableSample * 0x19) >> 9;
            func_8004F194(argument4, argument5Pointer, vectorArgument);
            tableSample = P74A5C_D_80065920[owner->angle.yaw];
            __asm__("" : "=r"(tableSample) : "0"(tableSample) : "$4", "$5", "$6");
            argument4 = &vector10;
            MATCHING_OBSERVE(argument4);
            vector10.x = (tableSample * 0x19) >> 0xA;
            MATCHING_BARRIER("memory");
            argument5Pointer = privateState19;
            tableSample = P74A5C_D_800658A0[owner->angle.yaw];
            __asm__("" : "=r"(tableSample) : "0"(tableSample), "r"(argument5Pointer) : "$6");
            vectorArgument = argument4;
            __asm__("" : "=m"(vector10.z) : "r"(tableSample), "r"(vectorArgument));
            *(volatile int*)&vector10.z = 0;
            __asm__("" : "=r"(tableSample) : "0"(tableSample), "m"(vector10.z));
            vector10.y = (tableSample * 0x19) >> 0xA;
            func_8004F194(argument4, argument5Pointer, vectorArgument);
            P74A5CClearVector(&vector20);
            effect1 = SpawnParticle(1, 0x37, (Vector3D*)&vector10, &vector20);
            if (effect1 != 0) {
                (*(signed char*)((unsigned char*)(effect1) + 0xA)) = 3;
            }
            func_8004F178(privateState19, ownerPosition);
            (*(int*)((unsigned char*)(privateState19) + 0xC)) = (int)owner->angle.yaw;
            __asm__("" : : : "$2", "memory");
            condition = globalWord < 0x219;
            MATCHING_KEEP(condition);
            if (!condition) {
                owner->state = 3;
            }
            return;
    }
}

void func_cutscene_73_80074D94(void) {
}

INCLUDE_RODATA("asm/nonmatchings/overlays/cutscene_73/moby", D_cutscene_73_80074490);

INCLUDE_RODATA("asm/nonmatchings/overlays/cutscene_73/moby", D_cutscene_73_800744C0);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original parser recovery and native C; original SHA256 84b12cf1aaba1af1ee55d424d5a0f45a17415ffc6913367ce36ad5086207721a. Raw helper/units/cadence/runtime unproven. */
#define ParserField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Parser6245_0CountTimerDown() __asm__("func_800359A4");                    /* extern */
unsigned char Parser6245_0NormalizeVectorToLength() __asm__("func_8004EF04"); /* extern */
int Parser6245_0_rand() __asm__("rand");                                      /* extern */
extern int Parser6245_0_D_8006EDDC __asm__("D_8006EDDC");
extern unsigned char Parser6245_0_D_cutscene_73_80074490 __asm__("D_cutscene_73_80074490");
extern unsigned char Parser6245_0_D_cutscene_73_800744C0 __asm__("D_cutscene_73_800744C0");

typedef struct {
    int words[4];
} CutsceneCopy16;
void func_cutscene_73_80074D9C(Moby* moby) {
    register Moby* arg0 __asm__("$16") = moby;
    struct {
        Vector3D sp10;
        char pad1C[4];
        unsigned char sp20[48];
        unsigned char sp50[48];
        Vector3D sp80;
        char pad8C[4];
        Vector3D sp90;
        char pad9C[4];
    } frame;
    register unsigned char* var_a2 __asm__("$6");
    register unsigned char* var_a2_2 __asm__("$6");
    register unsigned char* var_a3 __asm__("$7");
    register unsigned char* var_a3_2 __asm__("$7");
    register int temp_s4 __asm__("$20");
    register int var_s0 __asm__("$16");
    register int var_s1 __asm__("$17");
    register int var_s1_2 __asm__("$17");
    register int var_s1_3 __asm__("$17");
    register int var_s1_4 __asm__("$17");
    register int var_v0 __asm__("$2");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register Vector3D* vector19 __asm__("$19");
    register unsigned char *base2 __asm__("$2"), *base3 __asm__("$3");
    register int arg4 __asm__("$4"), arg5 __asm__("$5"), arg7 __asm__("$7");
    register Vector3D* arg6 __asm__("$6");
    register int (*particle2)() __asm__("$2");
    register int var_v1 __asm__("$3");
    register signed char* temp_v0 __asm__("$16");
    register signed char* temp_v0_2 __asm__("$16");
    register unsigned int temp_s2 __asm__("$18");
    register void* temp_s2_2 __asm__("$18");

    if (Parser6245_0CountTimerDown(&arg0->substate, 1) != 0) {
        arg0->substate = 0x2D;
        temp_s4 = Parser6245_0_rand() & 3;
        var_s0 = -1;
        temp_s2 = Parser6245_0_rand() & 7;
        var_a3 = frame.sp20;
        var_a2 = &Parser6245_0_D_cutscene_73_80074490;
        do {
            *(CutsceneCopy16*)var_a3 = *(CutsceneCopy16*)var_a2;
            var_a2 += 0x10;
            var_a3 += 0x10;
        } while (var_a2 != (&Parser6245_0_D_cutscene_73_80074490 + 0x30));
        var_a3_2 = frame.sp50;
        var_a2_2 = &Parser6245_0_D_cutscene_73_800744C0;
        do {
            *(CutsceneCopy16*)var_a3_2 = *(CutsceneCopy16*)var_a2_2;
            var_a2_2 += 0x10;
            var_a3_2 += 0x10;
        } while (var_a2_2 != (&Parser6245_0_D_cutscene_73_800744C0 + 0x30));
        if ((unsigned int)(Parser6245_0_D_8006EDDC - 0x14) < 0x10DU) {
            var_s0 = 0;
        } else if ((unsigned int)(Parser6245_0_D_8006EDDC - 0x121) < 0x78U) {
            var_s0 = 1;
        } else if (((unsigned int)(Parser6245_0_D_8006EDDC - 0x210) < 0x81U) ||
                   (Parser6245_0_D_8006EDDC >= 0x72C)) {
            var_s0 = 2;
        } else if ((unsigned int)(Parser6245_0_D_8006EDDC - 0x454) < 0x131U) {
            var_s0 = 3;
        }
        if (var_s0 != -1) {
            arg4 = (int)&frame.sp10;
            MATCHING_KEEP(arg4);
            base2 = frame.sp20;
            MATCHING_KEEP(base2);
            func_8004F178(arg4, base2 + (var_s0 * 12));
            value2 = Parser6245_0_rand();
            value3 = frame.sp10.x;
            value2 &= 0xFFF;
            value3 -= 0x800;
            value3 += value2;
            frame.sp10.x = value3;
            value2 = Parser6245_0_rand();
            value3 = frame.sp10.y;
            value2 &= 0xFFF;
            value3 -= 0x800;
            value3 += value2;
            frame.sp10.y = value3;
            if (var_s0 != 3) {
                var_v0 = Parser6245_0_rand() & 0x1FFF;
                var_v1 = frame.sp10.z - 0x1000;
            } else {
                var_v0 = Parser6245_0_rand() & 0xFFF;
                var_v1 = frame.sp10.z - 0x800;
            }
            var_v1 += var_v0;
            frame.sp10.z = var_v1;
            var_s1 = 0;
            do {
                arg4 = 1;
                arg5 = 70;
                arg6 = &frame.sp10;
                arg7 = 35;
                MATCHING_KEEP4(arg4, arg5, arg6, arg7);
                particle2 = SpawnParticle;
                MATCHING_KEEP(particle2);
                var_s1++;
                particle2(arg4, arg5, arg6, arg7);
            } while (var_s1 < 0x14);
            switch (temp_s2) {
                case 0:
                case 1:
                case 2:
                    var_s1_2 = 0;
                    MATCHING_OBSERVE(temp_s2);
                    vector19 = &frame.sp80;
                    value2 = temp_s4 * 12;
                    MATCHING_KEEP2(vector19, value2);
                    base3 = frame.sp50;
                    temp_s2_2 = base3 + value2;
                loop_24:
                    frame.sp80.x = (Parser6245_0_rand() & 0x3FF) - 0x200;
                    frame.sp80.y = (Parser6245_0_rand() & 0x3FF) - 0x200;
                    frame.sp80.z = (Parser6245_0_rand() & 0x3FF) - 0x200;
                    Parser6245_0NormalizeVectorToLength(vector19, 0xC8);
                    temp_v0 = SpawnParticle(1, 0, &frame.sp10, (Vector3D*)vector19);
                    if (temp_v0 != 0) {
                        ParserField(temp_v0, signed char*, 0xC) =
                            (signed char)ParserField(temp_s2_2, int*, 0);
                        ParserField(temp_v0, signed char*, 0xD) =
                            (signed char)ParserField(temp_s2_2, int*, 4);
                        ParserField(temp_v0, signed char*, 0xE) =
                            (signed char)ParserField(temp_s2_2, int*, 8);
                        ParserField(temp_v0, unsigned char*, 2) =
                            (unsigned char)(ParserField(temp_v0, unsigned char*, 2) +
                                            (Parser6245_0_rand(vector19) & 8));
                        MATCHING_BARRIER_VOLATILE("memory");
                        arg4 = (int)vector19;
                        MATCHING_OBSERVE_VOLATILE(arg4);
                    }
                    /* Original A0 producer: word166 supplies vector19 on the zero
                 * particle path; word180 restores it after rand on the
                 * nonzero path. Capture the proven common raw ABI value. */
                    __asm__("" : "=r"(arg4));
                    Parser6245_0NormalizeVectorToLength(arg4, 0x64);
                    temp_v0_2 = SpawnParticle(1, 0, &frame.sp10, (Vector3D*)vector19);
                    if (temp_v0_2 != 0) {
                        ParserField(temp_v0_2, signed char*, 0xC) =
                            (signed char)ParserField(temp_s2_2, int*, 0);
                        ParserField(temp_v0_2, signed char*, 0xD) =
                            (signed char)ParserField(temp_s2_2, int*, 4);
                        ParserField(temp_v0_2, signed char*, 0xE) =
                            (signed char)ParserField(temp_s2_2, int*, 8);
                        ParserField(temp_v0_2, unsigned char*, 2) =
                            (unsigned char)(ParserField(temp_v0_2, unsigned char*, 2) +
                                            (Parser6245_0_rand() & 8));
                    }
                    var_s1_2 += 1;
                    if (var_s1_2 < 0x28) {
                        goto loop_24;
                    }
                    break;
                case 3:
                case 4:
                    var_s1_3 = 0;
                    do {
                        arg4 = 1;
                        arg5 = 70;
                        arg6 = &frame.sp10;
                        arg7 = 45;
                        MATCHING_KEEP4(arg4, arg5, arg6, arg7);
                        particle2 = SpawnParticle;
                        MATCHING_KEEP(particle2);
                        var_s1_3++;
                        particle2(arg4, arg5, arg6, arg7);
                        SpawnParticle(1, 0x46, &frame.sp10, (Vector3D*)0x3C);
                    } while (var_s1_3 < 0x14);
                    return;
                case 5:
                case 6:
                case 7:
                    var_s1_4 = 0;
                    do {
                        var_s1_4 += 1;
                        frame.sp90.x = (Parser6245_0_rand() & 0x3FF) - 0x200;
                        frame.sp90.y = (Parser6245_0_rand() & 0x3FF) - 0x200;
                        frame.sp90.z = (Parser6245_0_rand() & 0x3FF) - 0x200;
                        Parser6245_0NormalizeVectorToLength(&frame.sp90, 0xC8);
                        SpawnParticle(1, 0x37, &frame.sp10, (Vector3D*)&frame.sp90);
                        Parser6245_0NormalizeVectorToLength(&frame.sp90, 0x64);
                        SpawnParticle(1, 0x37, &frame.sp10, (Vector3D*)&frame.sp90);
                    } while (var_s1_4 < 0x28);
                    break;
            }
        }
    } else {
    }
}
#undef ParserField

void func_cutscene_73_80075210(void) {
    int frame[8];
}

extern Moby* func_80055A7C(void);
extern Moby* D_8006C550;
Moby* func_cutscene_73_80075220(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C();
    void* tag;
    unsigned int index;
    if (!moby)
        return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, sizeof(Moby));
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        index = parent - D_8006C550;
        if (index < 0x100)
            moby->linkedMoby = index;
        else
            moby->linkedMoby = 0xFF;
    } else
        moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    switch (mobyClass) {
        case 0x27A2:
            func_8004F178(&moby->position, &parent->position);
            moby->mobyClass = 0xFF;
            moby->distanceToGround = 0x27A2;
            func_80055D10(moby);
            moby->updateDistance = 0xFF;
            break;
        case 0x28F0:
            func_8004F178(&moby->position, &parent->position);
            moby->mobyClass = 0xFF;
            moby->distanceToGround = 0x28F0;
            func_80055D10(moby);
            moby->updateDistance = 0xFF;
            parent->mobyTag = moby->mobyTag;
            break;
        default:
            if (parent)
                func_8004F178(&moby->position, &parent->position);
            else
                func_8004F178(&moby->position, (Vector3D*)&spyro);
            func_80055C24(moby);
            break;
    }
    return moby;
}
