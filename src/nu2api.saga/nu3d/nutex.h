#pragma once

#include <pthread.h>
#include <stddef.h>
#include <stdint.h>

#include "decomp.h"

#include "nu2api.saga/nucore/common.h"

typedef enum nutextype_e {
    NUTEX_RTT24 = 15,
} NUTEXTYPE;

typedef struct nutext_s {
    NUTEXTYPE type;
    int width;
    int height;
} NUTEX;

typedef struct nunativetex_s {
    void *ptr;
    int32_t field1_0x4;
    uint8_t field2_0x8;
    uint8_t field3_0x9;
    uint8_t field4_0xa;
    uint8_t field5_0xb;
    uint8_t field6_0xc;
    uint8_t field7_0xd;
    uint8_t field8_0xe;
    uint8_t field9_0xf;
    uint8_t field10_0x10;
    uint8_t field11_0x11;
    uint8_t field12_0x12;
    uint8_t field13_0x13;
    uint8_t field14_0x14;
    uint8_t field15_0x15;
    uint8_t field16_0x16;
    uint8_t field17_0x17;
    uint8_t field18_0x18;
    uint8_t field19_0x19;
    uint8_t field20_0x1a;
    uint8_t field21_0x1b;
    void *image_data;
    size_t size;
    int32_t gl_tex;
} NUNATIVETEX;

C_API_START

extern pthread_mutex_t criticalSection;
extern int max_textures;

void NuTexInitEx(VARIPTR *buf, int max_tex_count);

int NuTexRead(char *name, VARIPTR *buf);

int NuTexCreate(NUTEX *tex);
int NuTexCreateNative(NUNATIVETEX *tex, bool is_pvrtc);

C_API_END

void NuTexCreatePS(NUNATIVETEX *tex, bool is_pvrtc);
