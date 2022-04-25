/*
** EPITECH PROJECT, 2021
** my_puststr
** File description:
** char to tab to t[0]
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
