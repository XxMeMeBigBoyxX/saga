#include "decomp.h"

#include "nu2api.saga/nuandroid/nuios.h"

int32_t g_isLowEndDevice = 0;

int32_t NuIOS_IsLowEndDevice(void) {
    return g_isLowEndDevice;
}

SAGA_NOMATCH char *NuIOS_GetDocumentsPath(void) {
    return "res/";
}

uint32_t NuIOS_YieldThread(void) {
    UNIMPLEMENTED();
}
