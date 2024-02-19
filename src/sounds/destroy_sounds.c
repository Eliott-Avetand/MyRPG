/*
** EPITECH PROJECT, 2020
** destroy_sounds.c
** File description:
** destroy all sounds of the game.
*/

#include "rpg.h"

void destroy_game_sounds(main_t *main)
{
    for (int scene = 0; main->scenes[scene] != NULL; scene++) {
        for (int sd = 0; main->scenes[scene]->music[sd] != NULL; sd++) {
            sfSound_stop(main->scenes[scene]->music[sd]->sound);
            sfSoundBuffer_destroy(main->scenes[scene]->music[sd]->buffer);
            sfSound_destroy(main->scenes[scene]->music[sd]->sound);
            free(main->scenes[scene]->music[sd]);
        }
    }
    destroy_player_sounds(main->player->player_sounds);
}