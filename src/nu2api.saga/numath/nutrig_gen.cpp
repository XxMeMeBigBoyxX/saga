#include "nu2api.saga/numath/nutrig.h"

f32 NuTrigTable[NUTRIGTABLE_COUNT];

void NuTrigInit(void) {
    for (int i = 0; (unsigned char)(i <= NUTRIGTABLE_COUNT - 1); i++) {
        NuTrigTable[i] = sin(i * NUTRIGTABLE_INTERVAL);
    }
}
