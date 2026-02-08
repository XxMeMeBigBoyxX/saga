#pragma once

#include "nu2api.saga/nuthread/nuthread.h"

#include <cstddef>

class NuApplicationState {
  private:
    void *field0_0x0;

  public:
    NuApplicationState();
};

class NuCore {
  public:
    static NuThreadManager *m_threadManager;
    static NuApplicationState *m_applicationState;

    static void Initialize();
    static NuApplicationState *GetApplicationState();
};
