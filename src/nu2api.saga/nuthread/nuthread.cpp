#include <pthread.h>

#include "nu2api.saga/nuthread/nuthread.h"

static pthread_mutex_t NuThread_CriticalSections[16] = {PTHREAD_MUTEX_INITIALIZER};

int32_t NuThreadCriticalSectionBegin(int32_t index) {
    return pthread_mutex_lock(&NuThread_CriticalSections[index]);
}

int32_t NuThreadCriticalSectionEnd(int32_t index) {
    return pthread_mutex_unlock(&NuThread_CriticalSections[index]);
}

static uint8_t NuThread_CriticalSectionsUsed[16] = {0};

int32_t NuThreadCreateCriticalSection() {
    int32_t index = -1;

    for (int32_t i = 0; i < 16; i++) {
        if (NuThread_CriticalSectionsUsed[i] == '\0') {
            index = i;

            break;
        }
    }

    if (index == -1) {
        return -1;
    }

    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, 1);
    pthread_mutex_init(&NuThread_CriticalSections[index], &attr);
    pthread_mutexattr_destroy(&attr);

    NuThread_CriticalSectionsUsed[index] = 1;

    return index;
}

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

NuMemoryManager *NuThreadBase::GetLocalStorage(uint32_t index) const {
    return this->memoryManagers[index];
}
