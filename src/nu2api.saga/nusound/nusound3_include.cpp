#pragma once

#include "nu2api.saga/nusound/nusound3_include.hpp"
#include "decomp.h"
#include "nu2api.saga/nucore/nucore.hpp"
#include "nu2api.saga/nucore/nuvector.hpp"
#include "nu2api.saga/nucore/nuvuvec.hpp"
#include "nu2api.saga/numusic/numusic.h"
#include "nu2api.saga/nusound/nusound.h"
#include "nu2api.saga/nusound/nusound_buffer.hpp"
#include "nu2api.saga/nusound/nusound_loader.hpp"
#include "nu2api.saga/nusound/nusound_sample.hpp"
#include "nu2api.saga/nusound/nusound_voice.hpp"
#include "nu2api.saga/nuthread/nuthread.h"

extern "C" {
    const char *audio_ps2_music_ext = ".vag";
}

static NuVector<NuSoundSample> g_NuSoundSamples;

static NuSoundLoadTrigger g_NuSoundLoadTrigger;

static NuEList<NuSound3Voice> g_NuSoundVoicesPendingPlayback{};
static NuEList<NuSound3Voice> g_NuSoundVoicesActive{};
static NuEList<NuSound3Voice> g_NuSoundVoicesPendingDestruction{};

static NuSoundBuffer g_NuSoundStreamBuffers[4];

static i32 g_NuSoundLoadBits = 0;
static NuThread *g_NuSoundLoadThread = NULL;
static pthread_mutex_t g_NuSoundLoadCriticalSection = PTHREAD_MUTEX_INITIALIZER;

void NuSound3SampleLoadThread(void *arg) {
    do {
    } while (g_NuSoundLoadBits == NULL);

    if (g_NuSoundSamples.length != 0) {
    }
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

NuSoundLoader *NuSoundSystem::CreateFileLoader(FileType type) {
    switch (type) {
        case FILE_TYPE_WAV:
            UNIMPLEMENTED("WAV loader");
        case FILE_TYPE_OGG:
            UNIMPLEMENTED("OGG loader");
        default:
            return NULL;
    }
}

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

i32 NuSound3PlayStereoV(NUSOUNDPLAYTOK, ...) {
}
