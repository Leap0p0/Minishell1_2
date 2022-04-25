/*
** EPITECH PROJECT, 2021
** my_print_nbr
** File description:
** print one number
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar ((nb % 10) + 48);
    return (0);
}
