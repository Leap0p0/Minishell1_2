/*
** EPITECH PROJECT, 2021
** putchar
** File description:
** lea_pollet
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
