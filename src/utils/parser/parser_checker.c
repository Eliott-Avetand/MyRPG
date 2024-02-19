/*
** EPITECH PROJECT, 2020
** parser
** File description:
** parser for scene file (error handler)
*/

#include "rpg.h"

FILE *open_file(char *path)
{
    FILE *file = fopen(path, "r");

    if (!file)
        return my_perror_null("Error: can't open given file.\n");
    return file;
}

int check_file(char *path)
{
    FILE *scene_file = open_file(path);
    char *line = NULL;

    for (int i = 0; my_getline(&line, scene_file) != NULL; i++) {
        if (line[0] == '-' && my_strcmp(line, "-TEXTS:") != 0 &&
        my_strcmp(line, "-BUTTONS:") != 0 && my_strcmp(line, "-SPRITES:") != 0)
            return 84;
        free(line);
    }
    fclose(scene_file);
    return 0;
}

FILE *get_scene_file(char *path)
{
    FILE *scene_file;

    if (check_file(path) != 0)
        return NULL;
    scene_file = open_file(path);
    if (!scene_file)
        return NULL;
    return scene_file;
}