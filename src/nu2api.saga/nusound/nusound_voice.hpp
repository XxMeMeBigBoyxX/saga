#pragma once

#include "decomp.h"

#include "nu2api.saga/nusound/nusound3_include.hpp"

class NuSoundSource;

class NuSoundVoice {
    NuSoundVoice(NuSoundSource *sound_source, bool);
};

class NuSound3Voice : NuSoundVoice {};
