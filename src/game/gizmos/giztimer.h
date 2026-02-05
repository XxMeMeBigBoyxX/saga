#pragma once

#include "game/gizmo.h"

extern int giztimer_gizmotype_id;

#ifdef __cplusplus

typedef struct GIZTIMER_s {
} GIZTIMER;

void GizTimer_RegisterGizmo(int type_id);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
