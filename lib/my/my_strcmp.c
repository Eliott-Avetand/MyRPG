/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** Compare two string
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

int my_strcmp(char const *a, char const *b)
{
    int co = 0;

    while ((a[co] == b[co]) && a[co] != '\0' && b[co] != '\0')
        co++;
    return a[co] - b[co];
}
