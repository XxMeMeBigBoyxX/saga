#include "nu2api/numath/nuvec.h"

#define IS_SNAN(x) (*(u32 *)&(x) == 0xffc00000)

void NuVecCheckForSNANs(NUVEC *v) {
    if (IS_SNAN(v->x) || IS_SNAN(v->y) || IS_SNAN(v->z)) {
        v->x = 0.0f;
        v->y = 1.0f;
        v->z = 0.0f;
    }
}
