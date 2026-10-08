#include "common.h"
typedef struct { Moby* actor; unsigned short reserved04; unsigned char state, byte41; short selector; } DecodedActorTransition;
#include "ovl_header.h"
#include "hud.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

extern short D_80065920[],D_800658A0[];
extern int D_8006C648;
int func_8004E880(int,int,int);
int func_8003613C(int,int);
int func_8004F264(int,int);
int func_8004F334(Vector3D*,Vector3D*);
int func_8003585C(Moby*,int,int,int,int,int);
int func_80035EE0(Moby*,int,int,int,int,int);
int func_80035DDC(Moby*,int,int,int,int);
int func_level_31_800874E0(Moby* actor,Vector3D* center,int radius,int heading,int tolerance,int speed,int turnA,int turnB,int avoidA,int avoidB,int argA,int argB,int flags) {
    register Moby* current __asm__("$19");
    register Vector3D* target __asm__("$20");
    register int range __asm__("$23");
    register int rate __asm__("$22");
    register int limit __asm__("$17");
    int avoid;
    register int angle __asm__("$18");
    register int error __asm__("$21");
    register int absolute __asm__("$2");
    register int distance __asm__("$3");
    register int initialHeading __asm__("$16");
    int result;
    register int lowAngle __asm__("$16");
    Vector3D destination;
    current=actor;
    __asm__("" : "=r"(current) : "0"(current));
    target=center;
    __asm__("" : "=r"(target) : "0"(target));
    range=radius;
    __asm__("" : "=r"(range) : "0"(range));
    initialHeading=heading;
    __asm__("" : "=r"(initialHeading) : "0"(initialHeading));
    rate=speed;
    __asm__("" : "=r"(rate) : "0"(rate));
    limit=tolerance;avoid=avoidA;
    angle=func_8004E880(current->position.x-target->x,current->position.y-target->y,0);
    error=func_8003613C(initialHeading,angle&0xFF);
    distance=func_8004F334(&current->position,target);
    absolute=error;
    if(error<0)absolute=-absolute;
    if(absolute<limit) {
        int radial=distance-range;
        if(radial<0)radial=range-distance;
        if(radial<0xC8)goto done;
    }
    if(avoid!=0xFF) {
        lowAngle=angle&0xFF;
        if(func_8004F264(lowAngle,avoid)<5) {
            result=func_8003613C(avoid,lowAngle);
            if(error<0 && result<0)return 0x100;
            if(error>0 && result>0)return 0x100;
        }
    }
    if(avoidB!=0xFF) {
        lowAngle=angle&0xFF;
        if(func_8004F264(lowAngle,avoidB)<5) {
            result=func_8003613C(avoidB,lowAngle);
            if(error<0 && result<0)return 0x100;
            if(error>0 && result>0)return 0x100;
        }
    }
    if(error<0)angle+=3;else angle-=3;
    {
    register int lookup __asm__("$3")=angle&0xFF;
    register int x __asm__("$7");
    __asm__("" : "=r"(lookup) : "0"(lookup));
    {register int product __asm__("$2")=(D_80065920[lookup]*range)>>12;
    x=target->x;
    __asm__("" : "=r"(product),"=r"(x) : "0"(product),"1"(x));
    x+=product;}
    destination.x=x;
    destination.y=target->y+((D_800658A0[lookup]*range)>>12);
    heading=func_8004E880(x-current->position.x,destination.y-current->position.y,0);
    }
    if(D_8006C648==3)rate+=rate>>1;
    else if(D_8006C648==4)rate<<=1;
    if(flags&8) {
        result=func_8004E880(target->x-current->position.x,target->y-current->position.y,0);
        func_8003585C(current,result,turnA,0,0,0);
        result=func_80035EE0(current,heading,rate,argA,argB,flags);
    } else {
        if(!func_8003585C(current,heading,turnA,turnB,1,0))goto done;
        result=func_80035DDC(current,rate,argA,argB,flags);
    }
    if(result)return -result;
 done:
    return ABS(error);
}

void func_level_31_800877FC(Moby* moby, int mode) {
    spyro.unk20a = 1;
    spyro.unk20b = mode;
    spyro.critterMobyPtr = moby;
    if ((camera.cameraState == CAMERA_FIRST_PERSON && (unsigned int)camera.unk50 >= 2)
        || (spyro.unk17b & 0x2000)) {
        moby->lowDrawDistance = 0;
        moby->drawn = 0;
    } else {
        moby->lowDrawDistance = 0x10;
    }
}

#define Controller582CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char Controller582CPlayer[] __asm__("D_80070328");
extern void* Controller582CLinked0 __asm__("D_80070328 + 0x250");
extern void* Controller582CLinked1 __asm__("D_80070328 + 0x250");
extern void* Controller582CLinked2 __asm__("D_80070328 + 0x250");
extern unsigned char Controller582CSave[] __asm__("D_8006C7F8");
extern int D_8006C6C0,D_8006C710,D_8006E524,D_8007203C,D_80072040;
int Controller582CHelper3B7B4(void*,int,void*) __asm__("func_8003B7B4");
int Controller582CHelper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller582CHelper3BE70(int) __asm__("func_8003BE70");
int Controller582CHelper3BFC0(void*,int) __asm__("func_8003BFC0");
int Controller582CHelper498C0(void) __asm__("func_800498C0");
int Controller582CHelper4BEF8(int) __asm__("func_8004BEF8");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original289 instructions and eight owned jump-table words per copy.
 * Original instruction streams, global/helper symbols and table offsets checked
 * independently across23 level copies. Representative: level11/8008582C.
 * Exact entry guards, input mask, word/halfword access widths and eight dispatch
 * targets retained. Eight particle calls retain two rand calls per iteration,
 * signed halfword samples and product shifts7/12. The linked pointer at+250 is
 * reread at the original call boundaries; repeated tests are not consolidated.
 * Numeric units, semantic helper/table producers and caller cadence remain
 * unresolved; once per invocation. Names do not establish semantic meanings.
 * Confidence: exact compiled and linked original words/full retail hashes.
 * Falsifiable vectors: all original words and complete retail SHA values.
 * Empty constraints preserve original register phases without opcode patches.
 */
int func_level_31_80087874(int inputMask) {
    register int* gateWord __asm__("$5")=(int*)(Controller582CPlayer+0x284);
    register signed short* cosine __asm__("$21");
    register signed short* sine __asm__("$20");
    Vector3D offset;
    register int helperArgument __asm__("$4");
    register signed short *cosinePointer __asm__("$5");
    register int firstSample __asm__("$16");
    register int firstTableWord __asm__("$16");
    register int selectedBits __asm__("$19");
    register int secondTableWord __asm__("$2");
    register int particleIndex __asm__("$18");
    int nextWord;
    unsigned char *resultRecord;
    register unsigned char *record0 __asm__("$17");
    register unsigned char *record1 __asm__("$17");

    if ((*gateWord == 0) && (Controller582CField(Controller582CPlayer, int *, 0x1CC) == 0)) {
        if (Controller582CField(Controller582CPlayer, unsigned int *, 0x24C) == 5) {
            Controller582CField(Controller582CPlayer, int *, 0x24) = (int) Controller582CField(Controller582CField(Controller582CPlayer, void **, 0x250), int *, 0x18);
            Controller582CField(Controller582CField(Controller582CPlayer, void **, 0x250), int *, 0x18) = 0;
        }
        { register int inputBits __asm__("$2")=Controller582CField(Controller582CPlayer,int*,0x24);
          __asm__("" : "=r"(inputBits) : "0"(inputBits));
          selectedBits=inputBits&inputMask; }
        if (selectedBits != 0) {
            if (Controller582CField(Controller582CPlayer, unsigned int *, 0x24C) == 5) {
                Controller582CField(Controller582CPlayer, unsigned int *, 0x284) = (unsigned int) Controller582CField(Controller582CPlayer, unsigned int *, 0x24C);
                goto dispatch;
            }
            if (Controller582CField(Controller582CPlayer, int *, 0x48) == 0x26) {
                helperArgument = 0x39;
                Controller582CField(Controller582CPlayer, int *, 0x244) = 0;
                Controller582CField(Controller582CPlayer, void **, 0x250) = 0;
                goto sharedCall;
            }
            goto afterCall;
sharedCall:
            Controller582CHelper4BEF8(helperArgument);
handled:
            __asm__ volatile("" : : : "$2");
            return 1;
afterCall:
            if (Controller582CField(Controller582CPlayer, unsigned int *, 0x24C) != 7) {
                { register int literal __asm__("$2")=90;
                  register int remaining __asm__("$3")=Controller582CField(Controller582CPlayer,int*,0x280);
                  __asm__("" : "=r"(literal),"=r"(remaining) : "0"(literal),"1"(remaining));
                  *gateWord=literal;
                  if(remaining>=0){
                    { register int next __asm__("$2")=remaining-1;
                      Controller582CField(Controller582CPlayer,int*,0x280)=next;
                      __asm__ volatile("" : : : "memory"); }
                    D_8006C6C0+=1;D_8006C710+=1;
                  } }

            }
dispatch:
            switch (Controller582CField(Controller582CPlayer, unsigned int *, 0x24C)) {
            default:
                goto handled;
            case 0:
                helperArgument=0x1B;
                goto sharedCall;
            case 1:
                helperArgument = 0x48;
                goto sharedCall;
            case 2:
                helperArgument = 0x58;
                goto sharedCall;
            case 3:
                if (({ register int selector __asm__("$2")=selectedBits&8; __asm__("" : "=r"(selector) : "0"(selector)); selector; })) {
                    helperArgument = 0x6C;
                    if (Controller582CField(Controller582CPlayer, int *, 0x280) >= 0) {
                        helperArgument = 0x6B;
                    }
                } else {
                    helperArgument = 0x69;
                    if (Controller582CField(Controller582CPlayer, int *, 0x280) >= 0) {
                        helperArgument = 0x68;
                    }
                }
                goto sharedCall;
            case 4:
                helperArgument = 0x79;
                goto sharedCall;
            case 5:
                record0 = Controller582CField(Controller582CField(Controller582CPlayer, void **, 0x250), void **, 0);
                            if (Controller582CField(Controller582CPlayer, int *, 0x240) == 0) {
                    particleIndex = 0;
                    cosine=D_80065920;
                    sine=D_800658A0;
                    do {
                        particleIndex += 1;
                        firstSample = rand() & 0xFF;
                        secondTableWord=rand()&255;
                        __asm__("" : "=r"(secondTableWord),"=r"(firstSample) : "0"(secondTableWord),"1"(firstSample));
                        firstTableWord=firstSample*2;
                        { register int firstAddress __asm__("$3")=firstTableWord+(int)cosine;
                          register int sample __asm__("$3");
                          register int factor __asm__("$4");
                          register int product __asm__("$8");
                          __asm__("" : "=r"(firstAddress) : "0"(firstAddress));
                          secondTableWord*=2;
                          cosinePointer=(signed short*)(secondTableWord+(int)cosine);
                          sample=*(signed short*)firstAddress;
                          factor=*cosinePointer;
                          __asm__("" : "=r"(sample),"=r"(factor) : "0"(sample),"1"(factor));
                          sample >>=7;
                          product=sample*factor;
                          firstTableWord+=(int)sine;
                          __asm__("" : "=r"(product),"=r"(firstTableWord) : "0"(product),"1"(firstTableWord));
                          sample=product>>12;
                          __asm__("" : "=r"(sample) : "0"(sample));
                          offset.x=sample;
                          sample=*(signed short*)firstTableWord;
                          factor=*cosinePointer;
                          __asm__("" : "=r"(sample),"=r"(factor) : "0"(sample),"1"(factor));
                          sample >>=7;
                          product=sample*factor;
                          { register unsigned char* position __asm__("$6")=record0+0x30;
                            register Vector3D* prepared __asm__("$7");
                            register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$2");
                            register int zero __asm__("$5");
                            secondTableWord+=(int)sine;
                            __asm__("" : "=r"(secondTableWord),"=r"(position) : "0"(secondTableWord),"1"(position) : "$7");
                            prepared=&offset;
                            __asm__("" : "=r"(product),"=r"(position),"=r"(prepared),"=r"(secondTableWord) : "0"(product),"1"(position),"2"(prepared),"3"(secondTableWord));
                            sample=product>>12;
                            __asm__("" : "=r"(sample) : "0"(sample));
                            offset.y=sample;
                            secondTableWord=*(signed short*)secondTableWord;
                            __asm__("" : "=r"(secondTableWord) : "0"(secondTableWord) : "$5");
                            zero=0;
                            __asm__("" : "=r"(secondTableWord),"=r"(zero) : "0"(secondTableWord),"1"(zero));
                            offset.z=secondTableWord>>7;
                            __asm__ volatile("" : : : "memory");
                            callback=(void(*)(int,int,Vector3D*,Vector3D*))SpawnParticle;
                            __asm__("" : "=r"(callback) : "0"(callback) : "$4");
                            callback(1,zero,(Vector3D*)position,prepared); }
                        }

                    } while (particleIndex < 8);
                    D_80072040 = 0xC8;
                    D_8007203C = 0xA;
                    if (selectedBits & 1) {
                        Controller582CHelper4BEF8(0x8C);
                        nextWord = Controller582CField(record0, int *, 0x24) - 1;
                    } else if (({ register int selector __asm__("$2"); __asm__("" : : : "$2"); selector=selectedBits&2; __asm__("" : "=r"(selector) : "0"(selector)); selector; })) {
                        Controller582CHelper4BEF8(0x8C);
                        nextWord = Controller582CField(record0, int *, 0x24) - 3;
                    } else {
                        Controller582CHelper4BEF8(0x8D);
                        nextWord = Controller582CField(record0, int *, 0x24) - 2;
                    }
                    Controller582CField(record0, int *, 0x24) = nextWord;
                    D_8006C6C0 += 1;
                    __asm__ volatile("" : : : "memory");
                    { register int counter __asm__("$2")=D_8006C710;
                      register int remaining __asm__("$3")=Controller582CField(record0,int*,0x24);
                      __asm__("" : "=r"(counter),"=r"(remaining) : "0"(counter),"1"(remaining));
                      D_8006C710=counter+1;
                      if (remaining < 0) {
                        Controller582CField(record0, int *, 0x24) = 0;
                    } }
                    Controller582CHelper3B7B4(record0 + 0x24, 4, Controller582CSave);
                    return 1;
                }

                return 0;
            case 7:
                { register void* linked __asm__("$2")=Controller582CLinked0;
                  __asm__("" : "=r"(linked) : "0"(linked));
                  record1=*(unsigned char**)linked; }
                if (Controller582CField(record1,int*,0x1C)&1)return 1;
                { register int duration __asm__("$16")=15;
                  Controller582CField(Controller582CPlayer,int*,0x284)=duration;
                  { register int count __asm__("$2")=Controller582CField(record1,int*,0x28);
                    register int second __asm__("$5");
                    __asm__("" : "=r"(count) : "0"(count) : "$5");
                    second=2;
                    __asm__("" : "=r"(count),"=r"(second) : "0"(count),"1"(second));
                    Controller582CField(record1,int*,0x28)=count-1;
                    __asm__ volatile("" : : : "memory");
                    Controller582CHelper3BABC(Controller582CLinked0,second,0); }
                  D_8006E524=duration; }
                if(Controller582CField(Controller582CPlayer,int*,0x280)>0 && Controller582CField(record1,int*,0x28)>0)return 1;
                if(Controller582CHelper3BFC0(Controller582CLinked1,Controller582CField(record1,int*,0x48))!=0){
                    if(Controller582CHelper3BFC0(Controller582CLinked2,Controller582CField(record1,int*,0x48))!=0)Controller582CHelper3BE70(Controller582CField(record1,int*,0x48));
                    Controller582CField(record1,int*,0x48)=-1;
                }
                Controller582CHelper498C0();
                return 1;
            case 6:
                resultRecord = Controller582CField(Controller582CField(Controller582CPlayer, void **, 0x250), void **, 0);
                Controller582CField(resultRecord, unsigned short *, 0x66) = (unsigned short) (Controller582CField(resultRecord, unsigned short *, 0x66) | selectedBits);
                return 0;
            }
        } else {

            return 0;
        }
    } else {
        return 0;
    }
}

#undef Controller582CField


int func_level_31_80087CF8(Vector3D* position, int value, Moby* whirlwind) {
    int previousState = spyro.unk17c == 2;
    spyro.unk17a = 0x10000040;
    spyro.m_WhirlwindPointer = whirlwind;
    func_8004F178(&spyro.unk19, position);
    spyro.unk20[0] = value;
    return previousState;
}

/* USA Rev 0 SCUS-94467, 0x80087D6C: 217 original instructions.
 * Vector words are signed 32-bit values; helper units and caller cadence remain
 * unresolved. The record reproduces original stack offsets 0x18 through 0x9C.
 * Empty constraints preserve compiler allocation/order and emit no instructions.
 * AI generated; not human reviewed. */
typedef struct {
 Vector3D position18;int pad24;
 Vector3D difference28;int pad34;
 Vector3D rotated[3];int pad5C;
 Vector3D stepped[3];int pad84;
 int counter88;int pad8C;
 Vector3D* volatile pointer90;int pad94;
 Vector3D* volatile pointer98;int pad9C;
} P87D6CFrame;
int TypedCaller80087D6C_func_80050B00(void*,void*,void*,void*,int) __asm__("func_80050B00");
void TypedCaller80087D6C_func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
void TypedCaller80087D6C_func_8004F110(void*,int) __asm__("func_8004F110");
void func_level_31_80087D6C(void **arg0, int arg1) {
    P87D6CFrame frame;
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5"), *call6 __asm__("$6");
    register void *call7 __asm__("$7");
    register Vector3D *vector21 __asm__("$21"), *vector19 __asm__("$19");
    register Vector3D *step0 __asm__("$20"), *step1 __asm__("$18"), *step2 __asm__("$16");
    register Vector3D *difference28 __asm__("$16");
    register int sourceAddress __asm__("$18")=arg1;
    register void *pointer17 __asm__("$17");
    register int iteration8 __asm__("$8");
    int initResult;
    int index1;
    register int index3 __asm__("$18");
    register int vectorOffset __asm__("$20");
    register int entryCount __asm__("$23");
    register int index4 __asm__("$4");
    register int lastIndex4 __asm__("$4");
    register int index5 __asm__("$5");
    register int lastIndex5 __asm__("$5");
    register int index6 __asm__("$6");
    register int index7 __asm__("$7");
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int byteValue __asm__("$19");
    register void *write16Next __asm__("$16");
    register void *write16Last __asm__("$16");
    register void *state __asm__("$22");
    register void *end2 __asm__("$2");
    register void *write16 __asm__("$16");


    state = *arg0;
    if ((*(int *)((unsigned char*)state + 0x14)) == 0) {
        call4=state+0x18;call5=state+0x288;call6=state+0x2CC;
        __asm__("" : "=r"(call6) : "0"(call6), "r"(call4), "r"(call5) : "$2", "$7");
        work2=2;
        __asm__("" : "=r"(work2) : "0"(work2), "r"(call4), "r"(call5), "r"(call6) : "$7");
        call7=state+0xC;
        initResult=TypedCaller80087D6C_func_80050B00(call4,call5,call6,call7,work2);
        (*(int *)((unsigned char*)state+0x14))=initResult;
        if(initResult==0)goto finish;
    }
     {
        call4=&frame.position18;
        __asm__("" : "=r"(call4) : "0"(call4) : "$17");
        pointer17 = (Vector3D*)(sourceAddress + 0xC);
        func_8004F178(call4, pointer17);
        difference28=&frame.difference28;
        TypedCaller80087D6C_func_8004F1C8(difference28, state, pointer17);
        TypedCaller80087D6C_func_8004F110(difference28, 4);
        call4=(void*)(sourceAddress+0x20);
        __asm__("" : "=r"(call4) : "0"(call4) : "$21");
        frame.rotated[0].z = 0x200;
        frame.rotated[1].y = 0x200;
        frame.rotated[0].x = 0;
        frame.rotated[0].y = 0;
        frame.rotated[1].x = 0;
        frame.rotated[1].z = -0x130;
        frame.rotated[2].x = 0;
        frame.rotated[2].y = -0x200;
        frame.rotated[2].z = -0x130;
        vector21=&frame.rotated[0];
        func_8004ED6C(call4, vector21, vector21);
        call4=0;
        __asm__("" : "=r"(call4) : "0"(call4) : "$19");
        vector19=&frame.rotated[1];
        func_8004ED6C(call4, vector19, vector19);
        call4=0;
        __asm__("" : "=r"(call4) : "0"(call4) : "$17");
        pointer17=&frame.rotated[2];
        func_8004ED6C(call4, pointer17, pointer17);
        step0=&frame.stepped[0];
        func_8004F178(step0, vector21);
        step1=&frame.stepped[1];
        func_8004F178(step1, vector19);
        step2=&frame.stepped[2];
        func_8004F178(step2, pointer17);
        TypedCaller80087D6C_func_8004F110(step0, 4);
        TypedCaller80087D6C_func_8004F110(step1, 4);
        TypedCaller80087D6C_func_8004F110(step2, 4);
        entryCount = 0;
        func_8004F194(state + 0x18, &frame.position18, (Vector3D *) &frame.rotated[0].x);
        func_8004F194(state + 0x24, &frame.position18, (Vector3D *) &frame.rotated[1].x);
        func_8004F194(state + 0x30, &frame.position18, (Vector3D *) &frame.rotated[2].x);
        index3 = 3;
        index1 = 1;
        frame.pointer90 = vector21;
        vector21 = pointer17;
        frame.pointer98 = vector19;
        byteValue = 0xF;
        write16 = state;
        pointer17 = state + 4;
        vectorOffset = 0x3C;
        frame.counter88 = 0;
        (*(signed char *)((unsigned char*)(state) + 0x288)) = 0;
        (*(signed char *)((unsigned char*)(state) + 0x289)) = 0;
        (*(signed char *)((unsigned char*)(state) + 0x28A)) = 0;
        do {
            __asm__("" : : : "$4");
            func_8004F194(&frame.position18, &frame.position18, &frame.difference28);
            TypedCaller80087D6C_func_8004F1C8(frame.pointer90, frame.pointer90, &frame.stepped[0]);
            TypedCaller80087D6C_func_8004F1C8(frame.pointer98, frame.pointer98, &frame.stepped[1]);
            TypedCaller80087D6C_func_8004F1C8(vector21, vector21, &frame.stepped[2]);
            func_8004F194(state + vectorOffset, &frame.position18, (Vector3D *) frame.pointer90);
            vectorOffset += 0xC;index3++;
            func_8004F194(state + vectorOffset, &frame.position18, (Vector3D *) frame.pointer98);
            vectorOffset += 0xC;index3++;
            func_8004F194(state + vectorOffset, &frame.position18, vector21);
            vectorOffset += 0xC;index3++;
            (*(signed char *)((unsigned char*)(pointer17) + 0x288)) = byteValue;
            (*(signed char *)((unsigned char*)(pointer17) + 0x289)) = byteValue;
            (*(signed char *)((unsigned char*)(pointer17) + 0x28A)) = 0;
            pointer17 += 4;
            __asm__ __volatile__("" : "=r"(index1) : "0"(index1) : "memory");
            index1 += 1;
            index5 = index3 - 6;
            index4 = index3 - 3;
            index7 = index3 - 5;
            index6 = index3 - 2;
            work3 = index1 - 2;
            __asm__("" : "=r"(work3) : "0"(work3) : "$2");
            work2 = index1 - 1;
            (*(signed char *)((unsigned char*)(write16) + 0x2CC)) = index5;
            (*(signed char *)((unsigned char*)(write16) + 0x2CD)) = index4;
            (*(signed char *)((unsigned char*)(write16) + 0x2CE)) = index7;
            (*(signed char *)((unsigned char*)(write16) + 0x2CF)) = index6;
            (*(signed char *)((unsigned char*)(write16) + 0x2D0)) = work3;
            (*(signed char *)((unsigned char*)(write16) + 0x2D1)) = work2;
            (*(signed char *)((unsigned char*)(write16) + 0x2D2)) = work3;
            (*(signed char *)((unsigned char*)(write16) + 0x2D3)) = work2;
            write16Next = write16 + 8;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2CC)) = index5;
            lastIndex5 = index3 - 4;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2CD)) = index4;
            lastIndex4 = index3 - 1;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2CE)) = lastIndex5;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2CF)) = lastIndex4;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2D0)) = work3;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2D1)) = work2;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2D2)) = work3;
            (*(signed char *)((unsigned char*)(write16Next) + 0x2D3)) = work2;
            write16Last = write16Next + 8;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2CC)) = lastIndex5;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2CD)) = lastIndex4;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2CE)) = index7;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2CF)) = index6;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2D0)) = work3;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2D1)) = work2;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2D2)) = work3;
            (*(signed char *)((unsigned char*)(write16Last) + 0x2D3)) = work2;
            write16 = write16Last + 8;
            entryCount += 3;
            __asm__("" : "=r"(entryCount) : "0"(entryCount));
            byteValue += 0x10;
            iteration8 = frame.counter88 + 1;
            work2 = iteration8 < 0x10;
            __asm__("" : : "r"(iteration8));
            frame.counter88 = iteration8;
        } while (work2);
        end2 = state + (index3 * 0xC);
        __asm__("" : "=r"(end2) : "0"(end2) : "$3");
        (*(int *)((unsigned char*)(end2) + 0x18)) = -1;
        (*(int *)((unsigned char*)(end2) + 0x1C)) = -1;
        (*(int *)((unsigned char*)(end2) + 0x20)) = -1;
        work2=entryCount*8 + (int)state;
        __asm__("" : "=r"(work2) : "0"(work2));
        (*(int *)((unsigned char*)(work2) + 0x2CC)) = -1;
    }
finish:;
}

/* Rev0 representative8008E034..8008E2F0,175 original instructions.
 * Reuses the inspected1057 oriented-bounds reconstruction. Fields at C/10/14,
 * signed trig halfwords, low-word products and arithmetic shifts12 follow
 * the original instructions. Physical units, table/angle producers and caller
 * cadence remain unresolved. Empty constraints emit no instructions and retain
 * GCC2.7.2 register lifetimes, access order and native multiply destinations.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct { Vector3D position; int width, height, angle; } DecodedOrientedBounds;
typedef struct { int local[2]; int reserved18[2]; Vector3D delta; int reserved2C; } DecodedBoundsWorkspace;
extern short D_80065920[], D_800658A0[];
void DecodedBoundsSubtract(void*,void*,void*) __asm__("func_8004F1C8");
void DecodedBoundsAdd(void*,void*,void*) __asm__("func_8004F194");
void func_level_31_800880D0(Vector3D* outputArg, Vector3D* position, DecodedOrientedBounds* boundsArg, int marginArg) {
    DecodedBoundsWorkspace work;
    register DecodedOrientedBounds* bounds __asm__("$18");
    register int margin __asm__("$19");
    register int incomingMargin __asm__("$7") = marginArg;
    register Vector3D* output __asm__("$20");
    register int magnitude __asm__("$3");
    register int sourceWidth __asm__("$2");
    int width;
    int height;
    register int distanceX __asm__("$2");
    register int x __asm__("$6");
    register int y __asm__("$4");
    register int distanceY __asm__("$3");
    __asm__("" : : : "$20");
    bounds = boundsArg;
    __asm__("" : "=r"(bounds), "=r"(incomingMargin) : "0"(bounds), "1"(incomingMargin));
    margin = incomingMargin;
    __asm__("" : "=r"(margin) : "0"(margin));
    magnitude = margin;
    sourceWidth = bounds->width;
    if (margin < 0) magnitude = -magnitude;
    __asm__("" : "=r"(magnitude) : "0"(magnitude));
    width = sourceWidth - magnitude;
    output = outputArg;
    if (width < 0) width = 0;
    height = bounds->height - magnitude;
    if (height < 0) height = 0;
    {
        register void* deltaArgument __asm__("$4") = &work.delta;
        __asm__("" : "=r"(deltaArgument) : "0"(deltaArgument));
        DecodedBoundsSubtract(deltaArgument,position,bounds);
    }
    __asm__ volatile ("" : : "r"(margin));
    /* Transform the helper output into the two raw local coordinates. */
    {
        register int firstProduct __asm__("$3") = work.delta.x*D_80065920[bounds->angle];
        register int secondProduct __asm__("$2") = work.delta.y*D_800658A0[bounds->angle];
        __asm__("" : "=r"(firstProduct), "=r"(secondProduct) : "0"(firstProduct), "1"(secondProduct));
        x = (firstProduct - secondProduct) >> 12;
    }
    work.local[0] = x;
    {
        register int firstProduct __asm__("$3") = work.delta.x*D_800658A0[bounds->angle];
        register int secondProduct __asm__("$2") = work.delta.y*D_80065920[bounds->angle];
        __asm__("" : "=r"(firstProduct), "=r"(secondProduct) : "0"(firstProduct), "1"(secondProduct));
        y = (firstProduct + secondProduct) >> 12;
        __asm__("" : "=r"(y) : "0"(y));
    }
    work.local[1] = y;
    /* Preserve the retail signed-margin branches and independent clamps. */
    if (margin >= 0) {
        {
            register int lower __asm__("$3") = -width;
            register int condition __asm__("$2") = x < lower;
            __asm__("" : "=r"(condition) : "0"(condition));
            if (condition) work.local[0] = lower;
        }
        if (work.local[0] > width) work.local[0] = width;
        {
            register int lower __asm__("$3") = -height;
            register int condition __asm__("$2") = y < lower;
            __asm__("" : "=r"(condition) : "0"(condition));
            if (condition) work.local[1] = lower;
        }
        if (work.local[1] > height) work.local[1] = height;
    } else {
        register int absolute __asm__("$2");
        absolute = x;
        if (x < 0) absolute = -absolute;
        if (absolute < width) {
            absolute = y;
            if (y < 0) absolute = -absolute;
            if (absolute < height) {
                if (x < 0) distanceX = x + width;
                else distanceX = width - x;
                __asm__("" : "=r"(distanceX) : "0"(distanceX));
                distanceY = work.local[1];
                if (distanceY < 0) distanceY += height;
                else distanceY = height-distanceY;
                __asm__("" : "=r"(distanceY) : "0"(distanceY));
                if (distanceX < distanceY) {
                    if (work.local[0] < 0) work.local[0] = -width;
                    else work.local[0] = width;
                } else {
                    if (work.local[1] < 0) work.local[1] = -height;
                    else work.local[1] = height;
                }
            }
        }
    }
    /* Transform the selected local coordinates back through the same tables. */
    {
        register int localX __asm__("$4") = work.local[0];
        register int localY __asm__("$5") = work.local[1];
        register int firstProduct __asm__("$3") = localX*D_80065920[bounds->angle];
        register int secondProduct __asm__("$2") = localY*D_800658A0[bounds->angle];
        __asm__("" : "=r"(firstProduct), "=r"(secondProduct) : "0"(firstProduct), "1"(secondProduct));
        work.delta.x = (firstProduct + secondProduct) >> 12;
        firstProduct = -localX*D_800658A0[bounds->angle];
        secondProduct = localY*D_80065920[bounds->angle];
        __asm__("" : "=r"(firstProduct), "=r"(secondProduct) : "0"(firstProduct), "1"(secondProduct));
        work.delta.y = (firstProduct + secondProduct) >> 12;
    }
    DecodedBoundsAdd(output,&work.delta,bounds);
}

void func_level_31_8008838C(Moby* moby, DecodedActorTransition* tag, int state) {
    if (!tag->actor) {
        tag->actor = SpawnMoby(tag->selector, moby);
        if (tag->actor) {
            func_8003BABC(tag->actor, 0, 0);
            tag->actor->position.z -= moby->distanceToGround;
            *(short*)((char*)tag + 0xA) = 0x20;
            tag->actor->size = 0x20;
            tag->actor->angle.yaw = moby->angle.yaw;
        }
    }
    tag->reserved04 = 0x12C;
    moby->colour.r = 0x40;
    moby->colour.g = 0x40;
    moby->colour.b = 0xF0;
    *((int*)moby + 2) = 0;
    moby->colour.a = 0x3A;
    if (moby->state != state) {
        tag->state = moby->state;
        tag->byte41 = moby->unknown3[0];
        moby->unknown3[0] = 0;
        moby->state = state;
        *((unsigned char*)moby + 0x47) -= 2;
    }
}

/* SCUS-94467 Rev0 8008849C..8008866C,116 original words.
 * Reuses upstream Moby fields, SpawnMoby and vector/animation interfaces.
 * Tag access widths, unsigned byte wrap, unsigned /24 and raw constants
 * 1/2/6/8/48 are original. Colour subtraction wraps as unsigned bytes;
 * /24 is native unsigned C division, not a hand-written magic multiplier.
 * Positions retain raw32-bit components and signed distance halfword reads.
 * Units, tag/table producers, helper effects and cadence remain unresolved.
 * Empty constraints emit no instructions and preserve GCC2.7.2 lifetimes.
 * AI-generated reconstruction; not yet human reviewed. */
typedef struct { Moby* spawned; short timer; unsigned char state,byte7; short mobyClass; unsigned short size; } DecodedSpawnFadeTag;
void func_80034F40(Moby*,int);
int func_800359A4(void*,int);
void func_80055D24(Moby*,int);
void func_80034F80(Moby*,int);
int func_level_31_8008849C(Moby* argument,DecodedSpawnFadeTag* data) {
    register Moby* moby __asm__("$17");
    register DecodedSpawnFadeTag* tag __asm__("$18");
    register Moby* child __asm__("$16");
    moby = argument;
    __asm__("" : "=r"(moby) : "0"(moby));
    tag = data;
    __asm__("" : "=r"(tag) : "0"(tag));
    if (tag->spawned) {
        func_8004F178(&tag->spawned->position,&moby->position);
        tag->spawned->position.z -= moby->distanceToGround;
        func_80055D24(tag->spawned,2);
    }
    if (func_800359A4(&tag->timer,2)) {
        if (tag->spawned) {
            func_80034F40(tag->spawned,1);
            child = SpawnMoby(tag->mobyClass,tag->spawned);
            if (child) {
                func_80034F80(child,6);
                child->unknownCollision = 0;
            }
        }
        tag->spawned = 0;
        func_80055D24(moby,1);
        if (moby->colour.r) moby->colour.r -= 8;
        if (moby->colour.g) moby->colour.g -= 8;
        if (moby->colour.b) {
            moby->colour.b -= 8;
            if (moby->colour.b) {
                register unsigned char alpha __asm__("$2") = ((unsigned int)moby->colour.b / 24) | 48;
                moby->colour.a = alpha;
                goto pending;

            }
        }
        {
            register int byte7 __asm__("$2") = tag->byte7;
            register int flags __asm__("$3") = moby->unknown4;
            register int state __asm__("$4");
            register int result __asm__("$2");
            moby->unknown3[0] = byte7;
            result = 1;
            __asm__("" : "=r"(result) : "0"(result));
            state = tag->state;
            flags += 2;
            moby->colour.r = 0;
            moby->colour.g = 0;
            moby->colour.b = 0;
            moby->colour.a = 0;
            moby->unknown4 = flags;
            moby->state = state;
            return result;
        }
    }
    if (!tag->spawned) {
        Moby* spawned = SpawnMoby(tag->mobyClass,moby);
        tag->spawned = spawned;
        if (spawned) {
            spawned->size = tag->size;
            tag->spawned->angle.yaw = moby->angle.yaw;
        }
    }
pending:
    return 0;
}

void func_800391E8(int, int, Moby*, int, int, int, int);
int func_level_31_8008866C(Moby* moby, DecodedActorTransition* tag, int state) {
    if (tag->actor) {
        func_8003BABC(tag->actor, 1, 0);
        func_800391E8(6, tag->selector, tag->actor, 2, 5, 0x40, 0x100);
        func_80055B18(tag->actor);
        tag->actor = 0;
    }
    if (moby->state == state) {
        moby->unknown3[0] = tag->byte41;
        __asm__("" : : : "memory");
        {
        register int byte47 __asm__("$2") = *((unsigned char*)moby + 0x47);
        register int nextState __asm__("$3") = tag->state;
        __asm__("" : "=r"(byte47), "=r"(nextState) : "0"(byte47), "1"(nextState));
        *((unsigned char*)moby + 0x47) = byte47 + 2;
        moby->state = nextState;
        }
        func_80055D24(moby, 1);
        return 1;
    }
    return 0;
}

int rand(void);
int func_level_31_80088738(Moby* moby) {
    Vector3D velocity;
    char* particle;
    register int randomValue __asm__("$2");
    register unsigned int halfword __asm__("$3");
    int index = 0;
    do {
        velocity.x = (rand() & 0xF) - 8;
        velocity.y = (rand() & 0xF) - 8;
        velocity.z = (rand() & 0xF) + 8;
        particle = SpawnParticle(1, 0x37, &moby->position, &velocity);
        if (particle) *(short*)(particle + 8) += rand() & 0xFF;
        index++;
    } while (index < 2);
    if (!moby->colour.a) {
        moby->colour.r = 0x80;
        moby->colour.g = 0x80;
        moby->colour.b = 0x80;
        moby->colour.a = 0x30;
    } else if (moby->colour.r >= 8) {
        moby->colour.r -= 8;
        moby->colour.g -= 8;
        moby->colour.b -= 8;
        moby->colour.a = (15 - (moby->colour.b >> 3)) | 0x30;
    } else {
        index = 0;
        do {
            velocity.x = (rand() & 0x3F) - 0x20;
            velocity.y = (rand() & 0x3F) - 0x20;
            velocity.z = (rand() & 0x3F) + 0x20;
            particle = SpawnParticle(1, 0x37, &moby->position, &velocity);
            if (particle) {
                randomValue = rand();
                halfword = *(unsigned short*)(particle + 4);
                __asm__("" : "=r"(randomValue) : "0"(randomValue), "r"(halfword));
                randomValue &= 0x7F;
                halfword -= 0x3F;
                __asm__("" : "=r"(halfword) : "0"(halfword), "r"(randomValue));
                halfword += randomValue;
                __asm__("" : "=r"(halfword) : "0"(halfword));
                *(short*)(particle + 4) = halfword;
                randomValue = rand();
                halfword = *(unsigned short*)(particle + 6);
                __asm__("" : "=r"(randomValue) : "0"(randomValue), "r"(halfword));
                randomValue &= 0x7F;
                halfword -= 0x3F;
                __asm__("" : "=r"(halfword) : "0"(halfword), "r"(randomValue));
                halfword += randomValue;
                __asm__("" : "=r"(halfword) : "0"(halfword));
                *(short*)(particle + 6) = halfword;
                *(short*)(particle + 8) += rand() & 0x7F;
            }
            index++;
        } while (index < 16);
        return 1;
    }
    return 0;
}

void func_level_31_8008892C(Moby* moby) {
    moby->colour.r += 2;
    moby->colour.g += 2;
    moby->colour.b += 2;
    if (moby->colour.r >= 0x80) {
        moby->colour.r = 0;
        moby->colour.g = 0;
        moby->colour.b = 0;
        moby->colour.a = 0;
    } else moby->colour.a = (0xF - (moby->colour.b >> 3)) | 0x30;
}

extern int D_8006C578, D_8006C574;
extern short D_80065920[], D_800658A0[];
extern unsigned char DecodedBatchPlayer[] __asm__("D_80070328");
void DecodedBatchZero(Vector3D*) __asm__("func_8004F168");
void DecodedBatchCopy(Vector3D*, Vector3D*) __asm__("func_8004F178");
void DecodedBatchAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
void DecodedBatchRotate(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int DecodedBatchLength(Vector3D*, int) __asm__("func_8004EDE8");
void DecodedBatchScale(Vector3D*, int, int) __asm__("func_8004F08C");
void DecodedBatchMode(Moby*, int) __asm__("func_80055D24");
int DecodedBatchRandom(int, int) __asm__("func_8003636C");
int DecodedBatchAngle(int, int, int) __asm__("func_8004E880");
void DecodedBatchAnimation(Moby*, int) __asm__("func_80034F80");
int rand(void);
/* Rev 0 representative: level_10 0x80084418..0x80084B04.
 * Preserve the original signed divisions, halfword truncation, class/flag
 * branches and ordered random calls. Empty asm constraints emit no code;
 * they retain the original compiler's argument and temporary lifetimes.
 * AI generated; not yet human reviewed. See the batch provenance document.
 */
void func_level_31_80088990(int count, int childClass, Moby* sourceMoby, Vector3D* offsets, int firstAnimation, int argument5) {
    Vector3D average;
    int reserved1C;
    Vector3D temporary;
    int reserved2C;
    Vector3D impulse;
    int reserved3C;
    struct { int childClass; int reserved44; Vector3D* offsets; } saved;
    int reservedStack[4];
    register int index __asm__("$19");
    register Moby* source __asm__("$18") = sourceMoby;
    register Moby* child __asm__("$17");
    register short* tag __asm__("$16");
    register Vector3D* temporaryPtr __asm__("$20");
    register unsigned char* player __asm__("$22");
    register short* sine __asm__("$23");
    short* cosine;
    Vector3D* cursor;
    int averageX, averageY, averageZ;
    int randomLow, randomHigh, angle;
    register int impulseX __asm__("$3");
    register int sample0 __asm__("$2");
    register int sample4 __asm__("$4");
    register short* samplePointer __asm__("$4");
    register unsigned int trigByteOffset __asm__("$4");
    register Vector3D* averageArgument __asm__("$4");
    register int offsetArgument __asm__("$5");
    register Vector3D* copyArgument __asm__("$4");
    register Vector3D* offsetBase __asm__("$8");
    register int stackArgument4 __asm__("$8");
    register unsigned int stackArgument5 __asm__("$8");
    __asm__("" : "=r"(source) : "0"(source));
    averageArgument = &average;
    __asm__("" : : "r"(averageArgument));
    saved.childClass = childClass;
    saved.offsets = offsets;
    DecodedBatchZero(averageArgument);
    __asm__("" : "=m"(saved) : "m"(saved));
    index = 0;
    if (count > 0) {
        cursor = saved.offsets;
        do {
            DecodedBatchAdd(&average, &average, cursor);
            index++;
            cursor++;
        } while (index < count);
    }
    /* Native division retains the retail zero and overflow traps. */
    averageX = average.x / count;
    averageY = average.y / count;
    averageZ = average.z / count;
    average.x = averageX;
    average.y = averageY;
    average.z = averageZ;
    {
        register int modeArgument __asm__("$5") = 4;
        __asm__("" : "=r"(index) : "0"(0), "r"(modeArgument));
        DecodedBatchMode(source, modeArgument);
    }
    temporaryPtr = &temporary;
    if (count <= 0) return;
    cosine = D_80065920;
    sine = D_800658A0;
    player = DecodedBatchPlayer;
    __asm__("" : "=r"(cosine) : "0"(cosine), "r"(sine), "r"(player), "r"(temporaryPtr));
    do {
        /* Capacity exhaustion ends the whole spawn request. */
        if (D_8006C578 - D_8006C574 < 21) return;
        __asm__("" : "=m"(saved) : "m"(saved));
        child = SpawnMoby(saved.childClass, source);
        __asm__("" : "=r"(child) : "0"(child));
        copyArgument = temporaryPtr;
        if (child != 0) {
            offsetArgument = index * 12;
            __asm__("" : "=r"(offsetArgument) : "0"(offsetArgument), "r"(copyArgument));
            offsetBase = saved.offsets;
            tag = child->mobyTag;
            DecodedBatchCopy(copyArgument, (Vector3D*)((char*)offsetBase + offsetArgument));
            DecodedBatchRotate(&source->rotationMatrix, temporaryPtr, temporaryPtr);
            tag[0] = (temporary.x - average.x) >> 2;
            tag[1] = (temporary.y - average.y) >> 2;
            tag[2] = (temporary.z - average.z) >> 2;
            DecodedBatchAdd(&child->position, temporaryPtr, &source->position);
            if (source->mobyClass == 254) {
                child->size = 20;
                child->position.z += 1000;
                tag[0] = (unsigned short)tag[0] + ((cosine[source->unkb] * 5) >> 8);
                tag[1] = (unsigned short)tag[1] + ((sine[source->unkb] * 5) >> 8);
                randomLow = 250;
                randomHigh = 350;
                goto randomZ;
            } else if (source->mobyClass == 132) {
                tag[0] = tag[0] * 3 / 2;
                tag[1] = tag[1] * 3 / 2;
                tag[2] = tag[2] * 2;
                goto finish;
            } else if (source->mobyClass == 999) {
                if (*(int*)(DecodedBatchPlayer + 0x48) == 42) {
                    DecodedBatchCopy(temporaryPtr, (Vector3D*)(DecodedBatchPlayer + 0x8C));
                    DecodedBatchScale(temporaryPtr, DecodedBatchLength(temporaryPtr, 0), 300);
                    tag[0] = (unsigned short)tag[0] + temporary.x;
                    tag[1] = (unsigned short)tag[1] + temporary.y;
                } else {
                    temporary.x = 140;
                    temporary.y = 0;
                    temporary.z = 0;
                    /* The original class-999 branch passes a null matrix. */
                    DecodedBatchRotate(0, temporaryPtr, temporaryPtr);
                    tag[0] = (unsigned short)tag[0] + temporary.x;
                    tag[1] = (unsigned short)tag[1] + temporary.y;
                    tag[2] = (unsigned short)tag[2] + temporary.z;
                }
                goto finish;
            } else if (source->unkb != 0 && (source->damageFlags & 0x100000)) {
                tag[0] = (unsigned short)tag[0] + ((cosine[source->unkb] * 75) >> 11);
                tag[1] = (unsigned short)tag[1] + ((sine[source->unkb] * 75) >> 11);
                randomLow = 40;
                randomHigh = 70;
randomZ:
                tag[2] = (unsigned short)tag[2] + DecodedBatchRandom(randomLow, randomHigh);
                goto finish;
            } else if (source->damageFlags & 0x40000) {
                tag[0] = (unsigned short)tag[0] + (*(int*)(DecodedBatchPlayer + 0x8C) >> 5);
                tag[1] = (unsigned short)tag[1] + (*(int*)(DecodedBatchPlayer + 0x90) >> 5);
                goto finish;
            } else if (source->damageFlags & 0x2000000) {
                sample0 = cosine[DecodedBatchAngle(child->position.x - *(int*)player, child->position.y - *(int*)(player + 4), 0)];
                __asm__("" : "=r"(sample0) : "0"(sample0));
                impulse.x = sample0 >> 4;
                sample0 = sine[DecodedBatchAngle(child->position.x - *(int*)player, child->position.y - *(int*)(player + 4), 0)];
                __asm__("" : "=r"(sample0) : "0"(sample0));
                impulseX = impulse.x;
                impulse.y = sample0 >> 4;
                impulse.z = 0;
                __asm__("" : : "m"(impulse.z), "r"(impulseX));
            } else if ((source->damageFlags & 0x20000) && (*(int*)(DecodedBatchPlayer + 0x50) == 4 || *(int*)(DecodedBatchPlayer + 0x50) == 12)) {
                tag[0] = (unsigned short)tag[0] + (*(int*)(DecodedBatchPlayer + 0x8C) >> 6);
                tag[1] = (unsigned short)tag[1] + (*(int*)(DecodedBatchPlayer + 0x90) >> 6);
                goto finish;
            } else {
                if (source->mobyClass == 132) goto finish;
                angle = source->unkb;
                if (angle == 0) angle = DecodedBatchAngle(child->position.x - *(int*)player, child->position.y - *(int*)(player + 4), 0);
                trigByteOffset = angle * 2;
                __asm__("" : "=r"(trigByteOffset) : "0"(trigByteOffset));
                sample0 = *(short*)(trigByteOffset + (unsigned int)cosine);
                __asm__("" : "=r"(trigByteOffset) : "0"(trigByteOffset), "r"(sample0));
                samplePointer = (short*)(trigByteOffset + (unsigned int)sine);
                __asm__("" : "=r"(sample0), "=r"(samplePointer) : "0"(sample0), "1"(samplePointer));
                impulseX = (sample0 * 35) >> 10;
                impulse.x = impulseX;
                sample4 = *samplePointer;
                __asm__("" : "=r"(sample4) : "0"(sample4));
                impulse.y = (sample4 * 35) >> 10;
                impulse.z = 0;
                __asm__("" : : "m"(impulse.z), "r"(impulseX));
            }
            tag[0] = (unsigned short)tag[0] + impulseX;
            tag[1] = (unsigned short)tag[1] + impulse.y;
finish:
            child->angle.roll = source->angle.roll;
            child->angle.pitch = source->angle.pitch;
            child->angle.yaw = source->angle.yaw;
            /* Keep the random calls in their original order. */
            tag[3] = (rand() & 6) - 3;
            tag[4] = (rand() & 6) - 3;
            tag[5] = (rand() & 6) - 3;
            tag[7] = source->position.z - 64;
            {
                int lifetime = DecodedBatchRandom(30, 50);
                register int animationArgument __asm__("$5");
                __asm__("" : "=m"(firstAnimation), "=m"(argument5) : "m"(firstAnimation), "m"(argument5));
                stackArgument4 = *(int*)&firstAnimation;
                tag[6] = lifetime;
                tag[8] = 8;
                animationArgument = stackArgument4 + index;
                stackArgument5 = *(unsigned short*)&argument5;
                __asm__("" : "=r"(stackArgument5) : "0"(stackArgument5));
                tag[9] = stackArgument5;
                DecodedBatchAnimation(child, animationArgument);
            }
            *(int*)(tag + 10) = 1;
            child->unknownCollision = 0;
        }
        index++;
    } while (index < count);
}

/*
 * USA SCUS-94467 Rev 0: representative func_level_11_80086468,
 * 0x80086468..0x800869E4 (352 instructions). Per-copy evidence is
 * recorded in overlay-batch-2026-10-04-1268.md.
 * Packet fields follow the retail store offsets, including byte colour
 * truncation and signed halfword coordinates. Empty asm constraints emit
 * no instructions; they retain GCC 2.7.2 register allocation/store order.
 * AI-generated reconstruction; not yet human reviewed.
 */
typedef struct {
    unsigned int tag;
    unsigned char red, green, blue, code;
    short x0, y0, x1, y1;
} DecodedHudLine;
typedef struct {
    unsigned int tag;
    unsigned char red0, green0, blue0, code;
    short x0, y0;
    unsigned char red1, green1, blue1, reserved0F;
    short x1, y1;
    unsigned char red2, green2, blue2, reserved17;
    short x2, y2;
    unsigned char red3, green3, blue3, reserved1F;
    short x3, y3;
} DecodedHudQuad;
extern unsigned char* DecodedHudPacketCursor __asm__("D_8006C664");
int DecodedHudSprite(SpriteData*, int, int) __asm__("func_800289C8");
int func_level_31_80089080(HudEntry* argument) {
    int x, y, verticalOffset, reserved1C, barY, reserved24;
    HudEntry* hud = argument;
    register int top __asm__("$20");
    register int bottom __asm__("$17");
    register unsigned int lineTag __asm__("$18");
    register int lineCode __asm__("$19");
    register int colour __asm__("$16");
    register DecodedHudLine* line __asm__("$22");
    register DecodedHudLine* lineArgument __asm__("$4");
    register SpriteData* sprite __asm__("$23");
    register DecodedHudQuad* quad __asm__("$19");
    register DecodedHudQuad* quadArgument __asm__("$4");
    register int width __asm__("$21");
    register int result __asm__("$3");
    register int centredY __asm__("$16");
    register int* xArgument __asm__("$5") = &x;
    register int* yArgument __asm__("$6");
    __asm__("" : : "r"(xArgument));
    {
        register int frame __asm__("$2") = (unsigned char)hud->unk1C.frame;
        register int initialX __asm__("$3");
        register int initialY __asm__("$7");
        register SpriteData* sprites __asm__("$3");
        __asm__("" : "=r"(frame) : "0"(frame));
        initialX = hud->unk0;
        initialY = hud->unk2;
        __asm__("" : : "r"(initialX), "r"(initialY) : "$6");
        yArgument = &y;
        __asm__("" : : "r"(initialX), "r"(initialY), "r"(yArgument));
        x = initialX;
        sprites = D_8006C788;
        __asm__("" : "=r"(frame) : "0"(frame), "r"(sprites));
        frame *= 8;
        __asm__("" : "=r"(frame) : "0"(frame));
        y = initialY;
        __asm__ volatile("" : : "m"(y));
        sprite = (SpriteData*)((int)sprites + frame);
    }
    /* Apply the existing HUD position and movement helpers. */
    func_80029674(hud, xArgument, yArgument);
    if ((unsigned char)hud->movementFrame) {
        verticalOffset = ((unsigned char)hud->movementFrame + 10) >> 1;
    } else {
        verticalOffset = 0;
    }
    func_80029708(hud, &verticalOffset, &x, &y);
    {
        register int height __asm__("$2") = sprite->unk5;
        register int low __asm__("$3") = sprite->unk1;
        register int storedY __asm__("$3");
        __asm__("" : : "r"(height), "r"(low));
        height -= low;
        __asm__("" : "=r"(height) : "0"(height));
        storedY = y;
        centredY = storedY - (height >> 1);
        y = centredY;
    }
    /* Select the retail bar origin from the sprite bounds. */
    if (hud->displayMode & 1) {
        centredY++;
        __asm__("" : "=r"(centredY) : "0"(centredY));
        barY = centredY;
    } else {
        register int edge __asm__("$2") = centredY + sprite->unk5;
        edge -= sprite->unk1;
        edge -= 7;
        __asm__("" : "=r"(edge) : "0"(edge));
        barY = edge;
    }
    /* Bit 3 places the bordered bar before the sprite. */
    if (hud->displayMode & 8) {
        lineCode = 64;
        colour = 192;
        lineTag = 0x03000000;
        line = (DecodedHudLine*)DecodedHudPacketCursor;
        top = barY - 1;
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(line);
        line++;
        lineArgument = line;
        __asm__("" : "=r"(lineArgument) : "0"(lineArgument));
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->y0 = top;
        __asm__ volatile("" : : : "memory");
        bottom = barY + 6;
        __asm__("" : "=r"(bottom) : "0"(bottom));
        line->y1 = bottom;
        line->x1 = x + 96;
        line->x0 = x + 96;
        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        __asm__("" : "=r"(lineArgument) : "0"(lineArgument));
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = colour;
        line->green = colour;
        line->blue = 0;
        line->y1 = bottom;
        line->y0 = bottom;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(lineArgument);
        line++;
        __asm__("" : "=r"(line) : "0"(line));
        {
            register DecodedHudLine* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            __asm__("" : "=r"(lastLine) : "0"(lastLine));
            lastLine->code = lineCode;

            lastLine->red = colour;
            lastLine->green = colour;
            lastLine->blue = 0;
            __asm__ volatile("" : : : "memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (DecodedHudQuad*)(lastLine + 1);
            __asm__("" : "=r"(quad) : "0"(quad));
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = bottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        /* Four border lines are followed by one gradient quad. */
        quad->tag = 0x08000000;
        quad->code = 56;
        {
            int channel = -32 - hud->unk40 * 224 / 96;
            __asm__("" : "=r"(channel) : "0"(channel));
            quad->red0 = quad->red2 = channel;
            __asm__ volatile("" : : "m"(quad->red0), "m"(quad->red2));
        }
        {
            register int numerator __asm__("$3") = hud->unk40 * 224;
            int greenChannel;
            __asm__("" : "=r"(quad) : "0"(quad), "r"(numerator));
            greenChannel = numerator / 96;
            quad->blue0 = quad->blue2 = 0;
            quad->green1 = quad->green3 = 0;
            quad->blue1 = quad->blue3 = 0;
            __asm__("" : "=r"(quad) : "0"(quad));
            quadArgument = quad;
            __asm__("" : : "r"(quadArgument));
            quad->red1 = quad->red3 = 224;
            quad->green0 = quad->green2 = greenChannel;
        }
        __asm__ volatile("" : : : "memory");
        {
            register int value __asm__("$3") = hud->unk40;
            register int barCoordinate __asm__("$2");
            register int coordinate __asm__("$2");
            __asm__ volatile("" : : : "memory");
            barCoordinate = (unsigned short)barY;
            __asm__("" : "=r"(barCoordinate) : "0"(barCoordinate));
            quad->y2 = quad->y3 = bottom;
            quad->y0 = quad->y1 = barCoordinate;
            __asm__ volatile("" : : : "memory");
            coordinate = x;
            __asm__("" : "=r"(value) : "0"(value), "r"(coordinate));
            value -= 96;
            value = coordinate - value;
            __asm__("" : "=r"(value) : "0"(value));
            coordinate += 96;
            quad->x0 = quad->x2 = value;
            quad->x1 = quad->x3 = coordinate;
            func_8004E758(quadArgument);
        }
        quad++;
        DecodedHudPacketCursor = (unsigned char*)quad;
        x += 106;
        DecodedHudSprite(sprite, x, y);
        {
            register int spriteWidth __asm__("$2") = sprite->unk4;
            register int left __asm__("$3") = sprite->unk0;
            __asm__("" : : "r"(spriteWidth), "r"(left));
            spriteWidth -= left;
            __asm__("" : "=r"(spriteWidth) : "0"(spriteWidth));
            result = spriteWidth + 106;
        }
    } else {
        /* The other branch draws the sprite before the bordered bar. */
        register int defaultColour __asm__("$17");
        register int defaultBottom __asm__("$16");
        {
            register SpriteData* spriteArgument __asm__("$4") = sprite;
            register int callX __asm__("$5");
            int origin;
            register int callY __asm__("$6");
            __asm__("" : : "r"(spriteArgument));
            callX = x;
            __asm__("" : "=r"(callX) : "0"(callX));
            origin = barY;
            callY = y;
            top = origin - 1;
            DecodedHudSprite(spriteArgument, callX, callY);
        }
        lineCode = 64;
        defaultColour = 192;
        lineTag = 0x03000000;
        __asm__("" : : "r"(lineCode), "r"(defaultColour), "r"(lineTag));
        width = sprite->unk4;
        __asm__("" : "=r"(width) : "0"(width));
        {
            register int left __asm__("$2") = sprite->unk0;
            line = (DecodedHudLine*)DecodedHudPacketCursor;
            __asm__("" : "=r"(left) : "0"(left), "r"(line));
            width -= left;
        }
        {
            register int currentX __asm__("$2") = x;
            register int offset __asm__("$3");
            __asm__("" : "=r"(width) : "0"(width), "r"(currentX));
            offset = width + 10;
            __asm__("" : "=r"(offset) : "0"(offset));
            x = currentX + offset;
        }

        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->tag = lineTag;
        line->y1 = top;
        line->y0 = top;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(line);
        line++;
        lineArgument = line;
        __asm__("" : "=r"(lineArgument) : "0"(lineArgument));
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->y0 = top;
        __asm__ volatile("" : : : "memory");
        defaultBottom = barY + 6;
        __asm__("" : "=r"(defaultBottom) : "0"(defaultBottom));
        line->y1 = defaultBottom;
        line->x1 = x + 96;
        line->x0 = x + 96;
        func_8004E758(lineArgument);
        line++;
        lineArgument = line;
        __asm__("" : "=r"(lineArgument) : "0"(lineArgument));
        line->tag = lineTag;
        __asm__ volatile("" : : "m"(line->tag));
        line->code = lineCode;
        line->red = 0;
        line->green = 0;
        line->blue = defaultColour;
        line->y1 = defaultBottom;
        line->y0 = defaultBottom;
        line->x0 = x - 1;
        line->x1 = x + 96;
        func_8004E758(lineArgument);
        line++;
        __asm__("" : "=r"(line) : "0"(line));
        {
            register DecodedHudLine* lastLine __asm__("$4") = line;
            register int xValue __asm__("$2");
            __asm__("" : "=r"(lastLine) : "0"(lastLine));
            lastLine->code = lineCode;

            lastLine->red = 0;
            lastLine->green = 0;
            lastLine->blue = defaultColour;
            __asm__ volatile("" : : : "memory");
            xValue = x;
            __asm__("" : "=r"(lastLine) : "0"(lastLine), "r"(xValue));
            quad = (DecodedHudQuad*)(lastLine + 1);
            __asm__("" : "=r"(quad) : "0"(quad));
            lastLine->tag = lineTag;
            lastLine->y0 = top;
            lastLine->y1 = defaultBottom;
            lastLine->x1 = xValue - 1;
            lastLine->x0 = xValue - 1;
            func_8004E758(lastLine);
        }
        /* Four border lines are followed by one gradient quad. */
        quad->tag = 0x08000000;
        quad->code = 56;
        quad->red0 = quad->red2 = 224;
        quad->green0 = quad->green2 = 0;
        quad->blue0 = quad->blue2 = 0;
        {
            int channel = -32 - hud->unk40 * 224 / 96;
            __asm__("" : "=r"(channel) : "0"(channel));
            quad->red1 = quad->red3 = channel;
            __asm__ volatile("" : : "m"(quad->red1), "m"(quad->red3));
        }
        {
            register int numerator __asm__("$2") = hud->unk40 * 224;
            int greenChannel;
            __asm__("" : "=r"(quad) : "0"(quad), "r"(numerator));
            greenChannel = numerator / 96;
            quad->blue1 = quad->blue3 = 0;
            __asm__("" : "=r"(quad) : "0"(quad));
            quad->green1 = quad->green3 = greenChannel;
        }
        __asm__ volatile("" : : : "memory");
        {
            register int currentX __asm__("$5") = x;
            register DecodedHudQuad* argument __asm__("$4");
            register int coordinate __asm__("$2");
            register int barCoordinate __asm__("$2");
            register int value __asm__("$3");
            __asm__("" : : "r"(currentX) : "$4");
            argument = quad;
            __asm__("" : : "r"(argument));
            coordinate = currentX;
            quad->x0 = quad->x2 = coordinate;
            __asm__ volatile("" : : : "memory");
            value = hud->unk40;
            __asm__ volatile("" : : : "memory");
            barCoordinate = (unsigned short)barY;
            __asm__("" : "=r"(barCoordinate) : "0"(barCoordinate));
            quad->y2 = quad->y3 = defaultBottom;
            value += currentX;
            __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
            quad->y0 = quad->y1 = barCoordinate;
            quad->x1 = quad->x3 = value;
            func_8004E758(argument);
        }
        quad++;
        DecodedHudPacketCursor = (unsigned char*)quad;
        result = width + 116;
    }
    __asm__("" : "=r"(result) : "0"(result));
    return result;
}

void func_level_31_80089600(HudEntry* hud) {
    int value, maximum;
    func_80027D60(hud);
    hud->unk3C += 0x6A;
    if (hud->unk28 != 0) {
        value = *hud->unk28;
        maximum = hud->unk26;
        if (value > maximum) value = maximum;
        if (value < 0) value = 0;
        hud->unk40 = hud->unk42 = value * 96 / maximum;
    }
}

void func_level_31_800896A8(HudEntry* hud) {
    int value, maximum, current;
    if (hud->unk28 != 0) {
        value = *hud->unk28;
        maximum = hud->unk26;
        if (value > maximum) value = maximum;
        if (value < 0) value = 0;
        value = value * 96 / maximum;
        if (value < 0) value = 0;
        current = hud->unk40;
        hud->unk42 = value;
        if ((unsigned short)current < hud->unk42) hud->unk40 = current + 1;
        else if (hud->unk42 < (unsigned short)current) hud->unk40 = current - 1;
        if (*hud->unk28 > 0 && hud->unk40 == 0) hud->unk40 = 1;
    }
    func_8002798C(hud);
}

#define Timer86B88High(a,b) ({ int high; __asm__ __volatile__("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory"); high; })
#define Timer86B88Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern int Timer86B88Motion __asm__("D_8006C64C");
extern unsigned char *Timer86B88SpriteBase __asm__("D_8006C788");
extern short Timer86B88DigitBase __asm__("D_800719CC");
int Timer86B88Place(void*,int*,int*,int*) __asm__("func_80029708");
int Timer86B88Draw(void*,int,int) __asm__("func_800289C8");
/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 356-instruction timer family is the authority. Byte access widths,
 * signed high products, shifts and draw argument sequences retain the disc
 * representation. Counter time units, caller cadence and helper contracts
 * remain unresolved; divisor-based names describe arithmetic only.
 * The high-product constraint follows the existing drawutil.c MULT_HI idiom.
 * Empty constraints emit no instructions. Acceptance requires full retail
 * hashes and unmasked linked instruction words, not a semantic runtime claim.
 */
int func_level_31_800897A0(void *input) {
    register unsigned char *owner __asm__("$21");
    struct {int drawOrdinal,drawPositionX,drawPositionY,pad1C,quotient3600,pad24,digitWidth,pad2C,divide10Multiplier,pad34;
    } frame;
    int *counterPointer;
    register int singleLeadingDigit __asm__("$2");
    int motionFlags;
    register int entryFlags __asm__("$4");
    register int *horizontalOutput __asm__("$23");
    register int *verticalOutput;
    register void *drawOwner __asm__("$4");
    register int *drawIndex __asm__("$5");
    register int *drawX __asm__("$6");
    register int *drawY __asm__("$7");
    register int digitQuotient __asm__("$16");
    register unsigned char *sprite __asm__("$17");
    register int index __asm__("$18");
    register int x __asm__("$19");
    register int remainder60 __asm__("$20");
    register int y __asm__("$22");
    register int counter __asm__("$9");
    register int quotient60 __asm__("$10");
    register int scaled __asm__("$3");
    register int scaledRemainder __asm__("$8");
    register int counterSign __asm__("$11");
    {register int digit __asm__("$2")=Timer86B88DigitBase;
     register unsigned char *base __asm__("$3")=Timer86B88SpriteBase;
     register int width __asm__("$2");
     register int other __asm__("$3");
     owner=input;
     __asm__ __volatile__("" : : "r"(owner),"r"(digit),"r"(base) : "$4");
     x=Timer86B88Field(owner,short*,0);
     __asm__("" : "=r"(x),"=r"(digit),"=r"(base) : "0"(x),"1"(digit),"2"(base));
     digit<<=3;
     sprite=base+digit;
     width=Timer86B88Field(sprite,unsigned char*,5);
     other=Timer86B88Field(sprite,unsigned char*,1);
     {register int flags __asm__("$4")=Timer86B88Field(owner,unsigned char*,24);
     __asm__("" : "=r"(width),"=r"(other),"=r"(flags) : "0"(width),"1"(other),"2"(flags));
     motionFlags=flags;
     }
     width-=other;
     other=Timer86B88Field(owner,short*,2);
     width>>=1;
     y=other-width;
     }
    if (motionFlags & 2) {
        y -= Timer86B88Motion;
    } else if (motionFlags & 1) {
        y += Timer86B88Motion;
    }
    {register int width __asm__("$3")=Timer86B88Field(sprite,unsigned char*,4);
     register int other __asm__("$2")=Timer86B88Field(sprite,unsigned char*,0);
     entryFlags=Timer86B88Field(owner,unsigned char*,63);
     __asm__("" : "=r"(width),"=r"(other),"=r"(entryFlags) : "0"(width),"1"(other),"2"(entryFlags));
     width-=other;
     frame.digitWidth=width;
     if(entryFlags) {other=entryFlags+10;
     __asm__("" : "=r"(other) : "0"(other));
     index=other>>1;
     }
     else {__asm__("" ::: "$4");
     index=0;
     }}
    counterPointer = Timer86B88Field(owner, int **, 0x28);
    counter=*counterPointer;
    {register int magic60 __asm__("$4")=(int)0x88888889;
     register int magic10 __asm__("$12");
     register int width __asm__("$13");
     register int value __asm__("$2");
     register int highFirst __asm__("hi");
     register int highSecond __asm__("hi");
     register int highTens __asm__("hi");
     register int highMinutes __asm__("hi");
     register int digit __asm__("$3");
     register unsigned char *base __asm__("$2");
     highFirst=Timer86B88High(counter,magic60);
     counterSign=counter>>31;
     {register int word __asm__("$12")=highFirst;
      __asm__("" : "=r"(word),"=r"(counterSign) : "0"(word),"1"(counterSign));
      quotient60=((word+counter)>>5)-counterSign;
      }
     value=counter-quotient60*60;
     scaled=value*100;
     highSecond=Timer86B88High(scaled,magic60);
     drawIndex=&frame.drawOrdinal;
     horizontalOutput=&frame.drawPositionX;
     width=frame.digitWidth;
     drawX=horizontalOutput;
     x-=width;
     __asm__("" : "=r"(drawIndex),"=r"(horizontalOutput),"=r"(drawX),"=r"(x) : "0"(drawIndex),"1"(horizontalOutput),"2"(drawX),"3"(x),"r"(width) : "$12");
     magic10=0x66666667;
     {register int word __asm__("$13")=highSecond;
      __asm__("" : "=r"(word) : "0"(word));
      scaledRemainder=((word+scaled)>>5)-(scaled>>31);
      }
     highTens=Timer86B88High(scaledRemainder,magic10);
     verticalOutput=&frame.drawPositionY;
     drawY=verticalOutput;
     __asm__("" : "=r"(drawY) : "0"(drawY));
     frame.drawOrdinal=index;
     index--;
     frame.drawPositionX=x;
     frame.drawPositionY=y;
     __asm__ __volatile__("" ::: "$2","$4","memory");
     value=(int)0x91A2B3C5;
     drawOwner=owner;
     __asm__("" : "=r"(value),"=r"(drawOwner) : "0"(value),"1"(drawOwner));
     frame.divide10Multiplier=magic10;
     {register int nextWidth __asm__("$12")=frame.digitWidth;
      register int word __asm__("$13");
      __asm__("" : "=r"(nextWidth),"=h"(highTens) : "0"(nextWidth),"1"(highTens) : "memory");
      word=highTens;
      __asm__("" : "=r"(word) : "0"(word) : "$3","memory");
      digit=Timer86B88DigitBase;
      __asm__("" : "=r"(word) : "0"(word) : "memory");
      digitQuotient=word>>2;
      __asm__("" : "=r"(counter),"=r"(digit) : "0"(counter),"1"(digit),"r"(digitQuotient));
      highMinutes=Timer86B88High(counter,value);
      x-=nextWidth;
      }
     value=scaledRemainder>>31;
     digitQuotient-=value;
     scaledRemainder-=digitQuotient*10;
     digit+=scaledRemainder;
     __asm__("" : "=r"(digit) : "0"(digit) : "$2","memory");
     base=Timer86B88SpriteBase;
     __asm__("" : "=r"(digit),"=r"(base) : "0"(digit),"1"(base));
     digit<<=3;
     sprite=base+digit;
     __asm__("" : "=r"(sprite),"=h"(highMinutes) : "0"(sprite),"1"(highMinutes));
     {register int word __asm__("$12")=highMinutes;
      __asm__("" : "=r"(word) : "0"(word));
      counter=((word+counter)>>11)-counterSign;
      }
     value=counter*60;
     remainder60=quotient60-value;
     frame.quotient3600=counter;
     }
    Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
    Timer86B88Draw(sprite, frame.drawPositionX, frame.drawPositionY);
    {register int digit __asm__("$2");
     register unsigned char *base __asm__("$3");
     drawOwner=owner;
     drawIndex=&frame.drawOrdinal;
     drawX=horizontalOutput;
     __asm__("" : "=r"(drawOwner),"=r"(drawIndex),"=r"(drawX) : "0"(drawOwner),"1"(drawIndex),"2"(drawX) : "$2","$3","memory");
     digit=Timer86B88DigitBase;
     base=Timer86B88SpriteBase;
     __asm__("" : "=r"(digit) : "0"(digit) : "$7","memory");
     drawY=verticalOutput;
     __asm__("" : "=r"(digit),"=r"(drawY) : "0"(digit),"1"(drawY) : "memory");
     frame.drawOrdinal=index;
     index--;
     frame.drawPositionX=x;
     frame.drawPositionY=y;
     __asm__("" : "=r"(digit) : "0"(digit) : "memory");
     digit+=digitQuotient;
     digit<<=3;
     __asm__("" : "=r"(digit),"=r"(base) : "0"(digit),"1"(base));
     sprite=base+digit;
     Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
     Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
     }
    {register int digit __asm__("$2");
     register unsigned char *base __asm__("$3");
     register int other __asm__("$3");
     drawOwner=owner;
     drawIndex=&frame.drawOrdinal;
     drawX=horizontalOutput;
     __asm__("" : "=r"(drawOwner),"=r"(drawIndex),"=r"(drawX) : "0"(drawOwner),"1"(drawIndex),"2"(drawX) : "$2","$3","memory");
     digit=Timer86B88DigitBase;
     base=Timer86B88SpriteBase;
     digit<<=3;
     digit+=96;
     __asm__("" : "=r"(digit),"=r"(base) : "0"(digit),"1"(base) : "$7");
     sprite=base+digit;
     digit=Timer86B88Field(sprite,unsigned char*,4);
     other=Timer86B88Field(sprite,unsigned char*,0);
     drawY=verticalOutput;
     frame.drawPositionY=y;
     frame.drawOrdinal=index;
     __asm__("" : "=r"(digit),"=r"(other),"=r"(drawY) : "0"(digit),"1"(other),"2"(drawY) : "memory");
     digit-=other;
     x-=digit;
     frame.drawPositionX=x;
     Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
     Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
     }
    {register int test __asm__("$13")=frame.quotient3600;
     __asm__("" : "=r"(test) : "0"(test));
    drawIndex=&frame.drawOrdinal;
    if(test) {
        register int magic __asm__("$12");
        register int high __asm__("hi");
        register int width __asm__("$13");
        register int digit __asm__("$3");
        register int value __asm__("$2");
        register unsigned char *base __asm__("$2");
        register int word __asm__("$12");
        index--;
        drawOwner=owner;
        __asm__("" : "=r"(index),"=r"(drawOwner) : "0"(index),"1"(drawOwner) : "memory");
        magic=frame.divide10Multiplier;
        high=Timer86B88High(remainder60,magic);
        drawX=horizontalOutput;
        drawY=verticalOutput;
        frame.drawOrdinal=index;
        index--;
        width=frame.digitWidth;
        digit=Timer86B88DigitBase;
        value=remainder60>>31;
        frame.drawPositionY=y;
        __asm__("" : "=r"(drawOwner),"=r"(drawX),"=r"(drawY),"=r"(x),"=r"(value) : "0"(drawOwner),"1"(drawX),"2"(drawY),"3"(x),"4"(value) : "memory");
        x-=width;
        frame.drawPositionX=x;
        __asm__("" : "=r"(x),"=h"(high) : "0"(x),"1"(high) : "memory");
        x-=width;
        __asm__("" : "=r"(x),"=h"(high) : "0"(x),"1"(high),"r"(width));
        word=high;
        __asm__("" : "=r"(word) : "0"(word));
        digitQuotient=(word>>2)-value;
        value=remainder60-digitQuotient*10;
        digit+=value;
        __asm__("" : "=r"(digit) : "0"(digit) : "$2","memory");
        base=Timer86B88SpriteBase;
        __asm__("" : "=r"(digit),"=r"(base) : "0"(digit),"1"(base));
        digit<<=3;
        sprite=base+digit;
        Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
        Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
        {register int nextDigit __asm__("$2");
         register unsigned char *nextBase __asm__("$3");
         drawOwner=owner;
         drawIndex=&frame.drawOrdinal;
         drawX=horizontalOutput;
         __asm__("" : "=r"(drawOwner),"=r"(drawIndex),"=r"(drawX) : "0"(drawOwner),"1"(drawIndex),"2"(drawX) : "$2","$3","memory");
         nextDigit=Timer86B88DigitBase;
         nextBase=Timer86B88SpriteBase;
         __asm__("" : "=r"(nextDigit) : "0"(nextDigit) : "$7","memory");
         drawY=verticalOutput;
         __asm__("" : "=r"(nextDigit),"=r"(drawY) : "0"(nextDigit),"1"(drawY) : "memory");
         frame.drawOrdinal=index;
         index--;
         frame.drawPositionX=x;
         frame.drawPositionY=y;
         __asm__("" : "=r"(nextDigit) : "0"(nextDigit) : "memory");
         nextDigit+=digitQuotient;
         nextDigit<<=3;
         __asm__("" : "=r"(nextDigit),"=r"(nextBase) : "0"(nextDigit),"1"(nextBase));
         sprite=nextBase+nextDigit;
         Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
         Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
         }
        {register int nextDigit __asm__("$2");
         register unsigned char *nextBase __asm__("$3");
         register int other __asm__("$3");
         drawOwner=owner;
         drawIndex=&frame.drawOrdinal;
         drawX=horizontalOutput;
         __asm__("" : "=r"(drawOwner),"=r"(drawIndex),"=r"(drawX) : "0"(drawOwner),"1"(drawIndex),"2"(drawX) : "$2","$3","memory");
         nextDigit=Timer86B88DigitBase;
         nextBase=Timer86B88SpriteBase;
         nextDigit<<=3;
         nextDigit+=88;
         __asm__("" : "=r"(nextDigit),"=r"(nextBase) : "0"(nextDigit),"1"(nextBase) : "$7");
         sprite=nextBase+nextDigit;
         nextDigit=Timer86B88Field(sprite,unsigned char*,4);
         other=Timer86B88Field(sprite,unsigned char*,0);
         drawY=verticalOutput;
         frame.drawPositionY=y;
         frame.drawOrdinal=index;
         __asm__("" : "=r"(nextDigit),"=r"(other),"=r"(drawY) : "0"(nextDigit),"1"(other),"2"(drawY) : "memory");
         nextDigit-=other;
         x-=nextDigit;
         frame.drawPositionX=x;
         Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
         Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
         }
        {register int number __asm__("$13")=frame.quotient3600;
         register int factor __asm__("$12")=frame.divide10Multiplier;
         register int productHigh __asm__("hi");
         register int remainder __asm__("$2");
         register int digitBase __asm__("$3");
         register unsigned char *sprites __asm__("$2");
         __asm__("" : "=r"(index),"=r"(number),"=r"(factor) : "0"(index),"1"(number),"2"(factor));
         index--;
         productHigh=Timer86B88High(number,factor);
         drawOwner=owner;
         drawIndex=&frame.drawOrdinal;
         number=frame.digitWidth;
         drawX=horizontalOutput;
         x-=number;
         __asm__("" : "=r"(drawOwner),"=r"(drawIndex),"=r"(drawX),"=r"(x) : "0"(drawOwner),"1"(drawIndex),"2"(drawX),"3"(x),"r"(number) : "memory");
         number=frame.quotient3600;
         drawY=verticalOutput;
         frame.drawPositionY=y;
         frame.drawOrdinal=index;
         frame.drawPositionX=x;
         remainder=number>>31;
         __asm__("" : "=h"(productHigh),"=r"(remainder),"=r"(number) : "0"(productHigh),"1"(remainder),"2"(number) : "memory");
         factor=productHigh;
         __asm__("" : "=r"(factor) : "0"(factor));
         digitBase=factor>>2;
         digitQuotient=digitBase-remainder;
         remainder=digitQuotient*10;
         digitBase=Timer86B88DigitBase;
         remainder=number-remainder;
         digitBase+=remainder;
         __asm__("" : "=r"(digitBase) : "0"(digitBase) : "$2","memory");
         sprites=Timer86B88SpriteBase;
         __asm__("" : "=r"(digitBase),"=r"(sprites) : "0"(digitBase),"1"(sprites));
         digitBase<<=3;
         sprite=sprites+digitBase;
         Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
         Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
         factor=frame.quotient3600;
         __asm__("" : "=r"(factor) : "0"(factor));
         singleLeadingDigit=factor<10;
         }
    } else {
        register int factor __asm__("$12");
        register int productHigh __asm__("hi");
        register int width __asm__("$13");
        register int value __asm__("$2");
        register int digit __asm__("$3");
        register unsigned char *base __asm__("$2");
        factor=frame.divide10Multiplier;
        productHigh=Timer86B88High(remainder60,factor);
        index--;
        drawOwner=owner;
        drawX=horizontalOutput;
        drawY=verticalOutput;
        width=frame.digitWidth;
        value=remainder60>>31;
        frame.drawPositionY=y;
        frame.drawOrdinal=index;
        __asm__("" : "=r"(drawOwner),"=r"(drawX),"=r"(drawY),"=r"(x),"=r"(value) : "0"(drawOwner),"1"(drawX),"2"(drawY),"3"(x),"4"(value) : "memory");
        x-=width;
        frame.drawPositionX=x;
        __asm__("" : "=r"(x),"=h"(productHigh) : "0"(x),"1"(productHigh),"r"(width) : "memory");
        factor=productHigh;
        __asm__("" : "=r"(factor) : "0"(factor));
        digit=factor>>2;
        digitQuotient=digit-value;
        value=digitQuotient*10;
        digit=Timer86B88DigitBase;
        value=remainder60-value;
        digit+=value;
        __asm__("" : "=r"(digit) : "0"(digit) : "$2","memory");
        base=Timer86B88SpriteBase;
        __asm__("" : "=r"(digit),"=r"(base) : "0"(digit),"1"(base));
        digit<<=3;
        sprite=base+digit;
        Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
        Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
        singleLeadingDigit=remainder60<10;
    }}
    __asm__("" : "=r"(singleLeadingDigit) : "0"(singleLeadingDigit));
    if(!singleLeadingDigit) {
        register int width __asm__("$13");
        register int digit __asm__("$2");
        register unsigned char *base __asm__("$3");
        index--;
        drawOwner=owner;
        drawIndex=&frame.drawOrdinal;
        drawX=horizontalOutput;
        __asm__("" : "=r"(drawOwner),"=r"(drawIndex),"=r"(drawX) : "0"(drawOwner),"1"(drawIndex),"2"(drawX) : "$2","$3","memory");
        width=frame.digitWidth;
        digit=Timer86B88DigitBase;
        base=Timer86B88SpriteBase;
        drawY=verticalOutput;
        frame.drawPositionY=y;
        frame.drawOrdinal=index;
        __asm__("" : "=r"(x),"=r"(digit),"=r"(base),"=r"(width),"=r"(drawY) : "0"(x),"1"(digit),"2"(base),"3"(width),"4"(drawY) : "memory");
        x-=width;
        digit+=digitQuotient;
        digit<<=3;
        __asm__("" : "=r"(digit),"=r"(base) : "0"(digit),"1"(base));
        sprite=base+digit;
        frame.drawPositionX=x;
        Timer86B88Place(drawOwner,drawIndex,drawX,drawY);
        Timer86B88Draw(sprite,frame.drawPositionX,frame.drawPositionY);
    }
    return 0;
}

#undef Timer86B88Field

#undef Timer86B88High


typedef struct { Vector3D origin; int unkC, unk10, unk14; } DecodedVectorRecord;
extern short D_800658A0[], D_80065920[];
void func_level_31_80089D30(Vector3D* out, int x, int y, DecodedVectorRecord* record) {
    Vector3D scaled;
    short* cosine;
    short* sine;
    int angle;
    int sineProduct;
    angle = record->unk14;
    scaled.x = (x * record->unkC) >> 7;
    scaled.y = (y * record->unk10) >> 7;
    cosine = D_80065920;
    /* Non-emitting constraint preserves the retail table-base load before index scaling. */
    __asm__("" : "=r"(angle) : "0"(angle), "r"(cosine));
    cosine += angle;
    sine = &D_800658A0[angle];
    out->x = (scaled.x * *cosine + scaled.y * *sine) >> 12;
    sineProduct = scaled.x * *sine;
    out->y = (scaled.y * *cosine - sineProduct) >> 12;
    out->z = 0;
    func_8004F194(out, out, &record->origin);
}
