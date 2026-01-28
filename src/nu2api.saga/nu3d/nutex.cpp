#include <pthread.h>
#include <string.h>

#include "nu2api.saga/nu3d/nutex.h"

#include "nu2api.saga/nucore/common.h"

int max_textures;
static NUNATIVETEX **texture_list;
static int *texture_order;
static int gTextureLoadCount;

void NuTexInitEx(VARIPTR *buf, int max_tex_count) {
    max_textures = max_tex_count;

    texture_list = (NUNATIVETEX **)ALIGN(buf->addr, 0x4);
    buf->void_ptr = (void *)(texture_list + max_tex_count);
    memset(texture_list, 0, max_tex_count * sizeof(NUNATIVETEX *));

    texture_order = (int *)ALIGN(buf->addr, 0x4);
    buf->void_ptr = (void *)(texture_order + max_tex_count);
    memset(texture_order, 0, max_tex_count * sizeof(int));

    gTextureLoadCount = 0;
}

pthread_mutex_t criticalSection = PTHREAD_MUTEX_INITIALIZER;

int NuTexCreateNative(NUNATIVETEX *tex, bool is_pvrtc) {
    int tex_id;
    int i;

    if (tex == NULL) {
        return 0;
    }

    pthread_mutex_lock(&criticalSection);

    if (max_textures <= 0) {
        pthread_mutex_unlock(&criticalSection);

        return 0;
    }

    tex_id = 1;
    i = 0;

    while (texture_list[i] != NULL) {
        tex_id++;
        i++;
    }

    texture_list[i] = tex;
    texture_order[i] = gTextureLoadCount++;

    pthread_mutex_unlock(&criticalSection);

    NuTexCreatePS(tex, is_pvrtc);

    return tex_id;
}
