/*
** EPITECH PROJECT, 2020
** anim_enemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void death_anim(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->clock);
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite->sprite);

    rect.top = enemy->direction->e_direction;
    if (sfTime_asMilliseconds(time) > 300) {
        if (rect.left < (65.75 * 10))
            rect.left += 65.75;
        else {
            enemy->enemy_status = DEAD;
            enemy->death++;
            sfClock_restart(enemy->time_death);
        }
        sfSprite_setTextureRect(enemy->sprite->sprite, rect);
        sfClock_restart(enemy->direction->clock);
    }
}

void anim_enemies(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->clock);
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite->sprite);

    rect.top = enemy->direction->e_direction;
    if (enemy->direction->enemy_status == E_IDLE) {
        rect.left = 0;
        sfSprite_setTextureRect(enemy->sprite->sprite, rect);
        return;
    }
    if (sfTime_asMilliseconds(time) > 100) {
        if (rect.left < 197.25)
            rect.left += 65.75;
        else
            rect.left = 0;
        sfSprite_setTextureRect(enemy->sprite->sprite, rect);
        sfClock_restart(enemy->direction->clock);
    }
}

sfFloatRect update_bound_enemy(enemies_t *enemy)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite->sprite);

    rect.top -= 5 * 32;
    rect.left -= 5 * 32;
    rect.height += 10 * 32;
    rect.width += 10 * 32;
    return rect;
}

sfVector2f new_enemy_pos(enemies_t *enemy)
{
    sfVector2f go_to = sfSprite_getPosition(enemy->sprite->sprite);

    if (enemy->direction->e_move->what_side == 0) {
        go_to.x -= 8;
        enemy->direction->e_direction = E_LEFT;
    }
    if (enemy->direction->e_move->what_side == 1) {
        go_to.x += 8;
        enemy->direction->e_direction = E_RIGHT;
    }
    if (enemy->direction->e_move->what_side == 2) {
        go_to.y -= 8;
        enemy->direction->e_direction = E_FORWARD;
    }
    if (enemy->direction->e_move->what_side == 3) {
        go_to.y += 8;
        enemy->direction->e_direction = E_DOWN;
    }
    return go_to;
}

void random_move_enemies(enemies_t *enemy, player_t *player, main_t *main)
{
    update_enemy_hitbox(enemy);
    enemy_attack_handler(enemy);
    if (enemy->enemy_status == BEFORE_DEAD)
        return death_anim(enemy);
    if (enemy->direction->enemy_status == E_FOLLOW) {
        target_player(player, enemy, main->scenes[main->actual_scene]->map);
        is_near_the_player(player, enemy);
    }
    if (enemy->direction->enemy_status == E_IDLE) {
        check_player(player, enemy);
        anim_enemies(enemy);
        idle_enemy_handler(enemy);
    }
    if (enemy->direction->enemy_status == E_MOVING)
        moving_enemy_handler(enemy, main->scenes[main->actual_scene]->map);
    if (enemy->direction->enemy_status == E_ATTACK) {
        update_enemy_attack_box(enemy, main);
        anim_enemy_attack(enemy);
    }
}