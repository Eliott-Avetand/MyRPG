/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Header for our personal lib
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdarg.h>

// string :
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *a, char const *b);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strdup(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **str_to_word_array(char *str, char delim);

// display :
void my_putchar(char c);
void my_putstr(char const *str);

#endif
