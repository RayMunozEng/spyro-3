#include "common.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_63_80074780(void) {}

/* AI-generated reconstruction; not human reviewed. Original Rev0 span
 * 80074788..80074AA0,198 words. Reuses upstream Moby/SpawnMoby/vector
 * interfaces. Two spawned records feed three signed-halfword orbit points:
 * phases3*tick and8*tick+43, increments85, multiply5>>6, low-word product
 * >>12. Raw effect result bytes68/69/6A feed wrapping color bytes. Empty
 * constraints preserve original argument/read/register lifetimes; signed
 * sample inputs explicitly extend to int and emit no added instructions.
 * Coordinates, table/record producers, helper/effect semantics and caller
 * cadence remain unresolved; compiled identity proves this source slice. */
typedef struct { Vector3D position; void* effect[3]; } DecodedCutsceneOrbitTag;
extern int D_8006C644;
extern short CutsceneOrbitCos[] __asm__("D_80065920");
extern short CutsceneOrbitSin[] __asm__("D_800658A0");
void CutsceneOrbitDraw(Moby*,int) __asm__("func_80055D24");
void CutsceneOrbitPoint(Moby*,int,Vector3D*) __asm__("func_80055F14");
void CutsceneOrbitAdd(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F194");
void CutsceneOrbitShift(Vector3D*,int) __asm__("func_8004F110");
void* CutsceneOrbitEffect(Vector3D*,int,int,int) __asm__("func_80050844");
void func_cutscene_63_80074788(Moby* argument) {
    register Moby* moby __asm__("$17")=argument;
    register Moby* child __asm__("$16");
    register Vector3D* temporary __asm__("$16");
    register DecodedCutsceneOrbitTag* first __asm__("$21");
    register DecodedCutsceneOrbitTag* second __asm__("$20");
    register int index __asm__("$16");
    register int phaseA __asm__("$19");
    register int phaseB __asm__("$18");
    register short* cosine __asm__("$23");
    register short* sine __asm__("$22");
    Vector3D center;int pad1;
    Vector3D offset;int pad2;
    __asm__("" : "=r"(moby) : "0"(moby) : "$4");
    if(moby->state==0) {
        child=SpawnMoby(0x2C3A,moby);
        moby->mobyTag=child->mobyTag;
        moby->damageFlags=(int)SpawnMoby(0x2C3A,moby);
        first=child->mobyTag;
        second=((Moby*)moby->damageFlags)->mobyTag;
        CutsceneOrbitDraw(moby,4);
        CutsceneOrbitPoint(moby,0,&center);
        { register Moby* ownerArgument __asm__("$4")=moby;
          register int selector __asm__("$5")=1;
          __asm__("" : : "r"(ownerArgument), "r"(selector) : "$16");
          temporary=&offset;
          CutsceneOrbitPoint(ownerArgument,selector,temporary); }
        CutsceneOrbitAdd(&center,&center,temporary);
        CutsceneOrbitShift(&center,1);
        func_8004F178(&first->position,&center);
        temporary=(Vector3D*)first->effect;
        func_8004F178(temporary,&center);
        func_8004F178(&second->position,&center);
        second->effect[0]=CutsceneOrbitEffect(&first->position,10,10,0xA03396);
        second->effect[1]=CutsceneOrbitEffect(temporary,10,10,0xA03396);
        second->effect[2]=CutsceneOrbitEffect(&second->position,10,10,0xA03396);
        moby->state=1;
    } else {
        first=moby->mobyTag;
        second=((Moby*)moby->damageFlags)->mobyTag;
        CutsceneOrbitDraw(moby,4);
        CutsceneOrbitPoint(moby,0,&center);
        { register Moby* ownerArgument __asm__("$4")=moby;
          register int selector __asm__("$5")=1;
          __asm__("" : : "r"(ownerArgument), "r"(selector) : "$16");
          temporary=&offset;
          CutsceneOrbitPoint(ownerArgument,selector,temporary); }
        CutsceneOrbitAdd(&center,&center,temporary);
        CutsceneOrbitShift(&center,1);
    }
    index=0;
    cosine=CutsceneOrbitCos;
    __asm__("" : : "r"(cosine));
    { register int tick __asm__("$2")=D_8006C644;
      sine=CutsceneOrbitSin;
      __asm__("" : : "r"(sine), "r"(tick));
      { register int doubled __asm__("$3")=tick<<1;
        __asm__("" : : "r"(doubled));
        phaseA=doubled+tick;phaseB=(tick<<3)+43; } }
    for(;index<3;index++,phaseB+=85) {
        int a=(phaseA&255),b=(phaseB&255);
        Vector3D* destination;
        { register int partial __asm__("$3")=cosine[a]*5>>6;
          __asm__("" : : "r"(partial));
          offset.x=(partial*cosine[b])>>12; }
        { register int sample __asm__("$3");
          __asm__("" : "=&r"(sample) : "0"((int)sine[a]) : "$2");
          offset.y=((sample*5>>6)*cosine[b])>>12; }
        { register int sample __asm__("$3");
          __asm__("" : "=&r"(sample) : "0"((int)sine[b]) : "$2");
          offset.z=sample*5>>6; }
        if(index==0)destination=&first->position;
        else { register int one __asm__("$2")=1;
          __asm__("" : : "r"(one));
          if(index==one)destination=(Vector3D*)first->effect;
          else destination=&second->position; }
        CutsceneOrbitAdd(destination,&center,&offset);
        phaseA+=85;
        __asm__("" : "=r"(phaseA) : "0"(phaseA));
    }
    { unsigned char value=((unsigned char*)second->effect[0])[0x68];moby->colour.r=value+(value>>1); }
    __asm__("" : : : "memory");
    { unsigned char value=((unsigned char*)second->effect[0])[0x69];moby->colour.g=value+(value>>1); }
    __asm__("" : : : "memory");
    { unsigned char value=((unsigned char*)second->effect[0])[0x6A];moby->colour.b=value+(value>>1);moby->colour.a=0; }
}

void func_cutscene_63_80074AA0(void) {}

extern Moby* D_8006C550;
Moby* func_80055A7C(void);
void func_80034FEC(Moby*);
int func_80055D10(Moby*);
int func_80055C24(Moby*);
void func_8004F178(Vector3D*, Vector3D*);
Moby* func_cutscene_63_80074AA8(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C();
    void* tag;
    if (!moby) return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, sizeof(Moby));
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        int index = parent - D_8006C550;
        if ((unsigned int)index < 0x100) moby->linkedMoby = index;
        else moby->linkedMoby = 0xFF;
    } else moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    if (mobyClass == 0x2C3A) {
        func_8004F178(&moby->position, &parent->position);
        moby->mobyClass = 0xFF;
        moby->distanceToGround = 0x2C3A;
        func_80055D10(moby);
        moby->updateDistance = 0xFF;
    } else {
        if (parent) func_8004F178(&moby->position, &parent->position);
        else func_8004F178(&moby->position, &spyro.position);
        func_80055C24(moby);
    }
    return moby;
}
