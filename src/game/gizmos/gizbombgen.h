#pragma once

#include "game/gizmo.h"

extern int bombgen_gizmotype_id;

#ifdef __cplusplus

typedef struct GIZBOMBGEN_s {
} GIZBOMBGEN;

void GizBombGen_RegisterGizmo(int type_id);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
