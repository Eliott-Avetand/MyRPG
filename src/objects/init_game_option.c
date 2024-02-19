/*
** EPITECH PROJECT, 2020
** create_objects
** File description:
** create objects (sprite, button, text)
*/

#include "rpg.h"

options_t *init_game_option(void)
{
    options_t *options = malloc(sizeof(options_t));

    if (!options)
        return NULL;
    options->volume = 100;
    options->volume_state = ON;
    return options;
}