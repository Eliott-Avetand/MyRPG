/*
** EPITECH PROJECT, 2020
** main
** File description:
** main file of the rpg
*/

#include "rpg.h"

void game_loop(main_t *main)
{
    while (sfRenderWindow_isOpen(main->win)) {
        redirect_events(main);
        if (main->actual_scene < HUB)
            render_menu_scene(main, main->scenes[main->actual_scene]);
        else
            render_game_scene(main, main->scenes[main->actual_scene]);
    }
}

int main(void)
{
    main_t *main = create_main_struct();

    if (!main)
        return EXIT_ERROR;
    game_loop(main);
    clean_program(main);
    return 0;
}
