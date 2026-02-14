#pragma once

#include "nu2api.saga/nu3d/nugscn.h"
#include "nu2api.saga/nucore/common.h"

typedef struct WORLDINFO_s {
    char filler0[0x104];
    VARIPTR giz_buffer;
    char filler1[0x20];
    struct LEVELDATA_s *current_level;
    char filler2[0x10];
    NUGSCN *current_gscn;

    char filler3[0x4fbc];

    struct GIZTIMER_s *giz_timers;
    i32 giz_timers_count;

    char filler4[172];
} WORLDINFO;

extern WORLDINFO WorldInfo[];

/// @brief Global pointer to the currently active world info
extern WORLDINFO *WORLD;

#ifdef __cplusplus

void WorldInfo_Activate(void);
void WorldInfo_Init(WORLDINFO *info);
WORLDINFO *WorldInfo_CurrentlyActive(void);
WORLDINFO *WorldInfo_CurrentlyLoading(void);
void WorldInfo_InitOnce(void);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
