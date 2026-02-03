#include <pthread.h>

#include "decomp.h"

#include "nu2api.saga/nusound/nusound.h"

#include "globals.h"
#include "nu2api.saga/nucore/nucore.h"
#include "nu2api.saga/numusic/numusic.h"
#include "nu2api.saga/nuthread/nuthread.h"

extern "C" {
    const char *audio_ps2_music_ext;
}

nusound_filename_info_s *ConfigureMusic(char *file, VARIPTR *bufferStart, VARIPTR *bufferEnd) {
    nusound_filename_info_s *finfo;

    music_man.Initialise("audio\\music.cfg", NULL, bufferStart, *bufferEnd);
    music_man.GetSoundFiles(&finfo, NULL);

    audio_ps2_music_ext = ".mib";

    // MusicConfig *musicConfig;
    // musicConfig = (MusicConfig *)((int)bufferStart->voidptr + 3U & 0xfffffffc);

    // musicConfig->field0_0x0 = 0;
    // ActionPairTab = &musicConfig->actionTab;
    // musicConfig->actionTab = -1;
    // musicConfig->ambientTab = -1;
    // AmbientPairTab = &musicConfig->ambientTab;
    // bufferStart->voidptr = musicConfig + 1;

    return finfo;
}

NuSoundLoader::NuSoundLoader() {
    this->file = 0;
    this->field2_0x8 = 0;
    this->field3_0xc = 0;
    this->desc = NULL;
    this->oom = NULL;
}

NuSoundLoader::~NuSoundLoader() {
}

NuSoundLoader *NuSoundSystem::CreateFileLoader(FileType type) {
    switch (type) {
        case WAV:
            UNIMPLEMENTED("WAV loader");
        case OGG:
            UNIMPLEMENTED("OGG loader");
        default:
            return NULL;
    }
}

i32 NuSoundLoader::LoadFromFile(char *name, NuSoundStreamDesc *desc, NuSoundBuffer *buffer,
                                NuSoundOutOfMemCallback *oom) {
    this->oom = oom;
    this->path = name;

    NUFILE file = NuFileOpen(name, NUFILE_READ);
    this->file = file;

    if (file == 0) {
        return 2;
    }

    return Load(desc, buffer);
}

i32 NuSoundLoader::Load(NuSoundStreamDesc *desc, NuSoundBuffer *buffer) {
    UNIMPLEMENTED();
}

i32 NuSoundLoader::OpenForStreaming(char const *) {
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

LoadState NuSoundSample::GetLoadState() {
    LoadState ls;

    pthread_mutex_lock(&sCriticalSection);
    ls = this->load_state;
    pthread_mutex_unlock(&sCriticalSection);

    return ls;
}

ErrorState NuSoundSample::GetLastErrorState() {
    ErrorState es;

    pthread_mutex_lock(&sCriticalSection);
    es = this->last_error;
    pthread_mutex_unlock(&sCriticalSection);

    return es;
}

void NuSoundSample::Reference() {
    __sync_fetch_and_add(&ref_count, 1);
}

void NuSoundSample::Release() {
    __sync_fetch_and_sub(&ref_count, 1);
}

ErrorState NuSoundSample::Load(void *param_1, int param_2, NuSoundOutOfMemCallback oomCallback) {
    NuSoundLoader *loader;
    NuSoundStreamDesc *desc;
    NuSoundBuffer *buffer;
    LoadState LVar2;

    ErrorState EVar3 = ERRORSTATE_NONE;
    if (GetLoadState() != LOADSTATE_LOADED) {
        loader = NuSoundSystem::CreateFileLoader(this->type);

        // desc = (NuSoundStreamDesc *)(*(code *)loader->vtable[2])(loader);
        desc = loader->CreateHeader();

        /*if (desc == NULL) {
            EVar3 = 3;
            NuSoundSystem::ReleaseFileLoader(loader);
        } else {
            NuSoundSource::SetStreamDesc((NuSoundSource *)this, desc);
            buffer = (NuSoundBuffer *)GetSourceBuffer(this);
            iVar1 = NuSoundLoader::LoadFromFile(loader, this->path, desc, buffer, oomCallback);
            NuSoundSystem::ReleaseFileLoader(loader);
            LVar2 = 1;
            if (iVar1 != 1) {
                EVar3 = 1;
                if (iVar1 - 2U < 4) {
                    EVar3 = *(ErrorState *)(CSWTCH.185 + (iVar1 - 2U) * 4);
                }
                NuSoundSystem::FreeMemory(0, (uint)desc, 0);
                NuSoundSource::SetStreamDesc((NuSoundSource *)this, (NuSoundStreamDesc *)0x0);
                LVar2 = 0;
            }

            SetLoadState(this, LVar2);
            SetLastErrorState(this, EVar3);
        }
            */
    }

    return EVar3;
}

struct NuSoundLoadTrigger {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool a;
    bool b;
};

static NuSoundLoadTrigger g_NuSoundLoadTrigger;
static pthread_mutex_t g_NuSoundLoadCriticalSection = PTHREAD_MUTEX_INITIALIZER;

static i32 g_NuSoundLoadBits = 0;

static NuSoundSample *g_NuSoundSamples[3];

void NuSound3SampleLoadThread(void *arg) {
    do {
        do {
            pthread_mutex_lock(&g_NuSoundLoadTrigger.mutex);

            while (g_NuSoundLoadTrigger.a == false) {
                pthread_cond_wait(&g_NuSoundLoadTrigger.cond, &g_NuSoundLoadTrigger.mutex);
            }

            g_NuSoundLoadTrigger.a = g_NuSoundLoadTrigger.b;
            pthread_mutex_unlock(&g_NuSoundLoadTrigger.mutex);
        } while (g_NuSoundLoadBits == 0);

        pthread_mutex_lock(&g_NuSoundLoadCriticalSection);

        if (g_NuSoundSamples[2] != NULL) {
        }
    } while (true);
}

static NuThread *g_NuSoundLoadThread = NULL;

void NuSound3Init(i32 zero) {
    // int iVar1;
    // NuMemory *this;
    // NuMemoryManager *this_00;
    // NuSoundStreamer *this_01;
    // uint uVar2;

    // iVar1 = NuIOS_IsLowEndDevice();
    // NuCore::Initialize();
    // NuSoundSystem::Initialise(&NuSound, (-(uint)(iVar1 == 0) & 0x1ccccd) + 0x633333);
    // NuSoundDecoder::Initialise();
    // this = NuMemoryGet();
    // this_00 = NuMemory::GetThreadMem(this);
    // this_01 = (NuSoundStreamer *)NuMemoryManager::_BlockAlloc(this_00, 0xa48, 4, 1, "", 7);
    // if (this_01 != (NuSoundStreamer *)0x0) {
    //     NuSoundStreamer::NuSoundStreamer(this_01);
    // }
    // g_NuSoundStreamer = this_01;

    g_NuSoundLoadThread =
        NuCore::m_threadManager->CreateThread(NuSound3SampleLoadThread, NULL, 0, "NuSoundLoadThread", 0,
                                              NUTHREADCAFECORE_UNKNOWN_1, NUTHREADXBOX360CORE_UNKNOWN_1);

    // NuSoundSystem::AddListener(&NuSound, &g_NuSoundListener);
    // NuSoundListener::SetHeadMatrix(&g_NuSoundListener, (VuMtx *)&global_camera);
    // NuSoundListener::Enable(&g_NuSoundListener);

    // uVar2 = NuSoundSystem::GetStreamBufferSize();
    // NuSoundBuffer::Allocate(CONCAT44(uVar2 >> 1, g_NuSoundStreamBuffers), 0);

    // uVar2 = NuSoundSystem::GetStreamBufferSize();
    // NuSoundBuffer::Allocate(CONCAT44(uVar2 >> 1, 0x11ef440), 0);

    // uVar2 = NuSoundSystem::GetStreamBufferSize();
    // NuSoundBuffer::Allocate(CONCAT44(uVar2 >> 1, 0x11ef480), 0);

    // uVar2 = NuSoundSystem::GetStreamBufferSize();
    // NuSoundBuffer::Allocate(CONCAT44(uVar2 >> 1, 0x11ef4c0), 0);
}

i32 NuSound3InitV(VARIPTR *bufferStart, VARIPTR bufferEnd, i32 zero1, i32 zero2) {
    NuSound3Init(0);
    return 1;
}
