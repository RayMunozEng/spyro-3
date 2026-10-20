#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "ovl_header.h"

void func_cutscene_78_80074780(void) {}

void func_cutscene_78_80074788(Moby* moby) {
    if (moby->state == 0) {
        if (SpawnMoby(0x28F0, moby)) moby->state = 1;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
#include "common.h"
extern Moby* P747DC_D_8006C550 __asm__("D_8006C550");
extern short P747DC_D_800658A0[] __asm__("D_800658A0");
extern short P747DC_D_80065920[] __asm__("D_80065920");
void P747DC_func_80055D24(Moby*, int) __asm__("func_80055D24");
int P747DC_func_8004F168(Vector3D *) __asm__("func_8004F168");
int P747DC_func_80055F14(Moby *, int, int *) __asm__("func_80055F14");
extern int P747DC_D_8006C598 __asm__("D_8006C598");
extern int P747DC_D_8006EDDC __asm__("D_8006EDDC");


int P747DC_func_8004E880(int,int,int) __asm__("func_8004E880");
/* AI-generated; not human reviewed. Verified cutscene73 C baseline and
 * complete original SCUS-94467 Rev0 cutscene78/800747DC instructions.
 * Raw field widths, pool stride88, signed table products and three spawn
 * sequences retained. Helper meanings, units and cadence unresolved. */
void func_cutscene_78_800747DC(Moby *argument) {
    register Moby* owner __asm__("$19") = argument;
    union {int words[8];struct {Vector3D v10;int pad1;Vector3D v20;int pad2;} vectors;} frame;
    register int recordBase2 __asm__("$2");
    register int scanLoop __asm__("$18");
    register int scanOffset17 __asm__("$17");
    register int scanClass20 __asm__("$20");
    register Vector3D *vector20Pointer __asm__("$16");
    register Moby *scanPointer5 __asm__("$5");

    register Moby *selectedMoby __asm__("$16");
    register Vector3D *ownerPosition __asm__("$18");
    register Vector3D *privateState19 __asm__("$17");
    register int globalWord __asm__("$20");
    register int scanOffset __asm__("$4");
    register int condition __asm__("$2");
    register int tableSample __asm__("$3");
    register Vector3D* vectorArgument __asm__("$6");
    register Vector3D* argument4 __asm__("$4"), *argument5Pointer __asm__("$5");
    register int scanClass __asm__("$6"),scanOne __asm__("$5"),linkedIndex __asm__("$3"),argument5 __asm__("$5");
    signed char *effect0;
    signed char *effect1;
    register int scanIndex __asm__("$3");
    register int stateByte __asm__("$3");
    register void *privateState16 __asm__("$16");

    __asm__("" : "=r"(owner) : "0"(owner));
    stateByte = owner->state;
    globalWord = P747DC_D_8006EDDC;
    switch (stateByte) {
    case 0:
        __asm__("" : : : "$3");
        if (P747DC_D_8006C598 == 0) {
            scanIndex = 0;
            scanClass=0x28A0;scanOne=1;
            __asm__("" : "=r"(scanClass),"=r"(scanOne):"0"(scanClass),"1"(scanOne):"$4");
            scanOffset = 0;
            do {
                if ((*(short *)((unsigned char*)((scanOffset + (int)P747DC_D_8006C550)) + 0x38)) == scanClass) {
                    owner->state = scanOne;
                    owner->linkedMoby = scanIndex;
                }
                scanIndex += 1;
                scanOffset += 0x58;
            } while (scanIndex < 4);
            return;
        }
        break;
    case 1:
        condition = globalWord < 0x6C4;
        __asm__("" : "=r"(condition):"0"(condition));
        if (!condition) {
            argument5 = 4;
            __asm__ volatile("" ::: "$2","memory");
            scanLoop=0;
            scanClass20=0x28A2;
            __asm__("" : "=r"(scanLoop),"=r"(scanClass20) : "0"(scanLoop),"1"(scanClass20));
            scanOffset17=0;
            __asm__("" : "=r"(scanLoop),"=r"(scanClass20),"=r"(scanOffset17) : "0"(scanLoop),"1"(scanClass20),"2"(scanOffset17));
            linkedIndex = (unsigned char)owner->linkedMoby;
            __asm__("" : : "r"(argument5),"r"(linkedIndex):"$2");
            owner->state = 2;
            selectedMoby = P747DC_D_8006C550;
            __asm__("" : "=r"(selectedMoby):"0"(selectedMoby),"r"(linkedIndex));
            selectedMoby += linkedIndex;
            P747DC_func_80055D24(selectedMoby, argument5);
            P747DC_func_80055F14(selectedMoby, 0, &frame.vectors.v10);
            func_8004F178(&owner->position, (Vector3D *) &frame.vectors.v10);
            owner->angle.yaw = selectedMoby->angle.yaw;
            SpawnMoby(0x28F0, owner);
            privateState16 = owner->mobyTag;
            func_8004F178((Vector3D *) privateState16, (Vector3D *) &frame.vectors.v10);
            do{
                recordBase2=(int)P747DC_D_8006C550;
                __asm__("" : "=r"(recordBase2) : "0"(recordBase2) : "$5","memory");
                scanPointer5=(Moby*)(scanOffset17+recordBase2);
                if(*(short*)((unsigned char*)scanPointer5+0x38)==scanClass20){
                    (*(int*)((unsigned char*)privateState16+12))=P747DC_func_8004E880(
                        scanPointer5->position.x-owner->position.x,
                        scanPointer5->position.y-owner->position.y,0);
                }
                scanLoop+=1;
                scanOffset17+=88;
            }while(scanLoop<4);
            return;
        }
        break;
    case 2:
        ownerPosition = &owner->position;
        privateState19 = owner->mobyTag;
        func_8004F178(ownerPosition, privateState19);
        owner->angle.yaw = (unsigned char) (*(int *)((unsigned char*)(privateState19) + 0xC));
        P747DC_func_8004F168(&frame.vectors.v10);
        effect0 = SpawnParticle(1, 0x37, ownerPosition, &frame.vectors.v10);
        {register int tableSample __asm__("$2");
        tableSample = P747DC_D_80065920[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample):"$4","$5","$6");
        argument4 = ownerPosition;
        __asm__("" : : "r"(argument4));
        frame.vectors.v10.x = (tableSample * 75) >> 9;
        __asm__("" : : : "memory");
        argument5Pointer = ownerPosition;
        tableSample = P747DC_D_800658A0[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample),"r"(argument5Pointer):"$6");
        vectorArgument = &frame.vectors.v10;
        __asm__("" : "=m"(frame.vectors.v10.z):"r"(tableSample),"r"(vectorArgument));
        *(volatile int*)&frame.vectors.v10.z = 0;
        __asm__("" : "=r"(tableSample):"0"(tableSample),"m"(frame.vectors.v10.z));
        frame.vectors.v10.y = (tableSample * 75) >> 9;
        func_8004F194(argument4, argument5Pointer, vectorArgument);
        }
        tableSample = P747DC_D_80065920[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample):"$4","$5","$6");
        argument4 = &frame.vectors.v10;
        __asm__("" : : "r"(argument4));
        frame.vectors.v10.x = (tableSample * 0x19) >> 9;
        __asm__("" : : : "memory");
        argument5Pointer = privateState19;
        tableSample = P747DC_D_800658A0[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample),"r"(argument5Pointer):"$6");
        vectorArgument = argument4;
        __asm__("" : "=m"(frame.vectors.v10.z):"r"(tableSample),"r"(vectorArgument));
        *(volatile int*)&frame.vectors.v10.z = 0;
        __asm__("" : "=r"(tableSample):"0"(tableSample),"m"(frame.vectors.v10.z));
        frame.vectors.v10.y = (tableSample * 0x19) >> 9;
        func_8004F194(argument4, argument5Pointer, vectorArgument);
        vector20Pointer=&frame.vectors.v20;
        __asm__("" : "=r"(vector20Pointer) : "0"(vector20Pointer));
        P747DC_func_8004F168(vector20Pointer);
        SpawnParticle(1,0x37,&frame.vectors.v10,vector20Pointer);
        tableSample = P747DC_D_80065920[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample):"$4","$5","$6");
        argument4 = &frame.vectors.v10;
        __asm__("" : : "r"(argument4));
        frame.vectors.v10.x = (tableSample * 0x19) >> 8;
        __asm__("" : : : "memory");
        argument5Pointer = privateState19;
        tableSample = P747DC_D_800658A0[owner->angle.yaw];
        __asm__("" : "=r"(tableSample):"0"(tableSample),"r"(argument5Pointer):"$6");
        vectorArgument = argument4;
        __asm__("" : "=m"(frame.vectors.v10.z):"r"(tableSample),"r"(vectorArgument));
        *(volatile int*)&frame.vectors.v10.z = 0;
        __asm__("" : "=r"(tableSample):"0"(tableSample),"m"(frame.vectors.v10.z));
        frame.vectors.v10.y = (tableSample * 0x19) >> 8;
        func_8004F194(argument4, argument5Pointer, vectorArgument);
        P747DC_func_8004F168(vector20Pointer);
        SpawnParticle(1,0x37,&frame.vectors.v10,vector20Pointer);
        func_8004F178(privateState19, ownerPosition);
        (*(int *)((unsigned char*)(privateState19) + 0xC)) = (int) owner->angle.yaw;
        __asm__("" : : : "$2", "memory");
        condition = globalWord < 0x6EC;
        __asm__("" : "=r"(condition):"0"(condition));
        if (!condition) {
            owner->state = 3;
        }
        return;
    }
}


void func_cutscene_78_80074BC0(void) {}

extern Moby* func_80055A7C(void);
extern Moby* D_8006C550;
Moby* func_cutscene_78_80074BC8(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C();
    void* tag;
    unsigned int index;
    if (!moby) return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, sizeof(Moby));
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        index = parent - D_8006C550;
        if (index < 0x100) moby->linkedMoby = index;
        else moby->linkedMoby = 0xFF;
    } else moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    switch (mobyClass) {
    case 0x28A3:
        func_8004F178(&moby->position, &parent->position);
        moby->mobyClass = 3;
        moby->distanceToGround = 0x28A3;
        func_80055C24(moby);
        moby->updateDistance = 0xFF;
        moby->lowDrawDistance = 0x40;
        break;
    case 0x28F0:
        func_8004F178(&moby->position, &parent->position);
        moby->mobyClass = 0xFF;
        moby->distanceToGround = 0x28F0;
        func_80055D10(moby);
        moby->updateDistance = 0xFF;
        parent->mobyTag = moby->mobyTag;
        break;
    default:
        if (parent) func_8004F178(&moby->position, &parent->position);
        else func_8004F178(&moby->position, (Vector3D*)&spyro);
        func_80055C24(moby);
        break;
    }
    return moby;
}
