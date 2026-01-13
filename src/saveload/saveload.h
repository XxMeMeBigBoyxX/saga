#pragma once

#include <stdint.h>

#include "decomp.h"

C_API_START

void saveloadInit(void **bufferStart, void *bufferEnd, int32_t, char *prodcode, char *iconname, char *unicodename,
                  int32_t);

int32_t saveloadLoadSlot(int32_t slot, void *buffer, size_t size);

int32_t TriggerExtraDataLoad(void);

void SaveSystemInitialise(int32_t slots, void *makeSaveHash, void *save, int32_t saveSize, int32_t saveCount,
                          void *drawSaveIcon, void *extradata, int32_t extradataSize);

int32_t ChecksumSaveData(void *buffer, int32_t size);

void saveloadASSave(int32_t slot, void *buffer, int32_t size, uint32_t hash);
void saveloadASLoad(int32_t slot, void *buffer, int32_t size);

C_API_END