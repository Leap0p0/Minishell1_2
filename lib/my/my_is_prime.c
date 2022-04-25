/*
** EPITECH PROJECT, 2021
** prime
** File description:
** prime number or not
*/

int my_is_prime(int nb)
{
    int i;
    int p = 0;

    for (i = 1; i <= nb; i++) {
        if (nb % i == 0)
            p++;
    }
    if (p == 2) {
        return (1);
    } else {
        return (0);
    }
}
