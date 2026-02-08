#pragma once

#include "nu2api.saga/nusound/nusound3_include.hpp"

#include <pthread.h>

class NuSoundSample {
  private:
    LoadState load_state;
    ErrorState last_error;
    NuSoundSystem::FileType type;
    i32 ref_count;

    static pthread_mutex_t sCriticalSection;

  public:
    LoadState GetLoadState() const;
    ErrorState GetLastErrorState() const;

    void Reference();
    void Release();

    ErrorState Load(void *param_1, int param_2, NuSoundOutOfMemCallback *oomCallback);
};
