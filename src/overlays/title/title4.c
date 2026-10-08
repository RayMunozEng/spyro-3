#include "common.h"
#include "str.h"
#include "drawutil.h"
#include "hud.h"

void func_title_8007AA54(int y) {
    register int index __asm__("$2") = func_80027934(0x44D);
    register SpriteDefinition* definitions __asm__("$3");
    register int frame __asm__("$19");
    SpriteData* sprite;
    register int drawMode __asm__("$4");
    register int x __asm__("$16");
    register int width __asm__("$17");
    register int height __asm__("$18");
    index *= sizeof(SpriteDefinition);
    __asm__("" : "=r"(index) : "0"(index) : "$4");
    drawMode = 0x18;
    definitions = D_8006C738;
    __asm__("" : "=r"(definitions) : "0"(definitions), "r"(drawMode) : "$16");
    x = 0x100;
    frame = ((SpriteDefinition*)(index + (unsigned int)definitions))->frame;
    frame *= sizeof(SpriteData);
    sprite = (SpriteData*)(frame + (unsigned int)D_8006C788);
    width = sprite->unk4 - sprite->unk0 + 1;
    height = sprite->unk5 - sprite->unk1 + 1;
    __asm__("" : "=r"(width), "=r"(height) : "0"(width), "1"(height));
    __asm__("" : "=r"(x) : "0"(x), "r"(drawMode), "r"(sprite));
    x -= width >> 1;
    func_8001FABC(drawMode);
    func_8001FC90(x, x + width, y, y + height);
    func_800289C8((SpriteData*)((unsigned int)D_8006C788 + frame), x, y);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/title/title4", D_title_800746CC);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 three-slot routine.
 * Original options800780E0/title8007AB24 instructions and owned %d%% format.
 * Byte frame/colour stores, stride8 slots, stride900 numeric records and
 * signed sprite-width/height shifts retained. No save-layout meaning claim.
 * Selected and inputY copied once; original later helper does not reset Y.
 * Empty constraints emit no opcodes. Every code/local jump, format/padding,
 * strict complete TU and every original EXE/overlay SHA required.
 * Helpers, record semantics, physical units and live runtime remain open.
 */
static const char RawTitlePercentFormat[] __asm__("D_title_80074A34") = "%d%%";
extern unsigned char RawTitleSlots[] __asm__("D_title_8007F13C");
extern unsigned char RawTitleFrames[] __asm__("D_title_8007F13F");
extern unsigned char RawTitleFlags[] __asm__("D_title_8007F3D8");
extern unsigned char RawTitleSaves[] __asm__("D_title_8007F3D4");
extern int RawTitleTick __asm__("D_title_8007F134");
extern char* RawTitleNames[] __asm__("D_title_8007EECC");
extern int D_8006C76C;
int RawTitleSaveValue(unsigned char*) __asm__("func_title_8007928C");
void func_title_8007AB24(int selected,int inputY) {
 char buffer[32];
 register int selection __asm__("$22")=selected;
 register int row __asm__("$18");
 register int x __asm__("$17");
 register int y __asm__("$16");
 register int width __asm__("$19");
 register int slotOffset __asm__("$20");
 register int saveOffset __asm__("$21");
 register int textY __asm__("$23");
 unsigned char* slots;
 int index, frame, value;
 register int flag __asm__("$7");
 register int textX __asm__("$5");
 register char** nameEntry __asm__("$4");
 register char** namesBase __asm__("$3");
 register int temporaryV0 __asm__("$2");
 register int temporaryV3 __asm__("$3");
 register int temporaryA0 __asm__("$4");
 register SpriteData* sprite __asm__("$4");
 unsigned char* draw;
 char* text;
 __asm__("" : "=r"(selection) : "0"(selection));
 y=inputY;
 __asm__("" : "=r"(y) : "0"(y));
 index=func_80027934(1000);
 row=0;
 slots=RawTitleSlots;
 textY=y+20;
 saveOffset=0;
 __asm__("" : "=r"(textY) : "0"(textY));
 temporaryA0=(unsigned char)D_8006C738[index].frame;
 __asm__("" : "=r"(temporaryA0) : "0"(temporaryA0));
 sprite=(SpriteData*)((temporaryA0<<3)+(unsigned int)D_8006C788);
 temporaryV3=sprite->unk4;
 temporaryV0=sprite->unk0;
 __asm__("" : "=r"(temporaryV3),"=r"(temporaryV0) : "0"(temporaryV3),"1"(temporaryV0) : "$20");
 slotOffset=0;
 width=temporaryV3-temporaryV0;
 __asm__("" : "=r"(width) : "0"(width) : "memory");
 temporaryV3=width>>1;
 temporaryV0=256-temporaryV3;
 temporaryV0-=width;
 __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0));
 temporaryV3=sprite->unk5;
 temporaryA0=sprite->unk1;
 __asm__("" : "=r"(temporaryV3),"=r"(temporaryA0) : "0"(temporaryV3),"1"(temporaryA0));
 x=temporaryV0-32;
 temporaryV3=(temporaryV3-temporaryA0)>>1;
 y-=temporaryV3;
 do {
  frame=func_80028378((SpriteDefinition*)(slotOffset+(unsigned int)slots),0);
  RawTitleFrames[slotOffset]=frame;
  draw=(unsigned char*)func_800289C8(&D_8006C788[(unsigned char)frame],x,y);
  if(row==selection) {
   if((*(int*)(slots-8)&31)>=22) {
    draw[4]=64;
    draw[5]=64;
    draw[6]=64;
   }
   else func_80027934(1000);
   if(RawTitleFlags[saveOffset]) {
    __asm__("" : "=r"(selection) : "0"(selection));
 index=func_80027934(1000);
    func_800289C8(&D_8006C788[(unsigned char)D_8006C738[index].frame],x,y);
   }
  }
  value=RawTitleSaveValue(RawTitleSaves+saveOffset);
  if(value>=0) {
   sprintf(buffer,RawTitlePercentFormat,value);
   flag=0;
   temporaryV0=width>>1;
   __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0));
   textX=x+temporaryV0;
   if(selection==row) {
    temporaryV0=RawTitleTick&31;
    __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0));
    flag=temporaryV0<22;
   }
   text=buffer;
  } else {
   flag=0;
   temporaryV0=D_8006C76C;
   __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0) : "memory");
   namesBase=RawTitleNames;
   __asm__("" : "=r"(namesBase),"=r"(temporaryV0) : "0"(namesBase),"1"(temporaryV0));
   nameEntry=(char**)((temporaryV0<<2)+(unsigned int)namesBase);
   __asm__("" : "=r"(nameEntry) : "0"(nameEntry) : "memory");
   temporaryV0=width>>1;
   __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0));
   textX=x+temporaryV0;
   if(selection==row) {
    temporaryV0=RawTitleTick&31;
    __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0));
    flag=temporaryV0<22;
   }
   text=*nameEntry;
  }
  DrawStringCentered(text,textX,textY,flag|2);
  temporaryV0=x+32;
  __asm__("" : "=r"(temporaryV0) : "0"(temporaryV0));
  x=temporaryV0+width; saveOffset+=2304;
  row++;
  slotOffset+=8;
 }while(row<3);
}

extern int D_8006E53C;
extern int DecodedMenuFields[] __asm__("D_800725B0");
extern int D_800725DC, D_800725E0, D_800725B4, D_800725CC[];
int func_title_8007D218(int, int*, int*);
void func_title_8007C2A8(int);
int func_title_8007AD80(void) {
    int changed;
    int offset;
    register int* fields __asm__("$16");
    int result;
    register int argument __asm__("$4");
    if (D_8006E53C & 0x10) return 2;
    changed = 0;
    argument = 1;
    __asm__("" : "=r"(argument) : "0"(argument) : "$16");
    fields = DecodedMenuFields;
    __asm__("" : "=r"(fields) : "0"(fields));
    result = func_title_8007D218(argument, fields, fields + 1);
    if (result) {
        if (result == 1 && fields[0] == 1) {
            if (fields[1] == 2) fields[1] = 1;
            if (D_800725E0 < 0 || D_800725E0 == D_800725DC) {
                offset = D_800725DC << 2;
                __asm__("" : "=r"(fields) : "0"(fields), "r"(offset));
                if (((int*)((unsigned int)fields + offset))[7] == 1) {
                    if (fields[1] != 1) changed = 1;
                } else if (fields[1] != 0) changed = 1;
            }
            D_800725CC[D_800725DC] = D_800725B4;
            __asm__("" : : : "memory");
            D_800725DC = 1 - D_800725DC;
        }
        func_title_8007C2A8(D_800725DC << 4);
    }
    return changed;
}
