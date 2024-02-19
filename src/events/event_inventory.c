/*
** EPITECH PROJECT, 2020
** event_inventory.c
** File description:
** get the event and redirect them on differents functions
*/
#include "rpg.h"

void analyse_key_inventory(main_t *main)
{
    if (main->e.key.code == sfKeyI)
        open_inventory(main);
}

void event_inventory_handler(main_t *main)
{
    if (main->e.type == sfEvtKeyPressed)
        analyse_key_inventory(main);
}