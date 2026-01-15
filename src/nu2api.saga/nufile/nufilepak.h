#include "decomp.h"

#include "nu2api.saga/nucore/types.h"

typedef struct nufilepakhdrv2_s {
    unsigned int type;
    unsigned int item_count;
    unsigned int file_size;
    unsigned int checksum;
    unsigned int flags;
    unsigned int decrypted_checksum;
} NUFILEPAKHDR;

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

C_API_START

void *NuFilePakLoad(char *filepath, VARIPTR *buf, VARIPTR buf_end, int alignment);
void *NuFilePakLoadKey(char *filepath, VARIPTR *buf, VARIPTR buf_end, int alignment, unsigned char *key,
                       unsigned int key_len);

C_API_END
