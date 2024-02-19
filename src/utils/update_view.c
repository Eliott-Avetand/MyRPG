/*
** EPITECH PROJECT, 2020
** my_perror.c
** File description:
** Print errors
*/

#include "rpg.h"

void update_view(main_t *main)
{
    sfVector2f pos = sfSprite_getPosition(main->player->sprite->sprite);

    sfView_setCenter(main->camera, pos);
    sfRenderWindow_setView(main->win, main->camera);
}