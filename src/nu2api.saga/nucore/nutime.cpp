#include "nu2api.saga/nucore/nutime.h"

#include <time.h>

void NuTimeGetTicksPS(unsigned int *low, unsigned int *high) {

}

extern "C" void NuTimeGet(NUTIME *t) {
    NuTimeGetTicksPS(&t->low, &t->high);
}