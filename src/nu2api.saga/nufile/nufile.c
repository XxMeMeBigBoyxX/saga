#include "nu2api.saga/nufile/nufile.h"
#include "nu2api.saga/nucore/nustring.h"
#include "nu2api.saga/nuthread/nuthread.h"

#include <stddef.h>
#include <string.h>

#include "decomp.h"

NuFileHandle NuFileOpen(const char *path, NuFileOpenMode mode) {
    return NuFileOpenDF(path, mode, curr_dat);
}

int32_t NuFileStatus(NuFileHandle file) {
    int32_t ret;

    if (0x1fff < file) {
        do {
            /* WARNING: Do nothing block with infinite loop */
        } while (1);
    }
    if (file < 0x400) {
        if (file < 0x800) {
            ret = 0;
        } else {
            ret =
                NuFileStatus((dat_file_infos[file + -0x800].ptr)->openFiles[dat_file_infos[file + -0x800].index].file);
        }
    } else {
        ret = 0;
    }
    return ret;
}

NuFileHandle NuFileOpenDF(const char *path, NuFileOpenMode mode, nudathdr_s *header) {
    NuFileDevice *device = NuFileGetDeviceFromPath(path);
    int fileId;

    if (device == NULL) {
        if (mode != 1 && mode != 2) {
            fileId = 0;
            if (header == NULL) {
                // if (g_apkFileDevice != (NuFileDeviceAndroidAPK *)0x0) {
                // fileId = NuFileAndroidAPK::OpenFile(path, 0);
                //}
                UNIMPLEMENTED("android specific");
            } else {
                fileId = NuDatFileOpen(header, path, mode);
            }
            if (0 < fileId) {
                return fileId;
            }
        }

        device = default_device;
    }

    char buf[256];

    typedef void (*openFuncType)(NuFileDevice *, char *, const char *, int);
    (*(openFuncType)device->openFunc)(device, buf, path, 0x100);

    if (device->vtable == 2) {
        NuStrCat(buf, ";1");
    }

    if (device->vtable == 1) {
        UNIMPLEMENTED("memory card specific");
        int _local[2];
        /*local_1c = buf[2] + -0x30;
        local_20 = buf[3] + -0x30;
        index = NuMcOpen(local_1c, local_20, buf + device->someLength, mode, 0);
        if (index < 0) {
            index = 0;
        } else {
            index = index + 0x1000;
        }*/
    } else {
        int fileIndex = NuPSFileOpen(buf, mode);

        int index;
        if (fileIndex < 0) {
            index = 0;
        } else {
            int64_t size;

            index = fileIndex;
            memset(&file_info[fileIndex], 0, sizeof(fileinfo_s));

            file_info[fileIndex].file = index;
            file_info[fileIndex].mode = mode;

            if (mode == 1) {
                file_info[fileIndex].size.i[0] = 0;
                file_info[fileIndex].size.i[1] = 0;
            } else if (index < 17) {
                do {
                    size = NuFileSeek(fileIndex + 1, 0, 2);
                } while (size < 0);

                file_info[fileIndex].size.l = size;

                if (mode == 3) {
                    while (NuFileStatus(fileIndex + 1) != 0) {
                    }
                }

                do {
                    size = NuFileSeek(fileIndex + 1, 0, 0);
                } while (size < 0);

                if (mode == 3) {
                    while (NuFileStatus(fileIndex + 1) != 0) {
                    }
                }
            }

            if (mode == 0) {
                file_info[fileIndex].offset.i[1] = nufile_buffering_enabled;
            }

            index = fileIndex + 1;
        }
    }

    return NUFILE_PS(index);
}

NuFileDevice *NuFileGetDeviceFromPath(const char *path) {
    int i;

    for (i = 0; i < 8 && (path[i] != ':'); i++) {
    }

    if (i < 8) {
        for (int index = 0; index < numdevices; index++) {
            // if (NuStrNICmp(path, index * 0x234 + 0x6c93b4, devices[index].length) == 0) {
            // return &devices[index];
            //}
            UNIMPLEMENTED();
        }
    }

    return NULL;
}

size_t NuMemFileRead(NuFileHandle file, char *dest, size_t size) {
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

size_t NuFileRead(NuFileHandle file, void *dest, size_t length) {
    int index;
    uint uVar1;
    fileinfo_s *info;
    uint uVar2;
    int iVar3;
    uint uVar4;
    char *local_24;
    int bytesRead;

    if (file < 0x2000) {
        if (file < 0x1000) {
            if (file < 0x400) {
                index = file + -1;
                info = file_info + index;
                if (file_info[index].offset.i[1] == 0) {
                    bytesRead = NuPSFileRead(index, dest, length);
                } else {
                    if (file_info[index].buffer == (FileBuffer *)0x0) {
                        // AquireFileBuffer(info);
                    }
                    bytesRead = 0;
                    local_24 = dest;
                    while (0 < (int)length) {
                        if (file_info[index].size.i[1] <= file_info[index].field1_0x4.i[1]) {
                            if (file_info[index].size.i[1] < file_info[index].field1_0x4.i[1]) {
                                return bytesRead;
                            }
                            if (file_info[index].size.u[0] <= file_info[index].field1_0x4.u[0]) {
                                return bytesRead;
                            }
                        }
                        if ((file_info[index].field1_0x4.i[1] < file_info[index].field6_0x20) ||
                            ((file_info[index].field1_0x4.i[1] <= file_info[index].field6_0x20 &&
                              (file_info[index].field1_0x4.u[0] < file_info[index].field5_0x1c)))) {
                        LAB_0026ae23:
                            if (file_info[index].field2_0xc != file_info[index].field1_0x4.i[0] ||
                                file_info[index].field1_0x4.i[1] != file_info[index].field3_0x10) {
                                NuPSFileLSeek(info->file, file_info[index].field1_0x4.l, 0);
                                uVar2 = file_info[index].field1_0x4.i[1];
                                file_info[index].field2_0xc = file_info[index].field1_0x4.i[0];
                                file_info[index].field3_0x10 = uVar2;
                            }
                            iVar3 = NuPSFileRead(info->file, (file_info[index].buffer)->field2_0x8, 0x400);
                            file_info[index].offset.i[0] = iVar3;
                            uVar2 = file_info[index].field3_0x10;
                            file_info[index].field5_0x1c = file_info[index].field2_0xc;
                            file_info[index].field6_0x20 = uVar2;
                            uVar2 = file_info[index].field2_0xc;
                            uVar4 = file_info[index].field3_0x10;
                            uVar1 = file_info[index].offset.u[0];
                            file_info[index].field2_0xc = uVar1 + uVar2;
                            file_info[index].field3_0x10 = ((int)uVar1 >> 0x1f) + uVar4 + (uint)CARRY4(uVar1, uVar2);
                        } else {
                            uVar2 = file_info[index].offset.u[0];
                            iVar3 = ((int)uVar2 >> 0x1f) + file_info[index].field6_0x20 +
                                    (uint)CARRY4(uVar2, file_info[index].field5_0x1c);
                            if ((iVar3 <= file_info[index].field1_0x4.i[1]) &&
                                ((iVar3 < file_info[index].field1_0x4.i[1] ||
                                  (uVar2 + file_info[index].field5_0x1c <= file_info[index].field1_0x4.u[0]))))
                                goto LAB_0026ae23;
                        }
                        uVar4 = file_info[index].offset.i[0] +
                                (file_info[index].field5_0x1c - file_info[index].field1_0x4.i[0]);
                        uVar2 = length;
                        if ((int)uVar4 <= (int)length) {
                            uVar2 = uVar4;
                        }
                        if (uVar2 != 0) {
                            memcpy(local_24,
                                   (void *)((int)file_info[index].buffer +
                                            (file_info[index].field1_0x4.i[0] - file_info[index].field5_0x1c) + 8),
                                   uVar2);
                        }
                        local_24 = local_24 + uVar2;
                        bytesRead = bytesRead + uVar2;
                        length = length - uVar2;
                        uVar4 = file_info[index].field1_0x4.u[0];
                        iVar3 = file_info[index].field1_0x4.i[1];
                        file_info[index].field1_0x4.i[0] = uVar2 + uVar4;
                        file_info[index].field1_0x4.i[1] = ((int)uVar2 >> 0x1f) + iVar3 + (uint)CARRY4(uVar2, uVar4);
                    }
                }
            } else {
                bytesRead = NuMemFileRead(file, dest, length);
            }
        } else {
            // bytesRead = NuMcRead(file + -0x1000, dest, length, 0);
        }
    } else {
        // bytesRead = NuFileAndroidAPK::ReadFile(file, dest, length);
    }
    return bytesRead;
}

int32_t NuFileSeek(NuFileHandle file, int64_t offset, int32_t seekMode) {
    UNIMPLEMENTED();
}

nudathdr_s *NuDatOpen(char *name, void **bufferBase, int32_t zero) {
    return NuDatOpenEx(name, bufferBase, zero, 0);
}

void APIEndianSwap(void *data, size_t count, size_t size) {
    return;
}

nudathdr_s *NuDatOpenEx(char *name, void **bufferBase, int zero, short mode) {
    uint uVar3;
    int file;
    int len;
    nudathdr_struct1 *puVar4;
    nudathdr_struct1 *puVar5;
    char *str;
    int buffer[2];
    nudathdr_s *header;
    int j;
    int local_38;
    uint local_34;
    int offsetL;
    int offsetH;
    int k;
    int i;
    nudathdr_struct2 *struct2;
    int uVar1;
    undefined4 uVar2;
    undefined4 uVar6;
    undefined4 uVar7;

    uVar2 = nufile_buffering_enabled;
    mode = (int)mode;
    uVar7 = 0;
    uVar6 = 0;
    file = NuFileOpenDF(name, mode, (nudathdr_s *)0x0);
    if (file == 0) {
        header = (nudathdr_s *)0x0;
        nufile_buffering_enabled = uVar2;
    } else {
        NuFileOpenSize(file);
        NuFileRead(file, buffer, 8);
        APIEndianSwap(buffer, 2, 4);
        offsetH = buffer[0] >> 31;
        offsetL = buffer[0];
        if (offsetH < 0) {
            offsetL = (int)((ulonglong)(uint)buffer[0] * 0xffffff00);
            offsetH = (offsetH * -0x100 - buffer[0]) + (int)((ulonglong)(uint)buffer[0] * 0xffffff00 >> 0x20);
        }
        NuFileSeek(file, CONCAT44(offsetH, offsetL), 0);
        len = NuStrLen(name);
        header = (nudathdr_s *)*bufferBase;
        *bufferBase = (void *)((int)*bufferBase + 0x178);
        memset(header, 0, 0x178);
        header->field300_0x16c = 1;
        header->path = (char *)*bufferBase;
        *bufferBase = (void *)((int)*bufferBase + (len + 0x10U & 0xfffffff0));
        NuStrCpy(header->path, name);
        NuFileRead(file, header, 4);
        APIEndianSwap(header, 1, 4);
        NuFileRead(file, &header->hashesCount, 4);
        APIEndianSwap(&header->hashesCount, 1, 4);
        header->arr1 = (nudathdr_struct1 *)((int)*bufferBase + 0x1fU & 0xffffffe0);
        *bufferBase = (void *)((int)*bufferBase + 0x1fU & 0xffffffe0);
        *bufferBase = (void *)((int)*bufferBase + header->hashesCount * 0x10);
        NuFileRead(file, header->arr1, header->hashesCount << 4);
        for (i = 0; i < header->hashesCount; i = i + 1) {
            APIEndianSwap(header->arr1 + i, 1, 4);
            APIEndianSwap(&header->arr1[i].field1_0x4, 1, 4);
            APIEndianSwap(&header->arr1[i].field2_0x8, 1, 4);
        }
        NuFileRead(file, &header->count2, 4);
        APIEndianSwap(&header->count2, 1, 4);
        header->arr2 = (nudathdr_struct2 *)*bufferBase;
        *bufferBase = (void *)((int)*bufferBase + header->count2 * 0xc);
        if (header->field0_0x0 < -4) {
            NuFileRead(file, header->arr2, header->count2 * 0xc);
        } else {
            NuFileRead(file, header->arr2, header->count2 << 3);
            struct2 = header->arr2;
            k = header->count2;
            while (k = k + -1, 0 < k) {
                header->arr2[k].field4_0xa = 0;
                header->arr2[k].field3_0x8 = 0;
                header->arr2[k].someName = *(char **)((int)struct2 + k * 8 + 4);
                header->arr2[k].field1_0x2 = *(short *)((int)struct2 + k * 8 + 2);
                header->arr2[k].field0_0x0 = *(short *)(k * 8 + (int)struct2);
            }
        }
        for (k = 0; k < header->count2; k = k + 1) {
            APIEndianSwap(header->arr2 + k, 1, 2);
            APIEndianSwap(&header->arr2[k].field1_0x2, 1, 2);
            APIEndianSwap(&header->arr2[k].someName, 1, 4);
            if (header->field0_0x0 < -4) {
                APIEndianSwap(&header->arr2[k].field3_0x8, 1, 2);
                APIEndianSwap(&header->arr2[k].field4_0xa, 1, 2);
            }
        }
        NuFileRead(file, &header->field5_0x14, 4);
        APIEndianSwap(&header->field5_0x14, 1, 4);
        header->field6_0x18 = (int)*bufferBase;
        *bufferBase = (void *)((int)*bufferBase + header->field5_0x14);
        NuFileRead(file, (void *)header->field6_0x18, header->field5_0x14);
        for (k = 0; k < header->count2; k = k + 1) {
            header->arr2[k].someName = header->arr2[k].someName + header->field6_0x18;
        }
        header->arr2->someName = (char *)0x0;
        *bufferBase = (void *)((int)*bufferBase - header->field5_0x14);
        *bufferBase = (void *)((int)*bufferBase + header->count2 * -0xc);
        header->arr2 = (nudathdr_struct2 *)0x0;
        header->field6_0x18 = 0;
        header->arr3hashes = (uint *)0x0;
        header->count3 = 0;
        header->count4 = 0;
        header->arr4 = (char *)0x0;
        if (header->field0_0x0 < -1) {
            header->arr3hashes = (uint *)((int)*bufferBase + 0x1fU & 0xffffffe0);
            *bufferBase = (void *)((int)*bufferBase + 0x1fU & 0xffffffe0);
            *bufferBase = (void *)((int)*bufferBase + header->hashesCount * 4);
            NuFileRead(file, header->arr3hashes, header->hashesCount << 2);
            for (k = 0; k < header->hashesCount; k = k + 1) {
                APIEndianSwap(header->arr3hashes + k, 1, 4);
            }
            NuFileRead(file, &header->count3, 4);
            APIEndianSwap(&header->count3, 1, 4);
            NuFileRead(file, &header->count4, 4);
            APIEndianSwap(&header->count4, 1, 4);
            header->arr4 = (char *)((int)*bufferBase + 0x1fU & 0xffffffe0);
            *bufferBase = (void *)((int)*bufferBase + 0x1fU & 0xffffffe0);
            *bufferBase = (void *)((int)*bufferBase + header->count4);
            NuFileRead(file, header->arr4, header->count4);
            str = header->arr4;
            for (k = 0; k < header->count3; k = k + 1) {
                len = NuStrLen(str);
                str = str + len + 1;
                if (((uint)str & 1) != 0) {
                    str = str + 1;
                }
                APIEndianSwap(str, 1, 2);
                str = str + 2;
            }
        }
        for (k = 0; k < 20; k = k + 1) {
            header->openFiles[k].field1_0x4 = -1;
            header->openFiles[k].file = 0;
            header->openFiles[k].position.i[0] = 0;
            header->openFiles[k].position.i[1] = 0;
        }
        header->openFiles[0].file = file;
        header->openFiles[0].position.i[0] = 0;
        header->openFiles[0].position.i[1] = 0;
        header->mode = mode;
        if (-3 < header->field0_0x0) {
            for (i = 0; i < header->hashesCount + -1; i = i + 1) {
                local_34 = header->arr3hashes[i];
                local_38 = i;
                j = i;
                while (j = j + 1, j < header->hashesCount) {
                    if (header->arr3hashes[j] <= local_34) {
                        local_34 = header->arr3hashes[j];
                        local_38 = j;
                    }
                }
                if (i != local_38) {
                    uVar3 = header->arr3hashes[i];
                    header->arr3hashes[i] = header->arr3hashes[local_38];
                    header->arr3hashes[local_38] = uVar3;
                    puVar5 = header->arr1 + i;
                    file = puVar5->field0_0x0;
                    len = puVar5->field1_0x4;
                    uVar1 = puVar5->field2_0x8;
                    uVar2 = puVar5->field3_0xc;
                    puVar4 = header->arr1 + i;
                    puVar5 = header->arr1 + local_38;
                    puVar4->field0_0x0 = puVar5->field0_0x0;
                    puVar4->field1_0x4 = puVar5->field1_0x4;
                    puVar4->field2_0x8 = puVar5->field2_0x8;
                    puVar4->field3_0xc = puVar5->field3_0xc;
                    puVar5 = header->arr1 + local_38;
                    puVar5->field0_0x0 = file;
                    puVar5->field1_0x4 = len;
                    puVar5->field2_0x8 = uVar1;
                    puVar5->field3_0xc = uVar2;
                }
            }
        }
    }

    return header;
}

size_t NuFileOpenSize(NuFileHandle file) {
    UNIMPLEMENTED();
}

static int32_t CSWTCH_152[3] = {1, 2, 0};

int64_t NuPSFileLSeek(NuFileHandle file, int64_t offset, int32_t seekMode) {
    int whence = 0;
    long value;
    int bit32;

    if (seekMode - 1U < 2) {
        whence = CSWTCH_152[seekMode - 1U];
    }
    whence = fseek(g_fileHandles[file], offset, whence);
    bit32 = 0;
    value = 0;
    if (whence == 0) {
        value = ftell(g_fileHandles[file]);
        bit32 = value >> 31;
    }
    return CONCAT44(bit32, value);
}