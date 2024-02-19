/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** Return length of string passed as parameter
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
