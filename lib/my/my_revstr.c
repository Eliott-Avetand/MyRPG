/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** Reverse string
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int last_index = my_strlen(str) - 1;
    int save_index = last_index;
    char save;

    for (int i = 0; i <= last_index / 2; i++) {
        save = str[i];
        str[i] = str[save_index];
        str[save_index] = save;
        save_index--;
    }
    return str;
}
