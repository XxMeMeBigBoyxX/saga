#pragma once

#include "nu2api.saga/nucore/nuelist.hpp"

class NuSoundLoader;

class NuSoundSystem {
  public:
    struct ChannelConfig {
        u32 channels;
    };

    enum FileType : u32 { FILE_TYPE_WAV = 0, FILE_TYPE_OGG = 5 };

    static NuSoundLoader *CreateFileLoader(FileType type);

}; // namespace NuSoundSystem

class NuSoundOutOfMemCallback {
  public:
    virtual void operator()() = 0;
};

class NuSoundStreamDesc {};

enum LoadState {
    LOADSTATE_LOADED = 1,
};
enum ErrorState {
    ERRORSTATE_NONE = 0,
};

extern "C" {
    void NuSound3Init(i32 zero);
}
