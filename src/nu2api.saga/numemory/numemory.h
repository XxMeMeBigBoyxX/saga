#pragma once

#include "decomp.h"

C_API_START

class NuMemoryManager {};

struct NuMemory {
    NuMemory(void *buffer);
};

NuMemory *NuMemoryGet();

C_API_END