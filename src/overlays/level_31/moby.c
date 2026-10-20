#include "common.h"
#include "mobyutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
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
int Controller74C50Helper399E8(void*,void*) __asm__("func_800399E8");
int Controller74C50Helper39B6C(void*,void*) __asm__("func_80039B6C");
void func_level_31_800757BC(void *input) {
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
    register void *stateThreeVector __asm__("$17");
    register void *stateThreeDelta __asm__("$16");
    register void *stateTwoNormal __asm__("$21");
    register int temp_v0 __asm__("$2");
    register int temp_v0_4 __asm__("$2");
    register unsigned char * resourceRecord __asm__("$16");
    register unsigned char * workingPosition __asm__("$17");
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
    register unsigned char * tag __asm__("$19");
    register unsigned char * callbackTag __asm__("$17");
    register void *originalCallback6 __asm__("$6");
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
        if(Controller74C50Field(owner,unsigned char*,0x48)==125) return;
        if(Controller74C50Field(tag,int*,0)==0)
            Controller74C50Helper399E8(owner,tag);
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
                    if ((var_v0 < var_a0) && ({originalCallback6=Controller74C50D_8006C65C;
        __asm__("" : "=r"(originalCallback6) : "0"(originalCallback6));
        originalCallback6!=0;}) && ((Controller74C50Field(owner, unsigned char *, 0x48) != 2) || ((unsigned char) Controller74C50Field(tag, unsigned char *, 0x12) < 3U)) && (callbackTag = Controller74C50Field(originalCallback6, void **, 0), Controller74C50Helper4F178(&frame.ninth.x, owner + 0xC), frame.ninth.z += 0x64, (Controller74C50Helper13E38(Controller74C50D_8006C65C + 0xC, &frame.ninth.x, 0) != 0))) {
                        callbackOwnerReference = Controller74C50Field(callbackTag, void **, 0x14);
                        if (callbackOwnerReference != 0) {
                            if ((callbackOwnerReference != owner) && (Controller74C50Field(callbackTag, short *, 0) > 0)) {
                                Controller74C50Field(callbackTag, short *, 0) = 0;
                                goto originalActorTail;
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
originalActorTail:
        if(Controller74C50Field(tag,int*,0)!=0)
            Controller74C50Helper39B6C(owner,tag);
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
void func_level_31_8007645C(Moby* argument) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
int Controller75F38Helper399E8(void*,void*) __asm__("func_800399E8");
int Controller75F38Helper39B6C(void*,void*) __asm__("func_80039B6C");
void func_level_31_80076AE8(void *input) {
    register unsigned char *owner __asm__("$20")=input;
    struct {
        struct {int x,y,z;} first;int p44;
        struct {int x,y,z;} second;int p54;
        struct {int x,y,z;} third;int p64;
        struct {int x,y,z;} fourth;int p74;
        struct {int x,y,z;} fifth;int p84;
        int matrix[6];
        struct {int x,y,z;} sixth;int padAC[1]; int siblingPadding[4];
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

    {register int gateValue __asm__("$3")=125;
     __asm__("" : "=r"(gateValue) : "0"(gateValue));
    tag = Controller75F38Field(owner, void **, 0);
    __asm__("" : "=r"(tag) : "0"(tag) : "$2","memory");
    {register int gate __asm__("$2")=Controller75F38Field(owner,unsigned char*,0x48);
     __asm__("" : "=r"(gate) : "0"(gate));
     originalAngle=Controller75F38Field(owner,unsigned char*,0x46);
     if(gate==gateValue)return;
    }
    }
    if(Controller75F38Field(tag,void**,0x18)==0)
        Controller75F38Helper399E8(owner,(unsigned char*)tag+0x18);
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
        {register void *particleVector __asm__("$17")=&frame.second.x;
         register void *first __asm__("$4")=particleVector;
         register int angleIndex __asm__("$3")=Controller75F38Field(owner,unsigned char*,0x46);
         register void *second __asm__("$5");
         register int sample __asm__("$6");
         register int value __asm__("$2");
         register int otherSample __asm__("$3");
         register void *third __asm__("$6");
         __asm__("" : "=r"(first),"=r"(angleIndex) : "0"(first),"1"(angleIndex) : "$5");
         second=&frame.first.x;
         __asm__("" : "=r"(second) : "0"(second) : "$16");
         angleIndex=((angleIndex+64)&255)*2;
         sample=*(short*)(Controller75F38D_80065920+angleIndex);
         __asm__("" : "=r"(sample) : "0"(sample) : "$16");
         temp_s0_2=owner+12;
         value=(sample*25)>>10;frame.first.x=value;
         otherSample=*(short*)(Controller75F38D_800658A0+angleIndex);
         __asm__("" : "=r"(otherSample) : "0"(otherSample) : "$6");
         third=temp_s0_2;
         frame.first.z=0;
         __asm__ volatile("" ::: "$2","memory");
         value=(otherSample*25)>>10;frame.first.y=value;
         Controller75F38Helper4F194(first,second,third);
         Controller75F38SpawnParticle(2,0x42,particleVector,0);
         Controller75F38Helper4F1C8(particleVector,temp_s0_2,&frame.first.x);
         Controller75F38SpawnParticle(2,0x42,particleVector,0);
         {register unsigned char *firstTable __asm__("$16")=Controller75F38D_80065920;
          register unsigned char *secondTable __asm__("$18");
          register unsigned char *child __asm__("$2");
          register int childAngle __asm__("$3");
          register int childSample __asm__("$4");
          register int childOther __asm__("$3");
          register int childValue __asm__("$2");
          register unsigned char *childFirstAddress __asm__("$2");
          register unsigned char *childSecondAddress __asm__("$3");
          register void *childSecond __asm__("$5");
          __asm__("" : "=r"(firstTable) : "0"(firstTable) : "$2","$18");
          child=Controller75F38Field(tag,unsigned char**,0x18);
          __asm__("" : "=r"(child) : "0"(child) : "$18");
          secondTable=Controller75F38D_800658A0;
          __asm__("" : "=r"(child),"=r"(secondTable) : "0"(child),"1"(secondTable) : "$5");
          childSecond=&frame.first.x;
          if(child!=0) {
            childAngle=Controller75F38Field(child,unsigned char*,0x46);
            childAngle=((childAngle+64)&255)*2;
            childFirstAddress=(unsigned char*)(childAngle+(int)firstTable);
            __asm__("" : "=r"(childFirstAddress) : "0"(childFirstAddress));
            childSample=*(short*)childFirstAddress;
            __asm__ volatile("" : "=r"(childSample) : "0"(childSample),"r"(childAngle) : "memory");
            childSecondAddress=(unsigned char*)(childAngle+(int)secondTable);
            __asm__("" : "=r"(childSample),"=r"(childSecondAddress) : "0"(childSample),"1"(childSecondAddress) : "$2");
            childValue=(childSample*25)>>10;
            frame.first.x=childValue;
            childOther=*(short*)childSecondAddress;
            frame.first.z=0;
            __asm__ volatile("" ::: "$2","memory");
            childValue=(childOther*25)>>10;frame.first.y=childValue;
            Controller75F38Helper4F194(particleVector,childSecond,Controller75F38Field(tag,unsigned char**,0x18)+12);
            Controller75F38SpawnParticle(2,0x42,particleVector,0);
            Controller75F38Helper4F1C8(particleVector,Controller75F38Field(tag,unsigned char**,0x18)+12,&frame.first.x);
            Controller75F38SpawnParticle(2,0x42,particleVector,0);
          }
         }
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
        temp_a0=Controller75F38Field(tag,void**,0x18);
        if(temp_a0!=0)Controller75F38Helper55B18(temp_a0);
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
    temp_v0=Controller75F38Field(tag,void**,0x18);
    if(temp_v0!=0) {
        Controller75F38Helper39B6C(owner,(unsigned char*)tag+0x18);
        temp_a0=Controller75F38Field(tag,void**,0x18);
        if(temp_a0!=0)Controller75F38Field(temp_a0,int*,0x54)=Controller75F38Field(owner,int*,0x54);
    }
}

typedef struct { short timer; unsigned char selector,reserved03; unsigned char reserved04[0x10]; Moby* target; } DecodedFocusTag;
extern int D_8006581C,D_80065810,D_80065818,D_8006C578,D_8006C574;
extern Moby* D_8006C65C;
int func_8004F334(Vector3D*,Vector3D*);
int func_80013E38(Vector3D*,Vector3D*,int);
void func_80037014(Moby*);
void func_80036A68(Moby*,int,int,int);
int rand(void);
void func_level_31_80078188(Moby* moby) {
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
void func_level_31_80078448(Moby* argument) {
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
void func_level_31_80078968(Moby *moby) {
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
void func_level_31_80078C6C(void *input) {
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
void func_level_31_800797E0(Moby* moby) {
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
void func_level_31_80079C10(Moby* owner) {
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

void func_level_31_80079D9C(Moby* moby) {
    if (!moby->substate) {
        SpawnParticle(0x40, 0xE, (Vector3D*)1, 0);
        moby->substate = 1;
    } else {
        SpawnParticle(1, 0xE, 0, 0);
    }
}

typedef struct {
    unsigned char reserved00,toll,mode,reserved03[2],enabled,reserved06[0x22];
    int actorIndex,tollIndex,selector;
} DecodedTollInteraction;
extern GemToll DecodedGateTolls[] __asm__("D_80066EAC");
extern unsigned char DecodedGateHeader[] __asm__("D_80066FCC");
extern unsigned char D_80070300[];
extern unsigned char DecodedGateStatus __asm__("D_80071584");
extern int D_8006C71C,D_8006C640,D_8006E344;
extern Moby* D_8006C550;
void DecodedGateDispatch(int,int,int) __asm__("func_80021ED8");
void func_level_31_80079E18(Moby* actor) {
    DecodedTollInteraction* tag=actor->mobyTag;
    int toll,selector;
    int state=actor->state;
    switch(state) {
    case 0:
        toll=tag->toll&0x7F;
        if(toll!=0x7F && D_8006C71C>=DecodedGateTolls[toll].value && !DecodedGateTolls[toll].paid) {
            tag->enabled=1;tag->toll=0xFF;
        }
        if(tag->tollIndex!=-1 && D_8006C640<0xA && (DecodedGateTolls[tag->tollIndex].paid || (D_80070300[DecodedGateHeader[0x2F]]&1))) {
            if(tag->actorIndex!=-1)D_8006C550[tag->actorIndex].substate=1;
            if(tag->selector!=-1)DecodedGateDispatch(tag->selector,0xFC,0);
            func_80055B18(actor);break;
        }
        if((tag->actorIndex!=-1 || tag->selector!=-1) && tag->mode==4) {
            if(tag->actorIndex!=-1)D_8006C550[tag->actorIndex].substate=1;
            selector=tag->selector;tag->actorIndex=-1;
            if(selector!=-1)DecodedGateDispatch(selector,0xFC,0);
            tag->selector=-1;
        }
        if(func_80037BBC(actor,0)) {func_800512E4(actor,0,1);actor->state=1;}
        break;
    case 1:
        DecodedGateStatus=1;
        if(D_8006E344!=state) {actor->state=0;func_80034F40(actor,0);}
        break;
    }
}

extern int D_8006E53C, D_8006E344;
extern unsigned char D_80066FCC[], D_80070300[];
int func_80037BBC(Moby*, int);
void func_800512E4(Moby*, int, int);
extern unsigned char D_80071582;
void func_level_31_8007A058(Moby* moby) {
    SpeechProps* tag = moby->mobyTag;
    switch (moby->state) {
    case 0:
        if (moby->mobyClass == 0x198) {
            if (!D_80071582) tag->nextMsg = 0;
            else {
                if (D_80070300[D_80066FCC[0x24]] & 1) tag->nextMsg = 2;
                else tag->nextMsg = 1;
            }
        }
        if (tag->nextMsg == 2) tag->autoTalk = 0;
        if (!tag->autoTalk) {
            if (D_8006E53C & 0x10) {
                if (func_80037BBC(moby, 0)) goto start;
                tag->talkable = 0;
                /* Preserve the original store-before-load ordering. */
                __asm__ volatile("" : : : "memory");
            }
            if (!tag->autoTalk) return;
        }
        if (func_80037BBC(moby, 0)) {
start:
            func_800512E4(moby, 0, 0);
            moby->state = 1;
        } else tag->talkable = 0;
        break;
    case 1:
        if (D_8006E344 != 1) {
            *(int*)((char*)tag + 0x20) = 1;
            moby->state = 0;
        }
        break;
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
void func_level_31_8007A1A8(Moby* actor) {
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
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original five-state controller: 259 instructions per overlay copy.
 * Tag word +0; position increments 64 and initial offset -2048.
 * Five table vectors have a 12-byte stride; phase rises by16, clamped256.
 * State4 retains signed table division by8, angle thresholds and exact
 * unsigned collision comparisons. Original load widths and pointer lifetimes
 * are preserved. Empty compiler constraints emit no opcode patches.
 * Units, fixed-point domains, helper/table producers and caller cadence remain
 * unresolved; updates occur once per call. Existing names imply no semantics.
 * Confidence: exact compiled instructions, linked table words and retail hashes.
 * Falsifiable test: compare every original linked word and complete retail SHA.
 */
void func_level_31_8007A454(Moby *input) {
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
        if ((D_8006C7B4 & 1) && (D_8006E344 == 0)) {
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


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original1913 words. AI generated, not human reviewed; UNINSTALLED CONDITIONAL
 * probe. AI-lane owner49 in0..3 remains UNPROVEN; no initializer or runtime guard is added. */
#define Level31_7A860Field(p, t, o) (*(t)((unsigned char *)(p) + (o)))
#define Level31_7A860Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level31_7A860_func_8001BA30() __asm__("func_8001BA30");
int Level31_7A860_func_80034F40() __asm__("func_80034F40");
int Level31_7A860_func_8003573C() __asm__("func_8003573C");
int Level31_7A860_func_8003585C() __asm__("func_8003585C");
int Level31_7A860_func_800359A4() __asm__("func_800359A4");
int Level31_7A860_func_8003636C() __asm__("func_8003636C");
int Level31_7A860_func_80038000() __asm__("func_80038000");
int Level31_7A860_func_8003A908() __asm__("func_8003A908");
int Level31_7A860_func_8003B7B4() __asm__("func_8003B7B4");
int Level31_7A860_func_8004E880() __asm__("func_8004E880");
int Level31_7A860_func_8004E9E4() __asm__("func_8004E9E4");
int Level31_7A860_func_8004EA2C() __asm__("func_8004EA2C");
int Level31_7A860_func_8004ECF4() __asm__("func_8004ECF4");
int Level31_7A860_func_8004ED6C() __asm__("func_8004ED6C");
int Level31_7A860_func_8004EDE8() __asm__("func_8004EDE8");
int Level31_7A860_func_8004EF04() __asm__("func_8004EF04");
int Level31_7A860_func_8004F08C() __asm__("func_8004F08C");
int Level31_7A860_func_8004F110() __asm__("func_8004F110");
int Level31_7A860_func_8004F168() __asm__("func_8004F168");
int Level31_7A860_func_8004F178() __asm__("func_8004F178");
int Level31_7A860_func_8004F194() __asm__("func_8004F194");
int Level31_7A860_func_8004F1C8() __asm__("func_8004F1C8");
int Level31_7A860_func_80055D24() __asm__("func_80055D24");
int Level31_7A860_func_80055E84() __asm__("func_80055E84");
int Level31_7A860_func_80055F14() __asm__("func_80055F14");
int Level31_7A860_rand() __asm__("rand");
extern int Level31_7A860_D_800658A0 __asm__("D_800658A0");
extern int Level31_7A860_D_80065920 __asm__("D_80065920");
extern int Level31_7A860_D_8006C54C __asm__("D_8006C54C");
extern int Level31_7A860_D_8006C550 __asm__("D_8006C550");
extern int Level31_7A860_D_8006C568 __asm__("D_8006C568");
extern int Level31_7A860_D_8006C58C __asm__("D_8006C58C");
extern int Level31_7A860_D_8006C640 __asm__("D_8006C640");
extern int Level31_7A860_D_8006C648 __asm__("D_8006C648");
extern int Level31_7A860_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level31_7A860_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level31_7A860_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level31_7A860_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level31_7A860_D_8006E020 __asm__("D_8006E020");
extern int Level31_7A860_D_8006E024 __asm__("D_8006E024");
extern short Level31_7A860_D_8006E040 __asm__("D_8006E040");
extern int Level31_7A860_D_8006E044 __asm__("D_8006E044");
extern int Level31_7A860_D_8006E048 __asm__("D_8006E048");
extern int Level31_7A860_D_8006E160 __asm__("D_8006E160");
extern int Level31_7A860_D_8006E164 __asm__("D_8006E164");
extern int Level31_7A860_D_8006E52C __asm__("D_8006E52C");
extern int Level31_7A860_D_8006E530 __asm__("D_8006E530");
extern int Level31_7A860_D_80070300 __asm__("D_80070300");
extern int Level31_7A860_D_80070328 __asm__("D_80070328");
extern unsigned char Level31_7A860_D_80072018 __asm__("D_80072018");
extern int Level31_7A860_D_80072034 __asm__("D_80072034");
extern unsigned char Level31_7A860_D_80072046 __asm__("D_80072046");
extern int Level31_7A860_D_80072048 __asm__("D_80072048");
extern int Level31_7A860_D_8007204C __asm__("D_8007204C");
extern unsigned char Level31_7A860_D_80072056 __asm__("D_80072056");
extern unsigned char Level31_7A860_D_80072057 __asm__("D_80072057");
extern int (*Level31_7A860_SpawnParticle)() __asm__("SpawnParticle");
extern int Level31_7A860_func_8005E9B0 __asm__("func_8005E9B0");
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned int low;
#else
        unsigned int low;
        int high;
#endif
    } words;
} Level31_7A860Product;
#define Level31_7A860Low(a, b)                                                                     \
    ({                                                                                             \
        int x = (a), y = (b);                                                                      \
        Level31_7A860Product p;                                                                    \
        p.full = (long long)x * (long long)y;                                                      \
        __asm__("" : "=x"(p.full) : "0"(p.full));                                                  \
        (int)p.words.low;                                                                          \
    })
void func_level_31_8007A860(void *ownerInput) {
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
    register int owner __asm__("$19");
    register int privateState __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int saved23 __asm__("$23");
    register int temporary24 __asm__("$24");
    register int temporary25 __asm__("$25");
    int retainedValue, outgoingWord5, outgoingWord6;
    struct {
        int sp18;
        int sp1C;
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
        int sp88;
        int sp8C;
        int sp90;
        int sp94;
        int sp98;
        int sp9C;
        int spA0;
        int spA4;
        int spA8;
        int spAC;
        int spB0;
        int spB4;
        int spB8;
        int spBC;
        int spC0;
        int spC4;
        int spC8;
        int spCC;
        int spD0;
        int spD4;
        int spD8;
        int spDC;
        int spE0;
        int spE4;
        int spE8;
        int spEC;
        int spF0;
        int spF4;
    } locals;
    Level31_7A860Product wholeProduct611, wholeProduct615, wholeProduct627, wholeProduct631,
        wholeProduct737, wholeProduct745;
    /* Proposed original machine-memory inputs only: existing SP20/SP24.
     * Full32 bits, same mutable locals cells, no numeric default or new CPU/ABI.
     * UNINSTALLED: actual MEM lowering and all source/native/full gates pending. */
    __asm__("" : "=m"(locals.sp20), "=m"(locals.sp24));
    owner = (int)ownerInput;
    Level31_7A860Keep(owner);
    argument0 = (int)ownerInput;
    temporary3 = (int)&Level31_7A860_D_8006E160;
    Level31_7A860Keep(temporary3);
    temporary2 = Level31_7A860Field(temporary3, int *, 0);
    Level31_7A860Keep(temporary2);
    privateState = Level31_7A860Field(owner, int *, 0);
    Level31_7A860Keep(privateState);
    if (temporary2 != 0)
        goto original1913_24;
    __asm__ volatile("" ::"r"(owner) : "$2");
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C568, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 34, 1) : (temporary2 = 0 + 34, 0))
        goto original1913_24;
    Level31_7A860Field(temporary3, int *, 0) = temporary2;

    Level31_7A860Field((int)&Level31_7A860_D_8006E164, int *, 0) = owner;
original1913_24:
    temporary2 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + -15;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_35;
    argument1 = 0 + 6;
    __asm__ volatile("" ::"r"(argument1) : "$2");
    argument2 = 0 + 0;
    __asm__("" : "=r"(argument2) : "0"(argument2), "r"(argument1));
    argument3 = 0 + 0;
    Level31_7A860_func_8003573C(argument0, argument1, argument2, argument3);
    argument0 = owner + 0;
original1913_35:
    argument1 = 0 + 4;
    Level31_7A860_func_80055D24(argument0, argument1);
    argument0 = (int)&Level31_7A860_D_80072018;
    Level31_7A860Keep(argument0);
    temporary2 = Level31_7A860Field(argument0, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 != 0)
        goto original1913_59;
    __asm__ volatile("" ::"r"(owner) : "$2");
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 4;
    if (temporary2 != 0)
        goto original1913_554;
    __asm__ volatile("" ::"r"(owner) : "$2");
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C58C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 =
        Level31_7A860Field(((int)&Level31_7A860_D_80070300 + temporary2), unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 4;
    if (temporary2 != 0)
        goto original1913_554;
    __asm__ volatile("" ::"r"(owner) : "$2");
original1913_59:
    saved16 = 0 + 1;
    Level31_7A860_func_8003A908(argument0);

    Level31_7A860Field((int)&Level31_7A860_D_80072046, unsigned char *, 0) = saved16;
    temporary3 = Level31_7A860Field(owner, unsigned char *, 73);
    Level31_7A860Keep(temporary3);
    saved17 = 0 + 1;
    if (temporary3 == saved17 ? (temporary2 = temporary3 < 2, 1) : (temporary2 = temporary3 < 2, 0))
        goto original1913_362;
    Level31_7A860Keep(temporary3);
    if (temporary2 == 0)
        goto original1913_73;
    saved16 = (int)&locals.sp20;
    if (temporary3 == 0)
        goto original1913_80;

    goto original1913_534;
original1913_73:
    temporary2 = 0 + 2;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original1913_500;
    if (temporary3 == temporary2)
        goto original1913_517;

    goto original1913_534;
original1913_80:
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument2 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument2);
    argument1 = owner + 12;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    Level31_7A860Field(&locals.sp18, int *, 16) = 0;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    saved18 = temporary2 + 0;
    argument0 = privateState + 16;
    argument1 = 0 + 4;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    if (temporary2 == 0 ? (temporary2 = saved18 < 2240, 1) : (temporary2 = saved18 < 2240, 0))
        goto original1913_206;
    if (temporary2 == 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1913_318;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2)
        goto original1913_104;
    saved16 = 0 + 64;
    goto original1913_107;
original1913_104:
    saved16 = 0 + 128;
    if (temporary3 != saved17)
        goto original1913_107;
    saved16 = 0 + 80;
original1913_107:

    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 255;
    temporary2 = temporary2 < saved16;
    if (temporary2 == 0 ? (temporary2 = 0 + 139, 1) : (temporary2 = 0 + 139, 0))
        goto original1913_140;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2)
        goto original1913_126;
    __asm__ volatile("" ::"r"(temporary3));
    temporary2 = (int)&Level31_7A860_D_80072048;
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = temporary3 | 64;
    __asm__ volatile("" ::"r"(temporary3), "r"(argument0));
    argument0 = argument0 | 64;
    goto original1913_174;
original1913_126:

    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 255;
    temporary2 = temporary2 < 170;
    if (temporary2 == 0)
        goto original1913_167;
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)&Level31_7A860_D_80072048;
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = temporary3 | 128;
    __asm__ volatile("" ::"r"(temporary3), "r"(argument0));
    argument0 = argument0 | 128;
    goto original1913_174;
original1913_140:
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2)
        goto original1913_153;
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)&Level31_7A860_D_80072048;
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = temporary3 | 64;
    __asm__ volatile("" ::"r"(temporary3), "r"(argument0));
    argument0 = argument0 | 64;
    goto original1913_174;
original1913_153:

    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 255;
    temporary2 = temporary2 < 170;
    if (temporary2 == 0)
        goto original1913_167;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary2 = (int)&Level31_7A860_D_80072048;
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = temporary3 | 128;
    __asm__ volatile("" ::"r"(temporary3), "r"(argument0));
    argument0 = argument0 | 128;
    goto original1913_174;
original1913_167:
    temporary2 = (int)&Level31_7A860_D_80072048;
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = temporary3 | 32;
    __asm__ volatile("" ::"r"(temporary3), "r"(argument0));
    argument0 = argument0 | 32;
original1913_174:
    Level31_7A860Field(temporary2, int *, 0) = temporary3;

    Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0) = argument0;
    __asm__ volatile("" ::"r"(argument0) : "$2", "memory");
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 2;
    if (temporary2 == 0 ? (argument0 = 0 + 30, 1) : (argument0 = 0 + 30, 0))
        goto original1913_185;
    argument1 = 0 + 75;
    goto original1913_186;
original1913_185:
    argument1 = 0 + 105;
original1913_186:

    temporary2 = Level31_7A860_func_8003636C(argument0, argument1);
    Level31_7A860Keep(temporary2);
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1913_199;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + 10;
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    goto original1913_318;
original1913_199:
    if (temporary3 != 0 ? (saved17 = (int)&locals.sp20, 1) : (saved17 = (int)&locals.sp20, 0))
        goto original1913_319;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + 30;
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    goto original1913_319;
original1913_206:
    if (temporary2 == 0)
        goto original1913_318;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 + -136;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 == 0 ? (temporary2 = 0 + 138, 1) : (temporary2 = 0 + 138, 0))
        goto original1913_264;
    temporary2 = Level31_7A860Field(privateState, int *, 32);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1913_318;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2)
        goto original1913_226;
    saved16 = 0 + 170;
    goto original1913_229;
original1913_226:
    saved16 = 0 + 96;
    if (temporary3 != saved17)
        goto original1913_229;
    saved16 = 0 + 149;
original1913_229:

    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 255;
    temporary2 = temporary2 < saved16;
    if (temporary2 == 0)
        goto original1913_315;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 2;
    argument0 = 0 + 0;
    if (temporary2 == 0)
        goto original1913_243;
    argument1 = 0 + 30;
    goto original1913_244;
original1913_243:
    __asm__ volatile("" ::"r"(owner) : "$2");
    argument1 = 0 + 45;
original1913_244:

    temporary2 = Level31_7A860_func_8003636C(argument0, argument1);
    Level31_7A860Keep(temporary2);
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1913_255;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);
    temporary2 = temporary2 + 10;
    goto original1913_260;
original1913_255:
    if (temporary3 != 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1913_262;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + 30;
original1913_260:
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary2 = 0 + 2;
original1913_262:
    Level31_7A860Field(owner, unsigned char *, 73) = temporary2;
    goto original1913_318;
original1913_264:
    if (temporary3 != temporary2)
        goto original1913_317;
    temporary2 = Level31_7A860Field(privateState, int *, 32);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1913_318;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2)
        goto original1913_277;
    saved16 = 0 + 170;
    goto original1913_280;
original1913_277:
    saved16 = 0 + 96;
    if (temporary3 != saved17)
        goto original1913_280;
    saved16 = 0 + 149;
original1913_280:

    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 255;
    temporary2 = temporary2 < saved16;
    if (temporary2 == 0)
        goto original1913_315;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 2;
    argument0 = 0 + 0;
    if (temporary2 == 0)
        goto original1913_294;
    argument1 = 0 + 30;
    goto original1913_295;
original1913_294:
    __asm__ volatile("" ::"r"(owner) : "$2");
    argument1 = 0 + 45;
original1913_295:

    temporary2 = Level31_7A860_func_8003636C(argument0, argument1);
    Level31_7A860Keep(temporary2);
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1913_306;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);
    temporary2 = temporary2 + 10;
    goto original1913_311;
original1913_306:
    if (temporary3 != 0 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original1913_313;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + 30;
original1913_311:
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary2 = 0 + 3;
original1913_313:
    Level31_7A860Field(owner, unsigned char *, 73) = temporary2;
    goto original1913_318;
original1913_315:
    Level31_7A860Field(privateState, int *, 32) = 0;
    goto original1913_318;
original1913_317:
    Level31_7A860Field(privateState, int *, 32) = saved17;
original1913_318:
    saved17 = (int)&locals.sp20;
original1913_319:
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved18 + 0;
    Level31_7A860Keep(argument1);
    argument2 = 0 + 1728;
    Level31_7A860_func_8004F08C(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument1 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument1);
    argument2 = saved17 + 0;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved17 + 0;
    Level31_7A860Keep(argument1);
    argument2 = owner + 12;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    Level31_7A860Field(&locals.sp18, int *, 16) = 0;
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    saved18 = temporary2 + 0;
    temporary2 = saved18 < 257;
    if (temporary2 != 0 ? (argument0 = saved17 + 0, 1) : (argument0 = saved17 + 0, 0))
        goto original1913_353;
    argument1 = saved18 + 0;
    Level31_7A860Keep(argument1);
    argument2 = 0 + 127;
    Level31_7A860_func_8004F08C(argument0, argument1, argument2);
    saved16 = (int)&locals.sp30;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$5");
    argument1 = owner + 32;
    Level31_7A860_func_8004ECF4(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved17 + 0;
    Level31_7A860Keep(argument1);
    argument2 = argument1 + 0;
    Level31_7A860_func_8004ED6C(argument0, argument1, argument2);

    goto original1913_355;
original1913_353:
    argument0 = saved17 + 0;
    Level31_7A860_func_8004F168(argument0);
original1913_355:
    temporary2 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 < 151;
    if (temporary2 != 0 ? (temporary2 = 0 + 1, 1) : (temporary2 = 0 + 1, 0))
        goto original1913_534;
    Level31_7A860Field(owner, unsigned char *, 73) = temporary2;
    goto original1913_534;
original1913_362:
    saved16 = (int)&locals.sp20;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument2 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument2);
    argument1 = owner + 12;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    Level31_7A860Field(&locals.sp18, int *, 16) = 0;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    saved18 = temporary2 + 0;
    temporary2 = saved18 < 2560;
    if (temporary2 == 0)
        goto original1913_411;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + -136;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 == 0)
        goto original1913_411;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 2;
    argument0 = 0 + 0;
    if (temporary2 == 0)
        goto original1913_391;
    argument1 = 0 + 30;
    goto original1913_392;
original1913_391:
    __asm__ volatile("" ::"r"(owner) : "$2");
    argument1 = 0 + 45;
original1913_392:

    temporary2 = Level31_7A860_func_8003636C(argument0, argument1);
    Level31_7A860Keep(temporary2);
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1913_403;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);
    temporary2 = temporary2 + 10;
    goto original1913_408;
original1913_403:
    if (temporary3 != 0 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1913_410;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + 30;
original1913_408:
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary2 = 0 + 2;
original1913_410:
    Level31_7A860Field(owner, unsigned char *, 73) = temporary2;
original1913_411:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C640, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0)
        goto original1913_433;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C54C, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_433;
    __asm__ volatile("" ::"r"(owner) : "$2");
    saved16 = 0 + 0;
    saved17 = (int)&Level31_7A860_func_8005E9B0;
    Level31_7A860Keep(saved17);
original1913_424:
    saved16 = saved16 + 1;
    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 63;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 + saved17;
    Level31_7A860Field(temporary2, int *, 0) = 0;
    temporary2 = saved16 < 6;
    if (temporary2 != 0)
        goto original1913_424;
original1913_433:
    temporary2 = saved18 < 2560;
    if (temporary2 == 0 ? (temporary2 = 0 + 138, 1) : (temporary2 = 0 + 138, 0))
        goto original1913_469;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = saved18 < 4096, 1)
                                 : (temporary2 = saved18 < 4096, 0))
        goto original1913_470;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 2;
    argument0 = 0 + 0;
    if (temporary2 == 0)
        goto original1913_448;
    argument1 = 0 + 30;
    goto original1913_449;
original1913_448:
    __asm__ volatile("" ::"r"(owner) : "$2");
    argument1 = 0 + 45;
original1913_449:

    temporary2 = Level31_7A860_func_8003636C(argument0, argument1);
    Level31_7A860Keep(temporary2);
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C7C4, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 1;
    if (temporary3 != temporary2)
        goto original1913_460;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);
    temporary2 = temporary2 + 10;
    goto original1913_465;
original1913_460:
    if (temporary3 != 0 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original1913_467;
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + 30;
original1913_465:
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    temporary2 = 0 + 3;
original1913_467:
    Level31_7A860Field(owner, unsigned char *, 73) = temporary2;
    goto original1913_493;
original1913_469:
    temporary2 = saved18 < 4096;
original1913_470:
    if (temporary2 == 0 ? (saved17 = (int)&locals.sp20, 1) : (saved17 = (int)&locals.sp20, 0))
        goto original1913_491;
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument2 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument2);
    argument1 = owner + 12;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    Level31_7A860Field(&locals.sp18, int *, 16) = 0;
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 127;
    Level31_7A860_func_8004EF04(argument0, argument1);
    saved16 = (int)&locals.sp30;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$5");
    argument1 = owner + 32;
    Level31_7A860_func_8004ECF4(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved17 + 0;
    Level31_7A860Keep(argument1);
    argument2 = argument1 + 0;
    Level31_7A860_func_8004ED6C(argument0, argument1, argument2);

    goto original1913_493;
original1913_491:
    argument0 = (int)&locals.sp20;
    Level31_7A860_func_8004F168(argument0);
original1913_493:
    temporary2 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 < 50;
    if (temporary2 == 0)
        goto original1913_534;
original1913_498:
    Level31_7A860Field(owner, unsigned char *, 73) = 0;
    goto original1913_534;
original1913_500:
    temporary2 = Level31_7A860_D_80072048;
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 | 16;

    Level31_7A860_D_80072048 = temporary2;
    __asm__ volatile("" ::"r"(temporary2) : "memory");
    argument0 = (int)&locals.sp20;
    Level31_7A860_func_8004F168(argument0);
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + -136;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 != 0 ? (argument0 = privateState + 16, 1) : (argument0 = privateState + 16, 0))
        goto original1913_534;

    goto original1913_524;
original1913_517:
    argument0 = (int)&locals.sp20;
    Level31_7A860_func_8004F168(argument0);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 138;
    if (temporary3 == temporary2 ? (argument0 = privateState + 16, 1)
                                 : (argument0 = privateState + 16, 0))
        goto original1913_534;
original1913_524:
    argument1 = 0 + 4;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    if (temporary2 == 0)
        goto original1913_534;
    temporary2 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 < 150;
    if (temporary2 != 0)
        goto original1913_498;
    Level31_7A860Field(owner, unsigned char *, 73) = saved16;
original1913_534:
    temporary3 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(temporary3);
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(temporary2);
    if (temporary3 >= 0)
        goto original1913_539;
    temporary3 = 0 - temporary3;
original1913_539:
    if (temporary2 >= 0)
        goto original1913_542;
    temporary2 = 0 - temporary2;
original1913_542:
    temporary2 = temporary2 < temporary3;
    if (temporary2 == 0)
        goto original1913_547;
    Level31_7A860Field(&locals.sp18, int *, 12) = 0;
    goto original1913_548;
original1913_547:
    __asm__("" : "=r"(temporary2) : "0"(temporary2));
    Level31_7A860Field(&locals.sp18, int *, 8) = 0;
original1913_548:
    argument0 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(argument0);
    argument1 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(argument1);
    argument2 = 0 + 1;
    temporary2 = Level31_7A860_func_8004E880(argument0, argument1, argument2);
    temporary2 = temporary2 + 512;
    goto original1913_654;
original1913_554:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072046, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0)
        goto original1913_569;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072056, unsigned char *, 0);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80072057, unsigned char *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = temporary2 + -127;
    Level31_7A860Field(&locals.sp18, int *, 0) = temporary2;
    temporary2 = 0 + 127;
    temporary2 = temporary2 - temporary3;
    Level31_7A860Field(&locals.sp18, int *, 4) = temporary2;
    goto original1913_597;
original1913_569:
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 & 4096;
    if (temporary2 == 0 ? (temporary2 = 0 + 127, 1) : (temporary2 = 0 + 127, 0))
        goto original1913_577;
    Level31_7A860Field(&locals.sp18, int *, 4) = temporary2;
    goto original1913_583;
original1913_577:
    temporary2 = temporary3 & 16384;
    if (temporary2 == 0 ? (temporary2 = 0 + -127, 1) : (temporary2 = 0 + -127, 0))
        goto original1913_582;
    Level31_7A860Field(&locals.sp18, int *, 4) = temporary2;
    goto original1913_583;
original1913_582:
    Level31_7A860Field(&locals.sp18, int *, 4) = 0;
original1913_583:
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 & 8192;
    if (temporary2 == 0 ? (temporary2 = 0 + 127, 1) : (temporary2 = 0 + 127, 0))
        goto original1913_591;
    Level31_7A860Field(&locals.sp18, int *, 0) = temporary2;
    goto original1913_597;
original1913_591:
    temporary2 = temporary3 & 32768;
    if (temporary2 == 0 ? (temporary2 = 0 + -127, 1) : (temporary2 = 0 + -127, 0))
        goto original1913_596;
    Level31_7A860Field(&locals.sp18, int *, 0) = temporary2;
    goto original1913_597;
original1913_596:
    Level31_7A860Field(&locals.sp18, int *, 0) = 0;
original1913_597:
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006E040, short *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    temporary2 = temporary2 - temporary3;
    saved18 = temporary2 & 4095;
    argument0 = saved18 + 0;
    temporary2 = Level31_7A860_func_8004EA2C(argument0);
    argument0 = saved18 + 0;
    Level31_7A860Keep(argument0);
    saved16 = temporary2 + 0;
    temporary2 = Level31_7A860_func_8004E9E4(argument0);
    temporary3 = Level31_7A860Field(&locals.sp18, volatile int *, 0);
    Level31_7A860Keep(temporary3);

    temporary3 = 0 - temporary3;
    Level31_7A860Keep(temporary3);
    Level31_7A860Keep(saved16);
    wholeProduct611.full = (long long)temporary3 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct611.full) : "0"(wholeProduct611.full));
    argument1 = (int)wholeProduct611.words.low;
    Level31_7A860Keep(argument1);
    __asm__ volatile("" : "=r"(argument1) : "0"(argument1) : "memory");
    temporary3 = Level31_7A860Field(&locals.sp18, volatile int *, 4);
    Level31_7A860Keep(temporary3);

    Level31_7A860Keep(temporary3);
    Level31_7A860Keep(temporary2);
    wholeProduct615.full = (long long)temporary3 * (long long)temporary2;
    __asm__("" : "=x"(wholeProduct615.full) : "0"(wholeProduct615.full));
    argument0 = saved18 + 0;
    Level31_7A860Keep(argument0);
    temporary3 = (int)wholeProduct615.words.low;
    Level31_7A860Keep(temporary3);
    temporary2 = argument1 - temporary3;
    temporary2 = (temporary2 >> 12);
    Level31_7A860Field(&locals.sp18, int *, 8) = temporary2;
    temporary2 = Level31_7A860_func_8004EA2C(argument0);
    argument0 = saved18 + 0;
    Level31_7A860Keep(argument0);
    saved16 = temporary2 + 0;
    temporary2 = Level31_7A860_func_8004E9E4(argument0);
    temporary3 = Level31_7A860Field(&locals.sp18, volatile int *, 4);
    Level31_7A860Keep(temporary3);

    Level31_7A860Keep(temporary3);
    Level31_7A860Keep(saved16);
    wholeProduct627.full = (long long)temporary3 * (long long)saved16;
    __asm__("" : "=x"(wholeProduct627.full) : "0"(wholeProduct627.full));
    argument0 = (int)wholeProduct627.words.low;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0) : "memory");
    temporary3 = Level31_7A860Field(&locals.sp18, volatile int *, 0);
    Level31_7A860Keep(temporary3);

    Level31_7A860Keep(temporary3);
    Level31_7A860Keep(temporary2);
    wholeProduct631.full = (long long)temporary3 * (long long)temporary2;
    __asm__("" : "=x"(wholeProduct631.full) : "0"(wholeProduct631.full));
    temporary3 = (int)wholeProduct631.words.low;
    Level31_7A860Keep(temporary3);
    temporary2 = argument0 - temporary3;
    temporary3 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level31_7A860Field(&locals.sp18, int *, 12) = temporary2;
    __asm__ volatile("" ::"r"(temporary2), "m"(Level31_7A860Field(&locals.sp18, int *, 12))
                     : "memory");
    if (temporary2 >= 0)
        goto original1913_640;
    temporary2 = 0 - temporary2;
original1913_640:
    if (temporary3 >= 0)
        goto original1913_643;
    temporary3 = 0 - temporary3;
original1913_643:
    temporary2 = temporary2 < temporary3;
    if (temporary2 == 0)
        goto original1913_648;
    Level31_7A860Field(&locals.sp18, int *, 12) = 0;
    goto original1913_649;
original1913_648:
    __asm__("" : "=r"(temporary2) : "0"(temporary2));
    Level31_7A860Field(&locals.sp18, int *, 8) = 0;
original1913_649:
    argument0 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(argument0);
    argument1 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(argument1);
    argument2 = 0 + 1;
    temporary2 = Level31_7A860_func_8004E880(argument0, argument1, argument2);
    temporary2 = temporary2 + -512;
original1913_654:
    saved18 = temporary2 & 4095;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C568, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_662;
    argument0 = (int)&locals.sp20;
    Level31_7A860_func_8004F168(argument0);
original1913_662:
    temporary2 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C648, int *, 0);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary2 - temporary3;
    Level31_7A860Field(privateState, int *, 12) = temporary2;
    if (temporary2 >= 0)
        goto original1913_670;
    Level31_7A860Field(privateState, int *, 12) = 0;
original1913_670:
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 8;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1913_682;
    temporary2 = Level31_7A860Field(owner, unsigned char *, 60);
    Level31_7A860Keep(temporary2);

    if (temporary2 != temporary3 ? (saved17 = 0 + 3, 1) : (saved17 = 0 + 3, 0))
        goto original1913_704;
    temporary2 = Level31_7A860Field(owner, int *, 24);
    Level31_7A860Keep(temporary2);
    saved17 = 0 + 4;
    temporary2 = temporary2 & 3;
    goto original1913_687;
original1913_682:
    if (temporary3 != temporary2 ? (saved17 = 0 + 7, 1) : (saved17 = 0 + 7, 0))
        goto original1913_704;
    temporary2 = Level31_7A860Field(owner, int *, 24);
    Level31_7A860Keep(temporary2);
    saved17 = 0 + 3;
    temporary2 = temporary2 & 4;
original1913_687:
    if (temporary2 == 0 ? (saved16 = privateState + 20, 1) : (saved16 = privateState + 20, 0))
        goto original1913_704;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument2 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument2);
    argument1 = owner + 12;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 2560;
    Level31_7A860Field(privateState, int *, 28) = 0;
    Level31_7A860_func_8004EF04(argument0, argument1);
    temporary2 = 0 + 120;

    Level31_7A860Field((int)&Level31_7A860_D_8006E530, int *, 0) = temporary2;
    temporary2 = 0 + 10;

    Level31_7A860Field((int)&Level31_7A860_D_8006E52C, int *, 0) = temporary2;
original1913_704:
    temporary2 = Level31_7A860Field(owner, int *, 24);
    Level31_7A860Keep(temporary2);
    argument0 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(argument0);
    argument1 = temporary2 & saved17;
    temporary3 = argument0 & 255;
    temporary2 = 0 + 17;
    Level31_7A860Field(owner, int *, 24) = argument1;
    if (temporary3 == temporary2)
        goto original1913_827;
    temporary2 = argument0 + -9;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 != 0)
        goto original1913_827;
    if (argument1 == 0)
        goto original1913_827;
    temporary2 = Level31_7A860Field(privateState, int *, 0);
    Level31_7A860Keep(temporary2);

    saved17 = 0 + 0;
    if (temporary2 != 0)
        goto original1913_827;
    saved22 = (int)&Level31_7A860_D_80065920;
    Level31_7A860Keep(saved22);
    saved21 = (int)&Level31_7A860_D_800658A0;
    Level31_7A860Keep(saved21);
original1913_725:
    saved17 = saved17 + 1;
    temporary2 = Level31_7A860_rand();
    saved16 = temporary2 & 255;
    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 255;
    saved16 = (int)((unsigned int)saved16 << 1);
    temporary3 = saved16 + saved22;
    Level31_7A860Keep(temporary3);
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2), "r"(temporary3));
    temporary2 = (int)((unsigned int)temporary2 << 1);
    argument1 = temporary2 + saved22;
    __asm__ volatile("" ::"r"(temporary3), "r"(argument1) : "memory");
    temporary3 = Level31_7A860Field(temporary3, short *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field(argument1, short *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = (temporary3 >> 7);
    Level31_7A860Keep(temporary3);
    Level31_7A860Keep(argument0);
    wholeProduct737.full = (long long)temporary3 * (long long)argument0;
    __asm__("" : "=x"(wholeProduct737.full) : "0"(wholeProduct737.full), "r"(saved16));
    saved16 = saved16 + saved21;
    __asm__("" : "=x"(wholeProduct737.full) : "0"(wholeProduct737.full), "r"(saved16));
    temporary8 = (int)wholeProduct737.words.low;
    Level31_7A860Keep(temporary8);
    temporary3 = (temporary8 >> 12);
    Level31_7A860Field(&locals.sp18, int *, 48) = temporary3;
    temporary3 = Level31_7A860Field(saved16, short *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field(argument1, short *, 0);
    Level31_7A860Keep(argument0);
    temporary3 = (temporary3 >> 7);
    Level31_7A860Keep(temporary3);
    Level31_7A860Keep(argument0);
    wholeProduct745.full = (long long)temporary3 * (long long)argument0;
    __asm__("" : "=x"(wholeProduct745.full) : "0"(wholeProduct745.full));
    argument2 = privateState + 40;
    argument3 = (int)&locals.sp48;
    temporary2 = temporary2 + saved21;
    Level31_7A860Keep(temporary2);
    argument1 = 0 + 0;
    argument0 = 0 + 1;
    __asm__(""
            : "=x"(wholeProduct745.full)
            : "0"(wholeProduct745.full), "r"(temporary2), "r"(argument0), "r"(argument1),
              "r"(argument2), "r"(argument3));
    temporary8 = (int)wholeProduct745.words.low;
    Level31_7A860Keep(temporary8);
    temporary3 = (temporary8 >> 12);
    Level31_7A860Field(&locals.sp18, int *, 52) = temporary3;
    temporary2 = Level31_7A860Field(temporary2, short *, 0);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_SpawnParticle, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = (temporary2 >> 7);
    Level31_7A860Field(&locals.sp18, int *, 56) = temporary2;
    ((int (*)())temporary3)(argument0, argument1, argument2, argument3);
    temporary2 = saved17 < 8;
    if (temporary2 != 0)
        goto original1913_725;
    temporary3 = Level31_7A860Field(owner, int *, 24);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 & 1;
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1913_776;
    argument1 = 0 + 9;
    temporary2 = Level31_7A860Field(privateState, int *, 4);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary3);
    temporary2 = temporary2 + -1;
    temporary3 = temporary3 + 30;
    Level31_7A860Field(privateState, int *, 4) = temporary2;
    __asm__("" : "=r"(argument0) : "0"(argument0), "m"(Level31_7A860Field(privateState, int *, 4)));
    temporary2 = 0 + 9;
    goto original1913_794;
original1913_776:
    temporary2 = temporary3 & 2;
    if (temporary2 == 0 ? (argument1 = 0 + 9, 1) : (argument1 = 0 + 9, 0))
        goto original1913_786;
    temporary2 = Level31_7A860Field(privateState, int *, 4);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary3);
    temporary2 = temporary2 + -3;
    temporary3 = temporary3 + 90;
    Level31_7A860Field(privateState, int *, 4) = temporary2;
    __asm__("" : "=r"(argument1) : "0"(argument1), "m"(Level31_7A860Field(privateState, int *, 4)));
    temporary2 = 0 + 9;
    goto original1913_794;
original1913_786:
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
    argument0 = owner + 0;
    argument1 = 0 + 10;
    temporary2 = Level31_7A860Field(privateState, int *, 4);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field(privateState, int *, 12);
    Level31_7A860Keep(temporary3);
    temporary2 = temporary2 + -2;
    temporary3 = temporary3 + 60;
    Level31_7A860Field(privateState, int *, 4) = temporary2;
    temporary2 = 0 + 10;
original1913_794:
    Level31_7A860Field(privateState, int *, 12) = temporary3;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    Level31_7A860_func_80034F40(argument0, argument1);
    temporary2 = Level31_7A860Field(privateState, int *, 4);
    Level31_7A860Keep(temporary2);

    if (temporary2 >= 0 ? (argument0 = privateState + 4, 1) : (argument0 = privateState + 4, 0))
        goto original1913_802;
    Level31_7A860Field(privateState, int *, 4) = 0;
original1913_802:
    argument2 = (int)&Level31_7A860_D_8006C7F8;
    Level31_7A860Keep(argument2);
    argument1 = 0 + 4;
    Level31_7A860_func_8003B7B4(argument0, argument1, argument2);
    saved16 = privateState + 20;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$5");
    argument1 = owner + 12;
    argument2 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument2);
    temporary2 = 0 + 15;

    Level31_7A860Field((int)&Level31_7A860_D_80072034, int *, 0) = temporary2;
    temporary2 = 0 + 200;

    Level31_7A860Field((int)&Level31_7A860_D_8006E530, int *, 0) = temporary2;
    temporary2 = 0 + 10;

    Level31_7A860Field((int)&Level31_7A860_D_8006E52C, int *, 0) = temporary2;
    temporary2 = 0 + 5;
    Level31_7A860Field(privateState, int *, 0) = temporary2;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 4096;
    Level31_7A860Field(privateState, int *, 28) = 0;
    Level31_7A860_func_8004EF04(argument0, argument1);
original1913_827:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C568, int *, 0);
    Level31_7A860Keep(temporary2);

    Level31_7A860Field(owner, int *, 24) = 0;
    if (temporary2 == 0)
        goto original1913_847;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 72);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 146;
    if (temporary3 != temporary2)
        goto original1913_847;
    temporary2 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + -15;
    temporary2 = (unsigned int)temporary2 < 2;
    if (temporary2 != 0 ? (temporary2 = 0 + 15, 1) : (temporary2 = 0 + 15, 0))
        goto original1913_847;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 15;
    Level31_7A860_func_80034F40(argument0, argument1);
original1913_847:
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    switch ((unsigned int)temporary3) {
    case 0:
        goto original1913_858;
    case 1:
        goto original1913_858;
    case 2:
        goto original1913_858;
    case 3:
        goto original1913_925;
    case 4:
        goto original1913_941;
    case 5:
        goto original1913_1081;
    case 6:
        goto original1913_1204;
    case 7:
        goto original1913_1278;
    case 8:
        goto original1913_1404;
    case 9:
        goto original1913_1571;
    case 10:
        goto original1913_1571;
    case 11:
        goto original1913_1630;
    case 12:
        goto original1913_1630;
    case 13:
        goto original1913_1630;
    case 14:
        goto original1913_1630;
    case 15:
        goto original1913_1843;
    case 16:
        goto original1913_1872;
    case 17:
        goto original1913_1892;
    default:
        goto original1913_1899;
    }
original1913_858:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C568, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1913_1624;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006E044, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 9;
    if (temporary3 != temporary2 ? (temporary2 = 0 + 2, 1) : (temporary2 = 0 + 2, 0))
        goto original1913_879;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006E048, int *, 0);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = 0 + 3, 1) : (temporary2 = 0 + 3, 0))
        goto original1913_879;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 3;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_879:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C7B4, unsigned char *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 4;
    if (temporary2 == 0)
        goto original1913_894;
    temporary2 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1899;
    Level31_7A860Field(owner, unsigned char *, 72) = 0;
    argument1 = 0 + 0;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_894:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1913_1900;
    __asm__ volatile("" ::"r"(argument0));
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_918;

    temporary2 = Level31_7A860_rand();
    temporary2 = temporary2 & 1;
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_910;
    argument1 = 0 + 1;
    goto original1913_911;
original1913_910:
    argument1 = 0 + 2;
original1913_911:

    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = 0 + 1;
    argument1 = 0 + 2;
    temporary2 = Level31_7A860_func_8003636C(argument0, argument1);
    Level31_7A860Keep(temporary2);
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    goto original1913_1899;
original1913_918:
    argument1 = 0 + 0;
    Level31_7A860_func_80034F40(argument0, argument1);
    temporary2 = Level31_7A860Field(privateState, volatile int *, 16);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 + -1;
    Level31_7A860Field(privateState, int *, 16) = temporary2;
    goto original1913_1899;
original1913_925:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C568, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1913_1624;
    temporary3 = Level31_7A860Field(owner, unsigned char *, 61);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 3;
    if (temporary3 != temporary2 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1900;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0)
        goto original1913_1900;

    goto original1913_1625;
original1913_941:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    saved16 = (int)&locals.sp58;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$17");
    saved17 = privateState + 20;
    argument1 = saved17 + 0;
    Level31_7A860_func_8004F178(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    argument1 = temporary2 + 0;
    temporary2 = argument1 < 385;
    if (temporary2 != 0 ? (argument0 = saved17 + 0, 1) : (argument0 = saved17 + 0, 0))
        goto original1913_957;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument2 = 0 + 384;
    Level31_7A860_func_8004F08C(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
original1913_957:
    argument1 = saved17 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved16 + 0;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved17 + 0;
    Level31_7A860_func_8004F178(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 5;
    Level31_7A860_func_8004F110(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = owner + 12;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = 0 + 768;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 33;
    outgoingWord5 = temporary2;
    Level31_7A860_func_80038000(argument0, argument1, argument2, argument3, outgoingWord5);
    argument0 = privateState + 0;
    argument1 = 0 + 4;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    temporary2 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C648, int *, 0);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary2 + temporary3;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = temporary2 < 61;
    if (temporary2 != 0 ? (temporary2 = 0 + 60, 1) : (temporary2 = 0 + 60, 0))
        goto original1913_990;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
original1913_990:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 576);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1900;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original1913_1010;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 15;
    if (temporary2 != 0 ? ({
            argument1 = 0 + 5;
            __asm__ volatile("" : "=r"(argument1) : "0"(argument1));
            1;
        })
                        : (argument1 = 0 + 5, 0))
        goto original1913_1010;
    temporary2 = temporary3 + -15;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
original1913_1008:
    __asm__ volatile("" ::"i"(4));
    temporary2 = 0 + 5;
    goto original1913_1500;
original1913_1010:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 32;
    if (temporary2 == 0)
        goto original1913_1026;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 30;
    if (temporary2 != 0 ? ({
            argument0 = owner + 0;
            __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
            1;
        })
                        : (argument0 = owner + 0, 0))
        goto original1913_1026;
    argument1 = 0 + 6;
    temporary2 = temporary3 + -30;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
original1913_1024:
    __asm__ volatile("" ::"i"(4));
    temporary2 = 0 + 6;
    goto original1913_1500;
original1913_1026:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 64;
    if (temporary2 == 0)
        goto original1913_1037;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 20;
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1496;
original1913_1037:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 16;
    if (temporary2 == 0 ? (temporary2 = 0 + 8, 1) : (temporary2 = 0 + 8, 0))
        goto original1913_1049;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 8;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1049:
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_1057;
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = saved18 < 1024, 1) : (temporary2 = saved18 < 1024, 0))
        goto original1913_1899;
original1913_1057:
    temporary2 = saved18 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1063;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1524;
original1913_1063:
    temporary2 = saved18 + -1024;
    temporary2 = (unsigned int)temporary2 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1071;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1538;
original1913_1071:
    temporary2 = saved18 + -2048;
    temporary2 = (unsigned int)temporary2 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original1913_1558;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original1913_1552;
    temporary2 = saved18 < 3072;
    goto original1913_1559;
original1913_1081:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    argument0 = owner + 0;
    temporary2 = Level31_7A860_func_80055E84(argument0);
    argument0 = privateState + 0;
    argument1 = 0 + 4;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1));
    saved21 = temporary2 + 0;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    temporary2 = saved21 + -1;
    temporary2 = (unsigned int)temporary2 < 3;
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1149;
    temporary3 = Level31_7A860Field(privateState, int *, 36);
    Level31_7A860Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C550, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    saved18 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(saved18);
    argument1 = 0 + 4;
    Level31_7A860_func_80055D24(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 2;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1) : "$16");
    saved16 = (int)&locals.sp68;
    argument2 = saved16 + 0;
    Level31_7A860_func_80055F14(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 3;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1) : "$17");
    saved17 = (int)&locals.sp78;
    argument2 = saved17 + 0;
    Level31_7A860_func_80055F14(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved17 + 0;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 1;
    Level31_7A860_func_8004F110(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 256;
    argument2 = 0 + 1;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 1;
    outgoingWord5 = temporary2;
    outgoingWord6 = owner;
    Level31_7A860_func_8001BA30(argument0, argument1, argument2, argument3, outgoingWord5,
                                outgoingWord6);
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level31_7A860Field(((int)&Level31_7A860_D_80065920 + temporary2), short *, 0);
    Level31_7A860Keep(temporary2);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    temporary2 = (temporary2 >> 4);
    Level31_7A860Field(&locals.sp18, int *, 96) = temporary2;
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);
    argument2 = saved17 + 0;
    Level31_7A860Keep(argument2);
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level31_7A860Field(((int)&Level31_7A860_D_800658A0 + temporary2), short *, 0);
    Level31_7A860Keep(temporary2);
    argument0 = saved18 + 48;
    Level31_7A860Field(&locals.sp18, int *, 104) = 0;
    __asm__ volatile(""
                     : "=r"(temporary2)
                     : "0"(temporary2), "m"(Level31_7A860Field(&locals.sp18, int *, 104))
                     : "memory");
    temporary2 = (temporary2 >> 4);
    Level31_7A860Field(&locals.sp18, int *, 100) = temporary2;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
original1913_1149:
    temporary2 = saved21 < 8;
    if (temporary2 != 0)
        goto original1913_1197;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original1913_1170;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 15;
    if (temporary2 != 0 ? (temporary2 = temporary3 + -15, 1) : (temporary2 = temporary3 + -15, 0))
        goto original1913_1170;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 114;

    Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0) = 0;
    Level31_7A860Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 5;
    goto original1913_1401;
original1913_1170:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 32;
    if (temporary2 == 0)
        goto original1913_1186;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 30;
    if (temporary2 != 0 ? ({
            argument0 = owner + 0;
            __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
            1;
        })
                        : (argument0 = owner + 0, 0))
        goto original1913_1186;
    argument1 = 0 + 6;
    temporary2 = temporary3 + -30;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
original1913_1184:
    __asm__ volatile("" ::"i"(5));
    temporary2 = 0 + 6;
    goto original1913_1500;
original1913_1186:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 64;
    if (temporary2 == 0)
        goto original1913_1197;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 20;
    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1913_1496;
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
original1913_1197:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1913_1900;
    __asm__ volatile("" ::"r"(argument0));
    temporary2 = 0 + 4;
    goto original1913_1624;
original1913_1204:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    argument0 = privateState + 0;
    argument1 = 0 + 4;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1913_1624;
    argument0 = owner + 0;
    temporary2 = Level31_7A860_func_80055E84(argument0);
    temporary2 = temporary2 + -11;
    temporary2 = (unsigned int)temporary2 < 3;
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1899;
    temporary3 = Level31_7A860Field(privateState, int *, 36);
    Level31_7A860Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C550, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    saved18 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(saved18);
    argument1 = 0 + 4;
    Level31_7A860_func_80055D24(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1) : "$16");
    saved16 = (int)&locals.sp88;
    argument2 = saved16 + 0;
    Level31_7A860_func_80055F14(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 1;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1) : "$17");
    saved17 = (int)&locals.sp98;
    argument2 = saved17 + 0;
    Level31_7A860_func_80055F14(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved17 + 0;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 1;
    Level31_7A860_func_8004F110(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 256;
    argument2 = 0 + 1;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 2;
    outgoingWord5 = temporary2;
    outgoingWord6 = owner;
    Level31_7A860_func_8001BA30(argument0, argument1, argument2, argument3, outgoingWord5,
                                outgoingWord6);
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level31_7A860Field(((int)&Level31_7A860_D_80065920 + temporary2), short *, 0);
    Level31_7A860Keep(temporary2);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    temporary2 = (temporary2 >> 4);
    Level31_7A860Field(&locals.sp18, int *, 128) = temporary2;
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);
    argument2 = saved17 + 0;
    Level31_7A860Keep(argument2);
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level31_7A860Field(((int)&Level31_7A860_D_800658A0 + temporary2), short *, 0);
    Level31_7A860Keep(temporary2);
    argument0 = saved18 + 48;
    Level31_7A860Field(&locals.sp18, int *, 136) = 0;
    __asm__ volatile(""
                     : "=r"(temporary2)
                     : "0"(temporary2), "m"(Level31_7A860Field(&locals.sp18, int *, 136))
                     : "memory");
    temporary2 = (temporary2 >> 4);
    Level31_7A860Field(&locals.sp18, int *, 132) = temporary2;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1278:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    argument0 = owner + 0;
    temporary2 = Level31_7A860_func_80055E84(argument0);
    argument0 = privateState + 0;
    argument1 = 0 + 4;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1));
    saved21 = temporary2 + 0;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    temporary2 = saved21 + -3;
    temporary2 = (unsigned int)temporary2 < 3;
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1346;
    temporary3 = Level31_7A860Field(privateState, int *, 36);
    Level31_7A860Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    temporary2 = temporary2 + temporary3;
    temporary2 = (int)((unsigned int)temporary2 << 2);
    temporary2 = temporary2 - temporary3;
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C550, int *, 0);
    Level31_7A860Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    temporary2 = temporary2 + temporary3;
    saved18 = Level31_7A860Field(temporary2, int *, 0);
    Level31_7A860Keep(saved18);
    argument1 = 0 + 4;
    Level31_7A860_func_80055D24(argument0, argument1);
    argument0 = owner + 0;
    argument1 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1) : "$16");
    saved16 = (int)&locals.spA8;
    argument2 = saved16 + 0;
    Level31_7A860_func_80055F14(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = 0 + 1;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1) : "$17");
    saved17 = (int)&locals.spB8;
    argument2 = saved17 + 0;
    Level31_7A860_func_80055F14(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved17 + 0;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 1;
    Level31_7A860_func_8004F110(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 256;
    argument2 = 0 + 1;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 4;
    outgoingWord5 = temporary2;
    outgoingWord6 = owner;
    Level31_7A860_func_8001BA30(argument0, argument1, argument2, argument3, outgoingWord5,
                                outgoingWord6);
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level31_7A860Field(((int)&Level31_7A860_D_80065920 + temporary2), short *, 0);
    Level31_7A860Keep(temporary2);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    temporary2 = (temporary2 >> 4);
    Level31_7A860Field(&locals.sp18, int *, 160) = temporary2;
    temporary2 = Level31_7A860Field(owner, unsigned char *, 70);
    Level31_7A860Keep(temporary2);
    argument2 = saved17 + 0;
    Level31_7A860Keep(argument2);
    temporary2 = (int)((unsigned int)temporary2 << 1);

    temporary2 = Level31_7A860Field(((int)&Level31_7A860_D_800658A0 + temporary2), short *, 0);
    Level31_7A860Keep(temporary2);
    argument0 = saved18 + 48;
    Level31_7A860Field(&locals.sp18, int *, 168) = 0;
    __asm__ volatile(""
                     : "=r"(temporary2)
                     : "0"(temporary2), "m"(Level31_7A860Field(&locals.sp18, int *, 168))
                     : "memory");
    temporary2 = (temporary2 >> 4);
    Level31_7A860Field(&locals.sp18, int *, 164) = temporary2;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
original1913_1346:
    temporary2 = saved21 < 10;
    if (temporary2 != 0)
        goto original1913_1197;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original1913_1365;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 15;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1365;
    argument1 = 0 + 5;
    temporary2 = temporary3 + -15;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 5;
    goto original1913_1380;
original1913_1365:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 32;
    if (temporary2 == 0)
        goto original1913_1384;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 30;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1384;
    argument1 = 0 + 6;
    temporary2 = temporary3 + -30;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 6;
original1913_1380:
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    Level31_7A860_func_80034F40(argument0, argument1);

    goto original1913_1197;
original1913_1384:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 64;
    if (temporary2 == 0)
        goto original1913_1197;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 20;
    if (temporary2 != 0 ? (temporary2 = temporary3 + -20, 1) : (temporary2 = temporary3 + -20, 0))
        goto original1913_1197;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 114;

    Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0) = 0;
    Level31_7A860Field(owner, unsigned char *, 64) = temporary2;
    temporary2 = 0 + 7;
original1913_1401:
    Level31_7A860Field(owner, unsigned char *, 61) = temporary2;
    Level31_7A860Field(owner, unsigned char *, 63) = 0;
    goto original1913_1197;
original1913_1404:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    saved16 = (int)&locals.spC8;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$17");
    saved17 = privateState + 20;
    argument1 = saved17 + 0;
    Level31_7A860_func_8004F178(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    argument1 = temporary2 + 0;
    temporary2 = argument1 < 385;
    if (temporary2 != 0 ? (argument0 = saved17 + 0, 1) : (argument0 = saved17 + 0, 0))
        goto original1913_1420;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument2 = 0 + 384;
    Level31_7A860_func_8004F08C(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
original1913_1420:
    argument1 = saved17 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved16 + 0;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved17 + 0;
    Level31_7A860_func_8004F178(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 5;
    Level31_7A860_func_8004F110(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = owner + 12;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = 0 + 768;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 33;
    outgoingWord5 = temporary2;
    Level31_7A860_func_80038000(argument0, argument1, argument2, argument3, outgoingWord5);
    argument0 = privateState + 0;
    argument1 = 0 + 4;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    temporary2 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C648, int *, 0);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary2 + temporary3;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = temporary2 < 61;
    if (temporary2 != 0 ? (temporary2 = 0 + 60, 1) : (temporary2 = 0 + 60, 0))
        goto original1913_1453;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
original1913_1453:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original1913_1469;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 15;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1469;
    argument1 = 0 + 5;
    temporary2 = temporary3 + -15;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 5;
    goto original1913_1500;
original1913_1469:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 32;
    if (temporary2 == 0)
        goto original1913_1485;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 30;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1485;
    argument1 = 0 + 6;
    temporary2 = temporary3 + -30;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 6;
    goto original1913_1500;
original1913_1485:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 64;
    if (temporary2 == 0)
        goto original1913_1504;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 20;
    argument0 = owner + 0;
    if (temporary2 != 0)
        goto original1913_1504;
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
original1913_1496:
    argument1 = 0 + 7;
    temporary2 = temporary3 + -20;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 7;
original1913_1500:
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1504:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 16;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1900;
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_1518;
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = saved18 < 1024, 1) : (temporary2 = saved18 < 1024, 0))
        goto original1913_1623;
original1913_1518:
    temporary2 = saved18 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1530;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1530;
original1913_1524:
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 11;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1530:
    temporary2 = saved18 + -1024;
    temporary2 = (unsigned int)temporary2 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1544;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1544;
original1913_1538:
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 14;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1544:
    temporary2 = saved18 + -2048;
    temporary2 = (unsigned int)temporary2 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original1913_1558;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original1913_1558;
original1913_1552:
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 12;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1558:
    temporary2 = saved18 < 3072;
original1913_1559:
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1900;
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 13;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    if (temporary3 == temporary2 ? (temporary2 = 0 + 13, 1) : (temporary2 = 0 + 13, 0))
        goto original1913_1900;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 13;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1571:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    saved16 = (int)&locals.spD8;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$17");
    saved17 = privateState + 20;
    argument1 = saved17 + 0;
    Level31_7A860_func_8004F178(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    argument1 = temporary2 + 0;
    temporary2 = argument1 < 385;
    argument0 = saved17 + 0;
    if (temporary2 != 0)
        goto original1913_1587;
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument2 = 0 + 384;
    Level31_7A860_func_8004F08C(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
original1913_1587:
    argument1 = saved17 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved16 + 0;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved17 + 0;
    Level31_7A860_func_8004F178(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 5;
    Level31_7A860_func_8004F110(argument0, argument1);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = owner + 12;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = 0 + 768;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 33;
    outgoingWord5 = temporary2;
    Level31_7A860_func_80038000(argument0, argument1, argument2, argument3, outgoingWord5);
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    argument0 = owner + 0;
    if (temporary2 == 0)
        goto original1913_1900;
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0));
    temporary2 = Level31_7A860Field(privateState, int *, 4);
    Level31_7A860Keep(temporary2);

    if (temporary2 > 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1913_1624;
    temporary2 = 0 + 17;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 17;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1623:
    temporary2 = 0 + 4;
original1913_1624:
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
original1913_1625:
    argument0 = owner + 0;
    argument1 = 0 + 4;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1630:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    argument0 = privateState + 0;
    argument1 = 0 + 4;
    temporary2 = Level31_7A860_func_800359A4(argument0, argument1);
    temporary2 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary2);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006C648, int *, 0);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary2 + temporary3;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = temporary2 < 61;
    if (temporary2 != 0 ? (temporary2 = 0 + 60, 1) : (temporary2 = 0 + 60, 0))
        goto original1913_1643;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
original1913_1643:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 128;
    if (temporary2 == 0)
        goto original1913_1660;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 15;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1660;
    argument1 = 0 + 5;
    temporary2 = temporary3 + -15;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 5;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    goto original1913_1773;
original1913_1660:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 32;
    if (temporary2 == 0)
        goto original1913_1677;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 30;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1677;
    argument1 = 0 + 6;
    temporary2 = temporary3 + -30;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 6;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    goto original1913_1773;
original1913_1677:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8007204C, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 64;
    if (temporary2 == 0)
        goto original1913_1694;
    temporary3 = Level31_7A860Field(privateState, int *, 8);
    Level31_7A860Keep(temporary3);

    temporary2 = temporary3 < 20;
    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1913_1694;
    argument1 = 0 + 7;
    temporary2 = temporary3 + -20;
    Level31_7A860Field(privateState, int *, 8) = temporary2;
    temporary2 = 0 + 7;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    goto original1913_1773;
original1913_1694:
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_80072048, int *, 0);
    Level31_7A860Keep(temporary2);

    temporary2 = temporary2 & 16;
    if (temporary2 == 0 ? (temporary2 = 0 + 8, 1) : (temporary2 = 0 + 8, 0))
        goto original1913_1704;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 8;
    goto original1913_1773;
original1913_1704:
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_1729;
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_1721;
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 4, 1) : (temporary2 = 0 + 4, 0))
        goto original1913_1721;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 4;
    goto original1913_1773;
original1913_1721:
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 8);
    Level31_7A860Keep(temporary2);

    if (temporary2 != 0)
        goto original1913_1729;
    temporary2 = Level31_7A860Field(&locals.sp18, volatile int *, 12);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = saved18 < 1024, 1) : (temporary2 = saved18 < 1024, 0))
        goto original1913_1775;
original1913_1729:
    temporary2 = saved18 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1739;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1739;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 11;
    goto original1913_1773;
original1913_1739:
    temporary2 = saved18 + -1024;
    temporary2 = (unsigned int)temporary2 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1751;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1751;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 14;
    goto original1913_1773;
original1913_1751:
    temporary2 = saved18 + -2048;
    temporary2 = (unsigned int)temporary2 < 1024;
    if (temporary2 == 0 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original1913_1763;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 12, 1) : (temporary2 = 0 + 12, 0))
        goto original1913_1763;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 12;
    goto original1913_1773;
original1913_1763:
    temporary2 = saved18 < 3072;
    if (temporary2 != 0 ? (temporary2 = 0 + 13, 1) : (temporary2 = 0 + 13, 0))
        goto original1913_1775;
    __asm__ volatile("" : "=r"(temporary2) : "0"(temporary2));
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = 0 + 13, 1) : (temporary2 = 0 + 13, 0))
        goto original1913_1775;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 13;
original1913_1773:

    Level31_7A860_func_80034F40(argument0, argument1);
original1913_1775:
    argument0 = (int)&locals.sp20;
    Level31_7A860_func_8004F168(argument0);
    temporary3 = Level31_7A860Field(owner, unsigned char *, 72);
    Level31_7A860Keep(temporary3);
    temporary2 = 0 + 12;
    if (temporary3 == temporary2 ? (temporary2 = temporary3 < 13, 1)
                                 : (temporary2 = temporary3 < 13, 0))
        goto original1913_1796;
    if (temporary2 == 0 ? (temporary2 = 0 + 11, 1) : (temporary2 = 0 + 11, 0))
        goto original1913_1787;
    if (temporary3 == temporary2)
        goto original1913_1794;
    temporary2 = 0 + 80;
    __asm__ volatile("" ::"r"(temporary2));
    argument0 = owner + 32;
    goto original1913_1802;
original1913_1787:
    temporary2 = 0 + 13;
    if (temporary3 == temporary2 ? (temporary2 = 0 + 14, 1) : (temporary2 = 0 + 14, 0))
        goto original1913_1799;
    if (temporary3 == temporary2)
        goto original1913_minus80_taken;
    temporary2 = 0 + -80;
    __asm__ volatile("" ::"r"(temporary2));
    argument0 = owner + 32;
    goto original1913_1802;
original1913_1794:
    temporary2 = 0 + 80;
    Level31_7A860Field(&locals.sp18, int *, 8) = temporary2;
    goto original1913_1801;
original1913_1796:
    temporary2 = 0 + -80;
    Level31_7A860Field(&locals.sp18, int *, 8) = temporary2;
    goto original1913_1801;
original1913_1799:
    temporary2 = 0 + 80;
    goto original1913_1800;
original1913_minus80_taken:
    temporary2 = 0 + -80;
original1913_1800:
    Level31_7A860Field(&locals.sp18, int *, 12) = temporary2;
original1913_1801:
    argument0 = owner + 32;
original1913_1802:
    saved16 = (int)&locals.sp20;
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved16 + 0;
    Level31_7A860_func_8004ED6C(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    __asm__ volatile("" ::"r"(argument0) : "$5");
    argument1 = owner + 12;
    argument2 = saved16 + 0;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
    saved17 = (int)&locals.spE8;
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument2 = (int)&Level31_7A860_D_80070328;
    Level31_7A860Keep(argument2);
    argument1 = saved16 + 0;
    Level31_7A860_func_8004F1C8(argument0, argument1, argument2);
    argument0 = saved17 + 0;
    Level31_7A860Keep(argument0);
    argument1 = 0 + 0;
    Level31_7A860Field(&locals.sp18, int *, 216) = 0;
    temporary2 = Level31_7A860_func_8004EDE8(argument0, argument1);
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_80070328, int *, 68);
    Level31_7A860Keep(temporary3);
    argument1 = temporary2 + 0;
    temporary2 = temporary3 + 1024;
    temporary2 = argument1 < temporary2;
    if (temporary2 == 0 ? (argument0 = saved17 + 0, 1) : (argument0 = saved17 + 0, 0))
        goto original1913_1834;
    argument2 = argument1 + -1024;
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2));
    argument2 = temporary3 - argument2;
    Level31_7A860_func_8004F08C(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level31_7A860Keep(argument0);
    argument1 = saved16 + 0;
    Level31_7A860Keep(argument1);
    argument2 = saved17 + 0;
    Level31_7A860_func_8004F194(argument0, argument1, argument2);
original1913_1834:
    temporary2 = 0 + 33;
    Level31_7A860_func_80038000(owner, saved16, 768, 0, temporary2);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1843:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    argument2 = 0 + 0;
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2));
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006E020, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field(owner, int *, 12);
    Level31_7A860Keep(argument0);
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006E024, int *, 0);
    Level31_7A860Keep(temporary2);
    argument1 = Level31_7A860Field(owner, int *, 16);
    Level31_7A860Keep(argument1);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level31_7A860_func_8004E880(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 1;
    outgoingWord5 = temporary2;
    outgoingWord6 = 0;
    Level31_7A860_func_8003585C(argument0, argument1, argument2, argument3, outgoingWord5,
                                outgoingWord6);
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + 16, 1) : (temporary2 = 0 + 16, 0))
        goto original1913_1899;
    Level31_7A860Field(owner, unsigned char *, 72) = temporary2;
    argument0 = owner + 0;
    argument1 = 0 + 16;
    Level31_7A860_func_80034F40(argument0, argument1);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1872:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    argument2 = 0 + 0;
    __asm__ volatile("" : "=r"(argument2) : "0"(argument2));
    temporary3 = Level31_7A860Field((int)&Level31_7A860_D_8006E020, int *, 0);
    Level31_7A860Keep(temporary3);
    argument0 = Level31_7A860Field(owner, int *, 12);
    Level31_7A860Keep(argument0);
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006E024, int *, 0);
    Level31_7A860Keep(temporary2);
    argument1 = Level31_7A860Field(owner, int *, 16);
    Level31_7A860Keep(argument1);
    argument0 = temporary3 - argument0;
    argument1 = temporary2 - argument1;
    temporary2 = Level31_7A860_func_8004E880(argument0, argument1, argument2);
    argument0 = owner + 0;
    argument1 = temporary2 + 0;
    argument2 = 0 + 6;
    argument3 = 0 + 0;
    __asm__ volatile("" ::"r"(argument0), "r"(argument1), "r"(argument2), "r"(argument3) : "$2");
    temporary2 = 0 + 1;
    outgoingWord5 = temporary2;
    outgoingWord6 = 0;
    Level31_7A860_func_8003585C(argument0, argument1, argument2, argument3, outgoingWord5,
                                outgoingWord6);
    argument0 = owner + 0;
    goto original1913_1900;
original1913_1892:
    __asm__ volatile("" : "=r"(temporary3) : "0"(temporary3));
    temporary2 = Level31_7A860Field((int)&Level31_7A860_D_8006C770, int *, 0);
    Level31_7A860Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = 0 + -1, 1) : (temporary2 = 0 + -1, 0))
        goto original1913_1899;
    Level31_7A860Field(privateState, int *, 4) = temporary2;
    Level31_7A860Field(owner, unsigned char *, 65) = 0;
original1913_1899:
    argument0 = owner + 0;
original1913_1900:
    argument1 = 0 + 2;
    Level31_7A860_func_80055D24(argument0, argument1);
original1913Return:
    return;
}
#undef Level31_7A860Field
#undef Level31_7A860Keep
#undef Level31_7A860Low


/* SCUS-94467 USA Rev 0, 0x8007C644: 230 original instructions.
 * Descriptor loads use a 32-bit word at 0xE0 and unsigned halfwords at
 * offsets 0xE4/0xE6. Trig table entries are signed halfwords, multiplied by
 * 13 and shifted arithmetically by five before the original vector helper.
 * The indirect overlay call receives the original owner and 0x87 arguments.
 * Helper semantics, source-domain units and caller cadence remain unresolved.
 * Empty constraints preserve allocation/order and emit no CPU instructions.
 * AI generated; not human reviewed. */
#define P7C644_FIELD(type,base,offset) (*(type*)((unsigned char*)(base)+(offset)))
extern unsigned char D_800652B0[],D_800652B4[],D_800652B6[];
extern int D_8006C3F4,D_8006C4F8,D_8006C568,D_8006C640,D_8006C658,D_8006C6D0,D_8006C6E0,D_8006E344,D_8006C770;
extern unsigned char D_8006C7F8[],D_8006D088[];
extern signed char D_80071574;
extern unsigned char D_800719A8[],D_800719F0[],D_80068F7C[],D_80068F90[];
extern Vector3D D_800719BC;
extern int D_800719C0,D_800719C4;
extern unsigned char P7C644Player[] __asm__("D_80070328");
extern void (*P7C644Dispatch)(Moby*,int) __asm__("unk_ovlheader_80074318");
void func_level_31_8007C644(Moby *input) {
    register Moby *owner __asm__("$18")=input;
    register Vector3D *vector4 __asm__("$4");
    register Vector3D *vector5 __asm__("$5");
    register int index2 __asm__("$2");
    register int sample3 __asm__("$3");
    int archiveAddress;
    int animationArgument;
    int animationValue;
    register unsigned char *stateAddress0 __asm__("$16");
    register unsigned char *stateAddress13 __asm__("$16");
    unsigned char nextAnimation;
    unsigned char state;
    register void *privateState __asm__("$16");

    owner->updateDistance = 0xFF;
    privateState = owner->mobyTag;
    if ((D_8006C640 > 0) && (P7C644_FIELD(int,privateState,0x48) == 0)) {
        archiveAddress = D_8006C3F4 + P7C644_FIELD(int,&D_800652B0,0xE0);
        func_8004F984(archiveAddress, archiveAddress + P7C644_FIELD(unsigned short,&D_800652B4,0xE0), (int) P7C644_FIELD(unsigned short,&D_800652B6,0xE0));
        P7C644_FIELD(int,privateState,0x48) = 1;
    }
    state = owner->state;
    switch (state) {                              /* irregular */
    case 0x0:
        if (D_8006C658 != 0) {
            D_8006C568 = 1;
            owner->state = 0x63;
            return;
        }
        if ((D_8006E344 == 0xD) && (owner->substate == 0)) {
            stateAddress0 = (unsigned char*)owner+0x48;
            if (D_8006C4F8 != 1) {
                owner->state = 0x63;
                func_8003B7B4(stateAddress0, 1, &D_8006D088);
                func_8003B7B4(stateAddress0, 1, &D_8006C7F8);
                owner->substate = 1;
                return;
            }
            sample3=D_80065920[owner->angle.yaw];
            __asm__("" : "=r"(sample3) : "0"(sample3) : "$4", "$5");
            vector4=&D_800719BC;
            vector4->x=(sample3*0xD)>>5;
            index2=owner->angle.yaw;
            __asm__("" : "=r"(index2) : "0"(index2), "m"(vector4->x) : "$5");
            vector5=vector4;
            __asm__("" : "=r"(vector5) : "0"(vector5), "r"(index2) : "$3");
            sample3=D_800658A0[index2];
            __asm__ __volatile__("" : "=r"(sample3) : "0"(sample3) : "memory");
            D_800719C4=0;
            __asm__ __volatile__("" : "=r"(sample3) : "0"(sample3) : "memory");
            D_800719C0=(sample3*0xD)>>5;
            func_8004F194(vector4, vector5, &owner->position);
            D_8006C6E0 = ((owner->angle.yaw + 0x80) * 0x10) & 0xFFF;
            owner->substate = 1;
            goto updateState0;
        }
updateState0:
        owner->distanceToGround = 0;
        if (func_80037BBC(owner, 0) != 0) {
            func_800512E4(owner, 0, 0xD);
            owner->state = 0xD;
            return;
        }
    case 0x62:
        return;
    case 0xD:
        stateAddress13 = &owner->state;
        if (D_8006E344 != 1) {
            D_80071574 = 1;
            owner->state = 0x63;
            func_8003B7B4(stateAddress13, 1, &D_8006D088);
            func_8003B7B4(stateAddress13, 1, &D_8006C7F8);
            func_8003B74C(&D_8006D088);
            owner->state = 0x62;
            return;
        }
        break;
    case 0x63:
        P7C644Dispatch(owner,0x87);
        D_8006C6D0 = 0x100;
        func_800135A4(&D_800719A8, &D_80068F7C, 0);
        func_800135A4(&D_800719F0, &D_80068F90, 0);
        if (P7C644_FIELD(int,P7C644Player,0x24C)==5) {
            animationArgument = P7C644_FIELD(int,P7C644Player,0x48) - 0x87;
            if (animationArgument != owner->animationState.nextId) {
                func_80034F40(owner, animationArgument);
            }
        }
        if (D_8006C770 != 0) {
            nextAnimation = owner->animationState.nextId;
            animationValue = nextAnimation + 0x87;
            if (((unsigned int) (nextAnimation - 1) < 2U) || (animationValue == 0x8A)) {
                func_80034F40(owner, 0);
            } else if (animationValue == 0x92) {
                owner->unknown3[0] = 0;
            }
        }
        func_80035D38(owner);
        func_8005629C(owner);
        break;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C9DC.
* Assembly SHA256 c354860fc3131e0e2c8e3cc8495052738e904d6db81b1116ebc54f574e8c0fe7.
* AI generated;not human reviewed. All781 instructions/eight selectors
* and every actual native/linked target must match. Frame50 preserves
* S0..S6/RA and full SP20..2F local extent. Physical outer dispatch is
* 2/0-or-1/3. The eighth selector enters the original epilogue directly.
* The first owner copy precedes every owner read.70300/716AC accesses
* are unsigned bytes with original unscaled byte offsets;the two indexed
* stores retain complete V0 arithmetic and original saturating branches.
* Original 58/5C/5E/60 stores and three seven-argument2803C calls retain
* every A0..A3 producer and original SP10/14/18 outgoing word. The three
* inline C helpers express the original evaluation order;they introduce
* no additional function or CPU instructions. Ordinary private-record
* allocation avoids a redundant saved-register copy across inline calls.
* The old S0 record pointer dies before the selected-branch16 role begins.
* Original flags/byte stores,39/13 trig paths,stack zero writes and shared
* final34F40 call remain exact. Empty initialized identities,late inputs
* and dead clobbers emit zero instructions. No opcode assembly,partialHI,
* fixedFP,undefined saved-register inputs or overlapping live aliases.
* Raw units/fixed point,full helper contracts,caller cadence and retail
* runtime remain open. Cadence here is per invocation. Confidence is
* Rev0 binary identity after all gates. Falsification:every native/linked
* word,actual transfer/eight selector targets,full EXE and every overlay
* retail hash. Binary identity does not establish full subsystem parity.
*/
#define Level31_C9DCField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level31_C9DCDataPlaySoundView1() __asm__("PlaySound");
int Level31_C9DCCall1A358View1() __asm__("func_8001A358");
int Level31_C9DCCall2803CView1() __asm__("func_8002803C");
int Level31_C9DCCall28154View1() __asm__("func_80028154");
int Level31_C9DCCall34F40View1() __asm__("func_80034F40");
int Level31_C9DCCall3573CView1() __asm__("func_8003573C");
int Level31_C9DCCall3585CView1() __asm__("func_8003585C");
int Level31_C9DCCall359A4View1() __asm__("func_800359A4");
int Level31_C9DCCall35D38View1() __asm__("func_80035D38");
int Level31_C9DCCall35DDCView1() __asm__("func_80035DDC");
int Level31_C9DCCall3636CView1() __asm__("func_8003636C");
int Level31_C9DCCall3B634View1() __asm__("func_8003B634");
int Level31_C9DCCall3B74CView1() __asm__("func_8003B74C");
int Level31_C9DCCall3B7B4View1() __asm__("func_8003B7B4");
int Level31_C9DCCall3BB10View1() __asm__("func_8003BB10");
int Level31_C9DCCall4E880View1() __asm__("func_8004E880");
int Level31_C9DCCall4F178View1() __asm__("func_8004F178");
int Level31_C9DCCall4F194View1() __asm__("func_8004F194");
int Level31_C9DCCall4F334View1() __asm__("func_8004F334");
int Level31_C9DCCall512E4View1() __asm__("func_800512E4");
int Level31_C9DCCall55D24View1() __asm__("func_80055D24");
int Level31_C9DCCall5629CView1() __asm__("func_8005629C");
extern int Level31_C9DCData658A0View1 __asm__("D_800658A0");
extern int Level31_C9DCData65920View1 __asm__("D_80065920");
extern int Level31_C9DCData66BC8View1 __asm__("D_80066BC8");
extern short Level31_C9DCData67406View1 __asm__("D_80067406");
extern unsigned char Level31_C9DCData6742BView1 __asm__("D_8006742B");
extern int Level31_C9DCData6C550View1 __asm__("D_8006C550");
extern int Level31_C9DCData6C568View1 __asm__("D_8006C568");
extern int Level31_C9DCData6C58CView1 __asm__("D_8006C58C");
extern unsigned char Level31_C9DCData6C62CView1 __asm__("D_8006C62C");
extern int Level31_C9DCData6C654View1 __asm__("D_8006C654");
extern int Level31_C9DCData6C658View1 __asm__("D_8006C658");
extern int Level31_C9DCData6C770View1 __asm__("D_8006C770");
extern unsigned char Level31_C9DCData6C7B4View1 __asm__("D_8006C7B4");
extern int Level31_C9DCData6C7F8View1 __asm__("D_8006C7F8");
extern int Level31_C9DCData6D088View1 __asm__("D_8006D088");
extern int Level31_C9DCData6D0B8View1 __asm__("D_8006D0B8");
extern int Level31_C9DCData6E044View1 __asm__("D_8006E044");
extern int Level31_C9DCData6E048View1 __asm__("D_8006E048");
extern int Level31_C9DCData6E344View1 __asm__("D_8006E344");
extern int Level31_C9DCData70300View1 __asm__("D_80070300");
extern int Level31_C9DCData70328View1 __asm__("D_80070328");
extern int Level31_C9DCData716ACView1 __asm__("D_800716AC");
extern short Level31_C9DCData719DCView1 __asm__("D_800719DC");
extern unsigned char Level31_C9DCData71A04View1 __asm__("D_80071A04");
extern int Level31_C9DCData74364View1 __asm__("unk_ovlheader_80074364");
extern int Level31_C9DCData74368View1 __asm__("unk_ovlheader_80074368");
extern int Level31_C9DCData7436CView1 __asm__("unk_ovlheader_8007436C");
extern int Level31_C9DCData74370View1 __asm__("unk_ovlheader_80074370");
static __inline__ int Level31_C9DCInitializeAndCall(int type, int sprite, int cb6, int cb7, int *cbStack, int displayBase, int maximum, int record, int initial){
    Level31_C9DCField(record, int*, 0x58) = initial;
    return Level31_C9DCCall2803CView1(type, sprite, cb6, cb7, *cbStack, displayBase+4, maximum);
}
static __inline__ int Level31_C9DCStoreFirstResultAndCall(int type, int sprite, int cb6, int cb7, int *cbStack, int displayBase, int maximum, int record, int previous){
    Level31_C9DCField(record, short*, 0x5C) = previous;
    return Level31_C9DCCall2803CView1(type, sprite, cb6, cb7, *cbStack, displayBase+0x24, maximum);
}
static __inline__ int Level31_C9DCStoreSecondResultAndCall(int type, int sprite, int cb6, int cb7, int cbStack, int record, int maximum, int previous){
    Level31_C9DCField(record, short*, 0x5E) = previous;
    return Level31_C9DCCall2803CView1(type, sprite, cb6, cb7, cbStack, record+0x58, maximum);
}
void func_level_31_8007C9DC(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), retainedByteAddress22 __asm__("$22");
    register void *ownerRecord18 __asm__("$18");
    int privateRecord;
    register int addressOrResult16 __asm__("$16"), retainedRecord19 __asm__("$19"), retainedLimit20 __asm__("$20"), retainedRecord21 __asm__("$21");
    struct{
        int sp20, sp24, sp28, sp2C;
    }
    originalFrame;
    register int selectedBranch16 __asm__("$16");
    int secondReturnedWord;
    int temporaryWord1, firstReturnedWord;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    argumentWord5 = 2;
    rawWord3 = Level31_C9DCField(ownerRecord18, unsigned char*, 0x48);
    privateRecord = Level31_C9DCField(ownerRecord18, void**, 0);
    __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
    if (rawWord3 == argumentWord5) goto dispatchStateTwo;
    rawWord2 = rawWord3 < 3;
    if (rawWord2) goto dispatchStateZeroOrOne;
    rawWord2 = 3;
    if (rawWord3 == rawWord2) goto dispatchStateThree;
    return;
    dispatchStateZeroOrOne:if (rawWord3 < 0) return;
    rawWord3 = Level31_C9DCField(ownerRecord18, unsigned char *, 0x49);
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    switch (rawWord3) {
    case 0:__asm__ __volatile__(""::"r"(rawWord3));
        if (Level31_C9DCData6C7B4View1 & 2) {
            Level31_C9DCField(privateRecord, signed char *, 2) = 4;
        }
        else {
            Level31_C9DCField(privateRecord, signed char *, 2) = 0;
        }
        if (({rawWord2 = Level31_C9DCData6C658View1;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;}) != 0) {
            rawWord2 = 3;
        }
        else {
            rawWord2 = 1;
        }
        Level31_C9DCField(ownerRecord18, unsigned char *, 0x49) = rawWord2;
        addressOrResult16 = ownerRecord18 + 0x49;
        Level31_C9DCCall3B7B4View1(addressOrResult16, 1, &Level31_C9DCData6D088View1);
        Level31_C9DCCall3B7B4View1(addressOrResult16, 1, &Level31_C9DCData6C7F8View1);
        return;
    case 1:
        if (Level31_C9DCField(&Level31_C9DCData70328View1, int *, 0x244) != 0) {
            Level31_C9DCField(ownerRecord18, unsigned char *, 0x48) = 3U;
            argumentWord4 = (int)ownerRecord18;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            argumentWord5 = 3;
            goto callOriginalFinalHelper;
        }
    default:
        return;
    case 2:
        Level31_C9DCCall512E4View1(ownerRecord18, 0, 2);
        Level31_C9DCField(ownerRecord18, unsigned char *, 0x48) = 2U;
        return;
    case 3:
        if (((Level31_C9DCData6E044View1 == 9) && (Level31_C9DCData6E048View1 == 1)) || ((Level31_C9DCData6C658View1 != 0) && (Level31_C9DCField(&Level31_C9DCData70328View1, void ***, 0x250) != 0))) {
            rawWord3 = Level31_C9DCField(privateRecord, int*, 0x4C);
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            argumentWord4 = Level31_C9DCField(&Level31_C9DCData70328View1, int*, 0x250);
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = rawWord3*11;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord2 <<= 3;
            rawWord3 = Level31_C9DCData6C550View1;
            retainedRecord21 = Level31_C9DCField(argumentWord4, int*, 0);
            rawWord2 += rawWord3;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord3 = Level31_C9DCData6C7B4View1;
            retainedRecord19 = Level31_C9DCField(rawWord2, int*, 0);
            __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(retainedRecord19):"$20");
            retainedLimit20 = 0x19;
            if (rawWord3 & 2) {
                retainedLimit20 = 0x3C;
            }
            retainedByteAddress22 = (int)&Level31_C9DCData71A04View1;
            __asm__("":"=r"(retainedByteAddress22):"0"(retainedByteAddress22));
            if (Level31_C9DCField(retainedByteAddress22, unsigned char*, 0) == 0) {
                Level31_C9DCField(retainedRecord21, int *, 0x24) = retainedLimit20;
                Level31_C9DCCall3B7B4View1(retainedRecord21 + 0x24, 4, &Level31_C9DCData6C7F8View1);
                Level31_C9DCField(retainedRecord19, int *, 4) = retainedLimit20;
                Level31_C9DCCall3B7B4View1(retainedRecord19 + 4, 4, &Level31_C9DCData6C7F8View1);
            }
            Level31_C9DCCall4F178View1(ownerRecord18 + 0xC, Level31_C9DCField(Level31_C9DCField(privateRecord, void **, 0x54), void **, 0xC));
            temporaryWord1 = Level31_C9DCField(Level31_C9DCField(privateRecord, void **, 0x54), void **, 0xC);
            Level31_C9DCField(ownerRecord18, signed char *, 0x46) = Level31_C9DCCall4E880View1(Level31_C9DCField(temporaryWord1, int *, 0x10) - Level31_C9DCField(ownerRecord18, int *, 0xC), Level31_C9DCField(temporaryWord1, int *, 0x14) - Level31_C9DCField(ownerRecord18, int *, 0x10), 0);
            Level31_C9DCCall35D38View1(ownerRecord18);
            Level31_C9DCCall5629CView1(ownerRecord18);
            Level31_C9DCCall55D24View1(ownerRecord18, 2);
            argumentWord4 = 0x37;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            addressOrResult16 = 0xE10;
            __asm__("":"=r"(addressOrResult16):"0"(addressOrResult16):"$5");
            firstReturnedWord = Level31_C9DCInitializeAndCall(argumentWord4, 0x137, Level31_C9DCData74368View1, Level31_C9DCData7436CView1, &Level31_C9DCData74364View1, retainedRecord19, retainedLimit20, privateRecord, addressOrResult16);
            __asm__ __volatile__(""::"r"(retainedRecord19));
            secondReturnedWord = Level31_C9DCStoreFirstResultAndCall(0x35, 0x136, Level31_C9DCData74368View1, Level31_C9DCData7436CView1, &Level31_C9DCData74364View1, retainedRecord21, retainedLimit20, privateRecord, firstReturnedWord);
            __asm__ __volatile__(""::"r"(retainedRecord21));
            Level31_C9DCField(privateRecord, short*, 0x60) = Level31_C9DCStoreSecondResultAndCall(0x32, 3, 0, 0, Level31_C9DCData74370View1, privateRecord, addressOrResult16, secondReturnedWord);
            if (Level31_C9DCField(retainedByteAddress22, unsigned char*, 0) != 0) {
                Level31_C9DCField(ownerRecord18, unsigned char *, 0x49) = 4U;
                return;
            }
            goto storeOriginalSelectorFive;
        }
        break;
    case 4:
        if ((Level31_C9DCData67406View1 == Level31_C9DCField(privateRecord, short *, 0x5E)) && (Level31_C9DCData6742BView1 == 0)) {
            rawWord3 = Level31_C9DCField(privateRecord, int*, 0x4C);
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            argumentWord4 = Level31_C9DCData6C550View1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = rawWord3*11;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord3 = Level31_C9DCField(&Level31_C9DCData70328View1, int*, 0x250);
            rawWord2 <<= 3;
            argumentWord5 = Level31_C9DCField(rawWord3, int*, 0);
            rawWord2 += argumentWord4;
            addressOrResult16 = Level31_C9DCField(rawWord2, int*, 0);
            rawWord3 = Level31_C9DCField(argumentWord5, int *, 0x24) + 0xF;
            Level31_C9DCField(argumentWord5, int *, 0x24) = rawWord3;
            if (rawWord3 >= 0x3D) {
                Level31_C9DCField(argumentWord5, int *, 0x24) = 0x3C;
            }
            Level31_C9DCCall3B7B4View1(argumentWord5 + 0x24, 4, &Level31_C9DCData6C7F8View1);
            rawWord2 = Level31_C9DCField(addressOrResult16, int *, 4) + 0xF;
            Level31_C9DCField(addressOrResult16, int *, 4) = rawWord2;
            if (rawWord2 >= 0x3D) {
                Level31_C9DCField(addressOrResult16, int *, 4) = 0x3C;
            }
            Level31_C9DCCall3B7B4View1(addressOrResult16 + 4, 4, &Level31_C9DCData6C7F8View1);
        storeOriginalSelectorFive:
            rawWord2 = 5;
            Level31_C9DCField(ownerRecord18, unsigned char*, 0x49) = rawWord2;
            return;
        }
        break;
    case 5:
        if (Level31_C9DCData6C770View1 != 0) {
            if (Level31_C9DCField(privateRecord, int *, 0x44) == 0) {
                Level31_C9DCCall34F40View1(ownerRecord18, 1);
                Level31_C9DCField(privateRecord, int *, 0x44) = Level31_C9DCCall3636CView1(3, 6);
            }
            else {
                Level31_C9DCCall34F40View1(ownerRecord18, 0);
                Level31_C9DCField(privateRecord, int *, 0x44) = (int) (Level31_C9DCField(privateRecord, int *, 0x44) - 1);
            }
        }
        if (Level31_C9DCData6C568View1 != 0) {
            rawWord3 = Level31_C9DCField(privateRecord, int*, 0x4C);
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            argumentWord4 = Level31_C9DCData6C550View1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = rawWord3*11;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord3 = Level31_C9DCField(&Level31_C9DCData70328View1, int*, 0x250);
            rawWord2 <<= 3;
            retainedRecord19 = Level31_C9DCField(rawWord3, int*, 0);
            rawWord2 += argumentWord4;
            addressOrResult16 = Level31_C9DCField(rawWord2, int*, 0);
            if ((Level31_C9DCField(retainedRecord19, int *, 0x24) > 0) && (Level31_C9DCField(addressOrResult16, int *, 4) > 0)) {
                Level31_C9DCCall359A4View1(privateRecord + 0x58, 4);
            }
            if ((Level31_C9DCField(privateRecord, int *, 0x58) == 0) || (Level31_C9DCField(retainedRecord19, int *, 0x24) < 0) || (Level31_C9DCField(addressOrResult16, int *, 4) < 0)) {
                Level31_C9DCField(privateRecord, int *, 0x44) = 0;
                Level31_C9DCCall28154View1(Level31_C9DCField(privateRecord, short *, 0x5C));
                Level31_C9DCCall28154View1(Level31_C9DCField(privateRecord, short *, 0x5E));
                Level31_C9DCCall28154View1(Level31_C9DCField(privateRecord, short *, 0x60));
                if (Level31_C9DCField(addressOrResult16, int *, 4) < 0) {
                    selectedBranch16 = 2;
                    Level31_C9DCField(privateRecord, int *, 0x44) = 0x5A;
                    Level31_C9DCField(ownerRecord18, unsigned char *, 0x48) = 0U;
                    Level31_C9DCCall34F40View1(ownerRecord18, 0);
                }
                else if (Level31_C9DCField(retainedRecord19, int *, 0x24) < 0) {
                    selectedBranch16 = 1;
                    Level31_C9DCField(privateRecord, int *, 0x44) = 0x5A;
                }
                else if ((Level31_C9DCData6C7B4View1 & 2) && ((unsigned char) Level31_C9DCData71A04View1 < 2U)) {
                    Level31_C9DCCall3BB10View1(ownerRecord18, 5, 1);
                    Level31_C9DCField(privateRecord, int *, 0x44) = 0x3C;
                    selectedBranch16 = 0;
                }
                else {
                    Level31_C9DCCall3BB10View1(ownerRecord18, 5, 1);
                    Level31_C9DCField(privateRecord, int *, 0x44) = 0x78;
                    if (Level31_C9DCField(addressOrResult16, int *, 4) < Level31_C9DCField(retainedRecord19, int *, 0x24)) {
                        Level31_C9DCCall34F40View1(Level31_C9DCData6C550View1 + (Level31_C9DCField(privateRecord, int *, 0x4C) * 0x58), 0x11);
                        rawWord3 = Level31_C9DCField(privateRecord, int*, 0x4C);
                        __asm__("":"=r"(rawWord3):"0"(rawWord3));
                        selectedBranch16 = 2;
                        __asm__("":"=r"(selectedBranch16):"0"(selectedBranch16));
                        rawWord2 = rawWord3*11;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        rawWord3 = Level31_C9DCData6C550View1;
                        rawWord2 <<= 3;
                        rawWord2 += rawWord3;
                        rawWord3 = 0x11;
                    }
                    else {
                        Level31_C9DCCall34F40View1(Level31_C9DCData6C550View1 + (Level31_C9DCField(privateRecord, int *, 0x4C) * 0x58), 0xF);
                        rawWord3 = Level31_C9DCField(privateRecord, int*, 0x4C);
                        __asm__("":"=r"(rawWord3):"0"(rawWord3));
                        selectedBranch16 = 1;
                        __asm__("":"=r"(selectedBranch16):"0"(selectedBranch16));
                        rawWord2 = rawWord3*11;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        rawWord3 = Level31_C9DCData6C550View1;
                        rawWord2 <<= 3;
                        rawWord2 += rawWord3;
                        rawWord3 = 0xF;
                    }
                    Level31_C9DCField(rawWord2, signed char *, 0x48) = rawWord3;
                }
                if (selectedBranch16 == 2) {
                    if (Level31_C9DCData6C7B4View1 & 2) {
                        if ((unsigned char) Level31_C9DCData71A04View1 < 2U) {
                            Level31_C9DCField(&Level31_C9DCData66BC8View1, signed char *, 9) = 3;
                            Level31_C9DCData719DCView1 = 1;
                            Level31_C9DCDataPlaySoundView1(Level31_C9DCField(Level31_C9DCData6C654View1, unsigned char *, 0x23), ownerRecord18, 0xA1);
                        }
                        Level31_C9DCData6C7B4View1 |= 4;
                    }
                    else {
                        Level31_C9DCData6C7B4View1 |= 2;
                    }
                }
                else if (selectedBranch16 == 1){
                    rawWord2 = Level31_C9DCData6C7B4View1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    rawWord2 &= 2;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    if (rawWord2)rawWord2 = 11;
                    else rawWord2 = 10;
                    Level31_C9DCField(privateRecord, signed char*, 2) = rawWord2;
                    __asm__ __volatile__("":::"$5");
                    Level31_C9DCCall3B7B4View1(privateRecord+2, 1, &Level31_C9DCData6C7F8View1);
                }
                Level31_C9DCField(ownerRecord18, unsigned char *, 0x49) = 6U;
                return;
            }
        }
        break;
    case 6:
        Level31_C9DCField(&Level31_C9DCData70328View1, int *, 0x20C) = 0x10000002;
        if (Level31_C9DCCall359A4View1(privateRecord + 0x44, 4) != 0) {
            addressOrResult16 = (int)&Level31_C9DCData6D088View1+0x24;
            Level31_C9DCCall4F178View1(&originalFrame.sp20, addressOrResult16);
            rawWord2 = Level31_C9DCCall1A358View1(&originalFrame.sp20, 0x1000);
            __asm__("":"=r"(addressOrResult16):"0"(addressOrResult16));
            addressOrResult16 -= 0x24;
            originalFrame.sp28 = rawWord2;
            Level31_C9DCCall3B634View1(addressOrResult16, &originalFrame.sp20, (int) Level31_C9DCData6D0B8View1 >> 4);
            Level31_C9DCCall3B74CView1(addressOrResult16);
            return;
        }
        return;
    case 7:goto originalEpilogue;
    }
    return;
dispatchStateTwo:
    if (Level31_C9DCData6E344View1 != 1) {
        rawWord2 = Level31_C9DCField(privateRecord, unsigned char *, 4);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawWord3 = rawWord2 & 0xFF;
        if (rawWord3 == 1) {
            Level31_C9DCData71A04View1 = 0;
            if (!(Level31_C9DCData6C7B4View1 & 2) && !(Level31_C9DCField(&Level31_C9DCData70300View1, unsigned char*, Level31_C9DCData6C58CView1) & 2)) {
                rawWord3 = Level31_C9DCData6C58CView1;
                rawWord2 = rawWord3*3;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                argumentWord4 = rawWord2*2;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                rawWord3 = Level31_C9DCField(&Level31_C9DCData716ACView1, unsigned char*, 1 + argumentWord4);
                if (rawWord3 < 0xFFU) {
                    rawWord2 = rawWord3+1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Level31_C9DCField(&Level31_C9DCData716ACView1, unsigned char*, 1 + argumentWord4) = rawWord2;
                }
            }
            goto storeSelectedRecordStateOne;
        }
        argumentWord4 = 5;
        if (rawWord3 == argumentWord4) goto updateOriginalTableByteTwo;
        rawWord2 -= 7;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if ((unsigned int)rawWord2 >= 2U) goto checkOtherOriginalSelectors;
        __asm__ __volatile__("":"=r"(rawWord3):"0"(rawWord3));
        if (rawWord3 != argumentWord4) goto checkOriginalSelectorsSevenAndEight;
    updateOriginalTableByteTwo:
        Level31_C9DCData71A04View1 = 0;
        if (!(Level31_C9DCData6C7B4View1 & 4) && !(Level31_C9DCField(&Level31_C9DCData70300View1, unsigned char*, Level31_C9DCData6C58CView1) & 4)) {
            rawWord3 = Level31_C9DCData6C58CView1;
            rawWord2 = rawWord3*3;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            argumentWord4 = rawWord2*2;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord3 = Level31_C9DCField(&Level31_C9DCData716ACView1, unsigned char*, 2 + argumentWord4);
            if (rawWord3 < 0xFFU) {
                rawWord2 = rawWord3+1;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                Level31_C9DCField(&Level31_C9DCData716ACView1, unsigned char*, 2 + argumentWord4) = rawWord2;
            }
        }
        goto storeSelectedRecordStateOne;
    checkOriginalSelectorsSevenAndEight:
        rawWord2 = 7;
        if (rawWord3 == rawWord2){
            rawWord2 = 1;
            goto storeOriginalSelectedByte;
        }
        rawWord2 = 8;
        if (rawWord3 == rawWord2){
            rawWord2 = 2;
            storeOriginalSelectedByte:Level31_C9DCData71A04View1 = rawWord2;
        }
    storeSelectedRecordStateOne:
        rawWord3 = Level31_C9DCField(privateRecord, int*, 0x48);
        rawWord2 = rawWord3*11;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawWord3 = Level31_C9DCData6C550View1;
        rawWord2 <<= 3;
        rawWord2 += rawWord3;
        rawWord3 = 1;
        Level31_C9DCField(rawWord2, signed char*, 0x48) = rawWord3;
        rawWord2 = 3;
        goto storeOriginalOwnerSelector;
    checkOtherOriginalSelectors:
        if (rawWord3 == argumentWord5) goto storeOtherRecordStateThree;
        rawWord2 = 6;
        if (rawWord3 == rawWord2) goto storeOtherRecordStateThree;
        rawWord2 = 9;
        if (rawWord3 == rawWord2) goto storeOtherRecordStateThree;
        rawWord2 = 12;
        if (rawWord3 != rawWord2) goto clearOwnerState;
    storeOtherRecordStateThree:
        rawWord3 = Level31_C9DCField(privateRecord, int*, 0x50);
        rawWord2 = rawWord3*11;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawWord3 = Level31_C9DCData6C550View1;
        rawWord2 <<= 3;
        rawWord2 += rawWord3;
        rawWord3 = 3;
        Level31_C9DCField(rawWord2, signed char*, 0x48) = rawWord3;
        rawWord2 = 7;
        storeOriginalOwnerSelector:Level31_C9DCField(ownerRecord18, unsigned char*, 0x49) = rawWord2;
    clearOwnerState:
        Level31_C9DCField(ownerRecord18, unsigned char *, 0x48) = 0U;
        return;
    }
    return;
dispatchStateThree:
    Level31_C9DCField(&Level31_C9DCData70328View1, int *, 0x20C) = 0x10000002;
    rawWord3 = Level31_C9DCField(ownerRecord18, unsigned char *, 0x49);
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    if (rawWord3 == 1) goto processStateThreeSelectorOne;
    if (rawWord3 == argumentWord5) goto processStateThreeSelectorTwo;
    return;
processStateThreeSelectorOne:
    rawWord3 = Level31_C9DCData6C7B4View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    rawWord2 = rawWord3&2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2) {
        if (Level31_C9DCData6C62CView1 & 2) {
            rawWord2 = rawWord3&4;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            goto checkOriginalStatusBitFour;
        }
        goto produceOriginal39Vector;
    }
    rawWord2 = rawWord3&4;
checkOriginalStatusBitFour:
    if ((rawWord2 != 0) && !(Level31_C9DCData6C62CView1 & 4)) {
    produceOriginal39Vector:
        argumentWord4 = Level31_C9DCField(&Level31_C9DCData70328View1, unsigned char *, 0xE) * 2;
        originalFrame.sp20 = (int) (Level31_C9DCField(&Level31_C9DCData65920View1, short*, argumentWord4) * 0x27) >> 6;
        rawWord3 = Level31_C9DCField(&Level31_C9DCData658A0View1, short*, argumentWord4);
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        originalFrame.sp28 = 0;
        __asm__ __volatile__("":::"memory");
        rawWord2 = (rawWord3*0x27) >> 6;
    }
    else {
        argumentWord4 = Level31_C9DCField(&Level31_C9DCData70328View1, unsigned char *, 0xE) * 2;
        originalFrame.sp20 = (int) (Level31_C9DCField(&Level31_C9DCData65920View1, short*, argumentWord4) * 0xD) >> 5;
        rawWord3 = Level31_C9DCField(&Level31_C9DCData658A0View1, short*, argumentWord4);
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        originalFrame.sp28 = 0;
        __asm__ __volatile__("":::"memory");
        rawWord2 = (rawWord3*0xD) >> 5;
    }
    originalFrame.sp24 = rawWord2;
    __asm__ __volatile__("":::"memory");
    Level31_C9DCCall4F194View1(&originalFrame.sp20, &Level31_C9DCData70328View1, &originalFrame.sp20);
    if (Level31_C9DCCall3585CView1(ownerRecord18, Level31_C9DCCall4E880View1(originalFrame.sp20 - Level31_C9DCField(ownerRecord18, int *, 0xC), originalFrame.sp24 - Level31_C9DCField(ownerRecord18, int *, 0x10), 0), 8, 0x10, 1, 0) != 0) {
        Level31_C9DCCall35DDCView1(ownerRecord18, 0x80, 0, 0, 0);
        if (Level31_C9DCCall4F334View1(&originalFrame.sp20, ownerRecord18 + 0xC) < 0x100) {
            Level31_C9DCField(ownerRecord18, unsigned char *, 0x49) = 2U;
            return;
        }
    }
    return;
processStateThreeSelectorTwo:
    if (Level31_C9DCCall3573CView1(ownerRecord18, 8, 4, 1) != 0) {
        Level31_C9DCField(privateRecord, signed char *, 5) = 1;
        if ((Level31_C9DCData6C7B4View1 & 6) == 6) {
            Level31_C9DCField(privateRecord, signed char *, 2) = 0xC;
        }
        Level31_C9DCField(ownerRecord18, unsigned char *, 0x48) = 0U;
        argumentWord4 = (int)ownerRecord18;
        __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
        argumentWord5 = 0;
        goto callOriginalFinalHelper;
    }
    return;
callOriginalFinalHelper:
    Level31_C9DCCall34F40View1(argumentWord4, argumentWord5);
    originalEpilogue:__asm__ __volatile__("":::"memory");
}
#undef Level31_C9DCField


typedef struct { Vector3D position; int flags; } DecodedCameraPathPoint;
typedef struct { short count, current; unsigned char reserved04[8]; DecodedCameraPathPoint* points; } DecodedCameraPath;
typedef struct { unsigned char reserved00[12]; Vector3D* position; } DecodedCameraPathRecord;
typedef struct { DecodedCameraPath* path; DecodedCameraPathRecord* camera; } DecodedCameraPathTag;
extern int D_8006E160, D_8006E048, D_8006C598, D_8006E53C, D_8006C74C, D_8006C568;
void DecodedCameraPathSet(Vector3D*,Vector3D*) __asm__("func_80013AE4");
void DecodedCameraPathFinish(int) __asm__("func_80013B7C");
int DecodedCameraPathMove(Moby*,DecodedCameraPath*,int,int,int,int,int,int) __asm__("func_80035A80");
void DecodedCameraPathSound(Moby*,int,int) __asm__("func_8003BB10");
void DecodedCameraPathDraw(Moby*,int) __asm__("func_80055D24");
void func_level_31_8007D610(Moby* moby) {
    DecodedCameraPathTag* tag = moby->mobyTag;
    int previous;
    int state = moby->state;
    int count;
    register int countMinusOne __asm__("$4");
    switch (state) {
    case 1:
        if (D_8006E160 == 9) {
            if (D_8006E048 == state) {
                SpawnMoby(0xF4,moby);
                moby->lowDrawDistance = 32;
                moby->state = 2;
            }
        } else DecodedCameraPathSet(tag->camera->position,(Vector3D*)((unsigned char*)tag->camera->position+16));
        break;
    case 2:
        if (!D_8006C598 && (D_8006E53C & 0x800)) {
            DecodedCameraPathFinish(0);
            D_8006C74C = 0;
            D_8006C568 = 1;
            SpawnParticle(12,12,(Vector3D*)moby,(Vector3D*)5);
            DecodedCameraPathSound(moby,5,1);
            goto remove;
        }
        if (!(DecodedCameraPathMove(moby,tag->path,0x200,0xA0,0,3,32,0)&1)) goto draw;
        if (moby->state == 2) {
            count = tag->path->count;
            countMinusOne = count - 1;
            __asm__("" : "=r"(countMinusOne) : "0"(countMinusOne));
            previous = (tag->path->current + countMinusOne) % count;
            if (tag->path->points[previous].flags) {
                DecodedCameraPathFinish(0);
                D_8006C568 = 1;
                D_8006C74C = 0;
                moby->state = 3;
                DecodedCameraPathSound(moby,5,1);
            }
        }
        goto draw;
    case 3:
        if ((DecodedCameraPathMove(moby,tag->path,0x200,0xA0,0,state,24,0)&1) && !tag->path->current) {
            SpawnParticle(12,12,(Vector3D*)moby,(Vector3D*)5);
remove:
            func_80055B18(moby);
        }
draw:
        DecodedCameraPathDraw(moby,4);
        break;
    }
}

void func_level_31_8007D8BC(Moby* moby) {
    Moby** tag = moby->mobyTag;
    Vector3D first, second;
    if ((*tag)->state & 0x80) {
        func_80055B18(moby);
    } else {
        func_80055F14(*tag, 0, &first);
        func_80055F14(*tag, 1, &second);
        func_8004F1C8(&second, &second, &first);
        moby->angle.yaw = func_8004E880(second.x, second.y, 0) - 0x40;
        func_8004F110(&second, 1);
        func_8004F194(&moby->position, &second, &first);
    }
}

extern unsigned char D_80066FCC[], D_80070300[];
void func_80021ED8(void*, int, int);
void func_80055B18(Moby*);
void func_level_31_8007D97C(Moby* moby) {
    int* tag = moby->mobyTag;
    if (D_80070300[D_80066FCC[tag[0]]] & 1) {
        func_80021ED8((void*)tag[1], 0xFC, 0);
    }
    func_80055B18(moby);
}

typedef struct { int actorIndex; Vector3D position; int timer; int* counter; } DecodedLinkedActor;
extern Moby* D_8006C550;
extern int D_8006C79C,D_8006C58C;
extern int D_80071AB0[][8];

extern Moby* DecodedActorCallback(Moby*,int,Vector3D*,Vector3D*) __asm__("func_80036A68");
int func_8001A358(Vector3D*,int);
void func_level_31_8007D9E8(Moby* moby) {
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

extern int D_8006C770;
void DecodedEnemyVectorHit(Moby*,void*,int,int) __asm__("func_80038BF8");
void DecodedEnemyVectorMove(Moby*,void*,int) __asm__("func_80037168");
int DecodedEnemyVectorComplete(Moby*,void*) __asm__("func_80035194");
int DecodedEnemyVectorTimer(void*,int) __asm__("func_800359A4");
void func_level_31_8007DD18(Moby* moby) {
    char* tag = moby->mobyTag;
    if (moby->state != 1) {
        if (moby->damageFlags & 0x10010000) {
            DecodedEnemyVectorHit(moby, tag + 0x1C, 7, 1);
            SpawnMoby(0x10, moby);
            if (moby->damageFlags & 0x100000) {
                *(short*)(tag + 0x20) += 200;
                *(short*)(tag + 0x22) += 50;
            }
            moby->state = 1;
            func_80034F40(moby, 1);
        } else if (moby->damageFlags & 0x20000) {
            DecodedEnemyVectorHit(moby, tag + 0x1C, 7, 1);
            SpawnMoby(0x10, moby);
            moby->state = 1;
            func_80034F40(moby, 1);
        }
    }
    switch (moby->state) {
    case 0:
        DecodedEnemyVectorMove(moby, tag, 1);
        if (DecodedEnemyVectorTimer(tag + 0x18, 4)) {
            moby->state = 2;
            func_80034F40(moby, 2);
        }
        break;
    case 1:
        if (DecodedEnemyVectorComplete(moby, tag + 0x1C) == 0x100) {
            func_80055D24(moby, 4);
            func_800369B8(moby, 0x18);
            func_80055B18(moby);
        }
        break;
    case 2:
        if (D_8006C770) {
            *(int*)(tag + 0x18) = func_8003636C(90, 300);
            moby->state = 0;
            func_80034F40(moby, 0);
        }
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007DEFC.
* Assembly SHA256 9cb45d7bd7b16f8393de2305a069b0decdac5df99ccce1afe3ddff2c8c3654ec.
* AI generated;not human reviewed. All830 original instructions,81 table
* selectors and one zero padding word must match,including actual targets.
* Frame80 saves S0..S5/RA and retains full SP20..5F. S0's private,returned
* child and returned particle roles are sequential;no live aliases overlap.
* Original two-child creation preserves class62,state81,flag63,owner byte
* heading loads and signed height-minus128 in the first helper call delay.
* The second spawn target occupies V1 while the first rand word remains
* live in V0. Player mode/counter bases retain original A3/A1-to-S2/S0/S3
* producer chains and byte addends. Full SLL16/SRA20 F264 caller arguments
* retain their signed32-bit values;the decoder's premature u8 casts are
* removed. Halfword selector reversal and neighbor comparisons preserve
* original A1/A2/V0/V1 producers and the shared SH target.
* The single shared3573C/35DDC block remains at its original state2 join.
* Ordinary retained distance copies into S2 in the following call delay.
* Original branch606 enters final call818 after its own A0 delay producer;
* other paths retain the owner reload817. Both targets are independently
* checked. Particle loops retain16 iterations,three rand vector words,
* independent halfword reloads and full signed-minus63 deltas before SH.
* Known helper prototypes reuse existing mobyutil/stdutil/ovl_header and
* original zero-input rand evidence. Other helper/caller meanings,physical
* units/fixed point and cadence beyond per invocation remain unresolved.
* Empty initialized identities/late inputs/dead-before-producer clobbers
* emit zero CPU words. No opcode assembly,partialHI,fixedFP,undefined saved
* input,overlapping live aliases or compiler/filter/flag changes are used.
* Confidence is binary identity after all gates. Next evidence:human review,
* complete helper/caller chains and synchronized retail runtime captures.
* Falsification:every native/linked instruction,actual branch/call/table
* target,owned data and full EXE/every-overlay retail hashes must agree.
*/
#define Level31_7DEFCField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level31_7DEFCCall1A358View1() __asm__("func_8001A358");
int Level31_7DEFCCall1C288View1() __asm__("func_8001C288");
void Level31_7DEFCCall34F40View1(void*, int) __asm__("func_80034F40");
int Level31_7DEFCCall34F80View1() __asm__("func_80034F80");
int Level31_7DEFCCall35194View1() __asm__("func_80035194");
int Level31_7DEFCCall3573CView1() __asm__("func_8003573C");
int Level31_7DEFCCall3585CView1() __asm__("func_8003585C");
int Level31_7DEFCCall359A4View1(void*, int) __asm__("func_800359A4");
int Level31_7DEFCCall35A80View1() __asm__("func_80035A80");
int Level31_7DEFCCall35DDCView1() __asm__("func_80035DDC");
int Level31_7DEFCCall3645CView1() __asm__("func_8003645C");
int Level31_7DEFCCall36A68View1() __asm__("func_80036A68");
int Level31_7DEFCCall38BF8View1() __asm__("func_80038BF8");
int Level31_7DEFCCall3BA00View1() __asm__("func_8003BA00");
int Level31_7DEFCCall3BABCView1() __asm__("func_8003BABC");
int Level31_7DEFCCall3BB10View1() __asm__("func_8003BB10");
int Level31_7DEFCCall40954View1() __asm__("func_80040954");
int Level31_7DEFCCall4E880View1(int, int, int) __asm__("func_8004E880");
int Level31_7DEFCCall4F264View1(int, int) __asm__("func_8004F264");
int Level31_7DEFCCall4F334View1() __asm__("func_8004F334");
int Level31_7DEFCCall55B18View1() __asm__("func_80055B18");
int Level31_7DEFCCall55D24View1() __asm__("func_80055D24");
int Level31_7DEFCCall55F14View1() __asm__("func_80055F14");
int Level31_7DEFCDatarandView1(void) __asm__("rand");
extern int Level31_7DEFCData658A0View1 __asm__("D_800658A0");
extern int Level31_7DEFCData65920View1 __asm__("D_80065920");
extern int Level31_7DEFCData6C770View1 __asm__("D_8006C770");
extern int Level31_7DEFCData6E020View1 __asm__("D_8006E020");
extern int Level31_7DEFCData6E024View1 __asm__("D_8006E024");
extern unsigned short Level31_7DEFCData6E040View1 __asm__("D_8006E040");
extern int Level31_7DEFCData70328View1 __asm__("D_80070328");
extern int Level31_7DEFCData71924View1 __asm__("D_80071924");
extern void*(*Level31_7DEFCDataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern void*(*Level31_7DEFCDataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
extern int(*Level31_7DEFCData74348View1)() __asm__("unk_ovlheader_80074348");
extern int(*Level31_7DEFCData7434CView1)() __asm__("unk_ovlheader_8007434C");
extern int(*Level31_7DEFCData74350View1)() __asm__("unk_ovlheader_80074350");
extern int(*Level31_7DEFCData74354View1)() __asm__("unk_ovlheader_80074354");
extern int(*Level31_7DEFCData74358View1)() __asm__("unk_ovlheader_80074358");
void func_level_31_8007DEFC(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void *ownerRecord17 __asm__("$17");
    register int privateOrReturnedRecord16 __asm__("$16"), retainedAddressOrResult18 __asm__("$18"), retainedHeightOrBase19 __asm__("$19"), retainedFlag20 __asm__("$20"), retainedState21 __asm__("$21");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C;
    }
    originalFrame;
    ownerRecord17 = input;
    __asm__("":"=r"(ownerRecord17):"0"(ownerRecord17));
    Level31_7DEFCField(ownerRecord17, signed char *, 0x4C) = 0x40;
    Level31_7DEFCField(ownerRecord17, signed char *, 0x4E) = 0x40;
    Level31_7DEFCField(ownerRecord17, unsigned char *, 0x4A) = 0xFF;
    argumentWord4 = Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48);
    privateOrReturnedRecord16 = Level31_7DEFCField(ownerRecord17, void **, 0);
    if (argumentWord4 == 0x51) {
        Level31_7DEFCField(ownerRecord17, int *, 0x14) = (int) (Level31_7DEFCField(ownerRecord17, int *, 0x14) + Level31_7DEFCField(privateOrReturnedRecord16, int *, 0));
        rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, int *, 4);
        Level31_7DEFCField(privateOrReturnedRecord16, int *, 0) = (int) (Level31_7DEFCField(privateOrReturnedRecord16, int *, 0) - 0xA);
        if (Level31_7DEFCField(ownerRecord17, int *, 0x14) < rawWord3) {
            Level31_7DEFCField(ownerRecord17, int *, 0x14) = rawWord3;
            rawWord2 = (int) -Level31_7DEFCField(privateOrReturnedRecord16, int *, 0) >> 1;
            Level31_7DEFCField(privateOrReturnedRecord16, int *, 0) = rawWord2;
            if (rawWord2 < 0x20) {
                goto removeOriginalRecord;
            }
        }
    }
    else {
        if (argumentWord4 < 0x50U) {
            rawWord3 = Level31_7DEFCField(ownerRecord17, int *, 0x18);
            if (rawWord3 & 0xA0000) {
                Level31_7DEFCData74350View1(ownerRecord17, privateOrReturnedRecord16 + 0xC, 0xB);
                Level31_7DEFCCall38BF8View1(ownerRecord17, privateOrReturnedRecord16 + 0x18, 1, 7);
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 0x50U;
                Level31_7DEFCCall36A68View1(ownerRecord17, 0, 0, 0);
                goto continueOriginalStateDispatch;
            }
            if (rawWord3 & 0x10000) {
                if (({rawWord2 = (unsigned int)argumentWord4 < 12;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})) {
                    Level31_7DEFCData74348View1(ownerRecord17, privateOrReturnedRecord16 + 0xC, 0xB, 0x1C);
                }
                goto continueOriginalStateDispatch;
            }
            if (({rawWord2 = rawWord3&0x10000000;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})) {
                rawWord2 = 11;
                if (argumentWord4 == rawWord2) {
                    Level31_7DEFCField(privateOrReturnedRecord16, short *, 0x10) = 0;
                }
                else {
                    if (Level31_7DEFCField(privateOrReturnedRecord16, short *, 0xA) < 0x3C) {
                        Level31_7DEFCCall3BABCView1(ownerRecord17, 0, 1);
                        Level31_7DEFCField(privateOrReturnedRecord16, short *, 0xA) = 0x78;
                    }
                    if (Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) != 5) {
                        Level31_7DEFCField(privateOrReturnedRecord16, short *, 0xA) = 0x78;
                        Level31_7DEFCField(privateOrReturnedRecord16, short *, 6) = (short) (Level31_7DEFCDatarandView1() & 0xFF);
                        Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 5U;
                    }
                }
                if (Level31_7DEFCData74354View1(ownerRecord17) != 0) {
                    privateOrReturnedRecord16 = Level31_7DEFCDataSpawnMobyView1(0x3E, ownerRecord17);
                    __asm__("":"=r"(privateOrReturnedRecord16):"0"(privateOrReturnedRecord16));
                    if (privateOrReturnedRecord16 != 0) {
                        rawWord2 = Level31_7DEFCField(ownerRecord17, int*, 20);
                        retainedAddressOrResult18 = Level31_7DEFCField(privateOrReturnedRecord16, int*, 0);
                        retainedHeightOrBase19 = rawWord2-128;
                        Level31_7DEFCCall34F80View1(privateOrReturnedRecord16, 0xA);
                        retainedState21 = 81;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x48) = retainedState21;
                        rawWord2 = Level31_7DEFCField(ownerRecord17, unsigned char*, 0x46);
                        __asm__("":::"$20", "memory");
                        retainedFlag20 = 63;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x54) = 0;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x55) = 0;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x56) = 0;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x57) = retainedFlag20;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x46) = rawWord2;
                        rawWord2 = Level31_7DEFCDatarandView1();
                        argumentWord4 = 62;
                        __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                        argumentWord5 = (int)ownerRecord17;
                        rawWord2 &= 127;
                        rawWord3 = (int)Level31_7DEFCDataSpawnMobyView1;
                        __asm__("":"=r"(rawWord3):"0"(rawWord3));
                        rawWord2 += 32;
                        Level31_7DEFCField(retainedAddressOrResult18, int*, 0) = rawWord2;
                        Level31_7DEFCField(retainedAddressOrResult18, int*, 4) = retainedHeightOrBase19;
                        privateOrReturnedRecord16 = ((int(*)())rawWord3)(argumentWord4, argumentWord5);
                        __asm__("":"=r"(privateOrReturnedRecord16):"0"(privateOrReturnedRecord16));
                        if (privateOrReturnedRecord16 != 0) {
                            retainedAddressOrResult18 = Level31_7DEFCField(privateOrReturnedRecord16, void **, 0);
                            Level31_7DEFCCall34F80View1(privateOrReturnedRecord16, 0xB);
                            Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x48) = retainedState21;
                            rawWord2 = Level31_7DEFCField(ownerRecord17, unsigned char*, 0x46);
                            Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x54) = 0;
                            Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x55) = 0;
                            Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x56) = 0;
                            Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x57) = retainedFlag20;
                            Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 0x46) = rawWord2;
                            Level31_7DEFCField(retainedAddressOrResult18, int *, 0) = (int) ((Level31_7DEFCDatarandView1() & 0x7F) + 0x20);
                            Level31_7DEFCField(retainedAddressOrResult18, int *, 4) = retainedHeightOrBase19;
                        }
                    }
                    Level31_7DEFCCall3BB10View1(ownerRecord17, 3, 1);
                    Level31_7DEFCCall36A68View1(ownerRecord17, 0, 0, 0);
                    Level31_7DEFCCall3BA00View1(ownerRecord17);
                removeOriginalRecord:
                    Level31_7DEFCCall55B18View1(ownerRecord17);
                    return;
                }
                goto continueOriginalStateDispatch;
            }
            if (({rawWord2 = (unsigned int)argumentWord4 < 10;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})) {
                argumentWord7 = (int)&Level31_7DEFCData70328View1+80;
                __asm__("":"=r"(argumentWord7):"0"(argumentWord7));
                if (((unsigned int)(Level31_7DEFCField(argumentWord7, int*, 0)-7) >= 2U) && ({rawWord2 = Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int*, 0x240);__asm__("":::"$18", "memory");retainedAddressOrResult18 = argumentWord7-80;rawWord2 == 0;}) && (Level31_7DEFCCall4F264View1(Level31_7DEFCField(ownerRecord17, unsigned char *, 0x46), Level31_7DEFCCall4E880View1(Level31_7DEFCField(argumentWord7, int *, -0x50) - Level31_7DEFCField(ownerRecord17, int *, 0xC), Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int *, 4) - Level31_7DEFCField(ownerRecord17, int *, 0x10), 0)) < 0x18) && (Level31_7DEFCCall4F334View1(ownerRecord17+12, retainedAddressOrResult18) < 0x800)) {
                    Level31_7DEFCField(privateOrReturnedRecord16, unsigned char *, 9) = (unsigned char) Level31_7DEFCField(ownerRecord17, unsigned char *, 0x3D);
                    Level31_7DEFCField(privateOrReturnedRecord16, unsigned char *, 8) = (unsigned char) Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48);
                    rawWord2 = Level31_7DEFCField(ownerRecord17, unsigned char*, 0x46);
                    rawWord2 *= 2;
                    rawWord3 = Level31_7DEFCField((int)&Level31_7DEFCData65920View1, short*, rawWord2);
                    rawWord2 = rawWord3*25;
                    rawWord2 >>= 10;
                    Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int*, 0x21C) = rawWord2;
                    rawWord2 = Level31_7DEFCField(ownerRecord17, unsigned char*, 0x46);
                    argumentWord5 = 5;
                    rawWord2 *= 2;
                    rawWord3 = Level31_7DEFCField((int)&Level31_7DEFCData658A0View1, short*, rawWord2);
                    rawWord2 = 25;
                    Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int*, 0x224) = rawWord2;
                    rawWord2 = rawWord3*25;
                    rawWord2 >>= 10;
                    Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int*, 0x220) = rawWord2;
                    Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 0xAU;
                    Level31_7DEFCCall34F40View1(ownerRecord17, argumentWord5);
                }
            }
            else if (({rawWord2 = 10;__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 == rawWord2;})) {
                Level31_7DEFCCall55F14View1(ownerRecord17, 0, &originalFrame.sp20);
                if (Level31_7DEFCCall1C288View1(&originalFrame.sp20, 0x80, 0x80) == 0) {
                    Level31_7DEFCCall55F14View1(ownerRecord17, 1, &originalFrame.sp20);
                    Level31_7DEFCCall1C288View1(&originalFrame.sp20, 0x80, 0x80);
                }
            }
            goto continueOriginalStateDispatch;
        }
    continueOriginalStateDispatch:
        rawWord3 = Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48);
        Level31_7DEFCField(ownerRecord17, int *, 0x18) = 0;
        if ((rawWord3 != 5) && (rawWord3 != 0xB) && (rawWord3 != 0x50) && (Level31_7DEFCField(ownerRecord17, unsigned char *, 0x57) != 0)) {
            Level31_7DEFCData74358View1(ownerRecord17);
        }
        rawWord3 = Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48);
        switch (rawWord3) {
        case 0x5:
            if (Level31_7DEFCCall359A4View1(privateOrReturnedRecord16 + 0xA, 2) != 0) {
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 4U;
                Level31_7DEFCCall34F40View1(ownerRecord17, 0U);
            }
            else {
                retainedAddressOrResult18 = ownerRecord17 + 0xC;
                if (Level31_7DEFCCall3645CView1(retainedAddressOrResult18, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), &originalFrame.sp30) >= 0x801) {
                    rawWord2 = (originalFrame.sp30 * 0x10) + Level31_7DEFCField(Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), int *, 0xC);
                    Level31_7DEFCField(privateOrReturnedRecord16, short *, 6) = Level31_7DEFCCall4E880View1(Level31_7DEFCField(rawWord2, int *, 0) - Level31_7DEFCField(ownerRecord17, int *, 0xC), Level31_7DEFCField(rawWord2, int *, 4) - Level31_7DEFCField(ownerRecord17, int *, 0x10), 0);
                }
                Level31_7DEFCCall3585CView1(ownerRecord17, Level31_7DEFCField(privateOrReturnedRecord16, short *, 6), 6, 2, 1, 0);
                if (Level31_7DEFCCall35DDCView1(ownerRecord17, 0x78, 0x200, 0x200, 0x34) != 0) {
                    rawWord2 = (originalFrame.sp30 * 0x10) + Level31_7DEFCField(Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), int *, 0xC);
                    Level31_7DEFCField(privateOrReturnedRecord16, short *, 6) = Level31_7DEFCCall4E880View1(Level31_7DEFCField(rawWord2, int *, 0) - Level31_7DEFCField(ownerRecord17, int *, 0xC), Level31_7DEFCField(rawWord2, int *, 4) - Level31_7DEFCField(ownerRecord17, int *, 0x10), 0);
                }
                if ((Level31_7DEFCDatarandView1() & 0x80) < Level31_7DEFCField(privateOrReturnedRecord16, short *, 0xA)) {
                    originalFrame.sp38 = (Level31_7DEFCDatarandView1() & 0xF) - 8;
                    originalFrame.sp3C = (Level31_7DEFCDatarandView1() & 0xF) - 8;
                    originalFrame.sp40 = (Level31_7DEFCDatarandView1() & 0xF) + 8;
                    privateOrReturnedRecord16 = Level31_7DEFCDataSpawnParticleView1(1, 0, retainedAddressOrResult18, &originalFrame.sp38);
                    __asm__("":"=r"(privateOrReturnedRecord16):"0"(privateOrReturnedRecord16));
                    if (privateOrReturnedRecord16 != 0) {
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 8) = (unsigned short) (Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 8) + (Level31_7DEFCDatarandView1() & 0xFF));
                    default:
                    }
                }
            }
            break;
        case 0xB:
            Level31_7DEFCData7434CView1(ownerRecord17, privateOrReturnedRecord16 + 0xC);
            break;
        case 0x0:
            Level31_7DEFCField(ownerRecord17, unsigned char *, 0x49) = 0U;
            if (Level31_7DEFCCall35A80View1(ownerRecord17, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), 0x200, 0x78, 0, 3, 0x20, 0x34) & 2) {
                rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, int *, 0);
                Level31_7DEFCField(rawWord3, unsigned short *, 0xA) = (unsigned short) -(int) Level31_7DEFCField(rawWord3, unsigned short *, 0xA);
                argumentWord4 = Level31_7DEFCField(privateOrReturnedRecord16, int*, 0);
                rawWord2 = Level31_7DEFCField(argumentWord4, unsigned short*, 2);
                rawWord3 = Level31_7DEFCField(argumentWord4, unsigned short*, 0);
                rawWord2++;
                rawWord3 -= rawWord2;
                Level31_7DEFCField(argumentWord4, unsigned short*, 2) = rawWord3;
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 3U;
            }
            argumentWord5 = (int)&Level31_7DEFCData70328View1+0x240;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            rawWord2 = Level31_7DEFCField(argumentWord5, int*, 0);
            __asm__("":::"$16", "memory");
            if (!rawWord2){
                argumentWord4 = (int)ownerRecord17+12;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                privateOrReturnedRecord16 = argumentWord5-0x240;
                if ((Level31_7DEFCCall4F334View1(argumentWord4, privateOrReturnedRecord16) < 0x2800) && ((unsigned int) (Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int *, 0x50) - 7) >= 2U)) {
                    if (Level31_7DEFCCall4F264View1(({argumentWord4 = Level31_7DEFCData6E040View1;argumentWord4 <<= 16;__asm__("":"=r"(argumentWord4):"0"(argumentWord4));argumentWord4 >> 20;}), Level31_7DEFCCall4E880View1(Level31_7DEFCField(ownerRecord17, int *, 0xC) - Level31_7DEFCData6E020View1, Level31_7DEFCField(ownerRecord17, int *, 0x10) - Level31_7DEFCData6E024View1, 0)) < 0x20) {
                        Level31_7DEFCCall1A358View1(privateOrReturnedRecord16, 0x1000);
                        if (Level31_7DEFCCall40954View1(Level31_7DEFCData71924View1) == 0xB) {
                            Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 1U;
                            Level31_7DEFCCall34F40View1(ownerRecord17, 4U);
                        }
                    }
                }
            }
            break;
        case 0x3:
            if (!(Level31_7DEFCCall35A80View1(ownerRecord17, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), 0x200, 0x28, 0, 8, 0x7F, 0x34) & 4)) {
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 0U;
            }
            break;
        case 0x1:
            Level31_7DEFCCall3573CView1(ownerRecord17, 6, 0, 1);
            if (Level31_7DEFCData6C770View1 != 0) {
                Level31_7DEFCCall3645CView1((int)&Level31_7DEFCData70328View1, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), &originalFrame.sp48);
                rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, int*, 0);
                argumentWord5 = Level31_7DEFCField(rawWord3, short*, 2);
                __asm__("":::"$4", "memory");
                argumentWord4 = originalFrame.sp48;
                rawWord2 = argumentWord4 < argumentWord5;
                argumentWord6 = argumentWord5;
                if (rawWord2){
                    rawWord2 = argumentWord6-1;
                    goto storeOriginalSequenceSelector;
                }
                rawWord2 = argumentWord5 < argumentWord4;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                if (rawWord2){
                    rawWord2 = argumentWord6+1;
                    storeOriginalSequenceSelector:Level31_7DEFCField(rawWord3, unsigned short*, 2) = rawWord2;
                }
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 2U;
                Level31_7DEFCCall34F40View1(ownerRecord17, 1U);
            }
            break;
        case 0xA:
            argumentWord4 = (int)ownerRecord17+12;
            if (Level31_7DEFCData6C770View1 != 0) {
                Level31_7DEFCCall34F40View1(ownerRecord17, Level31_7DEFCField(privateOrReturnedRecord16, unsigned char *, 9));
                rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, unsigned char*, 8);
                __asm__("":::"$2", "memory");
                rawWord2 = 1;
                Level31_7DEFCField(ownerRecord17, unsigned char*, 0x49) = rawWord2;
                Level31_7DEFCField(ownerRecord17, unsigned char*, 0x48) = rawWord3;
                __asm__("":"=r"(ownerRecord17):"0"(ownerRecord17));
                argumentWord4 = (int)ownerRecord17+12;
            }
            if ((Level31_7DEFCCall3645CView1(argumentWord4, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), &originalFrame.sp4C) < 0x1C01) && (Level31_7DEFCCall4F264View1(({argumentWord4 = Level31_7DEFCData6E040View1;argumentWord4 <<= 16;__asm__("":"=r"(argumentWord4):"0"(argumentWord4));argumentWord4 >> 20;}), Level31_7DEFCCall4E880View1(Level31_7DEFCField(ownerRecord17, int *, 0xC) - Level31_7DEFCData6E020View1, Level31_7DEFCField(ownerRecord17, int *, 0x10) - Level31_7DEFCData6E024View1, 0)) < 0x21) && ((unsigned int) (Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int *, 0x50) - 7) >= 2U) && (Level31_7DEFCField(ownerRecord17, unsigned char *, 0x49) == 0)) {
                rawWord2 = Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int*, 0x240);
                argumentWord4 = (int)ownerRecord17;
                if (rawWord2) goto callOriginalFinalHelper;
                argumentWord5 = 6;
                goto callOriginalSharedMovement;
            }
            break;
        case 0x2:
            retainedAddressOrResult18 = ownerRecord17 + 0xC;
            if ((Level31_7DEFCCall3645CView1(retainedAddressOrResult18, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), &originalFrame.sp50) >= 0x1C01) || (Level31_7DEFCCall4F264View1(({argumentWord4 = Level31_7DEFCData6E040View1;argumentWord4 <<= 16;__asm__("":"=r"(argumentWord4):"0"(argumentWord4));argumentWord4 >> 20;}), Level31_7DEFCCall4E880View1(Level31_7DEFCField(ownerRecord17, int *, 0xC) - Level31_7DEFCData6E020View1, Level31_7DEFCField(ownerRecord17, int *, 0x10) - Level31_7DEFCData6E024View1, 0)) >= 0x21) || ((unsigned int)(Level31_7DEFCField(({argumentWord5 = (int)&Level31_7DEFCData70328View1+80;__asm__("":"=r"(argumentWord5):"0"(argumentWord5));argumentWord5;}), int*, 0)-7) < 2U) || (Level31_7DEFCField(ownerRecord17, unsigned char *, 0x49) != 0) || ({rawWord2 = Level31_7DEFCField((int)&Level31_7DEFCData70328View1, int*, 0x240);argumentWord4 = retainedAddressOrResult18;rawWord2 != 0;})) {
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x49) = 0U;
                Level31_7DEFCField(Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), unsigned short *, 2) = (unsigned short) originalFrame.sp50;
                Level31_7DEFCField(privateOrReturnedRecord16, short *, 0xA) = 0xB4;
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 4U;
                Level31_7DEFCCall34F40View1(ownerRecord17, 0U);
            }
            else {
                __asm__("":::"$19");
                retainedHeightOrBase19 = argumentWord5-80;
                rawWord2 = Level31_7DEFCCall4F334View1(argumentWord4, retainedHeightOrBase19);
                {
                    int retainedDistance = rawWord2;
                    Level31_7DEFCCall1A358View1(retainedHeightOrBase19, 4096);
                    retainedAddressOrResult18 = retainedDistance;
                }
                argumentWord4 = (int)ownerRecord17;
                if ((retainedAddressOrResult18 >= 0x3001) || ({rawWord2 = Level31_7DEFCCall40954View1(Level31_7DEFCData71924View1);rawWord3 = 11;__asm__("":"=r"(rawWord3):"0"(rawWord3));argumentWord4 = (int)ownerRecord17;rawWord2 != rawWord3;})) {
                    Level31_7DEFCField(Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), unsigned short *, 2) = (unsigned short) originalFrame.sp50;
                    Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 0U;
                    Level31_7DEFCCall34F40View1(argumentWord4, 0);
                }
                else {
                    if (({rawWord2 = retainedAddressOrResult18 < 0x1800;argumentWord5 = 6;rawWord2;})){
                        callOriginalSharedMovement:Level31_7DEFCCall3573CView1(argumentWord4, argumentWord5, 0, 1);
                        Level31_7DEFCCall35DDCView1(ownerRecord17, 200, 512, 512, 52);
                        goto reloadOwnerBeforeFinalCall;
                    }
                    Level31_7DEFCCall3645CView1(retainedHeightOrBase19, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), &originalFrame.sp50);
                    argumentWord4 = Level31_7DEFCField(privateOrReturnedRecord16, int *, 0);
                    rawWord2 = originalFrame.sp50;
                    rawWord3 = Level31_7DEFCField(argumentWord4, short*, 2);
                    rawWord2 = rawWord2 < rawWord3;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    if (!rawWord2){
                        rawWord2 = 1;
                    }
                    else{
                        rawWord2 = -1;
                    }
                    Level31_7DEFCField(argumentWord4, unsigned short*, 10) = rawWord2;
                    Level31_7DEFCCall35A80View1(ownerRecord17, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), 0x200, 0xC8, 0, 0xA, 0x20, 0x34);
                }
            }
            break;
        case 0x4:
            Level31_7DEFCCall35A80View1(ownerRecord17, Level31_7DEFCField(privateOrReturnedRecord16, int *, 0), 0x200, 0x78, 0, 0xA, 0x18, 0x34);
            if (Level31_7DEFCCall359A4View1(privateOrReturnedRecord16 + 0xA, 2) != 0) {
                Level31_7DEFCField(ownerRecord17, unsigned char *, 0x48) = 0U;
            }
            break;
        case 0x50:
            if (Level31_7DEFCCall35194View1(ownerRecord17, privateOrReturnedRecord16 + 0x18) == 0x100) {
                retainedAddressOrResult18 = 0;
                do {
                    originalFrame.sp38 = (Level31_7DEFCDatarandView1() & 0xF) - 8;
                    originalFrame.sp3C = (Level31_7DEFCDatarandView1() & 0xF) - 8;
                    originalFrame.sp40 = (Level31_7DEFCDatarandView1() & 0xF) + 8;
                    privateOrReturnedRecord16 = Level31_7DEFCDataSpawnParticleView1(1, 0, ownerRecord17 + 0xC, &originalFrame.sp38);
                    __asm__("":"=r"(privateOrReturnedRecord16):"0"(privateOrReturnedRecord16));
                    if (privateOrReturnedRecord16 != 0) {
                        rawWord2 = Level31_7DEFCDatarandView1();
                        rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 4);
                        rawWord2 &= 127;
                        rawWord3 -= 63;
                        rawWord3 += rawWord2;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 4) = rawWord3;
                        rawWord2 = Level31_7DEFCDatarandView1();
                        rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 6);
                        rawWord2 &= 127;
                        rawWord3 -= 63;
                        rawWord3 += rawWord2;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 6) = rawWord3;
                        rawWord2 = Level31_7DEFCDatarandView1();
                        rawWord3 = Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 8);
                        rawWord2 &= 127;
                        rawWord3 += rawWord2;
                        Level31_7DEFCField(privateOrReturnedRecord16, unsigned short *, 8) = rawWord3;
                    }
                    retainedAddressOrResult18 += 1;
                }
                while (retainedAddressOrResult18 < 0x10);
                Level31_7DEFCCall3BA00View1(ownerRecord17);
                Level31_7DEFCCall55B18View1(ownerRecord17);
            }
            else if (Level31_7DEFCField(ownerRecord17, unsigned char *, 0x3D) == 8) {
                Level31_7DEFCField(ownerRecord17, short *, 0x38) = 0x200;
            }
            break;
        }
        reloadOwnerBeforeFinalCall:argumentWord4 = (int)ownerRecord17;
        callOriginalFinalHelper:Level31_7DEFCCall55D24View1(argumentWord4, 4);
    }
}
#undef Level31_7DEFCField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007EBF4.
* AI generated; not human reviewed. All811 original instructions,seven
* selectors,one zero pad and every actual destination must match:819 words.
* Frame58hex=88 bytes saves S0..S4/RA;SP18..3F retains original vectors.
* Full stride88 list indices and private pointers retain original widths.
* Original particle loop exits to125 after the removal branch;state/heading
* and child common671 follow their original physical entries. State4's
* failed child condition enters583 inside that state. All targets are gated.
* Two random particles preserve all three random calls,original signed
* division and zero/overflow guards. Owner byte4F is the full denominator;
* numerator15,denominator32 yields0. Byte countdown writes retain full+255
* before truncation. Original641 is LW through the child's private pointer,
* followed by SB to global object's byte76:0x12345678 stores0x78.
* Original spawn/global producers precede the private34 store. Helper35D38
* is followed by a fresh private34 reload;no child pointer is cached across
* that call. The original initialized fifth argument48 atSP10 is written
* before fresh A0..A3 arguments;SP is the complete incoming ABI frame address.
* Private/vector and owner/late-vector saved register phases do not overlap.
* Known timer,angle and spawn views reuse matched EXE/header evidence.
* Empty metadata consumes complete initialized values or clobbers dead words
* before fresh complete producers;zero CPU instructions. No opcode asm,
* partialHI,fixedFP,undefined saved inputs,overlapping live aliases or build
* pipeline changes. Raw units/fixed point,complete helper/caller chains,
* cadence beyond invocation,Rev1 mapping and synchronized runtime remain open.
* Confidence is binary identity after all gates. Next:human review and retail
* captures. Every native/linked word,target,selector/padding byte and full
* EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 cdf9d5a275746faa2b4da32c4bd24f98b3f44d68aa977c6c3ca22ed1f5f19831 */
#define Level31_7EBF4Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level31_7EBF4Call13AE4View1() __asm__("func_80013AE4");
int Level31_7EBF4Call13D44View1() __asm__("func_80013D44");
int Level31_7EBF4Call34F40View1() __asm__("func_80034F40");
int Level31_7EBF4Call34F80View1() __asm__("func_80034F80");
int Level31_7EBF4Call3573CView1() __asm__("func_8003573C");
int Level31_7EBF4Call3585CView1() __asm__("func_8003585C");
int Level31_7EBF4Call359A4View1(void*, int) __asm__("func_800359A4");
int Level31_7EBF4Call35D38View1() __asm__("func_80035D38");
int Level31_7EBF4Call35DDCView1() __asm__("func_80035DDC");
int Level31_7EBF4Call35EE0View1() __asm__("func_80035EE0");
int Level31_7EBF4Call36220View1() __asm__("func_80036220");
int Level31_7EBF4Call365E4View1() __asm__("func_800365E4");
int Level31_7EBF4Call369B8View1() __asm__("func_800369B8");
int Level31_7EBF4Call36A68View1() __asm__("func_80036A68");
int Level31_7EBF4Call3BA00View1() __asm__("func_8003BA00");
int Level31_7EBF4Call3BABCView1() __asm__("func_8003BABC");
int Level31_7EBF4Call3BB10View1() __asm__("func_8003BB10");
int Level31_7EBF4Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level31_7EBF4Call4F110View1() __asm__("func_8004F110");
int Level31_7EBF4Call4F178View1() __asm__("func_8004F178");
int Level31_7EBF4Call4F194View1() __asm__("func_8004F194");
int Level31_7EBF4Call4F1C8View1() __asm__("func_8004F1C8");
int Level31_7EBF4Call4F264View1(int, int) __asm__("func_8004F264");
int Level31_7EBF4Call4F334View1() __asm__("func_8004F334");
int Level31_7EBF4Call55B18View1() __asm__("func_80055B18");
int Level31_7EBF4Call55D24View1() __asm__("func_80055D24");
int Level31_7EBF4Call55E84View1() __asm__("func_80055E84");
int Level31_7EBF4Call55F14View1() __asm__("func_80055F14");
int Level31_7EBF4DatarandView1(void) __asm__("rand");
extern int Level31_7EBF4Data6C550View1 __asm__("D_8006C550");
extern int Level31_7EBF4Data6C640View1 __asm__("D_8006C640");
extern int Level31_7EBF4Data6C65CView1 __asm__("D_8006C65C");
extern int Level31_7EBF4Data6C770View1 __asm__("D_8006C770");
extern int Level31_7EBF4Data6E020View1 __asm__("D_8006E020");
extern int Level31_7EBF4Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level31_7EBF4Data6E040View1 __asm__("D_8006E040");
extern int Level31_7EBF4Data6E048View1 __asm__("D_8006E048");
extern int Level31_7EBF4Data6E1CCView1 __asm__("D_8006E1CC");
extern int Level31_7EBF4Data70328View1 __asm__("D_80070328");
extern void*(*Level31_7EBF4DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern void*(*Level31_7EBF4DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
void func_level_31_8007EBF4(void *ownerParameter) {
    register unsigned char *originalOutgoingFrame __asm__("$29");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void *ownerOrLateVector17 __asm__("$17");
    register int privateRecord19 __asm__("$19"), retainedPrivateOrVector16 __asm__("$16"), retainedLoopIndexOrHeight18 __asm__("$18"), linkedRecordPrivate20 __asm__("$20");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C;
    }
    originalFrame;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord15;
    int temporaryWord24;
    int temporaryWord32;
    int temporaryWord35;
    int temporaryWord5;
    int temporaryWord10;
    int temporaryWord18;
    int temporaryWord25;
    int temporaryWord26;
    int temporaryWord36;
    int temporaryWord27;
    int temporaryWord28;
    int temporaryWord29;
    int temporaryWord31;
    int temporaryWord34;
    int temporaryWord33;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord14;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord19;
    int temporaryWord20;
    int temporaryWord21;
    int temporaryWord22;
    int temporaryWord23;
    int temporaryWord30;
    ownerOrLateVector17 = ownerParameter;
    __asm__("":"=r"(ownerOrLateVector17):"0"(ownerOrLateVector17));
    privateRecord19 = Level31_7EBF4Field(ownerOrLateVector17, void **, 0);
    temporaryWord25 = Level31_7EBF4Field(privateRecord19, int *, 0x2C);
    if (temporaryWord25 >= 0) {
        temporaryWord33 = Level31_7EBF4Data6C550View1 + (temporaryWord25 * 0x58);
        linkedRecordPrivate20 = Level31_7EBF4Field(temporaryWord33, void **, 0);
        if (Level31_7EBF4Field(temporaryWord33, unsigned char *, 0x48) == 0) {
            temporaryWord26 = Level31_7EBF4Field(privateRecord19, int *, 0x30);
            if (temporaryWord26 >= 0) {
                temporaryWord33 = Level31_7EBF4Data6C550View1 + (temporaryWord26 * 0x58);
                linkedRecordPrivate20 = Level31_7EBF4Field(temporaryWord33, int*, 0);
            }
            if (Level31_7EBF4Field(temporaryWord33, unsigned char *, 0x48) != 0) {
                goto checkOriginalOwnerFlag;
            }
            goto updateOriginalIndependentState;
        }
    checkOriginalOwnerFlag:
        if (Level31_7EBF4Field(ownerOrLateVector17, int *, 0x18) & 0x10000000) {
            if (Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) == 0) {
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) = 0x20U;
            }
            temporaryWord27 = Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F);
            if (temporaryWord27 < 0xA0U) {
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) = (unsigned char) (temporaryWord27 + 2);
                retainedLoopIndexOrHeight18 = 0;
                do {
                    originalFrame.sp18 = (Level31_7EBF4DatarandView1() & 0xF) - 8;
                    originalFrame.sp1C = (Level31_7EBF4DatarandView1() & 0xF) - 8;
                    originalFrame.sp20 = (Level31_7EBF4DatarandView1() & 0xF) + 8;
                    temporaryWord11 = Level31_7EBF4DataSpawnParticleView1(1, 0, ownerOrLateVector17 + 0xC, &originalFrame.sp18);
                    if (temporaryWord11 != 0) {
                        Level31_7EBF4Field(temporaryWord11, unsigned short *, 8) = (unsigned short) (Level31_7EBF4Field(temporaryWord11, unsigned short *, 8) + ((int) (Level31_7EBF4DatarandView1() & 0x7FFF) / (int) Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F)));
                    }
                    retainedLoopIndexOrHeight18 += 1;
                }
                while (retainedLoopIndexOrHeight18 < 2);
                goto finishOriginalParticleLoop125;
            }
            Level31_7EBF4Call3BB10View1(ownerOrLateVector17, 3, 1);
            Level31_7EBF4Call36A68View1(ownerOrLateVector17, 1, 0, 0);
            Level31_7EBF4Call55D24View1(ownerOrLateVector17, 4);
            Level31_7EBF4Call3BA00View1(ownerOrLateVector17);
            Level31_7EBF4Call369B8View1(ownerOrLateVector17, 0x18);
            Level31_7EBF4Call55B18View1(ownerOrLateVector17);
            return;
        finishOriginalParticleLoop125:
            if (Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) != 7) {
                Level31_7EBF4Call3BABCView1(ownerOrLateVector17, 0, 1);
            }
            Level31_7EBF4Call34F40View1(ownerOrLateVector17, 4);
            Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 7U;
            Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x49) = 0x3CU;
            goto clearOriginalOwnerFlags;
        }
        if ((unsigned char) Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) >= 0x21U) {
            if (Level31_7EBF4Data6C770View1 != 0) {
                Level31_7EBF4Call34F40View1(ownerOrLateVector17, 6);
            }
            if (!(Level31_7EBF4Data6C640View1 & 3)) {
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) = (unsigned char) (Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) - 1);
            }
        }
        else if (Level31_7EBF4Data6C770View1 != 0) {
            Level31_7EBF4Call34F40View1(ownerOrLateVector17, 0);
        }
    clearOriginalOwnerFlags:
        Level31_7EBF4Field(ownerOrLateVector17, int *, 0x18) = 0;
        if (Level31_7EBF4Data6E048View1 & 1) {
            Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x4F) = 0U;
            Level31_7EBF4Call4F178View1(ownerOrLateVector17 + 0xC, Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC));
            temporaryWord17 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
            Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x46) = Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord17, int *, 0x10) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC), Level31_7EBF4Field(temporaryWord17, int *, 0x14) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10), 0);
            Level31_7EBF4Call34F40View1(ownerOrLateVector17, 0);
            Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 0U;
        }
        temporaryWord28 = Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48);
        switch (temporaryWord28) {
        case 7:
            retainedPrivateOrVector16 = Level31_7EBF4Field(((Level31_7EBF4Field(linkedRecordPrivate20, int *, 0x2C) * 0x58) + Level31_7EBF4Data6C550View1), int*, 0);
            rawWord2 = Level31_7EBF4Call4F334View1(ownerOrLateVector17+12, privateRecord19+12);
            argumentWord6 = 0;
            if (rawWord2 >= 3073){
                rawWord3 = Level31_7EBF4Field(privateRecord19, int*, 12);
                argumentWord4 = Level31_7EBF4Field(ownerOrLateVector17, int*, 12);
                rawWord2 = Level31_7EBF4Field(privateRecord19, int*, 16);
                argumentWord5 = Level31_7EBF4Field(ownerOrLateVector17, int*, 16);
                argumentWord4 = rawWord3-argumentWord4;
            }
            else{
                rawWord3 = Level31_7EBF4Field(ownerOrLateVector17, int*, 12);
                argumentWord4 = Level31_7EBF4Field(retainedPrivateOrVector16, int*, 0);
                rawWord2 = Level31_7EBF4Field(ownerOrLateVector17, int*, 16);
                argumentWord5 = Level31_7EBF4Field(retainedPrivateOrVector16, int*, 4);
                argumentWord4 = rawWord3-argumentWord4;
            }
            rawWord2 = Level31_7EBF4Call4E880View1(argumentWord4, rawWord2-argumentWord5, argumentWord6);
            Level31_7EBF4Call3585CView1(ownerOrLateVector17, rawWord2, 6, 0, 0, 1);
            rawWord2 = 48;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Level31_7EBF4Field(originalOutgoingFrame, int volatile*, 16) = rawWord2;
            __asm__ volatile("":::"$4", "$5", "$6", "$7", "memory");
            Level31_7EBF4Call35DDCView1(ownerOrLateVector17, 100, 500, 500);
            if (Level31_7EBF4Call359A4View1(ownerOrLateVector17 + 0x49, 1) != 0) {
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 0U;
                return;
            }
            break;
        case 0:
            Level31_7EBF4Call3573CView1(ownerOrLateVector17, 6, 0, 1);
            return;
        }
    }
    else {
    updateOriginalIndependentState:
        Level31_7EBF4Field(ownerOrLateVector17, int *, 0x18) = 0;
        temporaryWord18 = Level31_7EBF4Call4F334View1(ownerOrLateVector17 + 0xC, (int)&Level31_7EBF4Data70328View1);
        if ((temporaryWord18 < 0x3000) && (Level31_7EBF4Call4F264View1((int) (Level31_7EBF4Data6E040View1 << 0x10) >> 0x14, Level31_7EBF4Call4E880View1(Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC) - Level31_7EBF4Data6E020View1, Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10) - Level31_7EBF4Data6E024View1, 0)) < 0x18)) {
            Level31_7EBF4Data6E1CCView1 = (int) (0x3000 - temporaryWord18) >> 6;
        }
        temporaryWord29 = Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48);
        switch (temporaryWord29) {
        case 0:
            retainedPrivateOrVector16 = 0x12C;
            if (Level31_7EBF4Field(privateRecord19, int *, 0x2C) >= 0) {
                retainedPrivateOrVector16 = 0x1F4;
            }
            Level31_7EBF4Call3573CView1(ownerOrLateVector17, 6, 0, 1);
            if (Level31_7EBF4Call36220View1((int)&Level31_7EBF4Data70328View1, privateRecord19 + 0xC, 0, 0x800) != 0) {
                Level31_7EBF4Call34F40View1(ownerOrLateVector17, 2);
                Level31_7EBF4Call35DDCView1(ownerOrLateVector17, 0xC8, retainedPrivateOrVector16, retainedPrivateOrVector16, 0x30);
            }
            else {
                temporaryWord19 = Level31_7EBF4Field(privateRecord19, void **, 0x28);
                if (Level31_7EBF4Call4F334View1(ownerOrLateVector17 + 0xC, Level31_7EBF4Field(temporaryWord19, void **, 0xC) + (Level31_7EBF4Field(temporaryWord19, short *, 2) * 0x10)) >= 0x201) {
                    temporaryWord30 = Level31_7EBF4Field(privateRecord19, void **, 0x28);
                    rawWord2 = Level31_7EBF4Field(temporaryWord30, short*, 2)*16+Level31_7EBF4Field(temporaryWord30, int*, 12);
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    temporaryWord20 = rawWord2;
                    Level31_7EBF4Call35EE0View1(ownerOrLateVector17, Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord20, int *, 0) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC), Level31_7EBF4Field(temporaryWord20, int *, 4) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10), 0), 0x64, retainedPrivateOrVector16, retainedPrivateOrVector16, 0x30);
                }
                else {
                    Level31_7EBF4Call34F40View1(ownerOrLateVector17, 0);
                }
            }
            temporaryWord36 = ((Level31_7EBF4Field(ownerOrLateVector17, int *, 0x14) - Level31_7EBF4Field(ownerOrLateVector17, short *, 0x38)) - Level31_7EBF4Field((int)&Level31_7EBF4Data70328View1, int *, 8)) + Level31_7EBF4Field((int)&Level31_7EBF4Data70328View1, int *, 0x44);
            if (temporaryWord36 < 0) {
                temporaryWord36 = -temporaryWord36;
            }
            retainedPrivateOrVector16 = ownerOrLateVector17 + 0xC;
            if ((temporaryWord36 < 0x800) && (Level31_7EBF4Call4F334View1(retainedPrivateOrVector16, ((int)&Level31_7EBF4Data70328View1 + 8) - 8) < 0x800)) {
                Level31_7EBF4Call34F40View1(ownerOrLateVector17, 9);
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 1U;
                Level31_7EBF4Call13D44View1(retainedPrivateOrVector16, Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x46), 0, 0);
            }
            goto updateOriginalCommonChild671;
            default:goto updateOriginalCommonChild671;
        case 1:
            if ((Level31_7EBF4Data6E048View1 == 1) && (temporaryWord5 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x24), int *, 0xC), Level31_7EBF4Call13AE4View1(temporaryWord5, temporaryWord5 + 0x10), Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x49) = 1U, Level31_7EBF4Call34F80View1(ownerOrLateVector17, 0xA), Level31_7EBF4Call4F178View1(ownerOrLateVector17 + 0xC, Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC) + 0x20), temporaryWord23 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC), Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x46) = Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord23, int *, 0x30) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC), Level31_7EBF4Field(temporaryWord23, int *, 0x34) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10), 0), Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 2U, Level31_7EBF4Call55D24View1(ownerOrLateVector17, 4), temporaryWord24 = Level31_7EBF4DataSpawnMobyView1(0xFA, ownerOrLateVector17), argumentWord4 = Level31_7EBF4Data6C65CView1, Level31_7EBF4Field(privateRecord19, void **, 0x34) = temporaryWord24, (argumentWord4 != 0))) {
                if (temporaryWord24 != 0) {
                    rawWord2 = Level31_7EBF4Field(temporaryWord24, int*, 0);
                    rawWord3 = Level31_7EBF4Field(argumentWord4, unsigned char*, 76);
                    Level31_7EBF4Field(rawWord2, int*, 0) = rawWord3;
                    Level31_7EBF4Field(argumentWord4, unsigned char*, 76) = 0;
                    Level31_7EBF4Field(Level31_7EBF4Data6C65CView1, signed char *, 0x4D) = 0;
                    goto updateOriginalCommonChild671;
                }
            }
            else {
                goto updateOriginalCommonChild671;
            }
            break;
        case 2:
            if (Level31_7EBF4Call4F334View1(ownerOrLateVector17 + 0xC, Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC) + 0x30) < 0x400) {
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 3U;
            }
            else {
                temporaryWord12 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
                if (Level31_7EBF4Call3585CView1(ownerOrLateVector17, Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord12, int *, 0x30) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC), Level31_7EBF4Field(temporaryWord12, int *, 0x34) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10), 0), 3, 0, 0, 1) != 0) {
                    Level31_7EBF4Call35DDCView1(ownerOrLateVector17, 0x7D, 0, 0, 0x30);
                }
            }
            goto updateOriginalCommonChild671;
        case 3:
            temporaryWord13 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
            if ((Level31_7EBF4Call3585CView1(ownerOrLateVector17, Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord13, int *, 0x40) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC), Level31_7EBF4Field(temporaryWord13, int *, 0x44) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10), 0), 3, 0, 0, 1) != 0) && (Level31_7EBF4Data6C770View1 != 0)) {
                temporaryWord31 = Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x49);
                rawWord2 = temporaryWord31+255;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char*, 73) = rawWord2;
                if (temporaryWord31 == 0) {
                    temporaryWord6 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
                    if (temporaryWord6 != 0) {
                        Level31_7EBF4Call34F40View1(temporaryWord6, 1);
                    }
                    Level31_7EBF4Call34F40View1(ownerOrLateVector17, 0xB);
                    Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 4U;
                }
            }
            goto updateOriginalCommonChild671;
        case 4:
            if (Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, int*, 52), unsigned char*, 72) == 0){
                argumentWord6 = 600;
                if (Level31_7EBF4Data6C770View1 != 0) goto activateOriginalChild557;
                rawWord2 = Level31_7EBF4Call55E84View1(ownerOrLateVector17);
                argumentWord6 = 600;
                if (rawWord2 < 27) goto continueOriginalStateAt583;
            activateOriginalChild557:
                __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
                rawWord2 = 1;
                rawWord3 = Level31_7EBF4Field(privateRecord19, int*, 52);
                argumentWord7 = -10;
                Level31_7EBF4Field(rawWord3, unsigned char*, 72) = rawWord2;
                argumentWord4 = Level31_7EBF4Field(privateRecord19, int*, 52);
                rawWord2 = Level31_7EBF4Field(privateRecord19, int*, 40);
                retainedPrivateOrVector16 = Level31_7EBF4Field(rawWord3, int*, 0);
                Level31_7EBF4Field(retainedPrivateOrVector16, int*, 4) = Level31_7EBF4Call365E4View1(argumentWord4+12, Level31_7EBF4Field(rawWord2, int*, 12)+64, argumentWord6, argumentWord7, &originalFrame.sp28);
                Level31_7EBF4Call4F178View1((retainedPrivateOrVector16+8), Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x24), int *, 0xC) + 0x10);
                temporaryWord7 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
                if (temporaryWord7 != 0) {
                    Level31_7EBF4Call34F80View1(temporaryWord7, 3);
                }
            }
        continueOriginalStateAt583:
            if (Level31_7EBF4Data6C770View1 != 0) {
                Level31_7EBF4Call34F40View1(ownerOrLateVector17, 6);
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 5U;
            }
            goto updateOriginalCommonChild671;
        case 5:
            if (Level31_7EBF4Data6C770View1 != 0) {
                temporaryWord32 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
                if (temporaryWord32 != 0) {
                    Level31_7EBF4Field(temporaryWord32, unsigned char *, 0x48) = 2U;
                }
                temporaryWord14 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
                temporaryWord10 = Level31_7EBF4Field(temporaryWord14, int *, 0x30);
                Level31_7EBF4Call13D44View1(Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC) + 0x40, Level31_7EBF4Call4E880View1(temporaryWord10 - Level31_7EBF4Field(temporaryWord14, int *, 0x40), Level31_7EBF4Field(temporaryWord14, int *, 0x34) - Level31_7EBF4Field(temporaryWord14, int *, 0x44), 0), 0, 0);
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 6U;
            }
            goto updateOriginalCommonChild671;
        case 6:
            if (Level31_7EBF4Data6E048View1 & 1) {
                if (Level31_7EBF4Data6C65CView1 != 0) {
                    temporaryWord15 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
                    if (temporaryWord15 != 0) {
                        rawWord2 = Level31_7EBF4Field(Level31_7EBF4Field(temporaryWord15, int*, 0), int*, 0);
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        Level31_7EBF4Field(Level31_7EBF4Data6C65CView1, unsigned char*, 76) = rawWord2;
                        goto removeOriginalChild;
                    }
                }
                else {
                removeOriginalChild:
                    temporaryWord8 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
                    if (temporaryWord8 != 0) {
                        Level31_7EBF4Call55B18View1(temporaryWord8);
                    }
                }
                Level31_7EBF4Field(privateRecord19, void **, 0x34) = 0;
                Level31_7EBF4Call34F80View1(ownerOrLateVector17, 0);
                Level31_7EBF4Call4F178View1(ownerOrLateVector17 + 0xC, Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC));
                temporaryWord16 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x46) = Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord16, int *, 0x10) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0xC), Level31_7EBF4Field(temporaryWord16, int *, 0x14) - Level31_7EBF4Field(ownerOrLateVector17, int *, 0x10), 0);
                Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x48) = 0U;
            }
            goto updateOriginalCommonChild671;
        }
    }
    return;
updateOriginalCommonChild671:
    if (Level31_7EBF4Field(privateRecord19, void **, 0x34) != 0) {
        Level31_7EBF4Field((int)&Level31_7EBF4Data70328View1, int *, 0x20C) = (int) (Level31_7EBF4Field((int)&Level31_7EBF4Data70328View1, int *, 0x20C) | 0x10002000);
        temporaryWord1 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
        if (Level31_7EBF4Field(temporaryWord1, unsigned char *, 0x48) == 0) {
            Level31_7EBF4Call55D24View1(ownerOrLateVector17, 4);
            Level31_7EBF4Call55F14View1(ownerOrLateVector17, 0, Level31_7EBF4Field(privateRecord19, void **, 0x34) + 0xC);
            Level31_7EBF4Call55F14View1(ownerOrLateVector17, 1, &originalFrame.sp18);
            temporaryWord2 = Level31_7EBF4Field(privateRecord19, void **, 0x34) + 0xC;
            Level31_7EBF4Call4F194View1(temporaryWord2, temporaryWord2, &originalFrame.sp18);
            Level31_7EBF4Call4F110View1(Level31_7EBF4Field(privateRecord19, void **, 0x34) + 0xC, 1);
            Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x34), unsigned char *, 0x46) = (unsigned char) Level31_7EBF4Field(ownerOrLateVector17, unsigned char *, 0x46);
            return;
        }
        retainedPrivateOrVector16 = Level31_7EBF4Field(temporaryWord1, void **, 0);
        retainedLoopIndexOrHeight18 = Level31_7EBF4Call35D38View1(temporaryWord1);
        temporaryWord3 = Level31_7EBF4Field(privateRecord19, int*, 52);
        if (Level31_7EBF4Field(temporaryWord3, unsigned char *, 0x3C) == 3) {
            Level31_7EBF4Field(temporaryWord3, unsigned char *, 0x45) = (unsigned char) (Level31_7EBF4Field(temporaryWord3, unsigned char *, 0x45) - 0x10);
        }
        Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x34), int *, 0x14) = (int) (Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x34), int *, 0x14) + Level31_7EBF4Field(retainedPrivateOrVector16, int *, 4));
        temporaryWord4 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
        if ((retainedLoopIndexOrHeight18 + 0x100) >= Level31_7EBF4Field(temporaryWord4, int *, 0x14)) {
            Level31_7EBF4Call34F80View1(temporaryWord4, 2);
            Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x34), int *, 0x14) = retainedLoopIndexOrHeight18;
            Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x34), unsigned char *, 0x45) = 0U;
            Level31_7EBF4Field(retainedPrivateOrVector16, int *, 4) = 0;
            temporaryWord21 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
            argumentWord5 = Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord21, int*, 64)-Level31_7EBF4Field(ownerOrLateVector17, int*, 12), Level31_7EBF4Field(temporaryWord21, int*, 68)-Level31_7EBF4Field(ownerOrLateVector17, int*, 16), 0);
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            temporaryWord34 = argumentWord5;
            temporaryWord35 = 0x4B;
        }
        else {
            Level31_7EBF4Field(retainedPrivateOrVector16, int *, 4) = (int) (Level31_7EBF4Field(retainedPrivateOrVector16, int *, 4) - 0xA);
            temporaryWord22 = Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x28), void **, 0xC);
            argumentWord5 = Level31_7EBF4Call4E880View1(Level31_7EBF4Field(temporaryWord22, int*, 64)-Level31_7EBF4Field(ownerOrLateVector17, int*, 12), Level31_7EBF4Field(temporaryWord22, int*, 68)-Level31_7EBF4Field(ownerOrLateVector17, int*, 16), 0);
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            temporaryWord34 = argumentWord5;
            temporaryWord35 = 0x258;
        }
        Level31_7EBF4Call35EE0View1(Level31_7EBF4Field(privateRecord19, void **, 0x34), temporaryWord34, temporaryWord35, 0, 0, 0);
        temporaryWord9 = Level31_7EBF4Field(privateRecord19, void **, 0x34);
        if (Level31_7EBF4Field(temporaryWord9, unsigned char *, 0x48) != 2) {
            argumentWord4 = (int)&originalFrame.sp30;
            argumentWord5 = temporaryWord9+12;
            retainedPrivateOrVector16 += 8;
            __asm__("":"=r"(retainedPrivateOrVector16):"0"(retainedPrivateOrVector16), "r"(argumentWord4), "r"(argumentWord5));
            Level31_7EBF4Call4F1C8View1(argumentWord4, argumentWord5, retainedPrivateOrVector16);
            Level31_7EBF4Call4F110View1(&originalFrame.sp30, 4);
            Level31_7EBF4Call4F194View1(retainedPrivateOrVector16, &originalFrame.sp30, retainedPrivateOrVector16);
            Level31_7EBF4Call13AE4View1(Level31_7EBF4Field(Level31_7EBF4Field(privateRecord19, void **, 0x24), int *, 0xC), retainedPrivateOrVector16);
        }
    }
    else {
        return;
    }
    return;
}
#undef Level31_7EBF4Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007F8A0.
* AI generated; not human reviewed. All837 original instructions,99 table
* selectors and one zero padding word must match, including actual targets.
* Frame60 saves S0..S3/RA and retains all SP38..47 original locals. The
* thirteen-input indirect callback retains all original outgoing words.
* Original lower8-entry and upper91-entry dispatch tables share case7;
* the first table's7 target is the physical case7 of the other dispatch.
* High50/5A states retain the original common dispatch even when D6E044=9.
* The single call2 block remains at original667;the single reset remains
* at771;the temporary height decrement remains at516 following state5.
* Original floor helper result moves V0-to-V1 after the SP40 load,then
* signed comparisons preserve both store624 and call-entry626 branches.
* Original heading absolute difference uses full V0/V1 before the reset.
* Distinct empty selector-entry markers precede initialized6/7 producers
* and retain the original jump delay,full selector word and shared store.
* Known helper/zero-input rand/spawn contracts reuse existing verified
* headers and original EXE evidence. Empty metadata consumes initialized
* complete values or clobbers dead registers before new producers;zero
* CPU opcodes. No partialHI,fixedFP,overlapping live aliases or pipeline edit.
* Units/fixed point,complete helper/caller meanings,cadence beyond invocation
* and synchronized runtime remain open. Confidence is binary identity only
* after all gates;next evidence is human review and retail runtime capture.
* Falsification: every native/linked word,actual branch/call/table target,
* owned data and full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 4974c57d86f5ae0a060def3201dc3772cff3ed61b1a36b299e14fd9cb4e1a282 */
#define Level31_7F8A0Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level31_7F8A0Call13E38View1() __asm__("func_80013E38");
int Level31_7F8A0Call1A358View1() __asm__("func_8001A358");
void Level31_7F8A0Call34F40View1(void*, int) __asm__("func_80034F40");
int Level31_7F8A0Call35194View1() __asm__("func_80035194");
int Level31_7F8A0Call3573CView1() __asm__("func_8003573C");
int Level31_7F8A0Call3585CView1() __asm__("func_8003585C");
int Level31_7F8A0Call359A4View1(void*, int) __asm__("func_800359A4");
int Level31_7F8A0Call35A80View1() __asm__("func_80035A80");
int Level31_7F8A0Call369B8View1() __asm__("func_800369B8");
int Level31_7F8A0Call36A68View1() __asm__("func_80036A68");
int Level31_7F8A0Call38BF8View1() __asm__("func_80038BF8");
int Level31_7F8A0Call3BA00View1() __asm__("func_8003BA00");
int Level31_7F8A0Call3BABCView1() __asm__("func_8003BABC");
int Level31_7F8A0Call3BB10View1() __asm__("func_8003BB10");
int Level31_7F8A0Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level31_7F8A0Call4EDE8View1() __asm__("func_8004EDE8");
int Level31_7F8A0Call4F08CView1() __asm__("func_8004F08C");
int Level31_7F8A0Call4F178View1() __asm__("func_8004F178");
int Level31_7F8A0Call4F1C8View1() __asm__("func_8004F1C8");
int Level31_7F8A0Call4F264View1(int, int) __asm__("func_8004F264");
int Level31_7F8A0Call4F334View1() __asm__("func_8004F334");
int Level31_7F8A0Call55B18View1() __asm__("func_80055B18");
int Level31_7F8A0Call55D24View1() __asm__("func_80055D24");
int Level31_7F8A0Call55E84View1() __asm__("func_80055E84");
int Level31_7F8A0Call55F14View1() __asm__("func_80055F14");
int Level31_7F8A0DatarandView1(void) __asm__("rand");
extern int Level31_7F8A0Data6C550View1 __asm__("D_8006C550");
extern int Level31_7F8A0Data6C770View1 __asm__("D_8006C770");
extern int Level31_7F8A0Data6E020View1 __asm__("D_8006E020");
extern int Level31_7F8A0Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level31_7F8A0Data6E040View1 __asm__("D_8006E040");
extern int Level31_7F8A0Data6E044View1 __asm__("D_8006E044");
extern int Level31_7F8A0Data6E048View1 __asm__("D_8006E048");
extern int Level31_7F8A0Data70328View1 __asm__("D_80070328");
extern void*(*Level31_7F8A0DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern int(*Level31_7F8A0Data74314View1)() __asm__("unk_ovlheader_80074314");
extern int(*Level31_7F8A0Data74348View1)() __asm__("unk_ovlheader_80074348");
extern int(*Level31_7F8A0Data7434CView1)() __asm__("unk_ovlheader_8007434C");
extern int(*Level31_7F8A0Data74350View1)() __asm__("unk_ovlheader_80074350");
extern int(*Level31_7F8A0Data74354View1)() __asm__("unk_ovlheader_80074354");
extern int(*Level31_7F8A0Data74358View1)() __asm__("unk_ovlheader_80074358");
void func_level_31_8007F8A0(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5");
    register void *ownerRecord16 __asm__("$16");
    register int privateRecord17 __asm__("$17"), retainedVectorOrPrivate18 __asm__("$18"), retainedPlayerBase19 __asm__("$19");
    struct{
        int sp38, sp3C, sp40, sp44;
    }
    originalFrame;
    int temporaryWord3;
    int temporaryWord9;
    int temporaryWord12;
    int temporaryWord14;
    int temporaryWord1;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord2;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord13;
    int temporaryWord15;
    ownerRecord16 = input;
    __asm__("":"=r"(ownerRecord16):"0"(ownerRecord16));
    temporaryWord1 = Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48);
    privateRecord17 = Level31_7F8A0Field(ownerRecord16, void **, 0);
    if (temporaryWord1 < 0x5AU) {
        temporaryWord9 = Level31_7F8A0Field(ownerRecord16, int *, 0x18);
        if (temporaryWord9 != 0) {
            if (temporaryWord9 & 0xA0000) {
                Level31_7F8A0Data74350View1(ownerRecord16, privateRecord17 + 0x18, 0x50);
                Level31_7F8A0Call38BF8View1(ownerRecord16, privateRecord17 + 0x24, 2, 9);
                Level31_7F8A0Field(privateRecord17, unsigned short *, 0x30) = (unsigned short) (Level31_7F8A0Field(privateRecord17, unsigned short *, 0x30) | 0x4000);
                Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 0x5AU;
                Level31_7F8A0Call36A68View1(ownerRecord16, 0, 0, 0);
            }
            else if ((temporaryWord9 & 0x10000) && (temporaryWord1 < 0x51U)) {
                Level31_7F8A0Data74348View1(ownerRecord16, privateRecord17 + 0x18, 0x50, 0x1C);
            }
            if (Level31_7F8A0Field(ownerRecord16, int *, 0x18) & 0x10000000) {
                temporaryWord10 = Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48);
                if (temporaryWord10 < 0x5AU) {
                    if (temporaryWord10 == 0x50) {
                        Level31_7F8A0Field(privateRecord17, short *, 0x1C) = 0;
                    }
                    else {
                        if (Level31_7F8A0Field(privateRecord17, int *, 8) < 0x3C) {
                            Level31_7F8A0Call3BABCView1(ownerRecord16, 0, 1);
                            Level31_7F8A0Field(privateRecord17, int *, 8) = 0x78;
                        }
                        if (Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) != 6) {
                            rawWord2 = 120;
                            rawWord3 = Level31_7F8A0Field(privateRecord17, int*, 0x3C);
                            Level31_7F8A0Field(privateRecord17, int*, 8) = rawWord2;
                            if (rawWord3){
                                __asm__ volatile(""::"i"(7):"memory");
                                rawWord2 = 7;
                            }
                            else{
                                __asm__ volatile(""::"i"(6):"memory");
                                rawWord2 = 6;
                            }
                            Level31_7F8A0Field(ownerRecord16, unsigned char*, 0x48) = rawWord2;
                            Level31_7F8A0Call34F40View1(ownerRecord16, 6);
                        }
                    }
                    if (Level31_7F8A0Data74354View1(ownerRecord16) != 0) {
                        Level31_7F8A0Call3BB10View1(ownerRecord16, 3, 1);
                        Level31_7F8A0Call36A68View1(ownerRecord16, 0, 0, 0);
                        Level31_7F8A0Call3BA00View1(ownerRecord16);
                        Level31_7F8A0Call55B18View1(ownerRecord16);
                        return;
                    }
                    goto block_20;
                }
                goto block_21;
            }
            goto block_20;
        }
    }
block_20:
block_21:
    Level31_7F8A0Field(ownerRecord16, int *, 0x18) = 0;
    if ((Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) != 6) && (Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) != 0x50) && (Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) != 0x5A) && (Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x57) != 0)) {
        Level31_7F8A0Data74358View1(ownerRecord16);
    }
    if (((unsigned char) Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) < 0x50U) && ((unsigned int) (Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 0x50) - 7) < 2U)) {
        Level31_7F8A0Call34F40View1(ownerRecord16, 5);
        Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 5U;
    }
    if ((Level31_7F8A0Data6E044View1 == 9) && (Level31_7F8A0Data6E048View1 == 1)) {
        temporaryWord2 = Level31_7F8A0Field(privateRecord17, void **, 0);
        if (temporaryWord2 != 0) {
            Level31_7F8A0Call55B18View1(temporaryWord2);
            Level31_7F8A0Field(privateRecord17, void **, 0) = 0;
            goto block_33;
        }
    }
    else {
    block_33:
        temporaryWord5 = Level31_7F8A0Field(privateRecord17, void **, 0);
        if ((temporaryWord5 != 0) && (Level31_7F8A0Field(temporaryWord5, unsigned char *, 0x48) != 0x64)) {
            Level31_7F8A0Field(privateRecord17, void **, 0) = 0;
        }
    }
    if ((Level31_7F8A0Field(privateRecord17, int *, 0x3C) != 0) && ((unsigned char) Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) < 0x50U) && ((Level31_7F8A0Call4F334View1(ownerRecord16 + 0xC, (int)&Level31_7F8A0Data70328View1) < 0x3200) || (Level31_7F8A0Call4F334View1(Level31_7F8A0Data6C550View1 + (Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + 0xC, (int)&Level31_7F8A0Data70328View1) < 0x3200))) {
        Level31_7F8A0Call34F40View1(ownerRecord16, 6);
        Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 7U;
    }
    if (Level31_7F8A0Data6E044View1 == 9) {
        temporaryWord11 = Level31_7F8A0Field(ownerRecord16, unsigned char*, 0x48);
        if ((unsigned)temporaryWord11 >= 80) goto dispatchOriginalHighStates;
        switch (temporaryWord11) {
        case 0:
            Level31_7F8A0Call3585CView1(ownerRecord16, (Level31_7F8A0Field(privateRecord17, int *, 0x14) - 0x18) & 0xFF, 6, 0, 0, 0);
            if (Level31_7F8A0Data6C770View1 != 0) {
                if ((Level31_7F8A0Field(privateRecord17, void **, 0) == 0) && (Level31_7F8A0DatarandView1() & 1)) {
                    Level31_7F8A0Call34F40View1(ownerRecord16, 1);
                }
                else {
                    Level31_7F8A0Call34F40View1(ownerRecord16, 0);
                }
            }
            break;
        case 6:
            temporaryWord12 = Level31_7F8A0Field(privateRecord17, int *, 4);
            if (temporaryWord12 >= 0) {
                temporaryWord6 = (temporaryWord12 * 0x58) + Level31_7F8A0Data6C550View1;
                Level31_7F8A0Data74314View1(ownerRecord16, Level31_7F8A0Data6C550View1 + (Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + 0xC, 0x400, Level31_7F8A0Call4E880View1(Level31_7F8A0Field(temporaryWord6, int *, 0xC) - Level31_7F8A0Field(ownerRecord16, int *, 0xC), Level31_7F8A0Field(temporaryWord6, int *, 0x10) - Level31_7F8A0Field(ownerRecord16, int *, 0x10), 0), 8, 0xA0, 6, 0x10, 0xFF, 0xFF, 0, 0, 0);
                temporaryWord15 = privateRecord17 + 8;
            }
            else {
                goto block_109;
            }
            goto resetSequenceIndex;
        case 1:
        case 2:
        case 3:
        case 5:
            if (Level31_7F8A0Data6C770View1 != 0) {
                if (Level31_7F8A0Field(privateRecord17, int *, 0x3C) != 0) {
                    Level31_7F8A0Call34F40View1(ownerRecord16, 6);
                    Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 7U;
                }
                else {
                    goto resetOriginalOwnerState;
                }
            }
            break;
        case 7:goto originalSharedCase7;
        }
    }
    else {
        temporaryWord11 = Level31_7F8A0Field(ownerRecord16, unsigned char*, 0x48);
    dispatchOriginalHighStates:
        switch (temporaryWord11) {
        case 7:
        originalSharedCase7:
            if (Level31_7F8A0Call35A80View1(ownerRecord16, Level31_7F8A0Field(privateRecord17, int *, 0x3C), 0x80, 0xA0, 0, 6, 0x20, 5) & 2) {
                Level31_7F8A0Field(privateRecord17, int *, 8) = 0x1E;
                Level31_7F8A0Field(privateRecord17, int *, 0x3C) = 0;
                Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 6U;
            }
            break;
        case 0x50:
            Level31_7F8A0Data7434CView1(ownerRecord16, privateRecord17 + 0x18);
            break;
        case 0x0:
            if (Level31_7F8A0Field(((Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + Level31_7F8A0Data6C550View1), unsigned char *, 0x48) & 0x80) {
                Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 6U;
                Level31_7F8A0Call34F40View1(ownerRecord16, 6);
            }
            else if (Level31_7F8A0Field(privateRecord17, void **, 0) == 0) {
                Level31_7F8A0Call3585CView1(ownerRecord16, (Level31_7F8A0Field(privateRecord17, int *, 0x14) - 0x18) & 0xFF, 6, 0, 0, 0);
                goto callSharedState2Helper;
            }
            else {
                Level31_7F8A0Call3573CView1(ownerRecord16, 6, 0, 1);
                rawWord2 = Level31_7F8A0Field(ownerRecord16, int*, 20);
                __asm__("":::"$5", "memory");
                argumentWord5 = (int)&Level31_7F8A0Data70328View1+576;
                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                rawWord2 += 256;
                Level31_7F8A0Field(ownerRecord16, int*, 20) = rawWord2;
                rawWord2 = Level31_7F8A0Field(argumentWord5, int*, 0);
                retainedVectorOrPrivate18 = (int)ownerRecord16+12;
                if (rawWord2 == 0){
                    retainedPlayerBase19 = argumentWord5-576;
                    if ((Level31_7F8A0Call4F334View1(retainedVectorOrPrivate18, retainedPlayerBase19) < 0x3000) && (Level31_7F8A0Call13E38View1(retainedVectorOrPrivate18, retainedPlayerBase19, 0) != 0)) {
                    callSharedState3Helper:
                        Level31_7F8A0Call34F40View1(ownerRecord16, 3);
                        Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 2U;
                    }
                }
                goto subtractOriginalTemporaryHeight;
            }
            break;
        case 0x1:
            Level31_7F8A0Call3585CView1(ownerRecord16, (Level31_7F8A0Field(privateRecord17, int *, 0x14) - 0x18) & 0xFF, 6, 0, 0, 0);
            if ((Level31_7F8A0Field(privateRecord17, void **, 0) == 0) && !(Level31_7F8A0Field(((Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + Level31_7F8A0Data6C550View1), unsigned char *, 0x48) & 0x80) && ((Level31_7F8A0Data6C770View1 != 0) || (Level31_7F8A0Call55E84View1(ownerRecord16) >= 0xF))) {
                temporaryWord7 = Level31_7F8A0DataSpawnMobyView1(0x5E, ownerRecord16);
                Level31_7F8A0Field(privateRecord17, void **, 0) = temporaryWord7;
                if (temporaryWord7 != 0) {
                    Level31_7F8A0Field(temporaryWord7, signed char *, 0x48) = 0x64;
                }
            }
        case 0x5:
            if (Level31_7F8A0Data6C770View1 != 0) {
                Level31_7F8A0Field(ownerRecord16, int *, 0x14) = (int) (Level31_7F8A0Field(ownerRecord16, int *, 0x14) + 0x100);
                if (Level31_7F8A0Field(privateRecord17, int *, 0x3C) != 0) {
                    Level31_7F8A0Call34F40View1(ownerRecord16, 6);
                    Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 7U;
                }
                else {
                    retainedVectorOrPrivate18 = ownerRecord16 + 0xC;
                    if ((Level31_7F8A0Field(privateRecord17, void **, 0) == 0) || (Level31_7F8A0Call4F334View1(retainedVectorOrPrivate18, (int)&Level31_7F8A0Data70328View1) >= 0x3000) || (Level31_7F8A0Call13E38View1(retainedVectorOrPrivate18, (int)&Level31_7F8A0Data70328View1, 0) == 0)) {
                        Level31_7F8A0Call34F40View1(ownerRecord16, 0);
                        Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 0U;
                    }
                    else {
                        goto callSharedState3Helper;
                    }
                }
            subtractOriginalTemporaryHeight:
                Level31_7F8A0Field(ownerRecord16, int*, 0x14) -= 256;
            }
            break;
        case 0x2:
            Level31_7F8A0Call3573CView1(ownerRecord16, 6, 3, 1);
            temporaryWord3 = Level31_7F8A0Call4F334View1(ownerRecord16 + 0xC, (int)&Level31_7F8A0Data70328View1);
            if ((Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 0x240) == 0) && ((unsigned int) (Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 0x50) - 7) >= 2U) && (temporaryWord3 < 0x3401)) {
                if ((temporaryWord3 < 0x2400) && (Level31_7F8A0Call4F264View1((int) (Level31_7F8A0Data6E040View1 << 0x10) >> 0x14, Level31_7F8A0Call4E880View1(Level31_7F8A0Field(ownerRecord16, int *, 0xC) - Level31_7F8A0Data6E020View1, Level31_7F8A0Field(ownerRecord16, int *, 0x10) - Level31_7F8A0Data6E024View1, 0)) < 0x1C)) {
                    Level31_7F8A0Call34F40View1(ownerRecord16, 4);
                    Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 3U;
                }
            }
            else {
                goto resetOriginalOwnerState;
            }
            break;
        case 0x3:
            Level31_7F8A0Call3573CView1(ownerRecord16, 6, 3, 0);
            if ((Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 0x240) == 0) && ((unsigned int) (Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 0x50) - 7) >= 2U) && (Level31_7F8A0Field(privateRecord17, void **, 0) != 0) && ((Level31_7F8A0Data6C770View1 != 0) || (Level31_7F8A0Call55E84View1(ownerRecord16) >= 0xF))) {
                temporaryWord13 = Level31_7F8A0Field(privateRecord17, void **, 0);
                retainedVectorOrPrivate18 = Level31_7F8A0Field(temporaryWord13, void **, 0);
                Level31_7F8A0Field(temporaryWord13, unsigned char *, 0x48) = 0x63U;
                Level31_7F8A0Call4F178View1(&originalFrame.sp38, ((int)&Level31_7F8A0Data70328View1 + 0x240) - 0x240);
                rawWord2 = Level31_7F8A0Call1A358View1(&originalFrame.sp38, 4096);
                argumentWord4 = originalFrame.sp40;
                __asm__("":::"$3", "memory");
                rawWord3 = rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord2 = argumentWord4-rawWord3;
                if (rawWord2 >= 0){
                    if (rawWord2 < 1800){
                        rawWord2 = rawWord3+300;
                        goto storeOriginalHeight;
                    }
                    rawWord2 = rawWord3+300;
                    argumentWord4 = retainedVectorOrPrivate18;
                    goto callOriginalVector;
                }
                rawWord2 = rawWord3-argumentWord4;
                if (rawWord2 < 1800){
                    rawWord2 = rawWord3+300;
                    storeOriginalHeight:originalFrame.sp40 = rawWord2;
                }
                else{
                    rawWord2 = rawWord3+300;
                }
                argumentWord4 = retainedVectorOrPrivate18;
                callOriginalVector:Level31_7F8A0Call4F1C8View1(argumentWord4, &originalFrame.sp38, Level31_7F8A0Field(privateRecord17, void**, 0)+12);
                Level31_7F8A0Call4F08CView1(retainedVectorOrPrivate18, Level31_7F8A0Call4EDE8View1(retainedVectorOrPrivate18, 1), 0x12C);
                Level31_7F8A0Field(retainedVectorOrPrivate18, short *, 0xC) = 0x78;
                Level31_7F8A0Field(retainedVectorOrPrivate18, signed char *, 0x11) = 0x10;
                Level31_7F8A0Field(privateRecord17, void **, 0) = 0;
            }
            if (Level31_7F8A0Data6C770View1 != 0) {
                if (Level31_7F8A0Field(((Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + Level31_7F8A0Data6C550View1), unsigned char *, 0x48) & 0x80) {
                    Level31_7F8A0Call34F40View1(ownerRecord16, 6);
                    Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 6U;
                }
                else {
                callSharedState2Helper:
                    Level31_7F8A0Call34F40View1(ownerRecord16, 2);
                    Level31_7F8A0Field(ownerRecord16, unsigned char*, 0x48) = 1;
                }
            }
            break;
        case 0x6:
            temporaryWord14 = Level31_7F8A0Field(privateRecord17, int *, 4);
            if (temporaryWord14 >= 0) {
                temporaryWord8 = (temporaryWord14 * 0x58) + Level31_7F8A0Data6C550View1;
                Level31_7F8A0Data74314View1(ownerRecord16, Level31_7F8A0Data6C550View1 + (Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + 0xC, 0x400, Level31_7F8A0Call4E880View1(Level31_7F8A0Field(temporaryWord8, int *, 0xC) - Level31_7F8A0Field(ownerRecord16, int *, 0xC), Level31_7F8A0Field(temporaryWord8, int *, 0x10) - Level31_7F8A0Field(ownerRecord16, int *, 0x10), 0), 8, 0xA0, 6, 0x10, 0xFF, 0xFF, 0, 0, 0);
            }
            if (!(Level31_7F8A0Field(((Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + Level31_7F8A0Data6C550View1), unsigned char *, 0x48) & 0x80) || (Level31_7F8A0Call34F40View1(ownerRecord16, 0xA), Level31_7F8A0Field(ownerRecord16, unsigned char *, 0x48) = 0xAU, ((Level31_7F8A0Field(((Level31_7F8A0Field(privateRecord17, int *, 4) * 0x58) + Level31_7F8A0Data6C550View1), unsigned char *, 0x48) & 0x80) == 0))) {
            block_109:
                temporaryWord15 = privateRecord17 + 8;
            resetSequenceIndex:
                if (Level31_7F8A0Call359A4View1(temporaryWord15, 4) != 0) {
                    rawWord2 = Level31_7F8A0Field(ownerRecord16, unsigned char*, 0x46);
                    rawWord3 = Level31_7F8A0Field(privateRecord17, int*, 0x14);
                    rawWord2 -= rawWord3;
                    if (rawWord2 < 0) {
                        rawWord2 = -rawWord2;
                    }
                    if (rawWord2 < 4) {
                    resetOriginalOwnerState:
                        Level31_7F8A0Call34F40View1(ownerRecord16, 0);
                        Level31_7F8A0Field(ownerRecord16, unsigned char*, 0x48) = 0;
                    }
                }
            }
            break;
        case 0xA:
            Level31_7F8A0Call3585CView1(ownerRecord16, Level31_7F8A0Call4E880View1(Level31_7F8A0Field(ownerRecord16, int *, 0xC) - Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 0), Level31_7F8A0Field(ownerRecord16, int *, 0x10) - Level31_7F8A0Field((int)&Level31_7F8A0Data70328View1, int *, 4), 0), 5, 0, 1, 0);
            break;
        case 0x5A:
            if (Level31_7F8A0Call35194View1(ownerRecord16, privateRecord17 + 0x24) == 0x100) {
                temporaryWord4 = Level31_7F8A0Field(privateRecord17, void **, 0);
                if (temporaryWord4 != 0) {
                    Level31_7F8A0Call55B18View1(temporaryWord4);
                }
                Level31_7F8A0Call55D24View1(ownerRecord16, 4);
                Level31_7F8A0Call3BA00View1(ownerRecord16);
                Level31_7F8A0Call369B8View1(ownerRecord16, 0x30);
                Level31_7F8A0Call55B18View1(ownerRecord16);
            }
            break;
        }
    }
finishOriginalStateDispatch:
    if (Level31_7F8A0Field(privateRecord17, void **, 0) != 0) {
        Level31_7F8A0Call55D24View1(ownerRecord16, 4);
        Level31_7F8A0Call55F14View1(ownerRecord16, 0, Level31_7F8A0Field(privateRecord17, void **, 0) + 0xC);
    }
}
#undef Level31_7F8A0Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_31/moby/func_level_31_800805B4.s SHA256 46114498f18d405341e55907b7ced66fa0262190a3781c77927557b121766b8b. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level31_805B4_Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level31_805B4_func_80018368() __asm__("func_80018368");
/* extern */
int Level31_805B4_func_80019138() __asm__("func_80019138");
/* extern */
int Level31_805B4_func_80019194() __asm__("func_80019194");
/* extern */
int **Level31_805B4_func_8001BA30() __asm__("func_8001BA30");
/* extern */
int Level31_805B4_func_80035A80() __asm__("func_80035A80");
/* extern */
int Level31_805B4_func_80036220() __asm__("func_80036220");
/* extern */
int Level31_805B4_func_8004EDE8() __asm__("func_8004EDE8");
/* extern */
int Level31_805B4_func_8004EF74() __asm__("func_8004EF74");
/* extern */
int Level31_805B4_func_8004F08C() __asm__("func_8004F08C");
/* extern */
int Level31_805B4_func_8004F110() __asm__("func_8004F110");
/* extern */
int Level31_805B4_func_8004F1C8() __asm__("func_8004F1C8");
/* extern */
int Level31_805B4_func_8004F334() __asm__("func_8004F334");
/* extern */
int Level31_805B4_func_80055B18() __asm__("func_80055B18");
/* extern */
int Level31_805B4_func_80055D24() __asm__("func_80055D24");
/* extern */
int Level31_805B4_rand() __asm__("rand");
/* extern */
extern unsigned char Level31_805B4_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level31_805B4_D_80065920 __asm__("D_80065920");
extern int Level31_805B4_D_8006C550 __asm__("D_8006C550");
extern unsigned char Level31_805B4_D_80070328 __asm__("D_80070328");
extern Vector3D Level31_805B4_D_80071918 __asm__("D_80071918");
extern int Level31_805B4_D_80071930 __asm__("D_80071930");
void func_level_31_800805B4(Moby *moby) {
    /* SCUS-94467 USA Rev0 address800805B4; source and SHA above.
    * 875 original instructions, frame60: raw vectors20/30, saves16..22
    * at40..58 and RA5C. The initial position17 producer belongs only to
    * the admitted initial-colour arm, restoring compiler-owned save order.
    * Pointer arithmetic is in bytes: selected positions+0C and private
    * fields+0E/+18/+34/+4C. Signed table samples are LH full-word values;
    * literal25/15 shift11 and variable signed product shift12 reproduce
    * original instructions. Their physical units remain unknown.
    * Indirect74350 caller inputs are owner4/private+18 in5/literal46 in6.
    * Indirect74348 keeps that original owner4; its other inputs are
    * private+18 in5/literal46 in6/literal1C in7. Indirect7434C receives
    * owner4/private+18 in5. These are caller projections; full helper
    * contracts and SDK placeholder declarations remain unresolved.
    * The selected second record uses original pointer2 before old data17
    * is copied to18, before pointer17 is replaced; the zero store retains
    * its original order. Collision branches independently reconstruct
    * argument4 after the respective calls. Paired return2 values survive
    * original argument constructors before copies to16/17; no HI/LO
    * assumptions or hand-emitted instructions are used.
    * Every empty constraint consumes initialized original values. Dead
    * clobbers precede identified replacement producers. Compiler, flags,
    * assembly filters, data and all matching gates are unchanged.
    * AI generated; not human reviewed. Confidence: exact native/linked
    * instructions and conditional/internal J targets, preserved data and
    * full EXE/every-overlay hashes are required. This is the falsifiable
    * test vector. Cadence per invocation; frame frequency, fixed-point
    * units, complete helper/SFX/asset chains and synchronized runtime
    * verification remain unresolved. Browser behavior is unchanged. */
    struct {
        int sp20,sp24,sp28,pad2C,sp30,sp34,sp38,pad3C;
    }
    originalFrame;
    Moby *temp_a0;
    register int initialType2 __asm__("2");
    register int createdId4 __asm__("4");
    register void *createdSlot2 __asm__("2");
    Moby *temp_a0_2;
    Moby *temp_v0;
    register Vector3D *position16 __asm__("16");
    register Vector3D *position17 __asm__("17");
    register Vector3D *contactPosition17 __asm__("17");
    register int table658A0Word3 __asm__("3");
    register int secondTable658A0Word3 __asm__("3");
    int **temp_a1;
    int **temp_a1_2;
    register int **firstMoby6 __asm__("6");
    register int **contactPosition21 __asm__("$21");
    int **temp_v0_8;
    register int **contactMoby16 __asm__("16");
    register int **selectedMoby17 __asm__("$17");
    register int *contactData18 __asm__("$18");
    register int *otherData17 __asm__("$17");
    register int *selectedData18 __asm__("$18");
    register int angle16 __asm__("$16");
    register int tableByteOffset16 __asm__("$16");
    register int firstLength16 __asm__("$16");
    register int firstResult16 __asm__("$16");
    register int meanResult16 __asm__("$16");
    register int secondResult17 __asm__("17");
    int temp_v0_4;
    int temp_v0_5;
    int temp_v1;
    int otherDistance4;
    int var_a3;
    register int distance16 __asm__("$16");
    register int literal21 __asm__("$21");
    register int literal22 __asm__("$22");
    int var_v0;
    register unsigned int temp_v0_6 __asm__("2");
    register unsigned int temp_v0_7 __asm__("2");
    unsigned char temp_v1_3;
    register unsigned int var_v0_2 __asm__("2");
    register unsigned int var_v0_3 __asm__("2");
    void *temp_a0_3;
    register void *privateData __asm__("$20");
    register void *initialRecord20 __asm__("$20");
    void *temp_v0_12;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_5;
    register void *vector4 __asm__("4");
    register void *vector5 __asm__("5");
    register void *vector6 __asm__("6");
    register int angle2 __asm__("2");
    register int sample3 __asm__("3");
    register int returned2 __asm__("2");
    register void *selected2 __asm__("2");
    register int firstWord5 __asm__("5");
    register unsigned int counter3 __asm__("3");
    register int field2 __asm__("2");
    register void *initialPrivateData16 __asm__("16");
    register int *global71930Pointer17 __asm__("17");
    register void *fieldEArgument4 __asm__("4");
    register int zero5 __asm__("5");
    register int one5 __asm__("5");
    initialType2=0x50;
    __asm__("" : "=r"(initialType2) : "0"(initialType2));
    privateData = moby->mobyTag;
    if (moby->colour.a == initialType2) {
        position17=&moby->position;
        moby->lowDrawDistance = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x4C);
        moby->updateDistance = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x4A);
        moby->highDrawDistance = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x4E);
        func_8004F178(position17, Level31_805B4_Field(privateData, void **, 0) + 0xC);
        moby->position.z = 0x8000 - moby->position.z;
        moby->angle.roll = (unsigned char) -(int) Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x44);
        moby->angle.pitch = (unsigned char) -(int) Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x45);
        moby->angle.yaw = ({ register unsigned int yaw2 __asm__("2"); yaw2=Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x46); __asm__("" : "=r"(yaw2) : "0"(yaw2) : "memory"); moby->unknown3[0]=0; yaw2; });
        moby->animationState.id = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x3C);
        moby->animationState.nextId = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x3D);
        moby->animationState.frame = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x3E);
        moby->animationState.nextFrame = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x3F);
        moby->animationProgress = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), unsigned char *, 0x40);
        initialPrivateData16 = privateData;
        __asm__("" : "=r"(initialPrivateData16) : "0"(initialPrivateData16));
        initialRecord20 = Level31_805B4_Field(Level31_805B4_Field(privateData, void **, 0), void **, 0);
        if (Level31_805B4_Field(initialRecord20, void **, 0x18) != 0) {
            if (Level31_805B4_Field(initialPrivateData16, Moby **, 4) == 0) {
                temp_v0 = SpawnMoby(0x79, moby);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4) = temp_v0;
                if (temp_v0 != 0) {
                    goto block_5;
                }
            }
            else {
            block_5:
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->unknownCollision = 0;
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->unknown4 = 0xFD;
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->lowDrawDistance = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x4C);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->updateDistance = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x4A);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->highDrawDistance = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x4E);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->size = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x4F);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->colour.a = 0x50;
                func_8004F178(&Level31_805B4_Field(initialPrivateData16, Moby **, 4)->position, position17);
                temp_a0 = Level31_805B4_Field(initialPrivateData16, Moby **, 4);
                temp_a0->position.z += Level31_805B4_Field(Level31_805B4_Field(initialPrivateData16, void **, 0), short *, 0x38);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->angle.roll = (unsigned char) -(int) moby->angle.roll;
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->angle.pitch = (unsigned char) -(int) moby->angle.pitch;
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->angle.yaw = moby->angle.yaw;
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->unknown3[0] = 0;
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->animationState.id = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x3C);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->animationState.nextId = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x3D);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->animationState.frame = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x3E);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->animationState.nextFrame = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x3F);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4)->animationProgress = Level31_805B4_Field(Level31_805B4_Field(initialRecord20, void **, 0x18), unsigned char *, 0x40);
            }
        }
        else {
            temp_a0_2 = Level31_805B4_Field(initialPrivateData16, Moby **, 4);
            if (temp_a0_2 != 0) {
                Level31_805B4_func_80055B18(temp_a0_2);
                Level31_805B4_Field(initialPrivateData16, Moby **, 4) = 0;
            }
        }
    }
    else {
        createdSlot2=Level31_805B4_Field(privateData,void **,0x64);
        createdId4=0x5D;
        if (createdSlot2 == 0) {
            Level31_805B4_Field(privateData,Moby **,0x64)=SpawnMoby(createdId4,moby);
        }
        temp_v1 = moby->damageFlags;
        vector4=moby;
        if (temp_v1 & 0x20000) {
            if (((int (*)(Moby *,void *,int))unk_ovlheader_80074350)(vector4,privateData + 0x18,0x46) != 0) {
                moby->colour.r = 0;
                moby->colour.g = 0;
                moby->colour.b = 0;
                moby->colour.a = 0;
            }
        }
        else if (temp_v1 & 0x10000) {
            ((void (*)(void *,void *,int,int))unk_ovlheader_80074348)(vector4,privateData + 0x18,0x46,0x1C);
            moby->colour.r = 0;
            moby->colour.g = 0;
            moby->colour.b = 0;
            moby->colour.a = 0;
            if (moby->substate == 0) {
                moby->substate = 1;
            }
            if (Level31_805B4_Field(privateData, unsigned char *, 0xC) == 4) {
                originalFrame.sp20 = (int) (*(short *)(&Level31_805B4_D_80065920 + (func_8004E880(moby->position.x - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 0), moby->position.y - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 4), 0) * 2)) * 0x19) >> 0xB;
                table658A0Word3 = ({ angle2=func_8004E880(moby->position.x - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 0), moby->position.y - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 4), 0); vector4=privateData; vector5=privateData; __asm__("" : "=r"(vector4), "=r"(vector5) : "0"(vector4), "1"(vector5)); *(short *)(&Level31_805B4_D_800658A0 + (angle2 * 2)); });
                __asm__ volatile("" : "=r"(table658A0Word3) : "0"(table658A0Word3) : "6");
                vector6=&originalFrame.sp20;
                __asm__("" : "=r"(vector6) : "0"(vector6));
                originalFrame.sp28 = 0;
                __asm__ volatile("" : "=r"(table658A0Word3) : "0"(table658A0Word3) : "memory");
                originalFrame.sp24 = (int) (table658A0Word3 * 0x19) >> 0xB;
                func_8004F194(vector4,vector5,vector6);
            }
        }
        moby->damageFlags = 0;
        Level31_805B4_func_8004F08C((int *) privateData, 0x40, 0x3F);
        temp_v1_3 = moby->state;
        switch (temp_v1_3) {
            /* irregular */
        case 0x46:
            if (Level31_805B4_Field(privateData, unsigned char *, 0xC) == 4) {
                if (Level31_805B4_Field(privateData, int *, 0x18) != 0) {
                    if ((Level31_805B4_func_8004F334(&moby->position, &Level31_805B4_D_80070328) < 0x600) && (func_8004F264((int) Level31_805B4_Field(&Level31_805B4_D_80070328, unsigned char *, 0xE), func_8004E880(moby->position.x - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 0), moby->position.y - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 4), 0)) < 0x30)) {
                        originalFrame.sp20 = (int) (*(short *)(&Level31_805B4_D_80065920 + (func_8004E880(moby->position.x - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 0), moby->position.y - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 4), 0) * 2)) * 0xF) >> 0xB;
                        secondTable658A0Word3 = ({ angle2=func_8004E880(moby->position.x - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 0), moby->position.y - Level31_805B4_Field(&Level31_805B4_D_80070328, int *, 4), 0); vector4=privateData; vector5=privateData; __asm__("" : "=r"(vector4), "=r"(vector5) : "0"(vector4), "1"(vector5)); *(short *)(&Level31_805B4_D_800658A0 + (angle2 * 2)); });
                        __asm__ volatile("" : "=r"(secondTable658A0Word3) : "0"(secondTable658A0Word3) : "6");
                        vector6=&originalFrame.sp20;
                        __asm__("" : "=r"(vector6) : "0"(vector6));
                        originalFrame.sp28 = 0;
                        __asm__ volatile("" : "=r"(secondTable658A0Word3) : "0"(secondTable658A0Word3) : "memory");
                        originalFrame.sp24 = (int) (secondTable658A0Word3 * 0xF) >> 0xB;
                        func_8004F194(vector4,vector5,vector6);
                    }
                }
                if (Level31_805B4_Field(privateData, unsigned char *, 0xC) != 4) {
                    goto block_31;
                }
            }
            else {
            block_31:
                Level31_805B4_func_8004F08C((int *) privateData, 4, 3);
            }
            ((void (*)(Moby *,void *))unk_ovlheader_8007434C)(moby,privateData + 0x18);
            moby->colour.r = 0;
            moby->colour.g = 0;
            moby->colour.b = 0;
            moby->colour.a = 0;
            break;
        case 0x0:
            moby->updateDistance = 0xFF;
            moby->state = 1;
            func_80034F40(moby, 1);
            break;
        case 0x1:
            selectedData18 = 0;
            __asm__("" : "=r"(selectedData18) : "0"(selectedData18));
            temp_a1 = Level31_805B4_Field(privateData, int ***, 0x2C);
            otherData17 = 0;
            if ((temp_a1 != 0) && (selectedData18 = Level31_805B4_Field(temp_a1, int **, 0), (((unsigned char) Level31_805B4_Field(selectedData18, unsigned char *, 0xF) < 0x78U) != 0))) {
                distance16 = -1;
                if (Level31_805B4_Field(selectedData18, unsigned char *, 0xC) == 4) {
                    distance16 = Level31_805B4_func_8004F334(&moby->position, ((void *)((unsigned char *)temp_a1 + 0xC)));
                }
            }
            else {
                distance16 = -1;
            }
            temp_a1_2 = *Level31_805B4_Field(privateData, int ****, 0x28);
            otherDistance4 = -1;
            if (temp_a1_2 != 0) {
                otherData17 = *temp_a1_2;
                if (((unsigned char) Level31_805B4_Field(otherData17, unsigned char *, 0xF) < 0x78U) && (Level31_805B4_Field(otherData17, unsigned char *, 0xC) == 4)) {
                    otherDistance4 = Level31_805B4_func_8004F334(&moby->position, ((void *)((unsigned char *)temp_a1_2 + 0xC)));
                }
            }
            if (Level31_805B4_Field(privateData,unsigned char *,0xC) != 4) goto clearSelection;
            if (otherDistance4 >= 0) goto chooseAdmitted;
            if (distance16 >= 0) goto useFirst;
        clearSelection:
            Level31_805B4_Field(privateData,int ***,0x2C)=0;
            selectedMoby17=0;
            distance16=-1;
            goto selectionDone;
        chooseAdmitted:
            if (distance16 < 0) goto useSecond;
            if (distance16 < 0x1800 || distance16 < otherDistance4*2) {
                firstMoby6=Level31_805B4_Field(privateData,int ***,0x2C);
                if (Level31_805B4_Field(firstMoby6,unsigned char *,0x48)!=0x28) goto useSecond;
                selectedMoby17=firstMoby6;
                goto selectionDone;
            }
        useSecond:
            selected2=Level31_805B4_Field(privateData,void **,0x28);
            __asm__("" : "=r"(selected2) : "0"(selected2));
            selectedData18=otherData17;
            __asm__("" : "=r"(selectedData18) : "0"(selectedData18));
            Level31_805B4_Field(privateData,int ***,0x2C)=0;
            __asm__ volatile("" : : : "memory");
            selectedMoby17=*(int ***)selected2;
            distance16=otherDistance4;
            goto selectionDone;
        useFirst:
            selectedMoby17=Level31_805B4_Field(privateData,int ***,0x2C);
        selectionDone:
            __asm__("" : "=r"(distance16) : "0"(distance16) : "2");
            literal22 = 0x82;
            if ((unsigned int) distance16 >= 0x1401U) {
                literal22 = 0xA5;
                literal21 = (Level31_805B4_rand(otherDistance4) & 1) + 3;
            }
            else {
                literal21 = 6;
            }
            if ((unsigned int) ({ register int distanceWord2 __asm__("2"); distanceWord2 = distance16 - 1; __asm__("" : "=r"(distanceWord2) : "0"(distanceWord2)); distanceWord2; }) < 0x4FFFU) {
                if ((unsigned char) Level31_805B4_Field(privateData, unsigned char *, 0xD) >= 0x3DU) {
                    temp_v1_5 = Level31_805B4_Field(privateData, void **, 0x14);
                    temp_v0_2 = (Level31_805B4_Field(temp_v1_5, short *, 2) * 0x10) + Level31_805B4_Field(temp_v1_5, int *, 0xC);
                    func_8003585C(moby, func_8004E880(Level31_805B4_Field(temp_v0_2, int *, 0) - moby->position.x, Level31_805B4_Field(temp_v0_2, int *, 4) - moby->position.y, 0), literal21, 0, 0, 0);
                    var_v0 = 0;
                    var_a3 = 0;
                }
                else {
                    angle16 = func_8004E880(moby->position.x - Level31_805B4_Field(selectedMoby17, int *, 0xC), moby->position.y - Level31_805B4_Field(selectedMoby17, int *, 0x10), 0);
                    temp_v0_3 = (Level31_805B4_Field(selectedData18, int *, 0x38) * 0x58) + Level31_805B4_D_8006C550;
                    temp_v0_4 = func_8003613C(func_8004E880(Level31_805B4_Field(temp_v0_3, int *, 0xC) - moby->position.x, Level31_805B4_Field(temp_v0_3, int *, 0x10) - moby->position.y, 0), angle16);
                    tableByteOffset16 = ((angle16 - (temp_v0_4 >> 1)) & 0xFF) * 2;
                    temp_v0_5 = (temp_v0_4 * 0x10) + 0x200;
                    originalFrame.sp30 = (int) (*(short *)(&Level31_805B4_D_80065920 + tableByteOffset16) * temp_v0_5) >> 0xC;
                    sample3=*(short *)(&Level31_805B4_D_800658A0+tableByteOffset16);
                    __asm__("" : "=r"(sample3) : "0"(sample3) : "memory");
                    originalFrame.sp34=(sample3*temp_v0_5)>>0xC;
                    originalFrame.sp38=0;
                    func_8004F194((Vector3D *) &originalFrame.sp30, (Vector3D *) &originalFrame.sp30, ((void *)((unsigned char *)selectedMoby17 + 0xC)));
                    func_8003585C(moby, func_8004E880(originalFrame.sp30 - moby->position.x, originalFrame.sp34 - moby->position.y, 0), literal21, 0, 0, 0);
                    var_v0 = 0x30;
                    var_a3 = 0x200;
                }
                if ((func_80035DDC(moby, literal22, 0x200, var_a3, var_v0) != 0) || (func_80035D38(moby) != moby->position.z)) {
                    temp_v0_6 = Level31_805B4_Field(privateData, unsigned char *, 0xD) + 1;
                    Level31_805B4_Field(privateData, unsigned char *, 0xD) = temp_v0_6;
                    if ((temp_v0_6 & 0xFF) == 0x3C) {
                        Level31_805B4_Field(privateData, unsigned char *, 0xD) = 0x46U;
                    }
                }
                else {
                    temp_v0_7 = Level31_805B4_Field(privateData, unsigned char *, 0xD);
                    if (temp_v0_7 != 0) {
                        Level31_805B4_Field(privateData, unsigned char *, 0xD) = (unsigned char) (temp_v0_7 - 1);
                    }
                }
            }
            else {
                Level31_805B4_func_80035A80(moby, Level31_805B4_Field(privateData, void **, 0x10), 0x200, literal22, 0x12C, literal21, 0x7F, 0x22);
            }
            temp_v0_8 = Level31_805B4_func_8001BA30(&moby->position, 0x300, 1, 0, 0, moby);
            if ((temp_v0_8 != 0) && (Level31_805B4_Field(temp_v0_8, short *, 0x36) == 0xEF) && (Level31_805B4_Field(privateData, int ***, 0x2C) == 0) && (Level31_805B4_Field(Level31_805B4_Field(temp_v0_8, int **, 0), unsigned char *, 0xC) == 4)) {
                Level31_805B4_Field(temp_v0_8, int *, 0x18) = (int) (Level31_805B4_Field(temp_v0_8, int *, 0x18) | 0x10000000);
                Level31_805B4_Field(privateData, int ***, 0x2C) = temp_v0_8;
            }
            Level31_805B4_func_80019138(&moby->position, 0x300, 1, 0, 0x10000000, moby);
            break;
        }
        moby->position.z += 0x200;
        vector4=&originalFrame.sp20;
        if (moby->state != 1) {
            __asm__("" : "=r"(vector4) : "0"(vector4) : "16");
            position16 = &moby->position;
            Level31_805B4_Field(privateData, int *, 8) = 0;
            func_8004F178(vector4,position16);
            func_8004F194(position16, position16, (Vector3D *) privateData);
            global71930Pointer17 = &Level31_805B4_D_80071930;
            __asm__("" : "=r"(global71930Pointer17) : "0"(global71930Pointer17));
            *global71930Pointer17 = 0;
            if (moby->substate != 2) {
                returned2=Level31_805B4_func_80036220(position16,privateData+0x4C,0,0);
                __asm__("" : "=r"(privateData), "=r"(returned2) : "0"(privateData), "1"(returned2));
                fieldEArgument4=privateData+0xE;
                if (returned2 != 0) goto tryContact;
                returned2=Level31_805B4_func_80018368(&originalFrame.sp20,position16);
                vector4=position16;
                if (returned2 != 0) goto acceptedCollision;
                returned2=Level31_805B4_func_80019194(vector4,0x1C2);
                __asm__("" : "=r"(privateData), "=r"(returned2) : "0"(privateData), "1"(returned2));
                fieldEArgument4=privateData+0xE;
                if (returned2 == 0) goto tryContact;
            acceptedCollision:
                {
                    returned2=*global71930Pointer17;
                    vector4=position16;
                    if ((returned2 == 0) || ((unsigned char) Level31_805B4_Field(privateData, unsigned char *, 0xF) < 0xAU)) {
                        func_8004F178(vector4, (Vector3D *) &originalFrame.sp20);
                    }
                    __asm__ volatile("" : : : "4");
                    Level31_805B4_func_8004EF74(privateData, &Level31_805B4_D_80071918, privateData);
                    func_8004F178((Vector3D *) &originalFrame.sp20, &Level31_805B4_D_80071918);
                    originalFrame.sp28 = 0;
                    returned2=Level31_805B4_func_8004EDE8(privateData,0);
                    vector4=&originalFrame.sp20;
                    zero5=0;
                    __asm__("" : "=r"(returned2), "=r"(vector4), "=r"(zero5) : "0"(returned2), "1"(vector4), "2"(zero5));
                    firstLength16=returned2;
                    Level31_805B4_func_8004F08C(&originalFrame.sp20, Level31_805B4_func_8004EDE8(vector4,zero5), firstLength16);
                    func_8004F194((Vector3D *) privateData, (Vector3D *) privateData, (Vector3D *) &originalFrame.sp20);
                    Level31_805B4_func_8004F110(privateData, 1);
                    var_v0_2 = Level31_805B4_Field(privateData, unsigned char *, 0xF) + 1;
                    goto block_91;
                }
            tryContact:
                if (func_800359A4(fieldEArgument4, 1) != 0) {
                    contactPosition17 = &moby->position;
                    __asm__("" : "=r"(contactPosition17) : "0"(contactPosition17));
                    contactMoby16 = Level31_805B4_func_8001BA30(contactPosition17, 0x280, 0, 0, 0, moby);
                    __asm__("" : "=r"(contactMoby16) : "0"(contactMoby16));
                    if (contactMoby16 != 0) {
                        func_8004F178(contactPosition17, (Vector3D *) &originalFrame.sp20);
                        vector4=&originalFrame.sp20;
                        vector5=contactPosition17;
                        __asm__("" : "=r"(vector4), "=r"(vector5) : "0"(vector4), "1"(vector5) : "21");
                        contactPosition21=((void *)((unsigned char *)contactMoby16+0xC));
                        Level31_805B4_func_8004F1C8(vector4,vector5,(Vector3D *)contactPosition21);
                        Level31_805B4_func_8004EF74(privateData, (Vector3D *) &originalFrame.sp20, privateData);
                        Level31_805B4_Field(privateData, signed char *, 0xE) = 0x1E;
                        Level31_805B4_Field(privateData, unsigned char *, 0xF) = (unsigned char) (Level31_805B4_Field(privateData, unsigned char *, 0xF) + 1);
                        if ((Level31_805B4_Field(contactMoby16, short *, 0x36) == 0xEF) && (Level31_805B4_Field(contactMoby16, unsigned char *, 0x48) != 0xA)) {
                            contactData18 = Level31_805B4_Field(contactMoby16, int **, 0);
                            if (Level31_805B4_Field(contactData18, unsigned char *, 0xE) == 0) {
                                Level31_805B4_func_8004F1C8(&originalFrame.sp20, (Vector3D *) contactPosition21, contactPosition17);
                                Level31_805B4_func_8004EF74(contactData18, (Vector3D *) &originalFrame.sp20, contactData18);
                                vector4=privateData;
                                __asm__("" : "=r"(vector4) : "0"(vector4));
                                counter3=Level31_805B4_Field(contactData18,unsigned char *,0xF);
                                field2=Level31_805B4_Field(contactData18,int *,8);
                                __asm__("" : "=r"(counter3), "=r"(field2) : "0"(counter3), "1"(field2));
                                one5=1;
                                __asm__("" : "=r"(one5) : "0"(one5));
                                Level31_805B4_Field(contactData18,unsigned char *,0xE)=0x1E;
                                __asm__ volatile("" : "=r"(counter3) : "0"(counter3) : "memory");
                                ++counter3;
                                __asm__ volatile("" : "=r"(counter3), "=r"(field2) : "0"(counter3), "1"(field2) : "memory");
                                Level31_805B4_Field(contactData18,int *,8)=field2>>1;
                                Level31_805B4_Field(contactData18,unsigned char *,0xF)=counter3;
                                returned2=Level31_805B4_func_8004EDE8(vector4,one5);
                                vector4=contactData18;
                                one5=1;
                                __asm__("" : "=r"(returned2), "=r"(vector4), "=r"(one5) : "0"(returned2), "1"(vector4), "2"(one5));
                                firstResult16=returned2;
                                returned2=Level31_805B4_func_8004EDE8(vector4,one5);
                                vector4=privateData;
                                firstWord5=firstResult16;
                                __asm__("" : "=r"(returned2), "=r"(vector4), "=r"(firstWord5) : "0"(returned2), "1"(vector4), "2"(firstWord5));
                                secondResult17=returned2;
                                __asm__("" : "=r"(secondResult17) : "0"(secondResult17));
                                meanResult16 = (int) (firstWord5 + secondResult17) >> 1;
                                Level31_805B4_func_8004F08C(vector4,firstWord5,meanResult16);
                                Level31_805B4_func_8004F08C(contactData18, secondResult17, meanResult16);
                            }
                        }
                    }
                    else {
                        var_v0_2 = Level31_805B4_Field(privateData, unsigned char *, 0xF);
                        if (var_v0_2 != 0) {
                            --var_v0_2;
                        block_91:
                            Level31_805B4_Field(privateData, unsigned char *, 0xF) = var_v0_2;
                        }
                    }
                }
            }
            temp_v0_12 = Level31_805B4_Field(privateData, void **, 0x10);
            if (Level31_805B4_func_8004F334(&moby->position, Level31_805B4_Field(temp_v0_12, int *, 0xC) + (Level31_805B4_Field(temp_v0_12, short *, 2) * 0x10)) < 0x200) {
                temp_a0_3 = Level31_805B4_Field(privateData, void **, 0x10);
                Level31_805B4_Field(temp_a0_3, short *, 2) = (short) ((int) (Level31_805B4_Field(temp_a0_3, short *, 2) + 1) % (short) Level31_805B4_Field(temp_a0_3, short *, 0));
            }
        }
        returned2=Level31_805B4_func_80036220(&moby->position,privateData+0x34,0,0);
        __asm__("" : "=r"(returned2) : "0"(returned2));
        if (returned2 != 0) {
            var_v0_3=4;
        }
        else {
            var_v0_3=0xFF;
        }
        Level31_805B4_Field(privateData, unsigned char *, 0xC) = var_v0_3;
        __asm__ volatile("" : : : "memory","4");
        moby->position.z -= 0x200;
        Level31_805B4_func_80055D24(moby, 2);
    }
}
#undef Level31_805B4_Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * complete instruction evidence sibling5262. Rev1 raw94/raw621 machine
 * contracts confirm shared structure and the branch/callback/stack flag
 * differences; helpers are retargeted against original Rev0 symbols.
 * Native/linked words and every retail hash remain required. Raw units,
 * fixed point domains, helper meanings and cadence remain unresolved.
 * Empty constraints emit no opcode. */
#define Controller81360Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Controller81360H18368() __asm__("func_80018368");          /* extern */
int Controller81360H19194() __asm__("func_80019194");             /* extern */
int Controller81360H1BA30() __asm__("func_8001BA30"); /* extern */
int Controller81360H1C288() __asm__("func_8001C288");    /* extern */
int Controller81360H4E9E4() __asm__("func_8004E9E4");                             /* extern */
int Controller81360H4EA2C() __asm__("func_8004EA2C");                             /* extern */
int Controller81360H4EF74() __asm__("func_8004EF74");           /* extern */
int Controller81360H55B18() __asm__("func_80055B18");                      /* extern */
int Controller81360H5629C() __asm__("func_8005629C");                      /* extern */
int Controller81360rand() __asm__("rand");                                         /* extern */
extern unsigned char Controller81360D658A0 __asm__("D_800658A0");
extern unsigned char Controller81360D65920 __asm__("D_80065920");
extern int Controller81360D6C574 __asm__("D_8006C574");
extern int Controller81360D6C578 __asm__("D_8006C578");
extern int Controller81360D6C640 __asm__("D_8006C640");
extern unsigned char Controller81360D70328 __asm__("D_80070328");
extern int Controller81360D71918 __asm__("D_80071918");
extern int Controller81360D7191C __asm__("D_8007191C");
extern int Controller81360D71920 __asm__("D_80071920");

void func_level_31_80081360(Moby *input_arg0) {
register Moby *arg0 __asm__("$21")=input_arg0;
    struct {Vector3D position;int padding;int vector[3];} frame;
    register Moby *temp_v0 __asm__("$20");register int byte80 __asm__("$23");
    register Vector3D * temp_s1_2 __asm__("$17");
    register int temp_s0_2 __asm__("$16");
    register int temp_s0_3 __asm__("$16");
    register int temp_s1 __asm__("$17");
    register int temp_s3 __asm__("$19");
    int temp_v0_2;register int state3 __asm__("$3");register int work2 __asm__("$2");register int call4 __asm__("$4");register int other3 __asm__("$3");register int* table5 __asm__("$5");register int product6 __asm__("$6");register int product4 __asm__("$4");
    register int temp_v1_2 __asm__("$3");
    register int var_s6 __asm__("$22");
    unsigned char temp_v1;
    register void * temp_s0 __asm__("$16");
    register void * temp_s2 __asm__("$18");
    register void *var_a0 __asm__("$4");

    __asm__("" : "=r"(arg0):"0"(arg0));temp_s0 = arg0->mobyTag;
    if (arg0->damageFlags & 0x10000) {
        temp_v1 = arg0->state;
        if (temp_v1 != 1) {
            if (temp_v1 != 0x62) {
                arg0->colour.r = 0xF0;
                arg0->colour.g = 0xF0;
                arg0->colour.b = 0xF0;
                arg0->colour.a = 0x3E;
                temp_v1_2 = ((Controller81360Field(&Controller81360D70328, unsigned char *, 0xE) + (Controller81360Field(&Controller81360D70328, unsigned char *, 0xE) - func_8004E880(arg0->position.x - Controller81360Field(&Controller81360D70328, int *, 0), arg0->position.y - Controller81360Field(&Controller81360D70328, int *, 4), 0))) & 0xFF) * 2;
                Controller81360Field(temp_s0, int *, 0) = (int) ((int) (*(short*)(&Controller81360D65920 + temp_v1_2) * 0xF) >> 9);__asm__("" : : "r"(temp_v1_2):"memory");
                temp_v1_2=*(short*)(&Controller81360D658A0+temp_v1_2);Controller81360Field(temp_s0,int*,8)=100;Controller81360Field(temp_s0,int*,4)=(temp_v1_2*15)>>9;
                arg0->state = 0x62;
            }
        }
    }
    state3=arg0->state;work2=98;
    if(state3==work2)goto state98;
    if(state3<99){work2=1;if(state3==work2)goto state1;work2=3;if(state3==work2)goto state3label;goto done;}
    work2=99;if(state3==work2)goto state99;goto done;
    state1:
        var_s6 = 0;byte80=80;
loop_14:
        if ((Controller81360D6C578 - Controller81360D6C574) >= 0x15) {
            temp_v0 = SpawnMoby((int) arg0->mobyClass, arg0);__asm__("" : "=r"(temp_v0):"0"(temp_v0));
            if (temp_v0 != 0) {
                temp_s2 = temp_v0->mobyTag;
                temp_s3 = Controller81360rand() & 0xFFF;
                work2=Controller81360rand();call4=(int)&temp_v0->position;table5=(int*)&arg0->position;other3=-1;__asm__("" : "=r"(call4),"=r"(other3):"0"(call4),"1"(other3),"r"(work2));temp_s1=work2&0xFFF;
                temp_v0->unknownCollision = 0;
                temp_v0->unknown = other3;
                func_8004F178((Vector3D*)call4,(Vector3D*)table5);
                work2=Controller81360H4EA2C(temp_s1);call4=temp_s3;__asm__("" : "=r"(call4):"0"(call4),"r"(work2));temp_s0_2=work2;work2=Controller81360H4EA2C(call4);Controller81360Field(temp_s2,int*,0)=((temp_s0_2>>6)*work2)>>12;
                work2=Controller81360H4EA2C(temp_s1);call4=temp_s3;__asm__("" : "=r"(call4):"0"(call4),"r"(work2));temp_s0_3=work2;work2=Controller81360H4E9E4(call4);Controller81360Field(temp_s2,int*,4)=((temp_s0_3>>6)*work2)>>12;
                Controller81360Field(temp_s2, int *, 8) = (int) (Controller81360H4E9E4(temp_s1) >> 6);
                Controller81360Field(temp_s2, short *, 0xC) = func_8003636C(0x1E, 0x32);
                Controller81360Field(temp_s2, signed char *, 0x10) = 0;
                temp_v0->state = 3;
                temp_v0->size = byte80;
                temp_v0->lowDrawDistance = byte80;
                temp_v0->highDrawDistance = byte80;
                temp_v0->colour.r = arg0->colour.r;
                temp_v0->colour.g = arg0->colour.g;
                temp_v0->colour.b = arg0->colour.b;
                temp_v0->colour.a = arg0->colour.a;
            }
            var_s6 += 1;
            if(var_s6>=8)goto block_47;goto loop_14;
        }
goto block_47;
    state3label:
        if ((arg0->position.x >= 0x400) && (arg0->position.y >= 0x400) && (arg0->position.z >= 0x400)) {
            if ((Controller81360H19194(&arg0->position, 0x96) != 0) && ({table5=&Controller81360D71918;__asm__("" : "=r"(table5):"0"(table5));other3=Controller81360Field(temp_s0,int*,0);work2=*table5;product6=other3*work2;other3=Controller81360Field(temp_s0,int*,4);work2=Controller81360D7191C;product4=other3*work2;other3=Controller81360Field(temp_s0,int*,8);work2=Controller81360D71920;other3=other3*work2;work2=product6+product4;work2+=other3;work2<0;}) && (Controller81360H4EF74(temp_s0, table5, temp_s0) != 0)) {
                Controller81360Field(temp_s0, int *, 0) = (int) ((int) (Controller81360Field(temp_s0, int *, 0) * 6) >> 3);
                Controller81360Field(temp_s0, int *, 4) = (int) ((int) (Controller81360Field(temp_s0, int *, 4) * 6) >> 3);
                Controller81360Field(temp_s0, int *, 8) = (int) ((int) (Controller81360Field(temp_s0, int *, 8) * 6) >> 3);
            }
            func_8004F194(&arg0->position, &arg0->position, (Vector3D *) temp_s0);
            temp_v0_2 = Controller81360Field(temp_s0, int *, 8) - 6;
            Controller81360Field(temp_s0, int *, 8) = temp_v0_2;
            if (temp_v0_2 < -0x80) {
                Controller81360Field(temp_s0, int *, 8) = -0x80;
            }
            if (func_800359A4(temp_s0 + 0xC, 2) != 0) {
                goto block_47;
            }
            return;
        }
        goto block_47;
    state98:
        Controller81360Field(temp_s0, int *, 8) = (int) (Controller81360Field(temp_s0, int *, 8) - 0xC);
        /* fallthrough */
    state99:
        if ((arg0->position.x >= 0x400) && (arg0->position.y >= 0x400) && (arg0->position.z >= 0x400)) {
            call4=(int)&frame.position;__asm__("" : "=r"(call4):"0"(call4));temp_s1_2=&arg0->position;func_8004F178((Vector3D*)call4,temp_s1_2);
            func_8004F194(temp_s1_2, temp_s1_2, (Vector3D *) temp_s0);
            if (arg0->state != 0x62) {
                frame.vector[0] = func_800363DC(0, 7);
                frame.vector[1] = func_800363DC(0, 7);
                frame.vector[2] = 0xF;
                if (Controller81360D6C640 & 1) {
                    SpawnParticle(1, 0x37, temp_s1_2, (Vector3D *) &frame.vector[0]);
                }
                if (arg0->state != 0x62) {
                    if (Controller81360H1C288(temp_s1_2, 0x64, 7) != 0) {
                        Controller81360Field(&Controller81360D70328, int *, 0x298) = func_8004E880(Controller81360Field(temp_s0, int *, 0), Controller81360Field(temp_s0, int *, 4), 0);
                        goto block_41;
                    }
                } else {
                    goto block_40;
                }
            } else {
block_40:
                if (Controller81360H1C288(&arg0->position, 0x64, 0) != 0) {
block_41:
                    arg0->state = 1;
                }
                var_a0 = temp_s0 + 0x11;
            }
            var_a0=temp_s0+0x11;
            if ((func_800359A4(var_a0, 1) != 0) && (Controller81360H1BA30(&arg0->position, 0x96, 1, 0, 0, arg0) != 0)) {
                arg0->state = 1;
            }
            if(!func_800359A4(temp_s0+0xC,2))goto end99;
            block_47: Controller81360H55B18(arg0);goto done;
            end99:
            if (Controller81360H18368(&frame.position, &arg0->position) != 0) {
                arg0->state = 1;
            }
            func_80035D38(arg0);
            Controller81360H5629C(arg0);
        } else {
            goto block_47;
        }
        goto done;

    done:;
}

#undef Controller81360Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80081920.
* Assembly SHA256 ed6b3b1bcd9e1e6c0b6fda15cec1a8d8e9f5f3043644830180addf11db546f95.
* AI generated;not human reviewed. All744 instructions and actual native/
* linked branch/call targets are required. No owned selector/data words.
* Original frame50 preserves S0..S6/RA and the SP20..2B vector workspace.
* Entry callback74350 consumes original A0 owner,A1 private+30,A2=50.
* Private-class physical decision order0/3/4/1 and every shared removal/
* owner-state entry retain original destinations. Two byte CRC loops retain
* mask8000,polynomial8005,bounds64 and exact cursor byte increments,including
* the original main_TEXT_START+2 byte address and post-loop CRC reload.
* Record references use full word-pointer chains. Vector stores preserve
* the original SP28 zero store and following player+44 overwrite. All trig
* inputs are signed halfwords at their original byte offsets. The last
* two2803C calls retain complete S4/S3/S0 address producers,S1 literal5,
* independent record indices and original signed-halfword result consumers.
* The int2803C alias is a raw return-register view;explicit short casts
* preserve the original consumer extensions after second-call arguments.
* Initialized empty identities,late inputs and dead clobbers emit zero
* instructions. No opcode assembly,partialHI,fixedFP or overlapping live
* fixed aliases. Confidence is binary identity after all gates. Units/
* fixed point,complete helper contracts,caller cadence and synchronized
* retail runtime remain open. Cadence recorded here is per invocation.
* Falsification:every native/linked word,actual transfer target,original
* data byte,complete EXE and every overlay retail hash. */
#define Actor31_81920Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Actor31_81920Call13AE4View1() __asm__("func_80013AE4");
int Actor31_81920Call13B7CView1() __asm__("func_80013B7C");
int Actor31_81920Call13D44View1() __asm__("func_80013D44");
int Actor31_81920Call21ED8View1() __asm__("func_80021ED8");
int Actor31_81920Call21F8CView1() __asm__("func_80021F8C");
int Actor31_81920Call2803CView1() __asm__("func_8002803C");
int Actor31_81920Call28154View1() __asm__("func_80028154");
int Actor31_81920Call34F40View1() __asm__("func_80034F40");
int Actor31_81920Call3585CView1() __asm__("func_8003585C");
int Actor31_81920Call359A4View1() __asm__("func_800359A4");
int Actor31_81920Call35DDCView1() __asm__("func_80035DDC");
int Actor31_81920Call36220View1() __asm__("func_80036220");
int Actor31_81920Call3636CView1() __asm__("func_8003636C");
int Actor31_81920Call37BBCView1() __asm__("func_80037BBC");
int Actor31_81920Call3B74CView1() __asm__("func_8003B74C");
int Actor31_81920Call3B7B4View1() __asm__("func_8003B7B4");
int Actor31_81920Call3BB10View1() __asm__("func_8003BB10");
int Actor31_81920Call4E880View1() __asm__("func_8004E880");
int Actor31_81920Call4F178View1() __asm__("func_8004F178");
int Actor31_81920Call4F194View1() __asm__("func_8004F194");
int Actor31_81920Call4F334View1() __asm__("func_8004F334");
int Actor31_81920Call512E4View1() __asm__("func_800512E4");
int Actor31_81920Call55B18View1() __asm__("func_80055B18");
int Actor31_81920DatarandView1() __asm__("rand");
extern int Actor31_81920Data658A0View1 __asm__("D_800658A0");
extern int Actor31_81920Data65920View1 __asm__("D_80065920");
extern int Actor31_81920Data676E8View1 __asm__("D_800676E8");
extern int Actor31_81920Data6C550View1 __asm__("D_8006C550");
extern int Actor31_81920Data6C58CView1 __asm__("D_8006C58C");
extern int Actor31_81920Data6C76CView1 __asm__("D_8006C76C");
extern int Actor31_81920Data6C770View1 __asm__("D_8006C770");
extern unsigned char Actor31_81920Data6C7B4View1 __asm__("D_8006C7B4");
extern int Actor31_81920Data6C7F8View1 __asm__("D_8006C7F8");
extern int Actor31_81920Data6D088View1 __asm__("D_8006D088");
extern int Actor31_81920Data6E044View1 __asm__("D_8006E044");
extern int Actor31_81920Data6E048View1 __asm__("D_8006E048");
extern int Actor31_81920Data6E344View1 __asm__("D_8006E344");
extern int Actor31_81920Data70300View1 __asm__("D_80070300");
extern int Actor31_81920Data70328View1 __asm__("D_80070328");
extern int Actor31_81920Data8FAF8View1 __asm__("D_level_31_8008FAF8");
extern int(*Actor31_81920DataSpawnParticleView1)() __asm__("SpawnParticle");
extern int Actor31_81920Call27A60View1 __asm__("func_80027A60");
extern int Actor31_81920Call27E40View1 __asm__("func_80027E40");
extern int Actor31_81920Call29904View1 __asm__("func_80029904");
extern int Actor31_81920Call757BCView1 __asm__("func_level_31_800757BC");
extern int Actor31_81920Datamain_TEXT_ENDView1 __asm__("main_TEXT_END");
extern int Actor31_81920Datamain_TEXT_STARTView1 __asm__("main_TEXT_START");
extern int(*Actor31_81920Data74348View1)() __asm__("unk_ovlheader_80074348");
extern int(*Actor31_81920Data7434CView1)() __asm__("unk_ovlheader_8007434C");
extern int(*Actor31_81920Data74350View1)() __asm__("unk_ovlheader_80074350");
void func_level_31_80081920(void *input) {
    register int indexWord8 __asm__("$8"), recordBase9 __asm__("$9");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentOrEndAddress6 __asm__("$6"), argumentAddress7 __asm__("$7"), originalLiteralFive17 __asm__("$17"), callbackAddress19 __asm__("$19"), callbackAddress20 __asm__("$20");
    register void *ownerRecord22 __asm__("$22");
    register int privateRecord21 __asm__("$21"), retainedAddress16 __asm__("$16"), retainedRecordOrArchive18 __asm__("$18"), counterOrArgument4 __asm__("$4"), counterOrArgument5 __asm__("$5");
    struct{
        int sp20, sp24, sp28;
    }
    originalFrame;
    int temporaryWord1;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    ownerRecord22 = input;
    __asm__("":"=r"(ownerRecord22):"0"(ownerRecord22));
    privateRecord21 = Actor31_81920Field(ownerRecord22, void **, 0);
    if ((Actor31_81920Field(ownerRecord22, int *, 0x18) & 0xA0000) && (Actor31_81920Data74350View1(input, privateRecord21+0x30, 0x50) != 0)) {
        Actor31_81920Field(ownerRecord22, signed char *, 0x54) = 0;
        Actor31_81920Field(ownerRecord22, signed char *, 0x55) = 0;
        Actor31_81920Field(ownerRecord22, signed char *, 0x56) = 0;
        Actor31_81920Field(ownerRecord22, signed char *, 0x57) = 0;
    }
    if ((Actor31_81920Field(ownerRecord22, int *, 0x18) & 0x10000) && ((unsigned char) Actor31_81920Field(ownerRecord22, unsigned char *, 0x48) < 0x51U)) {
        Actor31_81920Data74348View1(ownerRecord22, privateRecord21 + 0x30, 0x50, 0x1C);
    }
    Actor31_81920Field(ownerRecord22, int *, 0x18) = 0;
    if ((Actor31_81920Field(privateRecord21, unsigned char *, 0) == 4) && (Actor31_81920Call36220View1(&Actor31_81920Data70328View1, privateRecord21 + 0x60, 0, 0) != 0)) {
        Actor31_81920Field(privateRecord21, int *, 0x78) = 1;
    }
    if ((Actor31_81920Field(privateRecord21, unsigned int *, 0x5C) == &Actor31_81920Data8FAF8View1) && (Actor31_81920Field(privateRecord21, int *, 0x4C) != 0)) {
        Actor31_81920DatarandView1();
        Actor31_81920Data6C76CView1 = 0;
        rawWord3 = 0;
        counterOrArgument5 = (int)&Actor31_81920Data676E8View1;
        __asm__("":"=r"(counterOrArgument5):"0"(counterOrArgument5));
        counterOrArgument4 = 0x35E8;
        do {
            rawWord3 += 1;
            Actor31_81920Field(counterOrArgument5, int*, 0) = counterOrArgument4;
        }
        while (rawWord3 < 0x28);
        Actor31_81920Field(privateRecord21, int *, 0x4C) = 0;
    }
    rawWord3 = Actor31_81920Field(ownerRecord22, unsigned char *, 0x48);
    switch (rawWord3) {
    case 0x53:
        Actor31_81920Call34F40View1(ownerRecord22, 2);
        temporaryWord4 = (Actor31_81920Field(privateRecord21, int *, 0x7C) * 0x58) + Actor31_81920Data6C550View1;
        Actor31_81920Call3585CView1(ownerRecord22, Actor31_81920Call4E880View1(Actor31_81920Field(temporaryWord4, int *, 0xC) - Actor31_81920Field(ownerRecord22, int *, 0xC), Actor31_81920Field(temporaryWord4, int *, 0x10) - Actor31_81920Field(ownerRecord22, int *, 0x10), 0), 4, 0, 1, 0);
        Actor31_81920Call35DDCView1(ownerRecord22, 0x96, 0, 0, 0);
        if (Actor31_81920Call4F334View1(ownerRecord22 + 0xC, Actor31_81920Data6C550View1 + (Actor31_81920Field(privateRecord21, int *, 0x7C) * 0x58) + 0xC) < 0x200) {
            Actor31_81920Field(privateRecord21, int *, 0x58) = 0xF;
            Actor31_81920Field(ownerRecord22, unsigned char *, 0x48) = 0x54U;
            return;
        }
        return;
    case 0x54:
        Actor31_81920Call35DDCView1(ownerRecord22, 0x96, 0, 0, 0);
        Actor31_81920DataSpawnParticleView1(2, 0xC, Actor31_81920Data6C550View1 + (Actor31_81920Field(privateRecord21, int *, 0x7C) * 0x58), 5);
        if (Actor31_81920Call359A4View1(privateRecord21 + 0x58, 4) != 0) {
            goto callSharedRemoval;
        }
        break;
    case 0x0:
        if (Actor31_81920Data6C770View1 != 0) {
            rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x80);
            counterOrArgument4 = (int)ownerRecord22;
            if (rawWord2) goto decrementOriginalPrivateCounter;
            Actor31_81920Call34F40View1(counterOrArgument4, 4);
            Actor31_81920Field(privateRecord21, int*, 0x80) = Actor31_81920Call3636CView1(3, 8);
            goto dispatchOriginalPrivateClass;
            decrementOriginalPrivateCounter:__asm__ __volatile__("":::"$3");
            Actor31_81920Call34F40View1(counterOrArgument4, 0);
            rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x80);
            rawWord2--;
            Actor31_81920Field(privateRecord21, int*, 0x80) = rawWord2;
            dispatchOriginalPrivateClass:;
        }
        rawWord3 = Actor31_81920Field(privateRecord21, unsigned char*, 0);
        if (!rawWord3) goto class0Crc;
        rawWord2 = 3;
        if (rawWord3 == rawWord2) goto class3Flag;
        rawWord2 = 4;
        goto checkPrivateClass4;
    class0Crc:
        rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x5C);
        rawWord3 = (int)&Actor31_81920Call757BCView1;
        rawWord2 = (unsigned int)rawWord2 < (unsigned int)rawWord3;
        counterOrArgument5 = 0;
        if (rawWord2) goto class3Flag;
        argumentOrEndAddress6 = (int)&Actor31_81920Data8FAF8View1;
        __asm__("":"=r"(argumentOrEndAddress6):"0"(argumentOrEndAddress6));
    class0CrcLoop:
        rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x5C);
        rawWord2 = (unsigned int)rawWord3 < (unsigned int)argumentOrEndAddress6;
        counterOrArgument4 = 0;
        if (!rawWord2) goto class3Flag;
        rawWord2 = Actor31_81920Field(rawWord3, unsigned char*, 0);
        rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x4C);
        rawWord2 <<= 8;
        rawWord3 ^= rawWord2;
        Actor31_81920Field(privateRecord21, int*, 0x4C) = rawWord3;
        do{
            rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x4C);
            if (rawWord3&0x8000){
                rawWord2 = rawWord3*2;
                rawWord2 ^= 0x8005;
            }
            else rawWord2 = rawWord3*2;
            Actor31_81920Field(privateRecord21, int*, 0x4C) = rawWord2;
            counterOrArgument4++;
        }
        while (counterOrArgument4 < 8);
        rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x5C);
        counterOrArgument5++;
        rawWord2++;
        Actor31_81920Field(privateRecord21, int*, 0x5C) = rawWord2;
        if (counterOrArgument5 < 64) goto class0CrcLoop;
    class3Flag:
        rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x40);
        rawWord2 = rawWord3*88;
        rawWord3 = Actor31_81920Data6C550View1;
        rawWord2 += rawWord3;
        rawWord2 = Actor31_81920Field(rawWord2, unsigned char*, 0x48)&0x80;
        goto storePrivateFlagWhenNonzero;
        checkPrivateClass4:if (rawWord3 != rawWord2) goto checkPrivateClass1;
        rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x78);
        storePrivateFlagWhenNonzero:if (rawWord2)Actor31_81920Field(privateRecord21, unsigned char*, 2) = 2;
        goto checkPrivateClassAfterSelector;
        checkPrivateClass1:rawWord2 = 1;
        if (rawWord3 != rawWord2) goto checkPrivateClassAfterSelector;
        __asm__ __volatile__("":::"$3");
        rawWord2 = Actor31_81920Field(ownerRecord22, unsigned char*, 0x49);
        if (rawWord2) goto checkPrivateClassAfterSelector;
        rawWord2 = Actor31_81920Data6C7B4View1;
        rawWord2 &= 1;
        counterOrArgument4 = 1;
        if (rawWord2) goto callOriginalTextHelpers;
        rawWord2 = Actor31_81920Data6C58CView1;
        rawWord2 = Actor31_81920Field(&Actor31_81920Data70300View1, unsigned char*, rawWord2);
        rawWord2 &= 1;
        if (!rawWord2) goto checkPrivateClassAfterSelector;
        callOriginalTextHelpers:Actor31_81920Call21ED8View1(counterOrArgument4, 0xFC, 0);
        Actor31_81920Call21F8CView1(1, 0x13, 0);
        rawWord2 = 1;
        Actor31_81920Field(ownerRecord22, unsigned char*, 0x49) = rawWord2;
        callSharedRemoval:Actor31_81920Call55B18View1(ownerRecord22);
        return;
    checkPrivateClassAfterSelector:
        rawWord3 = Actor31_81920Field(privateRecord21, unsigned char *, 0);
        if (rawWord3 == 2) {
            if (Actor31_81920Field(ownerRecord22, unsigned char *, 0x49) != 0) {
                retainedAddress16 = privateRecord21 + 0x78;
                rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x48);
                counterOrArgument4 = Actor31_81920Data6C550View1;
                rawWord3 = rawWord2*88;
                rawWord3 += counterOrArgument4;
                rawWord2 = Actor31_81920Field(rawWord3, int*, 0);
                rawWord2 = Actor31_81920Field(rawWord2, int*, 0);
                if (rawWord2 >= 5){
                    Actor31_81920Field(ownerRecord22, signed char *, 0x4A) = 0x20;
                    Actor31_81920Field(ownerRecord22, unsigned char *, 0x49) = 0U;
                    Actor31_81920Field(privateRecord21, int *, 0x78) = 1;
                    Actor31_81920Field(privateRecord21, unsigned char *, 2) = 6U;
                    Actor31_81920Field(privateRecord21, signed char *, 5) = 1;
                    Actor31_81920Call3B7B4View1(retainedAddress16, 4, &Actor31_81920Data6D088View1);
                    Actor31_81920Call3B7B4View1(retainedAddress16, 4, &Actor31_81920Data6C7F8View1);
                    retainedAddress16 = privateRecord21 + 2;
                    Actor31_81920Call3B7B4View1(retainedAddress16, 1, &Actor31_81920Data6D088View1);
                    Actor31_81920Call3B7B4View1(retainedAddress16, 1, &Actor31_81920Data6C7F8View1);
                    retainedAddress16 = privateRecord21 + 5;
                    Actor31_81920Call3B7B4View1(retainedAddress16, 1, &Actor31_81920Data6D088View1);
                    Actor31_81920Call3B7B4View1(retainedAddress16, 1, &Actor31_81920Data6C7F8View1);
                    Actor31_81920Call3B74CView1(&Actor31_81920Data6D088View1);
                    return;
                }
                rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x44);
                counterOrArgument4 = Actor31_81920Data6C550View1;
                rawWord3 = rawWord2*88;
                rawWord3 += counterOrArgument4;
                rawWord2 = Actor31_81920Field(rawWord3, int*, 0);
                rawWord2 = Actor31_81920Field(rawWord2, int*, 0);
                if (rawWord2 >= 5){
                    Actor31_81920Field(ownerRecord22, signed char *, 0x4A) = 0x20;
                    Actor31_81920Call28154View1(Actor31_81920Field(privateRecord21, int *, 0x50));
                    Actor31_81920Call28154View1(Actor31_81920Field(privateRecord21, int *, 0x54));
                    rawWord2 = Actor31_81920Data6C7B4View1;
                    rawWord3 = Actor31_81920Field(ownerRecord22, int*, 0);
                    rawWord2 |= 8;
                    Actor31_81920Data6C7B4View1 = rawWord2;
                    rawWord2 = 2;
                    Actor31_81920Field(ownerRecord22, unsigned char*, 0x49) = 0;
                    Actor31_81920Field(rawWord3, signed char*, 5) = rawWord2;
                    rawWord2 = Actor31_81920Field(ownerRecord22, unsigned char*, 0x46);
                    rawWord2 <<= 1;
                    rawWord3 = Actor31_81920Field(&Actor31_81920Data65920View1, short*, rawWord2);
                    counterOrArgument4 = (int)&originalFrame.sp20;
                    rawWord2 = (rawWord3*39) >> 6;
                    originalFrame.sp20 = rawWord2;
                    rawWord2 = Actor31_81920Field(ownerRecord22, unsigned char*, 0x46);
                    counterOrArgument5 = counterOrArgument4;
                    rawWord2 <<= 1;
                    rawWord3 = Actor31_81920Field(&Actor31_81920Data658A0View1, short*, rawWord2);
                    rawWord2 = Actor31_81920Field(&Actor31_81920Data70328View1, int*, 0x44);
                    argumentOrEndAddress6 = (int)ownerRecord22+12;
                    (*(volatile int*)&originalFrame.sp28) = 0;
                    originalFrame.sp28 = rawWord2;
                    rawWord2 = (rawWord3*39) >> 6;
                    originalFrame.sp24 = rawWord2;
                    Actor31_81920Call4F194View1(counterOrArgument4, counterOrArgument5, argumentOrEndAddress6);
                    Actor31_81920Call13D44View1(&originalFrame.sp20, (Actor31_81920Field(ownerRecord22, unsigned char *, 0x46) + 0x80) & 0xFF, 0, 0);
                    if (Actor31_81920Field(&Actor31_81920Data70328View1, int *, 0x280) < 0) {
                        Actor31_81920Field(&Actor31_81920Data70328View1, int *, 0x280) = 0;
                    }
                }
                goto callOwnerHelperAfterClass;
            }
            rawWord3 = Actor31_81920Field(privateRecord21, unsigned char *, 2);
            if (rawWord3 < 4U) {
                if (Actor31_81920Data6C7B4View1 & 8) {
                    Actor31_81920Field(privateRecord21, unsigned char *, 2) = 5U;
                }
                else if (Actor31_81920Field(privateRecord21, int *, 0x78) != 0) {
                    if (rawWord3 == 0) {
                        Actor31_81920Field(privateRecord21, unsigned char *, 2) = 7U;
                    }
                }
                else {
                    Actor31_81920Field(privateRecord21, unsigned char *, 2) = 0U;
                }
            }
            goto callOwnerHelperAfterClass;
        }
        if (rawWord3 == 0){
            rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x5C);
            if (!rawWord2){
                rawWord2 = Actor31_81920Data6C58CView1;
                rawWord3 = (int)&Actor31_81920Datamain_TEXT_STARTView1+2;
                rawWord2 += rawWord3;
                Actor31_81920Field(privateRecord21, int*, 0x5C) = rawWord2;
                rawWord2 = Actor31_81920Field(privateRecord21, volatile int*, 0x5C);
            }
            rawWord3 = (int)&Actor31_81920Datamain_TEXT_ENDView1;
            rawWord2 = (unsigned int)rawWord2 < (unsigned int)rawWord3;
            counterOrArgument5 = 0;
            if (!rawWord2) goto callOwnerHelperAfterClass;
            argumentOrEndAddress6 = rawWord3;
        class0TextLoop:
            rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x5C);
            rawWord2 = (unsigned int)rawWord3 < (unsigned int)argumentOrEndAddress6;
            counterOrArgument4 = 0;
            if (!rawWord2) goto resetTextCursor;
            rawWord2 = Actor31_81920Field(rawWord3, unsigned char*, 0);
            rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x4C);
            rawWord2 <<= 8;
            rawWord3 ^= rawWord2;
            Actor31_81920Field(privateRecord21, int*, 0x4C) = rawWord3;
            do{
                rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x4C);
                if (rawWord3&0x8000){
                    rawWord2 = rawWord3*2;
                    rawWord2 ^= 0x8005;
                }
                else rawWord2 = rawWord3*2;
                Actor31_81920Field(privateRecord21, int*, 0x4C) = rawWord2;
                counterOrArgument4++;
            }
            while (counterOrArgument4 < 8);
            counterOrArgument5++;
            rawWord2 = Actor31_81920Field(privateRecord21, volatile int*, 0x4C);
            rawWord3 = Actor31_81920Field(privateRecord21, int*, 0x5C);
            rawWord2 &= 3;
            rawWord2++;
            rawWord3 += rawWord2;
            Actor31_81920Field(privateRecord21, int*, 0x5C) = rawWord3;
            if (counterOrArgument5 < 64) goto class0TextLoop;
            rawWord2 = (int)&Actor31_81920Datamain_TEXT_ENDView1;
            rawWord2 = (unsigned int)rawWord3 < (unsigned int)rawWord2;
            if (rawWord2) goto callOwnerHelperAfterClass;
            resetTextCursor:rawWord2 = (int)&Actor31_81920Call757BCView1;
            Actor31_81920Field(privateRecord21, int*, 0x5C) = rawWord2;
        }
    callOwnerHelperAfterClass:
        if (Actor31_81920Call37BBCView1(ownerRecord22, 0) != 0) {
            if (Actor31_81920Field(privateRecord21, unsigned char *, 0) == 1) {
                Actor31_81920Data6C7B4View1 |= 1;
            }
            Actor31_81920Call512E4View1(ownerRecord22, 0, 1);
            Actor31_81920Field(ownerRecord22, unsigned char *, 0x48) = 0x51U;
            return;
        }
        break;
    case 0x51:
        if (Actor31_81920Data6E344View1 != 1) {
            Actor31_81920Call34F40View1(ownerRecord22, 0);
            if ((Actor31_81920Field(privateRecord21, unsigned char *, 0) == 1) && (Actor31_81920Field(privateRecord21, unsigned char *, 4) == 0)) {
                temporaryWord1 = Actor31_81920Field(Actor31_81920Field(privateRecord21, void **, 0x3C), int **, 0xC);
                Actor31_81920Call13AE4View1(temporaryWord1, temporaryWord1 + 0x10);
                Actor31_81920Field(privateRecord21, int *, 0x58) = 0x78;
                Actor31_81920Field(ownerRecord22, unsigned char*, 0x4A) = 255;
                Actor31_81920Field(ownerRecord22, unsigned char *, 0x48) = 0x52U;
                return;
            }
            if ((Actor31_81920Field(privateRecord21, unsigned char *, 0) == 2) && (Actor31_81920Field(privateRecord21, unsigned char *, 4) == 1)) {
                temporaryWord5 = Actor31_81920Field(Actor31_81920Field(privateRecord21, void **, 0x3C), int **, 0xC);
                temporaryWord2 = Actor31_81920Field(temporaryWord5, int *, 0x10);
                Actor31_81920Call13D44View1(Actor31_81920Field(Actor31_81920Field(privateRecord21, void **, 0x3C), int **, 0xC), Actor31_81920Call4E880View1(temporaryWord2 - Actor31_81920Field(temporaryWord5, int *, 0), Actor31_81920Field(temporaryWord5, int *, 0x14) - Actor31_81920Field(temporaryWord5, int *, 4), 0, temporaryWord2), 0, 0);
                Actor31_81920Field(ownerRecord22, unsigned char*, 0x4A) = 255;
                Actor31_81920Field(ownerRecord22, unsigned char *, 0x48) = 0x1EU;
                return;
            }
            goto clearOwnerStateAndReturn;
        }
        break;
    case 0x50:
        Actor31_81920Data7434CView1(ownerRecord22, privateRecord21 + 0x30);
        return;
    case 0x1E:
        if (Actor31_81920Data6E044View1 != 0xB) {
            counterOrArgument4 = 0x15;
            counterOrArgument5 = 0x138;
            callbackAddress20 = (int)&Actor31_81920Call27E40View1;
            __asm__("":"=r"(callbackAddress20):"0"(callbackAddress20), "r"(counterOrArgument4), "r"(counterOrArgument5));
            argumentOrEndAddress6 = callbackAddress20;
            callbackAddress19 = (int)&Actor31_81920Call27A60View1;
            __asm__("":"=r"(callbackAddress19):"0"(callbackAddress19), "r"(argumentOrEndAddress6));
            argumentAddress7 = callbackAddress19;
            retainedAddress16 = (int)&Actor31_81920Call29904View1;
            __asm__("":"=r"(retainedAddress16):"0"(retainedAddress16), "r"(argumentAddress7));
            rawWord2 = Actor31_81920Field(privateRecord21, int*, 0x48);
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"$9");
            recordBase9 = Actor31_81920Data6C550View1;
            __asm__("":"=r"(recordBase9):"0"(recordBase9):"$8");
            indexWord8 = Actor31_81920Field(privateRecord21, int*, 0x44);
            __asm__("":"=r"(indexWord8):"0"(indexWord8), "r"(rawWord2):"$3");
            rawWord3 = rawWord2*88;
            rawWord3 += recordBase9;
            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$2");
            rawWord2 = indexWord8*88;
            rawWord2 += recordBase9;
            __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"memory");
            retainedRecordOrArchive18 = Actor31_81920Field(rawWord3, int*, 0);
            __asm__("":"=r"(retainedRecordOrArchive18):"0"(retainedRecordOrArchive18):"memory");
            rawWord2 = Actor31_81920Field(rawWord2, int*, 0);
            __asm__(""::"r"(rawWord2), "r"(retainedRecordOrArchive18):"$17");
            originalLiteralFive17 = 5;
            __asm__("":"=r"(originalLiteralFive17):"0"(originalLiteralFive17));
            rawWord2 = Actor31_81920Call2803CView1(counterOrArgument4, counterOrArgument5, argumentOrEndAddress6, argumentAddress7, retainedAddress16, rawWord2, originalLiteralFive17);
            counterOrArgument4 = 0x17;
            counterOrArgument5 = 0x139;
            argumentOrEndAddress6 = callbackAddress20;
            argumentAddress7 = callbackAddress19;
            __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(counterOrArgument4), "r"(counterOrArgument5), "r"(argumentOrEndAddress6), "r"(argumentAddress7));
            rawWord2 = (short)rawWord2;
            Actor31_81920Field(privateRecord21, int*, 0x50) = rawWord2;
            rawWord2 = Actor31_81920Call2803CView1(counterOrArgument4, counterOrArgument5, argumentOrEndAddress6, argumentAddress7, retainedAddress16, retainedRecordOrArchive18, originalLiteralFive17);
            rawWord2 = (short)rawWord2;
            Actor31_81920Field(privateRecord21, int*, 0x54) = rawWord2;
            Actor31_81920Field(ownerRecord22, unsigned char*, 0x49) = 1;
            clearOwnerStateAndReturn:Actor31_81920Field(ownerRecord22, unsigned char*, 0x48) = 0;
            return;
        }
        if (Actor31_81920Data6E048View1 & 1) {
            Actor31_81920Call4F178View1(Actor31_81920Data6C550View1 + (Actor31_81920Field(privateRecord21, int *, 0x40) * 0x58) + 0xC, ((int)Actor31_81920Field(Actor31_81920Field(privateRecord21, void**, 0x3C), int**, 0xC)+0x10));
            temporaryWord6 = Actor31_81920Field(Actor31_81920Field(privateRecord21, void **, 0x3C), int **, 0xC);
            temporaryWord3 = Actor31_81920Field(temporaryWord6, int *, 0);
            Actor31_81920Field(ownerRecord22, unsigned char *, 0x46) = Actor31_81920Call4E880View1(temporaryWord3 - Actor31_81920Field(temporaryWord6, int *, 0x10), Actor31_81920Field(temporaryWord6, int *, 4) - Actor31_81920Field(temporaryWord6, int *, 0x14), 0, temporaryWord3);
            return;
        }
        break;
    case 0x52:
        if (Actor31_81920Call359A4View1(privateRecord21 + 0x58, 4) != 0) {
            if (Actor31_81920Field(ownerRecord22, unsigned char *, 0x49) != 0) {
                Actor31_81920Call13B7CView1(1);
                Actor31_81920Field(ownerRecord22, unsigned char *, 0x48) = 0x53U;
                return;
            }
            Actor31_81920Field(privateRecord21, int *, 0x58) = 0xB4;
            Actor31_81920Call3BB10View1(ownerRecord22, 6, 1);
            Actor31_81920Call21ED8View1(1, 0xFC, 0);
            Actor31_81920Field(ownerRecord22, unsigned char *, 0x49) = 1U;
        }
        break;
    }
}
#undef Actor31_81920Field


extern int D_8006C770;
void func_level_31_800824C0(Moby* moby) {
    Moby** tag = moby->mobyTag;
    if (moby->colour.a == 0x50) return;
    switch (moby->animationState.id) {
    case 0:
        if (moby->damageFlags && *tag) {
            if (*(Moby**)((char*)&spyro + 0x13C) == moby) moby->damageFlags &= ~0x20000;
            (*tag)->damageFlags |= moby->damageFlags;
        }
        moby->damageFlags = 0;
        break;
    case 1: case 6:
        if (D_8006C770) func_80055B18(moby);
        break;
    case 2: case 3: case 4: case 5:
        func_80039714(moby);
        break;
    }
}

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
void func_level_31_800825A8(void *input) {
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


extern int D_8006C640, D_8006C770, D_8006C58C;
extern unsigned char D_8006C7B4, D_80070300[];
void func_level_31_800836FC(Moby* moby) {
    if (D_8006C640 == 0 && ((D_8006C7B4 & 1) || (D_80070300[D_8006C58C] & 1))) {
        func_8003BA00(moby); func_80055B18(moby); return;
    }
    switch(moby->state) {
    case 0:
        moby->size=0x1D;
        moby->substate=moby->unknown3[0];
        moby->unknown3[0]=0;
        moby->state=1;
        break;
    case 1:
        if ((moby->damageFlags & 0x10000000) || moby->animationState.frame >= 0x14)
            moby->unknown3[0]=moby->substate;
        else moby->unknown3[0]=0;
        if(D_8006C770) {func_8003BA00(moby);func_80055B18(moby);return;}
        break;
    }
    moby->damageFlags=0;
}

extern Moby* D_8006C550;
extern unsigned char* D_8006C54C;
extern unsigned char D_level_31_8008FAF8[];
extern int D_8006C774;
extern unsigned int DecodedTriggerCode[] __asm__("func_800512E4");
void func_level_31_80083810(Moby* moby) {
    int* tag = moby->mobyTag;
    if (*tag >= 0) {
        if (D_8006C54C - 1 == D_level_31_8008FAF8 && D_8006C774) {
            DecodedTriggerCode[0] = 0x03E00008;
            DecodedTriggerCode[1] = 0;
        }
        D_8006C550[*tag].angle.yaw = moby->angle.yaw;
        moby->position.z = D_8006C550[*tag].position.z;
        func_8004F178(&D_8006C550[*tag].position, &moby->position);
        moby->position.z += 0x400;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 80083924..80083C20. Rev1 raw178 routes; original signed tables,
 * unmasked release index and fresh phase reads remain authoritative.
 * Pointer producers, callback contracts and live cadence remain open. */
extern short D_80065920[],D_800658A0[];
extern unsigned char DecodedFrozenPlayer[] __asm__("D_80070328");
void func_8003BA00(Moby*);
int rand(void);
void func_level_31_80083924(Moby* argument) {
 Vector3D direction;
 register Moby* moby __asm__("$18")=argument;
 register unsigned char* tag __asm__("$16")=moby->mobyTag;
 register int heading __asm__("$16");
 register Moby* child __asm__("$17");
 register Vector3D* childVector __asm__("$17");
 register int index __asm__("$19");
 register short* cosTable __asm__("$20");
 register int product __asm__("$8");
 unsigned char* particle;
 int delta;
 if(moby->damageFlags&0x20000) {
  func_8003BABC(moby,0,0);
  index=0;
  __asm__("" : "=r"(index) : "0"(index) : "$20");
  cosTable=D_80065920;
  do {
   child=SpawnMoby(94,moby);
   __asm__("" : "=r"(child) : "0"(child));
   if(child) {
    child->state=98;child->unknownCollision=0;
    childVector=child->mobyTag;
    delta=rand();
    heading=DecodedFrozenPlayer[14]+(delta&63)-32;
    { register int speed __asm__("$2")=rand();
      register int sample __asm__("$3");
      speed&=127;
      heading*=2;
      sample=*(short*)(heading+(unsigned int)cosTable);
      speed+=127;
      product=sample*speed;
      __asm__("" : "=r"(product) : "0"(product));
      sample=product>>12;
      __asm__("" : "=r"(sample) : "0"(sample));
      childVector->x=sample;
      sample=*(short*)((char*)D_800658A0+heading);
      product=sample*speed;
      childVector->z=0;
      __asm__("" : "=r"(product) : "0"(product));
      speed=product>>12;
      __asm__("" : "=r"(speed) : "0"(speed));
      childVector->y=speed;
    }
    childVector->z=(rand()&127)+63;
    *(short*)((char*)childVector+12)=120;
    *((unsigned char*)childVector+17)=16;
   }
  } while(++index<6);
  func_8003BA00(moby);func_80055B18(moby);return;
 }
 { register int first __asm__("$3")=tag[0];
   register int second __asm__("$2")=tag[1];
   register int third __asm__("$4")=tag[2];
   __asm__("" : "=r"(first), "=r"(second), "=r"(third) : "0"(first), "1"(second), "2"(third));
   first=D_800658A0[first];second=D_800658A0[second];third=D_800658A0[third];

   moby->colour.b=0;moby->colour.a=0;
   __asm__ volatile("" : : : "memory");
   first=((first+second+third+12288)>>7)&255;
   moby->colour.r=((unsigned int)first>>3)-112;
   moby->colour.g=((unsigned int)(first*3)>>5)+32;
 }
 { register int phase0 __asm__("$2")=tag[0];
 register int phase2 __asm__("$3")=tag[2];
 phase0+=3;tag[0]=phase0;
 phase0=tag[1];
 phase2+=7;tag[2]=phase2;
 phase2=tag[3];
 __asm__("" : "=r"(phase2), "=r"(phase0) : "0"(phase2), "1"(phase0));
 phase0+=5;tag[1]=phase0;
 if(phase2==moby->substate) {
  delta=(rand()&62)-32;
  tag[3]+=delta;
  if(delta<0)moby->state=0;else moby->state=1;
 }
 }
 if(moby->state)moby->substate++;else moby->substate--;
 direction.x=(D_80065920[moby->substate]*3)>>11;
 direction.y=(D_800658A0[moby->substate]*3)>>11;
 direction.z=0;
 direction.z=(rand()&3)+21;
 particle=(unsigned char*)SpawnParticle(1,22,&moby->position,&direction);
 if(particle)*(unsigned short*)(particle+8)+=64;
}

void func_level_31_80083C24(Moby* moby) {
    func_80039714(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_31/moby/func_level_31_80083C44.s SHA256 1416716f0cee45fdbabf141e58ec2095e5010324390f49d235a0b94150e43fde. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level31_83C44Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Level31_83C44_func_80034F40() __asm__("func_80034F40");
             /* extern */
int Level31_83C44_func_80035194() __asm__("func_80035194");
                  /* extern */
int Level31_83C44_func_8003573C() __asm__("func_8003573C");
 /* extern */
int Level31_83C44_func_8003585C() __asm__("func_8003585C");
 /* extern */
int Level31_83C44_func_800359A4() __asm__("func_800359A4");
                 /* extern */
int Level31_83C44_func_80035DDC() __asm__("func_80035DDC");
 /* extern */
int Level31_83C44_func_800369B8() __asm__("func_800369B8");
             /* extern */
int Level31_83C44_func_80036A68() __asm__("func_80036A68");
 /* extern */
int Level31_83C44_func_80038F14() __asm__("func_80038F14");
 /* extern */
int Level31_83C44_func_8003BA00() __asm__("func_8003BA00");
                      /* extern */
int Level31_83C44_func_8003BB10() __asm__("func_8003BB10");
    /* extern */
int Level31_83C44_func_8004E880() __asm__("func_8004E880");
               /* extern */
int Level31_83C44_func_8004F264() __asm__("func_8004F264");
                        /* extern */
int Level31_83C44_func_8004F334() __asm__("func_8004F334");
      /* extern */
int Level31_83C44_func_80055B18() __asm__("func_80055B18");
                      /* extern */
int Level31_83C44_func_80055D24() __asm__("func_80055D24");
             /* extern */
int Level31_83C44_func_80055E84() __asm__("func_80055E84");
                          /* extern */
int Level31_83C44_rand() __asm__("rand");
                                         /* extern */
extern int Level31_83C44_D_8006C770 __asm__("D_8006C770");
extern int Level31_83C44_D_8006E020 __asm__("D_8006E020");
extern int Level31_83C44_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level31_83C44_D_8006E040 __asm__("D_8006E040");
extern int Level31_83C44_D_8006E044 __asm__("D_8006E044");
extern int Level31_83C44_D_8006E344 __asm__("D_8006E344");
extern unsigned char Level31_83C44_D_80070328 __asm__("D_80070328");
extern unsigned char (*Level31_83C44_unk_ovlheader_80074348)(void *, int, unsigned char, unsigned char) __asm__("unk_ovlheader_80074348");
extern unsigned char (*Level31_83C44_unk_ovlheader_8007434C)(void *, void *) __asm__("unk_ovlheader_8007434C");
extern int (*Level31_83C44_unk_ovlheader_80074350)(void *, int, unsigned char) __asm__("unk_ovlheader_80074350");
extern int (*Level31_83C44_unk_ovlheader_80074354)() __asm__("unk_ovlheader_80074354");
extern unsigned char (*Level31_83C44_unk_ovlheader_80074358)(void *) __asm__("unk_ovlheader_80074358");
extern unsigned char (*Level31_83C44_unk_ovlheader_800743E4)(unsigned char *, int, int, void *) __asm__("unk_ovlheader_800743E4");

void func_level_31_80083C44(void *inputOwner) {
register void *owner18 __asm__("$18")=inputOwner;
    /* Original frame0x38 and all ten dispatch entries are retained.
     * Original branch83F44 enters83F74 after the zero argument assignment;
     * branch83F60 enters83F70 before it. These distinct entries are explicit.
     * The zero producer uses the architectural zero register, not a predicate
     * known to be zero. Separate callback sites and saved helper returns keep
     * their original register widths, order, delay slots and control targets.
     * Empty constraints emit no instructions or opcode patches.
     * Units/fixed-point domains, cadence, helper meanings and synchronized
     * runtime chains remain unresolved. Machine identity only. */
    unsigned char *privatePosition;
    register int argument5 __asm__("$5");
    short privateHalfword;
    int privateArgument;
    register int randomValue16 __asm__("$16");
    register int distance16 __asm__("$16");
    register int helperResult16 __asm__("$16");
    register int distance17 __asm__("$17");
    register int callbackResult2 __asm__("$2");
    register int predicate2 __asm__("$2");
    register int rawResult2 __asm__("$2");
    register void *callOwner4 __asm__("$4");
    register int callArg5 __asm__("$5");
    register int callArg6 __asm__("$6");
    register int callArg7 __asm__("$7");
    int heightDifference;
    int damageFlags;
    int heightDelta;
    register int interactionFlag16 __asm__("$16");
    int conditionWord;
    unsigned char initialState;
    register int stateByte3 __asm__("$3");
    unsigned char dispatchState;
    register void * ownerPrivate19 __asm__("$19");
    register void *argument4 __asm__("$4");

    ownerPrivate19 = Level31_83C44Field(owner18, void **, 0);
    Level31_83C44_func_800359A4(ownerPrivate19 + 0x3A, 2);
    damageFlags = Level31_83C44Field(owner18, int *, 0x18);
    interactionFlag16 = 0;
    if (damageFlags != 0) {
        initialState = Level31_83C44Field(owner18, unsigned char *, 0x48);
        if (initialState != 8) {
            privateArgument = ownerPrivate19 + 0x28;
            if (damageFlags & 0xA0000) {
                if (Level31_83C44_unk_ovlheader_80074350(owner18, privateArgument, 5) != 0) {
                    Level31_83C44_func_80036A68(owner18, 1, 0, 0);
                    Level31_83C44_func_80038F14(owner18, ownerPrivate19 + 0x3C, 3, 7);
                    Level31_83C44Field(owner18, unsigned char *, 0x48) = 8U;
                }
                goto clearDamageAndDispatch;
            }
            callArg6=5;
            if (damageFlags & 0x10000) {
                Level31_83C44_unk_ovlheader_80074348(owner18,privateArgument,callArg6,0x1C);
                goto clearDamageAndDispatch;
            }
            if (damageFlags & 0x10000000) {
                if (initialState == 5) {
                    Level31_83C44Field(ownerPrivate19, short *, 0x2C) = 0;
                    goto clearDamageAndDispatch;
                }
                interactionFlag16 = 1;
                __asm__("" : "=r"(callArg6):"0"(callArg6):"$4");
                callOwner4=owner18;
                if (Level31_83C44_unk_ovlheader_80074354(callOwner4,privateArgument,callArg6) != 0) {
                    Level31_83C44_func_8003BB10(owner18, 3, 1);
                    Level31_83C44_func_80036A68(owner18, 0, 0, 0);
                    Level31_83C44_func_8003BA00(owner18);
                    goto call55B18;
                }
                if (Level31_83C44Field(ownerPrivate19, int *, 0x24) == 0) {
                    Level31_83C44Field(ownerPrivate19, int *, 0x24) = 0xA;
                    Level31_83C44Field(owner18, unsigned char *, 0x48) = 7U;
                    Level31_83C44_func_80034F40(owner18, 4);
                }
                goto clearDamageAndDispatch;
            }
            goto clearDamageAndDispatch;
        }
    }
clearDamageAndDispatch:
    Level31_83C44Field(owner18, int *, 0x18) = 0;
    if (interactionFlag16 == 0) {
        stateByte3 = Level31_83C44Field(owner18, unsigned char *, 0x48);
        __asm__("" : "=r"(stateByte3):"0"(stateByte3));
        if (((unsigned int) (stateByte3 - 5) >= 2U) && ((stateByte3 & 0xFF) != 8) && (Level31_83C44Field(owner18, unsigned char *, 0x57) != 0)) {
            Level31_83C44_unk_ovlheader_80074358(owner18);
        }
    }
    dispatchState = Level31_83C44Field(owner18, unsigned char *, 0x48);
    switch (dispatchState) {
    case 8:
        if (Level31_83C44_func_80035194(owner18, ownerPrivate19 + 0x3C) == 0x100) {
            Level31_83C44_func_80055D24(owner18, 4);
            Level31_83C44_func_8003BA00(owner18);
            Level31_83C44_func_800369B8(owner18, 0x30);
call55B18:
            Level31_83C44_func_80055B18(owner18);
            return;
        }
    default:
        return;
    case 5:
        Level31_83C44_unk_ovlheader_8007434C(owner18, ownerPrivate19 + 0x28);
        return;
    case 0:
        if (Level31_83C44_D_8006E044 != 9) {
            if (Level31_83C44_func_8004F334(owner18 + 0xC, &Level31_83C44_D_80070328) >= 0x2400) {
                argument4 = ownerPrivate19 + 0x24;
                goto updatePrivate24;
            }
            goto storeState1;
        }
updatePrivate24:
        argument4=ownerPrivate19+0x24;
        __asm__("" : "=r"(argument4):"0"(argument4));
        if (Level31_83C44_func_800359A4(argument4, 4) != 0) {
            privatePosition = ownerPrivate19 + 0x18;
            randomValue16 = Level31_83C44_rand() & 0xFF;
            __asm__("" : "=r"(randomValue16):"0"(randomValue16));
            randomValue16-=0x7F;
            Level31_83C44_unk_ovlheader_800743E4(privatePosition, randomValue16, (Level31_83C44_rand() & 0xFF) - 0x7F, ownerPrivate19);
            if (Level31_83C44_func_8004F334(owner18 + 0xC, privatePosition) >= 0x401) {
                Level31_83C44_func_80034F40(owner18, 2);
                Level31_83C44Field(owner18, unsigned char *, 0x48) = 2U;
                return;
            }
        }
        break;
    case 2:
        callArg6=0;
        if (Level31_83C44_D_8006E044 != 9) {
            __asm__("" : :"r"(callArg6):"$4");
            callOwner4=owner18+0xC;
            rawResult2=Level31_83C44_func_8004F334(callOwner4,&Level31_83C44_D_80070328,callArg6);
            predicate2=rawResult2<0x2400;
            callOwner4=owner18;

            if(!predicate2) goto resetArgument6;
            callArg5=0;
            goto call34F40;
        }
        goto call4E880And3585C;
resetArgument6:
        __asm__("" :  : : "$2");
        callArg6=0;
call4E880And3585C:
        if (Level31_83C44_func_8003585C(owner18, Level31_83C44_func_8004E880(Level31_83C44Field(ownerPrivate19, int *, 0x18) - Level31_83C44Field(owner18, int *, 0xC), Level31_83C44Field(ownerPrivate19, int *, 0x1C) - Level31_83C44Field(owner18, int *, 0x10), callArg6), 4, 2, 1, 0) != 0) {
            argument5 = 0x78;
        } else {argument5=0x3C;
        }
        Level31_83C44_func_80035DDC(owner18, argument5, 0x2BC, 0x2BC, 0x32);
        conditionWord = Level31_83C44_func_8004F334(owner18 + 0xC, ownerPrivate19 + 0x18) < 0x200;
        goto checkCondition;
        break;
    case 1:
        rawResult2=Level31_83C44_func_8004F334(owner18+0xC,&Level31_83C44_D_80070328);
        callOwner4=owner18;
        callArg5=4;
        callArg6=2;
        callArg7=1;
        __asm__("" : "=r"(callOwner4),"=r"(callArg5),"=r"(callArg6),"=r"(callArg7):"0"(callOwner4),"1"(callArg5),"2"(callArg6),"3"(callArg7),"r"(rawResult2):"$16");
        distance16=rawResult2;
        Level31_83C44_func_8003573C(callOwner4,callArg5,callArg6,callArg7);
        predicate2=distance16<0x2801;
        __asm__("" : :"r"(distance16),"r"(predicate2));
        if(predicate2) {
            predicate2=distance16<0x1800;
            __asm__("" : :"r"(distance16),"r"(predicate2));
            if ((predicate2) && (Level31_83C44Field(ownerPrivate19, short *, 0x3A) == 0) && (Level31_83C44_func_8004F264((int) (Level31_83C44_D_8006E040 << 0x10) >> 0x14, Level31_83C44_func_8004E880(Level31_83C44Field(owner18, int *, 0xC) - Level31_83C44_D_8006E020, Level31_83C44Field(owner18, int *, 0x10) - Level31_83C44_D_8006E024, 0)) < 0x1C) && (Level31_83C44Field(&Level31_83C44_D_80070328, int *, 0x240) == 0) && ((unsigned int) (Level31_83C44Field(&Level31_83C44_D_80070328, int *, 0x50) - 7) >= 2U)) {
                Level31_83C44_func_80034F40(owner18, 3);
                Level31_83C44Field(owner18, unsigned char *, 0x48) = 3U;
                return;
            }
        } else {
            goto storeState0;
        }
        break;
    case 3:
        rawResult2=Level31_83C44_func_80055E84(owner18);
        callOwner4=owner18+0xC;
        __asm__("" : "=r"(callOwner4):"0"(callOwner4),"r"(rawResult2):"$16");
        helperResult16=rawResult2;
        distance17=Level31_83C44_func_8004F334(callOwner4,&Level31_83C44_D_80070328);
        Level31_83C44_func_8003573C(owner18, 4, 2, 1);
        if (((unsigned int) (helperResult16 - 0xD) < 8U) && (distance17 < 0xF00)) {
            heightDelta = Level31_83C44Field(owner18, int *, 0x14) - Level31_83C44Field(owner18, short *, 0x38);
            heightDifference = heightDelta - Level31_83C44Field(&Level31_83C44_D_80070328, int *, 8);
            if (heightDifference >= 0) {
                if (heightDifference < 0x400) {
                    goto setSpyroFlags;
                }
                goto checkGlobalState;
            }
            if ((Level31_83C44Field(&Level31_83C44_D_80070328, int *, 8) - heightDelta) < 0x400) {
setSpyroFlags:
                if (Level31_83C44_D_8006E344 != 1) {
                    Level31_83C44Field(&Level31_83C44_D_80070328, int *, 0x24) = (int) (Level31_83C44Field(&Level31_83C44_D_80070328, int *, 0x24) | 0x16);
                    Level31_83C44Field(owner18, unsigned char *, 0x49) = 1U;
                } else {
                    goto resetOwnerState;
                }
            } else {
                goto checkGlobalState;
            }
        } else {
checkGlobalState:
            if (Level31_83C44_D_8006E344 == 1) {
resetOwnerState:
                Level31_83C44_func_80034F40(owner18, 0);
                Level31_83C44Field(owner18, unsigned char *, 0x48) = 0U;
            }
        }
        if (Level31_83C44_D_8006C770 != 0) {
            if ((Level31_83C44Field(owner18, unsigned char *, 0x49) != 0) || ((unsigned int) (Level31_83C44Field(&Level31_83C44_D_80070328, int *, 0x50) - 7) < 2U)) {
                Level31_83C44Field(ownerPrivate19, short *, 0x3A) = (short) Level31_83C44Field(ownerPrivate19, unsigned short *, 0x38);
                Level31_83C44_func_80034F40(owner18, 4);
                Level31_83C44Field(owner18, unsigned char *, 0x48) = 4U;
                Level31_83C44Field(owner18, unsigned char *, 0x49) = 0U;
                return;
            }
            if (distance17 >= 0x2801) {
                Level31_83C44Field(ownerPrivate19, short *, 0x3A) = (short) Level31_83C44Field(ownerPrivate19, unsigned short *, 0x38);
                Level31_83C44_func_80034F40(owner18, 0);
                Level31_83C44Field(owner18, unsigned char *, 0x48) = 0U;
                return;
            }
            predicate2=distance17<0x1801;
            __asm__("" : :"r"(distance17),"r"(predicate2));
            if(!predicate2) {
                Level31_83C44Field(ownerPrivate19, short *, 0x3A) = (short) Level31_83C44Field(ownerPrivate19, unsigned short *, 0x38);
                Level31_83C44_func_80034F40(owner18, 4);
                Level31_83C44Field(owner18, unsigned char *, 0x48) = 4U;
                return;
            }
            privateHalfword = (short) Level31_83C44Field(ownerPrivate19, unsigned short *, 0x38);
            if (privateHalfword != 0) {
                callOwner4=owner18;
                callArg5=0;
                __asm__("" : :"r"(callOwner4),"r"(callArg5),"r"(privateHalfword));
                Level31_83C44Field(ownerPrivate19,short*,0x3A)=privateHalfword;
                goto call34F40;
            }
        }
        break;
prepare34F40:
        callOwner4=owner18;
        callArg5=0;
call34F40:
        Level31_83C44_func_80034F40(callOwner4,callArg5);
storeState1:
            Level31_83C44Field(owner18, unsigned char *, 0x48) = 1U;
            return;
    case 4:
        Level31_83C44_func_8003573C(owner18, 4, 2, 1);
        if (Level31_83C44_D_8006C770 != 0) {
            Level31_83C44Field(ownerPrivate19, short *, 0x3A) = (short) Level31_83C44Field(ownerPrivate19, unsigned short *, 0x38);
            callbackResult2=Level31_83C44_func_80034F40(owner18,0);
            __asm__ volatile("" : :"r"(callbackResult2));
            Level31_83C44Field(owner18, unsigned char *, 0x48) = 0U;
            return;
        }
        break;
    case 7:
        if (Level31_83C44_func_800359A4(ownerPrivate19 + 0x24, 4) != 0) {
            conditionWord = Level31_83C44_D_8006C770;
checkCondition:
        if (conditionWord != 0) {
            Level31_83C44_func_80034F40(owner18, 0);
            Level31_83C44Field(ownerPrivate19, int *, 0x24) = (int) ((Level31_83C44_rand() & 0x3F) + 0x1E);
storeState0:
            Level31_83C44Field(owner18, unsigned char *, 0x48) = 0U;
        }
        }
        break;
    }
}
#undef Level31_83C44Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
typedef union{long long full;struct{
#if defined(__MIPSEB__)
int high;unsigned int low;
#else
unsigned int low;int high;
#endif
}words;}Actor1779Product;
/* SCUS-94467 USA Rev0:1779 original instructions+41 selectors=1820 owned words. AI generated,not human reviewed. Original frame0x68; SP18/30 are12-byte vectors; SP28/2C are original3645C outputs. Units and cadence are original; no engine conversion. All acceptance gates mandatory. */
#define Actor1779Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Actor1779Keep(v) __asm__("":"=r"(v):"0"(v))
int Actor1779_func_80018368() __asm__("func_80018368");
int Actor1779_func_80019194() __asm__("func_80019194");
int Actor1779_func_8001BA30() __asm__("func_8001BA30");
int Actor1779_func_80034F40() __asm__("func_80034F40");
int Actor1779_func_8003585C() __asm__("func_8003585C");
int Actor1779_func_800359A4() __asm__("func_800359A4");
int Actor1779_func_80035DDC() __asm__("func_80035DDC");
int Actor1779_func_8003613C() __asm__("func_8003613C");
int Actor1779_func_80036220() __asm__("func_80036220");
int Actor1779_func_8003645C() __asm__("func_8003645C");
int Actor1779_func_8003BABC() __asm__("func_8003BABC");
int Actor1779_func_8003BB10() __asm__("func_8003BB10");
int Actor1779_func_8004E880() __asm__("func_8004E880");
int Actor1779_func_8004EDE8() __asm__("func_8004EDE8");
int Actor1779_func_8004EF74() __asm__("func_8004EF74");
int Actor1779_func_8004F08C() __asm__("func_8004F08C");
int Actor1779_func_8004F110() __asm__("func_8004F110");
int Actor1779_func_8004F168() __asm__("func_8004F168");
int Actor1779_func_8004F178() __asm__("func_8004F178");
int Actor1779_func_8004F194() __asm__("func_8004F194");
int Actor1779_func_8004F1C8() __asm__("func_8004F1C8");
int Actor1779_func_8004F264() __asm__("func_8004F264");
int Actor1779_func_8004F334() __asm__("func_8004F334");
int Actor1779_func_80055B18() __asm__("func_80055B18");
int Actor1779_func_80055D24() __asm__("func_80055D24");
int Actor1779_rand() __asm__("rand");
extern int Actor1779_D_800658A0 __asm__("D_800658A0");
extern int Actor1779_D_80065920 __asm__("D_80065920");
extern int Actor1779_D_8006C54C __asm__("D_8006C54C");
extern int Actor1779_D_8006C550 __asm__("D_8006C550");
extern unsigned char Actor1779_D_8006C640 __asm__("D_8006C640");
extern int Actor1779_FrameWord __asm__("D_8006C640");
extern int Actor1779_D_8006C770 __asm__("D_8006C770");
extern int Actor1779_D_80070300 __asm__("D_80070300");
extern int Actor1779_D_80070328 __asm__("D_80070328");
extern int Actor1779_D_80071900 __asm__("D_80071900");
extern int Actor1779_D_80071914 __asm__("D_80071914");
extern int Actor1779_D_80071918 __asm__("D_80071918");
extern int Actor1779_D_80071930 __asm__("D_80071930");
extern int(*Actor1779SpawnMoby)() __asm__("SpawnMoby");
extern int(*Actor1779unk_ovlheader_80074348)() __asm__("unk_ovlheader_80074348");
extern int(*Actor1779unk_ovlheader_8007434C)() __asm__("unk_ovlheader_8007434C");
extern int(*Actor1779unk_ovlheader_80074350)() __asm__("unk_ovlheader_80074350");
/* Register suffixes retain original value phases; semantic actor identities
 * remain unclaimed. Empty asm observes complete initialized C values only.
 * Reserved SP24/SP3C declarations are never read. Complete 64-bit products
 * precede every high/low projection; no incoming saved values are consumed. */
void func_level_31_80084324(void* input) {
Actor1779Product completeProduct;
register int word2 __asm__("$2"),word3 __asm__("$3"),arg4 __asm__("$4"),arg5 __asm__("$5"),arg6 __asm__("$6"),arg7 __asm__("$7"),word8 __asm__("$8");
register int retained16 __asm__("$16"),retained17 __asm__("$17"),retained18 __asm__("$18"),owner19 __asm__("$19"),private20 __asm__("$20"),retained21 __asm__("$21"),retained22 __asm__("$22"),headingOrSentinel23 __asm__("$23");
struct{int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C;}originalFrame;

    int var_a1_2;

    int temp_v1_12;

    int temp_v1_27;

    int temp_v0_13;

    int temp_v0_15;

    int temp_v1_23;

    int temp_a0_3;

    int temp_v1_19;

    int temp_v1_21;

    int var_a0_4;

    int temp_a0_7;

    int temp_v0_11;

    int temp_v1_17;

    int temp_v1_18;

    int temp_v1_28;

    int temp_v1_2;

    int temp_v1_6;

    int var_v0_8;

    int temp_v0_20;

    int temp_v1;

    int temp_v1_11;

    int temp_v1_30;

    int temp_a0;

    int temp_a0_2;

    int temp_a0_4;

    int temp_v0;

    int temp_v0_14;

    int temp_v1_29;

    int temp_a0_6;

    int temp_v0_10;

    int temp_v0_21;

    int temp_v0_22;

    int temp_v0_23;

    int temp_v0_24;

    int temp_v0_3;

    int temp_v0_4;

    int temp_v0_5;

    int temp_v0_6;

    int temp_v0_7;

    int temp_v0_9;

    int temp_v1_13;

    int temp_v1_14;

    int temp_v1_25;

    int temp_v1_26;

    int temp_v1_5;

    owner19=(int)input;Actor1779Keep(owner19);
    private20 = Actor1779Field(owner19, int*, 0);
    headingOrSentinel23 = -1;
    if (Actor1779Field(owner19, unsigned char *, 0x57) == 0x50) {
        Actor1779Field(owner19, unsigned char *, 0x4C) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x4C);
        Actor1779Field(owner19, unsigned char *, 0x4A) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x4A);
        retained17 = owner19 + 0xC;
        Actor1779Field(owner19, unsigned char *, 0x4E) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x4E);
        Actor1779_func_8004F178(retained17, Actor1779Field(private20, int*, 0) + 0xC);
        Actor1779Field(owner19, int *, 0x14) = (int) (0x8000 - Actor1779Field(owner19, int *, 0x14));
        Actor1779Field(owner19, signed char *, 0x44) = (signed char) -(signed char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x44);
        word2=Actor1779Field(Actor1779Field(private20,int*,0),unsigned char*,69);Actor1779Keep(word2);word2=-word2;Actor1779Field(owner19,unsigned char*,69)=word2;
        word2=Actor1779Field(Actor1779Field(private20,int*,0),unsigned char*,70);Actor1779Field(owner19,unsigned char*,65)=0;Actor1779Field(owner19,unsigned char*,70)=word2;
        Actor1779Field(owner19, unsigned char *, 0x3C) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x3C);
        Actor1779Field(owner19, unsigned char *, 0x3D) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x3D);
        Actor1779Field(owner19, unsigned char *, 0x3E) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x3E);
        Actor1779Field(owner19, unsigned char *, 0x3F) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x3F);
        Actor1779Field(owner19, unsigned char *, 0x40) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0), unsigned char *, 0x40);
        word2=Actor1779Field(private20,int*,0);__asm__ volatile(""::"r"(word2):"$16");retained16=private20;
        private20=Actor1779Field(word2,int*,0);
        if (Actor1779Field(private20, int*, 0x18) != 0) {
            if (Actor1779Field(retained16, int*, 4) == 0) {
                temp_v0 = Actor1779SpawnMoby(0x79, owner19);
                Actor1779Field(retained16, int*, 4) = temp_v0;
                if (temp_v0 != 0) {
                    goto block_5;
                }
            } else {
block_5:
                Actor1779Field(Actor1779Field(retained16, int*, 4), int *, 8) = 0;
                Actor1779Field(Actor1779Field(retained16,int*,4),unsigned char*,71)=253;
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x4C) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x4C);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x4A) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x4A);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x4E) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x4E);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x4F) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x4F);
                Actor1779Field(Actor1779Field(retained16, int*, 4), signed char *, 0x57) = 0x50;
                Actor1779_func_8004F178((int *) (Actor1779Field(retained16, int*, 4) + 0xC), retained17);
                temp_a0 = Actor1779Field(retained16, int*, 4);
                Actor1779Field(temp_a0, int *, 0x14) = (int) (Actor1779Field(temp_a0, int *, 0x14) + Actor1779Field(Actor1779Field(retained16, int*, 0), short *, 0x38));
                Actor1779Field(Actor1779Field(retained16, int*, 4), signed char *, 0x44) = (signed char) -(signed char) (unsigned char) Actor1779Field(owner19, signed char *, 0x44);
                Actor1779Field(Actor1779Field(retained16, int*, 4), signed char *, 0x45) = (signed char) -(signed char) (unsigned char) Actor1779Field(owner19, signed char *, 0x45);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x46) = (unsigned char) Actor1779Field(owner19, unsigned char *, 0x46);
                Actor1779Field(Actor1779Field(retained16, int*, 4), signed char *, 0x41) = 0;
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x3C) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x3C);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x3D) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x3D);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x3E) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x3E);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x3F) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x3F);
                Actor1779Field(Actor1779Field(retained16, int*, 4), unsigned char *, 0x40) = (unsigned char) Actor1779Field(Actor1779Field(private20, int*, 0x18), unsigned char *, 0x40);
            }
        } else {
            temp_a0_2 = Actor1779Field(retained16, int*, 4);
            if (temp_a0_2 != 0) {
                Actor1779_func_80055B18(temp_a0_2);
                Actor1779Field(retained16, int*, 4) = 0;
            }
        }
    } else if (Actor1779Field(private20, int*, 0x44) != 0) {
        temp_v1 = Actor1779Field(owner19, unsigned char *, 0x48);
        switch (temp_v1) {                          
        case 0:                                     
            Actor1779_func_80034F40(owner19, 3);
            Actor1779Field(owner19, unsigned char *, 0x48) = 0x14U;
            Actor1779Field(owner19, signed char *, 0x44) = Actor1779_rand();
            Actor1779Field(owner19, signed char *, 0x45) = Actor1779_rand();
            Actor1779Field(owner19, unsigned char *, 0x46) = Actor1779_rand();
            Actor1779Field(private20, int*, 0) = (void *) (Actor1779_rand() & 0x7F);
            Actor1779Field(private20, int*, 4) = (int*) (Actor1779_rand() & 0x7F);
            Actor1779Field(private20, int *, 8) = (int) (Actor1779_rand() & 0x7F);
            Actor1779Field(owner19, int *, 0x1C) = (int) (Actor1779Field(owner19, int *, 0x1C) & 0x7FFFFFFF);
            return;
        case 20:
            word2=Actor1779Field(owner19,unsigned char*,68);word3=Actor1779Field(owner19,unsigned char*,70);word2+=3;Actor1779Field(owner19,unsigned char*,68)=word2;
            word2=Actor1779Field(owner19,unsigned char*,69);word3+=5;Actor1779Field(owner19,unsigned char*,70)=word3;word2+=4;Actor1779Field(owner19,unsigned char*,69)=word2;
            Actor1779_func_8004F178(&originalFrame.sp18,Actor1779Field(Actor1779Field(private20,int*,68),int*,12));
            arg4=(int)&originalFrame.sp18;arg5=arg4;arg6=Actor1779_D_8006C640;retained16=owner19+12;arg6<<=1;
            word3=Actor1779Field((int)&Actor1779_D_800658A0,unsigned short*,arg6);word2=originalFrame.sp18;word3<<=16;Actor1779Keep(word3);word3>>=20;word2+=word3;originalFrame.sp18=word2;
            word3=Actor1779Field((int)&Actor1779_D_80065920,unsigned short*,arg6);arg6=retained16;word2=originalFrame.sp1C;word3<<=16;Actor1779Keep(word3);word3>>=20;word2+=word3;originalFrame.sp1C=word2;
            Actor1779_func_8004F1C8(arg4,arg5,arg6);
            Actor1779_func_8004F110(&originalFrame.sp18, 5);
            Actor1779_func_8004F194(private20, private20, &originalFrame.sp18);
            Actor1779_func_8004F178(&originalFrame.sp18, retained16);
            Actor1779_func_8004F194(retained16, retained16, private20);
            retained17=Actor1779_func_8004EDE8(private20,1);
            if(retained17>=301){
                Actor1779_func_8004F08C(private20,retained17,300);
            }
            Actor1779_D_80071930 = 0;
            if (Actor1779Field(((Actor1779Field(private20, int *, 0x50) * 0x58) + Actor1779_D_8006C550), unsigned char *, 0x49) != 0) {
                temp_a0_3 = Actor1779Field(private20, int*, 0x2C);
                temp_v1_2 = Actor1779Field(temp_a0_3,int*,0);
                if ((temp_v1_2 < 5) && (Actor1779Field(Actor1779Field(private20, int*, 0x30),int*,0) == 0)) {
                    Actor1779Field(temp_a0_3,int*,0) = temp_v1_2 + 1;
                    Actor1779Field(Actor1779Field(private20, int*, 0x30),int*,0) = 0x3C;
                    Actor1779Field(owner19, unsigned char *, 0x48) = 0x15U;
                    return;
                }
            }
            break;
        case 21:                                    
            if (Actor1779_func_800359A4(Actor1779Field(private20, int*, 0x30), 4) != 0) {
                Actor1779Field(owner19, unsigned char *, 0x48) = 0x16U;
            }
            
        case 22:
            word3=Actor1779Field(owner19,unsigned char*,68);word2=(unsigned int)word3<9U;
            if(word2)word2=8;else word2=word3-8;
            Actor1779Field(owner19,unsigned char*,68)=word2;__asm__ volatile("":::"memory");
            word3=Actor1779Field(owner19,unsigned char*,69);word2=(unsigned int)word3<9U;
            if(word2)word2=8;else word2=word3-8;
            Actor1779Field(owner19,unsigned char*,69)=word2;
            __asm__ volatile(""::"m"(Actor1779Field(owner19,unsigned char*,69)):"memory");arg4=(int)&originalFrame.sp18;__asm__("":"=r"(arg4):"0"(arg4):"$16");retained16=owner19+12;
            temp_v0_3 = Actor1779Field(private20, int*, 0x48);
            Actor1779_func_8004F1C8(arg4, Actor1779Field(temp_v0_3, int *, 0xC) + (Actor1779Field(temp_v0_3, short *, 2) * 0x10), retained16);
            retained17 = Actor1779_func_8004EDE8(&originalFrame.sp18, 1);
            if (retained17 < 0x15E) {
                temp_v1_5 = Actor1779Field(private20, int*, 0x48);
                Actor1779Field(temp_v1_5, short *, 2) = (short) ((unsigned short) Actor1779Field(temp_v1_5, short *, 2) + 1);
                temp_v0_4 = Actor1779Field(private20, int*, 0x48);
                Actor1779_func_8004F1C8(&originalFrame.sp18, Actor1779Field(temp_v0_4, int *, 0xC) + (Actor1779Field(temp_v0_4, short *, 2) * 0x10), retained16);
                retained17 = Actor1779_func_8004EDE8(&originalFrame.sp18, 1);
            }
            Actor1779_func_8004F08C(&originalFrame.sp18, retained17, 0x12C);
            Actor1779_func_8004F194(retained16, retained16, &originalFrame.sp18);
            temp_v0_5 = Actor1779Field(private20, int*, 0x48);
            if (Actor1779Field(temp_v0_5, short *, 2) == (Actor1779Field(temp_v0_5, short *, 0) - 1)) {
                Actor1779_func_8004F178(private20, &originalFrame.sp18);
                Actor1779Field(private20, int*, 0x44) = 0;
                Actor1779Field(owner19, signed char *, 0x44) = 0;
                Actor1779Field(owner19, signed char *, 0x45) = 0;
                if (Actor1779Field(owner19, unsigned char *, 0x48) == 0x15) {
                    Actor1779Field(Actor1779Field(private20, int*, 0x30),int*,0) = 0;
                }
                Actor1779_func_80055D24(owner19, 2);
                Actor1779_func_80034F40(owner19, 2);
                Actor1779Field(private20, signed char *, 0xD) = 0xA;
                Actor1779_func_8003BABC(owner19, 0, 0);
                Actor1779Field(owner19, unsigned char *, 0x48) = 0xAU;
                return;
            }
            break;
        }
    } else {
        retained22 = Actor1779_func_8004EDE8(private20, 1);
        if (Actor1779Field(owner19, unsigned char *, 0x48) != 7) {
            temp_v1_6 = Actor1779Field(owner19, int *, 0x18);
            if (temp_v1_6 & 0x20000) {
                if (Actor1779unk_ovlheader_80074350(owner19, private20 + 0x18, 0x28) != 0) {
                    Actor1779Field(owner19, signed char *, 0x54) = 0;
                    Actor1779Field(owner19, signed char *, 0x55) = 0;
                    Actor1779Field(owner19, signed char *, 0x56) = 0;
                    Actor1779Field(owner19, unsigned char *, 0x57) = 0U;
                }
                if (Actor1779Field(private20, unsigned char *, 0xC) == 4) {
                    originalFrame.sp18 = (int) (Actor1779Field((int)&Actor1779_D_80065920,short*,(Actor1779_func_8004E880(Actor1779Field(owner19, int *, 0xC) - Actor1779Field((int)&Actor1779_D_80070328, int *, 0), Actor1779Field(owner19, int *, 0x10) - Actor1779Field((int)&Actor1779_D_80070328, int *, 4), 0) * 2)) * 0xF) >> 0xA;
                    word2=Actor1779_func_8004E880(Actor1779Field(owner19, int *, 0xC) - Actor1779Field((int)&Actor1779_D_80070328, int *, 0), Actor1779Field(owner19, int *, 0x10) - Actor1779Field((int)&Actor1779_D_80070328, int *, 4), 0);arg4=private20;arg5=private20;word2*=2;
                    word3=Actor1779Field((int)&Actor1779_D_800658A0,short*,word2);arg6=(int)&originalFrame.sp18;originalFrame.sp20=0;
                    word2=((word3<<4)-word3)>>10;goto block_64;
                }
            } else if (temp_v1_6 & 0x10000) {
                Actor1779unk_ovlheader_80074348(owner19, private20 + 0x18, 0x28, 0x1C);
                Actor1779Field(private20, short *, 0x1C) = 0x258;
                Actor1779Field(owner19, signed char *, 0x54) = 0;
                Actor1779Field(owner19, signed char *, 0x55) = 0;
                Actor1779Field(owner19, signed char *, 0x56) = 0;
                Actor1779Field(owner19, unsigned char *, 0x57) = 0U;
                if (Actor1779Field(owner19, unsigned char *, 0x49) == 0) {
                    Actor1779Field(owner19, unsigned char *, 0x49) = 1U;
                }
                Actor1779Field(owner19, unsigned char *, 0x41) = 0U;
                word3=Actor1779Field(private20,unsigned char*,12);__asm__("":"=r"(word3):"0"(word3):"$2");word2=4;arg4=private20;
                if(word3==word2){
                    arg6=Actor1779Field((int)&Actor1779_D_80070328,unsigned char*,14);Actor1779Keep(arg6);arg6<<=1;
                    word3=Actor1779Field((int)&Actor1779_D_80065920,short*,arg6);arg5=private20;
                    word2=(word3*25)>>11;originalFrame.sp18=word2;
                    word3=Actor1779Field((int)&Actor1779_D_800658A0,short*,arg6);arg6=(int)&originalFrame.sp18;originalFrame.sp20=0;
                    word2=(word3*25)>>11;goto block_64;
                }
            } else if (temp_v1_6 & 0x10000000) {
                Actor1779unk_ovlheader_80074348(owner19, private20 + 0x18, 0x28, 0x1C);
                if (Actor1779Field(owner19, unsigned char *, 0x49) == 0) {
                    Actor1779Field(owner19, unsigned char *, 0x49) = 1U;
                }
                Actor1779Field(owner19, unsigned char *, 0x41) = 0U;
                if (Actor1779Field(private20, unsigned char *, 0xC) == 4) {
                    word3=Actor1779Field(private20,int*,52);retained17=owner19+12;
                    if(word3){
                        arg4=retained17;word2=Actor1779Field(private20,int*,60);retained16=Actor1779_D_8006C550;
                        arg5=word2*88;arg5=retained16+arg5;arg5+=12;word2=word3*88;retained16+=word2;
                        word2=Actor1779_func_8004F334(arg4,arg5);
                        arg4=retained17;arg5=Actor1779Field(private20,int*,56);retained21=word2;word3=arg5*88;
                        arg5=Actor1779_D_8006C550;arg5+=word3;arg5+=12;
                        word2=Actor1779_func_8004F334(arg4,arg5);arg6=0;__asm__ volatile(""::"r"(arg6):"memory");
                        arg4=Actor1779Field(retained16,int*,12);arg5=Actor1779Field(retained16,int*,16);retained16=word2;
                        arg7=Actor1779Field(owner19,int*,12);word3=Actor1779Field(owner19,int*,16);
                        word2=Actor1779_func_8004E880(arg7-arg4,word3-arg5,arg6,arg7);retained17=word2;
                        temp_v0_6 = (Actor1779Field(private20, int *, 0x3C) * 0x58) + Actor1779_D_8006C550;
                        retained18 = Actor1779_func_8003613C(retained17, Actor1779_func_8004E880(Actor1779Field(temp_v0_6, int *, 0xC) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_6, int *, 0x10) - Actor1779Field(owner19, int *, 0x10), 0));
                        if (retained16 < 0x2000) {
                            temp_v0_7 = (Actor1779Field(private20, int *, 0x38) * 0x58) + Actor1779_D_8006C550;
                            word3=Actor1779_func_8003613C(retained17,Actor1779_func_8004E880(Actor1779Field(temp_v0_7,int*,12)-Actor1779Field(owner19,int*,12),Actor1779Field(temp_v0_7,int*,16)-Actor1779Field(owner19,int*,16),0));
                            Actor1779Keep(word3);word2=word3;
                            if(word3<0)word2=-word2;
                            if(word2<25 ? (word2=retained18>>2,1) : (word2=retained18>>2,0)){
                                if(word3<0){word2=(word3+32)>>1;goto block_61;}
                                word2=(32-word3)>>1;retained17-=word2;goto block_62;
                            }
                            goto block_61;
                        }
                        retained16=50;
                        if(retained21<8192){
                            retained17+=retained18;Actor1779_func_8004F110(private20,1);retained17&=255;
                        }else{
                            word2=retained18>>1;
block_61:
                            retained17+=word2;
block_62:
                            retained16=25;retained17&=255;
                        }
                        __asm__ volatile(""::"r"(retained18),"r"(retained21));
                        word3=retained17*2;word2=Actor1779Field((int)&Actor1779_D_80065920,short*,word3);
                        completeProduct.full=(long long)word2*(long long)retained16;__asm__ volatile("":"=x"(completeProduct.full):"0"(completeProduct.full));
                        word8=completeProduct.words.low;Actor1779Keep(word8);word2=word8>>12;originalFrame.sp18=word2;
                        word2=Actor1779Field((int)&Actor1779_D_800658A0,short*,word3);
                        completeProduct.full=(long long)word2*(long long)retained16;__asm__ volatile("":"=x"(completeProduct.full):"0"(completeProduct.full));
                        arg4=private20;arg5=private20;arg6=(int)&originalFrame.sp18;originalFrame.sp20=0;
                        __asm__ volatile("":"=x"(completeProduct.full):"0"(completeProduct.full),"m"(originalFrame.sp20));
                        word8=completeProduct.words.low;Actor1779Keep(word8);word2=word8>>12;
block_64:
                        originalFrame.sp1C=word2;Actor1779_func_8004F194(arg4,arg5,arg6);
                    }
                }
            }
        }
        Actor1779Field(owner19, int *, 0x18) = 0;
        if (Actor1779Field(owner19, unsigned char *, 0x48) != 7) {
            Actor1779_func_8004F08C(private20, 0x40, 0x3F);
        }
        retained17=Actor1779_func_8004EDE8(private20,0);
        word3=Actor1779Field(private20,int*,64);
        if(word3){word2=Actor1779Field(word3,int*,20)+4096;Actor1779Field(word3,int*,20)=word2;}
        Actor1779_func_800359A4(private20 + 0x54, 4);
        temp_v1_11 = Actor1779Field(owner19, unsigned char *, 0x48);
        switch (temp_v1_11) {                       
        case 40:                                    
            if ((Actor1779Field(private20, unsigned char *, 0xC) == 4) && (Actor1779Field(private20, int*, 0x18) != 0) && (Actor1779_func_8004F334(owner19 + 0xC, (int)&Actor1779_D_80070328) < 0x600) && (Actor1779_func_8004F264(Actor1779Field((int)&Actor1779_D_80070328, unsigned char *, 0xE), Actor1779_func_8004E880(Actor1779Field(owner19, int *, 0xC) - Actor1779Field((int)&Actor1779_D_80070328, int *, 0), Actor1779Field(owner19, int *, 0x10) - Actor1779Field((int)&Actor1779_D_80070328, int *, 4), 0)) < 0x30)) {
                originalFrame.sp18 = (int) (Actor1779Field((int)&Actor1779_D_80065920,short*,(Actor1779_func_8004E880(Actor1779Field(owner19, int *, 0xC) - Actor1779Field((int)&Actor1779_D_80070328, int *, 0), Actor1779Field(owner19, int *, 0x10) - Actor1779Field((int)&Actor1779_D_80070328, int *, 4), 0) * 2)) * 0xF) >> 0xB;
                temp_v1_12 = Actor1779Field((int)&Actor1779_D_800658A0,short*,(Actor1779_func_8004E880(Actor1779Field(owner19, int *, 0xC) - Actor1779Field((int)&Actor1779_D_80070328, int *, 0), Actor1779Field(owner19, int *, 0x10) - Actor1779Field((int)&Actor1779_D_80070328, int *, 4), 0) * 2));
                originalFrame.sp20 = 0;
                originalFrame.sp1C = (int) (temp_v1_12 * 0xF) >> 0xB;
                Actor1779_func_8004F194(private20, private20, &originalFrame.sp18);
            }
            if ((Actor1779Field(private20, int *, 0x54) == 0) && (Actor1779Field(private20, int*, 0x18) != 0) && (retained22 < Actor1779_func_8004EDE8(private20, 1))) {
                Actor1779Field(private20, int *, 0x54) = 0x2D;
                Actor1779_func_8003BABC(Actor1779Field(private20, int*, 0x18), 2, 0);
            }
            if (Actor1779Field(private20, unsigned char *, 0xC) != 4) {
                if ((Actor1779Field(private20, unsigned char *, 0x1E) != 9) && (Actor1779Field(private20, int*, 0x18) != 0)) {
                    if (retained17 < 0x20) {
                        Actor1779Field(private20, short *, 0x1C) = 0;
                        Actor1779_func_8004F168(private20);
                        Actor1779Field(private20, unsigned char *, 0x1E) = 9U;
                    } else {
                        Actor1779Field(private20, unsigned char *, 0x1E) = 9U;
                        Actor1779_func_8004F08C(private20, 0x10, 0xF);
                        Actor1779Field(private20, short *, 0x1C) = 0x12C;
                    }
                }
            }
            Actor1779unk_ovlheader_8007434C(owner19, private20 + 0x18);
            Actor1779Field(owner19, signed char *, 0x54) = 0;
            Actor1779Field(owner19, signed char *, 0x55) = 0;
            Actor1779Field(owner19, signed char *, 0x56) = 0;
            Actor1779Field(owner19, unsigned char *, 0x57) = 0U;
            if (Actor1779Field(private20, short *, 0x1C) == 0) {
                Actor1779Field(owner19, unsigned char *, 0x41) = (unsigned char) Actor1779Field(private20, unsigned char *, 0x1F);
            }
            if (Actor1779Field(owner19, unsigned char *, 0x48) != 0x28) {
                Actor1779Field(private20, unsigned char *, 0x1E) = 0x28U;
            }
            break;
        case 10:                                    
            arg4=private20+13;
            if (Actor1779Field(private20, int*, 0x58) == 0) {
                Actor1779Field(private20, int*, 0x58) = Actor1779SpawnMoby(0xEF, owner19);
                __asm__ volatile("":"=r"(private20):"0"(private20));arg4=private20+13;
            }
            if (Actor1779_func_800359A4(arg4,1) != 0) {
                Actor1779Field(owner19, unsigned char *, 0x48) = 7U;
            }
            temp_v1_13 = Actor1779Field(private20, int*, 0x10);
            temp_v0_9 = (Actor1779Field(temp_v1_13, short *, 2) * 0x10) + Actor1779Field(temp_v1_13, int *, 0xC);
            Actor1779_func_8003585C(owner19, Actor1779_func_8004E880(Actor1779Field(temp_v0_9, int *, 0) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_9, int *, 4) - Actor1779Field(owner19, int *, 0x10), 0), 4, 0, 0, 0);
            Actor1779Field(private20, int *, 8) = (int) (Actor1779Field(private20, int *, 8) - 0xA);
            break;
        case 7:                                     
            temp_v1_14 = Actor1779Field(private20, int*, 0x10);
            temp_v0_10 = (Actor1779Field(temp_v1_14, short *, 2) * 0x10) + Actor1779Field(temp_v1_14, int *, 0xC);
            Actor1779_func_8003585C(owner19, Actor1779_func_8004E880(Actor1779Field(temp_v0_10, int *, 0) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_10, int *, 4) - Actor1779Field(owner19, int *, 0x10), 0), 4, 0, 0, 0);
            temp_v0_11 = Actor1779Field(private20, int *, 8) - 0xA;
            Actor1779Field(private20, int *, 8) = temp_v0_11;
            if (temp_v0_11 < -0x12C) {
                Actor1779Field(private20, int *, 8) = -0x12C;
            }
            Actor1779_D_80071930 = 0;
            word2=Actor1779Field(owner19,short*,56);word3=Actor1779Field(owner19,int*,20);retained16=word2+16384;word2+=16448;
            if(word2>=word3){
                word2=Actor1779Field(private20,int*,8);if(word2<0)word2=(int)(0U-(unsigned int)word2);
                if(word2<16 && Actor1779Field(owner19,unsigned char*,73)!=2){
                    Actor1779_func_8003645C(owner19+12,Actor1779Field(private20,int*,16),&originalFrame.sp28);
                    arg4=owner19;word3=Actor1779Field(private20,int*,16);word2=originalFrame.sp28;arg5=2;Actor1779Field(word3,short*,2)=word2;
                    word2=180;Actor1779Field(owner19,unsigned char*,73)=0;Actor1779Field(owner19,int*,20)=retained16;goto block_137;
                }
            }
            break;
        case 9:                                     
            temp_v0_13 = Actor1779Field(private20, int*, 0x40);
            if (temp_v0_13 != 0) {
                word2=Actor1779_func_8003585C(owner19, Actor1779_func_8004E880(Actor1779Field(temp_v0_13, int *, 0xC) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_13, int *, 0x10) - Actor1779Field(owner19, int *, 0x10), 0), 6, 0, 0, 0);
                arg4=owner19+12;arg5=Actor1779Field(private20,int*,64);retained16=word2;
                word2=Actor1779_func_8004F334(arg4,arg5+12);
                if(word2<640){
                    temp_v0_14 = Actor1779Field(private20, int*, 0x58);
                    if (temp_v0_14 != 0) {
                        temp_a0_4 = Actor1779Field(Actor1779Field(temp_v0_14,int*,0), int*, 4);
                        if (temp_a0_4 != 0) {
                            Actor1779_func_80055B18(temp_a0_4);
                        }
                        Actor1779_func_80055B18(Actor1779Field(private20, int*, 0x58));
                        Actor1779Field(private20, int*, 0x58) = 0;
                    }
                    Actor1779Field(owner19, unsigned char *, 0x48) = 4U;
                    Actor1779_func_80034F40(owner19, 4);
                    Actor1779_func_80035DDC(owner19, 0, 0x177, 0x200, 0x22);
                } else {
                    Actor1779_func_80034F40(owner19, 0);
                    if (retained16 != 0) {
                        Actor1779_func_80035DDC(owner19, 0x32, 0x190, 0x200, 0x22);
                    }
                }
            }
            break;
        case 4:                                     
            if ((Actor1779_FrameWord != 0) && (Actor1779_D_8006C54C == 0)) {
                Actor1779Field((int)&Actor1779_D_80070300, signed char *, 0) = 0;
                Actor1779Field((int)&Actor1779_D_80070300, signed char *, 1) = 0;
                Actor1779Field((int)&Actor1779_D_80070300, signed char *, 2) = 0;
                Actor1779Field((int)&Actor1779_D_80070300, signed char *, 3) = 0;
                Actor1779Field((int)&Actor1779_D_80070300, signed char *, 4) = 0;
            }
            if (Actor1779Field(private20, int*, 0x40) != 0) {
                if (Actor1779_D_8006C770 != 0) {
                    Actor1779_func_80034F40(owner19, 5);
                }
                temp_v0_15 = Actor1779Field(private20, int*, 0x40);
                Actor1779_func_8003585C(owner19, Actor1779_func_8004E880(Actor1779Field(temp_v0_15, int *, 0xC) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_15, int *, 0x10) - Actor1779Field(owner19, int *, 0x10), 0), 6, 0, 0, 0);
                Actor1779_func_80035DDC(owner19, 0, 0x177, 0x200, 0x22);
                if (Actor1779_func_800359A4(private20 + 0x4C, 4) != 0) {
                    word2=Actor1779_rand();word2=(word2&511)+480;Actor1779Field(private20,int*,76)=word2;
                    word2=Actor1779_rand();word3=0x55555556;word2&=511;Actor1779Keep(word2);
                    completeProduct.full=(long long)word2*(long long)word3;__asm__ volatile("":"=x"(completeProduct.full):"0"(completeProduct.full));
                    arg4=owner19;arg6=0;arg5=word2>>31;__asm__ volatile("":"=x"(completeProduct.full):"0"(completeProduct.full),"r"(arg5));
                    word8=completeProduct.words.high;Actor1779Keep(word8);arg5=word8-arg5;word3=arg5*2;word3+=arg5;word2-=word3;
                    Actor1779_func_8003BABC(arg4,word2+1,arg6);
                }
                if (Actor1779_func_8004F334(owner19 + 0xC, Actor1779Field(private20, int*, 0x40) + 0xC) >= 0x301) {
                    Actor1779Field(owner19, unsigned char *, 0x48) = 6U;
                    Actor1779_func_80034F40(owner19,6);
                }
            }
            break;
        case 6:                                     
            if (Actor1779_D_8006C770 != 0) {
                Actor1779Field(private20, signed char *, 0xD) = 0;
                Actor1779_func_80034F40(owner19, 0);
                Actor1779Field(owner19, unsigned char *, 0x48) = 9U;
            }
            break;
        case 0:                                     
            retained16 = owner19 + 0xC;
            if (Actor1779Field(private20, unsigned char *, 0xC) == 4) {
                Actor1779Field(owner19, int *, 0x14) = (int) (Actor1779Field(owner19, short *, 0x38) + 0x4000);
            }
            arg5=Actor1779_func_8001BA30(retained16,2048,0,0,0,owner19);word2=1;
            if(arg5){
                word3=Actor1779Field(owner19,int*,12);Actor1779Field(owner19,unsigned char*,73)=word2;
                arg4=Actor1779Field(arg5,int*,12);word2=Actor1779Field(owner19,int*,16);arg5=Actor1779Field(arg5,int*,16);arg6=0;
                goto actor1779TargetHeading;
            }
            word2=Actor1779Field(owner19,unsigned char*,73);arg4=retained16;
            if(word2){
                Actor1779_func_8003645C(arg4,Actor1779Field(private20,int*,16),&originalFrame.sp2C);
                word3=Actor1779Field(private20,int*,16);word2=originalFrame.sp2C;Actor1779Keep(word2);Actor1779Field(word3,short*,2)=word2;Actor1779Field(owner19,unsigned char*,73)=0;
            }
            arg6=0;word3=Actor1779Field(private20,int*,16);arg4=Actor1779Field(owner19,int*,12);arg5=Actor1779Field(owner19,int*,16);
            word2=Actor1779Field(word3,short*,2);word3=Actor1779Field(word3,int*,12);word2<<=4;word2+=word3;word3=Actor1779Field(word2,int*,0);word2=Actor1779Field(word2,int*,4);
actor1779TargetHeading:
            headingOrSentinel23=Actor1779_func_8004E880(word3-arg4,word2-arg5,arg6);
            Actor1779_func_8003585C(owner19, headingOrSentinel23, 3, 0, 0, 0);
            word2=Actor1779Field(owner19,unsigned char*,70);word2*=2;
            word2=Actor1779Field((int)&Actor1779_D_80065920,short*,word2);__asm__("":"=r"(word2):"0"(word2):"$4");arg4=private20;word2>>=10;originalFrame.sp18=word2;
            word2=Actor1779Field(owner19,unsigned char*,70);__asm__("":"=r"(word2):"0"(word2):"$5");arg5=private20;word2*=2;
            word2=Actor1779Field((int)&Actor1779_D_800658A0,short*,word2);__asm__("":"=r"(word2):"0"(word2):"$6");arg6=(int)&originalFrame.sp18;originalFrame.sp20=0;
            __asm__ volatile("":"=r"(word2):"0"(word2),"m"(originalFrame.sp20));word2>>=10;originalFrame.sp1C=word2;
            Actor1779_func_8004F194(arg4,arg5,arg6);
            if(retained17>=151)goto actor1779StartMotion;
            if(retained17<61)goto actor1779StatesDone;
            word2=Actor1779_func_8004E880(Actor1779Field(private20,int*,0),Actor1779Field(private20,int*,4),0);
            arg6=0;__asm__ volatile("":"=r"(word2):"0"(word2),"r"(arg6):"memory");retained16=word2;arg4=Actor1779Field(private20,int*,16);arg5=Actor1779Field(owner19,int*,16);
            word3=Actor1779Field(arg4,short*,2);arg4=Actor1779Field(arg4,int*,12);word3<<=4;word3+=arg4;
            arg7=Actor1779Field(word3,int*,0);arg4=Actor1779Field(owner19,int*,12);word3=Actor1779Field(word3,int*,4);
            word2=Actor1779_func_8004E880(arg7-arg4,word3-arg5,arg6,arg7);
            if(retained16!=word2)goto actor1779StatesDone;
actor1779StartMotion:
            arg4=owner19;arg5=1;word2=180;
block_137:
            Actor1779Field(private20,unsigned char*,13)=word2;Actor1779_func_80034F40(arg4,arg5);
            word2=2;Actor1779Field(owner19,unsigned char*,72)=word2;
            break;
        case 2:                                     
            if (Actor1779_D_8006C770 != 0) {
                Actor1779_func_80034F40(owner19, 2);
            }
            Actor1779Field(owner19, unsigned char *, 0x46) = (unsigned char) (Actor1779Field(owner19, unsigned char *, 0x46) + 8);
            if ((retained17 < 0xF) || ((Actor1779_func_800359A4(private20 + 0xD, 1) != 0) && (retained17 < 0x28))) {
                var_a1_2 = 0;
                Actor1779Field(owner19, unsigned char *, 0x49) = 1U;
                Actor1779Field(owner19, unsigned char *, 0x48) = 0U;
                Actor1779_func_80034F40(owner19,0);
            }
            break;
        }
actor1779StatesDone:
        if ((Actor1779Field(private20, unsigned char *, 0x1E) == 9) && (Actor1779Field(private20, int*, 0x40) == 0)) {
            temp_v1_17 = Actor1779Field(private20, int *, 0x38);
            if (temp_v1_17 >= 0) {
                retained16 = Actor1779_func_8004F334(owner19 + 0xC, Actor1779_D_8006C550 + (temp_v1_17 * 0x58) + 0xC);
            } else {
                retained16 = 0x186A0;
            }
            temp_v1_18 = Actor1779Field(private20, int *, 0x3C);
            if (temp_v1_18 >= 0) {
                var_v0_8 = Actor1779_func_8004F334(owner19 + 0xC, Actor1779_D_8006C550 + (temp_v1_18 * 0x58) + 0xC) < retained16;
            } else {
                var_v0_8 = retained16 > 0x186A0;
            }
            if (var_v0_8 != 0) {
                if (Actor1779Field(private20, int*, 0x40) == 0) {
                    temp_v1_19 = Actor1779Field(private20, int*, 0x2C);
                    Actor1779Field(temp_v1_19,int*,0) -= 1;
                    word3=Actor1779Field(private20,int*,60);arg4=owner19;
                    if(word3>=0){
                        word2=word3*88;word3=Actor1779_D_8006C550;word2+=word3;word3=Actor1779Field(word2,int*,0);
                        __asm__ volatile("":"=r"(word2):"0"(word2),"i"(7):"$5");arg5=7;goto block_160;
                    }
                }
            }else if(Actor1779Field(private20,int*,64)==0){
                temp_v1_21=Actor1779Field(private20,int*,44);Actor1779Field(temp_v1_21,int*,0)-=1;
                word3=Actor1779Field(private20,int*,56);arg4=owner19;
                if(word3>=0){
                    word2=word3*88;word3=Actor1779_D_8006C550;word2+=word3;word3=Actor1779Field(word2,int*,0);
                    __asm__ volatile("":"=r"(word2):"0"(word2),"i"(8):"$5");arg5=8;
block_160:
                    Actor1779Field(private20,int*,64)=word2;word2=Actor1779Field(word3,int*,0);arg6=1;word2++;Actor1779Field(word3,int*,0)=word2;
                    Actor1779_func_8003BB10(arg4,arg5,arg6);
                    temp_v1_23=Actor1779Field(private20,int*,64);Actor1779Field(temp_v1_23,int*,20)+=4096;
                }
            }
        }
        __asm__ volatile(""::"r"(retained17));
        word2=Actor1779Field(owner19,int*,20);word3=Actor1779Field(owner19,unsigned char*,72);word2+=128;Actor1779Field(owner19,int*,20)=word2;
        word2=7;arg4=(int)&originalFrame.sp18;
        if(word3!=word2)Actor1779Field(private20,int*,8)=0;
        __asm__ volatile(""::"r"(arg4):"memory");retained16=owner19+12;
        Actor1779_func_8004F178(arg4,retained16);
        Actor1779_func_8004F194(retained16, retained16, private20);
        word3=Actor1779Field(owner19,unsigned char*,72);word2=10;if(word3==word2)goto block_195;
        Actor1779_D_80071930=0;Actor1779_D_80071914=0;
        word2=Actor1779Field(owner19,short*,56);word3=Actor1779Field(owner19,int*,20);word2+=16384;
        word3=word3<word2;if(word3)goto block_171;
        word3=Actor1779Field(owner19,unsigned char*,72);
        if(word3==4 || word3==6 || word3==9)goto actor1779ContactArgument;
        word2=Actor1779_func_80036220(retained16,private20+116,0,0);__asm__ volatile("":"=r"(private20):"0"(private20));arg4=private20+14;if(word2)goto block_181;
        word2=Actor1779_func_80018368(&originalFrame.sp18,retained16);arg4=retained16;if(word2)goto block_171;
        word2=Actor1779_func_80019194(arg4,450);__asm__ volatile("":"=r"(private20):"0"(private20));arg4=private20+14;if(!word2)goto block_181;
block_171:
        __asm__ volatile("":::"memory");
                if ((Actor1779_D_80071930 == 0) || ((unsigned char) Actor1779Field(private20, unsigned char *, 0xF) < 0xAU)) {
                    if ((unsigned char) Actor1779Field(private20, unsigned char *, 0xF) >= 0x1FU) {
                        temp_v1_25 = Actor1779Field(private20, int*, 0x14);
                        temp_v0_21 = (Actor1779Field(temp_v1_25, short *, 2) * 0x10) + Actor1779Field(temp_v1_25, int *, 0xC);
                        originalFrame.sp30 = (int) (Actor1779Field((int)&Actor1779_D_80065920,short*,(Actor1779_func_8004E880(Actor1779Field(temp_v0_21, int *, 0) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_21, int *, 4) - Actor1779Field(owner19, int *, 0x10), 0) * 2)) * 5) >> 0xA;
                        temp_v1_26 = Actor1779Field(private20, int*, 0x14);
                        temp_v0_22 = (Actor1779Field(temp_v1_26, short *, 2) * 0x10) + Actor1779Field(temp_v1_26, int *, 0xC);
                        temp_v1_27 = Actor1779Field((int)&Actor1779_D_800658A0,short*,(Actor1779_func_8004E880(Actor1779Field(temp_v0_22, int *, 0) - Actor1779Field(owner19, int *, 0xC), Actor1779Field(temp_v0_22, int *, 4) - Actor1779Field(owner19, int *, 0x10), 0) * 2));
                        originalFrame.sp38 = 0;
                        originalFrame.sp34 = (int) (temp_v1_27 * 5) >> 0xA;
                        Actor1779_func_8004F194(owner19 + 0xC, &originalFrame.sp18, &originalFrame.sp30);
                    } else {
                        Actor1779_func_8004F178(owner19 + 0xC, &originalFrame.sp18);
                    }
                }
                if (Actor1779Field(owner19, unsigned char *, 0x48) == 7) {
                    arg5=(int)&Actor1779_D_80071918;arg4=private20;
                } else {
                    Actor1779_func_8004F1C8(&originalFrame.sp18, owner19 + 0xC, (int)&Actor1779_D_80071900);
                    originalFrame.sp20 = 0;
                    arg4=private20;__asm__("":"=r"(arg4):"0"(arg4):"$5");arg5=(int)&originalFrame.sp18;
                }
                Actor1779_func_8004EF74(arg4,arg5,private20);
                word3=Actor1779Field(private20,unsigned char*,15);word2=Actor1779Field(private20,int*,8);word3++;word2>>=1;
                Actor1779Field(private20,int*,8)=word2;Actor1779Field(private20,unsigned char*,15)=word3;
                goto block_195;
actor1779ContactArgument:
        arg4=private20+14;
block_181:
                word2=Actor1779_func_800359A4(arg4,1);retained17=owner19+12;
                if(word2){
                    retained16=Actor1779_func_8001BA30(retained17,640,0,0,0,owner19);Actor1779Keep(retained16);
                    if (retained16 != 0) {
                        Actor1779_func_8004F178(retained17, &originalFrame.sp18);
                        arg4=(int)&originalFrame.sp18;arg5=retained17;__asm__("":"=r"(arg4):"0"(arg4),"r"(arg5):"$21");retained21=retained16+12;
                        Actor1779_func_8004F1C8(arg4,arg5,retained21);
                        Actor1779_func_8004EF74(private20, &originalFrame.sp18, private20);
                        word3=Actor1779Field(private20,unsigned char*,15);word2=Actor1779Field(private20,int*,8);retained22=30;Actor1779Field(private20,unsigned char*,14)=retained22;
                        word3++;word2>>=1;Actor1779Field(private20,int*,8)=word2;Actor1779Field(private20,unsigned char*,15)=word3;
                        if (Actor1779Field(retained16, short *, 0x36) == 0xEF) {
                            if (Actor1779Field(retained16, unsigned char *, 0x48) != 0xA) {
                                retained18=Actor1779Field(retained16,int*,0);
                                retained16 = owner19 + 0xC;
                                if (Actor1779Field(retained18, unsigned char *, 0xE) == 0) {
                                    Actor1779_func_8004F1C8(&originalFrame.sp18, retained21, retained17);
                                    Actor1779_func_8004EF74(retained18, &originalFrame.sp18, retained18);
                                    arg4=private20;word3=Actor1779Field(retained18,unsigned char*,15);
                                    word2 = Actor1779Field(retained18, int *, 8);
                                    arg5=1;Actor1779Field(retained18,unsigned char*,14)=retained22;
                                    goto block_192;
                                }
                            } else {
                                goto block_188;
                            }
                        } else {
block_188:
                            if ((Actor1779Field(retained16, short *, 0x36) == 0x5D) && (Actor1779Field(retained16, unsigned char *, 0x48) != 1) && (retained18=Actor1779Field(retained16,int*,0), (Actor1779Field(retained18, unsigned char *, 0xE) == 0))) {
                                Actor1779_func_8004F1C8(&originalFrame.sp18, retained16 + 0xC, owner19 + 0xC);
                                Actor1779_func_8004EF74(retained18, &originalFrame.sp18, retained18);
                                arg4=private20;arg5=1;word3=Actor1779Field(retained18,unsigned char*,15);
                                __asm__ volatile("":::"$22");word2=30;Actor1779Field(retained18,unsigned char*,14)=word2;
                                word2 = Actor1779Field(retained18, int *, 8);
block_192:
                                word3++;word2>>=1;Actor1779Field(retained18,int*,8)=word2;
                                Actor1779Field(retained18,unsigned char*,15)=word3;
                                word2=Actor1779_func_8004EDE8(arg4,arg5);arg4=retained18;arg5=1;
                                __asm__ volatile("":"=r"(word2):"0"(word2),"r"(arg4),"r"(arg5));retained16=word2;
                                word2=Actor1779_func_8004EDE8(arg4,arg5);arg4=private20;arg5=retained16;
                                __asm__ volatile("":"=r"(word2):"0"(word2),"r"(arg4),"r"(arg5));retained17=word2;retained16=(arg5+retained17)>>1;
                                Actor1779_func_8004F08C(arg4,arg5,retained16);
                                Actor1779_func_8004F08C(retained18, retained17, retained16);
                                retained16 = owner19 + 0xC;
                            } else {
                                goto block_195;
                            }
                        }
                    } else {
                        temp_v0_20 = Actor1779Field(private20, unsigned char *, 0xF);
                        if (temp_v0_20 != 0) {
                            Actor1779Field(private20, unsigned char *, 0xF) = (unsigned char) (temp_v0_20 - 1);
                        }
                        goto block_195;
                    }
                } else {
                    goto block_195;
                }

        goto block_195;
block_195:
        retained16=owner19+12;
        temp_v0_23 = Actor1779Field(private20, int*, 0x10);
        if (Actor1779_func_8004F334(retained16, Actor1779Field(temp_v0_23, int *, 0xC) + (Actor1779Field(temp_v0_23, short *, 2) * 0x10)) < 0x200) {
            temp_a0_6 = Actor1779Field(private20, int*, 0x10);
            Actor1779Field(temp_a0_6, short *, 2) = (short) ((int) (Actor1779Field(temp_a0_6, short *, 2) + 1) % (short) Actor1779Field(temp_a0_6, short *, 0));
        }
        __asm__ volatile("":"=r"(owner19):"0"(owner19));
        temp_v1_28 = Actor1779Field(private20, int *, 0x34);
        if (temp_v1_28 >= 0) {
            temp_a0_7 = Actor1779_func_8004F334(retained16, Actor1779_D_8006C550 + (temp_v1_28 * 0x58) + 0xC);
            if (Actor1779Field(private20, unsigned char *, 0xC) != 4) {
                temp_v1_29 = Actor1779Field(private20, int*, 0x28);
                var_a0_4 = owner19 + 0xC;
                if (Actor1779Field(temp_v1_29,int*,0) == owner19) {
                    Actor1779Field(temp_v1_29,int*,0) = 0;
                }
            } else {
                temp_v0_24 = Actor1779Field(Actor1779Field(private20, int*, 0x28),int*,0);
                if ((temp_v0_24 == owner19) || (temp_v0_24 == 0) || (temp_a0_7 < Actor1779Field(Actor1779Field(private20, int*, 0x24),int*,0))) {
                    Actor1779Field(Actor1779Field(private20, int*, 0x28),int*,0) = owner19;
                    Actor1779Field(Actor1779Field(private20, int*, 0x24),int*,0) = temp_a0_7;
                }
                goto block_206;
            }
        } else {
block_206:
            var_a0_4 = owner19 + 0xC;
        }
        word2=Actor1779_func_80036220(var_a0_4,private20+92,0,0);
        if(word2)word2=4;else word2=255;
        Actor1779Field(private20,unsigned char*,12)=word2;
        Actor1779Field(owner19, int *, 0x14) = (int) (Actor1779Field(owner19, int *, 0x14) - 0x80);
        if ((Actor1779Field(private20, unsigned char *, 0xC) != 4) && ((temp_v1_30 = Actor1779Field(owner19, unsigned char *, 0x48), (temp_v1_30 == 2)) || ((temp_v1_30 == 0) && (Actor1779_func_8004F264(Actor1779Field(owner19, unsigned char *, 0x46), headingOrSentinel23) >= 0x11)))) {
            Actor1779_func_8004F08C(private20, 4, 3);
        }
        arg4=Actor1779Field(private20,int*,64);
        if(arg4){word2=Actor1779Field(arg4,int*,20)-4096;Actor1779Field(arg4,int*,20)=word2;}
        arg4=owner19;Actor1779_func_80055D24(arg4,2);
    }
}

#undef Actor1779Field
#undef Actor1779Keep


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
void func_level_31_80085EF0(Moby* argument) {
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

extern int D_8006C5B8;
void func_80034F80(Moby*, int);
void func_80055D24(Moby*, int);
void func_level_31_800860F0(Moby* moby) {
    if (!moby->state) {
        Moby* child = SpawnMoby(0x13A, moby);
        D_8006C5B8 = 0;
        moby->lowDrawDistance = 0x7F;
        moby->difficultyFlags |= 0x80;
        if (child) {
            child->drawn = 0;
            child->lowDrawDistance = 0;
            func_80034F80(child, 1);
            func_80055D24(child, 1);
            child->state = 1;
            moby->state = 1;
        }
    }
}

/* AI generated; not human reviewed. Rev1 raw385 reused and checked
 * against SCUS-94467 Rev0 80086190..80086510; units/cadence unresolved. */
extern int Decoded385Flags __asm__("D_8006C640");
extern unsigned char Decoded385Release __asm__("D_8006C7B4");
extern int Decoded385Level __asm__("D_8006C58C");
extern unsigned char Decoded385Table[] __asm__("D_80070300");
extern int Decoded385Gate __asm__("D_8006C598");
extern int Decoded385Stop __asm__("D_8006C770");
extern int Decoded385Mode __asm__("D_8006E344");
extern unsigned char Decoded385SaveA[] __asm__("D_8006D088");
extern unsigned char Decoded385SaveB[] __asm__("D_8006C7F8");
void Decoded385Init(Moby*,int,int) __asm__("func_800512E4");
void Decoded385Scale(Vector3D*,int) __asm__("func_8004EF04");
void Decoded385Save(void*,int,void*) __asm__("func_8003B7B4");
int rand(void);
void func_level_31_80086190(Moby* argument) {
 Vector3D vector;
 register int flags __asm__("$2")=Decoded385Flags;
 register Moby* moby __asm__("$17")=argument;
 register int* tag __asm__("$6");
 register int one __asm__("$7");
 register int state __asm__("$3");
 register int index __asm__("$16");
 register unsigned char* stateAddress __asm__("$16");
 __asm__ volatile("" : : : "$4");
 tag=moby->mobyTag;
 if(!flags) {
  if(Decoded385Release&1)goto release;
  if(Decoded385Table[Decoded385Level]&1)goto release;
 }
 __asm__ volatile("" : : : "$7");
 state=*(volatile unsigned char*)&moby->state;one=1;
 __asm__("" : "=r"(one) : "0"(one),"r"(state));
 if(state==one)goto state1;
 if(state<2) {if(state==0)goto state0;goto done;}
 if(state==2)goto state2;
 if(state==3)goto state3;goto done;
state0:
  if(!Decoded385Gate) {register int zero __asm__("$5");register Moby* owner __asm__("$4")=moby;__asm__("" : "=r"(owner) : "0"(owner));__asm__ volatile("" : : : "$3");zero=0;__asm__("" : "=r"(zero) : "0"(zero));Decoded385Init(owner,zero,0);moby->state=2;}
  goto done;
state1:
 __asm__("" : "=r"(one) : "0"(one));
  if(Decoded385Stop) {{register Moby* a0 __asm__("$4")=moby;register int a1 __asm__("$5")=0;__asm__("" : "=r"(a0),"=r"(a1) : "0"(a0),"1"(a1));tag[5]=one;func_80034F40(a0,a1);}moby->state=3;goto done;}
  if(func_80055E84(moby)<21)goto done;
  if(!(Decoded385Flags&1))goto done;
  func_8004F1C8(&vector,(Vector3D*)&spyro,&moby->position);
  Decoded385Scale(&vector,75);
  index=0;
  do {
   {int random=rand();register int old __asm__("$5")=vector.x;old-=10;old+=random%20;vector.x=old;}
   {int random=rand();register int old __asm__("$5")=vector.y;old-=10;old+=random%20;vector.y=old;}
   {int random=rand();register int old __asm__("$5")=vector.z;old-=10;old+=random%20;__asm__("" : "=r"(index) : "0"(index),"r"(old));vector.z=old;}
   if(index<4)SpawnParticle(1,16,&moby->position,&vector);
   index++;
   if(index>=4)goto done;
  }while(1);
  goto done;
state2:
  if(Decoded385Mode!=one) {moby->state=1;func_80034F40(moby,1);}
  goto done;
state3:
  if(Decoded385Stop)tag[5]--;
  __asm__ volatile("" : : : "memory");
  if(tag[5]>=0)goto done;
  if(!*((unsigned char*)moby+0x4F))*((unsigned char*)moby+0x4F)=32;
  {register Moby* a0 __asm__("$4")=moby;register int mode __asm__("$5");__asm__("" : "=r"(a0) : "0"(a0));mode=4;
  moby->angle.yaw-=8;*((unsigned char*)moby+0x4F)+=16;
  func_80055D24(a0,mode);}
  if(*((unsigned char*)moby+0x4F)<127)goto small;
  SpawnParticle(6,12,(Vector3D*)moby,(void*)5);
  stateAddress=&moby->state;
  Decoded385Save(stateAddress,1,Decoded385SaveA);
  Decoded385Save(stateAddress,1,Decoded385SaveB);
release:
  func_80055B18(moby);goto done;
small:
  SpawnParticle(1,12,(Vector3D*)moby,(void*)3);
done:;
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Original SCUS-94467 instructions; original assembly SHA256 aaf5ba6286a3bde04d676105c375007a3bbafd43909389fc41ee391343e46766. Rev1 raw1013 provides a structural crosswalk only. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int Frozen86514_func_80013AE4() __asm__("func_80013AE4");
int Frozen86514_func_80013B7C() __asm__("func_80013B7C");
int Frozen86514_func_80013E38() __asm__("func_80013E38");
int Frozen86514_func_80036220() __asm__("func_80036220");
int Frozen86514_func_80040F48() __asm__("func_80040F48");
int Frozen86514_func_8004E9E4() __asm__("func_8004E9E4");
int Frozen86514_func_8004EA2C() __asm__("func_8004EA2C");
int Frozen86514_func_8004EDE8() __asm__("func_8004EDE8");
int Frozen86514_func_8004F08C() __asm__("func_8004F08C");
int Frozen86514_func_8004F1C8() __asm__("func_8004F1C8");
int Frozen86514_func_8004F334() __asm__("func_8004F334");
int Frozen86514_func_80050B88() __asm__("func_80050B88");
int Frozen86514_rand() __asm__("rand");
extern int Frozen86514_D_8006C550 __asm__("D_8006C550");
extern short Frozen86514_D_8006E040 __asm__("D_8006E040");
extern int Frozen86514_D_8006E044 __asm__("D_8006E044");
extern int Frozen86514_D_8006E048 __asm__("D_8006E048");
extern int Frozen86514_D_8006E53C __asm__("D_8006E53C");
extern unsigned char Frozen86514_D_80070328 __asm__("D_80070328");
extern int Frozen86514_D_80071904 __asm__("D_80071904");
extern int Frozen86514_D_80071908 __asm__("D_80071908");
extern unsigned char Frozen86514_D_80071930 __asm__("D_80071930");

int (*Frozen86514_Callback_74340)() __asm__("unk_ovlheader_80074340");
int (*Frozen86514_Callback_7433C)() __asm__("unk_ovlheader_8007433C");
int (*Frozen86514_Callback_74330)() __asm__("unk_ovlheader_80074330");
void func_level_31_80086514(Moby *inputMoby) {
    /* Member names preserve original stack offsets; values retain retail units. */
    struct {int sp10;int sp14;int sp18;int sp1C;int sp20;char pad_24[4];int sp28;int sp2C;char pad_30[8];int sp38;int sp3C;int sp40;char pad_44[4];} originalStack;

register Moby *moby __asm__("$17")=inputMoby;

    Vector3D **pooledVectorSlot;
    register Vector3D * privateVector30 __asm__("$17");
    register Vector3D * pooledPosition __asm__("$20");
    register Vector3D * pooledVector __asm__("$21");
    Vector3D *targetVector;
    register int vectorAddress __asm__("$4");
    register int allocatedHandle __asm__("$4");
    register int allocatedHandleAgain __asm__("$4");
    register int product5 __asm__("$5");
    register int product7 __asm__("$7");
    register int cosine16 __asm__("$16");
    register int sine17 __asm__("$17");
    register int originalLength __asm__("$17");
    register int emitParticles __asm__("$23");
    register int state __asm__("$3");
    register void * pooledPrivate __asm__("$16");
    register void * pooledPrivateAgain __asm__("$16");
    register void * privateData __asm__("$18");
    register void * pooledMoby __asm__("$19");

    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register short *anglePointer16 __asm__("$16");
    register unsigned char *queryPointer16 __asm__("$16");
    register unsigned char *queryVector22 __asm__("$22");
    register Vector3D *relativeVector16 __asm__("$16");
    __asm__("" : "=r"(moby):"0"(moby));
    state = moby->state;
    privateData = moby->mobyTag;
    switch (state) {
    case 0:
        __asm__("" : "=r"(state):"0"(state));
        if (Frozen86514_func_80036220(&Frozen86514_D_80070328, privateData, 0, 0x400) != 0) {
            M2C_FIELD(&Frozen86514_D_80070328, int *, 0x20C) = 0x10080002;
            vectorAddress = M2C_FIELD(M2C_FIELD(privateData, void **, 0x1C), int *, 0xC);
            Frozen86514_func_80013AE4(vectorAddress, vectorAddress + 0x10);
            moby->state = 3;
            func_8004F178(privateData + 0x30, M2C_FIELD(M2C_FIELD(privateData, void **, 0x1C), int *, 0xC) + 0x10);
            M2C_FIELD(privateData, int *, 0x38) = (int) ((M2C_FIELD(&Frozen86514_D_80070328, int *, 8) - M2C_FIELD(&Frozen86514_D_80070328, int *, 0x44)) - M2C_FIELD(privateData, int *, 0x3C));
            return;
        }
        return;
    case 3:
        if ((Frozen86514_D_8006E044 == 9) && (Frozen86514_D_8006E048 == 1)) {
            moby->state = 1;
            return;
        }
        break;
    case 1:
        M2C_FIELD(&Frozen86514_D_80070328, int *, 0x20C) = 0x10080002;
        if (func_8003BFC0(moby, (int) M2C_FIELD(privateData, short *, 0x70)) == 0) {
            M2C_FIELD(privateData, short *, 0x70) = func_8003BB10(moby, 1, 5);
        }
        if (Frozen86514_D_8006E53C & 0x10) {
            moby->state = 2;
            Frozen86514_func_80013B7C(1);
            return;
        }
        argument4=(int)&originalStack.sp10;
        __asm__("" : "=r"(argument4):"0"(argument4));
        value3=M2C_FIELD(privateData,int*,0x20);
        argument6=Frozen86514_D_8006C550;
        value2=value3*88;
        pooledMoby=(void*)(argument6+value2);
        value3=M2C_FIELD(privateData,int*,0x2C);
        value2=value3*88;
        pooledVectorSlot=(Vector3D**)(argument6+value2);
        pooledVector=*pooledVectorSlot;
        Frozen86514_func_80040F48(argument4,0,argument6);
        anglePointer16=&Frozen86514_D_8006E040;
        emitParticles=0;
        sine17=Frozen86514_func_8004EA2C(*anglePointer16);
        value2=Frozen86514_func_8004E9E4(*anglePointer16);
        value3=originalStack.sp14;
        product5=value3*sine17;
        value3=originalStack.sp10;
        value3*=value2;
        argument4=*anglePointer16;
        value2=(product5+value3)>>11;
        originalStack.sp18=value2;
        value2=Frozen86514_func_8004EA2C(argument4);
        argument4=*anglePointer16;
        cosine16=value2;
        value2=Frozen86514_func_8004E9E4(argument4);
        value3=-originalStack.sp10;
        product7=value3*cosine16;
        value3=originalStack.sp14;
        value3*=value2;
        privateVector30=privateData+0x30;
        originalStack.sp20=0;
        value2=(product7+value3)>>11;
        originalStack.sp1C=value2;
        func_8004F194(privateVector30,privateVector30,(Vector3D*)&originalStack.sp18);
        Frozen86514_Callback_74340(privateVector30,privateVector30,privateData+0x40,0);
        Frozen86514_Callback_74340(privateVector30,privateVector30,privateData+0x58,-1);
        pooledPosition=pooledMoby+12;
        argument4=(int)pooledPosition;
        argument5=(int)privateVector30;
        argument6=1;
        __asm__("" : "=r"(argument4),"=r"(argument5),"=r"(argument6):"0"(argument4),"1"(argument5),"2"(argument6));
        queryPointer16=&Frozen86514_D_80071930;
        queryVector22=queryPointer16-48;
        M2C_FIELD(queryPointer16,Moby**,0)=0;
        M2C_FIELD(queryPointer16,int*,-48)=0;
        Frozen86514_D_80071904 = 0;
        Frozen86514_D_80071908 = 0;
        if (Frozen86514_func_80013E38(argument4,argument5,argument6) != 0) {
            func_8004F178(pooledVector, privateVector30);
        } else {
            value2=(int)M2C_FIELD(queryPointer16,Moby**,0);
            if(value2) {
                argument4=0x10000000;
                __asm__ volatile("" : "=r"(queryPointer16) : "0"(queryPointer16),"r"(argument4) : "memory");
                value2=(int)M2C_FIELD(&Frozen86514_D_80071930,Moby**,0);
                value3=M2C_FIELD(value2,int*,0x18);
                value3|=argument4;
                M2C_FIELD(value2,int*,0x18)=value3;
            }
            if (M2C_FIELD(queryPointer16, int *, -0x30) != 0) {
                func_8004F178(pooledVector,queryVector22);
                goto checkContact;
            }
            value2=(int)M2C_FIELD(queryPointer16,Moby**,0);
            if(value2) {
                relativeVector16=(Vector3D*)&originalStack.sp28;
                __asm__ volatile("" : : : "memory");
                argument5=(int)M2C_FIELD(&Frozen86514_D_80071930,Moby**,0);
                value3=M2C_FIELD(pooledMoby,int*,12);
                __asm__("" : "=r"(value3):"0"(value3));
                value2=M2C_FIELD(argument5,int*,12);
                argument4=(int)relativeVector16;
                originalStack.sp28=value2-value3;
                value2=M2C_FIELD(argument5,int*,16);
                value3=M2C_FIELD(pooledMoby,int*,16);
                argument5=0;
                originalStack.sp2C=value2-value3;
                value2=Frozen86514_func_8004EDE8(argument4,argument5);
                argument4=(int)relativeVector16;
                argument5=(int)privateVector30;
                argument6=(int)pooledPosition;
                __asm__("" : "=r"(argument4),"=r"(argument5),"=r"(argument6):"0"(argument4),"1"(argument5),"2"(argument6));
                originalLength=value2;
                Frozen86514_func_8004F1C8(argument4,argument5,argument6);
                Frozen86514_func_8004F08C(relativeVector16, Frozen86514_func_8004EDE8(relativeVector16, 0), originalLength);
                func_8004F194(pooledVector,pooledPosition,relativeVector16);
checkContact:
                argument4=(int)&Frozen86514_D_80071930;
                __asm__("" : "=r"(argument4):"0"(argument4));
                value2=M2C_FIELD(argument4,int*,0);
                if(value2) {
                    emitParticles=1;
                    if(M2C_FIELD(privateData,short*,0x72)==0) {
                        argument5=2;
                        __asm__("" : "=r"(argument5):"0"(argument5));
                        value2=1;
                        M2C_FIELD(privateData,short*,0x72)=value2;
                        argument4=M2C_FIELD(argument4,int*,0);
                        func_8003BB10(argument4,argument5,1);
                        __asm__ volatile("" : "=r"(emitParticles):"0"(emitParticles));
                        emitParticles=1;
                    }
                } else {
                    goto clearContact;
                }
            } else {
clearContact:
                M2C_FIELD(privateData, short *, 0x72) = 0;
                emitParticles = 1;
            }
        }
        M2C_FIELD(pooledMoby, signed char *, 0x46) = func_8004E880(M2C_FIELD(privateData, int *, 0x30) - M2C_FIELD(pooledMoby, int *, 0xC), M2C_FIELD(privateData, int *, 0x34) - M2C_FIELD(pooledMoby, int *, 0x10), 0);
        M2C_FIELD(pooledMoby, signed char *, 0x45) = func_8004E880(Frozen86514_func_8004F334(pooledMoby + 0xC, privateData + 0x30), M2C_FIELD(privateData, int *, 0x38) - M2C_FIELD(pooledMoby, int *, 0x14), 0);
        Frozen86514_Callback_7433C(pooledVectorSlot,pooledMoby);
        if (emitParticles != 0) {
            originalStack.sp38 = (Frozen86514_rand() & 0xF) - 7;
            originalStack.sp3C = (Frozen86514_rand() & 0xF) - 7;
            originalStack.sp40 = Frozen86514_rand() & 0x3F;
            SpawnParticle(1, 0, pooledVector, (Vector3D *) &originalStack.sp38);
            SpawnParticle(1, 0x3D, pooledVector, (Vector3D *)0x808080);
            return;
        }
        break;
    case 2:
        if ((Frozen86514_D_8006E044 == 9) && (Frozen86514_D_8006E048 == 0x81)) {
            value2=M2C_FIELD(privateData,int*,0x2C);
            value3=value2*88;
            value2=Frozen86514_D_8006C550;
            value2+=value3;
            pooledPrivate=M2C_FIELD(value2,void**,0);
            allocatedHandle = M2C_FIELD(pooledPrivate, int *, 0x14);
            if (allocatedHandle != 0) {
                Frozen86514_func_80050B88(allocatedHandle);
                M2C_FIELD(pooledPrivate, int *, 0x14) = 0;
            }
            if (func_8003BFC0(moby, (int) M2C_FIELD(privateData, short *, 0x70)) != 0) {
                func_8003BE70((int) M2C_FIELD(privateData, short *, 0x70));
            }
            M2C_FIELD(privateData, short *, 0x70) = -1;
        }
        targetVector = M2C_FIELD(M2C_FIELD(privateData, void **, 0x18), Vector3D **, 0xC);
        if (Frozen86514_Callback_74330(M2C_FIELD(M2C_FIELD(privateData, void **, 0x18), Vector3D **, 0xC), func_8004E880(targetVector->x - moby->position.x, targetVector->y - moby->position.y, 0), 0) != 0) {
            value2=M2C_FIELD(privateData,int*,0x2C);
            value3=value2*88;
            value2=Frozen86514_D_8006C550;
            value2+=value3;
            pooledPrivateAgain=M2C_FIELD(value2,void**,0);
            allocatedHandleAgain = M2C_FIELD(pooledPrivateAgain, int *, 0x14);
            if (allocatedHandleAgain != 0) {
                Frozen86514_func_80050B88(allocatedHandleAgain);
                M2C_FIELD(pooledPrivateAgain, int *, 0x14) = 0;
            }
            if (func_8003BFC0(moby, (int) M2C_FIELD(privateData, short *, 0x70)) != 0) {
                func_8003BE70((int) M2C_FIELD(privateData, short *, 0x70));
            }
            M2C_FIELD(privateData, short *, 0x70) = -1;
            moby->state = 0;
        }
        break;
    }
}
#undef M2C_FIELD
