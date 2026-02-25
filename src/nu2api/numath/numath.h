#pragma once

#include "nu2api/nucore/common.h"

#ifdef __cplusplus
extern "C" {
#endif
    static i32 NuMin(i32 a, i32 b) {
        if (a < b) {
            return a;
        }

        return b;
    }

    static i32 NuMax(i32 a, i32 b) {
        if (a > b) {
            return a;
        }

        return b;
    }
#ifdef __cplusplus
}
#endif
