#pragma once

#ifndef _NEW
#define _NEW // NOLINT

#include "nu2api.saga/nucore/common.h"
#include <cstddef>

namespace std {
    struct nothrow_t {};
    extern const nothrow_t nothrow;
} // namespace std

void *operator new(std::size_t size);
void *operator new(std::size_t size, u32 alignment);
void *operator new(std::size_t size, const std::nothrow_t &) noexcept;
void *operator new(std::size_t size, u32 alignment, const std::nothrow_t &) noexcept;

void *operator new[](std::size_t size);
void *operator new[](std::size_t size, u32 alignment);
void *operator new[](std::size_t size, const std::nothrow_t &) noexcept;
void *operator new[](std::size_t size, u32 alignment, const std::nothrow_t &) noexcept;

void operator delete(void *ptr) noexcept;
void operator delete(void *ptr, const std::nothrow_t &) noexcept;
void operator delete[](void *ptr) noexcept;
void operator delete[](void *ptr, const std::nothrow_t &) noexcept;

inline void *operator new(std::size_t, void *p) {
    return p;
}
inline void *operator new[](std::size_t, void *p) {
    return p;
}
inline void operator delete(void *, void *) {
}
inline void operator delete[](void *, void *) {
}

#endif
