#pragma once

typedef struct numtl_s {
    char filler1[0x40];
    unsigned char unk_flag1;
    unsigned char unk_flag2;
    unsigned char unk_flag3;
    char filler2[0x281];
} NUMTL;

typedef struct nushadermtldesc_s {

} NUSHADERMTLDESC;

#ifdef __cplusplus

void DefaultMtl(NUMTL* mtl);
void NuMtlCreatePS(NUMTL* mtl, int unk_flag);

extern "C" {
#endif

void NuShaderMtlDescInit(NUSHADERMTLDESC* shader_mtl_desc);
NUMTL* NuMtlCreate(int count);
void NuMtlUpdate(NUMTL* mtl);

#ifdef __cplusplus
}
#endif
