/*
** EPITECH PROJECT, 2020
** sounds_menu.c
** File description:
** create sounds of the menu.
*/

#include "rpg.h"

int create_options_sound(main_t *main)
{
    main->scenes[HOW_TO_PLAY]->music[0] = create_sounds(OPTION_MUSIC);
    main->scenes[HOW_TO_PLAY]->music[1] = NULL;
    main->scenes[OPTION_MENU]->music[0] = create_sounds(OPTION_MUSIC);
    main->scenes[OPTION_MENU]->music[1] = NULL;
    if (!main->scenes[OPTION_MENU]->music[0] ||
    !main->scenes[HOW_TO_PLAY]->music[0])
        return EXIT_ERROR;
    return 0;
}

int create_menu_sounds(main_t *main)
{
    char *sounds_path[2] = {MENU_MUSIC, SELECT_MENU};

    for (int i = 0; i < 2; i++) {
        main->scenes[MAIN_MENU]->music[i] = create_sounds(sounds_path[i]);
        if (!main->scenes[MAIN_MENU]->music[i])
            return EXIT_ERROR;
        main->scenes[MAIN_MENU]->music[i + 1] = NULL;
    }
    return create_options_sound(main);
}

int create_game_sounds(main_t *main)
{
    main->scenes[JUNGLE]->music[0] = create_sounds(JUNGLE_MUSIC);
    main->scenes[JUNGLE]->music[1] = NULL;
    main->scenes[ASHLAND]->music[0] = create_sounds(ASHLAND_MUSIC);
    main->scenes[ASHLAND]->music[1] = NULL;
    main->scenes[HUB]->music[0] = create_sounds(HUB_MUSIC);
    main->scenes[HUB]->music[1] = NULL;
    main->scenes[ATLANTIS]->music[0] = create_sounds(ATLANTIS_MUSIC);
    main->scenes[ATLANTIS]->music[1] = NULL;
    if (!main->scenes[ASHLAND]->music[0] || !main->scenes[HUB]->music[0] ||
    !main->scenes[ATLANTIS]->music[0] || !main->scenes[JUNGLE]->music[0])
        return EXIT_ERROR;
    update_sounds(main, 100);
    return 0;
}