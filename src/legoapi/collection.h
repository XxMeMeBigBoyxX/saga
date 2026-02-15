#pragma once

#include "nu2api/nucore/common.h"

#ifdef __cplusplus
extern "C" {
#endif

    extern i32 COLLECTION_COMPLETIONCOUNT;

#ifdef __cplusplus
}
#endif

void Collection_Configure(char *file, VARIPTR *buf, VARIPTR *buf_end);
