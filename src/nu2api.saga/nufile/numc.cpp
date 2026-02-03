#include "nu2api.saga/nufile/nufile.h"

int NuMcOpen(int port, int slot, char *filepath, int mode, int async) {
    return 0;
}

i32 NuMcClose(int fd, int async) {
    return 0;
}

int NuMcSeek(int fd, int offset, NUFILESEEK mode, int async) {
    return 0;
}

int NuMcOpenSize(int fd) {
    return 0;
}

int NuMcRead(int fd, void *buf, int size, int async) {
    return 0;
}

int NuMcWrite(int fd, void *data, int size, int async) {
    return 0;
}

int NuMcFileOpenSize(NUFILE file) {
    file -= 0x1000;

    return NuMcOpenSize(file);
}
