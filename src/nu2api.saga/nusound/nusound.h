#pragma once

#include "globals.h"
#include "nu2api.saga/nufile/nufile.h"

typedef struct nusound_filename_info_s {
    char *name;
} NUSOUND_FILENAME_INFO;

typedef enum {

} NUSOUNDPLAYTOK;

#ifdef __cplusplus
NUSOUND_FILENAME_INFO *ConfigureMusic(char *file, VARIPTR *bufferStart, VARIPTR *bufferEnd);
#endif

#ifdef __cplusplus
extern "C" {
#endif

    i32 NuSound3InitV(VARIPTR *bufferStart, VARIPTR bufferEnd, i32 zero1, i32 zero2);
    i32 NuSound3PlayStereoV(NUSOUNDPLAYTOK, ...);

    void NuSound3Init(i32 zero);

#ifdef __cplusplus
}
#endif
