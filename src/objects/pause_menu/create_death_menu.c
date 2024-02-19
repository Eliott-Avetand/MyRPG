/*
** EPITECH PROJECT, 2020
** create_pause_menu
** File description:
** create pause menu
*/

#include "rpg.h"

void destroy_death_menu(death_menu_t *death_menu)
{
    sfRectangleShape_destroy(death_menu->background);
    sfText_destroy(death_menu->text);
    sfText_destroy(death_menu->button->text);
    free(death_menu->button);
    sfFont_destroy(death_menu->font);
    free(death_menu);
}

void handle_mouse_click_death(death_menu_t *death_menu, sfVector2f pos)
{
    sfColor magenta = sfColor_fromRGB(124, 0, 73);

    if (is_on_btn(death_menu->button, pos.x, pos.y) == 1) {
        sfText_setColor(death_menu->button->text, magenta);
        sfText_setOutlineColor(death_menu->button->text, sfWhite);
        sfText_setOutlineThickness(death_menu->button->text, 2);
    } else {
        sfText_setColor(death_menu->button->text, sfWhite);
        sfText_setOutlineThickness(death_menu->button->text, 0);
    }
}

void handle_mouse_move_death(death_menu_t *death_menu, sfVector2f pos)
{
    sfColor magenta = sfColor_fromRGB(124, 0, 73);

    if (is_on_btn(death_menu->button, pos.x, pos.y) == 1) {
        sfText_setOutlineColor(death_menu->button->text, magenta);
        sfText_setOutlineThickness(death_menu->button->text, 2);
    } else {
        sfText_setColor(death_menu->button->text, sfWhite);
        sfText_setOutlineThickness(death_menu->button->text, 0);
    }
}

void death_menu_handler(death_menu_t *death_menu, main_t *main)
{
    sfVector2i pixelpos = sfMouse_getPositionRenderWindow(main->win);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(main->win,
    pixelpos, main->camera);

    if (main->e.type == 9 && main->e.mouseButton.button == 0)
        handle_mouse_click_death(death_menu, mouse_pos);
    if (main->e.type == 10 && main->e.mouseButton.button == 0) {
        if (is_on_btn(death_menu->button, mouse_pos.x, mouse_pos.y) == 1) {
            sfSound_play(main->scenes[MAIN_MENU]->music[1]->sound);
            death_menu->button->click_fn(main);
        }
    }
    if (main->e.type == sfEvtMouseMoved)
        handle_mouse_move_death(death_menu, mouse_pos);
}

death_menu_t *create_death_menu(void)
{
    death_menu_t *death_menu = malloc(sizeof(death_menu_t));
    sfColor bg_color = sfBlack;

    if (!death_menu)
        return NULL;
    death_menu->background = sfRectangleShape_create();
    death_menu->font = sfFont_createFromFile(FONT);
    if (!death_menu->background || !death_menu->font)
        return NULL;
    bg_color.a = 160;
    sfRectangleShape_setFillColor(death_menu->background, bg_color);
    sfRectangleShape_setSize(death_menu->background, (sfVector2f){720, 480});
    sfRectangleShape_setOrigin(death_menu->background, (sfVector2f){360, 240});
    death_menu->text = create_text(death_menu->font, T_DEATH);
    death_menu->button = create_button(death_menu->font, B_DEATH, left_game);
    return death_menu;
}