/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** getnbr
*/

#include "my.h"

int increment_result(int result, char c)
{
    result = result * 10;
    if (result >= 0)
        result = result + (c - '0');
    else
        result = result - (c - '0');
    return (result);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int k = 1;
    int result = 0;

    while ((str[i] == '+' || str[i] == '-') && str[i]) {
        if (str[i] == '-')
            k = k * (-1);
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0') {
        result = increment_result(result, str[i]);
        i++;
    }
    return (result);
}
