#pragma once

#include "nu2api/nucore/common.h"
#include "nu2api/numath/numtx.h"

#define NURNDR_STREAM_MAX_BUFFERS 2

typedef struct rndrstream_s {
} RNDRSTREAM;

typedef i32 NUCOLOUR32;

typedef struct nucolour3_s {
    f32 r;
    f32 g;
    f32 b;
} NUCOLOUR3;

typedef struct nucolour4_s {
    f32 r;
    f32 g;
    f32 b;
    f32 a;
} NUCOLOUR4;

typedef struct renderstate_s {
    char padding[0x1b0];
} RENDERSTATE;



typedef struct lightstate_s  {
    u8 pad_00[0x60]; 
    i32 unk_60;       
    u8 pad_64[0x10]; 
    i32 unk_74;       
} LIGHTSTATE;

extern LIGHTSTATE NuRndrLightingStateCurrent;


#ifdef __cplusplus

void NuRndrStreamInit(i32 stream_buffer_size, VARIPTR *buffer);

extern "C" {
#endif
    void NuRndrInitEx(int stream_buffer_size, VARIPTR *buffer);

    i32 NuRndrSetViewMtx(NUMTX *vpcs_mtx, NUMTX *viewport_vpc_mtx, NUMTX *scissor_vpc_mtx);

    void FaceYDirStream(i32 y_angle);
    void NuRndrDither();    
    int NuRndrSetFxMtx();
    char *NuRndrEndSceneEx();
    char *NuRndrEndScene();
    void *NuRndrStateInit();
    int NuRndrSetSpecularLightPS(int *a1, int *a2);
#ifdef __cplusplus
}
#endif
