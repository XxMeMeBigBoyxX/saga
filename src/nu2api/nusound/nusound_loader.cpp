#include "nu2api/nusound/nusound_loader.hpp"

NuSoundLoader::NuSoundLoader() {
    this->file = 0;
    this->field2_0x8 = 0;
    this->field3_0xc = 0;
    this->desc = NULL;
    this->oom = NULL;
}

NuSoundLoader::~NuSoundLoader() {
}

i32 NuSoundLoader::LoadFromFile(const char *name, NuSoundStreamDesc *desc, NuSoundBuffer *buffer,
                                NuSoundOutOfMemCallback *oom) {
    this->oom = oom;
    this->path = name;

    NUFILE file = NuFileOpen(const_cast<char *>(name), NUFILE_READ);
    this->file = file;

    if (file == 0) {
        return 2;
    }

    return Load(desc, buffer);
}

i32 NuSoundLoader::Load(NuSoundStreamDesc *desc, NuSoundBuffer *buffer) {
    UNIMPLEMENTED();
}

i32 NuSoundLoader::OpenForStreaming(const char *path, f64 param2, NuSoundStreamDesc *desc, bool param4) {
    UNIMPLEMENTED();
}
NuSoundBuffer *NuSoundLoader::FillStreamBuffer(NuSoundBuffer *, bool) {
    UNIMPLEMENTED();
}
bool NuSoundLoader::SeekRawData(u64) {
    UNIMPLEMENTED();
}
bool NuSoundLoader::OpenFileForStreaming(char const *, bool) {
    UNIMPLEMENTED();
}
void NuSoundLoader::Close() {
    UNIMPLEMENTED();
}
u64 NuSoundLoader::ReadData(void *, u64) {
    UNIMPLEMENTED();
}

static pthread_mutex_t sCriticalSection = PTHREAD_MUTEX_INITIALIZER;
