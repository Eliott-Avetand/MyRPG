/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** Copy string to another
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
