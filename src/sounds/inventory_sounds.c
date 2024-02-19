/*
** EPITECH PROJECT, 2020
** inventory_sounds.c
** File description:
** create sounds of the inventory.
*/

#include "rpg.h"

void destroy_inventory_sounds(inventory_sounds_t *inventory_sounds)
{
    sfSound_stop(inventory_sounds->open->sound);
    sfSound_destroy(inventory_sounds->open->sound);
    sfSoundBuffer_destroy(inventory_sounds->open->buffer);
    free(inventory_sounds->open);
    free(inventory_sounds);
}

inventory_sounds_t *create_inventory_sounds(void)
{
    inventory_sounds_t *inventory_sounds = malloc(sizeof(inventory_sounds_t));

    if (!inventory_sounds)
        return NULL;
    inventory_sounds->open = create_sounds(OPEN_INVENTORY);
    if (!inventory_sounds->open)
        return NULL;
    return inventory_sounds;
}