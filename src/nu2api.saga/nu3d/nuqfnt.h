#pragma once

#include "nu2api.saga/nu3d/numtl.h"
#include "nu2api.saga/nucore/common.h"

typedef struct vufnt_s {
    char filler1[0x24]; // 0x00-0x23
    float ic_gap;       // 0x24
    char filler2[0x4];  // 0x28-0x2B

    f32 *x_scale; // 0x2c
    f32 *y_scale; // 0x30

    char filler3[0x8]; // 0x34-0x3B

    VARIPTR *hdr; // 0x3c

    NUMTL *mtl; // 0x40

    u32 *color_abgr; // 0x44

    void *platform_data; // 0x48
} VUFNT;

typedef VUFNT NUQFNT;

#ifdef __cplusplus

int NuQFntReadPS(VUFNT *font, int tex_id, int flags, int render_plane, VARIPTR *buf, VARIPTR buf_end);

extern "C" {
#endif
    void NuQFntInit(VARIPTR *buffer, VARIPTR buffer_end);
    NUQFNT *NuQFntReadBuffer(VARIPTR *font, VARIPTR *buffer, VARIPTR buffer_end);
    void NuQFntSetICGap(NUQFNT *font, float ic_gap);
#ifdef __cplusplus
}
#endif
