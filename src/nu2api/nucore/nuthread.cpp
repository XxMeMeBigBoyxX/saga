#include "nu2api/nucore/nuthread.h"

#include <pthread.h>
#include <sched.h>

#include "nu2api/nucore/common.h"

u32 nu_current_thread_id;

static pthread_mutex_t NuThread_CriticalSections[16];
static char NuThread_CriticalSectionsUsed[16];

i32 NuThreadCriticalSectionBegin(i32 index) {
    return pthread_mutex_lock(&NuThread_CriticalSections[index]);
}

i32 NuThreadCriticalSectionEnd(i32 index) {
    return pthread_mutex_unlock(&NuThread_CriticalSections[index]);
}

i32 NuThreadCreateCriticalSection(void) {
    i32 index = -1;

    for (i32 i = 0; i < 16; i++) {
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

    NuThread_CriticalSectionsUsed[index] = true;

    return index;
}

void NuThreadDestroyCriticalSection(int index) {
    pthread_mutex_destroy(&NuThread_CriticalSections[index]);

    NuThread_CriticalSectionsUsed[index] = false;
}

void NuEnableVBlank() {
}

void NuDisableVBlank() {
}

nuthreadenableswapfn *NuThreadEnableThreadSwap = &NuEnableVBlank;
nuthreaddisableswapfn *NuThreadDisableThreadSwap = &NuDisableVBlank;
