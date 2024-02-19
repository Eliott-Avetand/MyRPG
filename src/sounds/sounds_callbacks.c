/*
** EPITECH PROJECT, 2020
** sounds_callbacks.c
** File description:
** create sounds of the menu.
*/

#include "rpg.h"

void increase_audio(main_t *main)
{
    if (main->game_options->volume < 100 &&
    main->game_options->volume_state == ON) {
        main->game_options->volume += 5;
        update_sounds(main, main->game_options->volume);
        sfText_setString(main->scenes[OPTION_MENU]->texts[3],
        int_to_str(main->game_options->volume));
        sfText_setString(main->player->pause_menu->text[2],
        int_to_str(main->game_options->volume));
        set_volume_position(main, main->game_options->volume);
    }
}

void decrease_audio(main_t *main)
{
    if (main->game_options->volume > 0 &&
    main->game_options->volume_state == ON) {
        main->game_options->volume -= 5;
        update_sounds(main, main->game_options->volume);
        sfText_setString(main->scenes[OPTION_MENU]->texts[3],
        int_to_str(main->game_options->volume));
        sfText_setString(main->player->pause_menu->text[2],
        int_to_str(main->game_options->volume));
        set_volume_position(main, main->game_options->volume);
    }
}