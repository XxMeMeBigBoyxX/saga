#include <stdint.h>

#include "globals.h"
#include "nu2api.saga/nucore/nustring.h"
#include "nu2api.saga/nufile/nufile.h"
#include "nu2api.saga/numemory/numemory.h"
#include "saveload/saveload.h"

void NuMtlInitEx(void **bufferBase, int32_t usually512) {
    // iVar2 = AndroidOBBUtils::LookupPackagePath(path, 1);
    char *path = "res/main.1060.com.wb.lego.tcs.obb";

    nudathdr_s *dat = NuDatOpen(path, bufferBase, 0);
    NuDatSet(dat);

    LOG("dat->version=%d", dat->version);
    LOG("dat->fileCount=%d", dat->filesCount);
    LOG("dat->treeCount=%d", dat->treeCount);
    LOG("dat->leafnamesize=%d", dat->leafnamesize);
    LOG("dat->filetree=%p", dat->filetree);

    int32_t size = NuFileLoadBuffer("stuff\\text\\badwords.txt", *bufferBase, 0x100000);
    LOG("size=%d", size);
    // replace \n with ,
    char *buf = (char *)*bufferBase;
    for (int32_t i = 0; i < size; i++) {
        if (buf[i] == '\r') {
            buf[i] = ',';
        } else if (buf[i] == '\n') {
            buf[i] = ' ';
        }
    }
    LOG("%*s", size, buf);
}

void NuInitHardware(void **bufferBase, void **bufferEnd, int32_t zero) {
    NuMtlInitEx(bufferBase, 512);
}

struct GAMESAVE_s {
    char data[0x7e58];
};

GAMESAVE_s Game;

short MakeSaveHash(void) {
    return *(short *)((size_t)Game.data + 0x7C24);
}

int32_t drawautosaveicon = 0;

void DrawAutoSaveIcon(void) {
    drawautosaveicon = 1;
    return;
}

char SuperOptions[24] = {0};

void InitGameBeforeConfig() {
    if (PAL == 0) {
        NuStrCpy(prodcode, "BASLUS-21409");
        FRAMETIME = 0.016666668;
    } else {
        NuStrCpy(prodcode, "BESLES-54221");
        FRAMETIME = 0.02;
    }
    DEFAULTFPS = 1.0 / FRAMETIME;
    DEFAULTFRAMETIME = 0.016666668;
    MAXFRAMETIME = 0.1;
    permbuffer_ptr = permbuffer_base;
    permbuffer_end = superbuffer_end;

    saveloadInit(&permbuffer_base, superbuffer_end, 0x7e58, prodcode, iconname, unicodename, 4);
    original_permbuffer_base = permbuffer_base;
    SaveSystemInitialise(3, (void *)MakeSaveHash, &Game, sizeof(GAMESAVE_s), 1, (void *)DrawAutoSaveIcon, SuperOptions,
                         sizeof(SuperOptions));
}

void InitOnce(int32_t argc, char **param_2) {
    NuMemory *memory = NuMemoryGet();
    NuMemoryManager *manager = memory->GetThreadMem();

    permbuffer_base = manager->_BlockAlloc(SUPERBUFFERSIZE, 4, 1, "", 0);
    superbuffer_end = (void *)(SUPERBUFFERSIZE + (size_t)permbuffer_base);
    original_permbuffer_base = permbuffer_base;

    InitGameBeforeConfig();
    //  Game_NuPad = Game_NuPad_Store;

    NuInitHardware(&permbuffer_base, &superbuffer_end, 0);
}

extern "C" int32_t NuMain(int32_t argc, char **argv) {
    InitOnce(argc, argv);
    TriggerExtraDataLoad();
    return 0;
}

int main(int argc, char **argv) {
    NuMain(argc, argv);

    return 0;
}

char uberShader2[] = {
#include <uberShader2.array>
};