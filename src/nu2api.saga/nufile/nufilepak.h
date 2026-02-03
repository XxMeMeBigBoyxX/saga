#pragma once

#include "nu2api.saga/nucore/common.h"

typedef struct nufilepakhdrv0_s {
    u32 type;
    u32 item_count;
    u32 file_size;
} NUFILEPAKHDR_V0;

typedef struct nufilepakhdrv1_s {
    u32 type;
    u32 item_count;
    u32 file_size;
    u32 checksum;
    u32 flags;
} NUFILEPAKHDR_V1;

typedef struct nufilepakhdrv2_s {
    u32 type;
    u32 item_count;
    u32 file_size;
    u32 checksum;
    u32 flags;
    u32 decrypted_checksum;
} NUFILEPAKHDR;

typedef struct nufilepakitemattr_s {
    u32 required : 1;
    u32 removed : 1;
} NUFILEPAKITEMATTR;

// There are no known uses of functions of this type, so their parameters are
// unknown.
typedef int NuFilePakMemMoveFn();

typedef struct nufilepakitem_s {
    int name_offset;
    int data_offset;
    int size;
    int alignment;
    NUFILEPAKITEMATTR attr;
    NuFilePakMemMoveFn *pre_move_fn;
    NuFilePakMemMoveFn *post_move_fn;
} NUFILEPAKITEM;

typedef enum {
    NUFILEPAK_ERROR_NONE,
    NUFILEPAK_ERROR_FILENOTFOUND,
    NUFILEPAK_ERROR_FILEIO,
    NUFILEPAK_ERROR_CHECKSUM,
    NUFILEPAK_ERROR_UNSUPPORTEDTYPE,
    NUFILEPAK_ERROR_ALIGNMENT,
    NUFILEPAK_ERROR_KEYMISMATCH,
    NUFILEPAK_ERROR_CNT,
} NUFILEPAK_ERROR;

#ifdef __cplusplus
extern "C" {
#endif
    void *NuFilePakLoad(char *filepath, VARIPTR *buf, VARIPTR buf_end, int alignment);
    void *NuFilePakLoadKey(char *filepath, VARIPTR *buf, VARIPTR buf_end, int alignment, unsigned char *key,
                           u32 key_len);

    int NuFilePakGetItem(void *hdr, char *item_name);
    int NuFilePakGetItemInfo(void *hdr, int item_handle, void **addr, int *size);
#ifdef __cplusplus
}
#endif
