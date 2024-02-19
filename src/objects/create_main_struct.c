/*
** EPITECH PROJECT, 2020
** create_main_struct
** File description:
** create_main_struct
*/

#include "rpg.h"

int fill_menu_scenes(main_t *main)
{
    char *files[5] = {F_MAIN_MENU, F_OPTION_MENU,
    F_HOW_TO_PLAY, F_COMMANDS, F_STORY};
    void (*callbacks[5][4])(main_t *main) = {
        {launch_game, goto_options, left_game, goto_how_to_play},
        {goto_main_menu, active_sounds, decrease_audio, increase_audio},
        {goto_commands, goto_story, goto_main_menu},
        {goto_how_to_play},
        {goto_how_to_play}
    };

    for (int i = 0; i < 5; i++) {
        main->scenes[i] = create_menu_scene(files[i], callbacks[i]);
        main->scenes[i + 1] = NULL;
        if (!main->scenes[i])
            return -1;
    }
    if (create_all_particles(main) != 0 ||
    create_menu_sounds(main) != 0)
        return -1;
    return 0;
}

int fill_other_objects(main_t *main)
{
    main->player = create_player();
    main->game_options = init_game_option();
    main->player->pause_menu = create_menu_pause();
    main->player->death_menu = create_death_menu();
    create_all_portals(main);
    if (!main->player || !main->game_options || !main->player->pause_menu ||
    !main->player->death_menu || create_game_sounds(main) != 0 ||
    create_all_enemies(main) != 0 || create_all_rocks(main) != 0)
        return -1;
    return 0;
}

int fill_game_scenes(main_t *main)
{
    char *layers[5] = {HUB_LAYERS_LIST, ASHLAND_LAYERS_LIST,
    CAVE_LAYERS_LIST, JUNGLE_LAYERS_LIST, ATLANTIS_LAYERS_LIST};
    char *collision[5] = {HUB_COLLISON_MAP, ASHLAND_COLLISION_MAP,
    CAVE_COLLISION_MAP, JUNGLE_COLLISON_MAP, ATLANTIS_COLLISION_MAP};

    for (int i = HUB; i < 10; i++) {
        main->scenes[i] = create_game_scene(layers[i - HUB],
        collision[i - HUB]);
        main->scenes[i + 1] = NULL;
        if (!main->scenes[i])
            return -1;
        if (i == ATLANTIS) {
            for (int i = 0; i < 60; i++) {
                main->scenes[ATLANTIS]->particles[i] = create_bubble();
                main->scenes[ATLANTIS]->particles[i + 1] = NULL;
            }
        }
    }
    return fill_other_objects(main);
}

main_t *create_main_struct(void)
{
    main_t *main = malloc(sizeof(main_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (!main)
        return my_perror_null(MALLOC_ERROR);
    main->win = sfRenderWindow_create(mode, "Traveled", sfFullscreen, NULL);
    main->camera = sfView_create();
    main->actual_scene = MAIN_MENU;
    main->game_status = IN_GAME;
    if (!main->win || !main->camera)
        return NULL;
    if (fill_menu_scenes(main) != 0 || fill_game_scenes(main) != 0)
        return NULL;
    sfRenderWindow_setFramerateLimit(main->win, 30);
    sfSound_play(main->scenes[main->actual_scene]->music[0]->sound);
    return main;
}