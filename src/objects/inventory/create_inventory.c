/*
** EPITECH PROJECT, 2020
** create_inventory.c
** File description:
** Functions that deal with the inventory
*/
#include "rpg.h"

sprite_t *create_inventory_sprite(void)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {50, 0, 250, 150};

    if (!sprite)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(INVENTORY_SPT, NULL);
    if (!sprite->sprite || !sprite->texture)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, rect);
    sfSprite_scale(sprite->sprite, (sfVector2f){2.5, 2.5});
    sfSprite_setPosition(sprite->sprite, (sfVector2f){700, 910});
    return sprite;
}

inventory_t *create_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return NULL;
    inventory->inventory_sounds = create_inventory_sounds();
    inventory->sprite = create_inventory_sprite();
    if (!inventory->sprite)
        return NULL;
    return inventory;
}