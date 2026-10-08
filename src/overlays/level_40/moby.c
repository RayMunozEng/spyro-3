#include "common.h"
#include "camera.h"
#include "savepoint.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "mobyutil.h"
#include "spyro.h"
extern void func_80039714(Moby*);

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
void func_level_40_800749B0(void *input) {
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
void func_level_40_8007560C(Moby* argument) {
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
void func_level_40_80075C98(void *input) {
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
void func_level_40_800771E8(Moby* moby) {
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
void func_level_40_800774A8(Moby* argument) {
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
void func_level_40_800779C8(Moby *moby) {
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


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
extern unsigned char Controller78288D_80066FD3[] __asm__("D_80066FCC+7");
extern unsigned char Controller78288D_80070300[] __asm__("D_80070300");
extern unsigned char Controller78288D_80071598 __asm__("D_80071598");
extern int Controller78288D_8006C5BC __asm__("D_8006C5BC");
extern int Controller78288D_8006C73C __asm__("D_8006C73C");
int Controller78288ActivateSparxPowers() __asm__("ActivateSparxPowers");
int Controller78288Helper584BC() __asm__("func_800584BC");
extern unsigned char Controller78288D_80071FB0[] __asm__("D_80071FB0");
extern int Controller78288D_8006C660 __asm__("D_8006C660");
extern int Controller78288D_8006C71C __asm__("D_8006C71C");
extern int Controller78288D_80065820 __asm__("D_80065820");
void func_level_40_80077CCC(void *input) {
    struct { struct {int x,y,z;} first; int p24; struct {int x,y,z;} second; int p34; struct {int x,y,z;} third; int p44; struct {int x,y,z;} fourth; int p54; int originalExtra58[2]; } frame;
    register int kind __asm__("$3");
    register int prefixKind3 __asm__("$3");
    register int three2 __asm__("$2");
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
    register int ownerPositionWord __asm__("$17");
    register int phaseResult __asm__("$16");
    register int distanceResult __asm__("$20");
    register int colourChannel __asm__("$2");
    int heightDelta;
    int heightResult;
    int ownerHeight;
    register int ownerIndex __asm__("$3");
    register int clampTest __asm__("$2");
    register int scaledDistance __asm__("$3");
    register int tagKind __asm__("$3");
    register int savedSelector __asm__("$17");
    unsigned char state;
    unsigned char substate;
    register int stateValue __asm__("$2");
    register int nextSubstate __asm__("$2");
    void *indexedOwner;
    register unsigned char *prefixTag __asm__("$16");
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
                    three2=3;
                    __asm__("" : "=r"(three2) : "0"(three2) : "$3");
                    prefixKind3=Controller78288Field(prefixTag,unsigned char*,0);
                    if(prefixKind3==three2)goto checkPrefixFlags;
                    three2=12;
                    __asm__("" : "=r"(three2),"=r"(prefixKind3) : "0"(three2),"1"(prefixKind3));
                    if(prefixKind3==three2) {
                        three2=3;
                        goto compareOriginalPrefix;
                    }

                    Controller78288Field(tag, unsigned char *, 2) = 0U;
                }
                }
                prefixKind3=Controller78288Field(prefixTag,unsigned char*,0);
                three2=3;
compareOriginalPrefix:
                if(prefixKind3==three2) {
checkPrefixFlags:
                    {register int raw3 __asm__("$3");
                     register int raw4 __asm__("$4");
                     register int raw2 __asm__("$2");
                     raw4=Controller78288D_8006C5BC;
                     raw2=Controller78288D_80070300[Controller78288D_80066FD3[raw4]];
                     __asm__("" : "=r"(raw2),"=r"(raw4) : "0"(raw2),"1"(raw4) : "$3");
                     raw3=(int)Controller78288D_80066FD3;
                     __asm__("" : "=r"(raw3),"=r"(raw4) : "0"(raw3),"1"(raw4));
                     raw2&=1;
                     if(raw2==0)goto removeController;
                     raw2=raw3+raw4;
                     __asm__("" : "=r"(raw2) : "0"(raw2));
                     raw2=Controller78288D_80070300[Controller78288Field((void*)raw2,unsigned char*,-9)]&1;
                     if(raw2==0)goto removeController;
                    }
                }
                else if(prefixKind3==12) {
                    if(Controller78288D_80071FB0[Controller78288D_80066FD3[0x2B]]!=0)goto removeController;
                    if(!(Controller78288D_80070300[Controller78288D_80066FD3[0x28]]&1))goto removeController;
                    if((Controller78288D_8006C660>=149) && (Controller78288D_8006C71C>=15000))goto removeController;
                }
                if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                    {register int rawOne4 __asm__("$4")=1;
                     register int rawKind3 __asm__("$3");
                     register int nine2 __asm__("$2");
                     __asm__("" : "=r"(rawOne4) : "0"(rawOne4) : "$3");
                     rawKind3=Controller78288Field(prefixTag,unsigned char*,0);
                     __asm__("" : "=r"(rawKind3) : "0"(rawKind3) : "$2");
                     nine2=3;
                     __asm__("" : "=r"(rawOne4),"=r"(rawKind3),"=r"(nine2) : "0"(rawOne4),"1"(rawKind3),"2"(nine2));
                     Controller78288Field(prefixTag,unsigned char*,5)=rawOne4;
                    if(rawKind3==nine2) {
                        if((Controller78288D_8006C73C==48) && (Controller78288D_80071598==0))goto storeOriginalLowering;
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
                  if(address) Controller78288Field(prefixTag,unsigned char*,5)=0;
                }
                        goto storeOriginalLowering;
                    } else {
                        nine2=12;
                        __asm__("" : "=r"(nine2),"=r"(rawKind3) : "0"(nine2),"1"(rawKind3));
                        if(rawKind3==nine2)Controller78288Field(prefixTag,unsigned char*,5)=rawOne4;
                    }
                    }
storeOriginalLowering:
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
removeController:
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
            if((Controller78288Field(prefixTag,unsigned char*,0)==12) && (Controller78288D_8006C71C>=15000) && (Controller78288D_8006C660>=149)) {
                Controller78288Field(tag,unsigned char*,2)=0;
            }
                    if (Controller78288Helper37BBC(owner, 0xC) != 0) {
                        if(Controller78288Field(prefixTag,unsigned char*,0)==3) {
                            if(Controller78288D_80070300[Controller78288D_80066FD3[0x29]]&1) {
                                register unsigned char *flag3 __asm__("$3")=&Controller78288D_80071598;
                                if(*flag3)Controller78288Field(prefixTag,unsigned char*,2)=1;
                                else {
                                    Controller78288Field(prefixTag,unsigned char*,2)=2;
                                    *flag3=1;
                                    Controller78288ActivateSparxPowers();
                                }
                            } else Controller78288Field(prefixTag,unsigned char*,2)=0;
                        }
                        Controller78288Helper512E4(owner, 0, 0);
                        {register int diff __asm__("$4")=Controller78288D_8006C550;
                         register int product __asm__("$3");
                         register int bank __asm__("$2");
                         register int address5 __asm__("$5");
                         __asm__("" : "=r"(diff) : "0"(diff));
                         diff=(int)owner-diff;product=-(diff*0x45D1745D);product>>=3;
                         __asm__("" : "=r"(product) : "0"(product) : "$2");
                         bank=Controller78288D_8006C79C;
                         __asm__("" : "=r"(bank) : "0"(bank) : "$4");
                         diff=(int)Controller78288D_80071AB0;
                         product+=bank;
                         address5=(product>>5)*4;
                         __asm__("" : "=r"(address5),"=r"(product),"=r"(diff) : "0"(address5),"1"(product),"2"(diff) : "$2");
                         bank=Controller78288D_8006C58C;
                         product&=31;
                         bank<<=5;bank+=diff;address5+=bank;
                         bank=1;diff=*(int*)address5;
                         bank<<=product;diff|=bank;
                         *(int*)address5=diff;
                        }
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
            if(Controller78288D_8006E344==1)goto clearExtraHandle;
            prefixKind3=Controller78288Field(prefixTag,unsigned char*,0);
            if(prefixKind3==3) {
                three2=Controller78288Field(prefixTag,unsigned char*,2);
                if(three2==prefixKind3)Controller78288Helper584BC(4,Controller78288D_8006C5BC+8);
                goto storeOriginalTagOne;
            }
            if(prefixKind3!=12)goto setSubstateFour;
            if((Controller78288Field(prefixTag,unsigned char*,4)==0) && (Controller78288D_8006C71C<15000)) {
                if(Controller78288D_80065820!=0) {
                    Controller78288Field(prefixTag,unsigned char*,2)=1;
                    goto storeOriginalTagOne;
                }
                Controller78288Field(prefixTag,unsigned char*,2)=2;
            } else {
                Controller78288Field(prefixTag,unsigned char*,2)=0;
            }
storeOriginalTagOne:
            Controller78288Field(tag,unsigned char*,2)=1;
            goto setSubstateFour;

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
void func_level_40_80078B20(Moby* moby) {
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
void func_level_40_80078F50(Moby* moby) {
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
void func_level_40_800792B8(Moby* owner) {
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

typedef struct { unsigned char reserved00, gateIndex, phase, reserved03[2], active; unsigned char reserved06[0x22]; int linkedIndex, tollIndex, targetIndex; } DecodedDialogueGateTag;
extern short DecodedDialogueGateThreshold[] __asm__("D_80066EAC");
extern short DecodedDialogueGatePaid[] __asm__("D_80066EAE");
extern unsigned char DecodedDialogueGateLevel __asm__("D_80066FCC + 0x2F");
extern unsigned char DecodedDialogueGateLevelFlags[] __asm__("D_80070300");
extern int D_8006C71C, D_8006C640, D_8006E344;
extern unsigned char D_80071584;
extern Moby* D_8006C550;
void DecodedDialogueGateTarget(int,int,int) __asm__("func_80021ED8");
int DecodedDialogueGateQuery(Moby*,int) __asm__("func_80037BBC");
void DecodedDialogueGateBegin(Moby*,int,int) __asm__("func_800512E4");
void func_level_40_80079444(Moby* moby) {
    DecodedDialogueGateTag* tag = moby->mobyTag;
    int gate, targetIndex;
    switch (moby->state) {
    case 0:
        gate = tag->gateIndex & 0x7F;
        if (gate != 0x7F && D_8006C71C >= DecodedDialogueGateThreshold[gate * 2]
            && !DecodedDialogueGatePaid[gate * 2]) {
            tag->active = 1;
            tag->gateIndex = 0xFF;
        }
        if (tag->tollIndex != -1 && D_8006C640 < 10) {
            if (DecodedDialogueGatePaid[tag->tollIndex * 2]
                || (DecodedDialogueGateLevelFlags[DecodedDialogueGateLevel] & 1)) {
                if (tag->linkedIndex != -1)
                    ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))->state = 9;
                if (tag->targetIndex != -1) DecodedDialogueGateTarget(tag->targetIndex,0xFC,0);
                func_80055B18(moby);
                break;
            }
        }
        if ((tag->linkedIndex != -1 || tag->targetIndex != -1) && tag->phase == 4) {
            if (tag->linkedIndex != -1)
                ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))->state = 9;
            targetIndex = tag->targetIndex;
            tag->linkedIndex = -1;
            if (targetIndex != -1) DecodedDialogueGateTarget(targetIndex,0xFC,0);
            tag->targetIndex = -1;
        }
        if (DecodedDialogueGateQuery(moby,0)) {
            DecodedDialogueGateBegin(moby,0,1);
            moby->state = 1;
        }
        break;
    case 1:
        D_80071584 = 1;
        if (D_8006E344 != 1) {
            moby->state = 0;
            func_80034F40(moby,0);
        }
        break;
    }
}

typedef struct {
    unsigned char reserved00[2],mode,reserved03[2],disabled,reserved06,status;
    unsigned char reserved08[0x18];
    int pendingState,actorIndex;
} DecodedInteractionGate;
extern Moby* D_8006C550;
extern int D_8006E53C,D_8006E344;
int func_80037BBC(Moby*,int);
void func_800512E4(Moby*,int,int);
void func_level_40_80079684(Moby* actor) {
    DecodedInteractionGate* tag=actor->mobyTag;
    unsigned short actorClass;
    if(actor->mobyClass==0x145 && tag->actorIndex!=-1 && D_8006C550[tag->actorIndex].state<0x80)tag->disabled=0xFF;
    actorClass=actor->mobyClass;
    if((unsigned int)(actorClass-0x2AB)<2 || (short)actorClass==0x198 || (short)actorClass==0x2AD)tag->disabled=0xFF;
    switch(actor->state) {
    case 0:
        if(tag->mode==2)tag->disabled=0;
        if(!tag->disabled) {
            if(D_8006E53C&0x10) {
                if(func_80037BBC(actor,0))goto activate;
                tag->status=0;
            }
        }
        if(tag->disabled) {
            if(func_80037BBC(actor,0)) {
 activate:
                func_800512E4(actor,0,0);actor->state=1;
            } else tag->status=0;
        }
        break;
    case 1:
        if(D_8006E344!=actor->state) {
            tag->pendingState=actor->state;actor->state=0;
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_80079810);

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007A638);

/* This caller only reads the signed halfword at tag +0xC. */
typedef struct { unsigned char reserved00[0xC]; short unkC; } DecodedCloneTag;
extern int D_8006C578, D_8006C574;
void func_level_40_8007B2A0(Moby* moby) {
    DecodedCloneTag* tag = moby->mobyTag;
    if (moby->substate == 0 && tag->unkC <= 0) {
        int index;
        moby->substate = 0x70;
        for (index = 0; index < 4; index++) {
            Moby* spawned;
            if (D_8006C578 - D_8006C574 < 0x15) break;
            spawned = func_800391E8(1, moby->mobyClass, moby, 0, 2, 0x40, 0x100);
            if (spawned) {
                spawned->substate = 1;
                spawned->size = 0x7F;
            }
        }
    }
    func_80039714(moby);
}

/* AI-generated reconstruction; not human reviewed. Rev0 original181 words
 * 8007B378..8007B64C. Reuses Rev1 raw264 controller source-local routes and
 * upstream Moby/helper interfaces. Raw tag offsets and access widths remain
 * explicit; target is an absolute coordinate, not a displacement. Signed
 * Y clamp is [-256,256] around anchor. Empty constraints preserve original
 * fresh read order and A2 scheduling; they emit no instructions. Physical
 * units, tag producer, helper/callback effects and cadence remain open. */
typedef struct {
    Vector3D anchor;
    unsigned short reserved0C;
    unsigned char initialized, duration, reserved10[2], step, heading, minDuration, maxDuration, reserved16[2];
    int timer, reserved1C[3], mode;
    unsigned int reserved2C;
    short force, scale;
    unsigned char reserved34[9], direction;
} DecodedRaw264Tag;
extern int D_8006C770;
extern int Raw264PlayerX __asm__("D_80070328");
extern int Raw264PlayerY __asm__("D_80070328+4");
extern unsigned char Raw264PlayerHeading __asm__("D_80070328+0xE");
int Raw264Angle(int,int,int) __asm__("func_8004E880");
int Raw264Direction(int,int,int,int) __asm__("func_800360F8");
int Raw264Random(int,int) __asm__("func_8003636C");
void Raw264Move(Moby*,void*,int) __asm__("func_80037168");
void func_level_40_8007B378(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    register DecodedRaw264Tag* tag __asm__("$17") = moby->mobyTag;
    Vector3D target;
    if (moby->state < 2) {
        if (moby->damageFlags & 0x20000) tag->force = 600;
        else if (moby->damageFlags) tag->force = 350;
        else goto dispatch;
        { int direction = moby->unkb;
        if (!direction) direction = Raw264Direction(Raw264Angle(moby->position.x-Raw264PlayerX,moby->position.y-Raw264PlayerY,0),Raw264PlayerHeading,32,64);
        tag->direction = direction; }
        tag->scale = 256;
        SpawnMoby(16,moby);
        moby->unknownCollision = 0;
        moby->state = 2;
        func_80034F40(moby,2);
    }
dispatch:
    switch(moby->state) {
    case 0:
        if (D_8006C770) {
            tag->timer = Raw264Random(90,300);
            moby->state = 1;
            func_80034F40(moby,1);
        }
        break;
    case 1:
        if (tag->mode) {
            if (!tag->initialized) {
                { int ownerX=moby->position.x;
                __asm__("" : : "r"(ownerX) : "memory");
                if (tag->anchor.x < ownerX) target.x = tag->anchor.x - (tag->step << 4);
                else target.x = tag->anchor.x + (tag->step << 4);
                }
                target.y = tag->anchor.y;
                target.z = tag->anchor.z;
                __asm__("" : : "m"(target) : "memory", "$6");
                tag->heading = Raw264Angle(target.x-moby->position.x,target.y-moby->position.y,0);
                tag->duration = Raw264Random(tag->minDuration,tag->maxDuration);
                tag->initialized = 1;
            }
            Raw264Move(moby,tag,87);
            { int delta = moby->position.y-tag->anchor.y;
              if (delta > 256) moby->position.y = tag->anchor.y+256;
              else if (delta < -256) moby->position.y = tag->anchor.y-256; }
            func_80055D24(moby,4);
        } else Raw264Move(moby,tag,87);
        if (func_800359A4(&tag->timer,4)) {
            moby->state = 0;
            func_80034F40(moby,0);
        }
        break;
    case 2:
        func_80035194(moby,&tag->reserved2C);
        if (D_8006C770) {
            func_80055D24(moby,4);
            func_800369B8(moby,24);
            func_80055B18(moby);
        }
        break;
    }
}

typedef struct { Moby* parent; unsigned char unk4, unk5; } DecodedYawTag;
extern int D_8006C644;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_level_40_8007B64C(Moby* moby) {
    DecodedYawTag* tag = moby->mobyTag;
    if (moby->state != tag->parent->state) func_80055B18(moby);
    else if (moby->animationState.id == 0) moby->angle.yaw += 6;
    else {
        int byteOffset = ((tag->unk5 + D_8006C644) << 3) & 0x1F8;
        int wave = *(short*)((char*)D_80065920 + byteOffset);
        moby->angle.yaw = tag->unk4 + ((wave * 3) >> 9);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007B6FC);

typedef struct {
    int timer;
    Colour* colours;
} DecodedColourFadeTag;
extern int D_8006C648;
void func_80055B18(Moby*);
void func_level_40_8007BCF4(Moby* moby) {
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
void func_level_40_8007BE30(Moby* moby) {
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

extern Moby* D_8006C550;
extern unsigned char D_80071570[];
typedef struct { unsigned char reserved00[0x2C]; int poolIndex; } DecodedPoolSelector;
typedef struct { unsigned char reserved00[0x0C]; int flagOffset; } DecodedPoolFlagSelector;
void func_800584BC(int,int);
void func_80055B18(Moby*);
void func_level_40_8007BFC0(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
    case 0:
        if (D_80071570[((DecodedPoolFlagSelector*)D_8006C550[((DecodedPoolSelector*)D_8006C550[*tag].mobyTag)->poolIndex].mobyTag)->flagOffset]) goto release;
        func_8004F178(&D_8006C550[*tag].position,&moby->position);
        D_8006C550[*tag].position.z += 128;
        D_8006C550[*tag].angle.yaw = moby->angle.yaw;
        func_80055D24(&D_8006C550[*tag],2);
        moby->state = 1;
        break;
    case 1:
        if (D_80071570[((DecodedPoolFlagSelector*)D_8006C550[((DecodedPoolSelector*)D_8006C550[*tag].mobyTag)->poolIndex].mobyTag)->flagOffset]) moby->state = 2;
        break;
    case 2:
        func_800584BC(6,80);
release:
        func_80055B18(moby);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007C1C0);

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007C668);

extern ProgressFlags progressFlags;
extern struct {
	int DAT_80070104; // 80070104
	int DAT_80070108; // 80070108
	int DAT_8007010c; // 8007010c
	int DAT_80070110; // 80070110
	char DAT_80070114; // 80070114
	char DAT_80070115; // 80070115
	short DAT_80070116; // 80070116, maybe char?
	int DAT_80070118; // 80070118
	int DAT_8007011c; // 8007011c
	int DAT_80070120; // 80070120
	Vector3D DAT_80070124; // 80070124, type is a guess
	char DAT_80070130; // 80070130
	char DAT_80070131; // 80070131
	char DAT_80070132; // 80070132
	char DAT_80070133; // 80070133
	short DAT_80070134; // 80070134
	short DAT_80070136; // 80070136
	int DAT_80070138; // 80070138
	int DAT_8007013c; // 8007013c
	int DAT_80070140; // 80070140
	int DAT_80070144; // 80070144
	int DAT_80070148; // 80070148
	short DAT_8007014c; // 8007014c
	char DAT_8007014e; // 8007014e
	char DAT_8007014f; // 8007014f
	int DAT_80070150; // 80070150
	int DAT_80070154; // 80070154
	short DAT_80070158; // 80070158
	short loadLevel; // 8007015a; i.e. to load via vehicle
	int DAT_8007015c; // 8007015c
} D_80070104;
extern int D_8006C598,D_8006C73C,D_8006C528,currentLevel;
extern short D_800658A0[256],D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
extern int Vehicle506Global __asm__("D_80070148");
void func_8005663C(void);
int func_8001A358(Vector3D*,int);
/* AI generated adaptation; not human reviewed. SCUS-94467 level10 8007F0BC. */
typedef struct {int unk0,unk4,unk8;PathTag* path;int timer;} Vehicle546Tag;
extern unsigned char Vehicle546Table[] __asm__("D_80071FB0");
void func_level_40_8007D14C(Moby* arg0) {
    Vector3D sp10,sp20,sp30,sp40,sp50;
    int temp_v1_3,count;
    Vehicle546Tag* mobyTag=(Vehicle546Tag*)arg0->mobyTag;
    switch(arg0->state) {
    case 0:
        switch(arg0->substate) {
        case 0:
            if(progressFlags.lvl20_WhirligigUsable)goto deleteVehicle;
            if(D_8006C73C != 0 && currentLevel != D_8006C73C &&
               ((temp_v1_3=D_8006C73C%10,temp_v1_3==0) || (temp_v1_3==7 && D_8006C73C<60))) {
                arg0->position.z+=0xC00;
                func_800136F0(&camera.unk170,(Vector3D*)mobyTag->path->nodes,&arg0->position);
                camera.unk170.pos.azimuth-=spyro.rotation.yaw;
                camera.unk170.yaw=0;camera.unk170.pitch=0;
                func_8004F178(&spyro.position,&arg0->position);
                spyro.position.z+=spyro.unk4a+0x280;
                func_80012BA8(&camera.unk170);
                func_8004F178(&camera.unk184,&camera.unk60);
                arg0->substate=1;arg0->state=7;
            } else {
                count=eggsCollectedArray[lvlIdToIndex[21]]&1;
                if(eggsCollectedArray[lvlIdToIndex[22]]&1)count++;
                if(eggsCollectedArray[lvlIdToIndex[23]]&1)count++;
                if(eggsCollectedArray[lvlIdToIndex[24]]&1)count++;
                if(eggsCollectedArray[lvlIdToIndex[26]]&1)count++;
                if(count==5) {
                deleteVehicle: func_80055B18(arg0);return;
                }
                if(currentLevel!=10 || Vehicle546Table[lvlIdToIndex[17]]!=0) {
                    arg0->substate=1;arg0->state=3;
                } else {
                    arg0->substate=2;arg0->state=1;arg0->position.z+=0xC00;
                }
                func_80055D24(arg0,2);mobyTag->timer=0;
            }
            break;
        case 1:arg0->state=3;break;
        case 2:
            arg0->position.z+=0xC00;func_80055D24(arg0,2);mobyTag->timer=0;arg0->state=1;break;
        }
        func_8003B7B4(&arg0->substate,1,&unsavedData);
        break;
    case 2:
        arg0->position.z-=64;
        func_8004F178(&sp10,&arg0->position);sp10.z+=512;
        sp10.z=func_8001A358(&sp10,512);
        if(sp10.z!=0) {
            arg0->position.z=sp10.z;arg0->state=3;
            func_8003B7B4(&arg0->state,1,&savedData);
            func_8003B7B4(&arg0->state,1,&unsavedData);arg0->substate=0;
        }
        func_80055D24(arg0,2);break;
    case 3:
        if (spyro.m_StoodOnMoby == arg0) {
            arg0->state = 4;
        case 4:
            if (spyro.m_StoodOnMoby != arg0) {
                camera.unk168 = 0;
                arg0->state = 3;
            } else {
                if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                    Vehicle506Global = 1;
                    func_8005663C();
                    arg0->state = 5;
                }
                func_8004F178(&camera.unk184, &arg0->position);
                func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
                camera.unk170.yaw = 0;
                camera.unk170.pitch = 0;
                camera.unk168 = 0x11;
            }
        }
        break;

    case 5:
        camera.unk168 = 0;
        if (D_80070104.loadLevel != 0) {
            mobyTag->timer = 0x78;
            arg0->state = 6;
        } else {
            arg0->state = 8;
        }
        break;

    case 6:
        arg0->position.z = (int) (arg0->position.z + 0x40);
        spyro.unk17a = 0x10008000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x280;
        spyro.unk18.roll = spyro.bodyRotation.roll;
        spyro.unk18.pitch = spyro.bodyRotation.pitch;
        spyro.unk18.yaw = spyro.bodyRotation.yaw;
        func_8004F178(&camera.unk184, &arg0->position);
        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
        camera.unk170.yaw = 0;
        camera.unk170.pitch = 0;
        camera.unk168 = 0x11;
        if (func_800359A4(&mobyTag->timer, 4) != 0) {
            D_8006C598 += 0x10;
            if (D_8006C598 >= 0xFF) {
                D_8006C598 = 0xFF;
                if ((D_80070104.loadLevel == 0x14) && (eggsCollectedArray[lvlIdToIndex[17]] == 0)) {
                    D_80070104.loadLevel = 0x11;
                }
                // BUG // Spike Bug
                // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                // This was fixed in all later revisions
                if ((D_80070104.loadLevel != 0x11) || (progressFlags.lvl63_BiancaStrikesBack != 0)) {
                    func_80054F94(D_80070104.loadLevel, arg0);
                } else {
                    progressFlags.lvl63_BiancaStrikesBack = 1;
                    func_800584BC(6, 0x3F);
                }
            }
        }
        func_80055D24(arg0, 2);
        break;

    case 7:
        arg0->position.z -= 0x40;
        spyro.unk17a = 0x10008000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x280;
        spyro.unk18.roll = arg0->angle.roll;
        spyro.unk18.pitch = arg0->angle.pitch;
        spyro.unk18.yaw = arg0->angle.yaw;
        func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
        func_8004F178(&sp20, &arg0->position);
        sp20.z += 0x200;
        sp20.z = func_8001A358(&sp20, 0x200);
        if (sp20.z != 0) {
            arg0->position.z = sp20.z;
            func_80013B7C(0);
            arg0->state = 8;
        }
        func_80055D24(arg0, 2);
        break;

    case 8:
        sp30.x = D_80065920[arg0->angle.yaw];
        sp30.y = D_800658A0[arg0->angle.yaw];
        sp30.z = 0;
        func_8004F194(&sp30, &sp30, &arg0->position);
        if (ovlHeader.unk2c(&sp30) != 0) {
            spyro.unk17c = 0;
            ovlHeader.unk2b(&sp30, arg0->angle.yaw, 0);
            mobyTag->timer = 120;
            arg0->state = 9;
        }
        break;

    case 9:
        sp40.x = D_80065920[arg0->angle.yaw];
        sp40.y = D_800658A0[arg0->angle.yaw];
        sp40.z = 0;
        func_8004F194(&sp40, &sp40, &arg0->position);
        if (ovlHeader.unk2b(&sp40, arg0->angle.yaw, 0) != 0) {
            func_8004F178(&sp50, &spyro.position);
            sp50.z -= spyro.unk4a;
            func_8003B634(&savedData, &sp50, spyro.bodyRotation.yaw);
            arg0->state = 3;
        }
        break;


    }
}


/* AI generated adaptation; not human reviewed. Original SCUS-94467 level10 8007F944. */
typedef struct {int unk0;PathTag* path;int timer;} Vehicle635Tag;
extern Moby* Vehicle635Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*,int);
void func_level_40_8007D9D4(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3;
    Vehicle635Tag* mobyTag;

    mobyTag = (Vehicle635Tag*)arg0->mobyTag;
    switch (arg0->state) {

    case 0:
        switch (arg0->substate) {
        case 0:
            if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                func_80055B18(arg0);
                return;
            }
            else {
                arg0->state=1;
                if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) && ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) || ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) && (arg0->mobyClass == D_8006C528) && D_8006C73C !=47) {
                    func_80034F80(arg0,2);
                    arg0->position.z += 0xC00;
                    func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
                    camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                    camera.unk170.yaw = 0;
                    camera.unk170.pitch = 0;
                    spyro.unk17a = 0x1001A000;
                    spyro.unk20[1] = 0;
                    func_8004F178(&spyro.unk19, &arg0->position);
                    spyro.unk19.z += spyro.unk4a + 0x604;
                    spyro.unk18.roll = arg0->angle.roll;
                    spyro.unk18.pitch = arg0->angle.pitch;
                    spyro.unk18.yaw = arg0->angle.yaw;
                    func_80012BA8(&camera.unk170);
                    func_8004F178(&camera.unk184, &camera.unk60);
                    arg0->state = 8;
                } else if (arg0->state == 0) {
                    arg0->state = 1;
                }
            }
            break;

        default:
            break;

        case 1:
            func_80034F80(arg0,2);
            arg0->position.z += 0xF00;
            func_80055D24(arg0, 2);
            mobyTag->timer = 0;
            arg0->state = 10;
            break;
        }
        break;

    case 1:
        if (spyro.m_StoodOnMoby == arg0) {
            arg0->state = 2;
        case 2:
            if (spyro.m_StoodOnMoby != arg0) {
                camera.unk168 = 0;
                arg0->state = 1;
            } else {
                if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                    Vehicle506Global = 1;
                    func_8005663C();
                    arg0->state = 3;
                }
                func_8004F178(&camera.unk184, &arg0->position);
                func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
                camera.unk170.yaw = 0;
                camera.unk170.pitch = 0;
                camera.unk168 = 0x11;
            }
        }
        break;

    case 3:
        camera.unk168=0;
        if(D_80070104.loadLevel!=0) {
            func_80034F40(arg0,1);
            spyro.unk17a=0x10018000;
            func_8004F178(&spyro.unk19,&arg0->position);
            spyro.unk19.z+=0x400;
            {int height=func_8001A358(&spyro.unk19,0x800);
             spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
             spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
            arg0->state=4;
        } else arg0->state=6;
        break;
    case 4:
        spyro.unk17a=0x10018000;
        spyro.unk19.z+=0x100-spyro.unk4a;
        {int height=func_8001A358(&spyro.unk19,512);
         spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
         spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
        if(D_8006C770!=0) {
            func_80034F80(arg0,2);spyro.unk17a|=0x2000;
            if(Vehicle635Moby!=0) {
                *((unsigned char*)Vehicle635Moby+0x4C)=0;
                *((unsigned char*)Vehicle635Moby+0x4D)=0;
            }
            mobyTag->timer=120;arg0->state=5;
        }
        break;
    case 5:
        arg0->position.z = (int) (arg0->position.z + 0x40);
        spyro.unk17a = 0x1001A000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x604;
        spyro.unk18.roll = spyro.bodyRotation.roll;
        spyro.unk18.pitch = spyro.bodyRotation.pitch;
        spyro.unk18.yaw = spyro.bodyRotation.yaw;
        func_8004F178(&camera.unk184, &arg0->position);
        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
        camera.unk170.yaw = 0;
        camera.unk170.pitch = 0;
        camera.unk168 = 0x11;
        if (func_800359A4(&mobyTag->timer, 4) != 0) {
            D_8006C598 += 0x10;
            if (D_8006C598 >= 0xFF) {
                D_8006C598 = 0xFF;
                if ((D_80070104.loadLevel == 0x28) && (eggsCollectedArray[lvlIdToIndex[37]] == 0)) {
                    D_80070104.loadLevel = 0x25;
                }
                // BUG // Spike Bug
                // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                // This was fixed in all later revisions
                if ((D_80070104.loadLevel != 0x25) || (progressFlags.lvl67_AMonsterToEndAllMonsters != 0)) {
                    func_80054F94(D_80070104.loadLevel, arg0);
                } else {
                    progressFlags.lvl67_AMonsterToEndAllMonsters = 1;
                    func_800584BC(6, 0x43);
                }
            }
        }
        func_80055D24(arg0, 2);
        break;

    case 6:
        sp10.x = D_80065920[arg0->angle.yaw];
        sp10.y = D_800658A0[arg0->angle.yaw];
        sp10.z = 0;
        func_8004F194(&sp10, &sp10, &arg0->position);
        if (ovlHeader.unk2c(&sp10) != 0) {
            spyro.unk17c = 0;
            ovlHeader.unk2b(&sp10, arg0->angle.yaw, 0);
            arg0->state = 7;
        }
        break;

    case 7:
        sp20.x = D_80065920[arg0->angle.yaw];
        sp20.y = D_800658A0[arg0->angle.yaw];
        sp20.z = 0;
        func_8004F194(&sp20, &sp20, &arg0->position);
        if (ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0) != 0) {
            func_8004F178(&sp30, &spyro.position);
            sp30.z -= spyro.unk4a;
            func_8003B634(&savedData, &sp30, spyro.bodyRotation.yaw);
            arg0->state = 1;
        }
        break;

    case 8:
        arg0->position.z -= 0x40;
        spyro.unk17a = 0x1001A000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x604;
        spyro.unk18.roll = arg0->angle.roll;
        spyro.unk18.pitch = arg0->angle.pitch;
        spyro.unk18.yaw = arg0->angle.yaw;
        func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
        func_8004F178(&sp40, &arg0->position);
        arg0->position.z += 0x400;
        sp40.z += 0x200;
        sp40.z = func_8001A358(&sp40, 0x200);
        if (sp40.z != 0) {
            arg0->position.z = sp40.z;
            func_80034F40(arg0,3);
            spyro.unk17a=0x10018000;
            func_8004F178(&spyro.unk19,&arg0->position);spyro.unk19.z+=0xE00;
            {int height=func_8001A358(&spyro.unk19,0x800);
             spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
             spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
            arg0->state=9;
        } else {
            arg0->position.z -= 0x400;
        }
        func_80055D24(arg0, 2);
        break;

    case 9:
        spyro.unk17a=0x10018000;
        spyro.unk19.z+=0x100-spyro.unk4a;
        {int height=func_8001A358(&spyro.unk19,512);
         spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
         spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
        func_80013AE4((Vector3D*)mobyTag->path->nodes,&spyro.position);
        if(D_8006C770!=0) {func_80034F80(arg0,0);func_80013B7C(0);arg0->state=6;}
        break;

    }
    func_80055D24(arg0,1);
}


extern ProgressFlags progressFlags;

extern int D_8006C598,D_8006C73C,D_8006C528,currentLevel;
extern short D_800658A0[256],D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
/* AI generated adaptation of upstream func_level_17_8007D19C; not human reviewed.
 * Original SCUS-94467 level10 800805A0 instruction route; units/cadence open. */
typedef struct {int unk0,unk4;PathTag* unk8;int unkC,unk10;} Vehicle506Tag;
extern int Vehicle506Global __asm__("D_80070148");
void func_8005663C(void);
int func_8001A358(Vector3D*,int);
void func_level_40_8007E3C0(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3;
    Vehicle506Tag* mobyTag;

    mobyTag = (Vehicle506Tag*)arg0->mobyTag;
    switch (arg0->state) {

    case 0:
        switch (arg0->substate) {
        case 0:
            if (progressFlags.lvl30_RocketUsable || ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable)) {
                func_80055B18(arg0);
                return;
            }
            else {
                if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) && ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) || ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) && (arg0->mobyClass == D_8006C528)) {
                    arg0->position.z += 0xC00;
                    func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
                    camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                    camera.unk170.yaw = 0;
                    camera.unk170.pitch = 0;
                    spyro.unk17a = 0x10018000;
                    spyro.unk20[1] = 0;
                    func_8004F178(&spyro.unk19, &arg0->position);
                    spyro.unk19.z += spyro.unk4a + 0x133;
                    spyro.unk18.roll = arg0->angle.roll;
                    spyro.unk18.pitch = arg0->angle.pitch;
                    spyro.unk18.yaw = arg0->angle.yaw;
                    func_80012BA8(&camera.unk170);
                    func_8004F178(&camera.unk184, &camera.unk60);
                    arg0->state = 7;
                } else if (arg0->state == 0) {
                    arg0->state = 1;
                }
            }
            break;

        default:
            break;

        case 1:
            arg0->position.z += 0xF00;
            func_80055D24(arg0, 2);
            mobyTag->unkC = 0;
            arg0->state = 8;
            break;
        }
        break;

    case 1:
        if (spyro.m_StoodOnMoby == arg0) {
            arg0->state = 2;
        case 2:
            if (spyro.m_StoodOnMoby != arg0) {
                camera.unk168 = 0;
                arg0->state = 1;
            } else {
                if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                    Vehicle506Global = 1;
                    func_8005663C();
                    arg0->state = 3;
                }
                func_8004F178(&camera.unk184, &arg0->position);
                func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
                camera.unk170.yaw = 0;
                camera.unk170.pitch = 0;
                camera.unk168 = 0x11;
            }
        }
        break;

    case 3:
        camera.unk168 = 0;
        if (D_80070104.loadLevel != 0) {
            mobyTag->unkC = 0x78;
            arg0->state = 4;
        } else {
            arg0->state = 5;
        }
        break;

    case 4:
        func_80034F40(arg0, 1);
        arg0->position.z = (int) (arg0->position.z + 0x40);
        spyro.unk17a = 0x10008000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x133;
        spyro.unk18.roll = spyro.bodyRotation.roll;
        spyro.unk18.pitch = spyro.bodyRotation.pitch;
        spyro.unk18.yaw = spyro.bodyRotation.yaw;
        func_8004F178(&camera.unk184, &arg0->position);
        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
        camera.unk170.yaw = 0;
        camera.unk170.pitch = 0;
        camera.unk168 = 0x11;
        if (func_800359A4(&mobyTag->unkC, 4) != 0) {
            D_8006C598 += 0x10;
            if (D_8006C598 >= 0xFF) {
                D_8006C598 = 0xFF;
                if ((D_80070104.loadLevel == 0x1E) && (eggsCollectedArray[lvlIdToIndex[27]] == 0)) {
                    D_80070104.loadLevel = 0x1B;
                }
                // BUG // Spike Bug
                // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                // This was fixed in all later revisions
                if ((D_80070104.loadLevel != 0x1B) || (progressFlags.lvl63_BiancaStrikesBack != 0)) {
                    func_80054F94(D_80070104.loadLevel, arg0);
                } else {
                    progressFlags.lvl65_SpikeIsBorn = 1;
                    func_800584BC(6, 0x41);
                }
            }
        }
        func_80055D24(arg0, 2);
        break;

    case 5:
        sp10.x = D_80065920[arg0->angle.yaw];
        sp10.y = D_800658A0[arg0->angle.yaw];
        sp10.z = 0;
        func_8004F194(&sp10, &sp10, &arg0->position);
        if (ovlHeader.unk2c(&sp10) != 0) {
            spyro.unk17c = 0;
            ovlHeader.unk2b(&sp10, arg0->angle.yaw, 0);
            arg0->state = 6U;
        }
        break;

    case 6:
        sp20.x = D_80065920[arg0->angle.yaw];
        sp20.y = D_800658A0[arg0->angle.yaw];
        sp20.z = 0;
        func_8004F194(&sp20, &sp20, &arg0->position);
        if (ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0) != 0) {
            func_8004F178(&sp30, &spyro.position);
            sp30.z -= spyro.unk4a;
            func_8003B634(&savedData, &sp30, spyro.bodyRotation.yaw);
            func_80034F40(arg0, 0);
            arg0->state = 1;
        }
        break;

    case 7:
        func_80034F40(arg0, 1);
        arg0->position.z -= 0x40;
        spyro.unk17a = 0x10018000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x133;
        spyro.unk18.roll = arg0->angle.roll;
        spyro.unk18.pitch = arg0->angle.pitch;
        spyro.unk18.yaw = arg0->angle.yaw;
        func_80013AE4((Vector3D*)mobyTag->unk8->nodes, &spyro.position);
        func_8004F178(&sp40, &arg0->position);
        arg0->position.z += 0x400;
        sp40.z += 0x200;
        sp40.z = func_8001A358(&sp40, 0x200);
        if (sp40.z != 0) {
            arg0->position.z = sp40.z;
            func_80013B7C(0);
            arg0->state = 5U;
        } else {
            arg0->position.z -= 0x400;
        }
        func_80055D24(arg0, 2);
        break;


    }

    if ((game.state == 0) && (arg0->animationState.nextId == 1)) {
        if (func_8003BFC0(arg0, mobyTag->unk10) == 0) {
            mobyTag->unk10 = func_8003BABC(arg0, 0, 4);
            return;
        }
    } else {
        if (func_8003BFC0(arg0, mobyTag->unk10) != 0) {
            func_8003BE70(mobyTag->unk10);
        }
        mobyTag->unk10 = -1;
        return;
    }

}

int func_80036220(Vector3D*, char*, int, int);
void func_800584BC(int, int);
void func_level_40_8007EBA8(Moby* moby) {
    char* bounds = moby->mobyTag;
    if (func_80036220((Vector3D*)&spyro, bounds, 0, 0))
        func_800584BC(0, 0x2F);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007EBE8);

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007F14C);

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/moby", func_level_40_8007F650);

typedef struct {
    short count;
    unsigned char reserved02[10];
    unsigned char* records;
} DecodedEventRecords;
typedef struct {
    int tableIndex, targetIndex, mask;
    short classOrCount, countOrClass;
    int kind;
    Vector3D* offsets;
    int reserved18;
    DecodedEventRecords* recordList;
    int soundIndex, enabled;
} DecodedEventTag;
extern int DecodedEventTick __asm__("D_8006C640");
extern unsigned char DecodedEventFlags __asm__("D_8006C7B4");
extern int DecodedEventSlot __asm__("D_8006C58C");
extern unsigned char DecodedEventSlots[] __asm__("D_80070300");
extern int** DecodedEventTable __asm__("D_8006D048 + 0x14");
extern int DecodedEventLevel __asm__("D_8006C5BC");
extern int DecodedEventSublevel __asm__("D_8006C5C8");
extern unsigned char DecodedEventTimerData[] __asm__("D_8006C7F8");
extern unsigned char DecodedEventSpecialTimerData[] __asm__("D_8006D088");
extern short DecodedEventCos[] __asm__("D_80065920");
extern short DecodedEventSin[] __asm__("D_800658A0");
void DecodedEventTimer(void*, int, void*) __asm__("func_8003B7B4");
void DecodedEventSound(Moby*, int, int) __asm__("func_8003BB10");
void DecodedEventTarget(int, int, int) __asm__("func_80021ED8");
void DecodedEventPrepare(Moby*, int) __asm__("func_80055D24");
void DecodedEventCopy(Vector3D*, const void*) __asm__("func_8004F178");
void DecodedEventAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedEventSubtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void DecodedEventRotate(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int DecodedEventLength(Vector3D*, int) __asm__("func_8004EDE8");
void DecodedEventScale(Vector3D*, int, int) __asm__("func_8004F08C");
void func_80055B18(Moby*);
/*
 * USA SCUS-94467 Rev 0: representative func_level_13_80082590,
 * 0x80082590..0x800829C8, 270 words. Per-copy source and word digests
 * are recorded in overlay-batch-2026-10-04-1298.md.
 * Empty asm constraints emit no instructions and retain the retail
 * register lifetimes, call arguments, fresh reads and stack layout.
 * Raw table/object fields and helper identities are preserved; caller
 * cadence and browser runtime interpretations remain unresolved.
 * AI-generated reconstruction; not yet human reviewed.
 */
void func_level_40_80080270(Moby* argument) {
    Vector3D offset;
    int reserved24;
    Vector3D direction;
    int reserved34[3];
    register Moby* moby __asm__("$20") = argument;
    register int state __asm__("$16") = moby->state;
    register DecodedEventTag* tag __asm__("$18") = moby->mobyTag;
    register int count __asm__("$17");
    register int kind __asm__("$3");
    register int limit __asm__("$2");
    register int cursor __asm__("$19");
    register Vector3D* directionPointer __asm__("$21");
    __asm__("" : "=r"(state) : "0"(state));
    switch (state) {
    /* Arm the controller from its enable bits or a masked table entry. */
    case 0: {
        register int* entry __asm__("$4");
        if (tag->enabled && !DecodedEventTick) {
            if ((DecodedEventFlags & 1) || (DecodedEventSlots[DecodedEventSlot] & 1)) {
                moby->updateDistance = 255;
                moby->state = 1;
                DecodedEventTimer(&moby->state, 1, DecodedEventTimerData);
            }
        }
        /* The table stores pointers; the tested word is at entry offset 4. */
        entry = DecodedEventTable[tag->tableIndex];
        if (!DecodedEventTick) entry[1] = 0;
        if (!(entry[1] & tag->mask)) return;
        entry[1] = 0;
        moby->state = 1;
        if ((DecodedEventLevel == 21 && DecodedEventSublevel == 1) || DecodedEventLevel == 26) {
            register unsigned char* statePointer __asm__("$16") = &moby->state;
            DecodedEventTimer(statePointer, 1, DecodedEventSpecialTimerData);
            DecodedEventTimer(statePointer, 1, DecodedEventTimerData);
        } else {
            DecodedEventTimer(&moby->state, 1, DecodedEventTimerData);
        }
        return;
    }
    /* Retain the saved state in the kind-1 comparison, as in retail. */
    case 1:
        __asm__("" : : "r"(moby) : "$4");
        if (DecodedEventTick < 5) goto finish;
        {
            register Moby* soundArgument __asm__("$4") = moby;
            if (tag->soundIndex != -1) DecodedEventSound(soundArgument, tag->soundIndex, 0);
        }
        kind = tag->kind;
        /* The three kinds use distinct original spawn/helper paths. */
        if (kind == 0) {
            __asm__("" : "=r"(kind) : "0"(kind));
            if (tag->classOrCount >= 0)
                SpawnFragments(tag->countOrClass, tag->classOrCount, moby, tag->offsets, 0, 0x200);
        } else if (kind == state) {
            if (tag->classOrCount < 0 || tag->countOrClass <= 0) goto finish;
            DecodedEventPrepare(moby, 4);
            count = 0;
            if (tag->countOrClass > 0) {
                cursor = 0;
                do {
                    register Moby* spawned __asm__("$16") = SpawnMoby(tag->classOrCount, moby);
                    if (spawned) {
                        DecodedEventCopy(&offset, (unsigned char*)tag->offsets + cursor);
                        DecodedEventRotate(&moby->rotationMatrix, &offset, &offset);
                        DecodedEventAdd(&spawned->position, &spawned->position, &offset);
                    }
                    limit = tag->countOrClass;
                    __asm__("" : "=r"(count) : "0"(count), "r"(limit));
                    count++;
                    cursor += 12;
                } while (count < limit);
            }
        } else if (kind == 2) {
            if (tag->classOrCount < 0 || !tag->recordList) goto finish;
            cursor = 0;
            if (tag->recordList->count <= 0) goto finish;
            directionPointer = &direction;
            do {
                /* The retail pointer slot holds the Moby, then its tag. */
                register void* spawnedData __asm__("$16") = SpawnMoby(tag->classOrCount, moby);
                register Vector3D* position __asm__("$17");
                __asm__("" : "=r"(spawnedData) : "0"(spawnedData));
                position = &((Moby*)spawnedData)->position;
                if (spawnedData) {
                    short* spawnedTag;
                    {
                        register Vector3D* copyArgument __asm__("$4") = position;
                        __asm__("" : : "r"(copyArgument));
                        {
                            register unsigned char* records __asm__("$2") = (unsigned char*)tag->recordList;
                            register int recordOffset __asm__("$5");
                            __asm__("" : "=r"(records) : "0"(records));
                            recordOffset = cursor * 16;
                            records = ((DecodedEventRecords*)records)->records;
                            spawnedData = ((Moby*)spawnedData)->mobyTag;
                            spawnedTag = spawnedData;
                            DecodedEventCopy(copyArgument, records + recordOffset);
                        }
                    }
                    DecodedEventSubtract(directionPointer, position, &moby->position);
                    DecodedEventScale(directionPointer, DecodedEventLength(directionPointer, 1), 90);
                    /* Preserve the original halfword writes and subsequent overwrites. */
                    spawnedTag[0] += (DecodedEventCos[moby->angle.yaw] * 15) >> 9;
                    spawnedTag[1] += (DecodedEventSin[moby->angle.yaw] * 15) >> 9;
                    spawnedTag[0] = direction.x;
                    spawnedTag[1] = direction.y;
                    spawnedTag[2] = direction.z;
                }
                cursor++;
            } while (cursor < tag->recordList->count);
        }
    /* Every state-1 path reaches the original target call and removal helper. */
    finish:
        DecodedEventTarget(tag->targetIndex, 0xFC, 0);
        func_80055B18(moby);
        return;
    default:
        return;
    }
}

typedef struct { int actorIndex; Vector3D position; int timer; int* counter; } DecodedLinkedActor;
extern Moby* D_8006C550;
extern int D_8006C79C,D_8006C58C;
extern int D_80071AB0[][8];

extern Moby* DecodedActorCallback(Moby*,int,Vector3D*,Vector3D*) __asm__("func_80036A68");
int func_8001A358(Vector3D*,int);
void func_level_40_800806A8(Moby* moby) {
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
void func_level_40_800809D8(Moby* actor) {
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
void func_level_40_80080BE4(Moby* argument) {
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
void func_level_40_8008110C(void *input) {
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


void func_level_40_80082260(Moby* moby) {
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
void func_level_40_80082280(Moby* argument) {
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
void func_level_40_80082480(Moby* moby) {
    if (D_8006C770 != 0) func_80055B18(moby);
}
