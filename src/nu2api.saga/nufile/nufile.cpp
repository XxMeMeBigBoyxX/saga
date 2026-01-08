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

size_t BinarySearch(int32_t element, int32_t *array, size_t length) {
    size_t end = length - 1;
    size_t start = 0;

    while (1) {
        if (end < start) {
            return -1;
        }

        size_t index = (end + start) / 2;
        if (array[index] == element) {
            return index;
        } else if (array[index] < element) {
            start = index + 1;
        } else {
            end = index - 1;
        }
    }
}

int32_t NuDatFileGetFreeInfo(void) {
    NuThreadCriticalSectionBegin(file_criticalsection);

    int32_t found = -1;
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
