/*
** EPITECH PROJECT, 2020
** create_game_scene
** File description:
** create game scene
*/

#include "rpg.h"

sprite_t *create_layer(char *path)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (!sprite || !path)
        return NULL;
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    return sprite;
}

int add_map_layers(map_t *map, char *path)
{
    FILE *list = fopen(path, "r");
    char *line = NULL;
    int co = 0;

    if (!list)
        return -1;
    while (my_getline(&line, list) != NULL) {
        map->layers[co] = create_layer(line);
        free(line);
        if (!map->layers[co++])
            return -1;
    }
    map->layers[co] = NULL;
    fclose(list);
    return 0;
}

int add_map_collision(map_t *map, char *path)
{
    FILE *matrix = fopen(path, "r");
    char *line = NULL;
    int co = 0;

    map->collision = malloc(sizeof(int *) * 60);
    if (!matrix || !map->collision)
        return -1;
    while (co < 60 && my_getline(&line, matrix) != NULL) {
        map->collision[co] = malloc(sizeof(int) * 60);
        if (!map->collision[co])
            return -1;
        for (int i = 0; i < 60; i++)
            map->collision[co][i] = line[i] - '0';
        co++;
        free(line);
    }
    fclose(matrix);
    return 0;
}

map_t *create_map(char *layers, char *collision)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    if (add_map_layers(map, layers) != 0 ||
    add_map_collision(map, collision) != 0)
        return NULL;
    if (create_collision_rect(map) != 0)
        return NULL;
    return map;
}

scene_t *create_game_scene(char *path_layers, char *path_collision)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (!scene)
        return NULL;
    scene->font = NULL;
    scene->texts[0] = NULL;
    scene->buttons[0] = NULL;
    scene->sprites[0] = NULL;
    scene->particles[0] = NULL;
    scene->music[0] = NULL;
    scene->portals[0] = NULL;
    scene->enemies[0] = NULL;
    scene->rocks[0] = NULL;
    scene->map = create_map(path_layers, path_collision);
    if (!scene->map)
        return NULL;
    return scene;
}