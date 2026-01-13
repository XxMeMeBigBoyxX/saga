#ifndef NU2API_SAGA_GAMELIB_NUWIND_H
#define NU2API_SAGA_GAMELIB_NUWIND_H

#include "nu2api.saga/numath/nuvec4.h"

struct nuwind_s {
    int unk0[8];
    int unk1;
    NUVEC4 unk2;
    float unk3;
};

typedef struct nuwind_s NUWIND;

#ifdef __cplusplus
extern "C" {
#endif

void NuWindInitialise(NUWIND *wind);

#ifdef __cplusplus
}
#endif

#endif // NU2API_SAGA_GAMELIB_NUWIND_H