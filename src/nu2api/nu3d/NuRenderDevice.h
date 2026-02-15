#pragma once

#ifdef __cplusplus

class NuRenderDevice {
  public:
    void SetThisTreadAsRender();
    int BeginCriticalSection(const char *file, int line);
    void EndCriticalSection(const char *file, int line);
    void SwapBuffers();
};

extern NuRenderDevice g_renderDevice;

extern "C" {
#endif
    void NuRenderSetThisTreadAsRender(void);
    void BeginCriticalSectionGL(const char *file, int line);
    void EndCriticalSectionGL(const char *file, int line);
    void NuRenderDeviceSwapBuffers(void);
#ifdef __cplusplus
}
#endif
