#include "nu2api.saga/nucore/nucore.hpp"
#include "nu2api.saga/nucore/bgproc.h"

NuThreadBase *g_bgProcThread;

int bgProcIsBgThread(void) {
    return NuCore::m_threadManager->GetCurrentThread() == g_bgProcThread;
}
