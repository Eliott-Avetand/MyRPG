/*
** EPITECH PROJECT, 2020
** portal_callback.c
** File description:
** callback of portals
*/

#include "rpg.h"

void go_ashland(main_t *main)
{
    if (main->actual_scene != ASHLAND) {
        main->actual_scene = ASHLAND;
        sfSprite_setPosition(main->player->sprite->sprite,
        main->scenes[HUB]->portals[0]->tp_position);
        sfRectangleShape_setPosition(main->player->hitbox,
        main->scenes[HUB]->portals[0]->tp_position);
        stop_all_sounds(main);
        sfSound_play(main->scenes[ASHLAND]->music[0]->sound);
        update_view(main);
    } else {
        main->actual_scene = HUB;
        stop_all_sounds(main);
        sfSound_play(main->scenes[HUB]->music[0]->sound);
        sfSprite_setPosition(main->player->sprite->sprite,
        main->scenes[ASHLAND]->portals[0]->tp_position);
        sfRectangleShape_setPosition(main->player->hitbox,
        main->scenes[ASHLAND]->portals[0]->tp_position);
        update_view(main);
    }
}

void go_jungle(main_t *main)
{
    int idx = (main->actual_scene != JUNGLE) ? 1 : 0;
    int tp_scene = (main->actual_scene != JUNGLE) ? HUB : JUNGLE;

    main->actual_scene = (main->actual_scene != JUNGLE) ? JUNGLE : HUB;
    main->player->movement->direction = RIGHT;
    sfSprite_setTextureRect(main->player->sprite->sprite,
    (sfIntRect){0, RIGHT, 64, 64});
    sfSprite_setPosition(main->player->sprite->sprite,
    main->scenes[tp_scene]->portals[idx]->tp_position);
    sfRectangleShape_setPosition(main->player->hitbox,
    main->scenes[tp_scene]->portals[idx]->tp_position);
    stop_all_sounds(main);
    sfSound_play(main->scenes[main->actual_scene]->music[0]->sound);
    update_view(main);
}

void go_boss(main_t *main)
{
    if (main->actual_scene != ATLANTIS) {
        main->actual_scene = ATLANTIS;
        sfSprite_setPosition(main->player->sprite->sprite,
        main->scenes[HUB]->portals[2]->tp_position);
        sfRectangleShape_setPosition(main->player->hitbox,
        main->scenes[HUB]->portals[2]->tp_position);
        stop_all_sounds(main);
        sfSound_play(main->scenes[ATLANTIS]->music[0]->sound);
        sfSound_setVolume(main->scenes[ATLANTIS]->music[0]->sound, 10);
        update_view(main);
    } else {
        main->actual_scene = HUB;
        stop_all_sounds(main);
        sfSound_play(main->scenes[HUB]->music[0]->sound);
        sfSprite_setPosition(main->player->sprite->sprite,
        main->scenes[ATLANTIS]->portals[0]->tp_position);
        sfRectangleShape_setPosition(main->player->hitbox,
        main->scenes[ATLANTIS]->portals[0]->tp_position);
        update_view(main);
    }
}

void check_portals(main_t *main)
{
    sfIntRect rect;
    sfVector2f pos = sfSprite_getPosition(main->player->sprite->sprite);

    for (int i = 0; i < 3; i++) {
        rect = sfSprite_getTextureRect(main->scenes[HUB]->
        portals[i]->portal_sprite->sprite);
        if (sfIntRect_contains(&rect, pos.x, pos.y) == sfTrue)
            main->scenes[HUB]->portals[i]->go_in(main);
    }
}