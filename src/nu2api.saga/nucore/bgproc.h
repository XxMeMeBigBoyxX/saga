#pragma once

#include "nu2api.saga/nucore/nuthread.h"

typedef struct bgprocinfo_s {
} BGPROCINFO;

extern NuThreadBase *g_bgProcThread;

int bgProcIsBgThread(void);
