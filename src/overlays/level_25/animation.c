#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
#include "spu.h"
#include "hud.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800870B4.
 * Assembly SHA256 b2fbab4440b6464ca8accb48546569392b2b989f483746df58c202fa77b3d555.
 * AI-generated; not human reviewed. All928 original instructions,
 * 37 selectors bias25 and 1 owned padding words are required.
 * Original frame0x90; every concrete field width and producer is retained.
 * Five exact groups reuse verified11/13/33/23/21 with original frame maps.
 * Original scratch10..74,savedS0..S4,slotS2,A0 selector and table bias25 remain.
 * All24 original55 rows retain the wrapped 144/148 recurrence: both original
 * loads,shift/add product, signed shift8,subtraction,addition and ordered stores.
 * No scale,timing or helper meaning is inferred. Every original word is required.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics25Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics25Call363DCView5() __asm__("func_800363DC");
unsigned char Physics25Call40D10View6() __asm__("func_80040D10");
unsigned char Physics25Call41580View6() __asm__("func_80041580");
unsigned char Physics25Call416F4View6() __asm__("func_800416F4");
unsigned char Physics25Call417FCView6() __asm__("func_800417FC");
unsigned char Physics25Call41B64View6() __asm__("func_80041B64");
int Physics25Call4E9E4View6() __asm__("func_8004E9E4");
int Physics25Call4EA2CView6() __asm__("func_8004EA2C");
unsigned char Physics25Call4ED6CView5() __asm__("func_8004ED6C");
int Physics25Call4EDE8View6() __asm__("func_8004EDE8");
unsigned char Physics25Call4F08CView6() __asm__("func_8004F08C");
unsigned char Physics25Call4F110View4() __asm__("func_8004F110");
unsigned char Physics25Call4F168View6() __asm__("func_8004F168");
unsigned char Physics25Call4F178View6() __asm__("func_8004F178");
unsigned char Physics25Call4F194View6() __asm__("func_8004F194");
unsigned char Physics25Call4F1C8View6() __asm__("func_8004F1C8");
int Physics25CallRandView5() __asm__("rand");
extern unsigned char Physics25Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View6 __asm__("D_80065920");
extern void *Physics25Data6C570View5 __asm__("D_8006C570");
extern int Physics25Data6C640View6 __asm__("D_8006C640");
extern int Physics25Data6E044View6 __asm__("D_8006E044");
extern unsigned char Physics25Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics25Player0View6 __asm__("D_80070328");
extern int Physics25Player94View4 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics25Call40D10View7() __asm__("func_80040D10");
int Physics25Call40F48View4() __asm__("func_80040F48");
int Physics25Call410F8View4() __asm__("func_800410F8");
int Physics25Call41404View3() __asm__("func_80041404");
int Physics25Call41580View7() __asm__("func_80041580");
int Physics25Call416F4View7() __asm__("func_800416F4");
int Physics25Call417FCView7() __asm__("func_800417FC");
int Physics25Call41848View5() __asm__("func_80041848");
int Physics25Call41B64View7() __asm__("func_80041B64");
int Physics25Call4E9E4View7() __asm__("func_8004E9E4");
int Physics25Call4EA2CView7() __asm__("func_8004EA2C");
int Physics25Call4EDE8View7() __asm__("func_8004EDE8");
int Physics25Call4F08CView7() __asm__("func_8004F08C");
int Physics25Call4F168View7() __asm__("func_8004F168");
int Physics25Call4F178View7() __asm__("func_8004F178");
int Physics25Call4F194View7() __asm__("func_8004F194");
int Physics25Call4F1C8View7() __asm__("func_8004F1C8");
int Physics25Call4F284View3() __asm__("func_8004F284");
extern unsigned char Physics25Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View7 __asm__("D_80065920");
extern int Physics25Data6763CView3 __asm__("D_8006763C");
extern int Physics25Data67640View3 __asm__("D_80067640");
extern int Physics25Data67644View3 __asm__("D_80067644");
extern unsigned char Physics25Data676E8View3 __asm__("D_800676E8");
extern int* Physics25Data6C570View6 __asm__("D_8006C570");
extern int Physics25Data6C58CView3 __asm__("D_8006C58C");
extern int Physics25Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics25Data6C640View7 __asm__("D_8006C640");
extern short Physics25Data6E040View3 __asm__("D_8006E040");
extern int Physics25Data6E044View7 __asm__("D_8006E044");
extern int Physics25Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics25Player0View7 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics25Player94View5 __asm__("D_80070328+0x94");
extern int Physics25PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics25Player80View2 __asm__("D_80070328+0x80");
extern int Physics25PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics25Player64View3 __asm__("D_80070328+0x64");
extern int Physics25Player88View3 __asm__("D_80070328+0x88");
extern int Physics25Player84View2 __asm__("D_80070328+0x84");
extern int Physics25Player144View3 __asm__("D_80070328+0x144");
extern int Physics25Player60View3 __asm__("D_80070328+0x60");
extern int Physics25PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics25Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics25Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics25Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics25PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics25PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics25Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics25Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics25Player20CView3 __asm__("D_80070328+0x20C");
extern unsigned char Physics25Player101View2 __asm__("D_80070328+0x101");
extern int Physics25PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics25Player210View3 __asm__("D_80070328+0x210");
extern int Physics25PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics25Player8View3 __asm__("D_80070328+0x8");
int Physics25Call363DCView6() __asm__("func_800363DC");
int Physics25Call40D10View8() __asm__("func_80040D10");
int Physics25Call40F48View5() __asm__("func_80040F48");
int Physics25Call41580View8() __asm__("func_80041580");
int Physics25Call416F4View8() __asm__("func_800416F4");
int Physics25Call417FCView8() __asm__("func_800417FC");
int Physics25Call41848View6() __asm__("func_80041848");
int Physics25Call41B64View8() __asm__("func_80041B64");
int Physics25Call43194View2() __asm__("func_80043194");
int Physics25Call4E880View3() __asm__("func_8004E880");
int Physics25Call4E9E4View8() __asm__("func_8004E9E4");
int Physics25Call4EA2CView8() __asm__("func_8004EA2C");
int Physics25Call4ED6CView6() __asm__("func_8004ED6C");
int Physics25Call4EDE8View8() __asm__("func_8004EDE8");
int Physics25Call4F08CView8() __asm__("func_8004F08C");
int Physics25Call4F168View8() __asm__("func_8004F168");
int Physics25Call4F178View8() __asm__("func_8004F178");
int Physics25Call4F194View8() __asm__("func_8004F194");
int Physics25Call4F1C8View8() __asm__("func_8004F1C8");
int Physics25Call4F284View4() __asm__("func_8004F284");
int Physics25CallRandView6() __asm__("rand");
extern unsigned char Physics25Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View8 __asm__("D_80065920");
extern unsigned char Physics25Data676E8View4 __asm__("D_800676E8");
extern int Physics25Data6C514View4 __asm__("D_8006C514");
extern int* Physics25Data6C570View7 __asm__("D_8006C570");
extern int Physics25Data6C58CView4 __asm__("D_8006C58C");
extern int Physics25Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics25Data6C640View8 __asm__("D_8006C640");
extern short Physics25Data6E040View4 __asm__("D_8006E040");
extern int Physics25Data6E044View8 __asm__("D_8006E044");
extern int Physics25Data6E344View4 __asm__("D_8006E344");
extern int Physics25Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View8 __asm__("D_8006E548");
extern unsigned char Physics25Player0View8 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25Player16CView2 __asm__("D_80070328+0x16C");
int Physics25Call13E38View2() __asm__("func_80013E38");
int Physics25Call363DCView7() __asm__("func_800363DC");
int Physics25Call40D10View9() __asm__("func_80040D10");
int Physics25Call410F8View5() __asm__("func_800410F8");
int Physics25Call41580View9() __asm__("func_80041580");
int Physics25Call416F4View9() __asm__("func_800416F4");
int Physics25Call417FCView9() __asm__("func_800417FC");
int Physics25Call41848View7() __asm__("func_80041848");
int Physics25Call41B64View9() __asm__("func_80041B64");
int Physics25Call4E4E4View2() __asm__("func_8004E4E4");
int Physics25Call4E880View4() __asm__("func_8004E880");
int Physics25Call4E9E4View9() __asm__("func_8004E9E4");
int Physics25Call4EA2CView9() __asm__("func_8004EA2C");
int Physics25Call4ED6CView7() __asm__("func_8004ED6C");
int Physics25Call4EDE8View9() __asm__("func_8004EDE8");
int Physics25Call4F08CView9() __asm__("func_8004F08C");
int Physics25Call4F0E8View2() __asm__("func_8004F0E8");
int Physics25Call4F110View5() __asm__("func_8004F110");
int Physics25Call4F168View9() __asm__("func_8004F168");
int Physics25Call4F178View9() __asm__("func_8004F178");
int Physics25Call4F194View9() __asm__("func_8004F194");
int Physics25Call4F1C8View9() __asm__("func_8004F1C8");
int Physics25CallRandView7() __asm__("rand");
extern unsigned char Physics25Data658A0View9 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View9 __asm__("D_80065920");
extern int Physics25Data67630View2 __asm__("D_80067630");
extern int Physics25Data67634View2 __asm__("D_80067634");
extern int Physics25Data67638View2 __asm__("D_80067638");
extern int Physics25Data6C514View5 __asm__("D_8006C514");
extern int Physics25Data6C640View9 __asm__("D_8006C640");
extern int Physics25Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics25Data6E044View9 __asm__("D_8006E044");
extern int Physics25Data6E344View5 __asm__("D_8006E344");
extern int Physics25Data6E538View7 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View9 __asm__("D_8006E548");
extern int Physics25Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics25Player0View9 __asm__("D_80070328");
extern int Physics25Data71908View2 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25Player130View2 __asm__("D_80070328+0x130");
extern int Physics25Player144View4 __asm__("D_80070328+0x144");
extern short Physics25Player148View3 __asm__("D_80070328+0x148");
extern short Physics25Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics25Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics25Player150View2 __asm__("D_80070328+0x150");
extern int Physics25Player154View2 __asm__("D_80070328+0x154");
extern int Physics25Player160View2 __asm__("D_80070328+0x160");
extern int Physics25Player48View2 __asm__("D_80070328+0x48");
extern int Physics25Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics25Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics25Player60View4 __asm__("D_80070328+0x60");
extern int Physics25Player64View4 __asm__("D_80070328+0x64");
extern int Physics25Player8View4 __asm__("D_80070328+0x8");
extern int Physics25Player88View4 __asm__("D_80070328+0x88");
extern int Physics25Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics25Player90View2 __asm__("D_80070328+0x90");
extern int Physics25Player94View6 __asm__("D_80070328+0x94");
extern int Physics25PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics25PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics25PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics25PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics25Player148View4 __asm__("D_80070328+0x148");
extern int Physics25Player210View4 __asm__("D_80070328+0x210");
extern int Physics25Player220View2 __asm__("D_80070328+0x220");
extern int Physics25Player98View2 __asm__("D_80070328+0x98");
extern int Physics25PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics25PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics25PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics25PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics25PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics25PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics25Call363DCView8() __asm__("func_800363DC");
int Physics25Call40D10View10() __asm__("func_80040D10");
int Physics25Call40F48View6() __asm__("func_80040F48");
int Physics25Call410F8View6() __asm__("func_800410F8");
int Physics25Call41404View4() __asm__("func_80041404");
int Physics25Call41580View10() __asm__("func_80041580");
int Physics25Call416F4View10() __asm__("func_800416F4");
int Physics25Call417FCView10() __asm__("func_800417FC");
int Physics25Call41848View8() __asm__("func_80041848");
int Physics25Call41B64View10() __asm__("func_80041B64");
int Physics25Call4E9E4View10() __asm__("func_8004E9E4");
int Physics25Call4EA2CView10() __asm__("func_8004EA2C");
int Physics25Call4ED6CView8() __asm__("func_8004ED6C");
int Physics25Call4EDE8View10() __asm__("func_8004EDE8");
int Physics25Call4F08CView10() __asm__("func_8004F08C");
int Physics25Call4F110View6() __asm__("func_8004F110");
int Physics25Call4F168View10() __asm__("func_8004F168");
int Physics25Call4F178View10() __asm__("func_8004F178");
int Physics25Call4F194View10() __asm__("func_8004F194");
int Physics25Call4F1C8View10() __asm__("func_8004F1C8");
int Physics25CallRandView8() __asm__("rand");
extern unsigned char Physics25Data658A0View10 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View10 __asm__("D_80065920");
extern int Physics25Data6763CView4 __asm__("D_8006763C");
extern int Physics25Data67640View4 __asm__("D_80067640");
extern int Physics25Data67644View4 __asm__("D_80067644");
extern int Physics25Data6C514View6 __asm__("D_8006C514");
extern int* Physics25Data6C570View8 __asm__("D_8006C570");
extern int Physics25Data6C640View10 __asm__("D_8006C640");
extern int Physics25Data6E044View10 __asm__("D_8006E044");
extern int Physics25Data6E344View6 __asm__("D_8006E344");
extern int Physics25Data6E538View8 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View10 __asm__("D_8006E548");
extern unsigned char Physics25Player0View10 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25Player8CView4 __asm__("D_80070328+0x8C");
extern int Physics25PlayerB4View2 __asm__("D_80070328+0xB4");
extern int Physics25Player158View2 __asm__("D_80070328+0x158");
extern int Physics25Player20CView4 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
int Physics25Call363DCView5() __asm__("func_800363DC");
unsigned char Physics25Call40D10View6() __asm__("func_80040D10");
unsigned char Physics25Call41580View6() __asm__("func_80041580");
unsigned char Physics25Call416F4View6() __asm__("func_800416F4");
unsigned char Physics25Call417FCView6() __asm__("func_800417FC");
unsigned char Physics25Call41B64View6() __asm__("func_80041B64");
int Physics25Call4E9E4View6() __asm__("func_8004E9E4");
int Physics25Call4EA2CView6() __asm__("func_8004EA2C");
unsigned char Physics25Call4ED6CView5() __asm__("func_8004ED6C");
int Physics25Call4EDE8View6() __asm__("func_8004EDE8");
unsigned char Physics25Call4F08CView6() __asm__("func_8004F08C");
unsigned char Physics25Call4F110View4() __asm__("func_8004F110");
unsigned char Physics25Call4F168View6() __asm__("func_8004F168");
unsigned char Physics25Call4F178View6() __asm__("func_8004F178");
unsigned char Physics25Call4F194View6() __asm__("func_8004F194");
unsigned char Physics25Call4F1C8View6() __asm__("func_8004F1C8");
int Physics25CallRandView5() __asm__("rand");
extern unsigned char Physics25Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View6 __asm__("D_80065920");
extern void *Physics25Data6C570View5 __asm__("D_8006C570");
extern int Physics25Data6C640View6 __asm__("D_8006C640");
extern int Physics25Data6E044View6 __asm__("D_8006E044");
extern unsigned char Physics25Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics25Player0View6 __asm__("D_80070328");
extern int Physics25Player94View4 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics25Call40D10View7() __asm__("func_80040D10");
int Physics25Call40F48View4() __asm__("func_80040F48");
int Physics25Call410F8View4() __asm__("func_800410F8");
int Physics25Call41404View3() __asm__("func_80041404");
int Physics25Call41580View7() __asm__("func_80041580");
int Physics25Call416F4View7() __asm__("func_800416F4");
int Physics25Call417FCView7() __asm__("func_800417FC");
int Physics25Call41848View5() __asm__("func_80041848");
int Physics25Call41B64View7() __asm__("func_80041B64");
int Physics25Call4E9E4View7() __asm__("func_8004E9E4");
int Physics25Call4EA2CView7() __asm__("func_8004EA2C");
int Physics25Call4EDE8View7() __asm__("func_8004EDE8");
int Physics25Call4F08CView7() __asm__("func_8004F08C");
int Physics25Call4F168View7() __asm__("func_8004F168");
int Physics25Call4F178View7() __asm__("func_8004F178");
int Physics25Call4F194View7() __asm__("func_8004F194");
int Physics25Call4F1C8View7() __asm__("func_8004F1C8");
int Physics25Call4F284View3() __asm__("func_8004F284");
extern unsigned char Physics25Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View7 __asm__("D_80065920");
extern int Physics25Data6763CView3 __asm__("D_8006763C");
extern int Physics25Data67640View3 __asm__("D_80067640");
extern int Physics25Data67644View3 __asm__("D_80067644");
extern unsigned char Physics25Data676E8View3 __asm__("D_800676E8");
extern int* Physics25Data6C570View6 __asm__("D_8006C570");
extern int Physics25Data6C58CView3 __asm__("D_8006C58C");
extern int Physics25Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics25Data6C640View7 __asm__("D_8006C640");
extern short Physics25Data6E040View3 __asm__("D_8006E040");
extern int Physics25Data6E044View7 __asm__("D_8006E044");
extern int Physics25Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics25Player0View7 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics25Player94View5 __asm__("D_80070328+0x94");
extern int Physics25PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics25Player80View2 __asm__("D_80070328+0x80");
extern int Physics25PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics25Player64View3 __asm__("D_80070328+0x64");
extern int Physics25Player88View3 __asm__("D_80070328+0x88");
extern int Physics25Player84View2 __asm__("D_80070328+0x84");
extern int Physics25Player144View3 __asm__("D_80070328+0x144");
extern int Physics25Player60View3 __asm__("D_80070328+0x60");
extern int Physics25PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics25Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics25Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics25Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics25PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics25PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics25Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics25Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics25Player20CView3 __asm__("D_80070328+0x20C");
extern unsigned char Physics25Player101View2 __asm__("D_80070328+0x101");
extern int Physics25PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics25Player210View3 __asm__("D_80070328+0x210");
extern int Physics25PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics25Player8View3 __asm__("D_80070328+0x8");
int Physics25Call363DCView6() __asm__("func_800363DC");
int Physics25Call40D10View8() __asm__("func_80040D10");
int Physics25Call40F48View5() __asm__("func_80040F48");
int Physics25Call41580View8() __asm__("func_80041580");
int Physics25Call416F4View8() __asm__("func_800416F4");
int Physics25Call417FCView8() __asm__("func_800417FC");
int Physics25Call41848View6() __asm__("func_80041848");
int Physics25Call41B64View8() __asm__("func_80041B64");
int Physics25Call43194View2() __asm__("func_80043194");
int Physics25Call4E880View3() __asm__("func_8004E880");
int Physics25Call4E9E4View8() __asm__("func_8004E9E4");
int Physics25Call4EA2CView8() __asm__("func_8004EA2C");
int Physics25Call4ED6CView6() __asm__("func_8004ED6C");
int Physics25Call4EDE8View8() __asm__("func_8004EDE8");
int Physics25Call4F08CView8() __asm__("func_8004F08C");
int Physics25Call4F168View8() __asm__("func_8004F168");
int Physics25Call4F178View8() __asm__("func_8004F178");
int Physics25Call4F194View8() __asm__("func_8004F194");
int Physics25Call4F1C8View8() __asm__("func_8004F1C8");
int Physics25Call4F284View4() __asm__("func_8004F284");
int Physics25CallRandView6() __asm__("rand");
extern unsigned char Physics25Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View8 __asm__("D_80065920");
extern unsigned char Physics25Data676E8View4 __asm__("D_800676E8");
extern int Physics25Data6C514View4 __asm__("D_8006C514");
extern int* Physics25Data6C570View7 __asm__("D_8006C570");
extern int Physics25Data6C58CView4 __asm__("D_8006C58C");
extern int Physics25Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics25Data6C640View8 __asm__("D_8006C640");
extern short Physics25Data6E040View4 __asm__("D_8006E040");
extern int Physics25Data6E044View8 __asm__("D_8006E044");
extern int Physics25Data6E344View4 __asm__("D_8006E344");
extern int Physics25Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View8 __asm__("D_8006E548");
extern unsigned char Physics25Player0View8 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25Player16CView2 __asm__("D_80070328+0x16C");
int Physics25Call13E38View2() __asm__("func_80013E38");
int Physics25Call363DCView7() __asm__("func_800363DC");
int Physics25Call40D10View9() __asm__("func_80040D10");
int Physics25Call410F8View5() __asm__("func_800410F8");
int Physics25Call41580View9() __asm__("func_80041580");
int Physics25Call416F4View9() __asm__("func_800416F4");
int Physics25Call417FCView9() __asm__("func_800417FC");
int Physics25Call41848View7() __asm__("func_80041848");
int Physics25Call41B64View9() __asm__("func_80041B64");
int Physics25Call4E4E4View2() __asm__("func_8004E4E4");
int Physics25Call4E880View4() __asm__("func_8004E880");
int Physics25Call4E9E4View9() __asm__("func_8004E9E4");
int Physics25Call4EA2CView9() __asm__("func_8004EA2C");
int Physics25Call4ED6CView7() __asm__("func_8004ED6C");
int Physics25Call4EDE8View9() __asm__("func_8004EDE8");
int Physics25Call4F08CView9() __asm__("func_8004F08C");
int Physics25Call4F0E8View2() __asm__("func_8004F0E8");
int Physics25Call4F110View5() __asm__("func_8004F110");
int Physics25Call4F168View9() __asm__("func_8004F168");
int Physics25Call4F178View9() __asm__("func_8004F178");
int Physics25Call4F194View9() __asm__("func_8004F194");
int Physics25Call4F1C8View9() __asm__("func_8004F1C8");
int Physics25CallRandView7() __asm__("rand");
extern unsigned char Physics25Data658A0View9 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View9 __asm__("D_80065920");
extern int Physics25Data67630View2 __asm__("D_80067630");
extern int Physics25Data67634View2 __asm__("D_80067634");
extern int Physics25Data67638View2 __asm__("D_80067638");
extern int Physics25Data6C514View5 __asm__("D_8006C514");
extern int Physics25Data6C640View9 __asm__("D_8006C640");
extern int Physics25Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics25Data6E044View9 __asm__("D_8006E044");
extern int Physics25Data6E344View5 __asm__("D_8006E344");
extern int Physics25Data6E538View7 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View9 __asm__("D_8006E548");
extern int Physics25Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics25Player0View9 __asm__("D_80070328");
extern int Physics25Data71908View2 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25Player130View2 __asm__("D_80070328+0x130");
extern int Physics25Player144View4 __asm__("D_80070328+0x144");
extern short Physics25Player148View3 __asm__("D_80070328+0x148");
extern short Physics25Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics25Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics25Player150View2 __asm__("D_80070328+0x150");
extern int Physics25Player154View2 __asm__("D_80070328+0x154");
extern int Physics25Player160View2 __asm__("D_80070328+0x160");
extern int Physics25Player48View2 __asm__("D_80070328+0x48");
extern int Physics25Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics25Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics25Player60View4 __asm__("D_80070328+0x60");
extern int Physics25Player64View4 __asm__("D_80070328+0x64");
extern int Physics25Player8View4 __asm__("D_80070328+0x8");
extern int Physics25Player88View4 __asm__("D_80070328+0x88");
extern int Physics25Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics25Player90View2 __asm__("D_80070328+0x90");
extern int Physics25Player94View6 __asm__("D_80070328+0x94");
extern int Physics25PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics25PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics25PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics25PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics25Player148View4 __asm__("D_80070328+0x148");
extern int Physics25Player210View4 __asm__("D_80070328+0x210");
extern int Physics25Player220View2 __asm__("D_80070328+0x220");
extern int Physics25Player98View2 __asm__("D_80070328+0x98");
extern int Physics25PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics25PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics25PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics25PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics25PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics25PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics25Call363DCView8() __asm__("func_800363DC");
int Physics25Call40D10View10() __asm__("func_80040D10");
int Physics25Call40F48View6() __asm__("func_80040F48");
int Physics25Call410F8View6() __asm__("func_800410F8");
int Physics25Call41404View4() __asm__("func_80041404");
int Physics25Call41580View10() __asm__("func_80041580");
int Physics25Call416F4View10() __asm__("func_800416F4");
int Physics25Call417FCView10() __asm__("func_800417FC");
int Physics25Call41848View8() __asm__("func_80041848");
int Physics25Call41B64View10() __asm__("func_80041B64");
int Physics25Call4E9E4View10() __asm__("func_8004E9E4");
int Physics25Call4EA2CView10() __asm__("func_8004EA2C");
int Physics25Call4ED6CView8() __asm__("func_8004ED6C");
int Physics25Call4EDE8View10() __asm__("func_8004EDE8");
int Physics25Call4F08CView10() __asm__("func_8004F08C");
int Physics25Call4F110View6() __asm__("func_8004F110");
int Physics25Call4F168View10() __asm__("func_8004F168");
int Physics25Call4F178View10() __asm__("func_8004F178");
int Physics25Call4F194View10() __asm__("func_8004F194");
int Physics25Call4F1C8View10() __asm__("func_8004F1C8");
int Physics25CallRandView8() __asm__("rand");
extern unsigned char Physics25Data658A0View10 __asm__("D_800658A0");
extern unsigned char Physics25Data65920View10 __asm__("D_80065920");
extern int Physics25Data6763CView4 __asm__("D_8006763C");
extern int Physics25Data67640View4 __asm__("D_80067640");
extern int Physics25Data67644View4 __asm__("D_80067644");
extern int Physics25Data6C514View6 __asm__("D_8006C514");
extern int* Physics25Data6C570View8 __asm__("D_8006C570");
extern int Physics25Data6C640View10 __asm__("D_8006C640");
extern int Physics25Data6E044View10 __asm__("D_8006E044");
extern int Physics25Data6E344View6 __asm__("D_8006E344");
extern int Physics25Data6E538View8 __asm__("D_8006E538");
extern unsigned char Physics25Data6E548View10 __asm__("D_8006E548");
extern unsigned char Physics25Player0View10 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics25Player8CView4 __asm__("D_80070328+0x8C");
extern int Physics25PlayerB4View2 __asm__("D_80070328+0xB4");
extern int Physics25Player158View2 __asm__("D_80070328+0x158");
extern int Physics25Player20CView4 __asm__("D_80070328+0x20C");
extern int Physics25Player148View5 __asm__("D_80070328+0x148");
void func_level_25_800870B4(int slotIndex) {
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
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74;
    }
    originalFrame;
    register void *globalVector80 __asm__("$16");
    register int workWord3 __asm__("$3");
    register void *globalField4CPointer __asm__("$16");
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    int raw21_temp_a0_7;
    int raw21_temp_a1_4;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex=slotIndex;
    workWord2=savedSlotIndex*16;
    globalPointer=&Physics25Data6E548View6;
    stateSelector4=Physics25Field(&Physics25Player0View6,int*,0x48);
    __asm__("":"=r"(globalPointer):"0"(globalPointer),"r"(stateSelector4),"r"(workWord2));
    workWord2+=(int)globalPointer;
    Physics25Data6C570View5=(void*)workWord2;
    switch(stateSelector4){
        default:return;
    case 53:case 54:globalVector80 = &Physics25Player0View6 + 0x80;
        Physics25Call4F168View6(globalVector80);
        Physics25Call4F168View6(globalVector80 + 0xC);
        if (Physics25Data6E044View6 != 7) {
            Physics25Call40D10View6(0x1200);
            Physics25Call416F4View6();
            Physics25Call41580View6(0x5A, 0x10);
            return;
        }
        return;
    case 25:Physics25Call40F48View4(&originalFrame.sp10,1);
        workWord2=originalFrame.sp10;
        call4=&Physics25PlayerA8View3;
        workWord2>>=1;
        Physics25Field(call4,int*,0)=workWord2;
        workWord2=workWord2<-25;
        if(workWord2){
            workWord2=-25;
            Physics25Field(call4,int*,0)=workWord2;
        }
        workWord2=Physics25Field(call4,int*,0);
        workWord2=workWord2<26;
        if(!workWord2){
            workWord2=25;
            Physics25Field(call4,int*,0)=workWord2;
        }
        call4=(void*)Physics25Field(call4,int*,0);
        Physics25Call41404View3(call4);
        Physics25Call417FCView7(576,384);
        workWord2=Physics25Call4EA2CView7(Physics25Player64View3);
        workWord3=Physics25PlayerB0View3;
        lowProduct0=workWord3*workWord2;
        call4=(void*)Physics25Player64View3;
        workWord2=lowProduct0>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics25Player80View2=workWord2;
        workWord2=Physics25Call4E9E4View7(call4);
        workWord3=Physics25PlayerB0View3;
        lowProduct1=workWord3*workWord2;
        workWord2=Physics25Player94View5;
        Physics25Player88View3=workWord2;
        workWord2=lowProduct1>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics25Player84View2=workWord2;
        Physics25Call41B64View7();
        workWord2=Physics25Player144View3;
        workWord2+=12;
        Physics25Player144View3=workWord2;
        workWord2=workWord2<193;
        if(!workWord2){
            workWord2=192;
            Physics25Player144View3=workWord2;
        }
        workWord2=Physics25Player94View5;
        workWord3=Physics25Player144View3;
        workWord2-=workWord3;
        Physics25Player94View5=workWord2;
        workWord2=workWord2<-8960;
        clamp19:__asm__ volatile(""::"i"(0x80087298):"memory");
        if(!workWord2)return;
        workWord2=-8960;
        Physics25Player94View5=workWord2;
        return;
    case 33:case 34:case 35:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta18 __asm__("$18");
            register int delta19 __asm__("$19");
            register void *pointer17 __asm__("$17");
            register void *pointer16 __asm__("$16");
            register int limit16 __asm__("$16");
            int originalLow;
            call4=&originalFrame.sp18;
            __asm__ volatile(""::"r"(call4):"memory");
            pointer17=&Physics25Player154View2;
            Physics25Call410F8View5(call4,pointer17,0);
            workWord2=originalFrame.sp1C;
            numeric4=Physics25Player94View6;
            workWord2=-workWord2;
            workWord3=workWord2*5;
            workWord3<<=2;
            delta18=workWord3>>7;
            numeric4>>=3;
            workWord3=originalFrame.sp18;
            numeric4-=1024;
            originalFrame.sp28=numeric4;
            workWord2=workWord3*5;
            workWord2<<=2;
            delta19=workWord2>>7;
            if(numeric4<0){
                pointer16=&originalFrame.sp20;
                call4=pointer16;
                call5=pointer16;
                __asm__ volatile("":"=r"(pointer17):"0"(pointer17),"r"(call4),"r"(call5):"memory");
                pointer17-=340;
                call6=pointer17;
                workWord2=Physics25Player8CView3;
                workWord3=Physics25Player90View2;
                workWord2>>=3;
                workWord3>>=3;
                originalFrame.sp20=workWord2;
                originalFrame.sp24=workWord3;
                Physics25Call4F194View9(call4,call5,call6);
                if(!Physics25Call13E38View2(pointer17,pointer16,2)){
                    workWord2=Physics25Player8View4;
                    workWord3=Physics25Data71908View2;
                    workWord2-=workWord3;
                    workWord2>>=3;
                    originalFrame.sp1C=workWord2;
                    workWord2=workWord2<11;
                    if(!workWord2)originalFrame.sp1C=10;
                    __asm__ volatile("":::"memory");
                    workWord2=originalFrame.sp1C;
                    delta18+=workWord2;
                }
            }
            workWord2=Physics25PlayerF8View4;
            workWord3=Physics25Player8View4;
            workWord3=workWord2-workWord3;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3<4096;
            if(workWord2){
                workWord2=workWord3*3;
                workWord2<<=3;
                workWord2+=workWord3;
                workWord2<<=5;
                workWord3=Physics25Player60View4;
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
            call4=&Physics25Player64View4;
            workWord2=Physics25Field(call4,int*,0);
            workWord3=Physics25Player60View4;
            Physics25PlayerA8View4=delta19;
            workWord2+=delta19;
            workWord2&=4095;
            workWord3+=delta18;
            workWord3&=4095;
            Physics25Field(call4,int*,0)=workWord2;
            workWord2=workWord3<2049;
            Physics25Player60View4=workWord3;
            if(!workWord2){
                workWord2=workWord3-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics25Player60View4=workWord2;
            }
            workWord2=Physics25Player60View4;
            workWord2=workWord2<-800;
            if(workWord2)Physics25Player60View4=-800;
            workWord2=Physics25Player60View4;
            workWord2=workWord2<801;
            if(!workWord2)Physics25Player60View4=800;
            workWord2=Physics25Data6FA38View2;
            if(workWord2>=0)goto nonnegative33;
            workWord3=Physics25Player60View4;
            if(workWord3>=0)goto positive33;
            numeric4=Physics25Data67634View2;
            workWord2=Physics25Data67630View2;
            workWord2=numeric4-workWord2;
            goto quotient33;
            positive33:if(workWord3<=0)goto zero33;
            workWord2=Physics25Data67638View2;
            numeric4=Physics25Data67634View2;
            workWord2-=numeric4;
            quotient33:workWord2=workWord3*workWord2;
            workWord3=workWord2/800;
            numeric4+=workWord3;
            Physics25PlayerACView4=numeric4;
            goto modifier33;
            zero33:workWord2=Physics25Data67634View2;
            Physics25PlayerACView4=workWord2;
            modifier33:speed33:call5=&Physics25Player144View4;
            workWord2=Physics25PlayerACView4;
            numeric4=Physics25PlayerB0View4;
            workWord3=Physics25Field(call5,int*,0);
            workWord2-=numeric4;
            workWord2-=workWord3;
            workWord2=(workWord2<<6)>>6;
            workWord3+=workWord2;
            Physics25Field(call5,int*,0)=workWord3;
            workWord3>>=6;
            numeric4+=workWord3;
            Physics25PlayerB0View4=numeric4;
            numeric4=numeric4<2048;
            if(numeric4)Physics25PlayerB0View4=2048;
            workWord2=Physics25PlayerB0View4;
            workWord2=workWord2<19201;
            if(!workWord2)Physics25PlayerB0View4=19200;
            goto rotation33;
            nonnegative33:numeric4=Physics25Player8View4;
            limit16=0;
            workWord2=Physics25Call4E4E4View2(numeric4);
            workWord3=Physics25Player148View3;
            __asm__ volatile(""::"r"(workWord3),"r"(workWord2):"memory");
            numeric4=workWord2;
            __asm__("":"=r"(numeric4):"0"(numeric4));
            Physics25PlayerACView4=numeric4;
            numeric5=workWord3;
            if(!workWord3)goto zeroCounter33;
            workWord2=0x60000;
            Physics25Player130View2=workWord2;
            workWord2=numeric5-1;
            Physics25Player148View3=workWord2;
            workWord2<<=16;
            if(workWord2>0)goto positiveCounter33;
            workWord3=Physics25PlayerB0View4;
            workWord2=workWord3-numeric4;
            workWord2=workWord2<192;
            if(workWord2){
                workWord2=numeric4+8192;
                Physics25PlayerB0View4=workWord2;
                Physics25Player148View3=0;
                goto counterClamp33;
            }
            workWord2=workWord3-192;
            Physics25PlayerB0View4=workWord2;
            workWord2=1;
            Physics25Player148View3=workWord2;
            goto counterClamp33;
            positiveCounter33:workWord2=numeric4+8192;
            Physics25PlayerB0View4=workWord2;
            limit16=96;
            goto counterClamp33;
            zeroCounter33:Physics25PlayerB0View4=numeric4;
            __asm__ volatile("":"=r"(limit16):"0"(limit16):"$3","memory");
            Physics25Player130View2=0;
            counterClamp33:globalPointer=&Physics25PlayerB0View4;
            workWord2=Physics25Field(globalPointer,int*,0);
            workWord2=workWord2<22785;
            if(!workWord2)Physics25Field(globalPointer,int*,0)=22784;
            workWord2=Physics25Field(globalPointer,int*,0);
            workWord2=workWord2<2048;
            if(workWord2)Physics25Field(globalPointer,int*,0)=2048;
            numeric5=Physics25Player14CView4;
            workWord3=Physics25Player150View2;
            workWord2=limit16-numeric5;
            workWord2<<=4;
            numeric4=workWord3<<5;
            workWord2-=numeric4;
            workWord2>>=6;
            workWord3+=workWord2;
            Physics25Player150View2=workWord3;
            workWord3>>=4;
            numeric5+=workWord3;
            Physics25Player14CView4=numeric5;
            if(numeric5<0)Physics25Player14CView4=0;
            workWord2=Physics25Player14CView4;
            workWord2=workWord2<97;
            if(!workWord2)Physics25Player14CView4=96;
            rotation33:workWord2=Physics25Player148View3;
            workWord2=workWord2<2;
            if(workWord2)goto spring33;
            workWord3=Physics25Player14AView2;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3*3;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            workWord3=Physics25Player5CView4;
            workWord2<<=11;
            Physics25Player154View2=workWord2;
            workWord2>>=6;
            workWord3+=workWord2;
            workWord3&=4095;
            workWord2=workWord3<2049;
            Physics25Player5CView4=workWord3;
            if(workWord2)goto rotationDone33;
            workWord2=workWord3-4096;
            goto storeAngle33;
            spring33:workWord2=Physics25Call4EA2CView9(Physics25Player60View4);
            workWord2<<=5;
            workWord2=-workWord2;
            originalLow=delta19*workWord2;
            workWord3=Physics25Player154View2;
            numeric5=Physics25Player5CView4;
            workWord2=(workWord3<<4)>>6;
            numeric4=originalLow>>12;
            numeric4-=workWord2;
            workWord2=(numeric5<<6)>>6;
            numeric4-=workWord2;
            workWord3+=numeric4;
            Physics25Player154View2=workWord3;
            workWord3>>=6;
            numeric5+=workWord3;
            numeric5&=4095;
            workWord2=numeric5<2049;
            Physics25Player5CView4=numeric5;
            if(workWord2)goto rotationDone33;
            workWord2=numeric5-4096;
            storeAngle33:Physics25Player5CView4=workWord2;
            rotationDone33:Physics25Call41848View7();
            call5=&Physics25Player4CView4;
            numeric4=Physics25Field(call5,int*,0);
            if(numeric4)goto active33;
            workWord2=(int)Physics25Data6C570View5;
            workWord2=Physics25Field((void*)workWord2,int*,4)&64;
            if(!workWord2)goto end33;
            workWord2=Physics25PlayerF8View4;
            workWord3=Physics25Player8View4;
            workWord2-=512;
            workWord3=workWord3<workWord2;
            if(!workWord3)goto end33;
            workWord3=Physics25Player48View2;
            workWord2=33;
            if(workWord3!=workWord2)goto end33;
            workWord2=1;
            Physics25Field(call5,int*,0)=workWord2;
            __asm__ volatile("":::"$4","memory");
            Physics25Player160View2=0;
            goto end33;
            active33:workWord2=Physics25Player8View4;
            workWord3=Physics25PlayerF8View4;
            workWord2=workWord2<workWord3;
            if(workWord2){
                workWord2=1;
                goto activeRemainder33;
            }
            workWord2=1;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics25Field(call5,int*,0)=0;
            goto end33;
            activeRemainder33:if(numeric4!=workWord2)goto decline33;
            workWord2=Physics25Player160View2;
            workWord2+=512;
            Physics25Player160View2=workWord2;
            workWord2=workWord2<6144;
            if(!workWord2){
                workWord2=6144;
                Physics25Player160View2=workWord2;
                workWord2=2;
                Physics25Field(call5,int*,0)=workWord2;
            }
            goto add88;
            decline33:workWord2=Physics25Player160View2;
            workWord2-=256;
            Physics25Player160View2=workWord2;
            if(workWord2<=0){
                Physics25Player160View2=0;
                Physics25Field(call5,int*,0)=0;
            }
            add88:{
                register void *pointer2 __asm__("$2");
                pointer2=&Physics25Player88View4;
                workWord3=Physics25Field(pointer2,int*,0);
                numeric4=Physics25Player160View2;
                workWord3+=numeric4;
                Physics25Field(pointer2,int*,0)=workWord3;
            }
            end33:Physics25Call41B64View9();
            return;
        }
    case 43:case 44:globalField4CPointer=&Physics25Player4CView3;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics25Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3!=workWord2)goto continue43;
        block_154:Physics25Call4F168View10(globalField4CPointer+52);
        Physics25Call4F168View10(globalField4CPointer+64);
        return;
        continue43:workWord2=7;
        workWord3=Physics25Data6E044View10;
        if (workWord3 == workWord2) {
            Physics25Field(&Physics25Player0View10, int *, 0xB0) = 0;
        }
        else {
            Physics25Call40D10View10(0x980);
            raw21_var_v0_2 = Physics25Call41580View10(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics25Field(&Physics25Player0View10, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics25Field(&Physics25Player0View10, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics25Call417FCView10(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics25Player0View10 + 0xB0;
        if (Physics25Field(&Physics25Player0View10, int *, 0xB0) != 0) {
            Physics25Call41848View8();
            Physics25Call41B64View10();
            Physics25Field(&Physics25Player0View10, int *, 0x94) = 0;
        }
        else {
            Physics25Call4F168View10(raw21_temp_s0_11 - 0x30);
            Physics25Call4F168View10(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics25Player0View10 + 0x28;
            if (Physics25Field(&Physics25Player0View10, int *, 0x28) < 0) {
                if ((Physics25Field(&Physics25Player0View10, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics25Data6C640View10 & 1)) {
                    Physics25Call4F178View10(&originalFrame.sp30, raw21_temp_s4 - 0x28);
                    originalFrame.sp44 = 0x40;
                    originalFrame.sp48 = 0;
                    originalFrame.sp40 = (int) Physics25Field(&Physics25Player0View10, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp44 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics25Call4ED6CView8(raw21_temp_s2_3, &originalFrame.sp40, &originalFrame.sp50);
                    Physics25Call4F194View10(&originalFrame.sp30, &originalFrame.sp30, &originalFrame.sp50);
                    originalFrame.sp40 = 0;
                    originalFrame.sp38 = -Physics25Field(&Physics25Player0View10, int *, 0x28);
                    Physics25Call4ED6CView8(raw21_temp_s2_3, &originalFrame.sp40, &originalFrame.sp40);
                    Physics25Call4F110View6(&originalFrame.sp40, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp30, &originalFrame.sp40);
                    if (!(Physics25CallRandView8() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp30, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics25Player0View10 + 0xB0;
                    if ((Physics25Field(&Physics25Player0View10, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics25Data6C640View10 & 7) && !(Physics25CallRandView8() & 3)) {
                        originalFrame.sp60 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp64 = 0;
                        originalFrame.sp68 = 0;
                        Physics25Call4ED6CView8(raw21_temp_s1_7 - 0x80, &originalFrame.sp60, &originalFrame.sp60);
                        Physics25Call4F194View10(&originalFrame.sp60, &originalFrame.sp60, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp68 = -Physics25Field(&Physics25Player0View10, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp60, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics25Field(&Physics25Player0View10, int *, 0x144) - ((int) ((Physics25Field(&Physics25Player0View10, int *, 0x148) * 2) + (Physics25Field(&Physics25Player0View10, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics25Field(&Physics25Player0View10, int *, 0x148) + raw21_temp_a1_4;
        Physics25Field(&Physics25Player0View10, int *, 0x144) = raw21_temp_a1_4;
        Physics25Field(&Physics25Player0View10, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics25Field(&Physics25Player0View10, int *, 0x148) = 0x5900;
        }
        if (Physics25Field(&Physics25Player0View10, int *, 0x148) < -0x5900) {
            Physics25Field(&Physics25Player0View10, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 55:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            globalVector80=&Physics25Player80View2;
            Physics25Call4F168View7(globalVector80);
            Physics25Call4F168View7(globalVector80+12);
            numeric5=Physics25Player148View5;
            numeric4=Physics25Player144View3;
            workWord3=numeric5<<1;
            workWord2=numeric4*5;
            workWord2<<=2;
            workWord3+=workWord2;
            workWord3>>=8;
            numeric4-=workWord3;
            numeric5+=numeric4;
            Physics25Player144View3=numeric4;
            Physics25Player148View5=numeric5;
            return;
        }
    case 61:Physics25Call40F48View4(&originalFrame.sp50,1);
        workWord3=originalFrame.sp50;
        workWord2=workWord3*25;
        call4=(void*)(workWord2>>7);
        if(call4)goto nonzero61;
        __asm__ volatile("":::"$4");
        Physics25PlayerA8View3=0;
        goto approach61;
        nonzero61:if((int)call4>=0)goto positive61;
        globalPointer=&Physics25PlayerA8View3;
        workWord2=Physics25Field(globalPointer,int*,0);
        if(workWord2>0)Physics25Field(globalPointer,int*,0)=0;
        goto approach61;
        positive61:globalPointer=&Physics25PlayerA8View3;
        workWord2=Physics25Field(globalPointer,int*,0);
        if(workWord2<0)Physics25Field(globalPointer,int*,0)=0;
        approach61:call5=&Physics25PlayerA8View3;
        workWord3=Physics25Field(call5,int*,0);
        workWord2=workWord3<(int)call4;
        if(workWord2){
            workWord2=workWord3+3;
            Physics25Field(call5,int*,0)=workWord2;
            workWord2=(int)call4<workWord2;
            goto clamp61;
        }
        workWord2=workWord3-3;
        Physics25Field(call5,int*,0)=workWord2;
        workWord2=workWord2<(int)call4;
        clamp61:if(workWord2)Physics25Field(call5,int*,0)=(int)call4;
        call4=(void*)Physics25PlayerA8View3;
        Physics25Call41404View3(call4);
        workWord3=Physics25Player60View3;
        workWord2=workWord3<2049;
        if(!workWord2){
            workWord2=workWord3-4096;
            Physics25Player60View3=workWord2;
            __asm__ volatile("":::"memory");
            workWord3=Physics25Player60View3;
        }
        if(workWord3>=0)goto nonnegative61;
        call4=(void*)Physics25Data67640View3;
        workWord2=Physics25Data6763CView3;
        workWord2=(int)call4-workWord2;
        goto quotient61;
        nonnegative61:if(workWord3<=0)goto zero61;
        workWord2=Physics25Data67644View3;
        call4=(void*)Physics25Data67640View3;
        workWord2-=(int)call4;
        quotient61:workWord2=workWord3*workWord2;
        workWord3=workWord2/352;
        call4+=workWord3;
        Physics25PlayerACView3=(int)call4;
        goto update61;
        zero61:workWord2=Physics25Data67640View3;
        Physics25PlayerACView3=workWord2;
        update61:Physics25Call417FCView7(576,384);
        Physics25Call41848View5();
        call6=&Physics25PlayerFCView3;
        workWord2=Physics25Field(call6,unsigned char*,0);
        if(workWord2)goto field94FromA0;
        workWord2=Physics25PlayerB8View3;
        call4=call6-112;
        if(!workWord2)goto vectorCommit61;
        field94FromA0:workWord2=Physics25PlayerA0View3;
        workWord2-=192;
        Physics25Player94View5=workWord2;
        return;
        vectorCommit61:call5=call6-124;
        Physics25Call4F194View7(call4,call5,call6-20);
        return;
    }
}
#undef Physics25Field


extern Spyro Callback25Player __asm__("D_80070328");
int Callback25_80037058(int x, int y) __asm__("func_80037058");
int Callback25_8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback25_80041930(void) __asm__("func_80041930");
void Callback25_80041AE8(void) __asm__("func_80041AE8");
void Callback25_80041C20(void) __asm__("func_80041C20");
void Callback25_80042A44(void) __asm__("func_80042A44");
void Callback25_80043A38(int scale) __asm__("func_80043A38");
void Callback25_80049590(void) __asm__("func_80049590");
void Callback25_8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback25_8006E344 __asm__("D_8006E344");
extern int Callback25_8006E52C __asm__("D_8006E52C");
extern int Callback25_8006E530 __asm__("D_8006E530");
extern int Callback25_8006E538 __asm__("D_8006E538");

/* AI-generated; not human reviewed. Original numeric callback and byte addresses. */
void func_level_25_80087F34(void) {
    struct { Vector3D value; int reserved[2]; } local;
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    unsigned char *sourceBytes;
    int value;
    register int iteration __asm__("$16");
    register int iterationLimit __asm__("$17");

    switch (Callback25Player.animationState) {
    case 0x35:
    case 0x36:
        Callback25_80041C20();
        Callback25_80042A44();
block_3:
        Callback25Player.unk4[0]  =  0;
        return;
    case 0x19:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80041930();
        Callback25_80049590();
        if ((Callback25Player.movementState == MOVEMENT_STATE_SUPERCHARGE) && (SpawnParticle != 0)) {
            SpawnParticle(1, 9, 0, 0);
        }
        if ((Callback25Player.unk7a[3].z < 0) && (Callback25Player.animationStateFrames >= 4)) {
            Callback25Player.unk5  =  1;
        } else if ((Callback25Player.unk5 == 0) && !(Callback25_8006E538 & 0x40)) {
            Callback25Player.unk5  =  2;
        }
        goto block_3;
    case 0x21:
    case 0x22:
    case 0x23:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80041930();
        if ((SpawnParticle != 0) && (Callback25Player.union144.b.unk148 != 0)) {
            iterationLimit  =  1;
            if (Callback25Player.union144.b.unk148 >= 2) {
                iterationLimit  =  2;
            }
            iteration  =  0;
            if (iterationLimit != 0) {
                sourceBytes  =  (unsigned char*)&Callback25Player.union144.a.unk13cc - 0xB0;
                do {
                    func_8004F178(&local.value, (Vector3D *) sourceBytes);
                    Callback25_8004F110(&local.value, 7);
                    iteration +=  1;
                    sample = rand();
                    component = local.value.x;
                    sample&= 254;
                    component-= 127;
                    component  =  component + sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.value.x  =  component;
                    sample = rand();
                    component = local.value.y;
                    sample&= 254;
                    component-= 127;
                    component  =  component + sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.value.y  =  component;
                    sample = rand();
                    kind = 1;
                    subtype = 23;
                    position = sourceBytes - 152;
                    vector = &local.value;
                    __asm__("" : "=r"(sample) : "0"(sample), "r"(kind), "r"(subtype), "r"(position), "r"(vector));
                    sample&= 254;
                    component = local.value.z;
                    component-= 127;
                    component = component + sample;

                    local.value.z = component;
                    SpawnParticle(kind, subtype, (Vector3D*)position, vector);
                } while (iteration < iterationLimit);
            }
        }
        goto block_3;
    case 0x2B:
    case 0x2C:
    case 0x37:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80041AE8();
        if ((unsigned char) Callback25Player.unk10[4] != 0) {
            value  =  -Callback25Player.unk9ha[4] - Callback25_80037058(Callback25Player.position.x, Callback25Player.position.y);
            Callback25Player.unk4[0]  =  value;
            Callback25Player.position.z  =  (Callback25Player.unk4a - value) - ((int) Callback25Player.union144.a.unk13cc >> 6);
            return;
        }
    default:
        return;
    case 0x3D:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80043A38(0xC00);
        Callback25_80049590();
        if (SpawnParticle != 0) {
            SpawnParticle(1, 9, 0, 0);
        }
        Callback25_8006E530  =  0x78;
        Callback25Player.unk4[0]  =  0;
        Callback25_8006E52C  =  4;
        if ((Callback25_8006E344 == 0) && (Callback25_8003BF6C((int) D_8006C654->supercharge, Callback25Player.unk22[2]) == 0)) {
            Callback25Player.unk22[2]  =  PlaySound((int) D_8006C654->supercharge, 0, 4);
            Callback25Player.unk22[3]  =  (int) D_8006C654->supercharge;
        }
        break;
    }
}


#define LEVEL_ID 25
#define PlaySpyroSounds_level_25 func_level_25_800882C4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_25_800883CC(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x2B: case 0x2C: case 0x35: case 0x36: case 0x37: case 0x3D:
        func_80043ABC(&spyro.unk9e);break;
    case 0x19:
        func_80043E00((Vector3D*)((char*)&spyro+0x8C));break;
case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2d: case 0x2e: case 0x2f: case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80088454.
 * Reuses verified10 fly clamp800/4B00 and23 surface stack10; original25
 * selectors19/37 share the original sound call after19, selector3D preserves
 * word170 reload and selector<A0 pointer clearing. Offsets are bytes. Exact
 * code/internal jumps/owned dispatch words, complete TU and every retail hash
 * required. Helpers, physical units, audio meaning, cadence and live parity open.
 * Clamp vectors7FF/800/4B00/4B01 yield800/800/4B00/4B00 before later helpers.
 */
extern Spyro Transition25Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw25Word __asm__("D_80070328+0x50");
extern unsigned char Raw25State[] __asm__("D_80070328+0x50");
extern unsigned char Raw25Union[] __asm__("D_80070328+0x144");
extern int Raw25Spit __asm__("D_80070328+0x170");
void Call25_8004F168(Vector3D*) __asm__("func_8004F168");
int Call25_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call25A358(Vector3D*,int) __asm__("func_8001A358");
void Call25_800441F0(void) __asm__("func_800441F0");
void Call25_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_25_80088454(int arg0) {
    Vector3D surfaceVector;
    int vectorLength;
    int surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");

    switch (arg0) {
    case 0x35:
    case 0x36:
        Transition25Player.movementState = MOVEMENT_STATE_STAND;
        Transition25Player.unk5 = 0;
        Call25_800441F0();
        Transition25Player.grounded = 1;
        goto clearPointers;
    case 0x19:
        soundZero=0;
        __asm__("" : "=r"(soundZero) : "0"(soundZero));
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition25Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition25Player.unk13a[0] = 0x60000;
        Transition25Player.unk5 = 0;
        Transition25Player.union144.a.unk13cb = 0;
        Transition25Player.grounded = 0;
        Transition25Player.unk15b = 1;
        soundSelector = soundTable[0x22];
playSharedSound:
        PlaySound((int) soundSelector, (Moby*)soundZero, 0);
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Raw25Word;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition25Player.unk5=0;
            Call25_8004F168((Vector3D*)(flyState+0x104));
            Transition25Player.union144.a.unk13db.y=0;
            vectorLength=Call25_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition25Player.unk8[0]=vectorLength;
            if(vectorLength<0x800)Transition25Player.unk8[0]=0x800;
            if(Transition25Player.unk8[0]>=0x4B01)Transition25Player.unk8[0]=0x4B00;
            Transition25Player.union144.a.unk13cb=0;
            Transition25Player.union144.b.unk148=0;
            Transition25Player.union144.a.unk13ce.x=0;
            Transition25Player.union144.a.unk13ce.y=0;
            Transition25Player.grounded=0;
            Transition25Player.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2B:case 0x2C: {
        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw25Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw25Union;
            *(int*)unionPointer=(-Transition25Player.unk7a[2].z)>>2;
            if(Raw25Word!=8){Transition25Player.union144.a.unk13cc=0x5900;Raw25Word=10;}
            Transition25Player.unk5=0;
            Transition25Player.unk8[0]=Call25_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition25Player.grounded=1;
            Transition25Player.unk15b=1;
            func_8004F178(&surfaceVector,(Vector3D*)(unionPointer-0x144));
            surfaceVector.z+=0x400;
            surfaceResult=Call25A358(&surfaceVector,0x800);
            surfaceVector.z=surfaceResult;
            if(surfaceResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&surfaceVector,0);SpawnParticle(6,0x2E,&surfaceVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x37:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw25Word=originalZ;
        __asm__ volatile("" : : : "memory");
        originalZ=Transition25Player.unk7a[2].z;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        {register int flagValue __asm__("$3")=1;
        __asm__("" : "=r"(flagValue) : "0"(flagValue));
        Transition25Player.unk15b=flagValue;
        __asm__ volatile("" : : : "memory");}
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition25Player.union144.a.unk13cc = 0;
        Transition25Player.unk5 = 0;
        Transition25Player.grounded = 0;
        __asm__ volatile("" : "=r"(originalZ) : "0"(originalZ) : "memory");
        Transition25Player.union144.a.unk13cb = -originalZ >> 2;
        soundSelector = soundTable[7];
        soundZero=0;
        goto playSharedSound;
    case 0x3D:
        stateBase=Raw25State;
        *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
        Transition25Player.unk5 = 0;
        Transition25Player.unk13a[0] = 0x60000;
        Transition25Player.unk8[0] = Call25_8004EDE8((Vector3D *) (stateBase + 0x48), 0);
        Transition25Player.horizontalSpeed = 0x1E80;
        Call25_80043A38(0xC00);
        Transition25Player.grounded = 1;
        if ((Transition25Player.unk13f[0] != 0) || (Transition25Player.spitState != 0) || (Transition25Player.unk17t != 6)) {
            spitWord=&Raw25Spit;
            if (((unsigned) (*spitWord - 3) < 2U) || (*spitWord == 5)) {
                *spitWord = 5;
            } else {
                *spitWord = 0;
            }
            Transition25Player.spitState = 0;
            Transition25Player.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition25Player.unk20a=0;
        Transition25Player.critterMobyPtr=0;
        return;
    }
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level25
 * 80088868: original677 instructions and37 dispatch words in sibling4839
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original25.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A25W48 __asm__("D_80070328 + 0x48");
extern int A25W4C __asm__("D_80070328 + 0x4C");
extern int A25W54 __asm__("D_80070328 + 0x54");
extern int A25WA0 __asm__("D_80070328 + 0xA0");
extern int A25WA8 __asm__("D_80070328 + 0xA8");
extern int A25WAC __asm__("D_80070328 + 0xAC");
extern int A25WB0 __asm__("D_80070328 + 0xB0");
extern int A25WB8 __asm__("D_80070328 + 0xB8");
extern int A25WCC __asm__("D_80070328 + 0xCC");
extern int A25WD0 __asm__("D_80070328 + 0xD0");
extern int A25WD4 __asm__("D_80070328 + 0xD4");
extern int A25W8C __asm__("D_80070328 + 0x8C");
extern int A25W90 __asm__("D_80070328 + 0x90");
extern int A25W94 __asm__("D_80070328 + 0x94");
extern int A25WE4 __asm__("D_80070328 + 0xE4");
extern int A25W144 __asm__("D_80070328 + 0x144");
extern int A25W158 __asm__("D_80070328 + 0x158");
extern int A25W1EC __asm__("D_80070328 + 0x1EC");
extern int A25W1F0 __asm__("D_80070328 + 0x1F0");
extern int A25W240 __asm__("D_80070328 + 0x240");
extern int A25W280 __asm__("D_80070328 + 0x280");
extern unsigned char A25B14 __asm__("D_80070328 + 0x14");
extern unsigned char A25B15 __asm__("D_80070328 + 0x15");
extern unsigned char A25B16 __asm__("D_80070328 + 0x16");
extern unsigned char A25B17 __asm__("D_80070328 + 0x17");
extern unsigned char A25B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A25BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A25B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A25B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A25Player[] __asm__("D_80070328");
extern unsigned char A25Table[] __asm__("D_80066530");
extern int A25Buttons __asm__("D_8006E538"),A25NewButtons __asm__("D_8006E53C");
extern int A25Mode __asm__("D_8006E044"),A25Gate __asm__("D_8006E344"),A25Count __asm__("D_8006C514");
extern int (*A25Callback)() __asm__("unk_ovlheader_80074374");
extern int A25W24 __asm__("D_80070328 + 0x24");
extern int A25W28C __asm__("D_80070328 + 0x28C");
extern int A25W290 __asm__("D_80070328 + 0x290");
extern int A25Surface __asm__("D_8006FA38");
extern unsigned char* A25SoundDesc __asm__("D_8006C654");
int A25Sound() __asm__("PlaySound");
int A25H3BF6C() __asm__("func_8003BF6C");
int A25H3BE70() __asm__("func_8003BE70");
int A25H40994() __asm__("func_80040994");
int A25H4BEF8() __asm__("func_8004BEF8");
int A25H49688() __asm__("func_80049688");
int A25H4F334() __asm__("func_8004F334");
int A25H498C0() __asm__("func_800498C0");
extern volatile int A25W20C __asm__("D_80070328 + 0x20C");
extern int A25W214 __asm__("D_80070328 + 0x214");
extern unsigned char A25B100 __asm__("D_80070328 + 0x100");
extern unsigned char A25E535 __asm__("D_8006E535");
extern unsigned char* A25Models __asm__("D_8006EE2C");
int A25H40BCC() __asm__("func_80040BCC");
int A25H1A310() __asm__("func_8001A310");
extern int A25W10C __asm__("D_80070328 + 0x10C");
extern int A25WB4 __asm__("D_80070328 + 0xB4");
extern int A25WA4 __asm__("D_80070328 + 0xA4");
extern int (*A25Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A25H40954() __asm__("func_80040954");
extern int A25W50 __asm__("D_80070328 + 0x50");
extern int A25WBC __asm__("D_80070328 + 0xBC"), A25W1BC __asm__("D_80070328 + 0x1BC"), A25W60 __asm__("D_80070328 + 0x60");
extern short A25H148 __asm__("D_80070328 + 0x148");
int A25H43194() __asm__("func_80043194");
int A25H4EDE8() __asm__("func_8004EDE8");
void func_level_25_80088868(void) {
 register int work2 __asm__("$2"),work3 __asm__("$3"),work4 __asm__("$4"),work5 __asm__("$5");
 register int* state __asm__("$16");
 register int* locomotion __asm__("$17");
 switch(A25W48){
 case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 36: case 37: case 38: case 39: case 40: case 41: case 42: case 45: case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 56: case 57: case 58: case 59: case 60: return;
 case 53: case 54:work2=A25H40994();work4=0;if(work2)return;goto call;

 case 25:
  if(A25H40BCC())return;
  if(A25B1B5 && (A25NewButtons&64))A25B1B6=1;
  if(A25WE4>=23){
   work3=A25W8C;work2=A25WCC;work4=work3*work2;
   work3=A25W90;work2=A25WD0;work3=work3*work2;
   work2=work4+work3;work4=14;if(work2<0)goto call;
  }
  work3=A25WB0;if(work3>=3201){work2=A25WB4*2;work2=work2<work3;work4=14;if(work2)goto call;}
  if(!A25WB8){work2=A25W54<5;work4=61;if(!work2)goto call;}
  if(A25B1B6){work2=A25W94;work4=17;if(work2>=0)return;goto call;}
  work2=A25W94;work4=22;if(work2>=0)return;goto call;
 case 33:

  if(A25H40994())return;
  locomotion=&A25WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A25WE4>=23)A25H4BEF8(7);
   if(A25WAC>0){
    work3=A25WB0;work2=work3<3841;if(!work2){__asm__ volatile("" ::: "memory");work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A25WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A25NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A25H43194(4);work4=47;if(work2)goto call;
  work2=A25WBC;work4=7;if(!work2)goto call;
  work2=A25W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A25H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  work2=A25H148<2;work4=35;if(!work2)goto call;
  work2=A25W4C;work4=34;if(work2)goto call;
  work3=A25W60;work2=work3<365;if(!work2)goto call;
  work2=work3< -364;work4=35;if(!work2)return;goto call;

 case 34:

  if(A25H40994())return;
  locomotion=&A25WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A25WE4>=23)A25H4BEF8(7);
   if(A25WAC>0){
    work3=A25WB0;work2=work3<3841;if(!work2){__asm__ volatile("" ::: "memory");work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A25WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A25NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A25H43194(4);work4=47;if(work2)goto call;
  work2=A25WBC;work4=7;if(!work2)goto call;
  work2=A25W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A25H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  work2=A25H148<2;work4=35;if(!work2)goto call;
  if(A25W60>=256)return;
  work2=A25W4C;work4=33;if(work2)return;goto call;

 case 35:

  if(A25H40994())return;
  locomotion=&A25WB8;__asm__("" : "=r"(locomotion):"0"(locomotion));
  if(!*locomotion){
   if(A25WE4>=23)A25H4BEF8(7);
   if(A25WAC>0){
    work3=A25WB0;work2=work3<3841;if(!work2){work4=3;goto call;}
    work2=work3<1921;__asm__("" : "=r"(work2):"0"(work2));work4=1;if(work2)goto call;
    __asm__ volatile("" ::: "memory");work4=2;goto call;
   }
   work2=A25WB0<1920;work4=0;if(work2)goto call;
   __asm__ volatile("" ::: "memory");work4=4;goto call;
  }
  state=&A25NewButtons;__asm__("" : "=r"(state):"0"(state));
  work2=*state&128;work4=22;if(work2)goto call;
  work2=A25H43194(4);work4=47;if(work2)goto call;
  work2=A25WBC;work4=7;if(!work2)goto call;
  work2=A25W1BC;work4=17;if(!work2)goto call;
  work2=*state&16;work4=18;if(work2)goto call;
  work4=(int)locomotion-32;work2=A25H4EDE8((void*)work4,1);work2=work2<1024;work4=7;if(work2)goto call;
  if(A25H148>=2)return;
  work2=A25W4C;work4=34;if(work2)goto call;
  work2=A25W60< -255;work4=33;if(work2)return;goto call;

 case 43: {
  register unsigned char* byte4 __asm__("$4");
  if(A25H40994())return;
  if((A25NewButtons&64) && A25W54>=9){work4=6;goto partialCall;}
  byte4=&A25B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto partialCall;}
  if(!(A25NewButtons&128))goto check44;
  if(A25W54<9)goto check44;
  work2=*(int*)(A25Models+220);byte4-=256;if(!work2)goto check44;
  work2=A25H1A310(byte4,1024,1,0);work4=40;
  if(work2)goto check44;goto call;
  partialCall:A25H4BEF8(work4);
  check44:work2=A25E535;work4=44;if(!work2)return;goto call;
 }
 case 44: {
  register unsigned char* byte4 __asm__("$4");
  register int (*callback2)() __asm__("$2");
  work3=A25W4C;work2=1;if(work3!=work2)goto other44;
  if(A25NewButtons&0x850)goto callback44;
  if(A25W54<61)return;
  callback44:callback2=A25Callback;__asm__("" : "=r"(callback2):"0"(callback2));
  if(!callback2)goto missingCallback;
  callback2();return;
  missingCallback:A25H498C0();return;
  other44:if(A25H40994())return;
  if((A25NewButtons&64) && A25W54>=9){work4=6;goto call;}
  byte4=&A25B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto call;}
  if(!(A25NewButtons&128))goto mode44;
  if(A25W54<9)goto mode44;
  work2=*(int*)(A25Models+220);byte4-=256;if(!work2)goto mode44;
  work2=A25H1A310(byte4,1024,1,0);work4=40;if(!work2)goto call;
  mode44:work3=A25Mode;work2=7;if(work3==work2)return;
  work2=A25E535;work4=43;if(work2)return;goto call;
 }
 case 55:
  if(A25W54<101)return;
  A25H4BEF8(44);work2=1;A25W4C=work2;work2=8;A25W50=work2;return;

 case 61:
  if(A25H40BCC())return;
  work2=1;__asm__("" : "=r"(work2):"0"(work2));state=&A25W4C;__asm__("" : "=r"(state):"0"(state));work3=*state;
  if(work3==work2){
   if(A25WB8>=4)goto partial25;
   work2=A25H40954(A25W10C);work3=9;if(work2==work3)goto finalSpeed;
   *state=0;goto finalSpeed;
  }
  if(A25Buttons&64){
   partial25:A25H4BEF8(25);work2=A25WB8;work3=3520;A25W94=work3;A25WB8=work2+1;return;
  }
  work2=A25WB8<4;work4=25;if(!work2)goto call;
  if(A25WE4>=23){
   work3=A25WCC;work2=A25W8C;work4=work3*work2;
   work3=A25WD0;work2=A25W90;work3=work3*work2;
   work2=work4+work3;work4=7;if(work2<0)goto call;
  }
  {
   register int* pointer4 __asm__("$4");
   pointer4=&A25W4C;__asm__("" : "=r"(pointer4):"0"(pointer4));
   work3=*pointer4;work2=2;if(work3==work2 && A25W54>=16)*pointer4=0;
  }
  if(A25Buttons&128)goto finalSpeed;
  work2=A25Surface;if(work2>=0)goto finalSpeed;
  work2=2;work3=A25W4C;work4=3;if(work3!=work2)goto call;
  finalSpeed:work3=A25WB0;work2=work3<3201;if(work2)return;
  work2=A25WB4*2;work2=work2<work3;work4=14;if(!work2)return;
  __asm__ volatile("" ::: "memory");
  call:__asm__ volatile("" ::: "memory");A25H4BEF8(work4);return;
 }
}
