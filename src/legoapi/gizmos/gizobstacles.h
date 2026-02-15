#pragma once

#include "legoapi/gizmo.h"

extern int obstacle_gizmotype_id;

#ifdef __cplusplus

typedef struct GIZOBSTACLE_s {
} GIZOBSTACLE;

ADDGIZMOTYPE* GizObstacles_RegisterGizmo(int type_id);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
