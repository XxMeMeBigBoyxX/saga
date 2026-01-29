#pragma once

#include <stdint.h>

#include "decomp.h"

C_API_START

extern int32_t g_isLowEndDevice;

int32_t NuIOS_IsLowEndDevice(void);

char *NuIOS_GetDocumentsPath(void);

uint32_t NuIOS_YieldThread(void);

C_API_END
