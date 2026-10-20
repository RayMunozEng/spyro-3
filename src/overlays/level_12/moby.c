#include "common.h"
#include "mobyutil.h"
#include "spu.h"
#include "savepoint.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "spyro.h"
#include "ovl_header.h"

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
void func_level_12_80074F50(void *input) {
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
void func_level_12_80075BAC(Moby* argument) {
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

/* AI-generated; not human reviewed. Verified 75F38 sibling with original
 * D_8006C568==1 gate. Raw units, helper meanings and cadence unresolved. */
extern int Controller75F38Gate __asm__("D_8006C568");
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
void func_level_12_80076238(void *input) {
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
    register int var_a1_2 __asm__("$4");
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
            { register unsigned int rawFlag __asm__("$2")=Controller75F38D_8006E534;
              __asm__("" : "=r"(rawFlag) : "0"(rawFlag));
              var_a1_2 = rawFlag != 0; }
        }
        __asm__ volatile("" : "=r"(var_a1_2) : "0"(var_a1_2) : "memory");
        if (Controller75F38Gate == 1) {
            var_a1_2 = 0;
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

typedef struct { short timer; unsigned char selector,reserved03; unsigned char reserved04[0x10]; Moby* target; } DecodedFocusTag;
extern int D_8006581C,D_80065810,D_80065818,D_8006C578,D_8006C574;
extern Moby* D_8006C65C;
int func_8004F334(Vector3D*,Vector3D*);
int func_80013E38(Vector3D*,Vector3D*,int);
void func_80037014(Moby*);
void func_80036A68(Moby*,int,int,int);
int rand(void);
void func_level_12_800777A4(Moby* moby) {
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
void func_level_12_80077A64(Moby* argument) {
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
void func_level_12_80077F84(Moby *moby) {
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
void func_level_12_80078288(void *input) {
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
void func_level_12_80078DFC(Moby* moby) {
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
void func_level_12_8007922C(Moby* moby) {
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
void func_level_12_80079594(Moby* owner) {
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

extern int D_8006C5C8;
void func_level_12_80079720(Moby* moby) {
    if (!*(int*)moby->mobyTag || moby->substate) {
        register int mode __asm__("$3");
        register int expected __asm__("$2");
        register int count __asm__("$4");
        register int selector __asm__("$5");
        register Vector3D* position __asm__("$6");
        /* Empty constraints retain the original constant/callback load order. */
        mode = D_8006C5C8;
        __asm__("" : : "r"(mode) : "$2");
        expected = 2;
        __asm__("" : "=r"(expected) : "0"(expected), "r"(mode));
        count = 2;
        if (mode == expected) count = 3;
        selector = 0x45;
        position = 0;
        __asm__("" : "=r"(count), "=r"(selector), "=r"(position)
            : "0"(count), "1"(selector), "2"(position) : "memory");
        SpawnParticle(count, selector, position, 0);
    }
}

typedef struct {
    unsigned char reserved00[0x18];
    EnemyTag enemy;
    int timer,count;
} DecodedEnemyDelay;
extern int D_8006C770;
int func_8003636C(int,int);
void func_80037168(Moby*,void*,int);
void func_level_12_80079794(Moby* actor) {
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

extern Moby* D_8006C550;
void func_level_12_80079960(Moby* moby) {
    int* tag = moby->mobyTag;
    if (moby->state == 0) {
        if (moby->damageFlags) {
            func_8003BABC(moby, 0, 0);
            tag[0] = 1;
            func_8003B7B4(tag, 4, &savedData);
            func_8003B7B4(tag, 4, &unsavedData);
        }
        if (tag[0]) {
            D_8006C550[tag[1]].substate = 1;
            moby->state = 1;
            func_80034F40(moby, 1);
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80079A30.
* AI generated; not human reviewed. All889 original instructions and22
* original selectors must match, including every actual destination.
* FrameB0 saves S0..S7/FP/RA and retains original SP20..87 local storage.
* Ordinary initialized scan limit24 allocates naturally to FP. A single
* T0 scalar holds four complete low32 C products, then distinct full flags
* and original distance words. No partialHI or overlapping live aliases.
* Original rand result remains complete until independent new A0/A1
* producers; its bit mask occupies the original bounded-call delay.
* Ground checks retain both signed501 comparisons and the original349
* blocked-store entry after the address producer in340's branch delay.
* Original469 enters870 with the already loaded distance; default entries
* reload at869. State21 preserves independent3500/10240/8000 predicates.
* Shared state writer and counter remain at700/703, not at the earlier
* substate0 entry. Timer30/15/0, signed70 clamp and all load widths remain.
* Six independent table views resolve to exact original zero addends.
* Empty metadata consumes full initialized words or clobbers only before
* their new producers, and emits zero CPU instructions. Known helper
* views reuse previously verified source/header and original EXE evidence.
* Compiler/filter/flags unchanged; no CPU opcode assembly or fixedFP.
* Physical units/fixed point, complete helper/caller contracts, cadence
* beyond invocation and synchronized runtime remain open. Confidence is
* binary identity after all gates. Next: human review and retail captures.
* Falsification: every native/linked word, actual transfer/table target,
* owned data, full EXE and every overlay retail hash must remain identical.
*/
/* Original assembly SHA256 f864770e98dcbf04a07112dc12d8742aef247ef6a53c1d5857a6b7ea21773340 */
#define Level12_79A30Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level12_79A30Call1A358View1() __asm__("func_8001A358");
void Level12_79A30Call34F40View1(void*, int) __asm__("func_80034F40");
int Level12_79A30Call35194View1() __asm__("func_80035194");
int Level12_79A30Call35734View1() __asm__("func_80035734");
int Level12_79A30Call3573CView1() __asm__("func_8003573C");
int Level12_79A30Call3585CView1() __asm__("func_8003585C");
int Level12_79A30Call359A4View1(void*, int) __asm__("func_800359A4");
int Level12_79A30Call35A80View1() __asm__("func_80035A80");
int Level12_79A30Call36220View1() __asm__("func_80036220");
int Level12_79A30Call3636CView1() __asm__("func_8003636C");
int Level12_79A30Call369B8View1() __asm__("func_800369B8");
int Level12_79A30Call36A68View1() __asm__("func_80036A68");
int Level12_79A30Call38F14View1() __asm__("func_80038F14");
int Level12_79A30Call3BA00View1() __asm__("func_8003BA00");
int Level12_79A30Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level12_79A30Call4EDE8View1() __asm__("func_8004EDE8");
int Level12_79A30Call4F178View1() __asm__("func_8004F178");
int Level12_79A30Call4F1C8View1() __asm__("func_8004F1C8");
int Level12_79A30Call4F264View1(int, int) __asm__("func_8004F264");
int Level12_79A30Call4F334View1() __asm__("func_8004F334");
int Level12_79A30Call55B18View1() __asm__("func_80055B18");
int Level12_79A30Call55D24View1() __asm__("func_80055D24");
int Level12_79A30Call55E84View1() __asm__("func_80055E84");
int Level12_79A30DatarandView1(void) __asm__("rand");
extern int Level12_79A30Data658A0View1 __asm__("D_800658A0");
extern int Level12_79A30Data65920View1 __asm__("D_80065920");
extern int Level12_79A30Data6C550View1 __asm__("D_8006C550");
extern int Level12_79A30Data6C58CView1 __asm__("D_8006C58C");
extern int Level12_79A30Data6C640View1 __asm__("D_8006C640");
extern int Level12_79A30Data6C648View1 __asm__("D_8006C648");
extern int Level12_79A30Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level12_79A30Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level12_79A30Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level12_79A30Data70300View1 __asm__("D_80070300");
extern int Level12_79A30Data70328View1 __asm__("D_80070328");
extern void*(*Level12_79A30DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
extern short Level12_79A30Data65920View2 __asm__("D_80065920 + 0x0");
extern short Level12_79A30Data658A0View2 __asm__("D_800658A0 + 0x00");
extern short Level12_79A30Data65920View3 __asm__("D_80065920 + 0x000");
extern short Level12_79A30Data658A0View3 __asm__("D_800658A0 + 0x0000");
extern short Level12_79A30Data65920View4 __asm__("D_80065920 + 0x00000");
extern short Level12_79A30Data658A0View4 __asm__("D_800658A0 + 0x000000");
void func_level_12_80079A30(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), originalTemporary8 __asm__("$8");
    register void *ownerRecord20 __asm__("$20");
    register int privateRecord21 __asm__("$21"), retainedHeadingOrRecord16 __asm__("$16"), retainedVectorOrPlayerBase17 __asm__("$17"), retainedScanStep18 __asm__("$18"), retainedBlockedFlagIndex19 __asm__("$19"), retainedScanDirection22 __asm__("$22"), retainedScanHeadingOffset23 __asm__("$23");
    int originalScanLimit;
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84;
    }
    originalFrame;
    int temporaryWord9;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord7;
    int temporaryWord6;
    int temporaryWord10;
    ownerRecord20 = input;
    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20));
    privateRecord21 = Level12_79A30Field(ownerRecord20, void **, 0);
    originalFrame.sp70 = Level12_79A30Call4F334View1(ownerRecord20 + 0xC, (int)&Level12_79A30Data70328View1);
    if (Level12_79A30Field(ownerRecord20, int *, 0x18) & 0x90000) {
        if (Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) != 6) {
            temporaryWord5 = Level12_79A30Field(privateRecord21, int *, 0x74);
            if (temporaryWord5 != -1) {
                Level12_79A30Field(((temporaryWord5 * 0x58) + Level12_79A30Data6C550View1), signed char *, 0x48) = 0;
            }
            Level12_79A30Call36A68View1(ownerRecord20, 1, 0, 0);
            Level12_79A30Call38F14View1(ownerRecord20, privateRecord21, 1, 6);
            goto block_5;
        }
    }
    else {
    block_5:
        if (Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) != 6) {
            temporaryWord1 = Level12_79A30Field(privateRecord21, int *, 0x18);
            if (temporaryWord1 >= 0) {
                if (temporaryWord1 >= 0x1C21) {
                    Level12_79A30Field(privateRecord21, int *, 0x18) = -1;
                    temporaryWord13 = 0xF;
                    temporaryWord10 = privateRecord21 + 0xF;
                    do {
                        Level12_79A30Field(temporaryWord10, signed char *, 0x24) = 0;
                        temporaryWord13 -= 1;
                        temporaryWord10 -= 1;
                    }
                    while (temporaryWord13 >= 0);
                    Level12_79A30Field(privateRecord21, int *, 0x5C) = 0;
                    if (Level12_79A30Field(privateRecord21, unsigned char *, 0x22) != 0) {
                        temporaryWord3 = Level12_79A30Call4E880View1(Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0) - Level12_79A30Field(ownerRecord20, int *, 0xC), Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 4) - Level12_79A30Field(ownerRecord20, int *, 0x10), 0);
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0x20C) = 0x10000480;
                        temporaryWord4 = (temporaryWord3 & 0xFF) * 2;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0x23C) = 0x31;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0x21C) = (int) ((int) (Level12_79A30Field((int)&Level12_79A30Data65920View2, short*, temporaryWord4) * 0x2D) >> 0xB);
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0x220) = (int) ((int) (Level12_79A30Field((int)&Level12_79A30Data658A0View2, short*, temporaryWord4) * 0x2D) >> 0xB);
                    }
                }
                else {
                    originalFrame.sp78 = 0;
                    Level12_79A30Field(privateRecord21, int *, 0x18) = (int) (temporaryWord1 + (Level12_79A30Data6C648View1 * 0x78));
                    temporaryWord7 = Level12_79A30Field(ownerRecord20, unsigned char *, 0x48);
                    originalScanLimit = 24;
                    if ((temporaryWord7 != 0x14) && ({rawWord2 = 1;__asm__("":"=r"(rawWord2):"0"(rawWord2));retainedHeadingOrRecord16 = (int)&originalFrame.sp40;temporaryWord7 != rawWord2;})) {
                        __asm__("":"=r"(originalScanLimit):"0"(originalScanLimit));
                        Level12_79A30Call4F1C8View1(retainedHeadingOrRecord16, (int)&Level12_79A30Data70328View1, (int)ownerRecord20+12);
                        temporaryWord2 = Level12_79A30Call4EDE8View1(&originalFrame.sp40, 0);
                        if (Level12_79A30Field(privateRecord21, unsigned char *, 0x22) == 0) {
                            temporaryWord8 = Level12_79A30Field(privateRecord21, int *, 0x18);
                            if ((temporaryWord2 < temporaryWord8) && ((temporaryWord8 - temporaryWord2) < 0x7D0) && ((Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 8) - Level12_79A30Field(ownerRecord20, int *, 0x14)) < 0x200)) {
                                Level12_79A30Field(privateRecord21, unsigned char *, 0x22) = 1U;
                            }
                            goto resetOriginalScanDirection;
                        }
                        goto prepareOriginalPlayerDescriptor;
                    }
                    resetOriginalScanDirection:__asm__("":"=r"(originalScanLimit):"0"(originalScanLimit));
                    retainedScanDirection22 = -1;
                    if (Level12_79A30Field(privateRecord21, unsigned char *, 0x22) != 0) {
                        prepareOriginalPlayerDescriptor:__asm__("":"=r"(originalScanLimit):"0"(originalScanLimit));
                        argumentWord6 = 0;
                        __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
                        retainedVectorOrPlayerBase17 = (int)&Level12_79A30Data70328View1;
                        __asm__("":"=r"(retainedVectorOrPlayerBase17):"0"(retainedVectorOrPlayerBase17));
                        {
                            int retainedHeading = Level12_79A30Call4E880View1(Level12_79A30Field(retainedVectorOrPlayerBase17, int*, 0) - Level12_79A30Field(ownerRecord20, int *, 0xC), Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 4) - Level12_79A30Field(ownerRecord20, int *, 0x10), argumentWord6);
                            Level12_79A30Call4F178View1(&originalFrame.sp50, ownerRecord20 + 0xC);
                            retainedHeadingOrRecord16 = retainedHeading;
                        }
                        retainedHeadingOrRecord16 = (retainedHeadingOrRecord16 & 0xFF) * 2;
                        rawWord3 = Level12_79A30Field((int)&Level12_79A30Data65920View3, short*, retainedHeadingOrRecord16);
                        __asm__("":::"$2", "memory");
                        rawWord2 = Level12_79A30Field(privateRecord21, int*, 24);
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        originalTemporary8 = rawWord3*rawWord2;
                        argumentWord7 = 0x10000000;
                        argumentWord4 = originalFrame.sp50;
                        rawWord3 = originalFrame.sp58;
                        __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8), "r"(argumentWord7), "r"(argumentWord4), "r"(rawWord3));
                        rawWord2 = originalTemporary8 >> 12;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        argumentWord4 += rawWord2;
                        originalFrame.sp50 = argumentWord4;
                        argumentWord6 = Level12_79A30Field((int)&Level12_79A30Data658A0View3, short*, retainedHeadingOrRecord16);
                        rawWord2 = Level12_79A30Field((int)&Level12_79A30Data70328View1, int*, 68);
                        argumentWord5 = Level12_79A30Field(privateRecord21, int*, 24);
                        argumentWord7 |= 0x8080;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int*, 524) = argumentWord7;
                        argumentWord7 = Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char*, 14);
                        rawWord3 += rawWord2;
                        originalTemporary8 = argumentWord6*argumentWord5;
                        argumentWord5 = Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char*, 12);
                        argumentWord6 = Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char*, 13);
                        __asm__("":::"$2", "memory");
                        rawWord2 = 49;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        originalFrame.sp58 = rawWord3;
                        __asm__("":::"memory");
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int*, 572) = rawWord2;
                        Level12_79A30Field(retainedVectorOrPlayerBase17, int*, 556) = argumentWord4;
                        __asm__("":::"memory");
                        rawWord2 = originalFrame.sp54;
                        __asm__("":::"memory");
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int*, 564) = rawWord3;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char*, 554) = argumentWord7;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char*, 552) = argumentWord5;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char*, 553) = argumentWord6;
                        __asm__ volatile("":"=r"(originalTemporary8):"0"(originalTemporary8), "r"(rawWord2):"memory");
                        rawWord3 = originalTemporary8 >> 12;
                        __asm__("":"=r"(rawWord3):"0"(rawWord3));
                        rawWord2 += rawWord3;
                        originalFrame.sp54 = rawWord2;
                        Level12_79A30Field((int)&Level12_79A30Data70328View1, int*, 560) = rawWord2;
                        if (({rawWord2 = Level12_79A30Field(privateRecord21, int*, 92);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord6 = retainedVectorOrPlayerBase17+556;rawWord2 != 0;})) {
                            Level12_79A30Call4F1C8View1(&originalFrame.sp60, privateRecord21+92, argumentWord6);
                            if (Level12_79A30Call4EDE8View1(&originalFrame.sp60, 1) >= 0x191) {
                                Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0x20C) = 0;
                                Level12_79A30Field(privateRecord21, unsigned char *, 0x22) = 0U;
                            }
                        }
                        retainedScanDirection22 = -1;
                        if (Level12_79A30Field(privateRecord21, unsigned char *, 0x22) != 0) {
                            __asm__ volatile("":"=r"(retainedScanDirection22):"0"(retainedScanDirection22):"memory");
                            Level12_79A30Call4F178View1(privateRecord21+92, (int)&Level12_79A30Data70328View1+556);
                            retainedScanDirection22 = -1;
                        }
                    }
                    do {
                        if (retainedScanDirection22 > 0) {
                            __asm__ volatile("":::"$8", "memory");
                            originalTemporary8 = 1;
                            __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8));
                            originalFrame.sp78 = originalTemporary8;
                        }
                        retainedScanStep18 = 0;
                        if (originalScanLimit != 0) {
                            retainedScanHeadingOffset23 = 0;
                        scanOriginalParticleDirections:
                            originalTemporary8 = 1;
                            __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8));
                            retainedBlockedFlagIndex19 = 0;
                            if (retainedScanDirection22 == originalTemporary8) {
                                rawWord2 = originalScanLimit;
                                if (originalScanLimit < 0) {
                                    rawWord2 = originalScanLimit+3;
                                }
                                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                                retainedBlockedFlagIndex19 = rawWord2 >> 2;
                            }
                            temporaryWord11 = retainedScanStep18;
                            if (retainedScanStep18 < 0) {
                                temporaryWord11 = retainedScanStep18 + 3;
                            }
                            retainedBlockedFlagIndex19 = retainedBlockedFlagIndex19 + (temporaryWord11 >> 2);
                            if (Level12_79A30Field((privateRecord21 + retainedBlockedFlagIndex19), unsigned char *, 0x24) == 0) {
                                __asm__("":"=r"(retainedBlockedFlagIndex19):"0"(retainedBlockedFlagIndex19));
                                {
                                    int originalRandomBit = Level12_79A30DatarandView1();
                                    __asm__ volatile("":::"$4", "$5", "memory");
                                    argumentWord4 = -150;
                                    argumentWord5 = 150;
                                    __asm__("":"=r"(originalRandomBit):"0"(originalRandomBit), "r"(argumentWord4), "r"(argumentWord5));
                                    originalRandomBit &= 1;
                                    retainedHeadingOrRecord16 = Level12_79A30Field(privateRecord21, int*, 28);
                                    retainedVectorOrPlayerBase17 = Level12_79A30Field(privateRecord21, int*, 24);
                                    retainedHeadingOrRecord16 += retainedScanHeadingOffset23;
                                    retainedHeadingOrRecord16 += originalRandomBit;
                                    __asm__("":"=r"(retainedHeadingOrRecord16):"0"(retainedHeadingOrRecord16));
                                    retainedHeadingOrRecord16 &= 255;
                                    rawWord2 = Level12_79A30Call3636CView1(argumentWord4, argumentWord5);
                                }
                                retainedHeadingOrRecord16 *= 2;
                                rawWord3 = Level12_79A30Field((int)&Level12_79A30Data65920View4, short*, retainedHeadingOrRecord16);
                                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                                originalTemporary8 = rawWord3*retainedVectorOrPlayerBase17;
                                argumentWord4 = -150;
                                argumentWord5 = 150;
                                rawWord3 = Level12_79A30Field(ownerRecord20, int*, 12);
                                __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8), "r"(argumentWord4), "r"(argumentWord5), "r"(rawWord3));
                                argumentWord6 = originalTemporary8 >> 12;
                                __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
                                rawWord3 += argumentWord6;
                                rawWord3 += rawWord2;
                                originalFrame.sp20 = rawWord3;
                                rawWord2 = Level12_79A30Call3636CView1(argumentWord4, argumentWord5);
                                rawWord3 = Level12_79A30Field((int)&Level12_79A30Data658A0View4, short*, retainedHeadingOrRecord16);
                                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                                originalTemporary8 = rawWord3*retainedVectorOrPlayerBase17;
                                rawWord3 = Level12_79A30Field(ownerRecord20, int*, 16);
                                __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8), "r"(rawWord3));
                                argumentWord4 = originalTemporary8 >> 12;
                                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                                rawWord3 += argumentWord4;
                                rawWord3 += rawWord2;
                                originalFrame.sp24 = rawWord3;
                                rawWord3 = Level12_79A30Field(ownerRecord20, int*, 20);
                                __asm__("":::"$2", "memory");
                                rawWord2 = Level12_79A30Data6C640View1;
                                __asm__("":::"$8", "memory");
                                originalTemporary8 = originalFrame.sp78;
                                rawWord2 &= 1;
                                originalFrame.sp28 = rawWord3;
                                if (rawWord2 != originalTemporary8) goto reloadOriginalParticleOne;
                                rawWord2 = retainedScanStep18&3;
                                argumentWord4 = 1;
                                if (rawWord2) goto spawnOriginalParticleWithOne;
                                argumentWord4 = (int)&originalFrame.sp20;
                                argumentWord5 = 2000;
                                __asm__ volatile("":::"$2", "memory");
                                rawWord2 = rawWord3+1000;
                                originalFrame.sp28 = rawWord2;
                                rawWord2 = Level12_79A30Call1A358View1(argumentWord4, argumentWord5);
                                rawWord3 = originalFrame.sp28;
                                __asm__("":::"$4", "memory");
                                argumentWord4 = rawWord2;
                                rawWord3 -= 1000;
                                originalFrame.sp28 = rawWord3;
                                if (!argumentWord4) goto originalBlockedAddress;
                                rawWord3 = Level12_79A30Field(ownerRecord20, int*, 20);
                                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                                rawWord2 = argumentWord4-rawWord3;
                                if (rawWord2 >= 0){
                                    if (({rawWord2 = rawWord2 < 501;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})){
                                        __asm__ volatile(""::"r"(argumentWord4));
                                        argumentWord4 = 1;
                                        goto spawnOriginalParticleWithOne;
                                    }
                                    rawWord2 = privateRecord21+retainedBlockedFlagIndex19;
                                    goto storeOriginalBlockedFlag;
                                }
                                rawWord2 = rawWord3-argumentWord4;
                                if (({rawWord2 = rawWord2 < 501;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})){
                                    argumentWord4 = 1;
                                    goto spawnOriginalParticleWithOne;
                                }
                                argumentWord4 = 1;
                                originalBlockedAddress:rawWord2 = privateRecord21+retainedBlockedFlagIndex19;
                                storeOriginalBlockedFlag:originalTemporary8 = 1;
                                __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8));
                                Level12_79A30Field(rawWord2, unsigned char*, 36) = originalTemporary8;
                                goto finishOriginalScanPass;
                                reloadOriginalParticleOne:argumentWord4 = 1;
                                spawnOriginalParticleWithOne:argumentWord5 = 0;
                                argumentWord6 = (int)&originalFrame.sp20;
                                argumentWord7 = (int)&originalFrame.sp30;
                                __asm__("":"=r"(argumentWord7):"0"(argumentWord7), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(retainedScanStep18));
                                retainedScanStep18 += 2;
                                rawWord3 = (int)Level12_79A30DataSpawnParticleView1;
                                rawWord2 = 8;
                                originalFrame.sp30 = 0;
                                originalFrame.sp34 = 0;
                                originalFrame.sp38 = rawWord2;
                                ((int(*)())rawWord3)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                                rawWord2 = retainedScanDirection22*2;
                                retainedScanHeadingOffset23 += rawWord2;
                                if (retainedScanStep18 < originalScanLimit) goto scanOriginalParticleDirections;
                                finishOriginalScanPass:;
                            }
                        }
                        retainedScanDirection22 += 2;
                    }
                    while (retainedScanDirection22 < 2);
                }
            }
        }
    }
    switch (Level12_79A30Field(ownerRecord20, unsigned char *, 0x48)) {
    case 0:
        rawWord2 = Level12_79A30Call1A358View1((int)&Level12_79A30Data70328View1, 4096);
        rawWord3 = Level12_79A30Field(ownerRecord20, int*, 20);
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        retainedVectorOrPlayerBase17 = rawWord2-rawWord3;
        rawWord3 = Level12_79A30Field(privateRecord21, int*, 116);
        argumentWord4 = -1;
        if (rawWord3 != argumentWord4) {
            if ((Level12_79A30Data6C7B4View1 & 0x10) || (Level12_79A30Field((int)&Level12_79A30Data70300View1, unsigned char*, Level12_79A30Data6C58CView1) & 0x10)) {
                Level12_79A30Field(privateRecord21, int *, 0x74) = -1;
            }
            else {
                Level12_79A30Field(((rawWord3 * 0x58) + Level12_79A30Data6C550View1), signed char *, 0x48) = 6;
            }
        }
        if (Level12_79A30Field(privateRecord21, int *, 0x38) == 1) {
            Level12_79A30Field(privateRecord21, int *, 0x38) = 0;
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 0x14U;
        }
        if (Level12_79A30Field(privateRecord21, int *, 0x38) == 2) {
            Level12_79A30Field(privateRecord21, int *, 0x38) = 0;
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 0x15U;
        }
        if (Level12_79A30Data6C770View1 != 0) {
            if (Level12_79A30Field(privateRecord21, unsigned char *, 0x23) == 0) {
                Level12_79A30Call34F40View1(ownerRecord20, 9);
                Level12_79A30Field(privateRecord21, unsigned char *, 0x23) = Level12_79A30Call3636CView1(1, 2);
            }
            else {
                Level12_79A30Call34F40View1(ownerRecord20, 0);
                Level12_79A30Field(privateRecord21, unsigned char *, 0x23) = (unsigned char) (Level12_79A30Field(privateRecord21, unsigned char *, 0x23) - 1);
            }
        }
        Level12_79A30Call3573CView1(ownerRecord20, 5, 0, 0);
        if (Level12_79A30Call359A4View1(privateRecord21 + 0x20, 2) != 0) {
            if (({originalTemporary8 = originalFrame.sp70;__asm__("":"=r"(originalTemporary8):"0"(originalTemporary8));rawWord2 = originalTemporary8 < 9216;rawWord2;})) {
                if ((Level12_79A30Call4F264View1(Level12_79A30Field(ownerRecord20, unsigned char *, 0x46), Level12_79A30Call4E880View1(Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0) - Level12_79A30Field(ownerRecord20, int *, 0xC), Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 4) - Level12_79A30Field(ownerRecord20, int *, 0x10), 0)) < 0x10) && (Level12_79A30Call4F264View1(Level12_79A30Field((int)&Level12_79A30Data70328View1, unsigned char *, 0xE), Level12_79A30Call4E880View1(Level12_79A30Field(ownerRecord20, int *, 0xC) - Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 0), Level12_79A30Field(ownerRecord20, int *, 0x10) - Level12_79A30Field((int)&Level12_79A30Data70328View1, int *, 4), 0)) < 0x1C)) {
                    temporaryWord12 = retainedVectorOrPlayerBase17;
                    if (retainedVectorOrPlayerBase17 < 0) {
                        temporaryWord12 = -temporaryWord12;
                    }
                    if (temporaryWord12 < 0x1F4) {
                        Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 3U;
                        Level12_79A30Call34F40View1(ownerRecord20, 3);
                    }
                }
            }
            else goto originalDistanceLoaded;
        }
        goto reloadOriginalDistance;
    case 21:
        if (Level12_79A30Field(ownerRecord20, unsigned char *, 0x3D) != 1) {
            Level12_79A30Data6C770View1 = 0;
            Level12_79A30Field(ownerRecord20, signed char *, 0x40) = 0x72;
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x3D) = 1U;
            Level12_79A30Field(ownerRecord20, signed char *, 0x3F) = 0;
            Level12_79A30Call35734View1(ownerRecord20);
        }
        Level12_79A30Call3573CView1(ownerRecord20, 5, 0, 0);
        rawWord2 = Level12_79A30Call36220View1((int)&Level12_79A30Data70328View1, privateRecord21+68, 0, Level12_79A30Field(privateRecord21, short*, 66));
        if (rawWord2){
            rawWord2 = 1;
            goto activateOriginalOwnerState1;
        }
        originalTemporary8 = originalFrame.sp70;
        __asm__("":"=r"(originalTemporary8):"0"(originalTemporary8));
        if (originalTemporary8 >= 10240){
            rawWord2 = originalTemporary8 < 8000;
            goto checkOriginalDistanceFlag;
        }
        rawWord3 = Level12_79A30Field(ownerRecord20, short*, 56);
        rawWord2 = Level12_79A30Field(ownerRecord20, int*, 20);
        argumentWord4 = Level12_79A30Field((int)&Level12_79A30Data70328View1, int*, 8);
        rawWord3 = rawWord2-rawWord3;
        rawWord2 = rawWord3-argumentWord4;
        if (rawWord2 >= 0){
            if (rawWord2 < 3500){
                rawWord2 = 1;
                goto activateOriginalOwnerState1;
            }
            rawWord2 = originalTemporary8 < 8000;
            goto checkOriginalDistanceFlag;
        }
        rawWord2 = argumentWord4-rawWord3;
        if (rawWord2 >= 3500){
            rawWord2 = 1;
            goto reloadOriginalDistance;
        }
        rawWord2 = 1;
        activateOriginalOwnerState1:Level12_79A30Field(ownerRecord20, unsigned char*, 72) = rawWord2;
        Level12_79A30Call34F40View1(ownerRecord20, 1);
        goto reloadOriginalDistance;
    case 20:
        rawWord3 = Level12_79A30Field(privateRecord21, int*, 60);
        argumentWord4 = Level12_79A30Field(ownerRecord20, unsigned char*, 73);
        rawWord2 = rawWord3*88;
        rawWord3 = Level12_79A30Data6C550View1;
        retainedHeadingOrRecord16 = rawWord3+rawWord2;
        if ((argumentWord4 != 0) || ((unsigned char) Level12_79A30Field(retainedHeadingOrRecord16, unsigned char *, 0x48) >= 0x80U)) {
            Level12_79A30Field(privateRecord21, short *, 0x20) = 0;
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 1U;
            Level12_79A30Call34F40View1(ownerRecord20, 1);
            return;
        }
        Level12_79A30Call3585CView1(ownerRecord20, Level12_79A30Call4E880View1(Level12_79A30Field(retainedHeadingOrRecord16, int *, 0xC) - Level12_79A30Field(ownerRecord20, int *, 0xC), Level12_79A30Field(retainedHeadingOrRecord16, int *, 0x10) - Level12_79A30Field(ownerRecord20, int *, 0x10), 0), 5, 1, 0, 0);
        if (Level12_79A30Field(privateRecord21, int *, 0x18) > 0) {
            if (Level12_79A30Call4F334View1(ownerRecord20 + 0xC, retainedHeadingOrRecord16 + 0xC) < Level12_79A30Field(privateRecord21, int *, 0x18)) {
                Level12_79A30Field(retainedHeadingOrRecord16, signed char *, 0x49) = 1;
            }
        }
        else {
            Level12_79A30Field(retainedHeadingOrRecord16, signed char *, 0x49) = 0;
        }
        temporaryWord9 = Level12_79A30Field(privateRecord21, short *, 0x40);
        switch (temporaryWord9) {
        case 0:
            if ((Level12_79A30Field(ownerRecord20, unsigned char *, 0x49) == 0) && (Level12_79A30Call4F334View1(ownerRecord20 + 0xC, retainedHeadingOrRecord16 + 0xC) < 0x1400)) {
                if (({rawWord2 = 3;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord3 = Level12_79A30Field(ownerRecord20, unsigned char*, 61);__asm__("":"=r"(rawWord3):"0"(rawWord3));argumentWord4 = (int)ownerRecord20;rawWord3 != rawWord2;})) {
                    rawWord2 = 114;
                    Level12_79A30Data6C770View1 = 0;
                    Level12_79A30Field(ownerRecord20, unsigned char*, 64) = rawWord2;
                    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20), "m"(Level12_79A30Field(ownerRecord20, unsigned char*, 64)), "r"(rawWord2), "i"(3));
                    rawWord2 = 3;
                    goto writeSharedOriginalState;
                }
                goto incrementOriginalSequence;
            }
            break;
        case 1:
            if (Level12_79A30Data6C770View1 != 0) {
                if (Level12_79A30Field(ownerRecord20, unsigned char *, 0x3D) != 4) {
                    Level12_79A30Data6C770View1 = 0;
                    Level12_79A30Field(ownerRecord20, signed char *, 0x40) = 0x72;
                    Level12_79A30Field(ownerRecord20, unsigned char *, 0x3D) = 4U;
                    Level12_79A30Field(ownerRecord20, signed char *, 0x3F) = 0;
                    Level12_79A30Call35734View1(ownerRecord20);
                }
                Level12_79A30Field(privateRecord21, int *, 0x18) = 0x1F4;
                argumentWord4 = Level12_79A30Field(ownerRecord20, unsigned char*, 70);
                __asm__("":::"$3", "memory");
                rawWord3 = Level12_79A30Field(privateRecord21, unsigned short*, 64);
                rawWord2 = 50;
                Level12_79A30Field(privateRecord21, short*, 32) = rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3), "m"(Level12_79A30Field(privateRecord21, short*, 32)));
                rawWord3 += 1;
                Level12_79A30Field(privateRecord21, int*, 28) = argumentWord4;
                __asm__("":::"memory");
                Level12_79A30Field(privateRecord21, short*, 64) = rawWord3;
            }
            break;
        case 2:
            if ((Level12_79A30Call359A4View1(privateRecord21 + 0x20, 2) != 0) && (Level12_79A30Data6C770View1 != 0)) {
                if (({rawWord2 = 5;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord3 = Level12_79A30Field(ownerRecord20, unsigned char*, 61);__asm__("":"=r"(rawWord3):"0"(rawWord3));argumentWord4 = (int)ownerRecord20;rawWord3 != rawWord2;})) {
                    rawWord2 = 114;
                    Level12_79A30Data6C770View1 = 0;
                    Level12_79A30Field(ownerRecord20, unsigned char*, 64) = rawWord2;
                    __asm__("":"=r"(ownerRecord20):"0"(ownerRecord20), "m"(Level12_79A30Field(ownerRecord20, unsigned char*, 64)), "r"(rawWord2), "i"(5));
                    rawWord2 = 5;
                    writeSharedOriginalState:__asm__ volatile(""::"r"(rawWord2));
                    Level12_79A30Field(ownerRecord20, unsigned char*, 61) = rawWord2;
                    Level12_79A30Field(ownerRecord20, unsigned char*, 63) = 0;
                    Level12_79A30Call35734View1(argumentWord4);
                }
                incrementOriginalSequence:rawWord2 = Level12_79A30Field(privateRecord21, unsigned short*, 64);
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                rawWord2 += 1;
                Level12_79A30Field(privateRecord21, short*, 64) = rawWord2;
            }
            break;
        case 3:
            if (Level12_79A30Data6C770View1 != 0) {
                if (Level12_79A30Field(ownerRecord20, unsigned char *, 0x3D) != 0) {
                    Level12_79A30Data6C770View1 = 0;
                    Level12_79A30Field(ownerRecord20, signed char *, 0x40) = 0x72;
                    Level12_79A30Field(ownerRecord20, unsigned char *, 0x3D) = 0U;
                    Level12_79A30Field(ownerRecord20, signed char *, 0x3F) = 0;
                    Level12_79A30Call35734View1(ownerRecord20);
                }
                Level12_79A30Field(privateRecord21, short *, 0x40) = 0;
            }
            break;
        }
        goto reloadOriginalDistance;
    case 1:
        temporaryWord6 = Level12_79A30Field(privateRecord21, void **, 0x34);
        argumentWord5 = Level12_79A30Field(ownerRecord20, int *, 0x14);
        rawWord2 = Level12_79A30Field(((Level12_79A30Field(temporaryWord6, short*, 2)*16)+Level12_79A30Field(temporaryWord6, int*, 12)), int*, 8);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawWord3 = rawWord2-argumentWord5;
        if (rawWord3 >= 71){
            rawWord3 = 70;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
        }
        if (({rawWord2 = rawWord3 < -70;__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = (int)ownerRecord20;rawWord2;}))rawWord3 = -70;
        argumentWord6 = 256;
        __asm__("":"=r"(argumentWord6):"0"(argumentWord6), "r"(argumentWord5), "r"(rawWord3));
        rawWord2 = argumentWord5+rawWord3;
        Level12_79A30Field(ownerRecord20, int*, 20) = rawWord2;
        if (Level12_79A30Call35A80View1(argumentWord4, Level12_79A30Field(privateRecord21, void **, 0x34), argumentWord6, 0x78, 0, 6, 0x28, 1) & 2) {
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 0U;
            goto callSharedOriginalReset;
        }
        goto reloadOriginalDistance;
    case 3:
        if (Level12_79A30Call55E84View1(ownerRecord20) >= 9) {
            if (Level12_79A30Field(privateRecord21, int *, 0x18) < 0) {
                Level12_79A30Field(privateRecord21, int *, 0x18) = 0x12C;
                rawWord2 = Level12_79A30Field(ownerRecord20, unsigned char*, 70);
                __asm__("":::"memory");
                Level12_79A30Field(privateRecord21, unsigned char*, 34) = 0;
                Level12_79A30Field(privateRecord21, int*, 28) = rawWord2;
            }
        }
        Level12_79A30Call3573CView1(ownerRecord20, 4, 0, 0);
        if (Level12_79A30Data6C770View1 != 0) {
            Level12_79A30Field(privateRecord21, short *, 0x20) = 0x28;
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 4U;
            Level12_79A30Call34F40View1(ownerRecord20, 4);
        }
        goto reloadOriginalDistance;
    case 4:
        Level12_79A30Call3573CView1(ownerRecord20, 4, 0, 0);
        if ((Level12_79A30Call359A4View1(privateRecord21 + 0x20, 2) != 0) && (Level12_79A30Data6C770View1 != 0)) {
            Level12_79A30Field(ownerRecord20, unsigned char *, 0x48) = 5U;
            Level12_79A30Call34F40View1(ownerRecord20, 5);
        }
        goto reloadOriginalDistance;
    case 5:
        Level12_79A30Call3573CView1(ownerRecord20, 4, 0, 0);
        if (!Level12_79A30Data6C770View1) goto reloadOriginalDistance;
        rawWord2 = 1;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawWord3 = Level12_79A30Data6C7C4View1;
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        if (rawWord3 == rawWord2) goto originalTimer15;
        if (({rawWord2 = rawWord3 < 2;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})){
            rawWord2 = 30;
            if (rawWord3 == 0) goto storeOriginalTimer;
            Level12_79A30Field(ownerRecord20, unsigned char*, 72) = 0;
            goto callSharedOriginalReset;
        }
        rawWord2 = 2;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if (rawWord3 == rawWord2) goto originalTimerZero;
        Level12_79A30Field(ownerRecord20, unsigned char*, 72) = 0;
        goto callSharedOriginalReset;
        storeOriginalTimer:__asm__ volatile(""::"r"(rawWord2));
        Level12_79A30Field(privateRecord21, short*, 32) = rawWord2;
        goto clearOriginalOwnerState;
        originalTimer15:rawWord2 = 15;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        Level12_79A30Field(privateRecord21, short*, 32) = rawWord2;
        goto clearOriginalOwnerState;
        originalTimerZero:Level12_79A30Field(privateRecord21, short*, 32) = 0;
        clearOriginalOwnerState:Level12_79A30Field(ownerRecord20, unsigned char*, 72) = 0;
        callSharedOriginalReset:Level12_79A30Call34F40View1(ownerRecord20, 0);
        goto reloadOriginalDistance;
    case 6:
        if (Level12_79A30Call35194View1(ownerRecord20, privateRecord21) == 0x100) {
            Level12_79A30Call55D24View1(ownerRecord20, 4);
            Level12_79A30Call3BA00View1(ownerRecord20);
            Level12_79A30Call369B8View1(ownerRecord20, 0x40);
            Level12_79A30Call55B18View1(ownerRecord20);
            return;
        }
        goto reloadOriginalDistance;
    default:
        reloadOriginalDistance:originalTemporary8 = originalFrame.sp70;
        originalDistanceLoaded:__asm__("":"=r"(originalTemporary8):"0"(originalTemporary8));
        rawWord2 = originalTemporary8 < 8000;
        checkOriginalDistanceFlag:if (rawWord2)Level12_79A30Call55D24View1(ownerRecord20, 4);
        return;
    }
}
#undef Level12_79A30Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_12/moby/func_level_12_8007A814.s SHA256 029998c2e089191bd7c60f6885587e0879eac8b75a281b2f4720d7c26399f5c2. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level12_7A814Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Level12_7A814_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level12_7A814_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level12_7A814_D_8006C550 __asm__("D_8006C550");
extern Spyro Level12_7A814_D_80070328 __asm__("D_80070328");
void Level12_7A814_func_80034F40(Moby* moby, int newId) __asm__("func_80034F40");
int Level12_7A814_func_80035194(Moby*, void*) __asm__("func_80035194");
void Level12_7A814_func_80035734(Moby* moby) __asm__("func_80035734");
int Level12_7A814_func_8003573C(Moby* ownerRecord, int arg1, int arg2, int arg3) __asm__("func_8003573C");
int Level12_7A814_func_800359A4(void*, int) __asm__("func_800359A4");
int Level12_7A814_func_8003636C(int low, int high) __asm__("func_8003636C");
void Level12_7A814_func_800369B8() __asm__("func_800369B8");
void Level12_7A814_func_80037014(Moby* moby) __asm__("func_80037014");
void Level12_7A814_func_80038BF8(Moby*, EnemyTag*, int, int) __asm__("func_80038BF8");
void Level12_7A814_func_8003BA00(Moby* moby) __asm__("func_8003BA00");
extern int Level12_7A814_func_8004E880(int, int, int) __asm__("func_8004E880");
extern int Level12_7A814_func_8004F264(int, int) __asm__("func_8004F264");
extern int Level12_7A814_func_8004F334(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level12_7A814_func_80055B18(Moby*) __asm__("func_80055B18");
extern void Level12_7A814_func_80055D24(Moby*, int) __asm__("func_80055D24");
struct _m2c_stack_func_level_12_8007A814 {
    /* 0x00 */ char pad0[0x40];
};
                                                  /* size = 0x40 */

int Level12_7A814_func_80035A80(Moby *, void *, int, int, int, int, int, int) __asm__("func_80035A80");
 /* extern */
int Level12_7A814_func_80036220(Spyro *, void *, int, int) __asm__("func_80036220");
 /* extern */
int Level12_7A814_func_800368A4(Moby *, int, unsigned char) __asm__("func_800368A4");
            /* extern */
unsigned int Level12_7A814_func_80036A68(Moby *, unsigned char, unsigned char, unsigned char) __asm__("func_80036A68");
 /* extern */
extern int Level12_7A814_D_8006C640 __asm__("D_8006C640");
extern int Level12_7A814_D_8006C770 __asm__("D_8006C770");

void func_level_12_8007A814(Moby *ownerRecord) {
    /* SCUS-94467, 8007A814: original 0x40-byte frame;
     saved16..22 at
     * SP+0x20..0x38, RA at SP+0x3C. All field offsets are byte offsets.
     * Numeric units and helper meanings remain unresolved;
      one invocation
     * is verified, not a frame-rate or synchronized gameplay claim.
     * Empty initialized constraints retain original register producers.
     * J148 enters after caller4 preparation;
      J169 skips the timer call.
     * Branch535 retains the original state-literal reload at instruction543.
     * Falsification requires all716 instructions,10 selector/padding words,
     * every control target, and complete original EXE/overlay hashes. */
    EnemyTag *privateRecord;
    register Vector3D *subPosition4 __asm__("4");
    Moby *pairedRecord;
    Moby *selectedRecord;
    register int modeWord3 __asm__("3");
    int temp_v1_2;
    int temp_v1_5;
    int temp_s0_2;
    register int savedWord19 __asm__("19");
    int callbackWord19;
    register int predicateWord2 __asm__("2");
    register int distanceWord22 __asm__("22");
    register int distanceLimit21 __asm__("21");
    register int heightLimit20 __asm__("20");
    register int distance2 __asm__("2");
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_8;
    int temp_v1_11;
    int temp_v1_13;
    int temp_v1_14;
    int temp_v1_15;
    int temp_v1_6;
    int temp_v1_7;
    int temp_v1_8;
    register int sharedParameter5 __asm__("5");
    register Moby *sharedCaller4 __asm__("4");
    register int var_v0 __asm__("2");
    int var_v0_3;
    int var_v0_4;
    unsigned int temp_v1;
    unsigned int temp_v1_12;
    unsigned int temp_v1_3;
    unsigned int temp_v1_4;
    register unsigned int sharedState2 __asm__("2");
    void *temp_a0;
    void *temp_v1_9;

    privateRecord = ownerRecord->mobyTag;
    if ((Level12_7A814_D_8006C640 == 0) && (Level12_7A814_func_8004F334((Vector3D *)((unsigned char *)ownerRecord + 0xC), &Level12_7A814_D_80070328.position) < 0xBB8)) {
        Level12_7A814_func_80036A68(ownerRecord, 1, 0, 0);
        goto block_129;
    }
    if ((ownerRecord->damageFlags & 0x8A0000) && (ownerRecord->state != 8)) {
        Level12_7A814_func_80036A68(ownerRecord, 0, 0, 0);
        Level12_7A814_func_80038BF8(ownerRecord, privateRecord, 6, 8);
        temp_v0 = Level12_7A814Field(privateRecord, int *, 0x44);
        if (temp_v0 != 0) {
            privateRecord->unk16 = (signed char) temp_v0;
        }
    }
    Level12_7A814Field(privateRecord, int *, 0x48) = Level12_7A814_func_800368A4(ownerRecord, Level12_7A814Field(privateRecord, int *, 0x48), 2);
    ownerRecord->damageFlags = 0;
    if (Level12_7A814Field(privateRecord, short *, 0x24) == 3) {
        Level12_7A814_func_80037014(ownerRecord);
    }
    temp_v1 = ownerRecord->state;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        temp_v1_2 = Level12_7A814Field(privateRecord, short *, 0x24);
        if (temp_v1_2 == 1) {
            pairedRecord = &Level12_7A814_D_8006C550[Level12_7A814Field(privateRecord, int *, 0x28)];
            temp_v1_3 = pairedRecord->state;
            if ((temp_v1_3 >= 0x80U) || (temp_v1_3 == 8)) {
                ownerRecord->substate = 0;
            }
            temp_v1_4 = ownerRecord->substate;
            if (temp_v1_4 == 1) goto subOne;
            if ((int)temp_v1_4 >= 2) goto subHigh;
            if (temp_v1_4 == 0) goto subZero;
            goto subEnd;
subHigh:
            if (temp_v1_4 == 2) goto subTwo;
            if (temp_v1_4 == 3) goto subThree;
            goto subEnd;
subZero:
                savedWord19 = Level12_7A814_func_80035A80(ownerRecord, Level12_7A814Field(privateRecord, void **, 0x20), 0x100, 0x8C, 0, 6, 0x28, 5);
                { register Moby *animationCaller4 __asm__("4");
                 animationCaller4 = ownerRecord;
                if (ownerRecord->animationState.nextId != 7) {
                    Level12_7A814_D_8006C770 = 0;
                    ownerRecord->animationProgress = 0x72;
                    ownerRecord->animationState.nextId = 7;
                    ownerRecord->animationState.nextFrame = 0;
                    Level12_7A814_func_80035734(animationCaller4);
                }
                }
                predicateWord2 = savedWord19 & 1;
                 __asm__("" : "=r"(predicateWord2) : "0"(predicateWord2));
                subPosition4 = &ownerRecord->position;
                if (predicateWord2) {
                    temp_v1_5 = Level12_7A814Field(Level12_7A814Field(privateRecord, void **, 0x20), short *, 2);
                    if ((temp_v1_5 != 0) && (temp_v1_5 != 2)) {

                    } else {
                        goto block_34;
                    }
                }
                __asm__("" : "=r"(savedWord19) : "0"(savedWord19));
                goto subPrepared;
subOne:
                if (Level12_7A814_func_8003573C(ownerRecord, 5, 4, 1) != 0) {
                    if (ownerRecord->animationState.nextId != 0) {
                        Level12_7A814_D_8006C770 = 0;
                        ownerRecord->animationProgress = 0x72;
                        ownerRecord->animationState.nextId = 0;
                        ownerRecord->animationState.nextFrame = 0;
                        Level12_7A814_func_80035734(ownerRecord);
                    }
                    Level12_7A814Field(privateRecord, short *, 0x26) = 0x14;
                    goto block_34;
                }
                goto subEnd;
subTwo:
                if (Level12_7A814_func_800359A4(((unsigned char *)privateRecord + 0x26), 2) != 0) {
block_34:
                        ownerRecord->substate += 1;
                }
                goto subEnd;
subThree:
                if (pairedRecord->substate == temp_v1_4) {
                    ownerRecord->substate = 0;
                    pairedRecord->substate = 0;
                }
                goto subEnd;
subEnd:
            subPosition4 = &ownerRecord->position;
subPrepared:
            { register int returned2 __asm__("2");
             returned2 = Level12_7A814_func_8004F334(subPosition4, &Level12_7A814_D_80070328.position);
             savedWord19 = 0x7D0;
            if ((returned2 < 0xDAC) || (Level12_7A814_func_8004F334(&pairedRecord->position, &Level12_7A814_D_80070328.position) < 0xDAC)) {
                { register int word3 __asm__("3");
                 register int word2 __asm__("2");
                 register int global4 __asm__("4");
                 word3 = ownerRecord->distanceToGround;
                 word2 = ownerRecord->position.z;
                 global4 = Level12_7A814_D_80070328.position.z;
                 word3 = word2 - word3;
                 __asm__("" : "=r"(word3), "=r"(global4) : "0"(word3), "1"(global4));
                 word2 = word3 - global4;
                 if (word2 < 0) { var_v0 = (global4 - word3) < 0x7D0;
                 } else { var_v0 = word2 < 0x7D0;
                 } }
                if (var_v0 == 0) {
                    __asm__("" : "=r"(savedWord19) : "0"(savedWord19));
                    { register int word3 __asm__("3");
                     register int word2 __asm__("2");
                     register int global4 __asm__("4");
                     word3 = pairedRecord->distanceToGround;
                     word2 = pairedRecord->position.z;
                     __asm__ volatile("" : : : "memory");
                     global4 = Level12_7A814_D_80070328.position.z;
                     word3 = word2 - word3;
                     __asm__("" : "=r"(word3), "=r"(global4) : "0"(word3), "1"(global4));
                     word2 = word3 - global4;
                     if (word2 >= 0) { if (word2 < savedWord19) goto block_47;
                     } else { word2 = global4 - word3;
                     __asm__("" : "=r"(word2) : "0"(word2));
                     if (word2 < savedWord19) goto block_47;
                     } }
                } else {
block_47:
                    __asm__("" : "=r"(savedWord19) : "0"(savedWord19));
                    if (pairedRecord->state == 0) {
                        pairedRecord->state = 2;
                        if (pairedRecord->animationState.nextId != 2) {
                            pairedRecord->animationProgress = 0x72;
                            pairedRecord->animationState.nextId = 2;
                            pairedRecord->animationState.nextFrame = 0;
                            Level12_7A814_func_80035734(pairedRecord);
                        }
                    }
                    goto block_126;
                }
            }
            }
        } else if (temp_v1_2 == 2) {
            if (Level12_7A814_D_8006C770 != 0) {
                if (Level12_7A814Field(privateRecord, int *, 0x18) == 0) {
                    Level12_7A814_func_80034F40(ownerRecord, 1);
                    Level12_7A814Field(privateRecord, int *, 0x18) = Level12_7A814_func_8003636C(1, 3);
                } else {
                    Level12_7A814_func_80034F40(ownerRecord, 0);
                    Level12_7A814Field(privateRecord, int *, 0x18) = (int) (Level12_7A814Field(privateRecord, int *, 0x18) - 1);
                }
            }
            if (Level12_7A814_func_80036220(&Level12_7A814_D_80070328, ((unsigned char *)privateRecord + 0x2C), 0, 0x320) != 0) {
                sharedCaller4 = ownerRecord;
                 __asm__("" : "=r"(sharedCaller4) : "0"(sharedCaller4));
                 sharedParameter5 = 7;
                sharedState2 = 7;
                Level12_7A814Field(privateRecord, short *, 0x24) = 0;
                goto block_115;
            }
            if (Level12_7A814_func_8004F334(&ownerRecord->position, &Level12_7A814_D_80070328.position) < 0x1194) {
                var_v0_3 = ((ownerRecord->position.z - ownerRecord->distanceToGround) - Level12_7A814_D_80070328.position.z) + Level12_7A814_D_80070328.unk4a;
                if (var_v0_3 < 0) {
                    var_v0_3 = -var_v0_3;
                }
                if (var_v0_3 < 0x7D0) {
                    sharedCaller4 = ownerRecord;
                     __asm__("" : "=r"(sharedCaller4) : "0"(sharedCaller4));
                     sharedParameter5 = 2;
                    sharedState2 = 2;
                    Level12_7A814Field(privateRecord, short *, 0x24) = 0;
                    goto block_115;
                }
            }
        } else {
            if ((Level12_7A814_func_8003573C(ownerRecord, 6, 0xA, 1) != 0) && (Level12_7A814_D_8006C770 != 0)) {
                if (Level12_7A814Field(privateRecord, int *, 0x18) == 0) {
                    Level12_7A814_func_80034F40(ownerRecord, 1);
                    Level12_7A814Field(privateRecord, int *, 0x18) = Level12_7A814_func_8003636C(1, 3);
                } else {
                    Level12_7A814_func_80034F40(ownerRecord, 0);
                    Level12_7A814Field(privateRecord, int *, 0x18) = (int) (Level12_7A814Field(privateRecord, int *, 0x18) - 1);
                }
            }
            if (Level12_7A814_func_8004F334(&ownerRecord->position, &Level12_7A814_D_80070328.position) < 0x1C00) {
                temp_v1_8 = ownerRecord->position.z - ownerRecord->distanceToGround;
                temp_v0_4 = temp_v1_8 - Level12_7A814_D_80070328.position.z;
                if (temp_v0_4 >= 0) {
                    if (temp_v0_4 < 0x9C4) goto block_126;
                    __asm__ volatile("" : : : "memory");
                    return;
                }
                var_v0_4 = (Level12_7A814_D_80070328.position.z - temp_v1_8) < 0x9C4;
                goto block_124;
            } else {
            default:                                /* switch 1 */
                return;
            }
        }
        break;
    case 7:                                         /* switch 1 */
        callbackWord19 = Level12_7A814_func_80035A80(ownerRecord, Level12_7A814Field(privateRecord, void **, 0x20), 0x100, 0xA0, 0, 8, 0x28, 5);
        temp_a0 = Level12_7A814Field(privateRecord, void **, 0x20);
        temp_v1_9 = (Level12_7A814Field(temp_a0, short *, 2) * 0x10) + Level12_7A814Field(temp_a0, int *, 0xC);
        temp_s0_2 = Level12_7A814_func_8004E880(Level12_7A814Field(temp_v1_9, int *, 0) - ownerRecord->position.x, Level12_7A814Field(temp_v1_9, int *, 4) - ownerRecord->position.y, 0);
        if ((Level12_7A814_func_8004F264(temp_s0_2, Level12_7A814_func_8004E880(Level12_7A814_D_80070328.position.x - ownerRecord->position.x, Level12_7A814_D_80070328.position.y - ownerRecord->position.y, 0)) >= 0x40) || (Level12_7A814_func_8004F334(&ownerRecord->position, &Level12_7A814_D_80070328.position) >= 0x7D0)) {
            if (callbackWord19 & 2) {
                ownerRecord->state = 0;
                return;
            }
        } else {
            goto block_126;
        }
        break;
    case 2:                                         /* switch 1 */
        Level12_7A814_func_8003573C(ownerRecord, 7, 0, 0);
        if (Level12_7A814_D_8006C770 != 0) {
            ownerRecord->state = 3;
            Level12_7A814_func_80034F40(ownerRecord, 3);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        distance2 = Level12_7A814_func_8004F334(&ownerRecord->position, &Level12_7A814_D_80070328.position);
         __asm__ volatile("" : : : "memory");
        modeWord3 = Level12_7A814Field(privateRecord, short *, 0x24);
         __asm__("" : "=r"(modeWord3) : "0"(modeWord3));
        __asm__("" : "=r"(ownerRecord) : "0"(ownerRecord));
        distanceWord22 = distance2;
        { register Moby *continue4 __asm__("4");
        if (modeWord3 == 0) {
            { register int height4 __asm__("4");
             register int negative2 __asm__("2");
            if (distanceWord22 < 0x2401) {
                temp_v1_11 = ownerRecord->position.z - ownerRecord->distanceToGround;
                height4 = Level12_7A814_D_80070328.position.z;
                temp_v0_5 = temp_v1_11 - height4;
                if (temp_v0_5 >= 0) {
                    if (temp_v0_5 < 0x7D1) {
                        continue4 = ownerRecord;
                         goto continuePrepared;
                    } else {
                        goto block_105;
                    }
                } else {
                    negative2 = height4 - temp_v1_11;
                    continue4 = ownerRecord;
                    if (negative2 < 0x7D1) goto continuePrepared;
                    goto block_105;
                }
            } else {
                goto block_105;
            }
            }
        } else if (modeWord3 == 1) {
            { register int index3 __asm__("3");
             index3 = Level12_7A814Field(privateRecord, int *, 0x28);
             __asm__("" : "=r"(index3) : "0"(index3));
             distanceLimit21 = 0x1388;
             __asm__("" : "=r"(index3), "=r"(distanceLimit21) : "0"(index3), "1"(distanceLimit21));
             selectedRecord = &Level12_7A814_D_8006C550[index3];
             }
            temp_v1_12 = selectedRecord->state;
             heightLimit20 = 0xBB8;
            { register Vector3D *position4 __asm__("4");
            if (temp_v1_12 >= 0x80U) goto parentNull;
            position4 = &ownerRecord->position;
            if (temp_v1_12 != 8) goto parentPosition;
parentNull:
            selectedRecord = 0;
             __asm__ volatile("" : : : "4");
             position4 = &ownerRecord->position;
parentPosition:
            __asm__("" : "=r"(position4), "=r"(heightLimit20) : "0"(position4), "1"(heightLimit20));
            savedWord19 = (int)&Level12_7A814_D_80070328.position;
             __asm__("" : "=r"(savedWord19) : "0"(savedWord19));
            if ((Level12_7A814_func_8004F334(position4, (Vector3D *)savedWord19) > distanceLimit21) && ((selectedRecord == 0) || (Level12_7A814_func_8004F334(&selectedRecord->position, (Vector3D *)savedWord19) > distanceLimit21))) {
                temp_v0_6 = ownerRecord->position.z - ownerRecord->distanceToGround;
                temp_v1_13 = temp_v0_6 - Level12_7A814_D_80070328.position.z;
                if (temp_v1_13 >= 0) {
                    if (temp_v1_13 <= heightLimit20) {

                    } else {
                        goto block_96;
                    }
                } else if ((Level12_7A814_D_80070328.position.z - temp_v0_6) > heightLimit20) {
block_96:
                    predicateWord2 = 6;
                    if (selectedRecord != 0) {
                        { register int value2 __asm__("2");
                         register int delta3 __asm__("3");
                         register int global4 __asm__("4");
                        delta3 = selectedRecord->distanceToGround;
                         value2 = selectedRecord->position.z;
                         global4 = Level12_7A814_D_80070328.position.z;
                         value2 -= delta3;
                         delta3 = value2 - global4;
                        value2 = global4 - value2;
                        if (delta3 >= 0) {
                            predicateWord2 = delta3 > heightLimit20;
                             __asm__("" : "=r"(predicateWord2) : "0"(predicateWord2));
                             if (predicateWord2) goto block_101;
                            __asm__ volatile("" : : "r"(global4));
                            continue4 = ownerRecord;
                             goto continuePrepared;
                        }
                        if (value2 <= heightLimit20) goto continueUnprepared;
                        {
block_101:
                            __asm__ volatile("" : : "r"(global4));
                            if (selectedRecord != 0) {
                                register int compare2 __asm__("2");
                                 register int parameter5 __asm__("5");
                                 register unsigned int state3 __asm__("3");
                                compare2 = 6;
                                 parameter5 = 6;
                                 state3 = selectedRecord->animationState.nextId;
                                __asm__("" : "=r"(compare2), "=r"(parameter5), "=r"(state3) : "0"(compare2), "1"(parameter5), "2"(state3));
                                selectedRecord->state = parameter5;
                                if (state3 != compare2) {
                                    selectedRecord->animationProgress = 0x72;
                                    selectedRecord->animationState.nextId = parameter5;
                                    selectedRecord->animationState.nextFrame = 0;
                                    Level12_7A814_func_80035734(selectedRecord);
                                }
                            }
                            goto block_105;
                        }
                        }
                    } else {
                        goto ownerSixWrite;
block_105:
                        predicateWord2 = 6;
ownerSixWrite:
                        __asm__("" : "=r"(predicateWord2) : "0"(predicateWord2));
                        ownerRecord->state = predicateWord2;
                        Level12_7A814_func_80034F40(ownerRecord, 6);
                    }
                }
            }
        }
            }
continueUnprepared:
        continue4 = ownerRecord;
continuePrepared:
        __asm__("" : "=r"(continue4) : "0"(continue4));
        __asm__("" : "=r"(distanceWord22) : "0"(distanceWord22));
        Level12_7A814_func_8003573C(continue4, 7, 0, 0);
        }
        if ((Level12_7A814_func_800359A4(((unsigned char *)privateRecord + 0x1C), 2) != 0) && ((predicateWord2 = distanceWord22 < 0x8FC), predicateWord2) && (Level12_7A814_func_8004F264((int) Level12_7A814_D_80070328.bodyRotation.yaw, Level12_7A814_func_8004E880(ownerRecord->position.x - Level12_7A814_D_80070328.position.x, ownerRecord->position.y - Level12_7A814_D_80070328.position.y, 0)) < 0x32)) {
            temp_v1_15 = ownerRecord->position.z - ownerRecord->distanceToGround;
            temp_v0_8 = temp_v1_15 - Level12_7A814_D_80070328.position.z;
            if (temp_v0_8 >= 0) {
                if (temp_v0_8 < 0x4B0) {
                    goto block_114;
                }
            } else if ((Level12_7A814_D_80070328.position.z - temp_v1_15) < 0x4B0) {
block_114:
                { register int table3 __asm__("3");
                 register int word2 __asm__("2");
                table3 = Level12_7A814_D_80065920[ownerRecord->angle.yaw];
                __asm__ volatile("" : "=r"(table3) : "0"(table3) : "4");
                sharedCaller4 = ownerRecord;
                 __asm__("" : "=r"(sharedCaller4), "=r"(table3) : "0"(sharedCaller4), "1"(table3));
                word2 = (table3 * 0x19) >> 0xA;
                 Level12_7A814_D_80070328.unk17e.x = word2;
                __asm__ volatile("" : : : "memory");
                word2 = sharedCaller4->angle.yaw;
                 __asm__("" : "=r"(word2) : "0"(word2));
                 sharedParameter5 = 4;
                 __asm__("" : "=r"(word2), "=r"(sharedParameter5) : "0"(word2), "1"(sharedParameter5));
                 table3 = Level12_7A814_D_800658A0[word2];
                __asm__("" : "=r"(table3) : "0"(table3));
                word2 = 0x28;
                 __asm__("" : "=r"(word2), "=r"(table3) : "0"(word2), "1"(table3));
                 Level12_7A814_D_80070328.unk17e.z = word2;
                __asm__ volatile("" : "=r"(table3) : "0"(table3) : "memory");
                word2 = (table3 * 0x19) >> 0xA;
                 Level12_7A814_D_80070328.unk17e.y = word2;
                 }
                sharedState2 = 4;
                Level12_7A814Field(privateRecord, short *, 0x1E) = 0;
block_115:
                    __asm__("" : "=r"(sharedCaller4), "=r"(sharedParameter5), "=r"(sharedState2) : "0"(sharedCaller4), "1"(sharedParameter5), "2"(sharedState2));
                    sharedCaller4->state = sharedState2;
                    Level12_7A814_func_80034F40(sharedCaller4, sharedParameter5);
                    return;
            }
        }
        break;
        __asm__("" : "=r"(distanceWord22) : "0"(distanceWord22));
    case 6:                                         /* switch 1 */
        if (Level12_7A814_D_8006C770 != 0) {
            ownerRecord->state = 0;
            Level12_7A814_func_80034F40(ownerRecord, 0);
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        Level12_7A814_func_8003573C(ownerRecord, 7, 0, 0);
        Level12_7A814_func_80055D24(ownerRecord, 5);
        if ((unsigned int) (Level12_7A814_D_80070328.movementState - 7) < 2U) {
            Level12_7A814Field(privateRecord, short *, 0x1E) = 1;
        }
        if (Level12_7A814_D_8006C770 != 0) {
            Level12_7A814Field(privateRecord, short *, 0x1C) = 0x78;
            if (Level12_7A814Field(privateRecord, short *, 0x1E) != 0) {
                ownerRecord->state = 5;
                Level12_7A814_func_80034F40(ownerRecord, 5);
                return;
            }
            goto block_125;
        }
        break;
    case 5:                                         /* switch 1 */
        Level12_7A814_func_8003573C(ownerRecord, 7, 0, 0);
        var_v0_4 = Level12_7A814_D_8006C770;
block_124:
                if (var_v0_4 == 0) return;
                {
block_125:
block_126:
                    ownerRecord->state = 2;
                    Level12_7A814_func_80034F40(ownerRecord, 2);
                    return;
                }

    case 8:                                         /* switch 1 */
        Level12_7A814_func_80055D24(ownerRecord, 1);
        if (Level12_7A814_func_80035194(ownerRecord, privateRecord) == 0x100) {
            Level12_7A814_func_80055D24(ownerRecord, 4);
            Level12_7A814_func_8003BA00(ownerRecord);
            Level12_7A814_func_800369B8(ownerRecord, 0x40);
block_129:
            Level12_7A814_func_80055B18(ownerRecord);
        }
        break;
    }
}
#undef Level12_7A814Field


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
void func_level_12_8007B344(Moby* actor) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007B584.
 * AI generated; not human reviewed. All721 original native/linked words,
 * 31 actual selector entries and one zero pad must match:753 owned words.
 * Frame70 (112 bytes) saves S0..S7/FP/RA at SP48..6C and retains SP18..47.
 * The first vector occupies SP20..28 and the second SP30..38. Unwritten
 * reserve bytes are never read. Natural FP retains the original SIN base;
 * there is no fixed FP/SP binding or overlapping live fixed-register alias.
 * Eight complete signed64 products contain both original signed32 operands.
 * Each high/low capture observes the complete HILO result, narrows to int,
 * then applies original shifts/sign corrections. Distinct capture objects
 * keep high/low lifetimes separate. No partial high input is manufactured.
 * The first /100 path retains its original narrowed90/120 numerator before
 * 51EB851F high capture. /40 uses66666667; /7 uses92492493 plus numerator.
 * Five original geometry products narrow before signedSRA12 and later MULT.
 * Original dynamic remainder retains its divisor,zero/overflow checks and
 * complete remainder. Count5,index3 advances to4; index4 advances to0.
 * Raw vector:32767*900=29490300 and signedSRA12=7199. Physical units remain
 * open. Original table index signed LH and unsigned LHU reloads are distinct.
 * Empty metadata consumes complete initialized words/addresses or written
 * fields,or clobbers dead values before fresh producers;zero CPU words.
 * Byte12 owner address precedes its conditional helper flag test,retaining
 * the original A0-address branch delay before the literal300 A2 producer.
 * Common continuation follows all state handlers. State30 signed-halfword
 * updates store before sign extension and share original substate increment.
 * Original flags,literals,widths,helper ABI words and invocation order remain.
 * All actual branch,J,call,data and selector targets plus complete EXE and
 * every-overlay retail hashes are mandatory. Compiler/filter/flags unchanged.
 * Confidence is binary identity after every gate. Full helper/caller chains,
 * units/fixed-point domains,cadence beyond invocation,Rev1 correspondence and
 * synchronized retail runtime remain open. Next:human review and captures.
 */
/* Original assembly SHA256 fd3f51fd61abe43bf5396a3b42ca9b0535b55f10ff2e93d4819903945bf9af23 */
#define Level12_7B584Keep(v) __asm__("":"=r"(v):"0"(v))
/* SCUS-94467 USA Rev0 independent721 candidate. AI generated; not human reviewed. No incoming register value or partial product is consumed. Every native word, actual target and full retail hash is mandatory. */
#define Level12_7B584Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level12_7B584Call13ACCView1() __asm__("func_80013ACC");
void Level12_7B584Call34F40View1(void*,int) __asm__("func_80034F40");
void Level12_7B584Call35734View1(void*) __asm__("func_80035734");
int Level12_7B584Call3573CView1(void*,int,int,int) __asm__("func_8003573C");
int Level12_7B584Call3585CView1(void*,int,int,int,int,int) __asm__("func_8003585C");
int Level12_7B584Call359A4View1(void*,int) __asm__("func_800359A4");
int Level12_7B584Call35EE0View1(void*,int,int,int,int,int) __asm__("func_80035EE0");
int Level12_7B584Call3636CView1(int,int) __asm__("func_8003636C");
int Level12_7B584Call363DCView1(int,int) __asm__("func_800363DC");
int Level12_7B584Call365E4View1() __asm__("func_800365E4");
void Level12_7B584Call37014View1(void*) __asm__("func_80037014");
int Level12_7B584Call37A60View1() __asm__("func_80037A60");
int Level12_7B584Call3BABCView1() __asm__("func_8003BABC");
int Level12_7B584Call4E880View1(int,int,int) __asm__("func_8004E880");
void Level12_7B584Call4F0E8View1(void*,int) __asm__("func_8004F0E8");
void Level12_7B584Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level12_7B584Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
int Level12_7B584Call4F334View1() __asm__("func_8004F334");
void Level12_7B584Call55D24View1(void*,int) __asm__("func_80055D24");
int Level12_7B584DatarandView1(void) __asm__("rand");
extern int Level12_7B584Data658A0View1 __asm__("D_800658A0");
extern int Level12_7B584Data65920View1 __asm__("D_80065920");
extern int Level12_7B584Data6C550View1 __asm__("D_8006C550");
extern int Level12_7B584Data6C58CView1 __asm__("D_8006C58C");
extern int Level12_7B584Data6C770View1 __asm__("D_8006C770");
extern int Level12_7B584Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level12_7B584Data6E160View1 __asm__("D_8006E160");
extern int Level12_7B584Data6E164View1 __asm__("D_8006E164");
extern int Level12_7B584Data70328View1 __asm__("D_80070328");
extern int Level12_7B584Data716ACView1 __asm__("D_800716AC");
extern int(*Level12_7B584DataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_12_8007B584(void *ownerParameter) {
    register int resultOrField2 __asm__("$2"),sampleFieldOrSign3 __asm__("$3"),argumentAddressOrMagic4 __asm__("$4"),argumentOrCosAddress5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7"),signedCapturedWord8 __asm__("$8");
    register int firstVectorAddress20 __asm__("$20"),secondVectorAddress22 __asm__("$22");
    int retainedSinTableBase;
    long long completeSignedProduct;
    int hundredSignedHigh,fortySignedHigh,sevenSignedHigh;
    register void *ownerRecord18 __asm__("$18");
    register int privateRecord19 __asm__("$19"),randomAngleOrSinAddress16 __asm__("$16"),speedAngleOrSinAddress17 __asm__("$17"),emittedCount21 __asm__("$21"),emissionCount23 __asm__("$23");
    struct{
        int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44;
    }
    originalFrame;
    int temp_v0_7;
    int temp_v1_6;
    int temp_v0_11;
    int temp_v0_4;
    int temp_v1_2;
    int var_a0;
    int temp_a0;
    int temp_v1;
    int temp_v1_7;
    int temp_v0_10;
    int temp_v0_2;
    int temp_v0_8;
    int temp_v0_9;
    int temp_v1_4;
    ownerRecord18=ownerParameter;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    temp_v1 = Level12_7B584Field(ownerRecord18, unsigned char *, 0x48);
    privateRecord19 = Level12_7B584Field(ownerRecord18, void **, 0);
    switch (temp_v1) {
    case 0:
        Level12_7B584Call37A60View1(ownerRecord18, privateRecord19 + 0x18, 2, 8, -0xC8);
        Level12_7B584Call3573CView1(ownerRecord18, 0xA, 0, 0);
        if (Level12_7B584Field(privateRecord19, int *, 0x24) == Level12_7B584Field(Level12_7B584Field(privateRecord19,int*,32),int*,0)) {
            sampleFieldOrSign3=Level12_7B584Call4F334View1(ownerRecord18+12,(int)&Level12_7B584Data70328View1);
            Level12_7B584Keep(sampleFieldOrSign3);
            if(sampleFieldOrSign3<4096){
                resultOrField2=Level12_7B584Data6E160View1;
                if(resultOrField2){
                    resultOrField2=sampleFieldOrSign3<4501;
                    goto checkOriginalDistancePredicate;
                }
                Level12_7B584Call13ACCView1(ownerRecord18,12);
                goto continueOriginalDistanceDone;
            }
            resultOrField2=Level12_7B584Data6E160View1;
            if(!resultOrField2)goto continueOriginalDistanceDone;
            resultOrField2=sampleFieldOrSign3<4501;
        checkOriginalDistancePredicate:
            if(!resultOrField2){
                Level12_7B584Keep(resultOrField2);
                Level12_7B584Data6E160View1=0;
                Level12_7B584Data6E164View1=0;
            }
        continueOriginalDistanceDone:
            if (Level12_7B584Field(ownerRecord18, unsigned char *, 0x4C) == 0) {
                Level12_7B584Field(ownerRecord18, signed char *, 0x41) = 1;
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x4C) = 0x30U;
                Level12_7B584Field(ownerRecord18, signed char *, 0x4D) = 1;
                Level12_7B584Call55D24View1(ownerRecord18, 1);
            }
            goto continueOriginalReady;
        }
        Level12_7B584Field(ownerRecord18, signed char *, 0x41) = 0;
        Level12_7B584Field(ownerRecord18, unsigned char *, 0x4C) = 0U;
        Level12_7B584Field(ownerRecord18, signed char *, 0x4D) = 0;
        Level12_7B584Field(ownerRecord18, int *, 8) = 0;
        return;
    continueOriginalReady:
        var_a0 = 0;
        if (Level12_7B584Field(privateRecord19, int *, 0x24) == Level12_7B584Field(Level12_7B584Field(privateRecord19,int*,32),int*,0)) {
            if (Level12_7B584Field(Level12_7B584Field(privateRecord19, void **, 0), short *, 2) == 0) {
                var_a0 = Level12_7B584Field(((Level12_7B584Field(privateRecord19, int *, 0x40) * 0x58) + Level12_7B584Data6C550View1), unsigned char *, 0x48) == 1;
            }
            if (Level12_7B584Field(ownerRecord18, int *, 0x18) & 0x10000) {
                var_a0 = 1;
            }
        }
        if (var_a0 != 0) {
            argumentAddressOrMagic4=(int)ownerRecord18+12;
            if (Level12_7B584Field(((Level12_7B584Field(privateRecord19, short *, 0x1A) * 0xC) + Level12_7B584Field(privateRecord19, int *, 0x44)), int *, 8) != 0) {
                temp_v0_2 = Level12_7B584Field(privateRecord19, void **, 0);
                Level12_7B584Field(privateRecord19, short *, 0x18) = Level12_7B584Call365E4View1(argumentAddressOrMagic4, Level12_7B584Field(temp_v0_2, int *, 0xC) + (Level12_7B584Field(temp_v0_2, short *, 2) * 0x10), 0x12C, -8, &originalFrame.sp18);
            }
            sampleFieldOrSign3=Level12_7B584Field(privateRecord19,short*,0x1A);
            Level12_7B584Keep(sampleFieldOrSign3);
            resultOrField2=sampleFieldOrSign3*3;
            sampleFieldOrSign3=Level12_7B584Field(privateRecord19,int*,0x44);
            resultOrField2*=4;
            resultOrField2+=sampleFieldOrSign3;
            resultOrField2=Level12_7B584Field(resultOrField2,int*,0);
            __asm__ volatile(""::"r"(resultOrField2):"memory");
            sampleFieldOrSign3=Level12_7B584Field(privateRecord19,short*,0x1A);
            Level12_7B584Field(privateRecord19,int*,0x1C)=resultOrField2;
            __asm__("":"=r"(sampleFieldOrSign3):"0"(sampleFieldOrSign3),"m"(Level12_7B584Field(privateRecord19,int*,0x1C)));
            resultOrField2=sampleFieldOrSign3*3;
            sampleFieldOrSign3=Level12_7B584Field(privateRecord19,int*,0x44);
            resultOrField2*=4;
            resultOrField2+=sampleFieldOrSign3;
            __asm__ volatile(""::"r"(resultOrField2):"memory");
            sampleFieldOrSign3=Level12_7B584Field(privateRecord19,unsigned short*,0x1A);
            resultOrField2=Level12_7B584Field(resultOrField2,int*,4);
            sampleFieldOrSign3++;
            Level12_7B584Field(privateRecord19,short*,0x1A)=sampleFieldOrSign3;
            sampleFieldOrSign3=Level12_7B584Data6C7C4View1;
            __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(sampleFieldOrSign3));
            Level12_7B584Field(privateRecord19,int*,4)=resultOrField2;
            resultOrField2=2;
            __asm__ volatile(""::"r"(resultOrField2),"r"(sampleFieldOrSign3):"$4");
            argumentAddressOrMagic4=0x51EB0000;
            if(sampleFieldOrSign3==resultOrField2){
                resultOrField2=Level12_7B584Field(privateRecord19,int*,4);
                __asm__("":"=r"(argumentAddressOrMagic4):"0"(argumentAddressOrMagic4),"r"(resultOrField2));
                argumentAddressOrMagic4|=0x851F;
                sampleFieldOrSign3=resultOrField2*3;
                resultOrField2=sampleFieldOrSign3*16-sampleFieldOrSign3;
                resultOrField2*=2;
                goto captureOriginalHundredProduct;
            }
            Level12_7B584Keep(argumentAddressOrMagic4);
            argumentAddressOrMagic4|=0x851F;
            if(sampleFieldOrSign3)goto continueOriginalHundredDone;
            sampleFieldOrSign3=Level12_7B584Field(privateRecord19,int*,4);
            resultOrField2=sampleFieldOrSign3*16-sampleFieldOrSign3;
            resultOrField2*=8;
            captureOriginalHundredProduct:Level12_7B584Keep(resultOrField2);
            completeSignedProduct=(long long)resultOrField2*(long long)argumentAddressOrMagic4;
            __asm__ volatile(""::"x"(completeSignedProduct));
            resultOrField2>>=31;
            __asm__("":"=h"(hundredSignedHigh):"x"(completeSignedProduct),"r"(resultOrField2));
            signedCapturedWord8=hundredSignedHigh;
            Level12_7B584Keep(signedCapturedWord8);
            sampleFieldOrSign3=signedCapturedWord8>>5;
            sampleFieldOrSign3-=resultOrField2;
            Level12_7B584Field(privateRecord19,int*,4)=sampleFieldOrSign3;
        continueOriginalHundredDone:
            if (Level12_7B584Field(Level12_7B584Field(privateRecord19, void **, 0), short *, 2) == 0) {
                temp_v1_2 = Level12_7B584Data6C58CView1 * 6;
                temp_a0 = Level12_7B584Field((int)&Level12_7B584Data716ACView1,unsigned char*,1+temp_v1_2);
                if (temp_a0 < 0xFFU) {
                    Level12_7B584Field((int)&Level12_7B584Data716ACView1,unsigned char*,1+temp_v1_2) = temp_a0 + 1;
                }
            }
            Level12_7B584Call13ACCView1(ownerRecord18, 0xC);
            resultOrField2=Level12_7B584Field(privateRecord19,short*,0x18);
            if(resultOrField2<=0)goto produceOriginalAnimationTwo;
            resultOrField2=7;
            sampleFieldOrSign3=Level12_7B584Field(ownerRecord18,unsigned char*,0x3D);
            argumentAddressOrMagic4=(int)ownerRecord18;
            if(sampleFieldOrSign3==resultOrField2)goto continueOriginalAnimationDone;
            resultOrField2=114;
            Level12_7B584Data6C770View1=0;
            Level12_7B584Field(ownerRecord18,unsigned char*,0x40)=resultOrField2;
            resultOrField2=7;
            goto storeOriginalAnimationWord;
        produceOriginalAnimationTwo:
            sampleFieldOrSign3=Level12_7B584Field(ownerRecord18,unsigned char*,0x3D);
            resultOrField2=2;
            argumentAddressOrMagic4=(int)ownerRecord18;
            if(sampleFieldOrSign3==resultOrField2)goto continueOriginalAnimationDone;
            resultOrField2=114;
            Level12_7B584Data6C770View1=0;
            Level12_7B584Field(ownerRecord18,unsigned char*,0x40)=resultOrField2;
            resultOrField2=2;
        storeOriginalAnimationWord:
            Level12_7B584Field(ownerRecord18,unsigned char*,0x3D)=resultOrField2;
            Level12_7B584Field(ownerRecord18,unsigned char*,0x3F)=0;
            Level12_7B584Call35734View1(argumentAddressOrMagic4);
        continueOriginalAnimationDone:
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x4A) = 0xFF;
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 2U;
            return;
        }
        if (Level12_7B584Call359A4View1(privateRecord19 + 4, 4) == 2) {
            Level12_7B584Data6E160View1 = 0;
            Level12_7B584Data6E164View1 = 0;
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 6U;
            Level12_7B584Call34F40View1(ownerRecord18, 6);
        }
        temp_v0_4 = Level12_7B584Field(privateRecord19, int *, 4);
        if ((temp_v0_4 != 0) && (temp_v0_4 < 0x5A)) {
            if (Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) != 3) {
                Level12_7B584Data6C770View1 = 0;
                Level12_7B584Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) = 3U;
                Level12_7B584Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level12_7B584Call35734View1(ownerRecord18);
            }
            if ((Level12_7B584Data6C770View1 != 0) && (Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) != 4)) {
                Level12_7B584Data6C770View1 = 0;
                Level12_7B584Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) = 4U;
                Level12_7B584Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level12_7B584Call35734View1(ownerRecord18);
            }
        }
        else if (Level12_7B584Data6C770View1 != 0) {
            if (Level12_7B584Field(privateRecord19, int *, 8) == 0) {
                Level12_7B584Call34F40View1(ownerRecord18, 1);
                Level12_7B584Field(privateRecord19, int *, 8) = Level12_7B584Call3636CView1(1, 2);
            }
            else {
                Level12_7B584Call34F40View1(ownerRecord18, 0);
                Level12_7B584Field(privateRecord19, int *, 8) = (int) (Level12_7B584Field(privateRecord19, int *, 8) - 1);
            }
        }
        goto continueOriginalCommonPhase;
    case 2:
        speedAngleOrSinAddress17 = 0x12C;
        if (Level12_7B584Call37A60View1(ownerRecord18, privateRecord19 + 0x18, 2, 8, -0xC8) != 0) {
            speedAngleOrSinAddress17 = Level12_7B584Field(privateRecord19, int *, 0x1C);
            if (Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) != 2) {
                Level12_7B584Data6C770View1 = 0;
                Level12_7B584Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) = 2U;
                Level12_7B584Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level12_7B584Call35734View1(ownerRecord18);
            }
        }
        temp_v1_4 = Level12_7B584Field(privateRecord19, void **, 0);
        temp_v0_7 = Level12_7B584Field(temp_v1_4, short *, 2);
        if (temp_v0_7 == 0) {
            speedAngleOrSinAddress17 = Level12_7B584Field(privateRecord19, int *, 0x1C);
        }
        temp_v0_8 = (temp_v0_7 * 0x10) + Level12_7B584Field(temp_v1_4, int *, 0xC);
        resultOrField2=Level12_7B584Call4E880View1(Level12_7B584Field(temp_v0_8, int *, 0) - Level12_7B584Field(ownerRecord18, int *, 0xC), Level12_7B584Field(temp_v0_8, int *, 4) - Level12_7B584Field(ownerRecord18, int *, 0x10), 0);
        argumentAddressOrMagic4=(int)ownerRecord18;
        __asm__ volatile(""::"r"(argumentAddressOrMagic4):"$16");
        randomAngleOrSinAddress16=resultOrField2&255;
        Level12_7B584Call3585CView1(argumentAddressOrMagic4, randomAngleOrSinAddress16, 5, 0, 0, 0);
        Level12_7B584Call35EE0View1(ownerRecord18, randomAngleOrSinAddress16, speedAngleOrSinAddress17, 0, 0, 1);
        temp_v0_9 = Level12_7B584Field(privateRecord19, void **, 0);
        if (Level12_7B584Call4F334View1(ownerRecord18 + 0xC, Level12_7B584Field(temp_v0_9, int *, 0xC) + (Level12_7B584Field(temp_v0_9, short *, 2) * 0x10)) < 0x200) {
            argumentOrCosAddress5=Level12_7B584Field(privateRecord19,int*,0);
            Level12_7B584Keep(argumentOrCosAddress5);
            sampleFieldOrSign3=Level12_7B584Field(argumentOrCosAddress5,short*,0);
            resultOrField2=Level12_7B584Field(argumentOrCosAddress5,short*,2);
            argumentAddressOrMagic4=sampleFieldOrSign3+1;
            resultOrField2+=argumentAddressOrMagic4;
            sampleFieldOrSign3=resultOrField2%sampleFieldOrSign3;
            Level12_7B584Field(argumentOrCosAddress5,short*,2)=sampleFieldOrSign3;
            temp_v0_10 = Level12_7B584Field(privateRecord19, void **, 0);
            temp_v1_6 = Level12_7B584Field(temp_v0_10, short *, 2);
            if (temp_v1_6 == 0) {
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 0x14U;
                return;
            }
            if ((temp_v1_6 > 0) && (Level12_7B584Field(((temp_v1_6 * 0x10) + Level12_7B584Field(temp_v0_10, int *, 0xC)), int *, -4) & 1)) {
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                Level12_7B584Call34F40View1(ownerRecord18, 0);
            }
            goto continueOriginalCommonPhase;
        }
        goto continueOriginalCommonPhase;
    case 6:
        if (Level12_7B584Field(ownerRecord18, int *, 0x18) & 0x10000) {
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 0U;
            return;
        }
        if (Level12_7B584Data6C770View1 != 0) {
            Level12_7B584Field(Level12_7B584Field(privateRecord19, void **, 0), short *, 2) = 0;
            Level12_7B584Field(privateRecord19, short *, 0x1A) = 0;
            Level12_7B584Call4F178View1(ownerRecord18 + 0xC, privateRecord19 + 0xC);
            Level12_7B584Call37014View1(ownerRecord18);
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x52) = 0xFE;
            Level12_7B584Call55D24View1(ownerRecord18, 2);
            Level12_7B584Field(ownerRecord18, signed char *, 0x4A) = 0x10;
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 0U;
            Level12_7B584Call34F40View1(ownerRecord18, 0);
        }
        goto continueOriginalCommonPhase;
    case 20:
        if (Level12_7B584Call37A60View1(ownerRecord18, privateRecord19 + 0x18, 2, 8, -0xC8) != 0) {
            Level12_7B584Call3BABCView1(ownerRecord18, 0, 0);
            temp_v0_11 = Level12_7B584Field(privateRecord19, void **, 0x20);
            Level12_7B584Field(temp_v0_11,int*,0) += 1;
            Level12_7B584Data6E160View1 = 0;
            Level12_7B584Data6E164View1 = 0;
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x48) = 0x15U;
            return;
        }
        goto continueOriginalCommonPhase;
    case 21:
        Level12_7B584Field(ownerRecord18, unsigned char *, 0x49) = 0U;
        Level12_7B584Call3573CView1(ownerRecord18, 3, 0, 0);
        goto continueOriginalCommonPhase;
    case 30:
        temp_v1_7 = Level12_7B584Field(ownerRecord18, unsigned char *, 0x49);
        switch (temp_v1_7) {
        case 0:
            if (Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) != 0) {
                Level12_7B584Data6C770View1 = 0;
                Level12_7B584Field(ownerRecord18, signed char *, 0x40) = 0x72;
                Level12_7B584Field(ownerRecord18, unsigned char *, 0x3D) = 0U;
                Level12_7B584Field(ownerRecord18, signed char *, 0x3F) = 0;
                Level12_7B584Call35734View1(ownerRecord18);
            }
            Level12_7B584Field(ownerRecord18, signed char *, 0x41) = 1;
            Level12_7B584Field(ownerRecord18, unsigned char *, 0x4C) = 0x30U;
            Level12_7B584Field(ownerRecord18, signed char *, 0x4D) = 1;
            Level12_7B584Field(ownerRecord18, signed char *, 0x57) = 0x30;
            Level12_7B584Field(privateRecord19, short *, 0x18) = 0;
            if(Level12_7B584Call359A4View1(privateRecord19+0x48,4))goto incrementOriginalSubstate;
            goto continueOriginalCommonPhase;
        case 1:
            resultOrField2=Level12_7B584Field(privateRecord19,unsigned short*,0x18);
            Level12_7B584Keep(resultOrField2);
            resultOrField2+=2;
            Level12_7B584Field(privateRecord19,short*,0x18)=resultOrField2;
            resultOrField2<<=16;
            sampleFieldOrSign3=Level12_7B584Field(ownerRecord18,int*,0x14);
            resultOrField2>>=16;
            sampleFieldOrSign3+=resultOrField2;
            Level12_7B584Field(ownerRecord18,int*,0x14)=sampleFieldOrSign3;
            sampleFieldOrSign3=sampleFieldOrSign3<7501;
            if(!sampleFieldOrSign3)goto incrementOriginalSubstate;
            goto continueOriginalCommonPhase;
        case 2:
            resultOrField2=Level12_7B584Field(privateRecord19,unsigned short*,0x18);
            Level12_7B584Keep(resultOrField2);
            resultOrField2-=3;
            Level12_7B584Field(privateRecord19,short*,0x18)=resultOrField2;
            resultOrField2<<=16;
            sampleFieldOrSign3=resultOrField2>>16;
            if(sampleFieldOrSign3>0)goto addOriginalSignedHeight;
        incrementOriginalSubstate:
            resultOrField2=Level12_7B584Field(ownerRecord18,unsigned char*,0x49);
            Level12_7B584Keep(resultOrField2);
            resultOrField2++;
            Level12_7B584Field(ownerRecord18,unsigned char*,0x49)=resultOrField2;
            goto continueOriginalCommonPhase;
        addOriginalSignedHeight:
            resultOrField2=Level12_7B584Field(ownerRecord18,int*,0x14);
            Level12_7B584Keep(resultOrField2);
            resultOrField2+=sampleFieldOrSign3;
            Level12_7B584Field(ownerRecord18,int*,0x14)=resultOrField2;
            goto continueOriginalCommonPhase;
        }
        goto continueOriginalCommonPhase;
        default:goto continueOriginalCommonPhase;
    }
continueOriginalCommonPhase:
    argumentAddressOrMagic4=Level12_7B584Field(privateRecord19,int*,4);
    emissionCount23=4;
    if(argumentAddressOrMagic4 && argumentAddressOrMagic4<120){
        resultOrField2=0x66666667;
        completeSignedProduct=(long long)argumentAddressOrMagic4*(long long)resultOrField2;
        __asm__ volatile(""::"x"(completeSignedProduct));
        resultOrField2=argumentAddressOrMagic4>>31;
        __asm__("":"=h"(fortySignedHigh):"x"(completeSignedProduct),"r"(resultOrField2));
        signedCapturedWord8=fortySignedHigh;
        Level12_7B584Keep(signedCapturedWord8);
        sampleFieldOrSign3=signedCapturedWord8>>4;
        emissionCount23=sampleFieldOrSign3-resultOrField2;
    }
    sampleFieldOrSign3=Level12_7B584Field(ownerRecord18,unsigned char*,0x48);
    resultOrField2=6;
    if(sampleFieldOrSign3==resultOrField2)emissionCount23=0;
    emittedCount21=0;
    if(emissionCount23>0){
        retainedSinTableBase=(int)&Level12_7B584Data658A0View1;
        Level12_7B584Keep(retainedSinTableBase);
        firstVectorAddress20=(int)&originalFrame.sp20;
        secondVectorAddress22=(int)&originalFrame.sp30;
        do{
            emittedCount21++;
            resultOrField2=Level12_7B584DatarandView1();
            argumentAddressOrMagic4=44;
            argumentOrCosAddress5=64;
            randomAngleOrSinAddress16=resultOrField2&255;
            resultOrField2=Level12_7B584Call3636CView1(argumentAddressOrMagic4,argumentOrCosAddress5);
            argumentAddressOrMagic4=50;
            argumentOrCosAddress5=90;
            speedAngleOrSinAddress17=resultOrField2;
            resultOrField2=Level12_7B584Call3636CView1(argumentAddressOrMagic4,argumentOrCosAddress5);
            randomAngleOrSinAddress16*=2;
            signedCapturedWord8=(int)&Level12_7B584Data65920View1;
            Level12_7B584Keep(signedCapturedWord8);
            sampleFieldOrSign3=randomAngleOrSinAddress16+signedCapturedWord8;
            sampleFieldOrSign3=Level12_7B584Field(sampleFieldOrSign3,short*,0);
            Level12_7B584Keep(sampleFieldOrSign3);
            completeSignedProduct=(long long)sampleFieldOrSign3*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            speedAngleOrSinAddress17*=2;
            argumentOrCosAddress5=speedAngleOrSinAddress17+signedCapturedWord8;
            {
                int captured;
                __asm__("":"=l"(captured):"x"(completeSignedProduct),"r"(argumentOrCosAddress5));
                signedCapturedWord8=captured;
                Level12_7B584Keep(signedCapturedWord8);
            }
            argumentAddressOrMagic4=Level12_7B584Field(argumentOrCosAddress5,short*,0);
            __asm__ volatile(""::"r"(argumentAddressOrMagic4):"$3");
            sampleFieldOrSign3=signedCapturedWord8>>12;
            __asm__("":"=r"(sampleFieldOrSign3):"0"(sampleFieldOrSign3),"r"(argumentAddressOrMagic4));
            completeSignedProduct=(long long)sampleFieldOrSign3*(long long)argumentAddressOrMagic4;
            __asm__ volatile(""::"x"(completeSignedProduct));
            randomAngleOrSinAddress16+=retainedSinTableBase;
            {
                int captured;
                __asm__("":"=l"(captured):"x"(completeSignedProduct),"r"(randomAngleOrSinAddress16));
                signedCapturedWord8=captured;
                Level12_7B584Keep(signedCapturedWord8);
            }
            sampleFieldOrSign3=signedCapturedWord8>>12;
            originalFrame.sp30=sampleFieldOrSign3;
            sampleFieldOrSign3=Level12_7B584Field(randomAngleOrSinAddress16,short*,0);
            Level12_7B584Keep(sampleFieldOrSign3);
            completeSignedProduct=(long long)sampleFieldOrSign3*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            {
                int captured;
                __asm__("":"=l"(captured):"x"(completeSignedProduct));
                signedCapturedWord8=captured;
                Level12_7B584Keep(signedCapturedWord8);
            }
            argumentAddressOrMagic4=Level12_7B584Field(argumentOrCosAddress5,short*,0);
            __asm__ volatile(""::"r"(argumentAddressOrMagic4):"$3");
            sampleFieldOrSign3=signedCapturedWord8>>12;
            __asm__("":"=r"(sampleFieldOrSign3):"0"(sampleFieldOrSign3),"r"(argumentAddressOrMagic4));
            completeSignedProduct=(long long)sampleFieldOrSign3*(long long)argumentAddressOrMagic4;
            __asm__ volatile(""::"x"(completeSignedProduct));
            speedAngleOrSinAddress17+=retainedSinTableBase;
            {
                int captured;
                __asm__("":"=l"(captured):"x"(completeSignedProduct),"r"(speedAngleOrSinAddress17));
                signedCapturedWord8=captured;
                Level12_7B584Keep(signedCapturedWord8);
            }
            sampleFieldOrSign3=signedCapturedWord8>>12;
            originalFrame.sp34=sampleFieldOrSign3;
            sampleFieldOrSign3=Level12_7B584Field(speedAngleOrSinAddress17,short*,0);
            Level12_7B584Keep(sampleFieldOrSign3);
            completeSignedProduct=(long long)sampleFieldOrSign3*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            argumentOrCosAddress5=secondVectorAddress22;
            argumentAddressOrMagic4=firstVectorAddress20;
            {
                int captured;
                __asm__("":"=l"(captured):"x"(completeSignedProduct),"r"(argumentAddressOrMagic4),"r"(argumentOrCosAddress5));
                signedCapturedWord8=captured;
                Level12_7B584Keep(signedCapturedWord8);
            }
            resultOrField2=signedCapturedWord8>>12;
            originalFrame.sp38=resultOrField2;
            Level12_7B584Call4F178View1(argumentAddressOrMagic4,argumentOrCosAddress5);
            Level12_7B584Call4F0E8View1(firstVectorAddress20,1);
            Level12_7B584Call4F194View1(firstVectorAddress20,firstVectorAddress20,(int)ownerRecord18+12);
            resultOrField2=Level12_7B584Call363DCView1(0,200);
            argumentAddressOrMagic4=0;
            sampleFieldOrSign3=originalFrame.sp20;
            argumentOrCosAddress5=200;
            sampleFieldOrSign3+=resultOrField2;
            originalFrame.sp20=sampleFieldOrSign3;
            resultOrField2=Level12_7B584Call363DCView1(argumentAddressOrMagic4,argumentOrCosAddress5);
            argumentAddressOrMagic4=1;
            argumentOrCosAddress5=13;
            sampleFieldOrSign3=originalFrame.sp24;
            __asm__ volatile(""::"r"(sampleFieldOrSign3),"r"(argumentAddressOrMagic4),"r"(argumentOrCosAddress5):"$6");
            argumentWord6=firstVectorAddress20;
            sampleFieldOrSign3+=resultOrField2;
            resultOrField2=originalFrame.sp28;
            __asm__ volatile(""::"r"(resultOrField2):"$7");
            argumentWord7=secondVectorAddress22;
            originalFrame.sp24=sampleFieldOrSign3;
            sampleFieldOrSign3=(int)Level12_7B584DataSpawnParticleView1;
            Level12_7B584Keep(sampleFieldOrSign3);
            resultOrField2+=500;
            originalFrame.sp28=resultOrField2;
            ((int(*)(int,int,int,int))sampleFieldOrSign3)(argumentAddressOrMagic4,argumentOrCosAddress5,argumentWord6,argumentWord7);
        }
        while(emittedCount21<emissionCount23);
    }
    sampleFieldOrSign3=Level12_7B584Field(ownerRecord18,unsigned char*,0x48);
    resultOrField2=30;
    if(sampleFieldOrSign3!=resultOrField2){
        resultOrField2=6;
        if(sampleFieldOrSign3==resultOrField2)goto produceOriginalSeventh;
        resultOrField2=Level12_7B584Field(privateRecord19,int*,4);
        if(!resultOrField2 || resultOrField2>=120)goto produceOriginalPlainShade;
    produceOriginalSeventh:
        resultOrField2=(int)0x92492493;
        sampleFieldOrSign3=Level12_7B584Field(privateRecord19,int*,4);
        completeSignedProduct=(long long)sampleFieldOrSign3*(long long)resultOrField2;
        __asm__("":"=h"(sevenSignedHigh):"x"(completeSignedProduct));
        signedCapturedWord8=sevenSignedHigh;
        Level12_7B584Keep(signedCapturedWord8);
        resultOrField2=signedCapturedWord8+sampleFieldOrSign3;
        resultOrField2>>=2;
        sampleFieldOrSign3>>=31;
        resultOrField2-=sampleFieldOrSign3;
        sampleFieldOrSign3=15;
        sampleFieldOrSign3-=resultOrField2;
        if(sampleFieldOrSign3<0){
            sampleFieldOrSign3=0;
            Level12_7B584Keep(sampleFieldOrSign3);
        }
        resultOrField2=sampleFieldOrSign3<14;
        if(!resultOrField2){
            sampleFieldOrSign3=13;
            Level12_7B584Keep(sampleFieldOrSign3);
        }
        resultOrField2=sampleFieldOrSign3+48;
        Level12_7B584Field(ownerRecord18,unsigned char*,0x57)=resultOrField2;
        Level12_7B584Field(ownerRecord18,unsigned char*,0x54)=0;
        Level12_7B584Field(ownerRecord18,unsigned char*,0x55)=0;
        Level12_7B584Field(ownerRecord18,unsigned char*,0x56)=0;
        goto continueOriginalShadeDone;
        produceOriginalPlainShade:resultOrField2=48;
        Level12_7B584Field(ownerRecord18,unsigned char*,0x57)=resultOrField2;
    }
continueOriginalShadeDone:
    Level12_7B584Field(ownerRecord18,int*,0x18)=0;
    Level12_7B584Call55D24View1(ownerRecord18,1);
    return;
}
#undef Level12_7B584Field
#undef Level12_7B584Keep


/* SCUS-94467 USA Rev 0: 0x8007C0C8..0x8007C2B8, 124 original words.
 * AI generated; not yet human reviewed. Record offsets and signed widths
 * follow the original loads/stores. Empty constraints preserve compiler
 * lifetimes without emitting instructions. See batch 2026-10-05-1576.
 */
typedef struct {
    int ownerIndex;
    short step, angle;
    unsigned char* source;
    int timer, selector, handle;
} DecodedOscillatorTag;
extern Moby* D_8006C550;
extern unsigned char OscillatorGate __asm__("D_8006C7B4");
int OscillatorHandle(Moby*,int) __asm__("func_8003BFC0");
int OscillatorStart(Moby*,int,int) __asm__("func_8003BB10");
int OscillatorTimer(void*,int) __asm__("func_800359A4");
void func_level_12_8007C0C8(Moby* argument) {
    register Moby* moby __asm__("$18")=argument;
    register DecodedOscillatorTag* tag __asm__("$17")=moby->mobyTag;
    register Moby* child __asm__("$16");
    unsigned int ownerState;
    /* Eleven eight-byte units reproduce the native 88-byte Moby stride. */
    register int byteOffset __asm__("$2")=tag->ownerIndex*11;
    register Moby* owner __asm__("$3");
    register int active __asm__("$4");
    __asm__("" : : "r"(byteOffset));
    owner=(Moby*)((unsigned int)D_8006C550+(byteOffset<<3));
    __asm__("" : "=r"(owner) : "0"(owner) : "$4");
    ownerState=owner->state;
    active=0;
    if(ownerState==2 || ownerState>=128)active=1;
    switch(moby->state) {
    case 0:
        if(active) { tag->step=-5;moby->state=1; }
        break;
    case 1:
        if(!active && ABS((int)tag->angle)<5) { moby->state=0;break; }
        if(OscillatorGate&4)goto paused;
        if(!OscillatorHandle(moby,tag->handle))tag->handle=OscillatorStart(moby,tag->selector,32);
        if(OscillatorTimer(&tag->timer,4)) {
            child=SpawnMoby(0x250,moby);
            __asm__("" : "=r"(child) : "0"(child));
            if(child) {
                { unsigned char** childTag=child->mobyTag;
                  unsigned char* source;
                  __asm__("" : : "r"(childTag) : "memory");
                  source=tag->source;
                *childTag=source;
                func_8004F178(&child->position,*(Vector3D**)(source+12)); }
                child->size=127;child->lowDrawDistance=40;child->highDrawDistance=40;
                tag->timer=30;
            }
        }
        /* Native halfword storage wraps the phase before its signed test. */
        tag->angle+=tag->step;
        if(ABS((int)tag->angle)>32)tag->step=-tag->step;
        moby->angle.roll=tag->angle;
        goto finish;
paused:
        moby->angle.roll=0;
        break;
    }
finish:;
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
typedef union{long long full;struct{
#if defined(__MIPSEB__)
int high;unsigned low;
#else
unsigned low;int high;
#endif
}words;}Level12_C2B8Product;
/* SCUS-94467 USA Rev0, func_level_12_8007C2B8.
 * AI generated; not human reviewed.
 * Original 344-byte frame, 2,979 instructions, four physical dispatch tables
 * with 85 selectors and one padding word. Addresses and unverified semantic
 * roles retain their original numeric identity.
 * Every saved word starts at an actual load, address or helper return.
 * All 36 signed products are initialized in full before their HI/LO word
 * projection. Empty metadata preserves complete original values and dead GP
 * phase boundaries; it contains no CPU instruction template.
 * The volatile result-word observation retains original2251's complete1 on
 * the path that overwrites it again at2255. It adds no value or site tag.
 * int arguments represent exact four-byte MIPS/o32 words, including target
 * pointers. The product union is a compiler-local word view.
 */
#define Level12_C2B8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Level12_C2B8Keep(v) __asm__("":"=r"(v):"0"(v))
void Level12_C2B8_func_80013AE4(int,int) __asm__("func_80013AE4");
void Level12_C2B8_func_80013B7C(int) __asm__("func_80013B7C");
void Level12_C2B8_func_80013D44(int,int,int,int) __asm__("func_80013D44");
int Level12_C2B8_func_8002803C(int,int,int,int,int,int,int) __asm__("func_8002803C");
void Level12_C2B8_func_80028154(int) __asm__("func_80028154");
void Level12_C2B8_func_80034F40(int,int) __asm__("func_80034F40");
void Level12_C2B8_func_80035734(int) __asm__("func_80035734");
int Level12_C2B8_func_8003585C(int,int,int,int,int,int) __asm__("func_8003585C");
int Level12_C2B8_func_800359A4(int,int) __asm__("func_800359A4");
int Level12_C2B8_func_80035A80(int,int,int,int,int,int,int,int) __asm__("func_80035A80");
int Level12_C2B8_func_80035DDC(int,int,int,int,int) __asm__("func_80035DDC");
int Level12_C2B8_func_80035EE0(int,int,int,int,int,int) __asm__("func_80035EE0");
int Level12_C2B8_func_80036220(int,int,int,int) __asm__("func_80036220");
int Level12_C2B8_func_8003636C(int,int) __asm__("func_8003636C");
int Level12_C2B8_func_800365E4(int,int,int,int,int) __asm__("func_800365E4");
int Level12_C2B8_func_80037BBC(int,int) __asm__("func_80037BBC");
void Level12_C2B8_func_8003B7B4(int,int,int) __asm__("func_8003B7B4");
int Level12_C2B8_func_8003BB10(int,int,int) __asm__("func_8003BB10");
void Level12_C2B8_func_8003BE70(int) __asm__("func_8003BE70");
int Level12_C2B8_func_8003BFC0(int,int) __asm__("func_8003BFC0");
void Level12_C2B8_func_8003C0B0(int,int) __asm__("func_8003C0B0");
void Level12_C2B8_func_8003C140(int,int) __asm__("func_8003C140");
void Level12_C2B8_func_800492DC(int) __asm__("func_800492DC");
int Level12_C2B8_func_8004E880(int,int,int) __asm__("func_8004E880");
int Level12_C2B8_func_8004E9E4(int) __asm__("func_8004E9E4");
int Level12_C2B8_func_8004EA2C(int) __asm__("func_8004EA2C");
void Level12_C2B8_func_8004F0E8(int,int) __asm__("func_8004F0E8");
void Level12_C2B8_func_8004F178(int,int) __asm__("func_8004F178");
void Level12_C2B8_func_8004F194(int,int,int) __asm__("func_8004F194");
int Level12_C2B8_func_8004F264(int,int) __asm__("func_8004F264");
int Level12_C2B8_func_8004F334(int,int) __asm__("func_8004F334");
void Level12_C2B8_func_8004F9C0(int,int,int) __asm__("func_8004F9C0");
void Level12_C2B8_func_800512E4(int,int,int) __asm__("func_800512E4");
void Level12_C2B8_func_80055B18(int) __asm__("func_80055B18");
int Level12_C2B8_rand(void) __asm__("rand");
extern int Level12_C2B8_D_800652B0 __asm__("D_800652B0");
extern unsigned short Level12_C2B8_D_800652B4 __asm__("D_800652B4");
extern unsigned short Level12_C2B8_D_800652B6 __asm__("D_800652B6");
extern int Level12_C2B8_D_800658A0 __asm__("D_800658A0");
extern int Level12_C2B8_D_80065920 __asm__("D_80065920");
extern int Level12_C2B8_D_8006C3F4 __asm__("D_8006C3F4");
extern int Level12_C2B8_D_8006C550 __asm__("D_8006C550");
extern int Level12_C2B8_D_8006C58C __asm__("D_8006C58C");
extern int Level12_C2B8_D_8006C628 __asm__("D_8006C628");
extern int Level12_C2B8_D_8006C640 __asm__("D_8006C640");
extern int Level12_C2B8_D_8006C730 __asm__("D_8006C730");
extern int Level12_C2B8_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level12_C2B8_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level12_C2B8_D_8006C7C0 __asm__("D_8006C7C0");
extern int Level12_C2B8_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level12_C2B8_D_8006E020 __asm__("D_8006E020");
extern int Level12_C2B8_D_8006E024 __asm__("D_8006E024");
extern int Level12_C2B8_D_8006E028 __asm__("D_8006E028");
extern unsigned short Level12_C2B8_D_8006E03E __asm__("D_8006E03E");
extern unsigned short Level12_C2B8_D_8006E040 __asm__("D_8006E040");
extern int Level12_C2B8_D_8006E048 __asm__("D_8006E048");
extern int Level12_C2B8_D_8006E344 __asm__("D_8006E344");
extern int Level12_C2B8_D_8006E53C __asm__("D_8006E53C");
extern int Level12_C2B8_D_8006EE2C __asm__("D_8006EE2C");
extern int Level12_C2B8_D_80070300 __asm__("D_80070300");
extern int Level12_C2B8_D_80070328 __asm__("D_80070328");
extern int Level12_C2B8_D_80071AB0 __asm__("D_80071AB0");
extern int Level12_C2B8_D_level_12_8008BD18 __asm__("D_level_12_8008BD18");
extern int (*Level12_C2B8_SpawnMoby)(int,int) __asm__("SpawnMoby");
extern void (*Level12_C2B8_SpawnParticle)(int,int,int,int) __asm__("SpawnParticle");
extern int Level12_C2B8_func_80027A60 __asm__("func_80027A60");
extern int Level12_C2B8_func_80027EE4 __asm__("func_80027EE4");
extern int Level12_C2B8_func_80029AA0 __asm__("func_80029AA0");
extern unsigned char Level12_C2B8_func_level_12_80074F50 __asm__("func_level_12_80074F50");
extern int Level12_C2B8_main_TEXT_END __asm__("main_TEXT_END");
extern int Level12_C2B8_main_TEXT_START __asm__("main_TEXT_START");
void func_level_12_8007C2B8(void* input) {
register int savedWord16 __asm__("$16"),savedWord17 __asm__("$17"),savedWord18 __asm__("$18"),privateAddress __asm__("$19"),savedWord20 __asm__("$20"),savedWord21 __asm__("$21"),ownerAddress __asm__("$22"),savedWord23 __asm__("$23");
register int resultWord __asm__("$2"),workWord __asm__("$3"),argument0 __asm__("$4"),argument1 __asm__("$5"),argument2 __asm__("$6"),argument3 __asm__("$7");
int tableFP;
int predicate31,predicate58;
int tail150;
Level12_C2B8Product tailProduct1,tailProduct2,tailProduct3,tailProduct4,tailProduct5,tailProduct6,tailProduct7,tailProduct8,tailProduct9,tailProduct10,tailProduct11,tailProduct12,tailProduct13,tailProduct14,tailProduct15,tailProduct16,tailProduct17,tailProduct18,tailProduct19,tailProduct20,tailProduct21,tailProduct22,tailProduct23,tailProduct24,tailProduct25,tailProduct26,tailProduct27,tailProduct28,tailProduct29,tailProduct30,tailProduct31,tailProduct32,tailProduct33,tailProduct34,tailProduct35,tailProduct36;
register int productWord __asm__("$11"),fullByteWord __asm__("$8"),reciprocalWord __asm__("$9"),limitWord __asm__("$10");
struct {int sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104,sp108,sp10C,sp110,sp114,sp118,sp11C,sp120,sp124,sp128,sp12C;
}nativeFrame;
    int var_a0_9;
    int var_a1_6;
    int temp_a1_3;
    int temp_a2_4;
    int temp_a2_6;
    int temp_v1_28;
    int temp_a0_10;
    int temp_a0_11;
    int temp_a0_13;
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_5;
    int temp_a0_6;
    int temp_a0_7;
    int temp_a0_9;
    int temp_a1_2;
    int temp_a1_4;
    int temp_a2;
    int temp_a2_2;
    int temp_a2_3;
    int temp_v0;
    int temp_v0_10;
    int temp_v0_11;
    int temp_v0_12;
    int temp_v0_13;
    int temp_v0_14;
    int temp_v0_17;
    int temp_v0_19;
    int temp_v0_20;
    int temp_v0_23;
    int temp_v0_26;
    int temp_v0_28;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_5;
    int temp_v0_8;
    int temp_v1_10;
    int temp_v1_20;
    int temp_v1_21;
    int temp_v1_25;
    int temp_v1_26;
    int temp_v1_31;
    int temp_v1_32;
    int temp_a0_4;
    int temp_a0_8;
    int temp_a1_7;
    int temp_a2_5;
    int temp_a3;
    int temp_a3_2;
    int temp_a3_3;
    int temp_a3_4;
    int temp_a3_5;
    int temp_a3_6;
    int temp_a3_7;
    int temp_a3_8;
    int temp_fp;
    int temp_lo;
    int temp_lo_2;
    int temp_t3;
    int temp_v0_16;
    int temp_v0_18;
    int temp_v0_21;
    int temp_v0_29;
    int temp_v0_30;
    int temp_v0_4;
    int temp_v0_6;
    int temp_v1_12;
    int temp_v1_16;
    int temp_v1_22;
    int temp_v1_27;
    int temp_v1_35;
    int temp_v1_4;
    int temp_v1_8;
    int var_a0;
    int var_a0_2;
    int var_a1;
    int var_a1_2;
    int var_a1_3;
    int var_a1_4;
    int var_a3;
    int var_fp;
    int var_v1;
    int temp_ret;
    int var_a0_3;
    int temp_v1_3;
    int temp_v1_5;
    int temp_v1_7;
    int temp_v0_15;
    int temp_v0_22;
    int temp_v1;
    int temp_v1_11;
    int temp_v1_13;
    int temp_v1_15;
    int temp_v1_23;
    int temp_v1_24;
    int temp_v1_2;
    int temp_v1_30;
    int temp_v1_9;
    int temp_a1_5;
    int temp_a1_6;
    int temp_v0_24;
    int temp_v1_14;
    int temp_v1_17;
    int temp_v1_29;
    int temp_v1_33;
    int temp_v1_6;
    int var_a0_4;
    int var_a0_5;
    int var_a0_6;
    int var_a0_7;
    int var_a0_8;
    int var_a2;
    ownerAddress=(int)input;
Level12_C2B8Keep(ownerAddress);
    privateAddress = Level12_C2B8Field(ownerAddress, int*, 0);
    if (Level12_C2B8Field(ownerAddress, int *, 0x18) == 0) {
        goto originalBlock2;
    }
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 5U;
    Level12_C2B8_func_80034F40(input,5);
originalBlock2:
    temp_v1 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x48);
    Level12_C2B8Field(ownerAddress, int *, 0x18) = 0;
    if (temp_v1 >= 0x3EU) {
        goto originalBlock314;
    }
switch(temp_v1){
case 0:goto originalDispatch1_selector0;
case 1:goto originalDispatch1_selector1;
case 2:goto originalDispatch1_selector2;
case 3:goto originalDispatch1_selector3;
case 4:goto originalDispatch1_selector4;
case 5:goto originalDispatch1_selector5;
case 6:goto originalDispatch1_selector6;
case 7:goto originalDispatch1_selector7;
case 8:goto originalDispatch1_selector8;
case 9:goto originalDispatch1_selector9;
case 10:goto originalDispatch1_selector10;
case 11:goto originalDispatch1_selector11;
case 12:goto originalDispatch1_selector12;
case 13:goto originalDispatch1_selector13;
case 14:goto originalDispatch1_selector14;
case 15:goto originalDispatch1_selector15;
case 16:goto originalDispatch1_selector16;
case 17:goto originalDispatch1_selector17;
case 18:goto originalDispatch1_selector18;
case 19:goto originalDispatch1_selector19;
case 20:goto originalDispatch1_selector20;
case 21:goto originalDispatch1_selector21;
case 22:goto originalDispatch1_selector22;
case 23:goto originalDispatch1_selector23;
case 24:goto originalDispatch1_selector24;
case 25:goto originalDispatch1_selector25;
case 26:goto originalDispatch1_selector26;
case 27:goto originalDispatch1_selector27;
case 28:goto originalDispatch1_selector28;
case 29:goto originalDispatch1_selector29;
case 30:goto originalDispatch1_selector30;
case 31:goto originalDispatch1_selector31;
case 32:goto originalDispatch1_selector32;
case 33:goto originalDispatch1_selector33;
case 34:goto originalDispatch1_selector34;
case 35:goto originalDispatch1_selector35;
case 36:goto originalDispatch1_selector36;
case 37:goto originalDispatch1_selector37;
case 38:goto originalDispatch1_selector38;
case 39:goto originalDispatch1_selector39;
case 40:goto originalDispatch1_selector40;
case 41:goto originalDispatch1_selector41;
case 42:goto originalDispatch1_selector42;
case 43:goto originalDispatch1_selector43;
case 44:goto originalDispatch1_selector44;
case 45:goto originalDispatch1_selector45;
case 46:goto originalDispatch1_selector46;
case 47:goto originalDispatch1_selector47;
case 48:goto originalDispatch1_selector48;
case 49:goto originalDispatch1_selector49;
case 50:goto originalDispatch1_selector50;
case 51:goto originalDispatch1_selector51;
case 52:goto originalDispatch1_selector52;
case 53:goto originalDispatch1_selector53;
case 54:goto originalDispatch1_selector54;
case 55:goto originalDispatch1_selector55;
case 56:goto originalDispatch1_selector56;
case 57:goto originalDispatch1_selector57;
case 58:goto originalDispatch1_selector58;
case 59:goto originalDispatch1_selector59;
case 60:goto originalDispatch1_selector60;
case 61:goto originalDispatch1_selector61;
default:goto originalBlock314;
}
originalDispatch1_selector0:
    workWord=Level12_C2B8Field(privateAddress,unsigned char*,0);
Level12_C2B8Keep(workWord);
    resultWord=(unsigned int)(workWord-1)<2U;
workWord&=255;
    if(!resultWord)goto originalBlock20;
    __asm__ volatile("":::"$2","memory");
resultWord=1;
if(workWord!=resultWord)goto originalBlock18;
    resultWord=Level12_C2B8Field(privateAddress,int*,0x38);
if(resultWord)goto originalBlock8;
    resultWord=Level12_C2B8_D_8006C58C;
__asm__ volatile("":::"$3","memory");
workWord=(int)&Level12_C2B8_main_TEXT_START+2;
resultWord+=workWord;
    Level12_C2B8Field(privateAddress,int*,0x38)=resultWord;
    resultWord=Level12_C2B8Field(privateAddress,volatile int*,0x38);
originalBlock8:
    __asm__ volatile("":::"$3","memory");
workWord=(int)&Level12_C2B8_main_TEXT_END;
Level12_C2B8Keep(workWord);
    if((unsigned int)resultWord>=(unsigned int)workWord)goto originalBlock18;
    __asm__ volatile("":::"$5","memory");
argument1=0;
argument2=workWord;
Level12_C2B8Keep(argument2);
originalLoop10:
    workWord=Level12_C2B8Field(privateAddress,int*,0x38);
    if((unsigned int)workWord>=(unsigned int)argument2)goto originalBlock17;
    __asm__ volatile("":::"$4","memory");
argument0=0;
resultWord=Level12_C2B8Field(workWord,unsigned char*,0);
workWord=Level12_C2B8Field(privateAddress,int*,0x94);
    resultWord<<=8;
workWord^=resultWord;
Level12_C2B8Field(privateAddress,int*,0x94)=workWord;
originalLoop12:
    workWord=Level12_C2B8Field(privateAddress,volatile int*,0x94);
resultWord=workWord&0x8000;
    if(resultWord){resultWord=(unsigned int)workWord<<1;
resultWord^=0x8005;
}
    else resultWord=(unsigned int)workWord<<1;
originalBlock14:
    Level12_C2B8Field(privateAddress,int*,0x94)=resultWord;
argument0++;
    resultWord=argument0<8;
if(resultWord)goto originalLoop12;
    argument1++;
resultWord=Level12_C2B8Field(privateAddress,volatile int*,0x94);
workWord=Level12_C2B8Field(privateAddress,int*,0x38);
    resultWord=(resultWord&3)+1;
workWord+=resultWord;
Level12_C2B8Field(privateAddress,int*,0x38)=workWord;
    resultWord=argument1<64;
if(resultWord)goto originalLoop10;
    __asm__ volatile("":::"$2","memory");
resultWord=(int)&Level12_C2B8_main_TEXT_END;
    if((unsigned int)workWord<(unsigned int)resultWord)goto originalBlock18;
originalBlock17:
    __asm__ volatile("":::"$2","memory");
resultWord=(int)&Level12_C2B8_func_level_12_80074F50;
Level12_C2B8Field(privateAddress,int*,0x38)=resultWord;
originalBlock18:
    if (Level12_C2B8_D_8006C7B4 & 1) {
        goto originalBlock302;
    }
    if (Level12_C2B8Field((int)&Level12_C2B8_D_80070300,unsigned char*,Level12_C2B8_D_8006C58C) & 1) {
        goto originalBlock302;
    }
originalBlock20:
    if (Level12_C2B8Field(privateAddress, int *, 0x30) == 0) {
        goto originalBlock23;
    }
    Level12_C2B8Field(privateAddress, int *, 0x30) = 0;
    if ((unsigned char) Level12_C2B8Field(((Level12_C2B8Field(privateAddress, int *, 0x34) * 0x58) + Level12_C2B8_D_8006C550), unsigned char *, 0x48) >= 0x80U) {
        goto originalBlock23;
    }
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0xAU;
originalBlock23:
    if (Level12_C2B8_D_8006C640 != 0) {
        goto originalBlock28;
    }
    if (Level12_C2B8Field(privateAddress, unsigned char *, 0) != 3) {
        goto originalBlock28;
    }
    if (Level12_C2B8_D_8006C7B4 & 1) {
        goto originalBlock27;
    }
    if (!(Level12_C2B8Field((int)&Level12_C2B8_D_80070300,unsigned char*,Level12_C2B8_D_8006C58C) & 1)) {
        goto originalBlock28;
    }
originalBlock27:
    Level12_C2B8Field(((Level12_C2B8Field(privateAddress, int *, 0x60) * 0x58) + Level12_C2B8_D_8006C550), signed char *, 0x49) = 1;
    goto originalBlock307;
originalBlock28:
    resultWord=Level12_C2B8_D_8006C7B4;
resultWord&=4;
    if(resultWord?(resultWord=5,1):(resultWord=5,0))goto originalBlock43;
    Level12_C2B8Keep(resultWord);
workWord=Level12_C2B8Field(privateAddress,unsigned char*,0);
savedWord17=0;
if(workWord!=resultWord)goto originalBlock47;
    resultWord=Level12_C2B8_D_8006C730;
argument1=Level12_C2B8_D_8006C550;
Level12_C2B8Keep(argument1);
    savedWord16=Level12_C2B8Field(resultWord,int*,0);
originalLoop31:
    argument0=Level12_C2B8Field(savedWord16,unsigned short*,0);
    resultWord=argument0&0x7FFF;
workWord=resultWord*88;
workWord+=argument1;
    resultWord=Level12_C2B8Field(workWord,unsigned char*,0x48);
resultWord=(unsigned int)resultWord<2U;
    if(resultWord==0?(resultWord=(unsigned int)argument0<<16,1):(resultWord=(unsigned int)argument0<<16,0))goto originalBlock33;
    savedWord17++;
originalBlock33:
    Level12_C2B8Keep(resultWord);
savedWord16+=2;
if(resultWord>=0)goto originalLoop31;
    __asm__ volatile("":::"$4","memory");
argument0=6;
Level12_C2B8Keep(argument0);
workWord=Level12_C2B8Field(privateAddress,int*,0x5C);
resultWord=argument0-savedWord17;
    Level12_C2B8_D_8006C628=resultWord;
__asm__ volatile("":::"$2","memory");
resultWord=-1;
if(workWord!=resultWord)goto originalBlock37;
    workWord=Level12_C2B8Field((int)&Level12_C2B8_D_80070328,int*,0x50);
if(workWord!=argument0)goto originalBlock37;
    argument0=23;
argument1=120;
argument2=(int)&Level12_C2B8_func_80027EE4;
argument3=(int)&Level12_C2B8_func_80027A60;
    resultWord=Level12_C2B8_func_8002803C(argument0,argument1,argument2,argument3,(int)&Level12_C2B8_func_80029AA0,(int)&Level12_C2B8_D_8006C628,workWord);
    resultWord=(short)resultWord;
Level12_C2B8Field(privateAddress,int*,0x5C)=resultWord;
originalBlock37:
    if (savedWord17 != 0) {
        goto originalBlock47;
    }
    savedWord16 = Level12_C2B8Field(Level12_C2B8_D_8006C730,int*,0);
originalLoop39:
    temp_a0_2 = ((Level12_C2B8Field(savedWord16,unsigned short*,0) & 0x7FFF) * 0x58) + Level12_C2B8_D_8006C550;
    if ((unsigned char) Level12_C2B8Field(temp_a0_2, unsigned char *, 0x48) >= 0x7FU) {
        goto originalBlock41;
    }
    Level12_C2B8_func_80055B18(temp_a0_2);
originalBlock41:
    resultWord=Level12_C2B8Field(savedWord16,short*,0);
Level12_C2B8Keep(resultWord);
    savedWord16 += 2;
    if (resultWord >= 0) {
        goto originalLoop39;
    }
    Level12_C2B8_func_80028154(Level12_C2B8Field(privateAddress, int *, 0x5C));
    Level12_C2B8Field(privateAddress, int *, 0x5C) = -1;
    __asm__ volatile("":::"$2","memory");
resultWord = 0x32;
    goto originalBlock263;
originalBlock43:
    Level12_C2B8Keep(resultWord);
workWord=Level12_C2B8Field(privateAddress,unsigned char*,0);
if(workWord!=resultWord)goto originalBlock47;
    if (Level12_C2B8_D_8006C640 != 0) {
        goto originalBlock46;
    }
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 7U;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0x32U;
    return;
originalBlock46:
    temp_v1_6 = Level12_C2B8_D_8006C550 + (Level12_C2B8Field(privateAddress, int *, 0x88) * 0x58);
    Level12_C2B8Field(temp_v1_6, signed char *, 0x49) = 1;
    Level12_C2B8Field(temp_v1_6, int *, 0x14) = 0x3D21;
    Level12_C2B8Field(temp_v1_6, signed char *, 0x4F) = 9;
originalBlock47:
    if ((unsigned int) Level12_C2B8Field(privateAddress, unsigned char **, 0x38) < (unsigned int) (int)&Level12_C2B8_func_level_12_80074F50) {
        goto originalBlock55;
    }
    __asm__ volatile("":::"$5","memory");
argument1=0;
__asm__ volatile("":::"$6","memory");
argument2=(int)&Level12_C2B8_D_level_12_8008BD18;
Level12_C2B8Keep(argument2);
originalLoop49:
    workWord=Level12_C2B8Field(privateAddress,int*,0x38);
    if((unsigned int)workWord>=(unsigned int)argument2)goto originalBlock55;
    __asm__ volatile("":::"$4","memory");
argument0=0;
resultWord=Level12_C2B8Field(workWord,unsigned char*,0);
workWord=Level12_C2B8Field(privateAddress,int*,0x94);
    resultWord<<=8;
workWord^=resultWord;
Level12_C2B8Field(privateAddress,int*,0x94)=workWord;
originalLoop51:
    workWord=Level12_C2B8Field(privateAddress,volatile int*,0x94);
resultWord=workWord&0x8000;
    if(resultWord){resultWord=(unsigned int)workWord<<1;
resultWord^=0x8005;
}
    else resultWord=(unsigned int)workWord<<1;
originalBlock53:
    Level12_C2B8Field(privateAddress,int*,0x94)=resultWord;
argument0++;
    resultWord=argument0<8;
if(resultWord)goto originalLoop51;
    argument1++;
resultWord=Level12_C2B8Field(privateAddress,int*,0x38);
resultWord++;
Level12_C2B8Field(privateAddress,int*,0x38)=resultWord;
    resultWord=argument1<64;
if(resultWord)goto originalLoop49;
originalBlock55:
    if (Level12_C2B8_D_8006C7B4 & 2) {
        goto originalBlock65;
    }
    if (Level12_C2B8Field(privateAddress, unsigned char *, 0) != 4) {
        goto originalBlock78;
    }
    __asm__ volatile("":::"$16","memory");
savedWord16=0;
__asm__ volatile("":::"$7","memory");
argument3=21;
Level12_C2B8Keep(argument3);
    resultWord=Level12_C2B8_D_8006C730;
__asm__ volatile("":::"$6","memory");
argument2=Level12_C2B8_D_8006C550;
Level12_C2B8Keep(argument2);
    argument0=Level12_C2B8Field(resultWord,int*,0);
originalLoop58:
    argument1=Level12_C2B8Field(argument0,unsigned short*,0);
    resultWord=argument1&0x7FFF;
workWord=resultWord*88;
workWord+=argument2;
    resultWord=Level12_C2B8Field(workWord,unsigned char*,0x48);
    if(resultWord==argument3?(resultWord=(unsigned int)argument1<<16,1):(resultWord=(unsigned int)argument1<<16,0))goto originalBlock60;
    savedWord16++;
originalBlock60:
    Level12_C2B8Keep(resultWord);
argument0+=2;
if(resultWord>=0)goto originalLoop58;
    __asm__ volatile("":::"$3","memory");
workWord=3;
resultWord=workWord-savedWord16;
Level12_C2B8_D_8006C628=resultWord;
    if (Level12_C2B8Field(privateAddress, int *, 0x5C) != -1) {
        goto originalBlock63;
    }
    Level12_C2B8Field(privateAddress, int *, 0x5C) = (short) Level12_C2B8_func_8002803C(0x17, 0x79, (int)&Level12_C2B8_func_80027EE4, (int)&Level12_C2B8_func_80027A60, (int)&Level12_C2B8_func_80029AA0, (int)&Level12_C2B8_D_8006C628, 3);
originalBlock63:
    if (savedWord16 != 0) {
        goto originalBlock77;
    }
    Level12_C2B8_func_80028154(Level12_C2B8Field(privateAddress, int *, 0x5C));
    __asm__ volatile("":::"$2","memory");
resultWord = 0x28;
    Level12_C2B8Field(privateAddress, int *, 0x5C) = -1;
    goto originalBlock263;
originalBlock65:
    if (Level12_C2B8Field(privateAddress, unsigned char *, 0) != 4) {
        goto originalBlock78;
    }
    if (Level12_C2B8_D_8006C640 != 0) {
        goto originalBlock68;
    }
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 7U;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0x28U;
    return;
originalBlock68:
    if (Level12_C2B8Field(privateAddress, int*, 0xD8) != 0) {
        goto originalBlock77;
    }
    temp_v1_9 = Level12_C2B8Field(privateAddress, unsigned char *, 5);
    if (temp_v1_9 == 0) {
        goto originalBlock71;
    }
    if (temp_v1_9 != 0xFF) {
        goto originalBlock77;
    }
originalBlock71:
    temp_v0 = Level12_C2B8_SpawnMoby(0x158, ownerAddress);
    Level12_C2B8Field(privateAddress, int*, 0xD8) = temp_v0;
    if (temp_v0 == 0) {
        goto originalBlock73;
    }
    Level12_C2B8_func_8004F178(temp_v0 + 0xC, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    temp_v1_10 = Level12_C2B8Field(privateAddress, int*, 0xD8);
    Level12_C2B8Field(temp_v1_10, int *, 0x14) = (int) (Level12_C2B8Field(temp_v1_10, int *, 0x14) + 0x9C4);
    temp_v0_2 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    temp_a3 = Level12_C2B8Field(temp_v0_2, int *, 0);
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x46) = Level12_C2B8_func_8004E880(temp_a3 - Level12_C2B8Field(temp_v0_2, int *, 0x10), Level12_C2B8Field(temp_v0_2, int *, 4) - Level12_C2B8Field(temp_v0_2, int *, 0x14), 0);
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x4C) = 0x3F;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x4E) = 0x3F;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x57) = 0x30;
originalBlock73:
    __asm__ volatile("":::"$17","memory");
savedWord17 = 0;
    savedWord16 = privateAddress;
originalLoop74:
    temp_a0_3 = (Level12_C2B8Field(savedWord16, int *, 0x88) * 0x58) + Level12_C2B8_D_8006C550;
    if ((unsigned char) Level12_C2B8Field(temp_a0_3, unsigned char *, 0x48) >= 0x80U) {
        goto originalBlock76;
    }
    Level12_C2B8_func_80055B18(temp_a0_3);
originalBlock76:
    savedWord17 += 1;
    savedWord16 += 4;
    if (savedWord17 < 3) {
        goto originalLoop74;
    }
originalBlock77:
originalBlock78:
    if (Level12_C2B8Field(privateAddress, unsigned char *, 0) != 3) {
        goto originalBlock81;
    }
    if (!(Level12_C2B8_D_8006C7B4 & 1)) {
        goto originalBlock81;
    }
    Level12_C2B8Field(((Level12_C2B8Field(privateAddress, int *, 0x60) * 0x58) + Level12_C2B8_D_8006C550), signed char *, 0x49) = 1;
originalBlock81:
    if (Level12_C2B8Field(privateAddress, unsigned char **, 0x38) != (int)&Level12_C2B8_D_level_12_8008BD18) {
        goto originalBlock86;
    }
    if (Level12_C2B8Field(privateAddress, int *, 0x94) == 0) {
        goto originalBlock86;
    }
    if (Level12_C2B8_D_8006C640 & 0x1F) {
        goto originalBlock86;
    }
    resultWord=Level12_C2B8_rand();
__asm__ volatile("":::"$3","memory");
workWord=0x66666667;
    tailProduct35.full=(long long)resultWord*(long long)workWord;
workWord=resultWord>>31;
    __asm__("":"=x"(tailProduct35.full):"0"(tailProduct35.full),"r"(workWord));
productWord=tailProduct35.words.high;
Level12_C2B8Keep(productWord);
    argument0=productWord>>4;
savedWord17=argument0-workWord;
Level12_C2B8Keep(savedWord17);
workWord=(savedWord17*5)<<3;
savedWord17=resultWord-workWord;
    resultWord=savedWord17<9;
if(resultWord)goto originalBlock86;
    resultWord=Level12_C2B8_rand();
savedWord16=resultWord&7;
resultWord=Level12_C2B8_rand();
resultWord&=7;
    __asm__ volatile("":::"$4","memory");
argument0=1;
__asm__ volatile("":::"$5","memory");
argument1=(int)&Level12_C2B8_D_80071AB0;
Level12_C2B8Keep(argument1);
    workWord=savedWord17<<5;
workWord+=argument1;
savedWord16<<=2;
savedWord16+=workWord;
    workWord=Level12_C2B8Field(savedWord16,int*,0);
argument0<<=resultWord;
workWord|=argument0;
Level12_C2B8Field(savedWord16,int*,0)=workWord;
originalBlock86:
    if (Level12_C2B8_D_8006C770 == 0) {
        goto originalBlock91;
    }
    if (Level12_C2B8Field(privateAddress, int *, 0x2C) != 0) {
        goto originalBlock89;
    }
    Level12_C2B8_func_80034F40(ownerAddress, 1);
    Level12_C2B8Field(privateAddress, int *, 0x2C) = Level12_C2B8_func_8003636C(1, 2);
    goto originalBlock90;
originalBlock89:
    Level12_C2B8_func_80034F40(ownerAddress, 0);
    Level12_C2B8Field(privateAddress, int *, 0x2C) = (int) (Level12_C2B8Field(privateAddress, int *, 0x2C) - 1);
originalBlock90:
originalBlock91:
    if (Level12_C2B8_func_80037BBC(ownerAddress, 0) == 0) {
        goto originalBlock314;
    }
    Level12_C2B8_func_800512E4(ownerAddress, 0, 2);
    __asm__ volatile("":::"$2","memory");
resultWord = 2;
    goto originalBlock313;
originalDispatch1_selector50:
    argument0=(int)&nativeFrame.sp20;
resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
workWord=Level12_C2B8Field(privateAddress,int*,0x88);
    __asm__ volatile("":::"$6","memory");
argument2=Level12_C2B8_D_8006C550;
Level12_C2B8Keep(argument2);
argument1=Level12_C2B8Field(resultWord,int*,12);
    resultWord=workWord*88;
workWord=Level12_C2B8Field(privateAddress,int*,0x8C);
savedWord17=argument2+resultWord;
resultWord=workWord*88;
    __asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord16=argument2+resultWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
argument1=Level12_C2B8Field(resultWord,int*,12);
argument0=(int)&nativeFrame.sp30;
argument1+=16;
    Level12_C2B8_func_8004F178(argument0,argument1);
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 0) {
        goto originalBlock97;
    }
    if (Level12_C2B8_D_8006E048 & 1) {
        goto originalBlock97;
    }
    if (!(Level12_C2B8_D_8006E53C & 0x810)) {
        goto originalBlock97;
    }
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 7U;
originalBlock97:
    temp_v1_11 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x49);
    if (temp_v1_11 >= 8U) {
        goto originalBlock125;
    }
switch(temp_v1_11){
case 0:goto originalDispatch2_selector0;
case 1:goto originalDispatch2_selector1;
case 2:goto originalDispatch2_selector2;
case 3:goto originalDispatch2_selector3;
case 4:goto originalDispatch2_selector4;
case 5:goto originalDispatch2_selector5;
case 6:goto originalDispatch2_selector6;
case 7:goto originalDispatch2_selector7;
default:goto originalBlock125;
}
originalDispatch2_selector0:
    temp_a0_4 = Level12_C2B8_D_8006C3F4 + Level12_C2B8_D_800652B0;
    Level12_C2B8_func_8004F9C0(temp_a0_4, temp_a0_4 + Level12_C2B8_D_800652B4, Level12_C2B8_D_800652B6);
    Level12_C2B8_func_80013AE4(&nativeFrame.sp20, &nativeFrame.sp30);
    temp_a0_5 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    Level12_C2B8Field(privateAddress, int *, 0x74) = Level12_C2B8_func_8004F334(temp_a0_5, temp_a0_5 + 0x10);
    temp_v0_3 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    temp_a3_2 = Level12_C2B8Field(temp_v0_3, int *, 0);
    Level12_C2B8Field(privateAddress, int *, 0x6C) = (int) (Level12_C2B8_func_8004E880(temp_a3_2 - Level12_C2B8Field(temp_v0_3, int *, 0x10), Level12_C2B8Field(temp_v0_3, int *, 4) - Level12_C2B8Field(temp_v0_3, int *, 0x14), 0) * 0x10);
    Level12_C2B8Field(privateAddress, int *, 0x7C) = 0x5DC;
    Level12_C2B8Field((int)&Level12_C2B8_D_80070328, int *, 0x1BC) = 0;
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0x190;
    goto originalBlock118;
originalDispatch2_selector1:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock124;
    }
    resultWord=1;
Level12_C2B8Keep(resultWord);
Level12_C2B8Field(savedWord17,unsigned char*,0x49)=resultWord;
__asm__ volatile("":::"$2","memory");
    resultWord=120;
Level12_C2B8Keep(resultWord);
Level12_C2B8Field(privateAddress,int*,0x70)=resultWord;
goto originalBlock118;
originalDispatch2_selector2:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock124;
    }
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0x50;
    Level12_C2B8Field(savedWord17, unsigned char *, 0x4F) = 0x20U;
    goto originalBlock118;
originalDispatch2_selector3:
    Level12_C2B8Field(privateAddress, int *, 0x74) = (int) (Level12_C2B8Field(privateAddress, int *, 0x74) + 0xAA);
    Level12_C2B8Field(savedWord17, int *, 0x14) = (int) (Level12_C2B8Field(savedWord17, int *, 0x14) + Level12_C2B8Field(privateAddress, int *, 0x64));
    Level12_C2B8Field(privateAddress, int *, 0x64) = (int) (Level12_C2B8Field(privateAddress, int *, 0x64) + 7);
    if (Level12_C2B8Field(privateAddress, int *, 0x70) >= 0x34) {
        goto originalBlock106;
    }
    Level12_C2B8Field(savedWord17, unsigned char *, 0x4F) = (unsigned char) (Level12_C2B8Field(savedWord17, unsigned char *, 0x4F) - 1);
originalBlock106:
    if ((unsigned char) Level12_C2B8Field(savedWord17, unsigned char *, 0x4F) >= 9U) {
        goto originalBlock116;
    }
    Level12_C2B8Field(savedWord17, unsigned char *, 0x4F) = 9U;
    goto originalBlock116;
originalDispatch2_selector4:
    Level12_C2B8Field(savedWord17, int *, 0x14) = (int) (Level12_C2B8Field(savedWord17, int *, 0x14) + Level12_C2B8Field(privateAddress, int *, 0x64));
    temp_v0_4 = Level12_C2B8Field(privateAddress, int *, 0x64) - 0xA;
    Level12_C2B8Field(privateAddress, int *, 0x64) = temp_v0_4;
    if (temp_v0_4 >= 0) {
        goto originalBlock110;
    }
    Level12_C2B8Field(privateAddress, int *, 0x64) = 0;
originalBlock110:
    if (Level12_C2B8Field(privateAddress, int *, 0x64) != 0) {
        goto originalBlock124;
    }
    Level12_C2B8_func_8003BB10(ownerAddress, 7, 0);
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0x78;
    goto originalBlock118;
originalDispatch2_selector5:
    temp_v1_12 = Level12_C2B8Field(privateAddress, int *, 0x9C) + 1;
    Level12_C2B8Field(privateAddress, int *, 0x9C) = temp_v1_12;
    if (temp_v1_12 >= 0x1C) {
        goto originalBlock114;
    }
    Level12_C2B8_D_8006C7C0 = (int) Level12_C2B8Field(Level12_C2B8Field(privateAddress, int *, 0x98) + temp_v1_12,unsigned char*,0);
originalBlock114:
    var_a0_4 = privateAddress + 0x70;
    if (Level12_C2B8_D_8006C7C0 != 0xFF) {
        goto originalBlock117;
    }
    Level12_C2B8Field(savedWord16, signed char *, 0x49) = 1;
originalBlock116:
    var_a0_4 = privateAddress + 0x70;
originalBlock117:
    if (Level12_C2B8_func_800359A4(var_a0_4, 4) == 0) {
        goto originalBlock124;
    }
originalBlock118:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) + 1);
    goto originalBlock124;
originalDispatch2_selector6:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock124;
    }
    savedWord16=(int)&nativeFrame.sp40;
Level12_C2B8Keep(savedWord16);
    resultWord=Level12_C2B8_D_8006C7B4;
workWord=Level12_C2B8Field(ownerAddress,int*,0);
Level12_C2B8_D_8006C7C0=0;
    resultWord|=4;
Level12_C2B8_D_8006C7B4=resultWord;
resultWord=2;
    Level12_C2B8Field(ownerAddress,unsigned char*,0x48)=resultWord;
Level12_C2B8Field(workWord,unsigned char*,5)=resultWord;
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
resultWord<<=1;
workWord=Level12_C2B8Field((int)&Level12_C2B8_D_80065920,short*,resultWord);
    argument0=savedWord16;
resultWord=workWord*39;
resultWord>>=6;
nativeFrame.sp40=resultWord;
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
argument1=savedWord16;
resultWord<<=1;
    workWord=Level12_C2B8Field((int)&Level12_C2B8_D_800658A0,short*,resultWord);
    __asm__ volatile("":::"$2","memory");
resultWord=Level12_C2B8Field((int)&Level12_C2B8_D_80070328,int*,0x44);
    argument2=ownerAddress+12;
nativeFrame.sp48=0;
__asm__ volatile("":::"memory");
nativeFrame.sp48=resultWord;
    resultWord=workWord*39;
resultWord>>=6;
nativeFrame.sp44=resultWord;
Level12_C2B8_func_8004F194(argument0,argument1,argument2);
    argument0=savedWord16;
argument2=0;
argument1=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
argument3=0;
argument1+=128;
argument1&=255;
    Level12_C2B8_func_80013D44(argument0,argument1,argument2,argument3);
    if (Level12_C2B8Field((int)&Level12_C2B8_D_80070328, int *, 0x280) >= 0) {
        goto originalBlock124;
    }
    Level12_C2B8Field((int)&Level12_C2B8_D_80070328, int *, 0x280) = 0;
    goto originalBlock124;
originalDispatch2_selector7:
    Level12_C2B8Field(savedWord16, signed char *, 0x49) = 1;
    if (Level12_C2B8_D_8006C640 >= 0xA) {
        goto originalBlock205;
    }
    Level12_C2B8Field(savedWord17, int *, 0x14) = 0x3D21;
    Level12_C2B8Field(savedWord17, signed char *, 0x49) = 1;
    Level12_C2B8Field(savedWord17, unsigned char *, 0x4F) = 9U;
    Level12_C2B8_func_80055B18(ownerAddress);
    return;
originalBlock124:
originalBlock125:
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 0) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) >= 6U) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) >= 3U) {
        goto originalBlock129;
    }
    Level12_C2B8Field(privateAddress, int *, 0x6C) = (int) (Level12_C2B8Field(privateAddress, int *, 0x6C) - 0x11);
originalBlock129:
    Level12_C2B8_func_8004F178(&nativeFrame.sp20, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    resultWord=Level12_C2B8_func_8004EA2C(Level12_C2B8Field(privateAddress,int*,0x6C));
workWord=Level12_C2B8Field(privateAddress,int*,0x74);
    tailProduct23.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct23.full):"0"(tailProduct23.full));
    resultWord=nativeFrame.sp20;
    __asm__("":"=x"(tailProduct23.full):"0"(tailProduct23.full),"r"(resultWord));
productWord=(int)tailProduct23.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
nativeFrame.sp20=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(Level12_C2B8Field(privateAddress,int*,0x6C));
workWord=Level12_C2B8Field(privateAddress,int*,0x74);
    tailProduct24.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct24.full):"0"(tailProduct24.full));
    resultWord=nativeFrame.sp24;
    __asm__("":"=x"(tailProduct24.full):"0"(tailProduct24.full),"r"(resultWord));
productWord=(int)tailProduct24.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
nativeFrame.sp24=resultWord;
    nativeFrame.sp28 = Level12_C2B8Field(Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC), int *, 8);
    nativeFrame.sp38 = Level12_C2B8Field(savedWord17, int *, 0x14) + 0x1F4;
    Level12_C2B8_func_80013AE4(&nativeFrame.sp20, &nativeFrame.sp30);
    goto originalBlock314;
originalDispatch1_selector40:
    Level12_C2B8_func_8004F178(&nativeFrame.sp40, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC));
    Level12_C2B8_func_8004F178(&nativeFrame.sp50, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 0) {
        goto originalBlock134;
    }
    if (Level12_C2B8_D_8006E048 & 1) {
        goto originalBlock134;
    }
    if (!(Level12_C2B8_D_8006E53C & 0x810)) {
        goto originalBlock134;
    }
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 7U;
originalBlock134:
    temp_v1_13 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x49);
    if (temp_v1_13 >= 8U) {
        goto originalBlock206;
    }
switch(temp_v1_13){
case 0:goto originalDispatch3_selector0;
case 1:goto originalDispatch3_selector1;
case 2:goto originalDispatch3_selector2;
case 3:goto originalDispatch3_selector3;
case 4:goto originalDispatch3_selector4;
case 5:goto originalDispatch3_selector5;
case 6:goto originalDispatch3_selector6;
case 7:goto originalDispatch3_selector7;
default:goto originalBlock206;
}
originalDispatch3_selector0:
    Level12_C2B8_func_80013AE4(&nativeFrame.sp40, &nativeFrame.sp50);
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
argument0=Level12_C2B8Field(resultWord,int*,12);
argument1=argument0+16;
    resultWord=Level12_C2B8_func_8004F334(argument0,argument1);
workWord=Level12_C2B8Field(privateAddress,int*,0x68);
Level12_C2B8Field(privateAddress,int*,0x74)=resultWord;
    resultWord=Level12_C2B8Field(workWord,int*,12);
argument2=0;
argument3=Level12_C2B8Field(resultWord,int*,0);
argument0=Level12_C2B8Field(resultWord,int*,16);
    workWord=Level12_C2B8Field(resultWord,int*,4);
argument1=Level12_C2B8Field(resultWord,int*,20);
argument0=argument3-argument0;
argument1=workWord-argument1;
    resultWord=Level12_C2B8_func_8004E880(argument0,argument1,argument2);
    argument1=0;
argument2=30;
argument0=privateAddress;
resultWord<<=4;
Level12_C2B8Field(privateAddress,int*,0x6C)=resultWord;
    resultWord=1500;
Level12_C2B8Field(privateAddress,int*,0x7C)=resultWord;
originalLoop137:
    workWord=Level12_C2B8Field(argument0,int*,0x88);
resultWord=workWord*88;
workWord=Level12_C2B8_D_8006C550;
workWord+=resultWord;
    Level12_C2B8Field(workWord,unsigned char*,0x48)=argument2;
resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
resultWord=Level12_C2B8Field(resultWord,int*,12);
    resultWord=Level12_C2B8Field(resultWord,int*,24);
__asm__("":"=r"(argument1):"0"(argument1):"memory");
argument1++;
Level12_C2B8Field(workWord,int*,20)=resultWord;
    resultWord=argument1<3;
__asm__("":"=r"(argument0):"0"(argument0),"r"(resultWord));
argument0+=4;
if(resultWord)goto originalLoop137;
    __asm__ volatile("":::"$2","memory");
resultWord = 0x15E;
    goto originalBlock192;
originalDispatch3_selector1:
originalDispatch3_selector2:
originalDispatch3_selector3:
    workWord=Level12_C2B8Field(privateAddress,int*,0x88);
resultWord=workWord*88;
workWord=Level12_C2B8_D_8006C550;
savedWord17=workWord+resultWord;
    workWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x49);
__asm__ volatile("":::"$2","memory");
resultWord=1;
__asm__ volatile("":::"$18","memory");
savedWord18=80;
    if(workWord!=resultWord)goto originalBlock142;
    Level12_C2B8Keep(savedWord18);
    resultWord=Level12_C2B8_D_8006E048;
resultWord&=1;
savedWord16=(int)&nativeFrame.sp60;
if(!resultWord)goto originalBlock142;
    Level12_C2B8_func_8004F178(savedWord16,ownerAddress+12);
    __asm__ volatile("":::"$7","memory");
argument3=0x10008000;
resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
resultWord<<=1;
    workWord=Level12_C2B8Field((int)&Level12_C2B8_D_80065920,short*,resultWord);
    __asm__ volatile("":::"$6","memory");
argument2=(int)&Level12_C2B8_D_80070328+0x20C;
Level12_C2B8Keep(argument2);
    resultWord=workWord*125;
workWord=nativeFrame.sp60;
resultWord>>=9;
workWord+=resultWord;
nativeFrame.sp60=workWord;
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
argument0=argument2+32;
resultWord<<=1;
    workWord=Level12_C2B8Field((int)&Level12_C2B8_D_800658A0,short*,resultWord);
argument1=savedWord16;
Level12_C2B8Field(argument2,int*,0)=argument3;
    resultWord=workWord*125;
workWord=nativeFrame.sp64;
resultWord>>=9;
workWord+=resultWord;
nativeFrame.sp64=workWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
    __asm__ volatile("":::"$5","memory");
argument1=(int)&Level12_C2B8_D_80070328+12;
Level12_C2B8Keep(argument1);
__asm__ volatile("":::"$4","memory");
argument0=(int)&Level12_C2B8_D_80070328+0x228;
Level12_C2B8Keep(argument0);
    resultWord=Level12_C2B8Field(argument1,signed char*,0);
workWord=Level12_C2B8Field(argument1,signed char*,1);
    Level12_C2B8Field(argument0,signed char*,0)=resultWord;
Level12_C2B8Field(argument0,signed char*,1)=workWord;
    resultWord=Level12_C2B8Field(argument1,signed char*,2);
Level12_C2B8Field(argument0,signed char*,2)=resultWord;
    Level12_C2B8Field((int)&Level12_C2B8_D_80070328,int*,0x23C)=0;
originalBlock142:
    Level12_C2B8Keep(savedWord18);
resultWord=Level12_C2B8Field(privateAddress,int*,0x84);
resultWord=savedWord18<resultWord;
if(!resultWord)goto originalBlock149;
    if(Level12_C2B8_func_8003BFC0(savedWord17,Level12_C2B8Field(privateAddress,int*,0xDC)))goto originalBlock145;
    Level12_C2B8Field(privateAddress,int*,0xDC)=Level12_C2B8_func_8003BB10(savedWord17,6,4);
originalBlock145:
    if(!Level12_C2B8_func_8003BFC0(savedWord17,Level12_C2B8Field(privateAddress,int*,0xDC)))goto originalBlock149;
    argument0=Level12_C2B8Field(privateAddress,int*,0x84);
argument1=savedWord18*3;
workWord=argument1<<2;
    resultWord=(argument0<<3)-argument0;
resultWord<<=1;
resultWord+=900;
savedWord16=resultWord-workWord;
    resultWord=argument0*3;
workWord=(resultWord<<4)-resultWord;
workWord<<=1;
workWord+=3500;
    resultWord=(argument1<<4)-argument1;
resultWord<<=1;
argument1=workWord-resultWord;
    resultWord=savedWord16<7001;
if(resultWord)goto originalBlock148;
__asm__ volatile("":::"$16","memory");
savedWord16=7000;
originalBlock148:
    argument0=Level12_C2B8Field(privateAddress,int*,0xDC);
Level12_C2B8_func_8003C0B0(argument0,argument1);
    Level12_C2B8_func_8003C140(Level12_C2B8Field(privateAddress,int*,0xDC),savedWord16);
originalBlock149:
    temp_v1_15 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x49);
    if (temp_v1_15 != 1) {
        goto originalBlock152;
    }
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock171;
    }
    goto originalBlock155;
originalBlock152:
    if (temp_v1_15 != 2) {
        goto originalBlock156;
    }
    Level12_C2B8Field(privateAddress, int *, 0x7C) = (int) (Level12_C2B8Field(privateAddress, int *, 0x7C) - 0x19);
    Level12_C2B8Field(privateAddress, int *, 0x84) = (int) (Level12_C2B8Field(privateAddress, int *, 0x84) + 1);
    if (Level12_C2B8Field(privateAddress, int *, 0x7C) >= 0x1F4) {
        goto originalBlock171;
    }
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0x5A;
originalBlock155:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) + 1);
    goto originalBlock171;
originalBlock156:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock160;
    }
    if (Level12_C2B8_func_8003BFC0(ownerAddress, Level12_C2B8Field(privateAddress, int *, 0xDC)) == 0) {
        goto originalBlock159;
    }
    Level12_C2B8_func_8003BE70(Level12_C2B8Field(privateAddress, int *, 0xDC));
originalBlock159:
    Level12_C2B8Field(privateAddress, int *, 0xDC) = -1;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) + 1);
    Level12_C2B8_func_8003BB10(savedWord17, 0xA, 0);
originalBlock160:
    temp_v1_16 = Level12_C2B8Field(privateAddress, int *, 0x7C);
    Level12_C2B8Field(privateAddress, int *, 0x84) = (int) (Level12_C2B8Field(privateAddress, int *, 0x84) + 2);
    if (temp_v1_16 < 0x12D) {
        goto originalBlock162;
    }
    Level12_C2B8Field(privateAddress, int *, 0x7C) = (int) (temp_v1_16 - 0x12);
originalBlock162:
    argument0=0x51EB851F;
Level12_C2B8Keep(argument0);
    workWord=Level12_C2B8Field(privateAddress,int*,0x7C);
__asm__ volatile("":::"$2","memory");
resultWord=500;
resultWord-=workWord;
    tailProduct16.full=(long long)resultWord*(long long)argument0;
    resultWord>>=31;
    __asm__("":"=x"(tailProduct16.full):"0"(tailProduct16.full));
    productWord=(int)tailProduct16.words.high;
Level12_C2B8Keep(productWord);
    workWord=productWord>>4;
savedWord23=workWord-resultWord;
__asm__("":"=r"(savedWord23):"0"(savedWord23):"$20");
__asm__ volatile("":::"$20","memory");
savedWord20=0;
    if(savedWord23<=0)goto originalBlock165;
    tableFP=(int)&Level12_C2B8_D_800658A0;
Level12_C2B8Keep(tableFP);
    savedWord18=(int)&nativeFrame.sp70;
Level12_C2B8Keep(savedWord18);
savedWord21=(int)&nativeFrame.sp80;
Level12_C2B8Keep(savedWord21);
originalLoop164:
    savedWord20++;
    resultWord=Level12_C2B8_rand();
savedWord16=resultWord&255;
    resultWord=Level12_C2B8_rand();
__asm__ volatile("":::"$4","memory");
argument0=140;
__asm__ volatile("":::"$5","memory");
argument1=200;
    __asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord17=resultWord&255;
    resultWord=Level12_C2B8_func_8003636C(argument0,argument1);
    savedWord16<<=1;
__asm__ volatile("":::"$11","memory");
productWord=(int)&Level12_C2B8_D_80065920;
Level12_C2B8Keep(productWord);
    workWord=savedWord16+productWord;
workWord=Level12_C2B8Field(workWord,short*,0);
    tailProduct11.full=(long long)workWord*(long long)resultWord;
    savedWord17<<=1;
argument1=savedWord17+productWord;
    __asm__("":"=x"(tailProduct11.full):"0"(tailProduct11.full));
    productWord=(int)tailProduct11.words.low;
__asm__("":"=r"(productWord):"0"(productWord):"memory");
    argument0=Level12_C2B8Field(argument1,short*,0);
workWord=productWord>>12;
    tailProduct12.full=(long long)workWord*(long long)argument0;
    savedWord16+=tableFP;
    __asm__("":"=x"(tailProduct12.full):"0"(tailProduct12.full));
    productWord=(int)tailProduct12.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
nativeFrame.sp80=workWord;
    workWord=Level12_C2B8Field(savedWord16,short*,0);
    tailProduct13.full=(long long)workWord*(long long)resultWord;
    __asm__("":"=x"(tailProduct13.full):"0"(tailProduct13.full));
    productWord=(int)tailProduct13.words.low;
__asm__("":"=r"(productWord):"0"(productWord):"memory");
    argument0=Level12_C2B8Field(argument1,short*,0);
workWord=productWord>>12;
    tailProduct14.full=(long long)workWord*(long long)argument0;
    savedWord17+=tableFP;
    __asm__("":"=x"(tailProduct14.full):"0"(tailProduct14.full));
    productWord=(int)tailProduct14.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
nativeFrame.sp84=workWord;
    workWord=Level12_C2B8Field(savedWord17,short*,0);
    tailProduct15.full=(long long)workWord*(long long)resultWord;
    argument1=savedWord21;
argument0=savedWord18;
    __asm__("":"=x"(tailProduct15.full):"0"(tailProduct15.full));
    productWord=(int)tailProduct15.words.low;
Level12_C2B8Keep(productWord);
    resultWord=productWord>>12;
nativeFrame.sp88=resultWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
    Level12_C2B8_func_8004F0E8(savedWord18,1);
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
argument0=savedWord18;
argument2=Level12_C2B8Field(resultWord,int*,12);
argument1=savedWord18;
argument2+=16;
    Level12_C2B8_func_8004F194(argument0,argument1,argument2);
    __asm__ volatile("":::"$4","memory");
argument0=1;
__asm__ volatile("":::"$5","memory");
argument1=13;
__asm__("":"=r"(argument0),"=r"(argument1):"0"(argument0),"1"(argument1):"memory");
workWord=Level12_C2B8Field(privateAddress,int*,0x88);
__asm__ volatile("":::"$6","memory");
argument2=savedWord18;
    resultWord=workWord*88;
workWord=Level12_C2B8_D_8006C550;
resultWord+=workWord;
resultWord=Level12_C2B8Field(resultWord,int*,20);
nativeFrame.sp78=resultWord;
    Level12_C2B8_SpawnParticle(argument0,argument1,argument2,savedWord21);
    if (savedWord20 < savedWord23) {
        goto originalLoop164;
    }
originalBlock165:
    __asm__ volatile("":::"$7");
__asm__ volatile("":::"$7","memory");
argument3=0;
limitWord=500;
Level12_C2B8Keep(limitWord);
    reciprocalWord=0x10624DD3;
Level12_C2B8Keep(reciprocalWord);
fullByteWord=255;
Level12_C2B8Keep(fullByteWord);
argument2=privateAddress;
originalLoop166:
    resultWord=Level12_C2B8Field(privateAddress,int*,0x7C);
resultWord=limitWord-resultWord;
workWord=resultWord<<4;
workWord-=resultWord;
    tailProduct17.full=(long long)workWord*(long long)reciprocalWord;
    argument0=Level12_C2B8Field(argument2,int*,0x88);
workWord>>=31;
    __asm__("":"=x"(tailProduct17.full):"0"(tailProduct17.full),"r"(argument0),"r"(workWord));
    productWord=tailProduct17.words.high;
Level12_C2B8Keep(productWord);
    resultWord=productWord>>5;
argument1=resultWord-workWord;
    resultWord=argument0*88;
workWord=Level12_C2B8_D_8006C550;
    workWord+=resultWord;
if(argument1>=0)goto originalBlock168;
    __asm__ volatile("":::"$5","memory");
argument1=0;
originalBlock168:
    resultWord=argument1<16;
if(resultWord)goto originalBlock170;
__asm__ volatile("":::"$5","memory");
argument1=15;
originalBlock170:
    argument2+=4;
argument3++;
resultWord=argument1+48;
Level12_C2B8Field(workWord,unsigned char*,0x57)=resultWord;
    resultWord=argument3<3;
    Level12_C2B8Field(workWord,unsigned char*,0x54)=fullByteWord;
    Level12_C2B8Field(workWord,unsigned char*,0x55)=fullByteWord;
    Level12_C2B8Field(workWord,unsigned char*,0x56)=fullByteWord;
    if(resultWord)goto originalLoop166;
originalBlock171:
    resultWord=Level12_C2B8Field(privateAddress,int*,0x80);
argument0=Level12_C2B8Field(privateAddress,int*,0x84);
    __asm__ volatile("":::"$3","memory");
workWord=Level12_C2B8Field(privateAddress,int*,0x84);
resultWord+=argument0;
workWord++;
    Level12_C2B8Field(privateAddress, int *, 0x84) = workWord;
    Level12_C2B8Field(privateAddress, int *, 0x80) = resultWord;
    if (workWord < 0x201) {
        goto originalBlock173;
    }
    Level12_C2B8Field(privateAddress, int *, 0x84) = 0x200;
originalBlock173:
    __asm__ volatile("":::"$23","memory");
savedWord23 = 0;
    __asm__ volatile("":::"$21","memory");
savedWord21 = 0;
    savedWord20 = privateAddress;
originalLoop174:
    workWord=Level12_C2B8Field(savedWord20,int*,0x88);
__asm__ volatile("":::"$17","memory");
savedWord17=Level12_C2B8_D_8006C550;
Level12_C2B8Keep(savedWord17);
    savedWord16=Level12_C2B8Field(privateAddress,int*,0x80);
resultWord=workWord*88;
savedWord17+=resultWord;
argument0=savedWord17+12;
    savedWord16+=savedWord21;
resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
savedWord16&=4095;
    argument1=Level12_C2B8Field(resultWord,int*,12);
savedWord18=Level12_C2B8Field(savedWord17,int*,20);
argument1+=16;
    Level12_C2B8_func_8004F178(argument0,argument1);
    resultWord=Level12_C2B8_func_8004EA2C(savedWord16);
workWord=Level12_C2B8Field(privateAddress,int*,0x7C);
    tailProduct29.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct29.full):"0"(tailProduct29.full));
    argument0=savedWord16;
resultWord=Level12_C2B8Field(savedWord17,int*,12);
    __asm__("":"=x"(tailProduct29.full):"0"(tailProduct29.full),"r"(argument0),"r"(resultWord));
productWord=(int)tailProduct29.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
Level12_C2B8Field(savedWord17,int*,12)=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
workWord=Level12_C2B8Field(privateAddress,int*,0x7C);
    tailProduct30.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct30.full):"0"(tailProduct30.full));
    savedWord20+=4;
savedWord23++;
savedWord21+=0x555;
__asm__ volatile("":::"$6","memory");
argument2=0;
    Level12_C2B8Field(savedWord17,int*,20)=savedWord18;
__asm__ volatile("":::"memory");
resultWord=Level12_C2B8Field(savedWord17,int*,16);
    __asm__("":"=x"(tailProduct30.full):"0"(tailProduct30.full),"r"(savedWord20),"r"(savedWord23),"r"(savedWord21),"r"(argument2),"r"(resultWord):"memory");
productWord=(int)tailProduct30.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
Level12_C2B8Field(savedWord17,int*,16)=resultWord;
__asm__ volatile("":::"$5","memory");
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
argument0=Level12_C2B8Field(savedWord17,int*,12);
__asm__ volatile("":::"memory");
    resultWord=Level12_C2B8Field(resultWord,int*,12);
argument1=Level12_C2B8Field(savedWord17,int*,16);
    workWord=Level12_C2B8Field(resultWord,int*,16);
resultWord=Level12_C2B8Field(resultWord,int*,20);
    argument0=workWord-argument0;
argument1=resultWord-argument1;
    resultWord=Level12_C2B8_func_8004E880(argument0,argument1,argument2);
Level12_C2B8Field(savedWord17,signed char*,0x46)=resultWord;
    if (savedWord23 >= 3) {
        goto originalBlock206;
    }
    goto originalLoop174;
originalDispatch3_selector4:
    var_v1 = Level12_C2B8_D_8006C7C0 + 0xC;
    if (var_v1 < 0x100) {
        goto originalBlock178;
    }
    var_v1 = 0xFF;
originalBlock178:
    resultWord=Level12_C2B8Field(privateAddress,int*,0x80);
argument0=Level12_C2B8Field(privateAddress,int*,0x84);
Level12_C2B8_D_8006C7C0=var_v1;
    __asm__ volatile("":::"$3","memory");
workWord=Level12_C2B8Field(privateAddress,int*,0x84);
resultWord+=argument0;
workWord++;
    Level12_C2B8Field(privateAddress, int *, 0x84) = workWord;
    Level12_C2B8Field(privateAddress, int *, 0x80) = resultWord;
    if (workWord < 0x201) {
        goto originalBlock180;
    }
    Level12_C2B8Field(privateAddress, int *, 0x84) = 0x200;
originalBlock180:
    __asm__ volatile("":::"$23","memory");
savedWord23 = 0;
    __asm__ volatile("":::"$21","memory");
savedWord21 = 0;
    savedWord20 = privateAddress;
originalLoop181:
    workWord=Level12_C2B8Field(savedWord20,int*,0x88);
__asm__ volatile("":::"$17","memory");
savedWord17=Level12_C2B8_D_8006C550;
Level12_C2B8Keep(savedWord17);
    savedWord16=Level12_C2B8Field(privateAddress,int*,0x80);
resultWord=workWord*88;
savedWord17+=resultWord;
argument0=savedWord17+12;
    savedWord16+=savedWord21;
resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
savedWord16&=4095;
    argument1=Level12_C2B8Field(resultWord,int*,12);
savedWord18=Level12_C2B8Field(savedWord17,int*,20);
argument1+=16;
    Level12_C2B8_func_8004F178(argument0,argument1);
    resultWord=Level12_C2B8_func_8004EA2C(savedWord16);
workWord=Level12_C2B8Field(privateAddress,int*,0x7C);
    tailProduct31.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct31.full):"0"(tailProduct31.full));
    argument0=savedWord16;
resultWord=Level12_C2B8Field(savedWord17,int*,12);
    __asm__("":"=x"(tailProduct31.full):"0"(tailProduct31.full),"r"(argument0),"r"(resultWord));
productWord=(int)tailProduct31.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
Level12_C2B8Field(savedWord17,int*,12)=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
workWord=Level12_C2B8Field(privateAddress,int*,0x7C);
    tailProduct32.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct32.full):"0"(tailProduct32.full));
    savedWord20+=4;
savedWord23++;
savedWord21+=0x555;
__asm__ volatile("":::"$6","memory");
argument2=0;
    Level12_C2B8Field(savedWord17,int*,20)=savedWord18;
__asm__ volatile("":::"memory");
resultWord=Level12_C2B8Field(savedWord17,int*,16);
    __asm__("":"=x"(tailProduct32.full):"0"(tailProduct32.full),"r"(savedWord20),"r"(savedWord23),"r"(savedWord21),"r"(argument2),"r"(resultWord):"memory");
productWord=(int)tailProduct32.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
Level12_C2B8Field(savedWord17,int*,16)=resultWord;
__asm__ volatile("":::"$5","memory");
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
argument0=Level12_C2B8Field(savedWord17,int*,12);
__asm__ volatile("":::"memory");
    resultWord=Level12_C2B8Field(resultWord,int*,12);
argument1=Level12_C2B8Field(savedWord17,int*,16);
    workWord=Level12_C2B8Field(resultWord,int*,16);
resultWord=Level12_C2B8Field(resultWord,int*,20);
    argument0=workWord-argument0;
argument1=resultWord-argument1;
    resultWord=Level12_C2B8_func_8004E880(argument0,argument1,argument2);
Level12_C2B8Field(savedWord17,signed char*,0x46)=resultWord;
    if (savedWord23 < 3) {
        goto originalLoop181;
    }
    if (Level12_C2B8_D_8006C7C0 != 0xFF) {
        goto originalBlock206;
    }
    temp_v0_11 = Level12_C2B8_SpawnMoby(0x158, ownerAddress);
    Level12_C2B8Field(privateAddress, int*, 0xD8) = temp_v0_11;
    if (temp_v0_11 == 0) {
        goto originalBlock193;
    }
    Level12_C2B8_func_8004F178(temp_v0_11 + 0xC, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    temp_v1_20 = Level12_C2B8Field(privateAddress, int*, 0xD8);
    Level12_C2B8Field(temp_v1_20, int *, 0x14) = (int) (Level12_C2B8Field(temp_v1_20, int *, 0x14) + 0x9C4);
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
resultWord=Level12_C2B8Field(resultWord,int*,12);
argument2=0;
    argument3=Level12_C2B8Field(resultWord,int*,0);
argument0=Level12_C2B8Field(resultWord,int*,16);
workWord=Level12_C2B8Field(resultWord,int*,4);
argument1=Level12_C2B8Field(resultWord,int*,20);
    argument0=argument3-argument0;
argument1=workWord-argument1;
resultWord=Level12_C2B8_func_8004E880(argument0,argument1,argument2);
    workWord=Level12_C2B8Field(privateAddress,int*,0xD8);
savedWord17=0;
Level12_C2B8Field(workWord,signed char*,0x46)=resultWord;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x4C) = 0x3F;
    savedWord16 = privateAddress;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x4E) = 0x3F;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x57) = 0x30;
originalLoop185:
    temp_a0_9 = (Level12_C2B8Field(savedWord16, int *, 0x88) * 0x58) + Level12_C2B8_D_8006C550;
    if ((unsigned char) Level12_C2B8Field(temp_a0_9, unsigned char *, 0x48) >= 0x80U) {
        goto originalBlock187;
    }
    Level12_C2B8_func_80055B18(temp_a0_9);
originalBlock187:
    savedWord17 += 1;
    savedWord16 += 4;
    if (savedWord17 < 3) {
        goto originalLoop185;
    }
    goto originalBlock193;
originalDispatch3_selector5:
    resultWord = Level12_C2B8_D_8006C7C0 - 0xC;
    if (resultWord >= 0) {
        goto originalBlock191;
    }
    __asm__ volatile("":::"$2","memory");
resultWord = 0;
originalBlock191:
    Level12_C2B8_D_8006C7C0=resultWord;
    if(resultWord!=0?(resultWord=90,1):(resultWord=90,0))goto originalBlock206;
originalBlock192:
    Level12_C2B8Field(privateAddress, int *, 0x70) = resultWord;
originalBlock193:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) + 1);
    goto originalBlock206;
originalDispatch3_selector6:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock206;
    }
    savedWord16=(int)&nativeFrame.sp80;
Level12_C2B8Keep(savedWord16);
    resultWord=Level12_C2B8_D_8006C7B4;
workWord=Level12_C2B8Field(ownerAddress,int*,0);
Level12_C2B8_D_8006C7C0=0;
    resultWord|=2;
Level12_C2B8_D_8006C7B4=resultWord;
resultWord=2;
    Level12_C2B8Field(ownerAddress,unsigned char*,0x48)=0;
Level12_C2B8Field(workWord,unsigned char*,5)=resultWord;
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
resultWord<<=1;
workWord=Level12_C2B8Field((int)&Level12_C2B8_D_80065920,short*,resultWord);
    argument0=savedWord16;
resultWord=workWord*39;
resultWord>>=6;
nativeFrame.sp80=resultWord;
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
argument1=savedWord16;
resultWord<<=1;
    workWord=Level12_C2B8Field((int)&Level12_C2B8_D_800658A0,short*,resultWord);
    __asm__ volatile("":::"$2","memory");
resultWord=Level12_C2B8Field((int)&Level12_C2B8_D_80070328,int*,0x44);
    argument2=ownerAddress+12;
nativeFrame.sp88=0;
__asm__ volatile("":::"memory");
nativeFrame.sp88=resultWord;
    resultWord=workWord*39;
resultWord>>=6;
nativeFrame.sp84=resultWord;
Level12_C2B8_func_8004F194(argument0,argument1,argument2);
    argument0=savedWord16;
argument2=0;
argument1=Level12_C2B8Field(ownerAddress,unsigned char*,0x46);
argument3=0;
argument1+=128;
argument1&=255;
    Level12_C2B8_func_80013D44(argument0,argument1,argument2,argument3);
    if (Level12_C2B8Field((int)&Level12_C2B8_D_80070328, int *, 0x280) >= 0) {
        goto originalBlock345;
    }
    Level12_C2B8Field((int)&Level12_C2B8_D_80070328, int *, 0x280) = 0;
    return;
originalDispatch3_selector7:
    __asm__ volatile("":::"$17","memory");
savedWord17 = 0;
    if (Level12_C2B8_D_8006C640 >= 0xA) {
        goto originalBlock205;
    }
    savedWord16 = privateAddress;
originalLoop199:
    temp_a0_10 = (Level12_C2B8Field(savedWord16, int *, 0x88) * 0x58) + Level12_C2B8_D_8006C550;
    if ((unsigned char) Level12_C2B8Field(temp_a0_10, unsigned char *, 0x48) >= 0x80U) {
        goto originalBlock201;
    }
    Level12_C2B8_func_80055B18(temp_a0_10);
originalBlock201:
    savedWord17 += 1;
    savedWord16 += 4;
    if (savedWord17 < 3) {
        goto originalLoop199;
    }
    if (Level12_C2B8Field(privateAddress, int*, 0xD8) != 0) {
        goto originalBlock302;
    }
    temp_v0_13 = Level12_C2B8_SpawnMoby(0x158, ownerAddress);
    Level12_C2B8Field(privateAddress, int*, 0xD8) = temp_v0_13;
    if (temp_v0_13 == 0) {
        goto originalBlock302;
    }
    Level12_C2B8_func_8004F178(temp_v0_13 + 0xC, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    temp_v1_21 = Level12_C2B8Field(privateAddress, int*, 0xD8);
    Level12_C2B8Field(temp_v1_21, int *, 0x14) = (int) (Level12_C2B8Field(temp_v1_21, int *, 0x14) + 0x9C4);
    temp_v0_14 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    temp_a3_5 = Level12_C2B8Field(temp_v0_14, int *, 0);
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x46) = Level12_C2B8_func_8004E880(temp_a3_5 - Level12_C2B8Field(temp_v0_14, int *, 0x10), Level12_C2B8Field(temp_v0_14, int *, 4) - Level12_C2B8Field(temp_v0_14, int *, 0x14), 0);
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x4C) = 0x3F;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x4E) = 0x3F;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xD8), signed char *, 0x57) = 0x30;
    goto originalBlock302;
originalBlock205:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) - 1);
    return;
originalBlock206:
    temp_v0_15 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x49);
    if (temp_v0_15 == 0) {
        goto originalBlock314;
    }
    if (temp_v0_15 >= 7U) {
        goto originalBlock314;
    }
    Level12_C2B8Field(privateAddress, int *, 0x6C) = (int) (Level12_C2B8Field(privateAddress, int *, 0x6C) - 0xC);
    Level12_C2B8_func_8004F178(&nativeFrame.sp40, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    resultWord=Level12_C2B8_func_8004EA2C(Level12_C2B8Field(privateAddress,int*,0x6C));
workWord=Level12_C2B8Field(privateAddress,int*,0x74);
    tailProduct25.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct25.full):"0"(tailProduct25.full));
    resultWord=nativeFrame.sp40;
    __asm__("":"=x"(tailProduct25.full):"0"(tailProduct25.full),"r"(resultWord));
productWord=(int)tailProduct25.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
nativeFrame.sp40=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(Level12_C2B8Field(privateAddress,int*,0x6C));
workWord=Level12_C2B8Field(privateAddress,int*,0x74);
    tailProduct26.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct26.full):"0"(tailProduct26.full));
    resultWord=nativeFrame.sp44;
    __asm__("":"=x"(tailProduct26.full):"0"(tailProduct26.full),"r"(resultWord));
productWord=(int)tailProduct26.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
nativeFrame.sp44=resultWord;
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
__asm__ volatile("":::"$5","memory");
argument1=0;
    resultWord=Level12_C2B8Field(resultWord,int*,12);
argument2=Level12_C2B8_D_8006C550;
    resultWord=Level12_C2B8Field(resultWord,int*,8);
argument0=privateAddress;
nativeFrame.sp58=0;
nativeFrame.sp48=resultWord;
originalLoop209:
    workWord=Level12_C2B8Field(argument0,int*,0x88);
argument0+=4;
resultWord=workWord*88;
resultWord=argument2+resultWord;
    workWord=nativeFrame.sp58;
resultWord=Level12_C2B8Field(resultWord,int*,20);
argument1++;
workWord+=resultWord;
    resultWord=argument1<3;
nativeFrame.sp58=workWord;
if(resultWord)goto originalLoop209;
    __asm__ volatile("":::"$2","memory");
resultWord=0x55555556;
tailProduct36.full=(long long)workWord*(long long)resultWord;
    argument0=(int)&nativeFrame.sp40;
argument1=(int)&nativeFrame.sp50;
resultWord=workWord>>31;
    __asm__("":"=x"(tailProduct36.full):"0"(tailProduct36.full),"r"(argument0),"r"(argument1),"r"(resultWord));
    productWord=tailProduct36.words.high;
Level12_C2B8Keep(productWord);
resultWord=productWord-resultWord;
nativeFrame.sp58=resultWord;
    Level12_C2B8_func_80013AE4(argument0,argument1);
    goto originalBlock314;
originalDispatch1_selector60:
    argument0=(int)&nativeFrame.sp60;
resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
workWord=Level12_C2B8Field(privateAddress,int*,0x60);
    argument1=Level12_C2B8Field(resultWord,int*,12);
resultWord=workWord*11;
Level12_C2B8Keep(resultWord);
__asm__ volatile("":::"$3","memory");
workWord=Level12_C2B8_D_8006C550;
__asm__("":"=r"(resultWord):"0"(resultWord):"memory");
resultWord<<=3;
    __asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord16=workWord+resultWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
    resultWord=Level12_C2B8Field(privateAddress,int*,0x68);
argument1=Level12_C2B8Field(resultWord,int*,12);
argument0=(int)&nativeFrame.sp70;
argument1+=16;
    Level12_C2B8_func_8004F178(argument0,argument1);
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 0) {
        goto originalBlock215;
    }
    if (Level12_C2B8_D_8006E048 & 1) {
        goto originalBlock215;
    }
    if (!(Level12_C2B8_D_8006E53C & 0x810)) {
        goto originalBlock215;
    }
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 6U;
originalBlock215:
    temp_v1_23 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x49);
    if (temp_v1_23 >= 7U) {
        goto originalBlock249;
    }
switch(temp_v1_23){
case 0:goto originalDispatch4_selector0;
case 1:goto originalDispatch4_selector1;
case 2:goto originalDispatch4_selector2;
case 3:goto originalDispatch4_selector3;
case 4:goto originalDispatch4_selector4;
case 5:goto originalDispatch4_selector5;
case 6:goto originalDispatch4_selector6;
default:goto originalBlock249;
}
originalDispatch4_selector0:
    Level12_C2B8_func_80013AE4(&nativeFrame.sp60, &nativeFrame.sp70);
    temp_a0_11 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    Level12_C2B8Field(privateAddress, int *, 0x74) = Level12_C2B8_func_8004F334(temp_a0_11, temp_a0_11 + 0x10);
    temp_v0_17 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    temp_a3_6 = Level12_C2B8Field(temp_v0_17, int *, 0);
    Level12_C2B8Field(privateAddress, int *, 0x6C) = (int) (Level12_C2B8_func_8004E880(temp_a3_6 - Level12_C2B8Field(temp_v0_17, int *, 0x10), Level12_C2B8Field(temp_v0_17, int *, 4) - Level12_C2B8Field(temp_v0_17, int *, 0x14), 0) * 0x10);
    Level12_C2B8Field(privateAddress, int *, 0x7C) = 0x5DC;
    goto originalBlock245;
originalDispatch4_selector1:
    if (Level12_C2B8_func_800359A4(privateAddress + 0xAE, 2) == 0) {
        goto originalBlock248;
    }
    Level12_C2B8_func_8003BB10(0, 8, 1);
    resultWord=Level12_C2B8Field(privateAddress,short*,0xAC);
workWord=Level12_C2B8Field(privateAddress,int*,0xA8);
resultWord<<=1;
resultWord+=workWord;
    workWord=Level12_C2B8Field(resultWord,unsigned char*,0);
savedWord21=0;
resultWord=workWord<<2;
savedWord23=resultWord+workWord;
    resultWord=savedWord23<<1;
resultWord+=10;
nativeFrame.spD0=resultWord;
resultWord=savedWord23<<2;
resultWord+=15;
nativeFrame.spD8=resultWord;
    if (savedWord23 == 0) {
        goto originalBlock222;
    }
    savedWord20=(int)&nativeFrame.sp90;
Level12_C2B8Keep(savedWord20);
var_fp=(int)&nativeFrame.spA0;
Level12_C2B8Keep(var_fp);
originalLoop221:
    savedWord21++;
    resultWord=Level12_C2B8_rand();
__asm__ volatile("":::"$4","memory");
argument0=800;
__asm__ volatile("":::"$5","memory");
argument1=2048;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord18=resultWord&4095;
    resultWord=Level12_C2B8_func_8003636C(argument0,argument1);
savedWord17=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(savedWord17);
argument0=savedWord18;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(argument0);
    productWord=nativeFrame.spD0;
Level12_C2B8Keep(productWord);
tailProduct18.full=(long long)resultWord*(long long)productWord;
__asm__("":"=x"(tailProduct18.full):"0"(tailProduct18.full));
    productWord=(int)tailProduct18.words.low;
Level12_C2B8Keep(productWord);
__asm__("":"=r"(savedWord16):"0"(savedWord16),"r"(productWord));
savedWord16>>=6;
    tailProduct19.full=(long long)savedWord16*(long long)productWord;
__asm__("":"=x"(tailProduct19.full):"0"(tailProduct19.full));
    argument0=savedWord17;
productWord=(int)tailProduct19.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>18;
nativeFrame.spA0=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(argument0);
argument0=savedWord18;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
    productWord=nativeFrame.spD0;
Level12_C2B8Keep(productWord);
tailProduct20.full=(long long)resultWord*(long long)productWord;
__asm__("":"=x"(tailProduct20.full):"0"(tailProduct20.full));
    productWord=(int)tailProduct20.words.low;
Level12_C2B8Keep(productWord);
__asm__("":"=r"(savedWord16):"0"(savedWord16),"r"(productWord));
savedWord16>>=6;
    tailProduct21.full=(long long)savedWord16*(long long)productWord;
__asm__("":"=x"(tailProduct21.full):"0"(tailProduct21.full));
    argument0=savedWord17;
productWord=(int)tailProduct21.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>18;
nativeFrame.spA4=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
    productWord=nativeFrame.spD8;
Level12_C2B8Keep(productWord);
tailProduct22.full=(long long)resultWord*(long long)productWord;
__asm__("":"=x"(tailProduct22.full):"0"(tailProduct22.full));
    argument0=savedWord20;
argument1=var_fp;
__asm__("":"=x"(tailProduct22.full):"0"(tailProduct22.full),"r"(argument0),"r"(argument1));
productWord=(int)tailProduct22.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>12;
nativeFrame.spA8=resultWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
Level12_C2B8_func_8004F0E8(savedWord20,1);
    resultWord=Level12_C2B8Field(privateAddress,int*,0xA0);
argument0=savedWord20;
argument2=Level12_C2B8Field(resultWord,int*,12);
argument1=savedWord20;
    Level12_C2B8_func_8004F194(argument0,argument1,argument2);
    __asm__ volatile("":::"$4","memory");
argument0=1;
__asm__ volatile("":::"$5","memory");
argument1=0;
argument2=savedWord20;
    __asm__("":"=r"(argument0),"=r"(argument1),"=r"(argument2):"0"(argument0),"1"(argument1),"2"(argument2):"memory");
resultWord=(int)Level12_C2B8_SpawnParticle;
    __asm__("":"=r"(resultWord):"0"(resultWord):"memory");
argument3=var_fp;
    ((void(*)(int,int,int,int))resultWord)(argument0,argument1,argument2,argument3);
    resultWord=savedWord21<savedWord23;
if(resultWord)goto originalLoop221;
originalBlock222:
    resultWord=Level12_C2B8Field(privateAddress,short*,0xAC);
workWord=Level12_C2B8Field(privateAddress,int*,0xA8);
resultWord<<=1;
resultWord+=workWord;
    argument0=Level12_C2B8Field(resultWord,unsigned char*,1);
__asm__ volatile("":::"$2","memory");
resultWord=255;
    __asm__("":"=r"(argument0):"0"(argument0),"r"(resultWord));
workWord=argument0&255;
    if(workWord!=resultWord){
        goto originalBlock226;
    }
    temp_v0_19 = Level12_C2B8_SpawnMoby(0x84, ownerAddress);
    Level12_C2B8Field(privateAddress, int*, 0xA4) = temp_v0_19;
    if (temp_v0_19 == 0) {
        goto originalBlock225;
    }
    Level12_C2B8_func_8003BB10(temp_v0_19, 9, 1);
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xA4), signed char *, 0x4C) = 0x50;
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xA4), signed char *, 0x4E) = 0x3F;
    Level12_C2B8_func_8004F178(Level12_C2B8Field(privateAddress, int*, 0xA4) + 0xC, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xA0), int*, 0xC));
    Level12_C2B8Field(privateAddress, int *, 0x64) = 0x17C;
originalBlock225:
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0xC8;
    goto originalBlock245;
originalBlock226:
    Level12_C2B8Field(privateAddress, short *, 0xAE) = (short) argument0;
    Level12_C2B8Field(privateAddress, short *, 0xAC) = (short) ((unsigned short) Level12_C2B8Field(privateAddress, short *, 0xAC) + 1);
    goto originalBlock248;
originalDispatch4_selector2:
originalDispatch4_selector3:
    Level12_C2B8Field(privateAddress, int *, 0xD4) = 1;
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) != 2) {
        goto originalBlock235;
    }
    if (Level12_C2B8Field(privateAddress, int*, 0xA4) == 0) {
        goto originalBlock230;
    }
    temp_a3_7 = Level12_C2B8Field(ownerAddress, int *, 0xC);
    temp_v0_20 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xA0), int*, 0xC);
    temp_v0_21 = (Level12_C2B8_func_8004E880(temp_a3_7 - Level12_C2B8Field(temp_v0_20, int *, 0), Level12_C2B8Field(ownerAddress, int *, 0x10) - Level12_C2B8Field(temp_v0_20, int *, 4), 0) & 0xFF) * 2;
    temp_a1_4 = Level12_C2B8Field(privateAddress, int*, 0xA4);
    Level12_C2B8Field(temp_a1_4, int *, 0x14) = (int) (Level12_C2B8Field(temp_a1_4, int *, 0x14) + Level12_C2B8Field(privateAddress, int *, 0x64));
    Level12_C2B8Field(privateAddress, int *, 0x64) = (int) (Level12_C2B8Field(privateAddress, int *, 0x64) - 0xC);
    temp_a2_2 = Level12_C2B8Field(privateAddress, int*, 0xA4);
    Level12_C2B8Field(temp_a2_2, int *, 0xC) = (int) (Level12_C2B8Field(temp_a2_2, int *, 0xC) + ((int) (Level12_C2B8Field((int)&Level12_C2B8_D_80065920,short*,0 + temp_v0_21) * 0x4B) >> 0xA));
    temp_a2_3 = Level12_C2B8Field(privateAddress, int*, 0xA4);
    Level12_C2B8Field(temp_a2_3, int *, 0x10) = (int) (Level12_C2B8Field(temp_a2_3, int *, 0x10) + ((int) (Level12_C2B8Field((int)&Level12_C2B8_D_800658A0,short*,0 + temp_v0_21) * 0x4B) >> 0xA));
    Level12_C2B8_SpawnParticle(4, 0xC, Level12_C2B8Field(privateAddress, int*, 0xA4), (int *)5);
originalBlock230:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock234;
    }
    temp_a0_13 = Level12_C2B8Field(privateAddress, int*, 0xA4);
    if (temp_a0_13 == 0) {
        goto originalBlock233;
    }
    Level12_C2B8_func_80055B18(temp_a0_13);
    Level12_C2B8Field(privateAddress, int*, 0xA4) = 0;
originalBlock233:
    Level12_C2B8Field(privateAddress, int *, 0x70) = 0x8C;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) + 1);
originalBlock234:
originalBlock235:
    var_a0_7 = privateAddress + 0x70;
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) != 3) {
        goto originalBlock248;
    }
    temp_v1_25 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    Level12_C2B8Field(temp_v1_25, int *, 0x18) = (int) (Level12_C2B8Field(temp_v1_25, int *, 0x18) + 0x37);
    temp_v1_26 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC);
    resultWord=Level12_C2B8Field(temp_v1_26,int*,8);
__asm__ volatile("":::"$5","memory");
argument1=4;
Level12_C2B8Keep(argument1);
resultWord-=75;
Level12_C2B8Field(temp_v1_26,int*,8)=resultWord;
    goto originalBlock244;
originalDispatch4_selector4:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock248;
    }
    argument0=0;
argument1=7;
argument2=0;
__asm__("":"=r"(argument0),"=r"(argument1),"=r"(argument2):"0"(argument0),"1"(argument1),"2"(argument2));
    resultWord=180;
Level12_C2B8Field(privateAddress,int*,0x70)=resultWord;
Level12_C2B8_func_8003BB10(argument0,argument1,argument2);
    goto originalBlock245;
originalDispatch4_selector5:
    temp_v1_27 = Level12_C2B8Field(privateAddress, int *, 0x9C) + 1;
    Level12_C2B8Field(privateAddress, int *, 0x9C) = temp_v1_27;
    if (temp_v1_27 >= 0x23) {
        goto originalBlock241;
    }
    Level12_C2B8_D_8006C7C0 = (int) Level12_C2B8Field(Level12_C2B8Field(privateAddress, int *, 0x98) + temp_v1_27,unsigned char*,0);
originalBlock241:
    var_a0_7 = privateAddress + 0x70;
    if (Level12_C2B8_D_8006C7C0 != 0xFF) {
        goto originalBlock243;
    }
    Level12_C2B8Field(savedWord16, signed char *, 0x49) = 1;
originalBlock243:
    argument1=4;
Level12_C2B8Keep(argument1);
originalBlock244:
    if (Level12_C2B8_func_800359A4(var_a0_7,argument1) == 0) {
        goto originalBlock248;
    }
originalBlock245:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = (unsigned char) (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) + 1);
    goto originalBlock248;
originalDispatch4_selector6:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x70, 4) == 0) {
        goto originalBlock248;
    }
    Level12_C2B8_D_8006C7C0 = 0;
    Level12_C2B8_D_8006C7B4 |= 1;
    Level12_C2B8Field(privateAddress, unsigned char *, 5) = 2U;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0U;
    Level12_C2B8_func_80013B7C(1);
    return;
originalBlock248:
originalBlock249:
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 0) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) >= 8U) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 2) {
        goto originalBlock253;
    }
    nativeFrame.sp78 = Level12_C2B8Field(Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC), int *, 0x18);
originalBlock253:
    if ((unsigned char) Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) < 2U) {
        goto originalBlock255;
    }
    Level12_C2B8Field(privateAddress, int *, 0x74) = (int) (Level12_C2B8Field(privateAddress, int *, 0x74) + 0x32);
originalBlock255:
    Level12_C2B8Field(privateAddress, int *, 0x6C) = (int) (Level12_C2B8Field(privateAddress, int *, 0x6C) + 8);
    Level12_C2B8_func_8004F178(&nativeFrame.sp60, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC) + 0x10);
    resultWord=Level12_C2B8_func_8004EA2C(Level12_C2B8Field(privateAddress,int*,0x6C));
workWord=Level12_C2B8Field(privateAddress,int*,0x74);
    tailProduct27.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct27.full):"0"(tailProduct27.full));
    resultWord=nativeFrame.sp60;
    __asm__("":"=x"(tailProduct27.full):"0"(tailProduct27.full),"r"(resultWord));
productWord=(int)tailProduct27.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
nativeFrame.sp60=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(Level12_C2B8Field(privateAddress,int*,0x6C));
workWord=Level12_C2B8Field(privateAddress,int*,0x74);
    tailProduct28.full=(long long)resultWord*(long long)workWord;
__asm__("":"=x"(tailProduct28.full):"0"(tailProduct28.full));
    resultWord=nativeFrame.sp64;
    __asm__("":"=x"(tailProduct28.full):"0"(tailProduct28.full),"r"(resultWord));
productWord=(int)tailProduct28.words.low;
Level12_C2B8Keep(productWord);
    workWord=productWord>>12;
resultWord+=workWord;
nativeFrame.sp64=resultWord;
    nativeFrame.sp68 = Level12_C2B8Field(Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x68), int*, 0xC), int *, 8);
    Level12_C2B8_func_80013AE4(&nativeFrame.sp60, &nativeFrame.sp70);
    goto originalBlock314;
originalDispatch1_selector5:
    resultWord = Level12_C2B8_D_8006C770;
    goto originalBlock293;
originalDispatch1_selector2:
    if (Level12_C2B8_D_8006E344 == 1) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(privateAddress, unsigned char *, 0) != 3) {
        goto originalBlock294;
    }
    temp_v0_22 = Level12_C2B8Field(privateAddress, unsigned char *, 4);
    if (temp_v0_22 != 0) {
        goto originalBlock261;
    }
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0x3CU;
    return;
originalBlock261:
    if (temp_v0_22 != 1) {
        goto originalBlock294;
    }
    Level12_C2B8_func_80034F40(ownerAddress, 0);
    Level12_C2B8Field(privateAddress, int *, 0x64) = 0x3C;
    __asm__ volatile("":::"$2","memory");
resultWord = 0x1E;
originalBlock263:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 0U;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = resultWord;
    return;
originalDispatch1_selector10:
    savedWord17=(int)&Level12_C2B8_D_80070328;
Level12_C2B8Keep(savedWord17);
argument0=savedWord17;
argument1=privateAddress+0x40;
argument2=0;
    resultWord=Level12_C2B8Field(privateAddress,int*,0x34);
argument3=0;
workWord=resultWord*11;
Level12_C2B8Keep(workWord);
resultWord=Level12_C2B8_D_8006C550;
__asm__("":"=r"(workWord):"0"(workWord):"memory");
workWord<<=3;
    __asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1),"r"(argument2),"r"(argument3));
savedWord16=resultWord+workWord;
    resultWord=Level12_C2B8_func_80036220(argument0,argument1,argument2,argument3);
Level12_C2B8Keep(privateAddress);
argument0=privateAddress+0xE0;
if(resultWord)goto originalBlock267;
    resultWord=Level12_C2B8_func_8004F334(ownerAddress+12,savedWord17);
resultWord=resultWord<8192;
Level12_C2B8Keep(privateAddress);
argument0=privateAddress+0xE0;
if(resultWord)goto originalBlock267;
    resultWord=Level12_C2B8Field(privateAddress,int*,0xE0);
    if(resultWord==0?(resultWord=1,1):(resultWord=1,0))goto originalBlock270;
    __asm__ volatile("":"=r"(resultWord):"0"(resultWord));
originalBlock267:
    argument1=4;
argument2=(int)&Level12_C2B8_D_8006C7F8;
__asm__ volatile("":::"$2","memory");
resultWord=1;
Level12_C2B8Field(privateAddress,int*,0xE0)=resultWord;
    Level12_C2B8_func_8003B7B4(argument0,argument1,argument2);
    Level12_C2B8Field(savedWord16, signed char *, 0x49) = 1;
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) == 4) {
        goto originalBlock269;
    }
    Level12_C2B8_D_8006C770 = 0;
    Level12_C2B8Field(ownerAddress, signed char *, 0x40) = 0x72;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) = 4U;
    Level12_C2B8Field(ownerAddress, signed char *, 0x3F) = 0;
    Level12_C2B8_func_80035734(ownerAddress);
originalBlock269:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0xBU;
    return;
originalBlock270:
    Level12_C2B8Keep(resultWord);
workWord=Level12_C2B8Field(privateAddress,short*,0x3C);
    if(workWord==resultWord?(resultWord=workWord<2,1):(resultWord=workWord<2,0))goto originalBlock280;
    if(!resultWord)goto originalBlock274;
    __asm__ volatile("":::"$6","memory");
argument2=0;
if(workWord==0)goto originalBlock276;
goto originalBlock314;
originalBlock274:
    resultWord=2;
if(workWord==resultWord)goto originalBlock284;
goto originalBlock314;
originalBlock276:
    Level12_C2B8_func_8003585C(ownerAddress, Level12_C2B8_func_8004E880(Level12_C2B8Field(savedWord16, int *, 0xC) - Level12_C2B8Field(ownerAddress, int *, 0xC), Level12_C2B8Field(savedWord16, int *, 0x10) - Level12_C2B8Field(ownerAddress, int *, 0x10), 0), 5, 1, 0, 0);
    Level12_C2B8_func_80035DDC(ownerAddress, 0x5A, 0, 0, 5);
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) == 0) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) == 3) {
        goto originalBlock279;
    }
    Level12_C2B8_D_8006C770 = 0;
    Level12_C2B8Field(ownerAddress, signed char *, 0x40) = 0x72;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) = 3U;
    Level12_C2B8Field(ownerAddress, signed char *, 0x3F) = 0;
    Level12_C2B8_func_80035734(ownerAddress);
originalBlock279:
    Level12_C2B8Field(privateAddress, short *, 0x3C) = (short) ((unsigned short) Level12_C2B8Field(privateAddress, short *, 0x3C) + 1);
    goto originalBlock314;
originalBlock280:
    Level12_C2B8_func_80035EE0(ownerAddress, Level12_C2B8Field(savedWord16, unsigned char *, 0x46), 0xAA, 0, 0, 5);
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) != 0) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) == 0) {
        goto originalBlock283;
    }
    Level12_C2B8_D_8006C770 = 0;
    Level12_C2B8Field(ownerAddress, signed char *, 0x40) = 0x72;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) = 0U;
    Level12_C2B8Field(ownerAddress, signed char *, 0x3F) = 0;
    Level12_C2B8_func_80035734(ownerAddress);
originalBlock283:
    Level12_C2B8Field(privateAddress, short *, 0x3E) = Level12_C2B8_func_8003636C(0x28, 0x5A);
    Level12_C2B8Field(privateAddress, short *, 0x3C) = (short) ((unsigned short) Level12_C2B8Field(privateAddress, short *, 0x3C) + 1);
    goto originalBlock314;
originalBlock284:
    argument0=privateAddress+0x3E;
Level12_C2B8Keep(argument0);
__asm__ volatile("":::"$2","$3","memory");
argument1=2;
    if (Level12_C2B8_func_800359A4(argument0,argument1) == 0) {
        goto originalBlock314;
    }
    if (Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) == 4) {
        goto originalBlock287;
    }
    Level12_C2B8_D_8006C770 = 0;
    Level12_C2B8Field(ownerAddress, signed char *, 0x40) = 0x72;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x3D) = 4U;
    Level12_C2B8Field(ownerAddress, signed char *, 0x3F) = 0;
    Level12_C2B8_func_80035734(ownerAddress);
originalBlock287:
    Level12_C2B8Field(privateAddress, short *, 0x3C) = 0;
    goto originalBlock314;
originalDispatch1_selector11:
    temp_v0_23 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x58), int*, 0xC);
    if (Level12_C2B8_func_8003585C(ownerAddress, Level12_C2B8_func_8004E880(Level12_C2B8Field(temp_v0_23, int *, 0) - Level12_C2B8Field(ownerAddress, int *, 0xC), Level12_C2B8Field(temp_v0_23, int *, 4) - Level12_C2B8Field(ownerAddress, int *, 0x10), 0), 5, 0x14, 1, 0) == 0) {
        goto originalBlock314;
    }
    if (Level12_C2B8_func_8004F334(ownerAddress + 0xC, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x58), int*, 0xC)) >= 0x200) {
        goto originalBlock291;
    }
    Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x58), short *, 2) = 1;
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0xCU;
    return;
originalBlock291:
    Level12_C2B8_func_80035DDC(ownerAddress, 0x78, 0, 0, 5);
    goto originalBlock314;
originalDispatch1_selector12:
    temp_v1_29 = Level12_C2B8Field(privateAddress, int*, 0x58);
    temp_v0_24 = (Level12_C2B8Field(temp_v1_29, short *, 2) * 0x10) + Level12_C2B8Field(temp_v1_29, int*, 0xC);
    resultWord = Level12_C2B8_func_8003585C(ownerAddress, Level12_C2B8_func_8004E880(Level12_C2B8Field(temp_v0_24, int *, 0) - Level12_C2B8Field(ownerAddress, int *, 0xC), Level12_C2B8Field(temp_v0_24, int *, 4) - Level12_C2B8Field(ownerAddress, int *, 0x10), 0), 5, 4, 1, 0);
originalBlock293:
    if (resultWord == 0) {
        goto originalBlock314;
    }
originalBlock294:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0U;
    Level12_C2B8_func_80034F40(ownerAddress, 0);
    goto originalBlock314;
originalDispatch1_selector30:
    if (Level12_C2B8_func_800359A4(privateAddress + 0x64, 4) == 0) {
        goto originalBlock310;
    }
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0x1FU;
    goto originalBlock310;
originalDispatch1_selector31:
    temp_v1_30 = Level12_C2B8Field(ownerAddress, unsigned char *, 0x49);
    savedWord18 = Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0x58), short *, 2);
    if (temp_v1_30 == 0) {
        goto originalBlock300;
    }
    if (temp_v1_30 == 1) {
        goto originalBlock305;
    }
    goto originalBlock311;
originalBlock300:
    if (!(Level12_C2B8_func_80035A80(ownerAddress, Level12_C2B8Field(privateAddress, int*, 0x58), 0x200, 0x80, 0, 4, 0x40, 5) & 1)) {
        goto originalBlock310;
    }
    temp_a1_5 = Level12_C2B8Field(privateAddress, int*, 0x58);
    temp_a2_4 = Level12_C2B8Field(temp_a1_5, short *, 2);
    if (temp_a2_4 != 0) {
        goto originalBlock303;
    }
originalBlock302:
    Level12_C2B8_func_80055B18(ownerAddress);
    return;
originalBlock303:
    temp_v1_31 = Level12_C2B8Field(temp_a1_5, int*, 0xC);
    if (!(Level12_C2B8Field(((savedWord18 * 0x10) + temp_v1_31), int *, 0xC) & 1)) {
        goto originalBlock310;
    }
    Level12_C2B8Field(privateAddress, int *, 0x64) = Level12_C2B8_func_800365E4(ownerAddress + 0xC, temp_v1_31 + (temp_a2_4 * 0x10), 0x80, -0xC, 0);
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x49) = 1U;
    goto originalBlock310;
originalBlock305:
    resultWord=Level12_C2B8_func_80035A80(ownerAddress,Level12_C2B8Field(privateAddress,int*,0x58),0x200,0x80,0,4,12,0);
    argument0=(int)&nativeFrame.spA0;
Level12_C2B8Keep(argument0);
__asm__ volatile("":::"$17","memory");
savedWord17=ownerAddress+12;
    argument2=Level12_C2B8Field(privateAddress,int*,0x64);
argument1=savedWord17;
argument2-=12;
Level12_C2B8Field(privateAddress,int*,0x64)=argument2;
    workWord=Level12_C2B8Field(ownerAddress,int*,0x14);
    __asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1),"r"(argument2):"memory");
savedWord16=resultWord;
    workWord+=argument2;
Level12_C2B8Field(ownerAddress,int*,0x14)=workWord;
Level12_C2B8_func_8004F178(argument0,argument1);
    resultWord=nativeFrame.spA8;
resultWord+=512;
nativeFrame.spA8=resultWord;
resultWord=savedWord16&1;
Level12_C2B8Keep(resultWord);
    if (!resultWord) {
        goto originalBlock310;
    }
    temp_a1_6 = Level12_C2B8Field(privateAddress, int*, 0x58);
    temp_a2_6 = Level12_C2B8Field(temp_a1_6, short *, 2);
    if (temp_a2_6 != 0) {
        goto originalBlock308;
    }
originalBlock307:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = 0x3DU;
    return;
originalBlock308:
    temp_v1_32 = Level12_C2B8Field(temp_a1_6, int*, 0xC);
    if (!(Level12_C2B8Field(((savedWord18 * 0x10) + temp_v1_32), int *, 0xC) & 1)) {
        goto originalBlock310;
    }
    Level12_C2B8Field(privateAddress, int *, 0x64) = Level12_C2B8_func_800365E4(savedWord17, temp_v1_32 + (temp_a2_6 * 0x10), 0x80, -0xC, 0);
originalBlock310:
originalBlock311:
    Level12_C2B8Field((int)&Level12_C2B8_D_80070328, int *, 0x20C) = 0x10000002;
    Level12_C2B8_func_800492DC(ownerAddress + 0xC);
    goto originalBlock314;
originalDispatch1_selector61:
    resultWord=1;
Level12_C2B8Keep(resultWord);
Level12_C2B8Field(privateAddress,int*,0xD4)=resultWord;
__asm__ volatile("":::"$2","memory");
    resultWord=255;
Level12_C2B8Keep(resultWord);
Level12_C2B8Field(ownerAddress,unsigned char*,0x4A)=resultWord;
    __asm__ volatile("":::"$2","memory");
resultWord = 0x3E;
    Level12_C2B8Field(ownerAddress, signed char *, 0x41) = 0;
    Level12_C2B8Field(ownerAddress, signed char *, 0x4C) = 0;
    Level12_C2B8Field(ownerAddress, signed char *, 0x4D) = 0;
    Level12_C2B8Field(ownerAddress, int *, 8) = 0;
originalBlock313:
    Level12_C2B8Field(ownerAddress, unsigned char *, 0x48) = resultWord;
originalDispatch1_selector1:
originalDispatch1_selector3:
originalDispatch1_selector4:
originalDispatch1_selector6:
originalDispatch1_selector7:
originalDispatch1_selector8:
originalDispatch1_selector9:
originalDispatch1_selector13:
originalDispatch1_selector14:
originalDispatch1_selector15:
originalDispatch1_selector16:
originalDispatch1_selector17:
originalDispatch1_selector18:
originalDispatch1_selector19:
originalDispatch1_selector20:
originalDispatch1_selector21:
originalDispatch1_selector22:
originalDispatch1_selector23:
originalDispatch1_selector24:
originalDispatch1_selector25:
originalDispatch1_selector26:
originalDispatch1_selector27:
originalDispatch1_selector28:
originalDispatch1_selector29:
originalDispatch1_selector32:
originalDispatch1_selector33:
originalDispatch1_selector34:
originalDispatch1_selector35:
originalDispatch1_selector36:
originalDispatch1_selector37:
originalDispatch1_selector38:
originalDispatch1_selector39:
originalDispatch1_selector41:
originalDispatch1_selector42:
originalDispatch1_selector43:
originalDispatch1_selector44:
originalDispatch1_selector45:
originalDispatch1_selector46:
originalDispatch1_selector47:
originalDispatch1_selector48:
originalDispatch1_selector49:
originalDispatch1_selector51:
originalDispatch1_selector52:
originalDispatch1_selector53:
originalDispatch1_selector54:
originalDispatch1_selector55:
originalDispatch1_selector56:
originalDispatch1_selector57:
originalDispatch1_selector58:
originalDispatch1_selector59:
originalBlock314:
    if (Level12_C2B8Field(privateAddress, int *, 0xD4) == 0) {
        goto originalBlock345;
    }
    nativeFrame.spE0=0;
workWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x48);
resultWord=62;
    if(workWord!=resultWord)goto originalBlock319;
    argument2=0;
Level12_C2B8Keep(argument2);
savedWord16=(int)&Level12_C2B8_D_8006E020;
Level12_C2B8Keep(savedWord16);
    resultWord=Level12_C2B8Field(privateAddress,int*,0xA0);
argument0=Level12_C2B8Field(savedWord16,int*,0);
resultWord=Level12_C2B8Field(resultWord,int*,12);
    argument1=Level12_C2B8_D_8006E024;
workWord=Level12_C2B8Field(resultWord,int*,0);
resultWord=Level12_C2B8Field(resultWord,int*,4);
argument0=workWord-argument0;
argument1=resultWord-argument1;
    resultWord=Level12_C2B8_func_8004E880(argument0,argument1,argument2);
workWord=Level12_C2B8Field(privateAddress,int*,0xA0);
argument0=savedWord16;
    argument1=Level12_C2B8Field(workWord,int*,12);
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004F334(argument0,argument1);
workWord=Level12_C2B8Field(privateAddress,int*,0xA0);
__asm__ volatile("":::"$6","memory");
argument2=0;
nativeFrame.spE0=resultWord;
__asm__ volatile("":::"$4","memory");
    resultWord=Level12_C2B8Field(workWord,int*,12);
argument1=Level12_C2B8_D_8006E028;
resultWord=Level12_C2B8Field(resultWord,int*,8);
argument0=nativeFrame.spE0;
argument1=resultWord-argument1;
    savedWord17=-Level12_C2B8_func_8004E880(argument0,argument1,argument2);
    argument1=Level12_C2B8_D_8006E040;
argument0=savedWord16&255;
argument1=(int)((unsigned int)argument1<<16)>>20;
    resultWord=Level12_C2B8_func_8004F264(argument0,argument1);
resultWord=resultWord<37;
if(!resultWord)goto originalBlock345;
    resultWord=Level12_C2B8_D_8006E03E;
resultWord=(unsigned int)resultWord<<16;
argument1=resultWord>>20;
    resultWord=argument1-127;
resultWord=(unsigned int)resultWord<114U;
    if(resultWord)goto originalBlock319;
    resultWord=Level12_C2B8_func_8004F264(savedWord17&255,argument1);
resultWord=resultWord<33;
    if(!resultWord)goto originalBlock345;
originalBlock319:
    savedWord23=(int)&nativeFrame.sp90;
Level12_C2B8Keep(savedWord23);
    __asm__ volatile("":::"$11","memory");
productWord=(int)&nativeFrame.spB0;
Level12_C2B8Keep(productWord);
    nativeFrame.spE8=0;
nativeFrame.spF0=productWord;
nativeFrame.sp128=privateAddress;
originalLoop320:
    productWord=nativeFrame.spE8;
argument1=4;
argument0=productWord<<2;
argument0+=0xB0;
argument0=privateAddress+argument0;
    if(!Level12_C2B8_func_800359A4(argument0,argument1))goto originalBlock334;
    savedWord16 = Level12_C2B8_SpawnMoby(0x287, ownerAddress);
Level12_C2B8Keep(savedWord16);
    if (savedWord16 == 0) {
        goto originalBlock334;
    }
    argument2=0;
resultWord=Level12_C2B8Field(privateAddress,int*,0xA0);
productWord=nativeFrame.spE8;
savedWord17=Level12_C2B8Field(savedWord16,int*,0);
    resultWord=Level12_C2B8Field(resultWord,int*,12);
temp_fp=productWord<<4;
workWord=temp_fp+resultWord;
Level12_C2B8Keep(temp_fp);
    argument3=Level12_C2B8Field(workWord,int*,0);
argument0=Level12_C2B8Field(resultWord,int*,0);
    workWord=Level12_C2B8Field(workWord,int*,4);
argument1=Level12_C2B8Field(resultWord,int*,4);
argument0=argument3-argument0;
argument1=workWord-argument1;
    savedWord20=Level12_C2B8_func_8004E880(argument0,argument1,argument2);
    resultWord=Level12_C2B8_func_8003636C(25,30);
__asm__ volatile("":::"$4","memory");
argument0=0;
__asm__ volatile("":::"$5","memory");
argument1=2;
    __asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord21=resultWord;
    resultWord=Level12_C2B8_func_8003636C(argument0,argument1);
savedWord18=resultWord;
Level12_C2B8Keep(savedWord18);
    workWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x48);
resultWord=60;
    if(workWord!=resultWord?(resultWord=255,1):(resultWord=255,0))goto originalBlock324;
    Level12_C2B8_func_8003BB10(savedWord16,8,1);
resultWord=255;
originalBlock324:
    Level12_C2B8Keep(resultWord);
Level12_C2B8Field(savedWord16,unsigned char*,0x4A)=resultWord;
    resultWord=Level12_C2B8_rand();
Level12_C2B8Field(savedWord16,unsigned char*,0x46)=resultWord;
    productWord=nativeFrame.spE8;
Level12_C2B8Keep(productWord);
if(productWord)goto originalBlock326;
    savedWord20=Level12_C2B8_rand();
originalBlock326:
    Level12_C2B8_func_8004F178(savedWord16 + 0xC, Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xA0), int*, 0xC) + temp_fp);
    resultWord=127;
Level12_C2B8Keep(resultWord);
workWord=(savedWord20&255)<<1;
Level12_C2B8Field(savedWord16,unsigned char*,0x4F)=resultWord;
    resultWord=Level12_C2B8Field((int)&Level12_C2B8_D_80065920,short*,workWord);
    tailProduct33.full=(long long)resultWord*(long long)savedWord21;
__asm__("":"=x"(tailProduct33.full):"0"(tailProduct33.full));
    __asm__("":"=x"(tailProduct33.full):"0"(tailProduct33.full));
productWord=(int)tailProduct33.words.low;
Level12_C2B8Keep(productWord);
    resultWord=productWord>>12;
Level12_C2B8Field(savedWord17,int*,0)=resultWord;
    resultWord=Level12_C2B8Field((int)&Level12_C2B8_D_800658A0,short*,workWord);
    tailProduct34.full=(long long)resultWord*(long long)savedWord21;
__asm__("":"=x"(tailProduct34.full):"0"(tailProduct34.full));
    __asm__ volatile("":::"$4","memory");
argument0=30;
__asm__ volatile("":::"$5","memory");
argument1=35;
Level12_C2B8Field(savedWord17,int*,8)=0;
    __asm__("":"=x"(tailProduct34.full):"0"(tailProduct34.full),"r"(argument0),"r"(argument1):"memory");
productWord=(int)tailProduct34.words.low;
Level12_C2B8Keep(productWord);
    resultWord=productWord>>12;
Level12_C2B8Field(savedWord17,int*,4)=resultWord;
    Level12_C2B8Field(savedWord17, int *, 8) = Level12_C2B8_func_8003636C(argument0,argument1);
    Level12_C2B8Field(savedWord17, int *, 0xC) = 0x190;
    resultWord=Level12_C2B8Field(savedWord16,unsigned char*,0x3C);
    if(resultWord==savedWord18?(resultWord=90,1):(resultWord=90,0))goto originalBlock328;
    resultWord=Level12_C2B8Field(savedWord16,short*,0x36);
Level12_C2B8Field(savedWord16,unsigned char*,0x42)=0;
resultWord<<=2;
    workWord=Level12_C2B8Field((int)&Level12_C2B8_D_8006EE2C,int*,resultWord);
resultWord=savedWord18<<2;
resultWord+=workWord;
    resultWord=Level12_C2B8Field(resultWord,int*,0x3C);
resultWord=Level12_C2B8Field(resultWord,unsigned char*,0);
workWord=1;
    Level12_C2B8Field(savedWord16,unsigned char*,0x3C)=savedWord18;
Level12_C2B8Field(savedWord16,unsigned char*,0x3D)=savedWord18;
    Level12_C2B8Field(savedWord16,unsigned char*,0x3E)=0;
Level12_C2B8Field(savedWord16,unsigned char*,0x3F)=workWord;
    resultWord=(unsigned int)resultWord<2U;
resultWord^=1;
resultWord=-resultWord;
resultWord&=48;
Level12_C2B8Field(savedWord16,unsigned char*,0x40)=resultWord;
resultWord=90;
originalBlock328:
    Level12_C2B8Keep(resultWord);
Level12_C2B8Field(savedWord16,unsigned char*,0x4C)=resultWord;
Level12_C2B8Field(savedWord16,unsigned char*,0x4E)=resultWord;
    workWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x48);
__asm__ volatile("":::"$2","memory");
resultWord=62;
argument0=150;
if(workWord==resultWord)goto originalBlock330;
    argument1=220;
goto originalBlock331;
originalBlock330:
    argument0=600;
argument1=1200;
originalBlock331:
    resultWord=Level12_C2B8_func_8003636C(argument0,argument1);
productWord=nativeFrame.sp128;
Level12_C2B8Keep(productWord);
Level12_C2B8Field(productWord,int*,0xB0)=resultWord;
    workWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x48);
resultWord=62;
if(workWord==resultWord)goto originalBlock334;
    __asm__ volatile("":::"$21","memory");
savedWord21=115;
Level12_C2B8Keep(savedWord21);
tail150=150;
Level12_C2B8Keep(tail150);
__asm__ volatile("":::"$20","memory");
savedWord20=0;
originalLoop333:
    resultWord=Level12_C2B8_rand();
__asm__ volatile("":::"$4","memory");
argument0=800;
__asm__ volatile("":::"$5","memory");
argument1=2048;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord18=resultWord&4095;
    resultWord=Level12_C2B8_func_8003636C(argument0,argument1);
savedWord17=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(savedWord17);
argument0=savedWord18;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(argument0);
    tailProduct1.full=(long long)resultWord*(long long)savedWord21;
__asm__("":"=x"(tailProduct1.full):"0"(tailProduct1.full));
    productWord=(int)tailProduct1.words.low;
Level12_C2B8Keep(productWord);
__asm__("":"=r"(savedWord16):"0"(savedWord16),"r"(productWord));
savedWord16>>=6;
    tailProduct2.full=(long long)savedWord16*(long long)productWord;
__asm__("":"=x"(tailProduct2.full):"0"(tailProduct2.full));
    argument0=savedWord17;
productWord=(int)tailProduct2.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>18;
nativeFrame.spB0=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(argument0);
argument0=savedWord18;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
    tailProduct3.full=(long long)resultWord*(long long)savedWord21;
__asm__("":"=x"(tailProduct3.full):"0"(tailProduct3.full));
    productWord=(int)tailProduct3.words.low;
Level12_C2B8Keep(productWord);
__asm__("":"=r"(savedWord16):"0"(savedWord16),"r"(productWord));
savedWord16>>=6;
    tailProduct4.full=(long long)savedWord16*(long long)productWord;
__asm__("":"=x"(tailProduct4.full):"0"(tailProduct4.full));
    argument0=savedWord17;
productWord=(int)tailProduct4.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>18;
nativeFrame.spB4=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
    tailProduct5.full=(long long)resultWord*(long long)tail150;
__asm__("":"=x"(tailProduct5.full):"0"(tailProduct5.full));
    argument0=savedWord23;
argument1=nativeFrame.spF0;
__asm__("":"=x"(tailProduct5.full):"0"(tailProduct5.full),"r"(argument0),"r"(argument1));
productWord=(int)tailProduct5.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>12;
nativeFrame.spB8=resultWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
Level12_C2B8_func_8004F0E8(savedWord23,1);
    argument0=savedWord23;
argument1=savedWord23;
resultWord=Level12_C2B8Field(privateAddress,int*,0xA0);
workWord=savedWord20<<4;
    argument2=Level12_C2B8Field(resultWord,int*,12);
savedWord20++;
    Level12_C2B8_func_8004F194(argument0,argument1,argument2+workWord);
    __asm__ volatile("":::"$4","memory");
argument0=1;
__asm__ volatile("":::"$5","memory");
argument1=0;
__asm__("":"=r"(argument0),"=r"(argument1):"0"(argument0),"1"(argument1):"memory");
resultWord=(int)Level12_C2B8_SpawnParticle;
    __asm__("":"=r"(resultWord):"0"(resultWord):"memory");
argument3=nativeFrame.spF0;
    ((void(*)(int,int,int,int))resultWord)(argument0,argument1,savedWord23,argument3);
    resultWord=savedWord20<30;
if(resultWord)goto originalLoop333;
originalBlock334:
    productWord=nativeFrame.sp128;
productWord+=4;
nativeFrame.sp128=productWord;
    productWord=nativeFrame.spE8;
productWord++;
resultWord=productWord<9;
nativeFrame.spE8=productWord;
if(resultWord)goto originalLoop320;
    productWord=nativeFrame.spE0;
resultWord=0x87FF;
resultWord=resultWord<productWord;
if(resultWord)goto originalBlock345;
    __asm__ volatile("":::"$2","memory");
resultWord=Level12_C2B8Field(privateAddress,int*,0xA0);
resultWord=Level12_C2B8Field(resultWord,short*,0);
savedWord23=0;
if(resultWord<=0)goto originalBlock345;
    savedWord20=(int)&nativeFrame.spA0;
Level12_C2B8Keep(savedWord20);
productWord=(int)&nativeFrame.spC0;
Level12_C2B8Keep(productWord);
nativeFrame.sp100=productWord;
originalLoop338:
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x48);
__asm__ volatile("":::"$11","memory");
productWord=41;
Level12_C2B8Keep(productWord);
nativeFrame.spF8=productWord;
    __asm__ volatile("":::"$11","memory");
productWord=62;
Level12_C2B8Keep(productWord);
var_fp=4;
if(resultWord!=productWord)goto originalBlock340;
    var_fp=1;
__asm__ volatile("":::"$11","memory");
productWord=56;
Level12_C2B8Keep(productWord);
nativeFrame.spF8=productWord;
originalBlock340:
    Level12_C2B8Keep(var_fp);
__asm__ volatile("":::"$21","memory");
savedWord21=0;
if(var_fp==0)goto originalBlock344;
originalLoop341:
    resultWord=Level12_C2B8_rand();
__asm__ volatile("":::"$4","memory");
argument0=800;
__asm__ volatile("":::"$5","memory");
argument1=2048;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0),"r"(argument1));
savedWord18=resultWord&4095;
    resultWord=Level12_C2B8_func_8003636C(argument0,argument1);
savedWord17=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(savedWord17);
argument0=savedWord18;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(argument0);
    __asm__ volatile("":::"$11","memory");
productWord=27;
Level12_C2B8Keep(productWord);
tailProduct6.full=(long long)resultWord*(long long)productWord;
__asm__("":"=x"(tailProduct6.full):"0"(tailProduct6.full));
    productWord=(int)tailProduct6.words.low;
Level12_C2B8Keep(productWord);
__asm__("":"=r"(savedWord16):"0"(savedWord16),"r"(productWord));
savedWord16>>=6;
    tailProduct7.full=(long long)savedWord16*(long long)productWord;
__asm__("":"=x"(tailProduct7.full):"0"(tailProduct7.full));
    argument0=savedWord17;
productWord=(int)tailProduct7.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>18;
nativeFrame.spC0=resultWord;
    resultWord=Level12_C2B8_func_8004EA2C(argument0);
argument0=savedWord18;
__asm__("":"=r"(resultWord):"0"(resultWord),"r"(argument0));
savedWord16=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
    __asm__ volatile("":::"$11","memory");
productWord=27;
Level12_C2B8Keep(productWord);
tailProduct8.full=(long long)resultWord*(long long)productWord;
__asm__("":"=x"(tailProduct8.full):"0"(tailProduct8.full));
    productWord=(int)tailProduct8.words.low;
Level12_C2B8Keep(productWord);
__asm__("":"=r"(savedWord16):"0"(savedWord16),"r"(productWord));
savedWord16>>=6;
    tailProduct9.full=(long long)savedWord16*(long long)productWord;
__asm__("":"=x"(tailProduct9.full):"0"(tailProduct9.full));
    argument0=savedWord17;
productWord=(int)tailProduct9.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>18;
nativeFrame.spC4=resultWord;
    resultWord=Level12_C2B8_func_8004E9E4(argument0);
    productWord=nativeFrame.spF8;
Level12_C2B8Keep(productWord);
tailProduct10.full=(long long)resultWord*(long long)productWord;
__asm__("":"=x"(tailProduct10.full):"0"(tailProduct10.full));
    argument0=savedWord20;
argument1=nativeFrame.sp100;
__asm__("":"=x"(tailProduct10.full):"0"(tailProduct10.full),"r"(argument0),"r"(argument1));
productWord=(int)tailProduct10.words.low;
Level12_C2B8Keep(productWord);
resultWord=productWord>>12;
nativeFrame.spC8=resultWord;
    Level12_C2B8_func_8004F178(argument0,argument1);
Level12_C2B8_func_8004F0E8(savedWord20,1);
    argument0=savedWord20;
resultWord=Level12_C2B8Field(privateAddress,int*,0xA0);
argument1=savedWord20;
resultWord=Level12_C2B8Field(resultWord,int*,12);
argument2=savedWord23<<4;
    Level12_C2B8_func_8004F194(argument0,argument1,resultWord+argument2);
    resultWord=Level12_C2B8Field(ownerAddress,unsigned char*,0x48);
__asm__ volatile("":::"$11","memory");
productWord=62;
__asm__ volatile("":::"$4","memory");
argument0=1;
    if(resultWord==productWord){resultWord=nativeFrame.spA8;
resultWord+=200;
nativeFrame.spA8=resultWord;
}
originalBlock343:
    __asm__ volatile("":::"$5","memory");
argument1=0;
argument2=savedWord20;
argument3=nativeFrame.sp100;
__asm__("":"=r"(argument1),"=r"(argument2),"=r"(argument3):"0"(argument1),"1"(argument2),"2"(argument3));
savedWord21++;
    Level12_C2B8_SpawnParticle(argument0,argument1,argument2,argument3);
    resultWord=savedWord21<var_fp;
if(resultWord)goto originalLoop341;
originalBlock344:
    savedWord23 += 1;
    if (savedWord23 < Level12_C2B8Field(Level12_C2B8Field(privateAddress, int*, 0xA0), short *, 0)) {
        goto originalLoop338;
    }
originalBlock345:
    return;
}
#undef Level12_C2B8Field
#undef Level12_C2B8Keep


extern int D_8006C770;
void func_80034F40(Moby*, int);
void func_level_12_8007F144(Moby* moby) {
    int animation;
    switch (moby->state) {
    case 0:
        if (!moby->substate) return;
        moby->state = 2;
        animation = 2;
        break;
    case 2:
        if (!D_8006C770) return;
        moby->state = 1;
        animation = 1;
        break;
    default: return;
    }
    func_80034F40(moby, animation);
}

typedef struct { int phaseOffset, firstSpan, secondSpan; } Controller7F1BCTag;
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
/* USA Rev 0, 0x8007F1BC..0x8007F578: 240 original instructions.
 * Reuses verified func_level_12_8008243C; omits its zero-span branch and
 * phase clamp because neither appears here. Units, producer/helper semantics
 * and caller cadence remain unresolved. Empty constraints contain no opcodes.
 * AI generated; not yet human reviewed. */
void func_level_12_8007F1BC(Moby* input) {
    register Moby* owner __asm__("$18") = input;
    Vector3D origin; int reserved1C;
    Vector3D target; int reserved2C;
    Vector3D particle; int reserved3C;
    Vector3D offset; int reserved4C;
    SHORTMATRIX matrix;
    register Controller7F1BCTag* tag __asm__("$19");
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
    if (owner->state == 2) {
        register int scaled __asm__("$2");
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

int rand(void);
void func_level_12_8007F57C(Moby* moby) {
    Vector3D origin, velocity, position;
    SHORTMATRIX matrix;
    Angle angle;
    int index;
    Moby* spawned;
    void* tag;
    func_8004F178(&origin, &moby->position);
    origin.z += 0x3E8;
    index = 0;
    do {
        angle.roll = 0;
        angle.pitch = func_800363DC(0, 0x1C) + 0x40;
        angle.yaw = rand();
        func_8004EA90(&angle, &matrix, 0);
        velocity.x = func_8003636C(0x28, 0x46);
        velocity.y = 0;
        velocity.z = 0;
        func_8004ED6C(&matrix, &velocity, &velocity);
        position.x = 0x384;
        position.y = 0;
        position.z = 0;
        func_8004ED6C(&matrix, &position, &position);
        func_8004F194(&position, &position, &origin);
        SpawnParticle(1, 0xD, &position, &velocity);
        index++;
    } while (index < 4);
    spawned = SpawnMoby(0x2C0, moby);
    if (spawned) {
        tag = spawned->mobyTag;
        func_8004F178(&spawned->position, &origin);
        func_8004F178(tag, &spawned->position);
        *(short*)((char*)tag + 0xE) = 0x384;
        *((char*)tag + 0x17) = 0xC;
        *((char*)tag + 0x16) = 0x1E;
        *(short*)((char*)tag + 0x14) = -7;
    }
}

void func_level_12_8007F6FC(Moby* moby) {
    int active;
    register unsigned int frames __asm__("$2");
    switch (moby->state) {
    case 0:
        active = 0;
        if (func_8004F334(&moby->position, (Vector3D*)&spyro) < 0x384)
            active = *(int*)((char*)&spyro + 0xB8) == 0;
        if (active) {
            func_8003BB10(moby, 5, 0);
            moby->state = 1;
            frames = D_8006EE2C[moby->mobyClass]->frames[1][0];
            moby->animationState.id = 1;
            moby->animationState.nextId = 1;
            goto animation;
        }
        break;
    case 1:
        active = 0;
        if (func_8004F334(&moby->position, (Vector3D*)&spyro) < 0x44C)
            active = *(int*)((char*)&spyro + 0xB8) == 0;
        if (!active) {
            moby->state = 0;
            frames = D_8006EE2C[moby->mobyClass]->frames[0][0];
            moby->animationState.id = 0;
            moby->animationState.nextId = 0;
animation:
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = 1;
            __asm__("" : : : "memory");
            frames = frames >= 2;
            __asm__("" : "=r"(frames) : "0"(frames));
            moby->animationProgress = -frames & 0x30;
        }
        break;
    }
}

extern int deltaTime;
void func_80055B18(Moby*);
void func_level_12_8007F844(Moby* moby) {
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
extern unsigned char Controller7C02CCounter2[] __asm__("D_800716AC + 0x2");
extern int Controller7C02CModeWord __asm__("D_8006C7C4");
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
void func_level_12_8007F91C(void *input) {
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
                { register int timerLiteral __asm__("$2")=8;
                  register int levelIndex __asm__("$3")=Controller7C02CD_8006C58C;
                  register int offsetWord __asm__("$2");
                  register int byteOffset __asm__("$4");
                  register unsigned int counter __asm__("$3");
                  Controller7C02CField(controller,int*,0x28)=timerLiteral;
                  offsetWord=levelIndex*3;
                  __asm__("" : "=r"(offsetWord) : "0"(offsetWord));
                  byteOffset=offsetWord<<1;
                  counter=Controller7C02CCounter2[byteOffset];
                  __asm__("" : "=r"(counter) : "0"(counter) : "$16");
                  eventSelector=0;
                  if(counter<255) {
                      register unsigned int nextCount __asm__("$2")=counter+1;
                      __asm__("" : "=r"(nextCount) : "0"(nextCount));
                      Controller7C02CCounter2[byteOffset]=nextCount;
                  }
                }
                { register int mode __asm__("$3")=Controller7C02CModeWord;
                  if(mode==2) Controller7C02CField(controller,int*,0)=0x3C0;
                  else if(mode==1) Controller7C02CField(controller,int*,0)=0x708;
                  else if(mode==0) Controller7C02CField(controller,int*,0)=0xE10;
                }
                __asm__ volatile("" : : : "memory");
                temp_v1_10 = Controller7C02CField(controller, unsigned int *, 8);
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
/* SCUS-94467 USA Rev0, original80080154.
* AI generated; not human reviewed. All715 instructions,five selectors and
* one zero pad require every native/linked word and actual target:721 words.
* Frame88 retains S0..S7/FP/RA and original SP20..5F workspace. The complete
* initialized helper flag allocates naturally to FP;no explicit FP binding.
* The signed/270 dividend is the old timer word at original297. The timer
* increments at304/305 independently;old269 with step1 yields timer270 and
* retained target250,not249. The ordinary whole quotient allocates to S4
* with original V0 intermediate words;no synthetic partial HI/LO values.
* Complete modulo operations retain all zero/signed overflow checks. The
* S0 path-index/descriptor/heading phases are disjoint;old pointer consumers
* finish before its new full heading producer. Height and path descriptors
* load after original callbacks. Independent LHU/LH counter producers remain.
* Original cleanup642 stays after all states. Distinct zero entries460/467/
* 476 and already-prepared477 preserve every actual branch destination.
* Original literal30 fills the complete remainder-result delay. Original
* caller A1 zero is produced independently after dead predicate/S0 phases.
* Empty metadata reads complete initialized words/addresses or clobbers
* only dead values before fresh full producers;zero CPU instructions.
* Compiler/filter/flags unchanged;no opcode asm,fixedFP,undefined saved
* inputs or overlapping live aliases. Known helper views reuse EXE/header
* evidence. Units/fixed point,complete helper/caller chains,cadence beyond
* invocation and synchronized retail runtime remain open. Confidence is
* binary identity after all gates. Next:human review and retail captures.
* Falsification:all native/linked words,actual destinations,owned data and
* full EXE/every-overlay retail hashes must remain identical.
*/
/* Original assembly SHA256 e02649356550b3a86374640c5497d6533cde445267057b47250d32ba2f2ddd90 */
#define Level12_80154Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level12_80154Call13D44View1() __asm__("func_80013D44");
int Level12_80154Call1A358View1() __asm__("func_8001A358");
int Level12_80154Call34F40View1() __asm__("func_80034F40");
int Level12_80154Call34F80View1() __asm__("func_80034F80");
int Level12_80154Call35194View1() __asm__("func_80035194");
int Level12_80154Call3573CView1() __asm__("func_8003573C");
int Level12_80154Call359A4View1(void*, int) __asm__("func_800359A4");
int Level12_80154Call35A80View1() __asm__("func_80035A80");
int Level12_80154Call35D38View1() __asm__("func_80035D38");
int Level12_80154Call3636CView1() __asm__("func_8003636C");
int Level12_80154Call369B8View1() __asm__("func_800369B8");
int Level12_80154Call37014View1() __asm__("func_80037014");
int Level12_80154Call37A60View1() __asm__("func_80037A60");
int Level12_80154Call38BF8View1() __asm__("func_80038BF8");
int Level12_80154Call3BA00View1() __asm__("func_8003BA00");
int Level12_80154Call3BABCView1() __asm__("func_8003BABC");
int Level12_80154Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level12_80154Call4F110View1() __asm__("func_8004F110");
int Level12_80154Call4F178View1() __asm__("func_8004F178");
int Level12_80154Call4F194View1() __asm__("func_8004F194");
int Level12_80154Call4F264View1(int, int) __asm__("func_8004F264");
int Level12_80154Call4F334View1() __asm__("func_8004F334");
int Level12_80154Call55B18View1() __asm__("func_80055B18");
int Level12_80154Call55D24View1() __asm__("func_80055D24");
int Level12_80154Call55F14View1() __asm__("func_80055F14");
extern int Level12_80154Data6C550View1 __asm__("D_8006C550");
extern int Level12_80154Data6C58CView1 __asm__("D_8006C58C");
extern int Level12_80154Data6C648View1 __asm__("D_8006C648");
extern int Level12_80154Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level12_80154Data6C7B4View1 __asm__("D_8006C7B4");
extern int Level12_80154Data6E048View1 __asm__("D_8006E048");
extern int Level12_80154Data70300View1 __asm__("D_80070300");
extern int Level12_80154Data70328View1 __asm__("D_80070328");
void func_level_12_80080154(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), retainedCoordinateWord8 __asm__("$8"), retainedOriginalDistance23 __asm__("$23");
    register void *ownerRecord19 __asm__("$19");
    register int privateRecord18 __asm__("$18"), retainedRemainderPointerHeadingOrFlag16 __asm__("$16"), retainedPlayerBaseHeightOrDistance17 __asm__("$17"), retainedQuotientOrHelperFlags, retainedLinkedRecord21 __asm__("$21"), retainedOriginalMotionFlags22 __asm__("$22");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C;
    }
    originalFrame;
    int temporaryWord10;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord3;
    int temporaryWord4;
    int retainedOriginalHelperFlag;
    int temporaryWord13;
    int temporaryWord8;
    int temporaryWord11;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord5;
    int temporaryWord9;
    int temporaryWord12;
    ownerRecord19 = ownerParameter;
    __asm__("":"=r"(ownerRecord19):"0"(ownerRecord19));
    privateRecord18 = Level12_80154Field(ownerRecord19, void **, 0);
    rawWord3 = Level12_80154Field(privateRecord18, int*, 16);
    argumentWord4 = Level12_80154Data6C550View1;
    rawWord2 = rawWord3*88;
    __asm__("":"=r"(rawWord2):"0"(rawWord2):"$3", "memory");
    rawWord3 = Level12_80154Field(ownerRecord19, unsigned char*, 72);
    rawWord3 -= 3;
    rawWord3 = (unsigned int)rawWord3 < 2U;
    __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(argumentWord4), "r"(rawWord2):"$21");
    retainedLinkedRecord21 = argumentWord4+rawWord2;
    if (!rawWord3 && Level12_80154Field(ownerRecord19, int*, 24)){
        Level12_80154Call38BF8View1(ownerRecord19, privateRecord18 + 0x24, 1, 3);
        Level12_80154Field(privateRecord18, signed char *, 0x37) = 0;
        Level12_80154Field(privateRecord18, unsigned short *, 0x30) = (unsigned short) (Level12_80154Field(privateRecord18, unsigned short *, 0x30) | 0x4000);
        Level12_80154Field(retainedLinkedRecord21, signed char *, 0x48) = 0;
        Level12_80154Call38BF8View1(retainedLinkedRecord21, privateRecord18 + 0x40, 1, 6);
        Level12_80154Call34F80View1(retainedLinkedRecord21, 0);
        Level12_80154Field(privateRecord18, short *, 0x4A) = 0xC8;
        Level12_80154Field(privateRecord18, signed char *, 0x4F) = 0x10;
        Level12_80154Field(privateRecord18, signed char *, 0x4E) = 0xC;
        Level12_80154Field(privateRecord18, unsigned short *, 0x4C) = 0xC001;
        Level12_80154Field(privateRecord18, signed char *, 0x53) = 0;
        Level12_80154Field(privateRecord18, short *, 0x44) = (short) (Level12_80154Field(privateRecord18, unsigned short *, 0x28) - 0x28);
    }
    temporaryWord8 = Level12_80154Field(ownerRecord19, unsigned char *, 0x48);
    switch (temporaryWord8) {
    case 0:
    case 1:
        temporaryWord11 = Level12_80154Field(ownerRecord19, unsigned char *, 0x49);
        switch (temporaryWord11) {
        case 0:
            if ((Level12_80154Data6C7B4View1 & 8) || (Level12_80154Field((int)&Level12_80154Data70300View1, unsigned char*, Level12_80154Data6C58CView1) & 8)) {
                temporaryWord1 = (Level12_80154Field(privateRecord18, int *, 0x10) * 0x58) + Level12_80154Data6C550View1;
                if (!(Level12_80154Field(temporaryWord1, unsigned char *, 0x48) & 0x80)) {
                    Level12_80154Call55B18View1(temporaryWord1);
                }
                Level12_80154Call55B18View1(ownerRecord19);
                __asm__ volatile(""::"r"(ownerRecord19));
                return;
            }
            argumentWord6 = 0x7FFFFFFF;
            argumentWord4 = 480;
            argumentWord5 = 1200;
            __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6):"memory");
            Level12_80154Field(ownerRecord19, unsigned char *, 0x55) = 0x80;
            Level12_80154Field(ownerRecord19, unsigned char *, 0x56) = 0xC0;
            Level12_80154Field(ownerRecord19, signed char *, 0x54) = 0;
            Level12_80154Field(ownerRecord19, signed char *, 0x57) = 0;
            Level12_80154Field(ownerRecord19, unsigned char *, 0x49) = 1U;
            rawWord2 = Level12_80154Field(retainedLinkedRecord21, int*, 28);
            rawWord3 = 6;
            Level12_80154Field(retainedLinkedRecord21, signed char*, 72) = rawWord3;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"memory");
            rawWord2 &= argumentWord6;
            Level12_80154Field(retainedLinkedRecord21, int*, 28) = rawWord2;
            Level12_80154Field(privateRecord18, short *, 0x5C) = Level12_80154Call3636CView1(argumentWord4, argumentWord5, argumentWord6);
            default:goto callOriginalLateCleanup642;
        case 1:
            retainedPlayerBaseHeightOrDistance17 = (int)&Level12_80154Data70328View1 + 0x98;
            Level12_80154Call4F178View1(&originalFrame.sp20, retainedPlayerBaseHeightOrDistance17);
            originalFrame.sp20 *= 0x14;
            originalFrame.sp24 *= 0x14;
            originalFrame.sp28 *= 0x14;
            Level12_80154Call4F110View1(&originalFrame.sp20, 6);
            Level12_80154Call4F194View1(&originalFrame.sp20, &originalFrame.sp20, retainedPlayerBaseHeightOrDistance17 - 0x98);
            if (Level12_80154Call4F334View1(ownerRecord19 + 0xC, &originalFrame.sp20) < 0x1C00) {
                rawWord3 = Level12_80154Field(privateRecord18, int*, 4);
                rawWord2 = Level12_80154Field(rawWord3, short*, 2);
                argumentWord4 = Level12_80154Field(rawWord3, short*, 10);
                rawWord3 = Level12_80154Field(rawWord3, short*, 0);
                rawWord2 += argumentWord4;
                rawWord2 += rawWord3;
                retainedRemainderPointerHeadingOrFlag16 = rawWord2%rawWord3;
                __asm__("":"=r"(retainedRemainderPointerHeadingOrFlag16):"0"(retainedRemainderPointerHeadingOrFlag16):"$4", "$5", "memory");
                argumentWord5 = Level12_80154Field(ownerRecord19, int*, 16);
                rawWord3 = Level12_80154Field(retainedPlayerBaseHeightOrDistance17, int*, -152);
                argumentWord4 = Level12_80154Field(ownerRecord19, int*, 12);
                rawWord2 = Level12_80154Field((int)&Level12_80154Data70328View1, int*, 4);
                argumentWord4 = rawWord3-argumentWord4;
                argumentWord5 = rawWord2-argumentWord5;
                rawWord2 = Level12_80154Call4E880View1(argumentWord4, argumentWord5, 0);
                rawWord3 = Level12_80154Field(privateRecord18, int*, 4);
                argumentWord4 = Level12_80154Field(rawWord3, int*, 12);
                rawWord3 = Level12_80154Field(rawWord3, short*, 2);
                __asm__ volatile("":::"$6", "memory");
                argumentWord6 = 0;
                __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(argumentWord6));
                rawWord3 *= 16;
                rawWord3 += argumentWord4;
                argumentWord5 = Level12_80154Field(rawWord3, int*, 4);
                __asm__("":"=r"(retainedRemainderPointerHeadingOrFlag16):"0"(retainedRemainderPointerHeadingOrFlag16):"memory");
                retainedRemainderPointerHeadingOrFlag16 *= 16;
                retainedRemainderPointerHeadingOrFlag16 += argumentWord4;
                retainedCoordinateWord8 = Level12_80154Field(retainedRemainderPointerHeadingOrFlag16, int*, 0);
                argumentWord4 = Level12_80154Field(rawWord3, int*, 0);
                __asm__("":"=r"(retainedCoordinateWord8):"0"(retainedCoordinateWord8):"memory");
                argumentWord7 = Level12_80154Field(retainedRemainderPointerHeadingOrFlag16, int*, 4);
                __asm__("":"=r"(rawWord2):"0"(rawWord2):"$16", "memory");
                retainedRemainderPointerHeadingOrFlag16 = rawWord2;
                argumentWord4 = retainedCoordinateWord8-argumentWord4;
                rawWord2 = Level12_80154Call4E880View1(argumentWord4, argumentWord7-argumentWord5, argumentWord6);
                rawWord2 = Level12_80154Call4F264View1(retainedRemainderPointerHeadingOrFlag16, rawWord2);
                argumentWord4 = (int)ownerRecord19;
                if (rawWord2 < 64){
                    temporaryWord12 = Level12_80154Field(privateRecord18, void **, 4);
                    Level12_80154Field(temporaryWord12, short *, 0xA) = (short) -(short) (unsigned short) Level12_80154Field(temporaryWord12, short *, 0xA);
                    argumentWord5 = Level12_80154Field(privateRecord18, int*, 4);
                    argumentWord4 = Level12_80154Field(argumentWord5, short*, 10);
                    __asm__ volatile("":::"$2", "memory");
                    rawWord2 = Level12_80154Field(argumentWord5, short*, 2);
                    rawWord3 = Level12_80154Field(argumentWord5, short*, 0);
                    argumentWord4 *= 2;
                    rawWord2 += argumentWord4;
                    rawWord2 += rawWord3;
                    rawWord3 = rawWord2%rawWord3;
                    rawWord2 = 30;
                    Level12_80154Field(argumentWord5, short*, 2) = rawWord3;
                    Level12_80154Field(privateRecord18, int*, 20) = rawWord2;
                    __asm__ volatile("":::"$4", "memory");
                    argumentWord4 = (int)ownerRecord19;
                }
                Level12_80154Field(privateRecord18, unsigned short *, 0x20) = 0x100U;
                Level12_80154Field(privateRecord18, unsigned char *, 0x23) = 0U;
                Level12_80154Call3BABCView1(argumentWord4, 0, 0);
                Level12_80154Field(ownerRecord19, unsigned char *, 0x48) = 2U;
                Level12_80154Call34F40View1(ownerRecord19, 2);
            }
            else {
                Level12_80154Call37A60View1(ownerRecord19, privateRecord18 + 0x1C, 4, 0x12, -0xC8);
                Level12_80154Call3573CView1(ownerRecord19, 8, 0, 1);
                if (Level12_80154Data6C770View1 != 0) {
                    if (Level12_80154Field(privateRecord18, int *, 0x14) == 0) {
                        Level12_80154Call34F40View1(ownerRecord19, 1);
                        Level12_80154Field(privateRecord18, int *, 0x14) = Level12_80154Call3636CView1(1, 2);
                    }
                    else {
                        Level12_80154Call34F40View1(ownerRecord19, 0);
                        Level12_80154Field(privateRecord18, int *, 0x14) = (int) (Level12_80154Field(privateRecord18, int *, 0x14) - 1);
                    }
                }
            }
            goto callOriginalLateCleanup642;
        }
        break;
    case 2:
        if (Level12_80154Field(ownerRecord19, unsigned char *, 0x49) == 1) {
            rawWord3 = Level12_80154Field(privateRecord18, int*, 24);
            retainedOriginalHelperFlag = 0;
            __asm__("":"=r"(retainedOriginalHelperFlag):"0"(retainedOriginalHelperFlag):"memory");
            rawWord2 = Level12_80154Data6C648View1;
            rawWord2 = rawWord3+rawWord2;
            Level12_80154Field(privateRecord18, int*, 24) = rawWord2;
            retainedQuotientOrHelperFlags = rawWord3/270;
            __asm__("":"=r"(retainedQuotientOrHelperFlags):"0"(retainedQuotientOrHelperFlags):"$2");
            rawWord2 = 250;
            retainedQuotientOrHelperFlags = rawWord2-retainedQuotientOrHelperFlags;
            rawWord2 = retainedQuotientOrHelperFlags < 210;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"$22");
            retainedOriginalMotionFlags22 = 0;
            if (rawWord2)retainedQuotientOrHelperFlags = 210;
            retainedRemainderPointerHeadingOrFlag16 = (int)&originalFrame.sp30;
            __asm__("":"=r"(retainedRemainderPointerHeadingOrFlag16):"0"(retainedRemainderPointerHeadingOrFlag16):"$17");
            argumentWord4 = retainedRemainderPointerHeadingOrFlag16;
            retainedPlayerBaseHeightOrDistance17 = (int)&Level12_80154Data70328View1+152;
            Level12_80154Call4F178View1(argumentWord4, retainedPlayerBaseHeightOrDistance17);
            originalFrame.sp30 *= 0x14;
            originalFrame.sp34 *= 0x14;
            originalFrame.sp38 *= 0x14;
            Level12_80154Call4F110View1(retainedRemainderPointerHeadingOrFlag16, 6);
            Level12_80154Call4F194View1(retainedRemainderPointerHeadingOrFlag16, retainedRemainderPointerHeadingOrFlag16, retainedPlayerBaseHeightOrDistance17-152);
            retainedOriginalDistance23 = Level12_80154Call4F334View1(ownerRecord19+12, retainedRemainderPointerHeadingOrFlag16);
            temporaryWord13 = Level12_80154Field(privateRecord18, unsigned short *, 0x20) + 8;
            Level12_80154Field(privateRecord18, unsigned short *, 0x20) = temporaryWord13;
            if ((short) temporaryWord13 >= 0x101) {
                Level12_80154Field(privateRecord18, unsigned short *, 0x20) = 0x100U;
            }
            if (Level12_80154Field(privateRecord18, unsigned char *, 0x23) != 0) {
                retainedOriginalMotionFlags22 = 0x20000;
            }
            rawWord2 = Level12_80154Call35A80View1(ownerRecord19, Level12_80154Field(privateRecord18, int*, 4), 512, retainedQuotientOrHelperFlags, 0, (int)(Level12_80154Field(privateRecord18, unsigned short*, 32) << 16) >> 20, 24, retainedOriginalMotionFlags22);
            argumentWord4 = Level12_80154Field(privateRecord18, int*, 4);
            rawWord3 = Level12_80154Field(argumentWord4, short*, 2);
            argumentWord4 = Level12_80154Field(argumentWord4, int*, 12);
            rawWord3 *= 16;
            rawWord3 += argumentWord4;
            argumentWord4 = Level12_80154Field(rawWord3, int*, 8);
            rawWord3 = Level12_80154Field(ownerRecord19, int*, 20);
            rawWord3 = argumentWord4-rawWord3;
            rawWord3 = rawWord3 < 2001;
            retainedQuotientOrHelperFlags = rawWord2;
            if (!rawWord3)Level12_80154Field(ownerRecord19, int*, 20) = argumentWord4;
            retainedRemainderPointerHeadingOrFlag16 = retainedQuotientOrHelperFlags & 1;
            if (retainedRemainderPointerHeadingOrFlag16 != 0) {
                Level12_80154Field(privateRecord18, unsigned char *, 0x23) = 1U;
            }
            if (Level12_80154Call37A60View1(ownerRecord19, privateRecord18 + 0x1C, 4, 0x12, -0xC8) != 0) {
                retainedOriginalHelperFlag = 1;
                if (retainedRemainderPointerHeadingOrFlag16 != 0) {
                    rawWord2 = Level12_80154Call35D38View1(ownerRecord19);
                    argumentWord6 = Level12_80154Field(privateRecord18, int*, 4);
                    argumentWord5 = Level12_80154Field(argumentWord6, short*, 10);
                    __asm__ volatile("":::"$3", "memory");
                    rawWord3 = Level12_80154Field(argumentWord6, short*, 2);
                    argumentWord4 = Level12_80154Field(argumentWord6, short*, 0);
                    argumentWord5 *= 2;
                    rawWord3 += argumentWord5;
                    rawWord3 += argumentWord4;
                    argumentWord5 = rawWord3%argumentWord4;
                    retainedRemainderPointerHeadingOrFlag16 = (int)&originalFrame.sp40;
                    retainedPlayerBaseHeightOrDistance17 = rawWord2;
                    argumentWord4 = retainedRemainderPointerHeadingOrFlag16;
                    rawWord3 = Level12_80154Field(argumentWord6, int*, 12);
                    argumentWord5 *= 16;
                    argumentWord5 = rawWord3+argumentWord5;
                    Level12_80154Call4F178View1(argumentWord4, argumentWord5);
                    originalFrame.sp48 += 0x400;
                    rawWord3 = Level12_80154Call1A358View1(&originalFrame.sp40, 0x1000) - retainedPlayerBaseHeightOrDistance17;
                    if (rawWord3 >= 601){
                        rawWord2 = 220;
                        goto writeOriginalHeightWord448;
                    }
                    rawWord2 = rawWord3 < 129;
                    if (rawWord2) goto testOriginalHeightLower450;
                    rawWord2 = 200;
                    writeOriginalHeightWord448:Level12_80154Field(privateRecord18, int*, 28) = rawWord2;
                    testOriginalHeightLower450:rawWord2 = rawWord3 < -128;
                    if (rawWord2 != 0) {
                        Level12_80154Field(privateRecord18, int *, 0x1C) = 0x6E;
                    }
                }
            }
            if (({rawWord2 = retainedQuotientOrHelperFlags&4;__asm__("":"=r"(rawWord2):"0"(rawWord2));!rawWord2;})) {
                Level12_80154Field(privateRecord18, unsigned short *, 0x20) = 0U;
            }
            if (!retainedOriginalHelperFlag) goto produceOriginalZero476;
            rawWord2 = retainedOriginalDistance23 < 14337;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"$16");
            retainedRemainderPointerHeadingOrFlag16 = 0;
            if (rawWord2) goto callOriginalPreparedDistance477;
            rawWord2 = Level12_80154Call4F334View1(ownerRecord19+12, (int)&Level12_80154Data70328View1);
            rawWord2 = rawWord2 < 14337;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"$16");
            retainedRemainderPointerHeadingOrFlag16 = 0;
            if (rawWord2) goto callOriginalPreparedDistance477;
            __asm__ volatile("":::"$2", "$5", "$16");
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 0;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5), "r"(argumentWord4):"$2");
            rawWord2 = 2;
            Level12_80154Field(privateRecord18, int*, 20) = rawWord2;
            Level12_80154Field(ownerRecord19, unsigned char*, 72) = 0;
            Level12_80154Call34F40View1(argumentWord4, argumentWord5);
            goto callOriginalLateCleanup642;
            produceOriginalZero476:__asm__ volatile("":::"$16");
            retainedRemainderPointerHeadingOrFlag16 = 0;
        callOriginalPreparedDistance477:
            {
                retainedPlayerBaseHeightOrDistance17 = Level12_80154Call4F334View1(ownerRecord19 + 0xC, (int)&Level12_80154Data70328View1);
                if (Level12_80154Call4F264View1(Level12_80154Field(ownerRecord19, unsigned char *, 0x46), Level12_80154Field((int)&Level12_80154Data70328View1, unsigned char *, 0xE)) >= 0x5B) {
                    retainedRemainderPointerHeadingOrFlag16 = retainedPlayerBaseHeightOrDistance17 < 0x2000;
                }
                if (Level12_80154Call359A4View1(privateRecord18 + 0x14, 4) == 0) {
                    retainedRemainderPointerHeadingOrFlag16 = 0;
                }
                if (retainedRemainderPointerHeadingOrFlag16 != 0) {
                    Level12_80154Call3BABCView1(ownerRecord19, 0, 0);
                    temporaryWord9 = Level12_80154Field(privateRecord18, void **, 4);
                    Level12_80154Field(temporaryWord9, short *, 0xA) = (short) -(short) (unsigned short) Level12_80154Field(temporaryWord9, short *, 0xA);
                    temporaryWord2 = Level12_80154Field(privateRecord18, void **, 4);
                    temporaryWord10 = Level12_80154Field(temporaryWord2, short *, 0);
                    Level12_80154Field(temporaryWord2, short *, 2) = (short) ((int) (Level12_80154Field(temporaryWord2, short *, 2) + (Level12_80154Field(temporaryWord2, short *, 0xA) * 2) + temporaryWord10) % temporaryWord10);
                    Level12_80154Field(privateRecord18, int *, 0x14) = 0x1E;
                    Level12_80154Field(privateRecord18, unsigned short *, 0x20) = 0x100U;
                    rawWord2 = Level12_80154Call3636CView1(720, 1320, temporaryWord2);
                    argumentWord5 = Level12_80154Field(privateRecord18, unsigned short*, 94);
                    __asm__ volatile("":::"memory");
                    rawWord3 = Level12_80154Field(privateRecord18, short*, 94);
                    argumentWord5 += 1;
                    argumentWord4 = rawWord3*3;
                    rawWord3 = argumentWord4*15;
                    rawWord3 *= 4;
                    rawWord2 += rawWord3;
                    Level12_80154Field(privateRecord18, short*, 92) = rawWord2;
                    Level12_80154Field(privateRecord18, unsigned short*, 94) = argumentWord5;
                }
            }
        }
        goto callOriginalLateCleanup642;
    case 3:
        Level12_80154Field((int)&Level12_80154Data70328View1, int *, 0x20C) = 0x10000002;
        if (Level12_80154Call35194View1(ownerRecord19, privateRecord18 + 0x24) == 0x100) {
            Level12_80154Call4F178View1(&originalFrame.sp40, Level12_80154Field(Level12_80154Field(privateRecord18, void **, 0x3C), void **, 0xC));
            originalFrame.sp48 += Level12_80154Field((int)&Level12_80154Data70328View1, int *, 0x44);
            temporaryWord6 = Level12_80154Field(Level12_80154Field(privateRecord18, void **, 0x3C), void **, 0xC);
            temporaryWord3 = Level12_80154Field(temporaryWord6, int *, 0x10);
            Level12_80154Call13D44View1(&originalFrame.sp40, Level12_80154Call4E880View1(temporaryWord3 - Level12_80154Field(temporaryWord6, int *, 0), Level12_80154Field(temporaryWord6, int *, 0x14) - Level12_80154Field(temporaryWord6, int *, 4), 0), 0, 0);
            if (Level12_80154Field((int)&Level12_80154Data70328View1, int *, 0x280) < 0) {
                Level12_80154Field((int)&Level12_80154Data70328View1, int *, 0x280) = 0;
            }
            Level12_80154Call55D24View1(ownerRecord19, 4);
            Level12_80154Call3BA00View1(ownerRecord19);
            Level12_80154Call369B8View1(ownerRecord19, 0x20);
            Level12_80154Field(ownerRecord19, signed char *, 0x41) = 0;
            Level12_80154Field(ownerRecord19, signed char *, 0x4C) = 0;
            Level12_80154Field(ownerRecord19, signed char *, 0x4D) = 0;
            Level12_80154Field(ownerRecord19, unsigned char *, 0x48) = 4U;
        }
        goto callOriginalLateCleanup642;
    case 4:
        if (Level12_80154Data6E048View1 & 1) {
            Level12_80154Call4F178View1(&originalFrame.sp50, Level12_80154Field(Level12_80154Field(privateRecord18, void **, 0x3C), void **, 0xC) + 0x10);
            Level12_80154Call4F178View1(retainedLinkedRecord21 + 0xC, &originalFrame.sp50);
            Level12_80154Call37014View1(retainedLinkedRecord21);
            Level12_80154Field(retainedLinkedRecord21, unsigned char *, 0x52) = 0xFE;
            Level12_80154Call55D24View1(retainedLinkedRecord21, 2);
            Level12_80154Field(retainedLinkedRecord21, signed char *, 0x48) = 1;
            temporaryWord7 = Level12_80154Field(Level12_80154Field(privateRecord18, void **, 0x3C), void **, 0xC);
            temporaryWord4 = Level12_80154Field(temporaryWord7, int *, 0);
            Level12_80154Field(retainedLinkedRecord21, unsigned char *, 0x46) = Level12_80154Call4E880View1(temporaryWord4 - Level12_80154Field(temporaryWord7, int *, 0x10), Level12_80154Field(temporaryWord7, int *, 4) - Level12_80154Field(temporaryWord7, int *, 0x14), 0);
            Level12_80154Call55B18View1(ownerRecord19);
            return;
        }
        goto callOriginalLateCleanup642;
        default:goto callOriginalLateCleanup642;
    }
callOriginalLateCleanup642:
    if (Level12_80154Field(ownerRecord19, unsigned char *, 0x48) != 4) {
        if (Level12_80154Field(ownerRecord19, unsigned char *, 0x48) == 3) {
            Level12_80154Call35194View1(retainedLinkedRecord21, privateRecord18 + 0x40);
            return;
        }
        Level12_80154Call55D24View1(ownerRecord19, 4);
        Level12_80154Call55F14View1(ownerRecord19, 0, Level12_80154Data6C550View1 + (Level12_80154Field(privateRecord18, int *, 0x10) * 0x58) + 0xC);
        temporaryWord5 = (Level12_80154Field(privateRecord18, int *, 0x10) * 0x58) + Level12_80154Data6C550View1;
        Level12_80154Field(temporaryWord5, int *, 0x14) = (int) (Level12_80154Field(temporaryWord5, int *, 0x14) - 0x80);
        Level12_80154Field(((Level12_80154Field(privateRecord18, int *, 0x10) * 0x58) + Level12_80154Data6C550View1), unsigned char *, 0x52) = 0xFE;
        Level12_80154Field(((Level12_80154Field(privateRecord18, int *, 0x10) * 0x58) + Level12_80154Data6C550View1), unsigned char *, 0x46) = (unsigned char) Level12_80154Field(ownerRecord19, unsigned char *, 0x46);
    }
    else {
        return;
    }
    return;
}
#undef Level12_80154Field


/* SCUS-94467 USA Rev 0, 0x80080C80..0x80080E88, 130 instructions.
 * AI generated; not yet human reviewed. Tag words at +0/+4/+8 and record
 * signed count/+0xC pointer preserve original widths. Point stride is 16
 * bytes; signed delta products divide by 3 with original truncation.
 * Tick advances once per invocation, resets at 3, and advances the index.
 * Both original byte stores at Moby+0x44 remain. The masked return byte is
 * folded using the original positive shift and negative signed division.
 * Halfword reads at 8006E040/8006E03E and byte size steps retain their exact
 * numeric operations. No physical units, caller cadence or producer meaning
 * asserted. Empty constraints emit no instructions. Evidence: original
 * level_12/moby/func_level_12_80080C80.s; test: all linked words/full hashes.
 */
typedef struct {
    short count;
    unsigned char reserved02[10];
    unsigned char* points;
} Path80C80Record;
typedef struct {
    Path80C80Record* record;
    int index;
    int tick;
} Path80C80Tag;
extern unsigned short PathYaw __asm__("D_8006E040");
extern unsigned short PathPitch __asm__("D_8006E03E");
void func_level_12_80080C80(Moby* argument) {
    Vector3D scaled, delta;
    register Moby* moby __asm__("$19") = argument;
    register Path80C80Tag* tag __asm__("$18");
    register Vector3D* difference __asm__("$17");
    register int tick __asm__("$16");
    register int angle __asm__("$2");
    __asm__("" : "=r"(moby) : "0"(moby));
    tag = moby->mobyTag;
    tag->tick++;
    difference = &delta;
    if (tag->tick >= 3) {
        tag->tick = 0;
        tag->index++;
        if (tag->index >= tag->record->count - 1) {
            func_80055B18(argument);
            return;
        }
    }
    { register int byteOffset __asm__("$6")=tag->index<<4;
      register int nextOffset __asm__("$5");
      unsigned char* points=tag->record->points;
      tick=tag->tick;
      nextOffset=byteOffset+16;
      func_8004F1C8(difference,(Vector3D*)((unsigned int)points+nextOffset),(Vector3D*)((unsigned int)points+byteOffset)); }
    scaled.x=delta.x*tick/3;
    scaled.y=delta.y*tick/3;
    scaled.z=delta.z*tick/3;
    func_8004F194(&moby->position,&scaled,(Vector3D*)(tag->record->points+(tag->index<<4)));
    angle=func_8004E880(func_8004EDE8(difference,0),delta.z,0);
    __asm__("" : "=r"(angle) : "0"(angle));
    { register unsigned int byteAngle __asm__("$3")=(unsigned char)angle;
      register int folded __asm__("$2");
      __asm__("" : "=r"(byteAngle),"=r"(angle) : "0"(byteAngle),"1"(angle));
      moby->angle.roll=angle;
      if (byteAngle < 128) {
          folded = byteAngle >> 1;
          goto storeFolded;
      }
      folded = -((256 - (int)byteAngle) / 2);
storeFolded:
      __asm__("" : "=r"(folded) : "0"(folded));
      moby->angle.roll=folded; }
    moby->angle.yaw=((int)((unsigned int)PathYaw<<16)>>20)-128;
    moby->angle.pitch=PathPitch>>4;
    if (moby->size > 32) {
        moby->size -= 16;
        if (moby->size < 32) {
            moby->size = 32;
        }
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_12/moby/func_level_12_80080E88.s SHA256 a7ad951969477213058f5ad70348cddc1417d7356a1413db123338d63f05e0dc. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level12_80E88Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Level12_80E88_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level12_80E88_D_80065920[0x100] __asm__("D_80065920");
extern int Level12_80E88_D_8006C648 __asm__("D_8006C648");
extern Spyro Level12_80E88_D_80070328 __asm__("D_80070328");
void Level12_80E88_func_80035734(Moby* moby) __asm__("func_80035734");
int Level12_80E88_func_800359A4(void*, int) __asm__("func_800359A4");
int Level12_80E88_func_800363DC(int low, int high) __asm__("func_800363DC");
int Level12_80E88_func_8003BABC(Moby*, int, int) __asm__("func_8003BABC");
extern int Level12_80E88_func_8004E880(int, int, int) __asm__("func_8004E880");
extern void Level12_80E88_func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
extern void Level12_80E88_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level12_80E88_func_8004F194(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level12_80E88_func_8004F1C8(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
extern int Level12_80E88_func_8004F264(int, int) __asm__("func_8004F264");
extern int Level12_80E88_func_8004F334(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level12_80E88_func_80055B18(Moby*) __asm__("func_80055B18");
extern void Level12_80E88_func_80055D24(Moby*, int) __asm__("func_80055D24");
extern int Level12_80E88_rand(void) __asm__("rand");

int Level12_80E88_func_80018368(Vector3D *, Vector3D *) __asm__("func_80018368");
          /* extern */
int Level12_80E88_func_800365E4(Vector3D *, Vector3D *, unsigned int, unsigned int, unsigned char *) __asm__("func_800365E4");
 /* extern */
int Level12_80E88_func_8004E9E4(int) __asm__("func_8004E9E4");
                             /* extern */
int Level12_80E88_func_8004EA2C(int) __asm__("func_8004EA2C");
                             /* extern */
unsigned char Level12_80E88_func_8004EA90(unsigned char *, SHORTMATRIX *, unsigned int) __asm__("func_8004EA90");
 /* extern */
extern int Level12_80E88_D_8006C770 __asm__("D_8006C770");
extern unsigned char Level12_80E88_D_8006C7B4 __asm__("D_8006C7B4");
extern int Level12_80E88_D_8006C7C4 __asm__("D_8006C7C4");

void func_level_12_80080E88(Moby *ownerRecord) {
    /* SCUS-94467 original80080E88;
     original assembly SHA256 above.
     * Original0xC0-byte frame: local SP18..SP98 storage, saved16..21
     * atSPA0..SPB4 and RA atSPB8. Record offsets are bytes. Vector3D
     * holds three words;
      SHORTMATRIX holds nine halfwords and padding.
     * No physical units or universal coordinate conversion is inferred.
     * Case0 retains original rand53/55/74/76 before the dependent table
     * reads. rand has no C arguments. Table bytes are masked to0xFF.
     * Raw vector4/5 precede masked16 at80;
      table3/mask2 precede zero
     * stores91..94, which precede arithmetic95..101. Initialized empty
     * constraints retain these original producer boundaries without CPU
     * opcodes. Stack fields remain contiguous through helper calls.
     * Shared movement3/4 producers retain distinct helper calls, caller
     * pointers4/5, saved index16 and signed product17/negation. The shared
     * vector call261 precedes case1's vertical producer284..294.
     * The packet's X-byte assignment precedes Y=0 in C so original GCC
     * emits SB-zero61 after the halfword/pointer producers at461/462.
     * Saved coefficient20 and table17/21 retain original MULTs and frame.
     * Terminal return2/dead16 precede position16 initialization;
      a fresh
     * initialized owner identity retains the separate original55B18 call.
     * Physical units/fixed point, helper/SFX meanings, caller frame cadence
     * and synchronized runtime parity remain unresolved. Per invocation.
     * Falsification: all737 instructions and6 owned selector/padding words,
     * native/linked transfers and full EXE/every-overlay original hashes.
     * AI generated;
      not human reviewed. No completed-subsystem claim. */
    /* Contiguous original stack storage;
     every native word and target verified independently. */
    struct { int sp18;
     int sp1C;
     int sp20;
     unsigned char pad24[4];
     int sp28;
     int sp2C;
     int sp30;
     unsigned char pad34[4];
     Vector3D sp38;
     unsigned char pad44[4];
     SHORTMATRIX sp48;
     unsigned char pad5C[4];
     unsigned char sp60;
     signed char sp61;
     signed char sp62;
     unsigned char pad63[5];
     int sp68;
     int sp6C;
     int sp70;
     unsigned char pad74[4];
     int sp78;
     int sp7C;
     int sp80;
     unsigned char pad84[4];
     unsigned char sp88;
     unsigned char pad89[7];
     int sp90;
     int sp94;
     int sp98;
     unsigned char pad9C[4];
     } scratch;
    Moby *temp_v0_3;
    Vector3D *ownerPosition16;
    Vector3D *particlePosition16;
    register Vector3D *terminalPosition16 __asm__("16");
    Vector3D *positionVector17;
    Vector3D *otherPositionVector17;
    Vector3D *updatedPositionVector17;
    Vector3D *privateVectorPointer17;
    Vector3D *privateVector19;
    register Vector3D *sourceVector5 __asm__("5");
    short temp_v1_2;
    register int coefficient180_20 __asm__("20");
    register short *table65920_17 __asm__("17");
    register short *table658A0_21 __asm__("21");
    int temp_a0;
    int randomResult2;
    register int firstRandomWord16 __asm__("16");
    register int secondRandomWord16 __asm__("16");
    int tableIndexWord16;
    int maskedIndex16;
    int otherMaskedIndex16;
    int temp_s1_2;
    register int randomWord2 __asm__("2");
    register int tableWord3 __asm__("3");
    register Vector3D *vectorArgument4 __asm__("4");
    register Vector3D *vectorArgument5 __asm__("5");
    register Vector3D *vectorArgument6 __asm__("6");
    int temp_v0_2;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    register int tableIndex16 __asm__("16");
    register Vector3D *movementArgument4 __asm__("4");
    int spawnIndex16;
    register int productWord17 __asm__("17");
    int var_v0;
    int var_v0_2;
    unsigned char temp_v0_4;
    unsigned char temp_v1;
    void *temp_a1;
    void *temp_v1_6;
    void *temp_v1_7;
    void *var_a0;

    privateVector19 = ownerRecord->mobyTag;
    if (Level12_80E88_D_8006C7B4 & 4) {
        Level12_80E88_func_80055B18(ownerRecord);
        return;
    }
    temp_v1 = ownerRecord->state;
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        positionVector17 = &ownerRecord->position;
        ownerRecord->angle.yaw = Level12_80E88_func_8004E880(Level12_80E88_D_80070328.position.x - ownerRecord->position.x, Level12_80E88_D_80070328.position.y - ownerRecord->position.y, 0);
        ownerRecord->angle.pitch = Level12_80E88_func_8004E880(Level12_80E88_func_8004F334(positionVector17, &Level12_80E88_D_80070328.position), Level12_80E88_D_80070328.position.z - ownerRecord->position.z, 0);
        firstRandomWord16 = Level12_80E88_rand();
        randomResult2 = Level12_80E88_rand();
        firstRandomWord16 &= 0x1F;
         __asm__("" : "=r"(firstRandomWord16) : "0"(firstRandomWord16));
         firstRandomWord16 += 0x70;
        temp_v1_2 = Level12_80E88_D_80065920[(ownerRecord->angle.yaw + firstRandomWord16) & 0xFF];
        scratch.sp18 = (int) ((temp_v1_2 * 0xB4) + (randomResult2 & 0x7F)) >> 0xC;
        secondRandomWord16 = Level12_80E88_rand();
        randomWord2 = Level12_80E88_rand();
        __asm__ volatile("" : : "r"(randomWord2) : "4", "5", "memory");
        vectorArgument4 = (Vector3D *)&scratch.sp18;
         vectorArgument5 = vectorArgument4;
         __asm__("" : "=r"(vectorArgument4), "=r"(vectorArgument5) : "0"(vectorArgument4), "1"(vectorArgument5));
        secondRandomWord16 &= 0x1F;
         __asm__("" : "=r"(secondRandomWord16) : "0"(secondRandomWord16));
         secondRandomWord16 += 0x70;
        tableWord3 = ownerRecord->angle.yaw;
        vectorArgument6 = positionVector17;
        tableWord3 = Level12_80E88_D_800658A0[(tableWord3 + secondRandomWord16) & 0xFF];
        __asm__ volatile("" : "=r"(tableWord3), "=r"(randomWord2) : "0"(tableWord3), "1"(randomWord2) : "memory");
        randomWord2 &= 0x7F;
        scratch.sp20 = 0;
        scratch.sp28 = 0;
        scratch.sp2C = 0;
        scratch.sp30 = 0;
        __asm__ volatile("" : "=r"(tableWord3), "=r"(randomWord2) : "0"(tableWord3), "1"(randomWord2) : "memory");
        scratch.sp1C = (int) ((tableWord3 * 0xB4) + randomWord2) >> 0xC;
        Level12_80E88_func_8004F194(vectorArgument4, vectorArgument5, vectorArgument6);
        SpawnParticle(1, 0x2D, (Vector3D *) &scratch.sp18, (Vector3D *) &scratch.sp28);
        if (Level12_80E88_D_8006C7C4 == 2) {
            Level12_80E88Field(privateVector19, int *, 0x44) = 0x41A;
            var_v0 = 0x1E;
            goto block_10;
        }
        if (Level12_80E88_D_8006C7C4 == 1) {
            Level12_80E88Field(privateVector19, int *, 0x44) = 0x2BC;
            var_v0 = 0x16;
            goto block_10;
        }
        var_a0 = ((unsigned char *)privateVector19 + 0x74);
        if (Level12_80E88_D_8006C7C4 == 0) {
            Level12_80E88Field(privateVector19, int *, 0x44) = 0x2BC;
            var_v0 = 0x14;
block_10:
            Level12_80E88Field(privateVector19, int *, 0x48) = var_v0;
            var_a0 = ((unsigned char *)privateVector19 + 0x74);
        }
        if ((Level12_80E88_func_800359A4(var_a0, 4) != 0) && (Level12_80E88_func_8004F334(&ownerRecord->position, &Level12_80E88_D_80070328.position) < 0x708)) {
            temp_v1_3 = ownerRecord->position.z - ownerRecord->distanceToGround;
            temp_v0_2 = temp_v1_3 - Level12_80E88_D_80070328.position.z;
            if (temp_v0_2 >= 0) {
                if (temp_v0_2 >= 0x5DC) {

                } else {
                    goto block_18;
                }
            } else if ((Level12_80E88_D_80070328.position.z - temp_v1_3) < 0x5DC) {
block_18:
                if (Level12_80E88_func_8004F264((int) Level12_80E88_D_80070328.bodyRotation.yaw, Level12_80E88_func_8004E880(ownerRecord->position.x - Level12_80E88_D_80070328.position.x, ownerRecord->position.y - Level12_80E88_D_80070328.position.y, 0)) >= 0x47) {
                    Level12_80E88Field(privateVector19, int *, 0x74) = 0x78;
                    Level12_80E88_func_8003BABC(ownerRecord, 2, 0);
                }
            }
        }
        temp_v1_4 = Level12_80E88Field(privateVector19, int *, 0x24);
        switch (temp_v1_4) {                        /* switch 2;
         irregular */
        case 2:                                     /* switch 2 */
            temp_s1_2 = (int) (Level12_80E88_func_8004E9E4(Level12_80E88Field(privateVector19, int *, 0x40)) * Level12_80E88Field(privateVector19, int *, 0x44)) >> 0xC;
            tableIndexWord16 = Level12_80E88Field(privateVector19, int *, 0x30) + 0x40;
            Level12_80E88_func_8004F178(&ownerRecord->position, ((unsigned char *)privateVector19 + 0x34));
            maskedIndex16 = tableIndexWord16 & 0xFF;
            ownerRecord->position.x += (int) (Level12_80E88_D_80065920[maskedIndex16] * temp_s1_2) >> 0xC;
            ownerRecord->position.y += (int) (Level12_80E88_D_800658A0[maskedIndex16] * temp_s1_2) >> 0xC;
            break;
        case 3:                                     /* switch 2 */
            productWord17 = (int) (Level12_80E88_func_8004EA2C(Level12_80E88Field(privateVector19, int *, 0x40)) * Level12_80E88Field(privateVector19, int *, 0x44)) >> 0xC;
            movementArgument4 = &ownerRecord->position;
             __asm__("" : "=r"(movementArgument4) : "0"(movementArgument4));
            tableIndex16 = Level12_80E88Field(privateVector19, int *, 0x30);
             __asm__("" : "=r"(tableIndex16) : "0"(tableIndex16));
            sourceVector5 = ((unsigned char *)privateVector19 + 0x34);
             __asm__("" : "=r"(sourceVector5) : "0"(sourceVector5));
             tableIndex16 += 0x40;
            goto block_30;
        case 4:                                     /* switch 2 */
            productWord17 = (int) (Level12_80E88_func_8004EA2C(Level12_80E88Field(privateVector19, int *, 0x40)) * Level12_80E88Field(privateVector19, int *, 0x44)) >> 0xC;
             __asm__("" : "=r"(productWord17) : "0"(productWord17));
             productWord17 = -productWord17;
            movementArgument4 = &ownerRecord->position;
             __asm__("" : "=r"(movementArgument4) : "0"(movementArgument4));
            tableIndex16 = Level12_80E88Field(privateVector19, int *, 0x30);
             __asm__("" : "=r"(tableIndex16) : "0"(tableIndex16));
            sourceVector5 = ((unsigned char *)privateVector19 + 0x34);
             __asm__("" : "=r"(sourceVector5) : "0"(sourceVector5));
             tableIndex16 += 0x40;
block_30:
            otherMaskedIndex16 = tableIndex16 & 0xFF;
            Level12_80E88_func_8004F178(movementArgument4, sourceVector5);
            ownerRecord->position.x += (int) (Level12_80E88_D_80065920[otherMaskedIndex16] * productWord17) >> 0xC;
            ownerRecord->position.y += (int) (Level12_80E88_D_800658A0[otherMaskedIndex16] * productWord17) >> 0xC;
        case 1:                                     /* switch 2 */
            ownerRecord->position.z = Level12_80E88Field(privateVector19, int *, 0x3C) + ((int) (Level12_80E88_func_8004E9E4(Level12_80E88Field(privateVector19, int *, 0x40)) * Level12_80E88Field(privateVector19, int *, 0x44)) >> 0xC);
            break;
        }
        if (Level12_80E88Field(privateVector19, int *, 0x40) == 0) {
            Level12_80E88_func_8004F178(((unsigned char *)privateVector19 + 0x64), &ownerRecord->position);
        }
        temp_v1_5 = Level12_80E88Field(privateVector19, int *, 0x40) + (Level12_80E88_D_8006C648 * Level12_80E88Field(privateVector19, int *, 0x48));
        var_v0_2 = temp_v1_5;
        Level12_80E88Field(privateVector19, int *, 0x40) = temp_v1_5;
        if (temp_v1_5 < 0) {
            var_v0_2 = temp_v1_5 + 0xFFF;
        }
        Level12_80E88Field(privateVector19, int *, 0x40) = (int) (temp_v1_5 - ((var_v0_2 >> 0xC) << 0xC));
        if (ownerRecord->damageFlags & 0x10000) {
            Level12_80E88_func_8003BABC(ownerRecord, 0, 0);
            Level12_80E88Field(privateVector19, unsigned short *, 0x22) = 0U;
            Level12_80E88Field(privateVector19, int *, 0x4C) = 0;
            Level12_80E88Field(privateVector19, int *, 0x54) = Level12_80E88_func_800363DC(7, 0xC);
            Level12_80E88Field(privateVector19, int *, 0x50) = (int) Level12_80E88Field(privateVector19, int *, 0x30);
            if (Level12_80E88_func_8004F264(Level12_80E88Field(privateVector19, int *, 0x50), Level12_80E88_func_8004E880(Level12_80E88_D_80070328.position.x - ownerRecord->position.x, Level12_80E88_D_80070328.position.y - ownerRecord->position.y, 0)) < 0x40) {
                Level12_80E88Field(privateVector19, int *, 0x50) = (int) ((Level12_80E88Field(privateVector19, int *, 0x50) + 0x80) & 0xFF);
            }
            ownerRecord->unknownCollision = 0;
            if (ownerRecord->animationState.nextId != 1) {
                Level12_80E88_D_8006C770 = 0;
                ownerRecord->animationProgress = 0x72;
                ownerRecord->animationState.nextId = 1;
                ownerRecord->animationState.nextFrame = 0;
                Level12_80E88_func_80035734(ownerRecord);
            }
            ownerRecord->state = 1;
        }
        Level12_80E88_func_80055D24(ownerRecord, 2);
        return;
    case 1:                                         /* switch 1 */
        otherPositionVector17 = &ownerRecord->position;
        ownerRecord->angle.yaw = Level12_80E88_func_8004E880(Level12_80E88_D_80070328.position.x - ownerRecord->position.x, Level12_80E88_D_80070328.position.y - ownerRecord->position.y, 0);
        ownerRecord->angle.pitch = Level12_80E88_func_8004E880(Level12_80E88_func_8004F334(otherPositionVector17, &Level12_80E88_D_80070328.position), Level12_80E88_D_80070328.position.z - ownerRecord->position.z, 0);
        Level12_80E88Field(privateVector19, unsigned short *, 0x22) = (unsigned short) (Level12_80E88Field(privateVector19, unsigned short *, 0x22) + Level12_80E88_D_8006C648);
        Level12_80E88Field(privateVector19, int *, 0x4C) = (int) (Level12_80E88Field(privateVector19, int *, 0x4C) + 0x14);
        Level12_80E88_func_8004F178(&scratch.sp38, otherPositionVector17);
        ownerRecord->position.x += (int) (Level12_80E88_D_80065920[Level12_80E88Field(privateVector19, int *, 0x50)] * 0xAF) >> 0xB;
        ownerRecord->position.y += (int) (Level12_80E88_D_800658A0[Level12_80E88Field(privateVector19, int *, 0x50)] * 0xAF) >> 0xB;
        if ((short) Level12_80E88Field(privateVector19, unsigned short *, 0x22) >= 0x10) {
            if (Level12_80E88_func_80018368(&scratch.sp38, otherPositionVector17) != 0) {
                Level12_80E88Field(privateVector19, unsigned short *, 0x22) = 0x78U;
            }
        }
        scratch.sp68 = 0;
        scratch.sp6C = 0;
        scratch.sp70 = Level12_80E88Field(privateVector19, int *, 0x4C);
        scratch.sp60 = (short) Level12_80E88Field(privateVector19, unsigned short *, 0x22) * 0xC;
        scratch.sp61 = 0;
        scratch.sp62 = (signed char) Level12_80E88Field(privateVector19, int *, 0x50);
        Level12_80E88_func_8004EA90(&scratch.sp60, &scratch.sp48, 0);
        Level12_80E88_func_8004ED6C(&scratch.sp48, (Vector3D *) &scratch.sp68, (Vector3D *) &scratch.sp68);
        updatedPositionVector17 = &ownerRecord->position;
        Level12_80E88_func_8004F194(updatedPositionVector17, updatedPositionVector17, (Vector3D *) &scratch.sp68);
        ownerRecord->angle.roll = (unsigned char) -(int) scratch.sp60;
        scratch.sp78 = Level12_80E88_rand() & 7;
        scratch.sp7C = Level12_80E88_rand() & 7;
        scratch.sp80 = 0xC;
        SpawnParticle(1, 1, updatedPositionVector17, (Vector3D *) &scratch.sp78);
        if ((short) Level12_80E88Field(privateVector19, unsigned short *, 0x22) >= 0x29) {
            coefficient180_20 = 0xB4;
             __asm__("" : "=r"(coefficient180_20) : "0"(coefficient180_20));
            spawnIndex16 = 0;
            table65920_17 = Level12_80E88_D_80065920;
             table658A0_21 = Level12_80E88_D_800658A0;
             __asm__("" : "=r"(table65920_17), "=r"(table658A0_21) : "0"(table65920_17), "1"(table658A0_21));
            do {
                temp_v0_3 = SpawnMoby((int) ownerRecord->mobyClass, ownerRecord);
                if (temp_v0_3 != 0) {
                    temp_v0_3->unknown3[0] = 0;
                    temp_v0_3->lowDrawDistance = 0;
                    temp_v0_3->drawn = 0;
                    temp_v0_3->state = 4;
                    temp_a1 = temp_v0_3->mobyTag;
                    Level12_80E88Field(temp_a1, int *, 0xC) = 0x30;
                    temp_a0 = spawnIndex16 * 2;
                    temp_v1_6 = temp_a0 + Level12_80E88Field(privateVector19, int *, 0x70);
                    Level12_80E88Field(temp_a1, int *, 0) = (int) ((int) (((int) (table65920_17[Level12_80E88Field(temp_v1_6, unsigned char *, 0)] * coefficient180_20) >> 0xC) * table65920_17[Level12_80E88Field(temp_v1_6, unsigned char *, 1)]) >> 0xC);
                    temp_v1_7 = temp_a0 + Level12_80E88Field(privateVector19, int *, 0x70);
                    Level12_80E88Field(temp_a1, int *, 4) = (int) ((int) (((int) (table658A0_21[Level12_80E88Field(temp_v1_7, unsigned char *, 0)] * coefficient180_20) >> 0xC) * table65920_17[Level12_80E88Field(temp_v1_7, unsigned char *, 1)]) >> 0xC);
                    Level12_80E88Field(temp_a1, int *, 8) = (int) ((int) (table658A0_21[Level12_80E88Field((temp_a0 + Level12_80E88Field(privateVector19, int *, 0x70)), unsigned char *, 1)] * coefficient180_20) >> 0xC);
                }
                spawnIndex16 += 1;
            } while (spawnIndex16 < 0xC);
            Level12_80E88_func_8003BABC(ownerRecord, 1, 0);
            ownerRecord->unknown3[0] = 0;
            ownerRecord->lowDrawDistance = 0;
            ownerRecord->drawn = 0;
            Level12_80E88Field(privateVector19, unsigned short *, 0x22) = (unsigned short) Level12_80E88Field(privateVector19, unsigned short *, 0x20);
            ownerRecord->state = 2;
            return;
        }
    default:                                        /* switch 1 */
        return;
    case 2:                                         /* switch 1 */
        if (ownerRecord->substate != 0) {
            ownerRecord->substate = 0;
            ownerRecord->damageFlags = 0;
            Level12_80E88Field(privateVector19, int *, 0x40) = 0;
            ownerRecord->angle.roll = 0;
            ownerRecord->unknown3[0] = 1;
            ownerRecord->lowDrawDistance = 0x30;
            ownerRecord->drawn = 1;
            if (ownerRecord->animationState.nextId != 0) {
                Level12_80E88_D_8006C770 = 0;
                ownerRecord->animationProgress = 0x72;
                ownerRecord->animationState.nextId = 0;
                ownerRecord->animationState.nextFrame = 0;
                Level12_80E88_func_80035734(ownerRecord);
            }
            privateVectorPointer17 = ((unsigned char *)privateVector19 + 0x64);
            ownerPosition16 = &ownerRecord->position;
            Level12_80E88_func_8004F1C8((Vector3D *) &scratch.sp78, privateVectorPointer17, ownerPosition16);
            privateVector19->x = (int) (Level12_80E88_func_8004EA2C(Level12_80E88_func_8004E880(scratch.sp78, scratch.sp7C, 1)) * 0x12C) >> 0xC;
            privateVector19->y = (int) (Level12_80E88_func_8004E9E4(Level12_80E88_func_8004E880(scratch.sp78, scratch.sp7C, 1)) * 0x12C) >> 0xC;
            privateVector19->z = Level12_80E88_func_800365E4(ownerPosition16, privateVectorPointer17, 0x12C, -0x10, &scratch.sp88);
            ownerRecord->size = 0x64;
            ownerRecord->state = 3;
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        particlePosition16 = &ownerRecord->position;
        Level12_80E88_func_8004F194(particlePosition16, particlePosition16, privateVector19);
        privateVector19->z -= 0x10;
        temp_v0_4 = ownerRecord->size - (Level12_80E88_D_8006C648 * 4);
        ownerRecord->size = temp_v0_4;
        if ((unsigned int) (temp_v0_4 & 0xFF) < 0x20U) {
            ownerRecord->size = 0x20;
        }
        scratch.sp90 = 0;
        scratch.sp94 = 0;
        scratch.sp98 = 0;
        SpawnParticle(1, 1, particlePosition16, (Vector3D *) &scratch.sp90);
        if (Level12_80E88_func_8004F334(particlePosition16, ((unsigned char *)privateVector19 + 0x64)) < 0x100) {
            Level12_80E88_func_80055D24(ownerRecord, 1);
            ownerRecord->state = 0;
            return;
        }
        break;
    case 4:                                         /* switch 1 */
        { register int return2 __asm__("2");
         return2 = Level12_80E88_func_800359A4(((unsigned char *)privateVector19 + 0xC), 4);
         __asm__ volatile("" : : "r"(return2) : "16", "memory");
         terminalPosition16 = &ownerRecord->position;
        if (return2 != 0) {
            __asm__ volatile("" : "=r"(ownerRecord) : "0"(ownerRecord));
            Level12_80E88_func_80055B18(ownerRecord);
            return;
        }
        Level12_80E88_func_8004F194(terminalPosition16, terminalPosition16, privateVector19);
        scratch.sp90 = 0;
        scratch.sp94 = 0;
        scratch.sp98 = 0;
        SpawnParticle(1, 1, terminalPosition16, (Vector3D *) &scratch.sp90);
        }
        break;
    }
}
#undef Level12_80E88Field


void func_level_12_80081A0C(Moby* moby) {
    int* tag = moby->mobyTag;
    if (moby->position.z > 0x3E800) func_80055B18(moby);
    else switch (moby->state) {
    case 0:
        func_8004F194(&moby->position, &moby->position, (Vector3D*)tag);
        tag[2] += 2;
        if (tag[2] > 0xF0) tag[2] = 0xF0;
        moby->size--;
        if (moby->size < 0x16) moby->size = 0x16;
        if (!moby->drawn || func_800359A4(tag + 3, 4)) moby->state = 1;
        break;
    case 1:
        moby->size += 4;
        if (moby->size >= 0x80) func_80055B18(moby);
        break;
    }
}

typedef struct {
    Vector3D origin;
    unsigned char rollStep, reserved0D;
    short radius;
    unsigned char pitchStep, reserved11, yawStep, reserved13;
    short sizeStep;
    unsigned char timer;
} DecodedRotatingParticleTag;
extern int D_8006C648;
void func_level_12_80081B1C(Moby* moby) {
    DecodedRotatingParticleTag* tag = moby->mobyTag;
    SHORTMATRIX matrix;
    Angle angle;
    Vector3D offset;
    int fade;
    moby->angle.roll += tag->rollStep;
    moby->angle.pitch += tag->pitchStep;
    moby->angle.yaw += tag->yawStep;
    if (tag->radius) {
        angle.roll = 0;
        angle.pitch = moby->angle.pitch;
        angle.yaw = moby->angle.yaw;
        func_8004EA90(&angle, &matrix, 0);
        offset.x = tag->radius;
        offset.y = 0;
        offset.z = 0;
        func_8004ED6C(&matrix, &offset, &offset);
        func_8004F194(&moby->position, &tag->origin, &offset);
    }
    if (func_800359A4(&tag->timer, 1)) { func_80055B18(moby); return; }
    fade = 16 - tag->timer;
    if (fade < 0) fade = 0;
    moby->colour.a = fade + 0x30;
    moby->size += tag->sizeStep * D_8006C648;
    if (moby->size >= 0x80) moby->size = 0;
    if (moby->size < 0x18) moby->size = 0x18;
}

void func_level_12_80081C88(Moby* moby) {
    int* tag = moby->mobyTag;
    switch (moby->state) {
    case 0:
        if (moby->substate) {
            unsigned char* state;
            moby->state = 1;
            state = &moby->state;
            func_8003B7B4(state, 1, &savedData);
            func_8003B7B4(state, 1, &unsavedData);
        }
        break;
    case 1:
        if (func_800359A4(tag + 1, 4)) {
            if (tag[4] != -1) func_8003BB10(moby, tag[4], 0);
            tag[1] = tag[0];
            if (tag[2] != -1) func_80021ED8((void*)tag[2], 0xFC, 0);
            if (tag[3] != -1) func_80021ED8((void*)tag[3], 0xFC, 0);
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
void func_level_12_80081D84(Moby* actor) {
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
void func_level_12_80082030(Moby *input) {
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
void func_level_12_8008243C(Moby* input) {
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

typedef struct { unsigned char reserved00[0xA]; unsigned short threshold; unsigned char reserved0C[4]; unsigned char enabled; unsigned char reserved11[3]; } DecodedSelectorDescriptor;
typedef struct { unsigned char reserved00[0xC]; unsigned char* records; } DecodedSelectorAttachment;
typedef struct { int minimum,maximum,timerMinimum,timerMaximum; DecodedSelectorAttachment* attachment; int timer,handle; } DecodedSelectorUpdate;
extern unsigned char* D_8006C708;
extern DecodedSelectorDescriptor* D_8006C6A0;
extern int D_8006E044,D_8006E028;
int func_8004F334(Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_80036518(void*,void*,int*);
void func_level_12_80082828(Moby* actor) {
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
void func_level_12_80082A34(Moby* argument) {
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
void func_level_12_80082F5C(void *input) {
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
 * MobyUpdate_501() - func_level_12_800840B0()
 * Egg Fragments
 * Just reuse code from Sunrise Spring Home
 */
void func_level_12_800840B0(Moby* moby) {
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
void func_level_12_800840D0(Moby* argument) {
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
