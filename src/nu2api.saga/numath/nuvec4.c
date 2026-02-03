#include "nu2api.saga/numath/nuvec4.h"

#include "nu2api.saga/numath/numtx.h"

void NuVec4MtxTransform(NUVEC4 *v, NUVEC *v0, NUMTX *m0) {
    f32 y = v0->x * m0->m01 + v0->y * m0->m11 + v0->z * m0->m21 + m0->m31;
    f32 z = v0->x * m0->m02 + v0->y * m0->m12 + v0->z * m0->m22 + m0->m32;
    f32 w = v0->x * m0->m03 + v0->y * m0->m13 + v0->z * m0->m23 + m0->m33;
    v->x = v0->x * m0->m00 + v0->y * m0->m10 + v0->z * m0->m20 + m0->m30;
    v->y = y;
    v->z = z;
    v->w = w;
}
