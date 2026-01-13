#include "nu2api.saga/nucore/nupad.h"

#include "nu2api.saga/nucore/nuapi.h"

void NuPadRecordStart(void) {
    nuapi.pad_recording = 1;
}