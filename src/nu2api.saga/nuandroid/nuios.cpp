#include "decomp.h"

#include "nu2api.saga/nuandroid/nuios.h"

#include <string.h>

i32 g_isLowEndDevice = 0;

i32 NuIOS_IsLowEndDevice(void) {
    return g_isLowEndDevice;
}

SAGA_NOMATCH char *NuIOS_GetDocumentsPath(void) {
    return "res/";
}

char *NuIOS_GetAppBundlePath(void) {
    static char storedAppBundlePath[4096];

    if (storedAppBundlePath[0] == '\0') {
        strcpy(storedAppBundlePath, "dummyPath");
    }

    return storedAppBundlePath;
}

u32 NuIOS_YieldThread(void) {
    UNIMPLEMENTED();
}
