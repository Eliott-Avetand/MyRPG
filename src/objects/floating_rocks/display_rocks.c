/*
** EPITECH PROJECT, 2021
** create_collision_rect
** File description:
** create_collision_rect
*/

#include "rpg.h"

void rocks_animation(rocks_t *rocks)
{
    sfTime time = sfClock_getElapsedTime(rocks->clock);
    sfIntRect rect = sfSprite_getTextureRect(rocks->sprite->sprite);

    if (sfTime_asMilliseconds(time) > 300) {
        if (rect.left < 64)
            rect.left += 32;
        else
            rect.left = 0;
        sfSprite_setTextureRect(rocks->sprite->sprite, rect);
        sfClock_restart(rocks->clock);
    }
}

void display_rocks(scene_t *scene, main_t *main)
{
    for (int i = 0; scene->rocks[i] != NULL; i++) {
        if (scene->rocks[i]->see_rocks == YES) {
            sfRenderWindow_drawSprite(main->win,
            scene->rocks[i]->sprite->sprite, NULL);
        }
        if (main->game_status != PAUSE)
            rocks_animation(scene->rocks[i]);
    }
    check_all_crystals(main);
}