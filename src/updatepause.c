#include "common.h"

/* Retail source: asm/nonmatchings/updatepause/func_800565A0.s,
 * 0x800565A0..0x8005663C. Selector updates once per caller invocation;
 * all branches write a state code to D_8006FBD0. */
extern int D_8006C650;
extern int D_8006C5BC;
extern int D_8006C5C8;
extern int D_8006C508;
extern int D_8006FA38;
extern int D_8006FA3C;
extern int D_8006FBD0;
void func_800565A0(void) {
    register int value __asm__("$2");
    if (D_8006C650 != 0) {
        int kind = D_8006C5BC;
        if (kind == 11 || kind == 22) { value = 6; goto done; }
        value = 5; goto done;
    }
    value = D_8006C5C8;
    if (value > 0) { value = 3; goto done; }
    value = D_8006C508;
    if (value != 0) { value = 1; goto done; }
    value = D_8006FA38;
    if (value < 0) { value = 2; goto done; }
    value = D_8006FA3C;
    if (value != 0) { value = 4; goto done; }
    value = 2;
done:
    __asm__ volatile ("" : "=r"(value) : "0"(value));
    D_8006FBD0 = value;
}

extern int D_8006FBC4, D_8006FBC8, D_8006FBCC, D_8006FBD4;
extern int D_8006FBEC, D_80070148;
extern unsigned char D_80070114;
extern unsigned char D_80070133, D_80070134, D_8007014E;
extern short D_8007015A, D_800719D2;
extern unsigned char D_80067602, D_80067603, D_80067604, D_80067605;
extern unsigned char D_80067606, D_80067607, D_80067608, D_80067609;
extern unsigned char D_8006760C[];
extern unsigned char D_80066FCC[], D_80070300[];
extern unsigned char D_80071586, D_80071587, D_80071588;
extern int D_8006E344, D_8006E49C;
extern char* D_8006C654;
void ClearCheatBuffer(void);
void func_8003BEDC(void);
void PlaySound(int, int, int);
/* Retail source: USA Rev 0 PSX.EXE 0x8005663C..0x8005693C (192 words).
 * Pause modes and list indices are integer state values; unlock entries and
 * flags are bytes, and one call initializes one pause transition. Confidence
 * is exact: falsify with any cited-span word or executable/overlay hash
 * mismatch against the retail manifest.
 */
void func_8005663C(void) {
    register int* pauseState __asm__("$5") = &D_8006FBC8;
    register int count __asm__("$4");
    register int value __asm__("$2");
    register int mode __asm__("$3") = 1;

    __asm__ volatile("" : "=r"(pauseState) : "0"(pauseState));
    *pauseState = 0;
    D_8006FBCC = mode;
    pauseState[-1] = 0;
    __asm__ volatile("" ::: "memory");
    count = D_80070148;
    value = 1;
    D_8006FBD4 = 0;
    D_80070114 = value;
    D_80070133 = value;
    D_80070134 = value;
    D_8007014E = 0;
    D_8006FBEC = 0;

    if (count == mode) {
        mode = D_8006C5BC;
        D_8006FBD0 = 0xD;
        D_8007015A = 0;
        count = 2;
        if (mode != 10) {
            D_8006760C[count] = D_80067602;
            count = 3;
        }
        if (D_80070300[D_80066FCC[0x11]] & 1)
            D_8006760C[count++] = D_80067603;
        if ((D_8006C5BC != 20) && D_80071586)
            D_8006760C[count++] = D_80067604;
        if (D_80070300[D_80066FCC[0x1B]] & 1)
            D_8006760C[count++] = D_80067605;
        if ((D_8006C5BC != 30) && D_80071587)
            D_8006760C[count++] = D_80067606;
        if (D_80070300[D_80066FCC[0x25]] & 1)
            D_8006760C[count++] = D_80067607;
        if ((D_8006C5BC != 40) && D_80071588)
            D_8006760C[count++] = D_80067608;
        if (D_80070300[D_80066FCC[0x2F]] & 1)
            D_8006760C[count++] = D_80067609;
        value = 0xFF;
        D_8006760C[count] = value;
        value = 1;
        goto done;
    } else if (count == 2) {
        pauseState[2] = 7;
        *pauseState = 0x15;
    } else if (count == 3) {
        pauseState[2] = 0;
        *pauseState = 0xF;
    } else {
        func_800565A0();
    }
    value = 1;
done:
    D_800719D2 = value;
    D_8006E344 = 4;
    ClearCheatBuffer();
    func_8003BEDC();
    PlaySound((unsigned char)D_8006C654[0x16], 0, 0x40);
    D_8006E49C = 1;
}

/* Retail source: asm/nonmatchings/updatepause/func_8005693C.s,
 * 0x8005693C..0x800569C0; level table entries have 16-byte stride. */
extern int D_80011254, D_8007013C, D_80070144;
extern int D_8006E470, D_8006C58C, D_80070138, D_80070108;
extern int D_8007015C, D_80072098, D_8006DBE0[];
void func_8004E7D4(void*, int, int);
int CDLoadAsync(int, void*, int, int);
void func_8005693C(void) {
    func_8004E7D4((void*)D_80011254, D_8007013C, D_80070144);
    CDLoadAsync(D_8006E470, (void*)(D_80070108 + D_8007015C),
                D_80070138, D_80072098 + D_8006DBE0[D_8006C58C * 4]);
}

/* Retail source: asm/nonmatchings/updatepause/func_800569C0.s,
 * 0x800569C0..0x80056A3C; the descriptor stride is eight bytes. */
typedef struct { int first, second; } PauseDiscEntry;
extern int D_8006C76C, D_8006FCE0, D_8006E470, D_80070138;
extern PauseDiscEntry D_8006DE68[];
int CDLoadAsync(int, void*, int, int);
void func_800569C0(void) {
    int index = D_8006C76C;
    CDLoadAsync(D_8006E470, (void*)(D_8006FCE0 + 0x8000),
                D_8006DE68[index].second, D_8006DE68[index].first);
    D_80070138 = D_8006DE68[D_8006C76C].second;
}

extern int D_8006DE74;
extern int D_8006DE70;
void func_80056A3C(void) {
    int base = D_8006FCE0;
    int sector = D_8006E470;
    int displacement = 0x8000;
    register int* size __asm__("$16") = &D_8006DE74;
    CDLoadAsync(sector, (void*)(base + displacement), *size, D_8006DE70);
    D_80070138 = *size;
}

extern Moby* (*SpawnMoby)(int, Moby*);
extern Moby* D_8006C65C;
extern unsigned char D_80070130, D_80070131;
extern signed char D_80070132;
extern unsigned char D_8007014F;
extern char D_8006E00C[];
extern int D_80065860;
extern int D_80070140;
void func_8004ECF4(SHORTMATRIX*, void*);
void func_8004ED6C(SHORTMATRIX*, void*, Vector3D*);
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
/* Retail source: USA Rev 0 PSX.EXE 0x80056A98..0x80056CF0 (150 words).
 * Resource offsets and copy lengths are bytes; the upload rectangle uses PSX
 * VRAM pixel coordinates, while Moby angles are stored as retail angle bytes.
 * One call performs this pause preview setup/load step. Confidence is exact:
 * falsify with a cited-span word or final executable/overlay hash mismatch.
 */
void func_80056A98(void) {
    RECT image;
    Vector3D vector;
    SHORTMATRIX matrix;
    register char* buffer __asm__("$20");
    register char* data __asm__("$19");
    register unsigned char* rotation __asm__("$18");
    register char* transform __asm__("$17");
    register char* scratch __asm__("$16");
    register int value __asm__("$2");
    register int remaining __asm__("$3");

    remaining = D_8006FCE0;
    value = 0x8000;
    buffer = (char*)(remaining + value);
    __asm__ volatile("" : "=r"(buffer) : "0"(buffer));

    {
        register Moby* current __asm__("$3") = D_8006C65C;
        __asm__ volatile("" : "=r"(current) : "0"(current));
        data = buffer;
        if (current == 0) {
            register SHORTMATRIX* matrixArg __asm__("$4");

            __asm__ volatile("" ::: "$3", "$5");
            current = SpawnMoby(0x78, 0);
            D_8006C65C = current;
            if (current == 0) goto load_data;
            scratch = (char*)&matrix;
            __asm__ volatile("" : "=r"(scratch) : "0"(scratch));
            __asm__ volatile("" ::: "memory", "$5");
            rotation = &D_80070130;
            value = rotation[0];
            __asm__ volatile("" ::: "$4");
            matrixArg = (SHORTMATRIX*)scratch;
            __asm__ volatile("" : "=r"(matrixArg) : "0"(matrixArg));
            current->angle.roll = value;
            {
                register Moby* spawned __asm__("$3") = D_8006C65C;
                value = D_80070131;
                __asm__ volatile("" ::: "$17");
                transform = D_8006E00C;
                spawned->angle.pitch = value;
            }
            {
                register Moby* spawned __asm__("$3") = D_8006C65C;
                value = (unsigned char)D_80070132;
                spawned->angle.yaw = value;
            }
            func_8004ECF4(matrixArg, transform);
            {
                register void* vectorSource __asm__("$5");
                matrixArg = (SHORTMATRIX*)scratch;
                vectorSource = rotation - 0x18;
                scratch = (char*)&vector;
                __asm__ volatile("" : "=r"(matrixArg), "=r"(vectorSource),
                                     "=r"(scratch) : "0"(matrixArg),
                                     "1"(vectorSource), "2"(scratch));
                func_8004ED6C(matrixArg, vectorSource,
                              (Vector3D*)scratch);
            }
            func_8004F194(&D_8006C65C->position, (Vector3D*)scratch,
                          (Vector3D*)(transform + 0x14));
            {
                register Moby* spawned __asm__("$3") = D_8006C65C;
                register int colour __asm__("$2") = D_80065860;
                __asm__ volatile("" : "=r"(spawned), "=r"(colour) :
                                     "0"(spawned), "1"(colour));
                *(int*)&spawned->colour = colour;
            }
            value = 1;
            goto set_state;
        } else {
            if (current->lowDrawDistance != 0) goto load_data;
            value = 0x10;
            current->lowDrawDistance = value;
            value = 2;
            goto set_state;
        }
    }
set_state:
    D_8007014F = value;

load_data:
    data += 4;
    value = *(int*)data;
    remaining = D_80011254;
    __asm__ volatile("" ::: "$16");
    scratch = (char*)&D_80070144;
    __asm__ volatile("" : "=r"(scratch) : "0"(scratch));
    value -= remaining;
    value -= 4;
    remaining = D_80070138;
    data += value;
    *(int*)scratch = value;
    remaining -= value;
    D_80070138 = remaining;
    {
        register int segmentSize __asm__("$5") = *(int*)data;

        value = (int)(data + 4);
        *(int*)(scratch - 0x3C) = value;
        value = -0x800;
        data += segmentSize;
        remaining -= segmentSize;
        D_80070138 = remaining;
        remaining += 0x7FF;
        remaining &= value;
        *(int*)(scratch + 0x18) = segmentSize;
        *(char**)(scratch - 8) = data;
        D_80070138 = remaining;
    }

    __asm__ volatile("" ::: "$4");
    DrawSync(0);
    image.x = 0x200;
    image.y = 0;
    image.w = 0x200;
    image.h = D_80070138 / 0x400;
    LoadImage(&image, data);
    DrawSync(0);

    {
        register void* copySource __asm__("$4") = *(void**)(scratch - 8);
        register int copyDestination __asm__("$5") = D_80011254;
        register int copySize __asm__("$6") = *(int*)scratch;

        copySize += 4;
        __asm__ volatile("" : "=r"(copySource), "=r"(copyDestination),
                             "=r"(copySize) : "0"(copySource),
                             "1"(copyDestination), "2"(copySize));
        *(int*)scratch = copySize;
        func_8004E7D4(copySource, copyDestination, copySize);
    }
    func_8004E7D4((void*)D_80011254, (int)buffer, *(int*)scratch);
    func_8004E7D4(buffer, *(int*)(scratch - 0x3C),
                  *(int*)(scratch + 0x18));
    value = *(int*)(scratch - 8);
    remaining = *(int*)scratch;
    *(char**)(scratch - 0x3C) = buffer;
    D_80070140 = value + remaining;
}

extern char* D_8006C788;
extern char* D_8006C738;
extern short D_800719D0;
extern int D_80070150, D_80070154;
int func_80027934(int);
/* Retail source: USA Rev 0 PSX.EXE 0x80056CF0..0x80056ECC (119 words).
 * Buffer offsets and copy lengths are bytes, the upload rectangle uses PSX
 * VRAM pixel coordinates, and one call completes this pause resource load and
 * relocation step. Confidence is exact: falsify with any word mismatch in the
 * cited span or any executable/overlay hash mismatch against the manifest.
 */
void func_80056CF0(void) {
    RECT image;
    register int* sizeState __asm__("$17");
    register char* buffer __asm__("$18");
    register char* data __asm__("$16");
    register int size __asm__("$2");
    register int remaining __asm__("$3");

    remaining = D_8006FCE0;
    size = 0x8000;
    sizeState = &D_80070144;
    __asm__ volatile("" : "=r"(sizeState) : "0"(sizeState));
    buffer = (char*)(remaining + size);
    __asm__ volatile("" : "=r"(buffer) : "0"(buffer));
    size = *(int*)(remaining + 0x8004);
    remaining = D_80011254;
    data = buffer + 4;
    size -= remaining;
    size -= 4;
    data += size;
    remaining = D_80070138;
    *sizeState = size;
    remaining -= size;
    D_80070138 = remaining;

    {
        register int segmentSize __asm__("$5");

        segmentSize = *(int*)data;
        *(int*)((char*)sizeState - 0x3C) = (int)(data + 4);
        data += segmentSize;
        remaining -= segmentSize;
        D_80070138 = remaining;
        *(int*)((char*)sizeState + 0x18) = segmentSize;

        segmentSize = *(int*)data;
        size = (int)(data + 4);
        *(int*)((char*)sizeState - 0x38) = size;
        data += segmentSize;
        remaining -= segmentSize;
        size = *(int*)((char*)sizeState + 0x18);
        size += segmentSize;
        D_80070138 = remaining;
        *(int*)((char*)sizeState + 0x18) = size;
    }
    *(char**)((char*)sizeState - 8) = data;
    D_80070138 = ((remaining << 1) + 0x7FF) & -0x800;

    __asm__ volatile("" ::: "$4");
    DrawSync(0);
    image.x = 0x300;
    image.y = 0;
    image.w = 0x100;
    image.h = D_80070138 / 0x400;
    LoadImage(&image, data);
    DrawSync(0);

    {
        register void* copySource __asm__("$4") =
            *(void**)((char*)sizeState - 8);
        register int copyDestination __asm__("$5") = D_80011254;
        register int copySize __asm__("$6") = *sizeState;

        copySize += 4;
        __asm__ volatile("" : "=r"(copySource), "=r"(copyDestination),
                             "=r"(copySize) : "0"(copySource),
                             "1"(copyDestination), "2"(copySize));
        *sizeState = copySize;
        func_8004E7D4(copySource, copyDestination, copySize);
    }
    func_8004E7D4((void*)D_80011254, (int)buffer, *sizeState);
    func_8004E7D4(buffer, *(int*)((char*)sizeState - 0x3C),
                  *(int*)((char*)sizeState + 0x18));

    {
        register int first __asm__("$3") =
            *(int*)((char*)sizeState - 0x3C);
        register char* oldSprites __asm__("$6") = D_8006C788;
        register int second __asm__("$2") =
            *(int*)((char*)sizeState - 0x38);
        register char* oldDefinitions __asm__("$5") = D_8006C738;

        *(char**)((char*)sizeState - 0x3C) = buffer;
        D_8006C788 = buffer;
        first -= (int)buffer;
        second -= first;
        *(int*)((char*)sizeState - 0x38) = second;
        D_80070150 = (int)oldSprites;
        D_80070154 = (int)oldDefinitions;
        D_8006C738 = (char*)second;
    }
    D_800719D0 = (unsigned char)D_8006C738[func_80027934(1) * 8 + 2];
}

extern int D_8006C598, D_8006C648;
extern Moby* D_8006C65C;
extern int D_8006FBC8, D_8006FBCC, D_8006FBD4;
extern unsigned short D_8006E040;
extern Moby* D_8006E788[];
extern int D_8006E78C;
extern unsigned char D_80070115;
extern short D_80070116;
extern int D_80070118, D_8007011C, D_80070120;
extern Vector3D D_80070124;
extern unsigned char D_80070130, D_80070131;
extern signed char D_80070132;
extern short D_80070136, D_80070158;
extern char* (*UpdateParticles)(int);
int func_800359A4(short*, int);
void func_8004F178(Vector3D*, Vector3D*);
void func_80055854(Moby**, int);
void func_80034DAC(Moby*);

/* Retail source: USA Rev 0 PSX.EXE 0x80056ECC..0x80057154 (162 words).
 * Pause state and frame delta are runtime scalar units; camera angle is a
 * signed 12-bit-style value reduced by four fractional bits. This update runs
 * once per paused frame. Confidence is confirmed only by exact instruction and
 * executable comparisons; falsify with any word mismatch in the cited span. */
void func_80056ECC(void) {
    register int offset __asm__("$2");
    int shift;

    if ((D_8006FBC8 == 0x15) && (D_8006FBD4 == 1)) {
        func_8004F178(&D_8006C65C->position, &D_80070124);
    }
    if (D_8006C598 == 0) {
        register short* randomTimer __asm__("$16") = &D_80070116;
        if (func_800359A4(randomTimer, 2) != 0) {
            *randomTimer = (rand() & 0x7F) + 0x1E;
            D_80070115 = rand() & 1;
        }
    }

    D_80070118 = 0x800;
    if (D_8006FBC8 == 3) {
        offset = D_8006FBCC + 8;
    } else {
        offset = D_8006FBCC - 1;
    }
    D_80070120 = 0x6E - offset * 0x87;
    __asm__ volatile ("" ::: "memory");
    {
        register int* coordinate __asm__("$5") = &D_80070120;
        register int vertical __asm__("$3") = D_80070158;
        register unsigned int direction __asm__("$4") = D_80070115;
        vertical -= 5;
        *coordinate += (vertical * 0x87) >> 1;

        if (direction != 0) {
            D_8007011C = 0x1AE;
            D_80070132 = ((short)D_8006E040 >> 4) - 0x40;
        } else {
            D_8007011C = -0x1AE;
            D_80070132 = ((short)D_8006E040 >> 4) + 0x40;
        }
    }

    if (D_80070136 != 0) {
        shift = D_80070136 / 8 - 1;
        if (shift >= 7) {
            shift = 6;
        }
        D_8007011C <<= shift;
    }

    D_80070130 = 0;
    D_80070131 = 0;
    if (D_8006C65C != 0) {
        D_8006E788[0] = D_8006C65C;
        D_8006E78C = 0;
        func_80055854(D_8006E788, 2);
        if (D_8006C648 >= 3) {
            func_80055854(D_8006E788, D_8006C648 + 0x7FFFFFFE);
        }
        func_80034DAC(D_8006C65C);
    }
    if (UpdateParticles != 0) {
        UpdateParticles(D_8006C648);
    }
}

extern int D_8006E48C, D_80070110;
extern unsigned char D_80070114;
int func_8005E074(int, void*);
int func_8005E0BC(int, void*, void*);
void func_8005F5FC(char*, ...);
CdLoc* CdIntToPos(int, CdLoc*);

/* Retail source: USA Rev 0 PSX.EXE 0x80057154..0x80057340 (123 words).
 * State values are unsigned bytes; seek offsets are byte counts converted to
 * 0x800-byte CD sectors. One call advances at most one asynchronous preseek
 * state. Confidence: exact; falsify with any cited-span word or final hash
 * mismatch. */
void func_80057154(void) {
    unsigned char command;
    register unsigned char* state __asm__("$17");

    if (D_8006E48C != 0) return;
    state = &D_80070114;
    if (*state == 0) return;
    command = 0x80;

    if (*state == 0xFF) {
        if (func_8005E074(1, 0) == 2) *state = 0;
        return;
    }
    if (*state < 0x80) {
        if (*state == 1) {
            D_80070110 = D_8006DE68[D_8006C76C].first;
        } else if (*state == 2) {
            D_80070110 = D_80072098 + D_8006DBE0[D_8006C58C * 4 + 2];
        } else {
            func_8005F5FC("bad pause preseek %d\n", *state);
        }
        D_80070114 = 0x80;
        return;
    }
    if (*state == 0x80) {
        if (func_8005E074(1, 0) == 2) {
            func_8005E0BC(0xE, &command, 0);
            *state = 0x81;
        }
        return;
    }
    if (*state == 0x81) {
        if (func_8005E074(1, 0) == 2) {
            register int seekOffset __asm__("$4") = D_80070110;
            register int* base __asm__("$2");
            register CdLoc* location __asm__("$16");
            __asm__ volatile ("" : "=r"(seekOffset) : "0"(seekOffset));
            base = &D_8006E470;
            location = (CdLoc*)((char*)base + 8);
            CdIntToPos(*base + seekOffset / 0x800, location);
            func_8005E0BC(2, location, 0);
            *state = 0x82;
        }
        return;
    }
    if (*state == 0x82) {
        if (func_8005E074(1, 0) == 2) {
            func_8005E0BC(0x16, 0, 0);
            *state = 0xFF;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80057340);

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80057834);

/**
 * ???() - func_80058408() - MATCHING
 * Ready to add, but there's a weird struct in here
 * Primitive example is in here too
 * https://decomp.me/scratch/5iaVQ
 */
typedef struct {
    unsigned char tag[4];
    unsigned char r0, g0, b0;
    unsigned char code;
    short x0, y0;
    short w, h;
} PauseTile;
extern PauseTile* D_8006C664;
extern int* func_800289C8(void*, short, short);
extern void func_8002ECA8(void);
extern void func_8004E758(PauseTile*);
void func_80058408(void) {
    PauseTile* temp_s0;
    struct {
        char sp10;
        char sp11;
        short sp12;
        signed char sp14;
        char sp15;
        short sp16;
    } unk;
    temp_s0 = D_8006C664;
    unk.sp14 = -1;
    unk.sp15 = 0x7F;
    unk.sp16 = 0x168;
    unk.sp10 = 0;
    unk.sp11 = 0;
    unk.sp12 = 0;
    temp_s0->tag[3] = 3;
    temp_s0->code = 0x60;
    temp_s0->r0 = 1;
    temp_s0->g0 = 1;
    temp_s0->b0 = 1;
    temp_s0->y0 = 0x41;
    temp_s0->x0 = 0x80;
    temp_s0->w = 0x100;
    temp_s0->h = 0x80;
    func_8004E758(temp_s0);
    D_8006C664 = temp_s0 + 1;
    func_800289C8(&unk, 0x80, 0x41);
    func_8002ECA8();
}
