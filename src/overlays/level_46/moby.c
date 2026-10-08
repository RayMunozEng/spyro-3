#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "spu.h"
#include "savepoint.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"
extern int func_80039714(Moby*);

/* AI generated; not yet human reviewed. Derived from the original SCUS-94467
 * USA Rev 0 instructions, including all five dispatch targets and padding.
 * Field offsets and integer operations preserve the disc representation.
 * Helper semantics, physical units, and caller update cadence remain unresolved;
 * this routine describes one invocation. Empty constraints preserve compiler
 * allocation/scheduling and emit no instruction or opcode patch.
 */
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
void func_level_46_80074E40(void *input) {
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

#undef Controller74C50Field


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
void func_level_46_80075A9C(Moby* argument) {
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

/* AI generated; not yet human reviewed. Derived from SCUS-94467 USA Rev 0
 * original instructions and all five dispatch tables, including padding.
 * Offsets, signedness, shifts, and integer operations preserve the disc data.
 * Physical units, helper meanings, and caller cadence remain unresolved;
 * this routine describes one invocation. Empty compiler constraints preserve
 * proven register allocation and scheduling without emitting instructions.
 */
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
void func_level_46_80076128(void *input) {
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
    originalAngle = Controller75F38Field(owner, unsigned char *, 0x46);
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

#undef Controller75F38Field


typedef struct { short timer; unsigned char selector,reserved03; unsigned char reserved04[0x10]; Moby* target; } DecodedFocusTag;
extern int D_8006581C,D_80065810,D_80065818,D_8006C578,D_8006C574;
extern Moby* D_8006C65C;
int func_8004F334(Vector3D*,Vector3D*);
int func_80013E38(Vector3D*,Vector3D*,int);
void func_80037014(Moby*);
void func_80036A68(Moby*,int,int,int);
int rand(void);
void func_level_46_80077678(Moby* moby) {
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
void func_level_46_80077938(Moby* argument) {
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

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80077E58);

extern int D_8006E020, D_8006E024, D_8007191C, D_80071920;
extern Vector3D D_8007190C;
extern int D_8006C644;
extern short D_800658A0[], D_80065920[];
int func_80019194(Vector3D*, int);
int func_8001A358(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8005629C(Moby*);
void func_level_46_800784DC(Moby *moby) {
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
void func_level_46_800787E0(void *input) {
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
void func_level_46_80079354(Moby* moby) {
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
void func_level_46_80079784(Moby* owner) {
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

extern int D_8006C770;
void func_level_46_80079910(Moby* moby) {
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
void func_level_46_800799A0(void *input) {
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


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define P7A6B4Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int P7A6B4func_800135A4() __asm__("func_800135A4");
int P7A6B4func_8001A358() __asm__("func_8001A358");
int P7A6B4func_80034F40() __asm__("func_80034F40");
int P7A6B4func_8003585C() __asm__("func_8003585C");
int P7A6B4func_800359A4() __asm__("func_800359A4");
int P7A6B4func_80035D38() __asm__("func_80035D38");
int P7A6B4func_80035DDC() __asm__("func_80035DDC");
int P7A6B4func_80037BBC() __asm__("func_80037BBC");
int P7A6B4func_8003B74C() __asm__("func_8003B74C");
int P7A6B4func_8003B7B4() __asm__("func_8003B7B4");
int P7A6B4func_8004ED6C() __asm__("func_8004ED6C");
int P7A6B4func_8004F178() __asm__("func_8004F178");
int P7A6B4func_8004F194() __asm__("func_8004F194");
int P7A6B4func_8004F984() __asm__("func_8004F984");
int P7A6B4func_800512E4() __asm__("func_800512E4");
int P7A6B4func_80055E84() __asm__("func_80055E84");
int P7A6B4func_8005629C() __asm__("func_8005629C");
extern unsigned char P7A6B4D_800652B0[] __asm__("D_800652B0");
extern unsigned char P7A6B4D_800652B4[] __asm__("D_800652B4");
extern unsigned char P7A6B4D_800652B6[] __asm__("D_800652B6");
extern unsigned char P7A6B4D_800658A0[] __asm__("D_800658A0");
extern unsigned char P7A6B4D_80065920[] __asm__("D_80065920");
extern unsigned char P7A6B4D_80068F7C[] __asm__("D_80068F7C");
extern unsigned char P7A6B4D_80068F90[] __asm__("D_80068F90");
extern unsigned char P7A6B4D_8006C7F8[] __asm__("D_8006C7F8");
extern unsigned char P7A6B4D_8006D088[] __asm__("D_8006D088");
extern unsigned char P7A6B4D_80070328[] __asm__("D_80070328");
extern unsigned char P7A6B4D_800719A8[] __asm__("D_800719A8");
extern unsigned char P7A6B4D_800719F0[] __asm__("D_800719F0");
extern int P7A6B4D_8006C3F4 __asm__("D_8006C3F4");
extern int P7A6B4D_8006C4F8 __asm__("D_8006C4F8");
extern int P7A6B4D_8006C598 __asm__("D_8006C598");
extern int P7A6B4D_8006C640 __asm__("D_8006C640");
extern int P7A6B4D_8006C648 __asm__("D_8006C648");
extern int P7A6B4D_8006C6D0 __asm__("D_8006C6D0");
extern int P7A6B4D_8006C6E0 __asm__("D_8006C6E0");
extern int P7A6B4D_8006E044 __asm__("D_8006E044");
extern int P7A6B4D_8006E344 __asm__("D_8006E344");
extern int P7A6B4D_8006E538 __asm__("D_8006E538");
extern int P7A6B4D_8006E53C __asm__("D_8006E53C");
extern int P7A6B4D_800719BC __asm__("D_800719BC");
extern int P7A6B4D_800719C0 __asm__("D_800719C0");
extern int P7A6B4D_800719C4 __asm__("D_800719C4");
extern void *P7A6B4D_8006C65C __asm__("D_8006C65C");
extern unsigned char P7A6B4D_80071591 __asm__("D_80071591");
extern void *(*P7A6B4SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7A6B4unk_ovlheader_80074318)() __asm__("unk_ovlheader_80074318");
extern int (*P7A6B4unk_ovlheader_80074320)() __asm__("unk_ovlheader_80074320");
extern int (*P7A6B4unk_ovlheader_8007432C)() __asm__("unk_ovlheader_8007432C");
extern unsigned char P7A6B4D_800715B2 __asm__("D_800715B2");
extern unsigned char P7A6B4D_8006C7B4 __asm__("D_8006C7B4");
extern int P7A6B4D_8006C58C __asm__("D_8006C58C");
extern unsigned char P7A6B4D_80070300[] __asm__("D_80070300");
extern unsigned char *P7A6B4D_8006C550 __asm__("D_8006C550");
int P7A6B4func_80053F50(int) __asm__("func_80053F50");
int P7A6B4func_8003B634(void*,void*,int) __asm__("func_8003B634");
/* AI generated; not human reviewed. Original3932 actor46 instructions.
 * Baseline actor44; preserves original byte2/4 selectors and table stride88.
 * Units, helper meanings and caller cadence unresolved. Empty constraints
 * emit no opcodes. Acceptance requires original linked words and all hashes. */
void func_level_46_80079E30(void *input) {
    register void *owner __asm__("$19")=input;
    struct { int sp18; int sp1C; int sp20; int pad24; } frame;
    register int *privateVector64 __asm__("$16");
    register int tableWord3 __asm__("$3");
    register void *tableArg4 __asm__("$4");
    register void *tableArg5 __asm__("$5");
    register void *callback17 __asm__("$17");
    int temp_a0;
    int temp_a0_4;
    register int helperSelector5 __asm__("$5");
    int wrappedShiftedWordB4;
    int quotientArgument;
    int var_v0;
    int var_v1;
    unsigned char temp_a0_2;
    unsigned char temp_a0_3;
    unsigned char ownerState;
    register int ownerSelector3D __asm__("$3");
    register int selector4 __asm__("$4");
    register int compare2 __asm__("$2");
    register int timerResult2 __asm__("$2");
    void *stateByteAddress;
    register void *savedStateByteAddress __asm__("$16");
    register void *playerVector30 __asm__("$17");
    register void *privateState __asm__("$18");
    void *linkedObject78;
    void *spawnedObject;

    P7A6B4Field(owner, unsigned char *, 0x4A) = 0xFF;
    privateState = P7A6B4Field(owner, void **, 0);
    if ((P7A6B4D_8006C640 > 0) && (P7A6B4Field(privateState, int *, 0x480) == 0)) {
        temp_a0 = P7A6B4D_8006C3F4 + P7A6B4Field(P7A6B4D_800652B0, int *, 0xB0);
        P7A6B4func_8004F984(temp_a0, temp_a0 + P7A6B4Field(P7A6B4D_800652B4, unsigned short *, 0xB0), P7A6B4Field(P7A6B4D_800652B6, unsigned short *, 0xB0));
        P7A6B4Field(privateState, int *, 0x480) = 1;
    }
    ownerState = P7A6B4Field(owner, unsigned char *, 0x48);
    switch (ownerState) {                              /* irregular */
    case 0:
        if (P7A6B4Field(privateState,unsigned char*,2)==0 && P7A6B4D_800715B2!=0) {
            P7A6B4Field(privateState,unsigned char*,2)=4;
        } else if (P7A6B4Field(privateState,unsigned char*,2)==1 &&
                   !(P7A6B4D_8006C7B4&1) &&
                   !(P7A6B4D_80070300[P7A6B4D_8006C58C]&1)) {
            P7A6B4Field(privateState,unsigned char*,2)=5;
        }
        P7A6B4Field(owner,short*,0x38)=0;
        P7A6B4Field(privateState,unsigned char*,5)=1;
        if ((P7A6B4D_8006C598 == 0) && (P7A6B4func_80037BBC(owner,0)!=0)) {
            P7A6B4func_800512E4(owner,0,0x12);
            P7A6B4Field(owner,unsigned char*,0x48)=0x12;
        }
        break;
    case 18:
        if (P7A6B4D_8006E344 != 1) {
            P7A6B4Field(P7A6B4D_80070328, int *, 0x20C) = 0x10000002;
            if(P7A6B4Field(privateState,unsigned char*,4)==2) {
                P7A6B4func_80053F50(-1);
                break;
            }
            {
                register void *originalArg4 __asm__("$4")=P7A6B4D_8006D088;
                register int originalIndex3 __asm__("$3")=P7A6B4Field(privateState,int*,0x44);
                register unsigned char *originalEntry5 __asm__("$5")=P7A6B4D_8006C550;
                originalEntry5 += originalIndex3*88;
                P7A6B4func_8003B634(originalArg4,originalEntry5+12,
                    P7A6B4Field(originalEntry5,unsigned char*,0x46));
            }
            P7A6B4Field(privateState, int *, 0x7C) = 0x3C;
            P7A6B4Field(owner, unsigned char *, 0x48) = 1U;
            P7A6B4func_80034F40(owner, 1);
        }
        break;
    case 1:
        P7A6B4Field(P7A6B4D_80070328, int *, 0x20C) = 0x10000002;
        if (P7A6B4func_8003585C(owner, P7A6B4Field(privateState, int *, 0x34) + 0x80, 8, 0x10, (int) ownerState, 0) != 0) {
            P7A6B4func_80035DDC(owner, 0x80, 0, 0, 0);
        }
        timerResult2 = P7A6B4func_800359A4(privateState + 0x7C, 4);
        __asm__("" : "=r"(owner), "=r"(timerResult2) : "0"(owner), "1"(timerResult2));
        savedStateByteAddress = owner + 0x48;
        if (timerResult2 == 2) {
            P7A6B4Field(owner, unsigned char *, 0x48) = 3U;
            tableArg4 = savedStateByteAddress;
            helperSelector5 = 1;
            __asm__("" : "=r"(tableArg4), "=r"(helperSelector5) : "0"(tableArg4), "1"(helperSelector5));
            callback17 = P7A6B4D_8006D088;
            P7A6B4func_8003B7B4(tableArg4, helperSelector5, callback17);
            P7A6B4func_8003B7B4(savedStateByteAddress, 1, P7A6B4D_8006C7F8);
            P7A6B4func_8003B74C(callback17);
            P7A6B4Field(owner, unsigned char *, 0x48) = 1U;
        }
        break;
    case 3:
        P7A6B4unk_ovlheader_80074318(owner, 0x73);
        P7A6B4D_8006C6D0 = 0;
        P7A6B4func_800135A4(P7A6B4D_800719A8, P7A6B4D_80068F7C, 0);
        P7A6B4func_800135A4(P7A6B4D_800719F0, P7A6B4D_80068F90, 0);
        if ((P7A6B4D_8006E044 == 0x1F) || (P7A6B4D_8006E044 == 0x28)) {
            P7A6B4Field(owner, unsigned char *, 0x4C) = 0;
            P7A6B4Field(owner, unsigned char *, 0x4D) = 0;
            if (P7A6B4D_8006C65C != 0) {
                P7A6B4Field(P7A6B4D_8006C65C, unsigned char *, 0x4C) = 0;
                P7A6B4Field(P7A6B4D_8006C65C, unsigned char *, 0x4D) = 0;
            }
        } else {
            P7A6B4Field(owner, unsigned char *, 0x4C) = 0x10;
            if (P7A6B4D_8006C65C != 0) {
                P7A6B4Field(P7A6B4D_8006C65C, unsigned char *, 0x4C) = 0x10;
            }
        }
        if (P7A6B4Field(P7A6B4D_80070328, int *, 0x24C) == 4) {
            selector4 = P7A6B4Field(P7A6B4D_80070328, int *, 0x48);
            ownerSelector3D = P7A6B4Field(owner, unsigned char *, 0x3D);
            helperSelector5 = selector4 - 0x73;
            if (helperSelector5 != ownerSelector3D) {
                if (selector4 == 0x83) {
                    selector4 = P7A6B4Field(owner, unsigned char *, 0x3C);
                    compare2 = 17;
                    if (selector4 == compare2) goto selectorTwo13;
                    if (ownerSelector3D != compare2) goto selectorOther13;
selectorTwo13:
                    selector4 = (int)owner;
                    __asm__("" : : "r"(selector4));
                    helperSelector5 = 2;
                    goto callSelectorHelper;
selectorOther13:
                    compare2 = 2;
                    if (ownerSelector3D != compare2) goto selectorSixteen13;
                    if (selector4 != ownerSelector3D) goto clearPrivateWord48;
                    selector4 = (int)owner;
                    __asm__("" : : "r"(selector4));
                    helperSelector5 = 16;
                    goto callSelectorHelper;
selectorSixteen13:
                    selector4 = (int)owner;
                    helperSelector5 = 16;
                    goto callSelectorHelper;
                } else if (selector4 == 0x84) {
                    selector4 = P7A6B4Field(owner, unsigned char *, 0x3C);
                    compare2 = 16;
                    if (selector4 == compare2) goto selectorTwo14;
                    if (ownerSelector3D != compare2) goto selectorOther14;
selectorTwo14:
                    selector4 = (int)owner;
                    __asm__("" : : "r"(selector4));
                    helperSelector5 = 2;
                    goto callSelectorHelper;
selectorOther14:
                    compare2 = 2;
                    helperSelector5 = 17;
                    if (ownerSelector3D != compare2) goto selectorSeventeen14;
                    if (selector4 != ownerSelector3D) goto clearPrivateWord48;
                    selector4 = (int)owner;
                    __asm__("" : : "r"(selector4));
                    goto callSelectorHelper;
selectorSeventeen14:
                    selector4 = (int)owner;
                } else {
                    selector4 = (int)owner;
                }
callSelectorHelper:
                P7A6B4func_80034F40(selector4, helperSelector5);
clearPrivateWord48:
                P7A6B4Field(privateState, int *, 0x48) = 0;
            } else {
                goto updateSelector1;
            }
        } else {
updateSelector1:
            if (P7A6B4Field(owner, unsigned char *, 0x3D) == 1) {
                if (P7A6B4Field(P7A6B4D_80070328, int *, 0xB4) != 0) {
                    wrappedShiftedWordB4 = (int)((unsigned int)P7A6B4Field(P7A6B4D_80070328, int *, 0xB4) << 4);
                    quotientArgument = wrappedShiftedWordB4 / 2048;
                } else {
                    quotientArgument = 8;
                }
                P7A6B4unk_ovlheader_80074320(owner, quotientArgument, privateState + 0x48);
            }
        }
        if (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) == 0x81) {
            var_v1 = P7A6B4Field(P7A6B4D_80070328, int *, 0xF4);
            if (var_v1 != 0) {
                var_v0 = 0xFFFFFF;
            } else {
                P7A6B4func_8004F178(&frame.sp18, owner + 0xC);
                frame.sp20 += 0x400;
                var_v0 = P7A6B4func_8001A358(&frame.sp18, 0x800);
                var_v1 = 0xFFFFFF;
                frame.sp20 = var_v0;
            }
            P7A6B4Field(owner, int *, 0x54) = (int) ((var_v0 & var_v1) | 0x80000000);
        } else {
            P7A6B4Field(owner, int *, 0x54) = 0;
        }
        if ((P7A6B4func_800359A4(privateState + 0x4C, 4) != 0) && (P7A6B4D_8006E538 & 0x20) && ((P7A6B4D_8006E044 == 0x1F) || ((P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x7E) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x79) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x80) && ((unsigned int) (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) - 0x7A) >= 2U) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x7C) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x240) == 0))) && (P7A6B4SpawnMoby(0xC5, owner) != 0)) {
            P7A6B4Field(privateState, int *, 0x4C) = 0x19;
        }
        linkedObject78 = P7A6B4Field(privateState, void **, 0x78);
        if (linkedObject78 != 0) {
            if (P7A6B4Field(linkedObject78, unsigned char *, 0x48) != 0) {
                P7A6B4Field(privateState, void **, 0x78) = 0;
                P7A6B4Field(privateState, int *, 0x7C) = 0x3C;
            } else {
                temp_a0_4 = P7A6B4Field(privateState, int *, 0x7C);
                if (temp_a0_4 != 0) {
                    if (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) == 0x82) {
                        if (P7A6B4func_80055E84(owner) >= 7) {
                            if (P7A6B4Field(privateState, short *, 0x74) == 0x22A) {
                                P7A6B4Field(P7A6B4Field(privateState, void **, 0x78), unsigned char *, 0x48) = 0x50U;
                            } else {
                                P7A6B4Field(P7A6B4Field(privateState, void **, 0x78), unsigned char *, 0x48) = 1U;
                            }
                        }
                    } else {
                        P7A6B4Field(privateState, int *, 0x7C) = (int) (temp_a0_4 + P7A6B4D_8006C648);
                    }
                } else if (P7A6B4D_8006E53C & 0x80) {
                    privateVector64 = privateState + 0x64;
                    if (P7A6B4D_8006E344 == 0) {
                        playerVector30 = P7A6B4D_80070328 + 0x30;
                        P7A6B4Field(privateState, int *, 0x5C) = 0x180;
                        P7A6B4Field(privateState, int *, 0x64) = 0x1800;
                        P7A6B4Field(privateState, int *, 0x68) = 0;
                        P7A6B4Field(privateState, int *, 0x6C) = 0;
                        P7A6B4func_8004ED6C(playerVector30, privateVector64, privateVector64);
                        P7A6B4func_8004F194(privateVector64, privateVector64, playerVector30 - 0x30);
                        P7A6B4unk_ovlheader_8007432C(P7A6B4Field(P7A6B4D_80070328, int *, 0x250));
                        P7A6B4Field(privateState, int *, 0x7C) = (int) (P7A6B4Field(privateState, int *, 0x7C) + P7A6B4D_8006C648);
                    }
                }
            }
        } else if ((P7A6B4Field(privateState, short *, 0x76) != 0) && (P7A6B4func_800359A4(privateState + 0x7C, 4) != 0) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x79) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x82) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x80) && (P7A6B4Field(P7A6B4D_80070328, int *, 0x48) != 0x7C)) {
            spawnedObject = P7A6B4SpawnMoby(P7A6B4Field(privateState, short *, 0x74), owner);
            P7A6B4Field(privateState, void **, 0x78) = spawnedObject;
            if (spawnedObject != 0) {
                P7A6B4Field(privateState, int *, 0x7C) = 0;
                P7A6B4Field(privateState, short *, 0x76) = (short) ((unsigned short) P7A6B4Field(privateState, short *, 0x76) - 1);
            }
        }
        break;
    }
    P7A6B4func_80035D38(owner);
    P7A6B4func_8005629C(owner);
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
void func_level_46_8007A5F8(Moby *input) {
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


typedef struct { Vector3D vector; int timer; } DecodedTimedVectorRecord;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_8004EF04(Vector3D*, int);
void func_level_46_8007AA04(Moby* moby) {
    Vector3D offset;
    DecodedTimedVectorRecord* tag = moby->mobyTag;
    if (func_800359A4(&tag->timer, 4)) {
        func_80055B18(moby);
        return;
    }
    func_8004F178(&offset, &tag->vector);
    offset.z += 0x20;
    func_8004EF04(&offset, 8);
    func_8004F1C8(&tag->vector, &tag->vector, &offset);
    func_8004F194(&moby->position, &moby->position, &tag->vector);
    moby->angle.roll = *(unsigned short*)((char*)D_80065920 + ((tag->timer * 8) & 0x1F8)) >> 7;
}

typedef struct {
    unsigned char reserved00[0x34];
    int angle;
    Vector3D point;
} DecodedCheckpointPositionTag;
extern short D_800658A0[], D_80065920[];
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
void func_level_46_8007AAC0(Moby* moby) {
    Vector3D position;
    register void* bounds __asm__("$5") = moby->mobyTag;
    /* Empty constraint retains the retail tag load before argument setup. */
    __asm__("" : "=r"(bounds) : "0"(bounds));
    if (func_80036220(&spyro.position, bounds, 0, 0x400)) {
        DecodedCheckpointPositionTag* tag = spyro.critterMobyPtr->mobyTag;
        register int angle __asm__("$17") = tag->angle;
        int state;
        position.x = (D_80065920[angle] * 13) >> 5;
        position.y = (D_800658A0[tag->angle] * 13) >> 5;
        position.z = 0;
        angle -= 0x80;
        __asm__("" : "=r"(angle) : "0"(angle));
        func_8004F194(&position, &position, &tag->point);
        state = spyro.critterMobyPtr->state;
        spyro.critterMobyPtr->state = 0;
        func_8003B7B4(&spyro.critterMobyPtr->state, 1, &unsavedData);
        spyro.critterMobyPtr->state = state;
        func_8003B634(&savedData, &position, angle & 0xFF);
        func_8003B74C(&savedData);
    }
}

typedef struct { int actorIndex; Vector3D position; int timer; int* counter; } DecodedLinkedActor;
extern Moby* D_8006C550;
extern int D_8006C79C,D_8006C58C;
extern int D_80071AB0[][8];

extern Moby* DecodedActorCallback(Moby*,int,Vector3D*,Vector3D*) __asm__("func_80036A68");
int func_8001A358(Vector3D*,int);
void func_level_46_8007ABF0(Moby* moby) {
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
void func_level_46_8007AF20(void *input) {
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


void func_level_46_8007C074(Moby* moby) {
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
void func_level_46_8007C094(Moby* argument) {
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

/* SCUS-94467 USA Rev 0: original instructions at 0x8007D730.
 * Signed halfword motion and timers; angles consume the low unsigned byte.
 * One update per invocation; caller cadence and particle semantics unresolved.
 * Empty asm constraints emit no instructions and preserve retail scheduling.
 */
typedef struct {
    short velocityX, velocityY, velocityZ;
    short rollDelta, pitchDelta, yawDelta;
    short lifetime, reserved0E;
    int reserved10;
    short bounceCount, particleTimer;
} DecodedBounceTag;
extern int DecodedBounceFloor __asm__("D_80071908");
int DecodedBounceContact(Vector3D*, int, int, Moby*) __asm__("func_8001A310");
int DecodedBounceFragments(Moby*) __asm__("func_80039714");
int DecodedBounceRandom(int, int) __asm__("func_8003636C");
int DecodedBounceCountdown(void*, int) __asm__("func_800359A4");
void DecodedBounceDelete(Moby*) __asm__("func_80055B18");
void func_level_46_8007C294(Moby* argument) {
    Vector3D velocity;
    int reserved1C;
    Vector3D position;
    int reserved2C;
    register Moby* moby __asm__("$16") = argument;
    register DecodedBounceTag* tag __asm__("$17") = moby->mobyTag;
    register unsigned char* particle __asm__("$3");
    int index;
    if (!moby->state && DecodedBounceContact(&moby->position, 150, 3, moby)) {
        if (tag->bounceCount < 3) {
            register int coefficient __asm__("$3") = 3 - tag->bounceCount;
            __asm__("" : "=r"(coefficient) : "0"(coefficient));
            {
                register int vertical __asm__("$2") = coefficient * 50;
                tag->velocityZ = vertical;
            }
            {
                register unsigned int count __asm__("$3") = (unsigned short)tag->bounceCount;
                count++;
                __asm__("" : "=r"(count) : "0"(count));
                tag->bounceCount = count;
            }
            __asm__ volatile("" : : : "memory");
            {
                register int floor __asm__("$2") = DecodedBounceFloor;
                moby->position.z = floor + 155;
            }
            tag->velocityX = tag->velocityX * 2 / 3;
            tag->velocityY = tag->velocityY * 2 / 3;
            tag->lifetime = 150;
        } else {
            moby->state = 1;
            moby->position.z = DecodedBounceFloor;
            tag->lifetime = 100;
        }
    }
    switch (moby->state) {
    case 3:
        if (DecodedBounceFragments(moby)) {
            for (index = 0; index < 3; index++) {
                {
                    int sample = DecodedBounceRandom(0, 2048);
                    register int coordinate __asm__("$3") = moby->position.x - 1024;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    coordinate += sample;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    position.x = coordinate;
                }
                {
                    int sample = DecodedBounceRandom(0, 2048);
                    register int coordinate __asm__("$3") = moby->position.y - 1024;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    coordinate += sample;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    position.y = coordinate;
                }
                {
                    int sample = DecodedBounceRandom(0, 2048);
                    int coordinate;
                    register char* (*spawn)(int, int, Vector3D*, Vector3D*) __asm__("$3");
                    register int kind __asm__("$4") = 1;
                    register int selector __asm__("$5") = 1;
                    register Vector3D* positionArgument __asm__("$6") = &position;
                    register Vector3D* velocityArgument __asm__("$7");
                    __asm__("" : : "r"(kind), "r"(selector), "r"(positionArgument));
                    coordinate = moby->position.z;
                    velocity.z = -30;
                    __asm__ volatile("" : : : "memory");
                    spawn = SpawnParticle;
                    __asm__("" : : "r"(spawn) : "$7");
                    velocityArgument = &velocity;
                    __asm__("" : : "r"(spawn), "r"(velocityArgument));
                    velocity.x = 0;
                    velocity.y = 0;
                    coordinate -= 1024;
                    coordinate += sample;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    position.z = coordinate;
                    particle = spawn(kind, selector, positionArgument, velocityArgument);
                }
                __asm__("" : "=r"(particle) : "0"(particle));
                if (particle) {
                    particle[10] = 180;
                }
            }
        }
        break;
    case 2:
        DecodedBounceFragments(moby);
        break;
    case 0:
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 30;
        SpawnParticle(1, 1, &moby->position, &velocity);
        moby->position.x += tag->velocityX;
        moby->position.y += tag->velocityY;
        tag->velocityZ -= 10;
        if (tag->velocityZ < -200) {
            tag->velocityZ = -200;
        }
        moby->position.z += tag->velocityZ;
        moby->angle.roll += *(unsigned char*)&tag->rollDelta;
        moby->angle.pitch += *(unsigned char*)&tag->pitchDelta;
        moby->angle.yaw += *(unsigned char*)&tag->yawDelta;
        if (DecodedBounceCountdown(&tag->lifetime, 2)) {
            DecodedBounceDelete(moby);
        }
        break;
    case 1:
        if (!tag->particleTimer) {
            velocity.x = DecodedBounceRandom(0, 20) - 10;
            velocity.y = DecodedBounceRandom(0, 20) - 10;
            velocity.z = 20;
            moby->position.z += 50;
            {
                unsigned char* result = SpawnParticle(1, 0, &moby->position, &velocity);
                register int restoredZ __asm__("$3") = moby->position.z;
                __asm__("" : "=r"(restoredZ) : "0"(restoredZ));
                restoredZ -= 50;
                moby->position.z = restoredZ;
                __asm__("" : : "r"(restoredZ));
                particle = result;
                __asm__("" : "=r"(particle) : "0"(particle));
            }
            if (particle) {
                particle[10] = 50;
            }
            tag->particleTimer = 5;
        } else {
            DecodedBounceCountdown(&tag->particleTimer, 2);
        }
        if (DecodedBounceCountdown(&tag->lifetime, 2)) {
            DecodedBounceDelete(moby);
        }
        break;
    }
}

#define ControllerCA7CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern void* ControllerCA7CLinked0 __asm__("D_80070328 + 0x250");
extern void* ControllerCA7CLinked1 __asm__("D_80070328 + 0x250");
extern void* ControllerCA7CLinked2 __asm__("D_80070328 + 0x250");
extern unsigned char ControllerCA7CPlayer[] __asm__("D_80070328");
extern int ControllerCA7CMobyBase __asm__("D_8006C550");
extern int D_80071908;
extern Vector3D ControllerCA7CCollision __asm__("D_80071900");
int ControllerCA7CHelper18368(void*,void*) __asm__("func_80018368");
void* ControllerCA7CHelper1AD60(void*,void*,int,int,void*) __asm__("func_8001AD60");
int ControllerCA7CHelper1C288(void*,int,int) __asm__("func_8001C288");
int ControllerCA7CHelper359A4(void*,int) __asm__("func_800359A4");
int ControllerCA7CHelper35D38(void*) __asm__("func_80035D38");
int ControllerCA7CHelper3BABC(void*,int,int) __asm__("func_8003BABC");
int ControllerCA7CHelper4E880(int,int,int) __asm__("func_8004E880");
int ControllerCA7CHelper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int ControllerCA7CHelper4EDE8(void*,int) __asm__("func_8004EDE8");
int ControllerCA7CHelper4F08C(void*,int,int) __asm__("func_8004F08C");
int ControllerCA7CHelper4F178(void*,void*) __asm__("func_8004F178");
int ControllerCA7CHelper4F194(void*,void*,void*) __asm__("func_8004F194");
int ControllerCA7CHelper4F334(void*,void*) __asm__("func_8004F334");
int ControllerCA7CHelper55B18(void*) __asm__("func_80055B18");
int ControllerCA7CHelper55D24(void*,int) __asm__("func_80055D24");
int ControllerCA7CHelper55F14(void*,int,void*) __asm__("func_80055F14");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level43/moby/8007CA7C and level46/moby/8007C630.
 * Both285 original instructions, global/helper symbols and six owned table/pad
 * words checked separately. Five dispatch entries retain state0/end and state1
 * fallthrough2. Original vector atsp18, fifth call argument atsp10 retained.
 * Exact signed decrements/clamps(-512/-400), thresholds and88-byte record stride
 * retained. Original helper rereads, player-pointer phases and separate calls
 * are preserved; no inferred runtime producer semantics are claimed.
 * Numeric units, fixed-point interpretation, helper contracts and caller cadence
 * remain open; once per invocation. Confidence: exact native/linked words.
 * Falsifiable vectors: every original word and complete retail EXE/overlay SHAs.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_46_8007C630(void *input) {
    register unsigned char *owner __asm__("$17")=input;
    register int* player __asm__("$16");
    register void* preparedPosition __asm__("$4");
    register void* preparedPlayer __asm__("$5");
    Vector3D previous;
    register int terminalWord __asm__("$16");
    register int selectedWord __asm__("$2");
    int *destination;
    register int *position __asm__("$16");
    register int *tag __asm__("$18");
    int nextWord;
    int nextWord3;
    int helperResult;
    register int belowBound __asm__("$2");
    unsigned char index1;
    unsigned char state;
    unsigned char index0;
    register unsigned char *privateRecord __asm__("$16");
    register unsigned char *linkedRecord __asm__("$18");
    register unsigned char *other __asm__("$18");

    state = ControllerCA7CField(owner, unsigned char *, 0x48);
    tag = ControllerCA7CField(owner, int **, 0);
    switch (state) {
    case 0:
        goto finished;
    case 1:
        { register void* linked __asm__("$2")=ControllerCA7CLinked0;
          register int angle __asm__("$3")=ControllerCA7CField(linked,unsigned char*,0x44);
          privateRecord=ControllerCA7CField(linked,void**,0);
          ControllerCA7CField(owner,unsigned char*,0x44)=angle;
          ControllerCA7CField(owner,unsigned char*,0x45)=ControllerCA7CField(privateRecord,int*,0x5C)>>4;
          linked=ControllerCA7CLinked1;
          { register int yaw __asm__("$2")=ControllerCA7CField(linked,unsigned char*,0x46);
            register int one __asm__("$5");
            __asm__("" : "=r"(yaw) : "0"(yaw) : "$5");
            one=1;
            __asm__("" : "=r"(yaw),"=r"(one) : "0"(yaw),"1"(one));
            ControllerCA7CField(owner,unsigned char*,0x46)=yaw;
            ControllerCA7CHelper55F14(ControllerCA7CLinked2,one,owner+0xC); }
        }
        ControllerCA7CHelper55D24(owner, 4);
        { register void* first __asm__("$4")=owner+0x20;
          register int* second __asm__("$5")=tag;
          register int word __asm__("$2")=ControllerCA7CField(privateRecord,int*,0x60);
          register int* third __asm__("$6");
          __asm__("" : "=r"(word) : "0"(word) : "$6");
          third=tag;
          __asm__("" : "=r"(first),"=r"(second),"=r"(word),"=r"(third) : "0"(first),"1"(second),"2"(word),"3"(third));
          ControllerCA7CField(tag,int*,4)=0;
          ControllerCA7CField(tag,int*,8)=0;
          ControllerCA7CField(tag,int*,0)=word;
          ControllerCA7CHelper4ED6C(first,second,third);
        }
        ControllerCA7CField(tag, int *, 0xC) = 0xB4;
        ControllerCA7CField(owner, unsigned char *, 0x48) = 2U;
        /* fallthrough */
    case 2:
        if ((ControllerCA7CField(owner, int *, 0xC) >= 0x400) && (ControllerCA7CField(owner, int *, 0x10) >= 0x400) && (ControllerCA7CField(owner, int *, 0x14) >= 0x400) && (ControllerCA7CHelper359A4((int*)((unsigned char*)tag+0xC), 4) == 0)) {
            { register void* prepared __asm__("$4")=&previous;
              __asm__("" : "=r"(prepared) : "0"(prepared) : "$16");
              position = (int*)(owner + 0xC);
              ControllerCA7CHelper4F178(prepared,position); }
            ControllerCA7CHelper4F194(position, position, tag);
            ControllerCA7CField(owner, unsigned char *, 0x45) = ControllerCA7CHelper4E880(ControllerCA7CHelper4F334(position, &previous), ControllerCA7CField(owner, int *, 0x14) - previous.z, 0);
            nextWord = ControllerCA7CField(tag, int *, 8) - 8;
            ControllerCA7CField(tag, int *, 8) = nextWord;
            if (nextWord < -0x200) {
                ControllerCA7CField(tag, int *, 8) = -0x200;
            }
            ControllerCA7CHelper55D24(owner, 6);
            if (ControllerCA7CHelper18368(&previous,position)!=0) {
                ControllerCA7CHelper4F178(position,&ControllerCA7CCollision);
                preparedPosition=position;
                __asm__("" : "=r"(preparedPosition) : "0"(preparedPosition) : "$16");
                player=(int*)ControllerCA7CPlayer;
                preparedPlayer=player;
                goto sharedDistance;
            }
            other=ControllerCA7CHelper1AD60(&previous,position,0,0,owner);
            if(!other)goto finished;
            if(ControllerCA7CHelper18368(position,other+0xC))goto finished;
            preparedPosition=position;
            __asm__("" : "=r"(preparedPosition) : "0"(preparedPosition) : "$16");
            player=(int*)ControllerCA7CPlayer;
            preparedPlayer=player;
            ControllerCA7CField(other,int*,0x18)|=0x10000;
sharedDistance:
            { register int first __asm__("$4")=ControllerCA7CHelper4F334(preparedPosition,preparedPlayer);
              register int third __asm__("$6")=0;
              register int second __asm__("$5")=ControllerCA7CField(owner,int*,0x14);
              register int word __asm__("$2")=ControllerCA7CField(ControllerCA7CPlayer,int*,8);
              second-=200;
              __asm__("" : "=r"(second),"=r"(word) : "0"(second),"1"(word));
              second=word-second;
              ControllerCA7CField(owner,unsigned char*,0x44)=64-ControllerCA7CHelper4E880(first,second,third); }
            ControllerCA7CField(owner,unsigned char*,0x46)=ControllerCA7CHelper4E880(player[0]-ControllerCA7CField(owner,int*,0xC),ControllerCA7CField(ControllerCA7CPlayer,int*,4)-ControllerCA7CField(owner,int*,0x10),0);
            ControllerCA7CHelper3BABC(owner,1,0);
            SpawnMoby(0x3ED,owner);

        }
removeOwner:
        ControllerCA7CHelper55B18(owner);
        return;
    case 3:
        index0 = ControllerCA7CField(owner, unsigned char *, 0x3A);
        if (index0 != 0xFF) {
            { register int offset __asm__("$2")=index0*11;
              register int address __asm__("$3")=ControllerCA7CMobyBase;
              register int one __asm__("$2");
              __asm__("" : "=r"(offset),"=r"(address) : "0"(offset),"1"(address));
              offset*=8;address+=offset;one=1;
              __asm__("" : "=r"(address),"=r"(one) : "0"(address),"1"(one));
              ControllerCA7CField(address,unsigned char*,0x49)=one; }
        }
        destination = (int*)(owner + 0xC);
        ControllerCA7CHelper4F194(destination, tag, destination);
        nextWord3 = ControllerCA7CField(tag, int *, 8) - 8;
        ControllerCA7CField(tag, int *, 8) = nextWord3;
        if (nextWord3 < -0x190) {
            ControllerCA7CField(tag, int *, 8) = -0x190;
        }
        helperResult = ControllerCA7CHelper35D38(owner);
        if ((helperResult != 0) && ((ControllerCA7CField(owner, int *, 0x14) - helperResult) < 0x50)) {
            ControllerCA7CHelper3BABC(owner, 0, 0);
            if (ControllerCA7CField(tag, int *, 0x10) == 0) {
                ControllerCA7CHelper3BABC(owner, 0, 0);
                ControllerCA7CHelper4F08C(tag, ControllerCA7CHelper4EDE8(tag, 1), 0x28);
                ControllerCA7CField(owner, int *, 0x14) = (int) (D_80071908 + 0x40);
                ControllerCA7CField(tag, int *, 8) = 0x32;
                ControllerCA7CField(tag, int *, 0x10) = 1;
                return;
            }
{ register int state __asm__("$3")=4;
              register int height __asm__("$2")=D_80071908;
              __asm__ volatile("" : "=r"(state) : "0"(state) : "memory");
              ControllerCA7CField(owner,unsigned char*,0x48)=state;
              ControllerCA7CField(owner,int*,0x14)=height+64; }
            return;
        }
        break;
    case 4:
        { register int sentinel __asm__("$3")=255;
          register void* linked __asm__("$2");
          register int index __asm__("$4");
          __asm__("" : "=r"(sentinel) : "0"(sentinel) : "$2", "$4", "$18");
          linked=ControllerCA7CLinked0;
          index=ControllerCA7CField(owner,unsigned char*,0x3A);
          linkedRecord=ControllerCA7CField(linked,void**,0);
          __asm__("" : "=r"(sentinel),"=r"(index),"=r"(linkedRecord) : "0"(sentinel),"1"(index),"2"(linkedRecord));
          if(index!=sentinel){
            register int offset __asm__("$2")=index*11;
            register int address __asm__("$3")=ControllerCA7CMobyBase;
            register int one __asm__("$2");
            __asm__("" : "=r"(offset),"=r"(address) : "0"(offset),"1"(address));
            offset*=8;address+=offset;one=1;
            __asm__("" : "=r"(address),"=r"(one) : "0"(address),"1"(one));
            ControllerCA7CField(address,unsigned char*,0x49)=one;
          }
        }
        { register int flags __asm__("$2")=ControllerCA7CField(linkedRecord,int*,0x78);
        terminalWord=ControllerCA7CField(linkedRecord,short*,0x76);
        if(flags!=0) { terminalWord+=1; } }
        belowBound=terminalWord<10;
        if ((belowBound != 0) && (ControllerCA7CHelper1C288(owner + 0xC, 0x200, 0) != 0)) {
            ControllerCA7CHelper55B18(owner);
            ControllerCA7CField(linkedRecord, int *, 0x7C) = 0;
            if (terminalWord == 0) {
                selectedWord = 0xA;
            } else {
                __asm__ volatile("" : : : "$2");
                selectedWord = 9;
            }
            ControllerCA7CField(linkedRecord, short *, 0x76) = selectedWord;
            ControllerCA7CField(linkedRecord, short *, 0x74) = 0x66;
        }
        break;
    }
finished:;
}
#undef ControllerCA7CField


INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_8007CAA4);

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_8007CF70);

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level46 0x8007EF28..0x8007F248: 200 original instructions.
 * Original helper arguments, signed table products (sample*25)>>7,
 * halfword counter, byte accesses and post-call rereads preserved.
 * Helper contracts, physical units and caller cadence remain unresolved.
 * Empty compiler constraints emit no CPU instructions. Acceptance requires
 * every original linked word and full EXE/all-overlay hashes.
 */
extern unsigned char P7EF28Player[] __asm__("D_80070328");
extern unsigned char P7EF28Flags[] __asm__("D_80066BC8");
extern short D_800719DC;
extern int D_8006C648;
extern short P7EF28Cos[] __asm__("D_80065920");
extern short P7EF28Sin[] __asm__("D_800658A0");
int func_800369D8(int);
void func_level_46_8007EF28(Moby* argument) {
 register Moby* owner __asm__("$18")=argument;
 register unsigned char* privateState __asm__("$17");
 register Moby* child __asm__("$16");
 register int value100 __asm__("$16");
 register int value1 __asm__("$19");
 register int valueC8 __asm__("$17");
 register int fragmentCount __asm__("$4"),fragmentClass __asm__("$5");
 __asm__("" : "=r"(owner):"0"(owner));privateState=owner->mobyTag;
 if(owner->damageFlags&0x40000) {
  if(owner->animationRun) {
   int helperResult=func_800369D8(owner->animationRun);
   
   if(helperResult==1) {
   P7EF28Flags[19]=3;D_800719DC=1;
   PlaySound(((unsigned char*)D_8006C654)[35],owner,161);
   child=SpawnMoby(211,owner);
   
   if(child) {
    func_8004F178(&child->position,(Vector3D*)P7EF28Player);
    child->position.x+=(P7EF28Cos[P7EF28Player[14]]*25)>>7;
    __asm__("" : : : "memory");
    {register int z __asm__("$3")=child->position.z;
     register int sample __asm__("$4")=P7EF28Sin[P7EF28Player[14]];
     __asm__("" : "=r"(sample):"0"(sample),"r"(z));
     child->position.z=z+500;
     __asm__("" : : : "memory");
     {register int y __asm__("$3")=child->position.y;
      __asm__("" : "=r"(y):"0"(y),"r"(sample));
      child->position.y=y+((sample*25)>>7);
     }
    }
   }
  }
  }
  fragmentCount=4;fragmentClass=191;
  __asm__("" : "=r"(fragmentClass):"0"(fragmentClass),"r"(fragmentCount):"$16");
  value100=256;
  SpawnFragments(fragmentCount,fragmentClass,owner,(Vector3D*)*(int*)(privateState+12),0,value100);
  {
   register int a4 __asm__("$4")=1;
   register int a5 __asm__("$5")=191;
   register Moby* a6 __asm__("$6")=owner;
   register int a7 __asm__("$7")=1;
   __asm__("" : : "r"(a4),"r"(a5),"r"(a6),"r"(a7):"$19","$17");
  }
  value1=1;valueC8=200;
  {
   register Moby* fragment __asm__("$3")=func_800391E8(1,191,owner,1,value1,valueC8,value100);
   if(fragment)fragment->position.z+=4096;
   fragment=func_800391E8(1,191,owner,1,value1,valueC8,value100);
   if(fragment)fragment->position.z+=4096;
  }
  func_80055D24(owner,4);func_8003BA00(owner);func_800369B8(owner,56);func_80055B18(owner);
 } else {
  if(owner->damageFlags&0x10000) {
   if(*(short*)(privateState+4)==0) {
    *(short*)(privateState+6)=owner->angle.roll;*(short*)(privateState+8)=owner->angle.pitch;
   }
   *(short*)(privateState+4)=1;__asm__("" : : : "$4");func_8003BABC(owner,0,0);
  }
  owner->damageFlags=0;
  if(*(short*)(privateState+4)) {
   *(short*)(privateState+4)+=D_8006C648;
   if(*(short*)(privateState+4)<64) {
    owner->angle.roll=((unsigned char*)*(int*)privateState)[(*(short*)(privateState+4)>>1)*2]+privateState[6];
    owner->angle.pitch=((unsigned char*)*(int*)privateState)[(*(short*)(privateState+4)>>1)*2+1]+privateState[8];
   } else {
    *(short*)(privateState+4)=0;owner->angle.roll=*(short*)(privateState+6);owner->angle.pitch=*(short*)(privateState+8);
   }
  }
 }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_8007F248);

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80081980);

int func_8003636C(int,int);
int func_80039714(Moby*);
void func_level_46_80081D8C(Moby* moby) {
    Vector3D16* tag=moby->mobyTag;
    Vector3D velocity;
    char* particle;
    if(moby->state==0x32) {func_80055B18(moby);return;}
    if(moby->state==0) {
        tag->z=func_8003636C(0x96,0x12C);
        tag->x=func_8003636C(0,0x12C)-0x96;
        tag->y=func_8003636C(0,0x12C)-0x96;
        moby->state=1;
    }
    velocity.x=func_8003636C(0,0xA0)-0x50;
    velocity.y=func_8003636C(0,0xA0)-0x50;
    velocity.z=func_8003636C(0,0x64);
    particle=SpawnParticle(1,0,&moby->position,&velocity);
    if(particle)particle[0xA]=func_8003636C(0x78,0xAA);
    if(func_80039714(moby))SpawnParticle(0x10,0x46,&moby->position,(Vector3D*)0x20);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80081EC8);

void func_level_46_80082FC0(Moby* moby) {
    func_80039714(moby);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level_43/moby/func_level_43_8007DF90.s and
 * level_46/moby/func_level_46_80082FE0.s: all 248 instructions read per copy.
 * Four word-sized child slots at tag+0..12 advance by four bytes. Signed
 * halfwords at tag+16/+18 and a word at +20 retain their original widths.
 * Child pointer rereads after helpers and byte stores are intentional.
 * Existing field/helper names do not establish semantics. Helper contracts,
 * selector producers, coordinate units and caller cadence remain unresolved.
 * Once per invocation. Confidence: exact compiled words. Falsifiable vectors:
 * every original linked word at the listed addresses and all retail hashes.
 * Empty compiler constraints preserve lifetimes without opcode patches.
 */
void ControllerDF90Update(int,int,int) __asm__("func_80021ED8");
int ControllerDF90Read(int) __asm__("func_80021F3C");
#define ControllerDF90Field(base,type,offset) (*(type)((unsigned char*)(base)+(offset)))
extern int D_8006C640;
void func_level_46_80082FE0(Moby *argument) {
    register Moby* moby __asm__("$19")=argument;
    short readSelector;
    short resetSelector;
    register int selectorBits __asm__("$2");
    register int highByte __asm__("$3");
    register int spawnIndex __asm__("$17");
    register int animationIndex __asm__("$17");
    register int removeIndex __asm__("$17");
    register int resetIndex __asm__("$17");
    register int frameStep __asm__("$21");
    register int updateByte __asm__("$2");
    register int framePhase __asm__("$20");
    register int animationOne __asm__("$20");
    register int animationSpeed __asm__("$21");
    unsigned char initialState;
    unsigned char currentState;
    register Moby **tag __asm__("$18");
    register Moby **spawnSlot __asm__("$16");
    register Moby **animationSlot __asm__("$16");
    register Moby **removeSlot __asm__("$16");
    register Moby **resetSlot __asm__("$16");
    void *removeChild;
    void *resetChild;
    register void *stateAddress __asm__("$16");
    void *spawnedChild;
    void *positionChild;
    void *animationChild;
    void *previousAnimationChild;
    void *previousFrameChild;
    void *stateArgument;

    initialState = moby->state;
    tag = (Moby**)moby->mobyTag;
    if(initialState==5)goto done;
    if(initialState==6)goto resetState;
    if(initialState!=7)goto normalState;
    moby->state=2;
    stateAddress=&moby->state;
    func_8003B7B4(stateAddress,1,&savedData);
    stateArgument=stateAddress;
    goto writeUnsavedState;
resetState:
    moby->state=0;
    ControllerDF90Read(ControllerDF90Field(tag, short *, 0x12));
    ControllerDF90Update(ControllerDF90Field(tag, short *, 0x12),0xFC,0);
normalState:
        if (ControllerDF90Field(tag, void **, 0) == 0) {
            spawnIndex = 0;
            spawnSlot = tag;
            frameStep = 1;
            do {
                spawnedChild = SpawnMoby(0xDD, moby);
                framePhase=spawnIndex*4;
                __asm__("" : "=r"(framePhase) : "0"(framePhase));
                *spawnSlot = spawnedChild;
                if (spawnedChild != 0) {
                    func_8004F178((Vector3D*)((unsigned char*)spawnedChild + 0xC), &moby->position);
                    ControllerDF90Field(*spawnSlot, unsigned char *, 0x46) = (unsigned char) ControllerDF90Field(moby, unsigned char *, 0x46);
                    positionChild = *spawnSlot;
                    ControllerDF90Field(positionChild, int *, 0x14) = (int) (ControllerDF90Field(positionChild, int *, 0x14) + (spawnIndex * ControllerDF90Field(tag, short *, 0x10)));
                    ControllerDF90Field(*spawnSlot, unsigned char *, 0x4C) = 0x28;
                    ControllerDF90Field(*spawnSlot, unsigned char *, 0x47) = 0xFF;
                    ControllerDF90Field(*spawnSlot, unsigned char *, 0x3E) = framePhase;
                    ControllerDF90Field(*spawnSlot, unsigned char *, 0x3F) = frameStep;
                    ControllerDF90Field(*spawnSlot, unsigned char *, 0x40) = 0x30;
                }
                spawnSlot++;
                spawnIndex += 1;
                frameStep += 4;
            } while (spawnIndex < 4);
        }
        currentState = moby->state;
        if (currentState == 1) {
            animationIndex = 0;
            animationOne=1;
            animationSpeed=0x72;
            __asm__("" : "=r"(animationOne),"=r"(animationSpeed) : "0"(animationOne),"1"(animationSpeed) : "$16");
            animationSlot = tag;
            do {
                animationChild = *animationSlot;
                if (ControllerDF90Field(animationChild, unsigned char *, 0x3D) != animationOne) {
                    ControllerDF90Field(animationChild, unsigned char *, 0x40) = animationSpeed;
                    previousAnimationChild = *animationSlot;
                    ControllerDF90Field(previousAnimationChild, unsigned char *, 0x3C) = (unsigned char) ControllerDF90Field(previousAnimationChild, unsigned char *, 0x3D);
                    ControllerDF90Field(*animationSlot, unsigned char *, 0x3D) = animationOne;
                    previousFrameChild = *animationSlot;
                    ControllerDF90Field(previousFrameChild, unsigned char *, 0x3E) = (unsigned char) ControllerDF90Field(previousFrameChild, unsigned char *, 0x3F);
                    ControllerDF90Field(*animationSlot, unsigned char *, 0x3F) = 0U;
                    func_80035734(*animationSlot);
                }
                animationIndex += 1;
                animationSlot++;
            } while (animationIndex < 4);
            goto removeParent;
        }
        if (currentState == 2) {
            removeIndex = 0;
            removeSlot = tag;
            do {
                removeChild = *removeSlot;
                if (removeChild != 0) {
                    func_80055B18(removeChild);
                    *removeSlot = 0;
                }
                removeIndex += 1;
                removeSlot++;
            } while (removeIndex < 4);
            readSelector = ControllerDF90Field(tag, short *, 0x12);
            if (readSelector >= 0) {
                selectorBits = ControllerDF90Read(readSelector);
                highByte=selectorBits>>8;
                __asm__("" : "=r"(highByte),"=r"(selectorBits) : "0"(highByte),"1"(selectorBits));
                if ((selectorBits & 0xF) && !(highByte & 0xFF)) {
                    ControllerDF90Update(ControllerDF90Field(tag, short *, 0x12), 0xFC, 0);
                }
            }
            if (func_8003BFC0(moby, ControllerDF90Field(tag, int *, 0x14)) != 0) {
                func_8003BE70(ControllerDF90Field(tag, int *, 0x14));
            }
            ControllerDF90Field(tag, int *, 0x14) = -1;
            func_8003BB10(moby, 2, 0);
            stateArgument = &moby->state;
            goto writeUnsavedState;
writeUnsavedState:
            func_8003B7B4(stateArgument,1,&unsavedData);
removeParent:
            func_80055B18(moby);
            goto done;
        }
        resetIndex = 0;
        if (currentState == 4) {
            resetSlot = tag;
            do {
                resetChild = *resetSlot;
                if (resetChild != 0) {
                    func_80055B18(resetChild);
                    *resetSlot = 0;
                }
                resetIndex += 1;
                resetSlot++;
            } while (resetIndex < 4);
            resetSelector = ControllerDF90Field(tag, short *, 0x12);
            if (resetSelector >= 0) {
                ControllerDF90Read(resetSelector);
                ControllerDF90Update(ControllerDF90Field(tag, short *, 0x12), 0xFC, 0);
            }
            if (func_8003BFC0(moby, ControllerDF90Field(tag, int *, 0x14)) != 0) {
                func_8003BE70(ControllerDF90Field(tag, int *, 0x14));
            }
            ControllerDF90Field(tag, int *, 0x14) = -1;
            func_8003BB10(moby, 2, 0);
            updateByte=5;
            __asm__("" : "=r"(updateByte) : "0"(updateByte));
            moby->state=updateByte;
            __asm__ volatile("" : : : "memory");
            updateByte = 0xFF;
            goto storeUpdateByte;
        }
        if (func_8003BFC0(moby, ControllerDF90Field(tag, int *, 0x14)) == 0) {
            ControllerDF90Field(tag, int *, 0x14) = func_8003BB10(moby, 1, 4);
        }
        { register int skip __asm__("$2")=D_8006C640<9;
          __asm__("" : "=r"(skip) : "0"(skip));
          if(skip)goto done; }
        updateByte=12;
        {
storeUpdateByte:
            ControllerDF90Field(moby, unsigned char *, 0x4A) = updateByte;
        }
done:
    return;
}

#undef ControllerDF90Field


extern int D_8006C770;
void func_80055B18(Moby*);
void func_level_46_800833C0(Moby* moby) {
    if (moby->state == 0) {
        if (D_8006C770 && moby->animationState.id == 1) func_80055B18(moby);
    } else {
        int expired = func_800359A4(moby->mobyTag, 4);
        register Moby* argument __asm__("$4") = moby;
        if (expired) {
            func_80055B18(argument);
        } else {
            /* Non-emitting constraint preserves the retail branch delay slot. */
            __asm__("" : "=r"(argument) : "0"(argument));
        }
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8008343C..80083760. One checksum byte is processed per invocation.
 * Source RAM, tracked pointer producers and runtime cadence unresolved. */
extern unsigned char DecodedAgent227Player[] __asm__("D_80070328");
extern unsigned char DecodedAgent227Flags[] __asm__("D_80070300");
extern unsigned int D_800722B8;
extern unsigned int DecodedAgent227Comparison __asm__("unk_ovlheader_8007439C");
extern int D_8006C770;
int func_80055E84(Moby*);
void func_8002CA50(void);void func_8002D044(void);
void func_level_46_8008343C(Moby* argument) {
 register Moby* moby __asm__("$17")=argument;
 register int mode __asm__("$2");
 register int* tag __asm__("$16");
 register Moby* child __asm__("$18");
 register int state __asm__("$16");
 Vector3D selectedPosition;int pad1;
 Vector3D local;int pad2;
 __asm__("" : "=r"(moby):"0"(moby));
 mode=*(int*)(DecodedAgent227Player+0x24C);
 tag=moby->mobyTag;
 if(mode==4) {
  unsigned char* tracked=**(unsigned char***)(DecodedAgent227Player+0x250);
  tag[1]=*(short*)(tracked+0x76);
  if(*(int*)(tracked+0x78))tag[1]++;
  if(tag[1]>0) {
   if(!tag[0]) {
    tag[0]=(short)func_8002803C(21,460,func_80027E40,func_80027A60,func_80029904,tag+1,10);
    moby->updateDistance=255;
   }
  } else if(tag[0]) {
   func_80028154(tag[0]);tag[0]=0;moby->updateDistance=16;
  }
 }
 if(!tag[3])tag[3]=(int)func_8002CA50+3-0x80AD;
 if((unsigned int)tag[3]<(unsigned int)func_8002D044+3-0x80AD) {
  register int index __asm__("$4")=0;
  register unsigned int polynomial __asm__("$5")=0x80050000;
  tag[2]^=(unsigned int)*(unsigned char*)(tag[3]+0x80AD)<<24;
  do {
   if(tag[2]<0)tag[2]=((unsigned int)tag[2]<<1)^polynomial;
   else tag[2]=(unsigned int)tag[2]<<1;
   index++;
  }while(index<8);
  tag[3]++;
 } else {
  if((((unsigned int)(tag[2]>>12)&0xFFFF0)|(D_800722B8&0xFFF0000F))!=DecodedAgent227Comparison) {
   DecodedAgent227Flags[7]=0;DecodedAgent227Flags[16]=0;DecodedAgent227Flags[25]=0;DecodedAgent227Flags[34]=0;tag[2]=0;
  }
 }
 state=moby->state;
 switch(state) {
 case 0:
  if(moby->substate!=1) {moby->state=1;func_80034F40(moby,1);}
  moby->substate=0;break;
 case 1: {
  int value=func_80055E84(moby);
  if(!moby->substate && moby->animationState.id==state && (unsigned int)(value-41)<5) {
   func_80055D24(moby,5);child=SpawnMoby(102,moby);
   __asm__("" : "=r"(child):"0"(child));
   if(child) {
    tag=child->mobyTag;
    moby->substate=1;local.x=60;local.y=0;local.z=0;
    func_8004ED6C(&moby->rotationMatrix,&local,(Vector3D*)tag);
    tag[2]=80;func_80055F14(moby,0,&selectedPosition);
    {register int z __asm__("$3")=selectedPosition.z;
     __asm__("" : "=r"(z):"0"(z));
     child->state=3;child->position.z=z;}
   }
  }
  if(D_8006C770) {moby->substate=0;moby->state=0;func_80034F40(moby,0);}
  break;
 }
 }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80083760);

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80084F60);

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_8008546C);

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80085908);

typedef struct { short selector, enabled; } DecodedSelectorTag;
int DecodedSelectorRead(int) __asm__("func_80021F3C");
void DecodedSelectorSend(int, int, int) __asm__("func_80021ED8");
void func_80055B18(Moby*);
void func_level_46_80086D08(Moby* moby) {
    DecodedSelectorTag* tag = moby->mobyTag;
    switch (moby->state) {
    case 0:
        if (tag->enabled) {
            unsigned char* state;
            moby->state = 1;
            state = &moby->state;
            func_8003B7B4(state, 1, &savedData);
            func_8003B7B4(state, 1, &unsavedData);
            func_80055B18(moby);
        }
        break;
    case 1:
        {
            int result = DecodedSelectorRead(tag->selector);
            if (((result >> 8) & 255) == 0 && (result & 15)) {
                DecodedSelectorSend(tag->selector, 0xFC, 0);
                func_80055B18(moby);
            }
        }
        break;
    }
}

/* SCUS-94467 USA Rev 0, 0x80086DD8: 227 original instructions.
 * Three loops consume six 32-bit Moby indices with an 88-byte record stride.
 * Linked byte stores follow the two original pointer loads at offset zero.
 * Signed modulo 27 is expressed as quotient and remainder; no CPU opcode asm.
 * HUD creation results are explicitly narrowed to signed 16 bits as in retail.
 * Helper semantics, position units and caller cadence remain unresolved.
 * Empty constraints preserve compiler allocation/order and emit no instructions.
 * AI generated; not human reviewed. */
#define P86DD8_FIELD(type,base,offset) (*(type*)((unsigned char*)(base)+(offset)))
extern unsigned char *P86DD8End __asm__("D_8006C54C");
extern int P86DD8Table[] __asm__("D_80071A10");
extern unsigned char D_level_46_80091B40[];
extern int D_8006C774;
extern struct { Vector3D position; } D_80070328;
void func_level_46_80086DD8(Moby *input) {
    register Moby *owner __asm__("$18")=input;
    register Moby *initialMoby __asm__("$3");
    register Moby *activeMoby __asm__("$3");
    register Moby *resetMoby __asm__("$3");
    register int *tableEntry4 __asm__("$4");
    register int index3 __asm__("$3"), offset2 __asm__("$2");
    register void *tag2 __asm__("$2");
    register int one4 __asm__("$4"), one9 __asm__("$9"), maximum8 __asm__("$8"), value7 __asm__("$7");
    register int remainder4 __asm__("$4");
    register int *privateState __asm__("$16");
    register int *initialIndices __asm__("$5");
    register int *activeIndices __asm__("$5");
    register int *resetIndices __asm__("$5");
    int hudHandle;
    int resetHudHandle;
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int *table3 __asm__("$3");
    register int initialCount __asm__("$6");
    register int activeCount __asm__("$6");
    register int resetCount __asm__("$6");
    register int state4 __asm__("$4");
    unsigned char state;

    state = owner->state;
    privateState = owner->mobyTag;
    if (state == 0) {
        owner->state = 1;
        return;
    }
    initialCount = 0;
    if (state == 1) {
        one4=1;
        __asm__("" : "=r"(one4) : "0"(one4));
        initialIndices = privateState;
        do {
            index3=*initialIndices;
            __asm__("" : "=r"(index3) : "0"(index3));
            offset2=index3*11;
            initialMoby=D_8006C550;
            __asm__("" : "=r"(initialMoby) : "0"(initialMoby), "r"(offset2));
            initialMoby=(Moby*)((unsigned char*)initialMoby+(offset2<<3));
            __asm__("" : "=r"(initialMoby) : "0"(initialMoby));
            if (!(initialMoby->state & 0x80)) {
                tag2=initialMoby->mobyTag;
                __asm__("" : "=r"(tag2) : "0"(tag2));
                initialMoby->updateDistance = one4;
                initialMoby->lowDrawDistance = one4;
                P86DD8_FIELD(unsigned char,*(void**)tag2,0x4A) = one4;
                P86DD8_FIELD(unsigned char,*(void**)initialMoby->mobyTag,0x4C) = one4;
            }
            initialCount += 1;
            initialIndices += 1;
        } while (initialCount < 6);
        owner->updateDistance = 0x10;
        owner->state = 2;
        return;
    }
    if (((P86DD8End - 1) == D_level_46_80091B40) && (D_8006C774 != 0)) {
        work2=rand();
        __asm__("" : "=r"(work2) : "0"(work2) : "$12");
        remainder4=work2/27;
        __asm__("" : "=r"(remainder4) : "0"(remainder4), "r"(work2));
        work3=remainder4*27;
        remainder4=work2-work3;
        __asm__("" : "=r"(remainder4) : "0"(remainder4));
        table3=P86DD8Table;
        __asm__("" : "=r"(table3) : "0"(table3), "r"(remainder4));
        work2=remainder4*4;
        tableEntry4=(int*)(work2+(int)table3);
        __asm__("" : "=r"(tableEntry4) : "0"(tableEntry4));
        work3=*tableEntry4;
        if(work2+0x49<work3) {
            work2=work3-1;
            __asm__("" : "=r"(work2) : "0"(work2));
            *tableEntry4=work2;
        }
    }
    if ((func_80036220(&D_80070328.position, (unsigned char*)privateState+0x20, 0, 0x2800) != 0) && (func_80036220(&D_80070328.position, (unsigned char*)privateState+0x38, 0, 0x2800) == 0)) {
        activeCount=0;
        __asm__("" : "=r"(activeCount) : "0"(activeCount) : "$9");
        P86DD8_FIELD(int,privateState,0x1C) = 0;
        one9=1;maximum8=0xFF;
        __asm__("" : : "r"(one9), "r"(maximum8) : "$7");
        value7=0x30;
        __asm__("" : : "r"(one9), "r"(maximum8), "r"(value7));
        activeIndices = privateState;
        do {
            index3=*activeIndices;
            __asm__("" : "=r"(index3) : "0"(index3));
            offset2=index3*11;
            activeMoby=D_8006C550;
            __asm__("" : "=r"(activeMoby) : "0"(activeMoby), "r"(offset2));
            activeMoby=(Moby*)((unsigned char*)activeMoby+(offset2<<3));
            __asm__("" : "=r"(activeMoby) : "0"(activeMoby));
            state4 = activeMoby->state;
            if ((state4 & 0x80) || (state4 == one9)) {
                P86DD8_FIELD(int,privateState,0x1C) = (int) (P86DD8_FIELD(int,privateState,0x1C) + 1);
            } else {
                tag2=activeMoby->mobyTag;
                __asm__("" : "=r"(tag2) : "0"(tag2));
                activeMoby->updateDistance = maximum8;
                activeMoby->lowDrawDistance = value7;
                P86DD8_FIELD(unsigned char,*(void**)tag2,0x4A) = maximum8;
                P86DD8_FIELD(unsigned char,*(void**)activeMoby->mobyTag,0x4C) = value7;
            }
            activeCount += 1;
            activeIndices += 1;
        } while (activeCount < 6);
        if (P86DD8_FIELD(int,privateState,0x1C) == 6) {
            hudHandle = P86DD8_FIELD(int,privateState,0x18);
            if (hudHandle != 0) {
                func_80028154(hudHandle);
                P86DD8_FIELD(int,privateState,0x18) = 0;
                func_80055B18(owner);
            }
        } else if (P86DD8_FIELD(int,privateState,0x18) == 0) {
            P86DD8_FIELD(int,privateState,0x18) = (short) func_8002803C(0x17, 0x1CE, func_80027EE4, func_80027A60, func_80029AA0, (int*)((unsigned char*)privateState+0x1C), 6);
        }
    } else {
        resetHudHandle = P86DD8_FIELD(int,privateState,0x18);
        if (resetHudHandle != 0) {
            func_80028154(resetHudHandle);
            P86DD8_FIELD(int,privateState,0x18) = 0;
            resetCount = 0;
            one4=1;
            __asm__("" : "=r"(one4) : "0"(one4));
            resetIndices = privateState;
            do {
                index3=*resetIndices;
            __asm__("" : "=r"(index3) : "0"(index3));
            offset2=index3*11;
            resetMoby=D_8006C550;
            __asm__("" : "=r"(resetMoby) : "0"(resetMoby), "r"(offset2));
            resetMoby=(Moby*)((unsigned char*)resetMoby+(offset2<<3));
            __asm__("" : "=r"(resetMoby) : "0"(resetMoby));
                if (!(resetMoby->state & 0x80)) {
                    tag2=resetMoby->mobyTag;
                __asm__("" : "=r"(tag2) : "0"(tag2));
                resetMoby->updateDistance = one4;
                    resetMoby->lowDrawDistance = one4;
                    P86DD8_FIELD(unsigned char,*(void**)tag2,0x4A) = one4;
                    P86DD8_FIELD(unsigned char,*(void**)resetMoby->mobyTag,0x4C) = one4;
                }
                resetCount += 1;
                resetIndices += 1;
            } while (resetCount < 6);
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_46/moby", func_level_46_80087164);

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * The original 401 instructions in each copy are the acceptance authority.
 * Preserve the 0x90-byte frame, signed table loads, byte offsets, wrapped
 * 32-bit products, arithmetic shifts, helper order and descriptor updates.
 * Empty constraints emit no opcodes and preserve original allocation/order.
 * Table meanings, physical units, full helper contracts and caller cadence
 * remain unresolved. No retail runtime completeness is claimed.
 * Falsifiable check: original linked words and every full retail binary hash.
 */
#define Actor84070Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor84070func_8001BA30() __asm__("func_8001BA30");
int Actor84070func_8003636C() __asm__("func_8003636C");
int Actor84070func_8004F194() __asm__("func_8004F194");
int Actor84070func_80050B00() __asm__("func_80050B00");
int Actor84070func_80050B88() __asm__("func_80050B88");
int Actor84070func_80055B18() __asm__("func_80055B18");
extern short Actor84070D_80065920[] __asm__("D_80065920");
extern short Actor84070D_800658A0[] __asm__("D_800658A0");
extern void* (*Actor84070SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_46_80087AE8(void *input) {
    register unsigned char *owner __asm__("$23")=input;
    struct {
        int sp18,sp1C,sp20,pad24,sp28,sp2C,sp30,pad34,sp38,pad3C;
        void *sp40;
        int pad44,sp48,pad4C;
        volatile short * volatile sp50;
        void * volatile sp54;
        volatile int sp58;
        short * volatile sp5C;
        void *sp60;
        int pad64;
    } frame;
    register short *table659 __asm__("$7");
    register short *table659Cursor __asm__("$21");
    register short *table658Cursor __asm__("$22");
    register short *shiftedTable659 __asm__("$10");
    register int value6 __asm__("$6");
    register int temp_a2_2 __asm__("$6");
    register int initialCondition __asm__("$2");
    int temp_v0_2;
    register int value3 __asm__("$3");
    register int temp_v1_3 __asm__("$3");
    register int temp_v1_4 __asm__("$3");
    register int *ownerWord0C __asm__("$16");
    register int value4 __asm__("$4");
    int temp_a0_3;
    register int value5 __asm__("$5");
    register int randomResult __asm__("$2");
    register int temp_v0_5 __asm__("$2");
    int temp_v0_6;
    register int scaledTable659 __asm__("$3");
    register int nextIndex8 __asm__("$3");
    register int nextIndex9 __asm__("$3");
    register int radiusWord __asm__("$4");
    register int innerIndex __asm__("$17");
    register int pointIndex __asm__("$18");
    register int columnCounter __asm__("$18");
    register int outerIndex __asm__("$19");
    register int descriptorCount __asm__("$19");
    register int tableByteOffset __asm__("$9");
    int var_v0;
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    register int nextDescriptorIndex __asm__("$5");
    register int descriptorFlag __asm__("$3");
    register int descriptorIndex __asm__("$17");
    register int headerValue __asm__("$3");
    register int temp_v0_3 __asm__("$2");
    void *createdPart;
    register void *state __asm__("$20");
    void *previousPart;
    register void *descriptorCursor __asm__("$4");
    short *table658;
    register int work2 __asm__("$2");
    int work12;
    int initialWord;
    register int work3 __asm__("$3");
    register short *raw2 __asm__("$2");
    register int product13 __asm__("$13");
    register int value12 __asm__("$12");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    register void *pointCursor __asm__("$16");
    register void *headerBytes __asm__("$8");
    register void *pointRecords __asm__("$11");

    __asm__("" : "=r"(owner) : "0"(owner));
    state = Actor84070Field(owner, void **, 0);
    frame.sp38 = *Actor84070Field(state, int **, 0x10);
    Actor84070Field(owner, unsigned char *, 0x41) = 0;
    Actor84070Field(owner, unsigned char *, 0x4C) = 0;
    Actor84070Field(owner, unsigned char *, 0x4D) = 0;
    initialCondition=Actor84070Field(state,short*,2);
    if (initialCondition != 0) {
        initialCondition=initialCondition<10;
        goto initialBound;
    }
    initialCondition=initialCondition<10;
    __asm__("" : "=r"(initialCondition) : "0"(initialCondition));
    ownerWord0C=owner+12;
    Actor84070func_8001BA30(ownerWord0C,1000,1,0,0x40000,owner);
    initialCondition=Actor84070Field(state,short*,2);
    if (initialCondition != 0) {
        initialCondition=initialCondition<10;
        goto initialBound;
    }
    initialCondition=initialCondition<10;
    __asm__("" : "=r"(initialCondition) : "0"(initialCondition));
    Actor84070SpawnParticle(10,70,ownerWord0C,(void*)30);
    initialCondition=Actor84070Field(state,short*,2)<10;
initialBound:
    if (initialCondition) {
        randomResult=Actor84070func_8003636C(0,0x400);
        value3=Actor84070Field(owner,int*,0xC)-0x200;
        __asm__("" : "=r"(value3) : "0"(value3));
        value3+=randomResult;
        __asm__("" : "=r"(value3) : "0"(value3));
        frame.sp18=value3;
        randomResult=Actor84070func_8003636C(0,0x400);
        value3=Actor84070Field(owner,int*,0x10)-0x200;
        __asm__("" : "=r"(value3) : "0"(value3));
        value3+=randomResult;
        __asm__("" : "=r"(value3) : "0"(value3));
        frame.sp1C=value3;
        randomResult=Actor84070func_8003636C(0,0x100);
        value3=Actor84070Field(owner,int*,0x14);
        value3+=randomResult;
        frame.sp20=value3;
        Actor84070SpawnParticle(2, 0x42, &frame.sp18, (int *)1);
    }
    pointIndex = 0;
    outerIndex = 0;
    table659 = &Actor84070D_80065920;
    table658=Actor84070D_800658A0;
    __asm__("" : "=r"(table658) : "0"(table658));
    pointRecords = Actor84070Field(state, void **, 4);
    __asm__("" : "=r"(work2),"=r"(work3),"=r"(value4),"=r"(value5),"=r"(value6),"=r"(tableByteOffset),"=r"(shiftedTable659));
    initialWord=Actor84070Field(state,short*,0);
    headerBytes=pointRecords+0x604;
    __asm__("" : "=r"(initialWord) : "0"(initialWord),"r"(work2),"r"(work3),"r"(value4),"r"(value5),"r"(value6),"r"(tableByteOffset),"r"(shiftedTable659),"r"(headerBytes));
    frame.sp48=initialWord;
    initialWord=(int)pointRecords+0x644;
    __asm__("" : "=r"(initialWord) : "0"(initialWord),"r"(work2),"r"(work3),"r"(value4),"r"(value5),"r"(value6),"r"(tableByteOffset),"r"(shiftedTable659),"r"(headerBytes));
    frame.sp40=(void*)initialWord;
    do {
        innerIndex = 0;
        work2=outerIndex<<5;
        __asm__("" : "=r"(work2) : "0"(work2));
        tableByteOffset=work2&0x1E0;
        shiftedTable659 = (short*)(tableByteOffset + (int)table659);
        table658Cursor = table658;
        table659Cursor = table659;
        work2=pointIndex*12;
        __asm__("" : "=r"(work2) : "0"(work2));
        pointCursor = (void*)(work2+(int)pointRecords);
loop_7:
        value3 = Actor84070Field(state, short *, 2);
        if (value3 != 0) {
            if (value3 == 1) {
                radiusWord = 0x190;
                goto block_14;
            }
            if (!(innerIndex & 1)) goto frameRadius;
            work2=value3<4;
            __asm__("" : "=r"(work2) : "0"(work2));
            if (!work2) {
                radiusWord=0x1F4;
                goto block_14;
            }
frameRadius:
            radiusWord=frame.sp48;
            frame.sp28=0;
        } else {
            radiusWord = 0x1F4;
block_14:
            frame.sp28 = 0;
        }
        work2=*table659Cursor;
        __asm__("" : "=r"(work2) : "0"(work2));
        value12=work2*radiusWord;
        __asm__("" : "=r"(value12) : "0"(value12));
        scaledTable659=value12>>12;
        frame.sp2C=scaledTable659;
        work2=*table658Cursor;
        __asm__("" : "=r"(work2) : "0"(work2));
        value12=work2*radiusWord;
        __asm__("" : "=r"(value12) : "0"(value12));
        work2=value12>>12;
        __asm__("" : "=r"(work2) : "0"(work2));
        frame.sp30=work2;
        raw2=(short*)(tableByteOffset+(int)table658);
        __asm__("" : "=r"(raw2) : "0"(raw2));
        work2=*raw2;
        __asm__("" : "=r"(work2) : "0"(work2));
        value12=scaledTable659*work2;
        __asm__("" : "=r"(value12) : "0"(value12));
        work2=(-value12)>>12;
        __asm__("" : "=r"(work2) : "0"(work2));
        Actor84070Field(pointCursor,int*,0)=work2;
        temp_v1_3=*shiftedTable659;
        work2=frame.sp2C;
        __asm__("" : "=r"(temp_v1_3),"=r"(work2) : "0"(temp_v1_3),"1"(work2));
        value12=work2*temp_v1_3;
        __asm__("" : "=r"(value12) : "0"(value12));
        work2=value12>>12;
        __asm__("" : "=r"(work2) : "0"(work2));
        Actor84070Field(pointCursor,int*,4)=work2;
        value4=frame.sp30;
        Actor84070Field(pointCursor, int *, 8) = value4;
        if (Actor84070Field(owner, int *, 0x44) & 0xFF00FF) {
            work2=Actor84070Field(owner,unsigned char*,0x44);
            __asm__("" : "=r"(work2) : "0"(work2));
            work3=work2<<1;
            __asm__("" : "=r"(work3) : "0"(work3));
            raw2=(short*)(work3+(int)table659);
            value6=*raw2;
            __asm__("" : "=r"(value6) : "0"(value6));
            work2=Actor84070Field(pointCursor,int*,0);
            __asm__("" : "=r"(work2) : "0"(work2));
            work2=work2*value6;
            work3=work3+(int)table658;
            __asm__("" : "=r"(work2),"=r"(work3) : "0"(work2),"1"(work3));
            temp_v1_3=*(short*)work3;
            __asm__("" : "=r"(temp_v1_3) : "0"(temp_v1_3));
            product13=value4*temp_v1_3;
            __asm__("" : "=r"(product13) : "0"(product13));
            value4=work2-product13;
            __asm__("" : "=r"(value4) : "0"(value4));
            value4 >>= 12;
            frame.sp28=value4;
            value5=Actor84070Field(pointCursor,int*,4);
            frame.sp2C=value5;
            work2=Actor84070Field(pointCursor,int*,0);
            __asm__("" : "=r"(work2) : "0"(work2));
            work3=work2*temp_v1_3;
            __asm__("" : "=r"(work3) : "0"(work3));
            work2=Actor84070Field(pointCursor,int*,8);
            __asm__("" : "=r"(work2) : "0"(work2));
            product13=work2*value6;
            __asm__("" : "=r"(product13) : "0"(product13));
            work2=(work3+product13)>>12;
            frame.sp30=work2;
            work2=(Actor84070Field(owner,unsigned char*,0x46)+128)&255;
            __asm__("" : "=r"(work2) : "0"(work2));
            work3=work2<<1;
            __asm__("" : "=r"(work3) : "0"(work3));
            raw2=(short*)(work3+(int)table659);
            value6=*raw2;
            __asm__("" : "=r"(value6) : "0"(value6));
            work2=value4*value6;
            work3=work3+(int)table658;
            __asm__("" : "=r"(work2),"=r"(work3) : "0"(work2),"1"(work3));
            temp_v1_3=*(short*)work3;
            __asm__("" : "=r"(temp_v1_3) : "0"(temp_v1_3));
            product13=value5*temp_v1_3;
            __asm__("" : "=r"(product13) : "0"(product13));
            work2=(work2-product13)>>12;
            Actor84070Field(pointCursor,int*,0)=work2;
            work2=frame.sp28;
            __asm__("" : "=r"(work2) : "0"(work2));
            work3=work2*temp_v1_3;
            __asm__("" : "=r"(work3) : "0"(work3));
            work2=frame.sp2C;
            __asm__("" : "=r"(work2) : "0"(work2));
            product13=work2*value6;
            __asm__("" : "=r"(product13) : "0"(product13));
            work2=(work3+product13)>>12;
            Actor84070Field(pointCursor,int*,4)=work2;
            __asm__ __volatile__("" ::: "memory");
            work2=frame.sp30;
            __asm__("" : "=r"(work2) : "0"(work2));
            Actor84070Field(pointCursor,int*,8)=work2;
        }
        call4=pointCursor;call5=owner+12;call6=pointCursor;
        __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));
        frame.sp50=table659;frame.sp54=headerBytes;frame.sp58=tableByteOffset;frame.sp5C=shiftedTable659;frame.sp60=pointRecords;
        Actor84070func_8004F194(call4,call5,call6);
        pointCursor += 0xC;
        pointIndex += 1;
        table658Cursor += 0x10;
        innerIndex += 1;
        work2=innerIndex<8;
        __asm__("" : "=r"(work2) : "0"(work2));
        table659=(short*)frame.sp50;headerBytes=frame.sp54;tableByteOffset=frame.sp58;shiftedTable659=frame.sp5C;pointRecords=*(void * volatile *)&frame.sp60;
        __asm__("" : "=r"(table659Cursor) : "0"(table659Cursor),"r"(pointRecords));
        table659Cursor += 0x10;
        if (work2) {
            goto loop_7;
        }
        outerIndex += 1;
    } while (outerIndex < 0x10);
    Actor84070Field(pointRecords, int *, 0x600) = -1;
    value3=Actor84070Field(state,short*,2);
    __asm__("" : "=r"(value3) : "0"(value3));
    work2=(value3<<1)+value3;
    __asm__("" : "=r"(work2) : "0"(work2));
    work2=(work2<<2)+value3;
    value3=255;
    __asm__("" : "=r"(work2),"=r"(value3) : "0"(work2),"1"(value3));
    headerValue=value3-work2;
    __asm__("" : "=r"(headerValue) : "0"(headerValue));
    work2=8;
    __asm__("" : "=r"(work2) : "0"(work2));
    if (headerValue != work2) {
        work2=headerValue<5;
        goto descriptorBound;
    }
    work2=headerValue<5;
    __asm__("" : "=r"(work2) : "0"(work2));
    headerValue=15;
    __asm__("" : "=r"(headerValue) : "0"(headerValue));
    work2=headerValue<5;
descriptorBound:
    descriptorIndex=0;
    if (work2) headerValue=5;
    columnCounter = 0;
    descriptorCount = 0;
    descriptorCursor = frame.sp40;
    Actor84070Field(headerBytes, unsigned char *, 0) = headerValue;
    Actor84070Field(headerBytes, unsigned char *, 1) = headerValue;
    Actor84070Field(headerBytes, unsigned char *, 2) = 0;
    Actor84070Field(headerBytes, unsigned char *, 4) = 0xFF;
    Actor84070Field(headerBytes, unsigned char *, 5) = 0xFF;
    Actor84070Field(headerBytes, unsigned char *, 6) = 0xFF;
    do {
        nextIndex8 = descriptorIndex + 8;
        var_v0_3 = nextIndex8;
        nextDescriptorIndex = descriptorIndex + 1;
        Actor84070Field(descriptorCursor, unsigned char *, 0) = descriptorIndex;
        Actor84070Field(descriptorCursor, unsigned char *, 1) = nextDescriptorIndex;
        if (nextIndex8 < 0) {
            var_v0_3 = descriptorIndex + 0x87;
        }
        work2=nextIndex8 - ((var_v0_3 >> 7) << 7);
        __asm__("" : "=r"(work2) : "0"(work2));
        Actor84070Field(descriptorCursor, unsigned char *, 2) = work2;
        nextIndex9 = descriptorIndex + 9;
        var_v0_4 = nextIndex9;
        if (nextIndex9 < 0) {
            var_v0_4 = descriptorIndex + 0x88;
        }
        descriptorIndex=nextDescriptorIndex;
        __asm__("" : "=r"(descriptorIndex) : "0"(descriptorIndex));
        work2=nextIndex9 - ((var_v0_4 >> 7) << 7);
        __asm__("" : "=r"(work2) : "0"(work2));
        Actor84070Field(descriptorCursor, unsigned char *, 3) = work2;
        work2=Actor84070Field(state,short*,2);
        __asm__("" : "=r"(columnCounter) : "0"(columnCounter),"r"(work2));
        columnCounter+=1;
        descriptorFlag=work2<4;
        __asm__("" : "=r"(descriptorFlag) : "0"(descriptorFlag));
        Actor84070Field(descriptorCursor, unsigned char *, 4) = descriptorFlag;
        Actor84070Field(descriptorCursor, unsigned char *, 5) = descriptorFlag;
        Actor84070Field(descriptorCursor, unsigned char *, 6) = descriptorFlag;
        Actor84070Field(descriptorCursor, unsigned char *, 7) = descriptorFlag;
        if (columnCounter >= 7) {
            descriptorIndex += 1;
            columnCounter = 0;
        }
        descriptorCount += 1;
        descriptorCursor += 8;
    } while (descriptorCount < 0x70);
    value12=(int)frame.sp40;
    Actor84070Field((void*)value12,int*,0x380)=-1;
    if (Actor84070Field(state, int *, 8) == 0) {
        call4=pointRecords;call5=headerBytes;
        call6=frame.sp40;
        value12=frame.sp38;
        Actor84070Field(state,int*,8)=Actor84070func_80050B00(call4,call5,call6,value12+12,1);
    }
    if (Actor84070Field(state, short *, 2) >= 7) {
        Actor84070Field(state, void **, 0xC) = 0;
    } else {
        frame.sp28 = 0;
        frame.sp2C = 0x28;
        frame.sp30 = 0;
        temp_v0_6 = Actor84070func_8003636C(0, 0x14) + 0x36;
        frame.sp2C = (int) (Actor84070D_80065920[temp_v0_6] * 5) >> 9;
        frame.sp30 = (int) (Actor84070D_800658A0[temp_v0_6] * 5) >> 9;
        createdPart = Actor84070SpawnParticle(1, 0xD, owner + 0xC, &frame.sp28);
        previousPart = Actor84070Field(state, void **, 0xC);
        if (previousPart != 0) {
            Actor84070Field(previousPart, unsigned char *, 0xC) = 0xFF;
            Actor84070Field(previousPart, unsigned char *, 0xD) = 0xFF;
            Actor84070Field(previousPart, unsigned char *, 0xE) = 0xFF;
        }
        if (createdPart != 0) {
            Actor84070Field(state, void **, 0xC) = createdPart;
            Actor84070Field(createdPart, unsigned char *, 0xA) = 0xBE;
            Actor84070Field(createdPart, unsigned char *, 0xE) = 0xFF;
        }
    }
    Actor84070Field(state, short *, 2) = (short) ((unsigned short) Actor84070Field(state, short *, 2) + 1);
    Actor84070Field(state, short *, 0) = (short) ((unsigned short) Actor84070Field(state, short *, 0) + 0x50);
    if (Actor84070Field(state,short*,2) < 21) {
        value12=0;
        __asm__("" : "=r"(value12) : "0"(value12));
        if (!value12) goto done;
    }
    {
        temp_a0_3 = Actor84070Field(state, int *, 8);
        if (temp_a0_3 != 0) {
            Actor84070func_80050B88(temp_a0_3);
        }
        Actor84070func_80055B18(owner);
    }
done:
    ;
}

#undef Actor84070Field
