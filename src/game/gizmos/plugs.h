#pragma once

#include "game/gizmo.h"

extern int plug_gizmotype_id;

#ifdef __cplusplus

typedef struct PLUG_s {
} PLUG;

void Plugs_RegisterGizmo(int type_id);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
