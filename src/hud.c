#include "common.h"
#include "hud.h"
#include "spu.h"

extern int func_8002EBB0(void*);

// sbss
extern int D_8006C598;
extern int g_CurrentLevel; // D_8006C5BC
extern int D_8006C64C;
extern int deltaTime; // 8006C648
extern int D_8006C784; // g_Lives
extern int D_8006C660; // g_EggTotal
extern int D_8006C71C; // g_GemTotal
extern int D_8006C74C;
extern int D_8006C768;
extern SpeedwayData speedwayData; // D_8006FA38

extern Vector3D D_800714F4; // likely just the aiming reticle position, e.g. in Country Speedway / Dino Mines 

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4; // might be chars?
    int unk8; // might be chars?
} Unknown_80071A04;
extern Unknown_80071A04 D_80071A04;

///////////////////////////////////////////////////

/**
 * GetSpriteIndex() - func_80027934() - MATCHING
 * https://decomp.me/scratch/VTcLP
 */
int func_80027934(int spriteClass) {
    int i = 0;

    while (D_8006C738[i].spriteClass != -1) {
        if (D_8006C738[i].spriteClass == spriteClass) break;
        i++;
    }

    return i;
}

/**
 * ???() - func_8002798C() - MATCHING 
 * https://decomp.me/scratch/VjAmr
 */
void func_8002798C(HudEntry* arg0) {
    int temp_v0;
    int var_a0;
    int var_v1;
    short temp_a2;

    if (arg0->unk40 != arg0->unk42) {
        temp_a2 = arg0->unk46 + deltaTime;
        arg0->unk46 = temp_a2;
        arg0->unk44 = 180;
        if (arg0->movementFrame == 0) {
            temp_v0 = arg0->unk40 - arg0->unk42;
            var_v1 = ABS(temp_v0);
            if (var_v1 >= 40 || (var_v1 >= 10 && temp_a2 >= 4) || temp_a2 >= 6) {

                if (var_v1 >= 320) {
                    var_a0 = 6;
                } else if (var_v1 >= 40) {
                    var_a0 = 3;
                } else {
                    var_a0 = 1;
                }

                if (arg0->unk40 <= arg0->unk42) {
                    arg0->unk40 += var_a0;
                } else {
                    arg0->unk40 -= var_a0;
                }
                
                arg0->unk46 = 0;
            }
        }
    }
}

/**
 * ???() - func_80027A60() - MATCHING
 * https://decomp.me/scratch/kBxS7
*/
void func_80027A60(HudEntry* arg0) {
    int var_v0;

    if (arg0->unk28 != 0) {
        var_v0 = *arg0->unk28;
        MIN(var_v0, 0);
        arg0->unk42 = var_v0;
        if (arg0->unk26 < arg0->unk42) {
            arg0->unk42 = arg0->unk26;
        }
    }
    func_8002798C(arg0);
}


/**
* ???() - func_80027AC0() - MATCHING
* https://decomp.me/scratch/AVgBX
*/
void func_80027AC0(HudEntry* arg0) {
    int var_v0;

    if (arg0->unk28 != 0) {
        var_v0 = *arg0->unk28;
        MIN(var_v0,0);
        arg0->unk42 = var_v0;
        if (arg0->unk26 < arg0->unk42) {
            arg0->unk42 = arg0->unk26;
        }
    }
    arg0->unk40 = arg0->unk42;
}


/**
 * ???() - func_80027B0C() - MATCHING
 * https://decomp.me/scratch/456ru
 */ 
void func_80027B0C(HudEntry* arg0) {
    int temp_s1;

    temp_s1 = arg0->unk40;
    func_80027A60(arg0);
    if (temp_s1 < arg0->unk40) {
        PlaySound(g_SoundTablePtr->extraLife, 0, 0);
    }
}

/*
 * ???() - func_80027B70() - MATCHING
 * https://decomp.me/scratch/lmfXY
 */
void func_80027B70() {
    int i;

    g_Hud.DAT_800719c8 = 0;
    g_Hud.reticleFrame = D_8006C738[func_80027934(2)].frame;
    g_Hud.numberFrame = D_8006C738[func_80027934(0)].frame;
    g_Hud.gemFrame =  D_8006C738[func_80027934(3)].frame;
    g_Hud.textBoxCornerFrame = D_8006C738[func_80027934(1)].frame;
    g_Hud.mainHudIsOnScreen = 0;
    
    for (i = 0; i < 8; i++) { 
        g_HudEntries[i].unk1A = -1;
        g_HudEntries[i].unk4 = 0;
        func_8002803C(i, -1, 0, 0, 0, 0, 1);
        g_HudEntries[i].movementFrame = 50;
    }

    func_8002803C(0, 3, func_80027E40, func_80027A60, func_80029904, &D_8006C71C, 20000);
    func_8002803C(1, 4, func_80027E40, func_80027B0C, func_80029BB0, &D_8006C784, 99);
    func_8002803C(2, 5, func_80027E40, func_80027A60, func_80029904, &D_8006C660, 150);
}

/**
 * ???() - func_80027D60() - MATCHING
 * https://decomp.me/scratch/4YB6r
 */
void func_80027D60(HudEntry* arg0) {
    SpriteDefinition* spriteDef;
    
    spriteDef = &D_8006C738[arg0->unk1C.index];
    if (arg0->unk28 != 0 && (int)arg0->unk28 % 4 == 0) {
        arg0->unk42 = *arg0->unk28;
        if (arg0->unk26 < arg0->unk42) {
            arg0->unk42 = arg0->unk26;
        }
        arg0->unk40 = arg0->unk42;
    } else {
        arg0->unk42 = 99;
        arg0->unk40 = 99;
    }
    
    if (!(arg0->unk38 & 0x40)) {
        arg0->unk44 = 180;
    }
    
    if (arg0->unk24 != -1) {
        SpriteData* spriteData = &D_8006C788[spriteDef->frame];
        arg0->unk3C = spriteData->unk4 - spriteData->unk0;
        arg0->unk3D = spriteData->unk5 - spriteData->unk1;
    } else {
        arg0->unk3C = 0;
        arg0->unk3D = 0;
    }
    
    arg0->unk4C = 0;
    arg0->unk50 = 0;
}

/**
 * ???() - func_80027E40() - MATCHING
 * https://decomp.me/scratch/FRzQ8
 */
void func_80027E40(HudEntry* arg0) {
    int var_a0;
    int var_v0;
    SpriteData* temp_s1;

    temp_s1 = &D_8006C788[g_Hud.numberFrame];
    func_80027D60(arg0);
    var_a0 = 0;
    var_v0 = arg0->unk26;
    while (var_v0 > 0) {
        var_v0 /= 10;
        var_a0++;
    }
    arg0->unk3C += (temp_s1->unk4 - temp_s1->unk0) * var_a0 + 10;
}

/**
 * ???() - func_80027EE4() - MATCHING
 * https://decomp.me/scratch/HKno1
 */
void func_80027EE4(HudEntry* arg0) {
    int var_a0;
    int var_v0;
    SpriteData* temp_s1;

    temp_s1 = &D_8006C788[g_Hud.numberFrame];
    func_80027D60(arg0);
    var_a0 = 0;
    var_v0 = arg0->unk26;
    while (var_v0 > 0) {
        var_v0 /= 10;
        var_a0 += 2;
    }
    var_a0++;
    arg0->unk3C += (temp_s1->unk4 - temp_s1->unk0) * var_a0 + 10;
}

/**
 * ???() - func_80027F88() - MATCHING
 * https://decomp.me/scratch/DupJT
 */
void func_80027F88(HudEntry* arg0) {
    func_80027D60(arg0);
    arg0->unk3C += func_8002EBB0(arg0->unk28);
}

/**
 * UpdateHudSpriteFromClass()? - func_80027FCC() - MATCHING
 * https://decomp.me/scratch/dYesf
 */
void func_80027FCC(HudEntry* hud, int spriteClass) {
    int i;

    i = func_80027934(spriteClass);
    hud->unk24 = D_8006C738[i].spriteClass;
    hud->unk1C.index = i;
    hud->unk1C.animationType = D_8006C738[i].animationType;
    hud->unk1C.frame = D_8006C738[i].frame;
}

/**
 * SetHud() - func_8002803C()
 * WIP
 * https://decomp.me/scratch/VNAQB
 */
/* Retail source: asm/nonmatchings/hud/func_8002803C.s,
 * 0x8002803C..0x80028154. HUD entry stride is 0x54 bytes;
 * raw selector and reset fields update on call. */
int func_8002803C(int slot, int number, void* callbackA, void* callbackB,
                  void* callbackC, int* display, int max) {
    HudEntry* entry = &D_80067248[slot & 15];
    int packed = slot & 0xFFF0;
    if (entry->unk8 != display || entry->unk6 != max ||
        entry->unk4 != number || entry->unk3A != packed ||
        entry->unkC != callbackA || entry->unk10 != callbackB ||
        entry->unk14 != callbackC) {
        unsigned short* count = (unsigned short*)&g_Hud.DAT_800719c8;
        unsigned int old;
        unsigned int frame;
        entry->unk6 = max;
        entry->unk8 = display;
        entry->unk4 = number;
        entry->unk3A = packed;
        entry->unkC = callbackA;
        entry->unk10 = callbackB;
        entry->unk14 = callbackC;
        old = *count;
        *count = old + 1;
        entry->unk1A = old;
        frame = (unsigned char)entry->movementFrame;
        if (frame >= 0x33) {
            register unsigned int newFrame __asm__("$2") = 100 - frame;
            *(volatile unsigned char*)((char*)entry + 0x3F) = newFrame;
            if ((unsigned char)newFrame >= 0x33)
                entry->movementFrame = 0;
        }
        entry->isOffScreen = 1;
    }
    return entry->unk1A;
}

/**
 * ???() - func_80028154() - MATCHING
 * Clears a HUD with a specific value in its struct, unclear what this value is right now
 * https://decomp.me/scratch/sn1q6
 */
int func_80028154(int arg0) {
    int i;

    for (i = 0; i < 8; i++) {
        if (g_HudEntries[i].unk1A == arg0) {
            break;
        }
    }
    
    if (i < 8) {
        func_8002803C(i, -1, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

/**
 * ???() - func_800281D0() - MATCHING
 * https://decomp.me/scratch/y73dG
 */
void func_800281D0(int arg0, int arg1) {
    int i;

    for (i = 0; i < 8; i++) {
        if (g_HudEntries[i].unk1A == arg0) {
            break;
        }
    }
    
    if (i < 8) {
        func_80027FCC(&g_HudEntries[i], arg1);
        g_HudEntries[i].unk4 = g_HudEntries[i].unk24;
    }
}

/**
 * ???() - func_80028264() - MATCHING
 * https://decomp.me/scratch/4We6S
 */
void func_80028264(HudEntry* arg0) {
    func_80027FCC(arg0, arg0->unk4);
    arg0->unk38 = arg0->unk3A;
    arg0->unk2C = arg0->unkC;
    arg0->unk30 = arg0->unk10;
    arg0->unk34 = arg0->unk14;
    arg0->unk28 = arg0->unk8;
    arg0->unk26 = arg0->unk6;
    if (arg0->unk2C != 0) {
        arg0->unk2C(arg0);
    }
    arg0->isOffScreen = 0;
}

/**
 * ResetHuds() - func_800282D8() - MATCHING
 * https://decomp.me/scratch/69F5F
 */
void func_800282D8() {
    int i;
    
    for (i = 0; i < 8; i++) {
        func_8002803C(i, -1, 0, 0, 0, 0, 1);
        g_HudEntries[i].movementFrame = 50;
        func_80028264(&g_HudEntries[i]);
    }
}

/**
 * Sprite animation frame selector - func_80028378() - MATCHING
 * Rev 0 target: asm/nonmatchings/hud/func_80028378.s,
 * 0x80028378..0x800285A4 plus its six-entry jump table (145 target words).
 * https://decomp.me/scratch/dRYvN supplied the initial candidate; the
 * reflected frame uses 2 * frameCount - (remainder + 2) in retail.
 */
extern int D_8006C644;
extern int rand();

int func_80028378(SpriteAnimationData* animData, int arg1) {
    SpriteDefinition* spriteDef;
    int temp;
    int ret;

    spriteDef = &D_8006C738[animData->index];
    ret = 0;
    if (spriteDef->spriteClass != -1) {
        switch (animData->animationType) {
        case 0:
            ret = animData->frame;
            break;
        case 1:
            temp = (D_8006C644 / spriteDef->frameDelay) + arg1;
            ret = spriteDef->frame + (temp % spriteDef->frameCount);
            break;
        case 2: {
            int quotient;
            int count;
            int result;
            int span;
            quotient = D_8006C644 / spriteDef->frameDelay;
            count = spriteDef->frameCount;
            result = quotient + arg1;
            __asm__ volatile("" : "=r"(result) : "0"(result), "r"(count));
            span = count * 2;
            ret = result % (span - 2);
            if (ret >= count) {
                int adjusted = ret + 2;
                /* Keep the retail add-two then subtract order in GCC 2.7.2. */
                __asm__ volatile("" : "=r"(adjusted) : "0"(adjusted));
                ret = span - adjusted;
            }
            ret = ret + spriteDef->frame;
            break;
        }
        case 3:
            ret = spriteDef->frame;
            if (!(rand() & 0x1F)) {
                animData->animationType = 4;
            }
            break;
        case 4:
            ret = animData->frame + 1;
            if (ret >= (spriteDef->frame + spriteDef->frameCount)) {
                animData->animationType = 5;
                ret = (spriteDef->frame + spriteDef->frameCount) - 1;
            }
            break;
        case 5:
            ret = animData->frame - 1;
            if (spriteDef->frame >= ret) {
                animData->animationType = 3;
                ret = spriteDef->frame;
            }
            break;
        }
    }
    return ret;
}

/**
 * ???() - func_800285A4()
 * Matching in decomp.me, check and implement fully
 * Could be the function pointers that I need to do something with
 * https://decomp.me/scratch/NkhCu
 */
int func_800285A4(int arg0) {
    int var_s3 = 0;
    int i;
    
    if (g_HudEntries[0].unk34 == 0 && g_HudEntries[0].unk14 == 0) {
        func_8002803C(0x40, 3, func_80027E40, func_80027A60, func_80029904, &D_8006C71C, 10000);
    }
    if (g_HudEntries[1].unk34 == 0 && g_HudEntries[1].unk14 == 0) {
        func_8002803C(0x41, 4, func_80027E40, func_80027B0C, func_80029BB0, &D_8006C784, 99);
    }
    if (g_HudEntries[2].unk34 == 0 && g_HudEntries[2].unk14 == 0) {
        func_8002803C(0x42, 5, func_80027E40, func_80027A60, func_80029904, &D_8006C660, 150);
    }
    
    for (i = 0; i < 8; i++) {
        HudEntry* hud = &g_HudEntries[i];
        
        if ((hud->unk38 & 0x10) || (g_Hud.mainHudIsOnScreen != 0)) {
            hud->unk44 = 10;
        }
        
        if (D_8006C598 == 0xFF) {
            hud->movementFrame = 50;
        }
        
        if (g_Hud.DAT_800719d4 != 0 || D_8006C598 == 0xFF || (short)hud->unk44 <= 0 || hud->isOffScreen || !arg0 || (!(D_8006C74C == 0 && D_8006C64C == 0) && !(g_HudEntries[i].unk38 & 0x20)) ) {
            if (hud->movementFrame > 100) {
                hud->movementFrame = 0;
            }
            else if (hud->movementFrame > 50) {
                hud->movementFrame = 100 - hud->movementFrame;
            }
            
            if ((hud->movementFrame < 50) && (hud->movementFrame += deltaTime, hud->movementFrame < 50)) {
                var_s3 = 1;
            } else {
                hud->movementFrame = 50;
                hud->unk44 = 0;
            }
        } else if ( ((D_8006C74C == 0 && D_8006C64C == 0) || g_HudEntries[i].unk38 & 0x20) && (var_s3 = 1, D_8006C598 == 0 || hud->movementFrame != 50) ) {
            if (hud->movementFrame != 0) {
                if (hud->movementFrame < 50) {
                    hud->movementFrame = 100 - hud->movementFrame;
                }
                
                hud->movementFrame = hud->movementFrame + deltaTime;
                
                if (hud->movementFrame >= 110) {
                    hud->movementFrame = 0;
                }
            } else {
                hud->unk44 -= deltaTime;
            }
        }
        
        if ((hud->isOffScreen != 0) && (hud->movementFrame == 50)) {
            func_80028264(hud);
        }
        
        hud->unk1C.frame = func_80028378(&hud->unk1C, 0);
        
        if (arg0 && hud->unk30 != 0) {
            hud->unk30(hud);
        }
    }
    g_Hud.DAT_800719d4 = 0;
    return var_s3;
}

/**
 * ???() - func_800289C8() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/UXqpI
 */
/* Retail source: 0x800289C8..0x80028D30. POLY_FT4 fields follow
 * the PSYQ packet layout; sprite input coordinates are byte units. */
extern void* D_8006C664;
void func_8004E758(void*);
int* func_800289C8(SpriteData* arg0, int arg1, int arg2) {
    int var_s0 = 0;
    int var_s2 = 0;
    POLY_FT4* temp_s0;
    POLY_FT4* temp_s1 = D_8006C664;
    POLY_FT4* temp_t6;
    temp_s1->tag = 0x09000000;
    *(int*)&temp_s1->r0 = 0x2C808080;
    if ((arg0->unk6 & 0x60) != 0x60) temp_s1->code |= 2;
    temp_s1->x0 = arg1;
    temp_s1->x2 = arg1;
    temp_s1->y0 = arg2;
    temp_s1->y1 = arg2;
    temp_s1->tpage = arg0->unk6;
    temp_s1->clut = arg0->unk2;
    temp_s1->x1 = arg1 + (arg0->unk4 - arg0->unk0);
    temp_s1->y2 = arg2 + (arg0->unk5 - arg0->unk1);
    temp_s1->u0 = arg0->unk0;
    temp_s1->u1 = arg0->unk4;
    if ((temp_s1->u1 & 0xFF) != 0xFF) {
        temp_s1->u1++;
        temp_s1->x1++;
    } else var_s0 = 1;
    temp_s1->v0 = arg0->unk1;
    temp_s1->v2 = arg0->unk5;
    if ((temp_s1->v2 & 0xFF) != 0xFF) {
        temp_s1->v2++;
        temp_s1->y2++;
    } else var_s2 = 1;
    temp_s1->x3 = temp_s1->x1;
    temp_s1->y3 = temp_s1->y2;
    temp_s1->u2 = temp_s1->u0;
    temp_s1->u3 = temp_s1->u1;
    temp_s1->v1 = temp_s1->v0;
    temp_s1->v3 = temp_s1->v2;
    func_8004E758(temp_s1);
    temp_t6 = temp_s1 + 1;
    D_8006C664 = temp_t6;
    if (var_s0 != 0) {
        POLY_FT4* temp_s6 = D_8006C664;
        temp_s6->tag = temp_s1->tag;
        *(int*)&temp_s6->r0 = *(int*)&temp_s1->r0;
        temp_s6->x0 = temp_s1->x1;
        temp_s6->x2 = temp_s1->x1;
        temp_s6->x1 = temp_s1->x1 + 1;
        temp_s6->x3 = temp_s1->x1 + 1;
        temp_s6->y0 = temp_s1->y0;
        temp_s6->y1 = temp_s1->y0;
        temp_s6->y2 = temp_s1->y2;
        temp_s6->y3 = temp_s1->y2;
        temp_s6->u0 = temp_s1->u1;
        temp_s6->u2 = temp_s1->u1;
        temp_s6->u1 = temp_s1->u1;
        temp_s6->u3 = temp_s1->u1;
        temp_s6->v0 = temp_s1->v0;
        temp_s6->v1 = temp_s1->v0;
        temp_s6->v2 = temp_s1->v2;
        temp_s6->v3 = temp_s1->v2;
        temp_s6->tpage = temp_s1->tpage;
        temp_s6->clut = temp_s1->clut;
        func_8004E758(temp_t6);
        D_8006C664 = temp_s6 + 1;
    }
    if (var_s2 != 0) {
        temp_s0 = D_8006C664;
        temp_s0->tag = temp_s1->tag;
        *(int*)&temp_s0->r0 = *(int*)&temp_s1->r0;
        temp_s0->x0 = temp_s1->x0;
        temp_s0->x2 = temp_s1->x0;
        temp_s0->x1 = temp_s1->x1;
        temp_s0->x3 = temp_s1->x1;
        temp_s0->y0 = temp_s1->y2;
        temp_s0->y1 = temp_s1->y2;
        temp_s0->y2 = temp_s1->y2 + 1;
        temp_s0->y3 = temp_s1->y2 + 1;
        temp_s0->u0 = temp_s1->u0;
        temp_s0->u2 = temp_s1->u0;
        temp_s0->u1 = temp_s1->u1;
        temp_s0->u3 = temp_s1->u1;
        temp_s0->v0 = temp_s1->v2;
        temp_s0->v1 = temp_s1->v2;
        temp_s0->v2 = temp_s1->v2;
        temp_s0->v3 = temp_s1->v2;
        temp_s0->tpage = temp_s1->tpage;
        temp_s0->clut = temp_s1->clut;
        func_8004E758(temp_s0);
        D_8006C664 = temp_s0 + 1;
    }
    return (int*)temp_s1;
}

/**
 * ???() - func_80028D30()
 * Nearly matching
 * https://decomp.me/scratch/zr6ZQ
 */
/* Retail source hypothesis: asm/nonmatchings/hud/func_80028D30.s, 0x80028D30..0x800291B8. */
int* func_80028D30(SpriteData* arg0, short arg1, short arg2, int arg3) {
    int temp_a0;
    int var_s0;
    int var_s2;
    int var_t1;
    POLY_FT4* temp_s1;
    unsigned char temp_v1_2;
    unsigned char temp_v1_3;

    var_s0 = 0;
    var_s2 = 0;
    var_t1 = 0;

    temp_s1 = D_8006C664;
    temp_s1->tag = 0x09000000;
    *(int*)&temp_s1->r0 = 0x2C808080;

    if (arg3 & 8) var_t1 = arg3 >> 0x10;

    if (((arg0->unk6 & 0x60) != 0x60) || (arg3 & 0x10)) {
        temp_s1->code |= 0x02;
    }

    temp_s1->x0 = arg1;
    temp_s1->x2 = arg1;
    temp_s1->y0 = arg2;
    temp_s1->y1 = arg2;

    temp_s1->tpage = arg0->unk6;
    if (arg3 & 0x10) {
        temp_s1->tpage &= 0xFF9F;
    }

    temp_s1->clut = arg0->unk2;
    temp_a0 = arg0->unk5 - arg0->unk1;
    temp_s1->x1 = (arg1 + (arg0->unk4 - arg0->unk0));

    temp_s1->y2 = arg2 + temp_a0;
    temp_s1->u0 = arg0->unk0;
    temp_s1->u1 = arg0->unk4;
    temp_s1->v0 = arg0->unk1;
    temp_s1->v2 = arg0->unk5;

    if (var_t1 > 0) {
        MAX(var_t1, temp_a0);
        temp_s1->y0 += var_t1;
        temp_s1->y1 += var_t1;
        temp_s1->v0 += var_t1;
    }
    else if (var_t1 < 0) {
        var_t1 = -var_t1;
        MAX(var_t1, temp_a0);
        temp_s1->y2 = temp_s1->y0 + var_t1;
        temp_s1->v2 = temp_s1->v0 + var_t1;
    }

    if ((arg3 & 2) != 0) {
        temp_v1_2 = temp_s1->v0;
        temp_s1->v0 = temp_s1->v2;
        temp_s1->v2 = temp_v1_2;
        if (temp_s1->v2 != 0) {
            if (!(arg3 & 4)) {
                temp_s1->v2--;
            }
            temp_s1->y2++;
        }
        else {
            var_s2 = 1;
        }
    }
    else if ((temp_s1->v2 & 0xFF) != 0xFF) {
        if (!(arg3 & 4)) {
            temp_s1->v2++;
        }
        temp_s1->y2++;
    }
    else {
        var_s2 = 1;
    }

    if (arg3 & 1) {
        temp_v1_3 = temp_s1->u0;
        temp_s1->u0 = temp_s1->u1;
        temp_s1->u1 = temp_v1_3;
        if (temp_s1->u1 != 0) {
            if (!(arg3 & 4)) {
                temp_s1->u1--;
            }
            temp_s1->x1++;
        }
        else {
            var_s0 = 1;
        }
    }
    else if ((temp_s1->u1 & 0xFF) != 0xFF) {
        if (!(arg3 & 4)) {
            temp_s1->u1++;
        }
        temp_s1->x1++;
    }
    else {
        var_s0 = 1;
    }

    temp_s1->x3 = temp_s1->x1;
    temp_s1->y3 = temp_s1->y2;
    temp_s1->u2 = temp_s1->u0;
    temp_s1->u3 = temp_s1->u1;
    temp_s1->v1 = temp_s1->v0;
    temp_s1->v3 = temp_s1->v2;
    func_8004E758(temp_s1);

    D_8006C664 = temp_s1 + 1;

    if (var_s0 != 0) {
        POLY_FT4* temp_t6 = D_8006C664;

        temp_t6->tag = temp_s1->tag;
        *(int*)&temp_t6->r0 = *(int*)&temp_s1->r0;
        temp_t6->x0 = temp_s1->x1;
        temp_t6->x2 = temp_s1->x1;
        temp_t6->x1 = temp_s1->x1 + 1;
        temp_t6->x3 = temp_s1->x1 + 1;
        temp_t6->y0 = temp_s1->y0;
        temp_t6->y1 = temp_s1->y0;
        temp_t6->y2 = temp_s1->y2;
        temp_t6->y3 = temp_s1->y2;
        temp_t6->u0 = temp_s1->u1;
        temp_t6->u2 = temp_s1->u1;
        temp_t6->u1 = temp_s1->u1;
        temp_t6->u3 = temp_s1->u1;
        temp_t6->v0 = temp_s1->v0;
        temp_t6->v1 = temp_s1->v0;
        temp_t6->v2 = temp_s1->v2;
        temp_t6->v3 = temp_s1->v2;
        temp_t6->tpage = temp_s1->tpage;
        temp_t6->clut = temp_s1->clut;
        func_8004E758(temp_t6);
        D_8006C664 = temp_t6 + 1;

    }
    if (var_s2 != 0) {
        POLY_FT4* temp_s0;

        temp_s0 = D_8006C664;
        temp_s0->tag = temp_s1->tag;
        *(int*)&temp_s0->r0 = *(int*)&temp_s1->r0;
        temp_s0->x0 = temp_s1->x0;
        temp_s0->x2 = temp_s1->x0;
        temp_s0->x1 = temp_s1->x1;
        temp_s0->x3 = temp_s1->x1;
        temp_s0->y0 = temp_s1->y2;
        temp_s0->y1 = temp_s1->y2;
        temp_s0->y2 = temp_s1->y2 + 1;
        temp_s0->y3 = temp_s1->y2 + 1;
        temp_s0->u0 = temp_s1->u0;
        temp_s0->u2 = temp_s1->u0;
        temp_s0->u1 = temp_s1->u1;
        temp_s0->u3 = temp_s1->u1;
        temp_s0->v0 = temp_s1->v2;
        temp_s0->v1 = temp_s1->v2;
        temp_s0->v2 = temp_s1->v2;
        temp_s0->v3 = temp_s1->v2;
        temp_s0->tpage = temp_s1->tpage;
        temp_s0->clut = temp_s1->clut;
        func_8004E758(temp_s0);
        D_8006C664 = temp_s0 + 1;
    }
    return (int*)temp_s1;
}

/**
 * ???() - func_800291B8()
 * https://decomp.me/scratch/m95oz
 */
/* Retail source: USA Rev 0 PSX.EXE 0x800291B8..0x800293C4.
 * Confirmed exact across 131 words and the 62-artifact retail hash set.
 * Integer HUD pixels update once per rendered digit. Falsify with values 0,
 * 9, 10, and negative motion offsets against the rebuilt instruction span. */
extern unsigned char D_800674AC[];
extern unsigned char D_800674E8[];
extern short D_800719CC;
int func_800291B8(int arg0, int arg1, int arg2, int arg3) {
    int sp10;
    int sp18;
    int sp20;
    int temp_height;
    SpriteData* temp_v0;
    int temp_v0_addr;
    int temp_fp;
    int var_a1;
    int var_a2;
    int var_a3;
    int var_s1;
    int var_s2;
    int var_s3;
    int var_s4;
    int var_v0;

    temp_v0_addr = D_800719CC << 3;
    temp_v0_addr += (int)D_8006C788;
    temp_v0 = (SpriteData*)temp_v0_addr;
    temp_fp = temp_v0->unk4 - temp_v0->unk0;
    var_s4 = 0;
    var_a3 = arg0;
    temp_height = (temp_v0->unk5 - temp_v0->unk1) >> 1;
    __asm__ volatile ("" : "=r"(temp_height) : "0"(temp_height));
    sp10 = temp_height;
    var_v0 = arg3 >= 0 ? arg3 : -arg3;
    sp20 = ((var_v0 + 0xA) >> 1) - 1;
    if (var_a3 >= 0xA) {
        while (var_a3 >= 0xA) {
            var_a3 /= 0xA;
            var_s4 += 1;
        }
    }
    sp18 = (var_s4 + 1) * temp_fp;
    var_a3 = arg0;
    if (var_s4 < 0) return sp18;
    var_s3 = sp20 - var_s4;
    var_s2 = var_s4 * temp_fp + arg1;
    var_s1 = var_s4 * temp_fp;
    do {
        var_a2 = arg2;
        if (arg3 == 0) {
            var_a1 = arg1 + var_s1;
        } else {
            var_a2 = 60;
            if (sp20 < var_a2) {
                var_a2 = D_800674E8[var_s3];
                if (arg3 < 0) var_a2 = arg2 - var_a2;
                else var_a2 += arg2;
                var_a1 = arg1 + var_s1;
            } else {
                var_a1 = D_800674AC[var_s3];
                var_a2 = arg2;
                var_a1 = arg3 < 0 ? var_s2 - var_a1 : var_a1 + var_s2;
            }
        }
        var_s3 += 1;
        var_s4 -= 1;
        func_800289C8(&D_8006C788[D_800719CC + (var_a3 % 10)],
                      var_a1, var_a2 - sp10);
        var_v0 = -temp_fp;
        var_s2 += var_v0;
        var_s1 += var_v0;
        var_a3 /= 0xA;
    } while (var_s4 >= 0);
    return sp18;
}

/**
 * ???() - func_800293C4()
 * https://decomp.me/scratch/8rUnD
 */
/* Retail source: USA Rev 0 PSX.EXE 0x800293C4..0x80029674.
 * Values are integer HUD pixel coordinates; decimal digits are consumed once
 * per loop iteration. Confidence is confirmed by all 172 matching words and
 * the 62-artifact retail hash set. Falsify with paired values containing
 * zero digits and both signs of the integer motion offset. */
int func_800293C4(int arg0, int arg1, int arg2, int arg3, int arg4) {
    volatile int sp10;
    int sp18;
    int sp20;
    int sp28;
    int sp30;
    SpriteData* temp_v0;
    int temp_v0_addr;
    int temp_lo;
    int temp_v0_2;
    int var_a1;
    int var_a2;
    int var_s0;
    register int saved_arg3 __asm__("$21");
    register int var_s1 __asm__("$17");
    register int saved_arg4 __asm__("$23");
    int var_s2;
    int var_s3;
    int var_s4;
    int var_v0;

    sp10 = arg0;
    var_s0 = sp10;
    temp_v0_addr = D_800719CC;
    temp_v0 = D_8006C788;
    saved_arg4 = arg4;
    saved_arg3 = arg3;
    /* Keep GCC's zero initialization after the saved Y-coordinate move. */
    __asm__ ("move %0,$0" : "=r"(var_s1) : "r"(saved_arg3));
    temp_v0_addr <<= 3;
    temp_v0_addr += (int)temp_v0;
    temp_v0 = (SpriteData*)temp_v0_addr;
    sp18 = temp_v0->unk4 - temp_v0->unk0;
    sp20 = (temp_v0->unk5 - temp_v0->unk1) >> 1;
    var_v0 = saved_arg4 >= 0 ? saved_arg4 : -saved_arg4;
    sp30 = ((var_v0 + 0xA) >> 1) - 1;
    if (var_s0 >= 0xA) {
        while (var_s0 >= 0xA) {
            var_s0 /= 0xA;
            var_s1 += 1;
        }
    }
    var_s0 = arg1;
    var_s1 += 2;
    if (var_s0 >= 0xA) {
        while (var_s0 >= 0xA) {
            var_s0 /= 0xA;
            var_s1 += 1;
        }
    }
    sp28 = (var_s1 + 1) * sp18;
    var_s0 = arg1;
    if (var_s1 < 0) return sp28;
    temp_lo = var_s1 * sp18;
    var_s4 = sp30 - var_s1;
    var_s3 = temp_lo + arg2;
    var_s2 = temp_lo;
    do {
        if (var_s0 == 0) {
            var_s0 = -0x64;
        } else if (var_s0 < 0) {
            var_s0 = sp10;
        }
        var_a2 = saved_arg3;
        if (saved_arg4 == 0) {
            var_a1 = arg2 + var_s2;
        } else {
            if ((var_a2 = sp30) < 0x3C) {
                var_a2 = D_800674E8[var_s4];
                if (saved_arg4 < 0) var_a2 = saved_arg3 - var_a2;
                else var_a2 += saved_arg3;
                var_a1 = arg2 + var_s2;
            } else {
                var_a1 = D_800674AC[var_s4];
                var_a2 = saved_arg3;
                var_a1 = saved_arg4 < 0 ? var_s3 - var_a1 : var_a1 + var_s3;
            }
        }
        if (var_s0 < 0) {
            func_800289C8(&D_8006C788[D_800719CC + 0xA],
                          var_a1 + 4, var_a2 - sp20);
        } else {
            func_800289C8(&D_8006C788[D_800719CC + (var_s0 % 10)],
                          var_a1, var_a2 - sp20);
        }
        temp_v0_2 = -sp18;
        var_s3 += temp_v0_2;
        var_s2 += temp_v0_2;
        var_s4 += 1;
        var_s1 -= 1;
        var_s0 /= 0xA;
    } while (var_s1 >= 0);
    return sp28;
}

/**
 * ???() - func_80029674() - MATCHING
 * https://decomp.me/scratch/ek230
 */
int func_80029674(HudEntry* arg0, int* arg1, int* arg2) {
    int temp_t1;
    int temp_v1;
    int temp_a3;

    // Needs an extra variable to return to match
    int ret = 0;
    
    temp_t1 = arg0->unk3C;
    temp_v1 = arg0->unk3D;
    temp_a3 = D_8006C64C;
    
    if (!(arg0->displayMode & 1)) {
        if (arg0->displayMode & 2) {
            *arg2 -= temp_a3;
        } else {
            *arg2 -= (temp_v1 >> 1);
        }
    } else {
        *arg2 += temp_a3;
    }
    
    if (!(arg0->displayMode & 4)) {
        if (arg0->displayMode & 8) {
            *arg1 -= temp_t1;
        } else {
            *arg1 -= (temp_t1 >> 1);
        }
    }
    return ret;
}

extern unsigned char D_800674E8[];
void func_80029708(HudEntry* hud, int* frame, int* x, int* y) {
    unsigned char mode;
    if (*frame < 0) *frame = 0;
    if (*frame >= 60) *frame = 59;
    mode = hud->displayMode;
    if (mode & 1) {
        *y -= D_800674E8[*frame];
        *frame = -(unsigned char)hud->movementFrame;
    } else if (mode & 2) {
        *y += D_800674E8[*frame];
        *frame = (unsigned char)hud->movementFrame;
    } else if (mode & 4) {
        *x -= D_800674E8[*frame] * 2;
        *frame = -((unsigned char)hud->movementFrame + 60);
    } else if (mode & 8) {
        *x += D_800674E8[*frame] * 2;
        *frame = (unsigned char)hud->movementFrame + 60;
    }
}

/**
 * ???() - func_8002982C() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/s4WGn
 */
int func_8002982C(HudEntry* hudEntry) {
    int sp10;
    int sp14;
    int sp18;
    SpriteData* spriteData;
    spriteData = &D_8006C788[hudEntry->unk1C.frame];
    sp10 = hudEntry->unk0;
    sp14 = hudEntry->unk2;
    sp18 = hudEntry->movementFrame != 0 ? (hudEntry->movementFrame + 0xA) >> 1 : 0;
    func_80029674(hudEntry, &sp10, &sp14);
    func_80029708(hudEntry, &sp18, &sp10, &sp14);
    sp14 = sp14 - ((spriteData->unk5 - spriteData->unk1) >> 1);
    func_800289C8(spriteData, sp10, sp14);
    return spriteData->unk4 - spriteData->unk0;
}

/**
 * ???() - func_80029904() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/H9Zvm
 */
int func_80029904(HudEntry* hudEntry) {
    int sp10;
    int sp14;
    int sp18;
    int sp1C;
    int sp20;
    SpriteData* spriteData;
    int ret;
    spriteData = &D_8006C788[hudEntry->unk1C.frame];
    sp10 = hudEntry->unk0;
    sp14 = hudEntry->unk2;
    sp18 = hudEntry->movementFrame != 0 ? (hudEntry->movementFrame + 0xA) >> 1 : 0;
    func_80029674(hudEntry, &sp10, &sp14);
    sp1C = sp10;
    sp20 = sp14;
    func_80029708(hudEntry, &sp18, &sp1C, &sp20);
    sp20 = sp20 - ((spriteData->unk5 - spriteData->unk1) >> 1);
    func_800289C8(spriteData, sp1C, sp20);
    ret = (spriteData->unk4 - spriteData->unk0) + 0xA;
    sp10 = sp10 + ret;
    return ret + func_800291B8(hudEntry->unk40, sp10, sp14, sp18);
}

/*
 * ???() - func_8009A00() - MATCHING
 * https://decomp.me/scratch/hwKcy
 */
void func_80029A00(HudEntry* hudEntry) {
    int sp10;
    int sp14;
    int sp18;
    int sp1C;
    int sp20;

    sp10 = hudEntry->unk0;
    sp14 = hudEntry->unk2;
    if (hudEntry->movementFrame != 0) {
        sp18 = (hudEntry->movementFrame + 10) >> 1;
    } else {
        sp18 = 0;
    }
    func_80029674(hudEntry, &sp10, &sp14);
    sp1C = sp10;
    sp20 = sp14;
    func_80029708(hudEntry, &sp18, &sp1C, &sp20);
    func_800291B8(hudEntry->unk40, sp10, sp14, sp18);
}

int func_80029AA0(HudEntry* hudEntry) {
    int sp18;
    int sp1C;
    int sp20;
    int sp24;
    int sp28;
    int width;
    int first;
    int second;
    int argA;
    int argB;
    register int x __asm__("$6");
    SpriteData* spriteData = &D_8006C788[hudEntry->unk1C.frame];
    sp18 = hudEntry->unk0;
    sp1C = hudEntry->unk2;
    if (hudEntry->movementFrame != 0) sp20 = (hudEntry->movementFrame + 10) >> 1;
    else sp20 = 0;
    func_80029674(hudEntry, &sp18, &sp1C);
    sp24 = sp18;
    sp28 = sp1C;
    func_80029708(hudEntry, &sp20, &sp24, &sp28);
    sp28 -= (spriteData->unk5 - spriteData->unk1) >> 1;
    func_800289C8(spriteData, sp24, sp28);
    first = spriteData->unk4;
    second = spriteData->unk0;
    argA = hudEntry->unk40;
    argB = hudEntry->unk26;
    __asm__ volatile ("" : "=r"(x) : "r"(first), "r"(second), "r"(argA), "r"(argB), "0"(sp18));
    width = first - second + 10;
    sp18 = x + width;
    return width + func_800293C4(argA, argB, sp18, sp1C, sp20);
}

/**
 * ???() - func_80029BB0() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/omtIh
 */
int func_80029BB0(HudEntry* hudEntry) {
    int x;
    int y;
    int sp18;
    int sp1C;
    int sp20;
    SpriteData* sprData0;
    SpriteData* sprData1;
    int temp_s0;
    int temp_v0;
    temp_v0 = D_8006C738[hudEntry->unk1C.index].frame;
    sprData0 = &D_8006C788[temp_v0];
    sprData1 = temp_v0 == hudEntry->unk1C.frame ? &D_8006C788[temp_v0 + 1] : &D_8006C788[hudEntry->unk1C.frame];
    x = hudEntry->unk0;
    y = hudEntry->unk2;
    sp18 = hudEntry->movementFrame != 0 ? (hudEntry->movementFrame + 0xA) >> 1 : 0;
    func_80029674(hudEntry, &x, &y);
    sp1C = x;
    sp20 = y;
    func_80029708(hudEntry, &sp18, &sp1C, &sp20);
    sp20 = sp20 - ((sprData0->unk5 - sprData0->unk1) >> 1);
    func_800289C8(sprData0, sp1C, sp20);
    func_800289C8(sprData1, sp1C + 0x16, sp20 + 0xA);
    temp_s0 = (sprData0->unk4 - sprData0->unk0) + 0xA;
    x = x + temp_s0;
    return temp_s0 + func_800291B8(hudEntry->unk40, x, y, sp18);
}

extern int D_8006C7D0;
extern int D_8006C76C;
extern char* D_80069DC4[];
extern void func_8001FE48(int, int, int, int);
extern void func_8002E748(char*, int, int, int, int*);
extern int sprintf(char*, const char*, ...);
int func_80029CF8(HudEntry* hud) {
    char buffer[32];
    int x = hud->unk0;
    int y = hud->unk2;
    int frame;
    int halfWidth;
    int centered;
    int drawY;
    frame = hud->movementFrame ? ((unsigned char)hud->movementFrame + 10) >> 1 : 0;
    func_80029674(hud, &x, &y);
    func_80029708(hud, &frame, &x, &y);
    drawY = y;
    y = drawY - 4;
    func_8001FE48(x - 9, x + (unsigned char)hud->unk3C + 9, drawY - 6, drawY + 7);
    func_8002E748((char*)hud->unk28, x, y, 1, 0);
    if (D_8006C7D0 != 0) {
        sprintf(buffer, D_80069DC4[D_8006C76C]);
        halfWidth = func_8002EBB0(buffer) >> 1;
        centered = 256 - halfWidth;
        func_8001FE48(centered - 9, halfWidth + 265, 178, 191);
        func_8002E748(buffer, centered, 180, 1, 0);
    }
    return (unsigned char)hud->unk3C;
}

/**
 * ???() - func_80029E48()
 * https://decomp.me/scratch/dFXYA
 */
INCLUDE_ASM("asm/nonmatchings/hud", func_80029E48);

/**
 * ???() - func_8002A580() - MATCHING
 * https://decomp.me/scratch/gamSH
 */
void func_8002A580() {
    if (game.state == GAMESTATE_PAUSE) {
        return;
    }
    if (g_CurrentLevel == 44 && D_80071A04.unk0 != 0 && game.state == GAMESTATE_GAMEPLAY) {
        func_800289C8(&D_8006C788[g_Hud.reticleFrame], D_800714F4.x - 16, D_800714F4.y - 11);
    }
    else if (g_CurrentLevel == 25 && speedwayData.gameMode == 3 && (game.state == GAMESTATE_GAMEPLAY || game.state == GAMESTATE_PAUSE)) {
        func_800289C8(&D_8006C788[g_Hud.reticleFrame], D_800714F4.x - 16, D_800714F4.y - 11);
    }
    else if (D_8006C768 != 0) {
        func_800289C8(&D_8006C788[g_Hud.reticleFrame], 240, 109);
    }
}

/**
 * ???() - func_8002A6B4() - MATCHING
 * https://decomp.me/scratch/CXdDl
 */
void func_8002A6B4() {
    PlaySound(g_SoundTablePtr->pauseEnter, 0, 0);
}

/**
 * ???() - func_8002A6E4() - MATCHING
 * https://decomp.me/scratch/Mck3B
 */
void func_8002A6E4() {
    PlaySound(g_SoundTablePtr->pauseExit, 0, 0);
}

/**
 * ???() - func_8002A714() - MATCHING
 * https://decomp.me/scratch/omnBk
 */
void func_8002A714() {
    int sound = PlaySound(g_SoundTablePtr->pauseMove, 0, 0); 
    if (sound >= 0) {
        func_8003C140(sound, 0x640);
    }
}

/**
 * ???() - func_8002A754() - MATCHING
 * https://decomp.me/scratch/0JDAC
 */
void func_8002A754() {
    int sound = PlaySound(g_SoundTablePtr->changeVolume, 0, 0); 
    if (sound >= 0) {
        func_8003C140(sound, 0xC00); 
    }
}
