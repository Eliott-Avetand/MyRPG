/*
** EPITECH PROJECT, 2020
** player_sounds.c
** File description:
** create sounds of the menu.
*/

#include "rpg.h"

void destroy_player_sounds(player_sounds_t *player_sounds)
{
    sfSound_stop(player_sounds->sword_sounds->sound);
    sfSoundBuffer_destroy(player_sounds->sword_sounds->buffer);
    sfSound_destroy(player_sounds->sword_sounds->sound);
    free(player_sounds->sword_sounds);
    free(player_sounds);
}

player_sounds_t *create_player_sounds(void)
{
    player_sounds_t *player_sounds = malloc(sizeof(player_sounds_t));

    if (!player_sounds)
        return NULL;
    player_sounds->sword_sounds = create_sounds(SWORD_SOUND);
    player_sounds->hit = create_sounds(HIT_SOUND);
    if (!player_sounds->sword_sounds || !player_sounds->hit)
        return NULL;
    return player_sounds;
}