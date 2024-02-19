/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** Gets number from a string
** {Epi-Lib}, created by Grégoire Biendiné.
** PLEASE DON'T COPY THIS FILE.
*/

int my_strlen(char const *str);

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int is_neg = 0;

    if (!str || my_strlen(str) > 11)
        return 0;
    is_neg = (str[0] == '-') ? 1 : 0;
    for (int i = is_neg; str[i] && is_num(str[i]) == 1; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return (is_neg == 1) ? nb * -1 : nb;
}
