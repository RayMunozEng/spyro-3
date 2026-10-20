#include "common.h"
#include "spu.h"
#include "spyro.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "moby/mobytag.h"
#include "mobyutil.h"
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
void func_level_25_80074CE0(void *input) {
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
void func_level_25_8007593C(void *input) {
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
void func_level_25_80076E8C(Moby* moby) {
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
void func_level_25_80076FC8(Moby* moby) {
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
void func_level_25_80077084(Moby* moby) {
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
void func_level_25_80077138(Moby *moby) {
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
void func_level_25_8007743C(void *input) {
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
void func_level_25_80077FB0(Moby* moby) {
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
void func_level_25_800780F0(void *input) {
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


#define Controller7A1FCField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char Controller7A1FCCameraBytes[] __asm__("D_8006FA40");
extern unsigned char Controller7A1FCPlayer[] __asm__("D_80070328");
extern unsigned char Controller7A1FCContext[] __asm__("D_8006D088");
extern unsigned char Controller7A1FCSin[] __asm__("D_800658A0"), Controller7A1FCCos[] __asm__("D_80065920");
extern int Controller7A1FCD_8006586C __asm__("D_8006586C");
extern int Controller7A1FCD_8006E344 __asm__("D_8006E344");
extern int Controller7A1FCD_8006FA3C __asm__("D_8006FA3C");
extern int Controller7A1FCD_8006FA40 __asm__("D_8006FA40");
extern int Controller7A1FCD_8006FA54 __asm__("D_8006FA54");
extern unsigned char Controller7A1FCD_8006C62C __asm__("D_8006C62C");
extern unsigned char Controller7A1FCD_8006C7B4 __asm__("D_8006C7B4");
void* Controller7A1FCHelper2EC50(int,int,int) __asm__("func_8002EC50");
int Controller7A1FCHelper3573C(void*,int,int,int) __asm__("func_8003573C");
int Controller7A1FCHelper3585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Controller7A1FCHelper35DDC(void*,int,int,int,int) __asm__("func_80035DDC");
int Controller7A1FCHelper3B74C(void*) __asm__("func_8003B74C");
int Controller7A1FCHelper4E880(int,int,int) __asm__("func_8004E880");
int Controller7A1FCHelper4F178(void*,int) __asm__("func_8004F178");
int Controller7A1FCHelper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller7A1FCHelper4F1C8(void*,int,int) __asm__("func_8004F1C8");
int Controller7A1FCHelper4F334(void*,void*) __asm__("func_8004F334");
int Controller7A1FCHelper512E4(void*,int,int) __asm__("func_800512E4");
int Controller7A1FCHelper53F50(int,int) __asm__("func_80053F50");
int Controller7A1FCHelper55B18(void*) __asm__("func_80055B18");
int Controller7A1FCHelper55D24(void*,int) __asm__("func_80055D24");
int Controller7A1FCHelper55F14(void*,int,void*) __asm__("func_80055F14");
extern int (*Controller7A1FCParticle)(int,int,void*,int) __asm__("SpawnParticle");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Evidence: level15/8007A1FC, level25/80078580, level35/80078C58 and
 * level45/80078CDC, original moby text. All four copies have 308 original
 * instructions, equal original helper/global symbols and no owned table rows.
 * Three stack vectors retain offsets 0x18/0x28/0x38. Preserve resource creation,
 * paired particle callback sequences and signed z averages, flag-bit checks,
 * signed table products (39 >> 6 and 13 >> 5), nested state paths, six-argument
 * helper stack slots, tag/record pointer rereads and camera-mode producers.
 * Helper semantics, vector coordinate domains, fixed-point meanings and caller
 * cadence remain unresolved; updates below are once per invocation.
 * Confidence: exact native/linked original words and complete retail SHA set.
 * Falsifiable vectors: every original instruction and EXE/all-overlay hashes.
 * Empty constraints preserve original scheduling without opcode patches.
 */
void func_level_25_80078580(void* input) {
    register unsigned char *owner __asm__("$16")=input;
    struct { Vector3D first; int padding24; Vector3D second; int padding34;
             Vector3D third; int padding44; } frame;
    void *resource;
    int wideTableOffset;
    int narrowTableOffset;
    int firstRecordAddress;
    int secondRecordAddress;
    int deltaX;
    int deltaY;
    int var_v0;
    int var_v0_2;
    int offsetY;
    register int selectedMode __asm__("$5");
    register int state __asm__("$3");
    register int substate __asm__("$3");
    register unsigned char *tag __asm__("$17");

    tag = Controller7A1FCField(owner, void **, 0);
    { register void* resource __asm__("$2")=Controller7A1FCField(tag,void**,0x38);
      __asm__("" : "=r"(resource) : "0"(resource) : "$4");
    if(resource==0) {
        Controller7A1FCField(tag, void **, 0x38) = Controller7A1FCHelper2EC50(1, 0x80, 0x489090);
        Controller7A1FCField(owner, int *, 0x54) = (int) Controller7A1FCD_8006586C;
    } else {
        Controller7A1FCHelper55F14(owner, 1, &frame.first);
        frame.first.z = (int) (frame.first.z + Controller7A1FCField(owner, int *, 0x14)) >> 1;
        Controller7A1FCParticle(2, 0x42, &frame.first, 0);
        Controller7A1FCHelper55F14(owner, 2, &frame.first);
        frame.first.z = (int) (frame.first.z + Controller7A1FCField(owner, int *, 0x14)) >> 1;
        Controller7A1FCParticle(2, 0x42, &frame.first, 0);
        Controller7A1FCField(Controller7A1FCField(tag, void **, 0x38), signed char *, 0x10) = 1;
        Controller7A1FCHelper55F14(owner, 0, Controller7A1FCField(tag, void **, 0x38));
    }
    }
    state = Controller7A1FCField(owner, unsigned char *, 0x48);
    __asm__("" : "=r"(state) : "0"(state));
    switch (state) {
    case 0:
        if (Controller7A1FCD_8006FA3C == 0) {
            { register int mask __asm__("$4")=0x10000000;
              register int *flags __asm__("$3");
              register int previous __asm__("$2");
              __asm__("" : "=r"(mask) : "0"(mask));
              flags=(int*)(Controller7A1FCPlayer+0x20C);
              previous=*flags;
              mask|=2;
              *flags=previous|mask; }
            substate = Controller7A1FCField(owner, unsigned char *, 0x49);
            __asm__("" : "=r"(substate) : "0"(substate));
            switch (substate) {
            case 0:
                { register int flags __asm__("$3")=Controller7A1FCD_8006C7B4;
                  register int predicate __asm__("$2");
                  __asm__("" : "=r"(flags) : "0"(flags));
                  if(flags&1) {
                      if(!(Controller7A1FCD_8006C62C&1)) goto wideOffset;
                  }
                  predicate=flags&2;
                  if(predicate) {
                      if(!(Controller7A1FCD_8006C62C&2)) goto wideOffset;
                  }
                  predicate=flags&4;
                  if(predicate && !(Controller7A1FCD_8006C62C&4)) {
wideOffset:
                    wideTableOffset = Controller7A1FCField(&Controller7A1FCPlayer, unsigned char *, 0xE) * 2;
                    frame.second.x = (int) (*(short*)(Controller7A1FCCos + wideTableOffset) * 0x27) >> 6;
                    { register int sample __asm__("$3")=*(short*)(Controller7A1FCSin+wideTableOffset);
                    __asm__("" : "=r"(sample) : "0"(sample) : "memory");
                    frame.second.z=0;
                    __asm__ volatile("" : : : "memory");
                    offsetY=(sample*0x27)>>6; }
                } else {
                    narrowTableOffset = Controller7A1FCField(&Controller7A1FCPlayer, unsigned char *, 0xE) * 2;
                    frame.second.x = (int) (*(short*)(Controller7A1FCCos + narrowTableOffset) * 0xD) >> 5;
                    { register int sample __asm__("$3")=*(short*)(Controller7A1FCSin+narrowTableOffset);
                    __asm__("" : "=r"(sample) : "0"(sample) : "memory");
                    frame.second.z=0;
                    __asm__ volatile("" : : : "memory");
                    offsetY=(sample*0xD)>>5; }
                }
                }
                frame.second.y = offsetY;
                __asm__ volatile("" : : : "memory");
                Controller7A1FCHelper4F194(&frame.second, &Controller7A1FCPlayer, &frame.second);
                if (Controller7A1FCHelper3585C(owner, Controller7A1FCHelper4E880(frame.second.x - Controller7A1FCField(owner, int *, 0xC), frame.second.y - Controller7A1FCField(owner, int *, 0x10), 0), 8, 0x10, 1, 0) != 0) {
                    Controller7A1FCHelper35DDC(owner, 0xC0, 0, 0, 0);
                    if (Controller7A1FCHelper4F334(&frame.second, owner + 0xC) < 0x100) {
                        Controller7A1FCField(owner, unsigned char *, 0x49) = 1U;
                    }
                }
                break;
            case 1:
                __asm__ volatile("" : : : "$3");
                if (Controller7A1FCHelper3573C(owner, 8, 4, 1) != 0) {
                    Controller7A1FCField(tag, signed char *, 5) = 1;
                    Controller7A1FCField(owner, unsigned char *, 0x49) = 2U;
                }
                break;
            case 2:
                Controller7A1FCHelper512E4(owner, 0, 0);
                Controller7A1FCField(owner, unsigned char *, 0x48) = 1U;
                break;
            }
            goto updateOwner;
        }
        resource = Controller7A1FCField(tag, void **, 0x38);
        if (resource != 0) {
            Controller7A1FCField(resource, signed char *, 0x10) = 0;
        }
        Controller7A1FCHelper55B18(owner);
        goto finished;
updateOwner:
        Controller7A1FCHelper55D24(owner,4);
        goto finished;
    case 1:
        if (Controller7A1FCD_8006E344 != state) {
            selectedMode = Controller7A1FCField(tag, unsigned char *, 4);
            if (selectedMode == state) {
                { register unsigned char* camera __asm__("$4")=Controller7A1FCCameraBytes;
                __asm__("" : "=r"(camera) : "0"(camera));
                *(int*)camera=selectedMode;
                Controller7A1FCHelper4F178(camera+8, Controller7A1FCField(Controller7A1FCField(tag, void **, 0x3C), int *, 0xC)); }
                firstRecordAddress = Controller7A1FCField(Controller7A1FCField(tag, void **, 0x3C), int *, 0xC);
                Controller7A1FCHelper4F1C8(&frame.second, firstRecordAddress + 0x10, firstRecordAddress);
                deltaX = frame.second.x;
                deltaY = frame.second.y;
                goto applyCameraResult;
            }
            if (selectedMode == 2) {
                { register unsigned char* camera __asm__("$4")=Controller7A1FCCameraBytes;
                __asm__("" : "=r"(camera) : "0"(camera));
                *(int*)camera=selectedMode;
                Controller7A1FCHelper4F178(camera+8, Controller7A1FCField(Controller7A1FCField(tag, void **, 0x40), int *, 0xC)); }
                secondRecordAddress = Controller7A1FCField(Controller7A1FCField(tag, void **, 0x40), int *, 0xC);
                Controller7A1FCHelper4F1C8(&frame.third, secondRecordAddress + 0x10, secondRecordAddress);
                deltaX = frame.third.x;
                deltaY = frame.third.y;
applyCameraResult:
                { register int angle __asm__("$2")=Controller7A1FCHelper4E880(deltaX,deltaY,0);
                  register void* context __asm__("$4")=Controller7A1FCContext;
                  __asm__("" : "=r"(context) : "0"(context) : "memory");
                  Controller7A1FCD_8006FA54=angle;
                  Controller7A1FCHelper3B74C(context); }
                return;
            }
            if (selectedMode == 3) {
                __asm__("" : "=r"(selectedMode) : "0"(selectedMode));
                Controller7A1FCHelper53F50(-1, selectedMode);
                return;
            }
            Controller7A1FCField(tag, signed char *, 5) = 1;
            Controller7A1FCField(owner, unsigned char *, 0x48) = 0U;
        } else {
            return;
        }
        break;
    }
finished:;
}

#undef Controller7A1FCField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0 func_level_25_80078A50; original assembly SHA256
 * 1e9f29831e4ac9312e0018848d454264c4c34655b11f363d496916c79529fa50. AI generated; not human
 * reviewed. Reuses the independently matched1182 family source, with target-specific native
 * branches, field widths, stack homes, helper arguments and table entries separately verified. 1265
 * native instructions; 7 selectors; 1 zero padding words. Frame 160 bytes. Descriptor
 * count/current/step are signed16; record stride16, actor stride88. Current linked signed16 entry
 * is read BEFORE cursor+2 on both scans. Path changes pass the OLD current-path index to the
 * original callback; the later player-path callback receives the full32 initialized index. The
 * signed /12 product executes before the independent timer predicate. Three complete signed64
 * products preserve original high/low projections; each empty h/l output consumes the entire
 * initialized x product, never a partial HI/LO input. Constant and low-word arithmetic retains
 * retail modulo32 and signed shift domains. Whole initialized GP/address/field metadata emits zero
 * CPU instructions; clobbers end only dead GP phases. No CPU opcode asm, fixed FP/SP, incoming
 * saved value, unwritten local read or overlapping live fixed alias is introduced. The original
 * local frame padding is declared but never read as invented behavior. Authored instances and
 * original dynamic-child constructor/state guards are audited separately in family1182 ownership
 * evidence. Helpers with unresolved meanings keep original word ABI. Units beyond raw shifts, full
 * producer/caller chains, cadence beyond per invocation, Rev1 mapping, SFX semantics and
 * synchronized runtime captures remain unresolved. Acceptance requires every native/linked word,
 * actual conditional/J/call/ table target, original data symbol/addend and all retail hashes. Full
 * linked EXE/every-overlay hashes remain pending parent integration.
 */
int Family1265TestSlot(void *, int) __asm__("func_8003BFC0");
void Family1265ClearSlot(int) __asm__("func_8003BE70");
extern int (*Family1265SpawnMoby)() __asm__("SpawnMoby");
#define Family1265Field(p, t, o) (*(t)((unsigned char *)(p) + (o)))
int Family1265_func_80019194() __asm__("func_80019194");
int Family1265_func_80034F40() __asm__("func_80034F40");
int Family1265_func_800359A4(void *, int) __asm__("func_800359A4");
int Family1265_func_80036518(void *, void *, void *) __asm__("func_80036518");
int Family1265_func_80036A68() __asm__("func_80036A68");
int Family1265_func_8003BABC(void *, int, int) __asm__("func_8003BABC");
int Family1265_func_8004E4E4(int) __asm__("func_8004E4E4");
int Family1265_func_8004ED6C() __asm__("func_8004ED6C");
int Family1265_func_8004EDE8() __asm__("func_8004EDE8");
int Family1265_func_8004F194() __asm__("func_8004F194");
int Family1265_func_8004F334(void *, void *) __asm__("func_8004F334");
int Family1265_func_80055B18() __asm__("func_80055B18");
int Family1265_func_80055D24() __asm__("func_80055D24");
int Family1265_func_80055F14() __asm__("func_80055F14");
int Family1265_rand() __asm__("rand");
extern int Family1265_D_80065920 __asm__("D_80065920");
extern int Family1265_D_8006C550 __asm__("D_8006C550");
extern int Family1265_D_8006C648 __asm__("D_8006C648");
extern int Family1265_D_8006C730 __asm__("D_8006C730");
extern int Family1265_D_8006C770 __asm__("D_8006C770");
extern int Family1265_D_8006C7C4 __asm__("D_8006C7C4");
extern int Family1265_D_8006E020 __asm__("D_8006E020");
extern int Family1265_D_8006FA3C __asm__("D_8006FA3C");
extern int Family1265_D_8006FA78 __asm__("D_8006FA78");
extern int Family1265_D_8006FA7C __asm__("D_8006FA7C");
extern int Family1265_D_8006FA80 __asm__("D_8006FA80");
extern int Family1265_D_80070328 __asm__("D_80070328");
extern int (*Family1265_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Family1265_unk_ovlheader_80074384)() __asm__("unk_ovlheader_80074384");
extern int (*Family1265_unk_ovlheader_80074398)() __asm__("unk_ovlheader_80074398");
extern int (*Family1265_unk_ovlheader_8007439C)() __asm__("unk_ovlheader_8007439C");
extern int (*Family1265_unk_ovlheader_800743A0)() __asm__("unk_ovlheader_800743A0");
extern int (*Family1265_unk_ovlheader_800743A4)() __asm__("unk_ovlheader_800743A4");
extern int (*Family1265_unk_ovlheader_800743EC)() __asm__("unk_ovlheader_800743EC");
void func_level_25_80078A50(void *input) {
    register int ownerRecord20 __asm__("$20"), privateRecord19 __asm__("$19"),
        retainedFactorCounterOrVector16 __asm__("$16"), retainedPathOrAngle17 __asm__("$17"),
        retainedVectorOrAngle18 __asm__("$18"), retainedRemainderMinimum21 __asm__("$21"),
        retainedRemainderMinimum22 __asm__("$22");
    int finalProductLow;
    long long completeFinalProduct, completeSpeedProduct, completeDivisionProduct;
    int speedProductLow, divisionProductHigh;
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        rawWord8 __asm__("$8"), rawWord9 __asm__("$9");
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C,
            sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C;
    } originalFrame;
    int signedRemainder;
    ownerRecord20 = (int)input;
    __asm__("" : "=r"(ownerRecord20) : "0"(ownerRecord20));
    privateRecord19 = Family1265Field(ownerRecord20, void **, 0);
    if (Family1265_D_8006C7C4 == 2) {
        retainedFactorCounterOrVector16 = 0x9E8;
    } else {
        retainedFactorCounterOrVector16 = 0x10;
        if (Family1265_D_8006C7C4 == 1) {
            retainedFactorCounterOrVector16 = 0x300;
        }
    }
    __asm__(""
            : "=r"(retainedRemainderMinimum21), "=r"(retainedRemainderMinimum22),
              "=m"(originalFrame.sp18));
    if (Family1265Field(privateRecord19, int *, 0x0) != 0) {
        if ((Family1265Field(ownerRecord20, int *, 0x18) != 0) &&
            (Family1265Field(ownerRecord20, unsigned char *, 0x48) != 5)) {
            if (Family1265TestSlot(ownerRecord20, Family1265Field(privateRecord19, int *, 4)))
                Family1265ClearSlot(Family1265Field(privateRecord19, int *, 4));
            Family1265Field(privateRecord19, int *, 4) = -1;
            Family1265_func_8003BABC(ownerRecord20, 1, 0);
            Family1265Field(privateRecord19, short *, 0x40) = 0xF0;
            Family1265Field(ownerRecord20, unsigned char *, 0x48) = 5U;
        }
        if (Family1265Field(ownerRecord20, unsigned char *, 0x48) != 6) {
            argumentWord5 = Family1265Field(privateRecord19, short **, 0x14);
            if (argumentWord5 != 0) {
                retainedRemainderMinimum22 = 5;
                rawWord8 = Family1265_D_8006C550;
                __asm__ volatile("" ::: "$21", "memory");
                retainedRemainderMinimum21 = 5;
                __asm__(""
                        : "=r"(retainedRemainderMinimum21)
                        : "0"(retainedRemainderMinimum21), "r"(rawWord8));
                argumentWord4 = ownerRecord20 - rawWord8;
                rawWord2 = ((unsigned)argumentWord4 << 5) - argumentWord4;
                rawWord2 = ((unsigned)rawWord2 << 5) + argumentWord4;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2));
                rawWord3 = (unsigned)rawWord2 << 3;
                rawWord2 += rawWord3;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2));
                rawWord3 = ((unsigned)rawWord2 << 15) - rawWord2;
                rawWord3 = ((unsigned)rawWord3 << 2) + argumentWord4;
                rawWord3 = -(unsigned)rawWord3;
                __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(argumentWord5));
                rawWord2 = Family1265Field(argumentWord5, short *, 2);
                rawWord9 = rawWord3 >> 3;
                originalFrame.sp18 = rawWord2;
                rawWord2 = Family1265Field(ownerRecord20, unsigned char *, 0x43);
                rawWord3 = Family1265_D_8006C730;
                argumentWord7 = Family1265Field(rawWord3, int *, rawWord2 * 4);
                do {
                    rawWord2 = Family1265Field(argumentWord7, unsigned short *, 0);
                    rawWord3 = rawWord2 & 0x7fff;
                    __asm__("" : "=r"(rawWord3) : "0"(rawWord3));
                    if (rawWord9 != rawWord3) {
                        rawWord2 = rawWord3 * 88;
                        rawWord2 = rawWord2 + rawWord8;
                        argumentWord6 = Family1265Field(rawWord2, int *, 0);
                        argumentWord4 = Family1265Field(privateRecord19, int *, 0x14);
                        rawWord3 = Family1265Field(argumentWord6, int *, 0x14);
                        rawWord2 = Family1265Field(argumentWord4, short *, 2);
                        rawWord3 = Family1265Field(rawWord3, short *, 2);
                        argumentWord5 = Family1265Field(argumentWord4, short *, 0);
                        rawWord2 = rawWord2 - rawWord3;
                        rawWord2 = rawWord2 + argumentWord5;
                        argumentWord4 = rawWord2 % argumentWord5;
                        if (argumentWord4 == 0) {
                            rawWord3 = Family1265Field(argumentWord6, int *, 0x58);
                            rawWord2 = Family1265Field(privateRecord19, int *, 0x58);
                            if (rawWord2 < rawWord3) {
                                argumentWord4 = argumentWord5;
                                __asm__("" : "=r"(argumentWord4) : "0"(argumentWord4));
                            }
                        }
                        rawWord2 = argumentWord4 < retainedRemainderMinimum22;
                        if (rawWord2)
                            retainedRemainderMinimum22 = argumentWord4;
                        rawWord2 = Family1265Field(privateRecord19, int *, 0x14);
                        rawWord2 = Family1265Field(rawWord2, short *, 0);
                        argumentWord4 = rawWord2 - argumentWord4;
                        if (argumentWord4 < retainedRemainderMinimum21)
                            retainedRemainderMinimum21 = argumentWord4;
                    }
                    rawWord2 = Family1265Field(argumentWord7, short *, 0);
                    __asm__ volatile("" ::"r"(argumentWord7) : "memory");
                    argumentWord7 += 2;
                } while (rawWord2 >= 0);
            }
        }
        goto dispatchOriginalState;
    }
    if (Family1265Field(ownerRecord20, int *, 0x18) != 0) {
        if (Family1265Field(ownerRecord20, unsigned char *, 0x48) != 4) {
            Family1265_func_80036A68(ownerRecord20, 0x10, 0, 0);
            Family1265_unk_ovlheader_80074384(ownerRecord20);
            Family1265Field(privateRecord19, int *, 0x48) = 0x78;
            Family1265Field(privateRecord19, int *, 0x1C) =
                (int)(Family1265_func_8004EDE8(privateRecord19 + 0x2C, 1) * 2);
            Family1265Field(privateRecord19, int *, 0x24) =
                (int)(Family1265Field(ownerRecord20, unsigned char *, 0x45) * 0x10);
            Family1265Field(privateRecord19, int *, 0x28) =
                (int)(Family1265Field(ownerRecord20, unsigned char *, 0x46) * 0x10);
            if (Family1265_rand() & 1) {
                Family1265Field(privateRecord19, int *, 0x2C) = -0x40;
                rawWord2 = 0x10;
            } else {
                Family1265Field(privateRecord19, int *, 0x2C) = 0x40;
                rawWord2 = -0x10;
            }
            Family1265Field(privateRecord19, int *, 0x34) = rawWord2;
            __asm__ volatile("" ::"m"(Family1265Field(privateRecord19, int *, 0x34)) : "memory");
            Family1265Field(privateRecord19, int *, 0x30) = -0x20;
            Family1265Field(ownerRecord20, int *, 8) = 0;
            if (Family1265TestSlot(ownerRecord20, Family1265Field(privateRecord19, int *, 4)))
                Family1265ClearSlot(Family1265Field(privateRecord19, int *, 4));
            Family1265Field(privateRecord19, int *, 4) = -1;
            Family1265_func_8003BABC(ownerRecord20, 2, 0);
            Family1265Field(ownerRecord20, unsigned char *, 0x48) = 4;
            return;
        }
        goto dispatchPreparedOriginalState;
    }
dispatchOriginalState:
dispatchPreparedOriginalState:
    switch (Family1265Field(ownerRecord20, unsigned char *, 0x48)) {
    case 0:
        if (Family1265Field(privateRecord19, int *, 0x0) != 0) {
            if (Family1265_D_8006FA3C == 2) {
                rawWord3 = Family1265Field(privateRecord19, void ***, 0x8);
                if ((*(int *)rawWord3) == 0) {
                    (*(int *)rawWord3) = ownerRecord20;
                    Family1265_func_80036518(
                        Family1265_D_8006C550 +
                            (Family1265Field(privateRecord19, int *, 0x50) * 0x58) + 0xC,
                        Family1265Field(privateRecord19, short **, 0xC),
                        Family1265Field(privateRecord19, int **, 0x54));
                    Family1265_D_8006FA80 = -2;
                }
                rawWord2 = Family1265Field(ownerRecord20, unsigned char *, 0x44);
                rawWord2 *= 16;
                Family1265Field(privateRecord19, int *, 0x20) = rawWord2;
                __asm__ volatile("" ::"m"(Family1265Field(privateRecord19, int *, 0x20))
                                 : "memory");
                rawWord2 = Family1265Field(ownerRecord20, unsigned char *, 0x45);
                argumentWord4 = Family1265Field(privateRecord19, int *, 0xC);
                rawWord2 *= 16;
                Family1265Field(privateRecord19, int *, 0x24) = rawWord2;
                rawWord3 = Family1265Field(ownerRecord20, unsigned char *, 0x46);
                __asm__ volatile("" ::: "$2", "memory");
                rawWord2 = Family1265Field(privateRecord19, int *, 0x58);
                Family1265Field(privateRecord19, int *, 0x14) = argumentWord4;
                rawWord2 = rawWord2 * 32 + 128;
                rawWord3 *= 16;
                Family1265Field(privateRecord19, int *, 0x18) = rawWord2;
                Family1265Field(privateRecord19, int *, 0x28) = rawWord3;
                goto initializeOriginalPath;
            }
            goto deleteOriginalActor;
        }
        if ((unsigned int)(Family1265_D_8006FA3C - 2) >= 2U) {
        initializeOriginalPath:
            Family1265SpawnMoby(303, ownerRecord20);
            Family1265Field(Family1265Field(privateRecord19, short **, 0x14), short *, 0xA) = 1;
            Family1265_func_80036518(ownerRecord20 + 0xC,
                                     Family1265Field(privateRecord19, short **, 0x14),
                                     &originalFrame.sp18);
            Family1265Field(Family1265Field(privateRecord19, short **, 0x14), short *, 2) =
                (short)originalFrame.sp18;
            argumentWord4 = Family1265Field(privateRecord19, short **, 0x14);
            rawWord3 = Family1265Field(argumentWord4, short *, 0);
            Family1265Field(argumentWord4, short *, 2) =
                (short)((int)(Family1265Field(argumentWord4, short *, 2) +
                              Family1265Field(argumentWord4, short *, 0xA) + rawWord3) %
                        rawWord3);
            argumentWord5 = 0x7fffffff;
            rawWord3 = Family1265Field(privateRecord19, int *, 0x58);
            rawWord2 = Family1265Field(privateRecord19, int *, 0x5C);
            rawWord3 = rawWord3 * 4 + rawWord2;
            rawWord2 = Family1265Field(ownerRecord20, int *, 0x1C);
            rawWord3 = Family1265Field(rawWord3, int *, 0);
            rawWord2 &= argumentWord5;
            Family1265Field(ownerRecord20, int *, 0x1C) = rawWord2;
            rawWord2 = 1;
            Family1265Field(ownerRecord20, unsigned char *, 0x48) = rawWord2;
            Family1265Field(ownerRecord20, int *, 0x54) = rawWord3;
            Family1265Field(ownerRecord20, signed char *, 0x57) = 0;
        } else
            goto deleteOriginalActor;
    default:
        goto processOriginalCommonPath;
    case 1:
        if (!Family1265TestSlot(ownerRecord20, Family1265Field(privateRecord19, int *, 4)))
            Family1265Field(privateRecord19, int *, 4) =
                Family1265_func_8003BABC(ownerRecord20, 0, 4);
        if (Family1265Field(privateRecord19, int *, 0x0) != 0) {
            Family1265Field(privateRecord19, int *, 0x1C) =
                Family1265_func_8004E4E4(
                    Family1265Field(ownerRecord20, int *, 0x14) -
                    ((int)((retainedFactorCounterOrVector16 *
                            (Family1265Field(privateRecord19, int *, 0x58) + 2))
                           << 0xE) >>
                     0x10)) -
                48;
            rawWord2 = Family1265_func_8004F334(ownerRecord20 + 12, (int)&Family1265_D_8006E020);
            rawWord2 = rawWord2 < 2048;
            if (rawWord2) {
                rawWord2 = Family1265Field(privateRecord19, int *, 0x1C);
                rawWord2 -= 2048;
                Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
            }
            rawWord2 = retainedRemainderMinimum21 < 5;
            if (rawWord2) {
                rawWord2 = Family1265Field(privateRecord19, int *, 0x1C);
                rawWord2 -= 1024;
                Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
            }
            rawWord3 = Family1265Field(privateRecord19, int *, 0x1C);
            rawWord2 = Family1265_D_8006C648;
            completeSpeedProduct = (long long)(int)rawWord3 * (int)rawWord2;
            argumentWord4 = ownerRecord20;
            argumentWord6 = privateRecord19 + 0x1C;
            argumentWord5 = Family1265Field(privateRecord19, int *, 0x14);
            rawWord3 = (int)Family1265_unk_ovlheader_80074398;
            __asm__(""
                    : "=l"(speedProductLow)
                    : "x"(completeSpeedProduct), "r"(rawWord3), "r"(argumentWord6));
            rawWord2 = speedProductLow >> 6;
            Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
            ((int (*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6);
            rawWord2 = Family1265_D_8006C730;
            __asm__ volatile("" ::: "$18", "memory");
            retainedVectorOrAngle18 = (int)&originalFrame.sp20;
            retainedPathOrAngle17 = Family1265Field(rawWord2, int *, 4);
        scanOriginalLinkedEntry:
            rawWord3 = Family1265Field(retainedPathOrAngle17, unsigned short *, 0);
            rawWord3 &= 0x7fff;
            __asm__("" : "=r"(rawWord3) : "0"(rawWord3));
            rawWord2 = rawWord3 * 88;
            rawWord3 = Family1265_D_8006C550;
            retainedFactorCounterOrVector16 = rawWord3 + rawWord2;
            if (Family1265_unk_ovlheader_800743A0(retainedFactorCounterOrVector16,
                                                  ownerRecord20 + 0xC, 0x400) != 0) {
                Family1265_func_8003BABC(retainedFactorCounterOrVector16, 1, 0);
                retainedFactorCounterOrVector16 = 0;
                argumentWord4 = ownerRecord20 + 0x20;
                do {
                    argumentWord5 = retainedVectorOrAngle18;
                    rawWord2 = Family1265Field(privateRecord19, int *, 0x1C);
                    __asm__ volatile("" ::: "$6", "memory");
                    argumentWord6 = retainedVectorOrAngle18;
                    __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                                     : "memory");
                    originalFrame.sp24 = 0;
                    originalFrame.sp28 = 0;
                    originalFrame.sp20 = rawWord2;
                    Family1265_func_8004ED6C(argumentWord4, argumentWord5, argumentWord6);
                    retainedFactorCounterOrVector16 += 1;
                    rawWord2 = Family1265_rand();
                    rawWord3 = originalFrame.sp20;
                    rawWord2 &= 0xFE;
                    rawWord3 -= 127;
                    rawWord3 += rawWord2;
                    originalFrame.sp20 = rawWord3;
                    rawWord2 = Family1265_rand();
                    rawWord3 = originalFrame.sp24;
                    rawWord2 &= 0xFE;
                    rawWord3 -= 127;
                    rawWord3 += rawWord2;
                    originalFrame.sp24 = rawWord3;
                    rawWord2 = Family1265_rand();
                    argumentWord4 = 1;
                    argumentWord5 = 23;
                    argumentWord6 = ownerRecord20 + 12;
                    argumentWord7 = (int)retainedVectorOrAngle18;
                    __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5),
                                     "r"(argumentWord6), "r"(argumentWord7));
                    rawWord2 &= 254;
                    rawWord3 = originalFrame.sp28;
                    rawWord3 -= 127;
                    rawWord3 += rawWord2;
                    originalFrame.sp28 = rawWord3;
                    Family1265_SpawnParticle(argumentWord4, argumentWord5, argumentWord6,
                                             argumentWord7);
                    argumentWord4 = ownerRecord20 + 0x20;
                } while (retainedFactorCounterOrVector16 < 8);
                rawWord3 = Family1265Field(privateRecord19, int *, 0x34);
                __asm__ volatile("" ::: "$2", "memory");
                rawWord2 = 48;
                Family1265Field(privateRecord19, short *, 0x40) = rawWord2;
                if (rawWord3 >= 0) {
                    rawWord2 = -1;
                } else {
                    __asm__ volatile("" ::: "$2");
                    rawWord2 = 1;
                }
                Family1265Field(privateRecord19, short *, 0x42) = rawWord2;
                rawWord2 = 2;
            writeOriginalTransitionState:
                Family1265Field(ownerRecord20, unsigned char *, 0x48) = rawWord2;
            } else {
                rawWord2 = Family1265Field(retainedPathOrAngle17, short *, 0);
                __asm__ volatile("" ::"r"(retainedPathOrAngle17) : "memory");
                retainedPathOrAngle17 += 2;
                if (rawWord2 < 0) {
                } else {
                    goto scanOriginalLinkedEntry;
                }
            }
            goto processOriginalCommonPath;
        }
        if (Family1265_D_8006FA3C == 2) {
            goto deleteOriginalActor;
        }
        retainedFactorCounterOrVector16 = Family1265Field(ownerRecord20, unsigned char *, 0x46);
        Family1265_unk_ovlheader_800743EC(ownerRecord20,
                                          Family1265Field(privateRecord19, short **, 0x14),
                                          privateRecord19 + 0x2C, privateRecord19 + 0x48, 0x12, 0);
        rawWord2 = Family1265Field(ownerRecord20, unsigned char *, 0x46);
        rawWord2 = retainedFactorCounterOrVector16 - rawWord2;
        retainedFactorCounterOrVector16 = rawWord2 & 255;
        if (retainedFactorCounterOrVector16 >= 0x81) {
            retainedFactorCounterOrVector16 -= 0x100;
        }
        rawWord2 = Family1265Field(ownerRecord20, unsigned char *, 0x44);
        rawWord3 = (unsigned)retainedFactorCounterOrVector16 << 6;
        rawWord3 -= rawWord2;
        retainedFactorCounterOrVector16 = rawWord3 & 255;
        if (retainedFactorCounterOrVector16 >= 0x81) {
            retainedFactorCounterOrVector16 -= 0x100;
        }
        argumentWord4 = Family1265Field(privateRecord19, int *, 0x38);
        rawWord3 = (unsigned)retainedFactorCounterOrVector16 << 3;
        rawWord2 = argumentWord4 * 12;
        rawWord3 = rawWord3 - rawWord2;
        __asm__ volatile("" ::"r"(rawWord3));
        rawWord3 >>= 6;
        __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(retainedFactorCounterOrVector16));
        rawWord2 = Family1265Field(privateRecord19, int *, 0x20);
        argumentWord4 += rawWord3;
        Family1265Field(privateRecord19, int *, 0x38) = argumentWord4;
        rawWord2 += argumentWord4;
        rawWord3 = rawWord2 & 4095;
        Family1265Field(privateRecord19, int *, 0x20) = rawWord3;
        if (rawWord3 >= 0x801) {
            rawWord2 = rawWord3 - 4096;
            Family1265Field(privateRecord19, int *, 0x20) = rawWord2;
            __asm__ volatile("" ::"r"(rawWord2), "r"(rawWord3));
        }
        rawWord2 = Family1265Field(privateRecord19, int *, 0x20);
        __asm__ volatile("" ::: "$3", "memory");
        rawWord3 = Family1265Field(privateRecord19, int *, 0x3C);
        if (rawWord3 < rawWord2) {
            Family1265Field(privateRecord19, int *, 0x20) = rawWord3;
        }
        rawWord3 = -Family1265Field(privateRecord19, int *, 0x3C);
        if (Family1265Field(privateRecord19, int *, 0x20) < rawWord3) {
            Family1265Field(privateRecord19, int *, 0x20) = rawWord3;
        }
        Family1265Field(ownerRecord20, unsigned char *, 0x44) =
            (unsigned char)((int)Family1265Field(privateRecord19, int *, 0x20) >> 4);
        Family1265_func_80055D24(ownerRecord20, 4);
        goto processOriginalCommonPath;
    case 2:
        if (!Family1265TestSlot(ownerRecord20, Family1265Field(privateRecord19, int *, 4)))
            Family1265Field(privateRecord19, int *, 4) =
                Family1265_func_8003BABC(ownerRecord20, 0, 4);
        rawWord2 = Family1265Field(privateRecord19, int *, 0x58) + 2;
        argumentWord4 = Family1265Field(ownerRecord20, int *, 0x14);
        retainedFactorCounterOrVector16 = (int)(retainedFactorCounterOrVector16 * rawWord2) >> 2;
        __asm__(""
                : "=r"(retainedFactorCounterOrVector16)
                : "0"(retainedFactorCounterOrVector16), "r"(argumentWord4));
        rawWord3 = Family1265_func_8004E4E4(argumentWord4 - retainedFactorCounterOrVector16);
        __asm__("" : "=r"(rawWord3) : "0"(rawWord3));
        Family1265Field(privateRecord19, int *, 0x1C) = rawWord3;
        if (retainedRemainderMinimum21 < 5) {
            rawWord2 = rawWord3 - 1024;
        } else
            rawWord2 = rawWord3 + 8192;
        Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
        __asm__ volatile("" ::"r"(rawWord2), "r"(rawWord3) : "memory");
        rawWord3 = Family1265Field(privateRecord19, int *, 0x1C);
        rawWord2 = Family1265_D_8006C648;
        rawWord2 = (int)(rawWord3 * rawWord2) >> 6;
        Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
        retainedFactorCounterOrVector16 = Family1265Field(privateRecord19, int *, 0x20);
        Family1265_unk_ovlheader_80074398(ownerRecord20,
                                          Family1265Field(privateRecord19, short **, 0x14),
                                          privateRecord19 + 0x1C);
        rawWord2 = Family1265Field(privateRecord19, short *, 0x42) << 7;
        retainedFactorCounterOrVector16 = (retainedFactorCounterOrVector16 + rawWord2) & 0xFFF;
        Family1265Field(privateRecord19, int *, 0x20) = retainedFactorCounterOrVector16;
        Family1265Field(privateRecord19, int *, 0x2C) = rawWord2;
        Family1265Field(ownerRecord20, unsigned char *, 0x44) =
            (unsigned char)(retainedFactorCounterOrVector16 >> 4);
        if (Family1265_func_800359A4(privateRecord19 + 0x40, 2) != 0) {
            Family1265Field(ownerRecord20, unsigned char *, 0x48) = 3U;
        }
        retainedFactorCounterOrVector16 = 0;
        retainedPathOrAngle17 = (int)&originalFrame.sp20;
        argumentWord4 = ownerRecord20 + 32;
        do {
            argumentWord5 = retainedPathOrAngle17;
            rawWord2 = Family1265Field(privateRecord19, int *, 0x1C);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedPathOrAngle17;
            __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                             : "memory");
            originalFrame.sp24 = 0;
            originalFrame.sp28 = 0;
            rawWord2 >>= 2;
            originalFrame.sp20 = rawWord2;
            Family1265_func_8004ED6C(argumentWord4, argumentWord5, argumentWord6);
            retainedFactorCounterOrVector16 += 1;
            rawWord2 = Family1265_rand();
            rawWord3 = originalFrame.sp20;
            rawWord2 &= 0xFE;
            rawWord3 -= 127;
            rawWord3 += rawWord2;
            originalFrame.sp20 = rawWord3;
            rawWord2 = Family1265_rand();
            rawWord3 = originalFrame.sp24;
            rawWord2 &= 0xFE;
            rawWord3 -= 127;
            rawWord3 += rawWord2;
            originalFrame.sp24 = rawWord3;
            rawWord2 = Family1265_rand();
            argumentWord4 = 1;
            argumentWord5 = 23;
            argumentWord6 = ownerRecord20 + 12;
            argumentWord7 = retainedPathOrAngle17;
            __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6),
                             "r"(argumentWord7));
            rawWord2 &= 254;
            rawWord3 = originalFrame.sp28;
            rawWord3 -= 127;
            rawWord3 += rawWord2;
            originalFrame.sp28 = rawWord3;
            Family1265_SpawnParticle(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            argumentWord4 = ownerRecord20 + 0x20;
        } while (retainedFactorCounterOrVector16 < 2);
        goto processOriginalCommonPath;
    case 3:
        if (!Family1265TestSlot(ownerRecord20, Family1265Field(privateRecord19, int *, 4)))
            Family1265Field(privateRecord19, int *, 4) =
                Family1265_func_8003BABC(ownerRecord20, 0, 4);
        rawWord2 = Family1265Field(privateRecord19, int *, 0x58) + 2;
        argumentWord4 = Family1265Field(ownerRecord20, int *, 0x14);
        retainedPathOrAngle17 = (int)(retainedFactorCounterOrVector16 * rawWord2) >> 2;
        __asm__("" : "=r"(retainedPathOrAngle17) : "0"(retainedPathOrAngle17), "r"(argumentWord4));
        retainedPathOrAngle17 = Family1265_func_8004E4E4(argumentWord4 - retainedPathOrAngle17);
        if (retainedRemainderMinimum21 < 5) {
            Family1265Field(privateRecord19, int *, 0x1C) =
                (int)(Family1265Field(privateRecord19, int *, 0x1C) - 0x400);
        }
        argumentWord4 = Family1265Field(privateRecord19, int *, 0x1C);
        retainedPathOrAngle17 = (int)(retainedPathOrAngle17 * Family1265_D_8006C648) >> 6;
        if ((argumentWord4 - retainedPathOrAngle17) >= 4) {
            rawWord2 = argumentWord4 - (Family1265_D_8006C648 * 3);
            Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
        } else {
            Family1265Field(privateRecord19, int *, 0x1C) = retainedPathOrAngle17;
            Family1265Field(ownerRecord20, unsigned char *, 0x48) = 1U;
        }
        retainedVectorOrAngle18 = Family1265Field(privateRecord19, int *, 0x20);
        retainedPathOrAngle17 = Family1265Field(privateRecord19, int *, 0x2C);
        Family1265_unk_ovlheader_80074398(ownerRecord20,
                                          Family1265Field(privateRecord19, short **, 0x14),
                                          privateRecord19 + 0x1C);
        rawWord2 = -retainedVectorOrAngle18;
        retainedVectorOrAngle18 = rawWord2 & 0xFFF;
        Family1265Field(privateRecord19, int *, 0x2C) = retainedPathOrAngle17;
        if (retainedVectorOrAngle18 >= 0x801) {
            retainedVectorOrAngle18 -= 0x1000;
        }
        argumentWord4 = ownerRecord20 + 32;
        retainedFactorCounterOrVector16 = (int)&originalFrame.sp30;
        argumentWord5 = retainedFactorCounterOrVector16;
        __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5));
        rawWord2 = retainedPathOrAngle17 +
                   ((int)(retainedVectorOrAngle18 - (retainedPathOrAngle17 * 0x18)) >> 6);
        Family1265Field(privateRecord19, int *, 0x2C) = rawWord2;
        rawWord3 = (Family1265Field(privateRecord19, int *, 0x20) + rawWord2) & 0xFFF;
        Family1265Field(privateRecord19, int *, 0x20) = rawWord3;
        Family1265Field(ownerRecord20, unsigned char *, 0x44) = (unsigned char)(rawWord3 >> 4);
        rawWord2 = Family1265Field(privateRecord19, int *, 0x1C);
        __asm__ volatile("" ::: "$6", "memory");
        argumentWord6 = retainedFactorCounterOrVector16;
        __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                         : "memory");
        originalFrame.sp34 = 0;
        originalFrame.sp38 = 0;
        rawWord2 >>= 2;
        originalFrame.sp30 = rawWord2;
        Family1265_func_8004ED6C(argumentWord4, argumentWord5, argumentWord6);
        rawWord2 = Family1265_rand();
        rawWord3 = originalFrame.sp30;
        rawWord2 &= 0xFE;
        rawWord3 -= 127;
        rawWord3 += rawWord2;
        originalFrame.sp30 = rawWord3;
        rawWord2 = Family1265_rand();
        rawWord3 = originalFrame.sp34;
        rawWord2 &= 0xFE;
        rawWord3 -= 127;
        rawWord3 += rawWord2;
        originalFrame.sp34 = rawWord3;
        rawWord2 = Family1265_rand();
        argumentWord4 = 1;
        argumentWord5 = 23;
        argumentWord6 = ownerRecord20 + 12;
        argumentWord7 = (int)&originalFrame.sp30;
        __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6),
                         "r"(argumentWord7));
        rawWord2 &= 254;
        rawWord3 = originalFrame.sp38;
        rawWord3 -= 127;
        rawWord3 += rawWord2;
        originalFrame.sp38 = rawWord3;
        Family1265_SpawnParticle(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
        goto processOriginalCommonPath;
    case 4:
        if (!Family1265_func_800359A4(privateRecord19 + 0x48, 4)) {
        updateOriginalFallAngles:
            rawWord2 = Family1265Field(privateRecord19, int *, 0x20);
            argumentWord4 = Family1265Field(privateRecord19, int *, 0x2C);
            rawWord3 = Family1265Field(privateRecord19, int *, 0x24);
            argumentWord5 = Family1265Field(privateRecord19, int *, 0x30);
            rawWord2 += argumentWord4;
            Family1265Field(privateRecord19, int *, 0x20) = rawWord2;
            rawWord3 = (rawWord3 + argumentWord5) & 0xfff;
            Family1265Field(privateRecord19, int *, 0x24) = rawWord3;
            if (rawWord3 >= 2049) {
                rawWord2 = rawWord3 - 4096;
                Family1265Field(privateRecord19, int *, 0x24) = rawWord2;
                __asm__ volatile("" ::"r"(rawWord2), "r"(rawWord3));
            }
            if (Family1265Field(privateRecord19, int *, 0x24) < -0x200) {
                Family1265Field(privateRecord19, int *, 0x24) = -0x200;
            }
            Family1265Field(privateRecord19, int *, 0x28) =
                (int)(Family1265Field(privateRecord19, int *, 0x28) +
                      Family1265Field(privateRecord19, int *, 0x34));
            Family1265Field(ownerRecord20, unsigned char *, 0x44) =
                (unsigned char)((int)Family1265Field(privateRecord19, int *, 0x20) >> 4);
            Family1265Field(ownerRecord20, unsigned char *, 0x45) =
                (unsigned char)((int)Family1265Field(privateRecord19, int *, 0x24) >> 4);
            Family1265Field(ownerRecord20, unsigned char *, 0x46) =
                (unsigned char)((int)Family1265Field(privateRecord19, int *, 0x28) >> 4);
            Family1265_func_80055D24(ownerRecord20, 4);
            argumentWord4 = ownerRecord20 + 32;
            retainedFactorCounterOrVector16 = (int)&originalFrame.sp40;
            argumentWord5 = retainedFactorCounterOrVector16;
            rawWord2 = Family1265Field(privateRecord19, int *, 0x1C);
            __asm__ volatile("" ::: "$6", "memory");
            argumentWord6 = retainedFactorCounterOrVector16;
            __asm__ volatile("" ::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6)
                             : "memory");
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0;
            originalFrame.sp40 = rawWord2;
            Family1265_func_8004ED6C(argumentWord4, argumentWord5, argumentWord6);
            retainedPathOrAngle17 = ownerRecord20 + 0xC;
            Family1265_func_8004F194(retainedPathOrAngle17, retainedPathOrAngle17,
                                     &originalFrame.sp40);
            Family1265_func_80055F14(ownerRecord20, 1, &originalFrame.sp50);
            originalFrame.sp40 = (Family1265_rand() & 0x3E) - 0x1F;
            originalFrame.sp44 = (Family1265_rand() & 0x3E) - 0x1F;
            originalFrame.sp48 = (Family1265_rand() & 0x3E) - 0x1F;
            Family1265_SpawnParticle(1, 1, &originalFrame.sp50, &originalFrame.sp40);
            if (Family1265_func_80019194(retainedPathOrAngle17, 0x400) != 0) {
                Family1265_func_8003BABC(ownerRecord20, 3, 0);
                goto deleteOriginalActor;
            }
            goto processOriginalCommonPath;
        }
        goto deleteOriginalActor;
    case 5:
        rawWord2 = Family1265Field(privateRecord19, int *, 0x58) + 2;
        argumentWord4 = Family1265Field(ownerRecord20, int *, 0x14);
        retainedFactorCounterOrVector16 = (int)(retainedFactorCounterOrVector16 * rawWord2) >> 2;
        __asm__(""
                : "=r"(retainedFactorCounterOrVector16)
                : "0"(retainedFactorCounterOrVector16), "r"(argumentWord4));
        rawWord3 = Family1265_func_8004E4E4(argumentWord4 - retainedFactorCounterOrVector16);
        __asm__("" : "=r"(rawWord3) : "0"(rawWord3));
        Family1265Field(privateRecord19, int *, 0x1C) = rawWord3;
        if (retainedRemainderMinimum22 >= 5) {
            rawWord2 = rawWord3 - 0x1000;
            Family1265Field(privateRecord19, int *, 0x1C) = rawWord2;
            __asm__ volatile("" ::"r"(rawWord2), "r"(rawWord3));
        }
        if (Family1265Field(privateRecord19, int *, 0x1C) < 0x800) {
            Family1265Field(privateRecord19, int *, 0x1C) = 0x800;
        }
        retainedPathOrAngle17 = Family1265Field(privateRecord19, int *, 0x20);
        Family1265Field(privateRecord19, int *, 0x1C) =
            (int)((int)(Family1265Field(privateRecord19, int *, 0x1C) * Family1265_D_8006C648) >>
                  6);
        retainedFactorCounterOrVector16 = Family1265Field(privateRecord19, int *, 0x2C);
        Family1265_unk_ovlheader_80074398(ownerRecord20,
                                          Family1265Field(privateRecord19, short **, 0x14),
                                          privateRecord19 + 0x1C);
        Family1265Field(privateRecord19, int *, 0x2C) = retainedFactorCounterOrVector16;
        Family1265Field(privateRecord19, int *, 0x20) = retainedPathOrAngle17;
        rawWord3 = Family1265Field(privateRecord19, short *, 0x40);
        rawWord2 = 240 - rawWord3;
        retainedFactorCounterOrVector16 = (unsigned)rawWord2 << 3;
        __asm__("" : "=r"(retainedFactorCounterOrVector16) : "0"(retainedFactorCounterOrVector16));
        rawWord2 = retainedFactorCounterOrVector16 & 0x1f8;
        rawWord2 = Family1265Field((int)&Family1265_D_80065920, unsigned short *, rawWord2);
        __asm__("" : "=r"(rawWord2) : "0"(rawWord2));
        rawWord2 = (unsigned)rawWord2 << 16;
        retainedFactorCounterOrVector16 = rawWord2 >> 19;
        __asm__("" : "=r"(retainedFactorCounterOrVector16) : "0"(retainedFactorCounterOrVector16));
        rawWord2 = retainedFactorCounterOrVector16 - retainedPathOrAngle17;
        retainedPathOrAngle17 = rawWord2 & 0xfff;
        if (retainedPathOrAngle17 >= 0x801) {
            retainedPathOrAngle17 -= 0xFFF;
        }
        argumentWord5 = 0x2aaaaaab;
        argumentWord4 = Family1265Field(privateRecord19, int *, 0x2C);
        rawWord3 = retainedPathOrAngle17 * 2;
        rawWord2 = argumentWord4 * 24;
        rawWord3 -= rawWord2;
        rawWord3 >>= 6;
        __asm__("" : "=r"(rawWord3) : "0"(rawWord3), "r"(retainedPathOrAngle17));
        argumentWord4 += rawWord3;
        Family1265Field(privateRecord19, int *, 0x2C) = argumentWord4;
        rawWord2 = (Family1265Field(privateRecord19, int *, 0x20) + argumentWord4) & 0xFFF;
        Family1265Field(privateRecord19, int *, 0x20) = rawWord2;
        Family1265Field(ownerRecord20, unsigned char *, 0x44) = (unsigned char)(rawWord2 >> 4);
        rawWord3 = Family1265Field(privateRecord19, short *, 0x40);
        rawWord2 = 90 - rawWord3;
        completeDivisionProduct = (long long)(int)rawWord2 * (int)argumentWord5;
        rawWord2 >>= 31;
        rawWord3 = rawWord3 < 90;
        __asm__(""
                : "=h"(divisionProductHigh)
                : "x"(completeDivisionProduct), "r"(rawWord2), "r"(rawWord3));
        argumentWord4 = divisionProductHigh >> 1;
        retainedFactorCounterOrVector16 = argumentWord4 - rawWord2;
        if (!rawWord3 || __extension__({
                rawWord2 = retainedFactorCounterOrVector16 & 1;
                __asm__("" : "=r"(rawWord2) : "0"(rawWord2), "r"(retainedFactorCounterOrVector16));
                argumentWord4 = privateRecord19 + 0x40;
                rawWord2;
            })) {
            Family1265_func_80055F14(ownerRecord20, 1, &originalFrame.sp70);
            retainedFactorCounterOrVector16 = 0;
            do {
                retainedFactorCounterOrVector16 += 1;
                originalFrame.sp60 = (Family1265_rand() & 0x3E) - 0x1F;
                originalFrame.sp64 = (Family1265_rand() & 0x3E) - 0x1F;
                originalFrame.sp68 = (Family1265_rand() & 0x3E) - 0x1F;
                Family1265_SpawnParticle(1, 1, &originalFrame.sp70, &originalFrame.sp60);
                argumentWord4 = privateRecord19 + 0x40;
            } while (retainedFactorCounterOrVector16 < 2);
        }
        if (Family1265_func_800359A4(argumentWord4, 2) != 0) {
            Family1265Field(ownerRecord20, int *, 0x18) = 0;
            rawWord2 = 1;
            Family1265Field(ownerRecord20, unsigned char *, 0x48) = rawWord2;
        }
        goto processOriginalCommonPath;
    case 6:
        retainedFactorCounterOrVector16 = Family1265Field(ownerRecord20, int *, 0);
        rawWord2 = Family1265Field(retainedFactorCounterOrVector16, int *, 0);
        if (Family1265Field(rawWord2, unsigned char *, 0x48) & 128) {
        deleteOriginalActor:
            Family1265_func_80055B18(ownerRecord20);
            return;
        }
        Family1265Field(ownerRecord20, unsigned char *, 0x44) += 24;
        Family1265_func_80055F14(Family1265Field(retainedFactorCounterOrVector16, int *, 0), 0,
                                 ownerRecord20 + 12);
        rawWord2 = Family1265Field(retainedFactorCounterOrVector16, int *, 0);
        Family1265Field(ownerRecord20, unsigned char *, 0x45) =
            Family1265Field(rawWord2, unsigned char *, 0x45);
        rawWord2 = Family1265Field(retainedFactorCounterOrVector16, int *, 0);
        Family1265Field(ownerRecord20, unsigned char *, 0x46) =
            Family1265Field(rawWord2, unsigned char *, 0x46);
        goto processOriginalCommonPath;
    }
processOriginalCommonPath:
    if (Family1265Field(ownerRecord20, unsigned char *, 0x48) != 6 &&
        Family1265Field(privateRecord19, int *, 0) != 0) {
        argumentWord4 = Family1265Field(privateRecord19, short **, 0x14);
        rawWord3 = Family1265Field(argumentWord4, short *, 2);
        if ((rawWord3 != originalFrame.sp18) &&
            (Family1265Field(((rawWord3 * 0x10) + Family1265Field(argumentWord4, int *, 0xC)),
                             int *, 0xC) != 0)) {
            rawWord2 = retainedRemainderMinimum22 < 5;
            if (rawWord2) {
                rawWord2 = 1;
                originalFrame.sp18 = rawWord2;
            } else {
                rawWord2 = retainedRemainderMinimum21 < 5;
                if (!rawWord2) {
                    rawWord2 = Family1265Field(privateRecord19, int *, 0x58);
                    rawWord3 = Family1265Field(privateRecord19, int *, 0x18);
                    rawWord2 = rawWord2 * 8 + 128;
                    rawWord3 = rawWord3 + rawWord2;
                    Family1265Field(privateRecord19, int *, 0x18) = rawWord3;
                    rawWord3 = rawWord3 < 345;
                    if (!rawWord3) {
                        rawWord3 = 1;
                        __asm__ volatile("" : "=r"(rawWord3) : "0"(rawWord3) : "memory");
                        rawWord2 = Family1265Field(privateRecord19, int *, 0x18);
                        originalFrame.sp18 = rawWord3;
                        rawWord2 -= 345;
                        Family1265Field(privateRecord19, int *, 0x18) = rawWord2;
                        goto family1182Selected;
                    }
                }
                originalFrame.sp18 = 0;
            }
        family1182Selected:
            rawWord2 = originalFrame.sp18;
            rawWord3 = Family1265Field(privateRecord19, int *, 0x14);
            rawWord2 = rawWord2 * 4 + privateRecord19;
            argumentWord5 = Family1265Field(rawWord2, int *, 12);
            argumentWord4 = ownerRecord20 + 12;
            if (rawWord3 != argumentWord5) {
                argumentWord6 = Family1265Field(rawWord3, short *, 2);
                rawWord2 = (int)Family1265_unk_ovlheader_800743A4;
                rawWord2 = ((int (*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, 3);
                rawWord3 = originalFrame.sp18 * 4 + privateRecord19;
                argumentWord4 = Family1265Field(rawWord3, int *, 12);
                Family1265Field(argumentWord4, short *, 2) = rawWord2;
                rawWord3 = Family1265Field(rawWord3, int *, 12);
                rawWord2 = 1;
                Family1265Field(privateRecord19, int *, 0x14) = rawWord3;
                Family1265Field(rawWord3, short *, 0xA) = rawWord2;
                argumentWord5 = Family1265Field(privateRecord19, int *, 0x14);
                rawWord3 = Family1265Field(argumentWord5, short *, 0);
                rawWord2 = Family1265Field(argumentWord5, short *, 2);
                argumentWord4 = rawWord3 + 2;
                rawWord2 = rawWord2 + argumentWord4;
                rawWord3 = rawWord2 % rawWord3;
                Family1265Field(argumentWord5, short *, 2) = rawWord3;
            }
        }
        argumentWord4 = privateRecord19 + 0x48;
        if (*Family1265Field(privateRecord19, void ***, 0x8) == ownerRecord20) {
            Family1265Field((int)&Family1265_D_8006FA7C, int *, 0) = 0;
            if (Family1265Field((int)&Family1265_D_8006FA7C, int *, 4) == -1) {
                Family1265_func_80036518((int)&Family1265_D_80070328,
                                         Family1265Field(privateRecord19, short **, 0xC),
                                         (int)&Family1265_D_8006FA7C + 4);
            } else if (Family1265Field((int)&Family1265_D_8006FA7C, int *, 4) == -2) {
                Family1265Field((int)&Family1265_D_8006FA7C, int *, 4) = -1;
            }
            retainedPathOrAngle17 = (int)&Family1265_D_8006FA80;
            retainedFactorCounterOrVector16 = Family1265Field(retainedPathOrAngle17, int *, 0);
            if (retainedFactorCounterOrVector16 >= 0) {
                argumentWord6 = retainedFactorCounterOrVector16;
                rawWord3 = Family1265_unk_ovlheader_800743A4(
                    (int)&Family1265_D_80070328, Family1265Field(privateRecord19, int *, 0xC),
                    argumentWord6, 10);
                Family1265Field(retainedPathOrAngle17, int *, 0) = rawWord3;
                rawWord2 = retainedFactorCounterOrVector16 < 10;
                if (rawWord2) {
                    rawWord2 = Family1265Field(privateRecord19, int *, 0xC);
                    rawWord2 = Family1265Field(rawWord2, short *, 0);
                    rawWord2 -= 11;
                    if (rawWord2 < rawWord3) {
                        rawWord2 = 10;
                        Family1265Field(retainedPathOrAngle17, int *, 0) = rawWord2;
                    }
                }
            }
            argumentWord4 = privateRecord19 + 0x48;
        }
        if ((Family1265_func_800359A4(argumentWord4, 4) != 0) &&
            (Family1265_unk_ovlheader_8007439C(
                 Family1265_D_8006C550 + (Family1265Field(privateRecord19, int *, 0x50) * 0x58),
                 ownerRecord20 + 0xC, 0x1000, 0) != 0)) {
            Family1265Field(privateRecord19, int *, 0x48) = 0x78;
            Family1265Field(privateRecord19, int *, 0x44) =
                (int)(Family1265Field(privateRecord19, int *, 0x44) + 1);
        }
        argumentWord4 = *Family1265Field(privateRecord19, short **, 0xC);
        retainedFactorCounterOrVector16 = (int)((Family1265_D_8006FA80 + argumentWord4) -
                                                *Family1265Field(privateRecord19, int **, 0x54)) %
                                          argumentWord4;
        if ((Family1265Field(
                 ((Family1265Field(privateRecord19, int *, 0x50) * 0x58) + Family1265_D_8006C550),
                 unsigned char *, 0x48) == 3) &&
            (retainedFactorCounterOrVector16 == 0)) {
            retainedFactorCounterOrVector16 = (int)argumentWord4;
        }
        argumentWord5 = Family1265Field(privateRecord19, short **, 0xC);
        retainedFactorCounterOrVector16 =
            retainedFactorCounterOrVector16 + ((*((short *)argumentWord5)) * Family1265_D_8006FA78);
        rawWord2 = Family1265_unk_ovlheader_800743A4(
            ownerRecord20 + 0xC, argumentWord5,
            Family1265Field(Family1265Field(privateRecord19, short **, 0x14), short *, 2), 3);
        originalFrame.sp18 = rawWord2;
        rawWord3 = *Family1265Field(privateRecord19, short **, 0xC);
        signedRemainder =
            (int)((rawWord2 + rawWord3) - *Family1265Field(privateRecord19, int **, 0x54)) %
            rawWord3;
        originalFrame.sp18 = signedRemainder;
        if ((signedRemainder == 0) && (Family1265Field(privateRecord19, int *, 0x48) == 0)) {
            originalFrame.sp18 = (int)*Family1265Field(privateRecord19, short **, 0xC);
        }
        rawWord2 = Family1265Field(privateRecord19, int *, 0xC);
        rawWord3 = Family1265Field(rawWord2, short *, 0);
        rawWord2 = Family1265Field(privateRecord19, int *, 0x44);
        completeFinalProduct = (long long)(int)rawWord3 * (int)rawWord2;
        rawWord2 = originalFrame.sp18;
        __asm__("" : "=l"(finalProductLow) : "x"(completeFinalProduct), "r"(rawWord2));
        rawWord3 = rawWord2 + finalProductLow;
        originalFrame.sp18 = rawWord3;
        argumentWord4 = Family1265Field(privateRecord19, int *, 0x4C);
        if (argumentWord4 == 1) {
            rawWord2 = rawWord3 + 1;
            goto family1182Adjusted;
        } else if (argumentWord4 == 2) {
            rawWord2 = rawWord3 - 1;
        family1182Adjusted:
            originalFrame.sp18 = rawWord2;
        }
        rawWord2 = originalFrame.sp18;
        rawWord2 = retainedFactorCounterOrVector16 < rawWord2;
        if (rawWord2) {
            rawWord2 = (int)&Family1265_D_8006FA7C;
            rawWord3 = Family1265Field(rawWord2, int *, 0);
            rawWord3++;
            Family1265Field(rawWord2, int *, 0) = rawWord3;
            rawWord2 = 1;
        } else
            rawWord2 = 2;
        Family1265Field(privateRecord19, int *, 0x4C) = rawWord2;
    }
    return;
}
#undef Family1265Field


/* AI-generated reconstruction; not human reviewed. Rev0 original181 words
 * at8007A6CC..8007A9A0. Reuses Rev1 raw329 source-local state/child routes;
 * Rev0 first sample byte offset uses phase<<3 (Rev1 uses phase<<2).
 * Tag words0/4/8 and byte/halfword access widths follow original instructions.
 * Physical coordinate units, table producers, helper effects, SFX meaning and
 * caller cadence remain unresolved. Empty constraints preserve fresh reads
 * and forget the incoming A0 lifetime without emitting instructions. */
typedef struct { int handle; Moby* child; unsigned int phase; } DecodedRaw329Tag;
extern int D_8006FA3C, D_8006C648;
extern unsigned char Raw329StateTable[] __asm__("D_80066964");
extern unsigned char Raw329AnimationTable[] __asm__("D_80066988");
extern unsigned char Raw329ColourTable[] __asm__("D_80066990");
extern unsigned short Raw329Samples[] __asm__("D_80065920");
extern unsigned char Raw329Player[] __asm__("D_80070328");
extern int (*Raw329Check)(Moby*,void*,int,int) __asm__("unk_ovlheader_8007439C");
extern void (*Raw329Finish)(Moby*) __asm__("unk_ovlheader_80074384");
int Raw329HandleCheck(Moby*,int) __asm__("func_8003BFC0");
int Raw329HandleStart(Moby*,int,int) __asm__("func_8003BABC");
void Raw329HandleStop(int) __asm__("func_8003BE70");
void func_level_25_80079E14(Moby* argument) {
    register Moby* moby __asm__("$18") = argument;
    register DecodedRaw329Tag* tag __asm__("$17") = moby->mobyTag;
    int reservedStack[2];
    register unsigned char* childTag __asm__("$16");
    __asm__("" : : : "$4");
    switch (moby->state) {
    case 0:
        if ((unsigned int)(D_8006FA3C - 2) < 2) goto remove;
        if (moby->gemValue != 255) {
            tag->child = SpawnMoby(1,moby);
            if (tag->child) {
                childTag = tag->child->mobyTag;
                func_8004F178(&tag->child->position,&moby->position);
                tag->child->state = 5;
                tag->child->substate = Raw329StateTable[moby->gemValue];
                __asm__("" : : : "memory");
                tag->child->animationState.id = Raw329AnimationTable[tag->child->substate];
                __asm__("" : : : "memory");
                tag->child->colour.r = Raw329ColourTable[tag->child->substate];
                __asm__("" : : : "memory");
                tag->child->lowDrawDistance = moby->lowDrawDistance;
                __asm__("" : : : "memory");
                tag->child->highDrawDistance = moby->highDrawDistance;
                childTag[0x13] = 255;
                tag->phase = rand() & 255;
            }
        }
        moby->state = 1;
        break;
    case 1:
        if (!Raw329HandleCheck(moby,tag->handle)) tag->handle = Raw329HandleStart(moby,1,4);
        moby->angle.roll += 8;
        if (tag->child) {
            tag->phase += D_8006C648;
            tag->child->angle.pitch = *(unsigned short*)((unsigned char*)Raw329Samples + ((tag->phase << 3) & 0x1F8)) >> 8;
            __asm__("" : : : "memory");
            tag->child->angle.yaw += 4;
            __asm__("" : : : "memory");
            tag->child->position.z = moby->position.z + ((int)(short)*(unsigned short*)((unsigned char*)Raw329Samples + ((tag->phase << 2) & 0x1FC)) >> 4);
        }
        if (Raw329Check(moby,Raw329Player,0xC00,0)) moby->state = 2;
        break;
    case 2:
        Raw329Finish(moby);
        if (tag->child) tag->child->state = 4;
        if (Raw329HandleCheck(moby,tag->handle)) Raw329HandleStop(tag->handle);
        tag->handle = -1;
        Raw329HandleStart(moby,0,0);
remove:
        func_80055B18(moby);
        break;
    }
}

typedef struct { int kind; Vector3D vector; int phase; Vector3D* fragments; int sound; } DecodedSoundFragmentTag;
extern int D_8006FA3C;
extern void (*DecodedFragmentDamage)(Moby*) __asm__("unk_ovlheader_80074384");
extern void (*DecodedFragmentMotion)(Moby*,int,Vector3D*,int*,int,int) __asm__("unk_ovlheader_800743EC");
void func_level_25_8007A0E8(Moby* moby) {
    DecodedSoundFragmentTag* tag = moby->mobyTag;
    if (moby->damageFlags) {
        if (func_8003BFC0(moby, tag->sound)) func_8003BE70(tag->sound);
        tag->sound = -1;
        func_8003BABC(moby, 0, 0);
        func_80036A68(moby, 0x10, 0, 0);
        DecodedFragmentDamage(moby);
        SpawnFragments(5, 0x154, moby, tag->fragments, 0, 0x200);
        func_80055B18(moby);
    } else if ((unsigned int)(D_8006FA3C - 2) < 2) func_80055B18(moby);
    else {
        if (!func_8003BFC0(moby, tag->sound)) tag->sound = func_8003BABC(moby, 1, 4);
        DecodedFragmentMotion(moby, tag->kind, &tag->vector, &tag->phase, 12, 4);
    }
}

typedef struct { int reserved00; EnemyTag enemy; } DecodedDamageTransitionTag;
extern int D_8006FA3C;
extern void (*DecodedDamageCallback)(Moby*) __asm__("unk_ovlheader_80074384");
void func_level_25_8007A238(Moby* moby) {
    DecodedDamageTransitionTag* tag = moby->mobyTag;
    if (moby->damageFlags && moby->state != 1) {
        func_80036A68(moby, 0x10, 0, 0);
        DecodedDamageCallback(moby);
        func_80038F14(moby, &tag->enemy, 6, 1);
        { int momentum = *(int*)((char*)&spyro + 0xB4);
        tag->enemy.unkE = 6;
        tag->enemy.unk16 = 0x78;
        tag->enemy.unk4 += momentum >> 5; }
        moby->unknownCollision = 0;
    }
    switch (moby->state) {
    case 0:
        func_8003573C(moby, 4, 0, 0);
        if ((unsigned int)(D_8006FA3C - 2) < 2) func_80055B18(moby);
        break;
    case 1:
        if (func_80035194(moby, &tag->enemy) == 0x100) {
            func_80055D24(moby, 4);
            func_8003BA00(moby);
            func_800369B8(moby, 0x30);
            func_80055B18(moby);
        }
        break;
    }
}

/* Original private record: word timer/mode and signed halfword range bounds. */
typedef struct {
    int timer, mode;
    short lower, upper;
} DecodedTimedPickupTag;
extern int D_8006FA3C, D_8006FA80;
extern unsigned short DecodedPickupYaw __asm__("D_8006E040");
extern unsigned short DecodedPickupPitch __asm__("D_8006E03E");
extern char DecodedPickupPlayer[] __asm__("D_80070328");
extern int DecodedPickupHeading __asm__("D_80070328 + 0x15C");
extern int (*DecodedPickupQuery)(Moby*, void*, int) __asm__("unk_ovlheader_800743A0");
int rand(void);
int func_800359A4(void*, int);
int func_8003BABC(Moby*, int, int);
void func_8004F178(Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
void func_80055B18(Moby*);
void func_level_25_8007A374(Moby* moby) {
    Vector3D velocity;
    register DecodedTimedPickupTag* tag __asm__("$19") = (DecodedTimedPickupTag*)moby->mobyTag;
    register Vector3D* playerVelocity __asm__("$18");
    register int sign __asm__("$2");
    int noise;
    register int heading __asm__("$3");
    register int boost __asm__("$2");
    register int biased __asm__("$3");
    register int index __asm__("$17");
    switch (moby->state) {
    case 0:
        if (D_8006FA3C == 2) {
            if (!tag->mode) { func_80055B18(moby); break; }
        } else if (D_8006FA3C == 3 || tag->mode) {
            func_80055B18(moby);
            break;
        }
        moby->state = 1;
        break;
    case 1:
        if (tag->lower && tag->upper) {
            if (tag->lower < D_8006FA80 && D_8006FA80 < tag->upper) {
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
            } else {
                moby->unknown3[0] = 1;
                moby->lowDrawDistance = 63;
                moby->drawn = 1;
            }
        }
        moby->angle.yaw = ((int)(DecodedPickupYaw << 16) >> 20) - 128;
        moby->angle.pitch = DecodedPickupPitch >> 4;
        if (DecodedPickupQuery(moby, DecodedPickupPlayer, 1024)) moby->state = 2;
        break;
    case 2:
        func_8003BABC(moby, 0, 0);
        index = 0;
        /* Empty constraints preserve retail loop setup and legacy compiler scheduling. */
        __asm__ volatile("" : : "r"(index) : "$18");
        playerVelocity = (Vector3D*)(DecodedPickupPlayer + 152);
        for (; index < 8; index++) {
            func_8004F178(&velocity, playerVelocity);
            func_8004F110(&velocity, 5);
            noise = rand();
            biased = velocity.x - 127;
            __asm__("" : "=r"(biased) : "0"(biased), "r"(noise & 254));
            velocity.x = biased + (noise & 254);
            noise = rand();
            biased = velocity.y - 127;
            __asm__("" : "=r"(biased) : "0"(biased), "r"(noise & 254));
            velocity.y = biased + (noise & 254);
            noise = rand();
            biased = velocity.z - 127;
            __asm__("" : "=r"(biased) : "0"(biased), "r"(noise & 254));
            velocity.z = biased + (noise & 254);
            SpawnParticle(1, 23, (Vector3D*)((char*)playerVelocity - 152), &velocity);
        }
        __asm__("" : "=r"(playerVelocity) : "0"(playerVelocity));
        heading = DecodedPickupHeading;
        __asm__ volatile("" : : : "$2", "memory");
        boost = 75;
        *(short*)((char*)playerVelocity + 176) = boost;
        if (heading >= 0) {
            __asm__ volatile("" : : "r"(boost));
            sign = 1;
        } else {
            __asm__ volatile("" : : "r"(boost));
            sign = -1;
        }
        *(short*)((char*)playerVelocity + 178) = sign;
        moby->updateDistance = 255;
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
        tag->timer = 60;
        moby->state = 3;
        break;
    case 3:
        if (func_800359A4(tag, 4)) {
            moby->angle.yaw = ((int)(DecodedPickupYaw << 16) >> 20) - 128;
            moby->angle.pitch = DecodedPickupPitch >> 4;
            moby->lowDrawDistance = 63;
            moby->updateDistance = 16;
            moby->state = 1;
        }
        break;
    }
}

void func_level_25_8007A654(Moby* moby) {
    func_80039714(moby);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Sources: level_15/moby/func_level_15_8007ACA0.s,
 * level_25/moby/func_level_25_8007A674.s,
 * level_35/moby/func_level_35_80079428.s,
 * level_45/moby/func_level_45_80079598.s.
 * All 204 instructions and six owned table/padding words per copy read.
 * Tag words at +0/+4; indexed Moby records have the original 88-byte stride.
 * Byte fields wrap as in retail. Helper argument four is stack+0x10;
 * its first output word is compared signed against 513.
 * Once per invocation. Helper semantics, output units, global producers and
 * caller cadence remain unresolved. Existing field names are not evidence.
 * Confidence: exact compiled words. Falsifiable vectors: every linked original
 * code/table word at the source addresses and every complete retail hash.
 * Empty constraints preserve register lifetimes without opcode patches.
 */
extern int D_8006C640;
extern int D_8006FA3C;
extern int D_8006FA44;
extern int D_8006FA74;
extern int D_8006FA78;

extern Moby* ControllerACA0Mobys __asm__("D_8006C550");
extern unsigned char ControllerACA0Player[] __asm__("D_80070328");
extern int (*ControllerACA0Test)(Moby*,void*,int,int*) __asm__("unk_ovlheader_8007439C");
void func_level_25_8007A674(Moby *argument) {
    register Moby* moby __asm__("$16")=argument;
    Vector3D helperOutput;
    register Moby *linkedMoby __asm__("$17");
    register Moby *nextLinkedMoby __asm__("$17");
    register int one __asm__("$5");
    register Moby* prepared __asm__("$4");
    register unsigned char* player __asm__("$5");
    int completedCount;
    unsigned char state;
    unsigned char nextState;
    register int *tag __asm__("$18");

    state = moby->state;
    tag = moby->mobyTag;
    switch (state) {
    case 0:
        if (D_8006FA3C != 2) {
            func_80055B18(moby);
            moby->lowDrawDistance = 0;
        } else {
            if (tag[1] != 0) {
                func_80034F80(moby, 0);
                moby->updateDistance = 0xFF;
                nextState = 2;
            } else {
                func_80034F80(moby, 1);
                moby->updateDistance = 0x10;
                nextState = 1;
            }
            moby->state = nextState;
            goto clearDistance;
        }
        goto clearDrawnFlag;
    default:
        return;
    case 1:
        moby->angle.roll += 8;
        return;
    case 2:
        { register int skip __asm__("$2")=D_8006C640<11;
          __asm__("" : "=r"(skip),"=r"(moby) : "0"(skip),"1"(moby) : "$4");
          prepared=moby;
          if(skip)goto sharedTest; }
        if(D_8006FA74<=0) {
            __asm__("" : : : "$4");
            prepared=moby;
            func_8003BABC(prepared,2,33);
            func_80034F80(moby,2);
            moby->state=3;
            goto prepareSharedTest;
        }
        if(D_8006FA74<61) {
            register int compare __asm__("$2")=1;
            register int current __asm__("$3");
            __asm__("" : "=r"(compare) : "0"(compare) : "$3");
            current=moby->animationState.id;
            __asm__("" : "=r"(current),"=r"(moby) : "0"(current),"1"(moby) : "$4");
            prepared=moby;
            if(current==compare)goto prepareSharedTest;
            func_8003BABC(prepared,1,33);
            func_80034F80(moby,1);
            prepared=moby;
            goto sharedTest;
        }
        { register int counter __asm__("$3")=D_8006FA74;
          register int skip __asm__("$2");
          __asm__("" : "=r"(counter) : "0"(counter) : "$2");
          skip=counter<121;
          __asm__("" : "=r"(skip),"=r"(moby) : "0"(skip),"1"(moby) : "$4");
          prepared=moby;
          if(!skip)goto sharedTest; }
        if((unsigned char)moby->lowDrawDistance>=63)goto sharedTest;
        func_8003BABC(prepared,1,33);
        moby->lowDrawDistance=63;
    case 3:
prepareSharedTest:
        prepared=moby;
sharedTest:
        { register int index __asm__("$3")=tag[0];
          register int offset __asm__("$2");
          register Moby* target __asm__("$3");
          __asm__("" : "=r"(index) : "0"(index));
          player=ControllerACA0Player;
          __asm__("" : "=r"(player) : "0"(player));
          offset=index*11;
          target=ControllerACA0Mobys;
          __asm__("" : "=r"(offset),"=r"(target) : "0"(offset),"1"(target));
          offset*=8;
          target=(Moby*)((char*)target+offset);
          target->lowDrawDistance=63; }
        moby->angle.roll += 8;
        if (ControllerACA0Test(prepared,player,0x1000,&helperOutput.x) != 0) {
            moby->state = 4;
            return;
        }
        if (helperOutput.x >= 0x201) {
            unk_ovlheader_80074374();
            D_8006FA44 = 3;
            return;
        }
        break;
    case 4:
        { register int zero5 __asm__("$5");
          register int zero6 __asm__("$6");
          prepared=moby;
          __asm__("" : "=r"(prepared) : "0"(prepared) : "$5","$3");
          zero5=0;
          __asm__("" : "=r"(prepared),"=r"(zero5) : "0"(prepared),"1"(zero5) : "$2","$3");
        { register int index __asm__("$3")=tag[0];
          register int offset __asm__("$2");
          register Moby* base __asm__("$3");
          __asm__("" : "=r"(index) : "0"(index) : "$6");
          zero6=0;
          __asm__("" : "=r"(index),"=r"(zero6) : "0"(index),"1"(zero6));
          offset=index*11;
          base=ControllerACA0Mobys;
          __asm__("" : "=r"(offset),"=r"(base) : "0"(offset),"1"(base));
          offset*=8;
          linkedMoby=(Moby*)((char*)base+offset); }
        func_8003BABC(prepared, zero5, zero6); }
        if (tag[1] != 0) {
            { register int* count __asm__("$2")=&D_8006FA78;
              register int incremented __asm__("$3");
              __asm__("" : "=r"(count) : "0"(count));
              incremented=*count+1;
              *count=incremented;
              __asm__("" : "=r"(incremented) : "0"(incremented));
              completedCount=incremented; }
            if (completedCount == 4) {
                unk_ovlheader_80074374();
            }
        }
        linkedMoby->updateDistance = 0xFF;
        linkedMoby->state = 3;
        func_80034F80(linkedMoby, 2);
        { register int index __asm__("$3")=*(int*)linkedMoby->mobyTag;
          register int offset __asm__("$2");
          register Moby* base __asm__("$3");
          __asm__("" : "=r"(index) : "0"(index) : "$5");
          one=1;
          __asm__("" : "=r"(one),"=r"(index) : "0"(one),"1"(index));
          offset=index*11;
          base=ControllerACA0Mobys;
          __asm__("" : "=r"(offset),"=r"(base) : "0"(offset),"1"(base));
          offset*=8;
          nextLinkedMoby=(Moby*)((char*)base+offset); }
        nextLinkedMoby->lowDrawDistance = 0x3F;
        func_80034F80(nextLinkedMoby, one);
        moby->state = 1;
        moby->updateDistance = 0x10;
        goto clearDistance;
    }
    return;
clearDistance:
    moby->lowDrawDistance=0;
clearDrawnFlag:
    moby->drawn=0;
}


/* Retail path records have 16-byte point stride and a signed halfword count. */
typedef struct {
    Vector3D position;
    int reserved0C;
} DecodedChainPoint;
typedef struct {
    short count;
    unsigned char reserved02[10];
    DecodedChainPoint* points;
} DecodedChainPath;
typedef struct {
    DecodedChainPath* path;
    int pointIndex;
} DecodedChainTag;
extern int D_8006FA3C, D_8006FA80, D_8006C648;
extern unsigned short DecodedChainYaw __asm__("D_8006E040");
extern unsigned short DecodedChainPitch __asm__("D_8006E03E");
void DecodedChainFindPoint(Vector3D*, DecodedChainPath*, int*) __asm__("func_80036518");
void func_80055B18(Moby*);
void func_level_25_8007A9A4(Moby* moby) {
    DecodedChainTag* tag = moby->mobyTag;
    DecodedChainTag* childTag;
    Moby* child;
    int pointIndex, index;
    register int elapsed __asm__("$4");
    register int difference __asm__("$3");
    register int count __asm__("$4");
    int packedCount;
    register int alpha __asm__("$4");
    register int rawAlpha __asm__("$2");
    register int step __asm__("$3");
    register int encodedAlpha __asm__("$2");
    switch (moby->state) {
    case 0:
        if (D_8006FA3C != 2) { func_80055B18(moby); break; }
        DecodedChainFindPoint(&moby->position, tag->path, &pointIndex);
        tag->pointIndex = pointIndex;
        for (index = 1; index < 10; index++) {
            pointIndex += 3;
            child = SpawnMoby(0x16B, moby);
            if (child) {
                childTag = child->mobyTag;
                childTag->pointIndex = pointIndex;
                childTag->path = tag->path;
                func_8004F178(&child->position, &tag->path->points[childTag->pointIndex].position);
                child->lowDrawDistance = moby->lowDrawDistance;
                child->highDrawDistance = moby->highDrawDistance;
                child->updateDistance = 255;
                child->state = 1;
            }
        }
        moby->state = 1;
        break;
    case 1:
        moby->angle.yaw = ((int)(DecodedChainYaw << 16) >> 20) - 128;
        moby->angle.pitch = DecodedChainPitch >> 4;
        elapsed = D_8006FA80;
        if (elapsed < 0) break;
        elapsed = (elapsed + 1) % tag->path->count;
        __asm__ volatile("" : "=r"(elapsed) : "0"(elapsed) : "memory");
        difference = (tag->pointIndex - elapsed + tag->path->count) % tag->path->count;
        __asm__ volatile("" : "=r"(difference) : "0"(difference) : "memory");
        /* Preserve the independent count read and both original stack stores. */
        packedCount = (unsigned short)tag->path->count << 16;
        pointIndex = elapsed;
        __asm__ volatile("" : : : "memory");
        count = packedCount >> 16;
        pointIndex = difference;
        __asm__("" : "=r"(count) : "0"(count));
        if (difference >= (packedCount >> 17)) {
            tag->pointIndex = (tag->pointIndex + 30) % count;
            moby->state = 2;
        }
        break;
    case 2:
        /* Empty constraints preserve original byte loads and compiler registers. */
        rawAlpha = ((unsigned char*)&moby->colour)[3];
        step = D_8006C648;
        alpha = (rawAlpha & 15) + step;
        __asm__("" : "=r"(alpha) : "0"(alpha), "r"(rawAlpha), "r"(step));
        if (alpha >= 16) {
            *(unsigned int*)&moby->colour = 0;
            func_8004F178(&moby->position, &tag->path->points[tag->pointIndex].position);
            moby->state = 1;
        } else {
            ((unsigned char*)&moby->colour)[0] = 0;
            ((unsigned char*)&moby->colour)[1] = 0;
            ((unsigned char*)&moby->colour)[2] = 0;
            encodedAlpha = alpha | 48;
            ((unsigned char*)&moby->colour)[3] = encodedAlpha;
            __asm__ volatile("" : "=r"(encodedAlpha) : "0"(encodedAlpha));
        }
        moby->angle.yaw = ((int)(DecodedChainYaw << 16) >> 20) - 128;
        moby->angle.pitch = DecodedChainPitch >> 4;
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
extern int F4865Gate __asm__("D_8006FA3C"),F4865Position __asm__("D_8006FA80"),F4865Mode __asm__("D_8006E044");
extern unsigned short F4865E040 __asm__("D_8006E040"),F4865E03E __asm__("D_8006E03E");
extern unsigned char F4865PlayerE __asm__("D_80070328 + 0xE"),F4865Player12 __asm__("D_80070328 + 0x12"),F4865PlayerD __asm__("D_80070328 + 0xD");
extern unsigned char F4865Player[] __asm__("D_80070328");
extern unsigned char* F4865Array __asm__("D_8006C550"),*F4865ArrayEnd __asm__("D_8006C704");
extern int F4865W20C __asm__("D_80070328 + 0x20C"),F4865W170 __asm__("D_80070328 + 0x170");
extern void* F4865W218 __asm__("D_80070328 + 0x218");
extern int (*F4865CallbackA0)() __asm__("unk_ovlheader_800743A0");
extern int (*F4865Callback24)() __asm__("unk_ovlheader_80074324");
int F4865func_80049484() __asm__("func_80049484");
void* F4865func_8002F540() __asm__("func_8002F540");
int F4865rand() __asm__("rand");
#define F4865Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int F4865func_80013E38() __asm__("func_80013E38");
int F4865func_8001830C() __asm__("func_8001830C");
int F4865func_80018368() __asm__("func_80018368");
void *F4865func_8001BA30() __asm__("func_8001BA30");
int F4865func_800359A4() __asm__("func_800359A4");
int F4865func_8003BABC() __asm__("func_8003BABC");
int F4865func_8003BE70() __asm__("func_8003BE70");
int F4865func_8003BFC0() __asm__("func_8003BFC0");
int F4865func_8003C0B0() __asm__("func_8003C0B0");
int F4865func_80040954() __asm__("func_80040954");
int F4865func_8004E880() __asm__("func_8004E880");
int F4865func_8004ED6C() __asm__("func_8004ED6C");
int F4865func_8004EDE8() __asm__("func_8004EDE8");
int F4865func_8004F0E8() __asm__("func_8004F0E8");
int F4865func_8004F110() __asm__("func_8004F110");
int F4865func_8004F178() __asm__("func_8004F178");
int F4865func_8004F194() __asm__("func_8004F194");
int F4865func_8004F1C8() __asm__("func_8004F1C8");
int F4865func_8004F334() __asm__("func_8004F334");
int F4865func_80055B18() __asm__("func_80055B18");
int F4865func_80055D24() __asm__("func_80055D24");
extern unsigned char F4865D_800658A0[] __asm__("D_800658A0");
extern unsigned char F4865D_80065920[] __asm__("D_80065920");
extern int F4865D_8006C574 __asm__("D_8006C574");
extern int F4865D_8006C578 __asm__("D_8006C578");
extern unsigned char F4865D_8006D048[] __asm__("D_8006D048");
extern void *F4865D_8006E788 __asm__("D_8006E788");
extern int F4865D_80071924 __asm__("D_80071924");
extern void *(*F4865SpawnMoby)() __asm__("SpawnMoby");
extern int (*F4865SpawnParticle)() __asm__("SpawnParticle");
void func_level_25_8007ACBC(void *arg0) {
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
    register unsigned char* scanPosition __asm__("$21");
    void *temp_a0_2;
    void *linkedObject00;
    register void *privateState __asm__("$20");
    register void *ownerVector0C __asm__("$23");
    register void *queriedObject __asm__("$17");
    register void *temp_v0_2 __asm__("$16");
    register void *temp_v0_3 __asm__("$16");
    void *temp_v1_6;
    register void *scannedObject __asm__("$22");

    owner = arg0;
    ownerState48 = F4865Field(owner, unsigned char *, 0x48);
    privateState = F4865Field(owner, void **, 0);
    switch (ownerState48) {

    case 0:
        if(F4865Gate!=2)goto removeOwner;
        temp_v0_2=F4865Field(owner,void**,0);
        result2=F4865Field(temp_v0_2,short*,0x14);
        if(result2){
            tableIndex4=F4865Field(temp_v0_2,short*,0x16);
            if(tableIndex4){
                work3=F4865Position;
                if(result2>=work3)goto outside0;result2=work3<tableIndex4;work3=1;if(!result2)goto outside0;{F4865Field(owner,unsigned char*,0x41)=0;F4865Field(owner,unsigned char*,0x4C)=0;F4865Field(owner,unsigned char*,0x4D)=0;}
                goto afterFlags0;outside0:work3=1;result2=63;{F4865Field(owner,unsigned char*,0x41)=work3;F4865Field(owner,unsigned char*,0x4C)=result2;F4865Field(owner,unsigned char*,0x4D)=work3;}afterFlags0:;
            }
        }
        result2=F4865E040;result2=((int)((unsigned)result2<<16)>>20)-128;F4865Field(owner,unsigned char*,0x46)=result2;
        result2=F4865E03E;F4865Field(owner,unsigned char*,0x45)=(unsigned)result2>>4;
        {register unsigned char* child4 __asm__("$4");
         child4=F4865Field(temp_v0_2,unsigned char**,0);
         if(!child4){F4865Field(temp_v0_2,void**,0)=F4865SpawnMoby(364,owner);return;}
         if(child4[72]!=4){F4865Field(temp_v0_2,int*,16)=30;F4865Field(temp_v0_2,void**,0)=0;F4865Field(owner,unsigned char*,72)=6;return;}
         child4[70]=F4865Field(owner,unsigned char*,70)+128;
         result2=F4865Field(owner,unsigned char*,69);work3=(int)F4865Field(temp_v0_2,void**,0);F4865Field((void*)work3,unsigned char*,69)=-result2;return;
        }
    case 1:
        F4865Field(owner,unsigned char*,76)=0;F4865Field(owner,unsigned char*,77)=0;
        F4865func_8004F178(owner+12,F4865Player);return;
    case 2:
        F4865Field(owner,unsigned char*,76)=63;F4865func_80049484(owner+12);
        result2=F4865PlayerE;work3=F4865Player12;F4865Field(owner,unsigned char*,70)=result2+work3;
        if(F4865Mode==7){result2=F4865E03E;result2=-((int)((unsigned)result2<<16)>>20);F4865Field(owner,unsigned char*,69)=result2;result2=F4865E040;F4865Field(owner,unsigned char*,70)=(unsigned)result2>>4;}
        else F4865Field(owner,unsigned char*,69)=F4865PlayerD;
        bestScore=0x10000;__asm__("" : "=r"(bestScore):"0"(bestScore));
        scannedObject=F4865Array;result2=(unsigned)scannedObject<(unsigned)F4865ArrayEnd;__asm__("" ::: "memory");bestScore |= 0x869F;
        F4865Field(privateState, void **, 0) = 0;
        if (result2) {
            ownerVector0C = owner + 0xC;
            scanPosition=scannedObject+12;
            do {
                if (!(F4865Field(scanPosition, unsigned char *, 0x3C) & 0x80) && (F4865Field(scanPosition, int *, -4) != 0)) {
                    F4865func_8004F178(&frame.sp18, scanPosition);
                    frame.sp20 += 0x80;
                    wrappedDifference46 = (F4865func_8004E880(frame.sp18 - F4865Field(owner, int *, 0xC), frame.sp1C - F4865Field(owner, int *, 0x10), 0) - F4865Field(owner, unsigned char *, 0x46)) & 0xFF;
                    if (wrappedDifference46 >= 0x81) {
                        wrappedDifference46 -= 0x100;
                    }
                    wrappedDifference45 = (F4865func_8004E880(F4865func_8004F334(ownerVector0C, &frame.sp18), frame.sp20 - F4865Field(owner, int *, 0x14), 0) - F4865Field(owner, unsigned char *, 0x45)) & 0xFF;
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
                        distanceScore = 0x2800 - F4865func_8004F334(ownerVector0C, &frame.sp18);
                        absoluteDistanceScore = distanceScore;
                        if (distanceScore < 0) {
                            absoluteDistanceScore = -absoluteDistanceScore;
                        }
                        result2 = (wrappedDifference46 + wrappedDifference45) << 10;
                        __asm__("" : "=r"(result2) : "0"(result2));
                        combinedScore = absoluteDistanceScore + result2;
                        if ((combinedScore < bestScore) && (F4865func_80013E38(ownerVector0C, &frame.sp18, 4) != 0)) {
                            F4865Field(privateState, void **, 0) = scannedObject;
                            bestScore = combinedScore;
                        }
                    }
                }
                result2=(int)F4865ArrayEnd;scannedObject+=88;result2=(unsigned)scannedObject<(unsigned)result2;scanPosition+=88;
            } while (result2);
        }
        if (bestScore == 0x1869F) {
            F4865Field(privateState, void **, 0) = 0;
        }
        initWord2 = F4865Field(owner, unsigned char *, 0x44) << 4;
        __asm__("" : "=r"(initWord2) : "0"(initWord2));
        F4865Field(privateState, short *, 4) = initWord2;
        initWord2 = F4865Field(owner, unsigned char *, 0x45) << 4;
        __asm__("" : "=r"(initWord2) : "0"(initWord2));
        F4865Field(privateState, short *, 6) = initWord2;
        phaseByte3 = F4865Field(owner, unsigned char *, 0x46);
        initWord2 = 0xB4;
        F4865Field(privateState, short *, 0xE) = initWord2;
        initWord2 = -1;
        F4865Field(privateState, int *, 0x10) = initWord2;
        __asm__("" : : : "memory");
        initWord2 = 3;
        F4865Field(privateState, short *, 0xA) = 0;
        F4865Field(privateState, short *, 0xC) = 0;
        F4865Field(privateState, short *, 8) = phaseByte3 << 4;
        F4865Field(owner, unsigned char *, 0x48) = initWord2;
    case 3:
        if(F4865Field(owner,int*,12)<1024 || F4865Field(owner,int*,16)<1024 || F4865Field(owner,int*,20)<1024 || ((result2=F4865func_800359A4(privateState+14,2)),(stackArg4=&frame.sp28),result2)) {
            if (F4865func_8003BFC0(owner, F4865Field(privateState, int *, 0x10)) != 0) {
                F4865func_8003BE70(F4865Field(privateState, int *, 0x10));
            }
            goto block_93;
        }
        __asm__("" : "=r"(owner) : "0"(owner));
        savedOwnerVector0C = owner + 0xC;
        F4865func_8004F178(stackArg4, savedOwnerVector0C);
        if (F4865Field(F4865Field(privateState, void **, 0), unsigned char *, 0x48) & 0x80) {
            F4865Field(privateState, void **, 0) = 0;
        }
        linkedObject00 = F4865Field(privateState, void **, 0);
        if (linkedObject00 != 0) {
            F4865func_8004F178(&frame.sp48, linkedObject00 + 0xC);
            frame.sp50 += 0x80;
            vector38 = &frame.sp38;
            F4865func_8004F1C8(vector38, &frame.sp48, savedOwnerVector0C);
            frame.sp40 += 0x100;
            F4865func_8004E880(frame.sp38, frame.sp3C, 1);
            result2 = F4865func_8004E880(frame.sp38, frame.sp3C, 1);
            halfword3 = F4865Field(privateState, short *, 8);
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
                result2 = F4865Field(privateState, short *, 0xE);
                upperStep = work3-result2;
                lowerStep = -upperStep;
                if (upperStep >= 65) {
                    upperStep = 64;
                    __asm__("" : "=r"(upperStep) : "0"(upperStep));
                    lowerStep = -upperStep;
                }
                if (wrappedDifference08 < lowerStep) wrappedDifference08 = lowerStep;
                if (upperStep < wrappedDifference08) wrappedDifference08 = upperStep;
                F4865Field(privateState, short *, 8) = (short) (previousHalfword08 + wrappedDifference08);
                result2 = F4865func_8004EDE8(vector38, 0, wrappedDifference08, previousHalfword08);
                result2 = F4865func_8004E880(result2, frame.sp40, 1);
                previousHalfword06 = F4865Field(privateState, short *, 6);
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
                    F4865Field(privateState, short *, 6) = updatedHalfword06;
                } else {
                    goto block_63;
                }
            } else {
block_63:
                F4865Field(privateState, void **, 0) = 0;
            }
        }
        F4865Field(owner, unsigned char *, 0x44) = (unsigned char) ((unsigned short) F4865Field(privateState, unsigned short *, 4) >> 4);
        F4865Field(owner, unsigned char *, 0x45) = (unsigned char) ((unsigned short) F4865Field(privateState, short *, 6) >> 4);
        F4865Field(owner, unsigned char *, 0x46) = (unsigned char) ((unsigned short) F4865Field(privateState, short *, 8) >> 4);
        F4865func_80055D24(owner, 4);
        frame.sp38 = 0x300;
        frame.sp3C = 0;
        frame.sp40 = 0;
        F4865func_8004ED6C(owner + 0x20, &frame.sp38, &frame.sp38);
        ownerVectorArgument = owner + 0xC;
        F4865func_8004F194(ownerVectorArgument, ownerVectorArgument, &frame.sp38);
        savedVector28 = &frame.sp28;
        if (F4865func_8001830C(savedVector28, ownerVectorArgument, 0, 0x10000, owner) != 0) {
            F4865func_8004F178(ownerVectorArgument, savedVector28);
            goto block_71;
        }
        queriedObject = F4865func_8001BA30(ownerVectorArgument, 0x200, 1, 0, 0, owner);
        if (queriedObject != 0) {
            F4865func_8004F178(&frame.sp58, queriedObject + 0xC);
            frame.sp60 += 0x80;
            if (F4865func_80018368(ownerVectorArgument, &frame.sp58) == 0) {
                F4865Field(queriedObject, int *, 0x18) = (int) (F4865Field(queriedObject, int *, 0x18) | 0x10000);
block_71:
                F4865Field(owner, unsigned char *, 0x48) = 5U;
            }
        }
        if (F4865func_8003BFC0(owner, F4865Field(privateState, int *, 0x10)) == 0) {
            F4865Field(privateState, int *, 0x10) = F4865func_8003BABC(owner, 0, 4);
        } else {
            /* Keep the original division constant before the signed load. */
            signedDivision180Magic = (int)0xB60B60B7;
            __asm__("" : "=r"(privateState) : "0"(privateState), "r"(signedDivision180Magic));
            halfword3 = F4865Field(privateState, short *, 0xE);
            result2 = (int)((unsigned int)(0xB4 - halfword3) << 13);
            work3 = result2 / 180;
            __asm__("" : "=r"(work3) : "0"(work3));
            result2 = 0x1000;
            __asm__("" : "=r"(result2) : "0"(result2));
            scaledWord16 = result2 - work3;
            if (scaledWord16 < 0xA00) {
                scaledWord16 = 0xA00;
            }
            F4865func_8003C0B0(F4865Field(privateState, int *, 0x10), scaledWord16);
        }
        F4865func_8004F110(&frame.sp38, 2);
        F4865SpawnParticle(1, 0x37, owner + 0xC, &frame.sp38);
        return;

    case 4:
        result2=F4865Field(owner,unsigned char*,58);
        work3=result2*88;result2=(int)F4865Array;result2+=work3;__asm__("" : "=r"(result2):"0"(result2));result2=F4865Field((void*)result2,unsigned char*,76);
        globalWordAddress16=&frame.sp68;
        if(result2){
            stackArg4=globalWordAddress16;__asm__("" : "=r"(stackArg4):"0"(stackArg4));temp_s1_3=(int*)F4865Player;
            F4865Field(owner,unsigned char*,76)=result2;
            F4865func_8004F1C8(stackArg4,temp_s1_3,owner+12);
            F4865func_8004EDE8(globalWordAddress16,1);
            if(F4865W20C&0x10000000)return;
            if(F4865W170)return;
            if(!F4865CallbackA0(owner,temp_s1_3,1536))return;
            F4865func_8003BABC(owner,2,0);
            result2=0x10001000;F4865W20C=result2;result2=1;F4865W218=owner;F4865Field(owner,unsigned char*,72)=result2;return;
        }
        idle6:__asm__ volatile("" ::: "memory");F4865Field(owner,unsigned char*,65)=0;F4865Field(owner,unsigned char*,76)=0;F4865Field(owner,unsigned char*,77)=0;return;
    case 5:
        temp_s1_3=owner+12;
        temp_v0_2=F4865func_8001BA30(temp_s1_3,1024,1,0,0,owner);
        if(temp_v0_2 && !F4865func_80018368(temp_s1_3,temp_v0_2+12))F4865Field(temp_v0_2,int*,24)|=0x10000;
        if(F4865func_8003BFC0(owner,F4865Field(privateState,int*,16)))F4865func_8003BE70(F4865Field(privateState,int*,16));
        F4865func_8003BABC(owner,1,0);F4865Callback24(owner,-1);removeOwner:F4865func_80055B18(owner);return;
    case 6:
        temp_v0_2=F4865Field(owner,void**,0);
        result2=F4865E040;result2=((int)((unsigned)result2<<16)>>20)-128;F4865Field(owner,unsigned char*,70)=result2;
        result2=F4865E03E;F4865Field(owner,unsigned char*,69)=(unsigned)result2>>4;
        if(F4865func_800359A4(temp_v0_2+16,4)){
            var_s1_3=0;stackArg4=temp_v0_2;__asm__("" : "=r"(stackArg4):"0"(stackArg4));do{F4865Field(F4865Field(stackArg4,void**,4),unsigned char*,28)=0;F4865Field(stackArg4,void**,4)=0;var_s1_3++;stackArg4+=4;}while(var_s1_3<3);
            F4865Field(owner,unsigned char*,72)=0;return;
        }
        var_s2_2=F4865rand()&255;privateState=F4865D_80065920;var_s1_3=0;
        do{
            if(!F4865Field(temp_v0_2,void**,4)){
                result2=(int)F4865func_8002F540(4,1,0x608080);__asm__("" : "=r"(result2):"0"(result2));F4865Field(temp_v0_2,void**,4)=(void*)result2;
                if(!result2)goto angleIncrement;{
                    F4865Field((void*)result2,int*,0)=0;
                    tableIndex4=var_s2_2*2;tablePointer2=(short*)((long)tableIndex4+(long)privateState);tableHalfword3=*tablePointer2;__asm__("" : "=r"(tableHalfword3):"0"(tableHalfword3));result2=tableHalfword3*3;__asm__("" : "=r"(result2):"0"(result2));
                    work3=(int)F4865Field(temp_v0_2,void**,4);result2>>=3;F4865Field((void*)work3,int*,4)=result2;
                    tableHalfword3=F4865Field(F4865D_800658A0+tableIndex4,short*,0);__asm__("" : "=r"(tableHalfword3):"0"(tableHalfword3));result2=tableHalfword3*3;__asm__("" : "=r"(result2):"0"(result2));
                    work3=(int)F4865Field(temp_v0_2,void**,4);result2>>=3;F4865Field((void*)work3,int*,8)=result2;
                    linkedObject00=F4865Field(temp_v0_2,void**,4);F4865func_8004ED6C(owner+32,linkedObject00,linkedObject00);
                    stackArg4=F4865Field(temp_v0_2,void**,4);F4865func_8004F194(stackArg4,stackArg4,owner+12);
                }
            }
            if(F4865Field(temp_v0_2,void**,4))F4865func_8004F178(F4865Field(temp_v0_2,unsigned char**,4)+12,F4865Player);
            angleIncrement:result2=var_s2_2+85;__asm__("" : "=r"(result2):"0"(result2));var_s2_2=result2&255;var_s1_3++;temp_v0_2+=4;
        }while(var_s1_3<3);
    }
    return;
block_93:
    goto removeOwner;
}
#undef F4865Field


extern int D_8006FA3C,D_8006FA78,D_8006C640;
void func_level_25_8007B78C(Moby* actor) {
    Moby** tag=actor->mobyTag;
    Moby* child;
    Vector3D childPoint,parentPoint;
    switch(actor->state) {
    case 0:case 1:
        actor->lowDrawDistance=(*tag)->lowDrawDistance;
        if(!actor->lowDrawDistance)actor->drawn=0;
        break;
    case 2:
        switch(actor->substate) {
        case 0:
            if(D_8006FA3C!=2){func_80055B18(actor);break;}
            child=SpawnMoby(0x17F,actor);
            if(child) {
                func_80034F80(child,0);child->state=0;
                func_80055F14(child,0,&childPoint);func_80055F14(actor,0,&parentPoint);
                func_8004F1C8(&childPoint,&parentPoint,&childPoint);
                func_8004F194(&child->position,&child->position,&childPoint);
            }
            child=SpawnMoby(0x17F,actor);
            if(child) {
                func_80034F80(child,1);child->state=1;
                func_80055F14(child,1,&childPoint);func_80055F14(actor,1,&parentPoint);
                func_8004F1C8(&childPoint,&parentPoint,&childPoint);
                func_8004F194(&child->position,&child->position,&childPoint);
            }
            actor->substate=1;break;
        case 1:
            if(D_8006FA78==3 && D_8006C640>=0xB) {actor->lowDrawDistance=0x3F;actor->substate=2;}
            break;
        }
        break;
    }
}

/* SCUS-94467 USA Rev 0, 0x8007B974: 228 instructions and eight owned table words.
 * Linked Moby indices use an 88-byte stride, followed by pointer loads at
 * offsets 0 and 0x24 and a signed halfword load at offset 2.
 * The stack Vector3D occupies original offsets 0x20 through 0x28.
 * Helper semantics, position units and caller cadence remain unresolved.
 * Empty constraints preserve compiler allocation/order without CPU instructions.
 * AI generated; not human reviewed. */
#define P7B974_FIELD(type,base,offset) (*(type*)((unsigned char*)(base)+(offset)))
extern int D_8006FA3C,D_8006C770;
extern Moby *D_8006C550;
int P7B974Query(Vector3D*,int) __asm__("func_8001A358");
void func_level_25_8007B974(Moby *input) {
    register Moby *owner __asm__("$17")=input;
    Vector3D position20;
    register int one __asm__("$18");
    int threshold8;
    int finalThreshold8;
    int value2;
    int queryResult;
    register int stateArgument5 __asm__("$5");
    register Moby *call4 __asm__("$4");
    unsigned char substate;
    register void *privateState __asm__("$16");

    substate = owner->substate;
    privateState = owner->mobyTag;
    switch (substate) {
    case 0:
        if (D_8006FA3C == 3) {
            if (P7B974_FIELD(int,privateState,4) != 0) {
                owner->unknown3[0] = 0;
                owner->lowDrawDistance = 0;
                owner->drawn = 0;
                owner->unknownCollision = 0;
                owner->updateDistance = 0xFF;
            }
            owner->substate = 1;
            return;
        }
        goto deleteOwner;
    case 1:
        if (P7B974_FIELD(short,P7B974_FIELD(void *,D_8006C550[P7B974_FIELD(int,privateState,0)].mobyTag,0x24),2) >= P7B974_FIELD(int,privateState,4)) {
            one=1;
            owner->unknown3[0] = one;
            owner->lowDrawDistance = 0x3F;
            owner->drawn = one;
            func_80055D24(owner, 1);
            if (P7B974_FIELD(int,privateState,0xC) != 0) {
                owner->state = one;
                func_80034F40(owner, 1);
            }
            owner->substate = 2;
            return;
        }
    default:
        return;
    case 2:
        if (owner->damageFlags & 0x10000000) {
            owner->state = 3;
            func_80034F40(owner, 3);
            owner->substate = 3;
            return;
        }
        threshold8 = P7B974_FIELD(int,privateState,8);
        if ((threshold8 == 0) || (P7B974_FIELD(short,P7B974_FIELD(void *,D_8006C550[P7B974_FIELD(int,privateState,0)].mobyTag,0x24),2) < threshold8)) {
            if (owner->state == 1) {
                func_80035A80(owner, P7B974_FIELD(int,privateState,0xC), 0x200, 0x80, 0, 8, 0xC, 5);
                return;
            }
        } else {
            goto deleteOwner;
        }
        break;
    case 3:
        if ((owner->state == 3) && (D_8006C770 != 0)) {
            func_800498C0();
            owner->state = 0;
            goto resetState;
        }
        break;
    case 4:
        if (owner->state != 2) {
            owner->state = 2;
            func_80034F40(owner, 2);
        }
        P7B974_FIELD(int,privateState,0x10) = 0;
        return;
    case 5:
        value2 = P7B974_FIELD(int,privateState,0x10) + 8;
        P7B974_FIELD(int,privateState,0x10) = value2;
        if (value2 >= 0x101) {
            P7B974_FIELD(int,privateState,0x10) = 0x100;
        }
        func_8004F178(&position20, &owner->position);
        position20.z += 0x400;
        queryResult = P7B974Query(&position20, P7B974_FIELD(int,privateState,0x10) + 0x420);
        if (queryResult != 0) {
            owner->position.z = queryResult;
            owner->state = 0;
            func_80034F40(owner, 0);
            owner->substate = 6;
            return;
        }
        owner->position.z -= P7B974_FIELD(int,privateState,0x10);
        if (owner->state != 2) {
            owner->state = 2;
            call4=owner;
            stateArgument5 = 2;
            goto changeState;
        }
        break;
    case 6:
        finalThreshold8=P7B974_FIELD(int,privateState,8);
        if(finalThreshold8!=0) {
            value2=P7B974_FIELD(short,P7B974_FIELD(void*,D_8006C550[P7B974_FIELD(int,privateState,0)].mobyTag,0x24),2);
            if(value2<finalThreshold8)goto resetCheck;
        }else goto resetCheck;
deleteOwner:
        func_80055B18(owner);
        return;
resetCheck:
        if(owner->state!=0) {
            owner->state=0;
            goto resetState;
        }
        break;
    }
    return;
resetState:
    call4=owner;
    stateArgument5=0;
changeState:
    __asm__("" : : "r"(call4), "r"(stateArgument5));
    func_80034F40(call4,stateArgument5);
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007BD04.
* AI generated; not human reviewed. All704 original instructions and every
* actual branch/call/internal destination require native/linked identity.
* Frame98 retains S0..S5/RA and original SP18..77 workspace. The union keeps
* original full LW SP18/SP1C and later SH SP18/SP1A/SP1C views. No padding
* content is read. Paired13/shift5 and39/shift6 samples retain signed table
* widths,late zero stores,original pointers and helper order. Original
* timer words,descriptor index16 stride and filter producer/consumer order
* remain exact. Complete signed remainder retains all original traps.
* Fixed A0 phases are scoped separately from the ordinary shared SP28
* pointer;path-call values and shared-frame values have disjoint lifetimes.
* This retains original independent stack-address producers359/384 without
* a cached S5 address. Original591/607 enter already-prepared595/611 and
* skip only the duplicate upper comparison;every actual target is checked.
* Empty metadata reads complete initialized words/addresses or clobbers
* only dead values before fresh full producers;zero CPU instructions.
* Compiler/filter/flags unchanged;no opcode asm,fixedFP,partialHI,undefined
* saved inputs or overlapping live fixed aliases. Known helper views reuse
* EXE/header evidence. Units/fixed point,complete helper/caller chains,
* cadence beyond invocation and synchronized retail runtime remain open.
* Confidence is binary identity after all gates. Next:human review and
* retail captures. Falsification:every native/linked word,actual target,
* owned data and full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 26df0cdc122c16aae2e58b05508c987e9e2660ebc6f76b32cd57750e588b9ad3 */
#define Level25_7BD04Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level25_7BD04Call359A4View1(void*, int) __asm__("func_800359A4");
int Level25_7BD04Call35D38View1() __asm__("func_80035D38");
int Level25_7BD04Call37BBCView1() __asm__("func_80037BBC");
int Level25_7BD04Call3B74CView1() __asm__("func_8003B74C");
int Level25_7BD04Call3B7B4View1() __asm__("func_8003B7B4");
int Level25_7BD04Call3BABCView1() __asm__("func_8003BABC");
int Level25_7BD04Call3BFC0View1() __asm__("func_8003BFC0");
int Level25_7BD04Call40F48View1() __asm__("func_80040F48");
int Level25_7BD04Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level25_7BD04Call4ECF4View1() __asm__("func_8004ECF4");
int Level25_7BD04Call4ED6CView1() __asm__("func_8004ED6C");
int Level25_7BD04Call4EDE8View1() __asm__("func_8004EDE8");
int Level25_7BD04Call4F178View1() __asm__("func_8004F178");
int Level25_7BD04Call4F194View1() __asm__("func_8004F194");
int Level25_7BD04Call4F1C8View1() __asm__("func_8004F1C8");
int Level25_7BD04Call4F334View1() __asm__("func_8004F334");
int Level25_7BD04Call4F408View1() __asm__("func_8004F408");
int Level25_7BD04Call4F6C4View1() __asm__("func_8004F6C4");
int Level25_7BD04Call512E4View1() __asm__("func_800512E4");
int Level25_7BD04Call55B18View1() __asm__("func_80055B18");
int Level25_7BD04Call55D24View1() __asm__("func_80055D24");
int Level25_7BD04Call5629CView1() __asm__("func_8005629C");
extern int Level25_7BD04Data658A0View1 __asm__("D_800658A0");
extern int Level25_7BD04Data65920View1 __asm__("D_80065920");
extern int Level25_7BD04Data6C574View1 __asm__("D_8006C574");
extern int Level25_7BD04Data6C578View1 __asm__("D_8006C578");
extern int Level25_7BD04Data6C598View1 __asm__("D_8006C598");
extern unsigned char Level25_7BD04Data6C62CView1 __asm__("D_8006C62C");
extern int Level25_7BD04Data6C648View1 __asm__("D_8006C648");
extern unsigned char Level25_7BD04Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level25_7BD04Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level25_7BD04Data6D088View1 __asm__("D_8006D088");
extern unsigned short Level25_7BD04Data6E03CView1 __asm__("D_8006E03C");
extern unsigned short Level25_7BD04Data6E03EView1 __asm__("D_8006E03E");
extern unsigned short Level25_7BD04Data6E040View1 __asm__("D_8006E040");
extern int Level25_7BD04Data6E160View1 __asm__("D_8006E160");
extern int Level25_7BD04Data6E164View1 __asm__("D_8006E164");
extern int Level25_7BD04Data6E344View1 __asm__("D_8006E344");
extern int Level25_7BD04Data6E538View1 __asm__("D_8006E538");
extern int Level25_7BD04Data6EE2CView1 __asm__("D_8006EE2C");
extern int Level25_7BD04Data6FA40View1 __asm__("D_8006FA40");
extern int Level25_7BD04Data6FA48View1 __asm__("D_8006FA48");
extern int Level25_7BD04Data6FA50View1 __asm__("D_8006FA50");
extern int Level25_7BD04Data6FA54View1 __asm__("D_8006FA54");
extern int Level25_7BD04Data70328View1 __asm__("D_80070328");
extern int Level25_7BD04Data714F4View1 __asm__("D_800714F4");
extern unsigned char Level25_7BD04Data7159AView1 __asm__("D_8007159A");
extern void*(*Level25_7BD04DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern int(*Level25_7BD04Data743ECView1)() __asm__("unk_ovlheader_800743EC");
void func_level_25_8007BD04(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4, argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), retainedOriginalDataBase21 __asm__("$21");
    register void *ownerRecord20 __asm__("$20");
    register int privateRecord19 __asm__("$19"), retainedStateByteOrPosition16 __asm__("$16"), retainedDataVectorOrMatrix17 __asm__("$17"), retainedDescriptorIndexOrPlayerBase18 __asm__("$18");
    struct{
        union{
            int vector[3];
            struct{
                unsigned short half18;
                short half1A, half1C, pad1E;
                int word20;
            }
            packed;
        }
        at18;
        int sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74;
    }
    originalFrame;
    int temporaryWord1;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord2;
    int temporaryWord3;
    rawWord2 = Level25_7BD04Data7159AView1;
    ownerRecord20 = ownerParameter;
    __asm__ volatile("":"=r"(ownerRecord20):"0"(ownerRecord20));
    privateRecord19 = Level25_7BD04Field(ownerRecord20, void **, 0);
    if (rawWord2 != 0){
        rawWord2 = 255;
        __asm__ volatile(""::"r"(rawWord2));
        Level25_7BD04Call55B18View1(ownerParameter);
        return;
    }
    rawWord2 = 255;
    rawWord3 = Level25_7BD04Field(ownerRecord20, unsigned char*, 72);
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    retainedStateByteOrPosition16 = 1;
    __asm__("":"=r"(retainedStateByteOrPosition16):"0"(retainedStateByteOrPosition16));
    Level25_7BD04Field(ownerRecord20, unsigned char*, 74) = rawWord2;
    if (rawWord3 == retainedStateByteOrPosition16) goto originalStateOne71;
    rawWord2 = rawWord3 < 2;
    if (!rawWord2) goto originalUpperStateDispatch29;
    if (({int stateIsZero = rawWord3 == 0;retainedStateByteOrPosition16 = 1;stateIsZero;})) goto originalStateZero36;
    goto callOriginalCommonHelpers674;
    originalUpperStateDispatch29:rawWord2 = 2;
    if (rawWord3 == rawWord2) goto originalStateTwo157;
    rawWord2 = 3;
    if (rawWord3 == rawWord2) goto originalStateThree671;
    goto callOriginalCommonHelpers674;
    {
        originalStateZero36:{
            register int argumentWord4 __asm__("$4");
            Level25_7BD04Field(ownerRecord20, short *, 0x38) = 0;
            Level25_7BD04Field(privateRecord19, signed char *, 5) = 1;
            rawWord2 = Level25_7BD04Data6C598View1;
            if (rawWord2 == 0){
                rawWord2 = 2;
                rawWord3 = Level25_7BD04Field(ownerRecord20, unsigned char*, 73);
                argumentWord4 = (int)ownerRecord20;
                if (rawWord3 == rawWord2){
                    rawWord2 = Level25_7BD04Data6C7B4View1;
                    rawWord3 = Level25_7BD04Data6C62CView1;
                    rawWord2 |= 4;
                    rawWord3 &= 251;
                    Level25_7BD04Data6C7B4View1 = rawWord2;
                    Level25_7BD04Data6C62CView1 = rawWord3;
                    rawWord2 = 2;
                    Level25_7BD04Field(privateRecord19, signed char*, 5) = rawWord2;
                    rawWord2 = 4;
                    Level25_7BD04Field(privateRecord19, signed char*, 2) = rawWord2;
                    Level25_7BD04Field(ownerRecord20, unsigned char*, 73) = 0;
                }
                if (Level25_7BD04Call37BBCView1(argumentWord4, 0) != 0) {
                    Level25_7BD04Call512E4View1(ownerRecord20, 0, 1);
                    Level25_7BD04Field(ownerRecord20, unsigned char *, 0x48) = 1U;
                }
            }
            goto callOriginalCommonHelpers674;
        originalStateOne71:
            if (Level25_7BD04Data6E344View1 != retainedStateByteOrPosition16) {
                rawWord3 = Level25_7BD04Field(privateRecord19, unsigned char*, 4);
                retainedStateByteOrPosition16 = (int)ownerRecord20+73;
                if (rawWord3 == 2){
                    rawWord2 = 0x10000002;
                    argumentWord4 = (int)&Level25_7BD04Data6FA40View1;
                    Level25_7BD04Field((int)&Level25_7BD04Data70328View1, int*, 524) = rawWord2;
                    rawWord2 = 3;
                    Level25_7BD04Field(argumentWord4, int*, 0) = rawWord2;
                    Level25_7BD04Field(ownerRecord20, unsigned char *, 0x48) = 2U;
                    Level25_7BD04Call4F178View1(argumentWord4+8, Level25_7BD04Field(Level25_7BD04Field(privateRecord19, void**, 36), void**, 12));
                    Level25_7BD04Data6FA50View1 += 0x200;
                    temporaryWord1 = Level25_7BD04Field(Level25_7BD04Field(privateRecord19, void **, 0x24), void **, 0xC);
                    Level25_7BD04Call4F1C8View1(&originalFrame.at18.vector[0], temporaryWord1+16, temporaryWord1);
                    Level25_7BD04Data6FA54View1 = Level25_7BD04Call4E880View1(originalFrame.at18.vector[0], originalFrame.at18.vector[1], 0);
                    Level25_7BD04Field(Level25_7BD04Field(privateRecord19, void **, 0x24), short *, 2) = 1;
                    Level25_7BD04Call3B7B4View1(Level25_7BD04Field(privateRecord19, void **, 0x24) + 2, 2, (int)&Level25_7BD04Data6D088View1);
                    Level25_7BD04Call3B7B4View1(Level25_7BD04Field(privateRecord19, void **, 0x24) + 2, 2, (int)&Level25_7BD04Data6C7F8View1);
                    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
                    retainedStateByteOrPosition16 = (int)ownerRecord20+72;
                    Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6D088View1);
                    Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6C7F8View1);
                    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
                    retainedStateByteOrPosition16 = (int)ownerRecord20+73;
                }
                Level25_7BD04Field(ownerRecord20, unsigned char *, 0x49) = 0U;
                Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6D088View1);
                Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6C7F8View1);
                Level25_7BD04Call3B74CView1((int)&Level25_7BD04Data6D088View1);
                Level25_7BD04Field(ownerRecord20, unsigned char *, 0x48) = 3U;
            }
            goto callOriginalCommonHelpers674;
        originalStateTwo157:
            retainedDescriptorIndexOrPlayerBase18 = Level25_7BD04Field(Level25_7BD04Field(privateRecord19, void **, 0x24), short *, 2);
            if (({rawWord2 = Level25_7BD04Call3BFC0View1(ownerRecord20, Level25_7BD04Field(privateRecord19, int*, 144));argumentWord4 = (int)ownerRecord20;rawWord2;}) == 0) {
                Level25_7BD04Field(privateRecord19, int *, 0x90) = Level25_7BD04Call3BABCView1(argumentWord4, ({__asm__ volatile("":"=r"(rawWord2):"0"(rawWord2):"$5");argumentWord5 = 0;argumentWord5;}), 4);
            }
            rawWord3 = Level25_7BD04Field(ownerRecord20, unsigned char*, 73);
            rawWord2 = rawWord3 < 2;
            if (rawWord3 == retainedStateByteOrPosition16) goto originalSubstateOne206;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"$4");
            if (!rawWord2) goto originalDescriptorDistance315;
            if (rawWord3) goto originalDescriptorDistance315;
            {
                Level25_7BD04Call4F178View1(ownerRecord20 + 0xC, (int)&Level25_7BD04Data6FA48View1);
                __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
                retainedStateByteOrPosition16 = (int)ownerRecord20+72;
                Level25_7BD04Field(privateRecord19, int *, 0x5C) = 0;
                Level25_7BD04Field(privateRecord19, int *, 0x64) = 0;
                rawWord2 = Level25_7BD04Data6FA54View1*16;
                Level25_7BD04Field(privateRecord19, int*, 108) = rawWord2;
                Level25_7BD04Field(privateRecord19, int*, 96) = 0;
                Level25_7BD04Field(privateRecord19, int*, 104) = 0;
                Level25_7BD04Field(privateRecord19, int*, 112) = 0;
                Level25_7BD04Field(ownerRecord20, int *, 8) = 0;
                Level25_7BD04Field(ownerRecord20, unsigned char *, 0x48) = 0U;
                Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6D088View1);
                Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6C7F8View1);
                Level25_7BD04Field(ownerRecord20, unsigned char *, 0x48) = 2U;
                Level25_7BD04Field(ownerRecord20, unsigned char *, 0x49) = 1U;
            }
        originalSubstateOne206:
            {
                retainedOriginalDataBase21 = (int)&Level25_7BD04Data6FA40View1;
                if (Level25_7BD04Field(retainedOriginalDataBase21, int*, 0) == 0){
                    argumentWord4 = retainedOriginalDataBase21+8;
                    rawWord2 = Level25_7BD04Field(privateRecord19, int*, 140);
                    rawWord2 *= 2;
                    rawWord3 = Level25_7BD04Field((int)&Level25_7BD04Data65920View1, short*, rawWord2);
                    argumentWord5 = (int)&originalFrame.sp58;
                    rawWord2 = (rawWord3*13) >> 5;
                    originalFrame.sp58 = rawWord2;
                    rawWord2 = Level25_7BD04Field(privateRecord19, int*, 140);
                    rawWord2 *= 2;
                    rawWord3 = Level25_7BD04Field((int)&Level25_7BD04Data658A0View1, short*, rawWord2);
                    argumentWord6 = privateRecord19+120;
                    originalFrame.sp60 = 0;
                    __asm__ volatile("":::"memory");
                    rawWord2 = (rawWord3*13) >> 5;
                    originalFrame.sp5C = rawWord2;
                    Level25_7BD04Call4F194View1(argumentWord4, argumentWord5, argumentWord6);
                    rawWord2 = Level25_7BD04Data6FA50View1;
                    rawWord2 += 356;
                    Level25_7BD04Data6FA50View1 = rawWord2;
                    rawWord2 = Level25_7BD04Field(privateRecord19, int*, 140);
                    __asm__ volatile("":::"$3", "memory");
                    rawWord3 = 3;
                    Level25_7BD04Field(retainedOriginalDataBase21, int*, 0) = rawWord3;
                    rawWord2 += 128;
                    Level25_7BD04Data6FA54View1 = rawWord2;
                }
                temporaryWord2 = Level25_7BD04Field(privateRecord19, void **, 0x24);
                if (Level25_7BD04Field(temporaryWord2, short *, 2) >= (Level25_7BD04Field(temporaryWord2, short *, 0) - 4)) {
                    argumentWord4 = retainedOriginalDataBase21+8;
                    rawWord2 = Level25_7BD04Field(privateRecord19, int*, 140);
                    rawWord2 *= 2;
                    rawWord3 = Level25_7BD04Field((int)&Level25_7BD04Data65920View1, short*, rawWord2);
                    argumentWord5 = (int)&originalFrame.sp68;
                    rawWord2 = (rawWord3*39) >> 6;
                    originalFrame.sp68 = rawWord2;
                    rawWord2 = Level25_7BD04Field(privateRecord19, int*, 140);
                    rawWord2 *= 2;
                    rawWord3 = Level25_7BD04Field((int)&Level25_7BD04Data658A0View1, short*, rawWord2);
                    argumentWord6 = privateRecord19+120;
                    originalFrame.sp70 = 0;
                    __asm__ volatile("":::"memory");
                    rawWord2 = (rawWord3*39) >> 6;
                    originalFrame.sp6C = rawWord2;
                    Level25_7BD04Call4F194View1(argumentWord4, argumentWord5, argumentWord6);
                    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
                    retainedStateByteOrPosition16 = (int)ownerRecord20+73;
                    argumentWord4 = retainedStateByteOrPosition16;
                    argumentWord5 = 1;
                    retainedDataVectorOrMatrix17 = (int)&Level25_7BD04Data6D088View1;
                    argumentWord6 = retainedDataVectorOrMatrix17;
                    rawWord2 = Level25_7BD04Data6FA50View1;
                    rawWord2 += 356;
                    Level25_7BD04Data6FA50View1 = rawWord2;
                    rawWord2 = Level25_7BD04Field(privateRecord19, int*, 140);
                    __asm__ volatile("":::"$3", "memory");
                    rawWord3 = 3;
                    Level25_7BD04Field(retainedOriginalDataBase21, int*, 0) = rawWord3;
                    rawWord2 += 128;
                    Level25_7BD04Data6FA54View1 = rawWord2;
                    Level25_7BD04Field(ownerRecord20, unsigned char *, 0x49) = 2U;
                    Level25_7BD04Call3B7B4View1(argumentWord4, argumentWord5, argumentWord6);
                    Level25_7BD04Call3B7B4View1(retainedStateByteOrPosition16, 1, (int)&Level25_7BD04Data6C7F8View1);
                    Level25_7BD04Call3B74CView1((int)&Level25_7BD04Data6D088View1);
                }
            }
        originalDescriptorDistance315:
            rawWord2 = Level25_7BD04Field(privateRecord19, int*, 36);
            __asm__ volatile("":::"$4", "$5", "memory");
            argumentWord4 = (int)ownerRecord20+12;
            rawWord2 = Level25_7BD04Field(rawWord2, int*, 12);
            __asm__ volatile("":::"$5", "memory");
            argumentWord5 = retainedDescriptorIndexOrPlayerBase18*16;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            argumentWord5 = rawWord2+argumentWord5;
            rawWord2 = Level25_7BD04Call4F334View1(argumentWord4, argumentWord5);
            __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
            if (rawWord2 < 1024){
                rawWord2 = Level25_7BD04Field(Level25_7BD04Field(privateRecord19, int*, 36), short*, 0)-1;
                rawWord2 = retainedDescriptorIndexOrPlayerBase18 < rawWord2;
                retainedDataVectorOrMatrix17 = (int)&originalFrame.sp28;
                if (!rawWord2) goto originalPreparedVector334;
                retainedDescriptorIndexOrPlayerBase18 += 1;
            }
            __asm__ volatile("":::"$17", "memory");
            retainedDataVectorOrMatrix17 = (int)&originalFrame.sp28;
        originalPreparedVector334:
            __asm__("":"=r"(retainedDataVectorOrMatrix17):"0"(retainedDataVectorOrMatrix17));
            argumentWord4 = retainedDataVectorOrMatrix17;
            __asm__ volatile("":::"$16", "memory");
            retainedStateByteOrPosition16 = (int)ownerRecord20+12;
            rawWord2 = Level25_7BD04Field(privateRecord19, int*, 36);
            argumentWord6 = retainedStateByteOrPosition16;
            rawWord2 = Level25_7BD04Field(rawWord2, int*, 12);
            __asm__ volatile("":::"$5", "memory");
            argumentWord5 = retainedDescriptorIndexOrPlayerBase18*16;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            argumentWord5 = rawWord2+argumentWord5;
            Level25_7BD04Call4F1C8View1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord7 = (Level25_7BD04Call4E880View1(originalFrame.sp28, originalFrame.sp2C, 1) - Level25_7BD04Field(privateRecord19, int *, 0x6C)) & 0xFFF;
            if (argumentWord7 >= 0x801) {
                argumentWord7 -= 0x1000;
            }
            temporaryWord6 = argumentWord7;
            if (argumentWord7 < 0) {
                temporaryWord6 = -temporaryWord6;
            }
        }
        argumentWord4 = (int)&originalFrame.sp28;
        if (temporaryWord6 >= 0x321) {
            {
                register int originalPathArgument4 __asm__("$4");
                temporaryWord3 = Level25_7BD04Field(privateRecord19, void **, 0x24);
                if (({rawWord2 = retainedDescriptorIndexOrPlayerBase18 < (Level25_7BD04Field(temporaryWord3, short *, 0)-1);argumentWord4 = retainedDataVectorOrMatrix17;originalPathArgument4 = argumentWord4;rawWord2;})) {
                    retainedDescriptorIndexOrPlayerBase18 += 1;
                }
                argumentWord6 = retainedStateByteOrPosition16;
                rawWord2 = Level25_7BD04Field(temporaryWord3, int*, 12);
                __asm__ volatile("":::"$5", "memory");
                argumentWord5 = retainedDescriptorIndexOrPlayerBase18*16;
                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                argumentWord5 = rawWord2+argumentWord5;
                Level25_7BD04Call4F1C8View1(originalPathArgument4, argumentWord5, argumentWord6, argumentWord7);
            }
            argumentWord7 = (Level25_7BD04Call4E880View1(originalFrame.sp28, originalFrame.sp2C, 1) - Level25_7BD04Field(privateRecord19, int *, 0x6C)) & 0xFFF;
            argumentWord4 = (int)&originalFrame.sp28;
            if (argumentWord7 >= 0x801) {
                argumentWord7 -= 0x1000;
            }
        }
        argumentWord6 = Level25_7BD04Field(privateRecord19, int*, 112);
        argumentWord5 = 0;
        rawWord2 = argumentWord6*9;
        rawWord2 = argumentWord7-rawWord2;
        rawWord2 = (rawWord2*2) >> 6;
        argumentWord6 += rawWord2;
        Level25_7BD04Field(privateRecord19, int*, 112) = argumentWord6;
        rawWord3 = Level25_7BD04Field(privateRecord19, int*, 108);
        rawWord3 += argumentWord6;
        Level25_7BD04Field(privateRecord19, int*, 108) = rawWord3;
        rawWord2 = Level25_7BD04Call4EDE8View1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
        rawWord2 = Level25_7BD04Call4E880View1(rawWord2, originalFrame.sp30, 1);
        rawWord3 = Level25_7BD04Field(privateRecord19, int*, 100);
        rawWord2 -= rawWord3;
        argumentWord7 = rawWord2&4095;
        if (argumentWord7 >= 2049)argumentWord7 -= 4096;
        {
            register int argumentWord4 __asm__("$4");
            argumentWord4 = argumentWord7*2;
            rawWord3 = Level25_7BD04Field(privateRecord19, int*, 112);
            rawWord3 = -rawWord3;
            rawWord2 = (rawWord3*3) >> 2;
            rawWord3 = Level25_7BD04Field(privateRecord19, int*, 104);
            argumentWord7 = rawWord2&255;
            rawWord2 = rawWord3*24;
            argumentWord4 -= rawWord2;
            argumentWord4 >>= 6;
            rawWord3 += argumentWord4;
            Level25_7BD04Field(privateRecord19, int*, 104) = rawWord3;
            rawWord2 = Level25_7BD04Field(privateRecord19, int*, 100);
            rawWord2 += rawWord3;
            Level25_7BD04Field(privateRecord19, int*, 100) = rawWord2;
            if (argumentWord7 >= 129)argumentWord7 -= 256;
            rawWord2 = argumentWord7 < 41;
            if (!rawWord2){
                argumentWord7 = 40;
                __asm__("":"=r"(argumentWord7):"0"(argumentWord7));
            }
            rawWord2 = argumentWord7 < -40;
            argumentWord4 = (int)ownerRecord20;
            if (rawWord2)argumentWord7 = -40;
            argumentWord6 = privateRecord19+44;
            rawWord2 = argumentWord7*16;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Level25_7BD04Field(privateRecord19, int*, 92) = rawWord2;
            Level25_7BD04Data743ECView1(argumentWord4, Level25_7BD04Field(privateRecord19, int*, 36), argumentWord6, privateRecord19+40, 6, 0);
            Level25_7BD04Field(ownerRecord20, unsigned char *, 0x44) = (unsigned char) ((int) Level25_7BD04Field(privateRecord19, int *, 0x5C) >> 4);
            Level25_7BD04Field(ownerRecord20, unsigned char *, 0x45) = (unsigned char) ((int) Level25_7BD04Field(privateRecord19, int *, 0x64) >> 4);
            Level25_7BD04Field(ownerRecord20, unsigned char *, 0x46) = (unsigned char) ((int) Level25_7BD04Field(privateRecord19, int *, 0x6C) >> 4);
            Level25_7BD04Field((int)&Level25_7BD04Data70328View1, int *, 0x20C) = 0x1000A000;
            Level25_7BD04Field((int)&Level25_7BD04Data70328View1, int *, 0x23C) = 0;
            Level25_7BD04Call4F178View1((int)&Level25_7BD04Data70328View1 + 0x20C + 0x20, ownerRecord20 + 0xC);
            argumentWord4 = (int)&originalFrame.sp38;
            __asm__ volatile(""::"r"(argumentWord4):"memory");
            Level25_7BD04Field((int)&Level25_7BD04Data70328View1, unsigned char *, 0x228) = (unsigned char) Level25_7BD04Field(ownerRecord20, unsigned char *, 0x44);
            rawWord2 = Level25_7BD04Field(ownerRecord20, unsigned char*, 69);
            __asm__ volatile("":::"$18", "memory");
            retainedDescriptorIndexOrPlayerBase18 = (int)&Level25_7BD04Data6E160View1;
            Level25_7BD04Field((int)&Level25_7BD04Data70328View1, unsigned char*, 553) = rawWord2;
            rawWord3 = Level25_7BD04Field(ownerRecord20, unsigned char*, 70);
            rawWord2 = 29;
            Level25_7BD04Field(retainedDescriptorIndexOrPlayerBase18, int*, 0) = rawWord2;
            Level25_7BD04Field(retainedDescriptorIndexOrPlayerBase18, int*, 4) = (int)ownerRecord20;
            Level25_7BD04Field((int)&Level25_7BD04Data70328View1, unsigned char*, 554) = rawWord3;
            Level25_7BD04Call40F48View1(argumentWord4, 0);
            temporaryWord4 = (Level25_7BD04Field(privateRecord19, int *, 0x3C) + (originalFrame.sp3C / 6)) & 0xFFF;
            Level25_7BD04Field(privateRecord19, int *, 0x3C) = temporaryWord4;
            if (temporaryWord4 >= 0x801) {
                Level25_7BD04Field(privateRecord19, int *, 0x3C) = (int) (temporaryWord4 - 0x1000);
            }
            if (Level25_7BD04Field(privateRecord19, int *, 0x3C) < -0xE0) {
                Level25_7BD04Field(privateRecord19, int *, 0x3C) = -0xE0;
            }
            if (Level25_7BD04Field(privateRecord19, int *, 0x3C) >= 0x101) {
                Level25_7BD04Field(privateRecord19, int *, 0x3C) = 0x100;
            }
            temporaryWord5 = (Level25_7BD04Field(privateRecord19, int *, 0x40) - (originalFrame.sp38 / 6)) & 0xFFF;
            Level25_7BD04Field(privateRecord19, int *, 0x40) = temporaryWord5;
            if (temporaryWord5 >= 0x801) {
                Level25_7BD04Field(privateRecord19, int *, 0x40) = (int) (temporaryWord5 - 0x1000);
            }
            if (Level25_7BD04Field(privateRecord19, int *, 0x40) < -0x170) {
                Level25_7BD04Field(privateRecord19, int *, 0x40) = -0x170;
            }
            if (Level25_7BD04Field(privateRecord19, int *, 0x40) >= 0x171) {
                Level25_7BD04Field(privateRecord19, int *, 0x40) = 0x170;
            }
            originalFrame.at18.packed.half18 = Level25_7BD04Data6E03CView1;
            originalFrame.at18.packed.half1A = (Level25_7BD04Data6E03EView1 + Level25_7BD04Field(privateRecord19, int *, 0x3C)) & 0xFFF;
            originalFrame.at18.packed.half1C = (Level25_7BD04Data6E040View1 + Level25_7BD04Field(privateRecord19, int *, 0x40)) & 0xFFF;
            Level25_7BD04Call4F6C4View1(&originalFrame.at18.packed.half18, &originalFrame.sp40, ownerRecord20 + 0x20);
            Level25_7BD04Call4ECF4View1(&originalFrame.sp40, &originalFrame.sp40);
            originalFrame.sp28 = 0x4000;
            originalFrame.sp2C = 0;
            originalFrame.sp30 = 0;
            Level25_7BD04Call4ED6CView1(&originalFrame.sp40, &originalFrame.sp28, &originalFrame.sp28);
            retainedDataVectorOrMatrix17 = privateRecord19 + 0x50;
            Level25_7BD04Call4F194View1(retainedDataVectorOrMatrix17, &originalFrame.sp28, retainedDescriptorIndexOrPlayerBase18-320);
            Level25_7BD04Call4F408View1((int)&Level25_7BD04Data714F4View1, retainedDataVectorOrMatrix17, 1);
            rawWord2 = Level25_7BD04Field(privateRecord19, int*, 60);
            rawWord2 = -rawWord2;
            rawWord3 = rawWord2 >> 3;
            rawWord2 = rawWord3 < -32;
            if (rawWord2){
                rawWord2 = rawWord3 < 32;
                rawWord3 = -32;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
            }
            else{
                rawWord2 = rawWord3 < 32;
            }
            rawWord2 = rawWord3 < 32;
            if (!rawWord2)rawWord3 = 31;
            rawWord2 = Level25_7BD04Field(ownerRecord20, unsigned char*, 69);
            rawWord2 += rawWord3;
            Level25_7BD04Field(ownerRecord20, unsigned char*, 69) = rawWord2;
            rawWord2 = Level25_7BD04Field(privateRecord19, int*, 64);
            rawWord2 = -rawWord2;
            argumentWord7 = rawWord2 >> 3;
            rawWord2 = argumentWord7 < -32;
            if (rawWord2){
                rawWord2 = argumentWord7 < 32;
                argumentWord7 = -32;
                __asm__("":"=r"(argumentWord7):"0"(argumentWord7));
            }
            else{
                rawWord2 = argumentWord7 < 32;
            }
            rawWord2 = argumentWord7 < 32;
            if (!rawWord2)argumentWord7 = 31;
            Level25_7BD04Field(ownerRecord20, unsigned char *, 0x3C) = 2U;
            Level25_7BD04Field(ownerRecord20, signed char *, 0x3D) = 3;
            argumentWord6 = (int) (Level25_7BD04Field(ownerRecord20, unsigned char *, 0x3E) + Level25_7BD04Data6C648View1) % (int) *Level25_7BD04Field(((Level25_7BD04Field(ownerRecord20, unsigned char *, 0x3C) * 4) + Level25_7BD04Field((int)&Level25_7BD04Data6EE2CView1, int*, (Level25_7BD04Field(ownerRecord20, short *, 0x36) * 4))), unsigned char **, 0x3C);
            __asm__ volatile("":"=r"(argumentWord6):"0"(argumentWord6):"$5");
            argumentWord7 += 32;
            argumentWord5 = 4;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5):"$4", "$2");
            argumentWord4 = (int)ownerRecord20;
            Level25_7BD04Field(ownerRecord20, signed char*, 65) = 0;
            __asm__ volatile("":::"$2", "memory");
            rawWord2 = argumentWord7 >> 2;
            Level25_7BD04Field(ownerRecord20, signed char*, 64) = rawWord2;
            Level25_7BD04Field(ownerRecord20, unsigned char*, 62) = argumentWord6;
            Level25_7BD04Field(ownerRecord20, signed char*, 63) = argumentWord6;
            Level25_7BD04Call55D24View1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            if ((Level25_7BD04Call359A4View1(privateRecord19 + 0x38, 4) != 0) && (Level25_7BD04Data6E538View1 & 0x20)) {
                Level25_7BD04DataSpawnMobyView1(0x29F, ownerRecord20);
                if ((Level25_7BD04Data6C578View1 - Level25_7BD04Data6C574View1) >= 0x15) {
                    Level25_7BD04DataSpawnMobyView1(0x2A0, ownerRecord20);
                }
                Level25_7BD04Field(privateRecord19, int *, 0x38) = 0x1E;
            }
            Level25_7BD04Field(privateRecord19, int *, 0x74) = 0;
        }
        goto callOriginalCommonHelpers674;
    originalStateThree671:
        Level25_7BD04Field((int)&Level25_7BD04Data70328View1, int *, 0x20C) = 0x10000002;
        goto callOriginalCommonHelpers674;
    }
callOriginalCommonHelpers674:
    Level25_7BD04Call35D38View1(ownerRecord20);
    Level25_7BD04Call5629CView1(ownerRecord20);
}
#undef Level25_7BD04Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C804.
* AI generated; not human reviewed. All561 original instructions,seven
* selectors and one zero padding word,569 owned words, require exact
* native/linked words and every actual transfer/table destination.
* Frame88 saves S0..S6/RA; original SP18..67 locals remain. S3 changes
* from the private record to count0 only after its final timer input.
* Original raw record index,screen deltas,vector-length argument phases,
* full signed table samples and complete signed divides retain all original
* operands,load widths,field stores and exceptional divide instructions.
* Complete second signed product spans the independent vector arguments
* and original4096 store. Saved base22 and independent random heading/count
* phases preserve original constructor slots. Original40 precedes its byte
* clears and word store; shared final helper remains before the last loop.
* Packed frame60 bytes remain0/rand/rand with the original matrix/vector
* helpers. Empty metadata reads complete initialized words/addresses or
* clobbers dead caller values before complete producers; zero CPU words.
* No partialHI,fixedFP,undefined inputs,live alias overlap or pipeline edits.
* Units/fixed point,complete helper/caller chains,cadence beyond invocation
* and synchronized runtime remain open. Confidence is binary identity only
* after all gates. Next: human review and synchronized retail captures.
* Falsification: native/linked words,actual targets,owned data/padding and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 7ed70ae4ee475fae5dc0dea21b888c1a6e81abec1f774d7c8ebd3e85b751d68d */
#define Level25_7C804Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level25_7C804Call359A4View1(void*, int) __asm__("func_800359A4");
int Level25_7C804Call3BABCView1() __asm__("func_8003BABC");
int Level25_7C804Call3BE70View1() __asm__("func_8003BE70");
int Level25_7C804Call3BFC0View1() __asm__("func_8003BFC0");
int Level25_7C804Call498C0View1() __asm__("func_800498C0");
int Level25_7C804Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level25_7C804Call4EA90View1() __asm__("func_8004EA90");
int Level25_7C804Call4ED6CView1() __asm__("func_8004ED6C");
int Level25_7C804Call4EDE8View1() __asm__("func_8004EDE8");
int Level25_7C804Call4F0E8View1() __asm__("func_8004F0E8");
void Level25_7C804Call4F178View1(void*, void*) __asm__("func_8004F178");
void Level25_7C804Call4F194View1(void*, void*, void*) __asm__("func_8004F194");
void Level25_7C804Call4F1C8View1(void*, void*, void*) __asm__("func_8004F1C8");
int Level25_7C804Call4F408View1() __asm__("func_8004F408");
int Level25_7C804Call55B18View1() __asm__("func_80055B18");
int Level25_7C804Call55D24View1() __asm__("func_80055D24");
int Level25_7C804DatarandView1(void) __asm__("rand");
extern int Level25_7C804Data658A0View1 __asm__("D_800658A0");
extern int Level25_7C804Data65920View1 __asm__("D_80065920");
extern int Level25_7C804Data6C550View1 __asm__("D_8006C550");
extern int Level25_7C804Data6C574View1 __asm__("D_8006C574");
extern int Level25_7C804Data6C578View1 __asm__("D_8006C578");
extern int Level25_7C804Data6C640View1 __asm__("D_8006C640");
extern int Level25_7C804Data6C7E8View1 __asm__("D_8006C7E8");
extern int Level25_7C804Data6E020View1 __asm__("D_8006E020");
extern int Level25_7C804Data6FA3CView1 __asm__("D_8006FA3C");
extern int Level25_7C804Data714F4View1 __asm__("D_800714F4");
extern int Level25_7C804Data714F8View1 __asm__("D_800714F8");
extern void*(*Level25_7C804DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern void*(*Level25_7C804DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
extern int(*Level25_7C804Data743ECView1)() __asm__("unk_ovlheader_800743EC");
void func_level_25_8007C804(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), retainedCoordinateBase22 __asm__("$22");
    int completeSecondSignedProduct;
    register void *ownerRecord18 __asm__("$18");
    register int privateRecordOrCounter19 __asm__("$19"), retainedRecordOrSignedValue16 __asm__("$16"), linkedOrSpawnedRecord17 __asm__("$17"), retainedHeadingOrMatrix20 __asm__("$20"), retainedSpawnCount21 __asm__("$21");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64;
    }
    originalFrame;
    int temporaryWord4;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord5;
    ownerRecord18 = ownerParameter;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateRecordOrCounter19 = Level25_7C804Field(ownerRecord18, void **, 0);
    rawWord3 = Level25_7C804Field(privateRecordOrCounter19, int *, 0);
    linkedOrSpawnedRecord17 = 0;
    if (rawWord3 >= 0) {
        rawWord2 = rawWord3*88;
        rawWord3 = Level25_7C804Data6C550View1;
        linkedOrSpawnedRecord17 = rawWord3+rawWord2;
        __asm__("":"=r"(linkedOrSpawnedRecord17):"0"(linkedOrSpawnedRecord17));
    }
    if ((unsigned int) (Level25_7C804Field(ownerRecord18, unsigned char *, 0x48) - 2) < 3U) {
        if (Level25_7C804Field(ownerRecord18, int *, 0x18) != 0) {
            Level25_7C804Field(ownerRecord18, unsigned char *, 0x48) = 5U;
        }
        retainedRecordOrSignedValue16 = Level25_7C804Field(((Level25_7C804Field(privateRecordOrCounter19, int *, 0xC) * 0x58) + Level25_7C804Data6C550View1), int*, 0);
        Level25_7C804Call4F1C8View1(&originalFrame.sp18, ownerRecord18 + 0xC, (int)&Level25_7C804Data6E020View1);
        argumentWord6 = Level25_7C804Call4EDE8View1(&originalFrame.sp18, 1);
        if (argumentWord6 <= 0xFFFF) {
            if (argumentWord6 < 16384)argumentWord6 = 1;
            else if (argumentWord6 <= 32767)argumentWord6 = 2;
            else argumentWord6 = 3;
            Level25_7C804Call4F408View1(&originalFrame.sp18, ownerRecord18+12, argumentWord6);
            rawWord2 = originalFrame.sp18;
            rawWord3 = Level25_7C804Data714F4View1;
            rawWord2 -= rawWord3;
            if (rawWord2 < 0) {
                rawWord2 = -rawWord2;
            }
            if (rawWord2 < 0x1E) {
                rawWord2 = originalFrame.sp1C;
                rawWord3 = Level25_7C804Data714F8View1;
                rawWord2 -= rawWord3;
                if (rawWord2 < 0) {
                    rawWord2 = -rawWord2;
                }
                if (rawWord2 < 0x18) {
                    Level25_7C804Field(retainedRecordOrSignedValue16, void **, 0x74) = ownerRecord18;
                }
            }
        }
    }
    if ((linkedOrSpawnedRecord17 == 0) || !(Level25_7C804Field(linkedOrSpawnedRecord17, unsigned char *, 0x48) & 0x80)) {
        temporaryWord4 = Level25_7C804Field(ownerRecord18, unsigned char *, 0x48);
        switch (temporaryWord4) {
        case 0:
            if (Level25_7C804Data6FA3CView1 == 3) {
                if (linkedOrSpawnedRecord17 != 0) {
                    temporaryWord5 = Level25_7C804Field(linkedOrSpawnedRecord17, void **, 0);
                    Level25_7C804Field(privateRecordOrCounter19, int *, 0x20) = (int) Level25_7C804Field(temporaryWord5, int *, 4);
                    Level25_7C804Field(privateRecordOrCounter19, int *, 0x24) = (int) Level25_7C804Field(temporaryWord5, int *, 8);
                    Level25_7C804Field(privateRecordOrCounter19, int *, 0xC) = (int) Level25_7C804Field(temporaryWord5, int *, 0);
                }
                if (Level25_7C804Field(privateRecordOrCounter19, int *, 0x20) != 0) {
                    Level25_7C804Field(ownerRecord18, signed char *, 0x41) = 0;
                    Level25_7C804Field(ownerRecord18, signed char *, 0x4C) = 0;
                    Level25_7C804Field(ownerRecord18, signed char *, 0x4D) = 0;
                    Level25_7C804Field(ownerRecord18, int *, 8) = 0;
                    Level25_7C804Field(ownerRecord18, unsigned char *, 0x4A) = 0xFF;
                }
                Level25_7C804Field(ownerRecord18, unsigned char *, 0x48) = 1U;
                return;
            }
            goto callSharedOriginalFinalHelper;
        case 1:
            rawWord3 = Level25_7C804Field(privateRecordOrCounter19, int*, 12);
            argumentWord4 = 2;
            rawWord2 = rawWord3*88;
            rawWord3 = Level25_7C804Data6C550View1;
            rawWord2 += rawWord3;
            rawWord3 = Level25_7C804Field(rawWord2, unsigned char*, 72);
            rawWord2 = Level25_7C804Field(rawWord2, int*, 0);
            if (rawWord3 == argumentWord4 && Level25_7C804Field(Level25_7C804Field(rawWord2, int*, 36), short*, 2) >= Level25_7C804Field(privateRecordOrCounter19, int*, 32)){
                Level25_7C804Field(ownerRecord18, signed char *, 0x41) = 1;
                Level25_7C804Field(ownerRecord18, signed char *, 0x4C) = 0x7F;
                Level25_7C804Field(ownerRecord18, signed char *, 0x4D) = 1;
                if (linkedOrSpawnedRecord17 != 0) {
                    argumentWord4 = (int)ownerRecord18+12;
                    rawWord3 = Level25_7C804Field(linkedOrSpawnedRecord17, unsigned char*, 70);
                    argumentWord5 = argumentWord4;
                    rawWord3 = ((rawWord3+128)&255)*2;
                    argumentWord7 = Level25_7C804Field((int)&Level25_7C804Data65920View1, short*, rawWord3);
                    argumentWord6 = linkedOrSpawnedRecord17+12;
                    rawWord2 = (argumentWord7*3) >> 1;
                    Level25_7C804Field(ownerRecord18, int*, 12) = rawWord2;
                    rawWord3 = Level25_7C804Field((int)&Level25_7C804Data658A0View1, short*, rawWord3);
                    __asm__("":::"$2", "memory");
                    rawWord2 = 4096;
                    Level25_7C804Field(ownerRecord18, int*, 20) = rawWord2;
                    rawWord2 = (rawWord3*3) >> 1;
                    Level25_7C804Field(ownerRecord18, int*, 16) = rawWord2;
                    Level25_7C804Call4F194View1(argumentWord4, argumentWord5, argumentWord6);
                    rawWord2 = Level25_7C804Field(privateRecordOrCounter19, int*, 8);
                    __asm__("":"=r"(rawWord2):"0"(rawWord2):"memory");
                    Level25_7C804Field(privateRecordOrCounter19, int*, 4) = rawWord2;
                    rawWord2 = 2;
                }
                else {
                    rawWord2 = Level25_7C804Field(privateRecordOrCounter19, int*, 28);
                    rawWord3 = 1;
                    Level25_7C804Field(rawWord2, short*, 2) = rawWord3;
                    rawWord2 = 3;
                }
                Level25_7C804Field(ownerRecord18, unsigned char *, 0x48) = rawWord2;
                Level25_7C804Call55D24View1(ownerRecord18, 3);
                return;
            }
        default:
            return;
        case 2:
            if (Level25_7C804Call3BFC0View1(ownerRecord18, Level25_7C804Field(privateRecordOrCounter19, int *, 0x28)) == 0) {
                Level25_7C804Field(privateRecordOrCounter19, int *, 0x28) = Level25_7C804Call3BABCView1(ownerRecord18, 0, 4);
            }
            Level25_7C804Call359A4View1(privateRecordOrCounter19+4, 4);
            rawWord2 = Level25_7C804Field(privateRecordOrCounter19, int*, 4);
            rawWord3 = rawWord2*3;
            rawWord2 = Level25_7C804Field(privateRecordOrCounter19, int*, 8);
            rawWord3 <<= 11;
            rawWord3 = rawWord3/rawWord2;
            rawWord2 = ((Level25_7C804Field(linkedOrSpawnedRecord17, unsigned char*, 70)+128)&255)*2;
            argumentWord4 = Level25_7C804Field((int)&Level25_7C804Data65920View1, short*, rawWord2);
            argumentWord4 = (argumentWord4*rawWord3) >> 12;
            Level25_7C804Field(ownerRecord18, int*, 12) = argumentWord4;
            argumentWord4 = (int)ownerRecord18+12;
            rawWord2 = Level25_7C804Field((int)&Level25_7C804Data658A0View1, short*, rawWord2);
            completeSecondSignedProduct = rawWord2*rawWord3;
            argumentWord6 = linkedOrSpawnedRecord17+12;
            argumentWord4 = (int)ownerRecord18+12;
            argumentWord5 = argumentWord4;
            rawWord2 = 4096;
            Level25_7C804Field(ownerRecord18, int*, 20) = rawWord2;
            rawWord2 = completeSecondSignedProduct >> 12;
            Level25_7C804Field(ownerRecord18, int*, 16) = rawWord2;
            Level25_7C804Call4F194View1(argumentWord4, argumentWord5, argumentWord6);
            Level25_7C804Call55D24View1(ownerRecord18, 3);
            if (Level25_7C804Field(privateRecordOrCounter19, int *, 4) == 0) {
                Level25_7C804Field(privateRecordOrCounter19, int *, 4) = 0x78;
                Level25_7C804Field(linkedOrSpawnedRecord17, unsigned char *, 0x49) = 4U;
                Level25_7C804Field(ownerRecord18, unsigned char *, 0x48) = 4U;
                return;
            }
            break;
        case 3:
            retainedRecordOrSignedValue16 = Level25_7C804Field(((Level25_7C804Field(privateRecordOrCounter19, int *, 0xC) * 0x58) + Level25_7C804Data6C550View1), int*, 0);
            if (Level25_7C804Call3BFC0View1(ownerRecord18, Level25_7C804Field(privateRecordOrCounter19, int *, 0x28)) == 0) {
                Level25_7C804Field(privateRecordOrCounter19, int *, 0x28) = Level25_7C804Call3BABCView1(ownerRecord18, 0, 4);
            }
            if (Level25_7C804Field(Level25_7C804Field(retainedRecordOrSignedValue16, void **, 0x24), short *, 2) >= Level25_7C804Field(privateRecordOrCounter19, int *, 0x24)) {
                Level25_7C804Call498C0View1();
            }
            Level25_7C804Data743ECView1(ownerRecord18, Level25_7C804Field(privateRecordOrCounter19, void **, 0x1C), privateRecordOrCounter19 + 0x10, privateRecordOrCounter19 + 4, 6, 0);
            return;
        case 4:
            if (Level25_7C804Call3BFC0View1(ownerRecord18, Level25_7C804Field(privateRecordOrCounter19, int *, 0x28)) == 0) {
                Level25_7C804Field(privateRecordOrCounter19, int *, 0x28) = Level25_7C804Call3BABCView1(ownerRecord18, 0, 4);
            }
            if (Level25_7C804Call359A4View1(privateRecordOrCounter19+4, 4) != 0) {
                Level25_7C804Call498C0View1();
            }
            rawWord2 = Level25_7C804Field(privateRecordOrCounter19, int*, 4);
            rawWord2 <<= 11;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            retainedRecordOrSignedValue16 = rawWord2/120;
            Level25_7C804Call4F178View1(linkedOrSpawnedRecord17 + 0xC, ownerRecord18 + 0xC);
            rawWord2 = Level25_7C804Field(linkedOrSpawnedRecord17, int*, 20);
            rawWord2 -= 2048;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord2 -= retainedRecordOrSignedValue16;
            Level25_7C804Field(linkedOrSpawnedRecord17, int*, 20) = rawWord2;
            return;
        case 5:
            if (Level25_7C804Call3BFC0View1(ownerRecord18, Level25_7C804Field(privateRecordOrCounter19, int *, 0x28)) != 0) {
                Level25_7C804Call3BE70View1(Level25_7C804Field(privateRecordOrCounter19, int *, 0x28));
            }
            Level25_7C804Field(privateRecordOrCounter19, int *, 0x28) = -1;
            Level25_7C804Call3BABCView1(ownerRecord18, 1, 0);
            if (linkedOrSpawnedRecord17 != 0) {
                rawWord2 = 4;
                rawWord3 = Level25_7C804Field(linkedOrSpawnedRecord17, unsigned char*, 73);
                if (rawWord3 == rawWord2)rawWord2 = 5;
                else rawWord2 = 6;
                Level25_7C804Field(linkedOrSpawnedRecord17, unsigned char *, 0x49) = rawWord2;
            }
            if (((Level25_7C804Data6C578View1 - Level25_7C804Data6C574View1) >= 0x15) && (Level25_7C804Data6C7E8View1 >= 0x7531)) {
                temporaryWord1 = Level25_7C804DataSpawnMobyView1(0x146, ownerRecord18);
                if (temporaryWord1 != 0) {
                    Level25_7C804Field(temporaryWord1, signed char *, 0x47) = 7;
                }
            }
            retainedSpawnCount21 = 0;
            if ((Level25_7C804Data6C578View1 - Level25_7C804Data6C574View1) >= 0x15) {
                retainedCoordinateBase22 = (int)&Level25_7C804Data6E020View1;
                retainedHeadingOrMatrix20 = 0;
            spawnOriginalBoundedSequence:
                rawWord2 = Level25_7C804Data6C7E8View1;
                argumentWord4 = 541;
                if (rawWord2 >= 30001){
                    temporaryWord2 = Level25_7C804DataSpawnMobyView1(argumentWord4, ownerRecord18);
                    if (temporaryWord2 != 0) {
                        retainedRecordOrSignedValue16 = Level25_7C804Call4E880View1(Level25_7C804Field(ownerRecord18, int *, 0xC) - Level25_7C804Field(retainedCoordinateBase22, int *, 0), Level25_7C804Field(ownerRecord18, int *, 0x10) - Level25_7C804Field(retainedCoordinateBase22, int *, 4), 0);
                        rawWord2 = Level25_7C804DatarandView1();
                        retainedRecordOrSignedValue16 += 64;
                        rawWord2 &= 31;
                        retainedRecordOrSignedValue16 += rawWord2;
                        Level25_7C804Field(temporaryWord2, unsigned char*, 70) = retainedRecordOrSignedValue16;
                        Level25_7C804Field(temporaryWord2, signed char *, 0x45) = (signed char) ((retainedHeadingOrMatrix20 + (Level25_7C804DatarandView1() & 0x1E)) - 0xF);
                        Level25_7C804Field(temporaryWord2, signed char *, 0x47) = 8;
                        Level25_7C804Field(temporaryWord2, signed char *, 0x4C) = 0x2A;
                    }
                    retainedSpawnCount21 += 1;
                    retainedHeadingOrMatrix20 += 0x33;
                    if ((retainedSpawnCount21 < 5) && ((Level25_7C804Data6C578View1 - Level25_7C804Data6C574View1) >= 0x15)) {
                        goto spawnOriginalBoundedSequence;
                    }
                }
            }
            __asm__("":::"$2", "memory");
            rawWord2 = 40;
            __asm__ volatile(""::"r"(rawWord2):"memory");
            Level25_7C804Field(ownerRecord18, signed char *, 0x41) = 0;
            Level25_7C804Field(ownerRecord18, signed char *, 0x4C) = 0;
            Level25_7C804Field(ownerRecord18, signed char *, 0x4D) = 0;
            Level25_7C804Field(privateRecordOrCounter19, int*, 4) = rawWord2;
            Level25_7C804Field(ownerRecord18, unsigned char *, 0x48) = 6U;
        case 6:
            rawWord2 = Level25_7C804Call359A4View1(privateRecordOrCounter19+4, 4);
            privateRecordOrCounter19 = 0;
            if (rawWord2){
                callSharedOriginalFinalHelper:Level25_7C804Call55B18View1(ownerRecord18);
                return;
            }
            retainedHeadingOrMatrix20 = (int)&originalFrame.sp48;
            __asm__("":"=r"(retainedHeadingOrMatrix20):"0"(retainedHeadingOrMatrix20));
            do {
                Level25_7C804Field(&originalFrame.sp60, unsigned char*, 0) = 0;
                Level25_7C804Field(&originalFrame.sp60, unsigned char*, 1) = Level25_7C804DatarandView1();
                Level25_7C804Field(&originalFrame.sp60, unsigned char*, 2) = Level25_7C804DatarandView1();
                Level25_7C804Call4EA90View1(&originalFrame.sp60, retainedHeadingOrMatrix20, 0);
                privateRecordOrCounter19 += 1;
                originalFrame.sp28 = (Level25_7C804DatarandView1() & 0x1F) + 0x64;
                originalFrame.sp2C = 0;
                originalFrame.sp30 = 0;
                Level25_7C804Call4ED6CView1(retainedHeadingOrMatrix20, &originalFrame.sp28, &originalFrame.sp28);
                Level25_7C804Call4F178View1(&originalFrame.sp38, &originalFrame.sp28);
                Level25_7C804Call4F0E8View1(&originalFrame.sp38, 2);
                Level25_7C804Call4F194View1(&originalFrame.sp38, &originalFrame.sp38, ownerRecord18 + 0xC);
                Level25_7C804DataSpawnParticleView1(1, 0x3A, &originalFrame.sp38, &originalFrame.sp28);
            }
            while (privateRecordOrCounter19 < 4);
            if (!(Level25_7C804Data6C640View1 & 1) && ((Level25_7C804Data6C578View1 - Level25_7C804Data6C574View1) >= 0x15) && (Level25_7C804Data6C7E8View1 >= 0x7531)) {
                temporaryWord3 = Level25_7C804DataSpawnMobyView1(0x1E2, ownerRecord18);
                if (temporaryWord3 != 0) {
                    Level25_7C804Field(temporaryWord3, signed char *, 0x4C) = 0x2A;
                    Level25_7C804Field(temporaryWord3, signed char *, 0x47) = 0xA;
                }
            }
            break;
        }
    }
    else {
        goto callSharedOriginalFinalHelper;
    }
}
#undef Level25_7C804Field


typedef struct { Moby* target; short timer, queryTimer; } DecodedDirectedProjectileTag;
extern int D_8006C578, D_8006C574;
int DecodedDirectedProjectileActor(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int DecodedDirectedProjectileSweep(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001AD60");
int DecodedDirectedProjectileWorld(Vector3D*,Vector3D*) __asm__("func_80018368");
void DecodedDirectedProjectileDraw(Moby*,int) __asm__("func_80055D24");
void DecodedDirectedProjectileTransform(void*,void*,void*) __asm__("func_8004ED6C");
void DecodedDirectedProjectileAdd(void*,void*,void*) __asm__("func_8004F194");
void func_level_25_8007D0C8(Moby* moby) {
    DecodedDirectedProjectileTag* tag = moby->mobyTag;
    Vector3D previous, velocity;
    switch (moby->state) {
    case 0:
        if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400) goto remove;
        if (tag->target && !(tag->target->state & 0x80)) {
            func_8004F178(&previous,&tag->target->position);
            if (tag->target->mobyClass == 0x2A1) previous.z += 0x400;
            moby->angle.roll = 0;
            moby->angle.pitch = func_8004E880(func_8004F334(&moby->position,&previous),previous.z-moby->position.z,0);
            moby->angle.yaw = func_8004E880(previous.x-moby->position.x,previous.y-moby->position.y,0);
            DecodedDirectedProjectileDraw(moby,4);
        }
        velocity.x = 0x600;
        velocity.y = 0;
        velocity.z = 0;
        DecodedDirectedProjectileTransform(&moby->rotationMatrix,&velocity,&velocity);
        func_8004F178(&previous,&moby->position);
        DecodedDirectedProjectileAdd(&moby->position,&moby->position,&velocity);
        if (func_800359A4(&tag->queryTimer,2) && (DecodedDirectedProjectileActor(&moby->position,0x600,0,0,0x10000,moby) || DecodedDirectedProjectileSweep(&previous,&moby->position,0,0x10000,moby))) {
            moby->state = 1;
        } else if (func_800359A4(&tag->timer,2)) goto remove;
        if (DecodedDirectedProjectileWorld(&previous,&moby->position)) {
            func_8004F178(&moby->position,&previous);
            moby->state = 1;
        }
        break;
    case 1:
        if (D_8006C578-D_8006C574 >= 21) SpawnMoby(0x2A0,moby);
        SpawnParticle(3,0x46,&moby->position,(void*)16);
remove:
        func_80055B18(moby);
        break;
    }
}

extern unsigned short D_8006E040, D_8006E03E;
void func_level_25_8007D358(Moby* moby) {
    int* tag = moby->mobyTag;
    Moby* actor = (Moby*)tag[0];
    register unsigned int yaw __asm__("$2");
    if (actor->mobyClass == 0x28D || actor->mobyClass == 0x2A1)
        func_80055F14(actor, 0, &moby->position);
    yaw = D_8006E040;
    __asm__("" : "=r"(yaw) : "0"(yaw));
    moby->angle.yaw = ((short)yaw >> 4) - 0x80;
    moby->angle.pitch = D_8006E03E >> 4;
    tag[1] += 0xE0;
    if (tag[1] >= 0x400) func_80055B18(moby);
    else {
        *(int*)&moby->colour = 0;
        moby->colour.a = (tag[1] >> 6) | 0x30;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8007D42C.
 * Source: sibling4712.func_level_25_8007D42C.json, 310 original words.
 * Units, helper contracts, update cadence and runtime parity unresolved. */
#define C25Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int C25H55F14() __asm__("func_80055F14");
int C25H4F178() __asm__("func_8004F178");
int C25H4F334() __asm__("func_8004F334");
int C25H4E880() __asm__("func_8004E880");
int C25H34F40() __asm__("func_80034F40");
int C25H4F1C8() __asm__("func_8004F1C8");
int C25H4EDE8() __asm__("func_8004EDE8");
int C25H4F408() __asm__("func_8004F408");
int C25H55D24() __asm__("func_80055D24");
int C25H369B8() __asm__("func_800369B8");
int C25H55B18() __asm__("func_80055B18");
extern unsigned char* C25Pool __asm__("D_8006C550");
extern unsigned char C25Coordinates[] __asm__("D_8006E020");
extern int C25ReferenceX __asm__("D_800714F4");
extern int C25ReferenceY __asm__("D_800714F8");
extern int C25Mode __asm__("D_8006FA3C");
extern int C25Contact __asm__("D_8006C770");
extern int C25CapacityEnd __asm__("D_8006C578");
extern int C25CapacityStart __asm__("D_8006C574");
extern void* (*C25Spawn)(int,void*) __asm__("SpawnMoby");
void func_level_25_8007D42C(void* input){
 struct {int first[4];int second[4];} frame;
 register unsigned char* owner __asm__("$17")=input;
 register void* temporary16 __asm__("$16");
 register unsigned char* linked18 __asm__("$18");
 register unsigned char* linkedTag19 __asm__("$19");
 register unsigned char* nestedTag20 __asm__("$20");
 register unsigned char* tag21 __asm__("$21");
 register int value __asm__("$2");
 register int other __asm__("$3");
 register void* call4 __asm__("$4");
 register int arg5 __asm__("$5");
 register int arg6 __asm__("$6");
 __asm__("" : "=r"(owner):"0"(owner));call4=(void*)owner[72];
 if((int)call4==4){
  linked18=C25Field(owner,unsigned char**,0);call4=C25Field(linked18,void**,0);other=((unsigned char*)call4)[72];arg5=2;
  if(other!=1)goto delete;
  temporary16=owner+12;C25H55F14(call4,arg5,temporary16);
  arg5=C25Field(linked18,int*,4);call4=frame.first;C25H4F178(call4,(unsigned char*)arg5+12);
  call4=temporary16;value=frame.first[2];arg5=(int)frame.first;frame.first[2]=value+1024;
  owner[68]=0;value=C25H4F334(call4,(void*)arg5);call4=(void*)value;
  value=frame.first[2];arg5=C25Field(owner,int*,20);arg6=0;value=C25H4E880((int)call4,value-arg5,arg6);
  owner[69]=value;
  value=C25H4E880(frame.first[0]-C25Field(owner,int*,12),frame.first[1]-C25Field(owner,int*,16),0);
  owner[70]=value;goto done;
 }
 tag21=C25Field(owner,unsigned char**,0);other=C25Field(tag21,int*,0);value=other*11;
 __asm__("" : "=r"(value):"0"(value));other=(int)C25Pool;value<<=3;linked18=(unsigned char*)other+value;
 value=owner[73];linkedTag19=C25Field(linked18,unsigned char**,0);
 if(value!=2)goto dispatch;if((int)call4==3)goto dispatch;
 other=0x10000;value=C25Field(owner,int*,24)&other;call4=owner;
 if(value){arg5=3;linked18[73]=6;owner[72]=3;C25H34F40(call4,arg5);}
 temporary16=frame.second;call4=temporary16;other=C25Field(linkedTag19,int*,0);arg6=(int)C25Coordinates;
 value=other*11;__asm__("" : "=r"(value):"0"(value));other=(int)C25Pool;value<<=3;value+=other;
 nestedTag20=C25Field((void*)value,unsigned char**,0);__asm__("" : : "r"(nestedTag20):"$5");C25H4F1C8(call4,owner+12,(void*)arg6);
 value=C25H4EDE8(temporary16,1);arg6=value;
 if(arg6>65535)goto dispatch;
 if(arg6<16384){arg6=1;goto query_ready;}
 value=arg6>32767;arg6=3;if(value)goto query_ready;arg6=2;
 query_ready:
 C25H4F408(frame.second,owner+12,arg6);
 value=frame.second[0];other=C25ReferenceX;value-=other;if(value<0)value=-value;if(value>=30)goto dispatch;
 value=frame.second[1];other=C25ReferenceY;value-=other;if(value<0)value=-value;if(value>=24)goto dispatch;
 C25Field(nestedTag20,void**,116)=owner;
 dispatch:
 other=owner[72];call4=(void*)1;
 if(other==(int)call4)goto state1;
 if(other<2){if(!other)goto state0;goto done;}
 if(other==2)goto state2;if(other==3)goto state3;goto done;
 state0:
 other=owner[73];if(other==(int)call4)goto sub1;
 if(other<2){if(!other)goto sub0;goto done;}
 if(other==2)goto sub2;goto done;
 sub0:
 other=C25Mode;if(other!=3)goto delete;
 value=C25H4E880(C25Field(linked18,int*,12)-C25Field(owner,int*,12),C25Field(linked18,int*,16)-C25Field(owner,int*,16),0);
 owner[70]=value;value=C25Field(linkedTag19,int*,4);
 if(value){owner[65]=0;owner[76]=0;owner[77]=0;C25Field(owner,int*,8)=0;owner[74]=255;}
 owner[73]=1;goto done;
 sub1:
 other=linked18[73];call4=owner;if(other!=2)goto done;
 arg5=1;__asm__("" : "=r"(arg5):"0"(arg5));value=1;other=63;owner[65]=value;owner[76]=other;owner[77]=value;C25H55D24(call4,arg5);
 owner[73]=2;goto done;
 sub2:
 other=C25Field(linkedTag19,int*,0);value=other*11;__asm__("" : "=r"(value):"0"(value));other=(int)C25Pool;value<<=3;value+=other;
 value=C25Field((void*)value,int*,0);value=C25Field((void*)value,int*,36);other=C25Field(tag21,int*,4);value=C25Field((void*)value,short*,2);
 if(value<other)goto done;
 owner[72]=1;C25H34F40(owner,1);goto done;
 state1:
 value=owner[60];if(value!=other)goto contact1;
 other=owner[73];if(other!=2)goto contact1;
 C25Spawn(673,owner);arg5=0x10000000;value=C25Field(linked18,int*,24);other=C25CapacityEnd;call4=(void*)C25CapacityStart;
 value|=arg5;other-=(int)call4;C25Field(linked18,int*,24)=value;
 if(other>=21)C25Spawn(672,owner);
 owner[73]=3;
 contact1:
 if(!C25Contact)goto done;owner[72]=2;C25H34F40(owner,2);goto done;
 state2:
 value=C25Contact;call4=owner;if(!value)goto done;
 arg5=0;((unsigned char*)call4)[73]=4;((unsigned char*)call4)[72]=0;C25H34F40(call4,arg5);goto done;
 state3:
 value=C25Contact;call4=owner;if(!value)goto done;
 C25H369B8(call4,48);
 delete:
 C25H55B18(owner);
 done:;
}
#undef C25Field


/* Original private words +0, +4, +8; selector/reference units remain open. */
typedef struct { int enabled, reference, limit; } DecodedRaceGateTag;
extern int D_8006FA3C, D_8006FA80, D_8006C644;
void func_80055B18(Moby*);
void func_level_25_8007D904(Moby* moby) {
    DecodedRaceGateTag* tag = moby->mobyTag;
    if (tag->enabled) {
        if (D_8006FA3C != 2) func_80055B18(moby);
        else if (tag->reference >= 0 && tag->limit > 0) {
            int difference = D_8006FA80 - tag->reference;
            if (moby->state == 1) {
                if (ABS(difference) < tag->limit) {
                    moby->unknown3[0] = 1;
                    moby->lowDrawDistance = 0x3F;
                    moby->drawn = 1;
                    moby->state = 0;
                }
            } else if (ABS(difference) > tag->limit) {
                moby->unknown3[0] = 0;
                moby->lowDrawDistance = 0;
                moby->drawn = 0;
                moby->state = 1;
            } else {
                /* Preserve the original packed word store followed by alpha-byte clear. */
                if ((D_8006C644 & 0x3F) >= 0x19)
                    *(int*)&moby->colour = 0xC0FF;
                else
                    *(int*)&moby->colour = 0x6080;
                *((unsigned char*)&moby->colour + 3) = 0;
            }
        }
    } else if (D_8006FA3C == 2) func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original SCUS-94467 USA Rev0
 * asm/nonmatchings/overlays/level_25/moby/func_level_25_8007DA2C.s
 * SHA256 dc5948c6950312d36fde7a24da7978fa96cd4a0d3853f078a9613d29e8a2703b.
 * 510 instructions and 8 original selector words. Original native/linked
 * words and full disc hashes are required; no semantic/runtime parity claim.
 * Raw units, helper contracts, producer chains and cadence remain unresolved. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))
struct _m2c_stack_func_level_25_8007DA2C {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

int SpeedwayController_func_8002803C() __asm__("func_8002803C"); /* extern */
int SpeedwayController_func_80028154() __asm__("func_80028154");                    /* extern */
int SpeedwayController_func_800359A4() __asm__("func_800359A4");                  /* extern */
int SpeedwayController_func_8003BB10() __asm__("func_8003BB10"); /* extern */
extern unsigned char SpeedwayController_D_80067262 __asm__("D_80067262");
extern unsigned char SpeedwayController_D_80067287 __asm__("D_80067287");
extern short SpeedwayController_D_8006728C __asm__("D_8006728C");
extern int SpeedwayController_D_8006C58C __asm__("D_8006C58C");
extern int SpeedwayController_D_8006C5BC __asm__("D_8006C5BC");
extern int SpeedwayController_D_8006C648 __asm__("D_8006C648");
extern unsigned char SpeedwayController_D_8006C7B4 __asm__("D_8006C7B4");
extern int SpeedwayController_D_8006C7C4 __asm__("D_8006C7C4");
extern int SpeedwayController_D_8006E344 __asm__("D_8006E344");
extern unsigned char SpeedwayController_D_8006FA3C __asm__("D_8006FA3C");
extern int SpeedwayController_D_8006FA58 __asm__("D_8006FA58");
extern int SpeedwayController_D_8006FA5C __asm__("D_8006FA5C");
extern int SpeedwayController_D_8006FA60 __asm__("D_8006FA60");
extern int SpeedwayController_D_8006FA64 __asm__("D_8006FA64");
extern unsigned char SpeedwayController_D_8006FA68 __asm__("D_8006FA68");
extern int SpeedwayController_D_8006FA6C __asm__("D_8006FA6C");
extern int SpeedwayController_D_8006FA70 __asm__("D_8006FA70");
extern int SpeedwayController_D_8006FA74 __asm__("D_8006FA74");
extern short SpeedwayController_D_8006FA84 __asm__("D_8006FA84");
extern short SpeedwayController_D_8006FA86 __asm__("D_8006FA86");
extern short SpeedwayController_D_8006FA88 __asm__("D_8006FA88");
extern unsigned char SpeedwayController_D_80070300 __asm__("D_80070300");
extern unsigned char SpeedwayController_D_80070328 __asm__("D_80070328");
extern unsigned char SpeedwayController_D_800716AC __asm__("D_800716AC");
extern short SpeedwayController_D_800719DE __asm__("D_800719DE");
extern unsigned char SpeedwayController_func_80027A60 __asm__("func_80027A60");
extern unsigned char SpeedwayController_func_80027D60 __asm__("func_80027D60");
extern unsigned char SpeedwayController_func_80027EE4 __asm__("func_80027EE4");
extern unsigned char SpeedwayController_func_8002982C __asm__("func_8002982C");
extern unsigned char SpeedwayController_func_80029AA0 __asm__("func_80029AA0");
extern unsigned char speedwayRecords;
extern unsigned char *SpeedwayController_unk_ovlheader_80074370 __asm__("unk_ovlheader_80074370");
extern unsigned char (*SpeedwayController_unk_ovlheader_80074374)() __asm__("unk_ovlheader_80074374");
extern unsigned char *SpeedwayController_unk_ovlheader_80074388 __asm__("unk_ovlheader_80074388");
extern unsigned char *SpeedwayController_unk_ovlheader_8007438C __asm__("unk_ovlheader_8007438C");
extern unsigned char *SpeedwayController_unk_ovlheader_80074390 __asm__("unk_ovlheader_80074390");
extern unsigned char *SpeedwayController_unk_ovlheader_80074394 __asm__("unk_ovlheader_80074394");

void func_level_25_8007DA2C(void *input_arg0) {
    register int *outgoing __asm__("$29");
register void *arg0 __asm__("$18")=input_arg0;
    register int * temp_s0 __asm__("$16");
    int *var_v0;
    register int initial4 __asm__("$4"),initial3 __asm__("$3"),initial5 __asm__("$5");
    register int temp_a0 __asm__("$4");
    int temp_a0_2;
    register int temp_a0_3 __asm__("$4");
    int temp_a0_4;
    register int raw3 __asm__("$3"),work2 __asm__("$2"),remaining6 __asm__("$6");int newQuotient3;
    register int *time5 __asm__("$5");
    register int temp_s1 __asm__("$17");
    register int temp_v0 __asm__("$2");
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    register int temp_v1_2 __asm__("$3");
    int temp_v1_5;register int *counter3 __asm__("$3"),*counter4 __asm__("$4");
    register int var_a0 __asm__("$4");
    register int var_a1 __asm__("$5");
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");register int (*route2)() __asm__("$2");register int selected8 __asm__("$8"),arg7 __asm__("$7"),arg6 __asm__("$6");
    int var_v1;
    unsigned char temp_v1;
    unsigned char temp_v1_3;
    unsigned char temp_v1_4;

    temp_v1 = M2C_FIELD(arg0, unsigned char *, 0x48);
    temp_s0 = M2C_FIELD(arg0, int **, 0);
    switch (temp_v1) {
    case 0:
        var_v1 = 3;
        var_v0 = &SpeedwayController_D_8006FA64;
        do {
            *var_v0 = 0;
            var_v1 -= 1;
            var_v0 -= 1;
        } while (var_v1 >= 0);
        initial4=0x16ACD;initial3=0x18A00;initial5=0x1493D;
        __asm__("" : "=r"(initial4),"=r"(initial3),"=r"(initial5):"0"(initial4),"1"(initial3),"2"(initial5));
        M2C_FIELD(&SpeedwayController_D_8006FA68, int *, 0) = -1;
        SpeedwayController_D_8006FA6C = -1;
        SpeedwayController_D_8006FA84 = -1;
        SpeedwayController_D_8006FA88 = -1;
        SpeedwayController_D_8006FA86 = -1;
        M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x254) = 5;
        M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x260) = 0x599A;
        M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x258) = initial4;
        M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x25C) = initial3;
        M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x264) = initial5;
        M2C_FIELD(arg0, unsigned char *, 0x48) = 1U;
        break;
    case 1:
        temp_s0=(int*)&SpeedwayController_D_8006FA3C;
        __asm__("" : "=r"(temp_s0):"0"(temp_s0));
        temp_s1=M2C_FIELD(temp_s0,int*,0);
        if (temp_s1 == 1) {
            SpeedwayController_D_8006FA84 = SpeedwayController_func_8002803C(0x12, 3, 0, 0, SpeedwayController_unk_ovlheader_80074370, (unsigned char*)temp_s0 + 0x34, 0x8CA0);
            temp_v0=SpeedwayController_func_8002803C(0x17, SpeedwayController_D_8006C5BC * 0xA, SpeedwayController_unk_ovlheader_80074390, 0, SpeedwayController_unk_ovlheader_8007438C, (unsigned char*)temp_s0 + 0x54, 0);
            raw3=M2C_FIELD(temp_s0,int*,-4);
            SpeedwayController_D_8006FA88=temp_v0;
            __asm__("" : "=r"(raw3):"0"(raw3));
            work2=raw3*3;work2*=4;work2-=raw3;temp_v1_2=work2*4;
            if (M2C_FIELD(&speedwayRecords,int*,0x10+temp_v1_2) != 0) {
                M2C_FIELD(temp_s0, int *, 0x34) = 0;
                M2C_FIELD(temp_s0, int *, 0x38) = 0;
                M2C_FIELD(arg0, unsigned char *, 0x48) = 3U;
            } else {
                temp_v0 = M2C_FIELD(&speedwayRecords,int*,0x18+temp_v1_2);
                raw3=SpeedwayController_D_8006C7C4;
                M2C_FIELD(temp_s0,int*,0x34)=temp_v0;
                if (raw3 == temp_s1) {
                    var_v0_2 = temp_v0 + 0x12C;
                    goto block_11;
                }
                var_v0_2 = temp_v0 + 0x258;
                if (raw3 == 0) {
block_11:
                    M2C_FIELD(temp_s0, int *, 0x34) = var_v0_2;
                }
                SpeedwayController_D_8006FA74 = 0;
                M2C_FIELD(arg0, unsigned char *, 0x48) = 2U;
                raw3=SpeedwayController_D_8006C58C;
                __asm__("" : "=r"(raw3):"0"(raw3));
                work2=raw3*3;__asm__("" : "=r"(work2):"0"(work2));temp_a0=work2*2;
                temp_v1_3 = *(&SpeedwayController_D_800716AC + temp_a0);
                if (temp_v1_3 < 0xFFU) {
                    *(&SpeedwayController_D_800716AC + temp_a0) = temp_v1_3 + 1;
                }
            }
        } else if (temp_s1 == 2) {
            SpeedwayController_D_8006FA84 = SpeedwayController_func_8002803C(0x12, 3, 0, 0, SpeedwayController_unk_ovlheader_80074370, (unsigned char*)temp_s0 + 0x34, 0x8CA0);
            SpeedwayController_D_8006FA86 = SpeedwayController_func_8002803C(0x15, 0x7D0, &SpeedwayController_func_80027EE4, &SpeedwayController_func_80027A60, &SpeedwayController_func_80029AA0, (unsigned char*)temp_s0 + 0x3C, 3);
            SpeedwayController_D_8006FA88 = SpeedwayController_func_8002803C(0x17, 0x7D1, &SpeedwayController_func_80027D60, SpeedwayController_unk_ovlheader_80074394, &SpeedwayController_func_8002982C, (unsigned char*)temp_s0 + 0x40, 5);
            M2C_FIELD(temp_s0, int *, 0x34) = 0;
            SpeedwayController_D_8006FA74 = 0xB4;
            M2C_FIELD(temp_s0, int *, 0x3C) = 0;
            M2C_FIELD(temp_s0, int *, 0x40) = 0;
            M2C_FIELD(arg0, unsigned char *, 0x48) = 5U;
            if (!(SpeedwayController_D_8006C7B4 & 2) && !(*(&SpeedwayController_D_80070300 + SpeedwayController_D_8006C58C) & 2)) {
                temp_a0_2 = SpeedwayController_D_8006C58C * 6;
                temp_v1_4 = *(&SpeedwayController_D_800716AC + 1 + temp_a0_2);
                if (temp_v1_4 < 0xFFU) {
                    *(&SpeedwayController_D_800716AC + 1 + temp_a0_2) = temp_v1_4 + 1;
                }
            }
        }
        break;
    case 2:
        if ((SpeedwayController_D_8006E344 == 0) && (M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x50) != 8) && (M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x1CC) == 0)) {
            time5=&SpeedwayController_D_8006FA70;__asm__("" : : "r"(time5));temp_a0_3=*(volatile int*)time5;
            work2=SpeedwayController_D_8006C648;
            raw3=SpeedwayController_D_8006FA74;
            remaining6=temp_a0_3-work2;raw3+=work2;
            *time5=remaining6;SpeedwayController_D_8006FA74=raw3;
            temp_a0_3/=60;
            if(raw3>0x8C9F)SpeedwayController_D_8006FA74=0x8C9F;
            newQuotient3=remaining6/60;__asm__("" : "=r"(newQuotient3):"0"(newQuotient3),"r"(remaining6));
            if(temp_a0_3<11 && temp_a0_3!=newQuotient3)SpeedwayController_func_8003BB10(0,1,1);
            counter3=&SpeedwayController_D_8006FA70;__asm__("" : "=r"(counter3):"0"(counter3));
            work2=*counter3;
            if(work2<=0){
                route2=(void*)SpeedwayController_unk_ovlheader_80074374;__asm__("" : "=r"(route2):"0"(route2));*counter3=0;route2();
            }
            raw3=SpeedwayController_D_8006FA58;work2=8;if(raw3==work2)goto equalCounts;
            goto controllerFooter;
        }
        break;
    case 3:
        if(SpeedwayController_D_8006E344!=0)goto controllerFooter;
        if(M2C_FIELD(&SpeedwayController_D_80070328,int*,0x50)==8)goto controllerFooter;
        counter4=&SpeedwayController_D_8006FA74;__asm__("" : "=r"(counter4):"0"(counter4));temp_v0_2=*counter4+SpeedwayController_D_8006C648;
        *counter4=temp_v0_2;
        if(temp_v0_2>0x8C9F)*counter4=0x8C9F;
        SpeedwayController_D_8006FA70=*counter4;
        raw3=SpeedwayController_D_8006FA58;if(raw3!=8)goto controllerFooter;
equalCounts:
        work2=SpeedwayController_D_8006FA5C;if(work2!=raw3)goto controllerFooter;
        raw3=SpeedwayController_D_8006FA60;if(raw3!=work2)goto controllerFooter;
        work2=SpeedwayController_D_8006FA64;if(work2!=raw3)goto controllerFooter;
        *temp_s0=120;M2C_FIELD(arg0,unsigned char*,72)=4;
        break;
    case 4:
        if ((SpeedwayController_func_800359A4(temp_s0, 4) != 0) && (SpeedwayController_D_800719DE == 0)) {
            SpeedwayController_func_8003BB10(0, 0, 1);
            SpeedwayController_D_8006C7B4 |= 1;
            SpeedwayController_unk_ovlheader_80074374();
        }
        break;
    case 5:
        M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x20C) = 0x10000002;
        if (SpeedwayController_func_800359A4(&SpeedwayController_D_8006FA74, 4) != 0) {
            M2C_FIELD(arg0, unsigned char *, 0x48) = 6U;
        }
        break;
    case 6:
        if ((SpeedwayController_D_8006E344 == 0) && (M2C_FIELD(&SpeedwayController_D_80070328, int *, 0x50) != 8)) {
            counter4=&SpeedwayController_D_8006FA74;__asm__("" : "=r"(counter4):"0"(counter4));temp_v0_3=*counter4+SpeedwayController_D_8006C648;
            *counter4=temp_v0_3;
            if (temp_v0_3 > 0x8C9F) {
                *counter4=0x8C9F;
            }
            SpeedwayController_D_8006FA70=*counter4;
        }
        break;
    }
controllerFooter:
    time5=(int*)&SpeedwayController_D_8006FA3C;
    __asm__("" : "=r"(time5):"0"(time5));
    raw3=*time5;work2=1;if(raw3!=work2)goto footerDone;
    work2=SpeedwayController_D_8006FA6C;
    if(work2<0){
        work2=SpeedwayController_D_8006FA86;var_a0=0;
        if(work2>=0){
            temp_s0=(int*)((unsigned char*)time5+0x4A);
            raw3=M2C_FIELD(time5,short*,0x4A);
            __asm__("" : "=r"(temp_s0),"=r"(raw3):"0"(temp_s0),"1"(raw3));
            var_a1=0;
            do{
                work2=M2C_FIELD(&SpeedwayController_D_80067262,short*,var_a1);
                if(work2==raw3){work2=var_a0*4;goto recordFound;}
                var_a0++;work2=var_a0<8;var_a1+=0x54;
            }while(work2);
            work2=var_a0*4;
recordFound:
            work2+=var_a0;work2*=4;work2+=var_a0;work2*=4;raw3=50;
            M2C_FIELD(&SpeedwayController_D_80067287,unsigned char*,work2)=raw3;
            M2C_FIELD(&SpeedwayController_D_8006728C,short*,work2)=0;
            var_a0=M2C_FIELD(temp_s0,short*,0);
            M2C_FIELD(temp_s0,short*,4)=0;
            SpeedwayController_func_80028154(var_a0,var_a1);
            work2=-1;M2C_FIELD(temp_s0,short*,0)=work2;
        }
    }
    temp_s0=(int*)&SpeedwayController_D_8006FA68;
    __asm__("" : "=r"(temp_s0):"0"(temp_s0));
    selected8=*temp_s0;if(selected8<0)goto footerDone;
    work2=temp_s0[1];if(selected8==work2)goto footerDone;
    var_a0=21;
    if(work2>=0){
        work2=SpeedwayController_D_8006FA6C;work2<<=2;work2=(int)temp_s0+work2;
        work2=M2C_FIELD((void*)work2,int*,-16);
        work2=work2<8;if(!work2)goto footerDone;
    }
    arg6=0;arg7=0;
    __asm__("" : "=r"(var_a0),"=r"(arg6),"=r"(arg7):"0"(var_a0),"1"(arg6),"2"(arg7));
    /* Original words 482..498 explicitly stage arguments 5..7 in the
     * outgoing frame at SP+10, SP+14 and SP+18. This is the original
     * seven-argument ABI, written explicitly for compiler comparison.
     * Helper contracts, units and semantic meaning remain unresolved. */
    __asm__("" : "=r"(outgoing));
    raw3=SpeedwayController_D_8006C5BC;
    work2=8;outgoing[6]=work2;
    work2=M2C_FIELD(temp_s0,volatile int*,0);
    var_a1=raw3*10+selected8;
    raw3=(int)SpeedwayController_unk_ovlheader_80074388;
    work2*=4;outgoing[4]=raw3;
    raw3=(int)temp_s0-16;work2+=raw3;outgoing[5]=work2;
    temp_v0=SpeedwayController_func_8002803C(var_a0,var_a1,arg6,arg7);
    raw3=*temp_s0;SpeedwayController_D_8006FA86=temp_v0;temp_s0[1]=raw3;
footerDone:;
}
#undef M2C_FIELD


typedef struct { unsigned char reserved00[0xA]; unsigned short threshold; unsigned char reserved0C[4]; unsigned char enabled; unsigned char reserved11[3]; } DecodedSelectorDescriptor;
typedef struct { unsigned char reserved00[0xC]; unsigned char* records; } DecodedSelectorAttachment;
typedef struct { int minimum,maximum,timerMinimum,timerMaximum; DecodedSelectorAttachment* attachment; int timer,handle; } DecodedSelectorUpdate;
extern unsigned char* D_8006C708;
extern DecodedSelectorDescriptor* D_8006C6A0;
extern int D_8006E044,D_8006E028;
int func_8004F334(Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_80036518(void*,void*,int*);
void func_level_25_8007E224(Moby* actor) {
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
void func_level_25_8007E430(void *input) {
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


void func_level_25_8007F584(Moby* moby) {
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
void func_level_25_8007F5A4(Moby* argument) {
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
