/*
** EPITECH PROJECT, 2020
** clean_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void destroy_enemy(enemies_t *enemy)
{
    sfClock_destroy(enemy->direction->clock);
    sfClock_destroy(enemy->direction->e_move->movement);
    sfClock_destroy(enemy->direction->attack_clock);
    sfClock_destroy(enemy->time_death);
    sfRectangleShape_destroy(enemy->hitbox);
    sfRectangleShape_destroy(enemy->attack_box);
    free(enemy->direction);
    free(enemy->direction->e_move);
    sfSprite_destroy(enemy->sprite->sprite);
    sfTexture_destroy(enemy->sprite->texture);
    sfSound_stop(enemy->dead_sounds->sound);
    sfSoundBuffer_destroy(enemy->dead_sounds->buffer);
    sfSound_destroy(enemy->dead_sounds->sound);
    free(enemy->dead_sounds);
    free(enemy->sprite);
    free(enemy);
}