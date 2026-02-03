#pragma once

#include "nu2api.saga/numath/nuang.h"
#include "nu2api.saga/numath/numtx.h"

typedef struct nuquat_s {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} NUQUAT;

#ifdef __cplusplus
extern "C" {
#endif
    void NuQuatFromEulerXYZ(NUQUAT *out, NUANG psi, NUANG theta, NUANG phi);

    void NuQuatToMtx(NUQUAT *quat, NUMTX *out);

    void NuQuatInv(NUQUAT *out, NUQUAT *quat);

    void NuQuatLerp(NUQUAT *out, NUQUAT *from, NUQUAT *to, f32 t);
    void NuQuatSlerp(NUQUAT *out, NUQUAT *from, NUQUAT *to, f32 t);
    void NuQuatCubicInt(NUQUAT *out, NUQUAT *m, NUQUAT *a, NUQUAT *b, NUQUAT *c, f32 t);
    void NuQuatHermiteInt(NUQUAT *out, NUQUAT *m, NUQUAT *a, NUQUAT *b, NUQUAT *c, f32 t);

    void NuQuatHarmonize(NUQUAT *a, NUQUAT *b);
#ifdef __cplusplus
}
#endif

f32 NuCubicInterpolation(f32 m, f32 y0, f32 y1, f32 y2, f32 t);
f32 NuHermiteInterpolation(f32 m, f32 y0, f32 y1, f32 y2, f32 t);
