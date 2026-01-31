#pragma once

typedef int nurdpgetvarfn(char *, float *, int *);

#ifdef __cplusplus
extern "C" {
#endif
    float NuRDPF(char *input);
    float NuRDPFVar(char *input, nurdpgetvarfn *get_var_fn);

    int NuRDPI(char *input);
    int NuRDPIVar(char *input, nurdpgetvarfn *get_var_fn);
#ifdef __cplusplus
}
#endif
