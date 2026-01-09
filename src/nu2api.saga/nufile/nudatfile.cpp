#include "nu2api.saga/nufile/nufile.h"
#include "nu2api.saga/nuthread/nuthread.h"

#include "decomp.h"

static int32_t NameToHash(char *name) {
    int32_t hash = 0x811c9dc5;
    int32_t prime = 0x199933;
    char *ptr = name;

    while (*++ptr != '\0') {
        hash = prime * (hash ^ (int32_t)*ptr);
    }

    return hash;
}

size_t BinarySearch(uint32_t element, uint32_t *array, size_t length) {
    size_t start = 0;
    size_t end = length - 1;

    while (end >= start) {
        size_t index = (start + end) / 2;
        if (array[index] == element) {
            return index;
        } else if (array[index] < element) {
            start = index + 1;
        } else {
            end = index - 1;
        }
    }

    return -1;
}

int32_t NuDatFileGetFreeInfo(void) {
    int32_t found = -1;

    NuThreadCriticalSectionBegin(file_criticalsection);

    for (int32_t i = 0; i < 20; i++) {
        if (dat_file_infos[i].used == 0) {
            dat_file_infos[i].used = 1;
            found = i;
            break;
        }
    }

    NuThreadCriticalSectionEnd(file_criticalsection);

    return found;
}