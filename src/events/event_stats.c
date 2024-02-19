/*
** EPITECH PROJECT, 2020
** event_inventory.c
** File description:
** get the event and redirect them on differents functions
*/
#include "rpg.h"

void analyse_key_stats(main_t *main)
{
    if (main->e.key.code == sfKeyC)
        open_stats(main);
}

void event_stats_handler(main_t *main)
{
    if (main->e.type == sfEvtKeyPressed)
        analyse_key_stats(main);
}