/*
** EPITECH PROJECT, 2020
** create_pause_menu
** File description:
** create pause menu
*/

#include "rpg.h"

void destroy_pause_menu(pause_menu_t *pause_menu)
{
    sfRectangleShape_destroy(pause_menu->background);
    for (int i = 0; i < 5; i++) {
        if (i < 4)
            sfText_destroy(pause_menu->text[i]);
        sfText_destroy(pause_menu->buttons[i]->text);
        free(pause_menu->buttons[i]);
    }
    sfFont_destroy(pause_menu->font);
    free(pause_menu);
}

void back_to_game(main_t *main)
{
    if (main->game_status != IN_GAME)
        main->game_status = IN_GAME;
    else
        main->game_status = PAUSE;
}

void pause_menu_handler(main_t *main)
{
    sfVector2i pixelpos = sfMouse_getPositionRenderWindow(main->win);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(main->win,
    pixelpos, main->camera);

    if (main->e.type == sfEvtKeyPressed) {
        if (main->e.key.code == sfKeyEscape)
            back_to_game(main);
    }
    if (main->e.type == 9 && main->e.mouseButton.button == 0)
        handle_mouse_click_pause(main->player->pause_menu, mouse_pos);
    if (main->e.type == 10 && main->e.mouseButton.button == 0)
        handle_mouse_released_pause(main->player->pause_menu, main, mouse_pos);
    if (main->e.type == sfEvtMouseMoved)
        handle_mouse_move_pause(main->player->pause_menu, mouse_pos);
}

int create_pause_buttons(pause_menu_t *pause_menu)
{
    char *buttons_settings[5] = {B_PAUSE_VOLUME, B_PAUSE_L_ARROW,
    B_PAUSE_R_ARROW, B_PAUSE_BACK, B_PAUSE_GO_MENU};
    void (*callbacks[5])(main_t *main) = {active_sounds, decrease_audio,
    increase_audio, back_to_game, goto_main_menu};
    sfColor bg_color = sfBlack;

    pause_menu->background = sfRectangleShape_create();
    bg_color.a = 160;
    sfRectangleShape_setFillColor(pause_menu->background, bg_color);
    sfRectangleShape_setSize(pause_menu->background, (sfVector2f){720, 480});
    sfRectangleShape_setOrigin(pause_menu->background, (sfVector2f){360, 240});
    for (int i = 0; i < 5; i++) {
        pause_menu->buttons[i] = create_button(pause_menu->font,
        buttons_settings[i], callbacks[i]);
        pause_menu->buttons[i + 1] = NULL;
        if (!pause_menu->buttons[i])
            return EXIT_ERROR;
    }
    return 0;
}

pause_menu_t *create_menu_pause(void)
{
    pause_menu_t *pause_menu = malloc(sizeof(pause_menu_t));
    char *text_settings[4] = {T_PAUSE_SOUNDS, T_PAUSE_VOLUME, T_PAUSE_NBR_VOL,
    T_PAUSE_TITLE};

    if (!pause_menu)
        return NULL;
    pause_menu->font = sfFont_createFromFile(FONT);
    if (!pause_menu->font)
        return NULL;
    for (int i = 0; i < 4; i++) {
        pause_menu->text[i] = create_text(pause_menu->font, text_settings[i]);
        if (!pause_menu->text[i])
            return NULL;
        pause_menu->text[i + 1] = NULL;
    }
    create_pause_buttons(pause_menu);
    return pause_menu;
}