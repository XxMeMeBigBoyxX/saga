#include <stdint.h>

#include "nu2api.saga/numemory/numemory.h"

extern "C" {
    int32_t SUPERBUFFERSIZE = 0x2EB8EEB;
    void *permbuffer_base;

    int32_t NuMain(int32_t argc, char **argv) {
        return 0;
    }

    void InitOnce(int32_t argc, char **param_2) {

        int iVar1 = SUPERBUFFERSIZE;
        NuMemory *memory = NuMemoryGet();
        // NuMemoryManager *manager = NuMemory::GetThreadMem(memory);
        // permbuffer_base = (void *)NuMemoryManager::_BlockAlloc(manager, iVar1, 4, 1, "", 0);
        // superbuffer_end.voidptr = (void *)(SUPERBUFFERSIZE + (int)permbuffer_base.voidptr);
        // original_permbuffer_base = (variptr_u)(variptr_u)permbuffer_base.voidptr;
        // InitGameBeforeConfig();
        // Game_NuPad = Game_NuPad_Store;
        // NuInitHardware(&permbuffer_base.voidptr, &superbuffer_end.voidptr, 0);
    }
}

int main(int argc, char **argv) {
    NuMain(argc, argv);

    return 0;
}

char uberShader2[] = {
#include <uberShader2.array>
};