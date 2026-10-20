#include "common.h"
#include "camera.h"

#define LEVEL_ID 44

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80092E18. Assembly SHA256
 * f5ea3469331f0e64e441d3bea20dc28c890f590de1b232ee2724f1e5205d4643.
 * AI-generated; not human reviewed. Reuses verified camera33/43 C only where
 * this function's original instructions confirm the same chain. Original631
 * instructions,36 owned selectors and every target remain acceptance gates.
 * Modes4/13 retain their shared forward join and distinct initialized table
 * offsets. Mode13 offsets -0x8C/-0x78 are bytes from original D_8006E164;
 * mode17/39 offsets retain their original byte-domain bases. Mode31 preserves
 * the cached input-word route, override store/reload order and initialized
 * MULT/LO producers. Branch347/delay348 uses the original BNE/LI4096 pair;
 * paired .set metadata emits zero CPU instructions. C produces every CPU
 * instruction. Compiler/assembler pipeline, flags and gates are unchanged.
 * Original frame/scratch/padding and signed access widths are retained.
 * Physical units/fixed point, complete helper contracts and caller cadence
 * remain unresolved. Cadence per invocation; frame frequency unknown.
 * Falsification: every native/linked word and target, preserved data and full
 * executable/every-overlay retail hashes. No synchronized runtime parity or
 * subsystem completion claim. */
#define Camera44_92E18_Zero() ({register int z0 __asm__("$0");__asm__ volatile("":"=r"(z0):"i"(0));z0;})
#include "spyro.h"
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_33/camera/func_level_33_8009DE6C.s SHA256 5ccccf359bcf3e1f18fba891b40682c4967803cac8f578fccfb38bae49bd7731. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Camera44_92E18_Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern CameraPosition Camera44_92E18_D_80069260 __asm__("D_80069260");
extern CameraPosition Camera44_92E18_D_8006929C[5] __asm__("D_8006929C");
extern CameraPosition Camera44_92E18_D_80069328[5] __asm__("D_80069328");
extern CameraPosition Camera44_92E18_D_800693B4 __asm__("D_800693B4");
extern CameraPosition Camera44_92E18_D_800693C8 __asm__("D_800693C8");
extern int Camera44_92E18_D_8006C5BC __asm__("D_8006C5BC");
extern Spyro Camera44_92E18_D_80070328 __asm__("D_80070328");
void Camera44_92E18_func_800135A4(CameraPosition*, CameraPosition*, int) __asm__("func_800135A4");
int Camera44_92E18_func_800136F0(CameraPosition*, Vector3D*, Vector3D*) __asm__("func_800136F0");
void Camera44_92E18_func_80013918(int) __asm__("func_80013918");
void Camera44_92E18_func_800139A4() __asm__("func_800139A4");
void Camera44_92E18_func_800142E0() __asm__("func_800142E0");
void Camera44_92E18_func_80014354() __asm__("func_80014354");
int Camera44_92E18_func_8003615C(int arg0, int arg1) __asm__("func_8003615C");
extern void Camera44_92E18_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
unsigned char Camera44_92E18_func_800410F8() __asm__("func_800410F8");
/* extern */
extern CameraPosition Camera44_92E18_D_80069314 __asm__("D_80069314");
extern CameraPosition Camera44_92E18_D_800693A0 __asm__("D_800693A0");
extern short Camera44_92E18_D_8006E040 __asm__("D_8006E040");
extern int Camera44_92E18_D_8006E044 __asm__("D_8006E044");
extern int Camera44_92E18_D_8006E050 __asm__("D_8006E050");
extern int Camera44_92E18_D_8006E064 __asm__("D_8006E064");
extern int Camera44_92E18_D_8006E078 __asm__("D_8006E078");
extern int Camera44_92E18_D_8006E08C __asm__("D_8006E08C");
extern int Camera44_92E18_D_8006E094 __asm__("D_8006E094");
extern int Camera44_92E18_D_8006E098 __asm__("D_8006E098");
extern int Camera44_92E18_D_8006E09C __asm__("D_8006E09C");
extern CameraPosition Camera44_92E18_D_8006E0D8 __asm__("D_8006E0D8");
extern int Camera44_92E18_D_8006E0DC __asm__("D_8006E0DC");
extern int Camera44_92E18_D_8006E0E8 __asm__("D_8006E0E8");
extern int Camera44_92E18_D_8006E114 __asm__("D_8006E114");
extern int Camera44_92E18_D_8006E118 __asm__("D_8006E118");
extern int Camera44_92E18_D_8006E11C __asm__("D_8006E11C");
extern int Camera44_92E18_D_8006E120 __asm__("D_8006E120");
extern int Camera44_92E18_D_8006E124 __asm__("D_8006E124");
extern CameraPosition Camera44_92E18_D_8006E12C __asm__("D_8006E12C");
extern int Camera44_92E18_D_8006E130 __asm__("D_8006E130");
extern int Camera44_92E18_D_8006E140 __asm__("D_8006E140");
extern int Camera44_92E18_D_8006E144 __asm__("D_8006E144");
extern unsigned char Camera44_92E18_D_8006E154 __asm__("D_8006E154");
extern unsigned char Camera44_92E18_D_8006E160 __asm__("D_8006E160");
extern int Camera44_92E18_D_8006E1D0 __asm__("D_8006E1D0");
extern Vector3D Camera44_92E18_D_8006E1E0 __asm__("D_8006E1E0");
extern int Camera44_92E18_D_8006E1E8 __asm__("D_8006E1E8");
extern short Camera44_92E18_D_8006E1EC __asm__("D_8006E1EC");
extern short Camera44_92E18_D_8006E1EE __asm__("D_8006E1EE");
extern short Camera44_92E18_D_8006E1F0 __asm__("D_8006E1F0");
extern unsigned char Camera44_92E18_D_8006E536 __asm__("D_8006E536");
extern int Camera44_92E18_D_8006E538 __asm__("D_8006E538");
extern unsigned char Camera44_92E18_D_8006E546 __asm__("D_8006E546");
extern unsigned char Camera44_92E18_D_8006E547 __asm__("D_8006E547");
extern unsigned char Camera44_92E18_D_80071A04 __asm__("D_80071A04");
extern CameraPosition Camera44_92E18_D_8006E100 __asm__("D_8006E100");
extern int Camera44_92E18_D_8006E344 __asm__("D_8006E344");
extern int Camera44_92E18_D_8006E164 __asm__("D_8006E164");
extern CameraPosition Camera44_92E18_D_80069008 __asm__("D_80069008");
extern int Camera44_92E18_func_8004E880(int,int,int) __asm__("func_8004E880");
extern void Camera44_92E18_func_8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void func_level_44_80092E18(void) {
    struct {
        Vector3D sp10;
        int pad1C;
        int sp20;
        int sp24;
    }
    originalFrame;
    register unsigned char *base17 __asm__("$17");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int *address4 __asm__("$4");
    register int product7 __asm__("$7");
    int rawLow;
    CameraPosition *temp_a0_4;
    register CameraPosition *var_a0 __asm__("$4");
    CameraPosition *var_a0_2;
    register CameraPosition *joinTable __asm__("$5");
    register CameraPosition *case4Base __asm__("$16");
    register int case4Offset __asm__("$17");
    register int var_s0 __asm__("$16");
    Vector3D *var_s3;
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_5;
    int temp_a1;
    register int temp_v0 __asm__("$2");
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    register int temp_v1_5 __asm__("$3");
    int temp_v1_6;
    int temp_v1_7;
    register int var_a1 __asm__("$5");
    int var_s2;
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    register int var_v0_5 __asm__("$2");
    int var_v0_6;
    register int var_v0_7 __asm__("$2");
    register int var_v1 __asm__("$3");
    int var_v1_2;
    register int var_v1_3 __asm__("$3");
    void *temp_s0;
    var_s2 = (int) (Camera44_92E18_D_8006E130 + 2) >> 2;
    if (var_s2 >= 5) {
        var_s2 = 4;
    }
    switch (Camera44_92E18_D_8006E044) {
    case 4:
        if ((Camera44_92E18_D_8006E12C.pos.azimuth == 0) && (Camera44_92E18_D_8006E344 != 7)) {
            Camera44_92E18_func_800135A4((CameraPosition *) ((unsigned char*)&Camera44_92E18_D_8006E12C - 0xA4), &Camera44_92E18_D_80069008, Camera44_92E18_D_8006E064);
            temp_v0 = -Camera44_92E18_Field(&Camera44_92E18_D_80070328, int *, 0x60);
            var_v1 = (int) (temp_v0 - Camera44_92E18_D_8006E078) >> 2;
            Camera44_92E18_D_8006E08C = temp_v0;
            if (var_v1 >= 0xC1) {
                var_v1 = Camera44_92E18_Zero()+0xC0;
            }
            var_v0 = var_v1 < -0xC0;
            __asm__("":"=r"(var_v0):"0"(var_v0));
            if (var_v0 != 0) {
                var_v1 = -0xC0;
            }
            var_v0_2 = var_v1 + Camera44_92E18_Zero();
            if (var_v1 < 0) {
                var_v0_2 = -var_v0_2;
            }
            if (var_v0_2 >= 9) {
                Camera44_92E18_D_8006E094 = var_v1;
            }
            else {
                Camera44_92E18_D_8006E094 = 0;
            }
            Camera44_92E18_D_8006E098 = (int) -Camera44_92E18_Field(&Camera44_92E18_D_80070328, int *, 0x5C) >> 2;
            Camera44_92E18_func_80013918(0x180);
            Camera44_92E18_func_800139A4();
        }
        Camera44_92E18_func_800142E0();
        __asm__ volatile("":"=r"(var_s2):"0"(var_s2));
        case4Base=&Camera44_92E18_D_8006E0D8;
        __asm__("":"=r"(case4Base):"0"(case4Base));
        var_a0=case4Base;
        __asm__ volatile("":"=r"(var_a0):"0"(var_a0));
        word2=var_s2*5;
        __asm__ volatile("":"=r"(word2):"0"(word2));
        case4Offset=word2*4;
        __asm__("":"=r"(case4Offset):"0"(case4Offset));
        Camera44_92E18_func_800135A4(var_a0, (CameraPosition*)((unsigned char*)&Camera44_92E18_D_8006929C+case4Offset), 0);
        if (case4Base->pos.azimuth < 0x80) {
            case4Base->pos.azimuth = 0x80;
        }
        if (Camera44_92E18_D_8006E0DC < 0x60) {
            Camera44_92E18_D_8006E0DC = 0x60;
        }
        if (Camera44_92E18_D_8006E0E8 < 0x40) {
            Camera44_92E18_D_8006E0E8 = 0x40;
        }
        var_a0 = (CameraPosition*)((unsigned char*)case4Base+0x14);
        joinTable=(CameraPosition*)((unsigned char*)&Camera44_92E18_D_80069328+case4Offset);
        goto block_27;
    case 13:
        Camera44_92E18_func_800142E0();
        base17=(unsigned char*)&Camera44_92E18_D_8006E164;
        __asm__("":"=r"(base17):"0"(base17));
        if (Camera44_92E18_Field(base17,int*,0) != 0) {
            Camera44_92E18_func_8004F1C8(&originalFrame.sp10, (Vector3D*)(Camera44_92E18_Field(base17,int*,0) + 0xC), &Camera44_92E18_D_80070328.position);
            word2 = Camera44_92E18_func_8004E880(originalFrame.sp10.x, originalFrame.sp10.y, 1);
            word3 = Camera44_92E18_D_8006E12C.pos.azimuth;
            __asm__("" : "=r"(word3) : "0"(word3));
            Camera44_92E18_D_8006E064 = word2;
            var_a0 = (CameraPosition*)(base17 - 0x8C);
            if (word3 == 0) {
                Camera44_92E18_func_80014354(var_a0);
                Camera44_92E18_func_80013918(0x400);
                __asm__ __volatile__("" : "=r"(base17) : "0"(base17) : "$4");
                var_a0 = (CameraPosition*)(base17 - 0x8C);
            }
            var_s0 = var_s2 * 0x14;
            __asm__("":"=r"(var_s0):"0"(var_s0));
            Camera44_92E18_func_800135A4(var_a0, (CameraPosition*)((unsigned char*)&Camera44_92E18_D_8006929C+var_s0), 0);
            var_a0_2 = (CameraPosition*)(base17 - 0x78);
            var_a0=var_a0_2;
            joinTable=(CameraPosition*)((unsigned char*)&Camera44_92E18_D_80069328 + var_s0);
        block_27:
            Camera44_92E18_func_800135A4(var_a0, joinTable, 0);
            Camera44_92E18_func_800135A4(&Camera44_92E18_D_8006E100, &Camera44_92E18_D_800693C8, 0);
            Camera44_92E18_func_800135A4(&Camera44_92E18_D_8006E114, &Camera44_92E18_D_800693B4, 0);
            return;
        }
        return;
        default: return;
    case 17:
        base17=&Camera44_92E18_D_8006E160;
        if (Camera44_92E18_Field(base17, int *, 0) == Camera44_92E18_D_8006E044) {
            var_s3 = base17 - 0x108;
            if (Camera44_92E18_D_8006E12C.pos.azimuth == 0) {
                Camera44_92E18_func_800135A4(base17 - 0xD8, base17 + 8, Camera44_92E18_Field(&Camera44_92E18_D_8006E064, int *, 0));
                __asm__ volatile("":"=r"(base17):"0"(base17) : "$16","$19");
                var_s3 = base17 - 0x108;
            }
            Camera44_92E18_func_8004F178(var_s3, base17 + 0x1C);
            Camera44_92E18_Field(&Camera44_92E18_D_8006E064, int *, 0) = 0;
            Camera44_92E18_func_800135A4(base17 - 0x88, &Camera44_92E18_D_8006929C[var_s2], 0);
            Camera44_92E18_func_800135A4(base17 - 0x74, &Camera44_92E18_D_80069328[var_s2], 0);
            Camera44_92E18_func_800135A4(base17 - 0x4C, &Camera44_92E18_D_800693B4, 0);
            Camera44_92E18_func_800135A4(base17 - 0x60, &Camera44_92E18_D_800693C8, 0);
            if (!(Camera44_92E18_D_8006E050 & 2)) {
                Camera44_92E18_func_800136F0(base17 - 0xEC, base17 - 0x140, var_s3);
                Camera44_92E18_D_8006E09C = Camera44_92E18_Field(base17, int *, -0xEC);
                return;
            }
        }
        break;
    case 31:
        temp_s0 = Camera44_92E18_D_80070328.critterMobyPtr->mobyTag;
        originalFrame.sp20 = 0;
        originalFrame.sp24 = 0;
        if (Camera44_92E18_D_8006E536 != 0) {
            originalFrame.sp20 = Camera44_92E18_D_8006E546 - 0x7F;
            originalFrame.sp24 = 0x7F - Camera44_92E18_D_8006E547;
        }
        word3=Camera44_92E18_D_8006E538;
        __asm__("":"=r"(word3):"0"(word3));
        word2=word3&8192;
        __asm__("":"=r"(word2):"0"(word2));
        if(word2)goto positive_sp10;
        word2=word3&32768;
        __asm__("":"=r"(word2):"0"(word2));
        if(!word2)goto after_sp10;
        word2=-0x7F;
        goto store_sp10;
    positive_sp10:
        word2=0x7F;
    store_sp10:
        originalFrame.sp20=word2;
        __asm__ volatile("" : : : "memory");
        word3=Camera44_92E18_D_8006E538;
        __asm__("":"=r"(word3):"0"(word3));
        after_sp10:;
        word2=word3&4096;
        __asm__("":"=r"(word2):"0"(word2));
        if(word2)goto positive_sp14;
        word2=word3&16384;
        __asm__("":"=r"(word2):"0"(word2));
        if(!word2)goto after_sp14;
        word2=-0x7F;
        goto store_sp14;
    positive_sp14:
        word2=0x7F;
    store_sp14:
        originalFrame.sp24=word2;
        after_sp14:;
        temp_v1 = Camera44_92E18_Field(temp_s0, int *, 0x50) + originalFrame.sp20;
        Camera44_92E18_Field(temp_s0, int *, 0x50) = temp_v1;
        if (originalFrame.sp20 > 0) {
            if (temp_v1 < 0) {
                Camera44_92E18_Field(temp_s0, int *, 0x50) = 0;
            }
            if (originalFrame.sp20 >= 0x7F) {
                if (Camera44_92E18_Field(temp_s0, int *, 0x50) >= 0x1001) {
                    Camera44_92E18_Field(temp_s0, int *, 0x50) = 0x1000;
                }
            }
            else {
                temp_v1_2 = originalFrame.sp20 * 0x10;
                if (temp_v1_2 < Camera44_92E18_Field(temp_s0, int *, 0x50)) {
                    Camera44_92E18_Field(temp_s0, int *, 0x50) = temp_v1_2;
                }
            }
        }
        else {
            if (originalFrame.sp20 < -0x7E) {
                if (temp_v1 < -0x1000) {
                    Camera44_92E18_Field(temp_s0, int *, 0x50) = -0x1000;
                }
            }
            else {
                temp_a0 = originalFrame.sp20 * 0x10;
                if (temp_v1 < temp_a0) {
                    Camera44_92E18_Field(temp_s0, int *, 0x50) = temp_a0;
                }
            }
            if (Camera44_92E18_Field(temp_s0, int *, 0x50) > 0) {
                Camera44_92E18_Field(temp_s0, int *, 0x50) = 0;
            }
        }
        temp_v1_3 = Camera44_92E18_Field(temp_s0, int *, 0x54) + originalFrame.sp24;
        Camera44_92E18_Field(temp_s0, int *, 0x54) = temp_v1_3;
        if (originalFrame.sp24 > 0) {
            if (temp_v1_3 < 0) {
                Camera44_92E18_Field(temp_s0, int *, 0x54) = 0;
            }
            if (originalFrame.sp24 >= 0x7F) {
                /* Original branch347/delay348 is BNE/LI4096.
                * Mode directives emit zero CPU instructions; C emits the
                * predicate, constant and store. Original targets/hashes required. */
                word2=Camera44_92E18_Field(temp_s0,int*,0x54)<0x1001;
                __asm__ volatile(".set\tnoreorder" : : "r"(word2));
                if(!word2) {
                    word2=0x1000;
                    __asm__ volatile(".set\treorder" : "=r"(word2) : "0"(word2));
                    Camera44_92E18_Field(temp_s0,int*,0x54)=word2;
                }
            }
            else {
                temp_v1_4 = originalFrame.sp24 * 0x10;
                if (temp_v1_4 < Camera44_92E18_Field(temp_s0, int *, 0x54)) {
                    Camera44_92E18_Field(temp_s0, int *, 0x54) = temp_v1_4;
                }
            }
        }
        else {
            if (originalFrame.sp24 < -0x7E) {
                if (temp_v1_3 < -0x1000) {
                    Camera44_92E18_Field(temp_s0, int *, 0x54) = -0x1000;
                }
            }
            else {
                temp_a0_2 = originalFrame.sp24 * 0x10;
                if (temp_v1_3 < temp_a0_2) {
                    Camera44_92E18_Field(temp_s0, int *, 0x54) = temp_a0_2;
                }
            }
            if (Camera44_92E18_Field(temp_s0, int *, 0x54) > 0) {
                Camera44_92E18_Field(temp_s0, int *, 0x54) = 0;
            }
        }
        word3=Camera44_92E18_Field(temp_s0,int*,0x58);
        __asm__("":"=r"(word3):"0"(word3));
        word2=0x555;
        word2-=word3;
        word2>>=8;
        __asm__("":"=r"(word2):"0"(word2));
        var_a1=word2+1;
        var_v0_5 = var_a1 < 6;
        if (var_a1 <= 0) {
            var_a1=Camera44_92E18_Zero()+1;
            var_v0_5=var_a1<6;
        }
        if (var_v0_5 == 0) {
            var_a1 = 5;
        }
        if (((unsigned int) (Camera44_92E18_D_80070328.animationState - 0x7A) < 2U) || (Camera44_92E18_D_80070328.animationState == 0x7C)) {
            word2=Camera44_92E18_Field(temp_s0,int*,0x50);
            __asm__ volatile("":"=l"(rawLow):"l"(var_a1*word2):"memory");
            address4=&Camera44_92E18_D_8006E140;
            __asm__("":"=r"(address4):"0"(address4));
            word2=*address4;
            product7=rawLow;
            __asm__("":"=r"(product7):"0"(product7),"r"(word2));
            word3=product7>>9;
            word2-=word3;
            *address4=word2;
            word2=Camera44_92E18_Field(temp_s0,int*,0x54);
            __asm__ volatile("":"=l"(rawLow):"l"(var_a1*word2):"memory");
            word2=Camera44_92E18_D_8006E144;
            product7=rawLow;
            __asm__("":"=r"(product7):"0"(product7),"r"(word2));
            word3=product7>>9;
            word2+=word3;
            Camera44_92E18_D_8006E144=word2;
        }
        else {
            word2=Camera44_92E18_Field(temp_s0,int*,0x50);
            __asm__ volatile("":"=l"(rawLow):"l"(var_a1*word2):"memory");
            address4=&Camera44_92E18_D_8006E140;
            __asm__("":"=r"(address4):"0"(address4));
            word2=*address4;
            product7=rawLow;
            __asm__("":"=r"(product7):"0"(product7),"r"(word2));
            word3=product7>>8;
            word2-=word3;
            *address4=word2;
            word2=Camera44_92E18_Field(temp_s0,int*,0x54);
            __asm__ volatile("":"=l"(rawLow):"l"(var_a1*word2):"memory");
            word2=Camera44_92E18_D_8006E144;
            product7=rawLow;
            __asm__("":"=r"(product7):"0"(product7),"r"(word2));
            word3=product7>>8;
            word2+=word3;
            Camera44_92E18_D_8006E144=word2;
        }
        address4=&Camera44_92E18_D_8006E144;
        __asm__("":"=r"(address4):"0"(address4));
        word2=*address4;
        __asm__("":"=r"(word2):"0"(word2));
        temp_v1_5=word2&0xFFF;
        *address4=temp_v1_5;
        if(temp_v1_5>=0x801){
            word2=temp_v1_5-0x1000;
            __asm__("":"=r"(word2):"0"(word2));
            *address4=word2;
        }
        if (*address4 < -0x200) {
            *address4 = -0x200;
        }
        if (*address4 >= 0x201) {
            *address4 = 0x200;
        }
        temp_v1_6 = Camera44_92E18_D_8006E140 & 0xFFF;
        Camera44_92E18_D_8006E140 = temp_v1_6;
        if (temp_v1_6 >= 0x801) {
            Camera44_92E18_D_8006E140 = temp_v1_6 - 0x1000;
        }
        if ((Camera44_92E18_D_8006C5BC != 0x2C) || (Camera44_92E18_D_80071A04 == 0)) {
            var_v0_6 = Camera44_92E18_D_8006E140;
            Camera44_92E18_D_80070328.rotation.yaw = var_v0_6;
        }
        else {
            var_v1_3 = Camera44_92E18_func_8003615C(Camera44_92E18_D_80070328.rotation.yaw, (int) Camera44_92E18_D_8006E040) >> 2;
            if (var_v1_3 == 0) {
                var_v0_6 = Camera44_92E18_D_80070328.rotation.yaw;
            }
            else {
                if (var_v1_3 >= 0x81) {
                    var_v1_3=Camera44_92E18_Zero()+0x80;
                }
                var_v0_7=var_v1_3<-0x80;
                __asm__("":"=r"(var_v0_7):"0"(var_v0_7));
                if (var_v0_7 != 0) {
                    var_v1_3 = -0x80;
                }
                var_v0_6 = (unsigned short) Camera44_92E18_D_8006E040 - var_v1_3;
            }
        }
        Camera44_92E18_D_8006E1F0 = var_v0_6;
        __asm__ volatile("":::"$4","$5","memory");
        Camera44_92E18_func_8004F178(&Camera44_92E18_D_8006E1E0, &Camera44_92E18_D_80070328.position);
        Camera44_92E18_D_8006E1EC = 0;
        Camera44_92E18_D_8006E1E8 += 0xE0;
        Camera44_92E18_D_8006E1EE = Camera44_92E18_D_8006E144;
        temp_a0_3 = Camera44_92E18_Field(temp_s0, int *, 0x58);
        temp_a1 = ((int) (temp_a0_3 - 0x155) >> 4) + 0x10;
        if (Camera44_92E18_D_8006E538 & 9) {
            temp_v0_2 = temp_a0_3 + temp_a1;
            Camera44_92E18_Field(temp_s0, int *, 0x58) = temp_v0_2;
            if (temp_v0_2 >= 0x801) {
                Camera44_92E18_Field(temp_s0, int *, 0x58) = 0x800;
            }
        }
        if (Camera44_92E18_D_8006E538 & 6) {
            temp_v0_3 = Camera44_92E18_Field(temp_s0, int *, 0x58) - temp_a1;
            Camera44_92E18_Field(temp_s0, int *, 0x58) = temp_v0_3;
            if (temp_v0_3 < 0x155) {
                Camera44_92E18_Field(temp_s0, int *, 0x58) = 0x155;
            }
        }
        Camera44_92E18_D_8006E1D0 = Camera44_92E18_Field(temp_s0, int *, 0x58) - 0x155;
        return;
    case 39:
        base17=(unsigned char*)&Camera44_92E18_D_8006E12C;
        __asm__("":"=r"(base17):"0"(base17));
        temp_a0_4 = (CameraPosition*)(base17 - 0x54);
        if (Camera44_92E18_Field(base17,int*,0) == 0) {
            Camera44_92E18_func_80014354(temp_a0_4);
            __asm__ volatile("":"=r"(base17):"0"(base17):"$4");
            Camera44_92E18_func_800135A4((CameraPosition*)(base17 - 0x54), &Camera44_92E18_D_80069314, 0);
            Camera44_92E18_func_800135A4((CameraPosition*)(base17 - 0x40), &Camera44_92E18_D_800693A0, 0);
            Camera44_92E18_func_800135A4((CameraPosition*)(base17 - 0x2C), &Camera44_92E18_D_800693C8, 0);
            Camera44_92E18_D_8006E114 = -1;
            Camera44_92E18_D_8006E118 = -1;
            Camera44_92E18_D_8006E11C = -1;
            Camera44_92E18_D_8006E120 = -1;
            Camera44_92E18_D_8006E124 = -1;
        }
        else {
            Camera44_92E18_func_800135A4(temp_a0_4, &Camera44_92E18_D_8006929C[var_s2], 0);
            Camera44_92E18_func_800135A4((CameraPosition*)(base17 - 0x40), &Camera44_92E18_D_80069328[var_s2], 0);
            Camera44_92E18_func_800135A4((CameraPosition*)(base17 - 0x18), &Camera44_92E18_D_800693B4, 0);
            Camera44_92E18_func_800135A4((CameraPosition*)(base17 - 0x2C), &Camera44_92E18_D_800693C8, 0);
        }
        Camera44_92E18_func_800142E0();
        return;
    }
}
#undef Camera44_92E18_Field


/**
 * ???() - func_level_44_800937F4() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_44_800937F4() {
	switch (camera.cameraState) {
        
#ifdef IS_ZOOM_OUT_CAMERA_LEVEL
	case CAMERA_ZOOM_OUT:
		if (camera.cameraState != camera.unk168) {
			func_80013900(&camera.unk7c.pos[3]);
			func_80012530();
			return;
		}
        func_8001241C();
		func_80012530();
		return;
#endif
        
#ifdef IS_AGENT_9_LEVEL  
	case CAMERA_AGENT_9_POV:
		func_800135A4(&camera.unk7c.pos[2], &camera.unk7c.pos[1], 0);
		return;
#endif
        
	default:
		func_8001241C();
		func_80012530();
		return;
	}

}

extern unsigned char** DecodedMode31Tag __asm__("D_80070328 + 0x250");
extern int DecodedMode31Value __asm__("D_80070328 + 0x64");
extern int DecodedMode31CameraState __asm__("D_8006E140");
extern int DecodedMode31Camera144 __asm__("D_8006E144");
extern int DecodedMode31Camera158 __asm__("D_8006E158");
extern int DecodedMode31Camera15C __asm__("D_8006E15C");
extern int DecodedMode31Flag __asm__("D_8006C768");
extern int DecodedMode31Camera12C __asm__("D_8006E12C");
extern int DecodedMode31Camera130 __asm__("D_8006E130");
extern Moby* D_8006E164;
extern int D_8006E048, D_8006E064;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern CameraPosition D_8006E074, D_8006E09C;
extern CameraPosition DecodedSettleInput __asm__("D_8006E074");
extern CameraPosition DecodedSettleFinal __asm__("D_8006E074");
extern Vector3D D_8006E020, D_8006E058, D_8006E17C;
void func_8004F178(Vector3D*, Vector3D*);
/* SCUS-94467 USA Rev0 8009387C..80093AB4, 143 code words.
 * Reuses verified func_level_50_800A0320. Modes4/39 reset, mode13 settle, mode17 vector copy and raw mode31 tag path.
 * Original dispatch entries, access widths and helper order are retained.
 * Units, table/flag/tag producers and caller cadence remain open.
 * Empty constraints preserve compiler lifetime/control flow without instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1690.
 */
void func_level_44_8009387C(int mode) {
    register int* base __asm__("$16");
    register unsigned char* actor __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register Vector3D* target __asm__("$18");
    switch (mode) {
    case 4:
    case 39:
        base = &D_8006E048;
        *base = 0;
        D_8006E138 = 0;
        D_8006E139 = 0;
        D_8006E13A = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        position = (CameraPosition*)((char*)base + 44);
        __asm__("" : "=r"(position) : "0"(position));
        func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
        goto settle;
    case 13:
        base = &D_8006E048;
        *base = 0;
        D_8006E138 = 0;
        D_8006E139 = 1;
        D_8006E13A = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        position = (CameraPosition*)((char*)base + 44);
        __asm__("" : "=r"(position) : "0"(position));
        func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
        func_800138A0(position, position);
        func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
        break;
    case 17:
        copyBase = &D_8006E048;
        target = (Vector3D*)((char*)copyBase + 16);
        *copyBase = 0;
        D_8006E138 = 0;
        D_8006E139 = 1;
        D_8006E13A = 1;
        D_8006E13D = 0;
        func_8004F178(target, (Vector3D*)((char*)copyBase + 308));
        copiedPosition = (CameraPosition*)((char*)copyBase + 44);
        __asm__("" : "=r"(copiedPosition) : "0"(copiedPosition));
        D_8006E064 = 0;
        func_800136F0(copiedPosition, (Vector3D*)((char*)copyBase - 40), target);
settle:
        func_800138A0(&D_8006E074, &DecodedSettleInput);
        func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
        break;
    case 31: {
        register int* state __asm__("$3");
        register int value __asm__("$2");
        register unsigned char** pointer __asm__("$2") = DecodedMode31Tag;
        __asm__("" : "=r"(pointer) : "0"(pointer));
        state = &DecodedMode31CameraState;
        __asm__("" : "=r"(state) : "0"(state),"r"(pointer));
        actor = *pointer;
        value = DecodedMode31Value;
        __asm__("" : "=r"(value) : "0"(value));
        *state = value;
        DecodedMode31Camera144 = 0;
        DecodedMode31Camera158 = 0;
        DecodedMode31Camera15C = 0;
        func_80013900((CameraPosition*)((char*)state - 0x7C));
        D_8006E13D = 1;
        D_8006E138 = 1;
        D_8006E139 = 1;
        DecodedMode31Flag = 1;
        DecodedMode31Camera12C = 0;
        DecodedMode31Camera130 = 0;
        D_8006E054 = 0;
        *(int*)(actor + 0x50) = 0;
        *(int*)(actor + 0x54) = 0;
        *(int*)(actor + 0x58) = 0x200;
        break;
    }    }
}

extern CameraPosition D_80068FE0;
extern int Camera44Mode __asm__("D_8006E044");
extern int Camera44Override __asm__("D_8006E160");
extern int Camera44Held __asm__("D_8006E538");
extern int Camera44Pressed __asm__("D_8006E53C");
extern unsigned char Camera44Player[] __asm__("D_80070328");
extern int Camera44ModeTable[] __asm__("D_80068CAC");
/* AI generated; not human reviewed. SCUS-94467 80093AB8..80093E58.
 * Baseline: verified level43_80096108 selector/copy structure; original level44
 * supplies its selector13, state31 and input/global access chains.
 * Empty flag constraints preserve the original late A0 branch-delay values.
 * Helper contracts, table producers, physical units and cadence remain open.
 * Acceptance requires every original code/table word and complete retail hashes.
 */
void func_level_44_80093AB8(void) {
    register int mode __asm__("$2") = Camera44Mode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    register int flag __asm__("$2");
    switch (mode) {
    case 4:
        next = Camera44Override;
        if (next) goto applySelector;
        if (Camera44Held & 16) {
            flag = Camera44Player[0x1B9];
            __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
            next = 7;
            if (flag) goto applySelector;
        }
        flag = Camera44Pressed & 12;
        __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
        next = 8;
        if (!flag) goto freshTable;
        goto applySelector;
    case 13:
        if (Camera44Held & 16) {
            flag = Camera44Player[0x1B9];
            __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
            next = 7;
            if (flag) goto applySelector;
        }
        flag = Camera44Pressed & 12;
        __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
        next = 8;
        if (flag) goto applySelector;
        next = Camera44Override;
        if (!next) {
readTable:
            next = Camera44ModeTable[*(int*)(Camera44Player + 0x48)];
            goto applySelector;
        }
        if (next == Camera44Mode) return;
        goto applySelector;

    case 17:
        next = Camera44Override;
        if (!next) goto readTable;
        if (next == 17) return;
        goto applySelector;
    case 31:
        next = Camera44Override;
        if (next && next != 40) func_80016764(next);
        if (Camera44Player[0x1B9] == 0) {
            register int* overrideState __asm__("$17") = &Camera44Override;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) {
force40:
                next = 40;
                goto applySelector;
            }
            func_800135A4(initial, &D_80068FE0, camera.unk6c);
            func_800135A4((CameraPosition*)((char*)overrideState - 0xC4), initial, 0);
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            func_80012AC8();
            func_80012B34();
            func_80016764(Camera44ModeTable[*(int*)(Camera44Player + 0x48)]);
            ((unsigned char*)*(unsigned int*)(Camera44Player + 0x250))[0x4C] = 16;
            return;
        }
        if (Camera44Pressed & 16) {
            register int* overrideState __asm__("$17") = &Camera44Override;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) goto force40;
            func_800135A4(initial, &D_80068FE0, camera.unk6c);
            func_800135A4((CameraPosition*)((char*)overrideState - 0xC4), initial, 0);
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            func_80012AC8();
            func_80012B34();
            func_80016764(0);
            camera.unk50 = 2;
            ((unsigned char*)*(unsigned int*)(Camera44Player + 0x250))[0x4C] = 16;
        }
        return;
    case 39:
        next = Camera44Override;
        if (next) goto applySelector;
        if ((Camera44Pressed & 16) && Camera44Player[0x1B9] &&
                *(int*)(Camera44Player + 0x24C) == 4) {
            next = 31;
            goto applySelector;
        }
freshTable:
        index = *(int*)(Camera44Player + 0x48);
        { register int current __asm__("$3") = Camera44Mode;
        next = Camera44ModeTable[index];
        if (current == next) return;
        if (next) goto applySelector;
        next = 6;
        goto applySelector;
        }
    default:
        return;
    }
applySelector:
    func_80016764(next);
}
