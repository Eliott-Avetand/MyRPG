/*
** EPITECH PROJECT, 2020
** redirect_events2
** File description:
** get the event and redirect them on differents functions
*/

#include "rpg.h"

void goto_commands(main_t *main)
{
    main->actual_scene = COMMANDS;
}

void goto_story(main_t *main)
{
    main->actual_scene = STORY;
}