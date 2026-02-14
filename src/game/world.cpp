#include "game/world.h"
#include "game/level.h"
#include "globals.h"
#include "nu2api.saga/nuandroid/ios_graphics.h"

#include <string.h>

WORLDINFO WorldInfo[2];
WORLDINFO *WORLD = &WorldInfo[0];

/// @brief Pointer to the currently loading world info
static WORLDINFO *LWORLD = &WorldInfo[0];

void WorldInfo_Activate(void) {
    char result;

    WORLD = LWORLD;
    WorldInfo_Init(LWORLD);

    result = 0;
    if (NuIOS_IsLowEndDevice() && WORLD != NULL) {
        LEVELDATA *current_level = WORLD->current_level;

        if (current_level && current_level->data_display.far_clip < 20000.0f) {
            result = current_level->data_display.fog_start < 20000.0f;
        }
    }

    g_BackgroundUsedFogColour = result;
}

void WorldInfo_Init(WORLDINFO *info) {
}

WORLDINFO *WorldInfo_CurrentlyActive(void) {
    return WORLD;
}

WORLDINFO *WorldInfo_CurrentlyLoading(void) {
    return LWORLD;
}

void WorldInfo_InitOnce(void) {
    memset(WorldInfo, 0, sizeof(WorldInfo));
}
