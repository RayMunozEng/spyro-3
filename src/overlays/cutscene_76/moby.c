#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_76_80074780(void) {
}

typedef struct {
    Vector3D position;
    int reserved0C;
    unsigned char byte10;
} DecodedCutsceneParticleTag;
void* func_8002EC50(int, int, int);
void func_80055D24(Moby*, int);
void func_80055F14(Moby*, int, Vector3D*);
void func_8004F178(Vector3D*, Vector3D*);
extern int D_8006C644;
void func_cutscene_76_80074788(Moby* moby) {
    DecodedCutsceneParticleTag* tag;
    Vector3D savedPosition;
    if (!moby->mobyTag) {
        moby->mobyTag = func_8002EC50(4, 0x40, 0x489090);
        if (!moby->mobyTag)
            return;
    }
    tag = moby->mobyTag;
    tag->byte10 = 4;
    func_80055D24(moby, 4);
    func_80055F14(moby, 0, &tag->position);
    if ((D_8006C644 & 0xF) < 2) {
        func_8004F178(&savedPosition, &moby->position);
        func_8004F178(&moby->position, &tag->position);
        SpawnParticle(1, 0xC, (Vector3D*)moby, (Vector3D*)3);
        func_8004F178(&moby->position, &savedPosition);
    }
}

Moby* func_80055A7C(int, Moby*);
void func_80055C24(Moby*);
extern Moby* D_8006C550;
Moby* func_cutscene_76_80074870(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C(mobyClass, parent);
    void* tag;
    if (!moby)
        return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, 0x58);
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        int index = parent - D_8006C550;
        if ((unsigned int)index < 0x100)
            moby->linkedMoby = index;
        else
            moby->linkedMoby = 0xFF;
    } else
        moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    if (parent)
        func_8004F178(&moby->position, &parent->position);
    else
        func_8004F178(&moby->position, &spyro.position);
    func_80055C24(moby);
    return moby;
}
