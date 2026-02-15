#include "nu2api.saga/nucore/nuapi.h"
#include "nu2api.saga/nu3d/nuocclusion.h"
#include "nu2api.saga/nu3d/nuportal.h"
#include "nu2api.saga/nu3d/nuwater.h"
#include "nu2api.saga/nucore/nukeyboard.h"
#include "nu2api.saga/nucore/numouse.h"

static void NuPrimReset() {
}

void NuFrameBegin(void) {
    nuapi.nuframe_begin_cnt++;

    NuPortalInit();
    NuPrimReset();
    NuWaterReset();
    NuMouseRead();
    NuKeyboardRead();
    NuOcclusionManagerBeginFrame();
}
