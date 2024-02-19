/*
** EPITECH PROJECT, 2020
** text_utils.c
** File description:
** all usefull functions for the texts
*/

#include "rpg.h"

int is_on_btn(button_t *btn, int x, int y)
{
    sfFloatRect rct = sfText_getGlobalBounds(btn->text);

    if (x >= rct.left && x <= rct.left + rct.width &&
    y >= rct.top && y <= rct.top + rct.height)
        return 1;
    return 0;
}