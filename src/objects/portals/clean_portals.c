/*
** EPITECH PROJECT, 2020
** create_portals
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

void clean_portals_list(portals_t *portal)
{
    sfSprite_destroy(portal->portal_sprite->sprite);
    sfTexture_destroy(portal->portal_sprite->texture);
    sfClock_destroy(portal->clock);
    free(portal->portal_sprite);
    free(portal);
}

void destroy_all_portals(main_t *main)
{
    for (int i = 0; i < 3; i++)
        clean_portals_list(main->scenes[HUB]->portals[i]);
    clean_portals_list(main->scenes[ASHLAND]->portals[0]);
}