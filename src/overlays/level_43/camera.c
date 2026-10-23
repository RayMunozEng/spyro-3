#include "matching.h"
#include "common.h"
#include "camera.h"

#define LEVEL_ID 43

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
/* SCUS-94467 USA Rev0; originalfunc_level_43_80095668.
* Assembly SHA256 7bdbc99c68df10168e42e7b5dec8f265d42c73d9fdda4d4735c5fded7dc49ed3.
* AI-generated; not human reviewed. Original numeric and address roles only:
* raw32 input masks, signed integer sums/shifts, literal clamps and byte-domain
* table addressing are preserved. Physical units/fixed point, complete helper
* meanings and per-frame caller cadence remain unresolved.
* Original branch94 skips the input-word reload after the first
* override store. The no-override route retains the already loaded word; the
* override route stores first and then reloads, with a zero-instruction memory
* boundary preserving that observed order. Both paths retain original targets.
* Original branch175 uses LI4096 in its delay slot. Paired .set modes
* are zero-CPU assembler metadata; C generates the predicate, constant/store.
* The same original frame, scratch fields, signed table loads, low-product
* producers, wrap/clamp arithmetic and per-level joins remain unchanged.
* No incoming HI/LO state is invented. Empty constraints consume initialized
* original values or mark dead replacements. Do not remove producer captures,
* pad fields or unused original frame storage as cosmetic cleanup.
* Falsification: every native/linked instruction and owned table word, all
* conditional/internal targets, preserved data and EXE/every-overlay hashes.
* Compiler/assembler pipeline, flags and acceptance requirements are unchanged.
* Binary identity does not establish synchronized runtime/system completion. */
#define Camera43_95668_Zero()                     \
    ({                                            \
        register int z0 __asm__("$0");            \
        __asm__ volatile("" : "=r"(z0) : "i"(0)); \
        z0;                                       \
    })
#include "spyro.h"
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_43/camera/func_level_43_80095668.s SHA256 7bdbc99c68df10168e42e7b5dec8f265d42c73d9fdda4d4735c5fded7dc49ed3. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Camera43_95668_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern CameraPosition Camera43_95668_D_8006929C[5] __asm__("D_8006929C");
extern CameraPosition Camera43_95668_D_80069328[5] __asm__("D_80069328");
extern CameraPosition Camera43_95668_D_800693B4 __asm__("D_800693B4");
extern CameraPosition Camera43_95668_D_800693C8 __asm__("D_800693C8");
extern int Camera43_95668_D_8006C5BC __asm__("D_8006C5BC");
extern Spyro Camera43_95668_D_80070328 __asm__("D_80070328");
void Camera43_95668CopyCameraPositionWithWrappedAngle(CameraPosition*, CameraPosition*,
                                                      int) __asm__("func_800135A4");
void Camera43_95668SelectSignedCameraOrbitRequest(int) __asm__("func_80013918");
void Camera43_95668RefreshCameraPlayerAnchor() __asm__("func_800142E0");
void Camera43_95668SelectCameraFollowProfile() __asm__("func_80014354");
int Camera43_95668SubAngle12(int arg0, int arg1) __asm__("func_8003615C");
extern int Camera43_95668PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Camera43_95668CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Camera43_95668SubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
extern CameraPosition Camera43_95668_D_80069184 __asm__("D_80069184");
extern CameraPosition Camera43_95668_D_80069314 __asm__("D_80069314");
extern CameraPosition Camera43_95668_D_800693A0 __asm__("D_800693A0");
extern short Camera43_95668_D_8006E040 __asm__("D_8006E040");
extern int Camera43_95668_D_8006E044 __asm__("D_8006E044");
extern int Camera43_95668_D_8006E050 __asm__("D_8006E050");
extern int Camera43_95668_D_8006E064 __asm__("D_8006E064");
extern int Camera43_95668_D_8006E09C __asm__("D_8006E09C");
extern CameraPosition Camera43_95668_D_8006E0D8 __asm__("D_8006E0D8");
extern int Camera43_95668_D_8006E114 __asm__("D_8006E114");
extern int Camera43_95668_D_8006E118 __asm__("D_8006E118");
extern int Camera43_95668_D_8006E11C __asm__("D_8006E11C");
extern int Camera43_95668_D_8006E120 __asm__("D_8006E120");
extern int Camera43_95668_D_8006E124 __asm__("D_8006E124");
extern int Camera43_95668_D_8006E12C __asm__("D_8006E12C");
extern int Camera43_95668_D_8006E130 __asm__("D_8006E130");
extern signed char Camera43_95668_D_8006E13A __asm__("D_8006E13A");
extern int Camera43_95668_D_8006E140 __asm__("D_8006E140");
extern int Camera43_95668_D_8006E144 __asm__("D_8006E144");
extern int Camera43_95668_D_8006E148 __asm__("D_8006E148");
extern int Camera43_95668_D_8006E164 __asm__("D_8006E164");
extern int Camera43_95668_D_8006E1D0 __asm__("D_8006E1D0");
extern Vector3D Camera43_95668_D_8006E1E0 __asm__("D_8006E1E0");
extern int Camera43_95668_D_8006E1E8 __asm__("D_8006E1E8");
extern short Camera43_95668_D_8006E1EC __asm__("D_8006E1EC");
extern short Camera43_95668_D_8006E1EE __asm__("D_8006E1EE");
extern short Camera43_95668_D_8006E1F0 __asm__("D_8006E1F0");
extern unsigned char Camera43_95668_D_8006E536 __asm__("D_8006E536");
extern int Camera43_95668_D_8006E538 __asm__("D_8006E538");
extern unsigned char Camera43_95668_D_8006E546 __asm__("D_8006E546");
extern unsigned char Camera43_95668_D_8006E547 __asm__("D_8006E547");
extern unsigned char Camera43_95668_D_80071A04 __asm__("D_80071A04");
void Camera43_95668UpdateCameraOrbitReturn() __asm__("func_800139A4");
extern CameraPosition Camera43_95668_D_80069238 __asm__("D_80069238");
extern int Camera43_95668_D_8006E0E0 __asm__("D_8006E0E0");
extern int Camera43_95668_D_8006E168 __asm__("D_8006E168");
void func_level_43_80095668(void) {
    struct {
        Vector3D sp10;
        unsigned char pad1C[4];
        int sp20;
        int sp24;
    } originalFrame;
    register unsigned char* base18 __asm__("$18");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int* address4 __asm__("$4");
    register int product7 __asm__("$7");
    int rawLow;
    int* var_a0;
    register int* temp_a0_4 __asm__("$4");
    Vector3D* var_s3;
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
    register int var_s1 __asm__("$17");
    register int var_s0 __asm__("$16");
    int* var_a0_2;
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
    void* temp_s0;
    base18 = (unsigned char*)&Camera43_95668_D_8006E130;
    MATCHING_KEEP(base18);
    word2 = Camera43_95668_Field(base18, int*, 0);
    word2 += 2;
    var_s1 = word2 >> 2;
    if (var_s1 >= 5) {
        var_s1 = 4;
    }
    switch (Camera43_95668_D_8006E044) {
            /* irregular */
        case 13:
            Camera43_95668RefreshCameraPlayerAnchor();
            if (Camera43_95668_D_8006E164 != 0) {
                Camera43_95668SubtractVector(&originalFrame.sp10, Camera43_95668_D_8006E164 + 0xC,
                                             &Camera43_95668_D_80070328.position);
                word2 = Camera43_95668PlanarHeadingLookup(originalFrame.sp10.x,
                                                          originalFrame.sp10.y, 1);
                word3 = Camera43_95668_D_8006E12C;
                MATCHING_KEEP(word3);
                Camera43_95668_D_8006E064 = word2;
                var_a0 = (int*)(base18 - 0x58);
                if (word3 == 0) {
                    Camera43_95668SelectCameraFollowProfile(var_a0);
                    Camera43_95668SelectSignedCameraOrbitRequest(0x400);
                    MATCHING_KEEP_GNU_VOLATILE_CLOBBER(base18, "$4");
                    var_a0 = (int*)(base18 - 0x58);
                }
                var_s0 = var_s1 * 0x14;
                Camera43_95668CopyCameraPositionWithWrappedAngle(
                    var_a0, &Camera43_95668_D_8006929C[var_s1], 0);
                var_a0_2 = (int*)(base18 - 0x44);
                goto block_88;
            }
            return;
        case 31:
            temp_s0 = Camera43_95668_D_80070328.critterMobyPtr->mobyTag;
            originalFrame.sp20 = 0;
            originalFrame.sp24 = 0;
            if (Camera43_95668_D_8006E536 != 0) {
                originalFrame.sp20 = Camera43_95668_D_8006E546 - 0x7F;
                originalFrame.sp24 = 0x7F - Camera43_95668_D_8006E547;
            }
            word3 = Camera43_95668_D_8006E538;
            MATCHING_KEEP(word3);
            word2 = word3 & 8192;
            MATCHING_KEEP(word2);
            if (word2)
                goto positive_sp10;
            word2 = word3 & 32768;
            MATCHING_KEEP(word2);
            if (!word2)
                goto after_sp10;
            word2 = -0x7F;
            goto store_sp10;
        positive_sp10:
            word2 = 0x7F;
        store_sp10:
            originalFrame.sp20 = word2;
            MATCHING_BARRIER_VOLATILE("memory");
            word3 = Camera43_95668_D_8006E538;
            MATCHING_KEEP(word3);
        after_sp10:;
            word2 = word3 & 4096;
            MATCHING_KEEP(word2);
            if (word2)
                goto positive_sp14;
            word2 = word3 & 16384;
            MATCHING_KEEP(word2);
            if (!word2)
                goto after_sp14;
            word2 = -0x7F;
            goto store_sp14;
        positive_sp14:
            word2 = 0x7F;
        store_sp14:
            originalFrame.sp24 = word2;
        after_sp14:;
            temp_v1 = Camera43_95668_Field(temp_s0, int*, 0x50) + originalFrame.sp20;
            Camera43_95668_Field(temp_s0, int*, 0x50) = temp_v1;
            if (originalFrame.sp20 > 0) {
                if (temp_v1 < 0) {
                    Camera43_95668_Field(temp_s0, int*, 0x50) = 0;
                }
                if (originalFrame.sp20 >= 0x7F) {
                    if (Camera43_95668_Field(temp_s0, int*, 0x50) >= 0x1001) {
                        Camera43_95668_Field(temp_s0, int*, 0x50) = 0x1000;
                    }
                } else {
                    temp_v1_2 = originalFrame.sp20 * 0x10;
                    if (temp_v1_2 < Camera43_95668_Field(temp_s0, int*, 0x50)) {
                        Camera43_95668_Field(temp_s0, int*, 0x50) = temp_v1_2;
                    }
                }
            } else {
                if (originalFrame.sp20 < -0x7E) {
                    if (temp_v1 < -0x1000) {
                        Camera43_95668_Field(temp_s0, int*, 0x50) = -0x1000;
                    }
                } else {
                    temp_a0 = originalFrame.sp20 * 0x10;
                    if (temp_v1 < temp_a0) {
                        Camera43_95668_Field(temp_s0, int*, 0x50) = temp_a0;
                    }
                }
                if (Camera43_95668_Field(temp_s0, int*, 0x50) > 0) {
                    Camera43_95668_Field(temp_s0, int*, 0x50) = 0;
                }
            }
            temp_v1_3 = Camera43_95668_Field(temp_s0, int*, 0x54) + originalFrame.sp24;
            Camera43_95668_Field(temp_s0, int*, 0x54) = temp_v1_3;
            if (originalFrame.sp24 > 0) {
                if (temp_v1_3 < 0) {
                    Camera43_95668_Field(temp_s0, int*, 0x54) = 0;
                }
                if (originalFrame.sp24 >= 0x7F) {
                    /* Original branch175/delay176 is BNE/LI4096.
                * Mode directives emit zero CPU instructions; C emits the
                * predicate, constant and store. Original targets/hashes required. */
                    word2 = Camera43_95668_Field(temp_s0, int*, 0x54) < 0x1001;
                    __asm__ volatile(".set\tnoreorder" : : "r"(word2));
                    if (!word2) {
                        word2 = 0x1000;
                        __asm__ volatile(".set\treorder" : "=r"(word2) : "0"(word2));
                        Camera43_95668_Field(temp_s0, int*, 0x54) = word2;
                    }
                } else {
                    temp_v1_4 = originalFrame.sp24 * 0x10;
                    if (temp_v1_4 < Camera43_95668_Field(temp_s0, int*, 0x54)) {
                        Camera43_95668_Field(temp_s0, int*, 0x54) = temp_v1_4;
                    }
                }
            } else {
                if (originalFrame.sp24 < -0x7E) {
                    if (temp_v1_3 < -0x1000) {
                        Camera43_95668_Field(temp_s0, int*, 0x54) = -0x1000;
                    }
                } else {
                    temp_a0_2 = originalFrame.sp24 * 0x10;
                    if (temp_v1_3 < temp_a0_2) {
                        Camera43_95668_Field(temp_s0, int*, 0x54) = temp_a0_2;
                    }
                }
                if (Camera43_95668_Field(temp_s0, int*, 0x54) > 0) {
                    Camera43_95668_Field(temp_s0, int*, 0x54) = 0;
                }
            }
            word3 = Camera43_95668_Field(temp_s0, int*, 0x58);
            MATCHING_KEEP(word3);
            word2 = 0x555;
            word2 -= word3;
            word2 >>= 8;
            MATCHING_KEEP(word2);
            var_a1 = word2 + 1;
            var_v0_5 = var_a1 < 6;
            if (var_a1 <= 0) {
                var_a1 = Camera43_95668_Zero() + 1;
                var_v0_5 = var_a1 < 6;
            }
            if (var_v0_5 == 0) {
                var_a1 = 5;
            }
            if (((unsigned int)(Camera43_95668_D_80070328.animationState - 0x7A) < 2U) ||
                (Camera43_95668_D_80070328.animationState == 0x7C)) {
                word2 = Camera43_95668_Field(temp_s0, int*, 0x50);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                address4 = &Camera43_95668_D_8006E140;
                MATCHING_KEEP(address4);
                word2 = *address4;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 9;
                word2 -= word3;
                *address4 = word2;
                word2 = Camera43_95668_Field(temp_s0, int*, 0x54);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                word2 = Camera43_95668_D_8006E144;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 9;
            } else {
                word2 = Camera43_95668_Field(temp_s0, int*, 0x50);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                address4 = &Camera43_95668_D_8006E140;
                MATCHING_KEEP(address4);
                word2 = *address4;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 8;
                word2 -= word3;
                *address4 = word2;
                word2 = Camera43_95668_Field(temp_s0, int*, 0x54);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                word2 = Camera43_95668_D_8006E144;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 8;
            }
            word2 += word3;
            Camera43_95668_D_8006E144 = word2;
            __asm__ volatile("" ::: "memory", "$4");
            address4 = &Camera43_95668_D_8006E144;
            MATCHING_KEEP(address4);
            word2 = *address4;
            MATCHING_KEEP(word2);
            temp_v1_5 = word2 & 0xFFF;
            *address4 = temp_v1_5;
            if (temp_v1_5 >= 0x801) {
                word2 = temp_v1_5 - 0x1000;
                MATCHING_KEEP(word2);
                *address4 = word2;
            }
            if (*address4 < -0x200) {
                *address4 = -0x200;
            }
            if (*address4 >= 0x201) {
                *address4 = 0x200;
            }
            temp_v1_6 = Camera43_95668_D_8006E140 & 0xFFF;
            Camera43_95668_D_8006E140 = temp_v1_6;
            if (temp_v1_6 >= 0x801) {
                Camera43_95668_D_8006E140 = temp_v1_6 - 0x1000;
            }
            if ((Camera43_95668_D_8006C5BC != 0x2C) || (Camera43_95668_D_80071A04 == 0)) {
                var_v0_6 = Camera43_95668_D_8006E140;
                Camera43_95668_D_80070328.rotation.yaw = var_v0_6;
            } else {
                var_v1_3 = Camera43_95668SubAngle12(Camera43_95668_D_80070328.rotation.yaw,
                                                    (int)Camera43_95668_D_8006E040) >>
                           2;
                if (var_v1_3 == 0) {
                    var_v0_6 = Camera43_95668_D_80070328.rotation.yaw;
                } else {
                    if (var_v1_3 >= 0x81) {
                        var_v1_3 = Camera43_95668_Zero() + 0x80;
                    }
                    var_v0_7 = var_v1_3 < -0x80;
                    MATCHING_KEEP(var_v0_7);
                    if (var_v0_7 != 0) {
                        var_v1_3 = -0x80;
                    }
                    var_v0_6 = (unsigned short)Camera43_95668_D_8006E040 - var_v1_3;
                }
            }
            Camera43_95668_D_8006E1F0 = var_v0_6;
            __asm__ volatile("" ::: "$4", "$5", "memory");
            Camera43_95668CopyVector(&Camera43_95668_D_8006E1E0,
                                     &Camera43_95668_D_80070328.position);
            Camera43_95668_D_8006E1EC = 0;
            Camera43_95668_D_8006E1E8 += 0xE0;
            Camera43_95668_D_8006E1EE = Camera43_95668_D_8006E144;
            temp_a0_3 = Camera43_95668_Field(temp_s0, int*, 0x58);
            temp_a1 = ((int)(temp_a0_3 - 0x155) >> 4) + 0x10;
            if (Camera43_95668_D_8006E538 & 9) {
                temp_v0_2 = temp_a0_3 + temp_a1;
                Camera43_95668_Field(temp_s0, int*, 0x58) = temp_v0_2;
                if (temp_v0_2 >= 0x801) {
                    Camera43_95668_Field(temp_s0, int*, 0x58) = 0x800;
                }
            }
            if (Camera43_95668_D_8006E538 & 6) {
                temp_v0_3 = Camera43_95668_Field(temp_s0, int*, 0x58) - temp_a1;
                Camera43_95668_Field(temp_s0, int*, 0x58) = temp_v0_3;
                if (temp_v0_3 < 0x155) {
                    Camera43_95668_Field(temp_s0, int*, 0x58) = 0x155;
                }
            }
            Camera43_95668_D_8006E1D0 = Camera43_95668_Field(temp_s0, int*, 0x58) - 0x155;
            return;
        case 33:
            if (Camera43_95668_D_8006E12C == 0) {
                Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0xA8),
                                                                 &Camera43_95668_D_80069238,
                                                                 Camera43_95668_D_8006E064);
                Camera43_95668SelectSignedCameraOrbitRequest(0xC0);
                Camera43_95668UpdateCameraOrbitReturn();
            }
            Camera43_95668RefreshCameraPlayerAnchor();
            __asm__ __volatile__("" : "=r"(base18) : "0"(base18) : "$16", "$4");
            address4 = (int*)(base18 - 0x58);
            MATCHING_KEEP(address4);
            word2 = var_s1 << 2;
            MATCHING_KEEP(word2);
            word2 += var_s1;
            MATCHING_KEEP(word2);
            var_s0 = word2 << 2;
            Camera43_95668_D_8006E064 = Camera43_95668_D_8006E168;
            Camera43_95668CopyCameraPositionWithWrappedAngle(
                (CameraPosition*)address4,
                (CameraPosition*)((unsigned char*)Camera43_95668_D_8006929C + var_s0), 0);
            var_a0_2 = (int*)(base18 - 0x44);
            if (Camera43_95668_Field(base18, int*, 0) == 0) {
                word2 = Camera43_95668_Field(base18, int*, -0x58);
                MATCHING_BARRIER_GNU_VOLATILE("memory");
                word3 = Camera43_95668_D_8006E0E0;
                word2 >>= 1;
                __asm__("" : "=r"(word3) : "0"(word3), "r"(word2));
                word3 >>= 1;
                Camera43_95668_Field(base18, int*, -0x58) = word2;
                Camera43_95668_D_8006E0E0 = word3;
            }
        block_88:
            Camera43_95668CopyCameraPositionWithWrappedAngle(
                var_a0_2, (CameraPosition*)((unsigned char*)Camera43_95668_D_80069328 + var_s0), 0);
            Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x30),
                                                             &Camera43_95668_D_800693C8, 0);
            Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x1C),
                                                             &Camera43_95668_D_800693B4, 0);
            return;
        case 39:
            temp_a0_4 = (CameraPosition*)(base18 - 0x58);
            if (Camera43_95668_D_8006E12C == 0) {
                Camera43_95668SelectCameraFollowProfile(temp_a0_4);
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(base18, "$4");
                Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x58),
                                                                 &Camera43_95668_D_80069314, 0);
                Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x44),
                                                                 &Camera43_95668_D_800693A0, 0);
                Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x30),
                                                                 &Camera43_95668_D_800693C8, 0);
                Camera43_95668_D_8006E114 = -1;
                Camera43_95668_D_8006E118 = -1;
                Camera43_95668_D_8006E11C = -1;
                Camera43_95668_D_8006E120 = -1;
                Camera43_95668_D_8006E124 = -1;
            } else {
                Camera43_95668CopyCameraPositionWithWrappedAngle(
                    temp_a0_4, &Camera43_95668_D_8006929C[var_s1], 0);
                Camera43_95668CopyCameraPositionWithWrappedAngle(
                    (CameraPosition*)(base18 - 0x44), &Camera43_95668_D_80069328[var_s1], 0);
                Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x1C),
                                                                 &Camera43_95668_D_800693B4, 0);
                Camera43_95668CopyCameraPositionWithWrappedAngle((CameraPosition*)(base18 - 0x30),
                                                                 &Camera43_95668_D_800693C8, 0);
            }
            Camera43_95668RefreshCameraPlayerAnchor();
            break;
    }
    return;
}
#undef Camera43_95668_Field


/**
 * ???() - func_level_43_80095E78() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_43_80095E78() {
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
extern int D_8006E168;
/* AI generated adaptation; not human reviewed.
 * SCUS-94467 USA Rev0 80095ECC..80096104, 143 words.
 * Reuses verified level40_80087024 reset/settle and level44_8009387C
 * raw mode31 tag route. Original dispatch uses13/31/33/39; mode33
 * retains the D_8006E168 -> D_8006E064 word transfer before common update.
 * The shared update label preserves original helper and argument ordering.
 * Raw tag producers, units and caller cadence remain unresolved.
 * Acceptance: every original linked word and complete retail hashes.
 */
void func_level_43_80095ECC(int mode) {
    register int* base __asm__("$16");
    register unsigned char* actor __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register CameraPosition* updatePosition __asm__("$4");
    register Vector3D* updateOrigin __asm__("$5");
    register Vector3D* updateTarget __asm__("$6");
    switch (mode) {
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
            MATCHING_KEEP(position);
            updatePosition = position;
            updateOrigin = (Vector3D*)((char*)base - 40);
            updateTarget = (Vector3D*)((char*)base + 16);
            goto update;
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
            MATCHING_KEEP(position);
            func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
            func_800138A0(position, position);
            func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
            break;
        case 31: {
            register int* state __asm__("$3");
            register int value __asm__("$2");
            register unsigned char** pointer __asm__("$2") = DecodedMode31Tag;
            MATCHING_KEEP(pointer);
            state = &DecodedMode31CameraState;
            __asm__("" : "=r"(state) : "0"(state), "r"(pointer));
            actor = *pointer;
            value = DecodedMode31Value;
            MATCHING_KEEP(value);
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
        }
        case 33:
            copyBase = &D_8006E048;
            *copyBase = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            copiedPosition = (CameraPosition*)((char*)copyBase + 44);
            MATCHING_KEEP(copiedPosition);
            updatePosition = copiedPosition;
            updateOrigin = (Vector3D*)((char*)copyBase - 40);
            D_8006E064 = D_8006E168;
            updateTarget = (Vector3D*)((char*)copyBase + 16);
        update:
            func_800136F0(updatePosition, updateOrigin, updateTarget);
            func_800138A0(&D_8006E074, &DecodedSettleInput);
            func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
            break;
    }

}

extern CameraPosition D_80068FE0;
extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 80096108..80096460,215 original words. Verified selector mode13,
 * original modes31/33/39 retain setup/calls and post-callee rereads.
 * Raw units, helper/input/table/actor producers and cadence unresolved.
 * Test: original linked words and complete retail hashes.
 */
void func_level_43_80096108(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
        case 13:
            if ((DecodedCameraHeld & 16) && DecodedCameraPlayer[0x1B9]) {
                next = 7;
                goto change;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            next = DecodedCameraOverride;
            if (!next) {
            readTable:
                next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
                goto change;
            }
            if (next == DecodedCameraMode)
                return;
            goto change;

        case 33:
            next = DecodedCameraOverride;
            if (!next)
                goto readTable;
            if (next == mode)
                return;
            goto change;
        case 31:
            next = DecodedCameraOverride;
            if (next && next != 40)
                func_80016764(next);
            if (DecodedCameraPlayer[0x1B9] == 0) {
                register int* overrideState __asm__("$17") = &DecodedCameraOverride;
                register CameraPosition* initial __asm__("$16") =
                    (CameraPosition*)((char*)overrideState - 0xD8);
                if (*overrideState == 40) {
                force40:
                    next = 40;
                    goto change;
                }
                func_800135A4(initial, &D_80068FE0, camera.unk6c);
                func_800135A4((CameraPosition*)((char*)overrideState - 0xC4), initial, 0);
                camera.unk140[0] = 0;
                camera.unk140[1] = 0;
                camera.unk140[2] = 1;
                camera.unk140[5] = 0;
                func_80012AC8();
                func_80012B34();
                func_80016764(DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)]);
                ((unsigned char*)*(unsigned int*)(DecodedCameraPlayer + 0x250))[0x4C] = 16;
                return;
            }
            if (DecodedCameraPressed & 16) {
                register int* overrideState __asm__("$17") = &DecodedCameraOverride;
                register CameraPosition* initial __asm__("$16") =
                    (CameraPosition*)((char*)overrideState - 0xD8);
                if (*overrideState == 40)
                    goto force40;
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
                ((unsigned char*)*(unsigned int*)(DecodedCameraPlayer + 0x250))[0x4C] = 16;
            }
            return;
        case 39:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            if ((DecodedCameraPressed & 16) && DecodedCameraPlayer[0x1B9] &&
                *(int*)(DecodedCameraPlayer + 0x24C) == 4) {
                next = 31;
                goto change;
            }
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraModeTable[index];
            if (mode == next)
                return;
            if (next)
                goto change;
            next = 6;
            goto change;
        default:
            return;
    }
change:
    func_80016764(next);
}
