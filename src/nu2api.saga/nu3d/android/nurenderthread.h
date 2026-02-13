#pragma once

#include "nu2api.saga/nucore/common.h"

#ifdef __cplusplus
void *renderThread_main(void *arg);

extern "C" {
#endif
    void NuRenderThreadLock(void);
    void NuRenderThreadUnlock(void);
    i32 NuRenderThreadIsLocked(void);
    void NuRenderThreadCreate(void);

    i32 renderThread_processRenderScenes(void);
#ifdef __cplusplus
}
#endif
