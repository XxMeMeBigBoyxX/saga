#include "nu2api.saga/nucore/nuapi.h"

#include <string.h>

NUAPI nuapi;

float nuapi_forced_frame_time;
float nuapi_max_fps;
static int NUAPI_PADREC_DEFAULT_BUFFERSIZE = 0x500000;
void NuAPIInit(void) {
    memset(&nuapi, 0, sizeof(NUAPI));
    nuapi.fps = 60.0f;
    nuapi.video_mode = NUVIDEOMODE_NTSC;
    nuapi.swap_mode = NUVIDEO_SWAPMODE_ROLLING;
    nuapi.field0_0x0 = 1;
    nuapi.field3_0xc = 0;
    nuapi.field77_0x88 = 0;
    nuapi.forced_frame_time = nuapi_forced_frame_time;
    nuapi.maxFps = nuapi_max_fps;
    NuTimeGet(&nuapi.time);
    nuapi.padrecBuffersize = NUAPI_PADREC_DEFAULT_BUFFERSIZE;
    nuapi.field50_0x64 = 0;
    nuapi.field51_0x68 = 0;
    NuWindInitialise(nuapi.wind);
}

void NuCommandLine(int argc, char** argv) {}