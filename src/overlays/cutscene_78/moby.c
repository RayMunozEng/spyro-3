#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "ovl_header.h"

void func_cutscene_78_80074780(void) {}

void func_cutscene_78_80074788(Moby* moby) {
    if (moby->state == 0) {
        if (SpawnMoby(0x28F0, moby)) moby->state = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/cutscene_78/moby", func_cutscene_78_800747DC);

void func_cutscene_78_80074BC0(void) {}

extern Moby* func_80055A7C(void);
extern Moby* D_8006C550;
Moby* func_cutscene_78_80074BC8(int mobyClass, Moby* parent) {
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
    case 0x28A3:
        func_8004F178(&moby->position, &parent->position);
        moby->mobyClass = 3;
        moby->distanceToGround = 0x28A3;
        func_80055C24(moby);
        moby->updateDistance = 0xFF;
        moby->lowDrawDistance = 0x40;
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
