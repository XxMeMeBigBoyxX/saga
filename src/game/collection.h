#pragma once

#include <stdint.h>

#include "nu2api.saga/nucore/common.h"

#ifdef __cplusplus
extern "C" {
#endif

    extern int32_t COLLECTION_COMPLETIONCOUNT;

#ifdef __cplusplus
}
#endif

void Collection_Configure(char *file, VARIPTR *buf, VARIPTR *buf_end);
