/*
** EPITECH PROJECT, 2020
** redirect_events
** File description:
** get the event and redirect them on differents functions
*/

#include "rpg.h"

void left_game(main_t *main)
{
    sfRenderWindow_close(main->win);
}

void launch_game(main_t *main)
{
    Vec2f pos = getPosition(main->player->sprite->sprite);

    stop_all_sounds(main);
    main->actual_scene = HUB;
    sfSound_play(main->scenes[HUB]->music[0]->sound);
    sfView_setSize(main->camera, (Vec2f){720, 480});
    sfView_setCenter(main->camera, pos);
    sfRenderWindow_setView(main->win, main->camera);
}

void goto_options(main_t *main)
{
    sfTime offset = sfSound_getPlayingOffset
    (main->scenes[main->actual_scene]->music[0]->sound);

    stop_all_sounds(main);
    sfSound_setPlayingOffset
    (main->scenes[OPTION_MENU]->music[0]->sound, offset);
    sfSound_play(main->scenes[OPTION_MENU]->music[0]->sound);
    main->actual_scene = OPTION_MENU;
}

void goto_how_to_play(main_t *main)
{
    sfTime offset;

    if (main->actual_scene != COMMANDS && main->actual_scene != STORY) {
        offset = sfSound_getPlayingOffset
        (main->scenes[main->actual_scene]->music[0]->sound);
        stop_all_sounds(main);
        sfSound_setPlayingOffset
        (main->scenes[HOW_TO_PLAY]->music[0]->sound, offset);
        sfSound_play(main->scenes[HOW_TO_PLAY]->music[0]->sound);
    }
    main->actual_scene = HOW_TO_PLAY;
}

void goto_main_menu(main_t *main)
{
    sfTime offset;

    if (main->scenes[main->actual_scene]->music[0] != NULL)
        offset = sfSound_getPlayingOffset
    (main->scenes[main->actual_scene]->music[0]->sound);
    sfRenderWindow_setView(main->win,
    sfRenderWindow_getDefaultView(main->win));
    stop_all_sounds(main);
    sfSound_setPlayingOffset
    (main->scenes[MAIN_MENU]->music[0]->sound, offset);
    sfSound_play(main->scenes[MAIN_MENU]->music[0]->sound);
    if (main->actual_scene != OPTION_MENU &&
    main->actual_scene != HOW_TO_PLAY) {
        main->game_status = IN_GAME;
        sfRenderWindow_setView(main->win,
        sfRenderWindow_getDefaultView(main->win));
        stop_all_sounds(main);
        sfSound_play(main->scenes[MAIN_MENU]->music[0]->sound);
    }
    main->actual_scene = MAIN_MENU;
}