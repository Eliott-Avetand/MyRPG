/*
** EPITECH PROJECT, 2020
** create_ennemies.c
** File description:
** create ennemies
*/

#include "rpg.h"

int get_enemies_count(scene_t *scene)
{
    int nbr = 0;
    int j = 0;
    int i = 0;

    while (i < 60) {
        if (scene->map->collision[i][j] == 9)
            nbr++;
        if (j > 59) {
            j = 0;
            i++;
        }
        j++;
    }
    return nbr;
}

sfVector2f get_enemy_pos(scene_t *scene, int nbr_ennemy)
{
    sfVector2f pos = {0, 0};
    int i = 0;
    int j = 0;
    int nbr = 0;

    while (i < 60) {
        if (scene->map->collision[i][j] == 9)
            nbr++;
        if (nbr == nbr_ennemy) {
            pos.x = j * 32;
            pos.y = i * 32;
            return pos;
        }
        if (j > 59) {
            j = 0;
            i++;
        }
        j++;
    }
    return pos;
}

int push_enemy_scene(scene_t *scene)
{
    int nbr_enemies = get_enemies_count(scene);
    sfVector2f pos = {0, 0};

    for (int i = 0; i < nbr_enemies; i++) {
        pos = get_enemy_pos(scene, i);
        pos.x = random_int(pos.x - 2, pos.x + 2);
        pos.y = random_int(pos.y - 2, pos.y + 2);
        scene->enemies[i] = create_enemy(pos);
        if (!scene->enemies[i])
            return EXIT_ERROR;
        scene->enemies[i + 1] = NULL;
    }
    return 0;
}

int create_all_enemies(main_t *main)
{
    for (int scene = HUB; main->scenes[scene] != NULL; scene++) {
        if (push_enemy_scene(main->scenes[scene]) == 84)
            return EXIT_ERROR;
    }
    main->scenes[ATLANTIS]->enemies[0] = create_boss();
    if (!main->scenes[ATLANTIS]->enemies[0])
        return EXIT_ERROR;
    main->scenes[ATLANTIS]->enemies[1] = NULL;
    return 0;
}