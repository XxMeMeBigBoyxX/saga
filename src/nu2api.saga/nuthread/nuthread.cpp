#include "nuthread.h"

int32_t NuThreadManager::AllocTLS() {
    for (int32_t i = 0; i < 32; i++) {
        if ((this->bitflags >> (i & 0x1f) & 1) == 0) {
            this->bitflags |= 1 << ((uint8_t)i & 0x1f);
            return i;
        }
    }

    return -1;
}

/// the original implementation uses gcc's emulated TLS
NuThreadBase *NuThreadGetCurrentThread() {
    return NULL;
}

NuThreadBase *NuThreadManager::GetCurrentThread() {
    return NuThreadGetCurrentThread();
}

NuMemoryManager *NuThreadBase::GetLocalStorage(int32_t index) {
    return this->memoryManagers[index];
}
