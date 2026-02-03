#pragma once

#include "decomp.h"

typedef int nurdpgetvarfn(char *, f32 *, int *);

#ifdef __cplusplus
extern "C" {
#endif
    f32 NuRDPF(char *input);
    f32 NuRDPFVar(char *input, nurdpgetvarfn *get_var_fn);

    int NuRDPI(char *input);
    int NuRDPIVar(char *input, nurdpgetvarfn *get_var_fn);
#ifdef __cplusplus
}
#endif
