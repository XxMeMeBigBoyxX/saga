#pragma once

#include <GLES2/gl2.h>

typedef struct nunativetex_ps_s {
    GLuint gl_tex;
} NUNATIVETEX_PS;

GLuint NuIOS_CreateGLTexFromPlatformInMemory(void *data, int *width, int *height, bool is_pvrtc);
