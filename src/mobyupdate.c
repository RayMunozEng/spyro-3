#include "common.h"
#include "mobyupdate.h"

/**
 * UpdateMobys() - func_8003038C()
 * Check Ghidra, this one is difficult
 * https://decomp.me/scratch/sqK7K
 */
extern Moby* D_8006E788[];
extern int D_8006C648;
extern int D_8006C770;
extern int D_8006C63C;
extern void (**MobyUpdate)(Moby*);
extern void func_80055680(void);
extern void func_80055854(Moby**, int);
void func_8003038C(void) {
    register Moby** slot __asm__("$16") = D_8006E788;
    Moby* moby;
    func_80055680();
    func_80055854(slot, 2);
    if (D_8006C648 >= 3) {
        func_80055854(slot, D_8006C648 + 0x7FFFFFFE);
    }
    while ((moby = *slot++) != 0) {
        if (*(unsigned char*)((char*)moby + 0x48) < 0x80) {
            D_8006C770 = *(unsigned char*)((char*)moby + 0x42) & 2;
            D_8006C63C = *(unsigned char*)((char*)moby + 0x42) & 1;
            if (MobyUpdate != 0) {
                void (*fn)(Moby*) = MobyUpdate[*(short*)((char*)moby + 0x36)];
                if (fn != 0) {
                    fn(moby);
                }
            }
        }
    }
}
