#pragma once

#include <stddef.h>
#include <stdint.h>

struct charfixup_s {
    char *name;
    int16_t *id;
};

typedef struct charfixup_s CHARFIXUP;