#include "globals.h"

int32_t PAL = 0;
float FRAMETIME = 0;
float DEFAULTFPS = 0;
float DEFAULTFRAMETIME = 0;
float MAXFRAMETIME = 0;

int32_t SUPERBUFFERSIZE = 0x2EB8EEB;
void *permbuffer_base = NULL;
void *original_permbuffer_base = NULL;
void *superbuffer_end = NULL;
void *permbuffer_ptr = NULL;
void *permbuffer_end = NULL;

char prodcode[16] = {0};
char *iconname = "lego.ico";
char unicodename[64] = "LEGO Star Wars Saga";

GAMESAVE_s Game = {0};