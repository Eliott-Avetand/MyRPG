/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** Functions that handle the inventory
*/
#include "rpg.h"

void open_inventory(main_t *main)
{
    if (main->game_status != INVENTORY) {
        sfSound_play(main->player->inventory->inventory_sounds->open->sound);
        main->game_status = INVENTORY;
    } else if (main->game_status == INVENTORY) {
        sfSound_play(main->player->inventory->inventory_sounds->open->sound);
        main->game_status = IN_GAME;
    }
}

void update_inventory(main_t *main)
{
    sfVector2f pos = sfSprite_getPosition(main->player->sprite->sprite);

    pos.x -= 250 + 250 / 4;
    pos.y -= 150 + 150 / 4;
    sfSprite_setPosition(main->player->inventory->sprite->sprite, pos);
}

void draw_inventory(main_t *main)
{
    if (main->game_status == INVENTORY)
        drawSprite(main->win, main->player->inventory->sprite->sprite, NULL);
}