#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t NuThreadCriticalSectionBegin(int32_t index);

int32_t NuThreadCriticalSectionEnd(int32_t index);

#ifdef __cplusplus
}
#endif