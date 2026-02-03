#pragma once

#include "decomp.h"
struct nutime_s {
    u32 low;
    int high;
};

typedef struct nutime_s NUTIME;

#ifdef __cplusplus
void NuTimeGetTicksPS(u32 *low, u32 *high);
u64 NuGetCurrentTimeMilisecondsPS(void);

extern "C" {
#endif
    void NuTimeInitPS(void);
    void NuTimeGet(NUTIME *t);
    void NuTimeSub(NUTIME *t, NUTIME *a, NUTIME *b);
#ifdef __cplusplus
}
#endif
