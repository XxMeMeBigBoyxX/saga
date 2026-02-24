#include "nu2api/nu3d/nurndr.h"

void NuRndrInitWorld(void) {
}

i32 NuRndrSetViewMtx(NUMTX *vpcs_mtx, NUMTX *viewport_vpc_mtx, NUMTX *scissor_vpc_mtx) {
    return 0;
}

void FaceYDirStream(i32 y_angle) {
}

int NuRndrSetFxMtx() {
  return 1;
}

void NuRndrDither() {
    
}

extern RENDERSTATE render_state;

void *NuRndrStateInit() {
  return memset(&render_state, 0, sizeof(render_state));
}