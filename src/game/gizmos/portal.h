#pragma once

#include "game/gizmo.h"
#include "game/world.h"

extern int portal_gizmotype_id;

typedef struct nuportal_s {
    u8 filler[0x1a];
    i8 id;
    u8 unknown;
    u32 active;
} NUPORTAL;

typedef struct gizportalprogress_s {
    u32 progress_mask;
} GIZPORTALPROGRESS;

#ifdef __cplusplus

ADDGIZMOTYPE* Portal_RegisterGizmo(int type_id);
char *Portal_GetOutputName(GIZMO *gizmo, int output_index);
void Portal_Activate(GIZMO *gizmo, int active);
void PortalDoors_Reset(WORLDINFO* world_info);

extern "C" {
#endif

void NuPortalSetActiveDirect(NUPORTAL* portal, int active);

#ifdef __cplusplus
}
#endif
