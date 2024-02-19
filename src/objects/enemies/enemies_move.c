/*
** EPITECH PROJECT, 2020
** clean_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void check_player(player_t *player, enemies_t *enemy)
{
    sfFloatRect e_bounds = update_bound_enemy(enemy);
    sfFloatRect p_bounds = sfSprite_getGlobalBounds(player->sprite->sprite);

    if (sfFloatRect_intersects(&p_bounds, &e_bounds, NULL) == sfTrue) {
        sfClock_restart(enemy->direction->e_move->movement);
        enemy->direction->enemy_status = E_FOLLOW;
        enemy->direction->e_move->nbr_move = 0;
    }
}

void move_enemy_on_y(enemies_t *enemy, Vec2f p_pos, Vec2f e_pos, Vec2f *ofs)
{
    if (p_pos.y < e_pos.y) {
        (*ofs).y = -8;
        enemy->direction->e_direction = E_FORWARD;
    } else if (p_pos.y > e_pos.y) {
        (*ofs).y = 8;
        enemy->direction->e_direction = E_DOWN;
    } else
        enemy->direction->e_move->nbr_move = 0;
}

Vec2f go_to_player(player_t *player, enemies_t *enemy, sfVector2f e_pos)
{
    sfVector2f p_pos = get_few_distance(player, enemy);
    sfVector2f offset = {0, 0};

    if (enemy->direction->e_move->nbr_move == 0) {
        if (p_pos.x < e_pos.x) {
            offset.x = -8;
            enemy->direction->e_direction = E_LEFT;
        } else if (p_pos.x > e_pos.x) {
            offset.x = 8;
            enemy->direction->e_direction = E_RIGHT;
        } else
            enemy->direction->e_move->nbr_move = 1;
    }
    if (enemy->direction->e_move->nbr_move == 1)
        move_enemy_on_y(enemy, p_pos, e_pos, &offset);
    return offset;
}

void idle_enemy_handler(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->e_move->movement);

    if (sfTime_asMilliseconds(time) > enemy->direction->e_move->r_milisec) {
        enemy->direction->enemy_status = E_MOVING;
        sfClock_restart(enemy->direction->e_move->movement);
        enemy->direction->e_move->what_side = random_int(0, 3);
        enemy->direction->e_move->nbr_move = random_int(1, 3);
    }
}

void moving_enemy_handler(enemies_t *enemy, map_t *map)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->e_move->movement);
    sfFloatRect bounds = rect_getGlobalBounds(enemy->hitbox);
    sfVector2f offset = new_enemy_pos(enemy);

    if (sfTime_asMilliseconds(time) > 100) {
        if (is_colliding(bounds, offset, map) == 1)
            return;
        sfSprite_setPosition(enemy->sprite->sprite, offset);
        sfClock_restart(enemy->direction->e_move->movement);
        enemy->direction->e_move->nbr_move--;
        if (enemy->direction->e_move->nbr_move <= 0) {
            enemy->direction->e_move->r_milisec = random_float(5000, 7000);
            enemy->direction->enemy_status = E_IDLE;
        }
    }
    anim_enemies(enemy);
}

