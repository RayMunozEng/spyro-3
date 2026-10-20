#include "common.h"
#include "ovl_header.h"
#include "mobyutil.h"
#include "spu.h"
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
int func_level_35_800810C4(Moby* actor,Vector3D* center,int radius,int heading,int tolerance,int speed,int turnA,int turnB,int avoidA,int avoidB,int argA,int argB,int flags) {
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

void func_level_35_800813E0(Moby* moby, int mode) {
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
int func_level_35_80081458(int inputMask) {
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


typedef struct { char value[7]; } DecodedBurstChoices;
extern DecodedBurstChoices DecodedBurstChoiceData __asm__("D_level_35_800746B8");
extern int D_8006C578, D_8006C574;
int rand(void);
void func_level_35_800818DC(Moby* moby, int selection) {
    Colour colour;
    DecodedBurstChoices choices;
    int reservedStack[2];
    register int type __asm__("$18") = 0;
    register int count __asm__("$20") = 0;
    register int lifetime __asm__("$19") = 0;
    int index;
    Moby* spawned;
    int* tag;
    unsigned char* choice;
    register int* sourceTag __asm__("$3");
    __asm__("" : "=r"(type), "=r"(count), "=r"(lifetime) : "0"(type), "1"(count), "2"(lifetime));
    choices = DecodedBurstChoiceData;
    if (moby->mobyClass == 0x5C) {
        sourceTag = moby->mobyTag;
        __asm__("" : "=r"(sourceTag) : "0"(sourceTag));
        *(int*)&colour = sourceTag[3];
        if (moby->state == 2) {
            type = count;
            count = 4;
            lifetime = 16;
        } else if (moby->state == 4) {
            type = 5;
            count = 1;
            lifetime = 32;
            colour.r = 255;
            colour.g = 255;
            colour.b = 255;
        }
    } else {
        choice = (unsigned char*)choices.value + selection;
        if (selection < 0) choice = (unsigned char*)choices.value + func_8003636C(0,6);
        type = *choice;
        if (type == 3) {
            colour.r = 255;
            colour.g = 0;
            colour.b = 0;
        } else if (type == 4) {
            colour.r = 255;
            colour.g = 255;
            colour.b = 64;
        } else {
            switch (rand() & 3) {
            case 0: colour.r = 255; colour.g = 0; colour.b = 0; break;
            case 1: colour.r = 255; colour.g = 255; colour.b = 0; break;
            case 2: colour.r = 0; colour.g = 255; colour.b = 0; break;
            case 3: colour.r = 255; colour.g = 0; colour.b = 255; break;
            }
        }
        count = 16;
        if (type == 2) lifetime = 48;
        else if (type == 3) lifetime = 88;
        else lifetime = 64;
    }
    colour.a = 63;
    index = 0;
    if (!count) goto done;
loop:
        if (D_8006C578-D_8006C574 < 21) goto done;
        spawned = SpawnMoby(0x5C,moby);
        if (spawned) {
            if (type == 4) {
                spawned->state = type;
                spawned->substate = rand() & 3;
            } else spawned->state = type;
            if (type == 1) spawned->substate = rand() & 15;
            tag = spawned->mobyTag;
            tag[3] = *(int*)&colour;
            tag[4] = lifetime;
        }
        index++;
        if (index < count) goto loop;
done:
    return;
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
void func_level_35_80081B7C(int count, int childClass, Moby* sourceMoby, Vector3D* offsets, int firstAnimation, int argument5) {
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
int func_level_35_8008226C(void *input) {
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


extern int D_8006FA3C, D_8006FA44, D_8006FA78, D_8006FA70;
extern int D_8006FA58[], D_8006FA5C, D_8006FA60, D_8006FA64;
extern int D_8006E344, D_8006FBC8, D_8006FBD0;
extern int* D_8006C560;
void func_level_35_800827FC(void) {
    register int mode __asm__("$4");
    register int result __asm__("$2");
    func_8003BEDC();
    mode = D_8006FA3C;
    D_8006E344 = 2;
    if (mode == 2) {
        D_8006FBC8 = 0;
        D_8006FBD0 = mode;
        if (D_8006FA78 == 4) {
            result = 1;
            goto storeResult;
        }
        D_8006FA44 = mode;
        goto finish;
    } else {
        int first = D_8006FA58[0];
        int second, third, fourth;
        D_8006FBC8 = 0;
        D_8006FBD0 = 0;
        if (first == 8 && (second = D_8006FA5C) == first && (third = D_8006FA60) == second && (fourth = D_8006FA64) == third) {
            D_8006FA44 = 0;
            goto finish;
        }
        {
            register int timer __asm__("$2") = D_8006FA70;
            /* Empty constraint retains the original word-load destination. */
            __asm__("" : "=r"(timer) : "0"(timer));
            if (timer <= 0) result = 1;
            else result = 2;
        }
storeResult:
        D_8006FA44 = result;
    }
finish:
    func_80013CC4(*D_8006C560, 4);
}

extern int D_8006FA3C,D_8006FA78,D_8006FA74,D_8006FA7C;
extern int DecodedRecordIndex __asm__("D_8006FA38");
extern int D_8006FA5C,D_8006FA60,D_8006FA64,D_8006E344;
extern int DecodedFirstCount __asm__("D_8006FA58");
extern unsigned char D_8006C7B4;
extern SpeedwayRecord speedwayRecords[];
void func_800498C0(int);
void func_level_35_80082910(int transition) {
    if(D_8006FA3C==2) {
        if(D_8006FA78==4) {
            if(D_8006FA74<speedwayRecords[DecodedRecordIndex].raceRecord)speedwayRecords[DecodedRecordIndex].raceRecord=D_8006FA74;
            if(!D_8006FA7C && !speedwayRecords[DecodedRecordIndex].raceComplete) {
                speedwayRecords[DecodedRecordIndex].raceComplete=1;D_8006C7B4|=2;
            }
        }
    } else if(DecodedFirstCount==8 && D_8006FA5C==DecodedFirstCount && D_8006FA60==D_8006FA5C && D_8006FA64==D_8006FA60) {
        if(!speedwayRecords[DecodedRecordIndex].trialComplete) {
            speedwayRecords[DecodedRecordIndex].trialComplete=1;D_8006C7B4|=1;
        }
        if(D_8006FA74<speedwayRecords[DecodedRecordIndex].trialRecord)speedwayRecords[DecodedRecordIndex].trialRecord=D_8006FA74;
    }
    D_8006E344=0;
    if(transition)func_800498C0(transition);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/level_35/level", D_level_35_800746B8);

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * 842 instructions and19 dispatch words. Evidence4925. Raw fields,
 * branch conditions, widths and helper addresses only; meanings, units,
 * cadence and runtime parity unresolved. Native/internal-target/data
 * identity and full EXE/every-overlay retail hashes required. */
#define A4926F(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern int A4926FBD0 __asm__("D_8006FBD0");
extern int A4926FBC8 __asm__("D_8006FBC8");
extern int A4926FBC4 __asm__("D_8006FBC4");
extern int A4926FBD4 __asm__("D_8006FBD4");
extern int A4926FBCC __asm__("D_8006FBCC");
extern int A4926FA40 __asm__("D_8006FA40");
extern int A4926FA38 __asm__("D_8006FA38");
extern int A4926FA78 __asm__("D_8006FA78");
extern int A4926FA7C __asm__("D_8006FA7C");
extern int A4926E53C __asm__("D_8006E53C");
extern int A4926C648 __asm__("D_8006C648");
extern int A4926C5BC __asm__("D_8006C5BC");
extern unsigned char A4926FA90[] __asm__("D_8006FA90");
extern unsigned char A4926FA58[] __asm__("D_8006FA58");
extern unsigned char* A4926C738 __asm__("D_8006C738");
extern unsigned char* A4926C788 __asm__("D_8006C788");
extern unsigned char* A4926C654 __asm__("D_8006C654");
extern unsigned char A4926Records[] __asm__("speedwayRecords");
extern int (*A4926Callback)() __asm__("unk_ovlheader_80074378");
int A4926H27934() __asm__("func_80027934");
int A4926Sound0() __asm__("PlaySound");
int A4926Sound1() __asm__("PlaySound");
int A4926Sound2() __asm__("PlaySound");
int A4926Sound3() __asm__("PlaySound");
int A4926Sound4() __asm__("PlaySound");
int A4926Sound5() __asm__("PlaySound");
int A4926Sound6() __asm__("PlaySound");
int A4926Sound7() __asm__("PlaySound");
int A4926Sound8() __asm__("PlaySound");
int A4926Sound9() __asm__("PlaySound");
int A4926Sound10() __asm__("PlaySound");
int A4926Sound11() __asm__("PlaySound");
int A4926Sound12() __asm__("PlaySound");
int A4926Sound13() __asm__("PlaySound");
int A4926Sound14() __asm__("PlaySound");
int A4926Sound15() __asm__("PlaySound");
int A4926Sound16() __asm__("PlaySound");
int A4926Sound17() __asm__("PlaySound");
int A4926Sound18() __asm__("PlaySound");
int A4926Sound19() __asm__("PlaySound");
int A4926Sound20() __asm__("PlaySound");
int A4926Sound21() __asm__("PlaySound");
int A4926Sound22() __asm__("PlaySound");
extern int A4927Choice0 __asm__("D_8006FBC8");
extern int A4927ChoiceGlobal __asm__("D_8006FBC8");
extern int A4927ChoiceTimer __asm__("D_8006FBC8");
extern int A4927Choice2 __asm__("D_8006FBC8");
extern int A4927ModeConfirm0 __asm__("D_8006FA40");
extern int A4927ModeConfirm1 __asm__("D_8006FA40");

void func_level_35_80082B18(void){
 register int test2 __asm__("$2");
 register int work2 __asm__("$2");register int work3 __asm__("$3");
 register int arg4 __asm__("$4");register int arg5 __asm__("$5");
 register int arg6 __asm__("$6");register int arg7 __asm__("$7");
 register int* timer16 __asm__("$16");register int* input17 __asm__("$17");
 register unsigned char* data16 __asm__("$16");register int index17 __asm__("$17");
 register int value18 __asm__("$18");register unsigned char* data18 __asm__("$18");
 register int value19 __asm__("$19");register int value20 __asm__("$20");register int value21 __asm__("$21");
 register unsigned char* data9 __asm__("$9");register int offset10 __asm__("$10");
 register int pressed8 __asm__("$8");register int* count12 __asm__("$12");
 register int* timer13 __asm__("$13");register int* row14 __asm__("$14");
 register int speed15 __asm__("$15");register int three11 __asm__("$11");
 work3=A4926FBD0;work2=1;if(work3==work2)goto mode1;
 if(work3<2){if(!work3)goto mode0;return;}if(work3==2)goto mode2;return;
 mode0:
 switch(A4926FBC8){
 case 0:
  data16=A4926FA90;value18=80;index17=0;value19=640;
  do{
   work2=A4926C5BC;arg4=work2*10+index17;work2=A4926H27934(arg4);
   arg5=0;arg7=work2;arg6=arg7<<3;arg4=(int)(data16+6);
   __asm__ volatile("" : "=r"(arg4),"=r"(arg5),"=r"(arg6),"=r"(arg7):"0"(arg4),"1"(arg5),"2"(arg6),"3"(arg7));
   do{
    work2=(int)A4926C738;A4926F(data16,short*,0)=arg7;work2=arg6+work2;
    work2=A4926F((void*)work2,unsigned char*,4);A4926F((void*)arg4,unsigned char*,-4)=work2;
    work2=(int)A4926C738;work2=arg6+work2;work2=A4926F((void*)work2,unsigned char*,2);
    data16+=8;A4926F((void*)arg4,short*,-2)=value19;A4926F((void*)arg4,unsigned char*,-3)=work2;
    work3=(int)A4926C788;work2<<=3;work3+=work2;
    work2=A4926F((void*)work3,unsigned char*,5);work3=A4926F((void*)work3,unsigned char*,1);
    arg5++;work2-=work3;work2>>=1;work2=value18-work2;A4926F((void*)arg4,short*,0)=work2;
    arg4+=8;work2=arg5<8;
   }while(work2);
   index17++;value18+=24;
  }while(index17<4);
  A4926Sound0(A4926C654[22],0,128);work2=1;goto clearGlobal;
 case 1:
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2>=45)goto sound01;
  if(!(A4926E53C&2112))return;
 sound01:A4926Sound1(A4926C654[22],0,128);work2=2;goto clearTimer;
 case 2:
  data9=A4926FA90;arg7=0;work3=(int)&A4926FBD4;timer13=(int*)(work3-16);
  __asm__("" : "=r"(timer13):"0"(timer13));
  work2=A4926E53C;offset10=0;A4926F((void*)work3,int*,0)=0;
  work3=A4926C648;work2&=2112;pressed8=work2!=0;work2=work3*3;speed15=work2<<2;
  do{
   arg5=128;arg4=0;work3=(int)A4926FA58;work2=arg7<<2;row14=(int*)(work2+work3);__asm__("" : "=r"(row14):"0"(row14));count12=&A4926FBD4;three11=3;
   arg6=0;work3=(int)(data9+4);
   do{
    work2=*timer13-offset10-arg6;
    if(work2<=0 && !pressed8)goto skipEntry;
    if(pressed8)A4926F((void*)work3,unsigned short*,0)=arg5;
    else A4926F((void*)work3,unsigned short*,0)-=speed15;
    if(A4926F((void*)work3,short*,0)>arg5)goto skipEntry;
    A4926F((void*)work3,short*,0)=arg5;
    if(*row14<=arg4)goto countDone;
    work2=*count12;work2++;*count12=work2;
    countDone:__asm__ volatile("" ::: "memory");if(arg7!=three11)goto skipEntry;work2=7;
    __asm__("" : "=r"(work2):"0"(work2));if(arg4!=work2)goto skipEntry;
    __asm__ volatile("" : "=r"(pressed8):"0"(pressed8):"$2");
    if(pressed8){work2=60;*timer13=work2;}else {__asm__("" : "=r"(pressed8):"0"(pressed8));*timer13=0;}A4926FBC8=three11;
   skipEntry:
    arg5+=32;work3+=8;data9+=8;arg4++;arg6+=6;
   }while(arg4<8);
   arg7++;offset10+=60;
  }while(arg7<4);
  {register int* p2 __asm__("$2");p2=&A4926FBC4;work3=*p2;arg4=A4926C648;work3+=arg4;*p2=work3;}
  return;
 case 3:
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<60)return;
  A4926Sound2(A4926C654[22],0,128);*timer16=0;
  work3=A4926F(A4926FA58,int*,0);work2=8;if(work3!=work2){work2=4;goto resetChoice;}
  work2=A4926F(A4926FA58,int*,4);if(work2!=work3){work2=4;goto resetChoice;}
  work3=A4926F(A4926FA58,int*,8);if(work3!=work2){work2=4;goto resetChoice;}
  work2=A4926F(A4926FA58,int*,12);if(work2==work3){work2=5;goto storeChoice0;}
  work2=4;goto resetChoice;
 case 4:
  timer16=&A4926FBC4;input17=&A4926E53C;
  work2=*timer16;arg4=A4926C648;work3=*input17;work2+=arg4;work3&=20480;*timer16=work2;
  if(work3){A4926Sound3(A4926C654[24],0,128);*timer16=0;work3=A4926FBCC;work2=1;work2-=work3;A4926FBCC=work2;}
  if(!(*input17&2112))return;
  if(A4926FBCC)goto soundExit;
  A4926Sound4(A4926C654[22],0,192);A4927ModeConfirm0=1;goto callback;
 case 5:
  timer16=&A4926FBC4;work2=*timer16;arg4=A4926C648;work3=A4926E53C;work2+=arg4;work3&=2112;*timer16=work2;
  if(!work3)return;
  A4926Sound5(A4926C654[22],0,192);work2=1;*timer16=0;A4926FBD4=0;A4926FBD0=work2;A4926FBC8=0;return;
 }
 return;
 mode1:
 switch(A4926FBC8){
 case 0:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound6(A4926C654[22],0,128);work2=1;goto clearTimer;
 case 1:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound7(A4926C654[22],0,128);work2=2;goto clearTimer;
 case 2:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound8(A4926C654[22],0,128);work2=3;goto clearTimer;
 case 3:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound9(A4926C654[22],0,128);work3=A4926FA38;*timer16=0;
  work2=work3*44;test2=A4926F(A4926Records+work2,int*,16);
  if(test2){work2=4;goto resetChoice;}
  work2=5;
 storeChoice0:A4927Choice0=5;return;
 case 4:
  timer16=&A4926FBC4;input17=&A4926E53C;
  work2=*timer16;arg4=A4926C648;work3=*input17;work2+=arg4;work3&=20480;*timer16=work2;
  if(work3){A4926Sound10(A4926C654[24],0,128);*timer16=0;work3=A4926FBCC;work2=1;work2-=work3;A4926FBCC=work2;}
  if(!(*input17&2112))return;
  if(A4926FBCC)goto soundExit;
  A4926Sound11(A4926C654[22],0,192);A4927ModeConfirm1=1;goto callback;
 case 5:goto soundExitUpdate;
 }
 return;
 mode2:
 switch(A4926FBC8){
 case 0:
  data18=A4926FA90;work2=A4926H27934(2001);work2<<=3;value19=0;
  work3=(int)A4926C738;data16=data18+6;work2+=work3;work3=A4926F((void*)work2,unsigned char*,2);
  work2=A4926FA7C;arg4=(int)A4926C788;value20=work3+work2;work2=value20<<3;arg4+=work2;__asm__("" : "=r"(arg4):"0"(arg4));
  work3=A4926F((void*)arg4,unsigned char*,5);work2=A4926F((void*)arg4,unsigned char*,1);arg5=70;
  work3-=work2;work3>>=1;value21=arg5-work3;
  work2=A4926F((void*)arg4,unsigned char*,4);arg4=A4926F((void*)arg4,unsigned char*,0);work3=144;
  work2-=arg4;work2>>=1;index17=work3-work2;
  do{
   work2=A4926H27934(2001);A4926F(data18,short*,0)=work2;data18+=8;
   work3=(int)A4926C738;work2<<=3;work2+=work3;work2=A4926F((void*)work2,unsigned char*,4);
   value19++;A4926F(data16,short*,-2)=index17;index17+=224;A4926F(data16,unsigned char*,-3)=value20;
   A4926F(data16,short*,0)=value21;A4926F(data16,unsigned char*,-4)=work2;data16+=8;
  }while(value19<2);
  A4926Sound12(A4926C654[22],0,128);work2=2;
 clearGlobal:A4926FBC4=0;A4927ChoiceGlobal=work2;return;
 case 1:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<45 && !A4926FBD4)return;
  A4926Sound13(A4926C654[22],0,128);work2=2;goto clearTimer;
 case 2:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound14(A4926C654[22],0,128);work2=3;goto clearTimer;
 case 3:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound15(A4926C654[22],0,128);work2=4;
 clearTimer:*timer16=0;A4927ChoiceTimer=work2;return;
 case 4:
  if(A4926E53C&2112)A4926FBD4=1;
  timer16=&A4926FBC4;work2=*timer16;work3=A4926C648;work2+=work3;*timer16=work2;
  if(work2<30 && !A4926FBD4)return;
  A4926Sound16(A4926C654[22],0,128);*timer16=0;work3=A4926FA78;work2=4;
  if(work3!=work2){work2=5;goto resetChoice;}
  test2=A4926FA7C;if(test2){work2=5;goto resetChoice;}
  work2=A4926FA38;work3=work2*44;work2=A4926F(A4926Records+work3,int*,36);
  __asm__("" : "=r"(work2):"0"(work2));
  if(!work2)goto storeSix;work2=5;
 resetChoice:A4926FBCC=0;
 storeChoice2:A4927Choice2=work2;return;
 storeSix:work2=6;A4926FBC8=work2;return;
 case 5:
  timer16=&A4926FBC4;input17=&A4926E53C;
  work2=*timer16;arg4=A4926C648;work3=*input17;work2+=arg4;work3&=20480;*timer16=work2;
  if(work3){A4926Sound17(A4926C654[24],0,128);*timer16=0;work3=A4926FBCC;work2=1;work2-=work3;A4926FBCC=work2;}
  if(!(*input17&2112))return;
  if(A4926FBCC)goto soundExit;
  A4926Sound18(A4926C654[22],0,192);A4926FA40=2;goto callback;
 case 6:
 soundExitUpdate:
  {register int* timer5 __asm__("$5");timer5=&A4926FBC4;work2=*timer5;arg4=A4926C648;work3=A4926E53C;
   work2+=arg4;work3&=2112;*timer5=work2;if(!work3)return;}
 soundExit:A4926Sound20(A4926C654[23],0,192);
 callback:A4926Callback(1);return;
 }
}
#undef A4926F


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80083840.
* Assembly SHA256 fc13ff6fd9ab3e8ef60c264c3745678291b79a6ef8f703a1eeb8abd763a014dc.
* AI generated; not human reviewed. All1086 original instructions and
* actual branch/call/internal targets are required. Frame0x100 retains
* S0..S6/RA and original SP0x18/0x20/0x30/0x40/0x50 buffer addresses. The five
* original format strings occupy48 bytes including original padding.
* Table entries are32-bit loads; record stride44 and offsets0x14/0x28
* retain byte-addressed source arithmetic. Time arithmetic uses ordinary
* signed C division/remainder3600/60 and hundredths multiplication100.
* Raw tick rate and complete helper contracts are not established here.
* Branch-local format buffer expressions preserve original redundant
* address producers; no shared live backup address is introduced.
* Initialized empty dependencies/dead-before-producer clobbers emit no
* CPU instructions. Immediate metadata tags are unique scheduling IDs,
* not retail addresses, data or semantic evidence. No partial HI, fixed
* FP shortcut or opcode assembly is used. Units/fixed point, complete
* helper contracts, caller cadence and synchronized retail runtime remain
* open. Cadence here is per invocation; confidence is binary identity
* only after every acceptance gate. Falsification: every native/linked
* word and actual target, original format bytes/padding, complete EXE
* and every overlay retail hash must remain identical. */
#define Speedway35Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
unsigned char Speedway35CallDrawStringCenteredView1() __asm__("DrawStringCentered");
unsigned char Speedway35Call1FB74View1() __asm__("func_8001FB74");
unsigned char Speedway35Call1FD00View1() __asm__("func_8001FD00");
int Speedway35Call28378View1() __asm__("func_80028378");
void * Speedway35Call289C8View1() __asm__("func_800289C8");
unsigned char Speedway35Call2E748View1() __asm__("func_8002E748");
int Speedway35Call2EBB0View1() __asm__("func_8002EBB0");
int Speedway35CallsprintfView1() __asm__("sprintf");
extern unsigned char Speedway35Data69D98View1 __asm__("D_80069D98");
extern unsigned char Speedway35Data69DA8View1 __asm__("D_80069DA8");
extern unsigned char Speedway35Data69DD8View1 __asm__("D_80069DD8");
extern unsigned char Speedway35Data69DDCView1 __asm__("D_80069DDC");
extern unsigned char Speedway35Data6C438View1 __asm__("D_8006C438");
extern unsigned char Speedway35Data6C43CView1 __asm__("D_8006C43C");
extern unsigned char Speedway35Data6C440View1 __asm__("D_8006C440");
extern unsigned char Speedway35Data6C444View1 __asm__("D_8006C444");
extern unsigned char Speedway35Data6C448View1 __asm__("D_8006C448");
extern unsigned char Speedway35Data6C44CView1 __asm__("D_8006C44C");
extern int Speedway35Data6C76CView1 __asm__("D_8006C76C");
extern int Speedway35Data6C788View1 __asm__("D_8006C788");
extern int Speedway35Data6FA38View1 __asm__("D_8006FA38");
extern int Speedway35Data6FA44View1 __asm__("D_8006FA44");
extern int Speedway35Data6FA74View1 __asm__("D_8006FA74");
extern int Speedway35Data6FA7CView1 __asm__("D_8006FA7C");
extern int Speedway35Data6FA90View1 __asm__("D_8006FA90");
extern int Speedway35Data6FBC4View1 __asm__("D_8006FBC4");
extern int Speedway35Data6FBC8View1 __asm__("D_8006FBC8");
extern int Speedway35Data6FBCCView1 __asm__("D_8006FBCC");
extern int Speedway35Data6FBD0View1 __asm__("D_8006FBD0");
extern int Speedway35Data6FBD4View1 __asm__("D_8006FBD4");
extern unsigned char Speedway35DataspeedwayRecordsView1 __asm__("speedwayRecords");
const char Speedway35Format1[6] __asm__("D_level_35_8007470C") __attribute__((aligned(4))) = "32/32";
extern unsigned char Speedway35Format1View __asm__("D_level_35_8007470C");
const char Speedway35Format2[7] __asm__("D_level_35_80074714") __attribute__((aligned(4))) = "%2d/32";
extern unsigned char Speedway35Format2View __asm__("D_level_35_80074714");
const char Speedway35Format3[13] __asm__("D_level_35_8007471C") __attribute__((aligned(4))) = "%d:%02d.%02d";
extern unsigned char Speedway35Format3View __asm__("D_level_35_8007471C");
const char Speedway35Format4[8] __asm__("D_level_35_8007472C") __attribute__((aligned(4))) = "%d.%02d";
extern unsigned char Speedway35Format4View __asm__("D_level_35_8007472C");
const char Speedway35Format5[8] __asm__("D_level_35_80074734") __attribute__((aligned(4))) = "-------";
extern unsigned char Speedway35Format5View __asm__("D_level_35_80074734");
void func_level_35_80083840(void) {
    int rawWord3;
    int temporaryWord1, temporaryWord2, temporaryWord3, temporaryWord4, temporaryWord5, temporaryWord6, temporaryWord7, temporaryWord8, temporaryWord14, temporaryWord16, temporaryWord17, temporaryWord18;
    register int widthOrPrimitive16 __asm__("$16");
    register int rowOrTable17 __asm__("$17");
    register int entryOrTable18 __asm__("$18");
    register int recordCursor19 __asm__("$19");
    register int rowCountOrCenter20 __asm__("$20");
    register int countTable21 __asm__("$21");
    register int retainedCountTable22 __asm__("$22");
    register int rawWord2 __asm__("$2"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7");
    struct {
        char sp18[8], sp20[16], sp30[16], sp40[16], sp50[16];
    }
    originalFrame;
    int *temporaryWord9;
    int *temporaryWord10;
    int temporaryWord11;
    int temporaryWord13;
    int temporaryWord12;
    int temporaryWord15;
    switch (Speedway35Data6FBD0View1) {
    case 0:
        Speedway35Call1FD00View1(0x70, 0x190, 0x1E, 0xD0);
        Speedway35Call1FB74View1(0x90, 0x40, 0x170, 0x40);
        Speedway35Call1FB74View1(0x90, 0xA8, 0x170, 0xA8);
        temporaryWord11 = Speedway35Data6FBC8View1;
        if (temporaryWord11 > 0) {
            argumentWord5 = 256;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            argumentWord6 = 36;
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
            argumentWord4 = (int)&Speedway35Data69D98View1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FA44View1;
            rawWord2 <<= 4;
            rawWord2 += argumentWord4;
            rawWord3 <<= 2;
            rawWord3 += rawWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            argumentWord4 = Speedway35Field(rawWord3, int*, 0);
            Speedway35CallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
        }
        rowCountOrCenter20 = 0;
        if (Speedway35Data6FBC8View1 >= 2) {
            recordCursor19 = (int)&Speedway35Data6FA90View1;
            countTable21 = recordCursor19-0x38;
            do {
                entryOrTable18 = 0;
                retainedCountTable22 = countTable21;
                __asm__("":"=r"(retainedCountTable22):"0"(retainedCountTable22));
                rowOrTable17 = recordCursor19+6;
            loop_11:
                if (entryOrTable18 < Speedway35Field(retainedCountTable22, int*, 0)) {
                    temporaryWord12 = Speedway35Call28378View1(recordCursor19, entryOrTable18);
                    Speedway35Field(rowOrTable17, unsigned char *, -3) = temporaryWord12;
                    Speedway35Call289C8View1(Speedway35Data6C788View1 + ((temporaryWord12 & 0xFF) * 8), Speedway35Field(rowOrTable17, short *, -2), Speedway35Field(rowOrTable17, short *, 0));
                    rowOrTable17 += 8;
                }
                else {
                    argumentWord5 = Speedway35Field(rowOrTable17, short*, -2);
                    argumentWord6 = Speedway35Field(rowOrTable17, short*, 0);
                    rawWord2 = Speedway35Field(rowOrTable17, unsigned char*, -3);
                    rawWord3 = Speedway35Data6C788View1;
                    rawWord2 <<= 3;
                    widthOrPrimitive16 = rawWord3+rawWord2;
                    rawWord2 = (int)Speedway35Call289C8View1(widthOrPrimitive16, argumentWord5, argumentWord6);
                    argumentWord4 = rawWord2;
                    rawWord3 = Speedway35Field(widthOrPrimitive16, unsigned short*, 6);
                    rawWord2 = 96;
                    rawWord3 &= 96;
                    if (rawWord3 == rawWord2){
                        rawWord2 = 64;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        Speedway35Field(argumentWord4, unsigned char*, 4) = rawWord2;
                        Speedway35Field(argumentWord4, unsigned char*, 5) = rawWord2;
                        Speedway35Field(argumentWord4, unsigned char*, 6) = rawWord2;
                        __asm__ __volatile__("":::"memory");
                        rawWord2 = Speedway35Field(argumentWord4, unsigned char*, 7);
                        rawWord3 = Speedway35Field(argumentWord4, unsigned short*, 0x16);
                        rawWord2 |= 2;
                        rawWord3 &= 0xFF9F;
                        Speedway35Field(argumentWord4, unsigned char*, 7) = rawWord2;
                        Speedway35Field(argumentWord4, unsigned short*, 0x16) = rawWord3;
                    }
                    else{
                        rawWord2 = 32;
                        Speedway35Field(argumentWord4, unsigned char*, 4) = rawWord2;
                        Speedway35Field(argumentWord4, unsigned char*, 5) = rawWord2;
                        Speedway35Field(argumentWord4, unsigned char*, 6) = rawWord2;
                    }
                    rowOrTable17 += 8;
                }
                entryOrTable18 += 1;
                recordCursor19 += 8;
                if (entryOrTable18 < 8) {
                    goto loop_11;
                }
                rowCountOrCenter20 += 1;
                countTable21 += 4;
            }
            while (rowCountOrCenter20 < 4);
            Speedway35CallsprintfView1(&originalFrame.sp18, &Speedway35Format1View);
            rowCountOrCenter20 = (Speedway35Call2EBB0View1(&originalFrame.sp18) >> 1) + 0x100;
            Speedway35CallsprintfView1(&originalFrame.sp18, &Speedway35Format2View, Speedway35Data6FBD4View1);
            Speedway35Call2E748View1(&originalFrame.sp18, rowCountOrCenter20 - Speedway35Call2EBB0View1(&originalFrame.sp18), 0x32, 2, 0);
        }
        if (Speedway35Data6FBC8View1 == 4) {
            widthOrPrimitive16 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data69DD8View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data69DDCView1 + (Speedway35Data6C76CView1 * 4)));
            rowOrTable17 = (int)&Speedway35Data69DD8View1;
            __asm__("":"=r"(rowOrTable17):"0"(rowOrTable17));
            entryOrTable18 = (int)&Speedway35Data69DDCView1;
            __asm__("":"=r"(entryOrTable18):"0"(entryOrTable18));
            rawWord3 = rawWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            if (widthOrPrimitive16 < rawWord3)widthOrPrimitive16 = rawWord3;
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord3 = widthOrPrimitive16+10;
            widthOrPrimitive16 = rawWord3+rawWord2;
            rawWord3 = widthOrPrimitive16 >> 1;
            rawWord2 = 256;
            widthOrPrimitive16 = rawWord2-rawWord3;
            Speedway35Call2E748View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)), widthOrPrimitive16, 0xB2, 2, 0);
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord3 = widthOrPrimitive16+10;
            widthOrPrimitive16 = rawWord3+rawWord2;
            argumentWord7 = 0;
            __asm__("":"=r"(argumentWord7):"0"(argumentWord7));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBCCView1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2+rowOrTable17;
            if (!rawWord3){
                rawWord2 = Speedway35Data6FBC4View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = widthOrPrimitive16;
            argumentWord6 = 178;
            Speedway35Call2E748View1(Speedway35Field(argumentWord4, int*, 0), argumentWord5, argumentWord6, argumentWord7|2, 0);
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBCCView1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2+entryOrTable18;
            __asm__ __volatile__(""::"r"(argumentWord4):"$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__(""::"r"(rawWord2):"$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2){
                rawWord2 = Speedway35Data6FBC4View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = widthOrPrimitive16;
            __asm__ __volatile__(""::"r"(argumentWord5), "i"(0x10860001):"$6", "memory");
            argumentWord6 = 192;
            goto drawFinalSelectionRow;
        }
        argumentWord7 = 2;
        if (Speedway35Data6FBC8View1 == 5) {
            argumentWord4 = (int)&Speedway35Data6C43CView1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBC4View1;
            rawWord2 <<= 2;
            rawWord3 &= 31;
            rawWord3 = rawWord3 < 22;
            rawWord2 += argumentWord4;
            if (rawWord3)argumentWord7 = 3;
            argumentWord4 = Speedway35Field(rawWord2, int*, 0);
            argumentWord5 = 256;
            argumentWord6 = 184;
            goto drawFinalCenteredCaption;
        }
        return;
    case 1:
        Speedway35Call1FD00View1(0x70, 0x190, 0x40, 0xA8);
        Speedway35Call1FB74View1(0x90, 0x56, 0x170, 0x56);
        Speedway35Call1FB74View1(0x90, 0x84, 0x170, 0x84);
        temporaryWord13 = Speedway35Data6FBC8View1;
        if (temporaryWord13 > 0) {
            Speedway35CallDrawStringCenteredView1(*(int*)(&Speedway35Data6C440View1 + (Speedway35Data6C76CView1 * 4)), 0xC0, 0x60, 2);
            Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C440View1 + (Speedway35Data6C76CView1 * 4)));
            temporaryWord1 = Speedway35Data6FA74View1 / 3600;
            temporaryWord5 = Speedway35Data6FA74View1/60;
            temporaryWord14 = ((Speedway35Data6FA74View1 % 60) * 0x64) / 60;
            argumentWord5 = temporaryWord5;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            rawWord2 = temporaryWord1*60;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            argumentWord7 = argumentWord5-rawWord2;
            rawWord2 = temporaryWord14;
            if (temporaryWord1){
                __asm__ __volatile__("":::"$4", "memory");
                argumentWord4 = (int)&originalFrame.sp20;
                Speedway35CallsprintfView1(argumentWord4, &Speedway35Format3View, temporaryWord1, argumentWord7, rawWord2);
                __asm__ __volatile__(""::"i"(0x10860002):"memory");
            }
            else{
                argumentWord4 = (int)&originalFrame.sp20;
                argumentWord5 = (int)&Speedway35Format4View;
                argumentWord6 = argumentWord7;
                __asm__ __volatile__(""::"r"(argumentWord6):"$7", "memory");
                argumentWord7 = rawWord2;
                Speedway35CallsprintfView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                __asm__ __volatile__(""::"i"(0x10860003):"memory");
            }
            Speedway35CallDrawStringCenteredView1(&originalFrame.sp20, 0xC0, 0x71, 2);
        }
        if (Speedway35Data6FBC8View1 >= 2) {
            Speedway35CallDrawStringCenteredView1(*(int*)(&Speedway35Data6C444View1 + (Speedway35Data6C76CView1 * 4)), 0x140, 0x60, 2);
            Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C444View1 + (Speedway35Data6C76CView1 * 4)));
            temporaryWord9 = &Speedway35DataspeedwayRecordsView1 + 0x14 + (Speedway35Data6FA38View1 * 0x2C);
            temporaryWord2 = *temporaryWord9 / 3600;
            temporaryWord6 = (*temporaryWord9 / 60) - (temporaryWord2 * 0x3C);
            temporaryWord16 = ((*temporaryWord9 % 60) * 0x64) / 60;
            if (*temporaryWord9 == 0x8CA0){
                Speedway35CallsprintfView1(&originalFrame.sp30, &Speedway35Format5View, temporaryWord2, temporaryWord6);
                __asm__ __volatile__(""::"i"(0x10860004):"memory");
            }
            else{
                if (temporaryWord2){
                    Speedway35CallsprintfView1(&originalFrame.sp30, &Speedway35Format3View, temporaryWord2, temporaryWord6, temporaryWord16);
                    __asm__ __volatile__(""::"i"(0x10860005):"memory");
                }
                else{
                    argumentWord4 = (int)&originalFrame.sp30;
                    argumentWord5 = (int)&Speedway35Format4View;
                    argumentWord6 = temporaryWord6;
                    __asm__ __volatile__(""::"r"(argumentWord6):"$7", "memory");
                    argumentWord7 = temporaryWord16;
                    Speedway35CallsprintfView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                    __asm__ __volatile__(""::"i"(0x10860006):"memory");
                }
            }
            Speedway35CallDrawStringCenteredView1(&originalFrame.sp30, 0x140, 0x71, 2);
        }
        if (Speedway35Data6FBC8View1 >= 3) {
            argumentWord7 = 2;
            if (Speedway35Data6FA74View1 < *(int*)(&Speedway35DataspeedwayRecordsView1 + 0x14 + (Speedway35Data6FA38View1 * 0x2C))) {
                argumentWord4 = (int)&Speedway35Data6C448View1;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                rawWord2 = Speedway35Data6C76CView1;
                rawWord3 = Speedway35Data6FBC4View1;
                rawWord2 <<= 2;
                rawWord3 &= 31;
                rawWord3 = rawWord3 < 22;
                rawWord2 += argumentWord4;
                if (rawWord3)argumentWord7 = 3;
                argumentWord4 = Speedway35Field(rawWord2, int*, 0);
                argumentWord5 = 256;
                __asm__ __volatile__(""::"i"(0x10860007):"$6", "memory");
                argumentWord6 = 72;
                goto drawFirstComparisonCaption;
            }
            else{
                argumentWord5 = 256;
                rawWord2 = Speedway35Data6C76CView1;
                __asm__ __volatile__("":::"$6", "memory");
                argumentWord6 = 72;
                rawWord2 <<= 2;
                argumentWord4 = Speedway35Field(&Speedway35Data6C44CView1, int*, rawWord2);
                drawFirstComparisonCaption:Speedway35CallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            }
        }
        if (Speedway35Data6FBC8View1 == 4) {
            widthOrPrimitive16 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data69DD8View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data69DDCView1 + (Speedway35Data6C76CView1 * 4)));
            rowOrTable17 = (int)&Speedway35Data69DD8View1;
            __asm__("":"=r"(rowOrTable17):"0"(rowOrTable17));
            entryOrTable18 = (int)&Speedway35Data69DDCView1;
            __asm__("":"=r"(entryOrTable18):"0"(entryOrTable18));
            rawWord3 = rawWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            if (widthOrPrimitive16 < rawWord3)widthOrPrimitive16 = rawWord3;
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord3 = widthOrPrimitive16+10;
            widthOrPrimitive16 = rawWord3+rawWord2;
            rawWord3 = widthOrPrimitive16 >> 1;
            rawWord2 = 256;
            widthOrPrimitive16 = rawWord2-rawWord3;
            Speedway35Call2E748View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)), widthOrPrimitive16, 0x8C, 2, 0);
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord3 = widthOrPrimitive16+10;
            widthOrPrimitive16 = rawWord3+rawWord2;
            argumentWord7 = 0;
            __asm__("":"=r"(argumentWord7):"0"(argumentWord7));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBCCView1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2+rowOrTable17;
            if (!rawWord3){
                rawWord2 = Speedway35Data6FBC4View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = widthOrPrimitive16;
            argumentWord6 = 140;
            Speedway35Call2E748View1(Speedway35Field(argumentWord4, int*, 0), argumentWord5, argumentWord6, argumentWord7|2, 0);
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBCCView1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2+entryOrTable18;
            __asm__ __volatile__(""::"r"(argumentWord4):"$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__(""::"r"(rawWord2):"$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2){
                rawWord2 = Speedway35Data6FBC4View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = widthOrPrimitive16;
            __asm__ __volatile__(""::"r"(argumentWord5), "i"(0x10860008):"$6", "memory");
            argumentWord6 = 154;
            goto drawFinalSelectionRow;
        }
        argumentWord7 = 2;
        if (Speedway35Data6FBC8View1 == 5) {
            argumentWord4 = (int)&Speedway35Data6C43CView1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBC4View1;
            rawWord2 <<= 2;
            rawWord3 &= 31;
            rawWord3 = rawWord3 < 22;
            rawWord2 += argumentWord4;
            if (rawWord3)argumentWord7 = 3;
            argumentWord4 = Speedway35Field(rawWord2, int*, 0);
            argumentWord5 = 256;
            argumentWord6 = 146;
            goto drawFinalCenteredCaption;
        }
        break;
    case 2:
        Speedway35Call1FD00View1(0x70, 0x190, 0x38, 0xB2);
        Speedway35Call1FB74View1(0x90, 0x54, 0x170, 0x54);
        Speedway35Call1FB74View1(0x90, 0x8E, 0x170, 0x8E);
        rawWord2 = Speedway35Data6FBC8View1;
        if (rawWord2 > 0){
            rawWord3 = (int)&Speedway35Data6FA44View1;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2 = Speedway35Field(rawWord3, int*, 0);
            if (rawWord2 != 1) goto prepareModeCaptionArguments;
            argumentWord5 = 256;
            __asm__ __volatile__(""::"r"(argumentWord5):"memory");
            rawWord2 = Speedway35Data6FA7CView1;
            if (rawWord2) goto prepareModeCaptionY;
            argumentWord6 = 64;
            __asm__ __volatile__(""::"r"(argumentWord6):"$2", "memory");
            Speedway35Field(rawWord3, int*, 0) = 0;
            prepareModeCaptionArguments:argumentWord5 = 256;
            prepareModeCaptionY:argumentWord6 = 64;
            __asm__ __volatile__(""::"r"(argumentWord5), "r"(argumentWord6):"memory");
            rawWord3 = Speedway35Data6C76CView1;
            __asm__ __volatile__("":::"$4", "memory");
            argumentWord4 = (int)&Speedway35Data69DA8View1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = rawWord3*20;
            rawWord3 = Speedway35Data6FA44View1;
            rawWord2 += argumentWord4;
            rawWord3 <<= 2;
            rawWord3 += rawWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            argumentWord4 = Speedway35Field(rawWord3, int*, 0);
            Speedway35CallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, 2);
            rawWord3 = (int)&Speedway35Data6FA44View1;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2 = Speedway35Field(rawWord3, int*, 0);
            if (rawWord2 < 2){
                entryOrTable18 = rawWord3+76;
                __asm__("":"=r"(entryOrTable18):"0"(entryOrTable18));
                rowOrTable17 = 0;
                widthOrPrimitive16 = rawWord3+82;
                do {
                    temporaryWord15 = Speedway35Call28378View1(entryOrTable18, 0);
                    argumentWord5 = Speedway35Field(widthOrPrimitive16, short *, -2);
                    argumentWord6 = Speedway35Field(widthOrPrimitive16, short *, 0);
                    Speedway35Field(widthOrPrimitive16, unsigned char *, -3) = temporaryWord15;
                    widthOrPrimitive16 += 8;
                    entryOrTable18 += 8;
                    rowOrTable17 += 1;
                    Speedway35Call289C8View1(Speedway35Data6C788View1 + ((temporaryWord15 & 0xFF) * 8), argumentWord5, argumentWord6);
                }
                while (rowOrTable17 < 2);
            }
            rawWord2 = Speedway35Data6FBC8View1;
        }
        rawWord2 = rawWord2 < 2;
        if (!rawWord2) {
            Speedway35CallDrawStringCenteredView1(*(int*)(&Speedway35Data6C440View1 + (Speedway35Data6C76CView1 * 4)), 0xC0, 0x6A, 2);
            Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C440View1 + (Speedway35Data6C76CView1 * 4)));
            temporaryWord3 = Speedway35Data6FA74View1 / 3600;
            temporaryWord7 = (Speedway35Data6FA74View1 / 60) - (temporaryWord3 * 0x3C);
            temporaryWord17 = ((Speedway35Data6FA74View1 % 60) * 0x64) / 60;
            if (Speedway35Data6FA44View1 >= 2){
                Speedway35CallsprintfView1(&originalFrame.sp40, &Speedway35Format5View, temporaryWord3, temporaryWord7);
                __asm__ __volatile__(""::"i"(0x10860009):"memory");
            }
            else{
                if (temporaryWord3){
                    Speedway35CallsprintfView1(&originalFrame.sp40, &Speedway35Format3View, temporaryWord3, temporaryWord7, temporaryWord17);
                    __asm__ __volatile__(""::"i"(0x1086000a):"memory");
                }
                else{
                    argumentWord4 = (int)&originalFrame.sp40;
                    argumentWord5 = (int)&Speedway35Format4View;
                    argumentWord6 = temporaryWord7;
                    __asm__ __volatile__(""::"r"(argumentWord6):"$7", "memory");
                    argumentWord7 = temporaryWord17;
                    Speedway35CallsprintfView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                    __asm__ __volatile__(""::"i"(0x1086000b):"memory");
                }
            }
            Speedway35CallDrawStringCenteredView1(&originalFrame.sp40, 0xC0, 0x7B, 2);
        }
        if (Speedway35Data6FBC8View1 >= 3) {
            Speedway35CallDrawStringCenteredView1(*(int*)(&Speedway35Data6C444View1 + (Speedway35Data6C76CView1 * 4)), 0x140, 0x6A, 2);
            Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C444View1 + (Speedway35Data6C76CView1 * 4)));
            temporaryWord10 = &Speedway35DataspeedwayRecordsView1 + 0x28 + (Speedway35Data6FA38View1 * 0x2C);
            temporaryWord4 = *temporaryWord10 / 3600;
            temporaryWord8 = (*temporaryWord10 / 60) - (temporaryWord4 * 0x3C);
            temporaryWord18 = ((*temporaryWord10 % 60) * 0x64) / 60;
            if (*temporaryWord10 == 0x8CA0){
                Speedway35CallsprintfView1(&originalFrame.sp50, &Speedway35Format5View, temporaryWord4, temporaryWord8);
                __asm__ __volatile__(""::"i"(0x1086000c):"memory");
            }
            else{
                if (temporaryWord4){
                    Speedway35CallsprintfView1(&originalFrame.sp50, &Speedway35Format3View, temporaryWord4, temporaryWord8, temporaryWord18);
                    __asm__ __volatile__(""::"i"(0x1086000d):"memory");
                }
                else{
                    argumentWord4 = (int)&originalFrame.sp50;
                    argumentWord5 = (int)&Speedway35Format4View;
                    argumentWord6 = temporaryWord8;
                    __asm__ __volatile__(""::"r"(argumentWord6):"$7", "memory");
                    argumentWord7 = temporaryWord18;
                    Speedway35CallsprintfView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                    __asm__ __volatile__(""::"i"(0x1086000e):"memory");
                }
            }
            Speedway35CallDrawStringCenteredView1(&originalFrame.sp50, 0x140, 0x7B, 2);
        }
        if ((Speedway35Data6FBC8View1 >= 4) && (Speedway35Data6FA44View1 < 2)) {
            argumentWord7 = 2;
            if (Speedway35Data6FA74View1 < *(int*)(&Speedway35DataspeedwayRecordsView1 + 0x28 + (Speedway35Data6FA38View1 * 0x2C))) {
                argumentWord4 = (int)&Speedway35Data6C448View1;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                rawWord2 = Speedway35Data6C76CView1;
                rawWord3 = Speedway35Data6FBC4View1;
                rawWord2 <<= 2;
                rawWord3 &= 31;
                rawWord3 = rawWord3 < 22;
                rawWord2 += argumentWord4;
                if (rawWord3)argumentWord7 = 3;
                argumentWord4 = Speedway35Field(rawWord2, int*, 0);
                argumentWord5 = 256;
                __asm__ __volatile__(""::"i"(0x1086000f):"$6", "memory");
                argumentWord6 = 90;
                goto drawSecondComparisonCaption;
            }
            else{
                argumentWord5 = 256;
                rawWord2 = Speedway35Data6C76CView1;
                __asm__ __volatile__("":::"$6", "memory");
                argumentWord6 = 90;
                rawWord2 <<= 2;
                argumentWord4 = Speedway35Field(&Speedway35Data6C44CView1, int*, rawWord2);
                drawSecondComparisonCaption:Speedway35CallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            }
        }
        if (Speedway35Data6FBC8View1 == 5) {
            widthOrPrimitive16 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data69DD8View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data69DDCView1 + (Speedway35Data6C76CView1 * 4)));
            rowOrTable17 = (int)&Speedway35Data69DD8View1;
            __asm__("":"=r"(rowOrTable17):"0"(rowOrTable17));
            entryOrTable18 = (int)&Speedway35Data69DDCView1;
            __asm__("":"=r"(entryOrTable18):"0"(entryOrTable18));
            rawWord3 = rawWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            if (widthOrPrimitive16 < rawWord3)widthOrPrimitive16 = rawWord3;
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord3 = widthOrPrimitive16+10;
            widthOrPrimitive16 = rawWord3+rawWord2;
            rawWord3 = widthOrPrimitive16 >> 1;
            rawWord2 = 256;
            widthOrPrimitive16 = rawWord2-rawWord3;
            Speedway35Call2E748View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)), widthOrPrimitive16, 0x96, 2, 0);
            rawWord2 = Speedway35Call2EBB0View1(*(int*)(&Speedway35Data6C438View1 + (Speedway35Data6C76CView1 * 4)));
            rawWord3 = widthOrPrimitive16+10;
            widthOrPrimitive16 = rawWord3+rawWord2;
            argumentWord7 = 0;
            __asm__("":"=r"(argumentWord7):"0"(argumentWord7));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBCCView1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2+rowOrTable17;
            if (!rawWord3){
                rawWord2 = Speedway35Data6FBC4View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = widthOrPrimitive16;
            argumentWord6 = 150;
            Speedway35Call2E748View1(Speedway35Field(argumentWord4, int*, 0), argumentWord5, argumentWord6, argumentWord7|2, 0);
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBCCView1;
            rawWord2 <<= 2;
            argumentWord4 = rawWord2+entryOrTable18;
            __asm__ __volatile__(""::"r"(argumentWord4):"$2", "memory");
            rawWord2 = 1;
            __asm__ __volatile__(""::"r"(rawWord2):"$7", "memory");
            argumentWord7 = 0;
            if (rawWord3 == rawWord2){
                rawWord2 = Speedway35Data6FBC4View1;
                rawWord2 &= 31;
                argumentWord7 = rawWord2 < 22;
            }
            argumentWord5 = widthOrPrimitive16;
            argumentWord6 = 164;
            drawFinalSelectionRow:Speedway35Call2E748View1(Speedway35Field(argumentWord4, int*, 0), argumentWord5, argumentWord6, argumentWord7|2, 0);
            return;
        }
        argumentWord7 = 2;
        if (Speedway35Data6FBC8View1 == 6) {
            argumentWord4 = (int)&Speedway35Data6C43CView1;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            rawWord2 = Speedway35Data6C76CView1;
            rawWord3 = Speedway35Data6FBC4View1;
            rawWord2 <<= 2;
            rawWord3 &= 31;
            rawWord3 = rawWord3 < 22;
            rawWord2 += argumentWord4;
            if (rawWord3)argumentWord7 = 3;
            argumentWord4 = Speedway35Field(rawWord2, int*, 0);
            argumentWord5 = 256;
            argumentWord6 = 156;
            drawFinalCenteredCaption:Speedway35CallDrawStringCenteredView1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
        }
        break;
    }
}
#undef Speedway35Field


extern SpeedwayRecord speedwayRecords[];
extern SpeedwayData D_8006FA38;
void func_level_35_80084938(Moby* argument) {
    register Moby* moby __asm__("$8") = argument;
    int index = 0;
    register SpeedwayRecord* records __asm__("$9") = speedwayRecords;
    SpeedwayData* data = &D_8006FA38;
    int* count = data->timeAttackMobys;
    for (; index < 4; index++, count++) {
        register int speedwayIndex __asm__("$3") = data->speedwayIndex;
        register int mobyClass __asm__("$4") = moby->mobyClass;
        register unsigned int recordOffset __asm__("$2") = speedwayIndex * sizeof(SpeedwayRecord);
        register unsigned int address __asm__("$3") = index * 4;
        __asm__ volatile("" : "=r"(recordOffset) : "0"(recordOffset), "r"(address), "r"(mobyClass));
        recordOffset += (unsigned int)records;
        address += recordOffset;
        __asm__ volatile("" : "=r"(address) : "0"(address));
        if (*(int*)address == mobyClass) {
            (*count)++;
            data->dat_8006fa68 = index;
            break;
        }
    }
}

/* Rev0 80082C80..80083088,258 original words. Reuses upstream
 * HudEntry/SpriteData and verified EXE29674/29708/289C8 interfaces.
 * Raw halfword/byte widths, record stride84 and blend shift8 are retail.
 * Interpolation uses low32 products and arithmetic right shift8, with raw
 * weights clamped0..256. The sine lookup uses a byte offset, not an index.
 * Coordinate units, global/table producers, packet consumers and caller
 * cadence remain unresolved. Empty asm constraints emit no instructions and
 * preserve GCC2.7.2 lifetimes, original reads/stores and delay-slot scheduling.
 * Confidence: exact compiled Rev0 words, subject to full linked/hash audit.
 * AI-generated reconstruction; not yet human reviewed. */
typedef struct { short target; unsigned short phase; int timer; } DecodedHudTransition;
extern DecodedHudTransition DecodedHudTransit __asm__("D_8006FA88");
extern short DecodedHudPhase __asm__("D_8006FA8A");
extern int DecodedHudTimer __asm__("D_8006FA8C");
extern int DecodedHudSelection __asm__("D_8006FA6C");
extern int DecodedHudPrevious __asm__("D_8006FA68");
extern int D_8006C648, D_8006E344;
extern short D_800658A0[];
extern short DecodedHudTargets[] __asm__("D_80067262");
int func_level_35_800849BC(HudEntry* argument) {
    int x,y,drawFrame,drawX,drawY,reserved24;
    register HudEntry* hud __asm__("$18") = argument;
    register SpriteData* sprite __asm__("$16");
    register int slot __asm__("$17");
    register unsigned char* global __asm__("$19");
    register int frame __asm__("$20");
    register int destinationY __asm__("$21");
    register int destinationX __asm__("$22");
    register int spacing __asm__("$23");
    {
        register int* xPointer __asm__("$5") = &x;
        register int* yPointer __asm__("$6");
        register int spriteIndex __asm__("$2");
        register SpriteData* spriteBase __asm__("$3");
        register int sourceY __asm__("$7");
        register int sourceX __asm__("$3");
        register int widthEnd __asm__("$2");
        register int widthStart __asm__("$8");
        __asm__("" : "=r"(xPointer) : "0"(xPointer));
        spriteIndex = (unsigned char)hud->unk1C.frame;
        __asm__("" : "=r"(spriteIndex) : "0"(spriteIndex) : "memory");
        spriteBase = D_8006C788;
        sourceY = hud->unk2;
        __asm__("" : "=r"(spriteBase), "=r"(sourceY) : "0"(spriteBase), "1"(sourceY), "r"(spriteIndex));
        sprite = &spriteBase[spriteIndex];
        widthEnd = sprite->unk4;
        widthStart = sprite->unk0;
        sourceX = hud->unk0;
        yPointer = &y;
        y = sourceY;
        spacing = widthEnd - widthStart + 2;
        x = sourceX;
        func_80029674(hud,xPointer,yPointer);
    }
    {
        register int initialFrame __asm__("$2") = (unsigned char)hud->movementFrame;
        __asm__("" : "=r"(initialFrame) : "0"(initialFrame));
        if (initialFrame) {
            initialFrame += 10;
            __asm__("" : "=r"(initialFrame) : "0"(initialFrame));
            frame = initialFrame >> 1;
        } else {
            __asm__("" : "=r"(initialFrame) : "0"(initialFrame));
            frame = 0;
        }
    }
    y -= (sprite->unk5 - sprite->unk1) >> 1;
    /* Find the original84-byte HUD record without adding a fallback slot. */
    slot = 0;
    if (*hud->unk28 == 8) {
        global = (unsigned char*)&DecodedHudTransit;
        {
            register int target __asm__("$4") = *(short*)global;
            register int offset __asm__("$3") = 0;
            for (; slot < 8; slot++,offset += 84) {
                if (*(short*)((char*)DecodedHudTargets + offset) == target) break;
                __asm__ volatile ("" : : : "memory");
            }
        }
        {
            register int rawX __asm__("$6") = D_80067248[slot].unk0;
            register int width __asm__("$7") = (unsigned char)D_80067248[slot].unk3C;
            register int rawY __asm__("$9") = D_80067248[slot].unk2;
            register int bottom __asm__("$5") = sprite->unk5;
            register int top __asm__("$8") = sprite->unk1;
            register int delta __asm__("$3") = D_8006C648;
            register int nextPhase __asm__("$2") = *(unsigned short*)(global + 2) + delta;
            register int nextTimer __asm__("$4") = *(int*)(global + 4) - delta;
            __asm__("" : "=r"(nextTimer), "=r"(rawY) : "0"(nextTimer), "1"(rawY));
            rawX -= width;
            destinationY = rawY - ((bottom - top) >> 1);
            delta = *(int*)(global - 0x1C);
            *(unsigned short*)(global + 2) = nextPhase;
            *(int*)(global + 4) = nextTimer;
            {
                register int scaled __asm__("$2") = delta * 34;
                __asm__("" : "=r"(scaled) : "0"(scaled));
                destinationX = rawX + scaled;
            }
        }
        if (*(int*)(global + 4) <= 0 && D_8006E344 == 0) {
            func_8003BB10(0,0,0);
            *(int*)(global + 4) = 20;
        }
    } else {
        DecodedHudPhase = 0;
        DecodedHudTimer = 0;
    }
    slot = 0;
    global = (unsigned char*)&DecodedHudSelection;
    do {
        register int blend __asm__("$5");
        drawFrame = frame;
        drawX = x;
        drawY = y;
        func_80029708(hud,&drawFrame,&drawX,&drawY);
        {
            register int count __asm__("$3") = *hud->unk28;
            __asm__("" : "=r"(count) : "0"(count) : "$5");
            blend = 0;
        if (count == 8) {
            {
                register int phase __asm__("$3") = DecodedHudPhase;
                __asm__("" : "=r"(phase) : "0"(phase));
                blend = (phase - slot * 10) * 4;
            }
            if (blend < 0) blend = 0;
            if (blend > 256) blend = 256;
            /* Preserve all four low-word products and the intermediate Y store. */
            {
                register int firstX __asm__("$6") = blend * destinationX;
                register int weight __asm__("$3");
                register int currentX __asm__("$2");
                register int secondX __asm__("$8");
                register int firstY __asm__("$4");
                register int secondY __asm__("$3");
                register int sumY __asm__("$3");
                register int sine __asm__("$4");
                __asm__("" : "=r"(firstX), "=r"(blend) : "0"(firstX), "1"(blend));
                weight = 256;
                __asm__("" : "=r"(weight) : "0"(weight), "r"(firstX) : "memory");
                currentX = drawX;
                weight -= blend;
                secondX = weight * currentX;
                __asm__("" : "=r"(secondX), "=r"(blend), "=r"(weight) : "0"(secondX), "1"(blend), "2"(weight));
                firstY = blend * destinationY;
                secondY = weight * drawY;
                {
                    register int sumX __asm__("$2") = firstX + secondX;
                    __asm__("" : "=r"(sumX) : "0"(sumX));
                    drawX = sumX >> 8;
                }
                sumY = firstY + secondY;
                sine = *(short*)((char*)D_800658A0 + blend);
                __asm__("" : "=r"(sumY), "=r"(sine) : "0"(sumY), "1"(sine));
                sumY >>= 8;
                drawY = sumY;
                __asm__ volatile ("" : : : "memory");
                drawY = sumY - ((sine * 3) >> 8);
            }
        }
        }
        if (slot < *hud->unk28) {
            {
                register int stillMoving __asm__("$2") = blend < 256;
                __asm__("" : "=r"(stillMoving) : "0"(stillMoving));
            if (stillMoving) {
                int index = func_80028378(&hud->unk1C,slot);
                func_800289C8(&D_8006C788[index],drawX,drawY);
            } else if (slot == 7) {
                if (*(int*)global == *(int*)(global - 4)) *(int*)(global - 4) = -1;
                *(int*)global = -1;
            }
            }
        } else {
            unsigned char* packet;
            {
                register int spriteIndex __asm__("$2");
                register SpriteData* base __asm__("$3");
                register int positionX __asm__("$5") = drawX;
                register int positionY __asm__("$6") = drawY;
                __asm__("" : "=r"(positionX), "=r"(positionY) : "0"(positionX), "1"(positionY));
                spriteIndex = hud->unk1C.index;
                __asm__("" : "=r"(spriteIndex) : "0"(spriteIndex));
                spriteIndex = (unsigned char)D_8006C738[spriteIndex].frame;
                __asm__("" : "=r"(spriteIndex) : "0"(spriteIndex) : "memory");
                base = D_8006C788;
                sprite = &base[spriteIndex];
                packet = (unsigned char*)func_800289C8(sprite,positionX,positionY);
            }
            /* Original packet byte colours, command bit and halfword mask. */
            if ((sprite->unk6 & 0x60) == 0x60) {
                packet[4] = 64; packet[5] = 64; packet[6] = 64;
                packet[7] |= 2;
                *(unsigned short*)(packet + 0x16) &= 0xFF9F;
            } else {
                packet[4] = 32; packet[5] = 32; packet[6] = 32;
            }
        }
        {
            int currentX = x;
            __asm__("" : "=r"(slot) : "0"(slot), "r"(currentX));
            slot++;
            x = currentX + spacing;
        }
        frame--;
    } while (slot < 8);
    return 0;
}

typedef struct { SpriteAnimationData animation; unsigned char reserved06[2]; } DecodedHudDrawRecord;
extern int D_8006E344, D_8006C74C, D_8006C64C;
extern int D_8006FA58[];
int func_level_35_80084DC4(HudEntry* hud) {
    int x, y;
    register int slot __asm__("$17");
    DecodedHudDrawRecord* record;
    int* states;
    register int* xPointer __asm__("$5");
    register int* yPointer __asm__("$6");
    if (D_8006E344 == 3) return 0;
    if (D_8006C74C) return 0;
    if (D_8006C64C) return 0;
    xPointer = &x;
    yPointer = &y;
    /* Empty constraints preserve the retail coordinate/loop scheduling. */
    __asm__("" : "=r"(xPointer), "=r"(yPointer) : "0"(xPointer), "1"(yPointer));
    slot = 0;
    record = (DecodedHudDrawRecord*)hud->unk28;
    x = hud->unk0;
    y = hud->unk2;
    states = D_8006FA58;
    func_80029674(hud, xPointer, yPointer);
    do {
        if (*states == 8) {
            SpriteData* sprite;
            record->animation.frame = func_80028378(&record->animation, slot);
            sprite = &D_8006C788[(unsigned char)record->animation.frame];
            func_800289C8(sprite, x, y - ((sprite->unk5 - sprite->unk1) >> 1));
        }
        record++;
        {
            int nextX = x;
            __asm__("" : "=r"(slot) : "0"(slot), "r"(nextX));
            slot++;
            x = nextX + 0x22;
        }
        states++;
    } while (slot < 4);
    return 0;
}

typedef struct { SpriteAnimationData animation; unsigned char reserved06[2]; } DecodedHudSpriteRecord;
void func_level_35_80084ECC(HudEntry* hud) {
    register int slot __asm__("$17") = 0;
    register DecodedHudSpriteRecord* record __asm__("$18") = (DecodedHudSpriteRecord*)hud->unk28;
    register unsigned char* frame __asm__("$16");
    hud->unk3C = 0x86;
    frame = &record->animation.frame;
    do {
        int index = func_80027934(hud->unk24 + slot);
        record->animation.index = index;
        frame[-1] = D_8006C738[index].animationType;
        __asm__ volatile("" : : : "memory");
        record++;
        *frame = D_8006C738[index].frame;
        slot++;
        frame += 8;
    } while (slot < 4);
}

void func_level_35_80084F70(HudEntry* hud) {
    SpriteDefinition* definition;
    SpriteData* sprite;
    func_80027A60(hud);
    definition = &D_8006C738[hud->unk1C.index];
    /* Retail reads the low byte of this upstream halfword field. */
    hud->unk1C.frame = definition->frame + *(unsigned char*)&hud->unk40;
    sprite = &D_8006C788[(unsigned char)hud->unk1C.frame];
    hud->unk3C = sprite->unk4 - sprite->unk0;
}

typedef struct {
    short count, index, reserved04[3], step;
    unsigned char* records;
} DecodedSteerPath;
typedef struct {
    int speed, roll, pitch, yaw;
    int rollStep, pitchStep, yawStep, rollCoupling, rollLimit;
} DecodedSteerMotion;
void DecodedSteerSubtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
int DecodedSteerLength(Vector3D*, int) __asm__("func_8004EDE8");
int DecodedSteerAngle(int, int, int) __asm__("func_8004E880");
void DecodedSteerPrepare(Moby*, int) __asm__("func_80055D24");
void DecodedSteerRotate(SHORTMATRIX*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
void DecodedSteerAdd(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
/*
 * USA SCUS-94467 Rev 0: representative func_level_15_800832AC,
 * 0x800832AC..0x80083604 (214 words). Per-copy original sources and
 * word digests are recorded in overlay-batch-2026-10-04-1315.md.
 * Keep the original signed record-index remainder, wrapped 12-bit
 * angular words, signed shifts and low-word product. Byte-angle writes
 * use the original right shift by 4; vector/helper domains remain raw.
 * Empty asm constraints emit no instructions and retain the compiler's
 * register lifetimes and intermediate arithmetic destinations.
 * AI-generated reconstruction; not yet human reviewed. Caller cadence,
 * source table producers and browser/runtime interpretation are unresolved.
 */
void func_level_35_80084FE8(Moby* argument, DecodedSteerPath* pathArgument, DecodedSteerMotion* motionArgument) {
    Vector3D vector;
    int reserved1C;
    register Moby* moby __asm__("$19") = argument;
    register DecodedSteerPath* path __asm__("$16");
    register DecodedSteerMotion* motion __asm__("$17");
    register Vector3D* position __asm__("$18");
    register int error __asm__("$6");
    register int product __asm__("$7");
    __asm__("" : "=r"(moby) : "0"(moby));
    path = pathArgument;
    __asm__("" : "=r"(path) : "0"(path));
    motion = motionArgument;
    __asm__("" : "=r"(motion) : "0"(motion));
    position = &moby->position;
    /* The first difference is used for the original 1024 distance test. */
    DecodedSteerSubtract(&vector, position, (Vector3D*)(path->records + path->index * 16));
    if (DecodedSteerLength(&vector, 1) < 1024) {
        path->index = (path->index + path->step + path->count) % path->count;
    }
    DecodedSteerSubtract(&vector, (Vector3D*)(path->records + path->index * 16), position);
    error = (DecodedSteerAngle(vector.x, vector.y, 1) - motion->yaw) & 0xFFF;
    if (error > 2048) error -= 4096;
    /* A heading difference greater than 800 advances the record once more. */
    {
        register int magnitude __asm__("$2") = error;
        if (error < 0) magnitude = -magnitude;
        __asm__("" : "=r"(magnitude) : "0"(magnitude));
        if (magnitude > 800) {
            path->index = (path->index + path->step + path->count) % path->count;
            DecodedSteerSubtract(&vector, (Vector3D*)(path->records + path->index * 16), position);
            error = (DecodedSteerAngle(vector.x, vector.y, 1) - motion->yaw) & 0xFFF;
            if (error > 2048) error -= 4096;
        }
    }
    /* Retain the distinct yaw and roll/pitch integration equations. */
    {
        register int step __asm__("$4") = motion->yawStep;
        register int angle __asm__("$3") = motion->yaw;
        step += ((error - step * 9) * 2) >> 6;
        angle = (angle + step) & 0xFFF;
        motion->yaw = angle;
        motion->yawStep = step;
        moby->angle.yaw = angle >> 4;
    }
    {
        register int gain __asm__("$2") = motion->rollCoupling;
        gain = -gain;
        __asm__("" : "=r"(gain) : "0"(gain));
        product = gain * error;
        {
            register int roll __asm__("$2") = motion->roll;
            error = product >> 6;
            roll = error - roll;
            __asm__("" : "=r"(roll) : "0"(roll));
            error = roll & 0xFFF;
        }
    }
    if (error > 2048) error -= 4096;
    {
        register int step __asm__("$4") = motion->rollStep;
        register int change __asm__("$3") = (error * 2 - step * 24) >> 6;
        __asm__("" : "=r"(change) : "0"(change));
        step += change;
        motion->rollStep = step;
        motion->roll = (motion->roll + step) & 0xFFF;
        if (motion->roll > 2048) motion->roll -= 4096;
    }
    /* Clamp the signed roll word with the original fresh field reads. */
    if (motion->roll > motion->rollLimit) motion->roll = motion->rollLimit;
    if (motion->roll < -motion->rollLimit) motion->roll = -motion->rollLimit;
    moby->angle.roll = motion->roll >> 4;
    error = (DecodedSteerAngle(DecodedSteerLength(&vector, 0), vector.z, 1) - motion->pitch) & 0xFFF;
    if (error > 2048) error -= 4096;
    {
        register int step __asm__("$5") = motion->pitchStep;
        register int change __asm__("$3") = (error * 2 - step * 24) >> 6;
        __asm__("" : "=r"(change) : "0"(change));
        step += change;
        motion->pitchStep = step;
        motion->pitch = (motion->pitch + step) & 0xFFF;
        moby->angle.pitch = motion->pitch >> 4;
    }
    /* Prepare, rotate and add the original local forward vector. */
    vector.x = motion->speed;
    vector.y = 0;
    vector.z = 0;
    DecodedSteerPrepare(moby, 6);
    DecodedSteerRotate(&moby->rotationMatrix, &vector, &vector);
    DecodedSteerAdd(&moby->position, &moby->position, &vector);
}

int func_level_35_80085340(Moby* actor,Vector3D* position,int limit,Vector3D* output) {
    Vector3D delta;
    SHORTMATRIX matrix;
    int shifted;
    func_8004F1C8(&delta,position,&actor->position);
    if(output) {
        if(ABS(delta.x)>limit || ABS(delta.y)>limit || ABS(delta.z)>limit) {
            func_8004F110(&delta,3);shifted=1;
        } else shifted=0;
        func_8004ECF4(&matrix,&actor->rotationMatrix);
        func_8004ED6C(&matrix,&delta,&delta);
        if(shifted)func_8004F0E8(&delta,3);
        func_8004F178(output,&delta);
        if(!shifted && ABS(delta.x)<0x200 && func_8004EDE8(&delta,1)<limit)return 1;
    } else if(ABS(delta.x)<limit && ABS(delta.y)<limit && ABS(delta.z)<limit && func_8004EDE8(&delta,1)<limit) {
        func_8004ECF4(&matrix,&actor->rotationMatrix);
        func_8004ED6C(&matrix,&delta,&delta);
        if(ABS(delta.x)<0x200)return 1;
    }
    return 0;
}

void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_8004EDE8(Vector3D*, int);
int func_level_35_80085534(Moby* moby, Vector3D* position, int limit) {
    Vector3D delta;
    func_8004F1C8(&delta, position, &moby->position);
    if (ABS(delta.x) < limit && ABS(delta.y) < limit && ABS(delta.z) < limit) {
        if (func_8004EDE8(&delta, 1) < limit) return 1;
    }
    return 0;
}

typedef struct { short count; unsigned char reserved02[0xA]; PathNode* nodes; } DecodedNearestPath;
int func_8004F334(Vector3D*, Vector3D*);
int func_level_35_800855DC(Vector3D* position, DecodedNearestPath* path, int center, int radius) {
    /* Eight further retail stack bytes have an unknown source purpose. */
    int reservedStack[2];
    int bestDistance = 0xFFFFFF;
    register int index __asm__("$16") = 0;
    register int bestIndex __asm__("$18") = 0;
    register int extent __asm__("$3") = radius * 2;
    register int count __asm__("$21");
    int first;
    /* Empty constraints retain the original temporary and loop registers. */
    __asm__("" : "=r"(extent) : "0"(extent));
    if (extent > 0) {
        first = center - radius;
        count = extent;
        __asm__("" : "=r"(count) : "0"(count));
        do {
            register int wrapped __asm__("$17") = (first + index + path->count) % path->count;
            int distance = func_8004F334(position, &path->nodes[wrapped].pos);
            if (distance < bestDistance) {
                bestDistance = distance;
                bestIndex = wrapped;
            }
            index++;
        } while (index < count);
    }
    return bestIndex;
}

typedef struct { Vector3D origin; int unkC, unk10, unk14; } DecodedVectorRecord;
extern short D_800658A0[], D_80065920[];
void func_level_35_800856D4(Vector3D* out, int x, int y, DecodedVectorRecord* record) {
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

typedef struct { Vector3D position; int reserved0C; } DecodedBlendPoint;
typedef struct { short count, index; short reserved04[3], step; DecodedBlendPoint* points; } DecodedBlendPath;
typedef struct { short current, previous; } DecodedBlendWeight;
extern DecodedBlendWeight DecodedBlendWeights[] __asm__("D_80066F0C");
extern DecodedBlendWeight DecodedSingleWeight __asm__("D_8006C410");
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004F1FC(Vector3D*, Vector3D*, int);
void func_8004F110(Vector3D*, int);
int func_8004EDE8(Vector3D*, int);
void func_80037014(Moby*);
void func_80055D24(Moby*, int);
int func_level_35_800857AC(Moby* moby, DecodedBlendPath* path, Vector3D* previous,
        int* timer, int period, int flags) {
    struct { Vector3D delta; int reserved1C; Vector3D weightedPrevious; int reserved2C; } work;
    DecodedBlendWeight* weights;
    int threshold;
    int result = 0;
    int flat;
    /* Retail selects weight-table blocks by the supplied period. */
    if (period >= 9) { weights = DecodedBlendWeights + 10; threshold = 7; }
    else if (period >= 7) { weights = DecodedBlendWeights + 4; threshold = 5; }
    else if (period >= 5) { weights = DecodedBlendWeights; threshold = 3; }
    else { weights = &DecodedSingleWeight; threshold = 1; }
    if (*timer >= period) {
        short next;
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        func_8004F178(previous, &work.delta);
        next = (path->index + path->step + path->count) % path->count;
        path->index = next;
        result = 1;
        if ((path->step < 0 && next == path->count - 1)
                || (path->step > 0 && next == 0)) result |= 2;
        *timer = 0;
    } else if (*timer > threshold) {
        int divisor;
        register int elapsed __asm__("$2");
        register int x __asm__("$4"), y __asm__("$3"), z __asm__("$2");
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        /* Empty constraints retain the original subtraction and division allocation. */
        elapsed = *timer - 1;
        __asm__("" : "=r"(elapsed) : "0"(elapsed));
        divisor = period - elapsed;
        x = work.delta.x / divisor;
        y = work.delta.y / divisor;
        z = work.delta.z / divisor;
        __asm__("" : "=r"(x), "=r"(y), "=r"(z) : "0"(x), "1"(y), "2"(z));
        work.delta.x = x; work.delta.y = y; work.delta.z = z;
        (*timer)++;
    } else {
        int divisor;
        register int elapsed __asm__("$2");
        register int x __asm__("$4"), y __asm__("$3"), z __asm__("$2");
        func_8004F1C8(&work.delta, &path->points[path->index].position, &moby->position);
        /* Empty constraints retain the original subtraction and division allocation. */
        elapsed = *timer - 1;
        __asm__("" : "=r"(elapsed) : "0"(elapsed));
        divisor = period - elapsed;
        x = work.delta.x / divisor;
        y = work.delta.y / divisor;
        z = work.delta.z / divisor;
        __asm__("" : "=r"(x), "=r"(y), "=r"(z) : "0"(x), "1"(y), "2"(z));
        work.delta.x = x; work.delta.y = y; work.delta.z = z;
        func_8004F1FC(&work.delta, &work.delta, weights[*timer].current);
        func_8004F1FC(&work.weightedPrevious, previous, weights[*timer].previous);
        func_8004F194(&work.delta, &work.delta, &work.weightedPrevious);
        func_8004F110(&work.delta, 10);
        (*timer)++;
    }
    /* Bit 2 clears the vertical displacement and gates the extra actor helper. */
    flat = flags & 4;
    if (flat) work.delta.z = 0;
    moby->angle.yaw = func_8004E880(work.delta.x, work.delta.y, 0);
    moby->angle.pitch = -func_8004E880(work.delta.z, func_8004EDE8(&work.delta, 0), 0) + 0x40;
    func_8004F194(&moby->position, &moby->position, &work.delta);
    if (flat) func_80037014(moby);
    func_80055D24(moby, 2);
    return result;
}
