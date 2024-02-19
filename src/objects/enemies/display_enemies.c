/*
** EPITECH PROJECT, 2020
** clean_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

void display_enemy(scene_t *scene, main_t *main, player_t *player)
{
    for (int i = 0; scene->enemies[i] != NULL; i++) {
        if (scene->enemies[i]->enemy_status != DEAD)
            drawSprite(main->win, scene->enemies[i]->sprite->sprite, NULL);
        if (main->game_status != PAUSE &&
        scene->enemies[i]->enemy_status != DEAD)
            random_move_enemies(scene->enemies[i], player, main);
        if (scene->enemies[i]->enemy_status == DEAD &&
        scene->enemies[i]->death < 3)
            enemi_death_management(scene->enemies[i]);
    }
}