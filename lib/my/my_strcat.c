/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** Concat two strings
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int co = my_strlen(dest);

    for (int i = 0; src[i]; i++, co++) {
        dest[co] = src[i];
    }
    dest[co] = '\0';
    return dest;
}
