/*
** EPITECH PROJECT, 2020
** redirect_events
** File description:
** get the event and redirect them on differents functions
*/

#include "rpg.h"

void go_in_cave(main_t *main)
{
    if (main->actual_scene == ASHLAND) {
        main->actual_scene = CAVE;
        sfSprite_setPosition(main->player->sprite->sprite, (Vec2f){942, 1680});
        sfRectangleShape_setPosition(main->player->hitbox, (Vec2f){942, 1680});
        update_view(main);
    } else {
        main->actual_scene = ASHLAND;
        sfSprite_setPosition(main->player->sprite->sprite, (Vec2f){1180, 1210});
        sfRectangleShape_setPosition(main->player->hitbox, (Vec2f){1180, 1210});
        update_view(main);
    }
}

void check_tp_in_cave(main_t *main)
{
    sfVector2f p_pos = sfRectangleShape_getPosition(main->player->hitbox);

    if (main->actual_scene == ASHLAND) {
        if (main->scenes[main->actual_scene]->map->
        collision[(int)p_pos.y / 32][(int)p_pos.x / 32] == 3 &&
        main->player->movement->direction == FORWARD)
            go_in_cave(main);
    } else if (main->actual_scene == CAVE) {
        if (main->scenes[main->actual_scene]->map->
            collision[(int)p_pos.y / 32][(int)p_pos.x / 32] == 3 &&
            main->player->movement->direction == BACK)
                go_in_cave(main);
    }
}