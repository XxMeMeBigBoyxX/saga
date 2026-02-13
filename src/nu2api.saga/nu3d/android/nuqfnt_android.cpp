#include "nu2api.saga/nu3d/nuqfnt.h"

#include <string.h>

#include "nu2api.saga/nu3d/numtl.h"
#include "nu2api.saga/nucore/common.h"

typedef struct vufnt_android_s {
    u32 color_abgr;

    // Fields uncertain.
    u8 unknown_04[0x4c];

    f32 x_scale;
    f32 y_scale;
} VUFNT_ANDROID;

int NuQFntReadPS(VUFNT *font, int tex_id, int flags, int render_plane, VARIPTR *buffer, VARIPTR buffer_end) {
    NUMTL *mtl;
    NUSHADERMTLDESC shader_desc;
    VUFNT_ANDROID *platform_font;

    mtl = NuMtlCreate(1);
    font->mtl = mtl;

    mtl->scale.x = 1.0f;
    mtl->scale.y = 1.0f;
    mtl->scale.z = 1.0f;
    mtl->opacity = 1.0f;
    mtl->attribs.alpha_mode = 1;
    mtl->attribs.unknown_2_4 = 1;
    mtl->tex_id = tex_id;
    mtl->attribs.unknown_1_1_2 = 1;
    mtl->attribs.unknown_1_4_8 = 1;
    mtl->attribs.cull_mode = 2;
    mtl->attribs.z_mode = 3;

    memset(&shader_desc, 0, sizeof(NUSHADERMTLDESC));

    shader_desc.tex_id = tex_id;
    shader_desc.byte4 = 0x10;
    shader_desc.flags = 0x1000;
    shader_desc.mask = 0xffffffff;
    shader_desc.byte1 = 1;
    shader_desc.byte2 = 9;
    shader_desc.byte3 = 4;
    shader_desc.value = 1.0f;

    NuMtlSetShaderDescPS(mtl, &shader_desc);
    NuMtlUpdate(font->mtl);

    font->platform_data = (void *)ALIGN(buffer->addr, 0x10);
    buffer->void_ptr = (void *)((ALIGN(buffer->addr, 0x10)) + sizeof(VUFNT_ANDROID));

    platform_font = (VUFNT_ANDROID *)font->platform_data;
    font->x_scale = &platform_font->x_scale;
    font->y_scale = &platform_font->y_scale;
    font->color_abgr = &platform_font->color_abgr;

    font->hdr = NULL;

    return 0;
}
