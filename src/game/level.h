#pragma once

#include "game/world.h"
#include "globals.h"

#ifdef __cplusplus

void Level_SetDefaults(LEVELDATA *level);
LEVELDATA *Level_FindByName(char *name, int *indexDest);
void Level_Draw(WORLDINFO *world);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
