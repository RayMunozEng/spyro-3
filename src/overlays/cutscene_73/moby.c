#include "common.h"
#include "spyro.h"
#include "stdutil.h"
#include "ovl_header.h"

void func_cutscene_73_80074800(void) {}

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
        if (!moby->mobyTag) return;
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
void P74A5C_func_80055D24(Moby*, int) __asm__("func_80055D24");
int P74A5C_func_8004F168(Vector3D *) __asm__("func_8004F168");
int P74A5C_func_80055F14(Moby *, int, int *) __asm__("func_80055F14");
extern int P74A5C_D_8006C598 __asm__("D_8006C598");
extern int P74A5C_D_8006EDDC __asm__("D_8006EDDC");

void func_cutscene_73_80074A5C(Moby *argument) {
    register Moby* owner __asm__("$17") = argument;
    Vector3D vector10;
    Vector3D vector20;
    register Moby *selectedMoby __asm__("$16");
    register Vector3D *ownerPosition __asm__("$18");
    register Vector3D *privateState19 __asm__("$19");
    register int globalWord __asm__("$20");
    register int scanOffset __asm__("$4");
    register int condition __asm__("$2");
    register int tableSample __asm__("$3");
    register Vector3D* vectorArgument __asm__("$6");
    register Vector3D* argument4 __asm__("$4"), *argument5Pointer __asm__("$5");
    register int scanClass __asm__("$6"),scanOne __asm__("$5"),linkedIndex __asm__("$3"),argument5 __asm__("$5");
    signed char *effect0;
    signed char *effect1;
    register int scanIndex __asm__("$3");
    register int stateByte __asm__("$3");
    register void *privateState16 __asm__("$16");

    __asm__("" : "=r"(owner) : "0"(owner));
    stateByte = owner->state;
    globalWord = P74A5C_D_8006EDDC;
    switch (stateByte) {
    case 0:
        __asm__("" : : : "$3");
        if (P74A5C_D_8006C598 == 0) {
            scanIndex = 0;
            scanClass=0x279C;scanOne=1;
            __asm__("" : "=r"(scanClass),"=r"(scanOne):"0"(scanClass),"1"(scanOne):"$4");
            scanOffset = 0;
            do {
                if ((*(short *)((unsigned char*)((scanOffset + (int)P74A5C_D_8006C550)) + 0x38)) == scanClass) {
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
        __asm__("" : "=r"(condition):"0"(condition));
        if (!condition) {
            argument5 = 4;
            linkedIndex = (unsigned char)owner->linkedMoby;
            __asm__("" : : "r"(argument5),"r"(linkedIndex):"$2");
            owner->state = 2;
            selectedMoby = P74A5C_D_8006C550;
            __asm__("" : "=r"(selectedMoby):"0"(selectedMoby),"r"(linkedIndex));
            selectedMoby += linkedIndex;
            P74A5C_func_80055D24(selectedMoby, argument5);
            P74A5C_func_80055F14(selectedMoby, 0, &vector10);
            func_8004F178(&owner->position, (Vector3D *) &vector10);
            owner->angle.yaw = selectedMoby->angle.yaw;
            SpawnMoby(0x28F0, owner);
            privateState16 = owner->mobyTag;
            func_8004F178((Vector3D *) privateState16, (Vector3D *) &vector10);
            vector20.x = 0x1397A;
            vector20.y = 0x11828;
            vector20.z = owner->position.z;
            (*(int *)((unsigned char*)(privateState16) + 0xC)) = 0xC4;
            return;
        }
        break;
    case 2:
        ownerPosition = &owner->position;
        privateState19 = owner->mobyTag;
        func_8004F178(ownerPosition, privateState19);
        owner->angle.yaw = (unsigned char) (*(int *)((unsigned char*)(privateState19) + 0xC));
        P74A5C_func_8004F168(&vector10);
        effect0 = SpawnParticle(1, 0x37, ownerPosition, &vector10);
        if (effect0 != 0) {
            (*(signed char *)((unsigned char*)(effect0) + 0xA)) = 3;
        }
        tableSample = P74A5C_D_80065920[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample):"$4","$5","$6");
        argument4 = ownerPosition;
        __asm__("" : : "r"(argument4));
        vector10.x = (tableSample * 0x19) >> 9;
        __asm__("" : : : "memory");
        argument5Pointer = ownerPosition;
        tableSample = P74A5C_D_800658A0[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample),"r"(argument5Pointer):"$6");
        vectorArgument = &vector10;
        __asm__("" : "=m"(vector10.z):"r"(tableSample),"r"(vectorArgument));
        *(volatile int*)&vector10.z = 0;
        __asm__("" : "=r"(tableSample):"0"(tableSample),"m"(vector10.z));
        vector10.y = (tableSample * 0x19) >> 9;
        func_8004F194(argument4, argument5Pointer, vectorArgument);
        tableSample = P74A5C_D_80065920[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample):"$4","$5","$6");
        argument4 = &vector10;
        __asm__("" : : "r"(argument4));
        vector10.x = (tableSample * 0x19) >> 0xA;
        __asm__("" : : : "memory");
        argument5Pointer = privateState19;
        tableSample = P74A5C_D_800658A0[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample),"r"(argument5Pointer):"$6");
        vectorArgument = argument4;
        __asm__("" : "=m"(vector10.z):"r"(tableSample),"r"(vectorArgument));
        *(volatile int*)&vector10.z = 0;
        __asm__("" : "=r"(tableSample):"0"(tableSample),"m"(vector10.z));
        vector10.y = (tableSample * 0x19) >> 0xA;
        func_8004F194(argument4, argument5Pointer, vectorArgument);
        P74A5C_func_8004F168(&vector20);
        effect1 = SpawnParticle(1, 0x37, (Vector3D *) &vector10, &vector20);
        if (effect1 != 0) {
            (*(signed char *)((unsigned char*)(effect1) + 0xA)) = 3;
        }
        func_8004F178(privateState19, ownerPosition);
        (*(int *)((unsigned char*)(privateState19) + 0xC)) = (int) owner->angle.yaw;
        __asm__("" : : : "$2", "memory");
        condition = globalWord < 0x219;
        __asm__("" : "=r"(condition):"0"(condition));
        if (!condition) {
            owner->state = 3;
        }
        return;
    }
}


void func_cutscene_73_80074D94(void) {}

INCLUDE_RODATA("asm/nonmatchings/overlays/cutscene_73/moby", D_cutscene_73_80074490);

INCLUDE_RODATA("asm/nonmatchings/overlays/cutscene_73/moby", D_cutscene_73_800744C0);

INCLUDE_ASM("asm/nonmatchings/overlays/cutscene_73/moby", func_cutscene_73_80074D9C);

void func_cutscene_73_80075210(void) {
    int frame[8];
}

extern Moby* func_80055A7C(void);
extern Moby* D_8006C550;
Moby* func_cutscene_73_80075220(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C();
    void* tag;
    unsigned int index;
    if (!moby) return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, sizeof(Moby));
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        index = parent - D_8006C550;
        if (index < 0x100) moby->linkedMoby = index;
        else moby->linkedMoby = 0xFF;
    } else moby->linkedMoby = 0xFF;
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
        if (parent) func_8004F178(&moby->position, &parent->position);
        else func_8004F178(&moby->position, (Vector3D*)&spyro);
        func_80055C24(moby);
        break;
    }
    return moby;
}
