/*
** EPITECH PROJECT, 2021
** create_player.c
** File description:
** create the scene
*/

#include "rpg.h"

void attack_handler(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->movement->attack_clk);

    if (sfTime_asMilliseconds(time) > 350)
        player->movement->attack_status = IS_ATTACKING;
}

void anim_player_attack(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->movement->clock);
    sfIntRect rect = sfSprite_getTextureRect(player->sprite->sprite);

    rect.top = player->movement->direction + (15 * 64);
    if (sfTime_asMilliseconds(time) > 100) {
        if (rect.left < 320)
            rect.left += 64;
        else {
            player->movement->is_moving = IDLE;
            player->movement->attack_status = WAIT;
            sfClock_restart(player->movement->attack_clk);
        }
        sfSprite_setTextureRect(player->sprite->sprite, rect);
        sfClock_restart(player->movement->clock);
    }
}

void anim_player_movement(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->movement->clock);
    sfIntRect rect = sfSprite_getTextureRect(player->sprite->sprite);

    rect.top = player->movement->direction;
    if (sfTime_asMilliseconds(time) > 100) {
        rect.left = (rect.left + 64) % 512;
        sfSprite_setTextureRect(player->sprite->sprite, rect);
        sfClock_restart(player->movement->clock);
    }
}

void reset_player_movement(player_t *player)
{
    sfIntRect rect = sfSprite_getTextureRect(player->sprite->sprite);

    rect.left = 0;
    rect.top = player->movement->direction;
    sfSprite_setTextureRect(player->sprite->sprite, rect);
}

void player_anim_movement(player_t *player)
{
    update_player_pos(player);
    attack_handler(player);
    if (player->movement->is_moving == MOVING)
        anim_player_movement(player);
    else if (player->movement->is_moving == ATTACK)
        anim_player_attack(player);
    else
        reset_player_movement(player);
}