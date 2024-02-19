/*
** EPITECH PROJECT, 2020
** int_to_str.c
** File description:
** transform int to str
*/

#include "rpg.h"

char *int_to_str(int nb)
{
    char *str = malloc(12);
    int co = 0;
    int save_nb = nb;

    if (!str)
        return NULL;
    if (nb == 0)
        return "0";
    while (save_nb > 0) {
        save_nb = save_nb / 10;
        co++;
    }
    str[co] = '\0';
    for (int i = 0; i < co; i++) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    return my_revstr(str);
}
