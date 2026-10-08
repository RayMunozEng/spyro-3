#include "common.h"

void func_8005DB1C(void);
void func_8005DB08(int);
void func_8005DC8C(void);
void VSyncCallback(void*);
void StopCallback(void);
void func_title_80078B38(void) {
    SetDispMask(0);
    func_8005DB1C();
    func_8005DB08(0);
    VSyncCallback(0);
    func_8005DC8C();
    ResetGraph(3);
    StopCallback();
}

const char D_title_80074604[] = "Shutting Down\n";
const char D_title_80074614[] = "Launching Crash Bash Demo\n";
const char D_title_80074630[] = "cdrom:\\CRASHBSH\\SHELL.EXE;1";
int func_8005F5FC(const char*, ...);
void func_8005FC0C(void);
void func_80064DAC(void);
void func_80064D9C(const char*, void*, int);
void func_title_80078B88(void) {
    func_8005F5FC(D_title_80074604);
    func_title_80078B38();
    func_8005FC0C();
    func_80064DAC();
    func_8005F5FC(D_title_80074614);
    func_80064D9C(D_title_80074630, (void*)0x801FFF00, 0);
}
