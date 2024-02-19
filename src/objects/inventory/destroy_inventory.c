/*
** EPITECH PROJECT, 2020
** destroy_inventory.c
** File description:
** Functions that destroy the inventory
*/
#include "rpg.h"

void destroy_inventory(inventory_t *inventory)
{
    destroy_inventory_sounds(inventory->inventory_sounds);
    sfTexture_destroy(inventory->sprite->texture);
    sfSprite_destroy(inventory->sprite->sprite);
    free(inventory->slot);
    free(inventory);
}