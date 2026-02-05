#pragma once

#include "game/gizmo.h"

extern int gizbuildit_gizmotype_id;

#ifdef __cplusplus

typedef struct GIZBUILDIT_s {
} GIZBUILDIT;

void GizBuildIts_RegisterGizmo(int type_id);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
