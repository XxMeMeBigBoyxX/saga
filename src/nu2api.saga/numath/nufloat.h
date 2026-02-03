#pragma once

#include <math.h>

#include "decomp.h"

// /// @brief The epsilon for f32 equivalence in NuEquiv
// extern f32 fetol;

#ifdef __cplusplus
extern "C" {
#endif
    /// @brief Compute the absolute value of a f32
    /// @details Computes the absolute value of the f32 f and returns the result.
    /// @param f The f32 to compute the absolute value of
    /// @return The absolute value of the f32
    static f32 NuFabs(f32 f) {
        return fabsf(f);
    }

    /// @brief Compute the negative absolute value of a f32
    /// @details Computes the negative absolute value of the f32 f and returns the result.
    /// @param f The f32 to compute the negative absolute value of
    /// @return The negative absolute value of the f32
    f32 NuFnabs(f32 f);

    /// @brief Compute the negation of a f32
    /// @details Computes the negation of the f32 v and returns the result.
    /// @param v The f32 to compute the negation of
    /// @return The negation of the f32 v
    f32 NuFneg(f32 v);

    /// @brief Compute the sign of a f32
    /// @details Computes the sign of the f32 v and returns the result as a unit f32.
    /// @param v The f32 to compute the sign of
    /// @return The sign of the f32 v as a unit f32 (-1.0f or 1.0f)
    f32 NuFsign(f32 f);

    // /// @brief Set the epsilon for f32 equivalence
    // /// @details Sets the epsilon for f32 equivalence to the value of the f32 e.
    // /// @param e The epsilon to set
    // /// @return void
    // void NuEquivTollerance(f32 f);

    // /// @brief Compute if two f32s are equivalent
    // /// @details Computes if the f32s f1 and f2 are equivalent within a small epsilon and returns the result.
    // /// @param f1 The first f32 to compare
    // /// @param f2 The second f32 to compare
    // /// @return 1 if the f32s are equivalent, 0 otherwise
    // int NuEquiv(f32 f1, f32 f2);

    /// @brief Compute the square root of a f32
    /// @details Computes the square root of the f32 f and returns the result.
    /// @param f The f32 to compute the square root of
    /// @return The square root of the f32
    f32 NuFsqrt(f32 f);

    /// @brief Compute the division of two f32s
    /// @details Computes the division of the f32 a divided by b and returns the result. Returns 0 if b is 0.
    /// @param a The f32 to divide
    /// @param b The f32 to divide by
    /// @return The division of the f32 a and b
    static f32 NuFdiv(f32 a, f32 b) {
        if (a == 0.0f || b == 0.0f) {
            return 0.0f;
        }

        return a / b;
    }

    f32 NuFmod(f32 a, f32 b);
#ifdef __cplusplus
}
#endif
