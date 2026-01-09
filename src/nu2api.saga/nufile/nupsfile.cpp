#include "nu2api.saga/nucore/nustring.h"
#include "nu2api.saga/nufile/nufile.h"
#include "nu2api.saga/nuthread/nuthread.h"

#include "decomp.h"

extern "C" size_t NuPSFileRead(NuFileHandle index, void *dest, size_t len) {
    FILE **files = g_fileHandles;
    return fread(dest, 1, len, files[index]);
}

extern "C" size_t NuPSFileWrite(NuFileHandle index, const void *src, size_t len) {
    FILE **files = g_fileHandles;
    return fwrite(src, 1, len, files[index]);
}

extern "C" NuFileHandle NuPSFileOpen(const char *name, NuFileOpenMode mode) {
    char path[1024];

    memset(path, 0, sizeof(path));
    NuStrCpy(path, name);

    NuFileHandle ret = NUFILE_INVALID;

    if (mode != 5) {

        for (char *c = path; *c != '\0'; c++) {
            if (*c == '\\') {
                *c = '/';
            }
        }

        int i = NuGetFileHandlePS();

        FILE *file = NULL;

        if (mode == NUFILE_OPENMODE_READ) {
            file = fopen(path, "rb");
        } else if (mode == NUFILE_OPENMODE_WRITE) {
            file = fopen(path, "wb");
        } else if (mode == NUFILE_OPENMODE_APPEND) {
            file = fopen(path, "ab+");
        }

        if (file != NULL) {
            g_fileHandles[i] = file;
            ret = NUFILE_PS(i);
        }
    }

    return ret;
}

extern "C" NuFileHandle NuGetFileHandlePS(void) {
    for (int32_t i = 0; i < 0x20; i++) {
        if (g_fileHandles[i] == (FILE *)0x0) {
            return NUFILE_PS(i);
        }
    }

    return NUFILE_INVALID;
}
