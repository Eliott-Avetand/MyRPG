/*
** EPITECH PROJECT, 2020
** parse_line
** File description:
** parser for scene file (parse line to get style)
*/

#include "rpg.h"

sfVector2f *get_pos(char *opt)
{
    char **tab = str_to_word_array(opt, ',');
    sfVector2f *pos = malloc(sizeof(sfVector2f));

    if (!pos || !tab[0] || !tab[1])
        return NULL;
    pos->x = my_getnbr(tab[0]);
    pos->y = my_getnbr(tab[1]);
    free_tab(tab);
    return pos;
}

sfIntRect *get_rect(char *opt)
{
    char **tab = str_to_word_array(opt, ',');
    sfIntRect *rct = malloc(sizeof(sfIntRect));

    if (!rct || !tab[0] || !tab[1] || !tab[2] || !tab[3])
        return NULL;
    rct->top = my_getnbr(tab[0]);
    rct->left = my_getnbr(tab[1]);
    rct->width = my_getnbr(tab[2]);
    rct->height = my_getnbr(tab[3]);
    free_tab(tab);
    return rct;
}

sprite_style_t *parse_sprite_line(char *line)
{
    sprite_style_t *style = malloc(sizeof(sprite_style_t));
    char **opt = str_to_word_array(line, '#');

    if (!opt || !style || !opt[0] || !opt[1] || !opt[2] || !opt[3])
        return my_perror_null("Can't parse style line\n");
    style->string = my_strdup(opt[0]);
    style->pos = get_pos(opt[1]);
    style->rct = get_rect(opt[2]);
    style->rotation = my_getnbr(opt[3]);
    free_tab(opt);
    if (!style->string || !style->pos || !style->rct)
        return my_perror_null("Can't parse style line\n");
    return style;
}

text_style_t *parse_text_line(char *line)
{
    text_style_t *style = malloc(sizeof(text_style_t));
    char **options = str_to_word_array(line, '#');

    if (!options || !style || !options[0] || !options[1] || !options[2])
        return NULL;
    style->string = my_strdup(options[0]);
    style->pos = get_pos(options[1]);
    style->charSize = my_getnbr(options[2]);
    free_tab(options);
    if (!style->string || !style->pos || !style->charSize)
        return NULL;
    return style;
}