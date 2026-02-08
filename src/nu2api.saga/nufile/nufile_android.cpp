#include "nu2api.saga/nufile/nufile_android.h"

#include "decomp.h"
#include "nu2api.saga/nufile/nufile.h"

NuFileAndroidAPK::NuFileAndroidAPK(const char *filepath, NuFile::OpenMode::T mode)
    : NuFileBase(filepath, mode, 0x534f2020) {
}

SAGA_NOMATCH i32 NuFileAndroidAPK::OpenFile(const char *filepath, NuFile::OpenMode::T mode) {
    UNIMPLEMENTED("android specific");
}

SAGA_NOMATCH i32 NuFileAndroidAPK::CloseFile(NUFILE file) {
    UNIMPLEMENTED("android specific");
}

SAGA_NOMATCH i64 NuFileAndroidAPK::SeekFile(NUFILE file, i64 offset, NuFile::SeekOrigin::T mode) {
    UNIMPLEMENTED("android specific");
}

SAGA_NOMATCH i32 NuFileAndroidAPK::ReadFile(NUFILE file, void *buf, u32 size) {
    UNIMPLEMENTED("android specific");
}

SAGA_NOMATCH i64 NuFileAndroidAPK::GetFilePos(NUFILE file) {
    UNIMPLEMENTED("android specific");
}

SAGA_NOMATCH i64 NuFileAndroidAPK::GetFileSize(NUFILE file) {
    UNIMPLEMENTED("android specific");
}
