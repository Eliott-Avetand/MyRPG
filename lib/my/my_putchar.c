/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** Print only one char
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
