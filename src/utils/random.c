/*
** EPITECH PROJECT, 2020
** random
** File description:
** generate random numbers between min and max
*/

#include "rpg.h"

int random_int(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

float random_float(float min, float max)
{
    float random = (float)rand() / (float)__INT_MAX__;

    return (random * (max - min)) + min;
}