#include "nu2api.saga/nu3d/nutex.h"

#ifdef __cplusplus
extern "C" {
#endif
    extern int g_currentTexUnit;

    void NuTexSetTextureWithStagePS(NUNATIVETEX *tex, GLuint stage);
#ifdef __cplusplus
}
#endif

GLuint NuIOS_CreateGLTexFromFile(const char *filename);
GLuint NuIOS_CreateGLTexFromPlatformInMemory(void *data, int *width, int *height, bool is_pvrtc);
