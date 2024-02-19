/*
** EPITECH PROJECT, 2020
** destroy_stats.c
** File description:
** Functions that destroy the stats
*/
#include "rpg.h"

void destroy_stats(stats_t *stats)
{
    for (int i = 0; i < 9; i++)
        sfText_destroy(stats->text[i]);
    sfFont_destroy(stats->font);
    sfTexture_destroy(stats->sprite->texture);
    sfSprite_destroy(stats->sprite->sprite);
    sfTexture_destroy(stats->player->texture);
    sfSprite_destroy(stats->player->sprite);
    sfSound_destroy(stats->stats_sound->sound);
    sfSoundBuffer_destroy(stats->stats_sound->buffer);
    free(stats);
}