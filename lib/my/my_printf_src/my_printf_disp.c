/*
** EPITECH PROJECT, 2020
** disp_args_1.c
** File description:
** Function to display arguments by type
*/

#include "../include/my.h"

void disp_normal_char(char c, int *len)
{
    my_putchar(c);
    (*len)++;
}

void disp_char(va_list *list, int *len)
{
    my_putchar(va_arg(*list, int));
    (*len)++;
}

void disp_string(va_list *list, int *len)
{
    char *str = va_arg(*list, char *);

    if (str) {
        my_putstr(str);
        (*len) += my_strlen(str);
    } else {
        my_putstr("(null)");
        (*len) += 6;
    }
}

void disp_int(va_list *list, int *len)
{
    int nb = va_arg(*list, int);

    my_put_nbr(nb);
    (*len) += my_nbrlen(nb);
}