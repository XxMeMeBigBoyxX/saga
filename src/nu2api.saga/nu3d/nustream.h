#pragma once

#include "nu2api.saga/nucore/common.h"

#define NURNDR_STREAM_MAX_BUFFERS 2

typedef struct rndrstream_s {
} RNDRSTREAM;

#ifdef __cplusplus

void NuRndrStreamInit(int stream_buffer_size, VARIPTR *buffer);

#endif
