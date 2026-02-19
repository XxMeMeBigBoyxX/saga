#pragma once

#include "nu2api/nusound/nusound_loader.hpp"

class NuSoundHeaderOGG : public NuSoundStreamDesc {
  public:
    NuSoundHeaderOGG() = default;

    DataFormat GetDecodedDataFormat();
    u64 GetEncodedLengthBytes();
    u64 GetLengthSamples();
    double GetLengthSeconds();
    u64 GetDataOffset();
    u16 GetNumChannels();
    u32 GetSampleRate();
    u16 GetBitsPerChannel();
    u16 GetBlockSize();
    DataFormat GetEncodedDataFormat();
    u64 GetDecodedLengthBytes();
    u16 GetInterleaveSize();
    u16 GetFormatId();
    u16 GetExtendedDataSize();
    void *GetExtendedData();
};

class NuSoundLoaderOGG : public NuSoundLoader {
  public:
    class OGGFileCallbacks {
      private:
        NUFILE file;

      public:
        i32 Read(void *dest, u32 size);
        void SetFile(NUFILE file);
    };

    NuSoundLoaderOGG();

    NuSoundStreamDesc::DataFormat GetDecodedDataFormat();
    NuSoundStreamDesc *CreateHeader();

    bool SeekPCMSample(u64 index);
    bool SeekTime(double seconds);
    virtual i32 ReadHeader(NuSoundStreamDesc *header);

  private:
    OGGFileCallbacks file_callbacks;
    void *buffer;

    void FreeMemoryBuffer();

    static usize OggCallbackRead(void *dest, usize count, usize size, void *callbacks);
};
