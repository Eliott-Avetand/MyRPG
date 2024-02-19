/*
** EPITECH PROJECT, 2021
** player_scaling.c
** File description:
** create the scene
*/

#include "rpg.h"

void update_scaling(player_t *player, int option)
{
    sfVector2f r_scale = sfRectangleShape_getScale(player->hitbox);
    sfVector2f p_scale = sfSprite_getScale(player->sprite->sprite);

    if (option == -1) {
        sfRectangleShape_setScale(player->hitbox,
        (Vec2f){r_scale.x - 0.05, r_scale.y - 0.05});
        sfSprite_setScale(player->sprite->sprite, (Vec2f){p_scale.x - 0.05,
        p_scale.y - 0.05});
    } else {
        sfRectangleShape_setScale(player->hitbox,
        (Vec2f){r_scale.x + 0.05, r_scale.y + 0.05});
        sfSprite_setScale(player->sprite->sprite, (Vec2f){p_scale.x + 0.05,
        p_scale.y + 0.05});
    }
}

void check_floor(scene_t *scene, player_t *player)
{
    sfVector2f p_pos = sfRectangleShape_getPosition(player->hitbox);
    int floor = scene->map->collision[(int)p_pos.y / 32][(int)p_pos.x / 32];

    if (floor != 2 && floor != 3 && floor != 9) {
        if (player->movement->floor > scene->map->
        collision[(int)p_pos.y / 32][(int)p_pos.x / 32]) {
            update_scaling(player, -1);
            player->movement->floor--;
        } else if (player->movement->floor < scene->map->
        collision[(int)p_pos.y / 32][(int)p_pos.x / 32]) {
            update_scaling(player, 1);
            player->movement->floor++;
        }
    }
}