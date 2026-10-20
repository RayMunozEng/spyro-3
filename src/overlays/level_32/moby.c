#include "common.h"
#include "savepoint.h"
#include "camera.h"
#include "spu.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
#include "ovl_header.h"
extern void func_80039714(Moby*);

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
void func_level_32_80075B98(void *input) {
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
    register int thirty __asm__("$23");
    register int timer __asm__("$3");
    register int timerCondition __asm__("$2");
    register void *selectorOwner __asm__("$4");
    register int selectorMode __asm__("$5");
    register int ten __asm__("$20");
    register int five __asm__("$22");
    register void *savedPlayer __asm__("$21");
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
    register int distanceResult;
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
        if(Controller74C50Field(Controller74C50D_80070328,int*,0x244)!=0 && Controller74C50Field(Controller74C50Field(Controller74C50D_80070328,void**,0x250),short*,0x36)==0x72)
            distanceResult=10000;
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
             __asm__("" : "=r"(first) : "0"(first) : "$21");
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
        case 3:
            ten=10;
            {register int poolIndex __asm__("$3")=Controller74C50Field(owner,unsigned char*,0x3A);
             register int sentinel __asm__("$2");
             register unsigned char *poolEntry __asm__("$2");
             register void *poolBase __asm__("$3");
             register int poolType __asm__("$3");
             register int expected __asm__("$2");
             __asm__("" : "=r"(poolIndex) : "0"(poolIndex) : "$2");
             sentinel=255;
             __asm__("" : "=r"(poolIndex),"=r"(sentinel) : "0"(poolIndex),"1"(sentinel));
             five=5;
             if(poolIndex!=sentinel) {
                 poolEntry=(unsigned char*)(poolIndex*11);
                 __asm__("" : "=r"(poolEntry) : "0"(poolEntry) : "$3");
                 poolBase=Controller74C50D_8006C550;
                 __asm__("" : "=r"(poolEntry),"=r"(poolBase) : "0"(poolEntry),"1"(poolBase));
                 poolEntry=(unsigned char*)(((int)poolEntry<<3)+(int)poolBase);
                 poolType=Controller74C50Field(poolEntry,short*,0x36);
                 __asm__("" : "=r"(poolType) : "0"(poolType) : "$2");
                 expected=0x2D9;
                 __asm__("" : "=r"(expected) : "0"(expected));
                 if(poolType==expected) {
                     thirty=120;
                     ten=2;
                     five=1;
                 }
             }
            }
            stateThreeVector=&frame.eighth.x;
            __asm__("" : "=r"(stateThreeVector) : "0"(stateThreeVector));
            Controller74C50Helper4F52C(stateThreeVector,tag+4);
            stateThreeDelta=&frame.seventh.x;
            if (Controller74C50Field(tag, short *, 0xA) >= thirty) {
                __asm__("" : "=r"(five) : "0"(five));
                Controller74C50Helper4F178(owner + 0xC, Controller74C50D_80070328);
            } else {
                __asm__("" : "=r"(five) : "0"(five));
                __asm__("" : "=r"(stateThreeDelta) : "0"(stateThreeDelta) : "$21");
                {register void *first __asm__("$4")=stateThreeDelta;
                 __asm__("" : "=r"(first) : "0"(first) : "$21");
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
            Controller74C50Helper36E60(owner);
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

typedef struct {
    Vector3D anchor;
    short turnSign, lifetime;
    unsigned char heading, turnTimer, phase, amplitude;
} DecodedButterflyTag;
typedef struct {
    short counter;
    unsigned char sound;
    unsigned char reserved03[17];
    Moby* target;
} DecodedButterflySparxTag;
extern Moby* DecodedButterflySparx __asm__("D_8006C65C");
extern int DecodedButterflyLives __asm__("D_8006C784");
extern int DecodedButterflyFlags __asm__("D_8006C640");
extern int DecodedButterflyTick __asm__("D_8006C648");
extern unsigned char DecodedButterflyPlayer[] __asm__("D_80070328");
extern int DecodedButterflyRecovery __asm__("D_80070328 + 0x280");
extern short DecodedButterflyCos[] __asm__("D_80065920");
extern short DecodedButterflySin[] __asm__("D_800658A0");
extern int (*DecodedButterflyPursuit)(Moby*, Vector3D*, int, int, int, int, int, int, int, int, int, int, int) __asm__("unk_ovlheader_80074314");
int DecodedButterflyDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
int DecodedButterflyCountdown(void*, int) __asm__("func_800359A4");
int DecodedButterflySoundActive(Moby*, int) __asm__("func_8003BFC0");
int DecodedButterflySound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedButterflyAngle(int, int, int) __asm__("func_8004E880");
int DecodedButterflyAngleDifference(int, int) __asm__("func_8003613C");
int DecodedButterflyAddAngle(int, int) __asm__("func_8003617C");
int DecodedButterflyRandom(int, int) __asm__("func_8003636C");
int DecodedButterflyHeadingRandom(int, int) __asm__("func_800363DC");
int DecodedButterflyTurn(Moby*, int, int, int, int, int) __asm__("func_8003585C");
void DecodedButterflyAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedButterflyCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
int DecodedButterflyCollision(Vector3D*, int) __asm__("func_80019194");
int DecodedButterflyGroundQuery(Vector3D*, int) __asm__("func_8001A358");
int DecodedButterflyGround(Moby*) __asm__("func_80035D38");
void DecodedButterflyRefresh(Moby*) __asm__("func_8005629C");
void DecodedButterflyDelete(Moby*) __asm__("func_80055B18");
int rand(void);
/* Rev 0 representative: level_10 0x800758AC..0x80075F34.
 * Reuses the Rev 1 shared-butterfly source chain, checked against every
 * original Rev 0 branch and access width. Empty asm constraints emit no
 * instructions and retain the retail compiler's temporary lifetimes.
 * AI generated; not yet human reviewed. See the batch provenance document.
 */
void func_level_32_80076870(Moby* argument) {
    Vector3D candidatePosition;
    register Moby* moby __asm__("$17") = argument;
    register DecodedButterflyTag* tag __asm__("$18");
    register int distanceOrTurned __asm__("$20");
    register int collision __asm__("$19");
    register DecodedButterflySparxTag* sparxTag __asm__("$16");
    int delta, speed, groundHeight, phase, targetZ;
    register Vector3D* position __asm__("$16");
    register Vector3D* initialPlayer __asm__("$5");
    register Moby* activeSparx __asm__("$2");
    __asm__("" : "=r"(moby) : "0"(moby));
    tag = moby->mobyTag;
    initialPlayer = (Vector3D*)DecodedButterflyPlayer;
    __asm__("" : "=r"(initialPlayer) : "0"(initialPlayer));
    distanceOrTurned = DecodedButterflyDistance(&moby->position, initialPlayer);
    if (moby->state == 2) {
        moby->angle.yaw += 2;
        return;
    }
    if (distanceOrTurned < 3000) {
        int height = moby->position.z - moby->distanceToGround;
        int playerHeight = *(int*)(DecodedButterflyPlayer + 8);
        /* Retail keeps two distinct signed height-admission paths. */
        if (height - playerHeight < 0) goto negativeHeight;
        if (height - playerHeight >= 2800) goto dispatch;
        __asm__ volatile("" : : : "memory");
        goto closeHeight;
negativeHeight:
        if (playerHeight - height >= 2800) goto dispatch;
closeHeight:
        {
            activeSparx = DecodedButterflySparx;
            __asm__("" : "=r"(activeSparx) : "0"(activeSparx));
            if (activeSparx == 0) {
                int* recovery = &DecodedButterflyRecovery;
                if (*recovery >= 0) {
                    DecodedButterflySparx = SpawnMoby(120, moby);
                    if (DecodedButterflySparx != 0) {
                        sparxTag = DecodedButterflySparx->mobyTag;
                        if (!DecodedButterflySoundActive(DecodedButterflySparx, sparxTag->sound))
                            sparxTag->sound = DecodedButterflySound(DecodedButterflySparx, 0, 0);
                        if (moby->mobyClass == 16) *recovery = 1;
                        else {
                            *recovery = 3;
                            DecodedButterflyLives++;
                            if (DecodedButterflyLives >= 100) DecodedButterflyLives = 99;
                        }
                        goto deleteActor;
                    }
                }
            } else {
                sparxTag = activeSparx->mobyTag;
                if (sparxTag->target != 0) {
                    if (sparxTag->target != moby && sparxTag->counter >= 31)
                        sparxTag->counter = 30;
                } else {
                    delta = DecodedButterflyAngle(moby->position.x - *(int*)DecodedButterflyPlayer,
                        moby->position.y - *(int*)(DecodedButterflyPlayer + 4), 0);
                    delta = DecodedButterflyAngleDifference(DecodedButterflyPlayer[0xE], delta);
                    /* Preserve the returned helper-result sign convention. */
                    tag->turnSign = delta >= 0 ? -1 : 1;
                    tag->phase = 0;
                    moby->state = 1;
                    DecodedButterflySparx->substate = 0;
                    sparxTag->target = moby;
                    sparxTag->counter = DecodedButterflyRandom(80, 130);
                }
            }
        }
    }
dispatch:
    switch (moby->state) {
    case 0:
        if (DecodedButterflyCountdown(&tag->lifetime, 2)) {
            if (!moby->drawn) {
deleteActor:
                DecodedButterflyDelete(moby);
                return;
            }
        } else if (!moby->drawn) goto hidden;
        if (distanceOrTurned < 12289) {
            if (DecodedButterflyCountdown(&tag->turnTimer, 1)) {
                int heading;
                __asm__("" : : "r"(distanceOrTurned));
                heading = DecodedButterflyHeadingRandom(30, 90);
                if (rand() & 1) heading = -heading;
                tag->heading = DecodedButterflyAddAngle(tag->heading, heading);
                tag->turnTimer = DecodedButterflyRandom(60, 140);
            }
            distanceOrTurned = DecodedButterflyTurn(moby, tag->heading, 4, 10, 1, 0);
            speed = 30;
            if (DecodedButterflyTick == 3) speed = 45;
            else if (DecodedButterflyTick == 4) speed = 60;
            candidatePosition.x = (DecodedButterflyCos[moby->angle.yaw] * speed) >> 12;
            candidatePosition.y = (DecodedButterflySin[moby->angle.yaw] * speed) >> 12;
            candidatePosition.z = 0;
            position = &moby->position;
            __asm__("" : "=r"(position) : "0"(position));
            DecodedButterflyAdd(&candidatePosition, &candidatePosition, position);
            collision = DecodedButterflyCollision(&candidatePosition, 50);
            if (!collision) DecodedButterflyCopy(position, &candidatePosition);
            if (!(DecodedButterflyFlags & 4)) {
                DecodedButterflyGroundQuery(position, 2048);
                DecodedButterflyRefresh(moby);
            }
            if (distanceOrTurned && collision) {
                tag->heading = DecodedButterflyAddAngle(tag->heading, DecodedButterflyRandom(98, 158));
                tag->turnTimer = DecodedButterflyRandom(30, 80);
            }
            if (!(DecodedButterflyFlags & 3) && DecodedButterflyDistance(&moby->position, &tag->anchor) >= 2001) {
                tag->heading = DecodedButterflyAngle(tag->anchor.x - moby->position.x,
                    tag->anchor.y - moby->position.y, 0);
                tag->turnTimer = 40;
            }
        }
        break;
    case 1:
        if (DecodedButterflySparx != 0) {
            register int zeroArgument __asm__("$6") = 0;
            register Vector3D* player __asm__("$16") = (Vector3D*)DecodedButterflyPlayer;
            __asm__("" : "=r"(player) : "0"(player), "r"(zeroArgument));
            delta = DecodedButterflyAngle(moby->position.x - player->x,
                moby->position.y - *(int*)(DecodedButterflyPlayer + 4), zeroArgument);
            delta = DecodedButterflyAddAngle(delta, tag->turnSign * 10);
            if (DecodedButterflyPursuit(moby, player, 800, delta, 8, 120, 14, 128, 255, 255, 0, 0, 0) < 0 && DecodedButterflySparx != 0)
                ((DecodedButterflySparxTag*)DecodedButterflySparx->mobyTag)->counter = 0;
        } else moby->state = 0;
        break;
    }
    if (!moby->drawn) {
hidden:
        if (moby->state != 1) goto effect;
    }
    {
        register Moby* refreshArgument __asm__("$4");
        int result = DecodedButterflyGround(moby);
        refreshArgument = moby;
        __asm__("" : : "r"(refreshArgument));
        groundHeight = result;
        DecodedButterflyRefresh(refreshArgument);
    }
    if (groundHeight != 0) {
        phase = tag->phase;
        targetZ = groundHeight + 640 + ((DecodedButterflySin[phase] * tag->amplitude) >> 12);
        /* The random result is truncated to the original amplitude byte. */
        if (phase == 0 || phase == 128) tag->amplitude = DecodedButterflyRandom(256, 512);
        tag->phase -= 4;
        groundHeight = targetZ - moby->position.z;
        if (groundHeight > 32) groundHeight = 32;
        if (groundHeight < -32) groundHeight = -32;
        moby->position.z += groundHeight;
    }
effect:
    if (moby->mobyClass == 211 && !(DecodedButterflyFlags & 1))
        SpawnParticle(1, 12, moby, 6);
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
void func_level_32_80076EFC(void *input) {
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
void func_level_32_800784BC(Moby* moby) {
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

typedef struct { short timer; unsigned char selector,reserved03; unsigned char reserved04[0x10]; Moby* target; } DecodedFocusTag;
extern int D_8006581C,D_80065810,D_80065818,D_8006C578,D_8006C574;
extern Moby* D_8006C65C;
int func_8004F334(Vector3D*,Vector3D*);
int func_80013E38(Vector3D*,Vector3D*,int);
void func_80037014(Moby*);
void func_80036A68(Moby*,int,int,int);
int rand(void);
void func_level_32_800785F8(Moby* moby) {
    int i;
    Vector3D position;
    if(*(int*)moby->mobyTag)func_80037014(moby);
    if(D_8006581C>0 && func_8004F334(&moby->position,(Vector3D*)&spyro)<D_80065810) {
        register int actorZ __asm__("$2")=moby->position.z;
        register int z __asm__("$3")=spyro.position.z;
        __asm__("" : "=r"(actorZ), "=r"(z) : "0"(actorZ), "1"(z));
        actorZ+=0x164;z-=actorZ;
        {
        register int limit __asm__("$2")=D_80065818;
        __asm__("" : "=r"(limit) : "0"(limit),"r"(z));
        if(z<0)z=-z;
        z=z<limit;
        __asm__("" : "=r"(z) : "0"(z));
        if(z && D_8006C65C && func_80013E38(&D_8006C65C->position,&moby->position,4)) {
            DecodedFocusTag* tag=D_8006C65C->mobyTag;
            if(tag->target) {
                if(tag->target!=moby && tag->timer>0)tag->timer=0;
            } else {
                D_8006C65C->substate=9;
                tag->target=moby;tag->timer=0;
                if(!func_8003BFC0(D_8006C65C,tag->selector))tag->selector=func_8003BABC(D_8006C65C,0,0);
            }
        }
    }
    }
    if(moby->damageFlags) {
        func_8003BABC(moby,0,0);moby->substate=0x70;
        for(i=0;i<0xC;i++) {
            Moby* piece;
            if(D_8006C578-D_8006C574<0x15)break;
            piece=SpawnMoby(0x132,moby);
            if(i<5)piece->substate=3;else piece->animationState.id=1;
        }
        i=0;
        do {
            func_8004F178(&position,&moby->position);
            i++;
            {
                register int random __asm__("$2")=rand();
                register int coordinate __asm__("$3")=position.x;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                random&=0x1FF;
                coordinate+=0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                coordinate-=random;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                position.x=coordinate;
            }
            {
                register int random __asm__("$2")=rand();
                register int coordinate __asm__("$3")=position.y;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                random&=0x1FF;
                coordinate+=0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                coordinate-=random;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                position.y=coordinate;
            }
            position.z+=rand()&0x1FF;
            SpawnParticle(1,2,&position,0);
            SpawnParticle(4,0x46,&position,(Vector3D*)0x18);
        }while(i<4);
        func_80036A68(moby,0,0,0);func_80055B18(moby);
    }
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
void func_level_32_800788B8(Moby* argument) {
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

typedef struct {
    short timer;
    unsigned char selector, reserved03[17];
    Moby* selected;
} DecodedContainerLink;
extern int D_8006581C, D_80065810, D_80065818;
extern int D_8006C578, D_8006C574, D_8006C644;
extern Moby* D_8006C65C;
extern int DecodedContainerPlayerZ __asm__("D_80070328 + 8");
extern Vector3D DecodedContainerPlayer __asm__("D_80070328");
extern unsigned short DecodedContainerCos[] __asm__("D_80065920");
extern unsigned short DecodedContainerSin[] __asm__("D_800658A0");
int rand(void);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003BFC0(Moby*, int);
int func_8003BABC(Moby*, int, int);
void func_80036A68(Moby*, int, int, int);
void func_80055B18(Moby*);
/* Original selection gates and flag-triggered child/particle emission. */
void func_level_32_80078DD8(Moby* moby) {
    Vector3D position, velocity;
    register DecodedContainerLink* link __asm__("$16");
    int distance, noise;
    register int index __asm__("$16");
    register int heightDifference __asm__("$3");
    register int raisedZ __asm__("$2");
    register int heightLimit __asm__("$2");
    register int childMode __asm__("$18");
    register int childAnimation __asm__("$19");
    if (!moby->substate) moby->substate = rand();
    if (D_8006581C >= 2) {
        distance = func_8004F334(&moby->position, &DecodedContainerPlayer);
        if (distance < D_80065810) {
            raisedZ = moby->position.z;
            heightDifference = DecodedContainerPlayerZ;
            raisedZ += 356;
            __asm__("" : "=r"(raisedZ), "=r"(heightDifference) : "0"(raisedZ), "1"(heightDifference));
            heightDifference -= raisedZ;
            heightLimit = D_80065818;
            __asm__ volatile("" : : : "memory");
            if (heightDifference < 0) heightDifference = -heightDifference;
            __asm__("" : "=r"(heightLimit) : "0"(heightLimit));
            heightDifference = heightDifference < heightLimit;
            __asm__("" : "=r"(heightDifference) : "0"(heightDifference));
            if (heightDifference && D_8006C65C
                && func_80013E38(&D_8006C65C->position, &moby->position, 0)) {
                link = D_8006C65C->mobyTag;
                __asm__("" : "=r"(link) : "0"(link));
                if (link->selected) {
                    if (link->selected != moby && link->timer > 0) link->timer = 0;
                } else {
                    D_8006C65C->substate = 9;
                    link->selected = moby;
                    link->timer = 0;
                    if (!func_8003BFC0(D_8006C65C, link->selector))
                        link->selector = func_8003BABC(D_8006C65C, 0, 0);
                }
            }
        }
    }
    if (*(unsigned int*)((char*)moby + 24) & 0x101B0000) {
        func_8003BABC(moby, 0, 0);
        moby->substate = 100;
        index = 0;
        /* Empty constraints retain original constants and register lifetimes. */
        __asm__ volatile("" : : "r"(index) : "$18", "$19");
        childAnimation = 1;
        childMode = 9;
        __asm__("" : "=r"(childAnimation), "=r"(childMode) : "0"(childAnimation), "1"(childMode));
        for (; index < 12; index++) {
            Moby* child;
            if (D_8006C578 - D_8006C574 < 21) break;
            child = SpawnMoby(0x136, moby);
            if (child) {
                if (index < 6) child->substate = childMode;
                else { child->animationState.id = childAnimation; child->substate = 0; }
            }
        }
        for (index = 0; index < 8; index++) {
            func_8004F178(&position, &moby->position);
            position.x += 128 - (rand() & 255);
            position.y += 128 - (rand() & 255);
            position.z += rand() & 511;
            velocity.x = 64 - (rand() & 127);
            velocity.y = 64 - (rand() & 127);
            velocity.z = 16 - (rand() & 31);
            SpawnParticle(1, 39, &position, &velocity);
            SpawnParticle(2, 70, &position, (Vector3D*)24);
        }
        func_80036A68(moby, 0, 0, 0);
        func_80055B18(moby);
    } else {
        moby->angle.roll = (int)(DecodedContainerCos[(D_8006C644 * 2 + moby->substate) & 255] << 16) >> 25;
        moby->angle.pitch = (int)(DecodedContainerSin[(D_8006C644 * 2 + moby->substate) & 255] << 16) >> 25;
    }
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
void func_level_32_80079158(Moby *moby) {
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
void func_level_32_8007945C(void *input) {
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
void func_level_32_80079FD0(Moby* moby) {
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

typedef struct { Moby* actor; int timer; } DecodedParticleAttachment;
extern int D_8006C648,D_8006C578,D_8006C574,D_8006C79C,D_8006C58C;
extern Moby* D_8006C550;
extern int D_80071AB0[][8];
extern unsigned short DecodedCosine[] __asm__("D_80065920");
extern unsigned short DecodedSine[] __asm__("D_800658A0");
extern Vector3D* DecodedParticleAllocation(int) __asm__("func_8002F040");
int rand(void);
void func_level_32_8007A400(Moby* moby) {
    DecodedParticleAttachment* tag=moby->mobyTag;
    Vector3D position;
    int i;
    if(!tag->actor) {
        tag->actor=SpawnMoby(0xD3,moby);
        if(tag->actor) {
            tag->actor->position.z=moby->position.z+0xE0;
            tag->actor->state=2;
            tag->actor->unknown=0;
        }
    }
    if(moby->drawn) {
        if(tag->timer<0x190)tag->timer+=D_8006C648;
        else {
            Vector3D* particle=DecodedParticleAllocation(5);
            if(particle) {
                register int random __asm__("$2");
                register int angle __asm__("$16");
                register Vector3D* destination __asm__("$4");
                register Vector3D* origin __asm__("$5");
                random=rand();destination=particle;origin=&moby->position;
                __asm__("" : "=r"(destination),"=r"(origin) : "0"(destination),"1"(origin),"r"(random) : "$16");
                angle=random;
                func_8004F178(destination,origin);
                angle&=0xFF;
                {
                    register unsigned int cosine __asm__("$2")=DecodedCosine[angle];
                    register int x __asm__("$3")=particle->x;
                    __asm__("" : "=r"(cosine),"=r"(x) : "0"(cosine),"1"(x));
                    x+=(short)cosine>>4;
                    {
                        register int z __asm__("$2")=particle->z;
                        __asm__("" : "=r"(z) : "0"(z),"r"(x));
                        particle->x=x;
                        {
                            register unsigned int sine __asm__("$3")=DecodedSine[angle];
                            __asm__("" : "=r"(sine) : "0"(sine),"r"(z));
                            z+=0x180;sine<<=16;
                            __asm__("" : "=r"(sine) : "0"(sine),"r"(z));
                            particle->z=z;
                            {
                                register int y __asm__("$2")=particle->y;
                                __asm__("" : "=r"(y) : "0"(y),"r"(sine));
                                y+=(int)sine>>20;
                                __asm__("" : "=r"(y) : "0"(y));
                                particle->y=y;
                            }
                        }
                    }
                }
            }
            {
                register int random __asm__("$2")=rand();
                register int timer __asm__("$3")=tag->timer;
                __asm__("" : "=r"(timer) : "0"(timer),"r"(random));
                random&=0xFF;timer-=0x80;
                __asm__("" : "=r"(timer) : "0"(timer),"r"(random));
                timer-=random;
                __asm__("" : "=r"(timer) : "0"(timer));
                tag->timer=timer;
            }
        }
    }
    if(moby->damageFlags) {
        if(tag->actor) {tag->actor->state=0;tag->actor->unknown=-1;}
        moby->substate=0x70;
        for(i=0;i<0x10;i++) {
            Moby* piece;
            if(D_8006C578-D_8006C574<0x15)break;
            piece=SpawnMoby(0x238,moby);
            piece->animationState.id=rand()%3;
        }
        i=0;
        do {
            func_8004F178(&position,&moby->position);
            i++;
            {
                register int random __asm__("$2")=rand();
                register int coordinate __asm__("$3")=position.x;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                random&=0x1FF;
                coordinate+=0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                coordinate-=random;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                position.x=coordinate;
            }
            {
                register int random __asm__("$2")=rand();
                register int coordinate __asm__("$3")=position.y;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                random&=0x1FF;
                coordinate+=0x100;
                __asm__("" : "=r"(coordinate) : "0"(coordinate),"r"(random));
                coordinate-=random;
                __asm__("" : "=r"(coordinate) : "0"(coordinate));
                position.y=coordinate;
            }
            position.z+=rand()&0x1FF;
            SpawnParticle(1,2,&position,0);
            SpawnParticle(4,0x46,&position,(Vector3D*)0x18);
        }while(i<4);

        func_8003BABC(moby,0,0);func_8003BA00(moby);
        {
            int packed=(moby-D_8006C550)+D_8006C79C;
            D_80071AB0[D_8006C58C][packed>>5]|=1<<(packed&0x1F);
        }
        func_80055B18(moby);
    }
}

/* Tag words at +0/+4/+8 and model pointer at +0x3C only. */
typedef struct { int mobyClass, countdown, reset; } DecodedRespawnTag;
typedef struct { unsigned char reserved00[0x3C]; unsigned char* frames[1]; } DecodedRespawnModel;
extern DecodedRespawnModel* D_8006EE2C[];
extern Moby* D_8006C550;
extern Moby* D_8006C704;
extern int D_8006C7C4;
int func_8004F334(Vector3D*, Vector3D*);
void func_80055C24(Moby*);
void func_8005629C(Moby*);
void func_level_32_8007A768(Moby* owner) {
    DecodedRespawnTag* tag = owner->mobyTag;
    Moby* moby;
    register unsigned char* pitch __asm__("$16");
    unsigned int animationFrames;
    register int multipleFrames __asm__("$3");
    register Moby* callArgument __asm__("$4");
    func_8004F178(&owner->position, &spyro.position);
    if (func_800359A4(&tag->countdown, 4)) {
        moby = D_8006C550;
        tag->countdown = tag->reset;
        if (moby < D_8006C704) {
            pitch = &moby->angle.pitch;
            __asm__ volatile("" : : "r"(pitch));
            do {
            if (*(short*)(pitch - 15) == tag->mobyClass && *(unsigned char*)(pitch + 3) >= 0x80
                && ((*(unsigned char*)(pitch + 14) >> D_8006C7C4) & 1)
                && func_8004F334(&spyro.position, moby->mobyTag) > 0x6000) {
                func_8004F178(&moby->position, moby->mobyTag);
                func_80055C24(moby);
                *(int*)(pitch - 45) = 0;
                *(unsigned char*)(pitch + 12) = 0;
                *(unsigned char*)(pitch + 3) = 0;
                *(unsigned char*)(pitch - 3) = 0;
                callArgument = moby;
                animationFrames = D_8006EE2C[*(short*)(pitch - 15)]->frames[0][0];
                __asm__ volatile("" : : "r"(callArgument));
                *(unsigned char*)(pitch - 9) = 0;
                *(unsigned char*)(pitch - 8) = 0;
                *(unsigned char*)(pitch - 7) = 0;
                *(unsigned char*)(pitch - 6) = 1;
                *(unsigned char*)(pitch - 1) = 0;
                *(unsigned char*)(pitch + 0) = 0;
                multipleFrames = animationFrames >= 2;
                __asm__ volatile("" : "=r"(multipleFrames) : "0"(multipleFrames));
                *(unsigned char*)(pitch - 5) = -multipleFrames & 0x30;
                func_80035D38(callArgument);
                func_8005629C(moby);
                break;
            }
            {
                Moby* limit = D_8006C704;
                __asm__ volatile("" : "=r"(moby) : "0"(moby), "r"(limit));
                moby++;
                pitch += sizeof(Moby);
                if (moby >= limit) break;
            }
            } while (1);
        }
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
void func_level_32_8007A8F4(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007AC10.
* AI generated; not human reviewed. All789 original instructions,21 selectors,
* one zero pad and every actual destination must match:811 owned words.
* Frame88hex=136 bytes saves S0..S7/FP/RA;SP20..5F keeps original vectors.
* The first helper's complete distance allocates naturally to FP. No fixedFP
* binding is present. Original full1/20 saved scalars retain list byte writes,
* private flags and comparisons. List stride88 retains every original full
* index/base/record producer and signed short path index*16-minus16.
* Original default773 enters the common callback,not state0's else chain.
* Original state2 writer follows state20;state3 writer656 follows state5.
* Mode byte branches retain shared call371,read373 and comparison374 entries.
* Original297 enters316 before the owner argument;304/311 enter317 after
* producing it. The full-target gate caught304's wrong316 entry after all789
* instruction shapes matched;the distinct initialized entry is restored.
* Private S3 becomes the original full4 count only after its pointer's last
* consumer. Particle128/count and (index<<8)/count are ordinary signed C
* divisions,including every original zero/overflow guard. Count4,index3 gives
* 32 and192. Both divisions precede RNG and the original SP38-to-SP48 copy.
* Full retained helper results,byte254 before truncation,opaque whole player
* pointer and signed trig table products keep original memory widths/order.
* Empty metadata consumes initialized complete words/addresses or clobbers
* dead values before fresh complete producers;zero CPU instructions. No CPU
* opcode asm,partialHI,undefined saved input,live overlapping aliases or build
* pipeline changes. Known timer,angle and callback views reuse EXE/headers.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation,
* Rev1 mapping and synchronized retail runtime remain open. Confidence is
* binary identity after all gates. Next:human review and retail captures.
* Every native/linked word,target,selector/pad byte and full EXE/every-overlay
* retail hash must remain identical.
*/
/* Original assembly SHA256 ff8f4e31f4c59a7a34988d2670d6bbf2a16be91f452b9b0fa7c00f3edf61e785 */
#define Level32_7AC10Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level32_7AC10Call34F40View1() __asm__("func_80034F40");
int Level32_7AC10Call35030View1() __asm__("func_80035030");
int Level32_7AC10Call35734View1() __asm__("func_80035734");
int Level32_7AC10Call3573CView1() __asm__("func_8003573C");
int Level32_7AC10Call359A4View1(void*, int) __asm__("func_800359A4");
int Level32_7AC10Call35A80View1() __asm__("func_80035A80");
int Level32_7AC10Call360F8View1() __asm__("func_800360F8");
int Level32_7AC10Call36220View1() __asm__("func_80036220");
int Level32_7AC10Call3636CView1() __asm__("func_8003636C");
int Level32_7AC10Call363DCView1() __asm__("func_800363DC");
int Level32_7AC10Call36A68View1() __asm__("func_80036A68");
int Level32_7AC10Call37014View1() __asm__("func_80037014");
int Level32_7AC10Call3BA00View1() __asm__("func_8003BA00");
int Level32_7AC10Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level32_7AC10Call4F110View1() __asm__("func_8004F110");
int Level32_7AC10Call4F178View1() __asm__("func_8004F178");
int Level32_7AC10Call4F194View1() __asm__("func_8004F194");
int Level32_7AC10Call4F264View1(int, int) __asm__("func_8004F264");
int Level32_7AC10Call4F334View1() __asm__("func_8004F334");
int Level32_7AC10Call55B18View1() __asm__("func_80055B18");
int Level32_7AC10Call55D24View1() __asm__("func_80055D24");
int Level32_7AC10Call55F14View1() __asm__("func_80055F14");
int Level32_7AC10DatarandView1(void) __asm__("rand");
extern int Level32_7AC10Data658A0View1 __asm__("D_800658A0");
extern int Level32_7AC10Data65920View1 __asm__("D_80065920");
extern int Level32_7AC10Data6C550View1 __asm__("D_8006C550");
extern int Level32_7AC10Data6C640View1 __asm__("D_8006C640");
extern int Level32_7AC10Data6C770View1 __asm__("D_8006C770");
extern int Level32_7AC10Data70328View1 __asm__("D_80070328");
extern void*(*Level32_7AC10DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
void func_level_32_8007AC10(void *ownerParameter) {
    register int originalEnabledValueOne22 __asm__("$22"), originalStateValueTwenty23 __asm__("$23");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void *ownerRecord18 __asm__("$18");
    register int privateCursorOrLateParticleCount19 __asm__("$19"), retainedRecordDistanceOrParticleIndex16 __asm__("$16"), retainedPrivatePlayerViewOrParticleIndex17 __asm__("$17"), retainedListIndexOrParticleDistance20 __asm__("$20"), retainedHeightOffsetOrParticleVector21 __asm__("$21");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C;
    }
    originalFrame;
    int retainedOriginalDistance;
    int temp_lo;
    int temporaryWord4;
    int temporaryWord8;
    int temporaryWord1;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord9;
    int temporaryWord2;
    int temporaryWord3;
    ownerRecord18 = ownerParameter;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateCursorOrLateParticleCount19 = Level32_7AC10Field(ownerRecord18, void **, 0);
    retainedOriginalDistance = Level32_7AC10Call4F334View1(ownerRecord18 + 0xC, (int)&Level32_7AC10Data70328View1);
    if ((Level32_7AC10Field(ownerRecord18, int *, 0x18) & 0x50000) && ((unsigned int) (Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) - 8) >= 2U)) {
        Level32_7AC10Field(privateCursorOrLateParticleCount19, int *, 0) = 0x154;
        Level32_7AC10Field(privateCursorOrLateParticleCount19, int *, 4) = 0;
        temporaryWord9 = Level32_7AC10Field(ownerRecord18, unsigned char *, 0x51);
        if (temporaryWord9 == 0) {
            temporaryWord9 = Level32_7AC10Call360F8View1(Level32_7AC10Call4E880View1(Level32_7AC10Field(ownerRecord18, int *, 0xC) - Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 0), Level32_7AC10Field(ownerRecord18, int *, 0x10) - Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 4), 0), Level32_7AC10Field((int)&Level32_7AC10Data70328View1, unsigned char *, 0xE), 0x20, 0x40);
        }
        retainedListIndexOrParticleDistance20 = 0;
        __asm__("":"=r"(retainedListIndexOrParticleDistance20):"0"(retainedListIndexOrParticleDistance20):"$23");
        originalStateValueTwenty23 = 20;
        __asm__("":"=r"(originalStateValueTwenty23):"0"(originalStateValueTwenty23):"$22");
        originalEnabledValueOne22 = 1;
        __asm__("":"=r"(originalEnabledValueOne22):"0"(originalEnabledValueOne22):"$21");
        retainedHeightOffsetOrParticleVector21 = 0;
        Level32_7AC10Field(privateCursorOrLateParticleCount19, int *, 8) = (int) temporaryWord9;
        Level32_7AC10Field(ownerRecord18, signed char *, 0x47) = 9;
        do {
            rawWord3 = Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 60+retainedListIndexOrParticleDistance20*4);
            argumentWord5 = 1;
            rawWord2 = rawWord3*11;
            rawWord3 = Level32_7AC10Data6C550View1;
            rawWord2 *= 8;
            retainedRecordDistanceOrParticleIndex16 = rawWord3+rawWord2;
            argumentWord4 = retainedRecordDistanceOrParticleIndex16;
            rawWord2 = 48;
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 76) = rawWord2;
            rawWord2 = Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int*, 28);
            retainedPrivatePlayerViewOrParticleIndex17 = Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int*, 0);
            rawWord3 = 0x80000000;
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 65) = originalEnabledValueOne22;
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 77) = originalEnabledValueOne22;
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int*, 28) = rawWord2|rawWord3;
            Level32_7AC10Call55D24View1(argumentWord4, argumentWord5);
            Level32_7AC10Call4F178View1(retainedRecordDistanceOrParticleIndex16 + 0xC, ownerRecord18 + 0xC);
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char *, 0x4A) = 0x28;
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0x14) = (int) (Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0x14) + retainedHeightOffsetOrParticleVector21);
            rawWord2 = Level32_7AC10Field(ownerRecord18, unsigned char*, 70);
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 72) = originalStateValueTwenty23;
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, unsigned char*, 70) = rawWord2;
            Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, short *, 0x34) = 0;
            rawWord2 = Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 8);
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, int*, 4) = rawWord2;
            rawWord3 = Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 0);
            Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, signed char*, 41) = originalStateValueTwenty23;
            Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, unsigned char*, 40) = 25;
            Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, int*, 0) = rawWord3;
            if (Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x1A) == originalEnabledValueOne22) {
                Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, unsigned char *, 0x28) = 0x3CU;
            }
            if (retainedListIndexOrParticleDistance20 == 0) {
                temporaryWord5 = Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, unsigned char *, 0x28);
                Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, unsigned char *, 0x28) = (unsigned char) (temporaryWord5 + 0x14);
                if (Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x1A) == originalEnabledValueOne22) {
                    Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, unsigned char *, 0x28) = (unsigned char) (temporaryWord5 + 0x23);
                }
            }
            else {
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0xC) = (int) (Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0xC) + ((int) (Level32_7AC10Field((int)&Level32_7AC10Data65920View1, short*, (Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, unsigned char *, 0x46) * 2)) * 0x19) >> 9));
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0x10) = (int) (Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0x10) + ((int) (Level32_7AC10Field((int)&Level32_7AC10Data658A0View1, short*, (Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, unsigned char *, 0x46) * 2)) * 0x19) >> 9));
            }
            Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char *, 0x49) = retainedListIndexOrParticleDistance20;
            retainedListIndexOrParticleDistance20 += 1;
            retainedHeightOffsetOrParticleVector21 += 0x258;
        }
        while (retainedListIndexOrParticleDistance20 < 2);
        Level32_7AC10Call3BA00View1(ownerRecord18);
        Level32_7AC10Call36A68View1(ownerRecord18, 1, 0, 0);
        Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 8U;
        Level32_7AC10Call34F40View1(ownerRecord18, 8);
    }
    rawWord2 = Level32_7AC10Data6C640View1;
    __asm__("":"=r"(rawWord2):"0"(rawWord2):"memory");
    Level32_7AC10Field(ownerRecord18, int*, 24) = 0;
    if (rawWord2 == 0 && ({rawWord3 = Level32_7AC10Field(privateCursorOrLateParticleCount19, short*, 26);rawWord2 = 3;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord3 == rawWord2;})) {
        if (Level32_7AC10Call4F334View1(ownerRecord18+12, (int)&Level32_7AC10Data70328View1) < 10000){
            retainedListIndexOrParticleDistance20 = 0;
            originalEnabledValueOne22 = 1;
            __asm__("":"=r"(originalEnabledValueOne22):"0"(originalEnabledValueOne22));
            do {
                rawWord3 = Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 60);
                privateCursorOrLateParticleCount19 += 4;
                retainedListIndexOrParticleDistance20 += 1;
                retainedRecordDistanceOrParticleIndex16 = Level32_7AC10Data6C550View1;
                rawWord2 = rawWord3*88;
                retainedRecordDistanceOrParticleIndex16 += rawWord2;
                rawWord2 = 48;
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 76) = rawWord2;
                rawWord2 = Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int*, 28);
                retainedPrivatePlayerViewOrParticleIndex17 = Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int*, 0);
                rawWord3 = 0x80000000;
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 65) = originalEnabledValueOne22;
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char*, 77) = originalEnabledValueOne22;
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int*, 28) = rawWord2|rawWord3;
                temporaryWord2 = Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, int*, 12);
                rawWord2 = temporaryWord2;
                argumentWord5 = Level32_7AC10Field(rawWord2, short*, 0)*16;
                rawWord2 = Level32_7AC10Field(rawWord2, int*, 12);
                argumentWord5 -= 16;
                Level32_7AC10Call4F178View1(retainedRecordDistanceOrParticleIndex16+12, rawWord2+argumentWord5);
                Level32_7AC10Call37014View1(retainedRecordDistanceOrParticleIndex16);
                Level32_7AC10Call55D24View1(retainedRecordDistanceOrParticleIndex16, 3);
                Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, signed char *, 0x46) = Level32_7AC10Call4E880View1(Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 0) - Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0xC), Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 4) - Level32_7AC10Field(retainedRecordDistanceOrParticleIndex16, int *, 0x10), 0);
                Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, short *, 0x34) = 0;
                Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, signed char *, 0x37) = 0;
            }
            while (retainedListIndexOrParticleDistance20 < 2);
            Level32_7AC10Call36A68View1(ownerRecord18, 1, 0, 0);
            goto removeOriginalOwner769;
        }
    }
    temporaryWord6 = Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48);
    switch (temporaryWord6) {
    case 0:
    case 1:
        if ((Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x16) != 0) && (Level32_7AC10Call36220View1((int)&Level32_7AC10Data70328View1, privateCursorOrLateParticleCount19 + 0x44, 0, 0) != 0)) {
            temporaryWord3 = Level32_7AC10Field(privateCursorOrLateParticleCount19, void **, 0x1C);
            Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x16) = 0;
            Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x1A) = 0;
            rawWord2 = temporaryWord3;
            argumentWord5 = Level32_7AC10Field(rawWord2, short*, 0)*16;
            rawWord2 = Level32_7AC10Field(rawWord2, int*, 12);
            argumentWord5 -= 16;
            Level32_7AC10Call4F178View1(ownerRecord18+12, rawWord2+argumentWord5);
            Level32_7AC10Call37014View1(ownerRecord18);
            argumentWord4 = (int)ownerRecord18;
            argumentWord5 = 2;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "r"(argumentWord5):"$2");
            rawWord2 = 254;
            Level32_7AC10Field(ownerRecord18, unsigned char*, 82) = rawWord2;
            Level32_7AC10Call55D24View1(argumentWord4, argumentWord5);
        }
        if (Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x1A) == 2) {
            Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x1A) = 0;
            if (Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3D) != 7) {
                Level32_7AC10Data6C770View1 = 0;
                temporaryWord7 = Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3D);
                temporaryWord1 = Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3F);
                Level32_7AC10Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3D) = 7U;
                Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3F) = 0U;
                Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3C) = temporaryWord7;
                Level32_7AC10Field(ownerRecord18, unsigned char *, 0x3E) = temporaryWord1;
                Level32_7AC10Call35734View1(ownerRecord18, temporaryWord1);
            }
            Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 0x14U;
        }
        else if (Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x16) != 0) {
            rawWord2 = Level32_7AC10Call36220View1((int)&Level32_7AC10Data70328View1, privateCursorOrLateParticleCount19+36, 0, 0);
            argumentWord4 = (int)ownerRecord18;
            if (rawWord2 && ({rawWord3 = Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int*, 8);rawWord2 = Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 44);rawWord2 = rawWord2 < rawWord3;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})){
                rawWord2 = 7;
                argumentWord5 = 7;
                Level32_7AC10Field(privateCursorOrLateParticleCount19, short*, 22) = 0;
                goto callOriginalStateWriter656;
            }
            else{
                goto callOriginalIdle317;
            }
        }
        else{
            produceOriginalIdleOwner316:argumentWord4 = (int)ownerRecord18;
            callOriginalIdle317:__asm__ volatile(""::"r"(argumentWord4));
            Level32_7AC10Call3573CView1(argumentWord4, 4, 0, 0);
            if ((Level32_7AC10Call359A4View1(privateCursorOrLateParticleCount19 + 0x10, 4) == 0) || (retainedOriginalDistance >= 0x251C)) {
                Level32_7AC10Call359A4View1(privateCursorOrLateParticleCount19 + 0x14, 2);
                if (Level32_7AC10Data6C770View1 != 0) {
                    rawWord2 = Level32_7AC10Field(privateCursorOrLateParticleCount19, short*, 20);
                    argumentWord4 = 700;
                    if (rawWord2 == 0){
                        Level32_7AC10Field(privateCursorOrLateParticleCount19, short*, 20) = Level32_7AC10Call3636CView1(argumentWord4, 1000);
                        rawWord3 = Level32_7AC10Field(ownerRecord18, unsigned char*, 61);
                        __asm__ volatile("":::"$2", "memory");
                        rawWord2 = 1;
                        argumentWord4 = (int)ownerRecord18;
                        if (rawWord3 == rawWord2) goto compareOriginalMode374;
                        Level32_7AC10Data6C770View1 = 0;
                        rawWord3 = Level32_7AC10Field(ownerRecord18, unsigned char*, 61);
                        argumentWord5 = Level32_7AC10Field(ownerRecord18, unsigned char*, 63);
                        rawWord2 = 114;
                        Level32_7AC10Field(ownerRecord18, signed char*, 64) = rawWord2;
                        Level32_7AC10Field(ownerRecord18, unsigned char*, 61) = 1;
                        Level32_7AC10Field(ownerRecord18, unsigned char*, 63) = 0;
                        Level32_7AC10Field(ownerRecord18, unsigned char*, 60) = rawWord3;
                        goto callOriginalModeUpdate371;
                    }
                    else{
                        rawWord2 = Level32_7AC10Field(ownerRecord18, unsigned char*, 61);
                        argumentWord4 = (int)ownerRecord18;
                        if (!rawWord2) goto readOriginalMode373;
                        Level32_7AC10Data6C770View1 = 0;
                        rawWord2 = Level32_7AC10Field(ownerRecord18, unsigned char*, 61);
                        argumentWord5 = Level32_7AC10Field(ownerRecord18, unsigned char*, 63);
                        rawWord3 = 114;
                        Level32_7AC10Field(ownerRecord18, signed char*, 64) = rawWord3;
                        Level32_7AC10Field(ownerRecord18, unsigned char*, 61) = 0;
                        Level32_7AC10Field(ownerRecord18, unsigned char*, 63) = 0;
                        Level32_7AC10Field(ownerRecord18, unsigned char*, 60) = rawWord2;
                    }
                    callOriginalModeUpdate371:Level32_7AC10Field(ownerRecord18, unsigned char*, 62) = argumentWord5;
                    Level32_7AC10Call35734View1(argumentWord4, argumentWord5);
                }
                readOriginalMode373:rawWord3 = Level32_7AC10Field(ownerRecord18, unsigned char*, 61);
                compareOriginalMode374:rawWord2 = 7;
                argumentWord4 = (int)ownerRecord18;
                if (rawWord3 != rawWord2) goto callOriginalCommon774;
                rawWord2 = 114;
                Level32_7AC10Data6C770View1 = 0;
                Level32_7AC10Field(ownerRecord18, signed char*, 64) = rawWord2;
                Level32_7AC10Field(ownerRecord18, unsigned char*, 61) = 0;
                Level32_7AC10Field(ownerRecord18, unsigned char*, 63) = 0;
                Level32_7AC10Call35734View1(argumentWord4);
            }
            else {
                goto writeOriginalStateTwo462;
            }
        }
        goto produceOriginalDefaultOwner773;
    case 7:
        rawWord2 = Level32_7AC10Call35A80View1(ownerRecord18, Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 28), 256, 170, 0, 6, 40, 5);
        argumentWord4 = (int)ownerRecord18+12;
        argumentWord5 = (int)&Level32_7AC10Data70328View1;
        __asm__("":"=r"(argumentWord5):"0"(argumentWord5), "r"(argumentWord4), "r"(rawWord2):"$16");
        retainedRecordDistanceOrParticleIndex16 = rawWord2;
        if (Level32_7AC10Call4F334View1(argumentWord4, argumentWord5) < 3500) {
            Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 2U;
            Level32_7AC10Call34F40View1(ownerRecord18, 2);
        }
        rawWord2 = retainedRecordDistanceOrParticleIndex16&1;
        __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(retainedRecordDistanceOrParticleIndex16));
        if (rawWord2 && (Level32_7AC10Field(Level32_7AC10Field(privateCursorOrLateParticleCount19, void **, 0x1C), short *, 2) == 0)) {
            Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 0U;
        }
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
    case 20:
        rawWord2 = Level32_7AC10Call36220View1((int)&Level32_7AC10Data70328View1, privateCursorOrLateParticleCount19+36, 0, 0);
        argumentWord4 = (int)ownerRecord18;
        if (rawWord2){
            argumentWord5 = 7;
            rawWord2 = 7;
            Level32_7AC10Field(privateCursorOrLateParticleCount19, short *, 0x16) = 0;
            goto callOriginalStateWriter656;
        }
        __asm__ volatile("":::"$2");
        Level32_7AC10Call35A80View1(ownerRecord18, Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 32), 256, 90, 0, 6, 20, 5);
        if ((retainedOriginalDistance < 0x1B58) && (Level32_7AC10Call4F264View1(Level32_7AC10Field(ownerRecord18, unsigned char *, 0x46), Level32_7AC10Call4E880View1(Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 0) - Level32_7AC10Field(ownerRecord18, int *, 0xC), Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 4) - Level32_7AC10Field(ownerRecord18, int *, 0x10), 0)) < 0x20)) {
            writeOriginalStateTwo462:Level32_7AC10Field(ownerRecord18, unsigned char*, 72) = 2;
            Level32_7AC10Call34F40View1(ownerRecord18, 2);
            argumentWord4 = (int)ownerRecord18;
            goto callOriginalCommon774;
        }
        goto produceOriginalDefaultOwner773;
    case 2:
        Level32_7AC10Call3573CView1(ownerRecord18, 4, 0, 0);
        if (Level32_7AC10Data6C770View1 != 0) {
            Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 3U;
            Level32_7AC10Call34F40View1(ownerRecord18, 3);
        }
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
    case 3:
        retainedPrivatePlayerViewOrParticleIndex17 = (int)&Level32_7AC10Data70328View1+80;
        __asm__("":"=r"(retainedPrivatePlayerViewOrParticleIndex17):"0"(retainedPrivatePlayerViewOrParticleIndex17));
        retainedRecordDistanceOrParticleIndex16 = 5;
        if (Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, int*, 0) == 4) {
            retainedRecordDistanceOrParticleIndex16 = 0xF;
        }
        Level32_7AC10Call4F178View1(&originalFrame.sp20, retainedPrivatePlayerViewOrParticleIndex17 + 0x48);
        temp_lo = originalFrame.sp20 * retainedRecordDistanceOrParticleIndex16;
        originalFrame.sp20 = temp_lo;
        originalFrame.sp24 *= retainedRecordDistanceOrParticleIndex16;
        originalFrame.sp28 *= retainedRecordDistanceOrParticleIndex16;
        Level32_7AC10Call4F110View1(&originalFrame.sp20, 6);
        Level32_7AC10Call4F194View1(&originalFrame.sp20, &originalFrame.sp20, retainedPrivatePlayerViewOrParticleIndex17 - 0x50);
        rawWord2 = Level32_7AC10Call4F334View1(ownerRecord18+12, &originalFrame.sp20);
        argumentWord4 = (int)ownerRecord18;
        argumentWord5 = 4;
        argumentWord6 = 0;
        argumentWord7 = 0;
        __asm__("":"=r"(argumentWord7):"0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(rawWord2):"$16");
        retainedRecordDistanceOrParticleIndex16 = rawWord2;
        Level32_7AC10Call3573CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
        argumentWord4 = privateCursorOrLateParticleCount19+16;
        if (retainedOriginalDistance >= 0x2AF9) {
            Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 6U;
            Level32_7AC10Call34F40View1(ownerRecord18, 6);
            __asm__("":"=r"(privateCursorOrLateParticleCount19):"0"(privateCursorOrLateParticleCount19));
            argumentWord4 = privateCursorOrLateParticleCount19+16;
        }
        if (Level32_7AC10Call359A4View1(argumentWord4, 4) != 0 && ({rawWord2 = retainedRecordDistanceOrParticleIndex16 < 3500;__asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(retainedRecordDistanceOrParticleIndex16));rawWord2;})) {
            if (Level32_7AC10Call4F264View1(Level32_7AC10Field((int)&Level32_7AC10Data70328View1, unsigned char *, 0xE), Level32_7AC10Call4E880View1(Level32_7AC10Field(ownerRecord18, int*, 12)-Level32_7AC10Field(retainedPrivatePlayerViewOrParticleIndex17, int*, -80), Level32_7AC10Field(ownerRecord18, int*, 16)-Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int*, 4), 0)) < 0x32) {
                temporaryWord8 = Level32_7AC10Field(ownerRecord18, int *, 0x14) - Level32_7AC10Field(ownerRecord18, short *, 0x38);
                temporaryWord4 = temporaryWord8 - Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 8);
                if (temporaryWord4 >= 0) {
                    if (temporaryWord4 >= 0x4B0) {
                    }
                    else {
                        goto writeOriginalTrigVector571;
                    }
                }
                else if ((Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 8) - temporaryWord8) < 0x4B0) {
                writeOriginalTrigVector571:
                    rawWord2 = Level32_7AC10Field(ownerRecord18, unsigned char*, 70)*2;
                    rawWord3 = Level32_7AC10Field((int)&Level32_7AC10Data65920View1, short*, rawWord2);
                    __asm__ volatile("":::"$4", "memory");
                    argumentWord4 = (int)ownerRecord18;
                    rawWord2 = (rawWord3*25) >> 10;
                    Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int*, 540) = rawWord2;
                    rawWord2 = Level32_7AC10Field(ownerRecord18, unsigned char*, 70)*2;
                    argumentWord5 = 4;
                    rawWord3 = Level32_7AC10Field((int)&Level32_7AC10Data658A0View1, short*, rawWord2);
                    rawWord2 = 40;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int*, 548) = rawWord2;
                    rawWord2 = (rawWord3*25) >> 10;
                    Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int*, 544) = rawWord2;
                    __asm__ volatile("":::"$2", "memory");
                    rawWord2 = 4;
                    Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 92) = 0;
                    goto callOriginalStateWriter656;
                }
            }
        }
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
    case 6:
        Level32_7AC10Call3573CView1(ownerRecord18, 4, 0, 0);
        if (Level32_7AC10Data6C770View1 != 0) {
            Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 0U;
            Level32_7AC10Call34F40View1(ownerRecord18, 0);
        }
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
    case 4:
        Level32_7AC10Call3573CView1(ownerRecord18, 4, 0, 0);
        if ((unsigned int) (Level32_7AC10Field((int)&Level32_7AC10Data70328View1, int *, 0x50) - 7) < 2U) {
            Level32_7AC10Field(privateCursorOrLateParticleCount19, int *, 0x5C) = 1;
        }
        if (Level32_7AC10Data6C770View1 != 0) {
            if (Level32_7AC10Field(privateCursorOrLateParticleCount19, int *, 0x5C) != 0) {
                Level32_7AC10Field(ownerRecord18, unsigned char *, 0x48) = 5U;
                Level32_7AC10Call34F40View1(ownerRecord18, 5);
            }
            else {
                goto writeOriginalTimer120At652;
            }
        }
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
    case 5:
        rawWord2 = Level32_7AC10Data6C770View1;
        argumentWord4 = (int)ownerRecord18;
        if (!rawWord2) goto callOriginalCommon774;
        writeOriginalTimer120At652:argumentWord5 = 3;
        rawWord2 = 120;
        Level32_7AC10Field(privateCursorOrLateParticleCount19, int*, 16) = rawWord2;
        rawWord2 = 3;
        callOriginalStateWriter656:Level32_7AC10Field(ownerRecord18, unsigned char*, 72) = rawWord2;
        Level32_7AC10Call34F40View1(argumentWord4, argumentWord5);
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
    case 8:
        argumentWord4 = (int)ownerRecord18;
        argumentWord5 = privateCursorOrLateParticleCount19;
        argumentWord7 = 0;
        privateCursorOrLateParticleCount19 = 4;
        __asm__("":"=r"(privateCursorOrLateParticleCount19):"0"(privateCursorOrLateParticleCount19), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord7));
        retainedPrivatePlayerViewOrParticleIndex17 = 0;
        retainedHeightOffsetOrParticleVector21 = (int)&originalFrame.sp40;
        Level32_7AC10Call35030View1(argumentWord4, argumentWord5, Level32_7AC10Field(argumentWord5, int*, 8), argumentWord7, 12, 0, 0, 1);
        Level32_7AC10Call55D24View1(ownerRecord18, 4);
        argumentWord4 = (int)ownerRecord18;
        argumentWord5 = 0;
        __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5):"$16");
        retainedRecordDistanceOrParticleIndex16 = (int)&originalFrame.sp30;
        Level32_7AC10Call55F14View1(argumentWord4, argumentWord5, retainedRecordDistanceOrParticleIndex16);
        retainedListIndexOrParticleDistance20 = Level32_7AC10Call4F334View1(ownerRecord18+12, retainedRecordDistanceOrParticleIndex16);
        do {
            Level32_7AC10Call4F178View1(retainedHeightOffsetOrParticleVector21, ownerRecord18+12);
            argumentWord5 = 128/privateCursorOrLateParticleCount19;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            retainedRecordDistanceOrParticleIndex16 = (retainedPrivatePlayerViewOrParticleIndex17 << 8)/privateCursorOrLateParticleCount19;
            __asm__("":"=r"(retainedRecordDistanceOrParticleIndex16):"0"(retainedRecordDistanceOrParticleIndex16), "r"(argumentWord5):"memory");
            rawWord2 = originalFrame.sp38;
            argumentWord4 = 0;
            originalFrame.sp48 = rawWord2;
            rawWord2 = Level32_7AC10Call363DCView1(argumentWord4, argumentWord5);
            retainedRecordDistanceOrParticleIndex16 += rawWord2;
            __asm__("":"=r"(retainedRecordDistanceOrParticleIndex16):"0"(retainedRecordDistanceOrParticleIndex16));
            retainedRecordDistanceOrParticleIndex16 &= 255;
            __asm__("":"=r"(retainedRecordDistanceOrParticleIndex16):"0"(retainedRecordDistanceOrParticleIndex16));
            retainedRecordDistanceOrParticleIndex16 *= 2;
            originalFrame.sp40 += (int) (Level32_7AC10Field((int)&Level32_7AC10Data65920View1, short*, retainedRecordDistanceOrParticleIndex16) * retainedListIndexOrParticleDistance20) >> 0xC;
            retainedPrivatePlayerViewOrParticleIndex17 += 1;
            originalFrame.sp44 += (int) (Level32_7AC10Field((int)&Level32_7AC10Data658A0View1, short*, retainedRecordDistanceOrParticleIndex16) * retainedListIndexOrParticleDistance20) >> 0xC;
            originalFrame.sp50 = (Level32_7AC10DatarandView1() & 0x1F) - 0x10;
            originalFrame.sp54 = (Level32_7AC10DatarandView1() & 0x1F) - 0x10;
            originalFrame.sp58 = Level32_7AC10Call3636CView1(0x12, 0x18);
            Level32_7AC10DataSpawnParticleView1(1, 13, retainedHeightOffsetOrParticleVector21, &originalFrame.sp50);
        }
        while (retainedPrivatePlayerViewOrParticleIndex17 < privateCursorOrLateParticleCount19);
        if (Level32_7AC10Data6C770View1 != 0) {
        removeOriginalOwner769:
            Level32_7AC10Call55B18View1(ownerRecord18);
            return;
        }
        argumentWord4 = (int)ownerRecord18;
        goto callOriginalCommon774;
        default:goto produceOriginalDefaultOwner773;
    }
    produceOriginalDefaultOwner773:argumentWord4 = (int)ownerRecord18;
    callOriginalCommon774:Level32_7AC10Call55D24View1(argumentWord4, 1);
    return;
}
#undef Level32_7AC10Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007B864.
* Assembly SHA256 0fcc92dfe99491f469b25073d7d80d5cfc74659ebe2d1dac1f2b96f44a493673.
* AI generated;not human reviewed. All757 instructions,22 selector words
* and every actual native/linked transfer/table target must match. Frame78
* retains S0..S5/RA and full SP20..57 local extent. Private34 dispatch0/2
* and owner-byte states retain original physical order. Shared35734 entry
* occurs after state20's transition9 producers;the effect/child tail occurs
* after states8/10. Both returned S0 values survive3573C through their
* original call-delay copies. Signed raw difference1800/word-plus300 paths,
* the early halfword2C clear,post-store signed LH2C and late callback
* arguments retain exact producers and destinations. The final result-byte
* load,A1 literal15 and S0+128 preserve their original call-delay positions.
* Trig table reads consume original signed halfwords at byte offsets;
* vector shifts,random calls and child byte4F clamp32 remain unchanged.
* All empty identities/late inputs/dead clobbers are initialized and emit
* zero instructions. No opcode assembly,partialHI,fixedFP or overlapping
* live fixed aliases. Confidence is binary identity after all gates.
* Raw units/fixed point,full helper contracts,caller cadence,synchronized
* retail runtime and subsystem completion remain open. Cadence recorded
* here is per invocation. Falsification:every native/linked word,target,
* original data byte,complete EXE and every overlay retail hash. */
#define Actor32_7B864Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Actor32_7B864Call1A358View1() __asm__("func_8001A358");
int Actor32_7B864Call34F40View1() __asm__("func_80034F40");
int Actor32_7B864Call35030View1() __asm__("func_80035030");
int Actor32_7B864Call35194View1() __asm__("func_80035194");
int Actor32_7B864Call35734View1() __asm__("func_80035734");
int Actor32_7B864Call3573CView1() __asm__("func_8003573C");
int Actor32_7B864Call359A4View1() __asm__("func_800359A4");
int Actor32_7B864Call35A80View1() __asm__("func_80035A80");
int Actor32_7B864Call3636CView1() __asm__("func_8003636C");
int Actor32_7B864Call363DCView1() __asm__("func_800363DC");
int Actor32_7B864Call365E4View1() __asm__("func_800365E4");
int Actor32_7B864Call369B8View1() __asm__("func_800369B8");
int Actor32_7B864Call36A68View1() __asm__("func_80036A68");
int Actor32_7B864Call37014View1() __asm__("func_80037014");
int Actor32_7B864Call37A60View1() __asm__("func_80037A60");
int Actor32_7B864Call38BF8View1() __asm__("func_80038BF8");
int Actor32_7B864Call3BA00View1() __asm__("func_8003BA00");
int Actor32_7B864Call4E880View1() __asm__("func_8004E880");
int Actor32_7B864Call4EDE8View1() __asm__("func_8004EDE8");
int Actor32_7B864Call4F08CView1() __asm__("func_8004F08C");
int Actor32_7B864Call4F178View1() __asm__("func_8004F178");
int Actor32_7B864Call4F1C8View1() __asm__("func_8004F1C8");
int Actor32_7B864Call4F264View1() __asm__("func_8004F264");
int Actor32_7B864Call4F334View1() __asm__("func_8004F334");
int Actor32_7B864Call55B18View1() __asm__("func_80055B18");
int Actor32_7B864Call55D24View1() __asm__("func_80055D24");
int Actor32_7B864Call55E84View1() __asm__("func_80055E84");
int Actor32_7B864Call55F14View1() __asm__("func_80055F14");
int Actor32_7B864DatarandView1() __asm__("rand");
extern int Actor32_7B864Data658A0View1 __asm__("D_800658A0");
extern int Actor32_7B864Data65920View1 __asm__("D_80065920");
extern int Actor32_7B864Data6C770View1 __asm__("D_8006C770");
extern int Actor32_7B864Data6E020View1 __asm__("D_8006E020");
extern int Actor32_7B864Data6E024View1 __asm__("D_8006E024");
extern unsigned short Actor32_7B864Data6E040View1 __asm__("D_8006E040");
extern int Actor32_7B864Data70328View1 __asm__("D_80070328");
extern int(*Actor32_7B864DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Actor32_7B864DataSpawnParticleView1)() __asm__("SpawnParticle");
extern int(*Actor32_7B864Data74410View1)() __asm__("unk_ovlheader_80074410");
void func_level_32_8007B864(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void *ownerRecord17 __asm__("$17");
    register int privateRecord18 __asm__("$18"), resultOrBound16 __asm__("$16"), recordOrFlag19 __asm__("$19"), argumentBound20 __asm__("$20"), retainedResult21 __asm__("$21");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54;
    }
    originalFrame;
    int temporaryWord7;
    int temporaryWord13;
    int temporaryWord3;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord14;
    int temporaryWord9;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord10;
    int temporaryWord12;
    ownerRecord17 = input;
    __asm__("":"=r"(ownerRecord17):"0"(ownerRecord17));
    privateRecord18 = Actor32_7B864Field(ownerRecord17, void **, 0);
    temporaryWord7 = Actor32_7B864Field(privateRecord18, short *, 0x34);
    switch (temporaryWord7) {
    case 2:
        Actor32_7B864Field(ownerRecord17, signed char *, 0x41) = 0;
        Actor32_7B864Field(ownerRecord17, signed char *, 0x4C) = 0;
        Actor32_7B864Field(ownerRecord17, signed char *, 0x4D) = 0;
        Actor32_7B864Field(ownerRecord17, int *, 8) = 0;
        Actor32_7B864Field(privateRecord18, short *, 0x34) = 1;
        return;
    case 0:
        Actor32_7B864Call359A4View1(privateRecord18 + 0x28, 1);
        Actor32_7B864Call359A4View1(privateRecord18 + 0x29, 1);
        temporaryWord8 = Actor32_7B864Field(ownerRecord17, int *, 0x18);
        if (((temporaryWord8 & 0x10000) && (Actor32_7B864Field(privateRecord18, unsigned char *, 0x29) == 0)) || (temporaryWord8 & 0x8A0000)) {
            temporaryWord9 = Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48);
            if ((temporaryWord9 != 8) && (temporaryWord9 != 0xA)) {
                temporaryWord1 = Actor32_7B864Field(privateRecord18, void **, 0x30);
                if (temporaryWord1 != 0) {
                    Actor32_7B864Call55B18View1(temporaryWord1);
                    Actor32_7B864Field(privateRecord18, void **, 0x30) = 0;
                }
                if (Actor32_7B864Field(ownerRecord17, int *, 0x18) == 0x10000) {
                    Actor32_7B864Field(privateRecord18, unsigned char *, 0x37) = 1U;
                }
                Actor32_7B864Call36A68View1(ownerRecord17, 0, 0, 0);
                Actor32_7B864Call38BF8View1(ownerRecord17, privateRecord18 + 0x10, 1, 0xA);
            }
        }
        Actor32_7B864Field(ownerRecord17, int *, 0x18) = 0;
        switch (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48)) {
        case 0:
            Actor32_7B864Call37A60View1(ownerRecord17, privateRecord18 + 0x16, 2, 0xA, -0xC8);
            Actor32_7B864Call359A4View1(privateRecord18 + 0x2A, 2);
            if (Actor32_7B864Field(privateRecord18, short *, 0x2A) < 0x3C) {
                if (Actor32_7B864Field(privateRecord18, void **, 0x30) != 0) {
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 4U;
                    Actor32_7B864Call34F40View1(ownerRecord17, 4);
                    return;
                }
                Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 3U;
                Actor32_7B864Call34F40View1(ownerRecord17, 3);
                return;
            }
            if ((Actor32_7B864Call3573CView1(ownerRecord17, 5, 0, 0) != 0) && (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) != 0)) {
                argumentWord4 = (int)ownerRecord17;
                Actor32_7B864Data6C770View1 = 0;
                Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 0U;
                goto clearOwnerByteAndCall35734;
            }
            default:goto updateSharedEffectAndChild;
        case 3:
            rawWord2 = Actor32_7B864Call55E84View1(ownerRecord17);
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 7;
            argumentWord6 = 0;
            argumentWord7 = 0;
            __asm__(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7):"$16");
            resultOrBound16 = rawWord2;
            Actor32_7B864Call3573CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if ((Actor32_7B864Field(privateRecord18, void **, 0x30) == 0) && (rawWord2 = resultOrBound16 < 19, !rawWord2)) {
                Actor32_7B864Call55D24View1(ownerRecord17, 4);
                Actor32_7B864Call55F14View1(ownerRecord17, 0, &originalFrame.sp20);
                Actor32_7B864Data74410View1(&originalFrame.sp20, 0x3A, 0xC, 8, 0xC);
                temporaryWord2 = Actor32_7B864DataSpawnMobyView1(0x249, ownerRecord17);
                Actor32_7B864Field(privateRecord18, void **, 0x30) = temporaryWord2;
                if (temporaryWord2 != 0) {
                    Actor32_7B864Field(temporaryWord2, signed char *, 0x48) = 0x64;
                    Actor32_7B864Field(Actor32_7B864Field(privateRecord18, void **, 0x30), unsigned char *, 0x4F) = 0x50U;
                }
            }
            if (Actor32_7B864Data6C770View1 != 0) {
                Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 4U;
                Actor32_7B864Call34F40View1(ownerRecord17, 4);
            }
            goto updateSharedEffectAndChild;
        case 4:
            Actor32_7B864Call37A60View1(ownerRecord17, privateRecord18 + 0x16, 2, 0xA, -0xC8);
            Actor32_7B864Call3573CView1(ownerRecord17, 6, 0, 0);
            if ((Actor32_7B864Call359A4View1(privateRecord18 + 0x2A, 2) != 0) && (Actor32_7B864Call4F334View1(ownerRecord17 + 0xC, &Actor32_7B864Data70328View1) < 0x2134)) {
                temporaryWord11 = Actor32_7B864Field(ownerRecord17, int *, 0x14) - Actor32_7B864Field(ownerRecord17, short *, 0x38);
                temporaryWord3 = temporaryWord11 - Actor32_7B864Field(&Actor32_7B864Data70328View1, int *, 8);
                if (temporaryWord3 >= 0) {
                    if (temporaryWord3 < 0x320) {
                        goto block_35;
                    }
                }
                else if ((Actor32_7B864Field(&Actor32_7B864Data70328View1, int *, 8) - temporaryWord11) < 0x320) {
                block_35:
                    if ((((Actor32_7B864Field(ownerRecord17, int *, 0x14) - Actor32_7B864Field(ownerRecord17, short *, 0x38)) - Actor32_7B864Field(&Actor32_7B864Data70328View1, int *, 8)) < 0xC8) && (Actor32_7B864Field(&Actor32_7B864Data70328View1, int *, 0xB8) == 0) && (Actor32_7B864Call4F264View1((int) (Actor32_7B864Data6E040View1 << 0x10) >> 0x14, Actor32_7B864Call4E880View1(Actor32_7B864Field(ownerRecord17, int *, 0xC) - Actor32_7B864Data6E020View1, Actor32_7B864Field(ownerRecord17, int *, 0x10) - Actor32_7B864Data6E024View1, 0)) < 0x18) && (Actor32_7B864Call4F264View1((int) Actor32_7B864Field(ownerRecord17, unsigned char *, 0x46), Actor32_7B864Call4E880View1(Actor32_7B864Field(&Actor32_7B864Data70328View1, int *, 0) - Actor32_7B864Field(ownerRecord17, int *, 0xC), Actor32_7B864Field(&Actor32_7B864Data70328View1, int *, 4) - Actor32_7B864Field(ownerRecord17, int *, 0x10), 0)) < 8)) {
                        Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 2U;
                        Actor32_7B864Call34F40View1(ownerRecord17, 2);
                    }
                }
            }
            goto updateSharedEffectAndChild;
        case 2:
            rawWord2 = Actor32_7B864Call55E84View1(ownerRecord17);
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 7;
            argumentWord6 = 0;
            argumentWord7 = 0;
            __asm__(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7):"$16");
            resultOrBound16 = rawWord2;
            Actor32_7B864Call3573CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if ((Actor32_7B864Field(privateRecord18, short *, 0x2A) == 0) && (rawWord2 = resultOrBound16 < 16, !rawWord2)) {
                temporaryWord12 = Actor32_7B864Field(privateRecord18, void **, 0x30);
                recordOrFlag19 = Actor32_7B864Field(temporaryWord12, void **, 0);
                Actor32_7B864Field(temporaryWord12, signed char *, 0x48) = 0x63;
                Actor32_7B864Field(privateRecord18, short *, 0x2A) = 0x14;
                Actor32_7B864Call4F178View1(&originalFrame.sp30, &Actor32_7B864Data70328View1);
                rawWord2 = Actor32_7B864Call1A358View1(&originalFrame.sp30, 0x1000);
                argumentWord4 = originalFrame.sp38;
                rawWord3 = rawWord2;
                rawWord2 = argumentWord4-rawWord3;
                if (rawWord2 < 0) goto compareOppositeRawDifference;
                rawWord2 = rawWord2 < 1800;
                if (rawWord2) goto storeOriginalWordPlus300;
                argumentWord4 = recordOrFlag19;
                goto copyOriginalPrivateVector;
                compareOppositeRawDifference:rawWord2 = rawWord3-argumentWord4;
                rawWord2 = rawWord2 < 1800;
                if (!rawWord2) goto keepOriginalFrameWord;
                storeOriginalWordPlus300:rawWord2 = rawWord3+300;
                originalFrame.sp38 = rawWord2;
                keepOriginalFrameWord:argumentWord4 = recordOrFlag19;
                copyOriginalPrivateVector:Actor32_7B864Call4F1C8View1(argumentWord4, &originalFrame.sp30, Actor32_7B864Field(privateRecord18, void**, 0x30)+12);
                Actor32_7B864Call4F08CView1(recordOrFlag19, Actor32_7B864Call4EDE8View1(recordOrFlag19, 1), 0xFA);
                Actor32_7B864Field(recordOrFlag19, short *, 0x10) = 0x78;
                Actor32_7B864Field(recordOrFlag19, signed char *, 0x15) = 0x10;
                Actor32_7B864Field(privateRecord18, void **, 0x30) = 0;
            }
            Actor32_7B864Call37A60View1(ownerRecord17, privateRecord18 + 0x16, 2, 0xA, -0xC8);
            if (Actor32_7B864Data6C770View1 != 0) {
                Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 3U;
                Actor32_7B864Call34F40View1(ownerRecord17, 3);
            }
            goto updateSharedEffectAndChild;
        case 20:
            if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) != 8) {
                Actor32_7B864Data6C770View1 = 0;
                Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 8U;
                Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                Actor32_7B864Call35734View1(ownerRecord17);
            }
            if (Actor32_7B864Field(privateRecord18, unsigned char *, 0x36) != 0) {
                Actor32_7B864Call35030View1(ownerRecord17, privateRecord18, Actor32_7B864Field(privateRecord18, int *, 4), 0, 0xC, 0, 0x12C, 0x4001);
                Actor32_7B864Call37014View1(ownerRecord17);
            }
            else {
                Actor32_7B864Call35030View1(ownerRecord17, privateRecord18, Actor32_7B864Field(privateRecord18, int *, 4), privateRecord18 + 8, 0xC, 0x10, 0x12C, 0x4001);
                Actor32_7B864Field(privateRecord18, short *, 0x16) = (short) Actor32_7B864Field(privateRecord18, int *, 8);
            }
            if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x49) != 0) {
                Actor32_7B864Field(ownerRecord17, int *, 0x14) = (int) (Actor32_7B864Field(ownerRecord17, int *, 0x14) + 0x28A);
            }
            if (Actor32_7B864Field(privateRecord18, unsigned char *, 0x28) == 0) {
                if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x49) == 0) {
                    if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) != 1) {
                        Actor32_7B864Data6C770View1 = 0;
                        Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                        Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 1U;
                        Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                        Actor32_7B864Call35734View1(ownerRecord17);
                    }
                    Actor32_7B864Field(privateRecord18, short *, 0x16) = 0;
                }
                else {
                    if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) != 5) {
                        Actor32_7B864Data6C770View1 = 0;
                        Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                        Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 5U;
                        Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                        Actor32_7B864Call35734View1(ownerRecord17);
                    }
                    Actor32_7B864Field(privateRecord18, short *, 0x16) = 0x8C;
                }
                Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 0x15U;
            }
            goto updateSharedEffectAndChild;
        case 21:
            rawWord2 = Actor32_7B864Call55E84View1(ownerRecord17);
            resultOrBound16 = 200;
            recordOrFlag19 = 0;
            argumentBound20 = 40;
            retainedResult21 = rawWord2;
            if (Actor32_7B864Field(privateRecord18, void **, 0x30) == 0) {
                temporaryWord4 = Actor32_7B864DataSpawnMobyView1(0x249, ownerRecord17);
                Actor32_7B864Field(privateRecord18, void **, 0x30) = temporaryWord4;
                if (temporaryWord4 != 0) {
                    Actor32_7B864Field(temporaryWord4, signed char *, 0x48) = 0x64;
                }
            }
            if (Actor32_7B864Data6C770View1 != 0) {
                if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) == 5) {
                    Actor32_7B864Data6C770View1 = 0;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 6U;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                    Actor32_7B864Call35734View1(ownerRecord17);
                }
                if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) == 7) {
                    Actor32_7B864Data6C770View1 = 0;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 1U;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                    Actor32_7B864Call35734View1(ownerRecord17);
                    goto block_75;
                }
                goto block_76;
            }
            block_75:if (Actor32_7B864Field(ownerRecord17, unsigned char*, 0x3D) == 7) goto clearPrivateHalfwordAndReturn;
        block_76:
            if ((Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) == 5) && (retainedResult21 < 5)) {
                clearPrivateHalfwordAndReturn:Actor32_7B864Field(privateRecord18, unsigned short*, 0x2C) = 0;
                return;
            }
            if (Actor32_7B864Call37A60View1(ownerRecord17, privateRecord18 + 0x16, 2, 0xA, -0xC8) != 0) {
                resultOrBound16 = 0xA0;
                if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) == 9) {
                    Actor32_7B864Data6C770View1 = 0;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 1U;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                    Actor32_7B864Call35734View1(ownerRecord17);
                }
                if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) == 6) {
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x49) = 0U;
                    if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) != 7) {
                        Actor32_7B864Data6C770View1 = 0;
                        Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                        Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 7U;
                        Actor32_7B864Field(ownerRecord17, signed char *, 0x3F) = 0;
                        Actor32_7B864Call35734View1(ownerRecord17);
                    }
                }
            }
            else {
                recordOrFlag19 = 1;
            }
            if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x49) == 1) {
                resultOrBound16 = 0xA0;
                argumentBound20 = 0x80;
            }
            if (recordOrFlag19 != 0) {
                temporaryWord14 = Actor32_7B864Field(privateRecord18, unsigned short *, 0x2C) + 0x1E;
            }
            else {
                temporaryWord14 = Actor32_7B864Field(privateRecord18, unsigned short *, 0x2C) + 0xF;
            }
            Actor32_7B864Field(privateRecord18, unsigned short*, 0x2C) = temporaryWord14;
            __asm__ __volatile__("":::"memory");
            if (resultOrBound16 < Actor32_7B864Field(privateRecord18, short*, 0x2C)) {
                Actor32_7B864Field(privateRecord18, unsigned short *, 0x2C) = (unsigned short) resultOrBound16;
            }
            if (Actor32_7B864Call35A80View1(ownerRecord17, Actor32_7B864Field(privateRecord18, void **, 0xC), 0x100, (short) Actor32_7B864Field(privateRecord18, unsigned short *, 0x2C), 0, 8, argumentBound20, 1) & 1) {
                temporaryWord5 = Actor32_7B864Field(privateRecord18, void **, 0xC);
                temporaryWord13 = Actor32_7B864Field(temporaryWord5, short *, 2);
                if (temporaryWord13 > 0) {
                    if (Actor32_7B864Field(((temporaryWord13 * 0x10) + Actor32_7B864Field(temporaryWord5, int *, 0xC)), int *, -4) == 1) {
                        Actor32_7B864Field(privateRecord18, short *, 0x2E) = 1;
                    }
                }
                if (Actor32_7B864Field(Actor32_7B864Field(privateRecord18, void **, 0xC), short *, 2) == 0) {
                    Actor32_7B864Field(privateRecord18, unsigned char *, 0x37) = 0U;
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x48) = 0U;
                }
            }
            if ((Actor32_7B864Field(privateRecord18, short *, 0x2E) != 0) && (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) == 1) && ((rawWord2 = retainedResult21-9, (unsigned int)rawWord2 < 4U))) {
                temporaryWord6 = Actor32_7B864Field(privateRecord18, void **, 0xC);
                Actor32_7B864Field(privateRecord18, short *, 0x2E) = 0;
                Actor32_7B864Field(privateRecord18, short *, 0x16) = Actor32_7B864Call365E4View1(ownerRecord17 + 0xC, Actor32_7B864Field(temporaryWord6, int *, 0xC) + (Actor32_7B864Field(temporaryWord6, short *, 2) * 0x10), 0xC8, -0xA, &originalFrame.sp40);
                if (Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) != 9) {
                    argumentWord4 = (int)ownerRecord17;
                    Actor32_7B864Data6C770View1 = 0;
                    Actor32_7B864Field(ownerRecord17, signed char *, 0x40) = 0x72;
                    Actor32_7B864Field(ownerRecord17, unsigned char *, 0x3D) = 9U;
                    clearOwnerByteAndCall35734:Actor32_7B864Field(ownerRecord17, signed char*, 0x3F) = 0;
                    Actor32_7B864Call35734View1(argumentWord4);
                }
            }
            goto updateSharedEffectAndChild;
        case 8:
        case 10:
            if (Actor32_7B864Call35194View1(ownerRecord17, privateRecord18 + 0x10) == 0x100) {
                Actor32_7B864Call55D24View1(ownerRecord17, 4);
                Actor32_7B864Call3BA00View1(ownerRecord17);
                Actor32_7B864Call369B8View1(ownerRecord17, 0x20);
                Actor32_7B864Call55B18View1(ownerRecord17);
                return;
            }
            goto updateSharedEffectAndChild;
        }
        break;
    }
    return;
updateSharedEffectAndChild:
    if (Actor32_7B864Field(privateRecord18, unsigned char *, 0x37) != 0) {
        Actor32_7B864Call4F178View1(&originalFrame.sp20, ownerRecord17 + 0xC);
        rawWord2 = Actor32_7B864Call363DCView1(0, 50);
        rawWord3 = originalFrame.sp28;
        __asm__("":"=r"(rawWord3):"0"(rawWord3):"$4");
        argumentWord4 = 0;
        __asm__("":"=r"(rawWord3), "=r"(argumentWord4):"0"(rawWord3), "1"(argumentWord4));
        rawWord3 += 350;
        rawWord3 += rawWord2;
        originalFrame.sp28 = rawWord3;
        resultOrBound16 = Actor32_7B864Field(ownerRecord17, unsigned char*, 0x46);
        __asm__("":"=r"(resultOrBound16):"0"(resultOrBound16):"$5");
        argumentWord5 = 15;
        __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
        resultOrBound16 += 128;
        rawWord2 = Actor32_7B864Call363DCView1(argumentWord4, argumentWord5);
        resultOrBound16 += rawWord2;
        __asm__("":"=r"(resultOrBound16):"0"(resultOrBound16));
        resultOrBound16 &= 255;
        resultOrBound16 <<= 1;
        originalFrame.sp20 += (int) (Actor32_7B864Field(&Actor32_7B864Data65920View1, short*, resultOrBound16) * 0xE1) >> 0xB;
        originalFrame.sp24 += (int) (Actor32_7B864Field(&Actor32_7B864Data658A0View1, short*, resultOrBound16) * 0xE1) >> 0xB;
        originalFrame.sp48 = (Actor32_7B864DatarandView1() & 0x1F) - 0x10;
        originalFrame.sp4C = (Actor32_7B864DatarandView1() & 0x1F) - 0x10;
        originalFrame.sp50 = Actor32_7B864Call3636CView1(0x12, 0x18);
        Actor32_7B864DataSpawnParticleView1(1, 0xD, &originalFrame.sp20, &originalFrame.sp48);
    }
    if (Actor32_7B864Field(privateRecord18, void **, 0x30) != 0) {
        Actor32_7B864Call55D24View1(ownerRecord17, 4);
        Actor32_7B864Call55F14View1(ownerRecord17, 0, Actor32_7B864Field(privateRecord18, void **, 0x30) + 0xC);
        temporaryWord10 = Actor32_7B864Field(privateRecord18, void **, 0x30);
        Actor32_7B864Field(temporaryWord10, unsigned char *, 0x4F) = (unsigned char) (Actor32_7B864Field(temporaryWord10, unsigned char *, 0x4F) - 8);
        argumentWord4 = Actor32_7B864Field(privateRecord18, int*, 0x30);
        if (Actor32_7B864Field(argumentWord4, unsigned char*, 0x4F) < 32){
            Actor32_7B864Field(argumentWord4, unsigned char*, 0x4F) = 32;
        }
    }
    return;
}
#undef Actor32_7B864Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C438.
* AI generated; not human reviewed. All1105 instructions and52 selectors,
* 1157 owned original words, require every native/linked word and actual
* transfer/table destination. Frame70 saves S0..S7/RA,SP20..47 locals.
* Original zero/one/two dispatch,distinct first clear304/later clear359,
* reset366,state40 literal/store815/816,increment935,halfword reset946,
* removal1063 and final flags/helper1087/1091 retain physical entries.
* Packed pointer table indexes are raw4-byte offsets. Each halfword list
* processes the current masked15-bit entry,then tests that same entry's
* signed high bit before advancing2. [0x0002,0x800B] processes2 and11 and
* stops before a third entry. Original633..644/669..672 prove this order.
* Full saved one,selector,list pointer,index and linked record lifetimes
* remain disjoint. Whole adjusted angle returns precede fresh arguments.
* Signed descriptor cap192/minimum80 and independent mask435/446 entries
* retain original producers. Last helper return remains complete until
* new SP38/position/height inputs precede original saved-result move1046.
* Complete dispatch byte survives through its selector only where used.
* Empty metadata reads initialized complete values/addresses or clobbers
* dead values before complete producers;zero CPU instructions. No partialHI,
* fixedFP,undefined saved inputs,live alias overlap or pipeline changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence: binary identity only
* after every gate. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned selectors and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 c1f85c1d7afaabf6294e6bae8fbe086d7739670a6890d2182f379d846f37c28a */
#define Level32_7C438Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
void Level32_7C438Call34F40View1(void*, int) __asm__("func_80034F40");
int Level32_7C438Call35734View1() __asm__("func_80035734");
int Level32_7C438Call3573CView1() __asm__("func_8003573C");
int Level32_7C438Call3585CView1() __asm__("func_8003585C");
int Level32_7C438Call359A4View1(void*, int) __asm__("func_800359A4");
int Level32_7C438Call35A80View1() __asm__("func_80035A80");
int Level32_7C438Call35DDCView1() __asm__("func_80035DDC");
int Level32_7C438Call36220View1() __asm__("func_80036220");
int Level32_7C438Call3645CView1() __asm__("func_8003645C");
int Level32_7C438Call365E4View1() __asm__("func_800365E4");
int Level32_7C438Call37014View1() __asm__("func_80037014");
int Level32_7C438Call37A60View1() __asm__("func_80037A60");
int Level32_7C438Call37BBCView1() __asm__("func_80037BBC");
int Level32_7C438Call3B634View1() __asm__("func_8003B634");
int Level32_7C438Call3B74CView1() __asm__("func_8003B74C");
int Level32_7C438Call3B7B4View1() __asm__("func_8003B7B4");
int Level32_7C438Call492DCView1() __asm__("func_800492DC");
int Level32_7C438Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level32_7C438Call4F178View1() __asm__("func_8004F178");
int Level32_7C438Call4F264View1(int, int) __asm__("func_8004F264");
int Level32_7C438Call4F334View1() __asm__("func_8004F334");
int Level32_7C438Call512E4View1() __asm__("func_800512E4");
int Level32_7C438Call55B18View1() __asm__("func_80055B18");
int Level32_7C438Call55D24View1() __asm__("func_80055D24");
int Level32_7C438Call55E84View1() __asm__("func_80055E84");
extern int Level32_7C438Data658A0View1 __asm__("D_800658A0");
extern int Level32_7C438Data65920View1 __asm__("D_80065920");
extern int Level32_7C438Data6C550View1 __asm__("D_8006C550");
extern int Level32_7C438Data6C58CView1 __asm__("D_8006C58C");
extern int Level32_7C438Data6C5C8View1 __asm__("D_8006C5C8");
extern int Level32_7C438Data6C640View1 __asm__("D_8006C640");
extern int Level32_7C438Data6C648View1 __asm__("D_8006C648");
extern int Level32_7C438Data6C65CView1 __asm__("D_8006C65C");
extern unsigned short** Level32_7C438Data6C730View1 __asm__("D_8006C730");
extern int Level32_7C438Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level32_7C438Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level32_7C438Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level32_7C438Data6D088View1 __asm__("D_8006D088");
extern int Level32_7C438Data6E044View1 __asm__("D_8006E044");
extern int Level32_7C438Data6E344View1 __asm__("D_8006E344");
extern int Level32_7C438Data70300View1 __asm__("D_80070300");
extern int Level32_7C438Data70328View1 __asm__("D_80070328");
extern int(*Level32_7C438DataSpawnMobyView1)() __asm__("SpawnMoby");
void func_level_32_8007C438(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), retainedOne22 __asm__("$22");
    register void *ownerRecord18 __asm__("$18");
    register int privateRecord20 __asm__("$20"), retainedPrivateRecordStepOrResult16 __asm__("$16"), retainedOneStepListOrPosition17 __asm__("$17"), retainedLinkedRecordResultOrListIndex19 __asm__("$19"), retainedSignedSelector21 __asm__("$21"), retainedLinkedRecord23 __asm__("$23");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    }
    originalFrame;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord23;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord19;
    int temporaryWord20;
    int temporaryWord22;
    int temporaryWord13;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord21;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord11;
    int temporaryWord14;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord24;
    int temporaryWord25;
    ownerRecord18 = ownerParameter;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateRecord20 = Level32_7C438Field(ownerRecord18, void **, 0);
    rawWord3 = Level32_7C438Field(privateRecord20, int*, 152);
    argumentWord4 = Level32_7C438Field(ownerRecord18, int*, 24);
    rawWord2 = rawWord3*88;
    rawWord3 = Level32_7C438Data6C550View1;
    retainedLinkedRecordResultOrListIndex19 = rawWord3+rawWord2;
    if (argumentWord4){
        rawWord3 = Level32_7C438Field(ownerRecord18, unsigned char*, 72);
        if (!rawWord3) goto resetOriginalStateSix;
        rawWord2 = 40;
        if (rawWord3 != rawWord2){
            rawWord2 = (unsigned int)rawWord3 < 52;
            goto originalBoundReady;
        }
    resetOriginalStateSix:
        Level32_7C438Field(ownerRecord18, unsigned char*, 72) = 6;
        Level32_7C438Call34F40View1(ownerRecord18, 6);
    }
    rawWord3 = Level32_7C438Field(ownerRecord18, unsigned char*, 72);
    rawWord2 = (unsigned int)rawWord3 < 52;
originalBoundReady:
    Level32_7C438Field(ownerRecord18, int*, 24) = 0;
    switch (rawWord3){
    case 6:__asm__ volatile(""::"r"(rawWord3));
        if (Level32_7C438Data6C770View1 == 0)break;
        if (Level32_7C438Data6C5C8View1 == 0) goto resetOriginalOwnerState366;
        if (Level32_7C438Field(ownerRecord18, unsigned char*, 61) == 0) goto produceOriginalStateForty815;
        Level32_7C438Data6C770View1 = 0;
        Level32_7C438Field(ownerRecord18, signed char*, 64) = 114;
        Level32_7C438Field(ownerRecord18, unsigned char*, 61) = 0;
        Level32_7C438Field(ownerRecord18, signed char*, 63) = 0;
        Level32_7C438Call35734View1(ownerRecord18);
        rawWord2 = 40;
        goto writeOriginalStateForty816;
    case 0x0:
        rawWord2 = Level32_7C438Data6C640View1;
        if (rawWord2 == 0){
            rawWord2 = Level32_7C438Field(privateRecord20, short*, 144);
            retainedOneStepListOrPosition17 = 1;
            if (rawWord2 != retainedOneStepListOrPosition17){
                if (!(Level32_7C438Data6C7B4View1 & 1) && !(Level32_7C438Field((int)&Level32_7C438Data70300View1, unsigned char*, Level32_7C438Data6C58CView1) & 1)) {
                    if (Level32_7C438Call36220View1((int)&Level32_7C438Data70328View1, privateRecord20 + 0x60, 0, 0) != 0) {
                        Level32_7C438Field(Level32_7C438Field(privateRecord20, void **, 0x3C), short *, 2) = 0x12;
                        rawWord2 = Level32_7C438Field(privateRecord20, int*, 60);
                        argumentWord4 = (int)ownerRecord18+12;
                        argumentWord5 = Level32_7C438Field(rawWord2, short*, 2);
                        rawWord2 = Level32_7C438Field(rawWord2, int*, 12);
                        argumentWord5 = (argumentWord5*16)-16;
                        argumentWord5 = rawWord2+argumentWord5;
                        Level32_7C438Call4F178View1(argumentWord4, argumentWord5);
                        Level32_7C438Call37014View1(ownerRecord18);
                        Level32_7C438Field(ownerRecord18, unsigned char *, 0x52) = 0xFE;
                        Level32_7C438Call55D24View1(ownerRecord18, 2);
                        Level32_7C438Field(privateRecord20, unsigned char *, 2) = 2U;
                        Level32_7C438Field(privateRecord20, signed char *, 5) = 0;
                        Level32_7C438Field(privateRecord20, int *, 0x44) = 2;
                        goto writeSharedOriginalPrivateOne155;
                    }
                    if (Level32_7C438Call36220View1((int)&Level32_7C438Data70328View1, privateRecord20 + 0x78, 0, 0) != 0) {
                        Level32_7C438Field(Level32_7C438Field(privateRecord20, void **, 0x3C), short *, 2) = 0x1E;
                        rawWord2 = Level32_7C438Field(privateRecord20, int*, 60);
                        argumentWord4 = (int)ownerRecord18+12;
                        argumentWord5 = Level32_7C438Field(rawWord2, short*, 2);
                        rawWord2 = Level32_7C438Field(rawWord2, int*, 12);
                        argumentWord5 = (argumentWord5*16)-16;
                        argumentWord5 = rawWord2+argumentWord5;
                        Level32_7C438Call4F178View1(argumentWord4, argumentWord5);
                        Level32_7C438Call37014View1(ownerRecord18);
                        Level32_7C438Field(ownerRecord18, unsigned char *, 0x52) = 0xFE;
                        Level32_7C438Call55D24View1(ownerRecord18, 2);
                        Level32_7C438Field(privateRecord20, unsigned char *, 2) = 2U;
                        Level32_7C438Field(privateRecord20, signed char *, 5) = 0;
                        Level32_7C438Field(privateRecord20, int*, 68) = retainedOneStepListOrPosition17;
                    writeSharedOriginalPrivateOne155:
                        Level32_7C438Field(privateRecord20, int*, 80) = retainedOneStepListOrPosition17;
                    }
                    rawWord2 = Level32_7C438Data6C640View1;
                    rawWord2 = rawWord2 < 2;
                    goto testSharedOriginalSignedBound160;
                }
                goto callSharedOriginalRemoval1063;
            }
            rawWord2 = 40;
            goto writeOriginalStateForty816;
        }
        else{
            rawWord2 = rawWord2 < 2;
        }
    testSharedOriginalSignedBound160:
        if (rawWord2)break;
        rawWord2 = 10;
        rawWord3 = Level32_7C438Data6E044View1;
        if (rawWord3 != rawWord2){
            retainedPrivateRecordStepOrResult16 = privateRecord20 + 0x48;
            if (Level32_7C438Field(privateRecord20, int *, 0x48) == 0) {
                Level32_7C438Field(privateRecord20, int *, 0x48) = 1;
                Level32_7C438Call3B7B4View1(retainedPrivateRecordStepOrResult16, 4, (int)&Level32_7C438Data6D088View1);
                Level32_7C438Call3B7B4View1(retainedPrivateRecordStepOrResult16, 4, (int)&Level32_7C438Data6C7F8View1);
                Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0x20C) = 0x10000002;
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x15U;
                return;
            }
            if (Level32_7C438Field(Level32_7C438Field(privateRecord20, void **, 0x3C), short *, 2) == 0) {
                Level32_7C438Field(privateRecord20, int *, 0x44) = 0;
            }
            if (Level32_7C438Field(privateRecord20, int *, 0x44) != 1) {
                if ((Level32_7C438Call3573CView1(ownerRecord18, 4, 0, 0) != 0) && (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) != 0)) {
                    Level32_7C438Data6C770View1 = 0;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                    Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 0U;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                    Level32_7C438Call35734View1(ownerRecord18);
                }
            }
            else {
                temporaryWord11 = (Level32_7C438Field(((Level32_7C438Field(privateRecord20, int *, 0x50) * 4) + privateRecord20), int *, 0x54) * 0x58) + Level32_7C438Data6C550View1;
                ({rawWord2 = Level32_7C438Call4E880View1(Level32_7C438Field(temporaryWord11, int*, 12)-Level32_7C438Field(ownerRecord18, int*, 12), Level32_7C438Field(temporaryWord11, int*, 16)-Level32_7C438Field(ownerRecord18, int*, 16), 0);rawWord2 -= 64;__asm__("":"=r"(rawWord2):"0"(rawWord2):"$4");argumentWord4 = (int)ownerRecord18;argumentWord5 = rawWord2&255;Level32_7C438Call3585CView1(argumentWord4, argumentWord5, 4, 0, 0, 0);});
            }
            if ((Level32_7C438Field(privateRecord20, int *, 0x50) != 1) && (Level32_7C438Call37BBCView1(ownerRecord18, 0) != 0)) {
                Level32_7C438Call512E4View1(ownerRecord18, 0, 1);
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 1U;
            }
            rawWord3 = Level32_7C438Field(privateRecord20, int*, 68);
            if (!rawWord3) goto resetOriginalPrivateHalfword946;
            rawWord2 = 1;
            if (rawWord3 != rawWord2) goto testOriginalStateTwo;
            {
                temporaryWord21 = Level32_7C438Field(ownerRecord18, unsigned char *, 0x3C);
                if ((temporaryWord21 == Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D)) && (temporaryWord21 != 3)) {
                    Level32_7C438Data6C770View1 = 0;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                    Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 3U;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                    Level32_7C438Call35734View1(ownerRecord18);
                }
                temporaryWord1 = Level32_7C438Field(privateRecord20, int *, 0x50);
                if ((temporaryWord1 < 2) && ((unsigned char) Level32_7C438Field(((Level32_7C438Field(((temporaryWord1 * 4) + privateRecord20), int *, 0x54) * 0x58) + Level32_7C438Data6C550View1), unsigned char *, 0x48) >= 0x80U)) {
                    Level32_7C438Field(privateRecord20, int *, 0x50) = (int) (temporaryWord1 + 1);
                clearOriginalPrivateStatus304:
                    __asm__ volatile("":::"memory");
                    Level32_7C438Field(privateRecord20, int *, 0x44) = 0;
                    return;
                }
                break;
            }
        testOriginalStateTwo:
            rawWord2 = 2;
            if (rawWord3 != rawWord2)break;
            {
                Level32_7C438Call3645CView1((int)&Level32_7C438Data70328View1, Level32_7C438Field(privateRecord20, void **, 0x3C), &originalFrame.sp20);
                if (Level32_7C438Call4F334View1(ownerRecord18 + 0xC, (int)&Level32_7C438Data70328View1) < 0x1B58) {
                    temporaryWord22 = Level32_7C438Field(ownerRecord18, int *, 0x14) - Level32_7C438Field(ownerRecord18, short *, 0x38);
                    temporaryWord12 = temporaryWord22 - Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 8);
                    if (temporaryWord12 >= 0){
                        rawWord2 = temporaryWord12 < 1000;
                        argumentWord6 = 0;
                        if (rawWord2) goto checkOriginalAngle336;
                        goto checkOriginalDescriptorBound352;
                    }
                    if ((Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 8) - temporaryWord22) < 0x3E8) {
                    checkOriginalAngle336:
                        if (Level32_7C438Call4F264View1(Level32_7C438Field((int)&Level32_7C438Data70328View1, unsigned char *, 0xE), Level32_7C438Call4E880View1(Level32_7C438Field(ownerRecord18, int *, 0xC) - Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0), Level32_7C438Field(ownerRecord18, int *, 0x10) - Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 4), 0)) >= 0x18) {
                            goto checkOriginalDescriptorBound352;
                        }
                        goto clearOriginalPrivateStatus304;
                    }
                    goto checkOriginalDescriptorBound352;
                }
            checkOriginalDescriptorBound352:
                if (Level32_7C438Field(Level32_7C438Field(privateRecord20, void **, 0x3C), short *, 2) < originalFrame.sp20) {
                    Level32_7C438Field(privateRecord20, int *, 0x44) = 0;
                    return;
                }
                break;
            }
        }
        break;
    case 1:
        if (Level32_7C438Data6E344View1 == 1)break;
    resetOriginalOwnerState366:
        Level32_7C438Field(ownerRecord18, unsigned char*, 72) = 0;
        Level32_7C438Call34F40View1(ownerRecord18, 0);
        return;
    case 0x14:
        rawWord2 = Level32_7C438Call55E84View1(ownerRecord18);
        retainedOneStepListOrPosition17 = 220;
        retainedPrivateRecordStepOrResult16 = 4;
        rawWord3 = Level32_7C438Field(privateRecord20, short*, 78);
        retainedLinkedRecordResultOrListIndex19 = rawWord2;
        if (rawWord3 != 0) {
            retainedPrivateRecordStepOrResult16 = 0x80;
        }
        if (Level32_7C438Call37A60View1(ownerRecord18, privateRecord20 + 0x40, 4, 0xA, -0xC8) != 0) {
            retainedOneStepListOrPosition17 = 0xA0;
            if (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) == 5) {
                Level32_7C438Data6C770View1 = 0;
                Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 4U;
                Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level32_7C438Call35734View1(ownerRecord18);
            }
        }
        argumentWord4 = Level32_7C438Call35A80View1(ownerRecord18, Level32_7C438Field(privateRecord20, void **, 0x3C), 0x100, retainedOneStepListOrPosition17, 0, (int) (Level32_7C438Field(privateRecord20, unsigned short *, 0x4C) << 0x10) >> 0x14, retainedPrivateRecordStepOrResult16, 1);
        if (argumentWord4 & 4) {
            temporaryWord13 = Level32_7C438Field(privateRecord20, unsigned short *, 0x4C) + (Level32_7C438Data6C648View1 * 2);
            Level32_7C438Field(privateRecord20, unsigned short *, 0x4C) = temporaryWord13;
            if ((short)temporaryWord13 >= 193){
                rawWord2 = 192;
                Level32_7C438Field(privateRecord20, short*, 76) = rawWord2;
            }
            else{
                rawWord2 = 192;
            }
            __asm__ volatile(""::"r"(rawWord2));
            rawWord2 = Level32_7C438Field(privateRecord20, short*, 78);
            if (rawWord2 == 0){
                rawWord2 = argumentWord4&1;
                __asm__ volatile(""::"r"(rawWord2));
                if ((short) Level32_7C438Field(privateRecord20, unsigned short *, 0x4C) < 0x50) {
                    Level32_7C438Field(privateRecord20, unsigned short *, 0x4C) = 0x50U;
                }
                goto reloadOriginalDescriptorFlag446;
            }
            else{
                rawWord2 = argumentWord4&1;
            }
        }
        else {
            Level32_7C438Field(privateRecord20, unsigned short *, 0x4C) = 0x20U;
            Level32_7C438Field(privateRecord20, short *, 0x4E) = 1;
        reloadOriginalDescriptorFlag446:
            rawWord2 = argumentWord4 & 1;
        }
        if (rawWord2 != 0) {
            temporaryWord14 = Level32_7C438Field(privateRecord20, void **, 0x3C);
            temporaryWord23 = Level32_7C438Field(temporaryWord14, short *, 2);
            if ((temporaryWord23 > 0) && (Level32_7C438Field(((temporaryWord23 * 0x10) + Level32_7C438Field(temporaryWord14, int *, 0xC)), int *, 0xC) & 1)) {
                Level32_7C438Field(privateRecord20, int *, 0x5C) = 1;
            }
            temporaryWord24 = Level32_7C438Field(privateRecord20, void **, 0x3C);
            rawWord3 = Level32_7C438Field(((Level32_7C438Field(temporaryWord24, short *, 2) * 0x10) + Level32_7C438Field(temporaryWord24, int *, 0xC)), int *, -4);
            argumentWord4 = rawWord3 & 6;
            if (argumentWord4 == 6) {
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x1EU;
                return;
            }
            rawWord3 = rawWord3 >> 1;
            if (argumentWord4 != 0) {
                Level32_7C438Field(privateRecord20, int *, 0x44) = rawWord3;
                if (rawWord3 == 1) {
                    Level32_7C438Field(privateRecord20, unsigned char *, 2) = (unsigned char) (Level32_7C438Field(privateRecord20, unsigned char *, 2) + 1);
                }
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                return;
            }
            goto checkOriginalDescriptorEvent490;
        }
    checkOriginalDescriptorEvent490:
        if ((Level32_7C438Field(privateRecord20, int *, 0x5C) != 0) && (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) == 4) && ({rawWord2 = retainedLinkedRecordResultOrListIndex19-13;(unsigned int)rawWord2 < 3U;})) {
            temporaryWord15 = Level32_7C438Field(privateRecord20, void **, 0x3C);
            Level32_7C438Field(privateRecord20, int *, 0x5C) = 0;
            Level32_7C438Field(privateRecord20, int *, 0x40) = Level32_7C438Call365E4View1(ownerRecord18 + 0xC, Level32_7C438Field(temporaryWord15, int *, 0xC) + (Level32_7C438Field(temporaryWord15, short *, 2) * 0x10), 0xDC, -0xA, &originalFrame.sp24);
            if (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) != 5) {
                Level32_7C438Data6C770View1 = 0;
                Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 5U;
                Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level32_7C438Call35734View1(ownerRecord18);
                return;
            }
        }
        break;
    case 0x1E:
        temporaryWord25 = Level32_7C438Field(privateRecord20, void **, 0x3C);
        temporaryWord16 = (Level32_7C438Field(temporaryWord25, short *, 0) * 0x10) + Level32_7C438Field(temporaryWord25, int *, 0xC);
        if (({rawWord2 = Level32_7C438Call4E880View1(Level32_7C438Field(temporaryWord16, int*, -48)-Level32_7C438Field(ownerRecord18, int*, 12), Level32_7C438Field(temporaryWord16, int*, -44)-Level32_7C438Field(ownerRecord18, int*, 16), 0);rawWord2 -= 12;__asm__("":"=r"(rawWord2):"0"(rawWord2):"$4");argumentWord4 = (int)ownerRecord18;argumentWord5 = rawWord2&255;Level32_7C438Call3585CView1(argumentWord4, argumentWord5, 4, 2, 1, 0);}) != 0) {
            if (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) != 0) {
                Level32_7C438Data6C770View1 = 0;
                Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 0U;
                Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level32_7C438Call35734View1(ownerRecord18);
            }
            Level32_7C438Field(privateRecord20, signed char *, 5) = 1;
            Level32_7C438Field(privateRecord20, unsigned char *, 2) = 3U;
            if (Level32_7C438Call37BBCView1(ownerRecord18, 0) != 0) {
                Level32_7C438Field(retainedLinkedRecordResultOrListIndex19, unsigned char *, 0x49) = 1U;
                Level32_7C438Field(((Level32_7C438Field(privateRecord20, int *, 0xA0) * 0x58) + Level32_7C438Data6C550View1), signed char *, 0x49) = 1;
                Level32_7C438Call512E4View1(ownerRecord18, 0, 1);
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x1FU;
                return;
            }
        }
        break;
    case 0x1F:
        if (Level32_7C438Data6E344View1 != 1) {
            Level32_7C438Call34F40View1(ownerRecord18, 0);
            Level32_7C438Field(privateRecord20, int *, 0x40) = 0;
            Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x32U;
            return;
        }
        break;
    case 0x28:
        rawWord3 = Level32_7C438Field(privateRecord20, int*, 148);
        rawWord2 = rawWord3*88;
        rawWord3 = Level32_7C438Data6C550View1;
        retainedLinkedRecord23 = rawWord3+rawWord2;
        retainedPrivateRecordStepOrResult16 = Level32_7C438Field(retainedLinkedRecord23, void **, 0);
        if ((Level32_7C438Field(privateRecord20, unsigned char *, 0x92) == 0) && (Level32_7C438Field(retainedPrivateRecordStepOrResult16, short *, 0x64) < 2)) {
            if (({rawWord2 = Level32_7C438Call36220View1((int)&Level32_7C438Data70328View1, privateRecord20+96, 0, 0);retainedLinkedRecordResultOrListIndex19 = 0;rawWord2;}) != 0){
                retainedOne22 = 1;
                __asm__("":"=r"(retainedOne22):"0"(retainedOne22));
                retainedSignedSelector21 = Level32_7C438Field(retainedPrivateRecordStepOrResult16, short *, 0x64);
                Level32_7C438Field(privateRecord20, unsigned char *, 0x92) = 1U;
            loadOriginalPackedList627:
                retainedOneStepListOrPosition17 = Level32_7C438Field((int)Level32_7C438Data6C730View1+retainedLinkedRecordResultOrListIndex19*4, int*, 0);
                do {
                    rawWord2 = Level32_7C438Field(retainedOneStepListOrPosition17, unsigned short*, 0)&32767;
                    rawWord3 = rawWord2*88;
                    rawWord2 = Level32_7C438Data6C550View1;
                    retainedPrivateRecordStepOrResult16 = rawWord2+rawWord3;
                    if (retainedLinkedRecordResultOrListIndex19 != retainedSignedSelector21) {
                        if ((unsigned char) Level32_7C438Field(retainedPrivateRecordStepOrResult16, unsigned char *, 0x48) < 0x80U) {
                            Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char *, 0x41) = 0;
                            Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char *, 0x4C) = 0;
                            Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char *, 0x4D) = 0;
                            Level32_7C438Field(retainedPrivateRecordStepOrResult16, int *, 8) = 0;
                            Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char *, 0x4A) = 0;
                        }
                    }
                    else if ((unsigned char) Level32_7C438Field(retainedPrivateRecordStepOrResult16, unsigned char *, 0x48) < 0x80U) {
                        Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char*, 65) = retainedOne22;
                        Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char *, 0x4C) = 0x3F;
                        Level32_7C438Field(retainedPrivateRecordStepOrResult16, signed char*, 77) = retainedOne22;
                        Level32_7C438Call55D24View1(retainedPrivateRecordStepOrResult16, 1);
                        Level32_7C438Field(retainedPrivateRecordStepOrResult16, unsigned char *, 0x4A) = 0xFF;
                    }
                    rawWord2 = Level32_7C438Field(retainedOneStepListOrPosition17, short*, 0);
                    retainedOneStepListOrPosition17 += 2;
                }
                while (rawWord2 >= 0);
                retainedLinkedRecordResultOrListIndex19 += 1;
                if (retainedLinkedRecordResultOrListIndex19 < 2) {
                    goto loadOriginalPackedList627;
                }
            }
            goto checkOriginalLinkedRecordState679;
        }
        if ((Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0x244) != 0) && (Level32_7C438Field(Level32_7C438Field((int)&Level32_7C438Data70328View1, void **, 0x250), short *, 0x36) == 0x72) && (Level32_7C438Call36220View1(((int)&Level32_7C438Data70328View1 + 0x244) - 0x244, privateRecord20 + 0x60, 0, 0x1388) != 0)) {
            Level32_7C438Call3B74CView1((int)&Level32_7C438Data6D088View1);
            return;
        }
    checkOriginalLinkedRecordState679:
        if ((Level32_7C438Field(retainedLinkedRecord23, unsigned char *, 0x48) != 1) && (Level32_7C438Call37BBCView1(ownerRecord18, 0) != 0)) {
            Level32_7C438Field(privateRecord20, unsigned char *, 0x92) = 0U;
            Level32_7C438Call512E4View1(ownerRecord18, 0, 1);
            Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x29U;
            return;
        }
        break;
    case 0x29:
        if ((Level32_7C438Data6C65CView1 == 0) && (Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0x280) > 0)) {
            Level32_7C438Data6C65CView1 = Level32_7C438DataSpawnMobyView1(0x78, ownerRecord18);
        }
        rawWord2 = Level32_7C438Data6E344View1;
        argumentWord6 = 1;
        if (rawWord2 != argumentWord6){
            rawWord2 = Level32_7C438Field(privateRecord20, int*, 148);
            argumentWord4 = Level32_7C438Data6C550View1;
            argumentWord5 = Level32_7C438Field(privateRecord20, unsigned char*, 4);
            Level32_7C438Field(privateRecord20, unsigned char*, 146) = 0;
            rawWord3 = rawWord2*88;
            retainedOneStepListOrPosition17 = argumentWord4+rawWord3;
            if ((argumentWord5 == argumentWord6) || (argumentWord5 == 6) || (argumentWord5 == 9)) {
                Level32_7C438Call4F178View1(&originalFrame.sp28, ownerRecord18 + 0xC);
                temporaryWord9 = originalFrame.sp28 + ((int) (Level32_7C438Field((int)&Level32_7C438Data65920View1, short*, (Level32_7C438Field(ownerRecord18, unsigned char *, 0x46) * 2)) * 0xD) >> 5);
                originalFrame.sp28 = temporaryWord9;
                temporaryWord3 = originalFrame.sp2C + ((int) (Level32_7C438Field((int)&Level32_7C438Data658A0View1, short*, (Level32_7C438Field(ownerRecord18, unsigned char *, 0x46) * 2)) * 0xD) >> 5);
                originalFrame.sp2C = temporaryWord3;
                Level32_7C438Call3B634View1((int)&Level32_7C438Data6D088View1, &originalFrame.sp28, Level32_7C438Call4E880View1(Level32_7C438Field(ownerRecord18, int *, 0xC) - temporaryWord9, Level32_7C438Field(ownerRecord18, int *, 0x10) - temporaryWord3, 0) & 0xFF);
                if (Level32_7C438Field(privateRecord20, unsigned char *, 4) == 1) {
                    Level32_7C438Field(privateRecord20, signed char *, 0x93) = 0;
                }
                else {
                    Level32_7C438Field(privateRecord20, signed char *, 0x93) = 1;
                }
                Level32_7C438Field(retainedOneStepListOrPosition17, signed char *, 0x48) = 1;
            }
            if (Level32_7C438Field(privateRecord20, unsigned char *, 4) == 3) {
                Level32_7C438Field(privateRecord20, signed char *, 5) = 2;
            }
        produceOriginalStateForty815:
            rawWord2 = 40;
        writeOriginalStateForty816:
            Level32_7C438Field(ownerRecord18, unsigned char*, 72) = rawWord2;
            return;
        }
        break;
    case 0x15:
        temporaryWord17 = Level32_7C438Field(ownerRecord18, unsigned char *, 0x49);
        switch (temporaryWord17) {
        case 0:
            Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0x20C) = 0x10000002;
            if (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) != 4) {
                Level32_7C438Data6C770View1 = 0;
                Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 4U;
                Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level32_7C438Call35734View1(ownerRecord18);
            }
            Level32_7C438Call4F178View1(&originalFrame.sp28, ((int)&Level32_7C438Data70328View1 + 0x20C) - 0x20C);
            temporaryWord2 = Level32_7C438Field((int)&Level32_7C438Data70328View1, unsigned char *, 0xE) * 2;
            temporaryWord10 = originalFrame.sp28 + ((int) (Level32_7C438Field((int)&Level32_7C438Data65920View1, short*, temporaryWord2) * 0x177) >> 0xA);
            originalFrame.sp28 = temporaryWord10;
            temporaryWord4 = originalFrame.sp2C + ((int) (Level32_7C438Field((int)&Level32_7C438Data658A0View1, short*, temporaryWord2) * 0x177) >> 0xA);
            originalFrame.sp2C = temporaryWord4;
            Level32_7C438Call3585CView1(ownerRecord18, Level32_7C438Call4E880View1(temporaryWord10 - Level32_7C438Field(ownerRecord18, int *, 0xC), temporaryWord4 - Level32_7C438Field(ownerRecord18, int *, 0x10), 0), 7, 0, 0, 0);
            Level32_7C438Call35DDCView1(ownerRecord18, 0x8C, 0, 0, 5);
            if (Level32_7C438Call4F334View1(ownerRecord18 + 0xC, &originalFrame.sp28) < 0x96) {
                if (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) != 0) {
                    Level32_7C438Data6C770View1 = 0;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                    Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 0U;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                    Level32_7C438Call35734View1(ownerRecord18);
                }
                goto incrementOriginalOwnerSubstate935;
            }
            break;
        case 1:
            Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0x20C) = 0x10000002;
            if (Level32_7C438Call3573CView1(ownerRecord18, 7, 0, 0) != 0) {
                Level32_7C438Call512E4View1(ownerRecord18, 0, 1);
            incrementOriginalOwnerSubstate935:
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x49) = (unsigned char) (Level32_7C438Field(ownerRecord18, unsigned char *, 0x49) + 1);
                return;
            }
            break;
        case 2:
            if (Level32_7C438Data6E344View1 != 1) {
                Level32_7C438Field(privateRecord20, int*, 68) = 0;
            resetOriginalPrivateHalfword946:
                Level32_7C438Field(privateRecord20, short *, 0x4E) = 0;
                if (Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) != 4) {
                    Level32_7C438Data6C770View1 = 0;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x40) = 0x72;
                    Level32_7C438Field(ownerRecord18, unsigned char *, 0x3D) = 4U;
                    Level32_7C438Field(ownerRecord18, signed char *, 0x3F) = 0;
                    Level32_7C438Call35734View1(ownerRecord18);
                }
                Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x14U;
                return;
            }
            break;
        }
        break;
    case 0x32:
        if (Level32_7C438Call359A4View1(privateRecord20 + 0x40, 4) != 0) {
            Level32_7C438Field(ownerRecord18, unsigned char *, 0x49) = 0U;
            Level32_7C438Field(Level32_7C438Field(privateRecord20, void **, 0x9C), short *, 2) = 0;
            Level32_7C438Call34F40View1(ownerRecord18, 4);
            Level32_7C438Field(ownerRecord18, unsigned char *, 0x48) = 0x33U;
        }
        goto writeOriginalPlayerFlags1087;
    case 0x33:
        temporaryWord18 = Level32_7C438Field(ownerRecord18, unsigned char *, 0x49);
        retainedSignedSelector21 = Level32_7C438Field(Level32_7C438Field(privateRecord20, void **, 0x9C), short *, 2);
        switch (temporaryWord18) {
        case 0:
            if (Level32_7C438Call35A80View1(ownerRecord18, Level32_7C438Field(privateRecord20, void **, 0x9C), 0x200, 0x80, 0, 8, 0xC, 5) & 1) {
                if ((unsigned char) Level32_7C438Field(retainedLinkedRecordResultOrListIndex19, unsigned char *, 0x49) < 0xAU) {
                    Level32_7C438Field(retainedLinkedRecordResultOrListIndex19, unsigned char *, 0x49) = 0xAU;
                }
                temporaryWord5 = Level32_7C438Field(privateRecord20, void **, 0x9C);
                temporaryWord7 = Level32_7C438Field(temporaryWord5, short *, 2);
                if (temporaryWord7 != 0) {
                    temporaryWord19 = Level32_7C438Field(temporaryWord5, int *, 0xC);
                    if (Level32_7C438Field(((retainedSignedSelector21 * 0x10) + temporaryWord19), int *, 0xC) & 1) {
                        Level32_7C438Field(privateRecord20, int *, 0x40) = Level32_7C438Call365E4View1(ownerRecord18 + 0xC, temporaryWord19 + (temporaryWord7 * 0x10), 0x80, -0xC, 0);
                        Level32_7C438Field(ownerRecord18, unsigned char *, 0x49) = 1U;
                    }
                    goto checkOriginalLinkedSubstate1082;
                }
                goto callSharedOriginalRemoval1063;
            }
            default:goto checkOriginalLinkedSubstate1082;
        case 1:
            rawWord2 = Level32_7C438Call35A80View1(ownerRecord18, Level32_7C438Field(privateRecord20, void**, 156), 512, 128, 0, 8, 12, 0);
            argumentWord4 = (int)&originalFrame.sp38;
            retainedOneStepListOrPosition17 = (int)ownerRecord18+12;
            argumentWord6 = Level32_7C438Field(privateRecord20, int*, 64);
            argumentWord5 = retainedOneStepListOrPosition17;
            argumentWord6 -= 12;
            Level32_7C438Field(privateRecord20, int*, 64) = argumentWord6;
            rawWord3 = Level32_7C438Field(ownerRecord18, int*, 20);
            __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(rawWord2), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6):"$16");
            retainedPrivateRecordStepOrResult16 = rawWord2;
            rawWord3 += argumentWord6;
            Level32_7C438Field(ownerRecord18, int*, 20) = rawWord3;
            Level32_7C438Call4F178View1(argumentWord4, argumentWord5);
            rawWord2 = originalFrame.sp40;
            rawWord2 += 512;
            originalFrame.sp40 = rawWord2;
            rawWord2 = retainedPrivateRecordStepOrResult16&1;
            if (rawWord2){
                temporaryWord6 = Level32_7C438Field(privateRecord20, void **, 0x9C);
                temporaryWord8 = Level32_7C438Field(temporaryWord6, short *, 2);
                if (temporaryWord8 == 0){
                callSharedOriginalRemoval1063:
                    Level32_7C438Call55B18View1(ownerRecord18);
                    return;
                }
                temporaryWord20 = Level32_7C438Field(temporaryWord6, int *, 0xC);
                if (Level32_7C438Field(((retainedSignedSelector21 * 0x10) + temporaryWord20), int *, 0xC) & 1) {
                    Level32_7C438Field(privateRecord20, int *, 0x40) = Level32_7C438Call365E4View1(retainedOneStepListOrPosition17, temporaryWord20 + (temporaryWord8 * 0x10), 0x80, -0xC, 0);
                }
                goto checkOriginalLinkedSubstate1082;
            }
            goto checkOriginalLinkedSubstate1082;
        }
    checkOriginalLinkedSubstate1082:
        if (Level32_7C438Field(retainedLinkedRecordResultOrListIndex19, unsigned char*, 73) >= 11) goto callOriginalFinalHelper1091;
    writeOriginalPlayerFlags1087:
        Level32_7C438Field((int)&Level32_7C438Data70328View1, int *, 0x20C) = 0x10000002;
    callOriginalFinalHelper1091:
        Level32_7C438Call492DCView1(ownerRecord18 + 0xC);
        break;
    }
}
#undef Level32_7C438Field


typedef struct {
    unsigned char reserved00[0x18];
    EnemyTag enemy;
    int timer,count;
} DecodedEnemyDelay;
extern int D_8006C770;
int func_8003636C(int,int);
void func_80037168(Moby*,void*,int);
void func_level_32_8007D57C(Moby* actor) {
    DecodedEnemyDelay* tag=actor->mobyTag;
    if(actor->state!=3 && actor->damageFlags) {
        if(actor->mobyClass==0x2E) {
            func_80038BF8(actor,&tag->enemy,8,3);
            tag->enemy.unk6=0xC8;tag->enemy.unk4+=0x64;
        } else {
            func_80038BF8(actor,&tag->enemy,0,3);tag->enemy.unk6=0x96;
        }
        SpawnMoby(0x10,actor);actor->unknownCollision=0;
    }
    switch(actor->state) {
    case 0:case 1:
        if(D_8006C770) {
            tag->timer=func_8003636C(0x5A,0x12C);actor->state=2;func_80034F40(actor,2);
        }
        break;
    case 2:
        func_80037168(actor,tag,0x57);
        if(func_800359A4(&tag->timer,4)) {
            if(tag->count) {tag->count--;actor->state=0;func_80034F40(actor,0);}
            else {tag->count=func_8003636C(2,4);actor->state=1;func_80034F40(actor,1);}
        }
        break;
    case 3:
        if(func_80035194(actor,&tag->enemy)==0x100) {
            func_80055D24(actor,4);func_8003BA00(actor);func_800369B8(actor,0x20);func_80055B18(actor);
        }
        break;
    }
}

extern int D_8006C770;
void func_level_32_8007D748(Moby* moby) {
    if ((moby->damageFlags & 0x2020000) && moby->state != 1) {
        moby->state = 1;
        func_80034F40(moby, 1);
    }
    moby->damageFlags = 0;
    switch (moby->state) {
    case 0:
        break;
    case 1:
        if (D_8006C770) {
            moby->state = 0;
            func_80034F40(moby, 0);
        }
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Original3159 instructions; AI generated, not human reviewed; uninstalled. */
#define Level32_7D7D8Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level32_7D7D8Field(p, t, o) (*(t)((unsigned char *)(p) + (o)))
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Level32_7D7D8Product;
int Level32_7D7D8_PlaySound() __asm__("PlaySound");
int Level32_7D7D8_func_80013D44() __asm__("func_80013D44");
int Level32_7D7D8_func_8001A358() __asm__("func_8001A358");
int Level32_7D7D8_func_8002803C() __asm__("func_8002803C");
int Level32_7D7D8_func_80028154() __asm__("func_80028154");
int Level32_7D7D8_func_80034F40() __asm__("func_80034F40");
int Level32_7D7D8_func_80035194() __asm__("func_80035194");
int Level32_7D7D8_func_80035734() __asm__("func_80035734");
int Level32_7D7D8_func_800359A4() __asm__("func_800359A4");
int Level32_7D7D8_func_8003613C() __asm__("func_8003613C");
int Level32_7D7D8_func_8003636C() __asm__("func_8003636C");
int Level32_7D7D8_func_800363DC() __asm__("func_800363DC");
int Level32_7D7D8_func_800369B8() __asm__("func_800369B8");
int Level32_7D7D8_func_800369D8() __asm__("func_800369D8");
int Level32_7D7D8_func_80037014() __asm__("func_80037014");
int Level32_7D7D8_func_80037BBC() __asm__("func_80037BBC");
int Level32_7D7D8_func_80038BF8() __asm__("func_80038BF8");
int Level32_7D7D8_func_8003B634() __asm__("func_8003B634");
int Level32_7D7D8_func_8003B74C() __asm__("func_8003B74C");
int Level32_7D7D8_func_8003B7B4() __asm__("func_8003B7B4");
int Level32_7D7D8_func_8003BABC() __asm__("func_8003BABC");
int Level32_7D7D8_func_8003BE70() __asm__("func_8003BE70");
int Level32_7D7D8_func_8003BEDC() __asm__("func_8003BEDC");
int Level32_7D7D8_func_8003BFC0() __asm__("func_8003BFC0");
int Level32_7D7D8_func_8003C140() __asm__("func_8003C140");
int Level32_7D7D8_func_8004E880() __asm__("func_8004E880");
int Level32_7D7D8_func_8004F178() __asm__("func_8004F178");
int Level32_7D7D8_func_8004F264() __asm__("func_8004F264");
int Level32_7D7D8_func_8004F334() __asm__("func_8004F334");
int Level32_7D7D8_func_800512E4() __asm__("func_800512E4");
int Level32_7D7D8_func_80055B18() __asm__("func_80055B18");
int Level32_7D7D8_func_80055D24() __asm__("func_80055D24");
int Level32_7D7D8_func_80055F14() __asm__("func_80055F14");
int Level32_7D7D8_func_8005629C() __asm__("func_8005629C");
extern int Level32_7D7D8_D_800658A0 __asm__("D_800658A0");
extern int Level32_7D7D8_D_80065920 __asm__("D_80065920");
extern int Level32_7D7D8_D_80066BC8 __asm__("D_80066BC8");
extern int Level32_7D7D8_D_800676E8 __asm__("D_800676E8");
extern int Level32_7D7D8_D_8006C550 __asm__("D_8006C550");
extern int Level32_7D7D8_D_8006C58C __asm__("D_8006C58C");
extern int Level32_7D7D8_D_8006C598 __asm__("D_8006C598");
extern int Level32_7D7D8_D_8006C5C8 __asm__("D_8006C5C8");
extern int Level32_7D7D8_D_8006C628 __asm__("D_8006C628");
extern int Level32_7D7D8_D_8006C640 __asm__("D_8006C640");
extern int Level32_7D7D8_D_8006C648 __asm__("D_8006C648");
extern int Level32_7D7D8_D_8006C650 __asm__("D_8006C650");
extern int Level32_7D7D8_D_8006C654 __asm__("D_8006C654");
extern int Level32_7D7D8_D_8006C700 __asm__("D_8006C700");
extern int Level32_7D7D8_D_8006C730 __asm__("D_8006C730");
extern int Level32_7D7D8_D_8006C770 __asm__("D_8006C770");
extern int Level32_7D7D8_D_8006C784 __asm__("D_8006C784");
extern int Level32_7D7D8_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level32_7D7D8_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level32_7D7D8_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level32_7D7D8_D_8006D088 __asm__("D_8006D088");
extern int Level32_7D7D8_D_8006E048 __asm__("D_8006E048");
extern int Level32_7D7D8_D_8006E160 __asm__("D_8006E160");
extern int Level32_7D7D8_D_8006E344 __asm__("D_8006E344");
extern int Level32_7D7D8_D_8006E538 __asm__("D_8006E538");
extern int Level32_7D7D8_D_8006EE2C __asm__("D_8006EE2C");
extern int Level32_7D7D8_D_80070328 __asm__("D_80070328");
extern int Level32_7D7D8_D_8007159A __asm__("D_8007159A");
extern int Level32_7D7D8_D_800716B0 __asm__("D_800716B0");
extern int Level32_7D7D8_D_800718D4 __asm__("D_800718D4");
extern int Level32_7D7D8_D_800719DC __asm__("D_800719DC");
extern int Level32_7D7D8_SpawnMoby __asm__("SpawnMoby");
extern int Level32_7D7D8_SpawnParticle __asm__("SpawnParticle");
extern int Level32_7D7D8_func_80027A60 __asm__("func_80027A60");
extern int Level32_7D7D8_func_80027D60 __asm__("func_80027D60");
extern int Level32_7D7D8_func_80027E40 __asm__("func_80027E40");
extern int Level32_7D7D8_func_80027EE4 __asm__("func_80027EE4");
extern int Level32_7D7D8_func_8002982C __asm__("func_8002982C");
extern int Level32_7D7D8_func_80029904 __asm__("func_80029904");
extern int Level32_7D7D8_func_80029AA0 __asm__("func_80029AA0");
extern int Level32_7D7D8_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level32_7D7D8_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level32_7D7D8_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
extern int Level32_7D7D8_unk_ovlheader_80074370 __asm__("unk_ovlheader_80074370");
extern int Level32_7D7D8_unk_ovlheader_80074394 __asm__("unk_ovlheader_80074394");
extern int Level32_7D7D8_unk_ovlheader_800743DC __asm__("unk_ovlheader_800743DC");
extern int Level32_7D7D8_unk_ovlheader_800743E8 __asm__("unk_ovlheader_800743E8");
extern int Level32_7D7D8_unk_ovlheader_80074440 __asm__("unk_ovlheader_80074440");
extern int Level32_7D7D8_unk_ovlheader_8007447C __asm__("unk_ovlheader_8007447C");
extern int Level32_7D7D8OriginalGlobalField0 __asm__("D_80070328+356");
int Level32_7D7D8TypedSound(int, int, int, int, int, void *, int) __asm__("func_8002803C");
void func_level_32_8007D7D8(void *ownerInput) {
    register int temporary2 __asm__("$2");
    register int temporary3 __asm__("$3");
    register int argument0 __asm__("$4");
    register int argument1 __asm__("$5");
    register int argument2 __asm__("$6");
    register int argument3 __asm__("$7");
    register int temporary8 __asm__("$8");
    register int temporary9 __asm__("$9");
    register int temporary10 __asm__("$10");
    register int temporary11 __asm__("$11");
    register int temporary12 __asm__("$12");
    register int temporary13 __asm__("$13");
    register int temporary14 __asm__("$14");
    register int temporary15 __asm__("$15");
    register int saved16 __asm__("$16");
    register int saved17 __asm__("$17");
    register int saved18 __asm__("$18");
    register int privateState __asm__("$19");
    register int saved20 __asm__("$20");
    register int saved21 __asm__("$21");
    register int owner __asm__("$22");
    register int saved23 __asm__("$23");
    register int temporary24 __asm__("$24");
    register int temporary25 __asm__("$25");
    int savedValue30, stackArgument4, stackArgument5, stackArgument6;
    struct {
        int sp20;
        int sp24;
        int sp28;
        int sp2C;
        int sp30;
        int sp34;
        int sp38;
        int sp3C;
        int sp40;
        int sp44;
        int sp48;
        int sp4C;
        int sp50;
        int sp54;
        int sp58;
        int sp5C;
        int sp60;
        int sp64;
        int sp68;
        int sp6C;
        int sp70;
        int sp74;
        int sp78;
        int sp7C;
        int sp80;
        int sp84;
    } locals;
    Level32_7D7D8Product wholeProduct92, wholeProduct1080, wholeProduct1102, wholeProduct1556,
        wholeProduct1567, wholeProduct1723, wholeProduct1763, wholeProduct1773, wholeProduct1781,
        wholeProduct1793, wholeProduct1801, wholeProduct1813, wholeProduct2475, wholeProduct2488,
        wholeProduct2540, wholeProduct2553, wholeProduct2689, wholeProduct2697, wholeProduct2705,
        wholeProduct2715, wholeProduct2723, wholeProduct2733;
    __asm__("" : "=m"(locals.sp78));
    owner = (int)ownerInput;
    Level32_7D7D8Keep(owner);
    argument0 = (int)ownerInput;
    privateState = Level32_7D7D8Field(owner, int *, 0);
    Level32_7D7D8Keep(privateState);

    temporary2 = Level32_7D7D8Field(privateState, int *, 96);
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)0x80070000U;
    Level32_7D7D8Keep(argument0);
    argument0 = Level32_7D7D8Field(argument0, int *, -15024);
    Level32_7D7D8Keep(argument0);
    temporary3 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 2);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 - temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 3);
    Level32_7D7D8Keep(temporary3);
    saved23 = argument0 + temporary3;
    Level32_7D7D8Keep(saved23);
    temporary10 = Level32_7D7D8Field(saved23, int *, 0);
    Level32_7D7D8Keep(temporary10);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14784);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field(&locals.sp20, int *, 80) = temporary10;
    if (temporary2 != 0)
        goto original3159_45;
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, -14412);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 32;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_45;
    temporary2 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary2);

    temporary3 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 2);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 - temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 3);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + argument0;
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, unsigned char *, 73) = temporary2;
original3159_45:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, 5530);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0 ? ({
            temporary3 = (int)0x00100000U;
            Level32_7D7D8Keep(temporary3);
            1;
        })
                        : ({
                              temporary3 = (int)0x00100000U;
                              Level32_7D7D8Keep(temporary3);
                              0;
                          }))
        goto original3159_54;
    argument0 = owner + 0;
    Level32_7D7D8_func_80055B18(argument0);

    goto original3159Return;
original3159_54:
    temporary2 = Level32_7D7D8Field(owner, int *, 24);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & temporary3;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 21, 1) : (temporary2 = 0 + 21, 0))
        goto original3159_157;
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);

    argument0 = owner + 0;
    if (temporary3 != temporary2)
        goto original3159_158;
    argument1 = privateState + 392;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 6;
    Level32_7D7D8Keep(argument2);
    argument3 = 0 + 5;
    Level32_7D7D8_func_80038BF8(argument0, argument1, argument2, argument3);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(privateState, int *, 460);
    Level32_7D7D8Keep(argument1);
    temporary2 = 0 + 120;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, unsigned char *, 414) = temporary2;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original3159_78;
    argument0 = Level32_7D7D8Field(privateState, int *, 460);

    Level32_7D7D8_func_8003BE70(argument0);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
original3159_78:
    argument1 = Level32_7D7D8Field(privateState, int *, 456);
    Level32_7D7D8Keep(argument1);
    saved16 = 0 + -1;
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Field(privateState, int *, 460) = saved16;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x66660000U;
    if (temporary2 == 0)
        goto original3159_88;
    __asm__ volatile("" ::);
    argument0 = Level32_7D7D8Field(privateState, int *, 456);

    Level32_7D7D8_func_8003BE70(argument0);
    temporary3 = (int)0x66660000U;
    Level32_7D7D8Keep(temporary3);
original3159_88:
    Level32_7D7D8Field(privateState, int *, 456) = saved16;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(privateState, int *, 456)) : "$2");
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 984);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 | 26215;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct92.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct92.full) : "0"(wholeProduct92.full));
    temporary2 = (temporary2 >> 31);
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=h"(projection) : "x"(wholeProduct92.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = (temporary10 >> 5);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 - temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(privateState, unsigned short *, 396);
    Level32_7D7D8Keep(temporary2);
    argument0 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(argument0);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 396) = temporary2;
    if (argument0 == 0)
        goto original3159_157;
    saved16 = Level32_7D7D8Field(argument0, int *, 0);
    Level32_7D7D8Keep(saved16);
    temporary2 = 0 + 30;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(argument0, unsigned char *, 73) = 0;
    Level32_7D7D8Field(saved16, short *, 14) = temporary2;
    temporary2 = 0 + 120;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, short *, 12) = temporary2;
    temporary2 = 0 + 12;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, short *, 18) = 0;
    Level32_7D7D8Field(saved16, short *, 16) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, unsigned char *, 409);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 10);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, int *, 0) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, unsigned char *, 409);
    Level32_7D7D8Keep(temporary2);
    argument1 = 0 + 4;
    Level32_7D7D8Keep(argument1);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 125;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, int *, 8) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 10);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, int *, 4) = temporary2;
    argument0 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(argument0);
    argument2 = 0 + 0;
    temporary2 = Level32_7D7D8_func_8003BABC(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    saved17 = 0 + -1;
    Level32_7D7D8Keep(saved17);
    Level32_7D7D8Field(saved16, short *, 22) = saved17;
    Level32_7D7D8Field(saved16, short *, 20) = saved17;
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, unsigned char *, 72) = temporary2;
    argument1 = Level32_7D7D8Field(saved16, short *, 20);
    Level32_7D7D8Keep(argument1);
    argument0 = owner + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_155;
    argument0 = Level32_7D7D8Field(saved16, short *, 20);

    Level32_7D7D8_func_8003BE70(argument0);
original3159_155:
    Level32_7D7D8Field(saved16, short *, 20) = saved17;
    Level32_7D7D8Field(privateState, int *, 132) = 0;
original3159_157:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);
original3159_158:

    Level32_7D7D8Field(owner, int *, 24) = 0;
    if (temporary3 == 0)
        goto original3159_170;
    temporary2 = 0 + 14;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = 0 + 20, 1) : (temporary2 = 0 + 20, 0))
        goto original3159_170;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original3159_170;
    temporary3 = Level32_7D7D8Field(privateState, int *, 452);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 != temporary2)
        goto original3159_222;
original3159_170:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, -14412);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 16;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0 ? (temporary2 = 0 + 20, 1) : (temporary2 = 0 + 20, 0))
        goto original3159_180;
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 != temporary2)
        goto original3159_222;
original3159_180:
    argument0 = 0 + 0;
    temporary2 = Level32_7D7D8_func_800369D8(argument0);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_222;
    saved18 = 0 + 0;
    Level32_7D7D8Keep(saved18);
    saved17 = privateState + 0;
    Level32_7D7D8Keep(saved17);
original3159_186:
    temporary3 = Level32_7D7D8Field(saved17, int *, 224);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -15024);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    saved16 = temporary3 + temporary2;
    Level32_7D7D8Keep(saved16);
    temporary2 = Level32_7D7D8Field(saved16, unsigned char *, 72);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (unsigned int)temporary2 < 128;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_216;
    temporary2 = Level32_7D7D8Field(saved16, int *, 0);
    Level32_7D7D8Keep(temporary2);

    argument0 = Level32_7D7D8Field(temporary2, int *, 64);
    Level32_7D7D8Keep(argument0);

    if (argument0 == 0)
        goto original3159_214;
    temporary2 = Level32_7D7D8Field(argument0, unsigned char *, 72);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (unsigned int)temporary2 < 128;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_214;

    Level32_7D7D8_func_80055B18(argument0);
original3159_214:
    argument0 = saved16 + 0;
    Level32_7D7D8_func_80055B18(argument0);
original3159_216:
    saved18 = saved18 + 1;
    Level32_7D7D8Keep(saved18);
    temporary2 = saved18 < 5;
    Level32_7D7D8Keep(temporary2);
    saved17 = saved17 + 4;
    if (temporary2 != 0)
        goto original3159_186;

    Level32_7D7D8_func_8003BEDC();
original3159_222:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + -20;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (unsigned int)temporary2 < 2;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_232;
    argument0 = 0 + 1;
    temporary2 = Level32_7D7D8_func_800369D8(argument0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C628, int *, 0) = temporary2;
original3159_232:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);

    switch ((unsigned int)temporary3) {
    case 0:
        goto original3159_695;
    case 1:
        goto original3159_2589;
    case 2:
        goto original3159_2589;
    case 3:
        goto original3159_2589;
    case 4:
        goto original3159_2589;
    case 5:
        goto original3159_1400;
    case 6:
        goto original3159_2589;
    case 7:
        goto original3159_2589;
    case 8:
        goto original3159_2589;
    case 9:
        goto original3159_2589;
    case 10:
        goto original3159_2589;
    case 11:
        goto original3159_2589;
    case 12:
        goto original3159_2589;
    case 13:
        goto original3159_2589;
    case 14:
        goto original3159_715;
    case 15:
        goto original3159_2589;
    case 16:
        goto original3159_2589;
    case 17:
        goto original3159_2589;
    case 18:
        goto original3159_2589;
    case 19:
        goto original3159_2589;
    case 20:
        goto original3159_1136;
    case 21:
        goto original3159_1400;
    case 22:
        goto original3159_2589;
    case 23:
        goto original3159_2589;
    case 24:
        goto original3159_2589;
    case 25:
        goto original3159_2589;
    case 26:
        goto original3159_2589;
    case 27:
        goto original3159_2589;
    case 28:
        goto original3159_2589;
    case 29:
        goto original3159_2589;
    case 30:
        goto original3159_782;
    case 31:
        goto original3159_982;
    case 32:
        goto original3159_2589;
    case 33:
        goto original3159_2589;
    case 34:
        goto original3159_2589;
    case 35:
        goto original3159_2589;
    case 36:
        goto original3159_2589;
    case 37:
        goto original3159_2589;
    case 38:
        goto original3159_2589;
    case 39:
        goto original3159_2589;
    case 40:
        goto original3159_2413;
    case 41:
        goto original3159_2498;
    case 42:
        goto original3159_2589;
    case 43:
        goto original3159_2589;
    case 44:
        goto original3159_2589;
    case 45:
        goto original3159_2589;
    case 46:
        goto original3159_2589;
    case 47:
        goto original3159_2589;
    case 48:
        goto original3159_2589;
    case 49:
        goto original3159_2589;
    case 50:
        goto original3159_243;
    case 51:
        goto original3159_2589;
    case 52:
        goto original3159_2589;
    case 53:
        goto original3159_2589;
    case 54:
        goto original3159_2589;
    case 55:
        goto original3159_2589;
    case 56:
        goto original3159_2589;
    case 57:
        goto original3159_2589;
    case 58:
        goto original3159_2589;
    case 59:
        goto original3159_2589;
    case 60:
        goto original3159_2589;
    case 61:
        goto original3159_2589;
    case 62:
        goto original3159_2589;
    case 63:
        goto original3159_2589;
    case 64:
        goto original3159_2589;
    case 65:
        goto original3159_2589;
    case 66:
        goto original3159_2589;
    case 67:
        goto original3159_2589;
    case 68:
        goto original3159_2589;
    case 69:
        goto original3159_2589;
    case 70:
        goto original3159_2589;
    case 71:
        goto original3159_2589;
    case 72:
        goto original3159_2589;
    case 73:
        goto original3159_2589;
    case 74:
        goto original3159_2589;
    case 75:
        goto original3159_2589;
    case 76:
        goto original3159_2589;
    case 77:
        goto original3159_2589;
    case 78:
        goto original3159_2589;
    case 79:
        goto original3159_2589;
    case 80:
        goto original3159_2589;
    case 81:
        goto original3159_2589;
    case 82:
        goto original3159_2589;
    case 83:
        goto original3159_2589;
    case 84:
        goto original3159_2589;
    case 85:
        goto original3159_2589;
    case 86:
        goto original3159_2589;
    case 87:
        goto original3159_2589;
    case 88:
        goto original3159_2589;
    case 89:
        goto original3159_2589;
    case 90:
        goto original3159_2589;
    case 91:
        goto original3159_2589;
    case 92:
        goto original3159_2589;
    case 93:
        goto original3159_2589;
    case 94:
        goto original3159_2589;
    case 95:
        goto original3159_2589;
    case 96:
        goto original3159_2589;
    case 97:
        goto original3159_2589;
    case 98:
        goto original3159_1400;
    default:
        goto original3159_2590;
    }
original3159_243:
    __asm__("" ::"r"(temporary3));
    temporary3 = Level32_7D7D8Field(privateState, int *, 452);
    Level32_7D7D8Keep(temporary3);
    saved16 = 0 + 1;
    Level32_7D7D8Keep(saved16);
    temporary2 = temporary3 < 2;
    if (temporary3 == saved16)
        goto original3159_364;
    if (temporary2 == 0)
        goto original3159_253;
    if (temporary3 == 0)
        goto original3159_260;

    goto original3159_2589;
original3159_253:
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original3159_371;
    if (temporary3 == temporary2) {
        temporary3 = (int)0x10000000U;
        goto original3159_614;
    }
    temporary3 = (int)0x10000000U;
    __asm__ volatile("" ::);

    goto original3159_2589;
original3159_260:
    temporary3 = (int)&Level32_7D7D8_D_800718D4;
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 6300, 1) : (temporary2 = 0 + 6300, 0))
        goto original3159_267;
    Level32_7D7D8Field(temporary3, int *, 0) = temporary2;
original3159_267:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 76);
    Level32_7D7D8Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original3159_279;
    argument1 = 0 + 0;
    temporary2 = Level32_7D7D8_func_80037BBC(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original3159_279;
    argument1 = 0 + 0;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 14;
    Level32_7D7D8_func_800512E4(argument0, argument1, argument2);
    Level32_7D7D8Field(privateState, int *, 452) = saved16;
original3159_279:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -7840);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 19, 1) : (temporary2 = 0 + 19, 0))
        goto original3159_2589;
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 888);
    Level32_7D7D8Keep(temporary3);

    saved16 = 0 + -1;
    if (temporary3 != temporary2)
        goto original3159_2589;
    saved17 = 0 + 1;
    Level32_7D7D8Keep(saved17);
    temporary2 = Level32_7D7D8Field(privateState, int *, 160);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 164) = 0;
    Level32_7D7D8Field(privateState, int *, 168) = saved17;
    Level32_7D7D8Field(privateState, short *, 308) = 0;
    Level32_7D7D8Field(privateState, int *, 416) = 0;
    Level32_7D7D8Field(privateState, int *, 448) = 0;
    Level32_7D7D8Field(privateState, int *, 264) = saved17;
    if (temporary2 != saved16)
        goto original3159_313;
    argument0 = 0 + 50;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 3;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = 0 + 0;
    Level32_7D7D8Keep(argument3);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 17264);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3, temporary3,
                                             (privateState + 448), (0 | 35940));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 160) = temporary2;
original3159_313:
    temporary2 = Level32_7D7D8Field(privateState, int *, 108);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 17;
    if (temporary2 != saved16)
        goto original3159_333;
    temporary2 = Level32_7D7D8TypedSound(
        argument0, 321, Level32_7D7D8_unk_ovlheader_80074368, Level32_7D7D8_unk_ovlheader_8007436C,
        Level32_7D7D8_unk_ovlheader_80074364, (void *)(privateState + 164), 900);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 108) = temporary2;
original3159_333:
    temporary2 = Level32_7D7D8Field(privateState, int *, 112);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 21;
    if (temporary2 != saved16)
        goto original3159_353;
    argument1 = 0 + 2000;
    Level32_7D7D8Keep(argument1);
    argument2 = (int)&Level32_7D7D8_func_80027EE4;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)&Level32_7D7D8_func_80027A60;
    Level32_7D7D8Keep(argument3);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3,
                                             ((int)&Level32_7D7D8_func_80029AA0),
                                             (privateState + 264), (0 + 3));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 112) = temporary2;
original3159_353:
    temporary10 = Level32_7D7D8Field(&locals.sp20, volatile int *, 80);
    Level32_7D7D8Keep(temporary10);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17472);
    Level32_7D7D8Keep(temporary2);
    argument0 = temporary10 + 100;
    Level32_7D7D8Keep(argument0);
    Level32_7D7D8Field(temporary10, int *, 140) = saved17;
    ((int (*)())temporary2)(argument0);
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C650, int *, 0) = saved17;
    Level32_7D7D8Field(privateState, int *, 452) = temporary2;
    goto original3159_2589;
original3159_364:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -7356);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == temporary3)
        goto original3159_2589;
    Level32_7D7D8Field(privateState, int *, 452) = 0;
    goto original3159_2589;
original3159_371:
    saved17 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(saved17);

    temporary3 = Level32_7D7D8Field(saved17, short *, 0);
    Level32_7D7D8Keep(temporary3);
    saved16 = Level32_7D7D8Field(privateState, int *, 220);
    Level32_7D7D8Keep(saved16);
    temporary2 = temporary3 + 1;
    Level32_7D7D8Keep(temporary2);
    temporary2 = saved16 + temporary2;
    Level32_7D7D8Keep(temporary2);
    saved20 = temporary2 % temporary3;
    Level32_7D7D8Keep(saved20);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    saved16 = (int)((unsigned int)saved16 << 4);
    Level32_7D7D8Keep(saved16);
    temporary3 = Level32_7D7D8Field(saved17, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)saved20 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = saved16 + temporary3;
    Level32_7D7D8Keep(temporary3);
    argument3 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument3);
    argument0 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(temporary3, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)&locals.sp20;
    Level32_7D7D8Keep(argument0);
    argument1 = (int)&Level32_7D7D8_D_80070328;
    Level32_7D7D8Keep(argument1);
    saved18 = temporary2 + 0;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = Level32_7D7D8Field(saved17, int *, 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 0);
    Level32_7D7D8Keep(temporary3);
    saved16 = saved16 + temporary2;
    Level32_7D7D8Keep(saved16);
    argument0 = Level32_7D7D8Field(saved16, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 4);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(saved16, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = temporary3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = saved18 & 255;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 & 255;
    temporary2 = Level32_7D7D8_func_8004F264(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 64;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 179, 1) : (temporary2 = 0 + 179, 0))
        goto original3159_428;
    Level32_7D7D8Field(privateState, int *, 220) = saved20;
    if (saved20 != temporary2)
        goto original3159_428;
    temporary2 = Level32_7D7D8Field(privateState, int *, 264);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 264) = temporary2;
original3159_428:
    temporary2 = Level32_7D7D8Field(privateState, int *, 448);
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)0x80070000U;
    Level32_7D7D8Keep(argument0);
    argument0 = Level32_7D7D8Field(argument0, int *, -14776);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(privateState, int *, 264);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 + argument0;
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 < 4;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(privateState, int *, 448) = temporary2;
    if (temporary3 != 0)
        goto original3159_544;
    argument0 = Level32_7D7D8Field(privateState, int *, 160);
    Level32_7D7D8Keep(argument0);
    saved16 = 0 + -1;
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(privateState, int *, 452) = 0;
    if (argument0 == saved16)
        goto original3159_442;

    Level32_7D7D8_func_80028154(argument0);
original3159_442:
    argument0 = Level32_7D7D8Field(privateState, int *, 108);
    Level32_7D7D8Keep(argument0);

    Level32_7D7D8Field(privateState, int *, 160) = saved16;
    if (argument0 == saved16)
        goto original3159_448;

    Level32_7D7D8_func_80028154(argument0);
original3159_448:
    argument0 = Level32_7D7D8Field(privateState, int *, 112);
    Level32_7D7D8Keep(argument0);

    Level32_7D7D8Field(privateState, int *, 108) = saved16;
    if (argument0 == saved16)
        goto original3159_454;

    Level32_7D7D8_func_80028154(argument0);
original3159_454:
    temporary3 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary3);
    argument0 = (int)&locals.sp20;
    Level32_7D7D8Keep(argument0);
    Level32_7D7D8Field(privateState, int *, 112) = saved16;
    saved16 = (int)0x80070000U;
    Level32_7D7D8Keep(saved16);
    saved16 = Level32_7D7D8Field(saved16, int *, -15024);
    Level32_7D7D8Keep(saved16);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    saved16 = saved16 + temporary2;
    Level32_7D7D8Keep(saved16);
    argument1 = saved16 + 12;
    Level32_7D7D8Keep(argument1);
    Level32_7D7D8Field(saved16, unsigned char *, 73) = 0;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(saved16, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 0) = temporary3;
    temporary2 = Level32_7D7D8Field(saved16, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);
    saved18 = (int)&Level32_7D7D8_D_8006D088;
    Level32_7D7D8Keep(saved18);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);
    argument0 = saved18 + 0;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 4);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 4) = temporary3;
    argument2 = Level32_7D7D8Field(saved16, unsigned char *, 70);
    Level32_7D7D8Keep(argument2);
    argument1 = (int)&locals.sp20;
    Level32_7D7D8_func_8003B634(argument0, argument1, argument2);
    saved16 = privateState + 448;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 4;
    Level32_7D7D8Keep(argument1);
    argument2 = saved18 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = 0 + 4;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved23, unsigned char *, 72) = 0;
    Level32_7D7D8Field(privateState, int *, 452) = temporary2;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 4;
    Level32_7D7D8Keep(argument1);
    saved17 = (int)&Level32_7D7D8_D_8006C7F8;
    Level32_7D7D8Keep(saved17);
    argument2 = saved17 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    saved16 = privateState + 452;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 4;
    Level32_7D7D8Keep(argument1);
    argument2 = saved18 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 4;
    Level32_7D7D8Keep(argument1);
    argument2 = saved17 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    saved16 = owner + 72;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    argument2 = saved18 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    argument2 = saved17 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved18 + 0;
    goto original3159_609;
original3159_544:
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14768);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2589;
    saved18 = (int)&locals.sp30;
    Level32_7D7D8Keep(saved18);
    temporary3 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary3);
    saved16 = (int)0x80070000U;
    Level32_7D7D8Keep(saved16);
    saved16 = Level32_7D7D8Field(saved16, int *, -15024);
    Level32_7D7D8Keep(saved16);
    argument0 = saved18 + 0;
    Level32_7D7D8Keep(argument0);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C650, int *, 0) = 0;
    __asm__ volatile("" ::: "memory", "$2");
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    saved16 = saved16 + temporary2;
    Level32_7D7D8Keep(saved16);
    argument1 = saved16 + 12;
    Level32_7D7D8Keep(argument1);
    Level32_7D7D8Field(saved16, unsigned char *, 73) = 0;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(saved16, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 16);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 16) = temporary3;
    temporary2 = Level32_7D7D8Field(saved16, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);
    saved17 = (int)&Level32_7D7D8_D_8006D088;
    Level32_7D7D8Keep(saved17);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);
    argument0 = saved17 + 0;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 20);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 20) = temporary3;
    argument2 = Level32_7D7D8Field(saved16, unsigned char *, 70);
    Level32_7D7D8Keep(argument2);
    argument1 = saved18 + 0;
    Level32_7D7D8_func_8003B634(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level32_7D7D8Keep(argument0);
    Level32_7D7D8Field(saved23, unsigned char *, 72) = 0;
original3159_609:

    Level32_7D7D8_func_8003B74C(argument0);
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 452) = temporary2;
    goto original3159Return;
original3159_614:
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 | 2;
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -7356);
    Level32_7D7D8Keep(temporary2);
    saved17 = (int)&Level32_7D7D8_D_80070328 + 524;
    Level32_7D7D8Keep(saved17);
    Level32_7D7D8Field(saved17, int *, 0) = temporary3;
    if (temporary2 != 0)
        goto original3159_2589;
    temporary3 = (int)&Level32_7D7D8_D_80066BC8 + 10;
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 0);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 1;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_687;
    temporary2 = Level32_7D7D8Field(privateState, int *, 448);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 < 6301;
    Level32_7D7D8Keep(temporary2);
    argument1 = owner + 0;
    if (temporary2 == 0)
        goto original3159_687;
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, unsigned char *, 0) = temporary2;
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14764);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_800719DC, short *, 0) = temporary2;
    argument0 = Level32_7D7D8Field(temporary3, unsigned char *, 35);
    Level32_7D7D8Keep(argument0);
    argument2 = 0 + 161;
    temporary2 = Level32_7D7D8_PlaySound(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = 0 + 211;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17120);
    Level32_7D7D8Keep(temporary2);

    argument1 = owner + 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    saved16 = temporary2 + 0;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 12;
    if (saved16 == 0)
        goto original3159_687;
    argument1 = saved17 + -524;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, 822);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(saved16, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 7);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(saved16, int *, 12) = temporary3;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(saved16, int *, 12)) : "$2");
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, 822);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(saved16, int *, 20);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    argument0 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(argument0);
    temporary3 = temporary3 + 500;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(saved16, int *, 20) = temporary3;
    temporary3 = Level32_7D7D8Field(saved16, int *, 16);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)argument0 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + argument0;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + argument0;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 7);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(saved16, int *, 16) = temporary3;
original3159_687:
    __asm__ volatile("" ::"r"(temporary2));
    argument0 = Level32_7D7D8Field(privateState, int *, 448);
    Level32_7D7D8Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$2");
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17532);

    ((int (*)())temporary2)(argument0);
    Level32_7D7D8Field(privateState, int *, 452) = 0;
    goto original3159_2589;
original3159_695:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, -14412);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 32;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 50, 1) : (temporary2 = 0 + 50, 0))
        goto original3159_704;
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    Level32_7D7D8Field(privateState, int *, 452) = 0;
    goto original3159Return;
original3159_704:
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level32_7D7D8_func_80037BBC(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument1 = 0 + 0;
    if (temporary2 == 0)
        goto original3159_2589;
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument2 = 0 + 14;
    Level32_7D7D8_func_800512E4(argument0, argument1, argument2);
    temporary2 = 0 + 14;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    goto original3159_2589;
original3159_715:
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -7356);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original3159_2589;
    temporary3 = Level32_7D7D8Field(privateState, unsigned char *, 4);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 5, 1) : (temporary2 = 0 + 5, 0))
        goto original3159_726;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 9, 1) : (temporary2 = 0 + 9, 0))
        goto original3159_746;
original3159_726:
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(owner, unsigned char *, 73)) : "$2");
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14964);
    Level32_7D7D8Keep(temporary2);

    temporary3 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary3);

    argument0 =
        Level32_7D7D8Field(((int)&Level32_7D7D8_D_800716B0 + temporary3), unsigned char *, 0);
    Level32_7D7D8Keep(argument0);

    temporary2 = (unsigned int)argument0 < 255;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = argument0 + 1, 1) : (temporary2 = argument0 + 1, 0))
        goto original3159_743;

    Level32_7D7D8Field(((int)&Level32_7D7D8_D_800716B0 + temporary3), unsigned char *, 0) =
        temporary2;
original3159_743:
    temporary2 = 0 + 30;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    goto original3159Return;
original3159_746:
    if (temporary3 == temporary2 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original3159_750;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 7, 1) : (temporary2 = 0 + 7, 0))
        goto original3159_770;
original3159_750:
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(owner, unsigned char *, 73)) : "$2");
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14964);
    Level32_7D7D8Keep(temporary2);

    temporary3 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary3);

    argument0 =
        Level32_7D7D8Field(((int)&Level32_7D7D8_D_800716B0 + 1 + temporary3), unsigned char *, 0);
    Level32_7D7D8Keep(argument0);

    temporary2 = (unsigned int)argument0 < 255;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = argument0 + 1, 1) : (temporary2 = argument0 + 1, 0))
        goto original3159_767;

    Level32_7D7D8Field(((int)&Level32_7D7D8_D_800716B0 + 1 + temporary3), unsigned char *, 0) =
        temporary2;
original3159_767:
    temporary2 = 0 + 20;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    goto original3159Return;
original3159_770:
    temporary3 = Level32_7D7D8Field(privateState, unsigned char *, 4);
    Level32_7D7D8Keep(temporary3);

    Level32_7D7D8Field(privateState, unsigned char *, 5) = 0;
    if (temporary3 != temporary2)
        goto original3159_776;
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, unsigned char *, 5) = temporary2;
original3159_776:
    Level32_7D7D8Field(owner, unsigned char *, 72) = 0;
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 0;
    Level32_7D7D8_func_80034F40(argument0, argument1);

    goto original3159_2589;
original3159_782:
    temporary3 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary3);
    saved16 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(saved16);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -15024);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    saved17 = temporary3 + temporary2;
    Level32_7D7D8Keep(saved17);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    if (saved16 == temporary2 ? (temporary2 = saved16 < 2, 1) : (temporary2 = saved16 < 2, 0))
        goto original3159_847;
    if (temporary2 == 0)
        goto original3159_801;
    argument0 = (int)&locals.sp20;
    if (saved16 == 0)
        goto original3159_806;

    goto original3159_2589;
original3159_801:
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    argument0 = 0 + 0;
    if (saved16 == temporary2)
        goto original3159_870;

    goto original3159_2589;
original3159_806:
    Level32_7D7D8Keep(saved16);
    argument1 = saved17 + 12;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 0) = temporary3;
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)&locals.sp20;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 4);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 4) = temporary3;
original3159_842:
    argument1 = Level32_7D7D8Field(saved17, unsigned char *, 70);
    Level32_7D7D8Keep(argument1);
    argument3 = 0 + 0;
    Level32_7D7D8_func_80013D44(argument0, argument1, argument2, argument3);

    goto original3159_1378;
original3159_847:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -8120);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 1;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2589;
    argument0 = 0 + 0;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17372);
    Level32_7D7D8Keep(temporary2);

    argument1 = 0 + 20;
    ((int (*)())temporary2)(argument0, argument1);
    Level32_7D7D8Field(saved17, unsigned char *, 73) = 0;
    temporary10 = Level32_7D7D8Field(&locals.sp20, volatile int *, 80);
    Level32_7D7D8Keep(temporary10);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17472);
    Level32_7D7D8Keep(temporary2);
    argument0 = temporary10 + 100;
    Level32_7D7D8Keep(argument0);
    Level32_7D7D8Field(temporary10, int *, 140) = saved16;
    ((int (*)())temporary2)(argument0);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C650, int *, 0) = saved16;

    goto original3159_1378;
original3159_870:
    argument2 = 0 + 180;
    Level32_7D7D8Keep(argument2);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    temporary3 = privateState + 0;
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 140) = temporary2;
    Level32_7D7D8Field(privateState, short *, 142) = temporary2;
    temporary2 = 0 + 60;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 144) = temporary2;
    temporary2 = 0 + 50;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 146) = temporary2;
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 154) = temporary2;
    Level32_7D7D8Field(privateState, int *, 156) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
original3159_884:
    Level32_7D7D8Field(temporary3, int *, 200) = argument2;
    Level32_7D7D8Field(temporary3, int *, 244) = argument1;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(temporary3, int *, 244)), "r"(argument0));
    argument0 = argument0 + 1;
    Level32_7D7D8Keep(argument0);
    temporary2 = argument0 < 6;
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + 4;
    if (temporary2 != 0)
        goto original3159_884;
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 168) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 220);
    Level32_7D7D8Keep(temporary2);
    saved17 = 0 + 5;
    Level32_7D7D8Keep(saved17);
    temporary2 = temporary2 + -1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 220) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 160);
    Level32_7D7D8Keep(temporary2);
    saved16 = 0 + -1;
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Field(privateState, short *, 182) = 0;
    Level32_7D7D8Field(privateState, int *, 164) = 0;
    Level32_7D7D8Field(privateState, short *, 308) = 0;
    Level32_7D7D8Field(privateState, int *, 304) = saved17;
    Level32_7D7D8Field(privateState, int *, 416) = 0;
    if (temporary2 != saved16)
        goto original3159_919;
    argument0 = 0 + 50;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 3;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = 0 + 0;
    Level32_7D7D8Keep(argument3);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 17264);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3, temporary3,
                                             (privateState + 448), (0 | 35940));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 160) = temporary2;
original3159_919:
    temporary2 = Level32_7D7D8Field(privateState, int *, 108);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 17;
    if (temporary2 != saved16)
        goto original3159_939;
    temporary2 = Level32_7D7D8TypedSound(
        argument0, 321, Level32_7D7D8_unk_ovlheader_80074368, Level32_7D7D8_unk_ovlheader_8007436C,
        Level32_7D7D8_unk_ovlheader_80074364, (void *)(privateState + 164), 900);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 108) = temporary2;
original3159_939:
    temporary2 = Level32_7D7D8Field(privateState, int *, 112);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 21;
    if (temporary2 != saved16)
        goto original3159_959;
    argument1 = 0 + 2000;
    Level32_7D7D8Keep(argument1);
    argument2 = (int)&Level32_7D7D8_func_80027EE4;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)&Level32_7D7D8_func_80027A60;
    Level32_7D7D8Keep(argument3);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3,
                                             ((int)&Level32_7D7D8_func_80029AA0),
                                             (privateState + 264), (0 + 3));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 112) = temporary2;
original3159_959:
    temporary2 = Level32_7D7D8Field(privateState, int *, 116);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != saved16 ? (temporary2 = 0 + 31, 1) : (temporary2 = 0 + 31, 0))
        goto original3159_980;
    argument0 = 0 + 23;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 2001;
    Level32_7D7D8Keep(argument1);
    argument2 = (int)&Level32_7D7D8_func_80027D60;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)0x80070000U;
    Level32_7D7D8Keep(argument3);
    argument3 = Level32_7D7D8Field(argument3, int *, 17300);
    Level32_7D7D8Keep(argument3);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3,
                                             ((int)&Level32_7D7D8_func_8002982C),
                                             (privateState + 304), saved17);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 116) = temporary2;
    temporary2 = 0 + 31;
    Level32_7D7D8Keep(temporary2);
original3159_980:
    __asm__ volatile("" ::"r"(temporary2), "r"(owner));
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    goto original3159_2589;
original3159_982:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(temporary2);

    saved16 = privateState + 0;
    if (temporary2 != 0)
        goto original3159_2589;
original3159_986:
    saved18 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(saved18);

    temporary3 = Level32_7D7D8Field(saved18, short *, 0);
    Level32_7D7D8Keep(temporary3);
    saved17 = Level32_7D7D8Field(saved16, int *, 200);
    Level32_7D7D8Keep(saved17);
    temporary2 = temporary3 + 1;
    Level32_7D7D8Keep(temporary2);
    temporary2 = saved17 + temporary2;
    Level32_7D7D8Keep(temporary2);
    saved20 = temporary2 % temporary3;
    Level32_7D7D8Keep(saved20);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument0 = Level32_7D7D8Field(saved18, int *, 12);
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)saved17 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + argument0;
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(argument1);
    temporary3 = (int)((unsigned int)saved20 << 4);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + argument0;
    Level32_7D7D8Keep(temporary3);
    argument3 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(argument3);
    argument0 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 4);
    Level32_7D7D8Keep(temporary3);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    saved21 = temporary2 + 0;
    Level32_7D7D8Keep(saved21);
    temporary2 = privateState + 20;
    Level32_7D7D8Keep(temporary2);
    temporary2 = saved16 < temporary2;
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)&locals.sp20;
    if (temporary2 == 0)
        goto original3159_1032;
    temporary2 = Level32_7D7D8Field(saved16, int *, 224);
    Level32_7D7D8Keep(temporary2);
    argument1 = (int)0x80070000U;
    Level32_7D7D8Keep(argument1);
    argument1 = Level32_7D7D8Field(argument1, int *, -15024);
    Level32_7D7D8Keep(argument1);
    temporary3 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 2);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 - temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 3);
    Level32_7D7D8Keep(temporary3);
    argument1 = argument1 + temporary3;
    Level32_7D7D8Keep(argument1);
    argument1 = argument1 + 12;
    goto original3159_1034;
original3159_1032:
    argument1 = (int)&Level32_7D7D8_D_80070328;
    Level32_7D7D8Keep(argument1);
original3159_1034:

    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = (int)((unsigned int)saved17 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(saved18, int *, 12);
    Level32_7D7D8Keep(temporary3);
    argument3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 0);
    Level32_7D7D8Keep(argument3);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    argument0 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 4);
    Level32_7D7D8Keep(temporary3);
    argument1 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = saved21 & 255;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 & 255;
    temporary2 = Level32_7D7D8_func_8004F264(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 64;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 179, 1) : (temporary2 = 0 + 179, 0))
        goto original3159_1059;
    Level32_7D7D8Field(saved16, int *, 200) = saved20;
    if (saved20 != temporary2)
        goto original3159_1059;
    temporary2 = Level32_7D7D8Field(saved16, int *, 244);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, int *, 244) = temporary2;
original3159_1059:
    saved16 = saved16 + 4;
    Level32_7D7D8Keep(saved16);
    temporary2 = privateState + 24;
    Level32_7D7D8Keep(temporary2);
    temporary2 = saved16 < temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary8 = 0 + 0;
    if (temporary2 != 0)
        goto original3159_986;
    temporary9 = (int)0x00980000U;
    Level32_7D7D8Keep(temporary9);
    argument1 = Level32_7D7D8Field(privateState, int *, 220);
    Level32_7D7D8Keep(argument1);

    temporary2 = argument1 < 179;
    Level32_7D7D8Keep(temporary2);
    temporary9 = temporary9 | 38527;
    if (temporary2 != 0)
        goto original3159_1075;
    temporary2 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    argument1 = argument1 - temporary2;
    Level32_7D7D8Keep(argument1);
original3159_1075:
    Level32_7D7D8Keep(temporary8);
    temporary2 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(privateState, int *, 264);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct1080.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct1080.full) : "0"(wholeProduct1080.full));
    argument3 = 0 + 0;
    Level32_7D7D8Keep(argument3);
    argument2 = privateState + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = argument1 + -179;
    Level32_7D7D8Keep(temporary2);
    argument1 = temporary2 + temporary3;
    Level32_7D7D8Keep(argument1);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1080.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    argument1 = argument1 + temporary10;
    Level32_7D7D8Keep(argument1);
original3159_1087:
    argument0 = Level32_7D7D8Field(argument2, int *, 200);
    Level32_7D7D8Keep(argument0);

    temporary2 = argument0 < 179;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_1097;
    temporary2 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    argument0 = argument0 - temporary2;
    Level32_7D7D8Keep(argument0);
original3159_1097:
    temporary2 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(argument2, int *, 244);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct1102.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct1102.full) : "0"(wholeProduct1102.full));
    temporary2 = argument0 + -179;
    Level32_7D7D8Keep(temporary2);
    argument0 = temporary2 + temporary3;
    Level32_7D7D8Keep(argument0);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1102.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    argument0 = argument0 + temporary10;
    Level32_7D7D8Keep(argument0);
    temporary2 = argument1 < argument0;
    Level32_7D7D8Keep(temporary2);
    temporary3 = argument0 - argument1;
    if (temporary2 == 0)
        goto original3159_1118;
    temporary2 = temporary3 < temporary9;
    if (temporary3 >= 0)
        goto original3159_1114;
    temporary3 = argument1 - argument0;
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary3 < temporary9;
    Level32_7D7D8Keep(temporary2);
original3159_1114:
    if (temporary2 == 0)
        goto original3159_1117;
    temporary9 = temporary3 + 0;
    Level32_7D7D8Keep(temporary9);
original3159_1117:
    temporary8 = temporary8 + 1;
    Level32_7D7D8Keep(temporary8);
original3159_1118:
    argument3 = argument3 + 1;
    Level32_7D7D8Keep(argument3);
    temporary2 = argument3 < 5;
    Level32_7D7D8Keep(temporary2);
    argument2 = argument2 + 4;
    if (temporary2 != 0)
        goto original3159_1087;
    temporary2 = Level32_7D7D8Field(privateState, int *, 304);
    Level32_7D7D8Keep(temporary2);

    if (temporary8 == temporary2 ? (temporary2 = temporary9 < 2, 1)
                                 : (temporary2 = temporary9 < 2, 0))
        goto original3159_1129;
    if (temporary2 != 0)
        goto original3159_1129;
    Level32_7D7D8Field(privateState, int *, 304) = temporary8;
original3159_1129:
    temporary2 = Level32_7D7D8Field(privateState, int *, 264);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 < 4;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0 ? (temporary2 = 0 + 40, 1) : (temporary2 = 0 + 40, 0))
        goto original3159_2589;
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
    goto original3159_1596;
original3159_1136:
    argument0 = Level32_7D7D8Field(privateState, int *, 328);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 179;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 324) = argument0;
    Level32_7D7D8Field(argument0, short *, 2) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)&locals.sp20;
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -15024);
    Level32_7D7D8Keep(temporary3);
    argument1 = argument1 + 2864;
    Level32_7D7D8Keep(argument1);
    saved17 = temporary3 + temporary2;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = Level32_7D7D8Field(temporary2, int *, 16);
    Level32_7D7D8Keep(argument3);
    argument0 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(temporary2, int *, 20);
    Level32_7D7D8Keep(temporary3);
    argument1 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    saved16 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(saved16);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    if (saved16 == temporary2 ? (temporary2 = saved16 < 2, 1) : (temporary2 = saved16 < 2, 0))
        goto original3159_1218;
    if (temporary2 == 0)
        goto original3159_1175;
    if (saved16 == 0 ? (saved16 = (int)&locals.sp40, 1) : (saved16 = (int)&locals.sp40, 0))
        goto original3159_1180;
    __asm__ volatile("" ::);

    goto original3159_2589;
original3159_1175:
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    if (saved16 == temporary2 ? (temporary2 = 0 + 300, 1) : (temporary2 = 0 + 300, 0))
        goto original3159_1383;
    __asm__ volatile("" ::);

    goto original3159_2589;
original3159_1180:
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = saved17 + 12;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 32);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 32) = temporary3;
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary3);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 36);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(&locals.sp20, int *, 36) = temporary3;
    goto original3159_842;
original3159_1218:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -8120);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 1;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2589;
    argument0 = owner + 12;
    Level32_7D7D8Keep(argument0);
    argument1 = (int)&locals.sp20;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(owner, short *, 56);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(owner, int *, 20);
    Level32_7D7D8Keep(temporary2);
    argument1 = 0 + 2;
    Level32_7D7D8Keep(argument1);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, int *, 20) = temporary2;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    temporary3 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary3);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = Level32_7D7D8Field(temporary3, short *, 2);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    argument3 = Level32_7D7D8Field(temporary2, int *, 16);
    Level32_7D7D8Keep(argument3);
    argument0 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(temporary2, int *, 20);
    Level32_7D7D8Keep(temporary3);
    argument1 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = 0 + 50;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 3;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = 0 + 0;
    Level32_7D7D8Keep(argument3);
    Level32_7D7D8Field(owner, unsigned char *, 70) = temporary2;
    Level32_7D7D8Field(saved17, unsigned char *, 73) = 0;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(owner, unsigned char *, 70)),
                     "m"(Level32_7D7D8Field(saved17, unsigned char *, 73))
                     : "$3");
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 17264);
    __asm__ volatile("" ::: "memory", "$2");
    temporary2 = 0 + 180;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 200) = temporary2;
    temporary2 = 0 + 179;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 220) = temporary2;
    temporary2 = privateState + 448;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 244) = saved16;
    Level32_7D7D8Field(privateState, int *, 264) = saved16;
    Level32_7D7D8Field(privateState, short *, 182) = 0;
    Level32_7D7D8Field(privateState, int *, 164) = 0;
    Level32_7D7D8Field(privateState, int *, 168) = saved16;
    Level32_7D7D8Field(privateState, short *, 308) = 0;
    Level32_7D7D8Field(privateState, int *, 304) = saved16;
    Level32_7D7D8Field(privateState, int *, 416) = 0;
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3, temporary3,
                                             (temporary2), (0 | 35940));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 160) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 108);
    Level32_7D7D8Keep(temporary2);
    saved17 = 0 + -1;
    Level32_7D7D8Keep(saved17);
    argument0 = 0 + 17;
    if (temporary2 != saved17)
        goto original3159_1296;
    temporary2 = Level32_7D7D8TypedSound(
        argument0, 321, Level32_7D7D8_unk_ovlheader_80074368, Level32_7D7D8_unk_ovlheader_8007436C,
        Level32_7D7D8_unk_ovlheader_80074364, (void *)(privateState + 164), 900);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 108) = temporary2;
original3159_1296:
    temporary2 = Level32_7D7D8Field(privateState, int *, 112);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 21;
    if (temporary2 != saved17)
        goto original3159_1316;
    argument1 = 0 + 2000;
    Level32_7D7D8Keep(argument1);
    argument2 = (int)&Level32_7D7D8_func_80027EE4;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)&Level32_7D7D8_func_80027A60;
    Level32_7D7D8Keep(argument3);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3,
                                             ((int)&Level32_7D7D8_func_80029AA0),
                                             (privateState + 264), (0 + 3));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 112) = temporary2;
original3159_1316:
    temporary2 = Level32_7D7D8Field(privateState, int *, 116);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 23;
    if (temporary2 != saved17)
        goto original3159_1336;
    argument1 = 0 + 2001;
    Level32_7D7D8Keep(argument1);
    argument2 = (int)&Level32_7D7D8_func_80027D60;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)0x80070000U;
    Level32_7D7D8Keep(argument3);
    argument3 = Level32_7D7D8Field(argument3, int *, 17300);
    Level32_7D7D8Keep(argument3);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3,
                                             ((int)&Level32_7D7D8_func_8002982C),
                                             (privateState + 304), (0 + 5));
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 116) = temporary2;
original3159_1336:
    temporary2 = Level32_7D7D8Field(privateState, int *, 120);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 22;
    if (temporary2 != saved17)
        goto original3159_1358;
    argument1 = 0 + 322;
    Level32_7D7D8Keep(argument1);
    argument2 = (int)&Level32_7D7D8_func_80027E40;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)&Level32_7D7D8_func_80027A60;
    Level32_7D7D8Keep(argument3);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14808);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8_func_8002803C(argument0, argument1, argument2, argument3,
                                             ((int)&Level32_7D7D8_func_80029904),
                                             ((int)&Level32_7D7D8_D_8006C628), temporary3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 120) = temporary2;
original3159_1358:
    temporary10 = Level32_7D7D8Field(&locals.sp20, volatile int *, 80);
    Level32_7D7D8Keep(temporary10);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17472);
    Level32_7D7D8Keep(temporary2);
    argument0 = temporary10 + 100;
    Level32_7D7D8Keep(argument0);
    Level32_7D7D8Field(temporary10, int *, 140) = saved16;
    ((int (*)())temporary2)(argument0);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C650, int *, 0) = saved16;
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 61);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original3159_1378;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 61) = temporary2;
    Level32_7D7D8Field(owner, unsigned char *, 63) = 0;
    Level32_7D7D8_func_80035734(argument0);
original3159_1378:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 73) = temporary2;
    goto original3159_2589;
original3159_1383:
    Level32_7D7D8Field(privateState, int *, 312) = temporary2;
    Level32_7D7D8Field(privateState, int *, 316) = temporary2;
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 140) = temporary2;
    Level32_7D7D8Field(privateState, short *, 142) = temporary2;
    temporary2 = 0 + 40;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 146) = temporary2;
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 154) = temporary2;
    Level32_7D7D8Field(privateState, int *, 156) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
    temporary2 = Level32_7D7D8Field(privateState, int *, 312);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field(privateState, short *, 144) = temporary2;
    temporary2 = 0 + 21;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    goto original3159_2589;
original3159_1400:
    temporary2 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary2);
    savedValue30 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(savedValue30);
    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original3159_1456;
    argument0 = 0 + 623;
    Level32_7D7D8Keep(argument0);
    temporary2 = 0 + 6;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 71) = temporary2;
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17120);
    Level32_7D7D8Keep(temporary2);

    argument1 = owner + 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 132) = temporary2;
    if (temporary2 == 0)
        goto original3159_1470;
    temporary3 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, short *, 22) = temporary2;
    Level32_7D7D8Field(temporary3, short *, 20) = temporary2;
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, unsigned char *, 71) = temporary2;
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 63;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, unsigned char *, 76) = temporary2;
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);

    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 76);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field(temporary3, unsigned char *, 78) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = Level32_7D7D8Field(temporary2, int *, 16);
    Level32_7D7D8Keep(argument3);
    argument0 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(temporary2, int *, 20);
    Level32_7D7D8Keep(temporary3);
    argument1 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);

    Level32_7D7D8Field(temporary3, unsigned char *, 70) = temporary2;
    argument0 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(owner, short *, 56);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(argument0, int *, 20);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(argument0, int *, 20) = temporary2;
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 24;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(temporary3, unsigned char *, 79) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original3159_1470;
original3159_1456:
    argument1 = 0 + 4;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument2 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(argument2);
    argument1 = 0 + 0;
    Level32_7D7D8Keep(argument1);
    argument2 = argument2 + 12;
    Level32_7D7D8_func_80055F14(argument0, argument1, argument2);
    temporary2 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(owner, signed char *, 68);
    Level32_7D7D8Keep(temporary3);
    argument0 = Level32_7D7D8Field(owner, signed char *, 69);
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(owner, signed char *, 70);
    Level32_7D7D8Keep(argument1);
    Level32_7D7D8Field(temporary2, unsigned char *, 68) = temporary3;
    Level32_7D7D8Field(temporary2, unsigned char *, 69) = argument0;
    Level32_7D7D8Field(temporary2, unsigned char *, 70) = argument1;
original3159_1470:
    saved21 = 0 + 0;
    Level32_7D7D8Keep(saved21);
    saved20 = privateState + 0;
    Level32_7D7D8Keep(saved20);
original3159_1472:
    saved17 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(saved17);
    temporary2 = 0 + 5;
    if (saved21 != 0)
        goto original3159_1478;
    argument0 = (int)&locals.sp30;
    Level32_7D7D8Keep(argument0);
    argument1 = owner + 12;
    goto original3159_1482;
original3159_1478:
    argument0 = (int)&locals.sp30;
    if (saved21 != temporary2)
        goto original3159_1535;
    argument1 = (int)&Level32_7D7D8_D_80070328;
    Level32_7D7D8Keep(argument1);
original3159_1482:

    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary3 = Level32_7D7D8Field(saved17, short *, 0);
    Level32_7D7D8Keep(temporary3);
    saved16 = Level32_7D7D8Field(saved20, int *, 200);
    Level32_7D7D8Keep(saved16);
    temporary2 = temporary3 + 1;
    Level32_7D7D8Keep(temporary2);
    temporary2 = saved16 + temporary2;
    Level32_7D7D8Keep(temporary2);
    saved18 = temporary2 % temporary3;
    Level32_7D7D8Keep(saved18);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    saved16 = (int)((unsigned int)saved16 << 4);
    Level32_7D7D8Keep(saved16);
    temporary3 = Level32_7D7D8Field(saved17, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)saved18 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = saved16 + temporary3;
    Level32_7D7D8Keep(temporary3);
    argument3 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument3);
    argument0 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(temporary3, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary3 = Level32_7D7D8Field(saved17, int *, 12);
    Level32_7D7D8Keep(temporary3);
    argument3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 16);
    Level32_7D7D8Keep(argument3);
    saved16 = saved16 + temporary3;
    Level32_7D7D8Keep(saved16);
    argument0 = Level32_7D7D8Field(saved16, int *, 0);
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(saved16, int *, 4);
    Level32_7D7D8Keep(argument1);
    saved16 = temporary2 + 0;
    Level32_7D7D8Keep(saved16);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 20);
    Level32_7D7D8Keep(temporary3);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = saved16 & 255;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 & 255;
    temporary2 = Level32_7D7D8_func_8004F264(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 64;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 179, 1) : (temporary2 = 0 + 179, 0))
        goto original3159_1535;
    Level32_7D7D8Field(saved20, int *, 200) = saved18;
    if (saved18 != temporary2)
        goto original3159_1535;
    temporary2 = Level32_7D7D8Field(saved20, int *, 244);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved20, int *, 244) = temporary2;
original3159_1535:
    saved21 = saved21 + 1;
    Level32_7D7D8Keep(saved21);
    temporary2 = saved21 < 6;
    Level32_7D7D8Keep(temporary2);
    saved20 = saved20 + 4;
    if (temporary2 != 0)
        goto original3159_1472;
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)0x00980000U;
    Level32_7D7D8Keep(argument3);
    argument1 = Level32_7D7D8Field(privateState, int *, 220);
    Level32_7D7D8Keep(argument1);

    temporary2 = argument1 < 179;
    Level32_7D7D8Keep(temporary2);
    argument3 = argument3 | 38527;
    if (temporary2 != 0)
        goto original3159_1551;
    temporary2 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    argument1 = argument1 - temporary2;
    Level32_7D7D8Keep(argument1);
original3159_1551:
    temporary2 = Level32_7D7D8Field(privateState, int *, 268);
    Level32_7D7D8Keep(temporary2);

    argument0 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(privateState, int *, 264);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(argument0);
    wholeProduct1556.full = (long long)temporary2 * (long long)argument0;
    __asm__("" : "=x"(wholeProduct1556.full) : "0"(wholeProduct1556.full));
    temporary3 = Level32_7D7D8Field(privateState, int *, 200);
    Level32_7D7D8Keep(temporary3);
    temporary2 = argument1 + -179;
    Level32_7D7D8Keep(temporary2);
    argument1 = temporary2 + argument0;
    Level32_7D7D8Keep(argument1);
    temporary2 = temporary3 < 179;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1556.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    argument1 = argument1 + temporary10;
    if (temporary2 != 0)
        goto original3159_1565;
    temporary3 = temporary3 - argument0;
    Level32_7D7D8Keep(temporary3);
original3159_1565:
    temporary2 = Level32_7D7D8Field(privateState, int *, 244);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(argument0);
    wholeProduct1567.full = (long long)temporary2 * (long long)argument0;
    __asm__("" : "=x"(wholeProduct1567.full) : "0"(wholeProduct1567.full));
    temporary2 = temporary3 + -179;
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary2 + argument0;
    Level32_7D7D8Keep(temporary3);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1567.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = temporary3 + temporary10;
    Level32_7D7D8Keep(temporary3);
    temporary2 = argument1 < temporary3;
    Level32_7D7D8Keep(temporary2);
    argument0 = temporary3 - argument1;
    if (temporary2 == 0)
        goto original3159_1582;
    temporary2 = argument0 < argument3;
    if (argument0 >= 0)
        goto original3159_1579;
    argument0 = argument1 - temporary3;
    Level32_7D7D8Keep(argument0);
    temporary2 = argument0 < argument3;
    Level32_7D7D8Keep(temporary2);
original3159_1579:
    argument2 = 0 + 1;
    if (temporary2 == 0)
        goto original3159_1582;
    argument3 = argument0 + 0;
    Level32_7D7D8Keep(argument3);
original3159_1582:
    temporary2 = Level32_7D7D8Field(privateState, int *, 304);
    Level32_7D7D8Keep(temporary2);

    if (argument2 == temporary2 ? (temporary2 = argument3 < 2, 1) : (temporary2 = argument3 < 2, 0))
        goto original3159_1589;
    if (temporary2 != 0)
        goto original3159_1589;
    Level32_7D7D8Field(privateState, int *, 304) = argument2;
original3159_1589:
    temporary2 = Level32_7D7D8Field(privateState, int *, 264);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 < 4;
    Level32_7D7D8Keep(temporary2);
    saved18 = 0 + 1;
    if (temporary2 != 0)
        goto original3159_1598;
    temporary2 = 0 + 41;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
original3159_1596:
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    goto original3159Return;
original3159_1598:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14544);
    Level32_7D7D8Keep(temporary2);

    saved17 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(saved17);
original3159_1602:

    temporary3 = Level32_7D7D8Field(saved17, unsigned short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary3 = temporary3 & 32767;
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -15024);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    saved16 = temporary3 + temporary2;
    Level32_7D7D8Keep(saved16);
    temporary2 = Level32_7D7D8Field(saved16, unsigned char *, 72);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (unsigned int)temporary2 < 128;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_1652;
    argument0 = owner + 12;
    Level32_7D7D8Keep(argument0);
    argument1 = saved16 + 12;
    temporary2 = Level32_7D7D8_func_8004F334(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 1000;
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    if (temporary2 == 0)
        goto original3159_1652;
    temporary3 = Level32_7D7D8Field(saved16, int *, 12);
    Level32_7D7D8Keep(temporary3);
    argument0 = Level32_7D7D8Field(owner, int *, 12);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(saved16, int *, 16);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(owner, int *, 16);
    Level32_7D7D8Keep(argument1);
    argument0 = temporary3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(owner, unsigned char *, 70);
    Level32_7D7D8Keep(argument1);
    argument0 = temporary2 + 0;
    temporary2 = Level32_7D7D8_func_8004F264(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 48;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? ({
            temporary3 = (int)0x00020000U;
            Level32_7D7D8Keep(temporary3);
            1;
        })
                        : ({
                              temporary3 = (int)0x00020000U;
                              Level32_7D7D8Keep(temporary3);
                              0;
                          }))
        goto original3159_1652;
    temporary2 = Level32_7D7D8Field(saved16, int *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field(temporary2, int *, 76) = saved18;
    temporary2 = 0 + 255;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, unsigned char *, 74) = temporary2;
    temporary2 = Level32_7D7D8Field(saved16, int *, 24);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 | temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved16, int *, 24) = temporary2;
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field(saved16, unsigned char *, 81) = temporary2;
    if (temporary2 != 0)
        goto original3159_1652;
    Level32_7D7D8Field(saved16, unsigned char *, 81) = saved18;
original3159_1652:
    temporary2 = Level32_7D7D8Field(saved17, short *, 0);
    Level32_7D7D8Keep(temporary2);

    saved17 = saved17 + 2;
    if (temporary2 >= 0)
        goto original3159_1602;
    argument0 = privateState + 316;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 4;
    temporary2 = Level32_7D7D8_func_800359A4(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_1670;
    temporary2 = Level32_7D7D8Field(privateState, int *, 320);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 20;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 320) = temporary2;
    temporary2 = temporary2 < 201;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0 ? (temporary2 = 0 + 200, 1) : (temporary2 = 0 + 200, 0))
        goto original3159_1676;
    Level32_7D7D8Field(privateState, int *, 320) = temporary2;
    goto original3159_1676;
original3159_1670:
    temporary2 = Level32_7D7D8Field(privateState, int *, 320);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + -20;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 320) = temporary2;
    if (temporary2 >= 0)
        goto original3159_1676;
    Level32_7D7D8Field(privateState, int *, 320) = 0;
original3159_1676:
    argument0 = owner + 12;
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(privateState, int *, 312);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(privateState, int *, 320);
    Level32_7D7D8Keep(temporary3);
    argument1 = (int)&Level32_7D7D8_D_80070328;
    Level32_7D7D8Keep(argument1);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 144) = temporary2;
    temporary2 = Level32_7D7D8_func_8004F334(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(privateState, int *, 304);
    Level32_7D7D8Keep(temporary3);

    argument0 = temporary2 + 0;
    if (temporary3 != 0)
        goto original3159_1701;
    temporary2 = argument0 < 20481;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_1694;
    temporary2 = Level32_7D7D8Field(privateState, unsigned short *, 144);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + 30;
    goto original3159_1700;
original3159_1694:
    temporary2 = argument0 < 10241;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_1701;
    temporary2 = Level32_7D7D8Field(privateState, unsigned short *, 144);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 15;
    Level32_7D7D8Keep(temporary2);
original3159_1700:
    Level32_7D7D8Field(privateState, short *, 144) = temporary2;
original3159_1701:
    __asm__ volatile("" ::"r"(temporary3));
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14396);
    Level32_7D7D8Keep(temporary3);

    temporary2 = 0 + 2;
    if (temporary3 == 0)
        goto original3159_1716;
    if (temporary3 != temporary2 ? ({
            argument0 = (int)0x51EB0000U;
            Level32_7D7D8Keep(argument0);
            1;
        })
                                 : ({
                                       argument0 = (int)0x51EB0000U;
                                       Level32_7D7D8Keep(argument0);
                                       0;
                                   }))
        goto original3159_1729;
    temporary3 = Level32_7D7D8Field(privateState, short *, 144);
    Level32_7D7D8Keep(temporary3);
    argument0 = argument0 | 34079;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    goto original3159_1723;
original3159_1716:
    argument0 = (int)0x51EB0000U;
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(privateState, short *, 144);
    Level32_7D7D8Keep(temporary3);
    argument0 = argument0 | 34079;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 5);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
original3159_1723:
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(argument0);
    wholeProduct1723.full = (long long)temporary2 * (long long)argument0;
    __asm__("" : "=x"(wholeProduct1723.full) : "0"(wholeProduct1723.full));
    temporary2 = (temporary2 >> 31);
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=h"(projection) : "x"(wholeProduct1723.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = (temporary10 >> 5);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 - temporary2;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(privateState, short *, 144) = temporary3;
original3159_1729:
    temporary2 = Level32_7D7D8Field(privateState, int *, 316);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0)
        goto original3159_1850;
    argument0 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(argument0);

    if (argument0 == 0)
        goto original3159_1850;
    argument1 = 0 + 4;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    saved17 = 0 + 0;
    Level32_7D7D8Keep(saved17);
    saved18 = (int)&locals.sp50;
    Level32_7D7D8Keep(saved18);
    saved20 = (int)&Level32_7D7D8_D_80065920;
    Level32_7D7D8Keep(saved20);
    saved21 = (int)&Level32_7D7D8_D_800658A0;
    Level32_7D7D8Keep(saved21);
    argument1 = (int)((unsigned int)saved17 >> 31);
    Level32_7D7D8Keep(argument1);
original3159_1746:
    argument1 = saved17 + argument1;
    Level32_7D7D8Keep(argument1);
    argument1 = (argument1 >> 1);
    Level32_7D7D8Keep(argument1);
    argument1 = (int)((unsigned int)argument1 << 1);
    Level32_7D7D8Keep(argument1);
    argument1 = saved17 - argument1;
    Level32_7D7D8Keep(argument1);
    argument0 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(argument0);
    argument2 = saved18 + 0;
    Level32_7D7D8_func_80055F14(argument0, argument1, argument2);
    argument0 = 0 + 0;
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(privateState, unsigned short *, 144);
    Level32_7D7D8Keep(temporary2);
    argument1 = 0 + 140;
    Level32_7D7D8Keep(argument1);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level32_7D7D8Keep(temporary2);
    temporary3 = (temporary2 >> 16);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 >> 31);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    saved16 = (temporary3 >> 1);
    temporary2 = Level32_7D7D8_func_800363DC(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + 256;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Keep(temporary2);
    wholeProduct1763.full = (long long)saved16 * (long long)temporary2;
    __asm__("" : "=x"(wholeProduct1763.full) : "0"(wholeProduct1763.full));
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);

    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved20;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1763.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);
    saved16 = (temporary10 >> 8);
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    wholeProduct1773.full = (long long)temporary2 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct1773.full) : "0"(wholeProduct1773.full));
    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved20;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1773.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct1781.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct1781.full) : "0"(wholeProduct1781.full));
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1781.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 64) = temporary2;
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);

    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved21;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    wholeProduct1793.full = (long long)temporary2 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct1793.full) : "0"(wholeProduct1793.full));
    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved20;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1793.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct1801.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct1801.full) : "0"(wholeProduct1801.full));
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1801.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 68) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved21;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    wholeProduct1813.full = (long long)temporary2 * (long long)saved16;
    __asm__ volatile("" : "=x"(wholeProduct1813.full) : "0"(wholeProduct1813.full) : "memory");
    saved17 = saved17 + 1;
    Level32_7D7D8Keep(saved17);
    argument0 = 0 + 1;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 13;
    Level32_7D7D8Keep(argument1);
    argument2 = saved18 + 0;
    Level32_7D7D8Keep(argument2);
    argument3 = (int)&locals.sp60;
    Level32_7D7D8Keep(argument3);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 17124);
    Level32_7D7D8Keep(temporary3);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct1813.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, int *, 72) = temporary2;
    temporary2 = ((int (*)())temporary3)(argument0, argument1, argument2, argument3);
    Level32_7D7D8Keep(temporary2);
    temporary3 = 0 + 255;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(temporary2, unsigned char *, 11) = temporary3;
    temporary2 = saved17 < 4;
    Level32_7D7D8Keep(temporary2);
    argument1 = (int)((unsigned int)saved17 >> 31);
    if (temporary2 != 0)
        goto original3159_1746;
    argument1 = Level32_7D7D8Field(privateState, int *, 456);
    Level32_7D7D8Keep(argument1);
    argument0 = owner + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original3159_1839;
    Level32_7D7D8Keep(temporary2);
    argument1 = 0 + 0;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 4;
    temporary2 = Level32_7D7D8_func_8003BABC(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 456) = temporary2;
original3159_1839:
    argument1 = Level32_7D7D8Field(privateState, int *, 460);
    Level32_7D7D8Keep(argument1);
    argument0 = owner + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + -1, 1) : (temporary2 = 0 + -1, 0))
        goto original3159_1848;
    argument0 = Level32_7D7D8Field(privateState, int *, 460);

    Level32_7D7D8_func_8003BE70(argument0);
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
original3159_1848:
    Level32_7D7D8Field(privateState, int *, 460) = temporary2;
    goto original3159_1869;
original3159_1850:
    argument1 = Level32_7D7D8Field(privateState, int *, 460);
    Level32_7D7D8Keep(argument1);
    argument0 = owner + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original3159_1859;
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 4;
    temporary2 = Level32_7D7D8_func_8003BABC(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 460) = temporary2;
original3159_1859:
    argument1 = Level32_7D7D8Field(privateState, int *, 456);
    Level32_7D7D8Keep(argument1);
    argument0 = owner + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + -1, 1) : (temporary2 = 0 + -1, 0))
        goto original3159_1868;
    argument0 = Level32_7D7D8Field(privateState, int *, 456);

    Level32_7D7D8_func_8003BE70(argument0);
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
original3159_1868:
    Level32_7D7D8Field(privateState, int *, 456) = temporary2;
original3159_1869:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 21;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = temporary3 < 22, 1)
                                 : (temporary2 = temporary3 < 22, 0))
        goto original3159_2050;
    if (temporary2 == 0 ? (temporary2 = 0 + 5, 1) : (temporary2 = 0 + 5, 0))
        goto original3159_1879;
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original3159_1884;
    temporary2 = 0 + 31;
    goto original3159_2591;
original3159_1879:
    temporary2 = 0 + 98;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original3159_1902;
    __asm__ volatile("" ::);

    goto original3159_2589;
original3159_1884:
    argument1 = 0 + 1;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = privateState + 392;
    temporary2 = Level32_7D7D8_func_80035194(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = 0 + 256;
    Level32_7D7D8Keep(temporary3);
    if (temporary2 != temporary3)
        goto original3159_2589;
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 4;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 48;
    Level32_7D7D8_func_800369B8(argument0, argument1);
    temporary2 = 0 + 98;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
    __asm__ volatile("" ::"r"(privateState), "X"(98));
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    Level32_7D7D8Keep(privateState);
    goto original3159_2589;
original3159_1902:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 60);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary3 = 0 + 3, 1) : (temporary3 = 0 + 3, 0))
        goto original3159_1927;
    temporary2 = Level32_7D7D8Field(owner, short *, 54);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_8006EE2C + temporary2), int *, 0);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, int *, 72);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, 0);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 60) = temporary3;
    Level32_7D7D8Field(owner, unsigned char *, 61) = temporary3;
    temporary3 = 0 + 1;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(owner, unsigned char *, 62) = 0;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(owner, unsigned char *, 62)));
    Level32_7D7D8Field(owner, unsigned char *, 63) = temporary3;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(owner, unsigned char *, 63)));
    temporary2 = (unsigned int)temporary2 < 2;
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 ^ 1;
    Level32_7D7D8Keep(temporary2);
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 & 48;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
original3159_1927:
    temporary2 = Level32_7D7D8Field(privateState, int *, 328);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(privateState, int *, 220);
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(privateState, int *, 324) = temporary2;
    Level32_7D7D8Field(temporary2, short *, 2) = temporary3;
    argument1 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(argument1);

    temporary2 = Level32_7D7D8Field(argument1, short *, 10);
    Level32_7D7D8Keep(temporary2);

    argument0 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(argument0);
    argument0 = argument0 + temporary2;
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(argument1, short *, 2);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(argument1, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 - argument0;
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level32_7D7D8Keep(temporary3);

    Level32_7D7D8Field(argument1, short *, 2) = temporary3;
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(temporary2, short *, 2);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(privateState, int *, 200);
    Level32_7D7D8Keep(temporary2);

    argument1 = privateState + 0;
    if (temporary2 == temporary3)
        goto original3159_1995;
    argument2 = 0 + 179;
    Level32_7D7D8Keep(argument2);
original3159_1962:
    temporary2 = Level32_7D7D8Field(argument1, int *, 200);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != argument2)
        goto original3159_1970;
    temporary2 = Level32_7D7D8Field(argument1, int *, 244);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + -1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(argument1, int *, 244) = temporary2;
original3159_1970:
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);

    argument0 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(argument1, int *, 200);
    Level32_7D7D8Keep(temporary2);
    temporary3 = argument0 + -1;
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary2 % argument0;
    Level32_7D7D8Keep(temporary3);

    Level32_7D7D8Field(argument1, int *, 200) = temporary3;
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(temporary2, short *, 2);
    Level32_7D7D8Keep(temporary2);

    if (temporary3 != temporary2)
        goto original3159_1962;
original3159_1995:
    argument2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(argument2);

    argument1 = Level32_7D7D8Field(argument2, short *, 2);
    Level32_7D7D8Keep(argument1);
    temporary2 = Level32_7D7D8Field(argument2, short *, 10);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(argument2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = argument1 + temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    saved16 = temporary2 % temporary3;
    Level32_7D7D8Keep(saved16);
    argument0 = owner + 12;
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(argument2, int *, 12);
    Level32_7D7D8Keep(temporary2);
    argument1 = (int)((unsigned int)argument1 << 4);
    Level32_7D7D8Keep(argument1);
    argument1 = temporary2 + argument1;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument0 = owner + 0;
    Level32_7D7D8_func_80037014(argument0);
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 2;
    Level32_7D7D8Keep(argument1);
    temporary2 = 0 + 254;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 82) = temporary2;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    Level32_7D7D8Field(owner, unsigned char *, 68) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 69) = 0;
    temporary2 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(temporary2);

    temporary3 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(temporary2, short *, 2);
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    argument0 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(argument1);
    saved16 = (int)((unsigned int)saved16 << 4);
    Level32_7D7D8Keep(saved16);
    saved16 = saved16 + temporary3;
    Level32_7D7D8Keep(saved16);
    argument3 = Level32_7D7D8Field(saved16, int *, 0);
    Level32_7D7D8Keep(argument3);
    temporary3 = Level32_7D7D8Field(saved16, int *, 4);
    Level32_7D7D8Keep(temporary3);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 70) = temporary2;
    temporary2 = 0 + 21;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 316) = 0;
    Level32_7D7D8Field(privateState, int *, 320) = 0;
    Level32_7D7D8Field(privateState, int *, 272) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 72) = temporary2;
    Level32_7D7D8Keep(privateState);
    goto original3159_2589;
original3159_2050:
    argument0 = owner + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(argument1);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17384);
    Level32_7D7D8Keep(temporary2);

    argument2 = privateState + 140;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    temporary3 = 0 + 1;
    Level32_7D7D8Keep(temporary3);
    argument0 = owner + 12;
    if (temporary2 != temporary3)
        goto original3159_2158;
    argument0 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(argument0);

    temporary2 = Level32_7D7D8Field(argument0, short *, 2);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(argument0, short *, 10);
    Level32_7D7D8Keep(argument1);
    temporary3 = Level32_7D7D8Field(argument0, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 - argument1;
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    saved18 = temporary2 % temporary3;
    Level32_7D7D8Keep(saved18);
    temporary3 = Level32_7D7D8Field(argument0, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)saved18 << 4);
    Level32_7D7D8Keep(temporary2);
    saved17 = temporary3 + temporary2;
    Level32_7D7D8Keep(saved17);
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 15);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0)
        goto original3159_2086;
    Level32_7D7D8Field(privateState, int *, 316) = temporary2;
original3159_2086:
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 14);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(saved17, unsigned char *, 13);
    Level32_7D7D8Keep(temporary3);
    saved16 = (int)((unsigned int)temporary2 >> 5);
    Level32_7D7D8Keep(saved16);
    temporary2 = temporary2 & 31;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved17, unsigned char *, 14) = temporary2;
    if (temporary3 != 0)
        goto original3159_2096;
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 12);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0)
        goto original3159_2143;
original3159_2096:
    argument0 = 0 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 100;
    temporary2 = Level32_7D7D8_func_8003636C(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(savedValue30, short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary3 = temporary3 + -1;
    Level32_7D7D8Keep(temporary3);
    argument0 = temporary2 + 0;
    if (saved18 != temporary3)
        goto original3159_2105;
    argument0 = 0 + 100;
    Level32_7D7D8Keep(argument0);
original3159_2105:
    temporary2 = (int)((unsigned int)saved16 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved16;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    argument0 = argument0 + temporary2;
    Level32_7D7D8Keep(argument0);
    temporary2 = argument0 < 31;
    Level32_7D7D8Keep(temporary2);
    saved16 = saved16 + 1;
    if (temporary2 != 0)
        goto original3159_2135;
    saved16 = Level32_7D7D8Field(saved17, unsigned char *, 13);
    Level32_7D7D8Keep(saved16);
    argument0 = (int)&locals.sp50;
    Level32_7D7D8Keep(argument0);
    saved16 = (int)((unsigned int)saved16 << 2);
    Level32_7D7D8Keep(saved16);
    saved16 = saved16 + privateState;
    Level32_7D7D8Keep(saved16);
    temporary2 = Level32_7D7D8Field(saved16, int *, 328);
    Level32_7D7D8Keep(temporary2);
    saved17 = Level32_7D7D8Field(saved17, unsigned char *, 12);
    Level32_7D7D8Keep(saved17);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(temporary2);
    argument1 = (int)((unsigned int)saved17 << 4);
    Level32_7D7D8Keep(argument1);
    argument1 = temporary2 + argument1;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    temporary3 = Level32_7D7D8Field(&locals.sp20, volatile int *, 48);
    Level32_7D7D8Keep(temporary3);
    argument0 = Level32_7D7D8Field(owner, int *, 12);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 52);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(owner, int *, 16);
    Level32_7D7D8Keep(argument1);
    argument0 = temporary3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(saved16, int *, 328);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field(privateState, int *, 324) = temporary2;
    Level32_7D7D8Field(temporary2, short *, 2) = saved17;
    goto original3159_2143;
original3159_2135:
    temporary2 = saved16 < 8;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2139;
    saved16 = 0 + 7;
    Level32_7D7D8Keep(saved16);
original3159_2139:
    temporary2 = Level32_7D7D8Field(saved17, unsigned char *, 14);
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)((unsigned int)saved16 << 5);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 | temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved17, unsigned char *, 14) = temporary2;
original3159_2143:
    temporary2 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary2);
    savedValue30 = Level32_7D7D8Field(privateState, int *, 324);
    Level32_7D7D8Keep(savedValue30);
    if (temporary2 != 0)
        goto original3159_2157;
    temporary2 = Level32_7D7D8Field(savedValue30, short *, 2);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(savedValue30, int *, 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 14);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 276) = 0;
    Level32_7D7D8Field(privateState, int *, 280) = 0;
    Level32_7D7D8Field(privateState, int *, 284) = 0;
    __asm__ volatile("" ::"r"(temporary2), "m"(Level32_7D7D8Field(privateState, int *, 276)),
                     "m"(Level32_7D7D8Field(privateState, int *, 280)),
                     "m"(Level32_7D7D8Field(privateState, int *, 284)));
    temporary2 = temporary2 & 31;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 272) = temporary2;
original3159_2157:
    argument0 = owner + 12;
    Level32_7D7D8Keep(argument0);
original3159_2158:
    argument1 = 0 + 12000;
    temporary2 = Level32_7D7D8_func_8001A358(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    Level32_7D7D8_func_8005629C(argument0);
    temporary2 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary2);

    temporary3 = temporary2 + -12;
    if (temporary2 != 0)
        goto original3159_2189;
    Level32_7D7D8Keep(temporary2);
    argument0 = Level32_7D7D8Field(owner, unsigned char *, 68);
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level32_7D7D8_func_8003613C(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary2 + 0;
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary3 + 0;
    if (temporary3 >= 0)
        goto original3159_2173;
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
original3159_2173:
    if (temporary2 <= 0 ? (temporary2 = temporary3 < 5, 1) : (temporary2 = temporary3 < 5, 0))
        goto original3159_2186;
    if (temporary2 != 0 ? (temporary2 = temporary3 < -4, 1) : (temporary2 = temporary3 < -4, 0))
        goto original3159_2179;
    temporary3 = 0 + 4;
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary3 < -4;
    Level32_7D7D8Keep(temporary2);
original3159_2179:
    if (temporary2 == 0)
        goto original3159_2182;
    temporary3 = 0 + -4;
    Level32_7D7D8Keep(temporary3);
original3159_2182:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 68);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 68) = temporary2;
original3159_2186:
    temporary2 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary2);

    temporary3 = temporary2 + -12;
    Level32_7D7D8Keep(temporary3);
original3159_2189:
    switch ((unsigned int)temporary3) {
    case 0:
        goto original3159_2269;
    case 1:
        goto original3159_2269;
    case 2:
        goto original3159_2589;
    case 3:
        goto original3159_2589;
    case 4:
        goto original3159_2198;
    case 5:
        goto original3159_2198;
    case 6:
        goto original3159_2589;
    case 7:
        goto original3159_2589;
    case 8:
        goto original3159_2332;
    case 9:
        goto original3159_2332;
    case 10:
        goto original3159_2589;
    case 11:
        goto original3159_2589;
    case 12:
        goto original3159_2269;
    case 13:
        goto original3159_2269;
    case 14:
        goto original3159_2589;
    case 15:
        goto original3159_2589;
    case 16:
        goto original3159_2198;
    case 17:
        goto original3159_2198;
    case 18:
        goto original3159_2589;
    case 19:
        goto original3159_2589;
    case 20:
        goto original3159_2332;
    case 21:
        goto original3159_2332;
    default:
        goto original3159_2589;
    }
original3159_2198:
    __asm__ volatile("" ::"r"(temporary3));
    temporary3 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 28;
    Level32_7D7D8Keep(temporary2);
    saved16 = 0 + 256;
    if (temporary3 == temporary2)
        goto original3159_2205;
    temporary2 = 0 + 17;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2206;
original3159_2205:
    saved16 = 0 + 512;
    Level32_7D7D8Keep(saved16);
original3159_2206:
    temporary2 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + -16;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (unsigned int)temporary2 < 2;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2213;
    saved16 = saved16 + 512;
    Level32_7D7D8Keep(saved16);
original3159_2213:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 61);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary3 != temporary2)
        goto original3159_2223;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 7;
    goto original3159_2235;
original3159_2223:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14480);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 8, 1) : (temporary2 = 0 + 8, 0))
        goto original3159_2238;
    Level32_7D7D8Keep(owner);
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original3159_2238;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 8;
    Level32_7D7D8Keep(temporary2);
original3159_2235:
    Level32_7D7D8Field(owner, unsigned char *, 61) = temporary2;
    Level32_7D7D8Field(owner, unsigned char *, 63) = 0;
    Level32_7D7D8_func_80035734(argument0);
original3159_2238:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 60);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 8;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2259;
    argument1 = Level32_7D7D8Field(privateState, int *, 276);
    Level32_7D7D8Keep(argument1);

    temporary2 = argument1 + 0;
    if (argument1 >= 0)
        goto original3159_2247;
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
original3159_2247:
    temporary3 = temporary2 + -12;
    Level32_7D7D8Keep(temporary3);
    temporary2 = saved16 < temporary3;
    Level32_7D7D8Keep(temporary2);
    argument0 = 0 + -12;
    if (temporary2 == 0)
        goto original3159_2252;
    argument0 = temporary3 - saved16;
    Level32_7D7D8Keep(argument0);
original3159_2252:
    temporary2 = argument1 + -12;
    if (argument0 == 0)
        goto original3159_2259;
    Level32_7D7D8Field(privateState, int *, 276) = temporary2;
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 68);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + -12;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 68) = temporary2;
original3159_2259:
    temporary2 = Level32_7D7D8Field(privateState, int *, 276);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 >= 0)
        goto original3159_2264;
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
original3159_2264:
    temporary2 = saved16 < temporary2;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2589;

    goto original3159_2394;
original3159_2269:
    __asm__ volatile("" ::"r"(temporary3));
    temporary3 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 25;
    Level32_7D7D8Keep(temporary2);
    saved16 = 0 + 256;
    if (temporary3 == temporary2)
        goto original3159_2276;
    temporary2 = 0 + 13;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2277;
original3159_2276:
    saved16 = 0 + 512;
    Level32_7D7D8Keep(saved16);
original3159_2277:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 61);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary3 != temporary2)
        goto original3159_2287;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 7;
    goto original3159_2299;
original3159_2287:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14480);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 8, 1) : (temporary2 = 0 + 8, 0))
        goto original3159_2302;
    Level32_7D7D8Keep(owner);
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original3159_2302;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 8;
    Level32_7D7D8Keep(temporary2);
original3159_2299:
    Level32_7D7D8Field(owner, unsigned char *, 61) = temporary2;
    Level32_7D7D8Field(owner, unsigned char *, 63) = 0;
    Level32_7D7D8_func_80035734(argument0);
original3159_2302:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 60);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 8;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2319;
    temporary2 = Level32_7D7D8Field(privateState, int *, 280);
    Level32_7D7D8Keep(temporary2);

    argument1 = temporary2 + 12;
    Level32_7D7D8Keep(argument1);
    temporary3 = argument1 + 0;
    if (argument1 >= 0)
        goto original3159_2312;
    temporary3 = 0 - temporary3;
    Level32_7D7D8Keep(temporary3);
original3159_2312:
    temporary2 = saved16 < temporary3;
    Level32_7D7D8Keep(temporary2);
    argument0 = 0 + 12;
    if (temporary2 == 0)
        goto original3159_2316;
    argument0 = temporary3 - saved16;
    Level32_7D7D8Keep(argument0);
original3159_2316:
    if (argument0 == 0)
        goto original3159_2319;
    Level32_7D7D8Field(privateState, int *, 280) = argument1;
original3159_2319:
    temporary3 = Level32_7D7D8Field(privateState, int *, 280);
    Level32_7D7D8Keep(temporary3);

    temporary2 = temporary3 + 0;
    if (temporary3 >= 0)
        goto original3159_2324;
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
original3159_2324:
    temporary2 = saved16 < temporary2;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2394;
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 69) = temporary2;
    goto original3159_2589;
original3159_2332:
    __asm__ volatile("" ::"r"(temporary3));
    temporary3 = Level32_7D7D8Field(privateState, int *, 272);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 21;
    Level32_7D7D8Keep(temporary2);
    saved16 = 0 + 256;
    if (temporary3 == temporary2)
        goto original3159_2339;
    temporary2 = 0 + 33;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2340;
original3159_2339:
    saved16 = 0 + 512;
    Level32_7D7D8Keep(saved16);
original3159_2340:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 61);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary3 != temporary2)
        goto original3159_2350;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 7;
    goto original3159_2362;
original3159_2350:
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14480);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 8, 1) : (temporary2 = 0 + 8, 0))
        goto original3159_2365;
    Level32_7D7D8Keep(owner);
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original3159_2365;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 8;
    Level32_7D7D8Keep(temporary2);
original3159_2362:
    Level32_7D7D8Field(owner, unsigned char *, 61) = temporary2;
    Level32_7D7D8Field(owner, unsigned char *, 63) = 0;
    Level32_7D7D8_func_80035734(argument0);
original3159_2365:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 60);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 8;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2386;
    temporary2 = Level32_7D7D8Field(privateState, int *, 284);
    Level32_7D7D8Keep(temporary2);

    argument1 = temporary2 + 14;
    Level32_7D7D8Keep(argument1);
    temporary3 = argument1 + 0;
    if (argument1 >= 0)
        goto original3159_2375;
    temporary3 = 0 - temporary3;
    Level32_7D7D8Keep(temporary3);
original3159_2375:
    temporary2 = saved16 < temporary3;
    Level32_7D7D8Keep(temporary2);
    argument0 = 0 + 14;
    if (temporary2 == 0)
        goto original3159_2379;
    argument0 = temporary3 - saved16;
    Level32_7D7D8Keep(argument0);
original3159_2379:
    if (argument0 == 0)
        goto original3159_2386;
    Level32_7D7D8Field(privateState, int *, 284) = argument1;
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 14;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 70) = temporary2;
original3159_2386:
    temporary3 = Level32_7D7D8Field(privateState, int *, 284);
    Level32_7D7D8Keep(temporary3);

    temporary2 = temporary3 + 0;
    if (temporary3 >= 0)
        goto original3159_2391;
    temporary2 = 0 - temporary2;
    Level32_7D7D8Keep(temporary2);
original3159_2391:
    temporary2 = temporary2 < saved16;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2408;
original3159_2394:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 61);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    argument0 = owner + 0;
    if (temporary3 == temporary2)
        goto original3159_2406;
    temporary2 = 0 + 114;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C770, int *, 0) = 0;
    Level32_7D7D8Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 61) = temporary2;
    Level32_7D7D8Field(owner, unsigned char *, 63) = 0;
    Level32_7D7D8_func_80035734(argument0);
original3159_2406:
    Level32_7D7D8Field(privateState, int *, 272) = 0;
    goto original3159_2589;
original3159_2408:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 70) = temporary2;
    goto original3159_2589;
    {
        int frameAddress16;
    original3159_2413:
        saved17 = 0 + 1664;
        Level32_7D7D8Keep(saved17);
        temporary3 = Level32_7D7D8Field(privateState, int *, 304);
        Level32_7D7D8Keep(temporary3);
        temporary2 = 0 + 4;
        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Field(privateState, unsigned char *, 2) = temporary2;
        temporary2 = 0 + 2;
        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Field(privateState, unsigned char *, 5) = temporary2;
        if (temporary3 != 0)
            goto original3159_2426;
        temporary2 = (int)0x80070000U;
        Level32_7D7D8Keep(temporary2);
        temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, -14412);
        Level32_7D7D8Keep(temporary2);
        saved17 = 0 + 2496;
        Level32_7D7D8Keep(saved17);
        temporary2 = temporary2 | 16;
        Level32_7D7D8Keep(temporary2);

        Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C7B4, unsigned char *, 0) = temporary2;
    original3159_2426:
        temporary3 = (int)&Level32_7D7D8_D_80066BC8 + 10;
        Level32_7D7D8Keep(temporary3);
        temporary2 = Level32_7D7D8Field(temporary3, unsigned char *, 0);
        Level32_7D7D8Keep(temporary2);

        temporary2 = temporary2 & 1;
        Level32_7D7D8Keep(temporary2);
        frameAddress16 = (int)&locals.sp30;
        if (temporary2 != 0)
            goto original3159_2460;
        temporary2 = Level32_7D7D8Field(privateState, int *, 448);
        Level32_7D7D8Keep(temporary2);

        temporary2 = temporary2 < 6301;
        Level32_7D7D8Keep(temporary2);
        argument1 = owner + 0;
        if (temporary2 == 0)
            goto original3159_2460;
        temporary2 = 0 + 3;
        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Field(temporary3, unsigned char *, 0) = temporary2;
        temporary3 = (int)0x80070000U;
        Level32_7D7D8Keep(temporary3);
        temporary3 = Level32_7D7D8Field(temporary3, int *, -14764);
        Level32_7D7D8Keep(temporary3);
        temporary2 = 0 + 1;
        Level32_7D7D8Keep(temporary2);

        Level32_7D7D8Field((int)&Level32_7D7D8_D_800719DC, short *, 0) = temporary2;
        argument0 = Level32_7D7D8Field(temporary3, unsigned char *, 35);
        Level32_7D7D8Keep(argument0);
        argument2 = 0 + 161;
        temporary2 = Level32_7D7D8_PlaySound(argument0, argument1, argument2);
        Level32_7D7D8Keep(temporary2);
        temporary2 = (int)0x80070000U;
        Level32_7D7D8Keep(temporary2);
        temporary2 = Level32_7D7D8Field(temporary2, int *, -14460);
        Level32_7D7D8Keep(temporary2);

        temporary2 = temporary2 + 1;
        Level32_7D7D8Keep(temporary2);

        Level32_7D7D8_D_8006C784 = temporary2;
        temporary2 = temporary2 < 100;
        Level32_7D7D8Keep(temporary2);
        __asm__ volatile("" : "=r"(frameAddress16) : "0"(frameAddress16));
        frameAddress16 = (int)&locals.sp30;
        if (temporary2 != 0)
            goto original3159_2460;
        temporary2 = 0 + 99;
        Level32_7D7D8Keep(temporary2);

        Level32_7D7D8_D_8006C784 = temporary2;
    original3159_2460:
        argument0 = frameAddress16 + 0;
        Level32_7D7D8Keep(argument0);
        argument1 = privateState + 380;
        Level32_7D7D8_func_8004F178(argument0, argument1);
        temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 24);
        Level32_7D7D8Keep(temporary2);
        temporary3 = Level32_7D7D8Field(owner, short *, 56);
        Level32_7D7D8Keep(temporary3);
        temporary2 = temporary2 + 356;
        Level32_7D7D8Keep(temporary2);
        temporary2 = temporary2 - temporary3;
        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Field(&locals.sp20, volatile int *, 24) = temporary2;
        temporary2 = Level32_7D7D8Field(privateState, int *, 376);
        Level32_7D7D8Keep(temporary2);

        temporary2 = (int)((unsigned int)temporary2 << 1);
        Level32_7D7D8Keep(temporary2);

        temporary2 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
        Level32_7D7D8Keep(temporary2);

        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Keep(saved17);
        wholeProduct2475.full = (long long)temporary2 * (long long)saved17;
        __asm__("" : "=x"(wholeProduct2475.full) : "0"(wholeProduct2475.full));
        temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 16);
        Level32_7D7D8Keep(temporary2);
        {
            int projection;
            __asm__("" : "=l"(projection) : "x"(wholeProduct2475.full));
            temporary10 = projection;
            Level32_7D7D8Keep(temporary10);
        }
        temporary3 = (temporary10 >> 12);
        Level32_7D7D8Keep(temporary3);
        temporary2 = temporary2 + temporary3;
        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Field(&locals.sp20, volatile int *, 16) = temporary2;
        temporary2 = Level32_7D7D8Field(privateState, int *, 376);
        Level32_7D7D8Keep(temporary2);

        temporary2 = (int)((unsigned int)temporary2 << 1);
        Level32_7D7D8Keep(temporary2);

        temporary2 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
        Level32_7D7D8Keep(temporary2);

        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Keep(saved17);
        wholeProduct2488.full = (long long)temporary2 * (long long)saved17;
        __asm__("" : "=x"(wholeProduct2488.full) : "0"(wholeProduct2488.full));
        argument1 = frameAddress16 + 0;
        Level32_7D7D8Keep(argument1);
        saved17 = (int)&Level32_7D7D8_D_8006D088;
        Level32_7D7D8Keep(saved17);
        temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 20);
        Level32_7D7D8Keep(temporary2);
        {
            int projection;
            __asm__("" : "=l"(projection) : "x"(wholeProduct2488.full));
            temporary10 = projection;
            Level32_7D7D8Keep(temporary10);
        }
        temporary3 = (temporary10 >> 12);
        Level32_7D7D8Keep(temporary3);
        temporary2 = temporary2 + temporary3;
        Level32_7D7D8Keep(temporary2);
        Level32_7D7D8Field(&locals.sp20, int *, 20) = temporary2;
        goto original3159_2562;
    }
original3159_2498:
    saved17 = 0 + 1664;
    Level32_7D7D8Keep(saved17);
    temporary3 = Level32_7D7D8Field(privateState, int *, 304);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 15;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, unsigned char *, 2) = temporary2;
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, unsigned char *, 5) = temporary2;
    if (temporary3 != 0)
        goto original3159_2524;
    argument0 = 0 + 1;
    temporary2 = Level32_7D7D8_func_800369D8(argument0);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2515;
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, -14412);
    Level32_7D7D8Keep(temporary2);
    saved17 = 0 + 2496;
    Level32_7D7D8Keep(saved17);
    temporary2 = temporary2 | 32;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C7B4, unsigned char *, 0) = temporary2;
original3159_2515:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = Level32_7D7D8Field(privateState, int *, 304);
    Level32_7D7D8Keep(temporary2);

    saved16 = (int)&locals.sp40;
    if (temporary2 != 0)
        goto original3159_2525;
    argument0 = 0 + 1;
    temporary2 = Level32_7D7D8_func_800369D8(argument0);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original3159_2524;
    Level32_7D7D8Field(privateState, unsigned char *, 2) = temporary2;
original3159_2524:
    saved16 = (int)&locals.sp40;
    Level32_7D7D8Keep(saved16);
original3159_2525:
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = privateState + 380;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 40);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(owner, short *, 56);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 + 356;
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 40) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 376);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_80065920 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved17);
    wholeProduct2540.full = (long long)temporary2 * (long long)saved17;
    __asm__("" : "=x"(wholeProduct2540.full) : "0"(wholeProduct2540.full));
    temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 32);
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2540.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 32) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, int *, 376);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);

    temporary2 = Level32_7D7D8Field(((int)&Level32_7D7D8_D_800658A0 + temporary2), short *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved17);
    wholeProduct2553.full = (long long)temporary2 * (long long)saved17;
    __asm__("" : "=x"(wholeProduct2553.full) : "0"(wholeProduct2553.full));
    argument1 = saved16 + 0;
    Level32_7D7D8Keep(argument1);
    saved17 = (int)&Level32_7D7D8_D_8006D088;
    Level32_7D7D8Keep(saved17);
    temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 36);
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2553.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 36) = temporary2;
original3159_2562:
    argument2 = Level32_7D7D8Field(privateState, int *, 376);
    Level32_7D7D8Keep(argument2);
    argument0 = saved17 + 0;
    Level32_7D7D8Keep(argument0);
    argument2 = argument2 + 128;
    Level32_7D7D8Keep(argument2);
    argument2 = argument2 & 255;
    Level32_7D7D8_func_8003B634(argument0, argument1, argument2);
    saved16 = privateState + 2;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    argument2 = saved17 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    saved18 = (int)&Level32_7D7D8_D_8006C7F8;
    Level32_7D7D8Keep(saved18);
    argument2 = saved18 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    saved16 = privateState + 5;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    argument2 = saved17 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 1;
    Level32_7D7D8Keep(argument1);
    argument2 = saved18 + 0;
    Level32_7D7D8_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level32_7D7D8_func_8003B74C(argument0);
original3159_2589:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);
original3159_2590:
    temporary2 = 0 + 31;
    Level32_7D7D8Keep(temporary2);
original3159_2591:
    if (temporary3 == temporary2 ? (temporary2 = 0 + 21, 1) : (temporary2 = 0 + 21, 0))
        goto original3159_2601;
    if (temporary3 == temporary2)
        goto original3159_2601;
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, unsigned char *, -14412);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 32;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2794;
original3159_2601:
    __asm__ volatile("" ::"r"(temporary2));
    temporary10 = Level32_7D7D8Field(&locals.sp20, volatile int *, 80);
    Level32_7D7D8Keep(temporary10);

    temporary2 = Level32_7D7D8Field(temporary10, int *, 228);
    Level32_7D7D8Keep(temporary2);

    temporary3 = temporary2 + 0;
    if (temporary2 == 0)
        goto original3159_2622;
    temporary2 = temporary3 < 501;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2611;
    temporary3 = 0 + 500;
    Level32_7D7D8Keep(temporary3);
original3159_2611:
    temporary2 = Level32_7D7D8Field(privateState, int *, 164);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 164) = temporary2;
    temporary2 = temporary2 < 901;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0 ? (temporary2 = 0 + 900, 1) : (temporary2 = 0 + 900, 0))
        goto original3159_2619;
    Level32_7D7D8Field(privateState, int *, 164) = temporary2;
original3159_2619:
    temporary10 = Level32_7D7D8Field(&locals.sp20, volatile int *, 80);
    Level32_7D7D8Keep(temporary10);

    Level32_7D7D8Field(temporary10, int *, 228) = 0;
original3159_2622:
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 888);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 19;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2754;

    Level32_7D7D8OriginalGlobalField0 = 0;
    temporary2 = Level32_7D7D8Field(privateState, short *, 308);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != 0)
        goto original3159_2639;
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -6856);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 128;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2754;
original3159_2639:
    __asm__ volatile("" ::"r"(temporary2) : "$4");
    argument0 = privateState + 308;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 2;
    temporary2 = Level32_7D7D8_func_800359A4(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = privateState + 164;
    if (temporary2 == 0)
        goto original3159_2648;
    argument1 = 0 + 4;
    temporary2 = Level32_7D7D8_func_800359A4(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2754;
original3159_2648:
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8OriginalGlobalField0 = temporary2;
    argument1 = Level32_7D7D8Field(privateState, int *, 444);
    Level32_7D7D8Keep(argument1);
    argument0 = saved23 + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    argument0 = saved23 + 0;
    if (temporary2 != 0)
        goto original3159_2661;
    argument1 = 0 + 6;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 4;
    temporary2 = Level32_7D7D8_func_8003BABC(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 444) = temporary2;
    argument0 = saved23 + 0;
    Level32_7D7D8Keep(argument0);
original3159_2661:
    argument1 = 0 + 4;
    Level32_7D7D8_func_80055D24(argument0, argument1);
    savedValue30 = 0 + 6;
    Level32_7D7D8Keep(savedValue30);
    saved17 = 0 + 0;
    Level32_7D7D8Keep(saved17);
    saved18 = (int)&locals.sp30;
    Level32_7D7D8Keep(saved18);
    saved20 = (int)&Level32_7D7D8_D_80065920;
    Level32_7D7D8Keep(saved20);
    saved21 = (int)&Level32_7D7D8_D_800658A0;
    Level32_7D7D8Keep(saved21);
    argument0 = saved23 + 0;
    Level32_7D7D8Keep(argument0);
original3159_2671:
    argument1 = (int)((unsigned int)saved17 >> 31);
    Level32_7D7D8Keep(argument1);
    argument1 = saved17 + argument1;
    Level32_7D7D8Keep(argument1);
    argument1 = (argument1 >> 1);
    Level32_7D7D8Keep(argument1);
    argument1 = (int)((unsigned int)argument1 << 1);
    Level32_7D7D8Keep(argument1);
    argument1 = saved17 - argument1;
    Level32_7D7D8Keep(argument1);
    argument2 = saved18 + 0;
    Level32_7D7D8_func_80055F14(argument0, argument1, argument2);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 984);
    Level32_7D7D8Keep(temporary2);

    saved16 = (temporary2 >> 6);
    if (temporary2 >= 0)
        goto original3159_2685;
    temporary2 = temporary2 + 63;
    Level32_7D7D8Keep(temporary2);
    saved16 = (temporary2 >> 6);
    Level32_7D7D8Keep(saved16);
original3159_2685:
    argument0 = 0 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = 0 + 140;
    temporary2 = Level32_7D7D8_func_800363DC(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + 256;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Keep(temporary2);
    wholeProduct2689.full = (long long)saved16 * (long long)temporary2;
    __asm__("" : "=x"(wholeProduct2689.full) : "0"(wholeProduct2689.full));
    temporary2 = Level32_7D7D8Field(saved23, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved20;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2689.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);
    saved16 = (temporary10 >> 8);
    Level32_7D7D8Keep(saved16);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    wholeProduct2697.full = (long long)temporary2 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct2697.full) : "0"(wholeProduct2697.full));
    temporary2 = Level32_7D7D8Field(saved23, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved20;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2697.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct2705.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct2705.full) : "0"(wholeProduct2705.full));
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2705.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 32) = temporary2;
    temporary2 = Level32_7D7D8Field(saved23, unsigned char *, 70);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved21;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    wholeProduct2715.full = (long long)temporary2 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct2715.full) : "0"(wholeProduct2715.full));
    temporary2 = Level32_7D7D8Field(saved23, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved20;
    Level32_7D7D8Keep(temporary2);
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2715.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary3 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(temporary3);
    wholeProduct2723.full = (long long)temporary2 * (long long)temporary3;
    __asm__("" : "=x"(wholeProduct2723.full) : "0"(wholeProduct2723.full));
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2723.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 36) = temporary2;
    temporary2 = Level32_7D7D8Field(saved23, unsigned char *, 69);
    Level32_7D7D8Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + saved21;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, short *, 0);
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Keep(saved16);
    wholeProduct2733.full = (long long)temporary2 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct2733.full) : "0"(wholeProduct2733.full));
    {
        int projection;
        __asm__("" : "=l"(projection) : "x"(wholeProduct2733.full));
        temporary10 = projection;
        Level32_7D7D8Keep(temporary10);
    }
    temporary2 = (temporary10 >> 12);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 40) = temporary2;
    temporary2 = Level32_7D7D8Field(privateState, short *, 308);
    Level32_7D7D8Keep(temporary2);

    argument0 = 0 + 1;
    if (temporary2 == 0)
        goto original3159_2743;
    argument1 = 0 + 57;
    goto original3159_2744;
original3159_2743:
    argument1 = 0 + 13;
    Level32_7D7D8Keep(argument1);
original3159_2744:
    argument2 = saved18 + 0;
    Level32_7D7D8Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 17124);
    Level32_7D7D8Keep(temporary2);

    argument3 = (int)&locals.sp40;
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    Level32_7D7D8Keep(temporary2);
    saved17 = saved17 + 1;
    Level32_7D7D8Keep(saved17);
    temporary2 = saved17 < savedValue30;
    Level32_7D7D8Keep(temporary2);
    argument0 = saved23 + 0;
    if (temporary2 != 0)
        goto original3159_2671;
original3159_2754:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 1164);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 21, 1) : (temporary2 = 0 + 21, 0))
        goto original3159_2764;
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 880);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 != temporary2)
        goto original3159_2775;
original3159_2764:
    argument1 = Level32_7D7D8Field(privateState, int *, 444);
    Level32_7D7D8Keep(argument1);
    argument0 = saved23 + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + -1, 1) : (temporary2 = 0 + -1, 0))
        goto original3159_2773;
    argument0 = Level32_7D7D8Field(privateState, int *, 444);

    Level32_7D7D8_func_8003BE70(argument0);
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
original3159_2773:
    Level32_7D7D8Field(privateState, int *, 444) = temporary2;
    goto original3159_2794;
original3159_2775:
    argument0 = Level32_7D7D8Field(privateState, int *, 444);
    Level32_7D7D8Keep(argument0);

    if (argument0 < 0)
        goto original3159_2794;
    __asm__ volatile("" ::"r"(owner));
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 984);
    Level32_7D7D8Keep(temporary3);

    temporary2 = temporary3 + -7000;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 >= 0 ? (temporary2 = (temporary2 >> 2), 1) : (temporary2 = (temporary2 >> 2), 0))
        goto original3159_2787;
    temporary2 = temporary3 + -6997;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (temporary2 >> 2);
    Level32_7D7D8Keep(temporary2);
original3159_2787:
    argument1 = temporary2 + 1024;
    Level32_7D7D8Keep(argument1);
    temporary2 = argument1 < 5001;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_2792;
    argument1 = 0 + 5000;
    Level32_7D7D8Keep(argument1);
original3159_2792:

    Level32_7D7D8_func_8003C140(argument0, argument1);
original3159_2794:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 31;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = 0 + 21, 1) : (temporary2 = 0 + 21, 0))
        goto original3159_2804;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 5, 1) : (temporary2 = 0 + 5, 0))
        goto original3159_2804;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 98, 1) : (temporary2 = 0 + 98, 0))
        goto original3159_2804;
    if (temporary3 != temporary2)
        goto original3159_2810;
original3159_2804:
    temporary2 = Level32_7D7D8Field(privateState, int *, 448);
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14776);
    Level32_7D7D8Keep(temporary3);

    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, int *, 448) = temporary2;
original3159_2810:
    argument0 = Level32_7D7D8Field(owner, unsigned char *, 72);
    Level32_7D7D8Keep(argument0);
    temporary2 = 0 + 31;
    Level32_7D7D8Keep(temporary2);
    argument1 = 0 + 21;
    if (argument0 == temporary2)
        goto original3159_2824;
    temporary2 = 0 + 50;
    if (argument0 == argument1)
        goto original3159_2824;
    if (argument0 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original3159Return;
    temporary3 = Level32_7D7D8Field(privateState, int *, 452);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 != temporary2)
        goto original3159Return;
    __asm__ volatile("" ::);
    Level32_7D7D8Keep(argument0);
    if (argument0 != argument1)
        goto original3159_2837;
original3159_2824:
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14768);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 2;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_2837;

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C650, int *, 0) = 0;
    argument0 = (int)&Level32_7D7D8_D_8006D088;

    Level32_7D7D8_func_8003B74C(argument0);

    goto original3159Return;
original3159_2837:
    temporary3 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original3159_2845;
    if (temporary3 == temporary2)
        goto original3159_2971;

    goto original3159_3032;
original3159_2845:
    saved21 = (int)0x00980000U;
    Level32_7D7D8Keep(saved21);
    saved21 = saved21 | 38527;
    Level32_7D7D8Keep(saved21);
    temporary3 = Level32_7D7D8Field(privateState, int *, 184);
    Level32_7D7D8Keep(temporary3);
    saved17 = 0 + 0;
    Level32_7D7D8Keep(saved17);
    temporary2 = Level32_7D7D8Field(temporary3, short *, 0);
    Level32_7D7D8Keep(temporary2);

    saved20 = 0 + 0;
    if (temporary2 <= 0)
        goto original3159_2922;
    saved23 = (int)&Level32_7D7D8_D_80070328;
    Level32_7D7D8Keep(saved23);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
original3159_2856:
    saved18 = (int)((unsigned int)saved17 << 4);
    Level32_7D7D8Keep(saved18);
    temporary2 = Level32_7D7D8Field(temporary3, int *, 12);
    Level32_7D7D8Keep(temporary2);
    argument0 = Level32_7D7D8Field(saved23, int *, 0);
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(saved23, int *, 4);
    Level32_7D7D8Keep(argument1);
    temporary2 = saved18 + temporary2;
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(temporary2, int *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 4);
    Level32_7D7D8Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument3 = Level32_7D7D8Field(privateState, int *, 184);
    Level32_7D7D8Keep(argument3);

    argument0 = Level32_7D7D8Field(argument3, short *, 0);
    Level32_7D7D8Keep(argument0);

    temporary3 = argument0 + 1;
    Level32_7D7D8Keep(temporary3);
    temporary3 = saved17 + temporary3;
    Level32_7D7D8Keep(temporary3);
    argument1 = temporary3 % argument0;
    Level32_7D7D8Keep(argument1);
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
    saved16 = temporary2 + 0;
    Level32_7D7D8Keep(saved16);
    temporary3 = Level32_7D7D8Field(argument3, int *, 12);
    Level32_7D7D8Keep(temporary3);
    argument1 = (int)((unsigned int)argument1 << 4);
    Level32_7D7D8Keep(argument1);
    argument1 = argument1 + temporary3;
    Level32_7D7D8Keep(argument1);
    temporary3 = saved18 + temporary3;
    Level32_7D7D8Keep(temporary3);
    temporary8 = Level32_7D7D8Field(argument1, int *, 0);
    Level32_7D7D8Keep(temporary8);
    argument0 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(argument0);
    argument3 = Level32_7D7D8Field(argument1, int *, 4);
    Level32_7D7D8Keep(argument3);
    argument1 = Level32_7D7D8Field(temporary3, int *, 4);
    Level32_7D7D8Keep(argument1);
    argument0 = temporary8 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = argument3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    saved16 = temporary2 + 0;
    Level32_7D7D8Keep(saved16);
    argument1 = saved16 + 0;
    temporary2 = Level32_7D7D8_func_8004F264(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 65;
    Level32_7D7D8Keep(temporary2);
    argument0 = saved23 + 0;
    if (temporary2 != 0)
        goto original3159_2915;
    temporary2 = Level32_7D7D8Field(privateState, int *, 184);
    Level32_7D7D8Keep(temporary2);

    argument1 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(argument1);
    argument1 = argument1 + saved18;
    temporary2 = Level32_7D7D8_func_8004F334(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary2 + 0;
    Level32_7D7D8Keep(temporary3);
    temporary2 = temporary3 < saved21;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0)
        goto original3159_2915;
    saved20 = saved17 + 0;
    Level32_7D7D8Keep(saved20);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 88) = saved16;
    saved21 = temporary3 + 0;
    Level32_7D7D8Keep(saved21);
original3159_2915:
    temporary3 = Level32_7D7D8Field(privateState, int *, 184);
    Level32_7D7D8Keep(temporary3);

    temporary2 = Level32_7D7D8Field(temporary3, short *, 0);
    Level32_7D7D8Keep(temporary2);
    saved17 = saved17 + 1;
    Level32_7D7D8Keep(saved17);
    temporary2 = saved17 < temporary2;
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    if (temporary2 != 0)
        goto original3159_2856;
original3159_2922:
    temporary2 = 0 + 26;
    Level32_7D7D8Keep(temporary2);
    argument2 = 0 + 0;
    if (saved20 != temporary2)
        goto original3159_2955;
    argument0 = Level32_7D7D8Field(privateState, int *, 184);
    Level32_7D7D8Keep(argument0);

    temporary3 = Level32_7D7D8Field(argument0, short *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = temporary3 + 26;
    Level32_7D7D8Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level32_7D7D8Keep(temporary3);
    saved20 = 0 + 25;
    Level32_7D7D8Keep(saved20);
    temporary2 = Level32_7D7D8Field(argument0, int *, 12);
    Level32_7D7D8Keep(temporary2);

    argument0 = Level32_7D7D8Field(temporary2, int *, 400);
    Level32_7D7D8Keep(argument0);
    argument1 = Level32_7D7D8Field(temporary2, int *, 404);
    Level32_7D7D8Keep(argument1);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    argument3 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(argument3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 4);
    Level32_7D7D8Keep(temporary3);
    argument0 = argument3 - argument0;
    Level32_7D7D8Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level32_7D7D8_func_8004E880(argument0, argument1, argument2);
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, volatile int *, 88) = temporary2;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(&locals.sp20, int *, 88)) : "$6");
    argument2 = 0 + 0;
    Level32_7D7D8Keep(argument2);
original3159_2955:
    argument3 = 0 + 0;
    Level32_7D7D8Keep(argument3);
    temporary2 = Level32_7D7D8Field(privateState, int *, 184);
    Level32_7D7D8Keep(temporary2);
    argument0 = (int)((unsigned int)saved20 << 4);
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 12);
    Level32_7D7D8Keep(temporary2);
    argument1 = Level32_7D7D8Field(&locals.sp20, volatile int *, 88);
    Level32_7D7D8Keep(argument1);
    argument0 = temporary2 + argument0;
    Level32_7D7D8_func_80013D44(argument0, argument1, argument2, argument3);
    argument1 = (int)&Level32_7D7D8_D_80070328;
    Level32_7D7D8Keep(argument1);
    argument0 = privateState + 188;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(owner, unsigned char *, 73) = temporary2;
    goto original3159_3032;
original3159_2971:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -8120);
    Level32_7D7D8Keep(temporary2);

    temporary2 = temporary2 & 1;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + 19, 1) : (temporary2 = 0 + 19, 0))
        goto original3159_3032;
    saved17 = (int)&Level32_7D7D8_D_80070328 + 80;
    Level32_7D7D8Keep(saved17);
    temporary3 = Level32_7D7D8Field(saved17, int *, 0);
    Level32_7D7D8Keep(temporary3);

    if (temporary3 == temporary2)
        goto original3159_3032;
    temporary10 = Level32_7D7D8Field(&locals.sp20, volatile int *, 80);
    Level32_7D7D8Keep(temporary10);

    Level32_7D7D8Field(temporary10, int *, 136) = 0;
    Level32_7D7D8Field(temporary10, int *, 232) = 0;
    Level32_7D7D8Field(temporary10, short *, 242) = 0;
    Level32_7D7D8_func_8003BEDC();
    temporary3 = Level32_7D7D8Field(privateState, int *, 132);
    Level32_7D7D8Keep(temporary3);

    temporary2 = 0 + -1;
    if (temporary3 == 0)
        goto original3159_2997;
    temporary3 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(temporary3);

    Level32_7D7D8Field(temporary3, short *, 22) = temporary2;
    Level32_7D7D8Field(temporary3, short *, 20) = temporary2;
original3159_2997:
    saved16 = (int)&locals.sp30;
    Level32_7D7D8Keep(saved16);
    argument0 = saved16 + 0;
    Level32_7D7D8Keep(argument0);
    argument1 = saved17 + -80;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument0 = saved23 + 12;
    Level32_7D7D8Keep(argument0);
    temporary2 = Level32_7D7D8Field(&locals.sp20, volatile int *, 24);
    Level32_7D7D8Keep(temporary2);
    argument1 = saved16 + 0;
    Level32_7D7D8Keep(argument1);
    temporary2 = temporary2 + -356;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(&locals.sp20, int *, 24) = temporary2;
    Level32_7D7D8_func_8004F178(argument0, argument1);
    argument0 = (int)0x10000000U;
    Level32_7D7D8Keep(argument0);
    argument0 = argument0 | 128;
    Level32_7D7D8Keep(argument0);
    Level32_7D7D8Field(saved23, unsigned char *, 68) = 0;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(saved23, unsigned char *, 68)));
    Level32_7D7D8Field(saved23, unsigned char *, 69) = 0;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(saved23, unsigned char *, 69)));
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, unsigned char *, 822);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 32;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(saved23, unsigned char *, 76) = temporary2;
    Level32_7D7D8Field(saved23, unsigned char *, 70) = temporary3;
    __asm__ volatile("" ::"m"(Level32_7D7D8Field(saved23, unsigned char *, 76)),
                     "m"(Level32_7D7D8Field(saved23, unsigned char *, 70))
                     : "$3");
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 1332);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 36;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_80070328 + 572, int *, 0) = temporary2;
    temporary2 = 0 + 4;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_80070328 + 592, int *, 0) = saved23;
    __asm__ volatile("" ::"r"(temporary3) : "memory");
    temporary3 = temporary3 | argument0;
    Level32_7D7D8Keep(temporary3);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_80070328 + 524, int *, 0) = temporary3;
    Level32_7D7D8Field(saved23, unsigned char *, 72) = temporary2;
    temporary2 = 0 + 9280;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8Field((int)&Level32_7D7D8_D_8006C700, int *, 0) = temporary2;
    Level32_7D7D8Field(owner, unsigned char *, 73) = 0;
original3159_3032:
    argument0 = (int)&Level32_7D7D8_D_80070328 + 80;
    Level32_7D7D8Keep(argument0);
    temporary3 = Level32_7D7D8Field(argument0, int *, 0);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 19;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2)
        goto original3159_3070;
    temporary2 = Level32_7D7D8Field(privateState, short *, 182);
    Level32_7D7D8Keep(temporary2);

    argument0 = argument0 + -80;
    if (temporary2 != 0)
        goto original3159_3074;
    temporary3 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary3);
    argument1 = (int)0x80070000U;
    Level32_7D7D8Keep(argument1);
    argument1 = Level32_7D7D8Field(argument1, int *, -15024);
    Level32_7D7D8Keep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    argument1 = argument1 + temporary2;
    Level32_7D7D8Keep(argument1);
    argument1 = argument1 + 12;
    temporary2 = Level32_7D7D8_func_8004F334(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 < 2201;
    Level32_7D7D8Keep(temporary2);
    if (temporary2 != 0)
        goto original3159_3070;
    temporary3 = Level32_7D7D8Field(privateState, int *, 100);
    Level32_7D7D8Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -15024);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level32_7D7D8Keep(temporary2);
    temporary3 = 0 + 1;
    Level32_7D7D8Keep(temporary3);
    Level32_7D7D8Field(temporary2, unsigned char *, 73) = temporary3;
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);
    Level32_7D7D8Field(privateState, short *, 182) = temporary2;
original3159_3070:
    temporary2 = Level32_7D7D8Field(privateState, short *, 182);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 == 0)
        goto original3159Return;
original3159_3074:
    temporary2 = Level32_7D7D8Field(owner, unsigned char *, 73);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != 0)
        goto original3159Return;
    __asm__ volatile("" ::"r"(owner));
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14952);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != 0)
        goto original3159Return;
    argument0 = (int)&Level32_7D7D8_D_800676E8;
    Level32_7D7D8Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, -14964);
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, -14904);
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level32_7D7D8Keep(temporary2);
    temporary2 = temporary2 + argument0;
    Level32_7D7D8Keep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 << 2);
    Level32_7D7D8Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level32_7D7D8Keep(temporary3);
    temporary2 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary2);
    temporary2 = Level32_7D7D8Field(temporary2, int *, 816);
    Level32_7D7D8Keep(temporary2);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 0);
    Level32_7D7D8Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    Level32_7D7D8Keep(temporary2);
    saved16 = temporary2 < 3500;
    Level32_7D7D8Keep(saved16);
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 888);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 19;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 == temporary2)
        goto original3159_3113;
    temporary2 = Level32_7D7D8Field(privateState, int *, 416);
    Level32_7D7D8Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = (unsigned int)temporary3 < 2, 1)
                        : (temporary2 = (unsigned int)temporary3 < 2, 0))
        goto original3159_3123;
    if (temporary2 != 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original3159_3112;
    if (temporary3 != temporary2)
        goto original3159_3113;
original3159_3112:
    saved16 = 0 + 1;
    Level32_7D7D8Keep(saved16);
original3159_3113:
    temporary2 = Level32_7D7D8Field(privateState, int *, 416);
    Level32_7D7D8Keep(temporary2);

    argument0 = privateState + 416;
    if (temporary2 != 0)
        goto original3159_3124;
    temporary3 = (int)0x80070000U;
    Level32_7D7D8Keep(temporary3);
    temporary3 = Level32_7D7D8Field(temporary3, int *, 880);
    Level32_7D7D8Keep(temporary3);
    temporary2 = 0 + 28;
    Level32_7D7D8Keep(temporary2);
    if (temporary3 != temporary2 ? (temporary2 = 0 + 40, 1) : (temporary2 = 0 + 40, 0))
        goto original3159_3124;
    Level32_7D7D8Field(privateState, int *, 416) = temporary2;
original3159_3123:
    argument0 = privateState + 416;
    Level32_7D7D8Keep(argument0);
original3159_3124:
    argument1 = 0 + 4;
    temporary2 = Level32_7D7D8_func_800359A4(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    temporary3 = 0 + 2;
    Level32_7D7D8Keep(temporary3);
    if (temporary2 != temporary3)
        goto original3159_3130;
    saved16 = 0 + 1;
    Level32_7D7D8Keep(saved16);
original3159_3130:
    if (saved16 == 0)
        goto original3159Return;
    argument1 = Level32_7D7D8Field(privateState, int *, 444);
    Level32_7D7D8Keep(argument1);
    argument0 = owner + 0;
    temporary2 = Level32_7D7D8_func_8003BFC0(argument0, argument1);
    Level32_7D7D8Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = 0 + -1, 1) : (temporary2 = 0 + -1, 0))
        goto original3159_3141;
    argument0 = Level32_7D7D8Field(privateState, int *, 444);

    Level32_7D7D8_func_8003BE70(argument0);
    temporary2 = 0 + -1;
    Level32_7D7D8Keep(temporary2);
original3159_3141:
    Level32_7D7D8Field(privateState, int *, 444) = temporary2;
    temporary2 = 0 + 1;
    Level32_7D7D8Keep(temporary2);

    Level32_7D7D8OriginalGlobalField0 = 0;
    Level32_7D7D8Field(owner, unsigned char *, 73) = temporary2;
original3159Return:
    return;
}
#undef Level32_7D7D8Field
#undef Level32_7D7D8Keep
#undef Level32_7D7D8Low


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80080934.
* AI generated; not human reviewed. All699 instructions,31 selectors and
* one zero padding word,731 owned words,require every native/linked word
* and actual transfer/table destination. Frame90 saves S0..S6/RA,SP20..6F.
* Retained S4 first holds1250,then a separate full divisor/count4 in state2.
* Both signed divisions128/count and (index<<8)/count preserve original
* DIV/MFLO and all zero/overflow checks. No synthetic partial HI/LO values.
* The particle vector retains original S6 address and runtime count/stride.
* Shared cleanup653 follows final state. Current height loads after35D38
* returns;full signed +/-70 clamp and distinct comparison entries remain.
* Signed caller heading retains full short-to-word shift before byte callee.
* Callback byte clear follows the result at original316. Full constructor,
* result and animation-byte snapshots retain original load/store widths.
* Second height check preserves two full sum producers,store463,complete
* copy-pointer464 and independent already-prepared entry465. Original
* initial metadata clobbers dead S4 before its complete1250 producer;all
* other empty constraints consume complete initialized words/addresses or
* clobber dead values before complete producers. Zero CPU instructions.
* No fixedFP,undefined saved inputs,live alias overlap or pipeline changes.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence: binary identity only
* after every gate. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned selectors/padding
* and full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 fc7dbe3fbb32fa5d2b61364894277a97afa0a848250244bc0486a61c195d4d18 */
#define Level32_80934Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level32_80934Call1A358View1() __asm__("func_8001A358");
void Level32_80934Call34F40View1(void*, int) __asm__("func_80034F40");
int Level32_80934Call35030View1() __asm__("func_80035030");
int Level32_80934Call35734View1() __asm__("func_80035734");
int Level32_80934Call3573CView1() __asm__("func_8003573C");
int Level32_80934Call3585CView1() __asm__("func_8003585C");
int Level32_80934Call359A4View1(void*, int) __asm__("func_800359A4");
int Level32_80934Call35A80View1() __asm__("func_80035A80");
int Level32_80934Call35D38View1() __asm__("func_80035D38");
int Level32_80934Call35DDCView1() __asm__("func_80035DDC");
int Level32_80934Call360F8View1() __asm__("func_800360F8");
int Level32_80934Call3636CView1() __asm__("func_8003636C");
int Level32_80934Call363DCView1() __asm__("func_800363DC");
int Level32_80934Call369B8View1() __asm__("func_800369B8");
int Level32_80934Call36A68View1() __asm__("func_80036A68");
int Level32_80934Call391E8View1() __asm__("func_800391E8");
int Level32_80934Call3BA00View1() __asm__("func_8003BA00");
int Level32_80934Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level32_80934Call4EDE8View1() __asm__("func_8004EDE8");
int Level32_80934Call4F08CView1() __asm__("func_8004F08C");
int Level32_80934Call4F178View1() __asm__("func_8004F178");
int Level32_80934Call4F1C8View1() __asm__("func_8004F1C8");
int Level32_80934Call4F264View1(int, int) __asm__("func_8004F264");
int Level32_80934Call4F334View1() __asm__("func_8004F334");
int Level32_80934Call55B18View1() __asm__("func_80055B18");
int Level32_80934Call55D24View1() __asm__("func_80055D24");
int Level32_80934Call55E84View1() __asm__("func_80055E84");
int Level32_80934Call55F14View1() __asm__("func_80055F14");
int Level32_80934Call5629CView1() __asm__("func_8005629C");
int Level32_80934DatarandView1(void) __asm__("rand");
extern int Level32_80934Data658A0View1 __asm__("D_800658A0");
extern int Level32_80934Data65920View1 __asm__("D_80065920");
extern int Level32_80934Data6C550View1 __asm__("D_8006C550");
extern int Level32_80934Data6C640View1 __asm__("D_8006C640");
extern int Level32_80934Data6C770View1 __asm__("D_8006C770");
extern int Level32_80934Data6E020View1 __asm__("D_8006E020");
extern int Level32_80934Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level32_80934Data6E040View1 __asm__("D_8006E040");
extern int Level32_80934Data70328View1 __asm__("D_80070328");
extern int(*Level32_80934DataSpawnMobyView1)() __asm__("SpawnMoby");
extern void*(*Level32_80934DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
extern int(*Level32_80934Data743C8View1)() __asm__("unk_ovlheader_800743C8");
extern int(*Level32_80934Data743ECView1)() __asm__("unk_ovlheader_800743EC");
extern int(*Level32_80934Data74410View1)() __asm__("unk_ovlheader_80074410");
void func_level_32_80080934(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), retainedHeightTargetOrDivisor20 __asm__("$20"), retainedParticleVector22 __asm__("$22");
    register void *ownerRecord19 __asm__("$19");
    register int privateRecord18 __asm__("$18"), retainedPrivateResultOrAngle16 __asm__("$16"), retainedLinkedRecordPrivateOrCounter17 __asm__("$17"), retainedParticleDistance21 __asm__("$21");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C;
    }
    originalFrame;
    int temporaryWord12;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord8;
    int temporaryWord7;
    int temporaryWord13;
    int temporaryWord1;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord11;
    ownerRecord19 = ownerParameter;
    __asm__("":"=r"(ownerRecord19):"0"(ownerRecord19):"$20");
    rawWord3 = 0x830000;
    rawWord2 = Level32_80934Field(ownerRecord19, int*, 24);
    privateRecord18 = Level32_80934Field(ownerRecord19, void**, 0);
    rawWord2 &= rawWord3;
    retainedHeightTargetOrDivisor20 = 1250;
    if (rawWord2){
        if (Level32_80934Field(ownerRecord19, unsigned char *, 0x48) != 2) {
            temporaryWord1 = Level32_80934Field(privateRecord18, void **, 0x2C);
            if (temporaryWord1 != 0) {
                Level32_80934Call55B18View1(temporaryWord1);
                Level32_80934Field(privateRecord18, void **, 0x2C) = 0;
            }
            Level32_80934Field(privateRecord18, int *, 4) = 0xFA;
            Level32_80934Field(privateRecord18, int *, 8) = 0x5A;
            temporaryWord13 = Level32_80934Field(ownerRecord19, unsigned char *, 0x51);
            if (temporaryWord13 == 0) {
                temporaryWord13 = Level32_80934Call360F8View1(Level32_80934Call4E880View1(Level32_80934Field(ownerRecord19, int *, 0xC) - Level32_80934Field((int)&Level32_80934Data70328View1, int *, 0), Level32_80934Field(ownerRecord19, int *, 0x10) - Level32_80934Field((int)&Level32_80934Data70328View1, int *, 4), 0), Level32_80934Field((int)&Level32_80934Data70328View1, unsigned char *, 0xE), 0x20, 0x40);
            }
            Level32_80934Field(privateRecord18, int *, 0) = (int) temporaryWord13;
            Level32_80934Field(ownerRecord19, signed char *, 0x47) = 9;
            temporaryWord6 = Level32_80934Field(privateRecord18, int *, 0x48);
            argumentWord5 = 1;
            if (temporaryWord6 != -1){
                rawWord3 = temporaryWord6;
                rawWord2 = rawWord3*88;
                rawWord3 = Level32_80934Data6C550View1;
                retainedLinkedRecordPrivateOrCounter17 = rawWord3+rawWord2;
                argumentWord4 = retainedLinkedRecordPrivateOrCounter17;
                rawWord3 = 1;
                rawWord2 = 48;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, signed char*, 65) = rawWord3;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, signed char*, 77) = rawWord3;
                rawWord3 = 0x80000000;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, signed char*, 76) = rawWord2;
                rawWord2 = Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, int*, 28);
                retainedPrivateResultOrAngle16 = Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, int*, 0);
                rawWord2 |= rawWord3;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, int*, 28) = rawWord2;
                Level32_80934Call55D24View1(argumentWord4, argumentWord5);
                Level32_80934Call4F178View1(retainedLinkedRecordPrivateOrCounter17 + 0xC, ownerRecord19 + 0xC);
                rawWord2 = Level32_80934Field(ownerRecord19, unsigned char*, 70);
                argumentWord4 = 20;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, signed char*, 72) = argumentWord4;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, unsigned char*, 70) = rawWord2;
                Level32_80934Field(retainedPrivateResultOrAngle16, short*, 52) = 0;
                rawWord2 = Level32_80934Field(privateRecord18, int*, 0);
                Level32_80934Field(retainedPrivateResultOrAngle16, int*, 4) = rawWord2;
                rawWord2 = Level32_80934Field(privateRecord18, int*, 4);
                Level32_80934Field(retainedPrivateResultOrAngle16, int*, 0) = rawWord2;
                rawWord3 = Level32_80934Field(privateRecord18, int*, 8);
                rawWord2 = 25;
                Level32_80934Field(retainedPrivateResultOrAngle16, signed char*, 41) = argumentWord4;
                Level32_80934Field(retainedPrivateResultOrAngle16, signed char*, 40) = rawWord2;
                Level32_80934Field(retainedPrivateResultOrAngle16, int*, 8) = rawWord3;
                if (!(Level32_80934Field(ownerRecord19, int *, 0x18) & 0x10000)) {
                    Level32_80934Field(retainedPrivateResultOrAngle16, signed char *, 0x37) = 0;
                }
                Level32_80934Field(retainedPrivateResultOrAngle16, signed char *, 0x36) = 0;
                Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, signed char *, 0x4C) = 0x20;
            }
            Level32_80934Call36A68View1(ownerRecord19, 1, 0, 0);
            if (Level32_80934Field(ownerRecord19, int *, 0x18) & 0x820000) {
                Level32_80934Call391E8View1(0xA, 0x91, ownerRecord19, 0, 2, 0xB4, 0xC8);
                Level32_80934Call391E8View1(5, 0x92, ownerRecord19, 0, 2, 0xB4, 0xC8);
                Level32_80934Call55D24View1(ownerRecord19, 4);
                Level32_80934Call3BA00View1(ownerRecord19);
                Level32_80934Call369B8View1(ownerRecord19, 0x18);
                goto callSharedOriginalRemoval649;
            }
            Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 2U;
            Level32_80934Call34F40View1(ownerRecord19, 2);
            goto block_13;
        }
        goto block_14;
    }
block_13:
block_14:
    if (Level32_80934Field(ownerRecord19, unsigned char *, 0x48) != 0x1E) {
        rawWord2 = Level32_80934Call35D38View1(ownerRecord19);
        argumentWord4 = Level32_80934Field(ownerRecord19, int*, 20);
        rawWord2 = argumentWord4-rawWord2;
        rawWord3 = retainedHeightTargetOrDivisor20-rawWord2;
        rawWord2 = rawWord3;
        if (rawWord3 < 0)rawWord2 = -rawWord2;
        if (rawWord2 >= 71){
            rawWord2 = rawWord3 < 71;
            if (rawWord2){
                rawWord2 = rawWord3 < -70;
            }
            else{
                rawWord2 = rawWord3 < -70;
                __asm__ volatile(""::"r"(rawWord2));
                rawWord3 = 70;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord2 = rawWord3 < -70;
            }
            if (!rawWord2){
                rawWord2 = argumentWord4+rawWord3;
                goto writeOriginalHeight171;
            }
            rawWord3 = -70;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2 = argumentWord4+rawWord3;
        writeOriginalHeight171:
            Level32_80934Field(ownerRecord19, int*, 20) = rawWord2;
        }
    }
    if ((Level32_80934Field(ownerRecord19, unsigned char *, 0x4D) != 0) || (Level32_80934Field(ownerRecord19, unsigned char *, 0x48) == 2)) {
        temporaryWord7 = Level32_80934Field(ownerRecord19, unsigned char *, 0x48);
        switch (temporaryWord7) {
        case 0:
            retainedPrivateResultOrAngle16 = Level32_80934Call4F334View1(ownerRecord19 + 0xC, (int)&Level32_80934Data70328View1);
            if (Level32_80934Field(privateRecord18, void **, 0x34) != 0) {
                Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0x1EU;
                goto callSharedOriginalCleanup653;
            }
            rawWord2 = Level32_80934Field(ownerRecord19, unsigned char*, 61);
            argumentWord4 = (int)ownerRecord19;
            if (rawWord2){
                Level32_80934Data6C770View1 = 0;
                rawWord2 = Level32_80934Field(ownerRecord19, unsigned char*, 61);
                argumentWord5 = Level32_80934Field(ownerRecord19, unsigned char*, 63);
                rawWord3 = 114;
                Level32_80934Field(ownerRecord19, signed char*, 64) = rawWord3;
                Level32_80934Field(ownerRecord19, unsigned char*, 61) = 0;
                Level32_80934Field(ownerRecord19, unsigned char*, 63) = 0;
                Level32_80934Field(ownerRecord19, unsigned char*, 60) = rawWord2;
                Level32_80934Field(ownerRecord19, unsigned char*, 62) = argumentWord5;
                Level32_80934Call35734View1(argumentWord4, argumentWord5);
            }
            Level32_80934Call3573CView1(ownerRecord19, 4, 0, 0);
            if ((Level32_80934Call359A4View1(privateRecord18 + 0x1C, 4) != 0) && (retainedPrivateResultOrAngle16 >= 0x5DD) && ({rawWord2 = Level32_80934Field(privateRecord18, int*, 48);rawWord2 = retainedPrivateResultOrAngle16 < rawWord2;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})) {
                temporaryWord8 = Level32_80934Field(ownerRecord19, int *, 0x14) - Level32_80934Field(ownerRecord19, short *, 0x38);
                temporaryWord2 = temporaryWord8 - Level32_80934Field((int)&Level32_80934Data70328View1, int *, 8);
                if (temporaryWord2 >= 0){
                    rawWord2 = temporaryWord2 < 2000;
                    argumentWord6 = 0;
                    if (rawWord2) goto checkOriginalAngle250;
                    goto checkOriginalTimedState286;
                }
                if ((Level32_80934Field((int)&Level32_80934Data70328View1, int *, 8) - temporaryWord8) < 0x7D0) {
                checkOriginalAngle250:
                    if ((Level32_80934Call4F264View1(Level32_80934Field(ownerRecord19, unsigned char *, 0x46), Level32_80934Call4E880View1(Level32_80934Field((int)&Level32_80934Data70328View1, int *, 0) - Level32_80934Field(ownerRecord19, int *, 0xC), Level32_80934Field((int)&Level32_80934Data70328View1, int *, 4) - Level32_80934Field(ownerRecord19, int *, 0x10), 0)) < 4) && (Level32_80934Call4F264View1(((int)(Level32_80934Data6E040View1 << 16) >> 20), Level32_80934Call4E880View1(Level32_80934Field(ownerRecord19, int *, 0xC) - Level32_80934Data6E020View1, Level32_80934Field(ownerRecord19, int *, 0x10) - Level32_80934Data6E024View1, 0)) < 0x1C)) {
                        Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 1U;
                        Level32_80934Call34F40View1(ownerRecord19, 1);
                        return;
                    }
                    goto checkOriginalTimedState286;
                }
                goto checkOriginalTimedState286;
            }
        checkOriginalTimedState286:
            if ((Level32_80934Field(privateRecord18, int *, 0x24) != 0) && (Level32_80934Call359A4View1(privateRecord18 + 0x28, 4) != 0)) {
                Level32_80934Field(privateRecord18, int *, 0x28) = Level32_80934Call3636CView1(0x8C, 0xB4);
                Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0x15U;
                return;
            }
            goto callSharedOriginalCleanup653;
        case 30:
            if (({rawWord2 = Level32_80934Data743ECView1(ownerRecord19, Level32_80934Field(privateRecord18, void**, 52), privateRecord18+56, privateRecord18+68, 30, 0)&1;Level32_80934Field(ownerRecord19, signed char*, 69) = 0;rawWord2;}) && (Level32_80934Field(Level32_80934Field(privateRecord18, void **, 0x34), short *, 2) == 0)) {
                Level32_80934Field(privateRecord18, void **, 0x34) = 0;
                Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0U;
            }
            goto callSharedOriginalCleanup653;
        case 20:
            temporaryWord3 = (Level32_80934Field(privateRecord18, int *, 0x20) * 0x10) + Level32_80934Field(Level32_80934Field(privateRecord18, void **, 0xC), int *, 0xC);
            if (Level32_80934Call3585CView1(ownerRecord19, Level32_80934Call4E880View1(Level32_80934Field(temporaryWord3, int *, 0) - Level32_80934Field(ownerRecord19, int *, 0xC), Level32_80934Field(temporaryWord3, int *, 4) - Level32_80934Field(ownerRecord19, int *, 0x10), 0), 5, 0x28, 1, 0) != 0) {
                Level32_80934Call35DDCView1(ownerRecord19, 0x78, 0, 0, 0);
                if (Level32_80934Call4F334View1(ownerRecord19 + 0xC, Level32_80934Field(Level32_80934Field(privateRecord18, void **, 0xC), int *, 0xC) + (Level32_80934Field(privateRecord18, int *, 0x20) * 0x10)) < 0x100) {
                    Level32_80934Field(Level32_80934Field(privateRecord18, void **, 0xC), short *, 2) = (short) Level32_80934Field(privateRecord18, int *, 0x20);
                    Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0U;
                }
            }
            goto callSharedOriginalCleanup653;
        case 21:
            if (Level32_80934Call35A80View1(ownerRecord19, Level32_80934Field(privateRecord18, void **, 0xC), 0x12C, 0x78, 0, 5, 0x28, 0) & 1) {
                Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0U;
            }
            goto callSharedOriginalCleanup653;
        case 1:
            rawWord2 = Level32_80934Call55E84View1(ownerRecord19);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 7;
            argumentWord6 = 0;
            argumentWord7 = 0;
            __asm__("":"=r"(argumentWord7):"0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(rawWord2):"$16");
            retainedPrivateResultOrAngle16 = rawWord2;
            Level32_80934Call3573CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            rawWord2 = Level32_80934Field(privateRecord18, int*, 44);
            if (rawWord2 == 0){
                rawWord2 = retainedPrivateResultOrAngle16 < 22;
                __asm__ volatile(""::"r"(rawWord2));
                if ((unsigned int) (retainedPrivateResultOrAngle16 - 5) < 0x10U) {
                    Level32_80934Call55D24View1(ownerRecord19, 4);
                    Level32_80934Call55F14View1(ownerRecord19, 0, &originalFrame.sp20);
                    Level32_80934Data74410View1(&originalFrame.sp20, 0x3A, 0xC, 8, 0xC);
                    temporaryWord4 = Level32_80934DataSpawnMobyView1(0x249, ownerRecord19);
                    Level32_80934Field(privateRecord18, void **, 0x2C) = temporaryWord4;
                    if (temporaryWord4 != 0) {
                        Level32_80934Field(temporaryWord4, signed char *, 0x48) = 0x64;
                        Level32_80934Field(Level32_80934Field(privateRecord18, void **, 0x2C), unsigned char *, 0x4F) = 0x50U;
                    }
                }
                rawWord2 = retainedPrivateResultOrAngle16 < 22;
            }
            else{
                rawWord2 = retainedPrivateResultOrAngle16 < 22;
            }
            if (rawWord2 == 0){
                temporaryWord10 = Level32_80934Field(privateRecord18, void **, 0x2C);
                if (temporaryWord10 != 0) {
                    retainedLinkedRecordPrivateOrCounter17 = Level32_80934Field(temporaryWord10, void **, 0);
                    Level32_80934Field(temporaryWord10, signed char *, 0x48) = 0x63;
                    Level32_80934Field(privateRecord18, int *, 0x1C) = 0x78;
                    Level32_80934Call4F178View1(&originalFrame.sp30, (int)&Level32_80934Data70328View1);
                    rawWord2 = Level32_80934Call1A358View1(&originalFrame.sp30, 4096);
                    argumentWord4 = originalFrame.sp38;
                    rawWord3 = rawWord2;
                    rawWord2 = argumentWord4-rawWord3;
                    if (rawWord2 >= 0){
                        rawWord2 = rawWord2 < 1800;
                        if (rawWord2){
                            rawWord2 = rawWord3+300;
                            goto writeOriginalFrameHeight463;
                        }
                        rawWord2 = rawWord3+300;
                        argumentWord4 = retainedLinkedRecordPrivateOrCounter17;
                        goto copyOriginalPreparedFrame465;
                    }
                    rawWord2 = rawWord3-argumentWord4;
                    if (rawWord2 < 1800){
                        rawWord2 = rawWord3+300;
                    writeOriginalFrameHeight463:
                        originalFrame.sp38 = rawWord2;
                    }
                    else{
                        rawWord2 = rawWord3+300;
                    }
                prepareOriginalFrameCopy464:
                    argumentWord4 = retainedLinkedRecordPrivateOrCounter17;
                copyOriginalPreparedFrame465:
                    __asm__ volatile(""::"r"(rawWord2));
                    Level32_80934Call4F1C8View1(argumentWord4, &originalFrame.sp30, Level32_80934Field(privateRecord18, void**, 44)+12);
                    Level32_80934Call4F08CView1(retainedLinkedRecordPrivateOrCounter17, Level32_80934Call4EDE8View1(retainedLinkedRecordPrivateOrCounter17, 1), 0xFA);
                    Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, short *, 0x10) = 0x78;
                    Level32_80934Field(retainedLinkedRecordPrivateOrCounter17, signed char *, 0x15) = 0x10;
                    Level32_80934Field(privateRecord18, void **, 0x2C) = 0;
                }
            }
            if (Level32_80934Data6C770View1 != 0) {
                if (Level32_80934Field(ownerRecord19, unsigned char *, 0x3D) != 0) {
                    Level32_80934Data6C770View1 = 0;
                    Level32_80934Field(ownerRecord19, signed char *, 0x40) = 0x72;
                    Level32_80934Field(ownerRecord19, unsigned char *, 0x3D) = 0U;
                    Level32_80934Field(ownerRecord19, unsigned char *, 0x3F) = 0U;
                    Level32_80934Call35734View1(ownerRecord19);
                }
                if (Level32_80934Field(privateRecord18, int *, 0x24) != 0) {
                    Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0x15U;
                }
                else {
                    temporaryWord5 = Level32_80934Data743C8View1(Level32_80934Field(privateRecord18, void **, 0xC));
                    temporaryWord11 = Level32_80934Field(privateRecord18, void **, 0xC);
                    Level32_80934Field(privateRecord18, int *, 0x20) = temporaryWord5;
                    if (temporaryWord5 == Level32_80934Field(temporaryWord11, short *, 2)) {
                        temporaryWord12 = Level32_80934Field(temporaryWord11, short *, 0);
                        Level32_80934Field(privateRecord18, int *, 0x20) = (int) ((int) (temporaryWord5 + Level32_80934Field(temporaryWord11, short *, 0xA) + temporaryWord12) % temporaryWord12);
                    }
                    Level32_80934Field(ownerRecord19, unsigned char *, 0x48) = 0x14U;
                }
            }
            goto callSharedOriginalCleanup653;
        case 2:
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = privateRecord18+4;
            argumentWord7 = privateRecord18+8;
            retainedHeightTargetOrDivisor20 = 4;
            retainedLinkedRecordPrivateOrCounter17 = 0;
            __asm__("":"=r"(retainedHeightTargetOrDivisor20):"0"(retainedHeightTargetOrDivisor20), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord7):"$2", "memory");
            retainedParticleVector22 = (int)&originalFrame.sp50;
            Level32_80934Call35030View1(argumentWord4, argumentWord5, Level32_80934Field(privateRecord18, int*, 0), argumentWord7, 12, 16, 300, 0x4001);
            Level32_80934Call55D24View1(ownerRecord19, 4);
            Level32_80934Call55F14View1(ownerRecord19, 5, &originalFrame.sp40);
            retainedParticleDistance21 = Level32_80934Call4F334View1(ownerRecord19 + 0xC, &originalFrame.sp40);
            do {
                Level32_80934Call4F178View1(retainedParticleVector22, (int)ownerRecord19+12);
                argumentWord5 = 128;
                argumentWord5 = argumentWord5/retainedHeightTargetOrDivisor20;
                retainedPrivateResultOrAngle16 = retainedLinkedRecordPrivateOrCounter17 << 8;
                retainedPrivateResultOrAngle16 = retainedPrivateResultOrAngle16/retainedHeightTargetOrDivisor20;
                rawWord2 = originalFrame.sp48;
                argumentWord4 = 0;
                originalFrame.sp58 = rawWord2;
                rawWord2 = Level32_80934Call363DCView1(argumentWord4, argumentWord5);
                retainedPrivateResultOrAngle16 += rawWord2;
                retainedPrivateResultOrAngle16 = (retainedPrivateResultOrAngle16&255)*2;
                originalFrame.sp50 += (int) (Level32_80934Field((int)&Level32_80934Data65920View1, short*, retainedPrivateResultOrAngle16) * retainedParticleDistance21) >> 0xC;
                retainedLinkedRecordPrivateOrCounter17 += 1;
                originalFrame.sp54 += (int) (Level32_80934Field((int)&Level32_80934Data658A0View1, short*, retainedPrivateResultOrAngle16) * retainedParticleDistance21) >> 0xC;
                originalFrame.sp60 = (Level32_80934DatarandView1() & 0x1F) - 0x10;
                originalFrame.sp64 = (Level32_80934DatarandView1() & 0x1F) - 0x10;
                originalFrame.sp68 = Level32_80934Call3636CView1(0x12, 0x18);
                Level32_80934DataSpawnParticleView1(1, 0xD, retainedParticleVector22, &originalFrame.sp60);
            }
            while (retainedLinkedRecordPrivateOrCounter17 < retainedHeightTargetOrDivisor20);
            if (Level32_80934Data6C770View1 != 0) {
                Level32_80934Call3BA00View1(ownerRecord19);
            callSharedOriginalRemoval649:
                Level32_80934Call55B18View1(ownerRecord19);
                return;
            }
            goto callSharedOriginalCleanup653;
        default:
        callSharedOriginalCleanup653:
            if (Level32_80934Field(privateRecord18, void **, 0x2C) != 0) {
                Level32_80934Call55D24View1(ownerRecord19, 4);
                Level32_80934Call55F14View1(ownerRecord19, 0, Level32_80934Field(privateRecord18, void **, 0x2C) + 0xC);
                temporaryWord9 = Level32_80934Field(privateRecord18, void **, 0x2C);
                Level32_80934Field(temporaryWord9, unsigned char *, 0x4F) = (unsigned char) (Level32_80934Field(temporaryWord9, unsigned char *, 0x4F) - 8);
                argumentWord4 = Level32_80934Field(privateRecord18, void **, 0x2C);
                if ((unsigned char) Level32_80934Field(argumentWord4, unsigned char *, 0x4F) < 0x20U) {
                    Level32_80934Field(argumentWord4, unsigned char *, 0x4F) = 0x20U;
                }
            }
            if (Level32_80934Data6C640View1 & 3) {
                Level32_80934Call35D38View1(ownerRecord19);
                Level32_80934Call5629CView1(ownerRecord19);
            }
            break;
        }
    }
}
#undef Level32_80934Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80081420.
 * AI generated; not human reviewed. All1506 native words,11 selectors and
 * one zero pad must match. Two original tables have5 and6 entries,pad after5.
 * Frame170 (368 bytes) saves S0..S7/FP/RA at SP148..16C. Explicit local
 * storage spans SP20..147. Vector homes begin20/30/40/50/60/78/88/98;
 * original controller words occupy A8/B0/B8/C0/C8/D0/D8/E0/E8/F0/F8/100/108/110.
 * Reserve contents are never read. Retained pitch is ordinary C naturally
 * allocated into FP;there is no fixed FP/SP or overlapping live GP alias.
 * Every local read has a producer on its original path,including frameE8
 * in each of the four count0..3 arms. No incoming saved value is consumed.
 * Original state0..4 and substate0..5 keep all callbacks,byte/halfword loads,
 * physical shared entries,record scans,target selection,bounded angle steps,
 * frame timers,four created owners and projectile/particle branches.
 * Tag scans use LHU masked7FFF,index*88,then separate signed LH of the
 * CURRENT entry before byte increment2 in the branch delay. They do not
 * inspect the following entry for termination. Pointer-table dereference
 * and byte-domain field offsets retain every original load.
 * All14 variable MULT sites form complete signed64 products from staged
 * signed32 operands. Five high and nine low captures use initialized full
 * values;low32 narrowing precedes each original signed shift. The two /100
 * precomputations store high>>5 and sign SEPARATELY,then subtract later.
 * Raw vectors:4500 gives high>>5=45,sign0; -4500 gives-46,sign-1,quotient-45.
 * /5(-100)=-20;32767*375>>10=11999;11999*32767 low32>>12=95989.
 * The /3 B0 high result executes before the negative sound-handle skip.
 * Original dynamic remainder DIV guards remain. HUD2803C is narrowed short
 * by the original caller:00018001 becomesFFFF8001.
 * Complete A0/A1 identities precede saved-result copies,allowing the two
 * original E880 returns to move into S0 in EDE8 call delays. Actual helper
 * inputs remain typed. 4F168 uses its single actual vector argument;the
 * original A1 setup survives because the preceding global store uses it.
 * Empty metadata consumes initialized values,original addresses or freshly
 * written fields,and clobbers dead GP roles only before their fresh producer.
 * It emits zero CPU instructions. No opcode asm or partial HILO input exists.
 * Level32 alone indexes both original tag lists by private halfword64,
 * conditions HUD creation on that value<2,and performs the identified wave
 * completion chain. The bit uses halfword64+1;byte64+3 and byte5 are saved
 * separately,then the incremented halfword64 is saved with length2. S3 is
 * reused as the checkpoint descriptor only after the owner state3 write,
 * its last owner use on that returning path. Projectile private0 is400.
 * Compiler,filter,flags,actual transfer/data-target and all EXE/overlay retail
 * hashes stay unchanged and mandatory. Confidence after gates is binary
 * identity. Complete allocation/caller/helper chains,units,fixed-point
 * domains,cadence beyond invocation,Rev1 mapping and synchronized retail
 * runtime verification remain open. Next:human review and retail captures.
 */
/* Original assembly SHA256 7464add17f85b9d674d6bfb4538aae1272f4b18b6edd75d514c434de2160c16a */
#define Level32_81420Keep(v) __asm__("":"=r"(v):"0"(v))
#define Level32_81420MultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level32_81420CaptureHigh(dst) do{int wholeCapturedHigh;__asm__("":"=h"(wholeCapturedHigh):"x"(completeSignedProduct));(dst)=wholeCapturedHigh;Level32_81420Keep(dst);}while(0)
#define Level32_81420CaptureLow(dst) do{int wholeCapturedLow;__asm__("":"=l"(wholeCapturedLow):"x"(completeSignedProduct));(dst)=wholeCapturedLow;Level32_81420Keep(dst);}while(0)
#define Level32_81420Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void Level32_81420Call135A4View1(void*,void*,int) __asm__("func_800135A4");
void Level32_81420Call135F8View1(void*,void*,void*) __asm__("func_800135F8");
int Level32_81420Call136F0View1(void*,void*,void*) __asm__("func_800136F0");
void Level32_81420Call13AE4View1(void*,void*) __asm__("func_80013AE4");
void Level32_81420Call13B7CView1(int) __asm__("func_80013B7C");
int Level32_81420Call13E38View1(void*,void*,int) __asm__("func_80013E38");
int Level32_81420Call18368View1(void*,void*) __asm__("func_80018368");
int Level32_81420Call2803CView1(int,int,void*,void*,void*,int*,int) __asm__("func_8002803C");
int Level32_81420Call3585CView1(void*,int,int,int,int,int) __asm__("func_8003585C");
int Level32_81420Call359A4View1(void*,int) __asm__("func_800359A4");
int Level32_81420Call3615CView1(int,int) __asm__("func_8003615C");
int Level32_81420Call3636CView1(int,int) __asm__("func_8003636C");
int Level32_81420Call363DCView1(int,int) __asm__("func_800363DC");
int Level32_81420Call369D8View1(int) __asm__("func_800369D8");
void Level32_81420Call3B7B4View1(void*,int,void*) __asm__("func_8003B7B4");
void Level32_81420Call3B74CView1(void*) __asm__("func_8003B74C");
int Level32_81420Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
void Level32_81420Call3BE70View1(int) __asm__("func_8003BE70");
int Level32_81420Call3BFC0View1(void*,int) __asm__("func_8003BFC0");
void Level32_81420Call3C0B0View1(int,int) __asm__("func_8003C0B0");
int Level32_81420Call4E880View1(int,int,int) __asm__("func_8004E880");
int Level32_81420Call4E9E4View1(int) __asm__("func_8004E9E4");
int Level32_81420Call4EA2CView1(int) __asm__("func_8004EA2C");
int Level32_81420Call4EDE8View1(void*,int) __asm__("func_8004EDE8");
void Level32_81420Call4F08CView1(void*,int,int) __asm__("func_8004F08C");
void Level32_81420Call4F168View1(void*) __asm__("func_8004F168");
void Level32_81420Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level32_81420Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
void Level32_81420Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
void Level32_81420Call55B18View1(void*) __asm__("func_80055B18");
void Level32_81420Call55D24View1(void*,int) __asm__("func_80055D24");
void Level32_81420Call55F14View1(void*,int,void*) __asm__("func_80055F14");
extern unsigned char Level32_81420Data658A0View1 __asm__("D_800658A0");
extern unsigned char Level32_81420Data658A0View2 __asm__("D_800658A0");
extern unsigned char Level32_81420Data65920View1 __asm__("D_80065920");
extern unsigned char Level32_81420Data66FCCView1 __asm__("D_80066FCC");
extern unsigned char Level32_81420Data68F7CView1 __asm__("D_80068F7C");
extern unsigned char Level32_81420Data68F90View1 __asm__("D_80068F90");
extern unsigned char Level32_81420Data69210View1 __asm__("D_80069210");
extern int Level32_81420Data6C54CView1 __asm__("D_8006C54C");
extern int Level32_81420Data6C550View1 __asm__("D_8006C550");
extern int Level32_81420Data6C628View1 __asm__("D_8006C628");
extern int Level32_81420Data6C640View1 __asm__("D_8006C640");
extern int Level32_81420Data6C648View1 __asm__("D_8006C648");
extern int Level32_81420Data6C6C4View1 __asm__("D_8006C6C4");
extern int Level32_81420Data6C6D0View1 __asm__("D_8006C6D0");
extern int Level32_81420Data6C730View1 __asm__("D_8006C730");
extern unsigned char Level32_81420Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Level32_81420Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level32_81420Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level32_81420Data6D088View1 __asm__("D_8006D088");
extern int Level32_81420Data6E048View1 __asm__("D_8006E048");
extern int Level32_81420Data6E160View1 __asm__("D_8006E160");
extern int Level32_81420Data6E174View1 __asm__("D_8006E174");
extern int Level32_81420Data6E178View1 __asm__("D_8006E178");
extern int Level32_81420Data6E17CView1 __asm__("D_8006E17C");
extern int Level32_81420Data6E53CView1 __asm__("D_8006E53C");
extern unsigned char Level32_81420Data6EE2CView1 __asm__("D_8006EE2C");
extern unsigned char Level32_81420Data70300View1 __asm__("D_80070300");
extern int Level32_81420Data70328View1 __asm__("D_80070328");
extern signed char Level32_81420Data71595View1 __asm__("D_80071595");
extern signed char Level32_81420Data71596View1 __asm__("D_80071596");
extern signed char Level32_81420Data71597View1 __asm__("D_80071597");
extern signed char Level32_81420Data71598View1 __asm__("D_80071598");
extern signed char Level32_81420Data71599View1 __asm__("D_80071599");
extern int Level32_81420Data719A8View1 __asm__("D_800719A8");
extern int Level32_81420Data719F0View1 __asm__("D_800719F0");
extern void(*Level32_81420DataSpawnFragmentsView1)(int,int,void*,void*,int,short) __asm__("SpawnFragments");
extern void*(*Level32_81420DataSpawnMobyView1)(int,void*) __asm__("SpawnMoby");
extern void*(*Level32_81420DataSpawnParticleView1)(int,int,void*,void*) __asm__("SpawnParticle");
extern unsigned char Level32_81420Call27A60View1 __asm__("func_80027A60");
extern unsigned char Level32_81420Call27EE4View1 __asm__("func_80027EE4");
extern unsigned char Level32_81420Call29AA0View1 __asm__("func_80029AA0");
extern void(*Level32_81420Data74318View1)(void*,int) __asm__("unk_ovlheader_80074318");
extern void(*Level32_81420Data74410View1)(void*,int,int,int,int) __asm__("unk_ovlheader_80074410");
void func_level_32_80081420(void* ownerParameter) {
    register int vectorOrScalar16 __asm__("$16"),counterSelectedOwnerOrCosine17 __asm__("$17"),selectedOwnerVectorOrSine18 __asm__("$18"),ownerOrCompletedWaveDescriptor19 __asm__("$19"),privateRecord20 __asm__("$20"),tagCursorRecordCursorOrParticleCount21 __asm__("$21"),positionOrInitializedOne22 __asm__("$22"),differenceVectorOrTimerBound23 __asm__("$23");
    register int resultOrField2 __asm__("$2"),fieldOrIntermediate3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrField6 __asm__("$6"),argumentOrField7 __asm__("$7"),scratchOrCapturedHalf8 __asm__("$8"),scratchOrCapturedHalf9 __asm__("$9"),capturedHigh10 __asm__("$10");
    int retainedOriginalPitch;
    long long completeSignedProduct;
    struct {
        int sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104,sp108,sp10C,sp110,sp114,sp118,sp11C,sp120,sp124,sp128,sp12C,sp130,sp134,sp138,sp13C,sp140,sp144;
    }
    originalFrame;
    int temp_a1;
    int temp_v0;
    int temp_v0_8;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_5;
    int temp_a0;
    int temp_v0_9;
    int var_a0_5;
    ownerOrCompletedWaveDescriptor19=(int)ownerParameter;
    Level32_81420Keep(ownerOrCompletedWaveDescriptor19);
    privateRecord20 = Level32_81420Field(ownerOrCompletedWaveDescriptor19, int*, 0);
    if (Level32_81420Field(privateRecord20, short *, 0x66) == 0) {
        goto block_9;
    }
    if ((unsigned int) (Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x48) - 3) < 2U) {
        goto block_9;
    }
    counterSelectedOwnerOrCosine17 = 0;
    vectorOrScalar16 = privateRecord20;
loop_3:
    temp_a0 = Level32_81420Field(vectorOrScalar16,int*,0);
    if (temp_a0 == 0) {
        goto block_5;
    }
    Level32_81420Call55B18View1(temp_a0);
    Level32_81420Field(vectorOrScalar16,int*,0) = 0;
block_5:
    counterSelectedOwnerOrCosine17 += 1;
    vectorOrScalar16 += 4;
    if (counterSelectedOwnerOrCosine17 < 4) {
        goto loop_3;
    }
    if (Level32_81420Call3BFC0View1(ownerOrCompletedWaveDescriptor19, Level32_81420Field(privateRecord20, int *, 0x34)) == 0) {
        goto block_8;
    }
    Level32_81420Call3BE70View1(Level32_81420Field(privateRecord20, int *, 0x34));
block_8:
    __asm__ volatile(""::"m"(Level32_81420Field(privateRecord20,int*,52)));
    Level32_81420Field(privateRecord20, int *, 0x34) = -1;
    Level32_81420Field(ownerOrCompletedWaveDescriptor19, int *, 0x18) = 0x10000;
    Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x51) = (unsigned char) Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x46);
    Level32_81420DataSpawnFragmentsView1(9, 0x8E, ownerOrCompletedWaveDescriptor19, Level32_81420Field(privateRecord20, int *, 0x78), 0, 0x100);
    Level32_81420Data74410View1(ownerOrCompletedWaveDescriptor19 + 0xC, 0x27, 0x30, 0x50, 0x78);
    argumentOrField5=0x10000080;
    fieldOrIntermediate3=(int)&Level32_81420Data70328View1+580;
    resultOrField2=40;
    Level32_81420Field(privateRecord20,int*,16)=resultOrField2;
    resultOrField2=57;
    Level32_81420Field(fieldOrIntermediate3,int*,0)=0;
    Level32_81420Field((int)&Level32_81420Data70328View1,int*,524)=argumentOrField5;
    Level32_81420Field((int)&Level32_81420Data70328View1,int*,572)=resultOrField2;
    Level32_81420Call4F168View1(fieldOrIntermediate3-440);
    Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x41) = 0;
    Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x4C) = 0;
    Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x4D) = 0;
    Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x48) = 4U;
block_9:
    resultOrField2=Level32_81420Data6C640View1;
    Level32_81420Field(ownerOrCompletedWaveDescriptor19,int*,24)=0;
    if (resultOrField2 == 0) {
        goto block_12;
    }
    if (Level32_81420Data6C54CView1 != 0) {
        goto block_12;
    }
    Level32_81420Field((int)&Level32_81420Data70300View1,unsigned char*,Level32_81420Field((int)&Level32_81420Data66FCCView1, unsigned char *, 0x12)) = 0;
    Level32_81420Field((int)&Level32_81420Data70300View1,unsigned char*,Level32_81420Field((int)&Level32_81420Data66FCCView1, unsigned char *, 0x1C)) = 0;
    Level32_81420Field((int)&Level32_81420Data70300View1,unsigned char*,Level32_81420Field((int)&Level32_81420Data66FCCView1, unsigned char *, 0x26)) = 0;
    Level32_81420Field((int)&Level32_81420Data70300View1,unsigned char*,Level32_81420Field((int)&Level32_81420Data66FCCView1, unsigned char *, 0x30)) = 0;
    Level32_81420Data71599View1 = 0;
    Level32_81420Data71595View1 = 0;
    Level32_81420Data71596View1 = 0;
    Level32_81420Data71597View1 = 0;
    Level32_81420Data71598View1 = 0;
block_12:
    temp_v1 = Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x48);
    if (temp_v1 >= 5U) {
        goto block_189;
    }
    switch (temp_v1){
    case 0:
        Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x4F) = 0x14;
        Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x49) = 0U;
        return;
    case 4:
        if (Level32_81420Field(privateRecord20, int *, 0x10) >= 0x26) {
            goto block_17;
        }
        Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x20C) = 0x10000002;
    block_17:
        Level32_81420Call4F168View1((int)&Level32_81420Data70328View1 + 0x8C);
        if (Level32_81420Call359A4View1(privateRecord20 + 0x10, 4) == 0) {
            goto block_189;
        }
        goto commitOriginalWaveFields;
    case 1:
        Level32_81420Call4F178View1(&originalFrame.sp20, ownerOrCompletedWaveDescriptor19 + 0xC);
        originalFrame.sp28 += 0x1F4;
        temp_v1_2 = Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x49);
        if (temp_v1_2 >= 6U) {
            goto block_189;
        }
        switch (temp_v1_2){
        case 0:
            Level32_81420Call4F178View1((int)&Level32_81420Data6E17CView1, Level32_81420Field(Level32_81420Field(privateRecord20, int*, 0x3C), int *, 0xC) + 0x10);
            temp_a1 = Level32_81420Field(Level32_81420Field(privateRecord20, int*, 0x3C), int *, 0xC);
            Level32_81420Call136F0View1((int)&Level32_81420Data6E17CView1 - 0x14, temp_a1, temp_a1 + 0x10);
            Level32_81420Data6E174View1 = 0;
            Level32_81420Data6E178View1 = 0;
            Level32_81420Data6E160View1 = 0x11;
            goto block_36;
        case 1:
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x20C) = 0x10000002;
            goto block_36;
        case 2:
            if (Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x214) >= 2) {
                goto block_25;
            }
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x20C) = 0x10000040;
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x218) = 0;
            vectorOrScalar16 = (int)&Level32_81420Data70328View1 + 0x214 + 0x18;
            Level32_81420Call4F178View1(vectorOrScalar16, Level32_81420Field(Level32_81420Field(privateRecord20, int*, 0x38), int*, 0xC));
            Level32_81420Call4F1C8View1(&originalFrame.sp20, &originalFrame.sp20, vectorOrScalar16);
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x238) = Level32_81420Call4E880View1(originalFrame.sp20, originalFrame.sp24, 0);
            return;
        block_25:
            Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x47) = 7;
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x214) = 0;
            resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,73);
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,int*,8)=0;
            goto incrementLoadedSubstate;
        case 3:
            Level32_81420Call4F1C8View1(&originalFrame.sp30, &originalFrame.sp20, (int)&Level32_81420Data70328View1);
            if (Level32_81420Call4EDE8View1(&originalFrame.sp30, 1) < 0x201) {
                goto block_28;
            }
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x20C) = 0x10000100;
            Level32_81420Call4F178View1((int)&Level32_81420Data70328View1 + 0x22C, &originalFrame.sp20);
            return;
        block_28:
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x288) = 1;
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x1CC) = 0x5A;
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x20C) = 0x10000002;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x47) = 2;
            if (Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x3C) == 1) {
                goto block_36;
            }
            fieldOrIntermediate3=1;
            resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,short*,54);
            resultOrField2*=4;
            resultOrField2=Level32_81420Field((int)&Level32_81420Data6EE2CView1,int*,resultOrField2);
            resultOrField2=Level32_81420Field(resultOrField2,int*,64);
            Level32_81420Data6C770View1=0;
            resultOrField2=Level32_81420Field(resultOrField2,unsigned char*,0);
            fieldOrIntermediate3=1;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,60)=fieldOrIntermediate3;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,61)=fieldOrIntermediate3;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,62)=0;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,63)=fieldOrIntermediate3;
            resultOrField2=-((unsigned int)resultOrField2>=2U)&48;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,64)=resultOrField2;
            goto block_36;
        case 4:
            if (Level32_81420Data6C770View1 == 0) {
                goto block_34;
            }
            if (Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x3D) != 1) {
                goto block_34;
            }
            if (Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x3C) == 2) {
                goto block_34;
            }
            fieldOrIntermediate3=2;
            resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,short*,54);
            resultOrField2*=4;
            resultOrField2=Level32_81420Field((int)&Level32_81420Data6EE2CView1,int*,resultOrField2);
            resultOrField2=Level32_81420Field(resultOrField2,int*,68);
            Level32_81420Data6C770View1=0;
            resultOrField2=Level32_81420Field(resultOrField2,unsigned char*,0);
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,60)=fieldOrIntermediate3;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,61)=fieldOrIntermediate3;
            fieldOrIntermediate3=1;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,62)=0;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,63)=fieldOrIntermediate3;
            resultOrField2=-((unsigned int)resultOrField2>=2U)&48;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,64)=resultOrField2;
        block_34:
            __asm__ volatile("":::"$16");
            resultOrField2=Level32_81420Field(privateRecord20,int*,56);
            vectorOrScalar16=(int)&originalFrame.sp40;
            argumentOrField5=Level32_81420Field(resultOrField2,int*,12);
            argumentOrField4=vectorOrScalar16;
            Level32_81420Call4F178View1(argumentOrField4,argumentOrField5+16);
            resultOrField2=Level32_81420Call3585CView1(ownerOrCompletedWaveDescriptor19, Level32_81420Call4E880View1(originalFrame.sp40 - Level32_81420Field(ownerOrCompletedWaveDescriptor19, int *, 0xC), originalFrame.sp44 - Level32_81420Field(ownerOrCompletedWaveDescriptor19, int *, 0x10), 0) & 0xFF, 5, 1, 0, 0);
            __asm__("":"=r"(ownerOrCompletedWaveDescriptor19):"0"(ownerOrCompletedWaveDescriptor19),"r"(resultOrField2));
            selectedOwnerVectorOrSine18=(int)&originalFrame.sp50;
            argumentOrField4=selectedOwnerVectorOrSine18;
            argumentOrField5=vectorOrScalar16;
            __asm__("":"=r"(argumentOrField4):"0"(argumentOrField4),"r"(argumentOrField5));
            counterSelectedOwnerOrCosine17=ownerOrCompletedWaveDescriptor19+12;
            Level32_81420Call4F1C8View1(argumentOrField4,argumentOrField5,counterSelectedOwnerOrCosine17);
            temp_v0 = Level32_81420Call4EDE8View1(&originalFrame.sp50, 1);
            Level32_81420Call4F08CView1(&originalFrame.sp50, temp_v0, 0x50);
            Level32_81420Call4F194View1(counterSelectedOwnerOrCosine17, counterSelectedOwnerOrCosine17, &originalFrame.sp50);
            if (temp_v0 >= 0x200) {
                goto block_38;
            }
            Level32_81420Call4F178View1((int)&Level32_81420Data70328View1, Level32_81420Field(Level32_81420Field(privateRecord20, int*, 0x38), int*, 0xC) + 0x20);
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x64) = (int) (Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x46) * 0x10);
            Level32_81420Field(ownerOrCompletedWaveDescriptor19, signed char *, 0x4F) = 0x20;
            Level32_81420Call135A4View1(&originalFrame.sp60, (int)&Level32_81420Data69210View1, Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x64));
            Level32_81420Call135F8View1(&originalFrame.sp50, &originalFrame.sp60, (int)&Level32_81420Data70328View1);
            Level32_81420Call13AE4View1(&originalFrame.sp50, (int)&Level32_81420Data70328View1);
        block_36:
        block_37:
            resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,73);
            incrementLoadedSubstate:resultOrField2++;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,73)=resultOrField2;
            return;
        block_38:
            Level32_81420Call4F178View1((int)&Level32_81420Data70328View1, counterSelectedOwnerOrCosine17);
            return;
        case 5:
            Level32_81420Data74318View1(ownerOrCompletedWaveDescriptor19, 0x96);
            if (Level32_81420Data6E048View1 != 2) {
                goto block_189;
            }
            Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0x280) = 3;
            Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x48) = 2U;
            Level32_81420Call13B7CView1(0);
            return;
            default:return;
        }
    case 2:
    case 3:
        scratchOrCapturedHalf8=1;
        originalFrame.spA8=0;
        originalFrame.spB0=0;
        originalFrame.spB8=0;
        originalFrame.spC0=scratchOrCapturedHalf8;
        if (Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x48) != 2) {
            goto block_43;
        }
        Level32_81420Data74318View1(ownerOrCompletedWaveDescriptor19, 0x96);
    block_43:
        Level32_81420Data6C6D0View1 = 0;
        Level32_81420Call135A4View1((int)&Level32_81420Data719A8View1, (int)&Level32_81420Data68F7CView1, 0);
        Level32_81420Call135A4View1((int)&Level32_81420Data719F0View1, (int)&Level32_81420Data68F90View1, 0);
        Level32_81420Call55D24View1(ownerOrCompletedWaveDescriptor19, 4);
        resultOrField2=Level32_81420Call3BFC0View1(ownerOrCompletedWaveDescriptor19,Level32_81420Field(privateRecord20,int*,52));
        fieldOrIntermediate3=0x55550000;
        if(resultOrField2)goto prepareOriginalHandlePitch;
        Level32_81420Keep(resultOrField2);
        resultOrField2=Level32_81420Call3BABCView1(ownerOrCompletedWaveDescriptor19,(argumentOrField5=0),4);
        Level32_81420Field(privateRecord20,int*,52)=resultOrField2;
        fieldOrIntermediate3=0x55550000;
        prepareOriginalHandlePitch:resultOrField2=Level32_81420Field((int)&Level32_81420Data70328View1,int*,176);
        fieldOrIntermediate3|=0x5556;
        Level32_81420MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        argumentOrField4=Level32_81420Field(privateRecord20,int*,52);
        resultOrField2>>=31;
        Level32_81420CaptureHigh(scratchOrCapturedHalf9);
        resultOrField2=scratchOrCapturedHalf9-resultOrField2;
        argumentOrField5=resultOrField2+3048;
        if(argumentOrField4>=0)Level32_81420Call3C0B0View1(argumentOrField4,argumentOrField5);
        block_47:argumentOrField4=Level32_81420Field(privateRecord20,short*,100);
        if(argumentOrField4>=2)goto block_49;
        resultOrField2=-1;
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,124);
        if(fieldOrIntermediate3!=resultOrField2)goto block_49;
        resultOrField2=Level32_81420Call369D8View1(argumentOrField4);
        Level32_81420Data6C6C4View1=resultOrField2;
        Level32_81420Field(privateRecord20,int*,124)=(short)Level32_81420Call2803CView1(23,320,&Level32_81420Call27EE4View1,&Level32_81420Call27A60View1,&Level32_81420Call29AA0View1,&Level32_81420Data6C628View1,resultOrField2);
        block_49:argumentOrField5=Level32_81420Data6C550View1;
        resultOrField2=Level32_81420Field(privateRecord20,short*,100);
        __asm__ volatile(""::"m"(Level32_81420Field(privateRecord20,short*,100)):"$3");
        fieldOrIntermediate3=Level32_81420Data6C730View1;
        Level32_81420Data6C628View1=0;
        resultOrField2*=4;
        resultOrField2+=fieldOrIntermediate3;
        argumentOrField4=Level32_81420Field(resultOrField2,int*,0);
        loop_50:resultOrField2=Level32_81420Field(argumentOrField4,unsigned short*,0);
        resultOrField2&=32767;
        fieldOrIntermediate3=resultOrField2*11;
        fieldOrIntermediate3*=8;
        fieldOrIntermediate3=argumentOrField5+fieldOrIntermediate3;
        resultOrField2=Level32_81420Field(fieldOrIntermediate3,unsigned char*,72);
        resultOrField2=(unsigned int)resultOrField2<128U;
        if(!resultOrField2)goto block_52;
        resultOrField2=Level32_81420Field(fieldOrIntermediate3,unsigned char*,61);
        if(!resultOrField2)goto block_53;
        block_52:resultOrField2=Level32_81420Data6C628View1;
        resultOrField2++;
        Level32_81420Data6C628View1=resultOrField2;
        block_53:resultOrField2=Level32_81420Field(argumentOrField4,short*,0);
        argumentOrField4+=2;
        if(resultOrField2>=0)goto loop_50;
        argumentOrField4=Level32_81420Field(privateRecord20,short*,100);
        tagCursorRecordCursorOrParticleCount21=1;
        if(argumentOrField4>=2)goto chooseOriginalParticleFrequency;
        resultOrField2=Level32_81420Call369D8View1(argumentOrField4);
        argumentOrField5=1;
        if(resultOrField2)goto processRemainingOriginalWave;
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,72);
        resultOrField2=fieldOrIntermediate3*11;
        fieldOrIntermediate3=Level32_81420Data6C550View1;
        resultOrField2*=8;
        fieldOrIntermediate3+=resultOrField2;
        Level32_81420Keep(fieldOrIntermediate3);
        counterSelectedOwnerOrCosine17=Level32_81420Field(fieldOrIntermediate3,int*,0);
        resultOrField2=3;
        Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,72)=resultOrField2;
        ownerOrCompletedWaveDescriptor19=(int)&Level32_81420Data6D088View1;
        argumentOrField6=ownerOrCompletedWaveDescriptor19;
        Level32_81420Keep(argumentOrField6);
        resultOrField2=1;
        argumentOrField4=Level32_81420Field(privateRecord20,short*,100);
        fieldOrIntermediate3=Level32_81420Data6C7B4View1;
        argumentOrField4++;
        resultOrField2<<=argumentOrField4;
        fieldOrIntermediate3|=resultOrField2;
        vectorOrScalar16=counterSelectedOwnerOrCosine17+2;
        Level32_81420Data6C7B4View1=fieldOrIntermediate3;
        resultOrField2=Level32_81420Field(privateRecord20,unsigned char*,100);
        argumentOrField4=vectorOrScalar16;
        resultOrField2+=3;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,2)=resultOrField2;
        Level32_81420Call3B7B4View1(argumentOrField4,argumentOrField5,argumentOrField6);
        argumentOrField4=vectorOrScalar16;
        argumentOrField5=1;
        Level32_81420Keep(argumentOrField5);
        selectedOwnerVectorOrSine18=(int)&Level32_81420Data6C7F8View1;
        Level32_81420Call3B7B4View1(argumentOrField4,argumentOrField5,selectedOwnerVectorOrSine18);
        vectorOrScalar16=counterSelectedOwnerOrCosine17+5;
        argumentOrField4=vectorOrScalar16;
        argumentOrField5=1;
        argumentOrField6=ownerOrCompletedWaveDescriptor19;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5),"=r"(argumentOrField6):"0"(argumentOrField4),"1"(argumentOrField5),"2"(argumentOrField6));
        resultOrField2=2;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,5)=resultOrField2;
        Level32_81420Call3B7B4View1(argumentOrField4,argumentOrField5,argumentOrField6);
        Level32_81420Call3B7B4View1(vectorOrScalar16,1,selectedOwnerVectorOrSine18);
        vectorOrScalar16=privateRecord20+100;
        argumentOrField4=vectorOrScalar16;
        argumentOrField5=2;
        resultOrField2=Level32_81420Field(privateRecord20,unsigned short*,100);
        argumentOrField6=ownerOrCompletedWaveDescriptor19;
        resultOrField2++;
        Level32_81420Field(privateRecord20,unsigned short*,100)=resultOrField2;
        Level32_81420Call3B7B4View1(argumentOrField4,argumentOrField5,argumentOrField6);
        Level32_81420Call3B7B4View1(vectorOrScalar16,2,selectedOwnerVectorOrSine18);
        commitOriginalWaveFields:Level32_81420Call3B74CView1((int)&Level32_81420Data6D088View1);
        return;
        processRemainingOriginalWave:resultOrField2=Level32_81420Field(privateRecord20,short*,100);
        argumentOrField4=ownerOrCompletedWaveDescriptor19;
        if(resultOrField2>=2)goto block_165;
        argumentOrField5=1;
        Level32_81420Keep(argumentOrField5);
        vectorOrScalar16=(int)&originalFrame.sp60;
        scratchOrCapturedHalf8=Level32_81420Field((int)&Level32_81420Data70328View1,int*,100);
        retainedOriginalPitch=Level32_81420Field((int)&Level32_81420Data70328View1,int*,96);
        argumentOrField6=vectorOrScalar16;
        originalFrame.spD0=0;
        originalFrame.spC8=scratchOrCapturedHalf8;
        Level32_81420Call55F14View1(argumentOrField4,argumentOrField5,argumentOrField6);
        scratchOrCapturedHalf9=99999999;
        differenceVectorOrTimerBound23=(int)&originalFrame.sp30;
        originalFrame.spD8=scratchOrCapturedHalf9;
        originalFrame.spE0=vectorOrScalar16;
        resultOrField2=Level32_81420Field(privateRecord20,short*,100);
        fieldOrIntermediate3=Level32_81420Data6C730View1;
        resultOrField2*=4;
        resultOrField2+=fieldOrIntermediate3;
        tagCursorRecordCursorOrParticleCount21=Level32_81420Field(resultOrField2,int*,0);
        loop_56:fieldOrIntermediate3=Level32_81420Field(tagCursorRecordCursorOrParticleCount21,unsigned short*,0);
        fieldOrIntermediate3&=32767;
        resultOrField2=fieldOrIntermediate3*11;
        fieldOrIntermediate3=Level32_81420Data6C550View1;
        resultOrField2*=8;
        selectedOwnerVectorOrSine18=fieldOrIntermediate3+resultOrField2;
        fieldOrIntermediate3=Level32_81420Field(selectedOwnerVectorOrSine18,unsigned char*,72);
        resultOrField2=(unsigned int)fieldOrIntermediate3<128U;
        if(!resultOrField2)goto block_68;
        resultOrField2=1;
        if(fieldOrIntermediate3==resultOrField2)goto block_68;
        counterSelectedOwnerOrCosine17=99999999;
        argumentOrField4=differenceVectorOrTimerBound23;
        positionOrInitializedOne22=selectedOwnerVectorOrSine18+12;
        argumentOrField6=originalFrame.spE0;
        Level32_81420Call4F1C8View1(argumentOrField4,positionOrInitializedOne22,argumentOrField6);
        resultOrField2=Level32_81420Call4E880View1(originalFrame.sp30,originalFrame.sp34,1);
        argumentOrField4=differenceVectorOrTimerBound23;
        argumentOrField5=0;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call4EDE8View1(argumentOrField4,argumentOrField5);
        argumentOrField4=resultOrField2;
        argumentOrField5=originalFrame.sp38;
        resultOrField2=Level32_81420Call4E880View1(argumentOrField4,argumentOrField5,1);
        argumentOrField5=vectorOrScalar16;
        argumentOrField4=originalFrame.spC8;
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call3615CView1(argumentOrField4,argumentOrField5);
        argumentOrField4=retainedOriginalPitch;
        argumentOrField5=vectorOrScalar16;
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call3615CView1(argumentOrField4,argumentOrField5);
        if(vectorOrScalar16>=0)goto block_60;
        vectorOrScalar16=-vectorOrScalar16;
        block_60:if(vectorOrScalar16>=512)goto block_66;
        if(resultOrField2>=0)goto block_63;
        resultOrField2=-resultOrField2;
        block_63:if(resultOrField2>=512)goto block_66;
        resultOrField2=Level32_81420Call13E38View1(originalFrame.spE0,positionOrInitializedOne22,0);
        argumentOrField4=differenceVectorOrTimerBound23;
        if(!resultOrField2)goto block_66;
        counterSelectedOwnerOrCosine17=Level32_81420Call4EDE8View1(argumentOrField4,1);
        block_66:scratchOrCapturedHalf8=originalFrame.spD8;
        resultOrField2=counterSelectedOwnerOrCosine17<scratchOrCapturedHalf8;
        if(!resultOrField2)goto block_68;
        originalFrame.spB0=selectedOwnerVectorOrSine18;
        originalFrame.spD8=counterSelectedOwnerOrCosine17;
        block_68:resultOrField2=Level32_81420Field(tagCursorRecordCursorOrParticleCount21,short*,0);
        tagCursorRecordCursorOrParticleCount21+=2;
        if(resultOrField2>=0)goto loop_56;
        scratchOrCapturedHalf9=originalFrame.spB0;
        if(scratchOrCapturedHalf9)goto block_72;
        resultOrField2=Level32_81420Field(privateRecord20,int*,44);
        if(resultOrField2)goto block_72;
        Level32_81420Keep(resultOrField2);
        Level32_81420Field(privateRecord20,int*,28)=0;
        Level32_81420Field(privateRecord20,int*,32)=0;
        Level32_81420Field(privateRecord20,int*,40)=0;
        Level32_81420Field(privateRecord20,int*,36)=0;
    block_72:
        temp_v1_5 = Level32_81420Field(Level32_81420Field(privateRecord20, int*, 0x1C), unsigned char *, 0x48);
        if (temp_v1_5 >= 0x80U) {
            goto block_74;
        }
        if (temp_v1_5 != 1) {
            goto block_75;
        }
    block_74:
        Level32_81420Field(privateRecord20, int*, 0x1C) = 0;
        Level32_81420Field(privateRecord20, int*, 0x30) = 0;
        Level32_81420Field(privateRecord20, int *, 0x2C) = 0;
        Level32_81420Field(privateRecord20, int *, 0x28) = 0;
        block_75:resultOrField2=Level32_81420Field(privateRecord20,int*,40);
        if(resultOrField2)goto block_82;
        resultOrField2=Level32_81420Field(privateRecord20,int*,28);
        scratchOrCapturedHalf8=originalFrame.spB0;
        if(scratchOrCapturedHalf8==resultOrField2)goto block_82;
        resultOrField2=Level32_81420Field(privateRecord20,int*,32);
        if(resultOrField2==scratchOrCapturedHalf8)goto block_79;
        Level32_81420Field(privateRecord20,int*,36)=0;
        block_79:scratchOrCapturedHalf9=originalFrame.spB0;
        resultOrField2=Level32_81420Field(privateRecord20,int*,36);
        fieldOrIntermediate3=Level32_81420Data6C648View1;
        argumentOrField4=Level32_81420Field(privateRecord20,int*,28);
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(privateRecord20,int*,32)=scratchOrCapturedHalf9;
        Level32_81420Field(privateRecord20,int*,36)=resultOrField2;
        if(!argumentOrField4)goto block_81;
        if(resultOrField2<41)goto block_82;
        block_81:resultOrField2=Level32_81420Field(privateRecord20,int*,32);
        Level32_81420Field(privateRecord20,int*,36)=0;
        Level32_81420Field(privateRecord20,int*,40)=0;
        Level32_81420Field(privateRecord20,int*,28)=resultOrField2;
        block_82:argumentOrField5=Level32_81420Field(privateRecord20,int*,28);
        selectedOwnerVectorOrSine18=(int)&originalFrame.sp78;
        if(!argumentOrField5)goto block_106;
        argumentOrField4=selectedOwnerVectorOrSine18;
        Level32_81420Keep(argumentOrField4);
        argumentOrField5+=12;
        Level32_81420Call4F1C8View1(argumentOrField4,argumentOrField5,&originalFrame.sp60);
        resultOrField2=Level32_81420Call4E880View1(originalFrame.sp78,originalFrame.sp7C,1);
        argumentOrField4=selectedOwnerVectorOrSine18;
        argumentOrField5=0;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call4EDE8View1(argumentOrField4,argumentOrField5);
        argumentOrField4=resultOrField2;
        argumentOrField5=originalFrame.sp80;
        resultOrField2=Level32_81420Call4E880View1(argumentOrField4,argumentOrField5,1);
        argumentOrField5=vectorOrScalar16;
        argumentOrField4=originalFrame.spC8;
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call3615CView1(argumentOrField4,argumentOrField5);
        counterSelectedOwnerOrCosine17=resultOrField2;
        argumentOrField4=retainedOriginalPitch;
        argumentOrField5=vectorOrScalar16;
        resultOrField2=Level32_81420Call3615CView1(argumentOrField4,argumentOrField5);
        fieldOrIntermediate3=resultOrField2;
        resultOrField2=counterSelectedOwnerOrCosine17<833;
        if(resultOrField2)goto block_85;
        counterSelectedOwnerOrCosine17=832;
        Level32_81420Keep(counterSelectedOwnerOrCosine17);
        block_85:resultOrField2=counterSelectedOwnerOrCosine17<-832;
        if(!resultOrField2)goto block_87;
        counterSelectedOwnerOrCosine17=-832;
        block_87:resultOrField2=fieldOrIntermediate3<833;
        if(resultOrField2)goto block_89;
        fieldOrIntermediate3=832;
        Level32_81420Keep(fieldOrIntermediate3);
        block_89:resultOrField2=fieldOrIntermediate3<-832;
        argumentOrField4=selectedOwnerVectorOrSine18;
        if(!resultOrField2)goto block_91;
        fieldOrIntermediate3=-832;
        block_91:scratchOrCapturedHalf8=originalFrame.spC8;
        argumentOrField5=1;
        resultOrField2=(scratchOrCapturedHalf8+counterSelectedOwnerOrCosine17)&4095;
        originalFrame.spC8=resultOrField2;
        resultOrField2=retainedOriginalPitch+fieldOrIntermediate3;
        retainedOriginalPitch=resultOrField2&4095;
        resultOrField2=Level32_81420Call4EDE8View1(argumentOrField4,argumentOrField5);
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,28);
        originalFrame.spD0=resultOrField2;
        if(!fieldOrIntermediate3)goto block_106;
        argumentOrField5=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,70);
        argumentOrField4=originalFrame.spC8;
        argumentOrField5*=16;
        resultOrField2=Level32_81420Call3615CView1(argumentOrField4,argumentOrField5);
        argumentOrField4=retainedOriginalPitch;
        argumentOrField5=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        vectorOrScalar16=resultOrField2;
        argumentOrField5*=16;
        resultOrField2=Level32_81420Call3615CView1(argumentOrField4,argumentOrField5);
        argumentOrField4=250;
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,40);
        argumentOrField5=resultOrField2;
        if(!fieldOrIntermediate3)goto block_94;
        argumentOrField4=312;
        block_94:resultOrField2=vectorOrScalar16;
        if(vectorOrScalar16>=0)goto block_96;
        resultOrField2=-resultOrField2;
        block_96:Level32_81420Field(privateRecord20,int*,20)=retainedOriginalPitch;
        scratchOrCapturedHalf9=originalFrame.spC8;
        resultOrField2=resultOrField2<argumentOrField4;
        Level32_81420Field(privateRecord20,int*,24)=scratchOrCapturedHalf9;
        if(!resultOrField2)goto block_101;
        resultOrField2=argumentOrField5;
        if(argumentOrField5>=0)goto block_99;
        resultOrField2=-resultOrField2;
        block_99:resultOrField2=resultOrField2<argumentOrField4;
        if(!resultOrField2)goto block_101;
        __asm__ volatile(""::"r"(resultOrField2));
        scratchOrCapturedHalf8=1;
        originalFrame.spA8=scratchOrCapturedHalf8;
        block_101:argumentOrField5=Level32_81420Field(privateRecord20,int*,28);
        argumentOrField4=(int)&originalFrame.sp60;
        if(!argumentOrField5)goto block_106;
        argumentOrField5+=12;
        resultOrField2=Level32_81420Call13E38View1(argumentOrField4,argumentOrField5,0);
        argumentOrField4=privateRecord20+44;
        if(resultOrField2)goto block_107;
        resultOrField2=Level32_81420Field(privateRecord20,int*,44);
        if(resultOrField2<16)goto block_105;
        resultOrField2=15;
        Level32_81420Field(privateRecord20,int*,44)=resultOrField2;
        block_105:originalFrame.spC0=0;
        block_106:argumentOrField4=privateRecord20+44;
        block_107:resultOrField2=Level32_81420Call359A4View1(argumentOrField4,4);
        if(!resultOrField2)goto block_109;
        scratchOrCapturedHalf9=originalFrame.spA8;
        if(!scratchOrCapturedHalf9)goto block_120;
        block_109:resultOrField2=Level32_81420Field(privateRecord20,int*,40);
        fieldOrIntermediate3=Level32_81420Data6C648View1;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(privateRecord20,int*,40)=resultOrField2;
        scratchOrCapturedHalf8=originalFrame.spA8;
        if(!scratchOrCapturedHalf8)goto block_114;
        resultOrField2=Level32_81420Field(privateRecord20,int*,28);
        if(!resultOrField2)goto block_114;
        scratchOrCapturedHalf9=originalFrame.spC0;
        if(!scratchOrCapturedHalf9)goto block_114;
        resultOrField2=Level32_81420Field(privateRecord20,int*,44);
        if(resultOrField2>=15)goto block_114;
        resultOrField2=15;
        Level32_81420Field(privateRecord20,int*,44)=resultOrField2;
        block_114:resultOrField2=Level32_81420Field(privateRecord20,int*,40);
        if(resultOrField2<181)goto block_121;
        scratchOrCapturedHalf8=originalFrame.spB0;
        resultOrField2=60;
        if(!scratchOrCapturedHalf8)goto block_117;
        Level32_81420Field(privateRecord20,int*,44)=resultOrField2;
        block_117:resultOrField2=Level32_81420Field(privateRecord20,int*,28);
        scratchOrCapturedHalf9=1;
        if(!resultOrField2)goto block_119;
        Level32_81420Field(privateRecord20,int*,48)=resultOrField2;
        block_119:originalFrame.spB8=scratchOrCapturedHalf9;
        goto block_121;
        block_120:Level32_81420Keep(scratchOrCapturedHalf9);
        Level32_81420Field(privateRecord20,int*,40)=0;
        block_121:resultOrField2=Level32_81420Field(privateRecord20,int*,28);
        scratchOrCapturedHalf8=0x51EB0000;
        if(!resultOrField2)goto block_127;
        scratchOrCapturedHalf8=originalFrame.spA8;
        fieldOrIntermediate3=Level32_81420Field(resultOrField2,int*,0);
        resultOrField2=1;
        if(!scratchOrCapturedHalf8)goto block_124;
        Level32_81420Field(fieldOrIntermediate3,int*,68)=resultOrField2;
        block_124:scratchOrCapturedHalf9=originalFrame.spB8;
        Level32_81420Keep(resultOrField2);
        resultOrField2=1;
        if(!scratchOrCapturedHalf9)goto block_126;
        Level32_81420Field(fieldOrIntermediate3,int*,76)=resultOrField2;
        block_126:scratchOrCapturedHalf8=0x51EB0000;
    block_127:
        scratchOrCapturedHalf9=originalFrame.spD0;
        scratchOrCapturedHalf8|=0x851F;
        resultOrField2=scratchOrCapturedHalf9*3;
        Level32_81420Keep(resultOrField2);
        fieldOrIntermediate3=resultOrField2*16-resultOrField2;
        Level32_81420Keep(fieldOrIntermediate3);
        Level32_81420MultiplyComplete(fieldOrIntermediate3,scratchOrCapturedHalf8);
        Level32_81420CaptureHigh(argumentOrField4);
        resultOrField2=fieldOrIntermediate3*2;
        Level32_81420MultiplyComplete(resultOrField2,scratchOrCapturedHalf8);
        selectedOwnerVectorOrSine18=0;
        positionOrInitializedOne22=1;
        tagCursorRecordCursorOrParticleCount21=privateRecord20;
        differenceVectorOrTimerBound23=60;
        originalFrame.spF0=scratchOrCapturedHalf8;
        __asm__("":"=r"(fieldOrIntermediate3):"0"(fieldOrIntermediate3),"m"(originalFrame.spF0));
        fieldOrIntermediate3>>=31;
        originalFrame.sp100=fieldOrIntermediate3;
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"m"(originalFrame.sp100));
        resultOrField2>>=31;
        argumentOrField4>>=5;
        originalFrame.sp110=resultOrField2;
        originalFrame.spF8=argumentOrField4;
        Level32_81420CaptureHigh(capturedHigh10);
        capturedHigh10>>=5;
        originalFrame.sp108=capturedHigh10;
        loop_128:argumentOrField4=Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,0);
        if(argumentOrField4)goto block_134;
        resultOrField2=Level32_81420DataSpawnMobyView1(143,ownerOrCompletedWaveDescriptor19);
        fieldOrIntermediate3=resultOrField2;
        scratchOrCapturedHalf8=3;
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,0)=fieldOrIntermediate3;
        if(selectedOwnerVectorOrSine18!=scratchOrCapturedHalf8)goto block_133;
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,12);
        resultOrField2=Level32_81420Field(fieldOrIntermediate3,unsigned char*,60);
        if(resultOrField2==positionOrInitializedOne22)goto block_132;
        Level32_81420Field(fieldOrIntermediate3,unsigned char*,66)=0;
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,12);
        resultOrField2=Level32_81420Field(fieldOrIntermediate3,short*,54);
        resultOrField2*=4;
        resultOrField2=Level32_81420Field((int)&Level32_81420Data6EE2CView1,int*,resultOrField2);
        resultOrField2=Level32_81420Field(resultOrField2,int*,64);
        resultOrField2=Level32_81420Field(resultOrField2,unsigned char*,0);
        resultOrField2=-((unsigned int)resultOrField2>=2U)&48;
        Level32_81420Field(fieldOrIntermediate3,unsigned char*,64)=resultOrField2;
        resultOrField2=Level32_81420Field(privateRecord20,int*,12);
        Level32_81420Field(resultOrField2,unsigned char*,60)=positionOrInitializedOne22;
        resultOrField2=Level32_81420Field(privateRecord20,int*,12);
        Level32_81420Field(resultOrField2,unsigned char*,61)=positionOrInitializedOne22;
        resultOrField2=Level32_81420Field(privateRecord20,int*,12);
        Level32_81420Field(resultOrField2,unsigned char*,62)=0;
        resultOrField2=Level32_81420Field(privateRecord20,int*,12);
        Level32_81420Field(resultOrField2,unsigned char*,63)=positionOrInitializedOne22;
        fieldOrIntermediate3=Level32_81420Field(privateRecord20,int*,12);
        block_132:resultOrField2=24;
        Level32_81420Field(fieldOrIntermediate3,unsigned char*,79)=resultOrField2;
        goto block_164;
        block_133:resultOrField2=selectedOwnerVectorOrSine18*15+32;
        Level32_81420Field(fieldOrIntermediate3,unsigned char*,79)=resultOrField2;
        goto block_164;
        block_134:counterSelectedOwnerOrCosine17=argumentOrField4;
        if(selectedOwnerVectorOrSine18==positionOrInitializedOne22)goto block_142;
        resultOrField2=selectedOwnerVectorOrSine18<2;
        if(!resultOrField2)goto block_138;
        resultOrField2=0x66660000;
        if(!selectedOwnerVectorOrSine18)goto block_141;
        argumentOrField4=counterSelectedOwnerOrCosine17+12;
        goto block_147;
        block_138:resultOrField2=2;
        scratchOrCapturedHalf9=3;
        if(selectedOwnerVectorOrSine18==resultOrField2)goto block_143;
        argumentOrField4=counterSelectedOwnerOrCosine17+12;
        if(selectedOwnerVectorOrSine18==scratchOrCapturedHalf9)goto block_145;
        goto block_147;
        block_141:scratchOrCapturedHalf8=originalFrame.spD0;
        resultOrField2|=0x6667;
        Level32_81420MultiplyComplete(scratchOrCapturedHalf8,resultOrField2);
        resultOrField2=scratchOrCapturedHalf8>>31;
        Level32_81420CaptureHigh(scratchOrCapturedHalf9);
        fieldOrIntermediate3=scratchOrCapturedHalf9>>1;
        goto block_144;
        block_142:scratchOrCapturedHalf8=originalFrame.spF8;
        scratchOrCapturedHalf9=originalFrame.sp100;
        scratchOrCapturedHalf8-=scratchOrCapturedHalf9;
        originalFrame.spE8=scratchOrCapturedHalf8;
        goto block_146;
        block_143:scratchOrCapturedHalf8=originalFrame.spD0;
        scratchOrCapturedHalf9=originalFrame.spF0;
        resultOrField2=scratchOrCapturedHalf8*70;
        Level32_81420MultiplyComplete(resultOrField2,scratchOrCapturedHalf9);
        resultOrField2>>=31;
        Level32_81420CaptureHigh(scratchOrCapturedHalf8);
        fieldOrIntermediate3=scratchOrCapturedHalf8>>5;
        block_144:fieldOrIntermediate3-=resultOrField2;
        originalFrame.spE8=fieldOrIntermediate3;
        goto block_146;
        block_145:scratchOrCapturedHalf9=originalFrame.sp108;
        scratchOrCapturedHalf8=originalFrame.sp110;
        scratchOrCapturedHalf9-=scratchOrCapturedHalf8;
        originalFrame.spE8=scratchOrCapturedHalf9;
        block_146:argumentOrField4=counterSelectedOwnerOrCosine17+12;
        block_147:scratchOrCapturedHalf9=originalFrame.spC8;
        argumentOrField5=(int)&originalFrame.sp60;
        resultOrField2=scratchOrCapturedHalf9>>4;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,70)=resultOrField2;
        resultOrField2=retainedOriginalPitch>>4;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,69)=resultOrField2;
        Level32_81420Call4F178View1(argumentOrField4,argumentOrField5);
        resultOrField2=Level32_81420Call4EA2CView1(originalFrame.spC8);
        argumentOrField4=retainedOriginalPitch;
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call4EA2CView1(argumentOrField4);
        scratchOrCapturedHalf8=originalFrame.spE8;
        Level32_81420MultiplyComplete(vectorOrScalar16,scratchOrCapturedHalf8);
        Level32_81420CaptureLow(scratchOrCapturedHalf9);
        fieldOrIntermediate3=scratchOrCapturedHalf9>>12;
        Level32_81420MultiplyComplete(fieldOrIntermediate3,resultOrField2);
        argumentOrField4=originalFrame.spC8;
        resultOrField2=Level32_81420Field(counterSelectedOwnerOrCosine17,int*,12);
        Level32_81420CaptureLow(scratchOrCapturedHalf8);
        fieldOrIntermediate3=scratchOrCapturedHalf8>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(counterSelectedOwnerOrCosine17,int*,12)=resultOrField2;
        resultOrField2=Level32_81420Call4E9E4View1(argumentOrField4);
        argumentOrField4=retainedOriginalPitch;
        vectorOrScalar16=resultOrField2;
        resultOrField2=Level32_81420Call4EA2CView1(argumentOrField4);
        scratchOrCapturedHalf9=originalFrame.spE8;
        Level32_81420MultiplyComplete(vectorOrScalar16,scratchOrCapturedHalf9);
        Level32_81420CaptureLow(scratchOrCapturedHalf8);
        fieldOrIntermediate3=scratchOrCapturedHalf8>>12;
        Level32_81420MultiplyComplete(fieldOrIntermediate3,resultOrField2);
        argumentOrField4=retainedOriginalPitch;
        resultOrField2=Level32_81420Field(counterSelectedOwnerOrCosine17,int*,16);
        Level32_81420CaptureLow(scratchOrCapturedHalf9);
        fieldOrIntermediate3=scratchOrCapturedHalf9>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(counterSelectedOwnerOrCosine17,int*,16)=resultOrField2;
        resultOrField2=Level32_81420Call4E9E4View1(argumentOrField4);
        scratchOrCapturedHalf8=originalFrame.spE8;
        Level32_81420MultiplyComplete(resultOrField2,scratchOrCapturedHalf8);
        resultOrField2=Level32_81420Field(counterSelectedOwnerOrCosine17,int*,20);
        Level32_81420CaptureLow(scratchOrCapturedHalf9);
        fieldOrIntermediate3=scratchOrCapturedHalf9>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(counterSelectedOwnerOrCosine17,int*,20)=resultOrField2;
        resultOrField2=selectedOwnerVectorOrSine18<3;
        if(!resultOrField2)goto block_149;
        resultOrField2=Level32_81420Field(privateRecord20,int*,28);
        if(!resultOrField2)goto block_151;
        block_149:scratchOrCapturedHalf8=3;
        resultOrField2=32;
        if(selectedOwnerVectorOrSine18!=scratchOrCapturedHalf8)goto block_152;
        scratchOrCapturedHalf9=originalFrame.spB8;
        if(scratchOrCapturedHalf9)goto block_152;
        block_151:Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,65)=0;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,76)=0;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,77)=0;
        goto block_153;
        block_152:Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,65)=positionOrInitializedOne22;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,76)=resultOrField2;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,77)=positionOrInitializedOne22;
        block_153:scratchOrCapturedHalf8=originalFrame.spB8;
        if(scratchOrCapturedHalf8)goto block_155;
        resultOrField2=Level32_81420Field(privateRecord20,int*,40);
        resultOrField2=differenceVectorOrTimerBound23<resultOrField2;
        if(!resultOrField2)goto block_161;
        block_155:resultOrField2=Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,104);
        if(resultOrField2)goto block_160;
        resultOrField2=2;
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,104)=positionOrInitializedOne22;
        if(selectedOwnerVectorOrSine18!=resultOrField2)goto block_158;
        argumentOrField4=ownerOrCompletedWaveDescriptor19;
        argumentOrField5=3;
        goto block_159;
        block_158:argumentOrField4=ownerOrCompletedWaveDescriptor19;
        argumentOrField5=1;
        block_159:Level32_81420Call3BABCView1(argumentOrField4,argumentOrField5,0);
        block_160:resultOrField2=63;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,87)=resultOrField2;
        resultOrField2=255;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,84)=resultOrField2;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,85)=0;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,86)=0;
        goto block_164;
        block_161:scratchOrCapturedHalf9=originalFrame.spA8;
        resultOrField2=63;
        if(!scratchOrCapturedHalf9)goto block_163;
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,104)=0;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,87)=resultOrField2;
        resultOrField2=255;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,84)=0;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,85)=resultOrField2;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,86)=0;
        goto block_164;
        block_163:Level32_81420Keep(scratchOrCapturedHalf9);
        Level32_81420Keep(scratchOrCapturedHalf8);
        resultOrField2=48;
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,104)=0;
        Level32_81420Field(counterSelectedOwnerOrCosine17,unsigned char*,87)=resultOrField2;
        block_164:tagCursorRecordCursorOrParticleCount21+=4;
        selectedOwnerVectorOrSine18++;
        differenceVectorOrTimerBound23+=60;
        if(selectedOwnerVectorOrSine18<4)goto loop_128;
    block_165:
        tagCursorRecordCursorOrParticleCount21 = 1;
    chooseOriginalParticleFrequency:
        counterSelectedOwnerOrCosine17 = 2;
        if (Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0xB0) < 0x1771) {
            goto block_167;
        }
        tagCursorRecordCursorOrParticleCount21 = 2;
        counterSelectedOwnerOrCosine17 = 1;
    block_167:
        if (Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0xB0) >= 0xFA0) {
            goto block_169;
        }
        counterSelectedOwnerOrCosine17 = 2;
    block_169:
        if (Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0xB0) >= 0x7D0) {
            goto block_171;
        }
        counterSelectedOwnerOrCosine17 = 4;
    block_171:
        if (Level32_81420Field((int)&Level32_81420Data70328View1, int *, 0xB0) >= 0x4B0) {
            goto block_173;
        }
        counterSelectedOwnerOrCosine17 = 7;
    block_173:
        if (counterSelectedOwnerOrCosine17 == 1) {
            goto block_175;
        }
        var_a0_5 = privateRecord20 + 0x10;
        if (((int) Level32_81420Data6C640View1 % counterSelectedOwnerOrCosine17) != 0) {
            goto block_181;
        }
    block_175:
        __asm__ volatile(""::"r"(counterSelectedOwnerOrCosine17),"r"(tagCursorRecordCursorOrParticleCount21));
        vectorOrScalar16 = 0;
        if (tagCursorRecordCursorOrParticleCount21 == 0) {
            goto block_180;
        }
        selectedOwnerVectorOrSine18=(int)&originalFrame.sp88;
        Level32_81420Keep(selectedOwnerVectorOrSine18);
    loop_177:
        Level32_81420Call55F14View1(ownerOrCompletedWaveDescriptor19,0,selectedOwnerVectorOrSine18);
        originalFrame.sp88 += Level32_81420Call363DCView1(0, 0x96);
        originalFrame.sp8C += Level32_81420Call363DCView1(0, 0x96);
        originalFrame.sp90 += Level32_81420Call363DCView1(0, 0x96);
        originalFrame.sp98 = Level32_81420Call363DCView1(0, 0xA);
        originalFrame.sp9C = Level32_81420Call363DCView1(0, 0xA);
        temp_v0_8 = Level32_81420Call3636CView1(5, 8);
        originalFrame.spA0 = temp_v0_8;
        if (counterSelectedOwnerOrCosine17 != 1) {
            goto block_179;
        }
        originalFrame.spA0 = temp_v0_8 * 2;
    block_179:
        argumentOrField4=1;
        argumentOrField5=39;
        argumentOrField6=selectedOwnerVectorOrSine18;
        argumentOrField7=(int)&originalFrame.sp98;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5),"=r"(argumentOrField6),"=r"(argumentOrField7):"0"(argumentOrField4),"1"(argumentOrField5),"2"(argumentOrField6),"3"(argumentOrField7));
        vectorOrScalar16++;
        Level32_81420DataSpawnParticleView1(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
        if (vectorOrScalar16 < tagCursorRecordCursorOrParticleCount21) {
            goto loop_177;
        }
    block_180:
        var_a0_5 = privateRecord20 + 0x10;
    block_181:
        if (Level32_81420Call359A4View1(var_a0_5, 4) == 0) {
            goto block_189;
        }
        if (!(Level32_81420Data6E53CView1 & 0x20)) {
            goto block_189;
        }
        temp_v0_9 = Level32_81420DataSpawnMobyView1(0x8D, ownerOrCompletedWaveDescriptor19);
        if (temp_v0_9 == 0) {
            goto block_189;
        }
        tagCursorRecordCursorOrParticleCount21 = Level32_81420Field(temp_v0_9, int*, 0);
        Level32_81420Call3BABCView1(ownerOrCompletedWaveDescriptor19, 2, 0);
        resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,70);
        fieldOrIntermediate3=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        resultOrField2*=2;
        fieldOrIntermediate3*=2;
        argumentOrField4=Level32_81420Field((int)&Level32_81420Data65920View1,short*,resultOrField2);
        fieldOrIntermediate3=Level32_81420Field((int)&Level32_81420Data65920View1,short*,fieldOrIntermediate3);
        resultOrField2=argumentOrField4*375;
        resultOrField2>>=10;
        Level32_81420MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        resultOrField2=Level32_81420Field(temp_v0_9,int*,12);
        Level32_81420CaptureLow(scratchOrCapturedHalf8);
        fieldOrIntermediate3=scratchOrCapturedHalf8>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(temp_v0_9,int*,12)=resultOrField2;
        resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,70);
        fieldOrIntermediate3=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        resultOrField2*=2;
        fieldOrIntermediate3*=2;
        argumentOrField4=Level32_81420Field((int)&Level32_81420Data658A0View2,short*,resultOrField2);
        fieldOrIntermediate3=Level32_81420Field((int)&Level32_81420Data65920View1,short*,fieldOrIntermediate3);
        resultOrField2=argumentOrField4*375;
        resultOrField2>>=10;
        Level32_81420MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        resultOrField2=Level32_81420Field(temp_v0_9,int*,16);
        Level32_81420CaptureLow(scratchOrCapturedHalf9);
        fieldOrIntermediate3=scratchOrCapturedHalf9>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(temp_v0_9,int*,16)=resultOrField2;
        Level32_81420Field(temp_v0_9, int *, 0x14) = (int) (Level32_81420Field(temp_v0_9, int *, 0x14) + ((int) (Level32_81420Field((int)&Level32_81420Data658A0View2,short*,(Level32_81420Field(ownerOrCompletedWaveDescriptor19, unsigned char *, 0x45) * 2)) * 0x177) >> 0xA) + 0x1F4);
        __asm__ volatile(""::"m"(Level32_81420Field(temp_v0_9,int*,20)):"$17");
        resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,70);
        counterSelectedOwnerOrCosine17=(int)&Level32_81420Data65920View1;
        Level32_81420Field(temp_v0_9,unsigned char*,70)=resultOrField2;
        fieldOrIntermediate3=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        resultOrField2=48;
        Level32_81420Field(temp_v0_9,unsigned char*,76)=resultOrField2;
        Level32_81420Field(temp_v0_9,unsigned char*,78)=resultOrField2;
        resultOrField2=300;
        Level32_81420Field(temp_v0_9,unsigned char*,69)=fieldOrIntermediate3;
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,4)=resultOrField2;
        resultOrField2=400;
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,0)=resultOrField2;
        __asm__ volatile(""::"m"(Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,0)):"$18");
        scratchOrCapturedHalf8=originalFrame.spB8;
        __asm__ volatile(""::"r"(scratchOrCapturedHalf8):"$18");
        selectedOwnerVectorOrSine18=(int)&Level32_81420Data658A0View1;
        argumentOrField4=ownerOrCompletedWaveDescriptor19+12;
        if(!scratchOrCapturedHalf8)goto block_186;
        resultOrField2=Level32_81420Field(privateRecord20,int*,48);
        Level32_81420Field(tagCursorRecordCursorOrParticleCount21,int*,8)=resultOrField2;
        block_186:resultOrField2=Level32_81420Call18368View1(argumentOrField4,temp_v0_9+12);
        if(!resultOrField2)goto block_188;
        resultOrField2=1;
        Level32_81420Field(temp_v0_9,unsigned char*,72)=resultOrField2;
        resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,70);
        resultOrField2*=2;
        resultOrField2+=counterSelectedOwnerOrCosine17;
        fieldOrIntermediate3=Level32_81420Field(resultOrField2,short*,0);
        resultOrField2=-(fieldOrIntermediate3*750);
        fieldOrIntermediate3=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        fieldOrIntermediate3*=2;
        fieldOrIntermediate3+=counterSelectedOwnerOrCosine17;
        fieldOrIntermediate3=Level32_81420Field(fieldOrIntermediate3,short*,0);
        resultOrField2>>=12;
        Level32_81420MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        resultOrField2=Level32_81420Field(temp_v0_9,int*,12);
        Level32_81420CaptureLow(scratchOrCapturedHalf9);
        fieldOrIntermediate3=scratchOrCapturedHalf9>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(temp_v0_9,int*,12)=resultOrField2;
        resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,70);
        resultOrField2*=2;
        resultOrField2+=selectedOwnerVectorOrSine18;
        fieldOrIntermediate3=Level32_81420Field(resultOrField2,short*,0);
        resultOrField2=-(fieldOrIntermediate3*750);
        fieldOrIntermediate3=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        fieldOrIntermediate3*=2;
        fieldOrIntermediate3+=counterSelectedOwnerOrCosine17;
        fieldOrIntermediate3=Level32_81420Field(fieldOrIntermediate3,short*,0);
        resultOrField2>>=12;
        Level32_81420MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        resultOrField2=Level32_81420Field(temp_v0_9,int*,16);
        Level32_81420CaptureLow(scratchOrCapturedHalf8);
        fieldOrIntermediate3=scratchOrCapturedHalf8>>12;
        resultOrField2+=fieldOrIntermediate3;
        Level32_81420Field(temp_v0_9,int*,16)=resultOrField2;
        resultOrField2=Level32_81420Field(ownerOrCompletedWaveDescriptor19,unsigned char*,69);
        resultOrField2*=2;
        resultOrField2+=selectedOwnerVectorOrSine18;
        fieldOrIntermediate3=Level32_81420Field(resultOrField2,short*,0);
        resultOrField2=-(fieldOrIntermediate3*750);
        fieldOrIntermediate3=Level32_81420Field(temp_v0_9,int*,20);
        resultOrField2>>=12;
        fieldOrIntermediate3+=resultOrField2;
        Level32_81420Field(temp_v0_9,int*,20)=fieldOrIntermediate3;
    block_188:
        Level32_81420Field(privateRecord20, int *, 0x10) = 0x3C;
    block_189:
        return;
        default:return;
    }
}
#undef Level32_81420Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* func_level_32_80082BA8, SCUS-94467 USA Rev0. Original assembly SHA256 0289015e9ffe8774594cccd89f6dce44f80a5d28ee3d978c68465e05851c40de.
 * AI generated; not human reviewed. 923 original native instructions,
 * 12 original selector entries, no selector padding; original frame248 bytes.
 * Reuses the separately verified shared923/1053 controller evidence;
 * target-specific entry guards, state1 additions, constants and data are
 * retained from each original source. This changes no game/helper contract.
 * The pitch difference is produced by original8003613C (8 native words,
 * SHA492e2c022ca7e03e29c8fa084e2663c9d1eb6b03d0a3f63371cd6ee9b5a09939).
 * Its AND255 and >=129/subtract256 result is always[-127,128]. Thus the
 * initialized __builtin_abs input cannot be INT_MIN. Explicit GNU abs emits
 * the original BGEZ/MOVE/NEGU and fixes cc1's false-edge V0 liveness;
 * first BEQZ now executes SLTI(S1,7) in its delay and enters Apply directly.
 * Complete signed64 C products feed whole x inputs and h projections;
 * no partial HI/LO input, CPU opcode asm, fixedFP/SP, explicit incoming
 * saved value, invented default or overlapping live fixed alias is added.
 * Empty metadata observes complete initialized values or ends a dead GP
 * phase. Helper views specify only independently observed32-bit argument
 * words; unresolved meanings retain original word ABI and source labels.
 * Angles in this clamp use original256-unit byte-domain deltas and +/-6
 * step bounds. Other units, cadence beyond per invocation, full external
 * helper/asset/SFX meaning, Rev1 mapping and synchronized captures are open.
 * Original selector section is.rodata; frozen uninstalled wrapper fallback
 * is.rodata.jtbl. Parent metadata-aware linked build must preserve.rodata.
 * Acceptance requires every native/linked word, actual branch/J/call/table
 * target, original symbol/addend and complete EXE/every-overlay hashes.
 */
#define Actor923Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Actor923Keep(v) __asm__("":"=r"(v):"0"(v))
int Actor923_func_80035194() __asm__("func_80035194");
int Actor923_func_800359A4(int,int) __asm__("func_800359A4");
int Actor923_func_8003613C(int,int) __asm__("func_8003613C");
int Actor923_func_8003636C(int,int) __asm__("func_8003636C");
int Actor923_func_800363DC(int,int) __asm__("func_800363DC");
int Actor923_func_800369B8() __asm__("func_800369B8");
int Actor923_func_80038BF8() __asm__("func_80038BF8");
int Actor923_func_8003BA00() __asm__("func_8003BA00");
int Actor923_func_8003BABC() __asm__("func_8003BABC");
int Actor923_func_8004E880() __asm__("func_8004E880");
int Actor923_func_8004EDE8() __asm__("func_8004EDE8");
int Actor923_func_8004F110() __asm__("func_8004F110");
int Actor923_func_8004F178() __asm__("func_8004F178");
int Actor923_func_8004F194() __asm__("func_8004F194");
int Actor923_func_8004F1C8() __asm__("func_8004F1C8");
int Actor923_func_8004F264() __asm__("func_8004F264");
int Actor923_func_8004F334(void*,void*) __asm__("func_8004F334");
int Actor923_func_80055B18() __asm__("func_80055B18");
int Actor923_func_80055D24() __asm__("func_80055D24");
int Actor923_func_80055F14() __asm__("func_80055F14");
extern unsigned char Actor923_D_800658A0 __asm__("D_800658A0");
extern unsigned char Actor923_D_80065920 __asm__("D_80065920");
extern int Actor923_D_8006C640 __asm__("D_8006C640");
extern int Actor923_D_8006C648 __asm__("D_8006C648");
extern volatile unsigned char Actor923_D_8006C7B4 __asm__("D_8006C7B4");
extern int Actor923_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor923_D_80070328 __asm__("D_80070328");
extern int(*Actor923SpawnFragments)() __asm__("SpawnFragments");
extern int(*Actor923SpawnMoby)() __asm__("SpawnMoby");
extern int(*Actor923SpawnParticle)() __asm__("SpawnParticle");
extern int(*Actor923unk_ovlheader_800743E8)() __asm__("unk_ovlheader_800743E8");
extern int(*Actor923unk_ovlheader_80074410)() __asm__("unk_ovlheader_80074410");
#define Actor923MUL(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Actor923HI(dst) do{int completeProductHigh;__asm__("":"=h"(completeProductHigh):"x"(completeSignedProduct));(dst)=completeProductHigh;Actor923Keep(dst);}while(0)
void func_level_32_80082BA8(unsigned char* input) {
    register int retainedHeadingOrVector16 __asm__("$16");
    register int retainedAngleOrWord17 __asm__("$17");
    register int retainedWord18 __asm__("$18");
    register int retainedWord19 __asm__("$19");
    register int privateRecord20 __asm__("$20");
    register int ownerRecord21 __asm__("$21");
    register int rawWord2 __asm__("$2"),rawWord3 __asm__("$3"),argumentWord4 __asm__("$4"),argumentWord5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7"),rawWord8 __asm__("$8");
    long long completeSignedProduct;
    struct {
        int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4;
    }
    originalFrame;
    int temp_v1_10;
    int temp_v1_13;
    int temp_v1_4;
    int temp_v1_6;
    int temp_v1_7;
    int temp_v0_3;
    int temp_v0_7;
    int temp_v1_11;
    int var_v1;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v1;
    int temp_v1_2;
    int temp_a0;
    int temp_a1;
    int temp_a1_2;
    int temp_a1_3;
    int temp_v0_2;
    int temp_v0_8;
    int temp_v1_12;
    int temp_v1_14;
    int temp_v1_3;
    int temp_v1_5;
    int temp_v1_8;
    int temp_v1_9;
    rawWord2=Actor923_D_8006C7B4;
    ownerRecord21=(int)input;
    __asm__("":"=r"(ownerRecord21):"0"(ownerRecord21),"r"(rawWord2));
    privateRecord20=Actor923Field(ownerRecord21,int*,0);
    __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(privateRecord20));
    rawWord2&=2;
    __asm__("":"=r"(ownerRecord21),"=r"(privateRecord20),"=r"(rawWord2):"0"(ownerRecord21),"1"(privateRecord20),"2"(rawWord2));
    if (rawWord2 && (Actor923Field(ownerRecord21, unsigned char *, 0x43) == 0)) {
        Actor923_func_80055B18(input);
        __asm__ volatile(""::"r"(ownerRecord21));
        return;
    }
    if (!(Actor923_D_8006C7B4 & 4) || (Actor923Field(ownerRecord21, unsigned char *, 0x43) != 1)) {
        if (Actor923Field(ownerRecord21, int *, 0x18) & 0x100000) {
            temp_v1 = Actor923Field(ownerRecord21, unsigned char *, 0x48);
            if ((temp_v1 != 3) && (temp_v1 != 1)) {
                Actor923Field(ownerRecord21, unsigned char *, 0x48) = 3U;
            }
        }
        Actor923_func_8004F1C8(&originalFrame.sp18, ownerRecord21 + 0xC, (int)&Actor923_D_80070328);
        rawWord2=Actor923_func_8004EDE8(&originalFrame.sp18,1);
        rawWord3=Actor923Field(privateRecord20,int*,24);
        rawWord2=rawWord2<rawWord3;
        Actor923Field(privateRecord20,int*,20)=0;
        if(rawWord2)Actor923Field(privateRecord20,int*,20)=1;
        rawWord2=Actor923_func_8004E880(originalFrame.sp18,originalFrame.sp1C,0);
        argumentWord4=(int)&originalFrame.sp18;
        argumentWord5=0;
        __asm__("":"=r"(argumentWord4),"=r"(argumentWord5):"0"(argumentWord4),"1"(argumentWord5));
        retainedHeadingOrVector16=rawWord2;
        rawWord2=Actor923_func_8004EDE8(argumentWord4,argumentWord5);
        argumentWord4=rawWord2;
        argumentWord5=originalFrame.sp20;
        rawWord2=Actor923_func_8004E880(argumentWord4,argumentWord5,0);
        argumentWord5=retainedHeadingOrVector16;
        argumentWord4=Actor923Field((int)&Actor923_D_80070328,unsigned char*,14);
        retainedAngleOrWord17=rawWord2;
        rawWord2=Actor923_func_8003613C(argumentWord4,argumentWord5);
        retainedHeadingOrVector16=rawWord2;
        argumentWord4=Actor923Field((int)&Actor923_D_80070328,unsigned char*,13);
        if(retainedHeadingOrVector16<0)retainedHeadingOrVector16=-retainedHeadingOrVector16;
        rawWord2=Actor923_func_8003613C(argumentWord4,retainedAngleOrWord17);
        if(rawWord2<0)rawWord2=-rawWord2;
        Actor923Keep(rawWord2);
        retainedHeadingOrVector16=retainedHeadingOrVector16<512;
        Actor923Keep(retainedHeadingOrVector16);
        if(retainedHeadingOrVector16){
            rawWord2=rawWord2<512;
            if(rawWord2)Actor923Field(privateRecord20,int*,20)=1;
        }
        Actor923_func_800359A4(privateRecord20 + 0x62, 2);
        temp_v1_2 = Actor923Field(ownerRecord21, unsigned char *, 0x48);
        switch (temp_v1_2) {
        case 0:
            Actor923_func_8004F1C8(&originalFrame.sp28, ownerRecord21 + 0xC, (int)&Actor923_D_80070328);
            Actor923_func_8004EDE8(&originalFrame.sp28, 1);
            if (Actor923Field(privateRecord20, int *, 0x14) != 0) {
                Actor923Field(ownerRecord21, unsigned char *, 0x48) = 0xAU;
            }
            goto runOriginalCommonTail;
            default:goto runOriginalCommonTail;
        case 10:
            temp_v1_3 = Actor923Field(privateRecord20, void **, 0);
            temp_v1_4 = Actor923Field(temp_v1_3, short *, 0);
            retainedHeadingOrVector16 = (int) (Actor923Field(temp_v1_3, short *, 2) + (Actor923Field(temp_v1_3, short *, 0xA) * 2) + temp_v1_4) % temp_v1_4;
            argumentWord5=(int)&Actor923_D_80070328;
            Actor923Keep(argumentWord5);
            retainedAngleOrWord17=ownerRecord21+12;
            Actor923_func_8004F1C8(&originalFrame.sp38,argumentWord5,retainedAngleOrWord17);
            Actor923_func_8004F1C8(&originalFrame.sp48, Actor923Field(Actor923Field(privateRecord20, void **, 0), int *, 0xC) + (retainedHeadingOrVector16 * 0x10), retainedAngleOrWord17);
            rawWord2=Actor923_func_8004E880(originalFrame.sp38,originalFrame.sp3C,0);
            argumentWord6=0;
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6):"memory");
            argumentWord4=originalFrame.sp48;
            argumentWord5=originalFrame.sp4C;
            retainedHeadingOrVector16=rawWord2;
            rawWord2=Actor923_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
            if(Actor923_func_8004F264(retainedHeadingOrVector16,rawWord2)<64) {
                temp_v1_5 = Actor923Field(privateRecord20, void **, 0);
                rawWord2=Actor923Field(temp_v1_5,short*,10);
                Actor923Keep(rawWord2);
                rawWord2=-rawWord2;
                Actor923Field(temp_v1_5,short*,10)=rawWord2;
                temp_a1 = Actor923Field(privateRecord20, void **, 0);
                temp_v1_6 = Actor923Field(temp_a1, short *, 0);
                Actor923Field(temp_a1, short *, 2) = (short) ((int) (Actor923Field(temp_a1, short *, 2) + (Actor923Field(temp_a1, short *, 0xA) * 2) + temp_v1_6) % temp_v1_6);
            }
            else {
                temp_a0 = Actor923Field(privateRecord20, void **, 0);
                temp_v1_7 = Actor923Field(temp_a0, short *, 0);
                Actor923Field(temp_a0, short *, 2) = (short) ((int) (Actor923Field(temp_a0, short *, 2) + Actor923Field(temp_a0, short *, 0xA) + temp_v1_7) % temp_v1_7);
            }
            if (Actor923Field(privateRecord20, int *, 0x5C) != 0) {
                rawWord2=Actor923_func_8003636C(120,300);
                rawWord3=rawWord2;
                argumentWord4=Actor923_D_8006C7C4;
                rawWord2=2;
                Actor923Field(privateRecord20,short*,96)=rawWord3;
                if(argumentWord4==rawWord2){
                    argumentWord4=0x51EB851F;
                    Actor923Keep(argumentWord4);
                    rawWord3=(short)rawWord3;
                    Actor923Keep(rawWord3);
                    rawWord2=rawWord3*5;
                    Actor923Keep(rawWord2);
                    rawWord3=rawWord2*16;
                    rawWord2+=rawWord3;
                    goto projectFirstOriginalTimerProduct;
                }
                else{
                    rawWord2=11;
                    if(argumentWord4)goto finishFirstOriginalTimer;
                    argumentWord4=0x51EB851F;
                    Actor923Keep(argumentWord4);
                    rawWord2=(short)rawWord3;
                    Actor923Keep(rawWord2);
                    rawWord3=rawWord2*5;
                    Actor923Keep(rawWord3);
                    rawWord2=rawWord3*15;
                    rawWord2*=2;
                }
            projectFirstOriginalTimerProduct:
                Actor923MUL(rawWord2,argumentWord4);
                rawWord2>>=31;
                Actor923HI(rawWord8);
                rawWord3=rawWord8>>5;
                rawWord3-=rawWord2;
                Actor923Field(privateRecord20,short*,96)=rawWord3;
                finishFirstOriginalTimer:;
            }
            Actor923Field(ownerRecord21, unsigned char *, 0x48) = 0xBU;
            goto runOriginalCommonTail;
        case 11:
            retainedHeadingOrVector16=(int)&originalFrame.sp58;
            Actor923Keep(retainedHeadingOrVector16);
            temp_v0_2 = Actor923Field(privateRecord20, void **, 0);
            Actor923_func_8004F1C8(retainedHeadingOrVector16, Actor923Field(temp_v0_2, int *, 0xC) + (Actor923Field(temp_v0_2, short *, 2) * 0x10), ownerRecord21 + 0xC);
            rawWord2=Actor923_func_8004E880(originalFrame.sp58,originalFrame.sp5C,0);
            argumentWord4=retainedHeadingOrVector16;
            argumentWord5=0;
            __asm__("":"=r"(argumentWord4),"=r"(argumentWord5):"0"(argumentWord4),"1"(argumentWord5));
            retainedHeadingOrVector16=rawWord2;
            rawWord2=Actor923_func_8004EDE8(argumentWord4,argumentWord5);
            argumentWord4=rawWord2;
            argumentWord5=originalFrame.sp60;
            rawWord2=Actor923_func_8004E880(argumentWord4,argumentWord5,0);
            argumentWord5=retainedHeadingOrVector16;
            argumentWord4=Actor923Field(ownerRecord21,unsigned char*,70);
            retainedHeadingOrVector16=rawWord2;
            rawWord2=Actor923_func_8003613C(argumentWord4,argumentWord5);
            retainedAngleOrWord17=rawWord2;
            argumentWord4=Actor923Field(ownerRecord21,unsigned char*,69);
            rawWord2=Actor923_func_8003613C(argumentWord4,retainedHeadingOrVector16);
            argumentWord4=rawWord2;
            rawWord2=retainedAngleOrWord17;
            if(retainedAngleOrWord17<0)rawWord2=-rawWord2;
            rawWord2=rawWord2<10;
            if(!rawWord2){
                rawWord2=retainedAngleOrWord17<7;
                goto applyOriginalYawClamp;
            }
            rawWord2=__builtin_abs(argumentWord4);
            rawWord2=rawWord2<10;
            if(!rawWord2){
                rawWord2=retainedAngleOrWord17<7;
                goto applyOriginalYawClamp;
            }
            rawWord2=Actor923Field(ownerRecord21,unsigned char*,70);
            Actor923Keep(rawWord2);
            rawWord2*=16;
            Actor923Field(privateRecord20,short*,54)=rawWord2;
            rawWord2=Actor923Field(ownerRecord21,unsigned char*,69);
            Actor923Field(privateRecord20,short*,56)=0;
            rawWord2*=16;
            Actor923Field(privateRecord20,short*,52)=rawWord2;
            rawWord2=2;
            Actor923Field(ownerRecord21,unsigned char*,72)=rawWord2;
            rawWord2=retainedAngleOrWord17<7;
        applyOriginalYawClamp:
            if(!rawWord2){
                retainedAngleOrWord17=6;
                Actor923Keep(retainedAngleOrWord17);
                rawWord2=retainedAngleOrWord17<-6;
            }
            else rawWord2=retainedAngleOrWord17<-6;
            if(rawWord2)retainedAngleOrWord17=-6;
            rawWord2=argumentWord4<7;
            if(!rawWord2){
                argumentWord4=6;
                Actor923Keep(argumentWord4);
                rawWord2=argumentWord4<-6;
            }
            else rawWord2=argumentWord4<-6;
            if(rawWord2)argumentWord4=-6;
            rawWord2=Actor923Field(ownerRecord21,unsigned char*,70);
            rawWord3=Actor923Field(ownerRecord21,unsigned char*,69);
            rawWord2+=retainedAngleOrWord17;
            rawWord3+=argumentWord4;
            Actor923Field(ownerRecord21,unsigned char*,70)=rawWord2;
            Actor923Field(ownerRecord21,unsigned char*,69)=rawWord3;
            goto runOriginalCommonTail;
        case 2:
            Actor923_func_8004F1C8(&originalFrame.sp68, (int)&Actor923_D_80070328, ownerRecord21 + 0xC);
            temp_v0_3 = Actor923_func_8004EDE8(&originalFrame.sp68, 1);
            Actor923Field(privateRecord20, short *, 0x3A) = 0x48;
            if ((Actor923Field(privateRecord20, int *, 0x14) != 0) && (temp_v0_3 < 0x6000)) {
                var_v1 = 0x14A;
                if (temp_v0_3 >= 0x1800) {
                    var_v1 = 0x12C;
                    if (temp_v0_3 >= 0x2800) {
                        if (temp_v0_3 < 0x3800) {
                            var_v1 = 0x118;
                        }
                        else {
                            var_v1 = 0xE6;
                            if (temp_v0_3 < 0x4800) {
                                var_v1 = 0xFA;
                            }
                        }
                    }
                }
                temp_v0_4 = Actor923Field(privateRecord20, unsigned short *, 0x38) + 0x1E;
                Actor923Field(privateRecord20, unsigned short *, 0x38) = temp_v0_4;
                if (var_v1 < (short) temp_v0_4) {
                    Actor923Field(privateRecord20, unsigned short *, 0x38) = (unsigned short) var_v1;
                }
            }
            else {
                temp_v0_5 = Actor923Field(privateRecord20, unsigned short *, 0x38) + 0x1E;
                Actor923Field(privateRecord20, unsigned short *, 0x38) = temp_v0_5;
                if ((short) temp_v0_5 >= 0xC9) {
                    Actor923Field(privateRecord20, unsigned short *, 0x38) = 0xC8U;
                }
            }
            rawWord3=Actor923_D_8006C7C4;
            rawWord2=2;
            argumentWord4=ownerRecord21;
            if(rawWord3==rawWord2){
                argumentWord4=0x51EB0000;
                rawWord3=Actor923Field(privateRecord20,short*,56);
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4):"memory");
                argumentWord4|=0x851F;
                Actor923Keep(argumentWord4);
                rawWord2=rawWord3*7;
                Actor923Keep(rawWord2);
                rawWord2=rawWord2*8-rawWord3;
                rawWord2*=2;
                Actor923MUL(rawWord2,argumentWord4);
                rawWord2>>=31;
                Actor923HI(rawWord8);
                rawWord3=rawWord8>>5;
                rawWord3-=rawWord2;
                Actor923Field(privateRecord20,short*,56)=rawWord3;
                __asm__ volatile("":::"$4","memory");
                argumentWord4=ownerRecord21;
            }
            Actor923unk_ovlheader_800743E8(argumentWord4,Actor923Field(privateRecord20,int*,0),privateRecord20+52);
            if (Actor923Field(privateRecord20, int *, 0x44) != 0) {
                Actor923Field(privateRecord20, int *, 0x48) = (int) (Actor923Field(privateRecord20, int *, 0x48) + Actor923_D_8006C648);
            }
            else {
                Actor923Field(privateRecord20, int *, 0x48) = 0;
            }
            if (Actor923Field(privateRecord20, int *, 0x4C) != 0) {
                Actor923Field(privateRecord20, int *, 0x50) = (int) (Actor923Field(privateRecord20, int *, 0x50) + Actor923_D_8006C648);
            }
            else {
                Actor923Field(privateRecord20, int *, 0x50) = 0;
            }
            if (Actor923Field(privateRecord20, int *, 0x44) != 0) {
                temp_v1_8 = Actor923Field(privateRecord20, void **, 0);
                if (Actor923Field(((Actor923Field(temp_v1_8, short *, 2) * 0x10) + Actor923Field(temp_v1_8, int *, 0xC)), int *, 0xC) == 0) {
                    if ((Actor923Field(privateRecord20, int *, 0x5C) != 0) && (Actor923_func_800359A4(privateRecord20 + 0x60, 2) != 0)) {
                        rawWord2=Actor923_func_8003636C(180,420);
                        rawWord3=rawWord2;
                        argumentWord4=Actor923_D_8006C7C4;
                        rawWord2=2;
                        Actor923Field(privateRecord20,short*,96)=rawWord3;
                        if(argumentWord4==rawWord2){
                            argumentWord4=0x51EB851F;
                            Actor923Keep(argumentWord4);
                            rawWord3=(short)rawWord3;
                            Actor923Keep(rawWord3);
                            rawWord2=rawWord3*5;
                            Actor923Keep(rawWord2);
                            rawWord3=rawWord2*16;
                            rawWord2+=rawWord3;
                            goto secondTimerDoneDivide;
                        }
                        else{
                            rawWord2=11;
                            if(argumentWord4)goto secondTimerDone;
                            argumentWord4=0x51EB851F;
                            Actor923Keep(argumentWord4);
                            rawWord2=(short)rawWord3;
                            Actor923Keep(rawWord2);
                            rawWord3=rawWord2*5;
                            Actor923Keep(rawWord3);
                            rawWord2=rawWord3*15;
                            rawWord2*=2;
                        }
                    secondTimerDoneDivide:
                        Actor923MUL(rawWord2,argumentWord4);
                        rawWord2>>=31;
                        Actor923HI(rawWord8);
                        rawWord3=rawWord8>>5;
                        rawWord3-=rawWord2;
                        Actor923Field(privateRecord20,short*,96)=rawWord3;
                        secondTimerDone:;
                        temp_v1_9 = Actor923Field(privateRecord20, void **, 0);
                        Actor923Field(privateRecord20, short *, 0x62) = 0x96;
                        rawWord2=Actor923Field(temp_v1_9,short*,10);
                        Actor923Keep(rawWord2);
                        rawWord2=-rawWord2;
                        Actor923Field(temp_v1_9,short*,10)=rawWord2;
                        temp_a1_2 = Actor923Field(privateRecord20, void **, 0);
                        temp_v1_10 = Actor923Field(temp_a1_2, short *, 0);
                        Actor923Field(temp_a1_2, short *, 2) = (short) ((int) (Actor923Field(temp_a1_2, short *, 2) + (Actor923Field(temp_a1_2, short *, 0xA) * 2) + temp_v1_10) % temp_v1_10);
                        Actor923Field(ownerRecord21, unsigned char *, 0x48) = 0xBU;
                    }
                    if ((Actor923Field(privateRecord20, int *, 0x54) != 0) && (Actor923_func_800359A4(privateRecord20 + 0x58, 4) != 0) && (Actor923_func_8004F334(ownerRecord21 + 0xC, (int)&Actor923_D_80070328) < 0x5000)) {
                        temp_v1_11 = Actor923Field(ownerRecord21, int *, 0x14) - Actor923Field(ownerRecord21, short *, 0x38);
                        temp_v0_7 = temp_v1_11 - Actor923Field((int)&Actor923_D_80070328, int *, 8);
                        if (temp_v0_7 >= 0) {
                            if (temp_v0_7 >= 0x1B58) {
                            }
                            else {
                                goto block_86;
                            }
                        }
                        else if ((Actor923Field((int)&Actor923_D_80070328, int *, 8) - temp_v1_11) < 0x1B58) {
                        block_86:
                            temp_v0_8 = Actor923SpawnMoby(0x189, ownerRecord21);
                            if (temp_v0_8 != 0) {
                                retainedWord18 = Actor923Field(temp_v0_8, void **, 0);
                                Actor923_func_8003BABC(ownerRecord21, 0, 0);
                                argumentWord4=temp_v0_8+12;
                                Actor923Keep(argumentWord4);
                                retainedHeadingOrVector16=ownerRecord21+12;
                                Actor923_func_8004F178(argumentWord4,retainedHeadingOrVector16);
                                Actor923Field(temp_v0_8, signed char *, 0x4C) = 0x3F;
                                Actor923Field(temp_v0_8, signed char *, 0x4E) = 0x3F;
                                Actor923Field(temp_v0_8, int *, 0x14) = (int) (Actor923Field(temp_v0_8, int *, 0x14) + 0x1F4);
                                rawWord2=Actor923_func_8004E880(Actor923Field((int)&Actor923_D_80070328,int*,0)-Actor923Field(ownerRecord21,int*,12),Actor923Field((int)&Actor923_D_80070328,int*,4)-Actor923Field(ownerRecord21,int*,16),0);
                                retainedAngleOrWord17=(int)&originalFrame.sp78;
                                argumentWord4=retainedAngleOrWord17;
                                Actor923Keep(argumentWord4);
                                argumentWord5=retainedHeadingOrVector16;
                                retainedHeadingOrVector16=rawWord2;
                                Actor923_func_8004F178(argumentWord4,argumentWord5);
                                retainedHeadingOrVector16 = (retainedHeadingOrVector16 & 0xFF) * 2;
                                originalFrame.sp80 = Actor923Field((int)&Actor923_D_80070328, int *, 8);
                                originalFrame.sp78 += (int) (Actor923Field((int)&Actor923_D_80065920 + retainedHeadingOrVector16,short*,0) * 0x7D) >> 7;
                                originalFrame.sp7C += (int) (Actor923Field((int)&Actor923_D_800658A0 + retainedHeadingOrVector16,short*,0) * 0x7D) >> 7;
                                Actor923_func_8004F178(&originalFrame.sp78, (int)&Actor923_D_80070328 + 0x98);
                                originalFrame.sp78 *= 0x1E;
                                originalFrame.sp7C *= 0x1E;
                                originalFrame.sp80 *= 0x1E;
                                Actor923_func_8004F110(&originalFrame.sp78, 6);
                                Actor923_func_8004F194(&originalFrame.sp78, &originalFrame.sp78, (int)&Actor923_D_80070328);
                                Actor923Field(retainedWord18, int *, 0) = 0x1E;
                                Actor923Field(retainedWord18, unsigned char *, 6) = Actor923_func_8004E880(originalFrame.sp78 - Actor923Field(ownerRecord21, int *, 0xC), originalFrame.sp7C - Actor923Field(ownerRecord21, int *, 0x10), 0);
                                Actor923Field(retainedWord18, short *, 4) = 0x28;
                                Actor923Field(retainedWord18, short *, 8) = Actor923_func_800363DC(4, 0xB);
                                Actor923Field(retainedWord18, short *, 0xA) = Actor923_func_800363DC(4, 0xB);
                                Actor923Field(retainedWord18, signed char *, 7) = 0x14;
                            }
                            rawWord2=Actor923_func_8003636C(120,240);
                            argumentWord5=rawWord2;
                            Actor923Keep(argumentWord5);
                            rawWord3=Actor923_D_8006C7C4;
                            rawWord2=2;
                            Actor923Field(privateRecord20,int*,88)=argumentWord5;
                            if(rawWord3==rawWord2){
                                argumentWord4=0x51EB851F;
                                Actor923Keep(argumentWord4);
                                rawWord3=argumentWord5*3;
                                Actor923Keep(rawWord3);
                                rawWord2=rawWord3*15;
                            }
                            else{
                                if(rawWord3){
                                    argumentWord4=0x51EB0000;
                                    Actor923Keep(argumentWord4);
                                    goto finishThirdOriginalTimer;
                                }
                                argumentWord4=0x51EB851F;
                                Actor923Keep(argumentWord4);
                                rawWord2=argumentWord5*5;
                                Actor923Keep(rawWord2);
                                rawWord3=rawWord2*16;
                                rawWord2+=rawWord3;
                            }
                            rawWord2*=2;
                            Actor923MUL(rawWord2,argumentWord4);
                            rawWord2>>=31;
                            Actor923HI(rawWord8);
                            rawWord3=rawWord8>>5;
                            rawWord3-=rawWord2;
                            Actor923Field(privateRecord20,int*,88)=rawWord3;
                            finishThirdOriginalTimer:;
                        }
                    }
                }
            }
            if ((Actor923Field(privateRecord20, short *, 0x62) == 0) && (Actor923Field(privateRecord20, int *, 0x14) != 0) && (Actor923_func_8004F264(Actor923_func_8004E880(originalFrame.sp68, originalFrame.sp6C, 0), Actor923Field(ownerRecord21, unsigned char *, 0x46)) < 0x30)) {
                temp_v1_12 = Actor923Field(privateRecord20, void **, 0);
                rawWord2=Actor923Field(temp_v1_12,short*,10);
                Actor923Keep(rawWord2);
                rawWord2=-rawWord2;
                Actor923Field(temp_v1_12,short*,10)=rawWord2;
                temp_a1_3 = Actor923Field(privateRecord20, void **, 0);
                temp_v1_13 = Actor923Field(temp_a1_3, short *, 0);
                Actor923Field(temp_a1_3, short *, 2) = (short) ((int) (Actor923Field(temp_a1_3, short *, 2) + (Actor923Field(temp_a1_3, short *, 0xA) * 2) + temp_v1_13) % temp_v1_13);
                Actor923Field(ownerRecord21, unsigned char *, 0x48) = 0xBU;
            }
            if (Actor923_D_8006C640 & 1) {
                Actor923_func_80055D24(ownerRecord21, 4);
                Actor923_func_80055F14(ownerRecord21, 0, &originalFrame.sp88);
                originalFrame.sp88 += Actor923_func_800363DC(0, 0x96);
                originalFrame.sp8C += Actor923_func_800363DC(0, 0x96);
                originalFrame.sp90 += Actor923_func_800363DC(0, 0x96);
                originalFrame.sp98 = Actor923_func_800363DC(0, 0xA);
                originalFrame.sp9C = Actor923_func_800363DC(0, 0xA);
                originalFrame.spA0 = Actor923_func_8003636C(5, 8);
                Actor923Field(Actor923SpawnParticle(1, 0x27, &originalFrame.sp88, &originalFrame.sp98), signed char *, 0xB) = 1;
            }
            if (Actor923Field(privateRecord20, int *, 0x14) == 0) {
                temp_v1_14 = Actor923Field(privateRecord20, void **, 0);
                if (Actor923Field(((Actor923Field(temp_v1_14, short *, 2) * 0x10) + Actor923Field(temp_v1_14, int *, 0xC)), int *, 0xC) & 2) {
                    Actor923Field(ownerRecord21, unsigned char *, 0x48) = 0U;
                }
            }
            goto runOriginalCommonTail;
        case 1:
            Actor923_func_80055D24(ownerRecord21, 4);
            Actor923_func_80055F14(ownerRecord21, 1, &originalFrame.spB8);
            Actor923_func_80055F14(ownerRecord21, 2, &originalFrame.spC8);
            Actor923_func_8004F194(&originalFrame.sp98, &originalFrame.spB8, &originalFrame.spC8);
            Actor923_func_8004F110(&originalFrame.sp98, 1);
            originalFrame.spA8 = Actor923_func_800363DC(0, 0xA);
            originalFrame.spAC = Actor923_func_800363DC(0, 0xA);
            originalFrame.spB0 = Actor923_func_8003636C(5, 8);
            Actor923SpawnParticle(1, 0x27, &originalFrame.sp98, &originalFrame.spA8);
            if (Actor923Field(privateRecord20, short *, 0x22) < -0x96) {
                Actor923Field(privateRecord20, short *, 0x22) = -0x96;
            }
            if (Actor923_func_80035194(ownerRecord21, privateRecord20 + 0x1C) == 0x100) {
                Actor923_func_80055D24(ownerRecord21, 4);
                Actor923_func_8003BA00(ownerRecord21);
                Actor923_func_800369B8(ownerRecord21, 0x20);
                goto returnFromOriginalController;
            }
            goto runOriginalCommonTail;
        returnFromOriginalController:
            Actor923_func_80055B18(ownerRecord21);
            return;
        case 3:
            Actor923_func_80038BF8(ownerRecord21, privateRecord20 + 0x1C, 8, 1);
            argumentWord4=9;
            argumentWord5=142;
            __asm__("":"=r"(argumentWord4),"=r"(argumentWord5):"0"(argumentWord4),"1"(argumentWord5));
            rawWord2=6;
            Actor923Keep(rawWord2);
            Actor923Field(privateRecord20,unsigned char*,43)=rawWord2;
            rawWord2=240;
            Actor923Keep(rawWord2);
            Actor923Field(privateRecord20,short*,32)=rawWord2;
            rawWord2=70;
            Actor923Keep(rawWord2);
            Actor923Field(privateRecord20,short*,34)=rawWord2;
            rawWord2=150;
            Actor923Keep(rawWord2);
            Actor923Field(privateRecord20,unsigned char*,50)=rawWord2;
            Actor923Field(privateRecord20, signed char *, 0x2A) = 5;
            Actor923Field(ownerRecord21, signed char *, 0x4F) = 0x1A;
            Actor923Field(ownerRecord21, int *, 0x18) = 0;
            Actor923Field(ownerRecord21, signed char *, 0x51) = 0;
            Actor923SpawnFragments(argumentWord4,argumentWord5,ownerRecord21, Actor923Field(privateRecord20, int *, 0x64), 0, 0x100);
            Actor923unk_ovlheader_80074410(ownerRecord21 + 0xC, 0x27, 0x30, 0x50, 0x78);
            return;
        }
    }
    else goto returnFromOriginalController;
runOriginalCommonTail:
    Actor923Field(privateRecord20,int*,68)=0;
    Actor923Field(privateRecord20,int*,76)=0;
    return;
}
#undef Actor923Field
#undef Actor923Keep


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
void func_level_32_80083A14(void *input) {
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


void func_level_32_80084024(Moby* moby) {
    func_80039714(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_32/moby/func_level_32_80084044.s SHA256 f10db0ce70b2d1578267be3d29581f0083a8abc824c4321424616e56bb1683d0. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level32_84044_Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern Moby* Level32_84044_D_8006C550 __asm__("D_8006C550");
extern int Level32_84044_D_8006C5BC __asm__("D_8006C5BC");
extern Spyro Level32_84044_D_80070328 __asm__("D_80070328");
int Level32_84044_func_80013E38(Vector3D*, Vector3D*, int) __asm__("func_80013E38");
void Level32_84044_func_80034F40(Moby* moby, int newId) __asm__("func_80034F40");
void Level32_84044_func_80035734(Moby* moby) __asm__("func_80035734");
int Level32_84044_func_8003573C(Moby* arg0, int arg1, int arg2, int arg3) __asm__("func_8003573C");
int Level32_84044_func_800359A4(void*, int) __asm__("func_800359A4");
int Level32_84044_func_80035DDC(Moby* arg0, int arg1, int arg2, int arg3, int arg4) __asm__("func_80035DDC");
int Level32_84044_func_8003636C(int low, int high) __asm__("func_8003636C");
void Level32_84044_func_80037014(Moby* moby) __asm__("func_80037014");
void Level32_84044_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
int Level32_84044_func_8003BABC(Moby*, int, int) __asm__("func_8003BABC");
extern int Level32_84044_func_8004E880(int, int, int) __asm__("func_8004E880");
extern void Level32_84044_func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
extern void Level32_84044_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level32_84044_func_8004F194(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level32_84044_func_8004F264(int, int) __asm__("func_8004F264");
extern int Level32_84044_func_8004F334(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level32_84044_func_80055B18(Moby*) __asm__("func_80055B18");
extern void Level32_84044_func_80055D24(Moby*, int) __asm__("func_80055D24");
unsigned char Level32_84044_func_80035A80(Moby *, int, unsigned int, unsigned int, int, int, int, int) __asm__("func_80035A80");
/* extern */
unsigned char Level32_84044_func_80036A68(Moby *, unsigned int, unsigned int, unsigned int) __asm__("func_80036A68");
/* extern */
unsigned char Level32_84044_func_80037168(Moby *, Vector3D *, unsigned int) __asm__("func_80037168");
/* extern */
extern unsigned char Level32_84044_D_80066EAE __asm__("D_80066EAE");
extern int Level32_84044_D_8006C54C __asm__("D_8006C54C");
extern int Level32_84044_D_8006C574 __asm__("D_8006C574");
extern int Level32_84044_D_8006C578 __asm__("D_8006C578");
extern enum MovementState Level32_84044_D_8006C5C8 __asm__("D_8006C5C8");
extern int Level32_84044_D_8006C640 __asm__("D_8006C640");
extern int Level32_84044_D_8006C770 __asm__("D_8006C770");
extern int Level32_84044_D_8006C774 __asm__("D_8006C774");
extern int Level32_84044_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level32_84044_D_8006E020 __asm__("D_8006E020");
extern int Level32_84044_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level32_84044_D_8006E040 __asm__("D_8006E040");
extern unsigned char Level32_84044_D_8006EE2C __asm__("D_8006EE2C");
extern unsigned char Level32_84044_D_level_32_8009D030 __asm__("D_level_32_8009D030");
void func_level_32_80084044(Moby *arg0) {
    /* SCUS-94467 USA Rev0; original assembly identity and SHA256 above.
    * Original 0x60-byte frame: vectors at SP20/SP30, saved16..21
    * at SP40..54 and RA58. The class index is signed LH36, then
    * SLL2 and an actual WORD pointer-table load, followed by descriptor
    * pointer and BYTE header loads. Byte loads never replace the pointers.
    * Every relative pointer expression adds BYTES before its final cast.
    * Original owner18, private19, loop17, created16, literal-one20 and
    * table21 roles are retained. The signed state switch preserves the
    * original branch tree. Descriptor loads precede animation state stores;
    * flag arithmetic is original SLTIU/XOR/negate/AND30. The signed modulo
    * uses quotient2 and raw result4, without premature byte narrowing.
    * Vector/yaw arguments retain their original producer order. Callback
    * consumers rebuild the private address after the callback, as the
    * original instructions do. Dead caller-register boundaries occur only
    * before replacement producers. Empty constraints consume initialized
    * original values and emit no CPU instructions. Compiler flags unchanged.
    * Evidence proves byte/word widths, signed shifts, original constants
    * and control flow. Physical units/fixed point, complete helper meanings,
    * caller/frame cadence and runtime semantics remain unresolved.
    * Falsification: every native/linked word, conditional/internal J target,
    * preserved data and complete EXE/every-overlay retail hash. No runtime
    * or subsystem completion claim. AI generated; not human reviewed. */
    register Moby *moby __asm__("18");
    register unsigned char *classPointerTable __asm__("21");
    register int one __asm__("20");
    struct {
        Vector3D sp20;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[4];
    }
    scratch;
    Moby *createdMoby;
    Vector3D *positionPointer;
    Vector3D *privateState;
    Vector3D *var_a0;
    register Vector3D *var_a0_2 __asm__("4");
    short temp_v1_5;
    int temp_a0;
    int temp_s0_2;
    int temp_v0;
    int temp_v0_3;
    int temp_v1;
    int temp_v1_3;
    int var_a1;
    register int loopIndex __asm__("17");
    int var_v0;
    register int var_v0_2 __asm__("2");
    unsigned short temp_v0_4;
    register int animationIndex __asm__("4");
    register unsigned int currentAnimationId __asm__("3");
    unsigned char temp_a1;
    unsigned char temp_v1_4;
    unsigned char temp_v1_6;
    void *temp_v1_2;
    moby = arg0;
    __asm__("" : "=r"(moby) : "0"(moby));
    temp_a0 = moby->damageFlags;
    privateState = moby->mobyTag;
    if (temp_a0 & 0x830000) {
        loopIndex = 0;
        if (Level32_84044_D_8006C5C8 == MOVEMENT_STATE_JUMP_HOVER) {
            moby->damageFlags = temp_a0 | 0x100000;
            if (Level32_84044_Field(privateState, int *, 0x4C) == 0) {
                temp_v1 = Level32_84044_Field(privateState, int *, 0x50);
                if (temp_v1 != -1) {
                    temp_v1_2 = Level32_84044_D_8006C550[temp_v1].mobyTag;
                    temp_v0 = Level32_84044_Field(temp_v1_2, int *, 0xA4) + 0x3C;
                    Level32_84044_Field(temp_v1_2, int *, 0xA4) = temp_v0;
                    if (temp_v0 >= 0x385) {
                        Level32_84044_Field(temp_v1_2, int *, 0xA4) = 0x384;
                        __asm__ volatile("" : : : "17");
                        loopIndex = 0;
                    }
                }
            }
        }
        one = 1;
        classPointerTable = &Level32_84044_D_8006EE2C;
    loop_8:
        {
            register int factoryKind4 __asm__("4");
            factoryKind4 = 0x147;
            if ((Level32_84044_D_8006C578 - Level32_84044_D_8006C574) >= 0x15) {
                createdMoby = SpawnMoby(factoryKind4, moby);
                if (createdMoby != 0) {
                    Level32_84044_Field(createdMoby->mobyTag, short *, 0x12) = one;
                    if (loopIndex < 4) {
                        {
                            register int quotient2 __asm__("2");
                            quotient2 = (unsigned int)loopIndex >> 31;
                            currentAnimationId = createdMoby->animationState.id;
                            __asm__("" : "=r"(quotient2) : "0"(quotient2), "r"(currentAnimationId));
                            quotient2 = loopIndex + quotient2;
                            quotient2 >>= 1;
                            quotient2 <<= 1;
                            animationIndex = loopIndex - quotient2;
                        }
                        __asm__("" : "=r"(animationIndex), "=r"(currentAnimationId) : "0"(animationIndex), "1"(currentAnimationId));
                        if (currentAnimationId != animationIndex) {
                            {
                                register int class2 __asm__("2");
                                register unsigned char *slot2 __asm__("2");
                                register unsigned char *bank2 __asm__("2");
                                register unsigned char *descriptor2 __asm__("2");
                                register unsigned int header2 __asm__("2");
                                class2 = createdMoby->mobyClass;
                                createdMoby->unknown3[1] = 0;
                                class2 <<= 2;
                                slot2 = (unsigned char *)(class2 + (int)classPointerTable);
                                {
                                    register unsigned char *bank3 __asm__("3");
                                    bank3 = Level32_84044_Field(slot2,unsigned char**,0);
                                    class2 = animationIndex << 2;
                                    slot2 = (unsigned char *)(class2 + (int)bank3);
                                    descriptor2 = Level32_84044_Field(slot2,unsigned char**,0x3C);
                                }
                                header2 = *descriptor2;
                                createdMoby->animationState.id = animationIndex;
                                createdMoby->animationState.nextId = animationIndex;
                                createdMoby->animationState.frame = 0;
                                createdMoby->animationState.nextFrame = one;
                                header2 = header2 < 2U;
                                __asm__("" : "=r"(header2) : "0"(header2));
                                header2 ^= 1;
                                header2 = -header2;
                                header2 &= 0x30;
                                createdMoby->animationProgress = header2;
                            }
                        }
                        goto block_27;
                    }
                    if (loopIndex < 8) {
                        if (createdMoby->animationState.id != 2) {
                            {
                                register int selected3 __asm__("3");
                                selected3 = 2;
                                {
                                    register int class2 __asm__("2");
                                    register unsigned char *slot2 __asm__("2");
                                    register unsigned char *bank2 __asm__("2");
                                    register unsigned char *descriptor2 __asm__("2");
                                    register unsigned int header2 __asm__("2");
                                    class2 = createdMoby->mobyClass;
                                    createdMoby->unknown3[1] = 0;
                                    class2 <<= 2;
                                    slot2 = (unsigned char *)(class2 + (int)classPointerTable);
                                    bank2 = Level32_84044_Field(slot2,unsigned char**,0);
                                    descriptor2 = Level32_84044_Field(bank2,unsigned char**,0x44);
                                    header2 = *descriptor2;
                                    createdMoby->animationState.id = selected3;
                                    createdMoby->animationState.nextId = selected3;
                                    createdMoby->animationState.frame = 0;
                                    createdMoby->animationState.nextFrame = one;
                                    header2 = header2 < 2U;
                                    __asm__("" : "=r"(header2) : "0"(header2));
                                    header2 ^= 1;
                                    header2 = -header2;
                                    header2 &= 0x30;
                                    createdMoby->animationProgress = header2;
                                }
                            }
                        }
                        Level32_84044_func_8004F178(&scratch.sp20, Level32_84044_Field(privateState, int *, 0x44) + ((loopIndex % 2) * 0xC));
                        Level32_84044_func_8004ED6C(&moby->rotationMatrix, &scratch.sp20, &scratch.sp20);
                        {
                            register Vector3D *position4 __asm__("4");
                            register Vector3D *ownerPosition5 __asm__("5");
                            register Vector3D *delta6 __asm__("6");
                            register unsigned int yaw2 __asm__("2");
                            position4 = &createdMoby->position;
                            ownerPosition5 = &moby->position;
                            __asm__("" : "=r"(position4), "=r"(ownerPosition5) : "0"(position4), "1"(ownerPosition5));
                            yaw2 = moby->angle.yaw;
                            delta6 = &scratch.sp20;
                            createdMoby->angle.pitch = 0;
                            createdMoby->angle.roll = 0;
                            createdMoby->angle.yaw = yaw2;
                            Level32_84044_func_8004F194(position4,ownerPosition5,delta6);
                        }
                        __asm__ volatile("" : : : "memory");
                        loopIndex += 1;
                    }
                    else if (loopIndex < 0xA) {
                        if (createdMoby->animationState.id != 3) {
                            {
                                register int selected3 __asm__("3");
                                selected3 = 3;
                                {
                                    register int class2 __asm__("2");
                                    register unsigned char *slot2 __asm__("2");
                                    register unsigned char *bank2 __asm__("2");
                                    register unsigned char *descriptor2 __asm__("2");
                                    register unsigned int header2 __asm__("2");
                                    class2 = createdMoby->mobyClass;
                                    createdMoby->unknown3[1] = 0;
                                    class2 <<= 2;
                                    slot2 = (unsigned char *)(class2 + (int)classPointerTable);
                                    bank2 = Level32_84044_Field(slot2,unsigned char**,0);
                                    descriptor2 = Level32_84044_Field(bank2,unsigned char**,0x48);
                                    header2 = *descriptor2;
                                    createdMoby->animationState.id = selected3;
                                    createdMoby->animationState.nextId = selected3;
                                    createdMoby->animationState.frame = 0;
                                    createdMoby->animationState.nextFrame = one;
                                    header2 = header2 < 2U;
                                    __asm__("" : "=r"(header2) : "0"(header2));
                                    header2 ^= 1;
                                    header2 = -header2;
                                    header2 &= 0x30;
                                    createdMoby->animationProgress = header2;
                                }
                            }
                        }
                        {
                            register Vector3D *scratch4 __asm__("4");
                            register int vectorOffset5 __asm__("5");
                            register int vectorBase2 __asm__("2");
                            scratch4 = &scratch.sp20;
                            __asm__("" : "=r"(scratch4) : "0"(scratch4));
                            vectorOffset5 = (loopIndex % 2) * 12;
                            __asm__("" : "=r"(vectorOffset5) : "0"(vectorOffset5));
                            vectorBase2 = Level32_84044_Field(privateState,int*,0x44);
                            __asm__("" : "=r"(vectorBase2), "=r"(vectorOffset5) : "0"(vectorBase2), "1"(vectorOffset5));
                            vectorOffset5 += 0x18;
                            Level32_84044_func_8004F178(scratch4,(Vector3D *)(vectorBase2 + vectorOffset5));
                        }
                        Level32_84044_func_8004ED6C(&moby->rotationMatrix, &scratch.sp20, &scratch.sp20);
                        {
                            register unsigned int yaw2 __asm__("2");
                            yaw2 = moby->angle.yaw;
                            __asm__("" : "=r"(yaw2) : "0"(yaw2));
                            createdMoby->angle.pitch = 0;
                            createdMoby->angle.roll = 0;
                            createdMoby->angle.yaw = yaw2;
                        }
                        __asm__ volatile("" : : : "memory");
                        if (!(loopIndex & 1)) {
                            createdMoby->angle.yaw += 0x80;
                        }
                        Level32_84044_func_8004F194(&createdMoby->position, &moby->position, &scratch.sp20);
                        __asm__ volatile("" : : : "memory");
                        loopIndex += 1;
                    }
                    else {
                        if (createdMoby->animationState.id != 4) {
                            {
                                register int selected3 __asm__("3");
                                selected3 = 4;
                                {
                                    register int class2 __asm__("2");
                                    register unsigned char *slot2 __asm__("2");
                                    register unsigned char *bank2 __asm__("2");
                                    register unsigned char *descriptor2 __asm__("2");
                                    register unsigned int header2 __asm__("2");
                                    class2 = createdMoby->mobyClass;
                                    createdMoby->unknown3[1] = 0;
                                    class2 <<= 2;
                                    slot2 = (unsigned char *)(class2 + (int)classPointerTable);
                                    bank2 = Level32_84044_Field(slot2,unsigned char**,0);
                                    descriptor2 = Level32_84044_Field(bank2,unsigned char**,0x4C);
                                    header2 = *descriptor2;
                                    createdMoby->animationState.id = selected3;
                                    createdMoby->animationState.nextId = selected3;
                                    createdMoby->animationState.frame = 0;
                                    createdMoby->animationState.nextFrame = one;
                                    header2 = header2 < 2U;
                                    __asm__("" : "=r"(header2) : "0"(header2));
                                    header2 ^= 1;
                                    header2 = -header2;
                                    header2 &= 0x30;
                                    createdMoby->animationProgress = header2;
                                }
                            }
                        }
                        {
                            register Vector3D *scratch4 __asm__("4");
                            register int vectorOffset5 __asm__("5");
                            register int vectorBase2 __asm__("2");
                            scratch4 = &scratch.sp20;
                            __asm__("" : "=r"(scratch4) : "0"(scratch4));
                            vectorOffset5 = (loopIndex % 2) * 12;
                            __asm__("" : "=r"(vectorOffset5) : "0"(vectorOffset5));
                            vectorBase2 = Level32_84044_Field(privateState,int*,0x44);
                            __asm__("" : "=r"(vectorBase2), "=r"(vectorOffset5) : "0"(vectorBase2), "1"(vectorOffset5));
                            vectorOffset5 += 0x30;
                            Level32_84044_func_8004F178(scratch4,(Vector3D *)(vectorBase2 + vectorOffset5));
                        }
                        Level32_84044_func_8004ED6C(&moby->rotationMatrix, &scratch.sp20, &scratch.sp20);
                        {
                            register Vector3D *position4 __asm__("4");
                            register Vector3D *ownerPosition5 __asm__("5");
                            register Vector3D *delta6 __asm__("6");
                            register unsigned int yaw2 __asm__("2");
                            position4 = &createdMoby->position;
                            ownerPosition5 = &moby->position;
                            __asm__("" : "=r"(position4), "=r"(ownerPosition5) : "0"(position4), "1"(ownerPosition5));
                            yaw2 = moby->angle.yaw;
                            delta6 = &scratch.sp20;
                            createdMoby->angle.pitch = 0;
                            createdMoby->angle.roll = 0;
                            createdMoby->angle.yaw = yaw2;
                            Level32_84044_func_8004F194(position4,ownerPosition5,delta6);
                        }
                        if (loopIndex == 0xB) {
                            createdMoby->size = 0x14;
                        }
                        goto block_27;
                    }
                }
                else {
                block_27:
                    __asm__ volatile("" : : : "memory");
                    loopIndex += 1;
                }
                if (loopIndex < 0xC) {
                    goto loop_8;
                }
            }
        }
        __asm__ volatile("" : : : "4");
        moby->updateDistance = 8;
        Level32_84044_func_80036A68(moby, 0, 0, 0);
        Level32_84044_func_8003BABC(moby, 0, 0);
        if (moby->unknown2 != 0x7E) {
            Level32_84044_func_8003BA00(moby);
        }
        Level32_84044_func_80055B18(moby);
        return;
    }
    moby->damageFlags = 0;
    if (moby->drawn != 0) {
        if (((unsigned char) moby->state < 2U) && (Level32_84044_func_800359A4(((unsigned char *)privateState + 0x2C), 2) != 0) && (Level32_84044_Field(privateState, int *, 0x48) == 0)) {
            var_v0 = Level32_84044_D_8006C640;
            if (Level32_84044_D_8006C640 < 0) {
                var_v0 = Level32_84044_D_8006C640 + 3;
            }
            if (((Level32_84044_D_8006C640 - ((var_v0 >> 2) * 4)) == Level32_84044_Field(privateState, short *, 0x42)) && (Level32_84044_func_8004F334(&moby->position, &Level32_84044_D_80070328.position) < Level32_84044_Field(privateState, int *, 0x34)) && ((Level32_84044_Field(privateState, int *, 0x38) == 0) || ((Level32_84044_D_80070328.ticksSinceLastSurfaceTouch == 0) && (((moby->position.z - moby->distanceToGround) - Level32_84044_D_80070328.position.z) < 0xC8))) && ((Level32_84044_Field(privateState, int *, 0x54) == 0) || ((Level32_84044_D_80070328.ticksSinceLastSurfaceTouch == 0) && (((moby->position.z - moby->distanceToGround) - Level32_84044_D_80070328.position.z) >= -0x12B)))) {
                temp_v1_3 = moby->position.z - moby->distanceToGround;
                temp_v0_3 = temp_v1_3 - Level32_84044_D_80070328.position.z;
                if (temp_v0_3 >= 0) {
                    if (temp_v0_3 >= 0x3E8) {
                    }
                    else {
                        goto block_50;
                    }
                }
                else if ((Level32_84044_D_80070328.position.z - temp_v1_3) < 0x3E8) {
                block_50:
                    if (Level32_84044_func_8004F264((int) (Level32_84044_D_8006E040 << 0x10) >> 0x14, Level32_84044_func_8004E880(moby->position.x - Level32_84044_D_8006E020, moby->position.y - Level32_84044_D_8006E024, 0)) < 0x1C) {
                        Level32_84044_func_8004F178(&scratch.sp30, &moby->position);
                        scratch.sp30.z += 0x12C;
                        if (Level32_84044_func_80013E38(&scratch.sp30, &Level32_84044_D_80070328.position, 0) != 0) {
                            moby->state = 0xA;
                        }
                    }
                }
            }
        }
        temp_v1_4 = moby->state;
        switch ((int)temp_v1_4) {
        case 0: {
                temp_v1_5 = Level32_84044_Field(privateState, short *, 0x28);
                if (temp_v1_5 == 0) {
                    Level32_84044_func_80037168(moby, privateState, 0x57);
                    Level32_84044_func_80037014(moby);
                    if (moby->substate != 0) {
                        moby->substate = 0;
                        Level32_84044_Field(privateState, unsigned short *, 0x18) = Level32_84044_func_8003636C(0x3C, 0x64);
                        moby->state = 1;
                        Level32_84044_func_80034F40(moby, 1);
                    }
                    if ((Level32_84044_func_800359A4(((unsigned char *)privateState + 0x18), 2) != 0) && (Level32_84044_D_8006C770 != 0)) {
                        temp_v0_4 = Level32_84044_Field(privateState, unsigned short *, 0x18) - 1;
                        Level32_84044_Field(privateState, unsigned short *, 0x18) = temp_v0_4;
                        if ((temp_v0_4 << 0x10) <= 0) {
                            Level32_84044_Field(privateState, unsigned short *, 0x18) = Level32_84044_func_8003636C(0x1E, 0x64);
                            Level32_84044_Field(privateState, short *, 0x1A) = Level32_84044_func_8003636C(0, 3);
                            moby->state = 1;
                            Level32_84044_func_80034F40(moby, 1);
                        }
                    }
                }
                else if (temp_v1_5 == 1) {
                    Level32_84044_func_80035A80(moby, Level32_84044_Field(privateState, int *, 0x30), 0x100, 0x50, 0, 3, 0xA, 5);
                }
                else if (temp_v1_5 == 2) {
                    Level32_84044_func_8003573C(moby, 2, 0, 0);
                }
                if ((Level32_84044_D_8006C54C - 1) == &Level32_84044_D_level_32_8009D030) {
                    if (({ register int enabled2 __asm__("2"); enabled2 = Level32_84044_D_8006C774; __asm__("" : "=r"(enabled2) : "0"(enabled2)); enabled2; }) != 0) {
                        var_v0_2 = 0x2C;
                    loop_72:
                        Level32_84044_Field(&Level32_84044_D_80066EAE, unsigned short*, var_v0_2) = 0;
                        var_v0_2 -= 4;
                        if (var_v0_2 >= 0) {
                            goto loop_72;
                        }
                    }
                }
                break;
            }
        case 1: {
                var_a0_2 = ((unsigned char *)privateState + 0x18);
                if (Level32_84044_Field(privateState, short *, 0x28) == 2) {
                    moby->state = 0;
                    Level32_84044_func_80034F40(moby, 0);
                    __asm__("" : "=r"(privateState) : "0"(privateState));
                    var_a0_2 = ((unsigned char *)privateState + 0x18);
                }
                if (Level32_84044_func_800359A4(var_a0_2, 2) != 0) {
                    if (Level32_84044_D_8006C770 != 0) {
                        Level32_84044_Field(privateState, unsigned short *, 0x18) = Level32_84044_func_8003636C(0x78, 0x1F4);
                        moby->state = 0;
                        Level32_84044_func_80034F40(moby, 0);
                        goto block_79;
                    }
                }
                else {
                block_79:
                    if (Level32_84044_D_8006C770 != 0) {
                        if (Level32_84044_Field(privateState, short *, 0x1A) == 0) {
                            Level32_84044_func_80034F40(moby, 4);
                            Level32_84044_Field(privateState, short *, 0x1A) = Level32_84044_func_8003636C(7, 7);
                        }
                        else {
                            Level32_84044_func_80034F40(moby, 1);
                            Level32_84044_Field(privateState, short *, 0x1A) = (short) ((unsigned short) Level32_84044_Field(privateState, short *, 0x1A) - 1);
                        }
                    }
                }
                break;
            }
        case 10: {
                positionPointer = &moby->position;
                temp_s0_2 = Level32_84044_func_8004F334(positionPointer, &Level32_84044_D_80070328.position);
                if (Level32_84044_func_8004F334(positionPointer, privateState) >= 0x2329) {
                    Level32_84044_Field(privateState, short *, 0x2C) = 0xB4;
                    Level32_84044_Field(privateState, unsigned short *, 0x18) = 0x78U;
                    moby->state = 0;
                    Level32_84044_func_80034F40(moby, 0);
                }
                if (Level32_84044_func_8003573C(moby, 6, 0x14, 1) != 0) {
                    var_a1 = 0xE6;
                    if (Level32_84044_D_8006C7C4 == 1) {
                        var_a1 = 0xBE;
                    }
                    else if (Level32_84044_D_8006C7C4 == 0) {
                        var_a1 = 0x8C;
                    }
                    if (Level32_84044_func_80035DDC(moby, var_a1, 0, 0x190, 0x255) != 0) {
                        Level32_84044_Field(privateState, short *, 0x2C) = 0xB4;
                        Level32_84044_Field(privateState, signed char *, 0x13) = Level32_84044_func_8004E880(privateState->x - moby->position.x, privateState->y - moby->position.y, 0);
                        Level32_84044_Field(privateState, unsigned short *, 0x18) = 0x78U;
                        moby->state = 0;
                        Level32_84044_func_80034F40(moby, 0);
                    }
                }
                if (moby->animationState.nextId != 5) {
                    Level32_84044_D_8006C770 = 0;
                    temp_v1_6 = moby->animationState.nextId;
                    temp_a1 = moby->animationState.nextFrame;
                    moby->animationProgress = 0x72;
                    moby->animationState.nextId = 5;
                    moby->animationState.nextFrame = 0;
                    moby->animationState.id = temp_v1_6;
                    moby->animationState.frame = temp_a1;
                    Level32_84044_func_80035734(moby);
                }
                if ((temp_s0_2 < 0x708) || (var_a0 = ((unsigned char *)privateState + 0x3C), (Level32_84044_D_80070328.movementState == MOVEMENT_STATE_HURT))) {
                    var_a0 = ((unsigned char *)privateState + 0x3C);
                    if (Level32_84044_Field(privateState, int *, 0x3C) == 0) {
                        Level32_84044_Field(privateState, int *, 0x3C) = 0xA;
                        Level32_84044_D_80070328.unk22[5] = (int) moby->angle.yaw;
                    }
                }
                if ((Level32_84044_func_800359A4(var_a0, 4) == 2) || (Level32_84044_func_8004F264((int) (Level32_84044_D_8006E040 << 0x10) >> 0x14, Level32_84044_func_8004E880(moby->position.x - Level32_84044_D_8006E020, moby->position.y - Level32_84044_D_8006E024, 0)) >= 0x29)) {
                    Level32_84044_Field(privateState, short *, 0x2C) = 0xB4;
                    Level32_84044_Field(privateState, unsigned short *, 0x18) = 0x78U;
                    moby->state = 0;
                    Level32_84044_func_80034F40(moby, 0);
                }
                if (Level32_84044_func_8004F264((int) (Level32_84044_D_8006E040 << 0x10) >> 0x14, Level32_84044_func_8004E880(moby->position.x - Level32_84044_D_8006E020, moby->position.y - Level32_84044_D_8006E024, 0)) >= 0x29) {
                    Level32_84044_Field(privateState, short *, 0x2C) = 0x3C;
                    Level32_84044_Field(privateState, unsigned short *, 0x18) = 0x78U;
                    moby->state = 0;
                    Level32_84044_func_80034F40(moby, 0);
                }
                break;
            }
        }
        {
            register int selector3 __asm__("3");
            register int literal2 __asm__("2");
            selector3 = Level32_84044_D_8006C5BC;
            literal2 = 50;
            __asm__("" : "=r"(selector3), "=r"(literal2) : "0"(selector3), "1"(literal2));
            if (selector3 == literal2) {
                literal2 = 2;
                selector3 = Level32_84044_D_8006C5C8;
                if (selector3 != literal2) goto finalHelper15283;
                selector3 = moby->animationState.nextId;
                if ((unsigned int)selector3 < 2U) goto finalHelper15283;
                literal2 = 4;
                if (selector3 == literal2) goto finalHelper15283;
                literal2 = 19;
                selector3 = Level32_84044_D_80070328.movementState;
            }
            else {
                literal2 = 2;
                selector3 = Level32_84044_D_8006C5C8;
            }
            if (selector3 != literal2) {
            finalHelper15283:
                Level32_84044_func_80055D24(moby,5);
            }
        }
    }
}
#undef Level32_84044_Field


typedef struct {
    unsigned char unk0, unk1;
    short offset;
    Moby* parent;
} DecodedFollowTag;
extern unsigned short D_8006E040, D_8006E03E;
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_32_80084C0C(Moby* moby) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * 80084D60,338 instructions, sibling4610. Raw units/helper meanings and
 * cadence unresolved; uninstalled until exact native instructions match. */
#define N32F(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int N32H4F178() __asm__("func_8004F178");
int N32H359A4() __asm__("func_800359A4");
int N32H1BA30() __asm__("func_8001BA30");
int N32H4E880() __asm__("func_8004E880");
int N32H360F8() __asm__("func_800360F8");
int N32H1830C() __asm__("func_8001830C");
int N32H19138() __asm__("func_80019138");
int N32H4F168() __asm__("func_8004F168");
int N32H1A358() __asm__("func_8001A358");
int N32H5629C() __asm__("func_8005629C");
int N32H55D24() __asm__("func_80055D24");
int N32H1C288() __asm__("func_8001C288");
int N32H3BABC() __asm__("func_8003BABC");
int N32H4EA90() __asm__("func_8004EA90");
int N32H4ED6C() __asm__("func_8004ED6C");
int N32H4F0E8() __asm__("func_8004F0E8");
int N32H4F194() __asm__("func_8004F194");
int N32H55B18() __asm__("func_80055B18");
int N32Rand() __asm__("rand");
extern int N32Tick __asm__("D_8006C640");
extern int N32Gate __asm__("D_8006C54C");
extern int N32Flag0 __asm__("D_8006580C");
extern int N32Flag1 __asm__("D_80065834");
extern void* (*N32Spawn)() __asm__("SpawnMoby");
extern void* (*N32Particle)() __asm__("SpawnParticle");
void func_level_32_80084D60(void* input){
 struct {int old[4],zero[4],vector[4],position[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$17")=input;
 register unsigned char* tag __asm__("$19");
 register int x __asm__("$6");register int y __asm__("$5");register int z __asm__("$4");
 register int maximum __asm__("$3");register int work2 __asm__("$2");register int work3 __asm__("$3");
 register int heading16 __asm__("$16");register unsigned char* target18 __asm__("$18");
 register unsigned char* child16 __asm__("$16");register void* position18 __asm__("$18");
 register void* vector18 __asm__("$18");register void* point16 __asm__("$16");
 register void* matrix21 __asm__("$21");register int index20 __asm__("$20");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 __asm__("" : "=r"(owner):"0"(owner));
 x=N32F(owner,int*,12);tag=N32F(owner,unsigned char**,0);
 if(x<1024)goto cleanup;
 y=N32F(owner,int*,16);if(y<1024)goto cleanup;
 z=N32F(owner,int*,20);if(z<1024)goto cleanup;
 maximum=256000;__asm__("" : "=r"(maximum):"0"(maximum));
 work2=x>maximum;__asm__("" : "=r"(work2):"0"(work2));if(work2)goto cleanup;
 work2=y>maximum;__asm__("" : "=r"(work2):"0"(work2));if(work2)goto cleanup;
 work2=z>maximum;__asm__("" : "=r"(work2):"0"(work2));if(work2)goto cleanup;
 N32H4F178(frame.old,owner+12);
 N32F(owner,int*,12)+=N32F(tag,int*,0);
 N32F(owner,int*,16)+=N32F(tag,int*,4);
 N32F(owner,int*,20)+=N32F(tag,int*,8);
 work3=N32F(tag,short*,12);work2=N32F(tag,int*,8);call4=(void*)N32Tick;
 work2+=work3;N32F(tag,int*,8)=work2;
 if(call4 && !N32Gate){N32Flag0=1;N32Flag1=1;}
 switch(owner[72]){
 case 0:goto moving;
 case 98:goto impact;
 case 99:goto particles;
 default:goto done;
 }
 moving:
 owner[68]+=4;N32H359A4(tag+14,2);
 if(!tag[18]){target18=0;goto timer;}
 {
  target18=N32H1BA30(owner+12,512,1,0,0x10170000,owner);
  if(target18){
   work2=N32H4E880(N32F(target18,int*,12)-N32F(owner,int*,12),N32F(target18,int*,16)-N32F(owner,int*,16),0);
   {register int zero6 __asm__("$6")=0;
    __asm__("" : "=r"(zero6):"0"(zero6),"r"(work2));heading16=work2;
    work2=N32H4E880(N32F(tag,int*,0),N32F(tag,int*,4),zero6);}
   target18[81]=N32H360F8(heading16,work2,32,64);
  }
 }
 timer:
 if(N32H359A4(tag+16,2))goto collision;
 call4=frame.old;if(target18)goto collision;
 __asm__("" : "=r"(call4):"0"(call4):"$18");position18=owner+12;
 work2=N32H1830C(call4,position18,0,0,N32F(tag,int*,20));call4=position18;
 if(work2)goto collision;
 __asm__("" ::: "$2");
 if(!N32H19138(call4,256,0,0,0,N32F(tag,int*,20)))goto no_collision;
 collision:
 work2=N32F(tag,short*,14);
 __asm__("" : "=r"(work2):"0"(work2));call4=owner+12;
 if(!work2){
  __asm__("" ::: "$2");
  N32F(tag,int*,0)=0;N32F(tag,int*,4)=0;N32F(tag,int*,8)=0;
  N32H4F178(call4,frame.old);owner[72]=98;goto feedback;
 }
 goto feedback_prepared;
 no_collision:
 if(N32Tick&1){point16=frame.zero;N32H4F168(point16);N32Particle(1,49,position18,point16);}
 feedback:
 call4=owner+12;
 feedback_prepared:
 N32H1A358(call4,8192);N32H5629C(owner);N32H55D24(owner,2);goto done;
 impact:
 position18=owner+12;
 if(tag[18]){
  child16=N32H1BA30(position18,1024,1,0,0x10170000,owner);
  if(child16)child16[81]=N32H4E880(N32F(child16,int*,12)-N32F(owner,int*,12),N32F(child16,int*,16)-N32F(owner,int*,16),0);
  N32H19138(position18,1024,0,0,0x10040000,owner);
 }
 if(tag[19])N32H1C288(owner+12,1024,7);
 N32H3BABC(owner,0,0);N32F(tag,short*,16)=0;owner[72]=99;
 particles:
 index20=0;matrix21=frame.matrix;vector18=frame.vector;point16=frame.position;
 do{
  frame.angles[0]=0;frame.angles[1]=N32Rand();frame.angles[2]=N32Rand();
  N32H4EA90(frame.angles,matrix21,0);
  index20++;work2=N32Rand();
  __asm__ volatile("" : "=r"(work2):"0"(work2):"$4","$5","$6");
  call4=matrix21;call5=(int)vector18;call6=vector18;
  __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2):"0"(call4),"1"(call5),"2"(call6),"3"(work2):"memory");
  work2=(work2&31)+48;frame.vector[0]=work2;frame.vector[1]=0;frame.vector[2]=0;
  N32H4ED6C(call4,(void*)call5,call6);
  N32H4F178(point16,vector18);N32H4F0E8(point16,2);
  __asm__("" : "=r"(owner):"0"(owner));N32H4F194(point16,point16,owner+12);
  N32Particle(1,13,point16,vector18);
  __asm__("" : "=r"(owner):"0"(owner));
 }while(index20<4);
 N32Particle(8,70,owner+12,(void*)16);
 child16=N32Spawn(326,owner);
 if(child16){
  child16[71]=4;
  if(N32F(tag,short*,16)){
   frame.angles[0]=0;frame.angles[1]=N32Rand();frame.angles[2]=N32Rand();
   N32H4EA90(frame.angles,matrix21,0);work2=N32Rand();
   __asm__ volatile("" : "=r"(work2):"0"(work2):"$4","$5","$6");
   call4=matrix21;call5=(int)vector18;call6=vector18;
   __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2):"0"(call4),"1"(call5),"2"(call6),"3"(work2):"memory");
   work2&=255;__asm__("" : "=r"(work2):"0"(work2));work2+=256;frame.vector[0]=work2;frame.vector[1]=0;frame.vector[2]=0;
   N32H4ED6C(call4,(void*)call5,call6);N32H4F194(child16+12,child16+12,vector18);
  }
 }
 work2=N32F(tag,unsigned short*,16)+1;N32F(tag,short*,16)=work2;
 if((short)work2<5)goto done;
 cleanup:N32H55B18(owner);
 done:__asm__ volatile("" ::: "memory");
}
#undef N32F


extern unsigned char DecodedSpawnFlags __asm__("D_8006C7B4");
extern unsigned char DecodedSpawnLevelFlags[] __asm__("D_80070300");
extern int D_8006C58C;
extern unsigned char* DecodedSpawnModels[] __asm__("D_8006EE2C");
extern unsigned char DecodedSpawnUnsaved[] __asm__("D_8006C7F8");
void DecodedSpawnSave(void*,int,void*) __asm__("func_8003B7B4");
void func_level_32_800852A8(Moby* moby) {
    int* tag = moby->mobyTag;
    Moby* spawned;
    int animation, index;
    unsigned char* frames;
    int progress;
    if (moby->state == 1 || (DecodedSpawnFlags & 1) || (DecodedSpawnLevelFlags[D_8006C58C] & 1)) goto release;
    if (moby->damageFlags & 0x40000) {
        moby->angle.yaw = *tag;
        index = 0;
        do {
            animation = func_8003636C(0, 2);
            spawned = SpawnMoby(0xD7, moby);
            if (spawned) {
                if (spawned->animationState.id != animation) {
                    spawned->unknown3[1] = 0;
                    frames = ((unsigned char**)(DecodedSpawnModels[spawned->mobyClass] + 0x3C))[animation];
                    progress = frames[0] >= 2 ? 0x30 : 0;
                    spawned->animationState.id = animation;
                    spawned->animationState.nextId = animation;
                    spawned->animationState.frame = 0;
                    spawned->animationState.nextFrame = 1;
                    spawned->animationProgress = progress;
                }
                func_8004F178(&spawned->position, &moby->position);
                spawned->position.x += func_800363DC(0, 0x384);
                spawned->position.y += func_800363DC(0, 0x384);
                spawned->position.z += func_800363DC(0, 0x384);
            }
            index++;
        } while (index < 10);
        func_8003BB10(moby, 1, 0);
        moby->state = 1;
        DecodedSpawnSave(&moby->state, 1, DecodedSpawnUnsaved);
        goto release;
    }
    return;
release:
    func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Original SCUS-94467 assembly SHA256 5de24f28b78484cea6b93c98e059c35ed3e3b25dbde237092eb60bcdc9e0b545. Rev1 raw270 provides a structural crosswalk only. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int Fleet85480_func_800410F8() __asm__("func_800410F8");      
int Fleet85480_func_8004F168() __asm__("func_8004F168");                      
int Fleet85480_func_8004F334() __asm__("func_8004F334");              
int Fleet85480_func_80055D24() __asm__("func_80055D24");             
extern signed short Fleet85480_D_800658A0 __asm__("D_800658A0");
extern signed short Fleet85480_D_80065920 __asm__("D_80065920");
extern int Fleet85480_D_80069020 __asm__("D_80069020");
extern int Fleet85480_D_80069024 __asm__("D_80069024");
extern int Fleet85480_D_80069028 __asm__("D_80069028");
extern int Fleet85480_D_8006C58C __asm__("D_8006C58C");
extern int Fleet85480_D_8006E160 __asm__("D_8006E160");
extern int Fleet85480_D_8006E53C __asm__("D_8006E53C");
extern unsigned char Fleet85480_D_80070328 __asm__("D_80070328");
extern signed char Fleet85480_D_80071573 __asm__("D_80071573");
extern unsigned char Fleet85480_D_level_32_8009D030 __asm__("D_level_32_8009D030");
extern unsigned char Fleet5946_StreamBegin __asm__("func_level_32_80075B98");
extern unsigned char main_TEXT_END;
extern unsigned char main_TEXT_START;

void func_level_32_80085480(Moby *inputMoby) {
    /* Member names retain original stack offsets and raw retail units. */
    struct {int sp10;int sp14;} originalStack;

register Moby *moby __asm__("$17")=inputMoby;

    register int previousValue20 __asm__("$20");
    register int tableIndex3 __asm__("$3");
    register int firstAccumulator3 __asm__("$3");
    register int currentValue3 __asm__("$3");
    register int secondAccumulator3 __asm__("$3");
    register int firstBitCount4 __asm__("$4");
    register int secondBitCount4 __asm__("$4");
    register int firstByteCount5 __asm__("$5");
    register int secondByteCount5 __asm__("$5");
    register int angle2 __asm__("$2");
    register int firstWord2 __asm__("$2");
    register int secondWord2 __asm__("$2");
    register unsigned int initialStreamPointer3 __asm__("$3");
    register unsigned int nextStreamPointer3 __asm__("$3");
    register unsigned int secondStreamPointer3 __asm__("$3");
    register int frameByte2 __asm__("$2");
    register int phase3 __asm__("$3");
    register int state3 __asm__("$3");
    register void * privateData __asm__("$16");
    register void * playerLink18 __asm__("$18");
    register void *eventAddress4 __asm__("$4");
    register unsigned int streamEnd4 __asm__("$4");
    register unsigned int streamEnd7 __asm__("$7");
    register unsigned int streamBegin6 __asm__("$6");
    register unsigned int secondEnd6 __asm__("$6");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register unsigned char *playerLink19 __asm__("$19");
    register int *event18 __asm__("$18");

    __asm__("" : "=r"(moby):"0"(moby));
    phase3 = moby->substate;
    privateData = moby->mobyTag;
    switch (phase3) {                              
    case 0:                                         
        Fleet85480_func_8004F168(privateData);
        playerLink18 = &Fleet85480_D_80070328 + 0x13C;
        __asm__("" : "=r"(playerLink18):"0"(playerLink18));
        if (M2C_FIELD(playerLink18,Moby**,0) == moby) {
            if (Fleet85480_func_8004F334(&moby->position, playerLink18 - 0x13C) < 0x300) {
                moby->substate = 1;
                if (M2C_FIELD(privateData, int *, 0x24) == 0) {
                    Fleet85480_D_80069020 = 0x46;
                    Fleet85480_D_80069024 = 0xB54;
                    Fleet85480_D_80069028 = -0xC8;
                } else {
                    Fleet85480_D_80069020 = 0x136;
                    Fleet85480_D_80069024 = 0x7D0;
                    Fleet85480_D_80069028 = -0xC4;
                }
            } else {
                if (func_8004F264((int) moby->angle.yaw, func_8004E880(M2C_FIELD(playerLink18, int *, -0x13C) - moby->position.x, M2C_FIELD(&Fleet85480_D_80070328, int *, 4) - moby->position.y, 0)) < 0x80) {
                    angle2 = moby->angle.yaw + 0x40;
                } else {
                    angle2 = moby->angle.yaw + 0xC0;
                }
                tableIndex3=angle2&255;
                __asm__("" : "=r"(tableIndex3):"0"(tableIndex3));
                value2=0x10000480;
                M2C_FIELD(&Fleet85480_D_80070328,int*,0x20C)=value2;
                value2=7;
                tableIndex3*=2;
                M2C_FIELD(&Fleet85480_D_80070328,int*,0x23C)=value2;
                value2=M2C_FIELD(&Fleet85480_D_80065920,signed short*,tableIndex3);
                __asm__("" : "=r"(value2):"0"(value2));
                M2C_FIELD(&Fleet85480_D_80070328,int*,0x21C)=value2>>6;
                value2=M2C_FIELD(&Fleet85480_D_800658A0,signed short*,tableIndex3);
                __asm__("" : "=r"(value2):"0"(value2));
                value3=16;
                M2C_FIELD(&Fleet85480_D_80070328,int*,0x224)=value3;
                __asm__ volatile("" : "=r"(value2):"0"(value2):"memory");
                M2C_FIELD(&Fleet85480_D_80070328,int*,0x220)=value2>>6;
            }
        }
        if (moby->position.z >= 0x7531) {
            initialStreamPointer3 = M2C_FIELD(privateData, unsigned int *, 0x28);
            streamEnd4=(unsigned int)&main_TEXT_END;
            if(initialStreamPointer3<streamEnd4) {
                firstByteCount5 = 0;
                if (initialStreamPointer3 <= 0x7FFFU) {
                    M2C_FIELD(privateData, unsigned int *, 0x28) = (unsigned int) (Fleet85480_D_8006C58C + (&main_TEXT_START + 2));
                }
                streamEnd7=streamEnd4;
                streamBegin6=(unsigned int)&Fleet5946_StreamBegin;
firstStreamByte:
                firstBitCount4 = 0;
                M2C_FIELD(privateData, int *, 0x18) = (int) (M2C_FIELD(privateData, int *, 0x18) ^ (M2C_FIELD(M2C_FIELD(privateData, unsigned int *, 0x28),unsigned char*,0) << 8));
                do {
                    firstAccumulator3 = M2C_FIELD(privateData, int *, 0x18);
                    firstWord2=firstAccumulator3&0x8000;
                    if(firstWord2) {
                        firstWord2=(firstAccumulator3*2)^0x8005;
                    } else {
                        firstWord2=firstAccumulator3*2;
                    }
                    M2C_FIELD(privateData,int*,0x18)=firstWord2;
                    __asm__ volatile("" : : : "memory");
                    firstBitCount4 += 1;
                } while (firstBitCount4 < 8);
                firstWord2=M2C_FIELD(privateData,int*,0x18);
                nextStreamPointer3=M2C_FIELD(privateData,unsigned int*,0x28);
                firstWord2&=3;
                firstWord2+=1;
                nextStreamPointer3+=firstWord2;
                M2C_FIELD(privateData, unsigned int *, 0x28) = nextStreamPointer3;
                firstByteCount5 += 1;
                if (nextStreamPointer3 >= streamEnd7) {
                    M2C_FIELD(privateData, unsigned int *, 0x28) =streamBegin6;
                    firstByteCount5=0x40;
                    __asm__("" : "=r"(firstByteCount5):"0"(firstByteCount5));
                    firstByteCount5++;
                }
                if (firstByteCount5 < 0x40) {
                    goto firstStreamByte;
                }
            }
        }
        break;
    case 1:                                         
        if(Fleet85480_D_8006E53C & 0x40) goto cancelPhase1;
        playerLink19=&Fleet85480_D_80070328+0x13C;
        if(M2C_FIELD(playerLink19,Moby**,0)!=moby) {
cancelPhase1:
            eventAddress4=&Fleet85480_D_8006E160;
            __asm__("" : "=r"(eventAddress4):"0"(eventAddress4));
            moby->substate=0;
            value3=M2C_FIELD(eventAddress4,int*,0);
            if(value3==14) M2C_FIELD(eventAddress4,int*,0)=0;
        } else {
            event18=&Fleet85480_D_8006E160;
            if (*event18 == 0) {
                func_80013ACC(moby, 0xE);
            }
            if (*event18 == 0xE) {
                M2C_FIELD(&Fleet85480_D_80070328, int *, 0x20C) = 0x10000040;
                M2C_FIELD(&Fleet85480_D_80070328, Moby **, 0x218) = moby;
                func_8004F178(playerLink19+0xF0, &moby->position);
                M2C_FIELD(&Fleet85480_D_80070328, int *, 0x238) = (int) moby->angle.yaw;
                if (M2C_FIELD(&Fleet85480_D_80070328, int *, 0x214) == 2) {
                    M2C_FIELD(privateData, int *, 0xC) = 0;
                    moby->substate = 2;
                }
            }
        }
        break;
    case 2:                                         
        if(Fleet85480_D_8006E53C & 0x40) goto cancelPhase2;
        playerLink19=&Fleet85480_D_80070328+0x13C;
        if(M2C_FIELD(playerLink19,Moby**,0)!=moby) {
cancelPhase2:
            eventAddress4=&Fleet85480_D_8006E160;
            __asm__("" : "=r"(eventAddress4):"0"(eventAddress4));
            moby->substate=0;
            value3=M2C_FIELD(eventAddress4,int*,0);
            if(value3==14) M2C_FIELD(eventAddress4,int*,0)=0;
        } else {
            event18=&Fleet85480_D_8006E160;
            previousValue20 = M2C_FIELD(privateData, int *, 0x14);
            if (*event18 == 0) {
                func_80013ACC(moby, 0xE);
            }
            if (*event18 == 0xE) {
                Fleet85480_func_800410F8(&originalStack.sp10, privateData, 1);
                moby->angle.yaw += (int) (originalStack.sp10 + 0xA) >> 5;
                M2C_FIELD(&Fleet85480_D_80070328, int *, 0x20C) = 0x10018000;
                func_8004F178(playerLink19+0xF0, &moby->position);
                M2C_FIELD(&Fleet85480_D_80070328, int *, 0x234) = (int) (M2C_FIELD(&Fleet85480_D_80070328, int *, 0x234) + 0x283);
                M2C_FIELD(&Fleet85480_D_80070328, unsigned char *, 0x228) = (unsigned char) moby->angle.roll;
                M2C_FIELD(&Fleet85480_D_80070328, unsigned char *, 0x229) = (unsigned char) moby->angle.pitch;
                __asm__ volatile("" : : : "memory");
                value2=moby->angle.yaw;
                M2C_FIELD(&Fleet85480_D_80070328, int *, 0x23C) = 0;
                __asm__ volatile("" : "=r"(value2):"0"(value2):"memory");
                M2C_FIELD(&Fleet85480_D_80070328, unsigned char *, 0x22A) = value2;
                __asm__ volatile("" : : : "memory");
                value2=originalStack.sp14;
                currentValue3=M2C_FIELD(privateData,int*,20);
                value2>>=5;
                currentValue3-=value2;
                M2C_FIELD(privateData, int *, 0x14) = currentValue3;
                if (currentValue3 < 0) {
                    M2C_FIELD(privateData, int *, 0x14) = 0;
                }
                if (M2C_FIELD(privateData, int *, 0x14) >= 0x79) {
                    M2C_FIELD(privateData, int *, 0x14) = 0x78;
                }
            }
            value2=-8;
            currentValue3=M2C_FIELD(privateData,int*,20);
            firstBitCount4=previousValue20&value2;
            currentValue3&=value2;
            if(firstBitCount4!=currentValue3) {
                if (func_8003BFC0(moby, M2C_FIELD(privateData, int *, 0x1C)) != 0) {
                    func_8003BE70(M2C_FIELD(privateData, int *, 0x1C));
                }
                M2C_FIELD(privateData, int *, 0x1C) = func_8003BABC(moby, 0, 0);
                __asm__ volatile("" : "=r"(privateData):"0"(privateData));
            }
            if ((func_800359A4(privateData+12, 4) != 0) && (Fleet85480_D_8006E53C & 0x20)) {
                moby->state = 1;
            }
        }
        Fleet85480_func_80055D24(moby, 4);
        break;
    }
    if ((unsigned int) M2C_FIELD(privateData, unsigned int *, 0x28) >= (unsigned int) &Fleet5946_StreamBegin) {
        secondByteCount5 = 0;
        secondEnd6=(unsigned int)&Fleet85480_D_level_32_8009D030;
secondStreamByte:
        secondStreamPointer3 = M2C_FIELD(privateData, unsigned int *, 0x28);
        if (secondStreamPointer3 < secondEnd6) {
            secondBitCount4 = 0;
            M2C_FIELD(privateData, int *, 0x18) = (int) (M2C_FIELD(privateData, int *, 0x18) ^ (M2C_FIELD(secondStreamPointer3,unsigned char*,0) << 8));
            do {
                secondAccumulator3 = M2C_FIELD(privateData, int *, 0x18);
                secondWord2=secondAccumulator3&0x8000;
                if(secondWord2) secondWord2=(secondAccumulator3*2)^0x8005;
                else secondWord2=secondAccumulator3*2;
                M2C_FIELD(privateData,int*,0x18)=secondWord2;
                __asm__ volatile("" : : : "memory");
                secondBitCount4 += 1;
            } while (secondBitCount4 < 8);
            secondByteCount5 += 1;
            M2C_FIELD(privateData, unsigned int *, 0x28) = (unsigned int) (M2C_FIELD(privateData, unsigned int *, 0x28) + 1);
            if (secondByteCount5 < 0x40) {
                goto secondStreamByte;
            }
        }
    }
    state3=moby->state;
    switch(state3) {
    case 0:
        moby->animationState.id=0;
        moby->animationState.nextId=2;
        moby->animationState.frame=0;
        moby->animationState.nextFrame=0;
        goto loadProgress;
    case 1:
        __asm__("" : "=r"(state3):"0"(state3));
        func_8003BABC(moby,1,0);
        Fleet85480_func_80055D24(moby,4);
        SpawnMoby(0xC2,moby);
        M2C_FIELD(privateData,int*,12)=30;
        moby->animationState.id=1;
        moby->animationState.nextId=3;
        moby->animationState.frame=0;
        moby->animationState.nextFrame=0;
        value2=M2C_FIELD(privateData,int*,20);
        value3=2;
        moby->state=value3;
        goto shiftProgress;
    case 2:
        moby->animationState.id=1;
        moby->animationState.nextId=3;
        frameByte2=moby->animationState.frame+1;
        moby->animationState.frame=frameByte2;
        if((unsigned int)(frameByte2&255)>=14U) {
            moby->animationState.frame=14;
            moby->state=0;
        }
        moby->animationState.nextFrame=moby->animationState.frame;
loadProgress:
        value2=M2C_FIELD(privateData,int*,20);
shiftProgress:
        moby->animationProgress=value2>>3;
        break;
    }
    if ((M2C_FIELD(privateData, unsigned int *, 0x28) == &Fleet85480_D_level_32_8009D030) && (M2C_FIELD(privateData, int *, 0x18) != 0)) {
        Fleet85480_D_80071573 = 1;
        M2C_FIELD(privateData, int *, 0x18) = 0;
    }
}
#undef M2C_FIELD


extern int D_8006C648,D_8006C640;
extern Vector3D D_80071918;
int rand(void);
int func_80019194(Vector3D*,int);
int func_8004EF74(Vector3D*,Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_level_32_80085BA4(Moby* moby) {
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

typedef struct { int speed; short velocityZ; unsigned char heading, timer; unsigned char reserved08[2]; unsigned char yawStep; } DecodedMovingCollisionTag;
extern short D_80065920[], D_800658A0[];
Moby* DecodedMovingCollisionQuery(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int DecodedMovingCollisionTest(Vector3D*,int,int) __asm__("func_8001C288");
int func_80018368(Vector3D*,Vector3D*);
void func_level_32_80085EC0(Moby* moby) {
    DecodedMovingCollisionTag* tag = moby->mobyTag;
    Vector3D previous;
    Vector3D* position;
    switch (moby->state) {
    case 0:
        if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400) goto remove;
        position = &moby->position;
        func_8004F178(&previous, position);
        moby->position.x += (D_80065920[tag->heading] * tag->speed) >> 12;
        moby->position.y += (D_800658A0[tag->heading] * tag->speed) >> 12;
        moby->position.z += tag->velocityZ;
        tag->velocityZ -= 2;
        moby->angle.yaw += tag->yawStep;
        if (func_800359A4(&tag->timer, 1)) {
            if (DecodedMovingCollisionQuery(position, 0x320, 0, 0, 0x120000, moby)) moby->state = 1;
        }
        if (DecodedMovingCollisionTest(&moby->position, 0x320, 7)) moby->state = 1;
        if (func_80018368(&previous, &moby->position)) moby->state = 1;
        break;
    case 1:
    remove:
        func_80055B18(moby);
        break;
    }
}

/* SCUS-94467 USA Rev 0, 0x80086078: 222 instructions and ten switch words.
 * Indexed Moby records have 88-byte stride; model table entries are 32-bit
 * pointers. Access widths and arithmetic shifts follow the original instructions.
 * Helper meanings, position units and caller cadence remain unresolved.
 * Empty constraints preserve register allocation/order without CPU instructions.
 * AI generated; not human reviewed. */
#define P86078_FIELD(type,base,offset) (*(type*)((unsigned char*)(base)+(offset)))
extern unsigned char P86078Bytes[] __asm__("D_80070300");
extern void *P86078Models[] __asm__("D_8006EE2C");
extern struct { Vector3D position; } D_80070328;
extern int D_8006C640,D_8006C58C;
extern unsigned char D_8006C7B4;
void func_level_32_80086078(Moby *input) {
    register Moby *owner __asm__("$17")=input;
    register Moby *linkedMoby __asm__("$16");
    register int value3 __asm__("$3");
    register int offset2 __asm__("$2"), poolIndex3 __asm__("$3"), flag4 __asm__("$4");
    register Moby *pool3 __asm__("$3");
    register int literal3 __asm__("$3"), literal4 __asm__("$4");
    register int arithmetic2 __asm__("$2");
    register int angleArg6 __asm__("$6");
    int signedState;
    register int player3 __asm__("$3"), player2 __asm__("$2");
    register int x4 __asm__("$4"), y5 __asm__("$5");
    register int value2 __asm__("$2");
    unsigned char substate;
    register void *privateState __asm__("$18");

    privateState = owner->mobyTag;
    poolIndex3=P86078_FIELD(int,privateState,0);
    __asm__("" : "=r"(poolIndex3) : "0"(poolIndex3) : "$4");
    flag4=D_8006C640;
    __asm__("" : "=r"(flag4) : "0"(flag4), "r"(poolIndex3));
    offset2=poolIndex3*11;
    pool3=D_8006C550;
    __asm__("" : "=r"(pool3) : "0"(pool3), "r"(offset2));
    linkedMoby=(Moby*)((unsigned char*)pool3+(offset2<<3));
    if (flag4 == 0) {
        if ((D_8006C7B4 & 1) || (P86078Bytes[D_8006C58C] & 1)) {
            func_80055B18(owner);
            return;
        }
        value2=6;
        __asm__ __volatile__("" : "=r"(flag4) : "r"(value2));
        linkedMoby->unknown3[0] = 0;
        linkedMoby->lowDrawDistance = 0;
        linkedMoby->drawn = 0;
        *(unsigned int*)((unsigned char*)linkedMoby+8)=0;
        linkedMoby->state = value2;
        goto dispatchState;
    }
dispatchState:
    value2 = owner->state;
    __asm__ __volatile__("" : "=r"(signedState) : "0"(value2));
    value2=signedState;
    switch(value2) {
    case 0:
        if (owner->substate != 0) {
            owner->state = 1;
            func_80034F40(owner, 1);
        }
        break;
    case 1:
    case 2:
        {
        if (D_8006C770 != 0) {
            literal3=2;
            __asm__("" : "=r"(literal3) : "0"(literal3));
            value2=owner->mobyClass;
            owner->state = literal3;
            value2=*(unsigned char*)P86078_FIELD(void*,P86078Models[value2],0x44);
            __asm__("" : "=r"(value2) : "0"(value2), "r"(literal3));
            owner->animationState.id=literal3;
            owner->animationState.nextId=literal3;
            literal3=1;
            owner->animationState.frame=0;
            owner->animationState.nextFrame=literal3;
            __asm__("" : "=r"(value2) : "0"(value2), "m"(owner->animationState));
            arithmetic2=value2>=2U;
            __asm__("" : "=r"(arithmetic2) : "0"(arithmetic2));
            owner->animationProgress=-arithmetic2&0x30;
        }
        substate = owner->substate;
        switch (substate) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        case 1:
            value2=func_80055E84(owner);
            __asm__("" : "=r"(value2) : "0"(value2) : "$6");
            angleArg6=0;
            if (value2 >= 0x11) {
                value3=linkedMoby->position.z;
                __asm__("" : "=r"(value3) : "0"(value3) : "$4");
                literal4=1;
                linkedMoby->unknown3[0] = literal4;
                linkedMoby->drawn = literal4;
                x4=linkedMoby->position.x;
                y5=linkedMoby->position.y;
                __asm__("" : "=r"(y5) : "0"(y5), "r"(x4) : "$2");
                linkedMoby->lowDrawDistance = 0x3F;
                __asm__("" : "=r"(value3) : "0"(value3), "m"(linkedMoby->lowDrawDistance));
                linkedMoby->position.z = value3-0x12C;
                player3=D_80070328.position.x;
                player2=D_80070328.position.y;
                linkedMoby->angle.yaw = func_8004E880(player3 - x4, player2 - y5, angleArg6);
                linkedMoby->unknown4 = 0xFF;
                P86078_FIELD(int,privateState,4) = 0xDC;
                goto advance;
            }
            break;
        case 2:
            SpawnParticle(4, 0xC, (Vector3D *) linkedMoby, (Vector3D *)5);
            linkedMoby->angle.yaw = func_8004E880(D_80070328.position.x - linkedMoby->position.x, D_80070328.position.y - linkedMoby->position.y, 0);
            linkedMoby->position.x += (int) (D_80065920[owner->angle.yaw] * 0xF) >> 0xA;
            linkedMoby->position.y += (int) (D_800658A0[owner->angle.yaw] * 0xF) >> 0xA;
            if (func_80037A60(linkedMoby, privateState + 4, 4, 0xC, -0xC8) != 0) {
                P86078_FIELD(int,privateState,4) = (int) ((int) -P86078_FIELD(int,privateState,4) / 2);
                value2=owner->substate;
                __asm__("" : "=r"(value2) : "0"(value2) : "$3");
                literal3=5;
                owner->unknown4 = literal3;
                goto advanceLoaded;
            }
            break;
        case 3:
            if (func_80037A60(linkedMoby, privateState + 4, 4, 0xC, -0xC8) != 0) {
                value3 = P86078_FIELD(int,privateState,4);
                arithmetic2 = value3;
                if (value3 < 0) {
                    arithmetic2 = -arithmetic2;
                }
                if (arithmetic2 >= 0x1E) {
                    arithmetic2=-value3;
                    __asm__("" : "=r"(arithmetic2) : "0"(arithmetic2));
                    P86078_FIELD(int,privateState,4) = arithmetic2 / 2;
                }
                goto advance;
            }
            break;
        case 10:
            linkedMoby->state = 0;
            goto advance;
        }
        break;
    }
    }
    return;
advance:
    value2=owner->substate;
advanceLoaded:
    value2++;
    owner->substate=value2;
}


typedef struct {
    SpeechProps speech;
    unsigned char reserved14[0xC];
    int word20;
} DecodedDialogueStateTag;
extern int D_8006C640, D_8006E53C, D_8006E344;
extern unsigned char D_8007159A;
void func_80055B18(Moby*);
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
void func_level_32_800863F0(Moby* moby) {
    int flags = D_8006C640;
    DecodedDialogueStateTag* tag = moby->mobyTag;
    if (!flags && moby->mobyClass == 0x220 && !D_8007159A) {
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
    case 0:
        if (tag->speech.nextMsg == 2) tag->speech.autoTalk = 0;
        if (!tag->speech.autoTalk) {
            if (D_8006E53C & 0x10) {
                if (func_80037BBC(moby, 0)) goto start;
                tag->speech.talkable = 0;
                /* Preserve the original store-before-load ordering. */
                __asm__ volatile("" : : : "memory");
            }
            if (!tag->speech.autoTalk) return;
        }
        if (func_80037BBC(moby, 0)) {
start:
            func_800512E4(moby, 0, 0);
            moby->state = 1;
        } else tag->speech.talkable = 0;
        break;
    case 1:
        if (D_8006E344 != 1) {
            tag->word20 = 1;
            moby->state = 0;
        }
        break;
    }
}

extern int deltaTime;
void func_80055B18(Moby*);
void func_level_32_80086530(Moby* moby) {
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

/* AI-generated; not human reviewed. Verified 7C02C C sibling with only
 * original player gate or counter/mode branches from sibling3791 evidence.
 * Raw units, helper semantics and cadence remain unresolved. */
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
void func_level_32_80086608(void *input) {
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
    if(Controller7C02CField(Controller7C02CD_80070328,int*,0x1CC)==0) {
        register int playerState __asm__("$3")=Controller7C02CField(Controller7C02CD_80070328,int*,0x48);
        if(playerState==40 || ({ register unsigned int range __asm__("$2")=(unsigned int)(playerState-41); __asm__("" : "=r"(range) : "0"(range)); range<2; })) {
            register int playerBits __asm__("$2")=Controller7C02CField(Controller7C02CD_80070328,int*,0x24);
            Controller7C02CField(Controller7C02CD_80070328,int*,0x280)=0;
            __asm__("" : "=r"(playerBits) : "0"(playerBits) : "memory");
            playerBits|=0x26;
            Controller7C02CField(Controller7C02CD_80070328,int*,0x24)=playerBits;
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
    if ((temp_v1_8 < 0x1000) && (Controller7C02CField(Controller7C02CD_80070328,int*,0x244)==0) && (crossedSide != 0) && (temp_v1_8 < 0x380)) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80086E34.
 * AI generated; not human reviewed. All1263 native words,45 selectors and
 * one zero pad must match. Original tables contain23 and22 entries.
 * Frame68 (104 bytes) saves S0..S7/RA at SP40..60. Explicit local storage
 * spans SP10..3F;outgoing home area is SP00..0F. No FP/SP binding or live
 * fixed-register alias overlap exists. Every local read has its original
 * initialized producer;there are no incoming saved-register reads.
 * Original switch default entries both continue at original block106;
 * they never enter the final epilogue. State/substate switches preserve
 * callbacks,path scans,timers,
 * field resets,turn limits,sounds,created owners and particle calculations.
 * Tag scans load signed termination from the CURRENT entry before the
 * byte increment2 in the branch delay. Count*30 uses the old count before
 * increment. The otherwise unused abs(private88/8C/90)+32 calculations are
 * retained as actual original computations,without reading reserve bytes.
 * All9 variable MULT sites form complete signed64 products from staged
 * signed32 operands. Two high and seven low captures use initialized full
 * values. Low32 narrowing precedes each original signed shift. Initial /80
 * uses66666667 high>>5 and sign correction;/100 uses51EB851F high>>5 with
 * sign correction. Signed16 narrowing occurs BEFORE factors108/104/98.
 * Falsifiable arithmetic vectors:/80(-4500)=-56;/100(-4500)=-45;
 * signed16(40000)=-25536;low32(32767*32767)>>12=262128.
 * Original guarded variable DIV remains. Signed LB44/45/46 values retain
 * their full signed representation before final byte stores.
 * The target-point index is signed16 and shifted left4. Complete loaded
 * pointer metadata plus a dead A2 clobber leaves the original first LW
 * delay empty and allows A2=0 to fill the later LH delay. It emits no CPU
 * instruction and never invents a read or supplies an uninitialized value.
 * Complete A0/A1 identities precede retained callback-result copies into
 * S0 in the1A358 delays. Helper views use known original argument widths;
 * 369B8 forwards the original caller A0/A1 ABI to2E2D0,whose full semantic
 * contract is unresolved. Header743E8 retains its original three-word ABI;
 * its complete callback target/allocation chain remains an evidence need.
 * Other empty metadata consumes complete initialized original values,
 * addresses or freshly written fields;there is no opcode asm or partial
 * HILO input. Compiler,filter,flags,actual transfer/data targets and every
 * EXE/overlay retail hash remain unchanged and mandatory.
 * Confidence after gates is binary identity. Complete allocation/caller/
 * helper chains,units,fixed-point domains,cadence beyond invocation,Rev1
 * mapping and synchronized retail runtime verification remain open.
 * Next evidence:human review and original runtime/caller-chain captures.
 */
/* Original assembly SHA256 b8bccf9d15341cd51713f0804528ead39b6200353581b2b18a8430cb2d33d048 */
#define Level32_86E34Keep(v) __asm__("":"=r"(v):"0"(v))
#define Level32_86E34MultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level32_86E34CaptureHigh(dst) do{int wholeCapturedHigh;__asm__("":"=h"(wholeCapturedHigh):"x"(completeSignedProduct));(dst)=wholeCapturedHigh;Level32_86E34Keep(dst);}while(0)
#define Level32_86E34CaptureLow(dst) do{int wholeCapturedLow;__asm__("":"=l"(wholeCapturedLow):"x"(completeSignedProduct));(dst)=wholeCapturedLow;Level32_86E34Keep(dst);}while(0)
#define Level32_86E34Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level32_86E34Call1A358View1(void*,int) __asm__("func_8001A358");
void Level32_86E34Call34F40View1(void*,int) __asm__("func_80034F40");
int Level32_86E34Call35194View1(void*,void*) __asm__("func_80035194");
void Level32_86E34Call35734View1(void*) __asm__("func_80035734");
int Level32_86E34Call359A4View1(void*,int) __asm__("func_800359A4");
int Level32_86E34Call3613CView1(int,int) __asm__("func_8003613C");
int Level32_86E34Call3636CView1(int,int) __asm__("func_8003636C");
int Level32_86E34Call363DCView1(int,int) __asm__("func_800363DC");
void Level32_86E34Call369B8View1(void*,int) __asm__("func_800369B8");
void Level32_86E34Call37014View1(void*) __asm__("func_80037014");
void Level32_86E34Call37168View1(void*,void*,int) __asm__("func_80037168");
void Level32_86E34Call38BF8View1(void*,void*,int,int) __asm__("func_80038BF8");
int Level32_86E34Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
void Level32_86E34Call3BE70View1(int) __asm__("func_8003BE70");
int Level32_86E34Call3BFC0View1(void*,int) __asm__("func_8003BFC0");
int Level32_86E34Call4E880View1(int,int,int) __asm__("func_8004E880");
void Level32_86E34Call4F110View1(void*,int) __asm__("func_8004F110");
void Level32_86E34Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level32_86E34Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
int Level32_86E34Call4F264View1(int,int) __asm__("func_8004F264");
int Level32_86E34Call4F334View1(void*,void*) __asm__("func_8004F334");
void Level32_86E34Call55D24View1(void*,int) __asm__("func_80055D24");
void Level32_86E34Call55F14View1(void*,int,void*) __asm__("func_80055F14");
void Level32_86E34Call5629CView1(void*) __asm__("func_8005629C");
extern unsigned char Level32_86E34Data658A0View1 __asm__("D_800658A0");
extern unsigned char Level32_86E34Data65920View1 __asm__("D_80065920");
extern int Level32_86E34Data6C550View1 __asm__("D_8006C550");
extern int Level32_86E34Data6C640View1 __asm__("D_8006C640");
extern int Level32_86E34Data6C730View1 __asm__("D_8006C730");
extern int Level32_86E34Data6C770View1 __asm__("D_8006C770");
extern int Level32_86E34Data6C7C4View1 __asm__("D_8006C7C4");
extern unsigned char Level32_86E34Data6EE2CView1 __asm__("D_8006EE2C");
extern unsigned char Level32_86E34Data70328View1 __asm__("D_80070328");
extern void*(*Level32_86E34DataSpawnMobyView1)(int,void*) __asm__("SpawnMoby");
extern void*(*Level32_86E34DataSpawnParticleView1)(int,int,void*,void*) __asm__("SpawnParticle");
extern int(*Level32_86E34Data743E8View1)(void*,void*,void*) __asm__("unk_ovlheader_800743E8");
void func_level_32_80086E34(void* ownerParameter) {
    register int pointerCountOrIndex16 __asm__("$16"),pathCountOrTagCursor17 __asm__("$17"),owner18 __asm__("$18"),privateRecord19 __asm__("$19"),relatedOwnerOrCosineBase20 __asm__("$20"),remainderOrSineBase21 __asm__("$21"),relatedRecordOrParticleLimit22 __asm__("$22"),retainedYaw23 __asm__("$23");
    register int resultOrField2 __asm__("$2"),fieldOrIntermediate3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrField6 __asm__("$6"),argumentOrField7 __asm__("$7"),capturedLowOrScratch8 __asm__("$8"),scratch9 __asm__("$9"),scratch10 __asm__("$10");
    int retainedOriginalPitch;
    long long completeSignedProduct;
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C;
    }
    originalFrame;
    int temp_a1_5;
    int temp_v1_10;
    int temp_v1_11;
    int temp_v1_4;
    int temp_a3;
    int temp_a3_3;
    int temp_v1;
    int var_a0;
    int temp_v0_12;
    int temp_v0_13;
    int var_v1;
    int temp_v0_4;
    int temp_a0;
    int temp_a0_5;
    int temp_v0_15;
    int temp_a1_4;
    int temp_a2;
    int temp_v0_10;
    int temp_v0_2;
    int temp_v0_6;
    int temp_v1_16;
    int temp_v1_9;
    owner18=(int)ownerParameter;
    Level32_86E34Keep(owner18);
    privateRecord19 = Level32_86E34Field(owner18, int*, 0);
    resultOrField2=Level32_86E34Field(privateRecord19,int*,168);
    retainedYaw23=Level32_86E34Field(owner18,unsigned char*,70);
    fieldOrIntermediate3=resultOrField2*11;
    resultOrField2=Level32_86E34Data6C550View1;
    fieldOrIntermediate3*=8;
    relatedOwnerOrCosineBase20=resultOrField2+fieldOrIntermediate3;
    resultOrField2=Level32_86E34Field(privateRecord19,int*,64);
    relatedRecordOrParticleLimit22=Level32_86E34Field(relatedOwnerOrCosineBase20,int*,0);
    pointerCountOrIndex16=0;
    if(resultOrField2)pointerCountOrIndex16=Level32_86E34Field(resultOrField2,int*,0);
block_2:
    temp_v1 = Level32_86E34Field(owner18, int *, 0x18);
    if (!(temp_v1 & 0x8B0000)) {
        goto block_14;
    }
    if (temp_v1 & 0x10000) {
        goto block_5;
    }
    if (Level32_86E34Call4F264View1(Level32_86E34Field((int)&Level32_86E34Data70328View1, unsigned char *, 0xE), Level32_86E34Call4E880View1(Level32_86E34Field(owner18, int *, 0xC) - Level32_86E34Field((int)&Level32_86E34Data70328View1, int *, 0), Level32_86E34Field(owner18, int *, 0x10) - Level32_86E34Field((int)&Level32_86E34Data70328View1, int *, 4), 0)) >= 0x34) {
        goto block_14;
    }
block_5:
    if (Level32_86E34Field(owner18, unsigned char *, 0x48) == 2) {
        goto block_15;
    }
    Level32_86E34Call38BF8View1(owner18, privateRecord19 + 0x18, 6, 2);
    Level32_86E34Field(privateRecord19, signed char *, 0x2E) = 0x78;
    if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB4)) == 0) {
        goto block_8;
    }
    Level32_86E34Call3BE70View1(Level32_86E34Field(privateRecord19, int *, 0xB4));
block_8:
    Level32_86E34Field(privateRecord19, int *, 0xB4) = -1;
    if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB0)) == 0) {
        goto block_10;
    }
    Level32_86E34Call3BE70View1(Level32_86E34Field(privateRecord19, int *, 0xB0));
block_10:
    Level32_86E34Field(privateRecord19, int *, 0xB0) = -1;
    resultOrField2=Level32_86E34Field((int)&Level32_86E34Data70328View1,int*,176);
    fieldOrIntermediate3=0x66666667;
    Level32_86E34MultiplyComplete(resultOrField2,fieldOrIntermediate3);
    resultOrField2>>=31;
    Level32_86E34CaptureHigh(capturedLowOrScratch8);
    fieldOrIntermediate3=capturedLowOrScratch8>>5;
    fieldOrIntermediate3-=resultOrField2;
    resultOrField2=Level32_86E34Field(privateRecord19,unsigned short*,28);
    argumentOrField4=Level32_86E34Field(privateRecord19,int*,64);
    resultOrField2+=fieldOrIntermediate3;
    Level32_86E34Field(privateRecord19,unsigned short*,28)=resultOrField2;
    temp_a0=argumentOrField4;
    if (temp_a0 == 0) {
        goto block_14;
    }
    Level32_86E34Field(temp_a0, signed char *, 0x49) = 0;
    Level32_86E34Field(pointerCountOrIndex16, short *, 0xE) = 0x1E;
    Level32_86E34Field(pointerCountOrIndex16, short *, 0xC) = 0x78;
    Level32_86E34Field(pointerCountOrIndex16, short *, 0x12) = 0;
    Level32_86E34Field(pointerCountOrIndex16, short *, 0x10) = 0xC;
    Level32_86E34Field(pointerCountOrIndex16, int *, 0) = (int) ((int) (Level32_86E34Field((int)&Level32_86E34Data65920View1,short*,(Level32_86E34Field(privateRecord19, unsigned char *, 0x29) * 2)) * 0x37) >> 0xA);
    resultOrField2=Level32_86E34Field(privateRecord19,unsigned char*,41);
    argumentOrField5=4;
    resultOrField2*=2;
    fieldOrIntermediate3=Level32_86E34Field((int)&Level32_86E34Data658A0View1,short*,resultOrField2);
    resultOrField2=125;
    Level32_86E34Field(pointerCountOrIndex16,int*,8)=resultOrField2;
    resultOrField2=fieldOrIntermediate3*55;
    resultOrField2>>=10;
    Level32_86E34Field(pointerCountOrIndex16,int*,4)=resultOrField2;
    Level32_86E34Call3BABCView1(Level32_86E34Field(privateRecord19,int*,64),argumentOrField5,0);
    Level32_86E34Field(pointerCountOrIndex16, short *, 0x16) = -1;
    Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x40), signed char *, 0x48) = 1;
    if (Level32_86E34Call3BFC0View1(owner18, (int) Level32_86E34Field(pointerCountOrIndex16, short *, 0x14)) == 0) {
        goto block_13;
    }
    Level32_86E34Call3BE70View1((int) Level32_86E34Field(pointerCountOrIndex16, short *, 0x14));
block_13:
    Level32_86E34Field(pointerCountOrIndex16, short *, 0x14) = -1;
    Level32_86E34Field(privateRecord19, int*, 0x40) = 0;
block_14:
block_15:
    Level32_86E34Field(owner18, int *, 0x18) = 0;
    if (Level32_86E34Field(owner18, unsigned char *, 0x48) >= 0x17U) {
        goto block_106;
    }
    switch (Level32_86E34Field(owner18, unsigned char *, 0x48)){
    case 0:
        if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB4)) != 0) {
            goto block_19;
        }
        Level32_86E34Field(privateRecord19, int *, 0xB4) = Level32_86E34Call3BABCView1(owner18, 1, 4);
    block_19:
        if (Level32_86E34Data6C640View1 != 0) {
            goto block_21;
        }
        Level32_86E34Field(owner18, signed char *, 0x57) = 0;
        Level32_86E34Field(owner18, unsigned char *, 0x54) = (unsigned char) Level32_86E34Field((Level32_86E34Field(privateRecord19, int *, 0x7C) * 3) + Level32_86E34Field(privateRecord19, int *, 0xAC),unsigned char*,0);
        Level32_86E34Field(owner18, unsigned char *, 0x55) = (unsigned char) Level32_86E34Field(((Level32_86E34Field(privateRecord19, int *, 0x7C) * 3) + Level32_86E34Field(privateRecord19, int *, 0xAC)), unsigned char *, 1);
        Level32_86E34Field(owner18, unsigned char *, 0x56) = (unsigned char) Level32_86E34Field(((Level32_86E34Field(privateRecord19, int *, 0x7C) * 3) + Level32_86E34Field(privateRecord19, int *, 0xAC)), unsigned char *, 2);
    block_21:
        Level32_86E34Call37168View1(owner18, privateRecord19, 0x57);
        goto block_106;
    case 20:
        Level32_86E34Call4F178View1(owner18 + 0xC, Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x44), int*, 0xC));
        Level32_86E34Call37014View1(owner18);
        Level32_86E34Field(owner18,unsigned char*,82)=254;
        Level32_86E34Call55D24View1(owner18, 2);
        temp_v0_2 = Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x44), int*, 0xC);
        temp_a3 = Level32_86E34Field(temp_v0_2, int *, 0x10);
        Level32_86E34Field(owner18, unsigned char *, 0x46) = Level32_86E34Call4E880View1(temp_a3 - Level32_86E34Field(temp_v0_2, int *, 0), Level32_86E34Field(temp_v0_2, int *, 0x14) - Level32_86E34Field(temp_v0_2, int *, 4), 0);
        Level32_86E34Field(privateRecord19, short *, 0x30) = -1;
        Level32_86E34Field(privateRecord19, short *, 0x32) = -1;
        Level32_86E34Field(privateRecord19, short *, 0x36) = 0x28;
        Level32_86E34Field(privateRecord19, short *, 0x3E) = 1;
        Level32_86E34Field(privateRecord19, int *, 0x78) = 0;
        Level32_86E34Field(privateRecord19, unsigned short *, 0xA4) = (unsigned short) (((5 - Level32_86E34Field(privateRecord19, int *, 0x7C)) * 5) + 0xFA);
        Level32_86E34Field(privateRecord19, int *, 0x80) = (int) (((5 - Level32_86E34Field(privateRecord19, int *, 0x7C)) * 0x5A) + 0xB4);
        Level32_86E34Field(owner18, unsigned char *, 0x49) = 0U;
        Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x44), short *, 2) = 0;
        resultOrField2=Level32_86E34Field(privateRecord19,int*,76);
        Level32_86E34Keep(resultOrField2);
        Level32_86E34Field(privateRecord19,int*,72)=resultOrField2;
        Level32_86E34Field(resultOrField2,short*,2)=0;
        resultOrField2=21;
        goto block_105;
    case 21:
        resultOrField2=Level32_86E34Data743E8View1(owner18,Level32_86E34Field(privateRecord19,int*,68),privateRecord19+48);
        argumentOrField4=owner18+12;
        argumentOrField5=12000;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        pointerCountOrIndex16=resultOrField2;
        Level32_86E34Call1A358View1(argumentOrField4,argumentOrField5);
        Level32_86E34Call5629CView1(owner18);
        pointerCountOrIndex16&=1;
        if(!pointerCountOrIndex16)goto block_106;
        fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,68);
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,short*,2);
        if(resultOrField2)goto block_106;
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,short*,0);
        fieldOrIntermediate3=Level32_86E34Field(fieldOrIntermediate3,int*,12);
        resultOrField2*=16;
        resultOrField2+=fieldOrIntermediate3;
        fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,76);
        resultOrField2=Level32_86E34Field(resultOrField2,unsigned char*,-4);
        Level32_86E34Field(privateRecord19,int*,72)=fieldOrIntermediate3;
        Level32_86E34Field(fieldOrIntermediate3,short*,2)=resultOrField2;
        resultOrField2=22;
        Level32_86E34Field(privateRecord19,unsigned short*,166)=0;
        goto block_105;
    case 22:
        pathCountOrTagCursor17=Level32_86E34Field(privateRecord19,int*,72);
        resultOrField2=Level32_86E34Data743E8View1(owner18,pathCountOrTagCursor17,privateRecord19+48);
        argumentOrField4=owner18+12;
        argumentOrField5=12000;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        pointerCountOrIndex16=resultOrField2;
        Level32_86E34Call1A358View1(argumentOrField4,argumentOrField5);
        Level32_86E34Call5629CView1(owner18);
        pointerCountOrIndex16&=1;
        if(!pointerCountOrIndex16)goto block_40;
        temp_v1_4 = Level32_86E34Field(pathCountOrTagCursor17, short *, 0);
        remainderOrSineBase21 = (int) ((Level32_86E34Field(pathCountOrTagCursor17, short *, 2) - Level32_86E34Field(pathCountOrTagCursor17, short *, 0xA)) + temp_v1_4) % temp_v1_4;
        fieldOrIntermediate3=Level32_86E34Field(pathCountOrTagCursor17,int*,12);
        resultOrField2=remainderOrSineBase21*16;
        relatedOwnerOrCosineBase20=fieldOrIntermediate3+resultOrField2;
        temp_v0_4 = Level32_86E34Field(relatedOwnerOrCosineBase20, unsigned char *, 0xF);
        if (temp_v0_4 == 0) {
            goto block_29;
        }
        Level32_86E34Field(privateRecord19, int *, 0x80) = (int) temp_v0_4;
    block_29:
        resultOrField2=Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,14);
        fieldOrIntermediate3=Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,13);
        pointerCountOrIndex16=(unsigned int)resultOrField2>>5;
        Level32_86E34Keep(pointerCountOrIndex16);
        resultOrField2&=31;
        Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,14)=resultOrField2;
        if(fieldOrIntermediate3)goto block_31;
        resultOrField2=Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,12);
        if(!resultOrField2)goto block_38;
    block_31:
        var_a0 = Level32_86E34Call3636CView1(0, 0x64);
        if (remainderOrSineBase21 != (Level32_86E34Field(pathCountOrTagCursor17, short *, 0) - 1)) {
            goto block_33;
        }
        var_a0 = 0x64;
    block_33:
        resultOrField2=pointerCountOrIndex16*30;
        argumentOrField4=var_a0+resultOrField2;
        resultOrField2=argumentOrField4<51;
        pointerCountOrIndex16++;
        if(resultOrField2)goto block_35;
        pointerCountOrIndex16 = (Level32_86E34Field(relatedOwnerOrCosineBase20, unsigned char *, 0xD) * 4) + privateRecord19;
        pathCountOrTagCursor17 = Level32_86E34Field(relatedOwnerOrCosineBase20, unsigned char *, 0xC);
        resultOrField2=Level32_86E34Field(pointerCountOrIndex16,int*,76);
        argumentOrField5=pathCountOrTagCursor17*16;
        resultOrField2=Level32_86E34Field(resultOrField2,int*,12);
        Level32_86E34Call4F178View1(&originalFrame.sp10,resultOrField2+argumentOrField5);
        Level32_86E34Call4E880View1(originalFrame.sp10 - Level32_86E34Field(owner18, int *, 0xC), originalFrame.sp14 - Level32_86E34Field(owner18, int *, 0x10), 0);
        temp_v0_6 = Level32_86E34Field(pointerCountOrIndex16, int*, 0x4C);
        Level32_86E34Field(privateRecord19, int*, 0x48) = temp_v0_6;
        Level32_86E34Field(temp_v0_6, short *, 2) = (short) pathCountOrTagCursor17;
        goto block_38;
    block_35:
        if (pointerCountOrIndex16 < 8) {
            goto block_37;
        }
        pointerCountOrIndex16 = 7;
    block_37:
        resultOrField2=Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,14);
        fieldOrIntermediate3=pointerCountOrIndex16<<5;
        resultOrField2|=fieldOrIntermediate3;
        Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,14)=resultOrField2;
    block_38:
        resultOrField2=Level32_86E34Field(privateRecord19,int*,132);
        pathCountOrTagCursor17=Level32_86E34Field(privateRecord19,int*,72);
        fieldOrIntermediate3=resultOrField2-12;
        if(resultOrField2)goto block_41;
        resultOrField2=Level32_86E34Field(pathCountOrTagCursor17,short*,2);
        fieldOrIntermediate3=Level32_86E34Field(pathCountOrTagCursor17,int*,12);
        resultOrField2*=16;
        fieldOrIntermediate3+=resultOrField2;
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,unsigned char*,14);
        Level32_86E34Field(privateRecord19,int*,136)=0;
        Level32_86E34Field(privateRecord19,int*,140)=0;
        Level32_86E34Field(privateRecord19,int*,144)=0;
        resultOrField2&=31;
        Level32_86E34Field(privateRecord19,int*,132)=resultOrField2;
        __asm__ volatile(""::"m"(Level32_86E34Field(privateRecord19,int*,132)):"memory");
        resultOrField2=Level32_86E34Field(privateRecord19,int*,132);
        fieldOrIntermediate3=resultOrField2-12;
        block_40:resultOrField2=Level32_86E34Field(privateRecord19,int*,132);
        fieldOrIntermediate3=resultOrField2-12;
        block_41:var_v1=fieldOrIntermediate3;
        if((unsigned int)var_v1>=22U)goto block_106;
        switch (var_v1){
        case 4:
        case 5:
        case 16:
        case 17:
            resultOrField2=Level32_86E34Field(privateRecord19,int*,136);
            fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,132);
            if(resultOrField2>=0)goto originalTurn0Abs;
            resultOrField2=-resultOrField2;
            originalTurn0Abs:__asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2));
            relatedOwnerOrCosineBase20=resultOrField2+32;
            __asm__ volatile(""::"r"(relatedOwnerOrCosineBase20));
            resultOrField2=28;
            pointerCountOrIndex16=256;
            if(fieldOrIntermediate3==resultOrField2)goto originalTurn0Large;
            resultOrField2=17;
            if(fieldOrIntermediate3!=resultOrField2)goto limitFirstOriginalTurn;
            originalTurn0Large:pointerCountOrIndex16=512;
            limitFirstOriginalTurn:resultOrField2=Level32_86E34Field(privateRecord19,int*,132);
            resultOrField2-=16;
            if((unsigned int)resultOrField2<2U)pointerCountOrIndex16+=512;
            resultOrField2=Level32_86E34Field(owner18,unsigned char*,61);
            pathCountOrTagCursor17=1;
            argumentOrField4=owner18;
            if(resultOrField2==pathCountOrTagCursor17)goto applyFirstOriginalTurn;
            resultOrField2=114;
            Level32_86E34Data6C770View1=0;
            Level32_86E34Field(owner18,unsigned char*,64)=resultOrField2;
            resultOrField2=1;
            Level32_86E34Field(owner18,unsigned char*,61)=resultOrField2;
            Level32_86E34Field(owner18,unsigned char*,63)=0;
            Level32_86E34Call35734View1(argumentOrField4);
            applyFirstOriginalTurn:resultOrField2=Level32_86E34Field(owner18,unsigned char*,60);
            if(resultOrField2!=pathCountOrTagCursor17)goto originalTurn0After;
            argumentOrField5=Level32_86E34Field(privateRecord19,int*,136);
            resultOrField2=argumentOrField5;
            if(argumentOrField5>=0)goto originalTurn0Delta;
            resultOrField2=-resultOrField2;
            originalTurn0Delta:fieldOrIntermediate3=resultOrField2-12;
            argumentOrField4=-12;
            if(pointerCountOrIndex16<fieldOrIntermediate3)argumentOrField4=fieldOrIntermediate3-pointerCountOrIndex16;
            if(!argumentOrField4)goto originalTurn0After;
            resultOrField2=argumentOrField5-12;
            Level32_86E34Field(privateRecord19,int*,136)=resultOrField2;
            resultOrField2=Level32_86E34Field(owner18,unsigned char*,68);
            resultOrField2-=12;
            Level32_86E34Field(owner18,unsigned char*,68)=resultOrField2;
            originalTurn0After:resultOrField2=Level32_86E34Field(privateRecord19,int*,136);
            if(resultOrField2>=0)goto originalTurn0Check;
            resultOrField2=-resultOrField2;
            originalTurn0Check:resultOrField2=pointerCountOrIndex16<resultOrField2;
            __asm__ volatile(""::"r"(pointerCountOrIndex16),"r"(resultOrField2));
            if(!resultOrField2)goto block_106;
            goto block_98;
        case 0:
        case 1:
        case 12:
        case 13:
            resultOrField2=Level32_86E34Field(privateRecord19,int*,140);
            fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,132);
            if(resultOrField2>=0)goto originalTurn1Abs;
            resultOrField2=-resultOrField2;
            originalTurn1Abs:__asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2));
            relatedOwnerOrCosineBase20=resultOrField2+32;
            __asm__ volatile(""::"r"(relatedOwnerOrCosineBase20));
            resultOrField2=25;
            pointerCountOrIndex16=256;
            if(fieldOrIntermediate3==resultOrField2)goto originalTurn1Large;
            resultOrField2=13;
            if(fieldOrIntermediate3!=resultOrField2)goto limitSecondOriginalTurn;
            originalTurn1Large:pointerCountOrIndex16=512;
            limitSecondOriginalTurn:resultOrField2=Level32_86E34Field(owner18,unsigned char*,61);
            pathCountOrTagCursor17=1;
            argumentOrField4=owner18;
            if(resultOrField2==pathCountOrTagCursor17)goto applySecondOriginalTurn;
            resultOrField2=114;
            Level32_86E34Data6C770View1=0;
            Level32_86E34Field(owner18,unsigned char*,64)=resultOrField2;
            resultOrField2=1;
            Level32_86E34Field(owner18,unsigned char*,61)=resultOrField2;
            Level32_86E34Field(owner18,unsigned char*,63)=0;
            Level32_86E34Call35734View1(argumentOrField4);
            applySecondOriginalTurn:resultOrField2=Level32_86E34Field(owner18,unsigned char*,60);
            if(resultOrField2!=pathCountOrTagCursor17)goto originalTurn1After;
            resultOrField2=Level32_86E34Field(privateRecord19,int*,140);
            argumentOrField5=resultOrField2+12;
            fieldOrIntermediate3=argumentOrField5;
            if(argumentOrField5>=0)goto originalTurn1Delta;
            fieldOrIntermediate3=-fieldOrIntermediate3;
            originalTurn1Delta:argumentOrField4=12;
            if(pointerCountOrIndex16<fieldOrIntermediate3)argumentOrField4=fieldOrIntermediate3-pointerCountOrIndex16;
            if(!argumentOrField4)goto originalTurn1After;
            Level32_86E34Field(privateRecord19,int*,140)=argumentOrField5;
            originalTurn1After:argumentOrField4=Level32_86E34Field(privateRecord19,int*,140);
            fieldOrIntermediate3=argumentOrField4;
            if(argumentOrField4>=0)goto originalTurn1Check;
            fieldOrIntermediate3=-fieldOrIntermediate3;
            originalTurn1Check:resultOrField2=pointerCountOrIndex16<fieldOrIntermediate3;
            if(resultOrField2)goto block_98;
            resultOrField2=Level32_86E34Field(owner18,unsigned char*,69);
            resultOrField2-=argumentOrField4;
            Level32_86E34Field(owner18,unsigned char*,69)=resultOrField2;
            goto block_106;
        case 8:
        case 9:
        case 20:
        case 21:
            resultOrField2=Level32_86E34Field(privateRecord19,int*,144);
            fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,132);
            if(resultOrField2>=0)goto originalTurn2Abs;
            resultOrField2=-resultOrField2;
            originalTurn2Abs:__asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2));
            relatedOwnerOrCosineBase20=resultOrField2+32;
            __asm__ volatile(""::"r"(relatedOwnerOrCosineBase20));
            resultOrField2=21;
            pointerCountOrIndex16=256;
            if(fieldOrIntermediate3==resultOrField2)goto originalTurn2Large;
            resultOrField2=33;
            if(fieldOrIntermediate3!=resultOrField2)goto limitThirdOriginalTurn;
            originalTurn2Large:pointerCountOrIndex16=512;
            limitThirdOriginalTurn:resultOrField2=Level32_86E34Field(owner18,unsigned char*,61);
            pathCountOrTagCursor17=1;
            argumentOrField4=owner18;
            if(resultOrField2==pathCountOrTagCursor17)goto applyThirdOriginalTurn;
            resultOrField2=114;
            Level32_86E34Data6C770View1=0;
            Level32_86E34Field(owner18,unsigned char*,64)=resultOrField2;
            resultOrField2=1;
            Level32_86E34Field(owner18,unsigned char*,61)=resultOrField2;
            Level32_86E34Field(owner18,unsigned char*,63)=0;
            Level32_86E34Call35734View1(argumentOrField4);
            applyThirdOriginalTurn:resultOrField2=Level32_86E34Field(owner18,unsigned char*,60);
            if(resultOrField2!=pathCountOrTagCursor17)goto originalTurn2After;
            resultOrField2=Level32_86E34Field(privateRecord19,int*,144);
            argumentOrField5=resultOrField2+14;
            fieldOrIntermediate3=argumentOrField5;
            if(argumentOrField5>=0)goto originalTurn2Delta;
            fieldOrIntermediate3=-fieldOrIntermediate3;
            originalTurn2Delta:argumentOrField4=14;
            if(pointerCountOrIndex16<fieldOrIntermediate3)argumentOrField4=fieldOrIntermediate3-pointerCountOrIndex16;
            if(!argumentOrField4)goto originalTurn2After;
            Level32_86E34Field(privateRecord19,int*,144)=argumentOrField5;
            resultOrField2=Level32_86E34Field(owner18,unsigned char*,70);
            resultOrField2+=14;
            Level32_86E34Field(owner18,unsigned char*,70)=resultOrField2;
            originalTurn2After:argumentOrField4=Level32_86E34Field(privateRecord19,int*,144);
            resultOrField2=argumentOrField4;
            if(argumentOrField4>=0)goto originalTurn2Check;
            resultOrField2=-resultOrField2;
            originalTurn2Check:resultOrField2=resultOrField2<pointerCountOrIndex16;
            if(resultOrField2)goto block_101;
            block_98:resultOrField2=Level32_86E34Field(owner18,unsigned char*,61);
            argumentOrField4=owner18;
            if(!resultOrField2)goto block_100;
            resultOrField2=114;
            Level32_86E34Data6C770View1=0;
            Level32_86E34Field(owner18,unsigned char*,64)=resultOrField2;
            Level32_86E34Field(owner18,unsigned char*,61)=0;
            Level32_86E34Field(owner18,unsigned char*,63)=0;
            Level32_86E34Call35734View1(argumentOrField4);
            block_100:Level32_86E34Field(privateRecord19,int*,132)=0;
            goto block_106;
            block_101:resultOrField2=Level32_86E34Field(owner18,unsigned char*,70);
            resultOrField2-=argumentOrField4;
            Level32_86E34Field(owner18,unsigned char*,70)=resultOrField2;
            goto block_106;
            default:goto block_106;
        }
    case 2:
        Level32_86E34Call55D24View1(owner18, 1);
        if (Level32_86E34Call35194View1(owner18, privateRecord19 + 0x18) != 0x100) {
            goto block_106;
        }
        Level32_86E34Call55D24View1(owner18, 4);
        Level32_86E34Call369B8View1(owner18, 0x30);
        Level32_86E34Field(owner18, unsigned char *, 0x49) = 0U;
        fieldOrIntermediate3=Level32_86E34Field(relatedOwnerOrCosineBase20,unsigned char*,72);
        resultOrField2=31;
        if(fieldOrIntermediate3!=resultOrField2){
            resultOrField2=99;
            goto block_105;
        }
        resultOrField2=98;
    block_105:
        Level32_86E34Field(owner18, unsigned char *, 0x48) = resultOrField2;
    block_106:
        if (Level32_86E34Field(owner18, unsigned char *, 0x48) != 0x62) {
            goto block_116;
        }
        if (Level32_86E34Field(owner18, unsigned char *, 0x49) != 0) {
            goto block_116;
        }
        if (Level32_86E34Field(owner18, unsigned char *, 0x3C) == 0) {
            goto block_110;
        }
        resultOrField2=Level32_86E34Field(owner18,short*,54);
        resultOrField2*=4;
        resultOrField2=Level32_86E34Field((int)&Level32_86E34Data6EE2CView1,int*,resultOrField2);
        resultOrField2=Level32_86E34Field(resultOrField2,int*,60);
        Level32_86E34Data6C770View1=0;
        resultOrField2=Level32_86E34Field(resultOrField2,unsigned char*,0);
        Level32_86E34Field(owner18,unsigned char*,60)=0;
        Level32_86E34Field(owner18,unsigned char*,61)=0;
        Level32_86E34Field(owner18,unsigned char*,62)=0;
        fieldOrIntermediate3=1;
        Level32_86E34Field(owner18,unsigned char*,63)=fieldOrIntermediate3;
        resultOrField2=-((unsigned int)resultOrField2>=2U)&48;
        Level32_86E34Field(owner18,unsigned char*,64)=resultOrField2;
    block_110:
        temp_v1_9 = Level32_86E34Field(privateRecord19, int*, 0x4C);
        Level32_86E34Field(privateRecord19, int*, 0x48) = temp_v1_9;
        Level32_86E34Field(temp_v1_9, short *, 2) = (short) Level32_86E34Field(relatedRecordOrParticleLimit22, int *, 0xDC);
        temp_a1_4 = Level32_86E34Field(privateRecord19, int*, 0x48);
        temp_v1_10 = Level32_86E34Field(temp_a1_4, short *, 0);
        Level32_86E34Field(temp_a1_4, short *, 2) = (short) ((int) ((Level32_86E34Field(temp_a1_4, short *, 2) - (Level32_86E34Field(temp_a1_4, short *, 0xA) * 5)) + temp_v1_10) % temp_v1_10);
        resultOrField2=Level32_86E34Field(privateRecord19,int*,72);
        fieldOrIntermediate3=Level32_86E34Field(resultOrField2,short*,2);
        resultOrField2=Level32_86E34Field(relatedRecordOrParticleLimit22,int*,200);
        argumentOrField6=179;
        if(resultOrField2==fieldOrIntermediate3)goto block_115;
        argumentOrField5=relatedRecordOrParticleLimit22;
        loop_112:resultOrField2=Level32_86E34Field(argumentOrField5,int*,200);
        if(resultOrField2!=argumentOrField6)goto block_114;
        resultOrField2=Level32_86E34Field(argumentOrField5,int*,244);
        resultOrField2--;
        Level32_86E34Field(argumentOrField5,int*,244)=resultOrField2;
        block_114:resultOrField2=Level32_86E34Field(privateRecord19,int*,72);
        argumentOrField4=Level32_86E34Field(resultOrField2,short*,0);
        resultOrField2=Level32_86E34Field(argumentOrField5,int*,200);
        fieldOrIntermediate3=argumentOrField4-1;
        resultOrField2+=fieldOrIntermediate3;
        fieldOrIntermediate3=resultOrField2%argumentOrField4;
        Level32_86E34Field(argumentOrField5,int*,200)=fieldOrIntermediate3;
        resultOrField2=Level32_86E34Field(privateRecord19,int*,72);
        resultOrField2=Level32_86E34Field(resultOrField2,short*,2);
        if(fieldOrIntermediate3!=resultOrField2)goto loop_112;
    block_115:
        temp_a2 = Level32_86E34Field(privateRecord19, int*, 0x48);
        temp_a1_5 = Level32_86E34Field(temp_a2, short *, 2);
        temp_v1_11 = Level32_86E34Field(temp_a2, short *, 0);
        pointerCountOrIndex16 = (int) (temp_a1_5 + Level32_86E34Field(temp_a2, short *, 0xA) + temp_v1_11) % temp_v1_11;
        Level32_86E34Call4F178View1(owner18 + 0xC, Level32_86E34Field(temp_a2, int *, 0xC) + (temp_a1_5 * 0x10));
        Level32_86E34Call37014View1(owner18);
        Level32_86E34Field(owner18,unsigned char*,82)=254;
        Level32_86E34Call55D24View1(owner18, 2);
        Level32_86E34Field(owner18, unsigned char *, 0x44) = 0U;
        Level32_86E34Field(owner18, unsigned char *, 0x45) = 0U;
        resultOrField2=Level32_86E34Field(privateRecord19,int*,72);
        __asm__ volatile(""::"r"(resultOrField2):"$6");
        fieldOrIntermediate3=Level32_86E34Field(resultOrField2,int*,12);
        resultOrField2=(int)(short)Level32_86E34Field(resultOrField2,short*,2);
        argumentOrField6=0;
        resultOrField2<<=4;
        resultOrField2+=fieldOrIntermediate3;
        argumentOrField4=Level32_86E34Field(resultOrField2,int*,0);
        argumentOrField5=Level32_86E34Field(resultOrField2,int*,4);
        pointerCountOrIndex16*=16;
        pointerCountOrIndex16+=fieldOrIntermediate3;
        Level32_86E34Keep(pointerCountOrIndex16);
        argumentOrField7=Level32_86E34Field(pointerCountOrIndex16,int*,0);
        fieldOrIntermediate3=Level32_86E34Field(pointerCountOrIndex16,int*,4);
        argumentOrField4=argumentOrField7-argumentOrField4;
        argumentOrField5=fieldOrIntermediate3-argumentOrField5;
        resultOrField2=Level32_86E34Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        Level32_86E34Field(owner18,unsigned char*,70)=resultOrField2;
        Level32_86E34Field(privateRecord19, int *, 0x80) = 0;
        Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) = 0U;
        Level32_86E34Field(privateRecord19, int *, 0x84) = 0;
        Level32_86E34Field(owner18, unsigned char *, 0x48) = 0x16U;
    block_116:
        if (Level32_86E34Field(owner18, unsigned char *, 0x48) != 0x63) {
            goto block_126;
        }
        pointerCountOrIndex16 = Level32_86E34Field(owner18, unsigned char *, 0x49);
        if (pointerCountOrIndex16 == 0) {
            goto block_120;
        }
        if (pointerCountOrIndex16 == 1) {
            goto block_123;
        }
        goto block_126;
    block_120:
        if (Level32_86E34Field(owner18, unsigned char *, 0x3C) == 0) {
            goto block_122;
        }
        Level32_86E34Keep(pointerCountOrIndex16);
        resultOrField2=Level32_86E34Field(owner18,short*,54);
        resultOrField2*=4;
        resultOrField2=Level32_86E34Field((int)&Level32_86E34Data6EE2CView1,int*,resultOrField2);
        resultOrField2=Level32_86E34Field(resultOrField2,int*,60);
        Level32_86E34Data6C770View1=0;
        resultOrField2=Level32_86E34Field(resultOrField2,unsigned char*,0);
        Level32_86E34Field(owner18,unsigned char*,60)=0;
        Level32_86E34Field(owner18,unsigned char*,61)=0;
        Level32_86E34Field(owner18,unsigned char*,62)=0;
        fieldOrIntermediate3=1;
        Level32_86E34Field(owner18,unsigned char*,63)=fieldOrIntermediate3;
        resultOrField2=-((unsigned int)resultOrField2>=2U)&48;
        Level32_86E34Field(owner18,unsigned char*,64)=resultOrField2;
    block_122:
        Level32_86E34Call4F178View1(owner18 + 0xC, Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x74), int*, 0xC));
        Level32_86E34Call37014View1(owner18);
        Level32_86E34Field(owner18,unsigned char*,82)=254;
        Level32_86E34Call55D24View1(owner18, 2);
        Level32_86E34Field(owner18, unsigned char *, 0x44) = 0U;
        Level32_86E34Field(owner18, unsigned char *, 0x45) = 0U;
        temp_v0_10 = Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x74), int*, 0xC);
        temp_a3_3 = Level32_86E34Field(temp_v0_10, int *, 0x10);
        Level32_86E34Field(owner18, unsigned char *, 0x46) = Level32_86E34Call4E880View1(temp_a3_3 - Level32_86E34Field(temp_v0_10, int *, 0), Level32_86E34Field(temp_v0_10, int *, 0x14) - Level32_86E34Field(temp_v0_10, int *, 4), 0);
        Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x74), short *, 2) = 1;
        Level32_86E34Field(owner18, unsigned char *, 0x49) = (unsigned char) (Level32_86E34Field(owner18, unsigned char *, 0x49) + 1);
        goto block_126;
    block_123:
        if (Level32_86E34Data743E8View1(owner18, Level32_86E34Field(privateRecord19, int*, 0x74), privateRecord19 + 0x30) != pointerCountOrIndex16) {
            goto block_126;
        }
        if (Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x74), short *, 2) != 0) {
            goto block_126;
        }
        Level32_86E34Field(owner18, unsigned char *, 0x48) = 0U;
        Level32_86E34Call34F40View1(owner18, 0);
        return;
    block_126:
        if ((unsigned int) (Level32_86E34Field(owner18, unsigned char *, 0x48) - 0x15) >= 2U) {
            goto block_160;
        }
        resultOrField2=Level32_86E34Data6C730View1;
        relatedOwnerOrCosineBase20=1;
        pathCountOrTagCursor17=Level32_86E34Field(resultOrField2,int*,4);
        loop_128:fieldOrIntermediate3=Level32_86E34Field(pathCountOrTagCursor17,unsigned short*,0);
        fieldOrIntermediate3&=32767;
        resultOrField2=fieldOrIntermediate3*11;
        fieldOrIntermediate3=Level32_86E34Data6C550View1;
        resultOrField2*=8;
        pointerCountOrIndex16=fieldOrIntermediate3+resultOrField2;
        Level32_86E34Keep(pointerCountOrIndex16);
        resultOrField2=Level32_86E34Field(pointerCountOrIndex16,unsigned char*,72);
        if((unsigned int)resultOrField2>=128U)goto block_133;
        resultOrField2=Level32_86E34Call4F334View1(owner18+12,pointerCountOrIndex16+12);
        if(resultOrField2>=1000)goto block_133;
        resultOrField2=Level32_86E34Call4E880View1(Level32_86E34Field(pointerCountOrIndex16,int*,12)-Level32_86E34Field(owner18,int*,12),Level32_86E34Field(pointerCountOrIndex16,int*,16)-Level32_86E34Field(owner18,int*,16),0);
        resultOrField2=Level32_86E34Call4F264View1(resultOrField2,Level32_86E34Field(owner18,unsigned char*,70));
        if(resultOrField2>=48)goto block_133;
        resultOrField2=Level32_86E34Field(pointerCountOrIndex16,int*,0);
        fieldOrIntermediate3=0x20000;
        Level32_86E34Field(resultOrField2,int*,76)=relatedOwnerOrCosineBase20;
        resultOrField2=255;
        Level32_86E34Field(pointerCountOrIndex16,unsigned char*,74)=resultOrField2;
        resultOrField2=Level32_86E34Field(pointerCountOrIndex16,int*,24);
        resultOrField2|=fieldOrIntermediate3;
        Level32_86E34Field(pointerCountOrIndex16,int*,24)=resultOrField2;
        resultOrField2=Level32_86E34Field(owner18,unsigned char*,70);
        Level32_86E34Field(pointerCountOrIndex16,unsigned char*,81)=resultOrField2;
        if(resultOrField2)goto block_133;
        Level32_86E34Field(pointerCountOrIndex16,unsigned char*,81)=relatedOwnerOrCosineBase20;
        block_133:resultOrField2=Level32_86E34Field(pathCountOrTagCursor17,short*,0);
        pathCountOrTagCursor17+=2;
        if(resultOrField2>=0)goto loop_128;
        if (Level32_86E34Call359A4View1(privateRecord19 + 0x80, 4) != 0) {
            goto block_143;
        }
        if (Level32_86E34Field(owner18, unsigned char *, 0x48) != 0x15) {
            goto block_137;
        }
        if (Level32_86E34Field(privateRecord19, int *, 0x7C) >= 2) {
            goto block_139;
        }
    block_137:
        if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB0)) != 0) {
            goto block_139;
        }
        Level32_86E34Field(privateRecord19, int *, 0xB0) = Level32_86E34Call3BABCView1(owner18, 0, 4);
    block_139:
        if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB4)) == 0) {
            goto block_141;
        }
        Level32_86E34Call3BE70View1(Level32_86E34Field(privateRecord19, int *, 0xB4));
    block_141:
        Level32_86E34Field(privateRecord19, int *, 0xB4) = -1;
        temp_v0_12 = Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) + 0x14;
        Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) = temp_v0_12;
        if ((short) temp_v0_12 < 0xC9) {
            goto block_149;
        }
        Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) = 0xC8U;
        goto block_149;
    block_143:
        if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB4)) != 0) {
            goto block_145;
        }
        Level32_86E34Field(privateRecord19, int *, 0xB4) = Level32_86E34Call3BABCView1(owner18, 1, 4);
    block_145:
        if (Level32_86E34Call3BFC0View1(owner18, Level32_86E34Field(privateRecord19, int *, 0xB0)) == 0) {
            goto block_147;
        }
        Level32_86E34Call3BE70View1(Level32_86E34Field(privateRecord19, int *, 0xB0));
    block_147:
        Level32_86E34Field(privateRecord19, int *, 0xB0) = -1;
        temp_v0_13 = Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) - 0x14;
        Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) = temp_v0_13;
        if ((int)(temp_v0_13<<16)>=0) {
            goto block_149;
        }
        Level32_86E34Field(privateRecord19, unsigned short *, 0xA6) = 0U;
        block_149:resultOrField2=Level32_86E34Field(privateRecord19,unsigned short*,164);
        fieldOrIntermediate3=Level32_86E34Field(privateRecord19,unsigned short*,166);
        argumentOrField4=Level32_86E34Data6C7C4View1;
        fieldOrIntermediate3=resultOrField2+fieldOrIntermediate3;
        resultOrField2=2;
        Level32_86E34Field(privateRecord19,short*,52)=fieldOrIntermediate3;
        if(argumentOrField4!=resultOrField2)goto block_151;
        argumentOrField4=0x51EB851F;
        fieldOrIntermediate3=(short)fieldOrIntermediate3;
        Level32_86E34Keep(fieldOrIntermediate3);
        resultOrField2=fieldOrIntermediate3*108;
        goto block_155;
        block_151:resultOrField2=1;
        if(argumentOrField4!=resultOrField2)goto block_153;
        argumentOrField4=0x51EB851F;
        fieldOrIntermediate3=(short)fieldOrIntermediate3;
        Level32_86E34Keep(fieldOrIntermediate3);
        resultOrField2=fieldOrIntermediate3*104;
        goto block_155;
        block_153:if(argumentOrField4)goto block_156;
        argumentOrField4=0x51EB851F;
        fieldOrIntermediate3=(short)fieldOrIntermediate3;
        Level32_86E34Keep(fieldOrIntermediate3);
        resultOrField2=fieldOrIntermediate3*98;
        block_155:Level32_86E34MultiplyComplete(resultOrField2,argumentOrField4);
        resultOrField2>>=31;
        Level32_86E34CaptureHigh(capturedLowOrScratch8);
        fieldOrIntermediate3=capturedLowOrScratch8>>5;
        fieldOrIntermediate3-=resultOrField2;
        Level32_86E34Field(privateRecord19,short*,52)=fieldOrIntermediate3;
    block_156:
        if (Level32_86E34Field(privateRecord19, int *, 0x80) == 0) {
            goto block_160;
        }
        temp_a0_5 = Level32_86E34Field(privateRecord19, int*, 0x40);
        if (temp_a0_5 == 0) {
            goto block_160;
        }
        Level32_86E34Call55D24View1(temp_a0_5, 4);
        __asm__ volatile(""::"m"(Level32_86E34Field(privateRecord19,int*,64)));
        relatedRecordOrParticleLimit22=4;
        Level32_86E34Keep(relatedRecordOrParticleLimit22);
        pathCountOrTagCursor17=0;
        Level32_86E34Keep(pathCountOrTagCursor17);
        relatedOwnerOrCosineBase20=(int)&Level32_86E34Data65920View1;
        remainderOrSineBase21=(int)&Level32_86E34Data658A0View1;
        Level32_86E34Keep(relatedOwnerOrCosineBase20);
        Level32_86E34Keep(remainderOrSineBase21);
        argumentOrField5=(unsigned int)pathCountOrTagCursor17>>31;
        loop_159:argumentOrField5=pathCountOrTagCursor17-(((pathCountOrTagCursor17+argumentOrField5)>>1)*2);
        argumentOrField4=Level32_86E34Field(privateRecord19,int*,64);
        Level32_86E34Call55F14View1(argumentOrField4,argumentOrField5,&originalFrame.sp10);
        resultOrField2=Level32_86E34Field(privateRecord19,unsigned short*,52);
        fieldOrIntermediate3=(int)(resultOrField2<<16)>>16;
        resultOrField2=(unsigned int)(resultOrField2<<16)>>31;
        fieldOrIntermediate3+=resultOrField2;
        pointerCountOrIndex16=fieldOrIntermediate3>>1;
        resultOrField2=Level32_86E34Call363DCView1(0,140);
        resultOrField2+=256;
        Level32_86E34MultiplyComplete(pointerCountOrIndex16,resultOrField2);
        fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,64);
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,unsigned char*,70);
        resultOrField2*=2;
        resultOrField2+=relatedOwnerOrCosineBase20;
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        resultOrField2=Level32_86E34Field(resultOrField2,short*,0);
        pointerCountOrIndex16=capturedLowOrScratch8>>8;
        Level32_86E34MultiplyComplete(resultOrField2,pointerCountOrIndex16);
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,unsigned char*,69);
        resultOrField2*=2;
        resultOrField2+=relatedOwnerOrCosineBase20;
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        fieldOrIntermediate3=Level32_86E34Field(resultOrField2,short*,0);
        resultOrField2=capturedLowOrScratch8>>12;
        Level32_86E34MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        resultOrField2=capturedLowOrScratch8>>12;
        originalFrame.sp20=resultOrField2;
        fieldOrIntermediate3=Level32_86E34Field(privateRecord19,int*,64);
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,unsigned char*,70);
        resultOrField2*=2;
        resultOrField2+=remainderOrSineBase21;
        resultOrField2=Level32_86E34Field(resultOrField2,short*,0);
        Level32_86E34MultiplyComplete(resultOrField2,pointerCountOrIndex16);
        resultOrField2=Level32_86E34Field(fieldOrIntermediate3,unsigned char*,69);
        resultOrField2*=2;
        resultOrField2+=relatedOwnerOrCosineBase20;
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        fieldOrIntermediate3=Level32_86E34Field(resultOrField2,short*,0);
        resultOrField2=capturedLowOrScratch8>>12;
        Level32_86E34MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        resultOrField2=capturedLowOrScratch8>>12;
        originalFrame.sp24=resultOrField2;
        resultOrField2=Level32_86E34Field(Level32_86E34Field(privateRecord19,int*,64),unsigned char*,69);
        resultOrField2*=2;
        resultOrField2+=remainderOrSineBase21;
        resultOrField2=Level32_86E34Field(resultOrField2,short*,0);
        Level32_86E34MultiplyComplete(resultOrField2,pointerCountOrIndex16);
        pathCountOrTagCursor17++;
        argumentOrField4=1;
        argumentOrField5=13;
        argumentOrField6=(int)&originalFrame.sp10;
        argumentOrField7=(int)&originalFrame.sp20;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5),"=r"(argumentOrField6),"=r"(argumentOrField7):"0"(argumentOrField4),"1"(argumentOrField5),"2"(argumentOrField6),"3"(argumentOrField7));
        fieldOrIntermediate3=(int)Level32_86E34DataSpawnParticleView1;
        Level32_86E34Keep(fieldOrIntermediate3);
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        resultOrField2=capturedLowOrScratch8>>12;
        originalFrame.sp28=resultOrField2;
        resultOrField2=((void*(*)(int,int,void*,void*))fieldOrIntermediate3)(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
        fieldOrIntermediate3=255;
        Level32_86E34Field(resultOrField2,unsigned char*,11)=fieldOrIntermediate3;
        argumentOrField5=(unsigned int)pathCountOrTagCursor17>>31;
        if(pathCountOrTagCursor17<relatedRecordOrParticleLimit22)goto loop_159;
    block_160:
        if (Level32_86E34Field(privateRecord19, int *, 0x84) != 0) {
            goto block_172;
        }
        resultOrField2=Level32_86E34Field(owner18,unsigned char*,70);
        fieldOrIntermediate3=Level32_86E34Field(owner18,unsigned char*,72);
        argumentOrField4=resultOrField2-retainedYaw23;
        resultOrField2=22;
        argumentOrField5=4;
        if(fieldOrIntermediate3==resultOrField2)goto block_163;
        argumentOrField5=3;
        block_163:resultOrField2=argumentOrField4;
        if(argumentOrField4>=0)goto block_165;
        resultOrField2=-resultOrField2;
        block_165:resultOrField2=resultOrField2<2;
        if(!resultOrField2)goto block_167;
        if(argumentOrField4)goto block_172;
        block_167:resultOrField2=-argumentOrField4;
        Level32_86E34MultiplyComplete(resultOrField2,argumentOrField5);
        argumentOrField4=Level32_86E34Field(owner18,unsigned char*,68);
        Level32_86E34CaptureLow(capturedLowOrScratch8);
        argumentOrField5=capturedLowOrScratch8&255;
        resultOrField2=Level32_86E34Call3613CView1(argumentOrField4,argumentOrField5);
        fieldOrIntermediate3=resultOrField2;
        resultOrField2=fieldOrIntermediate3<2;
        if(resultOrField2)goto block_169;
        fieldOrIntermediate3=1;
        Level32_86E34Keep(fieldOrIntermediate3);
        block_169:resultOrField2=fieldOrIntermediate3<-1;
        if(!resultOrField2)goto block_171;
        fieldOrIntermediate3=-1;
        block_171:resultOrField2=Level32_86E34Field(owner18,unsigned char*,68);
        resultOrField2+=fieldOrIntermediate3;
        Level32_86E34Field(owner18,unsigned char*,68)=resultOrField2;
    block_172:
        if (Level32_86E34Field(privateRecord19, int*, 0x40) != 0) {
            goto block_177;
        }
        if (Level32_86E34Field(owner18, unsigned char *, 0x48) == 2) {
            goto block_176;
        }
        temp_v0_15 = Level32_86E34DataSpawnMobyView1(0x26F, owner18);
        Level32_86E34Field(privateRecord19, int*, 0x40) = temp_v0_15;
        if (temp_v0_15 == 0) {
            goto block_178;
        }
        temp_v1_16 = Level32_86E34Field(temp_v0_15,int*,0);
        Level32_86E34Field(temp_v1_16, short *, 0x16) = -1;
        Level32_86E34Field(temp_v1_16, short *, 0x14) = -1;
        Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x40), signed char *, 0x4C) = 0x3F;
        Level32_86E34Field(Level32_86E34Field(privateRecord19, int*, 0x40), signed char *, 0x4E) = 0x3F;
    block_176:
        if (Level32_86E34Field(privateRecord19, int*, 0x40) == 0) {
            goto block_178;
        }
    block_177:
        Level32_86E34Call55D24View1(owner18, 4);
        Level32_86E34Call55F14View1(owner18, 0, &originalFrame.sp10);
        Level32_86E34Call55F14View1(owner18, 1, &originalFrame.sp30);
        Level32_86E34Call4F194View1(Level32_86E34Field(privateRecord19, int*, 0x40) + 0xC, &originalFrame.sp10, &originalFrame.sp30);
        Level32_86E34Call4F110View1(Level32_86E34Field(privateRecord19, int*, 0x40) + 0xC, 1);
        resultOrField2=Level32_86E34Field(privateRecord19,int*,64);
        fieldOrIntermediate3=Level32_86E34Field(owner18,signed char*,68);
        argumentOrField4=Level32_86E34Field(owner18,signed char*,69);
        argumentOrField5=Level32_86E34Field(owner18,signed char*,70);
        __asm__ volatile(""::"r"(fieldOrIntermediate3),"r"(argumentOrField4),"r"(argumentOrField5));
        Level32_86E34Field(resultOrField2,unsigned char*,68)=fieldOrIntermediate3;
        __asm__ volatile(""::"m"(Level32_86E34Field(resultOrField2,unsigned char*,68)):"memory");
        Level32_86E34Field(resultOrField2,unsigned char*,69)=argumentOrField4;
        Level32_86E34Field(resultOrField2,unsigned char*,70)=argumentOrField5;
    block_178:
        return;
        default:goto block_106;
    }
}
#undef Level32_86E34Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800881F0.
 * AI generated; not human reviewed. All1015 original native words and actual
 * targets must match. This function owns no selectors,padding or data words.
 * FrameF0 (240 bytes) saves S0..S7/FP/RA at SPC8..EC;locals span SP18..C7.
 * Original three-word vectors begin18/28/38/48/58/68/78/88/98;SPC0 retains
 * the initialized selected target. Unwritten frame reserves are never read.
 * The odd trajectory divisor is ordinary C allocated naturally into FP.
 * It starts at0 and a found trajectory writes2*count+1. Count is bounded30;
 * original dynamic signed DIV checks and all three quotient sites remain.
 * No fixed FP/SP or overlapping live fixed-register aliases are used.
 * S2 holds the original private record;state4 replaces it with the created
 * record's private pointer only after the original private record's last use.
 * All seven variable MULT sites form complete signed64 products from staged
 * signed32 operands. Distinct complete low captures narrow before SRA12.
 * The three dot-product low words retain the original32-bit additions.
 * Table samples are signed LH;165 and75/25 calculations keep their original
 * signed shifts. Raw vectors:32767*165=5406555,SRA11=2639;
 * 2639*32767=86472113,SRA12=21111;(31>>6)*4096=0;
 * a found count29 gives divisor59;(-1000)/59 truncates toward0 to-16.
 * Physical units,fixed-point domains and invocation cadence remain open.
 * Original states0/1/2/3/4/5/6/99 retain the irregular decision tree,owner
 * scan,trajectory bounds,three quotient corrections,particle loops,collider
 * predicates,reflection/bounce paths,callbacks,field widths and call order.
 * Every local read has a producer on its path. No incoming GP value is used.
 * Typed4F194 takes its three actual arguments;the former unused fourth view
 * is removed while its initialized A3 table sample remains an ordinary role.
 * Complete owner/private pointer identities follow fresh helper returns or
 * initialized fields written by the preceding vector helper. They prevent
 * unrelated phases from sharing an address cache. Dead S3 is clobbered only
 * before its fresh original producer;its consumed word/field is initialized.
 * Empty metadata emits zero CPU instructions;no partial HILO input or opcode
 * asm is used. Actual transfer/data targets and full EXE/every-overlay hashes
 * are mandatory. Compiler,filter and production flags stay unchanged.
 * Confidence is binary identity after all gates. Complete caller/allocation
 * chains,helper semantics,units,Rev1 mapping and synchronized retail runtime
 * verification remain open. Next:human review and synchronized captures.
 */
/* Original assembly SHA256 1022fbb3e9a5e667ce2d686cf1004961ee0a1d0fd5ec300569275dc16ed0db5d */
#define Level32_881F0Keep(v) __asm__("":"=r"(v):"0"(v))
#define Level32_881F0MultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level32_881F0CaptureHigh(dst) do{int wholeCapturedHigh;__asm__("":"=h"(wholeCapturedHigh):"x"(completeSignedProduct));(dst)=wholeCapturedHigh;Level32_881F0Keep(dst);}while(0)
#define Level32_881F0CaptureLow(dst) do{int wholeCapturedLow;__asm__("":"=l"(wholeCapturedLow):"x"(completeSignedProduct));(dst)=wholeCapturedLow;Level32_881F0Keep(dst);}while(0)
#define Level32_881F0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level32_881F0Call18368View1(void*,void*) __asm__("func_80018368");
int Level32_881F0Call19194View1(void*,int) __asm__("func_80019194");
void* Level32_881F0Call1BA30View1(void*,int,int,int,int,void*) __asm__("func_8001BA30");
int Level32_881F0Call1C288View1(void*,int,int) __asm__("func_8001C288");
int Level32_881F0Call359A4View1(void*,int) __asm__("func_800359A4");
int Level32_881F0Call35D38View1(void*) __asm__("func_80035D38");
int Level32_881F0Call3636CView1(int,int) __asm__("func_8003636C");
int Level32_881F0Call363DCView1(int,int) __asm__("func_800363DC");
int Level32_881F0Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
void Level32_881F0Call3C140View1(int,int) __asm__("func_8003C140");
void Level32_881F0Call49484View1(void*) __asm__("func_80049484");
int Level32_881F0Call4E880View1(int,int,int) __asm__("func_8004E880");
int Level32_881F0Call4E9E4View1(int) __asm__("func_8004E9E4");
int Level32_881F0Call4EA2CView1(int) __asm__("func_8004EA2C");
int Level32_881F0Call4EDE8View1(void*,int) __asm__("func_8004EDE8");
int Level32_881F0Call4EF74View1(void*,void*,void*) __asm__("func_8004EF74");
void Level32_881F0Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level32_881F0Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
void Level32_881F0Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
int Level32_881F0Call4F264View1(int,int) __asm__("func_8004F264");
int Level32_881F0Call4F334View1(void*,void*) __asm__("func_8004F334");
void Level32_881F0Call55B18View1(void*) __asm__("func_80055B18");
void Level32_881F0Call5629CView1(void*) __asm__("func_8005629C");
int Level32_881F0DatarandView1(void) __asm__("rand");
extern unsigned char Level32_881F0Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level32_881F0Data65920View1[] __asm__("D_80065920");
extern int Level32_881F0Data6C574View1 __asm__("D_8006C574");
extern int Level32_881F0Data6C578View1 __asm__("D_8006C578");
extern int Level32_881F0Data6C640View1 __asm__("D_8006C640");
extern unsigned short Level32_881F0Data6E03EView1 __asm__("D_8006E03E");
extern unsigned short Level32_881F0Data6E040View1 __asm__("D_8006E040");
extern int Level32_881F0Data6E044View1 __asm__("D_8006E044");
extern int Level32_881F0Data6E788View1 __asm__("D_8006E788");
extern int Level32_881F0Data70328View1 __asm__("D_80070328");
extern int Level32_881F0Data71918View1 __asm__("D_80071918");
extern int Level32_881F0Data7191CView1 __asm__("D_8007191C");
extern int Level32_881F0Data71920View1 __asm__("D_80071920");
extern void*(*Level32_881F0DataSpawnMobyView1)(int,void*) __asm__("SpawnMoby");
extern void*(*Level32_881F0DataSpawnParticleView1)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_32_800881F0(unsigned char* ownerParameter) {
    register int positionCandidateOrScalar16 __asm__("$16"),angleAddressOrDistanceOrVector17 __asm__("$17"),privateOrCreatedPrivate18 __asm__("$18"),scanAddressOrCountOrBound19 __asm__("$19"),selectedOrCreatedOrVector20 __asm__("$20"),owner21 __asm__("$21"),bestDistanceOrCount22 __asm__("$22"),bestAngleOrSize23 __asm__("$23");
    register int resultOrField2 __asm__("$2"),fieldOrIntermediate3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrField6 __asm__("$6"),argumentOrField7 __asm__("$7"),capturedLowOrTarget8 __asm__("$8");
    int originalOddTrajectoryDivisor;
    int originalDotLow;
    long long completeSignedProduct;
    struct {
        int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4;
    }
    originalFrame;
    int initialOwnerPositionAddress;
    int temp_v0_3;
    int temp_v0_2;
    owner21=(int)ownerParameter;
    Level32_881F0Keep(owner21);
    resultOrField2=4;
    fieldOrIntermediate3=Level32_881F0Field(owner21,unsigned char*,0x48);
    privateOrCreatedPrivate18=Level32_881F0Field(owner21,int*,0);
    if(fieldOrIntermediate3==resultOrField2)goto originalState4;
    if(fieldOrIntermediate3<5){
        resultOrField2=1;
        if(fieldOrIntermediate3==resultOrField2)goto originalState1;
        if(fieldOrIntermediate3<2){
            argumentOrField6=0;
            if(!fieldOrIntermediate3)goto originalState0;
            goto originalDone;
        }
        resultOrField2=2;
        if(fieldOrIntermediate3==resultOrField2)goto originalState2;
        angleAddressOrDistanceOrVector17=(int)&originalFrame.sp68;
        resultOrField2=3;
        if(fieldOrIntermediate3==resultOrField2)goto originalState3;
        goto originalDone;
    }
    resultOrField2=6;
    if(fieldOrIntermediate3==resultOrField2)goto originalState6;
    if(fieldOrIntermediate3<6)goto originalState5;
    resultOrField2=99;
    if(fieldOrIntermediate3==resultOrField2)goto originalState99;
    goto originalDone;
    originalState0:;
    positionCandidateOrScalar16=(int)&Level32_881F0Data70328View1;
    fieldOrIntermediate3=Level32_881F0Field(owner21,int*,12);
    argumentOrField4=Level32_881F0Field(positionCandidateOrScalar16,int*,0);
    resultOrField2=Level32_881F0Field(owner21,int*,16);
    argumentOrField5=Level32_881F0Field(&Level32_881F0Data70328View1,int*,4);
    argumentOrField4=fieldOrIntermediate3-argumentOrField4;
    argumentOrField5=resultOrField2-argumentOrField5;
    resultOrField2=Level32_881F0Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=Level32_881F0Field(&Level32_881F0Data70328View1,unsigned char*,14);
    argumentOrField5=resultOrField2;
    resultOrField2=Level32_881F0Call4F264View1(argumentOrField4,argumentOrField5);
    argumentOrField4=owner21+12;
    if(resultOrField2>=16)goto originalIdleDone;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level32_881F0Call4F334View1(argumentOrField4,argumentOrField5);
    resultOrField2-=600;
    resultOrField2=resultOrField2<250;
    fieldOrIntermediate3=Level32_881F0Field(owner21,int*,20);
    argumentOrField4=Level32_881F0Field(&Level32_881F0Data70328View1,int*,8);
    fieldOrIntermediate3+=356;
    Level32_881F0Keep(fieldOrIntermediate3);
    argumentOrField4-=fieldOrIntermediate3;
    if(!resultOrField2)goto originalIdleDone;
    resultOrField2=argumentOrField4<256;
    if(!resultOrField2)goto originalIdleDone;
    resultOrField2=Level32_881F0Field(&Level32_881F0Data70328View1,int*,0x170);
    if(resultOrField2)goto originalIdleDone;
    resultOrField2=0x10000001;
    Level32_881F0Field(&Level32_881F0Data70328View1,int*,0x20C)=resultOrField2;
    resultOrField2=32;
    Level32_881F0Field(&Level32_881F0Data70328View1,int*,0x218)=owner21;
    Level32_881F0Field(owner21,unsigned char*,0x4F)=resultOrField2;
    originalIdleDone:Level32_881F0Field(privateOrCreatedPrivate18,int*,12)=0;
    return;
    originalState1:;
    Level32_881F0Field(owner21, int *, 8) = 0;
    Level32_881F0Field(owner21, signed char *, 0x4C) = 0;
    Level32_881F0Field(owner21, signed char *, 0x4D) = 0;
    resultOrField2=255;
    Level32_881F0Keep(resultOrField2);
    Level32_881F0Field(owner21, unsigned char *, 0x4A) = resultOrField2;
    return;
    originalState2:;
    Level32_881F0Field(owner21, signed char *, 0x4F) = 0x20;
    Level32_881F0Field(owner21, signed char *, 0x4C) = 0x50;
    Level32_881F0Field(owner21, unsigned char *, 0x45) = 0U;
    Level32_881F0Field(owner21, signed char *, 0x4D) = 1;
    initialOwnerPositionAddress = owner21 + 0xC;
    if (Level32_881F0Data6E044View1 == 7) {
        argumentOrField4=initialOwnerPositionAddress;
        __asm__("":"=r"(owner21):"0"(owner21),"r"(argumentOrField4));
        Level32_881F0Call49484View1(owner21 + 0xC);
    }
    else {
        Level32_881F0Field(owner21, int *, 0xC) = (int) ((int) (Level32_881F0Field(&Level32_881F0Data65920View1,short*,(Level32_881F0Field(&Level32_881F0Data70328View1, unsigned char *, 0xE) * 2)) * 0x4B) >> 9);
        argumentOrField7 = Level32_881F0Field(&Level32_881F0Data658A0View1,short*,(Level32_881F0Field(&Level32_881F0Data70328View1, unsigned char *, 0xE) * 2));
        Level32_881F0Field(owner21, int *, 0x14) = 0xC8;
        Level32_881F0Field(owner21, int *, 0x10) = (int) ((int) (argumentOrField7 * 0x4B) >> 9);
        Level32_881F0Call4F194View1(initialOwnerPositionAddress, initialOwnerPositionAddress, (int)&Level32_881F0Data70328View1);
    }
    argumentOrField4=(int)&originalFrame.sp18;
originalFirstVector:
    angleAddressOrDistanceOrVector17=(int)&Level32_881F0Data70328View1+14;
    argumentOrField7=Level32_881F0Field(angleAddressOrDistanceOrVector17,unsigned char*,0);
    argumentOrField5=argumentOrField4;
    argumentOrField7*=2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data65920View1,short*,argumentOrField7);
    argumentOrField6=angleAddressOrDistanceOrVector17-14;
    resultOrField2=fieldOrIntermediate3*25;
    resultOrField2>>=9;
    originalFrame.sp18=resultOrField2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data658A0View1,short*,argumentOrField7);
    resultOrField2=200;
    originalFrame.sp20=resultOrField2;
    resultOrField2=fieldOrIntermediate3*25;
    resultOrField2>>=9;
    originalFrame.sp1C=resultOrField2;
    Level32_881F0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=(int)&originalFrame.sp18;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level32_881F0Call18368View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    if(resultOrField2){
        argumentOrField5=(int)&originalFrame.sp18;
        Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    }
    resultOrField2=Level32_881F0Field(angleAddressOrDistanceOrVector17,unsigned char*,0);
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data70328View1,unsigned char*,0x12);
    resultOrField2+=fieldOrIntermediate3;
    Level32_881F0Field(owner21,unsigned char*,0x46)=resultOrField2;
    fieldOrIntermediate3=Level32_881F0Data6E044View1;
    resultOrField2=7;
    if(fieldOrIntermediate3==resultOrField2){
        resultOrField2=Level32_881F0Data6E03EView1;
        fieldOrIntermediate3=14;
        resultOrField2=(int)(resultOrField2<<16)>>20;
        fieldOrIntermediate3-=resultOrField2;
        Level32_881F0Field(owner21,unsigned char*,0x45)=fieldOrIntermediate3;
        resultOrField2=Level32_881F0Data6E040View1;
        resultOrField2=(unsigned int)resultOrField2>>4;
        Level32_881F0Field(owner21,unsigned char*,0x46)=resultOrField2;
    }
    else{
        resultOrField2=14;
        Level32_881F0Field(owner21,unsigned char*,0x45)=resultOrField2;
    }
    resultOrField2=Level32_881F0Field(owner21,unsigned char*,0x46);
    resultOrField2*=2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data65920View1,short*,resultOrField2);
    Level32_881F0Keep(fieldOrIntermediate3);
    resultOrField2=fieldOrIntermediate3*5;
    Level32_881F0Keep(resultOrField2);
    argumentOrField4=resultOrField2*32;
    Level32_881F0Keep(argumentOrField4);
    fieldOrIntermediate3=Level32_881F0Field(owner21,unsigned char*,0x45);
    resultOrField2+=argumentOrField4;
    fieldOrIntermediate3*=2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data65920View1,short*,fieldOrIntermediate3);
    resultOrField2>>=11;
    Level32_881F0MultiplyComplete(resultOrField2,fieldOrIntermediate3);
    Level32_881F0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    resultOrField2=Level32_881F0Field(owner21,unsigned char*,0x46);
    resultOrField2*=2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data658A0View1,short*,resultOrField2);
    Level32_881F0Keep(fieldOrIntermediate3);
    resultOrField2=fieldOrIntermediate3*5;
    Level32_881F0Keep(resultOrField2);
    argumentOrField4=resultOrField2*32;
    Level32_881F0Keep(argumentOrField4);
    fieldOrIntermediate3=Level32_881F0Field(owner21,unsigned char*,0x45);
    resultOrField2+=argumentOrField4;
    fieldOrIntermediate3*=2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data65920View1,short*,fieldOrIntermediate3);
    resultOrField2>>=11;
    Level32_881F0MultiplyComplete(resultOrField2,fieldOrIntermediate3);
    originalOddTrajectoryDivisor=0;
    selectedOrCreatedOrVector20=0;
    scanAddressOrCountOrBound19=(int)&Level32_881F0Data6E788View1;
    originalFrame.spC0=0;
    Level32_881F0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    resultOrField2=Level32_881F0Field(owner21,unsigned char*,0x45);
    bestAngleOrSize23=127;
    resultOrField2*=2;
    fieldOrIntermediate3=Level32_881F0Field(&Level32_881F0Data658A0View1,short*,resultOrField2);
    bestDistanceOrCount22=0x7800;
    resultOrField2=fieldOrIntermediate3*165;
    resultOrField2>>=11;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    goto scanOriginalOwner;
originalOwnerCandidate:
    if(positionCandidateOrScalar16==owner21)goto scanOriginalOwner;
    resultOrField2=Level32_881F0Field(positionCandidateOrScalar16,int*,8);
    argumentOrField4=owner21+12;
    if(!resultOrField2)goto scanOriginalOwner;
    argumentOrField5=positionCandidateOrScalar16+12;
    resultOrField2=Level32_881F0Call4F334View1(argumentOrField4,argumentOrField5);
    angleAddressOrDistanceOrVector17=resultOrField2;
    argumentOrField6=0;
    fieldOrIntermediate3=Level32_881F0Field(positionCandidateOrScalar16,int*,12);
    argumentOrField4=Level32_881F0Field(owner21,int*,12);
    resultOrField2=Level32_881F0Field(positionCandidateOrScalar16,int*,16);
    argumentOrField5=Level32_881F0Field(owner21,int*,16);
    argumentOrField4=fieldOrIntermediate3-argumentOrField4;
    argumentOrField5=resultOrField2-argumentOrField5;
    resultOrField2=Level32_881F0Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField5=Level32_881F0Field(owner21,unsigned char*,0x46);
    argumentOrField4=resultOrField2;
    resultOrField2=Level32_881F0Call4F264View1(argumentOrField4,argumentOrField5);
    fieldOrIntermediate3=0x1800-angleAddressOrDistanceOrVector17;
    argumentOrField4=resultOrField2;
    if(fieldOrIntermediate3<0)fieldOrIntermediate3=angleAddressOrDistanceOrVector17-0x1800;
    resultOrField2=argumentOrField4<4;
    angleAddressOrDistanceOrVector17=fieldOrIntermediate3;
    if(!resultOrField2)goto scanOriginalOwner;
    Level32_881F0Keep(angleAddressOrDistanceOrVector17);
    resultOrField2=angleAddressOrDistanceOrVector17<0x1400;
    if(!resultOrField2)goto scanOriginalOwner;
    resultOrField2=bestAngleOrSize23<argumentOrField4;
    if(resultOrField2)goto scanOriginalOwner;
    resultOrField2=angleAddressOrDistanceOrVector17<bestDistanceOrCount22;
    if(!resultOrField2)goto scanOriginalOwner;
    selectedOrCreatedOrVector20=positionCandidateOrScalar16;
    bestDistanceOrCount22=angleAddressOrDistanceOrVector17;
    bestAngleOrSize23=argumentOrField4;
scanOriginalOwner:
    positionCandidateOrScalar16=Level32_881F0Field(scanAddressOrCountOrBound19,int*,0);
    scanAddressOrCountOrBound19+=4;
    if(positionCandidateOrScalar16)goto originalOwnerCandidate;
    if(!selectedOrCreatedOrVector20)goto originalTrajectoryDone;
    angleAddressOrDistanceOrVector17=(int)&originalFrame.sp38;
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level32_881F0Keep(argumentOrField4);
    argumentOrField5=privateOrCreatedPrivate18;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    positionCandidateOrScalar16=(int)&originalFrame.sp48;
    __asm__("":"=r"(positionCandidateOrScalar16):"0"(positionCandidateOrScalar16),"m"(originalFrame.sp38));
    argumentOrField4=positionCandidateOrScalar16;
    Level32_881F0Keep(argumentOrField4);
    argumentOrField5=owner21+12;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    __asm__ volatile(""::"m"(originalFrame.sp48):"$19");
    scanAddressOrCountOrBound19=0;
    argumentOrField4=(int)&originalFrame.sp28;
originalTrajectoryLoop:
    argumentOrField5=owner21+12;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    argumentOrField6=angleAddressOrDistanceOrVector17;
    Level32_881F0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=originalFrame.sp40;
    argumentOrField6=angleAddressOrDistanceOrVector17;
    resultOrField2-=10;
    originalFrame.sp40=resultOrField2;
    Level32_881F0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    resultOrField2=originalFrame.sp40;
    fieldOrIntermediate3=originalFrame.sp48;
    resultOrField2-=10;
    originalFrame.sp40=resultOrField2;
    if(fieldOrIntermediate3<0)goto originalTrajectoryDone;
    resultOrField2=originalFrame.sp4C;
    if(resultOrField2<0)goto originalTrajectoryDone;
    resultOrField2=originalFrame.sp50;
    if(resultOrField2<0)goto originalTrajectoryDone;
    argumentOrField4=selectedOrCreatedOrVector20+12;
    if(!selectedOrCreatedOrVector20)goto originalTrajectoryNext;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level32_881F0Call4F334View1(argumentOrField4,argumentOrField5);
    if(resultOrField2>=1200)goto originalTrajectoryNext;
    resultOrField2=Level32_881F0Field(selectedOrCreatedOrVector20,int*,20);
    argumentOrField4=originalFrame.sp50;
    fieldOrIntermediate3=resultOrField2+400;
    resultOrField2=fieldOrIntermediate3-argumentOrField4;
    if(resultOrField2<0){
        resultOrField2=argumentOrField4-fieldOrIntermediate3;
        argumentOrField4=(int)&originalFrame.sp58;
        if(resultOrField2>=1000)goto originalTrajectoryNext;
    }
    else{
        argumentOrField4=(int)&originalFrame.sp58;
        if(resultOrField2>=1000){
            scanAddressOrCountOrBound19++;
            goto originalTrajectoryLimit;
        }
    }
    argumentOrField5=(int)&originalFrame.sp48;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    resultOrField2=scanAddressOrCountOrBound19*2;
    Level32_881F0Keep(resultOrField2);
    originalOddTrajectoryDivisor=resultOrField2+1;
    originalFrame.spC0=selectedOrCreatedOrVector20;
    goto originalTrajectoryDone;
    originalTrajectoryNext:scanAddressOrCountOrBound19++;
    originalTrajectoryLimit:resultOrField2=scanAddressOrCountOrBound19<30;
    argumentOrField4=(int)&originalFrame.sp28;
    if(resultOrField2)goto originalTrajectoryLoop;
originalTrajectoryDone:
    capturedLowOrTarget8=originalFrame.spC0;
    argumentOrField4=(int)&originalFrame.sp28;
    if(capturedLowOrTarget8){
        argumentOrField5=capturedLowOrTarget8+12;
        argumentOrField6=(int)&originalFrame.sp58;
        Level32_881F0Field(privateOrCreatedPrivate18,int*,12)=capturedLowOrTarget8;
        Level32_881F0Call4F1C8View1(argumentOrField4,argumentOrField5,argumentOrField6);
        fieldOrIntermediate3=originalFrame.sp28;
        fieldOrIntermediate3/=originalOddTrajectoryDivisor;
        resultOrField2=originalFrame.sp30;
        resultOrField2+=400;
        originalFrame.sp30=resultOrField2;
        resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,0);
        resultOrField2+=fieldOrIntermediate3;
        Level32_881F0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
        fieldOrIntermediate3=originalFrame.sp2C;
        fieldOrIntermediate3/=originalOddTrajectoryDivisor;
        resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,4);
        resultOrField2+=fieldOrIntermediate3;
        Level32_881F0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
        fieldOrIntermediate3=originalFrame.sp30;
        fieldOrIntermediate3/=originalOddTrajectoryDivisor;
        resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
        resultOrField2+=fieldOrIntermediate3;
        Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    }
    resultOrField2=330;
    Level32_881F0Field(privateOrCreatedPrivate18,short*,18)=resultOrField2;
    resultOrField2=3;
    Level32_881F0Field(owner21,unsigned char*,0x48)=resultOrField2;
    return;
    originalState3:;
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    Level32_881F0Call4F194View1(positionCandidateOrScalar16, positionCandidateOrScalar16, privateOrCreatedPrivate18);
    Level32_881F0Field(privateOrCreatedPrivate18, int *, 8) = (int) (Level32_881F0Field(privateOrCreatedPrivate18, int *, 8) - 0xA);
    Level32_881F0Call4EDE8View1(privateOrCreatedPrivate18, 1);
    if ((Level32_881F0Field(owner21, int *, 0xC) >= 0x400) && (Level32_881F0Field(owner21, int *, 0x10) >= 0x400) && (Level32_881F0Field(owner21, int *, 0x14) >= 0x400)) {
        if (Level32_881F0Call18368View1(&originalFrame.sp68, positionCandidateOrScalar16) != 0) {
            Level32_881F0Call4F1C8View1(positionCandidateOrScalar16, positionCandidateOrScalar16, privateOrCreatedPrivate18);
            Level32_881F0Field(owner21, unsigned char *, 0x48) = 4U;
        }
        temp_v0_2 = Level32_881F0Call1BA30View1(positionCandidateOrScalar16, 0x12C, 0, 0, 0x800000, owner21);
        if (temp_v0_2 != 0) {
            temp_v0_3 = Level32_881F0Call4E880View1(Level32_881F0Field(privateOrCreatedPrivate18, int *, 0), Level32_881F0Field(privateOrCreatedPrivate18, int *, 4), 0);
            Level32_881F0Field(temp_v0_2, unsigned char *, 0x51) = temp_v0_3;
            if (!(temp_v0_3 & 0xFF)) {
                Level32_881F0Field(temp_v0_2, unsigned char *, 0x51) = 1U;
            }
            Level32_881F0Field(owner21, unsigned char *, 0x48) = 4U;
        }
        originalFrame.sp68 = Level32_881F0Call363DCView1(0, 7);
        originalFrame.sp6C = Level32_881F0Call363DCView1(0, 7);
        originalFrame.sp70 = 0xF;
        if (Level32_881F0Data6C640View1 & 1) {
            Level32_881F0DataSpawnParticleView1(1, 0x3A, owner21 + 0xC, &originalFrame.sp68);
        }
        if (Level32_881F0Call19194View1(owner21 + 0xC, 0x7D) != 0) {
            Level32_881F0Field(owner21, unsigned char *, 0x48) = 4U;
        }
        goto block_139;
    }
    goto block_133;
    originalState4:;
    bestDistanceOrCount22=0;
originalFirstParticleLoop:
    resultOrField2=Level32_881F0Call363DCView1(0,40);
    originalFrame.sp78=resultOrField2;
    resultOrField2=Level32_881F0Call363DCView1(0,40);
    originalFrame.sp7C=resultOrField2;
    resultOrField2=Level32_881F0Call363DCView1(0,40);
    argumentOrField4=1;
    argumentOrField5=58;
    argumentOrField6=owner21+12;
    argumentOrField7=(int)&originalFrame.sp78;
    __asm__ volatile(""::"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField6),"r"(argumentOrField7):"memory");
    fieldOrIntermediate3=(int)Level32_881F0DataSpawnParticleView1;
    __asm__("":"=r"(bestDistanceOrCount22):"0"(bestDistanceOrCount22),"r"(fieldOrIntermediate3));
    bestDistanceOrCount22++;
    originalFrame.sp80=resultOrField2;
    ((void*(*)(int,int,void*,void*))fieldOrIntermediate3)(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
    if(bestDistanceOrCount22<5)goto originalFirstParticleLoop;
    bestDistanceOrCount22=0;
    bestAngleOrSize23=80;
originalCreatedParticleLoop:
    resultOrField2=Level32_881F0Data6C578View1;
    fieldOrIntermediate3=Level32_881F0Data6C574View1;
    resultOrField2-=fieldOrIntermediate3;
    argumentOrField4=owner21;
    if(resultOrField2<21)goto originalCreatedParticleDone;
    argumentOrField4=Level32_881F0Field(owner21,short*,0x36);
    resultOrField2=Level32_881F0DataSpawnMobyView1(argumentOrField4,owner21);
    selectedOrCreatedOrVector20=resultOrField2;
    Level32_881F0Keep(selectedOrCreatedOrVector20);
    if(!selectedOrCreatedOrVector20)goto originalCreatedParticleNext;
    privateOrCreatedPrivate18=Level32_881F0Field(selectedOrCreatedOrVector20,int*,0);
    resultOrField2=Level32_881F0DatarandView1();
    scanAddressOrCountOrBound19=resultOrField2&4095;
    resultOrField2=Level32_881F0DatarandView1();
    argumentOrField4=selectedOrCreatedOrVector20+12;
    argumentOrField5=owner21+12;
    fieldOrIntermediate3=-1;
    angleAddressOrDistanceOrVector17=resultOrField2&4095;
    Level32_881F0Field(selectedOrCreatedOrVector20,int*,8)=0;
    Level32_881F0Field(selectedOrCreatedOrVector20,int*,28)=fieldOrIntermediate3;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    resultOrField2=Level32_881F0Call4EA2CView1(angleAddressOrDistanceOrVector17);
    argumentOrField4=scanAddressOrCountOrBound19;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=resultOrField2;
    resultOrField2=Level32_881F0Call4EA2CView1(argumentOrField4);
    positionCandidateOrScalar16>>=6;
    Level32_881F0MultiplyComplete(positionCandidateOrScalar16,resultOrField2);
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level32_881F0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    resultOrField2=Level32_881F0Call4EA2CView1(argumentOrField4);
    argumentOrField4=scanAddressOrCountOrBound19;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=resultOrField2;
    resultOrField2=Level32_881F0Call4E9E4View1(argumentOrField4);
    positionCandidateOrScalar16>>=6;
    Level32_881F0MultiplyComplete(positionCandidateOrScalar16,resultOrField2);
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level32_881F0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    resultOrField2=Level32_881F0Call4E9E4View1(argumentOrField4);
    argumentOrField4=30;
    argumentOrField5=50;
    __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrField4),"r"(argumentOrField5));
    resultOrField2>>=6;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level32_881F0Call3636CView1(argumentOrField4,argumentOrField5);
    Level32_881F0Field(privateOrCreatedPrivate18,short*,16)=resultOrField2;
    resultOrField2=5;
    Level32_881F0Field(privateOrCreatedPrivate18,unsigned char*,20)=0;
    Level32_881F0Field(selectedOrCreatedOrVector20,unsigned char*,0x48)=resultOrField2;
    Level32_881F0Field(selectedOrCreatedOrVector20,unsigned char*,0x4F)=bestAngleOrSize23;
    Level32_881F0Field(selectedOrCreatedOrVector20,unsigned char*,0x4C)=bestAngleOrSize23;
    Level32_881F0Field(selectedOrCreatedOrVector20,unsigned char*,0x4E)=bestAngleOrSize23;
    originalCreatedParticleNext:bestDistanceOrCount22++;
    if(bestDistanceOrCount22<8)goto originalCreatedParticleLoop;
    originalCreatedParticleDone:Level32_881F0Call3BABCView1(owner21,2,0);
    goto block_133;
    originalState5:;
    resultOrField2=Level32_881F0Field(owner21,int*,12);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level32_881F0Field(owner21,int*,16);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level32_881F0Field(owner21,int*,20);
    argumentOrField4=owner21+12;
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level32_881F0Call19194View1(argumentOrField4,150);
    __asm__("":"=r"(owner21):"0"(owner21),"r"(resultOrField2));
    argumentOrField4=owner21+12;
    if(!resultOrField2)goto originalState5Move;
    argumentOrField5=(int)&Level32_881F0Data71918View1;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,0);
    resultOrField2=Level32_881F0Field(argumentOrField5,int*,0);
    Level32_881F0MultiplyComplete(fieldOrIntermediate3,resultOrField2);
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,4);
    Level32_881F0CaptureLow(argumentOrField6);
    resultOrField2=Level32_881F0Data7191CView1;
    Level32_881F0MultiplyComplete(fieldOrIntermediate3,resultOrField2);
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    Level32_881F0CaptureLow(argumentOrField4);
    resultOrField2=Level32_881F0Data71920View1;
    Level32_881F0MultiplyComplete(fieldOrIntermediate3,resultOrField2);
    resultOrField2=argumentOrField6+argumentOrField4;
    Level32_881F0CaptureLow(fieldOrIntermediate3);
    resultOrField2+=fieldOrIntermediate3;
    __asm__("":"=r"(owner21):"0"(owner21),"r"(resultOrField2));
    argumentOrField4=owner21+12;
    if(resultOrField2>=0)goto originalState5Move;
    argumentOrField4=privateOrCreatedPrivate18;
    argumentOrField6=privateOrCreatedPrivate18;
    resultOrField2=Level32_881F0Call4EF74View1(argumentOrField4,argumentOrField5,argumentOrField6);
    __asm__("":"=r"(owner21):"0"(owner21),"r"(resultOrField2));
    argumentOrField4=owner21+12;
    if(!resultOrField2)goto originalState5Move;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,0);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,4);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    originalState5Move:argumentOrField5=argumentOrField4;
    argumentOrField6=privateOrCreatedPrivate18;
    Level32_881F0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    resultOrField2-=6;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    if(resultOrField2< -128){
        resultOrField2=-128;
        Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    }
    resultOrField2=Level32_881F0Call359A4View1(privateOrCreatedPrivate18+16,2);
    if(resultOrField2)goto block_133;
    goto originalDone;
    originalState6:;
    resultOrField2=Level32_881F0Field(owner21,int*,12);
    if(resultOrField2<1024)goto originalOutside6;
    resultOrField2=Level32_881F0Field(owner21,int*,16);
    if(resultOrField2<1024)goto originalOutside6;
    resultOrField2=Level32_881F0Field(owner21,int*,20);
    if(resultOrField2<1024){
        originalOutside6:resultOrField2=4;
        Level32_881F0Field(owner21,unsigned char*,0x48)=resultOrField2;
    }
    argumentOrField4=(int)&originalFrame.sp88;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    argumentOrField6=privateOrCreatedPrivate18;
    Level32_881F0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=privateOrCreatedPrivate18;
    argumentOrField5=1;
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    __asm__ volatile(""::"r"(resultOrField2):"$19");
    scanAddressOrCountOrBound19=125;
    resultOrField2-=10;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level32_881F0Call4EDE8View1(argumentOrField4,argumentOrField5);
    Level32_881F0Keep(scanAddressOrCountOrBound19);
    fieldOrIntermediate3=resultOrField2+8;
    resultOrField2=scanAddressOrCountOrBound19<fieldOrIntermediate3;
    argumentOrField4=positionCandidateOrScalar16;
    if(resultOrField2)scanAddressOrCountOrBound19=fieldOrIntermediate3;
    argumentOrField5=scanAddressOrCountOrBound19;
    resultOrField2=Level32_881F0Call19194View1(argumentOrField4,argumentOrField5);
    if(!resultOrField2)goto originalState6Particles;
    angleAddressOrDistanceOrVector17=(int)&Level32_881F0Data71920View1;
    selectedOrCreatedOrVector20=angleAddressOrDistanceOrVector17-8;
    argumentOrField4=selectedOrCreatedOrVector20;
    Level32_881F0Keep(argumentOrField4);
    Level32_881F0Field(privateOrCreatedPrivate18,unsigned char*,20)=0;
    positionCandidateOrScalar16=Level32_881F0Field(angleAddressOrDistanceOrVector17,int*,0);
    if(positionCandidateOrScalar16<0)positionCandidateOrScalar16=-positionCandidateOrScalar16;
    resultOrField2=Level32_881F0Call4EDE8View1(argumentOrField4,0);
    positionCandidateOrScalar16=positionCandidateOrScalar16<resultOrField2;
    if(!positionCandidateOrScalar16)goto originalVerticalBounce;
    positionCandidateOrScalar16=(int)&originalFrame.sp98;
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=selectedOrCreatedOrVector20;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=privateOrCreatedPrivate18;
    Level32_881F0Keep(argumentOrField4);
    argumentOrField5=positionCandidateOrScalar16;
    Level32_881F0Keep(argumentOrField5);
    argumentOrField6=privateOrCreatedPrivate18;
    resultOrField2=Level32_881F0Call4EF74View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=owner21;
    if(!resultOrField2)goto originalState6Particles;
    argumentOrField5=0;
    argumentOrField6=0;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,0);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,4);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level32_881F0Call3BABCView1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=resultOrField2;
    if(argumentOrField4<0)goto originalState6Particles;
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    if(resultOrField2<0)resultOrField2=-resultOrField2;
    Level32_881F0Keep(resultOrField2);
    argumentOrField5=resultOrField2*40;
    Level32_881F0Call3C140View1(argumentOrField4,argumentOrField5);
    goto originalState6Particles;
originalVerticalBounce:
    positionCandidateOrScalar16=Level32_881F0Field(angleAddressOrDistanceOrVector17,int*,0);
    if(positionCandidateOrScalar16<0){
        resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
        argumentOrField4=owner21;
        if(resultOrField2>0)goto originalReverseZ;
    }
    if(positionCandidateOrScalar16<=0)goto originalState6Particles;
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    argumentOrField4=owner21;
    if(resultOrField2>=0)goto originalState6Particles;
originalReverseZ:
    argumentOrField5=0;
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    argumentOrField6=0;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,0)=0;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,4)=0;
    resultOrField2=-resultOrField2;
    resultOrField2>>=1;
    Level32_881F0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level32_881F0Call3BABCView1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=resultOrField2;
    if(argumentOrField4>=0){
        resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
        if(resultOrField2<0)resultOrField2=-resultOrField2;
        argumentOrField5=resultOrField2*40;
        Level32_881F0Call3C140View1(argumentOrField4,argumentOrField5);
    }
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,int*,8);
    if(resultOrField2<14){
        resultOrField2=Level32_881F0Call35D38View1(owner21);
        resultOrField2+=scanAddressOrCountOrBound19;
        Level32_881F0Field(owner21,int*,20)=resultOrField2;
        Level32_881F0Field(owner21,unsigned char*,0x48)=0;
    }
originalState6Particles:
    resultOrField2=Level32_881F0DatarandView1();
    resultOrField2&=3;
    originalFrame.sp88=resultOrField2;
    resultOrField2=Level32_881F0DatarandView1();
    resultOrField2&=3;
    originalFrame.sp8C=resultOrField2;
    resultOrField2=20;
    originalFrame.sp90=resultOrField2;
    resultOrField2=Level32_881F0Field(privateOrCreatedPrivate18,unsigned char*,20);
    if(!resultOrField2)goto block_139;
    resultOrField2=Level32_881F0Data6C640View1;
    resultOrField2&=1;
    argumentOrField4=1;
    if(!resultOrField2)goto block_139;
    argumentOrField5=58;
    argumentOrField6=owner21+12;
    resultOrField2=(int)Level32_881F0DataSpawnParticleView1;
    argumentOrField7=(int)&originalFrame.sp88;
    goto originalCommonParticle;
    originalState99:;
    resultOrField2=Level32_881F0Field(owner21,int*,12);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level32_881F0Field(owner21,int*,16);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level32_881F0Field(owner21,int*,20);
    argumentOrField4=(int)&originalFrame.sp98;
    if(resultOrField2<1024)goto block_133;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    Level32_881F0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    argumentOrField6=privateOrCreatedPrivate18;
    Level32_881F0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    __asm__("":"=r"(owner21):"0"(owner21),"m"(originalFrame.sp98));
    argumentOrField5=Level32_881F0Field(privateOrCreatedPrivate18,int*,12);
    argumentOrField4=positionCandidateOrScalar16;
    if(!argumentOrField5)goto originalState99NearDone;
    argumentOrField5+=12;
    resultOrField2=Level32_881F0Call4F334View1(argumentOrField4,argumentOrField5);
    if(resultOrField2>=500)goto originalState99NearDone;
    resultOrField2=Level32_881F0Field(owner21,short*,56);
    fieldOrIntermediate3=Level32_881F0Field(privateOrCreatedPrivate18,int*,12);
    argumentOrField4=Level32_881F0Field(owner21,int*,20);
    fieldOrIntermediate3=Level32_881F0Field(fieldOrIntermediate3,int*,20);
    argumentOrField4-=resultOrField2;
    resultOrField2=argumentOrField4-fieldOrIntermediate3;
    if(resultOrField2<0){
        resultOrField2=fieldOrIntermediate3-argumentOrField4;
        if(resultOrField2>=600)goto originalState99NearDone;
    }
    else{
        if(resultOrField2>=600){
            positionCandidateOrScalar16=owner21+12;
            goto originalState99NearContinue;
        }
    }
    resultOrField2=4;
    Level32_881F0Field(owner21,unsigned char*,0x48)=resultOrField2;
    originalState99NearDone:positionCandidateOrScalar16=owner21+12;
    originalState99NearContinue:argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=100;
    argumentOrField6=7;
    resultOrField2=Level32_881F0Call1C288View1(argumentOrField4,argumentOrField5,argumentOrField6);
    __asm__("":"=r"(privateOrCreatedPrivate18):"0"(privateOrCreatedPrivate18),"r"(resultOrField2));
    argumentOrField4=privateOrCreatedPrivate18+21;
    if(resultOrField2){
        argumentOrField4=Level32_881F0Field(privateOrCreatedPrivate18,int*,0);
        argumentOrField5=Level32_881F0Field(privateOrCreatedPrivate18,int*,4);
        argumentOrField6=0;
        resultOrField2=Level32_881F0Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        Level32_881F0Field(&Level32_881F0Data70328View1,int*,0x298)=resultOrField2;
        resultOrField2=4;
        Level32_881F0Field(owner21,unsigned char*,0x48)=resultOrField2;
        __asm__("":"=r"(privateOrCreatedPrivate18):"0"(privateOrCreatedPrivate18),"m"(Level32_881F0Field(owner21,unsigned char*,0x48)));
        argumentOrField4=privateOrCreatedPrivate18+21;
    }
    resultOrField2=Level32_881F0Call359A4View1(argumentOrField4,1);
    argumentOrField4=positionCandidateOrScalar16;
    if(resultOrField2){
        resultOrField2=Level32_881F0Call1BA30View1(argumentOrField4,150,0,0,0x10000000,owner21);
        if(resultOrField2){
            resultOrField2=4;
            Level32_881F0Field(owner21,unsigned char*,0x48)=resultOrField2;
        }
    }
    resultOrField2=Level32_881F0Call359A4View1(privateOrCreatedPrivate18+16,2);
    angleAddressOrDistanceOrVector17=(int)&originalFrame.sp98;
    if(!resultOrField2)goto originalState99Probe;
    block_133:Level32_881F0Call55B18View1(owner21);
    return;
originalState99Probe:
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level32_881F0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level32_881F0Call18368View1(argumentOrField4,argumentOrField5);
    if(resultOrField2){
        resultOrField2=4;
        Level32_881F0Field(owner21,unsigned char*,0x48)=resultOrField2;
    }
    resultOrField2=Level32_881F0Call363DCView1(0,7);
    originalFrame.sp98=resultOrField2;
    resultOrField2=Level32_881F0Call363DCView1(0,7);
    originalFrame.sp9C=resultOrField2;
    resultOrField2=Level32_881F0Data6C640View1;
    fieldOrIntermediate3=15;
    resultOrField2&=1;
    originalFrame.spA0=fieldOrIntermediate3;
    if(!resultOrField2)goto block_139;
    argumentOrField4=1;
    argumentOrField5=58;
    argumentOrField6=positionCandidateOrScalar16;
    resultOrField2=(int)Level32_881F0DataSpawnParticleView1;
    argumentOrField7=angleAddressOrDistanceOrVector17;
    originalCommonParticle:((void*(*)(int,int,void*,void*))resultOrField2)(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
    block_139:Level32_881F0Call35D38View1(owner21);
    Level32_881F0Call5629CView1(owner21);
    return;
    originalDone:return;
}
#undef Level32_881F0Field


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
void func_level_32_800891CC(void *input) {
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
void func_level_32_80089724(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level32
 * 800899A0: all272 original instructions in sibling4450. Verified37 model
 * count selector C reused; raw original trig products and signed division.
 * Meanings, units, cadence unresolved. Native/linked/full hash gates required. */
#define Actor32Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char Actor32Player[] __asm__("D_80070328");
extern unsigned char* Actor32Models[] __asm__("D_8006EE2C");
extern short Actor32Cos[] __asm__("D_80065920"),Actor32Sin[] __asm__("D_800658A0");
extern int Actor32Count0 __asm__("D_8006C578"),Actor32Count1 __asm__("D_8006C574");
extern unsigned char Actor32Table0[] __asm__("D_8006D088"),Actor32Table1[] __asm__("D_8006C7F8");
extern unsigned char* (*Actor32Spawn)(int,void*) __asm__("SpawnMoby");
extern int (*Actor32Indirect)(void*,int,void*) __asm__("unk_ovlheader_800743E8");
int Actor32H36220() __asm__("func_80036220");
int Actor32H55D24() __asm__("func_80055D24");
int Actor32H3B7B4() __asm__("func_8003B7B4");
int Actor32H3BABC() __asm__("func_8003BABC");
int Actor32H3636C() __asm__("func_8003636C");
int Actor32H4F194() __asm__("func_8004F194");
int Actor32H36A68() __asm__("func_80036A68");
int Actor32H38BF8() __asm__("func_80038BF8");
int Actor32H35194() __asm__("func_80035194");
int Actor32H3BA00() __asm__("func_8003BA00");
int Actor32H369B8() __asm__("func_800369B8");
int Actor32H55B18() __asm__("func_80055B18");
void func_level_32_800899A0(void* input) {
 register unsigned char* owner __asm__("$20")=input;
 register unsigned char* tag __asm__("$22");
 register unsigned char* saved __asm__("$16");
 register int angle1 __asm__("$17");
 register unsigned char* childTag __asm__("$18");
 register unsigned char* child __asm__("$19");
 register int iteration __asm__("$21");


 register int high8 __asm__("$8");register int sign3 __asm__("$3");
 register int work2 __asm__("$2");
 register int work3 __asm__("$3");
 register void* call4 __asm__("$4");
 register void* call5 __asm__("$5");
 register void* call6 __asm__("$6");


 work2=owner[0x48];tag=Actor32Field(owner,unsigned char**,0);
 if(work2==10) {
  saved=Actor32Player;
  work2=Actor32H36220(saved,tag+0x40,0,0);call4=owner;
  if(work2)goto react;
  call4=saved;call5=tag+0x58;
  __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5):"$2","$6");
  call6=0;__asm__("" : "=r"(call6):"0"(call6));
  work2=Actor32H36220(call4,call5,call6,0);call4=owner;
  if(!work2)return;
  react:
  call5=(void*)1;
  __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
  work3=1;work2=80;owner[0x41]=work3;owner[0x4C]=work2;owner[0x4D]=work3;
  Actor32H55D24(call4,call5);
  saved=tag+0x3C;owner[0x4A]=70;Actor32Field(tag,int*,0x3C)=0;
  Actor32H3B7B4(saved,4,Actor32Table0);Actor32H3B7B4(saved,4,Actor32Table1);
  owner[0x48]=0;
 }
 if((Actor32Field(owner,int*,24)&0x30000) && !owner[0x48]) {
  Actor32H3BABC(owner,0,1);Actor32H55D24(owner,4);
  iteration=0;
  do {
   work2=Actor32Count0;work3=Actor32Count1;work2=work2-work3;
   if(work2<21)goto afterLoop;
   child=Actor32Spawn(730,owner);
   __asm__("" : "=r"(child):"0"(child));
   if(child) {
    childTag=Actor32Field(child,unsigned char**,0);child[0x4C]=80;child[0x4E]=80;
    work2=Actor32H3636C(0,255);
    call4=0;call5=(void*)255;
    __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
    saved=(void*)work2;work2=Actor32H3636C(call4,call5);
    call4=0;call5=(void*)900;
    __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
    angle1=work2;work2=Actor32H3636C(call4,call5);
    {
    register short* table;
    saved=(unsigned char*)((int)saved<<1);table=Actor32Cos;
    __asm__("" : "=r"(table):"0"(table):"$3","$4","$5","$6","$7");
    work3=(int)saved+(int)table;
    work3=Actor32Field((void*)work3,short*,0);
    work3=work3*work2;
    angle1<<=1;call5=(void*)(angle1+(int)table);
    call4=(void*)(int)Actor32Field(call5,short*,0);work3>>=12;work3*=(int)call4;
    table=Actor32Sin;
    __asm__("" : "=r"(table):"0"(table):"$4","$6","$7");
    saved=(void*)((int)saved+(int)table);
    work3>>=12;Actor32Field(child,int*,12)=work3;
    work3=Actor32Field(saved,short*,0);work3*=work2;
    call4=(void*)(int)Actor32Field(call5,short*,0);work3>>=12;work3*=(int)call4;
    angle1+=(int)table;
    __asm__("" : "=r"(angle1):"0"(angle1));
    work3>>=12;Actor32Field(child,int*,16)=work3;
    work3=Actor32Field((void*)angle1,short*,0);work3*=work2;
    }
    work2=Actor32Field(child,int*,12)<<1;
    work3>>=12;Actor32Field(child,int*,20)=work3;
    /* Signed multiply-high form. Original instruction indices145/153/164
     * sequencing is checked instruction by instruction; +sign then
     * -sign expresses the exact GCC signed division lowering, with
     * the original high word in T0 and corrected quotient in V0. */
    high8=work2/3+(work2>>31);work2=high8-(work2>>31);Actor32Field(childTag,int*,4)=work2;
    work2=Actor32Field(child,int*,16)<<1;
    high8=work2/3+(work2>>31);work2=high8-(work2>>31);Actor32Field(childTag,int*,8)=work2;
    work2=Actor32Field(child,int*,20)<<1;
    call6=owner+12;call4=child+12;call5=call4;
    high8=work2/3+(work2>>31);work2=high8-(work2>>31);Actor32Field(childTag,int*,12)=work2;
    Actor32H4F194(call4,call5,call6);
    if(iteration>=11 && child[0x3C]!=1) {
     register unsigned int count __asm__("$2");
     register int multiple __asm__("$2");
     child[0x42]=0;
     count=**(unsigned char**)(Actor32Models[Actor32Field(child,short*,0x36)]+0x40);
     child[0x3C]=1;child[0x3D]=1;child[0x3E]=0;child[0x3F]=1;
     multiple=count>=2;__asm__("" : "=r"(multiple):"0"(multiple));child[0x40]=-multiple&48;
    }
   }
   iteration++;
  }while(iteration<16);
  afterLoop:
  Actor32H36A68(owner,16,0,0);Actor32H38BF8(owner,tag+4,0,1);Actor32Field(tag,short*,10)+=50;
 }
 switch(owner[0x48]) {
 case 0:
  if(Actor32Field(tag,int*,0x3C)) {
   owner[0x4A]=255;owner[0x41]=0;owner[0x4C]=0;owner[0x4D]=0;Actor32Field(owner,int*,8)=0;owner[0x48]=10;
   return;
  }
  {
   register int (*indirect)() __asm__("$3");
   call4=owner;call6=tag+0x1C;call5=(void*)Actor32Field(tag,int*,0);
   __asm__("" : "=r"(call4),"=r"(call6),"=r"(call5):"0"(call4),"1"(call6),"2"(call5));
   indirect=Actor32Indirect;work2=160;Actor32Field(tag,short*,0x20)=work2;indirect(call4,call5,call6);
  }Actor32H55D24(owner,6);return;
 case 1:
  if(Actor32H35194(owner,tag+4)==256) {
   Actor32H55D24(owner,4);Actor32H3BA00(owner);Actor32H369B8(owner,48);Actor32H55B18(owner);
  }
 }
}


typedef struct { int timer; Vector3D velocity; } DecodedWobbleTag;
extern unsigned short DecodedWobbleSin[] __asm__("D_800658A0");
extern unsigned short DecodedWobbleCos[] __asm__("D_80065920");
void func_level_32_80089DE0(Moby* moby) {
    DecodedWobbleTag* tag = moby->mobyTag;
    Vector3D offset;
    int pitch, radius, fall;
    if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400 || func_800359A4(&tag->timer, 4)) {
        func_80055B18(moby);
        return;
    }
    pitch = (short)DecodedWobbleSin[(tag->timer * 4) & 0xFC] >> 7;
    moby->angle.pitch = pitch;
    if (moby->mobyClass != 0x2DA) moby->angle.pitch = pitch + 0x40;
    radius = (short)DecodedWobbleSin[(tag->timer * 4) & 0xFC] >> 8;
    offset.x = (short)DecodedWobbleCos[moby->angle.yaw] * radius >> 12;
    offset.y = (short)DecodedWobbleSin[moby->angle.yaw] * radius >> 12;
    offset.z = 0;
    fall = (short)DecodedWobbleCos[(tag->timer * 4) & 0xFC] >> 8;
    offset.z = -ABS(fall);
    func_8004F194(&moby->position, &moby->position, &offset);
    func_8004F194(&moby->position, &moby->position, &tag->velocity);
    func_8004F1FC(&tag->velocity, &tag->velocity, 0xC0);
    func_8004F110(&tag->velocity, 8);
}

typedef struct { int reserved00[6]; int threshold; } DecodedRandomParticleRecord;
int rand(void);
extern void (*DecodedRandomPosition)(Vector3D*, int, int, void*) asm("unk_ovlheader_800743E4");
void func_level_32_80089F90(Moby* moby) {
    Vector3D position;
    Vector3D offset;
    DecodedRandomParticleRecord* tag = moby->mobyTag;
    if ((rand() & 0x3FF) < tag->threshold) {
        int x, y;
        char* particle;
        offset.x = 0;
        offset.y = 0;
        offset.z = 0x14;
        x = (rand() & 0xFF) - 0x7F;
        y = (rand() & 0xFF) - 0x7F;
        DecodedRandomPosition(&position, x, y, tag);
        particle = SpawnParticle(1, 0, &position, &offset);
        particle[0x11] = 0;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev 0 five-state controller.
 * All180 instructions and six owned table/padding words of both copies read.
 * Original byte/halfword/word widths and twelve-byte table stride retained.
 * Sources: level_11/moby/func_level_11_80079F68.s and
 * level_32/moby/func_level_32_8008A03C.s. Once per invocation; helper/table
 * producers, coordinate units and caller cadence remain unresolved.
 * Confidence: exact original compiled words. Falsifiable vectors: all linked
 * instruction/table words at those addresses and all retail hashes.
 * Empty constraints preserve original register lifetimes without opcodes.
 */
extern int D_8006C640,D_8006C754,D_8006E044,D_8006E048;
extern int D_8006E160,D_8006E1A0,D_8006E344,D_8006E53C;
extern unsigned char* Controller79F68Records __asm__("D_8006C758");
void func_level_32_8008A03C(Moby *argument) {
    register Moby* moby __asm__("$17")=argument;
    Vector3D position;
    int sampledHeight;
    unsigned char state;
    register int value __asm__("$2");
    register Vector3D* prepared __asm__("$4");
    register int* transitionWord __asm__("$4");
    register Moby* removalTarget __asm__("$4");
    register unsigned char* stateAddress __asm__("$16");
    register int* playerControl __asm__("$16");
    register unsigned char* record __asm__("$3");

    state = moby->state;
    switch (state) {
    case 0:
        { register int blocked __asm__("$2")=D_8006C640;
          __asm__("" : "=r"(blocked),"=r"(moby) : "0"(blocked),"1"(moby) : "$4");
          removalTarget=moby;
          if(blocked) goto removeMoby;
          if(!D_8006C754) goto removeMoby;
          __asm__ volatile("" : : : "memory");
          stateAddress=&moby->state;
          if(!Controller79F68Records) goto removeMoby;
          moby->state=4;
          func_8003B7B4(stateAddress,1,&savedData);
          func_8003B7B4(stateAddress,1,&unsavedData);
          func_80013CC4(D_8006C754,8);
          D_8006E344=14;
          moby->state=1;
          return;
        }
    case 1:
        transitionWord=&D_8006E160;
        __asm__("" : "=r"(transitionWord) : "0"(transitionWord));
        if(*transitionWord==10) {
            if(!(D_8006E53C&0x850))goto loadSelectedRecord;
            *transitionWord=0;
            value=3;
        } else value=2;
        moby->state=value;
        goto loadSelectedRecord;
    case 2:
        /* Word at player +0x20C; fallback height at player +8. */
        __asm__ volatile("" : : : "memory");
        value=0x10000082;
        prepared=&position;
          __asm__("" : "=r"(value),"=r"(prepared) : "0"(value),"1"(prepared) : "$16");
        playerControl=&spyro.unk17a;
        *playerControl = value;
        spyro.unk20[1] = 0x12;
        func_8004F178(prepared, (Vector3D *) ((unsigned char*)playerControl - 0x20C));
        sampledHeight = func_8001A358(&position, 0x1000);
        position.z = sampledHeight;
        if (sampledHeight == 0) {
            __asm__("" : "=r"(playerControl) : "0"(playerControl));
            position.z = *(int*)((unsigned char*)playerControl - 0x204);
        } else {
            position.z = sampledHeight + spyro.unk4a;
        }
        func_8003B634(&savedData, &position, spyro.bodyRotation.yaw);
        __asm__ volatile("" : : : "$4", "memory");
        D_8006E344 = 0;
        __asm__ volatile("" : : : "memory");
        __asm__("" : "=r"(moby) : "0"(moby) : "$4");
        removalTarget=moby;
        goto removeMoby;
    case 3:
        if ((D_8006E044 != 0xA) || (D_8006E048 == 0x81)) {
            goto saveSelected;
        }
loadSelectedRecord:
        /* Original stride is 12, including the halfword read at +14.
         * Coordinate halves are multiplied by four; rotation halves shift
         * right four before byte stores. Their source units are unresolved. */
        { register int index __asm__("$3");
          value=0x10010000;
          index=D_8006E1A0;
          __asm__("" : "=r"(value),"=r"(index) : "0"(value),"1"(index));
          value |= 0x8000;
          spyro.unk17a=value;
          value=index*3;
          record=Controller79F68Records;
          __asm__("" : "=r"(value),"=r"(record) : "0"(value),"1"(record));
          value*=4;
          record+=value; }
        spyro.unk19.x = *(unsigned short*)(record + 4) * 4;
        spyro.unk19.y = *(unsigned short*)(record + 6) * 4;
        spyro.unk19.z = *(unsigned short*)(record + 8) * 4;
        spyro.unk18.roll = (unsigned char) ((unsigned short) *(unsigned short*)(record + 0xA) >> 4);
        spyro.unk18.pitch = (unsigned char) ((unsigned short) *(unsigned short*)(record + 0xC) >> 4);
        value=*(unsigned short*)(record+0xE);
        __asm__("" : "=r"(value) : "0"(value) : "$3");
        { register int literal __asm__("$3")=17;
          __asm__("" : "=r"(literal) : "0"(literal));
          spyro.unk20[1]=literal; }
        __asm__ volatile("" : : : "memory");
        spyro.unk18.yaw=(unsigned int)value>>4;
        return;
saveSelected:
        func_8003B634(&savedData, &spyro.unk19, spyro.unk18.yaw);
        __asm__ volatile("" : : : "$5", "memory");
        D_8006E344 = 0;
        __asm__ volatile("" : : : "memory");
        __asm__("" : "=r"(moby) : "0"(moby) : "$4");
        removalTarget=moby;
        goto removeMoby;
    case 4:
        __asm__("" : "=r"(moby) : "0"(moby) : "$4");
        removalTarget=moby;
removeMoby:
        func_80055B18(removalTarget);
        return;
    }
}


typedef struct { Vector3D position; int reserved0C; } DecodedLaunchPoint;
typedef struct { short count; unsigned char reserved02[10]; DecodedLaunchPoint* points; } DecodedLaunchPath;
typedef struct { DecodedLaunchPath* path; Moby* spawned; int timer, speed, mobyClass; } DecodedPathLaunchTag;
typedef struct { Vector3D velocity; unsigned char reserved0C[8]; unsigned char active; } DecodedPathLaunchChildTag;
int DecodedPathLaunchTimer(void*,int) __asm__("func_800359A4");
int DecodedPathLaunchDistance(Vector3D*,Vector3D*) __asm__("func_8004F334");
int DecodedPathLaunchVertical(Vector3D*,Vector3D*,int,int,int*) __asm__("func_800365E4");
void func_level_32_8008A30C(Moby* moby) {
    register DecodedPathLaunchTag* tag __asm__("$18") = moby->mobyTag;
    register Moby* spawned __asm__("$19");
    register DecodedPathLaunchChildTag* child __asm__("$22");
    register int maximum __asm__("$20");
    register int index __asm__("$16");
    register int bestIndex __asm__("$17");
    int distance, angle;
    DecodedLaunchPath* path;
    /* Retail target is sp+0x18; the vertical helper output is sp+0x28. */
    struct {
        Vector3D target;
        int reserved24;
        int unknown;
        int reserved2C;
    } workspace;
    int retailStackAlignment[2];
    DecodedPathLaunchTimer(&tag->timer,4);
    if (tag->spawned) {
        if (tag->spawned->state == 1) {
            tag->spawned = 0;
            tag->timer = func_8003636C(0x3C,0x78);
        }
    } else if (!tag->timer) {
        spawned = SpawnMoby(tag->mobyClass,moby);
        if (spawned) {
            maximum = -1;
            __asm__("" : "=r"(spawned) : "0"(spawned));
            child = spawned->mobyTag;
            spawned->unknown5 = 1;
            spawned->lowDrawDistance = 0x26;
            spawned->highDrawDistance = 0x26;
            func_8003BABC(spawned,1,0);
            spawned->unknown |= 0x80000000;
            index = 0;
            bestIndex = 0;
            path = tag->path;
            if (path->count > 0) {
                do {
                    {
                    register Vector3D* origin __asm__("$4") = (Vector3D*)&spyro;
                    register unsigned int points __asm__("$2") = (unsigned int)path->points;
                    register int offset __asm__("$5") = index << 4;
                    __asm__("" : "=r"(points), "=r"(offset) : "0"(points), "1"(offset),"r"(origin));
                    distance = DecodedPathLaunchDistance(origin,(Vector3D*)(points + offset));
            }
                    if (maximum < distance) {
                        maximum = distance;
                        bestIndex = index;
                    }
                    path = tag->path;
                    index++;
                } while (index < path->count);
            }
            {
                    register DecodedLaunchPath* selectedPath __asm__("$2") = tag->path;
                    register Vector3D* origin __asm__("$4");
                    register unsigned int points __asm__("$2");
                    register int offset __asm__("$5");
                    __asm__("" : "=r"(selectedPath) : "0"(selectedPath) : "$4","$5");
                    origin = &workspace.target;
                    points = (unsigned int)selectedPath->points;
                    __asm__("" : "=r"(points) : "0"(points), "r"(origin) : "$5");
                    offset = bestIndex << 4;
                    __asm__("" : "=r"(points), "=r"(offset) : "0"(points), "1"(offset),"r"(origin));
                    func_8004F178(origin,(Vector3D*)(points + offset));
            }
            func_8004F178(&spawned->position,&moby->position);
            angle = func_8004E880(workspace.target.x - moby->position.x,workspace.target.y - moby->position.y,0);
            child->velocity.x = (D_80065920[angle] * tag->speed) >> 12;
            child->velocity.y = (D_800658A0[angle] * tag->speed) >> 12;
            child->velocity.z = 0;
            child->velocity.z = DecodedPathLaunchVertical(&spawned->position,&workspace.target,tag->speed,-10,&workspace.unknown);
            child->active = 1;
            spawned->state = 6;
            tag->spawned = spawned;
        }
    }
}

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
void func_level_32_8008A540(Moby* actor) {
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
void func_level_32_8008A7EC(void *input) {
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


extern unsigned char D_8006C7B4;
extern int D_8006C58C,D_8006E344;
extern int ControllerA918NormalX __asm__("D_80071918");
extern int ControllerA918NormalY __asm__("D_8007191C");
extern int ControllerA918NormalZ __asm__("D_80071920");
extern unsigned char ControllerA918Saved[] __asm__("D_80070300");
extern unsigned char ControllerA918Table[] __asm__("D_80066650");
extern unsigned char* ControllerA918Output __asm__("D_8006C530");
extern Moby* ControllerA918Hit __asm__("D_80071930");
int ControllerA918Helper80018368(Vector3D*,Vector3D*) __asm__("func_80018368");
void ControllerA918Helper8004ED6C(SHORTMATRIX*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void ControllerA918Helper8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void ControllerA918Helper8004F1FC(Vector3D*,Vector3D*,int) __asm__("func_8004F1FC");
void ControllerA918Helper8004F110(Vector3D*,int) __asm__("func_8004F110");
int ControllerA918Helper8004F284(int,int) __asm__("func_8004F284");
/* AI-generated; not human reviewed. Verified level11 A918 sibling with
 * original state1 owner byte +0x49 condition. Raw units, helper meanings
 * and cadence remain unresolved. Original differences: sibling3802. */
void func_level_32_8008AC7C(Moby *input) {
    register Moby* owner __asm__("$18")=input;
    Vector3D origin;
    Vector3D transformed;
    Vector3D direction;
    int sample;
    register int *phase __asm__("$20");
    int nextPhase;
    int nextHeight;
    register int byteOffset __asm__("$17");
    register int pointIndex __asm__("$19");
    register unsigned char *playerField __asm__("$17");
    register Vector3D* scratch __asm__("$16");
    register Vector3D* player __asm__("$16");
    unsigned char state;
    register int headingValue __asm__("$16");

    state = owner->state;
    phase = owner->mobyTag;
    switch (state) {
    case 0:
        { register int flags __asm__("$2")=D_8006C7B4;
        *phase = 0;
        if ((flags & 1) || (ControllerA918Saved[D_8006C58C] & 1)) {
            owner->state = 3;
            return;
        }
        }
        *(unsigned int*)&owner->colour = (owner->position.z & 0xFFFFFF) | 0x80000000;
        owner->position.z -= 0x800;
        *phase = -0x800;
        func_80055D24(owner, 2);
        owner->unknown3[0] = 0;
        owner->lowDrawDistance = 0;
        owner->drawn = 0;
        owner->state = 1;
        return;
    case 1:
        if (owner->substate != 0) {
            register int one __asm__("$2")=1;
            register int literal __asm__("$3");
            __asm__("" : "=r"(one) : "0"(one) : "$3");
            literal=42;
            __asm__("" : "=r"(one),"=r"(literal) : "0"(one),"1"(literal));
            owner->unknown3[0] = one;
            owner->drawn = one;
            owner->lowDrawDistance = literal;
            owner->state = 2;
            return;
        }
    default:
        return;
    case 2:
        owner->position.z += 0x40;
        nextHeight = *phase + 0x40;
        *phase = nextHeight;
        if (nextHeight >= 0) {
            owner->position.z -= nextHeight;
            *phase = 0;
            *(unsigned int*)&owner->colour = 0;
            owner->state = 3;
        }
        func_80055D24(owner, 2);
        return;
    case 3:
        ControllerA918Output[0x40]=16;
        func_8004F178(&origin, &owner->position);
        origin.z += 0x300;
        nextPhase = *phase + 0x10;
        *phase = nextPhase;
        if (nextPhase >= 0x101) {
            *phase = 0x100;
        }
        __asm__("" : : : "$19");
        pointIndex=0;
        scratch=&transformed;
        byteOffset=0;
        do {
            ControllerA918Helper8004ED6C(&owner->rotationMatrix, (Vector3D*)(ControllerA918Table+byteOffset), scratch);
            func_8004F194(scratch, scratch, &owner->position);
            ControllerA918Helper8004F1C8(scratch, scratch, &origin);
            { register Vector3D* first __asm__("$4")=scratch;
              register Vector3D* second __asm__("$5")=scratch;
              __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second));
              ControllerA918Helper8004F1FC(first,second,*phase); }
            pointIndex += 1;
            ControllerA918Helper8004F110(scratch, 8);
            func_8004F194((Vector3D*)(ControllerA918Output+byteOffset), scratch, &origin);
            byteOffset += 0xC;
        } while (pointIndex < 5);
        if (*phase >= 0x100) {
            owner->state = 4;
            return;
        }
        break;
    case 4:
        { register Vector3D* prepared __asm__("$4")=&owner->position;
          __asm__("" : "=r"(prepared) : "0"(prepared) : "$16");
        player=&spyro.position;
        if (func_8004F334(prepared, player) < 0x800) {
            if (func_8004F264((int) owner->angle.yaw, func_8004E880(spyro.position.x - owner->position.x, spyro.position.y - owner->position.y, 0)) < 0x41) {
                register int heading __asm__("$2")=owner->angle.yaw+128;
                __asm__("" : "=r"(heading) : "0"(heading));
                headingValue=heading&255;
            } else {
                headingValue = owner->angle.yaw;
            }
            playerField=&spyro.bodyRotation.yaw;
            if (func_8004F264((int) headingValue, (int) *playerField) < 0x1F) {
                register int index __asm__("$4")=headingValue*2;
                __asm__("" : "=r"(index) : "0"(index));
                direction.x=*(short*)((char*)D_80065920+index)/8;
                sample=*(short*)((char*)D_800658A0+index);
                scratch=&direction;
                if (sample < 0) {
                    sample += 7;
                }
                { register Vector3D* first __asm__("$4")=scratch;
                  register Vector3D* second __asm__("$5")=scratch;
                  __asm__("" : "=r"(first),"=r"(second),"=r"(playerField) : "0"(first),"1"(second),"2"(playerField));
                playerField-=0xE;
                direction.y = sample >> 3;
                direction.z = 0;
                func_8004F194(first,second,(Vector3D*)playerField); }
                if ((ControllerA918Helper80018368((Vector3D*)playerField,scratch) != 0) && (ControllerA918Hit == owner) && ((unsigned int) (ControllerA918NormalZ + 0x28) < 0x51U) && ((unsigned int) (ControllerA918Helper8004F284(func_8004E880(ControllerA918NormalX, ControllerA918NormalY, 1), owner->angle.yaw * 0x10) - 0x21) >= 0x7BFU)) {
                    func_80053F50(0);
                }
            }
        }
        }
        break;
    }
}

typedef struct { int timer, reserved04; short firstFrame, lastFrame; int linkedIndex; } DecodedTimedPickupTag;
extern int D_8006FA80;
extern Moby* D_8006C550;
extern unsigned short DecodedTimedPickupYaw __asm__("D_8006E040");
extern unsigned short DecodedTimedPickupPitch __asm__("D_8006E03E");
extern int (*DecodedTimedPickupQuery)(Moby*,Vector3D*,int) __asm__("unk_ovlheader_800743A0");
int DecodedTimedPickupTimer(void*,int) __asm__("func_800359A4");
void func_level_32_8008B06C(Moby* moby) {
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
            linked = (unsigned short*)((char*)D_8006C550[tag->linkedIndex].mobyTag + 0x134);
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 family:
 * level25 8007ACBC, level35 80079A70, level45 80079BE0.692 original
 * instructions and7 state targets plus padding per member. Evidence4863/64.
 * Raw widths/units/helper meanings/cadence unresolved; original linked words
 * and full retail hashes required before acceptance. Verified34 C reused. */
extern int F4874Gate __asm__("D_8006FA3C"),F4874Position __asm__("D_8006FA80"),F4874Mode __asm__("D_8006E044");
extern unsigned short F4874E040 __asm__("D_8006E040"),F4874E03E __asm__("D_8006E03E");
extern unsigned char F4874PlayerE __asm__("D_80070328 + 0xE"),F4874Player12 __asm__("D_80070328 + 0x12"),F4874PlayerD __asm__("D_80070328 + 0xD");
extern unsigned char F4874Player[] __asm__("D_80070328");
extern unsigned char* F4874Array __asm__("D_8006C550"),*F4874ArrayEnd __asm__("D_8006C704");
extern int F4874W20C __asm__("D_80070328 + 0x20C"),F4874W170 __asm__("D_80070328 + 0x170");
extern void* F4874W218 __asm__("D_80070328 + 0x218");
extern int (*F4874CallbackA0)() __asm__("unk_ovlheader_800743A0");
extern int (*F4874Callback24)() __asm__("unk_ovlheader_80074324");
int F4874func_80049484() __asm__("func_80049484");
void* F4874func_8002F540() __asm__("func_8002F540");
int F4874rand() __asm__("rand");
#define F4874Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int F4874func_80013E38() __asm__("func_80013E38");
int F4874func_8001830C() __asm__("func_8001830C");
int F4874func_80018368() __asm__("func_80018368");
void *F4874func_8001BA30() __asm__("func_8001BA30");
int F4874func_800359A4() __asm__("func_800359A4");
int F4874func_8003BABC() __asm__("func_8003BABC");
int F4874func_8003BE70() __asm__("func_8003BE70");
int F4874func_8003BFC0() __asm__("func_8003BFC0");
int F4874func_8003C0B0() __asm__("func_8003C0B0");
int F4874func_80040954() __asm__("func_80040954");
int F4874func_8004E880() __asm__("func_8004E880");
int F4874func_8004ED6C() __asm__("func_8004ED6C");
int F4874func_8004EDE8() __asm__("func_8004EDE8");
int F4874func_8004F0E8() __asm__("func_8004F0E8");
int F4874func_8004F110() __asm__("func_8004F110");
int F4874func_8004F178() __asm__("func_8004F178");
int F4874func_8004F194() __asm__("func_8004F194");
int F4874func_8004F1C8() __asm__("func_8004F1C8");
int F4874func_8004F334() __asm__("func_8004F334");
int F4874func_80055B18() __asm__("func_80055B18");
int F4874func_80055D24() __asm__("func_80055D24");
extern unsigned char F4874D_800658A0[] __asm__("D_800658A0");
extern unsigned char F4874D_80065920[] __asm__("D_80065920");
extern int F4874D_8006C574 __asm__("D_8006C574");
extern int F4874D_8006C578 __asm__("D_8006C578");
extern unsigned char F4874D_8006D048[] __asm__("D_8006D048");
extern void *F4874D_8006E788 __asm__("D_8006E788");
extern int F4874D_80071924 __asm__("D_80071924");
extern void *(*F4874SpawnMoby)() __asm__("SpawnMoby");
extern int (*F4874SpawnParticle)() __asm__("SpawnParticle");
void func_level_32_8008B27C(void *arg0) {
    register void *owner __asm__("$19");
    register short *signedTable65920 __asm__("$23");
    register short *signedTable658A0 __asm__("$22");
    register short *temp_a2 __asm__("$6");
    register int tableIndex4 __asm__("$4");
    register int tableIndex5 __asm__("$5");
    register short *tablePointer2 __asm__("$2");
    register short *tablePointer4 __asm__("$4");
    register short *tablePointer5 __asm__("$5");
    int tableProduct2;
    int signedDivision180Magic;
    register int tableHalfword3 __asm__("$3");
    int temp_v0_4;
    register int previousHalfword08 __asm__("$7");
    register void *stackArg4 __asm__("$4");
    register int phaseByte3 __asm__("$3");
    register int initWord2 __asm__("$2");
    register int halfword3 __asm__("$3");
    register int result2 __asm__("$2");
    register int work3 __asm__("$3");
    register int *vector38 __asm__("$18");
    register int *savedVector28 __asm__("$16");
    register int *globalWordAddress16 __asm__("$16");
    register int previousHalfword06 __asm__("$3");
    register int updatedHalfword06 __asm__("$2");
    register int *savedOwnerVector0C __asm__("$17");
    register int *temp_s1_3 __asm__("$17");
    register int *ownerVectorArgument __asm__("$18");
    int ownerWord10;
    int temp_a0_3;
    int ownerWord0C;
    int temp_a1_3;
    register int combinedScore __asm__("$17");
    int temp_v0_5;
    int distanceScore;
    int ownerWord14;
    register int wrappedDifference08 __asm__("$6");
    register int wrappedDifference06 __asm__("$6");
    int bestScore;
    struct { int sp18; int sp1C; int sp20; int sp24; int sp28; int sp2C; int sp30; int sp34; int sp38; int sp3C; int sp40; int sp44; int sp48; int sp4C; int sp50; int sp54; int sp58; int sp5C; int sp60; int sp64; int sp68; int sp6C; int sp70; int sp74; int sp78; int sp7C; int sp80; int sp84; } frame;
    register int wrappedDifference45 __asm__("$16");
    register int upperStep __asm__("$16");
    register int scaledWord16 __asm__("$16");
    register int absoluteDistanceScore __asm__("$17");
    register int lowerStep __asm__("$17");
    register int var_s1_3 __asm__("$17");
    register int wrappedDifference46 __asm__("$18");
    register int var_s2_2 __asm__("$18");
    register int absoluteDifference08 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int absoluteDifference06 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    unsigned char ownerState48;
    register unsigned char* scanPosition __asm__("$20");
    void *temp_a0_2;
    void *linkedObject00;
    register void *privateState __asm__("$21");
    register void *ownerVector0C __asm__("$23");
    register void *queriedObject __asm__("$17");
    register void *temp_v0_2 __asm__("$16");
    register void *temp_v0_3 __asm__("$16");
    void *temp_v1_6;
    register void *scannedObject __asm__("$22");

    owner = arg0;
    ownerState48 = F4874Field(owner, unsigned char *, 0x48);
    privateState = F4874Field(owner, void **, 0);
    switch (ownerState48) {

    case 0:
        temp_v0_2=F4874Field(owner,void**,0);
        result2=F4874Field(temp_v0_2,short*,0x14);
        if(result2){
            tableIndex4=F4874Field(temp_v0_2,short*,0x16);
            if(tableIndex4){
                work3=F4874Position;
                if(result2>=work3)goto outside0;result2=work3<tableIndex4;work3=1;if(!result2)goto outside0;{F4874Field(owner,unsigned char*,0x41)=0;F4874Field(owner,unsigned char*,0x4C)=0;F4874Field(owner,unsigned char*,0x4D)=0;}
                goto afterFlags0;outside0:work3=1;result2=63;{F4874Field(owner,unsigned char*,0x41)=work3;F4874Field(owner,unsigned char*,0x4C)=result2;F4874Field(owner,unsigned char*,0x4D)=work3;}afterFlags0:;
            }
        }
        result2=F4874E040;result2=((int)((unsigned)result2<<16)>>20)-128;F4874Field(owner,unsigned char*,0x46)=result2;
        result2=F4874E03E;F4874Field(owner,unsigned char*,0x45)=(unsigned)result2>>4;
        {register unsigned char* child4 __asm__("$4");
         child4=F4874Field(temp_v0_2,unsigned char**,0);
         if(!child4){F4874Field(temp_v0_2,void**,0)=F4874SpawnMoby(364,owner);return;}
         if(child4[72]!=4){F4874Field(temp_v0_2,int*,16)=30;F4874Field(temp_v0_2,void**,0)=0;F4874Field(owner,unsigned char*,72)=6;return;}
         child4[70]=F4874Field(owner,unsigned char*,70)+128;
         result2=F4874Field(owner,unsigned char*,69);work3=(int)F4874Field(temp_v0_2,void**,0);F4874Field((void*)work3,unsigned char*,69)=-result2;return;
        }
    case 1:
        F4874Field(owner,unsigned char*,76)=0;F4874Field(owner,unsigned char*,77)=0;
        F4874func_8004F178(owner+12,F4874Player);return;
    case 2:
        F4874Field(owner,unsigned char*,76)=63;F4874func_80049484(owner+12);
        result2=F4874PlayerE;work3=F4874Player12;F4874Field(owner,unsigned char*,70)=result2+work3;
        if(F4874Mode==7){result2=F4874E03E;result2=-((int)((unsigned)result2<<16)>>20);F4874Field(owner,unsigned char*,69)=result2;result2=F4874E040;F4874Field(owner,unsigned char*,70)=(unsigned)result2>>4;}
        else F4874Field(owner,unsigned char*,69)=F4874PlayerD;
        bestScore=0x10000;__asm__("" : "=r"(bestScore):"0"(bestScore));
        scannedObject=F4874Array;result2=(unsigned)scannedObject<(unsigned)F4874ArrayEnd;__asm__("" ::: "memory");bestScore |= 0x869F;
        F4874Field(privateState, void **, 0) = 0;
        if (result2) {
            ownerVector0C = owner + 0xC;
            scanPosition=scannedObject+12;
            do {
                work3=F4874Field(scanPosition,short*,0x2A);
                if(work3==0x75 || work3==0x9B || work3==0x48 || work3==0xC8)goto nextScanned;
                if(work3==0x67 && F4874Field(scanPosition,unsigned char*,0x3C)!=0x15)goto nextScanned;
                if (!(F4874Field(scanPosition, unsigned char *, 0x3C) & 0x80) && (F4874Field(scanPosition, int *, -4) != 0)) {
                    F4874func_8004F178(&frame.sp18, scanPosition);
                    frame.sp20 += 0x80;
                    wrappedDifference46 = (F4874func_8004E880(frame.sp18 - F4874Field(owner, int *, 0xC), frame.sp1C - F4874Field(owner, int *, 0x10), 0) - F4874Field(owner, unsigned char *, 0x46)) & 0xFF;
                    if (wrappedDifference46 >= 0x81) {
                        wrappedDifference46 -= 0x100;
                    }
                    wrappedDifference45 = (F4874func_8004E880(F4874func_8004F334(ownerVector0C, &frame.sp18), frame.sp20 - F4874Field(owner, int *, 0x14), 0) - F4874Field(owner, unsigned char *, 0x45)) & 0xFF;
                    if (wrappedDifference45 >= 0x81) {
                        wrappedDifference45 -= 0x100;
                    }
                    if (wrappedDifference46 < 0) {
                        wrappedDifference46 = -wrappedDifference46;
                    }
                    if (wrappedDifference45 < 0) {
                        wrappedDifference45 = -wrappedDifference45;
                    }
                    __asm__("" : "=r"(wrappedDifference46) : "0"(wrappedDifference46));
                    if ((wrappedDifference46 < 0x30) && (wrappedDifference45 < 0x30)) {
                        distanceScore = 0x2800 - F4874func_8004F334(ownerVector0C, &frame.sp18);
                        absoluteDistanceScore = distanceScore;
                        if (distanceScore < 0) {
                            absoluteDistanceScore = -absoluteDistanceScore;
                        }
                        result2 = (wrappedDifference46 + wrappedDifference45) << 10;
                        __asm__("" : "=r"(result2) : "0"(result2));
                        combinedScore = absoluteDistanceScore + result2;
                        if ((combinedScore < bestScore) && (F4874func_80013E38(ownerVector0C, &frame.sp18, 4) != 0)) {
                            F4874Field(privateState, void **, 0) = scannedObject;
                            bestScore = combinedScore;
                        }
                    }
                }
                nextScanned:result2=(int)F4874ArrayEnd;scannedObject+=88;result2=(unsigned)scannedObject<(unsigned)result2;scanPosition+=88;
            } while (result2);
        }
        if (bestScore == 0x1869F) {
            F4874Field(privateState, void **, 0) = 0;
        }
        initWord2 = F4874Field(owner, unsigned char *, 0x44) << 4;
        __asm__("" : "=r"(initWord2) : "0"(initWord2));
        F4874Field(privateState, short *, 4) = initWord2;
        initWord2 = F4874Field(owner, unsigned char *, 0x45) << 4;
        __asm__("" : "=r"(initWord2) : "0"(initWord2));
        F4874Field(privateState, short *, 6) = initWord2;
        phaseByte3 = F4874Field(owner, unsigned char *, 0x46);
        initWord2 = 0xB4;
        F4874Field(privateState, short *, 0xE) = initWord2;
        initWord2 = -1;
        F4874Field(privateState, int *, 0x10) = initWord2;
        __asm__("" : : : "memory");
        initWord2 = 3;
        F4874Field(privateState, short *, 0xA) = 0;
        F4874Field(privateState, short *, 0xC) = 0;
        F4874Field(privateState, short *, 8) = phaseByte3 << 4;
        F4874Field(owner, unsigned char *, 0x48) = initWord2;
    case 3:
        if(F4874Field(owner,int*,12)<1024 || F4874Field(owner,int*,16)<1024 || F4874Field(owner,int*,20)<1024 || ((result2=F4874func_800359A4(privateState+14,2)),(stackArg4=&frame.sp28),result2)) {
            if (F4874func_8003BFC0(owner, F4874Field(privateState, int *, 0x10)) != 0) {
                F4874func_8003BE70(F4874Field(privateState, int *, 0x10));
            }
            goto block_93;
        }
        __asm__("" : "=r"(owner) : "0"(owner));
        savedOwnerVector0C = owner + 0xC;
        F4874func_8004F178(stackArg4, savedOwnerVector0C);
        if (F4874Field(F4874Field(privateState, void **, 0), unsigned char *, 0x48) & 0x80) {
            F4874Field(privateState, void **, 0) = 0;
        }
        linkedObject00 = F4874Field(privateState, void **, 0);
        if (linkedObject00 != 0) {
            F4874func_8004F178(&frame.sp48, linkedObject00 + 0xC);
            frame.sp50 += 0x80;
            vector38 = &frame.sp38;
            F4874func_8004F1C8(vector38, &frame.sp48, savedOwnerVector0C);
            frame.sp40 += 0x100;
            F4874func_8004E880(frame.sp38, frame.sp3C, 1);
            result2 = F4874func_8004E880(frame.sp38, frame.sp3C, 1);
            halfword3 = F4874Field(privateState, short *, 8);
            wrappedDifference08 = (result2 - halfword3) & 0xFFF;
            previousHalfword08 = halfword3;
            if (wrappedDifference08 >= 0x801) {
                wrappedDifference08 -= 0x1000;
            }
            absoluteDifference08 = wrappedDifference08;
            if (wrappedDifference08 < 0) {
                absoluteDifference08 = -absoluteDifference08;
            }
            if (absoluteDifference08 < 0x400) {
                work3 = 0xBE;
                result2 = F4874Field(privateState, short *, 0xE);
                upperStep = work3-result2;
                lowerStep = -upperStep;
                if (upperStep >= 65) {
                    upperStep = 64;
                    __asm__("" : "=r"(upperStep) : "0"(upperStep));
                    lowerStep = -upperStep;
                }
                if (wrappedDifference08 < lowerStep) wrappedDifference08 = lowerStep;
                if (upperStep < wrappedDifference08) wrappedDifference08 = upperStep;
                F4874Field(privateState, short *, 8) = (short) (previousHalfword08 + wrappedDifference08);
                result2 = F4874func_8004EDE8(vector38, 0, wrappedDifference08, previousHalfword08);
                result2 = F4874func_8004E880(result2, frame.sp40, 1);
                previousHalfword06 = F4874Field(privateState, short *, 6);
                wrappedDifference06 = (result2 - previousHalfword06) & 0xFFF;
                if (wrappedDifference06 >= 0x801) {
                    wrappedDifference06 -= 0x1000;
                }
                absoluteDifference06 = wrappedDifference06;
                if (wrappedDifference06 < 0) {
                    absoluteDifference06 = -absoluteDifference06;
                }
                if (absoluteDifference06 < 0x400) {
                    if (wrappedDifference06 < lowerStep) wrappedDifference06 = lowerStep;
                    if (upperStep < wrappedDifference06) wrappedDifference06 = upperStep;
                    updatedHalfword06 = previousHalfword06 + wrappedDifference06;
                    F4874Field(privateState, short *, 6) = updatedHalfword06;
                } else {
                    goto block_63;
                }
            } else {
block_63:
                F4874Field(privateState, void **, 0) = 0;
            }
        }
        F4874Field(owner, unsigned char *, 0x44) = (unsigned char) ((unsigned short) F4874Field(privateState, unsigned short *, 4) >> 4);
        F4874Field(owner, unsigned char *, 0x45) = (unsigned char) ((unsigned short) F4874Field(privateState, short *, 6) >> 4);
        F4874Field(owner, unsigned char *, 0x46) = (unsigned char) ((unsigned short) F4874Field(privateState, short *, 8) >> 4);
        F4874func_80055D24(owner, 4);
        frame.sp38 = 0x300;
        frame.sp3C = 0;
        frame.sp40 = 0;
        F4874func_8004ED6C(owner + 0x20, &frame.sp38, &frame.sp38);
        ownerVectorArgument = owner + 0xC;
        F4874func_8004F194(ownerVectorArgument, ownerVectorArgument, &frame.sp38);
        savedVector28 = &frame.sp28;
        if (F4874func_8001830C(savedVector28, ownerVectorArgument, 0, 0x10000, owner) != 0) {
            F4874func_8004F178(ownerVectorArgument, savedVector28);
            goto block_71;
        }
        queriedObject = F4874func_8001BA30(ownerVectorArgument, 0x200, 1, 0, 0, owner);
        if (queriedObject != 0) {
            F4874func_8004F178(&frame.sp58, queriedObject + 0xC);
            frame.sp60 += 0x80;
            if (F4874func_80018368(ownerVectorArgument, &frame.sp58) == 0) {
                result2=0x10000;work3=F4874Field(queriedObject,int*,0x18);stackArg4=(void*)(work3|result2);__asm__("" : "=r"(stackArg4):"0"(stackArg4));
                work3=F4874Field(queriedObject,short*,0x36);
                F4874Field(queriedObject,int*,0x18)=(int)stackArg4;
                if(work3==0x67){result2=(int)stackArg4|0x100000;__asm__("" : "=r"(result2):"0"(result2));F4874Field(queriedObject,int*,0x18)=result2;}
block_71:
                F4874Field(owner, unsigned char *, 0x48) = 5U;
            }
        }
        if (F4874func_8003BFC0(owner, F4874Field(privateState, int *, 0x10)) == 0) {
            F4874Field(privateState, int *, 0x10) = F4874func_8003BABC(owner, 0, 4);
        } else {
            /* Keep the original division constant before the signed load. */
            signedDivision180Magic = (int)0xB60B60B7;
            __asm__("" : "=r"(privateState) : "0"(privateState), "r"(signedDivision180Magic));
            halfword3 = F4874Field(privateState, short *, 0xE);
            result2 = (int)((unsigned int)(0xB4 - halfword3) << 13);
            work3 = result2 / 180;
            __asm__("" : "=r"(work3) : "0"(work3));
            result2 = 0x1000;
            __asm__("" : "=r"(result2) : "0"(result2));
            scaledWord16 = result2 - work3;
            if (scaledWord16 < 0xA00) {
                scaledWord16 = 0xA00;
            }
            F4874func_8003C0B0(F4874Field(privateState, int *, 0x10), scaledWord16);
        }
        F4874func_8004F110(&frame.sp38, 2);
        F4874SpawnParticle(1, 0x37, owner + 0xC, &frame.sp38);
        return;

    case 4:
        result2=F4874Field(owner,unsigned char*,58);
        work3=result2*88;result2=(int)F4874Array;result2+=work3;__asm__("" : "=r"(result2):"0"(result2));result2=F4874Field((void*)result2,unsigned char*,76);
        globalWordAddress16=&frame.sp68;
        if(result2){
            stackArg4=globalWordAddress16;__asm__("" : "=r"(stackArg4):"0"(stackArg4));temp_s1_3=(int*)F4874Player;
            F4874Field(owner,unsigned char*,76)=result2;
            F4874func_8004F1C8(stackArg4,temp_s1_3,owner+12);
            F4874func_8004EDE8(globalWordAddress16,1);
            if(F4874W20C&0x10000000)return;
            if(F4874W170)return;
            F4874Field(owner,unsigned char*,0x4F)=0x18;
            if(!F4874CallbackA0(owner,temp_s1_3,0x672))return;
            F4874func_8003BABC(owner,2,0);
            result2=0x10001000;F4874W20C=result2;result2=1;F4874W218=owner;F4874Field(owner,unsigned char*,72)=result2;return;
        }
        idle6:__asm__ volatile("" ::: "memory");F4874Field(owner,unsigned char*,65)=0;F4874Field(owner,unsigned char*,76)=0;F4874Field(owner,unsigned char*,77)=0;return;
    case 5:
        temp_s1_3=owner+12;
        temp_v0_2=F4874func_8001BA30(temp_s1_3,1024,1,0,0,owner);
        if(temp_v0_2 && !F4874func_80018368(temp_s1_3,temp_v0_2+12))F4874Field(temp_v0_2,int*,24)|=0x10000;
        if(F4874func_8003BFC0(owner,F4874Field(privateState,int*,16)))F4874func_8003BE70(F4874Field(privateState,int*,16));
        F4874func_8003BABC(owner,1,0);F4874Callback24(owner,-1);removeOwner:F4874func_80055B18(owner);return;
    case 6:
        temp_v0_2=F4874Field(owner,void**,0);
        result2=F4874E040;result2=((int)((unsigned)result2<<16)>>20)-128;F4874Field(owner,unsigned char*,70)=result2;
        result2=F4874E03E;F4874Field(owner,unsigned char*,69)=(unsigned)result2>>4;
        if(F4874func_800359A4(temp_v0_2+16,4)){
            var_s1_3=0;stackArg4=temp_v0_2;__asm__("" : "=r"(stackArg4):"0"(stackArg4));do{F4874Field(F4874Field(stackArg4,void**,4),unsigned char*,28)=0;F4874Field(stackArg4,void**,4)=0;var_s1_3++;stackArg4+=4;}while(var_s1_3<3);
            F4874Field(owner,unsigned char*,72)=0;return;
        }
        var_s2_2=F4874rand()&255;scanPosition=F4874D_80065920;var_s1_3=0;
        do{
            if(!F4874Field(temp_v0_2,void**,4)){
                result2=(int)F4874func_8002F540(4,1,0x608080);__asm__("" : "=r"(result2):"0"(result2));F4874Field(temp_v0_2,void**,4)=(void*)result2;
                if(!result2)goto angleIncrement;{
                    F4874Field((void*)result2,int*,0)=0;
                    tableIndex4=var_s2_2*2;tablePointer2=(short*)((long)tableIndex4+(long)scanPosition);tableHalfword3=*tablePointer2;__asm__("" : "=r"(tableHalfword3):"0"(tableHalfword3));result2=tableHalfword3*3;__asm__("" : "=r"(result2):"0"(result2));
                    work3=(int)F4874Field(temp_v0_2,void**,4);result2>>=3;F4874Field((void*)work3,int*,4)=result2;
                    tableHalfword3=F4874Field(F4874D_800658A0+tableIndex4,short*,0);__asm__("" : "=r"(tableHalfword3):"0"(tableHalfword3));result2=tableHalfword3*3;__asm__("" : "=r"(result2):"0"(result2));
                    work3=(int)F4874Field(temp_v0_2,void**,4);result2>>=3;F4874Field((void*)work3,int*,8)=result2;
                    linkedObject00=F4874Field(temp_v0_2,void**,4);F4874func_8004ED6C(owner+32,linkedObject00,linkedObject00);
                    stackArg4=F4874Field(temp_v0_2,void**,4);F4874func_8004F194(stackArg4,stackArg4,owner+12);
                }
            }
            if(F4874Field(temp_v0_2,void**,4))F4874func_8004F178(F4874Field(temp_v0_2,unsigned char**,4)+12,F4874Player);
            angleIncrement:result2=var_s2_2+85;__asm__("" : "=r"(result2):"0"(result2));var_s2_2=result2&255;var_s1_3++;temp_v0_2+=4;
        }while(var_s1_3<3);
    }
    return;
block_93:
    goto removeOwner;
}
#undef F4874Field


typedef struct { int actorIndex; Vector3D position; int timer; int* counter; } DecodedLinkedActor;
extern Moby* D_8006C550;
extern int D_8006C79C,D_8006C58C;
extern int D_80071AB0[][8];

extern Moby* DecodedActorCallback(Moby*,int,Vector3D*,Vector3D*) __asm__("func_80036A68");
int func_8001A358(Vector3D*,int);
void func_level_32_8008BD98(Moby* moby) {
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
void func_level_32_8008C0C8(Moby* actor) {
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

typedef struct {
    int verticalLimit, radialLimit, selector;
    int timer, soundHandle, linkedIndex;
} DecodedProximityTag;
extern unsigned char DecodedProximityPlayer[] __asm__("D_80070328");
extern int DecodedProximityAnimation __asm__("D_80070328 + 0x48");
extern int DecodedProximityZ __asm__("D_80070328 + 8");
extern int DecodedProximityDisabled __asm__("D_80070328 + 0x244");
extern int DecodedProximityRequest __asm__("D_80070328 + 0x20C");
extern Moby* DecodedProximityOwner __asm__("D_80070328 + 0x218");
extern unsigned char* DecodedProximitySounds __asm__("D_8006C654");
extern unsigned char D_8006C7B4, D_80070300[];
extern int D_8006C58C, D_8006C640, D_8006E344;
extern Moby* D_8006C550;
extern void* (*DecodedProximityParticle)(int,int,Moby*,void*) __asm__("SpawnParticle");
int func_8004F334(Vector3D*,Vector3D*);
/* USA SCUS-94467 Rev 0: representative level11
 * 0x8007B388..0x8007B8B0, 330 words; per-copy source identity in batch1376.
 * Retain raw selector bits, states/substates, signed distance/height comparisons,
 * timer helper argument4, sound-table byte0x1D and particle IDs6/0x52.
 * Coordinates and helper results retain their retail arithmetic representation;
 * physical units, cadence and complete producer/helper semantic chains are open.
 * Particle and sound payload/event meanings are not inferred from IDs or names.
 * Empty constraints retain original register lifetimes and emit no instructions.
 * AI generated; not yet human reviewed.
 */
void func_level_32_8008C2D4(Moby* argument) {
    Vector3D difference;
    int kind;
    register Moby* moby __asm__("$17") = argument;
    register DecodedProximityTag* tag __asm__("$18");
    register Vector3D* position __asm__("$19");
    register int two __asm__("$20");
    register int* playerMode __asm__("$21") = (int*)(DecodedProximityPlayer + 0x50);
    register int distance __asm__("$22");
    register Vector3D* playerPosition __asm__("$23");
    __asm__("" : "=r"(moby) : "0"(moby));
    __asm__("" : "=r"(playerMode) : "0"(playerMode));
    tag = moby->mobyTag;
    if (*playerMode == 6 || DecodedProximityDisabled) {
        if (moby->state) moby->state = 2;
        return;
    }
    two = 2;
    __asm__("" : "=r"(two) : "0"(two));
    if (moby->state == two) moby->state = 1;
    playerPosition = (Vector3D*)((char*)playerMode - 0x50);
    kind = tag->selector & 0x7F;
    position = &moby->position;
    func_8004F1C8(&difference, playerPosition, position);
    distance = func_8004EDE8(&difference, 0);
    /* Shared state transitions preserve the original dispatch/jump structure. */
    if (!kind) goto activate;
    {
        register int one __asm__("$4") = 1;
        register int substate __asm__("$3");
        register int condition __asm__("$2");
        __asm__("" : "=r"(one) : "0"(one));
        if (kind == one) {
            substate = moby->substate;
            if (substate == kind) goto kindOneWaiting;
            if (substate < 2) {
                if (!substate) goto kindOneInitial;
                goto update;
            }
            if (substate == two) goto kindOneActive;
            if (substate == 3) goto kindOneFinished;
            goto update;
        kindOneInitial:
            if (distance < tag->radialLimit + 0x400 && ABS(difference.z) < 0x400) {
                tag->timer = 60;
                moby->substate = 1;
            }
            goto update;
        kindOneWaiting:
            if (!func_800359A4(&tag->timer, 4)) goto update;
            goto secondSubstate;
        kindOneActive:
            if (DecodedProximityAnimation != 19) goto update;
            goto thirdSubstate;
        kindOneFinished:
            if (DecodedProximityAnimation != 19 && func_800359A4(&tag->timer, 4)) {
                moby->substate = 0;
                moby->state = 0;
            }
            goto update;
        } else if (kind == 3) {
            substate = moby->substate;
            if (substate == one) goto kindThreeWaiting;
            if (substate < 2) {
                if (!substate) goto kindThreeInitial;
                goto update;
            }
            if (substate == two) goto kindThreeActive;
            if (substate == kind) goto kindThreeFinished;
            goto update;
        kindThreeInitial:
            if (distance <= tag->radialLimit + 0x800 || distance >= 0x2000) goto update;
            condition = ABS(difference.z) < 0x400;
            goto checkSecond;
        kindThreeWaiting:
            condition = distance > tag->radialLimit + 0x800;
        checkSecond:
            if (!condition) goto update;
        timedSecond:
            tag->timer = 60;
        secondSubstate:
            moby->substate = 2;
        activate:
            moby->state = 1;
            goto update;
        kindThreeActive:
            if (DecodedProximityAnimation != 19 && distance <= 0x2800 && DecodedProximityZ - moby->position.z <= 0xC00) goto update;
        thirdSubstate:
            tag->timer = 60;
            moby->substate = 3;
            goto update;
        kindThreeFinished:
            if (playerMode[-2] != 19 && func_800359A4(&tag->timer, 4)) {
                moby->substate = 0;
                moby->state = 0;
            }
            goto update;
        }
    }
    if (kind == 4) {
        if ((D_8006C7B4 & 1) || (D_80070300[D_8006C58C] & 1)) {
            if (func_8004F334(position, playerPosition) > 0x800 && D_8006C640 > 0) goto clearKind;
        }
    } else if (kind == 5) {
        if (tag->linkedIndex != -1 && D_8006C550[tag->linkedIndex].state >= 0x80) goto clearKind;
    }
    goto update;
clearKind:
    tag->selector &= 0x80;
update:
    /* Active/inactive sound-handle paths and both callbacks retain retail order. */
    __asm__("" : : "r"(two));
    if (moby->state) {
        if (!func_8003BFC0(moby, tag->soundHandle)) tag->soundHandle = PlaySound(DecodedProximitySounds[0x1D], moby, 4);
        if (!(D_8006C640 & 1)) DecodedProximityParticle(1, 6, moby, 0);
        DecodedProximityParticle(1, 0x52, moby, 0);
        if (DecodedProximityAnimation != 19 && distance < tag->radialLimit && !D_8006E344
            && difference.z >= -0x3FF && difference.z < tag->verticalLimit
            && DecodedProximityZ + 0xC00 < moby->position.z + tag->verticalLimit) {
            DecodedProximityRequest = 0x10000020;
            DecodedProximityOwner = moby;
            __asm__("" : : "r"(tag), "r"(distance));
        }
    } else {
        if (func_8003BFC0(moby, tag->soundHandle)) {
            func_8003BE70(tag->soundHandle);
            tag->soundHandle = -1;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008C7FC.
* Assembly SHA256 ace0e940778d978c3e6065df9a7b94af9f83606c9c92dc6db9b2120b9b2208b8.
* AI generated; not human reviewed. All891 instructions,
* six selector words and actual targets are required. Original frame0x80
* retains all original saved words and full SP18..67 local extent.
* The823 base has independently decoded891/922 deltas:the original68-word
* insertion and2440 global literal in891;initialized S5,timer/two36220 calls,
* original2000 global literal and hook arguments in922. No target identity
* follows from similarity alone. Full target-native/control/data gates apply.
* Sequential S0 angle roles copy the first value to A0 before overwriting S0.
* Signed input/clamps,word handles at+15C,stored halfword handles followed by
* original SLL/SRA into A0,and complete low products preserve their domains.
* Stack source bases change from S0/SP38 to S0/SP58;the independent S3/SP48
* source remains separate. The first collision has two physical entries:
* one initializes A0 and the other retains its already prepared value.
* Shared countdown/state3 exit and three hook joins preserve actual targets.
* Empty initialized identities,late consumers,dead clobbers and compiler
* memory barriers emit zero CPU instructions. No opcode assembly,partialHI,
* FP shortcut or live-alias overlap. Confidence is binary identity after
* all gates. Raw units/fixed point,complete helper contracts,caller cadence
* and synchronized retail runtime remain open. Cadence is per invocation.
* Falsification:every native/linked word,actual transfer/table target,owned
* data byte,EXE and every overlay retail hash. */
#define Actor32_8C7FCField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Actor32_8C7FCCall18368View1() __asm__("func_80018368");
int Actor32_8C7FCCall19194View1() __asm__("func_80019194");
int Actor32_8C7FCCall1BA30View1() __asm__("func_8001BA30");
int Actor32_8C7FCCall1C288View1() __asm__("func_8001C288");
int Actor32_8C7FCCall34F80View1() __asm__("func_80034F80");
int Actor32_8C7FCCall359A4View1() __asm__("func_800359A4");
int Actor32_8C7FCCall369B8View1() __asm__("func_800369B8");
int Actor32_8C7FCCall3BABCView1() __asm__("func_8003BABC");
int Actor32_8C7FCCall3BE70View1() __asm__("func_8003BE70");
int Actor32_8C7FCCall3BFC0View1() __asm__("func_8003BFC0");
int Actor32_8C7FCCall3C0B0View1() __asm__("func_8003C0B0");
int Actor32_8C7FCCall3C140View1() __asm__("func_8003C140");
int Actor32_8C7FCCall4E880View1() __asm__("func_8004E880");
int Actor32_8C7FCCall4ED6CView1() __asm__("func_8004ED6C");
int Actor32_8C7FCCall4EDE8View1() __asm__("func_8004EDE8");
int Actor32_8C7FCCall4EF74View1() __asm__("func_8004EF74");
int Actor32_8C7FCCall4F168View1() __asm__("func_8004F168");
int Actor32_8C7FCCall4F178View1() __asm__("func_8004F178");
int Actor32_8C7FCCall4F194View1() __asm__("func_8004F194");
int Actor32_8C7FCCall4F1C8View1() __asm__("func_8004F1C8");
int Actor32_8C7FCCall4F284View1() __asm__("func_8004F284");
int Actor32_8C7FCCall4F334View1() __asm__("func_8004F334");
int Actor32_8C7FCCall55D24View1() __asm__("func_80055D24");
int Actor32_8C7FCCall55F14View1() __asm__("func_80055F14");
extern int Actor32_8C7FCData658A0View1 __asm__("D_800658A0");
extern int Actor32_8C7FCData65920View1 __asm__("D_80065920");
extern int Actor32_8C7FCData6C550View1 __asm__("D_8006C550");
extern int Actor32_8C7FCData6C700View1 __asm__("D_8006C700");
extern short Actor32_8C7FCData6E03EView1 __asm__("D_8006E03E");
extern short Actor32_8C7FCData6E040View1 __asm__("D_8006E040");
extern int Actor32_8C7FCData70328View1 __asm__("D_80070328");
extern int Actor32_8C7FCData71918View1 __asm__("D_80071918");
extern int Actor32_8C7FCDatag_CheatFlagsView1 __asm__("g_CheatFlags");
extern void*(*Actor32_8C7FCDataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Actor32_8C7FCData7443CView1)() __asm__("unk_ovlheader_8007443C");
extern int(*Actor32_8C7FCData74444View1)() __asm__("unk_ovlheader_80074444");
void func_level_32_8008C7FC(void *input) {
    register void *ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int retainedAngleOrAddress16 __asm__("$16"), privateRecord17 __asm__("$17"), secondaryResult20 __asm__("$20"), retainedStackAddress19 __asm__("$19");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64;
    }
    originalFrame;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateRecord17 = Actor32_8C7FCField(ownerRecord18, void **, 0);
    if ((unsigned int) (Actor32_8C7FCField(privateRecord17, int *, 0) - 1) < 2U) {
        if ((Actor32_8C7FCField(privateRecord17, void **, 0x2C) != 0) || ((rawWord3 = Actor32_8C7FCDataSpawnMobyView1(0x1CE, ownerRecord18), Actor32_8C7FCField(privateRecord17, void**, 0x2C) = rawWord3, (rawWord3 != 0)) && (Actor32_8C7FCField(rawWord3, int*, 20) = Actor32_8C7FCField(rawWord3, int*, 20)+512, Actor32_8C7FCField(Actor32_8C7FCField(privateRecord17, void **, 0x2C), signed char *, 0x45) = 0x30, (Actor32_8C7FCField(privateRecord17, void **, 0x2C) != 0)))) {
            rawWord3 = Actor32_8C7FCField(privateRecord17, void **, 0x2C);
            Actor32_8C7FCField(rawWord3, unsigned char *, 0x46) = (unsigned char) (Actor32_8C7FCField(rawWord3, unsigned char *, 0x46) + 8);
        }
        rawWord3 = Actor32_8C7FCField(privateRecord17, int*, 0);
        rawWord2 = 2;
        if (rawWord3 != rawWord2) goto continuePrivateModeEntry;
        rawWord3 = Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x48);
        rawWord2 = 6;
        if (rawWord3 == rawWord2){
            rawWord2 = 5;
            goto comparePreservedOrReloadedState5;
        }
        rawWord2 = Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x49);
        if (!rawWord2) goto initializeState5Comparison;
        rawWord2 = 5;
        Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        rawWord3 = Actor32_8C7FCField(ownerRecord18, volatile unsigned char*, 0x48);
        initializeState5Comparison:rawWord2 = 5;
        comparePreservedOrReloadedState5:if (rawWord3 == rawWord2) goto runInsertedState5;
        rawWord2 = 6;
        if (rawWord3 == rawWord2) goto runInsertedState6;
        goto continuePrivateModeEntry;
    runInsertedState5:
        if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short*, 0x28)))Actor32_8C7FCCall3BE70View1(Actor32_8C7FCField(privateRecord17, short*, 0x28));
        rawWord2 = -1;
        Actor32_8C7FCField(privateRecord17, short*, 0x28) = rawWord2;
        Actor32_8C7FCField(ownerRecord18, signed char*, 0x41) = 0;
        Actor32_8C7FCField(ownerRecord18, signed char*, 0x4C) = 0;
        Actor32_8C7FCField(ownerRecord18, signed char*, 0x4D) = 0;
        rawWord2 = Actor32_8C7FCField(privateRecord17, void**, 0x2C);
        if (rawWord2){
            Actor32_8C7FCField(rawWord2, signed char*, 0x41) = 0;
            rawWord2 = Actor32_8C7FCField(privateRecord17, void**, 0x2C);
            Actor32_8C7FCField(rawWord2, signed char*, 0x4C) = 0;
            rawWord2 = Actor32_8C7FCField(privateRecord17, void**, 0x2C);
            Actor32_8C7FCField(rawWord2, signed char*, 0x4D) = 0;
        }
        rawWord2 = 6;
        Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        return;
    runInsertedState6:
        rawWord2 = Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x49);
        rawWord3 = 1;
        if (rawWord2) return;
        argumentWord4 = 50;
        Actor32_8C7FCField(ownerRecord18, signed char*, 0x41) = rawWord3;
        Actor32_8C7FCField(ownerRecord18, signed char*, 0x4C) = argumentWord4;
        Actor32_8C7FCField(ownerRecord18, signed char*, 0x4D) = rawWord3;
        rawWord2 = Actor32_8C7FCField(privateRecord17, void**, 0x2C);
        if (rawWord2){
            Actor32_8C7FCField(rawWord2, signed char*, 0x41) = rawWord3;
            rawWord2 = Actor32_8C7FCField(privateRecord17, void**, 0x2C);
            Actor32_8C7FCField(rawWord2, signed char*, 0x4C) = argumentWord4;
            rawWord2 = Actor32_8C7FCField(privateRecord17, void**, 0x2C);
            Actor32_8C7FCField(rawWord2, signed char*, 0x4D) = rawWord3;
        }
        Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x48) = 0;
    continuePrivateModeEntry:
        if (Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x48) != 6) {
            if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short *, 0x28)) == 0) {
                Actor32_8C7FCField(privateRecord17, short *, 0x28) = Actor32_8C7FCCall3BABCView1(ownerRecord18, 3, 4);
            }
            if ((Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x48) != 6) && (Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), unsigned char *, 0x48) != 1) && (retainedAngleOrAddress16 = ownerRecord18 + 0xC, (((unsigned int) (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x50) - 7) < 2U) == 0)) && (Actor32_8C7FCCall4F334View1(retainedAngleOrAddress16, (&Actor32_8C7FCData70328View1 + 0x50) - 0x50) < 0x400)) {
                rawWord2 = (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 8) - Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x44)) - Actor32_8C7FCField(ownerRecord18, int *, 0x14);
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if (rawWord2 < 0x140) {
                    Actor32_8C7FCCall4F178View1(Actor32_8C7FCData6C550View1 + (Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + 0xC, retainedAngleOrAddress16);
                    Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), signed char *, 0x44) = 0;
                    Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), signed char *, 0x45) = 0;
                    Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), unsigned char *, 0x46) = (unsigned char) Actor32_8C7FCField(&Actor32_8C7FCData70328View1, unsigned char *, 0xE);
                    Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), signed char *, 0x4C) = 0x20;
                    Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), signed char *, 0x48) = 4;
                    Actor32_8C7FCCall369B8View1(Actor32_8C7FCData6C550View1 + (Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58), 0x18);
                    Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x23C) = 0x24;
                    Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x20C) = (int) (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x20C) | 0x10000080);
                    Actor32_8C7FCField(&Actor32_8C7FCData70328View1, void **, 0x250) = (void *) (Actor32_8C7FCData6C550View1 + (Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58));
                    Actor32_8C7FCField(((Actor32_8C7FCField(privateRecord17, int *, 4) * 0x58) + Actor32_8C7FCData6C550View1), signed char *, 0x48) = 4;
                    Actor32_8C7FCData6C700View1 = 0x2440;
                }
            }
        }
    }
    else {
        if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x50) == 0x13) {
            if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x4C) == 5) {
                Actor32_8C7FCField(privateRecord17, short *, 0xF0) = 3;
            }
            else if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x4C) == 4) {
                Actor32_8C7FCField(privateRecord17, short *, 0xF0) = 2;
            }
            else {
                Actor32_8C7FCField(privateRecord17, short *, 0xF0) = 1;
            }
        }
        else {
            Actor32_8C7FCField(privateRecord17, short *, 0xF0) = 0;
        }
        rawWord3 = Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x48);
        switch (rawWord3) {
        case 0:
            rawWord3 = Actor32_8C7FCField(ownerRecord18, short *, 0x36);
            if ((rawWord3 == 0x36) || (rawWord3 == 0x294) || (rawWord3 == 0xFB)) {
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x41) = 0;
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x4C) = 0;
                Actor32_8C7FCField(ownerRecord18, signed char*, 0x4D) = 0;
                goto prepareHookArgument4;
            }
            argumentWord4 = 0;
            goto prepareHookArgument5;
            default:argumentWord4 = 0;
            goto prepareHookArgument5;
        case 4:
            if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x50) == 0x13) {
                Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x48) = 1U;
            }
            argumentWord4 = 0;
            goto prepareHookArgument5;
        case 1:
            Actor32_8C7FCCall4F168View1(&originalFrame.sp18);
            originalFrame.sp20 = -0x400;
            Actor32_8C7FCCall55D24View1(ownerRecord18, 4);
            Actor32_8C7FCCall4ED6CView1(ownerRecord18 + 0x20, &originalFrame.sp18, &originalFrame.sp18);
            rawWord2 = Actor32_8C7FCCall4E880View1(Actor32_8C7FCCall4EDE8View1(&originalFrame.sp18, 0), originalFrame.sp20, 1);
            argumentWord6 = 1;
            __asm__(""::"r"(argumentWord6):"$16");
            retainedAngleOrAddress16 = rawWord2;
            rawWord2 = Actor32_8C7FCCall4E880View1(originalFrame.sp18, originalFrame.sp1C, argumentWord6);
            argumentWord4 = retainedAngleOrAddress16;
            rawWord3 = 4;
            retainedAngleOrAddress16 = rawWord2+0x800;
            Actor32_8C7FCField(ownerRecord18, signed char*, 0x47) = rawWord3;
            argumentWord5 = Actor32_8C7FCData6E03EView1;
            retainedAngleOrAddress16 &= 0xFFF;
            rawWord2 = Actor32_8C7FCCall4F284View1(argumentWord4, argumentWord5);
            argumentWord4 = retainedAngleOrAddress16;
            argumentWord5 = Actor32_8C7FCData6E040View1;
            retainedAngleOrAddress16 = rawWord2;
            rawWord2 = Actor32_8C7FCCall4F284View1(argumentWord4, argumentWord5);
            retainedAngleOrAddress16 = retainedAngleOrAddress16 < 600;
            rawWord2 = rawWord2 < 600;
            if (retainedAngleOrAddress16 && rawWord2) {
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x47) = 9;
            }
            rawWord2 = Actor32_8C7FCField(&Actor32_8C7FCDatag_CheatFlagsView1, unsigned char*, 1);
            argumentWord4 = (int)ownerRecord18;
            if (rawWord2){
                __asm__ __volatile__(""::"r"(rawWord2):"$5");
                argumentWord5 = 1;
            }
            else{
                __asm__ __volatile__("":::"$2");
                argumentWord5 = 0;
                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            }
            Actor32_8C7FCCall34F80View1(argumentWord4, argumentWord5);
            if (Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x3D) == 0) {
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x41) = 0;
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x3E) = 0;
                argumentWord5 = 0;
                if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0xB8) == 0) {
                    argumentWord5 = Actor32_8C7FCField(&Actor32_8C7FCData70328View1, unsigned char *, 0xC);
                }
                if ((int) argumentWord5 >= 0x81) {
                    argumentWord5 -= 0x100;
                }
                if (argumentWord5 <= 0) goto clampNonPositiveInput;
                rawWord2 = argumentWord5 < 16;
                if (rawWord2){
                    rawWord2 = 1;
                    goto storeInputBytes;
                }
                rawWord2 = 1;
                argumentWord5 = 15;
                goto storeInputBytes;
                clampNonPositiveInput:argumentWord5 = -argumentWord5;
                rawWord2 = argumentWord5 < 16;
                if (rawWord2){
                    rawWord2 = 2;
                    goto storeInputBytes;
                }
                rawWord2 = 2;
                argumentWord5 = 15;
            storeInputBytes:
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x3F) = rawWord2;
                rawWord2 = argumentWord5&15;
                Actor32_8C7FCField(ownerRecord18, signed char*, 0x40) = rawWord2;
            }
            else {
                Actor32_8C7FCField(ownerRecord18, signed char *, 0x41) = 1;
            }
            if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0xB8) != 0) {
                if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short *, 0x28)) != 0) {
                    Actor32_8C7FCCall3BE70View1(Actor32_8C7FCField(privateRecord17, short *, 0x28));
                }
                Actor32_8C7FCField(privateRecord17, short *, 0x28) = -1;
            }
            else {
                if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short *, 0x28)) == 0) {
                    Actor32_8C7FCField(privateRecord17, short *, 0x28) = Actor32_8C7FCCall3BABCView1(ownerRecord18, 0, 4);
                }
                argumentWord4 = Actor32_8C7FCField(privateRecord17, short *, 0x28);
                if (argumentWord4 >= 0) {
                    rawWord2 = Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int*, 0x5C);
                    argumentWord5 = rawWord2&0xFFF;
                    if (argumentWord5 >= 0x801) {
                        argumentWord5 -= 0x1000;
                    }
                    argumentWord5 = argumentWord5 * 4;
                    if (argumentWord5 < 0) {
                        argumentWord5 = -argumentWord5;
                    }
                    Actor32_8C7FCCall3C0B0View1(argumentWord4, argumentWord5 + 0x1000);
                }
            }
            if (Actor32_8C7FCField(privateRecord17, int *, 0xC) != 0) {
                if ((unsigned int) (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x4C) - 4) >= 2U) {
                    Actor32_8C7FCField(privateRecord17, int *, 0xC) = 0;
                }
            }
            else if ((unsigned int) (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x4C) - 4) < 2U) {
                argumentWord4 = privateRecord17+100;
                rawWord3 = (int)Actor32_8C7FCData74444View1;
                rawWord2 = 1;
                Actor32_8C7FCField(privateRecord17, int*, 12) = rawWord2;
                ((int(*)())rawWord3)(argumentWord4);
            }
            Actor32_8C7FCField(&Actor32_8C7FCData70328View1, void **, 0x250) = ownerRecord18;
            if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x50) != 0x13) {
                argumentWord5 = privateRecord17 + 0x64;
                if (Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x240) == 0) {
                    Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x49) = 0U;
                    Actor32_8C7FCField(privateRecord17, short *, 0x22) = 0x1E;
                    Actor32_8C7FCField(privateRecord17, short *, 0x20) = 0x78;
                    Actor32_8C7FCField(privateRecord17, unsigned short *, 0x26) = 0U;
                    Actor32_8C7FCField(privateRecord17, short *, 0x24) = 0xC;
                    rawWord2 = Actor32_8C7FCField(&Actor32_8C7FCData70328View1, unsigned char*, 14);
                    argumentWord4 = (int)ownerRecord18;
                    rawWord2 += 128;
                    rawWord2 &= 255;
                    rawWord2 <<= 1;
                    rawWord3 = Actor32_8C7FCField(&Actor32_8C7FCData65920View1, short*, rawWord2);
                    argumentWord5 = 4;
                    rawWord2 = rawWord3*25;
                    rawWord2 >>= 9;
                    Actor32_8C7FCField(privateRecord17, int*, 20) = rawWord2;
                    rawWord2 = Actor32_8C7FCField(&Actor32_8C7FCData70328View1, unsigned char*, 14);
                    argumentWord6 = 0;
                    rawWord2 += 128;
                    rawWord2 &= 255;
                    rawWord2 <<= 1;
                    rawWord3 = Actor32_8C7FCField(&Actor32_8C7FCData658A0View1, short*, rawWord2);
                    rawWord2 = 125;
                    Actor32_8C7FCField(privateRecord17, int*, 28) = rawWord2;
                    rawWord2 = rawWord3*25;
                    rawWord2 >>= 9;
                    Actor32_8C7FCField(privateRecord17, int*, 24) = rawWord2;
                    Actor32_8C7FCCall3BABCView1(argumentWord4, argumentWord5, argumentWord6);
                    Actor32_8C7FCField(privateRecord17, short *, 0x2A) = -1;
                    Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x48) = 2U;
                    if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, int*, 0x15C)) != 0) {
                        Actor32_8C7FCCall3BE70View1(Actor32_8C7FCField(privateRecord17, int*, 0x15C));
                    }
                    Actor32_8C7FCField(privateRecord17, int *, 0x15C) = -1;
                    if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short *, 0x28)) != 0) {
                        Actor32_8C7FCCall3BE70View1(Actor32_8C7FCField(privateRecord17, short *, 0x28));
                    }
                    Actor32_8C7FCField(privateRecord17, short *, 0x28) = -1;
                    goto prepareHookArgument4;
                }
            }
            else {
                argumentWord4 = 0;
                goto prepareHookArgument5;
            }
            argumentWord4 = 0;
            goto callSharedHook;
        case 3:
            Actor32_8C7FCCall369B8View1(ownerRecord18, 0x18);
            Actor32_8C7FCField(ownerRecord18, signed char *, 0x4D) = 0;
            Actor32_8C7FCField(ownerRecord18, signed char *, 0x4C) = 0;
            Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x48) = 0U;
            goto prepareHookArgument4;
        case 2:
            argumentWord4 = (int)&originalFrame.sp28;
            __asm__(""::"r"(argumentWord4):"$16");
            retainedAngleOrAddress16 = (int)ownerRecord18+12;
            Actor32_8C7FCCall4F178View1(argumentWord4, retainedAngleOrAddress16);
            if (Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x49) != 0) {
                argumentWord6 = (unsigned char) Actor32_8C7FCField(privateRecord17, short *, 0x24);
                Actor32_8C7FCField(privateRecord17, int *, 0x1C) = (int) (Actor32_8C7FCField(privateRecord17, int *, 0x1C) - 0xC);
                Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x45) = (unsigned char) (Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x45) + argumentWord6);
                Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x44) = (unsigned char) (Actor32_8C7FCField(ownerRecord18, unsigned char *, 0x44) + 8);
                Actor32_8C7FCCall55D24View1(ownerRecord18, 4, argumentWord6);
                if ((Actor32_8C7FCField(ownerRecord18, int *, 0xC) >= 0x400) && (Actor32_8C7FCField(ownerRecord18, int *, 0x10) >= 0x400) && (Actor32_8C7FCField(ownerRecord18, int *, 0x14) >= 0x400)) {
                    Actor32_8C7FCCall4F194View1(retainedAngleOrAddress16, retainedAngleOrAddress16, privateRecord17 + 0x14);
                    goto prepareState2Sources;
                }
                goto storeState3AndReturn;
            }
        prepareState2Sources:
            Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x49) = 1;
            __asm__ __volatile__("":"=r"(ownerRecord18):"0"(ownerRecord18):"$16");
            argumentWord4 = (int)ownerRecord18;
            argumentWord5 = 0;
            __asm__(""::"r"(argumentWord4), "r"(argumentWord5):"$16");
            retainedAngleOrAddress16 = (int)&originalFrame.sp38;
            Actor32_8C7FCCall55F14View1(argumentWord4, argumentWord5, retainedAngleOrAddress16);
            retainedStackAddress19 = (int)&originalFrame.sp48;
            Actor32_8C7FCCall55F14View1(ownerRecord18, 1, retainedStackAddress19);
            secondaryResult20 = 0;
            if (Actor32_8C7FCCall359A4View1(privateRecord17 + 0x22, 2) != 0) {
                if ((Actor32_8C7FCCall1C288View1(retainedAngleOrAddress16, 0x64, 0) != 0) || (rawWord2 = Actor32_8C7FCCall1C288View1(retainedStackAddress19, 0x64, 0), secondaryResult20 = rawWord2 != 0, (rawWord2 != 0))) {
                    rawWord2 = Actor32_8C7FCField(privateRecord17, unsigned short*, 0x26);
                    rawWord2 += 1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Actor32_8C7FCField(privateRecord17, unsigned short*, 0x26) = rawWord2;
                    if (secondaryResult20 != 0) {
                        rawWord2 = -0xC;
                    }
                    else{
                        __asm__ __volatile__("":::"$2");
                        rawWord2 = 12;
                    }
                    Actor32_8C7FCField(privateRecord17, short*, 0x24) = rawWord2;
                    __asm__ __volatile__("":::"memory");
                    Actor32_8C7FCField(&Actor32_8C7FCData70328View1, int *, 0x298) = Actor32_8C7FCCall4E880View1(Actor32_8C7FCField(privateRecord17, int *, 0x14), Actor32_8C7FCField(privateRecord17, int *, 0x18), 0);
                    (retainedAngleOrAddress16 = (int)&originalFrame.sp58, Actor32_8C7FCCall4F1C8View1(retainedAngleOrAddress16, ownerRecord18 + 0xC, (&Actor32_8C7FCData70328View1+0x298)-0x298));
                    argumentWord4 = privateRecord17 + 0x14;
                    rawWord2 = Actor32_8C7FCCall4EF74View1(argumentWord4, retainedAngleOrAddress16, argumentWord4);
                    argumentWord4 = (int)ownerRecord18;
                    if (rawWord2){
                        Actor32_8C7FCField(privateRecord17, int *, 0x14) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x14) * 6) >> 3);
                        Actor32_8C7FCField(privateRecord17, int *, 0x18) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x18) * 6) >> 3);
                        Actor32_8C7FCField(privateRecord17, int *, 0x1C) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x1C) * 6) >> 3);
                        rawWord2 = Actor32_8C7FCCall3BFC0View1(argumentWord4, Actor32_8C7FCField(privateRecord17, short*, 0x2A));
                        argumentWord4 = (int)&originalFrame.sp38;
                        if (rawWord2) goto callFirstCollisionWithPreparedA0;
                        {
                            __asm__ __volatile__("":::"$2");
                            rawWord2 = Actor32_8C7FCCall3BABCView1(ownerRecord18, 4, 0);
                            Actor32_8C7FCField(privateRecord17, short*, 0x2A) = rawWord2;
                            rawWord2 = (unsigned int)rawWord2 << 16;
                            argumentWord4 = rawWord2 >> 16;
                            if (argumentWord4 >= 0) {
                                rawWord2 = Actor32_8C7FCField(privateRecord17, int *, 0x1C);
                                if (rawWord2 < 0) {
                                    rawWord2 = -rawWord2;
                                }
                                Actor32_8C7FCCall3C140View1(argumentWord4, rawWord2*40);
                            }
                        }
                    }
                }
                prepareFirstCollisionStack:__asm__ __volatile__("":::"$4");
                argumentWord4 = (int)&originalFrame.sp38;
                callFirstCollisionWithPreparedA0:argumentWord5 = 150;
                argumentWord6 = Actor32_8C7FCCall1BA30View1(argumentWord4, argumentWord5, 1, 0, 0x10000000, ownerRecord18);
                argumentWord4 = (int)&originalFrame.sp48;
                if (argumentWord6 == 0){
                    __asm__(""::"r"(argumentWord4):"$5");
                    argumentWord5 = 150;
                    argumentWord6 = Actor32_8C7FCCall1BA30View1(argumentWord4, argumentWord5, 1, 0, 0x10000000, ownerRecord18);
                    argumentWord4 = privateRecord17 + 0x20;
                    if (argumentWord6 != 0) {
                        secondaryResult20 = 1;
                        goto handleSecondCollisionResult;
                    }
                }
                else {
                handleSecondCollisionResult:
                    rawWord2 = Actor32_8C7FCField(privateRecord17, unsigned short*, 0x26);
                    rawWord2 += 1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Actor32_8C7FCField(privateRecord17, unsigned short*, 0x26) = rawWord2;
                    if (secondaryResult20 != 0) {
                        rawWord2 = -0xC;
                    }
                    else{
                        __asm__ __volatile__("":::"$2");
                        rawWord2 = 12;
                    }
                    Actor32_8C7FCField(privateRecord17, short *, 0x24) = rawWord2;
                    retainedAngleOrAddress16 = (int)&originalFrame.sp58;
                    Actor32_8C7FCCall4F1C8View1(retainedAngleOrAddress16, ownerRecord18+12, argumentWord6+12);
                    argumentWord4 = privateRecord17 + 0x14;
                    if (Actor32_8C7FCCall4EF74View1(argumentWord4, retainedAngleOrAddress16, argumentWord4) != 0) {
                        Actor32_8C7FCField(privateRecord17, int *, 0x14) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x14) * 6) >> 3);
                        Actor32_8C7FCField(privateRecord17, int *, 0x18) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x18) * 6) >> 3);
                        Actor32_8C7FCField(privateRecord17, int *, 0x1C) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x1C) * 6) >> 3);
                        argumentWord4 = privateRecord17 + 0x20;
                        rawWord2 = Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short*, 0x2A));
                        argumentWord4 = privateRecord17+32;
                        if (rawWord2) goto callState2CountdownHelper;
                        {
                            __asm__ __volatile__("":::"$2");
                            rawWord2 = Actor32_8C7FCCall3BABCView1(ownerRecord18, 4, 0);
                            Actor32_8C7FCField(privateRecord17, short*, 0x2A) = rawWord2;
                            rawWord2 = (unsigned int)rawWord2 << 16;
                            argumentWord4 = rawWord2 >> 16;
                            if (argumentWord4 >= 0) {
                                rawWord2 = Actor32_8C7FCField(privateRecord17, int *, 0x1C);
                                if (rawWord2 < 0) {
                                    rawWord2 = -rawWord2;
                                }
                                Actor32_8C7FCCall3C140View1(argumentWord4, rawWord2*40);
                            }
                            goto prepareState2Countdown;
                        }
                    }
                    else {
                        goto prepareState2Countdown;
                    }
                }
            }
            else {
            prepareState2Countdown:
                argumentWord4 = privateRecord17 + 0x20;
            }
            callState2CountdownHelper:if (Actor32_8C7FCCall359A4View1(argumentWord4, 2)) goto storeState3AndReturn;
            rawWord2 = Actor32_8C7FCField(privateRecord17, short*, 0x26);
            rawWord2 = rawWord2 < 31;
            if (rawWord2) goto probeState2SurfaceSources;
            storeState3AndReturn:rawWord2 = 3;
            Actor32_8C7FCField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
            return;
            probeState2SurfaceSources:{
                if (Actor32_8C7FCCall19194View1(&originalFrame.sp38, 0x96) == 0) {
                    if (Actor32_8C7FCCall19194View1(&originalFrame.sp48, 0x96) != 0) {
                        secondaryResult20 = 1;
                        goto handleSurfaceResult;
                    }
                    if (Actor32_8C7FCCall18368View1(&originalFrame.sp28, ownerRecord18 + 0xC) != 0) {
                        goto handleSurfaceResult;
                    }
                }
                else {
                handleSurfaceResult:
                    rawWord2 = Actor32_8C7FCField(privateRecord17, unsigned short*, 0x26);
                    rawWord2 += 1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Actor32_8C7FCField(privateRecord17, unsigned short*, 0x26) = rawWord2;
                    if (secondaryResult20 != 0) {
                        rawWord2 = -0xC;
                    }
                    else{
                        __asm__ __volatile__("":::"$2");
                        rawWord2 = 12;
                    }
                    Actor32_8C7FCField(privateRecord17, short *, 0x24) = rawWord2;
                    argumentWord4 = privateRecord17 + 0x14;
                    if (Actor32_8C7FCCall4EF74View1(argumentWord4, &Actor32_8C7FCData71918View1, argumentWord4) != 0) {
                        Actor32_8C7FCField(privateRecord17, int *, 0x14) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x14) * 6) >> 3);
                        Actor32_8C7FCField(privateRecord17, int *, 0x18) = (int) ((int) (Actor32_8C7FCField(privateRecord17, int *, 0x18) * 6) >> 3);
                        Actor32_8C7FCField(privateRecord17, int *, 0x1C) = (int) (((int) (Actor32_8C7FCField(privateRecord17, int *, 0x1C) * 6) >> 3) + 0x14);
                        if (Actor32_8C7FCCall3BFC0View1(ownerRecord18, Actor32_8C7FCField(privateRecord17, short *, 0x2A)) == 0) {
                            rawWord2 = Actor32_8C7FCCall3BABCView1(ownerRecord18, 4, 0);
                            Actor32_8C7FCField(privateRecord17, short*, 0x2A) = rawWord2;
                            rawWord2 = (unsigned int)rawWord2 << 16;
                            argumentWord4 = rawWord2 >> 16;
                            if (argumentWord4 >= 0) {
                                rawWord2 = Actor32_8C7FCField(privateRecord17, int *, 0x1C);
                                if (rawWord2 < 0) {
                                    rawWord2 = -rawWord2;
                                }
                                Actor32_8C7FCCall3C140View1(argumentWord4, rawWord2*40);
                            }
                        }
                    }
                }
                argumentWord4 = 0;
                goto prepareHookArgument5;
            }
        }
    }
    return;
    prepareHookArgument4:argumentWord4 = 0;
    prepareHookArgument5:argumentWord5 = privateRecord17+0x64;
    callSharedHook:Actor32_8C7FCData7443CView1(argumentWord4, argumentWord5, 0);
}
#undef Actor32_8C7FCField


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
void func_level_32_8008D5E8(void *input) {
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


void func_level_32_8008E73C(Moby* moby) {
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
void func_level_32_8008E75C(Moby* argument) {
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

extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_32_8008E95C(Moby* moby) {
    if (D_8006C770 != 0) func_80055B18(moby);
}
