#pragma once

typedef int NUANG;

#define NUANG_90DEG (NUANG)(0x4000)
#define NUANG_180DEG (NUANG)(0x8000)
#define NUANG_270DEG (NUANG)(0xC000)
#define NUANG_360DEG (NUANG)(0x10000)

struct nuangvec_s {
    NUANG x;
    NUANG y;
    NUANG z;
};

typedef struct nuangvec_s NUANGVEC;
