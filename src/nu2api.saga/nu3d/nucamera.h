#pragma once

#include "nu2api.saga/numath/numtx.h"
#include "nu2api.saga/numath/nuvec.h"
#include "nu2api.saga/numath/nuvec4.h"

typedef struct nucamera_s {
    NUMTX mtx;
    f32 fov;
    f32 aspect;
    f32 near_clip;
    f32 far_clip;

    f32 unknown_50;
    f32 unknown_54;
    f32 unknown_58;
    f32 unknown_5c;
    f32 unknown_60;
    f32 unknown_64;

    f32 portal_nearclip;

    NUVEC scale;
} NUCAMERA;

typedef struct nuclipplanes_s {
    NUMTX frustum_planes;
    NUMTX scissor_planes;
    NUMTX near_far_planes;
    NUVEC4 near_plane;
    NUMTX abs_frustum_planes;
    NUMTX abs_scissor_planes;
} NUCLIPPLANES;

#ifdef __cplusplus
void NuCameraBuildClipPlanes(void);

extern "C" {
#endif
    extern NUMTX clip_planes;
    extern NUCAMERA global_camera;

    extern NUMTX pmtx;
    extern NUMTX smtx;
    extern NUMTX vmtx;

    extern NUCLIPPLANES ClipPlanes;

    extern f32 zx;
    extern f32 zy;

    extern f32 zxs;
    extern f32 zys;

    NUCAMERA *NuCameraCreate(void);
    void NuCameraDestroy(NUCAMERA *cam);

    NUCAMERA *NuCameraGetCam(void);

    NUMTX *NuCameraGetMtx(void);
    NUMTX *NuCameraGetProjectionMtx(void);
    NUMTX *NuCameraGetScalingMtx(void);
    NUMTX *NuCameraGetViewMtx(void);

    NUMTX *NuCameraGetClipPlanes(void);
    void NuCameraGetPosition(NUVEC *v);
    void NuCameraGetTrans(NUVEC *v);

    f32 NuCameraDist(NUVEC *v);
    f32 NuCameraDistSqr(NUVEC *v);

    i32 NuCameraClipTestSphere(NUVEC *pnt, float radius, NUMTX *wm);

    void NuCameraCalcRay(float screen_x, float screen_y, NUVEC *ray_start, NUVEC *ray_end, NUCAMERA *cam);
#ifdef __cplusplus
}
#endif
