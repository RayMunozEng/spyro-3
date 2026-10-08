#include "common.h"
#include "spu.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
#include "ovl_header.h"
extern int func_80039714(Moby*);

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Controller74C50Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller74C50Helper13E38(void*,void*,int) __asm__("func_80013E38");
int Controller74C50Helper19194(void*,int) __asm__("func_80019194");
int Controller74C50Helper1A358(void*,int) __asm__("func_8001A358");
void* Controller74C50Helper2F040(int) __asm__("func_8002F040");
int Controller74C50Helper36188(void*) __asm__("func_80036188");
int Controller74C50Helper36E60(void*) __asm__("func_80036E60");
int Controller74C50Helper37014(void*) __asm__("func_80037014");
int Controller74C50Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller74C50Helper3BFC0(void*,int) __asm__("func_8003BFC0");
int Controller74C50Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller74C50Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Controller74C50Helper4EDE8(void*,int) __asm__("func_8004EDE8");
int Controller74C50Helper4EF74(void*,void*,void*) __asm__("func_8004EF74");
int Controller74C50Helper4F110(void*,int) __asm__("func_8004F110");
int Controller74C50Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller74C50Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller74C50Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Controller74C50Helper4F1FC(void*,void*,int) __asm__("func_8004F1FC");
int Controller74C50Helper4F228(void*,void*,int) __asm__("func_8004F228");
int Controller74C50Helper4F264(int,int) __asm__("func_8004F264");
int Controller74C50Helper4F334(void*,void*) __asm__("func_8004F334");
int Controller74C50Helper4F52C(void*,void*) __asm__("func_8004F52C");
int Controller74C50Helper4F5DC(int,void*) __asm__("func_8004F5DC");
int Controller74C50Helper55B18(void*) __asm__("func_80055B18");
int Controller74C50Helper55D24(void*,int) __asm__("func_80055D24");
int Controller74C50Helper56270(void*) __asm__("func_80056270");
int Controller74C50Helper5629C(void*) __asm__("func_8005629C");
extern int Controller74C50D_80065810 __asm__("D_80065810");
extern int Controller74C50D_80065818 __asm__("D_80065818");
extern unsigned char Controller74C50D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller74C50D_80065920[] __asm__("D_80065920");
extern unsigned char Controller74C50D_80066964[] __asm__("D_80066964");
extern unsigned char Controller74C50D_80066988[] __asm__("D_80066988");
extern unsigned char Controller74C50D_80066990[] __asm__("D_80066990");
extern unsigned char Controller74C50D_80066A48[] __asm__("D_80066A48");
extern int Controller74C50D_8006C648 __asm__("D_8006C648");
extern void * Controller74C50D_8006C65C __asm__("D_8006C65C");
extern unsigned char Controller74C50D_8006DEF8[] __asm__("D_8006DEF8");
extern int Controller74C50D_8006E020 __asm__("D_8006E020");
extern int Controller74C50D_8006E024 __asm__("D_8006E024");
extern unsigned short Controller74C50D_8006E040 __asm__("D_8006E040");
extern unsigned char Controller74C50D_80070328[] __asm__("D_80070328");
extern int Controller74C50D_80071908 __asm__("D_80071908");
extern unsigned char Controller74C50D_80071918[] __asm__("D_80071918");
extern int Controller74C50D_8007192C __asm__("D_8007192C");
extern int (*Controller74C50SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
extern void *Controller74C50D_8006C550 __asm__("D_8006C550");
extern int Controller74C50D_8006C6F8 __asm__("D_8006C6F8");
extern unsigned char Controller74C50D_8006E3B0[] __asm__("D_8006E3B0");
void func_level_50_800759B4(void *input) {
    struct {
        struct {int x,y,z;} first;int p1C;
        struct {int x,y,z;} second, third, fourth;int p44;
        struct {int x,y,z;} fifth;int p54;
        struct {int x,y,z;} sixth;int p64;
        struct {int x,y,z;} seventh;int p74;
        struct {int x,y,z;} eighth;int p84;
        struct {int x,y,z;} ninth;int p94;
        int pad98[4];
    } frame;
    register unsigned char *owner __asm__("$18")=input;
    int thirty;
    register int timer __asm__("$3");
    register int timerCondition __asm__("$2");
    register void *selectorOwner __asm__("$4");
    register int selectorMode __asm__("$5");
    register int ten __asm__("$21");
    register int five __asm__("$23");
    register void *savedPlayer __asm__("$20");
    register void *stateThreeVector __asm__("$19");
    register void *stateThreeDelta __asm__("$16");
    register void *stateTwoNormal __asm__("$21");
    register int temp_v0 __asm__("$2");
    register int temp_v0_4 __asm__("$2");
    register unsigned char * resourceRecord __asm__("$16");
    register unsigned char * workingPosition __asm__("$19");
    register unsigned char * ownerPosition __asm__("$20");
    register unsigned char * selectedResource __asm__("$16");
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    register int sampledHeight __asm__("$16");
    register int distanceResult __asm__("$22");
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    register int var_a0 __asm__("$4");
    register int var_a1 __asm__("$5");
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    signed char signedAngleResult;
    register int temp_s0 __asm__("$16");
    unsigned char temp_v0_2;
    unsigned char temp_v1;
    register int temp_v1_2 __asm__("$3");
    register unsigned char * tag __asm__("$17");
    register unsigned char * callbackTag __asm__("$17");
    void *callbackOwnerReference;
    void *temp_v1_6;

    workingPosition = owner + 0xC;
    tag = Controller74C50Field(owner, void **, 0);
    distanceResult = Controller74C50Helper4F334(workingPosition, Controller74C50D_80070328);
    temp_v0 = Controller74C50Field(tag, short *, 0xA);
    __asm__("" : "=r"(temp_v0) : "0"(temp_v0));
    timer=temp_v0;timerCondition=temp_v0<0x218;
    __asm__ volatile("" : "=r"(timerCondition) : "0"(timerCondition) : "$30");
    thirty=30;
    if (timerCondition) {
        __asm__("" : "=r"(thirty) : "0"(thirty));
        temp_v0=Controller74C50D_8006C648;
        __asm__("" : "=r"(temp_v0) : "0"(temp_v0));
        temp_v0=timer+temp_v0;
        Controller74C50Field(tag,short*,0xA)=temp_v0;
    } else {
        __asm__("" : "=r"(thirty) : "0"(thirty));
        __asm__ volatile("" ::: "$2");
        selectedResource = 0;
        if (Controller74C50Helper4F264((int) (Controller74C50D_8006E040 << 0x10) >> 0x14, Controller74C50Helper4E880(Controller74C50Field(owner, int *, 0xC) - Controller74C50D_8006E020, Controller74C50Field(owner, int *, 0x10) - Controller74C50D_8006E024, 0)) < 0x20) {
            selectedResource = Controller74C50Helper2F040(Controller74C50Field(owner, unsigned char *, 0x49));
        }
        if (selectedResource != 0) {
            if (distanceResult < 0x3000) {
                Controller74C50Field(tag, unsigned char *, 0x13) = (unsigned char) ((int) (selectedResource - Controller74C50D_8006DEF8) >> 4);
                Controller74C50Field(tag, short *, 0xA) = (short) ((unsigned short) Controller74C50Field(tag, short *, 0xA) - 0x20);
                Controller74C50Field(tag, unsigned char *, 0x14) = (unsigned char) ((Controller74C50Field(owner, unsigned char *, 0x49) * 2) + (rand() & 1));
            } else {
                Controller74C50Helper4F178(selectedResource, workingPosition);
                if (distanceResult <= 0x7FFF) {
                    Controller74C50Field(tag, short *, 0xA) = (short) ((unsigned short) Controller74C50Field(tag, short *, 0xA) - 0x80);
                    Controller74C50Field(selectedResource, int *, 8) = (int) (Controller74C50Field(selectedResource, int *, 8) + 0x80);
                } else {
                    Controller74C50Field(tag, short *, 0xA) = (short) ((unsigned short) Controller74C50Field(tag, short *, 0xA) - 0x100);
                }
                Controller74C50Field(tag, unsigned char *, 0x13) = 0xFFU;
            }
            Controller74C50Field(selectedResource, unsigned char *, 0xD) = (unsigned char) (Controller74C50Field(selectedResource, unsigned char *, 0xD) + (rand() & 0x3F));
        } else {
            Controller74C50Field(tag, short *, 0xA) = (short) ((unsigned short) Controller74C50Field(tag, short *, 0xA) - 0x100);
        }
        Controller74C50Field(tag, short *, 0xA) = (short) ((unsigned short) Controller74C50Field(tag, short *, 0xA) - (rand() & 0xFF));
    }
    temp_s0 = Controller74C50Field(tag, unsigned char *, 0x13);
    __asm__("" : "=r"(temp_s0) : "0"(temp_s0));
    selectorOwner=owner;
    if (temp_s0 < 0x10U) {
        __asm__("" : "=r"(selectorOwner) : "0"(selectorOwner));
        selectorMode=4;
        __asm__("" : "=r"(selectorMode) : "0"(selectorMode));
        temp_s0*=16;
        __asm__("" : "=r"(temp_s0) : "0"(temp_s0) : "$2");
        {register unsigned char *base __asm__("$2")=Controller74C50D_8006DEF8;
         resourceRecord=(unsigned char*)(temp_s0+(int)base);}
        Controller74C50Helper55D24(selectorOwner,selectorMode);
        Controller74C50Helper4F178(resourceRecord, (Controller74C50Field(tag, unsigned char *, 0x14) * 0xC) + (Controller74C50D_80066A48 + 0x30));
        Controller74C50Helper4ED6C(owner + 0x20, resourceRecord, resourceRecord);
        Controller74C50Helper4F194(resourceRecord, resourceRecord, owner + 0xC);
        if ((unsigned char) Controller74C50Field(resourceRecord, unsigned char *, 0xC) < 4U) {
            Controller74C50Field(tag, unsigned char *, 0x13) = 0xFFU;
        }
    }
    if ((Controller74C50Field(owner, unsigned char *, 0x4D) != 0) || (distanceResult < 0x1801) || (Controller74C50Field(owner, unsigned char *, 0x48) != 1) || (Controller74C50Field(tag, unsigned char *, 0x11) != 0)) {
        if (Controller74C50Field(owner, int *, 0x14) < 0x401) {
            Controller74C50Helper4F178(owner + 0xC, Controller74C50D_80070328);
        }
        temp_v1 = Controller74C50Field(owner, unsigned char *, 0x48);
        switch (temp_v1) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            Controller74C50Helper4F178(&frame.first.x, owner + 0xC);
            frame.first.z += 0x400;
            Controller74C50Helper1A358(&frame.first.x, 0x10000);
            Controller74C50Helper36188(tag + 0xE);
            if (Controller74C50Field(tag, int *, 0xC) & 0xFFFF0000) {
                Controller74C50Field(owner, unsigned char *, 0x46) = 0U;
            }
            Controller74C50Field(owner, int *, 0x14) = (int) Controller74C50D_80071908;
            Controller74C50Field(tag, short *, 0xA) = (short) ((rand() & 0xFF) + 0x100);
            Controller74C50Field(owner, unsigned char *, 0x48) = 1U;
            temp_v0_2 = *(Controller74C50D_80066964 + Controller74C50Field(owner, unsigned char *, 0x50));
            Controller74C50Field(owner, unsigned char *, 0x49) = temp_v0_2;
            Controller74C50Field(owner, unsigned char *, 0x3C) = (unsigned char) *(Controller74C50D_80066988 + (temp_v0_2 & 0xFF));
            Controller74C50Field(owner, unsigned char *, 0x54) = (unsigned char) *(Controller74C50D_80066990 + Controller74C50Field(owner, unsigned char *, 0x49));
            goto block_75;
        case 1:                                     /* switch 1 */
            temp_v1_2 = Controller74C50Field(tag, unsigned char *, 0x11);
            if(temp_v1_2==0) goto stateOneTail;
            if(temp_v1_2==1) {
                Controller74C50Helper37014(owner);
                Controller74C50Helper36188(tag + 0xE);
                goto stateOneTail;
            }
            if(temp_v1_2==2) {
                Controller74C50Helper4F5DC((short) Controller74C50Field(tag, int *, 0xC), &frame.second.x);
                Controller74C50Helper4F194(&frame.second.x, &frame.second.x, &frame.third.x);
                Controller74C50Helper4F194(&frame.second.x, &frame.second.x, &frame.fourth.x);
                Controller74C50Helper4F228(&frame.second.x, &frame.second.x, 3);
                Controller74C50Helper55D24(owner, 2);
                Controller74C50Helper37014(owner);
                goto stateOneTail;
            }
                Controller74C50Helper4F178(&frame.fifth.x, owner + 0xC);
                frame.fifth.z += 0x400;
                if (Controller74C50Helper1A358(&frame.fifth.x, 0x1000) > 0) {
                    {register int value __asm__("$3")=Controller74C50D_8007192C;
                     register int two __asm__("$2")=2;
                     __asm__("" : "=r"(value),"=r"(two) : "0"(value),"1"(two));
                     Controller74C50Field(tag,unsigned char*,0x11)=two;
                     Controller74C50Field(tag,short*,0xC)=value;}
                }
stateOneTail:
            if (Controller74C50Field(tag, short *, 0xA) >= 0x1E) {
                __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult) : "$4");
                temp_a0 = Controller74C50Field(Controller74C50D_80070328, int *, 0x44) + 0x80;
                if (distanceResult < temp_a0) {
                    temp_v1_3 = Controller74C50Field(Controller74C50D_80070328, int *, 8) - Controller74C50Field(owner, int *, 0x14);
                    if (temp_v1_3 < temp_a0) {
                        var_v0_2=-Controller74C50Field(Controller74C50D_80070328,int*,0x44);
                        __asm__ volatile("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$6");
                        var_v0_2=var_v0_2 < temp_v1_3;
                        goto block_69;
                    }
                }
            }
            goto block_75;
        case 2:                                     /* switch 1 */
            frame.fifth.x = Controller74C50Field(tag, short *, 4) * Controller74C50D_8006C648;
            frame.fifth.y = Controller74C50Field(tag, short *, 6) * Controller74C50D_8006C648;
            frame.fifth.z = Controller74C50Field(tag, short *, 8) * Controller74C50D_8006C648;
            workingPosition=(unsigned char*)&frame.fifth.x;
            __asm__("" : "=r"(workingPosition) : "0"(workingPosition));
            Controller74C50Helper4F110(workingPosition,1);
            {register void *first __asm__("$4")=workingPosition;
             __asm__("" : "=r"(first) : "0"(first) : "$20");
             ownerPosition=owner+12;
             Controller74C50Helper4F194(first,ownerPosition,workingPosition);}
            temp_v0_4=Controller74C50Field(tag,short*,8);
            __asm__("" : "=r"(temp_v0_4) : "0"(temp_v0_4));
            {register int old __asm__("$4")=temp_v0_4;
             temp_v0_4=temp_v0_4 < -215;
             if(!temp_v0_4) {
               register int delta __asm__("$3")=Controller74C50D_8006C648;
               register int product __asm__("$2");
               __asm__("" : "=r"(old),"=r"(delta) : "0"(old),"1"(delta));
               product=delta*5;product=old-product;
               Controller74C50Field(tag,short*,8)=product;
             }}
            if (frame.fifth.z < 0x400) {
                Controller74C50Helper36E60(owner);
                Controller74C50Helper55B18(owner);
                return;
            }
            frame.fifth.z += 0xF0;
            if (Controller74C50Helper19194(workingPosition, 0xF0) != 0) {
                stateTwoNormal=&frame.sixth.x;
                __asm__("" : "=r"(stateTwoNormal) : "0"(stateTwoNormal));
                Controller74C50Helper4F178(stateTwoNormal,Controller74C50D_80071918);
                Controller74C50Helper4F178(ownerPosition, Controller74C50D_80071918 - 0xC);
                Controller74C50Field(owner, int *, 0x14) = (int) (Controller74C50Field(owner, int *, 0x14) - 0xF0);
                if (Controller74C50Field(tag, unsigned char *, 0x12) == 0) {
                    {register int height __asm__("$2")=Controller74C50Helper1A358(workingPosition,0x400);
                     register void *first __asm__("$4")=stateTwoNormal;
                     register int zero __asm__("$5")=0;
                     register int magnitude __asm__("$5");
                     register int signedAngle __asm__("$2");
                     __asm__("" : "=r"(first),"=r"(zero) : "0"(first),"1"(zero) : "$16");
                     sampledHeight=height;
                     magnitude=Controller74C50Helper4EDE8(first,zero);
                     signedAngle=Controller74C50Helper4E880(frame.sixth.z,magnitude,0);
                     signedAngle<<=24;
                     __asm__("" : "=r"(signedAngle) : "0"(signedAngle));
                     signedAngleResult=signedAngle>>24;}
                    if (((frame.fifth.z - 0x190) < sampledHeight) && (signedAngleResult < 0x18)) {
                        Controller74C50Field(owner, unsigned char *, 0x48) = 1U;
                        Controller74C50Helper4F178(ownerPosition, workingPosition);
                        Controller74C50Field(owner, int *, 0x14) = sampledHeight;
                        Controller74C50Helper36188(tag + 0xE);
                        if (Controller74C50Field(tag, int *, 0xC) & 0xFFFF0000) {
                            Controller74C50Field(owner, unsigned char *, 0x46) = 0U;
                        }
                        Controller74C50Field(owner, signed char *, 0x52) = 0;
                        Controller74C50Helper56270(owner);
                        Controller74C50Helper5629C(owner);
                    } else {
                        Controller74C50Field(tag, unsigned char *, 0x12) = (unsigned char) (Controller74C50Field(tag, unsigned char *, 0x12) + 1);
                    }
                    if (Controller74C50Field(tag, unsigned char *, 0x12) != 0) {
                        goto block_52;
                    }
                } else {
block_52:
                    frame.seventh.x = (int) Controller74C50Field(tag, short *, 4);
                    frame.seventh.y = (int) Controller74C50Field(tag, short *, 6);
                    frame.seventh.z = (int) Controller74C50Field(tag, short *, 8);
                    if (Controller74C50Helper4EF74(&frame.seventh.x, &frame.sixth.x, &frame.seventh.x) != 0) {
                        Controller74C50Field(tag, unsigned char *, 0x12) = (unsigned char) (Controller74C50Field(tag, unsigned char *, 0x12) - 1);
                        Controller74C50Field(tag, short *, 4) = (short) frame.seventh.x;
                        Controller74C50Field(tag, short *, 6) = (short) frame.seventh.y;
                        Controller74C50Field(tag, short *, 8) = (short) frame.seventh.z;
                        Controller74C50Field(tag, short *, 4) = (short) ((((int) ((unsigned short) Controller74C50Field(tag, short *, 4) << 0x10) >> 0x13) + (rand() & 0x3F)) - 0x20);
                        Controller74C50Field(tag, short *, 6) = (short) ((((int) ((unsigned short) Controller74C50Field(tag, short *, 6) << 0x10) >> 0x13) + (rand() & 0x3F)) - 0x20);
                        Controller74C50Field(tag, short *, 8) = (short) (((int) ((unsigned short) Controller74C50Field(tag, short *, 8) << 0x10) >> 0x12) + (rand() & 0xF));
                        Controller74C50Helper3BABC(owner, 1, 0);
                    }
                }
            } else {
                frame.fifth.z -= 0xF0;
                Controller74C50Helper4F178(ownerPosition, workingPosition);
                Controller74C50Helper1A358(workingPosition, 0x10000);
                Controller74C50Helper5629C(owner);
            }
            __asm__ volatile("" ::: "memory");
            if (Controller74C50Field(tag, short *, 0xA) >= 0x1E) {
                __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult) : "$5");
                temp_a0_2 = Controller74C50Field(Controller74C50D_80070328, int *, 0x44) + 0x80;
                if (distanceResult < temp_a0_2) {
                    temp_v1_4 = Controller74C50Field(Controller74C50D_80070328, int *, 8) - Controller74C50Field(owner, int *, 0x14);
                    if (temp_v1_4 < temp_a0_2) {
                        var_v0_2=-Controller74C50Field(Controller74C50D_80070328,int*,0x44);
                        __asm__ volatile("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$7");
                        var_v0_2=var_v0_2 < temp_v1_4;
                        goto block_69;
                    }
                }
            }
            goto block_75;
        case 3:                                     /* switch 1 */
            stateThreeVector=&frame.eighth.x;
            __asm__("" : "=r"(stateThreeVector) : "0"(stateThreeVector));
            Controller74C50Helper4F52C(stateThreeVector,tag+4);
            ten=10;
            __asm__("" : "=r"(ten) : "0"(ten));
            five=5;
            if (Controller74C50Field(tag, short *, 0xA) >= thirty) {
                __asm__("" : "=r"(five) : "0"(five));
                Controller74C50Helper4F178(owner + 0xC, Controller74C50D_80070328);
            } else {
                __asm__("" : "=r"(five) : "0"(five));
                stateThreeDelta=&frame.seventh.x;
                __asm__("" : "=r"(stateThreeDelta) : "0"(stateThreeDelta) : "$20");
                {register void *first __asm__("$4")=stateThreeDelta;
                 __asm__("" : "=r"(first) : "0"(first) : "$20");
                 savedPlayer=Controller74C50D_80070328;
                 Controller74C50Helper4F1C8(first,savedPlayer,stateThreeVector);}
                Controller74C50Helper4F228(stateThreeDelta, stateThreeDelta, thirty);
                if (Controller74C50Helper4EDE8(stateThreeDelta, 1) >= 0x1E1) {
                    Controller74C50Helper4F178(owner+12,savedPlayer);
                    Controller74C50Field(tag,short*,0xA)=thirty;
                } else {
                    Controller74C50Helper4F1FC(stateThreeDelta, stateThreeDelta, Controller74C50Field(tag, short *, 0xA));
                    Controller74C50Helper4F194(owner + 0xC, stateThreeVector, stateThreeDelta);
                    Controller74C50Field(owner, int *, 0x14) = (int) (Controller74C50Field(owner, int *, 0x14) + ((short) *(unsigned short*)(Controller74C50D_800658A0 + (Controller74C50Field(tag, short *, 0xA) * five*2)) / ten));
                }
            }
            {register int offset __asm__("$2")=Controller74C50Field(tag,unsigned char*,0xE);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Controller74C50Field(owner,unsigned char*,0x44);
              offset+=249;old+=offset;Controller74C50Field(owner,unsigned char*,0x44)=old;}
            {register int offset __asm__("$2")=Controller74C50Field(tag,unsigned char*,0xF);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Controller74C50Field(owner,unsigned char*,0x45);
              offset+=249;old+=offset;Controller74C50Field(owner,unsigned char*,0x45)=old;}
            {register int offset __asm__("$2")=Controller74C50Field(tag,unsigned char*,0x10);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Controller74C50Field(owner,unsigned char*,0x46);
              offset+=249;old+=offset;Controller74C50Field(owner,unsigned char*,0x46)=old;}
            if ((Controller74C50Field(tag, short *, 0xA) < 0xF) || (temp_a0_3 = Controller74C50Field(Controller74C50D_80070328, int *, 0x44) + 0x80, ((distanceResult < temp_a0_3) == 0)) || (temp_v1_5 = Controller74C50Field(Controller74C50D_80070328, int *, 8) - Controller74C50Field(owner, int *, 0x14), ((temp_v1_5 < temp_a0_3) == 0)) || (-Controller74C50Field(Controller74C50D_80070328, int *, 0x44) >= temp_v1_5)) {
                var_v0_2 = Controller74C50Field(tag, short *, 0xA) > thirty;
                goto block_69;
            }
            goto block_70;
block_69:
            if(!var_v0_2) goto block_75;
block_70:
            Controller74C50Field(owner,unsigned char*,0x48)=4;
            goto block_75;
        case 4:                                     /* switch 1 */
            if (Controller74C50D_8006C65C != 0) {
                temp_v1_6 = Controller74C50Field(Controller74C50D_8006C65C, void **, 0);
                if (Controller74C50Field(temp_v1_6, int *, 0x14) == owner) {
                    Controller74C50Field(temp_v1_6, int *, 0x14) = 0;
                }
            }
            Controller74C50Helper55D24(owner, 4);
            {register int type __asm__("$4")=4;
             register int subtype __asm__("$5")=12;
             register int (*emit)(int,int,void*,int) __asm__("$2");
             register int selector __asm__("$7");
             __asm__("" : "=r"(type),"=r"(subtype) : "0"(type),"1"(subtype) : "$2");
             emit=Controller74C50SpawnParticle;
             __asm__("" : "=r"(emit) : "0"(emit) : "$7");
             selector=Controller74C50Field(owner,unsigned char*,0x49);
             emit(type,subtype,owner,selector);}
            {register int poolIndex __asm__("$3")=Controller74C50Field(owner,unsigned char*,0x3A);
             register int sentinel __asm__("$2");
             register unsigned char *poolEntry __asm__("$2");
             register void *poolBase __asm__("$3");
             register int typeValue __asm__("$3");
             register int typeGate __asm__("$2");
             register int ringIndex __asm__("$2");
             register int savedSelector __asm__("$3");
             __asm__("" : "=r"(poolIndex) : "0"(poolIndex) : "$2");
             sentinel=255;
             __asm__("" : "=r"(poolIndex),"=r"(sentinel) : "0"(poolIndex),"1"(sentinel));
             if(poolIndex!=sentinel) {
                 poolEntry=(unsigned char*)(poolIndex*11);
                 __asm__("" : "=r"(poolEntry) : "0"(poolEntry) : "$3");
                 poolBase=Controller74C50D_8006C550;
                 __asm__("" : "=r"(poolEntry),"=r"(poolBase) : "0"(poolEntry),"1"(poolBase));
                 poolEntry=(unsigned char*)(((int)poolEntry<<3)+(int)poolBase);
                 typeValue=Controller74C50Field(poolEntry,short*,0x36);
                 __asm__("" : "=r"(typeValue) : "0"(typeValue) : "$2");
                 typeGate=0xE0;
                 __asm__("" : "=r"(typeGate) : "0"(typeGate));
                 if(typeValue==typeGate)goto recordSelector;
                 typeGate=0x205;
                 __asm__("" : "=r"(typeGate) : "0"(typeGate));
                 if(typeValue==typeGate)goto recordSelector;
                 typeGate=0x75;
                 __asm__("" : "=r"(typeGate) : "0"(typeGate));
                 if(typeValue==typeGate)goto recordSelector;
                 typeGate=0x1B9;
                 __asm__("" : "=r"(typeGate) : "0"(typeGate));
                 if(typeValue==typeGate)goto recordSelector;
                 typeGate=0x28;
                 __asm__("" : "=r"(typeGate) : "0"(typeGate));
                 if(typeValue!=typeGate)goto standardCleanup;
recordSelector:
                 ringIndex=Controller74C50D_8006C6F8;
                 savedSelector=Controller74C50Field(owner,unsigned char*,0x49);
                 ringIndex&=31;
                 Controller74C50D_8006E3B0[ringIndex]=savedSelector;
                 ringIndex=Controller74C50D_8006C6F8;
                 __asm__("" : "=r"(ringIndex) : "0"(ringIndex));
                 Controller74C50D_8006C6F8=ringIndex+1;
                 goto commonCleanup;
             }
            }
standardCleanup:
            Controller74C50Helper36E60(owner);
commonCleanup:
            Controller74C50Helper3BABC(owner, 0, 0);
            Controller74C50Helper55B18(owner);
            goto block_75;
        }
block_75:
            if ((unsigned char) Controller74C50Field(owner, unsigned char *, 0x48) < 3U) {

                {register int sample __asm__("$2")=*(unsigned short*)(Controller74C50D_80065920+(Controller74C50Field(tag,unsigned char*,0x10)*2));
                  register int base __asm__("$3");
                  __asm__("" : "=r"(sample) : "0"(sample) : "$3");
                  base=Controller74C50Field(tag,unsigned char*,0xE);
                  __asm__("" : "=r"(sample),"=r"(base) : "0"(sample),"1"(base));
                  sample=(sample<<16)>>23;sample+=base;
                  Controller74C50Field(owner,unsigned char*,0x44)=sample;}
                {register int sample __asm__("$2")=*(unsigned short*)(Controller74C50D_800658A0+(Controller74C50Field(tag,unsigned char*,0x10)*2));
                  register int base __asm__("$3");
                  __asm__("" : "=r"(sample) : "0"(sample) : "$3");
                  base=Controller74C50Field(tag,unsigned char*,0xF);
                  __asm__("" : "=r"(sample),"=r"(base) : "0"(sample),"1"(base));
                  sample=(sample<<16)>>23;sample+=base;
                  Controller74C50Field(owner,unsigned char*,0x45)=sample;}
                Controller74C50Field(tag, unsigned char *, 0x10) = (unsigned char) (Controller74C50Field(tag, unsigned char *, 0x10) + (Controller74C50D_8006C648 * 2));
                var_a1=Controller74C50D_80065810;
                {register int state __asm__("$3")=Controller74C50Field(Controller74C50D_80070328,int*,0x50);
                 if(state==6) goto commonIncreasedThreshold;
                 {register unsigned int index __asm__("$2")=state-11;
                  __asm__("" : "=r"(index) : "0"(index));
                 if(index<2) {
                   register int source __asm__("$3")=Controller74C50D_80065818;
                   register int product __asm__("$2")=(var_a1<<1)+var_a1;
                   __asm__("" : "=r"(source),"=r"(product) : "0"(source),"1"(product));
                   var_a1=product>>1;var_a0=source+512;goto commonThresholdReady;
                 }
                 }
                 state=Controller74C50Field(Controller74C50D_80070328,int*,0x24C);
                 if(state!=3) goto commonNormalThreshold;
                }
commonIncreasedThreshold:
                {register int source __asm__("$2")=Controller74C50D_80065818;
                 __asm__("" : "=r"(source) : "0"(source));
                 var_a0=source+512;goto commonThresholdReady;}
commonNormalThreshold:
                var_a0=Controller74C50D_80065818;
commonThresholdReady:
                if (({register int inRange __asm__("$2")=distanceResult<var_a1;__asm__("" : "=r"(inRange) : "0"(inRange));inRange;})) {
                    {register int height __asm__("$3")=Controller74C50Field(owner,int*,0x14);
                     register int playerZ __asm__("$2")=Controller74C50Field(Controller74C50D_80070328,int*,8);
                     __asm__("" : "=r"(height),"=r"(playerZ) : "0"(height),"1"(playerZ));
                     height+=356;var_v0=playerZ-height;}
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    if ((var_v0 < var_a0) && (Controller74C50D_8006C65C != 0) && ((Controller74C50Field(owner, unsigned char *, 0x48) != 2) || ((unsigned char) Controller74C50Field(tag, unsigned char *, 0x12) < 3U)) && (callbackTag = Controller74C50Field(Controller74C50D_8006C65C, void **, 0), Controller74C50Helper4F178(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64, (Controller74C50Helper13E38(Controller74C50D_8006C65C + 0xC, &frame.ninth.x, 0) != 0))) {
                        callbackOwnerReference = Controller74C50Field(callbackTag, void **, 0x14);
                        if (callbackOwnerReference != 0) {
                            if ((callbackOwnerReference != owner) && (Controller74C50Field(callbackTag, short *, 0) > 0)) {
                                Controller74C50Field(callbackTag, short *, 0) = 0;
                                return;
                            }
                        } else {
                            Controller74C50Field(Controller74C50D_8006C65C, signed char *, 0x49) = 4;
                            {register void *callbackOwner __asm__("$4")=Controller74C50D_8006C65C;
                             register int selector __asm__("$5")=Controller74C50Field(callbackTag,unsigned char*,2);
                             __asm__("" : "=r"(callbackOwner),"=r"(selector) : "0"(callbackOwner),"1"(selector) : "memory");
                             Controller74C50Field(callbackTag,void**,0x14)=owner;
                             Controller74C50Field(callbackTag,short*,0)=0;
                            if (Controller74C50Helper3BFC0(callbackOwner,selector) == 0) {
                                Controller74C50Field(callbackTag, unsigned char *, 2) = Controller74C50Helper3BABC(Controller74C50D_8006C65C, 0, 0);
                            }
                            }
                        }
                    }
                }
            }
    }
}

/* AI-generated; not human reviewed. Verified 75F38 sibling plus the
 * original player +0x244 / linked-record model 0x72 cleanup branch.
 * Raw units, helper semantics and update cadence remain unresolved. */
extern unsigned char Controller75F38TablePlayer[] __asm__("D_80070328");
#define Controller75F38Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller75F38Helper19194(void*,int) __asm__("func_80019194");
void* Controller75F38Helper2EC50(int,int,int) __asm__("func_8002EC50");
int Controller75F38Helper34F40(void*,int) __asm__("func_80034F40");
int Controller75F38Helper35734(void*,int) __asm__("func_80035734");
int Controller75F38Helper3585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Controller75F38Helper359A4(void*,int) __asm__("func_800359A4");
int Controller75F38Helper36018(int,int,int) __asm__("func_80036018");
unsigned int Controller75F38Helper3636C(int,int) __asm__("func_8003636C");
int Controller75F38Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller75F38Helper3BFC0(void*,int) __asm__("func_8003BFC0");
int Controller75F38Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller75F38Helper4EA74(int) __asm__("func_8004EA74");
int Controller75F38Helper4ECF4(void*,void*) __asm__("func_8004ECF4");
int Controller75F38Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Controller75F38Helper4EDE8(void*,int) __asm__("func_8004EDE8");
int Controller75F38Helper4EF04(void*,int) __asm__("func_8004EF04");
int Controller75F38Helper4F08C(void*,int,int) __asm__("func_8004F08C");
int Controller75F38Helper4F110(void*,int) __asm__("func_8004F110");
int Controller75F38Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller75F38Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller75F38Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Controller75F38Helper4F2A4(int,int) __asm__("func_8004F2A4");
int Controller75F38Helper4F334(void*,void*) __asm__("func_8004F334");
int Controller75F38Helper4F504(void*,void*) __asm__("func_8004F504");
int Controller75F38Helper4F554(void*,void*) __asm__("func_8004F554");
int Controller75F38Helper55B18(void*) __asm__("func_80055B18");
int Controller75F38Helper55D24(void*,int) __asm__("func_80055D24");
int Controller75F38Helper55F14(void*,int,void*) __asm__("func_80055F14");
extern unsigned char Controller75F38D_80065830[] __asm__("D_80065830");
extern unsigned char Controller75F38D_8006585C[] __asm__("D_8006585C");
extern unsigned char Controller75F38D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller75F38D_80065920[] __asm__("D_80065920");
extern unsigned char Controller75F38D_8006E00C[] __asm__("D_8006E00C");
extern unsigned char Controller75F38D_80070328[] __asm__("D_80070328");
extern unsigned char Controller75F38D_8007190C[] __asm__("D_8007190C");
extern int Controller75F38D_8006580C __asm__("D_8006580C");
extern int Controller75F38D_80065814 __asm__("D_80065814");
extern int Controller75F38D_80065820 __asm__("D_80065820");
extern int Controller75F38D_80065828 __asm__("D_80065828");
extern int Controller75F38D_8006C644 __asm__("D_8006C644");
extern int Controller75F38D_8006C648 __asm__("D_8006C648");
extern int Controller75F38D_8006C65C __asm__("D_8006C65C");
extern int Controller75F38D_8006C770 __asm__("D_8006C770");
extern int Controller75F38D_8006C784 __asm__("D_8006C784");
extern int Controller75F38D_8006E020 __asm__("D_8006E020");
extern int Controller75F38D_8006E024 __asm__("D_8006E024");
extern int Controller75F38D_8006E044 __asm__("D_8006E044");
extern int Controller75F38D_8006E538 __asm__("D_8006E538");
extern void* Controller75F38D_8006C550 __asm__("D_8006C550");
extern unsigned short Controller75F38D_8006E040 __asm__("D_8006E040");
extern unsigned char Controller75F38D_8006E534 __asm__("D_8006E534");
extern void* (*Controller75F38SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Controller75F38SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
extern int (*Controller75F38Callback)(void*,void*,int,int,int,int,int,int,int,int,int,int,int) __asm__("unk_ovlheader_80074314");
void func_level_50_800766A8(void *input) {
    register unsigned char *owner __asm__("$20")=input;
    struct {
        struct {int x,y,z;} first;int p44;
        struct {int x,y,z;} second;int p54;
        struct {int x,y,z;} third;int p64;
        struct {int x,y,z;} fourth;int p74;
        struct {int x,y,z;} fifth;int p84;
        int matrix[6];
        struct {int x,y,z;} sixth;int padAC[1];
    } frame;
    short temp_a0_2;
    short temp_a0_7;
    short temp_v0_12;
    register int temp_v1_10 __asm__("$3");
    register int var_v0_8 __asm__("$2");
    int var_v0_9;
    unsigned char *temp_a0_4;
    unsigned char *temp_a0_5;
    unsigned char *temp_a0_6;
    unsigned char *temp_a1;
    unsigned char *temp_a2;
    register unsigned char *temp_s0_2 __asm__("$16");
    register unsigned char *temp_s0_4 __asm__("$16");
    register unsigned char *temp_s0_5 __asm__("$16");
    register unsigned char *temp_s1 __asm__("$17");
    register unsigned char *ownerPosition __asm__("$22");
    unsigned char *temp_v0_11;
    register unsigned char * temp_v0_8 __asm__("$2");
    unsigned char *temp_v1_2;
    register unsigned char *var_a2_5 __asm__("$6");
    register void *matrixFirst __asm__("$4");
    register void *matrixSecond __asm__("$5");
    register void *commonOwner __asm__("$4");
    register void *movementPosition __asm__("$4");
    register int movementRadius __asm__("$5");
    register int temp_a1_4 __asm__("$5");
    register int temp_s0 __asm__("$16");
    register int magnitudeDelta __asm__("$16");
    register unsigned char *temp_s1_3 __asm__("$17");
    register int initialMagnitude __asm__("$17");
    register int adjustedMagnitude __asm__("$17");
    register int adjustedAngle __asm__("$21");
    register int temp_v0_10 __asm__("$5");
    int temp_v0_5;
    int temp_v0_6;
    register int temp_v0_9 __asm__("$5");
    int temp_v1;
    int temp_v1_14;
    int temp_v1_5;
    register int temp_v1_8 __asm__("$3");
    register int var_a0_2 __asm__("$4");
    register int var_a0_3 __asm__("$4");
    register int tailMagnitude __asm__("$2");
    register int var_a0_4 __asm__("$4");
    register int var_a1 __asm__("$5");
    int var_a1_2;
    register int var_a2 __asm__("$6");
    register int var_a2_2 __asm__("$6");
    register int var_a2_3 __asm__("$6");
    register int var_a2_4 __asm__("$6");
    register int verticalStep __asm__("$16");
    register int var_v0 __asm__("$2");
    register int var_v0_10 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int thirdY __asm__("$3");
    register int scanEnabled __asm__("$2");
    register unsigned char *candidateBase __asm__("$5");
    register unsigned char *candidateRecords __asm__("$18");
    register int var_v0_3 __asm__("$2");
    int var_v0_5;
    int var_v0_6;
    int var_v0_7;
    register int var_v1 __asm__("$3");
    register int var_v1_2 __asm__("$3");
    register unsigned int temp_s0_3 __asm__("$16");
    unsigned int temp_v0_13;
    register unsigned char *var_s0 __asm__("$16");
    register int temp_a0_3 __asm__("$4");
    int temp_a1_2;
    register int temp_a1_3 __asm__("$5");
    register int temp_s1_2 __asm__("$17");
    register int initialAngle __asm__("$21");
    register int originalAngle __asm__("$23");
    int temp_v0_4;
    register int temp_v0_7 __asm__("$2");
    unsigned char temp_v1_11;
    unsigned char temp_v1_12;
    unsigned char temp_v1_13;
    register int temp_v1_4 __asm__("$3");
    unsigned char temp_v1_6;
    int temp_v1_7;
    register int temp_v1_9 __asm__("$3");
    register int stateValue __asm__("$2");
    unsigned char var_a0;
    register int var_a1_3 __asm__("$5");
    register int var_v0_11 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    register void * temp_a0 __asm__("$4");
    register void *tag __asm__("$19");
    register void * temp_v0 __asm__("$2");
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_15;
    void *temp_v1_3;
    register void *var_s1 __asm__("$17");

    tag = Controller75F38Field(owner, void **, 0);
    __asm__("" : "=r"(tag) : "0"(tag) : "$2","memory");
    { register int gate __asm__("$2")=Controller75F38Field(Controller75F38D_80070328,int*,0x244);
      __asm__("" : "=r"(gate) : "0"(gate));
      originalAngle = Controller75F38Field(owner, unsigned char *, 0x46);
      if (gate != 0 && Controller75F38Field(Controller75F38Field(Controller75F38D_80070328,void**,0x250),short*,0x36)==0x72) {
          temp_a0=(void*)Controller75F38D_8006C65C;
          if(temp_a0 != 0) {
              temp_s0_2=Controller75F38Field(temp_a0,unsigned char**,0);
              Controller75F38Helper55B18(temp_a0);
              temp_v0=Controller75F38Field(temp_s0_2,void**,0x10);
              __asm__("" : "=r"(temp_v0) : "0"(temp_v0) : "memory");
              Controller75F38D_8006C65C=0;
              if(temp_v0 != 0) {
                  Controller75F38Field(temp_v0,unsigned char*,0x10)=0;
                  Controller75F38Field(temp_s0_2,void**,0x10)=0;
              }
          }
          return;
      }
    }
    if (((unsigned int) (Controller75F38Field(Controller75F38D_80070328, int *, 0x50) - 0xB) < 2U) && (Controller75F38Field(tag, unsigned char *, 0xA) == 0) && (Controller75F38Field(owner, unsigned char *, 0x4D) != 0)) {
        {register int one __asm__("$6");
         register int model __asm__("$5");
         register int value __asm__("$3");
        temp_v0 = Controller75F38SpawnMoby(0xAA, owner);
        temp_a0 = Controller75F38Field(temp_v0, void **, 0);
        __asm__("" : "=r"(temp_a0) : "0"(temp_a0) : "$6");
        one=1;
        __asm__("" : "=r"(temp_a0),"=r"(one) : "0"(temp_a0),"1"(one) : "$3","$5");
        Controller75F38Field(temp_a0,void**,4)=owner;
        Controller75F38Field(temp_a0,unsigned char*,0)=one;
        __asm__ volatile("" ::: "$3","memory");
        model=Controller75F38Field(owner,unsigned short*,0x36);
        __asm__("" : "=r"(model) : "0"(model) : "$3");
        value=28;
        __asm__("" : "=r"(value) : "0"(value));
        Controller75F38Field(temp_a0,short*,2)=value;
        value=127;
        __asm__("" : "=r"(value),"=r"(model) : "0"(value),"1"(model) : "memory");
        Controller75F38Field(temp_a0,unsigned char*,1)=model;
        Controller75F38Field(temp_v0,unsigned char*,0x4F)=value;
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Controller75F38Field(temp_v0,unsigned char*,0x47)=value;
        Controller75F38Field(tag,unsigned char*,0xA)=one;
        }
    }
    if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x280) >= 2) && (Controller75F38Field(owner, unsigned char *, 0x4D) != 0)) {
        {register void *particleVector __asm__("$16")=&frame.second.x;
         register void *first __asm__("$4")=particleVector;
         register int angleIndex __asm__("$3")=Controller75F38Field(owner,unsigned char*,0x46);
         register void *second __asm__("$5");
         register int sample __asm__("$6");
         register int value __asm__("$2");
         register int otherSample __asm__("$3");
         register void *third __asm__("$6");
         __asm__("" : "=r"(first),"=r"(angleIndex) : "0"(first),"1"(angleIndex) : "$5");
         second=&frame.first.x;
         __asm__("" : "=r"(second) : "0"(second) : "$17");
         angleIndex=((angleIndex+64)&255)*2;
         sample=*(short*)(Controller75F38D_80065920+angleIndex);
         __asm__("" : "=r"(sample) : "0"(sample) : "$17");
         temp_s1=owner+12;
         value=(sample*25)>>10;frame.first.x=value;
         otherSample=*(short*)(Controller75F38D_800658A0+angleIndex);
         __asm__("" : "=r"(otherSample) : "0"(otherSample) : "$6");
         third=temp_s1;
         frame.first.z=0;
         __asm__ volatile("" ::: "$2","memory");
         value=(otherSample*25)>>10;frame.first.y=value;
         Controller75F38Helper4F194(first,second,third);
         Controller75F38SpawnParticle(2,0x42,particleVector,0);
         Controller75F38Helper4F1C8(particleVector,temp_s1,&frame.first.x);
         Controller75F38SpawnParticle(2,0x42,particleVector,0);
        }
    }
    if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x280) >= 3) && (Controller75F38Field(owner, unsigned char *, 0x4C) != 0)) {
        if (Controller75F38Field(tag, void **, 0x10) == 0) {
            Controller75F38Field(tag, void **, 0x10) = Controller75F38Helper2EC50(1, 0x40, 0x489090);
        }
    } else {
        temp_v0_2 = Controller75F38Field(tag, void **, 0x10);
        if (temp_v0_2 != 0) {
            Controller75F38Field(temp_v0_2, signed char *, 0x10) = 0;
            Controller75F38Field(tag, void **, 0x10) = 0;
        }
    }
    temp_a1 = Controller75F38D_80070328 + 0x280;
    if (Controller75F38Field(Controller75F38D_80070328, int *, 0x280) <= 0) {
        temp_v1_2 = Controller75F38Field(tag, unsigned char **, 0x14);
        if ((temp_v1_2 != 0) && ((unsigned char) Controller75F38Field(temp_v1_2, unsigned char *, 0x48) < 0x80U) && ((temp_a0_2 = Controller75F38Field(temp_v1_2, short *, 0x36), (temp_a0_2 == 0x10)) || (temp_a0_2 == 0xD3))) {
            Controller75F38Field(temp_v1_2, unsigned char *, 0x48) = 0U;
        }
        temp_v0_3 = Controller75F38Field(tag, void **, 0x10);
        Controller75F38D_8006C65C = 0;
        if (temp_v0_3 != 0) {
            Controller75F38Field(temp_v0_3, signed char *, 0x10) = 0;
            Controller75F38Field(tag, void **, 0x10) = 0;
        }
        Controller75F38Helper55B18(owner);
        return;
    }
    if ((Controller75F38Field(tag, unsigned char **, 0x14) != 0) && (Controller75F38Helper4F334(owner + 0xC, temp_a1 - 0x280) >= 0xC01)) {
        Controller75F38Field(tag, short *, 0) = 0;
    }
    temp_v1_3 = Controller75F38Field(tag, void **, 0x10);
    if (temp_v1_3 != 0) {
        Controller75F38Field(temp_v1_3, signed char *, 0x13) = 4;
    }
    scanEnabled=Controller75F38D_80065820;
    __asm__("" : "=r"(scanEnabled) : "0"(scanEnabled) : "$5");
    candidateBase=Controller75F38D_80065830;
    __asm__("" : "=r"(scanEnabled),"=r"(candidateBase) : "0"(scanEnabled),"1"(candidateBase));
    Controller75F38Field(candidateBase, void **, 0) = 0;
    if ((scanEnabled != 0) && ((Controller75F38D_8006E538 & 0xE) == 0xE)) {
        var_s1 = Controller75F38D_8006C550;
        var_a0 = Controller75F38Field(var_s1, unsigned char *, 0x48);
        if ((var_a0 & 0xFF) != 0xFF) {
            candidateRecords=candidateBase;
            __asm__("" : "=r"(candidateRecords) : "0"(candidateRecords) : "$16");
            var_s0 = var_s1 + 0x48;
            do {
                if ((unsigned int)(var_a0&255)<128) {
                    if(Controller75F38Field(var_s0,short*,-0x12)==1) goto eligibleCandidate;
                    temp_v1_4=Controller75F38Field(var_s0,unsigned char*,8);
                    {register unsigned int index __asm__("$2")=temp_v1_4-1;
                     index=index<2;
                     __asm__("" : "=r"(index) : "0"(index) : "$4");
                     __asm__("" : "=r"(temp_v1_4) : "0"(temp_v1_4));
                     temp_v1_4&=255;
                     if(index) goto eligibleCandidate;
                     if(temp_v1_4==5) goto eligibleCandidate;
                     if(temp_v1_4==10) goto eligibleCandidate;
                     if(temp_v1_4!=25) goto nextCandidate;
                    }
eligibleCandidate:
                    __asm__ volatile("" ::: "$4");
                    Controller75F38Helper4F1C8(&frame.first.x, var_s1 + 0xC, Controller75F38D_80070328);
                    var_a0_2 = frame.first.x;
                    var_v1 = frame.first.y;
                    var_v0 = frame.first.z;
                    __asm__("" : "=r"(var_a0_2),"=r"(var_v1),"=r"(var_v0) : "0"(var_a0_2),"1"(var_v1),"2"(var_v0));
                    if (var_a0_2 < 0) {
                        var_a0_2 = -var_a0_2;
                    }
                    if (var_v1 < 0) {
                        var_v1 = -var_v1;
                    }
                    var_a0_2+=var_v1;
                    __asm__("" : "=r"(var_a0_2),"=r"(var_v0) : "0"(var_a0_2),"1"(var_v0));
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    var_a0_3 = var_a0_2 + var_v0;
                    if (var_a0_3 < 0x4000) {
                        var_a0_3 = Controller75F38Helper4EDE8(&frame.first.x, 1);
                    }
                    if ((Controller75F38Field(candidateRecords, void **, 0) == 0) || (var_a0_3 < Controller75F38Field(candidateRecords, int *, -8))) {
                        Controller75F38Field(candidateRecords, void **, 0) = var_s1;
                        Controller75F38Field(candidateRecords, int *, -8) = var_a0_3;
                    }
                }
nextCandidate:
                var_s0 += 0x58;
                var_a0 = *var_s0;
                var_s1 += 0x58;
            } while ((var_a0 & 0xFF) != 0xFF);
        }
    }
    if (Controller75F38Field(tag, unsigned char **, 0x14) != 0) {
        temp_v1_6 = Controller75F38Field(owner, unsigned char *, 0x49);
        switch (temp_v1_6) {                        /* switch 1 */
        case 0:                                     /* switch 1 */
            temp_s1_2 = Controller75F38Field(owner, unsigned char *, 0x3D);
            Controller75F38Helper4F178(&frame.third.x, Controller75F38Field(tag, unsigned char **, 0x14) + 0xC);
            if (temp_s1_2 == 0) {
                __asm__ volatile("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
                frame.third.x -= (int) (*(unsigned short*)(Controller75F38D_80065920 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2)) << 0x10) >> 0x14;
                var_v0_2 = *(unsigned short*)(Controller75F38D_800658A0 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2));
                __asm__("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$3");
                thirdY=frame.third.y;
                __asm__("" : "=r"(var_v0_2),"=r"(thirdY) : "0"(var_v0_2),"1"(thirdY));
                var_v0_2=(var_v0_2<<16)>>0x14;
            } else {
                frame.third.x -= (int) (*(unsigned short*)(Controller75F38D_80065920 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2)) << 0x10) >> 0x16;
                var_v0_2 = *(unsigned short*)(Controller75F38D_800658A0 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2));
                __asm__("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$3");
                thirdY=frame.third.y;
                __asm__("" : "=r"(var_v0_2),"=r"(thirdY) : "0"(var_v0_2),"1"(thirdY));
                var_v0_2=(var_v0_2<<16)>>0x16;
            }
            thirdY-=var_v0_2;frame.third.y=thirdY;
            if (temp_s1_2 != 0) {
                if ((unsigned char) Controller75F38Field(owner, unsigned char *, 0x3F) >= 7U) {
                    Controller75F38Field(owner, unsigned char *, 0x49) = (unsigned char) (Controller75F38Field(owner, unsigned char *, 0x49) + 1);
                }
                temp_a0_3 = Controller75F38Field(owner, unsigned char *, 0x45);
                var_v1_2 = -(int) temp_a0_3;
                if ((unsigned int) ((temp_a0_3 - 3) & 0xFF) < 0xFBU) {
                    var_v0_3=var_v1_2<3;
                    if(var_v0_3) {
                        var_v0_3=var_v1_2<-2;
                    }else {
                        var_v1_2=2;
                        __asm__("" : "=r"(var_v1_2) : "0"(var_v1_2));
                        var_v0_3=var_v1_2<-2;
                    }
                    if(var_v0_3) {
                        var_v1_2=-2;
                        __asm__("" : "=r"(var_v1_2) : "0"(var_v1_2));
                        var_v0_3=temp_a0_3+var_v1_2;
                    }else var_v0_3=temp_a0_3+var_v1_2;
                    Controller75F38Field(owner,unsigned char*,0x45)=var_v0_3;
                }
            }
            temp_s0_2=(unsigned char*)&frame.third.x;
            __asm__("" : "=r"(temp_s0_2) : "0"(temp_s0_2));
            Controller75F38Helper4F1C8(temp_s0_2,temp_s0_2,owner+12);
            temp_s0 = Controller75F38Helper4EDE8(temp_s0_2,1);
            if ((temp_s1_2 == 0) && (Controller75F38Helper359A4(tag, 2) != 0)) {
                __asm__ volatile("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
                if (Controller75F38Helper3BFC0(owner, Controller75F38Field(tag, unsigned char *, 2)) == 0) {
                    Controller75F38Field(tag, unsigned char *, 2) = Controller75F38Helper3BABC(owner, 0, 0);
                }
                if (Controller75F38Field(owner, unsigned char *, 0x3D) != 1) {
                    Controller75F38D_8006C770 = 0;
                    temp_v1_7 = Controller75F38Field(owner, unsigned char *, 0x3D);
                    temp_a1_2 = Controller75F38Field(owner, unsigned char *, 0x3F);
                    Controller75F38Field(owner, signed char *, 0x40) = 0x72;
                    Controller75F38Field(owner, unsigned char *, 0x3D) = 1U;
                    Controller75F38Field(owner, unsigned char *, 0x3F) = 0U;
                    Controller75F38Field(owner, unsigned char *, 0x3C) = temp_v1_7;
                    Controller75F38Field(owner, unsigned char *, 0x3E) = temp_a1_2;
                    Controller75F38Helper35734(owner, temp_a1_2);
                }
            }
            var_a2 = 0x82;
            if (temp_s1_2 != 0) {
                var_a2 = 0x96;
            }
            temp_v1_8 = var_a2 + 5;
            {register void *adjustedVector __asm__("$4");
             register int magnitude __asm__("$5");
             if(temp_v1_8<temp_s0) {
                adjustedVector=&frame.third.x;magnitude=temp_s0;
                __asm__("" : "=r"(adjustedVector),"=r"(magnitude) : "0"(adjustedVector),"1"(magnitude));
                var_a2_2=temp_v1_8;goto stateZeroAdjust;
             }
             adjustedVector=&frame.third.x;magnitude=temp_s0;
             __asm__("" : "=r"(adjustedVector),"=r"(magnitude) : "0"(adjustedVector),"1"(magnitude));
             var_a2_2=var_a2-5;
stateZeroAdjust:
             Controller75F38Helper4F08C(adjustedVector,magnitude,var_a2_2);
            }
            {register void *first __asm__("$4")=owner+12;
             register void *second __asm__("$5")=first;
             __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16","$17");
             temp_s0_2=(unsigned char*)&frame.third.x;
             __asm__("" : "=r"(temp_s0_2) : "0"(temp_s0_2));
             Controller75F38Helper4F194(first,second,temp_s0_2);
            }
            Controller75F38Helper3585C(owner, Controller75F38Helper4E880(frame.third.x, frame.third.y, 0), 0xAU, 0, 0, 0);
            tailMagnitude = Controller75F38Helper4EDE8(temp_s0_2,0);
            __asm__ volatile("" : "=r"(tailMagnitude) : "0"(tailMagnitude) : "$6");
                var_a0_4=tailMagnitude;
            var_a1 = frame.third.z;
            goto block_97;
        case 1:                                     /* switch 1 */
            if (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), short *, 0x36) == 0x10) {
                temp_v0_5 = Controller75F38Field(Controller75F38D_80070328, int *, 0x280) + 1;
                Controller75F38Field(Controller75F38D_80070328, int *, 0x280) = temp_v0_5;
                if (Controller75F38D_8006580C < temp_v0_5) {
                    Controller75F38Field(Controller75F38D_80070328, int *, 0x280) = (int) Controller75F38D_8006580C;
                }
            } else {
                temp_v0_6 = Controller75F38D_8006C784 + 1;
                Controller75F38D_8006C784 = temp_v0_6;
                Controller75F38Field(Controller75F38D_80070328, int *, 0x280) = (int) Controller75F38D_8006580C;
                if (temp_v0_6 >= 0x64) {
                    Controller75F38D_8006C784 = 0x63;
                }
            }
            Controller75F38Field(owner, unsigned char *, 0x49) = (unsigned char) (Controller75F38Field(owner, unsigned char *, 0x49) + 1);
            Controller75F38Helper55B18(Controller75F38Field(tag, unsigned char **, 0x14));
            break;
        case 2:                                     /* switch 1 */
            if (Controller75F38D_8006C770 != 0) {
                register void *callbackOwner __asm__("$4")=owner;
                if (Controller75F38Field(owner, unsigned char *, 0x3D) != 0) {
                    __asm__("" : "=r"(callbackOwner) : "0"(callbackOwner));
                    Controller75F38D_8006C770 = 0;
                    temp_v0_7 = Controller75F38Field(owner, unsigned char *, 0x3D);
                    temp_a1_3 = Controller75F38Field(owner, unsigned char *, 0x3F);
                    {register int value __asm__("$3");
                     __asm__("" : "=r"(temp_v0_7),"=r"(temp_a1_3) : "0"(temp_v0_7),"1"(temp_a1_3) : "$3");
                     value=114;
                     __asm__("" : "=r"(value) : "0"(value));
                     Controller75F38Field(owner,unsigned char*,0x40)=value;
                    Controller75F38Field(owner, unsigned char *, 0x3D) = 0U;
                    Controller75F38Field(owner, unsigned char *, 0x3F) = 0U;
                    Controller75F38Field(owner, unsigned char *, 0x3C) = temp_v0_7;
                    Controller75F38Field(owner, unsigned char *, 0x3E) = temp_a1_3;
                    Controller75F38Helper35734(callbackOwner, temp_a1_3);
                    }
                }
                Controller75F38Field(owner, unsigned char *, 0x49) = 0U;
                Controller75F38Field(tag, unsigned char **, 0x14) = 0;
            }
            break;
        case 4:                                     /* switch 1 */
            temp_v0_8 = Controller75F38Field(tag, unsigned char **, 0x14);
            temp_s1_3 = Controller75F38Field(temp_v0_8, void **, 0);
            temp_s0_4=(unsigned char*)&frame.fourth.x;
            __asm__("" : "=r"(temp_s0_4) : "0"(temp_s0_4));
            Controller75F38Helper4F1C8(temp_s0_4,temp_v0_8+12,owner+12);
            temp_v0_9=Controller75F38Helper4EDE8(temp_s0_4,1);
            if (temp_v0_9 < 0x200) {
                Controller75F38Helper55D24(Controller75F38Field(tag, unsigned char **, 0x14), 4);
                temp_a2 = Controller75F38Field(tag, unsigned char **, 0x14);
                Controller75F38SpawnParticle(4, 0xC, temp_a2, Controller75F38Field(temp_a2, unsigned char *, 0x49));
                Controller75F38Field(temp_s1_3, short *, 0xA) = 0;
                Controller75F38Field(temp_s1_3, signed char *, 0xE) = (signed char) (rand() & 0xE);
                Controller75F38Field(temp_s1_3, signed char *, 0xF) = (signed char) (rand() & 0xE);
                Controller75F38Field(temp_s1_3, signed char *, 0x10) = (signed char) (rand() & 0xE);
                Controller75F38Helper4F504(temp_s1_3 + 4, Controller75F38Field(tag, unsigned char **, 0x14) + 0xC);
                Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x48) = 3U;
                Controller75F38Helper3BABC(Controller75F38Field(tag, unsigned char **, 0x14), 1, 0);
                Controller75F38Field(tag, unsigned char **, 0x14) = 0;
            } else {
                {register int threshold __asm__("$2")=310;
                 register void *adjustedVector __asm__("$4");
                 __asm__("" : "=r"(threshold) : "0"(threshold));
                 if(threshold<temp_v0_9) {
                    var_a2_3=310;
                    adjustedVector=temp_s0_4;
                    goto stateFourAdjust;
                 }
                 adjustedVector=temp_s0_4;
                 __asm__("" : "=r"(adjustedVector) : "0"(adjustedVector));
                 var_a2_3=290;
stateFourAdjust:
                 Controller75F38Helper4F08C(adjustedVector,temp_v0_9,var_a2_3);
                }
                {register void *first __asm__("$4")=owner+12;
                 register void *second __asm__("$5")=first;
                 __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16","$18");
                 temp_s0_4=(unsigned char*)&frame.fourth.x;
                 __asm__("" : "=r"(temp_s0_4) : "0"(temp_s0_4));
                 Controller75F38Helper4F194(first,second,temp_s0_4);
                }
                Controller75F38Helper3585C(owner, Controller75F38Helper4E880(frame.fourth.x, frame.fourth.y, 0), 0xAU, 0, 0, 0);
                tailMagnitude = Controller75F38Helper4EDE8(temp_s0_4,0);
                __asm__ volatile("" : "=r"(tailMagnitude) : "0"(tailMagnitude) : "$7");
                var_a0_4=tailMagnitude;
                var_a1 = frame.fourth.z;
                goto block_97;
            }
            break;
        case 5:
            {register int value __asm__("$2");
             register int offset __asm__("$3");
             register void *first __asm__("$4");
             register void *second __asm__("$5");
             register void *third __asm__("$6");
             temp_s0_5=(unsigned char*)&frame.fifth.x;
             __asm__("" : "=r"(temp_s0_5) : "0"(temp_s0_5));
             value=(int)Controller75F38Field(tag,void**,0x14);
             offset=Controller75F38Field(tag,short*,4);
             value=Controller75F38Field((void*)value,int*,12);
             __asm__("" : "=r"(value),"=r"(offset) : "0"(value),"1"(offset) : "$4");
             first=temp_s0_5;
             value+=offset;frame.fifth.x=value;
             value=(int)Controller75F38Field(tag,void**,0x14);
             offset=Controller75F38Field(tag,short*,6);
             value=Controller75F38Field((void*)value,int*,16);
             __asm__("" : "=r"(value),"=r"(offset) : "0"(value),"1"(offset) : "$5");
             second=temp_s0_5;
             value+=offset;frame.fifth.y=value;
             value=(int)Controller75F38Field(tag,void**,0x14);
             offset=Controller75F38Field(tag,short*,8);
             value=Controller75F38Field((void*)value,int*,20);
             __asm__("" : "=r"(value),"=r"(offset) : "0"(value),"1"(offset) : "$6");
             third=owner+12;
             value+=offset;frame.fifth.z=value;
             Controller75F38Helper4F1C8(first,second,third);
            }
            temp_v0_10 = Controller75F38Helper4EDE8(temp_s0_5,1);
            if (temp_v0_10 < 0x200) {
                temp_v0_11 = Controller75F38Field(tag, unsigned char **, 0x14);
                Controller75F38Field(temp_v0_11, int *, 0x18) = (int) (Controller75F38Field(temp_v0_11, int *, 0x18) | 0x10000000);
                Controller75F38Field(tag, unsigned char **, 0x14) = 0;
            } else {
                var_a2_4 = Controller75F38D_80065814 + 0xA;
                if (var_a2_4 >= temp_v0_10) {
                    var_a2_4 = Controller75F38D_80065814 - 0xA;
                }
                {register void *adjustedVector __asm__("$4")=temp_s0_5;
                 __asm__("" : "=r"(adjustedVector) : "0"(adjustedVector));
                 Controller75F38Helper4F08C(adjustedVector,temp_v0_10,var_a2_4);}
                __asm__ volatile("" : "=r"(owner) : "0"(owner));
                {register void *first __asm__("$4")=owner+12;
                 register void *second __asm__("$5")=first;
                 __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16","$17","$18","$21","$22","memory");
                 {register unsigned char *stack __asm__("$29");
                  __asm__ volatile("" : "=r"(stack));
                  temp_s0_5=stack+0x78;}
                 __asm__("" : "=r"(temp_s0_5) : "0"(temp_s0_5));
                 Controller75F38Helper4F194(first,second,temp_s0_5);
                }
                Controller75F38Helper3585C(owner, Controller75F38Helper4E880(frame.fifth.x, frame.fifth.y, 0), 0xAU, 0, 0, 0);
                var_a0_4 = Controller75F38Helper4EDE8(temp_s0_5,0);
                var_a1 = frame.fifth.z;
                goto block_97;
            }
            break;
block_97:
            temp_v0_4 = Controller75F38Helper4E880(var_a0_4, var_a1, 0);
            Controller75F38Field(owner, unsigned char *, 0x45) = temp_v0_4;
            Controller75F38Field(owner, unsigned char *, 0x45) = Controller75F38Helper36018(temp_v0_4 & 0xFF, 0, 0x30);
            break;
        case 9:                                     /* switch 1 */
            Controller75F38Field(tag, short *, 8) = 0x180;
            Controller75F38Field(tag, short *, 4) = 0;
            Controller75F38Field(tag, short *, 6) = 0;
            Controller75F38Field(owner, unsigned char *, 0x49) = 5U;
            break;
        }
    } else if (Controller75F38Field(Controller75F38D_80065830, void **, 0) != 0) {
        Controller75F38Helper4F1C8(&frame.first.x, Controller75F38Field(Controller75F38D_80065830, void **, 0) + 0xC, Controller75F38D_80070328);
        if (Controller75F38D_80065828 >= 0x401) {
            if (Controller75F38D_80065828 >= 0x4001) {
                Controller75F38Helper4F110(&frame.first.x, Controller75F38Helper4EA74(Controller75F38D_80065828) - 0xE);
            }
            {register int sample __asm__("$2")=*(unsigned short*)(Controller75F38D_800658A0+((Controller75F38D_8006C644*16)&0x1F0));
             register void *vector __asm__("$4");
             __asm__("" : "=r"(sample) : "0"(sample) : "$4");
             vector=&frame.first.x;
             __asm__("" : "=r"(sample),"=r"(vector) : "0"(sample),"1"(vector));
             sample=(sample<<16)>>21;
             Controller75F38Helper4EF04(vector,sample+1024);}
        }
        if (frame.first.z < -0x100) {
            frame.first.z = -0x100;
        }
        Controller75F38Field(owner, signed char *, 0x44) = 0;
        Controller75F38Field(owner, unsigned char *, 0x45) = Controller75F38Helper4E880(Controller75F38Helper4EDE8(&frame.first.x, 0), frame.first.z, 0);
        Controller75F38Field(owner, unsigned char *, 0x46) = Controller75F38Helper4E880(Controller75F38Field(owner, int *, 0xC) - Controller75F38Field(Controller75F38D_80070328, int *, 0), Controller75F38Field(owner, int *, 0x10) - Controller75F38Field(Controller75F38D_80070328, int *, 4), 0);
        Controller75F38Helper4F194(&frame.first.x, &frame.first.x, Controller75F38D_80070328);
        {register void *first __asm__("$4")=&frame.first.x;
         register void *second __asm__("$5")=first;
         __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16");
         temp_s0_2=owner+12;
         Controller75F38Helper4F1C8(first,second,temp_s0_2);}
        Controller75F38Helper4F110(&frame.first.x, 2);
        Controller75F38Helper4F194(temp_s0_2, temp_s0_2, &frame.first.x);
        if (Controller75F38Helper19194(temp_s0_2, 0x100) != 0) {
            Controller75F38Helper4F178(temp_s0_2, Controller75F38D_8007190C);
        }
    } else {
        var_a1_2 = 0;
        if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x50) == 0) && (Controller75F38Field(Controller75F38D_80070328, int *, 0x240) == 0) && !(Controller75F38Field(Controller75F38D_80070328, int *, 0x20C) & 8)) {
            var_a1_2 = Controller75F38D_8006E534 != 0;
        }
        if (var_a1_2 != 0) {
            var_a1_2 = Controller75F38Helper359A4(tag + 0xD, 1);
        } else {
            Controller75F38Field(tag, signed char *, 0xD) = 0x78;
        }
        temp_v0_12 = Controller75F38Field(tag, short *, 0);
        if (temp_v0_12 <= 0) {
            temp_v1_9 = Controller75F38Field(tag, unsigned char *, 3);
            __asm__("" : "=r"(temp_v1_9) : "0"(temp_v1_9));
            switch(temp_v1_9) {
            case 0:case 1:case 3:case 6:
                __asm__ volatile("" : : "r"(temp_v1_9));
                if((var_a1_2!=0)&&(rand()<0x2AAA)) {
                    temp_v0_13=Controller75F38Helper3636C(0,9);
                    switch(temp_v0_13) {
                    case 0:case 1:case 2:case 3:
                        stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        stateValue=3;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                        Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
                    case 4:case 5:case 6:
                        stateValue=12;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        stateValue=2;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                        Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
                    case 7:case 8:
                        stateValue=20;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        stateValue=6;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                        Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
                    case 9:
                        stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        goto selectFour;
                    }
                    goto reloadSelectedState;
                }
                temp_v1_9=Controller75F38Field(tag,unsigned char*,3);
                if(temp_v1_9==3) goto resetLarge;
                stateValue=4;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                goto resetZero;
            case 2:
                stateValue=12;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                if(var_a1_2==0) goto selectOneNoRandom;
                stateValue=rand()<0x3FFF;
                if(!stateValue) {stateValue=1;goto selectOne;}
selectFour:
                stateValue=4;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
selectOneNoRandom:
                stateValue=1;
selectOne:
                __asm__("" : "=r"(stateValue) : "0"(stateValue));
                Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
            case 4:
                stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                stateValue=5;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
            case 5:
resetLarge:
                stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
resetZero:
                Controller75F38Field(tag,unsigned char*,3)=0;
                goto reloadSelectedState;
            default:goto dispatchSelectedState;
            }
reloadSelectedState:
            temp_v1_9=Controller75F38Field(tag,unsigned char*,3);
dispatchSelectedState:
            __asm__ volatile("" : "=r"(temp_v1_9) : "0"(temp_v1_9));
            switch(temp_v1_9) {  /* switch 4 */
            case 0:                                 /* switch 4 */
            case 1:                                 /* switch 4 */
                __asm__ volatile("" : : "r"(temp_v1_9));
                frame.first.x = -0x258;
                frame.first.y = (rand() & 0x310) - 0x188;
                if (Controller75F38D_8006E044 == 2) {
                    var_v0_5 = (rand() & 0x7F) + 0x64;
                } else {
                    var_v0_5 = (rand() & 0x1FF) - 0xC8;
                }
                frame.first.z = var_v0_5;
                if (Controller75F38Field(tag, unsigned char *, 0xA) != 0) {
                    frame.first.x = -0xC8;
                    frame.first.z = (rand() & 0x7F) - 0xFA;
                }
                Controller75F38Field(tag, short *, 4) = (short) frame.first.x;
                Controller75F38Field(tag, short *, 6) = (short) frame.first.y;
                Controller75F38Field(tag, short *, 8) = (short) frame.first.z;
                if (Controller75F38Field(tag, unsigned char *, 3) == 0) {
                    Controller75F38Field(tag, short *, 0) = (short) ((rand() & 0x3F) + 0x3C);
                    Controller75F38Field(tag, unsigned char *, 0xB) = 5U;
                } else goto resetTimer;
                break;
            case 2:                                 /* switch 4 */
                Controller75F38Field(tag, short *, 4) = 0x1F4;
                Controller75F38Field(tag, short *, 8) = 0x12C;
                Controller75F38Field(tag, short *, 6) = 0;
                Controller75F38Field(tag, short *, 0) = 0x78;
                break;
            case 3:                                 /* switch 4 */
                Controller75F38Field(tag, short *, 0) = (short) ((rand() & 0x1F) + 0x3C);
                break;
            case 4:                                 /* switch 4 */
            case 5:                                 /* switch 4 */
                {register int selected __asm__("$2")=Controller75F38Helper3636C(0,3);
                 register int value __asm__("$3")=700;
                 __asm__("" : "=r"(selected),"=r"(value) : "0"(selected),"1"(value) : "$16");
                 temp_s0_3=selected;
                 Controller75F38Field(tag,short*,4)=value;}
                if(Controller75F38Field(tag,unsigned char*,3)==4) {
                    var_v0_8=rand()<0x3FFF;
                    if(var_v0_8) {var_v0_8=temp_s0_3<<1;goto positiveOffset;}
                    var_v0_8=temp_s0_3<<1;var_v0_8+=temp_s0_3;
                    goto negativeCompute;
                }
                var_v0_8=Controller75F38Field(tag,short*,6);
                if(var_v0_8>=0) {var_v0_8=temp_s0_3<<1;goto negativeOffset;}
                var_v0_8=temp_s0_3<<1;
positiveOffset:
                var_v0_8+=temp_s0_3;
                __asm__("" : "=r"(var_v0_8) : "0"(var_v0_8) : "$7");
                var_v0_8=(var_v0_8<<3)+temp_s0_3;var_v0_8<<=1;
                var_v0_8+=100;goto storeOffset;
negativeOffset:
                __asm__ volatile("" : "=r"(temp_s0_3) : "0"(temp_s0_3));
                var_v0_8+=temp_s0_3;
negativeCompute:
                __asm__("" : "=r"(var_v0_8) : "0"(var_v0_8) : "$6");
                var_v0_8=(var_v0_8<<3)+temp_s0_3;var_v0_8<<=1;
                var_v0_8=-var_v0_8-100;
storeOffset:
                Controller75F38Field(tag, short *, 6) = var_v0_8;
                __asm__ volatile("" ::: "memory");
                {register int selected __asm__("$2")=Controller75F38Helper3636C(0,3);
                 temp_v1_10=selected*50;
                 __asm__("" : "=r"(temp_v1_10) : "0"(temp_v1_10) : "$2");
                 stateValue=60;Controller75F38Field(tag,short*,0)=stateValue;
                 stateValue=10;
                 __asm__("" : "=r"(stateValue) : "0"(stateValue));
                 Controller75F38Field(tag,short*,8)=temp_v1_10;
                 Controller75F38Field(tag,unsigned char*,11)=stateValue;}
                break;
            case 6:
resetTimer:
                Controller75F38Field(tag,short*,0)=120;
                break;
            }
        } else {
            Controller75F38Field(tag, short *, 0) = (short) (temp_v0_12 - Controller75F38D_8006C648);
            if ((Controller75F38Field(tag, unsigned char *, 3) != 0) && (var_a1_2 == 0)) {
                Controller75F38Field(tag, short *, 0) = 0;
            }
            temp_v1_11 = Controller75F38Field(tag, unsigned char *, 3);
            switch (temp_v1_11) {                   /* switch 5 */
            case 0:                                 /* switch 5 */
            case 4:                                 /* switch 5 */
            case 5:                                 /* switch 5 */
                temp_v1_12 = Controller75F38Field(tag, unsigned char *, 0xB);
                if (temp_v1_12 & 1) {
                    if ((Controller75F38D_8006E044 == 2) || (Controller75F38Field(Controller75F38D_80070328, int *, 0x50) == 0xC)) {
                        frame.first.x = Controller75F38Field(tag, short *, 4) + ((int) Controller75F38Field(Controller75F38D_80070328, int *, 0xB0) >> 2);
                        frame.first.y = (int) Controller75F38Field(tag, short *, 6);
                        temp_a0_7 = Controller75F38Field(tag, short *, 8);
                        frame.first.z = (int) temp_a0_7;
                        if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x50) != 0xC) && (temp_a0_7 < 0x64)) {
                            frame.first.z = 0x64;
                        }
                    } else {
                        if (Controller75F38D_8006E044 == 7) {
                            var_v0_9 = Controller75F38Field(tag, short *, 4) - 0x200;
                        } else {
                            var_v0_9 = Controller75F38Field(tag, short *, 4);
                        }
                        frame.first.x = (int) var_v0_9;
                        frame.first.y = (int) Controller75F38Field(tag, short *, 6);
                        frame.first.z = (int) Controller75F38Field(tag, short *, 8);
                    }
                    temp_s0_4 = Controller75F38D_80070328 + 0x30;
                    Controller75F38Helper4ED6C(temp_s0_4, &frame.first.x, &frame.first.x);
                    matrixFirst=&frame.first.x;matrixSecond=matrixFirst;
                    __asm__("" : "=r"(matrixFirst),"=r"(matrixSecond) : "0"(matrixFirst),"1"(matrixSecond) : "$6");
                    var_a2_5 = temp_s0_4 - 0x30;
                    goto transformOffset;
                }
                if (temp_v1_12 & 2) {
                    Controller75F38Helper4ECF4(&frame.matrix[0], Controller75F38D_8006E00C);
                    Controller75F38Helper4F554(&frame.first.x, tag + 4);
                    Controller75F38Helper4ED6C(&frame.matrix[0], &frame.first.x, &frame.first.x);
                    matrixFirst=&frame.first.x;matrixSecond=matrixFirst;
                    __asm__("" : "=r"(matrixFirst),"=r"(matrixSecond) : "0"(matrixFirst),"1"(matrixSecond) : "$6");
                    var_a2_5 = Controller75F38D_8006E00C + 0x14;
transformOffset:
                    Controller75F38Helper4F194(matrixFirst,matrixSecond,var_a2_5);
                }
                {register void *first __asm__("$4")=&frame.first.x;
                 register void *second __asm__("$5")=first;
                 __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16");
                 temp_s0_5=owner+12;
                 Controller75F38Helper4F1C8(first,second,temp_s0_5);}
                Controller75F38Helper4F110(&frame.first.x, 2);
                Controller75F38Helper4F194(temp_s0_5, temp_s0_5, &frame.first.x);
                if (Controller75F38Helper19194(temp_s0_5, 0x100) != 0) {
                    Controller75F38Helper4F178(temp_s0_5, Controller75F38D_8007190C);
                }
                if (frame.first.z >= 0x21) {
                    frame.first.z = 0x20;
                }
                if (frame.first.z < -0x20) {
                    frame.first.z = -0x20;
                }
                Controller75F38Field(owner, signed char *, 0x44) = 0;
                Controller75F38Field(owner, unsigned char *, 0x45) = (unsigned char) frame.first.z;
                temp_v1_13 = Controller75F38Field(tag, unsigned char *, 0xB);
                {register int flag __asm__("$2")=temp_v1_13&4;
                 __asm__("" : "=r"(flag) : "0"(flag) : "$4");
                 commonOwner=owner;
                if (flag) {
                    var_a1_3 = Controller75F38Field(Controller75F38D_80070328, unsigned char *, 0xE);
                    __asm__ volatile("" : "=r"(var_a1_3) : "0"(var_a1_3) : "$6");
                    goto applyOwnerAngle;
                } else {
                    __asm__ volatile("" : "=r"(temp_v1_13) : "0"(temp_v1_13));
                    {register int zero __asm__("$7");
                     flag=temp_v1_13&8;
                     __asm__("" : "=r"(flag) : "0"(flag) : "$7");
                     zero=0;
                    if (flag) {
                    __asm__("" : "=r"(zero) : "0"(zero));
                    Controller75F38Helper3585C(commonOwner, (((int) (Controller75F38D_8006E040 << 0x10) >> 0x14) + 0x80) & 0xFF, Controller75F38Field(tag, unsigned char *, 0xC), zero, 0, 0);
                    }
                    }
                }
                }
                break;
            case 1:                                 /* switch 5 */
            case 2:                                 /* switch 5 */
                temp_s0_5=&frame.sixth.x;
                {register void *vector __asm__("$4")=temp_s0_5;
                 __asm__("" : "=r"(vector) : "0"(vector) : "$22");
                 ownerPosition=owner+12;
                 Controller75F38Helper4F1C8(vector,ownerPosition,Controller75F38D_80070328);}
                initialMagnitude = Controller75F38Helper4EDE8(&frame.sixth.x, 0);
                initialAngle = Controller75F38Helper4E880(frame.sixth.x, frame.sixth.y, 0);
                Controller75F38Helper4F554(&frame.sixth.x, tag + 4);
                Controller75F38Helper4ED6C(Controller75F38D_80070328 + 0x30, &frame.sixth.x, &frame.sixth.x);
                {register int magnitude __asm__("$2")=Controller75F38Helper4EDE8(&frame.sixth.x,0);
                 register int zero __asm__("$6")=0;
                 register int x __asm__("$4"); register int y __asm__("$5");
                 __asm__ volatile("" : "=r"(magnitude) : "0"(magnitude));
                 __asm__("" : "=r"(zero) : "0"(zero) : "$4","$5");
                 x=frame.sixth.x;y=frame.sixth.y;
                 __asm__("" : "=r"(x),"=r"(y),"=r"(magnitude) : "0"(x),"1"(y),"2"(magnitude));
                 magnitudeDelta=magnitude;
                 magnitude=Controller75F38Helper4E880(x,y,zero);
                 x=magnitude;y=initialAngle;
                 __asm__("" : "=r"(x),"=r"(y),"=r"(magnitudeDelta) : "0"(x),"1"(y),"2"(magnitudeDelta));
                 magnitudeDelta=(magnitudeDelta-initialMagnitude)>>3;
                 magnitude=Controller75F38Helper4F2A4(x,y);
                 magnitude>>=3;magnitude=initialAngle+magnitude;
                 adjustedAngle=magnitude&255;}
                temp_a1_4 = adjustedAngle * 2;
                {register int sample __asm__("$2")=*(short*)(Controller75F38D_80065920+temp_a1_4);
                 register int vertical __asm__("$3");register int playerX __asm__("$4");register int playerZ __asm__("$6");
                 register int product __asm__("$8");
                 __asm__("" : "=r"(sample) : "0"(sample) : "$17");
                 adjustedMagnitude=initialMagnitude+magnitudeDelta;
                 product=sample*adjustedMagnitude;
                 vertical=frame.sixth.z;playerX=Controller75F38Field(Controller75F38D_80070328,int*,0);
                 playerZ=Controller75F38Field(Controller75F38D_80070328,int*,8);
                 __asm__("" : "=r"(vertical),"=r"(playerX),"=r"(playerZ),"=r"(product) : "0"(vertical),"1"(playerX),"2"(playerZ),"3"(product));
                 sample=(product>>12)+playerX;Controller75F38Field(owner,int*,12)=sample;
                 sample=*(short*)(Controller75F38D_800658A0+temp_a1_4);
                 product=sample*adjustedMagnitude;
                 __asm__("" : "=r"(sample),"=r"(vertical) : "0"(sample),"1"(vertical) : "$4","$5");
                 vertical+=playerZ;
                 movementPosition=ownerPosition;
                 __asm__("" : "=r"(movementPosition) : "0"(movementPosition) : "$2","$5");
                 sample=Controller75F38Field(owner,int*,20);
                 __asm__("" : "=r"(sample) : "0"(sample) : "$5");
                 movementRadius=256;
                 __asm__("" : "=r"(sample),"=r"(vertical),"=r"(movementRadius) : "0"(sample),"1"(vertical),"2"(movementRadius));
                 vertical-=sample;verticalStep=vertical>>3;
                 sample=Controller75F38Field(owner,int*,20);
                 vertical=Controller75F38Field(Controller75F38D_80070328,int*,4);
                 __asm__("" : "=r"(sample),"=r"(vertical) : "0"(sample),"1"(vertical));
                 sample+=verticalStep;Controller75F38Field(owner,int*,20)=sample;
                 __asm__ volatile("" ::: "memory");
                 sample=(product>>12)+vertical;Controller75F38Field(owner,int*,16)=sample;}
                if (Controller75F38Helper19194(movementPosition, movementRadius) != 0) {
                    Controller75F38Helper4F178(ownerPosition, Controller75F38D_8007190C);
                    __asm__ volatile("" : "=r"(verticalStep) : "0"(verticalStep));
                }
                var_v0_10 = verticalStep < 0x21;
                Controller75F38Field(owner, signed char *, 0x44) = 0;
                if (var_v0_10 == 0) {
                    verticalStep = 0x20;
                }
                if (verticalStep < -0x20) {
                    verticalStep = -0x20;
                }
                Controller75F38Field(owner, unsigned char *, 0x45) = (unsigned char) verticalStep;
                {register int state __asm__("$3")=Controller75F38Field(tag,unsigned char*,3);
                 register int one __asm__("$2");
                 __asm__("" : "=r"(state) : "0"(state) : "$2");
                 one=1;
                if (state == one) {
                    if (Controller75F38Field(tag, short *, 0) < 0x65) {
                        commonOwner=owner;
                        __asm__("" : "=r"(commonOwner) : "0"(commonOwner) : "$5");
                        var_a1_3 = Controller75F38Field(Controller75F38D_80070328, unsigned char *, 0xE);
                        __asm__ volatile("" : "=r"(var_a1_3) : "0"(var_a1_3) : "$7");
                        goto applyOwnerAngle;
                    }
                    var_v0_11 = adjustedAngle - 0x80;
                    goto storeOwnerAngle;
                } else {var_v0_11=adjustedAngle-128;}
                }
storeOwnerAngle:
                __asm__ volatile("" : : "r"(adjustedAngle));
                Controller75F38Field(owner, unsigned char *, 0x46) = var_v0_11;
                break;
            case 3:                                 /* switch 5 */
                {register int angle __asm__("$2")=Controller75F38Helper4E880(Controller75F38D_8006E020 - Controller75F38Field(owner, int *, 0xC), Controller75F38D_8006E024 - Controller75F38Field(owner, int *, 0x10), 0);
                 commonOwner=owner;
                 __asm__("" : "=r"(commonOwner) : "0"(commonOwner) : "$5");
                 var_a1_3=angle;}
applyOwnerAngle:
                Controller75F38Helper3585C(commonOwner,var_a1_3,Controller75F38Field(tag,unsigned char*,12),0,0,0);
                break;
            case 6:                                 /* switch 5 */
                if (Controller75F38Callback(owner, Controller75F38D_80070328, 0, Controller75F38Field(owner, unsigned char *, 0x46), 8, 0xA0, (int) Controller75F38Field(tag, unsigned char *, 0xC), 0x80, 0xFF, 0xFF, 0, 0, 0) < 0) {
                    Controller75F38Field(tag, short *, 0) = 0;
                }
                {register int ownerHeight __asm__("$2")=Controller75F38Field(owner,int*,20);
                 register int playerHeight __asm__("$3")=Controller75F38Field(Controller75F38D_80070328,int*,8);
                 __asm__("" : "=r"(ownerHeight),"=r"(playerHeight) : "0"(ownerHeight),"1"(playerHeight));
                 ownerHeight-=300;playerHeight-=ownerHeight;playerHeight>>=2;
                 frame.first.z=playerHeight;
                 ownerHeight=Controller75F38Field(owner,int*,20);
                 Controller75F38Field(owner,int*,20)=ownerHeight+playerHeight;}
                break;
            }
        }
    }
    if ((Controller75F38Field(tag, void **, 0x10) != 0) && (Controller75F38Field(owner, unsigned char *, 0x46) != originalAngle)) {
        Controller75F38Helper55D24(owner, 4);
    }
    {register int tableIndex __asm__("$2")=Controller75F38Field(Controller75F38TablePlayer,int*,0x280);
     __asm__("" : "=r"(tableIndex) : "0"(tableIndex));
     Controller75F38Field(owner,int*,0x54)=*(int*)(Controller75F38D_8006585C+(tableIndex<<2));}
    __asm__ volatile("" ::: "$4","$5","$6","$7","memory");
    temp_v1_15 = Controller75F38Field(tag, void **, 0x10);
    if (temp_v1_15 != 0) {
        if (Controller75F38Field(Controller75F38D_80070328, int *, 0x280) >= 4) {
            Controller75F38Field(temp_v1_15, signed char *, 0x10) = (signed char) Controller75F38Field(Controller75F38D_80070328, int *, 0x280);
        } else {
            Controller75F38Field(temp_v1_15, signed char *, 0x10) = 1;
        }
        Controller75F38Helper55F14(owner, 0, Controller75F38Field(tag, void **, 0x10));
    }
    if ((Controller75F38Field(owner, unsigned char *, 0x3D) == 1) && (Controller75F38D_8006C770 != 0)) {
        Controller75F38Helper34F40(owner, 0);
    }
}

typedef struct {
    short counter;
    unsigned char unk2, unk3;
} DecodedColourTag;
void func_80055B18(Moby*);
void func_level_50_80077C68(Moby* moby) {
    DecodedColourTag* tag = moby->mobyTag;
    if (func_800359A4(tag, 2)) func_80055B18(moby);
    if (tag->unk2 == 0) {
        short value = tag->counter;
        if (value < 8) {
            moby->colour.r = value << 4;
            moby->colour.g = 0;
        } else moby->colour.g = (value - 8) << 4;
    } else if (tag->unk2 == 1) {
        short value = tag->counter;
        if (value < 8) {
            moby->colour.g = value << 4;
            moby->colour.r = 0;
        } else moby->colour.r = (value - 8) << 4;
    } else if (tag->unk2 == 2) {
        moby->colour.r -= 8;
        moby->colour.g -= 8;
        moby->colour.b -= 8;
        moby->colour.a = (unsigned short)tag->counter;
    }
    if (tag->unk3 == 0) moby->size = *(unsigned char*)tag * 2 + 0x30;
    else moby->size = *(unsigned char*)tag * 4 + 0x34;
}

extern int deltaTime;
int func_800359A4(void*, int);
void func_80055B18(Moby*);
void func_level_50_80077DA4(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4)) func_80055B18(moby);
    {
        int value = 0x10 - tag[0];
        if (value < 0) value = 0;
        moby->colour.a = value + 0x30;
    }
    moby->size -= deltaTime * 6;
    if (moby->size >= 0x80) moby->size = 0;
    if (moby->size < 0x18) moby->size = 0x18;
}

extern int deltaTime;
int func_800359A4(void*, int);
void func_80055B18(Moby*);
void func_level_50_80077E60(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4)) func_80055B18(moby);
    moby->colour.r = tag[0] << 3;
    moby->colour.g = tag[0] << 2;
    moby->size -= deltaTime * 3;
    if (moby->size >= 0x80) moby->size = 0;
    if (moby->size < 0xE) moby->size = 0xE;
}

typedef struct {
    int timer, roll, pitch, z, groundGate, feedback;
    signed char* table;
} DecodedRaw201Tag;
typedef struct {
    short counter;
    unsigned char sound, reserved03[17];
    Moby* target;
} DecodedRaw201SparxTag;
extern int DecodedRaw201Profile __asm__("D_80070328 + 0x24C");
extern unsigned char DecodedRaw201Player[] __asm__("D_80070328");
extern int DecodedRaw201Enable __asm__("D_8006581C");
extern int DecodedRaw201Planar __asm__("D_80065810");
extern int DecodedRaw201Vertical __asm__("D_80065818");
extern int DecodedRaw201Tick __asm__("D_8006C648");
extern Moby* DecodedRaw201Sparx __asm__("D_8006C65C");
extern int DecodedRaw201Capacity __asm__("D_8006C578");
extern int DecodedRaw201Active __asm__("D_8006C574");
void DecodedRaw201Ground(Moby*) __asm__("func_80037014");
int DecodedRaw201Distance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int DecodedRaw201Collision(Vector3D*, Vector3D*, int) __asm__("func_80013E38");
int DecodedRaw201SoundActive(Moby*, int) __asm__("func_8003BFC0");
int DecodedRaw201Sound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedRaw201Feedback(Moby*, int, int) __asm__("func_800368A4");
void DecodedRaw201Copy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DecodedRaw201Collectible(Moby*, int, int, int) __asm__("func_80036A68");
void DecodedRaw201Delete(Moby*) __asm__("func_80055B18");
int rand(void);
/* SCUS-94467 Rev 0: level_10 0x80077748..0x80077C64.
* Baseline: Rev 1 sunrise_spring_type201_runtime.py, checked against each
* original Rev 0 branch, mask and access width. Empty asm constraints emit
* no instructions; they preserve the retail compiler temporary lifetimes.
* AI generated; not yet human reviewed. See the batch provenance document.
*/
void func_level_50_80077F14(Moby* argument) {
    Vector3D particlePosition;
    int reservedStack[2];
    register Moby* moby __asm__("$17") = argument;
    register int* profile __asm__("$20");
    register unsigned int breakMask __asm__("$19");
    register DecodedRaw201Tag* tag __asm__("$18");
    __asm__("" : "=r"(moby) : "0"(moby));
    breakMask = 0x04140000;
    profile = &DecodedRaw201Profile;
    tag = moby->mobyTag;
    {
        register int currentProfile __asm__("$2") = *profile;
        register int expectedProfile __asm__("$3") = 1;
        if (currentProfile == expectedProfile) breakMask = 0x041C0000;
        __asm__("" : : "r"(expectedProfile));
    }
    if (tag->groundGate) DecodedRaw201Ground(moby);
    if (DecodedRaw201Enable >= 2 && moby->mobyClass == 201) {
        register Vector3D* position __asm__("$16") = &moby->position;
        register int delta __asm__("$3");
        if (DecodedRaw201Distance(position, (Vector3D*)((char*)profile - 0x24C)) < DecodedRaw201Planar) {
            {
                register int actorHeight __asm__("$2") = moby->position.z + 356;
                __asm__("" : "=r"(actorHeight) : "0"(actorHeight));
                delta = *(int*)(DecodedRaw201Player + 8) - actorHeight;
            }
            {
                register int limit __asm__("$2") = DecodedRaw201Vertical;
                __asm__("" : "=r"(limit) : "0"(limit));
                if (delta < 0) delta = -delta;
                delta = delta < limit;
                __asm__("" : "=r"(delta) : "0"(delta));
                if (delta && DecodedRaw201Sparx &&
                DecodedRaw201Collision(&DecodedRaw201Sparx->position, position, 4)) {
                    register DecodedRaw201SparxTag* sparxTag __asm__("$16") = DecodedRaw201Sparx->mobyTag;
                    if (sparxTag->target) {
                        if (sparxTag->target != moby && sparxTag->counter > 0) sparxTag->counter = 0;
                    } else {
                        DecodedRaw201Sparx->substate = 9;
                        sparxTag->target = moby;
                        sparxTag->counter = 0;
                        if (!DecodedRaw201SoundActive(DecodedRaw201Sparx, sparxTag->sound))
                        sparxTag->sound = DecodedRaw201Sound(DecodedRaw201Sparx, 0, 0);
                    }
                }
            }
        }
    }
    if (tag->timer) {
        tag->timer += DecodedRaw201Tick;
        if (tag->timer < 64) {
            register int first __asm__("$3");
            register int second __asm__("$2");
            register signed char* pair __asm__("$2");
            moby->angle.roll = (unsigned char)tag->table[(tag->timer >> 1) * 2] + tag->roll;
            moby->angle.pitch = (unsigned char)tag->table[(tag->timer >> 1) * 2 + 1] + tag->pitch;
            pair = (signed char*)((tag->timer >> 1) * 2 + (unsigned int)tag->table);
            __asm__("" : "=r"(pair) : "0"(pair));
            first = pair[0];
            second = pair[1];
            if (first < 0) first = -first;
            if (second < 0) second = -second;
            first += second;
            __asm__("" : "=r"(first) : "0"(first));
            second = first * 3;
            __asm__("" : "=r"(second) : "0"(second));
            first = tag->z;
            __asm__("" : "=r"(first) : "0"(first));
            first += second * 2;
            moby->position.z = first;
        } else {
            tag->timer = 0;
            moby->angle.roll = tag->roll;
            moby->angle.pitch = tag->pitch;
            moby->position.z = tag->z;
        }
    }
    if (moby->mobyClass == 201) breakMask |= 0x12820000;
    else if (moby->mobyClass == 202) breakMask |= 0x80000;
    if (moby->damageFlags & breakMask) {
        register int attempts __asm__("$18");
        register int leadingCount __asm__("$20");
        register int childClass __asm__("$19");
        register int index __asm__("$16");
        register int leadingMode __asm__("$22");
        register int one __asm__("$21");
        int brokenSubstate;
        DecodedRaw201Sound(moby, 0, 0);
        if (moby->mobyClass == 201) {
            brokenSubstate = 100;
            attempts = 12;
            leadingCount = 5;
            childClass = 307;
        } else {
            brokenSubstate = 144;
            attempts = 16;
            leadingCount = 8;
            childClass = 308;
        }
        moby->substate = brokenSubstate;
        __asm__("" : "=r"(attempts) : "0"(attempts));
        index = 0;
        if (attempts != 0) {
            leadingMode = 5;
            one = 1;
            do {
                register Moby* child __asm__("$4");
                register int normalMode __asm__("$2");
                register int parentClass __asm__("$3");
                register int expectedClass __asm__("$2");
                if (DecodedRaw201Capacity - DecodedRaw201Active < 21) break;
                child = SpawnMoby(childClass, moby);
                __asm__("" : "=r"(child) : "0"(child));
                if (index < leadingCount) child->substate = leadingMode;
                else {
                    normalMode = 4;
                    __asm__("" : "=r"(normalMode) : "0"(normalMode));
                    child->animationState.id = one;
                    child->substate = normalMode;
                }
                parentClass = moby->mobyClass;
                expectedClass = 201;
                __asm__("" : "=r"(expectedClass) : "0"(expectedClass));
                if (parentClass != expectedClass) child->colour.r = one;
                index++;
            } while (index < attempts);
        }
        index = 0;
        if (moby->mobyClass != 201) goto particleLoop;
fourParticles:
        if (index >= 4) goto particlesDone;
particleLoop:
        {
            DecodedRaw201Copy(&particlePosition, &moby->position);
            index++;
            {
                register int sample __asm__("$2") = rand() & 255;
                register int coordinate __asm__("$3") = particlePosition.x + 128;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                coordinate -= sample;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                particlePosition.x = coordinate;
            }
            {
                register int sample __asm__("$2") = rand() & 255;
                register int coordinate __asm__("$3") = particlePosition.y + 128;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                coordinate -= sample;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                particlePosition.y = coordinate;
            }
            particlePosition.z += rand() & 511;
            SpawnParticle(1, 2, &particlePosition, 0);
            SpawnParticle(4, 70, &particlePosition, 24);
        }
        if (moby->mobyClass == 201) goto fourParticles;
        /* Preserve the original four-count branch and delay slot. */
        __asm__ volatile("" : : : "memory");
        if (index < 8) goto particleLoop;
particlesDone:
        DecodedRaw201Collectible(moby, 0, 0, 0);
        DecodedRaw201Delete(moby);
        moby->damageFlags = 0;
        return;
    }
    tag->feedback = DecodedRaw201Feedback(moby, tag->feedback, moby->mobyClass != 201);
    if ((moby->damageFlags & 0x30000) && !tag->timer) {
        tag->timer = 1;
        tag->roll = moby->angle.roll;
        tag->pitch = moby->angle.pitch;
        tag->z = moby->position.z;
        if ((unsigned int)(unsigned short)moby->mobyClass - 202 < 2)
        DecodedRaw201Sound(moby, 1, 0);
    }
    moby->damageFlags = 0;
}

extern int D_8006E020, D_8006E024, D_8007191C, D_80071920;
extern Vector3D D_8007190C;
extern int D_8006C644;
extern short D_800658A0[], D_80065920[];
int func_80019194(Vector3D*, int);
int func_8001A358(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8005629C(Moby*);
void func_level_50_80078434(Moby *moby) {
    Vector3D offset;
    /* Retail reserves eight further stack bytes; their source purpose is unknown. */
    int reservedStack[2];
    Vector3D* collisionBase;
    Vector3D *tagVector;
    Vector3D *position;
    Vector3D *normal;
    int tagZ;
    int positionZ;
    int dotProduct;
    MobyTag_260 *tag;

    tag = moby->mobyTag;
    if (moby->substate == 0) {
        if (tag->unk4 > 0) {
            moby->angle.yaw += 1;
            tagZ = tag->unkC.z - 6;
            tag->unkC.z = tagZ;
            if (tagZ < -0x80) {
                tag->unkC.z = -0x80;
            }
            moby->position.x += tag->unkC.x;
            moby->position.y += tag->unkC.y;
            positionZ = moby->position.z + tag->unkC.z;
            moby->position.z = positionZ;
            position = &moby->position;
            if (positionZ >= 0x400) {
                func_8001A358(position, 0x2000);
                func_8005629C(moby);
                if (func_80019194(position, 0x100) != 0) {
                    collisionBase = &D_8007190C;
                    func_8004F178(position, collisionBase);
                    normal = collisionBase + 1;
                    func_8004EF04(normal, 0x1000);
                    dotProduct = (int) ((tag->unkC.x * ((Vector3D*)(collisionBase + 1))->x) + (tag->unkC.y * D_8007191C) + (tag->unkC.z * D_80071920)) >> 0xB;
                    if (dotProduct < 0) {
                        func_8004F08C(normal, 0x1000, -dotProduct);
                        tagVector = &tag->unkC;
                        func_8004F194(tagVector, tagVector, normal);
                    }
                }
                tag->unk4 = (int) (tag->unk4 - 1);
                return;
            }
            goto deleteActor;
        }
        SpawnParticle(0xA, 0x47, &moby->position, 0);
        goto deleteActor;
    }
    if (tag->unk0->state != 0) {
deleteActor:
        func_80055B18(moby);
        return;
    }
    {
        /* These empty constraints emit no instructions and retain retail scheduling. */
        register int retainedOppositeAngle __asm__("$5");
        int wave;
        register short* sineTable __asm__("$6");
        register int angleByteOffset __asm__("$4");
        register int angle __asm__("$2");
        register int oppositeAngle __asm__("$2");
        register int heading __asm__("$4");
        angle = func_8004E880(D_8006E020 - moby->position.x, D_8006E024 - moby->position.y, 0);
        heading = angle;
        oppositeAngle = angle + 0x80;
        __asm__("" : "=r"(oppositeAngle) : "0"(oppositeAngle));
        sineTable = D_800658A0;
        wave = (int)(*(unsigned short*)((char*)D_800658A0 + ((D_8006C644 * 8) & 0x1F8)) << 16) >> 23;
        retainedOppositeAngle = oppositeAngle;
        __asm__("" : "=r"(wave), "=r"(retainedOppositeAngle), "=r"(sineTable) : "0"(wave), "1"(retainedOppositeAngle), "2"(sineTable));
        wave += oppositeAngle;
        __asm__("" : "=r"(wave) : "0"(wave));
        moby->angle.yaw = wave;
        if (moby->substate == 2) {
            heading = retainedOppositeAngle;
        }
        offset.x = 0;
        offset.y = 0;
        angleByteOffset = heading & 0xFF;
        if (moby->substate != 3) {
            register short* divisionEntry __asm__("$2");
            /* High word of the compiler reciprocal for signed division by 28. */
            register unsigned int divisionMagicHigh __asm__("$5") = 0x92490000U;
            __asm__("" : "=r"(angleByteOffset) : "0"(angleByteOffset), "r"(divisionMagicHigh));
            angleByteOffset *= 2;
            divisionEntry = (short*)(angleByteOffset + (unsigned int)sineTable);
            __asm__("" : "=r"(divisionEntry) : "0"(divisionEntry));
            offset.x = (int)(short)(*divisionEntry / 28);
            offset.y = -*(short*)((char*)D_80065920 + angleByteOffset) / 28;
        }
        offset.z = 0x520;
    func_8004F194(&moby->position, &tag->unk0->position, &offset);
    }
}


#define Controller78288Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller78288Helper1A358(void*,int) __asm__("func_8001A358");
void* Controller78288Helper2EC50(int,int,int) __asm__("func_8002EC50");
void* Controller78288Helper2F540(int,int,int) __asm__("func_8002F540");
int Controller78288Helper34F40(void*,int) __asm__("func_80034F40");
int Controller78288Helper3573C(void*,int,int,int) __asm__("func_8003573C");
int Controller78288Helper3585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Controller78288Helper37BBC(void*,int) __asm__("func_80037BBC");
int Controller78288Helper3B634(void*,void*,int) __asm__("func_8003B634");
int Controller78288Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller78288Helper492DC(void*) __asm__("func_800492DC");
int Controller78288Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller78288Helper4F0E8(void*,int) __asm__("func_8004F0E8");
int Controller78288Helper4F110(void*,int) __asm__("func_8004F110");
int Controller78288Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller78288Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller78288Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Controller78288Helper4F228(void*,void*,int) __asm__("func_8004F228");
int Controller78288Helper4F334(void*,void*) __asm__("func_8004F334");
int Controller78288Helper512E4(void*,int,int) __asm__("func_800512E4");
int Controller78288Helper55B18(void*) __asm__("func_80055B18");
int Controller78288Helper55D24(void*,int) __asm__("func_80055D24");
int Controller78288Helper55E84(void*) __asm__("func_80055E84");
int Controller78288Helper55F14(void*,int,void*) __asm__("func_80055F14");
extern unsigned char Controller78288D_80065920[] __asm__("D_80065920");
extern int Controller78288D_8006C550 __asm__("D_8006C550");
extern int Controller78288D_8006C58C __asm__("D_8006C58C");
extern int Controller78288D_8006C644 __asm__("D_8006C644");
extern int Controller78288D_8006C704 __asm__("D_8006C704");
extern int Controller78288D_8006C770 __asm__("D_8006C770");
extern int Controller78288D_8006C79C __asm__("D_8006C79C");
extern unsigned char Controller78288D_8006D088[] __asm__("D_8006D088");
extern int Controller78288D_8006E044 __asm__("D_8006E044");
extern int Controller78288D_8006E160 __asm__("D_8006E160");
extern int Controller78288D_8006E344 __asm__("D_8006E344");
extern unsigned char Controller78288D_80070328[] __asm__("D_80070328");
extern unsigned char Controller78288D_80071AB0[] __asm__("D_80071AB0");
extern int (*Controller78288SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original authority: the 32 copies in build/family3038.json, beginning
 * level12/80078288. All 733 instructions, exact helper/global identities
 * and eight jump-table target offsets were independently compared.
 * Retain the 112-byte frame and four byte-addressed vector slots at
 * 0x18/0x28/0x38/0x48; original signed/unsigned reads, index low products,
 * bitset banks, state exits, handle reloads, clamps and helper arguments.
 * Empty compiler constraints preserve original allocation/scheduling;
 * no opcode patches. Numeric domains, helper semantics and caller cadence
 * remain unresolved. Updates occur once per invocation. Confidence is
 * exact compiled native/linked words and complete retail hashes, not a
 * semantic runtime review. Falsifiable vectors: every original word/table
 * at its recorded address and full executable/all-overlay SHA set.
 */
void func_level_50_80078738(void *input) {
    struct { struct {int x,y,z;} first; int p24; struct {int x,y,z;} second; int p34; struct {int x,y,z;} third; int p44; struct {int x,y,z;} fourth; int p54; } frame;
    register int kind __asm__("$3");
    register unsigned char *owner __asm__("$18")=input;
    register unsigned char *handleOwnerPosition __asm__("$16");
    register unsigned char *playerHeightAddress __asm__("$16");
    register unsigned char *savedOwnerPosition __asm__("$16");
    register unsigned char *particleOwnerPosition __asm__("$16");
    unsigned char *extraHandle;
    unsigned char *allocatedHandle;
    unsigned char *oldPrimaryHandle;
    register unsigned char *cleanupHandle __asm__("$2");
    register unsigned char *extraPosition __asm__("$4");
    register unsigned char *extraTarget __asm__("$5");
    register unsigned char *particleTarget __asm__("$5");
    register int bitIndex __asm__("$5");
    register int ownerPositionWord __asm__("$16");
    register int phaseResult __asm__("$16");
    register int distanceResult __asm__("$20");
    register int colourChannel __asm__("$2");
    int heightDelta;
    int heightResult;
    int ownerHeight;
    register int ownerIndex __asm__("$3");
    register int clampTest __asm__("$2");
    register int scaledDistance __asm__("$3");
    register int tagKind __asm__("$16");
    register int savedSelector __asm__("$17");
    unsigned char state;
    unsigned char substate;
    register int stateValue __asm__("$2");
    register int nextSubstate __asm__("$2");
    void *indexedOwner;
    register unsigned char *prefixTag __asm__("$17");
    register unsigned char *tag __asm__("$19");

    if (owner >= (unsigned char*)Controller78288D_8006C704) {
        __asm__("" : "=r"(owner) : "0"(owner));
        tag = Controller78288Field(owner, void **, 0);
        prefixTag = 0;
    } else {
        __asm__("" : "=r"(owner) : "0"(owner));
        prefixTag = Controller78288Field(owner, void **, 0);
        tag = prefixTag + 0x2C;
    }
    ownerPositionWord = (int)(owner + 0xC);
    distanceResult = Controller78288Helper4F334((void*)ownerPositionWord, Controller78288D_80070328);
    state = Controller78288Field(owner, unsigned char *, 0x48);
    switch (state) {
    case 0:
        substate = Controller78288Field(owner, unsigned char *, 0x49);
        switch (substate) {
        case 0:
            kind=Controller78288Field(tag,unsigned char*,2);
            __asm__("" : "=r"(kind) : "0"(kind) : "$2");
            {register int two __asm__("$2")=2;__asm__("" : "=r"(two) : "0"(two));
            if (kind==two) goto caseZeroOne;}
            {
                {register int product __asm__("$3")= -(((int)owner - ({register int base __asm__("$4")=Controller78288D_8006C550;__asm__("" : "=r"(base) : "0"(base));base;}))*0x45D1745D); product>>=3; __asm__("" : "=r"(product) : "0"(product)); {register int base __asm__("$2")=Controller78288D_8006C79C;
 register int byte __asm__("$4");
 __asm__("" : "=r"(base) : "0"(base) : "$4");
 byte=Controller78288Field(tag,unsigned char*,4);
 __asm__("" : "=r"(byte) : "0"(byte));
 bitIndex=product+base;
 if(byte==0) Controller78288Field(tag,unsigned char*,4)=Controller78288Field(owner,unsigned char*,0x46);
 }}
                { register int bank __asm__("$3")=Controller78288D_8006C58C;
                  register int address __asm__("$2");
                  __asm__("" : "=r"(bank) : "0"(bank) : "$2");
                  address=(int)Controller78288D_80071AB0;
                  __asm__("" : "=r"(bank),"=r"(address) : "0"(bank),"1"(address));
                  bank<<=5; bank+=address;
                  __asm__("" : "=r"(bank) : "0"(bank));
                  address=(bitIndex>>5)*4;address+=bank;
                  address=*(int*)address;
                  __asm__ volatile("" : "=r"(address) : "0"(address) : "$3");
                  bank=bitIndex&31;
                  address=(address>>bank)&1;
                  if(address) {
                    Controller78288Field(tag, unsigned char *, 2) = 0U;
                }
                }
                if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                    Controller78288Field(prefixTag, unsigned char *, 5) = 1U;
                    Controller78288Field(tag, short *, 6) = -0x280;
                    Controller78288Field(owner, int *, 0x14) = (int) (Controller78288Field(owner, int *, 0x14) - 0x280);
                } else {
                    Controller78288Field(prefixTag, unsigned char *, 5) = 0U;
                }
                {register int heading __asm__("$2")=Controller78288Field(owner,unsigned char*,0x46);
                 kind=Controller78288Field(tag,unsigned char*,2);
                 __asm__("" : "=r"(heading),"=r"(kind) : "0"(heading),"1"(kind));
                 Controller78288Field(tag,unsigned char*,3)=heading;}
                if(kind!=1) goto caseZeroCompare;
                stateValue=Controller78288Field(prefixTag,unsigned char*,5);
                if(stateValue!=0) goto caseZeroOne;
caseZeroCompare:
                stateValue=distanceResult<0x1000;
                if(stateValue) {stateValue=5;goto caseZeroStore;}
            }
caseZeroOne:
            stateValue=1;
caseZeroStore:
            Controller78288Field(owner, unsigned char *, 0x49) = stateValue;
            Controller78288Field(owner, signed char *, 0x41) = 0;
            Controller78288Field(owner, signed char *, 0x4C) = 0;
            Controller78288Field(owner, unsigned char *, 0x4D) = 0U;
            goto clearExtraHandle;
        case 1:
            if ((distanceResult < 0x2400) || (Controller78288Field(tag, unsigned char *, 2) == 2)) {
                {register int one __asm__("$3")=1;
                 __asm__("" : "=r"(one) : "0"(one));
                 Controller78288Field(owner,signed char*,0x4C)=24;
                 Controller78288Field(owner,signed char*,0x41)=one;
                 Controller78288Field(owner,unsigned char*,0x4D)=one;
                 Controller78288Field(owner,unsigned char*,0x4F)=127;}
                if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                    Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) Controller78288Field(tag, unsigned char *, 3);
                } else {
                    Controller78288Field(owner, unsigned char *, 0x46) = Controller78288Helper4E880(Controller78288Field(Controller78288D_80070328, int *, 0) - Controller78288Field(owner, int *, 0xC), Controller78288Field(Controller78288D_80070328, int *, 4) - Controller78288Field(owner, int *, 0x10), 0);
                }
                Controller78288Field(owner, unsigned char *, 0x49) = 2U;
                Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) + 0x67);
            }
            goto clearExtraHandle;
        case 2:
            Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) + 8);
            Controller78288Field(owner, unsigned char *, 0x4F) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x4F) - 5);
            if ((Controller78288Field(Controller78288D_80070328, int *, 0xB4) >= 0x1400) || (Controller78288Field(tag, unsigned char *, 2) == 2)) {
                Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) + 8);
                Controller78288Field(owner, unsigned char *, 0x4F) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x4F) - 5);
            }
            Controller78288Helper55D24(owner, 4);
            Controller78288SpawnParticle(1, 0xC, owner, 5);
            if ((unsigned char) Controller78288Field(owner, unsigned char *, 0x4F) < 0x21U) {
                Controller78288Field(owner, unsigned char *, 0x4F) = 0x20U;
                goto setSubstateFour;
            }
            goto clearExtraHandle;
        case 3:
        case 5:
            if (Controller78288Field(owner, unsigned char *, 0x4F) == 0) {
                Controller78288Field(owner, unsigned char *, 0x4F) = 0x20U;
            }
            Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) - 8);
            Controller78288Field(owner, unsigned char *, 0x4F) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x4F) + 5);
            Controller78288Helper55D24(owner, 4);
            if ((unsigned char) Controller78288Field(owner, unsigned char *, 0x4F) >= 0x7FU) {
                Controller78288SpawnParticle(6, 0xC, owner, 5);
                if (Controller78288Field(tag, unsigned char *, 2) == 2) {
                    oldPrimaryHandle = Controller78288Field(tag, int **, 8);
                    if (oldPrimaryHandle != 0) {
                        Controller78288Field(oldPrimaryHandle, signed char *, 0x10) = 0;
                    }
                    Controller78288Helper55B18(owner);
                    return;
                }
                Controller78288Field(owner, signed char *, 0x41) = 0;
                Controller78288Field(owner, signed char *, 0x4C) = 0;
                Controller78288Field(owner, unsigned char *, 0x4D) = 0U;
                {register int state __asm__("$3")=Controller78288Field(owner,unsigned char*,0x49);
                 register int five __asm__("$2")=5;
                 __asm__("" : "=r"(state),"=r"(five) : "0"(state),"1"(five));
                 if(state!=five) goto caseThreeOne;}
                nextSubstate=6;goto storeSubstate;
caseThreeOne:
                nextSubstate=1;goto storeSubstate;
            }
            Controller78288SpawnParticle(1, 0xC, owner, 3);
            goto clearExtraHandle;
        case 4:
            tagKind = Controller78288Field(tag, unsigned char *, 2);
            if (tagKind != 2) {
                if (tagKind == 1) {
                    if (Controller78288Helper37BBC(owner, 0xC) != 0) {
                        Controller78288Helper512E4(owner, 0, 0);
                        {register int diff __asm__("$4")=Controller78288D_8006C550;
                         register int product __asm__("$3");
                         register int bank __asm__("$2");
                         __asm__("" : "=r"(diff) : "0"(diff));
                         diff=(int)owner-diff;product=-(diff*0x45D1745D);
                         __asm__("" : "=r"(product) : "0"(product) : "$2");
                         bank=Controller78288D_8006C79C;
                         product>>=3;product+=bank;
                         __asm__("" : "=r"(product) : "0"(product));
                         bank=Controller78288D_8006C58C;
                         __asm__("" : "=r"(bank) : "0"(bank) : "$4");
                         diff=(int)Controller78288D_80071AB0;
                         __asm__("" : "=r"(diff),"=r"(bank) : "0"(diff),"1"(bank));
                         bank<<=5;bank=bank+diff;
                         __asm__("" : "=r"(bank) : "0"(bank));
                         diff=product>>5;__asm__("" : "=r"(diff) : "0"(diff));diff*=4;diff+=bank;
                         __asm__("" : "=r"(diff) : "0"(diff) : "$3");
                         product&=31;bank=*(int*)diff;product=tagKind<<product;
                         bank|=product;*(int*)diff=bank; }
                        Controller78288Field(tag, unsigned char *, 2) = 0U;
                        Controller78288Field(owner, unsigned char *, 0x49) = 7U;
                    }
                } else {
                    Controller78288Helper3573C(owner, 4, 0, 0);
                    Controller78288Helper55D24(owner, 4);
                    if (distanceResult >= 0x2801) {
                        Controller78288Field(owner, unsigned char *, 0x49) = 3U;
                    } else if (distanceResult < 0x1000) {
                        ownerHeight = Controller78288Field(owner, int *, 0x14) - Controller78288Field(owner, short *, 0x38);
                        heightDelta = ownerHeight - Controller78288Field(Controller78288D_80070328, int *, 8);
                        if (heightDelta >= 0) {
                            if (heightDelta < 0x800) {
                                goto checkHeightAndPlayer;
                            }
                        } else if ((Controller78288Field(Controller78288D_80070328, int *, 8) - ownerHeight) < 0x800) {
checkHeightAndPlayer:
                            playerHeightAddress = Controller78288D_80070328 + 8;
                            if ((((Controller78288Field(owner, int *, 0x14) - Controller78288Field(owner, short *, 0x38)) - Controller78288Field(Controller78288D_80070328, int *, 8)) >= -0x1F3) && ((Controller78288Field(Controller78288D_80070328, int *, 0x50) < 5) || ((unsigned int) (Controller78288Field(Controller78288D_80070328, int *, 0x50) - 0xB) < 2U))) {
                                Controller78288Helper4F178(&frame.first.x, playerHeightAddress + 0x90);
                                { register void *vector __asm__("$4")=&frame.first.x;
                                  register int six __asm__("$5")=6;
                                  register int x __asm__("$2")=frame.first.x;
                                  register int z __asm__("$3")=frame.first.z;
                                  __asm__("" : "=r"(vector),"=r"(six),"=r"(x),"=r"(z) : "0"(vector),"1"(six),"2"(x),"3"(z));
                                  x<<=5;frame.first.x=x;
                                  x=frame.first.y;z<<=5;frame.first.z=z;
                                  __asm__ volatile("" : "=r"(x) : "0"(x) : "memory");
                                  x<<=5;frame.first.y=x;
                                  Controller78288Helper4F110(vector,six); }
                                Controller78288Helper4F194(&frame.first.x, &frame.first.x, playerHeightAddress - 8);
                                if (distanceResult >= 0x800) {
                                    if (Controller78288Helper4F334(owner + 0xC, &frame.first.x) < 0x800) {
                                        goto enterStateOneFromRange;
                                    }
                                } else {
                                    goto enterStateOne;
                                }
                            }
                        }
                    }
                }
            } else {
enterStateOneFromRange:
enterStateOne:
                Controller78288Field(owner, unsigned char *, 0x48) = 1U;
                Controller78288Helper34F40(owner, 1);
            }
            if ((Controller78288D_8006C644 & 0xF) < 2) {
                {register void *vector __asm__("$17")=&frame.second.x;
                 register void *argument __asm__("$4")=vector;
                 __asm__("" : "=r"(argument) : "0"(argument) : "$16");
                 savedOwnerPosition = owner + 0xC;
                 Controller78288Helper4F178(argument, savedOwnerPosition);}
                Controller78288Helper55F14(owner, 0, savedOwnerPosition);
                Controller78288SpawnParticle(1, 0xC, owner, 3);
                Controller78288Helper4F178(savedOwnerPosition, &frame.second.x);
            }
            goto clearExtraHandle;
        case 6:
            if (distanceResult >= 0x2801) {
                Controller78288Field(owner, unsigned char *, 0x49) = 1U;
            }
            goto clearExtraHandle;
        case 7:
            if (Controller78288D_8006E344 != 1) {
                goto setSubstateFour;
            }
            goto clearExtraHandle;
        }
        goto clearExtraHandle;
setSubstateFour:
                nextSubstate = 4;
storeSubstate:
                Controller78288Field(owner, unsigned char *, 0x49) = nextSubstate;
clearExtraHandle:
            extraHandle = Controller78288Field(tag, int **, 0xC);
            if (extraHandle != 0) {
                Controller78288Field(extraHandle, signed char *, 0x1C) = 0;
                Controller78288Field(tag, int **, 0xC) = 0;
            }
        goto updatePrimaryHandle;
    case 1:
        if (Controller78288Field(tag, unsigned char *, 2) == state) {
            Controller78288Field(Controller78288D_80070328, int *, 0x20C) = 0x10000002;
            Controller78288Helper492DC(ownerPositionWord);
        }
        phaseResult = Controller78288Helper55E84(owner);
        ownerIndex = Controller78288Field(tag, int *, 0x10);
        if (ownerIndex >= 0) {
            indexedOwner = (ownerIndex * 0x58) + Controller78288D_8006C550;
            Controller78288Helper3585C(owner, Controller78288Helper4E880(Controller78288Field(indexedOwner, int *, 0xC) - Controller78288Field(owner, int *, 0xC), Controller78288Field(indexedOwner, int *, 0x10) - Controller78288Field(owner, int *, 0x10), 0), 6, 0, 0, 0);
        } else {
            Controller78288Helper3573C(owner, 6, 0, 0);
        }
        Controller78288Helper55D24(owner, 4);
        if (phaseResult < 0x14) {
            if ((Controller78288Field(tag, unsigned char *, 2) != 2) && (distanceResult >= 0x1001)) {
                Controller78288Field(owner, unsigned char *, 0x48) = 0U;
                Controller78288Helper34F40(owner, 0);
            }
        } else if (({register int within __asm__("$2")=phaseResult<0x1F; __asm__("" : "=r"(within) : "0"(within) : "$3"); within;})) {
            if (Controller78288Field(owner, unsigned char *, 0x49) != 5) {
                Controller78288Helper4F178(&frame.second.x, owner + 0xC);
                savedSelector = Controller78288Field(tag, unsigned char *, 4);
                heightResult = Controller78288Helper1A358(&frame.second.x, 0x800);
                frame.second.z = heightResult;
                if (heightResult == 0) {
                    frame.second.z = Controller78288Field(Controller78288D_80070328, int *, 8);
                }
                Controller78288Helper3B634(Controller78288D_8006D088, &frame.second.x, savedSelector);
                Controller78288Helper3BABC(owner, 0, 0x80);
                Controller78288Field(owner, unsigned char *, 0x49) = 5U;
            }
            {register void *handle __asm__("$2")=Controller78288Field(tag,void**,0xC);
             register void *prepared __asm__("$4")=owner;
             if(handle!=0) goto handleReady;
             {register int close __asm__("$2")=distanceResult<0x1000;
              __asm__("" : "=r"(close) : "0"(close) : "$4");
              prepared=(void*)4;
              if(close) {
                __asm__("" : "=r"(prepared) : "0"(prepared));
                Controller78288Field(tag,void**,0xC)=Controller78288Helper2F540((int)prepared,1,0x608080);
              }}
             handle=Controller78288Field(tag,void**,0xC);prepared=owner;
             if(handle==0) goto handleFinished;
handleReady:
             __asm__("" : "=r"(prepared) : "0"(prepared));
                Controller78288Helper55F14(prepared,0,&frame.third.x);
                Controller78288Helper4F178(Controller78288Field(tag, int **, 0xC), &frame.third.x);
                {register int index __asm__("$3")=Controller78288Field(tag,int*,0x10);
                 register int offset __asm__("$2");
                 if(index>=0) {
                   offset=index*0x58;__asm__("" : "=r"(offset) : "0"(offset) : "$4","$5");
                   extraPosition=Controller78288Field(tag,unsigned char**,0xC);
                   extraTarget=(unsigned char*)Controller78288D_8006C550;
                   __asm__("" : "=r"(extraPosition),"=r"(extraTarget) : "0"(extraPosition),"1"(extraTarget));
                   extraPosition+=12;extraTarget+=offset;extraTarget+=12;
                 }else {
                   extraPosition=Controller78288Field(tag,unsigned char**,0xC);
                   extraTarget=Controller78288D_80070328;
                   __asm__("" : "=r"(extraPosition),"=r"(extraTarget) : "0"(extraPosition),"1"(extraTarget));
                   extraPosition+=12;
                 }}
                Controller78288Helper4F178(extraPosition, extraTarget);
            }
handleFinished:
            {register void *argument __asm__("$4");
             argument=&frame.fourth.x;
             __asm__("" : "=r"(argument) : "0"(argument) : "$16");
             particleOwnerPosition = owner + 0xC;
             Controller78288Helper4F178(argument,particleOwnerPosition);}
            {register int index __asm__("$3")=Controller78288Field(tag,int*,0x10);
             register void *prepared __asm__("$4");
             __asm__("" : "=r"(index) : "0"(index) : "$4");
             prepared=particleOwnerPosition;
             if(index>=0) {
               register int offset __asm__("$2")=index*11;
               __asm__("" : "=r"(offset) : "0"(offset) : "$5");
               particleTarget=(unsigned char*)Controller78288D_8006C550;
               offset*=8;particleTarget+=offset;particleTarget+=12;
             }else particleTarget=Controller78288D_80070328;
             Controller78288Helper4F178(prepared,particleTarget);}
            Controller78288SpawnParticle(1, 0xC, owner, 3);
            Controller78288Helper4F178(owner + 0xC, &frame.fourth.x);
        } else {
            cleanupHandle = Controller78288Field(tag, int **, 0xC);
            if (cleanupHandle != 0) {
                Controller78288Field(cleanupHandle, signed char *, 0x1C) = 0;
                {register int minusOne __asm__("$2")=-1;
                 __asm__("" : "=r"(minusOne) : "0"(minusOne) : "memory");
                 Controller78288Field(tag,int**,0xC)=0;
                 Controller78288Field(tag,int*,0x10)=minusOne;}
            }
        }
        if ((Controller78288Field(tag, short *, 6) < 0) && (Controller78288Field(tag, unsigned char *, 2) != 1)) {
            Controller78288Field(owner, int *, 0x14) = (int) (Controller78288Field(owner, int *, 0x14) + 0x20);
            Controller78288Field(tag, short *, 6) = (short) ((unsigned short) Controller78288Field(tag, short *, 6) + 0x20);
        }
        if (Controller78288D_8006C770 != 0) {
            if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                Controller78288Field(owner, unsigned char *, 0x49) = 4U;
                if ((Controller78288Field(tag, int *, 0x14) != 0) && (Controller78288D_8006E044 == 0x11)) {
                    Controller78288D_8006E160 = 0;
                    Controller78288Field(tag, int *, 0x14) = 0;
                }
            }
            Controller78288Field(owner, unsigned char *, 0x48) = 0U;
            Controller78288Helper34F40(owner, 0);
        }
        goto updatePrimaryHandle;
    }

updatePrimaryHandle:
            __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult));
            { register void *handle __asm__("$2")=Controller78288Field(tag,void**,8);
              __asm__("" : "=r"(handle) : "0"(handle) : "$3");
              scaledDistance=distanceResult>>6;
            if (handle == 0) {
                allocatedHandle = Controller78288Helper2EC50(4,0x40,({register int zero __asm__("$6");__asm__ volatile("" : "=r"(handle) : "0"(handle) : "$6");zero=0;zero;}));
                Controller78288Field(tag, int **, 8) = allocatedHandle;
                if (allocatedHandle != 0) {
                    __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult));
                    scaledDistance = distanceResult >> 6;
                    __asm__("" : "=r"(scaledDistance) : "0"(scaledDistance));
                    goto clampPrimaryHandle;
                }
            } else {
clampPrimaryHandle:
                clampTest=scaledDistance<0x50;
                if(clampTest) {
                    scaledDistance=0x50;
                    __asm__("" : "=r"(scaledDistance) : "0"(scaledDistance));
                }
                clampTest=scaledDistance<0xA1;
                if(!clampTest) scaledDistance=0xA0;
                Controller78288Field(Controller78288Field(tag, int **, 8), signed char *, 0x11) = (signed char) scaledDistance;
                colourChannel = ((int) (*(unsigned short*)(Controller78288D_80065920 + ((Controller78288D_8006C644 * 8) & 0x1F8)) << 0x10) >> 0x17) + 0x70;
                Controller78288Field(Controller78288Field(tag, int **, 8), int *, 0xC) = (int) (({register int colour __asm__("$3")=colourChannel<<8;__asm__("" : "=r"(colour) : "0"(colour));colour=colourChannel+colour;__asm__("" : "=r"(colour) : "0"(colour));colour;}) + ((colourChannel >> 1) << 0x10));
                if (Controller78288Field(owner, unsigned char *, 0x4D) != 0) {
                    Controller78288Helper55F14(owner, 0, &frame.first.x);
                    {register void *first __asm__("$4")=&frame.first.x;
                     register void *second __asm__("$5")=first;
                     __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16");
                     handleOwnerPosition=owner+12;
                     Controller78288Helper4F1C8(first,second,handleOwnerPosition);}
                    Controller78288Helper4F0E8(&frame.first.x, 5);
                    Controller78288Helper4F228(&frame.first.x, &frame.first.x, Controller78288Field(owner, unsigned char *, 0x4F));
                    Controller78288Helper4F194(Controller78288Field(tag, int **, 8), handleOwnerPosition, &frame.first.x);
                    return;
                }
                Controller78288Helper4F178(Controller78288Field(tag, int **, 8), owner + 0xC);
                return;
            }
    }
}

#undef Controller78288Field


/* Rev 0 private record: signed halfword velocity and low-byte angle deltas. */
typedef struct {
    Vector3D16 velocity;
    unsigned short rollDelta, pitchDelta, yawDelta;
    int remaining, zLimit;
} DecodedMotionTag;
extern Vector3D DecodedMotionNormal __asm__("D_80071918");
extern int DecodedMotionNormalY __asm__("D_8007191C");
extern int DecodedMotionNormalZ __asm__("D_80071920");
int func_80019194(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_80055B18(Moby*);
int rand(void);
void func_level_50_800792AC(Moby* moby) {
    Vector3D particle;
    int reservedStack[6]; /* Preserve the original local frame layout. */
    DecodedMotionTag* tag = moby->mobyTag;
    int dot, index;
    register int projection __asm__("$16");
    register Vector3D* normal __asm__("$19");
    if (tag->remaining <= 0 || !moby->drawn) goto retire;
    if (!(moby->substate & 1)) {
        int positionZ = moby->position.z;
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        if (tag->zLimit >= positionZ) goto retire;
    } else if (func_80019194(&moby->position, 256)) {
        /* Empty constraints preserve the original compiler register allocation. */
        normal = &DecodedMotionNormal;
        __asm__("" : "=r"(normal) : "0"(normal));
        func_8004EF04(normal, 4096);
        dot = tag->velocity.x * normal->x
            + tag->velocity.y * DecodedMotionNormalY
            + tag->velocity.z * DecodedMotionNormalZ;
        projection = dot >> 11;
        __asm__("" : "=r"(projection) : "0"(projection));
        if (projection < 0) {
            func_8004F08C(normal, 4096, (dot >> 13) - projection);
            tag->velocity.x = (unsigned short)tag->velocity.x + normal->x;
            __asm__ volatile("" : : : "memory");
            tag->velocity.y = (unsigned short)tag->velocity.y + DecodedMotionNormalY;
            __asm__ volatile("" : : : "memory");
            tag->velocity.z = (unsigned short)tag->velocity.z + DecodedMotionNormalZ;
        }
    }
    moby->position.x += tag->velocity.x;
    moby->position.y += tag->velocity.y;
    if (moby->substate & 8) tag->velocity.z = (unsigned short)tag->velocity.z - 3;
    else if (moby->mobyClass == 0x12F) tag->velocity.z = (unsigned short)tag->velocity.z - 16;
    else tag->velocity.z = (unsigned short)tag->velocity.z - 6;
    if (tag->velocity.z < -128) tag->velocity.z = -128;
    moby->position.z += tag->velocity.z;
    moby->angle.roll += (unsigned char)tag->rollDelta;
    moby->angle.pitch += (unsigned char)tag->pitchDelta;
    moby->angle.yaw += (unsigned char)tag->yawDelta;
    if ((moby->substate & 2) && !(tag->remaining & 3)) {
        particle.x = rand() & 3;
        particle.y = rand() & 3;
        particle.z = 20;
        SpawnParticle(1, 1, &moby->position, &particle);
    } else if (moby->substate & 4) {
        register int count __asm__("$2") = 1;
        /* Retail retains this initially true guard before the particle loop. */
        __asm__("" : "=r"(count) : "0"(count));
        index = 0;
        if (count) {
            do {
                index++;
                particle.x = 64 - (rand() & 127);
                particle.y = 64 - (rand() & 127);
                particle.z = 64 - (rand() & 127);
                func_8004F194(&particle, &particle, &moby->position);
                SpawnParticle(1, 0x42, &particle, (Vector3D*)1);
            } while (index < ((moby->substate & 1) * 2 + 1));
        }
    } else if ((moby->substate & 8) && !(tag->remaining & 7)) {
        particle.x = 8 - (rand() & 15);
        particle.y = 8 - (rand() & 15);
        particle.z = 4 - (rand() & 7);
        SpawnParticle(1, 0x27, &moby->position, &particle);
    }
    tag->remaining--;
    return;
retire:
    if (moby->substate & 1) {
        if (moby->substate & 16) SpawnParticle(8, 15, &moby->position, 0);
        else SpawnParticle(8, 0x46, &moby->position, (Vector3D*)16);
    }
    func_80055B18(moby);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_800796DC);

void func_level_50_8007A6DC(Moby* moby) {
    if (!moby->substate) {
        SpawnParticle(0x80, 0xE, (Vector3D*)1, 0);
        moby->substate = 1;
    } else {
        SpawnParticle(2, 0xE, 0, 0);
    }
}

typedef struct {
    short x,y,z;
    unsigned char roll,reserved07,pitch,reserved09,yaw,reserved0B;
    short timer,lifetime,reserved10,mode;
} DecodedFragmentUpdate;
extern int D_8006C648,D_8006C640;
extern Vector3D D_80071918;
int rand(void);
int func_80019194(Vector3D*,int);
int func_8004EF74(Vector3D*,Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_level_50_8007A758(Moby* moby) {
    DecodedFragmentUpdate* tag=moby->mobyTag;
    Vector3D vector;
    /* Retail reserves further frame storage; its source purpose is unknown. */
    int reservedStack;
    if(tag->lifetime==0)return;
    if(tag->lifetime>=2) {
        tag->lifetime-=D_8006C648;
        if(tag->lifetime<=0)tag->lifetime=1;
    }
    if(func_800359A4(&tag->timer,2) || (!moby->drawn && tag->lifetime==1)) {
        SpawnParticle(8,0x46,&moby->position,(Vector3D*)0x10);
        func_80055B18(moby);return;
    }
    if(func_80019194(&moby->position,0x12C)) {
        vector.x=tag->x;vector.y=tag->y;vector.z=tag->z;
        if(func_8004EF74(&vector,&D_80071918,&vector)) {
            tag->x=vector.x;tag->y=vector.y;tag->z=vector.z;
        }
    }
    moby->position.x+=tag->x;moby->position.y+=tag->y;
    if(tag->mode==3)tag->z-=5;else tag->z-=10;
    if(tag->z< -0xC8)tag->z= -0xC8;
    moby->position.z+=tag->z;
    moby->angle.roll+=tag->roll;moby->angle.pitch+=tag->pitch;moby->angle.yaw+=tag->yaw;
    if(tag->mode!=2 && D_8006C640%5==0) {
        vector.x=rand()&3;vector.y=rand()&3;vector.z=0x14;
        if(tag->mode==1)SpawnParticle(1,0,&moby->position,&vector);
        else if(tag->mode==0)SpawnParticle(1,1,&moby->position,&vector);
        else if(tag->mode==3) {
            vector.x=tag->x>>2;vector.y=tag->x>>2;vector.z=tag->z>>2;
            vector.z+=func_8003636C(0xA,0x14);
            SpawnParticle(1,0x27,&moby->position,&vector);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8007AA74);

typedef struct { unsigned char reserved00[4], response, reserved05[0x33]; unsigned char bounds[0x18]; int dialogueValue, linkedIndex; } DecodedLinkedDialogueTag;
extern Moby* D_8006C550;
extern int D_8006C770, D_8006E344;
extern Moby* D_8006C65C;
extern int DecodedDialoguePlayer244 __asm__("D_80070328 + 0x244");
extern int DecodedDialoguePlayer280 __asm__("D_80070328 + 0x280");
extern Moby* DecodedDialoguePlayerActor __asm__("D_80070328 + 0x250");
extern short D_80065920[], D_800658A0[];
extern unsigned char D_8006D088[];
extern Spyro spyro;
int DecodedLinkedDialogueBounds(void*,void*,int,int) __asm__("func_80036220");
void DecodedLinkedDialogueSave(void*) __asm__("func_8003B74C");
int DecodedLinkedDialogueQuery(Moby*,int) __asm__("func_80037BBC");
void DecodedLinkedDialogueBegin(Moby*,int,int) __asm__("func_800512E4");
void DecodedLinkedDialoguePosition(void*,Vector3D*,int) __asm__("func_8003B634");
void func_level_50_8007BAF4(Moby* moby) {
    DecodedLinkedDialogueTag* tag = moby->mobyTag;
    Moby* linked;
    Vector3D position;
    register int* playerCheck __asm__("$4");
    switch (moby->state) {
    case 0:
        linked = &D_8006C550[tag->linkedIndex];
        if (moby->animationState.nextId != 0) {
            D_8006C770 = 0;
            moby->animationProgress = 0x72;
            moby->animationState.nextId = 0;
            moby->animationState.nextFrame = 0;
            func_80035734(moby);
        }
        playerCheck = &DecodedDialoguePlayer244;
        __asm__("" : "=r"(playerCheck) : "0"(playerCheck));
        if (*playerCheck && DecodedDialoguePlayerActor->mobyClass == 0x72 && DecodedLinkedDialogueBounds((unsigned char*)playerCheck - 0x244,tag->bounds,0,0x1388)) {
            DecodedLinkedDialogueSave(D_8006D088);
            break;
        }
        if (linked->state != 1 && DecodedLinkedDialogueQuery(moby,0)) {
            tag->dialogueValue = 0;
            DecodedLinkedDialogueBegin(moby,0,1);
            moby->state = 1;
        }
        break;
    case 1:
        if (!D_8006C65C && DecodedDialoguePlayer280 > 0) D_8006C65C = SpawnMoby(0x78,moby);
        if (D_8006E344 != 1) {
            tag->dialogueValue = 0;
            linked = &D_8006C550[tag->linkedIndex];
            if (tag->response == 2) {
                func_8004F178(&position,&moby->position);
                position.x += (D_80065920[moby->angle.yaw] * 13) >> 5;
                position.y += (D_800658A0[moby->angle.yaw] * 13) >> 5;
                DecodedLinkedDialoguePosition(D_8006D088,&position,func_8004E880(moby->position.x-position.x,moby->position.y-position.y,0)&0xFF);
                linked->state = 1;
            }
            moby->state = 0;
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8007BD70);

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8007D7E0);

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8007EE20);

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 388 instructions per copy are the acceptance authority.
 * Preserve the 0xA8-byte frame, signed table loads, 32-bit product wrap,
 * arithmetic shifts, byte accesses, helper order and original exit blocks.
 * Empty constraints emit no instructions and retain original scheduling.
 * Table meanings, physical units, complete helper contracts, state layouts
 * and caller cadence remain unresolved. No runtime completeness claimed.
 * Falsifiable check: every original linked word and all full binary hashes.
 */
#define Actor83A14Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor83A14func_80018368() __asm__("func_80018368");
void* Actor83A14func_8001BA30() __asm__("func_8001BA30");
int Actor83A14func_800359A4() __asm__("func_800359A4");
int Actor83A14func_8003613C() __asm__("func_8003613C");
int Actor83A14func_8003636C() __asm__("func_8003636C");
int Actor83A14func_800363DC() __asm__("func_800363DC");
int Actor83A14func_8003BABC() __asm__("func_8003BABC");
int Actor83A14func_8004E880() __asm__("func_8004E880");
int Actor83A14func_8004E9E4() __asm__("func_8004E9E4");
int Actor83A14func_8004EA2C() __asm__("func_8004EA2C");
int Actor83A14func_8004F0E8() __asm__("func_8004F0E8");
int Actor83A14func_8004F178() __asm__("func_8004F178");
int Actor83A14func_8004F194() __asm__("func_8004F194");
int Actor83A14func_8004F334() __asm__("func_8004F334");
int Actor83A14func_80055B18() __asm__("func_80055B18");
int Actor83A14rand() __asm__("rand");
extern short Actor83A14D_80065920[] __asm__("D_80065920");
extern short Actor83A14D_800658A0[] __asm__("D_800658A0");
extern int Actor83A14D_8006C550 __asm__("D_8006C550");
extern int (*Actor83A14SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_50_8007FE94(void *input) {
    register unsigned char *owner __asm__("$21")=input;
    struct {
        int sp18,pad1C,pad20,pad24;
        int sp28,sp2C,sp30,pad34;
        int sp38,sp3C,sp40,pad44;
        int sp48,sp4C,sp50,pad54;
        int sp58,pad5C,pad60,pad64;
    } frame;
    register int helperMode __asm__("$5");
    register void *call4 __asm__("$4");
    register int work2 __asm__("$2");
    register void *call6 __asm__("$6");
    register void *call5 __asm__("$5");
    register int *ownerPosition __asm__("$17");
    int positionWord14;
    int positionWord10;
    int positionWord0C;
    register int firstTableResult __asm__("$16");
    register int secondTableResult __asm__("$16");
    register int maskedSelector __asm__("$18");
    register int firstFactor __asm__("$19");
    register int secondFactor __asm__("$20");
    register int helperSelector __asm__("$17");
    register int particleIndex __asm__("$23");
    register int firstDifference __asm__("$3");
    register int secondDifference __asm__("$3");
    unsigned char copiedByte;
    unsigned char stateByte;
    register void *state __asm__("$16");
    void *initialTarget;
    void *target;
    void *hitActor;

    __asm__("" : "=r"(owner) : "0"(owner));
    stateByte = Actor83A14Field(owner, unsigned char *, 0x48);
    state = Actor83A14Field(owner, void **, 0);
    switch (stateByte) {                              /* irregular */
    case 0:
        if ((Actor83A14Field(owner, int *, 0xC) >= 0x400) && (Actor83A14Field(owner, int *, 0x10) >= 0x400) && (Actor83A14Field(owner, int *, 0x14) >= 0x400)) {
            initialTarget = Actor83A14Field(state, void **, 8);
            if (initialTarget != 0) {
                if ((unsigned char) Actor83A14Field(initialTarget, unsigned char *, 0x48) >= 0x80U) {
                    Actor83A14Field(state, void **, 8) = 0;
                }
                target = Actor83A14Field(state, void **, 8);
                if (target != 0) {
                    firstDifference = Actor83A14func_8003613C(Actor83A14Field(owner, unsigned char *, 0x46), Actor83A14func_8004E880(Actor83A14Field(target, int *, 0xC) - Actor83A14Field(owner, int *, 0xC), Actor83A14Field(target, int *, 0x10) - Actor83A14Field(owner, int *, 0x10), 0));
                    if (firstDifference >= 4) {
                        firstDifference=3;
                        __asm__("" : "=r"(firstDifference) : "0"(firstDifference));
                    }
                    if (firstDifference < -3) firstDifference=-3;
                    Actor83A14Field(owner, unsigned char *, 0x46) = (unsigned char) (Actor83A14Field(owner, unsigned char *, 0x46) + firstDifference);
                    secondDifference = Actor83A14func_8003613C(Actor83A14Field(owner, unsigned char *, 0x45), Actor83A14func_8004E880(Actor83A14func_8004F334(owner + 0xC, Actor83A14Field(state, void **, 8) + 0xC), Actor83A14Field(Actor83A14Field(state, void **, 8), int *, 0x14) - Actor83A14Field(owner, int *, 0x14), 0));
                    if (secondDifference >= 4) {
                        secondDifference=3;
                        __asm__("" : "=r"(secondDifference) : "0"(secondDifference));
                    }
                    if (secondDifference < -3) secondDifference=-3;
                    Actor83A14Field(owner, unsigned char *, 0x45) = (unsigned char) (Actor83A14Field(owner, unsigned char *, 0x45) + secondDifference);
                }
            }
            frame.sp28 = (int) (((int) (Actor83A14D_80065920[Actor83A14Field(owner, unsigned char *, 0x46)] * Actor83A14Field(state, int *, 0)) >> 0xC) * Actor83A14D_80065920[Actor83A14Field(owner, unsigned char *, 0x45)]) >> 0xC;
            frame.sp2C = (int) (((int) (Actor83A14D_800658A0[Actor83A14Field(owner, unsigned char *, 0x46)] * Actor83A14Field(state, int *, 0)) >> 0xC) * Actor83A14D_80065920[Actor83A14Field(owner, unsigned char *, 0x45)]) >> 0xC;
            call4=&frame.sp18;
            __asm__("" : "=r"(call4) : "0"(call4));
            ownerPosition = owner + 0xC;
            frame.sp30 = (int) (Actor83A14D_800658A0[Actor83A14Field(owner, unsigned char *, 0x45)] * Actor83A14Field(state, int *, 0)) >> 0xC;
            Actor83A14func_8004F178(call4, ownerPosition);
            Actor83A14func_8004F194(ownerPosition, ownerPosition, &frame.sp28);
            positionWord0C = Actor83A14Field(owner, int *, 0xC);
            if (positionWord0C >= 0x400) {
                positionWord10 = Actor83A14Field(owner, int *, 0x10);
                if (positionWord10 >= 0x400) {
                    positionWord14 = Actor83A14Field(owner, int *, 0x14);
                    if ((positionWord14 >= 0x400) && (positionWord0C <= 0x3E800) && (positionWord10 <= 0x3E800) && (positionWord14 <= 0x3E800)) {
                        if (Actor83A14func_80018368(&frame.sp18, ownerPosition, positionWord0C) != 0) goto block_30;
                        {
                            hitActor = Actor83A14func_8001BA30(ownerPosition, 0x12C, 0, 0, 0x130000, Actor83A14D_8006C550 + (Actor83A14Field(owner, unsigned char *, 0x3A) * 0x58));
                            if (hitActor != 0) {
                                copiedByte = Actor83A14Field(owner, unsigned char *, 0x46);
                                Actor83A14Field(hitActor, unsigned char *, 0x51) = copiedByte;
                                if (copiedByte == 0) {
                                    Actor83A14Field(hitActor, unsigned char *, 0x51) = 1U;
                                }
                                Actor83A14Field(state, int *, 0xC) = 1;
                                goto block_30;
                            }
                            goto noTarget;
block_30:
                            Actor83A14Field(owner, unsigned char *, 0x48)=1;
                            return;
noTarget:
                            if (Actor83A14func_800359A4(state + 4, 4) == 0) {
                                Actor83A14Field(owner, unsigned char *, 0x44) = (unsigned char) (Actor83A14Field(owner, unsigned char *, 0x44) + 0xF4);
                                Actor83A14func_8004F178(&frame.sp38, ownerPosition);
                                frame.sp38 += Actor83A14func_800363DC(0, 0x32);
                                frame.sp3C += Actor83A14func_800363DC(0, 0x32);
                                frame.sp40 += Actor83A14func_800363DC(0, 0x32);
                                frame.sp48 = Actor83A14func_800363DC(0, 0xA);
                                frame.sp4C = Actor83A14func_800363DC(0, 0xA);
                                frame.sp50 = Actor83A14func_8003636C(0xA, 0xF);
                                Actor83A14SpawnParticle(1, 0x27, &frame.sp38, &frame.sp48);
                                return;
                            }
                            goto block_39;
                        }
                    }
                }
            }
            goto block_39;
        }
        goto block_39;
    case 1:
        Actor83A14func_8001BA30(owner + 0xC, 0x3E8, 0, 0, 0x130000, Actor83A14D_8006C550 + (Actor83A14Field(owner, unsigned char *, 0x3A) * 0x58));
        if (Actor83A14Field(state, int *, 0xC) != 0) {
            __asm__ __volatile__("" ::: "$4", "$5");
            call4=owner;
            helperMode = 1;
        } else {
            __asm__ __volatile__("" ::: "$4", "$5");
            call4=owner;
            helperMode = 0;
        }
        Actor83A14func_8003BABC(call4, helperMode, 0);
        particleIndex = 0;
        do {
            firstFactor = Actor83A14func_8003636C(0x28, 0x3C);
            secondFactor = Actor83A14func_8003636C(0x28, 0x3C);
            maskedSelector = Actor83A14rand() & 0xFFF;
            helperSelector = Actor83A14func_8003636C(0, 0x800);
            work2=Actor83A14func_8004EA2C(helperSelector);
            call4=(void*)maskedSelector;
            __asm__("" : "=r"(call4),"=r"(work2) : "0"(call4),"1"(work2));
            firstTableResult=work2;
            frame.sp48 = (int) ((firstTableResult >> 6) * (Actor83A14func_8004EA2C((int)call4) * firstFactor)) >> 0x12;
            work2=Actor83A14func_8004EA2C(helperSelector);
            call4=(void*)maskedSelector;
            __asm__("" : "=r"(call4),"=r"(work2) : "0"(call4),"1"(work2));
            secondTableResult=work2;
            frame.sp4C = (int) ((secondTableResult >> 6) * (Actor83A14func_8004E9E4((int)call4) * firstFactor)) >> 0x12;
            particleIndex += 1;
            frame.sp50 = (int) (Actor83A14func_8004E9E4(helperSelector) * secondFactor) >> 0xC;
            Actor83A14func_8004F178(&frame.sp58, &frame.sp48);
            Actor83A14func_8004F0E8(&frame.sp58, 1);
            call4=&frame.sp58;
            __asm__("" : "=r"(call4) : "0"(call4));
            call5=&frame.sp58;
            __asm__("" : "=r"(call4),"=r"(call5) : "0"(call4),"1"(call5));
            call6=owner+12;
            Actor83A14func_8004F194(call4, call5, call6);
            __asm__("" : "=r"(owner) : "0"(owner));
            Actor83A14SpawnParticle(1, 0, &frame.sp58, &frame.sp48);
            call6=owner+12;
        } while (particleIndex < 8);
        Actor83A14SpawnParticle(8, 0x46, call6, (int *)0x10);
block_39:
        Actor83A14func_80055B18(owner);
        return;
    }
}

#undef Actor83A14Field


void func_level_50_800804A4(Moby* moby) {
    func_80039714(moby);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_800804C4);

typedef struct {
    unsigned char unk0, unk1;
    short offset;
    Moby* parent;
} DecodedFollowTag;
extern unsigned short D_8006E040, D_8006E03E;
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_50_8008102C(Moby* moby) {
    DecodedFollowTag* tag;
    moby->angle.yaw = ((short)D_8006E040 >> 4) - 0x80;
    moby->angle.pitch = D_8006E03E >> 4;
    tag = moby->mobyTag;
    if (tag->unk0 == 1) {
        if (tag->parent->state >= 0x80 || tag->parent->mobyClass != tag->unk1) {
            func_80055B18(moby);
            return;
        }
        if (tag->parent->mobyClass == 0x78) {
            moby->size -= deltaTime * 4;
            if (moby->size < 0x1A) moby->size = 0x1A;
            if ((unsigned int)(spyro.movementState - 0xB) >= 2 || tag->parent->drawn == 0) {
                ((unsigned char*)tag->parent->mobyTag)[0xA] = 0;
                func_80055B18(moby);
                return;
            }
        }
        func_8004F178(&moby->position, &tag->parent->position);
        moby->position.z += tag->offset;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_80081180);

extern int D_8006C648,D_8006C640;
extern Vector3D D_80071918;
int rand(void);
int func_80019194(Vector3D*,int);
int func_8004EF74(Vector3D*,Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_level_50_80081C90(Moby* moby) {
    DecodedFragmentUpdate* tag=moby->mobyTag;
    Vector3D vector;
    /* Retail reserves further frame storage; its source purpose is unknown. */
    int reservedStack;
    if(tag->lifetime==0)return;
    if(tag->lifetime>=2) {
        tag->lifetime-=D_8006C648;
        if(tag->lifetime<=0)tag->lifetime=1;
    }
    if(func_800359A4(&tag->timer,2) || (!moby->drawn && tag->lifetime==1)) {
        SpawnParticle(8,0x46,&moby->position,(Vector3D*)0x10);
        func_80055B18(moby);return;
    }
    if(func_80019194(&moby->position,0x12C)) {
        vector.x=tag->x;vector.y=tag->y;vector.z=tag->z;
        if(func_8004EF74(&vector,&D_80071918,&vector)) {
            tag->x=vector.x;tag->y=vector.y;tag->z=vector.z;
        }
    }
    moby->position.x+=tag->x;moby->position.y+=tag->y;
    if(tag->mode==3)tag->z-=5;else tag->z-=10;
    if(tag->z< -0xC8)tag->z= -0xC8;
    moby->position.z+=tag->z;
    moby->angle.roll+=tag->roll;moby->angle.pitch+=tag->pitch;moby->angle.yaw+=tag->yaw;
    if(tag->mode!=2 && D_8006C640%5==0) {
        vector.x=rand()&3;vector.y=rand()&3;vector.z=0x14;
        if(tag->mode==1)SpawnParticle(1,0,&moby->position,&vector);
        else if(tag->mode==0)SpawnParticle(1,1,&moby->position,&vector);
        else if(tag->mode==3) {
            vector.x=tag->x>>2;vector.y=tag->x>>2;vector.z=tag->z>>2;
            vector.z+=func_8003636C(0xA,0x14);
            SpawnParticle(1,0x27,&moby->position,&vector);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_80081FAC);

typedef struct {
    unsigned char reserved00[0x44];
    unsigned char* animation;
} DecodedAnimationHeader;
extern DecodedAnimationHeader* D_8006EE2C[];
extern int D_8006C770;
void func_level_50_800833B4(Moby* moby) {
    if (moby->state == 1 && D_8006C770) {
        register unsigned int frames __asm__("$2");
        moby->state = 2;
        frames = *D_8006EE2C[moby->mobyClass]->animation;
        moby->animationState.id = 2;
        moby->animationState.nextId = 2;
        moby->animationState.frame = 0;
        moby->animationState.nextFrame = 1;
        /* Keep the original branch-free progress mask; emits no instructions. */
        frames = frames >= 2;
        __asm__("" : "=r"(frames) : "0"(frames));
        moby->animationProgress = -frames & 0x30;
    }
}

extern int deltaTime;
void func_80055B18(Moby*);
void func_level_50_80083430(Moby* moby) {
    int* countdown = moby->mobyTag;
    if (*countdown > 0) *countdown -= deltaTime * 2;
    else moby->size += deltaTime * 2;
    moby->position.z += deltaTime * 32;
    moby->angle.yaw += deltaTime * 8;
    if (moby->size >= 0x7C) {
        moby->position.z += 0x60;
        SpawnParticle(8, 0x47, &moby->position, 0);
        func_80055B18(moby);
    }
}

extern unsigned char Controller7C02CFlagPlayer[] __asm__("D_80070328");
#define Controller7C02CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller7C02Cfunc_8002803C(int,int,int,int,int,void*,int) __asm__("func_8002803C");
void* Controller7C02Cfunc_8002F540(int,int,int) __asm__("func_8002F540");
int Controller7C02Cfunc_8003BABC(void*,int,int) __asm__("func_8003BABC");
int Controller7C02Cfunc_8003BFC0(void*,int) __asm__("func_8003BFC0");
int Controller7C02Cfunc_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Controller7C02Cfunc_8004F178(void*,void*) __asm__("func_8004F178");
int Controller7C02Cfunc_8004F194(void*,void*,void*) __asm__("func_8004F194");
int Controller7C02Cfunc_8004F334(void*,void*) __asm__("func_8004F334");
int Controller7C02Crand(void) __asm__("rand");
extern unsigned char Controller7C02CD_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller7C02CD_80065920[] __asm__("D_80065920");
extern unsigned char Controller7C02CD_80067648[] __asm__("D_80067648");
extern unsigned char Controller7C02CD_80070328[] __asm__("D_80070328");
extern unsigned char Controller7C02Cg_CheatFlags[] __asm__("g_CheatFlags");
extern int Controller7C02CD_8006C58C __asm__("D_8006C58C");
extern int Controller7C02CD_8006C5BC __asm__("D_8006C5BC");
extern int Controller7C02CD_8006C640 __asm__("D_8006C640");
extern int Controller7C02CD_8006C648 __asm__("D_8006C648");
extern int Controller7C02Cunk_ovlheader_800743B8 __asm__("unk_ovlheader_800743B8");
extern int Controller7C02Cunk_ovlheader_800743BC __asm__("unk_ovlheader_800743BC");
extern int Controller7C02Cunk_ovlheader_800743C0 __asm__("unk_ovlheader_800743C0");
extern void* (*Controller7C02CSpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Controller7C02CSpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original controller instructions and twelve-entry dispatch table are the
 * authority. Access widths, byte offsets, integer shifts and branch conditions
 * retain the disc representation. Physical units, helper meanings and caller
 * cadence are unresolved. Empty constraints only preserve compiler allocation;
 * they emit no instructions. The linked word audit and full hashes are the
 * falsifiable acceptance vectors; no semantic runtime parity is claimed here.
 */
void func_level_50_80083508(void *input) {
    register unsigned char *owner __asm__("$18")=input;
    struct {
        int sp20,sp24,sp28,pad2C,sp30,sp34,sp38,pad3C;
    } frame;
    short childClass;
    unsigned char *attachedChild;
    unsigned char *temp_a0_5;
    unsigned char *temp_a0_6;
    unsigned char *temp_a1;
    register unsigned char *spawnedChild __asm__("$16");
    unsigned char *temp_v0_3;
    unsigned char *temp_v0_6;
    unsigned char *temp_v0_7;
    register unsigned char *temp_v1_11 __asm__("$3");
    unsigned char *temp_v1_3;
    register unsigned char *eventDestination __asm__("$21");
    register unsigned char *spawnedRecord __asm__("$17");
    register unsigned char *controller __asm__("$19");
    register unsigned char *childSlot __asm__("$16");
    register int temp_a0 __asm__("$4");
    int temp_a0_4;
    int temp_a3;
    int temp_hi;
    int distance;
    int nextTimer;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_8;
    int temp_v1;
    int timer;
    int temp_v1_6;
    int temp_v1_7;
    int temp_v1_8;
    int temp_v1_9;
    register int eventSelector __asm__("$16");
    register int childIndex __asm__("$17");
    register int childExtent __asm__("$20");
    register int crossedSide __asm__("$22");
    unsigned int temp_v1_10;
    unsigned char temp_a0_2;
    int state;
    __asm__("" : "=r"(owner) : "0"(owner) : "$22");
    crossedSide = 0;
    controller = Controller7C02CField(owner, void **, 0);
    distance = Controller7C02Cfunc_8004F334(owner + 0xC, Controller7C02CD_80070328);
    Controller7C02CField(controller, int *, 0x14) = distance;
    if (distance < 0x1000) {
         {
            register int index __asm__("$3")=Controller7C02CField(owner,unsigned char*,70);
            register int component __asm__("$2")=Controller7C02CField(Controller7C02CD_80070328,int*,4);
            register int ownerComponent __asm__("$4")=Controller7C02CField(owner,int*,16);
            register int firstProduct __asm__("$5");
            __asm__("" : "=r"(index),"=r"(component),"=r"(ownerComponent) : "0"(index),"1"(component),"2"(ownerComponent));
            index<<=1;
            firstProduct=*(short*)(Controller7C02CD_800658A0+index);
            component-=ownerComponent;
            firstProduct*=component;
            index=*(short*)(Controller7C02CD_80065920+index);
            ownerComponent=Controller7C02CField(owner,int*,12);
            component=Controller7C02CField(Controller7C02CD_80070328,int*,0);
            __asm__("" : "=r"(firstProduct),"=r"(index),"=r"(ownerComponent),"=r"(component) : "0"(firstProduct),"1"(index),"2"(ownerComponent),"3"(component));
            index=-index;
            component-=ownerComponent;
            index*=component;
            component=Controller7C02CField(controller,int*,24);
            component>>=31;
            temp_a0=firstProduct-index;
            index=temp_a0>>31;
            index^=component;
            __asm__("" : "=r"(index) : "0"(index));
            crossedSide=(unsigned int)index!=0;
            Controller7C02CField(controller,int*,24)=temp_a0;
        }
    }
    timer = Controller7C02CField(controller, int *, 4);
    if (timer != 0) {
        nextTimer = timer - Controller7C02CD_8006C648;
        Controller7C02CField(controller, int *, 4) = nextTimer;
        if (nextTimer < 0) {
            Controller7C02CField(controller, int *, 4) = 0;
        }
        crossedSide = 0;
    }
    temp_a0_2 = Controller7C02CField(owner, unsigned char *, 0x50);
    if (temp_a0_2 != 0xFF) {
        temp_v0_3 = Controller7C02CSpawnMoby(temp_a0_2, owner);
        Controller7C02CField(controller, void **, 0x24) = temp_v0_3;
        if (temp_v0_3 != 0) {
            Controller7C02Cfunc_8004F178(temp_v0_3 + 0xC, owner + 0xC);
            temp_v1_3 = Controller7C02CField(controller, void **, 0x24);
            Controller7C02CField(temp_v1_3, int *, 0x14) = (int) (Controller7C02CField(temp_v1_3, int *, 0x14) + 0x580);
            Controller7C02CField(Controller7C02CField(controller, void **, 0x24), unsigned char *, 0x46) = (unsigned char) Controller7C02CField(owner, unsigned char *, 0x46);
            Controller7C02CField(Controller7C02CField(controller, void **, 0x24), unsigned char *, 0x4C) = (unsigned char) Controller7C02CField(owner, unsigned char *, 0x4C);
            Controller7C02CField(Controller7C02CField(controller, void **, 0x24), unsigned char *, 0x52) = (unsigned char) Controller7C02CField(owner, unsigned char *, 0x52);
            if (Controller7C02CField(owner, unsigned char *, 0x50) == 0x21) {
                Controller7C02CField(Controller7C02CField(controller, void **, 0x24), int *, 0x54) = 0x2A606060;
            }
            Controller7C02CField(owner, unsigned char *, 0x50) = 0xFFU;
            goto updateAttachedChild;
        }
    } else {
    updateAttachedChild:
        attachedChild = Controller7C02CField(controller, void **, 0x24);
        if (attachedChild != 0) {
            childClass = Controller7C02CField(attachedChild, short *, 0x36);
            if (childClass == 0x21) {
                Controller7C02CField(attachedChild, unsigned char *, 0x46) = (unsigned char) (Controller7C02CField(attachedChild, unsigned char *, 0x46) + (Controller7C02CD_8006C648 * 2));
            } else if (childClass == 0x22) {
                Controller7C02CField(attachedChild, unsigned char *, 0x44) = (unsigned char) (Controller7C02CField(attachedChild, unsigned char *, 0x44) + (Controller7C02CD_8006C648 * 4));
            }
        }
    }
    state=Controller7C02CField(owner,unsigned char*,72);
    if(!state) {
        Controller7C02CField(owner,unsigned char*,72)=1;
        return;
    }
    switch(state) {
        case 1:break;
        default:return;
    }
    if ((Controller7C02CField(owner, unsigned char *, 0x4D) != 0) && (Controller7C02CField(controller, int *, 0x14) < 0x4000) && !(Controller7C02Crand() & 0x3F)) {
        spawnedChild = Controller7C02CSpawnMoby(0x1CBU, owner);
        spawnedRecord = Controller7C02CField(spawnedChild, void **, 0);
         {
            register int factor __asm__("$2")=Controller7C02Crand();
            register int trig __asm__("$3")=Controller7C02CField(owner,unsigned char*,70);
            int product;
            __asm__("" : "=r"(factor),"=r"(trig) : "0"(factor),"1"(trig));
            factor&=2;
            trig<<=1;
            trig=*(unsigned short*)(Controller7C02CD_800658A0+trig);
            factor-=1;
            trig=(trig<<16)>>18;
            product=trig*factor;
            trig=Controller7C02CField(spawnedChild,int*,12);
            trig+=product;
            Controller7C02CField(spawnedChild,int*,12)=trig;
            trig=Controller7C02CField(owner,unsigned char*,70);
            trig<<=1;
            trig=*(short*)(Controller7C02CD_80065920+trig);
            trig=-trig;
            trig>>=2;
            __asm__("" : "=r"(trig),"=r"(factor) : "0"(trig),"1"(factor) : "memory");
            product=trig*factor;
            factor=32;
            Controller7C02CField(spawnedChild,unsigned char*,79)=factor;
            factor=Controller7C02CField(spawnedChild,int*,16);
            trig=5;
            Controller7C02CField(spawnedChild,unsigned char*,71)=trig;
            factor+=product;
            Controller7C02CField(spawnedChild,int*,16)=factor;
        }
        *(int*)spawnedRecord = 0xE;
    }
    if (Controller7C02Cfunc_8003BFC0(owner, Controller7C02CField(controller, int *, 0x20)) == 0) {
        Controller7C02CField(controller, int *, 0x20) = Controller7C02Cfunc_8003BABC(owner, 0, 4);
    }
    if (Controller7C02CField(owner, unsigned char *, 0x4D) != 0) {
        temp_a0_4 = Controller7C02CField(controller, int *, 0x14);
        if ((temp_a0_4 <= 0x9FFF) && (!(Controller7C02CD_8006C640 & 3) || (!(Controller7C02CD_8006C640 & 1) && (temp_a0_4 < 0x5000)))) {
            frame.sp20 = 0;
            frame.sp24=0x352-(Controller7C02Crand()%1700);
            frame.sp28=0;
            Controller7C02Cfunc_8004ED6C(owner+32,&frame.sp20,&frame.sp20);
            Controller7C02Cfunc_8004F194(&frame.sp20, &frame.sp20, owner + 0xC);
            Controller7C02CSpawnParticle(1, 4, &frame.sp20, Controller7C02CField(owner, int *, 0x14) + 0x640);
        }
    }
    temp_v1_7 = Controller7C02CField(controller, int *, 0x28);
    if (temp_v1_7 != 0) {
        Controller7C02CField(controller, int *, 0x28) = (int) (temp_v1_7 - 1);
        if (Controller7C02CField(controller, int *, 0x14) >= 0x601) {
            Controller7C02CField(controller, int *, 0x28) = 0;
        }
         {
            register void *vector __asm__("$16")=&frame.sp30;
            register int arg4 __asm__("$4");
            register int arg5 __asm__("$5");
            register void *arg6 __asm__("$6");
            register int arg7 __asm__("$7");
            Controller7C02Cfunc_8004F178(vector,Controller7C02CD_80070328);
            arg4=4;
            arg5=71;
            arg6=vector;
            arg7=0;
            __asm__("" : "=r"(arg4),"=r"(arg5),"=r"(arg6),"=r"(arg7) : "0"(arg4),"1"(arg5),"2"(arg6),"3"(arg7) : "$17","$20","memory");
            childIndex=0;
            childExtent=1740;
            childSlot=controller;
            frame.sp38-=64;
            Controller7C02CSpawnParticle(arg4,arg5,arg6,arg7);
        }
        do {
            if (Controller7C02CField(controller, int *, 0x28) == 0) {
                temp_v0_6 = Controller7C02CField(childSlot, void **, 0x2C);
                if (temp_v0_6 != 0) {
                    Controller7C02CField(temp_v0_6, signed char *, 0x1C) = 0;
                    Controller7C02CField(childSlot, void **, 0x2C) = 0;
                }
            } else if (Controller7C02CField(childSlot, void **, 0x2C) == 0) {
                temp_v0_7 = Controller7C02Cfunc_8002F540(4, 1, 0x608080);
                Controller7C02CField(childSlot, void **, 0x2C) = temp_v0_7;
                if (temp_v0_7 != 0) {
                    goto initializeChildSlot;
                }
            } else {
    initializeChildSlot:
                Controller7C02CField(Controller7C02CField(childSlot, void **, 0x2C), void **, 0) = 0;
                if (childIndex == 0) {
                    Controller7C02CField(Controller7C02CField(controller, void **, 0x2C), int *, 4) = 0x400;
                    Controller7C02CField(Controller7C02CField(controller, void **, 0x2C), int *, 8) = childExtent;
                } else {
                    Controller7C02CField(Controller7C02CField(childSlot, void **, 0x2C), int *, 4) = -0x400;
                    Controller7C02CField(Controller7C02CField(childSlot, void **, 0x2C), int *, 8) = childExtent;
                }
                temp_a1 = Controller7C02CField(childSlot, void **, 0x2C);
                Controller7C02Cfunc_8004ED6C(owner + 0x20, temp_a1, temp_a1);
                temp_a0_5 = Controller7C02CField(childSlot, void **, 0x2C);
                Controller7C02Cfunc_8004F194(temp_a0_5, temp_a0_5, owner + 0xC);
                Controller7C02Cfunc_8004F178(Controller7C02CField(childSlot, void **, 0x2C) + 0xC, &frame.sp30);
            }
            childIndex += 1;
            childSlot += 4;
        } while (childIndex < 2);
    }
    Controller7C02CField(owner, int *, 0x54) = 0x30C0C0C0;
    Controller7C02CField(owner, unsigned char *, 0x57) = (unsigned char) (Controller7C02CField(owner, unsigned char *, 0x57) + (Controller7C02Crand() & 3));
    temp_v1_8 = Controller7C02CField(controller, int *, 0x14);
    if ((temp_v1_8 < 0x1000) && (crossedSide != 0) && (temp_v1_8 < 0x380)) {
        temp_v1_9 = Controller7C02CField(owner, int *, 0x14) - Controller7C02CField(owner, short *, 0x38);
        temp_v0_8 = temp_v1_9 - Controller7C02CField(Controller7C02CD_80070328, int *, 8);
        if (temp_v0_8 >= 0) {
            if (temp_v0_8 < 0x680) {
                goto checkPlayerState;
            }
        } else if ((Controller7C02CField(Controller7C02CD_80070328, int *, 8) - temp_v1_9) < 0x680) {
checkPlayerState:
            if (Controller7C02CField(Controller7C02CD_80070328, int *, 0x280) >= 0) {
                temp_v1_10 = Controller7C02CField(controller, unsigned int *, 8);
                Controller7C02CField(controller, int *, 0x28) = 8;
                eventSelector = 0;
                switch (temp_v1_10) {
                    /* switch 2 */
                    case 0: /* switch 2 */
                     {
                        register unsigned char *base __asm__("$2")=Controller7C02CD_80070328+0x1CC;
                        __asm__("" : "=r"(base) : "0"(base));
                        eventDestination=base;
                    }
                    eventSelector = 8;
                    *(int*)eventDestination = (int) Controller7C02CField(controller, int *, 0);
                    break;
                    case 1: /* switch 2 */
                    Controller7C02CField(Controller7C02CD_80070328, int *, 0x1C4) = 1;
                    Controller7C02CField(Controller7C02CD_80070328, int *, 0x1C8) = 1;
                    Controller7C02CField(controller, int *, 4) = 0x3C;
                    if (Controller7C02CField(Controller7C02CD_80070328, int *, 0x50) == 9) {
                        Controller7C02CField(controller, int *, 0) += 1;
                    } else {
                        Controller7C02CField(controller, int *, 0) = 0;
                    }
                    break;
                    case 3: /* switch 2 */
                     {
                        register unsigned char *base __asm__("$2")=Controller7C02CD_80070328+0x1D0;
                        __asm__("" : "=r"(base) : "0"(base));
                        eventDestination=base;
                    }
                    eventSelector = 9;
                    *(int*)eventDestination = (int) Controller7C02CField(controller, int *, 0);
                    break;
                    case 2:
                     {
                        register unsigned char *base __asm__("$2")=Controller7C02CD_80070328+0x1BC;
                        register int word __asm__("$4");
                        register int level __asm__("$3");
                        register int one __asm__("$2");
                        __asm__("" : "=r"(base) : "0"(base));
                        eventDestination=base;
                        word=Controller7C02CField(controller,int*,0);
                        level=Controller7C02CD_8006C58C;
                        __asm__("" : "=r"(word),"=r"(level) : "0"(word),"1"(level));
                        one=1;
                        Controller7C02CField(Controller7C02CFlagPlayer,int*,0x1C0)=one;
                        __asm__("" : "=r"(level) : "0"(level) : "memory");
                        level<<=2;
                        *(int*)eventDestination=word;
                        one=*(int*)(Controller7C02CD_80067648+level);
                        Controller7C02CField(Controller7C02CD_80070328,int*,0xF8)=one;
                        eventSelector=10;
                    }
                    break;
                    case 11:
                     {
                        register int word __asm__("$4")=Controller7C02CField(controller,int*,0);
                        register int value __asm__("$2");
                        register unsigned char *base __asm__("$3");
                        __asm__("" : "=r"(word) : "0"(word));
                        value=1;
                        Controller7C02CField(Controller7C02CFlagPlayer,int*,0x1C0)=value;
                        value=Controller7C02CD_8006C58C;
                        __asm__("" : "=r"(value) : "0"(value) : "$3","memory");
                        base=Controller7C02CD_80070328+0x1BC;
                        __asm__("" : "=r"(value),"=r"(base) : "0"(value),"1"(base));
                        value<<=2;
                        *(int*)base=word;
                        value=*(int*)(Controller7C02CD_80067648+value);
                        Controller7C02CField(Controller7C02CD_80070328,int*,0xF8)=value;
                        value=Controller7C02CField(controller,int*,0);
                        eventDestination=base+20;
                        Controller7C02CField(base,int*,20)=value;
                        if(Controller7C02CD_8006C5BC==50)eventSelector=10;
                    }
                    break;
                    case 10: /* switch 2 */
                    Controller7C02CField(Controller7C02Cg_CheatFlags, signed char *, 3) = 1;
                    break;
                }
                temp_a0_6 = Controller7C02CField(controller, void **, 0x24);
                if (temp_a0_6 != 0) {
                    Controller7C02Cfunc_8003BABC(temp_a0_6, 0, 0);
                }
                if (eventSelector != 0) {
                    Controller7C02Cfunc_8002803C(4, eventSelector, Controller7C02Cunk_ovlheader_800743B8, Controller7C02Cunk_ovlheader_800743C0, Controller7C02Cunk_ovlheader_800743BC, eventDestination, *(int*)eventDestination);
                }
            }
        }
    }
    return;
}
#undef Controller7C02CField


INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_80083CD0);

/* AI-generated reconstruction; not human reviewed. Original Rev0 span
 * 80079F10..8007A1FC,187 words. Private offsets0/2/4/8/C..14 follow original
 * signed/unsigned halfword and pointer accesses. State10 synchronizes three
 * child slots; state20 retains pre-update signed speed, increments speed by
 * 12*raw tick below800 and wraps phase to16 bits before per-axis rotation.
 * Each route transforms its own vector; GCC merges only the original common
 * call tail. Empty constraints preserve native read/argument lifetimes and
 * emit no instructions. Units, private-record producer, helpers/effect and
 * particle meanings, callback timing and caller cadence remain unresolved. */
typedef struct {
    short speed;
    unsigned short phase;
    void* effect;
    unsigned char* particle;
    Moby* children[3];
} DecodedSpeedwayCarryTag;
extern int D_8006C648;
void SpeedwayCarryStop(void*) __asm__("func_800509E8");
void* SpeedwayCarryEffect(Vector3D*,int,int,int) __asm__("func_80050844");
void SpeedwayCarryTransform(void*,void*,void*) __asm__("func_8004ED6C");
void SpeedwayCarryAdd(void*,void*,void*) __asm__("func_8004F194");
void func_level_50_800846F0(Moby* argument) {
    register Moby* moby __asm__("$18") = argument;
    register DecodedSpeedwayCarryTag* tag __asm__("$16") = moby->mobyTag;
    register int index __asm__("$17");
    Vector3D velocity;
    int reserved[2];
    switch(moby->state) {
    case 10:
        if (moby->substate == 4) {
            register DecodedSpeedwayCarryTag* cursor __asm__("$3");
            index=0;
            if (tag->particle) { tag->particle[0x10]=0;tag->particle=0; }
            { register int clearState __asm__("$4")=4;
            __asm__("" : : "r"(clearState));
            cursor=tag;
            for(;index<3;index++,cursor=(DecodedSpeedwayCarryTag*)((char*)cursor+4)) {
                __asm__("" : "=r"(cursor) : "0"(cursor));
                if(cursor->children[0]) { cursor->children[0]->substate=clearState;cursor->children[0]=0; }
            }
            }
            goto remove;
        } else {
            if(moby->size>60) { moby->size-=12;if(moby->size<60)moby->size=60; }
            if(tag->particle[0x11]<244) tag->particle[0x11]+=12;
            { register Vector3D* particleArgument __asm__("$4")=(Vector3D*)tag->particle;
              register Vector3D* positionArgument __asm__("$5");
            __asm__("" : : "r"(particleArgument));
            positionArgument=&moby->position;
            __asm__("" : : "r"(positionArgument));
            index=0;
            func_8004F178(particleArgument,positionArgument); }
            for(;index<3;index++,tag=(DecodedSpeedwayCarryTag*)((char*)tag+4)) {
                if(tag->children[0]) {
                    func_8004F178(&tag->children[0]->position,&moby->position);
                    tag->children[0]->angle.roll=moby->angle.roll;
                    __asm__("" : : : "memory");
                    tag->children[0]->angle.pitch=moby->angle.pitch;
                    __asm__("" : : : "memory");
                    tag->children[0]->angle.yaw=moby->angle.yaw;
                }
            }
        }
        break;
    case 20:
        if(moby->substate==4) {
            if(tag->effect) SpeedwayCarryStop(tag->effect);
remove:
            func_80055B18(moby);
            break;
        }
        index=tag->speed;
        { if(index<800) { register int speedBase __asm__("$4")=index;
        __asm__("" : : "r"(speedBase)); { register int tick __asm__("$3")=D_8006C648;
        register int newSpeed __asm__("$2")=speedBase+tick*12;
        __asm__("" : : "r"(newSpeed));tag->speed=newSpeed; } } }
        __asm__("" : : : "memory");
        tag->phase+=D_8006C648;
        if(moby->substate==3) {
            moby->angle.yaw+=(short)tag->phase*8;
            func_80055D24(moby,4);
            velocity.x=index;velocity.y=0;velocity.z=0;
            SpeedwayCarryTransform(&moby->rotationMatrix,&velocity,&velocity);
        } else if(moby->substate==2) {
            moby->angle.pitch+=(short)tag->phase*8;
            func_80055D24(moby,4);
            velocity.x=index;velocity.y=0;velocity.z=0;
            SpeedwayCarryTransform(&moby->rotationMatrix,&velocity,&velocity);
        } else {
            moby->angle.roll+=(short)tag->phase*8;
            func_80055D24(moby,4);
            velocity.x=0;velocity.y=index;velocity.z=0;
            SpeedwayCarryTransform(&moby->rotationMatrix,&velocity,&velocity);
        }

        __asm__("" : "=r"(moby) : "0"(moby));
        SpeedwayCarryAdd(&moby->position,&moby->position,&velocity);
        __asm__("" : "=r"(moby) : "0"(moby));
        if(!tag->effect)tag->effect=SpeedwayCarryEffect(&moby->position,8,10,0x40C0C0);
        break;
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 342 instructions per copy are the acceptance authority.
 * Preserve the 0x70-byte frame, original byte/halfword accesses, signed
 * helper-result truncation, multiply-by-six shifts, and shared exit blocks.
 * Empty constraints emit no instructions and retain original scheduling.
 * Helper names and field offsets identify evidence; helper contracts,
 * units, complete state layouts and caller cadence remain unresolved.
 * Falsifiable check: all original linked words and all full binary hashes.
 */
#define Actor891CCField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor891CCfunc_80018368() __asm__("func_80018368");
int Actor891CCfunc_80019194() __asm__("func_80019194");
int Actor891CCfunc_8001BA30() __asm__("func_8001BA30");
int Actor891CCfunc_8001C288() __asm__("func_8001C288");
int Actor891CCfunc_800359A4() __asm__("func_800359A4");
int Actor891CCfunc_800369B8() __asm__("func_800369B8");
int Actor891CCfunc_8003BABC() __asm__("func_8003BABC");
int Actor891CCfunc_8003BFC0() __asm__("func_8003BFC0");
int Actor891CCfunc_8003C140() __asm__("func_8003C140");
int Actor891CCfunc_8004E880() __asm__("func_8004E880");
int Actor891CCfunc_8004EF74() __asm__("func_8004EF74");
int Actor891CCfunc_8004F178() __asm__("func_8004F178");
int Actor891CCfunc_8004F194() __asm__("func_8004F194");
int Actor891CCfunc_8004F1C8() __asm__("func_8004F1C8");
int Actor891CCfunc_80055B18() __asm__("func_80055B18");
int Actor891CCfunc_80055D24() __asm__("func_80055D24");
int Actor891CCfunc_80055F14() __asm__("func_80055F14");
extern unsigned char Actor891CCD_80070328[] __asm__("D_80070328");
extern unsigned char Actor891CCD_80071918[] __asm__("D_80071918");
void func_level_50_800849DC(void *input) {
    register unsigned char *owner __asm__("$18")=input;
    int sp18[4];
    int sp28[4];
    int sp38[4];
    int sp48[4];
    short firstHandle;
    short actorHandle;
    short lastHandle;
    register int firstDelta __asm__("$2");
    register int actorDelta __asm__("$2");
    register int lastDelta __asm__("$2");
    int secondVectorResult;
    register int hitActorAddress __asm__("$19");
    register int secondVectorSelected __asm__("$20");
    register int firstMagnitude __asm__("$2");
    register int actorMagnitude __asm__("$2");
    register int lastMagnitude __asm__("$2");
    register int byteDelta __asm__("$6");
    unsigned char stateByte;
    register void *scratchPointer __asm__("$16");
    register void *state __asm__("$17");
    register void *stateField0C __asm__("$4");
    register void *secondVector __asm__("$19");
    register void *call4 __asm__("$4");
    register int call5 __asm__("$5");
    register int call7 __asm__("$7");
    register int work2 __asm__("$2");
    register int call6 __asm__("$6");

    __asm__("" : "=r"(owner) : "0"(owner));
    stateByte = Actor891CCField(owner, unsigned char *, 0x48);
    switch (stateByte) {                              /* irregular */
    case 1:
        call4=&sp18;
        __asm__("" : "=r"(call4) : "0"(call4));
        scratchPointer = owner + 0xC;
        state = Actor891CCField(owner, void **, 0);
        Actor891CCfunc_8004F178(call4, scratchPointer);
        if (Actor891CCField(owner, unsigned char *, 0x49) != 0) {
            byteDelta = Actor891CCField(state, unsigned char *, 0x10);
            Actor891CCField(state, int *, 8) = (int) (Actor891CCField(state, int *, 8) - 0xC);
            Actor891CCField(owner, unsigned char *, 0x45) = (unsigned char) (Actor891CCField(owner, unsigned char *, 0x45) + byteDelta);
            Actor891CCField(owner, unsigned char *, 0x44) = (unsigned char) (Actor891CCField(owner, unsigned char *, 0x44) + 8);
            Actor891CCfunc_80055D24(owner, 4, byteDelta);
            if ((Actor891CCField(owner, int *, 0xC) >= 0x400) && (Actor891CCField(owner, int *, 0x10) >= 0x400) && (Actor891CCField(owner, int *, 0x14) >= 0x400)) {
                Actor891CCfunc_8004F194(scratchPointer, scratchPointer, state);
                goto block_8;
            }
            goto block_39;
        }
block_8:
        Actor891CCField(owner, unsigned char *, 0x49) = 1U;
        call4=owner;call5=0;
        __asm__("" : "=r"(call4),"=r"(call5) : "0"(call4),"1"(call5));
        scratchPointer=&sp28;
        Actor891CCfunc_80055F14(call4, call5, scratchPointer);
        call4=owner;call5=1;
        __asm__("" : "=r"(call4),"=r"(call5) : "0"(call4),"1"(call5));
        secondVector=&sp38;
        Actor891CCfunc_80055F14(call4, call5, secondVector);
        secondVectorSelected = 0;
        if (Actor891CCfunc_800359A4(state + 0xE, 2) != 0) {
            if ((Actor891CCfunc_8001C288(scratchPointer, 0x64, 0) != 0) || (secondVectorResult = Actor891CCfunc_8001C288(secondVector, 0x64, 0), secondVectorSelected = secondVectorResult != 0, (secondVectorResult != 0))) {
                Actor891CCField(state, unsigned short *, 0x12) = (unsigned short) (Actor891CCField(state, unsigned short *, 0x12) + 1);
                if (secondVectorSelected != 0) {
                    __asm__ __volatile__("" ::: "$2");
                    firstDelta = -0xC;
                } else {
                    __asm__ __volatile__("" ::: "$2");
                    firstDelta = 0xC;
                }
                Actor891CCField(state, short *, 0x10) = firstDelta;
                __asm__ __volatile__("" ::: "memory");
                Actor891CCField(&Actor891CCD_80070328, int *, 0x298) = Actor891CCfunc_8004E880(Actor891CCField(state, int *, 0), Actor891CCField(state, int *, 4), 0);
                scratchPointer=&sp48;
                Actor891CCfunc_8004F1C8(scratchPointer, owner + 0xC, ((unsigned char*)&Actor891CCD_80070328 + 0x298) - 0x298);
                if (Actor891CCfunc_8004EF74(state, scratchPointer, state) != 0) {
                    Actor891CCField(state, int *, 0) = (int) ((int) (Actor891CCField(state, int *, 0) * 6) >> 3);
                    Actor891CCField(state, int *, 4) = (int) ((int) (Actor891CCField(state, int *, 4) * 6) >> 3);
                    Actor891CCField(state, int *, 8) = (int) ((int) (Actor891CCField(state, int *, 8) * 6) >> 3);
                    if (Actor891CCfunc_8003BFC0(owner, Actor891CCField(state, short *, 0x16)) == 0) {
                        firstHandle = Actor891CCfunc_8003BABC(owner, 4, 0);
                        Actor891CCField(state, short *, 0x16) = firstHandle;
                        if (firstHandle >= 0) {
                            firstMagnitude = Actor891CCField(state, int *, 8);
                            if (firstMagnitude < 0) {
                                firstMagnitude = -firstMagnitude;
                            }
                            Actor891CCfunc_8003C140(firstHandle, firstMagnitude * 0x28);
                        }
                    }
                }
            }
            hitActorAddress = Actor891CCfunc_8001BA30(&sp28, 0x96, 1, 0, 0x10000000, owner);
            if (hitActorAddress == 0) {
                __asm__("" : "=r"(hitActorAddress) : "0"(hitActorAddress));
                call4=&sp38;call5=150;call6=1;
                __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));
                call7=0;
                hitActorAddress = Actor891CCfunc_8001BA30(call4, call5, call6, call7, 0x10000000, owner);
                stateField0C = state + 0xC;
                if (hitActorAddress != 0) {
                    secondVectorSelected = 1;
                    goto block_24;
                }
            } else {
block_24:
                if (Actor891CCfunc_8003BFC0(owner, Actor891CCField(state, short *, 0x16)) == 0) {
                    Actor891CCField(state, short *, 0x14) = Actor891CCfunc_8003BABC(owner, 5, 0);
                }
                Actor891CCField(state, unsigned short *, 0x12) = (unsigned short) (Actor891CCField(state, unsigned short *, 0x12) + 1);
                if (secondVectorSelected != 0) {
                    __asm__ __volatile__("" ::: "$2");
                    actorDelta = -0xC;
                } else {
                    __asm__ __volatile__("" ::: "$2");
                    actorDelta = 0xC;
                }
                Actor891CCField(state, short *, 0x10) = actorDelta;
                scratchPointer=&sp48;
                Actor891CCfunc_8004F1C8(scratchPointer, owner + 0xC, hitActorAddress + 0xC);
                if (Actor891CCfunc_8004EF74(state, scratchPointer, state) != 0) {
                    Actor891CCField(state, int *, 0) = (int) ((int) (Actor891CCField(state, int *, 0) * 6) >> 3);
                    Actor891CCField(state, int *, 4) = (int) ((int) (Actor891CCField(state, int *, 4) * 6) >> 3);
                    Actor891CCField(state, int *, 8) = (int) ((int) (Actor891CCField(state, int *, 8) * 6) >> 3);
                    work2=Actor891CCfunc_8003BFC0(owner, Actor891CCField(state, short *, 0x16));
                    stateField0C = state + 0xC;
                    if (work2 == 0) {
                        __asm__("" : "=r"(work2) : "0"(work2));
                        actorHandle = Actor891CCfunc_8003BABC(owner, 4, 0);
                        Actor891CCField(state, short *, 0x16) = actorHandle;
                        if (actorHandle >= 0) {
                            actorMagnitude = Actor891CCField(state, int *, 8);
                            if (actorMagnitude < 0) {
                                actorMagnitude = -actorMagnitude;
                            }
                            Actor891CCfunc_8003C140(actorHandle, actorMagnitude * 0x28);
                        }
                        goto block_35;
                    } else { goto block_36; }
                } else {
                    goto block_35;
                }
            }
        } else {
block_35:
            stateField0C = state + 0xC;
        }
block_36:
        if (Actor891CCfunc_800359A4(stateField0C, 2) != 0) goto block_39;
        if (Actor891CCField(state, short *, 0x12) < 0x1F) goto block_40;
block_39:
        Actor891CCField(owner, unsigned char *, 0x48) = 0xAU;
        goto finish;
block_40:
        {
            if (Actor891CCfunc_80019194(&sp28, 0x96) == 0) {
                if (Actor891CCfunc_80019194(&sp38, 0x96) != 0) {
                    secondVectorSelected = 1;
                    goto block_44;
                }
                if (Actor891CCfunc_80018368(&sp18, owner + 0xC) != 0) {
                    goto block_44;
                }
            } else {
block_44:
                Actor891CCField(state, unsigned short *, 0x12) = (unsigned short) (Actor891CCField(state, unsigned short *, 0x12) + 1);
                if (secondVectorSelected != 0) {
                    __asm__ __volatile__("" ::: "$2");
                    lastDelta = -0xC;
                } else {
                    __asm__ __volatile__("" ::: "$2");
                    lastDelta = 0xC;
                }
                Actor891CCField(state, short *, 0x10) = lastDelta;
                if (Actor891CCfunc_8004EF74(state, &Actor891CCD_80071918, state) != 0) {
                    Actor891CCField(state, int *, 0) = (int) ((int) (Actor891CCField(state, int *, 0) * 6) >> 3);
                    Actor891CCField(state, int *, 4) = (int) ((int) (Actor891CCField(state, int *, 4) * 6) >> 3);
                    Actor891CCField(state, int *, 8) = (int) (((int) (Actor891CCField(state, int *, 8) * 6) >> 3) + 0x14);
                    if (Actor891CCfunc_8003BFC0(owner, Actor891CCField(state, short *, 0x16)) == 0) {
                        lastHandle = Actor891CCfunc_8003BABC(owner, 4, 0);
                        Actor891CCField(state, short *, 0x16) = lastHandle;
                        if (lastHandle >= 0) {
                            lastMagnitude = Actor891CCField(state, int *, 8);
                            if (lastMagnitude < 0) {
                                lastMagnitude = -lastMagnitude;
                            }
                            __asm__("" : "=r"(lastMagnitude) : "0"(lastMagnitude));
                            Actor891CCfunc_8003C140(lastHandle, lastMagnitude * 0x28);
                            return;
                        }
                    }
                }
                return;
            }
        }
        break;
    case 10:
        Actor891CCfunc_80055D24(owner, 4);
        Actor891CCfunc_800369B8(owner, 0x18);
        Actor891CCfunc_80055B18(owner);
        break;
    }
finish:;
}

#undef Actor891CCField


typedef struct { int linkedIndex, animationA, animationB; } DecodedLinkedModelTag;
extern Moby* D_8006C550;
int DecodedLinkedModelHeadingDifference(int,int) __asm__("func_8004F264");
void func_level_50_80084F34(Moby* moby) {
    DecodedLinkedModelTag* tag = moby->mobyTag;
    Moby* linked = &D_8006C550[tag->linkedIndex];
    Vector3D modelPoint, position, delta;
    int angle, length;
    if (linked->state >= 0x80) goto remove;
    switch (moby->state) {
    case 0:
        if (!linked->lowDrawDistance) {
        remove:
            func_80055B18(moby);
            return;
        }
        if (linked->animationState.nextId != tag->animationA
            && linked->animationState.nextId != tag->animationB) {
            moby->unknownCollision = 0;
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            moby->state = 1;
            break;
        }
        angle = linked->angle.yaw - 0x40;
        func_8004F178(&position,&linked->position);
        angle &= 0xFF;
        position.x += (D_80065920[angle] * 275) >> 11;
        position.y += (D_800658A0[angle] * 275) >> 11;
        position.z = linked->position.z - linked->distanceToGround;
        func_80055D24(linked,4);
        func_80055F14(linked,2,&modelPoint);
        func_8004F178(&moby->position,&position);
        func_8004F1C8(&delta,&position,&modelPoint);
        moby->angle.yaw = linked->angle.yaw + 0x7A;
        length = func_8004EDE8(&delta,0);
        angle = func_8004E880(delta.x,delta.y,0);
        if (DecodedLinkedModelHeadingDifference(angle,linked->angle.yaw) < 0x40)
            length = -length;
        moby->angle.pitch = func_8004E880(length,delta.z,0) - 1;
        break;
    case 1:
        if (linked->animationState.nextId == tag->animationA
            || linked->animationState.nextId == tag->animationB) {
            moby->unknown3[0] = 1;
            moby->lowDrawDistance = 0x28;
            moby->drawn = 1;
            func_80055D24(moby,1);
            moby->state = 0;
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_800851B0);

typedef struct {
    int box[6];
    int innerBox[6];
    int actorIndex, selector, outerLimit, innerLimit, level;
} DecodedStreamTrigger;
extern int D_8006C5C8,D_8006E480,D_8006E344,D_8006E48C,D_8006C58C,D_8006E470,D_8006E49C,D_8006C4F8;
extern int D_80072098[];
extern int D_8006DBE8[][4];
extern Moby* D_8006C550;
void func_80052918(int,Moby*);
int func_8005E0BC(int,void*,int);
int func_8005F46C(int,void*);
void func_level_50_800857B4(Moby* actor) {
    register Moby* current __asm__("$18")=actor;
    register DecodedStreamTrigger* tag __asm__("$16");
    register Spyro* player __asm__("$17");
    register int* streamState __asm__("$20");
    unsigned char parameter;
    int record, offset;
    __asm__("" : "=r"(current) : "0"(current));
    tag=current->mobyTag;
    if(tag->level!=D_8006C5C8)return;
    streamState=&D_8006E480;
    __asm__("" : "=r"(streamState) : "0"(streamState));
    if(*streamState || D_8006E344==1 || D_8006E344==0xF)return;
    player=&g_Spyro;
    if(func_80036220((Vector3D*)player,(void*)tag,0,tag->outerLimit)) {
        func_80052918(tag->selector,&D_8006C550[tag->actorIndex]);return;
    }
    switch(current->state) {
    case 0:
        if(func_80036220((Vector3D*)player,(void*)tag->innerBox,0,tag->innerLimit)) {
            D_8006E49C=1;current->state=1;
        }
        break;
    case 1:
        if(!func_80036220((Vector3D*)player,(void*)tag->innerBox,0x400,tag->innerLimit+0x400)) {
            D_8006E49C=0;current->state=0;break;
        }
        if(D_8006E48C)break;
        record=2;parameter=0x80;
        if(D_8006C5C8)record=D_8006C5C8*2+2;
        offset=D_80072098[record*2]+D_8006DBE8[D_8006C58C][0];
        func_8005E0BC(0xE,&parameter,0);
        {
        register int sector __asm__("$4")=offset;
        register void* buffer __asm__("$16");
        __asm__("" : "=r"(sector) : "0"(sector));
        buffer=(void*)((int)streamState-8);
        func_8005F46C(D_8006E470+sector/0x800,buffer);
        func_8005E0BC(2,buffer,0);
        }
        func_8005E0BC(0x16,0,0);
        current->state=2;break;
    case 2:
        if(!func_80036220((Vector3D*)player,(void*)tag->innerBox,0x400,tag->innerLimit+0x400)) {
            D_8006E49C=0;current->state=0;
        } else if(D_8006E48C) {
            D_8006E49C=1;current->state=1;
        }
        break;
    case 3:
        func_80052918(tag->selector,&D_8006C550[tag->actorIndex]);
        D_8006C4F8=2;break;
    }
}

extern int (*Controller780F0Spawn)(int,int,void*,void*) __asm__("SpawnParticle");
extern int (*Controller780F0Header)(void*,int) __asm__("unk_ovlheader_80074324");
#define Controller780F0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char Controller780F0Sin[] __asm__("D_800658A0");
extern unsigned char Controller780F0Cos[] __asm__("D_80065920");
extern unsigned short Controller780F0Angle0 __asm__("D_8006E03E"), Controller780F0Angle1 __asm__("D_8006E040");
int Controller780F0Helper18368(void*,void*) __asm__("func_80018368");
int Controller780F0Helper359A4(void*,int) __asm__("func_800359A4");
int Controller780F0Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller780F0Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller780F0Helper55B18() __asm__("func_80055B18");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level25/800780F0, level32/8008A7EC, level35/800787C8,
 * level45/8007884C, level46/800799A0 and level50/80085A60, moby text.
 * Every copy has 292 original instructions and six dispatch entries with
 * relative targets 364, 400, 540, 608, 908 and 1004 bytes. Helper and global
 * symbols were compared separately before reusing this body.
 * Preserve byte colour loads, packed word store, signed decrement/clamp -64,
 * table byte offsets and signed shifts, branch-specific countdown rereads,
 * six state paths and callback arguments. The initial removal path supplies
 * the original incoming argument register implicitly; later removal explicitly
 * prepares owner and still reaches the shared final stores.
 * Units, fixed-point meanings, helper contracts and caller cadence remain
 * unresolved; updates below are once per invocation. No runtime semantics inferred.
 * Confidence: exact native and linked instructions/data. Falsifiable vectors:
 * every original word and complete retail executable/overlay SHA checks.
 * Empty constraints preserve compiler scheduling and distinct original calls;
 * they contain no opcode patches.
 */
void func_level_50_80085A60(void *input) {
    register unsigned char *owner __asm__("$16")=input;
    Vector3D previous;
    unsigned char color[4];
    int pad20;
    unsigned char first[3];
    int pad28;
    unsigned char second[3];
    int nextVerticalWord;
    int initialCountdown;
    register int firstWeight __asm__("$3");
    register int secondWeight __asm__("$4");
    int helperResult;
    register int blendLimit __asm__("$2");
    register int belowBlendLimit __asm__("$2");
    unsigned char decrementedByte;
    unsigned int state;
    unsigned char nextByte;
    register unsigned char *tag __asm__("$17");
    register unsigned char *position __asm__("$18");
    register unsigned char *countdownArgument __asm__("$4");

    __asm__("" : "=r"(owner) : "0"(owner));
    tag = Controller780F0Field(owner, void **, 0);
    color[0] = Controller780F0Field(tag, unsigned char *, 0xC);
    color[1] = Controller780F0Field(tag, unsigned char *, 0xD);
    color[2] = Controller780F0Field(tag, unsigned char *, 0xE);
    color[3] = Controller780F0Field(tag, unsigned char *, 0xF);
    state = Controller780F0Field(owner, unsigned char *, 0x48);

    if (state != 5) {
        position = owner + 0xC;
        if (Controller780F0Field(owner, unsigned char *, 0x4D) == 0) {
            Controller780F0Helper55B18();
            return;
        }
        Controller780F0Helper4F178(&previous, position);
        nextVerticalWord = Controller780F0Field(tag, int *, 8) - 2;
        Controller780F0Field(tag, int *, 8) = nextVerticalWord;
        if (nextVerticalWord < -0x40) {
            Controller780F0Field(tag, int *, 8) = -0x40;
        }
        Controller780F0Helper4F194(position, position, tag);
        Controller780F0Spawn(4, 0x54, position, tag + 0xC);
        initialCountdown = Controller780F0Field(tag, int *, 0x10);
        if (initialCountdown < 0x20) {
            { register int left __asm__("$3")=initialCountdown;
            register int right __asm__("$2")=Controller780F0Field(tag,unsigned char*,0xC);
            register int product __asm__("$8");
            register int shifted __asm__("$2");
            __asm__("" : "=r"(left),"=r"(right) : "0"(left),"1"(right));
            product=left*right;
            __asm__("" : "=r"(product) : "0"(product) : "$2");
            shifted=product>>5;
            __asm__("" : "=r"(shifted) : "0"(shifted));
            color[0]=shifted; }
            { register int right __asm__("$3")=Controller780F0Field(tag,unsigned char*,0xD);
            register int left __asm__("$2")=Controller780F0Field(tag,int*,0x10);
            register int product __asm__("$8");
            register int shifted __asm__("$2");
            __asm__("" : "=r"(left),"=r"(right) : "0"(left),"1"(right));
            product=left*right;
            __asm__("" : "=r"(product) : "0"(product) : "$2");
            shifted=product>>5;
            __asm__("" : "=r"(shifted) : "0"(shifted));
            color[1]=shifted; }
            { register int right __asm__("$3")=Controller780F0Field(tag,unsigned char*,0xE);
            register int left __asm__("$2")=Controller780F0Field(tag,int*,0x10);
            register int product __asm__("$8");
            register int shifted __asm__("$2");
            __asm__("" : "=r"(left),"=r"(right) : "0"(left),"1"(right));
            product=left*right;
            __asm__("" : "=r"(product) : "0"(product) : "$2");
            shifted=product>>5;
            __asm__("" : "=r"(shifted) : "0"(shifted));
            color[2]=shifted; }
        }
        state = Controller780F0Field(owner, unsigned char *, 0x48);

        goto dispatch;
    }
dispatch:
    {
        switch (state) {
        case 0:
            helperResult=Controller780F0Helper359A4(tag+0x10,4);
            __asm__ volatile("" : : : "$8");
            if(helperResult) goto removeOwner;
            helperResult=Controller780F0Helper18368(&previous,owner+0xC);
            __asm__ volatile("" : : : "$12");
                goto testResult;
        case 1:
            Controller780F0Field(owner, int *, 0xC) = (int) (Controller780F0Field(owner, int *, 0xC) + ((int) (*(unsigned short*)(Controller780F0Cos + (((Controller780F0Field(tag, int *, 0x10) + Controller780F0Field(owner, unsigned char *, 0x49)) << 5) & 0x1E0)) << 0x10) >> 0x16));
            Controller780F0Field(owner, int *, 0x10) = (int) (Controller780F0Field(owner, int *, 0x10) + ((int) (*(unsigned short*)(Controller780F0Sin + (((Controller780F0Field(tag, int *, 0x10) + Controller780F0Field(owner, unsigned char *, 0x49)) << 5) & 0x1E0)) << 0x10) >> 0x16));
            helperResult=Controller780F0Helper359A4(tag+0x10,4);
            __asm__ volatile("" : : : "$9");
            if(helperResult==0) {
                helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                __asm__ volatile("" : : : "$13");
                goto testResult;
            }
            goto removeOwner;
        case 2:
            if (Controller780F0Helper18368(&previous, owner + 0xC) == 0) {
                if (Controller780F0Helper359A4(tag + 0x10, 4) != 0) {
                    Controller780F0Header(owner, -1);
                    goto removeOwner;
                }
            } else {
                goto removeOwner;
            }
            break;
        case 3:
            if (Controller780F0Field(tag, int *, 0x10) < 0x20) {
                { register int full __asm__("$3")=255;
                register int byteWord __asm__("$2")=32;
                __asm__("" : "=r"(full),"=r"(byteWord) : "0"(full),"1"(byteWord));
                second[0] = byteWord;
                byteWord=64;
                first[0] = 0;
                first[1] = full;
                first[2] = 0;
                second[1] = byteWord;
                second[2] = full; }
                firstWeight = Controller780F0Field(tag,int*,0x10);
                __asm__("" : "=r"(firstWeight) : "0"(firstWeight) : "$2");
                blendLimit = 0x20;
            } else {
                { register int full __asm__("$2")=255;
                __asm__("" : "=r"(full) : "0"(full));
                first[0] = full;
                first[1] = 0;
                first[2] = 0;
                second[0] = 0;
                second[1] = full;
                second[2] = 0; }
                firstWeight = Controller780F0Field(tag,int*,0x10);
                __asm__("" : "=r"(firstWeight) : "0"(firstWeight) : "$2");
                blendLimit = 0x38;
            }
            secondWeight = blendLimit - firstWeight;
            belowBlendLimit = secondWeight < 9;
            if (secondWeight < 0) {
                secondWeight = 0;
                __asm__("" : "=r"(secondWeight) : "0"(secondWeight));
                belowBlendLimit = secondWeight < 9;
                __asm__("" : "=r"(belowBlendLimit) : "0"(belowBlendLimit));
            }
            if (belowBlendLimit == 0) {
                secondWeight = 8;
            }
            firstWeight = 8;
            { register int firstByte __asm__("$2")=first[0];
            register int firstProduct __asm__("$5");
            register int secondByte __asm__("$2");
            register int secondProduct __asm__("$9");
            register int sum __asm__("$2");
            __asm__("" : "=r"(firstByte),"=r"(firstWeight) : "0"(firstByte),"1"(firstWeight));
            firstWeight-=secondWeight;
            __asm__("" : "=r"(firstByte),"=r"(firstWeight) : "0"(firstByte),"1"(firstWeight));
            firstProduct=firstWeight*firstByte;
            __asm__("" : "=r"(firstProduct) : "0"(firstProduct) : "$2");
            secondByte=second[0];
            __asm__("" : "=r"(secondByte) : "0"(secondByte));
            secondProduct=secondWeight*secondByte;
            __asm__("" : "=r"(secondProduct) : "0"(secondProduct) : "$2");
            sum=(firstProduct+secondProduct)>>3;
            __asm__("" : "=r"(sum) : "0"(sum));
            Controller780F0Field(tag,unsigned char*,0xC)=sum; }
            { register int firstByte __asm__("$2")=first[1];
            register int firstProduct __asm__("$5");
            register int secondByte __asm__("$2");
            register int secondProduct __asm__("$9");
            register int sum __asm__("$2");
            __asm__("" : "=r"(firstByte) : "0"(firstByte));
            firstProduct=firstWeight*firstByte;
            __asm__("" : "=r"(firstProduct) : "0"(firstProduct) : "$2");
            secondByte=second[1];
            __asm__("" : "=r"(secondByte) : "0"(secondByte));
            secondProduct=secondWeight*secondByte;
            __asm__("" : "=r"(secondProduct) : "0"(secondProduct) : "$2");
            sum=(firstProduct+secondProduct)>>3;
            __asm__("" : "=r"(sum) : "0"(sum));
            Controller780F0Field(tag,unsigned char*,0xD)=sum; }
            { register int firstByte __asm__("$2")=first[2];
            register int firstProduct __asm__("$3");
            register int secondByte __asm__("$2");
            register int secondProduct __asm__("$9");
            register int sum __asm__("$2");
            __asm__("" : "=r"(firstByte) : "0"(firstByte));
            firstProduct=firstWeight*firstByte;
            __asm__("" : "=r"(firstProduct) : "0"(firstProduct) : "$2");
            secondByte=second[2];
            __asm__("" : "=r"(secondByte) : "0"(secondByte));
            secondProduct=secondWeight*secondByte;
            __asm__("" : "=r"(secondProduct) : "0"(secondProduct) : "$2");
            sum=(firstProduct+secondProduct)>>3;
            __asm__("" : "=r"(sum) : "0"(sum));
            Controller780F0Field(tag,unsigned char*,0xE)=sum; }
            helperResult=Controller780F0Helper359A4(tag+0x10,4);
            __asm__ volatile("" : : : "$10");
            if(helperResult==0) {
                helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                __asm__ volatile("" : : : "$14");
                goto testResult;
            }
            goto removeOwner;
        case 4:
            decrementedByte = Controller780F0Field(owner, unsigned char *, 0x49) - 1;
            Controller780F0Field(owner, unsigned char *, 0x49) = decrementedByte;
            __asm__ volatile("" : : : "$4");
            countdownArgument = tag + 0x10;

            if (!(decrementedByte & 0xFF)) {
                Controller780F0Header(owner, -1);
                __asm__ volatile("" : "=r"(tag) : "0"(tag));
                Controller780F0Field(owner, unsigned char *, 0x49) = 4U;
                __asm__ volatile("" : : : "$4");
                countdownArgument = tag + 0x10;

            }
            helperResult=Controller780F0Helper359A4(countdownArgument,4);
            __asm__ volatile("" : : : "$11");
            if(helperResult==0) {
                helperResult = Controller780F0Helper18368(&previous, owner + 0xC);
                __asm__ volatile("" : : : "$15");
                __asm__ volatile("" : "=r"(tag) : "0"(tag));
                goto testResult;
            }
            goto removeOwner;
        case 5:
            if (Controller780F0Field(owner, unsigned char *, 0x49) == 0) {
                Controller780F0Field(owner, signed char *, 0x4C) = 0x7F;
                nextByte = 4;
            } else {
                Controller780F0Field(owner, signed char *, 0x4C) = 0;
                Controller780F0Field(owner, unsigned char *, 0x4D) = 0U;
                nextByte = Controller780F0Field(owner, unsigned char *, 0x49) - 1;
            }
            Controller780F0Field(owner, unsigned char *, 0x49) = nextByte;
            helperResult = Controller780F0Helper359A4(tag + 0x10, 4);
            goto testResult;
        }
    }
    goto finalTail;
testResult:
    if(helperResult==0) goto finalTail;
removeOwner:
    Controller780F0Helper55B18(owner);
finalTail:
    Controller780F0Field(owner, signed char *, 0x46) = (signed char) (((int) (Controller780F0Angle1 << 0x10) >> 0x14) - 0x80);
    Controller780F0Field(owner, signed char *, 0x45) = (signed char) ((unsigned short) Controller780F0Angle0 >> 4);
    Controller780F0Field(owner, int *, 0x54) = *(int*)color;
}

#undef Controller780F0Field


typedef struct { Moby* parent; unsigned char unk4, unk5; } DecodedYawTag;
extern int D_8006C644;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_level_50_80085EF0(Moby* moby) {
    DecodedYawTag* tag = moby->mobyTag;
    if (moby->state != tag->parent->state) func_80055B18(moby);
    else if (moby->animationState.id == 0) moby->angle.yaw += 6;
    else {
        int byteOffset = ((tag->unk5 + D_8006C644) << 3) & 0x1F8;
        int wave = *(short*)((char*)D_80065920 + byteOffset);
        moby->angle.yaw = tag->unk4 + ((wave * 3) >> 9);
    }
}

typedef struct { int timer, reserved04; short firstFrame, lastFrame; int linkedIndex; } DecodedTimedPickupTag;
extern int D_8006FA80;
extern Moby* D_8006C550;
extern unsigned short DecodedTimedPickupYaw __asm__("D_8006E040");
extern unsigned short DecodedTimedPickupPitch __asm__("D_8006E03E");
extern int (*DecodedTimedPickupQuery)(Moby*,Vector3D*,int) __asm__("unk_ovlheader_800743A0");
int DecodedTimedPickupTimer(void*,int) __asm__("func_800359A4");
void func_level_50_80085FA0(Moby* moby) {
    DecodedTimedPickupTag* tag = moby->mobyTag;
    unsigned short* linked;
    switch (moby->state) {
    case 0:
        moby->state = 1;
        break;
    case 1:
        if (tag->firstFrame && tag->lastFrame) {
            if (tag->firstFrame < D_8006FA80 && D_8006FA80 < tag->lastFrame) {
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
            } else {
                moby->unknown3[0] = 1;
                moby->lowDrawDistance = 0x3F;
                moby->drawn = 1;
            }
        }
        moby->angle.yaw = ((short)DecodedTimedPickupYaw >> 4) - 0x80;
        moby->angle.pitch = DecodedTimedPickupPitch >> 4;
        moby->size = 0x18;
        if (DecodedTimedPickupQuery(moby, (Vector3D*)&spyro, 0x672)) moby->state = 2;
        break;
    case 2:
        func_8003BABC(moby, 0, 0);
        if (tag->linkedIndex != -1) {
            linked = (unsigned short*)((char*)D_8006C550[tag->linkedIndex].mobyTag + 0x14C);
            linked[0] += linked[1];
        }
        moby->updateDistance = 0xFF;
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
        tag->timer = 60;
        moby->state = 3;
        break;
    case 3:
        if (DecodedTimedPickupTimer(tag, 4)) {
            moby->angle.yaw = ((short)DecodedTimedPickupYaw >> 4) - 0x80;
            moby->angle.pitch = DecodedTimedPickupPitch >> 4;
            moby->lowDrawDistance = 0x3F;
            moby->updateDistance = 0x10;
            moby->state = 1;
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_800861B0);

typedef struct {
    int timer;
    Colour* colours;
} DecodedColourFadeTag;
extern int D_8006C648;
void func_80055B18(Moby*);
void func_level_50_80086CCC(Moby* moby) {
    DecodedColourFadeTag* tag = moby->mobyTag;
    int timer = tag->timer + D_8006C648;
    Colour colour;
    tag->timer = timer;
    if (timer >= 30) {
        func_80055B18(moby);
    } else {
        int factor = ((30 - timer) << 8) / 30;
        colour.r = (factor * tag->colours[moby->substate].r) >> 8;
        colour.g = (factor * tag->colours[moby->substate].g) >> 8;
        colour.b = (factor * tag->colours[moby->substate].b) >> 8;
        moby->size = factor;
        moby->angle.yaw = (moby->substate << 8) / 6;
        moby->colour.r = colour.r;
        moby->colour.g = colour.g;
        moby->colour.b = colour.b;
        moby->colour.a = 0;
        moby->lowDrawDistance = 0x10;
    }
}

typedef struct { int timer; Colour* colours; unsigned char* secondary; Vector3D velocity; } DecodedColourTimer;
extern int D_8006C648;
void func_800509E8(void*);
void func_level_50_80086E08(Moby* moby) {
    DecodedColourTimer* tag=moby->mobyTag;
    Colour colour;
    int scale;
    tag->timer+=D_8006C648;
    if(tag->timer>=0x3C) {
        if(tag->secondary)func_800509E8(tag->secondary);
        func_80055B18(moby);
        return;
    }
    tag->velocity.z-=8;
    func_8004F194(&moby->position,&moby->position,&tag->velocity);
    scale=((0x3C-tag->timer)<<8)/0x3C;
    colour.r=(scale*tag->colours[moby->substate].r)>>8;
    colour.g=(scale*tag->colours[moby->substate].g)>>8;
    colour.b=(scale*tag->colours[moby->substate].b)>>8;
    moby->colour.r=colour.r;
    moby->colour.g=colour.g;
    moby->colour.b=colour.b;
    moby->colour.a=0;
    if(tag->secondary) {
        tag->secondary[0x68]=colour.r;
        tag->secondary[0x69]=colour.g;
        tag->secondary[0x6A]=colour.b;
    }
}

typedef struct { int actorIndex; Vector3D position; int timer; int* counter; } DecodedLinkedActor;
extern Moby* D_8006C550;
extern int D_8006C79C,D_8006C58C;
extern int D_80071AB0[][8];

extern Moby* DecodedActorCallback(Moby*,int,Vector3D*,Vector3D*) __asm__("func_80036A68");
int func_8001A358(Vector3D*,int);
void func_level_50_80086F98(Moby* moby) {
    DecodedLinkedActor* tag=moby->mobyTag;
    switch(moby->state) {
    case 0:
        if(D_8006C550[tag->actorIndex].state&0x80) {
            Moby* actor;
            int height;
            func_8004F178(&tag->position,&D_8006C550[tag->actorIndex].position);
            actor=DecodedActorCallback(moby,1,&tag->position,&moby->position);
            if(!actor)return;
            func_8004F178(&actor->position,&moby->position);
            height=func_8001A358(&actor->position,0x400);
            if(height)actor->position.z=height;
            {unsigned char gem=moby->gemValue; actor->state=0;actor->gemValue=gem;}
            func_80055B18(moby);return;
        }
        func_8004F178(&tag->position,&moby->position);
        func_8004F178(&moby->position,&D_8006C550[tag->actorIndex].position);
        moby->substate=*tag->counter;
        tag->timer=moby->substate*15;
        (*tag->counter)++;
        moby->state=1;
        break;
    case 1:
        if(D_8006C550[tag->actorIndex].mobyClass==0xCE)
            func_8004F178(&moby->position,&D_8006C550[tag->actorIndex].position);
        if(D_8006C550[tag->actorIndex].state&0x80)moby->state=2;
        break;
    case 2:
        if(func_800359A4(&tag->timer,4))moby->state=3;
        break;
    case 3: {
        int handle;
        if(D_8006C550[tag->actorIndex].gemValue==0xFF) {
            func_8003BA00(&D_8006C550[tag->actorIndex]);
            {
                register int packed __asm__("$3")=tag->actorIndex;
                register int offset __asm__("$2")=D_8006C79C;
                register unsigned char* base __asm__("$4");
                register int bit __asm__("$5");
                __asm__("" : "=r"(packed),"=r"(offset) : "0"(packed),"1"(offset) : "$4");
                base=(unsigned char*)D_80071AB0;
                __asm__("" : "=r"(base) : "0"(base),"r"(packed),"r"(offset));
                packed+=offset;bit=packed&0x1F;packed>>=5;
                {
                    register int level __asm__("$2")=D_8006C58C;
                    __asm__("" : "=r"(level) : "0"(level),"r"(packed),"r"(bit));
                    packed<<=2;level<<=5;level+=(int)base;packed+=level;
                    __asm__("" : "=r"(packed) : "0"(packed),"r"(bit));
                    *(int*)packed|=1<<bit;
                }
            }
        }
        if(DecodedActorCallback(moby,1,&moby->position,&tag->position)) {
            handle=PlaySound(((unsigned char*)D_8006C654)[0x1A],moby,0);
            if(handle>=0)func_8003C0B0(handle,(moby->substate<<8)+0x1000);
            func_80055B18(moby);
        }
        break;
    }
    }
}

typedef struct { unsigned char reserved00[0xA]; unsigned short threshold; unsigned char reserved0C[4]; unsigned char enabled; unsigned char reserved11[3]; } DecodedSelectorDescriptor;
typedef struct { unsigned char reserved00[0xC]; unsigned char* records; } DecodedSelectorAttachment;
typedef struct { int minimum,maximum,timerMinimum,timerMaximum; DecodedSelectorAttachment* attachment; int timer,handle; } DecodedSelectorUpdate;
extern unsigned char* D_8006C708;
extern DecodedSelectorDescriptor* D_8006C6A0;
extern int D_8006E044,D_8006E028;
int func_8004F334(Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_80036518(void*,void*,int*);
void func_level_50_800872C8(Moby* actor) {
    register Moby* moby __asm__("$17")=actor;
    register DecodedSelectorUpdate* tag __asm__("$16");
    int index;
    __asm__("" : "=r"(moby) : "0"(moby));
    tag=moby->mobyTag;
    if(D_8006C6A0[D_8006C708[tag->minimum]].enabled) {
        register int distance __asm__("$2");
        register int z __asm__("$3");
        register int total __asm__("$5");
        register int* mode __asm__("$5")=&D_8006E044;
        __asm__("" : "=r"(mode) : "0"(mode));
        if((unsigned int)(*mode-9)<2) {
            distance=func_8004F334(&moby->position,(Vector3D*)((char*)mode-0x24));
            {
                register int actorZ __asm__("$3")=moby->position.z;
                register int otherZ __asm__("$4")=D_8006E028;
                __asm__("" : "=r"(actorZ), "=r"(otherZ) : "0"(actorZ), "1"(otherZ));
                z=actorZ-otherZ;
            }
        } else {
            distance=func_8004F334(&moby->position,(Vector3D*)&spyro);
            {
                register int actorZ __asm__("$3")=moby->position.z;
                register int otherZ __asm__("$4")=spyro.position.z;
                __asm__("" : "=r"(actorZ), "=r"(otherZ) : "0"(actorZ), "1"(otherZ));
                z=actorZ-otherZ;
            }
        }
        if(z<0)z=-z;
        __asm__("" : "=r"(z) : "0"(z), "r"(distance));
        total=z+distance;
        total=((total<<2)-total)>>4;
        {
        register int within __asm__("$2")=total<D_8006C6A0[D_8006C708[tag->minimum]].threshold;
        __asm__("" : "=r"(within) : "0"(within));
        if(within && !func_8003BFC0(moby,tag->handle))
            tag->handle=func_8003BB10(moby,tag->minimum,4);
        }
    } else if(func_800359A4(&tag->timer,4)) {
        register int minimum __asm__("$4")=tag->minimum;
        register int maximum __asm__("$5")=tag->maximum;
        register int selector __asm__("$18")=minimum;
        if(minimum<maximum)selector=func_8003636C(minimum,maximum);
        if(tag->timerMinimum<tag->timerMaximum)tag->timer=func_8003636C(tag->timerMinimum,tag->timerMaximum);
        else tag->timer=tag->timerMinimum;
        func_8003BB10(moby,selector,0);
    }
    if(tag->attachment) {
        func_80036518(&spyro,tag->attachment,&index);
        func_8004F178(&moby->position,(Vector3D*)(tag->attachment->records+(index<<4)));
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_800874D4);

/* AI generated; not yet human reviewed. Derived from SCUS-94467 USA Rev 0
 * original controller instructions and its eleven-entry dispatch table.
 * Byte offsets, signed loads, word loads, shifts, and branch conditions
 * preserve the disc representation. Physical units, helper meanings, and
 * caller cadence remain unresolved; this routine describes one invocation.
 * Empty compiler constraints preserve original registers and scheduling;
 * they emit no instructions. Linked instructions and owned table/padding
 * must match every original copy before this source is accepted.
 */
extern unsigned char Controller821F8AngleTable[] __asm__("D_80065398");
extern unsigned char Controller821F8InitialTable[] __asm__("D_80066BDC");
#define Controller821F8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller821F8CDLoadTime(void) __asm__("CDLoadTime");
int Controller821F8func_8002803C(int,int,void*,int,void*,int,int) __asm__("func_8002803C");
int Controller821F8func_80028154(int) __asm__("func_80028154");
int Controller821F8func_8002AF9C(void*,int,int) __asm__("func_8002AF9C");
int Controller821F8func_80034F40(void*,int) __asm__("func_80034F40");
int Controller821F8func_800359A4(void*,int) __asm__("func_800359A4");
int Controller821F8func_8003613C(int,int) __asm__("func_8003613C");
int Controller821F8func_80039974(int,int,int) __asm__("func_80039974");
int Controller821F8func_8003BABC(void*,int,int) __asm__("func_8003BABC");
int Controller821F8func_8003BE70(int) __asm__("func_8003BE70");
int Controller821F8func_8003BFC0(void*,int) __asm__("func_8003BFC0");
int Controller821F8func_8003C140(int,int) __asm__("func_8003C140");
int Controller821F8func_800492DC(void*,int) __asm__("func_800492DC");
int Controller821F8func_8004E880(int,int,int) __asm__("func_8004E880");
int Controller821F8func_8004F178(void*,void*) __asm__("func_8004F178");
int Controller821F8func_8004F264(int,int) __asm__("func_8004F264");
int Controller821F8func_8004F334(void*,void*) __asm__("func_8004F334");
int Controller821F8func_800527C4(void*,int) __asm__("func_800527C4");
int Controller821F8func_80055B18(void*) __asm__("func_80055B18");
int Controller821F8func_80055D24(void*,int) __asm__("func_80055D24");
int Controller821F8func_80055F14(void*,int,void*) __asm__("func_80055F14");
extern unsigned char Controller821F8D_80065398[] __asm__("D_80065398");
extern unsigned char Controller821F8D_800658A0[] __asm__("D_800658A0");
extern unsigned char Controller821F8D_80065920[] __asm__("D_80065920");
extern unsigned char Controller821F8D_80066BDC[] __asm__("D_80066BDC");
extern unsigned char Controller821F8D_80066BDD[] __asm__("D_80066BDD");
extern unsigned char Controller821F8D_80066BDE[] __asm__("D_80066BDE");
extern unsigned char Controller821F8D_80070300[] __asm__("D_80070300");
extern unsigned char Controller821F8D_80070328[] __asm__("D_80070328");
extern unsigned char Controller821F8D_800715BC[] __asm__("D_800715BC");
extern unsigned char Controller821F8D_800716AC[] __asm__("D_800716AC");
extern unsigned char Controller821F8func_80027F88[] __asm__("func_80027F88");
extern unsigned char Controller821F8func_80029CF8[] __asm__("func_80029CF8");
extern int Controller821F8D_8006C3EC __asm__("D_8006C3EC");
extern int Controller821F8D_8006C58C __asm__("D_8006C58C");
extern int Controller821F8D_8006C5C8 __asm__("D_8006C5C8");
extern int Controller821F8D_8006C5F4 __asm__("D_8006C5F4");
extern unsigned char Controller821F8D_8006C62C __asm__("D_8006C62C");
extern int Controller821F8D_8006C648 __asm__("D_8006C648");
extern int Controller821F8D_8006C660 __asm__("D_8006C660");
extern unsigned int Controller821F8D_8006C704 __asm__("D_8006C704");
extern int Controller821F8D_8006C770 __asm__("D_8006C770");
extern int Controller821F8D_8006C7A0 __asm__("D_8006C7A0");
extern int Controller821F8D_8006C7A8 __asm__("D_8006C7A8");
extern unsigned char Controller821F8D_8006C7B4 __asm__("D_8006C7B4");
extern int Controller821F8D_8006C7D0 __asm__("D_8006C7D0");
extern int Controller821F8D_8006E48C __asm__("D_8006E48C");
extern int Controller821F8D_8006E49C __asm__("D_8006E49C");
extern int Controller821F8D_8006E53C __asm__("D_8006E53C");
extern unsigned int *Controller821F8D_8006C5B0 __asm__("D_8006C5B0");
extern void* (*Controller821F8SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Controller821F8SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
extern int (*Controller821F8SpawnFragments)(int,int,void*,void*,int,int) __asm__("SpawnFragments");
void func_level_50_80088570(void *input) {
    register unsigned char *owner __asm__("$17")=input;
    struct {int vector[4];short rect[4];} frame;
    short temp_a0_2;
    register int temp_a1_2 __asm__("$5");
    short temp_v0_2;
    register int temp_v0_3 __asm__("$2");
    short temp_v0_7;
    short temp_v0_8;
    short temp_v1_2;
    register int var_a0 __asm__("$4");
    int temp_a0_5;
    register int temp_t0 __asm__("$8");
    register int temp_v0 __asm__("$2");
    int temp_v0_10;
    int nextTableIndex;
    register int temp_v1_15 __asm__("$3");
    int temp_v1_6;
    register int var_a1 __asm__("$5");
    register int var_a2 __asm__("$6");
    register int var_a3 __asm__("$7");
    register int distance __asm__("$19");
    register int scanEnabled __asm__("$2");
    register int heightOffset __asm__("$2");
    register void *finishOwner __asm__("$4");
    register int verticalDistance __asm__("$20");
    register int sharedTailEnabled __asm__("$21");
    int var_v0;
    register int var_v0_3 __asm__("$2");
    int var_v1;
    int var_v1_2;
    int var_v1_3;
    register int var_v1_4 __asm__("$3");
    register int var_a2_2 __asm__("$6");
    unsigned short temp_v1_3;
    unsigned char *temp_v1_4;
    register int temp_a0_12 __asm__("$4");
    register int temp_a0_3 __asm__("$4");
    unsigned char temp_a1;
    register int temp_v1 __asm__("$3");
    unsigned char temp_v1_11;
    unsigned char temp_v1_13;
    unsigned char temp_v1_5;
    unsigned char temp_v1_7;
    unsigned char temp_v1_9;
    register int var_a0_2 __asm__("$4");
    register int var_v0_2 __asm__("$2");
    register void *temp_a0 __asm__("$4");
    void *temp_a0_10;
    void *temp_a0_11;
    void *temp_a0_4;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a0_8;
    void *temp_a0_9;
    register unsigned char *tag __asm__("$16");
    void *childForAngle;
    void *spawnedChild;
    void *spawnedRecord;
    void *temp_v1_10;
    void *temp_v1_12;
    void *temp_v1_14;
    void *temp_v1_8;

    tag = Controller821F8Field(owner, void **, 0);
    distance = Controller821F8func_8004F334(owner + 0xC, Controller821F8D_80070328);
    {register int heightOffset __asm__("$3")=Controller821F8Field(owner,short*,0x38);
     temp_v0=Controller821F8Field(owner,int*,20);
     __asm__("" : "=r"(heightOffset),"=r"(temp_v0) : "0"(heightOffset),"1"(temp_v0));
     temp_v0-=heightOffset;
     __asm__("" : "=r"(temp_v0) : "0"(temp_v0) : "$3");
     heightOffset=Controller821F8Field(Controller821F8D_80070328,int*,8);
     {register int base __asm__("$4")=Controller821F8Field(Controller821F8D_80070328,int*,0x44);
      __asm__("" : "=r"(heightOffset),"=r"(base) : "0"(heightOffset),"1"(base));
      temp_v0-=heightOffset;temp_v0+=base;}}
    temp_a0 = Controller821F8Field(tag, void **, 8);
    verticalDistance = temp_v0;
    if (temp_v0 < 0) {
        verticalDistance = -verticalDistance;
    }
    sharedTailEnabled=0;
    if (temp_a0 != 0) {
        Controller821F8func_80055F14(temp_a0, 0, &frame.vector);
    }
    __asm__ volatile("" : "=r"(sharedTailEnabled) : "0"(sharedTailEnabled));
    temp_v1 = Controller821F8Field(owner, unsigned char *, 0x48);
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        if (Controller821F8Field(tag, short *, 6) < 0) {
            Controller821F8Field(tag, short *, 6) = (short) Controller821F8Field(owner, unsigned char *, 0x46);
        }
        temp_v1_2 = Controller821F8Field(tag, short *, 0);
        if (temp_v1_2 >= 0) {
            if ((((int) Controller821F8D_8006C7B4 >> temp_v1_2) & 1) || (((int) *(Controller821F8D_80070300 + Controller821F8D_8006C58C) >> temp_v1_2) & 1)) {
                Controller821F8func_80055B18(owner);
            } else if (Controller821F8func_8004F334(owner + 0xC, Controller821F8D_80070328) < 0x2000) {
                var_v0 = ((Controller821F8Field(owner, int *, 0x14) - Controller821F8Field(owner, short *, 0x38)) - Controller821F8Field(Controller821F8D_80070328, int *, 8)) + Controller821F8Field(Controller821F8D_80070328, int *, 0x44);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < 0x800) && ((Controller821F8func_8004F264(Controller821F8Field(owner, unsigned char *, 0x46), Controller821F8func_8004E880(Controller821F8Field(Controller821F8D_80070328, int *, 0) - Controller821F8Field(owner, int *, 0xC), Controller821F8Field(Controller821F8D_80070328, int *, 4) - Controller821F8Field(owner, int *, 0x10), 0)) < 0x20) || (Controller821F8Field(tag, short *, 0x16) != 0))) {
                    Controller821F8Field(owner, unsigned char *, 0x48) = 7U;
                    Controller821F8Field(tag, unsigned short *, 0xC) = 0U;
                }
            }
        }
    default:                                        /* switch 1 */
        goto sharedTail;
    case 7:                                         /* switch 1 */
        if ((distance >= 0x2401) || (verticalDistance >= 0x901)) {
            Controller821F8Field(owner, unsigned char *, 0x48) = 0U;
        } else if ((distance < 0x800) && (verticalDistance < 0x200) && ((Controller821F8Field(Controller821F8D_80070328, int *, 0xB8) == 0) || ((unsigned int) (Controller821F8Field(Controller821F8D_80070328, int *, 0x50) - 0xB) < 2U)) && ((Controller821F8func_8004F264(Controller821F8Field(owner, unsigned char *, 0x46), Controller821F8func_8004E880(Controller821F8Field(Controller821F8D_80070328, int *, 0) - Controller821F8Field(owner, int *, 0xC), Controller821F8Field(Controller821F8D_80070328, int *, 4) - Controller821F8Field(owner, int *, 0x10), 0)) < 0x20) || (Controller821F8Field(tag, short *, 0x16) != 0))) {
            Controller821F8Field(owner, unsigned char *, 0x48) = 1U;
        }
        goto sharedTail;
    case 1:                                         /* switch 1 */
        Controller821F8func_800527C4(owner, Controller821F8Field(tag, short *, 0));
        /* fallthrough */
    case 2:                                         /* switch 1 */
        if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) == 0) {
            temp_v0_2 = Controller821F8func_8003BABC(owner, 0, 4);
            Controller821F8Field(tag, short *, 0x14) = temp_v0_2;
            if (temp_v0_2 >= 0) {
                Controller821F8func_8003C140(temp_v0_2, 1);
            }
        }
        temp_a0_2 = Controller821F8Field(tag, short *, 0);
        temp_v1_4 = Controller821F8D_8006C58C + Controller821F8D_80070300;
        temp_a1 = *temp_v1_4;
        if (!(((int) temp_a1 >> temp_a0_2) & 1)) {
            *temp_v1_4 = temp_a1 | (1 << temp_a0_2);
            Controller821F8D_8006C660 += 1;
        } else {
            Controller821F8D_8006C7D0 = 1;
        }
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(owner + 0xC,var_a1);
        Controller821F8Field(tag, short *, 2) = 0xB4;
        Controller821F8D_8006C3EC = 0;
        Controller821F8Field(owner, unsigned char *, 0x48) = 3U;
        if (Controller821F8Field(((Controller821F8Field(tag, short *, 0) * 0xC) + Controller821F8D_8006C7A0), unsigned char *, 7) == 0xFF) {
            Controller821F8Field(tag, short *, 4) = -1;
            Controller821F8Field(owner, unsigned char *, 0x49) = 4U;
        } else {
            Controller821F8Field(tag, short *, 4) = Controller821F8func_8002803C(0x36, -1, Controller821F8func_80027F88, 0, Controller821F8func_80029CF8, *(int*)((Controller821F8Field(tag, short *, 0) * 0xC) + Controller821F8D_8006C7A0), 0);
            Controller821F8D_8006E49C = 1;
            Controller821F8Field(owner, unsigned char *, 0x49) = 0U;
        }
        goto sharedTail;
    case 3:                                         /* switch 1 */
        if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) == 0) {
            temp_v0_3 = Controller821F8func_8003BABC(owner, 0, 4);
            Controller821F8Field(tag, short *, 0x14) = temp_v0_3;
            var_a0 = (temp_v0_3<<16)>>16;
            if (var_a0 >= 0) {
                var_a1 = Controller821F8D_8006C3EC << 0xC;
                goto updateOwnerHeight;
            }
        } else {
            var_a1 = Controller821F8D_8006C3EC;
            {register int condition __asm__("$2")=var_a1<65;
             __asm__("" : "=r"(condition) : "0"(condition));
             var_a1<<=12;
            if (condition) {
                var_a0 = Controller821F8Field(tag, short *, 0x14);
updateOwnerHeight:
                Controller821F8func_8003C140(var_a0, (var_a1 >> 6) | 1);
            }
            }
        }
        {register int selector __asm__("$4")=1;
         register int kind __asm__("$5")=12;
         register void *particleOwner __asm__("$6")=owner;
         register int mode __asm__("$7")=5;
         register int height __asm__("$2");register int alpha __asm__("$3");
         register int (*particle)(int,int,void*,int) __asm__("$8");
         __asm__("" : "=r"(selector),"=r"(kind),"=r"(particleOwner),"=r"(mode) : "0"(selector),"1"(kind),"2"(particleOwner),"3"(mode) : "$2","$3","$8");
         height=Controller821F8Field(owner,int*,20);alpha=Controller821F8Field(owner,unsigned char*,79);
         __asm__("" : "=r"(height),"=r"(alpha) : "0"(height),"1"(alpha) : "$8");
         particle=Controller821F8SpawnParticle;
         __asm__("" : "=r"(particle),"=r"(height) : "0"(particle),"1"(height));
         height+=128;height-=alpha;Controller821F8Field(owner,int*,20)=height;
         particle(selector,kind,particleOwner,mode);
         height=Controller821F8Field(owner,int*,20);alpha=Controller821F8Field(owner,unsigned char*,79);
         __asm__ volatile("" : "=r"(height),"=r"(alpha) : "0"(height),"1"(alpha) : "$4","memory");
         temp_a0_3=Controller821F8Field(owner,unsigned char*,79);
         __asm__("" : "=r"(temp_a0_3),"=r"(height),"=r"(alpha) : "0"(temp_a0_3),"1"(height),"2"(alpha));
         height-=128;height+=alpha;Controller821F8Field(owner,int*,20)=height;}
        if ((temp_a0_3 != 0) && ((unsigned int) owner >= (unsigned int) Controller821F8D_8006C704)) {
            Controller821F8Field(owner, unsigned char *, 0x4F) = (unsigned char) *(int*)(Controller821F8D_80065398 + 0xA4 + (Controller821F8D_8006C3EC * 0xC));
        }
        Controller821F8Field(owner, unsigned char *, 0x44) = (unsigned char) *(int*)(Controller821F8AngleTable + 0x9C + (Controller821F8D_8006C3EC * 0xC));
        Controller821F8Field(owner, unsigned char *, 0x45) = (unsigned char) *(int*)(Controller821F8D_80065398 + 0xA0 + (Controller821F8D_8006C3EC * 0xC));
        nextTableIndex = Controller821F8D_8006C3EC + 1;
        Controller821F8D_8006C3EC = nextTableIndex;
        if (nextTableIndex >= 0x40) {
            Controller821F8D_8006C3EC = 0x2F;
        }
        temp_v1_5 = Controller821F8Field(owner, unsigned char *, 0x49);
        switch (temp_v1_5) {
        case 0:
            if(Controller821F8D_8006E48C!=0) goto loadingDone;
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            var_a1=0;
            __asm__("" : "=r"(var_a1) : "0"(var_a1) : "$4");
            var_a0=Controller821F8Field(tag,short*,0);
            Controller821F8func_80039974(var_a0,var_a1,0x3000);
            var_v0_2=1;goto storeLoadingState;
        case 1:
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            DrawSync(0);
            frame.rect[0]=0x380;frame.rect[1]=0x100;frame.rect[2]=0x40;frame.rect[3]=0x60;
            LoadImage((RECT*)&frame.rect[0],Controller821F8D_8006C5B0);
            var_v0_2=2;goto storeLoadingState;
        case 2:
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            var_a1=0x3000;
            __asm__("" : "=r"(var_a1) : "0"(var_a1) : "$4");
            var_a0=Controller821F8Field(tag,short*,0);
            Controller821F8func_80039974(var_a0,var_a1,0);
            var_v0_2=3;goto storeLoadingState;
        case 3:
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            var_a1=500;
            __asm__("" : "=r"(var_a1) : "0"(var_a1) : "$4");
            Controller821F8func_8002AF9C(Controller821F8D_8006C5B0,var_a1,0x80400000);
            var_v0_2=4;
storeLoadingState:
            Controller821F8Field(owner,unsigned char*,73)=var_v0_2;
loadingBusy:
        default:
loadingDone:
            break;
        }
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(owner + 0xC,var_a1);
        if ((Controller821F8func_800359A4(tag + 2, 2) != 0) && (Controller821F8Field(owner, unsigned char *, 0x49) == 4)) {
            if (Controller821F8Field(((Controller821F8Field(tag, short *, 0) * 0xC) + Controller821F8D_8006C7A0), unsigned char *, 7) == 0xFF) {
                Controller821F8Field(tag, void **, 8) = 0;
            } else {
                Controller821F8Field(tag, void **, 8) = Controller821F8SpawnMoby(0x1F4, owner);
            }
            if (Controller821F8Field(tag, void **, 8) != 0) {
                Controller821F8SpawnFragments(0xD, 0x1F5, owner, Controller821F8D_80065398, 0, 0x100);
                childForAngle = Controller821F8Field(tag, void **, 8);
                Controller821F8Field(Controller821F8Field(tag, void **, 8), signed char *, 0x46) = Controller821F8func_8004E880(Controller821F8Field(Controller821F8D_80070328, int *, 0) - Controller821F8Field(childForAngle, int *, 0xC), Controller821F8Field(Controller821F8D_80070328, int *, 4) - Controller821F8Field(childForAngle, int *, 0x10), 0);
                Controller821F8D_8006E49C = 0;
                Controller821F8Field(owner, unsigned char *, 0x48) = 4U;
                Controller821F8D_8006C3EC = 0;
                Controller821F8Field(owner, signed char *, 0x4C) = 0;
                Controller821F8Field(owner, signed char *, 0x4D) = 0;
                Controller821F8func_80055D24(Controller821F8Field(tag, void **, 8), 4);
                if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) != 0) {
                    Controller821F8func_8003BE70(Controller821F8Field(tag, short *, 0x14));
                }
                Controller821F8Field(tag, short *, 0x14) = -1;
                Controller821F8func_8003BABC(owner, 1, 4);
            } else {
                goto enterStateFive;
            }
        }
        goto sharedTail;
    case 4:                                         /* switch 1 */
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(&frame.vector,var_a1);
        if (({register unsigned char *child __asm__("$2")=Controller821F8Field(tag,void**,8);__asm__("" : "=r"(child) : "0"(child) : "$4");Controller821F8Field(child,unsigned char*,66)&2;}) || (Controller821F8D_8006E53C & 0x800)) {
            temp_a0_4 = Controller821F8Field(tag, void **, 8);
            Controller821F8Field(tag, short *, 2) = -0x200;
            if (Controller821F8Field(temp_a0_4, unsigned char *, 0x42) & 2) {
                Controller821F8func_80034F40(temp_a0_4, 1);
            }
            Controller821F8func_8004F178(owner + 0xC, &frame.vector);
            heightOffset=Controller821F8Field(tag,short*,2);
            __asm__("" : "=r"(heightOffset) : "0"(heightOffset) : "$3");
            {register unsigned char *child __asm__("$3")=Controller821F8Field(tag,void**,8);
             __asm__("" : "=r"(child),"=r"(heightOffset) : "0"(child),"1"(heightOffset) : "$4");
             temp_a0_5=Controller821F8Field(owner,int*,20);
             temp_v1_6=Controller821F8Field(child,int*,20);}
            if ((temp_a0_5 + heightOffset) < temp_v1_6) {
                Controller821F8Field(tag, short *, 2) = (short) (temp_v1_6 - temp_a0_5);
            }
            spawnedChild = Controller821F8SpawnMoby(0x171, owner);
            Controller821F8Field(tag, void **, 0x10) = spawnedChild;
            if (spawnedChild != 0) {
                Controller821F8Field(spawnedChild, int *, 0x14) = (int) (Controller821F8Field(spawnedChild, int *, 0x14) + Controller821F8Field(tag, short *, 2));
                Controller821F8Field(Controller821F8Field(tag, void **, 0x10), unsigned char *, 0x4F) = 0xFFU;
            }
            Controller821F8func_8003BABC(owner, 2, 0);
            Controller821F8Field(owner, unsigned char *, 0x48) = 8U;
        }
        goto sharedTail;
    case 9:                                         /* switch 1 */
        if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) != 0) {
            Controller821F8func_8003BE70(Controller821F8Field(tag, short *, 0x14));
        }
        Controller821F8Field(tag, short *, 0x14) = -1;
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(owner + 0xC,var_a1);
        Controller821F8Field(owner, int *, 0x54) = (int) (((Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2)) & 0xFFFFFF) | 0x80000000);
        temp_a0_6 = Controller821F8Field(tag, void **, 0x10);
        if (temp_a0_6 != 0) {
            Controller821F8Field(temp_a0_6, int *, 0x14) = (int) (Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2));
        }
        temp_v0_7 = (unsigned short) Controller821F8Field(tag, short *, 2) + (Controller821F8D_8006C648 << 5);
        Controller821F8Field(tag, short *, 2) = temp_v0_7;
        if (temp_v0_7 >= 0x185) {
            temp_a0_7 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_7 = Controller821F8Field(temp_a0_7, unsigned char *, 0x4F);
            if (temp_v1_7 < 0x7FU) {
                Controller821F8Field(temp_a0_7, unsigned char *, 0x4F) = (unsigned char) (temp_v1_7 + (Controller821F8D_8006C648 * 8));
            }
            temp_v1_8 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned char) Controller821F8Field(temp_v1_8, unsigned char *, 0x4F) >= 0x80U) {
                Controller821F8Field(temp_v1_8, unsigned char *, 0x4F) = 0x7FU;
            }
        } else {
            temp_a0_8 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_9 = Controller821F8Field(temp_a0_8, unsigned char *, 0x4F);
            if (temp_v1_9 >= 0x21U) {
                Controller821F8Field(temp_a0_8, unsigned char *, 0x4F) = (unsigned char) (temp_v1_9 - (Controller821F8D_8006C648 * 8));
            }
            temp_v1_10 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned int) (Controller821F8Field(temp_v1_10, unsigned char *, 0x4F) - 0x20) >= 0x60U) {
                Controller821F8Field(temp_v1_10, unsigned char *, 0x4F) = 0x20U;
            }
        }
        {register int below __asm__("$2")=Controller821F8Field(tag,short*,2)<769;
         __asm__("" : "=r"(below) : "0"(below));
         if(below) goto sharedTail;
         finishOwner=Controller821F8Field(tag,void**,16);
         goto releaseSecondaryChild;}
    case 8:                                         /* switch 1 */
        if (Controller821F8D_8006C770 != 0) {
            Controller821F8func_80034F40(Controller821F8Field(tag, void **, 8), 1);
        }
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(&frame.vector,var_a1);
        Controller821F8func_8004F178(owner + 0xC, &frame.vector);
        Controller821F8Field(Controller821F8Field(tag, void **, 8), int *, 0x54) = (int) (((Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2)) & 0xFFFFFF) | 0x80000000);
        temp_a0_9 = Controller821F8Field(tag, void **, 0x10);
        if (temp_a0_9 != 0) {
            Controller821F8Field(temp_a0_9, int *, 0x14) = (int) (Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2));
        }
        temp_v0_8 = (unsigned short) Controller821F8Field(tag, short *, 2) + (Controller821F8D_8006C648 << 5);
        Controller821F8Field(tag, short *, 2) = temp_v0_8;
        if (temp_v0_8 >= 0x185) {
            temp_a0_10 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_11 = Controller821F8Field(temp_a0_10, unsigned char *, 0x4F);
            if (temp_v1_11 < 0x7FU) {
                Controller821F8Field(temp_a0_10, unsigned char *, 0x4F) = (unsigned char) (temp_v1_11 + (Controller821F8D_8006C648 * 8));
            }
            temp_v1_12 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned char) Controller821F8Field(temp_v1_12, unsigned char *, 0x4F) >= 0x80U) {
                Controller821F8Field(temp_v1_12, unsigned char *, 0x4F) = 0x7FU;
            }
        } else {
            temp_a0_11 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_13 = Controller821F8Field(temp_a0_11, unsigned char *, 0x4F);
            if (temp_v1_13 >= 0x21U) {
                Controller821F8Field(temp_a0_11, unsigned char *, 0x4F) = (unsigned char) (temp_v1_13 - (Controller821F8D_8006C648 * 8));
            }
            temp_v1_14 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned int) (Controller821F8Field(temp_v1_14, unsigned char *, 0x4F) - 0x20) >= 0x60U) {
                Controller821F8Field(temp_v1_14, unsigned char *, 0x4F) = 0x20U;
            }
        }
        if (Controller821F8Field(tag, short *, 2) >= 0x301) {
            Controller821F8func_80055B18(Controller821F8Field(tag, void **, 8));
            finishOwner=Controller821F8Field(tag,void**,16);
            Controller821F8Field(tag, void **, 8) = 0;
releaseSecondaryChild:
            if(finishOwner!=0) {
                Controller821F8func_80055B18(finishOwner);
            }
enterStateFive:
            Controller821F8Field(owner,unsigned char*,72)=5;
        }
        goto sharedTail;
    case 5:                                         /* switch 1 */
        Controller821F8Field(Controller821F8D_80070328, int *, 0x20C) = (int) (Controller821F8Field(Controller821F8D_80070328, int *, 0x20C) | 0x10000002);
        spawnedRecord = Controller821F8SpawnMoby(0x110, owner);
        if (spawnedRecord != 0) {
            Controller821F8Field(spawnedRecord, signed char *, 0x46) = (signed char) (unsigned short) Controller821F8Field(tag, short *, 6);
            Controller821F8Field(Controller821F8Field(spawnedRecord, void **, 0), signed char *, 4) = (signed char) (unsigned short) Controller821F8Field(tag, short *, 6);
        }
        Controller821F8func_80028154(Controller821F8Field(tag, short *, 4));
        {register int index __asm__("$2")=Controller821F8Field(tag,short*,0);
         register int level __asm__("$4")=Controller821F8D_8006C58C;
         register int offset __asm__("$3");
         __asm__("" : "=r"(index),"=r"(level) : "0"(index),"1"(level) : "$3");
         offset=(index<<1)+index;
         __asm__("" : "=r"(offset) : "0"(offset) : "$2");
         index=((level<<3)+level)<<1;offset+=index;
         offset=*(Controller821F8InitialTable+offset);
         __asm__("" : "=r"(offset) : "0"(offset) : "$2");
         scanEnabled=Controller821F8D_8006C5C8;
         Controller821F8D_8006C5F4=0;
         __asm__("" : "=r"(scanEnabled),"=r"(offset) : "0"(scanEnabled),"1"(offset));
         temp_t0=offset&0xF0;}
        if (scanEnabled != 0) {
            register unsigned char *scanOutput __asm__("$9");
            register int expectedKind __asm__("$10");
            var_a2=0;expectedKind=16;
            __asm__("" : "=r"(var_a2),"=r"(expectedKind) : "0"(var_a2),"1"(expectedKind) : "$9","$7");
            scanOutput=Controller821F8D_800716AC;
            __asm__("" : "=r"(scanOutput) : "0"(scanOutput) : "$7");
            var_a3=0;
            do {
                register int value __asm__("$2")=Controller821F8Field(tag,short*,0);
                register int selectedKind __asm__("$3");
                register int level __asm__("$5");
                __asm__("" : "=r"(value) : "0"(value));
                if(var_a2==value) goto advanceScan;
                level=Controller821F8D_8006C58C;
                value=((level<<3)+level)<<1;
                __asm__("" : "=r"(value) : "0"(value));
                value=var_a3+value;
                temp_a0_12=*(Controller821F8D_80066BDC+value);
                __asm__("" : "=r"(temp_a0_12) : "0"(temp_a0_12) : "$3");
                selectedKind=Controller821F8D_8006C5C8;
                value=temp_a0_12&15;
                if(value!=selectedKind) goto advanceScan;
                value=temp_a0_12&240;
                if(value!=expectedKind) goto advanceScan;
                value=((level<<1)+level)<<1;
                value+=(int)scanOutput;
                __asm__("" : "=r"(value) : "0"(value));
                value+=var_a2;
                *(unsigned char*)value=0;
advanceScan:
                var_a2+=1;var_a3+=3;
            } while(var_a2<6);
        }
        {register unsigned char *stateEntry __asm__("$2")=Controller821F8D_800715BC;
         register int level __asm__("$7");
         register int value __asm__("$2");
         __asm__("" : "=r"(stateEntry) : "0"(stateEntry) : "$7");
         level=Controller821F8D_8006C58C;
         __asm__("" : "=r"(level) : "0"(level) : "$5");
         temp_a1_2=Controller821F8Field(tag,short*,0);
         __asm__("" : "=r"(temp_a1_2) : "0"(temp_a1_2) : "$3");
         temp_v1_15=((level<<1)+level)<<1;
         stateEntry=(unsigned char*)((int)temp_v1_15+(int)stateEntry);stateEntry+=temp_a1_2;
         value=*stateEntry;
        if(value==0) {
            var_a2_2=2;
            switch(temp_t0) {
            default:goto classificationReady;
            case 16:
            {register unsigned char *entry __asm__("$4")=Controller821F8D_800716AC;
             __asm__("" : "=r"(entry) : "0"(entry));
             entry=(unsigned char*)((int)temp_v1_15+(int)entry);entry+=temp_a1_2;
             __asm__("" : "=r"(entry) : "0"(entry) : "$3");
             var_v1_4=(temp_a1_2<<1)+temp_a1_2;
             value=level<<3;value+=level;value<<=1;var_v1_4+=value;
             var_a0_2=*entry;
             value=*(Controller821F8D_80066BDD+var_v1_4);
             __asm__ volatile("" : "=r"(value),"=r"(var_a0_2) : "0"(value),"1"(var_a0_2) : "$7");
             value=var_a0_2<value;
             if(!value) goto classifyUpper;
             __asm__ volatile("" : "=r"(value) : "0"(value) : "$7");
             var_a2_2=1;goto classificationReady;}
            case 32:
            value=level<<3;
            {register unsigned char *entry __asm__("$4")=Controller821F8D_800716AC;
             __asm__("" : "=r"(entry) : "0"(entry));
             entry=(unsigned char*)((int)temp_v1_15+(int)entry);entry+=temp_a1_2;
             __asm__("" : "=r"(entry) : "0"(entry) : "$3");
             var_v1_4=(temp_a1_2<<1)+temp_a1_2;
             value+=level;value<<=1;var_v1_4+=value;
             var_a0_2=*entry;
             value=*(Controller821F8D_80066BDD+var_v1_4);
             __asm__ volatile("" : "=r"(value),"=r"(var_a0_2) : "0"(value),"1"(var_a0_2) : "$5");
             value=var_a0_2<value;
             if(!value) goto classifyUpper;
             __asm__ volatile("" : "=r"(value) : "0"(value) : "$5");
             var_a2_2=1;goto classificationReady;}
            }
classifyUpper:
            value=*(Controller821F8D_80066BDE+var_v1_4);
            __asm__ volatile("" : "=r"(value),"=r"(var_a0_2) : "0"(value),"1"(var_a0_2));
            var_a2_2=3;
            if(value<var_a0_2) goto classificationReady;
            var_a2_2=2;
classificationReady:
            if (temp_t0 != 0x30) {
                {register int level __asm__("$3")=Controller821F8D_8006C58C;
                 register unsigned char *base __asm__("$4");
                 register int result __asm__("$2");
                 __asm__("" : "=r"(level) : "0"(level) : "$4");
                 base=Controller821F8D_800715BC;
                 __asm__("" : "=r"(level),"=r"(base) : "0"(level),"1"(base));
                 result=((level<<1)+level)<<1;
                 __asm__("" : "=r"(result) : "0"(result) : "$3");
                 level=Controller821F8Field(tag,short*,0);
                 result+=(int)base;result+=level;*(unsigned char*)result=var_a2_2;}
                if(var_a2_2==1) {
                    value=Controller821F8D_8006C7A8-10;
                    Controller821F8D_8006C7A8=value;
                    value=value<-40;
                    if(!value) goto resetClassificationRecord;
                    value=-40;goto storeClassificationCounter;
                } else if(var_a2_2==2) {
                    register int current __asm__("$3")=Controller821F8D_8006C7A8;
                    __asm__("" : "=r"(current) : "0"(current));
                    if(current>0) {
                        value=Controller821F8Field(tag,short*,0);
                        if(value!=0) {
                            value=current-5;Controller821F8D_8006C7A8=value;
                            __asm__ volatile("" ::: "memory");
                            current=Controller821F8D_8006C7A8;
                        }
                    }
                    if(current>=0) goto resetClassificationRecord;
                    value=Controller821F8Field(tag,short*,0);
                    if(value==0) goto resetClassificationRecord;
                    value=current+5;
storeClassificationCounter:
                    Controller821F8D_8006C7A8=value;
                }
resetClassificationRecord:
                {register int level __asm__("$3")=Controller821F8D_8006C58C;
                 register unsigned char *base __asm__("$4");
                 register int result __asm__("$2");
                 __asm__("" : "=r"(level) : "0"(level) : "$4");
                 base=Controller821F8D_800716AC;
                 __asm__("" : "=r"(level),"=r"(base) : "0"(level),"1"(base));
                 result=((level<<1)+level)<<1;
                 __asm__("" : "=r"(result) : "0"(result) : "$3");
                 level=Controller821F8Field(tag,short*,0);
                 result+=(int)base;result+=level;*(unsigned char*)result=0;}
            }
        }
        }
        Controller821F8D_8006C7B4 |= 1 << Controller821F8Field(tag, short *, 0);
        Controller821F8D_8006C62C |= 1 << Controller821F8Field(tag, short *, 0);
        Controller821F8Field(owner, unsigned char *, 0x48) = 0xAU;
        return;
    case 10:                                        /* switch 1 */
        if (Controller821F8CDLoadTime() == 0) {
            Controller821F8D_8006E49C = 0;
            Controller821F8func_80055B18(owner);
            return;
        }
        break;
    }
    return;
sharedTail:
        if (sharedTailEnabled != 0) {
            if ((distance >= 0x2401) || !({register int condition __asm__("$2")=verticalDistance<2305;__asm__("" : "=r"(condition) : "0"(condition));condition;})) {
                if (Controller821F8Field(owner, unsigned short *, 0x44) != 0) {
                    var_v1 = Controller821F8func_8003613C(Controller821F8Field(owner, unsigned char *, 0x44), 0);
                    if (var_v1 < 0) {
                        var_v1 -= 1;
                    } else if (var_v1 > 0) {
                        var_v1 += 1;
                    }
                    Controller821F8Field(owner, unsigned char *, 0x44) = (unsigned char) (Controller821F8Field(owner, unsigned char *, 0x44) + (var_v1 >> 1));
                    return;
                }
            } else {
                if (distance < 0xC00) {
                    distance = 0xC00;
                }
                temp_v1_3 = Controller821F8Field(tag, unsigned short *, 0xC) + ((int) (0x2400 - distance) >> 6);
                Controller821F8Field(tag, unsigned short *, 0xC) = temp_v1_3;
                var_v1_2 = Controller821F8func_8003613C(Controller821F8Field(owner, unsigned char *, 0x44), (int) (*(unsigned short*)(Controller821F8D_800658A0 + (temp_v1_3 & 0x1FE)) << 0x10) >> 0x18);
                if (var_v1_2 < 0) {
                    var_v1_2 -= 1;
                } else if (var_v1_2 > 0) {
                    var_v1_2 += 1;
                }
                Controller821F8Field(owner, unsigned char *, 0x44) = (unsigned char) (Controller821F8Field(owner, unsigned char *, 0x44) + (var_v1_2 >> 1));
                var_v1_3 = Controller821F8func_8003613C(Controller821F8Field(owner, unsigned char *, 0x45), (int) (*(unsigned short*)(Controller821F8D_80065920 + (Controller821F8Field(tag, unsigned short *, 0xC) & 0x1FE)) << 0x10) >> 0x18);
                if (var_v1_3 < 0) {
                    var_v1_3 -= 1;
                } else if (var_v1_3 > 0) {
                    var_v1_3 += 1;
                }
                Controller821F8Field(owner, unsigned char *, 0x45) = (unsigned char) (Controller821F8Field(owner, unsigned char *, 0x45) + (var_v1_3 >> 1));
            }
        } else {
            return;
        }
}


#undef Controller821F8Field


void func_level_50_800896C4(Moby* moby) {
    func_80039714(moby);
}

/* SCUS-94467 Rev0 representative 8008336C..8008356C, 128 words.
 * Table halfwords are interpreted as signed via the packed arithmetic shift.
 * Preserve native signed /5 and /3 and their short-result truncation, raw
 * byte heading wrap, tag offsets 6/7, and fresh parent/table reads.
 * Empty constraints emit no instructions: they preserve GCC2.7.2 lifetimes
 * and keep the full +128 heading value observable before its byte store.
 * Physical units, table producers and caller cadence remain unresolved.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct { unsigned char reserved00[6]; signed char offset6; unsigned char count7; } DecodedOrbitParentTag;
typedef struct { Moby* parent; } DecodedOrbitTag;
extern unsigned short DecodedOrbitCos[] __asm__("D_80065920");
extern unsigned short DecodedOrbitSin[] __asm__("D_800658A0");
extern int D_8006C644;
extern unsigned char D_80067555[], D_80067556[];
void func_80055B18(Moby*);
static __inline__ short DecodedOrbitQuotientFive(int packed) { return (packed >> 16) / 5; }
static __inline__ short DecodedOrbitQuotientThree(int packed) { return (packed >> 16) / 3; }
void func_level_50_800896E4(Moby* argument) {
    register Moby* moby __asm__("$10") = argument;
    int reservedStack[6];
    register DecodedOrbitTag* tag __asm__("$14") = moby->mobyTag;
    register Moby* parent __asm__("$11") = tag->parent;
    DecodedOrbitParentTag* parentTag = parent->mobyTag;
    register unsigned int angleByteOffset __asm__("$5");
    register int step __asm__("$5");
    register int phase __asm__("$7");
    register int cosine __asm__("$4");
    register int sine __asm__("$5");
    register int phaseCosine __asm__("$3");
    register int phaseSine __asm__("$3");
    register int parentY __asm__("$6");
    if (parentTag->count7 == 0) {
        func_80055B18(moby);
        return;
    }
    phase = parent->angle.yaw;
    angleByteOffset = phase * 2;
    __asm__("" : "=r"(angleByteOffset) : "0"(angleByteOffset), "r"(phase));
    cosine = (int)(*(unsigned short*)((char*)DecodedOrbitCos + angleByteOffset) << 16);
    phase += D_80067555[moby->substate * 4];
    phaseCosine = (int)((DecodedOrbitCos[phase & 255]) << 16);
    sine = (int)(*(unsigned short*)((char*)DecodedOrbitSin + angleByteOffset) << 16);
    /* Retain the original quotient truncation before combining coordinates. */
    {
        register int basePart __asm__("$2") = DecodedOrbitQuotientFive(cosine);
        register int phasePart __asm__("$3") = DecodedOrbitQuotientThree(phaseCosine);
        register int positionX __asm__("$4") = parent->position.x - basePart;
        __asm__("" : "=r"(positionX), "=r"(phasePart) : "0"(positionX), "1"(phasePart) : "memory");
        parentY = *(volatile int*)&parent->position.y;
        __asm__("" : "=r"(parentY) : "0"(parentY));
        positionX += phasePart;
        __asm__("" : : "r"(positionX), "r"(parentY));
        moby->position.x = positionX;
    }
    phaseSine = (int)((DecodedOrbitSin[phase & 255]) << 16);
    {
        register int basePart __asm__("$2") = DecodedOrbitQuotientFive(sine);
        register int phasePart __asm__("$3") = DecodedOrbitQuotientThree(phaseSine);
        register int positionY __asm__("$6") = parentY - basePart;
        step = D_8006C644;
        positionY += phasePart;
        __asm__("" : "=r"(positionY) : "0"(positionY), "r"(step));
        moby->position.y = positionY;
    }
    moby->position.z = tag->parent->position.z
        + ((DecodedOrbitParentTag*)tag->parent->mobyTag)->offset6 * 16
        + D_80067556[moby->substate * 4];
    {
        int sample = *(short*)((char*)D_80065920 + ((moby->substate + step) * 8 & 0x1F8));
        __asm__("" : "=r"(phase) : "0"(phase), "r"(sample));
        phase += 0x80;
        __asm__("" : : "r"(phase));
        moby->angle.yaw = phase + ((sample * 3) >> 9);
    }
    if (moby->animationState.id == 0)
        ((DecodedOrbitParentTag*)tag->parent->mobyTag)->count7--;
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_800898E4);

typedef struct { short timer, velocity; int selector; } DecodedVerticalTimer;
void func_level_50_8008A900(Moby* moby) {
    DecodedVerticalTimer* tag=moby->mobyTag;
    Vector3D velocity;
    if(moby->state==1) {
        velocity.x=0;velocity.y=0;velocity.z=0x1E;
        SpawnParticle(1,0xD,&moby->position,&velocity);
        func_80035DDC(moby,tag->selector,0,0,0);
        moby->position.z+=tag->velocity;
        tag->velocity-=4;
        if(tag->velocity>0x12C)tag->velocity=0x12C;
        if(func_800359A4(tag,2))goto remove;
    } else if(func_80039714(moby)) {
        func_80055D24(moby,4);
        func_800369B8(moby,0x18);
        SpawnParticle(0xA,0x46,&moby->position,(Vector3D*)8);
remove:
        func_80055B18(moby);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8008AA24);

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8008B434);

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 412-instruction actor callback and 23-word dispatch table.
 * Field offsets, signed/unsigned access widths, callback order and the
 * 136-byte stack frame are preserved. Empty compiler constraints emit no
 * opcodes; they preserve original register producers and store boundaries.
 * Vector units, helper contracts, caller cadence and synchronized runtime
 * semantics remain unresolved. Acceptance requires every linked original
 * word, owned table word and the full EXE/every-overlay hashes to match.
 */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Probe83264func_800359A4() __asm__("func_800359A4");
int Probe83264func_8004E880() __asm__("func_8004E880");
int Probe83264func_8004ED6C() __asm__("func_8004ED6C");
int Probe83264func_8004F178() __asm__("func_8004F178");
int Probe83264func_8004F194() __asm__("func_8004F194");
int Probe83264func_8004F334() __asm__("func_8004F334");
int Probe83264func_80050844() __asm__("func_80050844");
int Probe83264func_800509E8() __asm__("func_800509E8");
int Probe83264func_80055B18() __asm__("func_80055B18");
int Probe83264func_80055D24() __asm__("func_80055D24");
extern unsigned char Probe83264D_800658A0[] __asm__("D_800658A0");
extern unsigned char Probe83264D_80065920[] __asm__("D_80065920");
extern int Probe83264D_8006C550 __asm__("D_8006C550");
extern int Probe83264D_8006C648 __asm__("D_8006C648");
extern int Probe83264D_8006E020 __asm__("D_8006E020");
extern int Probe83264D_8006E024 __asm__("D_8006E024");
extern int Probe83264D_8006E028 __asm__("D_8006E028");
extern int (*Probe83264SpawnParticle)() __asm__("SpawnParticle");
void func_level_50_8008D58C(void *owner) {
    struct { int sp10,sp14,sp18,pad1c,sp20,sp24,sp28,pad2c,sp30,sp34,sp38,pad3c,sp40,sp44,sp48,pad4c,sp50,sp54,sp58,pad5c,pad60,pad64; } frame;
    register int savedStateHalfword __asm__("21");
    register int phaseWord3 __asm__("3");
    register int workWord2 __asm__("2");
    int *referenceBase;
    int handleWord;
    int nextVerticalWord;
    register unsigned char stateByte49 __asm__("4");
    register unsigned int color2 __asm__("2");
    register unsigned int color3 __asm__("3");
    unsigned char selector48;
    void *ownerPosition13;
    void *linkedActor20;
    register void *positionOrVector __asm__("16");
    void *linkedActor;
    void *linkedActor21;
    register void *matrix11 __asm__("17");
    register void *matrix10 __asm__("17");
    register void *state __asm__("18");
    void *ownerPosition23;
    register void *ownerPosition __asm__("20");
    void *var_a0;
    register void *helperArg4 __asm__("4");
    register void *helperArg5 __asm__("5");
    register void *helperArg6 __asm__("6");
    register int savedWordArg4 __asm__("4");
    register int tickWord3 __asm__("3");

    selector48 = M2C_FIELD(owner, unsigned char *, 0x48);
    state = M2C_FIELD(owner, void **, 0);
    switch (selector48) {
    case 22:
        positionOrVector = owner + 0xC;
        frame.sp10 = (int) (((short *)Probe83264D_80065920)[M2C_FIELD(owner, unsigned char *, 0x46)] * 0x19) >> 9;

        frame.sp14 = (int) (((short *)Probe83264D_800658A0)[M2C_FIELD(owner, unsigned char *, 0x46)] * 0x19) >> 9;
        frame.sp18 = 0;
        Probe83264func_8004F194(positionOrVector, positionOrVector, &frame.sp10);
        M2C_FIELD(owner, int *, 0x14) = (int) (M2C_FIELD(owner, int *, 0x14) + M2C_FIELD(state, int *, 8));
        nextVerticalWord = M2C_FIELD(state, int *, 8) - 0x10;
        M2C_FIELD(state, int *, 8) = nextVerticalWord;
        if (nextVerticalWord < -0x12C) {
            M2C_FIELD(state, int *, 8) = -0x12C;
        }
        Probe83264func_8004F178(M2C_FIELD(state, int *, 0xC) + 0xC, positionOrVector);
        M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x45) - (Probe83264D_8006C648 * 2));
        Probe83264SpawnParticle(1, 0xC, M2C_FIELD(state, int *, 0xC), 5);
        if ((Probe83264func_800359A4(state + 2, 2) == 0) && (M2C_FIELD(((M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58) + Probe83264D_8006C550), unsigned char *, 0x49) != 0xA)) {
            return;
        }
        goto releaseOwner;
    case 2:
    case 3:
        if (M2C_FIELD(state, short *, 2) != 0) {
            if (Probe83264func_800359A4(state + 2, 2) != 0) {
                color2 = 0x30;
                M2C_FIELD(owner, unsigned char *, 0x4F) = color2;
                color2 = M2C_FIELD(owner, unsigned char *, 0x54);
                color3 = 13;
                M2C_FIELD(owner, unsigned char *, 0x57) = color3;
                color3 = M2C_FIELD(owner, unsigned char *, 0x56);
                color2 >>= 3;
                M2C_FIELD(owner, unsigned char *, 0x54) = color2;
                color2 = M2C_FIELD(owner, unsigned char *, 0x55);
                color3 >>= 3;
                M2C_FIELD(owner, unsigned char *, 0x56) = color3;
                color2 >>= 3;
                M2C_FIELD(owner, unsigned char *, 0x55) = color2;
            }
            linkedActor = Probe83264D_8006C550 + (M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58);
            M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) M2C_FIELD(linkedActor, unsigned char *, 0x44);
            M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) M2C_FIELD(linkedActor, unsigned char *, 0x45);
            M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(linkedActor, unsigned char *, 0x46);
            Probe83264func_80055D24(owner, 4);
            frame.sp20 = 0x400;
            frame.sp24 = 0;
            frame.sp28 = 0;
            Probe83264func_8004ED6C(owner + 0x20, &frame.sp20, &frame.sp20);
            ownerPosition23 = owner + 0xC;
            Probe83264func_8004F194(ownerPosition23, linkedActor + 0xC, &frame.sp20);
            referenceBase = &Probe83264D_8006E020;
            M2C_FIELD(owner, unsigned char *, 0x45) = Probe83264func_8004E880(Probe83264func_8004F334(ownerPosition23, referenceBase), Probe83264D_8006E028 - M2C_FIELD(owner, int *, 0x14), 0);
            M2C_FIELD(owner, unsigned char *, 0x46) = Probe83264func_8004E880(*referenceBase - M2C_FIELD(owner, int *, 0xC), Probe83264D_8006E024 - M2C_FIELD(owner, int *, 0x10), 0);
            return;
        }
        goto releaseOwner;
    case 13:
        if (M2C_FIELD(state, int *, 4) == 0) {
            M2C_FIELD(state, int *, 4) = Probe83264func_80050844(owner + 0xC, 8, 0xA, 0x40C0C0);
            }
        frame.sp30 = 0x1B8;
        frame.sp34 = 0;
        frame.sp38 = 0;
        Probe83264func_8004ED6C(owner + 0x20, &frame.sp30, &frame.sp30);
        ownerPosition13 = owner + 0xC;
        Probe83264func_8004F194(ownerPosition13, ownerPosition13, &frame.sp30);
        if (Probe83264func_800359A4(state + 2, 2) != 0) {
            goto releaseHandle;
        }
        return;
    case 21:
        linkedActor21 = Probe83264D_8006C550 + (M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58);
        M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) M2C_FIELD(linkedActor21, unsigned char *, 0x44);
        M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) M2C_FIELD(linkedActor21, unsigned char *, 0x45);
        M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(linkedActor21, unsigned char *, 0x46);
        Probe83264func_80055D24(owner, 4);
        frame.sp40 = 0x9C4;
        frame.sp44 = 0;
        frame.sp48 = 0;
        Probe83264func_8004ED6C(owner + 0x20, &frame.sp40, &frame.sp40);
        Probe83264func_8004F194(owner + 0xC, linkedActor21 + 0xC, &frame.sp40);
        M2C_FIELD(owner, unsigned char *, 0x4F) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x4F) + (Probe83264D_8006C648 * 4));
        if (Probe83264func_800359A4(state + 2, 2) != 0) {
            goto releaseOwner;
        }
        break;
    case 20:
        ownerPosition = owner + 0xC;
        if (M2C_FIELD(owner, unsigned char *, 0x49) != 0xC) {
            goto case20_main;
        }
releaseHandle:
        handleWord = M2C_FIELD(state, int *, 4);
        if (handleWord != 0) {
            Probe83264func_800509E8(handleWord);
        }
releaseOwner:
        Probe83264func_80055B18(owner);
        return;
case20_main:
        linkedActor20 = Probe83264D_8006C550 + (M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58);
        M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) M2C_FIELD(linkedActor20, unsigned char *, 0x44);
        M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) M2C_FIELD(linkedActor20, unsigned char *, 0x45);
        M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(linkedActor20, unsigned char *, 0x46);
        Probe83264func_8004F178(ownerPosition, linkedActor20 + 0xC);
        savedStateHalfword = M2C_FIELD(state, short *, 0);
        if (savedStateHalfword < 0x320) {
            savedWordArg4 = savedStateHalfword;
            __asm__("" : "=r"(savedWordArg4) : "0"(savedWordArg4));
            tickWord3 = Probe83264D_8006C648;
            workWord2 = savedWordArg4 + tickWord3 * 12;
            M2C_FIELD(state, short *, 0) = workWord2;
        }
        workWord2 = Probe83264D_8006C648;
        __asm__("" : "=r"(workWord2) : "0"(workWord2));
        phaseWord3 = M2C_FIELD(state, unsigned short *, 2);
        phaseWord3 += workWord2;
        M2C_FIELD(state, short *, 2) = phaseWord3;
        stateByte49 = M2C_FIELD(owner, unsigned char *, 0x49);
        if (stateByte49 == 0xB) {
            Probe83264func_80055D24(owner, 4);
            matrix11 = owner + 0x20;
            frame.sp50 = 0x9C4;
            frame.sp54 = 0;
            frame.sp58 = 0;
            Probe83264func_8004ED6C(matrix11, &frame.sp50, &frame.sp50);
            Probe83264func_8004F194(ownerPosition, ownerPosition, &frame.sp50);
            M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x46) + (M2C_FIELD(state, short *, 2) * 8));
            Probe83264func_80055D24(owner, 4);
            helperArg4 = matrix11;
            positionOrVector = &frame.sp50;
            helperArg5 = positionOrVector;
            __asm__("" : "=r"(helperArg5) : "0"(helperArg5));
            helperArg6 = positionOrVector;
            __asm__("" : "=r"(helperArg4),"=r"(helperArg6) : "0"(helperArg4),"1"(helperArg6));
            frame.sp50 = (int) savedStateHalfword;
            __asm__("" : : : "memory");
            frame.sp54 = 0;
            goto vector_tail;
        } else if (stateByte49 == 0xA) {
            Probe83264func_80055D24(owner, 4);
            matrix10 = owner + 0x20;
            frame.sp50 = 0x9C4;
            frame.sp54 = 0;
            frame.sp58 = 0;
            Probe83264func_8004ED6C(matrix10, &frame.sp50, &frame.sp50);
            Probe83264func_8004F194(ownerPosition, ownerPosition, &frame.sp50);
            M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x45) + (M2C_FIELD(state, short *, 2) * 8));
            Probe83264func_80055D24(owner, 4);
            helperArg4 = matrix10;
            positionOrVector = &frame.sp50;
            helperArg5 = positionOrVector;
            __asm__("" : "=r"(helperArg5) : "0"(helperArg5));
            helperArg6 = positionOrVector;
            __asm__("" : "=r"(helperArg4),"=r"(helperArg6) : "0"(helperArg4),"1"(helperArg6));
            frame.sp50 = (int) savedStateHalfword;
            frame.sp54 = 0;
        } else {
            helperArg4 = owner;
            helperArg5 = (void *)4;
            __asm__("" : "=r"(helperArg4),"=r"(phaseWord3),"=r"(helperArg5) : "0"(helperArg4),"1"(phaseWord3),"2"(helperArg5));
            workWord2 = phaseWord3 << 16;
            phaseWord3 = M2C_FIELD(owner, unsigned char *, 0x44);
            workWord2 >>= 13;
            phaseWord3 += workWord2;
            M2C_FIELD(owner, unsigned char *, 0x44) = phaseWord3;
            Probe83264func_80055D24(helperArg4, helperArg5);
            helperArg4 = owner + 0x20;
            positionOrVector = &frame.sp50;
            helperArg5 = positionOrVector;
            __asm__("" : "=r"(helperArg5) : "0"(helperArg5));
            helperArg6 = positionOrVector;
            __asm__("" : "=r"(helperArg4),"=r"(helperArg6) : "0"(helperArg4),"1"(helperArg6));
            frame.sp50 = 0x9C4;
            frame.sp54 = (int) savedStateHalfword;
        }
vector_tail:
        frame.sp58 = 0;
        Probe83264func_8004ED6C(helperArg4, helperArg5, helperArg6);
        Probe83264func_8004F194(ownerPosition, ownerPosition, positionOrVector);
        if (M2C_FIELD(state, int *, 4) == 0) {
            M2C_FIELD(state, int *, 4) = Probe83264func_80050844(owner + 0xC, 8, 0xA, 0x40C0C0);
        }
    case 0:
    default:
        __asm__("" : : : "memory");
        return;
    }
}

#undef M2C_FIELD


INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8008DBFC);

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8008E924);

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8008F0C8);

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/moby", func_level_50_8008FA4C);
