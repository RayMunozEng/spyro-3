#include "common.h"
#include "drawutil.h"

INCLUDE_ASM("asm/nonmatchings/overlays/loading/loading1", func_loading_8007494C);

/* AI generated; not human reviewed. Retail numeric loading text routes. */
extern int D_800725B8,D_800725C8,D_8006C76C;
extern unsigned char Decoded2073State __asm__("D_loading_8007B954");
extern char* D_loading_8007B6E4[];extern char* D_loading_8007B6E8[];extern char* D_loading_8007B6EC[];
extern char* D_loading_8007B6F0[];extern char* D_loading_8007B6F4[];extern char* D_loading_8007B6F8[];extern char* D_loading_8007B6FC[];extern char* D_loading_8007B700[];extern char* D_loading_8007B704[];
void func_loading_80075114(int y) {
 if(!D_800725B8) {int state=Decoded2073State;if(state!=4)return;}
 __asm__("" : : : "memory");
 switch(Decoded2073State) {
 case 4:
  func_80020344(D_loading_8007B6F0[D_8006C76C],256,y,11);
  func_80020344(D_loading_8007B6F4[D_8006C76C],256,y+15,11);break;
 case 3:
  func_80020344(D_loading_8007B6EC[D_8006C76C],256,y+7,2);break;
 case 6:
  switch(D_800725C8) {
  case 1:
   func_80020344(D_loading_8007B6F0[D_8006C76C],256,y,11);
   func_80020344(D_loading_8007B6F8[D_8006C76C],256,y+15,11);break;
  case 2:
   func_80020344(D_loading_8007B6F0[D_8006C76C],256,y,11);
   func_80020344(D_loading_8007B6FC[D_8006C76C],256,y+15,11);break;
  default:
   func_80020344(D_loading_8007B700[D_8006C76C],256,y,11);
   func_80020344(D_loading_8007B704[D_8006C76C],256,y+15,11);break;
  }
  break;
 case 0:case 5:break;
 default:
  func_80020344(D_loading_8007B6E4[D_8006C76C],256,y,2);
  func_80020344(D_loading_8007B6E8[D_8006C76C],256,y+15,2);break;
 }
}

