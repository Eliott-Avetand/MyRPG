/*
** EPITECH PROJECT, 2021
** create_collision_rect
** File description:
** create_collision_rect
*/

#include "rpg.h"

int get_wall_nb(int **coll_map)
{
    int co = 0;

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++)
            co += (coll_map[i][j] == 1) ? 1 : 0;
    }
    return co;
}

sfRectangleShape *create_wall(int x, int y)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    if (!rect)
        return NULL;
    sfRectangleShape_setSize(rect, (Vec2f){32, 32});
    sfRectangleShape_setFillColor(rect, sfRed);
    sfRectangleShape_setPosition(rect, (Vec2f){x * 32, y * 32});
    return rect;
}

int add_walls(map_t *map, int *co, int i)
{
    for (int j = 0; j < 60; j++) {
        if (map->collision[i][j] != 1)
            continue;
        map->coll_rect[*co] = create_wall(j, i);
        if (!map->coll_rect[*co])
            return -1;
        (*co)++;
    }
    return 0;
}

int create_collision_rect(map_t *map)
{
    int wall_nb = get_wall_nb(map->collision);
    int co = 0;

    map->coll_rect = malloc(sizeof(sfRectangleShape *) * (wall_nb + 1));
    if (!map->coll_rect)
        return -1;
    for (int i = 0; i < 60; i++) {
        if (add_walls(map, &co, i) != 0)
            return -1;
    }
    map->coll_rect[co] = NULL;
    return 0;
}