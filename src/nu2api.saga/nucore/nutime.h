#ifndef NU2API_SAGA_NUCORE_NUTIME_H
#define NU2API_SAGA_NUCORE_NUTIME_H

struct nutime_s {
    unsigned int low;
    unsigned int high;
};

typedef struct nutime_s NUTIME;

void NuTimeGetTicksPS(unsigned int *low, unsigned int *high);
void NuTimeGet(NUTIME *t);

#endif // NU2API_SAGA_NUCORE_NUTIME_H