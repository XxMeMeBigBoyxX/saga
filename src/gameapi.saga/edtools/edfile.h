#include "decomp.h"

#include "nu2api.saga/nufile/nufile.h"

C_API_START

int EdFileOpen(char *filepath, NUFILEMODE mode);
int EdFileClose();
void EdFileSetMedia(int media);
void EdFileSetPakFile(void *pak);

void EdFileRead(void *buf, int len);
char EdFileReadChar();
float EdFileReadFloat();
int EdFileReadInt();
short EdFileReadShort();

void EdFileWrite(void *data, int len);

void EdFileSwapEndianess16(void *data);
void EdFileSwapEndianess32(void *data);

C_API_END
