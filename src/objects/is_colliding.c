/*
** EPITECH PROJECT, 2021
** is_colling.c
** File description:
** collision
*/

#include "rpg.h"

sfFloatRect add_dir_to_bounds(sfFloatRect bounds, Vec2f offset)
{
    return (sfFloatRect){bounds.left + offset.x, bounds.top + offset.y,
    bounds.width, bounds.height};
}

int is_colliding(sfFloatRect bounds, Vec2f offset, map_t *map)
{
    sfFloatRect p_bounds = add_dir_to_bounds(bounds, offset);
    sfFloatRect wall_bounds;

    for (int i = 0; map->coll_rect[i]; i++) {
        wall_bounds = rect_getGlobalBounds(map->coll_rect[i]);
        if (sfFloatRect_intersects(&p_bounds, &wall_bounds, NULL) == sfTrue)
            return 1;
    }
    return 0;
}