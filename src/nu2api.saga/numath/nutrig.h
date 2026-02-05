#pragma once

#include <math.h>

#include "nu2api.saga/nucore/common.h"
#include "nu2api.saga/numath/nuang.h"

#define NUTRIGTABLE_COUNT 32768
#define NUTRIGTABLE_INTERVAL (f32)(2.0f * M_PI / NUTRIGTABLE_COUNT)

/// @brief The sine lookup table
/// @details The sine lookup table is a table of the sine function for the angles 0 to 2π.
extern f32 NuTrigTable[NUTRIGTABLE_COUNT];

#define NU_SIN_LUT(ang) NuTrigTable[(int)(ang) >> 1 & 0x7fff]
#define NU_COS_LUT(ang) NuTrigTable[((int)(ang) + NUANG_90DEG) >> 1 & 0x7fff]
#define NU_TAN_LUT(ang) (NuTrigTable[(int)(ang) >> 1 & 0x7fff] / NuTrigTable[((int)(ang) + NUANG_90DEG) >> 1 & 0x7fff])

#ifdef __cplusplus
extern "C" {
#endif
    /// @brief Initializes the sine lookup table
    /// @details Initializes the sine lookup table with the values of the sine function for the angles 0 to 2π.
    /// @return void
    void NuTrigInit(void);

    i16 NuACos(f32 cos);
    int NuAtan2D(f32 dx, f32 dy);
    f32 NuAtan2(f32 dx, f32 dy);
#ifdef __cplusplus
}
#endif
