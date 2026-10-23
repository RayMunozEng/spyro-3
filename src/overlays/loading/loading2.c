#include "matching.h"
#include "common.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/loading/loading2/func_loading_80075360.s SHA256 3e0f0a412b600764f38da1db78c3ad669c3f36bb922ba641b319522b4ea9f9b5. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Loading75360Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Loading75360PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
/* extern */
int Loading75360InterpolateSine(int) __asm__("func_8004E9E4");
/* extern */
int Loading75360InterpolateCosine(int) __asm__("func_8004EA2C");
/* extern */
int Loading75360MeasureVectorLength(int*, int) __asm__("func_8004EDE8");
/* extern */
void Loading75360SubtractVector(int*, void*, int*) __asm__("func_8004F1C8");
/* extern */
extern int Loading75360_D_8006E020 __asm__("D_8006E020");
extern int Loading75360_D_8006E024 __asm__("D_8006E024");
extern int Loading75360_D_8006E028 __asm__("D_8006E028");
extern short Loading75360_D_8006E03C __asm__("D_8006E03C");
extern short Loading75360_D_8006E03E __asm__("D_8006E03E");
extern short Loading75360_D_8006E040 __asm__("D_8006E040");
extern int Loading75360_D_8006FBC4 __asm__("D_8006FBC4");
extern unsigned char Loading75360_D_80070328 __asm__("D_80070328");
extern int Loading75360_D_80072328 __asm__("D_80072328");

void func_loading_80075360(void) {
    /* Original 0x40 frame with three-word scratch vectors at SP10 and
     * SP20, padding at SP1C/SP2C. Sequential state0/1/2/3 tests and the
     * shared forward halfword-store destination follow the original CFG.
     * Signed division, MULT/MFHI and MULT/MFLO producers, SRA12 consumers,
     * unsigned counter windows and byte writes preserve the disc ordering.
     * The counter pointer is naturally allocated to saved17 in state1;
     * forcing that binding changed the original reciprocal load order.
     * State3 reuses saved17 for the three-word destination after its phase
     * argument is copied to register4. Empty constraints and comment-only
     * markers emit no instructions. Physical units/fixed point, helper
     * meanings, update cadence and synchronized runtime verification are
     * unresolved. AI generated;
      not human reviewed. */
    struct {
        Vector3D first;
        int pad1C;
        Vector3D second;
        int pad2C;
    } scratch;
    register int helperResult2 __asm__("$2");
    int temp_lo;
    register int phase16 __asm__("$16");
    register int phase16_2 __asm__("$16");
    register int scale16 __asm__("$16");
    register int phase17 __asm__("$17");
    register int raw3 __asm__("$3");
    register int raw3_2 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int raw3_3 __asm__("$3");
    int* counterPointer;
    register int* counterPointer18 __asm__("$18");
    register int count5 __asm__("$5");
    register int count7 __asm__("$7");
    register int state3 __asm__("$3");
    register int raw2 __asm__("$2");
    register int argument6 __asm__("$6");
    int product8;
    register int magic3 __asm__("$3");
    register int* destination6 __asm__("$6");
    register int* destination17 __asm__("$17");
    register int* scratchVector16 __asm__("$16");
    register int* scratchVector4 __asm__("$4");
    register void* source5 __asm__("$5");

    state3 = Loading75360_D_80072328;
    if (state3 == 0) {
        raw3 = Loading75360_D_8006FBC4;
        raw2 = raw3 * 1792;
        MATCHING_KEEP_CLOBBER(raw2, "$16");
        phase16 = -128;
        MATCHING_KEEP(phase16);
        raw3 = raw2 / 140;
        MATCHING_KEEP(raw3);
        phase16 -= raw3;
        Loading75360_D_8006E020 =
            ((int)(Loading75360InterpolateCosine(phase16) * 0xA00) >> 0xC) + 0x2000;
        raw3 = ((int)(Loading75360InterpolateSine(phase16) * 0xA00) >> 0xC) + 0x2000;
        Loading75360_D_8006E028 = 0x1E00;
        Loading75360_D_8006E024 = raw3;
        Loading75360_D_8006E03C = 0;
        Loading75360_D_8006E03E = 0xF80;
        Loading75360_D_8006E040 = phase16 + 0x800;
        return;
    } else if (state3 == 1) {
        counterPointer = &Loading75360_D_8006FBC4;
        phase16_2 = ((((*counterPointer) << 0xA) / 140) - 0x200) & 0xFFF;
        Loading75360_D_8006E020 =
            ((int)(Loading75360InterpolateCosine(phase16_2) * 0x600) >> 0xC) + 0x2000;
        raw3_2 = ((int)(Loading75360InterpolateSine(phase16_2) * 0x600) >> 0xC) + 0x2000;
        raw2 = 0x1E80;
        MATCHING_KEEP(raw2);
        Loading75360_D_8006E028 = raw2;
        raw2 = 0xF80;
        MATCHING_KEEP(raw2);
        Loading75360_D_8006E024 = raw3_2;
        Loading75360_D_8006E03C = 0;
        Loading75360_D_8006E03E = raw2;
        MATCHING_BARRIER_VOLATILE("memory");
        raw3_2 = *counterPointer;
        phase16_2 += 0x800;
        Loading75360_D_8006E040 = phase16_2;
        if ((unsigned int)(raw3_2 - 33) < 16) {
            raw2 = 32 - raw3_2;
            raw2 <<= 1;
            Loading75360Field(&Loading75360_D_80070328, signed char*, 17) = raw2;
            raw2 = raw3_2 - 32;
            MATCHING_KEEP(raw2);
            Loading75360Field(&Loading75360_D_80070328, signed char*, 18) = raw2;
            __asm__ volatile("# window33" ::"r"(raw3_2));
            return;
        }
        if ((unsigned int)(raw3_2 - 57) < 16) {
            raw2 = 64 - raw3_2;
            raw2 <<= 1;
            Loading75360Field(&Loading75360_D_80070328, signed char*, 18) = raw2;
            return;
        }
        if ((unsigned int)(raw3_2 - 89) < 16) {
            raw3_2 -= 104;
            raw2 = raw3_2 << 1;
            Loading75360Field(&Loading75360_D_80070328, signed char*, 17) = raw2;
            Loading75360Field(&Loading75360_D_80070328, signed char*, 18) = raw3_2;
            __asm__ volatile("# window89");
            return;
        }
        return;
    } else if (state3 == 2) {
        scratchVector4 = &scratch.first.x;
        source5 = &Loading75360_D_80070328;
        destination6 = &Loading75360_D_8006E020;
        MATCHING_KEEP3(scratchVector4, source5, destination6);
        Loading75360_D_8006E024 = 0x1E70;
        Loading75360_D_8006E028 = 0x1E70;
        count7 = Loading75360_D_8006FBC4;
        *destination6 = 0x3E00 - count7 * 160;
        Loading75360SubtractVector(scratchVector4, source5, destination6);
        Loading75360_D_8006E03C = 0;
        helperResult2 = Loading75360PlanarHeadingLookup(
            Loading75360MeasureVectorLength(&scratch.first.x, 0), scratch.first.z, 1);
        argument4 = scratch.first.x;
        argument5 = scratch.first.y;
        argument6 = 1;
        goto storeFinalHalfwords;
    } else if (state3 == 3) {
        counterPointer18 = &Loading75360_D_8006FBC4;
        count5 = *counterPointer18;
        scale16 = (count5 * 0x1C) + 0x600;
        phase17 = (-0x100 - ((count5 * 0x280) / 120)) & 0xFFF;
        raw2 = Loading75360InterpolateCosine(phase17);
        product8 = raw2 * scale16;
        argument4 = phase17;
        MATCHING_KEEP(argument4);
        destination17 = &Loading75360_D_8006E020;
        raw2 = (product8 >> 12) + 8192;
        *destination17 = raw2;
        raw2 = Loading75360InterpolateSine(argument4);
        product8 = raw2 * scale16;
        scratchVector16 = &scratch.second.x;
        scratchVector4 = scratchVector16;
        source5 = &Loading75360_D_80070328;
        raw3 = *counterPointer18;
        raw2 = 0x1F00;
        raw3 <<= 2;
        MATCHING_KEEP(raw3);
        raw2 -= raw3;
        Loading75360_D_8006E028 = raw2;
        raw2 = (product8 >> 12) + 8192;
        Loading75360_D_8006E024 = raw2;
        MATCHING_BARRIER_VOLATILE("$6");
        Loading75360SubtractVector(scratchVector4, source5, destination17);
        Loading75360_D_8006E03C = 0;
        helperResult2 = Loading75360PlanarHeadingLookup(
            Loading75360MeasureVectorLength(&scratch.second.x, 0), scratch.second.z, 1);
        argument6 = 1;
        MATCHING_KEEP(argument6);
        argument4 = scratch.second.x;
        argument5 = scratch.second.y;
        goto storeFinalHalfwords;
    }
    return;
storeFinalHalfwords:
    __asm__ volatile("# angle-store-join" : "=r"(helperResult2) : "0"(helperResult2));
    Loading75360_D_8006E03E = -helperResult2;
    Loading75360_D_8006E040 = Loading75360PlanarHeadingLookup(argument4, argument5, argument6);
}
#undef Loading75360Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original asm/nonmatchings/overlays/loading/loading2/func_loading_80075738.s SHA256 8ee46f734ad59d645a429e3c4d02a3529d7af0ac03c9e64f3b482c2f556ccb89. Native/linked/full hashes required;
 units/helper meanings/cadence unresolved. */
#define Loading75738Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Loading75738PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
/* extern */
int Loading75738InterpolateSine(int) __asm__("func_8004E9E4");
/* extern */
int Loading75738InterpolateCosine(int) __asm__("func_8004EA2C");
/* extern */
int Loading75738MeasureVectorLength(int*, int) __asm__("func_8004EDE8");
/* extern */
void Loading75738SubtractVector(int*, void*, int*) __asm__("func_8004F1C8");
/* extern */
extern int Loading75738_D_8006C528 __asm__("D_8006C528");
extern int Loading75738_D_8006E020 __asm__("D_8006E020");
extern int Loading75738_D_8006E024 __asm__("D_8006E024");
extern int Loading75738_D_8006E028 __asm__("D_8006E028");
extern short Loading75738_D_8006E03C __asm__("D_8006E03C");
extern short Loading75738_D_8006E03E __asm__("D_8006E03E");
extern short Loading75738_D_8006E040 __asm__("D_8006E040");
extern int Loading75738_D_8006FBC4 __asm__("D_8006FBC4");
extern unsigned char Loading75738_D_80070328 __asm__("D_80070328");
extern int Loading75738_D_80072328 __asm__("D_80072328");

void func_loading_80075738(void) {
    /* Original 0x40 frame with three-word scratch vectors at SP10 and
     * SP20, padding at SP1C/SP2C. Sequential state tests and the shared
     * forward halfword-store destination retain the original control flow.
     * State1 tests D_8006C528 against0x204 and keeps distinct SLL12/SRA12
     * and SLL11/SRA12 helper-return paths before the shared word store.
     * Signed reciprocal and low-product producers, unsigned counter windows
     * and byte writes retain their original registers and ordering. State3
     * reuses saved17 as the destination after copying its phase argument
     * to register4. Empty constraints and comment-only markers emit no
     * instructions. Raw units/fixed point, helper meanings, update cadence
     * and synchronized runtime validation remain unresolved. AI generated;
     * not human reviewed. */
    struct {
        Vector3D first;
        int pad1C;
        Vector3D second;
        int pad2C;
    } scratch;
    register int helperResult2 __asm__("$2");
    int temp_lo;
    register int phase16 __asm__("$16");
    register int phase16_2 __asm__("$16");
    register int scale16 __asm__("$16");
    register int phase17 __asm__("$17");
    register int raw3 __asm__("$3");
    register int raw3_2 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int raw3_3 __asm__("$3");
    int* unusedCounterPointer;
    register int* counterPointer18 __asm__("$18");
    register int count5 __asm__("$5");
    register int count7 __asm__("$7");
    register int state3 __asm__("$3");
    register int raw2 __asm__("$2");
    register int argument6 __asm__("$6");
    int product8;
    register int magic3 __asm__("$3");
    register int* destination6 __asm__("$6");
    register int* destination17 __asm__("$17");
    register int* scratchVector16 __asm__("$16");
    register int* scratchVector4 __asm__("$4");
    register void* source5 __asm__("$5");

    state3 = Loading75738_D_80072328;
    if (state3 == 0) {
        raw3 = Loading75738_D_8006FBC4;
        raw2 = raw3 * 1792;
        MATCHING_KEEP_CLOBBER(raw2, "$16");
        phase16 = -128;
        MATCHING_KEEP(phase16);
        raw3 = raw2 / 140;
        MATCHING_KEEP(raw3);
        phase16 -= raw3;
        Loading75738_D_8006E020 =
            ((int)(Loading75738InterpolateCosine(phase16) << 12) >> 12) + 8192;
        Loading75738_D_8006E024 = ((int)(Loading75738InterpolateSine(phase16) << 12) >> 12) + 8192;
        Loading75738_D_8006E028 = 0x1A00;
        Loading75738_D_8006E03C = 0;
        Loading75738_D_8006E03E = 0xF00;
        Loading75738_D_8006E040 = phase16 + 2048;
        return;
    } else if (state3 == 1) {
        if (Loading75738_D_8006C528 == 0x204) {
            raw3_2 = Loading75738_D_8006FBC4;
            raw3_2 <<= 10;
            MATCHING_KEEP(raw3_2);
            raw2 = raw3_2 / 140;
            MATCHING_KEEP(raw2);
            raw2 += 512;
            phase16_2 = raw2 & 4095;
            Loading75738_D_8006E020 =
                ((int)(Loading75738InterpolateCosine(phase16_2) << 12) >> 12) + 8192;
            raw2 = Loading75738InterpolateSine(phase16_2);
            raw2 <<= 12;
            raw2 >>= 12;
            raw2 += 8192;
            Loading75738_D_8006E024 = raw2;
            __asm__ volatile("# phase-plus");
            raw2 = 0x1C00;
        } else {
            raw3_2 = Loading75738_D_8006FBC4;
            raw3_2 <<= 10;
            MATCHING_KEEP(raw3_2);
            raw2 = raw3_2 / 140;
            MATCHING_KEEP(raw2);
            raw2 += -512;
            phase16_2 = raw2 & 4095;
            Loading75738_D_8006E020 =
                ((int)(Loading75738InterpolateCosine(phase16_2) << 11) >> 12) + 8192;
            raw2 = Loading75738InterpolateSine(phase16_2);
            raw2 <<= 11;
            raw2 >>= 12;
            raw2 += 8192;
            Loading75738_D_8006E024 = raw2;
            __asm__ volatile("# phase-minus");
            raw2 = 0x1E80;
        }
        Loading75738_D_8006E028 = raw2;
        MATCHING_BARRIER_VOLATILE("memory");
        raw3_2 = Loading75738_D_8006FBC4;
        raw2 = 0xF80;
        Loading75738_D_8006E03E = raw2;
        raw2 = phase16_2 + 2048;
        Loading75738_D_8006E03C = 0;
        Loading75738_D_8006E040 = raw2;
        if ((unsigned int)(raw3_2 - 33) < 16) {
            raw2 = 32 - raw3_2;
            raw2 <<= 1;
            Loading75738Field(&Loading75738_D_80070328, signed char*, 17) = raw2;
            raw2 = raw3_2 - 32;
            MATCHING_KEEP(raw2);
            Loading75738Field(&Loading75738_D_80070328, signed char*, 18) = raw2;
            __asm__ volatile("# window33" ::"r"(raw3_2));
            return;
        }
        if ((unsigned int)(raw3_2 - 57) < 16) {
            raw2 = 64 - raw3_2;
            raw2 <<= 1;
            Loading75738Field(&Loading75738_D_80070328, signed char*, 18) = raw2;
            return;
        }
        if ((unsigned int)(raw3_2 - 89) < 16) {
            raw3_2 -= 104;
            raw2 = raw3_2 << 1;
            Loading75738Field(&Loading75738_D_80070328, signed char*, 17) = raw2;
            Loading75738Field(&Loading75738_D_80070328, signed char*, 18) = raw3_2;
            __asm__ volatile("# window89");
            return;
        }
        return;
    } else if (state3 == 2) {
        scratchVector4 = &scratch.first.x;
        source5 = &Loading75738_D_80070328;
        destination6 = &Loading75738_D_8006E020;
        MATCHING_KEEP3(scratchVector4, source5, destination6);
        Loading75738_D_8006E024 = 0x1800;
        Loading75738_D_8006E028 = 0x1E70;
        count7 = Loading75738_D_8006FBC4;
        *destination6 = 0x3E00 - count7 * 160;
        Loading75738SubtractVector(scratchVector4, source5, destination6);
        Loading75738_D_8006E03C = 0;
        helperResult2 = Loading75738PlanarHeadingLookup(
            Loading75738MeasureVectorLength(&scratch.first.x, 0), scratch.first.z, 1);
        argument4 = scratch.first.x;
        argument5 = scratch.first.y;
        argument6 = 1;
        goto storeFinalHalfwords;
    } else if (state3 == 3) {
        counterPointer18 = &Loading75738_D_8006FBC4;
        count5 = *counterPointer18;
        scale16 = count5 * 28 + 0x800;
        phase17 = (-0x100 - ((count5 * 0x280) / 120)) & 0xFFF;
        raw2 = Loading75738InterpolateCosine(phase17);
        product8 = raw2 * scale16;
        argument4 = phase17;
        MATCHING_KEEP(argument4);
        destination17 = &Loading75738_D_8006E020;
        raw2 = (product8 >> 12) + 8192;
        *destination17 = raw2;
        raw2 = Loading75738InterpolateSine(argument4);
        product8 = raw2 * scale16;
        scratchVector16 = &scratch.second.x;
        scratchVector4 = scratchVector16;
        source5 = &Loading75738_D_80070328;
        raw3 = *counterPointer18;
        raw2 = 0x1F00;
        raw3 <<= 4;
        MATCHING_KEEP(raw3);
        raw2 -= raw3;
        Loading75738_D_8006E028 = raw2;
        raw2 = (product8 >> 12) + 8192;
        Loading75738_D_8006E024 = raw2;
        MATCHING_BARRIER_VOLATILE("$6");
        Loading75738SubtractVector(scratchVector4, source5, destination17);
        Loading75738_D_8006E03C = 0;
        helperResult2 = Loading75738PlanarHeadingLookup(
            Loading75738MeasureVectorLength(&scratch.second.x, 0), scratch.second.z, 1);
        argument6 = 1;
        MATCHING_KEEP(argument6);
        argument4 = scratch.second.x;
        argument5 = scratch.second.y;
        goto storeFinalHalfwords;
    }
    return;
storeFinalHalfwords:
    __asm__ volatile("# angle-store-join" : "=r"(helperResult2) : "0"(helperResult2));
    Loading75738_D_8006E03E = -helperResult2;
    Loading75738_D_8006E040 = Loading75738PlanarHeadingLookup(argument4, argument5, argument6);
}
#undef Loading75738Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80075B74.
* AI generated; not human reviewed. Original625 native/linked instructions,
* every conditional/internal jump/call/data symbol and full retail hashes
* must match. No owned selectors, padding or separate initializer objects.
* Original68hex104-byte frame saves S0..S5/RA. The48-byte text buffer retains
* SP18..47 and the fifth outgoing argument retains its original SP10 word.
* Original1/2,3,4 dispatch,24-record loop,88-byte record stride,unsigned
* byte tables,signed halfword tables,word language tables and shared render/
* fade entries retain their physical instruction chains and memory widths.
* Every MULT input is a complete initialized signed64 C product. Consuming
* LO narrows to signed32 before dynamic division;HI uses the original /40
* magic66666667,arithmetic shift4 and dividend-sign correction. Original
* dynamic divide-by-zero and signed overflow traps remain intact. Whole
* initialized operands prevent generic64x64 cross-product expansion.
* A fresh timer read follows the first text/draw/helper chain before the
* second window tests;the earlier V1 word is not live across those calls.
* Original unsigned LHU/SLL16/SRA19 sample chain and flag store precede the
* final low-result capture. Empty memory metadata reads only its own fully
* written byte at record+68,never padding or incoming saved-register values.
* Two later clamp predicates are produced after their own negative-input
* conditions. Read-only compiler trace21155 identifies the moved predicate
* that otherwise blocks the two earlier native sum delay slots.
* Metadata emits zero CPU words;no opcode asm,fixedFP,partial products or
* overlapping live fixed aliases. Compiler/filter/flags remain unchanged.
* Known helper views cite drawutil.h,mobyfunc.h,memcard.h,cyclorama.h,
* mobydraw.h and the existing matched sprintf declaration in src/draw.c.
* Fade remains an original physical call view;its full incoming word values
* are retained without assuming a narrower source-level argument contract.
* Falsification:all625 original words,actual symbols/targets,full EXE/every
* overlay hash; signed /40 vectors-41->-1,-1->0,0->0,40->1,41->1.
* Confidence is binary identity only. Raw units/fixed point,full helper/
* producer/consumer chains,cadence beyond invocation,buffer-content bounds
* and synchronized retail runtime remain open. Next:human review and retail
* capture. Engine/browser unchanged;no runtime parity claim is made.
*/
/* Original assembly SHA256 c2c78bf30715404bf4aea95f121cd07ec4ea5de7061d80254d32a03306b20327 */
#define Loading75B74CompleteProductLow(a, b)                           \
    ({                                                                 \
        int left = (a), right = (b), low;                              \
        long long product;                                             \
        __asm__("" : "=r"(left), "=r"(right) : "0"(left), "1"(right)); \
        product = (long long)left * (long long)right;                  \
        __asm__("" : "=l"(low) : "x"(product));                        \
        low;                                                           \
    })
extern volatile int Loading75B74Data6FBC4View1 __asm__("D_8006FBC4");
#define Loading75B74Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
void Loading75B74CallDrawStringCenteredView1(char*, int, int, int) __asm__("DrawStringCentered");
void Loading75B74CallDrawStringRightAlignedView1(char*, int, int,
                                                 int) __asm__("DrawStringRightAligned");
void Loading75B74EmitVisibleWorldTrianglePacketsView1(void) __asm__("func_8001C368");
void Loading75B74EmitPortalVolumePacketsView1() __asm__("func_8001EDEC");
int Loading75B74EmitScreenColorQuadView1() __asm__("func_800200A0");
void Loading75B74DrawNumericCounterTextView1(int, int, int, int) __asm__("func_80020428");
void Loading75B74EmitUiTextGlyphPacketsView1(char*, int, int, int, int*) __asm__("func_8002E748");
void Loading75B74BuildMobyRenderListsView1(void) __asm__("func_80030478");
void Loading75B74EmitVisibleRecordPacketsView1(void) __asm__("func_80033C5C");
int Loading75B74EmitPlayerModelPacketsView1() __asm__("func_8003CDA0");
void Loading75B74FillWordRangeView1(void*, int, int) __asm__("func_8004E790");
int Loading75B74FillWordRangeUnrolled4View1() __asm__("func_8004E7AC");
int Loading75B74Call75114View1() __asm__("func_loading_80075114");
int Loading75B74CallsprintfView1(char*, const char*, ...) __asm__("sprintf");
extern unsigned char Loading75B74Data658A0View1 __asm__("D_800658A0");
extern unsigned char Loading75B74Data65920View1 __asm__("D_80065920");
extern unsigned char Loading75B74Data674C0View1 __asm__("D_800674C0");
extern unsigned char Loading75B74Data674D8View1 __asm__("D_800674D8");
extern unsigned char Loading75B74Data674E8View1 __asm__("D_800674E8");
extern unsigned char Loading75B74Data674FCView1 __asm__("D_800674FC");
extern unsigned char Loading75B74Data67510View1 __asm__("D_80067510");
extern unsigned char Loading75B74Data67520View1 __asm__("D_80067520");
extern unsigned char Loading75B74Data69CF8View1 __asm__("D_80069CF8");
extern unsigned char Loading75B74Data69DC8View1 __asm__("D_80069DC8");
extern unsigned char Loading75B74Data69DCCView1 __asm__("D_80069DCC");
extern unsigned char Loading75B74Data69DD0View1 __asm__("D_80069DD0");
extern unsigned char Loading75B74Data69DD4View1 __asm__("D_80069DD4");
extern int Loading75B74Data6C508View1 __asm__("D_8006C508");
extern void* Loading75B74Data6C550View1 __asm__("D_8006C550");
extern int Loading75B74Data6C58CView1 __asm__("D_8006C58C");
extern int Loading75B74Data6C598View1 __asm__("D_8006C598");
extern void* Loading75B74Data6C604View1 __asm__("D_8006C604");
extern int Loading75B74Data6C60CView1 __asm__("D_8006C60C");
extern int Loading75B74Data6C668View1 __asm__("D_8006C668");
extern int Loading75B74Data6C6F8View1 __asm__("D_8006C6F8");
extern int Loading75B74Data6C71CView1 __asm__("D_8006C71C");
extern int Loading75B74Data6C720View1 __asm__("D_8006C720");
extern int Loading75B74Data6C764View1 __asm__("D_8006C764");
extern int Loading75B74Data6C76CView1 __asm__("D_8006C76C");
extern int Loading75B74Data6D058View1 __asm__("D_8006D058");
extern unsigned char Loading75B74Data6E3B0View1 __asm__("D_8006E3B0");
extern int Loading75B74Data6FBC4View2 __asm__("D_8006FBC4");
extern int Loading75B74Data6FBC8View1 __asm__("D_8006FBC8");
extern unsigned char Loading75B74Data70328View1 __asm__("D_80070328");
extern unsigned char Loading75B74Data71A10View1 __asm__("D_80071A10");
extern void* Loading75B74Data722D0View1 __asm__("D_800722D0");
extern unsigned char Loading75B74Data74504View1 __asm__("D_loading_80074504");
void func_loading_80075B74(void) {
    register int recordOffsetOrAmount16 __asm__("$16");
    register int byteCursorRowOrSavedWord17 __asm__("$17");
    register int recordIndex18 __asm__("$18");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register int argumentWord7 __asm__("$7");
    register int argumentWord4 __asm__("$4");
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int signedHalfwordTable21 __asm__("$21"), originalByte255 __asm__("$20");
    register int signedFortiethMagic19 __asm__("$19"), completeProductHalf8 __asm__("$8");
    char originalTextBuffer[48];
    rawWord3 = Loading75B74Data6FBC8View1;
    MATCHING_KEEP(rawWord3);
    switch (rawWord3) {
        case 1:
        case 2:
            argumentWord4 = 2;
            if (Loading75B74Field(&Loading75B74Data70328View1, int*, 0x244) != 0) {
                argumentWord5 = 0xFF;
                argumentWord6 = 0xFF;
                argumentWord7 = 0xFF;
                goto drawOriginalFade;
            }
            if (Loading75B74Data6FBC4View2 < 0x10) {
                Loading75B74EmitPortalVolumePacketsView1(argumentWord4);
                Loading75B74FillWordRangeUnrolled4View1(Loading75B74Data6C668View1 - 0x3000, 0,
                                                        0xC00);
                goto queueOriginalCommonDraw;
            }
            break;
        case 3:
            rawWord2 = Loading75B74Data722D0View1 + 0x36000;
            Loading75B74Data6C550View1 = rawWord2;
            Loading75B74Data6C604View1 = rawWord2;
            Loading75B74Field(Loading75B74Data722D0View1, unsigned char*, 0x36048) = 0xFF;
            if ((unsigned int)(Loading75B74Data6FBC4View2 - 0x21) < 0x48U) {
                recordIndex18 = 0;
                signedFortiethMagic19 = 0x66666667;
                MATCHING_KEEP(signedFortiethMagic19);
                signedHalfwordTable21 = (int)&Loading75B74Data658A0View1;
                MATCHING_KEEP(signedHalfwordTable21);
                originalByte255 = 255;
                MATCHING_KEEP(originalByte255);
                byteCursorRowOrSavedWord17 = (int)&Loading75B74Data6E3B0View1;
                do {
                    recordOffsetOrAmount16 = recordIndex18 * 8;
                    if (Loading75B74Field((recordOffsetOrAmount16 + Loading75B74Data6C764View1),
                                          unsigned char*, 4) != 0) {
                        Loading75B74FillWordRangeView1(Loading75B74Data6C604View1, 0, 0x58);
                        Loading75B74Field(Loading75B74Data6C604View1, short*, 0x36) = 1;
                        Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x3C) =
                            (unsigned char)Loading75B74Field(byteCursorRowOrSavedWord17,
                                                             unsigned char*, 0);
                        argumentWord5 = Loading75B74Data6C764View1;
                        MATCHING_KEEP(argumentWord5);
                        argumentWord5 = recordOffsetOrAmount16 + argumentWord5;
                        {
                            long long firstCompleteSignedProduct, secondCompleteSignedProduct,
                                thirdCompleteSignedProduct, fourthCompleteSignedProduct,
                                fifthCompleteSignedProduct;
                            int firstProductHigh, secondProductLow, thirdProductHigh,
                                fourthProductHigh, fifthProductLow;
                            argumentWord6 = Loading75B74Field(argumentWord5, int*, 0);
                            argumentWord4 = argumentWord6 << 7;
                            firstCompleteSignedProduct =
                                (long long)argumentWord4 * (long long)signedFortiethMagic19;
                            rawWord2 = Loading75B74Field(argumentWord5, unsigned char*, 5);
                            rawWord2 <<= 1;
                            rawWord3 = Loading75B74Field(
                                (int)&Loading75B74Data65920View1 + rawWord2, short*, 0);
                            argumentWord4 >>= 31;
                            rawWord2 = rawWord3 * 3;
                            rawWord3 = rawWord2 << 4;
                            rawWord3 -= rawWord2;
                            __asm__(""
                                    : "=h"(firstProductHigh)
                                    : "x"(firstCompleteSignedProduct), "r"(rawWord3));
                            completeProductHalf8 = firstProductHigh;
                            MATCHING_KEEP(completeProductHalf8);
                            rawWord2 = completeProductHalf8 >> 4;
                            rawWord2 -= argumentWord4;
                            rawWord2 <<= 1;
                            rawWord2 += signedHalfwordTable21;
                            rawWord2 = Loading75B74Field(rawWord2, short*, 0);
                            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(rawWord2));
                            rawWord3 >>= 10;
                            __asm__(""
                                    : "=r"(rawWord3), "=r"(rawWord2)
                                    : "0"(rawWord3), "1"(rawWord2), "r"(completeProductHalf8));
                            secondCompleteSignedProduct = (long long)rawWord3 * (long long)rawWord2;
                            argumentWord7 = (int)Loading75B74Data6C604View1;
                            argumentWord6 <<= 2;
                            __asm__("" : "=l"(secondProductLow) : "x"(secondCompleteSignedProduct));
                            completeProductHalf8 = secondProductLow;
                            MATCHING_KEEP(completeProductHalf8);
                            rawWord2 = completeProductHalf8 >> 12;
                            rawWord2 += 340;
                            rawWord2 -= argumentWord6;
                            Loading75B74Field(argumentWord7, int*, 12) = rawWord2;
                            rawWord2 = Loading75B74Field(argumentWord5, int*, 0);
                            rawWord3 = rawWord2 * 3;
                            rawWord2 = rawWord3 << 4;
                            rawWord2 -= rawWord3;
                            rawWord2 <<= 2;
                            __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(completeProductHalf8));
                            thirdCompleteSignedProduct =
                                (long long)rawWord2 * (long long)signedFortiethMagic19;
                            rawWord2 >>= 31;
                            __asm__("" : "=h"(thirdProductHigh) : "x"(thirdCompleteSignedProduct));
                            completeProductHalf8 = thirdProductHigh;
                            MATCHING_KEEP(completeProductHalf8);
                            rawWord3 = completeProductHalf8 >> 4;
                            rawWord3 -= rawWord2;
                            rawWord3 += 38;
                            Loading75B74Field(argumentWord7, int*, 16) = rawWord3;
                            rawWord3 = Loading75B74Field(argumentWord5, int*, 0);
                            rawWord3 <<= 7;
                            __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(completeProductHalf8));
                            fourthCompleteSignedProduct =
                                (long long)rawWord3 * (long long)signedFortiethMagic19;
                            rawWord2 = Loading75B74Field(argumentWord5, unsigned char*, 5);
                            rawWord2 <<= 1;
                            rawWord2 += signedHalfwordTable21;
                            argumentWord4 = Loading75B74Field(rawWord2, unsigned short*, 0);
                            rawWord3 >>= 31;
                            argumentWord4 <<= 16;
                            __asm__(""
                                    : "=h"(fourthProductHigh)
                                    : "x"(fourthCompleteSignedProduct), "r"(argumentWord4));
                            completeProductHalf8 = fourthProductHigh;
                            MATCHING_KEEP(completeProductHalf8);
                            rawWord2 = completeProductHalf8 >> 4;
                            rawWord2 -= rawWord3;
                            rawWord2 <<= 1;
                            rawWord2 += signedHalfwordTable21;
                            rawWord2 = Loading75B74Field(rawWord2, short*, 0);
                            __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4), "r"(rawWord2));
                            argumentWord4 >>= 19;
                            __asm__(""
                                    : "=r"(argumentWord4), "=r"(rawWord2)
                                    : "0"(argumentWord4), "1"(rawWord2), "r"(completeProductHalf8));
                            fifthCompleteSignedProduct =
                                (long long)argumentWord4 * (long long)rawWord2;
                            Loading75B74Field(argumentWord7, signed char*, 68) = 0;
                            rawWord3 = Loading75B74Data6C604View1;
                            __asm__(""
                                    : "=l"(fifthProductLow)
                                    : "x"(fifthCompleteSignedProduct), "r"(rawWord3),
                                      "m"(Loading75B74Field(argumentWord7, signed char*, 68)));
                            completeProductHalf8 = fifthProductLow;
                            MATCHING_KEEP(completeProductHalf8);
                            rawWord2 = completeProductHalf8 >> 12;
                            rawWord2 += 3200;
                            Loading75B74Field(argumentWord7, int*, 20) = rawWord2;
                        }
                        Loading75B74Field(rawWord3, signed char*, 69) = 8;
                        Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x46) =
                            (unsigned char)Loading75B74Field(
                                (recordOffsetOrAmount16 + Loading75B74Data6C764View1),
                                volatile unsigned char*, 6);
                        MATCHING_OBSERVE(recordOffsetOrAmount16);
                        Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x47) = 0x3F;
                        Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x54) =
                            (signed char)(Loading75B74Field(byteCursorRowOrSavedWord17,
                                                            unsigned char*, 0) +
                                          1);
                        Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x4C) =
                            originalByte255;
                        Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x4E) = 0x40;
                        Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x4C) =
                            originalByte255;
                        rawWord3 = Loading75B74Data6C604View1;
                        Loading75B74Data6C604View1 = rawWord3 + 0x58;
                        Loading75B74Field(rawWord3, unsigned char*, 0xA0) = originalByte255;
                    }
                    recordIndex18 += 1;
                    byteCursorRowOrSavedWord17 += 1;
                } while (recordIndex18 < 0x18);
            }
            rawWord3 = Loading75B74Data6FBC4View2;
            if ((unsigned int)(rawWord3 - 4) < 0x5DU) {
                byteCursorRowOrSavedWord17 = 0x18;
                if (rawWord3 < 0x10) {
                    rawWord2 = Loading75B74Field((int)&Loading75B74Data67520View1 +
                                                     Loading75B74Data6FBC4View1,
                                                 unsigned char*, 0);
                    byteCursorRowOrSavedWord17 = rawWord2 - 16;
                } else if ((rawWord2 = rawWord3 < 0x54, !rawWord2)) {
                    rawWord2 = Loading75B74Field((int)&Loading75B74Data674E8View1 +
                                                     Loading75B74Data6FBC4View1,
                                                 unsigned char*, 0);
                    byteCursorRowOrSavedWord17 = rawWord2 - 16;
                }
                argumentWord5 = Loading75B74Data6FBC4View2;
                if (argumentWord5 < 0x20) {
                    rawWord2 = Loading75B74Data6C60CView1;
                    rawWord2 <<= 2;
                    rawWord3 =
                        Loading75B74Field((int)&Loading75B74Data71A10View1 + rawWord2, int*, 0);
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = Loading75B74Data6C720View1;
                    recordOffsetOrAmount16 = rawWord3 - rawWord2;
                } else {
                    rawWord3 = Loading75B74Data6C6F8View1;
                    argumentWord4 = rawWord3 + 1;
                    if (rawWord3 < 16) {
                        argumentWord4 += rawWord3;
                    }
                    if (argumentWord4 >= 33) {
                        argumentWord4 = 32;
                        MATCHING_KEEP(argumentWord4);
                    }
                    rawWord2 = argumentWord4 + 32;
                    argumentWord5 = rawWord2 - argumentWord5;
                    if (argumentWord5 < 0) {
                        argumentWord5 = 0;
                    }
                    rawWord2 = argumentWord4 < argumentWord5;
                    if (rawWord2 != 0) {
                        argumentWord5 = argumentWord4;
                    }
                    rawWord2 = Loading75B74CompleteProductLow(
                        (Loading75B74Field((int)&Loading75B74Data71A10View1 +
                                               (Loading75B74Data6C60CView1 * 4),
                                           int*, 0) -
                         Loading75B74Data6C720View1),
                        argumentWord5);
                    MATCHING_KEEP(rawWord2);
                    recordOffsetOrAmount16 = rawWord2 / argumentWord4;
                }
                Loading75B74CallDrawStringRightAlignedView1(
                    Loading75B74Field((int)&Loading75B74Data69DC8View1 +
                                          (Loading75B74Data6C76CView1 * 4),
                                      int*, 0),
                    0x12C, byteCursorRowOrSavedWord17, 1);
                Loading75B74DrawNumericCounterTextView1(recordOffsetOrAmount16, 0x17C,
                                                        byteCursorRowOrSavedWord17, 1);
                Loading75B74FillWordRangeView1(Loading75B74Data6C604View1, 0, 0x58);
                rawWord3 = Loading75B74Data6C604View1;
                rawWord2 = 0x154;
                Loading75B74Field(rawWord3, int*, 12) = rawWord2;
                rawWord2 = byteCursorRowOrSavedWord17 + 14;
                Loading75B74Field(rawWord3, int*, 16) = rawWord2;
                rawWord2 = 3072;
                Loading75B74Field(rawWord3, int*, 20) = rawWord2;
                Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x46) =
                    (unsigned char)(Loading75B74Data6FBC4View2 * 4);
                Loading75B74Field(Loading75B74Data6C604View1, short*, 0x36) = 1;
                Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x47) = 0x3F;
                Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x54) = 2;
                Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x4C) = 0xFF;
                Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x4E) = 0x40;
                rawWord3 = Loading75B74Data6C604View1;
                Loading75B74Data6C604View1 = rawWord3 + 0x58;
                Loading75B74Field(rawWord3, unsigned char*, 0xA0) = 255;
            }
            rawWord3 = Loading75B74Data6FBC4View2;
            if ((unsigned int)(rawWord3 - 0x28) < 0x61U) {
                byteCursorRowOrSavedWord17 = 0xD0;
                if (rawWord3 < 0x34) {
                    rawWord3 = Loading75B74Field((int)&Loading75B74Data674FCView1 +
                                                     Loading75B74Data6FBC4View1,
                                                 unsigned char*, 0);
                    goto computeOriginalLowerRow;
                }
                if ((rawWord2 = rawWord3 < 0x7C, !rawWord2)) {
                    rawWord3 = Loading75B74Field((int)&Loading75B74Data674C0View1 +
                                                     Loading75B74Data6FBC4View1,
                                                 unsigned char*, 0);
                computeOriginalLowerRow:
                    rawWord2 = 248;
                    MATCHING_KEEP(rawWord2);
                    byteCursorRowOrSavedWord17 = rawWord2 - rawWord3;
                }
                argumentWord5 = Loading75B74Data6FBC4View2;
                if (argumentWord5 < 0x48) {
                    rawWord2 = Loading75B74Data6C60CView1;
                    rawWord3 = Loading75B74Data6C720View1;
                    rawWord2 <<= 2;
                    rawWord2 =
                        Loading75B74Field((int)&Loading75B74Data71A10View1 + rawWord2, int*, 0);
                    argumentWord4 = Loading75B74Data6C71CView1;
                    rawWord2 -= rawWord3;
                    recordOffsetOrAmount16 = argumentWord4 - rawWord2;
                } else {
                    rawWord3 = Loading75B74Data6C6F8View1;
                    argumentWord4 = rawWord3 + 1;
                    if (rawWord3 < 16) {
                        argumentWord4 += rawWord3;
                    }
                    if (argumentWord4 >= 33) {
                        argumentWord4 = 32;
                        MATCHING_KEEP(argumentWord4);
                    }
                    rawWord2 = argumentWord4 + 72;
                    argumentWord5 = rawWord2 - argumentWord5;
                    if (argumentWord5 < 0) {
                        argumentWord5 = 0;
                    }
                    rawWord2 = argumentWord4 < argumentWord5;
                    if (rawWord2 != 0) {
                        argumentWord5 = argumentWord4;
                    }
                    rawWord2 = Loading75B74CompleteProductLow(
                        (Loading75B74Field((int)&Loading75B74Data71A10View1 +
                                               (Loading75B74Data6C60CView1 * 4),
                                           int*, 0) -
                         Loading75B74Data6C720View1),
                        argumentWord5);
                    MATCHING_KEEP(rawWord2);
                    rawWord3 = rawWord2 / argumentWord4;
                    MATCHING_KEEP(rawWord3);
                    rawWord2 = Loading75B74Data6C71CView1;
                    recordOffsetOrAmount16 = rawWord2 - rawWord3;
                }
                if (recordOffsetOrAmount16 < 0) {
                    recordOffsetOrAmount16 = 0;
                }
                Loading75B74EmitUiTextGlyphPacketsView1(
                    Loading75B74Field((int)&Loading75B74Data69DCCView1 +
                                          (Loading75B74Data6C76CView1 * 4),
                                      int*, 0),
                    0xDC, byteCursorRowOrSavedWord17, 1, 0);
                Loading75B74DrawNumericCounterTextView1(recordOffsetOrAmount16, -0x8C,
                                                        byteCursorRowOrSavedWord17, 1);
                Loading75B74FillWordRangeView1(Loading75B74Data6C604View1, 0, 0x58);
                rawWord3 = Loading75B74Data6C604View1;
                rawWord2 = 0xB4;
                Loading75B74Field(rawWord3, int*, 12) = rawWord2;
                rawWord2 = byteCursorRowOrSavedWord17 + 14;
                Loading75B74Field(rawWord3, int*, 16) = rawWord2;
                rawWord2 = 3072;
                Loading75B74Field(rawWord3, int*, 20) = rawWord2;
                Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x46) =
                    (unsigned char)(Loading75B74Data6FBC4View2 * 4);
                Loading75B74Field(Loading75B74Data6C604View1, short*, 0x36) = 1;
                Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x47) = 0x3F;
                Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x54) = 2;
                Loading75B74Field(Loading75B74Data6C604View1, unsigned char*, 0x4C) = 0xFF;
                Loading75B74Field(Loading75B74Data6C604View1, signed char*, 0x4E) = 0x40;
                rawWord3 = Loading75B74Data6C604View1;
                Loading75B74Data6C604View1 = rawWord3 + 0x58;
                Loading75B74Field(rawWord3, unsigned char*, 0xA0) = 255;
            }
            goto renderOriginalCommonRecords;
        case 4:
            rawWord3 = (int)Loading75B74Data722D0View1;
            rawWord2 = rawWord3 + 0x36000;
            Loading75B74Data6C550View1 = rawWord2;
            Loading75B74Data6C604View1 = rawWord2;
            Loading75B74Field(rawWord3, unsigned char*, 0x36048) = 0xFF;
            rawWord3 = Loading75B74Data6FBC4View2;
            MATCHING_KEEP(rawWord3);
            if ((unsigned int)(rawWord3 - 0x14) < 0x5DU) {
                recordOffsetOrAmount16 = 0x18;
                if (rawWord3 < 0x20) {
                    rawWord2 = Loading75B74Field((int)&Loading75B74Data67510View1 + rawWord3,
                                                 unsigned char*, 0);
                    recordOffsetOrAmount16 = rawWord2 - 16;
                } else if (rawWord3 >= 0x64) {
                    rawWord2 = Loading75B74Field((int)&Loading75B74Data674D8View1 + rawWord3,
                                                 unsigned char*, 0);
                    recordOffsetOrAmount16 = rawWord2 - 16;
                }
                argumentWord4 = (int)originalTextBuffer;
                if (Loading75B74Data6C508View1 != 0) {
                    rawWord3 = Loading75B74Data6C76CView1;
                    MATCHING_KEEP_CLOBBER(rawWord3, "memory");
                    argumentWord5 = (int)&Loading75B74Data69CF8View1;
                    MATCHING_KEEP(argumentWord5);
                    rawWord2 = rawWord3 << 2;
                    argumentWord6 =
                        Loading75B74Field((int)&Loading75B74Data69DD0View1 + rawWord2, int*, 0);
                    rawWord2 += rawWord3;
                    goto formatOriginalSharedText;
                }
                rawWord3 = Loading75B74Data6C76CView1;
                MATCHING_KEEP_CLOBBER(rawWord3, "memory");
                argumentWord5 = (int)&Loading75B74Data69CF8View1;
                MATCHING_KEEP(argumentWord5);
                rawWord2 = rawWord3 << 2;
                argumentWord6 =
                    Loading75B74Field((int)&Loading75B74Data69DD4View1 + rawWord2, int*, 0);
                rawWord2 += rawWord3;
            formatOriginalSharedText:
                rawWord2 <<= 5;
                rawWord3 = Loading75B74Data6C58CView1;
                rawWord2 += argumentWord5;
                rawWord3 <<= 2;
                rawWord3 += rawWord2;
                MATCHING_KEEP(rawWord3);
                argumentWord7 = Loading75B74Field(rawWord3, int*, 0);
                argumentWord5 = (int)&Loading75B74Data74504View1;
                Loading75B74CallsprintfView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
                Loading75B74CallDrawStringCenteredView1(originalTextBuffer, 0x10A,
                                                        recordOffsetOrAmount16, 1);
            }
            goto renderOriginalCommonRecords;
        default:
            break;
    }
    goto finishOriginalInvocation;
renderOriginalCommonRecords:
    recordOffsetOrAmount16 = (int)&Loading75B74Data6D058View1;
    MATCHING_KEEP(recordOffsetOrAmount16);
    byteCursorRowOrSavedWord17 = Loading75B74Field(recordOffsetOrAmount16, int*, 0);
    Loading75B74Field(recordOffsetOrAmount16, int*, 0) = 0;
    Loading75B74EmitVisibleWorldTrianglePacketsView1();
    argumentWord5 = 0;
    argumentWord4 = Loading75B74Data6C668View1;
    argumentWord6 = 3072;
    argumentWord4 -= 12288;
    MATCHING_KEEP(argumentWord4);
    Loading75B74Field(recordOffsetOrAmount16, int*, 0) = byteCursorRowOrSavedWord17;
    Loading75B74FillWordRangeUnrolled4View1(argumentWord4, argumentWord5, argumentWord6);
    Loading75B74BuildMobyRenderListsView1();
    Loading75B74EmitVisibleRecordPacketsView1();
queueOriginalCommonDraw:
    Loading75B74EmitPlayerModelPacketsView1();
    argumentWord5 = Loading75B74Data6C598View1;
    argumentWord4 = 2;
    if (argumentWord5 != 0) {
        argumentWord6 = argumentWord5;
        argumentWord7 = argumentWord5;
    drawOriginalFade:
        Loading75B74EmitScreenColorQuadView1(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
    }
finishOriginalInvocation:
    Loading75B74Call75114View1(0xAE);
}
#undef Loading75B74Field
#undef Loading75B74CompleteProductLow

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80076538.
* Assembly SHA256 817cda4f024cadaaef277afa34474a3c15137d05c606ee80839d20522ce3c516.
* AI generated; not human reviewed. All620 original instructions and
* actual branch/call/internal targets are required; no owned selector/data
* table. Frame48 retains SP10..2F local extent and all six original
* S0/S1/S2/S3/S4/RA saves/restores. Only original vector words are read.
* This uses the separately matched80078678 record loop as its baseline,
* with the original single archive import/S1 relocation cursor,mode17,
* helper80075360 and final scan/vector chain. Successful scan branch at
* 80076E08 returns to the original physical join80076D08; every actual
* destination is checked. The final byte selector/record stride44,word
* differences,raw masks,vector words and halfword store remain exact.
* Full rand results and ordinary signed divide3/remainder160 remain C.
* Empty initialized dependencies/dead-register clobbers emit no CPU
* instructions. No partial HI, FP shortcut or opcode assembly is used.
* Raw units/fixed point, complete helper contracts, caller cadence and
* synchronized retail runtime remain unresolved. Cadence here is per
* invocation; confidence is binary identity after every acceptance gate.
* Falsification: every native/linked word and actual target, full EXE and
* every overlay retail hash must remain identical. */
int LoadingPlanarHeadingLookupView1() __asm__("func_8004E880");
int LoadingInterpolateSineView1() __asm__("func_8004E9E4");
int LoadingInterpolateCosineView1() __asm__("func_8004EA2C");
unsigned char LoadingAddVectorView1() __asm__("func_8004F194");
unsigned char LoadingExpandUnsignedHalfwordVectorTimes4View1() __asm__("func_8004F52C");
extern unsigned char LoadingData67014View1 __asm__("D_80067014");
extern unsigned char LoadingData6703CView1 __asm__("D_8006703C");
extern unsigned char LoadingData67064View1 __asm__("D_80067064");
extern void* LoadingData6C530View1 __asm__("D_8006C530");
extern int LoadingData6C5E0View1 __asm__("D_8006C5E0");
extern short LoadingData72304View1 __asm__("D_80072304");
#define LoadingField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char LoadingCallCDLoadAsyncView1() __asm__("CDLoadAsync");
int LoadingCallCDLoadTimeView1() __asm__("CDLoadTime");
int LoadingCallPlaySoundView1() __asm__("PlaySound");
unsigned char LoadingClearTwoDisplayRegionsView1() __asm__("func_8001EBAC");
unsigned char LoadingRelocateAndPublishModelView1() __asm__("func_8002AF9C");
unsigned char LoadingServiceLevelResourceLoadingView1() __asm__("func_8002CA50");
unsigned char LoadingSetSoundHandleWord0CAndFlag10View1() __asm__("func_8003C140");
unsigned char LoadingUpdatePlayerAnimationSubstepsView1() __asm__("func_80044240");
unsigned char LoadingResetPlayerRuntimeStateView1() __asm__("func_80047190");
int LoadingPullPlayerPoseTowardTargetView1() __asm__("func_80048444");
unsigned char LoadingDispatchPlayerStateRequestView1() __asm__("func_8004BEF8");
unsigned char LoadingCall75360View1() __asm__("func_loading_80075360");
int LoadingCallrandView1() __asm__("rand");
extern unsigned char LoadingData6668CView1 __asm__("D_8006668C");
extern unsigned char LoadingData66FCCView1 __asm__("D_80066FCC");
extern int LoadingData6C508View1 __asm__("D_8006C508");
extern int LoadingData6C518View1 __asm__("D_8006C518");
extern int LoadingData6C58CView1 __asm__("D_8006C58C");
extern int LoadingData6C598View1 __asm__("D_8006C598");
extern int LoadingData6C5BCView1 __asm__("D_8006C5BC");
extern int LoadingData6C60CView1 __asm__("D_8006C60C");
extern int LoadingData6C6F8View1 __asm__("D_8006C6F8");
extern int LoadingData6C718View1 __asm__("D_8006C718");
extern unsigned char* LoadingData6C764View1 __asm__("D_8006C764");
extern int LoadingData6C7C8View1 __asm__("D_8006C7C8");
extern unsigned char LoadingData6D8D8View1 __asm__("D_8006D8D8");
extern int LoadingData6E038View1 __asm__("D_8006E038");
extern int LoadingData6E334View1 __asm__("D_8006E334");
extern void** LoadingData6E338View1 __asm__("D_8006E338");
extern unsigned char LoadingData6E33CView1 __asm__("D_8006E33C");
extern unsigned char LoadingData6E33DView1 __asm__("D_8006E33D");
extern unsigned char LoadingData6E33EView1 __asm__("D_8006E33E");
extern int LoadingData6E470View1 __asm__("D_8006E470");
extern unsigned char LoadingData6E988View1 __asm__("D_8006E988");
extern int LoadingData6FBC4View1 __asm__("D_8006FBC4");
extern int LoadingData6FBC8View1 __asm__("D_8006FBC8");
extern int LoadingData6FBD0View1 __asm__("D_8006FBD0");
extern unsigned char LoadingData6FC15View1 __asm__("D_8006FC15");
extern unsigned char LoadingData6FC16View1 __asm__("D_8006FC16");
extern unsigned char LoadingData6FC17View1 __asm__("D_8006FC17");
extern unsigned char LoadingData6FC89View1 __asm__("D_8006FC89");
extern unsigned char LoadingData6FC8AView1 __asm__("D_8006FC8A");
extern unsigned char LoadingData6FC8BView1 __asm__("D_8006FC8B");
extern unsigned char LoadingData70328View1 __asm__("D_80070328");
extern void* LoadingData722D0View1 __asm__("D_800722D0");
extern int LoadingData722ECView1 __asm__("D_800722EC");
extern int LoadingData722F0View1 __asm__("D_800722F0");
extern int LoadingData722F8View1 __asm__("D_800722F8");
extern int LoadingData722FCView1 __asm__("D_800722FC");
extern int LoadingData72328View1 __asm__("D_80072328");
extern int LoadingData7232CView1 __asm__("D_8007232C");
void func_loading_80076538(void) {
    register int baseIndexOrAngle16 __asm__("$16");
    register int timerOffsetOrCursor17 __asm__("$17");
    register int stepOrSelectedRecord18 __asm__("$18");
    register int recordThreshold19 __asm__("$19");
    register int retainedOne20 __asm__("$20");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    int temporaryWord4;
    void* temporaryPointer1;
    void* temporaryPointer2;
    void* temporaryPointer3;
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C;
    } originalFrame;
    argumentWord5 = (int)&LoadingData6FBC8View1;
    MATCHING_KEEP(argumentWord5);
    rawWord3 = LoadingField(argumentWord5, int*, 0);
    __asm__ __volatile__("" ::: "$4", "memory");
    argumentWord4 = 2;
    if (rawWord3 == argumentWord4)
        goto loadingState2;
    rawWord2 = rawWord3 < 3;
    if (rawWord2) {
        rawWord2 = 1;
        if (rawWord3 == rawWord2)
            goto loadingState1;
        return;
    }
    rawWord2 = 3;
    if (rawWord3 == rawWord2)
        goto loadingState3;
    rawWord2 = 4;
    if (rawWord3 == rawWord2)
        goto loadingState4;
    return;
    {
    loadingState1:
        if (LoadingData6C518View1 < 2) {
            LoadingServiceLevelResourceLoadingView1(argumentWord4, argumentWord5);
            return;
        }
        LoadingField(argumentWord5, int*, 0) = argumentWord4;
        return;
    loadingState2:
        if (LoadingData7232CView1 == 0) {
            if (LoadingData6C508View1 != 0) {
                temporaryWord4 = LoadingData6C7C8View1;
            } else {
                temporaryWord4 = LoadingData6C5BCView1;
            }
            LoadingCallCDLoadAsyncView1(
                LoadingData6E470View1, LoadingData722D0View1 + 0x2A000, 0xC000,
                LoadingField(&LoadingData6D8D8View1, int*, 0x300) +
                    (LoadingField(
                         &LoadingData6668CView1, unsigned char*,
                         LoadingField(&LoadingData66FCCView1, unsigned char*, temporaryWord4)) *
                     0xC000));
            LoadingData7232CView1 = 1;
        }
        timerOffsetOrCursor17 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(timerOffsetOrCursor17);
        rawWord2 = LoadingField(timerOffsetOrCursor17, int*, 0);
        rawWord3 = LoadingData6FBD0View1;
        argumentWord4 = rawWord2 + 1;
        LoadingField(timerOffsetOrCursor17, int*, 0) = argumentWord4;
        if (!rawWord3) {
            rawWord2 = argumentWord4 < 16;
            MATCHING_KEEP(rawWord2);
            if (!rawWord2)
                goto clearPendingColorBytes;
            baseIndexOrAngle16 = (int)&LoadingData722ECView1;
            MATCHING_KEEP(baseIndexOrAngle16);
            if (LoadingPullPlayerPoseTowardTargetView1(baseIndexOrAngle16) < 1024) {
                rawWord2 = LoadingField(baseIndexOrAngle16, int*, 0);
                argumentWord4 = LoadingData722F8View1;
                rawWord3 = LoadingData722F0View1;
                argumentWord5 = LoadingData722FCView1;
                rawWord2 += argumentWord4;
                rawWord3 += argumentWord5;
                LoadingField(baseIndexOrAngle16, int*, 0) = rawWord2;
                LoadingData722F0View1 = rawWord3;
            }
            LoadingUpdatePlayerAnimationSubstepsView1();
            rawWord2 = LoadingField(timerOffsetOrCursor17, int*, 0);
            LoadingData6C598View1 = rawWord2 * 16;
            return;
        }
    clearPendingColorBytes:
        LoadingData6FC15View1 = 0;
        LoadingData6FC16View1 = 0;
        LoadingData6FC17View1 = 0;
        LoadingData6FC89View1 = 0;
        LoadingData6FC8AView1 = 0;
        LoadingData6FC8BView1 = 0;
        if ((LoadingData7232CView1 != 0) && (LoadingCallCDLoadTimeView1() == 0)) {
            rawWord2 = 0x2A000;
            baseIndexOrAngle16 = (int)LoadingData722D0View1;
            argumentWord5 = 1;
            timerOffsetOrCursor17 = baseIndexOrAngle16 + rawWord2;
            argumentWord4 = LoadingField(timerOffsetOrCursor17, int*, 0);
            argumentWord6 = 0x80800000;
            argumentWord4 += rawWord2;
            argumentWord4 = baseIndexOrAngle16 + argumentWord4;
            LoadingRelocateAndPublishModelView1(argumentWord4 + 20, argumentWord5, argumentWord6);
            rawWord2 = LoadingField(baseIndexOrAngle16, int*, 0x2A010);
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = (int)&LoadingData6E33CView1;
            MATCHING_KEEP(argumentWord5);
            timerOffsetOrCursor17 += rawWord2;
            rawWord2 = LoadingField(timerOffsetOrCursor17, unsigned char*, 0);
            LoadingField(argumentWord5, unsigned char*, 0) = rawWord2;
            rawWord2 = LoadingField(timerOffsetOrCursor17, unsigned char*, 1);
            argumentWord4 = timerOffsetOrCursor17;
            LoadingData6E33DView1 = rawWord2;
            rawWord2 = LoadingField(timerOffsetOrCursor17, unsigned char*, 2);
            MATCHING_KEEP(timerOffsetOrCursor17);
            timerOffsetOrCursor17 += 4;
            LoadingData6E33EView1 = rawWord2;
            rawWord2 = LoadingField(timerOffsetOrCursor17, int*, 0);
            timerOffsetOrCursor17 += 4;
            LoadingData6E338View1 = (void**)timerOffsetOrCursor17;
            LoadingData6E334View1 = rawWord2;
            __asm__ __volatile__("" ::: "$3", "memory");
            rawWord3 = 0;
            if (rawWord2 > 0) {
                __asm__ __volatile__(""
                                     : "=r"(argumentWord5)
                                     : "0"(argumentWord5), "i"(0x800767E8)
                                     : "memory");
                argumentWord5 -= 8;
                do {
                    rawWord2 = LoadingField(timerOffsetOrCursor17, int*, 0);
                    rawWord3++;
                    rawWord2 = argumentWord4 + rawWord2;
                    LoadingField(timerOffsetOrCursor17, int*, 0) = rawWord2;
                    rawWord2 = LoadingField(argumentWord5, int*, 0);
                    timerOffsetOrCursor17 += 4;
                } while (rawWord3 < rawWord2);
            }
            LoadingData6C718View1 = 1;
            LoadingData6E038View1 = 0;
            LoadingData6FBC8View1 = 3;
            LoadingData6FBC4View1 = 0;
            LoadingData6FC15View1 = LoadingData6E33CView1;
            LoadingData6FC16View1 = LoadingData6E33DView1;
            LoadingData6FC17View1 = LoadingData6E33EView1;
            LoadingData6FC89View1 = LoadingData6E33CView1;
            LoadingData6FC8AView1 = LoadingData6E33DView1;
            LoadingData6FC8BView1 = LoadingData6E33EView1;
            LoadingData6C5BCView1 = LoadingData6C7C8View1;
            LoadingData6C60CView1 = LoadingData6C58CView1;
            return;
        }
        return;
    loadingState3:
        if (LoadingData6C518View1 < 8) {
            LoadingServiceLevelResourceLoadingView1();
        }
        if (LoadingData6FBC4View1 == 0) {
            LoadingResetPlayerRuntimeStateView1();
            LoadingField(&LoadingData70328View1, int*, 0) = 0x2000;
            LoadingField(&LoadingData70328View1, int*, 4) = 0x2000;
            LoadingField(&LoadingData70328View1, int*, 8) = 0x2000;
            LoadingField(&LoadingData70328View1, signed char*, 0x1E) = 0;
            LoadingDispatchPlayerStateRequestView1(17);
            LoadingField(&LoadingData70328View1, signed char*, 0xC) = 0;
            LoadingField(&LoadingData70328View1, signed char*, 0xD) = 0;
            LoadingField(&LoadingData70328View1, signed char*, 0xE) = 0;
            LoadingData72328View1 = LoadingCallrandView1() & 1;
        }
        LoadingUpdatePlayerAnimationSubstepsView1();
        if ((unsigned int)(LoadingData6FBC4View1 - 0x20) < 0x49U) {
            if (LoadingData6FBC4View1 == 0x20) {
                LoadingData6C764View1 = &LoadingData6E988View1;
                baseIndexOrAngle16 = 0;
                MATCHING_KEEP(baseIndexOrAngle16);
                do {
                    rawWord2 = baseIndexOrAngle16 * 8;
                    rawWord3 = (int)LoadingData6C764View1;
                    baseIndexOrAngle16++;
                    rawWord2 += rawWord3;
                    LoadingField(rawWord2, unsigned char*, 4) = 0;
                    rawWord2 = baseIndexOrAngle16 < 32;
                    MATCHING_KEEP(rawWord2);
                } while (rawWord2);
            }
            stepOrSelectedRecord18 = 3;
            if (LoadingData6C6F8View1 >= 0x10) {
                stepOrSelectedRecord18 = 1;
            }
            baseIndexOrAngle16 = 0;
            retainedOne20 = 1;
            MATCHING_KEEP(retainedOne20);
            timerOffsetOrCursor17 = 0;
            recordThreshold19 = 0x20;
            do {
                if ((baseIndexOrAngle16 < LoadingData6C6F8View1) &&
                    (LoadingData6FBC4View1 >= recordThreshold19)) {
                    rawWord2 = (int)LoadingData6C764View1;
                    rawWord3 = timerOffsetOrCursor17 + rawWord2;
                    temporaryPointer2 = (void*)rawWord3;
                    if (LoadingField(temporaryPointer2, unsigned char*, 4) == 0) {
                        if (LoadingData6FBC4View1 < 0x40) {
                            LoadingField(temporaryPointer2, unsigned char*, 4) = retainedOne20;
                            if ((stepOrSelectedRecord18 != retainedOne20) ||
                                (baseIndexOrAngle16 == ((baseIndexOrAngle16 / 3) * 3))) {
                                LoadingSetSoundHandleWord0CAndFlag10View1(
                                    LoadingCallPlaySoundView1(1, 0, 0), 0x800);
                            }
                            rawWord2 = (int)LoadingData6C764View1;
                            rawWord2 = timerOffsetOrCursor17 + rawWord2;
                            LoadingField(rawWord2, int*, 0) = 0;
                            if (baseIndexOrAngle16 == 0) {
                                LoadingField(LoadingData6C764View1, signed char*, 5) =
                                    LoadingCallrandView1();
                            } else {
                                rawWord2 = LoadingCallrandView1();
                                argumentWord6 = (int)LoadingData6C764View1;
                                argumentWord6 = timerOffsetOrCursor17 + argumentWord6;
                                argumentWord5 =
                                    LoadingField(argumentWord6, unsigned char*, -3) + 48;
                                LoadingField(argumentWord6, unsigned char*, 5) =
                                    argumentWord5 + (rawWord2 % 160);
                            }
                            rawWord2 = LoadingCallrandView1();
                            rawWord3 = (int)LoadingData6C764View1;
                            rawWord3 = timerOffsetOrCursor17 + rawWord3;
                            LoadingField(rawWord3, unsigned char*, 6) = rawWord2;
                            rawWord2 = LoadingCallrandView1();
                            rawWord2 &= 15;
                            rawWord3 = (int)LoadingData6C764View1;
                            rawWord2 -= 8;
                            rawWord3 = timerOffsetOrCursor17 + rawWord3;
                            LoadingField(rawWord3, unsigned char*, 7) = rawWord2;
                        }
                        if (LoadingField(timerOffsetOrCursor17 + (int)LoadingData6C764View1,
                                         unsigned char*, 4) != 0) {
                            goto advanceRecord;
                        }
                    } else {
                    advanceRecord:
                        argumentWord4 = (int)LoadingData6C764View1;
                        argumentWord4 = timerOffsetOrCursor17 + argumentWord4;
                        temporaryPointer1 = (void*)argumentWord4;
                        LoadingField(temporaryPointer1, unsigned char*, 6) =
                            (unsigned char)(LoadingField(temporaryPointer1, unsigned char*, 6) +
                                            LoadingField(temporaryPointer1, unsigned char*, 7));
                        rawWord3 = (int)LoadingData6C764View1;
                        rawWord3 = timerOffsetOrCursor17 + rawWord3;
                        temporaryPointer3 = (void*)rawWord3;
                        LoadingField(temporaryPointer1, int*, 0) =
                            (int)(LoadingField(temporaryPointer1, int*, 0) + 1);
                        if ((LoadingField(temporaryPointer3, int*, 0) >= 0x28) &&
                            ((LoadingField(temporaryPointer3, signed char*, 4) = 0,
                              (stepOrSelectedRecord18 != retainedOne20)) ||
                             (baseIndexOrAngle16 == ((baseIndexOrAngle16 / 3) * 3)))) {
                            LoadingSetSoundHandleWord0CAndFlag10View1(
                                LoadingCallPlaySoundView1(0, 0, 0), 0x800);
                        }
                    }
                }
                timerOffsetOrCursor17 += 8;
                baseIndexOrAngle16 += 1;
                recordThreshold19 += stepOrSelectedRecord18;
            } while (baseIndexOrAngle16 < 0x18);
        }
        LoadingCall75360View1();
        rawWord2 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(rawWord2);
        argumentWord4 = LoadingField(rawWord2, int*, 0);
        rawWord3 = argumentWord4 + 1;
        LoadingField(rawWord2, int*, 0) = rawWord3;
        rawWord2 = rawWord3 < 9;
        MATCHING_KEEP(rawWord2);
        if (rawWord2) {
            rawWord2 = 8;
            rawWord2 -= rawWord3;
            goto storeState3TimerValue;
        }
        rawWord2 = rawWord3 < 133;
        if (rawWord2)
            goto afterState3Timer;
        rawWord2 = argumentWord4 - 131;
    storeState3TimerValue:
        rawWord2 <<= 5;
        LoadingData6C598View1 = rawWord2;
    afterState3Timer:;
        argumentWord4 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(argumentWord4);
        rawWord3 = LoadingField(argumentWord4, int*, 0);
        if (rawWord3 == 140) {
            rawWord2 = 4;
            LoadingData6FBC8View1 = rawWord2;
            rawWord2 = 255;
            LoadingField(argumentWord4, int*, 0) = 0;
            LoadingData6C598View1 = rawWord2;
            return;
        }
        return;
    loadingState4:
        if (LoadingData6C518View1 < 8) {
            LoadingServiceLevelResourceLoadingView1();
        }
        if (LoadingData6FBC4View1 == 0) {
            LoadingData72328View1 = (LoadingCallrandView1() & 1) + 2;
        }
        LoadingUpdatePlayerAnimationSubstepsView1();
        LoadingCall75360View1();
        argumentWord4 = LoadingData6FBC4View1;
        rawWord3 = argumentWord4 + 1;
        rawWord2 = rawWord3 < 9;
        LoadingData6FBC4View1 = rawWord3;
        MATCHING_KEEP(rawWord2);
        if (!rawWord2)
            goto checkState4LateTimer;
        rawWord2 = 8;
        rawWord2 -= rawWord3;
        goto storeState4TimerValue;
    retainSelectedRecord:
        stepOrSelectedRecord18 = rawWord3;
        goto prepareFinalVector;
    checkState4LateTimer:
        rawWord2 = rawWord3 < 112;
        if (rawWord2)
            goto afterState4Timer;
        rawWord2 = argumentWord4 - 111;
    storeState4TimerValue:
        rawWord2 <<= 5;
        LoadingData6C598View1 = rawWord2;
    afterState4Timer:;
        if (LoadingData6C598View1 >= 0x100) {
            LoadingData6C598View1 = 0xFF;
        }
        baseIndexOrAngle16 = (int)&LoadingData6FBC4View1;
        MATCHING_KEEP(baseIndexOrAngle16);
        rawWord3 = LoadingField(baseIndexOrAngle16, int*, 0);
        if (rawWord3 == 120) {
            LoadingClearTwoDisplayRegionsView1();
            rawWord2 = 5;
            LoadingData6FBC8View1 = rawWord2;
            rawWord2 = LoadingData6C518View1;
            rawWord3 = 1;
            LoadingField(baseIndexOrAngle16, int*, 0) = 0;
            LoadingData6C718View1 = rawWord3;
            if (rawWord2 < 8) {
                do {
                    LoadingServiceLevelResourceLoadingView1();
                } while (LoadingData6C518View1 < 8);
            }
            rawWord2 = LoadingData6C508View1;
            argumentWord4 = 0;
            if (!rawWord2)
                return;
            rawWord2 = LoadingData6C5E0View1;
            stepOrSelectedRecord18 = 0;
            if (rawWord2 > 0) {
                argumentWord6 = rawWord2;
                rawWord2 = LoadingData6C60CView1;
                rawWord3 = (int)LoadingData6C530View1;
                argumentWord5 = LoadingField(&LoadingData67014View1, unsigned char*, rawWord2);
            scanNextRecord:
                rawWord2 = LoadingField(rawWord3, unsigned char*, 0x42);
                if (rawWord2 == argumentWord5)
                    goto retainSelectedRecord;
                argumentWord4++;
                rawWord2 = argumentWord4 < argumentWord6;
                rawWord3 += 68;
                if (rawWord2)
                    goto scanNextRecord;
            }
        prepareFinalVector:
            argumentWord6 = 1;
            rawWord3 = LoadingField(stepOrSelectedRecord18, int*, 0x30);
            argumentWord4 = LoadingField(stepOrSelectedRecord18, int*, 0);
            rawWord2 = LoadingField(stepOrSelectedRecord18, int*, 0x34);
            argumentWord5 = LoadingField(stepOrSelectedRecord18, int*, 4);
            argumentWord4 = rawWord3 - argumentWord4;
            rawWord2 = LoadingPlanarHeadingLookupView1(argumentWord4, rawWord2 - argumentWord5,
                                                       argumentWord6);
            baseIndexOrAngle16 = rawWord2 + 0x400;
            baseIndexOrAngle16 &= 0xFFF;
            rawWord2 = LoadingInterpolateCosineView1(baseIndexOrAngle16);
            argumentWord4 = baseIndexOrAngle16;
            rawWord2 >>= 1;
            originalFrame.sp10 = rawWord2;
            rawWord2 = LoadingInterpolateSineView1(argumentWord4);
            timerOffsetOrCursor17 = (int)&LoadingData722ECView1;
            MATCHING_KEEP(timerOffsetOrCursor17);
            argumentWord4 = timerOffsetOrCursor17;
            argumentWord5 = stepOrSelectedRecord18 + 24;
            argumentWord6 = (int)&originalFrame.sp10;
            MATCHING_KEEP(argumentWord6);
            rawWord2 >>= 1;
            originalFrame.sp14 = rawWord2;
            rawWord2 = -0x480;
            originalFrame.sp18 = rawWord2;
            LoadingAddVectorView1(argumentWord4, argumentWord5, argumentWord6);
            baseIndexOrAngle16 += 0x800;
            baseIndexOrAngle16 &= 0xFFF;
            rawWord2 = LoadingData6C60CView1;
            argumentWord4 = timerOffsetOrCursor17 + 12;
            LoadingData72304View1 = baseIndexOrAngle16;
            argumentWord5 = LoadingField(&LoadingData6703CView1, unsigned char*, rawWord2);
            rawWord2 = (int)&LoadingData67064View1;
            MATCHING_KEEP(rawWord2);
            argumentWord5 *= 8;
            LoadingExpandUnsignedHalfwordVectorTimes4View1(argumentWord4, argumentWord5 + rawWord2);
        }
        return;
    }
}
#undef LoadingField


INCLUDE_RODATA("asm/nonmatchings/overlays/loading/loading2", D_loading_80074504);
