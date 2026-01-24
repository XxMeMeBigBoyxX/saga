#pragma once

#include "decomp.h"

#ifdef __cplusplus

class NuMemoryManager {
  private:
    int32_t m_headerSize;
    uint32_t field12_0xc;

  public:
    void *_BlockAlloc(uint32_t size, uint32_t param_2, uint32_t param_3, const char *name, uint16_t param_5);

  private:
    void *_TryBlockAlloc(uint32_t size, uint32_t param_2, uint32_t param_3, const char *name, uint16_t param_5);
    void ____WE_HAVE_RUN_OUT_OF_MEMORY_____(uint32_t size, const char *name);

    int32_t CalculateBlockSize(uint32_t size);
};

struct NuMemory {
  private:
    int32_t tlsIndex = -1;
    NuMemoryManager *memoryManager = NULL;

  public:
    NuMemory(void **buffer);
    NuMemoryManager *GetThreadMem();

  private:
    void InitalizeThreadLocalStorage();
};

NuMemory *NuMemoryGet();

#endif
