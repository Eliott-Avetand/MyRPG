/*
** EPITECH PROJECT, 2020
** str_to_word_array.c
** File description:
** String to 2D array of strings
*/

#include "include/my.h"

char *parse_arg(char *arg, char delim)
{
    char *n_arg = malloc(sizeof(char) * my_strlen(arg) + 1);
    int ltr_check = 0;
    int co = 0;

    if (!n_arg)
        return NULL;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == '\t')
            arg[i] = delim;
        if (arg[i] != delim) {
            n_arg[co++] = arg[i];
            ltr_check = 1;
        } else if (arg[i + 1] != '\0' && arg[i + 1] != delim &&
        arg[i + 1] != '\t' && ltr_check == 1)
            n_arg[co++] = arg[i];
    }
    n_arg[co] = '\0';
    return n_arg;
}

int get_nb_word(char *arg, char delim)
{
    int co = 0;

    if (!arg)
        return -1;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == delim || arg[i + 1] == '\0')
            co++;
    }
    return co;
}

char **malloc_words(char *arg, char delim)
{
    char **words = malloc(sizeof(char *) * (get_nb_word(arg, delim) + 1));
    int word_idx = 0;
    int bornes = 0;

    if (!words)
        return NULL;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == delim || arg[i + 1] == '\0') {
            words[word_idx] = malloc(sizeof(char) * ((i - bornes)) + 2);
            if (!words[word_idx])
                return NULL;
            word_idx++;
            bornes = i;
        }
    }
    return words;
}

char **str_to_word_array(char *str, char delim)
{
    char *arg = parse_arg(str, delim);
    char **words = malloc_words(arg, delim);
    int word_idx = 0;
    int char_idx = 0;

    if (!arg || !words || arg[0] == '\0')
        return NULL;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] != delim)
            words[word_idx][char_idx++] = arg[i];
        else {
            words[word_idx++][char_idx] = '\0';
            char_idx = 0;
        }
    }
    words[word_idx++][char_idx] = '\0';
    words[word_idx] = NULL;
    free(arg);
    return words;
}