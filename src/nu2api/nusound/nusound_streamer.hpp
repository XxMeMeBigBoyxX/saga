#pragma once

#include "nu2api/nucore/android/NuThread_android.h"
#include "nu2api/nucore/nuthread.h"
#include "nu2api/nusound/nulist.hpp"
#include "nu2api/nusound/nusound_sample.hpp"

#include "nu2api/nucore/nuvuvec.hpp"

class NuSoundStreamer;

class NuSoundStreamingSample : public NuSoundSample {
  public:
    NuSoundBuffer *buffer1;
    NuSoundBuffer *buffer2;

    NuSoundStreamer *streamer;
    NuSoundLoader *loader;

    NuSoundStreamingSample(const char *file);

    i32 Open(float param_1, bool param_2, bool param_3);
};

class NuSoundWeakPtrListNode {
  public:
    static pthread_mutex_t sPtrListLock;
    static pthread_mutex_t sPtrAccessLock;

    NuSoundStreamingSample *streaming_sample;

    virtual ~NuSoundWeakPtrListNode() = default;
};

class NuSoundStreamer {
  public:
  public:
    static NuList<NuSoundStreamer *> sStreamers;

    static i32 sThreadPriority;
    static i32 sThreadStackSize;
    static NUTHREAD_CORE sThreadCoreId;

  private:
    NuThread *thread;

    NuSoundWeakPtrListNode queue[32];
    i32 queue_length = 0;
    i32 index = 0;

    u8 buffer2[0x500];

    NuThreadSemaphore semaphore1;
    NuThreadSemaphore semaphore2;
    NuThreadSemaphore semaphore3;

  public:
    NuSoundStreamer();

    void RequestCue(NuSoundStreamingSample *streaming_sample, bool loop, float start_offset, bool always_false);

  private:
    static void ThreadFunc(void *self);
};
