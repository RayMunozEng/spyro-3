#include "common.h"
#include "hud.h"
#include "savepoint.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "camera.h"
#include "mobyutil.h"
#include "ovl_header.h"
#include "spyro.h"

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
void func_level_18_80074A54(void *input) {
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
void func_level_18_800756B0(Moby* argument) {
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
void func_level_18_80075D3C(void *input) {
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
void func_level_18_8007728C(Moby* moby) {
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
void func_level_18_800773C8(Moby* moby) {
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
void func_level_18_80077484(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4)) func_80055B18(moby);
    moby->colour.r = tag[0] << 3;
    moby->colour.g = tag[0] << 2;
    moby->size -= deltaTime * 3;
    if (moby->size >= 0x80) moby->size = 0;
    if (moby->size < 0xE) moby->size = 0xE;
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
void func_level_18_80077538(Moby *moby) {
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
void func_level_18_8007783C(void *input) {
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
void func_level_18_800783B0(void *input) {
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
 * MobyUpdate_501() - func_level_18_80079504()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_18_80079504(Moby* moby) {
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
void func_level_18_80079524(Moby* argument) {
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

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 406 instructions per copy are the acceptance authority.
 * Preserve byte and signed-halfword accesses, original 0x78-byte frame,
 * table shifts, helper registers, bottom-tested actor loop and fallthroughs.
 * Empty constraints emit no instructions; separate aliases preserve original
 * table address lifetimes. Units, table meanings, complete helper contracts
 * and caller cadence remain unresolved. No runtime completeness claimed.
 * Falsifiable check: every original linked word and full binary hashes.
 */
#define Actor79724Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor79724func_80018368(void*,void*) __asm__("func_80018368");
void* Actor79724func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");
int Actor79724func_800359A4(void*,int) __asm__("func_800359A4");
int Actor79724func_800360F8(int,int,int,int) __asm__("func_800360F8");
int Actor79724func_8003BABC(void*,int,int) __asm__("func_8003BABC");
int Actor79724func_8003BE70(int) __asm__("func_8003BE70");
int Actor79724func_8003BFC0(void*,int) __asm__("func_8003BFC0");
int Actor79724func_8004E880(int,int,int) __asm__("func_8004E880");
int Actor79724func_8004F110(void*,int) __asm__("func_8004F110");
int Actor79724func_8004F178(void*,void*) __asm__("func_8004F178");
int Actor79724func_8004F194(void*,void*,void*) __asm__("func_8004F194");
int Actor79724func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Actor79724func_8004F334(void*,void*) __asm__("func_8004F334");
int Actor79724func_80055B18(void*) __asm__("func_80055B18");
int Actor79724rand(void) __asm__("rand");
extern short Actor79724D_80065920[] __asm__("D_80065920");
extern short Actor79724D_800658A0[] __asm__("D_800658A0");
extern short Actor79724Late65920[] __asm__("D_80065920");
extern short Actor79724Late658A0[] __asm__("D_800658A0");
extern short Actor79724Loop658A0[] __asm__("D_800658A0");
extern int Actor79724D_8006C574 __asm__("D_8006C574");
extern int Actor79724D_8006C578 __asm__("D_8006C578");
extern void* Actor79724D_8006E788[] __asm__("D_8006E788");
extern void* (*Actor79724SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Actor79724SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_18_80079724(void *input) {
    register unsigned char *owner __asm__("$19")=input;
    struct { int sp18,sp1C,sp20,pad24;
        int sp28,sp2C,sp30,pad34;
        int sp38,sp3C,sp40,pad44;
        int pad48,pad4C,pad50,pad54;
    } frame;
    register short *particleTable __asm__("$18");
    register int *ownerPosition __asm__("$16");
    register int *particlePosition __asm__("$20");
    int positionZ;
    int positionY;
    int positionX;
    register int randomByteOffset __asm__("$2");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    register void *call7 __asm__("$7");
    register short *raw3 __asm__("$3");
    register short *raw2 __asm__("$2");
    register int (*particle3)(int,int,void*,void*) __asm__("$3");
    register short *table18 __asm__("$18");
    register short *table20 __asm__("$20");
    register int *vector22 __asm__("$22");
    register int candidateScore __asm__("$3");
    register int angleDifference __asm__("$16");
    register int particleIndex __asm__("$16");
    register int particleSelector __asm__("$17");
    register int minimumScore __asm__("$22");
    register int spawnCount __asm__("$22");
    int var_v0;
    int var_v0_2;
    register int distanceDifference __asm__("$3");
    register int signedAngleDifference __asm__("$3");
    register int helperAngle __asm__("$16");
    register int currentAngle __asm__("$4");
    unsigned char stateByte;
    register int updatedAngle __asm__("$2");
    register void **candidateCursor __asm__("$18");
    register void **spawnCursor __asm__("$20");
    void *selectedActor;
    register void *spawnedState __asm__("$16");
    register void *spawnCandidate __asm__("$18");
    register void *state __asm__("$21");
    register void *hitActor __asm__("$17");
    register void *spawnedActor __asm__("$17");
    register void *candidateActor __asm__("$17");
    positionX = Actor79724Field(owner, int *, 0xC);
    state = Actor79724Field(owner, void **, 0);
    if ((positionX >= 0x400) && (positionY = Actor79724Field(owner, int *, 0x10), ((positionY < 0x400) == 0)) && (positionZ = Actor79724Field(owner, int *, 0x14), ((positionZ < 0x400) == 0)) && (positionX <= 0x3E800) && (positionY <= 0x3E800) && (positionZ <= 0x3E800) && (Actor79724Field(owner, unsigned char *, 0x4D) != 0)) {
        Actor79724func_8004F178(&frame.sp18, owner + 0xC);
        stateByte = Actor79724Field(owner, unsigned char *, 0x48);
        switch (stateByte) {                          /* irregular */
            case 0:
            minimumScore = 0x1869F;
            Actor79724Field(state, void **, 4) = 0;
            candidateActor = Actor79724D_8006E788[0];
            candidateCursor = Actor79724D_8006E788 + 1;
            if (candidateActor != 0) {
                do {
                    if (Actor79724Field(candidateActor, int *, 8) != 0) {
                        Actor79724func_8004F178(&frame.sp38, candidateActor + 0xC);
                        angleDifference = (Actor79724func_8004E880(frame.sp38 - Actor79724Field(owner, int *, 0xC), frame.sp3C - Actor79724Field(owner, int *, 0x10), 0) - Actor79724Field(owner, unsigned char *, 0x46)) & 0xFF;
                        if (angleDifference >= 0x81) {
                            angleDifference -= 0x100;
                        }
                        if (angleDifference < 0) {
                            angleDifference = -angleDifference;
                        }
                        __asm__("" : "=r"(angleDifference) : "0"(angleDifference));
                        if (angleDifference < 6) {
                            distanceDifference = 0x1000 - Actor79724func_8004F334(owner + 0xC, &frame.sp38);
                            if (distanceDifference < 0) {
                                distanceDifference = -distanceDifference;
                            }
                            __asm__("" : "=r"(distanceDifference) : "0"(distanceDifference));
                            work2=angleDifference<<5;
                            __asm__("" : "=r"(work2),"=r"(distanceDifference) : "0"(work2),"1"(distanceDifference));
                            candidateScore = distanceDifference + work2;
                            if (candidateScore < minimumScore) {
                                Actor79724Field(state, void **, 4) = candidateActor;
                                minimumScore = candidateScore;
                            }
                        }
                    }
                    candidateActor = *candidateCursor;
                    candidateCursor += 1;
                } while (candidateActor != 0);
            }
            Actor79724Field(owner, unsigned char *, 0x48) = 1U;
            /* fallthrough */
            case 1:
            if (Actor79724func_8003BFC0(owner, Actor79724Field(state, int *, 8)) == 0) {
                Actor79724Field(state, int *, 8) = Actor79724func_8003BABC(owner, 1, 4);
            }
            if (Actor79724Field(Actor79724Field(state, void **, 4), unsigned char *, 0x48) & 0x80) {
                Actor79724Field(state, void **, 4) = 0;
            }
            selectedActor = Actor79724Field(state, void **, 4);
            if (selectedActor != 0) {
                Actor79724func_8004F178(&frame.sp28, selectedActor + 0xC);
                frame.sp20 += 0x80;
                Actor79724func_8004F1C8(&frame.sp28, &frame.sp28, owner + 0xC);
                frame.sp30 += 0x100;
                Actor79724func_8004E880(frame.sp28, frame.sp2C, 0);
                work2=Actor79724func_8004E880(frame.sp28, frame.sp2C, 0);
                currentAngle=Actor79724Field(owner,unsigned char*,0x46);
                __asm__("" : "=r"(work2),"=r"(currentAngle) : "0"(work2),"1"(currentAngle));
                signedAngleDifference=(work2-currentAngle)&255;
                if(signedAngleDifference>=129)signedAngleDifference-=256;
                work2=signedAngleDifference < -3;
                if(work2){signedAngleDifference=-3;
                    __asm__("" : "=r"(signedAngleDifference) : "0"(signedAngleDifference));
                }
                work2=signedAngleDifference<4;
                if(work2){updatedAngle=currentAngle+signedAngleDifference;
                }else{signedAngleDifference=3;
                    __asm__("" : "=r"(signedAngleDifference) : "0"(signedAngleDifference));
                    updatedAngle=currentAngle+signedAngleDifference;
                }
                Actor79724Field(owner, unsigned char *, 0x46) = updatedAngle;
            }
            ownerPosition = owner + 0xC;
            work2=Actor79724Field(owner,unsigned char*,0x46);
            __asm__ __volatile__("" ::: "$4");
            call4=ownerPosition;
            __asm__("" : "=r"(work2),"=r"(call4) : "0"(work2),"1"(call4));
            work2=Actor79724D_80065920[work2];
            __asm__ __volatile__("" ::: "$5");
            call5=ownerPosition;
            __asm__("" : "=r"(work2),"=r"(call5) : "0"(work2),"1"(call5));
            frame.sp28=work2>>4;
            work2=Actor79724Field(owner,unsigned char*,0x46);
            __asm__ __volatile__("" ::: "$22");
            vector22=&frame.sp28;
            __asm__("" : "=r"(work2),"=r"(vector22) : "0"(work2),"1"(vector22));
            work2=Actor79724D_800658A0[work2];
            __asm__ __volatile__("" ::: "$6");
            call6=vector22;
            __asm__("" : "=r"(work2),"=r"(call6) : "0"(work2),"1"(call6));
            frame.sp30=0;
            __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "memory");
            frame.sp2C=work2>>4;
            Actor79724func_8004F194(call4,call5,call6);
            Actor79724Field(owner, unsigned char *, 0x44) = (unsigned char) (Actor79724Field(owner, unsigned char *, 0x44) + 4);
            work2=(int)Actor79724func_8001BA30(ownerPosition, 0x80, 1, 0, 0x110000, owner);
            __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "memory");
            table18=Actor79724Late65920;
            table20=Actor79724Late658A0;
            __asm__("" : "=r"(table18),"=r"(table20),"=r"(work2) : "0"(table18),"1"(table20),"2"(work2));
            hitActor=(void*)work2;
            if (hitActor != 0) {
                work2=Actor79724func_8004E880(Actor79724Field(hitActor,int*,12)-Actor79724Field(owner,int*,12),Actor79724Field(hitActor,int*,16)-Actor79724Field(owner,int*,16),0);
                call6=0;
                call4=(void*)frame.sp28;
                call5=(void*)frame.sp2C;
                __asm__("" : "=r"(work2),"=r"(call6),"=r"(call4),"=r"(call5) : "0"(work2),"1"(call6),"2"(call4),"3"(call5));
                helperAngle=work2;
                work2=Actor79724func_8004E880((int)call4,(int)call5,(int)call6);
                Actor79724Field(hitActor,signed char*,0x51)=Actor79724func_800360F8(helperAngle,work2,32,64);
                if (Actor79724Field(state, short *, 2) != 0) {
                    Actor79724Field(owner, unsigned char *, 0x48) = 2U;
                    return;
                }
                goto block_46;
            }
            if (Actor79724func_800359A4(state, 2) == 0) {
                if (Actor79724func_80018368(&frame.sp18, ownerPosition) != 0) {
                    Actor79724func_8004F178(ownerPosition, &frame.sp18);
                    block_46:
                    Actor79724Field(owner, unsigned char *, 0x48) = 3U;
                    return;
                }
                work2=Actor79724rand();
                call4=&frame.sp18;
                __asm__("" : "=r"(call4),"=r"(work2) : "0"(call4),"1"(work2));
                randomByteOffset=(work2&255)*2;
                raw3=(short*)(randomByteOffset+(int)table18);
                call5=call4;
                __asm__("" : "=r"(raw3),"=r"(call5),"=r"(call4),"=r"(table18) : "0"(raw3),"1"(call5),"2"(call4),"3"(table18));
                work3=*raw3;
                __asm__("" : "=r"(work3),"=r"(randomByteOffset),"=r"(table20) : "0"(work3),"1"(randomByteOffset),"2"(table20));
                raw2=(short*)(randomByteOffset+(int)table20);
                __asm__("" : "=r"(work3),"=r"(raw2) : "0"(work3),"1"(raw2));
                frame.sp18=work3>>7;
                work2=*raw2;
                __asm__ __volatile__("" ::: "$6");
                call6=vector22;
                __asm__("" : "=r"(work2),"=r"(call6) : "0"(work2),"1"(call6));
                __asm__ __volatile__("" ::: "$3", "memory");
                frame.sp20=0;
                __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "memory");
                frame.sp1C=work2>>7;
                Actor79724func_8004F194(call4,call5,call6);
                Actor79724func_8004F110(&frame.sp18, 2);
                Actor79724SpawnParticle(1, 0x37, ownerPosition, &frame.sp18);
                return;
            }
            goto block_62;
            case 2:
            spawnCursor = Actor79724D_8006E788;
            spawnCount = 0;
            goto nextActor;
            actorBody:
            if(spawnCount>=4)goto actorEnd;
            if ((Actor79724Field(spawnCandidate, int *, 8) != 0) && !(Actor79724Field(spawnCandidate, int *, 0x18) & 0x110000) && (Actor79724func_8004F334(owner + 0xC, spawnCandidate + 0xC) < 0x1000)) {
                spawnedActor = Actor79724SpawnMoby(Actor79724Field(owner, short *, 0x36), owner);
                call6=0;
                if (spawnedActor != 0) {
                    spawnCount++;
                    work3=Actor79724Field(spawnCandidate,int*,12);
                    call4=(void*)Actor79724Field(owner,int*,12);
                    work2=Actor79724Field(spawnCandidate,int*,16);
                    call5=(void*)Actor79724Field(owner,int*,16);
                    __asm__("" : "=r"(work3),"=r"(call4),"=r"(work2),"=r"(call5),"=r"(spawnedActor) : "0"(work3),"1"(call4),"2"(work2),"3"(call5),"4"(spawnedActor));
                    spawnedState=Actor79724Field(spawnedActor,void**,0);
                    __asm__("" : "=r"(spawnedState),"=r"(work3),"=r"(call4),"=r"(work2),"=r"(call5) : "0"(spawnedState),"1"(work3),"2"(call4),"3"(work2),"4"(call5));
                    call4=(void*)(work3-(int)call4);
                    call5=(void*)(work2-(int)call5);
                    Actor79724Field(spawnedActor,signed char*,0x46)=Actor79724func_8004E880((int)call4,(int)call5,(int)call6);
                    Actor79724Field(spawnedState, void **, 4) = spawnCandidate;
                }
            }
            nextActor:
            spawnCandidate=*spawnCursor;
            spawnCursor++;
            if(spawnCandidate!=0 && Actor79724D_8006C578-Actor79724D_8006C574>=21)goto actorBody;
            actorEnd:
            if (spawnCount == 0) {
                case 3:
                particleIndex = 0;
                particleSelector = Actor79724rand() & 0xFF;
                particlePosition = owner + 0xC;
                raw3=Actor79724D_80065920;
                __asm__("" : "=r"(raw3),"=r"(particleSelector) : "0"(raw3),"1"(particleSelector));
                work2=particleSelector<<1;
                particleTable=(short*)(work2+(int)raw3);
                do {
                    call4=(void*)1;
                    call5=(void*)55;
                    call6=particlePosition;
                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(particleTable) : "0"(call4),"1"(call5),"2"(call6),"3"(particleTable));
                    work2=*particleTable;
                    particle3=Actor79724SpawnParticle;
                    __asm__("" : "=r"(work2),"=r"(particle3) : "0"(work2),"1"(particle3));
                    work2>>=7;
                    __asm__("" : "=r"(work2) : "0"(work2));
                    frame.sp18=work2;
                    work2=particleSelector<<1;
                    __asm__("" : "=r"(work2) : "0"(work2));
                    work2=*(short*)((unsigned char*)Actor79724Loop658A0+work2);
                    __asm__ __volatile__("" ::: "$7");
                    call7=&frame.sp18;
                    __asm__("" : "=r"(work2),"=r"(call7) : "0"(work2),"1"(call7));
                    frame.sp20=0;
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "memory");
                    frame.sp1C=work2>>7;
                    particle3((int)call4,(int)call5,call6,call7);
                    if (particleIndex & 1) {
                        Actor79724func_8004F110(&frame.sp18, 1);
                        Actor79724SpawnParticle(1, 0x37, particlePosition, &frame.sp18);
                    }
                    particleTable += 0x20;
                    particleIndex += 1;
                    particleSelector += 0x20;
                } while (particleIndex < 8);
            }
            goto block_62;
        }
    } else {
        block_62:
        if (Actor79724func_8003BFC0(owner, Actor79724Field(state, int *, 8)) != 0) {
            if (Actor79724func_8003BFC0(owner, Actor79724Field(state, int *, 8)) != 0) {
                Actor79724func_8003BE70(Actor79724Field(state, int *, 8));
            }
            Actor79724Field(state, int *, 8) = -1;
        }
        Actor79724func_80055B18(owner);
    }
}
#undef Actor79724Field

/* Partial retail tag layout; meanings of the reserved words are unresolved. */
typedef struct {
    unsigned char reserved00[0x1C];
    int flags, reserved20, timer, reserved28, word2C;
} DecodedCritterAttachmentRecord;
extern short D_800658A0[];
void func_80055B18(Moby*);
void func_80055F14(Moby*, int, Vector3D*);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
void func_level_18_80079D7C(Moby* moby) {
    Moby* first;
    Moby* current;
    Moby** slot;
    DecodedCritterAttachmentRecord* tag;
    Vector3D* position;
    /* Preserve both original loads through the upstream aliases. */
    first = g_Spyro.critterMobyPtr;
    slot = &spyro.critterMobyPtr;
    current = *slot;
    tag = first->mobyTag;
    if (current) {
        if (!(tag->flags & 1) || tag->timer <= 0 || !moby->drawn) {
            func_80055B18(moby);
            tag->word2C = 0;
            return;
        }
        position = &moby->position;
        func_80055F14(current, 0, position);
        func_8001BA30(position, 0x400, 1, 0, 0x80000, *slot);
        if (tag->timer < 0xB4) {
            register int delta __asm__("$3") = tag->timer - 0xB4;
            register int shifted __asm__("$2");
            register int index __asm__("$3");
            register int byteOffset __asm__("$2");
            int wave, strength;
            /* Empty constraints preserve retail register allocation and shifts. */
            __asm__("" : "=r"(delta) : "0"(delta));
            shifted = delta * 8;
            __asm__("" : "=r"(shifted) : "0"(shifted));
            index = shifted & 0xFF;
            __asm__("" : "=r"(index) : "0"(index));
            byteOffset = index * 2;
            __asm__("" : "=r"(byteOffset) : "0"(byteOffset));
            wave = *(short*)((char*)D_800658A0 + byteOffset);
            if (wave < 0) wave = -wave;
            __asm__("" : "=r"(wave) : "0"(wave));
            strength = wave >> 8;
            if (strength >= 0x10) strength = 0xF;
            *(int*)&moby->colour = 0;
            moby->colour.a = strength | 0x30;
        }
    }
}

#define Controller79EA8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Controller79EA8D_800658A0 __asm__("D_800658A0");
extern short Controller79EA8D_80065920[] __asm__("D_80065920");
extern int Controller79EA8D_8006C574 __asm__("D_8006C574");
extern int Controller79EA8D_8006C578 __asm__("D_8006C578");
extern void* Controller79EA8D_8006E788 __asm__("D_8006E788");
int Controller79EA8Helper1830C(void*,void*,int,int,void*) __asm__("func_8001830C");
int Controller79EA8Helper18368(void*,void*) __asm__("func_80018368");
void* Controller79EA8Helper1BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");
int Controller79EA8Helper359A4(void*,int) __asm__("func_800359A4");
int Controller79EA8Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller79EA8Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller79EA8Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Controller79EA8Helper4F110(void*,int) __asm__("func_8004F110");
int Controller79EA8Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller79EA8Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller79EA8Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Controller79EA8Helper4F264(int,int) __asm__("func_8004F264");
int Controller79EA8Helper4F334(void*,void*) __asm__("func_8004F334");
int Controller79EA8Helper509E8(void*) __asm__("func_800509E8");
int Controller79EA8Helper55B18(void*) __asm__("func_80055B18");
int Controller79EA8Helper55D24(void*,int) __asm__("func_80055D24");
extern void* (*Controller79EA8SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Controller79EA8SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level18/80079EA8, level28/80079E60, level38/80079E64 and
 * level48/80079E88; each has 365 equal original instructions and exact
 * helper/global symbols, without owned table rows. Local vectors retain
 * offsets 0x18/0x28/0x38/0x48/0x58/0x68 and target pointers stride 4.
 * Preserve target-score early exit, signed heading differences/clamps,
 * duplicate angle helper calls, original trace masks and pointer rereads,
 * eight particle iterations and signed table shifts by 7.
 * Helper semantics, coordinate units and caller cadence remain unresolved;
 * updates occur once per invocation. Confidence: exact compiled/linked
 * original words and complete retail hashes, not semantic runtime review.
 * Falsifiable vectors: all 1,460 original words and EXE/all-overlay SHA set.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_18_80079EA8(void *input) {
    struct { Vector3D a; int pad24; Vector3D b; int pad34; Vector3D c; int pad44; Vector3D d; int pad54; Vector3D e; int pad64; Vector3D f; int pad74; } frame;
    register unsigned char *owner __asm__("$19")=input;
    register short *cosineEntry __asm__("$18");
    register int *currentPosition __asm__("$17");
    register int *probePosition __asm__("$17");
    register int *updatedPosition __asm__("$18");
    register int targetScore __asm__("$3");
    register int absoluteTurn __asm__("$16");
    register int particleIndex __asm__("$16");
    register int stepValue __asm__("$17");
    register int particleAngle __asm__("$17");
    register int bestScore __asm__("$20");
    register int absoluteDelta __asm__("$2");
    register int distanceDelta __asm__("$3");
    register int turnDelta __asm__("$3");
    register int previousHeading __asm__("$4");
    unsigned char state;
    register int nextHeading __asm__("$2");
    register void **targetCursor __asm__("$18");
    void *cleanupHandle;
    void *finalHandle;
    void *selectedTarget;
    register void *candidateTarget __asm__("$17");
    register void *particlePosition __asm__("$21");
    register void *particleVector __asm__("$20");
    register void *tag __asm__("$22");
    register void *firstHit __asm__("$17");
    register void *secondHit __asm__("$16");
    register void *spawnedChild __asm__("$16");

    tag = Controller79EA8Field(owner, void **, 0);
    if (Controller79EA8Field(owner, unsigned char *, 0x4D) == 0) {
        cleanupHandle = Controller79EA8Field(tag, void **, 8);
        if (cleanupHandle != 0) {
            Controller79EA8Helper509E8(cleanupHandle);
        }
        goto removeOwner;
    }
    state = Controller79EA8Field(owner, unsigned char *, 0x48);
    switch (state) {                              /* irregular */
    case 0:
        bestScore = 0x1869F;
        targetCursor = &Controller79EA8D_8006E788;
        Controller79EA8Field(tag, void **, 4) = 0;
        goto nextTarget;
evaluateTarget:
        {
            if (Controller79EA8Field(candidateTarget, int *, 8) != 0) {
                Controller79EA8Helper4F178(&frame.a.x, candidateTarget + 0xC);
                absoluteTurn = (Controller79EA8Helper4E880(frame.a.x - Controller79EA8Field(owner, int *, 0xC), frame.a.y - Controller79EA8Field(owner, int *, 0x10), 0) - Controller79EA8Field(owner, unsigned char *, 0x46)) & 0xFF;
                if (absoluteTurn >= 0x81) {
                    absoluteTurn -= 0x100;
                }
                if (absoluteTurn < 0) {
                    absoluteTurn = -absoluteTurn;
                }
                __asm__ volatile("" : : : "$4");
                distanceDelta = 0x1000 - Controller79EA8Helper4F334(owner + 0xC, &frame.a.x);
                if (distanceDelta < 0) {
                    distanceDelta = -distanceDelta;
                }
                __asm__("" : "=r"(distanceDelta) : "0"(distanceDelta) : "$2");
                { register int shifted __asm__("$2")=absoluteTurn<<8;
                  __asm__("" : "=r"(shifted) : "0"(shifted));
                  targetScore=distanceDelta+shifted; }
                if (targetScore < bestScore) {
                    Controller79EA8Field(tag, void **, 4) = candidateTarget;
                    if (targetScore < 0x801) goto targetSelected;
                    {
                        bestScore = targetScore;
                        goto nextTarget;
                    }
                } else {
                    goto nextTarget;
                }
            } else {
                goto nextTarget;
            }
        }
nextTarget:
        candidateTarget=*targetCursor;
        targetCursor+=1;
        if(candidateTarget!=0) goto evaluateTarget;
targetSelected:
        __asm__("" : "=r"(candidateTarget) : "0"(candidateTarget));
        if (bestScore == 0x1869F) {
            Controller79EA8Field(tag, void **, 4) = 0;
        }
        Controller79EA8Field(owner, unsigned char *, 0x48) = 1U;
        /* fallthrough */
    case 1:
        if ((Controller79EA8Field(owner, int *, 0xC) < 0x400) || (Controller79EA8Field(owner, int *, 0x10) < 0x400) || (Controller79EA8Field(owner, int *, 0x14) < 0x400) || (Controller79EA8Helper359A4(tag, 4) != 0)) {
            Controller79EA8Field(owner, unsigned char *, 0x48) = 2U;
            return;
        }
        { register void *prepared __asm__("$4")=&frame.b.x;
          __asm__("" : "=r"(prepared) : "0"(prepared));
          currentPosition=owner+0xC;
          Controller79EA8Helper4F178(prepared,currentPosition); }
        if (Controller79EA8Field(Controller79EA8Field(tag, void **, 4), unsigned char *, 0x48) & 0x80) {
            Controller79EA8Field(tag, void **, 4) = 0;
        }
        selectedTarget = Controller79EA8Field(tag, void **, 4);
        if (selectedTarget != 0) {
            Controller79EA8Helper4F178(&frame.d.x, selectedTarget + 0xC);
            frame.d.z += 0x80;
            Controller79EA8Helper4F1C8(&frame.c.x, &frame.d.x, currentPosition);
            frame.c.z += 0x100;
            Controller79EA8Helper4E880(frame.c.x, frame.c.y, 0);
            { register int angle __asm__("$2")=Controller79EA8Helper4E880(frame.c.x,frame.c.y,0);
              previousHeading=Controller79EA8Field(owner,unsigned char*,0x46);
              turnDelta=(angle-previousHeading)&255; }
            if (turnDelta >= 0x81) {
                turnDelta -= 0x100;
            }
            absoluteDelta = turnDelta;
            if (turnDelta < 0) {
                absoluteDelta = -absoluteDelta;
            }
            stepValue = 0x80;
            if (absoluteDelta < 0x30) {
                stepValue = 0xFA;
            }
            if(turnDelta < -4) {
                turnDelta=-4;
                __asm__("" : "=r"(turnDelta) : "0"(turnDelta));
            }
            if(turnDelta>=5) {
                turnDelta=4;
                __asm__("" : "=r"(turnDelta) : "0"(turnDelta));
            }
            nextHeading=previousHeading+turnDelta;
            Controller79EA8Field(owner, unsigned char *, 0x46) = nextHeading;
        } else {
            stepValue = 0xFA;
            Controller79EA8Field(owner, unsigned char *, 0x48) = 0U;
        }
        Controller79EA8Helper55D24(owner, 4);
        frame.c.x = stepValue;
        frame.c.y = 0;
        frame.c.z = 0;
        Controller79EA8Helper4ED6C(owner + 0x20, &frame.c.x, &frame.c.x);
        updatedPosition = owner + 0xC;
        Controller79EA8Helper4F194(updatedPosition, updatedPosition, &frame.c.x);
        if (Controller79EA8Helper1830C(&frame.b.x, updatedPosition, 0, 0x110000, owner) != 0) {
            Controller79EA8Helper4F178(updatedPosition, &frame.b.x);
            goto enterStateTwo;
        }
        firstHit = Controller79EA8Helper1BA30(updatedPosition, 0x200, 1, 0, 0, owner);
        if (firstHit != 0) {
            Controller79EA8Helper4F178(&frame.e.x, firstHit + 0xC);
            frame.e.z += 0x80;
            if (Controller79EA8Helper18368(updatedPosition, &frame.e.x) == 0) {
                Controller79EA8Field(firstHit, int *, 0x18) = (int) (Controller79EA8Field(firstHit, int *, 0x18) | 0x110000);
enterStateTwo:
                Controller79EA8Field(owner, unsigned char *, 0x48) = 2U;
            }
        }
        if (Controller79EA8Field(tag, void **, 8) != 0) {
            if ((Controller79EA8Helper4F264(Controller79EA8Field(owner, unsigned char *, 0x46), 0) < 0x20) || (Controller79EA8Helper4F264(Controller79EA8Field(owner, unsigned char *, 0x46), 0x80) < 0x20)) {
                Controller79EA8Field(Controller79EA8Field(tag, void **, 8), unsigned char *, 0x66) = 0xF4;
                return;
            }
            Controller79EA8Field(Controller79EA8Field(tag, void **, 8), signed char *, 0x66) = 7;
            return;
        }
        return;
    case 2:
        particleIndex = 0;
        particleAngle = rand() & 0xFF;
        particlePosition = owner + 0xC;
        particleVector=&frame.f.x;
        __asm__("" : "=r"(particleVector) : "0"(particleVector));
        __asm__("" : "=r"(particleVector),"=r"(particlePosition) : "0"(particleVector),"1"(particlePosition));
        { register short *base __asm__("$3")=Controller79EA8D_80065920;
          register int offset __asm__("$2");
          __asm__("" : "=r"(base) : "0"(base));
          offset=particleAngle*2;
          cosineEntry=(short*)(offset+(int)base); }
        do {
            register int type __asm__("$4")=1;
            register int selector __asm__("$5")=0x37;
            register void *position __asm__("$6")=particlePosition;
            register int sample __asm__("$2");
            register void *vectorArgument __asm__("$7");
            register int (*emit)(int,int,void*,void*) __asm__("$3");
            __asm__("" : "=r"(type),"=r"(selector),"=r"(position) : "0"(type),"1"(selector),"2"(position));
            sample=*cosineEntry;
            emit=Controller79EA8SpawnParticle;
            __asm__("" : "=r"(sample),"=r"(emit) : "0"(sample),"1"(emit));
            frame.f.x=sample>>7;
            __asm__ volatile("" : : : "memory");
            { register int offset __asm__("$2")=particleAngle*2;
              __asm__("" : "=r"(offset) : "0"(offset));
              sample=*(short*)((unsigned char*)&Controller79EA8D_800658A0+offset); }
            __asm__("" : "=r"(sample) : "0"(sample) : "$7");
            vectorArgument=particleVector;
            __asm__("" : "=r"(vectorArgument) : "0"(vectorArgument));
            frame.f.z=0;
            __asm__ volatile("" : "=r"(sample) : "0"(sample) : "memory");
            frame.f.y=sample>>7;
            emit(type,selector,position,vectorArgument);
            if (particleIndex & 1) {
                Controller79EA8Helper4F110(particleVector, 1);
                Controller79EA8SpawnParticle(1, 0x37, particlePosition, particleVector);
            }
            cosineEntry += 0x20;
            particleIndex += 1;
            particleAngle += 0x20;
        } while (particleIndex < 8);
        probePosition = owner + 0xC;
        secondHit = Controller79EA8Helper1BA30(probePosition, 0x400, 1, 0, 0, owner);
        if ((secondHit != 0) && (Controller79EA8Helper18368(probePosition, secondHit + 0xC) == 0)) {
            Controller79EA8Field(secondHit, int *, 0x18) = (int) (Controller79EA8Field(secondHit, int *, 0x18) | 0x110000);
        }
        if ((Controller79EA8D_8006C578 - Controller79EA8D_8006C574) >= 0x15) {
            spawnedChild = Controller79EA8SpawnMoby(0x146, owner);
            if (spawnedChild != 0) {
                Controller79EA8Field(spawnedChild, signed char *, 0x47) = 8;
                Controller79EA8Field(spawnedChild, signed char *, 0x4C) = 0x3F;
                Controller79EA8Field(spawnedChild, signed char *, 0x4E) = 0x3F;
            }
        }
        finalHandle = Controller79EA8Field(tag, void **, 8);
        if (finalHandle != 0) {
            Controller79EA8Helper509E8(finalHandle);
        }
        Controller79EA8Helper3BABC(owner, 1, 0);
removeOwner:
        Controller79EA8Helper55B18(owner);
        break;
    }
}

#undef Controller79EA8Field


/* Retail private layouts pin byte+5, index+0x30, flags+0x1C and handle+0x36. */
typedef struct {
    unsigned char reserved00[5];
    unsigned char ready;
    unsigned char reserved06[0x2A];
    int actorIndex;
} DecodedIndexedStateTag;
typedef struct {
    unsigned char reserved00[0x1C];
    int flags;
    unsigned char reserved20[0x16];
    short handle;
} DecodedIndexedStatePrivate;
extern unsigned char DecodedIndexedStateGate __asm__("D_80071599");
extern int DecodedIndexedStateMode __asm__("D_8006E344");
extern Moby* DecodedIndexedStatePool __asm__("D_8006C550");
extern Moby* DecodedIndexedStatePlayerLink __asm__("D_80070328 + 0x250");
extern Vector3D DecodedIndexedStatePlayer __asm__("D_80070328");
extern unsigned char DecodedIndexedStateHeading __asm__("D_80070328 + 0xE");
int DecodedIndexedStateQuery(Moby*,int) __asm__("func_80037BBC");
void DecodedIndexedStateSetup(Moby*,int,int) __asm__("func_800512E4");
void DecodedIndexedStateCamera(Vector3D*,int,int,int) __asm__("func_80013D44");
void DecodedIndexedStateRelease(Moby*) __asm__("func_80055B18");
void func_level_18_8007A45C(Moby* moby) {
    DecodedIndexedStateTag* tag = moby->mobyTag;
    Moby* target;
    DecodedIndexedStatePrivate* linkedPrivate;
    register int actorIndex __asm__("$3");
    int state = moby->state;
    register int ready __asm__("$17");
    register int cameraMode __asm__("$6");
    register int enabled __asm__("$2");
    switch (state) {
    case 0:
        /* Preserve the separate state-0 one constant across both helper calls. */
        __asm__ volatile ("" : : : "$17");
        if (DecodedIndexedStateGate) break;
        ready = 1;
        tag->ready = ready;
        if (!DecodedIndexedStateQuery(moby,9)) break;
        DecodedIndexedStateSetup(moby,0,0);
        __asm__ volatile ("" : : "r"(ready));
        moby->state = ready;
        break;
    case 1:
        if (DecodedIndexedStateMode==state) break;
        if (tag->actorIndex!=-1) {
            enabled = 1;
            __asm__ volatile ("" : : "r"(enabled));
            cameraMode = 0;
            /* The indexed actor selector is reread after this gate-byte store. */
            DecodedIndexedStateGate = enabled;
            __asm__ volatile ("" : : "r"(cameraMode) : "memory");
            actorIndex = tag->actorIndex;
            target = &DecodedIndexedStatePool[actorIndex];
            DecodedIndexedStateCamera(&target->position,target->angle.yaw,cameraMode,152);
        }
        moby->state = 2;
        break;
    case 2:
        if (tag->actorIndex!=-1) {
            linkedPrivate = DecodedIndexedStatePlayerLink->mobyTag;
            linkedPrivate->flags&=~30;
            if (linkedPrivate->handle!=-1) func_80028154(linkedPrivate->handle);
        } else {
            func_8003B634(&savedData,&DecodedIndexedStatePlayer,DecodedIndexedStateHeading);
        }
        DecodedIndexedStateRelease(moby);
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_18/moby", D_level_18_800745A4);

typedef struct { int type, retain, hudIndex; } DecodedCollectibleHudTag;
typedef struct { int value[4]; } DecodedCollectibleHudIds;
extern DecodedCollectibleHudIds DecodedCollectibleHudData __asm__("D_level_18_800745A4");
extern unsigned char DecodedCollectibleHudPlayer[] __asm__("D_80070328");
extern unsigned char D_8006C7F8[];
void DecodedCollectibleHudSave(void*,int,void*) __asm__("func_8003B7B4");
void DecodedCollectibleHudSound(Moby*,int,int) __asm__("func_8003BABC");
void DecodedCollectibleHudUpdate(void*) __asm__("func_80027D60");
void DecodedCollectibleHudDraw(void*) __asm__("func_8002982C");
short DecodedCollectibleHudCreate(int,int,void(*)(void*),int,void(*)(void*),int,int) __asm__("func_8002803C");
void DecodedCollectibleHudDelete(int) __asm__("func_80028154");
void func_level_18_8007A5E8(Moby* moby) {
    DecodedCollectibleHudTag* tag = moby->mobyTag;
    DecodedCollectibleHudIds ids = DecodedCollectibleHudData;
    int distance;
    Moby* spawned;
    moby->size = 40;
    distance = func_8004F334(&moby->position,DecodedCollectibleHudPlayer);
    switch (moby->state) {
    case 0:
        switch (tag->type) {
        case 0: moby->colour.r = 0xCF; moby->colour.g = 0x20; moby->colour.b = 0x20; break;
        case 1: moby->colour.r = 0x20; moby->colour.g = 0xCF; moby->colour.b = 0x20; break;
        case 2: moby->colour.r = 0x20; moby->colour.g = 0x20; moby->colour.b = 0xCF; break;
        default: tag->type = 3; moby->colour.r = 0xFF; moby->colour.g = 0xB0; moby->colour.b = 0x20; break;
        }
        DecodedCollectibleHudSave(tag,4,D_8006C7F8);
        moby->colour.a = 0x3F;
        moby->angle.roll = 0x40;
        moby->angle.pitch = 0x20;
        moby->state = 1;
        /* Retail initialization continues into the state 1 yaw update. */
    case 1:
        moby->angle.yaw += 8;
        if (distance < 900) {
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            moby->state = 2;
            DecodedCollectibleHudSave(&moby->state,1,D_8006C7F8);
            DecodedCollectibleHudSound(moby,0,0);
            if (!tag->retain) {
                spawned = SpawnMoby(0x110,moby);
                if (spawned) {
                    spawned->angle.yaw = 0;
                    spawned->size = 16;
                    ((unsigned char*)spawned->mobyTag)[4] = 0;
                }
            }
        }
        break;
    case 2:
        if (tag->hudIndex == -1) tag->hudIndex = DecodedCollectibleHudCreate(0x15,ids.value[tag->type],DecodedCollectibleHudUpdate,0,DecodedCollectibleHudDraw,0,0);
        moby->unknown3[0] = 0;
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
        func_8004F178(&moby->position,DecodedCollectibleHudPlayer);
        break;
    case 3:
        if (tag->hudIndex != -1) {
            DecodedCollectibleHudDelete(tag->hudIndex);
            tag->hudIndex = -1;
        }
        func_80055B18(moby);
        break;
    case 4:
        moby->angle.pitch = 0;
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 8007A890.
* Assembly SHA256 7a4b3068d2790cc0c2d21b2fb0ecd9c8ba84669c36fe0768ed23ff29654be4ce.
* AI generated; not human reviewed. All original instructions (1031) and
* actual branch/call/internal targets are required. Frame F0 retains every
* S0/S1/S2/S3/S4/RA save/restore and original SP20..CF local extent.
* Original packed data at 800745CC  is exactly 12 bytes:
* 20 00 00 00 00 00 00 00 E0 FF FF FF; it is not a jump table.
* The physical dispatch order is 4/8/16/2. Each successful 4/8/16 arm
* retains its original countdown read and jump to the shared decrement.
* Independent named data views resolve to the exact original addresses;
* the final palette channel uses the original signed halfword at +2.
* Empty initialized constraints and dead-before-producer clobbers emit no
* CPU instructions. They retain original ownership, scheduling and joins.
* Raw units/fixed point, full helper contracts and caller cadence remain
* unresolved. Cadence here is per invocation. Binary identity does not
* establish synchronized retail runtime or complete game behavior.
* Falsification: every native/linked word and actual target, complete data
* bytes, full EXE and every overlay retail hash must remain identical. */
#define Actor18Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
unsigned char Actor18Call135A4View1() __asm__("func_800135A4");
int Actor18Call18368View1() __asm__("func_80018368");
int Actor18Call2803CView1() __asm__("func_8002803C");
short Actor18Call2803CView2() __asm__("func_8002803C");
unsigned char Actor18Call28154View1() __asm__("func_80028154");
unsigned char Actor18Call35734View1() __asm__("func_80035734");
unsigned char Actor18Call3585CView1() __asm__("func_8003585C");
int Actor18Call359A4View1() __asm__("func_800359A4");
int Actor18Call3617CView1() __asm__("func_8003617C");
int Actor18Call3BABCView1() __asm__("func_8003BABC");
unsigned char Actor18Call3BE70View1() __asm__("func_8003BE70");
int Actor18Call3BFC0View1() __asm__("func_8003BFC0");
int Actor18Call4F264View1() __asm__("func_8004F264");
void * Actor18Call50844View1() __asm__("func_80050844");
unsigned char Actor18Call509E8View1() __asm__("func_800509E8");
unsigned char Actor18Call55B18View1() __asm__("func_80055B18");
unsigned char Actor18Call55D24View1() __asm__("func_80055D24");
int Actor18Call55E84View1() __asm__("func_80055E84");
unsigned char Actor18Call55F14View1() __asm__("func_80055F14");
extern int Actor18Data6580CView1 __asm__("D_8006580C");
extern unsigned char Actor18Data6585CView1 __asm__("D_8006585C");
extern unsigned char Actor18Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor18Data65920View1 __asm__("D_80065920");
extern unsigned char Actor18Data68F7CView1 __asm__("D_80068F7C");
extern unsigned char Actor18Data68F90View1 __asm__("D_80068F90");
extern unsigned int Actor18Data6C550View1 __asm__("D_8006C550");
extern int Actor18Data6C58CView1 __asm__("D_8006C58C");
extern int Actor18Data6C640View1 __asm__("D_8006C640");
extern int Actor18Data6C6D0View1 __asm__("D_8006C6D0");
extern unsigned int Actor18Data6C704View1 __asm__("D_8006C704");
extern int Actor18Data6C770View1 __asm__("D_8006C770");
extern int Actor18Data6E344View1 __asm__("D_8006E344");
extern int Actor18Data6E538View1 __asm__("D_8006E538");
extern unsigned char Actor18Data70328View1 __asm__("D_80070328");
extern unsigned char Actor18Data716ACView1 __asm__("D_800716AC");
extern unsigned char Actor18Data719A8View1 __asm__("D_800719A8");
extern unsigned char Actor18Data719F0View1 __asm__("D_800719F0");
extern unsigned char Actor18Data745D8View1 __asm__("D_level_18_800745D8");
extern int Actor18Data74364View1 __asm__("unk_ovlheader_80074364");
extern int Actor18Data74368View1 __asm__("unk_ovlheader_80074368");
extern int Actor18Data7436CView1 __asm__("unk_ovlheader_8007436C");
extern void *(*Actor18DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Actor18DataSpawnParticleView1)() __asm__("SpawnParticle");
extern int(*Actor18Data74318View1)() __asm__("unk_ovlheader_80074318");
const unsigned char Actor18Data745CCView1[12] __asm__("D_level_18_800745CC") __attribute__((aligned(4))) = {
    32, 0, 0, 0, 0, 0, 0, 0, 224, 255, 255, 255
}
;
extern unsigned char Actor18Data745CCView2 __asm__("D_level_18_800745CC");
extern int Actor18Data70328View2 __asm__("D_80070328 + 640 + 0 - 0");
extern int Actor18Data70328View3 __asm__("D_80070328 + 640 + 1 - 1");
extern int Actor18Data70328View4 __asm__("D_80070328 + 640 + 2 - 2");
extern int Actor18Data70328View5 __asm__("D_80070328 + 640 + 3 - 3");
extern int Actor18Data70328View6 __asm__("D_80070328 + 640 + 4 - 4");
extern int Actor18Data70328View7 __asm__("D_80070328 + 640 + 5 - 5");
extern unsigned char Actor18Data6585CView2 __asm__("D_8006585C + 0 + 6 - 6");
extern unsigned char Actor18Data6585CView3 __asm__("D_8006585C + 0 + 7 - 7");
extern unsigned char Actor18Data6585CView4 __asm__("D_8006585C + 0 + 8 - 8");
extern unsigned char Actor18Data6585CView5 __asm__("D_8006585C + 0 + 9 - 9");
extern unsigned char Actor18Data6585CView6 __asm__("D_8006585C + 2 + 10 - 10");
int Actor18Call34F40View1(void*, int) __asm__("func_80034F40");
void func_level_18_8007A890(void *input) {
    register int scanCount17 __asm__("$17");
    register int scanOne21 __asm__("$21");
    register void *scanPrivate6 __asm__("$6");
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register unsigned int addressWord4 __asm__("$4");
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register void *memoryCursor3 __asm__("$3");
    register unsigned char *copyEnd8 __asm__("$8");
    register void *spawnedRecord18 __asm__("$18");
    register void *ownerRecord20 __asm__("$20");
    struct {
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4, spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4, spC8, spCC;
    }
    originalFrame;
    register unsigned char *temporaryWord9 __asm__("$5");
    register unsigned char *temporaryWord10 __asm__("$5");
    register unsigned char *temporaryWord16 __asm__("$6");
    register unsigned char *temporaryWord17 __asm__("$7");
    int temporaryWord3;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord11;
    int temporaryWord15;
    register int firstSpawnIndex16 __asm__("$16");
    register int secondSpawnIndex16 __asm__("$16");
    int temporaryWord13;
    int temporaryWord12;
    void *temporaryPointer4;
    void *temporaryPointer5;
    register void *playerModePointer16 __asm__("$16");
    register void *privateRecord19 __asm__("$19");
    void *temporaryPointer14;
    spawnedRecord18 = (void*)Actor18Data6C550View1;
    __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
    rawWord2 = Actor18Data6C704View1;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    ownerRecord20 = input;
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20):"$17");
    privateRecord19 = Actor18Field(ownerRecord20, void**, 0);
    __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(privateRecord19));
    rawWord2 = (unsigned int)spawnedRecord18 < (unsigned int)rawWord2;
    scanCount17 = 0;
    if (!rawWord2) goto scanned18;
    scanOne21 = 1;
    playerModePointer16 = spawnedRecord18+72;
scanLoop18:
    rawWord3 = 374;
    rawWord2 = Actor18Field(playerModePointer16, short*, -18);
    scanPrivate6 = Actor18Field(spawnedRecord18, void**, 0);
    if (rawWord2 != rawWord3) goto nextScan18;
    rawWord2 = Actor18Field(ownerRecord20, unsigned char*, 72)&128;
    if (rawWord2) goto nextScan18;
    argumentWord4 = Actor18Field(ownerRecord20, int*, 12);
    rawWord2 = Actor18Field(playerModePointer16, int*, -60);
    rawWord3 = argumentWord4-rawWord2;
    if (rawWord3 < 0)rawWord3 = rawWord2-argumentWord4;
    argumentWord5 = Actor18Field(ownerRecord20, int*, 16);
    argumentWord4 = Actor18Field(playerModePointer16, int*, -56);
    rawWord2 = argumentWord5-argumentWord4;
    if (rawWord2 < 0)rawWord2 = argumentWord4-argumentWord5;
    argumentWord4 = rawWord3+rawWord2;
    rawWord2 = Actor18Field(scanPrivate6, short*, 26);
    if (rawWord2 < argumentWord4) goto nextScan18;
    rawWord3 = (((30-scanCount17) << 13)/30)+4096;
    if (rawWord3 < argumentWord4){
        if (scanCount17 >= 5){
            rawWord2 = Actor18Field(playerModePointer16, unsigned char*, 0);
            if (rawWord2 == scanOne21){
                __asm__("":"=r"(scanOne21):"0"(scanOne21));
                __asm__ __volatile__(""::"i"(0x8007A9A4):"memory");
                Actor18Field(scanPrivate6, int*, 28) = scanOne21;
                goto counted18;
            }
        }
    }
    rawWord2 = argumentWord4 < rawWord3;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    if (rawWord2 || scanCount17 < 5){
        rawWord2 = Actor18Field(scanPrivate6, unsigned short*, 24)&512;
        if (rawWord2) goto nextScan18;
        __asm__ __volatile__("":::"$2", "memory");
        Actor18Field(scanPrivate6, int*, 28) = 0;
        rawWord2 = Actor18Field(playerModePointer16, unsigned char*, 0);
        if (!rawWord2){
            Actor18Call34F40View1(spawnedRecord18, 1);
            Actor18Field(playerModePointer16, unsigned char*, 0) = scanOne21;
        }
    counted18:
        __asm__ __volatile__(""::"r"(scanCount17), "i"(0x8007A9F4):"memory");
        scanCount17 += 1;
    }
nextScan18:
    rawWord2 = Actor18Data6C704View1;
    spawnedRecord18 += 88;
    rawWord2 = (unsigned int)spawnedRecord18 < (unsigned int)rawWord2;
    playerModePointer16 += 88;
    if (rawWord2) goto scanLoop18;
scanned18:
    rawWord2 = Actor18Field(privateRecord19, short*, 4);
    if (rawWord2) goto initialized28;
    {
        rawWord2 = 1;
        addressWord4 = Actor18Data6C550View1;
        rawWord3 = Actor18Data6C704View1;
        Actor18Field(privateRecord19, short*, 4) = rawWord2;
        rawWord3 = addressWord4 < (unsigned int)rawWord3;
        Actor18Field(privateRecord19, short*, 0x32) = 0;
        if (!rawWord3) goto listDone28;
        argumentWord6 = 1;
        argumentWord5 = 381;
        memoryCursor3 = (void*)(addressWord4+71);
        __asm__("":"=r"(memoryCursor3):"0"(memoryCursor3));
        do{
            rawWord2 = Actor18Field(memoryCursor3, short*, -17);
            if (rawWord2 == argumentWord6){
                Actor18Field(memoryCursor3, short*, -17) = argumentWord5;
                Actor18Field(memoryCursor3, unsigned char*, 0) = 0;
            }
            rawWord2 = Actor18Data6C704View1;
            addressWord4 += 88;
            rawWord2 = addressWord4 < (unsigned int)rawWord2;
            memoryCursor3 += 88;
        }
        while (rawWord2);
    listDone28:
        temporaryWord11 = Actor18Field(&Actor18Data70328View1, int *, 0x280) * 2;
        Actor18Field(privateRecord19, int *, 0x28) = temporaryWord11;
        if (temporaryWord11 >= 7) {
            Actor18Field(privateRecord19, int *, 0x28) = 6;
        }
        if (Actor18Field(privateRecord19, int *, 0x28) <= 0) {
            Actor18Field(privateRecord19, int *, 0x28) = 1;
        }
        rawWord2 = Actor18Call2803CView1(0x17, 0xB4, Actor18Data74368View1, Actor18Data7436CView1, Actor18Data74364View1, privateRecord19+0x28, 6);
        rawWord2 <<= 16;
        rawWord3 = Actor18Data6C58CView1;
        rawWord2 >>= 16;
        Actor18Field(privateRecord19, int*, 0x40) = rawWord2;
        temporaryWord1 = rawWord3*6;
        temporaryWord12 = *(&Actor18Data716ACView1 + temporaryWord1);
        if (temporaryWord12 < 0xFFU) {
            *(&Actor18Data716ACView1 + temporaryWord1) = temporaryWord12 + 1;
        }
    }
initialized28:
    if (Actor18Data6E344View1 == 1) {
        temporaryWord2 = Actor18Field(privateRecord19, int *, 0x40);
        if (temporaryWord2 != -1) {
            Actor18Call28154View1(temporaryWord2);
            Actor18Field(privateRecord19, int *, 0x40) = -1;
        }
    }
    else if (Actor18Field(privateRecord19, int *, 0x40) == -1) {
        Actor18Field(privateRecord19, int *, 0x40) = (int) Actor18Call2803CView2(0x17, 0xB4, Actor18Data74368View1, Actor18Data7436CView1, Actor18Data74364View1, privateRecord19 + 0x28, 6);
    }
    Actor18Data74318View1(ownerRecord20, 0x98);
    if ((Actor18Field(privateRecord19, int *, 0x1C) & 0x21) == 0x20) {
        if ((Actor18Data6C640View1 % 15) < 0xC) {
            Actor18Field(ownerRecord20, signed char *, 0x4C) = 0;
            Actor18Field(ownerRecord20, signed char *, 0x4D) = 0;
        }
        else {
            Actor18Field(ownerRecord20, signed char *, 0x4C) = 0x20;
            Actor18Field(ownerRecord20, signed char *, 0x4D) = 1;
        }
    }
    Actor18Data6C6D0View1 = 0;
    Actor18Call135A4View1(&Actor18Data719A8View1, &Actor18Data68F7CView1, 0);
    Actor18Call135A4View1(&Actor18Data719F0View1, &Actor18Data68F90View1, 0);
    rawWord2 = Actor18Field(privateRecord19, int*, 0x28);
    if (rawWord2 > 0) goto positiveCount28;
    Actor18Field(&Actor18Data70328View1, int*, 0x280) = 0;
    Actor18Field(&Actor18Data70328View1, int*, 0x24) |= 1;
    return;
positiveCount28:
    rawWord2 += 1;
    addressWord4 = (unsigned int)(&Actor18Data70328View1+0x280);
    __asm__("":"=r"(addressWord4):"0"(addressWord4));
    rawWord3 = (unsigned int)rawWord2 >> 31;
    rawWord2 += rawWord3;
    rawWord3 = Actor18Data6580CView1;
    rawWord2 >>= 1;
    Actor18Field(addressWord4, int*, 0) = rawWord2;
    if (rawWord3 < rawWord2)Actor18Field(addressWord4, int*, 0) = rawWord3;
    if (Actor18Field(privateRecord19, int *, 0x44) != 0) {
        Actor18Call3585CView1(ownerRecord20, 0x10E, 2, 0, 0, 0);
    }
    if (Actor18Field(privateRecord19, int *, 8) != 0) {
        Actor18Call3BABCView1(ownerRecord20, 0, 0);
        if (Actor18Field(ownerRecord20, unsigned char *, 0x3D) != 1) {
            Actor18Data6C770View1 = 0;
            Actor18Field(ownerRecord20, signed char *, 0x40) = 0x72;
            Actor18Field(ownerRecord20, unsigned char *, 0x3D) = 1U;
            Actor18Field(ownerRecord20, signed char *, 0x3F) = 0;
            Actor18Call35734View1(ownerRecord20);
        }
        Actor18Field(privateRecord19, int *, 8) = 0;
    }
    if ((Actor18Call55E84View1(ownerRecord20) >= 8) && (Actor18Field(privateRecord19, int *, 0x3C) != 1) && (Actor18Field(ownerRecord20, unsigned short *, 0x3C) == 0x101)) {
        Actor18Call3BABCView1(ownerRecord20, 1, 0);
        Actor18Field(privateRecord19, int *, 0x3C) = 1;
    }
    else if (Actor18Data6C770View1 != 0) {
        if (Actor18Field(ownerRecord20, unsigned char *, 0x3D) != 0) {
            Actor18Data6C770View1 = 0;
            Actor18Field(ownerRecord20, signed char *, 0x40) = 0x72;
            Actor18Field(ownerRecord20, unsigned char *, 0x3D) = 0U;
            Actor18Field(ownerRecord20, signed char *, 0x3F) = 0;
            Actor18Call35734View1(ownerRecord20);
        }
        Actor18Field(privateRecord19, int *, 0x3C) = 0;
    }
    if (Actor18Data6E538View1 & 0x80) {
        if (!(Actor18Field(privateRecord19, int *, 0x1C) & 1)) {
            if ((Actor18Data6E344View1 != 1) && (Actor18Data6E344View1 != 0xF)) {
                if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(privateRecord19, int *, 0x48)) == 0) {
                    Actor18Field(privateRecord19, int *, 0x48) = Actor18Call3BABCView1(ownerRecord20, 3, 4);
                }
            }
            else {
                goto checkStatusBit;
            }
        }
        else {
            goto updateStatusHandle;
        }
    }
    else {
    checkStatusBit:
        if (Actor18Field(privateRecord19, int *, 0x1C) & 1) {
        updateStatusHandle:
            if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(privateRecord19, int *, 0x48)) == 0) {
                Actor18Field(privateRecord19, int *, 0x48) = Actor18Call3BABCView1(ownerRecord20, 4, 4);
            }
        }
        else if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(privateRecord19, int *, 0x48)) != 0) {
            if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(privateRecord19, int *, 0x48)) != 0) {
                Actor18Call3BE70View1(Actor18Field(privateRecord19, int *, 0x48));
            }
            Actor18Field(privateRecord19, int *, 0x48) = -1;
        }
    }
    Actor18Call359A4View1(privateRecord19, 4);
    if ((Actor18Data6E538View1 & 0x60) && (playerModePointer16 = &Actor18Data70328View1 + 0x48, (Actor18Field(&Actor18Data70328View1, int *, 0x48) != 0x99)) && (Actor18Data6E344View1 != 1)) {
        if (Actor18Data6E344View1 != 0xF) {
            if (Actor18Field(privateRecord19, int *, 0) <= 0) {
                if (Actor18Data6E538View1 & 0x40) {
                    rawWord2 = Actor18Field(privateRecord19, int*, 0x1C);
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    rawWord3 = rawWord2&0x1E;
                    switch (rawWord3) {
                    case 4:
                        temporaryWord9 = &Actor18Data745CCView2;
                        __asm__("":"=r"(temporaryWord9):"0"(temporaryWord9));
                        rawWord2 = Actor18Field(temporaryWord9, int*, 0);
                        rawWord3 = Actor18Field(temporaryWord9, int*, 4);
                        argumentWord4 = Actor18Field(temporaryWord9, int*, 8);
                        originalFrame.sp20 = rawWord2;
                        originalFrame.sp24 = rawWord3;
                        originalFrame.sp28 = argumentWord4;
                        __asm__ __volatile__("":::"$16", "memory");
                        firstSpawnIndex16 = 0;
                        do {
                            spawnedRecord18 = Actor18DataSpawnMobyView1(0xBB, ownerRecord20);
                            __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                            if (spawnedRecord18 != 0) {
                                Actor18Field(spawnedRecord18, unsigned char *, 0x46) = Actor18Call3617CView1(Actor18Field(spawnedRecord18, unsigned char *, 0x46), Actor18Field((((unsigned char*)&originalFrame-0x20) + (firstSpawnIndex16 * 4)), int *, 0x20));
                                if (Actor18Call18368View1(&Actor18Data70328View1, spawnedRecord18 + 0xC) != 0) {
                                    Actor18Call55B18View1(spawnedRecord18);
                                }
                                Actor18Call3BABCView1(spawnedRecord18, 0, 1);
                            }
                            firstSpawnIndex16 += 1;
                        }
                        while (firstSpawnIndex16 < 3);
                        rawWord2 = Actor18Field(privateRecord19, int*, 0x20);
                        __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
                        rawWord3 = 50;
                        __asm__ __volatile__(""::"r"(rawWord2), "r"(rawWord3), "i"(0x8007b030):"memory");
                        Actor18Field(privateRecord19, int*, 0) = rawWord3;
                        goto decrementCountdown;
                    case 8:
                        temporaryWord10 = &Actor18Data745CCView2;
                        __asm__("":"=r"(temporaryWord10):"0"(temporaryWord10));
                        rawWord2 = Actor18Field(temporaryWord10, int*, 0);
                        rawWord3 = Actor18Field(temporaryWord10, int*, 4);
                        argumentWord4 = Actor18Field(temporaryWord10, int*, 8);
                        originalFrame.sp30 = rawWord2;
                        originalFrame.sp34 = rawWord3;
                        originalFrame.sp38 = argumentWord4;
                        __asm__ __volatile__("":::"$16", "memory");
                        secondSpawnIndex16 = 0;
                        do {
                            spawnedRecord18 = Actor18DataSpawnMobyView1(0x97, ownerRecord20);
                            __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                            if (spawnedRecord18 != 0) {
                                Actor18Field(spawnedRecord18, unsigned char *, 0x46) = Actor18Call3617CView1(Actor18Field(spawnedRecord18, unsigned char *, 0x46), Actor18Field((((unsigned char*)&originalFrame-0x20) + (secondSpawnIndex16 * 4)), int *, 0x30));
                                if (Actor18Call18368View1(&Actor18Data70328View1, spawnedRecord18 + 0xC) != 0) {
                                    if (Actor18Call3BFC0View1(spawnedRecord18, Actor18Field(Actor18Field(spawnedRecord18, void **, 0), int *, 8)) != 0) {
                                        if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(Actor18Field(spawnedRecord18, void **, 0), int *, 8)) != 0) {
                                            Actor18Call3BE70View1(Actor18Field(Actor18Field(spawnedRecord18, void **, 0), int *, 8));
                                        }
                                        Actor18Field(Actor18Field(spawnedRecord18, void **, 0), int *, 8) = -1;
                                    }
                                    Actor18Call55B18View1(spawnedRecord18);
                                }
                                Actor18Call3BABCView1(spawnedRecord18, 0, 1);
                            }
                            secondSpawnIndex16 += 1;
                        }
                        while (secondSpawnIndex16 < 3);
                        rawWord2 = Actor18Field(privateRecord19, int*, 0x20);
                        __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
                        rawWord3 = 50;
                        __asm__ __volatile__(""::"r"(rawWord2), "r"(rawWord3), "i"(0x8007b138):"memory");
                        Actor18Field(privateRecord19, int*, 0) = rawWord3;
                        goto decrementCountdown;
                    case 16:
                        spawnedRecord18 = Actor18DataSpawnMobyView1(0x251, ownerRecord20);
                        __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                        if (spawnedRecord18 != 0) {
                            if (Actor18Call18368View1(playerModePointer16 - 0x48, spawnedRecord18 + 0xC) != 0) {
                                Actor18Call55B18View1(spawnedRecord18);
                            }
                            else {
                                Actor18Field(Actor18Field(spawnedRecord18, void**, 0), int *, 0) = (int) ((int) (Actor18Field(&Actor18Data65920View1, short*, (Actor18Field(&Actor18Data70328View1, unsigned char *, 0xE) * 2)) * 0xAF) >> 0xC);
                                Actor18Field(Actor18Field(spawnedRecord18, void**, 0), int *, 4) = (int) ((int) (Actor18Field(&Actor18Data658A0View1, short*, (Actor18Field(&Actor18Data70328View1, unsigned char *, 0xE) * 2)) * 0xAF) >> 0xC);
                                Actor18Field(Actor18Field(spawnedRecord18, void**, 0), int *, 8) = 0;
                                rawWord2 = Actor18Field(privateRecord19, int*, 0x20);
                                __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
                                rawWord3 = 50;
                                __asm__ __volatile__(""::"r"(rawWord2), "r"(rawWord3), "i"(0x8007b21c):"memory");
                                Actor18Field(privateRecord19, int*, 0) = rawWord3;
                                goto decrementCountdown;
                            }
                        }
                        break;
                    case 2:
                        temporaryWord17 = (unsigned char*)&originalFrame.sp40;
                        temporaryWord16 = &Actor18Data745D8View1;
                        copyEnd8 = temporaryWord16+128;
                        do {
                            rawWord2 = Actor18Field(temporaryWord16, int*, 0);
                            rawWord3 = Actor18Field(temporaryWord16, int*, 4);
                            argumentWord4 = Actor18Field(temporaryWord16, int*, 8);
                            argumentWord5 = Actor18Field(temporaryWord16, int*, 12);
                            Actor18Field(temporaryWord17, int*, 0) = rawWord2;
                            Actor18Field(temporaryWord17, int*, 4) = rawWord3;
                            Actor18Field(temporaryWord17, int*, 8) = argumentWord4;
                            Actor18Field(temporaryWord17, int*, 12) = argumentWord5;
                            __asm__ __volatile__("":"=r"(temporaryWord16):"0"(temporaryWord16):"memory");
                            temporaryWord16 += 0x10;
                            temporaryWord17 += 0x10;
                        }
                        while (temporaryWord16 != copyEnd8);
                        temporaryWord13 = Actor18Field(privateRecord19, unsigned short *, 0x30);
                        if (temporaryWord13 >= 0x1FU) {
                            Actor18Field(privateRecord19, unsigned short *, 0x30) = 0U;
                        }
                        else {
                            Actor18Field(privateRecord19, unsigned short *, 0x30) = (unsigned short) (temporaryWord13 + 1);
                        }
                        spawnedRecord18 = Actor18DataSpawnMobyView1(0x175, ownerRecord20);
                        __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                        if (spawnedRecord18 != 0) {
                            Actor18Field(privateRecord19, int *, 0) = 1;
                            Actor18Field(Actor18Field(spawnedRecord18, void**, 0), int *, 0) = (int) ((int) (Actor18Field(&Actor18Data65920View1, short*, (Actor18Call3617CView1(Actor18Field(&Actor18Data70328View1, unsigned char *, 0xE), Actor18Field(&(&originalFrame.sp20)[(short) Actor18Field(privateRecord19, unsigned short *, 0x30)], int *, 0x20)) * 2)) * 0xE1) >> 0xB);
                            Actor18Field(Actor18Field(spawnedRecord18, void**, 0), int *, 4) = (int) ((int) (Actor18Field(&Actor18Data658A0View1, short*, (Actor18Call3617CView1(Actor18Field(&Actor18Data70328View1, unsigned char *, 0xE), Actor18Field(&(&originalFrame.sp20)[(short) Actor18Field(privateRecord19, unsigned short *, 0x30)], int *, 0x20)) * 2)) * 0xE1) >> 0xB);
                            Actor18Field(Actor18Field(spawnedRecord18, void**, 0), int *, 8) = 0;
                            if (Actor18Call18368View1((&Actor18Data70328View1 + 0xE) - 0xE, spawnedRecord18 + 0xC) != 0) {
                                Actor18Call55B18View1(spawnedRecord18);
                            }
                            if (Actor18Field(privateRecord19, int *, 0x20) == ((Actor18Field(privateRecord19, int *, 0x20) / 5) * 5)) {
                                Actor18Call3BABCView1(spawnedRecord18, 0, 1);
                            }
                        }
                        rawWord2 = Actor18Field(privateRecord19, int*, 0x20);
                    decrementCountdown:
                        rawWord2 -= 1;
                        Actor18Field(privateRecord19, int *, 0x20) = rawWord2;
                        if ((rawWord2 <= 0) && (temporaryWord3 = Actor18Field(privateRecord19, short *, 0x36), Actor18Field(privateRecord19, int *, 0x1C) = (int) (Actor18Field(privateRecord19, int *, 0x1C) & ~0x1E), (temporaryWord3 != -1))) {
                            Actor18Call28154View1((int) temporaryWord3);
                        }
                        break;
                        default:break;
                    }
                }
                else if ((Actor18Data6E538View1 & 0x20) && (Actor18Field(privateRecord19, short *, 0x32) < 0x37) && (spawnedRecord18 = Actor18DataSpawnMobyView1(0x175, ownerRecord20), (spawnedRecord18 != 0))) {
                    Actor18Field(privateRecord19, int *, 0) = 0xB;
                    __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                    if (Actor18Call18368View1(playerModePointer16 - 0x48, spawnedRecord18 + 0xC) != 0) {
                        Actor18Call55B18View1(spawnedRecord18);
                    }
                    Actor18Call3BABCView1(spawnedRecord18, 0, 1);
                }
            }
        }
        else {
            goto resetSequenceIndex;
        }
    }
    else {
    resetSequenceIndex:
        rawWord2 = -1;
        Actor18Field(privateRecord19, unsigned short *, 0x30) = rawWord2;
    }
    Actor18Field(privateRecord19, short *, 0x32) = 0;
    Actor18Call55D24View1(ownerRecord20, 4);
    rawWord2 = Actor18Data70328View2;
    rawWord2 = Actor18Field(&Actor18Data6585CView2, int*, rawWord2*4);
    Actor18Field(ownerRecord20, int*, 0x54) = rawWord2;
    __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
    if (Actor18Data70328View3 >= 2) {
        Actor18Call55F14View1(ownerRecord20, 1, &originalFrame.sp20);
        originalFrame.sp28 = (int) (originalFrame.sp28 + Actor18Field(ownerRecord20, int *, 0x14)) >> 1;
        Actor18DataSpawnParticleView1(2, 0x42, &originalFrame.sp20, 0);
        Actor18Call55F14View1(ownerRecord20, 2, &originalFrame.sp20);
        originalFrame.sp28 = (int) (originalFrame.sp28 + Actor18Field(ownerRecord20, int *, 0x14)) >> 1;
        Actor18DataSpawnParticleView1(2, 0x42, &originalFrame.sp20, 0);
    }
    if (Actor18Field(&Actor18Data70328View1, int *, 0x48) == 0x99) {
        Actor18Call55F14View1(ownerRecord20, 0, privateRecord19 + 0x10);
        temporaryPointer4 = Actor18Field(privateRecord19, void **, 0xC);
        Actor18Field(privateRecord19, int *, 0x18) = (int) (Actor18Field(privateRecord19, int *, 0x18) + 0x100);
        if ((unsigned char) Actor18Field(temporaryPointer4, unsigned char *, 0x65) < 0x10U) {
            if (temporaryPointer4 != 0) {
                Actor18Call509E8View1(temporaryPointer4);
            }
            Actor18Field(privateRecord19, void **, 0xC) = 0;
        }
        if (Actor18Field(privateRecord19, void **, 0xC) == 0) {
            Actor18Field(privateRecord19, void **, 0xC) = Actor18Call50844View1(privateRecord19 + 0x10, -0xC, 0x10, Actor18Field(&Actor18Data6585CView3, int*, (Actor18Data70328View4 * 4)) & 0xFFFFFF);
        }
        else {
            if (Actor18Call4F264View1(Actor18Field(ownerRecord20, unsigned char*, 0x46), 0) < 32) goto bright28;
            if (Actor18Call4F264View1(Actor18Field(ownerRecord20, unsigned char*, 0x46), 128) >= 32) goto dark28;
        bright28:
            memoryCursor3 = Actor18Field(privateRecord19, void**, 12);
            __asm__ __volatile__(""::"r"(memoryCursor3), "i"(0x8007b604):"memory");
            rawWord2 = 244;
            goto color28;
        dark28:
            rawWord2 = 7;
            memoryCursor3 = Actor18Field(privateRecord19, void**, 12);
        color28:
            __asm__ __volatile__(""::"r"(rawWord2), "r"(memoryCursor3):"memory");
            Actor18Field(memoryCursor3, signed char*, 0x66) = rawWord2;
            __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
            Actor18Field(Actor18Field(privateRecord19, void **, 0xC), signed char *, 0x68) = (signed char) Actor18Field(&Actor18Data6585CView4, int*, (Actor18Data70328View5 * 4));
            __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
            Actor18Field(Actor18Field(privateRecord19, void **, 0xC), signed char *, 0x69) = (signed char) ((int) Actor18Field(&Actor18Data6585CView5, int*, (Actor18Data70328View6 * 4)) >> 8);
            __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
            rawWord2 = Actor18Data70328View7;
            memoryCursor3 = Actor18Field(privateRecord19, void**, 12);
            rawWord2 = Actor18Field(&Actor18Data6585CView6, short*, rawWord2*4);
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Actor18Field(memoryCursor3, signed char*, 0x6A) = rawWord2;
        }
    }
    else {
        temporaryPointer14 = Actor18Field(privateRecord19, void **, 0xC);
        if (temporaryPointer14 != 0) {
            Actor18Field(temporaryPointer14, unsigned char *, 0x65) = (unsigned char) (Actor18Field(temporaryPointer14, unsigned char *, 0x65) - 1);
            temporaryPointer5 = Actor18Field(privateRecord19, void **, 0xC);
            if (Actor18Field(temporaryPointer5, unsigned char *, 0x65) == 0) {
                Actor18Call509E8View1(temporaryPointer5);
                Actor18Field(privateRecord19, void **, 0xC) = 0;
            }
            else {
                Actor18Call55F14View1(ownerRecord20, 0, privateRecord19 + 0x10);
                Actor18Field(privateRecord19, int *, 0x18) = (int) (Actor18Field(privateRecord19, int *, 0x18) + 0x100);
            }
        }
    }
    temporaryWord15 = Actor18Field(privateRecord19, int *, 0x1C) & 0x21;
    switch (temporaryWord15) {
    case 1:
        if (Actor18Call359A4View1(privateRecord19 + 0x24, 4) != 0) {
            if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(privateRecord19, int *, 0x48)) != 0) {
                if (Actor18Call3BFC0View1(ownerRecord20, Actor18Field(privateRecord19, int *, 0x48)) != 0) {
                    Actor18Call3BE70View1(Actor18Field(privateRecord19, int *, 0x48));
                }
                Actor18Field(privateRecord19, int *, 0x48) = -1;
            }
            temporaryWord6 = Actor18Field(privateRecord19, short *, 0x34);
            Actor18Field(privateRecord19, int *, 0x1C) = (int) (Actor18Field(privateRecord19, int *, 0x1C) & ~0x21);
            if (temporaryWord6 != -1) {
                Actor18Call28154View1((int) temporaryWord6);
            }
            Actor18Field(privateRecord19, short *, 0x34) = -1;
        }
        else if (Actor18Field(privateRecord19, void ***, 0x2C) == 0) {
            Actor18Field(privateRecord19, void ***, 0x2C) = Actor18DataSpawnMobyView1(0xA3, ownerRecord20);
        }
        break;
    case 32:
        if (Actor18Call359A4View1(privateRecord19 + 0x24, 4) != 0) {
            temporaryWord7 = Actor18Field(privateRecord19, short *, 0x34);
            Actor18Field(privateRecord19, int *, 0x1C) = (int) (Actor18Field(privateRecord19, int *, 0x1C) & ~0x21);
            if (temporaryWord7 != -1) {
                Actor18Call28154View1((int) temporaryWord7);
            }
            Actor18Field(privateRecord19, short *, 0x34) = -1;
            Actor18Field(ownerRecord20, signed char *, 0x4C) = 0x20;
            Actor18Field(ownerRecord20, signed char *, 0x4D) = 1;
        }
        break;
    }
    rawWord2 = Actor18Field(privateRecord19, int*, 0x1C);
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    rawWord3 = rawWord2&30;
    if (rawWord3 == 4) goto finishActiveCountdown;
    if (rawWord3 >= 5) goto upper28;
    if (rawWord3 == 2) goto finishActiveCountdown;
    goto exit28;
upper28:
    if (rawWord3 == 8) goto finishActiveCountdown;
    if (rawWord3 != 16) goto exit28;
finishActiveCountdown:
    if (Actor18Field(privateRecord19, int *, 0x20) <= 0) {
        temporaryWord8 = Actor18Field(privateRecord19, short *, 0x36);
        Actor18Field(privateRecord19, int *, 0x1C) = (int) (Actor18Field(privateRecord19, int *, 0x1C) & ~0x1E);
        if (temporaryWord8 != -1) {
            Actor18Call28154View1((int) temporaryWord8);
        }
    }
    exit28:;
}
#undef Actor18Field


/* AI-generated; not human reviewed. SCUS-94467 USA Rev0 original
 * words govern this actor family. Reuses verified raw601 signed trig/packet
 * code; original owner count, collision/helper chain, delta resets retained.
 * Raw coordinates, producer/helper semantics and cadence remain unresolved.
 * Test: independent original object/linked words and every retail hash. */
typedef struct { Vector3D delta; int timer; } DecodedRawProjectileTag;
typedef struct { Vector3D oldPosition; int pad24; Vector3D particlePosition; int pad34; Vector3D direction; int pad44; int reserved48[4]; } DecodedRawProjectileWork;
extern void* DecodedRawProjectilePlayerLink __asm__("D_80070328+0x250");
extern short D_800658A0[], D_80065920[];
void func_level_18_8007B8AC(Moby* argument) {
    DecodedRawProjectileWork work;
    register Moby* moby __asm__("$18") = argument;
    register DecodedRawProjectileTag* tag __asm__("$19");
    register int x __asm__("$6") = moby->position.x;
    register int y __asm__("$5");
    register int z __asm__("$4");
    register void* retained __asm__("$17");
    register int opposite __asm__("$19");
    register int heading __asm__("$16");
    register Vector3D* position __asm__("$20");
    register void* parent __asm__("$7");
    register int maximum __asm__("$3");
    char* particle;
    __asm__("" : "=r"(moby) : "0"(moby));
    {
        register void* link __asm__("$2") = DecodedRawProjectilePlayerLink;
        register int below __asm__("$3");
        tag = moby->mobyTag;
        below = x < 1024;
        /* These ties preserve computed values and emit no instructions. */
        __asm__("" : "=r"(below) : "0"(below), "r"(link), "r"(tag));
        parent = *(void**)link;
        if (below) goto cleanup;
    }
    y = moby->position.y;
    if (y < 1024) goto cleanup;
    z = moby->position.z;
    if (z < 1024) goto cleanup;
    maximum = 256000;
    __asm__("" : "=r"(maximum) : "0"(maximum));
    {
        register int outside __asm__("$2");
        outside = x > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
        outside = y > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
        outside = z > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
    }
    if (!*((unsigned char*)moby + 0x4D)) goto cleanup;
    position = &moby->position;
    *(unsigned short*)((char*)parent + 0x32) += 1;
    func_8004F178(&work.oldPosition,position);
    moby->position.x += tag->delta.x;
    moby->position.y += tag->delta.y;
    moby->position.z += tag->delta.z;
    if (moby->state == 0) {
        retained = func_8001BA30(position,50,1,0,0x10000,moby);
        if (retained) {
            register int firstHeading __asm__("$2") = func_8004E880(((Moby*)retained)->position.x - moby->position.x,
                ((Moby*)retained)->position.y - moby->position.y,0);
            {
                register int zero __asm__("$6") = 0;
                int deltaHeading;
                __asm__("" : "=r"(zero) : "0"(zero), "r"(firstHeading));
                heading = firstHeading;
                deltaHeading = func_8004E880(tag->delta.x,tag->delta.y,zero);
                ((unsigned char*)retained)[0x51] = func_800360F8(heading,deltaHeading,32,64);
            }
        }
        if (func_800359A4(&tag->timer,4) || retained ||
                ({ int collided;
                    /* The collision pointer is already tested and dead here.
                     * Retail passes a fresh zero rather than reusing that register.
                     * This clobber emits no instruction. */
                    __asm__("" : : : "$17");
                    collided = func_8001830C(&work.oldPosition,position,0,0x10000,moby);
                    collided; })) {
            tag->delta.x = 0;
            tag->delta.y = 0;
            tag->delta.z = 0;
            func_8004F178(&moby->position,&work.oldPosition);
            moby->state = 98;
        }
        {
            register int result __asm__("$2") = func_8004E880(tag->delta.x,tag->delta.y,0);
            register int low __asm__("$4") = 0;
            register int high __asm__("$5") = 14;
            __asm__("" : "=r"(low), "=r"(high) : "0"(low), "1"(high), "r"(result));
            heading = result;
            heading += func_800363DC(low,high);
        }
        opposite = heading;
        __asm__ volatile ("" : : "r"(opposite));
        retained = &work.particlePosition;
        func_8004F178(retained,&moby->position);
        /* Preserve both signed table lanes and the raw particle packet writes. */
        {
            register int primaryIndex __asm__("$3") = opposite & 255;
            register int oppositeIndex __asm__("$7");
            register int cosine __asm__("$5");
            register int kind __asm__("$4");
            register int selector __asm__("$5");
            register Vector3D* positionArg __asm__("$6");
            register char* (*spawn)(int,int,Vector3D*,Vector3D*) __asm__("$8");
            __asm__("" : "=r"(primaryIndex) : "0"(primaryIndex));
            opposite = heading - 128;
            __asm__("" : "=r"(opposite) : "0"(opposite));
            primaryIndex *= 2;
            kind = 1;
            __asm__("" : "=r"(kind) : "0"(kind));
            oppositeIndex = (opposite & 255) * 2;
            __asm__("" : "=r"(primaryIndex), "=r"(oppositeIndex) : "0"(primaryIndex), "1"(oppositeIndex));
            cosine = *(short*)((char*)D_80065920 + primaryIndex);
            spawn = SpawnParticle;
            __asm__("" : "=r"(cosine), "=r"(spawn) : "0"(cosine), "1"(spawn));
            work.direction.x = (cosine * 15) >> 11;
            {
                register int sine __asm__("$3") = *(short*)((char*)D_800658A0 + primaryIndex);
                __asm__("" : "=r"(sine) : "0"(sine));
                positionArg = retained;
                __asm__("" : "=r"(positionArg) : "0"(positionArg));
                work.direction.z = 0;
                __asm__ volatile ("" : : : "memory");
                work.direction.y = (sine * 15) >> 11;
            }
            {
                register int sample __asm__("$3") = *(short*)((char*)D_80065920 + oppositeIndex);
                __asm__("" : "=r"(sample) : "0"(sample) : "$5");
                selector = 13;
                __asm__("" : "=r"(selector) : "0"(selector), "r"(sample));
                work.particlePosition.x += (sample * 5) >> 9;
            }
            {
                register int sample __asm__("$2") = *(short*)((char*)D_800658A0 + oppositeIndex);
                register int product __asm__("$3") = sample * 5;
                __asm__("" : "=r"(product) : "0"(product));
                work.particlePosition.y += product >> 9;
            }
            particle = spawn(kind,selector,positionArg,&work.direction);
        }
        particle[2] = 14;
        particle[10] += 56;
    }
done:
    if (moby->state != 98) return;
cleanup:
    func_80055B18(moby);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_18/moby", D_level_18_800745D8);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_18/moby/func_level_18_8007BBA4.s SHA256 72b12ef6bcab5f2f8eb404df8c6691e621662223a91a172585e73c16e90390c7. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level18_7BBA4Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Level18_7BBA4_func_80013E38() __asm__("func_80013E38");
         /* extern */
unsigned char Level18_7BBA4_func_80034F40() __asm__("func_80034F40");
             /* extern */
unsigned char Level18_7BBA4_func_8003573C() __asm__("func_8003573C");
 /* extern */
unsigned char Level18_7BBA4_func_8003585C() __asm__("func_8003585C");
 /* extern */
int Level18_7BBA4_func_800359A4() __asm__("func_800359A4");
                 /* extern */
int Level18_7BBA4_func_80035DDC() __asm__("func_80035DDC");
 /* extern */
unsigned char Level18_7BBA4_func_8003617C() __asm__("func_8003617C");
                          /* extern */
int Level18_7BBA4_func_80036220() __asm__("func_80036220");
 /* extern */
unsigned char Level18_7BBA4_func_8003645C() __asm__("func_8003645C");
       /* extern */
unsigned char Level18_7BBA4_func_800369B8() __asm__("func_800369B8");
             /* extern */
unsigned char Level18_7BBA4_func_8003B74C() __asm__("func_8003B74C");
                   /* extern */
unsigned char Level18_7BBA4_func_8003BA00() __asm__("func_8003BA00");
                      /* extern */
unsigned char Level18_7BBA4_func_8003BABC() __asm__("func_8003BABC");
    /* extern */
int Level18_7BBA4_func_8004E880() __asm__("func_8004E880");
          /* extern */
unsigned char Level18_7BBA4_func_8004F178() __asm__("func_8004F178");
                  /* extern */
int Level18_7BBA4_func_8004F334() __asm__("func_8004F334");
                   /* extern */
unsigned char Level18_7BBA4_func_80055B18() __asm__("func_80055B18");
                      /* extern */
unsigned char Level18_7BBA4_func_80055D24() __asm__("func_80055D24");
             /* extern */
int Level18_7BBA4_rand() __asm__("rand");
                                         /* extern */
extern unsigned char Level18_7BBA4_D_8006D088 __asm__("D_8006D088");
extern int Level18_7BBA4_D_80070328 __asm__("D_80070328");
extern void *Level18_7BBA4_D_80071930 __asm__("D_80071930");
extern int (*Level18_7BBA4_unk_ovlheader_800743C4)() __asm__("unk_ovlheader_800743C4");
extern unsigned char (*Level18_7BBA4_unk_ovlheader_800743E0)() __asm__("unk_ovlheader_800743E0");

void func_level_18_8007BBA4(void *ownerRecord) {
    /* Original 0x50-byte frame: scratch starts at SP+0x18, the copy at
     * SP+0x20 occupies three words, and saved registers start at SP+0x38.
     * LBU/LHU already zero-extend: local register roles use full-width words
     * while the original byte/halfword stores retain their storage widths.
     * The volatile argument6 retains the original zero producer in the
     * condition's delay slot. No instruction asm or compiler changes.
     * Physical units, helper effects and invocation cadence remain open. */
    struct {
        int sp18;
        unsigned char pad1C[4];
        int sp20, sp24;
        unsigned char pad28[8];
    } scratch;

    register int indexWord4 __asm__("$4");
    register short nextIndex2 __asm__("$2");
    register int ownerWord7 __asm__("$7");
    register int initialHelperResult20 __asm__("$20");
    register int predicate2 __asm__("$2");
    register int deltaWord4 __asm__("$4");
    register int otherDeltaWord4 __asm__("$4");
    register int deltaWord5 __asm__("$5");
    register int otherDeltaWord5 __asm__("$5");
    register int phaseFlag18 __asm__("$18");
    register int candidateFlag18 __asm__("$18");
    register int selectedWord2 __asm__("$2");
    register int limitPredicate2 __asm__("$2");
    register unsigned int footerFlags4 __asm__("$4");
    register unsigned int flags3 __asm__("$3");
    register unsigned int otherFlags3 __asm__("$3");
    register unsigned int footerFlags3 __asm__("$3");
    register unsigned int headerByte3 __asm__("$3");
    register unsigned int stateByte3 __asm__("$3");
    register unsigned int selectorWord5 __asm__("$5");
    register void *argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument7 __asm__("$7");
    register volatile int argument6 __asm__("$6");
    register int word2 __asm__("$2");
    register void *privateRecord17 __asm__("$17");
    register void *ownerWords18 __asm__("$18");
    register void *nestedRecord19 __asm__("$19");

    privateRecord17=Level18_7BBA4Field(ownerRecord,void**,0);
    nestedRecord19=Level18_7BBA4Field(privateRecord17,void**,0x38);
    phaseFlag18=0;
    if(Level18_7BBA4Field(ownerRecord,int*,0x18)!=0){
        headerByte3=Level18_7BBA4Field(ownerRecord,unsigned char*,0x48);
        if(headerByte3!=2){
            if(headerByte3==0 && (Level18_7BBA4Field(privateRecord17,unsigned short*,0x18)&4))
                Level18_7BBA4_unk_ovlheader_800743E0(Level18_7BBA4Field(ownerRecord,unsigned char*,0x43),1);
            argument4=ownerRecord;
            argument5=0;
            word2=Level18_7BBA4Field(privateRecord17,unsigned short*,0x18);
            argument6=0;
            word2|=0x80;
            Level18_7BBA4Field(privateRecord17,unsigned short*,0x18)=word2;
            Level18_7BBA4Field(ownerRecord,int*,8)=0;
            goto cleanupCalls;
        }
    }
    initialHelperResult20=Level18_7BBA4_func_8004F334(ownerRecord+0xC,&Level18_7BBA4_D_80070328);
    __asm__ volatile("":"=r"(initialHelperResult20):"0"(initialHelperResult20):"memory");
    headerByte3=Level18_7BBA4Field(ownerRecord,unsigned char*,0x48);
    if(headerByte3!=2){
        predicate2=initialHelperResult20<0x384;
        if(predicate2){
            if(!(Level18_7BBA4Field(privateRecord17,unsigned short*,0x18)&0x600)){
                Level18_7BBA4Field(&Level18_7BBA4_D_80070328,int*,0x24)|=1;
            }else{
                Level18_7BBA4_func_8003B74C(&Level18_7BBA4_D_8006D088);
            }
            argument4=ownerRecord;
            argument5=0;
            word2=Level18_7BBA4Field(privateRecord17,unsigned short*,0x18);
            argument6=0;
            word2|=0x80;
            Level18_7BBA4Field(privateRecord17,unsigned short*,0x18)=word2;
            goto cleanupCalls;
        }
    }
    Level18_7BBA4Field(ownerRecord,unsigned char*,0x4E)=4;
    if(Level18_7BBA4Field(privateRecord17,int*,0x1C)!=0){
        stateByte3=Level18_7BBA4Field(ownerRecord,unsigned char*,0x48);
        if(stateByte3==1){
            Level18_7BBA4Field(ownerRecord,unsigned char*,0x48)=0;
            Level18_7BBA4_func_80034F40(ownerRecord,0);
            goto reloadStateByte;
        }
    }else{
reloadStateByte:
        stateByte3=Level18_7BBA4Field(ownerRecord,unsigned char*,0x48);
    }
    if(stateByte3<8U){
        switch (stateByte3) {
        /* This initialized state-byte input retains the original SLL2,3
         * dispatch operand. The switch guard proves the index is0..7. */
        case 0:
            __asm__ volatile(""::"r"(stateByte3));
            flags3=Level18_7BBA4Field(privateRecord17,unsigned short*,0x18);
            if(!(flags3&0x80)){
                Level18_7BBA4_func_8003573C(ownerRecord, 5, 0, 0);
                phaseFlag18 = 1;
            } else {goto applyMaskAndSetState3;
            }
            goto commonTail;
        case 1:
            flags3 = Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18);
            if (flags3 & 0x100) {
                Level18_7BBA4_func_80035DDC(ownerRecord, 0x50, 0, 0x380, 0x21);
                if (Level18_7BBA4_func_800359A4(privateRecord17 + 0x16, 1) != 0) {
                    Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18) = (unsigned short) (Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18) & 0xFEFF);
                    goto case1Tail;
                }
                goto setState3;
            }
            if(!(flags3&0x80))goto case1Tail;
/* Cases0/1 share the original mask/state3 producer here, after case1's
 * flag tests. Moving it into case0 duplicates the original control flow. */
applyMaskAndSetState3:
                argument4=ownerRecord;
                __asm__("":"=r"(argument4):"0"(argument4):"$2","$5");
                argument5=1;
                __asm__("":"=r"(argument5):"0"(argument5):"$2");
                word2=(flags3&0xFF7F)|0x100;
                Level18_7BBA4Field(privateRecord17,unsigned short*,0x18)=word2;
                word2=0x50;
                __asm__("":"=r"(word2):"0"(word2));
                Level18_7BBA4Field(privateRecord17,unsigned char*,0x16)=word2;
                Level18_7BBA4_func_80034F40(argument4,argument5);
setState3:
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 3U;
            goto commonTail;
case1Tail:
            if (initialHelperResult20 >= 0x4075) {
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 5U;
            } else {
                otherFlags3 = Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18);
                if (otherFlags3 & 2) {
                    word2=(otherFlags3&0xFFFD)|1;
                    __asm__("":"=r"(word2):"0"(word2));
                    Level18_7BBA4Field(privateRecord17,unsigned short*,0x18)=word2;
                }
                word2=Level18_7BBA4_func_80035DDC(ownerRecord,0x50,0x380,0x380,0x23);
                word2&=0x20;
                argument6=0;
                if(word2){
                    ownerWord7 = Level18_7BBA4Field(ownerRecord, int *, 0xC);
                    selectedWord2 = Level18_7BBA4_func_8004E880(ownerWord7 - Level18_7BBA4Field(Level18_7BBA4_D_80071930, int *, 0xC), Level18_7BBA4Field(ownerRecord, int *, 0x10) - Level18_7BBA4Field(Level18_7BBA4_D_80071930, int *, 0x10), argument6, ownerWord7);
                } else {
                    selectedWord2 = Level18_7BBA4_unk_ovlheader_800743C4(ownerRecord + 0x49, ownerRecord + 0xC, &Level18_7BBA4_D_80070328);
                }
                argument4=ownerRecord;
                __asm__("":"=r"(argument4):"0"(argument4):"$5");
                selectorWord5=selectedWord2&0xFF;
                argument6=5;
                argument7=0;
                goto sharedCall3585C;
            }
            goto commonTail;
        case 2:
prepareCleanupCall:
            argument4=ownerRecord;
            argument5=0;
            argument6=0;
cleanupCalls:
            Level18_7BBA4_func_8003BABC(argument4,argument5,argument6);
            Level18_7BBA4_func_80055D24(ownerRecord, 4);
            Level18_7BBA4_func_8003BA00(ownerRecord);
            Level18_7BBA4_func_800369B8(ownerRecord, 0x28);
            Level18_7BBA4_func_80055B18(ownerRecord);
            return;
        case 3:
            Level18_7BBA4_func_80035DDC(ownerRecord, 0x50, 0, 0x380, 0x21);
            if (Level18_7BBA4_func_800359A4(privateRecord17 + 0x16, 1) != 0) {
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 4U;
                Level18_7BBA4Field(privateRecord17, signed char *, 0x16) = 0x28;
                Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18) = (unsigned short) (Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18) & 0xFEFF);
                Level18_7BBA4Field(privateRecord17, unsigned char *, 0x11) = Level18_7BBA4_func_8003617C(Level18_7BBA4Field(ownerRecord, unsigned char *, 0x46), (Level18_7BBA4_rand() & 0x1F) - 0x10);
            }
            goto commonTail;
        case 4:
            Level18_7BBA4_func_80035DDC(ownerRecord, 0x50, 0x380, 0x380, 0x23);
            if (Level18_7BBA4_func_800359A4(privateRecord17 + 0x16, 1) != 0) {
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 1U;
            }
            argument4=ownerRecord;
            argument6=5;
            argument7=0;
            phaseFlag18=0;
            selectorWord5=Level18_7BBA4Field(privateRecord17,unsigned char*,0x11);
/* Case1 prepares the return-byte selector before jumping here;
 case4
 * loads its private byte. Their shared six-argument call remains after4. */
sharedCall3585C:
            Level18_7BBA4_func_8003585C(argument4,selectorWord5,argument6,argument7,1,0);
            goto commonTail;
        case 5:
            Level18_7BBA4_func_80035DDC(ownerRecord, 0x50, 0, 0x380, 0x23);
            ownerWords18 = ownerRecord + 0xC;
            if ((Level18_7BBA4_func_80013E38(ownerWords18, privateRecord17 + 0x3C, 1) == 1) || (nestedRecord19 == 0)) {
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 6U;
            } else {
                Level18_7BBA4_func_8003645C(ownerWords18, nestedRecord19, &scratch.sp18);
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 7U;
                Level18_7BBA4Field(nestedRecord19, short *, 2) = (short) scratch.sp18;
            }
            /* fallthrough */
        case 6:
            word2=Level18_7BBA4_func_80035DDC(ownerRecord,0x50,0x380,0x380,0x23);
            word2&=0x20;
            argument6=0;
            if(word2){
                deltaWord4 = Level18_7BBA4Field(ownerRecord, int *, 0xC) - Level18_7BBA4Field(Level18_7BBA4_D_80071930, int *, 0xC);
                deltaWord5 = Level18_7BBA4Field(ownerRecord, int *, 0x10) - Level18_7BBA4Field(Level18_7BBA4_D_80071930, int *, 0x10);
            } else {
                deltaWord4 = Level18_7BBA4Field(privateRecord17, int *, 0x3C) - Level18_7BBA4Field(ownerRecord, int *, 0xC);
                deltaWord5 = Level18_7BBA4Field(privateRecord17, int *, 0x40) - Level18_7BBA4Field(ownerRecord, int *, 0x10);
            }
            Level18_7BBA4_func_8003585C(ownerRecord, Level18_7BBA4_func_8004E880(deltaWord4,deltaWord5,argument6) & 0xFF, 5, 0, 1, 0);
            if (Level18_7BBA4_func_8004F334(ownerRecord + 0xC, privateRecord17 + 0x3C) < 0x200) {
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 0U;
                Level18_7BBA4_func_80034F40(ownerRecord, 0);
            }
            goto enableFlag18;
        case 7:
            Level18_7BBA4_func_8004F178(&scratch.sp20, Level18_7BBA4Field(nestedRecord19, int *, 0xC) + (Level18_7BBA4Field(nestedRecord19, short *, 2) * 0x10));
            word2=Level18_7BBA4_func_80035DDC(ownerRecord,0x50,0x380,0x380,0x23);
            word2&=0x20;
            argument6=0;
            if(word2){
                otherDeltaWord4 = Level18_7BBA4Field(ownerRecord, int *, 0xC) - Level18_7BBA4Field(Level18_7BBA4_D_80071930, int *, 0xC);
                otherDeltaWord5 = Level18_7BBA4Field(ownerRecord, int *, 0x10) - Level18_7BBA4Field(Level18_7BBA4_D_80071930, int *, 0x10);
            } else {
                otherDeltaWord4 = scratch.sp20 - Level18_7BBA4Field(ownerRecord, int *, 0xC);
                otherDeltaWord5 = scratch.sp24 - Level18_7BBA4Field(ownerRecord, int *, 0x10);
            }
            Level18_7BBA4_func_8003585C(ownerRecord, Level18_7BBA4_func_8004E880(otherDeltaWord4,otherDeltaWord5,argument6) & 0xFF, 5, 0, 1, 0);
            if(Level18_7BBA4_func_8004F334(ownerRecord+0xC,&scratch.sp20)>=0x200)goto enableFlag18;
            indexWord4=Level18_7BBA4Field(nestedRecord19,short*,2);
            if(Level18_7BBA4Field(indexWord4*0x10+Level18_7BBA4Field(nestedRecord19,int*,0xC),int*,0xC)!=0)goto setState6;
            nextIndex2=indexWord4+1;
            Level18_7BBA4Field(nestedRecord19,short*,2)=nextIndex2;
            if(nextIndex2<Level18_7BBA4Field(nestedRecord19,short*,0))goto enableFlag18;
setState6:
            Level18_7BBA4Field(ownerRecord,unsigned char*,0x48)=6;
            goto enableFlag18;
/* Cases6/7 enter this original producer. An out-of-range state enters
 * commonTail directly and must retain its prior phaseFlag18. */
enableFlag18:
            phaseFlag18=1;
            goto commonTail;
        }
    } else {
commonTail:
        if ((phaseFlag18 != 0) && (Level18_7BBA4Field(privateRecord17, int *, 0x1C) == 0)) {
            footerFlags3 = Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18);
            candidateFlag18 = 0;
            if (footerFlags3 & 1) {
                word2=Level18_7BBA4Field(privateRecord17,short*,0x1A);
                __asm__("":"=r"(word2):"0"(word2));
                candidateFlag18=initialHelperResult20<word2;
            }
            word2=footerFlags3&2;
            __asm__("":"=r"(word2):"0"(word2),"r"(footerFlags3));
            if(word2){
                if(Level18_7BBA4_func_80036220(&Level18_7BBA4_D_80070328,privateRecord17+0x20,0,0)!=0)candidateFlag18=1;
            }
            limitPredicate2=initialHelperResult20<0x4075;
            if (limitPredicate2 == 0) {
                candidateFlag18 = 0;
            }
            footerFlags4 = Level18_7BBA4Field(privateRecord17, unsigned short *, 0x18);
            if (footerFlags4 & 0x200) {
                candidateFlag18 = 0;
            }
            if (candidateFlag18 != 0) {
                word2=footerFlags4&4;
                __asm__("":"=r"(word2):"0"(word2),"r"(footerFlags4));
                if(word2){
                    Level18_7BBA4_unk_ovlheader_800743E0(Level18_7BBA4Field(ownerRecord, unsigned char *, 0x43), 1);
                }
                Level18_7BBA4Field(ownerRecord, unsigned char *, 0x48) = 1U;
                Level18_7BBA4_func_80034F40(ownerRecord, 1);
            }
        }
    }
}
#undef Level18_7BBA4Field


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Actor8007C2B4Helper4F554(void*,void*) __asm__("func_8004F554");
int Actor8007C2B4Helper4F570(void*,void*) __asm__("func_8004F570");
extern unsigned char Actor8007C2B4D_800676E8[] __asm__("D_800676E8");
extern int Actor8007C2B4D_8006C58C __asm__("D_8006C58C");
extern int Actor8007C2B4D_8006C5C8 __asm__("D_8006C5C8");
#define Actor8007C2B4Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor8007C2B4Helper13E38(void*,void*,int) __asm__("func_80013E38");
int Actor8007C2B4Helper19194(void*,int) __asm__("func_80019194");
int Actor8007C2B4Helper1A358(void*,int) __asm__("func_8001A358");
void* Actor8007C2B4Helper2F040(int) __asm__("func_8002F040");
int Actor8007C2B4Helper36188(void*) __asm__("func_80036188");
int Actor8007C2B4Helper36E60(void*) __asm__("func_80036E60");
int Actor8007C2B4Helper37014(void*) __asm__("func_80037014");
int Actor8007C2B4Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Actor8007C2B4Helper3BFC0(void*,int) __asm__("func_8003BFC0");
int Actor8007C2B4Helper4E880(int,int,int) __asm__("func_8004E880");
int Actor8007C2B4Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Actor8007C2B4Helper4EDE8(void*,int) __asm__("func_8004EDE8");
int Actor8007C2B4Helper4EF74(void*,void*,void*) __asm__("func_8004EF74");
int Actor8007C2B4Helper4F110(void*,int) __asm__("func_8004F110");
int Actor8007C2B4Helper4F178(void*,void*) __asm__("func_8004F178");
int Actor8007C2B4Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Actor8007C2B4Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Actor8007C2B4Helper4F1FC(void*,void*,int) __asm__("func_8004F1FC");
int Actor8007C2B4Helper4F228(void*,void*,int) __asm__("func_8004F228");
int Actor8007C2B4Helper4F264(int,int) __asm__("func_8004F264");
int Actor8007C2B4Helper4F334(void*,void*) __asm__("func_8004F334");
int Actor8007C2B4Helper4F52C(void*,void*) __asm__("func_8004F52C");
int Actor8007C2B4Helper4F5DC(int,void*) __asm__("func_8004F5DC");
int Actor8007C2B4Helper55B18(void*) __asm__("func_80055B18");
int Actor8007C2B4Helper55D24(void*,int) __asm__("func_80055D24");
int Actor8007C2B4Helper56270(void*) __asm__("func_80056270");
int Actor8007C2B4Helper5629C(void*) __asm__("func_8005629C");
extern int Actor8007C2B4D_80065810 __asm__("D_80065810");
extern int Actor8007C2B4D_80065818 __asm__("D_80065818");
extern unsigned char Actor8007C2B4D_800658A0[] __asm__("D_800658A0");
extern unsigned char Actor8007C2B4D_80065920[] __asm__("D_80065920");
extern unsigned char Actor8007C2B4D_80066964[] __asm__("D_80066964");
extern unsigned char Actor8007C2B4D_80066988[] __asm__("D_80066988");
extern unsigned char Actor8007C2B4D_80066990[] __asm__("D_80066990");
extern unsigned char Actor8007C2B4D_80066A48[] __asm__("D_80066A48");
extern int Actor8007C2B4D_8006C648 __asm__("D_8006C648");
extern void * Actor8007C2B4D_8006C65C __asm__("D_8006C65C");
extern unsigned char Actor8007C2B4D_8006DEF8[] __asm__("D_8006DEF8");
extern int Actor8007C2B4D_8006E020 __asm__("D_8006E020");
extern int Actor8007C2B4D_8006E024 __asm__("D_8006E024");
extern unsigned short Actor8007C2B4D_8006E040 __asm__("D_8006E040");
extern unsigned char Actor8007C2B4D_80070328[] __asm__("D_80070328");
extern int Actor8007C2B4D_80071908 __asm__("D_80071908");
extern unsigned char Actor8007C2B4D_80071918[] __asm__("D_80071918");
extern int Actor8007C2B4D_8007192C __asm__("D_8007192C");
extern int (*Actor8007C2B4SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
void func_level_18_8007C2B4(void *input) {
    struct {
        struct {int x,y,z;} first;int p1C;
        struct {int x,y,z;} fifth;int p2C;
        struct {int x,y,z;} sixth;int p3C;
        struct {int x,y,z;} seventh;int p4C;
        struct {int x,y,z;} delta;int p5C;
        struct {int x,y,z;} eighth;int p6C;
        int pad70[4];
    } frame;
    register unsigned char *owner __asm__("$17")=input;
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
    register unsigned char * tag __asm__("$18");
    register unsigned char * callbackTag __asm__("$17");
    void *callbackOwnerReference;
    void *temp_v1_6;

    workingPosition = owner + 0xC;
    tag = Actor8007C2B4Field(owner, void **, 0);
    temp_v0 = Actor8007C2B4Helper4F334(workingPosition, Actor8007C2B4D_80070328);
    {register int old3 __asm__("$3")=Actor8007C2B4Field(tag,short*,0xA);
     register int old __asm__("$4");register int predicate __asm__("$3");
     __asm__("" : "=r"(old3),"=r"(temp_v0):"0"(old3),"1"(temp_v0));
     old=old3;predicate=old3<0x218;
     __asm__("" : "=r"(old),"=r"(predicate),"=r"(temp_v0):"0"(old),"1"(predicate),"2"(temp_v0));
     distanceResult=temp_v0;
     if(predicate) {
       temp_v0=Actor8007C2B4D_8006C648;
       temp_v0=old+temp_v0;
       Actor8007C2B4Field(tag,short*,0xA)=temp_v0;
     } else {
        selectedResource=Actor8007C2B4Helper2F040(Actor8007C2B4Field(owner,unsigned char*,0x49));
        if (selectedResource != 0) {
            if (distanceResult < 0x3000) {
                Actor8007C2B4Field(tag, unsigned char *, 0x13) = (unsigned char) ((int) (selectedResource - Actor8007C2B4D_8006DEF8) >> 4);
                Actor8007C2B4Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007C2B4Field(tag, short *, 0xA) - 0x20);
                Actor8007C2B4Field(tag, unsigned char *, 0x14) = (unsigned char) ((Actor8007C2B4Field(owner, unsigned char *, 0x49) * 2) + (rand() & 1));
            } else {
                Actor8007C2B4Helper4F178(selectedResource, workingPosition);
                if (distanceResult <= 0x7FFF) {
                    Actor8007C2B4Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007C2B4Field(tag, short *, 0xA) - 0x80);
                    Actor8007C2B4Field(selectedResource, int *, 8) = (int) (Actor8007C2B4Field(selectedResource, int *, 8) + 0x80);
                } else {
                    Actor8007C2B4Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007C2B4Field(tag, short *, 0xA) - 0x100);
                }
                Actor8007C2B4Field(tag, unsigned char *, 0x13) = 0xFFU;
            }
            Actor8007C2B4Field(selectedResource, unsigned char *, 0xD) = (unsigned char) (Actor8007C2B4Field(selectedResource, unsigned char *, 0xD) + (rand() & 0x3F));
        } else {
            Actor8007C2B4Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007C2B4Field(tag, short *, 0xA) - 0x100);
        }
        Actor8007C2B4Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007C2B4Field(tag, short *, 0xA) - (rand() & 0xFF));
    }
    }
    temp_s0 = Actor8007C2B4Field(tag, unsigned char *, 0x13);
    __asm__("" : "=r"(temp_s0) : "0"(temp_s0));
    selectorOwner=owner;
    if (temp_s0 < 0x10U) {
        __asm__("" : "=r"(selectorOwner) : "0"(selectorOwner));
        selectorMode=4;
        __asm__("" : "=r"(selectorMode) : "0"(selectorMode));
        temp_s0*=16;
        __asm__("" : "=r"(temp_s0) : "0"(temp_s0) : "$2");
        {register unsigned char *base __asm__("$2")=Actor8007C2B4D_8006DEF8;
         resourceRecord=(unsigned char*)(temp_s0+(int)base);}
        Actor8007C2B4Helper55D24(selectorOwner,selectorMode);
        Actor8007C2B4Helper4F178(resourceRecord, (Actor8007C2B4Field(tag, unsigned char *, 0x14) * 0xC) + (Actor8007C2B4D_80066A48 + 0x30));
        Actor8007C2B4Helper4F1FC(resourceRecord,resourceRecord,2);
        Actor8007C2B4Helper4ED6C(owner + 0x20, resourceRecord, resourceRecord);
        Actor8007C2B4Helper4F194(resourceRecord, resourceRecord, owner + 0xC);
        if ((unsigned char) Actor8007C2B4Field(resourceRecord, unsigned char *, 0xC) < 4U) {
            Actor8007C2B4Field(tag, unsigned char *, 0x13) = 0xFFU;
        }
    }
    if ((Actor8007C2B4Field(owner, unsigned char *, 0x4D) != 0) || (distanceResult < 0x1801) || (Actor8007C2B4Field(owner, unsigned char *, 0x48) != 1) || (Actor8007C2B4Field(tag, unsigned char *, 0x11) != 0)) {
        {register unsigned char *base __asm__("$4")=Actor8007C2B4D_800676E8;
         register int row __asm__("$3");register int column __asm__("$2");register int height __asm__("$3");
         __asm__("" : "=r"(base):"0"(base):"$3","$2");
         row=Actor8007C2B4D_8006C58C;column=Actor8007C2B4D_8006C5C8;
         __asm__("" : "=r"(row),"=r"(column):"0"(row),"1"(column));
         row=row*16+(int)base;
         __asm__("" : "=r"(row):"0"(row));
         column=column*4+row;
         __asm__("" : "=r"(column):"0"(column):"$3");
         height=Actor8007C2B4Field(owner,int*,0x14);column=*(int*)column;
         if (column >= height) {
            Actor8007C2B4Helper4F178(owner + 0xC, Actor8007C2B4D_80070328);
        }
        }
        temp_v1 = Actor8007C2B4Field(owner, unsigned char *, 0x48);
        switch (temp_v1) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            Actor8007C2B4Helper4F178(&frame.first.x, owner + 0xC);
            frame.first.z += 0x400;
            Actor8007C2B4Helper1A358(&frame.first.x, 0x10000);
            Actor8007C2B4Helper36188(tag + 0xE);
            if (Actor8007C2B4Field(tag, int *, 0xC) & 0xFFFF0000) {
                Actor8007C2B4Field(owner, unsigned char *, 0x46) = 0U;
            }
            Actor8007C2B4Field(owner, int *, 0x14) = (int) Actor8007C2B4D_80071908;
            Actor8007C2B4Field(tag, short *, 0xA) = (short) ((rand() & 0xFF) + 0x100);
            Actor8007C2B4Field(owner, unsigned char *, 0x48) = 1U;
            temp_v0_2 = *(Actor8007C2B4D_80066964 + Actor8007C2B4Field(owner, unsigned char *, 0x50));
            Actor8007C2B4Field(owner, unsigned char *, 0x49) = temp_v0_2;
            Actor8007C2B4Field(owner, unsigned char *, 0x3C) = (unsigned char) *(Actor8007C2B4D_80066988 + (temp_v0_2 & 0xFF));
            Actor8007C2B4Field(owner, unsigned char *, 0x54) = (unsigned char) *(Actor8007C2B4D_80066990 + Actor8007C2B4Field(owner, unsigned char *, 0x49));
            goto block_75;
        case 1:                                     /* switch 1 */
            if (Actor8007C2B4Field(tag, short *, 0xA) >= 0x1E) {
                __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult) : "$4");
                temp_a0 = Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 0x44);
                if (({register int pred __asm__("$2")=distanceResult < temp_a0+0x180;__asm__("" : "=r"(pred):"0"(pred));pred;})) {
                    temp_v1_3 = Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 8) - Actor8007C2B4Field(owner, int *, 0x14);
                    if (temp_v1_3 < temp_a0+0x80) {
                        var_v0_2=-Actor8007C2B4Field(Actor8007C2B4D_80070328,int*,0x44);
                        __asm__ volatile("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$6");
                        var_v0_2=var_v0_2 < temp_v1_3;
                        __asm__ volatile("" : "=r"(var_v0_2):"0"(var_v0_2):"memory");
                        if(!var_v0_2) goto block_75;
                        goto block_70;
                    }
                }
            }
            goto block_75;
        case 2:                                     /* switch 1 */
            workingPosition=(unsigned char*)&frame.fifth.x;
            Actor8007C2B4Helper4F554(workingPosition,tag+4);
            Actor8007C2B4Helper4F1FC(workingPosition,workingPosition,Actor8007C2B4D_8006C648);
            Actor8007C2B4Helper4F110(workingPosition,1);
            {register void *first __asm__("$4")=workingPosition;
             __asm__("" : "=r"(first) : "0"(first) : "$20");
             ownerPosition=owner+12;
             Actor8007C2B4Helper4F194(first,ownerPosition,workingPosition);}
            temp_v0_4=Actor8007C2B4Field(tag,short*,8);
            __asm__("" : "=r"(temp_v0_4) : "0"(temp_v0_4));
            {register int old __asm__("$4")=temp_v0_4;
             temp_v0_4=temp_v0_4 < -215;
             if(!temp_v0_4) {
               register int delta __asm__("$3")=Actor8007C2B4D_8006C648;
               register int product __asm__("$2");
               __asm__("" : "=r"(old),"=r"(delta) : "0"(old),"1"(delta));
               product=delta*5;product=old-product;
               Actor8007C2B4Field(tag,short*,8)=product;
             }}
            if (frame.fifth.z < 0x400) {
                Actor8007C2B4Helper36E60(owner);
                Actor8007C2B4Helper55B18(owner);
                return;
            }
            frame.fifth.z += 0xF0;
            if (Actor8007C2B4Helper19194(workingPosition, 0xF0) != 0) {
                stateTwoNormal=&frame.sixth.x;
                __asm__("" : "=r"(stateTwoNormal) : "0"(stateTwoNormal));
                Actor8007C2B4Helper4F178(stateTwoNormal,Actor8007C2B4D_80071918);
                Actor8007C2B4Helper4F178(ownerPosition, Actor8007C2B4D_80071918 - 0xC);
                Actor8007C2B4Field(owner, int *, 0x14) = (int) (Actor8007C2B4Field(owner, int *, 0x14) - 0xF0);
                if (Actor8007C2B4Field(tag, unsigned char *, 0x12) == 0) {
                    {register int height __asm__("$2")=Actor8007C2B4Helper1A358(workingPosition,0x400);
                     register void *first __asm__("$4")=stateTwoNormal;
                     register int zero __asm__("$5")=0;
                     register int magnitude __asm__("$5");
                     register int signedAngle __asm__("$2");
                     __asm__("" : "=r"(first),"=r"(zero) : "0"(first),"1"(zero) : "$16");
                     sampledHeight=height;
                     magnitude=Actor8007C2B4Helper4EDE8(first,zero);
                     signedAngle=Actor8007C2B4Helper4E880(frame.sixth.z,magnitude,0);
                     signedAngle<<=24;
                     __asm__("" : "=r"(signedAngle) : "0"(signedAngle));
                     signedAngleResult=signedAngle>>24;}
                    if (((frame.fifth.z - 0x190) < sampledHeight) && (signedAngleResult < 0x18)) {
                        Actor8007C2B4Field(owner, unsigned char *, 0x48) = 1U;
                        Actor8007C2B4Helper4F178(ownerPosition, workingPosition);
                        Actor8007C2B4Field(owner, int *, 0x14) = sampledHeight;
                        Actor8007C2B4Helper36188(tag + 0xE);
                        if (Actor8007C2B4Field(tag, int *, 0xC) & 0xFFFF0000) {
                            Actor8007C2B4Field(owner, unsigned char *, 0x46) = 0U;
                        }
                        Actor8007C2B4Field(owner, signed char *, 0x52) = 0;
                        Actor8007C2B4Helper56270(owner);
                        Actor8007C2B4Helper5629C(owner);
                    } else {
                        Actor8007C2B4Field(tag, unsigned char *, 0x12) = (unsigned char) (Actor8007C2B4Field(tag, unsigned char *, 0x12) + 1);
                    }
                    if (Actor8007C2B4Field(tag, unsigned char *, 0x12) != 0) {
                        goto block_52;
                    }
                } else {
block_52:
                    stateThreeDelta=&frame.seventh.x;
                    {register void *arg __asm__("$4")=stateThreeDelta;
                     __asm__("" : "=r"(arg):"0"(arg):"$19");
                     workingPosition=tag+4;
                     Actor8007C2B4Helper4F554(arg,workingPosition);}
                    {register int result __asm__("$2")=Actor8007C2B4Helper4EF74(&frame.seventh.x, &frame.sixth.x, &frame.seventh.x);
                     register void *arg __asm__("$4")=workingPosition;
                     if(result != 0) {
                        Actor8007C2B4Field(tag, unsigned char *, 0x12) = (unsigned char) (Actor8007C2B4Field(tag, unsigned char *, 0x12) - 1);
                        frame.seventh.x=(frame.seventh.x>>3)+(rand()&0x3F)-0x20;
                        frame.seventh.y=(frame.seventh.y>>3)+(rand()&0x3F)-0x20;
                        frame.seventh.z=(frame.seventh.z>>2)+(rand()&0xF);
                        Actor8007C2B4Helper3BABC(owner, 1, 0);
                    }
                    Actor8007C2B4Helper4F570(workingPosition,stateThreeDelta);
                }
            }
            } else {
                frame.fifth.z -= 0xF0;
                Actor8007C2B4Helper4F178(ownerPosition, workingPosition);
                Actor8007C2B4Helper1A358(workingPosition, 0x10000);
                Actor8007C2B4Helper5629C(owner);
            }
            __asm__ volatile("" ::: "memory");
            if (Actor8007C2B4Field(tag, short *, 0xA) >= 0x1E) {
                __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult) : "$5");
                temp_a0_2 = Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 0x44) + 0x80;
                if (({register int pred __asm__("$2")=distanceResult < temp_a0_2;__asm__("" : "=r"(pred):"0"(pred));pred;})) {
                    temp_v1_4 = Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 8) - Actor8007C2B4Field(owner, int *, 0x14);
                    if (temp_v1_4 < temp_a0_2) {
                        var_v0_2=-Actor8007C2B4Field(Actor8007C2B4D_80070328,int*,0x44);
                        __asm__ volatile("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$7");
                        var_v0_2=var_v0_2 < temp_v1_4;
                        __asm__ volatile("" : "=r"(var_v0_2):"0"(var_v0_2):"memory");
                        if(!var_v0_2) goto block_75;
                        goto block_70;
                    }
                }
            }
            goto block_75;
        case 3:                                     /* switch 1 */
            stateThreeVector=&frame.eighth.x;
            __asm__("" : "=r"(stateThreeVector) : "0"(stateThreeVector));
            Actor8007C2B4Helper4F554(stateThreeVector,tag+4);
            if (Actor8007C2B4Field(tag, short *, 0xA) >= 30) {
                Actor8007C2B4Helper4F178(owner + 0xC, Actor8007C2B4D_80070328);
            } else {
                stateThreeDelta=&frame.delta.x;
                __asm__("" : "=r"(stateThreeDelta) : "0"(stateThreeDelta) : "$20");
                {register void *first __asm__("$4")=stateThreeDelta;
                 __asm__("" : "=r"(first) : "0"(first) : "$20");
                 savedPlayer=Actor8007C2B4D_80070328;
                 Actor8007C2B4Helper4F1C8(first,savedPlayer,stateThreeVector);}
                Actor8007C2B4Helper4F228(stateThreeDelta, stateThreeDelta, 30);
                if (Actor8007C2B4Helper4EDE8(stateThreeDelta, 1) >= 0x1E1) {
                    Actor8007C2B4Helper4F178(owner+12,savedPlayer);
                    Actor8007C2B4Field(tag,short*,0xA)=30;
                } else {
                    Actor8007C2B4Helper4F1FC(stateThreeDelta, stateThreeDelta, Actor8007C2B4Field(tag, short *, 0xA));
                    Actor8007C2B4Helper4F194(owner + 0xC, stateThreeVector, stateThreeDelta);
                    Actor8007C2B4Field(owner, int *, 0x14) = (int) (Actor8007C2B4Field(owner, int *, 0x14) + (short)((short) *(unsigned short*)(Actor8007C2B4D_800658A0 + (Actor8007C2B4Field(tag, short *, 0xA) * 8)) / 10));
                }
            }
            {register int offset __asm__("$2")=Actor8007C2B4Field(tag,unsigned char*,0xE);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Actor8007C2B4Field(owner,unsigned char*,0x44);
              offset+=249;old+=offset;Actor8007C2B4Field(owner,unsigned char*,0x44)=old;}
            {register int offset __asm__("$2")=Actor8007C2B4Field(tag,unsigned char*,0xF);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Actor8007C2B4Field(owner,unsigned char*,0x45);
              offset+=249;old+=offset;Actor8007C2B4Field(owner,unsigned char*,0x45)=old;}
            {register int offset __asm__("$2")=Actor8007C2B4Field(tag,unsigned char*,0x10);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Actor8007C2B4Field(owner,unsigned char*,0x46);
              offset+=249;old+=offset;Actor8007C2B4Field(owner,unsigned char*,0x46)=old;}
            if ((Actor8007C2B4Field(tag, short *, 0xA) < 0x1E) || (temp_a0_3 = Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 0x44) + 0x80, ((({register int pred __asm__("$2")=distanceResult < temp_a0_3;__asm__("" : "=r"(pred):"0"(pred));pred;})) == 0)) || (temp_v1_5 = Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 8) - Actor8007C2B4Field(owner, int *, 0x14), ((temp_v1_5 < temp_a0_3) == 0)) || (-Actor8007C2B4Field(Actor8007C2B4D_80070328, int *, 0x44) >= temp_v1_5)) {
                var_v0_2 = Actor8007C2B4Field(tag, short *, 0xA) < 65;
                if(!var_v0_2) Actor8007C2B4Field(owner,unsigned char*,0x48)=4;
                goto block_75;
            }
            goto block_70;
block_70:
            Actor8007C2B4Field(owner,unsigned char*,0x48)=4;
            goto block_75;
        case 4:                                     /* switch 1 */
            Actor8007C2B4Helper55D24(owner, 4);
            Actor8007C2B4SpawnParticle(4,12,owner,Actor8007C2B4Field(owner,unsigned char*,0x49));
            Actor8007C2B4SpawnParticle(4,12,owner,Actor8007C2B4Field(owner,unsigned char*,0x49));
            Actor8007C2B4Helper36E60(owner);
            Actor8007C2B4Helper3BABC(owner, 0, 0);
            Actor8007C2B4Helper55B18(owner);
            goto block_75;
        }
block_75:
            if ((unsigned char) Actor8007C2B4Field(owner, unsigned char *, 0x48) < 3U) {

                {register int sample __asm__("$2")=*(unsigned short*)(Actor8007C2B4D_80065920+(Actor8007C2B4Field(tag,unsigned char*,0x10)*2));
                  register int base __asm__("$3");
                  __asm__("" : "=r"(sample) : "0"(sample) : "$3");
                  base=Actor8007C2B4Field(tag,unsigned char*,0xE);
                  __asm__("" : "=r"(sample),"=r"(base) : "0"(sample),"1"(base));
                  sample=(sample<<16)>>23;sample+=base;
                  Actor8007C2B4Field(owner,unsigned char*,0x44)=sample;}
                {register int sample __asm__("$2")=*(unsigned short*)(Actor8007C2B4D_800658A0+(Actor8007C2B4Field(tag,unsigned char*,0x10)*2));
                  register int base __asm__("$3");
                  __asm__("" : "=r"(sample) : "0"(sample) : "$3");
                  base=Actor8007C2B4Field(tag,unsigned char*,0xF);
                  __asm__("" : "=r"(sample),"=r"(base) : "0"(sample),"1"(base));
                  sample=(sample<<16)>>23;sample+=base;
                  Actor8007C2B4Field(owner,unsigned char*,0x45)=sample;}
                Actor8007C2B4Field(tag, unsigned char *, 0x10) = (unsigned char) (Actor8007C2B4Field(tag, unsigned char *, 0x10) + (Actor8007C2B4D_8006C648 * 2));
            }
    }
}
#undef Actor8007C2B4Field


/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level18 8007CC40 / level28 8007C200 / level48 8007C228.
 * Each original contains483 instructions plus20 owned switch/padding words.
 * Offset names describe observed storage; helper contracts, physical units,
 * actor meanings and caller cadence remain unresolved. Preserve pool stride88,
 * signed-halfword handle/selectors, byte stores, pointer rereads, distinct
 * switch paths and the signed quotient/subtract remainder chain. Compiler
 * constraints are empty and emit no CPU instructions. Linked original words,
 * all hashes and owned switch targets/padding are acceptance requirements.
 */
#define P7CC40Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int P7CC40func_80027A60() __asm__("func_80027A60");
int P7CC40func_80027AC0() __asm__("func_80027AC0");
int P7CC40func_80027E40() __asm__("func_80027E40");
int P7CC40func_8002803C() __asm__("func_8002803C");
int P7CC40func_80028154() __asm__("func_80028154");
int P7CC40func_80029904() __asm__("func_80029904");
int P7CC40func_80034F80() __asm__("func_80034F80");
int P7CC40func_800359A4() __asm__("func_800359A4");
int P7CC40func_80037168() __asm__("func_80037168");
int P7CC40func_8003BE70() __asm__("func_8003BE70");
int P7CC40func_8003BFC0() __asm__("func_8003BFC0");
int P7CC40func_8004F334() __asm__("func_8004F334");
int P7CC40func_80055B18() __asm__("func_80055B18");
extern unsigned int P7CC40D_8006C550 __asm__("D_8006C550");
extern unsigned int P7CC40D_8006C704 __asm__("D_8006C704");
extern int P7CC40D_8006C640 __asm__("D_8006C640");
extern int P7CC40D_8006C770 __asm__("D_8006C770");
extern unsigned char P7CC40D_8006EE2C[] __asm__("D_8006EE2C");
extern unsigned char P7CC40D_80070328[] __asm__("D_80070328");
extern void *P7CC40unk_ovlheader_800743B8 __asm__("unk_ovlheader_800743B8");
extern void *P7CC40unk_ovlheader_800743BC __asm__("unk_ovlheader_800743BC");
extern void *P7CC40unk_ovlheader_800743C0 __asm__("unk_ovlheader_800743C0");
extern void *(*P7CC40SpawnParticle)() __asm__("SpawnParticle");
void func_level_18_8007CC40(void *owner) {
    register void *helperCallback7 __asm__("$7");
    register int helperSelector5 __asm__("$5");
    register int helperKind4 __asm__("$4");
    register void *helperProducer6 __asm__("$6");
    register void *tablePointer2 __asm__("$2");
    register unsigned int tableByte2 __asm__("$2");
    register int particleArgument7 __asm__("$7");
    register int particleKind4 __asm__("$4");
    register int particleSelector5 __asm__("$5");
    register void *particleOwner6 __asm__("$6");
    register void *(*particleCallback2)() __asm__("$2");
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_5;
    int temp_a0_6;
    int temp_a0_7;
    short colorCaseHalfword;
    short particleCaseHalfword;
    short temp_v1;
    int temp_a0;
    register int tickRemainder4 __asm__("$4");
    int temp_v0_2;
    register int quotient3 __asm__("$3");
    int var_v0;
    int var_v1_2;
    register int colorWord2 __asm__("$2");
    register int colorWord3 __asm__("$3");
    register int case3Result2 __asm__("$2");
    register int case3Halfword3 __asm__("$3");
    register int payloadWord2 __asm__("$2");
    register void *payloadHeader3 __asm__("$3");
    register int payloadLimit8 __asm__("$8");
    register unsigned int poolCursor3 __asm__("$3");
    register unsigned int poolEnd4 __asm__("$4");
    register int poolType5 __asm__("$5");
    unsigned char ownerStateByte48;
    void *linkedPrivate;
    void *privateState;
    void *temp_v0;
    void *privateWord44Address;

    privateState = P7CC40Field(owner, void **, 0);
    if (P7CC40Field(P7CC40D_80070328, int *, 0x250) != 0) {
        if (P7CC40Field(owner, unsigned char *, 0x48) == 2) {
            P7CC40Field(owner, unsigned char *, 0x41) = 0;
            P7CC40Field(owner, unsigned char *, 0x4C) = 0;
            P7CC40Field(owner, unsigned char *, 0x4D) = 0;
            temp_v0 = P7CC40Field(privateState, void **, 0x4C);
            if (temp_v0 != 0) {
                P7CC40Field(temp_v0, unsigned char *, 0x41) = 0;
                P7CC40Field(P7CC40Field(privateState, void **, 0x4C), unsigned char *, 0x4C) = 0;
                P7CC40Field(P7CC40Field(privateState, void **, 0x4C), unsigned char *, 0x4D) = 0;
            }
            temp_a0 = P7CC40Field(privateState, int *, 0x50);
            if (temp_a0 != 0) {
                P7CC40func_80055B18(temp_a0);
                P7CC40Field(privateState, int *, 0x50) = 0;
            }
            goto exitFunction;
foundPool:
            P7CC40Field(privateState, unsigned int *, 0x48) = poolCursor3;
            goto poolReady;
        } else {
            privateWord44Address = privateState + 0x44;
            if (P7CC40Field(privateState, short *, 0xE) == 0) {
                P7CC40Field(privateState, short *, 0xE) = 1;
                if (P7CC40Field(owner, unsigned char *, 0x3C) != 0) {
                    tablePointer2 = *(void **)(P7CC40D_8006EE2C + P7CC40Field(owner, short *, 0x36) * 4);
                    tablePointer2 = P7CC40Field(tablePointer2, void **, 0x3C);
                    __asm__("" : "=r"(tablePointer2) : "0"(tablePointer2));
                    P7CC40D_8006C770 = 0;
                    tableByte2 = *(unsigned char *)tablePointer2;
                    __asm__("" : "=r"(tableByte2) : "0"(tableByte2));
                    P7CC40Field(owner, unsigned char *, 0x3C) = 0;
                    P7CC40Field(owner, unsigned char *, 0x3D) = 0;
                    P7CC40Field(owner, unsigned char *, 0x3E) = 0;
                    P7CC40Field(owner, unsigned char *, 0x3F) = 1;
                    __asm__("" : "=r"(tableByte2) : "0"(tableByte2) : "memory");
                    tableByte2 = tableByte2 < 2U;
                    __asm__("" : "=r"(tableByte2) : "0"(tableByte2));
                    tableByte2 ^= 1;
                    tableByte2 = -tableByte2;
                    tableByte2 &= 0x30;
                    P7CC40Field(owner, unsigned char *, 0x40) = tableByte2;
                }
                poolCursor3 = P7CC40D_8006C550;
                poolEnd4 = P7CC40D_8006C704;
                poolType5 = 0x170;
                if (poolCursor3 < poolEnd4) {
scanPool:
                    if (P7CC40Field(poolCursor3, short *, 0x36) != poolType5) {
                        poolCursor3 += 0x58;
                        if (poolCursor3 < poolEnd4) {
                            goto scanPool;
                        }
                    } else {
                        goto foundPool;
                    }
                }
poolReady:
                privateWord44Address = privateState + 0x44;
            }
            linkedPrivate = *P7CC40Field(privateState, void ***, 0x48);
            if (P7CC40func_800359A4(privateWord44Address, 4) == 2) {
                temp_v1 = P7CC40Field(privateState, short *, 0xC);
                switch (temp_v1) {
                case 0:
                    temp_v0_2 = P7CC40Field(linkedPrivate, int *, 0x28) + 2;
                    P7CC40Field(linkedPrivate, int *, 0x28) = temp_v0_2;
                    if (temp_v0_2 >= 7) {
                        P7CC40Field(linkedPrivate, int *, 0x28) = 6;
                    default:
                    }
                    break;
                case 1:
                    temp_a0_2 = P7CC40Field(linkedPrivate, short *, 0x36);
                    P7CC40Field(linkedPrivate, int *, 0x1C) = (int) (P7CC40Field(linkedPrivate, int *, 0x1C) & ~0x1E);
                    if (temp_a0_2 != -1) {
                        P7CC40func_80028154(temp_a0_2);
                    }
                    helperKind4 = 0x12;
                    helperSelector5 = 0xB7;
                    helperProducer6 = (void *)&P7CC40func_80027E40;
                    helperCallback7 = &P7CC40func_80027A60;
                    __asm__("" : "=r"(helperKind4), "=r"(helperSelector5), "=r"(helperProducer6), "=r"(helperCallback7) : "0"(helperKind4), "1"(helperSelector5), "2"(helperProducer6), "3"(helperCallback7));
                    var_v1_2 = 9;
                    P7CC40Field(linkedPrivate, int *, 0x20) = 9;
                    var_v0 = P7CC40Field(linkedPrivate, int *, 0x1C) | 8;
                    goto createWord20Handle;
                case 2:
                    temp_a0_3 = P7CC40Field(linkedPrivate, short *, 0x34);
                    P7CC40Field(linkedPrivate, int *, 0x1C) = (int) (P7CC40Field(linkedPrivate, int *, 0x1C) & ~0x21);
                    if (temp_a0_3 != -1) {
                        P7CC40func_80028154(temp_a0_3);
                    }
                    helperKind4 = 0x14;
                    helperSelector5 = 0xB6;
                    helperProducer6 = P7CC40unk_ovlheader_800743B8;
                    helperCallback7 = P7CC40unk_ovlheader_800743C0;
                    __asm__("" : "=r"(helperKind4), "=r"(helperSelector5), "=r"(helperProducer6), "=r"(helperCallback7) : "0"(helperKind4), "1"(helperSelector5), "2"(helperProducer6), "3"(helperCallback7));
                    payloadWord2 = P7CC40Field(linkedPrivate, int *, 0x1C);
                    payloadHeader3 = P7CC40unk_ovlheader_800743BC;
                    payloadLimit8 = 0x5DC;
                    P7CC40Field(linkedPrivate, int *, 0x24) = payloadLimit8;
                    payloadWord2 |= 1;
                    P7CC40Field(linkedPrivate, int *, 0x1C) = payloadWord2;
                    P7CC40Field(linkedPrivate, short *, 0x34) = P7CC40func_8002803C(helperKind4, helperSelector5, helperProducer6, helperCallback7, payloadHeader3, linkedPrivate + 0x24, payloadLimit8);
                    if (P7CC40func_8003BFC0((void **) P7CC40Field(privateState, unsigned int *, 0x48), P7CC40Field(linkedPrivate, int *, 0x48)) != 0) {
                        if (P7CC40func_8003BFC0((void **) P7CC40Field(privateState, unsigned int *, 0x48), P7CC40Field(linkedPrivate, int *, 0x48)) != 0) {
                            P7CC40func_8003BE70(P7CC40Field(linkedPrivate, int *, 0x48));
                        }
                        P7CC40Field(linkedPrivate, int *, 0x48) = -1;
                    }
                    break;
                case 3:
                    temp_a0_4 = P7CC40Field(linkedPrivate, short *, 0x36);
                    P7CC40Field(linkedPrivate, int *, 0x1C) = (int) (P7CC40Field(linkedPrivate, int *, 0x1C) & ~0x1E);
                    if (temp_a0_4 != -1) {
                        P7CC40func_80028154(temp_a0_4);
                    }
                    helperKind4 = 0x12;
                    helperSelector5 = 0xB8;
                    helperProducer6 = (void *)&P7CC40func_80027E40;
                    helperCallback7 = &P7CC40func_80027A60;
                    __asm__("" : "=r"(helperKind4), "=r"(helperSelector5), "=r"(helperProducer6), "=r"(helperCallback7) : "0"(helperKind4), "1"(helperSelector5), "2"(helperProducer6), "3"(helperCallback7));
                    var_v1_2 = 9;
                    P7CC40Field(linkedPrivate, int *, 0x20) = 9;
                    var_v0 = P7CC40Field(linkedPrivate, int *, 0x1C) | 4;
                    goto createWord20Handle;
                case 4:
                    temp_a0_5 = P7CC40Field(linkedPrivate, short *, 0x36);
                    P7CC40Field(linkedPrivate, int *, 0x1C) = (int) (P7CC40Field(linkedPrivate, int *, 0x1C) & ~0x1E);
                    if (temp_a0_5 != -1) {
                        P7CC40func_80028154(temp_a0_5);
                    }
                    helperKind4 = 0x12;
                    helperSelector5 = 0xB5;
                    helperProducer6 = (void *)&P7CC40func_80027E40;
                    helperCallback7 = &P7CC40func_80027AC0;
                    __asm__("" : "=r"(helperKind4), "=r"(helperSelector5), "=r"(helperProducer6), "=r"(helperCallback7) : "0"(helperKind4), "1"(helperSelector5), "2"(helperProducer6), "3"(helperCallback7));
                    var_v1_2 = 0x12C;
                    P7CC40Field(linkedPrivate, int *, 0x20) = 0x12C;
                    var_v0 = P7CC40Field(linkedPrivate, int *, 0x1C) | 2;
                    goto createWord20Handle;
                case 5:
                    temp_a0_6 = P7CC40Field(linkedPrivate, short *, 0x36);
                    P7CC40Field(linkedPrivate, int *, 0x1C) = (int) (P7CC40Field(linkedPrivate, int *, 0x1C) & ~0x1E);
                    if (temp_a0_6 != -1) {
                        P7CC40func_80028154(temp_a0_6);
                    }
                    helperKind4 = 0x12;
                    helperSelector5 = 0xB9;
                    helperProducer6 = (void *)&P7CC40func_80027E40;
                    helperCallback7 = &P7CC40func_80027A60;
                    __asm__("" : "=r"(helperKind4), "=r"(helperSelector5), "=r"(helperProducer6), "=r"(helperCallback7) : "0"(helperKind4), "1"(helperSelector5), "2"(helperProducer6), "3"(helperCallback7));
                    var_v1_2 = 9;
                    P7CC40Field(linkedPrivate, int *, 0x20) = 9;
                    var_v0 = P7CC40Field(linkedPrivate, int *, 0x1C) | 0x10;
createWord20Handle:
                    P7CC40Field(linkedPrivate, int *, 0x1C) = var_v0;
                    P7CC40Field(linkedPrivate, short *, 0x36) = P7CC40func_8002803C(helperKind4, helperSelector5, helperProducer6, helperCallback7, &P7CC40func_80029904, linkedPrivate + 0x20, var_v1_2);
                    break;
                case 6:
                    temp_a0_7 = P7CC40Field(linkedPrivate, short *, 0x34);
                    P7CC40Field(linkedPrivate, int *, 0x1C) = (int) (P7CC40Field(linkedPrivate, int *, 0x1C) & ~0x21);
                    if (temp_a0_7 != -1) {
                        P7CC40func_80028154(temp_a0_7);
                    }
                    helperKind4 = 0x14;
                    helperSelector5 = 0xB6;
                    helperProducer6 = P7CC40unk_ovlheader_800743B8;
                    helperCallback7 = P7CC40unk_ovlheader_800743C0;
                    __asm__("" : "=r"(helperKind4), "=r"(helperSelector5), "=r"(helperProducer6), "=r"(helperCallback7) : "0"(helperKind4), "1"(helperSelector5), "2"(helperProducer6), "3"(helperCallback7));
                    payloadWord2 = P7CC40Field(linkedPrivate, int *, 0x1C);
                    payloadHeader3 = P7CC40unk_ovlheader_800743BC;
                    payloadLimit8 = 0x5DC;
                    P7CC40Field(linkedPrivate, int *, 0x24) = payloadLimit8;
                    payloadWord2 |= 0x20;
                    P7CC40Field(linkedPrivate, int *, 0x1C) = payloadWord2;
                    P7CC40Field(linkedPrivate, short *, 0x34) = P7CC40func_8002803C(helperKind4, helperSelector5, helperProducer6, helperCallback7, payloadHeader3, linkedPrivate + 0x24, payloadLimit8);
                    break;
                }
                P7CC40Field(owner, unsigned char *, 0x48) = 2U;
                return;
            }
            if ((P7CC40func_8004F334(owner + 0xC, P7CC40D_80070328) < 0x3E8) && (P7CC40Field(privateState, int *, 0x44) == 0)) {
                P7CC40Field(privateState, int *, 0x44) = 0xA;
                P7CC40Field(linkedPrivate, void **, 8) = owner;
            }
            if (P7CC40Field(privateState, short *, 0xC) == 6) {
                tickRemainder4 = P7CC40D_8006C640;
                quotient3 = tickRemainder4 / 15;
                tickRemainder4 -= quotient3 * 15;
                if (tickRemainder4 == 0) {
                    P7CC40Field(owner, unsigned char *, 0x4C) = 0;
                    P7CC40Field(owner, unsigned char *, 0x4D) = 0;
                } else if (tickRemainder4 == 0xC) {
                    P7CC40Field(owner, unsigned char *, 0x4C) = 0x20;
                    P7CC40Field(owner, unsigned char *, 0x4D) = 1;
                }
            }
            ownerStateByte48 = P7CC40Field(owner, unsigned char *, 0x48);
            switch (ownerStateByte48) {
            case 0:
                if (P7CC40Field(privateState, short *, 0xC) != 0) {
                    P7CC40func_80034F80(owner, 1);
                    colorCaseHalfword = (unsigned short) P7CC40Field(privateState, short *, 0xC) - 1;
                    switch (colorCaseHalfword) {
                    case 0:
                        P7CC40Field(owner, unsigned char *, 0x54) = 0xDF;
                        colorWord2 = 0x40;
                        goto storeByte55;
                    case 2:
                        colorWord2 = 0xDF;
                        colorWord3 = 0x40;
                        P7CC40Field(owner, unsigned char *, 0x54) = colorWord2;
                        P7CC40Field(owner, unsigned char *, 0x56) = colorWord2;
                        colorWord2 = 0x3A;
                        P7CC40Field(owner, unsigned char *, 0x55) = colorWord3;
                        __asm__("" : : "r"(colorWord2), "r"(colorWord3));
                        goto storeByte57;
                    case 3:
                        colorWord2 = 0x40;
                        colorWord3 = 0xDF;
                        P7CC40Field(owner, unsigned char *, 0x54) = colorWord2;
                        P7CC40Field(owner, unsigned char *, 0x56) = colorWord2;
                        colorWord2 = 0x3A;
                        P7CC40Field(owner, unsigned char *, 0x55) = colorWord3;
                        goto storeByte57;
                    case 4:
                        colorWord2 = 0x40;
                        P7CC40Field(owner, unsigned char *, 0x54) = colorWord2;
                        P7CC40Field(owner, unsigned char *, 0x55) = colorWord2;
                        colorWord2 = 0xDF;
                        goto storeByte56;
                    case 1:
                    case 5:
                        colorWord2 = 0x80;
                        P7CC40Field(owner, unsigned char *, 0x54) = colorWord2;
storeByte55:
                        P7CC40Field(owner, unsigned char *, 0x55) = colorWord2;
storeByte56:
                        P7CC40Field(owner, unsigned char *, 0x56) = colorWord2;
                        colorWord2 = 0x3A;
storeByte57:
                        P7CC40Field(owner, unsigned char *, 0x57) = colorWord2;
                        break;
                    }

                }
                goto storeOwnerState1;
            case 1:
                if ((P7CC40Field(privateState, int *, 0x1C) != 0) && (P7CC40func_8004F334(owner + 0xC, P7CC40D_80070328) < P7CC40Field(privateState, short *, 0x40))) {
                    P7CC40Field(owner, unsigned char *, 0x48) = 3U;
                }
                if (P7CC40Field(privateState, int *, 0x18) == 0) {
                    P7CC40func_80037168(owner, privateState + 0x28, 0x4001);
                }
                break;
            case 3:
                case3Result2 = P7CC40func_8004F334(owner + 0xC, P7CC40D_80070328);
                case3Halfword3 = P7CC40Field(privateState, short *, 0x42);
                __asm__("" : "=r"(case3Halfword3) : "0"(case3Halfword3));
                case3Halfword3 = case3Halfword3 < case3Result2;
                __asm__("" : "=r"(case3Halfword3) : "0"(case3Halfword3));
                if (case3Halfword3 == 0) break;
storeOwnerState1:
                P7CC40Field(owner, unsigned char *, 0x48) = 1;
                break;
            }
            particleCaseHalfword = (unsigned short) P7CC40Field(privateState, short *, 0xC) - 1;
            switch (particleCaseHalfword) {
            case 0:
                particleKind4 = 3;
                particleSelector5 = 0xC;
                particleOwner6 = owner;
                particleCallback2 = P7CC40SpawnParticle;
                __asm__("" : "=r"(particleKind4), "=r"(particleSelector5), "=r"(particleOwner6), "=r"(particleCallback2) : "0"(particleKind4), "1"(particleSelector5), "2"(particleOwner6), "3"(particleCallback2));
                particleArgument7 = 4;
                goto callParticleCallback;
            case 2:
                particleKind4 = 3;
                particleSelector5 = 0xC;
                particleOwner6 = owner;
                particleCallback2 = P7CC40SpawnParticle;
                __asm__("" : "=r"(particleKind4), "=r"(particleSelector5), "=r"(particleOwner6), "=r"(particleCallback2) : "0"(particleKind4), "1"(particleSelector5), "2"(particleOwner6), "3"(particleCallback2));
                particleArgument7 = 4;
                goto callParticleCallback;
            case 3:
                particleKind4 = 3;
                particleSelector5 = 0xC;
                particleOwner6 = owner;
                particleCallback2 = P7CC40SpawnParticle;
                __asm__("" : "=r"(particleKind4), "=r"(particleSelector5), "=r"(particleOwner6), "=r"(particleCallback2) : "0"(particleKind4), "1"(particleSelector5), "2"(particleOwner6), "3"(particleCallback2));
                particleArgument7 = 1;
                goto callParticleCallback;
            case 4:
                particleKind4 = 3;
                particleSelector5 = 0xC;
                particleOwner6 = owner;
                particleCallback2 = P7CC40SpawnParticle;
                __asm__("" : "=r"(particleKind4), "=r"(particleSelector5), "=r"(particleOwner6), "=r"(particleCallback2) : "0"(particleKind4), "1"(particleSelector5), "2"(particleOwner6), "3"(particleCallback2));
                particleArgument7 = 0;
                goto callParticleCallback;
            case 1:
            case 5:
                particleKind4 = 3;
                particleSelector5 = 0xC;
                particleOwner6 = owner;
                particleCallback2 = P7CC40SpawnParticle;
                __asm__("" : "=r"(particleKind4), "=r"(particleSelector5), "=r"(particleOwner6), "=r"(particleCallback2) : "0"(particleKind4), "1"(particleSelector5), "2"(particleOwner6), "3"(particleCallback2));
                particleArgument7 = 3;
callParticleCallback:
                particleCallback2(particleKind4, particleSelector5, particleOwner6, particleArgument7);
                break;
            }
        }
    }
exitFunction:
    return;
}

#undef P7CC40Field


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007EB68,503 instructions, sibling4584. Verified28 spawn/particle C
 * reused; all raw fields, branches and constants from original18.
 * Units, helper contracts and cadence unresolved; uninstalled until exact. */
#define G18Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int G18func_80018368(void*,void*) __asm__("func_80018368");

int G18func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");

int G18func_800359A4(void*,int) __asm__("func_800359A4");

int G18func_8003BABC(void*,int,int) __asm__("func_8003BABC");

int G18func_8004E880(int,int,int) __asm__("func_8004E880");

int G18func_8004EA90(void*,void*,int) __asm__("func_8004EA90");

int G18func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");

int G18func_8004F0E8(void*,int) __asm__("func_8004F0E8");

int G18func_8004F110(void*,int) __asm__("func_8004F110");

int G18func_8004F178(void*,void*) __asm__("func_8004F178");

int G18func_8004F194(void*,void*,void*) __asm__("func_8004F194");

int G18func_80055B18(void*) __asm__("func_80055B18");

int G18rand(void) __asm__("rand");

extern short G18D_800658A0[] __asm__("D_800658A0");

extern short G18D_80065920[] __asm__("D_80065920");

extern int G18D_8006C574 __asm__("D_8006C574");

extern int G18D_8006C578 __asm__("D_8006C578");

extern int G18D_8006C640 __asm__("D_8006C640");

extern int G18D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char G18D_8006E020[] __asm__("D_8006E020");

extern void *(*G18SpawnMoby)(int,void*) __asm__("SpawnMoby");

extern int (*G18SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");

extern unsigned char G18D_80070328[] __asm__("D_80070328");
int G18func_8004F334(void*,void*) __asm__("func_8004F334");

int G18H19194() __asm__("func_80019194");
int G18H4EF74() __asm__("func_8004EF74");
int G18H3636C() __asm__("func_8003636C");
extern int G18Delta __asm__("D_8006C648");
extern int G18Reflect[] __asm__("D_80071918");


const int G18Initial[4] __asm__("D_level_18_800746E0")={65,55,45,0};
extern unsigned char* G18Pool __asm__("D_8006C550");
extern unsigned short** G18Lists __asm__("D_8006C730");
extern int G18Mode __asm__("D_8006C7C4");
extern int G18Gate __asm__("D_8006C770");
int G18H55D24() __asm__("func_80055D24");
int G18H34F40() __asm__("func_80034F40");
int G18H36A68() __asm__("func_80036A68");
int G18H3BA00() __asm__("func_8003BA00");
int G18H369B8() __asm__("func_800369B8");
int G18H55C24() __asm__("func_80055C24");
int G18H34F80() __asm__("func_80034F80");
int G18H35D38() __asm__("func_80035D38");
int G18H5629C() __asm__("func_8005629C");
extern int (*G18Notify)() __asm__("unk_ovlheader_800743E0");
extern unsigned char* G18Classes[] __asm__("D_8006EE2C");
int G18H3BFC0() __asm__("func_8003BFC0");
int G18H3BE70() __asm__("func_8003BE70");
void func_level_18_8007D3CC(void* input){
 struct {int first[4],second[4],third[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$18")=input;
 register unsigned char* state __asm__("$21");
 register int selectedAngle __asm__("$16");
 register unsigned char* nested16 __asm__("$16");
 register int minus17 __asm__("$17");
 register unsigned char* linked17 __asm__("$17");
 register int one17 __asm__("$17");
 register unsigned char* selected16 __asm__("$16");
 register void* spawned21D __asm__("$17");
 register int spawnIndex __asm__("$20");
 register int spawnOffset __asm__("$19");
 register unsigned char* player21 __asm__("$22");
 register int matrixParticleIndex __asm__("$19");
 register void* matrix21 __asm__("$20");
 register int* vector17 __asm__("$17");
 register int* vector16 __asm__("$16");
 register int work2 __asm__("$2");register int work3 __asm__("$3");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 void* spawned146;void* spawned1E2;unsigned char* linked;
 register short* list __asm__("$5");
 register unsigned char* selected4 __asm__("$4");
 register unsigned char* pool7 __asm__("$7");register int mode6 __asm__("$6");int kind;
 __asm__("" : "=r"(owner):"0"(owner));
 state=G18Field(owner,unsigned char**,0);
 __asm__("" : "=r"(state):"0"(state):"$2","$3","$4","$5");
 {register int* initial5 __asm__("$5")=G18Initial;
 __asm__("" : "=r"(initial5):"0"(initial5));
 {register int first2 __asm__("$2")=initial5[0];register int second3 __asm__("$3")=initial5[1];register int third4 __asm__("$4")=initial5[2];
 __asm__("" : "=r"(first2),"=r"(second3),"=r"(third4):"0"(first2),"1"(second3),"2"(third4));
 frame.first[0]=first2;frame.first[1]=second3;frame.first[2]=third4;}}
 work3=G18Field(state,int*,8);
 if(work3!=-1 && G18Field(owner,int*,24))G18Notify(owner[0x43],1);
 work3=G18Field(state,int*,16);minus17=-1;
 if(work3!=minus17){
  linked=G18Pool+work3*88;work2=G18Field(linked,int*,0);
  __asm__("" : "=r"(work2):"0"(work2));
  if(G18Field((void*)work2,int*,0)){
   G18Field(owner,int*,24)=0;
   if(!G18Field(state,int*,20))G18Field(state,int*,20)=(int)G18SpawnMoby(577,owner);
  }else{
   call4=G18Field(state,void**,20);
   if(call4){
    nested16=G18Field(call4,unsigned char**,0);
    if(G18H3BFC0(call4,G18Field(nested16,int*,4))){
     if(G18H3BFC0(G18Field(state,void**,20),G18Field(nested16,int*,4)))G18H3BE70(G18Field(nested16,int*,4));
     G18Field(nested16,int*,4)=minus17;
    }
    G18func_80055B18(G18Field(state,void**,20));G18Field(state,int*,20)=0;
   }
  }
 }
 if(G18Field(owner,int*,24) && (unsigned int)(owner[0x48]-2)>=2){
  work2=G18Field(state,int*,12)-1;G18Field(state,int*,12)=work2;
  if(work2<=0 || (G18Field(owner,int*,24)&0x180000)){
   owner[0x48]=2;call4=owner;call5=1;
   goto emit;
  }
  call4=owner;call5=0;
  emit:__asm__ volatile("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
  G18func_8003BABC(call4,call5,0);
  owner[0x54]=255;owner[0x55]=255;owner[0x56]=255;owner[0x57]=63;
 }else{owner[0x54]=0;owner[0x55]=0;owner[0x56]=0;owner[0x57]=0;}
 switch(owner[0x48]){
 case 0:goto selection;
 case 1:goto timer;
 case 2:goto spawn;
 case 3:goto particles;
 default:{G18Field(owner,int*,24)=0;goto done;}
 }
 selection:
 work2=G18func_800359A4(state,4);one17=1;
 if(!work2)goto clear;
 work2=G18Field(state,int*,8);
 {register unsigned short** table3 __asm__("$3")=G18Lists;
 __asm__("" : "=r"(work2),"=r"(table3):"0"(work2),"1"(table3));list=(short*)table3[work2];}
 do{
  work3=G18Field(list,unsigned short*,0)&32767;work2=work3*11;
  __asm__("" : "=r"(work2),"=r"(work3):"0"(work2),"1"(work3));
  work3=(int)G18Pool;__asm__("" : "=r"(work3):"0"(work3));
  selected4=(unsigned char*)((work2<<3)+work3);
  __asm__("" : "=r"(selected4):"0"(selected4));
  if((selected4[0x48]&128) && ((selected4[0x53]>>G18Mode)&1)){
   selected16=selected4;
   work2=G18Field(selected16,short*,54);call4=G18Field(selected16,void**,0);
   if(work2==374){
    work3=G18Field(call4,unsigned short*,24);
    if(!(work3&128)){work2=work3|128;__asm__("" : "=r"(work2):"0"(work2));G18Field(call4,short*,24)=work2;}
   }
   G18H55C24(selected16);G18func_8004F178(selected16+12,owner+12);
   work2=G18Field(selected16,short*,54);
   G18Field(selected16,int*,24)=0;selected16[0x51]=0;selected16[0x48]=0;selected16[0x42]=0;
   work2=G18Field(G18Classes[work2],int*,60);work2=G18Field((void*)work2,unsigned char*,0);
   selected16[0x3C]=0;selected16[0x3D]=0;selected16[0x3E]=0;selected16[0x3F]=one17;
   selected16[0x44]=0;selected16[0x45]=0;
   work2=(unsigned int)work2<2;__asm__("" : "=r"(work2):"0"(work2));
   work2^=1;work2=-work2;work2&=48;selected16[0x40]=work2;
   selected16[0x46]=owner[0x46];G18H35D38(selected16);G18H5629C(selected16);
   {struct poolActor {unsigned char bytes[88];};
    call4=G18Pool;__asm__("" : "=r"(call4):"0"(call4));
    selected16[0x3A]=(struct poolActor*)owner-(struct poolActor*)call4;}
   work2=G18Mode;call5=1;work2=frame.first[work2];
   __asm__("" : "=r"(work2),"=r"(call5):"0"(work2),"1"(call5):"$4");
   call4=owner;G18Field(state,int*,0)=work2;owner[0x48]=one17;G18H34F40(call4,call5);
   G18Field(owner,int*,24)=0;goto done;
  }
  work2=*list;list++;
 }while(work2>=0);
 __asm__ volatile("" ::: "memory");G18Field(owner,volatile int*,24)=0;goto done;
 timer:
 if(G18Gate && G18Field(owner,unsigned short*,60)==257)G18H34F40(owner,0);
 if(!G18func_800359A4(state,4))goto clear;
 work2=G18Field(state,int*,4);if(!work2)work2=15;
 G18Field(state,int*,0)=work2;owner[0x48]=0;
 __asm__ volatile("" ::: "memory","$4","$5");
 G18H34F40(owner,0);goto clear;
 spawn:
 if (((G18D_8006C578 - G18D_8006C574) >= 0x15) && (G18D_8006C7E8 >= 0x7531)) {
                    spawned146 = G18SpawnMoby(0x146, owner);

                    if (spawned146 != 0) {
                        G18Field(spawned146, signed char *, 0x47) = 7;

                    }
                }
                spawnIndex = 0;

                if ((G18D_8006C578 - G18D_8006C574) >= 0x15) {
                    player21=G18D_8006E020;

                    __asm__("" : "=r"(player21) : "0"(player21));

                    spawnOffset = 0;

                    loop_32:
                    if (G18D_8006C7E8 >= 0x7531) {
                        spawned21D = G18SpawnMoby(0x21D, owner);

                        if (spawned21D != 0) {
                            selectedAngle = G18func_8004E880(G18Field(owner, int *, 0xC) - G18Field(player21, int *, 0), G18Field(owner, int *, 0x10) - G18Field(player21, int *, 4), 0);

                            work2=G18rand();
                            selectedAngle+=64;

                            __asm__("" : "=r"(work2),"=r"(selectedAngle) : "0"(work2),"1"(selectedAngle));

                            work2&=31;
                            selectedAngle+=work2;
                            G18Field(spawned21D,signed char*,0x46)=selectedAngle;

                            G18Field(spawned21D, signed char *, 0x45) = (signed char) ((spawnOffset + (G18rand() & 0x1E)) - 0xF);

                            G18Field(spawned21D, signed char *, 0x47) = 8;

                            G18Field(spawned21D, signed char *, 0x4C) = 0x2A;

                        }
                        spawnIndex += 1;

                        spawnOffset += 0x33;

                        if ((spawnIndex < 5) && ((G18D_8006C578 - G18D_8006C574) >= 0x15)) {
                            goto loop_32;

                        }
                    }
                }

 __asm__("" ::: "$2");
 owner[0x41]=0;owner[0x4C]=0;owner[0x4D]=0;G18Field(state,int*,0)=20;owner[0x48]=3;

  particles:
 if(G18Field(state,int*,0)>=6){
  __asm__ volatile("" : "=r"(call4));
  matrixParticleIndex=0;matrix21=frame.matrix;vector17=frame.second;vector16=frame.third;
  do {
                    frame.angles[0] = 0;

                    frame.angles[1] = G18rand();

                    frame.angles[2] = G18rand();

                    G18func_8004EA90(&frame.angles[0], matrix21, 0);

                    matrixParticleIndex++;work2=G18rand();

                    /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)vector17;
                    call6=vector17;

                    __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2) : "memory");

                    work2&=31;
                    work2+=48;
                    frame.second[0]=work2;

                    frame.second[1] = 0;

                    frame.second[2] = 0;

                    G18func_8004ED6C(call4,(void*)call5,call6);

                    G18func_8004F178(vector16, vector17);

                    G18func_8004F0E8(vector16, 2);

                    __asm__("" : "=r"(owner) : "0"(owner));

                    G18func_8004F194(vector16, vector16, owner + 0xC);

                    call4=(void*)1;
                    call5=13;
                    call6=vector16;


                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));



                    G18SpawnParticle((int)call4,call5,call6,vector17);
                    __asm__("" : "=r"(owner):"0"(owner):"$22");

                } while (matrixParticleIndex < 4);



 call4=(void*)6;call5=70;call6=owner+12;
 __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
 G18SpawnParticle((int)call4,call5,call6,(void*)16);
 }
 if(!(G18D_8006C640&1) && G18D_8006C578-G18D_8006C574>=21 && G18D_8006C7E8>=30001){
  spawned1E2=G18SpawnMoby(482,owner);
  if(spawned1E2){G18Field(spawned1E2,unsigned char*,76)=42;G18Field(spawned1E2,unsigned char*,71)=10;}
 }
 if(!G18func_800359A4(state,4))goto clear;
 G18H36A68(owner,1,0,0);G18H55D24(owner,4);G18H3BA00(owner);G18H369B8(owner,48);G18func_80055B18(owner);goto done;
 clear:
 G18Field(owner,int*,24)=0;
 done:__asm__ volatile("" ::: "memory");
}
#undef G18Field


/* Original private record: two word actor indices and a child pointer. */
typedef struct {
    int gateIndex, sourceIndex;
    Moby* child;
} DecodedIndexedSpawnTag;
extern Moby* D_8006C550;
extern int D_8006E344, D_8006C5BC;
extern int DecodedIndexedPlayer44 __asm__("D_80070328 + 0x44");
extern int DecodedIndexedPlayer280 __asm__("D_80070328 + 0x280");
extern Vector3D DecodedIndexedPlayer __asm__("D_80070328");
extern short DecodedIndexedCos[] __asm__("D_80065920");
extern short DecodedIndexedSin[] __asm__("D_800658A0");
int func_8004F334(Vector3D*, Vector3D*);
void func_800584BC(int, int);
void func_level_18_8007DBA8(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    register DecodedIndexedSpawnTag* tag __asm__("$18") = moby->mobyTag;
    register Moby* child __asm__("$17");
    register unsigned char* stateAddress __asm__("$16");
    Vector3D offset;
    register Vector3D* work __asm__("$4");
    short* childPrivate;
    register int childYaw __asm__("$2");
    int sine, vertical;
    register Vector3D* copiedWork __asm__("$5");
    register Vector3D* childPosition __asm__("$6");
    register int visible __asm__("$3");
    Moby* secondChild;
    switch (moby->state) {
    case 0:
        moby->unknown3[0] = 0;
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
        moby->updateDistance = 127;
        if (!(D_8006C550[tag->gateIndex].state & 128)) break;
        child = SpawnMoby(132, &D_8006C550[tag->sourceIndex]);
        __asm__("" : "=r"(child) : "0"(child));
        work = &offset;
        if (!child) break;
        childYaw = D_8006C550[tag->sourceIndex].angle.yaw;
        childPrivate = child->mobyTag;
        child->angle.yaw = childYaw;
        __asm__ volatile("" : : "r"(childYaw));
        *childPrivate = 0;
        child->state = 1;
        moby->state = 1;
        tag->child = child;
        __asm__ volatile("" : : "r"(moby), "r"(tag), "r"(child));
        offset.x = (DecodedIndexedCos[child->angle.yaw] * 13) >> 5;
        __asm__ volatile("" : : "r"(work));
        childYaw = child->angle.yaw;
        copiedWork = work;
        sine = DecodedIndexedSin[childYaw];
        vertical = DecodedIndexedPlayer44;
        childPosition = &child->position;
        /* Retail writes zero to this local slot before replacing it. */
        offset.z = 0;
        __asm__ volatile("" : : "r"(copiedWork), "r"(childPosition) : "memory");
        offset.z = vertical;
        offset.y = (sine * 13) >> 5;
        func_8004F194(work, copiedWork, childPosition);
        func_80013D44(&offset, (child->angle.yaw + 128) & 255, 0, 152);
        if (DecodedIndexedPlayer280 < 0) DecodedIndexedPlayer280 = 0;
        break;
    case 1:
        if ((tag->child->state & 128) && D_8006E344 != 15) {
            moby->state = 2;
            stateAddress = &moby->state;
            __asm__("" : "=r"(stateAddress) : "0"(stateAddress));
            func_8003B7B4(stateAddress, 1, &savedData);
            func_8003B7B4(stateAddress, 1, &unsavedData);
        }
        break;
    case 2:
        secondChild = SpawnMoby(603, moby);
        secondChild->position.z -= 512;
        secondChild->angle.pitch = 0;
        /* Empty constraints retain the original delayed visibility constant. */
        __asm__ volatile("" : : : "$3", "memory");
        visible = 1;
        __asm__("" : "=r"(visible) : "0"(visible));
        moby->lowDrawDistance = 32;
        moby->angle.pitch = 64;
        moby->unknown3[0] = visible;
        moby->drawn = visible;
        moby->state = 3;
        /* Original state-2 route continues through the state-3 distance gate. */
    case 3:
        if (func_8004F334(&moby->position, &DecodedIndexedPlayer) < 768)
            func_800584BC(0, D_8006C5BC - 8);
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define State594ZeroWord() ({register int zero0 __asm__("$0");__asm__ volatile("":"=r"(zero0):"i"(0));zero0;})
#define State594High(a,b) ({int high;__asm__ volatile("":"=h"(high):"l"((int)(a)*(int)(b)):"memory");high;})
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_18/moby/func_level_18_8007DE90.s SHA256 473e62fb0a07526029fad0b20e842528fd5c69c32e81deb200706b5fc22bf6d4. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define State594Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short State594_D_800658A0[0x100] __asm__("D_800658A0");
extern short State594_D_80065920[0x100] __asm__("D_80065920");
extern Moby* State594_D_8006C550 __asm__("D_8006C550");
extern Spyro State594_D_80070328 __asm__("D_80070328");
void State594_func_80034F40() __asm__("func_80034F40");
int State594_func_8003573C() __asm__("func_8003573C");
int State594_func_8003585C() __asm__("func_8003585C");
int State594_func_800359A4() __asm__("func_800359A4");
int State594_func_80035DDC() __asm__("func_80035DDC");
int State594_func_8003617C() __asm__("func_8003617C");
void State594_func_800369B8() __asm__("func_800369B8");
void State594_func_8003BA00() __asm__("func_8003BA00");
int State594_func_8003BABC() __asm__("func_8003BABC");
extern int State594_func_8004E880() __asm__("func_8004E880");
extern void State594_func_8004F178() __asm__("func_8004F178");
extern int State594_func_8004F264() __asm__("func_8004F264");
extern int State594_func_8004F334() __asm__("func_8004F334");
extern void State594_func_80055B18() __asm__("func_80055B18");
extern void State594_func_80055D24() __asm__("func_80055D24");
extern int State594_rand() __asm__("rand");

int State594_func_8001A310() __asm__("func_8001A310");
 /* extern */
int State594_func_8001C288() __asm__("func_8001C288");
    /* extern */
unsigned char State594_func_80034F80() __asm__("func_80034F80");
             /* extern */
int State594_func_80035030() __asm__("func_80035030");
 /* extern */
unsigned char State594_func_80036A68() __asm__("func_80036A68");
 /* extern */
unsigned char State594_func_80055F14() __asm__("func_80055F14");
 /* extern */
extern int State594_D_8006C770 __asm__("D_8006C770");
extern int State594_D_8006E344 __asm__("D_8006E344");

void func_level_18_8007DE90(Moby *owner17) {
    /* Original 0x60-byte frame: scratch SP+0x20..0x47,
     * saved registers SP+0x48..0x5C. Traced addresses retain byte offsets.
     * Signed LH comparisons occur after the original helper returns.
     * MULT55555556/HI/sign correction retains the original signed remainder.
     * Table samples are signed halfwords;
      products are shifted right by 9.
     * The substate2 write is in the copy call's delay slot, BEFORE the callee.
     * ZeroWord reads architectural hardwired register0 with initialized
     * immediate-zero input. It preserves ADDIU2,zero,1 and MOVE4,owner
     * producers through this target compiler's constant propagation.
     * This helper is specific to the MIPS target, with no instruction assembly.
     * Physical units, fixed-point domains, helper meanings/cadence and
     * synchronized retail runtime captures remain unresolved. */
    struct {
        Vector3D sp20;
        unsigned char pad2C[4];
        Vector3D sp30;
        unsigned char pad3C[12];
    } originalFrame;

    Moby *otherRecord16;
    Vector3D *ownerPosition16;
    Vector3D *storage18;
    Vector3D *ownerPosition19;
    int temp_a0;
    int helperWord16;
    int secondHelperWord16;
    int selectorLowBit;
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int word4 __asm__("$4");
    register int productHigh8 __asm__("$8");
    register int helperResultWord2 __asm__("$2");
    register Moby *ownerArgument4 __asm__("$4");
    register int stateArgument5 __asm__("$5");
    register void *sourceArgument5 __asm__("$5");
    register void *scratchArgument4 __asm__("$4");
    int temp_v0;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int recordIndex3;
    register int selector5 __asm__("$5");
    register int secondSelector5 __asm__("$5");
    int compareLimit20;
    register int state3 __asm__("$3");
    void *otherStorage19;

    storage18 = owner17->mobyTag;
    if (owner17->substate == 0) {
        owner17->substate = 1;
    }
    if (((unsigned int) (owner17->state - 5) >= 3U) && (owner17->damageFlags != 0)) {
        temp_v0 = State594Field(storage18, int *, 0x10) - 1;
        State594Field(storage18, int *, 0x10) = temp_v0;
        if ((temp_v0 <= 0) || (owner17->damageFlags & 0x180000)) {
            State594_func_80036A68(owner17, 1, 0, 0);
            owner17->updateDistance = 0xFF;
            owner17->state = 5;
            State594_func_80034F80(owner17, 2);
            State594_func_8003BABC(owner17, 0, 0);
            State594Field(storage18, int *, 0x28) = 0xB4;
            State594Field(storage18, int *, 0x24) = 0x96;
            State594Field(storage18, int *, 0x20) = State594_func_8004E880(owner17->position.x - State594_D_80070328.position.x, owner17->position.y - State594_D_80070328.position.y, 0);
            return;
        }
        owner17->state = 4;
        State594_func_80034F40(owner17, 2);
        owner17->damageFlags = 0;
        State594_func_8003BABC(owner17, 1, 0);
        State594Field(storage18, int *, 0x28) = 0xC8;
        State594Field(storage18, int *, 0x24) = 0x64;
        helperWord16 = State594_func_8004E880(owner17->position.x - State594_D_80070328.position.x, owner17->position.y - State594_D_80070328.position.y, 0);
        selectorLowBit=State594_rand()&1;
        selector5=-0x20;
        if(selectorLowBit){
            selector5 = 0x20;
        }
        State594Field(storage18, int *, 0x20) = State594_func_8003617C(helperWord16, selector5);
        goto dispatchState;
    }
dispatchState:
    state3 = owner17->state;
    switch (state3) {
    case 0:
        if (State594_func_8004F334(&owner17->position, &State594_D_80070328.position) < State594Field(storage18, short *, 0x14)) {
            owner17->substate = 1;
            owner17->state = 1;
            State594_func_80034F40(owner17, 0);
        }
        if (State594_D_8006C770 != 0) {
            word2=State594Field(storage18,short*,0x1A);
            __asm__("":"=r"(word2):"0"(word2));
            word4=word2;
            if(!word2)return;
            word3=State594_D_8006E344;
            __asm__("":"=r"(word3):"0"(word3),"r"(word4):"$2");
            word2=1;
            if(word3==word2)return;
            owner17->state=word4;
            State594Field(storage18,short*,0x1A)=0;
            return;
        }
    default:
        return;
    case 2:
        ownerPosition19=&owner17->position;
        helperResultWord2=State594_func_8004F334(ownerPosition19,storage18);
        __asm__("":"=r"(helperResultWord2):"0"(helperResultWord2));
        word3=State594Field(storage18,short*,0x18);
        word3=word3<helperResultWord2;
        __asm__("":"=r"(word3):"0"(word3));
        ownerArgument4=(Moby*)((unsigned char*)owner17+State594ZeroWord());
        if(word3)goto fallbackFields594;
        word2=owner17->position.z;
        __asm__("":"=r"(word2):"0"(word2));
        word3=State594_D_80070328.position.z;
        __asm__("":"=r"(word3):"0"(word3),"r"(word2));
        word2-=word3;
        if(word2<0)word2=-word2;
        if(word2>=0x401)goto fallbackFields594;
        __asm__ volatile(""::"r"(ownerArgument4));
        word3=State594_D_8006E344;
        word2=1;
        if(word3!=word2)goto processCase2_594;

ownerArgument4=owner17;
__asm__("":"=r"(ownerArgument4):"0"(ownerArgument4):"$5");
fallbackFields594:
stateArgument5=0;
__asm__("":"=r"(stateArgument5):"0"(stateArgument5):"$2");
word2=0x50;
__asm__ volatile("":"=r"(word2):"0"(word2):"memory");
State594Field(storage18,short*,0x30)=word2;
word2=2;
__asm__ volatile("":"=r"(word2):"0"(word2):"memory");
ownerArgument4->substate=word2;
word2=State594ZeroWord()+1;
goto callState594;

processCase2_594:
                temp_v0_3 = State594_func_8004E880(State594_D_80070328.position.x - owner17->position.x, State594_D_80070328.position.y - owner17->position.y, 0);
                State594_func_8003585C(owner17, temp_v0_3, 4, 0xC, 0, 0);
                if (State594_func_8004F264(temp_v0_3, (int) owner17->angle.yaw) < 0x14) {
                    State594_func_80035DDC(owner17, 0x5F, 0x200, 0x200, 0x23);
                }
                State594_func_8004F178(&originalFrame.sp20, ownerPosition19);
                originalFrame.sp20.z += 0x64;
                temp_v0_4 = State594_func_8001A310(&originalFrame.sp20, 0x400, 3, 0);
                if (temp_v0_4 == 0) {
                    ownerArgument4=owner17;
                    __asm__("":"=r"(ownerArgument4):"0"(ownerArgument4):"$5");
                    stateArgument5=0;
                    __asm__("":"=r"(stateArgument5):"0"(stateArgument5):"$2");
                    word2=0x50;
                    __asm__ volatile("":"=r"(word2):"0"(word2):"memory");
                    State594Field(storage18,short*,0x30)=word2;
                    word2=2;
                    __asm__ volatile("":"=r"(word2):"0"(word2):"memory");
                    ownerArgument4->substate=word2;
                    word2=State594ZeroWord()+1;
                    goto callState594;
                }
                owner17->position.z = temp_v0_4;
                State594_func_80055D24(owner17, 5);
                State594_func_80055F14(owner17, 0, &originalFrame.sp20);
                if (State594_func_8001C288(ownerPosition19, 0x200, 7) != 0) {
                    temp_v0_5 = State594_func_8004E880(State594_D_80070328.position.x - owner17->position.x, State594_D_80070328.position.y - owner17->position.y, 0) & 0xFF;
                    State594_D_80070328.unk22[5] = temp_v0_5;
                    State594_D_80070328.unk17a = 0x10000400;
                    State594_D_80070328.unk17e.x = (int) (State594_D_80065920[temp_v0_5] * 0x19) >> 9;
                    State594_D_80070328.unk17e.y = (int) (State594_D_800658A0[temp_v0_5] * 0x19) >> 9;
                    owner17->state = 4;
                    State594_func_80034F40(owner17, 2);
                    owner17->damageFlags = 0x10000;
                    State594Field(storage18, int *, 0x28) = 0xC8;
                    State594Field(storage18, int *, 0x24) = 0x64;
                    secondHelperWord16 = State594_func_8004E880(owner17->position.x - State594_D_80070328.position.x, owner17->position.y - State594_D_80070328.position.y, 0);
                    selectorLowBit=State594_rand()&1;
                    secondSelector5=-0x20;
                    if(selectorLowBit){
                        secondSelector5 = 0x20;
                    }
                    State594Field(storage18, int *, 0x20) = State594_func_8003617C(secondHelperWord16, secondSelector5);
                }
                helperResultWord2=State594_func_8004F334(&owner17->position,&State594_D_80070328.position);
                __asm__("":"=r"(helperResultWord2):"0"(helperResultWord2));
                word3=State594Field(storage18,short*,0x16);
                __asm__("":"=r"(word3):"0"(word3),"r"(helperResultWord2));
                word3=word3<helperResultWord2;
                __asm__("":"=r"(word3):"0"(word3));
                if(word3){
                    owner17->state = 1;
                    State594_func_80034F40(owner17, 0);
                    return;
                }

        break;
    case 1:
        compareLimit20 = 0x14;
        if (owner17->substate == 1) {
            ownerPosition16 = &owner17->position;
            helperResultWord2=State594_func_8004F334(ownerPosition16,&State594_D_80070328.position);
            __asm__("":"=r"(helperResultWord2):"0"(helperResultWord2));
            word3=State594Field(storage18,short*,0x16);
            __asm__("":"=r"(word3):"0"(word3),"r"(helperResultWord2));
            if(word3<=helperResultWord2){
                helperResultWord2=State594_func_8004F334(ownerPosition16,storage18);
                word3=State594Field(storage18,short*,0x18);
                word3=word3<helperResultWord2;
                __asm__("":"=r"(word3):"0"(word3):"$4");
                scratchArgument4=&originalFrame.sp30;
                if(word3)goto copyStorage594;
                word2=owner17->position.z;
                __asm__("":"=r"(word2):"0"(word2));
                word3=State594_D_80070328.position.z;
                __asm__("":"=r"(word3):"0"(word3),"r"(word2));
                word2-=word3;
                if(word2<0)word2=-word2;
                if(word2<0x401)goto copyPlayer594;
copyStorage594:
                sourceArgument5=storage18;
                __asm__ volatile(""::"r"(scratchArgument4));
                __asm__("":"=r"(sourceArgument5):"0"(sourceArgument5):"$2");
                word2=0x50;
                State594Field(storage18,short*,0x30)=word2;
                __asm__ volatile(""::"r"(scratchArgument4));
                word2=2;
                owner17->substate=word2;
                State594_func_8004F178(scratchArgument4,sourceArgument5);
                goto continueCase1;
copyPlayer594:
                State594_func_8004F178(scratchArgument4,&State594_D_80070328.position);
                goto continueCase1;
            }
            goto setState2;
        }
        compareLimit20 = 8;
        if (State594Field(storage18, short *, 0x30) == 0) {
            if (State594_func_8004F334(&owner17->position, &State594_D_80070328.position) < State594Field(storage18, short *, 0x16)) {
setState2:
                owner17->state = 2;
                return;
            }
            goto copyStorageCase1;
        }
        State594_func_800359A4(((void *)((unsigned char *)storage18 + 0x30)), 2);
copyStorageCase1:
        State594_func_8004F178(&originalFrame.sp30, storage18);
        if (State594_func_8004F334(&owner17->position, &originalFrame.sp30) < 0x400) {
            owner17->state = 8;
            return;
        }
continueCase1:
        temp_v0_6 = State594_func_8004E880((int) originalFrame.sp30.x - owner17->position.x, originalFrame.sp30.y - owner17->position.y, 0);
        State594_func_8003585C(owner17, temp_v0_6, 4, 1, 1, 0);
        if (State594_func_8004F264(temp_v0_6, (int) owner17->angle.yaw) < compareLimit20) {
            State594_func_80035DDC(owner17, 0xB4, 0x200, 0x200, 0x23);
        }
        State594_func_8004F178(&originalFrame.sp30, &owner17->position);
        originalFrame.sp30.z += 0x64;
        temp_v0_7 = State594_func_8001A310(&originalFrame.sp30, 0x400, 3, 0);
        if (temp_v0_7 == 0) {
            State594Field(storage18, short *, 0x30) = 0x50;
            owner17->substate = 2;
            return;
        }
        owner17->position.z = temp_v0_7;
        return;
    case 8:
        if (State594_func_8003573C(owner17, 8, 4, 0) != 0) {
            owner17->state = 0;
            State594_func_80034F40(owner17, 1);
            return;
        }
        break;
    case 3:
        if (State594_D_8006C770 != 0) {
            ownerArgument4=owner17;
            __asm__("":"=r"(ownerArgument4):"0"(ownerArgument4):"$5");
            stateArgument5=0;
            __asm__("":"=r"(stateArgument5):"0"(stateArgument5):"$2");
            word2=0x50;
            __asm__ volatile("":"=r"(word2):"0"(word2):"memory");
            State594Field(storage18,short*,0x30)=word2;
            word2=2;
            __asm__ volatile("":"=r"(word2):"0"(word2):"memory");
            ownerArgument4->substate=word2;
            word2=State594ZeroWord()+1;
            goto callState594;
        }
        break;
    case 4:
        if (State594_func_80035030(owner17, ((void *)((unsigned char *)storage18 + 0x28)), State594Field(storage18, int *, 0x20), ((void *)((unsigned char *)storage18 + 0x24)), 8, 0x10, 0x200, 0x23) == 3) {
ownerArgument4=owner17;
__asm__("":"=r"(ownerArgument4):"0"(ownerArgument4):"$5");
stateArgument5=0;
__asm__("":"=r"(stateArgument5):"0"(stateArgument5):"$2");
word2=0x5A;
__asm__ volatile("":"=r"(word2):"0"(word2):"memory");
State594Field(storage18,short*,0x30)=word2;
word2=1;
State594Field(storage18,short*,0x32)=0;
ownerArgument4->substate=word2;
callState594:
__asm__("":"=r"(word2):"0"(word2),"r"(ownerArgument4),"r"(stateArgument5));
ownerArgument4->state=word2;
State594_func_80034F40(ownerArgument4,stateArgument5);
return;
        }
        break;
    case 5:
    case 6:
        if (State594_func_80035030(owner17, ((void *)((unsigned char *)storage18 + 0x28)), State594Field(storage18, int *, 0x20), ((void *)((unsigned char *)storage18 + 0x24)), 8, 0x10, 0x200, 0x23) == 3) {
            owner17->state = 7;
            return;
        }
        break;
    case 7:
        if (State594_D_8006C770 != 0) {
            recordIndex3 = State594Field(storage18, int *, 0x2C);
            if (recordIndex3 != -1) {
                otherRecord16 = &State594_D_8006C550[recordIndex3];
                if (otherRecord16->state == 2) {
                    otherStorage19 = otherRecord16->mobyTag;
                    otherRecord16->unknown3[0] = 1;
                    otherRecord16->lowDrawDistance = 0x20;
                    otherRecord16->drawn = 1;
                    State594_func_8004F178(&otherRecord16->position, &owner17->position);
                    temp_a0 = State594Field(storage18, int *, 0xC);
                    if (temp_a0 == 0) {
                        word2=State594_rand();
                        word3=0x55555556;
                        __asm__("":"=r"(word3):"0"(word3));
                        productHigh8=State594High(word2,word3);
                        word4=word2>>31;
                        __asm__("":"=r"(productHigh8):"0"(productHigh8),"r"(word4));
                        word4=productHigh8-word4;
                        word3=(word4<<1)+word4;
                        word2-=word3;
                        word2++;
                        State594Field(otherStorage19,short*,0xC)=word2;
                    } else {
                        State594Field(otherStorage19, short *, 0xC) = (short) temp_a0;
                    }
                    otherRecord16->state = 0;
                }
            }
            State594_func_80055D24(owner17, 4);
            State594_func_8003BA00(owner17);
            State594_func_800369B8(owner17, 0x28);
            State594_func_80055B18(owner17);
            return;
        }
        break;
    case 9:
        State594_func_80035DDC(owner17, 0xB4, 0, 0x200, 0x21);
        if (State594_func_800359A4(((void *)((unsigned char *)storage18 + 0x30)), 2) != 0) {
            owner17->state = 0;
            State594Field(storage18, short *, 0x30) = 0x1E;
        }
        break;
    }
}
#undef State594Field


typedef struct {
    int selector, threshold;
} DecodedNearActorTag;
int func_8004F334(Vector3D*, Vector3D*);
void func_8003BABC(Moby*, int, int);
void func_80034F40(Moby*, int);
void func_level_18_8007E7D8(Moby* moby) {
    DecodedNearActorTag* tag = moby->mobyTag;
    if (func_8004F334(&moby->position, &spyro.position) < tag->threshold) {
        if (tag->selector) func_8003BABC(moby, 0, 0);
        tag->selector = 0;
        moby->state = 0;
        func_8003B7B4(tag, 4, &unsavedData);
    }
    if (!moby->state) {
        func_80034F40(moby, tag->selector);
        moby->state = 1;
    }
    switch (tag->selector) {
    case 0:
        moby->colour.g = 0xFF;
        moby->colour.r = 0;
        moby->colour.b = 0;
        moby->colour.a = 0x38;
        break;
    case 1:
        moby->colour.r = 0xFF;
        moby->colour.g = 0;
        moby->colour.b = 0;
        moby->colour.a = 0x38;
        break;
    }
}

typedef struct { int timer, sound; } DecodedDamageColourTag;
int DecodedDamageColourSound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedDamageColourPlaying(Moby*, int) __asm__("func_8003BFC0");
void func_level_18_8007E8D0(Moby* moby) {
    DecodedDamageColourTag* tag = moby->mobyTag;
    int blue, red, mode;
    register int firstBlue __asm__("$6");
    int firstMode;
    register int fullRed __asm__("$2");
    register int numerator __asm__("$2");
    register int counter __asm__("$3");
    register int product __asm__("$2");
    register int shifted __asm__("$3");
    register int encoded __asm__("$2");
    if (moby->damageFlags) {
        if (moby->state != 1) DecodedDamageColourSound(moby, 0, 0);
        tag->timer = 0;
        moby->damageFlags = 0;
    }
    if (!DecodedDamageColourPlaying(moby, tag->sound) && !DecodedDamageColourPlaying(moby, tag->sound)) tag->sound = DecodedDamageColourSound(moby, 1, 4);
    if (tag->timer >= 15) moby->state = 0;
    else if (tag->timer < 3) moby->state = 1;
    else moby->state = 2;
    switch (moby->state) {
    case 0:
        moby->colour.r = 0;
        moby->colour.g = 0;
        moby->colour.b = 0;
        moby->colour.a = 0;
        break;
    case 1:
        /* Original low-32-bit factorization: timer * 5 * 17 = timer * 85. */
        counter = tag->timer;
        product = counter * 5;
        shifted = product << 4;
        firstBlue = product + shifted;
        if (firstBlue > 255) firstBlue = 255;
        else if (firstBlue < 0) firstBlue = 0;
        numerator = (15 - tag->timer) * 8;
        /* Signed division truncates toward zero, as in the original instructions. */
        firstMode = numerator / 15;
        if (firstMode > 15) firstMode = 15;
        else if (firstMode < 0) firstMode = 0;
        fullRed = 255;
        /* Retain original allocation; this empty constraint emits no instructions. */
        __asm__ volatile ("" : : "r"(fullRed), "r"(firstMode) : "$3", "$4");
        moby->colour.r = fullRed;
        encoded = firstMode | 0x30;
        moby->colour.g = 0;
        moby->colour.b = firstBlue;
        moby->colour.a = encoded;
        tag->timer++;
        break;
    case 2:
        red = tag->timer * 170;
        if (red > 255) red = 255;
        else if (red < 0) red = 0;
        blue = tag->timer * 85;
        if (blue > 255) blue = 255;
        else if (blue < 0) blue = 0;
        mode = ((15-tag->timer) * 8) / 15;
        if (mode > 15) mode = 15;
        else if (mode < 0) mode = 0;
        moby->colour.r = red;
        moby->colour.g = 0;
        moby->colour.b = blue;
        moby->colour.a = mode | 0x30;
        tag->timer++;
        break;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007EB68,429 instructions, sibling4562. Verified28 spawn/particle C
 * reused; all raw fields, branches and constants from original18.
 * Units, helper contracts and cadence unresolved; uninstalled until exact. */
#define E18Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int E18func_80018368(void*,void*) __asm__("func_80018368");

int E18func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");

int E18func_800359A4(void*,int) __asm__("func_800359A4");

int E18func_8003BABC(void*,int,int) __asm__("func_8003BABC");

int E18func_8004E880(int,int,int) __asm__("func_8004E880");

int E18func_8004EA90(void*,void*,int) __asm__("func_8004EA90");

int E18func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");

int E18func_8004F0E8(void*,int) __asm__("func_8004F0E8");

int E18func_8004F110(void*,int) __asm__("func_8004F110");

int E18func_8004F178(void*,void*) __asm__("func_8004F178");

int E18func_8004F194(void*,void*,void*) __asm__("func_8004F194");

int E18func_80055B18(void*) __asm__("func_80055B18");

int E18rand(void) __asm__("rand");

extern short E18D_800658A0[] __asm__("D_800658A0");

extern short E18D_80065920[] __asm__("D_80065920");

extern int E18D_8006C574 __asm__("D_8006C574");

extern int E18D_8006C578 __asm__("D_8006C578");

extern int E18D_8006C640 __asm__("D_8006C640");

extern int E18D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char E18D_8006E020[] __asm__("D_8006E020");

extern void *(*E18SpawnMoby)(int,void*) __asm__("SpawnMoby");

extern int (*E18SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");

extern unsigned char E18D_80070328[] __asm__("D_80070328");
int E18func_8004F334(void*,void*) __asm__("func_8004F334");

int E18H19194() __asm__("func_80019194");
int E18H4EF74() __asm__("func_8004EF74");
int E18H3636C() __asm__("func_8003636C");
extern int E18Delta __asm__("D_8006C648");
extern int E18Reflect[] __asm__("D_80071918");


const int E18Initial[3] __asm__("D_level_18_80074718")={125,100,90};
extern unsigned char* E18Pool __asm__("D_8006C550");
extern unsigned short** E18Lists __asm__("D_8006C730");
extern int E18Mode __asm__("D_8006C7C4");
extern int E18Gate __asm__("D_8006C770");
int E18H55D24() __asm__("func_80055D24");
int E18H34F40() __asm__("func_80034F40");
int E18H36A68() __asm__("func_80036A68");
int E18H3BA00() __asm__("func_8003BA00");
int E18H369B8() __asm__("func_800369B8");
int E18H55C24() __asm__("func_80055C24");
int E18H34F80() __asm__("func_80034F80");
int E18H35D38() __asm__("func_80035D38");
int E18H5629C() __asm__("func_8005629C");
void func_level_18_8007EB68(void* input){
 struct {int first[4],second[4],third[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$18")=input;
 register unsigned char* state __asm__("$21");
 register int selectedAngle __asm__("$16");
 register unsigned char* nested16 __asm__("$16");
 register unsigned char* linked17 __asm__("$17");
 register void* spawned21D __asm__("$17");
 register int spawnIndex __asm__("$20");
 register int spawnOffset __asm__("$19");
 register unsigned char* player21 __asm__("$22");
 register int matrixParticleIndex __asm__("$19");
 register void* matrix21 __asm__("$20");
 register int* vector17 __asm__("$17");
 register int* vector16 __asm__("$16");
 register int work2 __asm__("$2");register int work3 __asm__("$3");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 void* spawned146;void* spawned1E2;unsigned char* linked;
 register unsigned short* list __asm__("$4");register unsigned int selector __asm__("$5");
 register unsigned char* pool7 __asm__("$7");register int mode6 __asm__("$6");int kind;
 __asm__("" : "=r"(owner):"0"(owner));
 state=E18Field(owner,unsigned char**,0);
 __asm__("" : "=r"(state):"0"(state):"$2","$3","$4","$5");
 {register int* initial5 __asm__("$5")=E18Initial;
 __asm__("" : "=r"(initial5):"0"(initial5));
 {register int first2 __asm__("$2")=initial5[0];register int second3 __asm__("$3")=initial5[1];register int third4 __asm__("$4")=initial5[2];
 __asm__("" : "=r"(first2),"=r"(second3),"=r"(third4):"0"(first2),"1"(second3),"2"(third4));
 frame.first[0]=first2;frame.first[1]=second3;frame.first[2]=third4;}}
 work3=E18Field(state,int*,16);
 if(work3!=-1){
  linked=E18Pool+work3*88;work2=E18Field(linked,int*,0);
  __asm__("" : "=r"(work2):"0"(work2));
  if(E18Field((void*)work2,int*,0)){
   E18Field(owner,int*,24)=0;
   if(!E18Field(state,int*,20)){
    work2=(int)E18SpawnMoby(577,owner);E18Field(state,int*,20)=work2;
    if(work2)E18H55D24((void*)work2,6);
   }
  }else{
   call4=E18Field(state,void**,20);
   if(call4){E18func_80055B18(call4);E18Field(state,int*,20)=0;}
  }
 }
 if(E18Field(owner,int*,24) && (unsigned int)(owner[0x48]-2)>=2){
  work2=E18Field(state,int*,12)-1;E18Field(state,int*,12)=work2;
  if(work2<=0 || (E18Field(owner,int*,24)&0x180000)){
   owner[0x48]=2;call4=owner;call5=1;
   goto emit;
  }
  call4=owner;call5=0;
  emit:__asm__ volatile("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
  E18func_8003BABC(call4,call5,0);
  owner[0x54]=255;owner[0x55]=255;owner[0x56]=255;owner[0x57]=63;
 }else{owner[0x54]=0;owner[0x55]=0;owner[0x56]=0;owner[0x57]=0;}
 switch(owner[0x48]){
 case 0:goto selection;
 case 1:goto timer;
 case 2:goto spawn;
 case 3:goto particles;
 default:{E18Field(owner,int*,24)=0;goto done;}
 }
 selection:
 if(!E18func_800359A4(state,4))goto clear;
 pool7=E18Pool;
 __asm__("" : "=r"(pool7):"0"(pool7):"$6");
 mode6=E18Mode;
 __asm__("" : "=r"(mode6):"0"(mode6):"$2","$3","$4");
 work2=E18Field(state,int*,8);
 __asm__("" : "=r"(work2):"0"(work2):"$3");
 {register unsigned short** table3 __asm__("$3")=E18Lists;
 __asm__("" : "=r"(table3),"=r"(work2):"0"(table3),"1"(work2));list=table3[work2];}
 do{
  selector=*list;work2=selector&32767;work3=work2*11;
  __asm__("" : "=r"(work3):"0"(work3));
  work3<<=3;__asm__("" : "=r"(work3):"0"(work3));
  linked17=(unsigned char*)(work3+(int)pool7);
  __asm__("" : "=r"(linked17):"0"(linked17));
  if(linked17[0x48]&128){
   if((linked17[0x53]>>mode6)&1)goto activate;
  }
  work2=selector<<16;list++;
 }while(work2>=0);
 __asm__ volatile("" ::: "memory");E18Field(owner,volatile int*,24)=0;goto done;
 timer:
 if(E18Gate && E18Field(owner,unsigned short*,60)==257)E18H34F40(owner,0);
 if(!E18func_800359A4(state,4))goto clear;
 E18Field(state,int*,0)=E18Field(state,int*,4);owner[0x48]=0;
 E18H34F40(owner,0);goto clear;
  spawn:
 if (((E18D_8006C578 - E18D_8006C574) >= 0x15) && (E18D_8006C7E8 >= 0x7531)) {
                    spawned146 = E18SpawnMoby(0x146, owner);

                    if (spawned146 != 0) {
                        E18Field(spawned146, signed char *, 0x47) = 7;

                    }
                }
                spawnIndex = 0;

                if ((E18D_8006C578 - E18D_8006C574) >= 0x15) {
                    player21=E18D_8006E020;

                    __asm__("" : "=r"(player21) : "0"(player21));

                    spawnOffset = 0;

                    loop_32:
                    if (E18D_8006C7E8 >= 0x7531) {
                        spawned21D = E18SpawnMoby(0x21D, owner);

                        if (spawned21D != 0) {
                            selectedAngle = E18func_8004E880(E18Field(owner, int *, 0xC) - E18Field(player21, int *, 0), E18Field(owner, int *, 0x10) - E18Field(player21, int *, 4), 0);

                            work2=E18rand();
                            selectedAngle+=64;

                            __asm__("" : "=r"(work2),"=r"(selectedAngle) : "0"(work2),"1"(selectedAngle));

                            work2&=31;
                            selectedAngle+=work2;
                            E18Field(spawned21D,signed char*,0x46)=selectedAngle;

                            E18Field(spawned21D, signed char *, 0x45) = (signed char) ((spawnOffset + (E18rand() & 0x1E)) - 0xF);

                            E18Field(spawned21D, signed char *, 0x47) = 8;

                            E18Field(spawned21D, signed char *, 0x4C) = 0x2A;

                        }
                        spawnIndex += 1;

                        spawnOffset += 0x33;

                        if ((spawnIndex < 5) && ((E18D_8006C578 - E18D_8006C574) >= 0x15)) {
                            goto loop_32;

                        }
                    }
                }

 __asm__("" ::: "$2");
 owner[0x41]=0;owner[0x4C]=0;owner[0x4D]=0;E18Field(state,int*,0)=20;owner[0x48]=3;

  particles:
 if(E18Field(state,int*,0)>=6){
  __asm__ volatile("" : "=r"(call4));
  matrixParticleIndex=0;matrix21=frame.matrix;vector17=frame.second;vector16=frame.third;
  do {
                    frame.angles[0] = 0;

                    frame.angles[1] = E18rand();

                    frame.angles[2] = E18rand();

                    E18func_8004EA90(&frame.angles[0], matrix21, 0);

                    matrixParticleIndex++;work2=E18rand();

                    /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)vector17;
                    call6=vector17;

                    __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2) : "memory");

                    work2&=31;
                    work2+=48;
                    frame.second[0]=work2;

                    frame.second[1] = 0;

                    frame.second[2] = 0;

                    E18func_8004ED6C(call4,(void*)call5,call6);

                    E18func_8004F178(vector16, vector17);

                    E18func_8004F0E8(vector16, 2);

                    __asm__("" : "=r"(owner) : "0"(owner));

                    E18func_8004F194(vector16, vector16, owner + 0xC);

                    call4=(void*)1;
                    call5=13;
                    call6=vector16;


                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));



                    E18SpawnParticle((int)call4,call5,call6,vector17);
                    __asm__("" : "=r"(owner):"0"(owner):"$22");

                } while (matrixParticleIndex < 4);



 call4=(void*)6;call5=70;call6=owner+12;
 __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
 E18SpawnParticle((int)call4,call5,call6,(void*)16);
 }
 if(!(E18D_8006C640&1) && E18D_8006C578-E18D_8006C574>=21 && E18D_8006C7E8>=30001){
  spawned1E2=E18SpawnMoby(482,owner);
  if(spawned1E2){E18Field(spawned1E2,unsigned char*,76)=42;E18Field(spawned1E2,unsigned char*,71)=10;}
 }
 if(!E18func_800359A4(state,4))goto clear;
 E18H36A68(owner,1,0,0);E18H55D24(owner,4);E18H3BA00(owner);E18H369B8(owner,48);E18func_80055B18(owner);goto done;
 activate:
 nested16=E18Field(linked17,unsigned char**,0);
 E18func_8004F178(linked17+12,owner+12);E18H55C24(linked17);
 E18Field(linked17,int*,24)=0;linked17[0x51]=0;
 E18Field(nested16,int*,16)=3;E18Field(nested16,short*,48)=30;E18H34F80(owner,0);
 linked17[0x48]=9;linked17[0x44]=0;linked17[0x45]=0;linked17[0x46]=owner[0x46];
 E18H35D38(linked17);E18H5629C(linked17);
 E18Field(state,int*,0)=frame.first[E18Mode];owner[0x48]=1;E18H34F40(owner,1);
 clear:
 E18Field(owner,int*,24)=0;
 done:__asm__ volatile("" ::: "memory");
}
#undef E18Field


INCLUDE_RODATA("asm/nonmatchings/overlays/level_18/moby", D_level_18_80074724);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_18/moby", D_level_18_80074730);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; AI generated, not human reviewed.
 * UNINSTALLED mixed C/original assembly proposal. Original CPU fragments are disclosed at each
 * site: two indexed LW reads; original F1C8/rand packets; three current-SP reads and F334 call
 * packet. The SP20/SP24 byte producers remain unresolved native inputs. No lookup bounds, defaults
 * or manual SP/FP object are supplied. Every
 * native/locals/control/table/source/helper/ownerInput/alias gate remains pending. */
#define Level18_7F21CField(p, t, o) (*(t)((unsigned char *)(p) + (o)))
#define Level18_7F21CKeep(v) __asm__("" : "=r"(v) : "0"(v))
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Level18_7F21CProduct;
extern int Level18_7F21C_D_800658A0 __asm__("D_800658A0");
extern int Level18_7F21C_D_80065920 __asm__("D_80065920");
extern int Level18_7F21C_D_8006C550 __asm__("D_8006C550");
extern int Level18_7F21C_D_8006C574 __asm__("D_8006C574");
extern int Level18_7F21C_D_8006C578 __asm__("D_8006C578");
extern int Level18_7F21C_D_8006C640 __asm__("D_8006C640");
extern int Level18_7F21C_D_8006C770 __asm__("D_8006C770");
extern int Level18_7F21C_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level18_7F21C_D_8006C7E8 __asm__("D_8006C7E8");
extern int Level18_7F21C_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level18_7F21C_D_8006D088 __asm__("D_8006D088");
extern int Level18_7F21C_D_8006E020 __asm__("D_8006E020");
extern int Level18_7F21C_D_80070328 __asm__("D_80070328");
extern volatile int Level18_7F21CPlayerPointer250 __asm__("D_80070328+592");
extern int Level18_7F21C_D_level_18_80074724 __asm__("D_level_18_80074724");
extern int Level18_7F21C_D_level_18_80074730 __asm__("D_level_18_80074730");
extern int Level18_7F21C_SpawnMoby __asm__("SpawnMoby");
extern int Level18_7F21C_SpawnParticle __asm__("SpawnParticle");
extern int Level18_7F21C_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level18_7F21C_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level18_7F21C_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
int Level18_7F21C_func_80018368() __asm__("func_80018368");
int Level18_7F21C_func_8002803C() __asm__("func_8002803C");
int Level18_7F21C_func_80028154() __asm__("func_80028154");
int Level18_7F21C_func_80034F40() __asm__("func_80034F40");
int Level18_7F21C_func_80034F80() __asm__("func_80034F80");
int Level18_7F21C_func_800359A4() __asm__("func_800359A4");
int Level18_7F21C_func_80035EE0() __asm__("func_80035EE0");
int Level18_7F21C_func_80036018() __asm__("func_80036018");
int Level18_7F21C_func_8003617C() __asm__("func_8003617C");
int Level18_7F21C_func_800369B8() __asm__("func_800369B8");
int Level18_7F21C_func_8003B7B4() __asm__("func_8003B7B4");
int Level18_7F21C_func_8003BA00() __asm__("func_8003BA00");
int Level18_7F21C_func_8003BABC() __asm__("func_8003BABC");
int Level18_7F21C_func_8004E880() __asm__("func_8004E880");
int Level18_7F21C_func_8004EA90() __asm__("func_8004EA90");
int Level18_7F21C_func_8004ED6C() __asm__("func_8004ED6C");
int Level18_7F21C_func_8004EDE8() __asm__("func_8004EDE8");
int Level18_7F21C_func_8004EF04() __asm__("func_8004EF04");
int Level18_7F21C_func_8004F0E8() __asm__("func_8004F0E8");
int Level18_7F21C_func_8004F178() __asm__("func_8004F178");
int Level18_7F21C_func_8004F194() __asm__("func_8004F194");
int Level18_7F21C_func_8004F1C8() __asm__("func_8004F1C8");
int Level18_7F21C_func_8004F1FC() __asm__("func_8004F1FC");
int Level18_7F21C_func_8004F2C8() __asm__("func_8004F2C8");
int Level18_7F21C_func_8004F334() __asm__("func_8004F334");
int Level18_7F21C_func_80050844() __asm__("func_80050844");
int Level18_7F21C_func_80055B18() __asm__("func_80055B18");
int Level18_7F21C_func_80055D24() __asm__("func_80055D24");
int Level18_7F21C_func_80055E84() __asm__("func_80055E84");
int Level18_7F21C_func_80055F14() __asm__("func_80055F14");
int Level18_7F21C_func_rand() __asm__("rand");
void func_level_18_8007F21C(void *ownerInput) {
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
    register int saved19 __asm__("$19");
    register int saved20 __asm__("$20");
    register int owner __asm__("$21");
    register int privateState __asm__("$22");
    register int saved23 __asm__("$23");
    register int temporary24 __asm__("$24");
    register int temporary25 __asm__("$25");
    int savedValue30, stackArgument4, stackArgument5, stackArgument6, stackArgument7;
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
        int spF8;
        int spFC;
        int sp100;
        int sp104;
        int sp108;
        int sp10C;
        int sp110;
        int sp114;
        int sp118;
        int sp11C;
        int sp120;
        int sp124;
        int sp128;
        int sp12C;
        int sp130;
        int sp134;
        int sp138;
        int sp13C;
        int sp140;
        int sp144;
        int sp148;
        int sp14C;
    } locals;
    long long completeSignedProduct;
    int actualHeader68, actualHeader6C;
    argument0 = (int)ownerInput;
    temporary2 = Level18_7F21CPlayerPointer250;
    owner = (int)((unsigned int)argument0 + (unsigned int)0);
    Level18_7F21CField((int)&locals, int *, 256) = 0;
    privateState = Level18_7F21CField(owner, int *, 0);
    __asm__("" : "=r"(owner), "=r"(privateState) : "0"(owner), "1"(privateState), "r"(temporary2));
    temporary2 = Level18_7F21CField(temporary2, int *, 0);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CField((int)&locals, int *, 240) = temporary2;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 1400);
    Level18_7F21CKeep(temporary2);
    __asm__ volatile("" ::"r"(temporary2));
    argument2 = (int)&Level18_7F21C_D_level_18_80074724;
    Level18_7F21CKeep(argument2);
    temporary3 = Level18_7F21CField(argument2, int *, 0);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(argument2, int *, 4);
    Level18_7F21CKeep(argument0);
    argument1 = Level18_7F21CField(argument2, int *, 8);
    Level18_7F21CKeep(argument1);
    Level18_7F21CField((int)&locals, int *, 16) = temporary3;
    Level18_7F21CField((int)&locals, int *, 20) = argument0;
    Level18_7F21CField((int)&locals, int *, 24) = argument1;
    __asm__(""
            : "=r"(temporary2)
            : "0"(temporary2), "m"(Level18_7F21CField((int)&locals, int *, 16)),
              "m"(Level18_7F21CField((int)&locals, int *, 20)),
              "m"(Level18_7F21CField((int)&locals, int *, 24)));
    if (temporary2 == 0)
        goto original1624Return;
    temporary2 = Level18_7F21CField(privateState, short *, 42);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)255), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)255), 0))
        goto original1624_42;
    Level18_7F21CField(owner, unsigned char *, 84) = temporary2;
    Level18_7F21CField(owner, unsigned char *, 85) = temporary2;
    Level18_7F21CField(owner, unsigned char *, 86) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)63);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 87) = temporary2;
    Level18_7F21CField(privateState, short *, 42) = 0;
    goto original1624_46;
original1624_42:
    Level18_7F21CField(owner, unsigned char *, 84) = 0;
    Level18_7F21CField(owner, unsigned char *, 85) = 0;
    Level18_7F21CField(owner, unsigned char *, 86) = 0;
    Level18_7F21CField(owner, unsigned char *, 87) = 0;
original1624_46:
    temporary2 = Level18_7F21CField(privateState, short *, 40);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);

    temporary3 = (int)0xFFF70000U;
    if (temporary2 != 0)
        goto original1624_186;
    temporary3 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)9);
    Level18_7F21CKeep(temporary2);
    saved16 = (int)((unsigned int)0 + (unsigned int)-1);
    if (temporary3 != temporary2)
        goto original1624_82;
    temporary2 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == saved16)
        goto original1624_68;
    argument0 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)temporary2);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 - (unsigned int)temporary2);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -15024);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)argument0 << 3);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    temporary2 = Level18_7F21C_func_80055B18(argument0);
    Level18_7F21CField(privateState, int *, 32) = saved16;
original1624_68:
    temporary2 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == saved16)
        goto original1624_82;
    argument0 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)temporary2);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 << 2);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 - (unsigned int)temporary2);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -15024);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)argument0 << 3);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    temporary2 = Level18_7F21C_func_80055B18(argument0);
    Level18_7F21CField(privateState, int *, 36) = saved16;
original1624_82:
    temporary2 = Level18_7F21CField(privateState, short *, 40);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);

    temporary3 = (int)0xFFF70000U;
    if (temporary2 != 0)
        goto original1624_186;
    temporary2 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-5);
    Level18_7F21CKeep(temporary2);
    temporary2 = (unsigned int)temporary2 < 2;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)-1), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)-1), 0))
        goto original1624_186;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    if (temporary3 == temporary2 ? (temporary2 = (int)((unsigned int)temporary3 << 1), 1)
                                 : (temporary2 = (int)((unsigned int)temporary3 << 1), 0))
        goto original1624_120;
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(temporary2, int *, 24);
    Level18_7F21CKeep(temporary3);

    if (temporary3 == 0)
        goto original1624_120;
    temporary2 = Level18_7F21CField(owner, int *, 24);
    Level18_7F21CKeep(temporary2);

    temporary2 = temporary2 | temporary3;
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, int *, 24) = temporary2;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, int *, 24) = 0;
original1624_120:
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = (int)((unsigned int)temporary3 << 1), 1)
                                 : (temporary2 = (int)((unsigned int)temporary3 << 1), 0))
        goto original1624_148;
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(temporary2, int *, 24);
    Level18_7F21CKeep(temporary3);

    if (temporary3 == 0)
        goto original1624_148;
    temporary2 = Level18_7F21CField(owner, int *, 24);
    Level18_7F21CKeep(temporary2);

    temporary2 = temporary2 | temporary3;
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, int *, 24) = temporary2;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, int *, 24) = 0;
original1624_148:
    temporary3 = (int)0xFFF70000U;
    Level18_7F21CKeep(temporary3);
    temporary2 = Level18_7F21CField(owner, int *, 24);
    Level18_7F21CKeep(temporary2);
    temporary3 = temporary3 | 65535;
    Level18_7F21CKeep(temporary3);
    temporary2 = temporary2 & temporary3;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)-1);
    if (temporary2 == 0)
        goto original1624_344;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    if (temporary3 != argument0)
        goto original1624_164;
    temporary2 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary2);

    if (temporary2 != temporary3 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)1), 1)
                                 : (temporary2 = (int)((unsigned int)0 + (unsigned int)1), 0))
        goto original1624_168;
    Level18_7F21CField(privateState, short *, 42) = temporary2;
    goto original1624_181;
original1624_164:
    temporary2 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == argument0 ? (temporary2 = (int)((unsigned int)temporary3 << 1), 1)
                                : (temporary2 = (int)((unsigned int)temporary3 << 1), 0))
        goto original1624_171;
original1624_168:
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
original1624_171:
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(temporary2, int *, 0);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary3, short *, 42) = temporary2;
original1624_181:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
    temporary3 = (int)0xFFF70000U;
    Level18_7F21CKeep(temporary3);
original1624_186:
    temporary2 = Level18_7F21CField(owner, int *, 24);
    Level18_7F21CKeep(temporary2);
    temporary3 = temporary3 | 65535;
    Level18_7F21CKeep(temporary3);
    temporary2 = temporary2 & temporary3;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1624_345;
    temporary2 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-5);
    Level18_7F21CKeep(temporary2);
    temporary2 = (unsigned int)temporary2 < 2;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0)
        goto original1624_345;
    temporary2 = Level18_7F21CField(privateState, short *, 40);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);

    if (temporary2 != 0)
        goto original1624_345;
    temporary2 = Level18_7F21CField(privateState, int *, 24);
    Level18_7F21CKeep(temporary2);

    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)-1);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)70);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 24) = temporary3;
    if (temporary3 != temporary2)
        goto original1624_270;
    Level18_7F21CKeep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)0 + (unsigned int)8);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, unsigned char *, 72) = temporary3;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(temporary2, int *, 0);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)10);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary3, int *, 16) = temporary2;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 65) = 0;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument1 = (int)((unsigned int)0 + (unsigned int)9);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 76) = 0;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 77) = 0;
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 36) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)120);
    goto original1624_334;
original1624_270:
    temporary2 = (int)((unsigned int)0 + (unsigned int)25);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary3 != temporary2)
        goto original1624_338;
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)0 + (unsigned int)8);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, unsigned char *, 72) = temporary3;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(temporary2, int *, 0);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)10);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary3, int *, 16) = temporary2;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 65) = 0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument1 = (int)((unsigned int)0 + (unsigned int)9);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 76) = 0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 77) = 0;
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 32) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)180);
    Level18_7F21CKeep(temporary2);
original1624_334:
    Level18_7F21CField(privateState, int *, 16) = temporary2;
    Level18_7F21C_func_80034F40(argument0, argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
original1624_338:
    temporary2 = Level18_7F21CField(privateState, int *, 24);
    Level18_7F21CKeep(temporary2);

    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 > 0)
        goto original1624_345;
    temporary2 = (int)((unsigned int)0 + (unsigned int)5);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
original1624_344:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
original1624_345:
    argument1 = (int)((unsigned int)0 + (unsigned int)5);
    Level18_7F21C_func_80055D24(argument0, argument1);
    temporary3 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)8);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)12);
    if (temporary3 != temporary2)
        goto original1624_419;
    argument0 = (int)((unsigned int)privateState + (unsigned int)16);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level18_7F21C_func_800359A4(argument0, argument1);
    saved19 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != 0)
        goto original1624_1376;
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(saved19);
    privateState = (int)&locals.sp70;
    Level18_7F21CKeep(privateState);
    saved18 = (int)&locals.sp40;
    Level18_7F21CKeep(saved18);
    saved16 = (int)&locals.sp50;
    Level18_7F21CKeep(saved16);
    saved20 = (int)&locals.sp60;
    Level18_7F21CKeep(saved20);
    saved17 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(saved17);
original1624_361:
    Level18_7F21CField((int)&locals, unsigned char *, 104) = 0;
    temporary2 = Level18_7F21C_func_rand();
    Level18_7F21CField((int)&locals, unsigned char *, 105) = temporary2;
    temporary2 = Level18_7F21C_func_rand();
    argument0 = (int)&locals.sp88;
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)privateState + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    Level18_7F21CField((int)&locals, unsigned char *, 106) = temporary2;
    Level18_7F21C_func_8004EA90(argument0, argument1, argument2);
    saved17 = (int)((unsigned int)saved17 + (unsigned int)1);
    temporary2 = Level18_7F21C_func_rand();
    argument0 = (int)((unsigned int)privateState + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved18 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved18 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    temporary2 = temporary2 & 31;
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)48);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 32) = temporary2;
    Level18_7F21CField((int)&locals, int *, 36) = 0;
    Level18_7F21CField((int)&locals, int *, 40) = 0;
    Level18_7F21C_func_8004ED6C(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved18 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8004F178(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21C_func_8004F0E8(argument0, argument1);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved19 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved20 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80055F14(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved20 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)13);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17124);
    Level18_7F21CKeep(temporary2);

    argument3 = (int)((unsigned int)saved18 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary2 = saved17 < 24;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)6);
    if (temporary2 != 0)
        goto original1624_361;
    argument1 = (int)((unsigned int)0 + (unsigned int)70);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)16);
    Level18_7F21CKeep(argument3);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17124);
    Level18_7F21CKeep(temporary2);

    saved19 = (int)((unsigned int)saved19 + (unsigned int)1);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary2 = saved19 < 4;
    Level18_7F21CKeep(temporary2);
    saved17 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != 0)
        goto original1624_361;

    goto original1624Return;
original1624_419:
    saved16 = (int)&Level18_7F21C_D_80070328;
    Level18_7F21CKeep(saved16);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8004F334(argument0, argument1);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, 1120);
    Level18_7F21CKeep(temporary3);

    Level18_7F21CField((int)&locals, int *, 248) = temporary2;
    if (temporary3 != owner)
        goto original1624_476;
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    temporary3 = Level18_7F21CField(saved16, int *, 0);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, int *, 12);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 812);
    Level18_7F21CKeep(temporary2);
    argument1 = Level18_7F21CField(owner, int *, 16);
    Level18_7F21CKeep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level18_7F21C_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)0x10000000U;
    Level18_7F21CKeep(argument0);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, 844);
    Level18_7F21CKeep(temporary3);
    argument0 = argument0 | 1024;
    Level18_7F21CKeep(argument0);

    Level18_7F21CField((int)&Level18_7F21C_D_80070328 + 664, int *, 0) = temporary2;

    Level18_7F21CField((int)&Level18_7F21C_D_80070328 + 524, int *, 0) = argument0;
    __asm__ volatile("" ::"i"((unsigned int)&Level18_7F21C_D_80070328 + 524U));
    __asm__("" : "=r"(temporary3) : "0"(temporary3), "r"(temporary2));
    temporary3 = temporary3 | 7;
    Level18_7F21CKeep(temporary3);

    Level18_7F21CField((int)&Level18_7F21C_D_80070328 + 36, int *, 0) = temporary3;
    temporary2 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(temporary2);

    temporary3 = Level18_7F21CField(
        ((int)((unsigned int)&Level18_7F21C_D_80065920 + (unsigned int)temporary2)), short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 9);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CField((int)&Level18_7F21C_D_80070328 + 540, int *, 0) = temporary2;
    temporary2 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(temporary2);

    temporary3 = Level18_7F21CField(
        ((int)((unsigned int)&Level18_7F21C_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 9);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CField((int)&Level18_7F21C_D_80070328 + 544, int *, 0) = temporary2;
original1624_476:
    temporary2 = Level18_7F21CField(privateState, short *, 40);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)5), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)5), 0))
        goto original1624_482;
    Level18_7F21CField(owner, unsigned char *, 65) = 0;
    goto original1624Return;
original1624_482:
    temporary3 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary3);

    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary3 == temporary2)
        goto original1624_558;
    temporary3 = Level18_7F21CField(saved16, int *, 0);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, int *, 12);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 812);
    Level18_7F21CKeep(temporary2);
    argument1 = Level18_7F21CField(owner, int *, 16);
    Level18_7F21CKeep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level18_7F21C_func_8004E880(argument0, argument1, argument2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level18_7F21CKeep(temporary2);
    argument1 = Level18_7F21CField(privateState, int *, 20);
    Level18_7F21CKeep(argument1);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)2048);
    temporary2 = Level18_7F21C_func_8004F2C8(argument0, argument1);
    argument1 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)((unsigned int)argument1 + (unsigned int)0);
    if (argument1 >= 0)
        goto original1624_502;
    temporary2 = (int)((unsigned int)0 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary2);
original1624_502:
    temporary3 = (int)((unsigned int)0 + (unsigned int)2048);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary2);
    temporary2 = temporary2 < 32;
    Level18_7F21CKeep(temporary2);
    if (temporary2 == 0)
        goto original1624_508;
    argument1 = (int)((unsigned int)0 + (unsigned int)2048);
    Level18_7F21CKeep(argument1);
original1624_508:
    temporary2 = (int)((unsigned int)argument1 + (unsigned int)0);
    if (argument1 >= 0)
        goto original1624_511;
    temporary2 = (int)((unsigned int)0 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary2);
original1624_511:
    temporary3 = (int)((unsigned int)temporary3 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    if (argument0 != temporary2 ? (temporary2 = temporary3 < 21, 1)
                                : (temporary2 = temporary3 < 21, 0))
        goto original1624_529;
    temporary2 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == argument0 ? (temporary2 = temporary3 < 26, 1)
                                : (temporary2 = temporary3 < 26, 0))
        goto original1624_524;
    if (temporary2 == 0)
        goto original1624_531;

    goto original1624_554;
original1624_524:
    temporary2 = temporary3 < 31;
    Level18_7F21CKeep(temporary2);
    if (temporary2 == 0)
        goto original1624_531;

    goto original1624_554;
original1624_529:
    if (temporary2 != 0)
        goto original1624_554;
original1624_531:
    temporary3 = Level18_7F21CField(privateState, int *, 20);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    if (argument1 <= 0)
        goto original1624_544;
    argument0 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(argument0);

    if (argument0 != temporary2
            ? (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)-20), 1)
            : (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)-20), 0))
        goto original1624_553;
    temporary2 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary2);

    if (temporary2 != argument0
            ? (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)-25), 1)
            : (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)-25), 0))
        goto original1624_553;
    temporary2 = (int)((unsigned int)temporary3 + (unsigned int)-30);
    goto original1624_553;
original1624_544:
    argument0 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(argument0);

    if (argument0 != temporary2
            ? (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)20), 1)
            : (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)20), 0))
        goto original1624_553;
    temporary2 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary2);

    if (temporary2 != argument0
            ? (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)25), 1)
            : (temporary2 = (int)((unsigned int)temporary3 + (unsigned int)25), 0))
        goto original1624_553;
    temporary2 = (int)((unsigned int)temporary3 + (unsigned int)30);
    Level18_7F21CKeep(temporary2);
original1624_553:
    Level18_7F21CField(privateState, int *, 20) = temporary2;
original1624_554:
    temporary2 = Level18_7F21CField(privateState, int *, 20);
    Level18_7F21CKeep(temporary2);

    temporary2 = (temporary2 >> 4);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 70) = temporary2;
original1624_558:
    temporary2 = Level18_7F21CField(privateState, int *, 48);
    Level18_7F21CKeep(temporary2);

    saved17 = (int)((unsigned int)temporary2 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1624_651;
    saved16 = (int)&locals.sp90;
    Level18_7F21CKeep(saved16);
    argument2 = Level18_7F21CField(saved17, int *, 12);
    Level18_7F21CKeep(argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)argument2 + (unsigned int)16);
    Level18_7F21C_func_8004F1C8(argument0, argument1, argument2);
    argument2 = Level18_7F21CField(saved17, int *, 12);
    Level18_7F21CKeep(argument2);
    argument1 = (int)&Level18_7F21C_D_80070328;
    Level18_7F21CKeep(argument1);
    /* Original570..571: the actual three-word F1C8 call and its
     * actual ADDIU A0,currentSP,160 delay producer. GP5/GP6 are the existing
     * complete initialized arguments. Native helper writes exactly the
     * three original locals words SPa0/a4/a8; no C stack-register binding,
     * incoming-locals capture, new value, or widened argument contract. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "jal\tfunc_8004F1C8\n\t"
                     "addiu\t$4,$sp,160\n\t"
                     ".set\treorder"
                     : "=r"(argument1), "=r"(argument2), "=m"(locals.spA0), "=m"(locals.spA4),
                       "=m"(locals.spA8)
                     : "0"(argument1), "1"(argument2)
                     : "$2", "$3", "$4", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
                       "$24", "$25", "$31", "hi", "lo", "memory");
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    temporary2 = Level18_7F21C_func_8004EDE8(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1024);
    Level18_7F21CKeep(argument1);
    saved16 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21C_func_8004EF04(argument0, argument1);
    temporary3 = Level18_7F21CField((int)&locals, volatile int *, 112);
    Level18_7F21CKeep(temporary3);
    temporary2 = Level18_7F21CField((int)&locals, volatile int *, 128);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary2);
    completeSignedProduct = (long long)temporary3 * (long long)temporary2;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    temporary3 = Level18_7F21CField((int)&locals, volatile int *, 116);
    Level18_7F21CKeep(temporary3);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        argument1 = wholeCapturedProjection;
    } while (0);
    Level18_7F21CKeep(argument1);
    temporary2 = Level18_7F21CField((int)&locals, volatile int *, 132);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary2);
    completeSignedProduct = (long long)temporary3 * (long long)temporary2;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    temporary3 = Level18_7F21CField((int)&locals, volatile int *, 120);
    Level18_7F21CKeep(temporary3);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        argument0 = wholeCapturedProjection;
    } while (0);
    Level18_7F21CKeep(argument0);
    temporary2 = Level18_7F21CField((int)&locals, volatile int *, 136);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary2);
    completeSignedProduct = (long long)temporary3 * (long long)temporary2;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    temporary2 = (int)((unsigned int)argument1 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        temporary3 = wholeCapturedProjection;
    } while (0);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    argument2 = (temporary2 >> 10);
    Level18_7F21CKeep(argument2);
    temporary2 = saved16 < argument2;
    Level18_7F21CKeep(temporary2);
    if (temporary2 == 0)
        goto original1624_602;
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    goto original1624_605;
original1624_602:
    Level18_7F21CKeep(temporary2);
    saved16 = (int)&locals.spA0;
    if (argument2 >= 0)
        goto original1624_606;
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
original1624_605:
    saved16 = (int)&locals.spA0;
    Level18_7F21CKeep(saved16);
original1624_606:
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)&locals.sp90;
    Level18_7F21C_func_8004F1FC(argument0, argument1, argument2);
    temporary2 = Level18_7F21CField((int)&locals, volatile int *, 128);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField((int)&locals, volatile int *, 132);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)&locals.sp20;
    Level18_7F21CKeep(argument0);
    Level18_7F21CField((int)&locals, int *, 136) = 0;
    __asm__(""
            : "=r"(temporary2)
            : "0"(temporary2), "m"(Level18_7F21CField((int)&locals, int *, 136)));
    temporary2 = (temporary2 >> 10);
    Level18_7F21CKeep(temporary2);
    temporary3 = (temporary3 >> 10);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField((int)&locals, int *, 128) = temporary2;
    Level18_7F21CField((int)&locals, int *, 132) = temporary3;
    argument2 = Level18_7F21CField(saved17, int *, 12);
    Level18_7F21CKeep(argument2);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    temporary2 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary2);

    temporary2 = (unsigned int)temporary2 < 2;
    Level18_7F21CKeep(temporary2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != 0)
        goto original1624_652;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 812);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField((int)&locals, volatile int *, 4);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)8000);
    Level18_7F21CKeep(argument0);
    temporary2 = argument0 < temporary3;
    Level18_7F21CKeep(temporary2);
    if (temporary2 == 0)
        goto original1624_633;
    temporary3 = (int)((unsigned int)argument0 + (unsigned int)0);
    Level18_7F21CKeep(temporary3);
original1624_633:
    argument0 = Level18_7F21CField(owner, int *, 16);
    Level18_7F21CKeep(argument0);

    temporary2 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    if (temporary2 < 0 ? (temporary2 = temporary2 < 1025, 1) : (temporary2 = temporary2 < 1025, 0))
        goto original1624_642;
    if (temporary2 == 0)
        goto original1624_646;

    goto original1624_648;
original1624_642:
    temporary2 = (int)((unsigned int)argument0 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = temporary2 < 1025;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0)
        goto original1624_648;
original1624_646:
    Level18_7F21CField((int)&locals, int *, 4) = temporary3;
    goto original1624_651;
original1624_648:
    temporary2 = Level18_7F21CField(owner, int *, 16);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CField((int)&locals, int *, 4) = temporary2;
original1624_651:
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
original1624_652:
    /* Actual original LW from currentSP+32; the prior byte producer
     * remains unresolved. The m operand binds the existing physical object;
     * it is no initialized C scalar, entry snapshot or fabricated value. */
    __asm__ volatile("lw %0,32($sp)" : "=r"(temporary3) : "m"(locals.sp20) : "memory");
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, int *, 12);
    Level18_7F21CKeep(argument0);
    /* Actual original LW from currentSP+36; the prior byte producer
     * remains unresolved. The m operand binds the existing physical object;
     * it is no initialized C scalar, entry snapshot or fabricated value. */
    __asm__ volatile("lw %0,36($sp)" : "=r"(temporary2) : "m"(locals.sp24) : "memory");
    Level18_7F21CKeep(temporary2);
    argument1 = Level18_7F21CField(owner, int *, 16);
    Level18_7F21CKeep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level18_7F21C_func_8004E880(argument0, argument1, argument2);
    Level18_7F21CKeep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)12);
    Level18_7F21CKeep(argument0);
    argument1 = (int)&locals.sp20;
    Level18_7F21CKeep(argument1);
    /* Original661..662: real F334 call, original S0=oldV0 delay.
     * A0/A1 are the actual initialized pointer words. The helper's original
     * SP20/SP24 machine reads retain their unresolved storage producers;
     * no byte of locals.sp20/sp24 is declared initialized by this boundary.
     * Normal F334 full GP2 and actual saved S0 preservation remain required. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "jal\tfunc_8004F334\n\t"
                     "addu\t$16,$2,$zero\n\t"
                     ".set\treorder"
                     : "=r"(temporary2), "=r"(argument0), "=r"(argument1), "=r"(saved16)
                     : "0"(temporary2), "1"(argument0), "2"(argument1), "m"(locals.sp20),
                       "m"(locals.sp24)
                     : "$3", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
                       "$24", "$25", "$31", "hi", "lo", "memory");
    temporary2 = temporary2 < 1025;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0)
        goto original1624_694;
    argument0 = Level18_7F21CField(owner, int *, 12);
    Level18_7F21CKeep(argument0);
    /* Actual original LW from currentSP+32; the prior byte producer
     * remains unresolved. The m operand binds the existing physical object;
     * it is no initialized C scalar, entry snapshot or fabricated value. */
    __asm__ volatile("lw %0,32($sp)" : "=r"(temporary3) : "m"(locals.sp20) : "memory");
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)argument0 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    if (temporary2 >= 0)
        goto original1624_673;
    temporary2 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
original1624_673:
    temporary3 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 << 4);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 + (unsigned int)0);
    if (temporary3 >= 0)
        goto original1624_681;
    temporary2 = (int)((unsigned int)temporary3 + (unsigned int)2047);
    Level18_7F21CKeep(temporary2);
original1624_681:
    temporary2 = (temporary2 >> 11);
    Level18_7F21CKeep(temporary2);
    argument2 = (int)((unsigned int)temporary2 + (unsigned int)40);
    Level18_7F21CKeep(argument2);
    temporary2 = argument2 < 251;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 != 0)
        goto original1624_687;
    argument2 = (int)((unsigned int)0 + (unsigned int)250);
    Level18_7F21CKeep(argument2);
original1624_687:
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument3);
    temporary2 = Level18_7F21C_func_80035EE0(argument0, argument1, argument2, argument3, 4096, 33);
original1624_694:
    temporary3 = Level18_7F21CField(privateState, int *, 52);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = (int)((unsigned int)temporary3 << 1), 1)
                                 : (temporary2 = (int)((unsigned int)temporary3 << 1), 0))
        goto original1624_774;
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 240);
    Level18_7F21CKeep(temporary8);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary3 = Level18_7F21CField(temporary8, int *, 40);
    Level18_7F21CKeep(temporary3);

    temporary3 = temporary3 < 5;
    Level18_7F21CKeep(temporary3);
    saved18 = (int)((unsigned int)argument0 + (unsigned int)temporary2);
    if (temporary3 == 0)
        goto original1624_774;
    temporary3 = Level18_7F21CField(saved18, unsigned char *, 72);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)privateState + (unsigned int)56);
    if (temporary3 != temporary2)
        goto original1624_774;
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level18_7F21C_func_800359A4(argument0, argument1);
    if (temporary2 == 0)
        goto original1624_774;
    argument0 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)96);
    temporary2 = Level18_7F21C_func_8003617C(argument0, argument1);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(temporary2);

    temporary3 = Level18_7F21CField(
        ((int)((unsigned int)&Level18_7F21C_D_80065920 + (unsigned int)temporary2)), short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 9);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved18, int *, 12) = temporary2;
    argument0 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)96);
    temporary2 = Level18_7F21C_func_8003617C(argument0, argument1);
    saved16 = (int)((unsigned int)saved18 + (unsigned int)12);
    Level18_7F21CKeep(saved16);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(temporary2);
    saved17 = (int)((unsigned int)owner + (unsigned int)12);
    Level18_7F21CKeep(saved17);

    temporary3 = Level18_7F21CField(
        ((int)((unsigned int)&Level18_7F21C_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);
    argument2 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    Level18_7F21CField(saved18, int *, 20) = 0;
    __asm__ volatile("" ::"m"(Level18_7F21CField(saved18, int *, 20)) : "memory");
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 9);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved18, int *, 16) = temporary2;
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80018368(argument0, argument1);
    temporary3 = (int)((unsigned int)0 + (unsigned int)1);
    if (temporary2 != 0)
        goto original1624_774;
    temporary2 = (int)((unsigned int)0 + (unsigned int)32);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved18, unsigned char *, 65) = temporary3;
    __asm__(""
            : "=r"(temporary2)
            : "0"(temporary2), "m"(Level18_7F21CField(saved18, unsigned char *, 65)));
    Level18_7F21CField(saved18, unsigned char *, 76) = temporary2;
    Level18_7F21CField(saved18, unsigned char *, 77) = temporary3;
    Level18_7F21CField(saved18, unsigned char *, 72) = 0;
    __asm__ volatile("" ::"m"(Level18_7F21CField(saved18, unsigned char *, 72)) : "memory");
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14396);
    Level18_7F21CKeep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)(int)&locals + (unsigned int)temporary2 - 32U);
    Level18_7F21CKeep(temporary2);
    /* Original Rev0 0x8007fe28; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,48(%1)" : "=r"(temporary2) : "0"(temporary2) : "memory");

    Level18_7F21CField(privateState, int *, 56) = temporary2;
original1624_774:
    temporary3 = Level18_7F21CField(owner, unsigned char *, 72);
    Level18_7F21CKeep(temporary3);

    switch ((unsigned int)temporary3) {
    case 0:
        __asm__ volatile("" ::"r"(temporary3));
        goto original1624_785;
    case 1:
        goto original1624_820;
    case 2:
        goto original1624_823;
    case 3:
        goto original1624_835;
    case 4:
        goto original1624_1380;
    case 5:
        goto original1624_1149;
    case 6:
        goto original1624_1255;
    case 7:
        goto original1624_1365;
    case 8:
        goto original1624_1380;
    case 9:
        goto original1624_1368;
    default:
        goto original1624_1380;
    }
original1624_785:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14396);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)(int)&locals + (unsigned int)temporary2 - 32U);
    Level18_7F21CKeep(temporary2);
    /* Original Rev0 0x8007fe78; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,48(%1)" : "=r"(argument1) : "r"(temporary2) : "memory");
    temporary2 = (int)((unsigned int)0 + (unsigned int)100);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 24) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 56) = argument1;
    Level18_7F21CField(temporary2, unsigned char *, 65) = 0;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument1 = (int)((unsigned int)0 + (unsigned int)8);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 65) = 0;
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
    temporary2 = Level18_7F21C_func_80034F80(argument0, argument1);

    goto original1624_1380;
original1624_820:
    temporary9 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary9);
    Level18_7F21CField((int)&locals, int *, 256) = temporary9;
    goto original1624_1380;
original1624_823:
    Level18_7F21CKeep(privateState);
    argument0 = (int)((unsigned int)privateState + (unsigned int)16);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level18_7F21C_func_800359A4(argument0, argument1);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1624_833;
    argument1 = (int)((unsigned int)0 + (unsigned int)10);
    Level18_7F21C_func_80034F40(argument0, argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
    goto original1624_1380;
original1624_833:
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 256) = 0;
    goto original1624_1380;
original1624_835:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80055E84(argument0);
    temporary3 = (int)((unsigned int)0 + (unsigned int)12);
    Level18_7F21CKeep(temporary3);
    if (temporary2 != temporary3)
        goto original1624_1139;
    argument1 = (int)&Level18_7F21C_D_level_18_80074730;
    Level18_7F21CKeep(argument1);
    temporary2 = Level18_7F21CField(argument1, int *, 0);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(argument1, int *, 4);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(argument1, int *, 8);
    Level18_7F21CKeep(argument0);
    Level18_7F21CField((int)&locals, int *, 160) = temporary2;
    Level18_7F21CField((int)&locals, int *, 164) = temporary3;
    Level18_7F21CField((int)&locals, int *, 168) = argument0;
    argument0 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    temporary8 = (int)((unsigned int)0 + (unsigned int)2);
    if (argument0 == temporary2)
        goto original1624_862;
    temporary2 = (int)((unsigned int)argument0 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 272) = temporary8;
    __asm__(""
            : "=r"(temporary3)
            : "0"(temporary3), "m"(Level18_7F21CField((int)&locals, int *, 272)));
    savedValue30 = (int)((unsigned int)temporary3 + (unsigned int)temporary2);
    goto original1624_878;
original1624_862:
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    temporary9 = (int)((unsigned int)0 + (unsigned int)1);
    if (temporary3 == argument0)
        goto original1624_876;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 272) = temporary9;
    __asm__(""
            : "=r"(temporary3)
            : "0"(temporary3), "m"(Level18_7F21CField((int)&locals, int *, 272)));
    savedValue30 = (int)((unsigned int)temporary3 + (unsigned int)temporary2);
    goto original1624_878;
original1624_876:
    savedValue30 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(savedValue30);
    Level18_7F21CField((int)&locals, int *, 272) = 0;
original1624_878:
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 272);
    Level18_7F21CKeep(temporary8);
    temporary3 = (int)&locals.sp20;
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary8 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 160);
    Level18_7F21CKeep(temporary2);

    Level18_7F21CField((int)&locals, int *, 264) = 0;
    if (temporary2 <= 0)
        goto original1624_1139;
    saved23 = (int)&locals.spB0;
    Level18_7F21CKeep(saved23);
    Level18_7F21CField((int)&locals, int *, 280) = temporary3;
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 280);
    Level18_7F21CKeep(temporary9);

    Level18_7F21CField((int)&locals, int *, 296) = temporary9;
original1624_891:
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 272);
    Level18_7F21CKeep(temporary8);
    temporary9 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary9);
    temporary2 = temporary8 < 2;
    if (temporary8 == temporary9)
        goto original1624_988;
    if (temporary2 == 0)
        goto original1624_901;
    saved20 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary8 == 0)
        goto original1624_1051;

    goto original1624_1126;
original1624_901:
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)590);
    if (temporary8 != temporary2)
        goto original1624_1126;
    argument1 = (int)((unsigned int)savedValue30 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17120);
    Level18_7F21CKeep(temporary2);
    temporary9 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary9);
    Level18_7F21CField((int)&locals, int *, 176) = 0;
    Level18_7F21CField((int)&locals, int *, 180) = temporary9;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved19 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(saved19);
    argument0 = (int)((unsigned int)saved19 + (unsigned int)0);
    if (saved19 == 0)
        goto original1624_1126;
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 296);
    Level18_7F21CKeep(temporary8);
    argument0 = (int)((unsigned int)savedValue30 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = Level18_7F21CField(temporary8, int *, 176);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved23 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80055F14(argument0, argument1, argument2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, 808);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField((int)&locals, volatile int *, 144);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 812);
    Level18_7F21CKeep(temporary2);
    argument1 = Level18_7F21CField((int)&locals, volatile int *, 148);
    Level18_7F21CKeep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level18_7F21C_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)32);
    temporary2 = Level18_7F21C_func_80036018(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved19 + (unsigned int)12);
    Level18_7F21CKeep(argument0);
    saved16 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(saved16);
    temporary9 = (int)&Level18_7F21C_D_80065920;
    Level18_7F21CKeep(temporary9);
    saved17 = (int)((unsigned int)saved16 + (unsigned int)temporary9);
    Level18_7F21CKeep(saved17);
    temporary2 = Level18_7F21CField(saved17, short *, 0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);
    argument1 = (int)((unsigned int)argument0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary2 = (temporary2 >> 5);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved19, int *, 12) = temporary2;
    temporary2 = (int)&Level18_7F21C_D_800658A0;
    Level18_7F21CKeep(temporary2);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)temporary2);
    Level18_7F21CKeep(saved16);
    temporary2 = Level18_7F21CField(saved16, short *, 0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);
    argument2 = (int)((unsigned int)saved23 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    Level18_7F21CField(saved19, int *, 20) = 0;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "m"(Level18_7F21CField(saved19, int *, 20)));
    temporary2 = (temporary2 >> 5);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved19, int *, 16) = temporary2;
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    temporary3 = Level18_7F21CField(saved17, short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary2 << 4);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary3);
    temporary2 = Level18_7F21CField(saved19, int *, 0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (temporary3 >> 10);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, int *, 0) = temporary3;
    temporary3 = Level18_7F21CField(saved16, short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary2 << 4);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary3);
    temporary2 = Level18_7F21CField(saved19, int *, 0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (temporary3 >> 10);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, int *, 4) = temporary3;
    temporary2 = Level18_7F21CField(saved19, int *, 0);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)0x51EB0000U;
    Level18_7F21CKeep(argument0);
    Level18_7F21CField(temporary2, int *, 8) = 0;
    temporary3 = Level18_7F21CField(privateState, int *, 24);
    Level18_7F21CKeep(temporary3);
    argument0 = argument0 | 34079;
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(argument0);
    completeSignedProduct = (long long)temporary2 * (long long)argument0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    temporary2 = (temporary2 >> 31);
    Level18_7F21CKeep(temporary2);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=h"(wholeCapturedProjection) : "x"(completeSignedProduct));
        temporary8 = wholeCapturedProjection;
    } while (0);
    Level18_7F21CKeep(temporary8);
    temporary3 = (temporary8 >> 5);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 - (unsigned int)temporary2);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)20);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(privateState, int *, 16) = temporary3;
    goto original1624_1126;
original1624_988:
    argument0 = (int)((unsigned int)0 + (unsigned int)591);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)savedValue30 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, 17120);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 176) = 0;
    Level18_7F21CField((int)&locals, int *, 180) = temporary2;
    temporary2 = ((int (*)())temporary3)(argument0, argument1);
    saved19 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(saved19);
    argument0 = (int)((unsigned int)saved19 + (unsigned int)0);
    if (saved19 == 0)
        goto original1624_1126;
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 296);
    Level18_7F21CKeep(temporary9);
    argument0 = (int)((unsigned int)savedValue30 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = Level18_7F21CField(temporary9, int *, 176);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved23 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80055F14(argument0, argument1, argument2);
    saved16 = (int)((unsigned int)saved19 + (unsigned int)12);
    Level18_7F21CKeep(saved16);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    temporary3 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(temporary3);
    temporary8 = (int)&Level18_7F21C_D_80065920;
    Level18_7F21CKeep(temporary8);
    temporary3 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 + (unsigned int)temporary8);
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, short *, 0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary2 = (temporary2 >> 5);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved19, int *, 12) = temporary2;

    temporary2 = Level18_7F21CField(
        ((int)((unsigned int)&Level18_7F21C_D_800658A0 + (unsigned int)temporary3)), short *, 0);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(temporary2);
    argument2 = (int)((unsigned int)saved23 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    Level18_7F21CField(saved19, int *, 20) = 0;
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "m"(Level18_7F21CField(saved19, int *, 20)));
    temporary2 = (temporary2 >> 5);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved19, int *, 16) = temporary2;
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)-12);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)12);
    Level18_7F21CKeep(argument2);
    Level18_7F21CField(saved19, unsigned char *, 69) = 0;
    temporary2 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(temporary2);
    argument3 = (int)((unsigned int)0 + (unsigned int)16512);
    Level18_7F21CKeep(argument3);
    Level18_7F21CField(saved19, unsigned char *, 70) = temporary2;
    temporary2 = Level18_7F21C_func_80050844(argument0, argument1, argument2, argument3);
    temporary3 = Level18_7F21CField(saved19, int *, 0);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x51EB0000U;
    Level18_7F21CKeep(argument0);
    Level18_7F21CField(temporary3, int *, 8) = temporary2;
    temporary2 = Level18_7F21CField(privateState, int *, 24);
    Level18_7F21CKeep(temporary2);
    argument0 = argument0 | 34079;
    Level18_7F21CKeep(argument0);
    temporary3 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)temporary2);
    Level18_7F21CKeep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 3);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(argument0);
    completeSignedProduct = (long long)temporary3 * (long long)argument0;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    temporary3 = (temporary3 >> 31);
    Level18_7F21CKeep(temporary3);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=h"(wholeCapturedProjection) : "x"(completeSignedProduct));
        temporary9 = wholeCapturedProjection;
    } while (0);
    Level18_7F21CKeep(temporary9);
    temporary2 = (temporary9 >> 5);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)20);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 16) = temporary2;
    goto original1624_1126;
original1624_1051:
    argument0 = (int)((unsigned int)0 + (unsigned int)601);
    Level18_7F21CKeep(argument0);
original1624_1052:
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17120);
    Level18_7F21CKeep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved19 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(saved19);
    temporary2 = (int)((unsigned int)0 + (unsigned int)60);
    if (saved19 == 0)
        goto original1624_1113;
    argument0 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(argument0);
    saved18 = Level18_7F21CField(saved19, int *, 0);
    Level18_7F21CKeep(saved18);
    argument1 = (int)((unsigned int)saved20 + (unsigned int)-8);
    temporary2 = Level18_7F21C_func_8003617C(argument0, argument1);
    argument0 = (int)((unsigned int)savedValue30 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved23 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    saved16 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(saved16);
    Level18_7F21CField(saved19, int *, 12) = 0;
    Level18_7F21CField(saved19, int *, 16) = 0;
    Level18_7F21CField(saved19, int *, 20) = 0;
    temporary2 = Level18_7F21C_func_80055F14(argument0, argument1, argument2);
    saved17 = (int)((unsigned int)saved19 + (unsigned int)12);
    Level18_7F21CKeep(saved17);
    argument0 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved23 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    temporary2 = (int)((unsigned int)0 + (unsigned int)64);
    Level18_7F21CKeep(temporary2);
    saved16 = (int)((unsigned int)saved16 << 1);
    Level18_7F21CKeep(saved16);
    temporary8 = (int)&Level18_7F21C_D_80065920;
    Level18_7F21CKeep(temporary8);
    Level18_7F21CField(saved19, unsigned char *, 69) = temporary2;
    temporary2 = (int)((unsigned int)saved16 + (unsigned int)temporary8);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(saved19, int *, 20);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)12);
    Level18_7F21CKeep(argument0);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)512);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(saved19, int *, 20) = temporary3;
    temporary3 = Level18_7F21CField(temporary2, short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    temporary2 = (int)((unsigned int)temporary3 << 5);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 11);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved18, int *, 0) = temporary2;

    temporary3 = Level18_7F21CField(
        ((int)((unsigned int)&Level18_7F21C_D_800658A0 + (unsigned int)saved16)), short *, 0);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)90);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved18, int *, 8) = 0;
    __asm__ volatile("" ::"m"(Level18_7F21CField(saved18, int *, 8)) : "memory");
    Level18_7F21CField(saved18, int *, 12) = temporary2;
    temporary2 = (int)((unsigned int)temporary3 << 5);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 11);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved18, int *, 4) = temporary2;
    temporary2 = Level18_7F21C_func_80018368(argument0, argument1);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)60), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)60), 0))
        goto original1624_1113;
    argument0 = (int)((unsigned int)saved19 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80055B18(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)60);
    Level18_7F21CKeep(temporary2);
original1624_1113:
    Level18_7F21CField(privateState, int *, 16) = temporary2;
    if (saved20 != 0)
        goto original1624_1118;
    if (saved19 == 0)
        goto original1624_1118;
    Level18_7F21CField(privateState, int *, 0) = saved19;
original1624_1118:
    saved20 = (int)((unsigned int)saved20 + (unsigned int)1);
    Level18_7F21CKeep(saved20);
    temporary2 = saved20 < 16;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)601);
    if (temporary2 != 0)
        goto original1624_1052;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)saved19 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
original1624_1126:
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 296);
    Level18_7F21CKeep(temporary9);
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 272);
    Level18_7F21CKeep(temporary8);
    temporary9 = (int)((unsigned int)temporary9 + (unsigned int)4);
    Level18_7F21CKeep(temporary9);
    temporary2 = (int)((unsigned int)temporary8 << 2);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 296) = temporary9;
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 280);
    Level18_7F21CKeep(temporary9);
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 264);
    Level18_7F21CKeep(temporary8);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary9);
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 160);
    Level18_7F21CKeep(temporary2);
    temporary8 = (int)((unsigned int)temporary8 + (unsigned int)1);
    Level18_7F21CKeep(temporary8);
    temporary2 = temporary8 < temporary2;
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 264) = temporary8;
    if (temporary2 != 0)
        goto original1624_891;
original1624_1139:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14480);
    Level18_7F21CKeep(temporary2);

    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1624_1380;
    argument1 = (int)((unsigned int)0 + (unsigned int)9);
    Level18_7F21C_func_80034F40(argument0, argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
    goto original1624_1380;
original1624_1149:
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14984);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -14988);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = temporary2 < 21;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0)
        goto original1624_1173;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14360);
    Level18_7F21CKeep(temporary2);

    temporary2 = temporary2 < 30001;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)326);
    if (temporary2 != 0)
        goto original1624_1173;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17120);
    Level18_7F21CKeep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)7);
    if (temporary3 == 0)
        goto original1624_1173;
    Level18_7F21CField(temporary3, unsigned char *, 71) = temporary2;
original1624_1173:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14984);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -14988);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = temporary2 < 21;
    Level18_7F21CKeep(temporary2);
    saved19 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != 0)
        goto original1624_1234;
    Level18_7F21CKeep(temporary2);
    Level18_7F21CKeep(saved19);
    Level18_7F21CKeep(temporary2);
    saved20 = (int)&Level18_7F21C_D_8006E020;
    Level18_7F21CKeep(saved20);
    saved18 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(saved18);
original1624_1185:
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14360);
    Level18_7F21CKeep(temporary2);

    temporary2 = temporary2 < 30001;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)541);
    if (temporary2 != 0)
        goto original1624_1234;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17120);
    Level18_7F21CKeep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved17 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(saved17);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (saved17 == 0)
        goto original1624_1221;
    temporary3 = Level18_7F21CField(owner, int *, 12);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(saved20, int *, 0);
    Level18_7F21CKeep(argument0);
    temporary2 = Level18_7F21CField(owner, int *, 16);
    Level18_7F21CKeep(temporary2);
    argument1 = Level18_7F21CField(saved20, int *, 4);
    Level18_7F21CKeep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level18_7F21C_func_8004E880(argument0, argument1, argument2);
    saved16 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_rand();
    saved16 = (int)((unsigned int)saved16 + (unsigned int)64);
    Level18_7F21CKeep(saved16);
    temporary2 = temporary2 & 31;
    Level18_7F21CKeep(temporary2);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)temporary2);
    Level18_7F21CKeep(saved16);
    Level18_7F21CField(saved17, unsigned char *, 70) = saved16;
    temporary2 = Level18_7F21C_func_rand();
    temporary2 = temporary2 & 30;
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)saved18 + (unsigned int)temporary2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-15);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved17, unsigned char *, 69) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)8);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved17, unsigned char *, 71) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)42);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(saved17, unsigned char *, 76) = temporary2;
original1624_1221:
    saved19 = (int)((unsigned int)saved19 + (unsigned int)1);
    Level18_7F21CKeep(saved19);
    temporary2 = saved19 < 5;
    Level18_7F21CKeep(temporary2);
    saved18 = (int)((unsigned int)saved18 + (unsigned int)51);
    if (temporary2 == 0)
        goto original1624_1234;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14984);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -14988);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = temporary2 < 21;
    Level18_7F21CKeep(temporary2);
    if (temporary2 == 0)
        goto original1624_1185;
original1624_1234:
    __asm__ volatile("" ::"r"(temporary2));
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BABC(argument0, argument1, argument2);
    temporary2 = (int)((unsigned int)0 + (unsigned int)90);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 65) = 0;
    Level18_7F21CField(owner, unsigned char *, 76) = 0;
    Level18_7F21CField(owner, unsigned char *, 77) = 0;
    Level18_7F21CField(owner, int *, 8) = 0;
    Level18_7F21CField(privateState, int *, 16) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)6);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
    argument0 = Level18_7F21CField(privateState, int *, 44);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(temporary2);
    if (argument0 == temporary2)
        goto original1624_1252;

    temporary2 = Level18_7F21C_func_80028154(argument0);
original1624_1252:
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 240);
    Level18_7F21CKeep(temporary9);
    Level18_7F21CField(temporary9, int *, 68) = 0;
    goto original1624_1380;
original1624_1255:
    saved23 = (int)((unsigned int)0 + (unsigned int)4096);
    Level18_7F21CKeep(saved23);
    saved18 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(saved18);
    saved19 = (int)&locals.spF8;
    Level18_7F21CKeep(saved19);
    saved20 = (int)((unsigned int)0 + (unsigned int)176);
    Level18_7F21CKeep(saved20);
    saved17 = (int)&locals.spD8;
    Level18_7F21CKeep(saved17);
    saved16 = (int)&locals.spE8;
    Level18_7F21CKeep(saved16);
original1624_1261:
    Level18_7F21CField((int)&locals, unsigned char *, 104) = 0;
    temporary2 = Level18_7F21C_func_rand();
    Level18_7F21CField((int)&locals, unsigned char *, 105) = temporary2;
    temporary2 = Level18_7F21C_func_rand();
    argument0 = (int)&locals.sp88;
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved19 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    Level18_7F21CField((int)&locals, unsigned char *, 106) = temporary2;
    Level18_7F21C_func_8004EA90(argument0, argument1, argument2);

    /* Original1270..1271: real zero-word rand call, original NOP delay.
     * The twelve-word original helper defines complete GP2; no ownerInput word
     * or initial random-state assumption is supplied here. Its actual seed
     * mutation and normal caller-GP/HI/LO effects remain visible. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "jal\trand\n\t"
                     "nop\n\t"
                     ".set\treorder"
                     : "=r"(temporary2)
                     :
                     : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14",
                       "$15", "$24", "$25", "$31", "hi", "lo", "memory");
    __asm__ volatile("" : "=r"(saved19) : "0"(saved19), "r"(temporary2));
    argument0 = (int)((unsigned int)saved19 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    argument2 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    temporary2 = temporary2 & 31;
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)saved20);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 184) = temporary2;
    Level18_7F21CField((int)&locals, int *, 188) = 0;
    Level18_7F21CField((int)&locals, int *, 192) = 0;
    Level18_7F21C_func_8004ED6C(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8004F178(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21C_func_8004F0E8(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument1);
    Level18_7F21CKeep(owner);
    Level18_7F21CKeep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    temporary2 = Level18_7F21C_func_8004F194(argument0, argument1, argument2);
    temporary2 = saved23 < 513;
    Level18_7F21CKeep(temporary2);
    argument1 = (int)((unsigned int)0 + (unsigned int)55);
    if (temporary2 != 0)
        goto original1624_1295;
    argument1 = (int)((unsigned int)0 + (unsigned int)13);
    Level18_7F21CKeep(argument1);
original1624_1295:
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(argument0);
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument2);
    argument3 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level18_7F21CKeep(argument3);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17124);
    Level18_7F21CKeep(temporary2);

    saved18 = (int)((unsigned int)saved18 + (unsigned int)1);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary2 = saved18 < 24;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)6);
    if (temporary2 != 0)
        goto original1624_1261;
    argument1 = (int)((unsigned int)0 + (unsigned int)70);
    Level18_7F21CKeep(argument1);
    Level18_7F21CKeep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    Level18_7F21CKeep(argument2);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17124);
    Level18_7F21CKeep(temporary2);

    argument3 = (int)((unsigned int)0 + (unsigned int)16);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14784);
    Level18_7F21CKeep(temporary2);

    temporary2 = temporary2 & 1;
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)privateState + (unsigned int)16);
    if (temporary2 != 0)
        goto original1624_1347;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14984);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -14988);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = temporary2 < 21;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0)
        goto original1624_1347;
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, -14360);
    Level18_7F21CKeep(temporary2);

    temporary2 = temporary2 < 30001;
    Level18_7F21CKeep(temporary2);
    if (temporary2 != 0)
        goto original1624_1347;
    argument0 = (int)((unsigned int)0 + (unsigned int)482);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)0x80070000U;
    Level18_7F21CKeep(temporary2);
    temporary2 = Level18_7F21CField(temporary2, int *, 17120);
    Level18_7F21CKeep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)42);
    if (temporary3 == 0)
        goto original1624_1346;
    Level18_7F21CField(temporary3, unsigned char *, 76) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)10);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary3, unsigned char *, 71) = temporary2;
original1624_1346:
    Level18_7F21CKeep(privateState);
    argument0 = (int)((unsigned int)privateState + (unsigned int)16);
    Level18_7F21CKeep(argument0);
original1624_1347:
    __asm__ volatile("" ::"r"(temporary2));
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level18_7F21C_func_800359A4(argument0, argument1);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)9), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)9), 0))
        goto original1624_1380;
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
    saved16 = (int)((unsigned int)owner + (unsigned int)72);
    Level18_7F21CKeep(saved16);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument2 = (int)&Level18_7F21C_D_8006D088;
    Level18_7F21CKeep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    temporary2 = Level18_7F21C_func_8003B7B4(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument2 = (int)&Level18_7F21C_D_8006C7F8;
    Level18_7F21CKeep(argument2);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    temporary2 = Level18_7F21C_func_8003B7B4(argument0, argument1, argument2);

    goto original1624Return;
original1624_1365:
    temporary8 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary8);
    Level18_7F21CField((int)&locals, int *, 256) = temporary8;
    goto original1624_1380;
original1624_1368:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Level18_7F21C_func_80055D24(argument0, argument1);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = Level18_7F21C_func_8003BA00(argument0);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level18_7F21CKeep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)48);
    Level18_7F21C_func_800369B8(argument0, argument1);
original1624_1376:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = Level18_7F21C_func_80055B18(argument0);

    goto original1624Return;
original1624_1380:
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 256);
    Level18_7F21CKeep(temporary9);

    if (temporary9 == 0)
        goto original1624_1424;
    temporary2 = Level18_7F21CField(privateState, int *, 28);
    Level18_7F21CKeep(temporary2);
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 248);
    Level18_7F21CKeep(temporary8);

    temporary2 = temporary8 < temporary2;
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField((int)&locals, int *, 256) = 0;
    if (temporary2 != 0)
        goto original1624_1394;
    temporary2 = Level18_7F21CField(owner, int *, 24);
    Level18_7F21CKeep(temporary2);

    if (temporary2 == 0)
        goto original1624_1396;
original1624_1394:
    temporary9 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary9);
    Level18_7F21CField((int)&locals, int *, 256) = temporary9;
original1624_1396:
    temporary8 = Level18_7F21CField((int)&locals, volatile int *, 256);
    Level18_7F21CKeep(temporary8);

    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary8 == 0)
        goto original1624_1424;
    argument1 = (int)((unsigned int)0 + (unsigned int)9);
    Level18_7F21C_func_80034F40(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)53);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(owner, unsigned char *, 72) = temporary2;
    actualHeader68 = Level18_7F21C_unk_ovlheader_80074368;
    actualHeader6C = Level18_7F21C_unk_ovlheader_8007436C;
    __asm__(""
            : "=r"(privateState)
            : "0"(privateState), "r"(actualHeader68), "r"(actualHeader6C)
            : "$2");
    stackArgument5 = (int)((unsigned int)privateState + (unsigned int)24);
    stackArgument6 = (int)((unsigned int)0 + (unsigned int)100);
    argument1 = (int)((unsigned int)0 + (unsigned int)186);
    temporary2 = Level18_7F21C_func_8002803C(argument0, argument1, actualHeader68, actualHeader6C,
                                             Level18_7F21C_unk_ovlheader_80074364, stackArgument5,
                                             stackArgument6);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level18_7F21CKeep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(privateState, int *, 44) = temporary2;
    temporary9 = Level18_7F21CField((int)&locals, volatile int *, 240);
    Level18_7F21CKeep(temporary9);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary9, int *, 68) = temporary2;
original1624_1424:
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    saved16 = (int)((unsigned int)0 + (unsigned int)-1);
    Level18_7F21CKeep(saved16);
    Level18_7F21CKeep(owner);
    argument1 = (int)((unsigned int)owner + (unsigned int)12);
    if (temporary3 == saved16)
        goto original1624_1517;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)temporary2);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)12);
    temporary2 = Level18_7F21C_func_8004F178(argument0, argument1);
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 70) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(owner, unsigned char *, 60);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)-4);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, unsigned char *, 60) = temporary3;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(owner, unsigned char *, 61);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)-4);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, unsigned char *, 61) = temporary3;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 62);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 62) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 63);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 63) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 64);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 64) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 65) = 0;
original1624_1517:
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);

    Level18_7F21CKeep(owner);
    argument1 = (int)((unsigned int)owner + (unsigned int)12);
    if (temporary3 == saved16)
        goto original1624_1610;
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)temporary2);
    Level18_7F21CKeep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)12);
    temporary2 = Level18_7F21C_func_8004F178(argument0, argument1);
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 70);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 70) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(owner, unsigned char *, 60);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)-8);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, unsigned char *, 60) = temporary3;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = (int)0x80070000U;
    Level18_7F21CKeep(argument0);
    argument0 = Level18_7F21CField(argument0, int *, -15024);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary3 = Level18_7F21CField(owner, unsigned char *, 61);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)-8);
    Level18_7F21CKeep(temporary3);
    Level18_7F21CField(temporary2, unsigned char *, 61) = temporary3;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 62);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 62) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 63);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 63) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 36);
    Level18_7F21CKeep(temporary3);
    argument0 = Level18_7F21CField(owner, unsigned char *, 64);
    Level18_7F21CKeep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 64) = argument0;
    temporary3 = Level18_7F21CField(privateState, int *, 32);
    Level18_7F21CKeep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    temporary3 = (int)0x80070000U;
    Level18_7F21CKeep(temporary3);
    temporary3 = Level18_7F21CField(temporary3, int *, -15024);
    Level18_7F21CKeep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level18_7F21CKeep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level18_7F21CKeep(temporary2);
    Level18_7F21CField(temporary2, unsigned char *, 65) = 0;
original1624_1610:
    Level18_7F21CField(owner, int *, 24) = 0;
original1624Return:
    return;
}
#undef Level18_7F21CField
#undef Level18_7F21CKeep


/* AI-generated; not human reviewed. SCUS-94467 USA Rev0
 * 80080B7C..80080E2C,173 original words. Reuses verified signed trig/packet
 * code from raw601/actor1852; original size, colour, proximity/flag and
 * collision-reset paths preserved. Raw units/helper meanings/cadence open.
 * Test: original linked words and full retail EXE/every-overlay hashes. */
extern unsigned char DecodedRawProjectilePlayer[] __asm__("D_80070328");
extern int DecodedRawProjectileFlags __asm__("D_80070328+0x24");
void func_level_18_80080B7C(Moby* argument) {
    DecodedRawProjectileWork work;
    register Moby* moby __asm__("$18") = argument;
    register DecodedRawProjectileTag* tag __asm__("$16");
    register int x __asm__("$6") = moby->position.x;
    register int y __asm__("$5");
    register int z __asm__("$4");
    register void* retained __asm__("$17");
    register int opposite __asm__("$19");
    register int heading __asm__("$16");
    register Vector3D* position __asm__("$17");
    register int size __asm__("$7");
    register int maximum __asm__("$3");
    char* particle;
    __asm__("" : "=r"(moby) : "0"(moby));
    tag = moby->mobyTag;
    __asm__("" : "=r"(tag) : "0"(tag), "r"(x));
    size = 32;
    __asm__("" : "=r"(size) : "0"(size));
    moby->size = size;
    if (x < 1024) goto cleanup;
    y = moby->position.y;
    if (y < 1024) goto cleanup;
    z = moby->position.z;
    if (z < 1024) goto cleanup;
    maximum = 256000;
    __asm__("" : "=r"(maximum) : "0"(maximum));
    {
        register int outside __asm__("$2");
        outside = x > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
        outside = y > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
        outside = z > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
    }
    if (!*((unsigned char*)moby + 0x4D)) goto cleanup;
    { register Vector3D* oldArgument __asm__("$4") = &work.oldPosition;
    __asm__("" : "=r"(oldArgument) : "0"(oldArgument));
    position = &moby->position;
    moby->colour.g = 255;
    moby->colour.r = size;
    moby->colour.b = size;
    moby->colour.a = 63;
    func_8004F178(oldArgument,position);
    }
    moby->position.x += tag->delta.x;
    moby->position.y += tag->delta.y;
    moby->position.z += tag->delta.z;
    if (moby->state == 0) {
        if (func_8004F334(position,(Vector3D*)DecodedRawProjectilePlayer) < 512) {
            DecodedRawProjectileFlags |= 1;
            moby->state = 98;
            goto done;
        }
        if (func_800359A4(&tag->timer,4) ||
                func_8001830C(&work.oldPosition,position,0,0x10000,moby)) {
            tag->delta.x = 0;
            tag->delta.y = 0;
            tag->delta.z = 0;
            func_8004F178(&moby->position,&work.oldPosition);
            moby->state = 98;
        }
        {
            register int result __asm__("$2") = func_8004E880(tag->delta.x,tag->delta.y,0);
            register int low __asm__("$4") = 0;
            register int high __asm__("$5") = 14;
            __asm__("" : "=r"(low), "=r"(high) : "0"(low), "1"(high), "r"(result));
            heading = result;
            heading += func_800363DC(low,high);
        }
        opposite = heading;
        __asm__ volatile ("" : : "r"(opposite));
        retained = &work.particlePosition;
        func_8004F178(retained,&moby->position);
        /* Preserve both signed table lanes and the raw particle packet writes. */
        {
            register int primaryIndex __asm__("$3") = opposite & 255;
            register int oppositeIndex __asm__("$7");
            register int cosine __asm__("$5");
            register int kind __asm__("$4");
            register int selector __asm__("$5");
            register Vector3D* positionArg __asm__("$6");
            register char* (*spawn)(int,int,Vector3D*,Vector3D*) __asm__("$8");
            __asm__("" : "=r"(primaryIndex) : "0"(primaryIndex));
            opposite = heading - 128;
            __asm__("" : "=r"(opposite) : "0"(opposite));
            primaryIndex *= 2;
            kind = 1;
            __asm__("" : "=r"(kind) : "0"(kind));
            oppositeIndex = (opposite & 255) * 2;
            __asm__("" : "=r"(primaryIndex), "=r"(oppositeIndex) : "0"(primaryIndex), "1"(oppositeIndex));
            cosine = *(short*)((char*)D_80065920 + primaryIndex);
            spawn = SpawnParticle;
            __asm__("" : "=r"(cosine), "=r"(spawn) : "0"(cosine), "1"(spawn));
            work.direction.x = (cosine * 15) >> 11;
            {
                register int sine __asm__("$3") = *(short*)((char*)D_800658A0 + primaryIndex);
                __asm__("" : "=r"(sine) : "0"(sine));
                positionArg = retained;
                __asm__("" : "=r"(positionArg) : "0"(positionArg));
                work.direction.z = 0;
                __asm__ volatile ("" : : : "memory");
                work.direction.y = (sine * 15) >> 11;
            }
            {
                register int sample __asm__("$3") = *(short*)((char*)D_80065920 + oppositeIndex);
                __asm__("" : "=r"(sample) : "0"(sample) : "$5");
                selector = 13;
                __asm__("" : "=r"(selector) : "0"(selector), "r"(sample));
                work.particlePosition.x += (sample * 5) >> 9;
            }
            {
                register int sample __asm__("$2") = *(short*)((char*)D_800658A0 + oppositeIndex);
                register int product __asm__("$3") = sample * 5;
                __asm__("" : "=r"(product) : "0"(product));
                work.particlePosition.y += product >> 9;
            }
            particle = spawn(kind,selector,positionArg,&work.direction);
        }
        particle[2] = 14;
        particle[10] += 56;
    }
done:
    if (moby->state != 98) return;
cleanup:
    func_80055B18(moby);
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Actor18E30Helper3BFC0(void*,int) __asm__("func_8003BFC0");
int Actor18E30Helper3BE70(int) __asm__("func_8003BE70");
extern unsigned char Actor18E30D_80070328[] __asm__("D_80070328");
extern int Actor18E30Player24 __asm__("D_80070328 + 0x24");
#define Actor18E30Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Actor18E30D_800658A0 __asm__("D_800658A0");
extern short Actor18E30D_80065920[] __asm__("D_80065920");
extern int Actor18E30D_8006C574 __asm__("D_8006C574");
extern int Actor18E30D_8006C578 __asm__("D_8006C578");
extern void* Actor18E30D_8006E788 __asm__("D_8006E788");
int Actor18E30Helper1830C(void*,void*,int,int,void*) __asm__("func_8001830C");
int Actor18E30Helper18368(void*,void*) __asm__("func_80018368");
void* Actor18E30Helper1BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");
int Actor18E30Helper359A4(void*,int) __asm__("func_800359A4");
int Actor18E30Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Actor18E30Helper4E880(int,int,int) __asm__("func_8004E880");
int Actor18E30Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Actor18E30Helper4F110(void*,int) __asm__("func_8004F110");
int Actor18E30Helper4F178(void*,void*) __asm__("func_8004F178");
int Actor18E30Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Actor18E30Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Actor18E30Helper4F264(int,int) __asm__("func_8004F264");
int Actor18E30Helper4F334(void*,void*) __asm__("func_8004F334");
int Actor18E30Helper509E8(void*) __asm__("func_800509E8");
int Actor18E30Helper55B18(void*) __asm__("func_80055B18");
int Actor18E30Helper55D24(void*,int) __asm__("func_80055D24");
extern void* (*Actor18E30SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Actor18E30SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
void func_level_18_80080E30(void *input) {
    struct { Vector3D b; int pad34; Vector3D c; int pad44; Vector3D d; int pad54; Vector3D f; int pad74; } frame;
    register unsigned char *owner __asm__("$18")=input;
    register short *cosineEntry __asm__("$19");
    register int *currentPosition __asm__("$17");
    register int *probePosition __asm__("$17");
    register int *updatedPosition __asm__("$17");
    register int targetScore __asm__("$3");
    register int absoluteTurn __asm__("$16");
    register int particleIndex __asm__("$16");
    register int stepValue __asm__("$17");
    register int particleAngle __asm__("$17");
    register int bestScore __asm__("$20");
    register int absoluteDelta __asm__("$2");
    register int distanceDelta __asm__("$3");
    register int turnDelta __asm__("$3");
    register int previousHeading __asm__("$4");
    unsigned char state;
    register int nextHeading __asm__("$2");
    register void **targetCursor __asm__("$18");
    register void **firstCursor __asm__("$3");
    register unsigned char *firstCandidate __asm__("$4");
    register int wanted __asm__("$5");
    void *cleanupHandle;
    void *finalHandle;
    void *selectedTarget;
    register void *candidateTarget __asm__("$17");
    register void *particlePosition __asm__("$21");
    register void *particleVector __asm__("$20");
    register void *tag __asm__("$22");
    register void *firstHit __asm__("$17");
    register void *secondHit __asm__("$16");
    register void *spawnedChild __asm__("$16");

    tag = Actor18E30Field(owner, void **, 0);
    if (Actor18E30Field(owner, unsigned char *, 0x4D) == 0) {
        cleanupHandle = Actor18E30Field(tag, void **, 8);
        if (cleanupHandle != 0) {
            Actor18E30Helper509E8(cleanupHandle);
        }
        goto removeOwner;
    }
    state = Actor18E30Field(owner, unsigned char *, 0x48);
    switch (state) {                              /* irregular */
foundFirstCandidate:
        Actor18E30Field(tag,void**,4)=firstCandidate;
        goto firstCandidateDone;
    case 0:
        firstCursor=&Actor18E30D_8006E788;
        Actor18E30Field(tag,void**,4)=0;
        firstCandidate=*firstCursor++;
        if(firstCandidate) {
            wanted=0x170;
            __asm__("" : "=r"(wanted):"0"(wanted));
testFirstCandidate:
            if(Actor18E30Field(firstCandidate,short*,0x36)==wanted) goto foundFirstCandidate;
            firstCandidate=*firstCursor++;
            if(firstCandidate) goto testFirstCandidate;
        }
firstCandidateDone:
        Actor18E30Field(owner, unsigned char *, 0x48) = 1U;
        /* fallthrough */
    case 1:
        if ((Actor18E30Field(owner, int *, 0xC) < 0x400) || (Actor18E30Field(owner, int *, 0x10) < 0x400) || (Actor18E30Field(owner, int *, 0x14) < 0x400) || (Actor18E30Helper359A4(tag, 4) != 0)) {
            Actor18E30Field(owner, unsigned char *, 0x48) = 2U;
            return;
        }
        {register void **cursor __asm__("$17")=&Actor18E30D_8006E788;
         register unsigned char *candidate __asm__("$16");
         register int type97 __asm__("$19");register int typeBB __asm__("$20");
         candidate=*cursor++;
         if(candidate) {
             type97=0x97;typeBB=0xBB;
             __asm__("" : "=r"(type97),"=r"(typeBB):"0"(type97),"1"(typeBB));
             do {
                 if((Actor18E30Field(candidate,short*,0x36)==0x175 || Actor18E30Field(candidate,short*,0x36)==type97 || Actor18E30Field(candidate,short*,0x36)==typeBB) && Actor18E30Helper4F334(owner+12,candidate+12)<512) {
                     Actor18E30Field(owner,unsigned char*,0x48)=2;
                     if(Actor18E30Field(candidate,short*,0x36)==type97) {
                         if(Actor18E30Helper3BFC0(candidate,Actor18E30Field(Actor18E30Field(candidate,void**,0),int*,8))) {
                             if(Actor18E30Helper3BFC0(owner,Actor18E30Field(Actor18E30Field(candidate,void**,0),int*,8)))
                                 Actor18E30Helper3BE70(Actor18E30Field(Actor18E30Field(candidate,void**,0),int*,8));
                             Actor18E30Field(Actor18E30Field(candidate,void**,0),int*,8)=-1;
                             goto deleteListCandidate;
                         }
                     }
                     if(Actor18E30Field(candidate,short*,0x36)==typeBB) {
                         register void *handle __asm__("$4")=Actor18E30Field(Actor18E30Field(candidate,void**,0),void**,8);
                         if(handle) Actor18E30Helper509E8(handle);
                     }
deleteListCandidate:
                     Actor18E30Helper55B18(candidate);
                     break;
                 }
                 candidate=*cursor++;
             } while(candidate);
         }
        }
        { register void *prepared __asm__("$4")=&frame.b.x;
          __asm__("" : "=r"(prepared) : "0"(prepared));
          currentPosition=owner+0xC;
          Actor18E30Helper4F178(prepared,currentPosition); }
        if (Actor18E30Field(Actor18E30Field(tag, void **, 4), unsigned char *, 0x48) & 0x80) {
            Actor18E30Field(tag, void **, 4) = 0;
        }
        selectedTarget = Actor18E30Field(tag, void **, 4);
        if (selectedTarget != 0) {
            Actor18E30Helper4F178(&frame.d.x, selectedTarget + 0xC);
            frame.d.z += 0x80;
            Actor18E30Helper4F1C8(&frame.c.x, &frame.d.x, currentPosition);
            frame.c.z += 0x100;
            Actor18E30Helper4E880(frame.c.x, frame.c.y, 0);
            { register int angle __asm__("$2")=Actor18E30Helper4E880(frame.c.x,frame.c.y,0);
              previousHeading=Actor18E30Field(owner,unsigned char*,0x46);
              turnDelta=(angle-previousHeading)&255; }
            if (turnDelta >= 0x81) {
                turnDelta -= 0x100;
            }
            absoluteDelta = turnDelta;
            if (turnDelta < 0) {
                absoluteDelta = -absoluteDelta;
            }
            stepValue = 0x82;
            if (absoluteDelta < 0x30) {
                stepValue = 0x96;
            }
            if(turnDelta < -2) {
                turnDelta=-2;
                __asm__("" : "=r"(turnDelta) : "0"(turnDelta));
            }
            if(turnDelta>=3) {
                turnDelta=2;
                __asm__("" : "=r"(turnDelta) : "0"(turnDelta));
            }
            nextHeading=previousHeading+turnDelta;
            Actor18E30Field(owner, unsigned char *, 0x46) = nextHeading;
        } else {
            stepValue = 0x96;
            Actor18E30Field(owner, unsigned char *, 0x48) = 0U;
        }
        Actor18E30Helper55D24(owner, 4);
        frame.c.x = stepValue;
        frame.c.y = 0;
        frame.c.z = 0;
        Actor18E30Helper4ED6C(owner + 0x20, &frame.c.x, &frame.c.x);
        updatedPosition = owner + 0xC;
        __asm__("" : "=r"(updatedPosition):"0"(updatedPosition));
        Actor18E30Helper4F194(updatedPosition, updatedPosition, &frame.c.x);
        if (Actor18E30Helper1830C(&frame.b.x, updatedPosition, 0, 0x110000, owner) != 0) {
            Actor18E30Helper4F178(updatedPosition, &frame.b.x);
            goto enterStateTwo;
        }
        if(Actor18E30Helper4F334(updatedPosition,Actor18E30D_80070328)<1024) {
            Actor18E30Player24|=1;
enterStateTwo:
            Actor18E30Field(owner,unsigned char*,0x48)=2;
        }
        if (Actor18E30Field(tag, void **, 8) != 0) {
            if ((Actor18E30Helper4F264(Actor18E30Field(owner, unsigned char *, 0x46), 0) < 0x20) || (Actor18E30Helper4F264(Actor18E30Field(owner, unsigned char *, 0x46), 0x80) < 0x20)) {
                Actor18E30Field(Actor18E30Field(tag, void **, 8), unsigned char *, 0x66) = 0xF4;
                return;
            }
            Actor18E30Field(Actor18E30Field(tag, void **, 8), signed char *, 0x66) = 7;
            return;
        }
        return;
    case 2:
        particleIndex = 0;
        particleAngle = rand() & 0xFF;
        particlePosition = owner + 0xC;
        particleVector=&frame.f.x;
        __asm__("" : "=r"(particleVector) : "0"(particleVector));
        __asm__("" : "=r"(particleVector),"=r"(particlePosition) : "0"(particleVector),"1"(particlePosition));
        { register short *base __asm__("$3")=Actor18E30D_80065920;
          register int offset __asm__("$2");
          __asm__("" : "=r"(base) : "0"(base));
          offset=particleAngle*2;
          cosineEntry=(short*)(offset+(int)base); }
        do {
            register int type __asm__("$4")=1;
            register int selector __asm__("$5")=0x37;
            register void *position __asm__("$6")=particlePosition;
            register int sample __asm__("$2");
            register void *vectorArgument __asm__("$7");
            register int (*emit)(int,int,void*,void*) __asm__("$3");
            __asm__("" : "=r"(type),"=r"(selector),"=r"(position) : "0"(type),"1"(selector),"2"(position));
            sample=*cosineEntry;
            emit=Actor18E30SpawnParticle;
            __asm__("" : "=r"(sample),"=r"(emit) : "0"(sample),"1"(emit));
            frame.f.x=sample>>7;
            __asm__ volatile("" : : : "memory");
            { register int offset __asm__("$2")=particleAngle*2;
              __asm__("" : "=r"(offset) : "0"(offset));
              sample=*(short*)((unsigned char*)&Actor18E30D_800658A0+offset); }
            __asm__("" : "=r"(sample) : "0"(sample) : "$7");
            vectorArgument=particleVector;
            __asm__("" : "=r"(vectorArgument) : "0"(vectorArgument));
            frame.f.z=0;
            __asm__ volatile("" : "=r"(sample) : "0"(sample) : "memory");
            frame.f.y=sample>>7;
            emit(type,selector,position,vectorArgument);
            if (particleIndex & 1) {
                Actor18E30Helper4F110(particleVector, 1);
                Actor18E30SpawnParticle(1, 0x37, particlePosition, particleVector);
            }
            cosineEntry += 0x20;
            particleIndex += 1;
            particleAngle += 0x20;
        } while (particleIndex < 8);
        probePosition = owner + 0xC;
        secondHit = Actor18E30Helper1BA30(probePosition, 0x400, 1, 0, 0, owner);
        if ((secondHit != 0) && (Actor18E30Helper18368(probePosition, secondHit + 0xC) == 0)) {
            Actor18E30Field(secondHit, int *, 0x18) = (int) (Actor18E30Field(secondHit, int *, 0x18) | 0x110000);
        }
        if ((Actor18E30D_8006C578 - Actor18E30D_8006C574) >= 0x15) {
            spawnedChild = Actor18E30SpawnMoby(0x146, owner);
            if (spawnedChild != 0) {
                Actor18E30Field(spawnedChild, signed char *, 0x47) = 8;
                Actor18E30Field(spawnedChild, signed char *, 0x4C) = 0x3F;
                Actor18E30Field(spawnedChild, signed char *, 0x4E) = 0x3F;
            }
        }
        finalHandle = Actor18E30Field(tag, void **, 8);
        if (finalHandle != 0) {
            Actor18E30Helper509E8(finalHandle);
        }
        Actor18E30Helper3BABC(owner, 1, 0);
removeOwner:
        Actor18E30Helper55B18(owner);
        break;
    }
}

#undef Actor18E30Field

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 403 instructions per copy are the acceptance authority.
 * Keep original field widths, integer arithmetic, stack matrix layout,
 * helper arguments, state fallthroughs and call order. Units, full helper
 * contracts, table meanings and caller cadence remain unresolved.
 * Empty constraints emit no instructions. The explicit nop preserves one
 * original rand call delay slot that GCC 2.7 otherwise fills with a move.
 * Falsifiable check: original linked words and every complete binary hash.
 */
#define Actor81438Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor81438func_80018368(void*,void*) __asm__("func_80018368");

int Actor81438func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");

int Actor81438func_800359A4(void*,int) __asm__("func_800359A4");

int Actor81438func_8003BABC(void*,int,int) __asm__("func_8003BABC");

int Actor81438func_8004E880(int,int,int) __asm__("func_8004E880");

int Actor81438func_8004EA90(void*,void*,int) __asm__("func_8004EA90");

int Actor81438func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");

int Actor81438func_8004F0E8(void*,int) __asm__("func_8004F0E8");

int Actor81438func_8004F110(void*,int) __asm__("func_8004F110");

int Actor81438func_8004F178(void*,void*) __asm__("func_8004F178");

int Actor81438func_8004F194(void*,void*,void*) __asm__("func_8004F194");

int Actor81438func_80055B18(void*) __asm__("func_80055B18");

int Actor81438rand(void) __asm__("rand");

extern short Actor81438D_800658A0[] __asm__("D_800658A0");

extern short Actor81438D_80065920[] __asm__("D_80065920");

extern int Actor81438D_8006C574 __asm__("D_8006C574");

extern int Actor81438D_8006C578 __asm__("D_8006C578");

extern int Actor81438D_8006C640 __asm__("D_8006C640");

extern int Actor81438D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char Actor81438D_8006E020[] __asm__("D_8006E020");

extern void *(*Actor81438SpawnMoby)(int,void*) __asm__("SpawnMoby");

extern int (*Actor81438SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");

void func_level_18_80081438(void *input) {
    register unsigned char *owner __asm__("$18")=input;

    struct {
        int sp18,sp1C,sp20,pad24;

        int sp28,sp2C,sp30,pad34;

        int sp38,sp3C,sp40,pad44;

        int sp48,sp4C,sp50,pad54;

        int matrix58[6];

        signed char sp70,sp71,sp72,pad73[5];

    } frame;

    register int (*particle3)(int,int,void*,void*) __asm__("$3");

    register void *call4 __asm__("$4");

    register int call5 __asm__("$5");

    register void *call6 __asm__("$6");

    register void *call7 __asm__("$7");

    register int work2 __asm__("$2");

    register int work3 __asm__("$3");

    register int scratch4 __asm__("$4");

    register unsigned char *player21 __asm__("$21");

    register int original800 __asm__("$23");

    register int constant112 __asm__("$22");

    register void *matrix21 __asm__("$21");

    register int *vector17 __asm__("$17");

    register int *vector16 __asm__("$16");

    int particleKind;

    register int *ownerPosition __asm__("$16");

    register int *particlePosition __asm__("$20");

    int positionZ;

    int positionY;

    int positionX;

    register int tableByteOffset __asm__("$16");

    register int selectedAngle __asm__("$16");

    register int firstParticleIndex __asm__("$19");

    register int spawnIndex __asm__("$19");

    register int matrixParticleIndex __asm__("$19");

    register int spawnOffset __asm__("$20");

    register int tableSelector __asm__("$21");

    register int firstRandom __asm__("$4");

    register int secondRandom __asm__("$8");

    register int firstBiasedRandom __asm__("$5");

    register int secondBiasedRandom __asm__("$9");

    unsigned char temp_v1;

    register void *state __asm__("$20");

    void *spawned146;

    register void *spawned21D __asm__("$17");

    void *spawned1E2;

    register void *timerPointer __asm__("$4");

    positionX = Actor81438Field(owner, int *, 0xC);

    state = Actor81438Field(owner, void **, 0);

    if ((positionX >= 0x400) && (positionY = Actor81438Field(owner, int *, 0x10), ((positionY < 0x400) == 0)) && (positionZ = Actor81438Field(owner, int *, 0x14), ((positionZ < 0x400) == 0)) && (positionX <= 0x3E800) && (positionY <= 0x3E800) && (positionZ <= 0x3E800)) {
        ownerPosition = owner + 0xC;

        Actor81438func_8004F178(&frame.sp18, ownerPosition);

        work2=Actor81438Field(owner,int*,12);
        work3=Actor81438Field(state,int*,0);

        __asm__("" : "=r"(work2),"=r"(work3) : "0"(work2),"1"(work3));

        work2+=work3;
        Actor81438Field(owner,int*,12)=work2;

        work2=Actor81438Field(owner, int *, 0x10);
        work3=Actor81438Field(state, int *, 4);

        __asm__("" : "=r"(work2),"=r"(work3) : "0"(work2),"1"(work3));

        work2+=work3;
        Actor81438Field(owner, int *, 0x10)=work2;

        scratch4=Actor81438Field(state, int *, 8);
        work3=Actor81438Field(owner, unsigned char *, 0x45);
        work2=Actor81438Field(owner, unsigned char *, 0x44);

        __asm__("" : "=r"(scratch4),"=r"(work3),"=r"(work2) : "0"(scratch4),"1"(work3),"2"(work2));

        work3+=2;
        Actor81438Field(owner, unsigned char *, 0x45)=work3;

        work3=Actor81438Field(owner, int *, 0x14);

        __asm__("" : "=r"(work3),"=r"(work2),"=r"(scratch4) : "0"(work3),"1"(work2),"2"(scratch4));

        work2+=5;
        Actor81438Field(owner, unsigned char *, 0x44)=work2;

        work2=Actor81438Field(owner, unsigned char *, 0x46);

        __asm__("" : "=r"(work2),"=r"(work3),"=r"(scratch4) : "0"(work2),"1"(work3),"2"(scratch4));

        work3+=scratch4;
        Actor81438Field(owner, int *, 0x14)=work3;

        work3=Actor81438Field(owner, unsigned char *, 0x48);

        __asm__("" : "=r"(work3),"=r"(work2) : "0"(work3),"1"(work2));

        work2+=3;
        Actor81438Field(owner, unsigned char *, 0x46)=work2;

        switch (work3) {                          /* irregular */
            case 0:
            call4=ownerPosition;

            __asm__ __volatile__("" ::: "$3");

            if ((Actor81438func_8001BA30(call4, 0x180, 1, 0, 0, owner) != 0) || (Actor81438func_80018368(&frame.sp18, ownerPosition) != 0)) {
                Actor81438Field(state, int *, 0) = 0;

                Actor81438Field(state, int *, 4) = 0;

                Actor81438Field(state, int *, 8) = 0;

                Actor81438func_8004F178(ownerPosition, &frame.sp18);

                Actor81438Field(owner, unsigned char *, 0x48) = 1U;

                Actor81438Field(state, int *, 0xC) = 6;

                return;

            }
            if (Actor81438func_800359A4(state + 0xC, 4) != 0) {
                Actor81438Field(owner, unsigned char *, 0x48) = 1U;

                Actor81438Field(state, int *, 0xC) = 6;

                case 1:
                firstParticleIndex = 0;

                tableSelector = Actor81438rand() & 0xFF;

                particlePosition = owner + 0xC;

                do {
                    tableByteOffset = tableSelector * 2;

                    firstRandom=Actor81438rand();

                    work3=*(short*)((unsigned char*)Actor81438D_80065920+tableByteOffset);

                    firstBiasedRandom=firstRandom;
                    work2=work3<<1;
                    work2+=work3;

                    __asm__("" : "=r"(firstRandom),"=r"(firstBiasedRandom),"=r"(work2),"=r"(work3) : "0"(firstRandom),"1"(firstBiasedRandom),"2"(work2),"3"(work3));

                    work3=work2<<4;

                    if(firstRandom<0)firstBiasedRandom=firstRandom+15;

                    work2=firstBiasedRandom>>4;
                    work2<<=4;
                    work2=firstRandom-work2;
                    work2=work3+work2;
                    work2>>=12;

                    frame.sp28=work2;

                    secondRandom=Actor81438rand();

                    work3=*(short*)((unsigned char*)Actor81438D_800658A0+tableByteOffset);

                    secondBiasedRandom=secondRandom;
                    work2=work3<<1;
                    work2+=work3;

                    __asm__("" : "=r"(secondRandom),"=r"(secondBiasedRandom),"=r"(work2),"=r"(work3) : "0"(secondRandom),"1"(secondBiasedRandom),"2"(work2),"3"(work3));

                    work3=work2<<4;

                    if(secondRandom<0)secondBiasedRandom=secondRandom+15;

                    call4=(void*)1;
                    call5=20;
                    call6=particlePosition;
                    call7=&frame.sp28;

                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(call7) : "0"(call4),"1"(call5),"2"(call6),"3"(call7));

                    work2=secondBiasedRandom>>4;
                    work2<<=4;
                    work2=secondRandom-work2;
                    work2=work3+work2;

                    particle3=Actor81438SpawnParticle;

                    __asm__("" : "=r"(particle3),"=r"(work2) : "0"(particle3),"1"(work2));

                    work2>>=12;
                    frame.sp2C=work2;
                    frame.sp30=0;

                    particle3((int)call4,call5,call6,call7);

                    if (firstParticleIndex & 1) {
                        Actor81438func_8004F110(&frame.sp28, 1);

                        Actor81438SpawnParticle(1, 0x14, particlePosition, &frame.sp28);

                    }
                    tableSelector += 0xA;

                    call4=(void*)6;
                    call5=70;
                    call6=particlePosition;
                    call7=(void*)16;

                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(call7) : "0"(call4),"1"(call5),"2"(call6),"3"(call7));

                    firstParticleIndex++;

                    Actor81438SpawnParticle((int)call4,call5,call6,call7);

                } while (firstParticleIndex < 0x18);

                if (((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15) && (Actor81438D_8006C7E8 >= 0x7531)) {
                    spawned146 = Actor81438SpawnMoby(0x146, owner);

                    if (spawned146 != 0) {
                        Actor81438Field(spawned146, signed char *, 0x47) = 7;

                    }
                }
                spawnIndex = 0;

                if ((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15) {
                    player21=Actor81438D_8006E020;

                    __asm__("" : "=r"(player21) : "0"(player21));

                    spawnOffset = 0;

                    loop_32:
                    if (Actor81438D_8006C7E8 >= 0x7531) {
                        spawned21D = Actor81438SpawnMoby(0x21D, owner);

                        if (spawned21D != 0) {
                            selectedAngle = Actor81438func_8004E880(Actor81438Field(owner, int *, 0xC) - Actor81438Field(player21, int *, 0), Actor81438Field(owner, int *, 0x10) - Actor81438Field(player21, int *, 4), 0);

                            work2=Actor81438rand();
                            selectedAngle+=64;

                            __asm__("" : "=r"(work2),"=r"(selectedAngle) : "0"(work2),"1"(selectedAngle));

                            work2&=31;
                            selectedAngle+=work2;
                            Actor81438Field(spawned21D,signed char*,0x46)=selectedAngle;

                            Actor81438Field(spawned21D, signed char *, 0x45) = (signed char) ((spawnOffset + (Actor81438rand() & 0x1E)) - 0xF);

                            Actor81438Field(spawned21D, signed char *, 0x47) = 8;

                            Actor81438Field(spawned21D, signed char *, 0x4C) = 0x2A;

                        }
                        spawnIndex += 1;

                        spawnOffset += 0x33;

                        if ((spawnIndex < 0x19) && ((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15)) {
                            goto loop_32;

                        }
                    }
                }
                __asm__ __volatile__("" ::: "$4");

                Actor81438func_8003BABC(owner, 0, 0);

                Actor81438Field(owner, unsigned char *, 0x48) = 2U;

                return;

            }
            break;

            case 2:
            if (Actor81438func_800359A4(state + 0xC, 4) != 0) {
                Actor81438func_8001BA30(ownerPosition, 0x800, 1, 0, 0x110000, owner);

                Actor81438Field(owner, unsigned char *, 0x48) = 3U;

                Actor81438Field(state, int *, 0xC) = 0x14;

                Actor81438Field(owner, signed char *, 0x41) = 0;

                Actor81438Field(owner, signed char *, 0x4C) = 0;

                Actor81438Field(owner, signed char *, 0x4D) = 0;

                case 3:
                original800=0x800;

                __asm__("" : "=r"(original800) : "0"(original800));

                matrixParticleIndex=0;

                matrix21=frame.matrix58;
                constant112=112;

                vector17=&frame.sp38;
                vector16=&frame.sp48;

                __asm__("" : "=r"(matrix21),"=r"(constant112),"=r"(vector17),"=r"(vector16) : "0"(matrix21),"1"(constant112),"2"(vector17),"3"(vector16));

                do {
                    frame.sp70 = 0;

                    frame.sp71 = Actor81438rand();

                    frame.sp72 = Actor81438rand();

                    Actor81438func_8004EA90(&frame.sp70, matrix21, 0);

                    work2=Actor81438rand();

                    /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                    __asm__ __volatile__("nop" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)vector17;
                    call6=vector17;

                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2));

                    work2&=31;
                    work2+=constant112;
                    frame.sp38=work2;

                    frame.sp3C = 0;

                    frame.sp40 = 0;

                    Actor81438func_8004ED6C(call4,(void*)call5,call6);

                    Actor81438func_8004F178(vector16, vector17);

                    Actor81438func_8004F0E8(vector16, 2);

                    __asm__("" : "=r"(owner) : "0"(owner));

                    Actor81438func_8004F194(vector16, vector16, owner + 0xC);

                    particleKind = 0x37;

                    if (original800 >= 0x401) {
                        particleKind = 0x14;

                    }
                    call4=(void*)1;
                    call5=particleKind;
                    call6=vector16;
                    call7=vector17;

                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(call7) : "0"(call4),"1"(call5),"2"(call6),"3"(call7));

                    matrixParticleIndex++;

                    Actor81438SpawnParticle((int)call4,call5,call6,call7);

                } while (matrixParticleIndex < 0x18);

                call4=(void*)6;

                __asm__("" : "=r"(owner), "=r"(call4) : "0"(owner), "1"(call4));

                Actor81438SpawnParticle((int)call4, 0x46, owner + 0xC, (int *)0x10);

                timerPointer = state + 0xC;

                if (!(Actor81438D_8006C640 & 1) && ((Actor81438D_8006C578 - Actor81438D_8006C574) >= 0x15) && (Actor81438D_8006C7E8 >= 0x7531)) {
                    spawned1E2 = Actor81438SpawnMoby(0x1E2, owner);

                    if (spawned1E2 != 0) {
                        Actor81438Field(spawned1E2, signed char *, 0x4C) = 0x2A;

                        Actor81438Field(spawned1E2, signed char *, 0x47) = 0xA;

                    }
                    __asm__("" : "=r"(state) : "0"(state));

                    timerPointer = state + 0xC;

                }
                if (Actor81438func_800359A4(timerPointer, 4) != 0) {
                    goto block_51;

                }
            }
            break;

        }
    } else {
        block_51:
        Actor81438func_80055B18(owner);

    }
}

#undef Actor81438Field

/* Original SCUS-94467 Rev0 80081A84..80081E24, 232 words.
 * Reuses Rev1 raw601 branch/helper evidence; every numeric operation below
 * is checked against Rev0 words. Rev1 Python direction *3 is not reused:
 * Rev0 SLL4/SUBU proves *15. Raw coordinates are bounded1024..256000;
 * products retain low32 bits, divisions are signed /35, shifts are signed.
 * Units, table producers, helper effects and caller cadence remain unresolved.
 * Instruction-free constraints retain native compiler scheduling/lifetimes.
 * AI-generated reconstruction; not yet human reviewed. */
typedef struct { Vector3D delta; int timer; } DecodedRaw601Tag;
typedef struct { Vector3D oldPosition; int pad24; Vector3D particlePosition; int pad34; Vector3D direction; int pad44; int reserved48[4]; } DecodedRaw601Work;
extern unsigned char DecodedRaw601Player[] __asm__("D_80070328");
extern Moby* D_8006C550;
extern void* DecodedRaw601PlayerLink __asm__("D_80070328+0x250");
extern int DecodedRaw601PlayerFlags __asm__("D_80070328+0x24");
static __inline__ int DecodedRaw601Quotient(int numerator) { return numerator / 35; }
extern short D_80065920[], D_800658A0[];
int func_8004F334(Vector3D*,Vector3D*);
int func_8001830C(Vector3D*,Vector3D*,int,int,Moby*);
void func_80055B18(Moby*);
void func_level_18_80081A84(Moby* argument) {
    DecodedRaw601Work work;
    register Moby* moby __asm__("$18") = argument;
    register DecodedRaw601Tag* tag __asm__("$16");
    register int x __asm__("$6") = moby->position.x;
    register int y __asm__("$5");
    register int z __asm__("$4");
    int intensity;
    register void* retained __asm__("$17");
    register int opposite __asm__("$19");
    register int heading __asm__("$16");
    register int maximum __asm__("$3");
    char* particle;
    __asm__("" : "=r"(moby) : "0"(moby));
    tag = moby->mobyTag;
    __asm__("" : "=r"(tag) : "0"(tag), "r"(x));
    moby->size = 32;
    if (x < 1024) goto cleanup;
    y = moby->position.y;
    if (y < 1024) goto cleanup;
    z = moby->position.z;
    if (z < 1024) goto cleanup;
    maximum = 256000;
    __asm__("" : "=r"(maximum) : "0"(maximum));
    {
        register int outside __asm__("$2");
        outside = x > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
        outside = y > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
        outside = z > maximum;
        __asm__("" : "=r"(outside) : "0"(outside));
        if (outside) goto cleanup;
    }
    {
        register int numerator __asm__("$2") = tag->timer * 255;
        __asm__("" : "=r"(numerator) : "0"(numerator));
        intensity = DecodedRaw601Quotient(numerator);
    }
    if (intensity >= 256) intensity = 255;
    else if (intensity < 0) intensity = 0;
    /* Retail computes this secondary quotient before the callback although
     * its result is not subsequently consumed in this body. Keep the native
     * signed division and its fresh timer read; the constraint emits no code. */
    {
        register int numerator __asm__("$2") = tag->timer * 15;
        register int secondary __asm__("$3");
        __asm__("" : "=r"(numerator) : "0"(numerator));
        secondary = DecodedRaw601Quotient(numerator);
        __asm__ volatile ("" : : "r"(secondary));
    }
    moby->colour.r = intensity;
    moby->colour.g = 0;
    moby->colour.b = 0;
    moby->colour.a = 63;
    SpawnParticle(1,12,(Vector3D*)moby,(Vector3D*)4);
    retained = &moby->position;
    func_8004F178(&work.oldPosition,retained);
    moby->position.x += tag->delta.x;
    moby->position.y += tag->delta.y;
    moby->position.z += tag->delta.z;
    if (moby->state == 0) {
        int distance;
        retained = *(void**)DecodedRaw601PlayerLink;
        distance = func_8004F334(&moby->position,(Vector3D*)DecodedRaw601Player);
        if (moby->state != 98 && distance < 512) {
            if (!(*(int*)((char*)retained + 0x1C) & 1))
                DecodedRaw601PlayerFlags |= 1;
            moby->state = 98;
            goto done;
        }
        if (func_800359A4(&tag->timer,4) || func_8001830C(&work.oldPosition,&moby->position,0,0,moby))
            moby->state = 98;
        {
            register int result __asm__("$2") = func_8004E880(tag->delta.x,tag->delta.y,0);
            register int low __asm__("$4") = 0;
            register int high __asm__("$5") = 14;
            __asm__("" : "=r"(low), "=r"(high) : "0"(low), "1"(high), "r"(result));
            heading = result;
            heading += func_800363DC(low,high);
        }
        opposite = heading;
        __asm__ volatile ("" : : "r"(opposite));
        retained = &work.particlePosition;
        func_8004F178(retained,&moby->position);
        /* Preserve both signed table lanes and the raw particle packet writes. */
        {
            register int primaryIndex __asm__("$3") = opposite & 255;
            register int oppositeIndex __asm__("$7");
            register int cosine __asm__("$5");
            register int kind __asm__("$4");
            register int selector __asm__("$5");
            register Vector3D* positionArg __asm__("$6");
            register char* (*spawn)(int,int,Vector3D*,Vector3D*) __asm__("$8");
            __asm__("" : "=r"(primaryIndex) : "0"(primaryIndex));
            opposite = heading - 128;
            __asm__("" : "=r"(opposite) : "0"(opposite));
            primaryIndex *= 2;
            kind = 1;
            __asm__("" : "=r"(kind) : "0"(kind));
            oppositeIndex = (opposite & 255) * 2;
            __asm__("" : "=r"(primaryIndex), "=r"(oppositeIndex) : "0"(primaryIndex), "1"(oppositeIndex));
            cosine = *(short*)((char*)D_80065920 + primaryIndex);
            spawn = SpawnParticle;
            __asm__("" : "=r"(cosine), "=r"(spawn) : "0"(cosine), "1"(spawn));
            work.direction.x = (cosine * 15) >> 11;
            {
                register int sine __asm__("$3") = *(short*)((char*)D_800658A0 + primaryIndex);
                __asm__("" : "=r"(sine) : "0"(sine));
                positionArg = retained;
                __asm__("" : "=r"(positionArg) : "0"(positionArg));
                work.direction.z = 0;
                __asm__ volatile ("" : : : "memory");
                work.direction.y = (sine * 15) >> 11;
            }
            {
                register int sample __asm__("$3") = *(short*)((char*)D_80065920 + oppositeIndex);
                __asm__("" : "=r"(sample) : "0"(sample) : "$5");
                selector = 13;
                __asm__("" : "=r"(selector) : "0"(selector), "r"(sample));
                work.particlePosition.x += (sample * 5) >> 9;
            }
            {
                register int sample __asm__("$2") = *(short*)((char*)D_800658A0 + oppositeIndex);
                register int product __asm__("$3") = sample * 5;
                __asm__("" : "=r"(product) : "0"(product));
                work.particlePosition.y += product >> 9;
            }
            particle = spawn(kind,selector,positionArg,&work.direction);
        }
        particle[2] = 14;
        particle[10] += 56;
    }
done:
    if (moby->state != 98) return;
cleanup:
    {
        Moby** owner = D_8006C550[moby->linkedMoby].mobyTag;
        if (*owner == moby) *owner = 0;
    }
    func_80055B18(moby);
}

typedef struct { short mode, parentClass; int offsetZ; Moby* parent; } DecodedParentFollowRecord;
extern unsigned short D_8006E040, D_8006E03E;
void func_80055B18(Moby*);
void func_80055F14(Moby*, int, Vector3D*);
void func_level_18_80081E24(Moby* moby) {
    DecodedParentFollowRecord* tag;
    moby->angle.yaw = ((short)D_8006E040 >> 4) - 0x80;
    moby->angle.pitch = D_8006E03E >> 4;
    tag = moby->mobyTag;
    if (tag->mode == 1) {
        /* Retail continues this routine after the deletion helper call. */
        if (tag->parent->state >= 0x80 || tag->parent->mobyClass != tag->parentClass)
            func_80055B18(moby);
        if (tag->parent->mobyClass == 0x170)
            func_80055F14(spyro.critterMobyPtr, 0, &moby->position);
        else
            func_8004F178(&moby->position, &tag->parent->position);
        moby->position.z += tag->offsetZ;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0.
* Original asm/nonmatchings/overlays/level_18/moby/func_level_18_80081F14.s; SHA256 127212ff2b167e1cc4b47e363366cc2a700d8558bedd1821534d2e2f70162221.
* 726 original instructions and six owned dispatch words.
* Original B0 frame: raw slots20..80; saved16..23 at88..A4; RA A8.
* Entry owner18/private20 and player+250 pointer16 lifetimes are retained.
* An initialized linked-status19 observer clobbers only dead17 before its
* original zero producer. The compiler retains the original saved17 order.
* Signed table LH results are full words before SRA5. Helper arguments are
* constructed at their original producers; dead4/5/6 boundaries precede
* replacement producers. Initialized empty constraints emit no CPU code.
* Record index2/base4, signed dividend3/remainder4 and return2 remain live
* through the original divide; player16 copies to argument5 before result16.
* The halfword index store is evaluated before helper entry, as in the
* original JAL delay slot. Particle constants, byte offsets and signed
* samples retain original ordering. No compiler or matching gate changes.
* Confirmed only by complete instruction/data/target and retail hash gates.
* Helper meanings, physical units/fixed point, caller/frame cadence and
* synchronized runtime behavior remain unresolved. Cadence per invocation;
* frame frequency unknown. No browser or subsystem completion claim. */
#define Level18_81F14_F(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char Level18_81F14_Player[] __asm__("D_80070328");
extern unsigned char Level18_81F14_Cos[] __asm__("D_80065920"),Level18_81F14_Sin[] __asm__("D_800658A0");
extern void ** volatile Level18_81F14_Player250 __asm__("D_80070328 + 0x250");
extern int Level18_81F14_Models __asm__("D_8006C550");
extern int (*Level18_81F14_Particle)() __asm__("SpawnParticle");
extern int (*Level18_81F14_Indirect)() __asm__("unk_ovlheader_80074320");
int Level18_81F14_H34F40() __asm__("func_80034F40");
int Level18_81F14_H35030() __asm__("func_80035030");
int Level18_81F14_H3573C() __asm__("func_8003573C");
int Level18_81F14_H3585C() __asm__("func_8003585C");
int Level18_81F14_H35DDC() __asm__("func_80035DDC");
int Level18_81F14_H3617C() __asm__("func_8003617C");
int Level18_81F14_H3645C() __asm__("func_8003645C");
int Level18_81F14_H369B8() __asm__("func_800369B8");
int Level18_81F14_H3BA00() __asm__("func_8003BA00");
int Level18_81F14_H3BABC() __asm__("func_8003BABC");
int Level18_81F14_H4E880() __asm__("func_8004E880");
int Level18_81F14_H4F110() __asm__("func_8004F110");
int Level18_81F14_H4F178() __asm__("func_8004F178");
int Level18_81F14_H4F194() __asm__("func_8004F194");
int Level18_81F14_H4F334() __asm__("func_8004F334");
int Level18_81F14_H55B18() __asm__("func_80055B18");
int Level18_81F14_H55D24() __asm__("func_80055D24");
int Level18_81F14_H55F14() __asm__("func_80055F14");
int Level18_81F14_Rand() __asm__("rand");
struct Level18_81F14_Frame {
    int sp20;
    int sp24;
    int sp28;
    char pad2C[4];
    int sp30;
    int sp34;
    int sp38;
    char pad3C[4];
    int sp40;
    int sp44;
    char pad48[8];
    int sp50;
    int sp54;
    int sp58;
    char pad5C[4];
    int sp60;
    int sp64;
    int sp68;
    char pad6C[4];
    int sp70;
    char pad74[4];
    int sp78;
    int sp7C;
    int sp80;
}
;
void func_level_18_80081F14(void *input) {
    struct Level18_81F14_Frame frame;
    register void *callbackArg4 __asm__("4");
    register int callbackArg5 __asm__("5");
    register void* moby __asm__("$18")=input;
    short temp_a1_2;
    unsigned char *player250Pointer;
    register int linkedMobyIndex __asm__("5");
    register int temp_a3 __asm__("$7");
    register unsigned char* table21 __asm__("$21");
    int temp_s0_2;
    int temp_s0_3;
    register int temp_s0_4 __asm__("$16");
    register int temp_s3_2 __asm__("$19");
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_6;
    register int temp_v0_7 __asm__("$2");
    int temp_v1;
    int temp_v1_2;
    int temp_v1_5;
    int temp_v1_7;
    int temp_v1_9;
    int var_a1;
    int var_a1_2;
    int var_s0;
    int private14Matches;
    register int linkedStatus __asm__("$19");
    int var_s3_2;
    int var_s5;
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    unsigned int temp_v0_4;
    unsigned int temp_v0_5;
    unsigned int temp_v1_6;
    unsigned int temp_v1_8;
    register int temp_v1_4 __asm__("$3");
    void *temp_a0;
    void *temp_s0_5;
    void *temp_s1;
    void *temp_s1_2;
    register void * recordPointer __asm__("$17");
    void *temp_s3;
    register void * privateData __asm__("$20");
    void *positionPointer;
    void *playerLinkedData;
    void *temp_v1_3;
    __asm__("" : "=r"(moby) : "0"(moby));
    linkedStatus = 0;
    __asm__("" : "=r"(linkedStatus) : "0"(linkedStatus) : "17");
    player250Pointer = Level18_81F14_Player + 0x250;
    privateData = Level18_81F14_F(moby, void **, 0);
    playerLinkedData = *Level18_81F14_Player250;
    __asm__("" : "=r"(player250Pointer) : "0"(player250Pointer));
    private14Matches = 0;
    if (Level18_81F14_F(player250Pointer, void ** volatile *, 0) != 0) {
        if (Level18_81F14_F(privateData, int *, 0x14) == -0x5D4) {
            private14Matches = 1;
            Level18_81F14_F(moby, int *, 8) = 0;
        }
        Level18_81F14_H55D24(moby, 5);
        temp_v0 = Level18_81F14_H4F334(moby + 0xC, player250Pointer - 0x250);
        if ((temp_v0 < 0x400) || (Level18_81F14_F(Level18_81F14_Player, int *, 0x138) == moby)) {
            if (private14Matches != 0) {
                Level18_81F14_F(moby, unsigned char *, 0x48) = 4U;
            }
            else {
                Level18_81F14_H34F40(moby, 3);
                Level18_81F14_F(moby, unsigned char *, 0x48) = 3U;
                Level18_81F14_F(privateData, int *, 0x14) = 0xC8;
                temp_s0_2 = Level18_81F14_H4E880(Level18_81F14_F(moby, int *, 0xC) - Level18_81F14_F(player250Pointer, int *, -0x250), Level18_81F14_F(moby, int *, 0x10) - Level18_81F14_F(Level18_81F14_Player, int *, 4), 0);
                temp_v0_2 = Level18_81F14_Rand();
                var_a1 = temp_v0_2;
                if (temp_v0_2 < 0) {
                    var_a1 = temp_v0_2 + 0x3F;
                }
                Level18_81F14_F(privateData, int *, 0x18) = Level18_81F14_H3617C(temp_s0_2, (temp_v0_2 - ((var_a1 >> 6) << 6)) - 0x20);
                temp_v1 = Level18_81F14_F(privateData, int *, 0x10);
                Level18_81F14_F(privateData, int *, 0x1C) = 0x32;
                if (temp_v1 != -1) {
                    temp_a0 = Level18_81F14_Models + (temp_v1 * 0x58);
                    linkedStatus = 1;
                    if (Level18_81F14_F(temp_a0, unsigned char *, 0x48) == 4) {
                        Level18_81F14_F(temp_a0, unsigned char *, 0x48) = 1U;
                        goto block_12;
                    }
                }
                else {
                block_12:
                    linkedStatus = 1;
                }
            }
        }
        if ((Level18_81F14_F(moby, int *, 0x18) & 0x190000) && (Level18_81F14_F(moby, unsigned char *, 0x48) != 4) && (private14Matches == 0)) {
            Level18_81F14_H34F40(moby, 3);
            Level18_81F14_F(moby, unsigned char *, 0x48) = 3U;
            Level18_81F14_F(privateData, int *, 0x14) = 0xC8;
            temp_s0_3 = Level18_81F14_H4E880(Level18_81F14_F(moby, int *, 0xC) - Level18_81F14_F(Level18_81F14_Player, int *, 0), Level18_81F14_F(moby, int *, 0x10) - Level18_81F14_F(Level18_81F14_Player, int *, 4), 0);
            temp_v0_3 = Level18_81F14_Rand();
            var_a1_2 = temp_v0_3;
            if (temp_v0_3 < 0) {
                var_a1_2 = temp_v0_3 + 0x3F;
            }
            Level18_81F14_F(privateData, int *, 0x18) = Level18_81F14_H3617C(temp_s0_3, (temp_v0_3 - ((var_a1_2 >> 6) << 6)) - 0x20);
            temp_v1_2 = Level18_81F14_F(privateData, int *, 0x10);
            Level18_81F14_F(privateData, int *, 0x1C) = 0x32;
            if (temp_v1_2 != -1) {
                temp_v1_3 = Level18_81F14_Models + (temp_v1_2 * 0x58);
                linkedStatus = 1;
                if (Level18_81F14_F(temp_v1_3, unsigned char *, 0x48) == 4) {
                    Level18_81F14_F(temp_v1_3, unsigned char *, 0x48) = 1U;
                    goto block_21;
                }
            }
            else {
            block_21:
                linkedStatus = 1;
            }
        }
        temp_v1_4 = Level18_81F14_F(moby, unsigned char *, 0x48);
        Level18_81F14_F(moby, int *, 0x18) = 0;
        switch (temp_v1_4) {
        case 0:
            temp_v1_5 = Level18_81F14_F(privateData, int *, 0x10);
            if (temp_v1_5 != -1) {
                temp_s1 = Level18_81F14_Models + (temp_v1_5 * 0x58);
                Level18_81F14_H55F14(moby, 0, &frame.sp20);
                Level18_81F14_H55F14(moby, 1, &frame.sp30);
                temp_v0_4 = frame.sp20 + frame.sp30;
                frame.sp30 = (int) (temp_v0_4 + (temp_v0_4 >> 0x1F)) >> 1;
                temp_v1_6 = frame.sp24 + frame.sp34;
                frame.sp34 = (int) (temp_v1_6 + (temp_v1_6 >> 0x1F)) >> 1;
                frame.sp38 = (int) (frame.sp28 + frame.sp38) / 2;
                {
                    register int sample2 __asm__("2");
                    register void *call4 __asm__("4");
                    register void *call5 __asm__("5");
                    register void *call6 __asm__("6");
                    sample2 = *(short *)(Level18_81F14_Cos + (Level18_81F14_F(moby, unsigned char *, 0x46) * 2));
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "5");
                    call5 = &frame.sp20;
                    __asm__ volatile("" : "=r"(sample2), "=r"(call5) : "0"(sample2), "1"(call5));
                    frame.sp20 = sample2 >> 5;
                    sample2 = Level18_81F14_F(moby, unsigned char *, 0x46);
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "6");
                    call6 = &frame.sp30;
                    __asm__ volatile("" : "=r"(sample2), "=r"(call6) : "0"(sample2), "1"(call6));
                    sample2 = *(short *)(Level18_81F14_Sin + (sample2 * 2));
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "4");
                    call4 = temp_s1 + 0xC;
                    __asm__ volatile("" : "=r"(sample2), "=r"(call4) : "0"(sample2), "1"(call4) : "memory");
                    frame.sp28 = 0;
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "memory");
                    frame.sp24 = sample2 >> 5;
                    Level18_81F14_H4F194(call4,call5,call6);
                }
                if (Level18_81F14_F(temp_s1, unsigned char *, 0x48) != 0) {
                    Level18_81F14_F(temp_s1, unsigned char *, 0x48) = 4U;
                }
                Level18_81F14_F(temp_s1, unsigned char *, 0x46) = (unsigned char) Level18_81F14_F(moby, unsigned char *, 0x46);
                Level18_81F14_H55D24(temp_s1, 5);
            }
            if ((Level18_81F14_F(Level18_81F14_Player, void ***, 0x250) == 0) || ((Level18_81F14_F(playerLinkedData, int *, 0x1C) & 0x21) != 0x20)) {
                if ((temp_v0 < 0x1B58) || (linkedStatus != 0) || (Level18_81F14_F(privateData, int *, 0x20) != -1)) {
                    linkedMobyIndex = Level18_81F14_F(privateData, int *, 0x20);
                    if (linkedMobyIndex == -1) goto noLinkedMobyIndex;
                    if (Level18_81F14_F(((linkedMobyIndex * 0x58) + Level18_81F14_Models), unsigned char *, 0x48) == 0) return;
                    callbackArg4 = moby;
                    __asm__("" : "=r"(callbackArg4) : "0"(callbackArg4));
                    callbackArg5 = 1;
                    goto callback597;
                noLinkedMobyIndex:
                    callbackArg4 = moby;
                    __asm__("" : "=r"(callbackArg4) : "0"(callbackArg4));
                    callbackArg5 = 1;
                    goto callback597;
                }
                else {
                    __asm__("" : "=r"(linkedStatus) : "0"(linkedStatus));
                    Level18_81F14_H3573C(moby, 0xB, 0, 0);
                    return;
                }
            }
            break;
        case 1:
            var_s5 = 0;
            Level18_81F14_Indirect(moby, 0x10, privateData + 0xC);
            temp_v1_7 = Level18_81F14_F(privateData, int *, 0x10);
            if (temp_v1_7 != -1) {
                temp_s3 = Level18_81F14_Models + (temp_v1_7 * 0x58);
                Level18_81F14_H55F14(moby, 0, &frame.sp50);
                Level18_81F14_H55F14(moby, 1, &frame.sp60);
                temp_v0_5 = frame.sp50 + frame.sp60;
                frame.sp60 = (int) (temp_v0_5 + (temp_v0_5 >> 0x1F)) >> 1;
                temp_v1_8 = frame.sp54 + frame.sp64;
                frame.sp64 = (int) (temp_v1_8 + (temp_v1_8 >> 0x1F)) >> 1;
                frame.sp68 = (int) (frame.sp58 + frame.sp68) / 2;
                {
                    register int sample2 __asm__("2");
                    register void *call4 __asm__("4");
                    register void *call5 __asm__("5");
                    register void *call6 __asm__("6");
                    sample2 = *(short *)(Level18_81F14_Cos + (Level18_81F14_F(moby, unsigned char *, 0x46) * 2));
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "5");
                    call5 = &frame.sp50;
                    __asm__ volatile("" : "=r"(sample2), "=r"(call5) : "0"(sample2), "1"(call5));
                    frame.sp50 = sample2 >> 5;
                    sample2 = Level18_81F14_F(moby, unsigned char *, 0x46);
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "6");
                    call6 = &frame.sp60;
                    __asm__ volatile("" : "=r"(sample2), "=r"(call6) : "0"(sample2), "1"(call6));
                    sample2 = *(short *)(Level18_81F14_Sin + (sample2 * 2));
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "4");
                    call4 = temp_s3 + 0xC;
                    __asm__ volatile("" : "=r"(sample2), "=r"(call4) : "0"(sample2), "1"(call4) : "memory");
                    frame.sp58 = 0;
                    __asm__ volatile("" : "=r"(sample2) : "0"(sample2) : "memory");
                    frame.sp54 = sample2 >> 5;
                    Level18_81F14_H4F194(call4,call5,call6);
                }
                if (Level18_81F14_F(temp_s3, unsigned char *, 0x48) != 0) {
                    Level18_81F14_F(temp_s3, unsigned char *, 0x48) = 4U;
                }
                Level18_81F14_F(temp_s3, unsigned char *, 0x46) = (unsigned char) Level18_81F14_F(moby, unsigned char *, 0x46);
                Level18_81F14_H55D24(temp_s3, 5);
            }
            if ((Level18_81F14_F(Level18_81F14_Player, void ***, 0x250) == 0) || ((Level18_81F14_F(playerLinkedData, int *, 0x1C) & 0x21) != 0x20)) {
                temp_s1_2 = Level18_81F14_F(privateData, void **, 0);
                if ((temp_s1_2 != 0) && (temp_a1_2 = Level18_81F14_F(temp_s1_2, signed short *, 2), (temp_a1_2 != Level18_81F14_F(temp_s1_2, signed short *, 0)))) {
                    Level18_81F14_H4F178(&frame.sp40, Level18_81F14_F(temp_s1_2, int *, 0xC) + (temp_a1_2 * 0x10));
                    Level18_81F14_H3585C(moby, Level18_81F14_H4E880(frame.sp40 - Level18_81F14_F(moby, int *, 0xC), frame.sp44 - Level18_81F14_F(moby, int *, 0x10), 0) & 0xFF, 0xB, 0, 0, 0);
                    Level18_81F14_H35DDC(moby, (Level18_81F14_F(privateData, int *, 8) * 0xA) + 0xB9, 0, 0x300, 0x21);
                    if (Level18_81F14_H4F334(moby + 0xC, &frame.sp40) < 0xC0) {
                        Level18_81F14_F(temp_s1_2, signed short *, 2) = (short) ((unsigned short) Level18_81F14_F(temp_s1_2, signed short *, 2) + 1);
                    }
                }
                else {
                    var_s5 = 1;
                }
                if (var_s5 != 0) {
                    recordPointer = Level18_81F14_F(privateData, void **, 4);
                    if (recordPointer != 0) {
                        Level18_81F14_H3645C(moby + 0xC, recordPointer, &frame.sp70);
                        {
                            register int route4 __asm__("4");
                            register void *player16 __asm__("16");
                            register void *player5 __asm__("5");
                            register int returned2 __asm__("2");
                            register int routeBase3 __asm__("3");
                            var_v0 = frame.sp70;
                            route4 = Level18_81F14_F(recordPointer,int*,0xC);
                            __asm__ volatile("" : : "r"(var_v0), "r"(route4));
                            if (var_v0 != 0) var_v0 -= 1;
                            else var_v0 = Level18_81F14_F(recordPointer,signed short*,0) - 1;
                            var_v0 <<= 4;
                            route4 += var_v0;
                            __asm__ volatile("" : "=r"(route4) : "0"(route4));
                            player16 = Level18_81F14_Player;
                            returned2 = Level18_81F14_H4F334(route4,player16);
                            player5 = player16;
                            __asm__("" : "=r"(returned2), "=r"(player5) : "0"(returned2), "1"(player5));
                            temp_s3_2 = returned2;
                            route4 = frame.sp70;
                            routeBase3 = Level18_81F14_F(recordPointer,int*,0xC);
                            __asm__("" : "=r"(route4), "=r"(routeBase3) : "0"(route4), "1"(routeBase3));
                            route4 <<= 4;
                            returned2 = Level18_81F14_H4F334(routeBase3 + route4,player5);
                            {
                                register int dividend3 __asm__("3");
                                dividend3 = frame.sp70;
                                route4 = Level18_81F14_F(recordPointer,signed short*,0);
                                dividend3 += 1;
                                route4 = dividend3 % route4;
                            }
                            __asm__ volatile("" : "=r"(returned2), "=r"(player16) : "0"(returned2), "1"(player16), "r"(route4));
                            player5 = player16;
                            __asm__("" : "=r"(returned2), "=r"(player5) : "0"(returned2), "1"(player5));
                            temp_s0_4 = returned2;
                            routeBase3 = Level18_81F14_F(recordPointer,int*,0xC);
                            __asm__("" : "=r"(routeBase3), "=r"(route4) : "0"(routeBase3), "1"(route4));
                            route4 <<= 4;
                            temp_v0_6 = Level18_81F14_H4F334(routeBase3 + route4,player5);
                        }
                        if (temp_s0_4 < temp_s3_2) {
                            temp_v0_7 = temp_v0_6 < temp_s3_2;
                            if (temp_v0_7 != 0) {
                                var_v0_2 = frame.sp70;
                                if (var_v0_2 != 0) var_v0_2 -= 1;
                                else var_v0_2 = Level18_81F14_F(recordPointer,signed short*,0) - 1;
                                frame.sp70 = var_v0_2;
                            }
                            else {
                                goto block_59;
                            }
                        }
                        else if (({ register int comparison2 __asm__("2"); comparison2 = temp_s0_4 < temp_v0_6; __asm__("" : "=r"(comparison2) : "0"(comparison2)); comparison2; })) {
                        block_59:
                            frame.sp70 = (int) (frame.sp70 + 1) % (short) Level18_81F14_F(recordPointer, signed short *, 0);
                        }
                        {
                            register void *vector4 __asm__("4");
                            register int selected3 __asm__("3");
                            register int base2 __asm__("2");
                            register int source5 __asm__("5");
                            vector4 = &frame.sp40;
                            selected3 = frame.sp70;
                            base2 = Level18_81F14_F(recordPointer,int*,0xC);
                            __asm__("" : "=r"(vector4), "=r"(selected3), "=r"(base2) : "0"(vector4), "1"(selected3), "2"(base2));
                            source5 = (selected3 << 16) >> 12;
                            source5 = base2 + source5;
                            __asm__ volatile("" : "=r"(source5), "=r"(selected3) : "0"(source5), "1"(selected3) : "memory");
                            Level18_81F14_H4F178(vector4, ({ Level18_81F14_F(recordPointer,signed short*,2) = selected3; source5; }));
                        }
                        if (Level18_81F14_H4F334(moby + 0xC, &frame.sp40) < 0xC0) {
                            Level18_81F14_H3573C(moby, 0xB, 0, 0);
                            goto block_65;
                        }
                        if (Level18_81F14_F(moby, unsigned char *, 0x4D) != 0) {
                            Level18_81F14_H3585C(moby, Level18_81F14_H4E880(frame.sp40 - Level18_81F14_F(moby, int *, 0xC), frame.sp44 - Level18_81F14_F(moby, int *, 0x10), 0) & 0xFF, 0xB, 0, 0, 0);
                            Level18_81F14_H35DDC(moby, (Level18_81F14_F(privateData, int *, 8) * 0xA) + 0xB9, 0, 0x300, 0x21);
                            goto block_65;
                        }
                        goto block_67;
                    }
                }
            block_65:
                if (Level18_81F14_F(moby, unsigned char *, 0x4D) != 0) {
                    if (Level18_81F14_H4F334(moby + 0xC, Level18_81F14_Player) >= 0x1F41) {
                    block_67:
                        goto block_68;
                    }
                }
                else {
                    goto block_68;
                }
            }
            else {
            block_68:
                Level18_81F14_H34F40(moby, 0);
                Level18_81F14_F(moby, unsigned char *, 0x48) = 0U;
                return;
            }
            break;
        case 2:
            temp_v1_9 = Level18_81F14_F(privateData, int *, 0x10);
            if (temp_v1_9 != -1) {
                temp_s0_5 = Level18_81F14_Models + (temp_v1_9 * 0x58);
                if (Level18_81F14_F(temp_s0_5, unsigned char *, 0x48) == 2) {
                    Level18_81F14_F(moby, unsigned char *, 0x48) = 4U;
                    return;
                }
                if (Level18_81F14_H4F334(moby + 0xC, temp_s0_5 + 0xC) < 0x300) {
                    callbackArg4 = moby;
                    __asm__("" : "=r"(callbackArg4) : "0"(callbackArg4));
                    callbackArg5 = 1;
                    Level18_81F14_F(temp_s0_5, unsigned char *, 0x48) = 4U;
                callback597:
                    Level18_81F14_H34F40(callbackArg4, callbackArg5);
                    Level18_81F14_F(moby, unsigned char *, 0x48) = 1U;
                    return;
                }
                Level18_81F14_H3585C(moby, Level18_81F14_H4E880(Level18_81F14_F(temp_s0_5, int *, 0xC) - Level18_81F14_F(moby, int *, 0xC), Level18_81F14_F(temp_s0_5, int *, 0x10) - Level18_81F14_F(moby, int *, 0x10), 0), 0xB, 0, 0, 0);
                Level18_81F14_H35DDC(moby, (Level18_81F14_F(privateData, int *, 8) * 0xA) + 0xB9, 0, 0x300, 0x21);
                return;
            }
            break;
        case 3:
            if (Level18_81F14_H35030(moby, privateData + 0x14, Level18_81F14_F(privateData, int *, 0x18), privateData + 0x1C, 8, 0x10, 0x400, 0x23) == 3) {
                Level18_81F14_F(moby, unsigned char *, 0x48) = 2U;
                Level18_81F14_H34F40(moby, 2);
                return;
            }
            break;
        case 4:
            var_s0 = 0;
            var_s3_2 = Level18_81F14_Rand();
            table21=Level18_81F14_Cos;
            __asm__("" : "=r"(table21):"0"(table21));
            positionPointer = moby + 0xC;
            do {
                {
                    register int literal4 __asm__("4");
                    register int literal5 __asm__("5");
                    register void *position6 __asm__("6");
                    register int sample3 __asm__("3");
                    literal4 = 1;
                    literal5 = 0x37;
                    __asm__ volatile("" : "=r"(literal4), "=r"(literal5) : "0"(literal4), "1"(literal5));
                    temp_a3 = (var_s3_2 & 0xFF) * 2;
                    sample3 = *(short *)((int)temp_a3 + (int)table21);
                    __asm__ volatile("" : "=r"(sample3) : "0"(sample3) : "6");
                    position6 = positionPointer;
                    __asm__ volatile("" : "=r"(sample3), "=r"(position6) : "0"(sample3), "1"(position6));
                    frame.sp78 = (sample3 * 3) >> 8;
                    sample3 = *(short *)(Level18_81F14_Sin + temp_a3);
                    temp_a3 = (int)&frame.sp78;
                    __asm__ volatile("" : "=r"(sample3), "=r"(temp_a3) : "0"(sample3), "1"(temp_a3) : "memory");
                    frame.sp80 = 0;
                    __asm__ volatile("" : "=r"(sample3) : "0"(sample3) : "memory");
                    frame.sp7C = (sample3 * 3) >> 8;
                    Level18_81F14_Particle(literal4,literal5,position6,temp_a3);
                }
                if (var_s0 & 1) {
                    Level18_81F14_H4F110(&frame.sp78, 1);
                    Level18_81F14_Particle(1, 0x37, positionPointer, &frame.sp78);
                }
                var_s0 += 1;
                var_s3_2 += 0x20;
            }
            while ((unsigned int) (var_s0 & 0xFF) < 8U);
            Level18_81F14_H3BABC(moby, 0, 0);
            Level18_81F14_H55D24(moby, 4);
            Level18_81F14_H3BA00(moby);
            Level18_81F14_H369B8(moby, 0x30);
            Level18_81F14_H55B18(moby);
            break;
        }
    }
    else {
    }
}
#undef Level18_81F14_F


extern Spyro D_80070328;
extern Moby* D_8006C550;
int func_8004F334(Vector3D*, Vector3D*);
void func_80055B18(Moby*);
extern int D_8006E344;
extern unsigned char D_80071599;

void func_level_18_80082A6C(Moby *moby) {
    Moby *linked;
    int *actorIndex;
    unsigned char flag;

    flag = D_80071599;
    actorIndex = moby->mobyTag;
    if ((flag == 1) && (func_8004F334(&moby->position, &D_80070328.position) < 0x800) && (D_8006E344 != flag)) {
        linked = &D_8006C550[*actorIndex];
        func_80013D44(&linked->position, (int) linked->angle.yaw, 0, 0x98);
        func_80055B18(moby);
    }
}


typedef struct { int kind, listIndex, retainSave; } DecodedPlayerGateTag;
typedef struct { unsigned char reserved00[0x1C]; unsigned int flags; } DecodedPlayerGateActorTag;
extern Moby* volatile DecodedPlayerGateActor __asm__("D_80070328 + 0x250");
extern int DecodedPlayerGateState __asm__("D_80070328 + 0x48");
extern int D_8006E538, D_8006E344;
extern Moby* D_8006C550;
extern unsigned short** DecodedPlayerGateLists __asm__("D_8006C730");
extern unsigned char DecodedPlayerGateSavepoint[] __asm__("D_8006D088");
void DecodedPlayerGateSave(void*) __asm__("func_8003B74C");
void func_level_18_80082B24(Moby* moby) {
    DecodedPlayerGateTag* tag = moby->mobyTag;
    Moby* actor = DecodedPlayerGateActor;
    Moby* checkedActor = DecodedPlayerGateActor;
    DecodedPlayerGateActorTag* playerTag = actor->mobyTag;
    unsigned short* list;
    unsigned short entry;
    if (!checkedActor) return;
    switch (tag->kind) {
    case 0:
        if ((D_8006E538 & 0xC) && (D_8006E538 & 0x60)
            && DecodedPlayerGateState != 0x99 && D_8006E344 != 1)
            tag->retainSave = 0;
        break;
    case 1:
        if ((D_8006E538 & 0x40) && DecodedPlayerGateState != 0x99
            && D_8006E344 != 1 && (playerTag->flags & 2))
            tag->retainSave = 0;
        break;
    }
    if (tag->listIndex != -1) {
        list = DecodedPlayerGateLists[tag->listIndex];
        do {
            entry = *list;
            if (!(D_8006C550[entry & 0x7FFF].state & 0x80)) return;
            list++;
        } while ((short)entry >= 0);
    }
    if (tag->retainSave) DecodedPlayerGateSave(DecodedPlayerGateSavepoint);
    func_80055B18(moby);
}

int func_8004F334(Vector3D*, Vector3D*);
void func_80055B18(Moby*);
void func_level_18_80082CC4(Moby* moby) {
    int* limit = moby->mobyTag;
    if (func_8004F334(&moby->position, &spyro.position) < *limit) {
        Moby* spawned = SpawnMoby(0x110, moby);
        if (spawned) {
            unsigned char* tag = spawned->mobyTag;
            spawned->angle.yaw = 0;
            spawned->size = 0x10;
            tag[4] = 0;
            func_80055B18(moby);
        }
    }
}

/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * level18 0x80082D50..0x8008309C: 211 original instructions, plus
 * five owned dispatch words at0x80074780. Original40-byte frame,
 * 88-byte pool stride, 2-byte packed-list stride, signed sentinel shift,
 * pointer/byte/halfword widths, helper arguments and post-call reads retained.
 * Offset names identify storage; units, helper contracts and caller cadence
 * remain unresolved. Empty constraints emit no CPU instructions.
 * Acceptance requires original linked code/table words and all retail hashes.
 */
#define P82D50Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern Moby* P82D50Pool __asm__("D_8006C550");
extern Moby* P82D50End __asm__("D_8006C704");
extern unsigned short** P82D50Lists __asm__("D_8006C730");
extern unsigned char P82D50Slot[] __asm__("D_8006C7F8");
extern unsigned char P82D50Player[] __asm__("D_80070328");
int P82D50func_80021ED8(int,int,int) __asm__("func_80021ED8");
int P82D50func_80021F3C(int) __asm__("func_80021F3C");
int P82D50func_8003B7B4(void*,int,void*) __asm__("func_8003B7B4");
void func_level_18_80082D50(Moby *argument) {
    register Moby* owner __asm__("$17")=argument;
    register Moby *scanMoby __asm__("$17");
    register int value19 __asm__("$19"),class20 __asm__("$20");
    register Vector3D *distanceTarget __asm__("$5");
    register Vector3D* distanceArgument __asm__("$4");
    register int work2 __asm__("$2");
    register Moby* end2 __asm__("$2");
    register Moby* listPool __asm__("$7");
    int listIndex24;
    int index28;
    int index4;
    register int helperResult6 __asm__("$6");
    register int flag80 __asm__("$16");
    register unsigned short *listCursor __asm__("$4");
    register int packedEntry __asm__("$5");
    unsigned char *stateArgument;
    register unsigned char *scanState __asm__("$16");
    unsigned char dispatchState;
    register void *privateState __asm__("$18");

    __asm__("" : "=r"(owner):"0"(owner));
    privateState = owner->mobyTag;
    index28 = P82D50Field(privateState, int *, 0x28);
    flag80 = 0;
    if (index28 != -1) {
        work2=P82D50Pool[index28].state;
        __asm__("" : "=r"(work2):"0"(work2));
        flag80 = work2 & 0x80;
    }
    dispatchState = owner->state;
    switch (dispatchState) {
    case 0:
        index4 = P82D50Field(privateState, int *, 4);
        distanceArgument=&owner->position;
        if (index4 == -1) {
            distanceTarget = (Vector3D*)P82D50Player;
            goto distanceCall;
listFailure:
            helperResult6=0x801;
            goto admission;
        } else {
            distanceTarget = &P82D50Pool[index4].position;
        }
distanceCall:
        helperResult6 = func_8004F334(distanceArgument, distanceTarget);
        if (helperResult6 < 0x800) {
            listIndex24 = P82D50Field(privateState, int *, 0x24);
            if (listIndex24 != -1) {
                listCursor = P82D50Lists[listIndex24];
                listPool=P82D50Pool;
nextListEntry:
                packedEntry = *listCursor;
                work2=packedEntry & 0x7FFF;
                __asm__("" : "=r"(work2):"0"(work2));
                if (listPool[work2].state & 0x80) {
                    work2=packedEntry<<16;
                    __asm__("" : "=r"(work2):"0"(work2));
                    if (work2 >= 0) {
                        listCursor += 1;
                        goto nextListEntry;
                    }
                } else {
                    goto listFailure;
                }
            }
admission:
            if (helperResult6 < 0x800) {
                work2=-1;
                __asm__("" : "=r"(privateState):"0"(privateState),"r"(helperResult6),"r"(work2));
                if (P82D50Field(privateState, int *, 4) != work2) {
                    scanMoby = P82D50Pool;
                    if ((unsigned int) scanMoby < (unsigned int) P82D50End) {
                        class20=0x3D5;value19=1;
                        scanState = &scanMoby->state;
                        do {
                            if ((P82D50Field(scanState, short *, -0x12) == class20) && (P82D50Field(scanMoby->mobyTag, int *, 4) == P82D50Field(privateState, int *, 4))) {
                                P82D50Field(scanState, unsigned char *, 0) = value19;
                                P82D50func_8003B7B4(scanState, 1, &P82D50Slot);
                            }
                            end2=P82D50End;
                            __asm__("" : "=r"(end2):"0"(end2));
                            scanMoby += 1;
                            scanState += 0x58;
                        } while ((unsigned int) scanMoby < (unsigned int) end2);
                    }
                    P82D50Pool[P82D50Field(privateState, int *, 4)].state = 3;
                    stateArgument = &P82D50Pool[P82D50Field(privateState, int *, 4)].state;
                } else {
                    goto transitionOwner;
                }
                P82D50func_8003B7B4(stateArgument, 1, &P82D50Slot);
            }
        }
    default:
        return;
    case 1:
        func_8003BB10(owner, 0, 0);
        P82D50func_80021ED8(P82D50Field(privateState, int *, 0), 0xFC, 0);
        owner->state = 2;
        return;
    case 2:
        if ((func_80036220((Vector3D*)P82D50Player, privateState + 8, 0, 0) != 0) && (flag80 == 0)) {
            owner->state = 3;
        case 3:
            if ((P82D50func_80021F3C(P82D50Field(privateState, int *, 0)) & 0xFF) == 2) {
                P82D50func_80021ED8(P82D50Field(privateState, int *, 0), 0xFC, 0);
                owner->state = 4;
            }
            func_8003BB10(owner, 0, 0);
            return;
        }
        break;
    case 4:
        if (flag80 != 0) {
            goto transitionOwner;
        }
        break;
    }
    return;
transitionOwner:
    owner->state=1;
    stateArgument=&owner->state;
    P82D50func_8003B7B4(stateArgument,1,&P82D50Slot);
}

#undef P82D50Field
