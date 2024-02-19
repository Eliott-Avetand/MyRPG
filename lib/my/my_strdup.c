/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** Duplicate string to another
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!new_str)
        return NULL;
    my_strcpy(new_str, str);
    return new_str;
}
