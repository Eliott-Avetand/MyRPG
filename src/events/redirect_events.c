/*
** EPITECH PROJECT, 2020
** redirect_events
** File description:
** get the event and redirect them on differents functions
*/

#include "rpg.h"

void handle_mouse_click(main_t *main, sfMouseButtonEvent pos)
{
    scene_t *scene = main->scenes[main->actual_scene];
    sfColor magenta = sfColor_fromRGB(124, 0, 73);

    for (int i = 0; scene->buttons[i] != NULL; i++) {
        if (is_on_btn(scene->buttons[i], pos.x, pos.y) == 1) {
            sfText_setColor(scene->buttons[i]->text, magenta);
            sfText_setOutlineColor(scene->buttons[i]->text, sfWhite);
            sfText_setOutlineThickness(scene->buttons[i]->text, 4);
        } else {
            sfText_setColor(scene->buttons[i]->text, sfWhite);
            sfText_setOutlineThickness(scene->buttons[i]->text, 0);
        }
    }
}

void handle_mouse_released(main_t *main, sfMouseButtonEvent pos)
{
    scene_t *scene = main->scenes[main->actual_scene];

    for (int i = 0; scene->buttons[i] != NULL; i++) {
        if (is_on_btn(scene->buttons[i], pos.x, pos.y) == 1 &&
        scene->buttons[i]->click_fn != NULL) {
            sfSound_play(main->scenes[MAIN_MENU]->music[1]->sound);
            scene->buttons[i]->click_fn(main);
        }
    }
}

void handle_mouse_move(main_t *main, sfMouseMoveEvent pos)
{
    scene_t *scene = main->scenes[main->actual_scene];
    sfColor magenta = sfColor_fromRGB(124, 0, 73);

    for (int i = 0; scene->buttons[i] != NULL; i++) {
        if (is_on_btn(scene->buttons[i], pos.x, pos.y) == 1) {
            sfText_setOutlineColor(scene->buttons[i]->text, magenta);
            sfText_setOutlineThickness(scene->buttons[i]->text, 4);
        } else {
            sfText_setColor(scene->buttons[i]->text, sfWhite);
            sfText_setOutlineThickness(scene->buttons[i]->text, 0);
        }
    }
}

void menu_handler(main_t *main)
{
    if (main->e.type == 9 && main->e.mouseButton.button == 0)
        handle_mouse_click(main, main->e.mouseButton);
    if (main->e.type == 10 && main->e.mouseButton.button == 0)
        handle_mouse_released(main, main->e.mouseButton);
    if (main->e.type == sfEvtMouseMoved)
        handle_mouse_move(main, main->e.mouseMove);
}

void redirect_events(main_t *main)
{
    while (sfRenderWindow_pollEvent(main->win, &main->e)) {
        if (main->e.type == sfEvtClosed)
            sfRenderWindow_close(main->win);
        if (main->actual_scene < HUB)
            menu_handler(main);
        else
            event_game_handler(main);
    }
}