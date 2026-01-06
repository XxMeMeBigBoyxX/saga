#include "nu2api.saga/nucore/nutime.h"

// for now we rely on POSIX
#include <time.h>

void NuTimeGetTicksPS(unsigned int *low, unsigned int *high) {
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);

    unsigned int nsec_us = ts.tv_nsec / 1000;
    unsigned int sec_us = ts.tv_sec * 1000000;
    unsigned long long us = nsec_us + sec_us;

    *low = us & 0xFFFFFFFF;
    *high = us >> 32;
}

void NuTimeGet(NUTIME *t) {
    NuTimeGetTicksPS(&t->low, &t->high);
}