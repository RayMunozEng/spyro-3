#include "common.h"
#include "spu.h"
#include "savepoint.h"
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
void func_level_22_8007574C(void *input) {
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
void func_level_22_800763A8(Moby* argument) {
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
void func_level_22_80076A34(void *input) {
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
void func_level_22_80077F84(Moby* moby) {
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
void func_level_22_800780C0(Moby* moby) {
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
void func_level_22_80078380(Moby* argument) {
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

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Three originals contain the same 404 instructions and no owned rodata.
 * Preserve the 0x98-byte frame, byte offsets, signed word arithmetic,
 * helper order, post-callback rereads, and phase boundaries 60/180/181.
 * Named stack vectors describe word layout, not verified physical units.
 * Empty compiler constraints emit no opcodes; they preserve original
 * argument producers and saved-register lifetimes. Full helper semantics,
 * vector units, caller cadence and synchronized retail runtime parity
 * remain unresolved. Verify all linked words and every retail binary hash.
 */
#define Actor783B0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor783B0func_8001A358() __asm__("func_8001A358");
int Actor783B0func_8003BABC() __asm__("func_8003BABC");
int Actor783B0func_8003BE70() __asm__("func_8003BE70");
int Actor783B0func_8003BFC0() __asm__("func_8003BFC0");
int Actor783B0func_8003C014() __asm__("func_8003C014");
int Actor783B0func_8004E880() __asm__("func_8004E880");
int Actor783B0func_8004ED6C() __asm__("func_8004ED6C");
int Actor783B0func_8004F0E8() __asm__("func_8004F0E8");
int Actor783B0func_8004F168() __asm__("func_8004F168");
int Actor783B0func_8004F178() __asm__("func_8004F178");
int Actor783B0func_8004F194() __asm__("func_8004F194");
int Actor783B0func_8004F1C8() __asm__("func_8004F1C8");
int Actor783B0func_80050844() __asm__("func_80050844");
int Actor783B0func_800509E8() __asm__("func_800509E8");
int Actor783B0func_80055B18() __asm__("func_80055B18");
int Actor783B0func_80055D24() __asm__("func_80055D24");
int Actor783B0func_8005629C() __asm__("func_8005629C");
extern int Actor783B0D_8006C550 __asm__("D_8006C550");
extern int Actor783B0D_8006C640 __asm__("D_8006C640");
extern int Actor783B0D_8006C648 __asm__("D_8006C648");
extern int (*Actor783B0SpawnParticle)() __asm__("SpawnParticle");
extern int (*Actor783B0unk_ovlheader_800743EC)() __asm__("unk_ovlheader_800743EC");
int Actor783B0rand() __asm__("rand");
void func_level_22_800788A0(unsigned char *owner) {
    struct {
        int referenceDelta[3]; int reserved24;
        int emissionPosition[3]; int reserved34;
        int emissionVelocity[3]; int reserved44;
        int burstPosition[3]; int reserved54;
        int burstVelocity[3]; int reserved64;
        int clearedVector[3]; int reserved74;
    } frame;

    int *ownerVector;
    register int work2 __asm__("2");
    register int work3 __asm__("3");
    register int arg4 __asm__("4");
    register int arg5 __asm__("5");
    register void *arg6 __asm__("6");
    register void *arg7 __asm__("7");
    register void *matrix4 __asm__("4");
    register void *matrix5 __asm__("5");
    int handle;
    int referenceWord0C;
    int nextPhase;
    int linkedIndex;
    int phase;
    int phaseAfterCallbacks;
    int linkedIndexAfterHeader;
    int particleCount;
    unsigned char stateByte49;
    void *firstMatrix;
    register void *secondMatrixOrVelocity __asm__("16");
    register void *emissionPosition __asm__("17");
    void *stateVector;
    unsigned char *state;
    void *linkedActor;

    state = Actor783B0Field(owner, void **, 0);
    if (Actor783B0Field(state, int *, 0x1C) == 1) {
        referenceWord0C = Actor783B0Field(Actor783B0Field(state, void **, 4), int *, 0xC);
        Actor783B0func_8004F1C8(&frame.referenceDelta[0], referenceWord0C + 0x10, referenceWord0C);
        Actor783B0Field(owner, unsigned char *, 0x45) = 0x20U;
        Actor783B0Field(owner, signed char *, 0x46) = (signed char) (Actor783B0func_8004E880(frame.referenceDelta[0], frame.referenceDelta[1], 0) - 0x80);
        Actor783B0Field(owner, int *, 0x14) = (int) (Actor783B0Field(owner, int *, 0x14) + 0x40);
        Actor783B0func_80055D24(owner, 4);
        Actor783B0Field(state, int *, 0x1C) = 2;
    }
    stateByte49 = Actor783B0Field(owner, unsigned char *, 0x49);
    switch (stateByte49) {                             
    case 0:
        linkedIndex = Actor783B0Field(state, int *, 0);
        if ((linkedIndex >= 0) && ((unsigned char) Actor783B0Field(((linkedIndex * 0x58) + Actor783B0D_8006C550), unsigned char *, 0x48) >= 0x80U)) {
            Actor783B0func_80055B18(owner);
        }
        if (Actor783B0Field(owner, int *, 0x18) & 0x10000) {
            Actor783B0Field(owner, unsigned char *, 0x49) = 1U;
            Actor783B0Field(owner, unsigned char *, 0x4A) = 0xFF;
            Actor783B0Field(owner, signed char *, 0x4C) = 0x3C;
            return;
        }
        return;
    case 1:
        if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int *, 0x20)) == 0) {
            Actor783B0Field(state, int *, 0x20) = Actor783B0func_8003BABC(owner, 1, 4);
        }
        phase = Actor783B0Field(state, int *, 0x18) + Actor783B0D_8006C648;
        Actor783B0Field(state, int *, 0x18) = phase;
        if (phase < 0x3C) {
            firstMatrix = owner + 0x20;
            frame.emissionPosition[0] = 0x40;
            frame.emissionPosition[1] = -0xF0;
            frame.emissionPosition[2] = 0x20;
            Actor783B0func_8004ED6C(firstMatrix, &frame.emissionPosition[0], &frame.emissionPosition[0]);
            Actor783B0func_8004F194(&frame.emissionPosition[0], &frame.emissionPosition[0], owner + 0xC);
            frame.emissionVelocity[1] = 6;
            frame.emissionVelocity[0] = 0;
            frame.emissionVelocity[2] = -0xC;
            Actor783B0func_8004ED6C(firstMatrix, &frame.emissionVelocity[0], &frame.emissionVelocity[0]);
            work2 = Actor783B0rand();
            work3 = frame.emissionVelocity[0];
            work2 &= 15; work3 -= 8;
            asm("" : "=r"(work2), "=r"(work3) : "0"(work2), "1"(work3));
            work3 += work2;
            frame.emissionVelocity[0] = work3;
            work2 = Actor783B0rand();
            arg4 = 1; arg5 = 74; arg6 = &frame.emissionPosition[0]; arg7 = &frame.emissionVelocity[0];
            asm("" : "=r"(arg4), "=r"(arg5), "=r"(arg6), "=r"(arg7) : "0"(arg4), "1"(arg5), "2"(arg6), "3"(arg7), "r"(work2));
            work3 = frame.emissionVelocity[1];
            work2 &= 15; work3 -= 8;
            asm("" : "=r"(work2), "=r"(work3) : "0"(work2), "1"(work3));
            work3 += work2;
            frame.emissionVelocity[1] = work3;
            Actor783B0SpawnParticle(arg4, arg5, arg6, arg7);
            return;
        }
        if (phase < 0xB4) {
            if (Actor783B0D_8006C640 & 1) {
                emissionPosition = &frame.emissionPosition[0];
                secondMatrixOrVelocity = owner + 0x20;
                asm("" : "=r"(emissionPosition), "=r"(secondMatrixOrVelocity) : "0"(emissionPosition), "1"(secondMatrixOrVelocity));
                frame.emissionPosition[0] = 0;
                frame.emissionPosition[1] = 0;
                frame.emissionPosition[2] = 0x20;
                Actor783B0func_8004ED6C(secondMatrixOrVelocity, emissionPosition, emissionPosition);
                Actor783B0func_8004F194(emissionPosition, emissionPosition, owner + 0xC);
                matrix4 = secondMatrixOrVelocity; secondMatrixOrVelocity = &frame.emissionVelocity[0]; matrix5 = secondMatrixOrVelocity;
                asm("" : "=r"(matrix4), "=r"(matrix5) : "0"(matrix4), "1"(matrix5) : "memory");
                work2 = Actor783B0Field(state, int *, 0x18);
                asm("" : : : "memory");
                frame.emissionVelocity[1] = 0;
                frame.emissionVelocity[0] = ((work2 - 0x5A) >> 2) + 0x18;
                frame.emissionVelocity[2] = -0x18 - ((int) (Actor783B0Field(state, int *, 0x18) - 0x5A) >> 2);
                Actor783B0func_8004ED6C(matrix4, matrix5, secondMatrixOrVelocity);
                Actor783B0SpawnParticle(1, 3, emissionPosition, secondMatrixOrVelocity);
            }
            phaseAfterCallbacks = Actor783B0Field(state, int *, 0x18);
            if (phaseAfterCallbacks >= 0x5B) {
                if ((unsigned char) Actor783B0Field(owner, unsigned char *, 0x44) < 0x80U) {
                    work2 = phaseAfterCallbacks - 0x5A;
                    Actor783B0Field(owner, unsigned char *, 0x44) = (unsigned char) -(work2 >> 5);
                    return;
                }
                work2 = phaseAfterCallbacks - 0x5A;
                Actor783B0Field(owner, unsigned char *, 0x44) = (unsigned char) (work2 >> 5);
                return;
            }
        } else if (phase >= 0xB5) {
            Actor783B0Field(owner, unsigned char *, 0x49) = 0U;
            Actor783B0Field(state, int *, 0x18) = 0;
            Actor783B0Field(owner, int *, 0x18) = 0;
            Actor783B0Field(owner, unsigned char *, 0x49) = 2U;
            Actor783B0Field(Actor783B0Field(state, void **, 4), short *, 2) = 1;
            Actor783B0Field(state, int *, 0x18) = 0;
            Actor783B0func_8004F168(state + 0xC);
            Actor783B0Field(state, int *, 8) = Actor783B0func_80050844(owner + 0xC, 3, 6, 0x4080E0);
            Actor783B0Field(owner, unsigned char *, 0x52) = 0xFF;
            if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int *, 0x20)) != 0) {
                if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int *, 0x20)) != 0) {
                    Actor783B0func_8003BE70(Actor783B0Field(state, int *, 0x20));
                }
                Actor783B0Field(state, int *, 0x20) = -1;
                return;
            }
        }
        break;
    case 2:
        stateVector = state + 0xC;
        if (Actor783B0unk_ovlheader_800743EC(owner, Actor783B0Field(state, void **, 4), stateVector, state + 0x18, 4, 0) & 2) {
            linkedIndexAfterHeader = Actor783B0Field(state, int *, 0);
            if (linkedIndexAfterHeader > 0) {
                linkedActor = (linkedIndexAfterHeader * 0x58) + Actor783B0D_8006C550;
                Actor783B0Field(linkedActor, int *, 0x18) = (int) (Actor783B0Field(linkedActor, int *, 0x18) | 0x60000);
                Actor783B0Field(((Actor783B0Field(state, int *, 0) * 0x58) + Actor783B0D_8006C550), unsigned char *, 0x4A) = 0xFF;
            }
            particleCount = 0;
            do {
                particleCount += 1;
                frame.burstVelocity[0] = 0x80 - (Actor783B0rand() & 0xFF);
                frame.burstVelocity[1] = 0x80 - (Actor783B0rand() & 0xFF);
                frame.burstVelocity[2] = Actor783B0rand() & 0x7F;
                Actor783B0func_8004F194(&frame.burstPosition[0], owner + 0xC, &frame.burstVelocity[0]);
                Actor783B0SpawnParticle(1, 3, &frame.burstPosition[0], &frame.burstVelocity[0]);
            } while (particleCount < 8);
            Actor783B0Field(owner, unsigned char *, 0x49) = 3U;
            Actor783B0Field(state, int *, 0x18) = 0;
            Actor783B0Field(owner, signed char *, 0x4C) = 0;
            Actor783B0Field(owner, signed char *, 0x4D) = 0;
        } else if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int *, 0x20)) == 0) {
            Actor783B0Field(state, int *, 0x20) = Actor783B0func_8003BABC(owner, 0, 4);
        } else {
            Actor783B0func_8004F178(&frame.burstPosition[0], stateVector);
            Actor783B0func_8004F0E8(&frame.burstPosition[0], 2);
            Actor783B0func_8003C014(Actor783B0Field(state, int *, 0x20), &frame.burstPosition[0]);
        }
        ownerVector = (int *)(owner + 0xC);
        Actor783B0Field(owner, unsigned char *, 0x45) = (unsigned char) (Actor783B0Field(owner, unsigned char *, 0x45) - 0x40);
        Actor783B0func_8001A358(ownerVector, 0x8000);
        Actor783B0func_8005629C(owner);
        if (Actor783B0D_8006C640 & 1) {
            Actor783B0func_8004F168(&frame.clearedVector[0]);
            Actor783B0SpawnParticle(1, 3, ownerVector, &frame.clearedVector[0]);
            return;
        }
        break;
    case 3:
        nextPhase = Actor783B0Field(state, int *, 0x18) + 1;
        Actor783B0Field(state, int *, 0x18) = nextPhase;
        if (nextPhase >= 6) {
            handle = Actor783B0Field(state, int *, 8);
            if (handle != 0) {
                Actor783B0func_800509E8(handle);
            }
            if (Actor783B0func_8003BFC0(owner, Actor783B0Field(state, int *, 0x20)) != 0) {
                Actor783B0func_8003BE70(Actor783B0Field(state, int *, 0x20));
            }
            Actor783B0func_80055B18(owner);
        }
        break;
    }
}

#undef Actor783B0Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev 0 source asm/nonmatchings/overlays/level_22/moby/func_level_22_80078EF0.s; SHA256 7fae6fddf72eccbec6b6e5bd91e4a32ef5ad669b2c227aca67caa6c830c37158. */
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
void func_level_22_80078EF0(void* input){
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
void func_level_22_80079574(Moby *moby) {
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
void func_level_22_80079878(void *input) {
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
void func_level_22_8007A3EC(Moby* moby) {
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
void func_level_22_8007A81C(Moby* moby) {
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
void func_level_22_8007AB84(Moby* owner) {
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
void func_level_22_8007AD10(Moby* moby) {
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

void func_level_22_8007B02C(Moby* moby) {
    int* tag = moby->mobyTag;
    if (moby->state == 0) {
        if (moby->damageFlags) {
            func_8003BABC(moby, 0, 0);
            func_8003BB10(moby, tag[3], 0);
            tag[0] = 1;
            func_8003B7B4(tag, 4, &savedData);
            func_8003B7B4(tag, 4, &unsavedData);
        }
        if (tag[0]) {
            func_80021ED8((void*)tag[2], 0xFC, 0);
            moby->state = 1;
            func_80034F40(moby, 1);
        }
    }
}

typedef struct {
    unsigned char unk0, unk1;
    short offset;
    Moby* parent;
} DecodedFollowTag;
extern unsigned short D_8006E040, D_8006E03E;
extern int deltaTime;
void func_80055B18(Moby*);
void func_level_22_8007B0F4(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* Modulo32 ADDU/SUBU/shift products; conversions and signed shifts use
* the frozen 32-bit MIPS compiler ABI. No input range is assumed. */
#define Actor857Add(a,b) ((int)((unsigned int)(a)+(unsigned int)(b)))
#define Actor857Sub(a,b) ((int)((unsigned int)(a)-(unsigned int)(b)))
#define Actor857Mul(a,b) ((int)((unsigned int)(a)*(unsigned int)(b)))
#define Actor857Neg(a) ((int)(0U-(unsigned int)(a)))
#define Actor857Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor857_func_80018368() __asm__("func_80018368");
int Actor857_func_80019194() __asm__("func_80019194");
int Actor857_func_8001A358() __asm__("func_8001A358");
int Actor857_func_8001BA30() __asm__("func_8001BA30");
int Actor857_func_80036220() __asm__("func_80036220");
int Actor857_func_800365E4() __asm__("func_800365E4");
int Actor857_func_80037014() __asm__("func_80037014");
int Actor857_func_8003BABC() __asm__("func_8003BABC");
int Actor857_func_8003C140() __asm__("func_8003C140");
int Actor857_func_80049484() __asm__("func_80049484");
int Actor857_func_8004E880() __asm__("func_8004E880");
int Actor857_func_8004E9E4() __asm__("func_8004E9E4");
int Actor857_func_8004EA2C() __asm__("func_8004EA2C");
int Actor857_func_8004EDE8() __asm__("func_8004EDE8");
int Actor857_func_8004EF74() __asm__("func_8004EF74");
int Actor857_func_8004F08C() __asm__("func_8004F08C");
int Actor857_func_8004F110() __asm__("func_8004F110");
int Actor857_func_8004F178() __asm__("func_8004F178");
int Actor857_func_8004F194() __asm__("func_8004F194");
int Actor857_func_8004F264() __asm__("func_8004F264");
int Actor857_func_8004F334() __asm__("func_8004F334");
int Actor857_func_80055D24() __asm__("func_80055D24");
int Actor857_func_80055F14() __asm__("func_80055F14");
int Actor857_func_8005629C() __asm__("func_8005629C");
extern int Actor857_D_800658A0 __asm__("D_800658A0");
extern int Actor857_D_80065920 __asm__("D_80065920");
extern int Actor857_D_8006C550 __asm__("D_8006C550");
extern int Actor857_D_8006C648 __asm__("D_8006C648");
extern unsigned short Actor857_D_8006E03E __asm__("D_8006E03E");
extern unsigned short Actor857_D_8006E040 __asm__("D_8006E040");
extern int Actor857_D_8006E044 __asm__("D_8006E044");
extern int Actor857_D_8006E344 __asm__("D_8006E344");
extern int Actor857_D_8006E788 __asm__("D_8006E788");
extern int Actor857_D_80070328 __asm__("D_80070328");
extern int Actor857_D_80071918 __asm__("D_80071918");
extern int Actor857_D_80071920 __asm__("D_80071920");
extern short Actor857OriginalTableView1 __asm__("D_80065920 + 0x0");
extern short Actor857OriginalTableView2 __asm__("D_800658A0 + 0x00");
extern short Actor857OriginalTableView3 __asm__("D_80065920 + 0x000");
extern short Actor857OriginalTableView4 __asm__("D_800658A0 + 0x0000");
extern short Actor857OriginalTableView5 __asm__("D_80065920 + 0x00000");
extern short Actor857OriginalTableView6 __asm__("D_80065920 + 0x000000");
extern short Actor857OriginalTableView7 __asm__("D_800658A0 + 0x0000000");
extern short Actor857OriginalTableView8 __asm__("D_80065920 + 0x00000000");
extern short Actor857OriginalTableView9 __asm__("D_800658A0 + 0x000000000");
extern short Actor857OriginalTableView10 __asm__("D_80065920 + 0x0000000000");
extern short Actor857OriginalTableView11 __asm__("D_800658A0 + 0x00000000000");
extern short Actor857OriginalTableView12 __asm__("D_80065920 + 0x000000000000");
extern short Actor857OriginalTableView13 __asm__("D_800658A0 + 0x0000000000000");
void func_level_22_8007B248(void *input) {
    register int valueT0 __asm__("$8");
    register int valueV0 __asm__("$2"),valueV1 __asm__("$3"),argument0 __asm__("$4"),argument1 __asm__("$5"),argument2 __asm__("$6"),argument3 __asm__("$7");
    register void *actor __asm__("$19");
    register int privateData __asm__("$20"),valueS0 __asm__("$16"),valueS1 __asm__("$17"),valueS2 __asm__("$18"),valueS5 __asm__("$21"),valueS6 __asm__("$22"),valueS7 __asm__("$23");
    struct{
        int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C;
    }
    frame;
    int temp_a3;
    int temp_a3_2;
    int temp_v0_8;
    int temp_a0;
    int temp_a0_2;
    int temp_a3_3;
    int temp_v0;
    int factorFp;
    int var_v0_2;
    int var_v1;
    int temp_v1;
    int temp_a1;
    int temp_v0_2;
    int temp_v0_7;
    int temp_v1_2;
    int var_a0;
    actor=input;
    __asm__("":"=r"(actor):"0"(actor));
    privateData = Actor857Field(actor, void **, 0);
    valueV1=Actor857Field(privateData,int*,24);
    valueV0=Actor857Mul(valueV1,88);
    valueV1=Actor857_D_8006C550;
    valueS5=Actor857Add(valueV1,valueV0);
    argument0=Actor857Field(valueS5,volatile int*,0);
    __asm__("":::"memory");
    Actor857Field(privateData,int*,28)=0;
    __asm__ volatile(""::"r"(argument0));
    valueV1=Actor857Field(actor,unsigned char*,72);
    __asm__("":"=r"(valueV1):"0"(valueV1));
    switch(valueV1){
        recordOriginalNearestIndex:Actor857Field(privateData,int*,28)=valueV0;
        goto originalNearestScanComplete;
        case 0:__asm__ volatile(""::"r"(valueV1));
        valueS2 = 0x05F5E0FF;
        valueS0 = 0;
        valueS1 = privateData;
        loop_4:
        valueV1=Actor857_func_8004F334((int)actor+12,Actor857Add(Actor857Add(Actor857_D_8006C550,Actor857Mul(Actor857Field(valueS1,int*,32),88)),12));
        if(valueV1<valueS2)valueS2=valueV1;
        valueV0=valueV1<700;
        __asm__("":"=r"(valueV0):"0"(valueV0));
        if(!valueV0){
            valueS0+=1;
            valueS1=Actor857Add(valueS1,4);
            if(valueS0<4)goto loop_4;
        }
        else{
            valueV0=valueS0+1;
            goto recordOriginalNearestIndex;
        }
        originalNearestScanComplete:
        if(({valueV0=valueS2<3000;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;})){
            if (Actor857Field(actor, int *, 0x14) < 0x3000) {
                Actor857Field(actor, int *, 0x14) = 0x4C00;
                Actor857Field(actor, int *, 0x14) = Actor857_func_8001A358(actor + 0xC, 0x2800);
            }
        }
        Actor857Field(actor, short *, 0x38) = 0x6E;
        Actor857_func_80037014(actor);
        if ((Actor857_func_8004F264(Actor857Field((int)&Actor857_D_80070328, unsigned char *, 0xE), Actor857_func_8004E880(Actor857Sub(Actor857Field(actor, int *, 0xC),Actor857Field((int)&Actor857_D_80070328, int *, 0)), Actor857Sub(Actor857Field(actor, int *, 0x10),Actor857Field((int)&Actor857_D_80070328, int *, 4)), 0)) < 0x10) && ({valueV0=Actor857_func_8004F334((int)actor+12,(int)&Actor857_D_80070328);valueV0=Actor857Sub(valueV0,600);valueV0=valueV0<250;valueV1=Actor857Field(actor,int*,20);argument0=Actor857Field((int)&Actor857_D_80070328,int*,8);valueV1=Actor857Add(valueV1,356);__asm__("":"=r"(valueV0):"0"(valueV0),"r"(argument0),"r"(valueV1));argument0=Actor857Sub(argument0,valueV1);valueV0;})&&({valueV0=argument0<256;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;}) && (Actor857_D_8006E344 != 1) && (Actor857Field((int)&Actor857_D_80070328, int *, 0x170) == 0)) {
            Actor857Field((int)&Actor857_D_80070328, int *, 0x20C) = 0x10000001;
            Actor857Field((int)&Actor857_D_80070328, void **, 0x218) = actor;
            Actor857Field(actor, signed char *, 0x4F) = 0x20;
        }
        Actor857Field(privateData, void **, 0xC) = 0;
        return;
        case 1:
        Actor857Field(actor, int *, 8) = 0;
        Actor857Field(actor, signed char *, 0x4C) = 0;
        Actor857Field(actor, signed char *, 0x4D) = 0;
        Actor857Field(actor, unsigned char *, 0x4A) = 0xFF;
        return;
        case 2:
        Actor857Field(actor, signed char *, 0x4F) = 0x20;
        Actor857Field(actor, signed char *, 0x4C) = 0x50;
        Actor857Field(actor, unsigned char *, 0x45) = 0U;
        Actor857Field(actor, signed char *, 0x4D) = 1;
        temp_a0 = actor + 0xC;
        if (Actor857_D_8006E044 == 7) {
            __asm__("":"=r"(actor):"0"(actor));
            Actor857_func_80049484(actor+12);
        }
        else {
            Actor857Field(actor, int *, 0xC) = (int) ((int) (Actor857Field((int)&Actor857OriginalTableView1,short*,(Actor857Field((int)&Actor857_D_80070328, unsigned char *, 0xE) * 2)) * 0x4B) >> 9);
            temp_a3 = Actor857Field((int)&Actor857OriginalTableView2,short*,(Actor857Field((int)&Actor857_D_80070328, unsigned char *, 0xE) * 2));
            Actor857Field(actor, int *, 0x14) = 0xFA;
            Actor857Field(actor, int *, 0x10) = (int) ((int) (temp_a3 * 0x4B) >> 9);
            Actor857_func_8004F194(temp_a0, temp_a0, ((int)&Actor857_D_80070328 + 0xE) - 0xE);
        }
        argument0=(int)&frame.sp18;
        valueS1=(int)&Actor857_D_80070328+14;
        argument3=Actor857Field(valueS1,unsigned char*,0);
        __asm__("":::"$5","memory");
        argument1=argument0;
        argument3*=2;
        valueV1=Actor857Field((int)&Actor857OriginalTableView3,short*,argument3);
        __asm__("":::"$6","memory");
        argument2=valueS1-14;
        __asm__("":"=r"(valueV1):"0"(valueV1),"r"(argument2));
        valueV0=valueV1*25;
        valueV0>>=9;
        frame.sp18=valueV0;
        valueV1=Actor857Field((int)&Actor857OriginalTableView4,short*,argument3);
        __asm__("":::"$2","memory");
        valueV0=200;
        frame.sp20=valueV0;
        __asm__("":"=r"(valueV1):"0"(valueV1),"m"(frame.sp20));
        valueV0=valueV1*25;
        valueV0>>=9;
        frame.sp1C=valueV0;
        Actor857_func_8004F194(argument0,argument1,argument2);
        argument0=(int)&frame.sp18;
        __asm__("":"=r"(argument0):"0"(argument0));
        __asm__("":::"$16","memory");
        valueS0=(int)actor+12;
        if(Actor857_func_80018368(argument0,valueS0)!=0)Actor857_func_8004F178(valueS0,&frame.sp18);
        Actor857Field(actor, unsigned char *, 0x46) = (unsigned char) (Actor857Field((int)&Actor857_D_80070328, unsigned char *, 0xE) + Actor857Field((int)&Actor857_D_80070328, unsigned char *, 0x12));
        if (Actor857_D_8006E044 == 7) {
            Actor857Field(actor, unsigned char *, 0x45) = (unsigned char) (0xE - ((int) ((int)((unsigned int)Actor857_D_8006E03E << 0x10)) >> 0x14));
            Actor857Field(actor, unsigned char *, 0x46) = (unsigned char) ((unsigned short) Actor857_D_8006E040 >> 4);
        }
        else {
            Actor857Field(actor, unsigned char *, 0x45) = 0xEU;
        }
        valueS7 = 0;
        factorFp=280;
        __asm__("":"=r"(factorFp):"0"(factorFp));
        frame.sp80 = 0;
        argument2=0;
        __asm__("":"=r"(argument2):"0"(argument2));
        valueS0=(int)&Actor857_D_80070328;
        valueV1=Actor857Field(privateData,int*,72);
        argument0=Actor857Field(valueS0,int*,0);
        argument1=Actor857Field((int)&Actor857_D_80070328,int*,4);
        valueV0=Actor857Mul(valueV1,88);
        valueV1=Actor857_D_8006C550;
        valueV0=Actor857Add(valueV0,valueV1);
        valueV1=Actor857Field(valueV0,int*,12);
        valueV0=Actor857Field(valueV0,int*,16);
        argument0=Actor857_func_8004E880(Actor857Sub(valueV1,argument0),Actor857Sub(valueV0,argument1),argument2);
        {
            int retainedApproach=Actor857_func_8004F264(argument0,Actor857Field((int)&Actor857_D_80070328,unsigned char*,14));
            valueV0=Actor857_func_80036220(valueS0,privateData+48,0,800);
            valueS0=retainedApproach;
            if(valueV0&&({valueV0=valueS0<24;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;})){
                factorFp=370;
            }
        }
        valueV0=Actor857Field(actor,unsigned char*,70);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        valueV0=Actor857Field((int)&Actor857OriginalTableView5,short*,valueV0);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueT0=valueV0*factorFp;
        valueV0=Actor857Field(actor,unsigned char*,69);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        __asm__ volatile("":"=r"(valueT0):"0"(valueT0),"r"(valueV0):"memory");
        valueV1=Actor857Field((int)&Actor857OriginalTableView6,short*,valueV0);
        __asm__("":::"$2","memory");
        valueV0=valueT0>>12;
        __asm__("":"=r"(valueV1):"0"(valueV1),"r"(valueV0));
        valueT0=valueV0*valueV1;
        __asm__("":"=r"(valueT0):"0"(valueT0));
        valueV0=valueT0>>12;
        __asm__("":"=r"(valueV0):"0"(valueV0));
        Actor857Field(privateData,int*,0)=valueV0;
        valueV0=Actor857Field(actor,unsigned char*,70);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        valueV0=Actor857Field((int)&Actor857OriginalTableView7,short*,valueV0);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueT0=valueV0*factorFp;
        valueV0=Actor857Field(actor,unsigned char*,69);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        __asm__ volatile("":"=r"(valueT0):"0"(valueT0),"r"(valueV0):"memory");
        valueV1=Actor857Field((int)&Actor857OriginalTableView8,short*,valueV0);
        __asm__("":::"$2","memory");
        valueV0=valueT0>>12;
        __asm__("":"=r"(valueV1):"0"(valueV1),"r"(valueV0));
        valueT0=valueV0*valueV1;
        __asm__("":"=r"(valueT0):"0"(valueT0));
        valueV0=valueT0>>12;
        __asm__("":"=r"(valueV0):"0"(valueV0));
        Actor857Field(privateData,int*,4)=valueV0;
        valueV0=Actor857Field(actor,unsigned char*,69);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        valueV0=Actor857Field((int)&Actor857OriginalTableView9,short*,valueV0);
        __asm__("":"=r"(valueV0):"0"(valueV0):"memory");
        valueT0=valueV0*factorFp;
        valueS2=(int)&Actor857_D_8006E788;
        valueS5=127;
        valueS6=30720;
        Actor857Field(privateData,int*,12)=0;
        __asm__("":"=r"(valueT0):"0"(valueT0),"m"(Actor857Field(privateData,int*,12)));
        valueV0=valueT0>>12;
        __asm__("":"=r"(valueV0):"0"(valueV0));
        Actor857Field(privateData,int*,8)=valueV0;
        goto checkOriginalActorCursor;
        originalActorBody:{
            if (Actor857Field(valueS0, short *, 0x36) == 0x224) {
                valueS1 = Actor857_func_8004F334(actor + 0xC, valueS0 + 0xC);
                argument0 = Actor857_func_8004F264(Actor857_func_8004E880(Actor857Sub(Actor857Field(valueS0, int *, 0xC),Actor857Field(actor, int *, 0xC)), Actor857Sub(Actor857Field(valueS0, int *, 0x10),Actor857Field(actor, int *, 0x10)), 0), Actor857Field(actor, unsigned char *, 0x46));
                valueV1=6144;
                valueV1=Actor857Sub(valueV1,valueS1);
                if(valueV1<0)valueV1=Actor857Sub(valueS1,6144);
                if (({valueV0=argument0<8;valueS1=valueV1;valueV0;})&&({__asm__("":"=r"(valueS1):"0"(valueS1));valueV0=valueS1<5120;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;})&&!({valueV0=valueS5<argument0;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;})&&({valueV0=valueS1<valueS6;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;})) {
                    valueS7 = valueS0;
                    valueS6 = valueS1;
                    valueS5 = argument0;
                }
            }
        }
        checkOriginalActorCursor:valueS0=Actor857Field(valueS2,int*,0);
        valueS2+=4;
        if(valueS0)goto originalActorBody;
        if (valueS7 != 0) {
            valueS1=(int)&frame.sp38;
            Actor857_func_8004F178(valueS1,privateData);
            valueS0=(int)&frame.sp48;
            Actor857_func_8004F178(valueS0,(int)actor+12);
            valueS2 = 0;
            loop_43:
            Actor857_func_8004F178(&frame.sp28, actor + 0xC);
            Actor857_func_8004F194(valueS0,valueS0,valueS1);
            frame.sp40 -= 0xE;
            Actor857_func_8004F194(valueS0,valueS0,valueS1);
            frame.sp40 -= 0xE;
            if ((frame.sp48 >= 0) && (frame.sp4C >= 0) && (frame.sp50 >= 0)) {
                if ((valueS7 != 0) && (Actor857_func_8004F334(valueS7+12,valueS0) < 0x1388)) {
                    valueV0=Actor857Field(valueS7,int*,20);
                    __asm__("":::"$4","memory");
                    argument0=frame.sp50;
                    __asm__("":::"$3","memory");
                    /* Original Rev0 8007B8F8 / Rev1 8007B9AC: initialized full32 register copy.
                    * Documented mixed C/assembly exception: frozen GCC otherwise emits ADDU. */
                    __asm__("addiu %0,%1,0" : "=r"(valueV1) : "r"(valueV0));
                    __asm__("":"=r"(valueV1):"0"(valueV1));
                    valueV0=Actor857Sub(valueV1,argument0);
                    if (valueV0 >= 0) {
                        if (valueV0 >= 0x708) {
                            valueS2 += 1;
                            goto block_54;
                        }
                        goto block_52;
                    }
                    if(({valueV0=Actor857Sub(argument0,valueV1);valueV0=valueV0<1800;__asm__("":"=r"(valueV0):"0"(valueV0));valueV0;})) {
                        block_52:
                        frame.sp80 = valueS7;
                    }
                    else {
                        goto block_53;
                    }
                }
                else {
                    block_53:
                    valueS2 += 1;
                    block_54:
                    if (valueS2 < 0x1E) {
                        goto loop_43;
                    }
                }
            }
        }
        valueT0=frame.sp80;
        __asm__("":"=r"(valueT0):"0"(valueT0));
        argument2=1;
        if(valueT0){
            Actor857Field(privateData,int*,12)=valueT0;
            valueV1=Actor857Field(valueT0,int*,12);
            argument0=Actor857Field(actor,int*,12);
            valueV0=Actor857Field(valueT0,int*,16);
            argument1=Actor857Field(actor,int*,16);
            __asm__ volatile(""::"r"(valueT0),"r"(valueV0),"r"(valueV1),"r"(argument0),"r"(argument1),"r"(argument2):"$7");
            valueV0=Actor857_func_8004E880(Actor857Sub(valueV1,argument0),Actor857Sub(valueV0,argument1),argument2);
            argument2=0;
            __asm__("":"=r"(argument2):"0"(argument2));
            valueS0=valueV0;
            valueV1=Actor857Field(privateData,void**,12);
            argument0=Actor857Field(actor,int*,12);
            argument1=Actor857Field(actor,int*,16);
            argument3=Actor857Field(valueV1,int*,12);
            valueV1=Actor857Field(valueV1,int*,16);
            valueV0=Actor857_func_8004E880(Actor857Sub(argument3,argument0),Actor857Sub(valueV1,argument1),argument2);
            valueS1=(int)&frame.sp58;
            Actor857Field(actor,unsigned char*,70)=valueV0;
            Actor857_func_8004F178(valueS1,Actor857Field(privateData,void**,12)+12);
            frame.sp60 = Actor857Add(frame.sp60,0xD2);
            valueV0=Actor857_func_8004EA2C(valueS0);
            valueT0=valueV0*factorFp;
            argument0=valueS0;
            __asm__("":"=r"(valueT0):"0"(valueT0),"r"(argument0));
            valueV0=valueT0>>12;
            __asm__("":"=r"(valueV0):"0"(valueV0));
            Actor857Field(privateData,int*,0)=valueV0;
            valueV0=Actor857_func_8004E9E4(argument0);
            valueT0=valueV0*factorFp;
            __asm__("":"=r"(factorFp):"0"(factorFp));
            argument0=(int)actor+12;
            argument1=valueS1;
            argument2=factorFp;
            argument3=-14;
            __asm__("":"=r"(valueT0):"0"(valueT0),"r"(argument0),"r"(argument1),"r"(argument2),"r"(argument3));
            valueV0=valueT0>>12;
            __asm__("":"=r"(valueV0):"0"(valueV0));
            Actor857Field(privateData,int*,4)=valueV0;
            valueV0=(int)&frame.sp68;
            valueV0=Actor857_func_800365E4(argument0,argument1,argument2,argument3,valueV0);
            Actor857Field(privateData,int*,8)=valueV0;
        }
        goto block_97;
        default:return;
        case 3:
        if ((Actor857Field(actor, int *, 0xC) < 0x400) || (Actor857Field(actor, int *, 0x10) < 0x400) || (Actor857Field(actor, int *, 0x14) < 0x400)) {
            valueV0=1;
            __asm__("":"=r"(valueV0):"0"(valueV0));
            Actor857Field(argument0,short*,28)=valueV0;
            valueV0 = 0x1E;
            goto block_98;
        }
        argument0=(int)&frame.sp58;
        __asm__("":"=r"(argument0):"0"(argument0));
        __asm__("":::"$16","memory");
        valueS0=(int)actor+12;
        Actor857_func_8004F178(argument0,valueS0);
        temp_a1 = Actor857Field(privateData, void **, 0xC);
        Actor857Field(privateData, int *, 8) = Actor857Add(Actor857Field(privateData, int *, 8),(Actor857Neg(Actor857Mul(Actor857_D_8006C648,0xE)) >> 1));
        if ((temp_a1 == 0) || (Actor857_func_8004F334(valueS0, temp_a1 + 0xC) >= 0x65)) {
            argument0=Actor857_D_8006C648;
            valueV0=Actor857Field(privateData,int*,0);
            __asm__("":"=r"(valueV0):"0"(valueV0));
            valueT0=(int)(unsigned int)((long long)(int)argument0 * (long long)(int)valueV0);
            valueV0=Actor857Field(actor,int*,12);
            __asm__("":"=r"(valueT0):"0"(valueT0),"r"(valueV0));
            valueV1=valueT0>>1;
            __asm__("":"=r"(valueV1):"0"(valueV1));
            valueV0=Actor857Add(valueV0,valueV1);
            Actor857Field(actor,int*,12)=valueV0;
            valueV0=Actor857Field(privateData,int*,4);
            __asm__("":"=r"(valueV0):"0"(valueV0));
            valueT0=(int)(unsigned int)((long long)(int)argument0 * (long long)(int)valueV0);
            valueV0=Actor857Field(actor,int*,16);
            __asm__("":"=r"(valueT0):"0"(valueT0),"r"(valueV0));
            valueV1=valueT0>>1;
            __asm__("":"=r"(valueV1):"0"(valueV1));
            valueV0=Actor857Add(valueV0,valueV1);
            Actor857Field(actor,int*,16)=valueV0;
        }
        valueV1=Actor857_D_8006C648;
        __asm__("":::"$2","memory");
        valueV0=Actor857Field(privateData,int*,8);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueT0=(int)(unsigned int)((long long)(int)valueV1 * (long long)(int)valueV0);
        valueS5=(int)&frame.sp58;
        argument0=valueS5;
        __asm__("":"=r"(argument0):"0"(argument0));
        __asm__("":::"$17","memory");
        valueS1=(int)actor+12;
        argument1=valueS1;
        valueV0=Actor857Field(actor,int*,20);
        __asm__("":"=r"(valueT0):"0"(valueT0),"r"(valueV0),"r"(argument1));
        valueV1=valueT0>>1;
        __asm__("":"=r"(valueV1):"0"(valueV1));
        valueV0=Actor857Add(valueV0,valueV1);
        Actor857Field(actor,int*,20)=valueV0;
        if(Actor857_func_80018368(argument0,argument1)!=0) {
            valueS6=(int)&Actor857_D_80071918;
            {
                int retainedContactDistance=Actor857_func_8004EDE8(valueS6,1);
                valueV0=Actor857_func_8004EDE8(privateData,1);
                valueS2=retainedContactDistance;
                valueS0=valueV0;
            }
            if(valueS0<30){
                valueS0=30;
                __asm__("":"=r"(valueS0):"0"(valueS0));
            }
            if(({valueV0=valueS0<81;__asm__("":"=r"(valueV0):"0"(valueV0));!valueV0;}))valueS0=80;
            Actor857_func_8004F178(privateData,valueS6);
            Actor857_func_8004F08C(privateData,valueS2,valueS0);
            Actor857_func_8004F178(valueS1,valueS5);
            Actor857Field(actor, int *, 0xC) = Actor857Add(Actor857Field(actor, int *, 0xC),(Actor857Field(privateData, int *, 0) >> 2));
            Actor857Field(actor, int *, 0x10) = Actor857Add(Actor857Field(actor, int *, 0x10),(Actor857Field(privateData, int *, 4) >> 2));
            Actor857Field(actor, int *, 0x14) = Actor857Add(Actor857Field(actor, int *, 0x14),(Actor857Field(privateData, int *, 8) >> 2));
            return;
        }
        if (Actor857_func_80019194(valueS1, 0x6E) != 0) {
            valueS1=(int)&Actor857_D_80071920;
            valueS2=valueS1-8;
            argument0=valueS2;
            __asm__("":"=r"(argument0):"0"(argument0));
            valueS0=Actor857Field(valueS1,int*,0);
            if (valueS0 < 0) {
                valueS0 = Actor857Neg(valueS0);
            }
            if(({valueV0=Actor857_func_8004EDE8(argument0,0);valueS0=valueS0<valueV0;valueS0;})) {
                Actor857_func_8004F178(&frame.sp28, valueS2);
                if ((Actor857_func_8004EF74(privateData, &frame.sp28, privateData) != 0) && (Actor857Field(privateData, int *, 0) = (int) (Actor857Mul(Actor857Field(privateData, int *, 0),6)) >> 3, Actor857Field(privateData, int *, 4) = (int) ((int) (Actor857Mul(Actor857Field(privateData, int *, 4),6)) >> 3), Actor857Field(privateData, int *, 8) = (int) ((int) (Actor857Mul(Actor857Field(privateData, int *, 8),6)) >> 3), argument0 = Actor857_func_8003BABC(actor, 0, 0), (argument0 >= 0))) {
                    valueV0 = Actor857Field(privateData, int *, 8);
                    if (valueV0 < 0) {
                        valueV0 = Actor857Neg(valueV0);
                    }
                    __asm__("":"=r"(valueV0):"0"(valueV0));
                    Actor857_func_8003C140(argument0, Actor857Mul(valueV0,0x28));
                    __asm__("":"=r"(actor):"0"(actor));
                    argument0=(int)actor+12;
                }
                else {
                    goto block_92;
                }
            }
            else if ((({valueS0=Actor857Field(valueS1,int*,0);valueS0;})>=0) || (({valueV0=Actor857Field(privateData,int*,8);argument0=(int)actor;valueV0;})<=0)) {
                __asm__("":"=r"(actor):"0"(actor));
                argument0=(int)actor+12;
                if ((valueS0>0) && (({valueV0=Actor857Field(privateData,int*,8);valueV0;})<0)) {
                    __asm__ volatile("":::"$4","memory");
                    argument0=(int)actor;
                    goto block_84;
                }
            }
            else {
                block_84:
                Actor857Field(privateData, int *, 0) = 0;
                Actor857Field(privateData, int *, 4) = 0;
                Actor857Field(privateData, int *, 8) = (int) ((int) Actor857Neg(Actor857Field(privateData, int *, 8)) >> 1);
                argument0 = Actor857_func_8003BABC(argument0,0,0);
                if (argument0 >= 0) {
                    valueV0 = Actor857Field(privateData, int *, 8);
                    if (valueV0 < 0) {
                        valueV0 = Actor857Neg(valueV0);
                    }
                    __asm__("":"=r"(valueV0):"0"(valueV0));
                    Actor857_func_8003C140(argument0, Actor857Mul(valueV0,0x28));
                }
                if (Actor857Field(privateData, int *, 8) < 0x1E) {
                    Actor857Field(actor, int *, 0x14) = (int) (Actor857Add(Actor857_func_8001A358(actor + 0xC, 0x2000),0x6E));
                    Actor857Field(actor, unsigned char *, 0x48) = 0U;
                }
                goto block_92;
            }
        }
        else {
            temp_v0_7 = Actor857_func_8001BA30(valueS1, 0x6E, 0, 0, 0, actor);
            if (temp_v0_7 != 0) {
                valueV0=Actor857_func_8004E880(Actor857Sub(Actor857Field(actor, int *, 0xC),Actor857Field(temp_v0_7, int *, 0xC)), Actor857Sub(Actor857Field(actor, int *, 0x10),Actor857Field(temp_v0_7, int *, 0x10)), 0);
                valueV0*=2;
                valueV0=Actor857Field((int)&Actor857OriginalTableView10,short*,valueV0);
                __asm__("":::"$6","memory");
                argument2=0;
                __asm__("":"=r"(valueV0):"0"(valueV0),"r"(argument2));
                valueV0>>=2;
                frame.sp70=valueV0;
                valueV0=Actor857_func_8004E880(Actor857Sub(Actor857Field(actor, int *, 0xC),Actor857Field(temp_v0_7, int *, 0xC)), Actor857Sub(Actor857Field(actor, int *, 0x10),Actor857Field(temp_v0_7, int *, 0x10)), 0);
                argument0=privateData;
                argument1=(int)&frame.sp70;
                __asm__("":"=r"(argument1):"0"(argument1));
                valueV0*=2;
                valueV0=Actor857Field((int)&Actor857OriginalTableView11,short*,valueV0);
                __asm__("":::"$6","memory");
                argument2=argument0;
                frame.sp78=0;
                __asm__("":"=r"(valueV0):"0"(valueV0),"r"(argument2),"m"(frame.sp78));
                valueV0>>=2;
                frame.sp74=valueV0;
                Actor857_func_8004EF74(argument0,argument1,argument2);
            }
            block_92:
            __asm__("":"=r"(actor):"0"(actor));
            argument0=(int)actor+12;
        }
        Actor857_func_8001A358(argument0,8192);
        Actor857_func_8005629C(actor);
        Actor857_func_80055D24(actor, 2);
        return;
        case 20:
        valueV0=12;
        Actor857Field(actor,unsigned char*,74)=valueV0;
        __asm__("":"=r"(valueV0):"0"(valueV0),"m"(Actor857Field(actor,unsigned char*,74)));
        valueV0 = 0x15;
        Actor857Field(actor, signed char *, 0x41) = 0;
        Actor857Field(actor, signed char *, 0x4C) = 0;
        __asm__("":"=r"(actor):"0"(actor),"m"(Actor857Field(actor,unsigned char*,76)),"i"(20));
        Actor857Field(actor, signed char *, 0x4D) = 0;
        __asm__("":"=r"(actor):"0"(actor),"m"(Actor857Field(actor,unsigned char*,77)),"i"(20));
        Actor857Field(actor, int *, 8) = 0;
        goto block_98;
        case 30:
        valueV0 = 0x1F;
        Actor857Field(actor, signed char *, 0x41) = 0;
        Actor857Field(actor, signed char *, 0x4C) = 0;
        __asm__("":"=r"(actor):"0"(actor),"m"(Actor857Field(actor,unsigned char*,76)),"i"(30));
        Actor857Field(actor, signed char *, 0x4D) = 0;
        __asm__("":"=r"(actor):"0"(actor),"m"(Actor857Field(actor,unsigned char*,77)),"i"(30));
        Actor857Field(actor, int *, 8) = 0;
        goto block_98;
        case 32:
        Actor857Field(actor, signed char *, 0x41) = 1;
        Actor857Field(actor, signed char *, 0x4C) = 0x28;
        Actor857Field(actor, signed char *, 0x4D) = 1;
        Actor857_func_80055D24(actor, 1);
        Actor857_func_80055D24(valueS5, 4);
        Actor857_func_80055F14(valueS5, 0, &frame.sp70);
        Actor857_func_80055F14(valueS5, 1, &frame.sp28);
        valueS0 = actor + 0xC;
        Actor857_func_8004F194(valueS0, &frame.sp70, &frame.sp28);
        Actor857_func_8004F110(valueS0, 1);
        valueV0=Actor857Field(valueS5,unsigned char*,70);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        valueV1=Actor857Field((int)&Actor857OriginalTableView12,short*,valueV0);
        __asm__("":"=r"(valueV1):"0"(valueV1));
        valueV0=valueV1*15;
        valueV0>>=9;
        Actor857Field(privateData,int*,0)=valueV0;
        valueV0=Actor857Field(valueS5,unsigned char*,70);
        __asm__("":"=r"(valueV0):"0"(valueV0));
        valueV0*=2;
        valueV1=Actor857Field((int)&Actor857OriginalTableView13,short*,valueV0);
        __asm__("":::"$2","memory");
        valueV0=35;
        Actor857Field(privateData,int*,8)=valueV0;
        __asm__("":"=r"(valueV1):"0"(valueV1),"m"(Actor857Field(privateData,int*,8)));
        valueV0=valueV1*15;
        valueV0>>=9;
        Actor857Field(privateData,int*,4)=valueV0;
        block_97:valueV0=3;
        block_98:Actor857Field(actor,unsigned char*,72)=valueV0;
        return;
    }
}
#undef Actor857Field
#undef Actor857Add
#undef Actor857Sub
#undef Actor857Mul
#undef Actor857Neg


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original level22 controller8007BFAC.
 * Assembly SHA256 1b4a6cca050f507f19888a2bb9f14b407fb0eee1a193cf2c7706e05502687821.
 * AI generated; not human reviewed.1772 native instructions and TWO
 * original .rodata tables:32 outer state entries at80074600 and7 inner
 * entries at80074680,plus one zero pad at8007469C=1812 owned words.
 * The inner7 entries are not additional outer states. Names identify
 * physical storage/producer roles; gameplay,asset and SFX meanings are open.
 * Original136-byte frame retains initialized SP20/24/28 and30/34/38
 * vectors from original4F178 copies before reads. SP40 is produced by
 * original36518: bestIndex begins0 and is written unconditionally when
 * the original nonnull output argument is provided,including empty scans.
 * SP48/50 are the two entry4F334 results; SP58 is the entry child-private
 * word1C. These producers execute before every state selector. SP2C,3C,
 * 44,4C,54,5C are unused original frame storage,never scalar initializers.
 * Source preserves original post-call child-coordinate reloads,post35D38
 * owner-height loads and the actual3-word E880/5-word35DDC call contracts.
 * The single original DIV uses complete initialized signed32 numerator and
 * signed16 denominator; its original zero/overflow traps remain native.
 * There are no MULT products or partial HILO inputs/projections. S0..S7
 * roles are initialized before use; the ordinary initialHelperPredicate
 * naturally occupies FP after its original entry helper. No FP/SP binding
 * or incoming saved-register read is used. Reused fixed GP phases do not
 * overlap; every metadata input/output is a complete initialized word or
 * address,or an explicit end of a dead caller-register phase.
 * Shared state23/26 exits,inner state27 exit and state30 exit are kept at
 * their actual original positions. State25/27 share ONE initialized next
 * substate producer at the state-byte store entry; GCC places its duplicate
 * calculations into the two original branch delays. The state20 helper
 * failure returns directly,without executing the unrelated common tail.
 * Original scalar flags/fallbacks retain distinct producer and consumer
 * lifetimes. Predicates use ordinary initialized C statements; there are
 * no GNU statement expressions,opcode asm,manual stack homes or defaults.
 * Numeric wrap,narrow and shift behavior targets the frozen32-bit MIPS
 * compiler. Full helper/caller/archive contracts,portable arithmetic
 * domains,units,invocation cadence,Rev1 mappings,synchronized original
 * runtime captures and human review remain open. Acceptance requires all
 * linked native/data/addend/39selector/pad bytes and every retail hash.
 */
#define Actor1772Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Actor1772Keep(v) __asm__("":"=r"(v):"0"(v))
void Actor1772_func_80013AE4(void*,void*) __asm__("func_80013AE4");
void Actor1772_func_80013B7C(int) __asm__("func_80013B7C");
int Actor1772_func_80013E38(void*,void*,int) __asm__("func_80013E38");
int Actor1772_func_8001A358(void*,int) __asm__("func_8001A358");
void Actor1772_func_80034F40(void*,int) __asm__("func_80034F40");
void Actor1772_func_80035734(void*) __asm__("func_80035734");
int Actor1772_func_8003573C(void*,int,int,int) __asm__("func_8003573C");
int Actor1772_func_8003585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Actor1772_func_800359A4(void*,int) __asm__("func_800359A4");
int Actor1772_func_80035A80(void*,void*,int,int,int,int,int,int) __asm__("func_80035A80");
int Actor1772_func_80035D38(void*) __asm__("func_80035D38");
int Actor1772_func_80035D84(void*,int) __asm__("func_80035D84");
int Actor1772_func_80035DDC(void*,int,int,int,int) __asm__("func_80035DDC");
int Actor1772_func_80036220(void*,void*,int,int) __asm__("func_80036220");
int Actor1772_func_8003636C(int,int) __asm__("func_8003636C");
int Actor1772_func_80036518(void*,void*,int*) __asm__("func_80036518");
void Actor1772_func_80037014(void*) __asm__("func_80037014");
int Actor1772_func_80037A60(void*,void*,int,int,int) __asm__("func_80037A60");
int Actor1772_func_8004E880(int,int,int) __asm__("func_8004E880");
void Actor1772_func_8004F178(void*,void*) __asm__("func_8004F178");
int Actor1772_func_8004F264(int,int) __asm__("func_8004F264");
int Actor1772_func_8004F334(void*,void*) __asm__("func_8004F334");
void Actor1772_func_80055D24(void*,int) __asm__("func_80055D24");
int Actor1772_func_80055E84(void*) __asm__("func_80055E84");
void Actor1772_func_8005629C(void*) __asm__("func_8005629C");
extern int Actor1772_D_800658A0 __asm__("D_800658A0");
extern int Actor1772_D_80065920 __asm__("D_80065920");
extern int Actor1772_D_8006C550 __asm__("D_8006C550");
extern int Actor1772_D_8006C770 __asm__("D_8006C770");
extern int Actor1772_D_8006E53C __asm__("D_8006E53C");
extern int Actor1772_D_80070328 __asm__("D_80070328");
void func_level_22_8007BFAC(void* input) {
    register int originalStackSample8 __asm__("$8");
    register int resultWord2 __asm__("$2"),intermediateWord3 __asm__("$3"),argumentWord4 __asm__("$4"),argumentWord5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7");
    register int ownerAddress18 __asm__("$18"),privateAddress19 __asm__("$19"),retainedPositionSpeedOrPath16 __asm__("$16"),retainedModeOrRemainder17 __asm__("$17"),retainedDistanceOrCursor20 __asm__("$20"),candidateCursorOrActor21 __asm__("$21"),linkedActorAddress22 __asm__("$22"),nearbyIndexOrOne23 __asm__("$23");
    struct{
        int sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C;
    }
    originalFrame;
    int pathPointIndex;
    int temporaryWord26;
    int privateMode34;
    int temporaryWord2;
    int selectedPrivateVectorAddress;
    int temporaryWord4;
    int verticalDifference;
    int initialHelperPredicate;
    int temporaryWord9;
    int temporaryWord10;
    int groundHelperResult;
    int pathPointFlags;
    int privateModeForPathEvent;
    int temporaryWord23;
    int temporaryWord24;
    int incrementedCounter1E;
    int temporaryWord6;
    int nextPrivateIndex18;
    int privateIndexForPathEvent;
    int selectedActorState48;
    int linkedActorState48ForMode;
    int ownerState48;
    int temporaryWord22;
    int pathHeaderForPreviousFlags;
    int previousPathPointAddress;
    int pathHeaderForFlags;
    ownerAddress18=(int)input;
    Actor1772Keep(ownerAddress18);
    retainedPositionSpeedOrPath16=ownerAddress18+12;
    argumentWord4=retainedPositionSpeedOrPath16;
    Actor1772Keep(argumentWord4);
    nearbyIndexOrOne23=0;
    privateAddress19=Actor1772Field(ownerAddress18,int*,0);
    candidateCursorOrActor21=0;
    intermediateWord3=Actor1772Field(privateAddress19,int*,4);
    retainedDistanceOrCursor20=privateAddress19;
    resultWord2=intermediateWord3*88;
    intermediateWord3=Actor1772_D_8006C550;
    linkedActorAddress22=intermediateWord3+resultWord2;
    retainedModeOrRemainder17=Actor1772Field(linkedActorAddress22,int*,0);
    resultWord2=Actor1772_func_8004F334(argumentWord4,linkedActorAddress22+12);
    argumentWord4=retainedPositionSpeedOrPath16;
    argumentWord5=(int)&Actor1772_D_80070328;
    __asm__ volatile("":"=r"(argumentWord4),"=r"(argumentWord5):"0"(argumentWord4),"1"(argumentWord5):"memory");
    originalFrame.sp48=resultWord2;
    resultWord2=Actor1772_func_8004F334(argumentWord4,argumentWord5);
    argumentWord7=Actor1772Field(linkedActorAddress22,int*,12);
    argumentWord4=Actor1772Field(ownerAddress18,int*,12);
    intermediateWord3=Actor1772Field(linkedActorAddress22,int*,16);
    argumentWord5=Actor1772Field(ownerAddress18,int*,16);
    argumentWord6=0;
    originalFrame.sp50=resultWord2;
    argumentWord4=argumentWord7-argumentWord4;
    retainedModeOrRemainder17=Actor1772Field(retainedModeOrRemainder17,int*,28);
    argumentWord5=intermediateWord3-argumentWord5;
    originalFrame.sp58=retainedModeOrRemainder17;
    resultWord2=Actor1772_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
    retainedModeOrRemainder17=Actor1772_func_8004F264(resultWord2,Actor1772Field(ownerAddress18,unsigned char*,70))>=65;
    initialHelperPredicate=Actor1772_func_80036220(retainedPositionSpeedOrPath16,privateAddress19+128,0,0)==0;
scanFourOriginalLinkedActors:
    if(Actor1772_func_8004F334(ownerAddress18+12,Actor1772_D_8006C550+Actor1772Field(retainedDistanceOrCursor20,int*,36)*88+12)<700){
        intermediateWord3=Actor1772Field(retainedDistanceOrCursor20,int*,36);
        Actor1772Keep(intermediateWord3);
        resultWord2=intermediateWord3*88;
        intermediateWord3=Actor1772_D_8006C550;
        resultWord2+=intermediateWord3;
        intermediateWord3=Actor1772Field(resultWord2,unsigned char*,72);
        resultWord2=1;
        if(intermediateWord3==resultWord2)goto originalFoundNearby;
    }
    candidateCursorOrActor21++;
    retainedDistanceOrCursor20+=4;
    if(candidateCursorOrActor21<4)goto scanFourOriginalLinkedActors;
originalNearbyDone:
    resultWord2=Actor1772Field(privateAddress19,short*,28);
    if(!resultWord2)goto originalAfterByteFlags;
    resultWord2=1;
    intermediateWord3=Actor1772Field(linkedActorAddress22,unsigned char*,72);
    if(intermediateWord3!=resultWord2)goto originalAfterByteFlags;
    resultWord2=4;
    Actor1772Field(privateAddress19,short*,28)=0;
    intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
    argumentWord4=ownerAddress18;
    if(intermediateWord3!=resultWord2)goto originalByteFlag2;
    resultWord2=114;
    Actor1772Keep(resultWord2);
    Actor1772_D_8006C770=0;
    Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
    resultWord2=3;
    goto originalSetByte3D;
originalFoundNearby:
    nearbyIndexOrOne23=candidateCursorOrActor21+1;
    goto originalNearbyDone;
originalByteFlag2:
    resultWord2=2;
    if(intermediateWord3!=resultWord2)goto originalAfterByteFlags;
    resultWord2=114;
    Actor1772Keep(resultWord2);
    Actor1772_D_8006C770=0;
    Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
    resultWord2=1;
originalSetByte3D:
    Actor1772Field(ownerAddress18,unsigned char*,61)=resultWord2;
    Actor1772Field(ownerAddress18,signed char*,63)=0;
    Actor1772_func_80035734(argumentWord4);
originalAfterByteFlags:
    if ((Actor1772Field(privateAddress19, int *, 0x58) != 0) && ((Actor1772Field((int)&Actor1772_D_80070328, int *, 0x20C) = 0x10000002, (Actor1772_func_800359A4(privateAddress19 + 0x58, 4) != 0)) || (Actor1772_D_8006E53C & 0x810))) {
        Actor1772Field(privateAddress19, int *, 0x58) = 0;
        Actor1772_func_80013B7C(1);
    }
    ownerState48 = Actor1772Field(ownerAddress18, unsigned char *, 0x48);
    switch (ownerState48) {
    case 0:
        retainedPositionSpeedOrPath16 = 0;
        if (Actor1772Field(ownerAddress18, int *, 0x18) != 0) {
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0xAU;
            Actor1772_func_80034F40(ownerAddress18, 0xA);
        }
        intermediateWord3=nearbyIndexOrOne23-1;
        if(!nearbyIndexOrOne23)goto originalAfterNearbySelector;
        Actor1772Keep(intermediateWord3);
        resultWord2=1;
        if(intermediateWord3==resultWord2)goto originalAfterNearbySelector;
        resultWord2=intermediateWord3<2;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto originalNearbySelectorHigh;
        if(intermediateWord3==0)goto originalNearbySelectorZero;
        goto originalAfterNearbySelector;
    originalNearbySelectorHigh:
        resultWord2=2;
        if(intermediateWord3==resultWord2)goto originalAfterNearbySelector;
        resultWord2=3;
        if(intermediateWord3==resultWord2)goto originalNearbySelector3;
        goto originalAfterNearbySelector;
        originalNearbySelectorZero:retainedPositionSpeedOrPath16=1;
        goto originalAfterNearbySelector;
    originalNearbySelector3:
        Actor1772Keep(retainedPositionSpeedOrPath16);
        intermediateWord3=Actor1772Field(ownerAddress18,short*,56);
        resultWord2=Actor1772Field(ownerAddress18,int*,20);
        argumentWord4=Actor1772Field(linkedActorAddress22,int*,20);
        intermediateWord3=resultWord2-intermediateWord3;
        resultWord2=intermediateWord3-argumentWord4;
        if(resultWord2<0)goto originalNearbyHeightNegative;
        resultWord2=resultWord2<800;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto originalAfterNearbySelector;
        __asm__ volatile(""::"r"(resultWord2),"r"(ownerAddress18):"memory");
        retainedPositionSpeedOrPath16=0;
        goto originalAfterNearbySelector;
    originalNearbyHeightNegative:
        resultWord2=argumentWord4-intermediateWord3;
        resultWord2=resultWord2<800;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto originalAfterNearbySelector;
        retainedPositionSpeedOrPath16=0;
    originalAfterNearbySelector:
        privateMode34 = Actor1772Field(privateAddress19, int *, 0x34);
        if ((privateMode34 == 1) && (Actor1772Field(privateAddress19, unsigned int *, 0x18) == 4)) {
            retainedModeOrRemainder17 = 0;
            if (Actor1772Field(((Actor1772Field(privateAddress19, int *, 0x28) * 0x58) + Actor1772_D_8006C550), unsigned char *, 0x48) == privateMode34) {
                Actor1772Keep(linkedActorAddress22);
                argumentWord4=linkedActorAddress22+12;
                if (Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) == 0) {
                    resultWord2=Actor1772_func_80036220(argumentWord4,privateAddress19+92,0,512);
                    Actor1772Keep(linkedActorAddress22);
                    argumentWord4=linkedActorAddress22+12;
                    if(resultWord2) {
                        resultWord2 = 0x1C;
                        if (nearbyIndexOrOne23 == 0) {
                            Actor1772Field(Actor1772Field((Actor1772Field(privateAddress19, int *, 0x28) * 0x58) + Actor1772_D_8006C550,int*,0), int *, 8) = 0xB4;
                            resultWord2=Actor1772Field(privateAddress19,int*,24);
                            resultWord2++;
                            Actor1772Keep(resultWord2);
                            Actor1772Field(privateAddress19,int*,24)=resultWord2;
                            goto prepareOriginalOwnerState23;
                        }
                        goto clearSubstateStoreStateAndReturn;
                    }
                }
                goto testOriginalMovementWithoutFlag;
            }
            Actor1772Keep(linkedActorAddress22);
            argumentWord4=linkedActorAddress22+12;
        testOriginalMovementWithoutFlag:
            if(Actor1772_func_80036220(argumentWord4,privateAddress19+92,0,0)!=0)goto originalSetMovementFlag;
            originalStackSample8=originalFrame.sp48;
            resultWord2=originalStackSample8<14337;
            Actor1772Keep(resultWord2);
            if(!resultWord2){
                originalSetMovementFlag:retainedPositionSpeedOrPath16=1;
            }
            goto testOriginalMovementAndHeight;
        }
    testOriginalMovementAndHeight:
        if (Actor1772Field(privateAddress19, short *, 0x1C) == 0) {
            if (retainedPositionSpeedOrPath16 == 0) {
                temporaryWord22 = Actor1772Field(linkedActorAddress22, unsigned char *, 0x48);
                if ((temporaryWord22 == 0) || ((retainedModeOrRemainder17 != 0) && (temporaryWord22 == 3))) {
                    temporaryWord2 = Actor1772Field(linkedActorAddress22, int *, 0x14);
                    temporaryWord23 = Actor1772Field(ownerAddress18, int *, 0x14) - Actor1772Field(ownerAddress18, short *, 0x38);
                    temporaryWord9 = temporaryWord23 - temporaryWord2;
                    if (temporaryWord9 >= 0) {
                        if (temporaryWord9 >= 0x578) {
                        }
                        else {
                            goto prepareOriginalVisibilityVectors;
                        }
                    }
                    else if ((temporaryWord2 - temporaryWord23) < 0x578) {
                    prepareOriginalVisibilityVectors:
                        Actor1772_func_8004F178(&originalFrame.sp20, linkedActorAddress22 + 0xC);
                        originalFrame.sp28 += 0x190;
                        Actor1772_func_8004F178(&originalFrame.sp30, ownerAddress18 + 0xC);
                        originalFrame.sp38 += 0x190;
                        if (Actor1772_func_80013E38(&originalFrame.sp30, &originalFrame.sp20, 0) != 0) {
                            resultWord2=((originalStackSample8=originalFrame.sp50) < 0x152D);
                            Actor1772Keep(resultWord2);
                            if(resultWord2) {
                                resultWord2=((originalStackSample8=originalFrame.sp48) < 0xC01);
                                Actor1772Keep(resultWord2);
                                if(resultWord2) {
                                    if ((retainedModeOrRemainder17 == 0) || (Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) != 0)) {
                                        if (((originalStackSample8=originalFrame.sp58) != 0)) {
                                            goto enterOriginalState20AfterDistance;
                                        }
                                    }
                                    else {
                                        goto enterOriginalState20;
                                    }
                                }
                                else {
                                enterOriginalState20AfterDistance:
                                    goto enterOriginalState20;
                                }
                            }
                            else {
                            enterOriginalState20:
                                Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
                                Actor1772Field(privateAddress19, unsigned short *, 0x1E) = 0U;
                                Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x14U;
                            }
                        }
                    }
                }
            }
            if (Actor1772Field(privateAddress19, short *, 0x1C) != 0) {
                goto testOriginalPlayerDistance;
            }
            goto updateOriginalState0;
        }
    testOriginalPlayerDistance:
        resultWord2=((originalStackSample8=originalFrame.sp50) < 0x12D4);
        Actor1772Keep(resultWord2);
        if(resultWord2) {
            resultWord2 = ((Actor1772Field(ownerAddress18, int *, 0x14) - Actor1772Field(ownerAddress18, short *, 0x38)) - Actor1772Field((int)&Actor1772_D_80070328, int *, 8)) + Actor1772Field((int)&Actor1772_D_80070328, int *, 0x44);
            if (resultWord2 < 0) {
                resultWord2 = -resultWord2;
            }
            if ((resultWord2 < 0x400) && (Actor1772_func_8004F264(Actor1772Field(ownerAddress18, unsigned char *, 0x46), Actor1772_func_8004E880(Actor1772Field((int)&Actor1772_D_80070328, int *, 0) - Actor1772Field(ownerAddress18, int *, 0xC), Actor1772Field((int)&Actor1772_D_80070328, int *, 4) - Actor1772Field(ownerAddress18, int *, 0x10), 0)) < 8)) {
                Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 8U;
                Actor1772_func_80034F40(ownerAddress18, 8);
                return;
            }
            goto updateOriginalState0;
        }
    updateOriginalState0:
        Actor1772_func_80037014(ownerAddress18);
        Actor1772_func_8005629C(ownerAddress18);
        if (Actor1772Field(((Actor1772Field(((Actor1772Field(privateAddress19, int *, 0x34) * 4) + privateAddress19), int *, 0x38) * 0x58) + Actor1772_D_8006C550), unsigned char *, 0x48) != 0) {
            Actor1772Field(privateAddress19, int *, 0x58) = 0x78;
            selectedPrivateVectorAddress = Actor1772Field(Actor1772Field(((Actor1772Field(privateAddress19, int *, 0x34) * 4) + privateAddress19), void **, 0x48), int *, 0xC);
            Actor1772_func_80013AE4(selectedPrivateVectorAddress, selectedPrivateVectorAddress + 0x10);
            Actor1772Field(privateAddress19, int *, 0x34) = (int) (Actor1772Field(privateAddress19, int *, 0x34) + 1);
            Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
            if (Actor1772_func_8004F334(ownerAddress18 + 0xC, linkedActorAddress22 + 0xC) < 0x7D0) {
                temporaryWord4 = Actor1772Field(linkedActorAddress22, int *, 0x14);
                temporaryWord24 = Actor1772Field(ownerAddress18, int *, 0x14) - Actor1772Field(ownerAddress18, short *, 0x38);
                temporaryWord10 = temporaryWord24 - temporaryWord4;
                if (temporaryWord10 >= 0) {
                    if (temporaryWord10 >= 0x100) {
                        resultWord2=23;
                        goto storeOriginalStateAndReturn;
                    }
                    goto testOriginalLinkedActorFlags;
                }
                if ((temporaryWord4 - temporaryWord24) < 0x100) {
                testOriginalLinkedActorFlags:
                    if (Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) == 0) {
                        if ((Actor1772Field(ownerAddress18, unsigned char *, 0x4D) == 0) && (Actor1772Field(linkedActorAddress22, unsigned char *, 0x4D) == 0)) {
                            Actor1772Field(privateAddress19, short *, 0x1C) = 1;
                            Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) = 0x1EU;
                            goto prepareOriginalReturnState23;
                        }
                        goto returnOriginalState26;
                    }
                    resultWord2=23;
                    goto storeOriginalStateAndReturn;
                }
                resultWord2=23;
                goto storeOriginalStateAndReturn;
            }
            resultWord2=23;
            goto storeOriginalStateAndReturn;
        }
        if (Actor1772_func_8004F264(Actor1772Field(ownerAddress18, unsigned char *, 0x46), Actor1772_func_8004E880(Actor1772Field((int)&Actor1772_D_80070328, int *, 0) - Actor1772Field(ownerAddress18, int *, 0xC), Actor1772Field((int)&Actor1772_D_80070328, int *, 4) - Actor1772Field(ownerAddress18, int *, 0x10), 0)) >= 0xD) {
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x15U;
            return;
        }
        resultWord2=Actor1772Field(privateAddress19,short*,28);
        if(resultWord2)goto originalTimerActive;
        resultWord2=Actor1772_D_8006C770;
        if(!resultWord2)goto runOriginalCommonTail;
        resultWord2=Actor1772Field(privateAddress19,short*,32);
        __asm__ volatile("":::"$4","memory");
        argumentWord4=ownerAddress18;
        if(resultWord2)goto originalTimerZeroDecrement;
        argumentWord5=11;
        goto originalTimerRandom;
        originalTimerZeroDecrement:argumentWord5=0;
        goto originalTimerDecrement;
    originalTimerActive:
        resultWord2=Actor1772_D_8006C770;
        if(!resultWord2)goto runOriginalCommonTail;
        resultWord2=Actor1772Field(privateAddress19,short*,32);
        __asm__ volatile("":::"$4","memory");
        argumentWord4=ownerAddress18;
        if(resultWord2)goto originalTimerActiveDecrement;
        argumentWord5=7;
    originalTimerRandom:
        Actor1772_func_80034F40(argumentWord4,argumentWord5);
        resultWord2=Actor1772_func_8003636C(1,3);
        Actor1772Field(privateAddress19,short*,32)=resultWord2;
        goto runOriginalCommonTail;
        originalTimerActiveDecrement:argumentWord5=6;
    originalTimerDecrement:
        Actor1772_func_80034F40(argumentWord4,argumentWord5);
        resultWord2=Actor1772Field(privateAddress19,unsigned short*,32);
        resultWord2--;
        Actor1772Field(privateAddress19,short*,32)=resultWord2;
        goto runOriginalCommonTail;
        default:goto runOriginalCommonTail;
    case 8:
        if ((Actor1772Field(privateAddress19, short *, 0x1C) != 0) && (Actor1772_func_80055E84(ownerAddress18) >= 8)) {
            Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) = 0x20U;
            Actor1772Field(privateAddress19, short *, 0x1C) = 0;
        }
        goto originalGlobalFlag10;
    case 23:
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,0x49);
        Actor1772Keep(intermediateWord3);
        resultWord2=1;
        if(intermediateWord3==0)goto originalState23Zero;
        retainedModeOrRemainder17=50;
        if(intermediateWord3==resultWord2)goto originalState23Nonzero;
        goto runOriginalCommonTail;
        originalState23Zero:{
            argumentWord4=ownerAddress18+12;
            argumentWord5=Actor1772Field(privateAddress19,int*,0);
            Actor1772_func_80036518(argumentWord4,argumentWord5,&originalFrame.sp40);
            argumentWord6=0;
            intermediateWord3=Actor1772Field(privateAddress19,int*,0);
            resultWord2=originalFrame.sp40;
            __asm__ volatile("":::"memory");
            argumentWord4=Actor1772Field(ownerAddress18,int*,12);
            argumentWord5=Actor1772Field(ownerAddress18,int*,16);
            intermediateWord3=Actor1772Field(intermediateWord3,int*,12);
            resultWord2*=16;
            resultWord2+=intermediateWord3;
            intermediateWord3=Actor1772Field(resultWord2,int*,0);
            resultWord2=Actor1772Field(resultWord2,int*,4);
            argumentWord4=intermediateWord3-argumentWord4;
            argumentWord5=resultWord2-argumentWord5;
            resultWord2=Actor1772_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
            argumentWord7=Actor1772Field(privateAddress19,int*,0);
            argumentWord5=originalFrame.sp40;
            argumentWord4=Actor1772Field(argumentWord7,short*,0);
            intermediateWord3=argumentWord5+1;
            retainedModeOrRemainder17=intermediateWord3%argumentWord4;
            __asm__ volatile(""::"r"(retainedModeOrRemainder17):"$6","memory");
            argumentWord6=0;
            __asm__ volatile("":"=r"(argumentWord6):"0"(argumentWord6):"memory");
            retainedPositionSpeedOrPath16=resultWord2;
            argumentWord4=Actor1772Field(argumentWord7,int*,12);
            __asm__ volatile("":::"memory");
            argumentWord5*=16;
            argumentWord5+=argumentWord4;
            __asm__ volatile("":"=r"(argumentWord5):"0"(argumentWord5),"r"(argumentWord4):"memory");
            intermediateWord3=retainedModeOrRemainder17*16;
            intermediateWord3+=argumentWord4;
            argumentWord7=Actor1772Field(intermediateWord3,int*,0);
            argumentWord4=Actor1772Field(argumentWord5,int*,0);
            intermediateWord3=Actor1772Field(intermediateWord3,int*,4);
            argumentWord5=Actor1772Field(argumentWord5,int*,4);
            argumentWord4=argumentWord7-argumentWord4;
            argumentWord5=intermediateWord3-argumentWord5;
            resultWord2=Actor1772_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
            resultWord2=Actor1772_func_8004F264(resultWord2,retainedPositionSpeedOrPath16);
            resultWord2=resultWord2<65;
            if(resultWord2)goto originalUseFrameIndex;
            resultWord2=Actor1772Field(privateAddress19,int*,0);
            Actor1772Field(resultWord2,short*,2)=retainedModeOrRemainder17;
            goto originalIndexWritten;
        originalUseFrameIndex:
            intermediateWord3=Actor1772Field(privateAddress19,int*,0);
            resultWord2=originalFrame.sp40;
            Actor1772Field(intermediateWord3,short*,2)=resultWord2;
        originalIndexWritten:
            resultWord2=Actor1772Field(privateAddress19,int*,0);
            argumentWord4=ownerAddress18+12;
            Actor1772Field(privateAddress19,int*,120)=0;
            argumentWord5=Actor1772Field(resultWord2,short*,2);
            resultWord2=Actor1772Field(resultWord2,int*,12);
            argumentWord5*=16;
            argumentWord5=resultWord2+argumentWord5;
            resultWord2=Actor1772_func_8004F334(argumentWord4,argumentWord5);
            resultWord2=resultWord2<300;
            if(resultWord2){
                intermediateWord3=Actor1772Field(privateAddress19,int*,0);
                resultWord2=Actor1772Field(intermediateWord3,unsigned short*,2);
                resultWord2++;
                Actor1772Field(intermediateWord3,unsigned short*,2)=resultWord2;
            }
            Actor1772Field(privateAddress19,unsigned short*,30)=0;
            goto incrementOriginalOwnerSubstate;
        }
        originalState23Nonzero:{
            resultWord2=Actor1772Field(privateAddress19,short*,28);
            __asm__ volatile("":::"$3","memory");
            retainedPositionSpeedOrPath16=1;
            if(!resultWord2)goto original23AnimationElse;
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            resultWord2=2;
            argumentWord4=ownerAddress18;
            if(intermediateWord3==resultWord2)goto original23AnimationDone;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772_D_8006C770=0;
            Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
            resultWord2=2;
            goto original23AnimationStore;
        original23AnimationElse:
            resultWord2=Actor1772Field(ownerAddress18,unsigned char*,61);
            argumentWord4=ownerAddress18;
            if(resultWord2==retainedPositionSpeedOrPath16)goto original23AnimationDone;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772_D_8006C770=0;
            Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
            resultWord2=1;
        original23AnimationStore:
            Actor1772Field(ownerAddress18,unsigned char*,61)=resultWord2;
            Actor1772Field(ownerAddress18,signed char*,63)=0;
            Actor1772_func_80035734(argumentWord4);
        original23AnimationDone:
            incrementedCounter1E = Actor1772Field(privateAddress19, unsigned short *, 0x1E) + 0xA;
            Actor1772Field(privateAddress19, unsigned short *, 0x1E) = incrementedCounter1E;
            if ((short) incrementedCounter1E >= 0xA1) {
                Actor1772Field(privateAddress19, unsigned short *, 0x1E) = 0xA0U;
            }
            Actor1772Keep(retainedPositionSpeedOrPath16);
            if (Actor1772Field(privateAddress19, int *, 0x78) == 0) {
                retainedModeOrRemainder17 = 4;
            }
            else {
                retainedPositionSpeedOrPath16 |= 0x20000;
            }
            retainedPositionSpeedOrPath16 = Actor1772_func_80035A80(ownerAddress18, Actor1772Field(privateAddress19, void **, 0), 0x100, (short) Actor1772Field(privateAddress19, unsigned short *, 0x1E), 0, 4, retainedModeOrRemainder17, retainedPositionSpeedOrPath16);
            if (initialHelperPredicate != 0) {
                Actor1772_func_80037A60(ownerAddress18, privateAddress19 + 0x74, 4, 0x11, -0xC8);
            }
            resultWord2=(retainedPositionSpeedOrPath16&1);
            Actor1772Keep(resultWord2);
            if(resultWord2) {
                pathHeaderForFlags = Actor1772Field(privateAddress19, void **, 0);
                Actor1772Field(privateAddress19, int *, 0x78) = 1;
                pathPointIndex = Actor1772Field(pathHeaderForFlags, short *, 2);
                pathPointFlags = Actor1772Field(((pathPointIndex * 0x10) + Actor1772Field(pathHeaderForFlags, int *, 0xC)), int *, 0xC);
                if (pathPointFlags & 1) {
                    if (pathPointFlags & 0xFFFF0) {
                        resultWord2 = pathPointFlags & 0xFFFFE;
                    }
                    else {
                        resultWord2=17;
                        Actor1772Keep(resultWord2);
                        if(pathPointIndex!=resultWord2){
                            resultWord2=155;
                            goto originalPathFlagsReady;
                        }
                        resultWord2=100;
                    }
                originalPathFlagsReady:
                    Actor1772Field(privateAddress19, int *, 0x74) = resultWord2;
                }
                pathHeaderForPreviousFlags = Actor1772Field(privateAddress19, void **, 0);
                previousPathPointAddress = (Actor1772Field(pathHeaderForPreviousFlags, short *, 2) * 0x10) + Actor1772Field(pathHeaderForPreviousFlags, int *, 0xC);
                if (Actor1772Field(previousPathPointAddress, int *, -4) & 2) {
                    Actor1772Field(previousPathPointAddress, int *, -4) = 0;
                    privateModeForPathEvent = Actor1772Field(privateAddress19, int *, 0x34);
                    switch (privateModeForPathEvent) {
                    case 1:
                        privateIndexForPathEvent = Actor1772Field(privateAddress19, unsigned int *, 0x18);
                        switch (privateIndexForPathEvent) {
                        case 0:
                        case 1:
                            resultWord2=Actor1772Field(privateAddress19,int*,24)*4+privateAddress19;
                            intermediateWord3=Actor1772Field(resultWord2,int*,8);
                            resultWord2=intermediateWord3*88;
                            intermediateWord3=Actor1772_D_8006C550;
                            resultWord2+=intermediateWord3;
                            intermediateWord3=1;
                            Actor1772Field(resultWord2,unsigned char*,73)=intermediateWord3;
                            resultWord2=24;
                            goto storeOriginalState24Or25;
                        case 2:
                            resultWord2=25;
                        storeOriginalState24Or25:
                            Actor1772Field(ownerAddress18,unsigned char*,73)=0;
                            Actor1772Field(ownerAddress18,unsigned char*,72)=resultWord2;
                            goto runOriginalCommonTail;
                        case 3:
                            resultWord2=Actor1772Field(privateAddress19,int*,24);
                            resultWord2++;
                            Actor1772Keep(resultWord2);
                            Actor1772Field(privateAddress19,int*,24)=resultWord2;
                        case 4:
                        case 6:
                            __asm__ volatile(""::"r"(ownerAddress18),"r"(privateAddress19):"memory");
                            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0U;
                            goto runOriginalCommonTail;
                        case 5:
                            if (Actor1772_func_80036220(ownerAddress18 + 0xC, privateAddress19 + 0x5C, 0, 0) != 0) {
                                resultWord2=Actor1772Field(privateAddress19,int*,24);
                                resultWord2++;
                                Actor1772Keep(resultWord2);
                                Actor1772Field(privateAddress19,int*,24)=resultWord2;
                                resultWord2 = 0x1A;
                                goto clearSubstateStoreStateAndReturn;
                            }
                            goto runOriginalCommonTail;
                        }
                        break;
                    case 2:
                        Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
                        Actor1772Field(privateAddress19, unsigned int *, 0x18) = 3U;
                        goto storeOriginalState27;
                    case 3:
                        temporaryWord6 = Actor1772Field(privateAddress19, unsigned int *, 0x18);
                        if (temporaryWord6 != privateModeForPathEvent) {
                            if (temporaryWord6 != 4) {
                            }
                            else {
                                goto storeOriginalState27;
                            }
                        }
                        else {
                            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x19U;
                        }
                        goto runOriginalCommonTail;
                    storeOriginalState27:
                        resultWord2=27;
                        Actor1772Field(ownerAddress18,unsigned char*,72)=resultWord2;
                        goto runOriginalCommonTail;
                    case 4:
                        Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x1DU;
                        return;
                    }
                }
                else {
                    goto runOriginalCommonTail;
                }
            }
            else {
                goto runOriginalCommonTail;
            }
        }
        break;
    case 24:
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,73);
        nearbyIndexOrOne23=1;
        __asm__("":"=r"(intermediateWord3),"=r"(nearbyIndexOrOne23):"0"(intermediateWord3),"1"(nearbyIndexOrOne23));
        retainedModeOrRemainder17=intermediateWord3&255;
        if(retainedModeOrRemainder17==nearbyIndexOrOne23)goto original24One;
        resultWord2=retainedModeOrRemainder17<2;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto original24High;
        if(retainedModeOrRemainder17==0){
            resultWord2=intermediateWord3+2;
            goto original24Zero;
        }
        resultWord2=intermediateWord3+2;
        __asm__ volatile(""::"r"(intermediateWord3),"r"(ownerAddress18):"memory");
        goto runOriginalCommonTail;
    original24High:
        resultWord2=2;
        if(retainedModeOrRemainder17==resultWord2){
            argumentWord4=ownerAddress18+12;
            goto original24Two;
        }
        argumentWord4=ownerAddress18+12;
        __asm__ volatile(""::"r"(argumentWord4),"r"(privateAddress19):"memory");
        goto runOriginalCommonTail;
    original24Zero:
        __asm__ volatile(""::"r"(resultWord2),"r"(nearbyIndexOrOne23):"memory");
        Actor1772Field(ownerAddress18,unsigned char*,73)=resultWord2;
        goto runOriginalCommonTail;
    original24One:
        if ((Actor1772Field(privateAddress19, short *, 0x1C) != 0) && (Actor1772_func_80055E84(ownerAddress18) >= 8)) {
            Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) = 0x20U;
            Actor1772Field(privateAddress19, short *, 0x1C) = 0;
        }
        __asm__ volatile(""::"r"(nearbyIndexOrOne23),"r"(candidateCursorOrActor21):"memory");
        resultWord2=Actor1772_D_8006C770;
        goto originalFlagResult;
    original24Two:
        resultWord2=Actor1772Field(privateAddress19,int*,24)*4+privateAddress19;
        __asm__ volatile(""::"r"(resultWord2):"$16","memory");
        intermediateWord3=Actor1772Field(resultWord2,int*,8);
        retainedPositionSpeedOrPath16=170;
        resultWord2=intermediateWord3*88;
        intermediateWord3=Actor1772_D_8006C550;
        candidateCursorOrActor21=intermediateWord3+resultWord2;
        retainedDistanceOrCursor20 = Actor1772_func_8004F334(argumentWord4, candidateCursorOrActor21 + 0xC);
        selectedActorState48 = Actor1772Field(candidateCursorOrActor21, unsigned char *, 0x48);
        if ((selectedActorState48 >= 0x80U) || (selectedActorState48 == 8)) {
            nextPrivateIndex18 = Actor1772Field(privateAddress19, unsigned int *, 0x18) + 1;
            Actor1772Field(privateAddress19, unsigned int *, 0x18) = nextPrivateIndex18;
            Actor1772Field(((Actor1772Field(((nextPrivateIndex18 * 4) + privateAddress19), int *, 8) * 0x58) + Actor1772_D_8006C550), signed char *, 0x49) = 1;
            goto prepareOriginalOwnerState23;
        }
        Actor1772Keep(retainedModeOrRemainder17);
        resultWord2=Actor1772Field(privateAddress19,short*,28);
        if(!resultWord2)goto original24AnimationElse;
        resultWord2=Actor1772Field(ownerAddress18,unsigned char*,61);
        argumentWord4=ownerAddress18;
        if(resultWord2==retainedModeOrRemainder17)goto original24AnimationDone;
        resultWord2=114;
        Actor1772Keep(resultWord2);
        Actor1772_D_8006C770=0;
        Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
        resultWord2=2;
        goto original24AnimationStore;
    original24AnimationElse:
        resultWord2=Actor1772Field(ownerAddress18,unsigned char*,61);
        argumentWord4=ownerAddress18;
        if(resultWord2==nearbyIndexOrOne23)goto original24AnimationDone;
        resultWord2=114;
        Actor1772Keep(resultWord2);
        Actor1772_D_8006C770=0;
        Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
        resultWord2=1;
    original24AnimationStore:
        Actor1772Field(ownerAddress18,unsigned char*,61)=resultWord2;
        Actor1772Field(ownerAddress18,signed char*,63)=0;
        Actor1772_func_80035734(argumentWord4);
    original24AnimationDone:
        Actor1772Keep(retainedPositionSpeedOrPath16);
        resultWord2=(retainedDistanceOrCursor20 < 0x640);
        Actor1772Keep(resultWord2);
        if(resultWord2) {
            retainedPositionSpeedOrPath16 = 0x28;
            goto prepareOriginalFinalDistanceClamp;
        }
        resultWord2=(retainedDistanceOrCursor20 < 0x834);
        Actor1772Keep(resultWord2);
        if(resultWord2) {
            retainedPositionSpeedOrPath16 -= 80;
            goto prepareOriginalFinalDistanceClamp;
        }
        resultWord2=retainedDistanceOrCursor20<2500;
        if(!resultWord2){
            resultWord2=retainedDistanceOrCursor20<3101;
            goto original24ClampApply;
        }
        retainedPositionSpeedOrPath16-=50;
    prepareOriginalFinalDistanceClamp:
        resultWord2=retainedDistanceOrCursor20<3101;
    original24ClampApply:
        argumentWord6=0;
        if(!resultWord2)retainedPositionSpeedOrPath16+=30;
        if (Actor1772_func_8003585C(ownerAddress18, Actor1772_func_8004E880(Actor1772Field(candidateCursorOrActor21, int *, 0xC) - Actor1772Field(ownerAddress18, int *, 0xC), Actor1772Field(candidateCursorOrActor21, int *, 0x10) - Actor1772Field(ownerAddress18, int *, 0x10), argumentWord6), 5, 0x28, 1, 0) != 0) {
            temporaryWord26 = retainedPositionSpeedOrPath16;
            Actor1772_func_80035DDC(ownerAddress18, temporaryWord26, 0, 0,35);
        }
        goto runOriginalCommonTail;
        break;
    case 25:
        argumentWord4=Actor1772Field(privateAddress19,int*,24);
        resultWord2=argumentWord4*4+privateAddress19;
        intermediateWord3=Actor1772Field(resultWord2,int*,8);
        resultWord2=intermediateWord3*88;
        intermediateWord3=Actor1772_D_8006C550;
        retainedPositionSpeedOrPath16=intermediateWord3+resultWord2;
        if ((unsigned char) Actor1772Field(retainedPositionSpeedOrPath16, unsigned char *, 0x48) >= 0x80U) {
            resultWord2=argumentWord4+1;
            Actor1772Keep(resultWord2);
            Actor1772Field(privateAddress19,int*,24)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
            if (Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) != 1) {
                if (Actor1772Field((int)&Actor1772_D_80070328, int *, 0x48) != 0x35) {
                    resultWord2=((originalStackSample8=originalFrame.sp48) < 0x898);
                    Actor1772Keep(resultWord2);
                    if(resultWord2) {
                        goto returnOriginalState26;
                    }
                    goto prepareOriginalReturnState23;
                }
                resultWord2=23;
                goto storeOriginalStateAndReturn;
            }
            goto prepareOriginalReturnState23;
        }
        goto original25Selector;
        returnOriginalState26:resultWord2=26;
        Actor1772Field(ownerAddress18,unsigned char*,72)=resultWord2;
        return;
        prepareOriginalReturnState23:resultWord2=23;
        storeOriginalStateAndReturn:Actor1772Field(ownerAddress18,unsigned char*,72)=resultWord2;
        return;
    original25Selector:
        argumentWord4=Actor1772Field(ownerAddress18,unsigned char*,73);
        resultWord2=1;
        __asm__("":"=r"(argumentWord4):"0"(argumentWord4),"r"(resultWord2));
        intermediateWord3=argumentWord4&255;
        if(intermediateWord3==resultWord2)goto original25One;
        resultWord2=intermediateWord3<2;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto original25High;
        if(intermediateWord3==0)goto original25Zero;
        goto runOriginalCommonTail;
        original25High:resultWord2=2;
        if(intermediateWord3==resultWord2)goto original25Two;
        goto runOriginalCommonTail;
    original25Zero:
        resultWord2=Actor1772Field(privateAddress19,short*,28);
        __asm__ volatile(""::"r"(resultWord2),"r"(retainedPositionSpeedOrPath16):"memory");
        if(!resultWord2)goto originalStateByte49;
        __asm__ volatile(""::"r"(retainedPositionSpeedOrPath16):"memory");
        goto originalAnimation8;
    original25One:
        resultWord2=Actor1772Field(privateAddress19,short*,28);
        if(resultWord2){
            __asm__ volatile(""::"r"(ownerAddress18),"r"(retainedPositionSpeedOrPath16):"memory");
            resultWord2=Actor1772_func_80055E84(ownerAddress18);
            resultWord2=resultWord2<8;
            if(!resultWord2){
                resultWord2=32;
                Actor1772Field(linkedActorAddress22,unsigned char*,72)=resultWord2;
                Actor1772Field(privateAddress19,short*,28)=0;
            }
        }
        __asm__ volatile(""::"r"(ownerAddress18),"r"(retainedPositionSpeedOrPath16):"memory");
        resultWord2=Actor1772_D_8006C770;
        goto originalFlagResult;
    original25Two:
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        resultWord2=9;
        argumentWord4=ownerAddress18;
        if(intermediateWord3!=resultWord2){
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772_D_8006C770=0;
            Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
            resultWord2=9;
            Actor1772Field(ownerAddress18,unsigned char*,61)=resultWord2;
            Actor1772Field(ownerAddress18,signed char*,63)=0;
            Actor1772_func_80035734(argumentWord4);
        }
        argumentWord6=0;
        goto originalCommonHeading25and27;
    case 27:
        argumentWord4=Actor1772Field(ownerAddress18,unsigned char*,73);
        resultWord2=1;
        __asm__("":"=r"(argumentWord4):"0"(argumentWord4),"r"(resultWord2));
        intermediateWord3=argumentWord4&255;
        if(intermediateWord3==resultWord2)goto original27One;
        resultWord2=intermediateWord3<2;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto original27High;
        if(intermediateWord3==0)goto original27Zero;
        goto runOriginalCommonTail;
        original27High:resultWord2=2;
        if(intermediateWord3==resultWord2)goto original27Two;
        goto runOriginalCommonTail;
    original27Zero:
        resultWord2=Actor1772Field(privateAddress19,short*,28);
        __asm__ volatile(""::"r"(resultWord2),"r"(linkedActorAddress22):"memory");
        if(resultWord2)goto originalAnimation8;
    originalStateByte49:
        resultWord2=argumentWord4+2;
        Actor1772Field(ownerAddress18,unsigned char*,73)=resultWord2;
        goto runOriginalCommonTail;
    originalAnimation8:
        __asm__ volatile(""::"r"(argumentWord4):"memory");
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        resultWord2=8;
        argumentWord4=ownerAddress18;
        if(intermediateWord3==resultWord2)goto incrementOriginalOwnerSubstate;
        resultWord2=114;
        Actor1772Keep(resultWord2);
        Actor1772_D_8006C770=0;
        Actor1772Field(ownerAddress18,signed char*,64)=resultWord2;
        resultWord2=8;
        Actor1772Field(ownerAddress18,unsigned char*,61)=resultWord2;
        Actor1772Field(ownerAddress18,signed char*,63)=0;
        Actor1772_func_80035734(argumentWord4);
        goto incrementOriginalOwnerSubstate;
    original27One:
        resultWord2=Actor1772Field(privateAddress19,short*,28);
        if(resultWord2){
            __asm__ volatile(""::"r"(privateAddress19),"r"(linkedActorAddress22):"memory");
            resultWord2=Actor1772_func_80055E84(ownerAddress18);
            resultWord2=resultWord2<8;
            if(!resultWord2){
                resultWord2=32;
                Actor1772Field(linkedActorAddress22,unsigned char*,72)=resultWord2;
                Actor1772Field(privateAddress19,short*,28)=0;
            }
        }
        __asm__ volatile(""::"r"(privateAddress19),"r"(linkedActorAddress22):"memory");
        resultWord2=Actor1772_D_8006C770;
        goto originalFlagResult;
    original27Two:
        resultWord2=Actor1772Field(privateAddress19,int*,52)*4+privateAddress19;
        intermediateWord3=Actor1772Field(resultWord2,int*,56);
        resultWord2=intermediateWord3*88;
        intermediateWord3=Actor1772_D_8006C550;
        retainedPositionSpeedOrPath16=intermediateWord3+resultWord2;
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"$2","memory");
        resultWord2=9;
        argumentWord4=ownerAddress18;
        if(intermediateWord3!=resultWord2) {
            Actor1772_D_8006C770 = 0;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 9U;
            Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
            Actor1772_func_80035734(argumentWord4);
        }
        if (Actor1772Field(retainedPositionSpeedOrPath16, unsigned char *, 0x48) != 0) {
            intermediateWord3=Actor1772Field(privateAddress19,int*,124);
            resultWord2=intermediateWord3*88;
            intermediateWord3=Actor1772_D_8006C550;
            intermediateWord3+=resultWord2;
            Actor1772Keep(intermediateWord3);
            resultWord2=1;
            Actor1772Field(intermediateWord3,unsigned char*,73)=resultWord2;
            Actor1772Field(privateAddress19, int *, 0x34) = (int) (Actor1772Field(privateAddress19, int *, 0x34) + 1);
            Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x17U;
        }
        argumentWord6=0;
        goto originalCommonHeading25and27;
    originalCommonHeading25and27:
        intermediateWord3=Actor1772Field(retainedPositionSpeedOrPath16,int*,12);
        argumentWord4=Actor1772Field(ownerAddress18,int*,12);
        resultWord2=Actor1772Field(retainedPositionSpeedOrPath16,int*,16);
        argumentWord5=Actor1772Field(ownerAddress18,int*,16);
        argumentWord4=intermediateWord3-argumentWord4;
        argumentWord5=resultWord2-argumentWord5;
        resultWord2=Actor1772_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
        Actor1772_func_8003585C(ownerAddress18,resultWord2,4,0,0,0);
        goto runOriginalCommonTail;
    case 29:
        intermediateWord3=Actor1772Field(privateAddress19,int*,124);
        resultWord2=intermediateWord3*88;
        intermediateWord3=Actor1772_D_8006C550;
        retainedPositionSpeedOrPath16=intermediateWord3+resultWord2;
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"$2","memory");
        resultWord2=3;
        argumentWord4=ownerAddress18;
        if(intermediateWord3!=resultWord2) {
            Actor1772_D_8006C770 = 0;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 3U;
            Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
            Actor1772_func_80035734(argumentWord4);
        }
        if (Actor1772_func_8003585C(ownerAddress18, Actor1772_func_8004E880(Actor1772Field(linkedActorAddress22, int *, 0xC) - Actor1772Field(ownerAddress18, int *, 0xC), Actor1772Field(linkedActorAddress22, int *, 0x10) - Actor1772Field(ownerAddress18, int *, 0x10), 0), 5, 0, 0, 0) != 0) {
            Actor1772Field(retainedPositionSpeedOrPath16, signed char *, 0x49) = 2;
            goto storeOriginalState30;
        }
        goto runOriginalCommonTail;
    case 30:
        if (Actor1772_D_8006C770 != 0) {
            if (Actor1772Field(privateAddress19, short *, 0x20) == 0) {
                Actor1772_func_80034F40(ownerAddress18, 9);
                Actor1772Field(privateAddress19, short *, 0x20) = Actor1772_func_8003636C(1, 3);
            }
            else {
                Actor1772_func_80034F40(ownerAddress18, 0xB);
                Actor1772Field(privateAddress19, short *, 0x20) = (short) ((unsigned short) Actor1772Field(privateAddress19, short *, 0x20) - 1);
            }
        }
        if (Actor1772Field(ownerAddress18, int *, 0x18) != 0) {
            resultWord2=0xA;
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
            argumentWord4=ownerAddress18;
            if(intermediateWord3!=resultWord2) {
                Actor1772_D_8006C770 = 0;
                resultWord2=114;
                Actor1772Keep(resultWord2);
                Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 0xAU;
                Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
                Actor1772_func_80035734(argumentWord4);
            }
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x1FU;
            return;
        }
        goto runOriginalCommonTail;
    case 31:
        if (Actor1772_D_8006C770 != 0) {
            resultWord2=0xB;
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
            argumentWord4=ownerAddress18;
            if(intermediateWord3!=resultWord2) {
                Actor1772_D_8006C770 = 0;
                resultWord2=114;
                Actor1772Keep(resultWord2);
                Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 0xBU;
                Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
                Actor1772_func_80035734(argumentWord4);
            }
        storeOriginalState30:
            resultWord2=30;
            Actor1772Field(ownerAddress18,unsigned char*,72)=resultWord2;
        }
        goto runOriginalCommonTail;
    case 20:
    case 26:
        linkedActorState48ForMode = Actor1772Field(linkedActorAddress22, unsigned char *, 0x48);
        if (linkedActorState48ForMode == 1) {
            if ((Actor1772Field(privateAddress19, int *, 0x34) == linkedActorState48ForMode) && (Actor1772Field(privateAddress19, unsigned int *, 0x18) == 3)) {
                Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
                Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x17U;
            }
            else {
                Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0U;
            }
        }
        retainedPositionSpeedOrPath16=Actor1772Field(ownerAddress18,unsigned char*,73);
        retainedModeOrRemainder17=1;
        __asm__("":"=r"(retainedPositionSpeedOrPath16),"=r"(retainedModeOrRemainder17):"0"(retainedPositionSpeedOrPath16),"1"(retainedModeOrRemainder17));
        if(retainedPositionSpeedOrPath16==retainedModeOrRemainder17)goto original20One;
        resultWord2=retainedPositionSpeedOrPath16<2;
        Actor1772Keep(resultWord2);
        if(!resultWord2)goto original20High;
        if(retainedPositionSpeedOrPath16==0)goto original20Zero;
        goto runOriginalCommonTail;
    original20High:
        resultWord2=2;
        if(retainedPositionSpeedOrPath16==resultWord2)goto original20Two;
        goto runOriginalCommonTail;
    original20Zero:
        Actor1772Keep(retainedPositionSpeedOrPath16);
        resultWord2=Actor1772Field(ownerAddress18,unsigned char*,61);
        argumentWord4=ownerAddress18;
        if(resultWord2!=retainedModeOrRemainder17) {
            Actor1772_D_8006C770 = 0;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 1U;
            Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
            Actor1772_func_80035734(argumentWord4);
        }
        if ((Actor1772_func_80036220(ownerAddress18 + 0xC, privateAddress19 + 0x5C, 0, 0) == 0) || (Actor1772_func_80037A60(ownerAddress18, privateAddress19 + 0x74, 4, 0x11, -0xC8) != 0)) {
            verticalDifference = Actor1772Field(linkedActorAddress22, int *, 0x14) - (Actor1772Field(ownerAddress18, int *, 0x14) - Actor1772Field(ownerAddress18, short *, 0x38));
            if(Actor1772Field(privateAddress19,int*,52)==retainedModeOrRemainder17){
                intermediateWord3=Actor1772Field(privateAddress19,int*,24);
                resultWord2=4;
                if(intermediateWord3!=resultWord2){
                    resultWord2=verticalDifference<601;
                    goto original20DistanceApply;
                }
                resultWord2=verticalDifference<1201;
                goto original20DistanceApply;
            }
            resultWord2=verticalDifference<601;
        original20DistanceApply:
            if (resultWord2 == 0) {
                Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 2U;
            }
            resultWord2=((originalStackSample8=originalFrame.sp48) < 0x2BC);
            Actor1772Keep(resultWord2);
            if(resultWord2) {
                if(initialHelperPredicate!=0){
                    resultWord2=Actor1772_func_80037A60(ownerAddress18,privateAddress19+0x74,4,0x11,-200);
                    originalFlagResult:if(!resultWord2)goto runOriginalCommonTail;
                }
            incrementOriginalOwnerSubstate:
                resultWord2=Actor1772Field(ownerAddress18,unsigned char*,73);
                resultWord2++;
                Actor1772Field(ownerAddress18,unsigned char*,73)=resultWord2;
                goto runOriginalCommonTail;
            }
            if (initialHelperPredicate != 0) {
                Actor1772_func_80037A60(ownerAddress18, privateAddress19 + 0x74, 4, 0x11, -0xC8);
            }
            if (Actor1772_func_8003585C(ownerAddress18, Actor1772_func_8004E880(Actor1772Field(linkedActorAddress22, int *, 0xC) - Actor1772Field(ownerAddress18, int *, 0xC), Actor1772Field(linkedActorAddress22, int *, 0x10) - Actor1772Field(ownerAddress18, int *, 0x10), 0), 5, 0, 0, 0) != 0) {
                resultWord2=Actor1772_func_80035D38(ownerAddress18);
                argumentWord4=Actor1772Field(ownerAddress18,short*,56);
                intermediateWord3=Actor1772Field(ownerAddress18,int*,20);
                retainedPositionSpeedOrPath16=intermediateWord3-argumentWord4;
                argumentWord4=(int)&originalFrame.sp20;
                if(retainedPositionSpeedOrPath16!=resultWord2)goto originalAfterHeightVector;
                Actor1772_func_8004F178(argumentWord4,ownerAddress18+12);
                resultWord2=Actor1772Field(ownerAddress18,unsigned char*,70);
                __asm__ volatile("":::"$4","memory");
                argumentWord4=(int)&originalFrame.sp20;
                resultWord2*=2;
                intermediateWord3=Actor1772Field((int)&Actor1772_D_80065920,short*,resultWord2);
                argumentWord5=4096;
                resultWord2=intermediateWord3*225;
                intermediateWord3=originalFrame.sp20;
                resultWord2>>=10;
                intermediateWord3+=resultWord2;
                originalFrame.sp20=intermediateWord3;
                intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,70);
                resultWord2=originalFrame.sp28;
                intermediateWord3*=2;
                intermediateWord3=Actor1772Field((int)&Actor1772_D_800658A0,short*,intermediateWord3);
                resultWord2+=1024;
                originalFrame.sp28=resultWord2;
                resultWord2=intermediateWord3*225;
                intermediateWord3=originalFrame.sp24;
                resultWord2>>=10;
                intermediateWord3+=resultWord2;
                originalFrame.sp24=intermediateWord3;
                resultWord2=Actor1772_func_8001A358(argumentWord4,argumentWord5);
                intermediateWord3=resultWord2-retainedPositionSpeedOrPath16;
                resultWord2=intermediateWord3<201;
                if(!resultWord2){
                    resultWord2=150;
                    Actor1772Field(privateAddress19,int*,116)=resultWord2;
                    resultWord2=intermediateWord3<-200;
                }
                else{
                    resultWord2=intermediateWord3<-200;
                }
                if(resultWord2){
                    resultWord2=100;
                    Actor1772Field(privateAddress19,int*,116)=resultWord2;
                }
            originalAfterHeightVector:
                resultWord2=((originalStackSample8=originalFrame.sp48) < 0x2BC);
                Actor1772Keep(resultWord2);
                if(!resultWord2) {
                    resultWord2=Actor1772Field(privateAddress19,unsigned short*,30);
                    resultWord2+=10;
                    Actor1772Field(privateAddress19,unsigned short*,30)=resultWord2;
                    resultWord2=(short)resultWord2;
                    resultWord2=resultWord2<151;
                    argumentWord4=ownerAddress18;
                    if(!resultWord2){
                        resultWord2=150;
                        Actor1772Field(privateAddress19,unsigned short*,30)=resultWord2;
                    }
                    argumentWord6=0;
                    argumentWord7=0;
                    argumentWord5=Actor1772Field(privateAddress19,short*,30);
                    Actor1772_func_80035DDC(argumentWord4,argumentWord5,argumentWord6,argumentWord7,33);
                }
            }
            goto runOriginalCommonTail;
        }
        return;
    original20One:
        retainedModeOrRemainder17 = Actor1772_func_80055E84(ownerAddress18);
        if (initialHelperPredicate != 0) {
            Actor1772_func_80037A60(ownerAddress18, privateAddress19 + 0x74, 4, 0x11, -0xC8);
        }
        if ((Actor1772Field(privateAddress19, short *, 0x1C) == 0) && (Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) != retainedPositionSpeedOrPath16) && (Actor1772Field(ownerAddress18, unsigned char *, 0x3C) == 5)) {
            resultWord2=retainedModeOrRemainder17<20;
            Actor1772Keep(resultWord2);
            if(!resultWord2){
                Actor1772Field(privateAddress19, short *, 0x1C) = 1;
                Actor1772Field(privateAddress19,unsigned short*,0x22)=(originalStackSample8=Actor1772Field(&originalFrame.sp58,unsigned short*,0));
                Actor1772Field(linkedActorAddress22, unsigned char *, 0x48) = 0x1EU;
            }
        }
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"$2","memory");
        resultWord2=5;
        argumentWord4=ownerAddress18;
        if(intermediateWord3!=resultWord2) {
            Actor1772_D_8006C770 = 0;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 5U;
            Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
            Actor1772_func_80035734(argumentWord4);
        }
        if (Actor1772_D_8006C770 != 0) {
            if (Actor1772Field(ownerAddress18, unsigned char *, 0x48) == 0x1A) {
                resultWord2=4;
                intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
                __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
                argumentWord4=ownerAddress18;
                if(intermediateWord3!=resultWord2) {
                    Actor1772_D_8006C770 = 0;
                    resultWord2=114;
                    Actor1772Keep(resultWord2);
                    Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                    Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 4U;
                    Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
                    Actor1772_func_80035734(argumentWord4);
                }
                prepareOriginalOwnerState23:resultWord2=23;
                clearSubstateStoreStateAndReturn:Actor1772Field(ownerAddress18,unsigned char*,73)=0;
                Actor1772Field(ownerAddress18,unsigned char*,72)=resultWord2;
                return;
            }
            if (Actor1772Field(privateAddress19,short*,0x22) != 0) {
                resultWord2=4;
                intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
                __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
                argumentWord4=ownerAddress18;
                if(intermediateWord3!=resultWord2) {
                    Actor1772_D_8006C770 = 0;
                    resultWord2=114;
                    Actor1772Keep(resultWord2);
                    Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                    Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 4U;
                    Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
                    Actor1772_func_80035734(argumentWord4);
                }
                Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0x16U;
                return;
            }
            goto clearOriginalStateAndAnimate;
        }
        goto runOriginalCommonTail;
    original20Two:
        resultWord2=9;
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
        argumentWord4=ownerAddress18;
        if(intermediateWord3!=resultWord2) {
            Actor1772_D_8006C770 = 0;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 9U;
            Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
            Actor1772_func_80035734(argumentWord4);
        }
        if (initialHelperPredicate != 0) {
            Actor1772_func_80037A60(ownerAddress18, privateAddress19 + 0x74, 4, 0x11, -0xC8);
        }
        if ((Actor1772Field(linkedActorAddress22, int *, 0x14) - (Actor1772Field(ownerAddress18, int *, 0x14) - Actor1772Field(ownerAddress18, short *, 0x38))) < 0x258) {
            Actor1772Field(ownerAddress18, unsigned char *, 0x49) = 0U;
        }
        goto runOriginalCommonTail;
        break;
    case 28:
        Actor1772_func_8004F178(&originalFrame.sp20, Actor1772Field(Actor1772Field(privateAddress19, void **, 0), int *, 0xC) + 0xD0);
        if (Actor1772_func_8004F334(ownerAddress18 + 0xC, &originalFrame.sp20) < 0x96) {
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0U;
            return;
        }
        resultWord2=1;
        intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
        __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
        argumentWord4=ownerAddress18;
        if(intermediateWord3!=resultWord2) {
            Actor1772_D_8006C770 = 0;
            resultWord2=114;
            Actor1772Keep(resultWord2);
            Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
            Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = 1U;
            Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
            Actor1772_func_80035734(argumentWord4);
        }
        if (Actor1772_func_8003585C(ownerAddress18, Actor1772_func_8004E880(originalFrame.sp20 - Actor1772Field(ownerAddress18, int *, 0xC), originalFrame.sp24 - Actor1772Field(ownerAddress18, int *, 0x10), 0), 5, 0, 0, 0) != 0) {
            Actor1772_func_80035DDC(ownerAddress18,0xAA,0,0,33);
            goto runOriginalCommonTail;
        }
        goto runOriginalCommonTail;
    case 22:
        resultWord2=Actor1772Field(privateAddress19,short*,34)*4;
        resultWord2=privateAddress19+resultWord2;
        intermediateWord3=Actor1772Field(resultWord2,int*,32);
        resultWord2=intermediateWord3*88;
        intermediateWord3=Actor1772_D_8006C550;
        retainedPositionSpeedOrPath16=intermediateWord3+resultWord2;
        if (Actor1772_func_8004F334(ownerAddress18 + 0xC, retainedPositionSpeedOrPath16 + 0xC) < 0x96) {
            Actor1772Field(privateAddress19, unsigned short *, 0x22) = 0U;
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0U;
            return;
        }
        if (Actor1772Field(privateAddress19, short *, 0x1C) != 0) {
            resultWord2=4;
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
            argumentWord4=ownerAddress18;
            if(intermediateWord3!=resultWord2) {
                Actor1772_D_8006C770 = 0;
                resultWord2=114;
                Actor1772Keep(resultWord2);
                Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                resultWord2 = 4;
                goto storeOriginalState22Animation;
            }
        }
        else {
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"$2","memory");
            resultWord2=3;
            argumentWord4=ownerAddress18;
            if(intermediateWord3!=resultWord2){
                Actor1772_D_8006C770 = 0;
                resultWord2=114;
                Actor1772Keep(resultWord2);
                Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                resultWord2 = 3;
            storeOriginalState22Animation:
                Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = resultWord2;
                Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
                Actor1772_func_80035734(argumentWord4);
            }
        }
        if (Actor1772_func_8003585C(ownerAddress18, Actor1772_func_8004E880(Actor1772Field(retainedPositionSpeedOrPath16, int *, 0xC) - Actor1772Field(ownerAddress18, int *, 0xC), Actor1772Field(retainedPositionSpeedOrPath16, int *, 0x10) - Actor1772Field(ownerAddress18, int *, 0x10), 0), 5, 0, 0, 0) != 0) {
            Actor1772_func_80035DDC(ownerAddress18,0x50,0,0,33);
            goto runOriginalCommonTail;
        }
        goto runOriginalCommonTail;
    case 21:
        if (Actor1772Field(privateAddress19, short *, 0x1C) != 0) {
            resultWord2=4;
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"memory");
            argumentWord4=ownerAddress18;
            if(intermediateWord3!=resultWord2) {
                Actor1772_D_8006C770 = 0;
                resultWord2=114;
                Actor1772Keep(resultWord2);
                Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                resultWord2 = 4;
                goto storeOriginalState21Animation;
            }
        }
        else {
            intermediateWord3=Actor1772Field(ownerAddress18,unsigned char*,61);
            __asm__ volatile("":"=r"(intermediateWord3):"0"(intermediateWord3):"$2","memory");
            resultWord2=3;
            argumentWord4=ownerAddress18;
            if(intermediateWord3!=resultWord2){
                Actor1772_D_8006C770 = 0;
                resultWord2=114;
                Actor1772Keep(resultWord2);
                Actor1772Field(ownerAddress18,signed char*,0x40)=resultWord2;
                resultWord2 = 3;
            storeOriginalState21Animation:
                Actor1772Field(ownerAddress18, unsigned char *, 0x3D) = resultWord2;
                Actor1772Field(ownerAddress18, signed char *, 0x3F) = 0;
                Actor1772_func_80035734(argumentWord4);
            }
        }
        if (Actor1772_func_8003573C(ownerAddress18, 4, 0, 0) != 0) {
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0U;
        }
        goto runOriginalCommonTail;
    case 10:
    originalGlobalFlag10:
        if (Actor1772_D_8006C770 != 0) {
        clearOriginalStateAndAnimate:
            Actor1772Field(ownerAddress18, unsigned char *, 0x48) = 0U;
            Actor1772_func_80034F40(ownerAddress18, 0);
        }
        goto runOriginalCommonTail;
    }
runOriginalCommonTail:
    if ((Actor1772Field(ownerAddress18, unsigned char *, 0x48) != 0x17) && (Actor1772Field(ownerAddress18, unsigned char *, 0x48) != 0x14) && (Actor1772Field(ownerAddress18, unsigned char *, 0x48) != 0x1A)) {
        groundHelperResult = Actor1772_func_80035D84(ownerAddress18, 0x200);
        if (groundHelperResult != 0) {
            Actor1772Field(ownerAddress18, int *, 0x14) = (int) (groundHelperResult + Actor1772Field(ownerAddress18, short *, 0x38));
            Actor1772_func_8005629C(ownerAddress18);
        }
    }
    if (Actor1772Field(ownerAddress18, int *, 0x14) < 0x3000) {
        Actor1772Field(ownerAddress18, int *, 0x14) = 0x4C00;
        Actor1772Field(ownerAddress18, int *, 0x14) = Actor1772_func_8001A358(ownerAddress18 + 0xC, 0x2800);
    }
    Actor1772_func_80055D24(ownerAddress18, 2);
    Actor1772Field(ownerAddress18, int *, 0x18) = 0;
    return;
}
#undef Actor1772Field
#undef Actor1772Keep


typedef struct { unsigned char reserved00[2]; unsigned char mode,reserved03,reserved04,byte05,reserved06,byte07; unsigned char reserved08[0x18]; int state20; } DecodedCallbackMergedTag;
extern unsigned char D_80071581,D_80066FCC[],D_80070300[];
extern int D_8006E53C,D_8006E344;
int func_80037BBC(Moby*,int);
void func_800512E4(Moby*,int,int);
extern int D_8006C640;
extern unsigned char D_8007159A;
void func_80055B18(Moby*);
/* USA SCUS-94467 Rev 0: level22 0x8007DB5C..0x8007DCF4,
 * level11 0x80079B64..0x80079CFC, 102 words each.
 * Baselines: verified level13 callback and level15 removal guard.
 * Per-copy class/flag/table index values come from the original assembly.
 * Tag bytes and state word preserve access widths, with no inferred timing
 * or dialogue/SFX meaning. Producers and helper semantic chains remain open.
 * AI generated; not yet human reviewed.
 */
void func_level_22_8007DB5C(Moby* argument) {
    int flags = D_8006C640;
    register Moby* moby __asm__("$17") = argument;
    register DecodedCallbackMergedTag* tag __asm__("$16") = moby->mobyTag;
    if (!flags && moby->mobyClass == 0x220 && !D_8007159A) {
        func_80055B18(moby);
        return;
    }
    switch(moby->state) {
    case 0:
        if (moby->mobyClass == 0x2AC) {
            if(!D_80071581)tag->mode=0;
            else {
                register int selected __asm__("$2")=D_80070300[D_80066FCC[0x1A]]&1;
                __asm__("" : "=r"(selected) : "0"(selected));
                if(!selected)selected=1;else selected=2;
                __asm__("" : "=r"(selected) : "0"(selected));
                tag->mode=selected;
            }
        }
        if (tag->mode == 2) tag->byte05 = 0;
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
                func_800512E4(moby, 0, 0);
                moby->state = 1;
            } else tag->byte07=0;
        }
        break;
    case 1:
        if (D_8006E344 != 1) {
            tag->state20 = 1;
            moby->state = 0;
        }
        break;
    }
}


typedef struct {
    /* Original private words +0, +4, +8, +12; helper meanings remain open. */
    int selector, actorIndex, timer, helperArgument;
} DecodedNearSelectorTag;
extern Moby* DecodedNearSelectorPool __asm__("D_8006C550");
extern int DecodedNearSelectorPlayerFlag __asm__("D_80070328 + 0xB8");
int DecodedNearSelectorRead(int) __asm__("func_80021F3C");
int DecodedNearSelectorDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
void DecodedNearSelectorUpdate(Moby*) __asm__("func_80037014");
void DecodedNearSelectorWrite(int, int, int) __asm__("func_80021ED8");
void DecodedNearSelectorSet(int, int, int) __asm__("func_80021F8C");
void DecodedNearSelectorOwner(Moby*, int, int) __asm__("func_8003BB10");
void DecodedNearSelectorState(Moby*, int) __asm__("func_80034F40");
int DecodedNearSelectorTimer(void*, int) __asm__("func_800359A4");
void func_level_22_8007DCF4(Moby* actor) {
    register Moby* moby __asm__("$16")=actor;
    register DecodedNearSelectorTag* tag __asm__("$17")=moby->mobyTag;
    Moby* target;
    register int near __asm__("$19")=0;
    register int flag __asm__("$18");
    int value;
    int* playerFlag;
    /* The original actor pool uses 88-byte records. */
    target = &DecodedNearSelectorPool[tag->actorIndex];
    /* Extract original return bit 1, independently checked against retail. */
    flag = (unsigned int)DecodedNearSelectorRead(tag->selector) >> 1;
    __asm__("" : "=r"(flag) : "0"(flag));
    flag &= 1;
    playerFlag = &DecodedNearSelectorPlayerFlag;
    if (!*playerFlag)
        near = DecodedNearSelectorDistance(&moby->position,
            (Vector3D*)((char*)playerFlag - 0xB8)) < 700;
    if (DecodedNearSelectorDistance(&moby->position, &target->position) < 650)
        near = 1;
    DecodedNearSelectorUpdate(moby);
    __asm__ volatile ("" : : "r"(moby), "r"(tag), "r"(target), "r"(near), "r"(flag));
    switch (moby->state) {
    case 0:
        if (!near) break;
        if (flag) {
            DecodedNearSelectorWrite(tag->selector,252,0);
            DecodedNearSelectorOwner(moby,tag->helperArgument,0);
            moby->state = 1;
            DecodedNearSelectorState(moby,1);
        } else {
            __asm__("" : "=r"(flag) : "0"(flag));
            if (tag->selector == 15) break;
            value = 64 - ((DecodedNearSelectorRead(tag->selector) >> 8) & 255);
            if (value <= 0) value = 1;
            if (value >= 61) value = 60;
            if (value == 32) value = 33;
            DecodedNearSelectorSet(tag->selector,value,0);
            DecodedNearSelectorOwner(moby,tag->helperArgument,0);
            if (tag->selector == 15) moby->substate = 4;
            moby->state = 1;
            DecodedNearSelectorState(moby,1);
        }
        break;
    case 1:
        if (!DecodedNearSelectorTimer(&tag->timer,4)) break;
        if (near) break;
        __asm__("" : "=r"(near) : "0"(near));
        if (flag && DecodedNearSelectorTimer(&moby->substate,1)) {
            DecodedNearSelectorWrite(tag->selector,252,0);
        } else {
            if (tag->selector == 15) break;
            value = 64 - ((DecodedNearSelectorRead(tag->selector) >> 8) & 255);
            if (value <= 0) value = 1;
            if (value >= 61) value = 60;
            if (value == 32) value = 33;
            DecodedNearSelectorSet(tag->selector,value,0);
        }
        DecodedNearSelectorOwner(moby,tag->helperArgument,0);
        moby->state = 0;
        DecodedNearSelectorState(moby,0);
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original8007DF78. AI generated; not human reviewed.
 * Required:3519 original native instructions,88 absolute selectors,four zero
 * pads,all actual transfers/data addends,and parent EXE/every-overlay hashes.
 * Original F8 frame: produced scalar/vector homes20..CC; saved S0..S7/FP/RA
 * occupyD0..F4. Outgoing argument homes are emitted by the unchanged compiler.
 * FP is an ordinary allocator-selected GP,defined by original SLT at822;
 * it is never bound or treated as an incoming semantic value.
 * GP roles have initialized,distinct phases. No fixed FP/SP,manual outgoing
 * homes,overlapping aliases,padding reads,opcode templates or pipeline edits.
 * Six complete signed64 products retain exact low32-before-shift or signed
 * magic high-word projections. The union word order follows compiler endian
 * mode only; it is not a retail in-memory structure or a partial HILO input.
 * Empty metadata emits zero CPU instructions and observes only complete
 * initialized values,real addresses,actual original literals or produced
 * real fields/cells. Explicit GP clobbers retire a dead role before its new
 * original producer. All observed memory has a separate prior-write proof.
 * Header callbacks use original3/4/3/1/1-word ABI views. Helper declarations
 * describe proven four-byte argument words; no foreign ABI/layout is added.
 * No external difficulty,owner/private lifecycle,allocation,coordinate or
 * state-writer bound is inferred. Full external/helper semantics,Rev1 mapping,
 * units/cadence,runtime captures and human review remain explicit open work.
 * Original compiler identity establishes this binary slice,not complete game
 * behavior or portable signed-overflow/alias semantics.
 */
/* SCUS-94467 USA Rev0 original3519native+ownedselectors. AI generated; not human reviewed. Uninstalled original-backed probe. */
#define Level22_7DF78Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Level22_7DF78CompleteValue(v) __asm__("":"=r"(v):"0"(v))
void Level22_7DF78_PlaySound(int,int,int) __asm__("PlaySound");
void Level22_7DF78_func_80013AE4(int,int) __asm__("func_80013AE4");
void Level22_7DF78_func_80013B7C(int) __asm__("func_80013B7C");
void Level22_7DF78_func_80013D44(int,int,int,int) __asm__("func_80013D44");
void Level22_7DF78_func_8001A358(int,int) __asm__("func_8001A358");
int Level22_7DF78_func_8002803C(int,int,int,int,int,int,int) __asm__("func_8002803C");
void Level22_7DF78_func_80028154(int) __asm__("func_80028154");
void Level22_7DF78_func_80034F40(int,int) __asm__("func_80034F40");
void Level22_7DF78_func_80035734(int) __asm__("func_80035734");
int Level22_7DF78_func_800359A4(int,int) __asm__("func_800359A4");
int Level22_7DF78_func_8003613C(int,int) __asm__("func_8003613C");
int Level22_7DF78_func_80036220(int,int,int,int) __asm__("func_80036220");
void Level22_7DF78_func_80037014(int) __asm__("func_80037014");
int Level22_7DF78_func_80037BBC(int,int) __asm__("func_80037BBC");
int Level22_7DF78_func_8003BABC(int,int,int) __asm__("func_8003BABC");
void Level22_7DF78_func_8003BE70(int) __asm__("func_8003BE70");
int Level22_7DF78_func_8003BFC0(int,int) __asm__("func_8003BFC0");
void Level22_7DF78_func_800492DC(int) __asm__("func_800492DC");
int Level22_7DF78_func_8004E880(int,int,int) __asm__("func_8004E880");
int Level22_7DF78_func_8004E9E4(int) __asm__("func_8004E9E4");
int Level22_7DF78_func_8004EA2C(int) __asm__("func_8004EA2C");
void Level22_7DF78_func_8004ED6C(int,int,int) __asm__("func_8004ED6C");
void Level22_7DF78_func_8004F178(int,int) __asm__("func_8004F178");
void Level22_7DF78_func_8004F194(int,int,int) __asm__("func_8004F194");
int Level22_7DF78_func_8004F264(int,int) __asm__("func_8004F264");
int Level22_7DF78_func_8004F334(int,int) __asm__("func_8004F334");
void Level22_7DF78_func_800512E4(int,int,int) __asm__("func_800512E4");
void Level22_7DF78_func_80055B18(int) __asm__("func_80055B18");
void Level22_7DF78_func_80055D24(int,int) __asm__("func_80055D24");
int Level22_7DF78_func_80055E84(int) __asm__("func_80055E84");
void Level22_7DF78_func_8005629C(int) __asm__("func_8005629C");
extern int Level22_7DF78_D_800658A0 __asm__("D_800658A0");
extern int Level22_7DF78_D_80065920 __asm__("D_80065920");
extern int Level22_7DF78_D_80066BC8 __asm__("D_80066BC8");
extern int Level22_7DF78_D_8006C550 __asm__("D_8006C550");
extern int Level22_7DF78_D_8006C58C __asm__("D_8006C58C");
extern int Level22_7DF78_D_8006C640 __asm__("D_8006C640");
extern int Level22_7DF78_D_8006C650 __asm__("D_8006C650");
extern int Level22_7DF78_D_8006C654 __asm__("D_8006C654");
extern int Level22_7DF78_D_8006C658 __asm__("D_8006C658");
extern int Level22_7DF78_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level22_7DF78_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level22_7DF78_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level22_7DF78_D_8006E020 __asm__("D_8006E020");
extern int Level22_7DF78_D_8006E048 __asm__("D_8006E048");
extern int Level22_7DF78_D_8006E160 __asm__("D_8006E160");
extern int Level22_7DF78_D_8006E344 __asm__("D_8006E344");
extern int Level22_7DF78_D_8006EE2C __asm__("D_8006EE2C");
extern int Level22_7DF78_D_80070300 __asm__("D_80070300");
extern int Level22_7DF78_D_80070328 __asm__("D_80070328");
extern unsigned char Level22_7DF78_D_8007159A __asm__("D_8007159A");
extern int Level22_7DF78_D_800718D0 __asm__("D_800718D0");
extern short Level22_7DF78_D_800719DC __asm__("D_800719DC");
extern int (*Level22_7DF78_SpawnMoby)(int,int) __asm__("SpawnMoby");
extern int Level22_7DF78_unk_ovlheader_80074370 __asm__("unk_ovlheader_80074370");
extern int (*Level22_7DF78_unk_ovlheader_800743E8)(int,int,int) __asm__("unk_ovlheader_800743E8");
extern void (*Level22_7DF78_unk_ovlheader_80074434)(int,int,int,int) __asm__("unk_ovlheader_80074434");
extern void (*Level22_7DF78_unk_ovlheader_8007443C)(int,int,int) __asm__("unk_ovlheader_8007443C");
extern void (*Level22_7DF78_unk_ovlheader_80074440)(int) __asm__("unk_ovlheader_80074440");
extern int Level22_7DF78_unk_ovlheader_80074448 __asm__("unk_ovlheader_80074448");
extern int Level22_7DF78_unk_ovlheader_8007444C __asm__("unk_ovlheader_8007444C");
extern int Level22_7DF78_unk_ovlheader_80074450 __asm__("unk_ovlheader_80074450");
extern void (*Level22_7DF78_unk_ovlheader_8007447C)(int) __asm__("unk_ovlheader_8007447C");
typedef union {
    long long full;
#if defined(__MIPSEB__)
    struct {
        int high;
        unsigned low;
    }
    words;
#else
    struct {
        unsigned low;
        int high;
    }
    words;
#endif
}
Level22_7DF78CompleteProduct;
#define Level22_7DF78WholeProduct(p) __asm__("":"=x"((p).full):"0"((p).full))
void func_level_22_8007DF78(void* ownerParameter) {
    int firstHudHeader;
    register int actorFrameOrHeading16 __asm__("$16"),descriptorIndexOrHeading17 __asm__("$17"),privateStateOrAngle18 __asm__("$18"),owner19 __asm__("$19"),descriptorOrSavedValue20 __asm__("$20"),overlayContextOrHeading21 __asm__("$21"),offsetOrFlag22 __asm__("$22"),retainedHeading23 __asm__("$23");
    register int resultOrArithmetic2 __asm__("$2"),fieldOrOffset3 __asm__("$3"),argumentOrAddress4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrIndex6 __asm__("$6"),argumentOrField7 __asm__("$7");
    Level22_7DF78CompleteProduct sineProductA,cosineProductA,sineProductB,cosineProductB,heightDifferenceProductA,heightDifferenceProductB;
    register int productWord9 __asm__("$9");
    register int coordinateOrHeader8 __asm__("$8");
    struct {
        int sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC;
    }
    originalFrame;
    int captured_v0_36;
    int captured_v1_10;
    int captured_v1_37;
    int captured_v1_38;
    int captured_v1_8;
    int captured_a0_17;
    int captured_a0_22;
    int captured_v0_27;
    int captured_v0_29;
    int captured_v0_31;
    int captured_v0_35;
    int captured_v0_37;
    int captured_v0_38;
    int captured_v0_3;
    int captured_v0_4;
    int captured_v0_6;
    int captured_v0_7;
    int captured_a0;
    int captured_a0_13;
    int captured_a0_20;
    int captured_a0_21;
    int captured_a0_4;
    int captured_a0_5;
    int captured_a0_6;
    int captured_a0_7;
    int captured_a1;
    int captured_a1_3;
    int captured_a3;
    int captured_a3_10;
    int captured_a3_11;
    int captured_a3_13;
    int captured_a3_14;
    int captured_a3_15;
    int captured_a3_2;
    int captured_a3_3;
    int captured_a3_4;
    int captured_a3_6;
    int captured_a3_9;
    int captured_fp;
    int captured_hi;
    int captured_v0_10;
    int captured_v0_13;
    int captured_v0_16;
    int captured_v0_17;
    int captured_v0_18;
    int captured_v0_33;
    int captured_v0_34;
    int captured_v1_12;
    int captured_v1_14;
    int captured_v1_15;
    int captured_v1_16;
    int captured_v1_19;
    int captured_v1_22;
    int captured_v1_23;
    int captured_v1_31;
    int captured_v1_33;
    int captured_v1_36;
    int working_a0_2;
    int working_a0_7;
    int working_a0_8;
    int working_a1;
    int working_a1_2;
    int working_a1_4;
    int working_v0_18;
    int working_v0_28;
    int working_v0_45;
    int working_v0_51;
    int working_v0_53;
    int working_v0_54;
    int working_v1_8;
    int working_v1_9;
    int captured_v0_32;
    int captured_v1_26;
    int captured_v0_11;
    int captured_v0_26;
    int captured_v0_28;
    int captured_v0_9;
    int captured_v1;
    int captured_v1_17;
    int captured_v1_20;
    int captured_v1_24;
    int captured_v1_2;
    int captured_v1_32;
    int captured_v1_34;
    int captured_v1_35;
    int captured_v1_4;
    int captured_v1_6;
    int captured_a0_10;
    int captured_a0_11;
    int captured_a0_19;
    int captured_a0_8;
    int captured_v0_30;
    int captured_v0_5;
    int captured_v1_11;
    int captured_v1_27;
    int captured_v1_5;
    int captured_v1_9;
    owner19=(int)ownerParameter;
    Level22_7DF78CompleteValue(owner19);
    privateStateOrAngle18 = Level22_7DF78Field(owner19, int*, 0);
    fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x88);
    resultOrArithmetic2=fieldOrOffset3*88;
    fieldOrOffset3=Level22_7DF78_D_8006C550;
    descriptorOrSavedValue20=fieldOrOffset3+resultOrArithmetic2;
    overlayContextOrHeading21 = Level22_7DF78Field(descriptorOrSavedValue20, int*, 0);
    if (Level22_7DF78_D_8007159A == 0) {
        goto block_5;
    }
    if (Level22_7DF78_D_8006C7B4 & 0x10) {
        goto block_3;
    }
    if (!(Level22_7DF78Field((int)&Level22_7DF78_D_80070300 + Level22_7DF78_D_8006C58C,unsigned char*,0) & 0x10)) {
        goto block_4;
    }
block_3:
    Level22_7DF78Field(owner19, signed char *, 0x41) = 0;
    Level22_7DF78Field(owner19, unsigned char *, 0x4C) = 0U;
    Level22_7DF78Field(owner19, signed char *, 0x4D) = 0;
    Level22_7DF78Field(owner19, int *, 8) = 0;
    Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0x32U;
    goto block_5;
block_4:
    Level22_7DF78_func_80055B18(owner19);
    return;
block_5:
    captured_v1 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
    captured_a0 = captured_v1 & 0xFF;
    if (captured_a0 == 3) {
        goto block_8;
    }
    if ((unsigned int) (captured_v1 - 7) < 2U) {
        goto block_8;
    }
    if (captured_a0 != 9) {
        goto block_10;
    }
block_8:
    if (Level22_7DF78_func_8003BFC0(owner19, Level22_7DF78Field(privateStateOrAngle18, int *, 0x4BC)) != 0) {
        goto block_13;
    }
    Level22_7DF78Field(privateStateOrAngle18, int *, 0x4BC) = Level22_7DF78_func_8003BABC(owner19, 0, 4);
    goto block_13;
block_10:
    if (Level22_7DF78_func_8003BFC0(owner19, Level22_7DF78Field(privateStateOrAngle18, int *, 0x4BC)) == 0) {
        goto block_12;
    }
    Level22_7DF78_func_8003BE70(Level22_7DF78Field(privateStateOrAngle18, int *, 0x4BC));
block_12:
    Level22_7DF78Field(privateStateOrAngle18, int *, 0x4BC) = -1;
block_13:
    captured_v1_2 = Level22_7DF78Field(owner19, unsigned char *, 0x48);
    if (captured_v1_2 >= 0x33U) {
        goto block_608;
    }
    switch (captured_v1_2){
        default:goto block_608;
    case 0:
        if (Level22_7DF78_D_8006C658 == 0) {
            goto block_18;
        }
        if (Level22_7DF78_D_8006C640 != 0) {
            goto block_28;
        }
        Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0x32U;
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
        return;
    block_18:
        working_a1 = 0;
        if (Level22_7DF78_D_8006C640 != 0) {
            goto block_27;
        }
        argumentOrIndex6=1;
        Level22_7DF78CompleteValue(argumentOrIndex6);
        argumentOrAddress4=privateStateOrAngle18;
    loop_20:
        /* Original six-actor loop; the counter is produced at its actual loop-test consumer. */
        fieldOrOffset3=Level22_7DF78Field(argumentOrAddress4,int*,0xA0);
        resultOrArithmetic2=fieldOrOffset3*88;
        fieldOrOffset3=Level22_7DF78_D_8006C550;
        resultOrArithmetic2+=fieldOrOffset3;
        Level22_7DF78Field(resultOrArithmetic2,signed char*,0x49)=argumentOrIndex6;
        argumentOrAddress4+=4;
        working_a1+=1;
        if(working_a1<6) {
            goto loop_20;
        }
        __asm__ __volatile__("":"=r"(argumentOrIndex6):"0"(argumentOrIndex6));
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x3AC);
        argumentOrAddress4=1;
        resultOrArithmetic2=fieldOrOffset3*88;
        fieldOrOffset3=Level22_7DF78_D_8006C550;
        resultOrArithmetic2+=fieldOrOffset3;
        Level22_7DF78Field(resultOrArithmetic2,signed char*,0x49)=argumentOrAddress4;
        fieldOrOffset3=Level22_7DF78_D_8006C7B4;
        resultOrArithmetic2=fieldOrOffset3&8;
        if(resultOrArithmetic2) {
            goto block_23;
        }
        resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_80070300+Level22_7DF78_D_8006C58C,unsigned char*,0);
        resultOrArithmetic2&=8;
        if(!resultOrArithmetic2) {
            goto block_25;
        }
    block_23:
        resultOrArithmetic2=fieldOrOffset3&16;
        if(resultOrArithmetic2) {
            goto block_27;
        }
        resultOrArithmetic2=18;
        Level22_7DF78Field(privateStateOrAngle18,unsigned char*,2)=resultOrArithmetic2;
        goto block_26;
    block_25:
        Level22_7DF78Field(privateStateOrAngle18,unsigned char*,2)=0;
    block_26:
        Level22_7DF78Field(privateStateOrAngle18,signed char*,5)=argumentOrAddress4;
    block_27:
    block_28:
        if (Level22_7DF78_func_80037BBC(owner19, 0) == 0) {
            goto block_608;
        }
        Level22_7DF78_func_800512E4(owner19, 0, 0xE);
        Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0xEU;
        return;
    case 14:
        if (Level22_7DF78_D_8006E344 == 1) {
            goto block_608;
        }
        if (Level22_7DF78_D_8006C7B4 & 8) {
            goto block_38;
        }
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,unsigned char*,4);
        __asm__ __volatile__("":"=r"(resultOrArithmetic2):"0"(resultOrArithmetic2):"memory");
        argumentOrAddress4=resultOrArithmetic2*2;
        resultOrArithmetic2=argumentOrAddress4+3;
        argumentOrAddress4+=4;
        if(fieldOrOffset3!=resultOrArithmetic2) {
            goto block_34;
        }
        __asm__ __volatile__(""::"r"(argumentOrAddress4):"memory");
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
        fieldOrOffset3=1;
        Level22_7DF78Field(privateStateOrAngle18,short*,0x20A)=fieldOrOffset3;
        resultOrArithmetic2=resultOrArithmetic2*2+4;
        Level22_7DF78Field(privateStateOrAngle18,unsigned char*,2)=resultOrArithmetic2;
        resultOrArithmetic2=21;
        goto block_88;
    block_34:
        resultOrArithmetic2=4;
        if(fieldOrOffset3!=argumentOrAddress4) {
            goto block_36;
        }
        resultOrArithmetic2=1;
        Level22_7DF78Field(owner19,unsigned char*,0x49)=resultOrArithmetic2;
        resultOrArithmetic2=21;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x98)=0;
        goto block_88;
    block_36:
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,unsigned char*,2);
        if(fieldOrOffset3!=resultOrArithmetic2) {
            goto block_38;
        }
        Level22_7DF78Field(privateStateOrAngle18,unsigned char*,2)=argumentOrAddress4;
        Level22_7DF78_func_800512E4(owner19,0,14);
        return;
    block_38:
        if (Level22_7DF78Field(privateStateOrAngle18, unsigned char *, 4) != 0xF) {
            goto block_40;
        }
        Level22_7DF78Field(privateStateOrAngle18, signed char *, 5) = 2;
    block_40:
        if(Level22_7DF78Field(privateStateOrAngle18,unsigned char*,4)==21) {
            resultOrArithmetic2=23;
            goto block_88;
        }
        if(Level22_7DF78_D_8006C7B4&16) {
            resultOrArithmetic2=50;
            goto block_88;
        }
        Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0U;
        Level22_7DF78_func_80034F40(owner19, 0);
        return;
    case 50:
        captured_v1_4 = Level22_7DF78Field(owner19, unsigned char *, 0x49);
        if (captured_v1_4 == 1) {
            goto block_57;
        }
        if ((int) captured_v1_4 >= 2) {
            goto block_47;
        }
        if (captured_v1_4 == 0) {
            goto block_49;
        }
        return;
    block_47:
        if (captured_v1_4 == 2) {
            goto block_59;
        }
        return;
    block_49:
        fieldOrOffset3=(int)&Level22_7DF78_D_800718D0;
        resultOrArithmetic2=Level22_7DF78Field(fieldOrOffset3,int*,0);
        if(resultOrArithmetic2>=10000) {
            resultOrArithmetic2=10000;
            goto block_51;
        }
        resultOrArithmetic2=10000;
        Level22_7DF78Field(fieldOrOffset3,int*,0)=resultOrArithmetic2;
    block_51:
        if (Level22_7DF78Field(owner19, unsigned char *, 0x4C) == 0) {
            goto block_54;
        }
        if (Level22_7DF78_func_80037BBC(owner19, 0) == 0) {
            goto block_54;
        }
        Level22_7DF78_func_800512E4(owner19, 0, 0xE);
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 1U;
    block_54:
        if (Level22_7DF78_D_8006E160 != 0) {
            goto block_608;
        }
        if (Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x50) != 0x13) {
            goto block_608;
        }
        firstHudHeader=(int)Level22_7DF78_unk_ovlheader_80074370;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x258)=7200;
        resultOrArithmetic2=Level22_7DF78_func_8002803C(50,3,0,0,firstHudHeader,privateStateOrAngle18+0x258,7200);
        actorFrameOrHeading16=overlayContextOrHeading21+100;
        argumentOrAddress4=actorFrameOrHeading16;
        __asm__("":"=r"(resultOrArithmetic2):"0"(resultOrArithmetic2),"r"(argumentOrAddress4));
        resultOrArithmetic2=(short)resultOrArithmetic2;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x3B4)=resultOrArithmetic2;
        resultOrArithmetic2=(int)Level22_7DF78_unk_ovlheader_80074440;
        descriptorIndexOrHeading17=1;
        Level22_7DF78Field(overlayContextOrHeading21,int*,0x8C)=descriptorIndexOrHeading17;
        ((void(*)(int))resultOrArithmetic2)(argumentOrAddress4);
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4) = (int)(short) Level22_7DF78_func_8002803C(0x15, 0xDD, Level22_7DF78_unk_ovlheader_80074448, Level22_7DF78_unk_ovlheader_80074450, Level22_7DF78_unk_ovlheader_8007444C, actorFrameOrHeading16, 0xEA60);
        Level22_7DF78_D_8006C650 = 1;
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 2U;
        return;
    block_57:
        if (Level22_7DF78_D_8006E344 == captured_v1_4) {
            goto block_608;
        }
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
        return;
    block_59:
        if (Level22_7DF78_func_800359A4(privateStateOrAngle18 + 0x258, 4) == 0) {
            goto block_69;
        }
        captured_a0_4 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B4);
        if (captured_a0_4 == -1) {
            goto block_62;
        }
        Level22_7DF78_func_80028154(captured_a0_4);
    block_62:
        captured_a0_5 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4);
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B4) = -1;
        if (captured_a0_5 == -1) {
            goto block_64;
        }
        Level22_7DF78_func_80028154(captured_a0_5);
    block_64:
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4) = -1;
        if (Level22_7DF78Field((int)&Level22_7DF78_D_80066BC8, unsigned char *, 6) & 1) {
            goto block_68;
        }
        if (Level22_7DF78Field(overlayContextOrHeading21, int *, 0xE4) < 0x2710) {
            goto block_68;
        }
        Level22_7DF78Field((int)&Level22_7DF78_D_80066BC8, unsigned char *, 6) = 3U;
        Level22_7DF78_D_800719DC = 1;
        Level22_7DF78_PlaySound(Level22_7DF78Field(Level22_7DF78_D_8006C654, unsigned char *, 0x23), owner19, 0xA1);
        actorFrameOrHeading16 = Level22_7DF78_SpawnMoby(0xD3, owner19);
        if (actorFrameOrHeading16 == 0) {
            goto block_68;
        }
        Level22_7DF78_func_8004F178(actorFrameOrHeading16 + 0xC, (int)&Level22_7DF78_D_80070328);
        resultOrArithmetic2=Level22_7DF78Field(&Level22_7DF78_D_80070328,unsigned char*,14);
        resultOrArithmetic2*=2;
        fieldOrOffset3=Level22_7DF78Field(&Level22_7DF78_D_80065920,short*,resultOrArithmetic2);
        resultOrArithmetic2=fieldOrOffset3*25;
        fieldOrOffset3=Level22_7DF78Field(actorFrameOrHeading16,int*,12);
        resultOrArithmetic2>>=7;
        fieldOrOffset3+=resultOrArithmetic2;
        Level22_7DF78Field(actorFrameOrHeading16,int*,12)=fieldOrOffset3;
        resultOrArithmetic2=Level22_7DF78Field(&Level22_7DF78_D_80070328,unsigned char*,14);
        resultOrArithmetic2*=2;
        fieldOrOffset3=Level22_7DF78Field(actorFrameOrHeading16,int*,20);
        argumentOrAddress4=Level22_7DF78Field(&Level22_7DF78_D_800658A0,short*,resultOrArithmetic2);
        fieldOrOffset3+=500;
        Level22_7DF78Field(actorFrameOrHeading16,int*,20)=fieldOrOffset3;
        fieldOrOffset3=Level22_7DF78Field(actorFrameOrHeading16,int*,16);
        resultOrArithmetic2=argumentOrAddress4*25;
        resultOrArithmetic2>>=7;
        fieldOrOffset3+=resultOrArithmetic2;
        Level22_7DF78Field(actorFrameOrHeading16,int*,16)=fieldOrOffset3;
    block_68:
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x3AC);
        actorFrameOrHeading16=Level22_7DF78_D_8006C550;
        resultOrArithmetic2=fieldOrOffset3*88;
        actorFrameOrHeading16+=resultOrArithmetic2;
        Level22_7DF78Field(actorFrameOrHeading16, signed char *, 0x49) = 0;
        Level22_7DF78_func_8004F178(&originalFrame.sp20, actorFrameOrHeading16 + 0xC);
        originalFrame.sp20 += (int) -(Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + (Level22_7DF78Field(actorFrameOrHeading16, unsigned char *, 0x46) * 2)) * 0x5DC) >> 0xC;
        originalFrame.sp24 += (int) -(Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + (Level22_7DF78Field(actorFrameOrHeading16, unsigned char *, 0x46) * 2)) * 0x5DC) >> 0xC;
        Level22_7DF78_func_80013D44(&originalFrame.sp20, Level22_7DF78Field(actorFrameOrHeading16, unsigned char *, 0x46), 0, 0);
        Level22_7DF78Field(descriptorOrSavedValue20, signed char *, 0x48) = 0;
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
        Level22_7DF78_unk_ovlheader_8007447C(Level22_7DF78Field(overlayContextOrHeading21, int *, 0xE4));
        Level22_7DF78_D_8006C650 = 0;
    block_69:
        if (Level22_7DF78_D_8006C650 != 2) {
            goto block_608;
        }
        captured_a0_6 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B4);
        Level22_7DF78_D_8006C650 = 0;
        if (captured_a0_6 == -1) {
            goto block_72;
        }
        Level22_7DF78_func_80028154(captured_a0_6);
    block_72:
        captured_a0_7 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4);
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B4) = -1;
        if (captured_a0_7 == -1) {
            goto block_74;
        }
        Level22_7DF78_func_80028154(captured_a0_7);
    block_74:
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4) = -1;
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x3AC);
        actorFrameOrHeading16=Level22_7DF78_D_8006C550;
        resultOrArithmetic2=fieldOrOffset3*88;
        actorFrameOrHeading16+=resultOrArithmetic2;
        Level22_7DF78Field(actorFrameOrHeading16, signed char *, 0x49) = 0;
        Level22_7DF78_func_8004F178(&originalFrame.sp30, actorFrameOrHeading16 + 0xC);
        originalFrame.sp30 += (int) -(Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + (Level22_7DF78Field(actorFrameOrHeading16, unsigned char *, 0x46) * 2)) * 0x5DC) >> 0xC;
        originalFrame.sp34 += (int) -(Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + (Level22_7DF78Field(actorFrameOrHeading16, unsigned char *, 0x46) * 2)) * 0x5DC) >> 0xC;
        Level22_7DF78_func_80013D44(&originalFrame.sp30, Level22_7DF78Field(actorFrameOrHeading16, unsigned char *, 0x46), 0, 0);
        Level22_7DF78Field(descriptorOrSavedValue20, signed char *, 0x48) = 0;
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
        return;
    case 23:
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x384);
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x3AC);
        Level22_7DF78Field(privateStateOrAngle18,int*,0x380)=resultOrArithmetic2;
        Level22_7DF78Field(resultOrArithmetic2,short*,2)=0;
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x380);
        argumentOrAddress4=(int)&originalFrame.sp20;
        argumentOrField5=Level22_7DF78Field(resultOrArithmetic2,int*,12);
        __asm__("":"=r"(fieldOrOffset3):"0"(fieldOrOffset3),"r"(argumentOrAddress4),"r"(argumentOrField5));
        resultOrArithmetic2=fieldOrOffset3*88;
        fieldOrOffset3=Level22_7DF78_D_8006C550;
        descriptorOrSavedValue20=fieldOrOffset3+resultOrArithmetic2;
        Level22_7DF78_func_8004F178(argumentOrAddress4,argumentOrField5);
        captured_v0_3 = Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x380), int*, 0xC);
        captured_a3 = Level22_7DF78Field(captured_v0_3, int *, 0x10);
        Level22_7DF78_func_8004E880(captured_a3 - Level22_7DF78Field(captured_v0_3, int *, 0), Level22_7DF78Field(captured_v0_3, int *, 0x14) - Level22_7DF78Field(captured_v0_3, int *, 4), 0);
        descriptorIndexOrHeading17 = Level22_7DF78Field(owner19, unsigned char *, 0x49);
        if (descriptorIndexOrHeading17 == 1) {
            goto block_82;
        }
        if ((int) descriptorIndexOrHeading17 >= 2) {
            goto block_79;
        }
        if (descriptorIndexOrHeading17 == 0) {
            goto block_81;
        }
        return;
    block_79:
        resultOrArithmetic2=2;
        if(descriptorIndexOrHeading17==resultOrArithmetic2) {
            resultOrArithmetic2=7200;
            goto block_87;
        }
        resultOrArithmetic2=7200;
        __asm__ __volatile__(""::"r"(resultOrArithmetic2));
        return;
    block_81:
        Level22_7DF78CompleteValue(descriptorIndexOrHeading17);
        Level22_7DF78_func_8004F178(&originalFrame.sp40, descriptorOrSavedValue20 + 0xC);
        originalFrame.sp40 += (int) -(Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + (Level22_7DF78Field(descriptorOrSavedValue20, unsigned char *, 0x46) * 2)) * 0x5DC) >> 0xC;
        originalFrame.sp44 += (int) -(Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + (Level22_7DF78Field(descriptorOrSavedValue20, unsigned char *, 0x46) * 2)) * 0x5DC) >> 0xC;
        Level22_7DF78_func_80013D44(&originalFrame.sp40, Level22_7DF78Field(descriptorOrSavedValue20, unsigned char *, 0x46), 0, 0);
        goto block_531;
    block_82:
        if (!(Level22_7DF78_D_8006E048 & 1)) {
            goto block_608;
        }
        Level22_7DF78_func_8004F178(owner19 + 0xC, Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x380), int*, 0xC));
        Level22_7DF78Field(owner19, int *, 0x14) = (int) (Level22_7DF78Field(owner19, int *, 0x14) + Level22_7DF78Field(owner19, short *, 0x38));
        Level22_7DF78_func_80055D24(owner19, 2);
        captured_v0_4 = Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x380), int*, 0xC);
        captured_a3_2 = Level22_7DF78Field(captured_v0_4, int *, 0x10);
        Level22_7DF78Field(owner19, unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_2 - Level22_7DF78Field(captured_v0_4, int *, 0), Level22_7DF78Field(captured_v0_4, int *, 0x14) - Level22_7DF78Field(captured_v0_4, int *, 4), 0);
        Level22_7DF78Field(descriptorOrSavedValue20, signed char *, 0x49) = 0;
        captured_v0_5 = Level22_7DF78_SpawnMoby(0x157, owner19);
        Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) = captured_v0_5;
        if (captured_v0_5 == 0) {
            goto block_85;
        }
        Level22_7DF78Field(captured_v0_5, signed char *, 0x47) = 0;
        Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x4C) = 0x30U;
        captured_v1_5 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220);
        Level22_7DF78Field(captured_v1_5, unsigned char *, 0x4E) = (unsigned char) Level22_7DF78Field(captured_v1_5, unsigned char *, 0x4C);
        captured_v0_6 = Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x380), int*, 0xC);
        captured_a3_3 = Level22_7DF78Field(captured_v0_6, int *, 0x10);
        Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_3 - Level22_7DF78Field(captured_v0_6, int *, 0), Level22_7DF78Field(captured_v0_6, int *, 0x14) - Level22_7DF78Field(captured_v0_6, int *, 4), 0);
        captured_a0_8 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220);
        Level22_7DF78Field(captured_a0_8, int *, 0x14) = (int) (Level22_7DF78Field(captured_a0_8, int *, 0x14) - Level22_7DF78Field(owner19, short *, 0x38));
    block_85:
        /* Two original one-word header callbacks, followed by three seven-word HUD calls. Signed low16 return projections retain their actual argument/read boundaries. */
        actorFrameOrHeading16=overlayContextOrHeading21+100;
        resultOrArithmetic2=(int)Level22_7DF78_unk_ovlheader_80074440;
        argumentOrAddress4=actorFrameOrHeading16;
        Level22_7DF78Field(overlayContextOrHeading21,int*,0x8C)=descriptorIndexOrHeading17;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x3E0)=descriptorIndexOrHeading17;
        ((void(*)(int))resultOrArithmetic2)(argumentOrAddress4);
        descriptorIndexOrHeading17=privateStateOrAngle18+0x3B8;
        resultOrArithmetic2=(int)Level22_7DF78_unk_ovlheader_80074440;
        ((void(*)(int))resultOrArithmetic2)(descriptorIndexOrHeading17);
        resultOrArithmetic2=Level22_7DF78_func_8002803C(50,3,0,0,Level22_7DF78_unk_ovlheader_80074370,privateStateOrAngle18+0x258,7200);
        argumentOrAddress4=21;
        __asm__("":"=r"(resultOrArithmetic2),"=r"(argumentOrAddress4):"0"(resultOrArithmetic2),"1"(argumentOrAddress4));
        resultOrArithmetic2=(int)((unsigned)resultOrArithmetic2<<16);
        __asm__ __volatile__("":"=r"(resultOrArithmetic2):"0"(resultOrArithmetic2):"memory");
        argumentOrIndex6=Level22_7DF78_unk_ovlheader_80074448;
        argumentOrField7=Level22_7DF78_unk_ovlheader_80074450;
        __asm__("":"=r"(resultOrArithmetic2),"=r"(argumentOrIndex6),"=r"(argumentOrField7):"0"(resultOrArithmetic2),"1"(argumentOrIndex6),"2"(argumentOrField7));
        resultOrArithmetic2>>=16;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x3B4)=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78_func_8002803C(argumentOrAddress4,221,argumentOrIndex6,argumentOrField7,Level22_7DF78_unk_ovlheader_8007444C,actorFrameOrHeading16,60000);
        argumentOrAddress4=23;
        __asm__("":"=r"(resultOrArithmetic2),"=r"(argumentOrAddress4):"0"(resultOrArithmetic2),"1"(argumentOrAddress4));
        resultOrArithmetic2=(int)((unsigned)resultOrArithmetic2<<16);
        __asm__ __volatile__("":"=r"(resultOrArithmetic2):"0"(resultOrArithmetic2):"memory");
        argumentOrIndex6=Level22_7DF78_unk_ovlheader_80074448;
        argumentOrField7=Level22_7DF78_unk_ovlheader_80074450;
        __asm__("":"=r"(resultOrArithmetic2),"=r"(argumentOrIndex6),"=r"(argumentOrField7):"0"(resultOrArithmetic2),"1"(argumentOrIndex6),"2"(argumentOrField7));
        resultOrArithmetic2>>=16;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x4A4)=resultOrArithmetic2;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x4A8)=(int)(short)Level22_7DF78_func_8002803C(argumentOrAddress4,222,argumentOrIndex6,argumentOrField7,Level22_7DF78_unk_ovlheader_8007444C,descriptorIndexOrHeading17,60000);
        if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 2) {
            goto block_531;
        }
        argumentOrAddress4=owner19;
        Level22_7DF78CompleteValue(argumentOrAddress4);
        Level22_7DF78_D_8006C770 = 0;
        resultOrArithmetic2=114;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
        Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 2U;
        Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
        Level22_7DF78_func_80035734(argumentOrAddress4);
        __asm__("":"=r"(owner19):"0"(owner19),"i"(23));
        goto block_531;
    block_87:
        /* The original7200 producer reaches this single store from both branch outcomes in the delay instruction; the false edge observes the same real complete literal. */
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,int*,0x258)=resultOrArithmetic2;
        resultOrArithmetic2=-1;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x228)=resultOrArithmetic2;
        Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22A)=resultOrArithmetic2;
        resultOrArithmetic2=60;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22C)=resultOrArithmetic2;
        resultOrArithmetic2=55;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,short*,0x22E)=resultOrArithmetic2;
        resultOrArithmetic2=1;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,short*,0x236)=resultOrArithmetic2;
        resultOrArithmetic2=24;
        Level22_7DF78Field(privateStateOrAngle18, short *, 0x444) = 0;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x4B8) = 0;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = 0;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x254) = 0;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
    block_88:
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
        Level22_7DF78Field(owner19, unsigned char *, 0x48) = resultOrArithmetic2;
        return;
    case 24:
        descriptorOrSavedValue20 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x380);
        Level22_7DF78_unk_ovlheader_8007443C(0, privateStateOrAngle18 + 0x3B8, 0);
        if (Level22_7DF78_func_800359A4(privateStateOrAngle18 + 0x258, 4) == 0) {
            goto block_102;
        }
        fieldOrOffset3=Level22_7DF78Field(overlayContextOrHeading21,int*,0xE4);
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x438);
        captured_fp=resultOrArithmetic2<fieldOrOffset3;
        descriptorIndexOrHeading17 = 0x680;
        if (captured_fp == 0) {
            goto block_92;
        }
        descriptorIndexOrHeading17 = 0x9C0;
    block_92:
        Level22_7DF78_func_8004F178(&originalFrame.sp30, Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x384), int*, 0xC));
        captured_v0_7 = Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x384), int*, 0xC);
        captured_a3_4 = Level22_7DF78Field(captured_v0_7, int *, 0x10);
        resultOrArithmetic2=Level22_7DF78_func_8004E880(captured_a3_4-Level22_7DF78Field(captured_v0_7,int*,0),Level22_7DF78Field(captured_v0_7,int*,20)-Level22_7DF78Field(captured_v0_7,int*,4),0);
        offsetOrFlag22=resultOrArithmetic2-128;
        captured_v1_6=Level22_7DF78Field(owner19,unsigned char*,0x49);
        retainedHeading23=resultOrArithmetic2;
        if (captured_v1_6 == 0) {
            goto block_95;
        }
        if (captured_v1_6 == 1) {
            goto block_96;
        }
        goto block_102;
    block_95:
        Level22_7DF78_func_8004F178(&originalFrame.sp50, &originalFrame.sp30);
        argumentOrAddress4 = (retainedHeading23 & 0xFF) * 2;
        resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + argumentOrAddress4);
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        sineProductA.full=(long long)resultOrArithmetic2*(long long)descriptorIndexOrHeading17;
        Level22_7DF78WholeProduct(sineProductA);
        resultOrArithmetic2=originalFrame.sp50;
        __asm__("":"=x"(sineProductA.full):"0"(sineProductA.full),"r"(resultOrArithmetic2));
        productWord9=(int)sineProductA.words.low;
        Level22_7DF78CompleteValue(productWord9);
        fieldOrOffset3=productWord9>>12;
        resultOrArithmetic2+=fieldOrOffset3;
        originalFrame.sp50=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + argumentOrAddress4);
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        cosineProductA.full=(long long)resultOrArithmetic2*(long long)descriptorIndexOrHeading17;
        Level22_7DF78WholeProduct(cosineProductA);
        argumentOrField5=offsetOrFlag22&255;
        argumentOrIndex6=0;
        argumentOrField7=0;
        argumentOrAddress4=(int)&originalFrame.sp50;
        resultOrArithmetic2=originalFrame.sp54;
        __asm__("":"=x"(cosineProductA.full):"0"(cosineProductA.full),"r"(resultOrArithmetic2),"r"(argumentOrAddress4),"r"(argumentOrField5),"r"(argumentOrIndex6),"r"(argumentOrField7));
        productWord9=(int)cosineProductA.words.low;
        Level22_7DF78CompleteValue(productWord9);
        fieldOrOffset3=productWord9>>12;
        resultOrArithmetic2+=fieldOrOffset3;
        originalFrame.sp54=resultOrArithmetic2;
        Level22_7DF78_func_80013D44(argumentOrAddress4,argumentOrField5,argumentOrIndex6,argumentOrField7);
        Level22_7DF78Field(owner19, unsigned char *, 0x49) = (unsigned char) (Level22_7DF78Field(owner19, unsigned char *, 0x49) + 1);
        goto block_102;
    block_96:
        if (!(Level22_7DF78_D_8006E048 & 1)) {
            goto block_102;
        }
        captured_a0_10 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220);
        if (captured_a0_10 == 0) {
            goto block_99;
        }
        Level22_7DF78_func_80055B18(captured_a0_10);
        Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) = 0;
    block_99:
        Level22_7DF78_func_80028154(Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B4));
        Level22_7DF78_func_80028154(Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4));
        Level22_7DF78_func_80028154(Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A8));
        Level22_7DF78Field(((Level22_7DF78Field(privateStateOrAngle18, int *, 0x3AC) * 0x58) + Level22_7DF78_D_8006C550), signed char *, 0x49) = 1;
        Level22_7DF78_func_8004F178(owner19 + 0xC, &originalFrame.sp30);
        Level22_7DF78Field(owner19, int *, 0x14) = (int) (Level22_7DF78Field(owner19, int *, 0x14) + Level22_7DF78Field(owner19, short *, 0x38));
        Level22_7DF78_func_80055D24(owner19, 2);
        Level22_7DF78Field(owner19, unsigned char *, 0x44) = 0U;
        Level22_7DF78Field(owner19, unsigned char *, 0x45) = 0U;
        Level22_7DF78Field(owner19, unsigned char *, 0x46) = retainedHeading23;
        Level22_7DF78Field(privateStateOrAngle18, unsigned char *, 2) = 0x13U;
        Level22_7DF78Field(privateStateOrAngle18, signed char *, 5) = 2;
        if (captured_fp == 0) {
            goto block_101;
        }
        Level22_7DF78_D_8006C7B4 |= 0x10;
    block_101:
        Level22_7DF78Field(owner19,unsigned char*,0x48)=0;
        resultOrArithmetic2=Level22_7DF78Field(owner19,short*,0x36);
        resultOrArithmetic2*=4;
        resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_8006EE2C,int*,resultOrArithmetic2);
        resultOrArithmetic2=Level22_7DF78Field(resultOrArithmetic2,int*,0x3C);
        resultOrArithmetic2=Level22_7DF78Field(resultOrArithmetic2,unsigned char*,0);
        Level22_7DF78Field(owner19,unsigned char*,0x3C)=0;
        Level22_7DF78Field(owner19,unsigned char*,0x3D)=0;
        Level22_7DF78Field(owner19,signed char*,0x3E)=0;
        Level22_7DF78Field(owner19,signed char*,0x3F)=1;
        resultOrArithmetic2=(unsigned)resultOrArithmetic2<2U;
        resultOrArithmetic2^=1;
        resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        resultOrArithmetic2&=48;
        Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
        return;
    block_102:
        if (Level22_7DF78_D_8006C770 == 0) {
            goto block_105;
        }
        if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) != 2) {
            goto block_107;
        }
        Level22_7DF78_D_8006C770 = 0;
        resultOrArithmetic2=114;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
        Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 3U;
        Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
        Level22_7DF78_func_80035734(owner19);
    block_105:
        if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) != 2) {
            goto block_107;
        }
        if (Level22_7DF78_func_80055E84(owner19) < 0x33) {
            goto block_608;
        }
    block_107:
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22C);
        fieldOrOffset3=Level22_7DF78_D_8006C7C4;
        resultOrArithmetic2+=30;
        Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22C)=resultOrArithmetic2;
        resultOrArithmetic2=2;
        working_a0_2=260;
        if(fieldOrOffset3!=resultOrArithmetic2) {
            goto block_109;
        }
        working_a0_2 = 0x122;
        goto block_111;
    block_109:
        if(fieldOrOffset3!=0) {
            goto block_111;
        }
        working_a0_2 = 0xF0;
    block_111:
        if (working_a0_2 >= (short) Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C)) {
            goto block_113;
        }
        Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) = (unsigned short) working_a0_2;
    block_113:
        Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) = (unsigned short) (Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) + Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0));
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x254) == 0) {
            goto block_155;
        }
        argumentOrAddress4=owner19 + 0xC;
        argumentOrField5=Level22_7DF78Field(descriptorOrSavedValue20,short*,2);
        resultOrArithmetic2=Level22_7DF78Field(descriptorOrSavedValue20,int*,12);
        argumentOrField5*=16;
        argumentOrField5=resultOrArithmetic2+argumentOrField5;
        resultOrArithmetic2=Level22_7DF78_func_8004F334(argumentOrAddress4,argumentOrField5);
        argumentOrAddress4=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78Field(descriptorOrSavedValue20,short*,2);
        fieldOrOffset3=Level22_7DF78Field(descriptorOrSavedValue20,int*,12);
        argumentOrField5=Level22_7DF78Field(owner19,int*,20);
        __asm__("":"=r"(resultOrArithmetic2),"=r"(fieldOrOffset3),"=r"(argumentOrField5):"0"(resultOrArithmetic2),"1"(fieldOrOffset3),"2"(argumentOrField5));
        resultOrArithmetic2*=16;
        resultOrArithmetic2+=fieldOrOffset3;
        resultOrArithmetic2=Level22_7DF78Field(resultOrArithmetic2,int*,8);
        argumentOrIndex6=0;
        resultOrArithmetic2=Level22_7DF78_func_8004E880(argumentOrAddress4,resultOrArithmetic2-argumentOrField5,argumentOrIndex6);
        argumentOrIndex6=0;
        __asm__("":"=r"(resultOrArithmetic2),"=r"(argumentOrIndex6):"0"(resultOrArithmetic2),"1"(argumentOrIndex6));
        descriptorIndexOrHeading17=resultOrArithmetic2;
        fieldOrOffset3=Level22_7DF78Field(descriptorOrSavedValue20,short*,2);
        argumentOrAddress4=Level22_7DF78Field(descriptorOrSavedValue20,int*,12);
        fieldOrOffset3*=16;
        fieldOrOffset3+=argumentOrAddress4;
        coordinateOrHeader8=Level22_7DF78Field(fieldOrOffset3,int*,32);
        argumentOrAddress4=Level22_7DF78Field(fieldOrOffset3,int*,0);
        argumentOrField7=Level22_7DF78Field(fieldOrOffset3,int*,36);
        argumentOrField5=Level22_7DF78Field(fieldOrOffset3,int*,4);
        argumentOrAddress4=coordinateOrHeader8-argumentOrAddress4;
        resultOrArithmetic2=Level22_7DF78_func_8004E880(argumentOrAddress4,argumentOrField7-argumentOrField5,argumentOrIndex6);
        argumentOrAddress4=owner19;
        __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4):"$3");
        fieldOrOffset3=3;
        argumentOrField5=2;
        Level22_7DF78Field(privateStateOrAngle18,short*,0x444)=fieldOrOffset3;
        __asm__("":"=r"(argumentOrField5):"0"(argumentOrField5),"m"(Level22_7DF78Field(privateStateOrAngle18,short*,0x444)):"$6");
        fieldOrOffset3=Level22_7DF78Field(owner19,int*,20);
        argumentOrIndex6=Level22_7DF78Field(privateStateOrAngle18,int*,0x24C);
        __asm__("":"=r"(resultOrArithmetic2):"0"(resultOrArithmetic2),"r"(argumentOrAddress4),"r"(argumentOrField5),"r"(fieldOrOffset3),"r"(argumentOrIndex6));
        captured_v0_9=resultOrArithmetic2;
        fieldOrOffset3+=argumentOrIndex6;
        Level22_7DF78Field(owner19,int*,20)=fieldOrOffset3;
        Level22_7DF78_func_80055D24(argumentOrAddress4,argumentOrField5);
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) = (int) (Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) - 0xC);
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0) {
            goto block_152;
        }
        fieldOrOffset3=Level22_7DF78_func_8003613C(Level22_7DF78Field(owner19, unsigned char *, 0x44), 0);
        Level22_7DF78CompleteValue(fieldOrOffset3);
        resultOrArithmetic2=fieldOrOffset3;
        if(fieldOrOffset3>=0) {
            goto clamp26790_1_absolute;
        }
        resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
    clamp26790_1_absolute:
        if(resultOrArithmetic2>=10) {
            goto clamp26790_1_upper4;
        }
        if(fieldOrOffset3<3) {
            goto clamp26790_1_lower2;
        }
        fieldOrOffset3=2;
        Level22_7DF78CompleteValue(fieldOrOffset3);
    clamp26790_1_lower2:
        resultOrArithmetic2=fieldOrOffset3<-2;
        if(!resultOrArithmetic2) {
            goto clamp26790_1_upper4;
        }
        fieldOrOffset3=-2;
    clamp26790_1_upper4:
        resultOrArithmetic2=fieldOrOffset3<5;
        if(resultOrArithmetic2) {
            goto clamp26790_1_lower4;
        }
        fieldOrOffset3=4;
        Level22_7DF78CompleteValue(fieldOrOffset3);
    clamp26790_1_lower4:
        resultOrArithmetic2=fieldOrOffset3<-4;
        if(!resultOrArithmetic2) {
            goto clamp26790_1_store;
        }
        fieldOrOffset3=-4;
    clamp26790_1_store:
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x44);
        Level22_7DF78Field(owner19,unsigned char*,0x44)=resultOrArithmetic2+fieldOrOffset3;
        fieldOrOffset3=Level22_7DF78_func_8003613C(Level22_7DF78Field(owner19, unsigned char *, 0x45), descriptorIndexOrHeading17 & 0xFF);
        Level22_7DF78CompleteValue(fieldOrOffset3);
        resultOrArithmetic2=fieldOrOffset3;
        if(fieldOrOffset3>=0) {
            goto clamp26790_2_absolute;
        }
        resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
    clamp26790_2_absolute:
        if(resultOrArithmetic2>=10) {
            goto clamp26790_2_upper4;
        }
        if(fieldOrOffset3<3) {
            goto clamp26790_2_lower2;
        }
        fieldOrOffset3=2;
        Level22_7DF78CompleteValue(fieldOrOffset3);
    clamp26790_2_lower2:
        resultOrArithmetic2=fieldOrOffset3<-2;
        if(!resultOrArithmetic2) {
            goto clamp26790_2_upper4;
        }
        fieldOrOffset3=-2;
    clamp26790_2_upper4:
        resultOrArithmetic2=fieldOrOffset3<5;
        if(resultOrArithmetic2) {
            goto clamp26790_2_lower4;
        }
        fieldOrOffset3=4;
        Level22_7DF78CompleteValue(fieldOrOffset3);
    clamp26790_2_lower4:
        resultOrArithmetic2=fieldOrOffset3<-4;
        if(!resultOrArithmetic2) {
            goto clamp26790_2_store;
        }
        fieldOrOffset3=-4;
    clamp26790_2_store:
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x45);
        Level22_7DF78Field(owner19,unsigned char*,0x45)=resultOrArithmetic2+fieldOrOffset3;
        fieldOrOffset3=Level22_7DF78_func_8003613C(Level22_7DF78Field(owner19, unsigned char *, 0x46), captured_v0_9 & 0xFF);
        Level22_7DF78CompleteValue(fieldOrOffset3);
        resultOrArithmetic2=fieldOrOffset3;
        if(fieldOrOffset3>=0) {
            goto clamp26790_3_absolute;
        }
        resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
    clamp26790_3_absolute:
        if(resultOrArithmetic2>=10) {
            goto clamp26790_3_upper4;
        }
        if(fieldOrOffset3<3) {
            goto clamp26790_3_lower2;
        }
        fieldOrOffset3=2;
        Level22_7DF78CompleteValue(fieldOrOffset3);
    clamp26790_3_lower2:
        resultOrArithmetic2=fieldOrOffset3<-2;
        if(!resultOrArithmetic2) {
            goto clamp26790_3_upper4;
        }
        fieldOrOffset3=-2;
    clamp26790_3_upper4:
        resultOrArithmetic2=fieldOrOffset3<5;
        if(resultOrArithmetic2) {
            goto clamp26790_3_lower4;
        }
        fieldOrOffset3=4;
        Level22_7DF78CompleteValue(fieldOrOffset3);
    clamp26790_3_lower4:
        resultOrArithmetic2=fieldOrOffset3<-4;
        if(!resultOrArithmetic2) {
            goto clamp26790_3_store;
        }
        fieldOrOffset3=-4;
    clamp26790_3_store:
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
        Level22_7DF78Field(owner19,unsigned char*,0x46)=resultOrArithmetic2+fieldOrOffset3;
    block_152:
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) >= 0) {
            goto block_206;
        }
        if ((Level22_7DF78Field(owner19, int *, 0x14) - Level22_7DF78Field(owner19, short *, 0x38)) >= Level22_7DF78Field(privateStateOrAngle18, int *, 0x250)) {
            goto block_206;
        }
        resultOrArithmetic2=descriptorIndexOrHeading17&255;
        resultOrArithmetic2*=16;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x228)=resultOrArithmetic2;
        resultOrArithmetic2=captured_v0_9&255;
        resultOrArithmetic2*=16;
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        Level22_7DF78Field(privateStateOrAngle18,int*,0x254)=0;
        Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22A)=resultOrArithmetic2;
        Level22_7DF78Field(owner19, unsigned char *, 0x44) = 0U;
        Level22_7DF78Field(owner19, unsigned char *, 0x45) = (unsigned char) ((unsigned short) Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x228) >> 4);
        Level22_7DF78Field(owner19, unsigned char *, 0x46) = (unsigned char) ((unsigned short) Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22A) >> 4);
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
        goto block_206;
    block_155:
        /* Original descriptor callback743E8 returns a complete int. Every original local vector input/output has a primary EXE producer proof. */
        Level22_7DF78_func_8004F178(&originalFrame.sp50, owner19 + 0xC);
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0) {
            goto block_157;
        }
        Level22_7DF78Field(privateStateOrAngle18, short *, 0x444) = 1;
        Level22_7DF78Field(owner19, unsigned char *, 0x44) = 0U;
    block_157:
        captured_v0_10 = Level22_7DF78_unk_ovlheader_800743E8(owner19, descriptorOrSavedValue20, privateStateOrAngle18 + 0x228);
        if (captured_v0_10 != 1) {
            goto block_201;
        }
        captured_v1_8 = Level22_7DF78Field(descriptorOrSavedValue20, short *, 0);
        captured_hi = (int) ((Level22_7DF78Field(descriptorOrSavedValue20, short *, 2) - Level22_7DF78Field(descriptorOrSavedValue20, short *, 0xA)) + captured_v1_8) % captured_v1_8;
        captured_v1_9 = Level22_7DF78Field(descriptorOrSavedValue20, int *, 0xC) + (captured_hi * 0x10);
        captured_v0_11 = Level22_7DF78Field(captured_v1_9, unsigned char *, 0xF);
        if (captured_v0_11 == 0) {
            goto block_160;
        }
        Level22_7DF78Field(privateStateOrAngle18, short *, 0x22E) = (short) captured_v0_11;
    block_160:
        resultOrArithmetic2=Level22_7DF78Field(captured_v1_9,unsigned char*,13);
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        argumentOrAddress4=(int)&originalFrame.sp60;
        if(!resultOrArithmetic2) goto block_169;
        overlayContextOrHeading21=resultOrArithmetic2;
        Level22_7DF78CompleteValue(overlayContextOrHeading21);
        actorFrameOrHeading16=overlayContextOrHeading21*4+privateStateOrAngle18;
        offsetOrFlag22 = Level22_7DF78Field(captured_v1_9, unsigned char *, 0xC);
        descriptorIndexOrHeading17 = offsetOrFlag22 * 0x10;
        Level22_7DF78_func_8004F178(argumentOrAddress4, Level22_7DF78Field(Level22_7DF78Field(actorFrameOrHeading16, int*, 0x384), int *, 0xC) + descriptorIndexOrHeading17);
        Level22_7DF78_func_8004E880(originalFrame.sp60 - Level22_7DF78Field(owner19, int *, 0xC), originalFrame.sp64 - Level22_7DF78Field(owner19, int *, 0x10), 0);
        captured_a0_11 = Level22_7DF78Field(actorFrameOrHeading16, int*, 0x384);
        captured_v1_10 = Level22_7DF78Field(captured_a0_11, short *, 0);
        captured_v0_13 = Level22_7DF78Field(captured_a0_11, int *, 0xC);
        descriptorIndexOrHeading17 = descriptorIndexOrHeading17 + captured_v0_13;
        captured_v1_11 = (((int) (offsetOrFlag22 + Level22_7DF78Field(captured_a0_11, short *, 0xA) + captured_v1_10) % captured_v1_10) * 0x10) + captured_v0_13;
        captured_a3_6 = Level22_7DF78Field(captured_v1_11, int *, 0);
        captured_a1 = Level22_7DF78_func_8004F264(Level22_7DF78_func_8004E880(captured_a3_6 - Level22_7DF78Field(descriptorIndexOrHeading17, int *, 0), Level22_7DF78Field(captured_v1_11, int *, 4) - Level22_7DF78Field(descriptorIndexOrHeading17, int *, 4), 0), Level22_7DF78Field(owner19, unsigned char *, 0x46)) >= 0x41;
        if (overlayContextOrHeading21 == captured_v0_10) {
            goto block_163;
        }
        if (captured_a1 != 0) {
            goto block_169;
        }
    block_163:
        resultOrArithmetic2 = 1;
        if (overlayContextOrHeading21 == captured_v0_10) {
            goto block_166;
        }
        resultOrArithmetic2=Level22_7DF78Field(descriptorOrSavedValue20,short*,0);
        resultOrArithmetic2-=1;
        if(captured_hi==resultOrArithmetic2) {
            resultOrArithmetic2=1;
            goto block_166;
        }
        captured_v1_12 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x4B8);
        resultOrArithmetic2 = Level22_7DF78Field((captured_v1_12 * 4) + Level22_7DF78Field(((Level22_7DF78_D_8006C7C4 * 4) + privateStateOrAngle18), int *, 0x4AC),int*,0);
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x4B8) = (int) (captured_v1_12 + 1);
    block_166:
        if (resultOrArithmetic2 == 0) {
            goto block_169;
        }
        resultOrArithmetic2=overlayContextOrHeading21*4;
        resultOrArithmetic2+=privateStateOrAngle18;
        resultOrArithmetic2=Level22_7DF78Field(resultOrArithmetic2,int*,0x384);
        Level22_7DF78CompleteValue(overlayContextOrHeading21);
        Level22_7DF78Field(privateStateOrAngle18,int*,0x380)=resultOrArithmetic2;
        Level22_7DF78Field(resultOrArithmetic2,short*,2)=offsetOrFlag22;
        Level22_7DF78Field(privateStateOrAngle18, short *, 0x22E) = 0x50;
        if (captured_a1 == 0) {
            goto block_169;
        }
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x380);
        resultOrArithmetic2=Level22_7DF78Field(fieldOrOffset3,short*,10);
        Level22_7DF78CompleteValue(resultOrArithmetic2);
        resultOrArithmetic2=-resultOrArithmetic2;
        Level22_7DF78Field(fieldOrOffset3,short*,10)=resultOrArithmetic2;
    block_169:
        descriptorOrSavedValue20 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x380);
        descriptorIndexOrHeading17 = 0;
        actorFrameOrHeading16 = 0;
    loop_170:
        /* Three recorded table words are read unconditionally before either original comparison; no table-count bound is fabricated. */
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x4A0);
        resultOrArithmetic2=actorFrameOrHeading16+resultOrArithmetic2;
        fieldOrOffset3=Level22_7DF78Field(resultOrArithmetic2,volatile int*,0);
        argumentOrIndex6=Level22_7DF78Field(resultOrArithmetic2,volatile int*,4);
        fieldOrOffset3=fieldOrOffset3*4+privateStateOrAngle18;
        argumentOrField5=Level22_7DF78Field(fieldOrOffset3,int*,0x384);
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x380);
        argumentOrAddress4=Level22_7DF78Field(resultOrArithmetic2,volatile int*,8);
        if(argumentOrField5!=fieldOrOffset3) {
            goto block_173;
        }
        resultOrArithmetic2=Level22_7DF78Field(argumentOrField5,short*,2);
        argumentOrField5=privateStateOrAngle18+0x3B8;
        if(resultOrArithmetic2!=argumentOrIndex6) {
            goto block_173;
        }
        Level22_7DF78_unk_ovlheader_8007443C(argumentOrAddress4,argumentOrField5,1);
    block_173:
        descriptorIndexOrHeading17 += 1;
        actorFrameOrHeading16 += 0xC;
        if (descriptorIndexOrHeading17 < 2) {
            goto loop_170;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0) {
            goto block_201;
        }
        resultOrArithmetic2=Level22_7DF78Field(descriptorOrSavedValue20,short*,2);
        fieldOrOffset3=Level22_7DF78Field(descriptorOrSavedValue20,int*,12);
        resultOrArithmetic2*=16;
        fieldOrOffset3+=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78Field(fieldOrOffset3,unsigned char*,14);
        fieldOrOffset3=Level22_7DF78_D_8006C7C4;
        argumentOrAddress4=resultOrArithmetic2&31;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x23C)=argumentOrAddress4;
        resultOrArithmetic2=1;
        if(fieldOrOffset3!=resultOrArithmetic2) {
            goto block_179;
        }
        resultOrArithmetic2=15;
        if(argumentOrAddress4==resultOrArithmetic2) {
            goto block_178;
        }
        resultOrArithmetic2=2;
        if(argumentOrAddress4!=resultOrArithmetic2) {
            goto block_179;
        }
    block_178:
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
    block_179:
        if (Level22_7DF78_D_8006C7C4 != 2) {
            goto block_183;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0x11) {
            goto block_185;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x258) >= 0xE10) {
            goto block_184;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 7;
    block_183:
    block_184:
    block_185:
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x240) = 0;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x244) = 0;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) = 0;
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 3) {
            goto block_191;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 6) {
            goto block_191;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 9) {
            goto block_191;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 0xC) {
            goto block_191;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 0x10) {
            goto block_191;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0x13) {
            goto block_201;
        }
    block_191:
        if (Level22_7DF78_D_8006C7C4 != 2) {
            goto block_196;
        }
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 6) {
            goto block_194;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 9;
    block_194:
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0x10) {
            goto block_196;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0x13;
    block_196:
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) = 0x136;
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 6) {
            goto block_198;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) = 0x14A;
    block_198:
        if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 9) {
            goto block_200;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) = 0x186;
    block_200:
        resultOrArithmetic2=Level22_7DF78Field(owner19,short*,0x38);
        fieldOrOffset3=Level22_7DF78Field(owner19,int*,0x14);
        argumentOrAddress4=1;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x254)=argumentOrAddress4;
        fieldOrOffset3-=resultOrArithmetic2;
        fieldOrOffset3+=300;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x250)=fieldOrOffset3;
    block_201:
        captured_v1_14 = Level22_7DF78Field(owner19, int *, 0x14) - originalFrame.sp58;
        if (captured_v1_14 >= 0) {
            goto block_204;
        }
        fieldOrOffset3=captured_v1_14;
        resultOrArithmetic2=0x38E38E39;
        __asm__("":"=r"(resultOrArithmetic2),"=r"(fieldOrOffset3):"0"(resultOrArithmetic2),"1"(fieldOrOffset3));
        fieldOrOffset3=(int)(0U-(unsigned)fieldOrOffset3);
        heightDifferenceProductA.full=(long long)fieldOrOffset3*(long long)resultOrArithmetic2;
        Level22_7DF78WholeProduct(heightDifferenceProductA);
        fieldOrOffset3>>=31;
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x3B0);
        __asm__("":"=x"(heightDifferenceProductA.full):"0"(heightDifferenceProductA.full),"r"(resultOrArithmetic2));
        productWord9=heightDifferenceProductA.words.high;
        Level22_7DF78CompleteValue(productWord9);
        argumentOrAddress4=productWord9>>2;
        argumentOrAddress4-=fieldOrOffset3;
        captured_v0_16=resultOrArithmetic2+argumentOrAddress4;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = captured_v0_16;
        if (captured_v0_16 < 0x119) {
            goto block_204;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = 0x118;
    block_204:
        captured_v0_17 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) - 3;
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = captured_v0_17;
        if (captured_v0_17 >= 0) {
            goto block_206;
        }
        Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = 0;
    block_206:
        captured_v0_18 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C);
        if ((unsigned int) (captured_v0_18 - 1) >= 0x13U) {
            goto block_365;
        }
        switch (captured_v0_18){
            default:goto block_365;
        case 1:
        case 4:
        case 7:
        case 10:
        case 14:
        case 17:
            actorFrameOrHeading16=256;
            Level22_7DF78CompleteValue(actorFrameOrHeading16);
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x240);
            captured_v1_15=Level22_7DF78Field(privateStateOrAngle18,int*,0x23C);
            if(resultOrArithmetic2>=0) {
                goto block_210;
            }
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        block_210:
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            descriptorOrSavedValue20=(int)((unsigned)resultOrArithmetic2+32U);
            resultOrArithmetic2=4;
            descriptorIndexOrHeading17=0;
            if(captured_v1_15==resultOrArithmetic2) goto block_212;
            resultOrArithmetic2=14;
            if(captured_v1_15!=resultOrArithmetic2) goto block_213;
        block_212:
            actorFrameOrHeading16=512;
            captured_v1_15=Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x23C);
        block_213:
            /* Original complete7/17 and conditional state reload are retained at their actual shared consumers. */
            resultOrArithmetic2=7;
            __asm__ __volatile__(""::"r"(resultOrArithmetic2));
            if(captured_v1_15==resultOrArithmetic2) {
                resultOrArithmetic2=17;
                goto block_215;
            }
            resultOrArithmetic2=17;
            if(captured_v1_15!=resultOrArithmetic2) goto block_216;
        block_215:
            __asm__ __volatile__(""::"r"(resultOrArithmetic2));
            actorFrameOrHeading16+=512;
        block_216:
            captured_v1_16 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C);
            if (captured_v1_16 == 0xA) {
                goto block_219;
            }
            if (captured_v1_16 == 0xE) {
                goto block_219;
            }
            if (captured_v1_16 != 0x11) {
                goto block_220;
            }
        block_219:
            descriptorIndexOrHeading17 = 1;
        block_220:
            Level22_7DF78Field(privateStateOrAngle18, short *, 0x444) = 2;
            captured_v1_17 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
            if (captured_v1_17 != 3) {
                goto block_222;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=7;
            goto block_225;
        block_222:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_226;
            }
            if (captured_v1_17 == 8) {
                goto block_226;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=8;
        block_225:
            Level22_7DF78Field(owner19,unsigned char*,0x3D)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,signed char*,0x3F)=0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_226:
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3C) != 8) {
                goto block_235;
            }
            fieldOrOffset3 = 0xC;
            if (descriptorIndexOrHeading17 == 0) {
                goto block_229;
            }
            fieldOrOffset3 = -0xC;
        block_229:
            argumentOrIndex6 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x240);
            working_v0_18 = argumentOrIndex6;
            if (argumentOrIndex6 >= 0) {
                goto block_231;
            }
            working_v0_18 = -working_v0_18;
        block_231:
            captured_a0_13 = working_v0_18 + fieldOrOffset3;
            working_a1_2 = fieldOrOffset3;
            if (actorFrameOrHeading16 >= captured_a0_13) {
                goto block_233;
            }
            working_a1_2 = captured_a0_13 - actorFrameOrHeading16;
        block_233:
            if (working_a1_2 == 0) {
                goto block_235;
            }
            resultOrArithmetic2=argumentOrIndex6+fieldOrOffset3;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(privateStateOrAngle18,int*,0x240)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x44) = (unsigned char) (Level22_7DF78Field(owner19, unsigned char *, 0x44) + fieldOrOffset3);
        block_235:
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,576);
            fieldOrOffset3=descriptorOrSavedValue20;
            Level22_7DF78CompleteValue(fieldOrOffset3);
            argumentOrIndex6=resultOrArithmetic2;
            if(resultOrArithmetic2>=0) goto block_237;
            argumentOrIndex6=(int)(0U-(unsigned)argumentOrIndex6);
        block_237:
            argumentOrAddress4=argumentOrIndex6+32;
            if(fieldOrOffset3>=0) goto block_239;
            fieldOrOffset3+=255;
        block_239:
            resultOrArithmetic2=argumentOrAddress4;
            argumentOrField5=fieldOrOffset3>>8;
            if(argumentOrAddress4>=0) goto block_241;
            resultOrArithmetic2=argumentOrIndex6+287;
        block_241:
            fieldOrOffset3=resultOrArithmetic2>>8;
            if(argumentOrField5==fieldOrOffset3) {
                goto block_254;
            }
            argumentOrAddress4 = 0;
            if (fieldOrOffset3 == 2) {
                goto block_249;
            }
            if (fieldOrOffset3 >= 3) {
                goto block_246;
            }
            if (fieldOrOffset3 == 1) {
                goto block_248;
            }
            goto block_251;
        block_246:
            if (fieldOrOffset3 == 3) {
                goto block_250;
            }
            goto block_251;
        block_248:
            argumentOrAddress4 = 0x10;
            goto block_251;
        block_249:
            argumentOrAddress4 = 0x11;
            goto block_251;
        block_250:
            argumentOrAddress4 = 0x12;
        block_251:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) < 0xA) {
                goto block_253;
            }
            argumentOrAddress4 += 0xC;
        block_253:
            Level22_7DF78_unk_ovlheader_8007443C(argumentOrAddress4, privateStateOrAngle18 + 0x3B8, 0);
        block_254:
            resultOrArithmetic2 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x240);
            if (resultOrArithmetic2 >= 0) {
                goto block_256;
            }
            resultOrArithmetic2 = -resultOrArithmetic2;
        block_256:
            descriptorIndexOrHeading17 = owner19 + 0xC;
            if (actorFrameOrHeading16 >= resultOrArithmetic2) {
                goto block_366;
            }
            goto block_362;
        case 2:
        case 5:
        case 8:
        case 11:
        case 15:
        case 18:
            actorFrameOrHeading16=256;
            Level22_7DF78CompleteValue(actorFrameOrHeading16);
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x244);
            fieldOrOffset3=Level22_7DF78_D_8006C7C4;
            if(resultOrArithmetic2>=0) goto block_260;
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        block_260:
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            descriptorOrSavedValue20=(int)((unsigned)resultOrArithmetic2+32U);
            resultOrArithmetic2=2;
            descriptorIndexOrHeading17=0;
            if(fieldOrOffset3!=resultOrArithmetic2) goto block_265;
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != fieldOrOffset3) {
                goto block_263;
            }
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 5;
        block_263:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0xB) {
                goto block_266;
            }
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0xF;
        block_265:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 0xB) {
                goto block_268;
            }
        block_266:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 0xF) {
                goto block_268;
            }
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0x12) {
                goto block_269;
            }
        block_268:
            descriptorIndexOrHeading17 = 1;
        block_269:
            captured_v1_19 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C);
            if (captured_v1_19 == 5) {
                goto block_271;
            }
            if (captured_v1_19 != 0xF) {
                goto block_272;
            }
        block_271:
            actorFrameOrHeading16+=256;
        block_272:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) == 8) {
                goto block_274;
            }
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0x12) {
                goto block_275;
            }
        block_274:
            actorFrameOrHeading16 += 0x200;
        block_275:
            Level22_7DF78Field(privateStateOrAngle18, short *, 0x444) = 2;
            captured_v1_20 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
            if (captured_v1_20 != 3) {
                goto block_277;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=7;
            goto block_280;
        block_277:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_281;
            }
            if (captured_v1_20 == 8) {
                goto block_281;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=8;
        block_280:
            Level22_7DF78Field(owner19,unsigned char*,0x3D)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,signed char*,0x3F)=0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_281:
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3C) != 8) {
                goto block_290;
            }
            fieldOrOffset3 = 0xC;
            if (descriptorIndexOrHeading17 == 0) {
                goto block_284;
            }
            fieldOrOffset3 = -0xC;
        block_284:
            captured_a1_3 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x244) + fieldOrOffset3;
            argumentOrAddress4 = captured_a1_3;
            if (captured_a1_3 >= 0) {
                goto block_286;
            }
            argumentOrAddress4 = -argumentOrAddress4;
        block_286:
            if (actorFrameOrHeading16 >= argumentOrAddress4) {
                goto block_288;
            }
            fieldOrOffset3 = argumentOrAddress4 - actorFrameOrHeading16;
        block_288:
            if (fieldOrOffset3 == 0) {
                goto block_290;
            }
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x244) = captured_a1_3;
        block_290:
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,580);
            fieldOrOffset3=descriptorOrSavedValue20;
            Level22_7DF78CompleteValue(fieldOrOffset3);
            argumentOrIndex6=resultOrArithmetic2;
            if(resultOrArithmetic2>=0) goto block_292;
            argumentOrIndex6=(int)(0U-(unsigned)argumentOrIndex6);
        block_292:
            argumentOrAddress4=argumentOrIndex6+32;
            if(fieldOrOffset3>=0) goto block_294;
            fieldOrOffset3+=255;
        block_294:
            resultOrArithmetic2=argumentOrAddress4;
            argumentOrField5=fieldOrOffset3>>8;
            if(argumentOrAddress4>=0) goto block_296;
            resultOrArithmetic2=argumentOrIndex6+287;
        block_296:
            fieldOrOffset3=resultOrArithmetic2>>8;
            if(argumentOrField5==fieldOrOffset3) {
                goto block_309;
            }
            argumentOrAddress4 = 0;
            if (fieldOrOffset3 == 2) {
                goto block_304;
            }
            if (fieldOrOffset3 >= 3) {
                goto block_301;
            }
            if (fieldOrOffset3 == 1) {
                goto block_303;
            }
            goto block_306;
        block_301:
            if (fieldOrOffset3 == 3) {
                goto block_305;
            }
            goto block_306;
        block_303:
            argumentOrAddress4 = 0xC;
            goto block_306;
        block_304:
            argumentOrAddress4 = 0xD;
            goto block_306;
        block_305:
            argumentOrAddress4 = 0xE;
        block_306:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) < 0xA) {
                goto block_308;
            }
            argumentOrAddress4 += 0xC;
        block_308:
            Level22_7DF78_unk_ovlheader_8007443C(argumentOrAddress4, privateStateOrAngle18 + 0x3B8, 0);
        block_309:
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x244);
            fieldOrOffset3=Level22_7DF78Field(owner19,unsigned char*,0x45);
            fieldOrOffset3-=resultOrArithmetic2;
            Level22_7DF78Field(owner19,unsigned char*,0x45)=fieldOrOffset3;
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x244);
            if(resultOrArithmetic2>=0) goto block_311;
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        block_311:
            resultOrArithmetic2=actorFrameOrHeading16<resultOrArithmetic2;
            descriptorIndexOrHeading17=owner19+12;
            if(!resultOrArithmetic2) goto block_366;
            goto block_362;
        case 3:
        case 6:
        case 9:
        case 12:
        case 16:
        case 19:
            descriptorIndexOrHeading17=128;
            Level22_7DF78CompleteValue(descriptorIndexOrHeading17);
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x248);
            captured_v1_22=Level22_7DF78Field(privateStateOrAngle18,int*,0x23C);
            if(resultOrArithmetic2>=0) {
                goto block_315;
            }
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        block_315:
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            overlayContextOrHeading21=(int)((unsigned)resultOrArithmetic2+160U);
            resultOrArithmetic2=6;
            descriptorOrSavedValue20=0;
            if(captured_v1_22==resultOrArithmetic2) goto block_317;
            resultOrArithmetic2=16;
            if(captured_v1_22!=resultOrArithmetic2) goto block_318;
        block_317:
            descriptorIndexOrHeading17=384;
            captured_v1_22=Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x23C);
        block_318:
            /* Original complete9/19 and conditional state reload are retained at their actual shared consumers. */
            resultOrArithmetic2=9;
            __asm__ __volatile__(""::"r"(resultOrArithmetic2));
            if(captured_v1_22==resultOrArithmetic2) {
                resultOrArithmetic2=19;
                goto block_320;
            }
            resultOrArithmetic2=19;
            if(captured_v1_22!=resultOrArithmetic2) goto block_321;
        block_320:
            __asm__ __volatile__(""::"r"(resultOrArithmetic2));
            descriptorIndexOrHeading17+=512;
        block_321:
            captured_v1_23 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C);
            if (captured_v1_23 == 0xC) {
                goto block_324;
            }
            if (captured_v1_23 == 0x10) {
                goto block_324;
            }
            if (captured_v1_23 != 0x13) {
                goto block_325;
            }
        block_324:
            descriptorOrSavedValue20 = 1;
        block_325:
            captured_v1_24 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
            if (captured_v1_24 != 3) {
                goto block_327;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=7;
            goto block_330;
        block_327:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_331;
            }
            if (captured_v1_24 == 8) {
                goto block_331;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=8;
        block_330:
            Level22_7DF78Field(owner19,unsigned char*,0x3D)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,signed char*,0x3F)=0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_331:
            working_v1_8 = 0xE;
            if ((unsigned int) (Level22_7DF78Field(owner19, unsigned char *, 0x3C) - 7) >= 2U) {
                goto block_340;
            }
            actorFrameOrHeading16 = 0xE;
            if (descriptorOrSavedValue20 == 0) {
                goto block_334;
            }
            working_v1_8 = -0xE;
        block_334:
            resultOrArithmetic2 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) + working_v1_8;
            working_v1_9 = resultOrArithmetic2;
            if (resultOrArithmetic2 >= 0) {
                goto block_336;
            }
            working_v1_9 = -working_v1_9;
        block_336:
            if (descriptorIndexOrHeading17 >= working_v1_9) {
                goto block_338;
            }
            actorFrameOrHeading16 = working_v1_9 - descriptorIndexOrHeading17;
        block_338:
            if (actorFrameOrHeading16 == 0) {
                goto block_340;
            }
            argumentOrField5=0;
            __asm__("":"=r"(argumentOrField5):"0"(argumentOrField5):"$4");
            argumentOrAddress4=owner19;
            argumentOrIndex6=0;
            Level22_7DF78_unk_ovlheader_80074434(argumentOrAddress4,argumentOrField5,argumentOrIndex6,actorFrameOrHeading16);
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) = (int) (Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) + actorFrameOrHeading16);
        block_340:
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,584);
            fieldOrOffset3=overlayContextOrHeading21;
            Level22_7DF78CompleteValue(fieldOrOffset3);
            argumentOrIndex6=resultOrArithmetic2;
            if(resultOrArithmetic2>=0) goto block_342;
            argumentOrIndex6=(int)(0U-(unsigned)argumentOrIndex6);
        block_342:
            argumentOrAddress4=argumentOrIndex6+160;
            if(fieldOrOffset3>=0) goto block_344;
            fieldOrOffset3+=255;
        block_344:
            resultOrArithmetic2=argumentOrAddress4;
            argumentOrField5=fieldOrOffset3>>8;
            if(argumentOrAddress4>=0) goto block_346;
            resultOrArithmetic2=argumentOrIndex6+415;
        block_346:
            fieldOrOffset3=resultOrArithmetic2>>8;
            if(argumentOrField5==fieldOrOffset3) {
                goto block_359;
            }
            argumentOrAddress4 = 0;
            if (fieldOrOffset3 == 2) {
                goto block_354;
            }
            if (fieldOrOffset3 >= 3) {
                goto block_351;
            }
            if (fieldOrOffset3 == 1) {
                goto block_353;
            }
            goto block_356;
        block_351:
            if (fieldOrOffset3 == 3) {
                goto block_355;
            }
            goto block_356;
        block_353:
            argumentOrAddress4 = 0x14;
            goto block_356;
        block_354:
            argumentOrAddress4 = 0x15;
            goto block_356;
        block_355:
            argumentOrAddress4 = 0x16;
        block_356:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) < 0xA) {
                goto block_358;
            }
            argumentOrAddress4 += 0xC;
        block_358:
            Level22_7DF78_unk_ovlheader_8007443C(argumentOrAddress4, privateStateOrAngle18 + 0x3B8, 0);
        block_359:
            working_v0_28 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x248);
            if (working_v0_28 >= 0) {
                goto block_361;
            }
            working_v0_28 = -working_v0_28;
        block_361:
            resultOrArithmetic2=working_v0_28<descriptorIndexOrHeading17;
            descriptorIndexOrHeading17=owner19+12;
            if(resultOrArithmetic2) {
                goto block_366;
            }
        block_362:
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 3) {
                goto block_364;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 3U;
            Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_364:
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
        case 13:
        block_365:
            descriptorIndexOrHeading17 = owner19 + 0xC;
        block_366:
            Level22_7DF78_func_8001A358(descriptorIndexOrHeading17, 0x2EE0);
            Level22_7DF78_func_8005629C(owner19);
            originalFrame.sp60 = 0;
            originalFrame.sp64 = 0;
            originalFrame.sp68 = (int) -Level22_7DF78Field(owner19, short *, 0x38);
            Level22_7DF78_func_80055D24(owner19, 4);
            Level22_7DF78_func_8004ED6C(owner19 + 0x20, &originalFrame.sp60, &originalFrame.sp60);
            Level22_7DF78_func_8004F178(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) + 0xC, descriptorIndexOrHeading17);
            captured_a0_17 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) + 0xC;
            Level22_7DF78_func_8004F194(captured_a0_17, captured_a0_17, &originalFrame.sp60);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x46) = (unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x46);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x45) = (unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x45);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x44) = (unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x44);
            return;
        }
    case 21:
        argumentOrAddress4=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
        Level22_7DF78CompleteValue(argumentOrAddress4);
        argumentOrAddress4=argumentOrAddress4*4+privateStateOrAngle18;
        fieldOrOffset3=Level22_7DF78Field(argumentOrAddress4,int*,0xA0);
        descriptorIndexOrHeading17=Level22_7DF78Field(argumentOrAddress4,int*,0xB8);
        resultOrArithmetic2=fieldOrOffset3*88;
        fieldOrOffset3=Level22_7DF78_D_8006C550;
        descriptorOrSavedValue20=fieldOrOffset3+resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x49);
        actorFrameOrHeading16=Level22_7DF78Field(argumentOrAddress4,int*,0xD0);
        if(resultOrArithmetic2!=0) {
            resultOrArithmetic2=(unsigned)resultOrArithmetic2<2U;
            goto block_372;
        }
        __asm__ __volatile__(""::"r"(privateStateOrAngle18):"memory");
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
        Level22_7DF78CompleteValue(fieldOrOffset3);
        resultOrArithmetic2=7000;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x20C)=resultOrArithmetic2;
        resultOrArithmetic2=2000;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x218)=resultOrArithmetic2;
        resultOrArithmetic2=1000;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x21C)=resultOrArithmetic2;
        resultOrArithmetic2=5;
        argumentOrIndex6=0;
        if(fieldOrOffset3!=resultOrArithmetic2) {
            goto block_370;
        }
        resultOrArithmetic2=2500;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x218)=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
        argumentOrField7=Level22_7DF78Field(resultOrArithmetic2,int*,16);
        argumentOrAddress4=Level22_7DF78Field(resultOrArithmetic2,int*,0);
        fieldOrOffset3=Level22_7DF78Field(resultOrArithmetic2,int*,20);
        argumentOrField5=Level22_7DF78Field(resultOrArithmetic2,int*,4);
        argumentOrAddress4=argumentOrField7-argumentOrAddress4;
        resultOrArithmetic2=Level22_7DF78_func_8004E880(argumentOrAddress4,fieldOrOffset3-argumentOrField5,argumentOrIndex6);
        resultOrArithmetic2-=50;
        goto block_371;
    block_370:
        resultOrArithmetic2=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
        argumentOrField7=Level22_7DF78Field(resultOrArithmetic2,int*,16);
        argumentOrAddress4=Level22_7DF78Field(resultOrArithmetic2,int*,0);
        fieldOrOffset3=Level22_7DF78Field(resultOrArithmetic2,int*,20);
        argumentOrField5=Level22_7DF78Field(resultOrArithmetic2,int*,4);
        argumentOrAddress4=argumentOrField7-argumentOrAddress4;
        resultOrArithmetic2=Level22_7DF78_func_8004E880(argumentOrAddress4,fieldOrOffset3-argumentOrField5,argumentOrIndex6);
        resultOrArithmetic2-=20;
    block_371:
        resultOrArithmetic2=(resultOrArithmetic2&255)*16;
        Level22_7DF78Field(privateStateOrAngle18,int*,0x210)=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x49);
        resultOrArithmetic2=(unsigned)resultOrArithmetic2<2;
    block_372:
        argumentOrAddress4=(int)&originalFrame.sp70;
        if(resultOrArithmetic2==0) {
            goto block_374;
        }
        argumentOrField5=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
        goto block_375;
    block_374:
        argumentOrField5=owner19+12;
    block_375:
        Level22_7DF78_func_8004F178(argumentOrAddress4,argumentOrField5);
        originalFrame.sp78 += Level22_7DF78Field(privateStateOrAngle18, int *, 0x21C);
        if ((unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x49) < 3U) {
            goto block_379;
        }
        captured_v1_26 = (unsigned short) Level22_7DF78Field(privateStateOrAngle18, short *, 0x208);
        if (captured_v1_26 < 2U) {
            goto block_379;
        }
        if ((short) captured_v1_26 == 2) {
            goto block_379;
        }
        if ((short) captured_v1_26 != 5) {
            goto block_380;
        }
    block_379:
        Level22_7DF78_func_8004F178(&originalFrame.sp50, owner19 + 0xC);
        resultOrArithmetic2=Level22_7DF78_func_8004EA2C(Level22_7DF78Field(privateStateOrAngle18,int*,0x210));
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x20C);
        fieldOrOffset3=(int)(0U-(unsigned)fieldOrOffset3);
        sineProductB.full=(long long)resultOrArithmetic2*(long long)fieldOrOffset3;
        Level22_7DF78WholeProduct(sineProductB);
        resultOrArithmetic2=originalFrame.sp50;
        __asm__("":"=x"(sineProductB.full):"0"(sineProductB.full),"r"(resultOrArithmetic2));
        productWord9=(int)sineProductB.words.low;
        Level22_7DF78CompleteValue(productWord9);
        fieldOrOffset3=productWord9>>12;
        resultOrArithmetic2+=fieldOrOffset3;
        originalFrame.sp50=resultOrArithmetic2;
        resultOrArithmetic2=Level22_7DF78_func_8004E9E4(Level22_7DF78Field(privateStateOrAngle18,int*,0x210));
        fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,int*,0x20C);
        fieldOrOffset3=(int)(0U-(unsigned)fieldOrOffset3);
        cosineProductB.full=(long long)resultOrArithmetic2*(long long)fieldOrOffset3;
        Level22_7DF78WholeProduct(cosineProductB);
        resultOrArithmetic2=originalFrame.sp54;
        __asm__("":"=x"(cosineProductB.full):"0"(cosineProductB.full),"r"(resultOrArithmetic2));
        productWord9=(int)cosineProductB.words.low;
        Level22_7DF78CompleteValue(productWord9);
        fieldOrOffset3=productWord9>>12;
        resultOrArithmetic2+=fieldOrOffset3;
        originalFrame.sp54=resultOrArithmetic2;
        originalFrame.sp58 += Level22_7DF78Field(privateStateOrAngle18, int *, 0x218);
        goto block_381;
    block_380:
        Level22_7DF78_func_8004F178(&originalFrame.sp50, (int)&Level22_7DF78_D_8006E020);
    block_381:
        captured_v0_26 = Level22_7DF78Field(owner19, unsigned char *, 0x49);
        if (captured_v0_26 != 0) {
            goto block_383;
        }
        captured_v0_27 = Level22_7DF78Field(descriptorIndexOrHeading17, int*, 0xC);
        captured_a3_9 = Level22_7DF78Field(captured_v0_27, int *, 0x10);
        captured_v0_28 = Level22_7DF78_func_8004E880(captured_a3_9 - Level22_7DF78Field(captured_v0_27, int *, 0), Level22_7DF78Field(captured_v0_27, int *, 0x14) - Level22_7DF78Field(captured_v0_27, int *, 4), 0);
        actorFrameOrHeading16=captured_v0_28;
        Level22_7DF78CompleteValue(actorFrameOrHeading16);
        privateStateOrAngle18=actorFrameOrHeading16-32;
        actorFrameOrHeading16+=96;
        argumentOrField5=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
        descriptorIndexOrHeading17=(int)&originalFrame.sp80;
        Level22_7DF78_func_8004F178(descriptorIndexOrHeading17,argumentOrField5);
        argumentOrAddress4=descriptorIndexOrHeading17;
        argumentOrField5=privateStateOrAngle18&255;
        __asm__("":"=r"(actorFrameOrHeading16),"=r"(argumentOrAddress4),"=r"(argumentOrField5):"0"(actorFrameOrHeading16),"1"(argumentOrAddress4),"2"(argumentOrField5));
        actorFrameOrHeading16=(actorFrameOrHeading16&255)*2;
        originalFrame.sp80 += (int) (Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + actorFrameOrHeading16) * 0x7D) >> 8;
        originalFrame.sp84 += (int) (Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + actorFrameOrHeading16) * 0x7D) >> 8;
        Level22_7DF78_func_80013D44(argumentOrAddress4,argumentOrField5,0,0);
        goto block_531;
    block_383:
        if ((unsigned int) (captured_v0_26 - 1) >= 5U) {
            goto block_608;
        }
        switch (captured_v0_26){
            default:goto block_608;
        case 1:
            if (!(Level22_7DF78_D_8006E048 & 1)) {
                goto block_608;
            }
            Level22_7DF78_func_80013AE4(&originalFrame.sp50, &originalFrame.sp70);
            Level22_7DF78_func_8004F178(owner19 + 0xC, Level22_7DF78Field(descriptorIndexOrHeading17, int*, 0xC));
            Level22_7DF78Field(owner19, int *, 0x14) = (int) (Level22_7DF78Field(owner19, int *, 0x14) + Level22_7DF78Field(owner19, short *, 0x38));
            captured_v0_29 = Level22_7DF78Field(descriptorIndexOrHeading17, int*, 0xC);
            captured_a3_10 = Level22_7DF78Field(captured_v0_29, int *, 0x10);
            Level22_7DF78Field(owner19, unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_10 - Level22_7DF78Field(captured_v0_29, int *, 0), Level22_7DF78Field(captured_v0_29, int *, 0x14) - Level22_7DF78Field(captured_v0_29, int *, 4), 0);
            captured_v0_30 = Level22_7DF78_SpawnMoby(0x157, owner19);
            Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) = captured_v0_30;
            if (captured_v0_30 == 0) {
                goto block_388;
            }
            Level22_7DF78Field(captured_v0_30, signed char *, 0x47) = 0;
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x4C) = 0x30U;
            captured_v1_27 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220);
            Level22_7DF78Field(captured_v1_27, unsigned char *, 0x4E) = (unsigned char) Level22_7DF78Field(captured_v1_27, unsigned char *, 0x4C);
            captured_v0_31 = Level22_7DF78Field(descriptorIndexOrHeading17, int*, 0xC);
            captured_a3_11 = Level22_7DF78Field(captured_v0_31, int *, 0x10);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_11 - Level22_7DF78Field(captured_v0_31, int *, 0), Level22_7DF78Field(captured_v0_31, int *, 0x14) - Level22_7DF78Field(captured_v0_31, int *, 4), 0);
            captured_a0_19 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220);
            Level22_7DF78Field(captured_a0_19, int *, 0x14) = (int) (Level22_7DF78Field(captured_a0_19, int *, 0x14) - Level22_7DF78Field(owner19, short *, 0x38));
        block_388:
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 2) {
                goto block_531;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 2U;
            Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
            goto block_531;
        case 2:
            Level22_7DF78_func_800492DC(owner19 + 0xC);
            Level22_7DF78_func_80013AE4(&originalFrame.sp50, &originalFrame.sp70);
            resultOrArithmetic2=-1;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
            Level22_7DF78CompleteValue(fieldOrOffset3);
            argumentOrAddress4=60;
            Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x228)=resultOrArithmetic2;
            Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22A)=resultOrArithmetic2;
            resultOrArithmetic2=16;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(privateStateOrAngle18,short*,0x22E)=resultOrArithmetic2;
            resultOrArithmetic2=1;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(privateStateOrAngle18,short*,0x236)=resultOrArithmetic2;
            __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4),"m"(Level22_7DF78Field(privateStateOrAngle18,short*,0x236)));
            Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22C)=argumentOrAddress4;
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = 0;
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x254) = 0;
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
            if (fieldOrOffset3 != 3) {
                goto block_392;
            }
            Level22_7DF78Field(privateStateOrAngle18,short*,0x22E)=argumentOrAddress4;
            Level22_7DF78Field(privateStateOrAngle18,short*,0x236)=0;
            goto block_396;
        block_392:
            if (fieldOrOffset3 != 4) {
                goto block_394;
            }
            Level22_7DF78Field(privateStateOrAngle18, short *, 0x22E) = 0x46;
            Level22_7DF78Field(privateStateOrAngle18, short *, 0x236) = 0;
            goto block_396;
        block_394:
            if (fieldOrOffset3 != 5) {
                goto block_396;
            }
            Level22_7DF78Field(privateStateOrAngle18,short*,0x22E)=argumentOrAddress4;
        block_396:
            Level22_7DF78Field(descriptorIndexOrHeading17, short *, 2) = 0;
            goto block_531;
        case 3:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_400;
            }
            actorFrameOrHeading16 = owner19 + 0xC;
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) != 2) {
                goto block_401;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 3U;
            Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_400:
            actorFrameOrHeading16 = owner19 + 0xC;
        block_401:
            Level22_7DF78_func_800492DC(actorFrameOrHeading16);
            Level22_7DF78_func_80013AE4(&originalFrame.sp50, &originalFrame.sp70);
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) != 2) {
                goto block_403;
            }
            if (Level22_7DF78_func_80055E84(owner19) < 0x33) {
                goto block_608;
            }
        block_403:
            captured_v0_32 = Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) + 0x1E;
            Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) = captured_v0_32;
            if ((short) captured_v0_32 < 0x12D) {
                goto block_405;
            }
            Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) = 0x12CU;
        block_405:
            Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) = (unsigned short) (Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22C) + Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0));
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x254) == 0) {
                goto block_447;
            }
            argumentOrAddress4=actorFrameOrHeading16;
            argumentOrField5=Level22_7DF78Field(descriptorIndexOrHeading17,short*,2);
            resultOrArithmetic2=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
            argumentOrField5*=16;
            argumentOrField5=resultOrArithmetic2+argumentOrField5;
            resultOrArithmetic2=Level22_7DF78_func_8004F334(argumentOrAddress4,argumentOrField5);
            argumentOrAddress4=resultOrArithmetic2;
            resultOrArithmetic2=Level22_7DF78Field(descriptorIndexOrHeading17,short*,2);
            fieldOrOffset3=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
            argumentOrField5=Level22_7DF78Field(owner19,int*,20);
            __asm__("":"=r"(resultOrArithmetic2),"=r"(fieldOrOffset3),"=r"(argumentOrField5):"0"(resultOrArithmetic2),"1"(fieldOrOffset3),"2"(argumentOrField5));
            resultOrArithmetic2*=16;
            resultOrArithmetic2+=fieldOrOffset3;
            resultOrArithmetic2=Level22_7DF78Field(resultOrArithmetic2,int*,8);
            argumentOrIndex6=0;
            resultOrArithmetic2=Level22_7DF78_func_8004E880(argumentOrAddress4,resultOrArithmetic2-argumentOrField5,argumentOrIndex6);
            argumentOrIndex6=0;
            Level22_7DF78CompleteValue(argumentOrIndex6);
            fieldOrOffset3=Level22_7DF78Field(descriptorIndexOrHeading17,short*,2);
            __asm__("":"=r"(resultOrArithmetic2),"=r"(fieldOrOffset3):"0"(resultOrArithmetic2),"1"(fieldOrOffset3));
            argumentOrAddress4=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
            descriptorIndexOrHeading17=resultOrArithmetic2;
            fieldOrOffset3*=16;
            fieldOrOffset3+=argumentOrAddress4;
            coordinateOrHeader8=Level22_7DF78Field(fieldOrOffset3,int*,32);
            argumentOrAddress4=Level22_7DF78Field(fieldOrOffset3,int*,0);
            argumentOrField7=Level22_7DF78Field(fieldOrOffset3,int*,36);
            argumentOrField5=Level22_7DF78Field(fieldOrOffset3,int*,4);
            argumentOrAddress4=coordinateOrHeader8-argumentOrAddress4;
            resultOrArithmetic2=Level22_7DF78_func_8004E880(argumentOrAddress4,argumentOrField7-argumentOrField5,argumentOrIndex6);
            argumentOrAddress4=owner19;
            argumentOrField5=2;
            fieldOrOffset3=Level22_7DF78Field(owner19,int*,20);
            argumentOrIndex6=Level22_7DF78Field(privateStateOrAngle18,int*,0x24C);
            __asm__("":"=r"(resultOrArithmetic2):"0"(resultOrArithmetic2),"r"(argumentOrAddress4),"r"(argumentOrField5),"r"(fieldOrOffset3),"r"(argumentOrIndex6));
            actorFrameOrHeading16=resultOrArithmetic2;
            fieldOrOffset3+=argumentOrIndex6;
            Level22_7DF78Field(owner19,int*,20)=fieldOrOffset3;
            Level22_7DF78_func_80055D24(argumentOrAddress4,argumentOrField5);
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) = (int) (Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) - 0xC);
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0) {
                goto block_444;
            }
            fieldOrOffset3=Level22_7DF78_func_8003613C(Level22_7DF78Field(owner19, unsigned char *, 0x44), 0);
            Level22_7DF78CompleteValue(fieldOrOffset3);
            resultOrArithmetic2=fieldOrOffset3;
            if(fieldOrOffset3>=0) {
                goto clamp26790_4_absolute;
            }
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        clamp26790_4_absolute:
            if(resultOrArithmetic2>=10) {
                goto clamp26790_4_upper4;
            }
            if(fieldOrOffset3<3) {
                goto clamp26790_4_lower2;
            }
            fieldOrOffset3=2;
            Level22_7DF78CompleteValue(fieldOrOffset3);
        clamp26790_4_lower2:
            resultOrArithmetic2=fieldOrOffset3<-2;
            if(!resultOrArithmetic2) {
                goto clamp26790_4_upper4;
            }
            fieldOrOffset3=-2;
        clamp26790_4_upper4:
            resultOrArithmetic2=fieldOrOffset3<5;
            if(resultOrArithmetic2) {
                goto clamp26790_4_lower4;
            }
            fieldOrOffset3=4;
            Level22_7DF78CompleteValue(fieldOrOffset3);
        clamp26790_4_lower4:
            resultOrArithmetic2=fieldOrOffset3<-4;
            if(!resultOrArithmetic2) {
                goto clamp26790_4_store;
            }
            fieldOrOffset3=-4;
        clamp26790_4_store:
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x44);
            Level22_7DF78Field(owner19,unsigned char*,0x44)=resultOrArithmetic2+fieldOrOffset3;
            fieldOrOffset3=Level22_7DF78_func_8003613C(Level22_7DF78Field(owner19, unsigned char *, 0x45), descriptorIndexOrHeading17 & 0xFF);
            Level22_7DF78CompleteValue(fieldOrOffset3);
            resultOrArithmetic2=fieldOrOffset3;
            if(fieldOrOffset3>=0) {
                goto clamp26790_5_absolute;
            }
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        clamp26790_5_absolute:
            if(resultOrArithmetic2>=10) {
                goto clamp26790_5_upper4;
            }
            if(fieldOrOffset3<3) {
                goto clamp26790_5_lower2;
            }
            fieldOrOffset3=2;
            Level22_7DF78CompleteValue(fieldOrOffset3);
        clamp26790_5_lower2:
            resultOrArithmetic2=fieldOrOffset3<-2;
            if(!resultOrArithmetic2) {
                goto clamp26790_5_upper4;
            }
            fieldOrOffset3=-2;
        clamp26790_5_upper4:
            resultOrArithmetic2=fieldOrOffset3<5;
            if(resultOrArithmetic2) {
                goto clamp26790_5_lower4;
            }
            fieldOrOffset3=4;
            Level22_7DF78CompleteValue(fieldOrOffset3);
        clamp26790_5_lower4:
            resultOrArithmetic2=fieldOrOffset3<-4;
            if(!resultOrArithmetic2) {
                goto clamp26790_5_store;
            }
            fieldOrOffset3=-4;
        clamp26790_5_store:
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x45);
            Level22_7DF78Field(owner19,unsigned char*,0x45)=resultOrArithmetic2+fieldOrOffset3;
            fieldOrOffset3=Level22_7DF78_func_8003613C(Level22_7DF78Field(owner19, unsigned char *, 0x46), actorFrameOrHeading16 & 0xFF);
            Level22_7DF78CompleteValue(fieldOrOffset3);
            resultOrArithmetic2=fieldOrOffset3;
            if(fieldOrOffset3>=0) {
                goto clamp26790_6_absolute;
            }
            resultOrArithmetic2=(int)(0U-(unsigned)resultOrArithmetic2);
        clamp26790_6_absolute:
            if(resultOrArithmetic2>=10) {
                goto clamp26790_6_upper4;
            }
            if(fieldOrOffset3<3) {
                goto clamp26790_6_lower2;
            }
            fieldOrOffset3=2;
            Level22_7DF78CompleteValue(fieldOrOffset3);
        clamp26790_6_lower2:
            resultOrArithmetic2=fieldOrOffset3<-2;
            if(!resultOrArithmetic2) {
                goto clamp26790_6_upper4;
            }
            fieldOrOffset3=-2;
        clamp26790_6_upper4:
            resultOrArithmetic2=fieldOrOffset3<5;
            if(resultOrArithmetic2) {
                goto clamp26790_6_lower4;
            }
            fieldOrOffset3=4;
            Level22_7DF78CompleteValue(fieldOrOffset3);
        clamp26790_6_lower4:
            resultOrArithmetic2=fieldOrOffset3<-4;
            if(!resultOrArithmetic2) {
                goto clamp26790_6_store;
            }
            fieldOrOffset3=-4;
        clamp26790_6_store:
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
            Level22_7DF78Field(owner19,unsigned char*,0x46)=resultOrArithmetic2+fieldOrOffset3;
        block_444:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x24C) >= 0) {
                goto block_460;
            }
            if ((Level22_7DF78Field(owner19, int *, 0x14) - Level22_7DF78Field(owner19, short *, 0x38)) >= Level22_7DF78Field(privateStateOrAngle18, int *, 0x250)) {
                goto block_460;
            }
            resultOrArithmetic2=descriptorIndexOrHeading17&255;
            resultOrArithmetic2*=16;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x228)=resultOrArithmetic2;
            resultOrArithmetic2=actorFrameOrHeading16&255;
            resultOrArithmetic2*=16;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(privateStateOrAngle18,int*,0x254)=0;
            Level22_7DF78Field(privateStateOrAngle18,unsigned short*,0x22A)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x44) = 0U;
            Level22_7DF78Field(owner19, unsigned char *, 0x45) = (unsigned char) ((unsigned short) Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x228) >> 4);
            Level22_7DF78Field(owner19, unsigned char *, 0x46) = (unsigned char) ((unsigned short) Level22_7DF78Field(privateStateOrAngle18, unsigned short *, 0x22A) >> 4);
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
            goto block_460;
        block_447:
            Level22_7DF78_func_8004F178(&originalFrame.sp90, actorFrameOrHeading16);
            if (Level22_7DF78_unk_ovlheader_800743E8(owner19, descriptorIndexOrHeading17, privateStateOrAngle18 + 0x228) != 1) {
                goto block_455;
            }
            if (Level22_7DF78Field(descriptorIndexOrHeading17, short *, 2) != (Level22_7DF78Field(descriptorIndexOrHeading17, short *, 0) - 1)) {
                goto block_450;
            }
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = (unsigned char) (Level22_7DF78Field(owner19, unsigned char *, 0x49) + 1);
        block_450:
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) != 0) {
                goto block_455;
            }
            resultOrArithmetic2=Level22_7DF78Field(descriptorIndexOrHeading17,short*,2);
            fieldOrOffset3=Level22_7DF78Field(descriptorIndexOrHeading17,int*,12);
            resultOrArithmetic2*=16;
            resultOrArithmetic2+=fieldOrOffset3;
            resultOrArithmetic2=Level22_7DF78Field(resultOrArithmetic2,int*,12);
            Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x240)=0;
            Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x244)=0;
            Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x248)=0;
            Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x23C)=resultOrArithmetic2;
            fieldOrOffset3=Level22_7DF78Field(privateStateOrAngle18,volatile int*,0x23C);
            resultOrArithmetic2=3;
            if(fieldOrOffset3!=resultOrArithmetic2) {
                goto block_455;
            }
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
            if(resultOrArithmetic2!=fieldOrOffset3) {
                resultOrArithmetic2=0x14A;
                goto block_454;
            }
            resultOrArithmetic2=0x14A;
            resultOrArithmetic2=0x118;
        block_454:
            Level22_7DF78Field(privateStateOrAngle18,int*,0x24C)=resultOrArithmetic2;
            resultOrArithmetic2=Level22_7DF78Field(owner19,short*,0x38);
            fieldOrOffset3=Level22_7DF78Field(owner19,int*,0x14);
            argumentOrAddress4=1;
            Level22_7DF78Field(privateStateOrAngle18,int*,0x254)=argumentOrAddress4;
            fieldOrOffset3-=resultOrArithmetic2;
            fieldOrOffset3+=300;
            Level22_7DF78Field(privateStateOrAngle18,int*,0x250)=fieldOrOffset3;
        block_455:
            captured_v1_31 = Level22_7DF78Field(owner19, int *, 0x14) - originalFrame.sp98;
            if (captured_v1_31 >= 0) {
                goto block_458;
            }
            fieldOrOffset3=captured_v1_31;
            resultOrArithmetic2=0x38E38E39;
            __asm__("":"=r"(resultOrArithmetic2),"=r"(fieldOrOffset3):"0"(resultOrArithmetic2),"1"(fieldOrOffset3));
            fieldOrOffset3=(int)(0U-(unsigned)fieldOrOffset3);
            heightDifferenceProductB.full=(long long)fieldOrOffset3*(long long)resultOrArithmetic2;
            Level22_7DF78WholeProduct(heightDifferenceProductB);
            fieldOrOffset3>>=31;
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x3B0);
            __asm__("":"=x"(heightDifferenceProductB.full):"0"(heightDifferenceProductB.full),"r"(resultOrArithmetic2));
            productWord9=heightDifferenceProductB.words.high;
            Level22_7DF78CompleteValue(productWord9);
            argumentOrAddress4=productWord9>>2;
            argumentOrAddress4-=fieldOrOffset3;
            captured_v0_33=resultOrArithmetic2+argumentOrAddress4;
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = captured_v0_33;
            if (captured_v0_33 < 0x119) {
                goto block_458;
            }
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = 0x118;
        block_458:
            captured_v0_34 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) - 3;
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = captured_v0_34;
            if (captured_v0_34 >= 0) {
                goto block_460;
            }
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x3B0) = 0;
        block_460:
            captured_a0_20 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C);
            if (captured_a0_20 == 2) {
                goto block_484;
            }
            if (captured_a0_20 >= 3) {
                goto block_464;
            }
            if (captured_a0_20 == 1) {
                goto block_466;
            }
            goto block_529;
        block_464:
            if (captured_a0_20 == 3) {
                goto block_507;
            }
            goto block_529;
        block_466:
            actorFrameOrHeading16 = 0x100;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 5) {
                goto block_468;
            }
            actorFrameOrHeading16 = 0x300;
        block_468:
            captured_v1_32 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
            if (captured_v1_32 != 3) {
                goto block_470;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=7;
            goto block_473;
        block_470:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_474;
            }
            if (captured_v1_32 == 8) {
                goto block_474;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=8;
        block_473:
            Level22_7DF78Field(owner19,unsigned char*,0x3D)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,signed char*,0x3F)=0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_474:
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3C) != 8) {
                goto block_483;
            }
            working_a0_7 = -0xC;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 5) {
                goto block_477;
            }
            working_a0_7 = -0xE;
        block_477:
            argumentOrIndex6 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x240);
            working_v0_45 = argumentOrIndex6;
            if (argumentOrIndex6 >= 0) {
                goto block_479;
            }
            working_v0_45 = -working_v0_45;
        block_479:
            captured_v1_33 = working_v0_45 + working_a0_7;
            working_a1_4 = working_a0_7;
            if (actorFrameOrHeading16 >= captured_v1_33) {
                goto block_481;
            }
            working_a1_4 = captured_v1_33 - actorFrameOrHeading16;
        block_481:
            if (working_a1_4 == 0) {
                goto block_483;
            }
            resultOrArithmetic2=argumentOrIndex6+working_a0_7;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(privateStateOrAngle18,int*,0x240)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x44) = (unsigned char) (Level22_7DF78Field(owner19, unsigned char *, 0x44) + working_a0_7);
        block_483:
            resultOrArithmetic2 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x240);
            goto block_500;
        block_484:
            actorFrameOrHeading16 = 0x100;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 5) {
                goto block_486;
            }
            actorFrameOrHeading16 = 0x300;
        block_486:
            captured_v1_34 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
            if (captured_v1_34 != 3) {
                goto block_488;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=7;
            goto block_491;
        block_488:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_492;
            }
            if (captured_v1_34 == 8) {
                goto block_492;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=8;
        block_491:
            Level22_7DF78Field(owner19,unsigned char*,0x3D)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,signed char*,0x3F)=0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_492:
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3C) != 8) {
                goto block_499;
            }
            working_a0_8 = 0xC;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 5) {
                goto block_495;
            }
            working_a0_8 = 0xE;
        block_495:
            fieldOrOffset3 = working_a0_8;
            captured_a0_21 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x244) + fieldOrOffset3;
            if (actorFrameOrHeading16 >= captured_a0_21) {
                goto block_497;
            }
            fieldOrOffset3 = captured_a0_21 - actorFrameOrHeading16;
        block_497:
            if (fieldOrOffset3 == 0) {
                goto block_499;
            }
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x244) = captured_a0_21;
        block_499:
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x244);
            fieldOrOffset3=Level22_7DF78Field(owner19,unsigned char*,0x45);
            fieldOrOffset3-=resultOrArithmetic2;
            Level22_7DF78Field(owner19,unsigned char*,0x45)=fieldOrOffset3;
            resultOrArithmetic2 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x244);
        block_500:
            if (resultOrArithmetic2 >= 0) {
                goto block_502;
            }
            resultOrArithmetic2 = -resultOrArithmetic2;
        block_502:
            if (actorFrameOrHeading16 >= resultOrArithmetic2) {
                goto block_528;
            }
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 3) {
                goto block_505;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 3U;
            Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_505:
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 5) {
                goto block_528;
            }
            Level22_7DF78Field(privateStateOrAngle18, short *, 0x22E) = 0x10;
            goto block_528;
        block_507:
            descriptorIndexOrHeading17 = 0x80;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 4) {
                goto block_509;
            }
            descriptorIndexOrHeading17 = 0x280;
        block_509:
            captured_v1_35 = Level22_7DF78Field(owner19, unsigned char *, 0x3D);
            if (captured_v1_35 != captured_a0_20) {
                goto block_511;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=7;
            goto block_514;
        block_511:
            if (Level22_7DF78_D_8006C770 == 0) {
                goto block_515;
            }
            if (captured_v1_35 == 8) {
                goto block_515;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            resultOrArithmetic2=8;
        block_514:
            Level22_7DF78Field(owner19,unsigned char*,0x3D)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,signed char*,0x3F)=0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_515:
            if ((unsigned int) (Level22_7DF78Field(owner19, unsigned char *, 0x3C) - 7) >= 2U) {
                goto block_522;
            }
            argumentOrField7 = 0xA;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 4) {
                goto block_518;
            }
            argumentOrField7 = 0xF;
        block_518:
            actorFrameOrHeading16 = argumentOrField7;
            captured_v1_36 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) + actorFrameOrHeading16;
            if (descriptorIndexOrHeading17 >= captured_v1_36) {
                goto block_520;
            }
            actorFrameOrHeading16 = captured_v1_36 - descriptorIndexOrHeading17;
        block_520:
            if (actorFrameOrHeading16 == 0) {
                goto block_522;
            }
            Level22_7DF78_unk_ovlheader_80074434(owner19, 0, 0, actorFrameOrHeading16);
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) = (int) (Level22_7DF78Field(privateStateOrAngle18, int *, 0x248) + actorFrameOrHeading16);
        block_522:
            resultOrArithmetic2 = Level22_7DF78Field(privateStateOrAngle18, int *, 0x248);
            if (resultOrArithmetic2 >= 0) {
                goto block_524;
            }
            resultOrArithmetic2 = -resultOrArithmetic2;
        block_524:
            if (resultOrArithmetic2 < descriptorIndexOrHeading17) {
                goto block_529;
            }
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 3) {
                goto block_527;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 3U;
            Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_527:
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x23C) = 0;
        block_528:
        block_529:
            originalFrame.spA0 = 0;
            originalFrame.spA4 = 0;
            originalFrame.spA8 = (int) -Level22_7DF78Field(owner19, short *, 0x38);
            Level22_7DF78_func_80055D24(owner19, 4);
            Level22_7DF78_func_8004ED6C(owner19 + 0x20, &originalFrame.spA0, &originalFrame.spA0);
            descriptorIndexOrHeading17 = owner19 + 0xC;
            Level22_7DF78_func_8004F178(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) + 0xC, descriptorIndexOrHeading17);
            captured_a0_22 = Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) + 0xC;
            Level22_7DF78_func_8004F194(captured_a0_22, captured_a0_22, &originalFrame.spA0);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x46) = (unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x46);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x45) = (unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x45);
            Level22_7DF78Field(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220), unsigned char *, 0x44) = (unsigned char) Level22_7DF78Field(owner19, unsigned char *, 0x44);
            Level22_7DF78_func_8001A358(descriptorIndexOrHeading17, 0x2EE0);
            Level22_7DF78_func_8005629C(owner19);
            return;
        case 4:
            Level22_7DF78_func_80013B7C(1);
        block_531:
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = (unsigned char) (Level22_7DF78Field(owner19, unsigned char *, 0x49) + 1);
            return;
        case 5:
            if (!(Level22_7DF78_D_8006E048 & 1)) {
                goto block_608;
            }
            Level22_7DF78_func_80055B18(Level22_7DF78Field(privateStateOrAngle18, int*, 0x220));
            Level22_7DF78Field(privateStateOrAngle18, int*, 0x220) = 0;
            Level22_7DF78_func_8004F178(owner19 + 0xC, Level22_7DF78Field(actorFrameOrHeading16, int*, 0xC));
            Level22_7DF78_func_80037014(owner19);
            argumentOrAddress4=owner19;
            argumentOrField5=2;
            __asm__("":"=r"(argumentOrAddress4),"=r"(argumentOrField5):"0"(argumentOrAddress4),"1"(argumentOrField5):"$2");
            resultOrArithmetic2=254;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x52)=resultOrArithmetic2;
            Level22_7DF78_func_80055D24(argumentOrAddress4,argumentOrField5);
            captured_v0_35 = Level22_7DF78Field(actorFrameOrHeading16, int*, 0xC);
            captured_a3_13 = Level22_7DF78Field(captured_v0_35, int *, 0x10);
            Level22_7DF78Field(owner19, unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_13 - Level22_7DF78Field(captured_v0_35, int *, 0), Level22_7DF78Field(captured_v0_35, int *, 0x14) - Level22_7DF78Field(captured_v0_35, int *, 4), 0);
            Level22_7DF78Field(owner19, unsigned char *, 0x45) = 0U;
            Level22_7DF78Field(owner19, unsigned char *, 0x44) = 0U;
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 0) {
                goto block_535;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(owner19, unsigned char *, 0x3D) = 0U;
            Level22_7DF78Field(owner19, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
        block_535:
            Level22_7DF78_func_8004F178(&originalFrame.sp90, descriptorOrSavedValue20 + 0xC);
            originalFrame.sp90 += (int) (Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + (((Level22_7DF78Field(descriptorOrSavedValue20, unsigned char *, 0x46) + 0x80) & 0xFF) * 2)) * 0x177) >> 0xA;
            originalFrame.sp94 += (int) (Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + (((Level22_7DF78Field(descriptorOrSavedValue20, unsigned char *, 0x46) + 0x80) & 0xFF) * 2)) * 0x177) >> 0xA;
            Level22_7DF78_func_80013D44(&originalFrame.sp90, Level22_7DF78Field(descriptorOrSavedValue20, unsigned char *, 0x46), 0, 0);
            Level22_7DF78Field(descriptorOrSavedValue20, signed char *, 0x49) = 0;
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x238) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF4) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF8) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xFC) = 0;
            Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0x16U;
            return;
        }
    case 22:
        resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
        resultOrArithmetic2=resultOrArithmetic2*4+privateStateOrAngle18;
        fieldOrOffset3=Level22_7DF78Field(resultOrArithmetic2,int*,0xA0);
        argumentOrAddress4=Level22_7DF78Field(owner19,unsigned char*,0x49);
        resultOrArithmetic2=fieldOrOffset3*88;
        fieldOrOffset3=Level22_7DF78_D_8006C550;
        offsetOrFlag22=fieldOrOffset3+resultOrArithmetic2;
        if((unsigned)argumentOrAddress4>=7U) {
            goto block_608;
        }
        switch (argumentOrAddress4){
            default:goto block_608;
        case 0:
            if (Level22_7DF78_func_80037BBC(owner19, 0) == 0) {
                goto block_540;
            }
            Level22_7DF78_func_800512E4(owner19, 0, 0xE);
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 2U;
        block_540:
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 5) {
                goto block_543;
            }
            actorFrameOrHeading16 = overlayContextOrHeading21 + 0x64;
            if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4) != -1) {
                goto block_544;
            }
            argumentOrAddress4=actorFrameOrHeading16;
            fieldOrOffset3=(int)Level22_7DF78_unk_ovlheader_80074440;
            resultOrArithmetic2=1;
            Level22_7DF78Field(overlayContextOrHeading21,int*,0x8C)=resultOrArithmetic2;
            ((void(*)(int))fieldOrOffset3)(argumentOrAddress4);
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4) = (int)(short) Level22_7DF78_func_8002803C(0x15, 0xDD, Level22_7DF78_unk_ovlheader_80074448, Level22_7DF78_unk_ovlheader_80074450, Level22_7DF78_unk_ovlheader_8007444C, actorFrameOrHeading16, 0xEA60);
            goto block_544;
        block_543:
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0x8C) = 0;
        block_544:
            argumentOrAddress4=(int)&Level22_7DF78_D_80070328+0x48;
            fieldOrOffset3=Level22_7DF78Field(argumentOrAddress4,int*,0);
            resultOrArithmetic2=21;
            if(fieldOrOffset3==resultOrArithmetic2) {
                resultOrArithmetic2=60;
                goto block_582;
            }
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
            descriptorIndexOrHeading17=0;
            if(resultOrArithmetic2) goto block_549;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            __asm__ __volatile__("":"=r"(descriptorIndexOrHeading17):"0"(descriptorIndexOrHeading17));
            argumentOrAddress4-=0x48;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            argumentOrField5=privateStateOrAngle18+0xE8;
            argumentOrIndex6=0;
            Level22_7DF78CompleteValue(argumentOrIndex6);
            argumentOrField7=0;
            resultOrArithmetic2=Level22_7DF78_func_80036220(argumentOrAddress4,argumentOrField5,argumentOrIndex6,argumentOrField7);
            descriptorIndexOrHeading17=0;
            if(!resultOrArithmetic2) goto block_549;
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x238);
            if(resultOrArithmetic2<0x4650) {
                resultOrArithmetic2=30;
                goto block_582;
            }
            descriptorIndexOrHeading17=0;
        block_549:
            argumentOrAddress4=(int)&Level22_7DF78_D_80070328+8;
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,int*,0x238);
            fieldOrOffset3=Level22_7DF78Field(argumentOrAddress4,int*,0);
            resultOrArithmetic2=resultOrArithmetic2<fieldOrOffset3;
            descriptorOrSavedValue20=0;
            if(!resultOrArithmetic2) goto block_551;
            Level22_7DF78Field(privateStateOrAngle18,int*,0x238)=fieldOrOffset3;
        block_551:
            captured_v1_37 = Level22_7DF78Field(privateStateOrAngle18, short *, 0x208);
            if (captured_v1_37 == 0) {
                goto block_553;
            }
            if (Level22_7DF78Field(overlayContextOrHeading21, int *, 0xC) != 0) {
                goto block_577;
            }
        block_553:
            argumentOrAddress4=(int)&Level22_7DF78_D_80070328;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            argumentOrField5=captured_v1_37*24;
            argumentOrField5+=0xE8;
            Level22_7DF78CompleteValue(argumentOrField5);
            argumentOrField5=(int)((char*)privateStateOrAngle18+argumentOrField5);
            if (Level22_7DF78_func_80036220(argumentOrAddress4,argumentOrField5,0,0) == 0) {
                goto block_577;
            }
            if (Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF4) != 0) {
                goto block_558;
            }
            if (Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF8) != 0) {
                goto block_558;
            }
            if (Level22_7DF78Field(overlayContextOrHeading21, int *, 0xFC) != 0) {
                goto block_558;
            }
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 0) {
                goto block_577;
            }
        block_558:
            captured_v1_38 = Level22_7DF78Field(privateStateOrAngle18, short *, 0x208);
            if ((unsigned int) captured_v1_38 >= 6U) {
                goto block_577;
            }
            switch (captured_v1_38){
                default:goto block_577;
            case 0:
                if (Level22_7DF78Field(privateStateOrAngle18, int *, 0x238) < 0x4651) {
                    goto block_577;
                }
            block_561:
                descriptorIndexOrHeading17 = 1;
                goto block_577;
            case 1:
                working_v0_51 = Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF4);
            block_563:
                if (working_v0_51 >= 0) {
                    goto block_565;
                }
                working_v0_51 = -working_v0_51;
            block_565:
                resultOrArithmetic2 = working_v0_51 < 0xBE9;
                goto block_575;
            case 2:
                working_v0_51 = Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF8);
                goto block_563;
            case 3:
                working_v0_53 = Level22_7DF78Field(overlayContextOrHeading21, int *, 0xFC);
                if (working_v0_53 >= 0) {
                    goto block_569;
                }
                working_v0_53 = -working_v0_53;
            block_569:
                resultOrArithmetic2 = working_v0_53 < 0x401;
                goto block_575;
            case 4:
                working_v0_54 = Level22_7DF78Field(overlayContextOrHeading21, int *, 0xFC);
                if (working_v0_54 >= 0) {
                    goto block_572;
                }
                working_v0_54 = -working_v0_54;
            block_572:
                resultOrArithmetic2 = working_v0_54 < 0x2401;
                goto block_575;
            case 5:
                fieldOrOffset3=Level22_7DF78Field(overlayContextOrHeading21,int*,0xE4);
                actorFrameOrHeading16=Level22_7DF78Field(overlayContextOrHeading21,int*,0xE8);
                resultOrArithmetic2=fieldOrOffset3<actorFrameOrHeading16;
                if(!resultOrArithmetic2) {
                    resultOrArithmetic2=fieldOrOffset3<500;
                    goto block_575;
                }
                fieldOrOffset3=actorFrameOrHeading16;
                Level22_7DF78CompleteValue(fieldOrOffset3);
                resultOrArithmetic2=fieldOrOffset3<500;
            block_575:
                if (resultOrArithmetic2 == 0) {
                    goto block_561;
                }
                descriptorOrSavedValue20 = 1;
            block_577:
                if (descriptorIndexOrHeading17 == 0) {
                    goto block_579;
                }
                captured_v0_36 = (unsigned short) Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) + 1;
                Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) = captured_v0_36;
                Level22_7DF78Field(privateStateOrAngle18, unsigned char *, 2) = (unsigned char) (((int) (captured_v0_36 << 0x10) >> 0xF) + 3);
                Level22_7DF78Field(owner19, unsigned char *, 0x49) = 4U;
                return;
            block_579:
                resultOrArithmetic2=30;
                if(descriptorOrSavedValue20) {
                    goto block_582;
                }
                Level22_7DF78CompleteValue(descriptorOrSavedValue20);
                Level22_7DF78CompleteValue(descriptorIndexOrHeading17);
                actorFrameOrHeading16=(int)&Level22_7DF78_D_80070328;
                argumentOrAddress4=actorFrameOrHeading16;
                __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4):"$6");
                argumentOrIndex6=0;
                Level22_7DF78CompleteValue(argumentOrIndex6);
                resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
                argumentOrField7=0;
                argumentOrField5=resultOrArithmetic2*48;
                argumentOrField5+=0x25C;
                Level22_7DF78CompleteValue(argumentOrField5);
                argumentOrField5=(int)((char*)privateStateOrAngle18+argumentOrField5);
                resultOrArithmetic2=Level22_7DF78_func_80036220(argumentOrAddress4,argumentOrField5,argumentOrIndex6,argumentOrField7);
                if(resultOrArithmetic2) {
                    resultOrArithmetic2=30;
                    goto block_582;
                }
                Level22_7DF78CompleteValue(resultOrArithmetic2);
                argumentOrAddress4=actorFrameOrHeading16;
                __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4):"$6");
                argumentOrIndex6=0;
                Level22_7DF78CompleteValue(argumentOrIndex6);
                resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
                argumentOrField7=0;
                argumentOrField5=resultOrArithmetic2*48;
                argumentOrField5+=0x274;
                Level22_7DF78CompleteValue(argumentOrField5);
                argumentOrField5=(int)((char*)privateStateOrAngle18+argumentOrField5);
                resultOrArithmetic2=Level22_7DF78_func_80036220(argumentOrAddress4,argumentOrField5,argumentOrIndex6,argumentOrField7);
                if(!resultOrArithmetic2) {
                    goto block_583;
                }
                resultOrArithmetic2=30;
            block_582:
                Level22_7DF78Field(privateStateOrAngle18,int*,0x98)=resultOrArithmetic2;
                Level22_7DF78Field(owner19,unsigned char*,0x49)=1;
                return;
            block_583:
                /* Original false-edge30 delay value is retained at this target before fresh call arguments; no unknown return or incoming GP is substituted. */
                resultOrArithmetic2=30;
                __asm__ __volatile__(""::"r"(resultOrArithmetic2));
                argumentOrAddress4=actorFrameOrHeading16;
                __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4):"$6");
                argumentOrIndex6=0;
                Level22_7DF78CompleteValue(argumentOrIndex6);
                resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
                argumentOrField7=0;
                argumentOrField5=resultOrArithmetic2*24;
                argumentOrField5+=0x178;
                Level22_7DF78CompleteValue(argumentOrField5);
                argumentOrField5=(int)((char*)privateStateOrAngle18+argumentOrField5);
                resultOrArithmetic2=Level22_7DF78_func_80036220(argumentOrAddress4,argumentOrField5,argumentOrIndex6,argumentOrField7);
                if(resultOrArithmetic2) {
                    goto block_608;
                }
                Level22_7DF78CompleteValue(resultOrArithmetic2);
                Level22_7DF78Field(offsetOrFlag22, signed char *, 0x49) = 1;
                Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
                Level22_7DF78Field(privateStateOrAngle18, signed char *, 5) = 1;
                Level22_7DF78Field(privateStateOrAngle18, unsigned char *, 2) = 2U;
                Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0U;
                Level22_7DF78_func_80034F40(owner19, 0);
                return;
            }
        case 4:
        case 5:
            argumentOrAddress4=4;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
            fieldOrOffset3=Level22_7DF78Field(owner19,unsigned char*,0x49);
            resultOrArithmetic2*=4;
            resultOrArithmetic2+=privateStateOrAngle18;
            actorFrameOrHeading16=Level22_7DF78Field(resultOrArithmetic2,int*,0xD0);
            if(fieldOrOffset3!=argumentOrAddress4) {
                goto block_593;
            }
            resultOrArithmetic2=Level22_7DF78Field(owner19,int*,12);
            fieldOrOffset3=Level22_7DF78Field(owner19,int*,16);
            argumentOrAddress4=Level22_7DF78Field(owner19,int*,20);
            originalFrame.sp90=resultOrArithmetic2;
            originalFrame.sp94=fieldOrOffset3;
            originalFrame.sp98=argumentOrAddress4;
            resultOrArithmetic2=Level22_7DF78Field(owner19,signed char*,0x44);
            fieldOrOffset3=Level22_7DF78Field(owner19,signed char*,0x45);
            argumentOrAddress4=Level22_7DF78Field(owner19,signed char*,0x46);
            Level22_7DF78Field(&originalFrame.spA0,signed char*,0)=resultOrArithmetic2;
            Level22_7DF78Field(&originalFrame.spA0,signed char*,1)=fieldOrOffset3;
            Level22_7DF78Field(&originalFrame.spA0,signed char*,2)=argumentOrAddress4;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78CompleteValue(fieldOrOffset3);
            Level22_7DF78CompleteValue(argumentOrAddress4);
            descriptorIndexOrHeading17 = owner19 + 0xC;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) != 6) {
                goto block_589;
            }
            resultOrArithmetic2=Level22_7DF78_D_8006C7B4;
            fieldOrOffset3=Level22_7DF78Field(owner19,int*,0);
            resultOrArithmetic2|=8;
            Level22_7DF78_D_8006C7B4=resultOrArithmetic2;
            resultOrArithmetic2=2;
            Level22_7DF78Field(fieldOrOffset3,signed char*,5)=resultOrArithmetic2;
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
            actorFrameOrHeading16=(int)&originalFrame.spB0;
            resultOrArithmetic2*=2;
            fieldOrOffset3=Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,resultOrArithmetic2);
            argumentOrAddress4=actorFrameOrHeading16;
            resultOrArithmetic2=fieldOrOffset3*39;
            originalFrame.spB0=resultOrArithmetic2>>6;
            __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4),"m"(originalFrame.spB0):"$5");
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
            argumentOrField5=actorFrameOrHeading16;
            resultOrArithmetic2*=2;
            fieldOrOffset3=Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,resultOrArithmetic2);
            __asm__("":"=r"(fieldOrOffset3):"0"(fieldOrOffset3):"$6");
            resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_80070328,int*,0x44);
            argumentOrIndex6=descriptorIndexOrHeading17;
            Level22_7DF78Field(&originalFrame.spB8,volatile int*,0)=0;
            originalFrame.spB8=resultOrArithmetic2;
            resultOrArithmetic2=fieldOrOffset3*39;
            originalFrame.spB4=resultOrArithmetic2>>6;
            Level22_7DF78_func_8004F194(argumentOrAddress4,argumentOrField5,argumentOrIndex6);
            Level22_7DF78_func_80013D44(&originalFrame.spB0, (Level22_7DF78Field(owner19, unsigned char *, 0x46) + 0x80) & 0xFF, 0, 0);
            if (Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x280) >= 0) {
                goto block_592;
            }
            Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x280) = 0;
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 5U;
            return;
        block_589:
            Level22_7DF78_func_8004F178(descriptorIndexOrHeading17, Level22_7DF78Field(actorFrameOrHeading16, int*, 0xC));
            Level22_7DF78Field(owner19, int *, 0x14) = (int) (Level22_7DF78Field(owner19, int *, 0x14) + Level22_7DF78Field(owner19, short *, 0x38));
            captured_v0_37 = Level22_7DF78Field(actorFrameOrHeading16, int*, 0xC);
            captured_a3_14 = Level22_7DF78Field(captured_v0_37, int *, 0x10);
            Level22_7DF78Field(owner19, unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_14 - Level22_7DF78Field(captured_v0_37, int *, 0), Level22_7DF78Field(captured_v0_37, int *, 0x14) - Level22_7DF78Field(captured_v0_37, int *, 4), 0);
            Level22_7DF78Field(Level22_7DF78Field(owner19, int*, 0), signed char *, 5) = 2;
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
            actorFrameOrHeading16=(int)&originalFrame.spC0;
            resultOrArithmetic2*=2;
            fieldOrOffset3=Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,resultOrArithmetic2);
            argumentOrAddress4=actorFrameOrHeading16;
            resultOrArithmetic2=fieldOrOffset3*13;
            originalFrame.spC0=resultOrArithmetic2>>5;
            __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4),"m"(originalFrame.spC0):"$5");
            resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
            argumentOrField5=actorFrameOrHeading16;
            resultOrArithmetic2*=2;
            fieldOrOffset3=Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,resultOrArithmetic2);
            __asm__("":"=r"(fieldOrOffset3):"0"(fieldOrOffset3):"$6");
            resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_80070328,int*,0x44);
            argumentOrIndex6=descriptorIndexOrHeading17;
            Level22_7DF78Field(&originalFrame.spC8,volatile int*,0)=0;
            originalFrame.spC8=resultOrArithmetic2;
            resultOrArithmetic2=fieldOrOffset3*13;
            originalFrame.spC4=resultOrArithmetic2>>5;
            Level22_7DF78_func_8004F194(argumentOrAddress4,argumentOrField5,argumentOrIndex6);
            Level22_7DF78_func_80013D44(&originalFrame.spC0, (Level22_7DF78Field(owner19, unsigned char *, 0x46) + 0x80) & 0xFF, 0, 0);
            if (Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x280) >= 0) {
                goto block_591;
            }
            Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x280) = 0;
        block_591:
            resultOrArithmetic2=originalFrame.sp90;
            fieldOrOffset3=originalFrame.sp94;
            argumentOrAddress4=originalFrame.sp98;
            Level22_7DF78Field(owner19,int*,12)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,int*,16)=fieldOrOffset3;
            Level22_7DF78Field(owner19,int*,20)=argumentOrAddress4;
            resultOrArithmetic2=Level22_7DF78Field(&originalFrame.spA0,signed char*,0);
            fieldOrOffset3=Level22_7DF78Field(&originalFrame.spA0,signed char*,1);
            argumentOrAddress4=Level22_7DF78Field(&originalFrame.spA0,signed char*,2);
            Level22_7DF78Field(owner19,unsigned char*,0x44)=resultOrArithmetic2;
            Level22_7DF78Field(owner19,unsigned char*,0x45)=fieldOrOffset3;
            Level22_7DF78Field(owner19,unsigned char*,0x46)=argumentOrAddress4;
        block_592:
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 5U;
            return;
        block_593:
            if (!(Level22_7DF78_D_8006E048 & 1)) {
                goto block_608;
            }
            Level22_7DF78_func_80028154(Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4));
            resultOrArithmetic2=Level22_7DF78Field(privateStateOrAngle18,short*,0x208);
            fieldOrOffset3=-1;
            Level22_7DF78Field(privateStateOrAngle18,int*,0x4A4)=fieldOrOffset3;
            resultOrArithmetic2*=4;
            resultOrArithmetic2=(int)((char*)privateStateOrAngle18+resultOrArithmetic2);
            fieldOrOffset3=Level22_7DF78Field(resultOrArithmetic2,int*,0x9C);
            resultOrArithmetic2=fieldOrOffset3*88;
            fieldOrOffset3=Level22_7DF78_D_8006C550;
            resultOrArithmetic2+=fieldOrOffset3;
            fieldOrOffset3=1;
            Level22_7DF78Field(resultOrArithmetic2,signed char*,0x49)=fieldOrOffset3;
            if (Level22_7DF78Field(privateStateOrAngle18, short *, 0x208) >= 6) {
                goto block_596;
            }
            Level22_7DF78_func_8004F178(owner19 + 0xC, Level22_7DF78Field(actorFrameOrHeading16, int*, 0xC));
            Level22_7DF78_func_80037014(owner19);
            argumentOrAddress4=owner19;
            argumentOrField5=2;
            __asm__("":"=r"(argumentOrAddress4),"=r"(argumentOrField5):"0"(argumentOrAddress4),"1"(argumentOrField5):"$2");
            resultOrArithmetic2=254;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(owner19,signed char*,0x52)=resultOrArithmetic2;
            Level22_7DF78_func_80055D24(argumentOrAddress4,argumentOrField5);
            captured_v0_38 = Level22_7DF78Field(actorFrameOrHeading16, int*, 0xC);
            captured_a3_15 = Level22_7DF78Field(captured_v0_38, int *, 0x10);
            Level22_7DF78Field(owner19, unsigned char *, 0x46) = Level22_7DF78_func_8004E880(captured_a3_15 - Level22_7DF78Field(captured_v0_38, int *, 0), Level22_7DF78Field(captured_v0_38, int *, 0x14) - Level22_7DF78Field(captured_v0_38, int *, 4), 0);
            Level22_7DF78Field(owner19, unsigned char *, 0x45) = 0U;
            Level22_7DF78Field(owner19, unsigned char *, 0x44) = 0U;
        block_596:
            Level22_7DF78Field(descriptorOrSavedValue20, signed char *, 0x48) = 0;
            goto block_607;
        case 1:
            if (Level22_7DF78_func_800359A4(privateStateOrAngle18 + 0x98, 4) == 0) {
                goto block_608;
            }
            Level22_7DF78_func_8004F178(&originalFrame.sp90, offsetOrFlag22 + 0xC);
            originalFrame.sp90 += (int) (Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,0 + (((Level22_7DF78Field(offsetOrFlag22, unsigned char *, 0x46) + 0x80) & 0xFF) * 2)) * 0x177) >> 0xA;
            originalFrame.sp94 += (int) (Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,0 + (((Level22_7DF78Field(offsetOrFlag22, unsigned char *, 0x46) + 0x80) & 0xFF) * 2)) * 0x177) >> 0xA;
            Level22_7DF78_func_80013D44(&originalFrame.sp90, Level22_7DF78Field(offsetOrFlag22, unsigned char *, 0x46), 0, 0);
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 6U;
            return;
        case 6:
            if (!(Level22_7DF78_D_8006E048 & 1)) {
                goto block_608;
            }
            Level22_7DF78Field(offsetOrFlag22, signed char *, 0x49) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF4) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF8) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xFC) = 0;
            Level22_7DF78Field(descriptorOrSavedValue20, signed char *, 0x48) = 0;
            Level22_7DF78_func_80028154(Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4));
            Level22_7DF78Field(privateStateOrAngle18, int *, 0x4A4) = -1;
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
            return;
        case 2:
            if (Level22_7DF78_D_8006E344 == 1) {
                goto block_608;
            }
            Level22_7DF78Field(owner19, unsigned char *, 0x49) = 0U;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF4) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xF8) = 0;
            Level22_7DF78Field(overlayContextOrHeading21, int *, 0xFC) = 0;
            if (Level22_7DF78Field(owner19, unsigned char *, 0x3D) == 0) {
                goto block_608;
            }
            argumentOrAddress4=owner19;
            Level22_7DF78CompleteValue(argumentOrAddress4);
            Level22_7DF78_D_8006C770 = 0;
            resultOrArithmetic2=114;
            Level22_7DF78CompleteValue(resultOrArithmetic2);
            Level22_7DF78Field(argumentOrAddress4,signed char*,0x40)=resultOrArithmetic2;
            Level22_7DF78Field(argumentOrAddress4, unsigned char *, 0x3D) = 0U;
            Level22_7DF78Field(argumentOrAddress4, signed char *, 0x3F) = 0;
            Level22_7DF78_func_80035734(argumentOrAddress4);
            return;
        }
    case 20:
        if (Level22_7DF78_func_800359A4(privateStateOrAngle18 + 0x98, 4) == 0) {
            goto block_608;
        }
        Level22_7DF78Field(Level22_7DF78Field(owner19, int*, 0), signed char *, 5) = 2;
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
        actorFrameOrHeading16=(int)&originalFrame.sp90;
        resultOrArithmetic2*=2;
        fieldOrOffset3=Level22_7DF78Field((int)&Level22_7DF78_D_80065920,short*,resultOrArithmetic2);
        argumentOrAddress4=actorFrameOrHeading16;
        resultOrArithmetic2=fieldOrOffset3*39;
        originalFrame.sp90=resultOrArithmetic2>>6;
        __asm__("":"=r"(argumentOrAddress4):"0"(argumentOrAddress4),"m"(originalFrame.sp90):"$5");
        resultOrArithmetic2=Level22_7DF78Field(owner19,unsigned char*,0x46);
        argumentOrField5=actorFrameOrHeading16;
        resultOrArithmetic2*=2;
        fieldOrOffset3=Level22_7DF78Field((int)&Level22_7DF78_D_800658A0,short*,resultOrArithmetic2);
        __asm__("":"=r"(fieldOrOffset3):"0"(fieldOrOffset3):"$6");
        resultOrArithmetic2=Level22_7DF78Field((int)&Level22_7DF78_D_80070328,int*,0x44);
        argumentOrIndex6=owner19+12;
        Level22_7DF78Field(&originalFrame.sp98,volatile int*,0)=0;
        originalFrame.sp98=resultOrArithmetic2;
        resultOrArithmetic2=fieldOrOffset3*39;
        originalFrame.sp94=resultOrArithmetic2>>6;
        Level22_7DF78_func_8004F194(argumentOrAddress4,argumentOrField5,argumentOrIndex6);
        Level22_7DF78_func_80013D44(&originalFrame.sp90, (Level22_7DF78Field(owner19, unsigned char *, 0x46) + 0x80) & 0xFF, 0, 0);
        if (Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x280) >= 0) {
            goto block_607;
        }
        Level22_7DF78Field((int)&Level22_7DF78_D_80070328, int *, 0x280) = 0;
    block_607:
        Level22_7DF78Field(owner19, unsigned char *, 0x48) = 0U;
    block_608:
        return;
    }
}
#undef Level22_7DF78Field
#undef Level22_7DF78CompleteValue
#undef Level22_7DF78WholeProduct


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80081674.
 * Original instructions: sibling4695.func_level_22_80081674.json.
 * Native identity pending; units, helper contracts and cadence unresolved. */
#define A22Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int A22H38F14() __asm__("func_80038F14");
int A22H36A68() __asm__("func_80036A68");
int A22H55D24() __asm__("func_80055D24");
int A22H359A4() __asm__("func_800359A4");
int A22H4F334() __asm__("func_8004F334");
int A22H34F40() __asm__("func_80034F40");
int A22H3573C() __asm__("func_8003573C");
int A22H35A80() __asm__("func_80035A80");
int A22H4E880() __asm__("func_8004E880");
int A22H4F264() __asm__("func_8004F264");
int A22H37168() __asm__("func_80037168");
int A22H55E84() __asm__("func_80055E84");
int A22H35194() __asm__("func_80035194");
int A22H3BA00() __asm__("func_8003BA00");
int A22H369B8() __asm__("func_800369B8");
int A22H55B18() __asm__("func_80055B18");
int A22Rand() __asm__("rand");
extern unsigned char A22Player[] __asm__("D_80070328");
extern unsigned char A22Coordinates[] __asm__("D_8006E020");
extern short A22Heading __asm__("D_8006E040");
extern unsigned char* A22Pool __asm__("D_8006C550");
extern int A22Contact __asm__("D_8006C770");
void func_level_22_80081674(void* input){
 register unsigned char* owner __asm__("$17")=input;
 register unsigned char* tag __asm__("$18");
 int temporary16;
 register int distance19 __asm__("$19");
 register int height20 __asm__("$20");
 register unsigned char* player21 __asm__("$21");
 register void* call4 __asm__("$4");
 register int arg5 __asm__("$5");
 register int arg6 __asm__("$6");
 register int arg7 __asm__("$7");
 register int value __asm__("$2");
 register int other __asm__("$3");
 register int playerZ __asm__("$8");
 int state;
 __asm__("" : "=r"(owner):"0"(owner));other=0x10000;value=A22Field(owner,int*,24);tag=A22Field(owner,unsigned char**,0);value&=other;
 if(value && owner[72]!=8){
  A22H38F14(input,tag,1,8);owner[72]=8;A22H36A68(owner,0,0,0);
 }
 call4=owner;arg5=4;A22Field(owner,int*,24)=0;A22H55D24(call4,arg5);
 A22H359A4(tag+34,2);
 other=A22Field(tag,int*,40);
 if(other!=1)goto dispatch_reload;
 other=owner[72];if(other==8)goto dispatch_ready;if(other==5)goto dispatch_switch;
 other=A22Field(tag,int*,44);call4=(void*)owner[73];value=other*11;__asm__("" : "=r"(value):"0"(value));other=(int)A22Pool;value<<=3;other+=value;
 if(!call4)goto dispatch_reload;
 value=A22H4F334(owner+12,(unsigned char*)other+12);call4=owner;
 if(value>=7000)goto dispatch_reload;
 arg5=11;A22Field(tag,volatile short*,64)=700;tag[68]=170;tag[70]=75;tag[69]=5;
 owner[72]=11;A22H34F40(call4,arg5);
 dispatch_reload:other=owner[72];
 dispatch_ready:;
 dispatch_switch:
 state=other;switch(state){
 case 0:
  value=A22H4F334(owner+12,A22Player);other=A22Field(tag,int*,36);temporary16=value;
  if(!other){call4=owner;arg5=6;__asm__("" : "=r"(arg5):"0"(arg5));__asm__("" : "=r"(arg6):"0"(0));A22H3573C(call4,arg5,arg6,1);if(!A22Field(tag,int*,36))goto near0;}
  value=A22Field(tag,int*,24)+2048;if(temporary16>=value)goto near0;
  owner[72]=2;A22H34F40(owner,2);break;
 near0:
  value=temporary16<A22Field(tag,int*,24);if(!value)goto done;
  owner[72]=3;A22H34F40(owner,3);break;
 case 2:
  value=A22H35A80(owner,A22Field(tag,int*,36),256,150,0,8,64,4);
  call4=owner;if(!(value&2))goto done;
  arg5=0;A22Field(tag,int*,36)=0;((unsigned char*)call4)[72]=0;A22H34F40(call4,arg5);break;
 case 3:
  A22H3573C(owner,6,0,1);if(!A22Contact)goto done;value=4;goto enter4_ready;
 case 4:
  call4=owner+12;arg5=(int)(A22Player+8);__asm__("" : "=r"(arg5):"0"(arg5));other=*(int*)arg5;value=A22Field(owner,int*,20);
  arg5-=8;temporary16=other-value;value=A22H4F334(call4,(void*)arg5);
  call4=owner;arg5=6;arg6=0;arg7=1;
  __asm__("" : "=r"(call4),"=r"(arg5),"=r"(arg6),"=r"(arg7):"0"(call4),"1"(arg5),"2"(arg6),"3"(arg7));
  distance19=value;A22H3573C(call4,arg5,arg6,arg7);
  if(distance19>=A22Field(tag,int*,28))goto retreat4;
  if(A22Field(tag,short*,34))goto retreat4;
  value=temporary16+767;value=(unsigned)value<3327;if(!value)goto retreat4;
  if(A22Field(A22Player,int*,576))goto retreat4;
  if((unsigned)(A22Field(A22Player,int*,80)-7)<2)goto retreat4;
  value=A22H4E880(A22Field(owner,int*,12)-A22Field(A22Coordinates,int*,0),A22Field(owner,int*,16)-A22Field(A22Coordinates,int*,4),0);
  value=A22H4F264(A22Heading>>4,value);if(value>=28)goto retreat4;
  owner[72]=5;A22H34F40(owner,5);break;
 retreat4:
  if(distance19<=A22Field(tag,int*,24)+512)goto done;
  owner[72]=6;A22H34F40(owner,6);break;
 case 11:
  A22H37168(owner,tag+52,16949);break;
 case 6:case 7:
  A22H3573C(owner,6,0,1);if(!A22Contact)goto done;owner[72]=0;goto reset_ready;
 case 5:
  value=A22H55E84(owner);call4=owner+12;player21=A22Player;arg5=(int)player21;__asm__("" : "=r"(arg5):"0"(arg5));
  temporary16=value;value=A22H4F334(call4,(void*)arg5);
  call4=owner;arg5=6;arg6=0;arg7=1;__asm__("" : "=r"(call4),"=r"(arg5),"=r"(arg6),"=r"(arg7):"0"(call4),"1"(arg5),"2"(arg6),"3"(arg7));
  playerZ=A22Field(A22Player,int*,8);__asm__("" : "=r"(playerZ):"0"(playerZ));other=A22Field(owner,int*,20);__asm__("" : "=r"(other):"0"(other));distance19=value;
  height20=playerZ-other;A22H3573C(call4,arg5,arg6,arg7);__asm__("" : "=r"(temporary16):"0"(temporary16));
  temporary16=(unsigned)(temporary16-9)<3;
  value=distance19<3584;if(!temporary16 || !value)goto contact5;
  other=A22Field(A22Player,int*,68);
  value=other+1536;if(height20>=value)goto contact5;value=-other;value=value<height20;if(!value)goto contact5;
  if(A22Field(A22Player,int*,576))goto contact5;
  value=A22H4E880(A22Field(player21,int*,0)-A22Field(owner,int*,12),A22Field(A22Player,int*,4)-A22Field(owner,int*,16),0);
  value=A22H4F264(owner[70],value);if(value>=32)goto contact5;
  A22Field(A22Player,int*,36)|=0x16;
  if(A22Field(tag,int*,40)!=1)owner[73]=1;
 contact5:
  if(!A22Contact)goto done;
  temporary16=A22H4F334(owner+12,A22Player)-5120;other=A22Field(tag,unsigned short*,32);
  value=temporary16<21;A22Field(tag,unsigned short*,34)=other;if(value)goto reset5;
  other=temporary16/20;temporary16=other;if(temporary16>=121)temporary16=120;
  other=A22Rand()%temporary16;value=A22Field(tag,unsigned short*,34);A22Field(tag,unsigned short*,34)=value+other;
 reset5:
  other=A22Field(tag,int*,40);if(other==1)goto distance5;
  value=owner[73];call4=owner;if(!value)goto distance5;
  arg5=7;__asm__("" : "=r"(arg5):"0"(arg5));value=7;((unsigned char*)call4)[73]=0;((unsigned char*)call4)[72]=value;A22H34F40(call4,arg5);break;
 distance5:
  value=A22Field(tag,int*,24)+256;if(temporary16>=value)goto reset0;
  value=4;
 enter4_ready:
  owner[72]=value;A22H34F40(owner,4);break;
 reset0:
  owner[72]=0;
 reset_ready:
  A22H34F40(owner,0);break;
 case 8:
  value=A22H35194(owner,tag);call4=owner;if(value!=256)goto done;
  A22H55D24(call4,4);A22H3BA00(owner);A22H369B8(owner,36);A22H55B18(owner);break;
 }
 done:;
}
#undef A22Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80081CF0.
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
/* Original assembly SHA256 7f46736c9f99d70227644a92d1b4ce5e5d09629d63b5fbf79ccc45f31aa9d7c6 */
#define Level22_81CF0Keep(v) __asm__("":"=r"(v):"0"(v))
#define Level22_81CF0MultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level22_81CF0CaptureHigh(dst) do{int wholeCapturedHigh;__asm__("":"=h"(wholeCapturedHigh):"x"(completeSignedProduct));(dst)=wholeCapturedHigh;Level22_81CF0Keep(dst);}while(0)
#define Level22_81CF0CaptureLow(dst) do{int wholeCapturedLow;__asm__("":"=l"(wholeCapturedLow):"x"(completeSignedProduct));(dst)=wholeCapturedLow;Level22_81CF0Keep(dst);}while(0)
#define Level22_81CF0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level22_81CF0Call18368View1(void*,void*) __asm__("func_80018368");
int Level22_81CF0Call19194View1(void*,int) __asm__("func_80019194");
void* Level22_81CF0Call1BA30View1(void*,int,int,int,int,void*) __asm__("func_8001BA30");
int Level22_81CF0Call1C288View1(void*,int,int) __asm__("func_8001C288");
int Level22_81CF0Call359A4View1(void*,int) __asm__("func_800359A4");
int Level22_81CF0Call35D38View1(void*) __asm__("func_80035D38");
int Level22_81CF0Call3636CView1(int,int) __asm__("func_8003636C");
int Level22_81CF0Call363DCView1(int,int) __asm__("func_800363DC");
int Level22_81CF0Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
void Level22_81CF0Call3C140View1(int,int) __asm__("func_8003C140");
void Level22_81CF0Call49484View1(void*) __asm__("func_80049484");
int Level22_81CF0Call4E880View1(int,int,int) __asm__("func_8004E880");
int Level22_81CF0Call4E9E4View1(int) __asm__("func_8004E9E4");
int Level22_81CF0Call4EA2CView1(int) __asm__("func_8004EA2C");
int Level22_81CF0Call4EDE8View1(void*,int) __asm__("func_8004EDE8");
int Level22_81CF0Call4EF74View1(void*,void*,void*) __asm__("func_8004EF74");
void Level22_81CF0Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level22_81CF0Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
void Level22_81CF0Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
int Level22_81CF0Call4F264View1(int,int) __asm__("func_8004F264");
int Level22_81CF0Call4F334View1(void*,void*) __asm__("func_8004F334");
void Level22_81CF0Call55B18View1(void*) __asm__("func_80055B18");
void Level22_81CF0Call5629CView1(void*) __asm__("func_8005629C");
int Level22_81CF0DatarandView1(void) __asm__("rand");
extern unsigned char Level22_81CF0Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level22_81CF0Data65920View1[] __asm__("D_80065920");
extern int Level22_81CF0Data6C574View1 __asm__("D_8006C574");
extern int Level22_81CF0Data6C578View1 __asm__("D_8006C578");
extern int Level22_81CF0Data6C640View1 __asm__("D_8006C640");
extern unsigned short Level22_81CF0Data6E03EView1 __asm__("D_8006E03E");
extern unsigned short Level22_81CF0Data6E040View1 __asm__("D_8006E040");
extern int Level22_81CF0Data6E044View1 __asm__("D_8006E044");
extern int Level22_81CF0Data6E788View1 __asm__("D_8006E788");
extern int Level22_81CF0Data70328View1 __asm__("D_80070328");
extern int Level22_81CF0Data71918View1 __asm__("D_80071918");
extern int Level22_81CF0Data7191CView1 __asm__("D_8007191C");
extern int Level22_81CF0Data71920View1 __asm__("D_80071920");
extern void*(*Level22_81CF0DataSpawnMobyView1)(int,void*) __asm__("SpawnMoby");
extern void*(*Level22_81CF0DataSpawnParticleView1)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_22_80081CF0(unsigned char* ownerParameter) {
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
    Level22_81CF0Keep(owner21);
    resultOrField2=4;
    fieldOrIntermediate3=Level22_81CF0Field(owner21,unsigned char*,0x48);
    privateOrCreatedPrivate18=Level22_81CF0Field(owner21,int*,0);
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
    positionCandidateOrScalar16=(int)&Level22_81CF0Data70328View1;
    fieldOrIntermediate3=Level22_81CF0Field(owner21,int*,12);
    argumentOrField4=Level22_81CF0Field(positionCandidateOrScalar16,int*,0);
    resultOrField2=Level22_81CF0Field(owner21,int*,16);
    argumentOrField5=Level22_81CF0Field(&Level22_81CF0Data70328View1,int*,4);
    argumentOrField4=fieldOrIntermediate3-argumentOrField4;
    argumentOrField5=resultOrField2-argumentOrField5;
    resultOrField2=Level22_81CF0Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=Level22_81CF0Field(&Level22_81CF0Data70328View1,unsigned char*,14);
    argumentOrField5=resultOrField2;
    resultOrField2=Level22_81CF0Call4F264View1(argumentOrField4,argumentOrField5);
    argumentOrField4=owner21+12;
    if(resultOrField2>=16)goto originalIdleDone;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level22_81CF0Call4F334View1(argumentOrField4,argumentOrField5);
    resultOrField2-=600;
    resultOrField2=resultOrField2<250;
    fieldOrIntermediate3=Level22_81CF0Field(owner21,int*,20);
    argumentOrField4=Level22_81CF0Field(&Level22_81CF0Data70328View1,int*,8);
    fieldOrIntermediate3+=356;
    Level22_81CF0Keep(fieldOrIntermediate3);
    argumentOrField4-=fieldOrIntermediate3;
    if(!resultOrField2)goto originalIdleDone;
    resultOrField2=argumentOrField4<256;
    if(!resultOrField2)goto originalIdleDone;
    resultOrField2=Level22_81CF0Field(&Level22_81CF0Data70328View1,int*,0x170);
    if(resultOrField2)goto originalIdleDone;
    resultOrField2=0x10000001;
    Level22_81CF0Field(&Level22_81CF0Data70328View1,int*,0x20C)=resultOrField2;
    resultOrField2=32;
    Level22_81CF0Field(&Level22_81CF0Data70328View1,int*,0x218)=owner21;
    Level22_81CF0Field(owner21,unsigned char*,0x4F)=resultOrField2;
    originalIdleDone:Level22_81CF0Field(privateOrCreatedPrivate18,int*,12)=0;
    return;
    originalState1:;
    Level22_81CF0Field(owner21, int *, 8) = 0;
    Level22_81CF0Field(owner21, signed char *, 0x4C) = 0;
    Level22_81CF0Field(owner21, signed char *, 0x4D) = 0;
    resultOrField2=255;
    Level22_81CF0Keep(resultOrField2);
    Level22_81CF0Field(owner21, unsigned char *, 0x4A) = resultOrField2;
    return;
    originalState2:;
    Level22_81CF0Field(owner21, signed char *, 0x4F) = 0x20;
    Level22_81CF0Field(owner21, signed char *, 0x4C) = 0x50;
    Level22_81CF0Field(owner21, unsigned char *, 0x45) = 0U;
    Level22_81CF0Field(owner21, signed char *, 0x4D) = 1;
    initialOwnerPositionAddress = owner21 + 0xC;
    if (Level22_81CF0Data6E044View1 == 7) {
        argumentOrField4=initialOwnerPositionAddress;
        __asm__("":"=r"(owner21):"0"(owner21),"r"(argumentOrField4));
        Level22_81CF0Call49484View1(owner21 + 0xC);
    }
    else {
        Level22_81CF0Field(owner21, int *, 0xC) = (int) ((int) (Level22_81CF0Field(&Level22_81CF0Data65920View1,short*,(Level22_81CF0Field(&Level22_81CF0Data70328View1, unsigned char *, 0xE) * 2)) * 0x4B) >> 9);
        argumentOrField7 = Level22_81CF0Field(&Level22_81CF0Data658A0View1,short*,(Level22_81CF0Field(&Level22_81CF0Data70328View1, unsigned char *, 0xE) * 2));
        Level22_81CF0Field(owner21, int *, 0x14) = 0xC8;
        Level22_81CF0Field(owner21, int *, 0x10) = (int) ((int) (argumentOrField7 * 0x4B) >> 9);
        Level22_81CF0Call4F194View1(initialOwnerPositionAddress, initialOwnerPositionAddress, (int)&Level22_81CF0Data70328View1);
    }
    argumentOrField4=(int)&originalFrame.sp18;
originalFirstVector:
    angleAddressOrDistanceOrVector17=(int)&Level22_81CF0Data70328View1+14;
    argumentOrField7=Level22_81CF0Field(angleAddressOrDistanceOrVector17,unsigned char*,0);
    argumentOrField5=argumentOrField4;
    argumentOrField7*=2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data65920View1,short*,argumentOrField7);
    argumentOrField6=angleAddressOrDistanceOrVector17-14;
    resultOrField2=fieldOrIntermediate3*25;
    resultOrField2>>=9;
    originalFrame.sp18=resultOrField2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data658A0View1,short*,argumentOrField7);
    resultOrField2=200;
    originalFrame.sp20=resultOrField2;
    resultOrField2=fieldOrIntermediate3*25;
    resultOrField2>>=9;
    originalFrame.sp1C=resultOrField2;
    Level22_81CF0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=(int)&originalFrame.sp18;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level22_81CF0Call18368View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    if(resultOrField2){
        argumentOrField5=(int)&originalFrame.sp18;
        Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    }
    resultOrField2=Level22_81CF0Field(angleAddressOrDistanceOrVector17,unsigned char*,0);
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data70328View1,unsigned char*,0x12);
    resultOrField2+=fieldOrIntermediate3;
    Level22_81CF0Field(owner21,unsigned char*,0x46)=resultOrField2;
    fieldOrIntermediate3=Level22_81CF0Data6E044View1;
    resultOrField2=7;
    if(fieldOrIntermediate3==resultOrField2){
        resultOrField2=Level22_81CF0Data6E03EView1;
        fieldOrIntermediate3=14;
        resultOrField2=(int)(resultOrField2<<16)>>20;
        fieldOrIntermediate3-=resultOrField2;
        Level22_81CF0Field(owner21,unsigned char*,0x45)=fieldOrIntermediate3;
        resultOrField2=Level22_81CF0Data6E040View1;
        resultOrField2=(unsigned int)resultOrField2>>4;
        Level22_81CF0Field(owner21,unsigned char*,0x46)=resultOrField2;
    }
    else{
        resultOrField2=14;
        Level22_81CF0Field(owner21,unsigned char*,0x45)=resultOrField2;
    }
    resultOrField2=Level22_81CF0Field(owner21,unsigned char*,0x46);
    resultOrField2*=2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data65920View1,short*,resultOrField2);
    Level22_81CF0Keep(fieldOrIntermediate3);
    resultOrField2=fieldOrIntermediate3*5;
    Level22_81CF0Keep(resultOrField2);
    argumentOrField4=resultOrField2*32;
    Level22_81CF0Keep(argumentOrField4);
    fieldOrIntermediate3=Level22_81CF0Field(owner21,unsigned char*,0x45);
    resultOrField2+=argumentOrField4;
    fieldOrIntermediate3*=2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data65920View1,short*,fieldOrIntermediate3);
    resultOrField2>>=11;
    Level22_81CF0MultiplyComplete(resultOrField2,fieldOrIntermediate3);
    Level22_81CF0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    resultOrField2=Level22_81CF0Field(owner21,unsigned char*,0x46);
    resultOrField2*=2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data658A0View1,short*,resultOrField2);
    Level22_81CF0Keep(fieldOrIntermediate3);
    resultOrField2=fieldOrIntermediate3*5;
    Level22_81CF0Keep(resultOrField2);
    argumentOrField4=resultOrField2*32;
    Level22_81CF0Keep(argumentOrField4);
    fieldOrIntermediate3=Level22_81CF0Field(owner21,unsigned char*,0x45);
    resultOrField2+=argumentOrField4;
    fieldOrIntermediate3*=2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data65920View1,short*,fieldOrIntermediate3);
    resultOrField2>>=11;
    Level22_81CF0MultiplyComplete(resultOrField2,fieldOrIntermediate3);
    originalOddTrajectoryDivisor=0;
    selectedOrCreatedOrVector20=0;
    scanAddressOrCountOrBound19=(int)&Level22_81CF0Data6E788View1;
    originalFrame.spC0=0;
    Level22_81CF0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    resultOrField2=Level22_81CF0Field(owner21,unsigned char*,0x45);
    bestAngleOrSize23=127;
    resultOrField2*=2;
    fieldOrIntermediate3=Level22_81CF0Field(&Level22_81CF0Data658A0View1,short*,resultOrField2);
    bestDistanceOrCount22=0x7800;
    resultOrField2=fieldOrIntermediate3*165;
    resultOrField2>>=11;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    goto scanOriginalOwner;
originalOwnerCandidate:
    if(positionCandidateOrScalar16==owner21)goto scanOriginalOwner;
    resultOrField2=Level22_81CF0Field(positionCandidateOrScalar16,int*,8);
    argumentOrField4=owner21+12;
    if(!resultOrField2)goto scanOriginalOwner;
    argumentOrField5=positionCandidateOrScalar16+12;
    resultOrField2=Level22_81CF0Call4F334View1(argumentOrField4,argumentOrField5);
    angleAddressOrDistanceOrVector17=resultOrField2;
    argumentOrField6=0;
    fieldOrIntermediate3=Level22_81CF0Field(positionCandidateOrScalar16,int*,12);
    argumentOrField4=Level22_81CF0Field(owner21,int*,12);
    resultOrField2=Level22_81CF0Field(positionCandidateOrScalar16,int*,16);
    argumentOrField5=Level22_81CF0Field(owner21,int*,16);
    argumentOrField4=fieldOrIntermediate3-argumentOrField4;
    argumentOrField5=resultOrField2-argumentOrField5;
    resultOrField2=Level22_81CF0Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField5=Level22_81CF0Field(owner21,unsigned char*,0x46);
    argumentOrField4=resultOrField2;
    resultOrField2=Level22_81CF0Call4F264View1(argumentOrField4,argumentOrField5);
    fieldOrIntermediate3=0x1800-angleAddressOrDistanceOrVector17;
    argumentOrField4=resultOrField2;
    if(fieldOrIntermediate3<0)fieldOrIntermediate3=angleAddressOrDistanceOrVector17-0x1800;
    resultOrField2=argumentOrField4<4;
    angleAddressOrDistanceOrVector17=fieldOrIntermediate3;
    if(!resultOrField2)goto scanOriginalOwner;
    Level22_81CF0Keep(angleAddressOrDistanceOrVector17);
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
    positionCandidateOrScalar16=Level22_81CF0Field(scanAddressOrCountOrBound19,int*,0);
    scanAddressOrCountOrBound19+=4;
    if(positionCandidateOrScalar16)goto originalOwnerCandidate;
    if(!selectedOrCreatedOrVector20)goto originalTrajectoryDone;
    angleAddressOrDistanceOrVector17=(int)&originalFrame.sp38;
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level22_81CF0Keep(argumentOrField4);
    argumentOrField5=privateOrCreatedPrivate18;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    positionCandidateOrScalar16=(int)&originalFrame.sp48;
    __asm__("":"=r"(positionCandidateOrScalar16):"0"(positionCandidateOrScalar16),"m"(originalFrame.sp38));
    argumentOrField4=positionCandidateOrScalar16;
    Level22_81CF0Keep(argumentOrField4);
    argumentOrField5=owner21+12;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    __asm__ volatile(""::"m"(originalFrame.sp48):"$19");
    scanAddressOrCountOrBound19=0;
    argumentOrField4=(int)&originalFrame.sp28;
originalTrajectoryLoop:
    argumentOrField5=owner21+12;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    argumentOrField6=angleAddressOrDistanceOrVector17;
    Level22_81CF0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=originalFrame.sp40;
    argumentOrField6=angleAddressOrDistanceOrVector17;
    resultOrField2-=10;
    originalFrame.sp40=resultOrField2;
    Level22_81CF0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
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
    resultOrField2=Level22_81CF0Call4F334View1(argumentOrField4,argumentOrField5);
    if(resultOrField2>=1200)goto originalTrajectoryNext;
    resultOrField2=Level22_81CF0Field(selectedOrCreatedOrVector20,int*,20);
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
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    resultOrField2=scanAddressOrCountOrBound19*2;
    Level22_81CF0Keep(resultOrField2);
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
        Level22_81CF0Field(privateOrCreatedPrivate18,int*,12)=capturedLowOrTarget8;
        Level22_81CF0Call4F1C8View1(argumentOrField4,argumentOrField5,argumentOrField6);
        fieldOrIntermediate3=originalFrame.sp28;
        fieldOrIntermediate3/=originalOddTrajectoryDivisor;
        resultOrField2=originalFrame.sp30;
        resultOrField2+=400;
        originalFrame.sp30=resultOrField2;
        resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,0);
        resultOrField2+=fieldOrIntermediate3;
        Level22_81CF0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
        fieldOrIntermediate3=originalFrame.sp2C;
        fieldOrIntermediate3/=originalOddTrajectoryDivisor;
        resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,4);
        resultOrField2+=fieldOrIntermediate3;
        Level22_81CF0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
        fieldOrIntermediate3=originalFrame.sp30;
        fieldOrIntermediate3/=originalOddTrajectoryDivisor;
        resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
        resultOrField2+=fieldOrIntermediate3;
        Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    }
    resultOrField2=330;
    Level22_81CF0Field(privateOrCreatedPrivate18,short*,18)=resultOrField2;
    resultOrField2=3;
    Level22_81CF0Field(owner21,unsigned char*,0x48)=resultOrField2;
    return;
    originalState3:;
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    Level22_81CF0Call4F194View1(positionCandidateOrScalar16, positionCandidateOrScalar16, privateOrCreatedPrivate18);
    Level22_81CF0Field(privateOrCreatedPrivate18, int *, 8) = (int) (Level22_81CF0Field(privateOrCreatedPrivate18, int *, 8) - 0xA);
    Level22_81CF0Call4EDE8View1(privateOrCreatedPrivate18, 1);
    if ((Level22_81CF0Field(owner21, int *, 0xC) >= 0x400) && (Level22_81CF0Field(owner21, int *, 0x10) >= 0x400) && (Level22_81CF0Field(owner21, int *, 0x14) >= 0x400)) {
        if (Level22_81CF0Call18368View1(&originalFrame.sp68, positionCandidateOrScalar16) != 0) {
            Level22_81CF0Call4F1C8View1(positionCandidateOrScalar16, positionCandidateOrScalar16, privateOrCreatedPrivate18);
            Level22_81CF0Field(owner21, unsigned char *, 0x48) = 4U;
        }
        temp_v0_2 = Level22_81CF0Call1BA30View1(positionCandidateOrScalar16, 0x12C, 0, 0, 0x800000, owner21);
        if (temp_v0_2 != 0) {
            temp_v0_3 = Level22_81CF0Call4E880View1(Level22_81CF0Field(privateOrCreatedPrivate18, int *, 0), Level22_81CF0Field(privateOrCreatedPrivate18, int *, 4), 0);
            Level22_81CF0Field(temp_v0_2, unsigned char *, 0x51) = temp_v0_3;
            if (!(temp_v0_3 & 0xFF)) {
                Level22_81CF0Field(temp_v0_2, unsigned char *, 0x51) = 1U;
            }
            Level22_81CF0Field(owner21, unsigned char *, 0x48) = 4U;
        }
        originalFrame.sp68 = Level22_81CF0Call363DCView1(0, 7);
        originalFrame.sp6C = Level22_81CF0Call363DCView1(0, 7);
        originalFrame.sp70 = 0xF;
        if (Level22_81CF0Data6C640View1 & 1) {
            Level22_81CF0DataSpawnParticleView1(1, 0x3A, owner21 + 0xC, &originalFrame.sp68);
        }
        if (Level22_81CF0Call19194View1(owner21 + 0xC, 0x7D) != 0) {
            Level22_81CF0Field(owner21, unsigned char *, 0x48) = 4U;
        }
        goto block_139;
    }
    goto block_133;
    originalState4:;
    bestDistanceOrCount22=0;
originalFirstParticleLoop:
    resultOrField2=Level22_81CF0Call363DCView1(0,40);
    originalFrame.sp78=resultOrField2;
    resultOrField2=Level22_81CF0Call363DCView1(0,40);
    originalFrame.sp7C=resultOrField2;
    resultOrField2=Level22_81CF0Call363DCView1(0,40);
    argumentOrField4=1;
    argumentOrField5=58;
    argumentOrField6=owner21+12;
    argumentOrField7=(int)&originalFrame.sp78;
    __asm__ volatile(""::"r"(argumentOrField4),"r"(argumentOrField5),"r"(argumentOrField6),"r"(argumentOrField7):"memory");
    fieldOrIntermediate3=(int)Level22_81CF0DataSpawnParticleView1;
    __asm__("":"=r"(bestDistanceOrCount22):"0"(bestDistanceOrCount22),"r"(fieldOrIntermediate3));
    bestDistanceOrCount22++;
    originalFrame.sp80=resultOrField2;
    ((void*(*)(int,int,void*,void*))fieldOrIntermediate3)(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
    if(bestDistanceOrCount22<5)goto originalFirstParticleLoop;
    bestDistanceOrCount22=0;
    bestAngleOrSize23=80;
originalCreatedParticleLoop:
    resultOrField2=Level22_81CF0Data6C578View1;
    fieldOrIntermediate3=Level22_81CF0Data6C574View1;
    resultOrField2-=fieldOrIntermediate3;
    argumentOrField4=owner21;
    if(resultOrField2<21)goto originalCreatedParticleDone;
    argumentOrField4=Level22_81CF0Field(owner21,short*,0x36);
    resultOrField2=Level22_81CF0DataSpawnMobyView1(argumentOrField4,owner21);
    selectedOrCreatedOrVector20=resultOrField2;
    Level22_81CF0Keep(selectedOrCreatedOrVector20);
    if(!selectedOrCreatedOrVector20)goto originalCreatedParticleNext;
    privateOrCreatedPrivate18=Level22_81CF0Field(selectedOrCreatedOrVector20,int*,0);
    resultOrField2=Level22_81CF0DatarandView1();
    scanAddressOrCountOrBound19=resultOrField2&4095;
    resultOrField2=Level22_81CF0DatarandView1();
    argumentOrField4=selectedOrCreatedOrVector20+12;
    argumentOrField5=owner21+12;
    fieldOrIntermediate3=-1;
    angleAddressOrDistanceOrVector17=resultOrField2&4095;
    Level22_81CF0Field(selectedOrCreatedOrVector20,int*,8)=0;
    Level22_81CF0Field(selectedOrCreatedOrVector20,int*,28)=fieldOrIntermediate3;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    resultOrField2=Level22_81CF0Call4EA2CView1(angleAddressOrDistanceOrVector17);
    argumentOrField4=scanAddressOrCountOrBound19;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=resultOrField2;
    resultOrField2=Level22_81CF0Call4EA2CView1(argumentOrField4);
    positionCandidateOrScalar16>>=6;
    Level22_81CF0MultiplyComplete(positionCandidateOrScalar16,resultOrField2);
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level22_81CF0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    resultOrField2=Level22_81CF0Call4EA2CView1(argumentOrField4);
    argumentOrField4=scanAddressOrCountOrBound19;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=resultOrField2;
    resultOrField2=Level22_81CF0Call4E9E4View1(argumentOrField4);
    positionCandidateOrScalar16>>=6;
    Level22_81CF0MultiplyComplete(positionCandidateOrScalar16,resultOrField2);
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level22_81CF0CaptureLow(capturedLowOrTarget8);
    resultOrField2=capturedLowOrTarget8>>12;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    resultOrField2=Level22_81CF0Call4E9E4View1(argumentOrField4);
    argumentOrField4=30;
    argumentOrField5=50;
    __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrField4),"r"(argumentOrField5));
    resultOrField2>>=6;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level22_81CF0Call3636CView1(argumentOrField4,argumentOrField5);
    Level22_81CF0Field(privateOrCreatedPrivate18,short*,16)=resultOrField2;
    resultOrField2=5;
    Level22_81CF0Field(privateOrCreatedPrivate18,unsigned char*,20)=0;
    Level22_81CF0Field(selectedOrCreatedOrVector20,unsigned char*,0x48)=resultOrField2;
    Level22_81CF0Field(selectedOrCreatedOrVector20,unsigned char*,0x4F)=bestAngleOrSize23;
    Level22_81CF0Field(selectedOrCreatedOrVector20,unsigned char*,0x4C)=bestAngleOrSize23;
    Level22_81CF0Field(selectedOrCreatedOrVector20,unsigned char*,0x4E)=bestAngleOrSize23;
    originalCreatedParticleNext:bestDistanceOrCount22++;
    if(bestDistanceOrCount22<8)goto originalCreatedParticleLoop;
    originalCreatedParticleDone:Level22_81CF0Call3BABCView1(owner21,2,0);
    goto block_133;
    originalState5:;
    resultOrField2=Level22_81CF0Field(owner21,int*,12);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level22_81CF0Field(owner21,int*,16);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level22_81CF0Field(owner21,int*,20);
    argumentOrField4=owner21+12;
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level22_81CF0Call19194View1(argumentOrField4,150);
    __asm__("":"=r"(owner21):"0"(owner21),"r"(resultOrField2));
    argumentOrField4=owner21+12;
    if(!resultOrField2)goto originalState5Move;
    argumentOrField5=(int)&Level22_81CF0Data71918View1;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,0);
    resultOrField2=Level22_81CF0Field(argumentOrField5,int*,0);
    Level22_81CF0MultiplyComplete(fieldOrIntermediate3,resultOrField2);
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,4);
    Level22_81CF0CaptureLow(argumentOrField6);
    resultOrField2=Level22_81CF0Data7191CView1;
    Level22_81CF0MultiplyComplete(fieldOrIntermediate3,resultOrField2);
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    Level22_81CF0CaptureLow(argumentOrField4);
    resultOrField2=Level22_81CF0Data71920View1;
    Level22_81CF0MultiplyComplete(fieldOrIntermediate3,resultOrField2);
    resultOrField2=argumentOrField6+argumentOrField4;
    Level22_81CF0CaptureLow(fieldOrIntermediate3);
    resultOrField2+=fieldOrIntermediate3;
    __asm__("":"=r"(owner21):"0"(owner21),"r"(resultOrField2));
    argumentOrField4=owner21+12;
    if(resultOrField2>=0)goto originalState5Move;
    argumentOrField4=privateOrCreatedPrivate18;
    argumentOrField6=privateOrCreatedPrivate18;
    resultOrField2=Level22_81CF0Call4EF74View1(argumentOrField4,argumentOrField5,argumentOrField6);
    __asm__("":"=r"(owner21):"0"(owner21),"r"(resultOrField2));
    argumentOrField4=owner21+12;
    if(!resultOrField2)goto originalState5Move;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,0);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,4);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    originalState5Move:argumentOrField5=argumentOrField4;
    argumentOrField6=privateOrCreatedPrivate18;
    Level22_81CF0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    resultOrField2-=6;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    if(resultOrField2< -128){
        resultOrField2=-128;
        Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    }
    resultOrField2=Level22_81CF0Call359A4View1(privateOrCreatedPrivate18+16,2);
    if(resultOrField2)goto block_133;
    goto originalDone;
    originalState6:;
    resultOrField2=Level22_81CF0Field(owner21,int*,12);
    if(resultOrField2<1024)goto originalOutside6;
    resultOrField2=Level22_81CF0Field(owner21,int*,16);
    if(resultOrField2<1024)goto originalOutside6;
    resultOrField2=Level22_81CF0Field(owner21,int*,20);
    if(resultOrField2<1024){
        originalOutside6:resultOrField2=4;
        Level22_81CF0Field(owner21,unsigned char*,0x48)=resultOrField2;
    }
    argumentOrField4=(int)&originalFrame.sp88;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    argumentOrField6=privateOrCreatedPrivate18;
    Level22_81CF0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=privateOrCreatedPrivate18;
    argumentOrField5=1;
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    __asm__ volatile(""::"r"(resultOrField2):"$19");
    scanAddressOrCountOrBound19=125;
    resultOrField2-=10;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level22_81CF0Call4EDE8View1(argumentOrField4,argumentOrField5);
    Level22_81CF0Keep(scanAddressOrCountOrBound19);
    fieldOrIntermediate3=resultOrField2+8;
    resultOrField2=scanAddressOrCountOrBound19<fieldOrIntermediate3;
    argumentOrField4=positionCandidateOrScalar16;
    if(resultOrField2)scanAddressOrCountOrBound19=fieldOrIntermediate3;
    argumentOrField5=scanAddressOrCountOrBound19;
    resultOrField2=Level22_81CF0Call19194View1(argumentOrField4,argumentOrField5);
    if(!resultOrField2)goto originalState6Particles;
    angleAddressOrDistanceOrVector17=(int)&Level22_81CF0Data71920View1;
    selectedOrCreatedOrVector20=angleAddressOrDistanceOrVector17-8;
    argumentOrField4=selectedOrCreatedOrVector20;
    Level22_81CF0Keep(argumentOrField4);
    Level22_81CF0Field(privateOrCreatedPrivate18,unsigned char*,20)=0;
    positionCandidateOrScalar16=Level22_81CF0Field(angleAddressOrDistanceOrVector17,int*,0);
    if(positionCandidateOrScalar16<0)positionCandidateOrScalar16=-positionCandidateOrScalar16;
    resultOrField2=Level22_81CF0Call4EDE8View1(argumentOrField4,0);
    positionCandidateOrScalar16=positionCandidateOrScalar16<resultOrField2;
    if(!positionCandidateOrScalar16)goto originalVerticalBounce;
    positionCandidateOrScalar16=(int)&originalFrame.sp98;
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=selectedOrCreatedOrVector20;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=privateOrCreatedPrivate18;
    Level22_81CF0Keep(argumentOrField4);
    argumentOrField5=positionCandidateOrScalar16;
    Level22_81CF0Keep(argumentOrField5);
    argumentOrField6=privateOrCreatedPrivate18;
    resultOrField2=Level22_81CF0Call4EF74View1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=owner21;
    if(!resultOrField2)goto originalState6Particles;
    argumentOrField5=0;
    argumentOrField6=0;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,0);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,0)=resultOrField2;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,4);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,4)=resultOrField2;
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    resultOrField2=fieldOrIntermediate3*6;
    resultOrField2>>=3;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level22_81CF0Call3BABCView1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=resultOrField2;
    if(argumentOrField4<0)goto originalState6Particles;
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    if(resultOrField2<0)resultOrField2=-resultOrField2;
    Level22_81CF0Keep(resultOrField2);
    argumentOrField5=resultOrField2*40;
    Level22_81CF0Call3C140View1(argumentOrField4,argumentOrField5);
    goto originalState6Particles;
originalVerticalBounce:
    positionCandidateOrScalar16=Level22_81CF0Field(angleAddressOrDistanceOrVector17,int*,0);
    if(positionCandidateOrScalar16<0){
        resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
        argumentOrField4=owner21;
        if(resultOrField2>0)goto originalReverseZ;
    }
    if(positionCandidateOrScalar16<=0)goto originalState6Particles;
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    argumentOrField4=owner21;
    if(resultOrField2>=0)goto originalState6Particles;
originalReverseZ:
    argumentOrField5=0;
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    argumentOrField6=0;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,0)=0;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,4)=0;
    resultOrField2=-resultOrField2;
    resultOrField2>>=1;
    Level22_81CF0Field(privateOrCreatedPrivate18,int*,8)=resultOrField2;
    resultOrField2=Level22_81CF0Call3BABCView1(argumentOrField4,argumentOrField5,argumentOrField6);
    argumentOrField4=resultOrField2;
    if(argumentOrField4>=0){
        resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
        if(resultOrField2<0)resultOrField2=-resultOrField2;
        argumentOrField5=resultOrField2*40;
        Level22_81CF0Call3C140View1(argumentOrField4,argumentOrField5);
    }
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,int*,8);
    if(resultOrField2<14){
        resultOrField2=Level22_81CF0Call35D38View1(owner21);
        resultOrField2+=scanAddressOrCountOrBound19;
        Level22_81CF0Field(owner21,int*,20)=resultOrField2;
        Level22_81CF0Field(owner21,unsigned char*,0x48)=0;
    }
originalState6Particles:
    resultOrField2=Level22_81CF0DatarandView1();
    resultOrField2&=3;
    originalFrame.sp88=resultOrField2;
    resultOrField2=Level22_81CF0DatarandView1();
    resultOrField2&=3;
    originalFrame.sp8C=resultOrField2;
    resultOrField2=20;
    originalFrame.sp90=resultOrField2;
    resultOrField2=Level22_81CF0Field(privateOrCreatedPrivate18,unsigned char*,20);
    if(!resultOrField2)goto block_139;
    resultOrField2=Level22_81CF0Data6C640View1;
    resultOrField2&=1;
    argumentOrField4=1;
    if(!resultOrField2)goto block_139;
    argumentOrField5=58;
    argumentOrField6=owner21+12;
    resultOrField2=(int)Level22_81CF0DataSpawnParticleView1;
    argumentOrField7=(int)&originalFrame.sp88;
    goto originalCommonParticle;
    originalState99:;
    resultOrField2=Level22_81CF0Field(owner21,int*,12);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level22_81CF0Field(owner21,int*,16);
    if(resultOrField2<1024)goto block_133;
    resultOrField2=Level22_81CF0Field(owner21,int*,20);
    argumentOrField4=(int)&originalFrame.sp98;
    if(resultOrField2<1024)goto block_133;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    Level22_81CF0Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=positionCandidateOrScalar16;
    argumentOrField6=privateOrCreatedPrivate18;
    Level22_81CF0Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
    __asm__("":"=r"(owner21):"0"(owner21),"m"(originalFrame.sp98));
    argumentOrField5=Level22_81CF0Field(privateOrCreatedPrivate18,int*,12);
    argumentOrField4=positionCandidateOrScalar16;
    if(!argumentOrField5)goto originalState99NearDone;
    argumentOrField5+=12;
    resultOrField2=Level22_81CF0Call4F334View1(argumentOrField4,argumentOrField5);
    if(resultOrField2>=500)goto originalState99NearDone;
    resultOrField2=Level22_81CF0Field(owner21,short*,56);
    fieldOrIntermediate3=Level22_81CF0Field(privateOrCreatedPrivate18,int*,12);
    argumentOrField4=Level22_81CF0Field(owner21,int*,20);
    fieldOrIntermediate3=Level22_81CF0Field(fieldOrIntermediate3,int*,20);
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
    Level22_81CF0Field(owner21,unsigned char*,0x48)=resultOrField2;
    originalState99NearDone:positionCandidateOrScalar16=owner21+12;
    originalState99NearContinue:argumentOrField4=positionCandidateOrScalar16;
    argumentOrField5=100;
    argumentOrField6=7;
    resultOrField2=Level22_81CF0Call1C288View1(argumentOrField4,argumentOrField5,argumentOrField6);
    __asm__("":"=r"(privateOrCreatedPrivate18):"0"(privateOrCreatedPrivate18),"r"(resultOrField2));
    argumentOrField4=privateOrCreatedPrivate18+21;
    if(resultOrField2){
        argumentOrField4=Level22_81CF0Field(privateOrCreatedPrivate18,int*,0);
        argumentOrField5=Level22_81CF0Field(privateOrCreatedPrivate18,int*,4);
        argumentOrField6=0;
        resultOrField2=Level22_81CF0Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
        Level22_81CF0Field(&Level22_81CF0Data70328View1,int*,0x298)=resultOrField2;
        resultOrField2=4;
        Level22_81CF0Field(owner21,unsigned char*,0x48)=resultOrField2;
        __asm__("":"=r"(privateOrCreatedPrivate18):"0"(privateOrCreatedPrivate18),"m"(Level22_81CF0Field(owner21,unsigned char*,0x48)));
        argumentOrField4=privateOrCreatedPrivate18+21;
    }
    resultOrField2=Level22_81CF0Call359A4View1(argumentOrField4,1);
    argumentOrField4=positionCandidateOrScalar16;
    if(resultOrField2){
        resultOrField2=Level22_81CF0Call1BA30View1(argumentOrField4,150,0,0,0x10000000,owner21);
        if(resultOrField2){
            resultOrField2=4;
            Level22_81CF0Field(owner21,unsigned char*,0x48)=resultOrField2;
        }
    }
    resultOrField2=Level22_81CF0Call359A4View1(privateOrCreatedPrivate18+16,2);
    angleAddressOrDistanceOrVector17=(int)&originalFrame.sp98;
    if(!resultOrField2)goto originalState99Probe;
    block_133:Level22_81CF0Call55B18View1(owner21);
    return;
originalState99Probe:
    argumentOrField4=angleAddressOrDistanceOrVector17;
    Level22_81CF0Keep(argumentOrField4);
    positionCandidateOrScalar16=owner21+12;
    argumentOrField5=positionCandidateOrScalar16;
    resultOrField2=Level22_81CF0Call18368View1(argumentOrField4,argumentOrField5);
    if(resultOrField2){
        resultOrField2=4;
        Level22_81CF0Field(owner21,unsigned char*,0x48)=resultOrField2;
    }
    resultOrField2=Level22_81CF0Call363DCView1(0,7);
    originalFrame.sp98=resultOrField2;
    resultOrField2=Level22_81CF0Call363DCView1(0,7);
    originalFrame.sp9C=resultOrField2;
    resultOrField2=Level22_81CF0Data6C640View1;
    fieldOrIntermediate3=15;
    resultOrField2&=1;
    originalFrame.spA0=fieldOrIntermediate3;
    if(!resultOrField2)goto block_139;
    argumentOrField4=1;
    argumentOrField5=58;
    argumentOrField6=positionCandidateOrScalar16;
    resultOrField2=(int)Level22_81CF0DataSpawnParticleView1;
    argumentOrField7=angleAddressOrDistanceOrVector17;
    originalCommonParticle:((void*(*)(int,int,void*,void*))resultOrField2)(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
    block_139:Level22_81CF0Call35D38View1(owner21);
    Level22_81CF0Call5629CView1(owner21);
    return;
    originalDone:return;
}
#undef Level22_81CF0Field


typedef struct { int linkedIndex, animationA, animationB; } DecodedLinkedModelTag;
extern Moby* D_8006C550;
int DecodedLinkedModelHeadingDifference(int,int) __asm__("func_8004F264");
void func_level_22_80082CCC(Moby* moby) {
    DecodedLinkedModelTag* tag = moby->mobyTag;
    Moby* linked = &D_8006C550[tag->linkedIndex];
    Vector3D modelPoint, position, delta;
    int angle, length;
    if (linked->state >= 0x80) {
        func_80055B18(moby);
        return;
    }
    switch (moby->state) {
    case 0:
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

typedef struct { Vector3D position; int reserved0C; } DecodedLaunchPoint;
typedef struct { short count; unsigned char reserved02[10]; DecodedLaunchPoint* points; } DecodedLaunchPath;
typedef struct { DecodedLaunchPath* path; Moby* spawned; int timer, speed, mobyClass; } DecodedPathLaunchTag;
typedef struct { Vector3D velocity; unsigned char reserved0C[8]; unsigned char active; } DecodedPathLaunchChildTag;
int DecodedPathLaunchTimer(void*,int) __asm__("func_800359A4");
int DecodedPathLaunchDistance(Vector3D*,Vector3D*) __asm__("func_8004F334");
int DecodedPathLaunchVertical(Vector3D*,Vector3D*,int,int,int*) __asm__("func_800365E4");
void func_level_22_80082F38(Moby* moby) {
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
void func_level_22_8008316C(Moby* actor) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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
extern unsigned char P7D820D_8006C7B4 __asm__("D_8006C7B4");
extern int P7D820D_8006C58C __asm__("D_8006C58C");
extern unsigned char P7D820D_80070300[] __asm__("D_80070300");
extern unsigned char *P7D820D_8006C550 __asm__("D_8006C550");
int P7D820func_80053F50() __asm__("func_80053F50");
int P7D820func_8003B634() __asm__("func_8003B634");
void func_level_22_80083418(void *owner) {
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
    if ((P7D820Field(state,unsigned char*,2)==1) && !(P7D820D_8006C7B4&1) && !(P7D820D_80070300[P7D820D_8006C58C]&1)) {
        P7D820Field(state,unsigned char*,2)=4;
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
    if (P7D820Field(state,unsigned char*,4)==2) {
        workWord3=P7D820Field(state,int*,0x58);
        workWord2=workWord3*11;
        workWord3=(int)P7D820D_8006C550;
        __asm__("" : "=r"(workWord2),"=r"(workWord3) : "0"(workWord2),"1"(workWord3));
        workWord2<<=3;
        workWord2+=workWord3;
        workWord3=3;
        P7D820Field((void*)workWord2,unsigned char*,0x48)=workWord3;
        P7D820Field(owner,unsigned char*,0x48)=99;
        goto finishPosition;
    }
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
void func_level_22_80083A40(void *arg0) {
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
void func_level_22_80084310(Moby *input) {
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


extern int D_8006E048;
extern Moby* D_8006C550;
int func_80036220(Vector3D*,void*,int,int);
void DecodedCameraSave(void*,Vector3D*,int) __asm__("func_8003B634");
void func_80037014(Moby*);
void func_80013D44(Vector3D*,int,int,int);
extern Moby* volatile DecodedResetPlayerActor __asm__("D_80070328 + 0x250");
#define DecodedResetPlayerWord(offset) (*(int*)((char*)&spyro + (offset)))
void func_level_22_8008471C(Moby* actor) {
    register Moby* moby __asm__("$17") = actor;
    int* tag = moby->mobyTag;
    register int* inner __asm__("$16");
    Moby* selected;
    Moby* reset;
    register Vector3D* destination __asm__("$4");
    switch (moby->state) {
    case 0:
        if (func_80036220((Vector3D*)&spyro,tag,0,1024)) {
            DecodedCameraSave(&savedData,&moby->position,moby->angle.yaw);
            moby->state = 3;
        }
        break;
    case 1:
        if (D_8006E048 == 1) {
            moby->updateDistance = 16;
            moby->state = 0;
        }
        break;
    case 2:
        if (D_8006E048 == 1) {
            reset = DecodedResetPlayerActor;
            inner = reset->mobyTag;
            __asm__("" : "=r"(inner) : "0"(inner),"r"(reset) : "memory");
            DecodedResetPlayerWord(0x244) = 0;
            *(short*)((char*)reset + 0x38) = 0;
            destination = &DecodedResetPlayerActor->position;
            __asm__("" : "=r"(destination) : "0"(destination) : "$5");
            func_8004F178(destination,(Vector3D*)((char*)inner + 0x4C));
            func_80037014(DecodedResetPlayerActor);
            *((unsigned char*)DecodedResetPlayerActor + 0x52) = 254;
            func_80055D24(DecodedResetPlayerActor,2);
            DecodedResetPlayerActor->angle.yaw = inner[0x48/4];
            DecodedResetPlayerActor->state = 0;
            DecodedResetPlayerWord(0x288) = 0;
            moby->updateDistance = 16;
            moby->state = 0;
        }
        break;
    case 3:
        DecodedResetPlayerWord(0x20C) = 0x10000002;
        if (!DecodedResetPlayerWord(0x244)) {
            DecodedResetPlayerWord(0x20C) = 0x10000082;
            DecodedResetPlayerWord(0x23C) = 0;
        }
        selected = &D_8006C550[tag[6]];
        func_80013D44(&selected->position,selected->angle.yaw,0,0);
        moby->updateDistance = 255;
        if (DecodedResetPlayerWord(0x244)) moby->state = 2;
        else moby->state = 1;
        break;
    }
}
#undef DecodedResetPlayerWord

extern unsigned char D_80066FCC[], D_80070300[];
void func_80021ED8(void*, int, int);
void func_80055B18(Moby*);
void func_level_22_80084920(Moby* moby) {
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
void func_level_22_8008498C(Moby* argument) {
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
void func_level_22_80084DC4(Moby* moby) {
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

void func_level_22_800850F4(Moby* moby) {
    int* tag = moby->mobyTag;
    register int first __asm__("$2") = tag[0];
    register int* destination __asm__("$4");
    __asm__("" : "=r"(first) : "0"(first) : "$4");
    destination = &spyro.unk21[0];
    __asm__("" : "=r"(destination) : "0"(destination), "r"(first));
    *destination = first;
    spyro.unk21[4] = tag[1];
    if (tag[0] & 8) {
        func_8004F178((Vector3D*)(destination + 5), (Vector3D*)(tag + 2));
        spyro.unk21[8] = tag[5];
        spyro.unk21[9] = tag[6];
        spyro.unk21[10] = tag[7];
    } else {
        func_8004F178((Vector3D*)(destination + 1), &moby->position);
    }
    func_80055B18(moby);
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
void func_level_22_800851A4(Moby* argument) {
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
/* SCUS-94467 USA Rev0, original800856CC.
* Assembly SHA256 602897339b7d53be41cd0de6d790b5127fcba335282867fd4be59168206ebb70.
* AI generated; not human reviewed. All922 instructions,
* six selector words and actual targets are required. Original frame0x88
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
int Actor22_856CCCall36220View1() __asm__("func_80036220");
#define Actor22_856CCField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Actor22_856CCCall18368View1() __asm__("func_80018368");
int Actor22_856CCCall19194View1() __asm__("func_80019194");
int Actor22_856CCCall1BA30View1() __asm__("func_8001BA30");
int Actor22_856CCCall1C288View1() __asm__("func_8001C288");
int Actor22_856CCCall34F80View1() __asm__("func_80034F80");
int Actor22_856CCCall359A4View1() __asm__("func_800359A4");
int Actor22_856CCCall369B8View1() __asm__("func_800369B8");
int Actor22_856CCCall3BABCView1() __asm__("func_8003BABC");
int Actor22_856CCCall3BE70View1() __asm__("func_8003BE70");
int Actor22_856CCCall3BFC0View1() __asm__("func_8003BFC0");
int Actor22_856CCCall3C0B0View1() __asm__("func_8003C0B0");
int Actor22_856CCCall3C140View1() __asm__("func_8003C140");
int Actor22_856CCCall4E880View1() __asm__("func_8004E880");
int Actor22_856CCCall4ED6CView1() __asm__("func_8004ED6C");
int Actor22_856CCCall4EDE8View1() __asm__("func_8004EDE8");
int Actor22_856CCCall4EF74View1() __asm__("func_8004EF74");
int Actor22_856CCCall4F168View1() __asm__("func_8004F168");
int Actor22_856CCCall4F178View1() __asm__("func_8004F178");
int Actor22_856CCCall4F194View1() __asm__("func_8004F194");
int Actor22_856CCCall4F1C8View1() __asm__("func_8004F1C8");
int Actor22_856CCCall4F284View1() __asm__("func_8004F284");
int Actor22_856CCCall4F334View1() __asm__("func_8004F334");
int Actor22_856CCCall55D24View1() __asm__("func_80055D24");
int Actor22_856CCCall55F14View1() __asm__("func_80055F14");
extern int Actor22_856CCData658A0View1 __asm__("D_800658A0");
extern int Actor22_856CCData65920View1 __asm__("D_80065920");
extern int Actor22_856CCData6C550View1 __asm__("D_8006C550");
extern int Actor22_856CCData6C700View1 __asm__("D_8006C700");
extern short Actor22_856CCData6E03EView1 __asm__("D_8006E03E");
extern short Actor22_856CCData6E040View1 __asm__("D_8006E040");
extern int Actor22_856CCData70328View1 __asm__("D_80070328");
extern int Actor22_856CCData71918View1 __asm__("D_80071918");
extern int Actor22_856CCDatag_CheatFlagsView1 __asm__("g_CheatFlags");
extern void*(*Actor22_856CCDataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Actor22_856CCData7443CView1)() __asm__("unk_ovlheader_8007443C");
extern int(*Actor22_856CCData74444View1)() __asm__("unk_ovlheader_80074444");
void func_level_22_800856CC(void *input) {
    register void *ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register int retainedAngleOrAddress16 __asm__("$16"), privateRecord17 __asm__("$17"), secondaryResult20 __asm__("$20"), retainedStackAddress19 __asm__("$19"), retainedHookArgument21 __asm__("$21");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64;
    }
    originalFrame;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateRecord17 = Actor22_856CCField(ownerRecord18, void**, 0);
    rawWord2 = Actor22_856CCField(privateRecord17, int*, 0);
    rawWord2 -= 1;
    rawWord2 = (unsigned int)rawWord2 < 2U;
    __asm__(""::"r"(rawWord2):"$21");
    retainedHookArgument21 = 0;
    if (rawWord2){
        if ((Actor22_856CCField(privateRecord17, void **, 0x2C) != 0) || ((rawWord3 = Actor22_856CCDataSpawnMobyView1(0x1CE, ownerRecord18), Actor22_856CCField(privateRecord17, void**, 0x2C) = rawWord3, (rawWord3 != 0)) && (Actor22_856CCField(rawWord3, int*, 20) = Actor22_856CCField(rawWord3, int*, 20)+512, Actor22_856CCField(Actor22_856CCField(privateRecord17, void **, 0x2C), signed char *, 0x45) = 0x30, (Actor22_856CCField(privateRecord17, void **, 0x2C) != 0)))) {
            rawWord3 = Actor22_856CCField(privateRecord17, void **, 0x2C);
            Actor22_856CCField(rawWord3, unsigned char *, 0x46) = (unsigned char) (Actor22_856CCField(rawWord3, unsigned char *, 0x46) + 8);
        }
        rawWord3 = Actor22_856CCField(privateRecord17, int*, 0);
        rawWord2 = 2;
        if (rawWord3 != rawWord2) goto continuePrivateModeEntry;
        rawWord3 = Actor22_856CCField(ownerRecord18, unsigned char*, 0x48);
        rawWord2 = 6;
        if (rawWord3 == rawWord2){
            rawWord2 = 5;
            goto comparePreservedOrReloadedState5;
        }
        rawWord2 = Actor22_856CCField(ownerRecord18, unsigned char*, 0x49);
        if (!rawWord2) goto initializeState5Comparison;
        rawWord2 = 5;
        Actor22_856CCField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        rawWord3 = Actor22_856CCField(ownerRecord18, volatile unsigned char*, 0x48);
        initializeState5Comparison:rawWord2 = 5;
        comparePreservedOrReloadedState5:if (rawWord3 == rawWord2) goto runInsertedState5;
        rawWord2 = 6;
        if (rawWord3 == rawWord2) goto runInsertedState6;
        goto continuePrivateModeEntry;
    runInsertedState5:
        if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short*, 0x28)))Actor22_856CCCall3BE70View1(Actor22_856CCField(privateRecord17, short*, 0x28));
        rawWord2 = -1;
        Actor22_856CCField(privateRecord17, short*, 0x28) = rawWord2;
        Actor22_856CCField(ownerRecord18, signed char*, 0x41) = 0;
        Actor22_856CCField(ownerRecord18, signed char*, 0x4C) = 0;
        Actor22_856CCField(ownerRecord18, signed char*, 0x4D) = 0;
        rawWord2 = Actor22_856CCField(privateRecord17, void**, 0x2C);
        if (rawWord2){
            Actor22_856CCField(rawWord2, signed char*, 0x41) = 0;
            rawWord2 = Actor22_856CCField(privateRecord17, void**, 0x2C);
            Actor22_856CCField(rawWord2, signed char*, 0x4C) = 0;
            rawWord2 = Actor22_856CCField(privateRecord17, void**, 0x2C);
            Actor22_856CCField(rawWord2, signed char*, 0x4D) = 0;
        }
        rawWord2 = 6;
        Actor22_856CCField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        return;
    runInsertedState6:
        rawWord2 = Actor22_856CCField(ownerRecord18, unsigned char*, 0x49);
        rawWord3 = 1;
        if (rawWord2) return;
        argumentWord4 = 50;
        Actor22_856CCField(ownerRecord18, signed char*, 0x41) = rawWord3;
        Actor22_856CCField(ownerRecord18, signed char*, 0x4C) = argumentWord4;
        Actor22_856CCField(ownerRecord18, signed char*, 0x4D) = rawWord3;
        rawWord2 = Actor22_856CCField(privateRecord17, void**, 0x2C);
        if (rawWord2){
            Actor22_856CCField(rawWord2, signed char*, 0x41) = rawWord3;
            rawWord2 = Actor22_856CCField(privateRecord17, void**, 0x2C);
            Actor22_856CCField(rawWord2, signed char*, 0x4C) = argumentWord4;
            rawWord2 = Actor22_856CCField(privateRecord17, void**, 0x2C);
            Actor22_856CCField(rawWord2, signed char*, 0x4D) = rawWord3;
        }
        Actor22_856CCField(ownerRecord18, unsigned char*, 0x48) = 0;
    continuePrivateModeEntry:
        if (Actor22_856CCField(ownerRecord18, unsigned char *, 0x48) != 6) {
            if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short *, 0x28)) == 0) {
                Actor22_856CCField(privateRecord17, short *, 0x28) = Actor22_856CCCall3BABCView1(ownerRecord18, 3, 4);
            }
            if ((Actor22_856CCField(ownerRecord18, unsigned char *, 0x48) != 6) && (Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), unsigned char *, 0x48) != 1) && (retainedAngleOrAddress16 = ownerRecord18 + 0xC, (((unsigned int) (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x50) - 7) < 2U) == 0)) && (Actor22_856CCCall4F334View1(retainedAngleOrAddress16, (&Actor22_856CCData70328View1 + 0x50) - 0x50) < 0x400)) {
                rawWord2 = (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 8) - Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x44)) - Actor22_856CCField(ownerRecord18, int *, 0x14);
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if (rawWord2 < 0x140) {
                    Actor22_856CCCall4F178View1(Actor22_856CCData6C550View1 + (Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + 0xC, retainedAngleOrAddress16);
                    Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), signed char *, 0x44) = 0;
                    Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), signed char *, 0x45) = 0;
                    Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), unsigned char *, 0x46) = (unsigned char) Actor22_856CCField(&Actor22_856CCData70328View1, unsigned char *, 0xE);
                    Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), signed char *, 0x4C) = 0x20;
                    Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), signed char *, 0x48) = 4;
                    Actor22_856CCCall369B8View1(Actor22_856CCData6C550View1 + (Actor22_856CCField(privateRecord17, int *, 4) * 0x58), 0x18);
                    Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x23C) = 0x24;
                    Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x20C) = (int) (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x20C) | 0x10000080);
                    Actor22_856CCField(&Actor22_856CCData70328View1, void **, 0x250) = (void *) (Actor22_856CCData6C550View1 + (Actor22_856CCField(privateRecord17, int *, 4) * 0x58));
                    Actor22_856CCField(((Actor22_856CCField(privateRecord17, int *, 4) * 0x58) + Actor22_856CCData6C550View1), signed char *, 0x48) = 4;
                    Actor22_856CCData6C700View1 = 0x2000;
                }
            }
        }
    }
    else{
        __asm__("":"=r"(retainedHookArgument21):"0"(retainedHookArgument21));
        rawWord3 = Actor22_856CCField(&Actor22_856CCData70328View1, int*, 0x50);
        rawWord2 = 19;
        if (rawWord3 == rawWord2){
            if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x4C) == 5) {
                Actor22_856CCField(privateRecord17, short *, 0xF0) = 3;
            }
            else if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x4C) == 4) {
                Actor22_856CCField(privateRecord17, short *, 0xF0) = 2;
            }
            else {
                Actor22_856CCField(privateRecord17, short *, 0xF0) = 1;
            }
        }
        else {
            Actor22_856CCField(privateRecord17, short *, 0xF0) = 0;
        }
        rawWord3 = Actor22_856CCField(ownerRecord18, unsigned char *, 0x48);
        switch (rawWord3) {
        case 0:
            rawWord3 = Actor22_856CCField(ownerRecord18, short *, 0x36);
            if ((rawWord3 == 0x36) || (rawWord3 == 0x294) || (rawWord3 == 0xFB)) {
                Actor22_856CCField(ownerRecord18, signed char *, 0x41) = 0;
                Actor22_856CCField(ownerRecord18, signed char *, 0x4C) = 0;
                Actor22_856CCField(ownerRecord18, signed char*, 0x4D) = 0;
                goto prepareHookArgument4;
            }
            argumentWord4 = retainedHookArgument21;
            goto prepareHookArgument5;
            default:goto prepareHookArgument4;
        case 4:
            if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x50) == 0x13) {
                Actor22_856CCField(ownerRecord18, unsigned char *, 0x48) = 1U;
            }
            argumentWord4 = retainedHookArgument21;
            goto prepareHookArgument5;
        case 1:
            Actor22_856CCCall359A4View1(privateRecord17+0x60, 4);
            Actor22_856CCCall4F168View1(&originalFrame.sp18);
            originalFrame.sp20 = -0x400;
            Actor22_856CCCall55D24View1(ownerRecord18, 4);
            Actor22_856CCCall4ED6CView1(ownerRecord18 + 0x20, &originalFrame.sp18, &originalFrame.sp18);
            rawWord2 = Actor22_856CCCall4E880View1(Actor22_856CCCall4EDE8View1(&originalFrame.sp18, 0), originalFrame.sp20, 1);
            argumentWord6 = 1;
            __asm__(""::"r"(argumentWord6):"$16");
            retainedAngleOrAddress16 = rawWord2;
            rawWord2 = Actor22_856CCCall4E880View1(originalFrame.sp18, originalFrame.sp1C, argumentWord6);
            argumentWord4 = retainedAngleOrAddress16;
            rawWord3 = 4;
            retainedAngleOrAddress16 = rawWord2+0x800;
            Actor22_856CCField(ownerRecord18, signed char*, 0x47) = rawWord3;
            argumentWord5 = Actor22_856CCData6E03EView1;
            retainedAngleOrAddress16 &= 0xFFF;
            rawWord2 = Actor22_856CCCall4F284View1(argumentWord4, argumentWord5);
            argumentWord4 = retainedAngleOrAddress16;
            argumentWord5 = Actor22_856CCData6E040View1;
            retainedAngleOrAddress16 = rawWord2;
            rawWord2 = Actor22_856CCCall4F284View1(argumentWord4, argumentWord5);
            retainedAngleOrAddress16 = retainedAngleOrAddress16 < 600;
            rawWord2 = rawWord2 < 600;
            if (retainedAngleOrAddress16 && rawWord2) {
                Actor22_856CCField(ownerRecord18, signed char *, 0x47) = 9;
            }
            rawWord2 = Actor22_856CCField(&Actor22_856CCDatag_CheatFlagsView1, unsigned char*, 1);
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
            Actor22_856CCCall34F80View1(argumentWord4, argumentWord5);
            if (Actor22_856CCField(ownerRecord18, unsigned char *, 0x3D) == 0) {
                Actor22_856CCField(ownerRecord18, signed char *, 0x41) = 0;
                Actor22_856CCField(ownerRecord18, signed char *, 0x3E) = 0;
                argumentWord5 = 0;
                if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0xB8) == 0) {
                    argumentWord5 = Actor22_856CCField(&Actor22_856CCData70328View1, unsigned char *, 0xC);
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
                Actor22_856CCField(ownerRecord18, signed char *, 0x3F) = rawWord2;
                rawWord2 = argumentWord5&15;
                Actor22_856CCField(ownerRecord18, signed char*, 0x40) = rawWord2;
            }
            else {
                Actor22_856CCField(ownerRecord18, signed char *, 0x41) = 1;
            }
            if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0xB8) != 0) {
                if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short *, 0x28)) != 0) {
                    Actor22_856CCCall3BE70View1(Actor22_856CCField(privateRecord17, short *, 0x28));
                }
                Actor22_856CCField(privateRecord17, short *, 0x28) = -1;
            }
            else {
                if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short *, 0x28)) == 0) {
                    Actor22_856CCField(privateRecord17, short *, 0x28) = Actor22_856CCCall3BABCView1(ownerRecord18, 0, 4);
                }
                argumentWord4 = Actor22_856CCField(privateRecord17, short *, 0x28);
                if (argumentWord4 >= 0) {
                    rawWord2 = Actor22_856CCField(&Actor22_856CCData70328View1, int*, 0x5C);
                    argumentWord5 = rawWord2&0xFFF;
                    if (argumentWord5 >= 0x801) {
                        argumentWord5 -= 0x1000;
                    }
                    argumentWord5 = argumentWord5 * 4;
                    if (argumentWord5 < 0) {
                        argumentWord5 = -argumentWord5;
                    }
                    Actor22_856CCCall3C0B0View1(argumentWord4, argumentWord5 + 0x1000);
                }
            }
            if (Actor22_856CCField(privateRecord17, int*, 12)){
                if ((unsigned int)(Actor22_856CCField(&Actor22_856CCData70328View1, int*, 0x4C)-4) >= 2U){
                    Actor22_856CCField(privateRecord17, int*, 12) = 0;
                    if (!Actor22_856CCField(privateRecord17, int*, 0x60) && Actor22_856CCCall36220View1(&Actor22_856CCData70328View1, privateRecord17+0x30, 0, 2000)){
                        Actor22_856CCField(privateRecord17, int*, 0x60) = 120;
                        retainedHookArgument21 = 2;
                    }
                }
            }
            else{
                if (!Actor22_856CCField(privateRecord17, int*, 0x60) && Actor22_856CCCall36220View1(&Actor22_856CCData70328View1, privateRecord17+0x48, 0, 1500)){
                    Actor22_856CCField(privateRecord17, int*, 0x60) = 120;
                    retainedHookArgument21 = 3;
                }
                if ((unsigned int)(Actor22_856CCField(&Actor22_856CCData70328View1, int*, 0x4C)-4) < 2U){
                    argumentWord4 = privateRecord17+100;
                    rawWord3 = (int)Actor22_856CCData74444View1;
                    rawWord2 = 1;
                    Actor22_856CCField(privateRecord17, int*, 12) = rawWord2;
                    ((int(*)())rawWord3)(argumentWord4);
                }
            }
            Actor22_856CCField(&Actor22_856CCData70328View1, void **, 0x250) = ownerRecord18;
            if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x50) != 0x13) {
                argumentWord5 = privateRecord17 + 0x64;
                if (Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x240) == 0) {
                    Actor22_856CCField(ownerRecord18, unsigned char *, 0x49) = 0U;
                    Actor22_856CCField(privateRecord17, short *, 0x22) = 0x1E;
                    Actor22_856CCField(privateRecord17, short *, 0x20) = 0x78;
                    Actor22_856CCField(privateRecord17, unsigned short *, 0x26) = 0U;
                    Actor22_856CCField(privateRecord17, short *, 0x24) = 0xC;
                    rawWord2 = Actor22_856CCField(&Actor22_856CCData70328View1, unsigned char*, 14);
                    argumentWord4 = (int)ownerRecord18;
                    rawWord2 += 128;
                    rawWord2 &= 255;
                    rawWord2 <<= 1;
                    rawWord3 = Actor22_856CCField(&Actor22_856CCData65920View1, short*, rawWord2);
                    argumentWord5 = 4;
                    rawWord2 = rawWord3*25;
                    rawWord2 >>= 9;
                    Actor22_856CCField(privateRecord17, int*, 20) = rawWord2;
                    rawWord2 = Actor22_856CCField(&Actor22_856CCData70328View1, unsigned char*, 14);
                    argumentWord6 = 0;
                    rawWord2 += 128;
                    rawWord2 &= 255;
                    rawWord2 <<= 1;
                    rawWord3 = Actor22_856CCField(&Actor22_856CCData658A0View1, short*, rawWord2);
                    rawWord2 = 125;
                    Actor22_856CCField(privateRecord17, int*, 28) = rawWord2;
                    rawWord2 = rawWord3*25;
                    rawWord2 >>= 9;
                    Actor22_856CCField(privateRecord17, int*, 24) = rawWord2;
                    Actor22_856CCCall3BABCView1(argumentWord4, argumentWord5, argumentWord6);
                    Actor22_856CCField(privateRecord17, short *, 0x2A) = -1;
                    Actor22_856CCField(ownerRecord18, unsigned char *, 0x48) = 2U;
                    if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, int*, 0x15C)) != 0) {
                        Actor22_856CCCall3BE70View1(Actor22_856CCField(privateRecord17, int*, 0x15C));
                    }
                    Actor22_856CCField(privateRecord17, int *, 0x15C) = -1;
                    if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short *, 0x28)) != 0) {
                        Actor22_856CCCall3BE70View1(Actor22_856CCField(privateRecord17, short *, 0x28));
                    }
                    Actor22_856CCField(privateRecord17, short *, 0x28) = -1;
                    goto prepareHookArgument4;
                }
            }
            else {
                argumentWord4 = retainedHookArgument21;
                goto prepareHookArgument5;
            }
            argumentWord4 = retainedHookArgument21;
            goto callSharedHook;
        case 3:
            Actor22_856CCCall369B8View1(ownerRecord18, 0x18);
            Actor22_856CCField(ownerRecord18, signed char *, 0x4D) = 0;
            Actor22_856CCField(ownerRecord18, signed char *, 0x4C) = 0;
            Actor22_856CCField(ownerRecord18, unsigned char *, 0x48) = 0U;
            goto prepareHookArgument4;
        case 2:
            argumentWord4 = (int)&originalFrame.sp28;
            __asm__(""::"r"(argumentWord4):"$16");
            retainedAngleOrAddress16 = (int)ownerRecord18+12;
            Actor22_856CCCall4F178View1(argumentWord4, retainedAngleOrAddress16);
            if (Actor22_856CCField(ownerRecord18, unsigned char *, 0x49) != 0) {
                argumentWord6 = (unsigned char) Actor22_856CCField(privateRecord17, short *, 0x24);
                Actor22_856CCField(privateRecord17, int *, 0x1C) = (int) (Actor22_856CCField(privateRecord17, int *, 0x1C) - 0xC);
                Actor22_856CCField(ownerRecord18, unsigned char *, 0x45) = (unsigned char) (Actor22_856CCField(ownerRecord18, unsigned char *, 0x45) + argumentWord6);
                Actor22_856CCField(ownerRecord18, unsigned char *, 0x44) = (unsigned char) (Actor22_856CCField(ownerRecord18, unsigned char *, 0x44) + 8);
                Actor22_856CCCall55D24View1(ownerRecord18, 4, argumentWord6);
                if ((Actor22_856CCField(ownerRecord18, int *, 0xC) >= 0x400) && (Actor22_856CCField(ownerRecord18, int *, 0x10) >= 0x400) && (Actor22_856CCField(ownerRecord18, int *, 0x14) >= 0x400)) {
                    Actor22_856CCCall4F194View1(retainedAngleOrAddress16, retainedAngleOrAddress16, privateRecord17 + 0x14);
                    goto prepareState2Sources;
                }
                goto storeState3AndReturn;
            }
        prepareState2Sources:
            Actor22_856CCField(ownerRecord18, unsigned char*, 0x49) = 1;
            __asm__ __volatile__("":"=r"(ownerRecord18):"0"(ownerRecord18):"$16");
            argumentWord4 = (int)ownerRecord18;
            argumentWord5 = 0;
            __asm__(""::"r"(argumentWord4), "r"(argumentWord5):"$16");
            retainedAngleOrAddress16 = (int)&originalFrame.sp38;
            Actor22_856CCCall55F14View1(argumentWord4, argumentWord5, retainedAngleOrAddress16);
            retainedStackAddress19 = (int)&originalFrame.sp48;
            Actor22_856CCCall55F14View1(ownerRecord18, 1, retainedStackAddress19);
            secondaryResult20 = 0;
            if (Actor22_856CCCall359A4View1(privateRecord17 + 0x22, 2) != 0) {
                if ((Actor22_856CCCall1C288View1(retainedAngleOrAddress16, 0x64, 0) != 0) || (rawWord2 = Actor22_856CCCall1C288View1(retainedStackAddress19, 0x64, 0), secondaryResult20 = rawWord2 != 0, (rawWord2 != 0))) {
                    rawWord2 = Actor22_856CCField(privateRecord17, unsigned short*, 0x26);
                    rawWord2 += 1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Actor22_856CCField(privateRecord17, unsigned short*, 0x26) = rawWord2;
                    if (secondaryResult20 != 0) {
                        rawWord2 = -0xC;
                    }
                    else{
                        __asm__ __volatile__("":::"$2");
                        rawWord2 = 12;
                    }
                    Actor22_856CCField(privateRecord17, short*, 0x24) = rawWord2;
                    __asm__ __volatile__("":::"memory");
                    Actor22_856CCField(&Actor22_856CCData70328View1, int *, 0x298) = Actor22_856CCCall4E880View1(Actor22_856CCField(privateRecord17, int *, 0x14), Actor22_856CCField(privateRecord17, int *, 0x18), 0);
                    (retainedAngleOrAddress16 = (int)&originalFrame.sp58, Actor22_856CCCall4F1C8View1(retainedAngleOrAddress16, ownerRecord18 + 0xC, (&Actor22_856CCData70328View1+0x298)-0x298));
                    argumentWord4 = privateRecord17 + 0x14;
                    rawWord2 = Actor22_856CCCall4EF74View1(argumentWord4, retainedAngleOrAddress16, argumentWord4);
                    argumentWord4 = (int)ownerRecord18;
                    if (rawWord2){
                        Actor22_856CCField(privateRecord17, int *, 0x14) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x14) * 6) >> 3);
                        Actor22_856CCField(privateRecord17, int *, 0x18) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x18) * 6) >> 3);
                        Actor22_856CCField(privateRecord17, int *, 0x1C) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x1C) * 6) >> 3);
                        rawWord2 = Actor22_856CCCall3BFC0View1(argumentWord4, Actor22_856CCField(privateRecord17, short*, 0x2A));
                        argumentWord4 = (int)&originalFrame.sp38;
                        if (rawWord2) goto callFirstCollisionWithPreparedA0;
                        {
                            __asm__ __volatile__("":::"$2");
                            rawWord2 = Actor22_856CCCall3BABCView1(ownerRecord18, 4, 0);
                            Actor22_856CCField(privateRecord17, short*, 0x2A) = rawWord2;
                            rawWord2 = (unsigned int)rawWord2 << 16;
                            argumentWord4 = rawWord2 >> 16;
                            if (argumentWord4 >= 0) {
                                rawWord2 = Actor22_856CCField(privateRecord17, int *, 0x1C);
                                if (rawWord2 < 0) {
                                    rawWord2 = -rawWord2;
                                }
                                Actor22_856CCCall3C140View1(argumentWord4, rawWord2*40);
                            }
                        }
                    }
                }
                prepareFirstCollisionStack:__asm__ __volatile__("":::"$4");
                argumentWord4 = (int)&originalFrame.sp38;
                callFirstCollisionWithPreparedA0:argumentWord5 = 150;
                argumentWord6 = Actor22_856CCCall1BA30View1(argumentWord4, argumentWord5, 1, 0, 0x10000000, ownerRecord18);
                argumentWord4 = (int)&originalFrame.sp48;
                if (argumentWord6 == 0){
                    __asm__(""::"r"(argumentWord4):"$5");
                    argumentWord5 = 150;
                    argumentWord6 = Actor22_856CCCall1BA30View1(argumentWord4, argumentWord5, 1, 0, 0x10000000, ownerRecord18);
                    argumentWord4 = privateRecord17 + 0x20;
                    if (argumentWord6 != 0) {
                        secondaryResult20 = 1;
                        goto handleSecondCollisionResult;
                    }
                }
                else {
                handleSecondCollisionResult:
                    rawWord2 = Actor22_856CCField(privateRecord17, unsigned short*, 0x26);
                    rawWord2 += 1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Actor22_856CCField(privateRecord17, unsigned short*, 0x26) = rawWord2;
                    if (secondaryResult20 != 0) {
                        rawWord2 = -0xC;
                    }
                    else{
                        __asm__ __volatile__("":::"$2");
                        rawWord2 = 12;
                    }
                    Actor22_856CCField(privateRecord17, short *, 0x24) = rawWord2;
                    retainedAngleOrAddress16 = (int)&originalFrame.sp58;
                    Actor22_856CCCall4F1C8View1(retainedAngleOrAddress16, ownerRecord18+12, argumentWord6+12);
                    argumentWord4 = privateRecord17 + 0x14;
                    if (Actor22_856CCCall4EF74View1(argumentWord4, retainedAngleOrAddress16, argumentWord4) != 0) {
                        Actor22_856CCField(privateRecord17, int *, 0x14) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x14) * 6) >> 3);
                        Actor22_856CCField(privateRecord17, int *, 0x18) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x18) * 6) >> 3);
                        Actor22_856CCField(privateRecord17, int *, 0x1C) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x1C) * 6) >> 3);
                        argumentWord4 = privateRecord17 + 0x20;
                        rawWord2 = Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short*, 0x2A));
                        argumentWord4 = privateRecord17+32;
                        if (rawWord2) goto callState2CountdownHelper;
                        {
                            __asm__ __volatile__("":::"$2");
                            rawWord2 = Actor22_856CCCall3BABCView1(ownerRecord18, 4, 0);
                            Actor22_856CCField(privateRecord17, short*, 0x2A) = rawWord2;
                            rawWord2 = (unsigned int)rawWord2 << 16;
                            argumentWord4 = rawWord2 >> 16;
                            if (argumentWord4 >= 0) {
                                rawWord2 = Actor22_856CCField(privateRecord17, int *, 0x1C);
                                if (rawWord2 < 0) {
                                    rawWord2 = -rawWord2;
                                }
                                Actor22_856CCCall3C140View1(argumentWord4, rawWord2*40);
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
            callState2CountdownHelper:if (Actor22_856CCCall359A4View1(argumentWord4, 2)) goto storeState3AndReturn;
            rawWord2 = Actor22_856CCField(privateRecord17, short*, 0x26);
            rawWord2 = rawWord2 < 31;
            if (rawWord2) goto probeState2SurfaceSources;
            storeState3AndReturn:rawWord2 = 3;
            Actor22_856CCField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
            return;
            probeState2SurfaceSources:{
                if (Actor22_856CCCall19194View1(&originalFrame.sp38, 0x96) == 0) {
                    if (Actor22_856CCCall19194View1(&originalFrame.sp48, 0x96) != 0) {
                        secondaryResult20 = 1;
                        goto handleSurfaceResult;
                    }
                    if (Actor22_856CCCall18368View1(&originalFrame.sp28, ownerRecord18 + 0xC) != 0) {
                        goto handleSurfaceResult;
                    }
                }
                else {
                handleSurfaceResult:
                    rawWord2 = Actor22_856CCField(privateRecord17, unsigned short*, 0x26);
                    rawWord2 += 1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    Actor22_856CCField(privateRecord17, unsigned short*, 0x26) = rawWord2;
                    if (secondaryResult20 != 0) {
                        rawWord2 = -0xC;
                    }
                    else{
                        __asm__ __volatile__("":::"$2");
                        rawWord2 = 12;
                    }
                    Actor22_856CCField(privateRecord17, short *, 0x24) = rawWord2;
                    argumentWord4 = privateRecord17 + 0x14;
                    if (Actor22_856CCCall4EF74View1(argumentWord4, &Actor22_856CCData71918View1, argumentWord4) != 0) {
                        Actor22_856CCField(privateRecord17, int *, 0x14) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x14) * 6) >> 3);
                        Actor22_856CCField(privateRecord17, int *, 0x18) = (int) ((int) (Actor22_856CCField(privateRecord17, int *, 0x18) * 6) >> 3);
                        Actor22_856CCField(privateRecord17, int *, 0x1C) = (int) (((int) (Actor22_856CCField(privateRecord17, int *, 0x1C) * 6) >> 3) + 0x14);
                        if (Actor22_856CCCall3BFC0View1(ownerRecord18, Actor22_856CCField(privateRecord17, short *, 0x2A)) == 0) {
                            rawWord2 = Actor22_856CCCall3BABCView1(ownerRecord18, 4, 0);
                            Actor22_856CCField(privateRecord17, short*, 0x2A) = rawWord2;
                            rawWord2 = (unsigned int)rawWord2 << 16;
                            argumentWord4 = rawWord2 >> 16;
                            if (argumentWord4 >= 0) {
                                rawWord2 = Actor22_856CCField(privateRecord17, int *, 0x1C);
                                if (rawWord2 < 0) {
                                    rawWord2 = -rawWord2;
                                }
                                Actor22_856CCCall3C140View1(argumentWord4, rawWord2*40);
                            }
                        }
                    }
                }
                argumentWord4 = retainedHookArgument21;
                goto prepareHookArgument5;
            }
        }
    }
    return;
    prepareHookArgument4:argumentWord4 = retainedHookArgument21;
    prepareHookArgument5:argumentWord5 = privateRecord17+0x64;
    callSharedHook:Actor22_856CCData7443CView1(argumentWord4, argumentWord5, 0);
}
#undef Actor22_856CCField


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
void func_level_22_80086534(void *input) {
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


int func_80039714(Moby*);
int func_8003BB10(Moby*, int, int);
void func_level_22_80087688(Moby* moby) {
    func_80039714(moby);
    if (moby->mobyClass == 0x239) func_8003BB10(moby, 9, 0);
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800876CC.
 * Original instructions: sibling4706.func_level_22_800876CC.json.
 * Native identity pending; units, helper contracts and cadence unresolved. */
#define B22Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int B22H38F14() __asm__("func_80038F14");
int B22H36A68() __asm__("func_80036A68");
int B22H55D24() __asm__("func_80055D24");
int B22H359A4() __asm__("func_800359A4");
int B22H4F334() __asm__("func_8004F334");
int B22H34F40() __asm__("func_80034F40");
int B22H3573C() __asm__("func_8003573C");
int B22H35A80() __asm__("func_80035A80");
int B22H4E880() __asm__("func_8004E880");
int B22H4F264() __asm__("func_8004F264");
int B22H37168() __asm__("func_80037168");
int B22H55E84() __asm__("func_80055E84");
int B22H35194() __asm__("func_80035194");
int B22H3BA00() __asm__("func_8003BA00");
int B22H369B8() __asm__("func_800369B8");
int B22H55B18() __asm__("func_80055B18");
int B22H35D38() __asm__("func_80035D38");
int B22H56270() __asm__("func_80056270");
int B22H13E38() __asm__("func_80013E38");
int B22H13ACC() __asm__("func_80013ACC");
extern unsigned char* B22SharedOwner __asm__("D_8006E164");
extern int B22SharedGate __asm__("D_8006E160");
int B22Rand() __asm__("rand");
extern unsigned char B22Player[] __asm__("D_80070328");
extern unsigned char B22Coordinates[] __asm__("D_8006E020");
extern short B22Heading __asm__("D_8006E040");
extern unsigned char* B22Pool __asm__("D_8006C550");
extern int B22Contact __asm__("D_8006C770");
void func_level_22_800876CC(void* input){
 register unsigned char* owner __asm__("$17")=input;
 register unsigned char* tag __asm__("$18");
 int temporary16;
 register int distance19 __asm__("$19");
 register int flag19 __asm__("$19");
 register int distance20 __asm__("$20");
 register int height21 __asm__("$21");
 register int* position16 __asm__("$16");
 register int height20 __asm__("$20");
 register unsigned char* player21 __asm__("$21");
 register void* call4 __asm__("$4");
 register int arg5 __asm__("$5");
 register int arg6 __asm__("$6");
 register int arg7 __asm__("$7");
 register int value __asm__("$2");
 register int other __asm__("$3");
 register int playerZ __asm__("$8");
 int state;
 __asm__("" : "=r"(owner):"0"(owner));__asm__("" ::: "$19");other=0x10000;value=B22Field(owner,int*,24);tag=B22Field(owner,unsigned char**,0);value&=other;
 flag19=1;if(value && owner[72]!=7){
  if(B22Field(tag,int*,40)==2){other=(int)&B22SharedOwner;value=*(int*)other;if((void*)value==owner){B22SharedGate=0;*(int*)other=0;}}
  B22H38F14(owner,tag,1,7);owner[72]=7;B22H36A68(owner,0,0,0);
 }
 call4=owner;arg5=4;B22Field(owner,int*,24)=0;B22H55D24(call4,arg5);
 B22H359A4(tag+34,2);
 other=B22Field(tag,int*,40);
 if(other==2){value=B22H4E880(B22Field(B22Player,int*,0)-B22Field(owner,int*,12),B22Field(B22Player,int*,4)-B22Field(owner,int*,16),0);value=B22H4F264(B22Field(tag,int*,84),value);flag19=value<64;}
 other=owner[72];
 state=other;switch(state){
 case 0:
  value=B22H4F334(owner+12,B22Player);other=B22Field(tag,int*,36);temporary16=value;
  if(!other){call4=owner;arg5=6;__asm__("" : "=r"(arg5):"0"(arg5));__asm__("" : "=r"(arg6):"0"(0));B22H3573C(call4,arg5,arg6,1);if(!B22Field(tag,int*,36))goto near0;}
  value=B22Field(tag,int*,24)+2048;if(temporary16>=value)goto near0;
  owner[72]=1;B22H34F40(owner,1);break;
 near0:
  value=temporary16<B22Field(tag,int*,24);if(!value)goto done;
  owner[72]=2;B22H34F40(owner,2);break;
 case 1:
  value=B22H35A80(owner,B22Field(tag,int*,36),256,150,0,8,64,4);
  call4=owner;if(value&2){arg5=0;B22Field(tag,int*,36)=0;owner[72]=0;B22H34F40(call4,arg5);}
  B22H35D38(owner);B22H56270(owner);break;
 case 2:
  B22H3573C(owner,6,0,1);if(!B22Contact)goto done;value=3;goto enter4_ready;
 case 3:
  call4=owner+12;position16=(int*)(B22Player+8);other=*position16;value=B22Field(owner,int*,20);arg5=(int)position16-8;
  height21=other-value;value=B22H4F334(call4,(void*)arg5);distance20=value;
  other=B22Field(tag,int*,40);call4=owner;if(other!=2)goto movement_ready;
  other=B22Field(tag,int*,48);value=other*11;__asm__("" : "=r"(value):"0"(value));other=(int)B22Pool;value<<=3;value+=other;
  value=((unsigned char*)value)[72]&128;if(!value || !flag19)goto clear3;
  other=B22Field(owner,short*,56);value=B22Field(owner,int*,20);arg5=*position16;other=value-other;value=other-arg5;
  if(value>=0){if(value<3072)goto query3;goto clear3;}value=arg5-other;if(value>=3072)goto clear3;
 query3:
  value=B22H13E38(owner+12,B22Player,0);call4=owner;if(!value)goto clear3;
  B22H13ACC(call4,12);call4=owner;goto movement_ready;
 clear3:
  other=(int)&B22SharedOwner;value=*(int*)other;if((void*)value==owner){B22SharedGate=0;*(int*)other=0;}
  call4=owner;
 movement_ready:
  B22H3573C(call4,6,0,1);
  if(distance20>=B22Field(tag,int*,28))goto retreat4;
  if(!flag19)goto retreat4;
  if(B22Field(tag,short*,34))goto retreat4;
  value=height21+767;value=(unsigned)value<3327;if(!value)goto retreat4;
  if(B22Field(B22Player,int*,576))goto retreat4;
  if((unsigned)(B22Field(B22Player,int*,80)-7)<2)goto retreat4;
  value=B22H4E880(B22Field(owner,int*,12)-B22Field(B22Coordinates,int*,0),B22Field(owner,int*,16)-B22Field(B22Coordinates,int*,4),0);
  value=B22H4F264(B22Heading>>4,value);if(value>=28)goto retreat4;
  other=B22Field(tag,int*,40);value=4;if(other!=3)goto enter_attack;
  other=B22Field(tag,int*,48);value=other*11;__asm__("" : "=r"(value):"0"(value));other=(int)B22Pool;value<<=3;arg5=value+other;
  value=((unsigned char*)arg5)[72]&128;if(value)goto enter_attack;
  value=B22H4F334(owner+12,(unsigned char*)arg5+12);if(value<=5120)goto done;
 enter_attack:
  owner[72]=4;B22H34F40(owner,4);break;
 retreat4:
  if(distance20<=B22Field(tag,int*,24)+512)goto done;
  if(B22Field(tag,int*,40)==2){other=(int)&B22SharedOwner;value=*(int*)other;if((void*)value==owner){B22SharedGate=0;*(int*)other=0;}}
  owner[72]=5;B22H34F40(owner,5);break;
 case 5:case 6:
  B22H3573C(owner,6,0,1);if(!B22Contact)goto done;owner[72]=0;goto reset_ready;
 case 4:
  value=B22H55E84(owner);call4=owner+12;player21=B22Player;arg5=(int)player21;__asm__("" : "=r"(arg5):"0"(arg5));
  temporary16=value;value=B22H4F334(call4,(void*)arg5);
  call4=owner;arg5=6;arg6=0;arg7=1;__asm__("" : "=r"(call4),"=r"(arg5),"=r"(arg6),"=r"(arg7):"0"(call4),"1"(arg5),"2"(arg6),"3"(arg7));
  playerZ=B22Field(B22Player,int*,8);__asm__("" : "=r"(playerZ):"0"(playerZ));other=B22Field(owner,int*,20);__asm__("" : "=r"(other):"0"(other));distance19=value;
  height20=playerZ-other;B22H3573C(call4,arg5,arg6,arg7);__asm__("" : "=r"(temporary16):"0"(temporary16));
  temporary16=(unsigned)(temporary16-9)<3;
  value=distance19<3584;if(!temporary16 || !value)goto contact5;
  other=B22Field(B22Player,int*,68);
  value=other+1536;if(height20>=value)goto contact5;value=-other;value=value<height20;if(!value)goto contact5;
  if(B22Field(B22Player,int*,576))goto contact5;
  value=B22H4E880(B22Field(player21,int*,0)-B22Field(owner,int*,12),B22Field(B22Player,int*,4)-B22Field(owner,int*,16),0);
  value=B22H4F264(owner[70],value);if(value>=32)goto contact5;
  B22Field(B22Player,int*,36)|=0x16;
  owner[73]=1;
 contact5:
  if(!B22Contact)goto done;
  temporary16=B22H4F334(owner+12,B22Player)-5120;other=B22Field(tag,unsigned short*,32);
  value=temporary16<21;B22Field(tag,unsigned short*,34)=other;if(value)goto reset5;
  other=temporary16/20;temporary16=other;if(temporary16>=121)temporary16=120;
  other=B22Rand()%temporary16;value=B22Field(tag,unsigned short*,34);B22Field(tag,unsigned short*,34)=value+other;
 reset5:
  value=owner[73];if(!value)goto distance5;
  if(B22Field(tag,int*,40)==2){other=(int)&B22SharedOwner;value=*(int*)other;if((void*)value==owner){B22SharedGate=0;*(int*)other=0;}}
  call4=owner;
  arg5=6;__asm__("" : "=r"(arg5):"0"(arg5));value=6;((unsigned char*)call4)[73]=0;((unsigned char*)call4)[72]=value;B22H34F40(call4,arg5);break;
 distance5:
  value=B22Field(tag,int*,24)+256;if(temporary16>=value)goto reset0;
  value=3;
 enter4_ready:
  owner[72]=value;B22H34F40(owner,3);break;
 reset0:
  if(B22Field(tag,int*,40)==2){other=(int)&B22SharedOwner;value=*(int*)other;if((void*)value==owner){B22SharedGate=0;*(int*)other=0;}}
  owner[72]=0;
 reset_ready:
  B22H34F40(owner,0);break;
 case 7:
  value=B22H35194(owner,tag);call4=owner;if(value!=256)goto done;
  B22H55D24(call4,4);B22H3BA00(owner);B22H369B8(owner,36);B22H55B18(owner);break;
 }
 done:;
}
#undef B22Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80087EEC.
* AI generated; not human reviewed. All1811 original instructions,46 switch
* selectors,two zero pads and every actual destination must match:1859 words.
* FrameB0hex=176 bytes saves S0..S7/RA;SP18..87 retains original local storage.
* Both23-way dispatches retain original physical case order and entries.
* The original first distance result remains inV0 until the second call's
* arguments are prepared;S1 then changes from position to retained distance
* in that call's delay slot. The saved heading and its absolute word occupy
* distinct whole-value phases. Negative-path identities preserve V0=-V0
* after the sign decision;the copies retain their original delay slots.
* Original858 skips load866 and enters867 with full height V0 from854.
* The later reload is volatile only on its original path. OriginalJ824 enters
* JAL1797 with the complete A0 already produced821;other paths produce1796.
* Six global E164 address/load/conditional-clear chains retain full pointers
* through their stores. Four height clamps,all signed LH/SH ramps and full
* SLL16/SRA20 angle conversions preserve original widths and ordering.
* Three3585C calls have all six complete original arguments. The player
* base/height,vector delta,timer,state and spawn-private phases remain
* independent. Full spawn-vector Z preserves both signed height paths.
* Empty metadata consumes complete initialized values or written fields,
* or clobbers dead values before fresh producers;zero CPU instructions.
* No opcode asm,partial HI/LO,fixed FP,undefined incoming saved input or
* overlapping live fixed aliases. Compiler/filter/flags remain unchanged.
* Confidence is binary identity after all gates. Units/fixed point,complete
* helper/caller chains,cadence beyond invocation,Rev1 mapping and synchronized
* runtime remain open. Next:human review and retail captures. Every native/
* linked word,actual destination,owned selector/pad and full EXE/every-overlay
* retail hash must remain identical.
*/
/* Original assembly SHA256 6a90863c632548529b0ad987fe3c02c57a8808790e92574555706f6ca0ea14ac */
#define Level22_87EECField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level22_87EECCall1A358View1() __asm__("func_8001A358");
int Level22_87EECCall34F40View1() __asm__("func_80034F40");
int Level22_87EECCall34F80View1() __asm__("func_80034F80");
int Level22_87EECCall35194View1() __asm__("func_80035194");
int Level22_87EECCall35734View1() __asm__("func_80035734");
int Level22_87EECCall3573CView1() __asm__("func_8003573C");
int Level22_87EECCall3585CView1() __asm__("func_8003585C");
int Level22_87EECCall359A4View1(void*, int) __asm__("func_800359A4");
int Level22_87EECCall35D38View1() __asm__("func_80035D38");
int Level22_87EECCall35DDCView1() __asm__("func_80035DDC");
int Level22_87EECCall35EE0View1() __asm__("func_80035EE0");
int Level22_87EECCall369B8View1() __asm__("func_800369B8");
int Level22_87EECCall36A68View1() __asm__("func_80036A68");
int Level22_87EECCall38BF8View1() __asm__("func_80038BF8");
int Level22_87EECCall3BA00View1() __asm__("func_8003BA00");
int Level22_87EECCall3BABCView1() __asm__("func_8003BABC");
int Level22_87EECCall4E880View1(int, int, int) __asm__("func_8004E880");
int Level22_87EECCall4EDE8View1() __asm__("func_8004EDE8");
int Level22_87EECCall4F08CView1() __asm__("func_8004F08C");
int Level22_87EECCall4F110View1() __asm__("func_8004F110");
int Level22_87EECCall4F168View1() __asm__("func_8004F168");
int Level22_87EECCall4F178View1() __asm__("func_8004F178");
int Level22_87EECCall4F194View1() __asm__("func_8004F194");
int Level22_87EECCall4F1C8View1() __asm__("func_8004F1C8");
int Level22_87EECCall4F264View1(int, int) __asm__("func_8004F264");
int Level22_87EECCall4F2ECView1() __asm__("func_8004F2EC");
int Level22_87EECCall4F334View1() __asm__("func_8004F334");
int Level22_87EECCall55B18View1() __asm__("func_80055B18");
int Level22_87EECCall55D24View1() __asm__("func_80055D24");
int Level22_87EECCall55E84View1() __asm__("func_80055E84");
int Level22_87EECCall55F14View1() __asm__("func_80055F14");
extern int Level22_87EECData66EAEView1 __asm__("D_80066EAE");
extern int Level22_87EECData6C54CView1 __asm__("D_8006C54C");
extern int Level22_87EECData6C648View1 __asm__("D_8006C648");
extern int Level22_87EECData6C770View1 __asm__("D_8006C770");
extern int Level22_87EECData6C774View1 __asm__("D_8006C774");
extern int Level22_87EECData6E020View1 __asm__("D_8006E020");
extern int Level22_87EECData6E024View1 __asm__("D_8006E024");
extern unsigned short Level22_87EECData6E040View1 __asm__("D_8006E040");
extern int Level22_87EECData6E160View1 __asm__("D_8006E160");
extern int Level22_87EECData6E164View1 __asm__("D_8006E164");
extern int Level22_87EECData70300View1 __asm__("D_80070300");
extern int Level22_87EECData70328View1 __asm__("D_80070328");
extern int Level22_87EECData9B090View1 __asm__("D_level_22_8009B090");
extern void*(*Level22_87EECDataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern int(*Level22_87EECData743ECView1)() __asm__("unk_ovlheader_800743EC");
extern int(*Level22_87EECData74414View1)() __asm__("unk_ovlheader_80074414");
extern unsigned char Level22_87EECData70300View2 __asm__("D_80070300 + 6");
extern int Level22_87EECData70328View2 __asm__("D_80070328 + 8");
void func_level_22_80087EEC(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    register void *ownerRecord20 __asm__("$20");
    register int privateRecord21 __asm__("$21"), retainedPlayerBaseHeadingDistanceOrVector16 __asm__("$16"), retainedOwnerPositionDistanceHeadingOrVector17 __asm__("$17"), retainedHeaderResult18 __asm__("$18"), retainedSpawnPrivateOrDistance19 __asm__("$19"), retainedDistanceSpawnOrPrivate22 __asm__("$22"), retainedTimerResult23 __asm__("$23");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84;
    }
    originalFrame;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord12;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord19;
    int temporaryWord20;
    int temporaryWord21;
    int temporaryWord4;
    int temporaryWord7;
    int temporaryWord10;
    int temporaryWord11;
    int temporaryWord13;
    int temporaryWord14;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord23;
    int temporaryWord3;
    int temporaryWord8;
    int temporaryWord9;
    int temporaryWord22;
    ownerRecord20 = ownerParameter;
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    privateRecord21 = Level22_87EECField(ownerRecord20, void **, 0);
    if ((Level22_87EECData6C54CView1 - 1) != (int)&Level22_87EECData9B090View1) {
        goto block_3;
    }
    if (Level22_87EECData6C774View1 == 0) {
        goto block_3;
    }
    rawWord2 = Level22_87EECData70300View2;
    Level22_87EECField((int)&Level22_87EECData66EAEView1, short*, 8) = 0;
    rawWord2 &= 254;
    Level22_87EECData70300View2 = rawWord2;
block_3:
    if (Level22_87EECField(privateRecord21, short *, 0x2A) != 2) {
        goto block_107;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0x18) == 0) {
        goto block_9;
    }
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x48) == 0x16) {
        goto block_9;
    }
    Level22_87EECCall3BABCView1(ownerRecord20, 0, 0);
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x3D) == 4) {
        goto block_8;
    }
    Level22_87EECData6C770View1 = 0;
    Level22_87EECField(ownerRecord20, signed char *, 0x40) = 0x72;
    Level22_87EECField(ownerRecord20, unsigned char *, 0x3D) = 4U;
    Level22_87EECField(ownerRecord20, signed char *, 0x3F) = 0;
    Level22_87EECCall35734View1(ownerRecord20);
block_8:
    rawWord2 = 0x16;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
block_9:
    Level22_87EECField(ownerRecord20, int *, 0x18) = 0;
    Level22_87EECCall359A4View1(privateRecord21 + 0x26, 2);
    temporaryWord14 = Level22_87EECField(ownerRecord20, unsigned char *, 0x48);
    Level22_87EECField(ownerRecord20, signed char *, 0x4F) = (signed char) ((unsigned short) Level22_87EECField(privateRecord21, unsigned short *, 0x28) >> 2);
    if (temporaryWord14 >= 0x17U) {
        goto returnOriginal1799;
    }
    switch (temporaryWord14){
    case 0:goto originalFirstState0;
    case 4:goto originalFirstState4;
    case 21:goto originalFirstState21;
    case 5:goto originalFirstState5;
    case 22:goto originalFirstState22;
        default:return;
    }
originalFirstState0:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x4C) = 0x7FU;
    retainedPlayerBaseHeadingDistanceOrVector16 = ownerRecord20 + 0xC;
    Level22_87EECCall4F178View1(retainedPlayerBaseHeadingDistanceOrVector16, Level22_87EECField(Level22_87EECField(privateRecord21, void **, 0x48), void **, 0xC));
    Level22_87EECField(Level22_87EECField(privateRecord21, void **, 0x48), short *, 2) = 1;
    Level22_87EECField(Level22_87EECField(privateRecord21, void **, 0x48), short *, 0xA) = 1;
    Level22_87EECField(ownerRecord20, unsigned char*, 82) = 254;
    Level22_87EECCall55D24View1(ownerRecord20, 2);
    temporaryWord1 = Level22_87EECField(Level22_87EECField(privateRecord21, void **, 0x48), void **, 0xC);
    Level22_87EECField(ownerRecord20, unsigned char *, 0x46) = Level22_87EECCall4E880View1(Level22_87EECField(temporaryWord1, int *, 0x10) - Level22_87EECField(ownerRecord20, int *, 0xC), Level22_87EECField(temporaryWord1, int *, 0x14) - Level22_87EECField(ownerRecord20, int *, 0x10), 0);
    Level22_87EECField(ownerRecord20, unsigned char *, 0x45) = Level22_87EECCall4E880View1(Level22_87EECCall4F334View1(retainedPlayerBaseHeadingDistanceOrVector16, Level22_87EECField(Level22_87EECField(privateRecord21, void **, 0x48), void **, 0xC) + 0x10), Level22_87EECField(Level22_87EECField(Level22_87EECField(privateRecord21, void **, 0x48), void **, 0xC), int *, 0x18) - Level22_87EECField(ownerRecord20, int *, 0x14), 0);
    Level22_87EECCall34F80View1(ownerRecord20, 4);
    Level22_87EECField(privateRecord21, int *, 0x20) = 0;
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 0U;
    Level22_87EECField(privateRecord21, unsigned short *, 0x28) = 0x80U;
    Level22_87EECField(ownerRecord20, signed char *, 0x4F) = 0x20;
    Level22_87EECCall4F168View1(privateRecord21 + 0x2C);
    argumentWord4 = 0x7fffffff;
    rawWord2 = Level22_87EECField(ownerRecord20, int*, 28);
    rawWord3 = 4;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord3;
    rawWord2 &= argumentWord4;
    Level22_87EECField(ownerRecord20, int*, 28) = rawWord2;
    return;
originalFirstState4:
    rawWord3 = Level22_87EECField(ownerRecord20, unsigned char*, 73);
    rawWord2 = 1;
    if (rawWord3 == rawWord2) {
        goto readOriginalPairedDistance198;
    }
    rawWord2 = (int)rawWord3 < 2;
    if (!rawWord2) {
        goto block_16;
    }
    if (rawWord3 == 0) {
        goto readOriginalFirstDistance166;
    }
    return;
block_16:
    retainedOwnerPositionDistanceHeadingOrVector17 = (int)ownerRecord20+12;
    if (rawWord3 == 2) {
        goto readOriginalReturnDistance308;
    }
    return;
    readOriginalFirstDistance166:__asm__("":"=r"(rawWord3):"0"(rawWord3));
    Level22_87EECData743ECView1(ownerRecord20, Level22_87EECField(privateRecord21, void**, 72), privateRecord21+44, privateRecord21+32, 64, 0);
    if (Level22_87EECCall4F334View1((int)ownerRecord20+12, (int)&Level22_87EECData70328View1) >= Level22_87EECField(privateRecord21, int*, 24)) goto returnOriginal1799;
    rawWord3 = Level22_87EECField(ownerRecord20, short*, 56);
    rawWord2 = Level22_87EECField(ownerRecord20, int*, 20);
    argumentWord4 = Level22_87EECData70328View2;
    rawWord3 = rawWord2-rawWord3;
    rawWord2 = rawWord3-argumentWord4;
    if (rawWord2 < 0) goto checkOriginalNegativeHeight185;
    rawWord2 = rawWord2 < 3072;
    __asm__ volatile("":"=r"(rawWord2):"0"(rawWord2));
    if (!rawWord2) goto returnOriginal1799;
    __asm__ volatile(""::"r"(rawWord3));
    goto writeOriginalHeightSnapshot189;
    checkOriginalNegativeHeight185:__asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4));
    rawWord2 = argumentWord4-rawWord3;
    rawWord2 = rawWord2 < 3072;
    if (!rawWord2) goto returnOriginal1799;
writeOriginalHeightSnapshot189:
    Level22_87EECField(privateRecord21, short *, 0x3E) = (short) Level22_87EECField(ownerRecord20, unsigned char *, 0x45);
    Level22_87EECField(privateRecord21, short *, 0x3C) = (short) Level22_87EECField(ownerRecord20, unsigned char *, 0x46);
    Level22_87EECField(privateRecord21, int *, 0x40) = (int) Level22_87EECField(ownerRecord20, int *, 0x14);
    goto block_76;
    readOriginalPairedDistance198:retainedOwnerPositionDistanceHeadingOrVector17 = (int)ownerRecord20+12;
    rawWord2 = Level22_87EECCall4F334View1(retainedOwnerPositionDistanceHeadingOrVector17, (int)&Level22_87EECData70328View1);
    argumentWord4 = retainedOwnerPositionDistanceHeadingOrVector17;
    argumentWord5 = (int)&Level22_87EECData70328View1;
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5));
    retainedOwnerPositionDistanceHeadingOrVector17 = rawWord2;
    rawWord2 = Level22_87EECCall4F334View1(argumentWord4, argumentWord5);
    retainedPlayerBaseHeadingDistanceOrVector16 = Level22_87EECCall4E880View1(rawWord2, Level22_87EECField((int)&Level22_87EECData70328View1, int*, 8)-Level22_87EECField(ownerRecord20, int*, 20), 0);
    __asm__("":"=r"(retainedPlayerBaseHeadingDistanceOrVector16):"0"(retainedPlayerBaseHeadingDistanceOrVector16));
    if (retainedPlayerBaseHeadingDistanceOrVector16 >= 0){
        rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16;
        goto testOriginalAbsoluteHeading219;
    }
    rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    rawWord2 = -rawWord2;
testOriginalAbsoluteHeading219:
    if (rawWord2 >= 32) {
        goto block_30;
    }
    temporaryWord11 = Level22_87EECCall4F2ECView1(retainedPlayerBaseHeadingDistanceOrVector16, Level22_87EECField(ownerRecord20, unsigned char *, 0x45), 3, 3);
    if (temporaryWord11 == Level22_87EECField(ownerRecord20, unsigned char *, 0x45)) {
        goto block_29;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x45) = temporaryWord11;
    goto block_30;
block_29:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x45) = (unsigned char) retainedPlayerBaseHeadingDistanceOrVector16;
    block_30:rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    rawWord2 = Level22_87EECField(privateRecord21, int*, 64);
    if (rawWord3 >= rawWord2) goto block_33;
    rawWord2 = rawWord3+10;
    Level22_87EECField(ownerRecord20, int*, 20) = rawWord2;
    rawWord3 = Level22_87EECField(privateRecord21, int*, 64);
    if (rawWord3 >= rawWord2) goto block_33;
    Level22_87EECField(ownerRecord20, int*, 20) = rawWord3;
block_33:
block_34:
    Level22_87EECCall3573CView1(ownerRecord20, 3, 0, 1);
    if ((rawWord2 = Level22_87EECField(privateRecord21, int*, 24)+1024, rawWord2 = rawWord2 < retainedOwnerPositionDistanceHeadingOrVector17, rawWord2 != 0)) {
        goto block_39;
    }
    temporaryWord21 = Level22_87EECField(ownerRecord20, int *, 0x14) - Level22_87EECField(ownerRecord20, short *, 0x38);
    temporaryWord12 = temporaryWord21 - Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8);
    if (temporaryWord12 < 0) {
        goto block_38;
    }
    if (temporaryWord12 >= 0xE01) {
        goto block_39;
    }
    goto block_40;
block_38:
    if ((Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8) - temporaryWord21) < 0xE01) {
        goto block_40;
    }
block_39:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 2U;
    return;
block_40:
    if ((rawWord2 = Level22_87EECField(privateRecord21, int*, 28), rawWord2 = retainedOwnerPositionDistanceHeadingOrVector17 < rawWord2, rawWord2 == 0)) {
        goto returnOriginal1799;
    }
    if (Level22_87EECField(privateRecord21, short *, 0x26) != 0) {
        goto returnOriginal1799;
    }
    if ((unsigned int) (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x50) - 7) < 2U) {
        goto returnOriginal1799;
    }
    rawWord2 = Level22_87EECCall4F264View1(Level22_87EECField(ownerRecord20, unsigned char *, 0x46), Level22_87EECCall4E880View1(Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0) - Level22_87EECField(ownerRecord20, int *, 0xC), Level22_87EECField((int)&Level22_87EECData70328View1, int *, 4) - Level22_87EECField(ownerRecord20, int *, 0x10), 0));
    argumentWord4 = (int)ownerRecord20;
    if (rawWord2 >= 8) {
        goto returnOriginal1799;
    }
    argumentWord5 = 5;
    goto prepareOriginalStateFive1281;
    readOriginalReturnDistance308:argumentWord4 = retainedOwnerPositionDistanceHeadingOrVector17;
    retainedPlayerBaseHeadingDistanceOrVector16 = (int)&Level22_87EECData70328View1;
    rawWord2 = Level22_87EECCall4F334View1(argumentWord4, retainedPlayerBaseHeadingDistanceOrVector16);
    argumentWord4 = Level22_87EECField(ownerRecord20, short*, 56);
    rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    __asm__("":"=r"(retainedPlayerBaseHeadingDistanceOrVector16):"0"(retainedPlayerBaseHeadingDistanceOrVector16));
    argumentWord5 = Level22_87EECField(retainedPlayerBaseHeadingDistanceOrVector16, int*, 8);
    rawWord3 -= argumentWord4;
    argumentWord4 = rawWord3-argumentWord5;
    argumentWord6 = rawWord2;
    if (argumentWord4 >= 0) goto updateStatusHandle;
    argumentWord4 = argumentWord5-rawWord3;
    updateStatusHandle:rawWord2 = Level22_87EECField(privateRecord21, int*, 24);
    rawWord2 = rawWord2 < argumentWord6;
    if (rawWord2) goto restoreOriginalPitch328;
    rawWord2 = argumentWord4 < 3073;
    if (rawWord2){
        argumentWord4 = retainedOwnerPositionDistanceHeadingOrVector17;
        goto readOriginalPairedHeading348;
    }
    argumentWord4 = retainedOwnerPositionDistanceHeadingOrVector17;
restoreOriginalPitch328:
    rawWord2 = Level22_87EECCall4F2ECView1(Level22_87EECField(privateRecord21, short *, 0x3E), Level22_87EECField(ownerRecord20, unsigned char *, 0x45), 4, 4);
    if (rawWord2 != Level22_87EECField(ownerRecord20, unsigned char *, 0x45)) {
        goto writeOriginalPitch339;
    }
    rawWord2 = Level22_87EECField(privateRecord21, unsigned short*, 62);
writeOriginalPitch339:
    Level22_87EECField(ownerRecord20, unsigned char*, 69) = rawWord2;
    __asm__ volatile(""::"m"(Level22_87EECField(ownerRecord20, unsigned char*, 69)):"memory");
    argumentWord4 = (int)ownerRecord20;
    argumentWord6 = 4;
    argumentWord7 = 0;
    argumentWord5 = Level22_87EECField(privateRecord21, short*, 60);
    __asm__ volatile(""::"r"(argumentWord5));
    rawWord2 = 1;
    Level22_87EECCall3585CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7, rawWord2, 0);
    goto decreaseOriginalHalfword392;
    readOriginalPairedHeading348:rawWord2 = Level22_87EECCall4F334View1(argumentWord4, retainedPlayerBaseHeadingDistanceOrVector16);
    argumentWord4 = rawWord2;
    rawWord2 = Level22_87EECData70328View2;
    argumentWord5 = Level22_87EECField(ownerRecord20, int*, 20);
    argumentWord6 = 0;
    argumentWord5 = rawWord2-argumentWord5;
    retainedPlayerBaseHeadingDistanceOrVector16 = Level22_87EECCall4E880View1(argumentWord4, argumentWord5, argumentWord6);
    __asm__("":"=r"(retainedPlayerBaseHeadingDistanceOrVector16):"0"(retainedPlayerBaseHeadingDistanceOrVector16));
    if (retainedPlayerBaseHeadingDistanceOrVector16 >= 0){
        rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16;
        goto testOriginalAbsoluteHeading363;
    }
    rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    rawWord2 = -rawWord2;
testOriginalAbsoluteHeading363:
    if (rawWord2 >= 32) {
        goto block_58;
    }
    temporaryWord13 = Level22_87EECCall4F2ECView1(retainedPlayerBaseHeadingDistanceOrVector16, Level22_87EECField(ownerRecord20, unsigned char *, 0x45), 3, 3);
    if (temporaryWord13 == Level22_87EECField(ownerRecord20, unsigned char *, 0x45)) {
        goto block_57;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x45) = temporaryWord13;
    goto block_58;
block_57:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x45) = (unsigned char) retainedPlayerBaseHeadingDistanceOrVector16;
block_58:
    Level22_87EECCall3573CView1(ownerRecord20, 3, 0, 1);
    if ((short) Level22_87EECField(privateRecord21, unsigned short *, 0x28) != 0x80) {
        goto decreaseOriginalHalfword392;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0x14) != Level22_87EECField(privateRecord21, int *, 0x40)) {
        goto decreaseOriginalHalfword392;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 1U;
    decreaseOriginalHalfword392:rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord3 = rawWord2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 < 129){
        rawWord2 = rawWord3-2;
        goto increaseOriginalHeight405;
    }
    rawWord2 = rawWord3-2;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    __asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    rawWord2 = (rawWord2 << 16) >> 16;
    if (rawWord2 >= 128) goto increaseOriginalHeight405;
    rawWord2 = 128;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    increaseOriginalHeight405:rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    rawWord2 = Level22_87EECField(privateRecord21, int*, 64);
    if (rawWord3 >= rawWord2) goto block_67;
    rawWord2 = rawWord3+10;
    Level22_87EECField(ownerRecord20, int*, 20) = rawWord2;
    rawWord3 = Level22_87EECField(privateRecord21, int*, 64);
    if (rawWord3 >= rawWord2) goto block_67;
    Level22_87EECField(ownerRecord20, int*, 20) = rawWord3;
block_67:
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x46) != Level22_87EECField(privateRecord21, short *, 0x3C)) {
        goto returnOriginal1799;
    }
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x45) != Level22_87EECField(privateRecord21, short *, 0x3E)) {
        goto returnOriginal1799;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0x14) != Level22_87EECField(privateRecord21, int *, 0x40)) {
        goto returnOriginal1799;
    }
    if ((short) Level22_87EECField(privateRecord21, unsigned short *, 0x28) != 0x80) {
        goto returnOriginal1799;
    }
    if (Level22_87EECCall4F334View1(ownerRecord20 + 0xC, (int)&Level22_87EECData70328View1) >= Level22_87EECField(privateRecord21, int *, 0x18)) {
        goto clearOriginalSubstate465;
    }
    temporaryWord15 = Level22_87EECField(ownerRecord20, int *, 0x14) - Level22_87EECField(ownerRecord20, short *, 0x38);
    temporaryWord2 = temporaryWord15 - Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8);
    if (temporaryWord2 < 0) {
        goto block_75;
    }
    if (temporaryWord2 < 0xC00) {
        goto block_77;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 0U;
    return;
block_75:
    if ((Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8) - temporaryWord15) >= 0xC00) {
        goto clearOriginalSubstate465;
    }
block_76:
block_77:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 1U;
    return;
    clearOriginalSubstate465:__asm__ volatile(""::"r"(ownerRecord20));
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 0U;
    return;
originalFirstState21:
    temporaryWord16 = Level22_87EECField(ownerRecord20, int *, 0x14);
    if (temporaryWord16 < 0x801) {
        goto increaseOriginalHalfword473;
    }
    Level22_87EECField(ownerRecord20, int *, 0x14) = (int) (temporaryWord16 - 0x3C);
    increaseOriginalHalfword473:rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord3 = rawWord2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 >= 257){
        rawWord2 = rawWord3+8;
        goto returnOriginal1799;
    }
    rawWord2 = rawWord3+8;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    __asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    rawWord2 = (rawWord2 << 16) >> 16;
    if (rawWord2 < 256){
        argumentWord4 = (int)ownerRecord20;
        goto returnOriginal1799;
    }
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 4;
    rawWord2 = 256;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    rawWord2 = 2;
    Level22_87EECField(argumentWord4, unsigned char*, 73) = rawWord2;
    __asm__ volatile(""::"m"(Level22_87EECField(argumentWord4, unsigned char*, 73)):"memory");
    rawWord2 = 4;
    goto callOriginalState1283;
originalFirstState5:
    rawWord2 = Level22_87EECCall55E84View1(ownerRecord20);
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 3;
    argumentWord6 = 0;
    argumentWord7 = 1;
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7));
    retainedPlayerBaseHeadingDistanceOrVector16 = rawWord2;
    Level22_87EECCall3573CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
    if (retainedPlayerBaseHeadingDistanceOrVector16 < 0x11) {
        goto testOriginalPlayerMode594;
    }
    rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord3 = rawWord2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 >= 256) {
        goto testOriginalPlayerMode594;
    }
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x49) != 0) {
        goto block_89;
    }
    temporaryWord3 = Level22_87EECDataSpawnMobyView1(0x1FC, ownerRecord20);
    argumentWord4 = (int)&originalFrame.sp18;
    if (temporaryWord3 == 0) {
        goto testOriginalPlayerMode594;
    }
    argumentWord5 = (int)&Level22_87EECData70328View1;
    __asm__ volatile(""::"r"(argumentWord5));
    retainedSpawnPrivateOrDistance19 = Level22_87EECField(temporaryWord3, int*, 0);
    rawWord2 = 100;
    Level22_87EECField(temporaryWord3, unsigned char*, 79) = rawWord2;
    Level22_87EECCall4F178View1(argumentWord4, argumentWord5);
    Level22_87EECCall55D24View1(ownerRecord20, 4);
    Level22_87EECCall55F14View1(ownerRecord20, 6, &originalFrame.sp28);
    Level22_87EECCall55F14View1(ownerRecord20, 7, &originalFrame.sp38);
    retainedPlayerBaseHeadingDistanceOrVector16 = temporaryWord3 + 0xC;
    Level22_87EECCall4F194View1(retainedPlayerBaseHeadingDistanceOrVector16, &originalFrame.sp28, &originalFrame.sp38);
    Level22_87EECCall4F110View1(retainedPlayerBaseHeadingDistanceOrVector16, 1);
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    argumentWord4 = retainedPlayerBaseHeadingDistanceOrVector16;
    argumentWord5 = retainedPlayerBaseHeadingDistanceOrVector16;
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5));
    retainedOwnerPositionDistanceHeadingOrVector17 = (int)ownerRecord20+12;
    Level22_87EECCall4F1C8View1(argumentWord4, argumentWord5, retainedOwnerPositionDistanceHeadingOrVector17);
    Level22_87EECCall4F08CView1(retainedPlayerBaseHeadingDistanceOrVector16, (short) Level22_87EECField(privateRecord21, unsigned short *, 0x28), 0x80);
    Level22_87EECCall4F194View1(retainedPlayerBaseHeadingDistanceOrVector16, retainedPlayerBaseHeadingDistanceOrVector16, retainedOwnerPositionDistanceHeadingOrVector17);
    Level22_87EECCall4F1C8View1(retainedSpawnPrivateOrDistance19, &originalFrame.sp18, retainedPlayerBaseHeadingDistanceOrVector16);
    Level22_87EECCall4F08CView1(retainedSpawnPrivateOrDistance19, Level22_87EECCall4EDE8View1(retainedSpawnPrivateOrDistance19, 1), 0xB4);
    Level22_87EECField(temporaryWord3, unsigned char *, 0x45) = Level22_87EECCall4E880View1(Level22_87EECCall4EDE8View1(retainedSpawnPrivateOrDistance19, 0), Level22_87EECField(retainedSpawnPrivateOrDistance19, int *, 8), 0);
    Level22_87EECField(temporaryWord3, unsigned char *, 0x46) = (unsigned char) Level22_87EECField(ownerRecord20, unsigned char *, 0x46);
    Level22_87EECField(retainedSpawnPrivateOrDistance19, int *, 0xC) = 0xB4;
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 1U;
    goto testOriginalPlayerMode594;
block_89:
    rawWord2 = rawWord3+2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    Level22_87EECField(ownerRecord20, int *, 0x14) = (int) (Level22_87EECField(ownerRecord20, int *, 0x14) - 0x28);
    testOriginalPlayerMode594:rawWord2 = (unsigned int)(Level22_87EECField((int)&Level22_87EECData70328View1, int*, 80)-7) < 2;
    argumentWord4 = (int)ownerRecord20;
    if (rawWord2) goto writeOriginalStateAndMode618;
    rawWord3 = Level22_87EECField(ownerRecord20, short*, 56);
    rawWord2 = Level22_87EECField(ownerRecord20, int*, 20);
    argumentWord4 = Level22_87EECData70328View2;
    rawWord3 = rawWord2-rawWord3;
    rawWord2 = rawWord3-argumentWord4;
    if (rawWord2 >= 0){
        rawWord2 = rawWord2 < 3585;
        goto block_93;
    }
    rawWord2 = argumentWord4-rawWord3;
    rawWord2 = rawWord2 < 3585;
    block_93:argumentWord4 = (int)ownerRecord20;
    if (!rawWord2) goto writeOriginalStateAndMode618;
    if (!Level22_87EECField((int)&Level22_87EECData70328View1, int*, 576)) goto block_96;
    writeOriginalStateAndMode618:argumentWord5 = 4;
    __asm__ volatile(""::"r"(argumentWord5));
    rawWord2 = 2;
    Level22_87EECField(ownerRecord20, unsigned char*, 73) = rawWord2;
    rawWord2 = 4;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    Level22_87EECCall34F40View1(argumentWord4, argumentWord5);
block_96:
    if (Level22_87EECData6C770View1 == 0) {
        goto returnOriginal1799;
    }
    rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord2 = rawWord2 < 193;
    argumentWord4 = (int)ownerRecord20;
    if (rawWord2) {
        goto prepareOriginalStateFour643;
    }
    argumentWord5 = 4;
    __asm__ volatile(""::"r"(argumentWord5));
    rawWord2 = 300;
    Level22_87EECField(privateRecord21, short*, 38) = rawWord2;
    rawWord2 = 2;
    Level22_87EECField(ownerRecord20, unsigned char*, 73) = rawWord2;
    Level22_87EECCall34F40View1(argumentWord4, argumentWord5);
    rawWord2 = 0x15;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    return;
    prepareOriginalStateFour643:argumentWord5 = 4;
    rawWord2 = 60;
    Level22_87EECField(privateRecord21, short*, 38) = rawWord2;
    rawWord2 = 1;
    Level22_87EECField(argumentWord4, unsigned char*, 73) = rawWord2;
    rawWord2 = 4;
    goto callOriginalState1283;
originalFirstState22:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x44) = (unsigned char) (Level22_87EECField(ownerRecord20, unsigned char *, 0x44) + (Level22_87EECCall55E84View1(ownerRecord20) >> 1));
    Level22_87EECCall35EE0View1(ownerRecord20, (Level22_87EECField(ownerRecord20, unsigned char *, 0x46) + 0x80) & 0xFF, 0x12C, 0x400, 0x400, 0x22);
    temporaryWord4 = Level22_87EECField(privateRecord21, unsigned short *, 0x28) + 8;
    Level22_87EECField(privateRecord21, unsigned short *, 0x28) = temporaryWord4;
    __asm__ volatile("":"=r"(temporaryWord4):"0"(temporaryWord4), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    argumentWord4 = (int)ownerRecord20;
    if ((short)temporaryWord4 >= 513) {
        goto block_104;
    }
    argumentWord5 = 0x10;
    if (Level22_87EECField(ownerRecord20, int *, 0xC) < 0x1000) {
        goto block_105;
    }
    argumentWord6 = 0;
    if (Level22_87EECField(ownerRecord20, int*, 16) < 4096) {
        goto block_106;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0x14) >= 0x1000) {
        goto returnOriginal1799;
    }
block_104:
    argumentWord5 = 0x10;
    block_105:argumentWord6 = 0;
block_106:
    __asm__ volatile(""::"r"(argumentWord4));
    argumentWord7 = 0;
    goto callOriginalRestore1777;
block_107:
    if (Level22_87EECField(ownerRecord20, int *, 0x18) == 0) {
        goto block_121;
    }
    temporaryWord17 = Level22_87EECField(ownerRecord20, unsigned char *, 0x48);
    if (temporaryWord17 == 0x16) {
        goto block_121;
    }
    if (temporaryWord17 == 6) {
        goto block_122;
    }
    rawWord3 = Level22_87EECField(privateRecord21, void ***, 0x44);
    if (Level22_87EECField(rawWord3, int*, 0) != ownerRecord20) {
        goto block_113;
    }
    Level22_87EECField(rawWord3, int*, 0) = 0;
    __asm__ volatile(""::"m"(Level22_87EECField(rawWord3, int*, 0)):"memory");
    rawWord3 = (int)&Level22_87EECData6E164View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    rawWord2 = Level22_87EECField(rawWord3, int*, 0);
    if (rawWord2 != (int)ownerRecord20) goto block_113;
    Level22_87EECData6E160View1 = 0;
    Level22_87EECField(rawWord3, int*, 0) = 0;
block_113:
    temporaryWord18 = Level22_87EECField(ownerRecord20, unsigned char *, 0x48);
    if (temporaryWord18 < 2U) {
        goto block_116;
    }
    if (temporaryWord18 != 2) {
        goto block_117;
    }
block_116:
    Level22_87EECCall38BF8View1(ownerRecord20, privateRecord21, 0, 6);
    temporaryWord23 = 6;
    goto block_120;
block_117:
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x3D) == 4) {
        goto block_119;
    }
    Level22_87EECData6C770View1 = 0;
    Level22_87EECField(ownerRecord20, signed char *, 0x40) = 0x72;
    Level22_87EECField(ownerRecord20, unsigned char *, 0x3D) = 4U;
    Level22_87EECField(ownerRecord20, signed char *, 0x3F) = 0;
    Level22_87EECCall35734View1(ownerRecord20);
block_119:
    temporaryWord23 = 0x16;
block_120:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x48) = temporaryWord23;
block_121:
block_122:
    Level22_87EECField(ownerRecord20, int *, 0x18) = 0;
    Level22_87EECField(ownerRecord20, signed char *, 0x4F) = (signed char) ((unsigned short) Level22_87EECField(privateRecord21, unsigned short *, 0x28) >> 2);
    Level22_87EECCall55D24View1(ownerRecord20, 1);
    retainedHeaderResult18 = Level22_87EECData74414View1(Level22_87EECField(privateRecord21, int *, 0x38), ownerRecord20 + 0xC);
    rawWord3 = Level22_87EECField(ownerRecord20, unsigned char*, 72);
    if (rawWord3 >= 0x17U) {
        goto returnOriginal1799;
    }
    switch (rawWord3){
    case 0:goto originalSecondState0;
    case 1:goto originalSecondState1;
    case 2:goto originalSecondState2;
    case 3:goto originalSecondState3;
    case 4:goto originalSecondState4;
    case 20:goto originalSecondState20;
    case 5:goto originalSecondState5;
    case 6:goto originalSecondState6;
    case 22:goto originalSecondState22;
        default:return;
    }
originalSecondState0:
    rawWord2 = Level22_87EECCall4F334View1(ownerRecord20 + 0xC, (int)&Level22_87EECData70328View1);
    argumentWord4 = (int)ownerRecord20;
    __asm__ volatile(""::"r"(argumentWord4));
    retainedOwnerPositionDistanceHeadingOrVector17 = rawWord2;
    temporaryWord5 = Level22_87EECCall35D38View1(argumentWord4);
    temporaryWord19 = Level22_87EECField(ownerRecord20, int *, 0x14);
    if (temporaryWord5 >= temporaryWord19) {
        goto block_128;
    }
    Level22_87EECField(ownerRecord20, int *, 0x14) = (int) (temporaryWord19 + Level22_87EECField(privateRecord21, short *, 0x24));
    Level22_87EECField(privateRecord21, short *, 0x24) = (short) ((unsigned short) Level22_87EECField(privateRecord21, short *, 0x24) - 0x14);
    if (Level22_87EECField(ownerRecord20, int *, 0x14) >= temporaryWord5) {
        goto block_129;
    }
    Level22_87EECField(ownerRecord20, int *, 0x14) = (int) (temporaryWord5 + 1);
    temporaryWord6 = -Level22_87EECField(privateRecord21, short*, 36) >> 2;
    Level22_87EECField(privateRecord21, short *, 0x24) = (short) temporaryWord6;
    if (temporaryWord6 >= 0x14) {
        goto block_129;
    }
    Level22_87EECField(privateRecord21, short *, 0x24) = 0;
block_128:
    Level22_87EECField(ownerRecord20, int *, 0x14) = temporaryWord5;
block_129:
    if (Level22_87EECField(ownerRecord20, int *, 0x14) >= 0x2000) {
        goto increaseOriginalHalfword826;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = (unsigned char) Level22_87EECField(ownerRecord20, unsigned char *, 0x4C);
    Level22_87EECCall36A68View1(ownerRecord20, 1, 0, privateRecord21 + 0x2C);
    argumentWord4 = (int)ownerRecord20;
    __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
    Level22_87EECField(argumentWord4, unsigned char*, 65) = 0;
    Level22_87EECField(argumentWord4, unsigned char*, 76) = 0;
    Level22_87EECField(argumentWord4, unsigned char*, 77) = 0;
    goto originalHeldOwner1797;
    increaseOriginalHalfword826:rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord3 = rawWord2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 >= 256){
        rawWord2 = rawWord3+8;
        goto block_134;
    }
    rawWord2 = rawWord3+8;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    __asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    rawWord2 = (rawWord2 << 16) >> 16;
    temporaryWord22 = privateRecord21+38;
    if (rawWord2 < 257) goto block_135;
    rawWord2 = 256;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
block_134:
    temporaryWord22 = privateRecord21 + 0x26;
block_135:
    if (Level22_87EECCall359A4View1(temporaryWord22, 2) == 0) {
        goto readOriginalOwnerHeight854;
    }
    if (retainedOwnerPositionDistanceHeadingOrVector17 < Level22_87EECField(privateRecord21, int *, 0x18)) {
        goto block_154;
    }
    if (Level22_87EECField(privateRecord21, short *, 0x2A) == 1) {
        goto block_154;
    }
    readOriginalOwnerHeight854:rawWord2 = Level22_87EECField(ownerRecord20, int*, 20);
    if (rawWord2 != temporaryWord5) goto returnOriginal1799;
    if (retainedHeaderResult18 == 0) goto compareOriginalHeldHeight868;
    rawWord2 = Level22_87EECField(privateRecord21, int*, 24);
    rawWord2 -= 2048;
    rawWord2 = retainedOwnerPositionDistanceHeadingOrVector17 < rawWord2;
    if (rawWord2){
        rawWord2 = 2;
        goto writeOriginalStateTwo914;
    }
    rawWord2 = 2;
    reloadOriginalOwnerHeight866:rawWord2 = Level22_87EECField(ownerRecord20, volatile int*, 20);
    compareOriginalHeldHeight868:if (rawWord2 != temporaryWord5) goto returnOriginal1799;
    if (retainedHeaderResult18 == 0) {
        goto block_158;
    }
    if (Level22_87EECCall4F334View1(ownerRecord20 + 0xC, privateRecord21 + 0x2C) < 0x401) {
        goto returnOriginal1799;
    }
    goto block_159;
    originalSecondState1:argumentWord6 = 0;
    rawWord3 = Level22_87EECField(privateRecord21, int*, 44);
    argumentWord4 = Level22_87EECField(ownerRecord20, int*, 12);
    rawWord2 = Level22_87EECField(privateRecord21, int*, 48);
    argumentWord5 = Level22_87EECField(ownerRecord20, int*, 16);
    argumentWord4 = rawWord3-argumentWord4;
    argumentWord5 = rawWord2-argumentWord5;
    rawWord2 = Level22_87EECCall4E880View1(argumentWord4, argumentWord5, argumentWord6);
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = rawWord2;
    argumentWord6 = 3;
    argumentWord7 = 0;
    rawWord2 = 1;
    __asm__ volatile(""::"r"(rawWord2));
    Level22_87EECCall3585CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7, rawWord2, 0);
    Level22_87EECCall35DDCView1(ownerRecord20, 0x32, 0x200, 0x200, 0x32);
    argumentWord4 = (int)ownerRecord20+12;
    if (retainedHeaderResult18 == 0) {
        goto readOriginalPrivateDistance921;
    }
    __asm__ volatile("":"=r"(ownerRecord20):"0"(ownerRecord20));
    argumentWord4 = (int)ownerRecord20+12;
    if (Level22_87EECCall4F334View1(argumentWord4, (int)&Level22_87EECData70328View1) >= (Level22_87EECField(privateRecord21, int*, 24)-2048)) {
        goto produceOriginalOwnerPosition920;
    }
writeOriginalStateTwo914:
    rawWord2 = 2;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    Level22_87EECCall34F40View1(ownerRecord20, 2);
    return;
produceOriginalOwnerPosition920:
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    argumentWord4 = (int)ownerRecord20+12;
readOriginalPrivateDistance921:
    if (Level22_87EECCall4F334View1(argumentWord4, privateRecord21 + 0x2C) >= 0x200) {
        goto returnOriginal1799;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x48) = 0U;
    goto block_197;
    originalSecondState2:argumentWord4 = (int)ownerRecord20+12;
    retainedPlayerBaseHeadingDistanceOrVector16 = (int)&Level22_87EECData70328View1;
    rawWord2 = Level22_87EECCall4F334View1(argumentWord4, retainedPlayerBaseHeadingDistanceOrVector16);
    argumentWord6 = 0;
    argumentWord4 = Level22_87EECField(retainedPlayerBaseHeadingDistanceOrVector16, int*, 0);
    __asm__ volatile(""::"r"(argumentWord4));
    retainedPlayerBaseHeadingDistanceOrVector16 = rawWord2;
    argumentWord7 = Level22_87EECField(ownerRecord20, int*, 12);
    rawWord3 = Level22_87EECField(ownerRecord20, int*, 16);
    argumentWord5 = Level22_87EECField((int)&Level22_87EECData70328View1, int*, 4);
    argumentWord4 = argumentWord7-argumentWord4;
    argumentWord5 = rawWord3-argumentWord5;
    rawWord2 = Level22_87EECCall4E880View1(argumentWord4, argumentWord5, argumentWord6);
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = rawWord2;
    argumentWord6 = 4;
    argumentWord7 = 0;
    rawWord2 = 1;
    __asm__ volatile(""::"r"(rawWord2));
    Level22_87EECCall3585CView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7, rawWord2, 0);
    Level22_87EECCall35DDCView1(ownerRecord20, 0x4B, 0x200, 0x200, 0x32);
    if (Level22_87EECCall359A4View1(privateRecord21 + 0x26, 2) == 0) {
        goto block_155;
    }
    if (retainedPlayerBaseHeadingDistanceOrVector16 >= Level22_87EECField(privateRecord21, int *, 0x18)) {
        goto block_155;
    }
block_154:
    rawWord2 = 3;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    Level22_87EECCall34F40View1(ownerRecord20, 3);
    return;
block_155:
    if (retainedHeaderResult18 == 0) {
        goto block_159;
    }
    if ((Level22_87EECField(privateRecord21, int *, 0x18) - 0x400) >= retainedPlayerBaseHeadingDistanceOrVector16) {
        goto returnOriginal1799;
    }
    if (Level22_87EECCall4F334View1(ownerRecord20 + 0xC, privateRecord21 + 0x2C) < 0x401) {
        goto block_196;
    }
block_158:
block_159:
    rawWord2 = 1;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    Level22_87EECCall34F40View1(ownerRecord20, 1);
    return;
originalSecondState3:
    rawWord2 = Level22_87EECCall35D38View1(ownerRecord20);
    rawWord3 = Level22_87EECField(privateRecord21, int*, 32);
    argumentWord4 = rawWord2+rawWord3;
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x24C) == 3) {
        goto adjustOriginalHeight1012;
    }
    rawWord2 = Level22_87EECData70328View2;
    rawWord3 = rawWord2+1024;
    if (argumentWord4 >= rawWord3) {
        goto adjustOriginalHeight1012;
    }
    argumentWord4 = rawWord3;
    adjustOriginalHeight1012:rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    rawWord2 = rawWord3 < argumentWord4;
    if (rawWord2){
        rawWord2 = rawWord3+40;
        goto block_165;
    }
    rawWord2 = rawWord3+40;
    rawWord2 = argumentWord4+40;
    rawWord2 = rawWord2 < rawWord3;
    if (!rawWord2){
        rawWord2 = rawWord3-40;
        goto decreaseOriginalHalfword1022;
    }
    rawWord2 = rawWord3-40;
    block_165:Level22_87EECField(ownerRecord20, int*, 20) = rawWord2;
    decreaseOriginalHalfword1022:rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord3 = rawWord2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 < 129){
        rawWord2 = rawWord3-16;
        goto block_169;
    }
    rawWord2 = rawWord3-16;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
    __asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    rawWord2 = (rawWord2 << 16) >> 16;
    if (rawWord2 >= 128) goto block_169;
    rawWord2 = 128;
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
block_169:
    if (Level22_87EECData6C770View1 == 0) {
        goto returnOriginal1799;
    }
    rawWord2 = 4;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    Level22_87EECCall34F40View1(ownerRecord20, 4);
    return;
originalSecondState4:
    rawWord2 = Level22_87EECCall35D38View1(ownerRecord20);
    rawWord3 = Level22_87EECField(privateRecord21, int*, 32);
    argumentWord4 = rawWord2+rawWord3;
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x24C) == 3) {
        goto adjustOriginalHeight1064;
    }
    rawWord2 = Level22_87EECData70328View2;
    rawWord3 = rawWord2+1024;
    if (argumentWord4 >= rawWord3) {
        goto adjustOriginalHeight1064;
    }
    argumentWord4 = rawWord3;
    adjustOriginalHeight1064:rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    rawWord2 = rawWord3 < argumentWord4;
    if (rawWord2){
        rawWord2 = rawWord3+40;
        goto block_176;
    }
    rawWord2 = rawWord3+40;
    rawWord2 = argumentWord4+40;
    rawWord2 = rawWord2 < rawWord3;
    if (!rawWord2){
        rawWord2 = rawWord3-40;
        goto block_177;
    }
    rawWord2 = rawWord3-40;
    block_176:Level22_87EECField(ownerRecord20, int*, 20) = rawWord2;
block_177:
    Level22_87EECCall3573CView1(ownerRecord20, 3, 0, 1);
    temporaryWord7 = Level22_87EECField(privateRecord21, unsigned short *, 0x28) - 0x10;
    Level22_87EECField(privateRecord21, unsigned short *, 0x28) = temporaryWord7;
    __asm__ volatile("":"=r"(temporaryWord7):"0"(temporaryWord7), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    if ((short) temporaryWord7 >= 0x80) {
        goto returnOriginal1799;
    }
    Level22_87EECField(privateRecord21, unsigned short *, 0x28) = 0x80U;
    Level22_87EECField(privateRecord21, short *, 0x3C) = Level22_87EECCall4E880View1(Level22_87EECField(ownerRecord20, int *, 0xC) - Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0), Level22_87EECField(ownerRecord20, int *, 0x10) - Level22_87EECField((int)&Level22_87EECData70328View1, int *, 4), 0);
    goto block_284;
originalSecondState20:
    rawWord2 = Level22_87EECCall4F334View1(ownerRecord20 + 0xC, (int)&Level22_87EECData70328View1);
    argumentWord4 = (int)ownerRecord20;
    __asm__ volatile(""::"r"(argumentWord4));
    retainedSpawnPrivateOrDistance19 = rawWord2;
    rawWord2 = Level22_87EECCall35D38View1(argumentWord4);
    rawWord3 = Level22_87EECField(privateRecord21, int*, 32);
    argumentWord4 = rawWord2+rawWord3;
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x24C) == 3) {
        goto adjustOriginalHeight1124;
    }
    rawWord2 = Level22_87EECData70328View2;
    rawWord3 = rawWord2+1024;
    if (argumentWord4 >= rawWord3) {
        goto adjustOriginalHeight1124;
    }
    argumentWord4 = rawWord3;
    adjustOriginalHeight1124:rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    rawWord2 = rawWord3 < argumentWord4;
    if (rawWord2){
        rawWord2 = rawWord3+40;
        goto block_184;
    }
    rawWord2 = rawWord3+40;
    rawWord2 = argumentWord4+40;
    rawWord2 = rawWord2 < rawWord3;
    if (!rawWord2){
        rawWord2 = rawWord3-40;
        goto block_185;
    }
    rawWord2 = rawWord3-40;
    block_184:Level22_87EECField(ownerRecord20, int*, 20) = rawWord2;
block_185:
    Level22_87EECCall3573CView1(ownerRecord20, 3, 0, 1);
    if ((unsigned int) (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x50) - 7) < 2U) {
        goto block_188;
    }
    rawWord3 = Level22_87EECData70328View2;
    rawWord2 = Level22_87EECField(ownerRecord20, int*, 20);
    if (rawWord2 < rawWord3) {
        goto block_188;
    }
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x240) == 0) {
        goto block_191;
    }
block_188:
    rawWord3 = Level22_87EECField(privateRecord21, void ***, 0x44);
    if (Level22_87EECField(rawWord3, int*, 0) != ownerRecord20) {
        goto block_191;
    }
    Level22_87EECField(rawWord3, int*, 0) = 0;
    __asm__ volatile(""::"m"(Level22_87EECField(rawWord3, int*, 0)):"memory");
    rawWord3 = (int)&Level22_87EECData6E164View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    rawWord2 = Level22_87EECField(rawWord3, int*, 0);
    if (rawWord2 != (int)ownerRecord20) goto block_191;
    Level22_87EECData6E160View1 = 0;
    Level22_87EECField(rawWord3, int*, 0) = 0;
block_191:
    if ((Level22_87EECField(privateRecord21, int *, 0x18) + 0x200) >= retainedSpawnPrivateOrDistance19) {
        goto block_198;
    }
    argumentWord4 = privateRecord21 + 0x26;
    if (Level22_87EECField(privateRecord21, short *, 0x2A) == 1) {
        goto readOriginalTimer1207;
    }
    rawWord3 = Level22_87EECField(privateRecord21, void ***, 0x44);
    Level22_87EECField(privateRecord21, short *, 0x24) = 0;
    if (Level22_87EECField(rawWord3, int*, 0) != ownerRecord20) {
        goto block_196;
    }
    Level22_87EECField(rawWord3, int*, 0) = 0;
    __asm__ volatile(""::"m"(Level22_87EECField(rawWord3, int*, 0)):"memory");
    rawWord3 = (int)&Level22_87EECData6E164View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    rawWord2 = Level22_87EECField(rawWord3, int*, 0);
    if (rawWord2 != (int)ownerRecord20) goto block_196;
    Level22_87EECData6E160View1 = 0;
    Level22_87EECField(rawWord3, int*, 0) = 0;
block_196:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x48) = 0U;
block_197:
    Level22_87EECCall34F40View1(ownerRecord20, 0);
    return;
block_198:
    argumentWord4 = privateRecord21 + 0x26;
readOriginalTimer1207:
    rawWord2 = Level22_87EECCall359A4View1(argumentWord4, 2);
    argumentWord4 = (int)ownerRecord20+12;
    if (rawWord2 == 0) {
        goto block_213;
    }
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8) >= Level22_87EECField(ownerRecord20, int *, 0x14)) {
        goto block_213;
    }
    if ((unsigned int) (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x50) - 7) < 2U) {
        goto block_213;
    }
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x240) != 0) {
        goto block_213;
    }
    if (retainedHeaderResult18 == 0) {
        goto block_213;
    }
    temporaryWord8 = *Level22_87EECField(privateRecord21, void ***, 0x44);
    if (temporaryWord8 == 0) {
        goto block_206;
    }
    if (temporaryWord8 != ownerRecord20) {
        goto block_213;
    }
block_206:
    if (retainedSpawnPrivateOrDistance19 >= Level22_87EECField(privateRecord21, int *, 0x1C)) {
        goto produceOriginalOwnerPosition1287;
    }
    if (Level22_87EECCall4F264View1(Level22_87EECField(ownerRecord20, unsigned char *, 0x46), Level22_87EECCall4E880View1(Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0) - Level22_87EECField(ownerRecord20, int *, 0xC), Level22_87EECField((int)&Level22_87EECData70328View1, int *, 4) - Level22_87EECField(ownerRecord20, int *, 0x10), 0)) >= 8) {
        goto produceOriginalOwnerPosition1287;
    }
    rawWord2 = Level22_87EECCall4F264View1(((int)(Level22_87EECData6E040View1 << 16) >> 20), Level22_87EECCall4E880View1(Level22_87EECField(ownerRecord20, int *, 0xC) - Level22_87EECData6E020View1, Level22_87EECField(ownerRecord20, int *, 0x10) - Level22_87EECData6E024View1, 0));
    argumentWord4 = (int)ownerRecord20;
    if (rawWord2 >= 0x20) {
        goto produceOriginalOwnerPosition1287;
    }
    argumentWord5 = 5;
    rawWord2 = Level22_87EECField(privateRecord21, int*, 68);
    __asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4), "r"(rawWord2):"$5");
    argumentWord5 = 5;
    Level22_87EECField(rawWord2, int*, 0) = argumentWord4;
prepareOriginalStateFive1281:
    rawWord2 = 5;
    Level22_87EECField(argumentWord4, unsigned char*, 73) = 0;
callOriginalState1283:
    Level22_87EECField(argumentWord4, unsigned char*, 72) = rawWord2;
    Level22_87EECCall34F40View1(argumentWord4, argumentWord5);
    return;
produceOriginalOwnerPosition1287:
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    argumentWord4 = (int)ownerRecord20+12;
block_213:
    rawWord2 = Level22_87EECCall4F334View1(argumentWord4, privateRecord21+44);
    retainedPlayerBaseHeadingDistanceOrVector16 = 5;
    __asm__ volatile(""::"r"(retainedPlayerBaseHeadingDistanceOrVector16));
    retainedDistanceSpawnOrPrivate22 = rawWord2;
    if (retainedHeaderResult18 == 0) {
        goto block_216;
    }
    if ((Level22_87EECField(privateRecord21, int *, 0x1C) - 0x400) >= retainedSpawnPrivateOrDistance19) {
        goto produceOriginalZero1327;
    }
    if ((rawWord2 = retainedDistanceSpawnOrPrivate22 < 513, rawWord2)) {
        argumentWord6 = 0;
        goto readOriginalPlayerVector1328;
    }
block_216:
    if (Level22_87EECField(privateRecord21, short *, 0x26) != 0) {
        goto readOriginalPrivateVector1321;
    }
    rawWord3 = Level22_87EECField(privateRecord21, void ***, 0x44);
    if (Level22_87EECField(rawWord3, int*, 0) != ownerRecord20) {
        goto readOriginalPrivateVector1321;
    }
    Level22_87EECField(rawWord3, int*, 0) = 0;
    __asm__ volatile(""::"m"(Level22_87EECField(rawWord3, int*, 0)):"memory");
    rawWord3 = (int)&Level22_87EECData6E164View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    rawWord2 = Level22_87EECField(rawWord3, int*, 0);
    if (rawWord2 != (int)ownerRecord20) goto readOriginalPrivateVector1321;
    Level22_87EECData6E160View1 = 0;
    Level22_87EECField(rawWord3, int*, 0) = 0;
readOriginalPrivateVector1321:
    rawWord3 = Level22_87EECField(privateRecord21, int *, 0x2C);
    argumentWord4 = Level22_87EECField(ownerRecord20, int *, 0xC);
    rawWord2 = Level22_87EECField(privateRecord21, int *, 0x30);
    argumentWord5 = Level22_87EECField(ownerRecord20, int *, 0x10);
    argumentWord6 = 0;
    goto callOriginalVectorHeading1335;
    produceOriginalZero1327:argumentWord6 = 0;
    __asm__ volatile(""::"r"(argumentWord6));
readOriginalPlayerVector1328:
    rawWord3 = Level22_87EECField(ownerRecord20, int *, 0xC);
    argumentWord4 = Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0);
    rawWord2 = Level22_87EECField(ownerRecord20, int *, 0x10);
    argumentWord5 = Level22_87EECField((int)&Level22_87EECData70328View1, int *, 4);
callOriginalVectorHeading1335:
    __asm__ volatile(""::"r"(argumentWord6));
    argumentWord4 = rawWord3-argumentWord4;
    argumentWord5 = rawWord2-argumentWord5;
    retainedOwnerPositionDistanceHeadingOrVector17 = Level22_87EECCall4E880View1(argumentWord4, argumentWord5, argumentWord6);
    argumentWord4 = Level22_87EECCall4F264View1(retainedOwnerPositionDistanceHeadingOrVector17, Level22_87EECField(privateRecord21, short*, 60));
    rawWord3 = Level22_87EECData6C648View1;
    rawWord2 = 3;
    if (rawWord3 != rawWord2){
        rawWord2 = 4;
        goto block_225;
    }
    rawWord2 = 4;
    rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16 >> 1;
    retainedPlayerBaseHeadingDistanceOrVector16 += rawWord2;
    goto block_227;
    block_225:if (rawWord3 != rawWord2){
        rawWord2 = argumentWord4 < retainedPlayerBaseHeadingDistanceOrVector16;
        goto block_228;
    }
    rawWord2 = argumentWord4 < retainedPlayerBaseHeadingDistanceOrVector16;
    retainedPlayerBaseHeadingDistanceOrVector16 <<= 1;
    block_227:rawWord2 = argumentWord4 < retainedPlayerBaseHeadingDistanceOrVector16;
block_228:
    if (rawWord2 == 0) {
        goto block_230;
    }
    retainedPlayerBaseHeadingDistanceOrVector16 = argumentWord4;
block_230:
    Level22_87EECField(privateRecord21, short *, 0x3C) = Level22_87EECCall4F2ECView1(retainedOwnerPositionDistanceHeadingOrVector17, Level22_87EECField(privateRecord21, short*, 60), retainedPlayerBaseHeadingDistanceOrVector16, (retainedPlayerBaseHeadingDistanceOrVector16 >> 1) + 1);
    if (retainedHeaderResult18 == 0) {
        goto block_233;
    }
    if ((rawWord2 = Level22_87EECField(privateRecord21, int*, 28)-1024, rawWord2 = retainedSpawnPrivateOrDistance19 < rawWord2, rawWord2)) {
        goto block_234;
    }
    if ((rawWord2 = retainedDistanceSpawnOrPrivate22 < 513, rawWord2)) {
        goto returnOriginal1799;
    }
block_233:
block_234:
    Level22_87EECCall35EE0View1(ownerRecord20, Level22_87EECField(privateRecord21, short *, 0x3C), 0x64, 0x400, 0x400, 0x22);
    return;
originalSecondState5:
    retainedTimerResult23 = Level22_87EECCall55E84View1(ownerRecord20);
    retainedPlayerBaseHeadingDistanceOrVector16 = Level22_87EECCall35D38View1(ownerRecord20);
    retainedDistanceSpawnOrPrivate22 = Level22_87EECCall4F334View1(ownerRecord20 + 0xC, (int)&Level22_87EECData70328View1);
    retainedPlayerBaseHeadingDistanceOrVector16 = retainedPlayerBaseHeadingDistanceOrVector16 + Level22_87EECField(privateRecord21, int *, 0x20);
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x24C) == 3) {
        goto adjustOriginalHeight1411;
    }
    temporaryWord20 = Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8) + 0x400;
    if (retainedPlayerBaseHeadingDistanceOrVector16 >= temporaryWord20) {
        goto adjustOriginalHeight1411;
    }
    retainedPlayerBaseHeadingDistanceOrVector16 = temporaryWord20;
    adjustOriginalHeight1411:rawWord3 = Level22_87EECField(ownerRecord20, int*, 20);
    rawWord2 = rawWord3 < retainedPlayerBaseHeadingDistanceOrVector16;
    if (rawWord2){
        rawWord2 = rawWord3+40;
        goto block_240;
    }
    rawWord2 = rawWord3+40;
    rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16+40;
    rawWord2 = rawWord2 < rawWord3;
    if (!rawWord2){
        rawWord2 = rawWord3-40;
        goto block_241;
    }
    rawWord2 = rawWord3-40;
    block_240:Level22_87EECField(ownerRecord20, int*, 20) = rawWord2;
block_241:
    Level22_87EECCall3573CView1(ownerRecord20, 3, 0, 1);
    rawWord2 = Level22_87EECCall4F334View1(ownerRecord20 + 0xC, privateRecord21+44);
    retainedPlayerBaseHeadingDistanceOrVector16 = 5;
    __asm__ volatile(""::"r"(retainedPlayerBaseHeadingDistanceOrVector16));
    retainedSpawnPrivateOrDistance19 = rawWord2;
    if (retainedHeaderResult18 == 0) {
        goto readOriginalPrivateVector1440;
    }
    if ((Level22_87EECField(privateRecord21, int *, 0x1C) - 0x400) >= retainedDistanceSpawnOrPrivate22) {
        goto produceOriginalZero1446;
    }
    if ((rawWord2 = retainedSpawnPrivateOrDistance19 < 513, rawWord2)) {
        argumentWord6 = 0;
        goto readOriginalPlayerVector1447;
    }
readOriginalPrivateVector1440:
    rawWord3 = Level22_87EECField(privateRecord21, int *, 0x2C);
    argumentWord4 = Level22_87EECField(ownerRecord20, int *, 0xC);
    rawWord2 = Level22_87EECField(privateRecord21, int *, 0x30);
    argumentWord5 = Level22_87EECField(ownerRecord20, int *, 0x10);
    argumentWord6 = 0;
    goto callOriginalVectorHeading1454;
    produceOriginalZero1446:argumentWord6 = 0;
    __asm__ volatile(""::"r"(argumentWord6));
readOriginalPlayerVector1447:
    rawWord3 = Level22_87EECField(ownerRecord20, int *, 0xC);
    argumentWord4 = Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0);
    rawWord2 = Level22_87EECField(ownerRecord20, int *, 0x10);
    argumentWord5 = Level22_87EECField((int)&Level22_87EECData70328View1, int *, 4);
callOriginalVectorHeading1454:
    __asm__ volatile(""::"r"(argumentWord6));
    argumentWord4 = rawWord3-argumentWord4;
    argumentWord5 = rawWord2-argumentWord5;
    retainedOwnerPositionDistanceHeadingOrVector17 = Level22_87EECCall4E880View1(argumentWord4, argumentWord5, argumentWord6);
    argumentWord4 = Level22_87EECCall4F264View1(retainedOwnerPositionDistanceHeadingOrVector17, Level22_87EECField(privateRecord21, short*, 60));
    rawWord3 = Level22_87EECData6C648View1;
    rawWord2 = 3;
    if (rawWord3 != rawWord2){
        rawWord2 = 4;
        goto block_249;
    }
    rawWord2 = 4;
    rawWord2 = retainedPlayerBaseHeadingDistanceOrVector16 >> 1;
    retainedPlayerBaseHeadingDistanceOrVector16 += rawWord2;
    goto block_251;
    block_249:if (rawWord3 != rawWord2){
        rawWord2 = argumentWord4 < retainedPlayerBaseHeadingDistanceOrVector16;
        goto block_252;
    }
    rawWord2 = argumentWord4 < retainedPlayerBaseHeadingDistanceOrVector16;
    retainedPlayerBaseHeadingDistanceOrVector16 <<= 1;
    block_251:rawWord2 = argumentWord4 < retainedPlayerBaseHeadingDistanceOrVector16;
block_252:
    if (rawWord2 == 0) {
        goto block_254;
    }
    retainedPlayerBaseHeadingDistanceOrVector16 = argumentWord4;
block_254:
    Level22_87EECField(privateRecord21, short *, 0x3C) = Level22_87EECCall4F2ECView1(retainedOwnerPositionDistanceHeadingOrVector17, Level22_87EECField(privateRecord21, short*, 60), retainedPlayerBaseHeadingDistanceOrVector16, (retainedPlayerBaseHeadingDistanceOrVector16 >> 1) + 1);
    if (retainedHeaderResult18 == 0) {
        goto block_257;
    }
    if ((rawWord2 = Level22_87EECField(privateRecord21, int*, 28)-1024, rawWord2 = retainedDistanceSpawnOrPrivate22 < rawWord2, rawWord2)) {
        goto block_258;
    }
    rawWord2 = retainedSpawnPrivateOrDistance19 < 513;
    if (rawWord2){
        rawWord2 = retainedTimerResult23 < 17;
        goto testOriginalTimer1503;
    }
    rawWord2 = retainedTimerResult23 < 17;
block_257:
block_258:
    Level22_87EECCall35EE0View1(ownerRecord20, Level22_87EECField(privateRecord21, short *, 0x3C), 0x64, 0x400, 0x400, 0x22);
    rawWord2 = retainedTimerResult23 < 0x11;
testOriginalTimer1503:
    if (rawWord2 != 0) {
        goto block_271;
    }
    rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord3 = rawWord2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 >= 256) {
        goto block_271;
    }
    if (Level22_87EECField(ownerRecord20, unsigned char *, 0x49) != 0) {
        goto block_270;
    }
    temporaryWord9 = Level22_87EECDataSpawnMobyView1(0x1FC, ownerRecord20);
    if (temporaryWord9 == 0) {
        goto block_271;
    }
    Level22_87EECField(temporaryWord9, signed char *, 0x4F) = 0x64;
    retainedDistanceSpawnOrPrivate22 = Level22_87EECField(temporaryWord9, void **, 0);
    Level22_87EECField(temporaryWord9, int *, 0x1C) = (int) (Level22_87EECField(temporaryWord9, int *, 0x1C) | 0x80000000);
    Level22_87EECCall4F178View1(&originalFrame.sp18, (int)&Level22_87EECData70328View1);
    rawWord2 = Level22_87EECCall1A358View1(&originalFrame.sp18, 4096);
    rawWord3 = rawWord2;
    argumentWord4 = Level22_87EECData70328View2;
    rawWord2 = argumentWord4-rawWord3;
    if (rawWord2 < 0) goto checkOriginalNegativeHeight1547;
    rawWord2 = rawWord2 < 1800;
    __asm__ volatile("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2){
        rawWord2 = rawWord3+300;
        goto writeOriginalSpawnHeight1551;
    }
    rawWord2 = rawWord3+300;
    __asm__ volatile(""::"r"(rawWord2));
    argumentWord4 = (int)ownerRecord20;
    goto block_269;
    checkOriginalNegativeHeight1547:rawWord2 = rawWord3-argumentWord4;
    rawWord2 = rawWord2 < 1800;
    if (!rawWord2){
        rawWord2 = rawWord3+300;
        goto block_268;
    }
    rawWord2 = rawWord3+300;
    writeOriginalSpawnHeight1551:originalFrame.sp20 = rawWord2;
    block_268:argumentWord4 = (int)ownerRecord20;
block_269:
    Level22_87EECCall55D24View1(argumentWord4, 4);
    Level22_87EECCall55F14View1(ownerRecord20, 6, &originalFrame.sp28);
    Level22_87EECCall55F14View1(ownerRecord20, 7, &originalFrame.sp48);
    retainedPlayerBaseHeadingDistanceOrVector16 = temporaryWord9 + 0xC;
    Level22_87EECCall4F194View1(retainedPlayerBaseHeadingDistanceOrVector16, &originalFrame.sp28, &originalFrame.sp48);
    Level22_87EECCall4F110View1(retainedPlayerBaseHeadingDistanceOrVector16, 1);
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    argumentWord4 = retainedPlayerBaseHeadingDistanceOrVector16;
    argumentWord5 = retainedPlayerBaseHeadingDistanceOrVector16;
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5));
    retainedOwnerPositionDistanceHeadingOrVector17 = (int)ownerRecord20+12;
    Level22_87EECCall4F1C8View1(argumentWord4, argumentWord5, retainedOwnerPositionDistanceHeadingOrVector17);
    Level22_87EECCall4F08CView1(retainedPlayerBaseHeadingDistanceOrVector16, (short) Level22_87EECField(privateRecord21, unsigned short *, 0x28), 0x80);
    Level22_87EECCall4F194View1(retainedPlayerBaseHeadingDistanceOrVector16, retainedPlayerBaseHeadingDistanceOrVector16, retainedOwnerPositionDistanceHeadingOrVector17);
    Level22_87EECCall4F1C8View1(retainedDistanceSpawnOrPrivate22, &originalFrame.sp18, retainedPlayerBaseHeadingDistanceOrVector16);
    Level22_87EECCall4F08CView1(retainedDistanceSpawnOrPrivate22, Level22_87EECCall4EDE8View1(retainedDistanceSpawnOrPrivate22, 1), 0xB4);
    Level22_87EECField(temporaryWord9, unsigned char *, 0x45) = Level22_87EECCall4E880View1(Level22_87EECCall4EDE8View1(retainedDistanceSpawnOrPrivate22, 0), Level22_87EECField(retainedDistanceSpawnOrPrivate22, int *, 8), 0);
    Level22_87EECField(temporaryWord9, unsigned char *, 0x46) = (unsigned char) Level22_87EECField(ownerRecord20, unsigned char *, 0x46);
    Level22_87EECField(retainedDistanceSpawnOrPrivate22, int *, 0xC) = 0xB4;
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 1U;
    goto block_271;
block_270:
    rawWord2 = rawWord3+2;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    Level22_87EECField(privateRecord21, short*, 40) = rawWord2;
block_271:
    if ((unsigned int) (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x50) - 7) < 2U) {
        goto block_274;
    }
    if ((Level22_87EECField(ownerRecord20, int *, 0x14) + 0x400) < Level22_87EECField((int)&Level22_87EECData70328View1, int *, 8)) {
        goto block_274;
    }
    if (Level22_87EECField((int)&Level22_87EECData70328View1, int *, 0x240) == 0) {
        goto checkOriginalOwnerStatus1655;
    }
block_274:
    rawWord3 = Level22_87EECField(privateRecord21, void ***, 0x44);
    if (Level22_87EECField(rawWord3, int*, 0) != ownerRecord20) {
        goto checkOriginalOwnerStatus1655;
    }
    Level22_87EECField(rawWord3, int*, 0) = 0;
    __asm__ volatile(""::"m"(Level22_87EECField(rawWord3, int*, 0)):"memory");
    rawWord3 = (int)&Level22_87EECData6E164View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    rawWord2 = Level22_87EECField(rawWord3, int*, 0);
    if (rawWord2 != (int)ownerRecord20) goto block_277;
    Level22_87EECData6E160View1 = 0;
    Level22_87EECField(rawWord3, int*, 0) = 0;
block_277:
    Level22_87EECField(privateRecord21, short *, 0x26) = 0x3C;
    Level22_87EECCall34F40View1(ownerRecord20, 4);
    rawWord2 = 0x14;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
checkOriginalOwnerStatus1655:
    if (Level22_87EECData6C770View1 == 0) {
        goto returnOriginal1799;
    }
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = 0U;
    rawWord2 = Level22_87EECField(privateRecord21, short*, 40);
    rawWord2 = rawWord2 < 193;
    argumentWord4 = (int)ownerRecord20;
    if (rawWord2) goto prepareOriginalStateFour1684;
    rawWord2 = Level22_87EECField(privateRecord21, int*, 68);
    __asm__ volatile(""::"r"(rawWord2));
    rawWord3 = (int)&Level22_87EECData6E164View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    Level22_87EECField(rawWord2, int*, 0) = 0;
    rawWord2 = Level22_87EECField(rawWord3, int*, 0);
    if (rawWord2 != (int)ownerRecord20){
        argumentWord5 = 0;
        goto clearOriginalOwnerState1678;
    }
    argumentWord5 = 0;
    Level22_87EECData6E160View1 = 0;
    Level22_87EECField(rawWord3, int*, 0) = 0;
    __asm__ volatile("":"=r"(ownerRecord20):"0"(ownerRecord20), "m"(Level22_87EECField(rawWord3, int*, 0)):"memory");
    argumentWord4 = (int)ownerRecord20;
    clearOriginalOwnerState1678:rawWord2 = 300;
    Level22_87EECField(privateRecord21, short*, 38) = rawWord2;
    Level22_87EECField(argumentWord4, unsigned char*, 72) = 0;
    Level22_87EECCall34F40View1(argumentWord4, argumentWord5);
    return;
    prepareOriginalStateFour1684:argumentWord5 = 4;
    __asm__ volatile(""::"r"(argumentWord5));
    rawWord2 = 60;
    Level22_87EECField(privateRecord21, short*, 38) = rawWord2;
    Level22_87EECCall34F40View1(argumentWord4, argumentWord5);
block_284:
    rawWord2 = 0x14;
    Level22_87EECField(ownerRecord20, unsigned char*, 72) = rawWord2;
    return;
originalSecondState6:
    if (Level22_87EECCall35194View1(ownerRecord20, privateRecord21) != 0x100) {
        goto returnOriginal1799;
    }
    rawWord2 = Level22_87EECCall35D38View1(ownerRecord20);
    argumentWord6 = 0;
    if (!rawWord2) goto produceOriginalPrivateVector1705;
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 1;
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5));
    argumentWord7 = 0;
    goto callOriginalRestore1708;
    produceOriginalPrivateVector1705:argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 1;
    argumentWord7 = privateRecord21+44;
callOriginalRestore1708:
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7));
    Level22_87EECCall36A68View1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
    Level22_87EECCall369B8View1(ownerRecord20, 0x18);
    Level22_87EECField(ownerRecord20, int *, 0x14) = 0x800;
    Level22_87EECField(ownerRecord20, unsigned char *, 0x49) = (unsigned char) Level22_87EECField(ownerRecord20, unsigned char *, 0x4C);
    Level22_87EECCall55D24View1(ownerRecord20, 4);
    Level22_87EECCall3BA00View1(ownerRecord20);
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 32;
    goto callOriginalOwnerUpdate1794;
originalSecondState22:
    Level22_87EECField(ownerRecord20, unsigned char *, 0x44) = (unsigned char) (Level22_87EECField(ownerRecord20, unsigned char *, 0x44) + (Level22_87EECCall55E84View1(ownerRecord20) >> 1));
    Level22_87EECCall35EE0View1(ownerRecord20, (Level22_87EECField(ownerRecord20, unsigned char *, 0x46) + 0x80) & 0xFF, 0x12C, 0x400, 0x400, 0x22);
    temporaryWord10 = Level22_87EECField(privateRecord21, unsigned short *, 0x28) + 8;
    Level22_87EECField(privateRecord21, unsigned short *, 0x28) = temporaryWord10;
    __asm__ volatile("":"=r"(temporaryWord10):"0"(temporaryWord10), "m"(Level22_87EECField(privateRecord21, short*, 40)):"memory");
    if ((short) temporaryWord10 >= 0x201) {
        goto readOriginalFinalHeight1766;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0xC) < 0x1000) {
        goto readOriginalFinalHeight1766;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0x10) < 0x1000) {
        goto readOriginalFinalHeight1766;
    }
    if (Level22_87EECField(ownerRecord20, int *, 0x14) >= 0x1000) {
        goto returnOriginal1799;
    }
    readOriginalFinalHeight1766:rawWord2 = Level22_87EECCall35D38View1(ownerRecord20);
    argumentWord6 = 0;
    if (!rawWord2) goto produceOriginalPrivateVector1774;
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 1;
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5));
    argumentWord7 = 0;
    goto callOriginalRestore1777;
    produceOriginalPrivateVector1774:argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 1;
    argumentWord7 = privateRecord21+44;
    callOriginalRestore1777:__asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7));
    Level22_87EECCall36A68View1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
    Level22_87EECCall369B8View1(ownerRecord20, 24);
    Level22_87EECField(ownerRecord20, int*, 20) = 2048;
    Level22_87EECField(ownerRecord20, unsigned char*, 68) = 0;
    Level22_87EECField(ownerRecord20, unsigned char*, 73) = Level22_87EECField(ownerRecord20, unsigned char*, 76);
    Level22_87EECCall55D24View1(ownerRecord20, 4);
    Level22_87EECCall3BA00View1(ownerRecord20);
    argumentWord4 = (int)ownerRecord20;
    argumentWord5 = 72;
callOriginalOwnerUpdate1794:
    __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5));
    Level22_87EECCall369B8View1(argumentWord4, argumentWord5);
produceOriginalOwnerArgument1796:
    argumentWord4 = (int)ownerRecord20;
    originalHeldOwner1797:__asm__ volatile(""::"r"(argumentWord4));
    Level22_87EECCall55B18View1(argumentWord4);
returnOriginal1799:
    return;
}
#undef Level22_87EECField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_22/moby/func_level_22_80089B38.s SHA256 ee997544d80220632927d74d14d66ebdbaffc465eda7f9b5dfb467fce6e58654. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level22_89B38_Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern Moby* Level22_89B38_D_8006C550 __asm__("D_8006C550");
extern Spyro Level22_89B38_D_80070328 __asm__("D_80070328");
void Level22_89B38_func_80034F40(Moby*, int) __asm__("func_80034F40");
/* extern */
void Level22_89B38_func_80035734(Moby*) __asm__("func_80035734");
int Level22_89B38_func_8003585C(Moby*, int, int, int, int, int) __asm__("func_8003585C");
/* extern */
int Level22_89B38_func_800359A4(void*, int) __asm__("func_800359A4");
/* extern */
int Level22_89B38_func_80035D38(Moby*) __asm__("func_80035D38");
int Level22_89B38_func_80035DDC(Moby*, int, int, int, int) __asm__("func_80035DDC");
/* extern */
int Level22_89B38_func_8003613C(int,int) __asm__("func_8003613C");
int Level22_89B38_func_8003636C(int,int) __asm__("func_8003636C");
int Level22_89B38_func_800363DC(int,int) __asm__("func_800363DC");
void Level22_89B38_func_800369B8(Moby*, int) __asm__("func_800369B8");
/* extern */
int Level22_89B38_func_8003BABC(Moby*, int, int) __asm__("func_8003BABC");
/* extern */
int Level22_89B38_func_8004E880(int, int, int) __asm__("func_8004E880");
/* extern */
void Level22_89B38_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
/* extern */
extern int Level22_89B38_func_8004F264(int,int) __asm__("func_8004F264");
int Level22_89B38_func_8004F334(Vector3D*, Vector3D*) __asm__("func_8004F334");
/* extern */
void Level22_89B38_func_80055B18(Moby*) __asm__("func_80055B18");
/* extern */
void Level22_89B38_func_80055D24(Moby*, int) __asm__("func_80055D24");
/* extern */
extern void Level22_89B38_func_80056270(Moby*) __asm__("func_80056270");
extern int Level22_89B38_rand() __asm__("rand");
extern int Level22_89B38_D_8006C770 __asm__("D_8006C770");
void func_level_22_80089B38(Moby *moby) {
    /* Original 0x58-byte frame: vector at SP18, saved16..21 at SP38..4C,
    * RA at SP50. Original states are 0/1/2; raw private fields retain their
    * identified byte/halfword/word widths. Position record offsets add bytes.
    * The late private1B adjustment is unsigned SLTU: +5, -5, or no store.
    * Original helper result4 is copied into result2 in the BGEZ delay slot;
    * the negative path then uses NEGU2,2. The initialized empty constraint
    * in that path preserves this lifetime and the earlier byte-branch delay
    * slot, avoiding an extra compiler NOP. It emits no CPU instructions.
    * The dead6 boundary precedes its replacement zero producer. Compiler,
    * options, matching gates and original data remain unchanged.
    * Confidence: exact native instructions/control flow. Helper meanings,
    * physical units/fixed point and caller/frame cadence remain unresolved.
    * Cadence is per invocation; no frame frequency or runtime claim.
    * Falsification: every native/linked word and branch/internal jump target,
    * preserved data, full executable and every original overlay hash.
    * AI generated; not human reviewed. */
    struct {
        Vector3D sp18;
        unsigned char pad24[20];
    }
    originalFrame;
    register int temp_a0_2 __asm__("4");
    register int temp_a1 __asm__("5");
    int temp_v1_7;
    int temp_v1_8;
    int nextIndex;
    int previousIndex;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s0_5;
    int temp_s1;
    register int temp_s1_2 __asm__("17");
    register int temp_s1_3 __asm__("17");
    register int temp_s1_4 __asm__("17");
    int linkedPositionResult;
    int temp_v0_12;
    register int signedHelperResult __asm__("4");
    register int temp_v0_2 __asm__("16");
    int temp_v0_3;
    register int temp_v0_7 __asm__("3");
    register int temp_v0_9 __asm__("3");
    int linkedMobyIndex;
    int var_a0;
    int var_a0_2;
    register int var_v0 __asm__("2");
    register int absoluteHelperResult __asm__("2");
    int var_v0_3;
    register int var_v0_4 __asm__("2");
    int var_v0_6;
    register int var_v0_9 __asm__("2");
    register int adjustmentStep __asm__("3");
    unsigned int currentByteMasked;
    unsigned int temp_a0;
    unsigned int temp_a0_3;
    unsigned int temp_a0_4;
    unsigned int temp_a1_2;
    unsigned int targetByte1A;
    register unsigned int temp_s0_6 __asm__("16");
    unsigned int temp_v0_10;
    unsigned int temp_v0_4;
    unsigned int currentByte1B;
    register unsigned int nextByte1B __asm__("2");
    unsigned int var_v0_12;
    register unsigned int var_v0_13 __asm__("2");
    unsigned int var_v0_2;
    unsigned int var_v0_5;
    void *temp_a0_5;
    void *temp_a0_6;
    register void *temp_a3 __asm__("7");
    void *privateData;
    void *temp_v0;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_8;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    privateData = moby->mobyTag;
    if (moby->damageFlags != 0) {
        Level22_89B38_func_8003BABC(moby, 0, 0);
        SpawnMoby(0x10, moby);
        Level22_89B38_func_80055D24(moby, 4);
        Level22_89B38_func_800369B8(moby, 0x20);
        Level22_89B38_func_80055B18(moby);
        return;
    }
    temp_a0 = moby->state;
    switch ((int)temp_a0) {
        /* irregular */
    case 0:
        if (Level22_89B38_func_8004F334(&moby->position, &Level22_89B38_D_80070328.position) < 0x1C00) {
            temp_s1 = Level22_89B38_func_8004E880(Level22_89B38_D_80070328.position.x - moby->position.x, Level22_89B38_D_80070328.position.y - moby->position.y, 0);
            temp_a3 = Level22_89B38_Field(privateData, void **, 0x14);
            temp_a1 = Level22_89B38_Field(temp_a3, short *, 2);
            temp_a0_2 = Level22_89B38_Field(temp_a3, short *, 0);
            {
                register int dividend3 __asm__("3");
                dividend3 = temp_a1 + 1;
                __asm__("" : "=r"(dividend3) : "0"(dividend3));
                nextIndex = dividend3 % temp_a0_2;
                dividend3 = temp_a0_2 - 1;
                __asm__("" : "=r"(dividend3) : "0"(dividend3));
                temp_a1 += dividend3;
                previousIndex = temp_a1 % temp_a0_2;
            }
            temp_v1 = (nextIndex * 0x10) + Level22_89B38_Field(temp_a3, int *, 0xC);
            temp_s0 = Level22_89B38_func_8004E880(Level22_89B38_Field(temp_v1, int *, 0) - moby->position.x, Level22_89B38_Field(temp_v1, int *, 4) - moby->position.y, 0);
            temp_v1_2 = (previousIndex * 0x10) + Level22_89B38_Field(Level22_89B38_Field(privateData, void **, 0x14), int *, 0xC);
            temp_s0_2 = Level22_89B38_func_8004E880(Level22_89B38_Field(temp_v1_2, int *, 0) - moby->position.x, Level22_89B38_Field(temp_v1_2, int *, 4) - moby->position.y, 0);
            temp_s0_3 = Level22_89B38_func_8004F264(temp_s1, temp_s0);
            if (Level22_89B38_func_8004F264(temp_s1, temp_s0_2) < temp_s0_3) {
                Level22_89B38_Field(Level22_89B38_Field(privateData, void **, 0x14), short *, 2) = (short) nextIndex;
            }
            else {
                Level22_89B38_Field(Level22_89B38_Field(privateData, void **, 0x14), short *, 2) = (short) previousIndex;
            }
            temp_v1_3 = Level22_89B38_Field(privateData, void **, 0x14);
            temp_v0 = (Level22_89B38_Field(temp_v1_3, short *, 2) * 0x10) + Level22_89B38_Field(temp_v1_3, int *, 0xC);
            {
                register int return2 __asm__("2");
                register int selector4 __asm__("4");
                register int selector5 __asm__("5");
                return2 = Level22_89B38_func_8004E880(Level22_89B38_Field(temp_v0, int *, 0) - moby->position.x, Level22_89B38_Field(temp_v0, int *, 4) - moby->position.y, 0);
                selector4 = 0;
                selector5 = 0x20;
                __asm__("" : "=r"(selector4), "=r"(selector5) : "0"(selector4), "1"(selector5));
                temp_s1_2 = return2;
                temp_s1_3 = temp_s1_2 + Level22_89B38_func_800363DC(selector4, selector5);
            }
            {
                register int x3 __asm__("3");
                register int y2 __asm__("2");
                register int delta4 __asm__("4");
                register int delta5 __asm__("5");
                register int zero6 __asm__("6");
                __asm__("" : "=r"(temp_s1_3) : "0"(temp_s1_3));
                zero6 = 0;
                x3 = moby->position.x;
                delta4 = Level22_89B38_D_80070328.position.x;
                y2 = moby->position.y;
                delta5 = Level22_89B38_D_80070328.position.y;
                delta4 = x3 - delta4;
                delta5 = y2 - delta5;
                temp_v0_2 = Level22_89B38_func_8004E880(delta4,delta5,zero6);
            }
            temp_v0_2 += (({ register int return2 __asm__("2"); register int coefficient3 __asm__("3"); register int product8 __asm__("8"); return2 = Level22_89B38_func_8003613C(temp_v0_2, temp_s1_3 & 0xFF); coefficient3 = 0x6C; __asm__("" : "=r"(coefficient3) : "0"(coefficient3)); product8 = return2 * coefficient3; __asm__("" : "=r"(product8) : "0"(product8)); { register int shifted2 __asm__("2"); shifted2 = product8 >> 7; __asm__("" : "=r"(shifted2) : "0"(shifted2)); shifted2; } }));
            __asm__("" : "=r"(temp_v0_2) : "0"(temp_v0_2));
            Level22_89B38_Field(privateData,unsigned char*,0x18) = temp_v0_2;
            {
                int randomResult = Level22_89B38_func_8003636C(0x6E, 0x8C);
                temp_v1_4 = Level22_89B38_Field(privateData, void **, 0x14);
                Level22_89B38_Field(privateData, unsigned char *, 0x1A) = randomResult;
            }
            Level22_89B38_Field(privateData, unsigned char *, 0x1B) = 0U;
            temp_v0_3 = (int) (Level22_89B38_func_8004F334(&moby->position, Level22_89B38_Field(temp_v1_4, int *, 0xC) + (Level22_89B38_Field(temp_v1_4, short *, 2) * 0x10)) / (int) Level22_89B38_Field(privateData, unsigned char *, 0x1A)) >> 1;
            Level22_89B38_Field(privateData, signed char *, 0x19) = (signed char) temp_v0_3;
            if ((unsigned int) (temp_v0_3 & 0xFF) >= 0x5BU) {
                Level22_89B38_Field(privateData, signed char *, 0x19) = 0x5A;
            }
            moby->state = 1;
            Level22_89B38_func_80034F40(moby, 1);
        }
        else if ((Level22_89B38_D_8006C770 != 0) && (moby->animationState.nextId != 0)) {
            Level22_89B38_D_8006C770 = 0;
            temp_v0_4 = moby->animationState.nextId;
            temp_a1_2 = moby->animationState.nextFrame;
            moby->animationProgress = 0x72;
            moby->animationState.nextId = 0;
            moby->animationState.nextFrame = 0;
            moby->animationState.id = temp_v0_4;
            moby->animationState.frame = temp_a1_2;
            Level22_89B38_func_80035734(moby);
        }
        goto commonCallbacks;
        default: goto commonCallbacks;
    case 1:
        temp_v0_5 = Level22_89B38_Field(privateData, void **, 0x14);
        temp_s0_4 = Level22_89B38_func_8004F334(&moby->position, Level22_89B38_Field(temp_v0_5, int *, 0xC) + (Level22_89B38_Field(temp_v0_5, short *, 2) * 0x10));
        temp_a0_3 = Level22_89B38_Field(privateData, unsigned char *, 0x1B);
        if (temp_a0_3 < (unsigned char) Level22_89B38_Field(privateData, unsigned char *, 0x1A)) {
            Level22_89B38_Field(privateData, unsigned char *, 0x1B) = (unsigned char) (temp_a0_3 + 0xA);
        }
        if (Level22_89B38_func_800359A4(privateData + 0x19, 1) != 0) {
            temp_v1_5 = Level22_89B38_Field(privateData, void **, 0x14);
            temp_v0_6 = (Level22_89B38_Field(temp_v1_5, short *, 2) * 0x10) + Level22_89B38_Field(temp_v1_5, int *, 0xC);
            temp_v0_7 = Level22_89B38_func_8003613C(Level22_89B38_func_8004E880(Level22_89B38_Field(temp_v0_6, int *, 0) - moby->position.x, Level22_89B38_Field(temp_v0_6, int *, 4) - moby->position.y, 0), (int) Level22_89B38_Field(privateData, unsigned char *, 0x18));
            __asm__("" : "=r"(temp_v0_7) : "0"(temp_v0_7));
            var_v0 = temp_v0_7;
            if (temp_v0_7 < 0) {
                var_v0 = -var_v0;
            }
            __asm__("" : "=r"(var_v0) : "0"(var_v0));
            var_a0 = 1;
            if (var_v0 >= 0x1F) {
                var_a0 = 2;
            }
            if (temp_v0_7 > 0) {
                var_v0_2 = Level22_89B38_Field(privateData, unsigned char *, 0x18) - var_a0;
                goto block_29;
            }
            if (temp_v0_7 < 0) {
                var_v0_2 = Level22_89B38_Field(privateData, unsigned char *, 0x18) + var_a0;
            block_29:
                Level22_89B38_Field(privateData, unsigned char *, 0x18) = var_v0_2;
            }
        }
        if (Level22_89B38_func_8003585C(moby, (int) Level22_89B38_Field(privateData, unsigned char *, 0x18), 5, 0x14, 1, 0) != 0) {
            if (Level22_89B38_func_80035DDC(moby, (int) Level22_89B38_Field(privateData, unsigned char *, 0x1B), 0x12C, 0x12C, 0x55) != 0) {
                Level22_89B38_Field(privateData, unsigned short *, 0x12) = (unsigned short) (Level22_89B38_Field(privateData, unsigned short *, 0x12) + 1);
            }
            else {
                Level22_89B38_Field(privateData, unsigned short *, 0x12) = 0U;
            }
            if ((short) Level22_89B38_Field(privateData, unsigned short *, 0x12) >= 4) {
                if (Level22_89B38_D_8006C770 != 0) {
                    if (temp_s0_4 < 0x1400) {
                        moby->state = 0;
                    }
                    else {
                        Level22_89B38_Field(privateData, unsigned char *, 0x18) = (unsigned char) (Level22_89B38_Field(privateData, unsigned char *, 0x18) + Level22_89B38_func_800363DC(0x3C, 0x64));
                    }
                }
                goto block_39;
            }
            else {
                var_v0_3 = temp_s0_4 < 0x708;
            }
        }
        else {
        block_39:
            var_v0_3 = temp_s0_4 < 0x708;
        }
        if ((var_v0_3 != 0) && (Level22_89B38_D_8006C770 != 0)) {
            moby->state = 0;
        }
        goto state2Callback;
    case 2:
        linkedMobyIndex = Level22_89B38_Field(privateData, int *, 0x24);
        if (linkedMobyIndex == -1) {
            Level22_89B38_Field(privateData, unsigned char *, 0x1A) = 0x64U;
            if (moby->animationState.nextId != 1) {
                Level22_89B38_func_80034F40(moby, 1);
            }
            temp_v0_8 = Level22_89B38_Field(privateData, void **, 0x14);
            Level22_89B38_func_8004F178(&originalFrame.sp18, Level22_89B38_Field(temp_v0_8, int *, 0xC) + (Level22_89B38_Field(temp_v0_8, short *, 2) * 0x10));
            temp_s0_5 = Level22_89B38_func_8004F334(&moby->position, &originalFrame.sp18);
            temp_a0_4 = Level22_89B38_Field(privateData, unsigned char *, 0x1B);
            if (temp_a0_4 < (unsigned char) Level22_89B38_Field(privateData, unsigned char *, 0x1A)) {
                Level22_89B38_Field(privateData, unsigned char *, 0x1B) = (unsigned char) (temp_a0_4 + 5);
            }
            temp_v0_9 = Level22_89B38_func_8003613C(Level22_89B38_func_8004E880((int) originalFrame.sp18.x - moby->position.x, originalFrame.sp18.y - moby->position.y, 0), (int) Level22_89B38_Field(privateData, unsigned char *, 0x18));
            __asm__("" : "=r"(temp_v0_9) : "0"(temp_v0_9));
            var_v0_4 = temp_v0_9;
            if (temp_v0_9 < 0) {
                var_v0_4 = -var_v0_4;
            }
            __asm__("" : "=r"(var_v0_4) : "0"(var_v0_4));
            var_a0_2 = 1;
            if (var_v0_4 >= 0x1F) {
                var_a0_2 = 2;
            }
            if (temp_v0_9 > 0) {
                var_v0_5 = Level22_89B38_Field(privateData, unsigned char *, 0x18) - var_a0_2;
                goto block_56;
            }
            if (temp_v0_9 < 0) {
                var_v0_5 = Level22_89B38_Field(privateData, unsigned char *, 0x18) + var_a0_2;
            block_56:
                Level22_89B38_Field(privateData, unsigned char *, 0x18) = var_v0_5;
            }
            if (Level22_89B38_func_8003585C(moby, (int) Level22_89B38_Field(privateData, unsigned char *, 0x18), 0xA, 0x14, 1, 0) != 0) {
                if (Level22_89B38_func_80035DDC(moby, (int) Level22_89B38_Field(privateData, unsigned char *, 0x1B), 0x12C, 0x12C, 0x55) != 0) {
                    Level22_89B38_Field(privateData, unsigned short *, 0x12) = (unsigned short) (Level22_89B38_Field(privateData, unsigned short *, 0x12) + 1);
                }
                else {
                    Level22_89B38_Field(privateData, unsigned short *, 0x12) = 0U;
                }
                if ((short) Level22_89B38_Field(privateData, unsigned short *, 0x12) >= 4) {
                    if (Level22_89B38_D_8006C770 != 0) {
                        if (temp_s0_5 < 0x1400) {
                            temp_a0_5 = Level22_89B38_Field(privateData, void **, 0x14);
                            temp_v1_7 = Level22_89B38_Field(temp_a0_5, short *, 2);
                            {
                                register int count2 __asm__("2");
                                register int previous5 __asm__("5");
                                register int next2 __asm__("2");
                                count2 = Level22_89B38_Field(temp_a0_5,short*,0);
                                previous5 = temp_v1_7;
                                __asm__("" : "=r"(previous5) : "0"(previous5));
                                {
                                    register int condition3 __asm__("3");
                                    condition3 = temp_v1_7 < count2 - 1;
                                    __asm__("" : "=r"(condition3) : "0"(condition3));
                                    next2 = previous5 + 1;
                                    if (condition3 == 0) {
                                        __asm__("" : "=r"(condition3) : "0"(condition3));
                                        next2 = 0;
                                    }
                                }
                                Level22_89B38_Field(temp_a0_5,short*,2) = next2;
                            }
                            Level22_89B38_Field(privateData, unsigned char *, 0x1B) = (unsigned char) ((unsigned char) Level22_89B38_Field(privateData, unsigned char *, 0x1A) >> 1);
                        }
                        else {
                            Level22_89B38_Field(privateData, unsigned char *, 0x18) = (unsigned char) (Level22_89B38_Field(privateData, unsigned char *, 0x18) + Level22_89B38_func_800363DC(0x3C, 0x64));
                        }
                    }
                    goto block_68;
                }
                else {
                    var_v0_6 = temp_s0_5 < 0x708;
                }
            }
            else {
            block_68:
                var_v0_6 = temp_s0_5 < 0x708;
            }
            if ((var_v0_6 != 0) && (Level22_89B38_D_8006C770 != 0)) {
                temp_a0_6 = Level22_89B38_Field(privateData, void **, 0x14);
                temp_v1_8 = Level22_89B38_Field(temp_a0_6, short *, 2);
                {
                    register int count2 __asm__("2");
                    register int previous5 __asm__("5");
                    register int next2 __asm__("2");
                    count2 = Level22_89B38_Field(temp_a0_6,short*,0);
                    previous5 = temp_v1_8;
                    __asm__("" : "=r"(previous5) : "0"(previous5));
                    {
                        register int condition3 __asm__("3");
                        condition3 = temp_v1_8 < count2 - 1;
                        __asm__("" : "=r"(condition3) : "0"(condition3));
                        next2 = previous5 + 1;
                        if (condition3 == 0) {
                            __asm__("" : "=r"(condition3) : "0"(condition3));
                            next2 = 0;
                        }
                    }
                    Level22_89B38_Field(temp_a0_6,short*,2) = next2;
                }
                Level22_89B38_Field(privateData, unsigned char *, 0x1B) = (unsigned char) ((unsigned char) Level22_89B38_Field(privateData, unsigned char *, 0x1A) >> 1);
            }
        state2Callback:
            Level22_89B38_func_80056270(moby);
            goto commonCallbacks;
        }
        if (Level22_89B38_D_8006C550[linkedMobyIndex].state != temp_a0) {
            moby->state = 0;
            return;
        }
        temp_v0_10 = moby->substate;
        if (temp_v0_10 == 0) {
            Level22_89B38_Field(privateData, unsigned short *, 0x12) = Level22_89B38_func_8003636C(0xA, 0x28);
            moby->substate = 1;
            return;
        }
        if (temp_v0_10 == 1) {
            if (Level22_89B38_func_800359A4(privateData + 0x12, 2) != 0) {
                moby->substate = 2;
                goto block_82;
            }
        }
        else {
        block_82:
            if (moby->animationState.nextId != 1) {
                Level22_89B38_func_80034F40(moby, 1);
            }
            Level22_89B38_Field(privateData, unsigned char *, 0x1A) = (unsigned char) Level22_89B38_Field(Level22_89B38_D_8006C550[Level22_89B38_Field(privateData, int *, 0x24)].mobyTag, unsigned char *, 0x1B);
            linkedPositionResult = Level22_89B38_func_8004F334(&moby->position, &Level22_89B38_D_8006C550[Level22_89B38_Field(privateData, int *, 0x24)].position);
            if ((linkedPositionResult + 0x100) < 0x400) {
                Level22_89B38_Field(privateData, unsigned char *, 0x1A) = (unsigned char) (Level22_89B38_Field(privateData, unsigned char *, 0x1A) - 0xA);
            }
            else {
                temp_v0_12 = linkedPositionResult - 0x400;
                if ((linkedPositionResult - 0x100) >= 0x401) {
                    var_v0_9 = (linkedPositionResult - 0x400) / 0x100;
                    {
                        register int step3 __asm__("3");
                        register unsigned int byte4 __asm__("4");
                        __asm__("" : "=r"(var_v0_9) : "0"(var_v0_9));
                        step3 = var_v0_9 << 2;
                        __asm__("" : "=r"(step3) : "0"(step3), "r"(var_v0_9));
                        byte4 = Level22_89B38_Field(privateData,unsigned char*,0x1A);
                        step3 += var_v0_9;
                        byte4 += step3;
                        Level22_89B38_Field(privateData,unsigned char*,0x1A) = byte4;
                    }
                }
            }
            currentByte1B = Level22_89B38_Field(privateData, unsigned char *, 0x1B);
            targetByte1A = Level22_89B38_Field(privateData, unsigned char *, 0x1A);
            currentByteMasked = currentByte1B & 0xFF;
            if (currentByteMasked < targetByte1A) nextByte1B = currentByte1B + 5;
            else if (targetByte1A < currentByteMasked) nextByte1B = currentByte1B - 5;
            else goto afterByteAdjustment;
            Level22_89B38_Field(privateData,unsigned char*,0x1B) = nextByte1B;
            afterByteAdjustment:;
            __asm__ volatile("" : : : "6");
            {
                register int index3 __asm__("3");
                register int delta4 __asm__("4");
                register int delta5 __asm__("5");
                register int zero6 __asm__("6");
                register Moby *base3 __asm__("3");
                register int offset2 __asm__("2");
                register Moby *record2 __asm__("2");
                register int x3 __asm__("3");
                register int y2 __asm__("2");
                zero6 = 0;
                index3 = Level22_89B38_Field(privateData,int*,0x24);
                delta4 = moby->position.x;
                delta5 = moby->position.y;
                offset2 = index3 * 11;
                base3 = Level22_89B38_D_8006C550;
                offset2 *= 8;
                record2 = (Moby *)(offset2 + (int)base3);
                __asm__("" : "=r"(record2) : "0"(record2));
                x3 = record2->position.x;
                y2 = record2->position.y;
                delta4 = x3 - delta4;
                delta5 = y2 - delta5;
                signedHelperResult = Level22_89B38_func_8003613C(Level22_89B38_func_8004E880(delta4,delta5,zero6), (int)Level22_89B38_Field(privateData,unsigned char*,0x18));
            }
            __asm__("" : "=r"(signedHelperResult) : "0"(signedHelperResult));
            if (signedHelperResult < 0) {
                absoluteHelperResult = signedHelperResult;
                __asm__("" : "=r"(absoluteHelperResult) : "0"(absoluteHelperResult));
                absoluteHelperResult = -absoluteHelperResult;
            }
            else absoluteHelperResult = signedHelperResult;
            __asm__("" : "=r"(absoluteHelperResult) : "0"(absoluteHelperResult));
            adjustmentStep = 1;
            if (absoluteHelperResult >= 0x1F) {
                adjustmentStep = 2;
            }
            if ((linkedPositionResult - 0x100) >= 0x401) {
                adjustmentStep += 1;
            }
            if (signedHelperResult > 0) {
                var_v0_12 = Level22_89B38_Field(privateData, unsigned char *, 0x18) - adjustmentStep;
                goto storeAdjustedByte18;
            }
            if (signedHelperResult < 0) {
                var_v0_12 = Level22_89B38_Field(privateData, unsigned char *, 0x18) + adjustmentStep;
            storeAdjustedByte18:
                Level22_89B38_Field(privateData, unsigned char *, 0x18) = var_v0_12;
            }
            Level22_89B38_func_8003585C(moby, (int) Level22_89B38_Field(privateData, unsigned char *, 0x18), 0xA, 0x14, 1, 0);
            if (Level22_89B38_func_80035DDC(moby, (int) Level22_89B38_Field(privateData, unsigned char *, 0x1B), 0x12C, 0x12C, 0x55) != 0) {
                Level22_89B38_Field(privateData, unsigned short *, 0x12) = (unsigned short) (Level22_89B38_Field(privateData, unsigned short *, 0x12) + 1);
            }
            else {
                Level22_89B38_Field(privateData, unsigned short *, 0x12) = 0U;
            }
            if (((short) Level22_89B38_Field(privateData, unsigned short *, 0x12) >= 4) && (Level22_89B38_D_8006C770 != 0)) {
                temp_s1_4 = Level22_89B38_func_800363DC(0x20, 0x40);
                temp_s0_6 = Level22_89B38_Field(privateData, unsigned char *, 0x18);
                if (Level22_89B38_rand() & 1) var_v0_13 = temp_s0_6 + temp_s1_4;
                else var_v0_13 = temp_s0_6 - temp_s1_4;
                Level22_89B38_Field(privateData, unsigned char *, 0x18) = var_v0_13;
            }
            goto commonCallbacks;
        }
        break;
    }
    return;
commonCallbacks:
    Level22_89B38_func_80035D38(moby);
    Level22_89B38_func_80056270(moby);
    return;
}
#undef Level22_89B38_Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_22/moby/func_level_22_8008A5D8.s SHA256 d2d49b284c4087a9c50837eda4d77942ef84c312e12307c87bc08fee4d65b3ca. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level22_8A5D8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Level22_8A5D8_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level22_8A5D8_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level22_8A5D8_D_8006C550 __asm__("D_8006C550");
extern unsigned char Level22_8A5D8_D_80070300[40] __asm__("D_80070300");
extern Spyro Level22_8A5D8_D_80070328 __asm__("D_80070328");
void Level22_8A5D8_func_80013B7C(int) __asm__("func_80013B7C");
void Level22_8A5D8_func_80013D44(Vector3D*, int, Vector3D*, int) __asm__("func_80013D44");
extern void Level22_8A5D8_func_80021ED8(int, char, char) __asm__("func_80021ED8");
extern int Level22_8A5D8_func_80021F3C(int) __asm__("func_80021F3C");
void Level22_8A5D8_func_80034F40(Moby* moby, int newId) __asm__("func_80034F40");
int Level22_8A5D8_func_800359A4(void*, int) __asm__("func_800359A4");
extern void Level22_8A5D8_func_800492DC(Vector3D*) __asm__("func_800492DC");
extern void Level22_8A5D8_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level22_8A5D8_func_8004F194(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level22_8A5D8_func_80055B18(Moby*) __asm__("func_80055B18");
extern int Level22_8A5D8_rand() __asm__("rand");

int Level22_8A5D8_func_80035A80() __asm__("func_80035A80");
 /* extern */
int Level22_8A5D8_func_800365E4() __asm__("func_800365E4");
 /* extern */
int Level22_8A5D8_func_80037BBC() __asm__("func_80037BBC");
                 /* extern */
int Level22_8A5D8_func_800512E4() __asm__("func_800512E4");
    /* extern */
extern int Level22_8A5D8_D_8006C58C __asm__("D_8006C58C");
extern int Level22_8A5D8_D_8006C640 __asm__("D_8006C640");
extern int Level22_8A5D8_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level22_8A5D8_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level22_8A5D8_D_8006E344 __asm__("D_8006E344");

void func_level_22_8008A5D8(Moby *inputOwner) {
    register Moby *owner __asm__("$17")=inputOwner;
    /* Original frame 0x58 and scratch offsets 0x20/0x30 are retained.
     * Signed LH table producers and 39*x >>6 operations are raw disc code.
     * Both callback sites and the shared final state store remain distinct.
     * Empty register constraints emit no instructions;
      they retain original
     * producer order, widths, load delays and helper-return liveness.
     * Units/fixed-point domains, cadence, helper meanings and synchronized
     * runtime chains remain unresolved. This establishes machine identity. */
    struct {int sp20;
     int sp24;
     int sp28;
     unsigned char pad2C[4];
     int sp30;
     int sp34;
     int sp38;
     unsigned char pad3C[4];
    } scratch;

    Moby *relatedMoby3;
    register Vector3D *ownerPosition19 __asm__("$19");
    int tableIndex;
    int tableIndex2;
    register int tableIndex20 __asm__("$20");
    register int damageFlags4 __asm__("$4");
    int unusedIndex;
    register int helperResult16 __asm__("$16");
    register int zero0 __asm__("$0");
    register int word2 __asm__("$2");
    register int trig3 __asm__("$3");
    register void *argument4 __asm__("$4");
    register void *argument5 __asm__("$5");
    register void *argument6 __asm__("$6");
    register void *scratch16 __asm__("$16");
    register void *relatedPrivate2 __asm__("$2");
    int tableBase;
    register int relatedIndex3 __asm__("$3");
    int tableBase2;
    signed char *spawnedParticle;
    register int damageState4 __asm__("$4");
    register int dispatchState3 __asm__("$3");
    unsigned char privateState;
    unsigned char unusedState;
    register int nextState2 __asm__("$2");
    void *relatedPrivate;
    void *privateTable;
    void *privateTable2;
    register void *ownerPrivate18 __asm__("$18");

    damageFlags4 = owner->damageFlags;
    ownerPrivate18 = owner->mobyTag;
    if ((damageFlags4 != 0) && (Level22_8A5D8_D_8006E344 != 1)) {
        if (damageFlags4 & 0x10000) {
            Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x2A) = 1U;
        }
        __asm__("" : : "r"(damageFlags4));
        damageState4 = owner->state;
        word2=3;
        __asm__("" : "=r"(damageState4):"0"(damageState4),"r"(word2));
        if ((damageState4 & 0xFF) != word2) {
            Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x28) = damageState4;
            Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x29) = (unsigned char) owner->animationState.nextId;
        }
        Level22_8A5D8_func_80034F40(owner, 2);
        owner->state = 3;
    }
    dispatchState3 = owner->state;
    owner->damageFlags = 0;
    switch (dispatchState3) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        if ((Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0) == 8) && !(Level22_8A5D8_D_8006C7B4 & 2) && (owner->substate == 2)) {
            Level22_8A5D8_D_8006C7B4 |= 2;
            Level22_8A5D8Field(owner->mobyTag, signed char *, 5) = 2;
            word2=owner->angle.yaw;
            word2*=2;
            trig3=Level22_8A5D8Field(&Level22_8A5D8_D_80065920,short*,word2);
            __asm__("" : "=r"(trig3):"0"(trig3):"$4");
            argument4=&scratch.sp20;
            __asm__("" : :"r"(argument4));
            word2=(trig3*39)>>6;
            scratch.sp20=word2;
            word2=owner->angle.yaw;
            __asm__("" : "=r"(word2):"0"(word2):"$5");
            argument5=argument4;
            __asm__("" : :"r"(argument5));
            word2*=2;
            trig3=Level22_8A5D8Field(&Level22_8A5D8_D_800658A0,short*,word2);
            word2=Level22_8A5D8_D_80070328.unk4a;
            __asm__("" : "=r"(word2):"0"(word2),"r"(trig3):"$6");
            argument6=&owner->position;
            *(volatile int*)&scratch.sp28=0;
            scratch.sp28=word2;
            word2=(trig3*39)>>6;
            scratch.sp24=word2;
            Level22_8A5D8_func_8004F194(argument4,argument5,argument6);
            Level22_8A5D8_func_80013D44((Vector3D *) &scratch.sp20, (owner->angle.yaw + 0x80) & 0xFF, 0, 0);
            if (Level22_8A5D8_D_80070328.currentHealth < 0) {
                Level22_8A5D8_D_80070328.currentHealth = 0;
            }
        }
        if ((Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0) != 0) || (!(Level22_8A5D8_D_8006C7B4 & 1) && !(Level22_8A5D8_D_80070300[Level22_8A5D8_D_8006C58C] & 1)) || (Level22_8A5D8_D_8006C640 != 0)) {
            if (Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0) == 2) {
                if ((Level22_8A5D8_D_8006C7B4 & 1) || (Level22_8A5D8_D_80070300[Level22_8A5D8_D_8006C58C] & 1)) {
                    if (owner->substate == 0) {
                        Level22_8A5D8Field(Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18, int *, 0x30)].mobyTag, int *, 8) = 0;
                        Level22_8A5D8Field(Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18, int *, 0x40)].mobyTag, int *, 8) = 0;
                        word2=Level22_8A5D8_func_80021F3C(1);
                        if (!((word2>>8)&255)) {
                            Level22_8A5D8_func_80021ED8(1, -4, 0);
                        }
                        goto call55B18;
                    }
                    goto finishRelatedCheck;
                }
                word2=Level22_8A5D8Field(ownerPrivate18,int*,0x2C);
                argument4=Level22_8A5D8_D_8006C550;
                relatedIndex3=word2*88;
                relatedIndex3+=(int)argument4;
                relatedMoby3=(Moby*)relatedIndex3;
                if (relatedMoby3->state & 0x80) {
                    if (owner->substate == 0) {
                        owner->substate = 1;
                        Level22_8A5D8Field(owner->mobyTag, signed char *, 5) = 2;
                        word2=owner->angle.yaw;
            scratch16=&scratch.sp30;
            word2*=2;
            trig3=Level22_8A5D8Field(&Level22_8A5D8_D_80065920,short*,word2);
            __asm__("" : "=r"(trig3):"0"(trig3):"$4");
            argument4=scratch16;
            __asm__("" : :"r"(argument4));
            word2=(trig3*39)>>6;
            scratch.sp30=word2;
            word2=owner->angle.yaw;
            __asm__("" : "=r"(word2):"0"(word2):"$5");
            argument5=scratch16;
            __asm__("" : :"r"(argument5));
            word2*=2;
            trig3=Level22_8A5D8Field(&Level22_8A5D8_D_800658A0,short*,word2);
            word2=Level22_8A5D8_D_80070328.unk4a;
            __asm__("" : "=r"(word2):"0"(word2),"r"(trig3):"$6");
            argument6=&owner->position;
            *(volatile int*)&scratch.sp38=0;
            scratch.sp38=word2;
            word2=(trig3*39)>>6;
            scratch.sp34=word2;
            Level22_8A5D8_func_8004F194(argument4,argument5,argument6);
            Level22_8A5D8_func_80013D44((Vector3D *) &scratch.sp30, (owner->angle.yaw + 0x80) & 0xFF, 0, 0);
                        if (Level22_8A5D8_D_80070328.currentHealth < 0) {
                            Level22_8A5D8_D_80070328.currentHealth = 0;
                        }
                    }
                } else if ((Level22_8A5D8Field(ownerPrivate18, unsigned char *, 2) == 0) && ((relatedPrivate = relatedMoby3->mobyTag, ((Level22_8A5D8_D_8006C550[Level22_8A5D8Field(relatedPrivate, int *, 4)].state & 0x80) != 0)) || (Level22_8A5D8_D_8006C550[Level22_8A5D8Field(relatedPrivate, int *, 0xC)].state & 0x80))) {
                    Level22_8A5D8Field(ownerPrivate18, unsigned char *, 2) = 1U;
                }
finishRelatedCheck:
                goto checkInteraction;
            }
checkInteraction:
            if (((Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0) != 8) || (owner->substate != 1)) && (Level22_8A5D8_func_80037BBC(owner, 0) != 0)) {
                if ((Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0) == 2) && (Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18, int *, 0x2C)].state & 0x80)) {
                    if (!(Level22_8A5D8_D_8006C7B4 & 1)) {
                        owner->substate = 1;
                        Level22_8A5D8_D_8006C7B4 |= 1;
                    }
                }
                word2=Level22_8A5D8_func_800512E4(owner,0,1);
                __asm__ volatile("" : :"r"(word2));
                nextState2=1;
                goto storeOwnerState;
            }
        default:                                    /* switch 1 */
            return;
        }
        goto call55B18;
    case 1:                                         /* switch 1 */
        if (Level22_8A5D8_D_8006E344 != 1) {
            Level22_8A5D8_func_80034F40(owner, 0);
            privateState = Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0);
            if ((privateState == 2) && (Level22_8A5D8Field(ownerPrivate18, unsigned char *, 4) == privateState)) {
                Level22_8A5D8Field(Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18, int *, 0x30)].mobyTag, int *, 8) = 0;
                relatedPrivate2=Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18,int*,0x40)].mobyTag;
                Level22_8A5D8Field(relatedPrivate2,int*,8)=0;
                __asm__("" : : "r"(relatedPrivate2),"m"(Level22_8A5D8Field(relatedPrivate2,int*,8)): "$2");
                word2=0x3C;
                Level22_8A5D8Field(ownerPrivate18,unsigned char*,0x2B)=word2;
                __asm__("" : :"m"(Level22_8A5D8Field(ownerPrivate18,unsigned char*,0x2B)):"$2");
                nextState2=0x14;
                goto storeOwnerState;
            }
            owner->state = 0;
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        if (Level22_8A5D8_func_800359A4(ownerPrivate18 + 0x2B, 1) != 0) {
            if (owner->substate == 1) {
                Level22_8A5D8Field(Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18, int *, 0x30)].mobyTag, int *, 8) = 0;
                Level22_8A5D8Field(Level22_8A5D8_D_8006C550[Level22_8A5D8Field(ownerPrivate18, int *, 0x40)].mobyTag, int *, 8) = 0;
                Level22_8A5D8_func_80021ED8(0, -4, 0);
                owner->substate = 2;
                Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x2B) = 0xB4;
                return;
            }
            Level22_8A5D8_func_80013B7C(1);
            __asm__ volatile("" : "=r"(zero0));
            word2=Level22_8A5D8_func_800512E4(owner,zero0,1);
            __asm__ volatile("" : :"r"(word2));
            nextState2=1;
            goto storeOwnerState;
        }
        break;
    case 20:                                        /* switch 1 */
        if (Level22_8A5D8_func_800359A4(ownerPrivate18 + 0x2B, 1) != 0) {
            owner->substate = 0;
            Level22_8A5D8_func_80034F40(owner, 3);
            owner->state = 0x15;
        }
        goto setSpyroControlAndCall492DC;
    case 21:                                        /* switch 1 */
        unusedState = owner->substate;
        tableIndex20 = Level22_8A5D8Field(Level22_8A5D8Field(ownerPrivate18, void **, 0x34), short *, 2);
        switch (unusedState) {                        /* switch 2;
         irregular */
        case 0:                                     /* switch 2 */
            if (Level22_8A5D8_func_80035A80(owner, Level22_8A5D8Field(ownerPrivate18, void **, 0x34), 0x200, 0x80, 0, 8, 0xC, 5) & 1) {
                privateTable = Level22_8A5D8Field(ownerPrivate18, void **, 0x34);
                tableIndex = Level22_8A5D8Field(privateTable, short *, 2);
                if (tableIndex != 0) {
                    tableBase = Level22_8A5D8Field(privateTable, int *, 0xC);
                    if (Level22_8A5D8Field(((tableIndex20 * 0x10) + tableBase), int *, 0xC) & 1) {
                        Level22_8A5D8Field(ownerPrivate18, int *, 0x3C) = Level22_8A5D8_func_800365E4(&owner->position, tableBase + (tableIndex * 0x10), 0x80, -0xC, 0);
                        owner->substate = 1;
                    }
                    goto setSpyroControlAndCall492DC;
                }
                goto call55B18;
            }
            goto setSpyroControlAndCall492DC;
        case 1:                                     /* switch 2 */
            word2=Level22_8A5D8_func_80035A80(owner,Level22_8A5D8Field(ownerPrivate18,void**,0x34),0x200,0x80,0,8,0xC,0);
            argument4=&scratch.sp30;
            __asm__("" : :"r"(argument4));
            ownerPosition19=&owner->position;
            __asm__("" : :"r"(ownerPosition19):"$6");
            argument6=(void*)Level22_8A5D8Field(ownerPrivate18,int*,0x3C);
            __asm__("" : "=r"(argument6):"0"(argument6):"$5");
            argument5=ownerPosition19;
            __asm__("" : :"r"(argument5));
            argument6=(void*)((int)argument6-12);
            Level22_8A5D8Field(ownerPrivate18,int*,0x3C)=(int)argument6;
            trig3=owner->position.z;
            __asm__("" : "=r"(trig3):"0"(trig3),"r"(word2):"$16");
            helperResult16=word2;
            trig3+=(int)argument6;
            owner->position.z=trig3;
            Level22_8A5D8_func_8004F178(argument4,argument5);
            scratch.sp38 += 0x200;
            __asm__("" : "=r"(helperResult16):"0"(helperResult16),"m"(scratch.sp38));
            word2=helperResult16&1;
            __asm__("" : :"r"(helperResult16));
            if(word2) {
                privateTable2 = Level22_8A5D8Field(ownerPrivate18, void **, 0x34);
                tableIndex2 = Level22_8A5D8Field(privateTable2, short *, 2);
                if (tableIndex2 == 0) {
call55B18:
                    Level22_8A5D8_func_80055B18(owner);
                    return;
                }
                tableBase2 = Level22_8A5D8Field(privateTable2, int *, 0xC);
                if (Level22_8A5D8Field(((tableIndex20 * 0x10) + tableBase2), int *, 0xC) & 1) {
                    Level22_8A5D8Field(ownerPrivate18, int *, 0x3C) = Level22_8A5D8_func_800365E4(ownerPosition19, tableBase2 + (tableIndex2 * 0x10), 0x80, -0xC, 0);
                }
                goto setSpyroControlAndCall492DC;
            }
            goto setSpyroControlAndCall492DC;
        default:
            goto setSpyroControlAndCall492DC;
        }
setSpyroControlAndCall492DC:
        Level22_8A5D8_D_80070328.unk17a=0x10000002;
        Level22_8A5D8_func_800492DC(&owner->position);
        return;
    case 3:                                         /* switch 1 */
        if (Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x2A) != 0) {
            scratch.sp30 = (Level22_8A5D8_rand() & 0xF) - 8;
            scratch.sp34 = (Level22_8A5D8_rand() & 0xF) - 8;
            scratch.sp38 = (Level22_8A5D8_rand() & 0xF) + 8;
            spawnedParticle = SpawnParticle(1, 0x37, &owner->position, (Vector3D *) &scratch.sp30);
            if (spawnedParticle != 0) {
                Level22_8A5D8Field(spawnedParticle, unsigned short *, 8) = (unsigned short) (Level22_8A5D8Field(spawnedParticle, unsigned short *, 8) + (Level22_8A5D8_rand() & 0xFF));
            }
        }
        if (Level22_8A5D8_D_8006C770 != 0) {
            Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x2A) = 0U;
            Level22_8A5D8_func_80034F40(owner, (int) Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x29));
            nextState2 = Level22_8A5D8Field(ownerPrivate18, unsigned char *, 0x28);
            goto storeOwnerState;
        }
        break;
    }
    return;
storeOwnerState:
    owner->state=nextState2;
}
#undef Level22_8A5D8Field


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
void func_level_22_8008AF54(Moby* argument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 original806 words. AI generated, not human reviewed; uninstalled. */
#define Level22_8B154Field(p, t, o) (*(t)((unsigned char *)(p) + (o)))
#define Level22_8B154Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level22_8B154_func_80013ACC() __asm__("func_80013ACC");
int Level22_8B154_func_8001C288() __asm__("func_8001C288");
int Level22_8B154_func_80034F40() __asm__("func_80034F40");
int Level22_8B154_func_80035194() __asm__("func_80035194");
int Level22_8B154_func_8003573C() __asm__("func_8003573C");
int Level22_8B154_func_8003585C() __asm__("func_8003585C");
int Level22_8B154_func_800359A4() __asm__("func_800359A4");
int Level22_8B154_func_80035D38() __asm__("func_80035D38");
int Level22_8B154_func_800369B8() __asm__("func_800369B8");
int Level22_8B154_func_80036A68() __asm__("func_80036A68");
int Level22_8B154_func_80038BF8() __asm__("func_80038BF8");
int Level22_8B154_func_800391E8() __asm__("func_800391E8");
int Level22_8B154_func_80039714() __asm__("func_80039714");
int Level22_8B154_func_8003BA00() __asm__("func_8003BA00");
int Level22_8B154_func_8003BABC() __asm__("func_8003BABC");
int Level22_8B154_func_8003BE70() __asm__("func_8003BE70");
int Level22_8B154_func_8003BFC0() __asm__("func_8003BFC0");
int Level22_8B154_func_8004E880() __asm__("func_8004E880");
int Level22_8B154_func_8004F264() __asm__("func_8004F264");
int Level22_8B154_func_8004F334() __asm__("func_8004F334");
int Level22_8B154_func_80055B18() __asm__("func_80055B18");
int Level22_8B154_func_80055D24() __asm__("func_80055D24");
int Level22_8B154_func_80056270() __asm__("func_80056270");
extern int Level22_8B154_D_8006C550 __asm__("D_8006C550");
extern int Level22_8B154_D_8006C770 __asm__("D_8006C770");
extern int Level22_8B154_D_8006E020 __asm__("D_8006E020");
extern int Level22_8B154_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level22_8B154_D_8006E040 __asm__("D_8006E040");
extern int Level22_8B154_D_8006E160 __asm__("D_8006E160");
extern int Level22_8B154_D_8006E164 __asm__("D_8006E164");
extern int Level22_8B154_D_80070328 __asm__("D_80070328");
extern int (*Level22_8B154_unk_ovlheader_800743F0)() __asm__("unk_ovlheader_800743F0");
extern int (*Level22_8B154_unk_ovlheader_80074414)() __asm__("unk_ovlheader_80074414");
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Level22_8B154Product;
#define Level22_8B154Low(a, b)                                                                     \
    ({                                                                                             \
        int x = (a), y = (b);                                                                      \
        Level22_8B154Product p;                                                                    \
        p.full = (long long)x * (long long)y;                                                      \
        __asm__("" : "=x"(p.full) : "0"(p.full));                                                  \
        (int)p.words.low;                                                                          \
    })
void func_level_22_8008B154(void *ownerInput) {
    register int owner __asm__("$18");
    register int privateState __asm__("$19");
    register int saved16 __asm__("$16");
    register int saved17 __asm__("$17");
    register int saved20 __asm__("$20");
    register int scratch3 __asm__("$3");
    register int result __asm__("$2");
    register int argument0 __asm__("$4");
    register int argument1 __asm__("$5");

    int temp_v0;

    int temp_v0_5;
    int temp_v0_6;

    int temp_v0_9;
    int temp_v1;

    int temp_v1_12;

    int temp_v1_8;

    int temp_v0_7;
    int temp_v1_6;
    int temp_v1_7;

    int temp_a1;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v1_10;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_9;
    __asm__("" : "=r"(saved20)::"$31");
    owner = (int)ownerInput;
    Level22_8B154Keep(owner);
    privateState = *((int *)(((unsigned char *)owner) + 0));
    if (((unsigned char)(*((unsigned char *)(((unsigned char *)owner) + 0x3C)))) >= 8U) {
        Level22_8B154_func_80039714(ownerInput);
        return;
    }
    if (((*((int *)(((unsigned char *)owner) + 0x18))) != 0) &&
        ((*((unsigned char *)(((unsigned char *)owner) + 0x48))) != 5)) {
        scratch3 = (int)&Level22_8B154_D_8006E164;
        Level22_8B154Keep(scratch3);
        result = Level22_8B154Field(scratch3, int *, 0);
        if (result == owner) {
            Level22_8B154_D_8006E160 = 0;
            Level22_8B154Field(scratch3, int *, 0) = 0;
        }
        Level22_8B154_func_80038BF8(owner, privateState, 1, 5);
        *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 5U;
        Level22_8B154_func_800391E8(1, 0x16D, owner, 8, 8, 0xA4, 0x100);
        Level22_8B154_func_800391E8(1, 0x16D, owner, 9, 9, 0xA4, 0x100);
        Level22_8B154_func_800391E8(1, 0x16D, owner, 0xA, 0xA, 0xA4, 0x100);
        Level22_8B154_func_80036A68(owner, 0, 0, 0);
        temp_v1 = *((int *)(((unsigned char *)privateState) + 0x44));
        if (temp_v1 != (-1)) {
            temp_v1_2 = (temp_v1 * 0x58) + Level22_8B154_D_8006C550;
            if (!((*((unsigned char *)(((unsigned char *)temp_v1_2) + 0x48))) & 0x80)) {
                *((unsigned char *)(((unsigned char *)temp_v1_2) + 0x48)) = 1U;
            }
        }
    }
    *((int *)(((unsigned char *)owner) + 0x18)) = 0;
    result = Level22_8B154Field(privateState, int *, 0x20);
    Level22_8B154Keep(result);
    saved16 = (int)&Level22_8B154_D_80070328;
    Level22_8B154Keep(saved16);
    result = Level22_8B154_func_8004F334(saved16, Level22_8B154Field(result, int *, 0xC));
    argument0 = saved16;
    Level22_8B154Keep(argument0);
    scratch3 = Level22_8B154Field(privateState, int *, 0x20);
    saved16 = result;
    argument1 = Level22_8B154Field(scratch3, short *, 0);
    scratch3 = Level22_8B154Field(scratch3, int *, 0xC);
    argument1 = argument1 * 16 - 16;
    if (Level22_8B154_func_8004F334(argument0, scratch3 + argument1) < saved16) {
        *((short *)(((unsigned char *)(*((int *)(((unsigned char *)privateState) + 0x20)))) + 2)) =
            0;
    } else {
        temp_v1_4 = *((int *)(((unsigned char *)privateState) + 0x20));
        *((short *)(((unsigned char *)temp_v1_4) + 2)) =
            (short)(((unsigned short)(*((short *)(((unsigned char *)temp_v1_4) + 0)))) - 1);
    }
    if ((*((unsigned char *)(((unsigned char *)owner) + 0x3C))) == 2) {
        if (Level22_8B154_func_8003BFC0(owner,
                                        *((int *)(((unsigned char *)privateState) + 0x40))) == 0) {
            *((int *)(((unsigned char *)privateState) + 0x40)) =
                Level22_8B154_func_8003BABC(owner, 0, 4);
        }
    } else {
        if (Level22_8B154_func_8003BFC0(owner,
                                        *((int *)(((unsigned char *)privateState) + 0x40))) != 0) {
            Level22_8B154_func_8003BE70(*((int *)(((unsigned char *)privateState) + 0x40)));
        }
        *((int *)(((unsigned char *)privateState) + 0x40)) = -1;
    }
    if (((*((int *)(((unsigned char *)privateState) + 0x44))) != (-1)) &&
        (Level22_8B154_unk_ovlheader_80074414(*((int *)(((unsigned char *)privateState) + 0x24)),
                                              (int)(&Level22_8B154_D_80070328)) == 0)) {
        temp_v1_5 = ((*((int *)(((unsigned char *)privateState) + 0x44))) * 0x58) +
                    Level22_8B154_D_8006C550;
        if ((!((*((unsigned char *)(((unsigned char *)temp_v1_5) + 0x48))) & 0x80)) &&
            (((unsigned int)((*((unsigned char *)(((unsigned char *)owner) + 0x48))) - 5)) >= 3U)) {
            *((unsigned char *)(((unsigned char *)temp_v1_5) + 0x48)) = 2U;
            temp_v1_6 = *((unsigned char *)(((unsigned char *)owner) + 0x3C));
            *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 0x1EU;
            if (temp_v1_6 == 0) {
                argument0 = owner;
                Level22_8B154Keep(argument0);
                argument1 = 1;
                goto block_27;
            }
            if (temp_v1_6 == 1) {
                result = Level22_8B154_D_8006C770;
                __asm__("" : "=r"(result) : "0"(result) : "$4");
                if (result != 0) {
                    argument0 = owner;
                    argument1 = 2;
                block_27:
                    Level22_8B154_func_80034F40(argument0, argument1);
                }
            }
        }
    }
    temp_v1_7 = *((unsigned char *)(((unsigned char *)owner) + 0x48));
    switch (temp_v1_7) {
    case 0:
        Level22_8B154_func_8003573C(owner, 6, 0, 1);
        if (Level22_8B154_func_8004F334(owner + 0xC, (int)(&Level22_8B154_D_80070328)) <
            (*((int *)(((unsigned char *)privateState) + 0x18)))) {
            temp_v1_8 = (*((int *)(((unsigned char *)owner) + 0x14))) -
                        (*((short *)(((unsigned char *)owner) + 0x38)));
            temp_v0 =
                temp_v1_8 - (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 8)));
            if (temp_v0 >= 0) {
                if (temp_v0 < 0xC00)
                    goto block_35;
                goto block_45;
            }
            if (((*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 8))) -
                 temp_v1_8) < 0xC00) {
            block_35:
                if ((((Level22_8B154_func_8004F264(
                           ((int)(Level22_8B154_D_8006E040 << 0x10)) >> 0x14,
                           Level22_8B154_func_8004E880(
                               (*((int *)(((unsigned char *)owner) + 0xC))) -
                                   (*((int *)(((unsigned char *)((
                                                  int)(&Level22_8B154_D_8006E020))) +
                                              0))),
                               (*((int *)(((unsigned char *)owner) + 0x10))) -
                                   Level22_8B154_D_8006E024,
                               0)) < 0x1C) &&
                      (((unsigned int)((*((int *)(((unsigned char *)((
                                                      int)(&Level22_8B154_D_80070328))) +
                                                  0x50))) -
                                       7)) >= 2U)) &&
                     ((*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 0x240))) ==
                      0)) &&
                    (Level22_8B154_unk_ovlheader_80074414(
                         *((int *)(((unsigned char *)privateState) + 0x24)),
                         (((int)(&Level22_8B154_D_80070328)) + 0x50) - 0x50) != 0)) {
                    if (((Level22_8B154_D_8006E160 == 0) || (Level22_8B154_D_8006E164 == 0)) ||
                        ((*((short *)(((unsigned char *)Level22_8B154_D_8006E164) + 0x36))) !=
                         0x16D)) {
                        Level22_8B154_func_80013ACC(owner, 0xC);
                    }
                    if (Level22_8B154_func_8004F264(
                            ((int)(Level22_8B154_D_8006E040 << 0x10)) >> 0x14,
                            Level22_8B154_func_8004E880(
                                (*((int *)(((unsigned char *)owner) + 0xC))) -
                                    (*((int *)(((unsigned char *)((
                                                   int)(&Level22_8B154_D_8006E020))) +
                                               0))),
                                (*((int *)(((unsigned char *)owner) + 0x10))) -
                                    Level22_8B154_D_8006E024,
                                0)) < 0x18) {
                        *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 1U;
                        Level22_8B154_func_80034F40(owner, 1);
                        return;
                    }
                } else {
                    goto block_45;
                }

            } else {
                goto block_45;
            }
        } else {
        block_45:
            scratch3 = (int)&Level22_8B154_D_8006E164;
            Level22_8B154Keep(scratch3);
            result = Level22_8B154Field(scratch3, int *, 0);
            if (result == owner) {
                Level22_8B154_D_8006E160 = 0;
                Level22_8B154Field(scratch3, int *, 0) = 0;
            }

            temp_v0_2 = *((int *)(((unsigned char *)privateState) + 0x20));
            if (Level22_8B154_func_8004F334(
                    owner + 0xC, (*((int *)(((unsigned char *)temp_v0_2) + 0xC))) +
                                     ((*((short *)(((unsigned char *)temp_v0_2) + 2))) * 0x10)) >=
                0x401) {
                Level22_8B154_func_80034F40(owner, 1);
                *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 0x14U;
                return;
            }
        default:
            return;
        }
        goto actor806_return;

    case 20:
        if (Level22_8B154_D_8006C770 != 0) {
            Level22_8B154_func_80034F40(owner, 2);
            *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 0x15U;
            return;
        }
        goto actor806_return;

    case 1:
        if (Level22_8B154_D_8006C770 != 0) {
            result = 2;
            goto block_102;
        }
        result = 2;
        Level22_8B154Keep(result);
        goto actor806_return;

    case 2:

    case 21:
        *((int *)(((unsigned char *)owner) + 0x14)) =
            (int)((*((int *)(((unsigned char *)owner) + 0x14))) + 0x180);
        if (Level22_8B154_func_8001C288(owner + 0xC, 0x190, 0) != 0) {
            *((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 0x24)) =
                (int)((*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 0x24))) |
                      0x10);
            *((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 0x298)) =
                (int)(*((unsigned char *)(((unsigned char *)owner) + 0x46)));
            if ((*((unsigned char *)(((unsigned char *)owner) + 0x48))) != 0x15) {
                result = 15;
                Level22_8B154Field(privateState, signed char *, 0x2D) = result;
                result = 180;
                scratch3 = (int)&Level22_8B154_D_8006E164;
                Level22_8B154Keep(scratch3);
                Level22_8B154Field(privateState, short *, 0x2E) = result;
                result = Level22_8B154Field(scratch3, int *, 0);
                if (result == owner) {
                    Level22_8B154_D_8006E160 = 0;
                    Level22_8B154Field(scratch3, int *, 0) = 0;
                }
                *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 0x15U;
            }
        }
        *((int *)(((unsigned char *)owner) + 0x14)) =
            (int)((*((int *)(((unsigned char *)owner) + 0x14))) - 0x180);
        if ((*((unsigned char *)(((unsigned char *)owner) + 0x48))) == 0x15) {
            if (Level22_8B154_func_800359A4(privateState + 0x2D, 1) != 0) {
                temp_v1_9 = *((int *)(((unsigned char *)privateState) + 0x20));
                temp_v0_3 = ((*((short *)(((unsigned char *)temp_v1_9) + 2))) * 0x10) +
                            (*((int *)(((unsigned char *)temp_v1_9) + 0xC)));
                *((unsigned char *)(((unsigned char *)privateState) + 0x2C)) =
                    Level22_8B154_func_8004E880((*((int *)(((unsigned char *)temp_v0_3) + 0))) -
                                                    (*((int *)(((unsigned char *)owner) + 0xC))),
                                                (*((int *)(((unsigned char *)temp_v0_3) + 4))) -
                                                    (*((int *)(((unsigned char *)owner) + 0x10))),
                                                0);
                temp_v1_10 = *((int *)(((unsigned char *)privateState) + 0x20));
                if (Level22_8B154_func_8004F334(
                        owner + 0xC,
                        (*((int *)(((unsigned char *)temp_v1_10) + 0xC))) +
                            ((*((short *)(((unsigned char *)temp_v1_10) + 2))) * 0x10)) < 0x200) {
                    if ((*((short *)(((unsigned char *)privateState) + 0x2E))) != 0) {
                        *((short *)(((unsigned char *)privateState) + 0x2E)) = 0;
                        goto block_67;
                    }
                    *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 3U;
                    Level22_8B154_func_80034F40(owner, 3);
                    return;
                }
            }
            goto block_67;
        }
        *((unsigned char *)(((unsigned char *)privateState) + 0x2C)) = Level22_8B154_func_8004E880(
            (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 0))) -
                (*((int *)(((unsigned char *)owner) + 0xC))),
            (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 4))) -
                (*((int *)(((unsigned char *)owner) + 0x10))),
            0);
        if (((*((short *)(((unsigned char *)privateState) + 0x3A))) == 0) &&
            (Level22_8B154_func_8004F334(owner + 0xC, (int)(&Level22_8B154_D_80070328)) < 0xC00)) {
            *((short *)(((unsigned char *)privateState) + 0x3A)) = 1;
            *((short *)(((unsigned char *)privateState) + 0x38)) = 0x1E;
        }
    block_67:
        if (!((*((int *)(((unsigned char *)privateState) + 0x30))) & 0x3000)) {
            Level22_8B154_func_8003585C(
                owner, *((unsigned char *)(((unsigned char *)privateState) + 0x2C)), 4, 0, 1, 0);
            saved16 = *((unsigned char *)(((unsigned char *)owner) + 0x46));
        } else {
            saved16 = *((unsigned char *)(((unsigned char *)privateState) + 0x2C));
            *((int *)(((unsigned char *)privateState) + 0x34)) = 0;
        }

        scratch3 = *((int *)(((unsigned char *)privateState) + 0x34));
        saved17 = *((unsigned char *)(((unsigned char *)owner) + 0x46));
        if (scratch3 < 0xE0) {
            result = scratch3 + 0x28;
            *((int *)(((unsigned char *)privateState) + 0x34)) = result;
            if (result >= 0xE1) {
                *((int *)(((unsigned char *)privateState) + 0x34)) = 0xE0;
            }
        }
        if ((*((short *)(((unsigned char *)privateState) + 0x3A))) != 0) {
            temp_v0_5 = Level22_8B154_func_80035D38(owner);
            *((int *)(((unsigned char *)owner) + 0x14)) =
                (int)((*((int *)(((unsigned char *)owner) + 0x14))) +
                      (*((short *)(((unsigned char *)privateState) + 0x38))));
            *((short *)(((unsigned char *)privateState) + 0x38)) =
                (short)(((unsigned short)(*((short *)(((unsigned char *)privateState) + 0x38)))) -
                        0x1E);
            saved20 = *((int *)(((unsigned char *)owner) + 0x14));
            if (saved20 < temp_v0_5) {
                *((short *)(((unsigned char *)privateState) + 0x3A)) = 0;
                *((short *)(((unsigned char *)privateState) + 0x38)) = 0;
                *((int *)(((unsigned char *)owner) + 0x14)) = temp_v0_5;
            }
        }
        *((int *)(((unsigned char *)privateState) + 0x30)) = Level22_8B154_unk_ovlheader_800743F0(
            owner, saved16, 0xE0, 0x200, 0x200, 0x27, privateState + 0x24, 1,
            *((int *)(((unsigned char *)privateState) + 0x28)));
        if ((*((short *)(((unsigned char *)privateState) + 0x3A))) != 0) {
            *((int *)(((unsigned char *)owner) + 0x14)) = saved20;
        }
        if ((*((unsigned char *)(((unsigned char *)owner) + 0x46))) != saved17) {
            *((int *)(((unsigned char *)privateState) + 0x30)) =
                (int)((*((int *)(((unsigned char *)privateState) + 0x30))) | 0x1000);
        }
        if (((Level22_8B154_func_8004F264(
                  ((int)((*((unsigned short
                                 *)(((unsigned char *)((int)(&Level22_8B154_D_8006E020))) + 0x20)))
                         << 0x10)) >>
                      0x14,
                  Level22_8B154_func_8004E880(
                      (*((int *)(((unsigned char *)owner) + 0xC))) -
                          (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_8006E020))) + 0))),
                      (*((int *)(((unsigned char *)owner) + 0x10))) -
                          (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_8006E020))) + 4))),
                      0)) >= 0x21) ||
             (((unsigned int)((*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) +
                                         0x50))) -
                              7)) < 2U)) ||
            (Level22_8B154_unk_ovlheader_80074414(
                 *((int *)(((unsigned char *)privateState) + 0x24)),
                 (((int)(&Level22_8B154_D_80070328)) + 0x50) - 0x50) == 0)) {
            if ((*((unsigned char *)(((unsigned char *)owner) + 0x48))) != 0x15) {
                result = 15;
                Level22_8B154Field(privateState, signed char *, 0x2D) = result;
                result = 180;
                scratch3 = (int)&Level22_8B154_D_8006E164;
                Level22_8B154Keep(scratch3);
                Level22_8B154Field(privateState, short *, 0x2E) = result;
                result = Level22_8B154Field(scratch3, int *, 0);
                if (result == owner) {
                    Level22_8B154_D_8006E160 = 0;
                    Level22_8B154Field(scratch3, int *, 0) = 0;
                }
                result = 0x15;
                goto block_95;
            }
        } else if ((Level22_8B154_func_800359A4(privateState + 0x2E, 2) != 0) &&
                   (Level22_8B154_func_8004F264(
                        ((int)((*((unsigned short *)(((unsigned char *)((
                                                         int)(&Level22_8B154_D_8006E020))) +
                                                     0x20)))
                               << 0x10)) >>
                            0x14,
                        Level22_8B154_func_8004E880(
                            (*((int *)(((unsigned char *)owner) + 0xC))) -
                                (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_8006E020))) +
                                           0))),
                            (*((int *)(((unsigned char *)owner) + 0x10))) -
                                (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_8006E020))) +
                                           4))),
                            0)) < 0x1C)) {
            temp_v1_12 = (*((int *)(((unsigned char *)owner) + 0x14))) -
                         (*((short *)(((unsigned char *)owner) + 0x38)));
            temp_v0_6 = temp_v1_12 -
                        (*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 8)));
            if (temp_v0_6 >= 0) {
                if (temp_v0_6 < 0xC00) {
                    goto block_92;
                }
            } else if (((*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 8))) -
                        temp_v1_12) < 0xC00) {
            block_92:
                if ((((unsigned int)((*((int *)(((unsigned char *)((
                                                    int)(&Level22_8B154_D_80070328))) +
                                                0x50))) -
                                     7)) >= 2U) &&
                    ((*((int *)(((unsigned char *)((int)(&Level22_8B154_D_80070328))) + 0x240))) ==
                     0)) {
                    Level22_8B154_func_80013ACC(owner, 0xC);
                    result = 2;
                block_95:
                    *((unsigned char *)(((unsigned char *)owner) + 0x48)) = result;
                }
            }
        }
        goto block_118;

    case 3:
        if (Level22_8B154_D_8006C770 != 0) {
            *((unsigned char *)(((unsigned char *)owner) + 0x48)) = 0U;
            Level22_8B154_func_80034F40(owner, 0);
            return;
        }
        goto actor806_return;

    case 5:
        if (Level22_8B154_func_80035194(owner, privateState) == 0x100) {
            Level22_8B154_func_80055D24(owner, 4);
            Level22_8B154_func_8003BA00(owner);
            Level22_8B154_func_800369B8(owner, 0x24);
            Level22_8B154_func_80055B18(owner);
            return;
        }
        goto actor806_return;

    case 30:
        if ((Level22_8B154_unk_ovlheader_80074414(
                 *((int *)(((unsigned char *)privateState) + 0x24)),
                 (int)(&Level22_8B154_D_80070328)) != 0) ||
            ((temp_a1 = ((*((int *)(((unsigned char *)privateState) + 0x44))) * 0x58) +
                        Level22_8B154_D_8006C550,
              ((*((unsigned char *)(((unsigned char *)temp_a1) + 0x48))) & 0x80) != 0))) {
            result = 2;
        block_102:
            *((unsigned char *)(((unsigned char *)owner) + 0x48)) = result;
            Level22_8B154_func_80034F40(owner, 2);
            return;
        }
        result = 2;
        Level22_8B154Keep(result);
        temp_v0_7 = Level22_8B154_func_8004E880((*((int *)(((unsigned char *)temp_a1) + 0xC))) -
                                                    (*((int *)(((unsigned char *)owner) + 0xC))),
                                                (*((int *)(((unsigned char *)temp_a1) + 0x10))) -
                                                    (*((int *)(((unsigned char *)owner) + 0x10))),
                                                0);
        *((unsigned char *)(((unsigned char *)privateState) + 0x2C)) = temp_v0_7;
        if (!((*((int *)(((unsigned char *)privateState) + 0x30))) & 0x3000)) {
            Level22_8B154_func_8003585C(owner, temp_v0_7 & 0xFF, 4, 0, 1, 0);
            saved16 = *((unsigned char *)(((unsigned char *)owner) + 0x46));
        } else {
            saved16 =
                *((volatile unsigned char *)(((volatile unsigned char *)privateState) + 0x2C));
            *((int *)(((unsigned char *)privateState) + 0x34)) = 0;
        }
        argument0 = owner + 0xC;
        scratch3 = Level22_8B154Field(privateState, int *, 0x44);
        argument1 = Level22_8B154_D_8006C550;
        saved17 = Level22_8B154Field(owner, unsigned char *, 0x46);
        argument1 = argument1 + scratch3 * 88;
        scratch3 = ((Level22_8B154_func_8004F334(argument0, argument1 + 12) - 8000) / 800) + 110;
        argument0 = *((int *)(((unsigned char *)privateState) + 0x34));
        result = scratch3 - argument0;
        Level22_8B154Keep(scratch3);
        if (result >= 0) {
            if (result >= 11)
                goto actor806_recompute_difference;
            goto actor806_speed_done;
        }
        result = argument0 - scratch3;
        if (result < 11)
            goto actor806_speed_done;
        argument0 = Level22_8B154Field(privateState, volatile int *, 0x34);
    actor806_recompute_difference:
        result = scratch3 - argument0;
    actor806_adjust_speed:
        if (result > 0)
            result = argument0 + 10;
        else
            result = argument0 - 10;
        Level22_8B154Field(privateState, int *, 0x34) = result;
        if (result < 0)
            Level22_8B154Field(privateState, int *, 0x34) = 0;
    actor806_speed_done:
        argument0 = owner;
        temp_v0_9 = Level22_8B154_unk_ovlheader_800743F0(
            argument0, saved16, *((int *)(((unsigned char *)privateState) + 0x34)), 0x200, 0x200,
            0x27, privateState + 0x24, 1, *((int *)(((unsigned char *)privateState) + 0x28)));
        *((int *)(((unsigned char *)privateState) + 0x30)) = temp_v0_9;
        if ((*((unsigned char *)(((unsigned char *)owner) + 0x46))) != saved17) {
            *((int *)(((unsigned char *)privateState) + 0x30)) = (int)(temp_v0_9 | 0x1000);
        }
    }
block_118:
    Level22_8B154_func_80056270(owner);
actor806_return:
    return;
}

#undef Level22_8B154Field
#undef Level22_8B154Keep
#undef Level22_8B154Low


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#define Actor22BDECField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor22BDECfunc_80018368() __asm__("func_80018368");
void* Actor22BDECfunc_8001BA30() __asm__("func_8001BA30");
int Actor22BDECfunc_800359A4() __asm__("func_800359A4");
int Actor22BDECfunc_8003613C() __asm__("func_8003613C");
int Actor22BDECfunc_8003636C() __asm__("func_8003636C");
int Actor22BDECfunc_800363DC() __asm__("func_800363DC");
int Actor22BDECfunc_8003BABC() __asm__("func_8003BABC");
int Actor22BDECfunc_8004E880() __asm__("func_8004E880");
int Actor22BDECfunc_8004E9E4() __asm__("func_8004E9E4");
int Actor22BDECfunc_8004EA2C() __asm__("func_8004EA2C");
int Actor22BDECfunc_8004F0E8() __asm__("func_8004F0E8");
int Actor22BDECfunc_8004F178() __asm__("func_8004F178");
int Actor22BDECfunc_8004F194() __asm__("func_8004F194");
int Actor22BDECfunc_8004F334() __asm__("func_8004F334");
int Actor22BDECfunc_80055B18() __asm__("func_80055B18");
int Actor22BDECrand() __asm__("rand");
extern short Actor22BDECD_80065920[] __asm__("D_80065920");
extern short Actor22BDECD_800658A0[] __asm__("D_800658A0");
extern int Actor22BDECD_8006C550 __asm__("D_8006C550");
extern int (*Actor22BDECSpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
int Actor22BDECfunc_8003BFC0() __asm__("func_8003BFC0");
int Actor22BDECfunc_8003BE70() __asm__("func_8003BE70");
int Actor22BDECfunc_8003C014() __asm__("func_8003C014");
int Actor22BDECfunc_8004F110() __asm__("func_8004F110");
int Actor22BDECfunc_8001C288() __asm__("func_8001C288");
int Actor22BDECfunc_80035D38() __asm__("func_80035D38");
int Actor22BDECfunc_8005629C() __asm__("func_8005629C");
extern int Actor22BDECTick __asm__("D_8006C640");
extern int Actor22BDECDelta __asm__("D_8006C648");
/* AI generated, not human reviewed. Original SCUS-94467 USA Rev0
 * level22:8008BDEC complete261 instructions captured in sibling4405.
 * Verified50 sibling provides the identical helper multiplication chain.
 * No semantic claims: raw fields/constants/call shapes only. */
void func_level_22_8008BDEC(void* input) {
 register unsigned char* owner __asm__("$22")=input;
 struct {int sp18[4],sp28[4];int sp38,sp3C,sp40,pad44;
         int sp48[4];void* volatile pointer;} frame;
 register void* state __asm__("$23");
 register void* ownerPosition __asm__("$17");
 register void* scratch __asm__("$16");
 register void* destination __asm__("$21");
 register int firstFactor __asm__("$19");
 register int secondFactor __asm__("$20");
 register int maskedSelector __asm__("$18");
 register int helperSelector __asm__("$17");
 register int firstTableResult __asm__("$16");
 register int secondTableResult __asm__("$16");
 register int work2 __asm__("$2");
 register void* call4 __asm__("$4");
 register void* call5 __asm__("$5");
 register void* call6 __asm__("$6");
 int particleIndex;
 unsigned char copiedByte;
 __asm__("" : "=r"(owner):"0"(owner));
 state=Actor22BDECField(owner,void**,0);
 if(!Actor22BDECfunc_8003BFC0(input,Actor22BDECField(state,int*,16)))
  Actor22BDECField(state,int*,16)=Actor22BDECfunc_8003BABC(owner,0,4);
 else {
  Actor22BDECfunc_8004F178(frame.sp18,state);
  Actor22BDECfunc_8004F110(frame.sp18,1);
  Actor22BDECfunc_8003C014(Actor22BDECField(state,int*,16),frame.sp18);
 }
 switch(Actor22BDECField(owner,unsigned char*,0x48)) {
 case 0:
  if(Actor22BDECField(owner,unsigned char*,0x4F)>32) {
   Actor22BDECField(owner,unsigned char*,0x4F)-=Actor22BDECDelta*4;
   if(Actor22BDECField(owner,unsigned char*,0x4F)<32)
    Actor22BDECField(owner,unsigned char*,0x4F)=32;
  }
  if(Actor22BDECField(owner,int*,12)<1024 || Actor22BDECField(owner,int*,16)<1024 || Actor22BDECField(owner,int*,20)<1024) goto remove;
  call4=frame.sp18;
  __asm__("" : "=r"(call4):"0"(call4));
  ownerPosition=owner+12;
  Actor22BDECfunc_8004F178(call4,ownerPosition);
  Actor22BDECfunc_8004F194(ownerPosition,ownerPosition,state);
  if(Actor22BDECfunc_8001C288(ownerPosition,150,1)) goto contact;
  scratch=Actor22BDECfunc_8001BA30(ownerPosition,300,0,0,0x10000,Actor22BDECD_8006C550+Actor22BDECField(owner,unsigned char*,0x3A)*88);
  if(scratch) {
   copiedByte=Actor22BDECfunc_8004E880(Actor22BDECField(state,int*,0),Actor22BDECField(state,int*,4),0);
   Actor22BDECField(scratch,unsigned char*,0x51)=copiedByte;
   if(!copiedByte) Actor22BDECField(scratch,unsigned char*,0x51)=1;
   goto contact;
  }
  if(Actor22BDECfunc_800359A4(state+12,4)) goto remove;
  scratch=frame.sp28;
  if(Actor22BDECTick&1) {
   Actor22BDECfunc_8004F178(scratch,ownerPosition);
   frame.sp38=Actor22BDECrand()&7;
   frame.sp3C=Actor22BDECrand()&7;
   frame.sp40=Actor22BDECfunc_8003636C(7,11);
   Actor22BDECSpawnParticle(1,13,scratch,&frame.sp38);
  }
  if(Actor22BDECfunc_80018368(frame.sp18,ownerPosition)) {
contact:
   Actor22BDECField(owner,unsigned char*,0x48)=1;
   return;
  }
  Actor22BDECfunc_80035D38(owner);Actor22BDECfunc_8005629C(owner);
  return;
 case 1:
  particleIndex=0;
  __asm__ volatile("" ::: "$21");
  destination=frame.sp48;
  {void* pointer=&frame.sp38;
   __asm__("" : "=r"(pointer):"0"(pointer):"$2","$3","$4","$5","$6","$7");frame.pointer=pointer;}
        do {
            firstFactor = Actor22BDECfunc_8003636C(0x28, 0x3C);
            secondFactor = Actor22BDECfunc_8003636C(0x28, 0x3C);
            maskedSelector = Actor22BDECrand() & 0xFFF;
            helperSelector = Actor22BDECfunc_8003636C(0, 0x800);
            work2=Actor22BDECfunc_8004EA2C(helperSelector);
            call4=(void*)maskedSelector;
            __asm__("" : "=r"(call4),"=r"(work2) : "0"(call4),"1"(work2));
            firstTableResult=work2;
            {register int product __asm__("$8")=Actor22BDECfunc_8004EA2C((int)call4)*firstFactor;
             __asm__("" : "=r"(product):"0"(product));
             firstTableResult>>=6;
             product=firstTableResult*product;
             __asm__("" : "=r"(product):"0"(product));
             work2=product>>18;
             __asm__("" : "=r"(work2):"0"(work2));frame.sp38=work2;}
            work2=Actor22BDECfunc_8004EA2C(helperSelector);
            call4=(void*)maskedSelector;
            __asm__("" : "=r"(call4),"=r"(work2) : "0"(call4),"1"(work2));
            secondTableResult=work2;
            {register int product __asm__("$8")=Actor22BDECfunc_8004E9E4((int)call4)*firstFactor;
             __asm__("" : "=r"(product):"0"(product));
             secondTableResult>>=6;
             product=secondTableResult*product;
             __asm__("" : "=r"(product):"0"(product));
             work2=product>>18;
             __asm__("" : "=r"(work2):"0"(work2));frame.sp3C=work2;}
            particleIndex += 1;
            {register int product __asm__("$8")=Actor22BDECfunc_8004E9E4(helperSelector)*secondFactor;
             __asm__("" : "=r"(product):"0"(product));work2=product>>12;
             __asm__("" : "=r"(work2):"0"(work2));frame.sp40=work2;}
            Actor22BDECfunc_8004F178(destination, frame.pointer);
            Actor22BDECfunc_8004F0E8(destination, 1);
            call4=destination;
            __asm__("" : "=r"(call4) : "0"(call4));
            call5=destination;
            __asm__("" : "=r"(call4),"=r"(call5) : "0"(call4),"1"(call5));
            call6=owner+12;
            Actor22BDECfunc_8004F194(call4, call5, call6);
            __asm__("" : "=r"(owner) : "0"(owner));
            {register void* argument __asm__("$7");
             register int (*spawn)(int,int,void*,void*) __asm__("$2");
             call4=(void*)1;call5=(void*)13;
             __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
             spawn=Actor22BDECSpawnParticle;
             __asm__("" : "=r"(spawn):"0"(spawn));
             argument=frame.pointer;
             spawn((int)call4,(int)call5,destination,argument);}
            call6=owner+12;
        } while (particleIndex < 20);
        Actor22BDECSpawnParticle(10, 0x46, call6, (int *)0x10);
remove:
  if(Actor22BDECfunc_8003BFC0(owner,Actor22BDECField(state,int*,16)))
   Actor22BDECfunc_8003BE70(Actor22BDECField(state,int*,16));
  Actor22BDECField(state,int*,16)=-1;
  Actor22BDECfunc_80055B18(owner);
  return;
 }
}
#undef Actor22BDECField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_22/moby/func_level_22_8008C200.s SHA256 f41952c83785e13c060da17b30213a78614483c8fe12d48cb06930392037a0b7. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level22_8C200_Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level22_8C200_func_8001A358() __asm__("func_8001A358");
/* extern */
int Level22_8C200_func_80021ED8() __asm__("func_80021ED8");
/* extern */
int Level22_8C200_func_80034F80() __asm__("func_80034F80");
/* extern */
int Level22_8C200_func_8004F1C8() __asm__("func_8004F1C8");
/* extern */
int Level22_8C200_func_80055B18() __asm__("func_80055B18");
/* extern */
int Level22_8C200_func_80055D24() __asm__("func_80055D24");
/* extern */
int Level22_8C200_rand() __asm__("rand");
/* extern */
extern short Level22_8C200_D_800658A0 __asm__("D_800658A0");
extern short Level22_8C200_D_80065920 __asm__("D_80065920");
extern int Level22_8C200_D_8006C550 __asm__("D_8006C550");
extern int Level22_8C200_D_8006C574 __asm__("D_8006C574");
extern int Level22_8C200_D_8006C578 __asm__("D_8006C578");
extern int Level22_8C200_D_8006C58C __asm__("D_8006C58C");
extern unsigned char Level22_8C200_D_8006C7B4 __asm__("D_8006C7B4");
extern Savepoint Level22_8C200_D_8006C7F8 __asm__("D_8006C7F8");
extern unsigned char Level22_8C200_D_80070300 __asm__("D_80070300");
void func_level_22_8008C200(Moby *inputMoby) {
    /* SCUS-94467 USA Rev0 address8008C200; original assembly/SHA above.
    * Original38 frame, owner18/private16 and saved16..23/30/RA retained.
    * Byte loads produce full words for state and animation selection:
    * comparisons consume the original byte before result3 increments.
    * Original index2/offset3/pool5 and index3/offset2/pool3 roles build
    * record byte addresses. State selector uses the original signed tree.
    * The branch-only private2C pointer constructor and the independent
    * constructor after the flag store remain separate. Dead4 is clobbered
    * only immediately before its replacement pointer producer.
    * Helper return2 copies into4 before private10 replaces2; the sign test
    * and following helper therefore consume the original retained return4.
    * Original500 in22, signed two-MULT low-word/SRA24 products, signed LH
    * samples and byte32 cursor advances retain original operations. Table
    * addresses add bytes before casts; no staged Q12 product is substituted.
    * The original shared delete callback follows the final state3 helpers.
    * Empty constraints consume initialized original values and emit no CPU
    * instructions. Compiler/options/gates unchanged. AI generated; not
    * human reviewed. Confidence requires every native/linked word and
    * conditional/internal J target, preserved data and full EXE/overlay
    * hashes. Helper meanings, SFX semantics, physical units/fixed point,
    * caller/frame cadence and synchronized runtime verification remain
    * unresolved. Cadence per invocation; no frame frequency, browser or
    * subsystem completion claim. */
    register Moby *moby __asm__("$18")=inputMoby;
    register Moby *createdMoby __asm__("$17");
    register int coefficient22 __asm__("$22");
    register short *table65920Base __asm__("$23");
    short *table658A0Base;
    register short * temp_a0_3 __asm__("$4");
    register short * table658A0Cursor __asm__("$19");
    register short * table65920Cursor __asm__("$20");
    register int temp_a0_2 __asm__("$4");
    register int temp_v0_2 __asm__("$2");
    register int temp_v0_3 __asm__("$2");
    register int helperReturn4 __asm__("$4");
    register int temp_v0_6 __asm__("$2");
    register int temp_v1_7 __asm__("$3");
    register int iteration __asm__("$21");
    register int absolutePrivate10 __asm__("$2");
    register int selectedIndexCase0 __asm__("$3");
    register int selectedIndexCase1 __asm__("$3");
    register unsigned int stateSelector __asm__("$4");
    register unsigned int animationIdCase0 __asm__("$3");
    register unsigned int animationIdCase1 __asm__("$3");
    register void * selectedRecordCase0 __asm__("$6");
    register void * selectedRecordCase1 __asm__("$6");
    register void * privateData __asm__("$16");
    register void * createdData __asm__("$16");
    register void * temp_v0 __asm__("$2");
    register void * temp_v1 __asm__("$3");
    register void * temp_v1_2 __asm__("$3");
    register void * temp_v1_3 __asm__("$3");
    register void * temp_v1_4 __asm__("$3");
    register void * record4 __asm__("$4");
    register void * flagWordArgument4 __asm__("$4");
    __asm__("" : "=r"(moby):"0"(moby));
    privateData = moby->mobyTag;
    if (moby->damageFlags & 0x40000) {
        moby->damageFlags = 0;
        record4 = ({ register int index2 __asm__("2"); register int offset3 __asm__("3"); register int pool5 __asm__("5"); index2 = Level22_8C200_Field(privateData,int*,0xC); pool5 = Level22_8C200_D_8006C550; offset3 = index2 * 0x58; __asm__("" : "=r"(offset3) : "0"(offset3)); (void *)(offset3 + pool5); });
        if (Level22_8C200_Field(record4, unsigned char *, 0x48) & 0x80) {
            temp_v1 = (Level22_8C200_Field(privateData, int *, 4) * 0x58) + Level22_8C200_D_8006C550;
            if (!(Level22_8C200_Field(temp_v1, unsigned char *, 0x48) & 0x80)) {
                Level22_8C200_Field(temp_v1, int *, 0x18) = (int) (Level22_8C200_Field(temp_v1, int *, 0x18) | 0x10000000);
                temp_v0 = (Level22_8C200_Field(privateData, int *, 8) * 0x58) + Level22_8C200_D_8006C550;
                Level22_8C200_Field(temp_v0, int *, 0x18) = (int) (Level22_8C200_Field(temp_v0, int *, 0x18) | 0x10000000);
            }
            else {
                record4 = ({ register int index2 __asm__("2"); register int offset3 __asm__("3"); register int pool5 __asm__("5"); index2 = Level22_8C200_Field(privateData,int*,0); pool5 = Level22_8C200_D_8006C550; offset3 = index2 * 0x58; __asm__("" : "=r"(offset3) : "0"(offset3)); (void *)(offset3 + pool5); });
                if (!(Level22_8C200_Field(record4, unsigned char *, 0x48) & 0x80)) {
                    goto markRecordFlags;
                }
            }
        }
        else {
        markRecordFlags:
            Level22_8C200_Field(record4, int *, 0x18) = (int) (Level22_8C200_Field(record4, int *, 0x18) | 0x10000000);
        }
        temp_v1_2 = ({ register int index3 __asm__("3"); register int offset2 __asm__("2"); register int pool3 __asm__("3"); index3 = Level22_8C200_Field(privateData,int*,0x20); offset2 = index3 * 11; __asm__("" : "=r"(offset2) : "0"(offset2)); pool3 = Level22_8C200_D_8006C550; offset2 *= 8; (void *)(offset2 + pool3); });
        if ((Level22_8C200_Field(temp_v1_2, unsigned char *, 0x48) & 0x80) || (Level22_8C200_Field(temp_v1_2, unsigned char *, 0x49) == 3)) {
            Level22_8C200_Field(privateData, int *, 0x2C) = (int) (Level22_8C200_Field(privateData, int *, 0x2C) | 1);
        }
        temp_v1_3 = ({ register int index3 __asm__("3"); register int offset2 __asm__("2"); register int pool3 __asm__("3"); index3 = Level22_8C200_Field(privateData,int*,0x24); offset2 = index3 * 11; __asm__("" : "=r"(offset2) : "0"(offset2)); pool3 = Level22_8C200_D_8006C550; offset2 *= 8; (void *)(offset2 + pool3); });
        if ((Level22_8C200_Field(temp_v1_3, unsigned char *, 0x48) & 0x80) || (Level22_8C200_Field(temp_v1_3, unsigned char *, 0x49) == 3)) {
            Level22_8C200_Field(privateData, int *, 0x2C) = (int) (Level22_8C200_Field(privateData, int *, 0x2C) | 2);
        }
        temp_v1_4 = ({ register int index3 __asm__("3"); register int offset2 __asm__("2"); register int pool3 __asm__("3"); index3 = Level22_8C200_Field(privateData,int*,0x28); offset2 = index3 * 11; __asm__("" : "=r"(offset2) : "0"(offset2)); pool3 = Level22_8C200_D_8006C550; offset2 *= 8; (void *)(offset2 + pool3); });
        if ((Level22_8C200_Field(temp_v1_4, unsigned char *, 0x48) & 0x80) || (flagWordArgument4 = privateData + 0x2C, Level22_8C200_Field(temp_v1_4, unsigned char *, 0x49) == 3)) {
            Level22_8C200_Field(privateData, int *, 0x2C) = (int) (Level22_8C200_Field(privateData, int *, 0x2C) | 4);
            __asm__ volatile("" : : : "memory", "4");
            flagWordArgument4 = privateData + 0x2C;
        }
        func_8003B7B4(flagWordArgument4, 4, &Level22_8C200_D_8006C7F8);
    }
    if (moby->damageFlags & 0x10000000) {
        moby->state = 3;
    }
    stateSelector = moby->state;
    moby->damageFlags = 0;
    switch ((int)stateSelector) {
        /* irregular */
    case 0:
        animationIdCase0 = moby->animationState.id;
        moby->highDrawDistance = 0x7F;
        moby->lowDrawDistance = 0x7F;
        selectedIndexCase0 = animationIdCase0;
        if (selectedIndexCase0 == 1) selectedIndexCase0 = 3;
        else if (selectedIndexCase0 == 2) selectedIndexCase0 = 1;
        else selectedIndexCase0 += 1;
        if (selectedIndexCase0 < 4) {
            selectedRecordCase0 = ({ register int address2 __asm__("2"); register int index3 __asm__("3"); register int pool3 __asm__("3"); address2 = selectedIndexCase0 << 2; address2 += (int)privateData; index3 = *(int *)address2; address2 = index3 * 11; __asm__("" : "=r"(address2) : "0"(address2)); pool3 = Level22_8C200_D_8006C550; address2 *= 8; (void *)(address2 + pool3); });
            __asm__("" : "=r"(selectedRecordCase0) : "0"(selectedRecordCase0));
            if (Level22_8C200_Field(selectedRecordCase0, unsigned char *, 0x48) & 0x80) {
                moby->substate = 1;
                temp_v0_2 = Level22_8C200_func_8001A358(&moby->position, 0x2800, selectedRecordCase0);
                Level22_8C200_Field(privateData, int *, 0x10) = (int) (temp_v0_2 - moby->position.z);
                moby->position.z = temp_v0_2;
            }
            else {
                moby->position.z += Level22_8C200_Field(Level22_8C200_Field(selectedRecordCase0, void **, 0), int *, 0x10);
                Level22_8C200_func_8004F1C8(privateData + 0x14, &moby->position, selectedRecordCase0 + 0xC);
            }
        }
        if (moby->animationState.id == 0) {
            if ((Level22_8C200_D_8006C7B4 & 1) || (*(&Level22_8C200_D_80070300 + Level22_8C200_D_8006C58C) & 1)) {
                Level22_8C200_func_80055B18(Level22_8C200_D_8006C550 + (Level22_8C200_Field(privateData, int *, 0x20) * 0x58));
                Level22_8C200_func_80055B18(Level22_8C200_D_8006C550 + (Level22_8C200_Field(privateData, int *, 0x24) * 0x58));
                goto deleteThirdLinkedMoby;
            }
            if (Level22_8C200_Field(privateData, int *, 0x2C) & 1) {
                Level22_8C200_func_80055B18(Level22_8C200_D_8006C550 + (Level22_8C200_Field(privateData, int *, 0x20) * 0x58));
            }
            if (Level22_8C200_Field(privateData, int *, 0x2C) & 2) {
                Level22_8C200_func_80055B18(Level22_8C200_D_8006C550 + (Level22_8C200_Field(privateData, int *, 0x24) * 0x58));
            }
            if (Level22_8C200_Field(privateData, int *, 0x2C) & 4) {
            deleteThirdLinkedMoby:
                Level22_8C200_func_80055B18(Level22_8C200_D_8006C550 + (Level22_8C200_Field(privateData, int *, 0x28) * 0x58));
            }
        }
        if (!(Level22_8C200_D_8006C7B4 & 1) && !(*(&Level22_8C200_D_80070300 + Level22_8C200_D_8006C58C) & 1)) {
            moby->state = 1;
            return;
        }
        goto deleteMoby;
    case 1:
        animationIdCase1 = moby->animationState.id;
        selectedIndexCase1 = animationIdCase1;
        if (selectedIndexCase1 == stateSelector) selectedIndexCase1 = 3;
        else if (selectedIndexCase1 == 2) selectedIndexCase1 = 1;
        else selectedIndexCase1 += 1;
        if (selectedIndexCase1 < 4) {
            selectedRecordCase1 = ({ register int address2 __asm__("2"); register int index3 __asm__("3"); register int pool3 __asm__("3"); address2 = selectedIndexCase1 << 2; address2 += (int)privateData; index3 = *(int *)address2; address2 = index3 * 11; __asm__("" : "=r"(address2) : "0"(address2)); pool3 = Level22_8C200_D_8006C550; address2 *= 8; (void *)(address2 + pool3); });
            __asm__("" : "=r"(selectedRecordCase1) : "0"(selectedRecordCase1));
            if (Level22_8C200_Field(selectedRecordCase1, unsigned char *, 0x48) & 0x80) {
                if (moby->substate == 0) {
                    Level22_8C200_Field(privateData, int *, 0x10) = 0x64;
                    moby->state = 2;
                    return;
                }
            }
            else {
                func_8004F194(&moby->position, privateData + 0x14, selectedRecordCase1 + 0xC);
                return;
            }
        }
        break;
    case 2:
        temp_v0_3 = func_80035D38(moby);
        temp_a0_2 = Level22_8C200_Field(privateData, int *, 0x10) - 0x14;
        Level22_8C200_Field(privateData, int *, 0x10) = temp_a0_2;
        temp_v1_7 = moby->position.z + temp_a0_2;
        moby->position.z = temp_v1_7;
        if (temp_v1_7 < temp_v0_3) {
            moby->position.z = temp_v0_3;
            Level22_8C200_Field(privateData, int *, 0x10) = (int) ((int) -Level22_8C200_Field(privateData, int *, 0x10) >> 2);
            helperReturn4 = func_8003BABC(moby, 1, 0);
            __asm__("" : "=r"(helperReturn4) : "0"(helperReturn4));
            if (helperReturn4 >= 0) {
                absolutePrivate10 = Level22_8C200_Field(privateData, int *, 0x10);
                if (absolutePrivate10 < 0) {
                    absolutePrivate10 = -absolutePrivate10;
                }
                func_8003C140(helperReturn4, absolutePrivate10 * 0x28);
            }
            if (Level22_8C200_Field(privateData, int *, 0x10) < 0x10) {
                moby->substate = 1;
                moby->state = 1;
            }
        }
        Level22_8C200_func_80055D24(moby, 3);
        return;
    case 3:
        coefficient22=0x1F4;
        __asm__("" : "=r"(coefficient22):"0"(coefficient22));
        func_8003BABC(moby, 0, 0);
        iteration = 0;
        table658A0Cursor = &Level22_8C200_D_800658A0;
        table658A0Base=table658A0Cursor;
        table65920Base = &Level22_8C200_D_80065920;
        table65920Cursor=table65920Base;
    loop_64:
        if ((Level22_8C200_D_8006C578 - Level22_8C200_D_8006C574) >= 0x15) {
            createdMoby = SpawnMoby(0x239, moby);
            __asm__("" : "=r"(createdMoby):"0"(createdMoby));
            if (createdMoby != 0) {
                createdData = createdMoby->mobyTag;
                createdMoby->position.z += 0x12C;
                temp_v0_6 = Level22_8C200_rand() & 0x1F;
                temp_a0_3 = (short *)((temp_v0_6 << 1) + (int)table65920Base);
                Level22_8C200_Field(createdData, short *, 0) = (short) ((int) (coefficient22 * *temp_a0_3 * *table65920Cursor) >> 0x18);
                Level22_8C200_Field(createdData, short *, 2) = (short) ((int) (coefficient22 * *temp_a0_3 * *table658A0Cursor) >> 0x18);
                Level22_8C200_Field(createdData, short *, 4) = (short) ((int) (coefficient22 * table658A0Base[temp_v0_6]) >> 0xC);
                createdMoby->position.x += Level22_8C200_Field(createdData, short *, 0) * 4;
                createdMoby->position.y += Level22_8C200_Field(createdData, short *, 2) * 4;
                createdMoby->position.z += Level22_8C200_Field(createdData, short *, 4) * 4;
                createdMoby->angle.pitch = Level22_8C200_rand(temp_a0_3);
                createdMoby->angle.yaw = Level22_8C200_rand();
                Level22_8C200_Field(createdData, short *, 6) = (short) ((Level22_8C200_rand() & 0xE) - 7);
                Level22_8C200_Field(createdData, short *, 8) = (short) ((Level22_8C200_rand() & 0xE) - 7);
                Level22_8C200_Field(createdData, short *, 0xA) = (short) ((Level22_8C200_rand() & 0xE) - 7);
                Level22_8C200_Field(createdData, short *, 0xE) = (short) (createdMoby->position.z - 0x40);
                Level22_8C200_Field(createdData, short *, 0xC) = func_8003636C(0x1E, 0x32);
                Level22_8C200_Field(createdData, short *, 0x10) = 8;
                Level22_8C200_Field(createdData, short *, 0x12) = 0x100;
                Level22_8C200_func_80034F80(createdMoby, func_8003636C(0, 2));
                createdMoby->unknownCollision = 0;
            }
            table658A0Cursor = (short*)((unsigned char*)table658A0Cursor + 0x20);
            iteration += 1;
            table65920Cursor = (short*)((unsigned char*)table65920Cursor + 0x20);
            if (iteration < 0x10) {
                goto loop_64;
            }
        }
        if (moby->animationState.id == 0) {
            Level22_8C200_func_80021ED8(1, 0xFC, 0);
        }
        Level22_8C200_func_80055D24(moby, 4);
        func_8003BA00(moby);
        func_800369B8(moby, 0x48);
        goto deleteMoby;
    }
    return;
deleteMoby:
    Level22_8C200_func_80055B18(moby);
    return;
}
#undef Level22_8C200_Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_22/moby/func_level_22_8008CADC.s SHA256 9edf0fa92070b0664f087ad5958a62c4ba8e4b132c37241ace43ad09c2be3576. Rev1 raw571 controller is a structural lead only: its initial multiplier177 differs from original Rev0 multiplier175 retained here. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level22_8CADCField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Level22_8CADC_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level22_8CADC_D_80065920[0x100] __asm__("D_80065920");
extern Spyro Level22_8CADC_D_80070328 __asm__("D_80070328");
void Level22_8CADC_func_80034F40(Moby* moby, int newId) __asm__("func_80034F40");
int Level22_8CADC_func_800359A4(void*, int) __asm__("func_800359A4");
int Level22_8CADC_func_800360F8(int owner, int arg1, int arg2, unsigned char arg3) __asm__("func_800360F8");
int Level22_8CADC_func_8003636C(int low, int high) __asm__("func_8003636C");
void Level22_8CADC_func_800369B8() __asm__("func_800369B8");
void Level22_8CADC_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
extern int Level22_8CADC_func_8004E880(int, int, int) __asm__("func_8004E880");
extern void Level22_8CADC_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level22_8CADC_func_8004F194(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level22_8CADC_func_80055B18(Moby*) __asm__("func_80055B18");
extern void Level22_8CADC_func_80055D24(Moby*, int) __asm__("func_80055D24");

unsigned char Level22_8CADC_func_80035030() __asm__("func_80035030");
 /* extern */
int Level22_8CADC_func_800365E4() __asm__("func_800365E4");
 /* extern */
extern int Level22_8CADC_D_8006C640 __asm__("D_8006C640");
extern int Level22_8CADC_D_8006C770 __asm__("D_8006C770");

extern short Level22_8CADC_InitialSin[] __asm__("D_80065920");
extern short Level22_8CADC_InitialCos[] __asm__("D_800658A0");

void func_level_22_8008CADC(Moby *inputOwner) {
    register Moby *owner __asm__("$17") = inputOwner;
    /* Original frame0x68 and scratch SP+0x20/+0x30 are retained.
     * Rev0 initial table arithmetic is 175*x >>10;
      Rev1 uses177.
     * The structured modulo255 loop preserves both original disjoint probes
     * and its backedge. Ordinary reverse-subtract constants allow original
     * invariant loads;
      no original instructions are deleted as unreachable.
     * Empty constraints preserve recorded raw producers without opcodes.
     * Helper meanings, physical units/fixed-point domains, invocation cadence
     * and synchronized retail runtime chains remain unresolved. */
    struct {int sp20;
     int sp24;
     int sp28;
     unsigned char pad2C[4];
     int sp30;
     unsigned char pad34[16];
    } scratch;

    Moby *child;
    register Vector3D *childPosition16 __asm__("$16");
    register int scalar5 __asm__("$5");
    register int angleOrTableWord2 __asm__("$2");
    register int initialCosine3 __asm__("$3");
    register int stepX3 __asm__("$3");
    register Vector3D *argument4 __asm__("$4");
    register int counterRemainder3 __asm__("$3");
    register int predicate2 __asm__("$2");
    int stepProduct;
    int scaledStepY2;
    int temp_v0_5;
    int temp_v0_6;
    int moduloValue;
    register int damageFlags3 __asm__("$3");
    register int stepScale20 __asm__("$20");
    int var_v0;
    int var_v0_2;
    int var_v0_3;
    int stateByte3;
    int directionParameter;
    register void *ownerPrivate18 __asm__("$18");
    register void *childPrivate19 __asm__("$19");
    void *referencePosition2;
    void *referencePosition2b;

    ownerPrivate18 = owner->mobyTag;
    if ((owner->damageFlags != 0) && (owner->state != 4)) {
        child = SpawnMoby(0x23C, owner);
        if (child != 0) {
            childPrivate19 = child->mobyTag;
            stepScale20 = 0x4B;
            if (Level22_8CADCField(ownerPrivate18, int *, 0x14) == 2) {
                stepScale20 = 0x96;
            }
            scratch.sp28 = 0x1F4;
            childPosition16 = &child->position;
            scratch.sp20 = (int) (Level22_8CADC_InitialSin[owner->angle.yaw] * 0xAF) >> 0xA;
            argument4 = childPosition16;
            {register Vector3D *initialArgument5 __asm__("$5");
            initialCosine3 = Level22_8CADC_InitialCos[owner->angle.yaw];
            __asm__ volatile("" : "=m"(scratch.sp28):"0"(scratch.sp28),"r"(initialCosine3):"$5");
            initialArgument5 = &owner->position;
            __asm__("" : :"r"(initialArgument5));
            *(volatile int *)&scratch.sp28 = 0;
            __asm__ volatile("" : "=r"(initialCosine3):"0"(initialCosine3),"m"(scratch.sp28));
            scratch.sp24 = (initialCosine3 * 0xAF) >> 0xA;
            Level22_8CADC_func_8004F178(argument4, initialArgument5);
            }
            Level22_8CADC_func_8004F194(childPosition16, childPosition16, (Vector3D *) &scratch.sp20);
            referencePosition2 = Level22_8CADCField(Level22_8CADCField(ownerPrivate18, void **, 0xC), void **, 0xC);
            scratch.sp20 = (int) (Level22_8CADC_D_80065920[Level22_8CADC_func_8004E880(Level22_8CADCField(referencePosition2, int *, 0) - owner->position.x, Level22_8CADCField(referencePosition2, int *, 4) - owner->position.y, 0)] * stepScale20) >> 0xC;
            referencePosition2b = Level22_8CADCField(Level22_8CADCField(ownerPrivate18, void **, 0xC), void **, 0xC);
            stepProduct = Level22_8CADC_D_800658A0[Level22_8CADC_func_8004E880(Level22_8CADCField(referencePosition2b, int *, 0) - owner->position.x, Level22_8CADCField(referencePosition2b, int *, 4) - owner->position.y, 0)] * stepScale20;
            stepX3 = scratch.sp20;
            __asm__("" : :"r"(stepX3):"$4");
            argument4 = childPosition16;
            scratch.sp28 = 0;
            scaledStepY2 = stepProduct >> 0xC;
            scratch.sp24 = scaledStepY2;
            Level22_8CADCField(childPrivate19, short *, 4) = (short) stepX3;
            __asm__ volatile("" : "=m"(scratch.sp24):"0"(scratch.sp24):"$6");
            Level22_8CADCField(childPrivate19, short *, 6) = (short) scratch.sp24;
            angleOrTableWord2 = Level22_8CADC_func_800365E4(argument4, Level22_8CADCField(Level22_8CADCField(ownerPrivate18, void **, 0xC), void **, 0xC), stepScale20, -0xC, &scratch.sp30);
            scalar5 = scratch.sp30;
            Level22_8CADCField(childPrivate19, short *, 8) = angleOrTableWord2;
            Level22_8CADCField(childPrivate19, short *, 0xA) = 6;
            Level22_8CADCField(childPrivate19, Moby **, 0) = owner;
            for (;;) {
                __asm__ volatile("" : "=m"(Level22_8CADCField(childPrivate19, short *, 0xA)));
                moduloValue = (Level22_8CADCField(childPrivate19, short *, 0xA) * scalar5) % 255;
                __asm__("" : "=r"(counterRemainder3):"0"(moduloValue));
                moduloValue = counterRemainder3;
                predicate2 = moduloValue - 64;
                if (predicate2 < 0) predicate2 = 64 - moduloValue;
                predicate2 = predicate2 < 25;
                if (!predicate2) break;
                predicate2 = moduloValue - 128;
                if (predicate2 < 0) predicate2 = 128 - moduloValue;
                predicate2 = predicate2 < 25;
                if (!predicate2) break;
                __asm__ volatile("" : "=m"(Level22_8CADCField(childPrivate19, short *, 0xA)));
                Level22_8CADCField(childPrivate19, short *, 0xA) = (short) ((unsigned short) Level22_8CADCField(childPrivate19, short *, 0xA) + 1);
            }
            Level22_8CADCField(childPrivate19, short *, 0xC) = 0;
            if (Level22_8CADCField(ownerPrivate18, int *, 0x14) == 1) {
                Level22_8CADC_func_8004F178(&child->position, &Level22_8CADC_D_80070328.position);
            }
            child->unknown |= 0x80000000;
        }
        damageFlags3 = owner->damageFlags;
        predicate2 = damageFlags3 & 0x800000;
        if (predicate2) { predicate2 = 140;
         goto flagParameters;
         }
        predicate2 = damageFlags3 & 0x10000;
        if (predicate2) { predicate2 = 220;
         goto flagParameters;
         }
        predicate2 = damageFlags3 & 0x20000;
        if (!predicate2) goto noFlagParameters;
        predicate2 = 340;
flagParameters:
        Level22_8CADCField(ownerPrivate18, int *, 0) = predicate2;
        Level22_8CADCField(ownerPrivate18, int *, 4) = 180;
noFlagParameters:
        directionParameter = owner->unkb;
        if (directionParameter == 0) {
            directionParameter = Level22_8CADC_func_800360F8(Level22_8CADC_func_8004E880(owner->position.x - Level22_8CADC_D_80070328.position.x, owner->position.y - Level22_8CADC_D_80070328.position.y, 0), (int) Level22_8CADC_D_80070328.bodyRotation.yaw, 0x20, 0x40U);
        }
        Level22_8CADCField(ownerPrivate18, int *, 8) = (int) directionParameter;
        owner->unknownCollision = 0;
        if (Level22_8CADCField(ownerPrivate18, int *, 0x14) == 1) {
            Level22_8CADCField(ownerPrivate18, int *, 0) = (int) (Level22_8CADCField(ownerPrivate18, int *, 0) + 0xC8);
            Level22_8CADCField(ownerPrivate18, int *, 4) = (int) (Level22_8CADCField(ownerPrivate18, int *, 4) + 0x1E);
        }
        if (owner->damageFlags & 0x100000) {
            Level22_8CADCField(ownerPrivate18, int *, 0) = (int) (Level22_8CADCField(ownerPrivate18, int *, 0) + 0xB4);
            Level22_8CADCField(ownerPrivate18, int *, 4) = (int) (Level22_8CADCField(ownerPrivate18, int *, 4) + 0x46);
        }
        owner->state = 4;
        Level22_8CADC_func_80034F40(owner, 4);
        return;
    }
    if ((Level22_8CADC_D_8006C640 < 2) && (Level22_8CADCField(ownerPrivate18, int *, 0x1C) != 0)) {
        Level22_8CADC_func_8003BA00(owner);
        goto block_46;
    }
    stateByte3 = owner->state;
    owner->updateDistance = 0x20;
    switch (stateByte3) {                            /* irregular */
    case 0:
        if (Level22_8CADC_D_8006C770 != 0) {
            Level22_8CADCField(ownerPrivate18, int *, 0x10) = Level22_8CADC_func_8003636C(0x3C, 0x78);
            owner->state = 1;
            Level22_8CADC_func_80034F40(owner, 1);
            return;
        }
        return;
    case 1:
        if ((Level22_8CADC_func_800359A4(ownerPrivate18 + 0x10, 4) != 0) && (Level22_8CADC_D_8006C770 != 0)) {
            owner->state = 2;
            Level22_8CADC_func_80034F40(owner, 2);
            return;
        }
        break;
    case 2:
        if (Level22_8CADC_D_8006C770 != 0) {
            owner->state = 0;
            Level22_8CADC_func_80034F40(owner, 0);
            return;
        }
        break;
    case 4:
        Level22_8CADC_func_80035030(owner, ownerPrivate18, Level22_8CADCField(ownerPrivate18, int *, 8), ownerPrivate18 + 4, 0xC, 0x10, 0x12C, 1);
        if (Level22_8CADC_D_8006C770 != 0) {
            Level22_8CADC_func_80055D24(owner, 4);
            Level22_8CADC_func_8003BA00(owner);
            Level22_8CADC_func_800369B8(owner, 0x18);
block_46:
            Level22_8CADC_func_80055B18(owner);
        }
        break;
    }
}
#undef Level22_8CADCField


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008D048,
 * original288 words in sibling4784. Raw units/helper meanings/cadence unresolved. */
#define MotionField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char MotionPlayer[] __asm__("D_80070328");
extern short MotionSin[] __asm__("D_800658A0");
extern unsigned char MotionTable0[] __asm__("D_8006D088"),MotionTable1[] __asm__("D_8006C7F8");
extern int MotionCounter __asm__("D_8006C628");
extern int MotionNormal __asm__("D_80071920");
extern int (*MotionParticle)() __asm__("SpawnParticle");
int MotionH4F334() __asm__("func_8004F334");
int MotionH3B7B4() __asm__("func_8003B7B4");
int MotionH3BABC() __asm__("func_8003BABC");
int MotionH55B18() __asm__("func_80055B18");
int MotionH19194() __asm__("func_80019194");
int MotionH3C0B0() __asm__("func_8003C0B0");
int MotionH35D38() __asm__("func_80035D38");
int MotionH5629C() __asm__("func_8005629C");
int MotionH4F264() __asm__("func_8004F264");
int MotionH3613C() __asm__("func_8003613C");
void func_level_22_8008D048(void* input){
 register unsigned char* owner __asm__("$19")=input;
 register unsigned char* tag __asm__("$20");
 register int iteration16 __asm__("$16");register void* destination16 __asm__("$16");register int choice16 __asm__("$16");
 register unsigned char* nested17 __asm__("$17");register void* table17 __asm__("$17");register void* table18 __asm__("$18");
 register int value __asm__("$2");register int other __asm__("$3");
 register int call4 __asm__("$4");register int arg5 __asm__("$5");register void* arg6 __asm__("$6");
 __asm__("" : "=r"(owner):"0"(owner));arg5=(int)MotionPlayer;tag=MotionField(owner,unsigned char**,0);
 value=MotionH4F334(owner+12,(void*)arg5);if(value>=600)goto dispatch;
 other=MotionField(owner,short*,56);value=MotionField(owner,int*,20);call4=MotionField(MotionPlayer,int*,8);other=value-other;value=other-call4;
 if(value<0)goto negative_height;value=value<600;__asm__("" : "=r"(value):"0"(value));if(!value)goto dispatch;goto acquired;
 negative_height:
 value=call4-other;value=value<600;if(!value)goto dispatch;__asm__ volatile("" ::: "memory");
 acquired:
 value=MotionField(tag,int*,0);__asm__("" : "=r"(value):"0"(value):"$16");iteration16=0;nested17=MotionField((void*)value,unsigned char**,0);
 particle_loop:
 call4=4;arg5=12;arg6=owner;__asm__("" : "=r"(call4),"=r"(arg5),"=r"(arg6):"0"(call4),"1"(arg5),"2"(arg6));iteration16++;MotionParticle(call4,arg5,arg6,3);value=iteration16<3;arg5=4;if(value)goto particle_loop;
 destination16=nested17+28;call4=(int)destination16;table18=MotionTable0;arg6=table18;__asm__("" : "=r"(arg6):"0"(arg6):"$2");value=1;MotionField(nested17,int*,28)=value;MotionH3B7B4((void*)call4,arg5,arg6);
 call4=(int)destination16;arg5=4;__asm__("" : "=r"(call4),"=r"(arg5):"0"(call4),"1"(arg5):"$17");table17=MotionTable1;MotionH3B7B4((void*)call4,arg5,table17);
 destination16=&MotionCounter;call4=(int)destination16;arg5=4;__asm__("" : "=r"(destination16):"0"(destination16));value=MotionCounter;value++;MotionCounter=value;MotionH3B7B4((void*)call4,arg5,table18);
 MotionH3B7B4(destination16,4,table17);MotionH3BABC(owner,1,0);MotionH55B18(owner);
 dispatch:
 other=owner[72];if(!other)goto state0;value=1;if(other==value)goto state1;goto done;
 state0:
 value=owner[68];call4=tag[10];other=value<<1;arg5=*(short*)((unsigned char*)MotionSin+other);value+=call4;owner[68]=value;
 other=MotionField(tag,short*,4);value=MotionField(owner,int*,12);value+=other;MotionField(owner,int*,12)=value;
 other=MotionField(tag,short*,6);value=MotionField(owner,int*,16);value+=other;MotionField(owner,int*,16)=value;
 other=MotionField(tag,short*,8);value=MotionField(owner,int*,20);value+=other;MotionField(owner,int*,20)=value;
 value=(arg5*25)>>8;if(value<0)value=-value;
 other=MotionField(tag,unsigned short*,8);other-=12;MotionField(tag,short*,8)=other;other=(short)other;arg5=value+50;if(other<-200)MotionField(tag,short*,8)=-200;
 value=MotionField(tag,short*,8);other=value;if(value<0)other=-other;value=arg5<other;if(value)arg5=other;
 value=MotionH19194(owner+12,arg5);if(!value)goto refresh;
 other=MotionNormal;if(other<0){value=MotionField(tag,short*,8);if(value>0)goto bounce;}if(other<=0)goto refresh;value=MotionField(tag,short*,8);if(value>=0)goto refresh;
 bounce:
 __asm__("" : "=r"(value):"0"(value));if(value<0)value=-value;value=value<29;call4=(int)owner;if(!value){__asm__("" ::: "$2","$5","$6");call4=MotionH3BABC((void*)call4,0,0);value=-1;if(call4!=value){arg5=MotionField(tag,short*,8);arg5+=4096;MotionH3C0B0(call4,arg5);}}
 MotionField(tag,short*,4)=0;MotionField(tag,short*,6)=0;
 other=owner[68];value=other-64;if(value<0){value=64-other;value=value<10;}else value=value<10;if(value)goto full_bounce;
 other=owner[68];value=other-128;if(value<0)goto negative_angle;value=value<10;__asm__("" : "=r"(value):"0"(value));if(!value)goto half_bounce;goto full_bounce;
 negative_angle:
 value=128-other;value=value<10;if(!value)goto half_bounce;__asm__ volatile("" ::: "memory");
 full_bounce:
 value=MotionField(tag,unsigned short*,8);value=-value;MotionField(tag,short*,8)=value;goto refresh;
 half_bounce:
 value=MotionField(tag,unsigned short*,8);value=((short)value)>>1;value=-value;MotionField(tag,short*,8)=value;__asm__ volatile("" : "=r"(value):"0"(value):"memory");if(value<0)value=-value;value=value<14;if(value)owner[72]=1;
 value=MotionField(tag,unsigned short*,10);value=-value;MotionField(tag,short*,10)=value;
 refresh:
 MotionH35D38(owner);MotionH5629C(owner);goto done;
 state1:
 call4=MotionH35D38(owner);other=MotionField(owner,int*,20);value=other-call4;value=value<76;if(!value){value=other-30;MotionField(owner,int*,20)=value;}
 value=MotionField(owner,int*,20);other=call4+75;value=value<other;if(value)MotionField(owner,int*,20)=other;
 arg5=owner[68];if(!arg5)goto done;value=MotionH4F264(0,arg5);call4=128;__asm__("" : "=r"(call4):"0"(call4):"$5");arg5=owner[68];choice16=value;value=MotionH4F264(call4,arg5);choice16=choice16<value;arg5=0;
 if(choice16){call4=owner[68];}else{call4=owner[68];arg5=128;}
 other=MotionH3613C(call4,arg5);value=other<7;if(!value)other=6;value=other<-6;if(value)other=-6;value=owner[68];value+=other;owner[68]=value;
 done:;
}
#undef MotionField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_22/moby/func_level_22_8008D4C8.s SHA256 9d8d74c30592da67e6acf4e39bbe3a4b931a6adbbfc59a24fb2257154adef2f7. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int ControllerD4C8_func_80013D44() __asm__("func_80013D44"); /* extern */
short ControllerD4C8_func_8002803C() __asm__("func_8002803C"); /* extern */
int ControllerD4C8_func_80028154() __asm__("func_80028154");                         /* extern */
int ControllerD4C8_func_80037BBC() __asm__("func_80037BBC");                 /* extern */
int ControllerD4C8_func_8004F9C0() __asm__("func_8004F9C0");               /* extern */
int ControllerD4C8_func_800512E4() __asm__("func_800512E4");    /* extern */
int ControllerD4C8_func_80055F14() __asm__("func_80055F14");     /* extern */
int ControllerD4C8_rand() __asm__("rand");                                         /* extern */
extern unsigned char ControllerD4C8_D_800652B0 __asm__("D_800652B0");
extern unsigned char ControllerD4C8_D_800652B4 __asm__("D_800652B4");
extern unsigned char ControllerD4C8_D_800652B6 __asm__("D_800652B6");
extern unsigned char ControllerD4C8_D_800658A0 __asm__("D_800658A0");
extern unsigned char ControllerD4C8_D_80065920 __asm__("D_80065920");
extern int ControllerD4C8_D_8006C3F4 __asm__("D_8006C3F4");
extern int ControllerD4C8_D_8006C550 __asm__("D_8006C550");
extern int ControllerD4C8_D_8006C58C __asm__("D_8006C58C");
extern int ControllerD4C8_D_8006C628 __asm__("D_8006C628");
extern unsigned char ControllerD4C8_D_8006C7B4 __asm__("D_8006C7B4");
extern int ControllerD4C8_D_8006E344 __asm__("D_8006E344");
extern int ControllerD4C8Field280 __asm__("D_80070328+0x280");
extern unsigned char ControllerD4C8_D_80070328 __asm__("D_80070328");
extern unsigned char ControllerD4C8_D_level_22_8009B090 __asm__("D_level_22_8009B090");
extern unsigned char ControllerD4C8_func_80027A60 __asm__("func_80027A60");
extern unsigned char ControllerD4C8_func_80027EE4 __asm__("func_80027EE4");
extern unsigned char ControllerD4C8_func_80029AA0 __asm__("func_80029AA0");
extern unsigned char ControllerD4C8Address __asm__("func_level_22_8007574C");
extern unsigned char main_TEXT_END;
extern unsigned char main_TEXT_START;

void func_level_22_8008D4C8(Moby *inputOwner) {
    struct {int sp20;int sp24;int sp28;char pad_2c[4];Vector3D sp30;char pad_3c[4];int sp40;int sp44;volatile int sp48;char pad_4c[4];int sp50;int sp54;volatile int sp58;char pad_5c[4];} originalStack;

register Moby *owner18 __asm__("$18")=inputOwner;

    register int cameraMode7 __asm__("$7");
    register int *position4 __asm__("$4");
    register Vector3D *vector16 __asm__("$16");
    register int value2 __asm__("$2");
    register int sample3 __asm__("$3");
    register unsigned int limit6 __asm__("$6");
    register unsigned int limit7 __asm__("$7");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int archive4 __asm__("$4");
    register int saved16 __asm__("$16");
    register int checksum3 __asm__("$3");
    register int checksum3Second __asm__("$3");
    register int bit4 __asm__("$4");
    register int bit4Second __asm__("$4");
    register int byte5 __asm__("$5");
    register int byte5Second __asm__("$5");
    register int checksum2 __asm__("$2");
    register int checksum2Second __asm__("$2");
    signed char stateByte2;
    unsigned int address3;
    unsigned int address3Second;
    register unsigned int nextAddress3 __asm__("$3");
    unsigned char state;
    register int subtype3 __asm__("$3");
    register void * tag17 __asm__("$17");

    __asm__("" : "=r"(owner18):"0"(owner18));
    tag17 = owner18->mobyTag;
    saved16 = ControllerD4C8_rand() & 7;
    if ((value2 = saved16 < 3)) {
        originalStack.sp20 = (ControllerD4C8_rand() & 0x1F) - 0x10;
        originalStack.sp24 = (ControllerD4C8_rand() & 0x1F) - 0x10;
        originalStack.sp28 = (ControllerD4C8_rand() & 0x1F) + 0x10;
        argument4 = (int)owner18;
        argument5 = saved16;
        vector16 = &originalStack.sp30;
        ControllerD4C8_func_80055F14(argument4, argument5, vector16);
        SpawnParticle(1, 0x26, vector16, (Vector3D *) &originalStack.sp20);
    }
    if ((unsigned int) (ControllerD4C8_D_8006C628 - 1) < 7U) {
        M2C_FIELD(tag17, int *, 0x38) = (int) ControllerD4C8_func_8002803C(7, 0xDC, &ControllerD4C8_func_80027EE4, &ControllerD4C8_func_80027A60, &ControllerD4C8_func_80029AA0, &ControllerD4C8_D_8006C628, 8);
    }
    state = owner18->state;
    switch (state) {                              /* Original states 0, 1 and 2. */
    case 0:
        if ((owner18->substate == 0) && (ControllerD4C8_D_8006C628 == 8) && !(ControllerD4C8_D_8006C7B4 & 4)) {
            ControllerD4C8_func_80028154(M2C_FIELD(tag17, int *, 0x38));
            __asm__("" ::: "$6");
            if (M2C_FIELD(&ControllerD4C8_D_80070328, int *, 0x24C) == 3) {
                value2 = 2;
                __asm__("" : "=r"(value2):"0"(value2));
                sample3 = (int)owner18->mobyTag;
                M2C_FIELD(sample3, signed char *, 5) = value2;
                value2 = owner18->angle.yaw;
                __asm__("" : "=r"(value2):"0"(value2):"$16");
                vector16 = (Vector3D*)&originalStack.sp40;
                value2 *= 2;
                sample3 = M2C_FIELD(&ControllerD4C8_D_80065920,short*,value2);
                argument4 = (int)vector16;
                originalStack.sp40 = (sample3 * 39) >> 6;
                value2 = owner18->angle.yaw;
                argument5 = (int)vector16;
                value2 *= 2;
                sample3 = M2C_FIELD(&ControllerD4C8_D_800658A0,short*,value2);
                __asm__("" : "=r"(sample3):"0"(sample3):"$6");
                value2 = M2C_FIELD(&ControllerD4C8_D_80070328, int *, 0x44);
                argument6 = (int)&owner18->position;
                originalStack.sp48 = 0;
                originalStack.sp48 = value2;
                value2 = (sample3 * 39) >> 6;
                originalStack.sp44 = value2;
                func_8004F194(argument4, argument5, argument6);
                position4 = (int *)vector16;
                argument6 = 0;
                argument5 = owner18->angle.yaw;
                __asm__("" : "=r"(argument5):"0"(argument5));
                cameraMode7 = 0x64;
            } else {
                value2 = 2;
                __asm__("" : "=r"(value2):"0"(value2));
                sample3 = (int)owner18->mobyTag;
                M2C_FIELD(sample3, signed char *, 5) = value2;
                value2 = owner18->angle.yaw;
                __asm__("" : "=r"(value2):"0"(value2):"$16");
                vector16 = (Vector3D*)&originalStack.sp50;
                value2 *= 2;
                sample3 = M2C_FIELD(&ControllerD4C8_D_80065920,short*,value2);
                argument4 = (int)vector16;
                originalStack.sp50 = (sample3 * 39) >> 6;
                value2 = owner18->angle.yaw;
                argument5 = (int)vector16;
                value2 *= 2;
                sample3 = M2C_FIELD(&ControllerD4C8_D_800658A0,short*,value2);
                __asm__("" : "=r"(sample3):"0"(sample3):"$6");
                value2 = M2C_FIELD(&ControllerD4C8_D_80070328, int *, 0x44);
                argument6 = (int)&owner18->position;
                originalStack.sp58 = 0;
                originalStack.sp58 = value2;
                value2 = (sample3 * 39) >> 6;
                originalStack.sp54 = value2;
                func_8004F194(argument4, argument5, argument6);
                position4 = (int *)vector16;
                argument6 = 0;
                argument5 = owner18->angle.yaw;
                __asm__("" : "=r"(argument5):"0"(argument5));
                cameraMode7 = 0;
            }
            ControllerD4C8_func_80013D44(position4, (argument5 + 0x80) & 0xFF, argument6, cameraMode7);
            if (ControllerD4C8Field280 < 0) {
                ControllerD4C8Field280 = 0;
            }
            owner18->substate = 1;
        }
        value2 = M2C_FIELD(tag17, unsigned int *, 0x34);
        sample3 = (int)&ControllerD4C8Address;
        value2 = (unsigned int)value2 < (unsigned int)sample3;
        argument4 = (int)owner18;
        if (!value2) {
            __asm__ volatile("" : "=r"(argument4):"0"(argument4):"$2");
            byte5 = 0;
            limit6 = (unsigned int)&ControllerD4C8_D_level_22_8009B090;
nextOverlayByte:
            address3 = M2C_FIELD(tag17, unsigned int *, 0x34);
            bit4 = 0;
            if (address3 < limit6) {
                M2C_FIELD(tag17, int *, 0x30) = (int) (M2C_FIELD(tag17, int *, 0x30) ^ (M2C_FIELD(address3, unsigned char *, 0) << 8));
                do {
                    checksum3 = M2C_FIELD(tag17, int *, 0x30);
                    if (checksum3 & 0x8000) {
                    checksum2 = (checksum3 * 2) ^ 0x8005;
                } else {
                    checksum2 = checksum3 * 2;
                }
                    M2C_FIELD(tag17, int *, 0x30) = checksum2;
                    bit4 += 1;
                } while (bit4 < 8);
                byte5 += 1;
                M2C_FIELD(tag17, unsigned int *, 0x34) = (unsigned int) (M2C_FIELD(tag17, unsigned int *, 0x34) + 1);
                if (byte5 < 0x40) {
                    goto nextOverlayByte;
                }
            }
            argument4 = (int)owner18;
        }
        if (ControllerD4C8_func_80037BBC(argument4, 0) != 0) {
            if (ControllerD4C8_D_8006C628 == 8) {
                if (!(ControllerD4C8_D_8006C7B4 & 4)) {
                    ControllerD4C8_D_8006C7B4 |= 4;
                }
            } else if (!(ControllerD4C8_D_8006C7B4 & 4)) {
                if (M2C_FIELD(&ControllerD4C8_D_80070328, int *, 0x24C) == 3) {
                    stateByte2 = 1;
                    if (ControllerD4C8_D_8006C628 == 0) {
                        M2C_FIELD(tag17, signed char *, 2) = 0;
                    } else {
                        goto setStateByte;
                    }
                } else {
                    stateByte2 = 6;
setStateByte:
                    M2C_FIELD(tag17, signed char *, 2) = stateByte2;
                }
            }
            ControllerD4C8_func_800512E4(owner18, 0, 1);
            owner18->state = 1;
        }
        address3Second = M2C_FIELD(tag17, unsigned int *, 0x34);
        argument4 = (int)&main_TEXT_END;
        if (address3Second < (unsigned int)argument4) {
            byte5Second = 0;
            if (address3Second <= 0x7FFFU) {
                M2C_FIELD(tag17, unsigned int *, 0x34) = (unsigned int) (ControllerD4C8_D_8006C58C + (&main_TEXT_START + 2));
            }
limit7 = argument4;
            limit6 = (unsigned int)&ControllerD4C8Address;
nextExecutableByte:
            bit4Second = 0;
            M2C_FIELD(tag17, int *, 0x30) = (int) (M2C_FIELD(tag17, int *, 0x30) ^ (M2C_FIELD(M2C_FIELD(tag17, unsigned int *, 0x34), unsigned char *, 0) << 8));
            do {
                checksum3Second = M2C_FIELD(tag17, int *, 0x30);
                if (checksum3Second & 0x8000) {
                    checksum2Second = (checksum3Second * 2) ^ 0x8005;
                } else {
                    checksum2Second = checksum3Second * 2;
                }
                M2C_FIELD(tag17, int *, 0x30) = checksum2Second;
                __asm__("" ::: "memory");
                bit4Second += 1;
            } while (bit4Second < 8);
            value2 = (M2C_FIELD(tag17, int *, 0x30) & 3) + 1;
            __asm__("" : "=r"(value2):"0"(value2));
            nextAddress3 = M2C_FIELD(tag17, unsigned int *, 0x34) + value2;
            M2C_FIELD(tag17, unsigned int *, 0x34) = nextAddress3;
            if (nextAddress3 >= limit7) {
                M2C_FIELD(tag17, unsigned int *, 0x34) = limit6;
                byte5Second = 0x40;
                __asm__("" : "=r"(byte5Second):"0"(byte5Second));
                }
            byte5Second += 1;
            if (byte5Second < 0x40) {
                goto nextExecutableByte;
            }
        }
        return;
    case 1:
        if (ControllerD4C8_D_8006E344 != state) {
            subtype3 = M2C_FIELD(tag17, unsigned char *, 4);
            saved16 = 2;
            if ((unsigned int) (subtype3 - 3) < 2U) {
                sample3 = M2C_FIELD(tag17, int *, 0x2C);
                value2 = sample3 * 0x58;
                sample3 = ControllerD4C8_D_8006C550;
                value2 += sample3;
                M2C_FIELD(value2, signed char *, 0x48) = saved16;
                archive4 = ControllerD4C8_D_8006C3F4;
                value2 = M2C_FIELD(&ControllerD4C8_D_800652B0, int *, 0x18);
                argument6 = M2C_FIELD(&ControllerD4C8_D_800652B6, unsigned short *, 0x18);
                argument5 = M2C_FIELD(&ControllerD4C8_D_800652B4, unsigned short *, 0x18);
                archive4 += value2;
                ControllerD4C8_func_8004F9C0(archive4, archive4 + argument5, argument6);
                func_80034F40(owner18, 0);
                owner18->state = saved16;
                return;
            }
            __asm__("" : "=r"(subtype3):"0"(subtype3));
            if ((subtype3 & 0xFF) == 2) {
                ControllerD4C8_func_800512E4(owner18, 0, 1);
                return;
            }
            goto resetOwner;
        }
        break;
    case 2:
        if (M2C_FIELD(((M2C_FIELD(tag17, int *, 0x2C) * 0x58) + ControllerD4C8_D_8006C550), unsigned char *, 0x48) == 3) {
            goto resetOwner;
        }
        break;
    }
    return;
resetOwner:
    owner18->state = 0;
    func_80034F40(owner18, 0);
}
#undef M2C_FIELD


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_22/moby/func_level_22_8008DAF4.s SHA256 2887300e5ebe41f63eadb5667932695777bd641a438f3cd693fa606633a711e5. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Controller8DAF4_func_800359A4() __asm__("func_800359A4");                 /* extern */
int Controller8DAF4_func_8003BABC() __asm__("func_8003BABC");         /* extern */
int Controller8DAF4_func_8003BE70() __asm__("func_8003BE70");                          /* extern */
int Controller8DAF4_func_8003BFC0() __asm__("func_8003BFC0");                      /* extern */
int Controller8DAF4_func_8004E880() __asm__("func_8004E880");           /* extern */
int Controller8DAF4_func_8004EDE8() __asm__("func_8004EDE8");                  /* extern */
int Controller8DAF4_func_8004F110() __asm__("func_8004F110");              /* extern */
int Controller8DAF4_func_8004F178() __asm__("func_8004F178");                /* extern */
int Controller8DAF4_func_8004F194() __asm__("func_8004F194");         /* extern */
int Controller8DAF4_func_8004F1C8() __asm__("func_8004F1C8");         /* extern */
int Controller8DAF4_func_8004F334() __asm__("func_8004F334");                   /* extern */
int Controller8DAF4_func_80055F14() __asm__("func_80055F14");          /* extern */
int Controller8DAF4_rand() __asm__("rand");                                         /* extern */
extern unsigned char Controller8DAF4_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller8DAF4_D_80065920 __asm__("D_80065920");
extern int Controller8DAF4_D_8006C640 __asm__("D_8006C640");
extern int Controller8DAF4_D_80070328 __asm__("D_80070328");
extern void *(*Controller8DAF4_SpawnParticle)() __asm__("SpawnParticle");

void func_level_22_8008DAF4(void *inputOwner) {
    register void *owner __asm__("$19")=inputOwner;
    /* Original scratch words occupy 0x10..0x94; saves begin at 0x98. */
    struct {int sp10,sp14,pad18,pad1C,sp20,sp24,sp28,pad2C,sp30,sp34,sp38,pad3C,sp40,sp44,sp48,pad4C,sp50,pad54,pad58,pad5C,sp60,pad64,pad68,pad6C,sp70,sp74,sp78,pad7C,sp80,pad84,pad88,pad8C,pad90,pad94;} originalFrame;

    register int temp_v1_3 __asm__("$3");
    int rawProduct;
    register int scalar4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register void *ownerVectorCState4 __asm__("$16");
    register void *ownerVectorCState2 __asm__("$16");
    int temp_a0;
    register int ownerXState0 __asm__("$7");
    register int ownerXState4 __asm__("$7");
    int distanceWordState0;
    int distanceWordState4;
    int temp_v1_2;
    int temp_v1_4;
    int temp_v1_5;
    register int directionWord __asm__("$2");
    register void *call4 __asm__("$4");
    register void *particleCallback __asm__("$2");
    unsigned char stateByte;
    register void *privateData __asm__("$18");
    register void *linkedOwnerState0 __asm__("$2");
    register void *linkedOwnerState4 __asm__("$2");
    register void *timerFieldPointer __asm__("$4");

    stateByte = M2C_FIELD(owner, unsigned char *, 0x48);
    privateData = M2C_FIELD(owner, void **, 0);
    switch (stateByte) {
    case 0:
        if (M2C_FIELD(M2C_FIELD(privateData, void **, 0), unsigned char *, 0x49) != 0) {
            if (Controller8DAF4_D_8006C640 == 0) {
                M2C_FIELD(owner, unsigned char *, 0x44) = 0U;
                M2C_FIELD(owner, unsigned char *, 0x48) = 2U;
                return;
            }
            word2=0x168;
            M2C_FIELD(privateData, short *, 0xA)=word2;
            __asm__("" : "=r"(word2):"0"(word2));
            M2C_FIELD(privateData, short *, 0xA)=word2-M2C_FIELD(privateData,unsigned short*,0xC);
            M2C_FIELD(privateData, unsigned short *, 0x10) = (unsigned short) ((Controller8DAF4_rand() & 0x1F) + 0x60);
            if (M2C_FIELD(owner, unsigned char *, 0x3C) != 0) {
                call6=0;
                __asm__("" : "=r"(call6):"0"(call6):"$2");
                word2=0x14;
                M2C_FIELD(privateData, short *, 0x12)=word2;
                __asm__("" : "=r"(word2):"0"(word2):"memory");
                linkedOwnerState0 = M2C_FIELD(privateData, void **, 0);
                ownerXState0 = M2C_FIELD(owner, int *, 0xC);
                M2C_FIELD(privateData, unsigned char *, 0x14) = Controller8DAF4_func_8004E880(ownerXState0 - M2C_FIELD(linkedOwnerState0, int *, 0xC), M2C_FIELD(owner, int *, 0x10) - M2C_FIELD(linkedOwnerState0, int *, 0x10), call6, ownerXState0);
                distanceWordState0 = Controller8DAF4_func_8004F334(owner + 0xC, M2C_FIELD(privateData, void **, 0) + 0xC);
                M2C_FIELD(privateData, int *, 4) = distanceWordState0;
                M2C_FIELD(privateData, short *, 0xE) = (short) (((distanceWordState0 / (short) M2C_FIELD(privateData, short *, 0xA)) + 1) * 2);
                M2C_FIELD(owner, unsigned char *, 0x48) = 1U;
                return;
            }
            M2C_FIELD(privateData, short *, 0x12) = (short) (((short)M2C_FIELD(privateData, unsigned short *, 0xC) / 30) + 0x14);
            M2C_FIELD(owner, unsigned char *, 0x48) = 4U;
            return;
        }
    default:
        return;
    case 4:
        M2C_FIELD(privateData, unsigned short *, 0x10) = (unsigned short) (M2C_FIELD(privateData, unsigned short *, 0x10) + 1);
        if (Controller8DAF4_func_800359A4(privateData + 0xC, 2) != 0) {
            linkedOwnerState4 = M2C_FIELD(privateData, void **, 0);
            ownerXState4 = M2C_FIELD(owner, int *, 0xC);
            directionWord = Controller8DAF4_func_8004E880(ownerXState4 - M2C_FIELD(linkedOwnerState4, int *, 0xC), M2C_FIELD(owner, int *, 0x10) - M2C_FIELD(linkedOwnerState4, int *, 0x10), 0, ownerXState4);
            M2C_FIELD(privateData, unsigned char *, 0x14) = directionWord;
            word2=((directionWord-0x80)&0xFF)*2;
            __asm__("" : "=r"(word2):"0"(word2));
            ownerVectorCState4=owner+0xC;
            word2=*(short*)(&Controller8DAF4_D_80065920+word2);
            __asm__("" : "=r"(word2):"0"(word2));
            call4=ownerVectorCState4;
            word2=word2>>3;
            M2C_FIELD(owner,int*,0xC)=word2;
            word2=M2C_FIELD(privateData,unsigned char*,0x14);
            __asm__("" : "=r"(word2):"0"(word2));
            call5=ownerVectorCState4;
            __asm__("" : "=r"(call5):"0"(call5));
            word2=((word2+0x80)&0xFF)*2;
            word2=*(short*)(&Controller8DAF4_D_800658A0+word2);
            __asm__("" : "=r"(word2):"0"(word2));
            call6=&Controller8DAF4_D_80070328;
            __asm__("" : "=r"(call6):"0"(call6));
            M2C_FIELD(owner,int*,0x14)=0;
            __asm__ volatile("" : "=r"(word2):"0"(word2):"memory");
            M2C_FIELD(owner,int*,0x10)=word2>>3;
            Controller8DAF4_func_8004F194(call4,call5,call6);
            distanceWordState4 = Controller8DAF4_func_8004F334(ownerVectorCState4, M2C_FIELD(privateData, void **, 0) + 0xC);
            M2C_FIELD(privateData, int *, 4) = distanceWordState4;
            M2C_FIELD(privateData, short *, 0xE) = (short) ((distanceWordState4 / (short) M2C_FIELD(privateData, short *, 0xA)) * 2);
            Controller8DAF4_func_8004F178(&originalFrame.sp10, ownerVectorCState4);
            word2=Controller8DAF4_rand();
            word3=originalFrame.sp10;
            word2&=0x1FF;word3-=0x100;
            __asm__("" : "=r"(word3):"0"(word3));
            word3+=word2;
            __asm__("" : "=r"(word3):"0"(word3));
            originalFrame.sp10=word3;
            word2=Controller8DAF4_rand();
            word3=originalFrame.sp14;
            word2&=0x1FF;word3-=0x100;
            __asm__("" : "=r"(word3):"0"(word3));
            word3+=word2;
            __asm__("" : "=r"(word3):"0"(word3));
            originalFrame.sp14=word3;
            originalFrame.sp20 = (Controller8DAF4_rand() & 0x1F) - 0x10;
            originalFrame.sp24 = (Controller8DAF4_rand() & 0x1F) - 0x10;
            word2=Controller8DAF4_rand();
            scalar4=1;call5=(void*)0x26;call6=&originalFrame.sp10;
            __asm__("" : "=r"(scalar4),"=r"(call5),"=r"(call6):"0"(scalar4),"1"(call5),"2"(call6));
            originalFrame.sp28=(word2&0x1F)+0x10;
            __asm__ volatile("" ::: "memory");
            particleCallback=(void*)Controller8DAF4_SpawnParticle;
            __asm__("" : "=r"(particleCallback):"0"(particleCallback));
            ((void*(*)())particleCallback)(scalar4,call5,call6,&originalFrame.sp20);
            M2C_FIELD(owner, unsigned char *, 0x48) = 1U;
            return;
        }
        break;
    case 1:
        if (M2C_FIELD(privateData, short *, 8) == 0) {
            timerFieldPointer = privateData + 0xA;
            if (Controller8DAF4_func_8003BFC0(M2C_FIELD(privateData, void **, 0), M2C_FIELD(privateData, unsigned char *, 0x15)) == 0) {
                M2C_FIELD(privateData, unsigned char *, 0x15) = Controller8DAF4_func_8003BABC(M2C_FIELD(privateData, void **, 0), 1, 4);
                timerFieldPointer = privateData + 0xA;
            }
        }
        timerFieldPointer=privateData+0xA;
        if (Controller8DAF4_func_800359A4(timerFieldPointer, 2) != 0) {
            if (M2C_FIELD(privateData, short *, 8) == 0) {
                if (Controller8DAF4_func_8003BFC0(M2C_FIELD(privateData, void **, 0), M2C_FIELD(privateData, unsigned char *, 0x15)) != 0) {
                    Controller8DAF4_func_8003BE70(M2C_FIELD(privateData, unsigned char *, 0x15));
                }
                M2C_FIELD(privateData, unsigned char *, 0x15) = 0xFFU;
            }
            M2C_FIELD(privateData, short *, 0x12) = 0;
            M2C_FIELD(owner, unsigned char *, 0x48) = 3U;
        }
        scalar4=M2C_FIELD(privateData,unsigned short*,0x10);
        __asm__("" : "=r"(scalar4):"0"(scalar4));
        word3=M2C_FIELD(privateData,volatile unsigned short*,0x10);
        __asm__ volatile("" : "=r"(word3):"0"(word3):"memory");
        word2=M2C_FIELD(privateData,unsigned char*,0x14);
        __asm__("" : "=r"(word2),"=r"(word3):"0"(word2),"1"(word3));
        scalar4+=1;
        word3=(word3<<16)>>21;
        __asm__ volatile("" : "=r"(word3):"0"(word3):"memory");
        M2C_FIELD(privateData,unsigned short*,0x10)=scalar4;
        scalar4=M2C_FIELD(privateData,short*,0xE);
        word2+=word3;
        M2C_FIELD(privateData,unsigned char*,0x14)=word2;
        __asm__ volatile("" ::: "memory");
        word2=M2C_FIELD(privateData,int*,4);
        word3=M2C_FIELD(privateData,short*,0xE);
        word2-=scalar4;
        M2C_FIELD(privateData,int*,4)=word2;
        word2=word3;
        __asm__("" : "=r"(word2),"=r"(word3):"0"(word2),"1"(word3));
        if(word3>=31) M2C_FIELD(privateData,short*,0xE)=word2-8;
        temp_a0 = (int) (*(short*)(&Controller8DAF4_D_80065920 + (M2C_FIELD(privateData, unsigned char *, 0x14) * 2)) * M2C_FIELD(privateData, int *, 4)) >> 0xC;
        originalFrame.sp30 = temp_a0;
        word2=M2C_FIELD(privateData,unsigned char*,0x14);
        word2*=2;
        __asm__("" : "=r"(word2):"0"(word2));
        word3=*(short*)(&Controller8DAF4_D_800658A0+word2);
        word2=M2C_FIELD(privateData,int*,4);
        __asm__ volatile("" : "=r"(word3),"=r"(word2):"0"(word3),"1"(word2):"memory");
        rawProduct=word3*word2;
        originalFrame.sp38=0;
        originalFrame.sp34=rawProduct>>12;
        M2C_FIELD(owner, int *, 0xC) = (int) (M2C_FIELD(M2C_FIELD(privateData, void **, 0), int *, 0xC) + temp_a0);
        M2C_FIELD(owner, int *, 0x10) = (int) (M2C_FIELD(M2C_FIELD(privateData, void **, 0), int *, 0x10) + originalFrame.sp34);
        M2C_FIELD(owner, int *, 0x14) = (int) (M2C_FIELD(owner, int *, 0x14) + M2C_FIELD(privateData, short *, 0x12));
        Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), M2C_FIELD(privateData, short *, 8) * 2, &originalFrame.sp40);
        Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), (M2C_FIELD(privateData, short *, 8) * 2) | 1, &originalFrame.sp50);
        Controller8DAF4_func_8004F1C8(&originalFrame.sp40, &originalFrame.sp50, &originalFrame.sp40);
        if ((unsigned short) M2C_FIELD(privateData, short *, 8) < 2U) {
            M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) (-Controller8DAF4_func_8004E880(Controller8DAF4_func_8004EDE8(&originalFrame.sp40, 0), originalFrame.sp48, 0) - 0x40);
            M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(M2C_FIELD(privateData, void **, 0), unsigned char *, 0x46);
        } else {
            M2C_FIELD(owner, unsigned char *, 0x45) = Controller8DAF4_func_8004E880(Controller8DAF4_func_8004EDE8(&originalFrame.sp40, 0), originalFrame.sp48, 0);
            M2C_FIELD(owner, unsigned char *, 0x46) = Controller8DAF4_func_8004E880(originalFrame.sp40, originalFrame.sp44, 0);
        }
        M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x44) + 0xA);
        return;
    case 3:
        Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), M2C_FIELD(privateData, short *, 8) * 2, &originalFrame.sp30);
        Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), (M2C_FIELD(privateData, short *, 8) * 2) | 1, &originalFrame.sp60);
        Controller8DAF4_func_8004F194(&originalFrame.sp30, &originalFrame.sp30, &originalFrame.sp60);
        Controller8DAF4_func_8004F110(&originalFrame.sp30, 1);
        M2C_FIELD(privateData, short *, 0x12) = (short) ((unsigned short) M2C_FIELD(privateData, short *, 0x12) - 0xA);
        word2=originalFrame.sp30;
        __asm__("" : "=r"(word2):"0"(word2));
        word3=M2C_FIELD(owner,int*,0xC);
        word2=(word2-word3)>>3;
        word3+=word2;
        M2C_FIELD(owner,int*,0xC)=word3;
        word2=originalFrame.sp34;
        __asm__("" : "=r"(word2):"0"(word2));
        word3=M2C_FIELD(owner,int*,0x10);
        word2=(word2-word3)>>3;
        word3+=word2;
        M2C_FIELD(owner,int*,0x10)=word3;
        scalar4=M2C_FIELD(privateData,short*,0x12);
        word3=M2C_FIELD(owner,int*,0x14);
        word2=M2C_FIELD(owner,unsigned char*,0x44);
        word3+=scalar4;
        M2C_FIELD(owner,int*,0x14)=word3;
        __asm__ volatile("" ::: "memory");
        word3=M2C_FIELD(owner,volatile int*,0x14);
        word2>>=1;
        M2C_FIELD(owner,unsigned char*,0x44)=word2;
        word2=originalFrame.sp38;
        if(word2>=word3) {
            word2=2;
            __asm__("" : "=r"(word2):"0"(word2));
            M2C_FIELD(owner,unsigned char*,0x44)=0;
            word3=originalFrame.sp38;
            __asm__("" : "=r"(word3):"0"(word3));
            M2C_FIELD(owner,unsigned char*,0x48)=word2;
            M2C_FIELD(owner,int*,0x14)=word3;
            return;
        }
        break;
    case 2:
        Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), M2C_FIELD(privateData, short *, 8) * 2, &originalFrame.sp70);
        Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), (M2C_FIELD(privateData, short *, 8) * 2) | 1, &originalFrame.sp80);
        ownerVectorCState2 = owner + 0xC;
        Controller8DAF4_func_8004F194(ownerVectorCState2, &originalFrame.sp70, &originalFrame.sp80);
        Controller8DAF4_func_8004F110(ownerVectorCState2, 1);
        if (M2C_FIELD(privateData, short *, 8) == 0) {
            M2C_FIELD(owner, int *, 0x14) = (int) (M2C_FIELD(owner, int *, 0x14) + 0x64);
        }
        Controller8DAF4_func_8004F1C8(&originalFrame.sp70, &originalFrame.sp80, &originalFrame.sp70);
        if ((unsigned short) M2C_FIELD(privateData, short *, 8) < 2U) {
            M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) (-Controller8DAF4_func_8004E880(Controller8DAF4_func_8004EDE8(&originalFrame.sp70, 0), originalFrame.sp78, 0) - 0x40);
            Controller8DAF4_func_80055F14(M2C_FIELD(privateData, void **, 0), M2C_FIELD(privateData, short *, 8) + 0x1C, &originalFrame.sp70);
            Controller8DAF4_func_8004F1C8(&originalFrame.sp70, &originalFrame.sp70, &originalFrame.sp80);
        } else {
            M2C_FIELD(owner, unsigned char *, 0x45) = Controller8DAF4_func_8004E880(Controller8DAF4_func_8004EDE8(&originalFrame.sp70, 0), originalFrame.sp78, 0);
        }
        M2C_FIELD(owner, unsigned char *, 0x46) = Controller8DAF4_func_8004E880(originalFrame.sp70, originalFrame.sp74, 0);
        break;
    }
}
#undef M2C_FIELD


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008E278.
* Assembly SHA256 2e0ff6bb9c9fd6d796eadf238051624efecf9a4413e74f69a58690ec5e8aa5e3.
* AI generated; not human reviewed. All517 original instructions and56
* selectors across the8/14/34-entry tables and actual targets are required.
* Frame0x70 retains S0..S7/FP/RA and original SP20..47 local extent.
* The original conditional code stores at8008E308/14 write03E00008 and0
* to func8005663C and+4; they are ordinary evidenced32-bit memory stores.
* Fourteen-entry initialization retains the original selector/mode/offset
* branches,SP40 private-pointer store and T0 reload. Every reachable entry
* assigns its selector and mode. Vertical offset and counter are ordinary
* C scalars; FP/S0 allocation is natural,with no fixed FP or undefined
* saved-register input. Shared mode/vector/state joins retain their original
* physical order. Both vector paths retain independent private-pointer loads
* and original signed subtraction/shift3 order. The final helper delay slot
* remains NOP before the independent owner-address producer. Empty fully
* initialized metadata emits0 CPU instructions. No opcode assembly or live
* alias overlap. Tags are scheduling identifiers,not retail addresses.
* Confidence is binary identity after all gates. Raw units/fixed point,
* full helper contracts,caller cadence and synchronized retail runtime remain
* open. Cadence is per invocation. Falsification: every native/linked word,
* actual transfer/table target,original data byte,EXE and all overlay hashes. */
#define Actor22_8E278Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Actor22_8E278Call13AE4View1() __asm__("func_80013AE4");
int Actor22_8E278Call13B7CView1() __asm__("func_80013B7C");
int Actor22_8E278Call34F40View1() __asm__("func_80034F40");
int Actor22_8E278Call34F80View1() __asm__("func_80034F80");
int Actor22_8E278Call3585CView1() __asm__("func_8003585C");
int Actor22_8E278Call359A4View1() __asm__("func_800359A4");
int Actor22_8E278Call35A80View1() __asm__("func_80035A80");
int Actor22_8E278Call3B7B4View1() __asm__("func_8003B7B4");
int Actor22_8E278Call3BABCView1() __asm__("func_8003BABC");
int Actor22_8E278Call3BE70View1() __asm__("func_8003BE70");
int Actor22_8E278Call3BFC0View1() __asm__("func_8003BFC0");
int Actor22_8E278Call4E880View1() __asm__("func_8004E880");
int Actor22_8E278Call4F178View1() __asm__("func_8004F178");
int Actor22_8E278Call55D24View1() __asm__("func_80055D24");
int Actor22_8E278Call55E84View1() __asm__("func_80055E84");
extern int Actor22_8E278Data6C550View1 __asm__("D_8006C550");
extern int Actor22_8E278Data6C770View1 __asm__("D_8006C770");
extern int Actor22_8E278Data6C7F8View1 __asm__("D_8006C7F8");
extern int Actor22_8E278Data6D088View1 __asm__("D_8006D088");
extern int Actor22_8E278Data6E028View1 __asm__("D_8006E028");
extern int Actor22_8E278Data6E048View1 __asm__("D_8006E048");
extern int Actor22_8E278Data6E53CView1 __asm__("D_8006E53C");
extern int Actor22_8E278Data9B090View1 __asm__("D_level_22_8009B090");
extern int Actor22_8E278Call5663CView1 __asm__("func_8005663C");
extern void*(*Actor22_8E278DataSpawnMobyView1)() __asm__("SpawnMoby");
void func_level_22_8008E278(void *input) {
    register void *ownerRecord17 __asm__("$17");
    int entryIndexOrAngle;
    register int entrySelectorOrFlag18 __asm__("$18"), entryModeOrFlag19 __asm__("$19"), entryOffsetOrHeading20 __asm__("$20"), spawnedRecord21 __asm__("$21"), entryVerticalStep22 __asm__("$22"), privateRecord23 __asm__("$23");
    register int privateAddress8 __asm__("$8");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    int entryVerticalOffset;
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C;
        void *sp40;
        int sp44;
    }
    originalFrame;
    void *temporaryPointer1;
    void *temporaryPointer2;
    void *temporaryPointer3;
    void *temporaryPointer4;
    void *temporaryPointer5;
    void *temporaryPointer6;
    void *temporaryPointer7;
    void *temporaryPointer8;
    ownerRecord17 = input;
    __asm__("":"=r"(ownerRecord17):"0"(ownerRecord17));
    privateRecord23 = (int)Actor22_8E278Field(ownerRecord17, void**, 0);
    argumentWord4 = Actor22_8E278Field((Actor22_8E278Field(privateRecord23, int*, 0xC)*0x58)+Actor22_8E278Data6C550View1, int*, 0);
    if ((Actor22_8E278Field(argumentWord4, int *, 0x34) == &Actor22_8E278Data9B090View1) && (Actor22_8E278Field(argumentWord4, int *, 0x30) != 0)) {
        Actor22_8E278Field(&Actor22_8E278Call5663CView1, int *, 0) = 0x03E00008;
        Actor22_8E278Field(&Actor22_8E278Call5663CView1, int *, 4) = 0;
        Actor22_8E278Field(argumentWord4, int *, 0x30) = 0;
    }
    rawWord3 = Actor22_8E278Field(ownerRecord17, unsigned char *, 0x48);
    switch (rawWord3) {
    case 0:
        entryIndexOrAngle = 0;
        entryVerticalStep22 = -0x4B;
        do {
            argumentWord4 = 0x23E;
            rawWord2 = (int)Actor22_8E278DataSpawnMobyView1;
            __asm__ __volatile__(""::"r"(rawWord2):"$5");
            argumentWord5 = (int)ownerRecord17;
            spawnedRecord21 = (int)((void*(*)())rawWord2)(argumentWord4, argumentWord5);
            __asm__("":"=r"(spawnedRecord21):"0"(spawnedRecord21));
            entryVerticalOffset = 0;
            if (spawnedRecord21 != 0) {
                rawWord2 = Actor22_8E278Field(privateRecord23, int*, 0x10);
                privateAddress8 = Actor22_8E278Field(spawnedRecord21, int*, 0);
                __asm__ __volatile__(""::"r"(privateAddress8):"$20");
                entryOffsetOrHeading20 = 0;
                originalFrame.sp40 = (void*)privateAddress8;
                if (rawWord2 == 0){
                    Actor22_8E278Field(privateRecord23, void **, 0x10) = spawnedRecord21;
                }
                Actor22_8E278Call4F178View1(spawnedRecord21 + 0xC, Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 0), int *, 0xC) + (entryIndexOrAngle * 0x10));
                switch (entryIndexOrAngle) {
                case 0:
                    entryModeOrFlag19 = 1;
                    entrySelectorOrFlag18 = 0;
                    entryVerticalOffset = 0xFA;
                    break;
                case 1:
                    entryModeOrFlag19 = 3;
                    entrySelectorOrFlag18 = 4;
                    break;
                case 2:
                    entryModeOrFlag19 = 3;
                    entrySelectorOrFlag18 = 7;
                    break;
                case 3:
                case 4:
                    entryModeOrFlag19 = 4;
                    entrySelectorOrFlag18 = entryIndexOrAngle + 7;
                    break;
                case 5:
                    entryModeOrFlag19 = 2;
                    entrySelectorOrFlag18 = 1;
                    entryVerticalOffset = 0xC8;
                    break;
                case 6:
                case 7:
                    entryModeOrFlag19 = 0;
                    entrySelectorOrFlag18 = entryIndexOrAngle - 4;
                    goto setSharedEntryOffset;
                case 8:
                case 9:
                    entryModeOrFlag19 = 0;
                    entrySelectorOrFlag18 = entryIndexOrAngle - 3;
                    goto setSharedEntryOffset;
                case 10:
                case 11:
                    entryModeOrFlag19 = 0;
                    entrySelectorOrFlag18 = entryIndexOrAngle - 2;
                    goto setSharedEntryOffset;
                case 12:
                case 13:
                    entryModeOrFlag19 = 0;
                    entrySelectorOrFlag18 = entryIndexOrAngle;
                    setSharedEntryOffset:entryOffsetOrHeading20 = entryVerticalStep22*2;
                    break;
                }
                Actor22_8E278Field(spawnedRecord21, int *, 0x14) = (int) (Actor22_8E278Field(spawnedRecord21, int *, 0x14) + entryVerticalOffset);
                Actor22_8E278Call34F80View1(spawnedRecord21, entryModeOrFlag19);
                privateAddress8 = (int)originalFrame.sp40;
                Actor22_8E278Field(privateAddress8, void**, 0) = ownerRecord17;
                Actor22_8E278Field(privateAddress8, unsigned short*, 8) = entrySelectorOrFlag18;
                Actor22_8E278Field(privateAddress8, short*, 12) = entryOffsetOrHeading20;
            }
            entryIndexOrAngle += 1;
            entryVerticalStep22 += 0xF;
        }
        while ((int) entryIndexOrAngle < 0xE);
        if (Actor22_8E278Field(ownerRecord17, unsigned char *, 0x49) != 0) {
            Actor22_8E278Call55D24View1(ownerRecord17, 1);
            Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 4), short *, 2) = 0;
            Actor22_8E278Field(ownerRecord17, unsigned char *, 0x48) = 3U;
            Actor22_8E278Call34F40View1(ownerRecord17, 3);
            return;
        }
        rawWord2 = 1;
        Actor22_8E278Field(ownerRecord17, signed char *, 0x41) = 0;
        Actor22_8E278Field(ownerRecord17, signed char *, 0x4C) = 0;
        Actor22_8E278Field(ownerRecord17, signed char *, 0x4D) = 0;
        Actor22_8E278Field(ownerRecord17, int *, 8) = 0;
        goto storeSharedState;
    default:
        return;
    case 2:
        Actor22_8E278Call13AE4View1(Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 8), int *, 0xC), ownerRecord17 + 0xC);
        rawWord2 = 5;
        goto storeSharedState;
    case 5:
        if (Actor22_8E278Data6E048View1 == 1) {
            Actor22_8E278Field(ownerRecord17, signed char *, 0x41) = 1;
            Actor22_8E278Field(ownerRecord17, signed char *, 0x4C) = 0x10;
            Actor22_8E278Field(ownerRecord17, signed char *, 0x4D) = 1;
            Actor22_8E278Call55D24View1(ownerRecord17, 1);
            Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 4), short *, 2) = 0;
            if (Actor22_8E278Field(ownerRecord17, unsigned char *, 0x49) == 0) {
                Actor22_8E278Call3BABCView1(ownerRecord17, 0, 0);
                entryIndexOrAngle = ownerRecord17 + 0x49;
                Actor22_8E278Field(ownerRecord17, unsigned char *, 0x49) = 1U;
                Actor22_8E278Call3B7B4View1(entryIndexOrAngle, 1, &Actor22_8E278Data6D088View1);
                Actor22_8E278Call3B7B4View1(entryIndexOrAngle, 1, &Actor22_8E278Data6C7F8View1);
                Actor22_8E278Field(privateRecord23, short *, 0x18) = 0xB4;
                Actor22_8E278Field(privateRecord23, unsigned short *, 0x1A) = 0U;
            }
            else {
                Actor22_8E278Field(privateRecord23, unsigned short *, 0x1A) = 7U;
            }
            rawWord2 = 4;
            goto storeSharedState;
        }
        break;
    case 4:
        if (Actor22_8E278Call359A4View1(privateRecord23 + 0x18, 2) != 0) {
            Actor22_8E278Field(ownerRecord17, unsigned char *, 0x48) = 6U;
        }
    case 6:
        entryModeOrFlag19 = 0;
        entrySelectorOrFlag18 = 0;
        entryIndexOrAngle = -1;
        if (Actor22_8E278Data6C770View1 != 0) {
            Actor22_8E278Field(privateRecord23, unsigned short *, 0x1A) = (unsigned short) (Actor22_8E278Field(privateRecord23, unsigned short *, 0x1A) + 1);
        }
        rawWord3 = (short) Actor22_8E278Field(privateRecord23, unsigned short *, 0x1A);
        switch (rawWord3) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            if (Actor22_8E278Call3BFC0View1(ownerRecord17, Actor22_8E278Field(privateRecord23, short *, 0x14)) == 0) {
                Actor22_8E278Field(privateRecord23, short *, 0x14) = Actor22_8E278Call3BABCView1(ownerRecord17, 1, 4);
            }
            Actor22_8E278Call34F40View1(ownerRecord17, 0);
            break;
        case 32:
            temporaryPointer5 = Actor22_8E278Field(privateRecord23, void **, 4);
            temporaryPointer1 = (Actor22_8E278Field(temporaryPointer5, short *, 2) * 0x10) + Actor22_8E278Field(temporaryPointer5, int *, 0xC);
            entryIndexOrAngle = (Actor22_8E278Call4E880View1(Actor22_8E278Field(temporaryPointer1, int *, 0) - Actor22_8E278Field(ownerRecord17, int *, 0xC), Actor22_8E278Field(temporaryPointer1, int *, 4) - Actor22_8E278Field(ownerRecord17, int *, 0x10), 0) + 0xC0) & 0xFF;
        case 7:
            if (Actor22_8E278Call3BFC0View1(ownerRecord17, Actor22_8E278Field(privateRecord23, short *, 0x14)) != 0) {
                Actor22_8E278Call3BE70View1(Actor22_8E278Field(privateRecord23, short *, 0x14));
            }
            Actor22_8E278Field(privateRecord23, short *, 0x14) = -1;
        case 9:
        case 15:
        case 16:
        case 22:
            Actor22_8E278Call34F40View1(ownerRecord17, 2);
            break;
        case 8:
            Actor22_8E278Call34F40View1(ownerRecord17, 1);
            break;
        case 10:
            Actor22_8E278Call34F40View1(ownerRecord17, 3);
            break;
        case 11:
            Actor22_8E278Call34F40View1(ownerRecord17, 4);
            break;
        case 13:
            Actor22_8E278Call34F40View1(ownerRecord17, 5);
            break;
        case 14:
            Actor22_8E278Call34F40View1(ownerRecord17, 6);
            break;
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 26:
        case 27:
        case 28:
        case 29:
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 7;
            goto callSharedModeAndReadRoute;
        case 30:
            argumentWord4 = (int)ownerRecord17;
            argumentWord5 = 8;
            callSharedModeAndReadRoute:Actor22_8E278Call34F40View1(argumentWord4, argumentWord5);
            temporaryPointer6 = Actor22_8E278Field(privateRecord23, void **, 4);
            temporaryPointer2 = (Actor22_8E278Field(temporaryPointer6, short *, 2) * 0x10) + Actor22_8E278Field(temporaryPointer6, int *, 0xC);
            entryIndexOrAngle = (Actor22_8E278Call4E880View1(Actor22_8E278Field(temporaryPointer2, int *, 0) - Actor22_8E278Field(ownerRecord17, int *, 0xC), Actor22_8E278Field(temporaryPointer2, int *, 4) - Actor22_8E278Field(ownerRecord17, int *, 0x10), 0) + 0x80) & 0xFF;
            if ((unsigned int) (Actor22_8E278Call55E84View1(ownerRecord17) - 0xA) < 0xDU) {
                entrySelectorOrFlag18 = 1;
            }
            break;
        case 31:
            Actor22_8E278Call34F40View1(ownerRecord17, 9);
            temporaryPointer7 = Actor22_8E278Field(privateRecord23, void **, 4);
            temporaryPointer3 = (Actor22_8E278Field(temporaryPointer7, short *, 2) * 0x10) + Actor22_8E278Field(temporaryPointer7, int *, 0xC);
            entryIndexOrAngle = (Actor22_8E278Call4E880View1(Actor22_8E278Field(temporaryPointer3, int *, 0) - Actor22_8E278Field(ownerRecord17, int *, 0xC), Actor22_8E278Field(temporaryPointer3, int *, 4) - Actor22_8E278Field(ownerRecord17, int *, 0x10), 0) + 0xC0) & 0xFF;
            break;
        case 23:
        case 24:
        case 25:
            Actor22_8E278Call34F40View1(ownerRecord17, 0xA);
            argumentWord6 = 0;
            __asm__ __volatile__(""::"r"(argumentWord6):"$18");
            entrySelectorOrFlag18 = 1;
            temporaryPointer8 = Actor22_8E278Field(privateRecord23, void **, 4);
            temporaryPointer4 = (Actor22_8E278Field(temporaryPointer8, short *, 2) * 0x10) + Actor22_8E278Field(temporaryPointer8, int *, 0xC);
            entryIndexOrAngle = (Actor22_8E278Call4E880View1(Actor22_8E278Field(temporaryPointer4, int *, 0) - Actor22_8E278Field(ownerRecord17, int *, 0xC), Actor22_8E278Field(temporaryPointer4, int *, 4) - Actor22_8E278Field(ownerRecord17, int *, 0x10), argumentWord6) + 0x80) & 0xFF;
            Actor22_8E278Call55E84View1(ownerRecord17);
            break;
        case 33:
            entryModeOrFlag19 = 1;
            break;
        }
        if (entryIndexOrAngle >= 0) {
            Actor22_8E278Call3585CView1(ownerRecord17, entryIndexOrAngle, 4, 0, 1, 0);
            if (entrySelectorOrFlag18 == 0) {
                Actor22_8E278Call55D24View1(ownerRecord17, 4);
                goto checkMovementFlag;
            }
            goto applyRouteMovement;
        }
    checkMovementFlag:
        if (entrySelectorOrFlag18 != 0) {
        applyRouteMovement:
            argumentWord6 = 0;
            if (entryIndexOrAngle != 0){
                rawWord3 = Actor22_8E278Field(privateRecord23, int*, 4);
                argumentWord4 = Actor22_8E278Field(ownerRecord17, int*, 12);
                argumentWord5 = Actor22_8E278Field(ownerRecord17, int*, 16);
                entryOffsetOrHeading20 = Actor22_8E278Field(ownerRecord17, unsigned char*, 0x46);
                rawWord2 = Actor22_8E278Field(rawWord3, short*, 2);
                rawWord3 = Actor22_8E278Field(rawWord3, int*, 12);
                rawWord2 <<= 4;
                rawWord2 += rawWord3;
                rawWord3 = Actor22_8E278Field(rawWord2, int*, 0);
                rawWord2 = Actor22_8E278Field(rawWord2, int*, 4);
                argumentWord4 = rawWord3-argumentWord4;
                argumentWord5 = rawWord2-argumentWord5;
                rawWord2 = Actor22_8E278Call4E880View1(argumentWord4, argumentWord5, argumentWord6);
                Actor22_8E278Field(ownerRecord17, unsigned char*, 0x46) = rawWord2;
            }
            Actor22_8E278Call35A80View1(ownerRecord17, Actor22_8E278Field(privateRecord23, void **, 4), 0x200, 0x64, 0, 4, 0x20, 0);
            if (entryIndexOrAngle != 0) {
                Actor22_8E278Field(ownerRecord17, unsigned char *, 0x46) = entryOffsetOrHeading20;
            }
            Actor22_8E278Call55D24View1(ownerRecord17, 4);
        }
        argumentWord5 = &originalFrame.sp30;
        if (Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 0x10), unsigned char *, 0x48) != 2) {
            originalFrame.sp30 = Actor22_8E278Field(ownerRecord17, int *, 0xC);
            originalFrame.sp34 = Actor22_8E278Field(ownerRecord17, int *, 0x10);
            originalFrame.sp38 = Actor22_8E278Data6E028View1 + ((int) (Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 0x10), int *, 0x14) - Actor22_8E278Data6E028View1) >> 3);
            argumentWord4 = Actor22_8E278Field(Actor22_8E278Field(privateRecord23, void **, 8), int *, 0xC);
            __asm__ __volatile__("":"=r"(argumentWord4):"0"(argumentWord4), "i"(517701):"memory");
            goto callSharedVectorHelper;
        }
        argumentWord5 = &originalFrame.sp20;
        if (Actor22_8E278Field(ownerRecord17, unsigned char*, 0x48) == 6){
            rawWord2 = Actor22_8E278Field(ownerRecord17, int*, 12);
            argumentWord4 = Actor22_8E278Data6E028View1;
            originalFrame.sp20 = rawWord2;
            rawWord2 = Actor22_8E278Field(ownerRecord17, int*, 16);
            originalFrame.sp24 = rawWord2;
            rawWord2 = Actor22_8E278Field(ownerRecord17, int*, 20);
            __asm__ __volatile__(""::"r"(rawWord2):"$3");
            rawWord3 = argumentWord4-768;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2 -= rawWord3;
            rawWord2 >>= 3;
            argumentWord4 += rawWord2;
            originalFrame.sp28 = argumentWord4;
            rawWord2 = Actor22_8E278Field(privateRecord23, int*, 8);
            argumentWord4 = Actor22_8E278Field(rawWord2, int*, 12);
            __asm__ __volatile__("":"=r"(argumentWord4):"0"(argumentWord4), "i"(517702):"memory");
        callSharedVectorHelper:
            Actor22_8E278Call13AE4View1(argumentWord4, argumentWord5);
        }
        if ((entryModeOrFlag19 != 0) || (Actor22_8E278Data6E53CView1 & 0x800)) {
            Actor22_8E278Call13B7CView1(1);
            rawWord2 = 7;
            goto storeSharedState;
        }
        break;
    case 7:
        if (Actor22_8E278Data6E048View1 & 1) {
            rawWord2 = Actor22_8E278Call3BFC0View1(ownerRecord17, Actor22_8E278Field(privateRecord23, short*, 0x14));
            argumentWord4 = (int)ownerRecord17+12;
            if (rawWord2 != 0){
                Actor22_8E278Call3BE70View1(Actor22_8E278Field(privateRecord23, short*, 0x14));
                __asm__ __volatile__("":"=r"(ownerRecord17):"0"(ownerRecord17));
                argumentWord4 = (int)ownerRecord17+12;
            }
            Actor22_8E278Field(privateRecord23, short *, 0x14) = -1;
            Actor22_8E278Call4F178View1(argumentWord4, privateRecord23+0x1C);
            Actor22_8E278Field(ownerRecord17, unsigned char *, 0x46) = (unsigned char) Actor22_8E278Field(privateRecord23, int *, 0x30);
            Actor22_8E278Call34F80View1(ownerRecord17, 0);
            Actor22_8E278Call55D24View1(ownerRecord17, 4);
            rawWord2 = 3;
            storeSharedState:Actor22_8E278Field(ownerRecord17, unsigned char*, 0x48) = rawWord2;
        }
        break;
    }
}
#undef Actor22_8E278Field


void func_level_22_8008EA8C(Moby* moby) {
    void** tag = moby->mobyTag;
    moby->updateDistance = 0xFF;
    switch (moby->state) {
    case 0:
        if (!spyro.critterMode) {
            func_80021ED8(*tag, 0xFC, 0);
            moby->state = 1;
        }
        break;
    case 1:
        if (spyro.critterMode) {
            func_80021ED8(*tag, 0xFC, 0);
            moby->state = 0;
        }
        break;
    }
}
