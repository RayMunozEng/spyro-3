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

/* Retail source: USA Rev 0 PSX.EXE 0x80057340..0x80057834
 * (317 words). Raw function bytes SHA-256:
 * ee1dc9f7fd061a237cbbd6d56cc39da241cfadbb59829a5ac283bef89b239ecb.
 * One call consumes the current pause input flags and updates one pause-menu
 * command transition. Command rows have a 12-byte stride; command selectors
 * and sentinels are bytes, menu states are signed integers, and input masks
 * retain their retail bit values. Confidence: exact. Falsifiable test:
 * compare all 454 instruction/relocation records, the generated 44-entry
 * jump table, the full PSX.EXE SHA-256, and every corrected/encrypted overlay
 * hash through build_multiproc.py. */
extern unsigned char D_80067570[];
extern int D_8006E53C;
extern unsigned char g_CheatFlags[];
void func_8002A6B4();
void func_8002A6E4();
void func_8002A714();
#define M2C_FIELD_57340(expr, type_ptr, offset) (*(type_ptr)((signed char *)(expr) + (offset)))
void func_80057340(void *input0) {
    register unsigned char *var_a0 asm ("$4") = input0;
    register int *state asm ("$16");
    int input;
    unsigned char command;
    register int value asm ("$2");
    register int short_value asm ("$2");
    register int *counter asm ("$6");
    register unsigned char *row asm ("$5");
    register int *counter2 asm ("$5");
    register int *final_state asm ("$4");
    register int row_index asm ("$3");
    register int row_offset asm ("$2");

    input = D_8006E53C;
    if (input & 0x810) {
        goto cancel_path;
    }
    if (D_8007014E != 0) {
        goto cancel_path;
    }
    if (M2C_FIELD_57340(&g_CheatFlags, unsigned char *, 4) != 0) {
        goto cancel_path;
    }
    if (!(input & 0x40)) {
        goto horizontal_input;
    }
    row_index = D_8006FBD0;
    __asm__ volatile ("" : "=r"(row_index) : "0"(row_index));
    var_a0 = D_80067570;
    __asm__ volatile ("" : "=r"(var_a0) : "0"(var_a0));
    row_offset = row_index * 12;
    __asm__ volatile ("" : "=r"(row_offset) : "0"(row_offset));
    row_offset += (int)var_a0;
    command = *(unsigned char *)(row_offset + D_8006FBCC);
    if (command != 0x22) {
        goto command_switch;
    }

cancel_path:
    if ((D_8006FBD0 == 0xE) && !(D_8006E53C & 0x800)) {
        func_8002A6B4();
        D_8006FBCC = 1;
        func_800565A0();
        D_8006FBC8 = 0;
        goto finish;
    }
    state = &D_8006FBC8;
    if (*state == 0) {
        goto activate;
    }
    if (*state != 3) {
        goto finish;
    }
    if (!(D_8006E53C & 0x800)) {
        goto finish;
    }
activate:
    if (D_8007014E == 0) {
        func_8002A6E4();
    }
    *state = 1;
    goto finish;

command_switch:
    switch (command) {
    case 10:
        func_8002A6E4();
        D_8006FBC8 = 0xB;
        goto finish;
    case 11:
    case 12:
        func_8002A6E4();
        D_8006FBC8 = 0xC;
        goto finish;
    case 1:
        func_8002A6E4();
        value = 1;
        goto store_state;
    case 2:
        func_8002A6E4();
        value = 0xF;
        goto reset_state;
    case 4:
        func_8002A6E4();
        D_8006FBCC = 1;
        D_8006FBD0 = 7;
        __asm__ volatile ("" ::: "memory");
        value = 0x15;
        goto reset_state;
    case 5:
        func_8002A6E4();
        D_8006FBCC = 1;
        D_8006FBD0 = 0xE;
        __asm__ volatile ("" ::: "memory");
        value = 3;
reset_state:
        D_8006FBC8 = value;
        D_8006FBC4 = 0;
        D_8006FBD4 = 0;
        goto finish;
    case 28:
        func_8002A6B4();
        D_8006FBC8 = 7;
        goto finish;
    case 29:
        func_8002A6B4();
        D_8006FBCC = 1;
        func_800565A0();
        goto finish;
    case 9:
        func_8002A6B4();
        D_8006FBCC = 2;
        D_8006FBD0 = 0xF;
        goto finish;
    case 7:
        func_8002A6E4();
        D_8006FBC8 = 8;
        goto finish;
    case 8:
        func_8002A6E4();
        D_8006FBC8 = 9;
        goto finish;
    case 36:
        func_8002A6E4();
        value = 1;
        D_8007015A = 0;
        D_8006FBC8 = value;
        goto finish;
    case 37:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x11;
        goto store_short;
    case 38:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0xA;
        goto store_short;
    case 39:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x1B;
        goto store_short;
    case 40:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x14;
        goto store_short;
    case 41:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x25;
        goto store_short;
    case 42:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x1E;
        goto store_short;
    case 43:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x2F;
        goto store_short;
    case 44:
        func_8002A6E4();
        __asm__ volatile ("" ::: "memory");
        short_value = 0x28;
store_short:
        D_8007015A = short_value;
        value = 1;
store_state:
        D_8006FBC8 = value;
        goto finish;
    default:
        goto finish;
    }

horizontal_input:
    if (input & 0x1000) {
        func_8002A714();
        counter = &D_8006FBCC;
        value = *counter - 1;
        *counter = value;
        if (value > 0) {
            goto finish;
        }
        row_index = D_8006FBD0;
        var_a0 = D_80067570;
        row_offset = row_index * 12;
        row_index = D_8006FBCC;
        row = (unsigned char *)(row_offset + (int)var_a0);
        row_index = (int)row + row_index;
        if (*(unsigned char *)(row_index + 1) == 0xFF) {
            goto finish;
        }
        var_a0 = (unsigned char *)counter;
        row_index = (int)row;
        row = (unsigned char *)0xFF;
        do {
            ++*(int *)var_a0;
        } while (*(unsigned char *)(row_index + D_8006FBCC + 1) != (int)row);
        goto finish;
    }
    if (input & 0x4000) {
        func_8002A714();
        counter2 = &D_8006FBCC;
        ++*counter2;
        row_index = D_8006FBD0;
        var_a0 = D_80067570;
        row_offset = row_index * 12;
        row_index = D_8006FBCC;
        row_offset += (int)var_a0;
        row_offset += row_index;
        if (*(unsigned char *)row_offset == 0xFF) {
            *counter2 = 1;
        }
    }

finish:
    if (M2C_FIELD_57340(&g_CheatFlags, unsigned char *, 4) != 0) {
        final_state = &D_8006FBC8;
        if (*final_state == 1) {
            goto force_cheat_state;
        }
        if (*final_state <= 0) {
            goto function_end;
        }
        if (*final_state >= 9) {
            goto function_end;
        }
        if (*final_state < 6) {
            goto function_end;
        }
force_cheat_state:
        *final_state = 0xA;
    }
function_end:
    return;
}
#undef M2C_FIELD_57340


/* Retail source: USA Rev 0 SCUS-94467, PSX.EXE 0x80057834..0x80058408.
 * Pause state dispatch and speech row selection run once per caller invocation.
 * Speech rows are 12 bytes; selectors are unsigned bytes, LBA offsets are signed
 * words, track IDs are signed halfwords, and lengths are unsigned halfwords.
 * Fade values are signed words/halfwords updated in retail steps of 16.
 * Falsifiable vectors: pause states 0..25 and default 26, input bits 0x4000/0x1000,
 * speech sentinel 255 and byte wrap 0/255, fades -1/0/16/254/255/256,
 * signed image-size rounding at -1024/-1/0/1023/1024 and warp selectors 59/60.
 * Confidence: complete retail executable and overlay hash match.
 * Empty register constraints emit no instructions. The old-style cheat-update
 * call preserves retail's lack of argument setup after func_80057154. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
int CDLoadTime();
int ProcessCheatBuffer();
int func_800285A4(int);
int func_800498C0();
void func_8004F984(int, int, int);
int func_80052918(int, int);
void func_80053F50(int);
void func_800584BC(int, int);
int func_atlas_8007A1A8();
int func_options_800777C8();
extern int D_8006C3F4;
extern unsigned int D_8006C550;
extern unsigned int D_8006C704;
extern int D_8006FA44;
extern int D_80070104;
extern int D_options_8007ABE0;
extern unsigned char *speechData[];
extern unsigned char warpRead asm("g_CheatFlags+0x4");
extern unsigned char warpWrite asm("g_CheatFlags+0x04");
extern int (*unk_ovlheader_80074374)();

void func_80057834(void) {
    struct { RECT first; RECT second; } frame;
    register int level2 asm("$2");
    register int level3 asm("$3");
    register unsigned char **table3 asm("$3");
    register unsigned char *loopRoot5 asm("$5");
    register int terminator6 asm("$6");
    register int var_a0 asm("$4");
    register unsigned int cheatMode5 asm("$5");
    short temp_v0_3;
    register int temp_a0 asm("$4");
    register int *pauseRoot asm("$16");
    register unsigned char *cheatRoot asm("$7");
    register unsigned int cheatValue asm("$6");
    register int input asm("$3");
    register int one3 asm("$17");
    register short *fadeRoot asm("$4");
    register int temp_a0_3 asm("$4");
    register int *counter3 asm("$3");
    register int *counter2 asm("$2");
    register int counterValue2 asm("$2");
    register int counterValue3 asm("$3");
    register int fade4 asm("$4");
    register int temp_a1 asm("$5");
    register int temp_v0_4 asm("$2");
    int temp_v0_5;
    int temp_v0_7;
    register int temp_v0_8 asm("$2");
    int temp_v1_2;
    register int var_a1 asm("$5");
    register int imageWidth2 asm("$2");
    register int expectedMode2 asm("$2");
    register int drawMode4 asm("$4");
    register int track6 asm("$6");
    register int length5 asm("$5");
    register int var_a1_2 asm("$5");
    int var_a1_3;
    register int var_v0_2 asm("$2");
    register unsigned int *temp_s0_2 asm("$16");
    register unsigned int *temp_s0_3 asm("$16");
    register unsigned int var_s0 asm("$16");
    register unsigned char **temp_a0_2 asm("$4");
    register unsigned char **temp_a1_2 asm("$5");
    register unsigned int temp_v0 asm("$2");
    register unsigned int temp_v0_2 asm("$2");
    unsigned char temp_v0_9;
    register unsigned int temp_v1 asm("$3");
    void *temp_a0_4;
    void *temp_s0;
    void *temp_v0_6;
    register void *var_v0 asm("$2");

    if (D_80070133 != 0) {
        ProcessCheatBuffer();
    }
    pauseRoot = &D_8006FBC8;
    __asm__("" : "=r"(pauseRoot) : "0"(pauseRoot));
    if (*pauseRoot != 0x13) {
        func_80056ECC();
    }
    cheatRoot = (unsigned char *)g_CheatFlags + 0x17;
    __asm__("" : "=r"(cheatRoot) : "0"(cheatRoot));
    cheatValue = *cheatRoot;
    __asm__ volatile("" : "=r"(cheatValue) : "0"(cheatValue) : "memory");
    temp_a0 = cheatValue & 0xFF;
    __asm__("" : "=r"(temp_a0) : "0"(temp_a0));
    if ((temp_a0 != 0) && (*pauseRoot == 0)) {
        input = D_8006E53C;
        if (input & 0x4000) {
            temp_v0 = cheatValue - 1;
            *cheatRoot = temp_v0;
            if (!(temp_v0 & 0xFF)) {
                level2 = D_8006C76C;
                __asm__("" : "=r"(level2) : "0"(level2));
                table3 = speechData;
                __asm__("" : "=r"(table3) : "0"(table3), "r"(level2));
                level2 <<= 2;
                __asm__("" : "=r"(level2) : "0"(level2));
                temp_a0_2 = (unsigned char **)(level2 + (int)table3);
                if (**temp_a0_2 != 0xFF) {
                    loopRoot5 = cheatRoot;
                    __asm__("" : "=r"(loopRoot5) : "0"(loopRoot5));
                    terminator6 = 255;
                    __asm__("" : "=r"(terminator6) : "0"(terminator6));
                    do {
                        temp_v0_2 = *loopRoot5 + 1;
                        *loopRoot5 = temp_v0_2;
                    } while (*(((temp_v0_2 & 0xFF) * 0xC) + *temp_a0_2) != terminator6);
                }
            }
            level3 = D_8006C76C;
            temp_a0 = g_CheatFlags[23];

            level3 <<= 2;
            __asm__("" : "=r"(level3) : "0"(level3));
            temp_a1 = (int)*(unsigned char **)((char *)speechData + level3);
            if (M2C_FIELD(((temp_a0 * 0xC) + temp_a1), unsigned char *, -0xC) != 0xFF) {
                temp_v1 = temp_a0 - 1;
                __asm__("" : "=r"(temp_v1) : "0"(temp_v1));
                var_v0 = (void *)((temp_v1 * 0xC) + temp_a1);
                temp_a0_3 = D_8006C3F4;
                goto block_18;
            }
        } else {
            temp_v0 = input & 0x1000;
            __asm__("" : "=r"(temp_v0) : "0"(temp_v0));
            if (temp_v0) {
                level2 = D_8006C76C;
                __asm__("" : "=r"(level2) : "0"(level2));
                table3 = speechData;
                __asm__("" : "=r"(table3) : "0"(table3), "r"(level2));
                if (((temp_a1_2 = (unsigned char **)(level2 * 4 + (int)table3), (M2C_FIELD(((temp_a0 * 0xC) + *temp_a1_2), unsigned char *, -0xC) != 0xFF)) && (temp_v1 = cheatValue + 1, *cheatRoot = temp_v1, (M2C_FIELD((((temp_v1 & 0xFF) * 0xC) + *temp_a1_2), unsigned char *, -0xC) != 0xFF))) || (*cheatRoot = 1U, (**temp_a1_2 != 0xFF))) {
                    temp_v1 = g_CheatFlags[23];
                    temp_a0 = D_8006C76C;
                    __asm__("" : "=r"(temp_v1), "=r"(temp_a0) : "0"(temp_v1), "1"(temp_a0));
                    temp_v1 -= 1;
                    __asm__("" : "=r"(temp_v1) : "0"(temp_v1));
                    temp_a0 <<= 2;
                    __asm__("" : "=r"(temp_a0) : "0"(temp_a0));
                    var_v0 = (void *)(temp_v1 * 12);
                    __asm__("" : "=r"(var_v0) : "0"(var_v0));
                    temp_v1 = (int)*(unsigned char **)((char *)speechData + temp_a0);
                    temp_a0_3 = D_8006C3F4;
                    __asm__("" : "=r"(temp_a0_3) : "0"(temp_a0_3), "r"(temp_v1));
                    var_v0 = (char *)var_v0 + temp_v1;
block_18:
                    temp_v1 = M2C_FIELD(var_v0, int *, 8);
                    track6 = M2C_FIELD(var_v0, short *, 2);
                    __asm__("" : "=r"(temp_v1), "=r"(track6) : "0"(temp_v1), "1"(track6));
                    length5 = M2C_FIELD(var_v0, unsigned short *, 4);
                    temp_a0_3 += temp_v1;
                    func_8004F984(temp_a0_3, temp_a0_3 + length5, track6);
                }
            }
        }
    } else {
        func_80057154();
        if (D_80070133 != 0) {
            ((void (*)())func_80057340)();
        }
    }
    switch (D_8006FBC8) {
    case 0:
    case 3:
        fadeRoot = &D_80070136;
        __asm__("" : "=r"(fadeRoot) : "0"(fadeRoot));
        if (*fadeRoot > 0) {
            temp_v0_3 = *fadeRoot - 0x10;
            *fadeRoot = temp_v0_3;
            if (temp_v0_3 < 0) {
                *fadeRoot = 0;
            }
        }
        func_800285A4(1);
        goto block_118;
    case 11:
        func_800285A4(1);
        pauseRoot = &D_8006FA3C;
        __asm__("" : "=r"(pauseRoot) : "0"(pauseRoot));
        temp_v0 = *pauseRoot;
        one3 = 3;
        __asm__("" : "=r"(one3) : "0"(one3), "r"(temp_v0));
        if (temp_v0 == one3) {
            func_800498C0();
        } else {
            unk_ovlheader_80074374();
            if (*pauseRoot == 2) {
                D_8006FA44 = 4;
            } else {
                D_8006FA44 = one3;
            }
        }
        goto block_118;
    case 12:
        func_800285A4(1);
        D_8006C650 = 2;
        D_8006FBC8 = 1;
        goto block_118;
    case 1:
        D_8006E49C = 0;
        D_800719D2 = 0;
        func_800285A4(1);
        D_80070148 = 0;
        D_8006E344 = 0;
        goto block_118;
    case 13:
        counter3 = &D_8006FBD4;
        __asm__("" : "=r"(counter3) : "0"(counter3));
        counterValue2 = *counter3;
        fade4 = D_8006C598;
        __asm__("" : "=r"(fade4) : "0"(fade4), "r"(counterValue2));
        *counter3 = counterValue2 + 1;
        if (fade4 > 0) {
            temp_v0_4 = fade4 - 0x10;
            D_8006C598 = temp_v0_4;
            if (temp_v0_4 < 0) {
                D_8006C598 = 0;
            }
            goto block_69;
        } else {
            D_80070133 = 1;
            D_8006FBC8 = 0;
        }
        goto block_118;
    case 21:
        D_80070133 = 0;
        if (CDLoadTime() == 0) {
            counter3 = &D_8006FBD4;
            __asm__("" : "=r"(counter3) : "0"(counter3));
            if ((*counter3 >= 5) && (D_8006E48C == 0) && (D_80070114 == 0)) {
                D_8006FBC8 = 0x16;
                *counter3 = 0;
            } else if (func_800285A4(0) == 0) {
                counter3 = &D_8006FBD4;
                __asm__("" : "=r"(counter3) : "0"(counter3));
                temp_v0_5 = *counter3 + 1;
                *counter3 = temp_v0_5;
                __asm__ volatile("" ::: "memory");
                if (temp_v0_5 == 1) {
                    if (D_8006C65C != 0) {
                        temp_s0 = D_8006C65C->mobyTag;
                        func_8004F178(&D_80070124, &D_8006C65C->position);
                        D_8006C65C->position.x = 0x200;
                        D_8006C65C->position.y = 0x200;
                        D_8006C65C->position.z = 0x200;
                        temp_v0_6 = M2C_FIELD(temp_s0, void **, 0x10);
                        if (temp_v0_6 != 0) {
                            M2C_FIELD(temp_v0_6, int *, 0) = 0x200;
                            M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x10), int *, 4) = 0x200;
                            M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x10), int *, 8) = 0x200;
                        }
                    }
                } else {
                    D_80070104 = 1;
                }
            }
        }
        goto block_118;
    case 15:
        D_80070133 = 0;
        if (CDLoadTime() == 0) {
            counter3 = &D_8006FBD4;
            __asm__("" : "=r"(counter3) : "0"(counter3));
            if ((*counter3 >= 5) && (D_8006E48C == 0) && (D_80070114 == 0)) {
                D_8006FBC8 = 0x10;
                D_8006FBD0 = 0;
                *counter3 = 0;
            } else {
                *counter3 += 1;
            }
            counterValue3 = D_8006C598;
            __asm__("" : "=r"(counterValue3) : "0"(counterValue3));
            if (counterValue3 < 0xFF) {
                var_v0_2 = counterValue3 + 0x10;
                goto block_67;
            }
        }
        goto block_118;
    case 22:
        if (D_8006FBD4 == 0) {
            if (D_8006FBC8 == 0x10) {
                func_800569C0();
            } else {
                func_80056A3C();
            }
        }
        counter2 = &D_8006FBD4;
        __asm__("" : "=r"(counter2) : "0"(counter2));
        counterValue3 = *counter2;
        D_8006FBC8 = 0x17;
        *counter2 = counterValue3 + 1;
        goto block_118;
    case 16:
        if (D_8006FBD4 == 0) {
            D_80070134 = 0;
            D_80070136 = 0;
            if (D_8006FBC8 == 0x10) {
                func_800569C0();
            } else {
                func_80056A3C();
            }
        }
        counter2 = &D_8006FBD4;
        __asm__("" : "=r"(counter2) : "0"(counter2));
        counterValue3 = *counter2;
        fade4 = D_8006C598;
        __asm__("" : "=r"(fade4) : "0"(fade4), "r"(counterValue3));
        *counter2 = counterValue3 + 1;
        __asm__ volatile("" ::: "memory");
        if (fade4 < 0xFF) {
            var_v0_2 = fade4 + 0x10;
block_67:
            D_8006C598 = var_v0_2;
            if (var_v0_2 >= 0x100) {
                D_8006C598 = 0xFF;
            }
block_69:
            D_80070136 = (short) D_8006C598;
            goto block_118;
        }
        D_8006FBC8 = 0x11;
        goto block_118;
    case 17:
    case 23:
        if (CDLoadTime() == 0) {
            expectedMode2 = 17;
            __asm__("" : "=r"(expectedMode2) : "0"(expectedMode2));
            pauseRoot = &D_8006FBC8;
            __asm__("" : "=r"(pauseRoot) : "0"(pauseRoot));
            if (*pauseRoot == expectedMode2) {
                func_80056A98();
                *pauseRoot = 0x13;
            } else {
                func_80056CF0();
                *pauseRoot = 0x19;
                D_options_8007ABE0 = 0;
            }
            D_80070134 = 1;
            D_80070114 = 2;
        }
        goto block_118;
    case 19:
        if (D_8006C76C == 0) {
            func_atlas_8007A1A8();
        }
        goto block_118;
    case 25:
        func_options_800777C8();
        goto block_118;
    case 24:
        if (CDLoadTime() == 0) {
            if (D_8006FBD4 == 0) {
                func_8005693C();
            }
            D_8006FBC8 = 0x14;
        }
        goto block_118;
    case 18:
        if (CDLoadTime() == 0) {
            pauseRoot = &D_8006FBD4;
            __asm__("" : "=r"(pauseRoot) : "0"(pauseRoot));
            temp_v0_7 = *pauseRoot;
            if (temp_v0_7 == 0) {
                func_8005693C();
            }
            counterValue2 = *pauseRoot;
            counterValue3 = D_8006C598;
            __asm__("" : "=r"(counterValue3) : "0"(counterValue3), "r"(counterValue2));
            *pauseRoot = counterValue2 + 1;
            __asm__ volatile("" ::: "memory");
            if (counterValue3 < 0xFF) {
                temp_v0_8 = counterValue3 + 0x10;
                D_8006C598 = temp_v0_8;
                if (temp_v0_8 >= 0x100) {
                    D_8006C598 = 0xFF;
                }
            } else {
                D_8006FBC8 = 0xE;
            }
        }
        goto block_118;
    case 14:
        if (CDLoadTime() == 0) {
            imageWidth2 = 512;
            var_a1 = D_80070138;
            __asm__("" : "=r"(var_a1) : "0"(var_a1), "r"(imageWidth2));
            frame.first.x = imageWidth2;
            frame.first.y = 0;
            frame.first.w = imageWidth2;
            fade4 = (int)D_80070108;
            counterValue3 = D_8007015C;
            __asm__("" : "=r"(counterValue3) : "0"(counterValue3), "r"(fade4));
            temp_s0_2 = (unsigned int *)(fade4 + counterValue3);
            if (var_a1 < 0) {
                var_a1 += 0x3FF;
            }
            drawMode4 = 0;
            __asm__("" : "=r"(drawMode4) : "0"(drawMode4), "r"(var_a1));
            imageWidth2 = var_a1 >> 10;
            __asm__("" : "=r"(imageWidth2) : "0"(imageWidth2));
            frame.first.h = imageWidth2;
            DrawSync(drawMode4);
            LoadImage(&frame.first, (unsigned long *)temp_s0_2);
            DrawSync(0);
            D_80070134 = 1;
            func_800565A0();
            D_8006FBC8 = 0xD;
            D_80070114 = 1;
            D_8006FBD4 = 0;
            D_80070104 = 0;
        }
        goto block_118;
    case 20:
        if (CDLoadTime() == 0) {
            imageWidth2 = 512;
            var_a1_2 = D_80070138;
            __asm__("" : "=r"(var_a1_2) : "0"(var_a1_2), "r"(imageWidth2));
            frame.second.x = imageWidth2;
            frame.second.y = 0;
            frame.second.w = imageWidth2;
            fade4 = (int)D_80070108;
            counterValue3 = D_8007015C;
            __asm__("" : "=r"(counterValue3) : "0"(counterValue3), "r"(fade4));
            temp_s0_3 = (unsigned int *)(fade4 + counterValue3);
            if (var_a1_2 < 0) {
                var_a1_2 += 0x3FF;
            }
            drawMode4 = 0;
            __asm__("" : "=r"(drawMode4) : "0"(drawMode4), "r"(var_a1_2));
            imageWidth2 = var_a1_2 >> 10;
            __asm__("" : "=r"(imageWidth2) : "0"(imageWidth2));
            frame.second.h = imageWidth2;
            DrawSync(drawMode4);
            LoadImage(&frame.second, (unsigned long *)temp_s0_3);
            DrawSync(0);
            D_80070134 = 1;
            if (D_8007014E == 0) {
                func_800565A0();
            }
            D_8006C598 = 0;
            D_8006FBC8 = 0xD;
            D_80070114 = 1;
            D_8006FBD4 = 0;
            D_8006C788 = (char *) D_80070150;
            D_8006C738 = (char *) D_80070154;
            temp_v0_9 = M2C_FIELD(((func_80027934(1) * 8) + D_8006C738), unsigned char *, 2);
            D_80070104 = 0;
            D_800719D0 = (short) temp_v0_9;
        }
        goto block_118;
    case 7:
        D_80070148 = 0;
        func_800584BC(5, 0U);
        goto block_118;
    case 9:
        var_s0 = D_8006C550;
        var_a1_3 = 1;
        if (var_s0 < (unsigned int) D_8006C704) {
            one3 = 0x3FE;
            __asm__("" : "=r"(one3) : "0"(one3));
loop_103:
            if (var_a1_3 != 0) {
                if (M2C_FIELD(var_s0, short *, 0x36) == one3) {
                    temp_a0_4 = M2C_FIELD(var_s0, void **, 0);
                    if ((M2C_FIELD(temp_a0_4, int *, 0x40) == D_8006C5C8) && (M2C_FIELD(temp_a0_4, int *, 0x34) == 0)) {
                        func_80052918(0, D_8006C550 + (M2C_FIELD(temp_a0_4, int *, 0x30) * 0x58));
                        var_a1_3 = 0;
                    }
                }
                var_s0 += 0x58;
                if (var_s0 < (unsigned int) D_8006C704) {
                    goto loop_103;
                }
            }
        }
        goto block_118;
    case 8:
        temp_v1_2 = D_8006C5BC % 10;
        if (temp_v1_2 == 7) {
            func_800584BC(0, D_8006C5BC - 7);
            return;
        }
        if (temp_v1_2 == 8) {
            func_800584BC(0, D_8006C5BC - 8);
            return;
        }
        func_80053F50(-1);
        return;
    case 10:
        cheatMode5 = warpRead;
        var_a0 = 0;
        if (cheatMode5 >= 0x3CU) {
            var_a0 = 6;
            __asm__("" : "=r"(var_a0) : "0"(var_a0));
        }
        __asm__("" : "=r"(var_a0) : "0"(var_a0));
        func_800584BC(var_a0, cheatMode5);
        __asm__ volatile("" ::: "memory");
        warpWrite = 0;
        return;
default:
block_118:
        if (D_8006E344 == 4) {
            counter2 = &D_8006FBC4;
            __asm__("" : "=r"(counter2) : "0"(counter2));
            counterValue3 = *counter2;
            fade4 = D_8006C648;
            __asm__("" : "=r"(fade4) : "0"(fade4), "r"(counterValue3));
            *counter2 = counterValue3 + fade4;
        }
        return;
    }
}

#undef M2C_FIELD

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
