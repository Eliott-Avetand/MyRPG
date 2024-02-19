/*
** EPITECH PROJECT, 2020
** my_perror.c
** File description:
** Print errors
*/

#include "rpg.h"

void *my_perror_null(char *err)
{
    write(2, err, my_strlen(err));
    return NULL;
}

int my_perror(char *err)
{
    write(2, err, my_strlen(err));
    return 84;
}
