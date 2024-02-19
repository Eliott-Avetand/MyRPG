/*
** EPITECH PROJECT, 2020
** display_pause_menu.c
** File description:
** create pause menu
*/

#include "rpg.h"

void update_pause_menu(pause_menu_t *pause_menu, main_t *main)
{
    sfVector2f pos = sfSprite_getPosition(main->player->sprite->sprite);
    sfVector2f text_pos[4] = {{pos.x - 150, pos.y - 60}, {pos.x - 150, pos.y + 40},
    {pos.x + 105, pos.y + 40}, {pos.x, pos.y - 200}};
    sfVector2f button_pos[5] = {{pos.x + 100, pos.y - 60}, {pos.x + 55, pos.y}, {pos.x + 150, pos.y},
    {pos.x - 240, pos.y + 210}, {pos.x + 260, pos.y + 210}};

    sfRectangleShape_setPosition(pause_menu->background, pos);
    for (int i = 0; i < 5; i++) {
        if (i < 4)
            sfText_setPosition(pause_menu->text[i], text_pos[i]);
        sfText_setPosition(pause_menu->buttons[i]->text, button_pos[i]);
    }
}

void display_pause_menu(pause_menu_t *pause_menu, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, pause_menu->background, NULL);
    for (int i = 0; pause_menu->buttons[i] != NULL; i++)
        sfRenderWindow_drawText(win, pause_menu->buttons[i]->text, NULL);
    for (int i = 0; pause_menu->text[i] != NULL; i++)
        sfRenderWindow_drawText(win, pause_menu->text[i], NULL);
}