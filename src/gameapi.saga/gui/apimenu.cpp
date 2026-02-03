#include "gameapi.saga/gui/apimenu.h"

#include <string.h>

#include "decomp.h"

MENU GameMenu[10];
int MenuSFX = -1;
int GameMenuLevel = -1;
MENUFNINFO GameMenuInfo[33] = {1}; // TODO: initialize with proper values

void MenuReset(void) {
    memset(GameMenu, 0, sizeof(GameMenu));
    GameMenu[0].menu = -1;
    MenuSFX = -1;
    GameMenuLevel = 0;
}

void APIMenuDrawMemCardSlots(MENU* menu, float time) {
    UNIMPLEMENTED();
}

void(*drawslotsfn)(MENU*, float) = APIMenuDrawMemCardSlots;

void MenuInitialiseEx(MENUFNINFO* menu_infos, int menu_infos_count, int language_count, void(*draw_save_slots_fn)(MENU*, float), int fade_enabled, int shadow_enabled) {
    UNIMPLEMENTED();
}

void MenuInitialise(MENUFNINFO* menu_infos, int menu_infos_count, int language_count, void(*draw_save_slots_fn)(MENU*, float), int fade_enabled, int shadow_enabled) {
    MenuInitialiseEx(menu_infos, menu_infos_count, language_count, NULL, fade_enabled, shadow_enabled);

    if (draw_save_slots_fn != NULL) {
        drawslotsfn = draw_save_slots_fn;
    }
}
