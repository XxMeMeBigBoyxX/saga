#include "nu2api.saga/nucore/nunew.hpp"

#include "globals.h"
#include "nu2api.saga/numemory/numemory.h"

void *operator new(std::size_t size) {
    if (g_disallowGlobalNew != false) {
        g_disallowGlobalNew = false;
    }

    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, 16, 1, "_new", 0);
}
void *operator new(std::size_t size, u32 alignment) {
    if (g_disallowGlobalNew != false) {
        g_disallowGlobalNew = false;
    }

    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, alignment, 1, "_new", 0);
}
void *operator new(std::size_t size, const std::nothrow_t &) noexcept {
    if (g_disallowGlobalNew != false) {
        g_disallowGlobalNew = false;
    }

    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, 16, 1, "_new", 0);
}
void *operator new(std::size_t size, u32 alignment, const std::nothrow_t &) noexcept {
    if (g_disallowGlobalNew != false) {
        g_disallowGlobalNew = false;
    }

    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, alignment, 1, "_new", 0);
}

void *operator new[](std::size_t size) {
    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, 16, 1, "_new", 0);
}
void *operator new[](std::size_t size, u32 alignment) {
    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, alignment, 1, "_new", 0);
}
void *operator new[](std::size_t size, const std::nothrow_t &) noexcept {
    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, 16, 1, "_new", 0);
}
void *operator new[](std::size_t size, u32 alignment, const std::nothrow_t &) noexcept {
    return NuMemoryGet()->GetThreadMem()->_BlockAlloc(size, alignment, 1, "_new", 0);
}

void operator delete(void *ptr) noexcept {
    NuMemoryGet()->GetThreadMem()->BlockFree(ptr, 0);
}
void operator delete(void *ptr, const std::nothrow_t &) noexcept {
    NuMemoryGet()->GetThreadMem()->BlockFree(ptr, 0);
}
void operator delete[](void *ptr) noexcept {
    NuMemoryGet()->GetThreadMem()->BlockFree(ptr, 2);
}
void operator delete[](void *ptr, const std::nothrow_t &) noexcept {
    NuMemoryGet()->GetThreadMem()->BlockFree(ptr, 2);
}
