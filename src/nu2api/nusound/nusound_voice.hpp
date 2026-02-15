#pragma once

#include "nu2api/nusound/nusound3_include.hpp"

class NuSoundSource;

class NuSoundVoice {
    NuSoundVoice(NuSoundSource *sound_source, bool);
};

class NuSound3Voice : NuSoundVoice {};
