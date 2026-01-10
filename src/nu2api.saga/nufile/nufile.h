#pragma once

#include <stdint.h>
#include <stdio.h>

#include "decomp.h"

#include "export.h"

typedef enum NuFileOpenMode {
    NUFILE_OPENMODE_READ = 0,
    NUFILE_OPENMODE_WRITE = 1,
    NUFILE_OPENMODE_APPEND = 2,
} NuFileOpenMode;

typedef struct NuFileDevice NuFileDevice;
typedef struct nudathdr_s nudathdr_s;

typedef uint32_t NuFileHandle;
enum NuFileHandleRanges {
    NUFILE_HANDLE_RANGE_PS = 1,
    NUFILE_HANDLE_RANGE_MEM = 0x400,
    NUFILE_HANDLE_RANGE_DAT = 0x800,
    NUFILE_HANDLE_RANGE_MC = 0x1000,
    NUFILE_HANDLE_RANGE_NATIVE = 0x2000,
};

#define NUFILE_PS(index) (index + NUFILE_HANDLE_RANGE_PS)
#define NUFILE_MEM(index) (index + NUFILE_HANDLE_RANGE_MEM)
#define NUFILE_DAT(index) (index + NUFILE_HANDLE_RANGE_DAT)
#define NUFILE_MC(index) (index + NUFILE_HANDLE_RANGE_MC)
#define NUFILE_NATIVE(index) (index + NUFILE_HANDLE_RANGE_NATIVE)
#define NUFILE_IS_PS(handle) ((handle) < NUFILE_HANDLE_RANGE_MEM)
#define NUFILE_IS_MEM(handle) (((handle) >= NUFILE_HANDLE_RANGE_MEM) && ((handle) < NUFILE_HANDLE_RANGE_DAT))
#define NUFILE_IS_DAT(handle) (((handle) >= NUFILE_HANDLE_RANGE_DAT) && ((handle) < NUFILE_HANDLE_RANGE_MC))
#define NUFILE_IS_MC(handle) (((handle) >= NUFILE_HANDLE_RANGE_MC) && ((handle) < NUFILE_HANDLE_RANGE_NATIVE))
#define NUFILE_IS_NATIVE(handle) ((handle) >= NUFILE_HANDLE_RANGE_NATIVE)
#define NUFILE_INDEX_PS(handle) ((handle) - NUFILE_HANDLE_RANGE_PS)
#define NUFILE_INDEX_MEM(handle) ((handle) - NUFILE_HANDLE_RANGE_MEM)
#define NUFILE_INDEX_DAT(handle) ((handle) - NUFILE_HANDLE_RANGE_DAT)
#define NUFILE_INDEX_MC(handle) ((handle) - NUFILE_HANDLE_RANGE_MC)
#define NUFILE_INDEX_NATIVE(handle) ((handle) - NUFILE_HANDLE_RANGE_NATIVE)
#define NUFILE_INVALID ((NuFileHandle)(-1))

typedef struct nudatfileinfo_s nudatfileinfo_s;
typedef struct NuMemFile NuMemFile;
typedef struct fileinfo_s fileinfo_s;
typedef struct FileBuffer FileBuffer;
typedef struct nudathdr_struct1 nudathdr_struct1;
typedef struct nudathdr_struct2 nudathdr_struct2;

C_API_START

extern nudathdr_s *curr_dat;
extern NuFileDevice host_device;
extern NuFileDevice *default_device;
extern int32_t numdevices;
extern NuFileDevice devices[16];
extern int32_t file_criticalsection;
extern nudatfileinfo_s dat_file_infos[20];
extern FILE *g_fileHandles[32];
extern NuMemFile memfiles[16];
extern int32_t nufile_buffering_enabled;
extern fileinfo_s file_info[32];

uint8_t DEV_FormatName(NuFileDevice *device, char *dest, char *path, int length);

void NuFileCorrectSlashes(NuFileDevice *device, char *path);
void NuFileReldirFix(NuFileDevice *device, char *path);

NuFileHandle NuFileOpen(const char *path, NuFileOpenMode mode);
int32_t NuFileStatus(NuFileHandle file);
NuFileHandle NuFileOpenDF(const char *path, NuFileOpenMode mode, nudathdr_s *header);
size_t NuFileRead(NuFileHandle index, void *dest, size_t length);
NuFileDevice *NuFileGetDeviceFromPath(const char *path);
uint32_t NuFileOpenSize(NuFileHandle file);
int32_t NuFileSeek(NuFileHandle file, int64_t offset, int32_t seekMode);

int32_t NuGetFileHandlePS(void);
int32_t NuPSFileOpen(const char *path, NuFileOpenMode mode);
int32_t NuPSFileClose(int32_t index);
size_t NuPSFileRead(int32_t index, void *dest, size_t len);
size_t NuPSFileWrite(int32_t index, const void *src, size_t len);
int64_t NuPSFileLSeek(int32_t index, int64_t offset, int32_t seekMode);

size_t NuMemFileRead(NuFileHandle file, char *dest, size_t size);

NuFileHandle NuDatFileOpen(nudathdr_s *header, const char *name, int32_t mode);
size_t NuDatFileRead(NuFileHandle file, void *dest, size_t size);
nudathdr_s *NuDatOpen(char *name, void **bufferBase, int32_t zero);
nudathdr_s *NuDatOpenEx(char *name, void **bufferBase, int zero, short mode);

nudathdr_s *NuDatSet(nudathdr_s *header);

C_API_END

CPP_API_START
int32_t NuDatFileGetFreeInfo(void);
size_t BinarySearch(int32_t element, int32_t *array, size_t length);
CPP_API_END