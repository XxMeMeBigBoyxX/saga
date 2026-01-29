#ifndef NU2API_SAGA_NU3D_NURENDERDEVICE_H
#define NU2API_SAGA_NU3D_NURENDERDEVICE_H

#ifdef __cplusplus

class NuRenderDevice {
    public:
        int BeginCriticalSection(const char* file, int line);
        void EndCriticalSection(const char* file, int line);
};

extern NuRenderDevice g_renderDevice;

extern "C" {
#endif

void BeginCriticalSectionGL(const char* file, int line);
void EndCriticalSectionGL(const char* file, int line);

#ifdef __cplusplus
}
#endif

#endif // NU2API_SAGA_NU3D_NURENDERDEVICE_H