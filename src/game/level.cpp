#include "game/level.h"

#include "globals.h"
#include "nu2api.saga/nucore/nustring.h"

void Level_SetDefaults(LEVELDATA *level) {
    level->field51_0xe4 = 0x400100;
    level->field52_0xe8 = 0x1000040;
    level->field53_0xec = 0x800080;
    level->field54_0xf0 = 0x100080;
    level->field55_0xf4 = 10;
    level->field56_0xf5 = 8;
    level->field57_0xf6 = 10;
    level->field58_0xf7 = 10;
    level->field59_0xf8 = 10;
    level->field60_0xf9 = 10;
    level->field61_0xfa = 10;
    level->max_obstacles = 32;
    level->field63_0xfc = 0x10;
    level->field64_0xfd = 0x40;
    level->field65_0xfe = 4;
    level->field66_0xff = 8;
    level->field67_0x100 = 2;
    level->field68_0x101 = 0x20;
    level->field69_0x102 = 5;
    level->field70_0x103 = 10;
    level->field71_0x104 = 0x20;
    level->field72_0x105 = 0x60;
    level->field73_0x106 = 5;
    level->field74_0x107 = 5;
    level->field75_0x108 = 8;
    level->field76_0x109 = 2;
    level->field77_0x10a = 0x20;
    level->field78_0x10b = 0x10;
    level->field79_0x10c = 8;
    level->field80_0x10d = 0x10;
    level->field81_0x10e = 4;
    level->field82_0x10f = 8;
    level->field83_0x110 = 2;
    level->field84_0x111 = 0x28;
    level->field97_0x128 = 0x44000000;
    level->field96_0x124 = 0x40400000;
    level->field85_0x112 = 0x20;
    level->max_bombgens = 8;
    level->field87_0x114 = 5;
    level->field88_0x115 = 10;
}

// this function chooses the wrong registers for some reason???
LEVELDATA *Level_FindByName(char *name, int *indexDest) {
    for (int i = 0; i < LEVELCOUNT; i++) {
        if (NuStrICmp(LDataList[i].name, name) == 0) {
            if (indexDest != NULL) {
                *indexDest = i;
            }

            return &LDataList[i];
        }
    }

    if (indexDest != NULL) {
        *indexDest = -1;
    }

    return NULL;
}

void Level_Draw(WORLDINFO *world) {
    void (*drawFn)(WORLDINFO *) = (void (*)(WORLDINFO *))world->current_level->drawFn;
    if (drawFn != NULL) {
        drawFn(world);
    }
}