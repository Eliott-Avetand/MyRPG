/*
** EPITECH PROJECT, 2020
** pause_menu_handler
** File description:
** create pause menu
*/

#include "rpg.h"

void handle_mouse_click_pause(pause_menu_t *pause_menu, sfVector2f pos)
{
    sfColor magenta = sfColor_fromRGB(124, 0, 73);

    for (int i = 0; pause_menu->buttons[i] != NULL; i++) {
        if (is_on_btn(pause_menu->buttons[i], pos.x, pos.y) == 1) {
            sfText_setColor(pause_menu->buttons[i]->text, magenta);
            sfText_setOutlineColor(pause_menu->buttons[i]->text, sfWhite);
            sfText_setOutlineThickness(pause_menu->buttons[i]->text, 2);
        } else {
            sfText_setColor(pause_menu->buttons[i]->text, sfWhite);
            sfText_setOutlineThickness(pause_menu->buttons[i]->text, 0);
        }
    }
}

void handle_mouse_released_pause(pause_menu_t *pause_menu, main_t *main,
sfVector2f pos)
{
    for (int i = 0; pause_menu->buttons[i] != NULL; i++) {
        if (is_on_btn(pause_menu->buttons[i], pos.x, pos.y) == 1 &&
        pause_menu->buttons[i]->click_fn != NULL) {
            sfSound_play(main->scenes[MAIN_MENU]->music[1]->sound);
            pause_menu->buttons[i]->click_fn(main);
        }
    }
}

void handle_mouse_move_pause(pause_menu_t *pause_menu, sfVector2f pos)
{
    sfColor magenta = sfColor_fromRGB(124, 0, 73);

    for (int i = 0; pause_menu->buttons[i] != NULL; i++) {
        if (is_on_btn(pause_menu->buttons[i], pos.x, pos.y) == 1) {
            sfText_setOutlineColor(pause_menu->buttons[i]->text, magenta);
            sfText_setOutlineThickness(pause_menu->buttons[i]->text, 2);
        } else {
            sfText_setColor(pause_menu->buttons[i]->text, sfWhite);
            sfText_setOutlineThickness(pause_menu->buttons[i]->text, 0);
        }
    }
}