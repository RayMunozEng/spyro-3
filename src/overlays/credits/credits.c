#include "libgpu.h"
#include "common.h"
#include "stdutil.h"
#include "drawutil.h"

extern void* D_8006C664;

/**
 * ???() - func_credits_800744BC() - MATCHING
 * https://decomp.me/scratch/0F0ce
 */
void func_credits_800744BC(int arg0, char r, char g, char b) {
    struct {
        DR_MODE drMode;
        POLY_F4 f4;
    } *poly = D_8006C664;
    
    func_8005C564(&poly->drMode, 1, 0, arg0 << 5, 0);
    func_8004E71C(&poly->drMode.tag, 8);
    poly->f4.tag = 0x05000000;
    poly->f4.code = 0x28 | 2;
    poly->f4.y0 = 0xC;
    poly->f4.y1 = 0xC;
    poly->f4.x0 = 0;
    poly->f4.x1 = 0x200;
    poly->f4.x2 = 0;
    poly->f4.y2 = 0xE4;
    poly->f4.x3 = 0x200;
    poly->f4.y3 = 0xE4;
    poly->f4.r0 = r;
    poly->f4.g0 = g;
    poly->f4.b0 = b;
    func_8004E71C(&poly->f4.tag, 8);
    D_8006C664 = poly + 1;
}

/* AI-generated, not human reviewed. Original byte-offset relocation chain. */
extern int* CreditsEnvironmentNodes __asm__("D_8006D068");
extern int CreditsEnvironmentNodeCount __asm__("D_8006D06C");
extern char* CreditsEnvironmentPacked __asm__("D_8006C724");
extern int CreditsEnvironmentPackedCount __asm__("D_8006C77C");
extern int* CreditsEnvironmentOffsets __asm__("D_8006D048");
extern int CreditsEnvironmentOffsetCount __asm__("D_8006D04C");
extern char* CreditsEnvironmentFirst __asm__("D_8006D050");
extern char* CreditsEnvironmentSecond __asm__("D_8006D054");
extern int CreditsEnvironmentFirstMode __asm__("D_8006D058");
extern int CreditsEnvironmentLimit __asm__("D_8006D074");
extern char* CreditsEnvironmentData __asm__("D_8006E340");
extern unsigned char CreditsEnvironmentR __asm__("D_8006E33C"), CreditsEnvironmentG __asm__("D_8006E33D"), CreditsEnvironmentB __asm__("D_8006E33E");
extern int CreditsEnvironmentDataCount __asm__("D_8006E334");
extern int* CreditsEnvironmentDataOffsets __asm__("D_8006E338");
extern unsigned short CreditsEnvironmentConfig __asm__("D_8006C6A8");
void CreditsEnvironmentFinish(char*,int) __asm__("func_8002C9F4");
void CreditsEnvironmentSound(int,int,int) __asm__("PlaySound");
char* func_credits_8007458C(char* input) {
    char* cursor=input;
    register char* block __asm__("$17")=cursor;
    register int count __asm__("$2");
    int index;
    volatile int reservedStack[4];
    register int* nodeCount __asm__("$4");
    __asm__("" : "=r"(block) : "0"(block));
    cursor+=4;
    count=*(int*)cursor;
    cursor+=4;
    CreditsEnvironmentNodes=(int*)cursor;
    nodeCount=&CreditsEnvironmentNodeCount;
    *nodeCount=count;
    cursor=block+*(int*)block;
    block=cursor;
    cursor+=4;
    CreditsEnvironmentPacked=cursor+4;
    CreditsEnvironmentPackedCount=(*(int*)cursor-4)/28;
    cursor+=*(int*)cursor;
    count=*(int*)cursor;
    cursor+=4;
    CreditsEnvironmentOffsets=(int*)cursor;
    CreditsEnvironmentOffsetCount=count;
    index=0;
    if(count>0) {
        nodeCount=(int*)((char*)nodeCount-32);
        do {
            int offset=*(int*)cursor+4;
            __asm__("" : "=r"(offset) : "0"(offset));
            *(int*)cursor=(int)block+offset;
            index++;
            cursor+=4;
        }
        while(index<*nodeCount);
    }
    cursor=block+*(int*)block;
    block=cursor;
    __asm__("" : "=r"(block) : "0"(block));
    {
        int size=*(int*)cursor;
        int again=*(volatile int*)block;
        cursor+=size;
        if(again<9) {
            CreditsEnvironmentFirst=block;
            CreditsEnvironmentFirstMode=0;
        }
        else {
            register char* next __asm__("$2")=block+4;
            __asm__("" : "=r"(next) : "0"(next));
            CreditsEnvironmentFirst=next;
            CreditsEnvironmentFirstMode=1;
        }
    }
    CreditsEnvironmentLimit=180224;
    block=cursor;
    __asm__("" : "=r"(block) : "0"(block));
    {
        int size=*(int*)cursor;
        int again=*(volatile int*)block;
        cursor+=size;
        if(again<9) {
            CreditsEnvironmentSecond=block;
            *(int*)block=-1;
        }
        else {
            register char* next __asm__("$2")=block+4;
            __asm__("" : "=r"(next) : "0"(next));
            CreditsEnvironmentSecond=next;
        }
    }
    {
        register char** slot __asm__("$3")=&CreditsEnvironmentData;
        register int* offsets __asm__("$4");
        register int index __asm__("$5");
        *slot=cursor+4;
        CreditsEnvironmentR=cursor[4];
        CreditsEnvironmentG=cursor[5];
        count=(unsigned char)cursor[6];
        __asm__("" : : "r"(count) : "$4", "$5");
        offsets=(int*)(cursor+12);
        CreditsEnvironmentB=count;
        count=*(int*)(cursor+8);
        CreditsEnvironmentDataOffsets=offsets;
        CreditsEnvironmentDataCount=count;
        index=0;
        if(count>0) {
            register char** loopSlot __asm__("$6")=slot;
            do {
                *offsets=(int)*loopSlot+*offsets;
                index++;
                offsets++;
            }
            while(index<*(int*)((char*)loopSlot-12));
        }
    }
    {
        int config=(short)CreditsEnvironmentConfig;
        cursor+=*(int*)cursor;
        if((short)(config%12)==0) {
            block=cursor;
            CreditsEnvironmentFinish(block+4,1);
            __asm__("" : "=r"(block) : "0"(block));
            {
                register int zero __asm__("$4")=0;
                __asm__("" : : "r"(zero));
                count=*(int*)block;
                cursor=block+count;
                CreditsEnvironmentSound(zero,0,4);
            }
        }
    }
    return cursor;
}


/* AI integration, not human reviewed. EXE relocation baseline. */
extern int D_8006EE2C[];
void func_credits_80074820(int* arg0, int arg1, int* arg2) {
    volatile char stackSpace[16];
    register char* base __asm__("$12") = (char*)arg0;
    register char* root __asm__("$9") = base;
    register int firstWord __asm__("$2");
    register int index __asm__("$10");
    register int fieldOffset __asm__("$7");
    register char* cursor __asm__("$3");
    register char* record __asm__("$4");
    int count;

    if ((unsigned)root >= (unsigned)arg2) return;
    __asm__("" : "=r"(root): "0"(root));
    firstWord = *(volatile int*)root;
    __asm__("" : "=r"(firstWord) : "0"(firstWord));
    index = 0;
    if (firstWord < 0) {
        register char* negativeRoot __asm__("$8");
        negativeRoot=root;
        __asm__("" : "=r"(negativeRoot) : "0"(negativeRoot),"r"(root));
        fieldOffset = 8;
        cursor=root;
        __asm__("" : "=r"(cursor) : "0"(cursor),"r"(root));
        do {
            int value = *(int*)(cursor + 8);
            if (value != 0 && (unsigned)(negativeRoot + fieldOffset) < (unsigned)arg2) {
                *(int*)(cursor + 8) = (int)base + value;
            }
            fieldOffset += 4;
            index++;
            cursor += 4;
        } while (index < 2);
        if ((unsigned)(negativeRoot + 16) < (unsigned)arg2) {
            *(int*)(negativeRoot + 16) = (int)base + *(int*)(negativeRoot + 16);
        }
        count = -*(int*)negativeRoot;
        *(int*)negativeRoot = count;
        index = 0;
        if (count > 0) {
            register char* nestedCursor __asm__("$7") = negativeRoot;
            register int nestedOffset __asm__("$11") = 20;
            do {
                if ((unsigned)(negativeRoot + nestedOffset) < (unsigned)arg2) {
                    *(int*)(nestedCursor + 20) = (int)base + *(int*)(nestedCursor + 20);
                }
                record = *(char**)(nestedCursor + 20);
                if ((unsigned)(record + 8) < (unsigned)arg2) {
                    *(unsigned short*)(record + 8) = *(unsigned short*)(record + 8) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                    record = *(char**)(nestedCursor + 20);
                    *(unsigned short*)(record + 10) = *(unsigned short*)(record + 10) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                }
                record = *(char**)(nestedCursor + 20);
                if ((unsigned)(record + 12) < (unsigned)arg2) {
                    *(unsigned short*)(record + 12) = *(unsigned short*)(record + 12) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                    record = *(char**)(nestedCursor + 20);
                    *(unsigned short*)(record + 14) = *(unsigned short*)(record + 14) +
                        (*(int*)(negativeRoot + 16) - (int)record);
                }
                nestedCursor += 4;
                count = *(volatile int*)negativeRoot;
                index++;
                nestedOffset += 4;
            } while (index < count);
        }
        root = (char*)((unsigned)root & 0x7FFFFFFF);
    } else {
        index = 0;
        fieldOffset = 20;
        cursor=root;
        __asm__("" : "=r"(cursor) : "0"(cursor),"r"(root));
        do {
            int value = *(int*)(cursor + 20);
            if (value != 0 && (unsigned)(root + fieldOffset) < (unsigned)arg2) {
                *(int*)(cursor + 20) = (int)base + value;
            }
            fieldOffset += 4;
            index++;
            cursor += 4;
        } while (index < 8);
        if ((unsigned)(root + 52) < (unsigned)arg2) *(int*)(root + 52) = (int)base + *(int*)(root + 52);
        if ((unsigned)(root + 56) < (unsigned)arg2) *(int*)(root + 56) = (int)base + *(int*)(root + 56);
        index = 0;
        if (*(int*)root > 0) {
            register char* nestedCursor __asm__("$7") = root;
            register int nestedOffset __asm__("$8") = 60;
            do {
                if ((unsigned)(root + nestedOffset) < (unsigned)arg2) {
                    *(int*)(nestedCursor + 60) = (int)base + *(int*)(nestedCursor + 60);
                }
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 12) < (unsigned)arg2)
                    *(int*)(record + 12) = *(int*)(root + 56) + *(int*)(record + 12);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 16) < (unsigned)arg2)
                    *(int*)(record + 16) = *(int*)(root + 56) + *(int*)(record + 16);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 20) < (unsigned)arg2)
                    *(int*)(record + 20) = *(int*)(root + 56) + *(int*)(record + 20);
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 24) < (unsigned)arg2 && *(int*)(record + 24) != 0) {
                    *(int*)(record + 24) = *(int*)(root + 56) + *(int*)(record + 24);
                }
                {
                    register char* specialRecord __asm__("$3") = *(char**)(nestedCursor + 60);
                    if ((unsigned)(specialRecord + 28) < (unsigned)arg2) {
                        register int specialValue __asm__("$4") = *(int*)(specialRecord + 28);
                        if (specialValue != 0)
                            *(int*)(specialRecord + 28) = *(int*)(root + 56) + specialValue;
                        else
                            *(int*)(specialRecord + 28) = *(int*)(specialRecord + 20);
                    }
                }
                record = *(char**)(nestedCursor + 60);
                if ((unsigned)(record + 32) < (unsigned)arg2)
                    *(int*)(record + 32) = *(int*)(root + 56) + *(int*)(record + 32);
                nestedCursor += 4;
                count = *(volatile int*)root;
                index++;
                nestedOffset += 4;
            } while (index < count);
        }
    }
    ((int*)&D_8006EE2C)[arg1] = (int)root;
}


INCLUDE_ASM("asm/nonmatchings/overlays/credits/credits", func_credits_80074BA0);

/* AI generated; not human reviewed. Numeric retail credits actor rebuild. */
typedef struct {unsigned char reserved00[4];unsigned char kind,roll,pitch,yaw;unsigned char reserved08[10];short x,y,z;unsigned char reserved18[2];unsigned short value;} CreditsLayoutRecord;
extern short D_8006C510,D_8006C5A4;
extern Moby* D_8006C550;
extern CreditsLayoutRecord* D_8006C5F0;
extern unsigned char D_8006E33C,D_8006E33D,D_8006E33E;
extern unsigned char D_8006FC15,D_8006FC16,D_8006FC17,D_8006FC89,D_8006FC8A,D_8006FC8B;
extern int D_8006C598,D_8006D074;
void CreditsShade(int,int,int,int) __asm__("func_credits_800744BC");
extern void func_80022378(void),func_8001C368(void);
void func_credits_80076118(void) {
 volatile unsigned char stackSpace[8];
 register Moby* actor __asm__("$19");
 register unsigned char* fields __asm__("$17");
 register int i __asm__("$18");
 register int offset __asm__("$20");
 register CreditsLayoutRecord* record __asm__("$16");
 if(D_8006C510==-1) {func_8001EBAC();return;}
 actor=D_8006C550;
 {int r=D_8006E33C,g=D_8006E33D,b=D_8006E33E;
  D_8006FC15=r;D_8006FC16=g;D_8006FC17=b;
  D_8006FC89=r;D_8006FC8A=g;D_8006FC8B=b;}
 i=0;
 if(D_8006C5A4>0) {
  offset=0;fields=(unsigned char*)actor+0x47;
  do {
   register int kind __asm__("$3");
   {register CreditsLayoutRecord* base __asm__("$2")=D_8006C5F0;
    __asm__("" : "=r"(base): "0"(base));
    record=(CreditsLayoutRecord*)((char*)base+offset);}
   kind=record->kind;
   __asm__("" : "=r"(kind): "0"(kind));
   if((unsigned int)(kind-1)<2 || (unsigned char)kind==3) {
    func_8004E790(actor,0,0x58);
    *(int*)(fields-0x3B)=record->x;
    *(int*)(fields-0x37)=record->y;
    *(int*)(fields-0x33)=record->z;
    fields[-3]=record->roll;fields[-2]=record->pitch;fields[-1]=record->yaw;
    fields[-11]=record->value;
    {int next=record->value;
     actor++;
     *(short*)(fields-0x11)=0x3B;
     fields[13]=2;fields[5]=255;fields[7]=32;fields[0]=127;fields[-10]=next;}
    fields+=0x58;
    __asm__("" : "=r"(fields): "0"(fields));
   }
   offset+=28;i++;
  }while(i<D_8006C5A4);
 }
 actor->state=255;
 if(D_8006C598) {int shade=D_8006C598<<4;CreditsShade(2,shade,shade,shade);}
 func_8001EC5C();D_8006D074=0x18000;func_80022378();func_8001C368();
}
