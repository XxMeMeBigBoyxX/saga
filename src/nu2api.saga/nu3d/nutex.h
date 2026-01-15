#pragma once

#include <stddef.h>
#include <stdint.h>

#include "decomp.h"

struct nutex_s {};
typedef struct nutex_s NUTEX;

struct nunativetex_s {
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
    void *imagedata;
    size_t size;
    int32_t glTex;
};
typedef struct nunativetex_s NUNATIVETEX;

C_API_START

int32_t NuTexRead(char *name, void **buffer);
int32_t NuTexCreateNative(nunativetex_s *tex, bool isPvr);

C_API_END