#include "common.h"
#include "stdutil.h"
#include "hud.h"
#include "libgpu.h"
#include "drawutil.h"

INCLUDE_ASM("asm/nonmatchings/overlays/title/title1", func_title_80074DEC);

INCLUDE_ASM("asm/nonmatchings/overlays/title/title1", func_title_8007566C);

extern int D_8006C76C;
extern char* D_title_8007EEC0[];
void func_title_80077BC4(void) {
    DrawStringCentered(D_title_8007EEC0[D_8006C76C], 0x100, 0xD2, 2);
}

extern unsigned char D_title_8007F133;
extern unsigned short DecodedTitleSine[] __asm__("D_80065920");
void func_title_80077C04(void) {
    int frame, x, y;
    SpriteData* sprite;
    frame = D_8006C738[func_80027934(1103)].frame;
    sprite = (SpriteData*)(frame * sizeof(SpriteData) + (unsigned int)D_8006C788);
    y = D_title_8007F133;
    x = 256 - ((sprite->unk4 - sprite->unk0 + 1) >> 1);
    if ((unsigned int)y < 80) y -= 60;
    else if ((unsigned int)y < 112)
        y = (((int)(DecodedTitleSine[((y - 80) << 3) & 248] << 16)) >> 26) + 20;
    else if ((unsigned int)y < 144)
        y = (((int)(DecodedTitleSine[((y - 112) << 3) & 248] << 16)) >> 27) + 20;
    else y = 20;
    func_800289C8(&D_8006C788[frame], x, y);
}

INCLUDE_ASM("asm/nonmatchings/overlays/title/title1", func_title_80077CFC);

int func_8004F820(void*, void*, int);
int VSync(int);
void func_title_80078848(void* source, unsigned long* pixels, int y) {
    int index;
    RECT rectangle;
    for (index = 4; index < 16; index++) {
        int size = func_8004F820(source, pixels, (15 - index) * 2);
        VSync(0);
        rectangle.y = y - (size >> 11);
        rectangle.x = 0;
        rectangle.w = 0x200;
        rectangle.h = size >> 10;
        LoadImage(&rectangle, pixels);
        rectangle.y += 0xE4;
        LoadImage(&rectangle, pixels);
        DrawSync(0);
    }
}

/* AI generated; not human reviewed. Retail save/reset fields retain numeric labels. */
extern int D_8006C784,D_8006C3F8,D_8006C3FC,D_8006C5BC,D_8006C7B0,D_8006E4AC,D_8006C400,D_8006C5D0,D_8006C584,D_8006C7A8,D_8006C7C4,D_8006C70C,D_8006C710,D_8006C660,D_8006C71C;
extern unsigned char D_8006E50C,D_8007201C;
extern unsigned char ResetCheats[] __asm__("g_CheatFlags");
extern unsigned char D_800716AC[40][6],D_800715BC[40][6];
extern unsigned char D_80070300[],D_80071A10[],D_80071AB0[],D_80071FB0[],D_80071570[],D_8007145C[],D_8006C408[],D_80066EEC[];
extern short D_80066EAE[];
extern int ResetRecords[4][11] __asm__("speedwayRecords");
extern void ActivateSparxPowers(void);
void func_title_80078918(void) {
 register int i __asm__("$8")=0;
 register int offset __asm__("$2");
 register int one __asm__("$3");
 register int first __asm__("$2");
 register int lives __asm__("$2");
 register unsigned char* performance __asm__("$6")=&D_800716AC[0][0];
 register unsigned char* thresholds __asm__("$7")=&D_800715BC[0][0];
 lives=4;
 __asm__("" : "=r"(lives): "0"(lives));
 D_8006C784=lives;
 first=1;
 __asm__("" : "=r"(first): "0"(first): "$3");
 one=1;
 D_8006E50C=first;D_8007201C=first;
 D_8006C3F8=10;D_8006C3FC=10;D_8006C5BC=0;ResetCheats[2]=0;
 D_8006C7B0=one;D_8006E4AC=0x5FFF;D_8006C400=one;
 D_8006C5D0=0;D_8006C584=0;D_8006C7A8=0;D_8006C7C4=0;D_8006C70C=0;D_8006C710=0;
 do {
  register unsigned char* p __asm__("$3")=performance;
  register unsigned char* t __asm__("$4")=thresholds;
  register unsigned char* end __asm__("$5")=performance+6;
  do {*t++=0;*p++=0;}while((int)p<(int)end);
  performance+=6;thresholds+=6;
 }while(++i<40);
 D_8006C660=0;func_8004E790(D_80070300,0,40);
 D_8006C71C=0;func_8004E790(D_80071A10,0,160);
 func_8004E790(D_80071AB0,0,1280);
 func_8004E790(D_80071FB0,0,40);
 func_8004E790(D_80071570,0,76);
 func_8004E790(D_8007145C,0,40);
 func_8004E790(D_8006C408,0,8);
 func_8004E790(D_80066EEC,0,32);
 offset=44;do {*(short*)((char*)D_80066EAE+offset)=0;offset-=4;}while(offset>=0);
 {register int recordIndex __asm__("$4")=0;
 register int recordValue __asm__("$5")=36000;
 register int recordOffset __asm__("$3")=0;
 do {
  *(int*)((char*)ResetRecords+recordOffset+16)=0;*(int*)((char*)ResetRecords+recordOffset+20)=recordValue;
  *(int*)((char*)ResetRecords+recordOffset+28)=0;*(int*)((char*)ResetRecords+recordOffset+40)=recordValue;*(int*)((char*)ResetRecords+recordOffset+36)=0;
  recordOffset+=44;
 }while(++recordIndex<4);}
 ActivateSparxPowers();
}

