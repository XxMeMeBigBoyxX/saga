#pragma once

#include "legoapi/gizmo.h"

extern int gizrandom_gizmotype_id;

#ifdef __cplusplus

typedef struct gizrandom_s {
    u8 filler[0x3c];
} GIZRANDOM;

ADDGIZMOTYPE* GizRandom_RegisterGizmo(int type_id);

extern "C" {
#endif

#ifdef __cplusplus
}
#endif
