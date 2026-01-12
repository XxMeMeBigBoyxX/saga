#include "saveload/saveload.h"

#include "nu2api.saga/nuandroid/nuios.h"
#include "nu2api.saga/nucore/nustring.h"
#include "nu2api.saga/numemory/numemory.h"

#include <stdio.h>
#include <string.h>

#include "export.h"

int32_t saveload_status = 0;
int32_t saveload_autosave = 0;
int32_t saveload_savepresent = 0;

int32_t saveload_slotused[6] = {0};
char *saveload_slotcode[6] = {0};

char *slotname(int32_t index) {
    static char name[4096];
    sprintf(name, "SaveGame%d.%s_SavedGame", index, "LEGO Star Wars - The Complete Saga");
    return name;
}

char *slotfolder(int32_t index) {
    static char name[4096];

    char *path = NuIOS_GetDocumentsPath();
    NuStrCpy(name, path);

    int32_t len = strlen(name);

    strcpy(&name[len], "SavedGames");

    return name;
}

char *fullslotname(int32_t index) {
    static char name[4096];

    strcpy(name, slotfolder(index));

    int32_t len = strlen(name);

    strcat(name, "/");
    strcat(name, slotname(index));

    return name;
}

int32_t saveload_getinfo(void) {
    saveload_savepresent = 0;
    int32_t count = 0;

    for (int32_t i = 0; i < 6; i = i + 1) {
        saveload_slotused[i] = 0;
        saveload_slotcode[i] = 0;

        char *path = fullslotname(i);
        FILE *file = fopen(path, "rb");

        if (file != NULL) {
            count = count + 1;
            saveload_slotused[i] = 1;

            fseek(file, -4, 2);
            fread(&saveload_slotcode[i], 4, 1, file);

            saveload_savepresent = 1;

            fclose(file);
        }
    }

    return count;
}

void saveloadInit(void **bufferStart, void *bufferEnd, int32_t, char *prodcode, char *iconname, char *unicodename,
                  int32_t) {
    saveload_getinfo();
    saveload_status = 1;
    saveload_autosave = -1;
}

int32_t saveloadLoadSlot(int32_t slot, void *buffer, size_t size) {
    char *filename = fullslotname(slot);
    FILE *file = fopen(filename, "rb");

    LOG("slot=%d, filename=%s, file=%p", slot, filename, file);

    if (file == NULL) {
        return 0;
    } else {
        SaveLoad buf;

        fread(&buf, 0x2028, 1, file);
        if (buf.offset != 0) {
            fseek(file, buf.offset, 1);
        }
        fread(buffer, size, 1, file);
        fclose(file);

        return 1;
    }
}

typedef short (*hashfn_t)(void);

int32_t SAVESLOTS = 3;

void *memcard_savedata = NULL;
int32_t memcard_savedatasize = 0;
void *memcard_savedatabuffer = NULL;

void *memcard_extra_savedata = NULL;
int32_t memcard_extra_savedatasize = 0;
void *memcard_extra_savedatabuffer = NULL;

hashfn_t memcard_hashfn = NULL;
void *memcard_drawasiconfn = NULL;
int32_t memcard_autosave = 0;

void SaveSystemInitialise(int32_t slots, void *makeSaveHash, void *save, int32_t saveSize, int32_t saveCount,
                          void *drawSaveIcon, void *extradata, int32_t extradataSize) {
    if (extradata == NULL) {
        SAVESLOTS = 6;
        if (slots < 7) {
            SAVESLOTS = slots;
        }
    } else {
        SAVESLOTS = 5;
        if (slots < 6) {
            SAVESLOTS = slots;
        }
    }

    memcard_hashfn = (hashfn_t)makeSaveHash;
    memcard_savedata = save;
    memcard_savedatasize = saveSize;
    memcard_extra_savedata = extradata;
    memcard_extra_savedatasize = extradataSize;

    NuMemory *mem = NuMemoryGet();
    NuMemoryManager *manager = mem->GetThreadMem();

    memcard_savedatabuffer = manager->_BlockAlloc(saveSize + 4, 4, 1, "", 0);
    mem = NuMemoryGet();

    manager = mem->GetThreadMem();

    memcard_extra_savedatabuffer = (void *)manager->_BlockAlloc(extradataSize + 4, 4, 1, "", 0);

    memcard_autosave = saveCount;
    memcard_drawasiconfn = drawSaveIcon;
}

int32_t ChecksumSaveData(void *buffer, int32_t size) {
    uint uVar1;
    int iVar2;
    uint uVar3;
    uint uVar4;
    uint uVar5;
    uint uVar6;
    int *piVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    int iVar11;

    if (size < 0) {
        size = size + 3;
    }
    uVar1 = size >> 2;
    if ((int)uVar1 < 1) {
        iVar2 = 0x5c0999;
    } else {
        iVar2 = 0x5c0999;
        uVar3 = -(((uint)buffer & 0xf) >> 2) & 3;
        if (uVar1 < uVar3) {
            uVar3 = uVar1;
        }
        if (uVar1 < 9) {
            uVar3 = uVar1;
        }
        uVar5 = 0;
        if (uVar3 != 0) {
            do {
                iVar2 = iVar2 + *(int *)((int)buffer + uVar5 * 4);
                uVar5 = uVar5 + 1;
            } while (uVar5 < uVar3);
            if (uVar1 == uVar3) {
                return iVar2;
            }
        }
        uVar6 = uVar1 - uVar3 >> 2;
        if (uVar6 != 0) {
            piVar7 = (int *)((int)buffer + uVar3 * 4);
            uVar4 = 0;
            iVar8 = 0;
            iVar9 = 0;
            iVar10 = 0;
            iVar11 = 0;
            do {
                uVar4 = uVar4 + 1;
                iVar8 = iVar8 + *piVar7;
                iVar9 = iVar9 + piVar7[1];
                iVar10 = iVar10 + piVar7[2];
                iVar11 = iVar11 + piVar7[3];
                piVar7 = piVar7 + 4;
            } while (uVar4 < uVar6);
            uVar5 = uVar5 + uVar6 * 4;
            iVar2 = iVar2 + iVar8 + iVar10 + iVar9 + iVar11;
            if (uVar1 - uVar3 == uVar6 * 4) {
                return iVar2;
            }
        }
        do {
            iVar2 = iVar2 + *(int *)((int)buffer + uVar5 * 4);
            uVar5 = uVar5 + 1;
        } while ((int)uVar5 < (int)uVar1);
    }
    return iVar2;
}

int32_t TriggerExtraDataLoad(void) {
    int32_t iVar1 = saveloadLoadSlot(SAVESLOTS, memcard_extra_savedatabuffer, memcard_extra_savedatasize + 4);

    if (iVar1 != 0) {
        int32_t checksum = *(int32_t *)((size_t)memcard_extra_savedatabuffer + memcard_extra_savedatasize);
        if (ChecksumSaveData(memcard_extra_savedatabuffer, memcard_extra_savedatasize) == checksum) {
            memmove(memcard_extra_savedata, memcard_extra_savedatabuffer, memcard_extra_savedatasize);
            return 1;
        }
    }

    return 0;
}
