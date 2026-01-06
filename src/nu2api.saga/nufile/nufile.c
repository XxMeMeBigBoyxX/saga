#include "nu2api.saga/nufile/nufile.h"

#include "nu2api.saga/nustr/nustr.h"
#include "nu2api.saga/nuthread/nuthread.h"

#include <stddef.h>
#include <string.h>

#include "decomp.h"

NuFileHandle NuFileOpen(const char *path, OpenMode mode) {
    return NuFileOpenDF(path, mode, curr_dat);
}

NuFileHandle NuFileOpenDF(const char *path, OpenMode mode, nudathdr_s *header) {
    NuFileHandle file;

    NuFileDevice *device = NuFileGetDeviceFromPath(path);

    if (device == (NuFileDevice *)0x0) {
        if (mode != MODE_WRITE && mode != MODE_APPEND) {
            file = 0;
            if (header == NULL) {
                UNIMPLEMENTED();
                // if (g_apkFileDevice != 0) {
                // file = NuFileAndroidAPK::OpenFile(path, 0);
                // }
            } else {
                file = NuDatFileOpen(header, path, mode);
            }

            if (file > 0) {
                return file;
            }
        }
        device = default_device;
    }

    char buf[256];

    //(*(code *)device->openFunc)(device, buf, path, 0x100);

    if (device->field0_0x0 == 2) {
        NuStrCat(buf, ";1");
    }

    /*

    if (device->field0_0x0 == 1) {
        local_1c = filename[2] + -0x30;
        local_20 = filename[3] + -0x30;
        index = NuMcOpen(local_1c, local_20, filename + *(int *)&device->field_0x48, mode, 0);
        if (index < 0) {
            index = 0;
        } else {
            index = index + 0x1000;
        }
    } else {
        fileIndex = NuPSFileOpen(buf, mode);
        if (fileIndex < 0) {
            index = 0;
        } else {
            index = fileIndex;
            memset(file_info.field31_0x28 + fileIndex * 0xe + -10, 0, 0x38);
            lVar2 = CONCAT44(local_2c._4_4_, (int)local_2c);
            file_info.field31_0x28[fileIndex * 0xe + -10] = index;
            file_info.field31_0x28[fileIndex * 0xe + 2] = mode;
            if (mode == 1) {
                file_info.field31_0x28[fileIndex * 0xe + -5] = 0;
                file_info.field31_0x28[fileIndex * 0xe + -4] = 0;
            } else if (index < 0x11) {
                do {
                    local_2c = lVar2;
                    lVar2 = NuFileSeek(fileIndex + 1, 0, 0, 2);
                } while (lVar2 < 0);
                *(long long *)(file_info.field31_0x28 + fileIndex * 0xe + -5) = lVar2;
                local_2c = lVar2;
                if (mode == 3) {
                    do {
                        iVar1 = NuFileStatus(fileIndex + 1);
                        lVar2 = local_2c;
                    } while (iVar1 != 0);
                }
                do {
                    local_2c = lVar2;
                    lVar2 = NuFileSeek(fileIndex + 1, 0, 0, 0);
                } while (lVar2 < 0);
                local_2c = lVar2;
                if (mode == 3) {
                    do {
                        iVar1 = NuFileStatus(fileIndex + 1);
                    } while (iVar1 != 0);
                }
            }
            if (mode == 0) {
                file_info.field31_0x28[fileIndex * 0xe] = nufile_buffering_enabled;
            }
            index = fileIndex + 1;
        }
    }
    */
}

NuFileDevice *NuFileGetDeviceFromPath(const char *path) {
    int i;

    for (i = 0; i < 8 && (path[i] != ':'); i++) {
    }

    if (i < 8) {
        for (int index = 0; index < _numdevices; index++) {
            // if (NuStrNICmp(path, index * 0x234 + 0x6c93b4, devices[index].length) == 0) {
            // return &devices[index];
            //}
            UNIMPLEMENTED();
        }
    }

    return NULL;
}

int32_t NameToHash(const char *name) {
    int32_t hash = 0x811c9dc5;

    for (; *name != 0; name = name + 1) {
        hash = (hash ^ (int32_t)*name) * 0x199933;
    }

    return hash;
}

size_t BinarySearch(int32_t element, int32_t *array, size_t length) {
    size_t end = length - 1;
    size_t start = 0;

    while (1) {
        if (end < start) {
            return -1;
        }

        size_t index = (end + start) / 2;
        if (array[index] == element) {
            return index;
        } else if (array[index] < element) {
            start = index + 1;
        } else {
            end = index - 1;
        }
    }
}

int32_t NuDatFileGetFreeInfo(void) {
    NuThreadCriticalSectionBegin(file_criticalsection);

    int32_t found = -1;
    for (int32_t i = 0; i < 20; i++) {
        if (dat_file_infos[i].used == 0) {
            dat_file_infos[i].used = 1;
            found = i;
            break;
        }
    }

    NuThreadCriticalSectionEnd(file_criticalsection);
    return found;
}

size_t NuPSFileRead(int32_t index, void *dest, size_t len) {
    return fread(dest, 1, len, g_fileHandles[index]);
}

size_t NuMemFileRead(int32_t file, char *dest, size_t size) {
    if (NUFILE_IS_MEM(file)) {
        int32_t i = NUFILE_INDEX_MEM(file);
        ptrdiff_t remaining = memfiles[i].end - memfiles[i].ptr + 1;

        if (remaining <= size) {
            size = remaining;
        }

        if (size != 0) {
            memcpy(dest, memfiles[i].ptr, size);
            memfiles[i].ptr = ((char *)memfiles[i].ptr + size);
        }

        return size;
    } else {
        return NuDatFileRead(file, dest, size);
    }
}

NuFileHandle NuDatFileOpen(nudathdr_s *header, const char *name, int32_t mode) {
    UNIMPLEMENTED();
}

size_t NuDatFileRead(NuFileHandle file, void *dest, size_t size) {
    UNIMPLEMENTED();
}