#include "common.h"
#include "savepoint.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "mobyutil.h"

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
void func_level_13_8007507C(void *input) {
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
void func_level_13_80075CD8(Moby* argument) {
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
void func_level_13_80076364(void *input) {
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


typedef struct {
    short counter;
    unsigned char unk2, unk3;
} DecodedColourTag;
void func_80055B18(Moby*);
void func_level_13_800778B4(Moby* moby) {
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
void func_level_13_800779F0(Moby* moby) {
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
        func_8003BABC(moby, 0, 0);moby->substate=0x70;
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
void func_level_13_80077CB0(Moby* argument) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0.
 * Original func_level_13_800781D0 and siblings:668 instructions,5 dispatch
 * targets and one alignment word; evidence4913. Raw field widths/offsets,
 * helper addresses and integer expressions follow original instructions.
 * Units, helper meanings, cadence and retail runtime parity unresolved.
 * Uninstalled candidate: every native/internal-target/table word and all
 * executable/overlay hashes required before acceptance. */
#define A4914F(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define A4914W(p,o) A4914F(p,int*,o)
#define A4914B(p,o) A4914F(p,unsigned char*,o)
extern unsigned char A4914Player[] __asm__("D_80070328");
extern int A4914PX __asm__("D_80070328"), A4914PY __asm__("D_80070328 + 4");
extern int A4914PZ __asm__("D_80070328 + 8"),A4914P44 __asm__("D_80070328 + 0x44");
extern int A4914PB8 __asm__("D_80070328 + 0xB8");
extern int A4914P20C __asm__("D_80070328 + 0x20C");
extern unsigned char* A4914Models __asm__("D_8006C550");
extern int A4914Delta __asm__("D_8006C648"),A4914C590 __asm__("D_8006C590");
extern int A4914C74C __asm__("D_8006C74C"),A4914C578 __asm__("D_8006C578"),A4914C574 __asm__("D_8006C574");
extern int A4914NewButtons __asm__("D_8006E53C");
extern short A4914Cos[] __asm__("D_80065920"),A4914Sin[] __asm__("D_800658A0");
extern int (*A4914Callback)() __asm__("unk_ovlheader_80074330");
extern unsigned char* (*A4914Spawn)() __asm__("SpawnMoby");
extern int (*A4914Particle)() __asm__("SpawnParticle");
int A4914H4F334() __asm__("func_8004F334");
int A4914H37014() __asm__("func_80037014");
int A4914H2803C() __asm__("func_8002803C");
int A4914H27D60() __asm__("func_80027D60");
int A4914H2982C() __asm__("func_8002982C");
int A4914H4E880() __asm__("func_8004E880");
int A4914H4F264() __asm__("func_8004F264");
int A4914H4F178() __asm__("func_8004F178");
int A4914H527C4() __asm__("func_800527C4");
int A4914H3BABC() __asm__("func_8003BABC");
int A4914H4F1C8() __asm__("func_8004F1C8");
int A4914H4F110() __asm__("func_8004F110");
int A4914H4F1FC() __asm__("func_8004F1FC");
int A4914H4F228() __asm__("func_8004F228");
int A4914H4F194() __asm__("func_8004F194");
int A4914H3585C() __asm__("func_8003585C");
int A4914H492DC() __asm__("func_800492DC");
int A4914H55D24() __asm__("func_80055D24");
int A4914H55B18() __asm__("func_80055B18");
int A4914H28154() __asm__("func_80028154");
int A4914H368A4() __asm__("func_800368A4");
int A4914Rand() __asm__("rand");
void func_level_13_800781D0(unsigned char* input){
 register int work2 __asm__("$2");
 register int work3 __asm__("$3");
 register int arg4 __asm__("$4");
 register int arg5 __asm__("$5");
 register int arg6 __asm__("$6");
 register int counter16 __asm__("$16");
 register int* vector17 __asm__("$17");
 register unsigned char* private18 __asm__("$18");
 register unsigned char* owner19 __asm__("$19");
 register int saved20 __asm__("$20");
 register int saved21 __asm__("$21");
 register int saved22 __asm__("$22");
 register int saved23 __asm__("$23");
 struct {int first[4],second[4],third[4],fourth[4];} frame;
 owner19=input;private18=A4914F(owner19,unsigned char**,0);
 counter16=A4914H4F334(owner19+12,A4914Player);
 if(A4914W(private18,16))A4914H37014(owner19);
 work3=A4914W(private18,28);work2=work3*88;
 work3=(int)A4914Models;work2+=work3;
 if(A4914B((void*)work2,72)>=128 && A4914W(private18,32)==-1)
  A4914W(private18,32)=(short)A4914H2803C(6,4000,A4914H27D60,0,A4914H2982C,0,0);
 work3=A4914B(owner19,72);work2=1;
 if(work3==work2)goto state1;
 if(work3<2){if(!work3)goto state0;goto common;}
 if(work3==2)goto state2;
 goto common;
 state0:
 A4914B(owner19,87)=41;A4914B(owner19,84)=128;A4914B(owner19,85)=128;
 A4914B(owner19,86)=144;A4914B(owner19,72)=1;goto update;
 state1:
 work3=A4914W(private18,0);
 if(work3){
  work3+=A4914Delta;A4914W(private18,0)=work3;
  if(work3<64){
   work2=work3>>1;work3=A4914W(private18,24);work2<<=1;work2+=work3;
   work3=A4914W(private18,4);work2=A4914B((void*)work2,0)+work3;A4914B(owner19,68)=work2;
   work2=A4914W(private18,0);work3=A4914W(private18,24);work2=((work2>>1)<<1)+work3;
   work3=A4914W(private18,8);work2=A4914B((void*)work2,1)+work3;A4914B(owner19,69)=work2;
   work2=A4914W(private18,0);work3=A4914W(private18,24);work2=((work2>>1)<<1)+work3;
   work3=A4914F((void*)work2,signed char*,0);work2=A4914F((void*)work2,signed char*,1);
   if(work3<0)work3=-work3;if(work2<0)work2=-work2;
   __asm__("" : "=r"(work3):"0"(work3));work3+=work2;__asm__("" : "=r"(work3):"0"(work3));
   work2=work3*6;work3=A4914W(private18,12);work3+=work2;A4914W(owner19,20)=work3;
  }else{
   work2=A4914W(private18,4);A4914W(private18,0)=0;A4914B(owner19,68)=work2;
   work2=A4914W(private18,8);A4914B(owner19,69)=work2;work2=A4914W(private18,12);A4914W(owner19,20)=work2;
  }
 }
 if(counter16>20480)goto done;
 work3=A4914W(private18,28);work2=work3*88;work3=(int)A4914Models;work2+=work3;
 if(A4914B((void*)work2,72)<128)goto common;
 work2=A4914H4E880(A4914PX-A4914W(owner19,12),A4914PY-A4914W(owner19,16),0);
 work2=A4914H4F264(A4914B(owner19,70),work2);
 if(work2>=32)goto update;
 work2=counter16<2700;if(!work2)goto common;if(A4914PB8)goto common;
 work3=A4914F(owner19,short*,56);work2=A4914W(owner19,20)-work3;
 work3=A4914PZ;arg4=A4914P44;work2-=work3;work2+=arg4;if(work2<0)work2=-work2;
 if(work2>=900)goto update;
 A4914B(owner19,73)=0;A4914B(owner19,72)=2;goto done;
 state2:
 switch(A4914B(owner19,73)){
 case 0:
  A4914H4F178(frame.first,owner19+12);
  work2=A4914B(owner19,70);work3=A4914Cos[work2];work2=(work3*125)>>8;
  work3=frame.first[0];work3+=work2;frame.first[0]=work3;
  work2=A4914B(owner19,70);work3=A4914Sin[work2];work2=(work3*125)>>8;
  work3=frame.first[1];work3+=work2;frame.first[1]=work3;
  work2=A4914Callback(frame.first,(A4914B(owner19,70)+128)&255,owner19);
  if(!work2)goto common;goto increment;
 case 1:
  A4914H527C4(owner19,-1);A4914C590=A4914W(private18,44);
  work2=(int)A4914Spawn(212,owner19);A4914W(private18,36)=work2;
  if(work2)A4914H3BABC((void*)work2,0,0);
 case 2:
  if(A4914NewButtons&2048)goto increment;
  if(!A4914W(private18,36))goto increment;
  vector17=frame.second;__asm__("" : "=r"(vector17):"0"(vector17));A4914H4F178(vector17,owner19+12);
  arg4=0x10000002;work2=A4914B(owner19,70);work3=A4914Cos[work2];arg6=(int)&A4914P20C;work2=(work3*175)>>10;
  work3=frame.second[0];work3+=work2;frame.second[0]=work3;
  work3=A4914B(owner19,70);work2=frame.second[2];work3=A4914Sin[work3];
  work2+=350;frame.second[2]=work2;A4914W((void*)arg6,0)=arg4;
  work2=(work3*175)>>10;work3=frame.second[1];work3+=work2;frame.second[1]=work3;
  work3=A4914W(private18,36);A4914B((void*)work3,76)=24;
  work3=A4914W(private18,40);arg4=A4914Delta;work3+=arg4;A4914W(private18,40)=work3;
  saved20=(int)A4914Sin;
  __asm__ volatile("" ::: "memory");work3=A4914W(private18,40);work2=1;A4914C74C=work2;
  if(work3<192){
   counter16=(int)frame.third;arg4=counter16;arg5=(int)vector17;
   __asm__("" : "=r"(arg4),"=r"(arg5):"0"(arg4),"1"(arg5));vector17=(int*)(arg6-524);
   A4914H4F1C8((void*)arg4,(void*)arg5,vector17);
   frame.third[2]-=256;A4914H4F110((void*)counter16,5);
   A4914H4F1FC((void*)counter16,(void*)counter16,A4914W(private18,40));
   A4914H4F228((void*)counter16,(void*)counter16,6);
   A4914H4F194((void*)counter16,(void*)counter16,vector17);
   arg4=frame.third[2]+256;frame.third[2]=arg4;
   work3=A4914W(private18,40)<<7;work2=work3/192;
   work2=A4914F((void*)(saved20+(work2<<1)),unsigned short*,0);work2=(short)work2;work2>>=3;
   arg4+=work2;frame.third[2]=arg4;
   A4914H4F178((void*)(A4914W(private18,36)+12),(void*)counter16);
   arg4=A4914W(private18,40);
   if(arg4<32){work2=-arg4;work3=A4914W(private18,36);A4914B((void*)work3,69)=work2;goto angle;}
   work2=arg4<128;if(!work2)goto lateAngle;
   work2=224;work3=A4914W(private18,36);A4914B((void*)work3,69)=work2;
 angle:
  work2=A4914W(private18,40);work3=A4914W(private18,36);A4914B((void*)work3,70)=(work2<<2)-128;
   goto reloadSubtract64;
 lateAngle:
   work3=A4914W(private18,36);work2=arg4+96;A4914B((void*)work3,69)=work2;
   work3=A4914W(private18,36);if(A4914B((void*)work3,69)>=127)goto subtract64;
   A4914B((void*)work3,69)=0;goto call3585C;
  }
  work2=work3<208;if(!work2)goto launch;
  work3=A4914W(private18,36);if(A4914B((void*)work3,79)<32)A4914B((void*)work3,79)=32;
  work2=A4914W(private18,36);work3=A4914B((void*)work2,79);A4914B((void*)work2,79)=work3+8;
 call3585C:
  A4914H3585C((void*)A4914W(private18,36),A4914B(owner19,70),3,0,0,0);goto reloadSubtract64;
  goto childStep;
 launch:
  work2=A4914B(owner19,73);A4914B(owner19,73)=work2+1;
 reloadSubtract64:work3=A4914W(private18,36);
 subtract64:work2=A4914B((void*)work3,69);work2-=64;A4914B((void*)work3,69)=work2;
 childStep:
  A4914H492DC((void*)(A4914W(private18,36)+12));
  work3=A4914B(owner19,73);work2=1;
  if(work3==work2){
   work3=A4914W(private18,36);A4914B((void*)work3,72)=99;
   work3=A4914W(private18,36);A4914B((void*)work3,87)=41;
   work2=A4914W(private18,36);A4914B((void*)work2,84)=128;
   work2=A4914W(private18,36);A4914B((void*)work2,85)=128;
   work2=A4914W(private18,36);
   __asm__ volatile("" : "=r"(work2):"0"(work2):"$16");counter16=0;
   A4914B((void*)work2,86)=0;
   __asm__ volatile("" : "=r"(work2):"0"(work2):"$5");arg5=4;
   do{arg4=A4914W(private18,36);
    __asm__("" : "=r"(arg4),"=r"(arg5):"0"(arg4),"1"(arg5));
    counter16++;A4914H55D24((void*)arg4,arg5);
    A4914Particle(4,12,(void*)A4914W(private18,36),3);
    work2=counter16<2;arg5=4;
   }while(work2);__asm__ volatile("" ::: "memory");
   goto increment;
  }
  A4914H55D24((void*)A4914W(private18,36),4);A4914Particle(1,12,(void*)A4914W(private18,36),3);goto common;
 dispose:
  A4914C74C=0;counter16=0;arg5=4;
   do{arg4=A4914W(private18,36);
    __asm__("" : "=r"(arg4),"=r"(arg5):"0"(arg4),"1"(arg5));
    counter16++;A4914H55D24((void*)arg4,arg5);
    A4914Particle(4,12,(void*)A4914W(private18,36),3);
    work2=counter16<3;arg5=4;
   }while(work2);__asm__ volatile("" ::: "memory");
  arg4=A4914W(private18,36);if(arg4)A4914H55B18((void*)arg4);goto increment;
 case 3:
  goto dispose;
 increment:
 work2=A4914B(owner19,73);A4914B(owner19,73)=work2+1;
 goto update;
 case 4:
  A4914H3BABC(owner19,0,0);saved23=16;saved22=8;saved21=308;A4914B(owner19,73)=144;
  counter16=0;saved20=5;vector17=(int*)1;
  do{
   work2=A4914C578;work3=A4914C574;work2-=work3;if(work2<21)goto dust;
   arg4=(int)A4914Spawn(saved21,owner19);
   if(counter16<saved22)A4914B((void*)arg4,73)=saved20;
   else{A4914B((void*)arg4,60)=(int)vector17;work2=4;A4914B((void*)arg4,73)=work2;}
   work3=A4914F(owner19,short*,54);work2=201;
   __asm__("" : "=r"(work2),"=r"(work3):"0"(work2),"1"(work3));
   if(work3!=work2)A4914B((void*)arg4,84)=(int)vector17;
   counter16++;
  }while(counter16<saved23);
 dust:
  counter16=0;vector17=frame.fourth;
  do{
   A4914H4F178(vector17,owner19+12);counter16++;
   work2=A4914Rand();work3=frame.fourth[0];work3+=128;work3-=work2&255;frame.fourth[0]=work3;
   work2=A4914Rand();work3=frame.fourth[1];work3+=128;work3-=work2&255;frame.fourth[1]=work3;
   work2=A4914Rand();work3=frame.fourth[2];work3+=work2&511;frame.fourth[2]=work3;
   A4914Particle(1,2,vector17,0);A4914Particle(4,70,vector17,24);
  }while(counter16<8);
  arg4=A4914W(private18,32);counter16=-1;if(arg4!=counter16)A4914H28154(arg4);
  A4914W(private18,32)=counter16;A4914H55B18(owner19);goto done;
 }
 goto update;
 update:
 common:
 A4914W(private18,20)=A4914H368A4(owner19,A4914W(private18,20),A4914F(owner19,short*,54)!=201);
 if((A4914W(owner19,24)&0x30000) && !A4914W(private18,0)){
  A4914W(private18,0)=1;work2=A4914B(owner19,68);A4914W(private18,4)=work2;
  work2=A4914B(owner19,69);A4914W(private18,8)=work2;work2=A4914W(owner19,20);A4914W(private18,12)=work2;
  A4914H3BABC(owner19,1,0);
 }
 A4914W(owner19,24)=0;
 done:return;
}
#undef A4914F
#undef A4914W
#undef A4914B


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev 0 source asm/nonmatchings/overlays/level_13/moby/func_level_13_80078C40.s; SHA256 7fa36578bfa69a530f93ebc0a4d9da9a3922a93c780f7a31c33793f5bc0b9dc0. */
/* AI generated;
 not human reviewed. SCUS-94467 USA Rev0 original417
 * instructions: sibling4768/4767. Units/helper meanings/cadence unresolved. */
#define SharedBurst417Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern int SharedBurst417Delta __asm__("D_8006C648");
extern int SharedBurst417Count0 __asm__("D_8006C578"),SharedBurst417Count1 __asm__("D_8006C574");
extern short SharedBurst417Cos[] __asm__("D_80065920"),SharedBurst417Sin[] __asm__("D_800658A0");
extern unsigned char* SharedBurst417Models[] __asm__("D_8006EE2C");
extern unsigned char* (*SharedBurst417Spawn)() __asm__("SpawnMoby");
extern int (*SharedBurst417Particle)() __asm__("SpawnParticle");
int SharedBurst417Rand() __asm__("rand");
int SharedBurst417H3636C() __asm__("func_8003636C");
int SharedBurst417H37A60() __asm__("func_80037A60");
int SharedBurst417H4F178() __asm__("func_8004F178");
int SharedBurst417H4F194() __asm__("func_8004F194");
int SharedBurst417H36A68() __asm__("func_80036A68");
int SharedBurst417H3BABC() __asm__("func_8003BABC");
int SharedBurst417H55B18() __asm__("func_80055B18");
#define SharedBurst417High(a,b) ({int high;__asm__ __volatile__("":"=h"(high):"l"((int)(a)*(int)(b)):"memory");high;})
#define SharedBurst417Low(a,b) ({register int low __asm__("lo");low=(int)(a)*(int)(b);__asm__("":"=l"(low):"0"(low));low;})
/* Original 417-word function and 0x70-byte frame. Raw table indices,
 * signed HI/LO products and register-width remainders retain the original
 * producer instructions. Empty constraints preserve their scheduling.
 * Physical units, helper meanings and frame cadence remain unresolved. */
void func_level_13_80078C40(void* input){
 struct {int first[4],second[4],third[4];
 } frame;
 register unsigned char* owner __asm__("$21")=input;
 unsigned char* tag;
 register int index17 __asm__("$17");
 register int five18 __asm__("$18");
 register unsigned char* small16 __asm__("$16");
 register int angle0 __asm__("$16");
 register int angle1 __asm__("$17");
 register unsigned char* child20 __asm__("$20");
 register unsigned char* nested22 __asm__("$22");
 register int count23 __asm__("$23");
 register short* cosine0 __asm__("$19");
 register short* cosine1 __asm__("$18");
 register short* sine22 __asm__("$22");
 register int* vector20 __asm__("$20");
 register int value __asm__("$2");
 register int other __asm__("$3");
 register void* call4 __asm__("$4");
 register int arg5 __asm__("$5");
 register void* arg6 __asm__("$6");
 register void* arg7 __asm__("$7");
 __asm__("" : "=r"(owner):"0"(owner));
 value=owner[72];
 tag=SharedBurst417Field(owner,unsigned char**,0);
 if(!value){value=SharedBurst417Field(owner,int*,24);
 if(value)owner[72]=2;
 }
 other=owner[72];
 value=1;
 SharedBurst417Field(owner,int*,24)=0;
 if(other==value)goto state1;
 if(other<2){if(!other)goto state0;
 goto done;
 }value=2;
 call4=owner;
 if(other==value)goto state2;
 goto done;
 state0:
 value=tag[0];
 if(!value){tag[0]=1;
 value=SharedBurst417Field(owner,int*,20);
 SharedBurst417Field(tag,int*,4)=value;
 }
 other=SharedBurst417Delta;
 value=tag[1];
 value+=other;
 tag[1]=value;
 value&=255;
 value<<=1;
 other=*(short*)((unsigned char*)SharedBurst417Sin+value);
 __asm__("" : "=r"(other):"0"(other));
 value=other*5;
 other=(value<<4)-value;
 value=SharedBurst417Field(tag,int*,4);
 other>>=10;
 value+=other;
 SharedBurst417Field(owner,int*,20)=value;
 goto done;
 state1:
 value=SharedBurst417H37A60(owner,tag+2,2,16,-200);
 if(!value)goto done;
 owner[73]=112;
 index17=0;
 five18=5;
 small_loop:
 value=SharedBurst417Count0;
 other=SharedBurst417Count1;
 value-=other;
 call4=(void*)631;
 if(value<21)goto small_done;
 small16=SharedBurst417Spawn(call4,owner);
 call4=0;
 if(small16){value=SharedBurst417H3636C(call4,300);
 other=SharedBurst417Field(small16,int*,20);
 other+=value;
 value=index17<6;
 SharedBurst417Field(small16,int*,20)=other;
 if(value)small16[73]=five18;
 }
 index17++;
 if(index17<16)goto small_loop;
 small_done:
 index17=0;
 call4=frame.first;
 first_particles:
 SharedBurst417H4F178(call4,owner+12);
 index17++;
 value=SharedBurst417Rand();
 other=frame.first[0];
 value&=255;
 other+=128;
 other-=value;
 frame.first[0]=other;
 value=SharedBurst417Rand();
 other=frame.first[1];
 value&=255;
 other+=128;
 other-=value;
 frame.first[1]=other;
 value=SharedBurst417Rand();
 call4=(void*)1;
 arg5=2;
 arg6=frame.first;
 arg7=0;
 __asm__("" : "=r"(call4),"=r"(arg5),"=r"(arg6),"=r"(arg7),"=r"(value):"0"(call4),"1"(arg5),"2"(arg6),"3"(arg7),"4"(value));
 value&=511;
 other=frame.first[2];
 other+=value;
 frame.first[2]=other;
 SharedBurst417Particle(call4,arg5,arg6,arg7);
 SharedBurst417Particle(4,70,frame.first,24);
 value=index17<4;
 call4=frame.first;
 if(value)goto first_particles;
 SharedBurst417H36A68(owner,0,0,0);
 SharedBurst417H3BABC(owner,1,0);
 SharedBurst417H55B18(owner);
 goto done;
 state2:
 SharedBurst417H3BABC(call4,0,0);
 count23=0;
 child_loop:
 value=SharedBurst417Count0;
 other=SharedBurst417Count1;
 value-=other;
 call4=(void*)630;
 if(value<21)goto child_done;
 child20=SharedBurst417Spawn(call4,owner);
 nested22=SharedBurst417Field(child20,unsigned char**,0);
 __asm__("" : "=r"(child20),"=r"(nested22):"0"(child20),"1"(nested22));
 if(!child20)goto child_next;
 angle0=SharedBurst417Rand();
 angle1=SharedBurst417Rand();
 value=SharedBurst417Rand();
 other=0x55555556;
 __asm__("":"=r"(other):"0"(other));
 {register int quotient9 __asm__("$9");
 quotient9=SharedBurst417High(value,other);
 call4=(void*)(value>>31);
 angle0=(angle0&255)<<1;
 angle1=(angle1&255)<<1;
 __asm__("":"=r"(quotient9):"0"(quotient9),"r"(angle1));
 call4=(void*)(quotient9-(int)call4);
 }value-=(int)call4*3;
 {register short* table9 __asm__("$9");
 register int product9 __asm__("$9");
 __asm__ volatile("" : : "r"(value): "memory", "$9");
 table9=SharedBurst417Cos;
 cosine0=(short*)(angle0+(int)table9);
 child20[60]=value;
 other=*cosine0;
 cosine1=(short*)(angle1+(int)table9);
 value=other*25;
 other=*cosine1;
 value>>=7;
 product9=SharedBurst417Low(value,other);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 value=product9>>12;
 table9=SharedBurst417Sin;
 angle0+=(int)table9;
 SharedBurst417Field(child20,int*,12)=value;
 other=*(short*)angle0;
 value=other*25;
 other=*cosine1;
 value>>=7;
 product9=SharedBurst417Low(value,other);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 arg6=owner+12;
 call4=child20+12;
 value=product9>>12;
 table9=SharedBurst417Sin;
 angle1+=(int)table9;
 SharedBurst417Field(child20,int*,16)=value;
 other=*(short*)angle1;
 arg5=(int)call4;
 value=other*25;
 value>>=7;
 SharedBurst417Field(child20,int*,20)=value;
 SharedBurst417H4F194(call4,(void*)arg5,arg6);
 value=SharedBurst417Field(child20,int*,20);
 value+=2000;
 SharedBurst417Field(child20,int*,20)=value;
 other=*cosine0;
 value=other*25;
 other=*cosine1;
 value>>=10;
 product9=SharedBurst417Low(value,other);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 value=product9>>12;
 SharedBurst417Field(nested22,short*,0)=value;
 other=*(short*)angle0;
 value=other*25;
 other=*cosine1;
 value>>=10;
 product9=SharedBurst417Low(value,other);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 call4=(void*)30;
 value=product9>>12;
 SharedBurst417Field(nested22,short*,2)=value;
 other=*(short*)angle1;
 arg5=60;
 value=other*25;
 value>>=10;
 SharedBurst417Field(nested22,short*,4)=value;
 value=SharedBurst417H3636C(call4,arg5);
 SharedBurst417Field(nested22,int*,12)=value;
 }
 child_next:
 count23++;
 if(count23<16)goto child_loop;
 child_done:
 count23=0;
 sine22=SharedBurst417Sin;
 vector20=frame.second;
 particle_loop:
 count23++;
 angle0=SharedBurst417Rand();
 value=SharedBurst417Rand();
 call4=(void*)200;
 arg5=1100;
 __asm__("" : "=r"(call4),"=r"(arg5):"0"(call4),"1"(arg5));
 angle1=value;
 value=SharedBurst417H3636C(call4,arg5);
 {register short* table9 __asm__("$9");
 register int product9 __asm__("$9");
 angle0=(angle0&255)<<1;
 table9=SharedBurst417Cos;
 cosine0=(short*)(angle0+(int)table9);
 other=*cosine0;
 __asm__("" : "=r"(other):"0"(other));
 value&=255;
 {register int heldLow __asm__("lo");
 heldLow=other*value;
 __asm__("":"=l"(heldLow),"=r"(angle1):"0"(heldLow),"1"(angle1));
 angle1=(angle1&255)<<1;
 cosine1=(short*)(angle1+(int)table9);
 product9=heldLow;
 __asm__("":"=r"(product9):"0"(product9):"memory");
 }call4=(void*)(int)*cosine1;
 other=product9>>12;
 product9=SharedBurst417Low(other,(int)call4);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 angle0+=(int)sine22;
 other=product9>>12;
 frame.second[0]=other;
 other=*(short*)angle0;
 product9=SharedBurst417Low(other,value);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 call4=(void*)(int)*cosine1;
 other=product9>>12;
 product9=SharedBurst417Low(other,(int)call4);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 angle1+=(int)sine22;
 other=product9>>12;
 frame.second[1]=other;
 other=*(short*)angle1;
 product9=SharedBurst417Low(other,value);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 arg5=(int)vector20;
 __asm__("" : "=r"(arg5):"0"(arg5));
 arg6=owner+12;
 call4=vector20;
 value=product9>>12;
 frame.second[2]=value;
 SharedBurst417H4F194(call4,(void*)arg5,arg6);
 call4=(void*)40;
 value=frame.second[2];
 arg5=70;
 value+=2000;
 frame.second[2]=value;
 value=SharedBurst417H3636C(call4,arg5);
 other=*cosine0;
 value&=255;
 product9=SharedBurst417Low(other,value);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 call4=(void*)(int)*cosine1;
 other=product9>>12;
 product9=SharedBurst417Low(other,(int)call4);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 other=product9>>12;
 frame.third[0]=other;
 other=*(short*)angle0;
 product9=SharedBurst417Low(other,value);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 call4=(void*)(int)*cosine1;
 other=product9>>12;
 product9=SharedBurst417Low(other,(int)call4);
 __asm__("":"=r"(product9):"0"(product9):"memory");
 other=product9>>12;
 frame.third[1]=other;
 other=*(short*)angle1;
 product9=SharedBurst417Low(other,value);
 arg5=0;
 __asm__("" : "=r"(arg5):"0"(arg5):"$6");
 arg6=vector20;
 arg7=frame.third;
 call4=(void*)1;
 {register int (*route3)() __asm__("$3")=SharedBurst417Particle;
 __asm__("":"=r"(product9):"0"(product9),"r"(route3));
 value=product9>>12;
 frame.third[2]=value;
 route3(call4,arg5,arg6,arg7);
 }
 }
 value=count23<20;
 other=1;
 if(value)goto particle_loop;
 SharedBurst417Field(tag,short*,2)=0;
 value=SharedBurst417Field(owner,short*,54);
 owner[72]=other;
 value=**(unsigned char**)(SharedBurst417Models[value]+64);
 owner[60]=other;
 owner[61]=other;
 owner[62]=0;
 owner[63]=other;
 value=(unsigned)value>=2;
 __asm__("" : "=r"(value):"0"(value));
 value=-value&48;
 owner[64]=value;
 done:;
}
#undef SharedBurst417Field


extern int D_8006E020, D_8006E024, D_8007191C, D_80071920;
extern Vector3D D_8007190C;
extern int D_8006C644;
extern short D_800658A0[], D_80065920[];
int func_80019194(Vector3D*, int);
int func_8001A358(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8005629C(Moby*);
void func_level_13_800792C4(Moby *moby) {
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


/* Private words: wrapped table phase, timer helper input, indexed actor gate. */
typedef struct {
    int phase;
    int timer;
    int gateIndex;
} DecodedTimedVectorTag;
extern Moby* D_8006C550;
extern int D_8006C648, D_8006C640;
extern Vector3D DecodedTimedVectorPlayer __asm__("D_80070328");
extern int DecodedTimedVectorPlayerZ __asm__("D_80070328 + 8");
extern unsigned short DecodedTimedVectorCos[] __asm__("D_80065920");
extern unsigned short DecodedTimedVectorSin[] __asm__("D_800658A0");
Vector3D* DecodedTimedVectorAllocate(char) __asm__("func_8002F040");
void func_80055B18(Moby*);
void func_80055D24(Moby*, int);
int func_8004F334(Vector3D*, Vector3D*);
int func_8003BABC(Moby*, int, int);
int func_800359A4(void*, int);
int func_8003636C(int, int);
int rand(void);
void func_level_13_800795C8(Moby* moby) {
    DecodedTimedVectorTag* tag = moby->mobyTag;
    Vector3D* vector;
    int baseZ, playerZ, difference, index;
    register int angle __asm__("$16");
    register int minimum __asm__("$4");
    register int maximum __asm__("$5");
    register int z __asm__("$2");
    register int sine __asm__("$3");
    unsigned char* stateAddress;
    switch (moby->state) {
    case 0:
        if (tag->gateIndex != -1 && D_8006C550[tag->gateIndex].state >= 128) goto retire;
        ((unsigned char*)&moby->colour)[3] = 41;
        ((unsigned char*)&moby->colour)[0] = 128;
        ((unsigned char*)&moby->colour)[1] = 128;
        ((unsigned char*)&moby->colour)[2] = 0;
        moby->state = 1;
        break;
    case 1:
        moby->angle.roll = DecodedTimedVectorCos[tag->phase] >> 7;
        moby->angle.pitch = DecodedTimedVectorSin[tag->phase] >> 7;
        tag->phase = (tag->phase + D_8006C648 * 2) & 255;
        func_80055D24(moby, 4);
        if (func_8004F334(&moby->position, &DecodedTimedVectorPlayer) >= 512) goto idle;
        baseZ = moby->position.z - moby->distanceToGround;
        playerZ = DecodedTimedVectorPlayerZ;
        difference = baseZ - playerZ;
        if (difference >= 0) {
            /* Keep the separate positive/negative retail comparison routes. */
            if (difference < 512) goto collect;
            __asm__ volatile ("" : : : "memory");
            goto idle;
        }
        if (playerZ - baseZ >= 512) goto idle;
collect:
        func_8003BABC(moby, 0, 0);
        for (index = 0; index < 3; index++)
            SpawnParticle(4, 12, (Vector3D*)moby, (Vector3D*)3);
        moby->state=2;
        stateAddress=&moby->state;
        func_8003B7B4(stateAddress, 1, &savedData);
        func_8003B7B4(stateAddress, 1, &unsavedData);
        goto retire;
idle:
        if (!(D_8006C640 & 3)) SpawnParticle(1, 12, (Vector3D*)moby, (Vector3D*)3);
        if (!func_800359A4(&tag->timer, 4)) break;
        vector=DecodedTimedVectorAllocate(3);
        if (!vector) break;
        {
            int rawAngle=rand();
            register Vector3D* destination __asm__("$4")=vector;
            register Vector3D* sourcePosition __asm__("$5")=&moby->position;
            __asm__ volatile ("" : : "r"(destination), "r"(sourcePosition));
            angle=rawAngle;
            func_8004F178(destination, sourcePosition);
        }
        minimum=120;
        maximum=200;
        angle &= 255;
        vector->x += (int)(DecodedTimedVectorCos[angle] << 16) >> 20;
        /* Retail publishes X before loading Z and the second table value. */
        __asm__ volatile ("" : : : "memory");
        z=vector->z;
        sine=DecodedTimedVectorSin[angle];
        z+=200;
        sine<<=16;
        vector->z=z;
        __asm__ volatile ("" : : : "memory");
        __asm__ volatile ("" : : "r"(minimum), "r"(maximum));
        vector->y += sine >> 20;
        tag->timer=func_8003636C(minimum, maximum);
        break;
    case 2:
retire:
        func_80055B18(moby);
        break;
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
void func_level_13_800798D0(void *input) {
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
void func_level_13_8007A444(Moby* moby) {
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

typedef struct { Moby* actor; int timer, trigger; } DecodedParticleAttachment;
extern int D_8006C648,D_8006C578,D_8006C574,D_8006C79C,D_8006C58C;
extern Moby* D_8006C550;
extern int D_80071AB0[][8];
extern unsigned short DecodedCosine[] __asm__("D_80065920");
extern unsigned short DecodedSine[] __asm__("D_800658A0");
extern Vector3D* DecodedParticleAllocation(int) __asm__("func_8002F040");
int rand(void);
extern unsigned char* AttachmentSounds __asm__("D_8006C654");
extern unsigned char AttachmentFlag __asm__("D_80066BC8 + 3");
extern short AttachmentTrigger __asm__("D_800719DC");
/* SCUS-94467 USA Rev0 8007A874..8007AC1C, 235 original words.
 * Reuses verified func_level_10_800794B8; Original tag+8 gated byte flag3, halfword flag1 and sound slot0x23/argument0xA1.
 * Raw field widths, helper identities and fixed-point shifts remain retail.
 * Complete units, producer/helper semantics and caller cadence remain open.
 * Empty constraints retain compiler lifetimes and emit no instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1659.
 */
void func_level_13_8007A874(Moby* moby) {
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
        if (tag->trigger) {
            AttachmentFlag = 3;
            AttachmentTrigger = 1;
            PlaySound(AttachmentSounds[0x23], moby, 0xA1);
        }
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
void func_level_13_8007AC20(Moby* owner) {
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
void DecodedDialogueGateTargetFirst(int,int,int) __asm__("func_80021F8C");
void DecodedDialogueGateTarget(int,int,int) __asm__("func_80021ED8");
int DecodedDialogueGateQuery(Moby*,int) __asm__("func_80037BBC");
void DecodedDialogueGateBegin(Moby*,int,int) __asm__("func_800512E4");
void func_level_13_8007ADAC(Moby* moby) {
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
                    ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))->substate = 1;
                if (tag->targetIndex != -1) {
                    DecodedDialogueGateTargetFirst(tag->targetIndex,0x3B,0);
                    DecodedDialogueGateTarget(tag->targetIndex,0xFC,0);
                }
                func_80055B18(moby);
                break;
            }
        }
        if ((tag->linkedIndex != -1 || tag->targetIndex != -1) && tag->phase == 4) {
            if (tag->linkedIndex != -1)
                ((Moby*)(tag->linkedIndex * sizeof(Moby) + (unsigned int)D_8006C550))->substate = 1;
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

typedef struct { unsigned char reserved00[2]; unsigned char mode,reserved03,reserved04,byte05,reserved06,byte07; unsigned char reserved08[0x18]; int state20; } DecodedCallbackTag;
extern unsigned char D_80071581,D_80066FCC[],D_80070300[];
extern int D_8006E53C,D_8006E344;
int func_80037BBC(Moby*,int);
void func_800512E4(Moby*,int,int);
void func_level_13_8007AFFC(Moby* moby) {
    DecodedCallbackTag* tag=moby->mobyTag;
    switch(moby->state) {
    case 0:
        if(moby->mobyClass==0x2AC) {
            if(!D_80071581)tag->mode=0;
            else {
                register int selected __asm__("$2")=D_80070300[D_80066FCC[0x1A]]&1;
                __asm__("" : "=r"(selected) : "0"(selected));
                if(!selected)selected=1;else selected=2;
                __asm__("" : "=r"(selected) : "0"(selected));
                tag->mode=selected;
            }
        }
        if(tag->mode==2)tag->byte05=0;
        if(!tag->byte05) {
            if(!(D_8006E53C&0x10))goto check;
            if(func_80037BBC(moby,0))goto fire;
            tag->byte07=0;
            __asm__("" : : : "memory");
        }
check:
        if(tag->byte05) {
            if(func_80037BBC(moby,0)) {
fire:
                func_800512E4(moby,0,0);moby->state=1;
            } else tag->byte07=0;
        }
        break;
    case 1:
        if(D_8006E344!=1) {tag->state20=1;moby->state=0;}
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
void func_level_13_8007B14C(Moby* actor) {
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

typedef struct { unsigned char reserved00[0x18];int threshold; } DecodedSpawnThreshold;
extern int D_8006C578,D_8006C574,D_8006C770,D_8006C640;
int rand(void);
void func_80055B18(Moby*);
int func_80055E84(Moby*);
void func_level_13_8007B3F8(Moby* actor) {
    DecodedSpawnThreshold* tag=actor->mobyTag;
    Vector3D velocity,position;
    int count;
    switch(actor->state) {
    case 0:
        actor->lowDrawDistance=0;actor->drawn=0;actor->state=1;break;
    case 1:
        if(D_8006C578-D_8006C574>=0x15 && (rand()&0x3FF)<tag->threshold)SpawnMoby(actor->mobyClass,actor);
        break;
    case 2:
        if(D_8006C770) {func_80055B18(actor);break;}
        count=func_80055E84(actor);
        if(!actor->substate && count>=0xA) {func_8003BABC(actor,0,0);actor->substate=1;}
        if(!(D_8006C640&3) && count>=0x16) {
            func_8004F178(&position,&actor->position);position.z+=0x80;
            velocity.x=(rand()&6)-3;velocity.y=(rand()&6)-3;velocity.z=0x20;
            SpawnParticle(1,0,&position,&velocity);
        }
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007B5B4.
* AI generated;not human reviewed. All837 original instructions,9 selectors
* and one zero padding word must match,including all actual destinations.
* FrameC8 saves S0..S5/RA and retains complete original SP18..A7 locals.
* Original list termination checks the current signed halfword before the
* pointer advances in its branch delay. List acquisition remains at782,
* shared1A358/5629C at664,and activation list at668. Irregular outer-state1
* subdispatch retains every original0/1/9 comparison and return entry.
* Distinct A0/SP18 entries preserve55/69 branch-delay producers and97 reload.
* Saved S1/SP28 has one C producer at the join;the frozen compiler retains
* its original delay-slot duplication at276/287 without a cached pointer.
* Full signed LH samples precede original multiply25/SRA7 and vector SRA4.
* Original color bytes,player base pointers,callback targets,random/current
* entry loops and case8 stores keep every original producer and load delay.
* Known helper/zero-input rand/spawn contracts reuse verified source/header
* and original EXE evidence. Empty metadata consumes full initialized values
* or clobbers only before new producers;it emits zero CPU instructions.
* No opcode assembly,partialHI,fixedFP,overlapping aliases or pipeline change.
* Physical units/fixed point,full helper/caller contracts,cadence beyond
* invocation and synchronized runtime remain open. Confidence is binary
* identity only after all gates. Next:human review and retail captures.
* Falsification: every native/linked word,actual branch/call/table target,
* owned data and full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 d712c455400e0130c0c81fd146c339a2d5c069203efc738b8f910d5d6d155995 */
#define Level13_7B5B4Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level13_7B5B4DataPlaySoundView1() __asm__("PlaySound");
int Level13_7B5B4Call18368View1() __asm__("func_80018368");
int Level13_7B5B4Call19194View1() __asm__("func_80019194");
int Level13_7B5B4Call1A358View1() __asm__("func_8001A358");
int Level13_7B5B4Call1BA30View1() __asm__("func_8001BA30");
void Level13_7B5B4Call34F40View1(void*, int) __asm__("func_80034F40");
int Level13_7B5B4Call35734View1() __asm__("func_80035734");
int Level13_7B5B4Call3585CView1() __asm__("func_8003585C");
int Level13_7B5B4Call359A4View1(void*, int) __asm__("func_800359A4");
int Level13_7B5B4Call36220View1() __asm__("func_80036220");
int Level13_7B5B4Call3636CView1() __asm__("func_8003636C");
int Level13_7B5B4Call363DCView1() __asm__("func_800363DC");
int Level13_7B5B4Call3BABCView1() __asm__("func_8003BABC");
int Level13_7B5B4Call40954View1() __asm__("func_80040954");
int Level13_7B5B4Call4EDE8View1() __asm__("func_8004EDE8");
int Level13_7B5B4Call4F08CView1() __asm__("func_8004F08C");
int Level13_7B5B4Call4F110View1() __asm__("func_8004F110");
int Level13_7B5B4Call4F178View1() __asm__("func_8004F178");
int Level13_7B5B4Call4F194View1() __asm__("func_8004F194");
int Level13_7B5B4Call4F1C8View1() __asm__("func_8004F1C8");
int Level13_7B5B4Call4F334View1() __asm__("func_8004F334");
int Level13_7B5B4Call55B18View1() __asm__("func_80055B18");
int Level13_7B5B4Call55D24View1() __asm__("func_80055D24");
int Level13_7B5B4Call5629CView1() __asm__("func_8005629C");
int Level13_7B5B4DatarandView1(void) __asm__("rand");
extern int Level13_7B5B4Data658A0View1 __asm__("D_800658A0");
extern int Level13_7B5B4Data65920View1 __asm__("D_80065920");
extern int Level13_7B5B4Data66BC8View1 __asm__("D_80066BC8");
extern int Level13_7B5B4Data6C550View1 __asm__("D_8006C550");
extern int Level13_7B5B4Data6C628View1 __asm__("D_8006C628");
extern int Level13_7B5B4Data6C654View1 __asm__("D_8006C654");
extern int Level13_7B5B4Data6C730View1 __asm__("D_8006C730");
extern int Level13_7B5B4Data6C770View1 __asm__("D_8006C770");
extern int Level13_7B5B4Data6E044View1 __asm__("D_8006E044");
extern int Level13_7B5B4Data70328View1 __asm__("D_80070328");
extern int Level13_7B5B4Data71900View1 __asm__("D_80071900");
extern int Level13_7B5B4Data7190CView1 __asm__("D_8007190C");
extern int Level13_7B5B4Data71924View1 __asm__("D_80071924");
extern short Level13_7B5B4Data719DCView1 __asm__("D_800719DC");
extern void*(*Level13_7B5B4DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern void*(*Level13_7B5B4DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
void func_level_13_8007B5B4(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5");
    register void *ownerRecord19 __asm__("$19");
    register int privateRecord20 __asm__("$20"), retainedStateAddressOrRecord16 __asm__("$16"), retainedFlagAddressOrVector17 __asm__("$17"), retainedListOffsetOrVector18 __asm__("$18"), retainedPlayerPrivate21 __asm__("$21");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4;
    }
    originalFrame;
    int temporaryWord2;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord1;
    int temporaryWord9;
    int temporaryWord3;
    ownerRecord19 = input;
    __asm__("":"=r"(ownerRecord19):"0"(ownerRecord19));
    retainedStateAddressOrRecord16 = Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x48);
    privateRecord20 = Level13_7B5B4Field(ownerRecord19, void **, 0);
    switch (retainedStateAddressOrRecord16) {
    case 0:
        temporaryWord9 = Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49);
        switch (temporaryWord9) {
        case 0:
            Level13_7B5B4Field(privateRecord20, int *, 0xC) = (int) Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x46);
            Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 1U;
            if (Level13_7B5B4Call36220View1(ownerRecord19 + 0xC, privateRecord20 + 0x20, 0, 0x1F4) != 0) {
                Level13_7B5B4Field(privateRecord20, int *, 0x38) = 1;
            }
        case 1:
            retainedFlagAddressOrVector17 = 0;
            if (({rawWord2 = Level13_7B5B4Call4F334View1((int)ownerRecord19+12, (int)&Level13_7B5B4Data70328View1);rawWord2 = rawWord2 < 512;argumentWord4 = (int)&originalFrame.sp18;rawWord2;})) {
                rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int*, 8);
                rawWord3 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int*, 68);
                argumentWord4 = Level13_7B5B4Field(ownerRecord19, int*, 20);
                rawWord2 -= rawWord3;
                rawWord2 -= argumentWord4;
                rawWord2 -= 700;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if (({rawWord2 = rawWord2 < 256;argumentWord4 = (int)&originalFrame.sp18;rawWord2;})) {
                    argumentWord4 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, void**, 592);
                    retainedStateAddressOrRecord16 = Level13_7B5B4Field(argumentWord4, int*, 0);
                    if (Level13_7B5B4Field(retainedStateAddressOrRecord16, void **, 0x30) == 0) {
                        Level13_7B5B4Call3BABCView1(argumentWord4, 1, 0);
                        Level13_7B5B4Field(retainedStateAddressOrRecord16, void **, 0x30) = ownerRecord19;
                        Level13_7B5B4Field(retainedStateAddressOrRecord16, int *, 0x34) = 1;
                        Level13_7B5B4Field(privateRecord20, int *, 0x10) = (int) (Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x46) - Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, unsigned char *, 0xE));
                        Level13_7B5B4Field(ownerRecord19, short *, 0x38) = 0x2BC;
                        Level13_7B5B4Field(ownerRecord19, int *, 8) = 0;
                        Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 2U;
                        Level13_7B5B4Field(privateRecord20, int *, 0x38) = 0;
                    }
                    else {
                        goto reloadOriginalFrameArgument;
                    }
                }
                else {
                    goto copyOriginalOwnerVector;
                }
            }
            else {
                goto copyOriginalOwnerVector;
                reloadOriginalFrameArgument:argumentWord4 = (int)&originalFrame.sp18;
            copyOriginalOwnerVector:
                __asm__("":::"$16", "memory");
                retainedStateAddressOrRecord16 = (int)ownerRecord19+12;
                Level13_7B5B4Call4F178View1(argumentWord4, retainedStateAddressOrRecord16);
                originalFrame.sp20 += 0x15E;
                if (Level13_7B5B4Call1BA30View1(&originalFrame.sp18, 0x15E, 0, 0, 0, ownerRecord19) != 0) {
                    Level13_7B5B4Call4F178View1(&originalFrame.sp18, (int)&Level13_7B5B4Data7190CView1);
                    retainedFlagAddressOrVector17 = 1;
                }
                if (Level13_7B5B4Call19194View1(&originalFrame.sp18, 0x15E) != 0) {
                    Level13_7B5B4Call4F178View1(&originalFrame.sp18, (int)&Level13_7B5B4Data7190CView1);
                    retainedFlagAddressOrVector17 = 1;
                }
                if (retainedFlagAddressOrVector17 != 0) {
                    originalFrame.sp20 -= 0x15E;
                    Level13_7B5B4Call4F178View1(retainedStateAddressOrRecord16, &originalFrame.sp18);
                    if (Level13_7B5B4Call1A358View1(&originalFrame.sp18, 0x1DE) == 0) {
                        Level13_7B5B4Field(privateRecord20, int *, 0x14) = 0;
                        Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 3U;
                    }
                }
                temporaryWord11 = 1;
                if (!(Level13_7B5B4Field((int)&Level13_7B5B4Data66BC8View1, unsigned char *, 2) & 1)) {
                    retainedListOffsetOrVector18 = Level13_7B5B4Field(((Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x43) * 4) + Level13_7B5B4Data6C730View1), int*, 0);
                    do {
                        temporaryWord1 = Level13_7B5B4Field(retainedListOffsetOrVector18, unsigned short*, 0);
                        if (Level13_7B5B4Field(Level13_7B5B4Field((((temporaryWord1 & 0x7FFF) * 0x58) + Level13_7B5B4Data6C550View1), int*, 0), int *, 0x38) == 0) {
                            temporaryWord11 = 0;
                        }
                        retainedListOffsetOrVector18 += 2;
                    }
                    while ((short)temporaryWord1 >= 0);
                    if (temporaryWord11 != 0) {
                        retainedListOffsetOrVector18 = Level13_7B5B4Field(((Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x43) * 4) + Level13_7B5B4Data6C730View1), int*, 0);
                        do {
                            retainedStateAddressOrRecord16 = Level13_7B5B4Data6C550View1 + ((Level13_7B5B4Field(retainedListOffsetOrVector18, unsigned short*, 0) & 0x7FFF) * 0x58);
                            retainedFlagAddressOrVector17 = Level13_7B5B4Field(retainedStateAddressOrRecord16, void **, 0);
                            Level13_7B5B4Field(retainedFlagAddressOrVector17, short *, 0x3C) = Level13_7B5B4Call3636CView1(0xF0, 0x168);
                            Level13_7B5B4Field(retainedStateAddressOrRecord16, signed char *, 0x48) = 2;
                            Level13_7B5B4Field(retainedFlagAddressOrVector17, signed char *, 0x3E) = Level13_7B5B4Call363DCView1(5, 0xC);
                            Level13_7B5B4Field(retainedFlagAddressOrVector17, signed char *, 0x3F) = Level13_7B5B4Call3636CView1(0, 0x1E);
                            rawWord2 = Level13_7B5B4Field(retainedListOffsetOrVector18, short*, 0);
                            __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(retainedListOffsetOrVector18));
                            retainedListOffsetOrVector18 += 2;
                        }
                        while (rawWord2 >= 0);
                        Level13_7B5B4Field((int)&Level13_7B5B4Data66BC8View1, unsigned char *, 2) = 3U;
                        Level13_7B5B4Data719DCView1 = 1;
                        Level13_7B5B4DataPlaySoundView1(Level13_7B5B4Field(Level13_7B5B4Data6C654View1, unsigned char *, 0x23), ownerRecord19, 0xA1);
                        temporaryWord3 = Level13_7B5B4DataSpawnMobyView1(0xD3, ownerRecord19);
                        if (temporaryWord3 != 0) {
                            Level13_7B5B4Call4F178View1(temporaryWord3 + 0xC, (int)&Level13_7B5B4Data70328View1);
                            rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, unsigned char*, 14);
                            __asm__("":"=r"(rawWord2):"0"(rawWord2));
                            rawWord2 *= 2;
                            rawWord3 = Level13_7B5B4Field((int)&Level13_7B5B4Data65920View1, short*, rawWord2);
                            __asm__("":"=r"(rawWord3):"0"(rawWord3));
                            rawWord2 = rawWord3*25;
                            rawWord3 = Level13_7B5B4Field(temporaryWord3, int*, 12);
                            rawWord2 >>= 7;
                            rawWord3 += rawWord2;
                            Level13_7B5B4Field(temporaryWord3, int*, 12) = rawWord3;
                            rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, unsigned char*, 14);
                            rawWord3 = Level13_7B5B4Field(temporaryWord3, int*, 20);
                            rawWord2 *= 2;
                            argumentWord4 = Level13_7B5B4Field((int)&Level13_7B5B4Data658A0View1, short*, rawWord2);
                            rawWord3 += 500;
                            Level13_7B5B4Field(temporaryWord3, int*, 20) = rawWord3;
                            __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "m"(Level13_7B5B4Field(temporaryWord3, int*, 20)));
                            rawWord3 = Level13_7B5B4Field(temporaryWord3, int*, 16);
                            __asm__("":::"$2", "memory");
                            rawWord2 = argumentWord4*25;
                            rawWord2 >>= 7;
                            rawWord3 += rawWord2;
                            Level13_7B5B4Field(temporaryWord3, int*, 16) = rawWord3;
                        }
                    }
                }
            }
            goto checkOriginalListActivation;
        case 2:
            temporaryWord10 = Level13_7B5B4Field(privateRecord20, int *, 0x10);
            retainedPlayerPrivate21 = Level13_7B5B4Field(Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, void **, 0x250), int*, 0);
            if (temporaryWord10 != 0) {
                temporaryWord4 = temporaryWord10 - 6;
                if (temporaryWord10 > 0) {
                    Level13_7B5B4Field(privateRecord20, int *, 0x10) = temporaryWord4;
                    if (temporaryWord4 < 0) {
                        Level13_7B5B4Field(privateRecord20, int *, 0x10) = 0;
                    }
                }
                else {
                    temporaryWord5 = temporaryWord10 + 6;
                    Level13_7B5B4Field(privateRecord20, int *, 0x10) = temporaryWord5;
                    if (temporaryWord5 > 0) {
                        Level13_7B5B4Field(privateRecord20, int *, 0x10) = 0;
                    }
                }
            }
            retainedFlagAddressOrVector17 = (int)&originalFrame.sp28;
            rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, unsigned char*, 12);
            __asm__("":::"$4", "memory");
            argumentWord4 = retainedFlagAddressOrVector17;
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 68) = rawWord2;
            rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, unsigned char*, 13);
            __asm__("":::"$18", "memory");
            retainedListOffsetOrVector18 = (int)ownerRecord19+12;
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 69) = rawWord2;
            rawWord3 = Level13_7B5B4Field(privateRecord20, int*, 16);
            rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, unsigned char*, 14);
            argumentWord5 = retainedListOffsetOrVector18;
            rawWord2 += rawWord3;
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 70) = rawWord2;
            Level13_7B5B4Call4F178View1(argumentWord4, argumentWord5);
            originalFrame.sp30 += 0x80;
            Level13_7B5B4Call4F178View1(&originalFrame.sp38, retainedListOffsetOrVector18);
            originalFrame.sp40 -= 0x80;
            if ((Level13_7B5B4Call18368View1(retainedFlagAddressOrVector17, &originalFrame.sp38) != 0) && (({retainedStateAddressOrRecord16 = (int)&Level13_7B5B4Data71924View1;Level13_7B5B4Call40954View1(Level13_7B5B4Field(retainedStateAddressOrRecord16, int*, 0));}) == 1)) {
                Level13_7B5B4Field(Level13_7B5B4Field(Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, void **, 0x250), int*, 0), int *, 0x30) = 0;
                Level13_7B5B4Call4F178View1(retainedListOffsetOrVector18, retainedStateAddressOrRecord16-36);
                Level13_7B5B4Field(ownerRecord19, int *, 0x54) = (int) Level13_7B5B4Field(ownerRecord19, int *, 0x14);
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x57) = 0x80;
                Level13_7B5B4Field(privateRecord20, int *, 0x14) = 0;
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 4U;
            }
            else {
                if (Level13_7B5B4Field(retainedPlayerPrivate21, int *, 0x38) != 0) {
                    if ((({argumentWord5 = (int)&Level13_7B5B4Data6E044View1;rawWord3 = Level13_7B5B4Field(argumentWord5, int*, 0);rawWord3;}) == 38) && (Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x4C) == 0)) {
                        Level13_7B5B4Call4F178View1((int)ownerRecord19+12, argumentWord5-36);
                        rawWord2 = Level13_7B5B4Field(ownerRecord19, int*, 20);
                        rawWord3 = 32;
                        Level13_7B5B4Field(ownerRecord19, unsigned char*, 76) = rawWord3;
                        rawWord2 -= 512;
                        goto storeOriginalHeight;
                    }
                    Level13_7B5B4Call4F178View1(&originalFrame.sp48, ownerRecord19 + 0xC);
                    originalFrame.sp50 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int *, 8);
                    rawWord2 = Level13_7B5B4Call1A358View1(&originalFrame.sp48, Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int *, 8) - Level13_7B5B4Field(ownerRecord19, int *, 0x14));
                    originalFrame.sp50 = rawWord2;
                    if (rawWord2 != 0) {
                    storeOriginalHeight:
                        Level13_7B5B4Field(ownerRecord19, int *, 0x14) = rawWord2;
                    }
                    Level13_7B5B4Field(retainedPlayerPrivate21, int *, 0x30) = 0;
                    Level13_7B5B4Field(privateRecord20, int *, 0x14) = (int) ((int) Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int *, 0xA0) >> 5);
                    Level13_7B5B4Field(ownerRecord19, short *, 0x38) = 0;
                    Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 3U;
                }
                __asm__("":::"$4", "memory");
                argumentWord4 = (int)ownerRecord19+12;
                goto callSharedOriginalFloorPair;
            }
            goto checkOriginalListActivation;
        case 3:
            if (Level13_7B5B4Field(ownerRecord19, int *, 0x14) < 0x400) {
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 8U;
                return;
            }
            retainedListOffsetOrVector18 = (int)&originalFrame.sp48;
            argumentWord4 = retainedListOffsetOrVector18;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            __asm__("":::"$17", "memory");
            retainedFlagAddressOrVector17 = (int)ownerRecord19+12;
            Level13_7B5B4Call4F178View1(argumentWord4, retainedFlagAddressOrVector17);
            Level13_7B5B4Call4F178View1(&originalFrame.sp58, retainedFlagAddressOrVector17);
            temporaryWord6 = Level13_7B5B4Field(privateRecord20, int *, 0x14) - 8;
            Level13_7B5B4Field(privateRecord20, int *, 0x14) = temporaryWord6;
            if (temporaryWord6 < -0xC0) {
                Level13_7B5B4Field(privateRecord20, int *, 0x14) = -0xC0;
            }
            originalFrame.sp60 += Level13_7B5B4Field(privateRecord20, int *, 0x14);
            if (Level13_7B5B4Call18368View1(&originalFrame.sp48, &originalFrame.sp58) != 0) {
                Level13_7B5B4Call4F178View1(retainedFlagAddressOrVector17, (int)&Level13_7B5B4Data71900View1);
                if (Level13_7B5B4Call40954View1(Level13_7B5B4Data71924View1) == 1) {
                    Level13_7B5B4Field(ownerRecord19, int *, 0x54) = (int) Level13_7B5B4Field(ownerRecord19, int *, 0x14);
                    Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x57) = 0x80;
                    Level13_7B5B4Field(privateRecord20, int *, 0x14) = 0;
                    Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 4U;
                }
                else {
                    if (Level13_7B5B4Call36220View1(retainedFlagAddressOrVector17, privateRecord20 + 0x20, 0, 0x1F4) != 0) {
                        Level13_7B5B4Field(privateRecord20, int *, 0x38) = 1;
                    }
                    Level13_7B5B4Call55D24View1(ownerRecord19, 3);
                    Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 1U;
                }
            }
            else {
                originalFrame.sp60 += 0x15E;
                if (Level13_7B5B4Call1BA30View1(&originalFrame.sp58, 0x15E, 0, 0, 0, ownerRecord19) != 0) {
                    Level13_7B5B4Call4F178View1(&originalFrame.sp58, (int)&Level13_7B5B4Data7190CView1);
                }
                if (Level13_7B5B4Call19194View1(&originalFrame.sp58, 0x15E) != 0) {
                    Level13_7B5B4Call4F178View1(&originalFrame.sp58, (int)&Level13_7B5B4Data7190CView1);
                }
                originalFrame.sp60 -= 0x15E;
                Level13_7B5B4Call4F178View1(retainedFlagAddressOrVector17, &originalFrame.sp58);
            }
            __asm__("":::"$4", "memory");
            argumentWord4 = (int)ownerRecord19+12;
            goto callSharedOriginalFloorPair;
        case 4:
            Level13_7B5B4Field(privateRecord20, int *, 0x14) = (int) (Level13_7B5B4Field(privateRecord20, int *, 0x14) + 0x10);
            Level13_7B5B4Field(ownerRecord19, int *, 0x14) = (int) (Level13_7B5B4Field(ownerRecord19, int *, 0x14) - 0x10);
            if (Level13_7B5B4Field(privateRecord20, int *, 0x14) >= 0x201) {
                Level13_7B5B4DataSpawnMobyView1(0x4C, ownerRecord19);
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 8U;
            }
            rawWord2 = Level13_7B5B4DatarandView1();
            rawWord2 = (rawWord2&255)*2;
            retainedFlagAddressOrVector17 = (int)&originalFrame.sp78;
            argumentWord4 = retainedFlagAddressOrVector17;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord3 = Level13_7B5B4Field((int)&Level13_7B5B4Data65920View1, short*, rawWord2);
            __asm__("":::"$16", "memory");
            retainedStateAddressOrRecord16 = (int)&originalFrame.sp68;
            __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(retainedStateAddressOrRecord16));
            rawWord3 >>= 4;
            originalFrame.sp68 = rawWord3;
            rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data658A0View1, short*, rawWord2);
            __asm__("":::"$5", "memory");
            argumentWord5 = retainedStateAddressOrRecord16;
            originalFrame.sp70 = 0;
            __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord5), "m"(originalFrame.sp70));
            rawWord2 >>= 4;
            originalFrame.sp6C = rawWord2;
            Level13_7B5B4Call4F178View1(argumentWord4, argumentWord5);
            Level13_7B5B4Call4F194View1(&originalFrame.sp68, &originalFrame.sp68, ownerRecord19 + 0xC);
            originalFrame.sp70 += Level13_7B5B4Field(privateRecord20, int *, 0x14);
            Level13_7B5B4Call4F110View1(&originalFrame.sp78, 5);
            originalFrame.sp80 = 0x10;
            Level13_7B5B4DataSpawnParticleView1(1, 0x37, &originalFrame.sp68, &originalFrame.sp78);
            goto checkOriginalListActivation;
        case 5:
            retainedStateAddressOrRecord16 = (int)&originalFrame.sp88;
            argumentWord4 = retainedStateAddressOrRecord16;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            __asm__("":::"$17", "memory");
            retainedFlagAddressOrVector17 = (int)ownerRecord19+12;
            Level13_7B5B4Call4F1C8View1(argumentWord4, Level13_7B5B4Field(privateRecord20, void**, 24)+12, retainedFlagAddressOrVector17);
            originalFrame.sp90 += 0x200;
            temporaryWord7 = Level13_7B5B4Call4EDE8View1(&originalFrame.sp88, 1);
            retainedListOffsetOrVector18 = temporaryWord7 < 0x21;
            if (retainedListOffsetOrVector18 == 0) {
                Level13_7B5B4Call4F08CView1(&originalFrame.sp88, temporaryWord7, 0x20);
            }
            Level13_7B5B4Call4F194View1(retainedFlagAddressOrVector17, retainedFlagAddressOrVector17, &originalFrame.sp88);
            if ((Level13_7B5B4Call3585CView1(ownerRecord19, Level13_7B5B4Field(Level13_7B5B4Field(privateRecord20, void **, 0x18), unsigned char *, 0x46), 6, 3, 1, 0) != 0) && (retainedListOffsetOrVector18 != 0)) {
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 6U;
            }
            Level13_7B5B4Call4F1C8View1(&originalFrame.sp88, (int)&Level13_7B5B4Data70328View1, ownerRecord19 + 0xC);
            originalFrame.sp90 -= 0x15E;
            temporaryWord8 = Level13_7B5B4Call4EDE8View1(&originalFrame.sp88, 1);
            if (temporaryWord8 < (Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int *, 0x44) + 0x15E)) {
                Level13_7B5B4Call4F08CView1(&originalFrame.sp88, temporaryWord8, 0x20);
                Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, int *, 0x20C) = 0x10000400;
                Level13_7B5B4Call4F178View1((int)&Level13_7B5B4Data70328View1 + 0x21C, &originalFrame.sp88);
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 5U;
            }
            goto checkOriginalListActivation;
        case 6:
            Level13_7B5B4DataSpawnParticleView1(0x10, 0xC, ownerRecord19, 0);
            Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x49) = 7U;
            Level13_7B5B4Field(Level13_7B5B4Field(privateRecord20, void **, 0x18), signed char *, 0x49) = 9;
            Level13_7B5B4Call55D24View1(ownerRecord19, 3);
            goto checkOriginalListActivation;
        case 7:
            Level13_7B5B4Call55B18View1(ownerRecord19);
            goto checkOriginalListActivation;
        case 8:
            retainedStateAddressOrRecord16 = ownerRecord19 + 0xC;
            Level13_7B5B4Field(privateRecord20, int *, 0x38) = 0;
            Level13_7B5B4Call4F178View1(retainedStateAddressOrRecord16, privateRecord20);
            Level13_7B5B4DataSpawnParticleView1(0x10, 0xC, ownerRecord19, 0);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 3;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 68) = 0;
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 69) = 0;
            rawWord3 = Level13_7B5B4Field(privateRecord20, int*, 12);
            rawWord2 = 1;
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 73) = rawWord2;
            Level13_7B5B4Field(ownerRecord19, int*, 84) = 0;
            Level13_7B5B4Field(ownerRecord19, unsigned char*, 70) = rawWord3;
            Level13_7B5B4Call55D24View1(argumentWord4, argumentWord5);
            argumentWord4 = retainedStateAddressOrRecord16;
        callSharedOriginalFloorPair:
            Level13_7B5B4Call1A358View1(argumentWord4, 0x3000);
            Level13_7B5B4Call5629CView1(ownerRecord19);
        default:
        checkOriginalListActivation:
            rawWord2 = Level13_7B5B4Field(ownerRecord19, unsigned char*, 0x49);
            rawWord2 -= 2;
            rawWord2 = (unsigned)rawWord2 < 2;
            retainedFlagAddressOrVector17 = (int)&originalFrame.sp98;
            if (rawWord2){
                retainedStateAddressOrRecord16 = Level13_7B5B4Field(Level13_7B5B4Data6C730View1, void**, 24);
            scanOriginalActorList:
                rawWord3 = Level13_7B5B4Field(retainedStateAddressOrRecord16, unsigned short*, 0);
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord3 &= 32767;
                rawWord2 = rawWord3*11;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                rawWord3 = Level13_7B5B4Data6C550View1;
                retainedListOffsetOrVector18 = rawWord2*8;
                argumentWord5 = retainedListOffsetOrVector18+rawWord3;
                if (!(Level13_7B5B4Field(argumentWord5, unsigned char*, 72)&128)){
                    Level13_7B5B4Call4F178View1(retainedFlagAddressOrVector17, argumentWord5+12);
                    originalFrame.spA0 += 512;
                    Level13_7B5B4Call4F1C8View1(retainedFlagAddressOrVector17, retainedFlagAddressOrVector17, (int)ownerRecord19+12);
                    if (Level13_7B5B4Call4EDE8View1(retainedFlagAddressOrVector17, 1) < 512) goto acquireOriginalListActor;
                }
                rawWord2 = Level13_7B5B4Field(retainedStateAddressOrRecord16, short*, 0);
                __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(retainedStateAddressOrRecord16));
                retainedStateAddressOrRecord16 += 2;
                if (rawWord2 >= 0) goto scanOriginalActorList;
            }
            return;
        }
        break;
    case 2:
        if (Level13_7B5B4Call359A4View1(privateRecord20 + 0x3F, 1) != 0) {
            __asm__("":"=r"(retainedStateAddressOrRecord16):"0"(retainedStateAddressOrRecord16));
            if (Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x3D) != retainedStateAddressOrRecord16) {
                Level13_7B5B4Data6C770View1 = 0;
                Level13_7B5B4Field(ownerRecord19, signed char *, 0x40) = 0x72;
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x3D) = 2U;
                Level13_7B5B4Field(ownerRecord19, signed char *, 0x3F) = 0;
                Level13_7B5B4Call35734View1(ownerRecord19);
            }
            if ((Level13_7B5B4Call359A4View1(privateRecord20 + 0x3C, 2) != 0) && (Level13_7B5B4Data6C770View1 != 0)) {
                Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x48) = 0U;
                Level13_7B5B4Call34F40View1(ownerRecord19, 0);
                return;
            }
            Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x46) = (unsigned char) (Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x46) + Level13_7B5B4Field(privateRecord20, unsigned char *, 0x3E));
            return;
        }
        break;
    case 1:__asm__("":"=r"(retainedStateAddressOrRecord16):"0"(retainedStateAddressOrRecord16));
        rawWord3 = Level13_7B5B4Field(ownerRecord19, unsigned char*, 0x49);
        if (rawWord3 == retainedStateAddressOrRecord16) return;
        if (({rawWord2 = rawWord3 < 2;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})){
            if (rawWord3 == 0) goto originalOuterState1Case0;
            return;
        }
        if (rawWord3 == 9) goto originalOuterState1Case9;
        return;
    originalOuterState1Case0:
        rawWord3 = Level13_7B5B4Field(privateRecord20, int*, 28);
        rawWord2 = rawWord3*88;
        rawWord3 = Level13_7B5B4Data6C550View1;
        rawWord2 += rawWord3;
        Level13_7B5B4Field(rawWord2, int*, 8) = 0;
        Level13_7B5B4Field(ownerRecord19, unsigned char*, 73) = 1;
        return;
    acquireOriginalListActor:
        rawWord2 = Level13_7B5B4Field((int)&Level13_7B5B4Data70328View1, void**, 592);
        rawWord3 = Level13_7B5B4Field(rawWord2, int*, 0);
        rawWord2 = Level13_7B5B4Data6C550View1;
        rawWord2 += retainedListOffsetOrVector18;
        Level13_7B5B4Field(rawWord3, int*, 48) = 0;
        Level13_7B5B4Field(privateRecord20, int*, 24) = rawWord2;
        rawWord2 = 5;
        Level13_7B5B4Field(ownerRecord19, unsigned char*, 73) = rawWord2;
        return;
    originalOuterState1Case9:
        temporaryWord2 = Level13_7B5B4Data6C550View1 + (Level13_7B5B4Field(privateRecord20, int *, 0x1C) * 0x58);
        Level13_7B5B4Field(temporaryWord2, signed char *, 0x48) = 0;
        Level13_7B5B4Field(temporaryWord2, unsigned char *, 0x46) = (unsigned char) Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x46);
        Level13_7B5B4Field(temporaryWord2, unsigned char *, 0x4C) = (unsigned char) Level13_7B5B4Field(ownerRecord19, unsigned char *, 0x4C);
        Level13_7B5B4Field(Level13_7B5B4Field(temporaryWord2, void **, 0), unsigned char *, 5) = 0xFF;
        Level13_7B5B4Data6C628View1 += 1;
        Level13_7B5B4Call55D24View1(temporaryWord2, 1);
        Level13_7B5B4Call3BABCView1(ownerRecord19, 0, 0);
        Level13_7B5B4Call55B18View1(ownerRecord19);
        break;
    }
}
#undef Level13_7B5B4Field


/**
 * MobyUpdate_88() - func_level_13_8007C2C8()
 * Thieves
 * https://decomp.me/scratch/JgS7L
 */
/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C2C8.
 * AI generated; not human reviewed. All1366 native words,seven selectors
 * and one zero pad must match. FrameC8 (200 bytes) saves S0..S4/RA at
 * SPB0..C4. Explicit local storage spans SP20..AF;outgoing home/stack
 * arguments occupy SP00..1F. No FP/SP binding or overlapping live fixed
 * aliases exists. Every local read has its original initialized producer;
 * there are no incoming saved-register reads or reserve-content reads.
 * Original state0..6 and substates retain descriptor scans,callbacks,
 * vector helpers,byte/halfword widths,timers,field resets and particles.
 * All five index/point/heading phases use the ORIGINAL ordering:1st E880
 * executes before path reloads;its full return stays in V0 while S0 still
 * holds the old index and then point address. Both point coordinates load
 * before S0 becomes that return. The point address is never read through
 * a heading scalar. No decoder-created pointer/scalar lifetime is assumed.
 * Counts/current/step are signed16;records stride16;all guarded dynamic
 * remainder DIV paths retain original zero/overflow traps. Each turn step
 * uses current+(count+step) BEFORE remainder,not current+step first.
 * All seven variable MULT sites form complete signed64 products from
 * staged signed32 operands. Five high and two low captures use complete
 * initialized inputs;low32 narrowing precedes original signed>>12.
 * Difficulty math shifts the OLD private10 by12 in the original32-bit
 * domain,then uses91A2B3C5 orC22E4507 high+input before signed>>11/12 and
 * ONE sign correction. The /300 path uses1B4E81B5 high>>5 and sign.
 * Falsifiable vectors:oldtimer3600 gives4096 for /3600,2730 for /5400,
 * and2048 for /7200. /300(-4500)=-15. low32(32767*32767)>>12=262128.
 * Upper constant values are complete original LUI register values in
 * ordinary C;identities preserve the two original load paths before ORI.
 * They are unrelated to HI/LO capture;no partial product input exists.
 * Original timer update follows these calculations and clamps at7200.
 * Complete original state witnesses retain unshifted V1 at dispatch;
 * the original table offset remains V0. The original redundant constant1
 * and separately stored zero/80 paths retain their physical producers.
 * Empty metadata consumes complete initialized original values,addresses,
 * constants or freshly written fields;dead GP clobbers precede fresh
 * original producers. It emits zero CPU instructions. No opcode asm exists.
 * Helper views use identified original contracts and native argument widths.
 * Compiler,filter,flags,actual transfer/data targets and all EXE/overlay
 * retail hashes remain unchanged and mandatory. Confidence after gates is
 * binary identity. Complete allocation/caller/helper chains,units,fixed-
 * point domains,cadence beyond invocation,Rev1 mapping and synchronized
 * retail runtime verification remain open. Next:human review and captures.
 */
/* Original assembly SHA256 3317c3a9f94b17f282a62478b140f157f1231685486caed99a283e4b1335d80e */
#define Level13_7C2C8Keep(v) __asm__("":"=r"(v):"0"(v))
#define Level13_7C2C8MultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level13_7C2C8CaptureHigh(dst) do{int wholeCapturedHigh;__asm__("":"=h"(wholeCapturedHigh):"x"(completeSignedProduct));(dst)=wholeCapturedHigh;Level13_7C2C8Keep(dst);}while(0)
#define Level13_7C2C8CaptureLow(dst) do{int wholeCapturedLow;__asm__("":"=l"(wholeCapturedLow):"x"(completeSignedProduct));(dst)=wholeCapturedLow;Level13_7C2C8Keep(dst);}while(0)
#define Level13_7C2C8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void Level13_7C2C8Call13D44View1(void*,int,void*,int) __asm__("func_80013D44");
int Level13_7C2C8Call1A358View1(void*,int) __asm__("func_8001A358");
void Level13_7C2C8Call34F40View1(void*,int) __asm__("func_80034F40");
int Level13_7C2C8Call35194View1(void*,void*) __asm__("func_80035194");
int Level13_7C2C8Call3573CView1(void*,int,int,int) __asm__("func_8003573C");
int Level13_7C2C8Call3585CView1(void*,int,int,int,int,int) __asm__("func_8003585C");
int Level13_7C2C8Call35A80View1(void*,void*,int,int,int,int,int,int) __asm__("func_80035A80");
int Level13_7C2C8Call3636CView1(int,int) __asm__("func_8003636C");
int Level13_7C2C8Call363DCView1(int,int) __asm__("func_800363DC");
int Level13_7C2C8Call365E4View1(void*,void*,int,int,int) __asm__("func_800365E4");
void Level13_7C2C8Call369B8View1(void*,int) __asm__("func_800369B8");
void Level13_7C2C8Call37014View1(void*) __asm__("func_80037014");
void Level13_7C2C8Call38BF8View1(void*,void*,int,int) __asm__("func_80038BF8");
void Level13_7C2C8Call3BA00View1(void*) __asm__("func_8003BA00");
int Level13_7C2C8Call4E880View1(int,int,int) __asm__("func_8004E880");
void Level13_7C2C8Call4F110View1(void*,int) __asm__("func_8004F110");
void Level13_7C2C8Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level13_7C2C8Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
void Level13_7C2C8Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
int Level13_7C2C8Call4F264View1(int,int) __asm__("func_8004F264");
int Level13_7C2C8Call4F334View1(void*,void*) __asm__("func_8004F334");
void Level13_7C2C8Call55B18View1(void*) __asm__("func_80055B18");
void Level13_7C2C8Call55D24View1(void*,int) __asm__("func_80055D24");
void Level13_7C2C8Call55F14View1(void*,int,void*) __asm__("func_80055F14");
extern unsigned char Level13_7C2C8Data658A0View1 __asm__("D_800658A0");
extern unsigned char Level13_7C2C8Data65920View1 __asm__("D_80065920");
extern int Level13_7C2C8Data6C550View1 __asm__("D_8006C550");
extern int Level13_7C2C8Data6C58CView1 __asm__("D_8006C58C");
extern int Level13_7C2C8Data6C648View1 __asm__("D_8006C648");
extern int Level13_7C2C8Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level13_7C2C8Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level13_7C2C8Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level13_7C2C8Data6E048View1 __asm__("D_8006E048");
extern unsigned char Level13_7C2C8Data70300View1 __asm__("D_80070300");
extern int Level13_7C2C8Data70328View1 __asm__("D_80070328");
extern void*(*Level13_7C2C8DataSpawnParticleView1)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_13_8007C2C8(void* ownerParameter) {
    register int indexPointHeadingOrVector16 __asm__("$16"),playerBasePathIndexOrVector17 __asm__("$17"),boundedHelperArgumentOrVector18 __asm__("$18"),privateRecord19 __asm__("$19"),owner20 __asm__("$20"),unusedRole21 __asm__("$21"),unusedRole22 __asm__("$22"),unusedRole23 __asm__("$23");
    register int resultOrField2 __asm__("$2"),fieldOrIntermediate3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrField6 __asm__("$6"),argumentOrField7 __asm__("$7"),pointCoordinateOrTable8 __asm__("$8"),capturedHalf9 __asm__("$9"),unusedScratch10 __asm__("$10");
    long long completeSignedProduct;
    struct {
        int sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC;
    }
    originalFrame;
    int temp_a3_11;
    int temp_a3_12;
    int temp_v0_10;
    int temp_v0_11;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_8;
    int temp_v0_9;
    int var_a3;
    int temp_v1_14;
    int temp_v1_24;
    int temp_v1_26;
    int temp_v1_2;
    int temp_a0;
    int temp_v0_12;
    int temp_v0_13;
    int temp_v0_14;
    int temp_v0_15;
    int temp_v1_25;
    owner20=(int)ownerParameter;
    Level13_7C2C8Keep(owner20);
    resultOrField2=3;
    fieldOrIntermediate3=Level13_7C2C8Field(owner20,unsigned char*,72);
    privateRecord19=Level13_7C2C8Field(owner20,int*,0);
    if(fieldOrIntermediate3==resultOrField2)goto block_4;
    resultOrField2=6;
    if(fieldOrIntermediate3==resultOrField2)goto testOriginalStateRange;
    resultOrField2=Level13_7C2C8Field(owner20,int*,24);
    argumentOrField5=privateRecord19+28;
    if(!resultOrField2)goto block_4;
    Level13_7C2C8Call38BF8View1(ownerParameter,argumentOrField5,1,3);
    Level13_7C2C8Field(privateRecord19,unsigned char*,47)=0;
    fieldOrIntermediate3=Level13_7C2C8Field(owner20,unsigned char*,72);
block_4:
    testOriginalStateRange:resultOrField2=(unsigned int)fieldOrIntermediate3<7U;
    if(!resultOrField2)goto block_138;
    switch (fieldOrIntermediate3){
    case 0:
    case 1:
        __asm__ volatile(""::"r"(fieldOrIntermediate3));
        temp_v1_2 = Level13_7C2C8Field(owner20, unsigned char *, 0x49);
        if (temp_v1_2 == 1) {
            goto block_28;
        }
        if ((int) temp_v1_2 >= 2) {
            goto block_11;
        }
        if (temp_v1_2 == 0) {
            goto block_14;
        }
        goto block_138;
    block_11:
        if (temp_v1_2 == 2) {
            goto block_34;
        }
        indexPointHeadingOrVector16=(int)&originalFrame.sp60;
        if (temp_v1_2 == 3) {
            goto block_41;
        }
        goto block_138;
    block_14:
        if (Level13_7C2C8Field(privateRecord19, int *, 0) != 0) {
            goto block_18;
        }
        if (Level13_7C2C8Data6C7B4View1 & 4) {
            goto block_21;
        }
        if (!(Level13_7C2C8Field((int)&Level13_7C2C8Data70300View1,unsigned char*,Level13_7C2C8Data6C58CView1) & 4)) {
            goto block_24;
        }
        goto block_21;
    block_18:
        if (Level13_7C2C8Data6C7B4View1 & 8) {
            goto block_21;
        }
        if (Level13_7C2C8Data6C7B4View1 & 4) {
            goto block_24;
        }
        if (Level13_7C2C8Field((int)&Level13_7C2C8Data70300View1,unsigned char*,Level13_7C2C8Data6C58CView1) & 4) {
            goto block_24;
        }
    block_21:
        temp_a0 = (Level13_7C2C8Field(privateRecord19, int *, 8) * 0x58) + Level13_7C2C8Data6C550View1;
        if (Level13_7C2C8Field(temp_a0, unsigned char *, 0x48) & 0x80) {
            goto block_23;
        }
        Level13_7C2C8Call55B18View1(temp_a0);
    block_23:
        Level13_7C2C8Call55B18View1(owner20);
        return;
        block_24:resultOrField2=Level13_7C2C8Field(privateRecord19,int*,0);
        if(!resultOrField2)goto block_26;
        resultOrField2=208;
        Level13_7C2C8Field(owner20,unsigned char*,84)=resultOrField2;
        resultOrField2=48;
        Level13_7C2C8Field(owner20,unsigned char*,85)=resultOrField2;
        goto block_27;
        block_26:resultOrField2=192;
        Level13_7C2C8Field(owner20,unsigned char*,84)=resultOrField2;
        resultOrField2=208;
        Level13_7C2C8Field(owner20,unsigned char*,85)=resultOrField2;
        resultOrField2=64;
        block_27:Level13_7C2C8Field(owner20,unsigned char*,86)=resultOrField2;
        __asm__ volatile(""::"m"(Level13_7C2C8Field(owner20,unsigned char*,86)):"$5");
        argumentOrField5=0x7FFF0000;
        resultOrField2=1;
        __asm__("":"=r"(argumentOrField5):"0"(argumentOrField5),"r"(resultOrField2));
        argumentOrField5|=65535;
        Level13_7C2C8Field(owner20,unsigned char*,87)=0;
        Level13_7C2C8Field(owner20,unsigned char*,73)=resultOrField2;
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,8);
        argumentOrField4=Level13_7C2C8Data6C550View1;
        resultOrField2=fieldOrIntermediate3*11;
        resultOrField2*=8;
        argumentOrField4+=resultOrField2;
        resultOrField2=Level13_7C2C8Field(argumentOrField4,int*,28);
        fieldOrIntermediate3=6;
        Level13_7C2C8Field(argumentOrField4,unsigned char*,72)=fieldOrIntermediate3;
        resultOrField2&=argumentOrField5;
        Level13_7C2C8Field(argumentOrField4,int*,28)=resultOrField2;
        goto block_138;
    block_28:
        argumentOrField4=(int)&originalFrame.sp20;
        Level13_7C2C8Keep(argumentOrField4);
        indexPointHeadingOrVector16 = (int)&Level13_7C2C8Data70328View1 + 0x98;
        Level13_7C2C8Call4F178View1(argumentOrField4,indexPointHeadingOrVector16);
        originalFrame.sp20 *= 0x14;
        originalFrame.sp24 *= 0x14;
        originalFrame.sp28 *= 0x14;
        Level13_7C2C8Call4F110View1(&originalFrame.sp20, 6);
        argumentOrField4=(int)&originalFrame.sp20;
        argumentOrField5=argumentOrField4;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        playerBasePathIndexOrVector17=indexPointHeadingOrVector16-152;
        Level13_7C2C8Call4F194View1(argumentOrField4,argumentOrField5,playerBasePathIndexOrVector17);
        if (Level13_7C2C8Call4F334View1(owner20 + 0xC, &originalFrame.sp20) >= 0x1800) {
            goto block_31;
        }
        argumentOrField7=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField7,short*,0);
        argumentOrField6=Level13_7C2C8Field(argumentOrField7,short*,2);
        resultOrField2=fieldOrIntermediate3+1;
        resultOrField2=argumentOrField6+resultOrField2;
        indexPointHeadingOrVector16=resultOrField2%fieldOrIntermediate3;
        resultOrField2=Level13_7C2C8Field(argumentOrField7,int*,12);
        argumentOrField6*=16;
        argumentOrField6=resultOrField2+argumentOrField6;
        Level13_7C2C8Call4F1C8View1(&originalFrame.sp30,playerBasePathIndexOrVector17,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4E880View1(originalFrame.sp30,originalFrame.sp34,0);
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        __asm__ volatile(""::"r"(fieldOrIntermediate3):"$6");
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,12);
        fieldOrIntermediate3=(int)(short)Level13_7C2C8Field(fieldOrIntermediate3,short*,2);
        argumentOrField6=0;
        fieldOrIntermediate3<<=4;
        fieldOrIntermediate3+=argumentOrField4;
        argumentOrField5=Level13_7C2C8Field(fieldOrIntermediate3,int*,4);
        indexPointHeadingOrVector16*=16;
        indexPointHeadingOrVector16+=argumentOrField4;
        pointCoordinateOrTable8=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,0);
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,0);
        argumentOrField7=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,4);
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(pointCoordinateOrTable8),"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField7));
        indexPointHeadingOrVector16=resultOrField2;
        argumentOrField4=pointCoordinateOrTable8-argumentOrField4;
        argumentOrField5=argumentOrField7-argumentOrField5;
        resultOrField2=Level13_7C2C8Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4F264View1(indexPointHeadingOrVector16,resultOrField2);
        if(resultOrField2 >= 0x40){
            goto block_38;
        }
        argumentOrField5=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField5,short*,0);
        resultOrField2=Level13_7C2C8Field(argumentOrField5,short*,2);
        argumentOrField4=fieldOrIntermediate3-2;
        resultOrField2+=argumentOrField4;
        fieldOrIntermediate3=resultOrField2%fieldOrIntermediate3;
        Level13_7C2C8Keep(fieldOrIntermediate3);
        Level13_7C2C8Field(argumentOrField5,short*,2)=fieldOrIntermediate3;
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        resultOrField2=-1;
        Level13_7C2C8Field(fieldOrIntermediate3,short*,10)=resultOrField2;
        resultOrField2=2;
        goto block_37;
    block_31:
        Level13_7C2C8Call3573CView1(owner20, 8, 0, 1);
        if (Level13_7C2C8Data6C770View1 == 0) {
            goto block_138;
        }
        if (Level13_7C2C8Field(privateRecord19, int *, 0xC) == 0) {
            goto block_49;
        }
        goto block_50;
    block_34:
        indexPointHeadingOrVector16=(int)&originalFrame.sp40;
        Level13_7C2C8Keep(indexPointHeadingOrVector16);
        argumentOrField4=indexPointHeadingOrVector16;
        Level13_7C2C8Keep(argumentOrField4);
        playerBasePathIndexOrVector17 = (int)&Level13_7C2C8Data70328View1 + 0x98;
        Level13_7C2C8Call4F178View1(argumentOrField4,playerBasePathIndexOrVector17);
        originalFrame.sp40 *= 0x14;
        originalFrame.sp44 *= 0x14;
        originalFrame.sp48 *= 0x14;
        Level13_7C2C8Call4F110View1(indexPointHeadingOrVector16,6);
        argumentOrField4=indexPointHeadingOrVector16;
        Level13_7C2C8Keep(argumentOrField4);
        argumentOrField5=indexPointHeadingOrVector16;
        Level13_7C2C8Keep(argumentOrField5);
        playerBasePathIndexOrVector17=playerBasePathIndexOrVector17-152;
        Level13_7C2C8Call4F194View1(argumentOrField4,argumentOrField5,playerBasePathIndexOrVector17);
        if (Level13_7C2C8Call4F334View1(owner20+12,indexPointHeadingOrVector16) >= 0x1800) {
            goto block_31;
        }
        argumentOrField7=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField7,short*,0);
        argumentOrField6=Level13_7C2C8Field(argumentOrField7,short*,2);
        resultOrField2=fieldOrIntermediate3+1;
        resultOrField2=argumentOrField6+resultOrField2;
        indexPointHeadingOrVector16=resultOrField2%fieldOrIntermediate3;
        resultOrField2=Level13_7C2C8Field(argumentOrField7,int*,12);
        argumentOrField6*=16;
        argumentOrField6=resultOrField2+argumentOrField6;
        Level13_7C2C8Call4F1C8View1(&originalFrame.sp50,playerBasePathIndexOrVector17,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4E880View1(originalFrame.sp50,originalFrame.sp54,0);
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        __asm__ volatile(""::"r"(fieldOrIntermediate3):"$6");
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,12);
        fieldOrIntermediate3=(int)(short)Level13_7C2C8Field(fieldOrIntermediate3,short*,2);
        argumentOrField6=0;
        fieldOrIntermediate3<<=4;
        fieldOrIntermediate3+=argumentOrField4;
        argumentOrField5=Level13_7C2C8Field(fieldOrIntermediate3,int*,4);
        indexPointHeadingOrVector16*=16;
        indexPointHeadingOrVector16+=argumentOrField4;
        pointCoordinateOrTable8=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,0);
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,0);
        argumentOrField7=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,4);
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(pointCoordinateOrTable8),"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField7));
        indexPointHeadingOrVector16=resultOrField2;
        argumentOrField4=pointCoordinateOrTable8-argumentOrField4;
        argumentOrField5=argumentOrField7-argumentOrField5;
        resultOrField2=Level13_7C2C8Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4F264View1(indexPointHeadingOrVector16,resultOrField2);
        if(resultOrField2 < 0x31){
            goto block_38;
        }
        argumentOrField5=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField5,short*,0);
        resultOrField2=Level13_7C2C8Field(argumentOrField5,short*,2);
        argumentOrField4=fieldOrIntermediate3+2;
        resultOrField2+=argumentOrField4;
        fieldOrIntermediate3=resultOrField2%fieldOrIntermediate3;
        Level13_7C2C8Keep(fieldOrIntermediate3);
        Level13_7C2C8Field(argumentOrField5,short*,2)=fieldOrIntermediate3;
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        resultOrField2=1;
        Level13_7C2C8Field(fieldOrIntermediate3,short*,10)=resultOrField2;
        __asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2));
        resultOrField2=1;
    block_37:
        Level13_7C2C8Field(owner20,unsigned char*,73)=resultOrField2;
    block_38:
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0x100;
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_40;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = 0;
    block_40:
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 2U;
        Level13_7C2C8Call34F40View1(owner20, 2);
        goto block_138;
    block_41:
        argumentOrField4=indexPointHeadingOrVector16;
        Level13_7C2C8Keep(argumentOrField4);
        playerBasePathIndexOrVector17 = (int)&Level13_7C2C8Data70328View1 + 0x98;
        Level13_7C2C8Call4F178View1(argumentOrField4,playerBasePathIndexOrVector17);
        originalFrame.sp60 *= 0x14;
        originalFrame.sp64 *= 0x14;
        originalFrame.sp68 *= 0x14;
        Level13_7C2C8Call4F110View1(&originalFrame.sp60, 6);
        argumentOrField4=(int)&originalFrame.sp60;
        argumentOrField5=argumentOrField4;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        playerBasePathIndexOrVector17=playerBasePathIndexOrVector17-152;
        Level13_7C2C8Call4F194View1(argumentOrField4,argumentOrField5,playerBasePathIndexOrVector17);
        if (Level13_7C2C8Call4F334View1(owner20 + 0xC, &originalFrame.sp60) >= 0x1800) {
            goto block_46;
        }
        argumentOrField7=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField7,short*,0);
        argumentOrField6=Level13_7C2C8Field(argumentOrField7,short*,2);
        resultOrField2=fieldOrIntermediate3+1;
        resultOrField2=argumentOrField6+resultOrField2;
        indexPointHeadingOrVector16=resultOrField2%fieldOrIntermediate3;
        resultOrField2=Level13_7C2C8Field(argumentOrField7,int*,12);
        argumentOrField6*=16;
        argumentOrField6=resultOrField2+argumentOrField6;
        Level13_7C2C8Call4F1C8View1(&originalFrame.sp70,playerBasePathIndexOrVector17,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4E880View1(originalFrame.sp70,originalFrame.sp74,0);
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        __asm__ volatile(""::"r"(fieldOrIntermediate3):"$6");
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,12);
        fieldOrIntermediate3=(int)(short)Level13_7C2C8Field(fieldOrIntermediate3,short*,2);
        argumentOrField6=0;
        fieldOrIntermediate3<<=4;
        fieldOrIntermediate3+=argumentOrField4;
        argumentOrField5=Level13_7C2C8Field(fieldOrIntermediate3,int*,4);
        indexPointHeadingOrVector16*=16;
        indexPointHeadingOrVector16+=argumentOrField4;
        pointCoordinateOrTable8=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,0);
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,0);
        argumentOrField7=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,4);
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(pointCoordinateOrTable8),"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField7));
        indexPointHeadingOrVector16=resultOrField2;
        argumentOrField4=pointCoordinateOrTable8-argumentOrField4;
        argumentOrField5=argumentOrField7-argumentOrField5;
        resultOrField2=Level13_7C2C8Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4F264View1(indexPointHeadingOrVector16,resultOrField2);
        if(resultOrField2 < 0x31){
            goto block_47;
        }
        Level13_7C2C8Field(Level13_7C2C8Field(privateRecord19, int*, 4), short *, 2) = 0;
        Level13_7C2C8Field(Level13_7C2C8Field(privateRecord19, int*, 4), short *, 0xA) = 1;
        Level13_7C2C8Field(owner20, unsigned char *, 0x49) = 1U;
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0x100;
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_45;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = 0;
    block_45:
        Level13_7C2C8Call34F40View1(owner20, 2);
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 5U;
        goto block_138;
    block_46:
    block_47:
        Level13_7C2C8Call3573CView1(owner20, 8, 0, 1);
        if (Level13_7C2C8Data6C770View1 == 0) {
            goto block_138;
        }
        if (Level13_7C2C8Field(privateRecord19, int *, 0xC) != 0) {
            goto block_50;
        }
    block_49:
        Level13_7C2C8Call34F40View1(owner20, 1);
        Level13_7C2C8Field(privateRecord19, int *, 0xC) = Level13_7C2C8Call3636CView1(1, 2);
        goto block_138;
    block_50:
        Level13_7C2C8Call34F40View1(owner20, 0);
        Level13_7C2C8Field(privateRecord19, int *, 0xC) = (int) (Level13_7C2C8Field(privateRecord19, int *, 0xC) - 1);
        goto block_138;
    case 2:
        temp_v1_14 = Level13_7C2C8Field(owner20, unsigned char *, 0x49);
        if (temp_v1_14 == 1) {
            goto block_54;
        }
        if (temp_v1_14 == 2) {
            goto block_83;
        }
        goto block_138;
    block_54:
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_65;
        }
        resultOrField2=Level13_7C2C8Data6C7C4View1;
        if(resultOrField2)goto block_57;
        fieldOrIntermediate3=(int)0x91A2B3C5;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,16);
        resultOrField2<<=12;
        Level13_7C2C8MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        Level13_7C2C8CaptureHigh(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9+resultOrField2;
        fieldOrIntermediate3>>=11;
        goto block_61;
        block_57:if(resultOrField2!=temp_v1_14)goto block_59;
        fieldOrIntermediate3=(int)0xC22E0000;
        Level13_7C2C8Keep(fieldOrIntermediate3);
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,16);
        fieldOrIntermediate3|=17671;
        goto block_60;
        block_59:fieldOrIntermediate3=(int)0x91A20000;
        Level13_7C2C8Keep(fieldOrIntermediate3);
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,16);
        fieldOrIntermediate3|=46021;
        block_60:resultOrField2<<=12;
        Level13_7C2C8MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        Level13_7C2C8CaptureHigh(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9+resultOrField2;
        fieldOrIntermediate3>>=12;
        block_61:resultOrField2>>=31;
        indexPointHeadingOrVector16=fieldOrIntermediate3-resultOrField2;
        resultOrField2=4096;
        boundedHelperArgumentOrVector18=resultOrField2-indexPointHeadingOrVector16;
        resultOrField2=Level13_7C2C8Call4F334View1(owner20+12,(int)&Level13_7C2C8Data70328View1);
        fieldOrIntermediate3=Level13_7C2C8Field((int)&Level13_7C2C8Data70328View1,int*,180);
        boundedHelperArgumentOrVector18-=resultOrField2;
        fieldOrIntermediate3=boundedHelperArgumentOrVector18+fieldOrIntermediate3;
        boundedHelperArgumentOrVector18=fieldOrIntermediate3>>5;
        resultOrField2=boundedHelperArgumentOrVector18<400;
        if(!resultOrField2)goto block_63;
        boundedHelperArgumentOrVector18=400;
        Level13_7C2C8Keep(boundedHelperArgumentOrVector18);
        block_63:resultOrField2=boundedHelperArgumentOrVector18<551;
        if(resultOrField2)goto block_66;
        boundedHelperArgumentOrVector18=550;
        goto block_66;
        block_65:fieldOrIntermediate3=0x1B4E81B5;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,16);
        Level13_7C2C8MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        resultOrField2>>=31;
        Level13_7C2C8CaptureHigh(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9>>5;
        boundedHelperArgumentOrVector18=fieldOrIntermediate3-resultOrField2;
        resultOrField2=248;
        boundedHelperArgumentOrVector18=resultOrField2-boundedHelperArgumentOrVector18;
    block_66:
        temp_v0_2 = Level13_7C2C8Field(privateRecord19, int *, 0x10) + Level13_7C2C8Data6C648View1;
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = temp_v0_2;
        if (temp_v0_2 < 0x1C21) {
            goto block_68;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = 0x1C20;
    block_68:
        argumentOrField4=(int)&originalFrame.sp70;
        Level13_7C2C8Keep(argumentOrField4);
        playerBasePathIndexOrVector17 = (int)&Level13_7C2C8Data70328View1 + 0x98;
        Level13_7C2C8Call4F178View1(argumentOrField4,playerBasePathIndexOrVector17);
        originalFrame.sp70 *= 0x14;
        originalFrame.sp74 *= 0x14;
        originalFrame.sp78 *= 0x14;
        Level13_7C2C8Call4F110View1(&originalFrame.sp70, 6);
        Level13_7C2C8Call4F194View1(&originalFrame.sp70, &originalFrame.sp70, playerBasePathIndexOrVector17 - 0x98);
        indexPointHeadingOrVector16 = Level13_7C2C8Call4F334View1(owner20 + 0xC, &originalFrame.sp70);
        if (Level13_7C2C8Field(privateRecord19, int *, 0) != 0) {
            goto block_71;
        }
        temp_v0_3 = Level13_7C2C8Field(privateRecord19, int *, 0x18) + 8;
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = temp_v0_3;
        if (temp_v0_3 < 0x101) {
            goto block_72;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0x100;
    block_71:
    block_72:
        temp_v0_4=Level13_7C2C8Call35A80View1(owner20,Level13_7C2C8Field(privateRecord19,int*,4),512,boundedHelperArgumentOrVector18,0,(fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,24),fieldOrIntermediate3>>4),24,5);
        fieldOrIntermediate3=temp_v0_4;
        resultOrField2=fieldOrIntermediate3&4;
        if(resultOrField2)goto block_77;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,0);
        if(!resultOrField2)goto block_75;
        resultOrField2=80;
        Level13_7C2C8Field(privateRecord19,int*,24)=resultOrField2;
        goto block_76;
        block_75:__asm__ volatile("":::"$2");
        Level13_7C2C8Field(privateRecord19,int*,24)=0;
    block_76:
        block_77:resultOrField2=fieldOrIntermediate3&1;
        if(!resultOrField2)goto block_79;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,4);
        resultOrField2=Level13_7C2C8Field(resultOrField2,short*,2);
        if(!resultOrField2)goto block_130;
        block_79:resultOrField2=indexPointHeadingOrVector16<10241;
        Level13_7C2C8Keep(resultOrField2);
        if(resultOrField2)goto block_81;
        if (Level13_7C2C8Call4F334View1(owner20 + 0xC, (int)&Level13_7C2C8Data70328View1) >= 0x2801) {
            goto block_107;
        }
    block_81:
        argumentOrField7=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField7,short*,0);
        argumentOrField6=Level13_7C2C8Field(argumentOrField7,short*,2);
        resultOrField2=fieldOrIntermediate3+1;
        resultOrField2=argumentOrField6+resultOrField2;
        indexPointHeadingOrVector16=resultOrField2%fieldOrIntermediate3;
        resultOrField2=Level13_7C2C8Field(argumentOrField7,int*,12);
        argumentOrField6*=16;
        argumentOrField6=resultOrField2+argumentOrField6;
        Level13_7C2C8Call4F1C8View1(&originalFrame.sp50,(int)&Level13_7C2C8Data70328View1,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4E880View1(originalFrame.sp50,originalFrame.sp54,0);
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        __asm__ volatile(""::"r"(fieldOrIntermediate3):"$6");
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,12);
        fieldOrIntermediate3=(int)(short)Level13_7C2C8Field(fieldOrIntermediate3,short*,2);
        argumentOrField6=0;
        fieldOrIntermediate3<<=4;
        fieldOrIntermediate3+=argumentOrField4;
        argumentOrField5=Level13_7C2C8Field(fieldOrIntermediate3,int*,4);
        indexPointHeadingOrVector16*=16;
        indexPointHeadingOrVector16+=argumentOrField4;
        pointCoordinateOrTable8=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,0);
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,0);
        argumentOrField7=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,4);
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(pointCoordinateOrTable8),"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField7));
        indexPointHeadingOrVector16=resultOrField2;
        argumentOrField4=pointCoordinateOrTable8-argumentOrField4;
        argumentOrField5=argumentOrField7-argumentOrField5;
        resultOrField2=Level13_7C2C8Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4F264View1(indexPointHeadingOrVector16,resultOrField2);
        if(resultOrField2 >= 0x40){
            goto block_138;
        }
        argumentOrField5=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField5,short*,0);
        resultOrField2=Level13_7C2C8Field(argumentOrField5,short*,2);
        argumentOrField4=fieldOrIntermediate3-2;
        resultOrField2+=argumentOrField4;
        fieldOrIntermediate3=resultOrField2%fieldOrIntermediate3;
        Level13_7C2C8Keep(fieldOrIntermediate3);
        Level13_7C2C8Field(argumentOrField5,short*,2)=fieldOrIntermediate3;
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        resultOrField2=-1;
        Level13_7C2C8Field(fieldOrIntermediate3,short*,10)=resultOrField2;
        Level13_7C2C8Field(owner20, unsigned char *, 0x49) = 2U;
        goto block_138;
    block_83:
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_88;
        }
        fieldOrIntermediate3=(int)0x91A2B3C5;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,16);
        resultOrField2<<=12;
        Level13_7C2C8MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        argumentOrField4=owner20+12;
        argumentOrField5=(int)&Level13_7C2C8Data70328View1;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        Level13_7C2C8CaptureHigh(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9+resultOrField2;
        fieldOrIntermediate3>>=12;
        resultOrField2>>=31;
        indexPointHeadingOrVector16=fieldOrIntermediate3-resultOrField2;
        resultOrField2=4096;
        boundedHelperArgumentOrVector18=resultOrField2-indexPointHeadingOrVector16;
        resultOrField2=Level13_7C2C8Call4F334View1(argumentOrField4,argumentOrField5);
        fieldOrIntermediate3=Level13_7C2C8Field((int)&Level13_7C2C8Data70328View1,int*,180);
        boundedHelperArgumentOrVector18-=resultOrField2;
        fieldOrIntermediate3=boundedHelperArgumentOrVector18+fieldOrIntermediate3;
        boundedHelperArgumentOrVector18=fieldOrIntermediate3>>5;
        resultOrField2=boundedHelperArgumentOrVector18<400;
        if(!resultOrField2)goto block_86;
        boundedHelperArgumentOrVector18=400;
        Level13_7C2C8Keep(boundedHelperArgumentOrVector18);
        block_86:resultOrField2=boundedHelperArgumentOrVector18<551;
        if(resultOrField2)goto block_89;
        boundedHelperArgumentOrVector18=550;
        goto block_89;
        block_88:fieldOrIntermediate3=0x1B4E81B5;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,16);
        Level13_7C2C8MultiplyComplete(resultOrField2,fieldOrIntermediate3);
        resultOrField2>>=31;
        Level13_7C2C8CaptureHigh(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9>>5;
        boundedHelperArgumentOrVector18=fieldOrIntermediate3-resultOrField2;
        resultOrField2=248;
        boundedHelperArgumentOrVector18=resultOrField2-boundedHelperArgumentOrVector18;
    block_89:
        temp_v0_5 = Level13_7C2C8Field(privateRecord19, int *, 0x10) + Level13_7C2C8Data6C648View1;
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = temp_v0_5;
        if (temp_v0_5 < 0x1C21) {
            goto block_91;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = 0x1C20;
    block_91:
        argumentOrField4=(int)&originalFrame.sp50;
        Level13_7C2C8Keep(argumentOrField4);
        playerBasePathIndexOrVector17 = (int)&Level13_7C2C8Data70328View1 + 0x98;
        Level13_7C2C8Call4F178View1(argumentOrField4,playerBasePathIndexOrVector17);
        originalFrame.sp50 *= 0x14;
        originalFrame.sp54 *= 0x14;
        originalFrame.sp58 *= 0x14;
        Level13_7C2C8Call4F110View1(&originalFrame.sp50, 6);
        Level13_7C2C8Call4F194View1(&originalFrame.sp50, &originalFrame.sp50, playerBasePathIndexOrVector17 - 0x98);
        indexPointHeadingOrVector16 = Level13_7C2C8Call4F334View1(owner20 + 0xC, &originalFrame.sp50);
        if (Level13_7C2C8Field(privateRecord19, int *, 0) != 0) {
            goto block_94;
        }
        temp_v0_6 = Level13_7C2C8Field(privateRecord19, int *, 0x18) + 8;
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = temp_v0_6;
        if (temp_v0_6 < 0x101) {
            goto block_94;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0x100;
    block_94:
        playerBasePathIndexOrVector17 = Level13_7C2C8Field(Level13_7C2C8Field(privateRecord19, int*, 4), short *, 2);
        temp_v0_7 = Level13_7C2C8Call35A80View1(owner20, Level13_7C2C8Field(privateRecord19, int*, 4), 0x200, boundedHelperArgumentOrVector18, 0, (int) Level13_7C2C8Field(privateRecord19, int *, 0x18) >> 4, 0x18, 5);
        fieldOrIntermediate3=temp_v0_7;
        resultOrField2=fieldOrIntermediate3&4;
        if(resultOrField2)goto block_99;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,0);
        if(!resultOrField2)goto block_97;
        resultOrField2=80;
        Level13_7C2C8Field(privateRecord19,int*,24)=resultOrField2;
        goto block_98;
        block_97:__asm__ volatile("":::"$2");
        Level13_7C2C8Field(privateRecord19,int*,24)=0;
    block_98:
        block_99:resultOrField2=fieldOrIntermediate3&1;
        if(!resultOrField2)goto block_104;
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        pointCoordinateOrTable8=Level13_7C2C8Field(fieldOrIntermediate3,int*,12);
        resultOrField2=playerBasePathIndexOrVector17*16;
        resultOrField2+=pointCoordinateOrTable8;
        resultOrField2=Level13_7C2C8Field(resultOrField2,int*,12);
        if(!resultOrField2)goto block_105;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,0);
        boundedHelperArgumentOrVector18=248;
        if(resultOrField2)boundedHelperArgumentOrVector18=512;
        argumentOrField4=owner20+12;
        argumentOrField6=boundedHelperArgumentOrVector18;
        argumentOrField5=Level13_7C2C8Field(fieldOrIntermediate3,short*,0);
        argumentOrField7=-8;
        argumentOrField5*=16;
        argumentOrField5-=16;
        resultOrField2=Level13_7C2C8Call365E4View1(argumentOrField4,pointCoordinateOrTable8+argumentOrField5,argumentOrField6,argumentOrField7,0);
        Level13_7C2C8Field(privateRecord19,int*,20)=resultOrField2;
        goto block_131;
    block_104:
        block_105:resultOrField2=indexPointHeadingOrVector16<10241;
        Level13_7C2C8Keep(resultOrField2);
        if(resultOrField2)goto block_108;
        if(Level13_7C2C8Call4F334View1(owner20+12,(int)&Level13_7C2C8Data70328View1)<10241)goto block_108;
    block_107:
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 0U;
        Level13_7C2C8Call34F40View1(owner20, 0);
        goto block_138;
    block_108:
        argumentOrField7=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField7,short*,0);
        argumentOrField6=Level13_7C2C8Field(argumentOrField7,short*,2);
        resultOrField2=fieldOrIntermediate3+1;
        resultOrField2=argumentOrField6+resultOrField2;
        indexPointHeadingOrVector16=resultOrField2%fieldOrIntermediate3;
        resultOrField2=Level13_7C2C8Field(argumentOrField7,int*,12);
        argumentOrField6*=16;
        argumentOrField6=resultOrField2+argumentOrField6;
        Level13_7C2C8Call4F1C8View1(&originalFrame.sp30,(int)&Level13_7C2C8Data70328View1,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4E880View1(originalFrame.sp30,originalFrame.sp34,0);
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        __asm__ volatile(""::"r"(fieldOrIntermediate3):"$6");
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,12);
        fieldOrIntermediate3=(int)(short)Level13_7C2C8Field(fieldOrIntermediate3,short*,2);
        argumentOrField6=0;
        fieldOrIntermediate3<<=4;
        fieldOrIntermediate3+=argumentOrField4;
        argumentOrField5=Level13_7C2C8Field(fieldOrIntermediate3,int*,4);
        indexPointHeadingOrVector16*=16;
        indexPointHeadingOrVector16+=argumentOrField4;
        pointCoordinateOrTable8=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,0);
        argumentOrField4=Level13_7C2C8Field(fieldOrIntermediate3,int*,0);
        argumentOrField7=Level13_7C2C8Field(indexPointHeadingOrVector16,int*,4);
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(pointCoordinateOrTable8),"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField7));
        indexPointHeadingOrVector16=resultOrField2;
        argumentOrField4=pointCoordinateOrTable8-argumentOrField4;
        argumentOrField5=argumentOrField7-argumentOrField5;
        resultOrField2=Level13_7C2C8Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        resultOrField2=Level13_7C2C8Call4F264View1(indexPointHeadingOrVector16,resultOrField2);
        if(resultOrField2 < 0x31){
            goto block_138;
        }
        argumentOrField5=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField5,short*,0);
        resultOrField2=Level13_7C2C8Field(argumentOrField5,short*,2);
        argumentOrField4=fieldOrIntermediate3+2;
        resultOrField2+=argumentOrField4;
        fieldOrIntermediate3=resultOrField2%fieldOrIntermediate3;
        Level13_7C2C8Keep(fieldOrIntermediate3);
        Level13_7C2C8Field(argumentOrField5,short*,2)=fieldOrIntermediate3;
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,4);
        resultOrField2=1;
        Level13_7C2C8Field(fieldOrIntermediate3,short*,10)=resultOrField2;
        Level13_7C2C8Field(owner20, unsigned char *, 0x49) = 1U;
        goto block_138;
    case 4:
        var_a3 = 0xF8;
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_112;
        }
        var_a3 = 0x200;
    block_112:
        temp_v0_8 = Level13_7C2C8Field(privateRecord19, int *, 0x10) + Level13_7C2C8Data6C648View1;
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = temp_v0_8;
        if (temp_v0_8 < 0x1C21) {
            goto block_114;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x10) = 0x1C20;
    block_114:
        if (Level13_7C2C8Field(privateRecord19, int *, 0) != 0) {
            goto block_117;
        }
        temp_v0_9 = Level13_7C2C8Field(privateRecord19, int *, 0x18) + 8;
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = temp_v0_9;
        if (temp_v0_9 < 0x101) {
            goto block_117;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0x100;
    block_117:
        if (Level13_7C2C8Call35A80View1(owner20, Level13_7C2C8Field(privateRecord19, int*, 4), 0x200, var_a3, 0, (int) Level13_7C2C8Field(privateRecord19, int *, 0x18) >> 4, 0x18, 0) & 4) {
            goto block_121;
        }
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_120;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0x50;
        goto block_121;
    block_120:
        Level13_7C2C8Field(privateRecord19, int *, 0x18) = 0;
    block_121:
        temp_v0_10 = Level13_7C2C8Field(privateRecord19, int *, 0x14) - 8;
        Level13_7C2C8Field(privateRecord19, int *, 0x14) = temp_v0_10;
        if (temp_v0_10 >= -0xF0) {
            goto block_123;
        }
        Level13_7C2C8Field(privateRecord19, int *, 0x14) = -0xF0;
    block_123:
        Level13_7C2C8Field(owner20, int *, 0x14) = (int) (Level13_7C2C8Field(owner20, int *, 0x14) + Level13_7C2C8Field(privateRecord19, int *, 0x14));
        Level13_7C2C8Call4F178View1(&originalFrame.sp30, owner20 + 0xC);
        originalFrame.sp38 += 0x200;
        temp_v0_11 = Level13_7C2C8Call1A358View1(&originalFrame.sp30, 0x200);
        originalFrame.sp38 = temp_v0_11;
        if (temp_v0_11 == 0) {
            goto block_138;
        }
        temp_v1_24 = Level13_7C2C8Field(owner20, unsigned char *, 0x49);
        Level13_7C2C8Field(owner20, int *, 0x14) = temp_v0_11;
        if (temp_v1_24 == 1) {
            goto block_127;
        }
        if (temp_v1_24 == 2) {
            goto block_128;
        }
        goto block_138;
    block_127:
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 2U;
        goto block_138;
    block_128:
        Level13_7C2C8Field(owner20, unsigned char *, 0x49) = 3U;
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 0U;
        Level13_7C2C8Call34F40View1(owner20, 0);
        goto block_138;
    case 5:
        temp_v1_25 = Level13_7C2C8Field(privateRecord19, int*, 4);
        temp_v0_12 = (Level13_7C2C8Field(temp_v1_25, short *, 2) * 0x10) + Level13_7C2C8Field(temp_v1_25, int*, 0xC);
        if (Level13_7C2C8Call3585CView1(owner20, Level13_7C2C8Call4E880View1(Level13_7C2C8Field(temp_v0_12, int *, 0) - Level13_7C2C8Field(owner20, int *, 0xC), Level13_7C2C8Field(temp_v0_12, int *, 4) - Level13_7C2C8Field(owner20, int *, 0x10), 0), 0x10, 0x10, 1, 0) == 0) {
            goto block_138;
        }
    block_130:
        Level13_7C2C8Field(privateRecord19, int *, 0x14) = 0x40;
    block_131:
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 4U;
        goto block_138;
    case 3:
        Level13_7C2C8Field((int)&Level13_7C2C8Data70328View1, int *, 0x20C) = 0x10000002;
        if (Level13_7C2C8Call35194View1(owner20, privateRecord19 + 0x1C) != 0x100) {
            goto block_138;
        }
        Level13_7C2C8Call4F178View1(&originalFrame.sp80, Level13_7C2C8Field(Level13_7C2C8Field(privateRecord19, int*, 4), int*, 0xC) + 0x30);
        originalFrame.sp88 += Level13_7C2C8Field((int)&Level13_7C2C8Data70328View1, int *, 0x44);
        temp_v0_13 = Level13_7C2C8Field(Level13_7C2C8Field(privateRecord19, int*, 4), int*, 0xC);
        temp_a3_11 = Level13_7C2C8Field(temp_v0_13, int *, 0x40);
        Level13_7C2C8Call13D44View1(&originalFrame.sp80, Level13_7C2C8Call4E880View1(temp_a3_11 - Level13_7C2C8Field(temp_v0_13, int *, 0x30), Level13_7C2C8Field(temp_v0_13, int *, 0x44) - Level13_7C2C8Field(temp_v0_13, int *, 0x34), 0), 0, 0);
        if (Level13_7C2C8Field((int)&Level13_7C2C8Data70328View1, int *, 0x280) >= 0) {
            goto block_135;
        }
        Level13_7C2C8Field((int)&Level13_7C2C8Data70328View1, int *, 0x280) = 0;
    block_135:
        Level13_7C2C8Call55D24View1(owner20, 4);
        Level13_7C2C8Call3BA00View1(owner20);
        Level13_7C2C8Call369B8View1(owner20, 0x20);
        Level13_7C2C8Field(owner20, signed char *, 0x41) = 0;
        Level13_7C2C8Field(owner20, signed char *, 0x4C) = 0;
        Level13_7C2C8Field(owner20, signed char *, 0x4D) = 0;
        Level13_7C2C8Field(owner20, unsigned char *, 0x48) = 6U;
        goto block_138;
    case 6:
        resultOrField2=Level13_7C2C8Data6E048View1;
        resultOrField2&=1;
        __asm__ volatile(""::"r"(resultOrField2):"$17");
        playerBasePathIndexOrVector17=(int)&originalFrame.sp90;
        if (!resultOrField2) {
            goto block_138;
        }
        Level13_7C2C8Keep(playerBasePathIndexOrVector17);
        argumentOrField4=playerBasePathIndexOrVector17;
        resultOrField2=Level13_7C2C8Field(privateRecord19,int*,4);
        fieldOrIntermediate3=Level13_7C2C8Field(privateRecord19,int*,8);
        indexPointHeadingOrVector16=Level13_7C2C8Data6C550View1;
        argumentOrField5=Level13_7C2C8Field(resultOrField2,int*,12);
        resultOrField2=fieldOrIntermediate3*11;
        resultOrField2*=8;
        indexPointHeadingOrVector16+=resultOrField2;
        Level13_7C2C8Call4F178View1(argumentOrField4,argumentOrField5+64);
        Level13_7C2C8Call4F178View1(indexPointHeadingOrVector16+12,playerBasePathIndexOrVector17);
        Level13_7C2C8Call37014View1(indexPointHeadingOrVector16);
        Level13_7C2C8Field(indexPointHeadingOrVector16, unsigned char *, 0x52) = 254;
        Level13_7C2C8Call55D24View1(indexPointHeadingOrVector16, 2);
        Level13_7C2C8Field(indexPointHeadingOrVector16, signed char *, 0x48) = 1;
        temp_v0_14 = Level13_7C2C8Field(Level13_7C2C8Field(privateRecord19, int*, 4), int*, 0xC);
        temp_a3_12 = Level13_7C2C8Field(temp_v0_14, int *, 0x30);
        Level13_7C2C8Field(indexPointHeadingOrVector16, signed char *, 0x46) = Level13_7C2C8Call4E880View1(temp_a3_12 - Level13_7C2C8Field(temp_v0_14, int *, 0x40), Level13_7C2C8Field(temp_v0_14, int *, 0x34) - Level13_7C2C8Field(temp_v0_14, int *, 0x44), 0);
        Level13_7C2C8Call55B18View1(owner20);
        return;
    block_138:
        if (Level13_7C2C8Field(owner20, unsigned char *, 0x48) == 6) {
            goto block_140;
        }
        Level13_7C2C8Call55D24View1(owner20, 4);
        Level13_7C2C8Call55F14View1(owner20, 0, Level13_7C2C8Data6C550View1 + (Level13_7C2C8Field(privateRecord19, int *, 8) * 0x58) + 0xC);
        temp_v0_15 = (Level13_7C2C8Field(privateRecord19, int *, 8) * 0x58) + Level13_7C2C8Data6C550View1;
        Level13_7C2C8Field(temp_v0_15, int *, 0x14) = (int) (Level13_7C2C8Field(temp_v0_15, int *, 0x14) - 0x80);
        Level13_7C2C8Field(((Level13_7C2C8Field(privateRecord19, int *, 8) * 0x58) + Level13_7C2C8Data6C550View1), unsigned char *, 0x52) = 254;
        Level13_7C2C8Field(((Level13_7C2C8Field(privateRecord19, int *, 8) * 0x58) + Level13_7C2C8Data6C550View1), unsigned char *, 0x46) = (unsigned char) Level13_7C2C8Field(owner20, unsigned char *, 0x46);
    block_140:
        if (Level13_7C2C8Field(privateRecord19, int *, 0) == 0) {
            goto block_145;
        }
        temp_v1_26 = Level13_7C2C8Field(owner20, unsigned char *, 0x48);
        if (temp_v1_26 == 2) {
            goto block_143;
        }
        if (temp_v1_26 != 4) {
            goto block_145;
        }
        block_143:playerBasePathIndexOrVector17=0;
        boundedHelperArgumentOrVector18=(int)&originalFrame.sp80;
        Level13_7C2C8Keep(boundedHelperArgumentOrVector18);
        loop_144:resultOrField2=Level13_7C2C8Call3636CView1(120,300);
        argumentOrField4=boundedHelperArgumentOrVector18;
        argumentOrField5=owner20+12;
        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5));
        indexPointHeadingOrVector16=resultOrField2;
        Level13_7C2C8Call4F178View1(argumentOrField4,argumentOrField5);
        originalFrame.sp88=Level13_7C2C8Field(owner20,int*,20);
        resultOrField2=Level13_7C2C8Call363DCView1(0,20);
        argumentOrField5=Level13_7C2C8Field(owner20,unsigned char*,70);
        argumentOrField4=(int)&Level13_7C2C8Data65920View1;
        argumentOrField5+=128;
        argumentOrField5+=resultOrField2;
        argumentOrField5&=255;
        argumentOrField5*=2;
        argumentOrField4=argumentOrField5+argumentOrField4;
        resultOrField2=Level13_7C2C8Field(argumentOrField4,short*,0);
        Level13_7C2C8MultiplyComplete(resultOrField2,indexPointHeadingOrVector16);
        resultOrField2=originalFrame.sp80;
        Level13_7C2C8CaptureLow(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9>>12;
        resultOrField2+=fieldOrIntermediate3;
        originalFrame.sp80=resultOrField2;
        resultOrField2=(int)&Level13_7C2C8Data658A0View1;
        argumentOrField5+=resultOrField2;
        resultOrField2=Level13_7C2C8Field(argumentOrField5,short*,0);
        Level13_7C2C8MultiplyComplete(resultOrField2,indexPointHeadingOrVector16);
        playerBasePathIndexOrVector17++;
        resultOrField2=originalFrame.sp84;
        Level13_7C2C8CaptureLow(capturedHalf9);
        fieldOrIntermediate3=capturedHalf9>>12;
        resultOrField2+=fieldOrIntermediate3;
        originalFrame.sp84=resultOrField2;
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField4,short*,0);
        argumentOrField4=7;
        resultOrField2=fieldOrIntermediate3*5;
        resultOrField2>>=10;
        originalFrame.spA0=resultOrField2;
        fieldOrIntermediate3=Level13_7C2C8Field(argumentOrField5,short*,0);
        argumentOrField5=12;
        originalFrame.spA8=0;
        resultOrField2=fieldOrIntermediate3*5;
        resultOrField2>>=10;
        originalFrame.spA4=resultOrField2;
        originalFrame.spA8=Level13_7C2C8Call3636CView1(argumentOrField4,argumentOrField5);
        Level13_7C2C8Keep(boundedHelperArgumentOrVector18);
        Level13_7C2C8DataSpawnParticleView1(1,0,boundedHelperArgumentOrVector18,&originalFrame.spA0);
        if (playerBasePathIndexOrVector17 < 2) {
            goto loop_144;
        }
    block_145:
        return;
        default:goto block_138;
    }
}
#undef Level13_7C2C8Field


/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Two originals each contain 418 instructions, without owned rodata.
 * The second copy has its own byte-flag address; preserve that relocation.
 * Preserve original byte/halfword/word widths, selector order and rereads.
 * Signed division follows a wrapping 32-bit shift by four; vectors and
 * caller cadence have unresolved semantic units. Empty compiler constraints
 * emit no opcodes and preserve original helper argument producers.
 * Acceptance requires all linked original words and every retail hash.
 */
#define P7D820Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int P7D820func_800135A4() __asm__("func_800135A4");
int P7D820func_8001A358() __asm__("func_8001A358");
int P7D820func_80034F40() __asm__("func_80034F40");
int P7D820func_8003585C() __asm__("func_8003585C");
int P7D820func_800359A4() __asm__("func_800359A4");
int P7D820func_80035DDC() __asm__("func_80035DDC");
int P7D820func_80037BBC() __asm__("func_80037BBC");
int P7D820func_8003B74C() __asm__("func_8003B74C");
int P7D820func_8003B7B4() __asm__("func_8003B7B4");
int P7D820func_8004F194() __asm__("func_8004F194");
int P7D820func_8004F984() __asm__("func_8004F984");
int P7D820func_800512E4() __asm__("func_800512E4");
int P7D820func_80055D24() __asm__("func_80055D24");
int P7D820func_8005629C() __asm__("func_8005629C");
extern unsigned char P7D820D_800652B0[] __asm__("D_800652B0");
extern unsigned char P7D820D_800652B4[] __asm__("D_800652B4");
extern unsigned char P7D820D_800652B6[] __asm__("D_800652B6");
extern unsigned char P7D820D_800658A0[] __asm__("D_800658A0");
extern unsigned char P7D820D_80065920[] __asm__("D_80065920");
extern unsigned char P7D820D_80068CAC[] __asm__("D_80068CAC");
extern unsigned char P7D820D_80068F7C[] __asm__("D_80068F7C");
extern unsigned char P7D820D_80068F90[] __asm__("D_80068F90");
extern unsigned char P7D820D_80068FA4[] __asm__("D_80068FA4");
extern int P7D820D_8006C3F4 __asm__("D_8006C3F4");
extern int P7D820D_8006C4F8 __asm__("D_8006C4F8");
extern int P7D820D_8006C598 __asm__("D_8006C598");
extern int P7D820D_8006C640 __asm__("D_8006C640");
extern int P7D820D_8006C658 __asm__("D_8006C658");
extern int P7D820D_8006C6D0 __asm__("D_8006C6D0");
extern int P7D820D_8006C6E0 __asm__("D_8006C6E0");
extern int P7D820D_8006C768 __asm__("D_8006C768");
extern unsigned char P7D820D_8006C7F8[] __asm__("D_8006C7F8");
extern unsigned char P7D820D_8006D088[] __asm__("D_8006D088");
extern int P7D820D_8006E044 __asm__("D_8006E044");
extern int P7D820D_8006E048 __asm__("D_8006E048");
extern int P7D820D_8006E078 __asm__("D_8006E078");
extern int P7D820D_8006E08C __asm__("D_8006E08C");
extern signed char P7D820D_8006E13F __asm__("D_8006E13F");
extern int P7D820D_8006E344 __asm__("D_8006E344");
extern int P7D820D_8006E53C __asm__("D_8006E53C");
extern unsigned char P7D820D_80070328[] __asm__("D_80070328");
extern signed char P7D820D_80071576 __asm__("D_80071576");
extern unsigned char P7D820D_800719A8[] __asm__("D_800719A8");
extern int P7D820D_800719BC __asm__("D_800719BC");
extern int P7D820D_800719C0 __asm__("D_800719C0");
extern int P7D820D_800719C4 __asm__("D_800719C4");
extern short P7D820D_800719D4 __asm__("D_800719D4");
extern unsigned char P7D820D_800719F0[] __asm__("D_800719F0");
extern int (*P7D820SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7D820unk_ovlheader_80074318)() __asm__("unk_ovlheader_80074318");
extern int (*P7D820unk_ovlheader_80074320)() __asm__("unk_ovlheader_80074320");
void func_level_13_8007D820(void *owner) {
    register unsigned char *sourceArg5 __asm__("5");
    register void *copyDestination4 __asm__("4");
    register int tableWord3 __asm__("3");
    int headerBaseWord;
    int requestedSelector;
    int headerArg5;
    register int workWord2 __asm__("2");
    register int workWord3 __asm__("3");
    int selector48;
    void *selectorAddress1;
    void *selectorAddress99;
    void *state;
    register void *positionArg4 __asm__("4");
    int scaledHeaderWord;
    void *stateArg4;

    P7D820Field(owner, unsigned char *, 0x4A) = 0xFF;
    state = P7D820Field(owner, void **, 0);
    if ((P7D820D_8006C640 > 0) && (P7D820Field(state, int *, 0x60) == 0)) {
        headerBaseWord = P7D820D_8006C3F4 + P7D820Field(&P7D820D_800652B0, int *, 0x10);
        P7D820func_8004F984(headerBaseWord, headerBaseWord + P7D820Field(&P7D820D_800652B4, unsigned short *, 0x10), P7D820Field(&P7D820D_800652B6, unsigned short *, 0x10));
        P7D820Field(state, int *, 0x60) = 1;
    }
    selector48 = P7D820Field(owner, unsigned char *, 0x48);
    if (selector48 == 3) goto selector3;
    if (selector48 < 4) {
        if (selector48 == 0) goto selector0;
        if (selector48 == 1) goto selector1;
        goto finishPositionArgument;
    }
    if (selector48 == 10) goto selector10;
    if (selector48 == 99) goto selector99;
    goto finishPositionArgument;
selector0:
    if (((P7D820D_8006C658 != 0) || (P7D820D_8006E344 == 0xD)) && (P7D820Field(owner, unsigned char *, 0x49) == 0)) {
        if (P7D820D_8006C4F8 != 1) {
            P7D820Field(owner, unsigned char *, 0x48) = 3U;
            goto notifySelector;
        }
        tableWord3 = ((short *)P7D820D_80065920)[P7D820Field(owner, unsigned char *, 0x46)];
        positionArg4 = &P7D820D_800719BC;
        *(int *)positionArg4 = (tableWord3 * 13) >> 5;
        sourceArg5 = positionArg4;
        tableWord3 = ((short *)P7D820D_800658A0)[P7D820Field(owner, unsigned char *, 0x46)];
        P7D820D_800719C4 = 0;
        P7D820D_800719C0 = (tableWord3 * 13) >> 5;
        P7D820func_8004F194(positionArg4, sourceArg5, owner + 0xC);
        P7D820D_8006C6E0 = ((P7D820Field(owner, unsigned char *, 0x46) + 0x80) * 0x10) & 0xFFF;
        P7D820Field(owner, unsigned char *, 0x49) = 1U;
        goto initializeState0;
    }
initializeState0:
    P7D820Field(owner, short *, 0x38) = 0;
    P7D820Field(state, signed char *, 5) = 1;
    positionArg4 = owner + 0xC;
    if (P7D820D_8006C598 == 0) {
        if (P7D820func_80037BBC(owner, 0) != 0) {
            P7D820func_800512E4(owner, 0, 0xA);
            P7D820Field(owner, unsigned char *, 0x48) = 0xAU;
        }
        goto finishPosition;
    }
    goto finishPositionArgument;
selector10:
    if (P7D820D_8006E344 == 1) goto finishPositionArgument;
    P7D820Field(&P7D820D_80070328, int *, 0x20C) = 0x10000002;
    P7D820D_80071576 = 1;
    P7D820Field(state, int *, 0x24) = 0x3C;
    P7D820Field(owner, unsigned char *, 0x48) = 1U;
    P7D820func_80034F40(owner, 1);
    positionArg4 = owner + 0xC;

    goto finishPositionArgument;
selector1:
    P7D820D_800719D4 = 1;
    P7D820Field(&P7D820D_80070328, int *, 0x20C) = 0x10000002;
    if (P7D820func_8003585C(owner, P7D820Field(state, int *, 0x48) + 0x80, 8, 0x10, (int) selector48, 0) != 0) {
        P7D820func_80035DDC(owner, 0x80, 0, 0, 0);
    }
    positionArg4 = owner + 0xC;
    if (P7D820func_800359A4(state + 0x24, 4) == 2) {
        selectorAddress1 = owner + 0x48;
        P7D820Field(owner, unsigned char *, 0x48) = 3U;
        P7D820func_8003B7B4(selectorAddress1, 1, &P7D820D_8006D088);
        P7D820func_8003B7B4(selectorAddress1, 1, &P7D820D_8006C7F8);
        P7D820func_8003B74C(&P7D820D_8006D088);
        P7D820Field(owner, unsigned char *, 0x48) = 1U;
        goto finishPosition;
    }
    goto finishPositionArgument;
selector3:
    P7D820unk_ovlheader_80074318(owner, 0x64);
    P7D820D_8006C6D0 = 0;
    if (P7D820Field(&P7D820D_80070328, int *, 0x50) == selector48) {
        copyDestination4 = &P7D820D_800719A8;
        sourceArg5 = &P7D820D_80068FA4;
        __asm__("" : "=r"(copyDestination4),"=r"(sourceArg5) : "0"(copyDestination4),"1"(sourceArg5));
    } else {
        copyDestination4 = &P7D820D_800719A8;
        sourceArg5 = &P7D820D_80068F7C;
        __asm__("" : "=r"(copyDestination4),"=r"(sourceArg5) : "0"(copyDestination4),"1"(sourceArg5));
    }
    P7D820func_800135A4(copyDestination4, sourceArg5, 0);
    P7D820func_800135A4(&P7D820D_800719F0, &P7D820D_80068F90, 0);
    if (P7D820Field(&P7D820D_80070328, int *, 0xB8) == 0) {
        P7D820Field(state, int *, 0x2C) = 0;
    }
    if ((P7D820D_8006E044 == 7) && ((unsigned int) (P7D820D_8006E048 - 3) < 2U)) {
        P7D820D_8006C768 = 1;
        P7D820Field(&P7D820D_80070328, int *, 0x288) = 1;
        P7D820D_8006E13F = 1;
    } else {
        P7D820D_8006C768 = 0;
    }
    if (P7D820Field(&P7D820D_80070328, int *, 0x24C) == 3) {
        requestedSelector = P7D820Field(&P7D820D_80070328, int *, 0x48) - 0x64;
        if (requestedSelector != P7D820Field(owner, unsigned char *, 0x3D)) {
            P7D820func_80034F40(owner, requestedSelector);
            P7D820Field(state, int *, 0x3C) = 0;
            goto selector3Counter;
        }
        goto updateSelector3;
    }
updateSelector3:
    stateArg4 = state + 0x24;
    if (P7D820Field(owner, unsigned char *, 0x3D) == 1) {
        if (P7D820Field(&P7D820D_80070328, int *, 0xB4) != 0) {
            scaledHeaderWord = (int)((unsigned int)P7D820Field(&P7D820D_80070328, int *, 0xB4) << 4);
            headerArg5 = scaledHeaderWord / 3840;
        } else {
            headerArg5 = 8;
        }
        P7D820unk_ovlheader_80074320(owner, headerArg5, state + 0x3C);
selector3Counter:
        stateArg4 = state + 0x24;
    }
    if ((P7D820func_800359A4(stateArg4, 4) != 0) && (P7D820D_8006E53C & 0x20) && (P7D820D_8006E044 != 0x26) && (P7D820Field(&P7D820D_80070328, int *, 0x240) == 0)) {
        P7D820func_80055D24(owner, 4);
        if (P7D820SpawnMoby(0x5A, owner) != 0) {
            P7D820Field(state, int *, 0x24) = 0x28;
            P7D820Field(state, int *, 0x28) = (int) (1 - P7D820Field(state, int *, 0x28));
        }
    }
    if ((((int *)P7D820D_80068CAC)[P7D820Field(&P7D820D_80070328, int *, 0x48)] == 0x1E) && (P7D820D_8006E53C & 0x10)) {
        P7D820Field(state, int *, 0x2C) = (int) (1 - P7D820Field(state, int *, 0x2C));
    }
    positionArg4 = owner + 0xC;
    if (P7D820D_8006E044 == 0x26) {
        workWord2 = P7D820D_8006E08C;
        workWord3 = P7D820D_8006E078;
        workWord2 -= workWord3;
        workWord3 = workWord2 & 0xFFF;
        if (workWord3 >= 0x801) {
            workWord3 -= 0x1000;
        }
        workWord2 = workWord3;
        if (workWord3 < 0) {
            workWord2 = -workWord2;
        }
        if (workWord2 < 0x80) {
            P7D820Field(owner, signed char *, 0x4C) = 0;
            P7D820Field(owner, signed char *, 0x4D) = 0;
            P7D820D_8006C768 = 1;
            positionArg4 = owner + 0xC;
        } else {
            P7D820Field(owner, signed char *, 0x4C) = 0x10;
            P7D820D_8006C768 = 0;
            positionArg4 = owner + 0xC;
        }
    }
    goto finishPositionArgument;
selector99:
    if (P7D820D_8006E044 != 11) goto finishPositionArgument;
    P7D820Field(owner, unsigned char *, 0x48) = 0;
notifySelector:
    selectorAddress99 = owner + 0x48;
    P7D820func_8003B7B4(selectorAddress99, 1, &P7D820D_8006D088);
    P7D820func_8003B7B4(selectorAddress99, 1, &P7D820D_8006C7F8);
finishPosition:
finishPositionArgument:
    positionArg4 = owner + 0xC;
    P7D820Field(owner, int *, 0x14) = (int) (P7D820Field(owner, int *, 0x14) + 0x100);
    P7D820func_8001A358(positionArg4, 0x1000);
    P7D820Field(owner, int *, 0x14) = (int) (P7D820Field(owner, int *, 0x14) - 0x100);
    P7D820func_8005629C(owner);
}

#undef P7D820Field


/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original functions: level13 8007DEA8, level22 80083A40,
 * level26 8007ACC0 and level34 8007DA38; 564 instructions each.
 * Offset names describe storage. Helper meanings, physical units and caller
 * cadence remain unresolved. Preserve signed halfword widths, wrapped
 * differences, ordered clamps, 32-bit shift wrapping and signed /180.
 * Empty compiler constraints emit no CPU instructions. Verified acceptance
 * requires every original linked word and full EXE/all-overlay hashes.
 */
#define P7DEA8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int P7DEA8func_80013E38() __asm__("func_80013E38");
int P7DEA8func_8001830C() __asm__("func_8001830C");
int P7DEA8func_80018368() __asm__("func_80018368");
void *P7DEA8func_8001BA30() __asm__("func_8001BA30");
int P7DEA8func_800359A4() __asm__("func_800359A4");
int P7DEA8func_8003BABC() __asm__("func_8003BABC");
int P7DEA8func_8003BE70() __asm__("func_8003BE70");
int P7DEA8func_8003BFC0() __asm__("func_8003BFC0");
int P7DEA8func_8003C0B0() __asm__("func_8003C0B0");
int P7DEA8func_80040954() __asm__("func_80040954");
int P7DEA8func_8004E880() __asm__("func_8004E880");
int P7DEA8func_8004ED6C() __asm__("func_8004ED6C");
int P7DEA8func_8004EDE8() __asm__("func_8004EDE8");
int P7DEA8func_8004F0E8() __asm__("func_8004F0E8");
int P7DEA8func_8004F110() __asm__("func_8004F110");
int P7DEA8func_8004F178() __asm__("func_8004F178");
int P7DEA8func_8004F194() __asm__("func_8004F194");
int P7DEA8func_8004F1C8() __asm__("func_8004F1C8");
int P7DEA8func_8004F334() __asm__("func_8004F334");
int P7DEA8func_80055B18() __asm__("func_80055B18");
int P7DEA8func_80055D24() __asm__("func_80055D24");
extern unsigned char P7DEA8D_800658A0[] __asm__("D_800658A0");
extern unsigned char P7DEA8D_80065920[] __asm__("D_80065920");
extern int P7DEA8D_8006C574 __asm__("D_8006C574");
extern int P7DEA8D_8006C578 __asm__("D_8006C578");
extern unsigned char P7DEA8D_8006D048[] __asm__("D_8006D048");
extern void *P7DEA8D_8006E788 __asm__("D_8006E788");
extern int P7DEA8D_80071924 __asm__("D_80071924");
extern void *(*P7DEA8SpawnMoby)() __asm__("SpawnMoby");
extern int (*P7DEA8SpawnParticle)() __asm__("SpawnParticle");
void func_level_13_8007DEA8(void *arg0) {
    register void *owner __asm__("$20");
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
    register int *savedVector28 __asm__("$17");
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
    struct { int sp18; int sp1C; int sp20; int sp24; int sp28; int sp2C; int sp30; int sp34; int sp38; int sp3C; int sp40; int sp44; int sp48; int sp4C; int sp50; int sp54; int sp58; int sp5C; int sp60; int sp64; int sp68; int sp6C; int sp70; int sp74; int sp78; int sp7C; int sp80; int sp84; int sp88; int sp8C; int sp90; int sp94; } frame;
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
    register void **objectListCursor __asm__("$22");
    void *temp_a0_2;
    void *linkedObject00;
    register void *privateState __asm__("$21");
    register void *ownerVector0C __asm__("$23");
    register void *queriedObject __asm__("$17");
    register void *temp_v0_2 __asm__("$16");
    register void *temp_v0_3 __asm__("$16");
    void *temp_v1_6;
    register void *scannedObject __asm__("$19");

    owner = arg0;
    ownerState48 = P7DEA8Field(owner, unsigned char *, 0x48);
    privateState = P7DEA8Field(owner, void **, 0);
    switch (ownerState48) {
    case 0:
        bestScore = 0x1869F;
        P7DEA8Field(privateState, void **, 0) = 0;
        objectListCursor = &P7DEA8D_8006E788;
        __asm__("" : "=r"(objectListCursor) : "0"(objectListCursor));
        scannedObject = *objectListCursor;
        objectListCursor += 1;
        if (scannedObject != 0) {
            ownerVector0C = owner + 0xC;
            do {
                if (!(P7DEA8Field(scannedObject, unsigned char *, 0x48) & 0x80) && (P7DEA8Field(scannedObject, int *, 8) != 0)) {
                    P7DEA8func_8004F178(&frame.sp18, scannedObject + 0xC);
                    frame.sp20 += 0x80;
                    wrappedDifference46 = (P7DEA8func_8004E880(frame.sp18 - P7DEA8Field(owner, int *, 0xC), frame.sp1C - P7DEA8Field(owner, int *, 0x10), 0) - P7DEA8Field(owner, unsigned char *, 0x46)) & 0xFF;
                    if (wrappedDifference46 >= 0x81) {
                        wrappedDifference46 -= 0x100;
                    }
                    wrappedDifference45 = (P7DEA8func_8004E880(P7DEA8func_8004F334(ownerVector0C, &frame.sp18), frame.sp20 - P7DEA8Field(owner, int *, 0x14), 0) - P7DEA8Field(owner, unsigned char *, 0x45)) & 0xFF;
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
                    if ((wrappedDifference46 < 0xC) && (wrappedDifference45 < 0xC)) {
                        distanceScore = 0x2800 - P7DEA8func_8004F334(ownerVector0C, &frame.sp18);
                        absoluteDistanceScore = distanceScore;
                        if (distanceScore < 0) {
                            absoluteDistanceScore = -absoluteDistanceScore;
                        }
                        result2 = (wrappedDifference46 + wrappedDifference45) << 10;
                        __asm__("" : "=r"(result2) : "0"(result2));
                        combinedScore = absoluteDistanceScore + result2;
                        if ((combinedScore < bestScore) && (P7DEA8func_80013E38(ownerVector0C, &frame.sp18, 4) != 0)) {
                            P7DEA8Field(privateState, void **, 0) = scannedObject;
                            bestScore = combinedScore;
                        }
                    }
                }
                scannedObject = *objectListCursor;
                objectListCursor += 1;
            } while (scannedObject != 0);
        }
        if (bestScore == 0x1869F) {
            P7DEA8Field(privateState, void **, 0) = 0;
        }
        initWord2 = P7DEA8Field(owner, unsigned char *, 0x44) << 4;
        __asm__("" : "=r"(initWord2) : "0"(initWord2));
        P7DEA8Field(privateState, short *, 4) = initWord2;
        initWord2 = P7DEA8Field(owner, unsigned char *, 0x45) << 4;
        __asm__("" : "=r"(initWord2) : "0"(initWord2));
        P7DEA8Field(privateState, short *, 6) = initWord2;
        phaseByte3 = P7DEA8Field(owner, unsigned char *, 0x46);
        initWord2 = 0xB4;
        P7DEA8Field(privateState, short *, 0xE) = initWord2;
        initWord2 = -1;
        P7DEA8Field(privateState, int *, 0x10) = initWord2;
        __asm__("" : : : "memory");
        initWord2 = 1;
        P7DEA8Field(privateState, short *, 0xA) = 0;
        P7DEA8Field(privateState, short *, 0xC) = 0;
        P7DEA8Field(privateState, short *, 8) = phaseByte3 << 4;
        P7DEA8Field(owner, unsigned char *, 0x48) = initWord2;
    case 1:
        ownerWord0C = P7DEA8Field(owner, int *, 0xC);
        if ((ownerWord0C > 0x3D400) || (ownerWord10 = P7DEA8Field(owner, int *, 0x10), ((ownerWord10 > 0x3D400) != 0)) || (ownerWord14 = P7DEA8Field(owner, int *, 0x14), ((ownerWord14 > 0x1E000) != 0)) || (ownerWord0C < 0x400) || (ownerWord10 < 0x400) || (ownerWord14 < 0x400) || ((result2 = P7DEA8func_800359A4(privateState + 0xE, 2)), (stackArg4 = &frame.sp28), result2 != 0)) {
            if (P7DEA8func_8003BFC0(owner, P7DEA8Field(privateState, int *, 0x10)) != 0) {
                P7DEA8func_8003BE70(P7DEA8Field(privateState, int *, 0x10));
            }
            goto block_93;
        }
        __asm__("" : "=r"(owner) : "0"(owner));
        savedOwnerVector0C = owner + 0xC;
        P7DEA8func_8004F178(stackArg4, savedOwnerVector0C);
        if (P7DEA8Field(P7DEA8Field(privateState, void **, 0), unsigned char *, 0x48) & 0x80) {
            P7DEA8Field(privateState, void **, 0) = 0;
        }
        linkedObject00 = P7DEA8Field(privateState, void **, 0);
        if (linkedObject00 != 0) {
            P7DEA8func_8004F178(&frame.sp48, linkedObject00 + 0xC);
            frame.sp50 += 0x80;
            vector38 = &frame.sp38;
            P7DEA8func_8004F1C8(vector38, &frame.sp48, savedOwnerVector0C);
            frame.sp40 += 0x100;
            P7DEA8func_8004E880(frame.sp38, frame.sp3C, 1);
            result2 = P7DEA8func_8004E880(frame.sp38, frame.sp3C, 1);
            halfword3 = P7DEA8Field(privateState, short *, 8);
            wrappedDifference08 = (result2 - halfword3) & 0xFFF;
            previousHalfword08 = halfword3;
            if (wrappedDifference08 >= 0x801) {
                wrappedDifference08 -= 0x1000;
            }
            absoluteDifference08 = wrappedDifference08;
            if (wrappedDifference08 < 0) {
                absoluteDifference08 = -absoluteDifference08;
            }
            if (absoluteDifference08 < 0x300) {
                work3 = 0xB4;
                result2 = P7DEA8Field(privateState, short *, 0xE);
                work3 -= result2;
                __asm__("" : "=r"(work3) : "0"(work3));
                upperStep = work3 >> 2;
                lowerStep = -upperStep;
                if (upperStep >= 9) {
                    upperStep = 8;
                    __asm__("" : "=r"(upperStep) : "0"(upperStep));
                    lowerStep = -upperStep;
                }
                if (wrappedDifference08 < lowerStep) wrappedDifference08 = lowerStep;
                if (upperStep < wrappedDifference08) wrappedDifference08 = upperStep;
                P7DEA8Field(privateState, short *, 8) = (short) (previousHalfword08 + wrappedDifference08);
                result2 = P7DEA8func_8004EDE8(vector38, 0, wrappedDifference08, previousHalfword08);
                result2 = P7DEA8func_8004E880(result2, frame.sp40, 1);
                previousHalfword06 = P7DEA8Field(privateState, short *, 6);
                wrappedDifference06 = (result2 - previousHalfword06) & 0xFFF;
                if (wrappedDifference06 >= 0x801) {
                    wrappedDifference06 -= 0x1000;
                }
                absoluteDifference06 = wrappedDifference06;
                if (wrappedDifference06 < 0) {
                    absoluteDifference06 = -absoluteDifference06;
                }
                if (absoluteDifference06 < 0x300) {
                    if (wrappedDifference06 < lowerStep) wrappedDifference06 = lowerStep;
                    if (upperStep < wrappedDifference06) wrappedDifference06 = upperStep;
                    updatedHalfword06 = previousHalfword06 + wrappedDifference06;
                    P7DEA8Field(privateState, short *, 6) = updatedHalfword06;
                } else {
                    goto block_63;
                }
            } else {
block_63:
                P7DEA8Field(privateState, void **, 0) = 0;
            }
        }
        P7DEA8Field(owner, unsigned char *, 0x44) = (unsigned char) ((unsigned short) P7DEA8Field(privateState, unsigned short *, 4) >> 4);
        P7DEA8Field(owner, unsigned char *, 0x45) = (unsigned char) ((unsigned short) P7DEA8Field(privateState, short *, 6) >> 4);
        P7DEA8Field(owner, unsigned char *, 0x46) = (unsigned char) ((unsigned short) P7DEA8Field(privateState, short *, 8) >> 4);
        P7DEA8func_80055D24(owner, 4);
        frame.sp38 = 0x180;
        frame.sp3C = 0;
        frame.sp40 = 0;
        P7DEA8func_8004ED6C(owner + 0x20, &frame.sp38, &frame.sp38);
        ownerVectorArgument = owner + 0xC;
        P7DEA8func_8004F194(ownerVectorArgument, ownerVectorArgument, &frame.sp38);
        savedVector28 = &frame.sp28;
        if (P7DEA8func_8001830C(savedVector28, ownerVectorArgument, 0, 0x10000, owner) != 0) {
            globalWordAddress16 = &P7DEA8D_80071924;
            if (P7DEA8func_80040954(*globalWordAddress16) == 3) {
                temp_a0_2 = *(void **)((unsigned char *)P7DEA8Field(P7DEA8D_8006D048, void **, 0x14) + ((*globalWordAddress16 & 0x3F) * 4));
                P7DEA8Field(temp_a0_2, int *, 4) = (int) (P7DEA8Field(temp_a0_2, int *, 4) | 0x10000);
            }
            P7DEA8func_8004F178(ownerVectorArgument, savedVector28);
            goto block_71;
        }
        queriedObject = P7DEA8func_8001BA30(ownerVectorArgument, 0x200, 1, 0, 0, owner);
        if (queriedObject != 0) {
            P7DEA8func_8004F178(&frame.sp58, queriedObject + 0xC);
            frame.sp60 += 0x80;
            if (P7DEA8func_80018368(ownerVectorArgument, &frame.sp58) == 0) {
                P7DEA8Field(queriedObject, int *, 0x18) = (int) (P7DEA8Field(queriedObject, int *, 0x18) | 0x10000);
block_71:
                P7DEA8Field(owner, unsigned char *, 0x48) = 2U;
            }
        }
        if (P7DEA8func_8003BFC0(owner, P7DEA8Field(privateState, int *, 0x10)) == 0) {
            P7DEA8Field(privateState, int *, 0x10) = P7DEA8func_8003BABC(owner, 0, 4);
        } else {
            /* Keep the original division constant before the signed load. */
            signedDivision180Magic = (int)0xB60B60B7;
            __asm__("" : "=r"(privateState) : "0"(privateState), "r"(signedDivision180Magic));
            halfword3 = P7DEA8Field(privateState, short *, 0xE);
            result2 = (int)((unsigned int)(0xB4 - halfword3) << 13);
            work3 = result2 / 180;
            __asm__("" : "=r"(work3) : "0"(work3));
            result2 = 0x1000;
            __asm__("" : "=r"(result2) : "0"(result2));
            scaledWord16 = result2 - work3;
            if (scaledWord16 < 0xA00) {
                scaledWord16 = 0xA00;
            }
            P7DEA8func_8003C0B0(P7DEA8Field(privateState, int *, 0x10), scaledWord16);
        }
        P7DEA8func_8004F110(&frame.sp38, 2);
        P7DEA8SpawnParticle(1, 0x37, owner + 0xC, &frame.sp38);
        return;
    case 2:
        temp_s1_3 = owner + 0xC;
        temp_v0_2 = P7DEA8func_8001BA30(temp_s1_3, 0x400, 1, 0, 0, owner);
        if ((temp_v0_2 != 0) && (P7DEA8func_80018368(temp_s1_3, temp_v0_2 + 0xC) == 0)) {
            P7DEA8Field(temp_v0_2, int *, 0x18) = (int) (P7DEA8Field(temp_v0_2, int *, 0x18) | 0x10000);
        }
        if (P7DEA8func_8003BFC0(owner, P7DEA8Field(privateState, int *, 0x10)) != 0) {
            P7DEA8func_8003BE70(P7DEA8Field(privateState, int *, 0x10));
        }
        if ((P7DEA8D_8006C578 - P7DEA8D_8006C574) >= 0x15) {
            temp_v0_3 = P7DEA8SpawnMoby(0x146, owner);
            if (temp_v0_3 != 0) {
                P7DEA8Field(temp_v0_3, signed char *, 0x47) = 8;
                P7DEA8Field(temp_v0_3, signed char *, 0x4C) = 0x3F;
                P7DEA8Field(temp_v0_3, signed char *, 0x4E) = 0x3F;
            }
        }
        P7DEA8func_8003BABC(owner, 1, 0);
        P7DEA8Field(privateState, short *, 0xE) = 4;
        P7DEA8Field(owner, unsigned char *, 0x48) = 3U;
    case 3:
        temp_v0_4 = P7DEA8Field(privateState, short *, 0xE);
        temp_v0_5 = (int)((unsigned int)temp_v0_4 << 4);
        var_s2_2 = temp_v0_5 / 4;
        var_s1_3 = 0;
        signedTable65920 = (short *)P7DEA8D_80065920;
        signedTable658A0 = (short *)P7DEA8D_800658A0;
        do {
            temp_v1_6 = P7DEA8Field(privateState, unsigned char **, 0x14) + (var_s1_3 * 2);
            tableIndex4 = P7DEA8Field(temp_v1_6, unsigned char *, 0) * 2;
            tablePointer2 = (short *)((unsigned char *)(long)tableIndex4 + (long)signedTable65920);
            tableProduct2 = *tablePointer2 * var_s2_2;
            tableIndex5 = P7DEA8Field(temp_v1_6, unsigned char *, 1) * 2;
            temp_a2 = (short *)((unsigned char *)(long)tableIndex5 + (long)signedTable65920);
            tableHalfword3 = *temp_a2;
            tableProduct2 = (tableProduct2 >> 12) * tableHalfword3;
            tablePointer4 = (short *)((unsigned char *)(long)tableIndex4 + (long)signedTable658A0);
            frame.sp78 = tableProduct2 >> 12;
            tableProduct2 = *tablePointer4 * var_s2_2;
            tableHalfword3 = *temp_a2;
            tableProduct2 = (tableProduct2 >> 12) * tableHalfword3;
            tablePointer5 = (short *)((unsigned char *)(long)tableIndex5 + (long)signedTable658A0);
            frame.sp7C = tableProduct2 >> 12;
            tableProduct2 = *tablePointer5 * var_s2_2;
            var_s1_3 += 1;
            frame.sp80 = tableProduct2 >> 12;
            P7DEA8func_8004F178(&frame.sp68, &frame.sp78, temp_a2);
            P7DEA8func_8004F0E8(&frame.sp68, 4);
            P7DEA8func_8004F194(&frame.sp68, &frame.sp68, owner + 0xC);
            P7DEA8SpawnParticle(1, 0x13, &frame.sp68, &frame.sp78);
        } while (var_s1_3 < 0xC);
        if (P7DEA8func_800359A4(privateState + 0xE, 2) != 0) {
            goto block_93;
        }
        break;
    }
    return;
block_93:
    P7DEA8func_80055B18(owner);
}

#undef P7DEA8Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_13/moby/func_level_13_8007E778.s SHA256 9169871d900e689a3d44a665896238cbde3a7fe062a2b02fc4541269178143a9. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int ControllerE778_func_80034F40() __asm__("func_80034F40");             /* extern */
int ControllerE778_func_80035194() __asm__("func_80035194");                  /* extern */
int ControllerE778_func_8003573C() __asm__("func_8003573C"); /* extern */
int ControllerE778_func_8003636C() __asm__("func_8003636C");                /* extern */
int ControllerE778_func_800369B8() __asm__("func_800369B8");             /* extern */
int ControllerE778_func_80036A68() __asm__("func_80036A68");   /* extern */
int ControllerE778_func_80038F14() __asm__("func_80038F14"); /* extern */
int ControllerE778_func_8003BA00() __asm__("func_8003BA00");                      /* extern */
int ControllerE778_func_8004E880() __asm__("func_8004E880");               /* extern */
int ControllerE778_func_8004EF04() __asm__("func_8004EF04");                  /* extern */
int ControllerE778_func_8004F110() __asm__("func_8004F110");              /* extern */
int ControllerE778_func_8004F178() __asm__("func_8004F178");                /* extern */
int ControllerE778_func_8004F194() __asm__("func_8004F194");         /* extern */
int ControllerE778_func_8004F1C8() __asm__("func_8004F1C8");        /* extern */
int ControllerE778_func_8004F264() __asm__("func_8004F264");                         /* extern */
int ControllerE778_func_8004F334() __asm__("func_8004F334");                   /* extern */
int ControllerE778_func_80055B18() __asm__("func_80055B18");                      /* extern */
int ControllerE778_func_80055D24() __asm__("func_80055D24");             /* extern */
int ControllerE778_func_80055E84() __asm__("func_80055E84");                          /* extern */
int ControllerE778_rand() __asm__("rand");                                         /* extern */
extern unsigned char ControllerE778_D_800658A0 __asm__("D_800658A0");
extern unsigned char ControllerE778_D_80065920 __asm__("D_80065920");
extern int ControllerE778_D_8006C770 __asm__("D_8006C770");
extern int global7036C __asm__("D_80070328+0x44");
extern unsigned char ControllerE778_D_80070328 __asm__("D_80070328");
extern unsigned char (*ControllerE778_SpawnParticle)(unsigned char, unsigned char, int *, int *) __asm__("SpawnParticle");

void func_level_13_8007E778(void *input_arg0) {
register void *owner __asm__("$18")=input_arg0;
    /* Original stack vectors at 0x10/0x20/0x30/0x40; retain each padding word. */
    struct {int sp10,sp14,sp18,pad1C,sp20,sp24,sp28,pad2C,sp30,pad34,sp38,pad3C,sp40,sp44,sp48,pad4C;} frame;
    register unsigned char *player __asm__("$22");
    register unsigned char *table5920 __asm__("$21");
    register unsigned char *table58A0 __asm__("$20");
    register int *vector30 __asm__("$16");
    register signed short *secondTableValuePtr __asm__("$5");
    register signed short *tableValuePtr __asm__("$3");
    register int tableValue3 __asm__("$3");
    register int tableValue2 __asm__("$2");
    register int *callVector __asm__("$4");
    register int *savedVector __asm__("$16");
    register unsigned char * globalVector98 __asm__("$16");
    register unsigned char * globalVector98State3 __asm__("$17");
    register unsigned char * globalVector98State6 __asm__("$17");
    register int randomIndex0 __asm__("$16");
    register int tableByteOffset0 __asm__("$16");
    register int tableByteOffset1 __asm__("$2");
    int helperCondition;
    register int particleIndex __asm__("$17");
    int delta0;
    int delta3a;
    int delta3b;
    int delta4;
    int delta6;
    unsigned char currentState;
    register void * ownerVector0C __asm__("$17");
    register void * ownerData __asm__("$19");

    ownerData = M2C_FIELD(owner, void **, 0);
    if ((M2C_FIELD(owner, unsigned char *, 0x48) != 7) && (M2C_FIELD(owner, int *, 0x18) & 0x90000)) {
        /* Original a0 remains owner; a1/a2/a3 = 1/0/0. */
        ControllerE778_func_80036A68(owner,1,0,0);
        ControllerE778_func_80038F14(owner, ownerData + 4, 1, 7);
        M2C_FIELD(ownerData, short *, 0xE) = 0x280;
    }
    currentState = M2C_FIELD(owner, unsigned char *, 0x48);
    switch (currentState) {
    case 0:
    case 1:
        ControllerE778_func_8003573C(owner, 6, 0, 1);
        callVector=&frame.sp10;__asm__("" : "=r"(callVector):"0"(callVector));
        globalVector98 = &ControllerE778_D_80070328 + 0x98;
        ControllerE778_func_8004F178(callVector, globalVector98);
        frame.sp10 *= 0x14;
        frame.sp14 *= 0x14;
        frame.sp18 *= 0x14;
        ControllerE778_func_8004F110(&frame.sp10, 6);
        ControllerE778_func_8004F194(&frame.sp10, &frame.sp10, globalVector98 - 0x98);
        if (ControllerE778_func_8004F334(owner + 0xC, &frame.sp10) < 0x1400) {
            delta0 = ((M2C_FIELD(owner, int *, 0x14) - M2C_FIELD(owner, short *, 0x38)) - M2C_FIELD(&ControllerE778_D_80070328, int *, 8)) + global7036C;
            if (delta0 < 0) {
                delta0 = -delta0;
            }
            if (delta0 < 0x400) {
                M2C_FIELD(owner, unsigned char *, 0x48) = 2U;
                ControllerE778_func_80034F40(owner, 2);
            } else {
                goto updateIdleState;
            }
        } else {
updateIdleState:
            if (ControllerE778_D_8006C770 != 0) {
                if (M2C_FIELD(ownerData, int *, 0) == 0) {
                    ControllerE778_func_80034F40(owner, 1);
                    M2C_FIELD(ownerData, int *, 0) = ControllerE778_func_8003636C(3, 6);
                } else {
                    ControllerE778_func_80034F40(owner, 0);
                    M2C_FIELD(ownerData, int *, 0) = (int) (M2C_FIELD(ownerData, int *, 0) - 1);
                }
            default:
            }
        }
        break;
    case 2:
        ControllerE778_func_8003573C(owner, 6, 0, 1);
        if (ControllerE778_D_8006C770 != 0) {
            M2C_FIELD(owner, unsigned char *, 0x48) = 3U;
            ControllerE778_func_80034F40(owner, 3);
        }
        break;
    case 3:
        ControllerE778_func_8003573C(owner, 6, 0, 1);
        savedVector=&frame.sp20;callVector=savedVector;__asm__("" : "=r"(callVector),"=r"(savedVector):"0"(callVector),"1"(savedVector));
        globalVector98State3 = &ControllerE778_D_80070328 + 0x98;
        ControllerE778_func_8004F178(callVector, globalVector98State3);
        frame.sp20 *= 0xA;
        frame.sp24 *= 0xA;
        frame.sp28 *= 0xA;
        ControllerE778_func_8004F110(savedVector, 6);
        ControllerE778_func_8004F194(savedVector, savedVector, globalVector98State3 - 0x98);
        if (ControllerE778_func_8004F334(owner + 0xC, savedVector) < 0xE00) {
            delta3a = ((M2C_FIELD(owner, int *, 0x14) - M2C_FIELD(owner, short *, 0x38)) - M2C_FIELD(&ControllerE778_D_80070328, int *, 8)) + global7036C;
            if (delta3a < 0) {
                delta3a = -delta3a;
            }
            if (delta3a >= 0x400) {
                goto testState3Fallback;
            }
            goto setState4;
        } else {
testState3Fallback:
            if (ControllerE778_func_8004F334(owner + 0xC, &ControllerE778_D_80070328) < 0x1801) {
                delta3b = ((M2C_FIELD(owner, int *, 0x14) - M2C_FIELD(owner, short *, 0x38)) - M2C_FIELD(&ControllerE778_D_80070328, int *, 8)) + global7036C;
                if (delta3b < 0) {
                    delta3b = -delta3b;
                }
                if (delta3b >= 0x601) {
                    goto setState5;
                }
            } else {
setState5:
                M2C_FIELD(owner, unsigned char *, 0x48) = 5U;
                ControllerE778_func_80034F40(owner, 5);
            }
        }
        break;
    case 4:
        ControllerE778_func_8003573C(owner, 6, 0, 1);
        if (((unsigned int) (ControllerE778_func_80055E84(owner) - 0xD) < 4U) && (ControllerE778_func_8004F264(M2C_FIELD(owner, unsigned char *, 0x46), ControllerE778_func_8004E880(((player=&ControllerE778_D_80070328),M2C_FIELD(player, int *, 0)) - M2C_FIELD(owner, int *, 0xC), M2C_FIELD(&ControllerE778_D_80070328, int *, 4) - M2C_FIELD(owner, int *, 0x10), 0)) < 0x10)) {
            ownerVector0C = owner + 0xC;
            if (ControllerE778_func_8004F334(ownerVector0C, player) < 0xE00) {
                delta4 = ((M2C_FIELD(owner, int *, 0x14) - M2C_FIELD(owner, short *, 0x38)) - M2C_FIELD(&ControllerE778_D_80070328, int *, 8)) + global7036C;
                if (delta4 < 0) {
                    delta4 = -delta4;
                }
                if (delta4 < 0x400) {
                    vector30=&frame.sp30;
                    ControllerE778_func_8004F1C8(vector30, ownerVector0C, player);
                    callVector=vector30;__asm__("" : "=r"(callVector):"0"(callVector));
                    particleIndex = 0;
                    table5920=&ControllerE778_D_80065920;
                    table58A0=&ControllerE778_D_800658A0;
                    __asm__("" : "=r"(table5920),"=r"(table58A0),"=r"(particleIndex):"0"(table5920),"1"(table58A0),"2"(particleIndex));
                    frame.sp38 += 0x400;
                    ControllerE778_func_8004EF04(callVector, global7036C);
                    ControllerE778_func_8004F194(vector30, vector30, player);
                    do {
                        particleIndex += 1;
                        randomIndex0 = ControllerE778_rand() & 0xFF;
                        tableByteOffset1 = ControllerE778_rand() & 0xFF;
                        /* Original second mask precedes the first index scale. */
                        __asm__("" : "=r"(tableByteOffset1),"=r"(randomIndex0):"0"(tableByteOffset1),"1"(randomIndex0));
                        tableByteOffset0 = randomIndex0 * 2;
                        tableValuePtr=(signed short *)((int)tableByteOffset0+(int)table5920);
                        tableByteOffset1 *= 2;
                        secondTableValuePtr = (signed short *)((int)tableByteOffset1 + (int)table5920);
                        __asm__("" : "=r"(tableValuePtr),"=r"(secondTableValuePtr):"0"(tableValuePtr),"1"(secondTableValuePtr));
                        tableValue3=*tableValuePtr;__asm__("" : "=r"(tableValue3):"0"(tableValue3));
                        frame.sp40 = (int) ((tableValue3 >> 7) * *secondTableValuePtr) >> 0xC;
                        tableValue3=*(signed short *)((int)tableByteOffset0 + (int)table58A0);__asm__("" : "=r"(tableValue3):"0"(tableValue3));
                        frame.sp44 = (int) ((tableValue3 >> 7) * *secondTableValuePtr) >> 0xC;
                        tableValue2=*(signed short *)((int)tableByteOffset1 + (int)table58A0);__asm__("" : "=r"(tableValue2):"0"(tableValue2));
                        frame.sp48 = tableValue2 >> 7;
                        ControllerE778_SpawnParticle(1, 0, &frame.sp30, &frame.sp40);
                    } while (particleIndex < 2);
                    M2C_FIELD(&ControllerE778_D_80070328, int *, 0x24) = (int) (M2C_FIELD(&ControllerE778_D_80070328, int *, 0x24) | 7);
                    M2C_FIELD(&ControllerE778_D_80070328, int *, 0x298) = (int) M2C_FIELD(owner, unsigned char *, 0x46);
                }
            }
        }
        if ((unsigned int) (M2C_FIELD(&ControllerE778_D_80070328, int *, 0x50) - 7) < 2U) {
            M2C_FIELD(owner, unsigned char *, 0x49) = 1U;
        }
        if (ControllerE778_D_8006C770 != 0) {
            if (M2C_FIELD(owner, unsigned char *, 0x49) != 0) {
                M2C_FIELD(owner, unsigned char *, 0x48) = 6U;
                ControllerE778_func_80034F40(owner, 6);
            } else {
                goto resetState;
            }
        }
        break;
    case 5:
        if (ControllerE778_D_8006C770 != 0) {
            __asm__ volatile("" : : "r"(owner));
            goto resetState;
        }
        break;
    case 6:
        ControllerE778_func_8003573C(owner, 6, 0, 1);
        savedVector=&frame.sp40;callVector=savedVector;__asm__("" : "=r"(callVector),"=r"(savedVector):"0"(callVector),"1"(savedVector));
        globalVector98State6 = &ControllerE778_D_80070328 + 0x98;
        ControllerE778_func_8004F178(callVector, globalVector98State6);
        frame.sp40 *= 0x14;
        frame.sp44 *= 0x14;
        frame.sp48 *= 0x14;
        ControllerE778_func_8004F110(savedVector, 6);
        ControllerE778_func_8004F194(savedVector, savedVector, globalVector98State6 - 0x98);
        helperCondition = ControllerE778_func_8004F334(owner + 0xC, savedVector) < 0xE00;
        if (ControllerE778_D_8006C770 != 0) {
            if (helperCondition != 0) {
                delta6 = ((M2C_FIELD(owner, int *, 0x14) - M2C_FIELD(owner, short *, 0x38)) - M2C_FIELD(&ControllerE778_D_80070328, int *, 8)) + global7036C;
                if (delta6 < 0) {
                    delta6 = -delta6;
                }
                if (delta6 < 0x400) {
setState4:
            M2C_FIELD(owner, unsigned char *, 0x49) = 0U;
            M2C_FIELD(owner, unsigned char *, 0x48) = 4U;
            ControllerE778_func_80034F40(owner, 4);
                    break;
                }
                goto resetState;
            }
resetStateAlias:
resetState:
                M2C_FIELD(ownerData, int *, 0) = ControllerE778_func_8003636C(3, 6);
                M2C_FIELD(owner, unsigned char *, 0x48) = 0U;
                ControllerE778_func_80034F40(owner, 0);
        }
        break;
    case 7:
        if (ControllerE778_func_80035194(owner, ownerData + 4) == 0x100) {
            ControllerE778_func_80055D24(owner, 4);
            ControllerE778_func_8003BA00(owner);
            ControllerE778_func_800369B8(owner, 0x30);
            ControllerE778_func_80055B18(owner);
        }
        break;
    }
    ControllerE778_func_80055D24(owner, 4);
}
#undef M2C_FIELD


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
void func_level_13_8007EEEC(Moby *input) {
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


/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007F2F8..8007F5BC. Original instructions define numeric branches.
 * Verified Crystal179 C supplies the baseline; indirect extra arguments remain unknown. */
extern unsigned char DecodedCrystalPlayer[] __asm__("D_80070328");
extern int D_8006C770;
void func_level_13_8007F2F8(Moby* argument) {
 register Moby* moby __asm__("$16") = argument;
 register int* tag __asm__("$17") = moby->mobyTag;
 int angle;
 if (moby->state != 3) {
  if (*(unsigned int*)((unsigned char*)moby+0x18) & 0x20000) {
   tag[8]=400;
   angle=*((unsigned char*)moby+0x51);
   if (!angle) angle=func_800360F8(func_8004E880(moby->position.x-*(int*)DecodedCrystalPlayer,moby->position.y-*(int*)(DecodedCrystalPlayer+4),0),DecodedCrystalPlayer[14],32,64);
   tag[7]=angle;tag[9]=64;SpawnMoby(16,moby);
   moby->unknownCollision=0;moby->state=3;func_80034F40(moby,3);
  } else if (*(unsigned int*)((unsigned char*)moby+0x18)) {
   tag[8]=200;
   angle=*((unsigned char*)moby+0x51);
   if (!angle) angle=func_800360F8(func_8004E880(moby->position.x-*(int*)DecodedCrystalPlayer,moby->position.y-*(int*)(DecodedCrystalPlayer+4),0),DecodedCrystalPlayer[14],32,64);
   tag[7]=angle;tag[9]=64;SpawnMoby(16,moby);
   /* This flag is freshly read after the indirect spawn callback. */
   if(moby->damageFlags&0x100000) {tag[8]+=200;tag[9]+=50;}
   moby->unknownCollision=0;moby->state=3;func_80034F40(moby,3);
  }
 }
 switch(moby->state) {
 case 0:case 1:
  if(D_8006C770) {
   tag[6]=func_8003636C(90,300);
   moby->state=2;func_80034F40(moby,2);
  } break;
 case 2:
  func_80037168(moby,(Vector3D*)tag,87);
  if(func_800359A4(tag+6,4)) {
   if(tag[10]) {
    tag[10]--;moby->state=0;func_80034F40(moby,0);
   } else {
    tag[10]=func_8003636C(2,4);moby->state=1;func_80034F40(moby,1);
   }
  } break;
 case 3:
  func_80035030(moby,tag+8,tag[7],tag+9,12,16,320,1);
  if(D_8006C770) {func_80055D24(moby,4);func_800369B8(moby,24);func_80055B18(moby);} break;
 }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_13/moby/func_level_13_8007F5C0.s SHA256 5449e3e202ea8370819be24d5e5bb861a5f387858c0ebbfda929d2afea4c69ce. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level13_7F5C0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Level13_7F5C0_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level13_7F5C0_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level13_7F5C0_D_8006C550 __asm__("D_8006C550");
extern Spyro Level13_7F5C0_D_80070328 __asm__("D_80070328");
extern int Level13_7F5C0_func_8001A358(Vector3D*, int) __asm__("func_8001A358");
int Level13_7F5C0_func_80035194(Moby*, void*) __asm__("func_80035194");
int Level13_7F5C0_func_800359A4(void*, int) __asm__("func_800359A4");
void Level13_7F5C0_func_800369B8() __asm__("func_800369B8");
void Level13_7F5C0_func_80038BF8(Moby*, EnemyTag*, int, int) __asm__("func_80038BF8");
int Level13_7F5C0_func_8003BABC(Moby*, int, int) __asm__("func_8003BABC");
extern int Level13_7F5C0_func_8004E880(int, int, int) __asm__("func_8004E880");
extern int Level13_7F5C0_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
extern void Level13_7F5C0_func_8004F110(Vector3D*, int) __asm__("func_8004F110");
extern void Level13_7F5C0_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level13_7F5C0_func_8004F194(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level13_7F5C0_func_8004F1C8(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
extern void Level13_7F5C0_func_80055D24(Moby*, int) __asm__("func_80055D24");
extern void Level13_7F5C0_func_8005629C(Moby*) __asm__("func_8005629C");
extern int Level13_7F5C0_rand() __asm__("rand");

int Level13_7F5C0_func_8004E9E4() __asm__("func_8004E9E4");
                             /* extern */
int Level13_7F5C0_func_8004EA2C() __asm__("func_8004EA2C");
                             /* extern */
unsigned char Level13_7F5C0_func_8004F0E8() __asm__("func_8004F0E8");
              /* extern */
extern int Level13_7F5C0_D_8006C574 __asm__("D_8006C574");
extern int Level13_7F5C0_D_8006C578 __asm__("D_8006C578");
extern unsigned char* Level13_7F5C0_D_8006EE2C[] __asm__("D_8006EE2C");

void func_level_13_8007F5C0(Moby *inputOwner) {
    /* Original frame0x80 and scratch vectors at SP10/20/30/40 retained.
     * Private offsets and model-table reads follow the original instructions.
     * Signed LH particle selectors and both height clamp branches are retained.
     * Empty constraints preserve physical register lifetimes without opcodes.
     * Units, fixed-point interpretation, helper contracts and cadence unresolved.
     * AI generated;
      not human reviewed. */
    register Moby* owner19 __asm__("$19")=inputOwner;
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register short* cosine22 __asm__("$22");
    register short* sine21 __asm__("$21");
    register Vector3D* vector20_17 __asm__("$17");
    register Vector3D* vector40_20 __asm__("$20");
    struct {Vector3D sp10;
     unsigned char pad1C[4];
     int sp20;
     int sp24;
     int sp28;
     unsigned char pad2C[4];
     int sp30;
     int sp34;
     int sp38;
     unsigned char pad3C[4];
     int sp40;
     int sp44;
     int sp48;
     unsigned char pad4C[12];
    } scratch;

    register Vector3D *ownerPosition16 __asm__("$16");
    register Vector3D *ownerPosition17 __asm__("$17");
    register Vector3D *private18 __asm__("$18");
    register Vector3D *var_a0 __asm__("$4");
    short *temp_a1_2;
    register int *temp_a0_2 __asm__("$4");
    register int *temp_a0_3 __asm__("$4");
    register int *temp_a1 __asm__("$5");
    int *temp_v1_2;
    register int temp_a0 __asm__("$4");
    int product;
    int secondProduct;
    register int firstAngle16 __asm__("$16");
    register int secondAngle16 __asm__("$16");
    register int particleOffset16 __asm__("$16");
    int temp_v0_2;
    int temp_v0_3;
    register int temp_v1_3 __asm__("$3");
    register int temp_v1_4 __asm__("$3");
    register int callbackArgument5 __asm__("$5");
    register int childIndex16 __asm__("$16");
    register int particleIndex18 __asm__("$18");
    register int particleCount23 __asm__("$23");
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int var_v1 __asm__("$3");
    register int var_v1_2 __asm__("$3");
    register unsigned char temp_a0_4 __asm__("$4");
    unsigned char temp_v0;
    int temp_v1;
    register int temp_v1_5 __asm__("$3");

    __asm__("" : "=r"(owner19):"0"(owner19));
    private18 = owner19->mobyTag;
    particleCount23 = 0;
    if (owner19->substate == 0) {
        argument4=(int)private18;
        __asm__("" : "=r"(argument4):"0"(argument4));
        ownerPosition16 = ((void *)((unsigned char *)owner19 + 0xC));
        Level13_7F5C0_func_8004F194((void*)argument4, ownerPosition16, &Level13_7F5C0_D_8006C550[Level13_7F5C0Field(private18, int *, 0x20)].position);
        Level13_7F5C0_func_8004F110(private18, 1);
        Level13_7F5C0_func_8004F1C8(&scratch.sp10, ownerPosition16, private18);
        Level13_7F5C0Field(private18, int *, 0x1C) = Level13_7F5C0_func_8004E880((int) scratch.sp10.x, scratch.sp10.y, 1);
        if (*Level13_7F5C0Field(private18, int **, 0xC) <= 0) {
            *Level13_7F5C0Field(private18, int **, 0xC) = Level13_7F5C0_func_8004EDE8(&scratch.sp10, 0);
            *Level13_7F5C0Field(private18, int **, 0x14) = 0;
            *Level13_7F5C0Field(private18, int **, 0x18) = owner19->position.z;
            Level13_7F5C0Field(private18, int *, 0x10) = 1;
        } else {
            Level13_7F5C0Field(private18, int *, 0x10) = 0;
        }
        owner19->substate = 1;
    }
    temp_v1 = owner19->state;
    switch (temp_v1) {                              /* irregular */
    case 0:
        childIndex16 = 0;
        if (owner19->damageFlags != 0) {
loop_13:
            if ((Level13_7F5C0_D_8006C578 - Level13_7F5C0_D_8006C574) >= 0x15) {
                argument4=245;
                argument5=(int)owner19;
                __asm__(""::"r"(argument4),"r"(argument5));
                childIndex16++;
                SpawnMoby(argument4,(void*)argument5);
                if (childIndex16 < 8) {
                    goto loop_13;
                }
            }
            __asm__ volatile("":::"memory");
            Level13_7F5C0_func_80038BF8(owner19, ((void *)((unsigned char *)private18 + 0x2C)), 1, 1);
            owner19->unknownCollision = 0;
            if (Level13_7F5C0Field(private18, int *, 0x10) != 0) {
                Level13_7F5C0Field(Level13_7F5C0_D_8006C550[Level13_7F5C0Field(private18, int *, 0x20)].mobyTag, int *, 0x10) = 1;
            }
        } else {
            if (Level13_7F5C0Field(private18, int *, 0x10) != 0) {
                temp_v1_2 = Level13_7F5C0Field(private18, int **, 0x14);
                *temp_v1_2 = (*temp_v1_2 + 0x20) & 0xFFF;
            }
            value2=Level13_7F5C0Field(private18,int*,0x14);
            value3=Level13_7F5C0Field(private18,int*,0x1C);
            value2=*(int*)value2;
            firstAngle16=(value2+value3)&0xFFF;
            scratch.sp20 = (int) (*Level13_7F5C0Field(private18, int **, 0xC) * Level13_7F5C0_func_8004EA2C(firstAngle16)) >> 0xC;
            product = *Level13_7F5C0Field(private18, int **, 0xC) * Level13_7F5C0_func_8004E9E4(firstAngle16);
            scratch.sp28 = 0;
            scratch.sp24 = product >> 0xC;
            Level13_7F5C0_func_8004F194(&owner19->position, private18, (Vector3D *) &scratch.sp20);
            value2=Level13_7F5C0Field(private18,int*,0x10);
            value3=firstAngle16+0x400;
            if(!value2)goto publishYaw;
            value2=Level13_7F5C0Field(private18,int*,0x28);
            if(!value2)goto publishYaw;
            argument5=Level13_7F5C0Field(private18,int*,0x18);
            value2=Level13_7F5C0_D_80070328.position.z;
            argument4=*(int*)argument5;
            value3=value2-argument4;
            if(value3 < -16){value3=-16;
            }
            value2=value3<17;
            if(value2){value2=argument4+value3;
            }
            else{value3=16;
            __asm__("" : "=r"(value3):"0"(value3));
             value2=argument4+value3;
            }
            *(int*)argument5=value2;
            value2=Level13_7F5C0Field(private18,int*,0x28);
            argument4=Level13_7F5C0Field(private18,int*,0x18);
            value3=Level13_7F5C0Field((void*)value2,int*,0xC);
            value2=*(int*)argument4;
            value3=Level13_7F5C0Field((void*)value3,int*,8);
            if(value2<value3)*(int*)argument4=value3;
            value2=Level13_7F5C0Field(private18,int*,0x28);
            argument4=Level13_7F5C0Field(private18,int*,0x18);
            value3=Level13_7F5C0Field((void*)value2,int*,0xC);
            value2=*(int*)argument4;
            value3=Level13_7F5C0Field((void*)value3,int*,0x18);
            if(value3<value2)*(int*)argument4=value3;
recomputeYaw:
            __asm__("" : "=r"(firstAngle16):"0"(firstAngle16));
            value3=firstAngle16+0x400;
publishYaw:
            value2=Level13_7F5C0Field(private18,int*,0x18);
            argument4=owner19->size;
            value2=*(int*)value2;
            value3>>=4;
            owner19->angle.yaw=value3;
            owner19->position.z=value2;
            if(argument4){
                value2=argument4-16;
                owner19->size=value2;
                value2&=255;
                if((unsigned)value2<33)owner19->size=0;
            }
            if ((Level13_7F5C0_D_80070328.unk13a[2] == owner19) && (Level13_7F5C0_D_80070328.critterMode == CRITTER_SGT_BYRD) && ((unsigned int) (Level13_7F5C0_D_80070328.movementState - 7) >= 2U)) {
                Level13_7F5C0_D_80070328.unk17a = 0x10000080;
                Level13_7F5C0_D_80070328.unk20[1] = 0x68;
            }
            Level13_7F5C0_func_8001A358(&owner19->position, 0x3000);
            Level13_7F5C0_func_8005629C(owner19);
            argument4=(int)owner19;
            callbackArgument5=2;
            goto invokeCallback;
        }
        break;
    case 1:
        owner19->angle.pitch += 8;
        temp_v0_2 = Level13_7F5C0_func_80035194(owner19, ((void *)((unsigned char *)private18 + 0x2C)));
        if ((temp_v0_2 == 0x100) || (temp_v0_2 == 3)) {
            Level13_7F5C0_func_80055D24(owner19, 4);
            Level13_7F5C0_func_800369B8(owner19, 0x20);
            owner19->lowDrawDistance = 0;
            owner19->drawn = 0;
            Level13_7F5C0Field(private18, int *, 0x24) = 0xB4;
            owner19->state = 2;
        }
        break;
    case 2:
        if (Level13_7F5C0Field(private18, int *, 0x24) >= 0x3D) {
            Level13_7F5C0_func_800359A4(((void *)((unsigned char *)private18 + 0x24)), 4);
        } else {
            Level13_7F5C0_func_8003BABC(owner19, 0, 0);
            owner19->state = 3;
        case 3:
            argument4=(int)private18+0x24;
            if (Level13_7F5C0Field(private18, int *, 0x24) < 0x3D) {
                secondAngle16 = (*Level13_7F5C0Field(private18, int **, 0x14) + Level13_7F5C0Field(private18, int *, 0x1C)) & 0xFFF;
                scratch.sp30 = (int) (*Level13_7F5C0Field(private18, int **, 0xC) * Level13_7F5C0_func_8004EA2C(secondAngle16)) >> 0xC;
                secondProduct = *Level13_7F5C0Field(private18, int **, 0xC) * Level13_7F5C0_func_8004E9E4(secondAngle16);
                ownerPosition17 = &owner19->position;
                scratch.sp38 = 0;
                scratch.sp34 = secondProduct >> 0xC;
                Level13_7F5C0_func_8004F194(ownerPosition17, private18, (Vector3D *) &scratch.sp30);
                argument4=2;
                argument5=0x47;
                argument6=(int)ownerPosition17;
                __asm__ volatile(""::"r"(argument4),"r"(argument5),"r"(argument6):"memory");
                value2=Level13_7F5C0Field(private18,int*,0x18);
                __asm__("" : "=r"(value2):"0"(value2));
                secondAngle16+=0x400;
                value3=*(int*)value2;
                __asm__("" : "=r"(secondAngle16):"0"(secondAngle16),"r"(value3));
                secondAngle16>>=4;
                owner19->angle.roll=0;
                owner19->angle.pitch=0;
                owner19->angle.yaw=secondAngle16;
                owner19->position.z=value3;
                SpawnParticle(argument4,argument5,(void*)argument6,0);
                __asm__("" : "=r"(private18):"0"(private18):"memory");
                argument4=(int)private18+0x24;
            }
            if (Level13_7F5C0_func_800359A4((void*)argument4, 4) != 0) {
                temp_v1_5 = Level13_7F5C0_D_8006C550[Level13_7F5C0Field(private18, int *, 0x20)].state;
                __asm__("" : "=r"(temp_v1_5):"0"(temp_v1_5));
                if (((unsigned int) (temp_v1_5 - 1) < 2U) || ((temp_v1_5 & 0xFF) == 3)) {
                    Level13_7F5C0Field(private18, int *, 0x10) = 1;
                } else {
                    Level13_7F5C0Field(private18, int *, 0x10) = 0;
                }
                value2=32;
                owner19->lowDrawDistance=value2;
                value2=127;
                value3=owner19->mobyClass;
                argument4=(int)owner19;
                owner19->damageFlags=0;
                owner19->size=value2;
                owner19->state=0;
                value3<<=2;
                value2=*(int*)((unsigned char*)Level13_7F5C0_D_8006EE2C+value3);
                callbackArgument5=7;
                value2=Level13_7F5C0Field((void*)value2,int*,0x3C);
                particleCount23=16;
                value2=*(unsigned char*)value2;
                value3=1;
                owner19->animationState.id=0;
                owner19->animationState.nextId=0;
                owner19->animationState.frame=0;
                owner19->animationState.nextFrame=value3;
                value2=(unsigned)value2<2;
                value2^=1;
                value2=-value2;
                value2&=48;
                owner19->animationProgress=value2;
invokeCallback:
                Level13_7F5C0_func_80055D24((void*)argument4,callbackArgument5);
                goto emitParticles;
            }
        }
        break;
    }
emitParticles:
    if (particleCount23 != 0) {
        __asm__("" : "=r"(particleCount23):"0"(particleCount23));
        particleIndex18=0;
        if (particleCount23 != 0) {
            cosine22=Level13_7F5C0_D_80065920;
            sine21=Level13_7F5C0_D_800658A0;
            vector20_17=(Vector3D*)&scratch.sp20;
            vector40_20=(Vector3D*)&scratch.sp40;
            do {
                particleIndex18 += 1;
                particleOffset16 = Level13_7F5C0_rand() & 0xFF;
                temp_v0_3 = Level13_7F5C0_rand() & 0xFF;
                value2=temp_v0_3;
                __asm__("" : "=r"(value2):"0"(value2));
                particleOffset16<<=1;
                value3=particleOffset16+(int)cosine22;
                __asm__("" : "=r"(value3):"0"(value3));
                value2<<=1;
                argument5=value2+(int)cosine22;
                __asm__ volatile(""::"r"(argument5),"r"(value3):"memory");
                value3=*(short*)value3;
                argument4=*(short*)argument5;
                __asm__("" : "=r"(value3):"0"(value3));
                value3>>=7;
                product=value3*argument4;
                particleOffset16+=(int)sine21;
                value3=product>>12;
                scratch.sp40=value3;
                value3=*(short*)particleOffset16;
                argument4=*(short*)argument5;
                __asm__("" : "=r"(value3):"0"(value3));
                value3>>=7;
                product=value3*argument4;
                value2+=(int)sine21;
                argument5=(int)vector40_20;
                value3=product>>12;
                scratch.sp44=value3;
                value2=*(short*)value2;
                __asm__ volatile(""::"r"(value2),"m"(scratch.sp44):"$4","memory");
                argument4=(int)vector20_17;
                __asm__("" : "=r"(value2):"0"(value2));
                value2>>=7;
                scratch.sp48=value2;
                Level13_7F5C0_func_8004F178((void*)argument4,(void*)argument5);
                Level13_7F5C0_func_8004F0E8(vector20_17, 2);
                Level13_7F5C0_func_8004F194(vector20_17, vector20_17, &owner19->position);
                SpawnParticle(1, 0, vector20_17, vector40_20);
            } while (particleIndex18 < particleCount23);
        }
        __asm__ volatile("":::"memory");
        SpawnParticle(particleCount23, 0x47, &owner19->position, 0);
    }
}
#undef Level13_7F5C0Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007FD5C.
 * AI generated;not human reviewed. Original1064 instructions+7 selectors+1 pad.
 * Original72-byte frame:9-argument outgoing area00..23;savesS0..S5/RA28..40.
 * No explicit local reserve,FP/SP binding,incoming saved value,overlapping
 * live GP alias,manual outgoing stack write or padding read is used.
 * S0's heading,owner-point address,distance,header result and D71930 address
 * have separate original producers;every former value dies before reuse.
 * S3 initially6 becomes target heading only in the original selected-owner
 * path;S4 keeps the original heading and S5 the initialized player base.
 * The complete signed64 variable MULT retains initialized signed32 operands
 * and full high projection. Original shifted low32 numerator,magic8D3DCB09,
 * signed>>4 and sign correction retain /29,followed by the original byte write.
 * Trig125 strength reductions and signed>>12 preserve native integer words.
 * Original LHU angle and signed16 class/path indices retain their domains.
 * D71930 is reloaded after each original pointer/field write and helper call.
 * Shared state/animation tails retain their distinct physical entries:the
 * angle failure enters LI4;callback failure first enters A2=0;range failure
 * enters SB4 after its own original LI4 branch delay. These entries are not
 * interchangeable even where A2 already contains zero on one predecessor.
 * The selected-heading false edge and seven ELF selectors target their
 * original instructions. All common setter inputs have initialized producers.
 * Empty metadata observes complete initialized values,addresses or fields
 * just written;clobbered GP roles are dead before fresh original producers.
 * It emits zero CPU instructions. No opcode templates,partial HILO,compiler,
 * flags,filters or native/control/data/table/hash gate has been changed.
 * Known helper signatures use existing EXE sources and headers. Header callback
 * semantic contracts and complete caller/allocation/physical-unit/fixed-point
 * chains remain open. Cadence:per invocation;frame-rate chain unresolved.
 * Confidence after full gates:binary identity. Synchronized retail captures
 * and human review remain required;engine/browser behavior is unchanged.
 */
/* Original assembly SHA256 f7448fa322f2e9b5cd382e36f15335b117fd6e2fad9103485681bf30a2dfdae8 */
#define Level13_7FD5CMultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level13_7FD5CCaptureHigh(v) do{int wholeHigh;__asm__("":"=h"(wholeHigh):"x"(completeSignedProduct));v=wholeHigh;Level13_7FD5CKeep(v);}while(0)
#define Level13_7FD5CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Level13_7FD5CKeep(v) __asm__("":"=r"(v):"0"(v))
void Level13_7FD5CAnimationPositive(void*,int) __asm__("func_80034F40");
void Level13_7FD5CCall80034F40(void*,int) __asm__("func_80034F40");
int Level13_7FD5CCall80035194(void*,void*) __asm__("func_80035194");
int Level13_7FD5CCall8003573C(void*,int,int,int) __asm__("func_8003573C");
int Level13_7FD5CCall8003585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Level13_7FD5CCall80035A80(void*,void*,int,int,int,int,int,int) __asm__("func_80035A80");
int Level13_7FD5CCall80036220(void*,void*,int,int) __asm__("func_80036220");
int Level13_7FD5CCall8003636C(int,int) __asm__("func_8003636C");
void Level13_7FD5CCall800369B8(void*,int) __asm__("func_800369B8");
void* Level13_7FD5CCall80036A68(void*,int,void*,void*) __asm__("func_80036A68");
void Level13_7FD5CCall80038BF8(void*,void*,int,int) __asm__("func_80038BF8");
void Level13_7FD5CCall8003BA00(void*) __asm__("func_8003BA00");
int Level13_7FD5CCall8004E880(int,int,int) __asm__("func_8004E880");
void Level13_7FD5CCall8004F178(void*,void*) __asm__("func_8004F178");
int Level13_7FD5CCall8004F264(int,int) __asm__("func_8004F264");
int Level13_7FD5CCall8004F334(void*,void*) __asm__("func_8004F334");
void Level13_7FD5CCall80055B18(void*) __asm__("func_80055B18");
void Level13_7FD5CCall80055D24(void*,int) __asm__("func_80055D24");
int Level13_7FD5CCall80055E84(void*) __asm__("func_80055E84");
extern int Level13_7FD5CData800658A0 __asm__("D_800658A0");
extern int Level13_7FD5CData80065920 __asm__("D_80065920");
extern int Level13_7FD5CData8006C550 __asm__("D_8006C550");
extern int Level13_7FD5CData8006C770 __asm__("D_8006C770");
extern int Level13_7FD5CData8006E020 __asm__("D_8006E020");
extern int Level13_7FD5CData8006E024 __asm__("D_8006E024");
extern unsigned short Level13_7FD5CData8006E040 __asm__("D_8006E040");
extern int Level13_7FD5CData8006E160 __asm__("D_8006E160");
extern int Level13_7FD5CData8006E164 __asm__("D_8006E164");
extern int Level13_7FD5CData8006EE2C __asm__("D_8006EE2C");
extern int Level13_7FD5CData80070328 __asm__("D_80070328");
extern int Level13_7FD5CData80071930 __asm__("D_80071930");
extern int(*Level13_7FD5CHeader800743F0)() __asm__("unk_ovlheader_800743F0");
extern int(*Level13_7FD5CHeader80074414)() __asm__("unk_ovlheader_80074414");
void func_level_13_8007FD5C(void* ownerParameter) {
long long completeSignedProduct;
register int headingDistanceResultOrGlobal16 __asm__("$16");
register int owner17 __asm__("$17");
register int privateRecord18 __asm__("$18");
register int initialSixOrTargetHeading19 __asm__("$19");
register int originalHeading20 __asm__("$20");
register int playerBase21 __asm__("$21");
register int resultOrIntermediate2 __asm__("$2"),fieldOrIntermediate3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),zeroArgument6 __asm__("$6"),ownerCoordinate7 __asm__("$7"),capturedHigh8 __asm__("$8"),unusedWord9 __asm__("$9"),unusedWord10 __asm__("$10");



    int temp_a0;


    int temp_v0_2;

    int temp_v1_2;

    unsigned char temp_v1;
    unsigned char temp_v1_11;
    unsigned char temp_v1_3;
    unsigned char temp_v1_5;


    int temp_a0_2;
    int temp_a0_3;


    int temp_v0;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1_10;
    int temp_v1_4;
    int temp_v1_8;

    owner17=(int)ownerParameter;Level13_7FD5CKeep(owner17);
    privateRecord18 = Level13_7FD5CField(owner17, int *, 0);
    if (Level13_7FD5CField(owner17, unsigned char *, 0x49) == 0) {
        Level13_7FD5CField(privateRecord18, int *, 0x1C) = (void *) (privateRecord18 + 0x20);
        Level13_7FD5CField(privateRecord18, int *, 0x54) = (int) Level13_7FD5CField(privateRecord18, int *, 0x58);
        Level13_7FD5CField(owner17, unsigned char *, 0x49) = 1U;
    }
    if (Level13_7FD5CField(owner17, unsigned char *, 0x48) != 4) {
        temp_v1 = Level13_7FD5CField(owner17, unsigned char *, 0x49);
        if (((temp_v1 == 2) || (temp_v1 == 5)) && !(Level13_7FD5CField(privateRecord18, int *, 0) & 4)) {
            fieldOrIntermediate3=(int)&Level13_7FD5CData8006E160;Level13_7FD5CKeep(fieldOrIntermediate3);resultOrIntermediate2=Level13_7FD5CField(fieldOrIntermediate3,int*,0);
            if(resultOrIntermediate2==0){
                Level13_7FD5CField(fieldOrIntermediate3,int*,0)=13;
                Level13_7FD5CData8006E164 = owner17;
            }
        } else if (({fieldOrIntermediate3=(int)&Level13_7FD5CData8006E164;Level13_7FD5CKeep(fieldOrIntermediate3);resultOrIntermediate2=Level13_7FD5CField(fieldOrIntermediate3,int*,0);resultOrIntermediate2==owner17;})) {
            Level13_7FD5CData8006E160 = 0;
            Level13_7FD5CField(fieldOrIntermediate3,int*,0)=0;
        }
        if (Level13_7FD5CField(owner17, int *, 0x18) & 0x30000) {
            headingDistanceResultOrGlobal16 = Level13_7FD5CField(owner17, unsigned char *, 0x48);
            if (headingDistanceResultOrGlobal16 == 6) {
                resultOrIntermediate2=Level13_7FD5CCall80055E84(owner17);fieldOrIntermediate3=(int)0x8D3DCB09;resultOrIntermediate2=(unsigned int)resultOrIntermediate2<<7;Level13_7FD5CMultiplyComplete(resultOrIntermediate2,fieldOrIntermediate3);fieldOrIntermediate3=Level13_7FD5CField(owner17,unsigned char*,70);Level13_7FD5CCaptureHigh(capturedHigh8);argumentOrField4=capturedHigh8+resultOrIntermediate2;argumentOrField4>>=4;resultOrIntermediate2>>=31;argumentOrField4-=resultOrIntermediate2;fieldOrIntermediate3-=argumentOrField4;Level13_7FD5CField(owner17,unsigned char*,70)=fieldOrIntermediate3;
            }
            Level13_7FD5CCall80036A68(owner17, 0, 0, 0);
            Level13_7FD5CCall80038BF8(owner17, privateRecord18 + 0x60, 0, 4);
            Level13_7FD5CField(owner17, int *, 8) = 0;
            if (headingDistanceResultOrGlobal16 == 6) {
                resultOrIntermediate2=Level13_7FD5CField(owner17,short*,54);__asm__ volatile("":::"$3","memory");fieldOrIntermediate3=4;Level13_7FD5CKeep(fieldOrIntermediate3);Level13_7FD5CField(owner17,unsigned char*,72)=fieldOrIntermediate3;resultOrIntermediate2*=4;resultOrIntermediate2=Level13_7FD5CField((int)&Level13_7FD5CData8006EE2C+resultOrIntermediate2,int*,0);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,int*,76);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,unsigned char*,0);
                Level13_7FD5CField(owner17,signed char*,60)=fieldOrIntermediate3;Level13_7FD5CField(owner17,signed char*,61)=fieldOrIntermediate3;fieldOrIntermediate3=1;Level13_7FD5CField(owner17,signed char*,62)=0;Level13_7FD5CField(owner17,signed char*,63)=fieldOrIntermediate3;resultOrIntermediate2=-(resultOrIntermediate2>=2U)&48;Level13_7FD5CField(owner17,signed char*,64)=resultOrIntermediate2;
            }
            resultOrIntermediate2=640;Level13_7FD5CKeep(resultOrIntermediate2);Level13_7FD5CField(privateRecord18,short*,106)=resultOrIntermediate2;__asm__ volatile(""::"m"(Level13_7FD5CField(privateRecord18,short*,106)):"memory");
            resultOrIntermediate2=23;Level13_7FD5CKeep(resultOrIntermediate2);fieldOrIntermediate3=(int)&Level13_7FD5CData8006E164;Level13_7FD5CKeep(fieldOrIntermediate3);Level13_7FD5CField(privateRecord18,signed char*,111)=resultOrIntermediate2;
            if((resultOrIntermediate2=Level13_7FD5CField(fieldOrIntermediate3,int*,0),resultOrIntermediate2==owner17)){
                Level13_7FD5CData8006E160 = 0;
                Level13_7FD5CField(fieldOrIntermediate3,int*,0)=0;
            }
        }
    }
    temp_v1_2 = Level13_7FD5CField(privateRecord18, int *, 0x50);
    if ((temp_v1_2 != 0) && (Level13_7FD5CField(((temp_v1_2 * 0x58) + Level13_7FD5CData8006C550), unsigned char *, 0x48) & 0x80)) {
        Level13_7FD5CField(privateRecord18, int *, 0x50) = -1;
        Level13_7FD5CField(privateRecord18, int *, 0) = (int) (Level13_7FD5CField(privateRecord18, int *, 0) & ~1);
    }
    temp_v1_3 = Level13_7FD5CField(owner17, unsigned char *, 0x48);
    switch (temp_v1_3) {                            
    case 0:                                         
    case 1:                                         
        if (Level13_7FD5CField(owner17, unsigned char *, 0x49) == 5) {
            temp_v1_4 = Level13_7FD5CField(privateRecord18, int *, 0x18);
            temp_v0 = (Level13_7FD5CField(temp_v1_4, short *, 2) * 0x10) + Level13_7FD5CField(temp_v1_4, int *, 0xC);
            Level13_7FD5CCall8003585C(owner17, Level13_7FD5CCall8004E880(Level13_7FD5CField(temp_v0, int *, 0) - Level13_7FD5CField(owner17, int *, 0xC), Level13_7FD5CField(temp_v0, int *, 4) - Level13_7FD5CField(owner17, int *, 0x10), 0), 8, 0, 1, 0);
            if (Level13_7FD5CCall8004F264((int) (Level13_7FD5CData8006E040 << 0x10) >> 0x14, Level13_7FD5CCall8004E880(Level13_7FD5CField(owner17, int *, 0xC) - Level13_7FD5CData8006E020, Level13_7FD5CField(owner17, int *, 0x10) - Level13_7FD5CData8006E024, 0)) >= 0x18) {
                if (Level13_7FD5CCall80036220((int)&Level13_7FD5CData80070328, Level13_7FD5CField(privateRecord18, int *, 0x1C), 0x400, 0x400) == 0) {
                    Level13_7FD5CField(owner17, unsigned char *, 0x49) = 1U;
                }
            } else {
                goto block_42;
            }
        } else {
            if ((Level13_7FD5CCall8004F264((int) (Level13_7FD5CData8006E040 << 0x10) >> 0x14, Level13_7FD5CCall8004E880(Level13_7FD5CField(owner17, int *, 0xC) - Level13_7FD5CData8006E020, Level13_7FD5CField(owner17, int *, 0x10) - Level13_7FD5CData8006E024, 0)) < 0x1C) && ((unsigned int) (Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x50) - 7) >= 2U) && (Level13_7FD5CHeader80074414(Level13_7FD5CField(privateRecord18, int *, 0x54), ((int)&Level13_7FD5CData80070328 + 0x50) - 0x50) != 0)) {
                resultOrIntermediate2=Level13_7FD5CField(privateRecord18,int*,80);if(resultOrIntermediate2<0)resultOrIntermediate2=2;else resultOrIntermediate2=3;Level13_7FD5CKeep(resultOrIntermediate2);Level13_7FD5CField(owner17,unsigned char*,73)=resultOrIntermediate2;
                goto block_41;
            }
            if ((Level13_7FD5CField(privateRecord18, int *, 0x18) != 0) && (Level13_7FD5CCall80036220((int)&Level13_7FD5CData80070328, Level13_7FD5CField(privateRecord18, int *, 0x1C), 0, 0x400) != 0) && (temp_a0 = Level13_7FD5CField(privateRecord18, int *, 0), ((temp_a0 & 1) == 0)) && ((Level13_7FD5CField(privateRecord18, int *, 0x50) < 0) || (Level13_7FD5CField(Level13_7FD5CField(privateRecord18, int *, 0x18), short *, 0xA) == 1)) && ((unsigned int) (Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x50) - 7) >= 2U)) {
                if ((temp_a0 & 2) || (Level13_7FD5CCall8004F264((int) (Level13_7FD5CData8006E040 << 0x10) >> 0x14, Level13_7FD5CCall8004E880(Level13_7FD5CField(owner17, int *, 0xC) - Level13_7FD5CData8006E020, Level13_7FD5CField(owner17, int *, 0x10) - Level13_7FD5CData8006E024, 0)) < 0x1C)) {
                    Level13_7FD5CField(owner17, unsigned char *, 0x49) = 5U;
                    if (!(Level13_7FD5CField(privateRecord18, int *, 0) & 2)) {
block_41:
block_42:
                        Level13_7FD5CField(owner17, unsigned char *, 0x48) = 2U;
                        Level13_7FD5CCall80034F40(owner17, 2);
                    }
                }
            } else if (Level13_7FD5CField(privateRecord18, int *, 0x14) != 0) {
                Level13_7FD5CField(owner17, unsigned char *, 0x49) = 1U;
                Level13_7FD5CField(owner17, unsigned char *, 0x48) = 5U;
                Level13_7FD5CCall80034F40(owner17, 5);
            } else {
                Level13_7FD5CCall8003573C(owner17, 8, 0x18, 1);
            }
        }
        if (Level13_7FD5CData8006C770 != 0) {
            temp_v0_2 = Level13_7FD5CField(privateRecord18, int *, 4) - 1;
            Level13_7FD5CField(privateRecord18, int *, 4) = temp_v0_2;
            if (temp_v0_2 <= 0) {
                temp_v1_5 = Level13_7FD5CField(owner17, unsigned char *, 0x48);
                if (temp_v1_5 == 0) {
                    resultOrIntermediate2=Level13_7FD5CCall8003636C(2,4);argumentOrField4=owner17;argumentOrField5=1;Level13_7FD5CField(privateRecord18,int*,4)=resultOrIntermediate2;resultOrIntermediate2=1;
                    goto block_127;
                } else if (temp_v1_5 == 1) {
                    resultOrIntermediate2=Level13_7FD5CCall8003636C(3,5);argumentOrField4=owner17;argumentOrField5=0;Level13_7FD5CField(privateRecord18,int*,4)=resultOrIntermediate2;
                    goto block_139;
                }
            }
        }
        break;
    case 2:                                         
        if ((Level13_7FD5CCall8004F264((int) Level13_7FD5CField(owner17, unsigned char *, 0x46), Level13_7FD5CCall8004E880(Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0) - Level13_7FD5CField(owner17, int *, 0xC), Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 4) - Level13_7FD5CField(owner17, int *, 0x10), 0)) < 0x20) && (Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x138) == owner17)) {
            resultOrIntermediate2 = ((Level13_7FD5CField(owner17, int *, 0x14) - Level13_7FD5CField(owner17, short *, 0x38)) - Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 8)) + Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x44);
            if (resultOrIntermediate2 < 0) {
                resultOrIntermediate2 = -resultOrIntermediate2;
            }
            if (resultOrIntermediate2 < 0x200) {
                argumentOrField4=owner17;Level13_7FD5CKeep(argumentOrField4);
                Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x24) = (int) (Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x24) | 0x80);
                Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x298) = (int) Level13_7FD5CField(owner17, unsigned char *, 0x46);
                resultOrIntermediate2=Level13_7FD5CField(owner17,unsigned char*,70);resultOrIntermediate2*=2;fieldOrIntermediate3=Level13_7FD5CField((int)&Level13_7FD5CData80065920+resultOrIntermediate2,short*,0);resultOrIntermediate2=fieldOrIntermediate3*31;Level13_7FD5CKeep(resultOrIntermediate2);resultOrIntermediate2=resultOrIntermediate2*4+fieldOrIntermediate3;resultOrIntermediate2>>=12;Level13_7FD5CField((int)&Level13_7FD5CData80070328,int*,540)=resultOrIntermediate2;
                resultOrIntermediate2=Level13_7FD5CField(owner17,unsigned char*,70);__asm__ volatile("":::"$5","memory");argumentOrField5=3;Level13_7FD5CKeep(argumentOrField5);resultOrIntermediate2*=2;fieldOrIntermediate3=Level13_7FD5CField((int)&Level13_7FD5CData800658A0+resultOrIntermediate2,short*,0);resultOrIntermediate2=20;Level13_7FD5CField((int)&Level13_7FD5CData80070328,int*,548)=resultOrIntermediate2;
                resultOrIntermediate2=fieldOrIntermediate3*31;Level13_7FD5CKeep(resultOrIntermediate2);resultOrIntermediate2=resultOrIntermediate2*4+fieldOrIntermediate3;resultOrIntermediate2>>=12;Level13_7FD5CField((int)&Level13_7FD5CData80070328,int*,544)=resultOrIntermediate2;resultOrIntermediate2=3;
                goto block_127;
            }
            goto block_58;
        }
block_58:
        fieldOrIntermediate3=Level13_7FD5CField(owner17,unsigned char*,73);Level13_7FD5CKeep(fieldOrIntermediate3);
        if((int)fieldOrIntermediate3<2)goto actor1064Finish;
        if((int)fieldOrIntermediate3>=4){if(fieldOrIntermediate3==5)goto actor1064Substate5;goto actor1064Finish;}

                zeroArgument6=0;Level13_7FD5CKeep(zeroArgument6);playerBase21=(int)&Level13_7FD5CData80070328;Level13_7FD5CKeep(playerBase21);
                headingDistanceResultOrGlobal16 = Level13_7FD5CCall8004E880(Level13_7FD5CField(playerBase21,int*,0) - Level13_7FD5CField(owner17, int *, 0xC), Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 4) - Level13_7FD5CField(owner17, int *, 0x10), zeroArgument6);
                originalHeading20 = headingDistanceResultOrGlobal16;
                if(Level13_7FD5CField(owner17,unsigned char*,73)==3){
                    fieldOrIntermediate3=Level13_7FD5CField(privateRecord18,int*,80);
                    if(fieldOrIntermediate3<0)goto actor1064State2;
                    resultOrIntermediate2=fieldOrIntermediate3*11;fieldOrIntermediate3=Level13_7FD5CData8006C550;resultOrIntermediate2*=8;argumentOrField5=resultOrIntermediate2+fieldOrIntermediate3;
                    if(Level13_7FD5CField(argumentOrField5,unsigned char*,72)&128)goto actor1064State2;
                    initialSixOrTargetHeading19=Level13_7FD5CCall8004E880(Level13_7FD5CField(argumentOrField5,int*,12)-Level13_7FD5CField(owner17,int*,12),Level13_7FD5CField(argumentOrField5,int*,16)-Level13_7FD5CField(owner17,int*,16),0);Level13_7FD5CKeep(initialSixOrTargetHeading19);
                    argumentOrField4=initialSixOrTargetHeading19;argumentOrField5=headingDistanceResultOrGlobal16;resultOrIntermediate2=Level13_7FD5CCall8004F264(argumentOrField4,argumentOrField5);
                    if(resultOrIntermediate2>=25)goto actor1064RestoreHeading;
                    headingDistanceResultOrGlobal16=owner17+12;resultOrIntermediate2=Level13_7FD5CCall8004F334(headingDistanceResultOrGlobal16,playerBase21);argumentOrField4=headingDistanceResultOrGlobal16;argumentOrField5=Level13_7FD5CField(privateRecord18,int*,80);headingDistanceResultOrGlobal16=resultOrIntermediate2;
                    fieldOrIntermediate3=argumentOrField5*11;argumentOrField5=Level13_7FD5CData8006C550;fieldOrIntermediate3*=8;argumentOrField5+=fieldOrIntermediate3;argumentOrField5+=12;resultOrIntermediate2=Level13_7FD5CCall8004F334(argumentOrField4,argumentOrField5);headingDistanceResultOrGlobal16=headingDistanceResultOrGlobal16<resultOrIntermediate2;
                    if(headingDistanceResultOrGlobal16){
actor1064RestoreHeading:
                        headingDistanceResultOrGlobal16=originalHeading20;
actor1064State2:
                        resultOrIntermediate2=2;Level13_7FD5CField(owner17,unsigned char*,73)=resultOrIntermediate2;
                    }else headingDistanceResultOrGlobal16=initialSixOrTargetHeading19;
                }
actor1064ApplyHeading:
                resultOrIntermediate2=Level13_7FD5CHeader800743F0(owner17, headingDistanceResultOrGlobal16, 0xE0, 0x280, 0x280, 0x27, privateRecord18 + 0x54, 1, 0);zeroArgument6=0;Level13_7FD5CKeep(zeroArgument6);headingDistanceResultOrGlobal16=resultOrIntermediate2;
                ownerCoordinate7=Level13_7FD5CField(owner17,int*,12);argumentOrField4=Level13_7FD5CData8006E020;fieldOrIntermediate3=Level13_7FD5CField(owner17,int*,16);argumentOrField5=Level13_7FD5CData8006E024;argumentOrField4=ownerCoordinate7-argumentOrField4;argumentOrField5=fieldOrIntermediate3-argumentOrField5;resultOrIntermediate2=Level13_7FD5CCall8004E880(argumentOrField4,argumentOrField5,zeroArgument6);
                resultOrIntermediate2=Level13_7FD5CCall8004F264((int)(Level13_7FD5CData8006E040<<16)>>20,resultOrIntermediate2);resultOrIntermediate2=resultOrIntermediate2<33;Level13_7FD5CKeep(resultOrIntermediate2);zeroArgument6=0;
                if(resultOrIntermediate2==0)goto actor1064FallbackState4;
                argumentOrField5=(int)&Level13_7FD5CData80070328+80;Level13_7FD5CKeep(argumentOrField5);resultOrIntermediate2=Level13_7FD5CField(argumentOrField5,int*,0);
                if((unsigned int)(resultOrIntermediate2-7)<2U){resultOrIntermediate2=4;goto actor1064StoreState4;}
                argumentOrField4=Level13_7FD5CField(privateRecord18,int*,84);
                if(Level13_7FD5CHeader80074414(argumentOrField4,argumentOrField5-80,zeroArgument6)!=0){resultOrIntermediate2=headingDistanceResultOrGlobal16&32;goto actor1064ChildFlags;}
                zeroArgument6=0;
actor1064FallbackState4:
                resultOrIntermediate2=4;
actor1064StoreState4:
                    Level13_7FD5CField(owner17, unsigned char *, 0x49) = resultOrIntermediate2;
                    if (Level13_7FD5CCall8004F264((int) Level13_7FD5CField(owner17, unsigned char *, 0x46), Level13_7FD5CCall8004E880(Level13_7FD5CField(privateRecord18, int *, 8) - Level13_7FD5CField(owner17, int *, 0xC), Level13_7FD5CField(privateRecord18, int *, 0xC) - Level13_7FD5CField(owner17, int *, 0x10), zeroArgument6)) >= 0x40) {
                        Level13_7FD5CField(owner17, unsigned char *, 0x48) = 6U;
                        argumentOrField4=owner17;Level13_7FD5CKeep(argumentOrField4);argumentOrField5 = 6;
                    } else {
                        Level13_7FD5CField(owner17, unsigned char *, 0x48) = 5U;
                        argumentOrField4=owner17;Level13_7FD5CKeep(argumentOrField4);argumentOrField5 = 5;
                    }
                    __asm__ volatile(""::"r"(argumentOrField4),"r"(argumentOrField5));Level13_7FD5CCall80034F40(argumentOrField4, argumentOrField5);
                    resultOrIntermediate2 = headingDistanceResultOrGlobal16 & 0x20;
actor1064ChildFlags:
                if(resultOrIntermediate2==0)goto actor1064Finish;
                headingDistanceResultOrGlobal16=(int)&Level13_7FD5CData80071930;Level13_7FD5CKeep(headingDistanceResultOrGlobal16);resultOrIntermediate2=Level13_7FD5CField(headingDistanceResultOrGlobal16,int*,0);
                if(resultOrIntermediate2==0)goto actor1064Finish;
                fieldOrIntermediate3=0x10000000;Level13_7FD5CKeep(fieldOrIntermediate3);argumentOrField4=Level13_7FD5CData80071930;resultOrIntermediate2=Level13_7FD5CField(argumentOrField4,int*,24);zeroArgument6=0;resultOrIntermediate2|=fieldOrIntermediate3;Level13_7FD5CField(argumentOrField4,int*,24)=resultOrIntermediate2;
                __asm__ volatile("":::"memory");resultOrIntermediate2=Level13_7FD5CData80071930;argumentOrField4=Level13_7FD5CField(owner17,int*,12);argumentOrField5=Level13_7FD5CField(owner17,int*,16);fieldOrIntermediate3=Level13_7FD5CField(resultOrIntermediate2,int*,12);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,int*,16);argumentOrField4=fieldOrIntermediate3-argumentOrField4;argumentOrField5=resultOrIntermediate2-argumentOrField5;resultOrIntermediate2=Level13_7FD5CCall8004E880(argumentOrField4,argumentOrField5,zeroArgument6);
                fieldOrIntermediate3=Level13_7FD5CData80071930;Level13_7FD5CField(fieldOrIntermediate3,unsigned char*,81)=resultOrIntermediate2;fieldOrIntermediate3=Level13_7FD5CData80071930;resultOrIntermediate2=Level13_7FD5CField(fieldOrIntermediate3,unsigned char*,81);if(resultOrIntermediate2==0)Level13_7FD5CField(fieldOrIntermediate3,unsigned char*,81)=1;
                    if ((Level13_7FD5CField(owner17, unsigned char *, 0x49) == 3) && (((int) -((Level13_7FD5CField(headingDistanceResultOrGlobal16,int*,0) - Level13_7FD5CData8006C550) * 0x45D1745D) >> 3) == Level13_7FD5CField(privateRecord18, int *, 0x50))) {
                        Level13_7FD5CField(privateRecord18, int *, 0x50) = -1;
                        Level13_7FD5CField(owner17, unsigned char *, 0x49) = 2U;
                    }

        goto actor1064Finish;
actor1064Substate5:

                    Level13_7FD5CData80071930 = 0;
                    if (Level13_7FD5CCall80035A80(owner17, Level13_7FD5CField(privateRecord18, int *, 0x18), 0x200, 0xE0, 0x280, 8, 8, 7) & 1) {
                        temp_a0_2 = Level13_7FD5CField(privateRecord18, int *, 0x18);
                        fieldOrIntermediate3 = Level13_7FD5CField(temp_a0_2, short *, 0xA);
                        if (fieldOrIntermediate3 == 1) {
                            if (Level13_7FD5CField(temp_a0_2, short *, 2) == 0) {
                                Level13_7FD5CField(temp_a0_2, short *, 0xA) = -1;
                                temp_v1_8 = Level13_7FD5CField(privateRecord18, int *, 0x18);
                                Level13_7FD5CField(temp_v1_8, short *, 2) = (short) (Level13_7FD5CField(temp_v1_8, unsigned short *, 0) - 1);
                                temp_v0_3 = Level13_7FD5CField(privateRecord18, int *, 0x18);
                                Level13_7FD5CCall8004F178(privateRecord18 + 8, Level13_7FD5CField(temp_v0_3, int *, 0xC) + (Level13_7FD5CField(temp_v0_3, short *, 2) * 0x10));
                                fieldOrIntermediate3 = Level13_7FD5CField(privateRecord18, int *, 0x5C);
                                resultOrIntermediate2 = privateRecord18 + 0x38;
                                goto block_94;
                            }
                            goto block_91;
                        }
block_91:
                        if ((fieldOrIntermediate3 == -1) && (Level13_7FD5CField(temp_a0_2, short *, 2) == ((short) Level13_7FD5CField(temp_a0_2, unsigned short *, 0) - 1))) {
                            Level13_7FD5CField(temp_a0_2, short *, 0xA) = 1;
                            Level13_7FD5CField(Level13_7FD5CField(privateRecord18, int *, 0x18), short *, 2) = 0;
                            temp_v0_4 = Level13_7FD5CField(privateRecord18, int *, 0x18);
                            Level13_7FD5CCall8004F178(privateRecord18 + 8, Level13_7FD5CField(temp_v0_4, int *, 0xC) + (Level13_7FD5CField(temp_v0_4, short *, 2) * 0x10));
                            fieldOrIntermediate3 = Level13_7FD5CField(privateRecord18, int *, 0x58);
                            __asm__ volatile("":::"$2","memory");resultOrIntermediate2 = privateRecord18 + 0x20;
block_94:
                            Level13_7FD5CField(privateRecord18, int *, 0x1C) = resultOrIntermediate2;
                            Level13_7FD5CField(privateRecord18, int *, 0x14) = 0;
                            Level13_7FD5CField(privateRecord18, int *, 0x54) = fieldOrIntermediate3;
                            Level13_7FD5CField(owner17, unsigned char *, 0x49) = 2U;
                        } else {
                            goto block_95;
                        }
                    } else {
block_95:
                        resultOrIntermediate2=Level13_7FD5CData80071930;__asm__ volatile(""::"r"(resultOrIntermediate2):"$3","memory");fieldOrIntermediate3=0x10000000;
                        if(resultOrIntermediate2!=0){
                            __asm__ volatile("":::"memory");
                            argumentOrField4=Level13_7FD5CData80071930;resultOrIntermediate2=Level13_7FD5CField(argumentOrField4,int*,24);zeroArgument6=0;resultOrIntermediate2|=fieldOrIntermediate3;Level13_7FD5CField(argumentOrField4,int*,24)=resultOrIntermediate2;
                            __asm__ volatile("":::"memory");resultOrIntermediate2=Level13_7FD5CData80071930;argumentOrField4=Level13_7FD5CField(owner17,int*,12);argumentOrField5=Level13_7FD5CField(owner17,int*,16);fieldOrIntermediate3=Level13_7FD5CField(resultOrIntermediate2,int*,12);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,int*,16);argumentOrField4=fieldOrIntermediate3-argumentOrField4;argumentOrField5=resultOrIntermediate2-argumentOrField5;resultOrIntermediate2=Level13_7FD5CCall8004E880(argumentOrField4,argumentOrField5,zeroArgument6);
                            fieldOrIntermediate3=Level13_7FD5CData80071930;Level13_7FD5CField(fieldOrIntermediate3,unsigned char*,81)=resultOrIntermediate2;fieldOrIntermediate3=Level13_7FD5CData80071930;resultOrIntermediate2=Level13_7FD5CField(fieldOrIntermediate3,unsigned char*,81);if(resultOrIntermediate2==0)Level13_7FD5CField(fieldOrIntermediate3,unsigned char*,81)=1;
                        }
                    }
                
        goto actor1064Finish;

        break;
    case 3:                                         
        if (Level13_7FD5CData8006C770 != 0) {
            resultOrIntermediate2=5;Level13_7FD5CKeep(resultOrIntermediate2);fieldOrIntermediate3=Level13_7FD5CField(owner17,unsigned char*,73);
            if(fieldOrIntermediate3==resultOrIntermediate2){
                resultOrIntermediate2=4;
                temp_a0_3 = Level13_7FD5CField(privateRecord18, int *, 0x18);
                if (Level13_7FD5CField(temp_a0_3, short *, 0xA) == 1) {
                    Level13_7FD5CField(temp_a0_3, short *, 0xA) = -1;
                    Level13_7FD5CField(Level13_7FD5CField(privateRecord18, int *, 0x18), short *, 2) = 0;
                } else {
                    Level13_7FD5CField(temp_a0_3, short *, 0xA) = 1;
                    temp_v1_10 = Level13_7FD5CField(privateRecord18, int *, 0x18);
                    Level13_7FD5CField(temp_v1_10, short *, 2) = (short) (Level13_7FD5CField(temp_v1_10, unsigned short *, 0) - 1);
                }
                resultOrIntermediate2 = 6;
            }else resultOrIntermediate2=4;
            Level13_7FD5CField(owner17, unsigned char *, 0x49) = resultOrIntermediate2;__asm__ volatile("":::"$6","memory");
            if (Level13_7FD5CCall8004F264((int) Level13_7FD5CField(owner17, unsigned char *, 0x46), Level13_7FD5CCall8004E880(Level13_7FD5CField(privateRecord18, int *, 8) - Level13_7FD5CField(owner17, int *, 0xC), Level13_7FD5CField(privateRecord18, int *, 0xC) - Level13_7FD5CField(owner17, int *, 0x10), 0)) < 0x40) {
                Level13_7FD5CField(owner17, unsigned char *, 0x48) = 5U;
                Level13_7FD5CCall80034F40(owner17, 5);
            } else {
                goto block_130;
            }
        }
        break;
    case 4:                                         
        if (Level13_7FD5CCall80035194(owner17, privateRecord18 + 0x60) == 0x100) {
            Level13_7FD5CCall80055D24(owner17, 4);
            Level13_7FD5CCall8003BA00(owner17);
            Level13_7FD5CCall800369B8(owner17, 0x20);
            Level13_7FD5CCall80055B18(owner17);
        }
        break;
    case 5:                                         
        temp_v1_11 = Level13_7FD5CField(owner17, unsigned char *, 0x49);
        switch (temp_v1_11) {                       
        case 1:                                     
            resultOrIntermediate2=Level13_7FD5CCall80035A80(owner17, Level13_7FD5CField(privateRecord18, int *, 0x14), 0x200, 0x40, 0x280, 8, 8, 7);zeroArgument6=0;Level13_7FD5CKeep(zeroArgument6);headingDistanceResultOrGlobal16=resultOrIntermediate2;
                ownerCoordinate7=Level13_7FD5CField(owner17,int*,12);argumentOrField4=Level13_7FD5CData8006E020;fieldOrIntermediate3=Level13_7FD5CField(owner17,int*,16);argumentOrField5=Level13_7FD5CData8006E024;argumentOrField4=ownerCoordinate7-argumentOrField4;argumentOrField5=fieldOrIntermediate3-argumentOrField5;resultOrIntermediate2=Level13_7FD5CCall8004E880(argumentOrField4,argumentOrField5,zeroArgument6);
                resultOrIntermediate2=Level13_7FD5CCall8004F264((int)(Level13_7FD5CData8006E040<<16)>>20,resultOrIntermediate2);
                if((resultOrIntermediate2 < 0x1C) && ((unsigned int) (Level13_7FD5CField((int)&Level13_7FD5CData80070328, int *, 0x50) - 7) >= 2U) && (Level13_7FD5CHeader80074414(Level13_7FD5CField(privateRecord18, int *, 0x54), ((int)&Level13_7FD5CData80070328 + 0x50) - 0x50) != 0)) {
                resultOrIntermediate2=Level13_7FD5CField(privateRecord18,int*,80);
                if(resultOrIntermediate2<0)resultOrIntermediate2=2;else resultOrIntermediate2=3;Level13_7FD5CKeep(resultOrIntermediate2);
                Level13_7FD5CField(owner17, unsigned char *, 0x49) = resultOrIntermediate2;
                Level13_7FD5CField(owner17, unsigned char *, 0x48) = 2U;
                __asm__ volatile("":::"$4","$5","memory");Level13_7FD5CAnimationPositive(owner17,2);
            }else{
                if(Level13_7FD5CField(privateRecord18,int*,24)==0)goto block_129;
                if(Level13_7FD5CCall80036220((int)&Level13_7FD5CData80070328,Level13_7FD5CField(privateRecord18,int*,28),0,1024)==0)goto block_129;
                if(Level13_7FD5CField(privateRecord18,int*,0)&1)goto block_129;
                if(Level13_7FD5CField(privateRecord18,int*,80)>=0){if(Level13_7FD5CField(Level13_7FD5CField(privateRecord18,int*,24),short*,10)!=1)goto block_129;}
block_126:
                argumentOrField4=owner17;argumentOrField5=2;Level13_7FD5CField(owner17,unsigned char*,73)=5;resultOrIntermediate2=2;
block_127:
                Level13_7FD5CField(owner17,unsigned char*,72)=resultOrIntermediate2;Level13_7FD5CCall80034F40(argumentOrField4,argumentOrField5);goto actor1064Finish;
block_129:
                resultOrIntermediate2=headingDistanceResultOrGlobal16&1;if(resultOrIntermediate2){
block_130:
                    Level13_7FD5CField(owner17, unsigned char *, 0x48) = 6U;
                    Level13_7FD5CCall80034F40(owner17, 6);
                }
            }
            break;
        case 4:                                     
            Level13_7FD5CHeader800743F0(owner17, Level13_7FD5CCall8004E880(Level13_7FD5CField(privateRecord18, int *, 8) - Level13_7FD5CField(owner17, int *, 0xC), Level13_7FD5CField(privateRecord18, int *, 0xC) - Level13_7FD5CField(owner17, int *, 0x10), 0), 0x40, 0x280, 0x280, 0x27, privateRecord18 + 0x54, 1, 0);
            if(Level13_7FD5CCall8004F334(owner17+12,privateRecord18+8)<512){argumentOrField4=owner17;argumentOrField5=0;goto block_138;}
            goto actor1064Finish;
        case 6:                                     
            if (Level13_7FD5CCall80035A80(owner17, Level13_7FD5CField(privateRecord18, int *, 0x18), 0x200, 0x40, 0x280, 8, 8, 7) & 1) {
                argumentOrField4=Level13_7FD5CField(privateRecord18,int*,24);
                fieldOrIntermediate3=Level13_7FD5CField(argumentOrField4,short*,10);
                if(fieldOrIntermediate3!=1){resultOrIntermediate2=Level13_7FD5CField(argumentOrField4,short*,0);fieldOrIntermediate3=resultOrIntermediate2-1;}else fieldOrIntermediate3=0;
                __asm__ volatile("":::"memory");resultOrIntermediate2=Level13_7FD5CField(privateRecord18,int*,24);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,short*,2);
                if(resultOrIntermediate2!=fieldOrIntermediate3)goto actor1064Finish;
                argumentOrField4=owner17;argumentOrField5=0;
block_138:
                resultOrIntermediate2=1;Level13_7FD5CField(owner17,unsigned char*,73)=resultOrIntermediate2;
block_139:
                Level13_7FD5CField(owner17,unsigned char*,72)=0;Level13_7FD5CCall80034F40(argumentOrField4,argumentOrField5);goto actor1064Finish;
            }
            break;
        }
        break;
    case 6:                                         
        if (Level13_7FD5CData8006C770 != 0) {
            argumentOrField4=5;Level13_7FD5CKeep(argumentOrField4);
            resultOrIntermediate2=Level13_7FD5CField(owner17,unsigned char*,70);fieldOrIntermediate3=Level13_7FD5CField(owner17,short*,54);Level13_7FD5CField(owner17,unsigned char*,72)=argumentOrField4;
            resultOrIntermediate2+=128;fieldOrIntermediate3*=4;Level13_7FD5CField(owner17,unsigned char*,70)=resultOrIntermediate2;
            resultOrIntermediate2=Level13_7FD5CField((int)&Level13_7FD5CData8006EE2C+fieldOrIntermediate3,int*,0);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,int*,80);resultOrIntermediate2=Level13_7FD5CField(resultOrIntermediate2,unsigned char*,0);
            __asm__ volatile(""::"r"(resultOrIntermediate2):"$3");fieldOrIntermediate3=1;Level13_7FD5CKeep(fieldOrIntermediate3);Level13_7FD5CField(owner17,unsigned char*,60)=argumentOrField4;Level13_7FD5CField(owner17,unsigned char*,61)=argumentOrField4;Level13_7FD5CField(owner17,unsigned char*,62)=0;Level13_7FD5CField(owner17,unsigned char*,63)=fieldOrIntermediate3;
            __asm__ volatile("":"=r"(resultOrIntermediate2):"0"(resultOrIntermediate2):"memory");resultOrIntermediate2=-((unsigned int)resultOrIntermediate2>=2U)&48;Level13_7FD5CField(owner17,unsigned char*,64)=resultOrIntermediate2;
        }
        break;
    }
actor1064Finish:
    Level13_7FD5CCall80055D24(owner17, 4);
}
#undef Level13_7FD5CMultiplyComplete
#undef Level13_7FD5CCaptureHigh
#undef Level13_7FD5CField
#undef Level13_7FD5CKeep


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80080DFC.
* Assembly SHA256 c8503353be55c84a2f8bab0b021f8add1f555f077cddb84dacbf012d8c543796.
* AI generated; not human reviewed. All674 original instructions and six
* original selector words/actual targets are required. Frame0x58 retains
* SP0x20/30 vectors,original local extent and S0/S1/S2/S3/S4/RA saves.
* Both original byte streams feed eight rounds of full32-bit shift/XOR
* with masks0x8000/0x8005. Unsigned shifts preserve original word bits;
* no16-bit accumulator truncation is introduced. Stream bounds/cursors,
* main_TEXT_START+2,original callback addresses and40 repeated stores of
* raw0x35E8 stay exact. Original13/39 trig products and shifts5/6 retain
* signed LH inputs,transient zero stores and raw player word+0x44.
* Irregular substate1/0/3 dispatch,conditional kind reloads,original
* no-pending return80081450->80081860 and shared delete/final joins are
* explicit. The movement tail reuses matched actor620 producer order,
* with this original's S1/S2 roles,field0x28 and decrement8. Complete
* V0 return remains live until its original late S0 copy. Every actual
* destination and address is independently checked for this function.
* Empty initialized dependencies and late consumers emit0 instructions.
* No partial HI,FP shortcut or opcode assembly is used. Raw units/fixed
* point,complete helper contracts,caller cadence and synchronized retail
* runtime remain open. Cadence is per invocation; confidence is binary
* identity after all acceptance gates. Falsification: every native/linked
* word and actual transfer/table target,selector/padding byte,full EXE
* and every overlay retail hash must remain identical. */
#define Actor13_80DFCField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
unsigned char Actor13_80DFCCall13D44View1() __asm__("func_80013D44");
int Actor13_80DFCCall1A358View1() __asm__("func_8001A358");
unsigned char Actor13_80DFCCall2803CView1() __asm__("func_8002803C");
unsigned char Actor13_80DFCCall34F40View1() __asm__("func_80034F40");
int Actor13_80DFCCall359A4View1() __asm__("func_800359A4");
int Actor13_80DFCCall35A80View1() __asm__("func_80035A80");
int Actor13_80DFCCall3636CView1() __asm__("func_8003636C");
int Actor13_80DFCCall365E4View1() __asm__("func_800365E4");
int Actor13_80DFCCall37BBCView1() __asm__("func_80037BBC");
unsigned char Actor13_80DFCCall3B634View1() __asm__("func_8003B634");
unsigned char Actor13_80DFCCall3B74CView1() __asm__("func_8003B74C");
unsigned char Actor13_80DFCCall3B7B4View1() __asm__("func_8003B7B4");
unsigned char Actor13_80DFCCall492DCView1() __asm__("func_800492DC");
unsigned char Actor13_80DFCCall4F178View1() __asm__("func_8004F178");
unsigned char Actor13_80DFCCall4F194View1() __asm__("func_8004F194");
int Actor13_80DFCCall4F334View1() __asm__("func_8004F334");
unsigned char Actor13_80DFCCall512E4View1() __asm__("func_800512E4");
unsigned char Actor13_80DFCCall55B18View1() __asm__("func_80055B18");
int Actor13_80DFCCallrandView1() __asm__("rand");
extern unsigned char Actor13_80DFCData658A0View1 __asm__("D_800658A0");
extern unsigned char Actor13_80DFCData65920View1 __asm__("D_80065920");
extern int Actor13_80DFCData676E8View1 __asm__("D_800676E8");
extern int Actor13_80DFCData6C550View1 __asm__("D_8006C550");
extern int Actor13_80DFCData6C58CView1 __asm__("D_8006C58C");
extern int Actor13_80DFCData6C628View1 __asm__("D_8006C628");
extern unsigned char Actor13_80DFCData6C62CView1 __asm__("D_8006C62C");
extern int Actor13_80DFCData6C640View1 __asm__("D_8006C640");
extern int Actor13_80DFCData6C770View1 __asm__("D_8006C770");
extern unsigned char Actor13_80DFCData6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Actor13_80DFCData6C7F8View1 __asm__("D_8006C7F8");
extern unsigned char Actor13_80DFCData6D088View1 __asm__("D_8006D088");
extern int Actor13_80DFCData6E344View1 __asm__("D_8006E344");
extern unsigned char Actor13_80DFCData70300View1 __asm__("D_80070300");
extern unsigned char Actor13_80DFCData70328View1 __asm__("D_80070328");
extern unsigned char Actor13_80DFCData71A04View1 __asm__("D_80071A04");
extern unsigned char Actor13_80DFCData8C5CCView1 __asm__("D_level_13_8008C5CC");
extern unsigned char Actor13_80DFCCall27A60View1 __asm__("func_80027A60");
extern unsigned char Actor13_80DFCCall27EE4View1 __asm__("func_80027EE4");
extern unsigned char Actor13_80DFCCall29AA0View1 __asm__("func_80029AA0");
extern unsigned char Actor13_80DFCCall7507CView1 __asm__("func_level_13_8007507C");
extern unsigned char Actor13_80DFCDatamain_TEXT_ENDView1 __asm__("main_TEXT_END");
extern unsigned char Actor13_80DFCDatamain_TEXT_STARTView1 __asm__("main_TEXT_START");
extern void*(*Actor13_80DFCDataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_13_80080DFC(void *input) {
    register void *ownerRecord18 __asm__("$18");
    register int retainedAddressOrResult16 __asm__("$16"), privateRecord17 __asm__("$17"), vectorAddress19 __asm__("$19"), retainedSignedHalfword20 __asm__("$20");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C;
    }
    originalFrame;
    short temporaryWord3;
    short temporaryWord4;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord15;
    unsigned int temporaryWord11;
    unsigned int temporaryWord12;
    unsigned int temporaryWord13;
    register int temporaryWord6 __asm__("$3");
    unsigned char temporaryWord7;
    unsigned char temporaryWord10;
    int temporaryWord14;
    void *firstPackedSource5;
    void *secondPackedSource5;
    void *temporaryPointer5;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateRecord17 = (int)Actor13_80DFCField(ownerRecord18, void**, 0);
    if (((unsigned int) (Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48) - 2) >= 2U) && (Actor13_80DFCField(ownerRecord18, int *, 0x18) != 0)) {
        Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48) = 3U;
        Actor13_80DFCCall34F40View1(input, 3);
    }
    temporaryWord6 = Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48);
    switch (temporaryWord6) {
    case 0:
    case 1:
        rawWord3 = Actor13_80DFCField(ownerRecord18, unsigned char*, 0x49);
        rawWord2 = 1;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if (rawWord3 == rawWord2) goto runSubstate1;
        if (rawWord3 < 2){
            if (rawWord3 == 0) goto runSubstate0;
            return;
        }
        rawWord2 = 3;
        argumentWord4 = privateRecord17+0x24;
        if (rawWord3 == rawWord2) goto runSubstate3;
        return;
        {
        runSubstate0:
            if ((Actor13_80DFCField(privateRecord17, unsigned char *, 0) != 0) || (!(Actor13_80DFCData6C7B4View1 & 1) && !(*(&Actor13_80DFCData70300View1 + Actor13_80DFCData6C58CView1) & 1))) {
                __asm__ __volatile__("":::"memory");
                rawWord3 = Actor13_80DFCField(privateRecord17, unsigned char*, 0);
                rawWord2 = 1;
                if (rawWord3 == rawWord2) {
                    if (Actor13_80DFCField(&Actor13_80DFCData70328View1, int *, 0x244) != 0) {
                        Actor13_80DFCCall2803CView1(7, 0x82, &Actor13_80DFCCall27EE4View1, &Actor13_80DFCCall27A60View1, &Actor13_80DFCCall29AA0View1, &Actor13_80DFCData6C628View1, 5);
                    }
                }
                rawWord3 = Actor13_80DFCField(privateRecord17, unsigned char*, 0);
                rawWord2 = 4;
                if (rawWord3 == rawWord2) {
                    if ((Actor13_80DFCData6C7B4View1 & 4) || (*(&Actor13_80DFCData70300View1 + Actor13_80DFCData6C58CView1) & 4)) {
                        Actor13_80DFCField(privateRecord17, signed char *, 2) = 1;
                        Actor13_80DFCField(privateRecord17, unsigned char *, 5) = 1U;
                    }
                }
                Actor13_80DFCField(ownerRecord18, unsigned char *, 0x49) = 1U;
                return;
            }
            goto deleteOwner;
        runSubstate1:
            if ((unsigned int) Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) >= (unsigned int) &Actor13_80DFCCall7507CView1) {
                argumentWord5 = 0;
                argumentWord6 = (int)&Actor13_80DFCData8C5CCView1;
            readNextOverlayByte:
                temporaryWord11 = Actor13_80DFCField(privateRecord17, unsigned int *, 0x38);
                if (temporaryWord11 < (unsigned int)argumentWord6) {
                    argumentWord4 = 0;
                    Actor13_80DFCField(privateRecord17, int *, 0x2C) = (int) (Actor13_80DFCField(privateRecord17, int *, 0x2C) ^ (Actor13_80DFCField(temporaryWord11, unsigned char*, 0) << 8));
                    do {
                        rawWord3 = Actor13_80DFCField(privateRecord17, int*, 0x2C);
                        if (rawWord3&0x8000){
                            rawWord2 = ((unsigned int)rawWord3 << 1)^0x8005;
                        }
                        else{
                            rawWord2 = (unsigned int)rawWord3 << 1;
                        }
                        Actor13_80DFCField(privateRecord17, int*, 0x2C) = rawWord2;
                        __asm__ __volatile__(""::"m"(Actor13_80DFCField(privateRecord17, int*, 0x2C)):"memory");
                        argumentWord4 += 1;
                    }
                    while (argumentWord4 < 8);
                    argumentWord5 += 1;
                    Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) = (unsigned int) (Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) + 1);
                    if (argumentWord5 < 0x40) {
                        goto readNextOverlayByte;
                    }
                }
            }
            if (Actor13_80DFCField(privateRecord17, unsigned char *, 0) == 4) {
                if ((Actor13_80DFCData6C62CView1 & 4) && ((retainedAddressOrResult16 = (int)&Actor13_80DFCData71A04View1), Actor13_80DFCField(retainedAddressOrResult16, unsigned char*, 0) == 0) && (Actor13_80DFCData6E344View1 == 0)) {
                    argumentWord4 = (int)&originalFrame.sp20;
                    rawWord2 = Actor13_80DFCField(ownerRecord18, unsigned char*, 0x46);
                    rawWord2 <<= 1;
                    rawWord3 = Actor13_80DFCField(&Actor13_80DFCData65920View1, short*, rawWord2);
                    rawWord2 = (rawWord3*13) >> 5;
                    originalFrame.sp20 = rawWord2;
                    rawWord2 = Actor13_80DFCField(ownerRecord18, unsigned char*, 0x46);
                    argumentWord5 = (int)&originalFrame.sp20;
                    rawWord2 <<= 1;
                    rawWord3 = Actor13_80DFCField(&Actor13_80DFCData658A0View1, short*, rawWord2);
                    rawWord2 = Actor13_80DFCField(&Actor13_80DFCData70328View1, int*, 0x44);
                    argumentWord6 = (int)ownerRecord18+12;
                    originalFrame.sp28 = 0;
                    __asm__ __volatile__(""::"m"(originalFrame.sp28));
                    originalFrame.sp28 = rawWord2;
                    rawWord2 = (rawWord3*13) >> 5;
                    originalFrame.sp24 = rawWord2;
                    Actor13_80DFCCall4F194View1(argumentWord4, argumentWord5, argumentWord6);
                    argumentWord4 = retainedAddressOrResult16;
                    argumentWord5 = 1;
                    argumentWord6 = (int)&Actor13_80DFCData6C7F8View1;
                    __asm__ __volatile__(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6):"$2");
                    rawWord2 = 1;
                    Actor13_80DFCField(argumentWord4, unsigned char*, 0) = rawWord2;
                    Actor13_80DFCCall3B7B4View1(argumentWord4, argumentWord5, argumentWord6);
                    Actor13_80DFCCall3B634View1(&Actor13_80DFCData6D088View1, &originalFrame.sp20, Actor13_80DFCField(ownerRecord18, unsigned char *, 0x46) + 0x80);
                    Actor13_80DFCCall3B74CView1(&Actor13_80DFCData6D088View1);
                }
                else if (Actor13_80DFCData6C7B4View1 & 8) {
                    Actor13_80DFCField(privateRecord17, signed char *, 2) = 3;
                }
            }
            if ((Actor13_80DFCField(privateRecord17, unsigned char *, 0) == 1) && (Actor13_80DFCField(privateRecord17, unsigned char *, 5) != 0xFF) && (Actor13_80DFCData6C628View1 >= 5) && !({rawWord3 = Actor13_80DFCData6C7B4View1;__asm__("":"=r"(rawWord3):"0"(rawWord3));rawWord3&2;})) {
                rawWord2 = rawWord3|2;
                rawWord3 = Actor13_80DFCField(ownerRecord18, int*, 0);
                Actor13_80DFCData6C7B4View1 = rawWord2;
                rawWord2 = 2;
                Actor13_80DFCField(rawWord3, unsigned char*, 5) = rawWord2;
                retainedAddressOrResult16 = (int)&originalFrame.sp30;
                rawWord2 = Actor13_80DFCField(ownerRecord18, unsigned char*, 0x46);
                rawWord2 <<= 1;
                rawWord3 = Actor13_80DFCField(&Actor13_80DFCData65920View1, short*, rawWord2);
                argumentWord4 = retainedAddressOrResult16;
                rawWord2 = (rawWord3*39) >> 6;
                __asm__ __volatile__(""::"r"(argumentWord4));
                originalFrame.sp30 = rawWord2;
                rawWord2 = Actor13_80DFCField(ownerRecord18, unsigned char*, 0x46);
                argumentWord5 = retainedAddressOrResult16;
                rawWord2 <<= 1;
                rawWord3 = Actor13_80DFCField(&Actor13_80DFCData658A0View1, short*, rawWord2);
                rawWord2 = Actor13_80DFCField(&Actor13_80DFCData70328View1, int*, 0x44);
                argumentWord6 = (int)ownerRecord18+12;
                originalFrame.sp38 = 0;
                __asm__ __volatile__(""::"m"(originalFrame.sp38));
                originalFrame.sp38 = rawWord2;
                rawWord2 = (rawWord3*39) >> 6;
                __asm__ __volatile__(""::"r"(argumentWord5), "r"(argumentWord6));
                originalFrame.sp34 = rawWord2;
                Actor13_80DFCCall4F194View1(argumentWord4, argumentWord5, argumentWord6);
                Actor13_80DFCCall13D44View1(&originalFrame.sp30, (Actor13_80DFCField(ownerRecord18, unsigned char *, 0x46) + 0x80) & 0xFF, 0, 0);
                if (Actor13_80DFCField(&Actor13_80DFCData70328View1, int *, 0x280) < 0) {
                    Actor13_80DFCField(&Actor13_80DFCData70328View1, int *, 0x280) = 0;
                }
            }
            if (Actor13_80DFCField(privateRecord17, unsigned char *, 0) == 2) {
                if (!(Actor13_80DFCData6C7B4View1 & 1)) {
                    if (Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) == 0) {
                        Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) = (unsigned int) (Actor13_80DFCData6C58CView1 + (&Actor13_80DFCDatamain_TEXT_STARTView1 + 2));
                    }
                    rawWord2 = Actor13_80DFCField(privateRecord17, unsigned int*, 0x38);
                    rawWord3 = (int)&Actor13_80DFCDatamain_TEXT_ENDView1;
                    __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(rawWord2));
                    argumentWord5 = 0;
                    if ((unsigned int)rawWord2 < (unsigned int)rawWord3) {
                        argumentWord6 = rawWord3;
                    readNextMainByte:
                        temporaryWord12 = Actor13_80DFCField(privateRecord17, unsigned int *, 0x38);
                        argumentWord4 = 0;
                        if (temporaryWord12 < (unsigned int)argumentWord6) {
                            Actor13_80DFCField(privateRecord17, int *, 0x2C) = (int) (Actor13_80DFCField(privateRecord17, int *, 0x2C) ^ (Actor13_80DFCField(temporaryWord12, unsigned char*, 0) << 8));
                            do {
                                rawWord3 = Actor13_80DFCField(privateRecord17, int*, 0x2C);
                                if (rawWord3&0x8000){
                                    rawWord2 = ((unsigned int)rawWord3 << 1)^0x8005;
                                }
                                else{
                                    rawWord2 = (unsigned int)rawWord3 << 1;
                                }
                                Actor13_80DFCField(privateRecord17, int*, 0x2C) = rawWord2;
                                __asm__ __volatile__(""::"m"(Actor13_80DFCField(privateRecord17, int*, 0x2C)):"memory");
                                argumentWord4 += 1;
                            }
                            while (argumentWord4 < 8);
                            argumentWord5 += 1;
                            rawWord2 = Actor13_80DFCField(privateRecord17, int*, 0x2C);
                            rawWord3 = Actor13_80DFCField(privateRecord17, int*, 0x38);
                            rawWord2 = (rawWord2&3)+1;
                            rawWord3 += rawWord2;
                            temporaryWord13 = rawWord3;
                            Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) = temporaryWord13;
                            if (argumentWord5 >= 0x40) {
                                if (temporaryWord13 >= (unsigned int) &Actor13_80DFCDatamain_TEXT_ENDView1) {
                                    goto resetStreamCursor;
                                }
                            }
                            else {
                                goto readNextMainByte;
                            }
                        }
                        else {
                        resetStreamCursor:
                            Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) = (unsigned int) &Actor13_80DFCCall7507CView1;
                        }
                    }
                    goto checkPrimaryHelperResult;
                }
                goto deleteOwner;
            }
        checkPrimaryHelperResult:
            if (Actor13_80DFCCall37BBCView1(ownerRecord18, 0) != 0) {
                if (Actor13_80DFCField(privateRecord17, unsigned char *, 0) == 0) {
                    Actor13_80DFCData6C7B4View1 |= 1;
                }
                Actor13_80DFCCall512E4View1(ownerRecord18, 0, 2);
                Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48) = 2U;
                return;
            }
            if ((Actor13_80DFCField(privateRecord17, unsigned int *, 0x38) == &Actor13_80DFCData8C5CCView1) && (Actor13_80DFCField(privateRecord17, int *, 0x2C) != 0)) {
                rawWord3 = 0;
                argumentWord5 = (int)&Actor13_80DFCData676E8View1;
                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                argumentWord4 = 0x35E8;
                do{
                    rawWord3++;
                    rawWord2 = rawWord3 < 40;
                    Actor13_80DFCField(argumentWord5, int*, 0) = argumentWord4;
                }
                while (rawWord2);
                Actor13_80DFCField(privateRecord17, int *, 0x2C) = 0;
            }
            if (Actor13_80DFCData6C770View1 != 0) {
                if (Actor13_80DFCField(privateRecord17, int *, 0x24) == 0) {
                    Actor13_80DFCCall34F40View1(ownerRecord18, 1);
                    Actor13_80DFCField(privateRecord17, int *, 0x24) = Actor13_80DFCCall3636CView1(3, 6);
                    return;
                }
                Actor13_80DFCCall34F40View1(ownerRecord18, 0);
                Actor13_80DFCField(privateRecord17, int *, 0x24) = (int) (Actor13_80DFCField(privateRecord17, int *, 0x24) - 1);
                return;
            }
            return;
        runSubstate3:
            if (Actor13_80DFCCall359A4View1(argumentWord4, 4) != 0) {
                Actor13_80DFCField(ownerRecord18, unsigned char *, 0x49) = 1U;
                Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48) = 4U;
                Actor13_80DFCCall34F40View1(ownerRecord18, 4);
            }
            goto updateFinalSharedWord;
        }
        break;
    case 2:
        if (Actor13_80DFCData6E344View1 != 1) {
            temporaryWord14 = Actor13_80DFCField(privateRecord17, unsigned char *, 0);
            Actor13_80DFCField(privateRecord17, int *, 0x24) = 3;
            if (temporaryWord14 == 0) {
                Actor13_80DFCField(Actor13_80DFCField(privateRecord17, void **, 0x28), short *, 0xA) = 1;
                Actor13_80DFCField(Actor13_80DFCField(privateRecord17, void **, 0x28), short *, 2) = 0;
                Actor13_80DFCField(privateRecord17, int *, 0x24) = 0x3C;
                Actor13_80DFCField(ownerRecord18, unsigned char *, 0x49) = 3U;
            }
            else if ((temporaryWord14 == 1) && (Actor13_80DFCField(privateRecord17, unsigned char *, 4) == 4)) {
                Actor13_80DFCField(privateRecord17, unsigned char *, 5) = 0xFFU;
            }
            Actor13_80DFCField(ownerRecord18, int *, 0x18) = 0;
            Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48) = 0U;
            return;
        }
        break;
    case 3:
        if (Actor13_80DFCData6C770View1 != 0) {
            Actor13_80DFCField(ownerRecord18, int *, 0x18) = 0;
            Actor13_80DFCField(ownerRecord18, unsigned char *, 0x48) = 0U;
            Actor13_80DFCCall34F40View1(ownerRecord18, 0);
            return;
        }
        if ((Actor13_80DFCField(ownerRecord18, int *, 0x18) & 0x10000) && (Actor13_80DFCData6C640View1 & 1)) {
            originalFrame.sp20 = (Actor13_80DFCCallrandView1() & 0xF) - 8;
            originalFrame.sp24 = (Actor13_80DFCCallrandView1() & 0xF) - 8;
            originalFrame.sp28 = (Actor13_80DFCCallrandView1() & 0xF) + 8;
            temporaryPointer5 = Actor13_80DFCDataSpawnParticleView1(1, 0x37, ownerRecord18 + 0xC, &originalFrame.sp20);
            if (temporaryPointer5 != 0) {
                Actor13_80DFCField(temporaryPointer5, unsigned short *, 8) = (unsigned short) (Actor13_80DFCField(temporaryPointer5, unsigned short *, 8) + (Actor13_80DFCCallrandView1() & 0xFF));
                return;
            }
        }
        break;
    case 4:
        temporaryWord15 = Actor13_80DFCField(privateRecord17, int *, 0x34);
        retainedSignedHalfword20 = Actor13_80DFCField(Actor13_80DFCField(privateRecord17, void **, 0x28), short *, 2);
        if ((temporaryWord15 >= 0) && (Actor13_80DFCCall4F334View1(ownerRecord18 + 0xC, Actor13_80DFCData6C550View1 + (temporaryWord15 * 0x58) + 0xC) < 0x200)) {
            Actor13_80DFCDataSpawnParticleView1(2, 0xC, Actor13_80DFCData6C550View1 + (Actor13_80DFCField(privateRecord17, int *, 0x34) * 0x58), (int *)5);
        }
        temporaryWord7 = Actor13_80DFCField(ownerRecord18, unsigned char *, 0x49);
        switch (temporaryWord7) {
        case 1:
            if (Actor13_80DFCCall35A80View1(ownerRecord18, Actor13_80DFCField(privateRecord17, void **, 0x28), 0x200, 0x80, 0, 8, 0xC, 5) & 1) {
                firstPackedSource5 = Actor13_80DFCField(privateRecord17, void **, 0x28);
                temporaryWord3 = Actor13_80DFCField(firstPackedSource5, short *, 2);
                if (temporaryWord3 != 0) {
                    temporaryWord8 = Actor13_80DFCField(firstPackedSource5, int *, 0xC);
                    if (((rawWord2 = retainedSignedHalfword20 << 4), (rawWord2 += temporaryWord8), (rawWord2 = Actor13_80DFCField(rawWord2, int*, 0xC)), (rawWord2&1))) {
                        Actor13_80DFCField(privateRecord17, int *, 0x30) = Actor13_80DFCCall365E4View1(ownerRecord18 + 0xC, temporaryWord8 + (temporaryWord3 * 0x10), 0x80, -8, 0);
                        Actor13_80DFCField(ownerRecord18, unsigned char *, 0x49) = 2U;
                    }
                    goto updateFinalSharedWord;
                }
                goto deleteOwner;
            }
            goto updateFinalSharedWord;
        case 2:
            rawWord2 = Actor13_80DFCCall35A80View1(ownerRecord18, Actor13_80DFCField(privateRecord17, void**, 0x28), 0x200, 0x80, 0, 8, 0xC, 0);
            argumentWord4 = (int)&originalFrame.sp20;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            vectorAddress19 = (int)ownerRecord18+12;
            __asm__("":"=r"(vectorAddress19):"0"(vectorAddress19));
            argumentWord6 = Actor13_80DFCField(privateRecord17, int*, 0x30);
            argumentWord5 = vectorAddress19;
            argumentWord6 -= 8;
            Actor13_80DFCField(privateRecord17, int*, 0x30) = argumentWord6;
            rawWord3 = Actor13_80DFCField(ownerRecord18, int*, 0x14);
            retainedAddressOrResult16 = rawWord2;
            rawWord3 += argumentWord6;
            Actor13_80DFCField(ownerRecord18, int*, 0x14) = rawWord3;
            Actor13_80DFCCall4F178View1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord4 = (int)&originalFrame.sp20;
            rawWord2 = originalFrame.sp28;
            rawWord2 += 512;
            originalFrame.sp28 = rawWord2;
            if (Actor13_80DFCCall1A358View1(argumentWord4, 512)){
                Actor13_80DFCField(ownerRecord18, unsigned char*, 0x49) = 1;
            }
            rawWord2 = retainedAddressOrResult16&1;
            if (rawWord2) {
                secondPackedSource5 = Actor13_80DFCField(privateRecord17, void **, 0x28);
                temporaryWord4 = Actor13_80DFCField(secondPackedSource5, short *, 2);
                if (temporaryWord4 == 0){
                    deleteOwner:Actor13_80DFCCall55B18View1(ownerRecord18);
                    return;
                }
                temporaryWord9 = Actor13_80DFCField(secondPackedSource5, int *, 0xC);
                if (((rawWord2 = retainedSignedHalfword20 << 4), (rawWord2 += temporaryWord9), (rawWord2 = Actor13_80DFCField(rawWord2, int*, 0xC)), (rawWord2&1))) {
                    Actor13_80DFCField(privateRecord17, int *, 0x30) = Actor13_80DFCCall365E4View1(vectorAddress19, temporaryWord9 + (temporaryWord4 * 0x10), 0x80, -8, 0);
                }
                goto updateFinalSharedWord;
            }
            goto updateFinalSharedWord;
            default:goto updateFinalSharedWord;
        }
        updateFinalSharedWord:Actor13_80DFCField(&Actor13_80DFCData70328View1, int*, 0x20C) = 0x10000002;
        Actor13_80DFCCall492DCView1(ownerRecord18+0xC);
        break;
    case 5:
        Actor13_80DFCField(ownerRecord18, int *, 8) = 0;
        break;
        default:return;
    }
}
#undef Actor13_80DFCField


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 80081884:277 instructions and six dispatch words, original4652.
 * Existing verified helper shapes reused. Raw state/field domains only;
 * units, helper contracts, update cadence and runtime parity unresolved.
 * Uninstalled until every native word and full retail hashes match. */
#define A13Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern void* A13Active __asm__("D_8006E164");
extern int A13Type __asm__("D_8006E160");
extern unsigned char* A13Pool __asm__("D_8006C550");
extern unsigned char A13Player[] __asm__("D_80070328");
extern int A13Contact __asm__("D_8006C770");
int A13Helper36A68() __asm__("func_80036A68");
int A13Helper38F14() __asm__("func_80038F14");
int A13Helper36220() __asm__("func_80036220");
int A13Helper359A4() __asm__("func_800359A4");
int A13Helper34F40() __asm__("func_80034F40");
int A13Helper55E84() __asm__("func_80055E84");
int A13Helper3585C() __asm__("func_8003585C");
int A13Helper35A80() __asm__("func_80035A80");
int A13Helper35194() __asm__("func_80035194");
int A13Helper55D24() __asm__("func_80055D24");
int A13Helper3BA00() __asm__("func_8003BA00");
int A13Helper369B8() __asm__("func_800369B8");
int A13Helper55B18() __asm__("func_80055B18");
extern void* (*A13SpawnMoby)(int,void*) __asm__("SpawnMoby");
int A13H3573C() __asm__("func_8003573C");
int A13H4F334() __asm__("func_8004F334");
int A13H38BF8() __asm__("func_80038BF8");
int A13H368A4() __asm__("func_800368A4");
void func_level_13_80081884(void* input){
 register unsigned char* owner __asm__("$16")=input;
 register unsigned char* tag __asm__("$17");
 register unsigned char* player __asm__("$18");
 register int value __asm__("$2");
 register int other __asm__("$3")=5;
 register void* call4 __asm__("$4");
 register void* call5 __asm__("$5");
 __asm__("" : "=r"(owner):"0"(owner));
 value=owner[72];tag=A13Field(owner,unsigned char**,0);
 if(value!=other && (A13Field(owner,int*,24)&0x10020000)){
  A13Helper36A68(input,0,0,0);A13H38BF8(owner,tag+36,1,5);
  A13Field(owner,int*,8)=0;A13Field(tag,short*,46)=320;
 }
 A13Field(tag,int*,0)=A13H368A4(owner,A13Field(tag,int*,0),2);
 other=owner[72];A13Field(owner,int*,24)=0;
 switch(other){
 case 0:
  A13H3573C(owner,8,0,1);player=A13Player;
  if(A13H4F334(owner+12,player)<4096)goto enter1;
  if(!A13Field(tag,int*,4))goto done;
  other=A13Field(tag,int*,32);
  if(other>=0){
   other=(A13Pool+other*88)[72];
   if(other&128)goto enter2;
   __asm__("" : "=r"(other):"0"(other));if((unsigned char)other!=4)goto done;
  }else if(!A13Helper36220(player,tag+8,0,0))goto done;
 enter2:
  owner[72]=2;A13Helper34F40(owner,2);break;
 case 1:
  A13H3573C(owner,8,0,1);
  if(A13H4F334(owner+12,A13Player)<2048){
   value=A13Field(owner,int*,20)-A13Field(owner,short*,56)-A13Field(A13Player,int*,8)+A13Field(A13Player,int*,68);
   if(value<0)value=-value;
   call4=owner;if(value<1024)goto enter3;
  }
  if(A13H4F334(owner+12,A13Player)<5121)goto done;
  owner[72]=0;goto enter0_ready;
 case 2:
  if(!(A13Helper35A80(owner,A13Field(tag,void**,4),512,128,320,8,16,7)&1))goto done;
  if(A13Field(A13Field(tag,void**,4),short*,2))goto done;
  A13Field(tag,int*,4)=0;owner[72]=0;A13Helper34F40(owner,0);break;
 case 3:
  A13H3573C(owner,8,0,1);call5=A13Player+80;
  if((unsigned int)(A13Field(call5,int*,0)-7)<2)owner[73]=1;
  if(!A13Contact)goto done;
  if(owner[73]){owner[72]=4;A13Helper34F40(owner,4);break;}
  if(A13H4F334(owner+12,(unsigned char*)call5-80)<2048){
   value=A13Field(owner,int*,20)-A13Field(owner,short*,56)-A13Field(A13Player,int*,8)+A13Field(A13Player,int*,68);
   if(value<0)value=-value;
   call4=owner;
   if(value<1024){
 enter3:
    owner[73]=0;owner[72]=3;A13Helper34F40(call4,3);goto done;
   }
  }
  if(A13H4F334(owner+12,A13Player)<4096){
 enter1:
   owner[72]=1;A13Helper34F40(owner,1);goto done;
  }
  goto enter0;
 case 4:
  A13H3573C(owner,8,0,1);if(!A13Contact)goto done;
 enter0:
  owner[72]=0;
 enter0_ready:
  A13Helper34F40(owner,0);break;
 case 5:
  if(A13Helper35194(owner,tag+36)!=256)goto done;
  A13Helper55D24(owner,4);A13Helper3BA00(owner);A13Helper369B8(owner,24);A13Helper55B18(owner);break;
 }
 done:
 other=owner[72];call4=owner;if(other!=5)A13Helper55D24(call4,5);
}
#undef A13Field


extern unsigned char D_8006C7B4, D_80070300[];
extern int D_8006C58C;
void func_level_13_80081CD8(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
    case 0:
        if ((D_8006C7B4 & 1) || (D_80070300[D_8006C58C] & 1)) {
            moby->state = 1;
            *(int*)&moby->colour = moby->position.z;
            moby->colour.a = 0x80;
        }
        break;
    case 1:
        tag[0] += 0x20;
        moby->position.z -= 0x20;
        func_80055D24(moby, 2);
        if (tag[0] >= 0x1000) func_80055B18(moby);
        break;
    }
}

/* This caller only reads the signed halfword at tag +0xC. */
typedef struct { unsigned char reserved00[0xC]; short unkC; } DecodedCloneTag;
extern int D_8006C578, D_8006C574;
void func_level_13_80081DBC(Moby* moby) {
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

typedef struct { Vector3D vector; int timer; } DecodedTimedVectorRecord;
extern short D_80065920[];
void func_80055B18(Moby*);
void func_8004EF04(Vector3D*, int);
void func_level_13_80081E94(Moby* moby) {
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

int func_8004EDE8(Vector3D*,int);
void func_8004F1C8(Vector3D*,Vector3D*,Vector3D*);
void func_8004ED6C(SHORTMATRIX*,Vector3D*,Vector3D*);
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level_12/moby/func_level_12_8008243C.s,
 * level_13/moby/func_level_13_80081F50.s,
 * level_26/moby/func_level_26_8007B99C.s; all251 instructions read per copy.
 * Three tag words+0/+4/+8; signed remainder retains original division traps.
 * Original halfword table samples shift three in initialization, seven after
 * multiplication by three for particle components. Clamp is64; local bounds
 * retain the original multiply/shift and strict comparisons. Stack components
 * preserve their original 16-byte spacing. Units and fixed-point interpretation,
 * table/helper producers and caller cadence remain unresolved. Once per call.
 * Existing names do not establish semantics. Confidence: exact compiled words.
 * Falsifiable vectors: every original linked word and all complete retail hashes.
 * Empty constraints preserve original register lifetimes without opcode patches.
 */
typedef struct { int phaseOffset, firstSpan, secondSpan; } Controller8243CTag;
extern short RawPulseCos[] __asm__("D_80065920");
extern short RawPulseSin[] __asm__("D_800658A0");
extern int RawPulseTick __asm__("D_8006C644");
extern int RawPulsePlayerFlags __asm__("D_8007034C");
extern int RawPulsePlayerHeading __asm__("D_800705C0");
extern Vector3D RawPulsePlayer __asm__("D_80070328");
extern Vector3D RawPulseCollision __asm__("D_80071900");
extern Vector3D RawPulseNormal __asm__("D_80071918");
extern int RawPulseNormalY __asm__("D_8007191C");
extern int RawPulseNormalZ __asm__("D_80071920");
int RawPulseTrace(Vector3D*,Vector3D*) __asm__("func_80018368");
void RawPulsePosition(Moby*,int,Vector3D*) __asm__("func_80055F14");
void RawPulseTurn(Moby*,int) __asm__("func_80055D24");
void RawPulseCopyMatrix(SHORTMATRIX*,SHORTMATRIX*) __asm__("func_8004ECF4");
void func_level_13_80081F50(Moby* input) {
    register Moby* owner __asm__("$18") = input;
    Vector3D origin; int reserved1C;
    Vector3D target; int reserved2C;
    Vector3D particle; int reserved3C;
    Vector3D offset; int reserved4C;
    SHORTMATRIX matrix;
    register Controller8243CTag* tag __asm__("$19");
    register int phase __asm__("$16");
    register int lower __asm__("$19");
    register int upper __asm__("$20");
    register Vector3D* position __asm__("$17");
    register Vector3D* scratch __asm__("$16");
    int value;
    { register int first __asm__("$2");
      register int state __asm__("$3");
      register Vector3D* initializeArgument __asm__("$4");
      __asm__("" : : "r"(owner) : "$2");
      first=1;
      state=owner->state;
      tag=owner->mobyTag;
      __asm__("" : "=r"(first),"=r"(state) : "0"(first),"1"(state),"r"(owner),"r"(tag) : "$4");
      if(state==first)goto sharedPhase;
      if(state<2){initializeArgument=&origin;if(state==0)goto initialize;goto sharedPhase;}
      if(state==2)goto emitParticle;
      goto sharedPhase;
initialize:
      __asm__("" : : : "$3");

        { register Vector3D* prepared __asm__("$4")=initializeArgument;
            register Vector3D* preparedPosition __asm__("$5");
            register Vector3D* preparedDirection __asm__("$6");
            register int sample __asm__("$2");
            __asm__("" : "=r"(prepared) : "0"(prepared) : "$17", "$16", "$5", "$6");
            sample=owner->angle.yaw;
            __asm__("" : "=r"(sample) : "0"(sample) : "$17");
            position=&owner->position;
            __asm__("" : : : "$5");
            sample=D_80065920[sample];
            __asm__("" : "=r"(sample), "=r"(position) : "0"(sample), "1"(position) : "$16", "$6", "$5");
            preparedPosition=position;
            target.x=sample>>3;
            sample=owner->angle.yaw;
            __asm__("" : "=r"(sample) : "0"(sample) : "$16");
            scratch=&target;
            __asm__("" : : : "$6");
            sample=D_800658A0[sample];
            __asm__("" : "=r"(sample), "=r"(scratch) : "0"(sample), "1"(scratch) : "$6");
            preparedDirection=scratch;
            target.z=0;
            __asm__ volatile("" : : : "memory");
            target.y=sample>>3;
            func_8004F194(prepared,preparedPosition,preparedDirection);
        }
        func_8004F1C8(scratch,position,scratch);
        { register int hit __asm__("$2")=func_80018368(&origin,scratch);
            register Vector3D* destination __asm__("$4");
            __asm__("" : "=r"(hit),"=r"(position) : "0"(hit),"1"(position) : "$4");
            destination=position;
            if(hit) {
                __asm__("" : : : "$2");
                scratch=&RawPulseCollision;
                __asm__("" : "=r"(scratch) : "0"(scratch));
                func_8004F178(destination,scratch);
                owner->angle.yaw=func_8004E880(*(int*)((char*)scratch+24),RawPulseNormalY,0);
                scratch=(Vector3D*)((char*)scratch+24);
                __asm__("" : "=r"(scratch) : "0"(scratch));
                value=func_8004EDE8(scratch,0);
                owner->angle.pitch=func_8004E880(value,RawPulseNormalZ,0);
                func_80055D24(owner,4);
            }
        }
        owner->state = 1;
        goto sharedPhase;
emitParticle:;
        { register Moby* prepared __asm__("$4")=owner;
          register int zero __asm__("$5");
          __asm__("" : "=r"(prepared) : "0"(prepared) : "$5");
          zero=0;
          __asm__("" : "=r"(prepared),"=r"(zero) : "0"(prepared),"1"(zero) : "$16");
          scratch=&particle;
          RawPulsePosition(prepared,zero,scratch); }
        offset.x = (*(short*)((char*)RawPulseCos+owner->angle.yaw*2)*3) >> 7;
        offset.y = (*(short*)((char*)RawPulseSin+owner->angle.yaw*2)*3) >> 7;
        offset.z = 0;
        { register int noise __asm__("$2") = rand(); register int component __asm__("$3") = offset.x; __asm__("" : "=r"(noise) : "0"(noise),"r"(component)); component -= 7; __asm__("" : "=r"(component) : "0"(component)); offset.x = component+(noise&14); }
        { register int noise __asm__("$2") = rand(); register int component __asm__("$3") = offset.y; __asm__("" : "=r"(noise) : "0"(noise),"r"(component)); component -= 7; __asm__("" : "=r"(component) : "0"(component)); offset.y = component+(noise&14); }
        { register int noise __asm__("$2")=rand();
          register int type __asm__("$4")=1;
          register int selector __asm__("$5")=19;
          register Vector3D* particlePosition __asm__("$6")=scratch;
          register int component __asm__("$3");
          __asm__("" : : "r"(type),"r"(selector),"r"(particlePosition) : "$3");
          component=*(volatile int*)&offset.z;
          __asm__ volatile("" : "=r"(noise) : "0"(noise),"m"(offset.z));
          noise &=14;
          component-=7;
          component+=noise;
          __asm__("" : "=r"(component) : "0"(component) : "$7");
          offset.z=component;
          SpawnParticle(type,selector,particlePosition,&offset); }
    }
sharedPhase:
    { register int numerator __asm__("$3")=RawPulseTick;
      register int start __asm__("$5")=tag->phaseOffset;
      register int active __asm__("$4")=tag->firstSpan;
      register int inactive __asm__("$2")=tag->secondSpan;
      int denominator;
      __asm__("" : "=r"(numerator),"=r"(start),"=r"(active) : "0"(numerator),"1"(start),"2"(active),"r"(inactive));
      numerator+=start;
      denominator=active+inactive;
      phase=numerator%denominator;
      active=phase<active;
      __asm__("" : "=r"(active) : "0"(active));
    if (active) {
        if (owner->state != 2) func_8003BABC(owner,0,0);
        owner->state = 2;
    } else owner->state = 1; }
    if (tag->secondSpan == 0) { upper = 3072; lower = 0; }
    else if (owner->state == 2) {
        register int scaled __asm__("$2");
        if(phase>64){phase=64; __asm__("" : "=r"(phase) : "0"(phase));}
        scaled=phase*2;
        scaled=(scaled+phase)<<5;
        __asm__("" : "=r"(scaled) : "0"(scaled));
        upper=scaled>>1;
        lower = 0;
    } else {
        register int active __asm__("$2")=tag->firstSpan;
        register int scaled __asm__("$3")=(active*3)<<5;
        __asm__("" : "=r"(scaled),"=r"(active) : "0"(scaled),"1"(active));
        upper=scaled>>1;
        active=phase-active;
        scaled=(active*3)<<5;
        __asm__("" : "=r"(scaled) : "0"(scaled));
        lower=scaled>>1;
    }
    if (lower < upper) {
        func_8004F1C8(&offset,&RawPulsePlayer,&owner->position);
        RawPulseCopyMatrix(&matrix,&owner->rotationMatrix);
        func_8004ED6C(&matrix,&offset,&offset);
        { register int x __asm__("$3")=offset.x;
          register int inside __asm__("$2");
          inside=lower<x;
          __asm__("" : "=r"(inside),"=r"(x) : "0"(inside),"1"(x));
          if(!inside)goto done;
          inside=x<upper;
          __asm__("" : "=r"(inside) : "0"(inside));
          if(!inside)goto done; }
        if (ABS(offset.y)<512 && ABS(offset.z)<512) {
            RawPulsePlayerFlags |= 14;
            RawPulsePlayerHeading = owner->angle.yaw;
        }
    }
done:;
}

extern short D_80065920[], D_800658A0[];
int rand(void);
void DecodedEightParticleDamage(Moby*,int,int,int) __asm__("func_80036A68");
Moby* DecodedEightParticleFragments(int,int,Moby*,int,int,int,int) __asm__("func_800391E8");
void DecodedEightParticleFinish(Moby*) __asm__("func_80039714");
void func_level_13_8008233C(Moby* moby) {
    Vector3D position, velocity;
    int index, heading;
    register int elevation __asm__("$2");
    register int component __asm__("$3");
    register int radius __asm__("$4");
    short* cosine;
    short* sine;
    switch (moby->state) {
    case 0:
        if (moby->damageFlags) {
            DecodedEightParticleDamage(moby, 0, 0, 0);
            moby->state = 1;
        }
        break;
    case 1:
        index = 0;
        if (moby->damageFlags & 0x10000) {
            cosine = D_80065920;
            sine = D_800658A0;
            do {
                heading = rand() & 0xFF;
                elevation = rand() & 0xFF;
                __asm__("" : "=r"(elevation) : "0"(elevation));
                component = cosine[heading];
                radius = cosine[elevation];
                __asm__("" : "=r"(component), "=r"(radius) : "0"(component), "1"(radius));
                velocity.x = ((component >> 8) * radius) >> 12;
                component = sine[heading];
                radius = cosine[elevation];
                __asm__("" : "=r"(component), "=r"(radius) : "0"(component), "1"(radius));
                velocity.y = ((component >> 8) * radius) >> 12;
                elevation = sine[elevation];
                __asm__("" : "=r"(elevation) : "0"(elevation) : "4");
                velocity.z = elevation >> 8;
                func_8004F178(&position, &velocity);
                func_8004F0E8(&position, 2);
                func_8004F194(&position, &position, &moby->position);
                position.z += 0x80;
                SpawnParticle(1, 0x37, &position, &velocity);
                index++;
            } while (index < 8);
        }
        DecodedEightParticleFragments(5, moby->mobyClass, moby, 1, 1, 0x30, 0);
        func_80055B18(moby);
        break;
    case 2:
        DecodedEightParticleFinish(moby);
        break;
    }
}

extern unsigned char D_80066FCC[], D_80070300[];
void func_80021ED8(void*, int, int);
void func_80055B18(Moby*);
void func_level_13_80082524(Moby* moby) {
    int* tag = moby->mobyTag;
    if (D_80070300[D_80066FCC[tag[0]]] & 1) {
        func_80021ED8((void*)tag[1], 0xFC, 0);
    }
    func_80055B18(moby);
}

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
void func_level_13_80082590(Moby* argument) {
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
void func_level_13_800829C8(Moby* moby) {
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
        if(func_800359A4(&tag->timer, 4))moby->state=3;
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

int func_80036220(Vector3D*, char*, int, int);
void func_level_13_80082CF8(Moby* moby) {
    int* surfaceTicks = &spyro.ticksSinceLastSurfaceTouch;
    char* bounds = moby->mobyTag;
    if (*surfaceTicks && func_80036220((Vector3D*)((char*)surfaceTicks - 0xB8), bounds, 0, 0)) {
        spyro.unk17a = 0x10000082;
        spyro.unk20[1] = 7;
    }
}

extern unsigned char D_8006C7B4, D_80070300[];
extern int D_8006C58C, D_8006C648;
void func_level_13_80082D54(Moby* moby) {
    int* tag = moby->mobyTag;
    if ((D_8006C7B4 & 4) || (D_80070300[D_8006C58C] & 4)) {
        int before = *tag / 10;
        int after;
        *tag += D_8006C648;
        after = *tag / 10;
        if (after != before) {
            func_80021ED8((void*)(before + 30), 0xFC, 0);
            if (after >= 3) func_80055B18(moby);
        }
    } else func_80055B18(moby);
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
void func_level_13_80082E2C(void *input) {
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


extern void func_80039714(Moby*);

/**
 * MobyUpdate_501() - func_level_13_80083F80()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_13_80083F80(Moby* moby) {
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
void func_level_13_80083FA0(Moby* argument) {
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
