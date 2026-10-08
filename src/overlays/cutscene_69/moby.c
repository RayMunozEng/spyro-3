#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_69_80074780(void) {}

extern short D_800658A0[], D_80065920[];
extern int DecodedParticleColour __asm__("D_80065868");
extern void* func_8002EC50(int, int, int);
void func_cutscene_69_80074788(Moby* moby) {
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

Moby* func_80055A7C(int, Moby*);
void func_80055C24(Moby*);
extern Moby* D_8006C550;
Moby* func_cutscene_69_800749DC(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C(mobyClass, parent);
    void* tag;
    if (!moby) return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, 0x58);
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        int index = parent - D_8006C550;
        if ((unsigned int)index < 0x100) moby->linkedMoby = index;
        else moby->linkedMoby = 0xFF;
    } else moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    if (parent) func_8004F178(&moby->position, &parent->position);
    else func_8004F178(&moby->position, &spyro.position);
    func_80055C24(moby);
    return moby;
}
