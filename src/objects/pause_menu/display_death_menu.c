/*
** EPITECH PROJECT, 2020
** create_pause_menu
** File description:
** create pause menu
*/

#include "rpg.h"

void display_death_menu(main_t *main, death_menu_t *death_menu)
{
    if (main->player->player_status == DEAD) {
        sfRenderWindow_drawRectangleShape(main->win, death_menu->background, NULL);
        sfRenderWindow_drawText(main->win, death_menu->text, NULL);
        sfRenderWindow_drawText(main->win, death_menu->button->text, NULL);
    }
}

void update_death_menu(player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite->sprite);

    sfRectangleShape_setPosition(player->death_menu->background, pos);
    sfText_setPosition(player->death_menu->text,
    (Vec2f){pos.x, pos.y - 100});
    sfText_setPosition(player->death_menu->button->text, (Vec2f)
    {pos.x, pos.y + 80});
}