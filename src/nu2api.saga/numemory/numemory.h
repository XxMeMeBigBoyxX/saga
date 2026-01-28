#pragma once

#include <stdint.h>

#ifdef __cplusplus

class NuMemoryManager {
  public:
    enum ErrorCode {};

    class IErrorHandler {
      public:
        virtual void HandleError(NuMemoryManager *manager, ErrorCode code, const char *msg);
        virtual int OpenDump(NuMemoryManager *manager, const char *filename, unsigned int &id);
        virtual void CloseDump(NuMemoryManager *manager, unsigned int id);
        virtual void Dump(NuMemoryManager *manager, unsigned int id, const char *msg);
    };

  private:
    static unsigned int m_headerSize;

    const char **categoryNames;
    unsigned int categoryCount;
    bool isZombie;
    uint32_t idx;

  public:
    static void SetFlags(unsigned int flags);

    void *_BlockAlloc(uint32_t size, uint32_t param_2, uint32_t param_3, const char *name, uint16_t param_5);

  private:
    void *_TryBlockAlloc(uint32_t size, uint32_t param_2, uint32_t param_3, const char *name, uint16_t param_5);
    void ____WE_HAVE_RUN_OUT_OF_MEMORY_____(uint32_t size, const char *name);

    unsigned int CalculateBlockSize(unsigned int size);
    void ValidateAllocAlignment(unsigned int alignment);
    void ValidateAllocSize(unsigned int size);
};

struct NuMemory {
  private:
    class MemErrorHandler : NuMemoryManager::IErrorHandler {};

    MemErrorHandler *errorHandler;
    int32_t tlsIndex = -1;
    NuMemoryManager *memoryManager = NULL;

  public:
    NuMemory(void **buf);
    NuMemoryManager *GetThreadMem();

  private:
    void InitalizeThreadLocalStorage();
};

NuMemory *NuMemoryGet();

#endif
