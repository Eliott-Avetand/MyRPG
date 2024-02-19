/*
** EPITECH PROJECT, 2020
** free_tab
** File description:
** free word array tabs and style structures
*/

#include "rpg.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_text_style(text_style_t *style)
{
    free(style->string);
    free(style->pos);
    free(style);
}

void free_sprite_style(sprite_style_t *style)
{
    free(style->string);
    free(style->pos);
    free(style->rct);
    free(style);
}