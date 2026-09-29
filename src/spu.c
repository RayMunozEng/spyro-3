#include "common.h"
#include "spu.h"

/* Retail source: 0x8003BABC..0x8003BB10. A moby type at +0x36
 * selects a per-type sound table; 0xFF means no sound. */
extern unsigned char* D_8006EE2C[];
int func_8003BABC(Moby* owner, int index, int selector) {
    short type = *(short*)((char*)owner + 0x36);
    unsigned char* table = D_8006EE2C[type];
    unsigned char id = *(table + index + 4);
    if (id == 0xFF) return -1;
    return ((int (*)(int, Moby*, int))PlaySound)(id, owner, selector);
}

/* Retail source: 0x8003BB10..0x8003BB50. A 0xFF table byte
 * means no sound; the caller-supplied third parameter is forwarded. */
extern unsigned char* D_8006C708;
int func_8003BB10(Moby* owner, int index, int selector) {
    unsigned char id = D_8006C708[index];
    if (id == 0xFF) return -1;
    return ((int (*)(int, Moby*, int))PlaySound)(id, owner, selector);
}

/** 
 * PlaySound() - func_8003BB50()
 * TODO
 */
INCLUDE_ASM("asm/nonmatchings/spu", PlaySound);

/* Retail source: asm/nonmatchings/spu/func_8003BE70.s,
 * 0x8003BE70..0x8003BEDC; ActiveSound entries are 44 bytes. */
void func_8003BE70(int index) {
    if (g_ActiveSounds[index].unk0 == 1) {
        g_ActiveSounds[index].unk0 = 5;
    } else if (g_ActiveSounds[index].unk0 == 2) {
        g_ActiveSounds[index].unk0 = 3;
        g_ActiveSounds[index].unk4 = 0;
    }
}

/* Retail source: asm/nonmatchings/spu/func_8003BEDC.s,
 * 0x8003BEDC..0x8003BF6C; 24 active sound entries, 44 bytes each. */
extern int D_8006C630;
void func_8003BEDC(void) {
    int i;
    D_8006C630 = 1;
    for (i = 0; i < 24; i++) {
        if ((unsigned int)(g_ActiveSounds[i].unk0 - 1) < 2 &&
            !(g_ActiveSounds[i].unk2 & 0x40)) {
            func_8003BE70(i);
        }
    }
}

extern unsigned char D_8006FCE5;
extern unsigned char D_8006FCE4;
int func_8003BF6C(int soundId, int index) {
    int offset;
    register int result __asm__("$2") = 0;
    if (index >= 0) {
        offset = index * 44;
        if (*(unsigned char*)((char*)&D_8006FCE5 + offset) == soundId) {
            result = (unsigned int)(*(unsigned char*)((char*)&D_8006FCE4 + offset) - 1) < 2;
        }
    }
    return result;
}
extern int D_8006FD0C;
int func_8003BFC0(Moby* soundPtr, int index) {
    int offset;
    register int result __asm__("$2") = 0;
    if (index >= 0) {
        offset = index * 44;
        if (*(int*)((char*)&D_8006FD0C + offset) == (int)soundPtr) {
            result = (unsigned int)(*(unsigned char*)((char*)&D_8006FCE4 + offset) - 1) < 2;
        }
    }
    return result;
}

/* Retail source: asm/nonmatchings/spu/func_8003C014.s,
 * 0x8003C014..0x8003C0B0; active sound entry stride is 44 bytes. */
void func_8004F178(Vector3D*, Vector3D*);
void func_8003C014(int index, Vector3D* source) {
    if (g_ActiveSounds[index].unk28 != 0 &&
        (unsigned int)(g_ActiveSounds[index].unk0 - 1) < 2) {
        func_8004F178((Vector3D*)&g_ActiveSounds[index].unk1C, source);
        g_ActiveSounds[index].unk2 |= 2;
    }
}

/**
 * ???() - func_8003C0B0() - MATCHING
 * Source of the bluto glitch, as there's no -1 check in here
 * If you pause during the start of the boat charge sound, and release charge while paused, it buffer underflows and writes to 8006fcd0
 * https://decomp.me/scratch/NVzfz
 */
void func_8003C0B0(int handle, int arg1) {
    g_ActiveSounds[handle].unk18 = (arg1 * ((g_SpuDefinitionsPtr[g_ActiveSounds[handle].unk1].unkC + g_SpuDefinitionsPtr[g_ActiveSounds[handle].unk1].unkE) / 2)) >> 12;
    g_ActiveSounds[handle].unk2 |= 8;
}

/* Retail source: 0x8003C140..0x8003C184. ActiveSound entries are
 * 44 bytes; the selector byte is +2 and the value word is +12. */
extern unsigned char D_8006FCE6;
extern int D_8006FCF0;
void func_8003C140(int index, int value) {
    int offset = index * 44;
    unsigned char flag = *(unsigned char*)((char*)&D_8006FCE6 + offset);
    *(int*)((char*)&D_8006FCF0 + offset) = value;
    *(unsigned char*)((char*)&D_8006FCE6 + offset) = flag | 0x10;
}

extern void func_8005E9B0(int, int);
extern void func_8005EB70(void*);
extern void func_8005EC1C(void*);
extern int D_8006FCF4;
extern int D_8006FCF8;

/* USA Rev 0 retail source: asm/nonmatchings/spu/func_8003C184.s,
 * 0x8003C184..0x8003C428. Each game update consumes one status byte for
 * each of 24 voices and advances 44-byte ActiveSound entries. Fade state 3
 * subtracts 0x400 integer volume units per update and clamps each channel at
 * zero. Confidence: exact; test vector: all 169 instructions match retail. */
void func_8003C184(void) {
    struct {
        unsigned char status[24];
        char fadeCommand[64];
        char stopCommand[64];
    } locals;
    register int startMask __asm__("$23");
    register int finishMask __asm__("$19");
    register int index __asm__("$18");
    register int offset __asm__("$17");
    register int one __asm__("$21");
    register int five __asm__("$22");
    register int tempMask __asm__("$16");
    register unsigned char *active __asm__("$20");
    register unsigned char *stack __asm__("$29");
    int value;
    int bit;

    startMask = 0;
    finishMask = 0;
    func_8005EB70(stack + 0x10);
    index = 0;
    one = 1;
    five = 5;
    active = &D_8006FCE4;
    offset = 0;
    do {
        switch (*active) {
        case 0: {
            unsigned char voiceStatus = *(index + stack + 0x10);
            if (voiceStatus != one) {
                register int three __asm__("$2") = 3;
                if (voiceStatus != three) {
                    break;
                }
            }
            finishMask |= one << index;
            *active = five;
            break;
        }
        case 1:
            func_8003C428(index);
            if (*active == one) {
                *(unsigned char *)((char *)&D_8006FCE4 + offset) = 2;
                startMask |= one << index;
            } else {
                finishMask |= one << index;
            }
            break;
        case 2: {
            unsigned char voiceStatus = *(index + stack + 0x10);
            register int three __asm__("$2") = 3;
            if (voiceStatus == three) {
                finishMask |= one << index;
                *active = five;
            } else {
                func_8003C428(index);
                active += sizeof(ActiveSound);
                goto next;
            }
            break;
        }
        case 3:
            bit = one << index;
            *(int *)(locals.fadeCommand + 0) = bit;
            *(int *)(locals.fadeCommand + 4) = 0x13;
            *(short *)(locals.fadeCommand + 0x14) = 0;
            value = *(int *)((char *)&D_8006FCF4 + offset) - 0x400;
            *(int *)((char *)&D_8006FCF4 + offset) = value;
            if (value < 0) {
                *(int *)((char *)&D_8006FCF4 + offset) = 0;
            }
            value = *(int *)((char *)&D_8006FCF8 + offset) - 0x400;
            *(int *)((char *)&D_8006FCF8 + offset) = value;
            if (value < 0) {
                *(int *)((char *)&D_8006FCF8 + offset) = 0;
            }
            if (*(int *)((char *)&D_8006FCF4 + offset) != 0 ||
                *(int *)((char *)&D_8006FCF8 + offset) != 0) {
                *(short *)(locals.fadeCommand + 8) = *(int *)((char *)&D_8006FCF8 + offset);
                *(short *)(locals.fadeCommand + 10) = *(int *)((char *)&D_8006FCF4 + offset);
                func_8005EC1C(locals.fadeCommand);
                active += sizeof(ActiveSound);
                goto next;
            }
            *(unsigned char *)((char *)&D_8006FCE4 + offset) = five;
            finishMask |= bit;
            break;
        case 4:
            tempMask = one << index;
            *(int *)(locals.stopCommand + 0) = tempMask;
            *(int *)(locals.stopCommand + 4) = 0x10;
            *(short *)(locals.stopCommand + 0x14) = 0;
            func_8005EC1C(locals.stopCommand);
            finishMask |= tempMask;
            *active = five;
            break;
        case 5:
            finishMask |= one << index;
            *active = 0;
            break;
        }
        active += sizeof(ActiveSound);
next:
        index += 1;
        offset += sizeof(ActiveSound);
    } while (index < 24);
    if (startMask != 0) {
        func_8005E9B0(1, startMask);
    }
    if (finishMask != 0) {
        func_8005E9B0(0, finishMask);
    }
    D_8006C630 = 0;
}

INCLUDE_ASM("asm/nonmatchings/spu", func_8003C428);

/* USA Rev 0 EXE 0x8003C79C..0x8003C994: update a sound's
 * two integer gain channels from its distance and planar angle. */
extern int D_8006C400;
extern int D_8006E344;
extern short D_8006E040;
extern unsigned char D_8006FCE4;
extern char D_8006E020;
extern short D_80065920[];
void func_8004F1C8(void*, void*, void*);
int func_8004E880(int, int, int);
int func_8003C994(int, void*);
void func_8003C79C(void* arg0, void* arg1) {
    register unsigned char* active __asm__("$16") = (unsigned char*)arg0;
    register unsigned char* output __asm__("$17") = (unsigned char*)arg1;
    int delta[3];
    register int gain __asm__("$3");
    int left;
    int right;
    int angle;
    register int product __asm__("$7");
    register int absolute __asm__("$2");
    register int coefficient __asm__("$2");
    register ActiveSound* base __asm__("$5");
    __asm__ volatile ("" : "=r"(active) : "0"(active));
    __asm__ volatile ("" : "=r"(output) : "0"(output));

    gain = func_8003C994(active[1], *(char**)(active + 0x28) + 12);
    __asm__ volatile ("" : "=r"(gain) : "0"(gain));
    *(int*)(active + 8) = gain;
    if (gain <= 0) {
        base = (ActiveSound*)&D_8006FCE4;
        __asm__ volatile ("" : "=r"(base) : "0"(base));
        func_8003BE70((ActiveSound*)active - base);
        return;
    }
    if (D_8006C400) {
        func_8004F1C8(delta, *(char**)(active + 0x28) + 12, &D_8006E020);
        angle = func_8004E880(delta[0], delta[1], 1);
        angle = ((angle - D_8006E040) >> 4) & 0xFF;
        if (angle > 0x80) angle -= 0x100;
        left = *(int*)(active + 8);
        right = left;
        if (angle > 0) {
            coefficient = D_80065920[angle];
            __asm__ volatile ("" : "=r"(coefficient) : "0"(coefficient));
            product = coefficient * left;
            __asm__ volatile ("" : "=r"(product) : "0"(product));
            absolute = product;
            if (product < 0) absolute = -absolute;
            left = absolute >> 12;
        } else if (angle < 0) {
            coefficient = D_80065920[angle & 0xFF];
            __asm__ volatile ("" : "=r"(coefficient) : "0"(coefficient));
            product = coefficient * left;
            __asm__ volatile ("" : "=r"(product) : "0"(product));
            absolute = product;
            if (product < 0) absolute = -absolute;
            right = absolute >> 12;
        }
    } else {
        left = *(int*)(active + 8);
        right = left;
    }
    if (D_8006E344 == 1 && !(active[2] & 0x80)) {
        right >>= 2;
        left >>= 2;
    }
    if (right < 0) right = 0;
    if (right >= 0x3000) right = 0x2FFF;
    if (left < 0) left = 0;
    if (left >= 0x3000) left = 0x2FFF;
    *(int*)(output + 4) |= 3;
    *(int*)(active + 0x14) = right;
    *(short*)(output + 8) = right;
    *(int*)(active + 0x10) = left;
    *(short*)(output + 0xA) = left;
}

/* USA Rev 0 EXE 0x8003C994..0x8003CB00: position-based sound gain.
 * Distances are quartered before looking up each 20-byte descriptor. */
extern int D_8006E044;
extern char D_80070328;
extern char* D_8006C6A0;
extern int D_8006C3F8;
int func_8004EDE8(void*, int);
int func_8003C994(int arg0, void* source) {
    register int index __asm__("$17") = arg0;
    int delta[3];
    register unsigned char* descriptor __asm__("$3");
    int gain;
    int distance;
    int nearDist;
    int farDist;
    int maxGain;
    register int stride __asm__("$3");
    register unsigned char* base __asm__("$4");
    char* basis = (char*)&D_8006E044;
    __asm__ volatile ("" : "=r"(index) : "0"(index));
    if ((unsigned int)(*(int*)basis - 9) < 2) {
        gain = 0;
        func_8004F1C8(delta, source, basis - 0x24);
    } else {
        gain = 0;
        func_8004F1C8(delta, source, &D_80070328);
    }
    distance = func_8004EDE8(delta, 1) >> 2;
    stride = index * 5;
    base = (unsigned char*)D_8006C6A0;
    descriptor = (unsigned char*)(stride * 4 + (int)base);
    farDist = *(unsigned short*)(descriptor + 10);
    nearDist = *(unsigned short*)(descriptor + 8);
    if (farDist != nearDist) {
        if (nearDist >= distance) {
            gain = *(unsigned short*)(descriptor + 6);
        } else if (distance >= farDist) {
            gain = *(unsigned short*)(descriptor + 4);
        } else {
            maxGain = *(unsigned short*)(descriptor + 6);
            gain = ((farDist - distance) * maxGain) / (farDist - nearDist);
            if (gain < *(unsigned short*)(descriptor + 4)) gain = *(unsigned short*)(descriptor + 4);
            if (maxGain < gain) gain = maxGain;
        }
    }
    return (gain * D_8006C3F8) / 10;
}

/* USA Rev 0 EXE 0x8003CB00..0x8003CCF0: update a positional
 * sound's panning and amplitude from the actor and listener vectors. */
extern char D_800703C0 __asm__("D_80070328+152");
void func_8004F110(void*, int);
void func_8003CB00(void* arg0, void* arg1) {
    register unsigned char* owner __asm__("$17") = (unsigned char*)arg0;
    register unsigned char* sound __asm__("$20") = (unsigned char*)arg1;
    int delta[3];
    register int angle __asm__("$19");
    register int side __asm__("$18");
    int index;
    int magnitude;
    int value;
    int volume;
    __asm__ volatile ("" : "=r"(owner) : "0"(owner));
    __asm__ volatile ("" : "=r"(sound) : "0"(sound));

    *(int*)(sound + 4) |= 0x10;
    func_8004F1C8(delta, &D_80070328, *(char**)(owner + 0x28) + 12);
    angle = func_8004E880(delta[0], delta[1], 0);
    if (owner[2] & 2) {
        index = (angle - func_8004E880(*(int*)(owner + 0x1C), *(int*)(owner + 0x20), 0)) & 0xFF;
        magnitude = func_8004EDE8(owner + 0x1C, 0);
        side = (magnitude * D_80065920[index]) >> 12;
    } else {
        side = 0;
    }
    angle += 0x80;
    func_8004F178((Vector3D*)delta, (Vector3D*)&D_800703C0);
    func_8004F110(delta, 6);
    index = (angle - func_8004E880(delta[0], delta[1], 0)) & 0xFF;
    magnitude = func_8004EDE8(delta, 0);
    value = 0x1000 + (((magnitude >> 1) * D_80065920[index]) >> 12);
    volume = (*(int*)(owner + 0x18) * value) / (0x1000 - side);
    *(short*)(sound + 0x14) = volume;
    if (*(unsigned short*)(sound + 0x14) < ((*(int*)(owner + 0x18) * 3) << 6 >> 8)) {
        *(short*)(sound + 0x14) = ((*(int*)(owner + 0x18) * 3) << 6 >> 8);
    }
    if (*(unsigned short*)(sound + 0x14) > ((*(int*)(owner + 0x18) * 5) << 6 >> 8)) {
        *(short*)(sound + 0x14) = ((*(int*)(owner + 0x18) * 5) << 6 >> 8);
    }
    owner[2] &= 0xFD;
}

/* Retail source: 0x8003CCF0..0x8003CDA0. These are raw
 * initialization words passed to PSYQ helpers, not SFX identities. */
void func_8005EBFC(void);
void func_8005E630(void*);
void func_8005EC1C(void*);
void func_8005E9B0(int, int);
void func_8005E600(int);
void func_8003CCF0(void) {
    int common[10];
    int reverb[15];
    char* c = (char*)common;
    char* r = (char*)reverb;
    func_8005EBFC();
    *(int*)(c + 0) = 3;
    *(short*)(c + 6) = 0x3CCC;
    *(short*)(c + 4) = 0x3CCC;
    func_8005E630(common);
    *(int*)(r + 4) = 0xFF13;
    *(short*)(r + 8) = 0x2FFF;
    *(short*)(r + 10) = 0x2FFF;
    *(short*)(r + 20) = 0x400;
    *(int*)(r + 36) = 1;
    *(int*)(r + 40) = 1;
    *(int*)(r + 0) = 0xFFFFFF;
    *(int*)(r + 44) = 3;
    *(short*)(r + 48) = 0;
    *(short*)(r + 50) = 0;
    *(short*)(r + 52) = 0;
    *(short*)(r + 54) = 0;
    *(short*)(r + 56) = 0xF;
    func_8005EC1C(reverb);
    func_8005E9B0(0, 0xFFFFFF);
    func_8005E600(0);
}
