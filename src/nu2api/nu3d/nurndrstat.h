#pragma once

#include "nu2api/nu3d/numtl.h"
#include "nu2api/nucore/common.h"

typedef struct nurndrstate_s {
    i32 global_state_bottom;
    i32 global_state_top;

    NUMTL *mtl;

    u16 unused;

    u8 *unknown_10;

    i32 tex_id;

    i32 global_state_ptr;

    u16 tex_slots;

    i16 konst_id;
    i32 global_id;
    i16 lights_id;
    i16 lights_type;
    i16 lights_specular_id;
    i16 lights_fx_id;
    i16 camera_id;
    i16 fog_id;
    i16 vertex_groups_id;
    i16 reflection_id;
} NURNDRSTATE;
