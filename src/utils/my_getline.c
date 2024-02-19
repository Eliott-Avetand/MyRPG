/*
** EPITECH PROJECT, 2020
** my_getline.c
** File description:
** Read file line by line
*/

#include "rpg.h"

char *my_getline(char **line, FILE *file)
{
    size_t size = 0;
    int read_size;

    (*line) = NULL;
    read_size = getline(line, &size, file);
    if (read_size == -1 || read_size == 0) {
        free((*line));
        return NULL;
    }
    (*line)[read_size - 1] = '\0';
    return (*line);
}