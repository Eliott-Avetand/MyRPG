/*
** EPITECH PROJECT, 2020
** destroy_objects
** File description:
** destroy objects
*/

#include "rpg.h"

void destroy_player(player_t *player)
{
    sfClock_destroy(player->movement->clock);
    sfClock_destroy(player->movement->attack_clk);
    free(player->movement);
    sfTexture_destroy(player->sprite->texture);
    sfSprite_destroy(player->sprite->sprite);
    sfSprite_destroy(player->key->sprite);
    sfTexture_destroy(player->key->texture);
    free(player->key);
    free(player->sprite);
    free(player->inventory);
    free(player);
}