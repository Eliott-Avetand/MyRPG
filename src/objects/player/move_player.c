/*
** EPITECH PROJECT, 2021
** create_player.c
** File description:
** create the scene
*/

#include "rpg.h"

void move_camera(main_t *main, Vec2f offset)
{
    sfView_move(main->camera, offset);
    sfRenderWindow_setView(main->win, main->camera);
}

void move_player(main_t *main, scene_t *scene, int i)
{
    Vec2f offset[4] = {{0, -8}, {0, 8}, {-8, 0}, {8, 0}};
    sfFloatRect bounds = rect_getGlobalBounds(main->player->hitbox);

    if (is_colliding(bounds, offset[i], scene->map) == 1)
        return;
    sfSprite_move(main->player->sprite->sprite, offset[i]);
    sfRectangleShape_move(main->player->hitbox, offset[i]);
    move_camera(main, offset[i]);
}

void player_event(main_t *main)
{
    if (main->e.key.code == sfKeySpace &&
    main->player->movement->is_moving != ATTACK &&
    main->player->movement->attack_status != WAIT) {
        main->player->movement->is_moving = ATTACK;
        update_attack_box(main->player, main);
        sfClock_restart(main->player->movement->clock);
        sfSound_play(main->player->player_sounds->sword_sounds->sound);
    }
    if (main->e.key.code == sfKeyEscape) {
        update_pause_menu(main->player->pause_menu, main);
        back_to_game(main);
    }
}

void handle_player_movement(main_t *main)
{
    sfKeyCode movekey[4] = {sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    int direction[4] = {FORWARD, BACK, LEFT, RIGHT};

    for (int i = 0; i < 4; i++) {
        if (movekey[i] == main->e.key.code &&
        main->player->movement->is_moving != ATTACK) {
            main->player->movement->direction = direction[i];
            main->player->movement->is_moving = MOVING;
            move_player(main, main->scenes[main->actual_scene], i);
            return;
        }
    }
    player_event(main);
}