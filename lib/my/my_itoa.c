/*
** EPITECH PROJECT, 2020
** my_itoa.c
** File description:
** Convert int to string
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int save = nb;
    int i = 0;

    if (!str)
        return NULL;
    nb *= (nb < 0) ? -1 : 1;
    for (i; nb > 0 ; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    str[i] = (save < 0) ? '-' : '\0';
    if (save < 0)
        str[i + 1] = '\0';
    return (save == 0) ? "0" : my_revstr(str);
}