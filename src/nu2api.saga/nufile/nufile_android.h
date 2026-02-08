#pragma once

#include "nu2api.saga/nufile/nufile.h"

class NuFileDeviceAndroidAPK {};

extern NuFileDeviceAndroidAPK *g_apkFileDevice;

class NuFileAndroidAPK : NuFileBase {
  public:
    NuFileAndroidAPK(const char *filepath, NuFile::OpenMode::T mode);

    static NUFILE OpenFile(const char *filepath, NuFile::OpenMode::T mode);
    static i32 CloseFile(NUFILE file);

    static i64 SeekFile(NUFILE file, i64 offset, NuFile::SeekOrigin::T mode);
    static i32 ReadFile(NUFILE file, void *buf, u32 size);

    static i64 GetFilePos(NUFILE file);
    static i64 GetFileSize(NUFILE file);
};
