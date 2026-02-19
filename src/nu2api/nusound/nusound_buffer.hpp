#pragma once

#include "nu2api/nucore/common.h"

#include "nu2api/nusound/nusound_system.hpp"

class NuSoundBuffer {
    u64 size;
    i32 allocated;
    void *addr;
    void *address;
    u32 flags;
    NuSoundSystem::MemoryDiscipline memory_discipline;

   public:
    void Free();
    bool IsAllocated() const;
    i32 Allocate(u64 size, NuSoundSystem::MemoryDiscipline disc);
};
