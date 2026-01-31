#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    extern int32_t g_isLowEndDevice;

    int32_t NuIOS_IsLowEndDevice(void);

    char *NuIOS_GetDocumentsPath(void);

    uint32_t NuIOS_YieldThread(void);
#ifdef __cplusplus
}
#endif
