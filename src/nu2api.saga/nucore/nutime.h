#ifndef NU2API_SAGA_NUCORE_NUTIME_H
#define NU2API_SAGA_NUCORE_NUTIME_H

struct nutime_s {
    unsigned int low;
    unsigned int high;
};

typedef struct nutime_s NUTIME;

#ifdef __cplusplus
void NuTimeGetTicksPS(unsigned int *low, unsigned int *high);

extern "C" {
#endif

void NuTimeGet(NUTIME *t);

#ifdef __cplusplus
}
#endif

#endif // NU2API_SAGA_NUCORE_NUTIME_H