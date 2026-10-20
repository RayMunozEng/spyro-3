#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800881FC.
 * Assembly SHA256 eddbd96802c249beb9aa620d5e47f2964a150c8daa35e7c1a0b1b83386946128.
 * AI-generated; not human reviewed. All1386 original instructions,
 * 26 selectors bias19 and 0 owned padding words are required.
 * Original frame0xC0; every concrete field width and producer is retained.
 * Five exact groups reuse11/33. Last43 falls straight to the epilogue.
 * Original A0 selector setup,slotS2,savedS0..S4 and scratch10..A4 remain exact.
 * Original33 omits C7C4 modifier rows,matching newly verified level33 C.
 * All original scalar/vector/water/particle fields and actual joins remain.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics10Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics10Call363DCView5() __asm__("func_800363DC");
unsigned char Physics10Call40D10View6() __asm__("func_80040D10");
unsigned char Physics10Call41580View6() __asm__("func_80041580");
unsigned char Physics10Call416F4View6() __asm__("func_800416F4");
unsigned char Physics10Call417FCView6() __asm__("func_800417FC");
unsigned char Physics10Call41B64View6() __asm__("func_80041B64");
int Physics10Call4E9E4View6() __asm__("func_8004E9E4");
int Physics10Call4EA2CView6() __asm__("func_8004EA2C");
unsigned char Physics10Call4ED6CView5() __asm__("func_8004ED6C");
int Physics10Call4EDE8View6() __asm__("func_8004EDE8");
unsigned char Physics10Call4F08CView6() __asm__("func_8004F08C");
unsigned char Physics10Call4F110View4() __asm__("func_8004F110");
unsigned char Physics10Call4F168View6() __asm__("func_8004F168");
unsigned char Physics10Call4F178View6() __asm__("func_8004F178");
unsigned char Physics10Call4F194View6() __asm__("func_8004F194");
unsigned char Physics10Call4F1C8View6() __asm__("func_8004F1C8");
int Physics10CallRandView5() __asm__("rand");
extern unsigned char Physics10Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View6 __asm__("D_80065920");
extern void *Physics10Data6C570View5 __asm__("D_8006C570");
extern int Physics10Data6C640View6 __asm__("D_8006C640");
extern int Physics10Data6E044View6 __asm__("D_8006E044");
extern unsigned char Physics10Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics10Player0View6 __asm__("D_80070328");
extern int Physics10Player94View4 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics10Call40D10View7() __asm__("func_80040D10");
int Physics10Call40F48View4() __asm__("func_80040F48");
int Physics10Call410F8View4() __asm__("func_800410F8");
int Physics10Call41404View3() __asm__("func_80041404");
int Physics10Call41580View7() __asm__("func_80041580");
int Physics10Call416F4View7() __asm__("func_800416F4");
int Physics10Call417FCView7() __asm__("func_800417FC");
int Physics10Call41848View5() __asm__("func_80041848");
int Physics10Call41B64View7() __asm__("func_80041B64");
int Physics10Call4E9E4View7() __asm__("func_8004E9E4");
int Physics10Call4EA2CView7() __asm__("func_8004EA2C");
int Physics10Call4EDE8View7() __asm__("func_8004EDE8");
int Physics10Call4F08CView7() __asm__("func_8004F08C");
int Physics10Call4F168View7() __asm__("func_8004F168");
int Physics10Call4F178View7() __asm__("func_8004F178");
int Physics10Call4F194View7() __asm__("func_8004F194");
int Physics10Call4F1C8View7() __asm__("func_8004F1C8");
int Physics10Call4F284View3() __asm__("func_8004F284");
extern unsigned char Physics10Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View7 __asm__("D_80065920");
extern int Physics10Data6763CView3 __asm__("D_8006763C");
extern int Physics10Data67640View3 __asm__("D_80067640");
extern int Physics10Data67644View3 __asm__("D_80067644");
extern unsigned char Physics10Data676E8View3 __asm__("D_800676E8");
extern int* Physics10Data6C570View6 __asm__("D_8006C570");
extern int Physics10Data6C58CView3 __asm__("D_8006C58C");
extern int Physics10Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics10Data6C640View7 __asm__("D_8006C640");
extern short Physics10Data6E040View3 __asm__("D_8006E040");
extern int Physics10Data6E044View7 __asm__("D_8006E044");
extern int Physics10Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics10Player0View7 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics10Player94View5 __asm__("D_80070328+0x94");
extern int Physics10PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics10Player80View2 __asm__("D_80070328+0x80");
extern int Physics10PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics10Player64View3 __asm__("D_80070328+0x64");
extern int Physics10Player88View3 __asm__("D_80070328+0x88");
extern int Physics10Player84View2 __asm__("D_80070328+0x84");
extern int Physics10Player144View3 __asm__("D_80070328+0x144");
extern int Physics10Player60View3 __asm__("D_80070328+0x60");
extern int Physics10PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics10Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics10Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics10Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics10PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics10PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics10Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics10Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics10Player20CView3 __asm__("D_80070328+0x20C");
extern unsigned char Physics10Player101View2 __asm__("D_80070328+0x101");
extern int Physics10PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics10Player210View3 __asm__("D_80070328+0x210");
extern int Physics10PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics10Player8View3 __asm__("D_80070328+0x8");
int Physics10Call363DCView6() __asm__("func_800363DC");
int Physics10Call40D10View8() __asm__("func_80040D10");
int Physics10Call40F48View5() __asm__("func_80040F48");
int Physics10Call41580View8() __asm__("func_80041580");
int Physics10Call416F4View8() __asm__("func_800416F4");
int Physics10Call417FCView8() __asm__("func_800417FC");
int Physics10Call41848View6() __asm__("func_80041848");
int Physics10Call41B64View8() __asm__("func_80041B64");
int Physics10Call43194View2() __asm__("func_80043194");
int Physics10Call4E880View3() __asm__("func_8004E880");
int Physics10Call4E9E4View8() __asm__("func_8004E9E4");
int Physics10Call4EA2CView8() __asm__("func_8004EA2C");
int Physics10Call4ED6CView6() __asm__("func_8004ED6C");
int Physics10Call4EDE8View8() __asm__("func_8004EDE8");
int Physics10Call4F08CView8() __asm__("func_8004F08C");
int Physics10Call4F168View8() __asm__("func_8004F168");
int Physics10Call4F178View8() __asm__("func_8004F178");
int Physics10Call4F194View8() __asm__("func_8004F194");
int Physics10Call4F1C8View8() __asm__("func_8004F1C8");
int Physics10Call4F284View4() __asm__("func_8004F284");
int Physics10CallRandView6() __asm__("rand");
extern unsigned char Physics10Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View8 __asm__("D_80065920");
extern unsigned char Physics10Data676E8View4 __asm__("D_800676E8");
extern int Physics10Data6C514View4 __asm__("D_8006C514");
extern int* Physics10Data6C570View7 __asm__("D_8006C570");
extern int Physics10Data6C58CView4 __asm__("D_8006C58C");
extern int Physics10Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics10Data6C640View8 __asm__("D_8006C640");
extern short Physics10Data6E040View4 __asm__("D_8006E040");
extern int Physics10Data6E044View8 __asm__("D_8006E044");
extern int Physics10Data6E344View4 __asm__("D_8006E344");
extern int Physics10Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View8 __asm__("D_8006E548");
extern unsigned char Physics10Player0View8 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10Player16CView2 __asm__("D_80070328+0x16C");
int Physics10Call13E38View2() __asm__("func_80013E38");
int Physics10Call363DCView7() __asm__("func_800363DC");
int Physics10Call40D10View9() __asm__("func_80040D10");
int Physics10Call410F8View5() __asm__("func_800410F8");
int Physics10Call41580View9() __asm__("func_80041580");
int Physics10Call416F4View9() __asm__("func_800416F4");
int Physics10Call417FCView9() __asm__("func_800417FC");
int Physics10Call41848View7() __asm__("func_80041848");
int Physics10Call41B64View9() __asm__("func_80041B64");
int Physics10Call4E4E4View2() __asm__("func_8004E4E4");
int Physics10Call4E880View4() __asm__("func_8004E880");
int Physics10Call4E9E4View9() __asm__("func_8004E9E4");
int Physics10Call4EA2CView9() __asm__("func_8004EA2C");
int Physics10Call4ED6CView7() __asm__("func_8004ED6C");
int Physics10Call4EDE8View9() __asm__("func_8004EDE8");
int Physics10Call4F08CView9() __asm__("func_8004F08C");
int Physics10Call4F0E8View2() __asm__("func_8004F0E8");
int Physics10Call4F110View5() __asm__("func_8004F110");
int Physics10Call4F168View9() __asm__("func_8004F168");
int Physics10Call4F178View9() __asm__("func_8004F178");
int Physics10Call4F194View9() __asm__("func_8004F194");
int Physics10Call4F1C8View9() __asm__("func_8004F1C8");
int Physics10CallRandView7() __asm__("rand");
extern unsigned char Physics10Data658A0View9 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View9 __asm__("D_80065920");
extern int Physics10Data67630View2 __asm__("D_80067630");
extern int Physics10Data67634View2 __asm__("D_80067634");
extern int Physics10Data67638View2 __asm__("D_80067638");
extern int Physics10Data6C514View5 __asm__("D_8006C514");
extern int Physics10Data6C640View9 __asm__("D_8006C640");
extern int Physics10Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics10Data6E044View9 __asm__("D_8006E044");
extern int Physics10Data6E344View5 __asm__("D_8006E344");
extern int Physics10Data6E538View7 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View9 __asm__("D_8006E548");
extern int Physics10Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics10Player0View9 __asm__("D_80070328");
extern int Physics10Data71908View2 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10Player130View2 __asm__("D_80070328+0x130");
extern int Physics10Player144View4 __asm__("D_80070328+0x144");
extern short Physics10Player148View3 __asm__("D_80070328+0x148");
extern short Physics10Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics10Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics10Player150View2 __asm__("D_80070328+0x150");
extern int Physics10Player154View2 __asm__("D_80070328+0x154");
extern int Physics10Player160View2 __asm__("D_80070328+0x160");
extern int Physics10Player48View2 __asm__("D_80070328+0x48");
extern int Physics10Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics10Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics10Player60View4 __asm__("D_80070328+0x60");
extern int Physics10Player64View4 __asm__("D_80070328+0x64");
extern int Physics10Player8View4 __asm__("D_80070328+0x8");
extern int Physics10Player88View4 __asm__("D_80070328+0x88");
extern int Physics10Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics10Player90View2 __asm__("D_80070328+0x90");
extern int Physics10Player94View6 __asm__("D_80070328+0x94");
extern int Physics10PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics10PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics10PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics10PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics10Player148View4 __asm__("D_80070328+0x148");
extern int Physics10Player210View4 __asm__("D_80070328+0x210");
extern int Physics10Player220View2 __asm__("D_80070328+0x220");
extern int Physics10Player98View2 __asm__("D_80070328+0x98");
extern int Physics10PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics10PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics10PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics10PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics10PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics10PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics10Call363DCView8() __asm__("func_800363DC");
int Physics10Call40D10View10() __asm__("func_80040D10");
int Physics10Call40F48View6() __asm__("func_80040F48");
int Physics10Call410F8View6() __asm__("func_800410F8");
int Physics10Call41404View4() __asm__("func_80041404");
int Physics10Call41580View10() __asm__("func_80041580");
int Physics10Call416F4View10() __asm__("func_800416F4");
int Physics10Call417FCView10() __asm__("func_800417FC");
int Physics10Call41848View8() __asm__("func_80041848");
int Physics10Call41B64View10() __asm__("func_80041B64");
int Physics10Call4E9E4View10() __asm__("func_8004E9E4");
int Physics10Call4EA2CView10() __asm__("func_8004EA2C");
int Physics10Call4ED6CView8() __asm__("func_8004ED6C");
int Physics10Call4EDE8View10() __asm__("func_8004EDE8");
int Physics10Call4F08CView10() __asm__("func_8004F08C");
int Physics10Call4F110View6() __asm__("func_8004F110");
int Physics10Call4F168View10() __asm__("func_8004F168");
int Physics10Call4F178View10() __asm__("func_8004F178");
int Physics10Call4F194View10() __asm__("func_8004F194");
int Physics10Call4F1C8View10() __asm__("func_8004F1C8");
int Physics10CallRandView8() __asm__("rand");
extern unsigned char Physics10Data658A0View10 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View10 __asm__("D_80065920");
extern int Physics10Data6763CView4 __asm__("D_8006763C");
extern int Physics10Data67640View4 __asm__("D_80067640");
extern int Physics10Data67644View4 __asm__("D_80067644");
extern int Physics10Data6C514View6 __asm__("D_8006C514");
extern int* Physics10Data6C570View8 __asm__("D_8006C570");
extern int Physics10Data6C640View10 __asm__("D_8006C640");
extern int Physics10Data6E044View10 __asm__("D_8006E044");
extern int Physics10Data6E344View6 __asm__("D_8006E344");
extern int Physics10Data6E538View8 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View10 __asm__("D_8006E548");
extern unsigned char Physics10Player0View10 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10Player8CView4 __asm__("D_80070328+0x8C");
extern int Physics10PlayerB4View2 __asm__("D_80070328+0xB4");
extern int Physics10Player158View2 __asm__("D_80070328+0x158");
extern int Physics10Player20CView4 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
int Physics10Call363DCView5() __asm__("func_800363DC");
unsigned char Physics10Call40D10View6() __asm__("func_80040D10");
unsigned char Physics10Call41580View6() __asm__("func_80041580");
unsigned char Physics10Call416F4View6() __asm__("func_800416F4");
unsigned char Physics10Call417FCView6() __asm__("func_800417FC");
unsigned char Physics10Call41B64View6() __asm__("func_80041B64");
int Physics10Call4E9E4View6() __asm__("func_8004E9E4");
int Physics10Call4EA2CView6() __asm__("func_8004EA2C");
unsigned char Physics10Call4ED6CView5() __asm__("func_8004ED6C");
int Physics10Call4EDE8View6() __asm__("func_8004EDE8");
unsigned char Physics10Call4F08CView6() __asm__("func_8004F08C");
unsigned char Physics10Call4F110View4() __asm__("func_8004F110");
unsigned char Physics10Call4F168View6() __asm__("func_8004F168");
unsigned char Physics10Call4F178View6() __asm__("func_8004F178");
unsigned char Physics10Call4F194View6() __asm__("func_8004F194");
unsigned char Physics10Call4F1C8View6() __asm__("func_8004F1C8");
int Physics10CallRandView5() __asm__("rand");
extern unsigned char Physics10Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View6 __asm__("D_80065920");
extern void *Physics10Data6C570View5 __asm__("D_8006C570");
extern int Physics10Data6C640View6 __asm__("D_8006C640");
extern int Physics10Data6E044View6 __asm__("D_8006E044");
extern unsigned char Physics10Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics10Player0View6 __asm__("D_80070328");
extern int Physics10Player94View4 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics10Call40D10View7() __asm__("func_80040D10");
int Physics10Call40F48View4() __asm__("func_80040F48");
int Physics10Call410F8View4() __asm__("func_800410F8");
int Physics10Call41404View3() __asm__("func_80041404");
int Physics10Call41580View7() __asm__("func_80041580");
int Physics10Call416F4View7() __asm__("func_800416F4");
int Physics10Call417FCView7() __asm__("func_800417FC");
int Physics10Call41848View5() __asm__("func_80041848");
int Physics10Call41B64View7() __asm__("func_80041B64");
int Physics10Call4E9E4View7() __asm__("func_8004E9E4");
int Physics10Call4EA2CView7() __asm__("func_8004EA2C");
int Physics10Call4EDE8View7() __asm__("func_8004EDE8");
int Physics10Call4F08CView7() __asm__("func_8004F08C");
int Physics10Call4F168View7() __asm__("func_8004F168");
int Physics10Call4F178View7() __asm__("func_8004F178");
int Physics10Call4F194View7() __asm__("func_8004F194");
int Physics10Call4F1C8View7() __asm__("func_8004F1C8");
int Physics10Call4F284View3() __asm__("func_8004F284");
extern unsigned char Physics10Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View7 __asm__("D_80065920");
extern int Physics10Data6763CView3 __asm__("D_8006763C");
extern int Physics10Data67640View3 __asm__("D_80067640");
extern int Physics10Data67644View3 __asm__("D_80067644");
extern unsigned char Physics10Data676E8View3 __asm__("D_800676E8");
extern int* Physics10Data6C570View6 __asm__("D_8006C570");
extern int Physics10Data6C58CView3 __asm__("D_8006C58C");
extern int Physics10Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics10Data6C640View7 __asm__("D_8006C640");
extern short Physics10Data6E040View3 __asm__("D_8006E040");
extern int Physics10Data6E044View7 __asm__("D_8006E044");
extern int Physics10Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics10Player0View7 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics10Player94View5 __asm__("D_80070328+0x94");
extern int Physics10PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics10Player80View2 __asm__("D_80070328+0x80");
extern int Physics10PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics10Player64View3 __asm__("D_80070328+0x64");
extern int Physics10Player88View3 __asm__("D_80070328+0x88");
extern int Physics10Player84View2 __asm__("D_80070328+0x84");
extern int Physics10Player144View3 __asm__("D_80070328+0x144");
extern int Physics10Player60View3 __asm__("D_80070328+0x60");
extern int Physics10PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics10Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics10Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics10Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics10PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics10PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics10Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics10Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics10Player20CView3 __asm__("D_80070328+0x20C");
extern unsigned char Physics10Player101View2 __asm__("D_80070328+0x101");
extern int Physics10PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics10Player210View3 __asm__("D_80070328+0x210");
extern int Physics10PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics10Player8View3 __asm__("D_80070328+0x8");
int Physics10Call363DCView6() __asm__("func_800363DC");
int Physics10Call40D10View8() __asm__("func_80040D10");
int Physics10Call40F48View5() __asm__("func_80040F48");
int Physics10Call41580View8() __asm__("func_80041580");
int Physics10Call416F4View8() __asm__("func_800416F4");
int Physics10Call417FCView8() __asm__("func_800417FC");
int Physics10Call41848View6() __asm__("func_80041848");
int Physics10Call41B64View8() __asm__("func_80041B64");
int Physics10Call43194View2() __asm__("func_80043194");
int Physics10Call4E880View3() __asm__("func_8004E880");
int Physics10Call4E9E4View8() __asm__("func_8004E9E4");
int Physics10Call4EA2CView8() __asm__("func_8004EA2C");
int Physics10Call4ED6CView6() __asm__("func_8004ED6C");
int Physics10Call4EDE8View8() __asm__("func_8004EDE8");
int Physics10Call4F08CView8() __asm__("func_8004F08C");
int Physics10Call4F168View8() __asm__("func_8004F168");
int Physics10Call4F178View8() __asm__("func_8004F178");
int Physics10Call4F194View8() __asm__("func_8004F194");
int Physics10Call4F1C8View8() __asm__("func_8004F1C8");
int Physics10Call4F284View4() __asm__("func_8004F284");
int Physics10CallRandView6() __asm__("rand");
extern unsigned char Physics10Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View8 __asm__("D_80065920");
extern unsigned char Physics10Data676E8View4 __asm__("D_800676E8");
extern int Physics10Data6C514View4 __asm__("D_8006C514");
extern int* Physics10Data6C570View7 __asm__("D_8006C570");
extern int Physics10Data6C58CView4 __asm__("D_8006C58C");
extern int Physics10Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics10Data6C640View8 __asm__("D_8006C640");
extern short Physics10Data6E040View4 __asm__("D_8006E040");
extern int Physics10Data6E044View8 __asm__("D_8006E044");
extern int Physics10Data6E344View4 __asm__("D_8006E344");
extern int Physics10Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View8 __asm__("D_8006E548");
extern unsigned char Physics10Player0View8 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10Player16CView2 __asm__("D_80070328+0x16C");
int Physics10Call13E38View2() __asm__("func_80013E38");
int Physics10Call363DCView7() __asm__("func_800363DC");
int Physics10Call40D10View9() __asm__("func_80040D10");
int Physics10Call410F8View5() __asm__("func_800410F8");
int Physics10Call41580View9() __asm__("func_80041580");
int Physics10Call416F4View9() __asm__("func_800416F4");
int Physics10Call417FCView9() __asm__("func_800417FC");
int Physics10Call41848View7() __asm__("func_80041848");
int Physics10Call41B64View9() __asm__("func_80041B64");
int Physics10Call4E4E4View2() __asm__("func_8004E4E4");
int Physics10Call4E880View4() __asm__("func_8004E880");
int Physics10Call4E9E4View9() __asm__("func_8004E9E4");
int Physics10Call4EA2CView9() __asm__("func_8004EA2C");
int Physics10Call4ED6CView7() __asm__("func_8004ED6C");
int Physics10Call4EDE8View9() __asm__("func_8004EDE8");
int Physics10Call4F08CView9() __asm__("func_8004F08C");
int Physics10Call4F0E8View2() __asm__("func_8004F0E8");
int Physics10Call4F110View5() __asm__("func_8004F110");
int Physics10Call4F168View9() __asm__("func_8004F168");
int Physics10Call4F178View9() __asm__("func_8004F178");
int Physics10Call4F194View9() __asm__("func_8004F194");
int Physics10Call4F1C8View9() __asm__("func_8004F1C8");
int Physics10CallRandView7() __asm__("rand");
extern unsigned char Physics10Data658A0View9 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View9 __asm__("D_80065920");
extern int Physics10Data67630View2 __asm__("D_80067630");
extern int Physics10Data67634View2 __asm__("D_80067634");
extern int Physics10Data67638View2 __asm__("D_80067638");
extern int Physics10Data6C514View5 __asm__("D_8006C514");
extern int Physics10Data6C640View9 __asm__("D_8006C640");
extern int Physics10Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics10Data6E044View9 __asm__("D_8006E044");
extern int Physics10Data6E344View5 __asm__("D_8006E344");
extern int Physics10Data6E538View7 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View9 __asm__("D_8006E548");
extern int Physics10Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics10Player0View9 __asm__("D_80070328");
extern int Physics10Data71908View2 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10Player130View2 __asm__("D_80070328+0x130");
extern int Physics10Player144View4 __asm__("D_80070328+0x144");
extern short Physics10Player148View3 __asm__("D_80070328+0x148");
extern short Physics10Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics10Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics10Player150View2 __asm__("D_80070328+0x150");
extern int Physics10Player154View2 __asm__("D_80070328+0x154");
extern int Physics10Player160View2 __asm__("D_80070328+0x160");
extern int Physics10Player48View2 __asm__("D_80070328+0x48");
extern int Physics10Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics10Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics10Player60View4 __asm__("D_80070328+0x60");
extern int Physics10Player64View4 __asm__("D_80070328+0x64");
extern int Physics10Player8View4 __asm__("D_80070328+0x8");
extern int Physics10Player88View4 __asm__("D_80070328+0x88");
extern int Physics10Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics10Player90View2 __asm__("D_80070328+0x90");
extern int Physics10Player94View6 __asm__("D_80070328+0x94");
extern int Physics10PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics10PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics10PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics10PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics10Player148View4 __asm__("D_80070328+0x148");
extern int Physics10Player210View4 __asm__("D_80070328+0x210");
extern int Physics10Player220View2 __asm__("D_80070328+0x220");
extern int Physics10Player98View2 __asm__("D_80070328+0x98");
extern int Physics10PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics10PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics10PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics10PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics10PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics10PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics10Call363DCView8() __asm__("func_800363DC");
int Physics10Call40D10View10() __asm__("func_80040D10");
int Physics10Call40F48View6() __asm__("func_80040F48");
int Physics10Call410F8View6() __asm__("func_800410F8");
int Physics10Call41404View4() __asm__("func_80041404");
int Physics10Call41580View10() __asm__("func_80041580");
int Physics10Call416F4View10() __asm__("func_800416F4");
int Physics10Call417FCView10() __asm__("func_800417FC");
int Physics10Call41848View8() __asm__("func_80041848");
int Physics10Call41B64View10() __asm__("func_80041B64");
int Physics10Call4E9E4View10() __asm__("func_8004E9E4");
int Physics10Call4EA2CView10() __asm__("func_8004EA2C");
int Physics10Call4ED6CView8() __asm__("func_8004ED6C");
int Physics10Call4EDE8View10() __asm__("func_8004EDE8");
int Physics10Call4F08CView10() __asm__("func_8004F08C");
int Physics10Call4F110View6() __asm__("func_8004F110");
int Physics10Call4F168View10() __asm__("func_8004F168");
int Physics10Call4F178View10() __asm__("func_8004F178");
int Physics10Call4F194View10() __asm__("func_8004F194");
int Physics10Call4F1C8View10() __asm__("func_8004F1C8");
int Physics10CallRandView8() __asm__("rand");
extern unsigned char Physics10Data658A0View10 __asm__("D_800658A0");
extern unsigned char Physics10Data65920View10 __asm__("D_80065920");
extern int Physics10Data6763CView4 __asm__("D_8006763C");
extern int Physics10Data67640View4 __asm__("D_80067640");
extern int Physics10Data67644View4 __asm__("D_80067644");
extern int Physics10Data6C514View6 __asm__("D_8006C514");
extern int* Physics10Data6C570View8 __asm__("D_8006C570");
extern int Physics10Data6C640View10 __asm__("D_8006C640");
extern int Physics10Data6E044View10 __asm__("D_8006E044");
extern int Physics10Data6E344View6 __asm__("D_8006E344");
extern int Physics10Data6E538View8 __asm__("D_8006E538");
extern unsigned char Physics10Data6E548View10 __asm__("D_8006E548");
extern unsigned char Physics10Player0View10 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics10Player8CView4 __asm__("D_80070328+0x8C");
extern int Physics10PlayerB4View2 __asm__("D_80070328+0xB4");
extern int Physics10Player158View2 __asm__("D_80070328+0x158");
extern int Physics10Player20CView4 __asm__("D_80070328+0x20C");
void func_level_10_800881FC(int slotIndex) {
    register int stateSelector4 __asm__("$4");
    int agentProduct0,agentProduct1,agentProduct2,agentProduct3,agentProduct4,agentProduct5,agentProduct6,agentProduct7;
    register void *fieldA4State28 __asm__("$16");
    register void *vector8CState28 __asm__("$17");
    register int signedWord19 __asm__("$20");
    register int signedWord20 __asm__("$21");
    register int signedWord21 __asm__("$22");
    register void *savedPointer22 __asm__("$19");
    register void *savedPointer17 __asm__("$17");
    register void *(*particleCall3)() __asm__("$3");
    register int particleArg7 __asm__("$7");
    register int workWord2 __asm__("$2");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4;
    }
    originalFrame;
    register int workWord3 __asm__("$3");
    register void *globalField4CPointer __asm__("$16");
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    void *raw21_temp_s0_9;
    int raw21_temp_a0_5;
    int raw21_temp_a0_6;
    int raw21_temp_a0_7;
    int raw21_temp_a1_2;
    int raw21_temp_a1_3;
    int raw21_temp_a1_4;
    int raw21_temp_s0_10;
    register int raw21_temp_s0_8 __asm__("$16");
    int raw21_temp_s1_4;
    int raw21_temp_v1_13;
    int raw21_temp_v1_14;
    int raw21_temp_v1_6;
    int raw21_temp_v1_7;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s0_7;
    register void *raw21_temp_s1_5 __asm__("$17");
    void *raw21_temp_s1_6;
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex=slotIndex;
    workWord2=savedSlotIndex*16;
    globalPointer=&Physics10Data6E548View6;
    stateSelector4=Physics10Field(&Physics10Player0View6,int*,0x48);
    __asm__("":"=r"(globalPointer):"0"(globalPointer),"r"(stateSelector4),"r"(workWord2));
    workWord2+=(int)globalPointer;
    Physics10Data6C570View5=(void*)workWord2;
    switch(stateSelector4){
        default:return;
    case 19:{
            int product19;
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3=Physics10Data6E344View4;
            workWord2=13;
            if(workWord3==workWord2){
                workWord2=Physics10Data6C514View4;
                if(workWord2)return;
            }
            vectorAt30=&Physics10Player0View8+8;
            workWord3=Physics10Field(vectorAt30,int*,0);
            workWord2=Physics10Field(&Physics10Player0View8,int*,0x144);
            numeric4=workWord3-workWord2;
            workWord2=numeric4<1024;
            if(!workWord2)goto beyond19;
            workWord2=Physics10Player94View5;
            workWord2+=128;
            Physics10Player94View5=workWord2;
            workWord2=workWord2<4801;
            __asm__("":"=r"(numeric4):"0"(numeric4),"r"(workWord2));
            if(!workWord2){
                workWord2=4800;
                Physics10Player94View5=workWord2;
            }
            product19=numeric4*numeric4;
            call4=&originalFrame.sp10;
            workWord3=Physics10Field(&Physics10Player0View8,int*,0x148);
            __asm__ volatile(""::"r"(workWord2),"r"(workWord3),"r"(call4):"memory");
            workWord2=product19>>11;
            angle16=workWord2+workWord3;
            Physics10Player64View3=angle16;
            __asm__ volatile("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4):"memory");
            Physics10Call4F178View8(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics10Call4F1C8View8(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics10Call4EDE8View8(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x80088340):"memory");
            numeric6=1024;
            goto limit19;
            beyond19:numeric5=Physics10Field(&Physics10Player0View8,int*,0x14C);
            workWord2=workWord3-numeric5;
            workWord2=workWord2<-1024;
            numeric6=numeric5-workWord3;
            if(!workWord2)goto curve19;
            __asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x80088364));
            workWord2=Physics10Player4CView3;
            workWord3=1;
            if(!workWord2){
                workWord2=Physics10Field(&Physics10Player0View8,int*,0x148);
                Physics10Player4CView3=workWord3;
                workWord2+=512;
                Physics10Field(&Physics10Player0View8,int*,0x148)=workWord2;
            }
            workWord2=Physics10Player94View5;
            workWord2+=128;
            Physics10Player94View5=workWord2;
            workWord2=workWord2<4801;
            if(!workWord2)Physics10Player94View5=4800;
            workWord2=Physics10Field(&Physics10Player0View8,int*,0x150);
            numeric6=numeric4-1024;
            workWord3=workWord2*numeric6;
            workWord2=Physics10Field(&Physics10Player0View8,int*,0x154);
            workWord2=workWord3/workWord2;
            call4=&originalFrame.sp10;
            workWord3=Physics10Field(&Physics10Player0View8,int*,0x148);
            angle16=workWord3+workWord2;
            workWord2=(numeric6<<10)>>10;
            workWord2=angle16+workWord2;
            angle16=workWord2&4095;
            Physics10Player64View3=angle16;
            Physics10Call4F178View8(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics10Call4F1C8View8(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics10Call4EDE8View8(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x80088474):"memory");
            numeric6=1024;
            goto limit19;
            curve19:__asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x8008847C));
            workWord2=(numeric6*4800)>>10;
            Physics10Player94View5=workWord2;
            workWord2=Physics10Player16CView2;
            numeric7=Physics10Field(&Physics10Player0View8,int*,0x168);
            workWord3=Physics10Field(&Physics10Player0View8,int*,0x158);
            workWord2&=127;
            numeric4=numeric7<<1;
            Physics10Player16CView2=workWord2;
            workWord2=*(short*)(&Physics10Data65920View8+numeric4);
            workWord3+=1024;
            product10=workWord3*workWord2;
            square8=numeric6*numeric6;
            workWord2=product10>>12;
            originalFrame.sp10=workWord2;
            workWord2=*(short*)(&Physics10Data658A0View8+numeric4);
            workWord3=workWord3*workWord2;
            numeric7<<=4;
            call4=&originalFrame.sp10;
            call5=call4;
            __asm__("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4),"r"(call5));
            numeric6=(int)vectorAt30+340;
            workWord2=square8>>11;
            angle16=numeric7-workWord2;
            workWord2=workWord3>>12;
            originalFrame.sp14=workWord2;
            Physics10Call4F194View8(call4,call5,numeric6,numeric7);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics10Player64View3=angle16;
            Physics10Call4F1C8View8(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics10Call4EDE8View8(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<2049;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            numeric6=2048;
            limit19:Physics10Call4F08CView8(call4,call5,numeric6);
            commit19:workWord2=originalFrame.sp10;
            workWord3=originalFrame.sp14;
            Physics10Field(&Physics10Player0View8,int*,0x8C)=workWord2;
            Physics10Field(&Physics10Player0View8,int*,0x90)=workWord3;
            return;
        }
    case 33:case 34:case 35:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta18 __asm__("$18");
            register int delta19 __asm__("$19");
            register void *pointer17 __asm__("$17");
            register void *pointer16 __asm__("$16");
            register int limit16 __asm__("$16");
            int originalLow;
            call4=&originalFrame.sp20;
            __asm__ volatile(""::"r"(call4):"memory");
            pointer17=&Physics10Player154View2;
            Physics10Call410F8View5(call4,pointer17,0);
            workWord2=originalFrame.sp24;
            numeric4=Physics10Player94View6;
            workWord2=-workWord2;
            workWord3=workWord2*5;
            workWord3<<=2;
            delta18=workWord3>>7;
            numeric4>>=3;
            workWord3=originalFrame.sp20;
            numeric4-=1024;
            originalFrame.sp30=numeric4;
            workWord2=workWord3*5;
            workWord2<<=2;
            delta19=workWord2>>7;
            if(numeric4<0){
                pointer16=&originalFrame.sp28;
                call4=pointer16;
                call5=pointer16;
                __asm__ volatile("":"=r"(pointer17):"0"(pointer17),"r"(call4),"r"(call5):"memory");
                pointer17-=340;
                call6=pointer17;
                workWord2=Physics10Player8CView3;
                workWord3=Physics10Player90View2;
                workWord2>>=3;
                workWord3>>=3;
                originalFrame.sp28=workWord2;
                originalFrame.sp2C=workWord3;
                Physics10Call4F194View9(call4,call5,call6);
                if(!Physics10Call13E38View2(pointer17,pointer16,2)){
                    workWord2=Physics10Player8View4;
                    workWord3=Physics10Data71908View2;
                    workWord2-=workWord3;
                    workWord2>>=3;
                    originalFrame.sp24=workWord2;
                    workWord2=workWord2<11;
                    if(!workWord2)originalFrame.sp24=10;
                    __asm__ volatile("":::"memory");
                    workWord2=originalFrame.sp24;
                    delta18+=workWord2;
                }
            }
            workWord2=Physics10PlayerF8View4;
            workWord3=Physics10Player8View4;
            workWord3=workWord2-workWord3;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3<4096;
            if(workWord2){
                workWord2=workWord3*3;
                workWord2<<=3;
                workWord2+=workWord3;
                workWord2<<=5;
                workWord3=Physics10Player60View4;
                numeric4=workWord2>>12;
                workWord3=numeric4-workWord3;
                numeric4=workWord3&4095;
                workWord2=numeric4<2049;
                if(!workWord2){
                    numeric4-=4096;
                    workWord2=numeric4<delta18;
                }
                else workWord2=numeric4<delta18;
                if(workWord2)delta18=numeric4;
            }
            call4=&Physics10Player64View4;
            workWord2=Physics10Field(call4,int*,0);
            workWord3=Physics10Player60View4;
            Physics10PlayerA8View4=delta19;
            workWord2+=delta19;
            workWord2&=4095;
            workWord3+=delta18;
            workWord3&=4095;
            Physics10Field(call4,int*,0)=workWord2;
            workWord2=workWord3<2049;
            Physics10Player60View4=workWord3;
            if(!workWord2){
                workWord2=workWord3-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics10Player60View4=workWord2;
            }
            workWord2=Physics10Player60View4;
            workWord2=workWord2<-800;
            if(workWord2)Physics10Player60View4=-800;
            workWord2=Physics10Player60View4;
            workWord2=workWord2<801;
            if(!workWord2)Physics10Player60View4=800;
            workWord2=Physics10Data6FA38View2;
            if(workWord2>=0)goto nonnegative33;
            workWord3=Physics10Player60View4;
            if(workWord3>=0)goto positive33;
            numeric4=Physics10Data67634View2;
            workWord2=Physics10Data67630View2;
            workWord2=numeric4-workWord2;
            goto quotient33;
            positive33:if(workWord3<=0)goto zero33;
            workWord2=Physics10Data67638View2;
            numeric4=Physics10Data67634View2;
            workWord2-=numeric4;
            quotient33:workWord2=workWord3*workWord2;
            workWord3=workWord2/800;
            numeric4+=workWord3;
            Physics10PlayerACView4=numeric4;
            goto modifier33;
            zero33:workWord2=Physics10Data67634View2;
            Physics10PlayerACView4=workWord2;
            modifier33:speed33:call5=&Physics10Player144View4;
            workWord2=Physics10PlayerACView4;
            numeric4=Physics10PlayerB0View4;
            workWord3=Physics10Field(call5,int*,0);
            workWord2-=numeric4;
            workWord2-=workWord3;
            workWord2=(workWord2<<6)>>6;
            workWord3+=workWord2;
            Physics10Field(call5,int*,0)=workWord3;
            workWord3>>=6;
            numeric4+=workWord3;
            Physics10PlayerB0View4=numeric4;
            numeric4=numeric4<2048;
            if(numeric4)Physics10PlayerB0View4=2048;
            workWord2=Physics10PlayerB0View4;
            workWord2=workWord2<19201;
            if(!workWord2)Physics10PlayerB0View4=19200;
            goto rotation33;
            nonnegative33:numeric4=Physics10Player8View4;
            limit16=0;
            workWord2=Physics10Call4E4E4View2(numeric4);
            workWord3=Physics10Player148View3;
            __asm__ volatile(""::"r"(workWord3),"r"(workWord2):"memory");
            numeric4=workWord2;
            __asm__("":"=r"(numeric4):"0"(numeric4));
            Physics10PlayerACView4=numeric4;
            numeric5=workWord3;
            if(!workWord3)goto zeroCounter33;
            workWord2=0x60000;
            Physics10Player130View2=workWord2;
            workWord2=numeric5-1;
            Physics10Player148View3=workWord2;
            workWord2<<=16;
            if(workWord2>0)goto positiveCounter33;
            workWord3=Physics10PlayerB0View4;
            workWord2=workWord3-numeric4;
            workWord2=workWord2<192;
            if(workWord2){
                workWord2=numeric4+8192;
                Physics10PlayerB0View4=workWord2;
                Physics10Player148View3=0;
                goto counterClamp33;
            }
            workWord2=workWord3-192;
            Physics10PlayerB0View4=workWord2;
            workWord2=1;
            Physics10Player148View3=workWord2;
            goto counterClamp33;
            positiveCounter33:workWord2=numeric4+8192;
            Physics10PlayerB0View4=workWord2;
            limit16=96;
            goto counterClamp33;
            zeroCounter33:Physics10PlayerB0View4=numeric4;
            __asm__ volatile("":"=r"(limit16):"0"(limit16):"$3","memory");
            Physics10Player130View2=0;
            counterClamp33:globalPointer=&Physics10PlayerB0View4;
            workWord2=Physics10Field(globalPointer,int*,0);
            workWord2=workWord2<22785;
            if(!workWord2)Physics10Field(globalPointer,int*,0)=22784;
            workWord2=Physics10Field(globalPointer,int*,0);
            workWord2=workWord2<2048;
            if(workWord2)Physics10Field(globalPointer,int*,0)=2048;
            numeric5=Physics10Player14CView4;
            workWord3=Physics10Player150View2;
            workWord2=limit16-numeric5;
            workWord2<<=4;
            numeric4=workWord3<<5;
            workWord2-=numeric4;
            workWord2>>=6;
            workWord3+=workWord2;
            Physics10Player150View2=workWord3;
            workWord3>>=4;
            numeric5+=workWord3;
            Physics10Player14CView4=numeric5;
            if(numeric5<0)Physics10Player14CView4=0;
            workWord2=Physics10Player14CView4;
            workWord2=workWord2<97;
            if(!workWord2)Physics10Player14CView4=96;
            rotation33:workWord2=Physics10Player148View3;
            workWord2=workWord2<2;
            if(workWord2)goto spring33;
            workWord3=Physics10Player14AView2;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3*3;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            workWord3=Physics10Player5CView4;
            workWord2<<=11;
            Physics10Player154View2=workWord2;
            workWord2>>=6;
            workWord3+=workWord2;
            workWord3&=4095;
            workWord2=workWord3<2049;
            Physics10Player5CView4=workWord3;
            if(workWord2)goto rotationDone33;
            workWord2=workWord3-4096;
            goto storeAngle33;
            spring33:workWord2=Physics10Call4EA2CView9(Physics10Player60View4);
            workWord2<<=5;
            workWord2=-workWord2;
            originalLow=delta19*workWord2;
            workWord3=Physics10Player154View2;
            numeric5=Physics10Player5CView4;
            workWord2=(workWord3<<4)>>6;
            numeric4=originalLow>>12;
            numeric4-=workWord2;
            workWord2=(numeric5<<6)>>6;
            numeric4-=workWord2;
            workWord3+=numeric4;
            Physics10Player154View2=workWord3;
            workWord3>>=6;
            numeric5+=workWord3;
            numeric5&=4095;
            workWord2=numeric5<2049;
            Physics10Player5CView4=numeric5;
            if(workWord2)goto rotationDone33;
            workWord2=numeric5-4096;
            storeAngle33:Physics10Player5CView4=workWord2;
            rotationDone33:Physics10Call41848View7();
            call5=&Physics10Player4CView4;
            numeric4=Physics10Field(call5,int*,0);
            if(numeric4)goto active33;
            workWord2=(int)Physics10Data6C570View5;
            workWord2=Physics10Field((void*)workWord2,int*,4)&64;
            if(!workWord2)goto end33;
            workWord2=Physics10PlayerF8View4;
            workWord3=Physics10Player8View4;
            workWord2-=512;
            workWord3=workWord3<workWord2;
            if(!workWord3)goto end33;
            workWord3=Physics10Player48View2;
            workWord2=33;
            if(workWord3!=workWord2)goto end33;
            workWord2=1;
            Physics10Field(call5,int*,0)=workWord2;
            __asm__ volatile("":::"$4","memory");
            Physics10Player160View2=0;
            goto end33;
            active33:workWord2=Physics10Player8View4;
            workWord3=Physics10PlayerF8View4;
            workWord2=workWord2<workWord3;
            if(workWord2){
                workWord2=1;
                goto activeRemainder33;
            }
            workWord2=1;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics10Field(call5,int*,0)=0;
            goto end33;
            activeRemainder33:if(numeric4!=workWord2)goto decline33;
            workWord2=Physics10Player160View2;
            workWord2+=512;
            Physics10Player160View2=workWord2;
            workWord2=workWord2<6144;
            if(!workWord2){
                workWord2=6144;
                Physics10Player160View2=workWord2;
                workWord2=2;
                Physics10Field(call5,int*,0)=workWord2;
            }
            goto add88;
            decline33:workWord2=Physics10Player160View2;
            workWord2-=256;
            Physics10Player160View2=workWord2;
            if(workWord2<=0){
                Physics10Player160View2=0;
                Physics10Field(call5,int*,0)=0;
            }
            add88:{
                register void *pointer2 __asm__("$2");
                pointer2=&Physics10Player88View4;
                workWord3=Physics10Field(pointer2,int*,0);
                numeric4=Physics10Player160View2;
                workWord3+=numeric4;
                Physics10Field(pointer2,int*,0)=workWord3;
            }
            end33:Physics10Call41B64View9();
            return;
        }
    case 40:{
            register int numeric4 __asm__("$4");
            call5=&Physics10Player20CView4;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics10Field(call5,int*,0)&64;
            call4=&originalFrame.sp38;
            if(workWord2)goto block_132;
            call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics10Call410F8View6(call4,call5,0);
            workWord3=Physics10Player4CView3;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics10Player60View3;
                numeric4=Physics10Player144View3;
                workWord2-=workWord3;
                workWord3=numeric4<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp3C=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp3C=workWord2;
                }
                __asm__ volatile("":::"memory");
                workWord2=originalFrame.sp3C;
                workWord3=numeric4+1;
                Physics10Player144View3=workWord3;
                workWord3=workWord3<21;
                workWord2=(workWord2<<7)>>8;
                originalFrame.sp3C=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics10Player4CView3=0;
                }
            }
            raw21_temp_s1_4 = (int) (originalFrame.sp38 * 0x14) >> 7;
            Physics10Field(&Physics10Player0View10, int *, 0x64) = (int) ((Physics10Field(&Physics10Player0View10, int *, 0x64) + raw21_temp_s1_4) & 0xFFF);
            raw21_temp_v1_6 = (Physics10Field(&Physics10Player0View10, int *, 0x60) + ((int) (originalFrame.sp3C * -0xF) >> 7)) & 0xFFF;
            Physics10Field(&Physics10Player0View10, int *, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics10Field(&Physics10Player0View10, int *, 0x60) = (int) (raw21_temp_v1_6 - 0x1000);
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x60) < -0x320) {
                Physics10Field(&Physics10Player0View10, int *, 0x60) = -0x320;
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x60) >= 0x321) {
                Physics10Field(&Physics10Player0View10, int *, 0x60) = 0x320;
            }
            if ((*Physics10Data6C570View8 & 0x40) || (Physics10Field(&Physics10Player0View10, int *, 0x4C) == 1)) {
                Physics10Field(&Physics10Player0View10, int *, 0xAC) = 0xE00;
            }
            else {
                Physics10Field(&Physics10Player0View10, int *, 0xAC) = 0;
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x4C) == 2) {
                Physics10Call417FCView10(0xC0, 0xC0);
                if (Physics10Field(&Physics10Player0View10, int *, 0xB0) < 0xE01) {
                    Physics10Field(&Physics10Player0View10, int *, 0x4C) = 0;
                }
            }
            else {
                Physics10Call417FCView10(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics10Player0View10 + 0x60;
            raw21_temp_a0_5 = (((int) (raw21_temp_s1_4 * -(Physics10Call4EA2CView10(Physics10Field(&Physics10Player0View10, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics10Field(&Physics10Player0View10, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics10Field(&Physics10Player0View10, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics10Field(&Physics10Player0View10, int *, 0x14C) + raw21_temp_a0_5;
            Physics10Field(&Physics10Player0View10, int *, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 = (Physics10Field(&Physics10Player0View10, int *, 0x5C) + (raw21_temp_v1_7 >> 6)) & 0xFFF;
            Physics10Field(&Physics10Player0View10, int *, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics10Field(&Physics10Player0View10, int *, 0x5C) = (int) (raw21_temp_a1_2 - 0x1000);
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x5C) < -0x300) {
                Physics10Field(&Physics10Player0View10, int *, 0x5C) = -0x300;
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x5C) >= 0x301) {
                Physics10Field(&Physics10Player0View10, int *, 0x5C) = 0x300;
            }
            Physics10Call41848View8(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics10Call4F178View10(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2=Physics10CallRandView8()&31;
            if(workWord2)goto block_130;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            particleCall3=Physics21_SpawnParticle;
            call4=(void*)1;
            if(!particleCall3)goto block_130;
            call5=(void*)44;
            call6=&originalFrame.sp40;
            particleArg7=0;
            __asm__("":"=r"(particleArg7):"0"(particleArg7));
            workWord2=544;
            originalFrame.sp40=workWord2;
            workWord2=64;
            originalFrame.sp44=0;
            __asm__ volatile(""::"i"(0x80088F30):"memory");
            originalFrame.sp48=workWord2;
            goto block_129;
        }
    case 41:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics10Player0View10 + 0x20C;
            if (!(Physics10Field(&Physics10Player0View10, int *, 0x20C) & 0x40)) {
                if (Physics10Data6E044View10 != 7) {
                    Physics10Call410F8View6(&originalFrame.sp40, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3=originalFrame.sp40;
                    numeric4=originalFrame.sp44;
                    workWord2=workWord3*5;
                    workWord2<<=2;
                    raw21_temp_s0_8=workWord2>>7;
                    workWord2=numeric4<<4;
                    numeric4-=workWord2;
                    numeric4>>=7;
                    workWord3=Physics10Player64View3;
                    workWord2=Physics10Player60View3;
                    workWord3+=raw21_temp_s0_8;
                    workWord3&=4095;
                    workWord2+=numeric4;
                    Physics10Player64View3=workWord3;
                    workWord3=workWord2&4095;
                    workWord2=workWord3<2049;
                    Physics10Player60View3=workWord3;
                    if(!workWord2){
                        workWord2=workWord3-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics10Player60View3=workWord2;
                    }
                    if (Physics10Field(&Physics10Player0View10, int *, 0x60) < -0x320) {
                        Physics10Field(&Physics10Player0View10, int *, 0x60) = -0x320;
                    }
                    if (Physics10Field(&Physics10Player0View10, int *, 0x60) >= 0x321) {
                        Physics10Field(&Physics10Player0View10, int *, 0x60) = 0x320;
                    }
                    workWord2=Physics10Call4EA2CView10(Physics10Player60View3);
                    workWord2<<=5;
                    workWord2=-workWord2;
                    product41=raw21_temp_s0_8*workWord2;
                    workWord3=Physics10Field(raw21_temp_s1_5,int*,-192);
                    numeric5=Physics10Player5CView3;
                    workWord2=(workWord3<<4)>>6;
                    numeric4=product41>>12;
                    numeric4-=workWord2;
                    workWord2=(numeric5<<6)>>6;
                    numeric4-=workWord2;
                    workWord3+=numeric4;
                    Physics10Field(raw21_temp_s1_5,int*,-192)=workWord3;
                    workWord3>>=6;
                    numeric5+=workWord3;
                    numeric5&=4095;
                    workWord2=numeric5<2049;
                    Physics10Player5CView3=numeric5;
                    if(!workWord2){
                        workWord2=numeric5-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics10Player5CView3=workWord2;
                    }
                    if (Physics10Field(&Physics10Player0View10, int *, 0x5C) < -0x300) {
                        Physics10Field(&Physics10Player0View10, int *, 0x5C) = -0x300;
                    }
                    if (Physics10Field(&Physics10Player0View10, int *, 0x5C) >= 0x301) {
                        Physics10Field(&Physics10Player0View10, int *, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics10Player0View10 + 0x80;
                Physics10Call4F168View10(raw21_temp_s0_9);
                Physics10Call4F168View10(raw21_temp_s0_9 + 0xC);
                workWord2=Physics10CallRandView8()&31;
                if(workWord2)goto block_130;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                particleCall3=Physics21_SpawnParticle;
                call4=(void*)1;
                if(!particleCall3)goto block_130;
                call5=(void*)44;
                call6=&originalFrame.sp50;
                particleArg7=0;
                __asm__("":"=r"(particleArg7):"0"(particleArg7));
                workWord2=544;
                originalFrame.sp50=workWord2;
                workWord2=64;
                originalFrame.sp54=0;
                originalFrame.sp58=workWord2;
                block_129:particleCall3(call4,call5,call6,particleArg7);
                block_130:globalPointer=&Physics10Player158View2;
                workWord2=Physics10Field(globalPointer,int*,0);
                workWord2++;
                Physics10Field(globalPointer,int*,0)=workWord2;
                return;
            }
            goto block_132;
        }
    case 42:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5=&Physics10Player20CView4;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics10Field(call5,int*,0)&64;
            call4=&originalFrame.sp50;
            if(!workWord2)goto run42;
            block_132:Physics10PlayerACView3=0;
            Physics10PlayerB0View3=0;
            return;
            run42:call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics10Call410F8View6(call4,call5,0);
            workWord3=Physics10Player4CView3;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics10Player60View3;
                numeric5=Physics10Player144View3;
                workWord2-=workWord3;
                workWord3=numeric5<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp54=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp54=workWord2;
                }
                __asm__ volatile("":::"memory");
                numeric4=originalFrame.sp54;
                workWord3=numeric5+1;
                Physics10Player144View3=workWord3;
                workWord3=workWord3<13;
                workWord2=numeric4*3;
                workWord2<<=5;
                workWord2>>=8;
                originalFrame.sp54=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics10Player4CView3=0;
                }
            }
            raw21_temp_s1_6 = &Physics10Player0View10 + 0x64;
            raw21_temp_s0_10 = (int) (originalFrame.sp50 * 0x14) >> 7;
            Physics10Field(&Physics10Player0View10, int *, 0x64) = (int) ((Physics10Field(&Physics10Player0View10, int *, 0x64) + raw21_temp_s0_10) & 0xFFF);
            raw21_temp_v1_13 = (Physics10Field(&Physics10Player0View10, int *, 0x60) + ((int) (originalFrame.sp54 * -0xF) >> 7)) & 0xFFF;
            Physics10Field(&Physics10Player0View10, int *, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics10Field(&Physics10Player0View10, int *, 0x60) = (int) (raw21_temp_v1_13 - 0x1000);
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x60) < -0x320) {
                Physics10Field(&Physics10Player0View10, int *, 0x60) = -0x320;
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x60) >= 0x321) {
                Physics10Field(&Physics10Player0View10, int *, 0x60) = 0x320;
            }
            Physics10Field(&Physics10Player0View10, int *, 0xAC) = 0x1C00;
            Physics10Call417FCView10(0x240, 0x30);
            raw21_temp_a0_6 = (((int) (raw21_temp_s0_10 * -(Physics10Call4EA2CView10(Physics10Field(&Physics10Player0View10, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics10Field(&Physics10Player0View10, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics10Field(&Physics10Player0View10, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 = Physics10Field(&Physics10Player0View10, int *, 0x14C) + raw21_temp_a0_6;
            Physics10Field(&Physics10Player0View10, int *, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 = (Physics10Field(&Physics10Player0View10, int *, 0x5C) + (raw21_temp_v1_14 >> 6)) & 0xFFF;
            Physics10Field(&Physics10Player0View10, int *, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics10Field(&Physics10Player0View10, int *, 0x5C) = (int) (raw21_temp_a1_3 - 0x1000);
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x5C) < -0x300) {
                Physics10Field(&Physics10Player0View10, int *, 0x5C) = -0x300;
            }
            if (Physics10Field(&Physics10Player0View10, int *, 0x5C) >= 0x301) {
                Physics10Field(&Physics10Player0View10, int *, 0x5C) = 0x300;
            }
            Physics10Call41848View8(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics10Call4F178View10(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) && (Physics10Field(&Physics10Player0View10, int *, 0xB4) >= 0x7D1)) {
                originalFrame.sp60 = -0x190;
                originalFrame.sp64 = 0x40 - (Physics10CallRandView8() & 0x7F);
                originalFrame.sp68 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp60, 0);
                return;
            }
            break;
        }
    case 43:case 44:globalField4CPointer=&Physics10Player4CView3;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics10Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3!=workWord2)goto continue43;
        block_154:Physics10Call4F168View10(globalField4CPointer+52);
        Physics10Call4F168View10(globalField4CPointer+64);
        return;
        continue43:workWord2=7;
        workWord3=Physics10Data6E044View10;
        if (workWord3 == workWord2) {
            Physics10Field(&Physics10Player0View10, int *, 0xB0) = 0;
        }
        else {
            Physics10Call40D10View10(0x980);
            raw21_var_v0_2 = Physics10Call41580View10(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics10Field(&Physics10Player0View10, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics10Field(&Physics10Player0View10, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics10Call417FCView10(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics10Player0View10 + 0xB0;
        if (Physics10Field(&Physics10Player0View10, int *, 0xB0) != 0) {
            Physics10Call41848View8();
            Physics10Call41B64View10();
            Physics10Field(&Physics10Player0View10, int *, 0x94) = 0;
        }
        else {
            Physics10Call4F168View10(raw21_temp_s0_11 - 0x30);
            Physics10Call4F168View10(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics10Player0View10 + 0x28;
            if (Physics10Field(&Physics10Player0View10, int *, 0x28) < 0) {
                if ((Physics10Field(&Physics10Player0View10, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics10Data6C640View10 & 1)) {
                    Physics10Call4F178View10(&originalFrame.sp60, raw21_temp_s4 - 0x28);
                    originalFrame.sp74 = 0x40;
                    originalFrame.sp78 = 0;
                    originalFrame.sp70 = (int) Physics10Field(&Physics10Player0View10, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp74 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics10Call4ED6CView8(raw21_temp_s2_3, &originalFrame.sp70, &originalFrame.sp80);
                    Physics10Call4F194View10(&originalFrame.sp60, &originalFrame.sp60, &originalFrame.sp80);
                    originalFrame.sp70 = 0;
                    originalFrame.sp68 = -Physics10Field(&Physics10Player0View10, int *, 0x28);
                    Physics10Call4ED6CView8(raw21_temp_s2_3, &originalFrame.sp70, &originalFrame.sp70);
                    Physics10Call4F110View6(&originalFrame.sp70, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp60, &originalFrame.sp70);
                    if (!(Physics10CallRandView8() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp60, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics10Player0View10 + 0xB0;
                    if ((Physics10Field(&Physics10Player0View10, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics10Data6C640View10 & 7) && !(Physics10CallRandView8() & 3)) {
                        originalFrame.sp90 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp94 = 0;
                        originalFrame.sp98 = 0;
                        Physics10Call4ED6CView8(raw21_temp_s1_7 - 0x80, &originalFrame.sp90, &originalFrame.sp90);
                        Physics10Call4F194View10(&originalFrame.sp90, &originalFrame.sp90, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp98 = -Physics10Field(&Physics10Player0View10, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp90, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics10Field(&Physics10Player0View10, int *, 0x144) - ((int) ((Physics10Field(&Physics10Player0View10, int *, 0x148) * 2) + (Physics10Field(&Physics10Player0View10, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics10Field(&Physics10Player0View10, int *, 0x148) + raw21_temp_a1_4;
        Physics10Field(&Physics10Player0View10, int *, 0x144) = raw21_temp_a1_4;
        Physics10Field(&Physics10Player0View10, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics10Field(&Physics10Player0View10, int *, 0x148) = 0x5900;
        }
        if (Physics10Field(&Physics10Player0View10, int *, 0x148) < -0x5900) {
            Physics10Field(&Physics10Player0View10, int *, 0x148) = -0x5900;
            return;
        }
        break;
    }
}
#undef Physics10Field


/* AI generated; not human reviewed. SCUS-94467 800897A4..80089B98.
 * Verified37 independent table and50 particle routes adapted to original10
 * standalone stack10 vector, saved countS1/sourceS2 and original selector scope.
 * Original10 retains frame38 with two reserved stack words; their source
 * meaning is unknown and no accesses are invented. Source148-B0 and-98 are
 * byte offsets. Final callbackV0/store-delay words independently agree.
 * Units/helpers/cadence unresolved. All original words, strict full TU and
 * every retail hash required; compiled equality is not runtime parity.
 */
extern Spyro Callback10Player __asm__("D_80070328");
int Callback10Call80037058(int x, int y) __asm__("func_80037058");
int Callback10Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback10Call80041930(void) __asm__("func_80041930");
void Callback10Call80041AE8(void) __asm__("func_80041AE8");
void Callback10Call80041C20(void) __asm__("func_80041C20");
void Callback10Call80042A44(void) __asm__("func_80042A44");
extern int D_8006FA38,D_8006C648;
extern int Callback10Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback10Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback10Values[] __asm__("D_8006FCF0");
void Callback10Call80049590(void) __asm__("func_80049590");
extern short Callback10Count __asm__("D_80070328+0x148");
void Callback10Call8004F110(Vector3D*,int) __asm__("func_8004F110");
void func_level_10_800897A4(void) {
    Vector3D localVector;
    int reservedStackWords[2];
    register int computedValue __asm__("$4");
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$18");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$17");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$2");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback10Player.animationState) {
    case 0x13:
        Callback10Call80041C20();
        Callback10Call80042A44();
        Callback10Call80041930();
clearSharedValue:
        Callback10Player.unk4[0]=0;
        return;
        case 0x21:
        case 0x22:
        case 0x23:
            Callback10Call80041C20();
            Callback10Call80042A44();
            Callback10Call80041930();
            if (SpawnParticle != 0) {
                countBase=(unsigned char*)&Callback10Count;
                if (*(short*)countBase == 0) goto clearSharedValue;
                secondLimit = 1;
                if (*(short*)countBase >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    __asm__("" : "=r"(countBase) : "0"(countBase));
                    sourceBytes=countBase-0xB0;
                    do {
                        func_8004F178((&localVector), (Vector3D *) sourceBytes);
                        Callback10Call8004F110((&localVector), 7);
                        iteration += 1;
                        sample=rand();
                        component=localVector.x;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        localVector.x=component;
                        sample=rand();
                        component=localVector.y;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        localVector.y=component;
                        sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=sourceBytes - 0x98;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position) : "0"(kind), "1"(subtype), "2"(position), "r"(sample) : "$3", "memory");
                        component=localVector.z;
                        __asm__("" : "=r"(component) : "0"(component), "r"(sample));
                        sample &=254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                        particles=SpawnParticle;
                        __asm__ volatile("" : "=r"(particles) : "0"(particles) : "$7");
                        vector=(&localVector);
                        __asm__("" : "=r"(particles), "=r"(vector), "=r"(component) : "0"(particles), "1"(vector), "2"(component));
                        localVector.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
    case 0x28:
    case 0x29:
        Callback10Call80041C20();
        Callback10Call80042A44();
        descriptor=&Callback10Player.unk22[2];
        if (Callback10Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback10Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback10Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback10Flags[flagOffset] = Callback10Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback10Call80041C20();
        Callback10Call80042A44();
        Callback10Call80049590();
        descriptor=&Callback10Player.unk22[2];
        if (Callback10Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback10Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback10Player.unk22[2];
        }
        if (Callback10Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback10Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback10Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback10Flags[flagOffset] = Callback10Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback10Call80041C20();
        Callback10Call80042A44();
        Callback10Call80041AE8();
        if ((unsigned char) Callback10Player.unk10[4] != 0) {
            computedValue = -Callback10Player.unk9ha[4] - Callback10Call80037058(Callback10Player.position.x, Callback10Player.position.y);
            positionValue = Callback10Player.unk4a - computedValue;
            Callback10Player.unk4[0] = computedValue;
            positionDelta = (int) Callback10Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback10Player.position.z=positionValue;
        return;
    default:
        return;
    }
}


/**
 * func_level_10_80089B9C() - ???() - MATCHING
 * Ready to add. Probably a Spyro animation sounds related one. Probably try making an animation.inc.h.
 * https://decomp.me/scratch/HatAh
 */
#define LEVEL_ID 10
#define PlaySpyroSounds_level_10 func_level_10_80089B9C
#include "overlay/animation.inc.h"

/**
 * func_level_10_80089CA4() - ???() - MATCHING
 * Ready to add. Check comments in scratch first, will probably try adding this using an animation.inc.h instead.
 * Likely has matches across other levels.
 * https://decomp.me/scratch/4KNXz
 */
extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_10_80089CA4(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x2B: case 0x2C:
        position = &spyro.unk9e;
        break;
    case 0x13:
        position = 0;
        break;
    case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: return;
    default: return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089D20.
 * Reuses verified41 private0/4/8 swirl and fly clamp800/4B00 with conditional
 * selector<A0 pointer clear, verified37 underwater/surface vectors stack10/20/30.
 * Original10 selector13,21..23,28..2C and244/250 tail. Word60 FFF wrap/801/clamp
 * vectors800/801/FFF yield0/-7FF/-1 before helpers. Offsets are bytes, shifts,
 * widths and branches source-native. Empty constraints emit no instructions.
 * Require every code/internal jump/owned dispatch word and complete EXE/overlay
 * retail hashes. Helper/audio semantics, units, cadence and live parity are open.
 */
extern Spyro Transition10_D_80070328 __asm__("D_80070328");
int Transition10_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition10_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern unsigned char Transition10RawUnion[] __asm__("D_80070328+0x144");
extern int Transition10RawMovement __asm__("D_80070328+0x50");
extern void (*Call10Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw10State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call10A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw10NegativeWord __asm__("D_80070328+0x28");
void func_80047138(void);
void func_level_10_80089D20(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;

    int lengthResult;


    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    switch(arg0){
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition10RawMovement;
        privateData = Transition10_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition10_D_80070328.unk5 = 0;
        Transition10_D_80070328.grounded = 0;
        Transition10_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition10_D_80070328.m_WhirlwindPointer;
        yawValue=Transition10_D_80070328.rotation.yaw;
        positionZ=Transition10_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition10_D_80070328.union144.a.unk13cc=yawValue;
        Transition10_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition10_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition10_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition10_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition10_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition10_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition10_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition10_D_80070328.unk13e[0] = (int) Transition10_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition10_D_80070328.unk20a = 0;
        Transition10_D_80070328.critterMobyPtr = 0;
        Transition10_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition10RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition10_D_80070328.unk5=0;
            Transition10_func_8004F168((Vector3D*)(flyState+0x104));
            Transition10_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition10_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition10_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition10_D_80070328.unk8[0]=0x800;
            if(Transition10_D_80070328.unk8[0]>=0x4B01)Transition10_D_80070328.unk8[0]=0x4B00;
            Transition10_D_80070328.union144.a.unk13cb=0;
            Transition10_D_80070328.union144.b.unk148=0;
            Transition10_D_80070328.union144.a.unk13ce.x=0;
            Transition10_D_80070328.union144.a.unk13ce.y=0;
            Transition10_D_80070328.grounded=0;
            Transition10_D_80070328.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition10_D_80070328.movementState - 0xB) >= 2U) && (Transition10_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition10_D_80070328.movementState - 0x50));
                if ((Transition10_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw10NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition10_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call10A358(&vectors.first, 0x800);
                    vectors.first.z = firstResult;
                    if (firstResult != 0) {
                        firstParticleKind = 6;
                        if (D_80071934 != 0) {
                            firstParticleSubtype = 0x2E;
emitFirstParticle:
                            SpawnParticle(firstParticleKind, firstParticleSubtype, &vectors.first, 0);
                        }
                    }
                }
            }
            firstWrappedWord = Transition10_D_80070328.rotation.pitch & 0xFFF;
            Transition10_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition10_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition10_D_80070328.rotation.pitch > 0) {
                Transition10_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition10_D_80070328.unk5 = 1;
            }
            Transition10_func_8004F168((Vector3D *) ((unsigned char*)&Transition10_D_80070328.rotation.pitch + 0xEC));
            Transition10_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition10_D_80070328.unk8[0] = Transition10_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition10_D_80070328.rotation.pitch + 0x38), 0);
            Transition10_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition10_D_80070328.animationState == 0x2A) {
            Transition10_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition10_D_80070328.union144.a.unk13da = 0;
        }
        Transition10_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition10_D_80070328.unk20a = 0;
        Transition10_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw10State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw10NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition10_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call10A358(localVector, 0x800);
                    vectors.second.z = secondResult;
                    if (secondResult != 0) {
                        secondParticleKind = 6;
                        if (D_80071934 != 0) {
                            secondParticleSubtype = 0x2E;
emitSecondParticle:
                            SpawnParticle(secondParticleKind, secondParticleSubtype, localVector, 0);
                        }
                    }
                }
            }
            if (Transition10_D_80070328.animationState == 0x2E) {
                Transition10_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition10_D_80070328.rotation.pitch & 0xFFF;
            Transition10_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition10_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition10_D_80070328.rotation.pitch > 0) {
                Transition10_D_80070328.rotation.pitch = 0;
            }
            Transition10_D_80070328.unk5 = 1;
            Transition10_func_8004F168((Vector3D *) ((unsigned char*)&Transition10_D_80070328.animationState + 0x104));
            Transition10_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition10_D_80070328.unk8[0] = Transition10_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition10_D_80070328.animationState + 0x50), 0);
            Transition10_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition10_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition10_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition10RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition10RawUnion;
            *(int*)unionPointer=(-Transition10_D_80070328.unk7a[2].z)>>2;
            if(Transition10RawMovement!=8){Transition10_D_80070328.union144.a.unk13cc=0x5900;Transition10RawMovement=10;}
            Transition10_D_80070328.unk5=0;
            Transition10_D_80070328.unk8[0]=Transition10_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition10_D_80070328.grounded=1;
            Transition10_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call10A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
clearPointers:
        Transition10_D_80070328.unk20a=0;
        Transition10_D_80070328.critterMobyPtr=0;
        return;
    }
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level10
 * 8008A444: original576 instructions and26 dispatch words in sibling4844
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original10.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A10W48 __asm__("D_80070328 + 0x48");
extern int A10W4C __asm__("D_80070328 + 0x4C");
extern int A10W54 __asm__("D_80070328 + 0x54");
extern int A10WA0 __asm__("D_80070328 + 0xA0");
extern int A10WA8 __asm__("D_80070328 + 0xA8");
extern int A10WAC __asm__("D_80070328 + 0xAC");
extern int A10WB0 __asm__("D_80070328 + 0xB0");
extern int A10WB8 __asm__("D_80070328 + 0xB8");
extern int A10WCC __asm__("D_80070328 + 0xCC");
extern int A10WD0 __asm__("D_80070328 + 0xD0");
extern int A10WD4 __asm__("D_80070328 + 0xD4");
extern int A10W8C __asm__("D_80070328 + 0x8C");
extern int A10W90 __asm__("D_80070328 + 0x90");
extern int A10W94 __asm__("D_80070328 + 0x94");
extern int A10WE4 __asm__("D_80070328 + 0xE4");
extern int A10W144 __asm__("D_80070328 + 0x144");
extern int A10W158 __asm__("D_80070328 + 0x158");
extern int A10W1EC __asm__("D_80070328 + 0x1EC");
extern int A10W1F0 __asm__("D_80070328 + 0x1F0");
extern int A10W240 __asm__("D_80070328 + 0x240");
extern int A10W280 __asm__("D_80070328 + 0x280");
extern unsigned char A10B14 __asm__("D_80070328 + 0x14");
extern unsigned char A10B15 __asm__("D_80070328 + 0x15");
extern unsigned char A10B16 __asm__("D_80070328 + 0x16");
extern unsigned char A10B17 __asm__("D_80070328 + 0x17");
extern unsigned char A10B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A10BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A10B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A10B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A10Player[] __asm__("D_80070328");
extern unsigned char A10Table[] __asm__("D_80066530");
extern int A10Buttons __asm__("D_8006E538"),A10NewButtons __asm__("D_8006E53C");
extern int A10Mode __asm__("D_8006E044"),A10Gate __asm__("D_8006E344"),A10Count __asm__("D_8006C514");
extern int (*A10Callback)() __asm__("unk_ovlheader_80074374");
extern int A10W24 __asm__("D_80070328 + 0x24");
extern int A10W28C __asm__("D_80070328 + 0x28C");
extern int A10W290 __asm__("D_80070328 + 0x290");
extern int A10Surface __asm__("D_8006FA38");
extern unsigned char* A10SoundDesc __asm__("D_8006C654");
int A10Sound() __asm__("PlaySound");
int A10H3BF6C() __asm__("func_8003BF6C");
int A10H3BE70() __asm__("func_8003BE70");
int A10H40994() __asm__("func_80040994");
int A10H4BEF8() __asm__("func_8004BEF8");
int A10H49688() __asm__("func_80049688");
int A10H4F334() __asm__("func_8004F334");
int A10H498C0() __asm__("func_800498C0");
extern volatile int A10W20C __asm__("D_80070328 + 0x20C");
extern int A10W214 __asm__("D_80070328 + 0x214");
extern unsigned char A10B100 __asm__("D_80070328 + 0x100");
extern unsigned char A10E535 __asm__("D_8006E535");
extern unsigned char* A10Models __asm__("D_8006EE2C");
int A10H40BCC() __asm__("func_80040BCC");
int A10H1A310() __asm__("func_8001A310");
extern int A10W10C __asm__("D_80070328 + 0x10C");
extern int A10WB4 __asm__("D_80070328 + 0xB4");
extern int A10WA4 __asm__("D_80070328 + 0xA4");
extern int (*A10Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A10H40954() __asm__("func_80040954");
extern int A10W50 __asm__("D_80070328 + 0x50");
extern int A10WBC __asm__("D_80070328 + 0xBC"), A10W1BC __asm__("D_80070328 + 0x1BC"), A10W60 __asm__("D_80070328 + 0x60");
extern short A10H148 __asm__("D_80070328 + 0x148");
int A10H43194() __asm__("func_80043194");
int A10H4EDE8() __asm__("func_8004EDE8");
void func_level_10_8008A444(void) {
 register int work2 __asm__("$2"),work3 __asm__("$3"),work4 __asm__("$4"),work5 __asm__("$5");
 register int* state __asm__("$16");
 register int* locomotion __asm__("$17");
 switch(A10W48){
 case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 36: case 37: case 38: case 39: return;

 case 19:
  if(A10H40994())return;
  work2=13;work3=A10Gate;
  if(work3==work2){work2=A10Count;work4=17;if(work2)goto call;}
  work4=(int)A10Player;work2=A10H4F334((void*)work4,(void*)(work4+348));
  work3=A10W158;work3=work3<work2;work4=17;if(!work3)return;goto call;
 case 33:

  if(A10H40994())return;
  locomotion=&A10WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A10WE4>=23)A10H4BEF8(7);
   if(A10WAC>0){
    work3=A10WB0;work2=work3<3841;if(!work2){__asm__ volatile("" ::: "memory");work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A10WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A10NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A10H43194(4);work4=47;if(work2)goto call;
  work2=A10WBC;work4=7;if(!work2)goto call;
  work2=A10W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A10H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  work2=A10H148<2;work4=35;if(!work2)goto call;
  work2=A10W4C;work4=34;if(work2)goto call;
  work3=A10W60;work2=work3<365;if(!work2)goto call;
  work2=work3< -364;work4=35;if(!work2)return;goto call;

 case 34:

  if(A10H40994())return;
  locomotion=&A10WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A10WE4>=23)A10H4BEF8(7);
   if(A10WAC>0){
    work3=A10WB0;work2=work3<3841;if(!work2){__asm__ volatile("" ::: "memory");work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A10WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A10NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A10H43194(4);work4=47;if(work2)goto call;
  work2=A10WBC;work4=7;if(!work2)goto call;
  work2=A10W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A10H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  work2=A10H148<2;work4=35;if(!work2)goto call;
  if(A10W60>=256)return;
  work2=A10W4C;work4=33;if(work2)return;goto call;

 case 35:

  if(A10H40994())return;
  locomotion=&A10WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A10WE4>=23)A10H4BEF8(7);
   if(A10WAC>0){
    work3=A10WB0;work2=work3<3841;if(!work2){work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A10WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A10NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A10H43194(4);work4=47;if(work2)goto call;
  work2=A10WBC;work4=7;if(!work2)goto call;
  work2=A10W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A10H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  if(A10H148>=2)return;
  work2=A10W4C;work4=34;if(work2)goto call;
  work2=A10W60< -255;work4=33;if(work2)return;goto call;

 case 40:
  if(A10H40994())return;
  if((A10Buttons&128) && A10W4C!=1){work4=42;goto call;}
  if(A10WB0)return;
  work2=A10W20C&64;work4=41;if(!work2)goto call;
  if(A10W214<=0)return;goto call;
 case 41:
  if(A10H40994())return;
  work4=A10Buttons;work2=work4&128;if(work2){work4=42;goto call;}
  work2=7;work3=A10Mode;if(work3==work2)return;
  work2=work4&64;work4=40;if(work2)goto call;
  if(!(A10W20C&64))return;
  if(!A10W214)goto call;return;
 case 42:
  if(A10H40BCC())return;
  if((A10Buttons&128) || A10W4C==1)goto flag64;
  work2=A10W20C&128;work4=40;if(!work2)goto call;
  flag64:work2=A10W20C&64;work4=40;if(!work2)return;goto call;
 case 43: {
  register unsigned char* byte4 __asm__("$4");
  if(A10H40994())return;
  if((A10NewButtons&64) && A10W54>=9){work4=6;goto partialCall;}
  byte4=&A10B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto partialCall;}
  if(!(A10NewButtons&128))goto check44;
  if(A10W54<9)goto check44;
  work2=*(int*)(A10Models+220);byte4-=256;if(!work2)goto check44;
  work2=A10H1A310(byte4,1024,1,0);work4=40;
  if(work2)goto check44;goto call;
  partialCall:A10H4BEF8(work4);
  check44:work2=A10E535;work4=44;if(!work2)return;goto call;
 }
 case 44: {
  register unsigned char* byte4 __asm__("$4");
  register int (*callback2)() __asm__("$2");
  work3=A10W4C;work2=1;if(work3!=work2)goto other44;
  if(A10NewButtons&0x850)goto callback44;
  if(A10W54<61)return;
  callback44:callback2=A10Callback;__asm__("" : "=r"(callback2):"0"(callback2));
  if(!callback2)goto missingCallback;
  callback2();return;
  missingCallback:A10H498C0();return;
  other44:if(A10H40994())return;
  if((A10NewButtons&64) && A10W54>=9){work4=6;goto call;}
  byte4=&A10B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto call;}
  if(!(A10NewButtons&128))goto mode44;
  if(A10W54<9)goto mode44;
  work2=*(int*)(A10Models+220);byte4-=256;if(!work2)goto mode44;
  work2=A10H1A310(byte4,1024,1,0);work4=40;if(!work2)goto call;
  mode44:work3=A10Mode;work2=7;if(work3==work2)return;
  work2=A10E535;work4=43;if(work2)return;__asm__ volatile("" ::: "memory");goto call;
 }
 }
 return;
 call:__asm__ volatile("" ::: "memory");A10H4BEF8(work4);return;
}
