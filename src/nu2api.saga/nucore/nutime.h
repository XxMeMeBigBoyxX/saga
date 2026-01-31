#pragma once

struct nutime_s {
    unsigned int low;
    int high;
};

typedef struct nutime_s NUTIME;

#ifdef __cplusplus
void NuTimeGetTicksPS(unsigned int *low, unsigned int *high);
unsigned long long NuGetCurrentTimeMilisecondsPS(void);

extern "C" {
#endif
    void NuTimeInitPS(void);
    void NuTimeGet(NUTIME *t);
    void NuTimeSub(NUTIME *t, NUTIME *a, NUTIME *b);
#ifdef __cplusplus
}
#endif
