#include "common.h"
#include "savepoint.h"
#include "camera.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "mobyutil.h"
#include "ovl_header.h"
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
void func_level_38_80074A10(void *input) {
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
void func_level_38_8007566C(Moby* argument) {
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
void func_level_38_80075CF8(void *input) {
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
void func_level_38_80077248(Moby* moby) {
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
void func_level_38_80077384(Moby* moby) {
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
void func_level_38_80077440(Moby* moby) {
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
void func_level_38_800774F4(Moby *moby) {
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
void func_level_38_800777F8(void *input) {
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
void func_level_38_8007836C(void *input) {
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


void func_level_38_800794C0(Moby* moby) {
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
void func_level_38_800794E0(Moby* argument) {
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
void func_level_38_800796E0(void *input) {
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
void func_level_38_80079D38(Moby* moby) {
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
void func_level_38_80079E64(void *input) {
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


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 8007A418.
* Assembly SHA256 b66546c21ed6fc86942b10e1cb8fa8f0a207b14a4defe16da6aa0faf095fa5e2.
* AI generated; not human reviewed. All original instructions (1038) and
* actual branch/call/internal targets are required. Frame E8 retains every
* S0/S1/S2/S3/S4/RA save/restore and original SP20..CF local extent.
* Original packed data at 800745A4  is exactly 12 bytes:
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
#define Actor38Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
unsigned char Actor38Call135A4View1() __asm__("func_800135A4");
int Actor38Call18368View1() __asm__("func_80018368");
int Actor38Call2803CView1() __asm__("func_8002803C");
short Actor38Call2803CView2() __asm__("func_8002803C");
unsigned char Actor38Call28154View1() __asm__("func_80028154");
unsigned char Actor38Call35734View1() __asm__("func_80035734");
unsigned char Actor38Call3585CView1() __asm__("func_8003585C");
int Actor38Call359A4View1() __asm__("func_800359A4");
int Actor38Call3617CView1() __asm__("func_8003617C");
int Actor38Call3BABCView1() __asm__("func_8003BABC");
unsigned char Actor38Call3BE70View1() __asm__("func_8003BE70");
int Actor38Call3BFC0View1() __asm__("func_8003BFC0");
int Actor38Call4F264View1() __asm__("func_8004F264");
void * Actor38Call50844View1() __asm__("func_80050844");
unsigned char Actor38Call509E8View1() __asm__("func_800509E8");
unsigned char Actor38Call55B18View1() __asm__("func_80055B18");
unsigned char Actor38Call55D24View1() __asm__("func_80055D24");
int Actor38Call55E84View1() __asm__("func_80055E84");
unsigned char Actor38Call55F14View1() __asm__("func_80055F14");
extern int Actor38Data6580CView1 __asm__("D_8006580C");
extern unsigned char Actor38Data6585CView1 __asm__("D_8006585C");
extern unsigned char Actor38Data658A0View1 __asm__("D_800658A0");
extern unsigned char Actor38Data65920View1 __asm__("D_80065920");
extern unsigned char Actor38Data68F7CView1 __asm__("D_80068F7C");
extern unsigned char Actor38Data68F90View1 __asm__("D_80068F90");
extern unsigned int Actor38Data6C550View1 __asm__("D_8006C550");
extern int Actor38Data6C58CView1 __asm__("D_8006C58C");
extern int Actor38Data6C640View1 __asm__("D_8006C640");
extern int Actor38Data6C6D0View1 __asm__("D_8006C6D0");
extern unsigned int Actor38Data6C704View1 __asm__("D_8006C704");
extern int Actor38Data6C770View1 __asm__("D_8006C770");
extern int Actor38Data6E344View1 __asm__("D_8006E344");
extern int Actor38Data6E538View1 __asm__("D_8006E538");
extern unsigned char Actor38Data70328View1 __asm__("D_80070328");
extern unsigned char Actor38Data716ACView1 __asm__("D_800716AC");
extern unsigned char Actor38Data719A8View1 __asm__("D_800719A8");
extern unsigned char Actor38Data719F0View1 __asm__("D_800719F0");
extern unsigned char Actor38Data745B0View1 __asm__("D_level_38_800745B0");
extern int Actor38Data74364View1 __asm__("unk_ovlheader_80074364");
extern int Actor38Data74368View1 __asm__("unk_ovlheader_80074368");
extern int Actor38Data7436CView1 __asm__("unk_ovlheader_8007436C");
extern void *(*Actor38DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Actor38DataSpawnParticleView1)() __asm__("SpawnParticle");
extern int(*Actor38Data74318View1)() __asm__("unk_ovlheader_80074318");
const unsigned char Actor38Data745A4View1[12] __asm__("D_level_38_800745A4") __attribute__((aligned(4))) = {
    32, 0, 0, 0, 0, 0, 0, 0, 224, 255, 255, 255
}
;
extern unsigned char Actor38Data745A4View2 __asm__("D_level_38_800745A4");
extern int Actor38Data70328View2 __asm__("D_80070328 + 640 + 0 - 0");
extern int Actor38Data70328View3 __asm__("D_80070328 + 640 + 1 - 1");
extern int Actor38Data70328View4 __asm__("D_80070328 + 640 + 2 - 2");
extern int Actor38Data70328View5 __asm__("D_80070328 + 640 + 3 - 3");
extern int Actor38Data70328View6 __asm__("D_80070328 + 640 + 4 - 4");
extern int Actor38Data70328View7 __asm__("D_80070328 + 640 + 5 - 5");
extern unsigned char Actor38Data6585CView2 __asm__("D_8006585C + 0 + 6 - 6");
extern unsigned char Actor38Data6585CView3 __asm__("D_8006585C + 0 + 7 - 7");
extern unsigned char Actor38Data6585CView4 __asm__("D_8006585C + 0 + 8 - 8");
extern unsigned char Actor38Data6585CView5 __asm__("D_8006585C + 0 + 9 - 9");
extern unsigned char Actor38Data6585CView6 __asm__("D_8006585C + 2 + 10 - 10");
extern unsigned char Actor38Data74630View1 __asm__("D_level_38_80074630");
extern int Actor38DatarandView1() __asm__("rand");
void func_level_38_8007A418(void *input) {
    register void *returned2 __asm__("$2");
    register void *pointer4 __asm__("$4");
    register void *effectPosition16 __asm__("$16");
    register void *effectVector18 __asm__("$18");
    register void *extraSource5 __asm__("$5");
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
    ownerRecord20 = input;
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    privateRecord19 = Actor38Field(ownerRecord20, void**, 0);
    if (!Actor38Field(privateRecord19, int*, 0x38)){
        if (Actor38Field(ownerRecord20, unsigned char*, 0x4D)){
            returned2 = Actor38DataSpawnMobyView1(0x2A9, ownerRecord20);
            pointer4 = Actor38Field(returned2, void**, 0);
            rawWord3 = 1;
            Actor38Field(pointer4, void**, 8) = ownerRecord20;
            Actor38Field(pointer4, short*, 0) = rawWord3;
            argumentWord5 = Actor38Field(ownerRecord20, unsigned short*, 0x36);
            rawWord3 = 28;
            Actor38Field(pointer4, int*, 4) = rawWord3;
            rawWord3 = 5;
            Actor38Field(pointer4, short*, 2) = argumentWord5;
            Actor38Field(returned2, unsigned char*, 0x4F) = rawWord3;
            rawWord3 = 7;
            Actor38Field(returned2, unsigned char*, 0x47) = rawWord3;
            Actor38Field(privateRecord19, void**, 0x38) = returned2;
        }
    }
    rawWord2 = Actor38Field(privateRecord19, short*, 4);
    if (rawWord2) goto initialized28;
    {
        rawWord2 = 1;
        addressWord4 = Actor38Data6C550View1;
        rawWord3 = Actor38Data6C704View1;
        Actor38Field(privateRecord19, short*, 4) = rawWord2;
        rawWord3 = addressWord4 < (unsigned int)rawWord3;
        Actor38Field(privateRecord19, short*, 0x32) = 0;
        if (!rawWord3) goto listDone28;
        argumentWord6 = 1;
        argumentWord5 = 381;
        memoryCursor3 = (void*)(addressWord4+71);
        __asm__("":"=r"(memoryCursor3):"0"(memoryCursor3));
        do{
            rawWord2 = Actor38Field(memoryCursor3, short*, -17);
            if (rawWord2 == argumentWord6){
                Actor38Field(memoryCursor3, short*, -17) = argumentWord5;
                Actor38Field(memoryCursor3, unsigned char*, 0) = 0;
            }
            rawWord2 = Actor38Data6C704View1;
            addressWord4 += 88;
            rawWord2 = addressWord4 < (unsigned int)rawWord2;
            memoryCursor3 += 88;
        }
        while (rawWord2);
    listDone28:
        temporaryWord11 = Actor38Field(&Actor38Data70328View1, int *, 0x280) * 2;
        Actor38Field(privateRecord19, int *, 0x28) = temporaryWord11;
        if (temporaryWord11 >= 7) {
            Actor38Field(privateRecord19, int *, 0x28) = 6;
        }
        if (Actor38Field(privateRecord19, int *, 0x28) <= 0) {
            Actor38Field(privateRecord19, int *, 0x28) = 1;
        }
        rawWord2 = Actor38Call2803CView1(0x17, 0xB4, Actor38Data74368View1, Actor38Data7436CView1, Actor38Data74364View1, privateRecord19+0x28, 6);
        rawWord2 <<= 16;
        rawWord3 = Actor38Data6C58CView1;
        rawWord2 >>= 16;
        Actor38Field(privateRecord19, int*, 0x40) = rawWord2;
        temporaryWord1 = rawWord3*6;
        temporaryWord12 = *(&Actor38Data716ACView1 + temporaryWord1);
        if (temporaryWord12 < 0xFFU) {
            *(&Actor38Data716ACView1 + temporaryWord1) = temporaryWord12 + 1;
        }
    }
initialized28:
    if (Actor38Data6E344View1 == 1) {
        temporaryWord2 = Actor38Field(privateRecord19, int *, 0x40);
        if (temporaryWord2 != -1) {
            Actor38Call28154View1(temporaryWord2);
            Actor38Field(privateRecord19, int *, 0x40) = -1;
        }
    }
    else if (Actor38Field(privateRecord19, int *, 0x40) == -1) {
        Actor38Field(privateRecord19, int *, 0x40) = (int) Actor38Call2803CView2(0x17, 0xB4, Actor38Data74368View1, Actor38Data7436CView1, Actor38Data74364View1, privateRecord19 + 0x28, 6);
    }
    Actor38Data74318View1(ownerRecord20, 0x98);
    if ((Actor38Field(privateRecord19, int *, 0x1C) & 0x21) == 0x20) {
        if ((Actor38Data6C640View1 % 15) < 0xC) {
            Actor38Field(ownerRecord20, signed char *, 0x4C) = 0;
            Actor38Field(ownerRecord20, signed char *, 0x4D) = 0;
        }
        else {
            Actor38Field(ownerRecord20, signed char *, 0x4C) = 0x20;
            Actor38Field(ownerRecord20, signed char *, 0x4D) = 1;
        }
    }
    Actor38Data6C6D0View1 = 0;
    Actor38Call135A4View1(&Actor38Data719A8View1, &Actor38Data68F7CView1, 0);
    Actor38Call135A4View1(&Actor38Data719F0View1, &Actor38Data68F90View1, 0);
    rawWord2 = Actor38Field(privateRecord19, int*, 0x28);
    if (rawWord2 > 0) goto positiveCount28;
    Actor38Field(&Actor38Data70328View1, int*, 0x280) = 0;
    Actor38Field(&Actor38Data70328View1, int*, 0x24) |= 1;
    return;
positiveCount28:
    rawWord2 += 1;
    addressWord4 = (unsigned int)(&Actor38Data70328View1+0x280);
    __asm__("":"=r"(addressWord4):"0"(addressWord4));
    rawWord3 = (unsigned int)rawWord2 >> 31;
    rawWord2 += rawWord3;
    rawWord3 = Actor38Data6580CView1;
    rawWord2 >>= 1;
    Actor38Field(addressWord4, int*, 0) = rawWord2;
    if (rawWord3 < rawWord2)Actor38Field(addressWord4, int*, 0) = rawWord3;
    if (Actor38Field(privateRecord19, int *, 0x44) != 0) {
        Actor38Call3585CView1(ownerRecord20, 0x10E, 2, 0, 0, 0);
    }
    if (Actor38Field(privateRecord19, int *, 8) != 0) {
        Actor38Call3BABCView1(ownerRecord20, 0, 0);
        if (Actor38Field(ownerRecord20, unsigned char *, 0x3D) != 1) {
            Actor38Data6C770View1 = 0;
            Actor38Field(ownerRecord20, signed char *, 0x40) = 0x72;
            Actor38Field(ownerRecord20, unsigned char *, 0x3D) = 1U;
            Actor38Field(ownerRecord20, signed char *, 0x3F) = 0;
            Actor38Call35734View1(ownerRecord20);
        }
        Actor38Field(privateRecord19, int *, 8) = 0;
    }
    if ((Actor38Call55E84View1(ownerRecord20) >= 8) && (Actor38Field(privateRecord19, int *, 0x3C) != 1) && (Actor38Field(ownerRecord20, unsigned short *, 0x3C) == 0x101)) {
        Actor38Call3BABCView1(ownerRecord20, 1, 0);
        Actor38Field(privateRecord19, int *, 0x3C) = 1;
    }
    else if (Actor38Data6C770View1 != 0) {
        if (Actor38Field(ownerRecord20, unsigned char *, 0x3D) != 0) {
            Actor38Data6C770View1 = 0;
            Actor38Field(ownerRecord20, signed char *, 0x40) = 0x72;
            Actor38Field(ownerRecord20, unsigned char *, 0x3D) = 0U;
            Actor38Field(ownerRecord20, signed char *, 0x3F) = 0;
            Actor38Call35734View1(ownerRecord20);
        }
        Actor38Field(privateRecord19, int *, 0x3C) = 0;
    }
    if (Actor38Data6E538View1 & 0x80) {
        if (!(Actor38Field(privateRecord19, int *, 0x1C) & 1)) {
            if ((Actor38Data6E344View1 != 1) && (Actor38Data6E344View1 != 0xF)) {
                if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(privateRecord19, int *, 0x48)) == 0) {
                    Actor38Field(privateRecord19, int *, 0x48) = Actor38Call3BABCView1(ownerRecord20, 3, 4);
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
        if (Actor38Field(privateRecord19, int *, 0x1C) & 1) {
        updateStatusHandle:
            if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(privateRecord19, int *, 0x48)) == 0) {
                Actor38Field(privateRecord19, int *, 0x48) = Actor38Call3BABCView1(ownerRecord20, 4, 4);
            }
        }
        else if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(privateRecord19, int *, 0x48)) != 0) {
            if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(privateRecord19, int *, 0x48)) != 0) {
                Actor38Call3BE70View1(Actor38Field(privateRecord19, int *, 0x48));
            }
            Actor38Field(privateRecord19, int *, 0x48) = -1;
        }
    }
    Actor38Call359A4View1(privateRecord19, 4);
    if ((Actor38Data6E538View1 & 0x60) && (playerModePointer16 = &Actor38Data70328View1 + 0x48, (Actor38Field(&Actor38Data70328View1, int *, 0x48) != 0x99)) && (Actor38Data6E344View1 != 1)) {
        if (Actor38Data6E344View1 != 0xF) {
            if (Actor38Field(privateRecord19, int *, 0) <= 0) {
                if (Actor38Data6E538View1 & 0x40) {
                    rawWord2 = Actor38Field(privateRecord19, int*, 0x1C);
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    rawWord3 = rawWord2&0x1E;
                    switch (rawWord3) {
                    case 4:
                        temporaryWord9 = &Actor38Data745A4View2;
                        __asm__("":"=r"(temporaryWord9):"0"(temporaryWord9));
                        rawWord2 = Actor38Field(temporaryWord9, int*, 0);
                        rawWord3 = Actor38Field(temporaryWord9, int*, 4);
                        argumentWord4 = Actor38Field(temporaryWord9, int*, 8);
                        originalFrame.sp20 = rawWord2;
                        originalFrame.sp24 = rawWord3;
                        originalFrame.sp28 = argumentWord4;
                        __asm__ __volatile__("":::"$16", "memory");
                        firstSpawnIndex16 = 0;
                        do {
                            spawnedRecord18 = Actor38DataSpawnMobyView1(0xBB, ownerRecord20);
                            __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                            if (spawnedRecord18 != 0) {
                                Actor38Field(spawnedRecord18, unsigned char *, 0x46) = Actor38Call3617CView1(Actor38Field(spawnedRecord18, unsigned char *, 0x46), Actor38Field((((unsigned char*)&originalFrame-0x20) + (firstSpawnIndex16 * 4)), int *, 0x20));
                                if (Actor38Call18368View1(&Actor38Data70328View1, spawnedRecord18 + 0xC) != 0) {
                                    Actor38Call55B18View1(spawnedRecord18);
                                }
                                Actor38Call3BABCView1(spawnedRecord18, 0, 1);
                            }
                            firstSpawnIndex16 += 1;
                        }
                        while (firstSpawnIndex16 < 3);
                        rawWord2 = Actor38Field(privateRecord19, int*, 0x20);
                        __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
                        rawWord3 = 50;
                        __asm__ __volatile__(""::"r"(rawWord2), "r"(rawWord3), "i"(0x8007aac8):"memory");
                        Actor38Field(privateRecord19, int*, 0) = rawWord3;
                        goto decrementCountdown;
                    case 8:
                        temporaryWord10 = &Actor38Data745A4View2;
                        __asm__("":"=r"(temporaryWord10):"0"(temporaryWord10));
                        rawWord2 = Actor38Field(temporaryWord10, int*, 0);
                        rawWord3 = Actor38Field(temporaryWord10, int*, 4);
                        argumentWord4 = Actor38Field(temporaryWord10, int*, 8);
                        originalFrame.sp30 = rawWord2;
                        originalFrame.sp34 = rawWord3;
                        originalFrame.sp38 = argumentWord4;
                        __asm__ __volatile__("":::"$16", "memory");
                        secondSpawnIndex16 = 0;
                        do {
                            spawnedRecord18 = Actor38DataSpawnMobyView1(0x97, ownerRecord20);
                            __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                            if (spawnedRecord18 != 0) {
                                Actor38Field(spawnedRecord18, unsigned char *, 0x46) = Actor38Call3617CView1(Actor38Field(spawnedRecord18, unsigned char *, 0x46), Actor38Field((((unsigned char*)&originalFrame-0x20) + (secondSpawnIndex16 * 4)), int *, 0x30));
                                if (Actor38Call18368View1(&Actor38Data70328View1, spawnedRecord18 + 0xC) != 0) {
                                    if (Actor38Call3BFC0View1(spawnedRecord18, Actor38Field(Actor38Field(spawnedRecord18, void **, 0), int *, 8)) != 0) {
                                        if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(Actor38Field(spawnedRecord18, void **, 0), int *, 8)) != 0) {
                                            Actor38Call3BE70View1(Actor38Field(Actor38Field(spawnedRecord18, void **, 0), int *, 8));
                                        }
                                        Actor38Field(Actor38Field(spawnedRecord18, void **, 0), int *, 8) = -1;
                                    }
                                    Actor38Call55B18View1(spawnedRecord18);
                                }
                                Actor38Call3BABCView1(spawnedRecord18, 0, 1);
                            }
                            secondSpawnIndex16 += 1;
                        }
                        while (secondSpawnIndex16 < 3);
                        rawWord2 = Actor38Field(privateRecord19, int*, 0x20);
                        __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
                        rawWord3 = 50;
                        __asm__ __volatile__(""::"r"(rawWord2), "r"(rawWord3), "i"(0x8007abd0):"memory");
                        Actor38Field(privateRecord19, int*, 0) = rawWord3;
                        goto decrementCountdown;
                    case 16:
                        spawnedRecord18 = Actor38DataSpawnMobyView1(0x251, ownerRecord20);
                        __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                        if (spawnedRecord18 != 0) {
                            if (Actor38Call18368View1(playerModePointer16 - 0x48, spawnedRecord18 + 0xC) != 0) {
                                Actor38Call55B18View1(spawnedRecord18);
                            }
                            else {
                                Actor38Field(Actor38Field(spawnedRecord18, void**, 0), int *, 0) = (int) ((int) (Actor38Field(&Actor38Data65920View1, short*, (Actor38Field(&Actor38Data70328View1, unsigned char *, 0xE) * 2)) * 0xAF) >> 0xC);
                                Actor38Field(Actor38Field(spawnedRecord18, void**, 0), int *, 4) = (int) ((int) (Actor38Field(&Actor38Data658A0View1, short*, (Actor38Field(&Actor38Data70328View1, unsigned char *, 0xE) * 2)) * 0xAF) >> 0xC);
                                Actor38Field(Actor38Field(spawnedRecord18, void**, 0), int *, 8) = 0;
                                rawWord2 = Actor38Field(privateRecord19, int*, 0x20);
                                __asm__ __volatile__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
                                rawWord3 = 50;
                                __asm__ __volatile__(""::"r"(rawWord2), "r"(rawWord3), "i"(0x8007acb4):"memory");
                                Actor38Field(privateRecord19, int*, 0) = rawWord3;
                                goto decrementCountdown;
                            }
                        }
                        break;
                    case 2:
                        temporaryWord17 = (unsigned char*)&originalFrame.sp40;
                        temporaryWord16 = &Actor38Data745B0View1;
                        copyEnd8 = temporaryWord16+128;
                        do {
                            rawWord2 = Actor38Field(temporaryWord16, int*, 0);
                            rawWord3 = Actor38Field(temporaryWord16, int*, 4);
                            argumentWord4 = Actor38Field(temporaryWord16, int*, 8);
                            argumentWord5 = Actor38Field(temporaryWord16, int*, 12);
                            Actor38Field(temporaryWord17, int*, 0) = rawWord2;
                            Actor38Field(temporaryWord17, int*, 4) = rawWord3;
                            Actor38Field(temporaryWord17, int*, 8) = argumentWord4;
                            Actor38Field(temporaryWord17, int*, 12) = argumentWord5;
                            __asm__ __volatile__("":"=r"(temporaryWord16):"0"(temporaryWord16):"memory");
                            temporaryWord16 += 0x10;
                            temporaryWord17 += 0x10;
                        }
                        while (temporaryWord16 != copyEnd8);
                        temporaryWord13 = Actor38Field(privateRecord19, unsigned short *, 0x30);
                        if (temporaryWord13 >= 0x1FU) {
                            Actor38Field(privateRecord19, unsigned short *, 0x30) = 0U;
                        }
                        else {
                            Actor38Field(privateRecord19, unsigned short *, 0x30) = (unsigned short) (temporaryWord13 + 1);
                        }
                        spawnedRecord18 = Actor38DataSpawnMobyView1(0x175, ownerRecord20);
                        __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                        if (spawnedRecord18 != 0) {
                            Actor38Field(privateRecord19, int *, 0) = 1;
                            Actor38Field(Actor38Field(spawnedRecord18, void**, 0), int *, 0) = (int) ((int) (Actor38Field(&Actor38Data65920View1, short*, (Actor38Call3617CView1(Actor38Field(&Actor38Data70328View1, unsigned char *, 0xE), Actor38Field(&(&originalFrame.sp20)[(short) Actor38Field(privateRecord19, unsigned short *, 0x30)], int *, 0x20)) * 2)) * 0xE1) >> 0xB);
                            Actor38Field(Actor38Field(spawnedRecord18, void**, 0), int *, 4) = (int) ((int) (Actor38Field(&Actor38Data658A0View1, short*, (Actor38Call3617CView1(Actor38Field(&Actor38Data70328View1, unsigned char *, 0xE), Actor38Field(&(&originalFrame.sp20)[(short) Actor38Field(privateRecord19, unsigned short *, 0x30)], int *, 0x20)) * 2)) * 0xE1) >> 0xB);
                            Actor38Field(Actor38Field(spawnedRecord18, void**, 0), int *, 8) = 0;
                            if (Actor38Call18368View1((&Actor38Data70328View1 + 0xE) - 0xE, spawnedRecord18 + 0xC) != 0) {
                                Actor38Call55B18View1(spawnedRecord18);
                            }
                            if (Actor38Field(privateRecord19, int *, 0x20) == ((Actor38Field(privateRecord19, int *, 0x20) / 5) * 5)) {
                                Actor38Call3BABCView1(spawnedRecord18, 0, 1);
                            }
                        }
                        rawWord2 = Actor38Field(privateRecord19, int*, 0x20);
                    decrementCountdown:
                        rawWord2 -= 1;
                        Actor38Field(privateRecord19, int *, 0x20) = rawWord2;
                        if ((rawWord2 <= 0) && (temporaryWord3 = Actor38Field(privateRecord19, short *, 0x36), Actor38Field(privateRecord19, int *, 0x1C) = (int) (Actor38Field(privateRecord19, int *, 0x1C) & ~0x1E), (temporaryWord3 != -1))) {
                            Actor38Call28154View1((int) temporaryWord3);
                        }
                        break;
                        default:break;
                    }
                }
                else if ((Actor38Data6E538View1 & 0x20) && (Actor38Field(privateRecord19, short *, 0x32) < 0x37) && (spawnedRecord18 = Actor38DataSpawnMobyView1(0x175, ownerRecord20), (spawnedRecord18 != 0))) {
                    Actor38Field(privateRecord19, int *, 0) = 0xB;
                    __asm__("":"=r"(spawnedRecord18):"0"(spawnedRecord18));
                    if (Actor38Call18368View1(playerModePointer16 - 0x48, spawnedRecord18 + 0xC) != 0) {
                        Actor38Call55B18View1(spawnedRecord18);
                    }
                    Actor38Call3BABCView1(spawnedRecord18, 0, 1);
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
        Actor38Field(privateRecord19, unsigned short *, 0x30) = rawWord2;
    }
    Actor38Field(privateRecord19, short *, 0x32) = 0;
    Actor38Call55D24View1(ownerRecord20, 4);
    rawWord2 = Actor38Data70328View2;
    rawWord2 = Actor38Field(&Actor38Data6585CView2, int*, rawWord2*4);
    Actor38Field(ownerRecord20, int*, 0x54) = rawWord2;
    __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
    if (Actor38Data70328View3 >= 2) {
        Actor38Call55F14View1(ownerRecord20, 1, &originalFrame.sp20);
        originalFrame.sp28 = (int) (originalFrame.sp28 + Actor38Field(ownerRecord20, int *, 0x14)) >> 1;
        Actor38DataSpawnParticleView1(2, 0x42, &originalFrame.sp20, 0);
        Actor38Call55F14View1(ownerRecord20, 2, &originalFrame.sp20);
        originalFrame.sp28 = (int) (originalFrame.sp28 + Actor38Field(ownerRecord20, int *, 0x14)) >> 1;
        Actor38DataSpawnParticleView1(2, 0x42, &originalFrame.sp20, 0);
    }
    if (Actor38Field(&Actor38Data70328View1, int *, 0x48) == 0x99) {
        effectPosition16 = &originalFrame.sp30;
        __asm__("":"=r"(effectPosition16):"0"(effectPosition16));
        extraSource5 = &Actor38Data74630View1;
        __asm__("":"=r"(extraSource5):"0"(extraSource5));
        rawWord2 = Actor38Field(extraSource5, int*, 0);
        rawWord3 = Actor38Field(extraSource5, int*, 4);
        argumentWord4 = Actor38Field(extraSource5, int*, 8);
        originalFrame.sp40 = rawWord2;
        originalFrame.sp44 = rawWord3;
        originalFrame.sp48 = argumentWord4;
        __asm__ __volatile__("":::"$4", "$5", "$6", "memory");
        Actor38Call55F14View1(ownerRecord20, 1, effectPosition16);
        originalFrame.sp38 = (originalFrame.sp38+Actor38Field(ownerRecord20, int*, 0x14)) >> 1;
        rawWord2 = Actor38DatarandView1();
        effectVector18 = &originalFrame.sp40;
        if (rawWord2%10 == 0)Actor38DataSpawnParticleView1(1, 20, effectPosition16, effectVector18);
        Actor38Call55F14View1(ownerRecord20, 2, effectPosition16);
        originalFrame.sp38 = (originalFrame.sp38+Actor38Field(ownerRecord20, int*, 0x14)) >> 1;
        rawWord2 = Actor38DatarandView1();
        if (rawWord2%10 == 0)Actor38DataSpawnParticleView1(1, 20, effectPosition16, effectVector18);
        Actor38Call55F14View1(ownerRecord20, 0, privateRecord19 + 0x10);
        temporaryPointer4 = Actor38Field(privateRecord19, void **, 0xC);
        Actor38Field(privateRecord19, int *, 0x18) = (int) (Actor38Field(privateRecord19, int *, 0x18) + 0x100);
        if ((unsigned char) Actor38Field(temporaryPointer4, unsigned char *, 0x65) < 0x10U) {
            if (temporaryPointer4 != 0) {
                Actor38Call509E8View1(temporaryPointer4);
            }
            Actor38Field(privateRecord19, void **, 0xC) = 0;
        }
        if (Actor38Field(privateRecord19, void **, 0xC) == 0) {
            Actor38Field(privateRecord19, void **, 0xC) = Actor38Call50844View1(privateRecord19 + 0x10, -0xC, 0x10, Actor38Field(&Actor38Data6585CView3, int*, (Actor38Data70328View4 * 4)) & 0xFFFFFF);
        }
        else {
            if (Actor38Call4F264View1(Actor38Field(ownerRecord20, unsigned char*, 0x46), 0) < 32) goto bright28;
            if (Actor38Call4F264View1(Actor38Field(ownerRecord20, unsigned char*, 0x46), 128) >= 32) goto dark28;
        bright28:
            memoryCursor3 = Actor38Field(privateRecord19, void**, 12);
            __asm__ __volatile__(""::"r"(memoryCursor3), "i"(0x8007b1ac):"memory");
            rawWord2 = 244;
            goto color28;
        dark28:
            rawWord2 = 7;
            memoryCursor3 = Actor38Field(privateRecord19, void**, 12);
        color28:
            __asm__ __volatile__(""::"r"(rawWord2), "r"(memoryCursor3):"memory");
            Actor38Field(memoryCursor3, signed char*, 0x66) = rawWord2;
            __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
            Actor38Field(Actor38Field(privateRecord19, void **, 0xC), signed char *, 0x68) = (signed char) Actor38Field(&Actor38Data6585CView4, int*, (Actor38Data70328View5 * 4));
            __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
            Actor38Field(Actor38Field(privateRecord19, void **, 0xC), signed char *, 0x69) = (signed char) ((int) Actor38Field(&Actor38Data6585CView5, int*, (Actor38Data70328View6 * 4)) >> 8);
            __asm__ __volatile__("":::"$3", "$4", "$5", "memory");
            rawWord2 = Actor38Data70328View7;
            memoryCursor3 = Actor38Field(privateRecord19, void**, 12);
            rawWord2 = Actor38Field(&Actor38Data6585CView6, short*, rawWord2*4);
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Actor38Field(memoryCursor3, signed char*, 0x6A) = rawWord2;
        }
    }
    else {
        temporaryPointer14 = Actor38Field(privateRecord19, void **, 0xC);
        if (temporaryPointer14 != 0) {
            Actor38Field(temporaryPointer14, unsigned char *, 0x65) = (unsigned char) (Actor38Field(temporaryPointer14, unsigned char *, 0x65) - 1);
            temporaryPointer5 = Actor38Field(privateRecord19, void **, 0xC);
            if (Actor38Field(temporaryPointer5, unsigned char *, 0x65) == 0) {
                Actor38Call509E8View1(temporaryPointer5);
                Actor38Field(privateRecord19, void **, 0xC) = 0;
            }
            else {
                Actor38Call55F14View1(ownerRecord20, 0, privateRecord19 + 0x10);
                Actor38Field(privateRecord19, int *, 0x18) = (int) (Actor38Field(privateRecord19, int *, 0x18) + 0x100);
            }
        }
    }
    temporaryWord15 = Actor38Field(privateRecord19, int *, 0x1C) & 0x21;
    switch (temporaryWord15) {
    case 1:
        if (Actor38Call359A4View1(privateRecord19 + 0x24, 4) != 0) {
            if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(privateRecord19, int *, 0x48)) != 0) {
                if (Actor38Call3BFC0View1(ownerRecord20, Actor38Field(privateRecord19, int *, 0x48)) != 0) {
                    Actor38Call3BE70View1(Actor38Field(privateRecord19, int *, 0x48));
                }
                Actor38Field(privateRecord19, int *, 0x48) = -1;
            }
            temporaryWord6 = Actor38Field(privateRecord19, short *, 0x34);
            Actor38Field(privateRecord19, int *, 0x1C) = (int) (Actor38Field(privateRecord19, int *, 0x1C) & ~0x21);
            if (temporaryWord6 != -1) {
                Actor38Call28154View1((int) temporaryWord6);
            }
            Actor38Field(privateRecord19, short *, 0x34) = -1;
        }
        else if (Actor38Field(privateRecord19, void ***, 0x2C) == 0) {
            Actor38Field(privateRecord19, void ***, 0x2C) = Actor38DataSpawnMobyView1(0xA3, ownerRecord20);
        }
        break;
    case 32:
        if (Actor38Call359A4View1(privateRecord19 + 0x24, 4) != 0) {
            temporaryWord7 = Actor38Field(privateRecord19, short *, 0x34);
            Actor38Field(privateRecord19, int *, 0x1C) = (int) (Actor38Field(privateRecord19, int *, 0x1C) & ~0x21);
            if (temporaryWord7 != -1) {
                Actor38Call28154View1((int) temporaryWord7);
            }
            Actor38Field(privateRecord19, short *, 0x34) = -1;
            Actor38Field(ownerRecord20, signed char *, 0x4C) = 0x20;
            Actor38Field(ownerRecord20, signed char *, 0x4D) = 1;
        }
        break;
    }
    rawWord2 = Actor38Field(privateRecord19, int*, 0x1C);
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
    if (Actor38Field(privateRecord19, int *, 0x20) <= 0) {
        temporaryWord8 = Actor38Field(privateRecord19, short *, 0x36);
        Actor38Field(privateRecord19, int *, 0x1C) = (int) (Actor38Field(privateRecord19, int *, 0x1C) & ~0x1E);
        if (temporaryWord8 != -1) {
            Actor38Call28154View1((int) temporaryWord8);
        }
    }
    exit28:;
}
#undef Actor38Field


/* AI-generated; not human reviewed. SCUS-94467 USA Rev0 original
 * 8007B450..8007B77C,204 words govern this actor. Reuses verified raw601 signed trig/packet
 * code; original owner count, collision/reset chain and fresh RNG-selected
 * callbacks13/20 retained. Numeric callback selectors are not labels.
 * Raw coordinates, producer/helper semantics and cadence remain unresolved.
 * Test: independent original object/linked words and every retail hash. */
typedef struct { Vector3D delta; int timer; } DecodedRawProjectileTag;
typedef struct { Vector3D oldPosition; int pad24; Vector3D particlePosition; int pad34; Vector3D direction; int pad44; int reserved48[4]; } DecodedRawProjectileWork;
extern void* DecodedRawProjectilePlayerLink __asm__("D_80070328+0x250");
extern short D_800658A0[], D_80065920[];
void func_level_38_8007B450(Moby* argument) {
    DecodedRawProjectileWork work;
    register Moby* moby __asm__("$17") = argument;
    register DecodedRawProjectileTag* tag __asm__("$19");
    register int x __asm__("$6") = moby->position.x;
    register int y __asm__("$5");
    register int z __asm__("$4");
    register void* retained __asm__("$18");
    register int opposite __asm__("$18");
    register int heading __asm__("$16");
    register Vector3D* position __asm__("$20");
    register void* parent __asm__("$7");
    register int maximum __asm__("$3");
    char* particle;
    register Vector3D* particlePosition __asm__("$19");
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
                    __asm__("" : : : "$18");
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
        particlePosition = &work.particlePosition;
        func_8004F178(particlePosition,&moby->position);
        /* Original Starfish lanes differ from the190-word actor:
         * retain their independent signed samples and computed addresses.
         * The constraints/barrier emit no instructions. */
        {
            register int offset __asm__("$4") = (opposite & 255) * 2;
            register int sample __asm__("$3") = *(short*)((char*)D_80065920 + offset);
            __asm__("" : "=r"(sample) : "0"(sample));
            opposite = heading - 128;
            __asm__("" : "=r"(opposite) : "0"(opposite));
            work.direction.x = (sample * 15) >> 11;
            sample = *(short*)((char*)D_800658A0 + offset);
            __asm__("" : "=r"(sample) : "0"(sample));
            offset = (opposite & 255) * 2;
            work.direction.z = 0;
            __asm__ volatile ("" : : : "memory");
            work.direction.y = (sample * 15) >> 11;
            sample = *(short*)((char*)D_80065920 + offset);
            __asm__("" : "=r"(sample) : "0"(sample));
            work.particlePosition.x += (sample * 5) >> 9;
            sample = *(short*)((char*)D_800658A0 + offset);
            __asm__("" : "=r"(sample) : "0"(sample));
            work.particlePosition.y += (sample * 5) >> 9;
        }
        if (rand() & 7) {
            particle = SpawnParticle(1,13,particlePosition,&work.direction);
            particle[2] = 14;
            particle[10] += 56;
        } else {
            SpawnParticle(1,20,particlePosition,&work.direction);
        }
    }
done:
    if (moby->state != 98) return;
cleanup:
    func_80055B18(moby);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_38/moby", D_level_38_800745B0);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_38/moby", D_level_38_80074630);

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
int Actor8007B780Helper4F554(void*,void*) __asm__("func_8004F554");
int Actor8007B780Helper4F570(void*,void*) __asm__("func_8004F570");
extern unsigned char Actor8007B780D_800676E8[] __asm__("D_800676E8");
extern int Actor8007B780D_8006C58C __asm__("D_8006C58C");
extern int Actor8007B780D_8006C5C8 __asm__("D_8006C5C8");
#define Actor8007B780Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor8007B780Helper13E38(void*,void*,int) __asm__("func_80013E38");
int Actor8007B780Helper19194(void*,int) __asm__("func_80019194");
int Actor8007B780Helper1A358(void*,int) __asm__("func_8001A358");
void* Actor8007B780Helper2F040(int) __asm__("func_8002F040");
int Actor8007B780Helper36188(void*) __asm__("func_80036188");
int Actor8007B780Helper36E60(void*) __asm__("func_80036E60");
int Actor8007B780Helper37014(void*) __asm__("func_80037014");
int Actor8007B780Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Actor8007B780Helper3BFC0(void*,int) __asm__("func_8003BFC0");
int Actor8007B780Helper4E880(int,int,int) __asm__("func_8004E880");
int Actor8007B780Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Actor8007B780Helper4EDE8(void*,int) __asm__("func_8004EDE8");
int Actor8007B780Helper4EF74(void*,void*,void*) __asm__("func_8004EF74");
int Actor8007B780Helper4F110(void*,int) __asm__("func_8004F110");
int Actor8007B780Helper4F178(void*,void*) __asm__("func_8004F178");
int Actor8007B780Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Actor8007B780Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Actor8007B780Helper4F1FC(void*,void*,int) __asm__("func_8004F1FC");
int Actor8007B780Helper4F228(void*,void*,int) __asm__("func_8004F228");
int Actor8007B780Helper4F264(int,int) __asm__("func_8004F264");
int Actor8007B780Helper4F334(void*,void*) __asm__("func_8004F334");
int Actor8007B780Helper4F52C(void*,void*) __asm__("func_8004F52C");
int Actor8007B780Helper4F5DC(int,void*) __asm__("func_8004F5DC");
int Actor8007B780Helper55B18(void*) __asm__("func_80055B18");
int Actor8007B780Helper55D24(void*,int) __asm__("func_80055D24");
int Actor8007B780Helper56270(void*) __asm__("func_80056270");
int Actor8007B780Helper5629C(void*) __asm__("func_8005629C");
extern int Actor8007B780D_80065810 __asm__("D_80065810");
extern int Actor8007B780D_80065818 __asm__("D_80065818");
extern unsigned char Actor8007B780D_800658A0[] __asm__("D_800658A0");
extern unsigned char Actor8007B780D_80065920[] __asm__("D_80065920");
extern unsigned char Actor8007B780D_80066964[] __asm__("D_80066964");
extern unsigned char Actor8007B780D_80066988[] __asm__("D_80066988");
extern unsigned char Actor8007B780D_80066990[] __asm__("D_80066990");
extern unsigned char Actor8007B780D_80066A48[] __asm__("D_80066A48");
extern int Actor8007B780D_8006C648 __asm__("D_8006C648");
extern void * Actor8007B780D_8006C65C __asm__("D_8006C65C");
extern unsigned char Actor8007B780D_8006DEF8[] __asm__("D_8006DEF8");
extern int Actor8007B780D_8006E020 __asm__("D_8006E020");
extern int Actor8007B780D_8006E024 __asm__("D_8006E024");
extern unsigned short Actor8007B780D_8006E040 __asm__("D_8006E040");
extern unsigned char Actor8007B780D_80070328[] __asm__("D_80070328");
extern int Actor8007B780D_80071908 __asm__("D_80071908");
extern unsigned char Actor8007B780D_80071918[] __asm__("D_80071918");
extern int Actor8007B780D_8007192C __asm__("D_8007192C");
extern int (*Actor8007B780SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
void func_level_38_8007B780(void *input) {
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
    tag = Actor8007B780Field(owner, void **, 0);
    temp_v0 = Actor8007B780Helper4F334(workingPosition, Actor8007B780D_80070328);
    {register int old3 __asm__("$3")=Actor8007B780Field(tag,short*,0xA);
     register int old __asm__("$4");register int predicate __asm__("$3");
     __asm__("" : "=r"(old3),"=r"(temp_v0):"0"(old3),"1"(temp_v0));
     old=old3;predicate=old3<0x218;
     __asm__("" : "=r"(old),"=r"(predicate),"=r"(temp_v0):"0"(old),"1"(predicate),"2"(temp_v0));
     distanceResult=temp_v0;
     if(predicate) {
       temp_v0=Actor8007B780D_8006C648;
       temp_v0=old+temp_v0;
       Actor8007B780Field(tag,short*,0xA)=temp_v0;
     } else {
        selectedResource=Actor8007B780Helper2F040(Actor8007B780Field(owner,unsigned char*,0x49));
        if (selectedResource != 0) {
            if (distanceResult < 0x3000) {
                Actor8007B780Field(tag, unsigned char *, 0x13) = (unsigned char) ((int) (selectedResource - Actor8007B780D_8006DEF8) >> 4);
                Actor8007B780Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007B780Field(tag, short *, 0xA) - 0x20);
                Actor8007B780Field(tag, unsigned char *, 0x14) = (unsigned char) ((Actor8007B780Field(owner, unsigned char *, 0x49) * 2) + (rand() & 1));
            } else {
                Actor8007B780Helper4F178(selectedResource, workingPosition);
                if (distanceResult <= 0x7FFF) {
                    Actor8007B780Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007B780Field(tag, short *, 0xA) - 0x80);
                    Actor8007B780Field(selectedResource, int *, 8) = (int) (Actor8007B780Field(selectedResource, int *, 8) + 0x80);
                } else {
                    Actor8007B780Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007B780Field(tag, short *, 0xA) - 0x100);
                }
                Actor8007B780Field(tag, unsigned char *, 0x13) = 0xFFU;
            }
            Actor8007B780Field(selectedResource, unsigned char *, 0xD) = (unsigned char) (Actor8007B780Field(selectedResource, unsigned char *, 0xD) + (rand() & 0x3F));
        } else {
            Actor8007B780Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007B780Field(tag, short *, 0xA) - 0x100);
        }
        Actor8007B780Field(tag, short *, 0xA) = (short) ((unsigned short) Actor8007B780Field(tag, short *, 0xA) - (rand() & 0xFF));
    }
    }
    temp_s0 = Actor8007B780Field(tag, unsigned char *, 0x13);
    __asm__("" : "=r"(temp_s0) : "0"(temp_s0));
    selectorOwner=owner;
    if (temp_s0 < 0x10U) {
        __asm__("" : "=r"(selectorOwner) : "0"(selectorOwner));
        selectorMode=4;
        __asm__("" : "=r"(selectorMode) : "0"(selectorMode));
        temp_s0*=16;
        __asm__("" : "=r"(temp_s0) : "0"(temp_s0) : "$2");
        {register unsigned char *base __asm__("$2")=Actor8007B780D_8006DEF8;
         resourceRecord=(unsigned char*)(temp_s0+(int)base);}
        Actor8007B780Helper55D24(selectorOwner,selectorMode);
        Actor8007B780Helper4F178(resourceRecord, (Actor8007B780Field(tag, unsigned char *, 0x14) * 0xC) + (Actor8007B780D_80066A48 + 0x30));
        Actor8007B780Helper4F1FC(resourceRecord,resourceRecord,2);
        Actor8007B780Helper4ED6C(owner + 0x20, resourceRecord, resourceRecord);
        Actor8007B780Helper4F194(resourceRecord, resourceRecord, owner + 0xC);
        if ((unsigned char) Actor8007B780Field(resourceRecord, unsigned char *, 0xC) < 4U) {
            Actor8007B780Field(tag, unsigned char *, 0x13) = 0xFFU;
        }
    }
    if ((Actor8007B780Field(owner, unsigned char *, 0x4D) != 0) || (distanceResult < 0x1801) || (Actor8007B780Field(owner, unsigned char *, 0x48) != 1) || (Actor8007B780Field(tag, unsigned char *, 0x11) != 0)) {
        {register unsigned char *base __asm__("$4")=Actor8007B780D_800676E8;
         register int row __asm__("$3");register int column __asm__("$2");register int height __asm__("$3");
         __asm__("" : "=r"(base):"0"(base):"$3","$2");
         row=Actor8007B780D_8006C58C;column=Actor8007B780D_8006C5C8;
         __asm__("" : "=r"(row),"=r"(column):"0"(row),"1"(column));
         row=row*16+(int)base;
         __asm__("" : "=r"(row):"0"(row));
         column=column*4+row;
         __asm__("" : "=r"(column):"0"(column):"$3");
         height=Actor8007B780Field(owner,int*,0x14);column=*(int*)column;
         if (column >= height) {
            Actor8007B780Helper4F178(owner + 0xC, Actor8007B780D_80070328);
        }
        }
        temp_v1 = Actor8007B780Field(owner, unsigned char *, 0x48);
        switch (temp_v1) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            Actor8007B780Helper4F178(&frame.first.x, owner + 0xC);
            frame.first.z += 0x400;
            Actor8007B780Helper1A358(&frame.first.x, 0x10000);
            Actor8007B780Helper36188(tag + 0xE);
            if (Actor8007B780Field(tag, int *, 0xC) & 0xFFFF0000) {
                Actor8007B780Field(owner, unsigned char *, 0x46) = 0U;
            }
            Actor8007B780Field(owner, int *, 0x14) = (int) Actor8007B780D_80071908;
            Actor8007B780Field(tag, short *, 0xA) = (short) ((rand() & 0xFF) + 0x100);
            Actor8007B780Field(owner, unsigned char *, 0x48) = 1U;
            temp_v0_2 = *(Actor8007B780D_80066964 + Actor8007B780Field(owner, unsigned char *, 0x50));
            Actor8007B780Field(owner, unsigned char *, 0x49) = temp_v0_2;
            Actor8007B780Field(owner, unsigned char *, 0x3C) = (unsigned char) *(Actor8007B780D_80066988 + (temp_v0_2 & 0xFF));
            Actor8007B780Field(owner, unsigned char *, 0x54) = (unsigned char) *(Actor8007B780D_80066990 + Actor8007B780Field(owner, unsigned char *, 0x49));
            goto block_75;
        case 1:                                     /* switch 1 */
            if (Actor8007B780Field(tag, short *, 0xA) >= 0x1E) {
                __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult) : "$4");
                temp_a0 = Actor8007B780Field(Actor8007B780D_80070328, int *, 0x44);
                if (({register int pred __asm__("$2")=distanceResult < temp_a0+0x180;__asm__("" : "=r"(pred):"0"(pred));pred;})) {
                    temp_v1_3 = Actor8007B780Field(Actor8007B780D_80070328, int *, 8) - Actor8007B780Field(owner, int *, 0x14);
                    if (temp_v1_3 < temp_a0+0x80) {
                        var_v0_2=-Actor8007B780Field(Actor8007B780D_80070328,int*,0x44);
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
            Actor8007B780Helper4F554(workingPosition,tag+4);
            Actor8007B780Helper4F1FC(workingPosition,workingPosition,Actor8007B780D_8006C648);
            Actor8007B780Helper4F110(workingPosition,1);
            {register void *first __asm__("$4")=workingPosition;
             __asm__("" : "=r"(first) : "0"(first) : "$20");
             ownerPosition=owner+12;
             Actor8007B780Helper4F194(first,ownerPosition,workingPosition);}
            temp_v0_4=Actor8007B780Field(tag,short*,8);
            __asm__("" : "=r"(temp_v0_4) : "0"(temp_v0_4));
            {register int old __asm__("$4")=temp_v0_4;
             temp_v0_4=temp_v0_4 < -215;
             if(!temp_v0_4) {
               register int delta __asm__("$3")=Actor8007B780D_8006C648;
               register int product __asm__("$2");
               __asm__("" : "=r"(old),"=r"(delta) : "0"(old),"1"(delta));
               product=delta*5;product=old-product;
               Actor8007B780Field(tag,short*,8)=product;
             }}
            if (frame.fifth.z < 0x400) {
                Actor8007B780Helper36E60(owner);
                Actor8007B780Helper55B18(owner);
                return;
            }
            frame.fifth.z += 0xF0;
            if (Actor8007B780Helper19194(workingPosition, 0xF0) != 0) {
                stateTwoNormal=&frame.sixth.x;
                __asm__("" : "=r"(stateTwoNormal) : "0"(stateTwoNormal));
                Actor8007B780Helper4F178(stateTwoNormal,Actor8007B780D_80071918);
                Actor8007B780Helper4F178(ownerPosition, Actor8007B780D_80071918 - 0xC);
                Actor8007B780Field(owner, int *, 0x14) = (int) (Actor8007B780Field(owner, int *, 0x14) - 0xF0);
                if (Actor8007B780Field(tag, unsigned char *, 0x12) == 0) {
                    {register int height __asm__("$2")=Actor8007B780Helper1A358(workingPosition,0x400);
                     register void *first __asm__("$4")=stateTwoNormal;
                     register int zero __asm__("$5")=0;
                     register int magnitude __asm__("$5");
                     register int signedAngle __asm__("$2");
                     __asm__("" : "=r"(first),"=r"(zero) : "0"(first),"1"(zero) : "$16");
                     sampledHeight=height;
                     magnitude=Actor8007B780Helper4EDE8(first,zero);
                     signedAngle=Actor8007B780Helper4E880(frame.sixth.z,magnitude,0);
                     signedAngle<<=24;
                     __asm__("" : "=r"(signedAngle) : "0"(signedAngle));
                     signedAngleResult=signedAngle>>24;}
                    if (((frame.fifth.z - 0x190) < sampledHeight) && (signedAngleResult < 0x18)) {
                        Actor8007B780Field(owner, unsigned char *, 0x48) = 1U;
                        Actor8007B780Helper4F178(ownerPosition, workingPosition);
                        Actor8007B780Field(owner, int *, 0x14) = sampledHeight;
                        Actor8007B780Helper36188(tag + 0xE);
                        if (Actor8007B780Field(tag, int *, 0xC) & 0xFFFF0000) {
                            Actor8007B780Field(owner, unsigned char *, 0x46) = 0U;
                        }
                        Actor8007B780Field(owner, signed char *, 0x52) = 0;
                        Actor8007B780Helper56270(owner);
                        Actor8007B780Helper5629C(owner);
                    } else {
                        Actor8007B780Field(tag, unsigned char *, 0x12) = (unsigned char) (Actor8007B780Field(tag, unsigned char *, 0x12) + 1);
                    }
                    if (Actor8007B780Field(tag, unsigned char *, 0x12) != 0) {
                        goto block_52;
                    }
                } else {
block_52:
                    stateThreeDelta=&frame.seventh.x;
                    {register void *arg __asm__("$4")=stateThreeDelta;
                     __asm__("" : "=r"(arg):"0"(arg):"$19");
                     workingPosition=tag+4;
                     Actor8007B780Helper4F554(arg,workingPosition);}
                    {register int result __asm__("$2")=Actor8007B780Helper4EF74(&frame.seventh.x, &frame.sixth.x, &frame.seventh.x);
                     register void *arg __asm__("$4")=workingPosition;
                     if(result != 0) {
                        Actor8007B780Field(tag, unsigned char *, 0x12) = (unsigned char) (Actor8007B780Field(tag, unsigned char *, 0x12) - 1);
                        frame.seventh.x=(frame.seventh.x>>3)+(rand()&0x3F)-0x20;
                        frame.seventh.y=(frame.seventh.y>>3)+(rand()&0x3F)-0x20;
                        frame.seventh.z=(frame.seventh.z>>2)+(rand()&0xF);
                        Actor8007B780Helper3BABC(owner, 1, 0);
                    }
                    Actor8007B780Helper4F570(workingPosition,stateThreeDelta);
                }
            }
            } else {
                frame.fifth.z -= 0xF0;
                Actor8007B780Helper4F178(ownerPosition, workingPosition);
                Actor8007B780Helper1A358(workingPosition, 0x10000);
                Actor8007B780Helper5629C(owner);
            }
            __asm__ volatile("" ::: "memory");
            if (Actor8007B780Field(tag, short *, 0xA) >= 0x1E) {
                __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult) : "$5");
                temp_a0_2 = Actor8007B780Field(Actor8007B780D_80070328, int *, 0x44) + 0x80;
                if (({register int pred __asm__("$2")=distanceResult < temp_a0_2;__asm__("" : "=r"(pred):"0"(pred));pred;})) {
                    temp_v1_4 = Actor8007B780Field(Actor8007B780D_80070328, int *, 8) - Actor8007B780Field(owner, int *, 0x14);
                    if (temp_v1_4 < temp_a0_2) {
                        var_v0_2=-Actor8007B780Field(Actor8007B780D_80070328,int*,0x44);
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
            Actor8007B780Helper4F554(stateThreeVector,tag+4);
            if (Actor8007B780Field(tag, short *, 0xA) >= 30) {
                Actor8007B780Helper4F178(owner + 0xC, Actor8007B780D_80070328);
            } else {
                stateThreeDelta=&frame.delta.x;
                __asm__("" : "=r"(stateThreeDelta) : "0"(stateThreeDelta) : "$20");
                {register void *first __asm__("$4")=stateThreeDelta;
                 __asm__("" : "=r"(first) : "0"(first) : "$20");
                 savedPlayer=Actor8007B780D_80070328;
                 Actor8007B780Helper4F1C8(first,savedPlayer,stateThreeVector);}
                Actor8007B780Helper4F228(stateThreeDelta, stateThreeDelta, 30);
                if (Actor8007B780Helper4EDE8(stateThreeDelta, 1) >= 0x1E1) {
                    Actor8007B780Helper4F178(owner+12,savedPlayer);
                    Actor8007B780Field(tag,short*,0xA)=30;
                } else {
                    Actor8007B780Helper4F1FC(stateThreeDelta, stateThreeDelta, Actor8007B780Field(tag, short *, 0xA));
                    Actor8007B780Helper4F194(owner + 0xC, stateThreeVector, stateThreeDelta);
                    Actor8007B780Field(owner, int *, 0x14) = (int) (Actor8007B780Field(owner, int *, 0x14) + (short)((short) *(unsigned short*)(Actor8007B780D_800658A0 + (Actor8007B780Field(tag, short *, 0xA) * 8)) / 10));
                }
            }
            {register int offset __asm__("$2")=Actor8007B780Field(tag,unsigned char*,0xE);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Actor8007B780Field(owner,unsigned char*,0x44);
              offset+=249;old+=offset;Actor8007B780Field(owner,unsigned char*,0x44)=old;}
            {register int offset __asm__("$2")=Actor8007B780Field(tag,unsigned char*,0xF);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Actor8007B780Field(owner,unsigned char*,0x45);
              offset+=249;old+=offset;Actor8007B780Field(owner,unsigned char*,0x45)=old;}
            {register int offset __asm__("$2")=Actor8007B780Field(tag,unsigned char*,0x10);
              register int old __asm__("$3");
              __asm__("" : "=r"(offset) : "0"(offset) : "$3");
              old=Actor8007B780Field(owner,unsigned char*,0x46);
              offset+=249;old+=offset;Actor8007B780Field(owner,unsigned char*,0x46)=old;}
            if ((Actor8007B780Field(tag, short *, 0xA) < 0x1E) || (temp_a0_3 = Actor8007B780Field(Actor8007B780D_80070328, int *, 0x44) + 0x80, ((({register int pred __asm__("$2")=distanceResult < temp_a0_3;__asm__("" : "=r"(pred):"0"(pred));pred;})) == 0)) || (temp_v1_5 = Actor8007B780Field(Actor8007B780D_80070328, int *, 8) - Actor8007B780Field(owner, int *, 0x14), ((temp_v1_5 < temp_a0_3) == 0)) || (-Actor8007B780Field(Actor8007B780D_80070328, int *, 0x44) >= temp_v1_5)) {
                var_v0_2 = Actor8007B780Field(tag, short *, 0xA) < 65;
                if(!var_v0_2) Actor8007B780Field(owner,unsigned char*,0x48)=4;
                goto block_75;
            }
            goto block_70;
block_70:
            Actor8007B780Field(owner,unsigned char*,0x48)=4;
            goto block_75;
        case 4:                                     /* switch 1 */
            Actor8007B780Helper55D24(owner, 4);
            Actor8007B780SpawnParticle(4,12,owner,Actor8007B780Field(owner,unsigned char*,0x49));
            Actor8007B780SpawnParticle(4,12,owner,Actor8007B780Field(owner,unsigned char*,0x49));
            Actor8007B780Helper36E60(owner);
            Actor8007B780Helper3BABC(owner, 0, 0);
            Actor8007B780Helper55B18(owner);
            goto block_75;
        }
block_75:
            if ((unsigned char) Actor8007B780Field(owner, unsigned char *, 0x48) < 3U) {

                {register int sample __asm__("$2")=*(unsigned short*)(Actor8007B780D_80065920+(Actor8007B780Field(tag,unsigned char*,0x10)*2));
                  register int base __asm__("$3");
                  __asm__("" : "=r"(sample) : "0"(sample) : "$3");
                  base=Actor8007B780Field(tag,unsigned char*,0xE);
                  __asm__("" : "=r"(sample),"=r"(base) : "0"(sample),"1"(base));
                  sample=(sample<<16)>>23;sample+=base;
                  Actor8007B780Field(owner,unsigned char*,0x44)=sample;}
                {register int sample __asm__("$2")=*(unsigned short*)(Actor8007B780D_800658A0+(Actor8007B780Field(tag,unsigned char*,0x10)*2));
                  register int base __asm__("$3");
                  __asm__("" : "=r"(sample) : "0"(sample) : "$3");
                  base=Actor8007B780Field(tag,unsigned char*,0xF);
                  __asm__("" : "=r"(sample),"=r"(base) : "0"(sample),"1"(base));
                  sample=(sample<<16)>>23;sample+=base;
                  Actor8007B780Field(owner,unsigned char*,0x45)=sample;}
                Actor8007B780Field(tag, unsigned char *, 0x10) = (unsigned char) (Actor8007B780Field(tag, unsigned char *, 0x10) + (Actor8007B780D_8006C648 * 2));
            }
    }
}
#undef Actor8007B780Field


/* AI-generated; not human reviewed. Verified 7CC40 C sibling plus
 * original level38 private +0x50/owner +0x4D spawn branch and raw stores.
 * Helper meanings, units and cadence remain unresolved. See sibling3802. */
extern void *(*P7CC40SpawnMoby)(int,void*) __asm__("SpawnMoby");
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
void func_level_38_8007C10C(void *owner) {
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
            if (P7CC40Field(privateState,void**,0x50)==0) {
                register unsigned int visible __asm__("$2")=P7CC40Field(owner,unsigned char*,0x4D);
                __asm__("" : "=r"(visible) : "0"(visible));
                helperKind4=0x2A9;
                if(visible != 0) {
                register void *child __asm__("$2");
                register void *childData __asm__("$4");
                register int literal __asm__("$3");
                register unsigned int model __asm__("$5");
                child=P7CC40SpawnMoby(helperKind4,owner);
                childData=P7CC40Field(child,void**,0);
                __asm__("" : "=r"(childData) : "0"(childData) : "$3");
                literal=1;
                P7CC40Field(childData,void**,8)=owner;
                P7CC40Field(childData,short*,0)=literal;
                __asm__ volatile("" : : : "memory");
                model=P7CC40Field(owner,unsigned short*,0x36);
                __asm__("" : "=r"(model) : "0"(model) : "$3");
                literal=28;
                __asm__("" : "=r"(literal),"=r"(model) : "0"(literal),"1"(model));
                P7CC40Field(childData,int*,4)=literal;
                literal=8;
                __asm__("" : "=r"(literal),"=r"(model) : "0"(literal),"1"(model));
                P7CC40Field(childData,unsigned short*,2)=model;
                P7CC40Field(child,unsigned char*,0x4F)=literal;
                literal=7;
                P7CC40Field(child,unsigned char*,0x47)=literal;
                P7CC40Field(privateState,void**,0x50)=child;
                }
            }
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
void func_level_38_8007C900(Moby* argument) {
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
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_38/moby/func_level_38_8007CBE8.s SHA256 fedbeefaea84ae022476cbb390fed22764ed4fb6716f24a96ab5da9d1fafd056. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level38_7CBE8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Level38_7CBE8_func_80013E38(Vector3D*, Vector3D*, int) __asm__("func_80013E38");
         /* extern */
void Level38_7CBE8_func_80034F40(Moby*, int) __asm__("func_80034F40");
             /* extern */
int Level38_7CBE8_func_8003573C(Moby*, int, int, int) __asm__("func_8003573C");
 /* extern */
int Level38_7CBE8_func_8003585C(Moby*, int, int, int, int, int) __asm__("func_8003585C");
 /* extern */
int Level38_7CBE8_func_800359A4(void*, int) __asm__("func_800359A4");
                 /* extern */
int Level38_7CBE8_func_80035DDC(Moby*, int, int, int, int) __asm__("func_80035DDC");
 /* extern */
int Level38_7CBE8_func_80036220(Vector3D*, char*, int, int) __asm__("func_80036220");
 /* extern */
int Level38_7CBE8_func_8003645C(Vector3D*, void*, int*) __asm__("func_8003645C");
       /* extern */
void Level38_7CBE8_func_800369B8(Moby*, int) __asm__("func_800369B8");
             /* extern */
void Level38_7CBE8_func_8003BA00(Moby*) __asm__("func_8003BA00");
                      /* extern */
int Level38_7CBE8_func_8003BABC(Moby*, int, int) __asm__("func_8003BABC");
    /* extern */
int Level38_7CBE8_func_8004E880(int, int, int) __asm__("func_8004E880");
          /* extern */
void Level38_7CBE8_func_8004F110(Vector3D*, int) __asm__("func_8004F110");
              /* extern */
void Level38_7CBE8_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
               /* extern */
int Level38_7CBE8_func_8004F334(Vector3D*, Vector3D*) __asm__("func_8004F334");
                   /* extern */
void Level38_7CBE8_func_80055B18(Moby*) __asm__("func_80055B18");
                      /* extern */
void Level38_7CBE8_func_80055D24(Moby*, int) __asm__("func_80055D24");
             /* extern */
int Level38_7CBE8_rand() __asm__("rand");
                                         /* extern */
extern short Level38_7CBE8_D_800658A0[] __asm__("D_800658A0");
extern short Level38_7CBE8_D_80065920 __asm__("D_80065920");
extern Spyro Level38_7CBE8_D_80070328 __asm__("D_80070328");
extern void *Level38_7CBE8_D_80071930 __asm__("D_80071930");
extern char *(*Level38_7CBE8_SpawnParticle)(int,int,Vector3D*,Vector3D*) __asm__("SpawnParticle");
extern int (*Level38_7CBE8_unk_ovlheader_800743C4)(unsigned char*,Vector3D*,Vector3D*) __asm__("unk_ovlheader_800743C4");
extern void (*Level38_7CBE8_unk_ovlheader_800743E0)(int,int) __asm__("unk_ovlheader_800743E0");

void func_level_38_8007CBE8(void *ownerRecord) {
    /* Original SCUS-94467 8007CBE8;
     assembly SHA256 above.
     * Frame0x60: scratchSP18..3F, saved16..21 at40..54 andRA58.
     * Byte record offsets, signed LH path count/index and signed LH tables
     * preserve disc operands. Particle table cursor advances0x48 bytes,
     * and its independent table index advances0x24 elements per iteration.
     * The original seven-iteration back edge remains an explicit label:
     * the old compiler's structured loop hoists658A0 into an extra saved
     * register, changing frame, loads and operands. No compiler flags change.
     * Callback slots800743C4/E0 resolve to80085154/800852B4 in level38;
     * particle slot800742E4 resolves to800869A8. Existing matched bodies
     * and contracts14576.json record the producer/interface source chain.
     * Verified4F110 consumes vector4/shift5 and writes three words.
     * Helper369B8 forwards raw4/5 to2E2D0;
      no SFX meaning is asserted.
     * Empty constraints retain initialized raw math4/5/6/7, shared terminal
     * owner4/selector5, distinct null-path zeros, post-call owner identity,
     * signed threshold2 and post-return default flag19. No CPU opcodes.
     * State0 reloads path index AFTER3645C. Its owner identity after34F40
     * preserves separate position4 calculations on the two original paths.
     * Units/fixed point, helper meanings and caller cadence unresolved.
     * Cadence per invocation. No synchronized runtime/subsystem claim.
     * Falsification:435 instructions and owned dispatch data, every native
     * and linked operand/transfer, full EXE/every-overlay original hashes.
     * AI generated;
      not human reviewed. */
    struct { Vector3D pathPosition;
     unsigned char pad24[4];
     int selectedIndex;
     unsigned char pad2C[4];
     Vector3D particleVector;
     unsigned char pad3C[4];
     } scratch;

    register Vector3D *particleVector20 __asm__("20");
    register Moby *terminalOwner4 __asm__("4");
    register int terminalSelector5 __asm__("5");
    register Moby *animationOwner4 __asm__("4");
    register int animationSelector5 __asm__("5");
    unsigned int unusedSelector;
    register short *particleTableCursor19 __asm__("$19");
    int previousPathIndex;
    register int angleZero6 __asm__("6");
    int movementFlags;
    register Moby *aimOwner4 __asm__("4");
    int ownerX;
    register int initialDistance20 __asm__("20");
    int initialNearCheck;
    int helperDistance;
    register int pathDeltaX4 __asm__("4");
    register int state5DeltaX4 __asm__("4");
    register int pathDeltaY5 __asm__("5");
    register int state5DeltaY5 __asm__("5");
    register int particleIndex17 __asm__("$17");
    register int particleTableIndex18 __asm__("$18");
    register int defaultCheck19 __asm__("$19");
    register int activationCheck19 __asm__("$19");
    int unusedRangeCheck;
    int movementAngle;
    unsigned int privateFlags;
    unsigned int activationFlags;
    unsigned int state1Flags;
    unsigned int initialState;
    unsigned int state;
    register void *privateRecord17 __asm__("$17");
    register void *pathRecord18 __asm__("$18");
    register void *ownerPosition21 __asm__("$21");
    void *positionPointer;

    privateRecord17 = Level38_7CBE8Field(ownerRecord, void **, 0);
    pathRecord18 = Level38_7CBE8Field(privateRecord17, void **, 0x38);
    defaultCheck19 = 0;
    if (Level38_7CBE8Field(ownerRecord, int *, 0x18) != 0) {
        initialState = Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48);
        if (initialState != 2) {
            if ((initialState == 0) && (Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C) & 4)) {
                Level38_7CBE8_unk_ovlheader_800743E0(Level38_7CBE8Field(ownerRecord, unsigned char *, 0x43), 1);
            }
            Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C) = (unsigned short) (Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C) | 0x80);
            Level38_7CBE8Field(ownerRecord, int *, 8) = 0;
            Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 2U;
            Level38_7CBE8_func_8003BABC(ownerRecord, 0, 0);
        }
    }
    initialDistance20 = Level38_7CBE8_func_8004F334(ownerRecord + 0xC, &Level38_7CBE8_D_80070328);
    state = Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48);
    if ((state != 2) && ({ register int near2 __asm__("2"); near2 = initialDistance20 < 0x400; __asm__("" : "=r"(near2) : "0"(near2)); near2; })) {
        terminalOwner4 = ownerRecord;
         __asm__("" : "=r"(terminalOwner4) : "0"(terminalOwner4));
        Level38_7CBE8Field(&Level38_7CBE8_D_80070328, int *, 0x24) = (int) (Level38_7CBE8Field(&Level38_7CBE8_D_80070328, int *, 0x24) | 1);
        { register int flags2 __asm__("2");
         flags2 = Level38_7CBE8Field(privateRecord17,unsigned short*,0x1C);
         __asm__ volatile("" : : "r"(flags2) : "5");
         terminalSelector5 = 4;
         flags2 |= 0x80;
         Level38_7CBE8Field(privateRecord17,unsigned short*,0x1C) = flags2;
         }
        goto sharedTerminalCall;
    }
    switch (state) {
    case 0:
        aimOwner4 = ownerRecord;
        if (pathRecord18 == 0) {
            __asm__ volatile("" : "=r"(pathRecord18) : "0"(pathRecord18));
            Level38_7CBE8_func_8003573C(aimOwner4, 5, 0, 0);
        }
        privateFlags = Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C);
        if (privateFlags & 0x80) {
            Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C) = (unsigned short) (privateFlags & 0xFF7F);
            Level38_7CBE8Field(privateRecord17, signed char *, 0x1A) = 0x3C;
            Level38_7CBE8_func_80034F40(ownerRecord, 1);
            Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 3U;
        } else {
            defaultCheck19 = 1;
            if (pathRecord18 != 0) {
                positionPointer = ownerRecord + 0xC;
                if (Level38_7CBE8Field(ownerRecord, unsigned short *, 0x3C) == 0) {
                    Level38_7CBE8_func_80034F40(ownerRecord, 1);
                    __asm__("" : "=r"(ownerRecord) : "0"(ownerRecord));
                    positionPointer = ownerRecord + 0xC;
                }
                helperDistance = Level38_7CBE8_func_8003645C(positionPointer, pathRecord18, &scratch.selectedIndex);
                previousPathIndex = Level38_7CBE8Field(pathRecord18, short *, 2);
                if ((scratch.selectedIndex != previousPathIndex) && (helperDistance >= 0x201)) {
                    if (previousPathIndex == 0) {
                        if (scratch.selectedIndex == (Level38_7CBE8Field(pathRecord18, short *, 0) - 1)) {

                        } else {
                            goto storePathIndex;
                        }
                    } else if (scratch.selectedIndex != (previousPathIndex - 1)) {
storePathIndex:
                        Level38_7CBE8Field(pathRecord18, short *, 2) = (short) scratch.selectedIndex;
                    }
                }
                Level38_7CBE8_func_8004F178(&scratch.pathPosition, Level38_7CBE8Field(pathRecord18, int *, 0xC) + (Level38_7CBE8Field(pathRecord18, short *, 2) * 0x10));
                movementFlags = Level38_7CBE8_func_80035DDC(ownerRecord, 0x50, 0x400, 0x400, 0x23);
                 angleZero6 = 0;
        if (movementFlags & 0x20) {
                    { register void *target2 __asm__("2");
                     register int ownX7 __asm__("7");
                     register int ownY3 __asm__("3");
                     target2 = Level38_7CBE8_D_80071930;
                     ownX7 = Level38_7CBE8Field(ownerRecord,int*,0xC);
                     ownY3 = Level38_7CBE8Field(ownerRecord,int*,0x10);
                     pathDeltaX4 = Level38_7CBE8Field(target2,int*,0xC);
                     pathDeltaY5 = Level38_7CBE8Field(target2,int*,0x10);
                     pathDeltaX4 = ownX7 - pathDeltaX4;
                     pathDeltaY5 = ownY3 - pathDeltaY5;
                     }
                } else {
                    { register int first3 __asm__("3");
                     register int second2 __asm__("2");
                     first3 = scratch.pathPosition.x;
                     pathDeltaX4 = Level38_7CBE8Field(ownerRecord,int*,0xC);
                     second2 = scratch.pathPosition.y;
                     pathDeltaY5 = Level38_7CBE8Field(ownerRecord,int*,0x10);
                     pathDeltaX4 = first3 - pathDeltaX4;
                     pathDeltaY5 = second2 - pathDeltaY5;
                     }
                }
                __asm__("" : "=r"(pathDeltaX4), "=r"(pathDeltaY5), "=r"(angleZero6) : "0"(pathDeltaX4), "1"(pathDeltaY5), "2"(angleZero6));
        Level38_7CBE8_func_8003585C(ownerRecord, Level38_7CBE8_func_8004E880(pathDeltaX4, pathDeltaY5, angleZero6) & 0xFF, 5, 0, 1, 0);
                if (Level38_7CBE8_func_8004F334(ownerRecord + 0xC, &scratch.pathPosition) < 0x200) {
                    Level38_7CBE8Field(pathRecord18, short *, 2) = (short) ((int) (Level38_7CBE8Field(pathRecord18, short *, 2) + 1) % (short) Level38_7CBE8Field(pathRecord18, short *, 0));
                }
            }
        }
        goto checkActivation;
    case 1:
        if (initialDistance20 < 0x4075) {
            state1Flags = Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C);
            if (state1Flags & 2) {
                Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C) = (unsigned short) ((state1Flags & 0xFFFD) | 1);
            }
            if (Level38_7CBE8_func_80035DDC(ownerRecord, 0x50, 0x400, 0x400, 0x23) & 0x20) {
                ownerX = Level38_7CBE8Field(ownerRecord, int *, 0xC);
                movementAngle = Level38_7CBE8_func_8004E880(ownerX - Level38_7CBE8Field(Level38_7CBE8_D_80071930, int *, 0xC), Level38_7CBE8Field(ownerRecord, int *, 0x10) - Level38_7CBE8Field(Level38_7CBE8_D_80071930, int *, 0x10), 0);
            } else {
                movementAngle = Level38_7CBE8_unk_ovlheader_800743C4(ownerRecord + 0x49, ownerRecord + 0xC, &Level38_7CBE8_D_80070328);
            }
            Level38_7CBE8_func_8003585C(ownerRecord, movementAngle & 0xFF, 5, 0, 1, 0);
        } else {
            goto storeState4;
        }
        goto checkActivation;
    case 2:
        particleIndex17 = 0;
        particleTableIndex18 = Level38_7CBE8_rand() & 0xFF;
        ownerPosition21 = ownerRecord + 0xC;
        particleVector20 = (Vector3D *)&scratch.particleVector;
         __asm__("" : "=r"(particleVector20) : "0"(particleVector20));
        { register short *base3 __asm__("3");
         register int offset2 __asm__("2");
         base3 = &Level38_7CBE8_D_80065920;
         __asm__("" : "=r"(base3) : "0"(base3));
         offset2 = particleTableIndex18 * 2;
         particleTableCursor19 = (short *)(offset2 + (int)base3);
         }
particleLoop:
            scratch.particleVector.x = (int) (*particleTableCursor19 * 3) >> 8;
            scratch.particleVector.y = (int) (Level38_7CBE8_D_800658A0[particleTableIndex18] * 3) >> 8;
            scratch.particleVector.z = 0;
            Level38_7CBE8_SpawnParticle(1, 0x14, ownerPosition21, particleVector20);
            if (particleIndex17 & 1) {
                Level38_7CBE8_func_8004F110(particleVector20, 1);
                Level38_7CBE8_SpawnParticle(1, 0x14, ownerPosition21, particleVector20);
            }
            particleTableCursor19 = (short *)((unsigned char *)particleTableCursor19 + 0x48);
            particleIndex17 += 1;
            particleTableIndex18 += 0x24;
        if (particleIndex17 < 7) goto particleLoop;
        terminalOwner4 = ownerRecord;
         terminalSelector5 = 4;
         __asm__("" : "=r"(terminalOwner4), "=r"(terminalSelector5) : "0"(terminalOwner4), "1"(terminalSelector5));
sharedTerminalCall:
        Level38_7CBE8_func_80055D24(terminalOwner4, terminalSelector5);
        Level38_7CBE8_func_8003BA00(ownerRecord);
        Level38_7CBE8_func_800369B8(ownerRecord, 0x28);
        Level38_7CBE8_func_80055B18(ownerRecord);
        return;
    case 3:
        Level38_7CBE8_func_80035DDC(ownerRecord, 0x50, 0, 0x400, 0x21);
        if (Level38_7CBE8_func_800359A4(privateRecord17 + 0x1A, 1) != 0) {
storeState4:
            Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 4U;
        }
        goto checkActivation;
    case 4:
        Level38_7CBE8_func_80035DDC(ownerRecord, 0x50, 0, 0x400, 0x23);
        if ((Level38_7CBE8_func_80013E38(ownerRecord + 0xC, privateRecord17 + 0x3C, 1) == 1) || (pathRecord18 == 0)) {
            Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 5U;
        } else {
            Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 0U;
        }
        /* fallthrough */
    case 5:
        movementFlags = Level38_7CBE8_func_80035DDC(ownerRecord, 0x50, 0x400, 0x400, 0x23);
         angleZero6 = 0;
        if (movementFlags & 0x20) {
            { register void *target2 __asm__("2");
             register int ownX7 __asm__("7");
             register int ownY3 __asm__("3");
             target2 = Level38_7CBE8_D_80071930;
             ownX7 = Level38_7CBE8Field(ownerRecord,int*,0xC);
             ownY3 = Level38_7CBE8Field(ownerRecord,int*,0x10);
             state5DeltaX4 = Level38_7CBE8Field(target2,int*,0xC);
             state5DeltaY5 = Level38_7CBE8Field(target2,int*,0x10);
             state5DeltaX4 = ownX7 - state5DeltaX4;
             state5DeltaY5 = ownY3 - state5DeltaY5;
             }
        } else {
            { register int first3 __asm__("3");
             register int second2 __asm__("2");
             first3 = Level38_7CBE8Field(privateRecord17, int *, 0x3C);
             state5DeltaX4 = Level38_7CBE8Field(ownerRecord,int*,0xC);
             second2 = Level38_7CBE8Field(privateRecord17, int *, 0x40);
             state5DeltaY5 = Level38_7CBE8Field(ownerRecord,int*,0x10);
             state5DeltaX4 = first3 - state5DeltaX4;
             state5DeltaY5 = second2 - state5DeltaY5;
             }
        }
        __asm__("" : "=r"(state5DeltaX4), "=r"(state5DeltaY5), "=r"(angleZero6) : "0"(state5DeltaX4), "1"(state5DeltaY5), "2"(angleZero6));
        Level38_7CBE8_func_8003585C(ownerRecord, Level38_7CBE8_func_8004E880(state5DeltaX4, state5DeltaY5, angleZero6) & 0xFF, 5, 0, 1, 0);
        { register int return2 __asm__("2");
         return2 = Level38_7CBE8_func_8004F334(ownerRecord + 0xC, privateRecord17 + 0x3C);
         __asm__ volatile("" : : "r"(return2) : "19");
         helperDistance = return2;
         }
        defaultCheck19 = 1;
        if (helperDistance < 0x200) {
            animationOwner4 = ownerRecord;
            if (pathRecord18 != 0) {
                Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 0U;
                __asm__ volatile("" : : : "memory");
                 animationSelector5 = 1;
            } else {
                Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 0U;
                __asm__ volatile("" : "=r"(pathRecord18) : "0"(pathRecord18) : "memory");
                 animationSelector5 = 0;
            }
            __asm__ volatile("" : : "r"(animationOwner4), "r"(animationSelector5) : "19");
            defaultCheck19 = 1;
            Level38_7CBE8_func_80034F40(animationOwner4, animationSelector5);
        }
        goto checkActivation;
    default: goto checkActivation;
    }
checkActivation:
        if (defaultCheck19 != 0) {
            activationFlags = Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C);
            activationCheck19 = 0;
            if (activationFlags & 1) {
                { register int threshold2 __asm__("2");
                 threshold2 = Level38_7CBE8Field(privateRecord17,short*,0x1E);
                 __asm__("" : "=r"(threshold2) : "0"(threshold2));
                 activationCheck19 = initialDistance20 < threshold2;
                 }
            }
            if ((activationFlags & 2) && Level38_7CBE8_func_80036220((Vector3D *)&Level38_7CBE8_D_80070328, privateRecord17 + 0x20, 0, 0)) activationCheck19 = 1;
            if (initialDistance20 >= 0x4075) activationCheck19 = 0;
            __asm__ volatile("" : : "r"(initialDistance20));
            if (activationCheck19 != 0) {
                if (Level38_7CBE8Field(privateRecord17, unsigned short *, 0x1C) & 4) {
                    Level38_7CBE8_unk_ovlheader_800743E0(Level38_7CBE8Field(ownerRecord, unsigned char *, 0x43), 1);
                }
                Level38_7CBE8Field(ownerRecord, unsigned char *, 0x48) = 1U;
                Level38_7CBE8_func_80034F40(ownerRecord, 1);
            }
        }
        return;
}
#undef Level38_7CBE8Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/level_38/moby/func_level_38_8007D2B4.s SHA256 3d598a3fd2cbbe7504437ad2cbe80c15b30abcd8ce7efc03b4386be0571a80d1. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int StarD2B4_func_80018368() __asm__("func_80018368");
int StarD2B4_func_80035030() __asm__("func_80035030");
int StarD2B4_func_80036A68() __asm__("func_80036A68");
int StarD2B4_func_8003BABC() __asm__("func_8003BABC");
int StarD2B4_func_8004E9E4() __asm__("func_8004E9E4");
int StarD2B4_func_8004EA2C() __asm__("func_8004EA2C");
int StarD2B4_func_8004EDE8() __asm__("func_8004EDE8");
int StarD2B4_func_8004EF04() __asm__("func_8004EF04");
int StarD2B4_func_8004F110() __asm__("func_8004F110");
int StarD2B4_func_8004F1C8() __asm__("func_8004F1C8");
int StarD2B4_func_8004F1FC() __asm__("func_8004F1FC");
int StarD2B4_func_8004F334() __asm__("func_8004F334");
int StarD2B4_func_80055B18() __asm__("func_80055B18");
int StarD2B4_func_80055D24() __asm__("func_80055D24");
int StarD2B4_func_80055E84() __asm__("func_80055E84");
int StarD2B4_rand() __asm__("rand");
extern unsigned char StarD2B4_D_800658A0 __asm__("D_800658A0");
extern unsigned char StarD2B4_D_80065920 __asm__("D_80065920");
extern int StarD2B4_D_8006C770 __asm__("D_8006C770");
extern Vector3D StarD2B4_D_80070328 __asm__("D_80070328");


extern unsigned char StarTable80065920_1 __asm__("D_80065920");
extern unsigned char StarTable80065920_0 __asm__("D_80065920");
extern unsigned char StarTable800658A0_1 __asm__("D_800658A0");
extern unsigned char StarTable800658A0_0 __asm__("D_800658A0");
extern signed char* (*StarParticleCallback)() __asm__("SpawnParticle");
void func_level_38_8007D2B4(Moby *inputMoby) {
    /* Stack byte offsets, signed table widths and raw fields follow retail.
     * Empty constraints preserve native code generation without instructions. */
    struct {Vector3D sp20;char pad_2c[4];int sp30;int sp34;int sp38;char pad_3c[4];int sp40;int sp44;int sp48;char pad_4c[4];int sp50;int sp54;int sp58;char pad_5c[20];} originalStack;

register Moby *moby __asm__("$18")=inputMoby;

    register Moby *spawnedChild19 __asm__("$19");
    register Vector3D *pathPosition6 __asm__("$6");
    register Vector3D * childPosition17 __asm__("$17");
    register Vector3D * position21 __asm__("$21");
    register Vector3D *pathPosition2 __asm__("$2");
    register Vector3D *targetVector5 __asm__("$5");
    register short * cosineCursor19 __asm__("$19");
    register int scaledProduct8 __asm__("$8");
    register int targetAngle16 __asm__("$16");
    register int pathLength16 __asm__("$16");
    register int steeringAngle16 __asm__("$16");
    register int remainingCount2 __asm__("$2");
    register int activeFrames2 __asm__("$2");
    register int clampedProjection6 __asm__("$6");
    register int particleIndex16 __asm__("$16");
    register int particleAngle17 __asm__("$17");
    register int state3 __asm__("$3");
    register int hitAngle2 __asm__("$2");
    register void * childData16 __asm__("$16");
    register void * pathData17 __asm__("$17");
    register void * privateData20 __asm__("$20");

    register void* vector16 __asm__("$16");
    register void* particleVector20 __asm__("$20");
    register int product8 __asm__("$8");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register signed char* (*callback3)() __asm__("$3");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    __asm__("" : "=r"(moby):"0"(moby));
    value3=3;
    value2=moby->state;
    privateData20 = moby->mobyTag;
    if ((value2 != value3) && (moby->damageFlags & 0x10000)) {
        remainingCount2 = M2C_FIELD(privateData20, int *, 0x10) - 1;
        M2C_FIELD(privateData20, int *, 0x10) = remainingCount2;
        if ((remainingCount2 <= 0) || (moby->damageFlags & 0x180000)) {
            StarD2B4_func_80036A68(moby, 1, 0, 0);
            moby->updateDistance = 0xFF;
            moby->state = 3;
            moby->unknownCollision = 0;
            func_80034F40(moby, 3);
            StarD2B4_func_8003BABC(moby, 1, 0);
        }
        M2C_FIELD(privateData20, int *, 0x2C) = 0xC8;
        M2C_FIELD(privateData20, int *, 0x28) = 0x96;
        hitAngle2 = moby->unkb;
        if (hitAngle2 == 0) {
            __asm__("" : "=r"(hitAngle2):"0"(hitAngle2));
            hitAngle2 = func_800360F8(func_8004E880(moby->position.x - StarD2B4_D_80070328.x, moby->position.y - StarD2B4_D_80070328.y, 0), (int) M2C_FIELD(&StarD2B4_D_80070328, unsigned char *, 0xE), 0x20, 0x40U);
        }
        M2C_FIELD(privateData20, int *, 0x24) = (int) hitAngle2;
        StarD2B4_func_80035030(moby, privateData20 + 0x2C, M2C_FIELD(privateData20, int *, 0x24), privateData20 + 0x28, 8, 0x10, 0x200, 0x23);
        moby->colour.r = 0xFF;
        moby->colour.g = 0xFF;
        moby->colour.b = 0xFF;
        moby->colour.a = 0x3F;
    }
    if ((moby->damageFlags == 0) || (moby->state == 3)) {
        moby->colour.r = 0;
        moby->colour.g = 0;
        moby->colour.b = 0;
        moby->colour.a = 0;
    }
    func_8003573C(moby, 5, 0, 0);
    pathData17 = M2C_FIELD(privateData20, void **, 0x20);
    if (pathData17 == 0) {
        func_8004F178(&originalStack.sp20, &moby->position);
    } else {
        if (M2C_FIELD(privateData20, short *, 0x1A) == 1) {
            pathPosition2 = M2C_FIELD(pathData17, Vector3D **, 0xC);
            targetAngle16 = func_80036018(func_8004E880(StarD2B4_D_80070328.x - pathPosition2->x, StarD2B4_D_80070328.y - pathPosition2->y, 0), (int) M2C_FIELD(privateData20, unsigned char *, 0x1C), (int) M2C_FIELD(privateData20, unsigned char *, 0x1D)) * 0x10;
            value2=StarD2B4_func_8004EA2C(targetAngle16);
            value3=M2C_FIELD(privateData20,short*,30);
            product8=value2*value3;
            value2=product8>>12;
            originalStack.sp20.x=value2;
            value2=StarD2B4_func_8004E9E4(targetAngle16);
            value3=M2C_FIELD(privateData20,short*,30);
            scaledProduct8=value2*value3;
            argument4=(int)&originalStack.sp20;
            __asm__("" : "=r"(argument4):"0"(argument4));
            originalStack.sp20.z = 0;
            value2=scaledProduct8>>12;
            originalStack.sp20.y=value2;
            argument6=M2C_FIELD(pathData17,int*,12);
            __asm__("" : "=r"(argument6):"0"(argument6):"$5");
            targetVector5=(Vector3D*)argument4;
        } else {
            vector16=&originalStack.sp30;
            pathPosition6 = M2C_FIELD(pathData17, Vector3D **, 0xC);
            StarD2B4_func_8004F1C8(vector16, (unsigned char*)pathPosition6 + 0x10, pathPosition6);
            StarD2B4_func_8004F1C8(&originalStack.sp40, &StarD2B4_D_80070328, M2C_FIELD(pathData17, Vector3D **, 0xC));
            value2=StarD2B4_func_8004EDE8(vector16,1);
            argument4=(int)vector16; argument5=1024;
            __asm__("" : "=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5));
            pathLength16=value2;
            StarD2B4_func_8004EF04(argument4,argument5);
            { register int p5 __asm__("$5"); register int p4 __asm__("$4");
              value3=originalStack.sp30; value2=originalStack.sp40; p5=value3*value2;
              value3=originalStack.sp34; value2=originalStack.sp44; p4=value3*value2;
              value3=originalStack.sp38; value2=originalStack.sp48;
              value3=value3*value2; value2=p5+p4; value2+=value3; clampedProjection6=value2>>10; }
            if (pathLength16 < clampedProjection6) {
                clampedProjection6 = pathLength16;
            } else if (clampedProjection6 < 0) {
                clampedProjection6 = 0;
            }
            __asm__("" : : : "$16");
            vector16=&originalStack.sp40;
            StarD2B4_func_8004F1FC(vector16, &originalStack.sp30, clampedProjection6);
            value2=originalStack.sp40; value3=originalStack.sp44;
            __asm__("" : "=r"(value2),"=r"(value3):"0"(value2),"1"(value3):"$4");
            argument4=(int)&originalStack.sp20;
            originalStack.sp48=0;
            __asm__ volatile("" : "=r"(value2),"=r"(value3):"0"(value2),"1"(value3):"memory");
            originalStack.sp40=value2>>10; originalStack.sp44=value3>>10;
            argument6=M2C_FIELD(pathData17,int*,12);
            __asm__("" : "=r"(argument6):"0"(argument6):"$5");
            targetVector5=(Vector3D*)vector16;
        }
        func_8004F194(argument4,targetVector5,argument6);
    }
    value2 = func_8004E880(originalStack.sp20.x - moby->position.x, originalStack.sp20.y - moby->position.y, 0);
    position21=&moby->position;
    argument4=(int)position21; argument5=(int)&originalStack.sp20;
    __asm__("" : "=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5));
    steeringAngle16=value2;
    if (StarD2B4_func_8004F334(argument4,argument5) >= 0x201) {
        func_80035EE0(moby, steeringAngle16, 0x5A, 0, 0, 0);
    }
    state3 = moby->state;
    if(state3==1) goto stateOne;
    if(state3<2) {if(state3==0) goto stateZero; moby->damageFlags=0;return;}
    value2=2; if(state3==value2) goto stateTwo;
    value2=3; if(state3==value2) goto stateThree;
    moby->damageFlags=0;return;
stateZero:
            if (moby->substate == 1) {
                if (StarD2B4_D_8006C770 != 0) {
                    func_80034F40(moby, 1);
                    moby->state = 1;
                    moby->substate = 0;
                    M2C_FIELD(privateData20, int *, 0x34) = 0;
                }
            } else if (((StarD2B4_func_8004F334(position21, &StarD2B4_D_80070328) < M2C_FIELD(privateData20, short *, 0x14)) && (moby->drawn != 0)) || (moby->damageFlags != 0)) {
                func_80034F40(moby, 1);
                moby->substate = 1;
            }
            goto clearDamageFlags;

stateOne:
    if (moby->drawn == 0) {
        M2C_FIELD(privateData20, int *, 0x34) = 0;
    }
    activeFrames2 = M2C_FIELD(privateData20, int *, 0x34) + 1;
    M2C_FIELD(privateData20, int *, 0x34) = activeFrames2;
    if ((activeFrames2 >= 0x15) && ((StarD2B4_func_8004F334(position21, &StarD2B4_D_80070328) < M2C_FIELD(privateData20, short *, 0x16)) || (moby->damageFlags != 0))) {
        func_80034F40(moby, 2);
        moby->state = 2;
    } else if ((value2=StarD2B4_func_8004F334(&moby->position, &StarD2B4_D_80070328),value3=M2C_FIELD(privateData20,short*,24),(value3=value3<value2),value3)) {
        func_80034F40(moby, 0);
        moby->state = 0;
    }
    goto clearDamageFlags;
stateTwo:
        if (StarD2B4_func_80055E84(moby) == 0x10) {
            StarD2B4_func_8003BABC(moby, 0, 0);
            spawnedChild19 = SpawnMoby(0x259, moby);
            __asm__("" : "=r"(spawnedChild19):"0"(spawnedChild19));
            childPosition17 = (Vector3D*)((unsigned char*)spawnedChild19 + 0xC);
            if (spawnedChild19 != 0) {
                value2=moby->angle.yaw;
                __asm__("" : "=r"(value2):"0"(value2):"$4");
                argument4=(int)childPosition17;
                __asm__("" : "=r"(argument4):"0"(argument4));
                value2=M2C_FIELD(&StarTable80065920_0,short*,value2*2);
                __asm__("" : "=r"(value2):"0"(value2):"$5");
                argument5=(int)childPosition17;
                spawnedChild19->position.x=value2>>2;
                value2=moby->angle.yaw;
                childData16 = spawnedChild19->mobyTag;
                value2=M2C_FIELD(&StarTable800658A0_0,short*,value2*2);
                __asm__("" : "=r"(value2):"0"(value2):"$6");
                argument6=(int)position21;
                spawnedChild19->position.z=0;
                __asm__ volatile("" : "=r"(value2):"0"(value2):"memory");
                spawnedChild19->position.y=value2>>2;
                func_8004F194(argument4,argument5,argument6);
                spawnedChild19->angle.roll = 0x40;
                spawnedChild19->position.z += 0x200;
                value2=moby->angle.yaw;
                __asm__("" : "=r"(value2):"0"(value2));
                value3=M2C_FIELD(&StarTable80065920_1,short*,value2*2);
                __asm__("" : "=r"(value3):"0"(value3):"$4");
                argument4=(int)position21;
                __asm__("" : "=r"(argument4):"0"(argument4));
                value2=(value3*125)>>11; M2C_FIELD(childData16,int*,0)=value2;
                __asm__ volatile("" : "=r"(value2):"0"(value2):"memory");
                value2=moby->angle.yaw;
                __asm__("" : "=r"(value2):"0"(value2):"$5");
                argument5=(int)childPosition17;
                value3=M2C_FIELD(&StarTable800658A0_1,short*,value2*2);
                value2=35;
                M2C_FIELD(childData16,int*,8)=0; M2C_FIELD(childData16,int*,12)=value2;
                __asm__ volatile("" : "=r"(value3):"0"(value3):"memory");
                M2C_FIELD(childData16,int*,4)=(value3*125)>>11;
                if (StarD2B4_func_80018368(argument4, argument5) != 0) {
                    StarD2B4_func_80055B18(spawnedChild19);
                }
                StarD2B4_func_8003BABC(spawnedChild19, 0, 0);
            }
            func_80034F40(moby, 1);
            moby->state = 1;
            M2C_FIELD(privateData20, int *, 0x34) = 0;
        }
        goto clearDamageFlags;
stateThree:
            if (StarD2B4_D_8006C770 != 0) {
                particleIndex16 = 0;
                particleAngle17 = StarD2B4_rand() & 0xFF;
                particleVector20=&originalStack.sp50;
                value3=(int)&StarD2B4_D_80065920;
                value2=particleAngle17*2; cosineCursor19=(short*)(value2+value3);
                do {
                    argument4=1; argument5=20;
                    __asm__("" : "=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5));
                    value3=*cosineCursor19;
                    __asm__("" : "=r"(value3):"0"(value3):"$6");
                    argument6=(int)position21;
                    __asm__("" : "=r"(value3),"=r"(argument6):"0"(value3),"1"(argument6));
                    value2=(value3*3)>>8; originalStack.sp50=value2;
                    __asm__ volatile("" : "=r"(value2):"0"(value2):"memory");
                    value2=particleAngle17*2;
                    __asm__("" : "=r"(value2):"0"(value2));
                    value3=M2C_FIELD(&StarD2B4_D_800658A0,short*,value2);
                    __asm__("" : "=r"(value3):"0"(value3):"$7");
                    argument7=(int)particleVector20;
                    originalStack.sp58=0;
                    __asm__ volatile("" : "=r"(value3):"0"(value3):"memory");
                    value2=value3*3;
                    callback3=StarParticleCallback;
                    __asm__("" : "=r"(callback3):"0"(callback3));
                    value2>>=8; originalStack.sp54=value2;
                    callback3(argument4,argument5,argument6,argument7);
                    if (particleIndex16 & 1) {
                        StarD2B4_func_8004F110(particleVector20, 1);
                        SpawnParticle(1, 0x14, position21, particleVector20);
                    }
                    cosineCursor19 += 0x17;
                    particleIndex16 += 1;
                    particleAngle17 += 0x17;
                } while (particleIndex16 < 0xB);
                StarD2B4_func_80055D24(moby, 4);
                func_8003BA00(moby);
                func_800369B8(moby, 0x28);
                StarD2B4_func_80055B18(moby);
                return;
            }
            goto clearDamageFlags;

clearDamageFlags:
    moby->damageFlags = 0;
}
#undef M2C_FIELD


INCLUDE_RODATA("asm/nonmatchings/overlays/level_38/moby", D_level_38_800746C0);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007DA7C.
* Assembly SHA256 22aff54bffe026b1d066ac5f5cc2dc3048a52303af335e2abd722bec6f4abd92.
* AI generated; not human reviewed. All650 original instructions,eight
* selector words and actual targets are required. Original frame0xB0,
* all S0..S7/FP/RA saves and full SP18..87 local extent are retained.
* An ordinary initialized player-vector address naturally occupies FP in
* the three-entry loop;there is no fixed FP binding or incoming saved value.
* Byte SP50/51/52 fields,three-word source copy,88-byte Moby indexing,
* both angle branches,particle chains,and signed16 route-index extension
* preserve their original producers and consumers. Shared activation uses
* original T0 stack loads/stores and exact branch/call/table destinations.
* Initialized empty identities,late consumers and dead clobbers emit zero
* instructions. No opcode assembly,partial HI or overlapping live aliases.
* Confidence is binary identity after all gates. Full helper contracts,
* raw units/fixed point,caller cadence and synchronized runtime remain open.
* Cadence is per invocation. Falsification:every native/linked word,actual
* transfer/table target,owned data byte,EXE and every overlay retail hash. */
#define Actor38_7DA7CField(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Actor38_7DA7CCall13E38View1() __asm__("func_80013E38");
int Actor38_7DA7CCall34F40View1() __asm__("func_80034F40");
int Actor38_7DA7CCall3573CView1() __asm__("func_8003573C");
int Actor38_7DA7CCall3585CView1() __asm__("func_8003585C");
int Actor38_7DA7CCall359A4View1() __asm__("func_800359A4");
int Actor38_7DA7CCall35DDCView1() __asm__("func_80035DDC");
int Actor38_7DA7CCall3617CView1() __asm__("func_8003617C");
int Actor38_7DA7CCall36220View1() __asm__("func_80036220");
int Actor38_7DA7CCall3645CView1() __asm__("func_8003645C");
int Actor38_7DA7CCall369B8View1() __asm__("func_800369B8");
int Actor38_7DA7CCall3BA00View1() __asm__("func_8003BA00");
int Actor38_7DA7CCall3BABCView1() __asm__("func_8003BABC");
int Actor38_7DA7CCall4E880View1() __asm__("func_8004E880");
int Actor38_7DA7CCall4EA90View1() __asm__("func_8004EA90");
int Actor38_7DA7CCall4ED6CView1() __asm__("func_8004ED6C");
int Actor38_7DA7CCall4F0E8View1() __asm__("func_8004F0E8");
int Actor38_7DA7CCall4F178View1() __asm__("func_8004F178");
int Actor38_7DA7CCall4F194View1() __asm__("func_8004F194");
int Actor38_7DA7CCall4F334View1() __asm__("func_8004F334");
int Actor38_7DA7CCall55B18View1() __asm__("func_80055B18");
int Actor38_7DA7CCall55D24View1() __asm__("func_80055D24");
int Actor38_7DA7CCallrandView1() __asm__("rand");
extern int Actor38_7DA7CData6C550View1 __asm__("D_8006C550");
extern int Actor38_7DA7CData6C574View1 __asm__("D_8006C574");
extern int Actor38_7DA7CData6C578View1 __asm__("D_8006C578");
extern int Actor38_7DA7CData6C640View1 __asm__("D_8006C640");
extern int Actor38_7DA7CData6C7E8View1 __asm__("D_8006C7E8");
extern int Actor38_7DA7CData6E020View1 __asm__("D_8006E020");
extern int Actor38_7DA7CData70328View1 __asm__("D_80070328");
extern int Actor38_7DA7CData71930View1 __asm__("D_80071930");
extern int Actor38_7DA7CData746C0View1 __asm__("D_level_38_800746C0");
extern void*(*Actor38_7DA7CDataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Actor38_7DA7CDataSpawnParticleView1)() __asm__("SpawnParticle");
extern int(*Actor38_7DA7CData743C4View1)() __asm__("unk_ovlheader_800743C4");
extern int(*Actor38_7DA7CData743E0View1)() __asm__("unk_ovlheader_800743E0");
void func_level_38_8007DA7C(void *input) {
    register void *ownerRecord18 __asm__("$18");
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), stackFlagOrDistance8 __asm__("$8");
    register int angleOrChildAddress16 __asm__("$16"), routeChildOrCounter17 __asm__("$17"), indexOrMatrixAddress19 __asm__("$19"), angularOffsetOrPrivateCursor20 __asm__("$20"), sourceOrStackCursor21 __asm__("$21"), privateRecord22 __asm__("$22"), retainedLiteralOne23 __asm__("$23");
    int playerVectorAddress;
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C;
        unsigned char sp50, sp51, sp52, sp53;
        int sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84;
    }
    originalFrame;
    int movementResult;
    void *firstSpawnedRecord;
    void *groupSpawnedRecord;
    void *periodicSpawnedRecord;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    originalFrame.sp78 = 0;
    privateRecord22 = (int)Actor38_7DA7CField(ownerRecord18, void**, 0);
    routeChildOrCounter17 = Actor38_7DA7CField(privateRecord22, void **, 0x24);
    if (Actor38_7DA7CField(ownerRecord18, int *, 0x18) != 0) {
        rawWord3 = Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48);
        if ((unsigned int) (rawWord3 - 2) >= 2U) {
            if ((rawWord3 == 0) && (Actor38_7DA7CField(privateRecord22, unsigned short *, 8) & 4)) {
                Actor38_7DA7CData743E0View1(Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x43), 1);
            }
            Actor38_7DA7CField(privateRecord22, unsigned short *, 8) = (unsigned short) (Actor38_7DA7CField(privateRecord22, unsigned short *, 8) | 0x80);
            Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 2U;
            Actor38_7DA7CCall3BABCView1(ownerRecord18, 0, 0);
        }
    }
    rawWord2 = Actor38_7DA7CCall4F334View1(ownerRecord18 + 0xC, &Actor38_7DA7CData70328View1);
    rawWord3 = Actor38_7DA7CField(ownerRecord18, unsigned char*, 0x48);
    rawWord3 = (unsigned int)(rawWord3-2) < 2U;
    originalFrame.sp70 = rawWord2;
    if (!rawWord3 && rawWord2 < 0x708) {
        Actor38_7DA7CField(&Actor38_7DA7CData70328View1, int *, 0x24) = (int) (Actor38_7DA7CField(&Actor38_7DA7CData70328View1, int *, 0x24) | 1);
        Actor38_7DA7CField(privateRecord22, unsigned short *, 8) = (unsigned short) (Actor38_7DA7CField(privateRecord22, unsigned short *, 8) | 0x80);
        Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 2U;
        return;
    }
    rawWord3 = Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48);
    switch (rawWord3) {
    case 0:
        Actor38_7DA7CCall3573CView1(ownerRecord18, 5, 0, 0);
        rawWord3 = Actor38_7DA7CField(privateRecord22, unsigned short *, 8);
        if (rawWord3 & 0x80) {
            argumentWord4 = (int)ownerRecord18;
            argumentWord5 = 1;
            __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(argumentWord4), "r"(argumentWord5));
            rawWord2 = rawWord3&0xFF7F;
            Actor38_7DA7CField(privateRecord22, unsigned short*, 8) = rawWord2;
            Actor38_7DA7CCall34F40View1(argumentWord4, argumentWord5);
            Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 4U;
        }
        else {
            goto markActivationEligible;
        }
    default:
        goto checkActivation;
    case 1:
        stackFlagOrDistance8 = originalFrame.sp70;
        rawWord2 = stackFlagOrDistance8 < 0x4075;
        if (rawWord2) goto runState1Movement;
        rawWord2 = 5;
        Actor38_7DA7CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        goto checkActivation;
        runState1Movement: {
            rawWord3 = Actor38_7DA7CField(privateRecord22, unsigned short *, 8);
            if (rawWord3 & 2) {
                rawWord2 = rawWord3&0xFFFD;
                rawWord2 |= 1;
                Actor38_7DA7CField(privateRecord22, unsigned short*, 8) = rawWord2;
            }
            if (Actor38_7DA7CCall35DDCView1(ownerRecord18, 0x28, 0x380, 0x380, 0x23) & 0x20) {
                argumentWord7 = Actor38_7DA7CField(ownerRecord18, int *, 0xC);
                movementResult = Actor38_7DA7CCall4E880View1(argumentWord7 - Actor38_7DA7CField(Actor38_7DA7CData71930View1, int *, 0xC), Actor38_7DA7CField(ownerRecord18, int *, 0x10) - Actor38_7DA7CField(Actor38_7DA7CData71930View1, int *, 0x10), 0, argumentWord7);
            }
            else {
                movementResult = Actor38_7DA7CData743C4View1(ownerRecord18 + 0x49, ownerRecord18 + 0xC, &Actor38_7DA7CData70328View1);
            }
            Actor38_7DA7CCall3585CView1(ownerRecord18, movementResult & 0xFF, 5, 0, 1, 0);
        }
        goto checkActivation;
    case 2:
        if (((Actor38_7DA7CData6C578View1 - Actor38_7DA7CData6C574View1) >= 0x15) && (Actor38_7DA7CData6C7E8View1 >= 0x7531)) {
            firstSpawnedRecord = Actor38_7DA7CDataSpawnMobyView1(0x146, ownerRecord18);
            if (firstSpawnedRecord != 0) {
                Actor38_7DA7CField(firstSpawnedRecord, signed char *, 0x47) = 7;
            }
        }
        indexOrMatrixAddress19 = 0;
        if ((Actor38_7DA7CData6C578View1 - Actor38_7DA7CData6C574View1) >= 0x15) {
            sourceOrStackCursor21 = (int)&Actor38_7DA7CData6E020View1;
            __asm__("":"=r"(sourceOrStackCursor21):"0"(sourceOrStackCursor21):"$20");
            angularOffsetOrPrivateCursor20 = 0;
        spawnNextGroupMember:
            if (Actor38_7DA7CData6C7E8View1 >= 0x7531) {
                groupSpawnedRecord = Actor38_7DA7CDataSpawnMobyView1(0x21D, ownerRecord18);
                if (groupSpawnedRecord != 0) {
                    angleOrChildAddress16 = Actor38_7DA7CCall4E880View1(Actor38_7DA7CField(ownerRecord18, int *, 0xC) - Actor38_7DA7CField(sourceOrStackCursor21, int *, 0), Actor38_7DA7CField(ownerRecord18, int *, 0x10) - Actor38_7DA7CField(sourceOrStackCursor21, int *, 4), 0);
                    rawWord2 = Actor38_7DA7CCallrandView1();
                    angleOrChildAddress16 += 64;
                    rawWord2 &= 31;
                    angleOrChildAddress16 += rawWord2;
                    Actor38_7DA7CField(groupSpawnedRecord, signed char*, 0x46) = angleOrChildAddress16;
                    Actor38_7DA7CField(groupSpawnedRecord, signed char *, 0x45) = (signed char) ((angularOffsetOrPrivateCursor20 + (Actor38_7DA7CCallrandView1() & 0x1E)) - 0xF);
                    Actor38_7DA7CField(groupSpawnedRecord, signed char *, 0x47) = 8;
                    Actor38_7DA7CField(groupSpawnedRecord, signed char *, 0x4C) = 0x2A;
                }
                indexOrMatrixAddress19 += 1;
                angularOffsetOrPrivateCursor20 += 0x33;
                if ((indexOrMatrixAddress19 < 5) && ((Actor38_7DA7CData6C578View1 - Actor38_7DA7CData6C574View1) >= 0x15)) {
                    goto spawnNextGroupMember;
                }
            }
        }
        indexOrMatrixAddress19 = 0;
        playerVectorAddress = (int)&Actor38_7DA7CData70328View1;
        __asm__("":"=r"(playerVectorAddress):"0"(playerVectorAddress));
        retainedLiteralOne23 = 1;
        __asm__("":"=r"(retainedLiteralOne23):"0"(retainedLiteralOne23));
        sourceOrStackCursor21 = &originalFrame.sp18;
        angularOffsetOrPrivateCursor20 = privateRecord22;
        do {
            argumentWord5 = (int)&Actor38_7DA7CData746C0View1;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            rawWord2 = Actor38_7DA7CField(argumentWord5, int*, 0);
            rawWord3 = Actor38_7DA7CField(argumentWord5, int*, 4);
            argumentWord4 = Actor38_7DA7CField(argumentWord5, int*, 8);
            originalFrame.sp18 = rawWord2;
            originalFrame.sp1C = rawWord3;
            originalFrame.sp20 = argumentWord4;
            rawWord3 = Actor38_7DA7CField(angularOffsetOrPrivateCursor20, int *, 0x34);
            if ((rawWord3 != -1) && ((angleOrChildAddress16 = ({rawWord2 = (unsigned int)rawWord3 << 1;rawWord2 += rawWord3;rawWord2 <<= 2;rawWord2 -= rawWord3;rawWord3 = Actor38_7DA7CData6C550View1;rawWord2 <<= 3;rawWord3+rawWord2;}), rawWord3 = Actor38_7DA7CField(angleOrChildAddress16, unsigned char *, 0x48), routeChildOrCounter17 = Actor38_7DA7CField(angleOrChildAddress16, void **, 0), (rawWord3 == 0)) || (rawWord3 == 0x2A))) {
                Actor38_7DA7CField(routeChildOrCounter17, int *, 0xC) = 0xF0;
                Actor38_7DA7CField(routeChildOrCounter17, int *, 8) = 0x96;
                Actor38_7DA7CField(routeChildOrCounter17, int *, 4) = Actor38_7DA7CCall3617CView1(Actor38_7DA7CCall4E880View1(Actor38_7DA7CField(ownerRecord18, int *, 0xC) - Actor38_7DA7CField(playerVectorAddress, int*, 0), Actor38_7DA7CField(ownerRecord18, int *, 0x10) - Actor38_7DA7CField(playerVectorAddress, int*, 4), 0), Actor38_7DA7CField(sourceOrStackCursor21, int*, 0));
                Actor38_7DA7CField(angleOrChildAddress16, unsigned char *, 0x48) = 3U;
                Actor38_7DA7CCall4F178View1(angleOrChildAddress16 + 0xC, ownerRecord18 + 0xC);
                Actor38_7DA7CField(angleOrChildAddress16, int *, 0x18) = 0;
                Actor38_7DA7CField(angleOrChildAddress16, signed char*, 0x41) = retainedLiteralOne23;
                Actor38_7DA7CField(angleOrChildAddress16, signed char *, 0x4C) = 0x20;
                Actor38_7DA7CField(angleOrChildAddress16, signed char*, 0x4D) = retainedLiteralOne23;
            }
            sourceOrStackCursor21 += 4;
            indexOrMatrixAddress19 += 1;
            angularOffsetOrPrivateCursor20 += 4;
        }
        while (indexOrMatrixAddress19 < 3);
        Actor38_7DA7CField(ownerRecord18, signed char *, 0x41) = 0;
        Actor38_7DA7CField(ownerRecord18, signed char *, 0x4C) = 0;
        Actor38_7DA7CField(ownerRecord18, signed char *, 0x4D) = 0;
        Actor38_7DA7CField(privateRecord22, int *, 4) = 0xA;
        Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 3U;
    case 3:
        if (Actor38_7DA7CField(privateRecord22, int *, 4) >= 3) {
            routeChildOrCounter17 = 0;
            indexOrMatrixAddress19 = (int)&originalFrame.sp38;
            do {
                originalFrame.sp50 = 0;
                originalFrame.sp51 = Actor38_7DA7CCallrandView1();
                originalFrame.sp52 = Actor38_7DA7CCallrandView1();
                Actor38_7DA7CCall4EA90View1(&originalFrame.sp50, indexOrMatrixAddress19, 0);
                routeChildOrCounter17 += 1;
                originalFrame.sp18 = (Actor38_7DA7CCallrandView1() & 0x1F) + 0x30;
                originalFrame.sp1C = 0;
                originalFrame.sp20 = 0;
                Actor38_7DA7CCall4ED6CView1(indexOrMatrixAddress19, &originalFrame.sp18, &originalFrame.sp18);
                Actor38_7DA7CCall4F178View1(&originalFrame.sp28, &originalFrame.sp18);
                Actor38_7DA7CCall4F194View1(&originalFrame.sp28, &originalFrame.sp28, ownerRecord18 + 0xC);
                Actor38_7DA7CDataSpawnParticleView1(1, 0x14, &originalFrame.sp28, &originalFrame.sp18);
                Actor38_7DA7CCall4F0E8View1(&originalFrame.sp28, 2);
                Actor38_7DA7CDataSpawnParticleView1(1, 0x14, &originalFrame.sp28, &originalFrame.sp18);
                Actor38_7DA7CCall4F0E8View1(&originalFrame.sp18, 2);
                Actor38_7DA7CDataSpawnParticleView1(1, 0x14, &originalFrame.sp28, &originalFrame.sp18);
                __asm__ __volatile__("":"=r"(ownerRecord18):"0"(ownerRecord18));
            }
            while (routeChildOrCounter17 < 4);
            Actor38_7DA7CDataSpawnParticleView1(6, 0x46, ownerRecord18 + 0xC, (int *)0x10);
        }
        argumentWord4 = privateRecord22 + 4;
        if (!(Actor38_7DA7CData6C640View1 & 1) && ((Actor38_7DA7CData6C578View1 - Actor38_7DA7CData6C574View1) >= 0x15) && (Actor38_7DA7CData6C7E8View1 >= 0x7531)) {
            periodicSpawnedRecord = Actor38_7DA7CDataSpawnMobyView1(0x1E2, ownerRecord18);
            if (periodicSpawnedRecord != 0) {
                Actor38_7DA7CField(periodicSpawnedRecord, signed char *, 0x4C) = 0x2A;
                Actor38_7DA7CField(periodicSpawnedRecord, signed char *, 0x47) = 0xA;
            }
            __asm__ __volatile__("":"=r"(privateRecord22):"0"(privateRecord22));
            argumentWord4 = privateRecord22+4;
        }
        if (Actor38_7DA7CCall359A4View1(argumentWord4, 4) != 0) {
            Actor38_7DA7CCall55D24View1(ownerRecord18, 4);
            Actor38_7DA7CCall3BA00View1(ownerRecord18);
            Actor38_7DA7CCall369B8View1(ownerRecord18, 0x30);
            Actor38_7DA7CCall55B18View1(ownerRecord18);
            return;
        }
        goto checkActivation;
    case 4:
        Actor38_7DA7CCall35DDCView1(ownerRecord18, 0x28, 0, 0x380, 0x21);
        rawWord3 = 1;
        rawWord2 = 32;
        Actor38_7DA7CField(ownerRecord18, signed char*, 0x4C) = rawWord2;
        rawWord2 = 5;
        Actor38_7DA7CField(ownerRecord18, signed char*, 0x41) = rawWord3;
        Actor38_7DA7CField(ownerRecord18, signed char*, 0x4D) = rawWord3;
        Actor38_7DA7CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        goto checkActivation;
    case 5:
        Actor38_7DA7CCall35DDCView1(ownerRecord18, 0x28, 0, 0x380, 0x23);
        angleOrChildAddress16 = ownerRecord18 + 0xC;
        if ((Actor38_7DA7CCall13E38View1(angleOrChildAddress16, privateRecord22 + 0x28, 1) == 1) || (routeChildOrCounter17 == 0)) {
            Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 6U;
        }
        else {
            Actor38_7DA7CCall3645CView1(angleOrChildAddress16, routeChildOrCounter17, &originalFrame.sp58);
            Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 7U;
            Actor38_7DA7CField(routeChildOrCounter17, short *, 2) = (short) originalFrame.sp58;
        }
    case 6:
        rawWord2 = Actor38_7DA7CCall35DDCView1(ownerRecord18, 0x28, 0x380, 0x380, 0x23)&32;
        argumentWord6 = 0;
        if (rawWord2){
            rawWord2 = Actor38_7DA7CData71930View1;
            argumentWord7 = Actor38_7DA7CField(ownerRecord18, int*, 12);
            rawWord3 = Actor38_7DA7CField(ownerRecord18, int*, 16);
            argumentWord4 = Actor38_7DA7CField(rawWord2, int*, 12);
            argumentWord5 = Actor38_7DA7CField(rawWord2, int*, 16);
            argumentWord4 = argumentWord7-argumentWord4;
            argumentWord5 = rawWord3-argumentWord5;
        }
        else{
            rawWord3 = Actor38_7DA7CField(privateRecord22, int*, 0x28);
            argumentWord4 = Actor38_7DA7CField(ownerRecord18, int*, 12);
            rawWord2 = Actor38_7DA7CField(privateRecord22, int*, 0x2C);
            argumentWord5 = Actor38_7DA7CField(ownerRecord18, int*, 16);
            argumentWord4 = rawWord3-argumentWord4;
            argumentWord5 = rawWord2-argumentWord5;
        }
        Actor38_7DA7CCall3585CView1(ownerRecord18, Actor38_7DA7CCall4E880View1(argumentWord4, argumentWord5, argumentWord6) & 0xFF, 5, 0, 1, 0);
        if (Actor38_7DA7CCall4F334View1(ownerRecord18 + 0xC, privateRecord22 + 0x28) < 0x200) {
            Actor38_7DA7CField(ownerRecord18, unsigned char *, 0x48) = 0U;
            Actor38_7DA7CCall34F40View1(ownerRecord18, 0);
        }
        goto markActivationEligible;
    case 7:
        Actor38_7DA7CCall4F178View1(&originalFrame.sp60, Actor38_7DA7CField(routeChildOrCounter17, int *, 0xC) + (Actor38_7DA7CField(routeChildOrCounter17, short *, 2) * 0x10));
        rawWord2 = Actor38_7DA7CCall35DDCView1(ownerRecord18, 0x28, 0x380, 0x380, 0x23)&32;
        argumentWord6 = 0;
        if (rawWord2){
            rawWord2 = Actor38_7DA7CData71930View1;
            argumentWord7 = Actor38_7DA7CField(ownerRecord18, int*, 12);
            rawWord3 = Actor38_7DA7CField(ownerRecord18, int*, 16);
            argumentWord4 = Actor38_7DA7CField(rawWord2, int*, 12);
            argumentWord5 = Actor38_7DA7CField(rawWord2, int*, 16);
            argumentWord4 = argumentWord7-argumentWord4;
            argumentWord5 = rawWord3-argumentWord5;
        }
        else{
            rawWord3 = originalFrame.sp60;
            argumentWord4 = Actor38_7DA7CField(ownerRecord18, int*, 12);
            rawWord2 = originalFrame.sp64;
            argumentWord5 = Actor38_7DA7CField(ownerRecord18, int*, 16);
            argumentWord4 = rawWord3-argumentWord4;
            argumentWord5 = rawWord2-argumentWord5;
        }
        Actor38_7DA7CCall3585CView1(ownerRecord18, Actor38_7DA7CCall4E880View1(argumentWord4, argumentWord5, argumentWord6) & 0xFF, 5, 0, 1, 0);
        if (Actor38_7DA7CCall4F334View1(ownerRecord18+12, &originalFrame.sp60) < 0x200){
            argumentWord4 = Actor38_7DA7CField(routeChildOrCounter17, short*, 2);
            rawWord3 = Actor38_7DA7CField(routeChildOrCounter17, int*, 12);
            rawWord2 = (unsigned int)argumentWord4 << 4;
            rawWord2 += rawWord3;
            rawWord2 = Actor38_7DA7CField(rawWord2, int*, 12);
            if (rawWord2) goto storeRouteFinishedState;
            rawWord2 = argumentWord4+1;
            Actor38_7DA7CField(routeChildOrCounter17, short*, 2) = rawWord2;
            rawWord2 = (int)((unsigned int)rawWord2 << 16) >> 16;
            rawWord3 = Actor38_7DA7CField(routeChildOrCounter17, short*, 0);
            if (rawWord2 < rawWord3) goto markActivationEligible;
            storeRouteFinishedState: rawWord2 = 6;
            Actor38_7DA7CField(ownerRecord18, unsigned char*, 0x48) = rawWord2;
        }
        goto markActivationEligible;
    }
    markActivationEligible:stackFlagOrDistance8 = 1;
    originalFrame.sp78 = stackFlagOrDistance8;
    checkActivation:stackFlagOrDistance8 = originalFrame.sp78;
    if (!stackFlagOrDistance8) goto clearInvocationFlags;
    rawWord3 = Actor38_7DA7CField(privateRecord22, unsigned short*, 8);
    originalFrame.sp78 = 0;
    rawWord2 = rawWord3&1;
    if (rawWord2){
        rawWord2 = Actor38_7DA7CField(privateRecord22, short*, 10);
        stackFlagOrDistance8 = originalFrame.sp70;
        rawWord2 = stackFlagOrDistance8 < rawWord2;
        originalFrame.sp78 = rawWord2;
    }
    rawWord2 = rawWord3&2;
    argumentWord5 = privateRecord22+12;
    if (rawWord2){
        rawWord2 = Actor38_7DA7CCall36220View1(&Actor38_7DA7CData70328View1, argumentWord5, 0, 0);
        stackFlagOrDistance8 = 1;
        if (rawWord2)originalFrame.sp78 = stackFlagOrDistance8;
    }
    stackFlagOrDistance8 = originalFrame.sp70;
    rawWord2 = stackFlagOrDistance8 < 0x4075;
    if (!rawWord2)originalFrame.sp78 = 0;
    stackFlagOrDistance8 = originalFrame.sp78;
    if (stackFlagOrDistance8){
        if (Actor38_7DA7CField(privateRecord22, unsigned short*, 8)&4){
            Actor38_7DA7CData743E0View1(Actor38_7DA7CField(ownerRecord18, unsigned char*, 0x43), 1);
        }
        Actor38_7DA7CField(ownerRecord18, unsigned char*, 0x48) = 1;
        Actor38_7DA7CCall34F40View1(ownerRecord18, 1);
    }
    clearInvocationFlags:Actor38_7DA7CField(ownerRecord18, int*, 0x18) = 0;
}
#undef Actor38_7DA7CField


typedef struct { int timer, sound; } DecodedDamageColourTag;
int DecodedDamageColourSound(Moby*, int, int) __asm__("func_8003BABC");
int DecodedDamageColourPlaying(Moby*, int) __asm__("func_8003BFC0");
void func_level_38_8007E4A4(Moby* moby) {
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

void func_level_38_8007E73C(void *input) {
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
void func_level_38_8007ED88(Moby* argument) {
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

INCLUDE_RODATA("asm/nonmatchings/overlays/level_38/moby", D_level_38_800746F0);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_38/moby", D_level_38_800746FC);

INCLUDE_RODATA("asm/nonmatchings/overlays/level_38/moby", D_level_38_80074708);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; AI generated, not human reviewed.
 * UNINSTALLED mixed C/original assembly proposal. Original CPU fragments are disclosed at each
 * site: three indexed LW reads425/435/1107, closed225..244, and call270..275; original12byte
 * prefix74714 is defined exactly. No lookup bounds, defaults or manual SP/FP object are supplied.
 * Every native/locals/control/table/source/helper/ownerInput/alias gate remains pending. */
#define Level38_7F128Field(p, t, o) (*(t)((unsigned char *)(p) + (o)))
#define Level38_7F128Keep(v) __asm__("" : "=r"(v) : "0"(v))
typedef union {
    long long full;
    struct {
        unsigned int low;
        int high;
    } words;
} Level38_7F128Product;
extern int Level38_7F128_D_800658A0 __asm__("D_800658A0");
extern int Level38_7F128_D_80065920 __asm__("D_80065920");
extern int Level38_7F128_D_8006C550 __asm__("D_8006C550");
extern int Level38_7F128_D_8006C574 __asm__("D_8006C574");
extern int Level38_7F128_D_8006C578 __asm__("D_8006C578");
extern int Level38_7F128_D_8006C640 __asm__("D_8006C640");
extern int Level38_7F128_D_8006C730 __asm__("D_8006C730");
extern int Level38_7F128_D_8006C770 __asm__("D_8006C770");
extern int Level38_7F128_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level38_7F128_D_8006C7E8 __asm__("D_8006C7E8");
extern int Level38_7F128_D_8006E020 __asm__("D_8006E020");
extern int Level38_7F128_D_80070328 __asm__("D_80070328");
extern int Level38_7F128_D_80071930 __asm__("D_80071930");
extern int Level38_7F128_D_level_38_800746F0 __asm__("D_level_38_800746F0");
extern int Level38_7F128_D_level_38_800746FC __asm__("D_level_38_800746FC");
extern int Level38_7F128_D_level_38_80074708 __asm__("D_level_38_80074708");
/* Original owned bytes74714..7471F: 41000000 37000000 2D000000. */
const int Level38_7F128_D_level_38_80074714[3] __asm__("D_level_38_80074714") = {65, 55, 45};
extern int Level38_7F128_SpawnMoby __asm__("SpawnMoby");
extern int Level38_7F128_SpawnParticle __asm__("SpawnParticle");
extern int Level38_7F128_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level38_7F128_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level38_7F128_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
extern int Level38_7F128_unk_ovlheader_800743C4 __asm__("unk_ovlheader_800743C4");
int Level38_7F128_func_8002803C() __asm__("func_8002803C");
int Level38_7F128_func_80028154() __asm__("func_80028154");
int Level38_7F128_func_80034F40() __asm__("func_80034F40");
int Level38_7F128_func_80035030() __asm__("func_80035030");
int Level38_7F128_func_8003573C() __asm__("func_8003573C");
int Level38_7F128_func_8003585C() __asm__("func_8003585C");
int Level38_7F128_func_800359A4() __asm__("func_800359A4");
int Level38_7F128_func_80035DDC() __asm__("func_80035DDC");
int Level38_7F128_func_80036018() __asm__("func_80036018");
int Level38_7F128_func_8003617C() __asm__("func_8003617C");
int Level38_7F128_func_8003645C() __asm__("func_8003645C");
int Level38_7F128_func_800369B8() __asm__("func_800369B8");
int Level38_7F128_func_8003BA00() __asm__("func_8003BA00");
int Level38_7F128_func_8003BABC() __asm__("func_8003BABC");
int Level38_7F128_func_8004E880() __asm__("func_8004E880");
int Level38_7F128_func_8004EA90() __asm__("func_8004EA90");
int Level38_7F128_func_8004ED6C() __asm__("func_8004ED6C");
int Level38_7F128_func_8004F0E8() __asm__("func_8004F0E8");
int Level38_7F128_func_8004F110() __asm__("func_8004F110");
int Level38_7F128_func_8004F178() __asm__("func_8004F178");
int Level38_7F128_func_8004F194() __asm__("func_8004F194");
int Level38_7F128_func_8004F264() __asm__("func_8004F264");
int Level38_7F128_func_8004F334() __asm__("func_8004F334");
int Level38_7F128_func_80055B18() __asm__("func_80055B18");
int Level38_7F128_func_80055D24() __asm__("func_80055D24");
int Level38_7F128_func_rand() __asm__("rand");
void func_level_38_8007F128(void *ownerInput) {
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
    register int saved20 __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int privateState __asm__("$23");
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
    } locals;
    long long completeSignedProduct;
    int actualHeader68, actualHeader6C;
    argument0 = (int)ownerInput;
    owner = (int)((unsigned int)argument0 + (unsigned int)0);
    Level38_7F128Keep(owner);
    saved18 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(saved18);
    privateState = Level38_7F128Field(owner, int *, 0);
    Level38_7F128Keep(privateState);
    temporary2 = Level38_7F128Field(owner, unsigned char *, 72);
    Level38_7F128Keep(temporary2);
    saved17 = Level38_7F128Field(privateState, int *, 32);
    Level38_7F128Keep(saved17);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 != saved18)
        goto original1483_23;
    Level38_7F128Field(owner, unsigned char *, 65) = 0;
    Level38_7F128Field(owner, unsigned char *, 76) = 0;
    Level38_7F128Field(owner, unsigned char *, 77) = 0;
    Level38_7F128Field(owner, int *, 8) = 0;
    goto original1483Return;
original1483_23:
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128_func_80055D24(argument0, argument1);
    Level38_7F128Keep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(argument0);
    saved16 = (int)&Level38_7F128_D_80070328;
    Level38_7F128Keep(saved16);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F334(argument0, argument1);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, 1120);
    Level38_7F128Keep(temporary3);

    Level38_7F128Field((int)&locals, int *, 192) = temporary2;
    if (temporary3 != owner)
        goto original1483_78;
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary3 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 812);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)0x10000000U;
    Level38_7F128Keep(argument0);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, 844);
    Level38_7F128Keep(temporary3);
    argument0 = argument0 | 1024;
    Level38_7F128Keep(argument0);

    Level38_7F128Field((int)&Level38_7F128_D_80070328 + 664, int *, 0) = temporary2;
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field((int)&Level38_7F128_D_80070328 + 524, int *, 0) = argument0;
    __asm__ volatile("" ::"i"((unsigned int)&Level38_7F128_D_80070328 + 524U));
    __asm__("" : "=r"(temporary3) : "0"(temporary3), "r"(temporary2));
    temporary3 = temporary3 | 7;
    Level38_7F128Keep(temporary3);

    Level38_7F128Field((int)&Level38_7F128_D_80070328 + 36, int *, 0) = temporary3;

    argument0 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_80065920 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(argument0);
    Level38_7F128Keep(argument0);

    temporary3 = (int)((unsigned int)argument0 << 5);
    Level38_7F128Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 << 2);
    Level38_7F128Keep(temporary3);
    temporary3 = (int)((unsigned int)temporary3 + (unsigned int)argument0);
    Level38_7F128Keep(temporary3);
    temporary3 = (temporary3 >> 11);
    Level38_7F128Keep(temporary3);

    Level38_7F128Field((int)&Level38_7F128_D_80070328 + 540, int *, 0) = temporary3;

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 5);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 11);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field((int)&Level38_7F128_D_80070328 + 544, int *, 0) = temporary2;
original1483_78:
    temporary3 = Level38_7F128Field(owner, unsigned char *, 72);
    Level38_7F128Keep(temporary3);
    saved16 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(saved16);
    temporary2 = temporary3 < 2;
    if (temporary3 == saved16)
        goto original1483_153;
    if (temporary2 == 0)
        goto original1483_88;
    if (temporary3 == 0)
        goto original1483_95;

    goto original1483Return;
original1483_88:
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)3), 1)
                                 : (temporary2 = (int)((unsigned int)0 + (unsigned int)3), 0))
        goto original1483_790;
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary3 == temporary2)
        goto original1483_1312;

    goto original1483Return;
original1483_95:
    temporary2 = Level38_7F128Field(privateState, int *, 20);
    Level38_7F128Keep(temporary2);
    temporary8 = Level38_7F128Field((int)&locals, volatile int *, 192);
    Level38_7F128Keep(temporary8);

    temporary2 = temporary8 < temporary2;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)53);
    if (temporary2 != 0)
        goto original1483_105;
    temporary2 = Level38_7F128Field(owner, int *, 24);
    Level38_7F128Keep(temporary2);

    if (temporary2 == 0)
        goto original1483_148;
original1483_105:
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 72) = temporary2;
    actualHeader68 = Level38_7F128_unk_ovlheader_80074368;
    actualHeader6C = Level38_7F128_unk_ovlheader_8007436C;
    __asm__(""
            : "=r"(privateState)
            : "0"(privateState), "r"(actualHeader68), "r"(actualHeader6C)
            : "$2");
    stackArgument5 = (int)((unsigned int)privateState + (unsigned int)16);
    stackArgument6 = (int)((unsigned int)0 + (unsigned int)100);
    argument1 = (int)((unsigned int)0 + (unsigned int)380);
    temporary2 = Level38_7F128_func_8002803C(argument0, argument1, actualHeader68, actualHeader6C,
                                             Level38_7F128_unk_ovlheader_80074364, stackArgument5,
                                             stackArgument6);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument1);
    temporary2 = (int)((unsigned int)temporary2 << 16);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 16);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(privateState, int *, 28) = temporary2;
    Level38_7F128Field(privateState, int *, 20) = 0;
    Level38_7F128_func_80034F40(argument0, argument1);
    temporary2 = Level38_7F128Field(owner, int *, 24);
    Level38_7F128Keep(temporary2);

    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)255), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)255), 0))
        goto original1483_148;
    Level38_7F128Field(owner, unsigned char *, 84) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 85) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 86) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)63);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 87) = temporary2;
    temporary2 = Level38_7F128Field(privateState, int *, 16);
    Level38_7F128Keep(temporary2);

    if (temporary2 <= 0 ? (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-1), 1)
                        : (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-1), 0))
        goto original1483_141;
    Level38_7F128Field(privateState, int *, 16) = temporary2;
original1483_141:
    Level38_7F128Field(owner, int *, 24) = 0;
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);

    goto original1483Return;
original1483_148:
    Level38_7F128Field(owner, unsigned char *, 84) = 0;
    Level38_7F128Field(owner, unsigned char *, 85) = 0;
    Level38_7F128Field(owner, unsigned char *, 86) = 0;
    Level38_7F128Field(owner, unsigned char *, 87) = 0;
    goto original1483Return;
original1483_153:
    argument1 = (int)&Level38_7F128_D_level_38_800746F0;
    Level38_7F128Keep(argument1);
    temporary2 = Level38_7F128Field(argument1, int *, 0);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(argument1, int *, 4);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(argument1, int *, 8);
    Level38_7F128Keep(argument0);
    Level38_7F128Field((int)&locals, int *, 0) = temporary2;
    Level38_7F128Field((int)&locals, int *, 4) = temporary3;
    Level38_7F128Field((int)&locals, int *, 8) = argument0;
    __asm__ volatile("" ::"m"(Level38_7F128Field((int)&locals, int *, 0)),
                     "m"(Level38_7F128Field((int)&locals, int *, 4)),
                     "m"(Level38_7F128Field((int)&locals, int *, 8)));
    argument1 = (int)&Level38_7F128_D_level_38_800746FC;
    Level38_7F128Keep(argument1);
    temporary2 = Level38_7F128Field(argument1, int *, 0);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(argument1, int *, 4);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(argument1, int *, 8);
    Level38_7F128Keep(argument0);
    Level38_7F128Field((int)&locals, int *, 16) = temporary2;
    Level38_7F128Field((int)&locals, int *, 20) = temporary3;
    Level38_7F128Field((int)&locals, int *, 24) = argument0;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary2);

    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == saved18)
        goto original1483_175;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128_func_80055D24(argument0, argument1);
original1483_175:
    temporary2 = Level38_7F128Field(owner, int *, 24);
    Level38_7F128Keep(temporary2);

    if (temporary2 == 0)
        goto original1483_209;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary2);

    if (temporary2 == saved18
            ? (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-2), 1)
            : (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-2), 0))
        goto original1483_209;
    temporary2 = (unsigned int)temporary2 < 2;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)255), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)255), 0))
        goto original1483_209;
    Level38_7F128Field(owner, unsigned char *, 84) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 85) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 86) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)63);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 87) = temporary2;
    temporary2 = Level38_7F128Field(privateState, int *, 16);
    Level38_7F128Keep(temporary2);

    if (temporary2 <= 0 ? (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-1), 1)
                        : (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-1), 0))
        goto original1483_196;
    Level38_7F128Field(privateState, int *, 16) = temporary2;
original1483_196:
    temporary2 = Level38_7F128Field(privateState, int *, 16);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 51;
    Level38_7F128Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)2), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)2), 0))
        goto original1483_203;
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
    goto original1483_207;
original1483_203:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);
original1483_207:
    Level38_7F128Field(owner, int *, 24) = 0;
    goto original1483_213;
original1483_209:
    Level38_7F128Field(owner, unsigned char *, 84) = 0;
    Level38_7F128Field(owner, unsigned char *, 85) = 0;
    Level38_7F128Field(owner, unsigned char *, 86) = 0;
    Level38_7F128Field(owner, unsigned char *, 87) = 0;
original1483_213:
    if (saved17 == 0)
        goto original1483_298;
    temporary2 = (int)((unsigned int)0 + (unsigned int)4);
    temporary3 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary3);

    Level38_7F128Keep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)12);
    if (temporary3 == temporary2)
        goto original1483_299;
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)&locals.sp50;
    temporary2 = Level38_7F128_func_8003645C(argument0, argument1, argument2);
    temporary3 = Level38_7F128Field(saved17, short *, 2);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field((int)&locals, volatile int *, 48);
    Level38_7F128Keep(argument0);

    /* Original CLOSED225..244 (8007F4AC..8007F4F8).
     * Every branch target is internal. Actual initialized inputs are V0
     * (the preceding real call return), V1/A0 (actual immediately preceding
     * loads), S1 (retained existing pointer), and the initialized SP50 word.
     * Actual S0/SP40 definitions occur on every exit; no incoming S0/SP capture.
     * Conditional native SH and its possible aliases/order remain unchanged. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "beq\t$4,$3,4f\n\t"
                     "slti\t$2,$2,1501\n\t"
                     "bne\t$2,$zero,5f\n\t"
                     "addiu\t$16,$sp,64\n\t"
                     "bne\t$3,$zero,1f\n\t"
                     "addiu\t$2,$3,-1\n\t"
                     "lh\t$2,0($17)\n\t"
                     "nop\n\t"
                     "addiu\t$2,$2,-1\n\t"
                     "bne\t$4,$2,2f\n\t"
                     "addu\t$4,$16,$zero\n\t"
                     "j\t6f\n\t"
                     "nop\n\t"
                     "1: beq\t$4,$2,5f\n\t"
                     "addiu\t$16,$sp,64\n\t"
                     "2: lw\t$2,%7\n\t"
                     "nop\n\t"
                     "sh\t$2,2($17)\n\t"
                     "4: addiu\t$16,$sp,64\n\t"
                     "5: addu\t$4,$16,$zero\n\t"
                     "6:\n\t"
                     ".set\treorder"
                     : "=r"(temporary2), "=r"(argument0), "=r"(saved16)
                     : "0"(temporary2), "1"(argument0), "r"(temporary3), "r"(saved17),
                       "m"(locals.sp50)
                     : "memory");
original1483_245:
    argument1 = Level38_7F128Field(saved17, short *, 2);
    Level38_7F128Keep(argument1);
    Level38_7F128Keep(argument1);
    temporary2 = Level38_7F128Field(saved17, int *, 12);
    Level38_7F128Keep(temporary2);
    argument1 = (int)((unsigned int)argument1 << 4);
    Level38_7F128Keep(argument1);
    argument1 = (int)((unsigned int)temporary2 + (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004F178(argument0, argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary3 = Level38_7F128Field((int)&locals, volatile int *, 32);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 36);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = temporary2 & 255;
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument3);
    stackArgument4 = 0;
    stackArgument5 = 0;
    temporary2 = Level38_7F128_func_8003585C(argument0, argument1, argument2, argument3,
                                             stackArgument4, stackArgument5);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14396);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)((unsigned int)0 + (unsigned int)33);
    Level38_7F128Keep(temporary3);
    /* Original270..275 (8007F560..8007F574), mixed C/original assembly.
     * The allocated o32 outgoing word at currentSP+16 is written BEFORE
     * the unrestricted original indexed LW, retaining possible same-byte
     * aliasing. Actual initialized inputs: V0=index, V1=33, A0=owner,
     * A2=0. The normal call consumes exactly five physical words. No C
     * SP object, array bound, default value, or implicit HI/LO ownerInput. */
    __asm__ volatile(".set\tnoreorder\n\t"
                     "sw\t$3,16($sp)\n\t"
                     "sll\t$2,$2,2\n\t"
                     "addu\t$2,$sp,$2\n\t"
                     "lw\t$5,48($2)\n\t"
                     "jal\tfunc_80035DDC\n\t"
                     "addiu\t$7,$zero,896\n\t"
                     ".set\treorder"
                     : "=r"(temporary2), "=r"(temporary3), "=r"(argument0), "=r"(argument2)
                     : "0"(temporary2), "1"(temporary3), "2"(argument0), "3"(argument2)
                     : "$5", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24",
                       "$25", "$31", "hi", "lo", "memory");
    Level38_7F128Keep(owner);
    argument0 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F334(argument0, argument1);
    temporary2 = temporary2 < 1500;
    Level38_7F128Keep(temporary2);
    if (temporary2 == 0)
        goto original1483_298;
    temporary2 = Level38_7F128Field(saved17, short *, 2);
    Level38_7F128Keep(temporary2);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(saved17, short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level38_7F128Keep(temporary3);

    Level38_7F128Field(saved17, short *, 2) = temporary3;
original1483_298:
    temporary3 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary3);
original1483_299:

    switch ((unsigned int)temporary3) {
    case 0:
        __asm__ volatile("" ::"r"(temporary3));
        goto original1483_309;
    case 1:
        goto original1483_450;
    case 2:
        goto original1483_461;
    case 3:
        goto original1483_653;
    case 4:
        goto original1483_770;
    default:
        goto original1483Return;
    }
original1483_309:
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level38_7F128_func_800359A4(argument0, argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483Return;
    saved16 = (int)&Level38_7F128_D_80070328;
    Level38_7F128Keep(saved16);
    temporary3 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(saved16, int *, 4);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument1 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F264(argument0, argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 < 0)
        goto original1483_343;
    temporary3 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(saved16, int *, 4);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument1 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F264(argument0, argument1);
    temporary2 = temporary2 < 20;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 != 0)
        goto original1483_357;

    goto original1483Return;
original1483_343:
    temporary3 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(saved16, int *, 4);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument1 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F264(argument0, argument1);
    temporary2 = (int)((unsigned int)0 - (unsigned int)temporary2);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 20;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483Return;
original1483_357:
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128_func_80034F40(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)700);
    Level38_7F128Keep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved16 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(saved16);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)12);
    if (saved16 == 0)
        goto original1483Return;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_80065920 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, int *, 12) = temporary2;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(temporary2);
    argument1 = (int)((unsigned int)argument0 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(argument2);
    Level38_7F128Field(saved16, int *, 20) = 0;
    __asm__ volatile("" ::"m"(Level38_7F128Field(saved16, int *, 20)) : "memory");
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, int *, 16) = temporary2;
    temporary2 = Level38_7F128_func_8004F194(argument0, argument1, argument2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, 808);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(saved16, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 812);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(saved16, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)32);
    temporary2 = Level38_7F128_func_80036018(argument0, argument1, argument2);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)&locals.sp20;
    Level38_7F128Keep(temporary3);
    argument0 = (int)0x80070000U;
    Level38_7F128Keep(argument0);
    argument0 = Level38_7F128Field(argument0, int *, -14396);
    Level38_7F128Keep(argument0);

    argument1 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_80065920 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(argument1);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)argument0 << 2);
    Level38_7F128Keep(argument0);
    argument0 = (int)((unsigned int)argument0 + (unsigned int)temporary3);
    Level38_7F128Keep(argument0);
    /* Original Rev0 0x8007f7cc; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,0(%1)" : "=r"(temporary3) : "r"(argument0) : "memory");

    Level38_7F128Keep(argument1);
    Level38_7F128Keep(temporary3);
    completeSignedProduct = (long long)argument1 * (long long)temporary3;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    argument1 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(argument1);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        temporary8 = wholeCapturedProjection;
    } while (0);
    Level38_7F128Keep(temporary8);
    temporary3 = (temporary8 >> 12);
    Level38_7F128Keep(temporary3);
    Level38_7F128Field(argument1, int *, 0) = temporary3;

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    /* Original435 at8007F7F4: repeat the actual unrestricted machine LW
     * through the already initialized A0 address. This preserves the second
     * real memory observation; no C array, selector bound or default word. */
    __asm__ volatile("lw %0,0(%1)" : "=r"(temporary2) : "r"(argument0) : "memory");
    Level38_7F128Keep(temporary2);

    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary2);
    completeSignedProduct = (long long)temporary3 * (long long)temporary2;
    __asm__ volatile("" ::"x"(completeSignedProduct));
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    temporary3 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(temporary3);
    do {
        int wholeCapturedProjection;
        __asm__("" : "=l"(wholeCapturedProjection) : "x"(completeSignedProduct));
        temporary8 = wholeCapturedProjection;
    } while (0);
    Level38_7F128Keep(temporary8);
    temporary2 = (temporary8 >> 12);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(temporary3, int *, 4) = temporary2;
    temporary2 = Level38_7F128Field(saved16, int *, 0);
    Level38_7F128Keep(temporary2);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument1);
    Level38_7F128Field(temporary2, int *, 8) = 0;
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);

    goto original1483Return;
original1483_450:
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14480);
    Level38_7F128Keep(temporary2);

    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128_func_80034F40(argument0, argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)50);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 73) = 0;
    Level38_7F128Field(privateState, int *, 12) = temporary2;
    goto original1483Return;
original1483_461:
    temporary2 = Level38_7F128Field(privateState, int *, 24);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14544);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    saved22 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(saved22);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);
    Level38_7F128Field((int)&locals, int *, 56) = 0;
    __asm__(""
            : "=r"(temporary2)
            : "0"(temporary2), "m"(Level38_7F128Field((int)&locals, int *, 56)));
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 60) = 0;
    if (temporary2 != 0)
        goto original1483_491;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14360);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 30001;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)326);
    if (temporary2 != 0)
        goto original1483_491;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)7);
    if (temporary3 == 0)
        goto original1483_491;
    Level38_7F128Field(temporary3, unsigned char *, 71) = temporary2;
original1483_491:
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    saved20 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != 0)
        goto original1483_552;
    Level38_7F128Keep(temporary2);
    Level38_7F128Keep(saved20);
    Level38_7F128Keep(temporary2);
    saved21 = (int)&Level38_7F128_D_8006E020;
    Level38_7F128Keep(saved21);
    saved18 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(saved18);
original1483_503:
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14360);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 30001;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)541);
    if (temporary2 != 0)
        goto original1483_552;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved17 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(saved17);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (saved17 == 0)
        goto original1483_539;
    temporary3 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(saved21, int *, 0);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(saved21, int *, 4);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    saved16 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level38_7F128_func_rand();
    saved16 = (int)((unsigned int)saved16 + (unsigned int)64);
    Level38_7F128Keep(saved16);
    temporary2 = temporary2 & 31;
    Level38_7F128Keep(temporary2);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)temporary2);
    Level38_7F128Keep(saved16);
    Level38_7F128Field(saved17, unsigned char *, 70) = saved16;
    temporary2 = Level38_7F128_func_rand();
    temporary2 = temporary2 & 30;
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)saved18 + (unsigned int)temporary2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-15);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 69) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)8);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 71) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)42);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 76) = temporary2;
original1483_539:
    saved20 = (int)((unsigned int)saved20 + (unsigned int)1);
    Level38_7F128Keep(saved20);
    temporary2 = saved20 < 5;
    Level38_7F128Keep(temporary2);
    saved18 = (int)((unsigned int)saved18 + (unsigned int)51);
    if (temporary2 == 0)
        goto original1483_552;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    if (temporary2 == 0)
        goto original1483_503;
original1483_552:
    __asm__ volatile("" ::"r"(temporary2));
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);
    saved20 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(saved20);
    savedValue30 = (int)&Level38_7F128_D_80070328;
    Level38_7F128Keep(savedValue30);
    saved21 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(saved21);
original1483_560:
    argument1 = (int)&Level38_7F128_D_level_38_80074708;
    Level38_7F128Keep(argument1);
    temporary2 = Level38_7F128Field(argument1, int *, 0);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(argument1, int *, 4);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(argument1, int *, 8);
    Level38_7F128Keep(argument0);
    Level38_7F128Field((int)&locals, int *, 64) = temporary2;
    Level38_7F128Field((int)&locals, int *, 68) = temporary3;
    Level38_7F128Field((int)&locals, int *, 72) = argument0;
    temporary2 = Level38_7F128Field(saved22, unsigned short *, 0);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(privateState, int *, 24);
    Level38_7F128Keep(temporary3);
    argument0 = temporary2 & 32767;
    Level38_7F128Keep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = (int)((unsigned int)argument0 << 1), 1)
                                 : (temporary2 = (int)((unsigned int)argument0 << 1), 0))
        goto original1483_624;
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)argument0);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)argument0);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -15024);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level38_7F128Keep(temporary2);
    saved17 = (int)((unsigned int)temporary3 + (unsigned int)temporary2);
    Level38_7F128Keep(saved17);
    temporary3 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(temporary3);
    temporary2 = Level38_7F128Field(saved17, unsigned char *, 72);
    Level38_7F128Keep(temporary2);
    saved18 = Level38_7F128Field(saved17, int *, 0);
    Level38_7F128Keep(saved18);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != temporary3)
        goto original1483_623;
    saved16 = (int)((unsigned int)saved20 << 2);
    Level38_7F128Keep(saved16);
    temporary2 = (int)&locals.sp20;
    Level38_7F128Keep(temporary2);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)temporary2);
    Level38_7F128Keep(saved16);
    temporary2 = (int)((unsigned int)0 + (unsigned int)240);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, int *, 56) = saved17;
    Level38_7F128Field(saved18, int *, 52) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)150);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved18, int *, 48) = temporary2;
    temporary3 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(savedValue30, int *, 0);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(savedValue30, int *, 4);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument1 = Level38_7F128Field(saved16, int *, 64);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003617C(argument0, argument1);
    argument0 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(argument1);
    Level38_7F128Field(saved18, int *, 44) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)25);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved18, int *, 16) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 72) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)100);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved18, int *, 36) = owner;
    Level38_7F128Field(saved18, int *, 12) = temporary2;
    Level38_7F128_func_80034F40(argument0, argument1);
    argument0 = (int)((unsigned int)saved17 + (unsigned int)12);
    Level38_7F128Keep(argument0);
    Level38_7F128Keep(owner);
    argument1 = (int)((unsigned int)owner + (unsigned int)12);
    temporary2 = Level38_7F128_func_8004F178(argument0, argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)32);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, int *, 24) = 0;
    Level38_7F128Field(saved17, unsigned char *, 65) = saved21;
    Level38_7F128Field(saved17, unsigned char *, 76) = temporary2;
    Level38_7F128Field(saved17, unsigned char *, 77) = saved21;
original1483_623:
    saved22 = (int)((unsigned int)saved22 + (unsigned int)2);
    Level38_7F128Keep(saved22);
original1483_624:
    saved20 = (int)((unsigned int)saved20 + (unsigned int)1);
    Level38_7F128Keep(saved20);
    temporary2 = saved20 < 2;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_560;
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 56);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field(privateState, int *, 36) = temporary2;
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 60);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field(privateState, int *, 40) = temporary2;
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 56);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(temporary3);
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 60);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field(temporary3, int *, 40) = temporary2;
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 60);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(temporary3);
    temporary2 = Level38_7F128Field((int)&locals, volatile int *, 56);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field(temporary3, int *, 40) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 65) = 0;
    Level38_7F128Field(owner, unsigned char *, 76) = 0;
    Level38_7F128Field(owner, unsigned char *, 77) = 0;
    Level38_7F128Field(privateState, int *, 12) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
original1483_653:
    temporary2 = Level38_7F128Field(privateState, int *, 12);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 3;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_729;
    Level38_7F128Keep(temporary2);
    saved18 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(saved18);
    saved20 = (int)&locals.sp80;
    Level38_7F128Keep(saved20);
    saved17 = (int)&locals.sp60;
    Level38_7F128Keep(saved17);
    saved16 = (int)&locals.sp70;
    Level38_7F128Keep(saved16);
original1483_662:
    Level38_7F128Field((int)&locals, unsigned char *, 120) = 0;
    temporary2 = Level38_7F128_func_rand();
    Level38_7F128Field((int)&locals, unsigned char *, 121) = temporary2;
    temporary2 = Level38_7F128_func_rand();
    argument0 = (int)&locals.sp98;
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    Level38_7F128Field((int)&locals, unsigned char *, 122) = temporary2;
    Level38_7F128_func_8004EA90(argument0, argument1, argument2);
    saved18 = (int)((unsigned int)saved18 + (unsigned int)1);
    temporary2 = Level38_7F128_func_rand();
    argument0 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = temporary2 & 31;
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)48);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 64) = temporary2;
    Level38_7F128Field((int)&locals, int *, 68) = 0;
    Level38_7F128Field((int)&locals, int *, 72) = 0;
    Level38_7F128_func_8004ED6C(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F178(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    Level38_7F128Keep(owner);
    Level38_7F128Keep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    temporary2 = Level38_7F128_func_8004F194(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128_func_8004F0E8(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128_func_8004F0E8(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary2 = saved18 < 4;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)6);
    if (temporary2 != 0)
        goto original1483_662;
    argument1 = (int)((unsigned int)0 + (unsigned int)70);
    Level38_7F128Keep(argument1);
    Level38_7F128Keep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)0 + (unsigned int)16);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
original1483_729:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14784);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 & 1;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    if (temporary2 != 0)
        goto original1483_763;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_763;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14360);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 30001;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_763;
    argument0 = (int)((unsigned int)0 + (unsigned int)482);
    Level38_7F128Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)42);
    if (temporary3 == 0)
        goto original1483_762;
    Level38_7F128Field(temporary3, unsigned char *, 76) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(temporary3, unsigned char *, 71) = temporary2;
original1483_762:
    Level38_7F128Keep(privateState);
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    Level38_7F128Keep(argument0);
original1483_763:
    __asm__ volatile("" ::"r"(temporary2));
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level38_7F128_func_800359A4(argument0, argument1);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)4), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)4), 0))
        goto original1483Return;
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
    Level38_7F128Field(owner, int *, 8) = 0;
    goto original1483Return;
original1483_770:
    temporary2 = Level38_7F128Field(privateState, int *, 36);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(privateState, int *, 40);
    Level38_7F128Keep(temporary3);
    temporary2 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(temporary3, int *, 0);
    Level38_7F128Keep(temporary3);
    temporary2 = Level38_7F128Field(temporary2, int *, 16);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(temporary3, int *, 16);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(privateState, int *, 16) = temporary2;
    if (temporary2 > 0)
        goto original1483Return;
    argument0 = Level38_7F128Field(privateState, int *, 28);
    Level38_7F128Keep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level38_7F128Keep(temporary2);
    if (argument0 == temporary2)
        goto original1483_786;

    temporary2 = Level38_7F128_func_80028154(argument0);
original1483_786:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003BA00(argument0);

    goto original1483_1308;
original1483_790:
    argument1 = (int)&Level38_7F128_D_level_38_80074714;
    Level38_7F128Keep(argument1);
    temporary2 = Level38_7F128Field(argument1, int *, 0);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(argument1, int *, 4);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(argument1, int *, 8);
    Level38_7F128Keep(argument0);
    Level38_7F128Field((int)&locals, int *, 96) = temporary2;
    Level38_7F128Field((int)&locals, int *, 100) = temporary3;
    Level38_7F128Field((int)&locals, int *, 104) = argument0;
    __asm__(""
            : "=r"(owner)
            : "0"(owner), "m"(Level38_7F128Field((int)&locals, int *, 96)),
              "m"(Level38_7F128Field((int)&locals, int *, 100)),
              "m"(Level38_7F128Field((int)&locals, int *, 104)));
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128_func_80055D24(argument0, argument1);
    temporary2 = Level38_7F128Field(owner, int *, 24);
    Level38_7F128Keep(temporary2);

    if (temporary2 == 0)
        goto original1483_924;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-2);
    Level38_7F128Keep(temporary2);
    temporary2 = (unsigned int)temporary2 < 2;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 != 0)
        goto original1483_924;
    Level38_7F128Keep(temporary2);
    argument1 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)((unsigned int)0 + (unsigned int)255);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 84) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 85) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 86) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)63);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 87) = temporary2;
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);
    temporary2 = Level38_7F128Field(privateState, int *, 16);
    Level38_7F128Keep(temporary2);

    if (temporary2 <= 0 ? (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-1), 1)
                        : (temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-1), 0))
        goto original1483_826;
    Level38_7F128Field(privateState, int *, 16) = temporary2;
    if (temporary2 > 0)
        goto original1483_828;
original1483_826:
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
original1483_828:
    temporary2 = Level38_7F128Field(privateState, int *, 40);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(temporary3);
    temporary2 = Level38_7F128Field(privateState, int *, 16);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(temporary3, int *, 16);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    saved22 = (int)&locals.spA0;
    if (temporary2 > 0)
        goto original1483_928;
    Level38_7F128Field((int)&locals, int *, 216) = 0;
    __asm__ volatile("" ::"m"(Level38_7F128Field((int)&locals, int *, 216)) : "memory");
    temporary2 = Level38_7F128Field(privateState, int *, 24);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14544);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
    __asm__ volatile("" ::"r"(temporary3), "m"(Level38_7F128Field(owner, unsigned char *, 73)));
    savedValue30 = (int)((unsigned int)temporary3 + (unsigned int)0);
    Level38_7F128Keep(savedValue30);
original1483_847:
    temporary3 = Level38_7F128Field(savedValue30, unsigned short *, 0);
    Level38_7F128Keep(temporary3);

    temporary3 = temporary3 & 32767;
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -15024);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(argument0, unsigned char *, 72);
    Level38_7F128Keep(temporary2);
    temporary8 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(temporary8);
    if (temporary2 == temporary8)
        goto original1483_916;
    saved17 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(saved17);
    saved20 = (int)((unsigned int)argument0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_rand();
    saved16 = temporary2 & 255;
    Level38_7F128Keep(saved16);
    saved21 = (int)((unsigned int)saved20 + (unsigned int)12);
    Level38_7F128Keep(saved21);
    temporary2 = (int)((unsigned int)saved16 << 1);
    Level38_7F128Keep(temporary2);
    temporary8 = (int)&Level38_7F128_D_80065920;
    Level38_7F128Keep(temporary8);
    saved18 = (int)((unsigned int)temporary2 + (unsigned int)temporary8);
    Level38_7F128Keep(saved18);
original1483_871:
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    temporary3 = Level38_7F128Field(saved18, short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    argument2 = (int)((unsigned int)saved21 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 8);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 128) = temporary2;
    temporary2 = (int)((unsigned int)saved16 << 1);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    argument3 = (int)((unsigned int)saved22 + (unsigned int)0);
    Level38_7F128Keep(argument3);
    Level38_7F128Field((int)&locals, int *, 136) = 0;
    __asm__(""
            : "=r"(temporary3)
            : "0"(temporary3), "m"(Level38_7F128Field((int)&locals, int *, 136)));
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, 17124);
    Level38_7F128Keep(temporary3);
    temporary2 = (temporary2 >> 8);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 132) = temporary2;
    temporary2 = ((int (*)())temporary3)(argument0, argument1, argument2, argument3);
    temporary2 = saved17 & 1;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)saved22 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483_905;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    temporary2 = Level38_7F128_func_8004F110(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved21 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)saved22 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
original1483_905:
    saved18 = (int)((unsigned int)saved18 + (unsigned int)20);
    Level38_7F128Keep(saved18);
    saved17 = (int)((unsigned int)saved17 + (unsigned int)1);
    Level38_7F128Keep(saved17);
    temporary2 = saved17 < 24;
    Level38_7F128Keep(temporary2);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)10);
    if (temporary2 != 0)
        goto original1483_871;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)40);
    Level38_7F128Keep(argument1);
    Level38_7F128Field(saved20, int *, 8) = 0;
    Level38_7F128_func_800369B8(argument0, argument1);
    temporary8 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(temporary8);
    Level38_7F128Field(saved20, unsigned char *, 72) = temporary8;
original1483_916:
    temporary8 = Level38_7F128Field((int)&locals, volatile int *, 216);
    Level38_7F128Keep(temporary8);
    savedValue30 = (int)((unsigned int)savedValue30 + (unsigned int)2);
    Level38_7F128Keep(savedValue30);
    temporary8 = (int)((unsigned int)temporary8 + (unsigned int)1);
    Level38_7F128Keep(temporary8);
    temporary2 = temporary8 < 10;
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 216) = temporary8;
    if (temporary2 != 0)
        goto original1483_847;

    goto original1483_928;
original1483_924:
    Level38_7F128Field(owner, unsigned char *, 84) = 0;
    Level38_7F128Field(owner, unsigned char *, 85) = 0;
    Level38_7F128Field(owner, unsigned char *, 86) = 0;
    Level38_7F128Field(owner, unsigned char *, 87) = 0;
original1483_928:
    temporary3 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, int *, 24) = 0;
    if (temporary3 == temporary2)
        goto original1483_967;
    temporary2 = temporary3 < 2;
    Level38_7F128Keep(temporary2);
    if (temporary2 == 0)
        goto original1483_939;
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary3 == 0)
        goto original1483_946;

    goto original1483Return;
original1483_939:
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)3), 1)
                                 : (temporary2 = (int)((unsigned int)0 + (unsigned int)3), 0))
        goto original1483_1110;
    if (temporary3 == temporary2)
        goto original1483_1206;

    goto original1483Return;
original1483_946:
    argument1 = (int)((unsigned int)privateState + (unsigned int)52);
    Level38_7F128Keep(argument1);
    temporary2 = Level38_7F128_func_80035030(
        argument0, argument1, Level38_7F128Field(privateState, int *, 44),
        (int)((unsigned int)privateState + 48U), 8, 16, 2048, 35);
    temporary3 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(temporary3);
    if (temporary2 != temporary3 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)1), 1)
                                 : (temporary2 = (int)((unsigned int)0 + (unsigned int)1), 0))
        goto original1483Return;
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128_func_80034F40(argument0, argument1);

    goto original1483Return;
original1483_967:
    temporary8 = Level38_7F128Field((int)&locals, volatile int *, 192);
    Level38_7F128Keep(temporary8);

    temporary2 = temporary8 < 4097;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 != 0)
        goto original1483_1010;
    temporary2 = Level38_7F128_func_80035DDC(argument0, 80, 3000, 3000, 35);
    temporary2 = temporary2 & 32;
    Level38_7F128Keep(temporary2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483_990;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 6448);
    Level38_7F128Keep(temporary2);
    argument3 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument3);
    temporary3 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(temporary2, int *, 12);
    Level38_7F128Keep(argument0);
    argument1 = Level38_7F128Field(temporary2, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)argument3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary3 - (unsigned int)argument1);
    goto original1483_998;
original1483_990:
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, 808);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 812);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    Level38_7F128Keep(argument1);
original1483_998:

    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = temporary2 & 255;
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level38_7F128_func_8003585C(argument0, argument1, argument2, argument3,
                                             stackArgument4, stackArgument5);
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    goto original1483_1015;
original1483_1010:
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003573C(argument0, argument1, argument2, argument3);
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    Level38_7F128Keep(argument0);
original1483_1015:
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level38_7F128_func_800359A4(argument0, argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483Return;
    saved17 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(saved17);
    temporary2 = Level38_7F128Field(privateState, int *, 24);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14544);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(argument1);
original1483_1026:
    temporary3 = Level38_7F128Field(privateState, int *, 24);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)-1);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2)
        goto original1483_1098;
    temporary3 = Level38_7F128Field(argument1, unsigned short *, 0);
    Level38_7F128Keep(temporary3);

    temporary3 = temporary3 & 32767;
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -15024);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level38_7F128Keep(temporary2);
    saved16 = (int)((unsigned int)temporary3 + (unsigned int)temporary2);
    Level38_7F128Keep(saved16);
    argument0 = Level38_7F128Field(saved16, unsigned char *, 72);
    Level38_7F128Keep(argument0);
    temporary2 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(temporary2);
    temporary3 = argument0 & 255;
    Level38_7F128Keep(temporary3);
    if (temporary3 == temporary2 ? (temporary2 = argument0 & 128, 1)
                                 : (temporary2 = argument0 & 128, 0))
        goto original1483_1048;
    argument1 = (int)((unsigned int)argument1 + (unsigned int)2);
    if (temporary2 == 0)
        goto original1483_1098;
original1483_1048:
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)6);
    Level38_7F128Keep(argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, unsigned char *, 72) = temporary2;
    Level38_7F128Field(saved16, unsigned char *, 73) = 0;
    Level38_7F128_func_80034F40(argument0, argument1);
    Level38_7F128Field(saved16, unsigned char *, 68) = 0;
    Level38_7F128Field(saved16, unsigned char *, 69) = 0;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(temporary2);

    Level38_7F128Field(saved16, unsigned char *, 70) = temporary2;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_80065920 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)12);
    Level38_7F128Keep(argument0);
    temporary2 = (int)((unsigned int)temporary3 << 3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 5);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, int *, 12) = temporary2;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 70);
    Level38_7F128Keep(temporary2);
    argument1 = (int)((unsigned int)argument0 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(argument2);
    Level38_7F128Field(saved16, int *, 20) = 0;
    __asm__ volatile("" ::"m"(Level38_7F128Field(saved16, int *, 20)) : "memory");
    temporary2 = (int)((unsigned int)temporary3 << 3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 5);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, int *, 16) = temporary2;
    temporary2 = Level38_7F128_func_8004F194(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)((unsigned int)0 + (unsigned int)32);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved16, int *, 24) = 0;
    Level38_7F128Field(saved16, unsigned char *, 65) = saved17;
    Level38_7F128Field(saved16, unsigned char *, 76) = temporary2;
    Level38_7F128Field(saved16, unsigned char *, 77) = saved17;
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);

    goto original1483_1102;
original1483_1098:
    argument2 = (int)((unsigned int)argument2 + (unsigned int)1);
    Level38_7F128Keep(argument2);
    temporary2 = argument2 < 10;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_1026;
original1483_1102:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14396);
    Level38_7F128Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)(int)&locals + (unsigned int)temporary2 - 32U);
    Level38_7F128Keep(temporary2);
    /* Original Rev0 0x80080274; unrestricted native LW, not a C array lookup. */
    __asm__ volatile("lw %0,128(%1)" : "=r"(temporary2) : "0"(temporary2) : "memory");
    Level38_7F128Field(privateState, int *, 12) = temporary2;
    goto original1483Return;
original1483_1110:
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_1134;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14360);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 30001;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)326);
    if (temporary2 != 0)
        goto original1483_1134;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)7);
    if (temporary3 == 0)
        goto original1483_1134;
    Level38_7F128Field(temporary3, unsigned char *, 71) = temporary2;
original1483_1134:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    saved20 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 != 0)
        goto original1483_1195;
    Level38_7F128Keep(temporary2);
    Level38_7F128Keep(saved20);
    Level38_7F128Keep(temporary2);
    saved21 = (int)&Level38_7F128_D_8006E020;
    Level38_7F128Keep(saved21);
    saved18 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(saved18);
original1483_1146:
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14360);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 30001;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)541);
    if (temporary2 != 0)
        goto original1483_1195;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    saved17 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(saved17);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (saved17 == 0)
        goto original1483_1182;
    temporary3 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(saved21, int *, 0);
    Level38_7F128Keep(argument0);
    temporary2 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(temporary2);
    argument1 = Level38_7F128Field(saved21, int *, 4);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)temporary3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary2 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    saved16 = (int)((unsigned int)temporary2 + (unsigned int)0);
    temporary2 = Level38_7F128_func_rand();
    saved16 = (int)((unsigned int)saved16 + (unsigned int)64);
    Level38_7F128Keep(saved16);
    temporary2 = temporary2 & 31;
    Level38_7F128Keep(temporary2);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)temporary2);
    Level38_7F128Keep(saved16);
    Level38_7F128Field(saved17, unsigned char *, 70) = saved16;
    temporary2 = Level38_7F128_func_rand();
    temporary2 = temporary2 & 30;
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)saved18 + (unsigned int)temporary2);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)-15);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 69) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)8);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 71) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)42);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(saved17, unsigned char *, 76) = temporary2;
original1483_1182:
    saved20 = (int)((unsigned int)saved20 + (unsigned int)1);
    Level38_7F128Keep(saved20);
    temporary2 = saved20 < 5;
    Level38_7F128Keep(temporary2);
    saved18 = (int)((unsigned int)saved18 + (unsigned int)51);
    if (temporary2 == 0)
        goto original1483_1195;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    if (temporary2 == 0)
        goto original1483_1146;
original1483_1195:
    __asm__ volatile("" ::"r"(temporary2));
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)5);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);
    temporary2 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 65) = 0;
    Level38_7F128Field(owner, unsigned char *, 76) = 0;
    Level38_7F128Field(owner, unsigned char *, 77) = 0;
    Level38_7F128Field(privateState, int *, 12) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
original1483_1206:
    temporary2 = Level38_7F128Field(privateState, int *, 12);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 6;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_1263;
    Level38_7F128Keep(temporary2);
    saved18 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(saved18);
    saved20 = (int)&locals.spC0;
    Level38_7F128Keep(saved20);
    saved17 = (int)&locals.spA0;
    Level38_7F128Keep(saved17);
    saved16 = (int)&locals.spB0;
    Level38_7F128Keep(saved16);
original1483_1215:
    Level38_7F128Field((int)&locals, unsigned char *, 184) = 0;
    temporary2 = Level38_7F128_func_rand();
    Level38_7F128Field((int)&locals, unsigned char *, 185) = temporary2;
    temporary2 = Level38_7F128_func_rand();
    argument0 = (int)&locals.spD8;
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    Level38_7F128Field((int)&locals, unsigned char *, 186) = temporary2;
    Level38_7F128_func_8004EA90(argument0, argument1, argument2);
    saved18 = (int)((unsigned int)saved18 + (unsigned int)1);
    temporary2 = Level38_7F128_func_rand();
    argument0 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved17 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = temporary2 & 31;
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)48);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 128) = temporary2;
    Level38_7F128Field((int)&locals, int *, 132) = 0;
    Level38_7F128Field((int)&locals, int *, 136) = 0;
    Level38_7F128_func_8004ED6C(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = Level38_7F128_func_8004F178(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128_func_8004F0E8(argument0, argument1);
    argument0 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument1);
    Level38_7F128Keep(owner);
    Level38_7F128Keep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    temporary2 = Level38_7F128_func_8004F194(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved16 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)saved17 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
    temporary2 = saved18 < 4;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)0 + (unsigned int)6);
    if (temporary2 != 0)
        goto original1483_1215;
    argument1 = (int)((unsigned int)0 + (unsigned int)70);
    Level38_7F128Keep(argument1);
    Level38_7F128Keep(owner);
    argument2 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)0 + (unsigned int)16);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
original1483_1263:
    __asm__ volatile("" ::"r"(temporary2));
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14784);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 & 1;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    if (temporary2 != 0)
        goto original1483_1297;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14984);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, -14988);
    Level38_7F128Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary2 - (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = temporary2 < 21;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_1297;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, -14360);
    Level38_7F128Keep(temporary2);

    temporary2 = temporary2 < 30001;
    Level38_7F128Keep(temporary2);
    if (temporary2 != 0)
        goto original1483_1297;
    argument0 = (int)((unsigned int)0 + (unsigned int)482);
    Level38_7F128Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17120);
    Level38_7F128Keep(temporary2);

    argument1 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    temporary3 = (int)((unsigned int)temporary2 + (unsigned int)0);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)42);
    if (temporary3 == 0)
        goto original1483_1296;
    Level38_7F128Field(temporary3, unsigned char *, 76) = temporary2;
    temporary2 = (int)((unsigned int)0 + (unsigned int)10);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(temporary3, unsigned char *, 71) = temporary2;
original1483_1296:
    Level38_7F128Keep(privateState);
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    Level38_7F128Keep(argument0);
original1483_1297:
    __asm__ volatile("" ::"r"(temporary2));
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    temporary2 = Level38_7F128_func_800359A4(argument0, argument1);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483Return;
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128_func_80055D24(argument0, argument1);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = Level38_7F128_func_8003BA00(argument0);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)48);
    Level38_7F128_func_800369B8(argument0, argument1);
original1483_1308:
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    temporary2 = Level38_7F128_func_80055B18(argument0);

    goto original1483Return;
original1483_1312:
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128_func_80055D24(argument0, argument1);
    temporary2 = Level38_7F128Field(owner, int *, 24);
    Level38_7F128Keep(temporary2);

    if (temporary2 == 0)
        goto original1483_1328;
    temporary2 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary2);

    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 != saved16)
        goto original1483_1328;
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, int *, 8) = 0;
    Level38_7F128Field(owner, unsigned char *, 73) = temporary2;
    temporary2 = Level38_7F128_func_8003BABC(argument0, argument1, argument2);
original1483_1328:
    temporary3 = Level38_7F128Field(owner, unsigned char *, 72);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2)
        goto original1483_1344;
    temporary8 = Level38_7F128Field((int)&locals, volatile int *, 192);
    Level38_7F128Keep(temporary8);

    temporary2 = temporary8 < 1024;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483_1344;
    temporary2 = (int)&Level38_7F128_D_80070328 + 36;
    Level38_7F128Keep(temporary2);
    temporary3 = Level38_7F128Field(temporary2, int *, 0);
    Level38_7F128Keep(temporary3);
    argument1 = (int)((unsigned int)0 + (unsigned int)40);
    Level38_7F128Keep(argument1);
    temporary3 = temporary3 | 1;
    Level38_7F128Keep(temporary3);
    Level38_7F128Field(temporary2, int *, 0) = temporary3;
    goto original1483_1466;
original1483_1344:
    temporary3 = Level38_7F128Field(owner, unsigned char *, 73);
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2 ? (temporary2 = temporary3 < 2, 1)
                                 : (temporary2 = temporary3 < 2, 0))
        goto original1483_1378;
    if (temporary2 == 0)
        goto original1483_1354;
    argument0 = (int)((unsigned int)privateState + (unsigned int)12);
    if (temporary3 == 0)
        goto original1483_1359;

    goto original1483Return;
original1483_1354:
    temporary2 = (int)((unsigned int)0 + (unsigned int)2);
    Level38_7F128Keep(temporary2);
    if (temporary3 == temporary2)
        goto original1483_1416;

    goto original1483Return;
original1483_1359:
    argument1 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(argument1);
    saved16 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(saved16);
    temporary2 = (int)((unsigned int)0 + (unsigned int)32);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 65) = saved16;
    Level38_7F128Field(owner, unsigned char *, 76) = temporary2;
    Level38_7F128Field(owner, unsigned char *, 77) = saved16;
    temporary2 = Level38_7F128_func_800359A4(argument0, argument1);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)0 + (unsigned int)33), 1)
                        : (temporary2 = (int)((unsigned int)0 + (unsigned int)33), 0))
        goto original1483_1370;
    Level38_7F128Field(owner, unsigned char *, 73) = saved16;
    goto original1483Return;
original1483_1370:
    temporary2 = Level38_7F128_func_80035DDC(owner, 120, 896, 0, temporary2);

    goto original1483Return;
original1483_1378:
    temporary2 = Level38_7F128_func_80035DDC(owner, 120, 896, 896, 35);
    temporary2 = temporary2 & 32;
    Level38_7F128Keep(temporary2);
    argument2 = (int)((unsigned int)0 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483_1399;
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 6448);
    Level38_7F128Keep(temporary2);
    argument3 = Level38_7F128Field(owner, int *, 12);
    Level38_7F128Keep(argument3);
    temporary3 = Level38_7F128Field(owner, int *, 16);
    Level38_7F128Keep(temporary3);
    argument0 = Level38_7F128Field(temporary2, int *, 12);
    Level38_7F128Keep(argument0);
    argument1 = Level38_7F128Field(temporary2, int *, 16);
    Level38_7F128Keep(argument1);
    argument0 = (int)((unsigned int)argument3 - (unsigned int)argument0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)temporary3 - (unsigned int)argument1);
    temporary2 = Level38_7F128_func_8004E880(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    goto original1483_1407;
original1483_1399:
    argument0 = (int)((unsigned int)privateState + (unsigned int)20);
    Level38_7F128Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17348);
    Level38_7F128Keep(temporary2);
    argument2 = (int)&Level38_7F128_D_80070328;
    Level38_7F128Keep(argument2);
    Level38_7F128Keep(owner);
    argument1 = (int)((unsigned int)owner + (unsigned int)12);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2);
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
original1483_1407:
    argument1 = temporary2 & 255;
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)0 + (unsigned int)3);
    Level38_7F128Keep(argument2);
    argument3 = (int)((unsigned int)0 + (unsigned int)0);
    Level38_7F128Keep(argument3);
    temporary2 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(temporary2);
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    temporary2 = Level38_7F128_func_8003585C(argument0, argument1, argument2, argument3,
                                             stackArgument4, stackArgument5);

    goto original1483Return;
original1483_1416:
    saved16 = (int)((unsigned int)0 + (unsigned int)0);
    temporary2 = Level38_7F128_func_rand();
    saved17 = temporary2 & 255;
    Level38_7F128Keep(saved17);
    saved21 = (int)((unsigned int)owner + (unsigned int)12);
    Level38_7F128Keep(saved21);
    saved20 = (int)&locals.spC0;
    Level38_7F128Keep(saved20);
    temporary3 = (int)&Level38_7F128_D_80065920;
    Level38_7F128Keep(temporary3);
    temporary2 = (int)((unsigned int)saved17 << 1);
    Level38_7F128Keep(temporary2);
    saved18 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(saved18);
original1483_1425:
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    temporary3 = Level38_7F128Field(saved18, short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    argument2 = (int)((unsigned int)saved21 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary2 = (temporary2 >> 8);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 160) = temporary2;
    temporary2 = (int)((unsigned int)saved17 << 1);
    Level38_7F128Keep(temporary2);

    temporary3 = Level38_7F128Field(
        ((int)((unsigned int)&Level38_7F128_D_800658A0 + (unsigned int)temporary2)), short *, 0);
    Level38_7F128Keep(temporary3);
    Level38_7F128Keep(temporary3);
    argument3 = (int)((unsigned int)saved20 + (unsigned int)0);
    Level38_7F128Keep(argument3);
    Level38_7F128Field((int)&locals, int *, 168) = 0;
    __asm__(""
            : "=r"(temporary3)
            : "0"(temporary3), "m"(Level38_7F128Field((int)&locals, int *, 168)));
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level38_7F128Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 + (unsigned int)temporary3);
    Level38_7F128Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level38_7F128Keep(temporary3);
    temporary3 = Level38_7F128Field(temporary3, int *, 17124);
    Level38_7F128Keep(temporary3);
    temporary2 = (temporary2 >> 8);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field((int)&locals, int *, 164) = temporary2;
    temporary2 = ((int (*)())temporary3)(argument0, argument1, argument2, argument3);
    temporary2 = saved16 & 1;
    Level38_7F128Keep(temporary2);
    argument0 = (int)((unsigned int)saved20 + (unsigned int)0);
    if (temporary2 == 0)
        goto original1483_1459;
    argument1 = (int)((unsigned int)0 + (unsigned int)1);
    temporary2 = Level38_7F128_func_8004F110(argument0, argument1);
    argument0 = (int)((unsigned int)0 + (unsigned int)1);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)20);
    Level38_7F128Keep(argument1);
    argument2 = (int)((unsigned int)saved21 + (unsigned int)0);
    Level38_7F128Keep(argument2);
    temporary2 = (int)0x80070000U;
    Level38_7F128Keep(temporary2);
    temporary2 = Level38_7F128Field(temporary2, int *, 17124);
    Level38_7F128Keep(temporary2);

    argument3 = (int)((unsigned int)saved20 + (unsigned int)0);
    temporary2 = ((int (*)())temporary2)(argument0, argument1, argument2, argument3);
original1483_1459:
    saved18 = (int)((unsigned int)saved18 + (unsigned int)72);
    Level38_7F128Keep(saved18);
    saved16 = (int)((unsigned int)saved16 + (unsigned int)1);
    Level38_7F128Keep(saved16);
    temporary2 = saved16 < 7;
    Level38_7F128Keep(temporary2);
    saved17 = (int)((unsigned int)saved17 + (unsigned int)36);
    if (temporary2 != 0)
        goto original1483_1425;
    argument0 = (int)((unsigned int)owner + (unsigned int)0);
    Level38_7F128Keep(argument0);
    argument1 = (int)((unsigned int)0 + (unsigned int)40);
    Level38_7F128Keep(argument1);
original1483_1466:
    Level38_7F128Field(owner, int *, 8) = 0;
    Level38_7F128_func_800369B8(argument0, argument1);
    temporary2 = (int)((unsigned int)0 + (unsigned int)4);
    Level38_7F128Keep(temporary2);
    Level38_7F128Field(owner, unsigned char *, 72) = temporary2;
original1483Return:
    return;
}
#undef Level38_7F128Field
#undef Level38_7F128Keep


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007EB68,439 instructions, sibling4597. Verified28 spawn/particle C
 * reused; all raw fields, branches and constants from original38.
 * Units, helper contracts and cadence unresolved; uninstalled until exact. */
#define K38Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int K38func_80018368(void*,void*) __asm__("func_80018368");

int K38func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");

int K38func_800359A4(void*,int) __asm__("func_800359A4");

int K38func_8003BABC(void*,int,int) __asm__("func_8003BABC");

int K38func_8004E880(int,int,int) __asm__("func_8004E880");

int K38func_8004EA90(void*,void*,int) __asm__("func_8004EA90");

int K38func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");

int K38func_8004F0E8(void*,int) __asm__("func_8004F0E8");

int K38func_8004F110(void*,int) __asm__("func_8004F110");

int K38func_8004F178(void*,void*) __asm__("func_8004F178");

int K38func_8004F194(void*,void*,void*) __asm__("func_8004F194");

int K38func_80055B18(void*) __asm__("func_80055B18");

int K38rand(void) __asm__("rand");

extern short K38D_800658A0[] __asm__("D_800658A0");

extern short K38D_80065920[] __asm__("D_80065920");

extern int K38D_8006C574 __asm__("D_8006C574");

extern int K38D_8006C578 __asm__("D_8006C578");

extern int K38D_8006C640 __asm__("D_8006C640");

extern int K38D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char K38D_8006E020[] __asm__("D_8006E020");

extern void *(*K38SpawnMoby)(int,void*) __asm__("SpawnMoby");

extern int (*K38SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");

extern unsigned char K38D_80070328[] __asm__("D_80070328");
int K38func_8004F334(void*,void*) __asm__("func_8004F334");

int K38H19194() __asm__("func_80019194");
int K38H4EF74() __asm__("func_8004EF74");
int K38H3636C() __asm__("func_8003636C");
extern int K38Delta __asm__("D_8006C648");
extern int K38Reflect[] __asm__("D_80071918");



extern unsigned char* K38Pool __asm__("D_8006C550");
extern unsigned short** K38Lists __asm__("D_8006C730");
extern int K38Mode __asm__("D_8006C7C4");
extern int K38Gate __asm__("D_8006C770");
int K38H55D24() __asm__("func_80055D24");
int K38H34F40() __asm__("func_80034F40");
int K38H36A68() __asm__("func_80036A68");
int K38H3BA00() __asm__("func_8003BA00");
int K38H369B8() __asm__("func_800369B8");
int K38H55C24() __asm__("func_80055C24");
int K38H34F80() __asm__("func_80034F80");
int K38H35D38() __asm__("func_80035D38");
int K38H5629C() __asm__("func_8005629C");
extern int (*K38Notify)() __asm__("unk_ovlheader_800743E0");
extern unsigned char* K38Classes[] __asm__("D_8006EE2C");
void func_level_38_80080854(void* input){
 struct {int first[4],second[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$18")=input;
 register unsigned char* state __asm__("$21");
 register int selectedAngle __asm__("$16");
 register unsigned char* nested16 __asm__("$16");
 register unsigned char* linked17 __asm__("$17");
 register void* spawned21D __asm__("$17");
 register int spawnIndex __asm__("$20");
 register int spawnOffset __asm__("$19");
 register unsigned char* player21 __asm__("$22");
 register int matrixParticleIndex __asm__("$17");
 register void* matrix21 __asm__("$19");

 register int* vector16 __asm__("$16");
 register int work2 __asm__("$2");register int work3 __asm__("$3");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 void* spawned146;void* spawned1E2;unsigned char* linked;
 register unsigned short* list __asm__("$4");register unsigned int selector __asm__("$5");
 register unsigned char* pool7 __asm__("$7");register int mode6 __asm__("$6");int kind;
 __asm__("" : "=r"(owner):"0"(owner));
 state=K38Field(owner,unsigned char**,0);
 __asm__("" : "=r"(state):"0"(state):"$2","$3","$4","$5");
 work3=K38Field(state,int*,12);
 if(work3!=-1 && K38Field(owner,int*,24))K38Notify(owner[0x43],1);
 work3=K38Field(state,int*,20);
 if(work3!=-1){
  linked=K38Pool+work3*88;work2=K38Field(linked,int*,0);
  __asm__("" : "=r"(work2):"0"(work2));
  if(K38Field((void*)work2,int*,0)){
   K38Field(owner,int*,24)=0;
   if(!K38Field(state,int*,24)){
    work2=(int)K38SpawnMoby(577,owner);K38Field(state,int*,24)=work2;

   }
  }else{
   call4=K38Field(state,void**,24);
   if(call4){K38func_80055B18(call4);K38Field(state,int*,24)=0;}
  }
 }
 if(K38Field(owner,int*,24) && (unsigned int)(owner[0x48]-2)>=2){
  work2=K38Field(state,int*,16)-1;K38Field(state,int*,16)=work2;
  if(work2<=0 || (K38Field(owner,int*,24)&0x180000)){
   owner[0x48]=2;K38func_8003BABC(owner,0,0);
  }
  owner[0x54]=255;owner[0x55]=255;owner[0x56]=255;owner[0x57]=63;
 }else{owner[0x54]=0;owner[0x55]=0;owner[0x56]=0;owner[0x57]=0;}
 switch(owner[0x48]){
 case 0:goto selection;
 case 1:goto timer;
 case 2:goto spawn;
 case 3:goto particles;
 default:{K38Field(owner,int*,24)=0;goto done;}
 }
 selection:
 if(!K38func_800359A4(state+4,4))goto clear;
 pool7=K38Pool;
 __asm__("" : "=r"(pool7):"0"(pool7):"$6");
 mode6=K38Mode;
 __asm__("" : "=r"(mode6):"0"(mode6):"$2","$3","$4");
 work2=K38Field(state,int*,12);
 __asm__("" : "=r"(work2):"0"(work2):"$3");
 {register unsigned short** table3 __asm__("$3")=K38Lists;
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
 __asm__ volatile("" ::: "memory");K38Field(owner,volatile int*,24)=0;goto done;
 timer:
 if(!K38func_800359A4(state+4,4))goto clear;
 K38Field(state,int*,4)=K38Field(state,int*,8);owner[0x48]=0;goto clear;
 spawn:
 if (((K38D_8006C578 - K38D_8006C574) >= 0x15) && (K38D_8006C7E8 >= 0x7531)) {
                    spawned146 = K38SpawnMoby(0x146, owner);

                    if (spawned146 != 0) {
                        K38Field(spawned146, signed char *, 0x47) = 7;

                    }
                }
                spawnIndex = 0;

                if ((K38D_8006C578 - K38D_8006C574) >= 0x15) {
                    player21=K38D_8006E020;

                    __asm__("" : "=r"(player21) : "0"(player21));

                    spawnOffset = 0;

                    loop_32:
                    if (K38D_8006C7E8 >= 0x7531) {
                        spawned21D = K38SpawnMoby(0x21D, owner);

                        if (spawned21D != 0) {
                            selectedAngle = K38func_8004E880(K38Field(owner, int *, 0xC) - K38Field(player21, int *, 0), K38Field(owner, int *, 0x10) - K38Field(player21, int *, 4), 0);

                            work2=K38rand();
                            selectedAngle+=64;

                            __asm__("" : "=r"(work2),"=r"(selectedAngle) : "0"(work2),"1"(selectedAngle));

                            work2&=31;
                            selectedAngle+=work2;
                            K38Field(spawned21D,signed char*,0x46)=selectedAngle;

                            K38Field(spawned21D, signed char *, 0x45) = (signed char) ((spawnOffset + (K38rand() & 0x1E)) - 0xF);

                            K38Field(spawned21D, signed char *, 0x47) = 8;

                            K38Field(spawned21D, signed char *, 0x4C) = 0x2A;

                        }
                        spawnIndex += 1;

                        spawnOffset += 0x33;

                        if ((spawnIndex < 5) && ((K38D_8006C578 - K38D_8006C574) >= 0x15)) {
                            goto loop_32;

                        }
                    }
                }

 __asm__("" ::: "$2");
 owner[0x41]=0;owner[0x4C]=0;owner[0x4D]=0;K38Field(state,int*,4)=20;owner[0x48]=3;

  particles:
 if(K38Field(state,int*,4)>=6){
  __asm__ volatile("" : "=r"(call4));
  matrixParticleIndex=0;matrix21=frame.matrix;vector16=frame.second;
  do {
                    frame.angles[0] = 0;

                    frame.angles[1] = K38rand();

                    frame.angles[2] = K38rand();

                    K38func_8004EA90(&frame.angles[0], matrix21, 0);

                    matrixParticleIndex++;work2=K38rand();

                    /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)frame.first;
                    call6=frame.first;

                    __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2) : "memory");

                    work2&=31;
                    work2+=48;
                    frame.first[0]=work2;

                    frame.first[1] = 0;

                    frame.first[2] = 0;

                    K38func_8004ED6C(call4,(void*)call5,call6);

                    K38func_8004F178(vector16, frame.first);



                    __asm__("" : "=r"(owner) : "0"(owner));

                    K38func_8004F194(vector16, vector16, owner + 0xC);

                    call4=(void*)1;
                    call5=20;
                    call6=vector16;


                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));



                    K38SpawnParticle((int)call4,call5,call6,frame.first);
                    K38func_8004F0E8(vector16,2);
                    K38SpawnParticle(1,20,vector16,frame.first);
                    K38func_8004F0E8(frame.first,2);
                    K38SpawnParticle(1,20,vector16,frame.first);
                    __asm__("" : "=r"(owner):"0"(owner):"$22");

                } while (matrixParticleIndex < 4);



 call4=(void*)6;call5=70;call6=owner+12;
 __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
 K38SpawnParticle((int)call4,call5,call6,(void*)16);
 }
 if(!(K38D_8006C640&1) && K38D_8006C578-K38D_8006C574>=21 && K38D_8006C7E8>=30001){
  spawned1E2=K38SpawnMoby(482,owner);
  if(spawned1E2){K38Field(spawned1E2,unsigned char*,76)=42;K38Field(spawned1E2,unsigned char*,71)=10;}
 }
 if(!K38func_800359A4(state+4,4))goto clear;
 K38H36A68(owner,1,0,0);K38H55D24(owner,4);K38H3BA00(owner);K38H369B8(owner,48);K38func_80055B18(owner);goto done;
 activate:
 K38func_8004F178(linked17+12,owner+12);K38H55C24(linked17);
 work2=K38Field(linked17,short*,54);
 K38Field(linked17,int*,24)=0;linked17[0x51]=0;linked17[0x48]=0;linked17[0x42]=0;
 work2=K38Field(K38Classes[work2],int*,60);
 call4=linked17;work2=K38Field((void*)work2,unsigned char*,0);
 selectedAngle=1;
 linked17[0x3C]=0;linked17[0x3D]=0;linked17[0x3E]=0;linked17[0x3F]=selectedAngle;
 linked17[0x44]=0;linked17[0x45]=0;
 work2=(unsigned int)work2<2;
 __asm__("" : "=r"(work2):"0"(work2));
 work2^=1;work2=-work2;work2&=48;linked17[0x40]=work2;
 work2=K38Field(linked17,int*,20);work3=owner[0x46];work2+=512;K38Field(linked17,int*,20)=work2;
 linked17[0x46]=work3;K38H35D38(call4);K38H5629C(linked17);
 K38Field(state,int*,4)=60;
 owner[0x48]=selectedAngle;
 clear:
 K38Field(owner,int*,24)=0;
 done:__asm__ volatile("" ::: "memory");
}
#undef K38Field


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 8007EB68,440 instructions, sibling4595. Verified28 spawn/particle C
 * reused; all raw fields, branches and constants from original38.
 * Units, helper contracts and cadence unresolved; uninstalled until exact. */
#define J38Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int J38func_80018368(void*,void*) __asm__("func_80018368");

int J38func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");

int J38func_800359A4(void*,int) __asm__("func_800359A4");

int J38func_8003BABC(void*,int,int) __asm__("func_8003BABC");

int J38func_8004E880(int,int,int) __asm__("func_8004E880");

int J38func_8004EA90(void*,void*,int) __asm__("func_8004EA90");

int J38func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");

int J38func_8004F0E8(void*,int) __asm__("func_8004F0E8");

int J38func_8004F110(void*,int) __asm__("func_8004F110");

int J38func_8004F178(void*,void*) __asm__("func_8004F178");

int J38func_8004F194(void*,void*,void*) __asm__("func_8004F194");

int J38func_80055B18(void*) __asm__("func_80055B18");

int J38rand(void) __asm__("rand");

extern short J38D_800658A0[] __asm__("D_800658A0");

extern short J38D_80065920[] __asm__("D_80065920");

extern int J38D_8006C574 __asm__("D_8006C574");

extern int J38D_8006C578 __asm__("D_8006C578");

extern int J38D_8006C640 __asm__("D_8006C640");

extern int J38D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char J38D_8006E020[] __asm__("D_8006E020");

extern void *(*J38SpawnMoby)(int,void*) __asm__("SpawnMoby");

extern int (*J38SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");

extern unsigned char J38D_80070328[] __asm__("D_80070328");
int J38func_8004F334(void*,void*) __asm__("func_8004F334");

int J38H19194() __asm__("func_80019194");
int J38H4EF74() __asm__("func_8004EF74");
int J38H3636C() __asm__("func_8003636C");
extern int J38Delta __asm__("D_8006C648");
extern int J38Reflect[] __asm__("D_80071918");



extern unsigned char* J38Pool __asm__("D_8006C550");
extern unsigned short** J38Lists __asm__("D_8006C730");
extern int J38Mode __asm__("D_8006C7C4");
extern int J38Gate __asm__("D_8006C770");
int J38H55D24() __asm__("func_80055D24");
int J38H34F40() __asm__("func_80034F40");
int J38H36A68() __asm__("func_80036A68");
int J38H3BA00() __asm__("func_8003BA00");
int J38H369B8() __asm__("func_800369B8");
int J38H55C24() __asm__("func_80055C24");
int J38H34F80() __asm__("func_80034F80");
int J38H35D38() __asm__("func_80035D38");
int J38H5629C() __asm__("func_8005629C");
extern int (*J38Notify)() __asm__("unk_ovlheader_800743E0");
extern unsigned char* J38Classes[] __asm__("D_8006EE2C");
void func_level_38_80080F30(void* input){
 struct {int first[4],second[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$18")=input;
 register unsigned char* state __asm__("$21");
 register int selectedAngle __asm__("$16");
 register unsigned char* nested16 __asm__("$16");
 register unsigned char* linked17 __asm__("$17");
 register void* spawned21D __asm__("$17");
 register int spawnIndex __asm__("$20");
 register int spawnOffset __asm__("$19");
 register unsigned char* player21 __asm__("$22");
 register int matrixParticleIndex __asm__("$17");
 register void* matrix21 __asm__("$19");

 register int* vector16 __asm__("$16");
 register int work2 __asm__("$2");register int work3 __asm__("$3");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 void* spawned146;void* spawned1E2;unsigned char* linked;
 register unsigned short* list __asm__("$4");register unsigned int selector __asm__("$5");
 register unsigned char* pool7 __asm__("$7");register int mode6 __asm__("$6");int kind;
 __asm__("" : "=r"(owner):"0"(owner));
 state=J38Field(owner,unsigned char**,0);
 __asm__("" : "=r"(state):"0"(state):"$2","$3","$4","$5");
 work3=J38Field(state,int*,12);
 if(work3!=-1 && J38Field(owner,int*,24))J38Notify(owner[0x43],1);
 work3=J38Field(state,int*,20);
 if(work3!=-1){
  linked=J38Pool+work3*88;work2=J38Field(linked,int*,0);
  __asm__("" : "=r"(work2):"0"(work2));
  if(J38Field((void*)work2,int*,0)){
   J38Field(owner,int*,24)=0;
   if(!J38Field(state,int*,24)){
    work2=(int)J38SpawnMoby(577,owner);J38Field(state,int*,24)=work2;

   }
  }else{
   call4=J38Field(state,void**,24);
   if(call4){J38func_80055B18(call4);J38Field(state,int*,24)=0;}
  }
 }
 if(J38Field(owner,int*,24) && (unsigned int)(owner[0x48]-2)>=2){
  work2=J38Field(state,int*,16)-1;J38Field(state,int*,16)=work2;
  if(work2<=0 || (J38Field(owner,int*,24)&0x180000)){
   owner[0x48]=2;J38func_8003BABC(owner,0,0);
  }
  owner[0x54]=255;owner[0x55]=255;owner[0x56]=255;owner[0x57]=63;
 }else{owner[0x54]=0;owner[0x55]=0;owner[0x56]=0;owner[0x57]=0;}
 switch(owner[0x48]){
 case 0:goto selection;
 case 1:goto timer;
 case 2:goto spawn;
 case 3:goto particles;
 default:{J38Field(owner,int*,24)=0;goto done;}
 }
 selection:
 if(!J38func_800359A4(state+4,4))goto clear;
 pool7=J38Pool;
 __asm__("" : "=r"(pool7):"0"(pool7):"$6");
 mode6=J38Mode;
 __asm__("" : "=r"(mode6):"0"(mode6):"$2","$3","$4");
 work2=J38Field(state,int*,12);
 __asm__("" : "=r"(work2):"0"(work2):"$3");
 {register unsigned short** table3 __asm__("$3")=J38Lists;
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
 __asm__ volatile("" ::: "memory");J38Field(owner,volatile int*,24)=0;goto done;
 timer:
 if(!J38func_800359A4(state+4,4))goto clear;
 J38Field(state,int*,4)=J38Field(state,int*,8);owner[0x48]=0;goto clear;
 spawn:
 if (((J38D_8006C578 - J38D_8006C574) >= 0x15) && (J38D_8006C7E8 >= 0x7531)) {
                    spawned146 = J38SpawnMoby(0x146, owner);

                    if (spawned146 != 0) {
                        J38Field(spawned146, signed char *, 0x47) = 7;

                    }
                }
                spawnIndex = 0;

                if ((J38D_8006C578 - J38D_8006C574) >= 0x15) {
                    player21=J38D_8006E020;

                    __asm__("" : "=r"(player21) : "0"(player21));

                    spawnOffset = 0;

                    loop_32:
                    if (J38D_8006C7E8 >= 0x7531) {
                        spawned21D = J38SpawnMoby(0x21D, owner);

                        if (spawned21D != 0) {
                            selectedAngle = J38func_8004E880(J38Field(owner, int *, 0xC) - J38Field(player21, int *, 0), J38Field(owner, int *, 0x10) - J38Field(player21, int *, 4), 0);

                            work2=J38rand();
                            selectedAngle+=64;

                            __asm__("" : "=r"(work2),"=r"(selectedAngle) : "0"(work2),"1"(selectedAngle));

                            work2&=31;
                            selectedAngle+=work2;
                            J38Field(spawned21D,signed char*,0x46)=selectedAngle;

                            J38Field(spawned21D, signed char *, 0x45) = (signed char) ((spawnOffset + (J38rand() & 0x1E)) - 0xF);

                            J38Field(spawned21D, signed char *, 0x47) = 8;

                            J38Field(spawned21D, signed char *, 0x4C) = 0x2A;

                        }
                        spawnIndex += 1;

                        spawnOffset += 0x33;

                        if ((spawnIndex < 5) && ((J38D_8006C578 - J38D_8006C574) >= 0x15)) {
                            goto loop_32;

                        }
                    }
                }

 __asm__("" ::: "$2");
 owner[0x41]=0;owner[0x4C]=0;owner[0x4D]=0;J38Field(state,int*,4)=20;owner[0x48]=3;

  particles:
 if(J38Field(state,int*,4)>=6){
  __asm__ volatile("" : "=r"(call4));
  matrixParticleIndex=0;matrix21=frame.matrix;vector16=frame.second;
  do {
                    frame.angles[0] = 0;

                    frame.angles[1] = J38rand();

                    frame.angles[2] = J38rand();

                    J38func_8004EA90(&frame.angles[0], matrix21, 0);

                    matrixParticleIndex++;work2=J38rand();

                    /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)frame.first;
                    call6=frame.first;

                    __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2) : "memory");

                    work2&=31;
                    work2+=48;
                    frame.first[0]=work2;

                    frame.first[1] = 0;

                    frame.first[2] = 0;

                    J38func_8004ED6C(call4,(void*)call5,call6);

                    J38func_8004F178(vector16, frame.first);



                    __asm__("" : "=r"(owner) : "0"(owner));

                    J38func_8004F194(vector16, vector16, owner + 0xC);

                    call4=(void*)1;
                    call5=20;
                    call6=vector16;


                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));



                    J38SpawnParticle((int)call4,call5,call6,frame.first);
                    J38func_8004F0E8(vector16,2);
                    J38SpawnParticle(1,20,vector16,frame.first);
                    J38func_8004F0E8(frame.first,2);
                    J38SpawnParticle(1,20,vector16,frame.first);
                    __asm__("" : "=r"(owner):"0"(owner):"$22");

                } while (matrixParticleIndex < 4);



 call4=(void*)6;call5=70;call6=owner+12;
 __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
 J38SpawnParticle((int)call4,call5,call6,(void*)16);
 }
 if(!(J38D_8006C640&1) && J38D_8006C578-J38D_8006C574>=21 && J38D_8006C7E8>=30001){
  spawned1E2=J38SpawnMoby(482,owner);
  if(spawned1E2){J38Field(spawned1E2,unsigned char*,76)=42;J38Field(spawned1E2,unsigned char*,71)=10;}
 }
 if(!J38func_800359A4(state+4,4))goto clear;
 J38H36A68(owner,1,0,0);J38H55D24(owner,4);J38H3BA00(owner);J38H369B8(owner,48);J38func_80055B18(owner);goto done;
 activate:
 J38func_8004F178(linked17+12,owner+12);J38H55C24(linked17);
 work2=J38Field(linked17,short*,54);
 J38Field(linked17,int*,24)=0;linked17[0x51]=0;linked17[0x48]=0;linked17[0x42]=0;
 work2=J38Field(J38Classes[work2],int*,60);
 work2=J38Field((void*)work2,unsigned char*,0);
 selectedAngle=1;
 linked17[0x3C]=0;linked17[0x3D]=0;linked17[0x3E]=0;linked17[0x3F]=selectedAngle;
 linked17[0x44]=0;linked17[0x45]=0;
 work2=(unsigned int)work2<2;
 __asm__("" : "=r"(work2):"0"(work2));
 work2^=1;work2=-work2;work2&=48;linked17[0x40]=work2;
 linked17[0x46]=owner[0x46];J38H35D38(linked17);J38H5629C(linked17);
 J38Field(state,int*,4)=60;
 work3=J38Field(linked17,int*,0);J38Field((void*)work3,int*,16)=3;owner[0x48]=selectedAngle;
 clear:
 J38Field(owner,int*,24)=0;
 done:__asm__ volatile("" ::: "memory");
}
#undef J38Field


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * 80081610,470 instructions, sibling4602. Verified28 spawn/particle C
 * reused; all raw fields, branches and constants from original38.
 * Units, helper contracts and cadence unresolved; uninstalled until exact. */
#define M38Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int M38func_80018368(void*,void*) __asm__("func_80018368");

int M38func_8001BA30(void*,int,int,int,int,void*) __asm__("func_8001BA30");

int M38func_800359A4(void*,int) __asm__("func_800359A4");

int M38func_8003BABC(void*,int,int) __asm__("func_8003BABC");

int M38func_8004E880(int,int,int) __asm__("func_8004E880");

int M38func_8004EA90(void*,void*,int) __asm__("func_8004EA90");

int M38func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");

int M38func_8004F0E8(void*,int) __asm__("func_8004F0E8");

int M38func_8004F110(void*,int) __asm__("func_8004F110");

int M38func_8004F178(void*,void*) __asm__("func_8004F178");

int M38func_8004F194(void*,void*,void*) __asm__("func_8004F194");

int M38func_80055B18(void*) __asm__("func_80055B18");

int M38rand(void) __asm__("rand");

extern short M38D_800658A0[] __asm__("D_800658A0");

extern short M38D_80065920[] __asm__("D_80065920");

extern int M38D_8006C574 __asm__("D_8006C574");

extern int M38D_8006C578 __asm__("D_8006C578");

extern int M38D_8006C640 __asm__("D_8006C640");

extern int M38D_8006C7E8 __asm__("D_8006C7E8");

extern unsigned char M38D_8006E020[] __asm__("D_8006E020");

extern void *(*M38SpawnMoby)(int,void*) __asm__("SpawnMoby");

extern int (*M38SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");

extern unsigned char M38D_80070328[] __asm__("D_80070328");
int M38func_8004F334(void*,void*) __asm__("func_8004F334");

int M38H19194() __asm__("func_80019194");
int M38H4EF74() __asm__("func_8004EF74");
int M38H3636C() __asm__("func_8003636C");
extern int M38Delta __asm__("D_8006C648");
extern int M38Reflect[] __asm__("D_80071918");



extern unsigned char* M38Pool __asm__("D_8006C550");
extern unsigned short** M38Lists __asm__("D_8006C730");
extern int M38Mode __asm__("D_8006C7C4");
extern int M38Gate __asm__("D_8006C770");
int M38H55D24() __asm__("func_80055D24");
int M38H34F40() __asm__("func_80034F40");
int M38H36A68() __asm__("func_80036A68");
int M38H3BA00() __asm__("func_8003BA00");
int M38H369B8() __asm__("func_800369B8");
int M38H55C24() __asm__("func_80055C24");
int M38H34F80() __asm__("func_80034F80");
int M38H35D38() __asm__("func_80035D38");
int M38H5629C() __asm__("func_8005629C");
extern int (*M38Notify)() __asm__("unk_ovlheader_800743E0");
extern unsigned char* M38Classes[] __asm__("D_8006EE2C");
void func_level_38_80081610(void* input){
 struct {int first[4],second[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$18")=input;
 register unsigned char* state __asm__("$21");
 register int selectedAngle __asm__("$16");
 register unsigned char* nested16 __asm__("$16");
 register unsigned char* linked17 __asm__("$17");
 register void* spawned21D __asm__("$17");
 register int spawnIndex __asm__("$20");
 register int spawnOffset __asm__("$19");
 register unsigned char* player21 __asm__("$22");
 register int matrixParticleIndex __asm__("$17");
 register void* matrix21 __asm__("$19");

 register int* vector16 __asm__("$16");
 register int work2 __asm__("$2");register int work3 __asm__("$3");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 void* spawned146;void* spawned1E2;unsigned char* linked;
 register unsigned short* list __asm__("$6");
 register unsigned char* selected4 __asm__("$4");
 register unsigned char* cursor4 __asm__("$4");
 register int count5 __asm__("$5");register int valid7 __asm__("$7");
 register int minus10 __asm__("$10");register int constant9 __asm__("$9");
 register unsigned char* pool8 __asm__("$8");int kind;
 __asm__("" : "=r"(owner):"0"(owner));
 state=M38Field(owner,unsigned char**,0);
 __asm__("" : "=r"(state):"0"(state):"$2","$3","$4","$5");
 work3=M38Field(state,int*,12);
 if(work3!=-1 && M38Field(owner,int*,24))M38Notify(owner[0x43],1);
 work3=M38Field(state,int*,20);
 if(work3!=-1){
  linked=M38Pool+work3*88;work2=M38Field(linked,int*,0);
  __asm__("" : "=r"(work2):"0"(work2));
  if(M38Field((void*)work2,int*,0)){
   M38Field(owner,int*,24)=0;
   if(!M38Field(state,int*,24)){
    work2=(int)M38SpawnMoby(577,owner);M38Field(state,int*,24)=work2;

   }
  }else{
   call4=M38Field(state,void**,24);
   if(call4){M38func_80055B18(call4);M38Field(state,int*,24)=0;}
  }
 }
 if(M38Field(owner,int*,24) && (unsigned int)(owner[0x48]-2)>=2){
  work2=M38Field(state,int*,16)-1;M38Field(state,int*,16)=work2;
  if(work2<=0 || (M38Field(owner,int*,24)&0x180000)){
   owner[0x48]=2;M38func_8003BABC(owner,0,0);
  }
  owner[0x54]=255;owner[0x55]=255;owner[0x56]=255;owner[0x57]=63;
 }else{owner[0x54]=0;owner[0x55]=0;owner[0x56]=0;owner[0x57]=0;}
 switch(owner[0x48]){
 case 0:goto selection;
 case 1:goto timer;
 case 2:goto spawn;
 case 3:goto particles;
 default:{M38Field(owner,int*,24)=0;goto done;}
 }
 selection:
 work2=M38func_800359A4(state+4,4);minus10=-1;

 if(!work2)goto clear;
 constant9=42;pool8=M38Pool;
 __asm__("" : "=r"(pool8),"=r"(constant9):"0"(pool8),"1"(constant9):"$2","$3");
 work2=M38Field(state,int*,12);
 __asm__("" : "=r"(work2):"0"(work2):"$3");
 {register unsigned short** table3 __asm__("$3")=M38Lists;
 __asm__("" : "=r"(table3),"=r"(work2):"0"(table3),"1"(work2));list=table3[work2];}
 do{
  work2=*list;work2&=32767;work3=work2*11;
  __asm__("" : "=r"(work3):"0"(work3));
  work3<<=3;__asm__("" : "=r"(work3):"0"(work3));
  selected4=(unsigned char*)(work3+(int)pool8);
  __asm__("" : "=r"(selected4):"0"(selected4));
  if(selected4[0x48]&128){
   work2=selected4[0x53];work3=M38Mode;
   if((work2>>work3)&1){
    valid7=1;count5=0;
    __asm__("" : "=r"(count5):"0"(count5));linked17=selected4;cursor4=M38Field(linked17,unsigned char**,0);
    do{
     work3=M38Field(cursor4,int*,52);
     __asm__ volatile("" : "=r"(work3):"0"(work3));
     if(work3==minus10)goto invalid_link;
     work2=pool8[work3*88+72];
     if(work2!=constant9 && work2!=0){
      invalid_link:valid7=0;break;
     }
     count5++;cursor4+=4;
    }while(count5<3);
    if(valid7)goto activate;
   }
  }
  work2=*(short*)list;list++;
 }while(work2>=0);
 __asm__ volatile("" ::: "memory");M38Field(owner,volatile int*,24)=0;goto done;
 timer:
 if(!M38func_800359A4(state+4,4))goto clear;
 M38Field(state,int*,4)=M38Field(state,int*,8)*2;owner[0x48]=0;goto clear;
 spawn:
 if (((M38D_8006C578 - M38D_8006C574) >= 0x15) && (M38D_8006C7E8 >= 0x7531)) {
                    spawned146 = M38SpawnMoby(0x146, owner);

                    if (spawned146 != 0) {
                        M38Field(spawned146, signed char *, 0x47) = 7;

                    }
                }
                spawnIndex = 0;

                if ((M38D_8006C578 - M38D_8006C574) >= 0x15) {
                    player21=M38D_8006E020;

                    __asm__("" : "=r"(player21) : "0"(player21));

                    spawnOffset = 0;

                    loop_32:
                    if (M38D_8006C7E8 >= 0x7531) {
                        spawned21D = M38SpawnMoby(0x21D, owner);

                        if (spawned21D != 0) {
                            selectedAngle = M38func_8004E880(M38Field(owner, int *, 0xC) - M38Field(player21, int *, 0), M38Field(owner, int *, 0x10) - M38Field(player21, int *, 4), 0);

                            work2=M38rand();
                            selectedAngle+=64;

                            __asm__("" : "=r"(work2),"=r"(selectedAngle) : "0"(work2),"1"(selectedAngle));

                            work2&=31;
                            selectedAngle+=work2;
                            M38Field(spawned21D,signed char*,0x46)=selectedAngle;

                            M38Field(spawned21D, signed char *, 0x45) = (signed char) ((spawnOffset + (M38rand() & 0x1E)) - 0xF);

                            M38Field(spawned21D, signed char *, 0x47) = 8;

                            M38Field(spawned21D, signed char *, 0x4C) = 0x2A;

                        }
                        spawnIndex += 1;

                        spawnOffset += 0x33;

                        if ((spawnIndex < 5) && ((M38D_8006C578 - M38D_8006C574) >= 0x15)) {
                            goto loop_32;

                        }
                    }
                }

 __asm__("" ::: "$2");
 owner[0x41]=0;owner[0x4C]=0;owner[0x4D]=0;M38Field(state,int*,4)=20;owner[0x48]=3;

  particles:
 if(M38Field(state,int*,4)>=6){
  __asm__ volatile("" : "=r"(call4));
  matrixParticleIndex=0;matrix21=frame.matrix;vector16=frame.second;
  do {
                    frame.angles[0] = 0;

                    frame.angles[1] = M38rand();

                    frame.angles[2] = M38rand();

                    M38func_8004EA90(&frame.angles[0], matrix21, 0);

                    matrixParticleIndex++;work2=M38rand();

                    /* Preserve the original rand call delay slot; GCC 2.7 fills an empty constraint with the next move. */
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)frame.first;
                    call6=frame.first;

                    __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2) : "memory");

                    work2&=31;
                    work2+=48;
                    frame.first[0]=work2;

                    frame.first[1] = 0;

                    frame.first[2] = 0;

                    M38func_8004ED6C(call4,(void*)call5,call6);

                    M38func_8004F178(vector16, frame.first);



                    __asm__("" : "=r"(owner) : "0"(owner));

                    M38func_8004F194(vector16, vector16, owner + 0xC);

                    call4=(void*)1;
                    call5=20;
                    call6=vector16;


                    __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6) : "0"(call4),"1"(call5),"2"(call6));



                    M38SpawnParticle((int)call4,call5,call6,frame.first);
                    M38func_8004F0E8(vector16,2);
                    M38SpawnParticle(1,20,vector16,frame.first);
                    M38func_8004F0E8(frame.first,2);
                    M38SpawnParticle(1,20,vector16,frame.first);
                    __asm__("" : "=r"(owner):"0"(owner):"$22");

                } while (matrixParticleIndex < 4);



 call4=(void*)6;call5=70;call6=owner+12;
 __asm__("" : "=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
 M38SpawnParticle((int)call4,call5,call6,(void*)16);
 }
 if(!(M38D_8006C640&1) && M38D_8006C578-M38D_8006C574>=21 && M38D_8006C7E8>=30001){
  spawned1E2=M38SpawnMoby(482,owner);
  if(spawned1E2){M38Field(spawned1E2,unsigned char*,76)=42;M38Field(spawned1E2,unsigned char*,71)=10;}
 }
 if(!M38func_800359A4(state+4,4))goto clear;
 M38H36A68(owner,1,0,0);M38H55D24(owner,4);M38H3BA00(owner);M38H369B8(owner,48);M38func_80055B18(owner);goto done;
 activate:
 M38func_8004F178(linked17+12,owner+12);M38H55C24(linked17);
 work2=M38Field(linked17,short*,54);
 M38Field(linked17,int*,24)=0;linked17[0x51]=0;linked17[0x48]=0;linked17[0x42]=0;
 work2=M38Field(M38Classes[work2],int*,60);
 call4=linked17;work2=M38Field((void*)work2,unsigned char*,0);
 selectedAngle=1;
 linked17[0x3C]=0;linked17[0x3D]=0;linked17[0x3E]=0;linked17[0x3F]=selectedAngle;
 linked17[0x44]=0;linked17[0x45]=0;
 work2=(unsigned int)work2<2;
 __asm__("" : "=r"(work2):"0"(work2));
 work2^=1;work2=-work2;work2&=48;linked17[0x40]=work2;
 work2=M38Field(linked17,int*,20);work3=owner[0x46];work2+=512;M38Field(linked17,int*,20)=work2;
 linked17[0x46]=work3;M38H35D38(call4);M38H5629C(linked17);
 M38Field(state,int*,4)=60;
 owner[0x48]=selectedAngle;
 clear:
 M38Field(owner,int*,24)=0;
 done:__asm__ volatile("" ::: "memory");
}
#undef M38Field


/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 80081D68..8008202C,178 original words; Rev1 raw655 source-local routes.
 * Rev0 SLL1 uses a TWO-byte halfword-table stride; Rev1's descriptive
 * eight-byte stride is not reused. Raw units/table/helper producers and
 * caller cadence remain open. Test: original linked words/full hashes. */
extern unsigned char DecodedStarfishPlayer[] __asm__("D_80070328");
extern int DecodedStarfishFlags __asm__("D_80070328+0x24");
extern Moby* DecodedStarfishTarget __asm__("D_80071930");
extern int (*DecodedStarfishHeading)(unsigned char*,Vector3D*,Vector3D*) __asm__("unk_ovlheader_800743C4");
extern short D_80065920[],D_800658A0[];
int rand(void);
int func_80035030(Moby*,void*,int,void*,int,int,int,int);
void func_level_38_80081D68(Moby* argument) {
    Vector3D vector;
    int reserved2C;
    register Moby* moby __asm__("$16") = argument;
    register int* tag __asm__("$18");
    register int state __asm__("$17");
    register int heading __asm__("$2");
    int distance;
    tag = moby->mobyTag;
    /* Retail prepares a fresh owner argument; the clobber emits no code. */
    __asm__("" : : : "$4");
    if (moby->state == 0 || moby->state == 42) goto reset;
    { register Moby* modeOwner __asm__("$4") = moby;
    __asm__("" : "=r"(modeOwner) : "0"(modeOwner));
    func_80055D24(modeOwner,5);
    }
    if (*(int*)((unsigned char*)moby+0x18) && moby->state != 2) {
        moby->state = 2;
        *(int*)((unsigned char*)moby+8) = 0;
        func_8003BABC(moby,0,0);
    }
    distance = func_8004F334(&moby->position,(Vector3D*)DecodedStarfishPlayer);
    if (moby->state != 2 && distance < 1024) {
        DecodedStarfishFlags |= 1;
        moby->state = 2;
    }
    state = moby->state;
    switch (state) {
    case 1:
        if (func_80035DDC(moby,160,896,896,35) & 32) {
            heading = func_8004E880(moby->position.x - DecodedStarfishTarget->position.x,
                moby->position.y - DecodedStarfishTarget->position.y,0);
        } else {
            heading = DecodedStarfishHeading(&moby->substate,&moby->position,(Vector3D*)DecodedStarfishPlayer);
        }
        func_8003585C(moby,heading & 255,10,0,1,0);
        break;
    case 2:
        {
            register int index __asm__("$17") = 0;
            register int selector __asm__("$18") = rand();
            register short* cosine __asm__("$20") = D_80065920;
            register Vector3D* position __asm__("$19") = &moby->position;
            do {
                register int kind __asm__("$4") = 1;
                register int code __asm__("$5") = 20;
                register int byteOffset __asm__("$3");
                register int sample __asm__("$2");
                register Vector3D* positionArgument __asm__("$6");
                register Vector3D* vectorArgument __asm__("$7");
                register char* (*spawn)(int,int,Vector3D*,Vector3D*) __asm__("$3");
                /* Instruction-free ties retain signed samples and argument
                 * preparation before the original callback/stack writes. */
                __asm__("" : "=r"(kind), "=r"(code) : "0"(kind), "1"(code));
                byteOffset = (selector & 255) * 2;
                __asm__("" : "=r"(byteOffset) : "0"(byteOffset));
                sample = *(short*)(byteOffset + (unsigned int)cosine);
                __asm__("" : "=r"(sample) : "0"(sample));
                positionArgument = position;
                __asm__("" : "=r"(positionArgument) : "0"(positionArgument));
                vector.x = sample >> 7;
                sample = *(short*)((char*)D_800658A0 + byteOffset);
                spawn = SpawnParticle;
                __asm__("" : "=r"(sample), "=r"(spawn) : "0"(sample), "1"(spawn));
                vectorArgument = &vector;
                __asm__("" : "=r"(vectorArgument) : "0"(vectorArgument));
                vector.z = 0;
                __asm__ volatile ("" : : : "memory");
                vector.y = sample >> 7;
                spawn(kind,code,positionArgument,vectorArgument);
                if (index & 1) {
                    func_8004F110(&vector,1);
                    SpawnParticle(1,20,position,&vector);
                }
                index++;
                selector += 32;
            } while ((unsigned char)index < 8);
        }
reset:
        __asm__ volatile ("" : : : "memory");
        *(int*)((unsigned char*)moby+8) = 0;
        moby->unknown3[0] = 0;
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
        moby->state = 42;
        break;
    case 3:
        if (func_80035030(moby,tag+3,tag[1],tag+2,8,16,512,35) == state) {
            moby->state = 1;
            func_80034F40(moby,1);
        }
        break;
    }
}

typedef struct { short mode, parentClass; int offsetZ; Moby* parent; } DecodedParentFollowRecord;
extern unsigned short D_8006E040, D_8006E03E;
void func_80055B18(Moby*);
void func_80055F14(Moby*, int, Vector3D*);
void func_level_38_80082030(Moby* moby) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
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

extern unsigned char Actor81438D_80070328[] __asm__("D_80070328");
int Actor81438func_8004F334(void*,void*) __asm__("func_8004F334");
void func_level_38_80082120(void *input) {
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
            __asm__ __volatile__("" ::: "$3");

            if ((Actor81438func_8004F334(ownerPosition,Actor81438D_80070328)<0x400) || (Actor81438func_80018368(&frame.sp18, ownerPosition) != 0)) {
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
                Actor81438func_8003BABC(owner, 0, 0);
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

                Actor81438Field(owner, unsigned char *, 0x48) = 2U;

                return;

            }
            break;

            case 2:
            if (Actor81438func_800359A4(state + 0xC, 4) != 0) {
                if(Actor81438func_8004F334(ownerPosition,Actor81438D_80070328)<0x800) {
                    Actor81438Field(Actor81438D_80070328,int*,0x24)|=1;
                }

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
                    __asm__ __volatile__("" : "=r"(work2) : "0"(work2) : "$4", "$5", "$6");

                    call4=matrix21;
                    call5=(int)vector17;
                    call6=vector17;

                    __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2) : "0"(call4),"1"(call5),"2"(call6),"3"(work2) : "memory");

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

int func_8004F334(Vector3D*, Vector3D*);
void func_80055B18(Moby*);
void func_level_38_80082780(Moby* moby) {
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

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008280C.
 * Original280 instructions and six dispatch words: sibling4743.
 * Raw units, helper meanings and cadence unresolved; native/hash gates required. */
#define F38Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
typedef struct { unsigned char bytes[88]; } F38Entry;
extern unsigned char* F38Pool __asm__("D_8006C550");
extern unsigned char* F38End __asm__("D_8006C704");
extern unsigned char F38Player[] __asm__("D_80070328");
extern unsigned char F38Table[] __asm__("D_8006C7F8");
int F38H36220() __asm__("func_80036220");
int F38H21F3C() __asm__("func_80021F3C");
int F38H21ED8() __asm__("func_80021ED8");
int F38H21F8C() __asm__("func_80021F8C");
int F38H3BB10() __asm__("func_8003BB10");
int F38H3B7B4() __asm__("func_8003B7B4");
void func_level_38_8008280C(void* input){
 register unsigned char* owner __asm__("$18")=input;
 register unsigned char* tag __asm__("$19");
 register int linkedFlag __asm__("$20");
 register unsigned char* scan __asm__("$16");
 register unsigned char* kindPointer __asm__("$17");
 register int kindValue __asm__("$22");
 register int four __asm__("$21");
 register int index __asm__("$23");
 register int value __asm__("$2");register int other __asm__("$3");
 register void* call4 __asm__("$4");register unsigned char* pool5 __asm__("$5")=F38Pool;
 register void* arg5 __asm__("$5");
 __asm__("" : : "r"(owner):"$20");tag=F38Field(owner,unsigned char**,0);
 call4=(void*)(owner-pool5);value=((unsigned)call4<<5)-(unsigned)call4;
 value=((unsigned)value<<5)+(unsigned)call4;other=(unsigned)value<<3;value+=other;
 other=((unsigned)value<<15)-(unsigned)value;other=((unsigned)other<<2)+(unsigned)call4;
 other=-(unsigned)other;index=other>>3;__asm__("" : : "r"(index));
 other=F38Field(tag,int*,52);__asm__("" : "=r"(other):"0"(other):"$20");linkedFlag=0;
 if(other!=-1){value=pool5[other*88+72];linkedFlag=value&128;}
 value=owner[72];if(!value)goto dispatch;
 value=(unsigned)pool5<(unsigned)F38End;scan=pool5;if(!value)goto dispatch;
 kindValue=655;four=4;kindPointer=scan+54;__asm__("" : "=r"(kindValue),"=r"(four):"0"(kindValue),"1"(four));
 scan_loop:
 other=F38Field(kindPointer,short*,0);
 if(other==557)goto scan_selected;
 value=other<558;if(!value)goto high_kind;
 value=other<552;if(!value)goto scan_next;
 value=other<550;if(!value)goto scan_selected;goto scan_next;
 high_kind:
 value=other<624;if(value)goto scan_next;
 value=other<627;if(value)goto scan_selected;
 if(other!=kindValue)goto scan_next;
 scan_selected:
 value=F38Field(scan,int*,0);call4=scan+12;if(!value)goto scan_next;
 value=F38H36220(call4,tag+4,0,0);
 if(value){value=owner[72];if(value==four)goto invalidate;other=owner[73];value=2;if(other!=value)goto scan_owner;
 invalidate:
 other=F38Field(scan,int*,0);value=-1;F38Field((void*)other,int*,0)=value;
 }
 scan_owner:
 value=F38Field(scan,int*,0);value=F38Field((void*)value,int*,0);if(value!=index)goto scan_next;
 other=kindPointer[18];value=other&128;if(value)goto scan_next;
 value=F38Field(kindPointer,short*,0);__asm__("" : "=r"(other):"0"(other));other&=255;if(value==kindValue && other==42)goto scan_next;
 value=owner[73];if(value==four)goto scan_next;if(!linkedFlag)goto done;
 scan_next:
 value=(int)F38End;scan+=88;value=(unsigned)scan<(unsigned)value;kindPointer+=88;if(value)goto scan_loop;
 dispatch:
 other=owner[72];switch(other){
 case 1:
  value=F38H21F3C(F38Field(tag,void**,0));other=value&255;value=2;
  if(other==value){other=owner[73];value=3;if(other==value){value=4;goto store_state;}}
  scan=F38Player;value=F38H36220(scan,tag+4,0,0);
  if(value){other=owner[73];value=3;call4=owner;if(other==value)goto react;arg5=0;if(!other)goto react_call;}
  call4=owner;if(!linkedFlag)goto second_query;
 react:
  arg5=0;
 react_call:
  F38H3BB10(call4,arg5,0);value=2;goto store_state;
 second_query:
  __asm__("" : "=r"(linkedFlag):"0"(linkedFlag):"$6","$7");value=F38H36220(scan,tag+28,0,0);if(!value)goto done;
  other=owner[73];value=2;call4=owner;if(other!=value)goto done;
  __asm__("" ::: "$5","$6");F38H3BB10(call4,0,0);
  call4=owner+72;arg5=(void*)1;__asm__("" : "=r"(arg5):"0"(arg5));scan=F38Table;__asm__("" : "=r"(scan):"0"(scan):"$17");{register void* arg6 __asm__("$6")=scan;__asm__("" : "=r"(arg6):"0"(arg6):"$17");kindPointer=(void*)3;owner[72]=(int)kindPointer;
  F38H3B7B4(call4,arg5,arg6);}call4=owner+73;arg5=(void*)1;owner[73]=4;F38H3B7B4(call4,arg5,scan);owner[73]=(int)kindPointer;goto done;
 case 2:
  value=F38H21F3C(F38Field(tag,void**,0));other=value&255;value=2;arg5=tag+4;
  if(other==value){F38H21ED8(F38Field(tag,void**,0),252,0);value=5;if(!linkedFlag)goto resume;owner[72]=value;goto done;}
  value=F38H36220(F38Player,arg5,0,0);if(!value)goto done;
  value=F38H21F3C(F38Field(tag,void**,0));value>>=8;arg5=(void*)(value&255);value=62;arg5=(void*)(value-(int)arg5);value=(int)arg5<60;if(!value)arg5=(void*)59;
  F38H21F8C(F38Field(tag,void**,0),arg5,0);value=5;if(linkedFlag)goto store_state;
 resume:
  value=1;owner[72]=value;value=2;owner[73]=value;goto done;
 case 0:case 3:
  value=F38H21F3C(F38Field(tag,void**,0));value&=255;other=2;arg5=(void*)252;if(value!=other)goto done;
  F38H21ED8(F38Field(tag,void**,0),arg5,0);other=owner[73];value=4;if(!other || other==value)F38H21F8C(F38Field(tag,void**,0),29,0);
  other=owner[72];value=1;owner[72]=value;owner[73]=other;goto done;
 case 5:goto done;
 case 4:
  value=2;if(!linkedFlag)goto done;goto store_state;
 default:goto done;
 }
 store_state:
 owner[72]=value;
 done:;
}
#undef F38Field
