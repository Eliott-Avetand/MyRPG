/*
** EPITECH PROJECT, 2020
** clean_program
** File description:
** redirect to the differents function to clean and destroy objects
*/

#include "rpg.h"

void free_particule(particles_t *particle)
{
    sfSprite_destroy(particle->sprite);
    sfTexture_destroy(particle->texture);
    sfClock_destroy(particle->clock);
    free(particle);
}

void free_game_scene(scene_t *scene)
{
    for (int i = 0; scene->map->layers[i] != NULL; i++) {
        sfTexture_destroy(scene->map->layers[i]->texture);
        sfSprite_destroy(scene->map->layers[i]->sprite);
        free(scene->map->layers[i]);
    }
    for (int i = 0; i < 60; i++)
        free(scene->map->collision[i]);
    for (int i = 0; scene->enemies[i] != NULL; i++)
        destroy_enemy(scene->enemies[i]);
    free(scene->map->collision);
    for (int i = 0; scene->map->coll_rect[i] != NULL; i++)
        sfRectangleShape_destroy(scene->map->coll_rect[i]);
    free(scene->map->coll_rect);
    free(scene->map);
    free(scene);
}

void free_menu_scene(scene_t *scene)
{
    for (int i = 0; scene->particles[i] != NULL; i++)
        free_particule(scene->particles[i]);
    for (int i = 0; scene->texts[i] != NULL; i++)
        sfText_destroy(scene->texts[i]);
    for (int i = 0; scene->buttons[i] != NULL; i++) {
        sfText_destroy(scene->buttons[i]->text);
        free(scene->buttons[i]);
    }
    for (int i = 0; scene->sprites[i] != NULL; i++) {
        sfTexture_destroy(scene->sprites[i]->texture);
        sfSprite_destroy(scene->sprites[i]->sprite);
        free(scene->sprites[i]);
    }
    sfFont_destroy(scene->font);
    free(scene);
}

void clean_program(main_t *main)
{
    sfRenderWindow_destroy(main->win);
    sfView_destroy(main->camera);
    destroy_game_sounds(main);
    destroy_all_portals(main);
    destroy_death_menu(main->player->death_menu);
    destroy_pause_menu(main->player->pause_menu);
    destroy_player(main->player);
    for (int i = 0; main->scenes[i] != NULL; i++) {
        destroy_all_rocks(main->scenes[i]);
        if (i < HUB)
            free_menu_scene(main->scenes[i]);
        else
            free_game_scene(main->scenes[i]);
    }
    free(main);
}