#include "nu2api.saga/numemory/numemory.h"

#include <iostream>
#include <pthread.h>

static NuMemory *g_memory = NULL;

static const char *g_categoryNames[51] = {
    "NONE",          "INITIAL",      "HARDWAREINIT",  "NUFILE",      "NUFONT",         "NUSCENE",       "NURENDER",
    "NUSOUND",       "NUDEBUG",      "CHARS",         "CHARANIMS",   "SPLITSCREEN",    "DYNOTERRAIN",   "DYNODATA",
    "DYNOSYSTEM",    "AI",           "PARTICLE",      "VFX",         "TECH",           "SCRIPT",        "RESOURCE",
    "GAMEFRAMEWORK", "LEVEL",        "CUTSCENE",      "KRAWLIE",     "GAME",           "EDITOR",        "ANIMATION",
    "MANAGERS",      "ENGINE",       "G_LEGOSETS",    "L_LEGOSETS",  "TECH_GIN",       "TECH_GIZMO",    "TECH_GADGET",
    "TECH_FLOW",     "TECH_ANIM",    "TECH_LIGHTING", "TECH_AI",     "TECH_AI_EDMESH", "TECH_AI_GRAPH", "TECH_CAMERA",
    "TECH_AUDIO",    "TECH_PICKUPS", "TECH_KRAWLIE",  "TECH_STREAM", "TECH_GRASS",     "TECH_MAINLED",  "TECH_FIXUP",
    "RUNTIME",       "TTSHARED",
};

NuMemory::NuMemory(void *buffer) {
}

static NuMemory g_memoryBuffer = {0};

NuMemory *NuMemoryGet() {
    static char nuMemoryHugeArray[65000];

    if (g_memory != NULL) {
        return g_memory;
    }

    new (&g_memoryBuffer) NuMemory{(void *)nuMemoryHugeArray};

    g_memory = &g_memoryBuffer;

    return &g_memoryBuffer;
}
