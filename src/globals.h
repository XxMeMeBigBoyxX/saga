#pragma once

#include "decomp.h"
#include <stdint.h>

C_API_START

extern int32_t PAL;
extern float FRAMETIME;
extern float DEFAULTFPS;
extern float DEFAULTFRAMETIME;
extern float MAXFRAMETIME;

extern int32_t SUPERBUFFERSIZE;
extern void *permbuffer_base;
extern void *original_permbuffer_base;
extern void *superbuffer_end;
extern void *permbuffer_ptr;
extern void *permbuffer_end;

extern char prodcode[16];
extern char *iconname;
extern char unicodename[64];

C_API_END