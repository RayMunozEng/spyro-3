#include "common.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_68_80074780(void) {
}

Moby* func_80055A7C(int, Moby*);
void func_80055C24(Moby*);
extern Moby* D_8006C550;
Moby* func_cutscene_68_80074788(int mobyClass, Moby* parent) {
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
