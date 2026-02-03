#pragma once

#include "globals.h"
#include "nu2api.saga/nufile/nufile.h"

class NuSoundLoader;

namespace NuSoundSystem {
    struct ChannelConfig {
        u32 channels;
    };

    enum FileType : u32 { WAV = 0, OGG = 5 };

    NuSoundLoader *CreateFileLoader(FileType type);

}; // namespace NuSoundSystem

typedef void(NuSoundOutOfMemCallback)();

class NuSoundBuffer {};

class NuSoundStreamDesc {};

class NuSoundLoader {
  private:
    NUFILE file;
    i32 field2_0x8;
    i32 field3_0xc;
    NuSoundStreamDesc *desc;
    NuSoundOutOfMemCallback *oom;
    char *path;

  public:
    NuSoundLoader();

    i32 CloseStream();
    u64 Deinterleave(byte *data, int length, char **dest, int count, NuSoundSystem::ChannelConfig config);
    i32 LoadFromFile(char *name, NuSoundStreamDesc *desc, NuSoundBuffer *buffer, NuSoundOutOfMemCallback *oom);
    i32 Load(NuSoundStreamDesc *desc, NuSoundBuffer *buffer);

    // virtual methods
    virtual ~NuSoundLoader();

    virtual NuSoundStreamDesc *CreateHeader() = 0;

    virtual i32 OpenForStreaming(const char *path);
    virtual NuSoundBuffer *FillStreamBuffer(NuSoundBuffer *buffer, bool param2);

    virtual bool SeekRawData(u64 position);
    virtual bool SeekPCMSample(u64 sampleIndex) = 0;
    virtual bool SeekTime(f64 seconds) = 0;

    virtual bool OpenFileForStreaming(const char *path, bool unused);
    virtual void Close();

    virtual void *ReadHeader(NuSoundStreamDesc *desc) = 0;
    virtual u64 ReadData(void *buffer, u64 size);
};

enum LoadState {
    LOADSTATE_LOADED = 1,
};
enum ErrorState {
    ERRORSTATE_NONE = 0,
};

class NuSoundSample {
  private:
    LoadState load_state;
    ErrorState last_error;
    NuSoundSystem::FileType type;
    i32 ref_count;

  public:
    LoadState GetLoadState();
    ErrorState GetLastErrorState();

    void Reference();
    void Release();

    ErrorState Load(void *param_1, int param_2, NuSoundOutOfMemCallback *oomCallback);
};

struct nusound_filename_info_s {
    char *name;
};

#ifdef __cplusplus

nusound_filename_info_s *ConfigureMusic(char *file, VARIPTR *bufferStart, VARIPTR *bufferEnd);

extern "C" {
#endif
    i32 NuSound3InitV(VARIPTR *bufferStart, VARIPTR bufferEnd, i32 zero1, i32 zero2);
#ifdef __cplusplus
}
#endif
