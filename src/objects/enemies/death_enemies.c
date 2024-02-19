/*
** EPITECH PROJECT, 2020
** death_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void enemi_death_management(enemies_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(enemy->time_death);

    if (sfTime_asSeconds(time) > 20) {
        enemy->enemy_status = ALIVE;
        enemy->health = enemy->max_health;
        sfSprite_setPosition(enemy->sprite->sprite, enemy->spawn_pos);
    }
}
