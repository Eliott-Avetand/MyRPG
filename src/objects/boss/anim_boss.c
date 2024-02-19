/*
** EPITECH PROJECT, 2020
** create_portals
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

void boss_attack_clock(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->direction->clock);

    enemy->direction->attack_status = WAIT;
    if (sfTime_asMilliseconds(time) > 700) {
        enemy->direction->enemy_status = E_IDLE;
        sfClock_restart(enemy->direction->attack_clock);
        sfClock_restart(enemy->direction->clock);
    }
}

void anim_boss(enemies_t *boss)
{
    sfTime time = sfClock_getElapsedTime(boss->direction->clock);
    sfIntRect rect = sfSprite_getTextureRect(boss->sprite->sprite);

    rect.top = boss->direction->b_direction;
    if (sfTime_asMilliseconds(time) > 100) {
        if (rect.left >= 94)
            rect.left = 0;
        else
            rect.left += 47;
        sfSprite_setTextureRect(boss->sprite->sprite, rect);
        sfClock_restart(boss->direction->clock);
    }
}

void display_boss(main_t *main, enemies_t *boss)
{
    if (boss->enemy_status != DEAD)
        drawSprite(main->win, boss->sprite->sprite, NULL);
    if (boss->enemy_status != DEAD && main->game_status != PAUSE) {
        anim_boss(boss);
        random_move_boss(boss, main->player, main);
    }
}

void random_move_boss(enemies_t *enemy, player_t *player, main_t *main)
{
    update_enemy_hitbox(enemy);
    enemy_attack_handler(enemy);
    if (enemy->direction->enemy_status == E_FOLLOW) {
        target_player(player, enemy, main->scenes[ATLANTIS]->map);
        is_near_the_player(player, enemy);
    }
    if (enemy->direction->enemy_status == E_IDLE) {
        check_player(player, enemy);
        idle_enemy_handler(enemy);
    }
    if (enemy->direction->enemy_status == E_MOVING)
        moving_enemy_handler(enemy, main->scenes[ATLANTIS]->map);
    if (enemy->direction->enemy_status == E_ATTACK) {
        update_enemy_attack_box(enemy, main);
        boss_attack_clock(enemy);
    }
}