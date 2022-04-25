/*
** EPITECH PROJECT, 2021
** pow rec
** File description:
** pow
*/

int multi(int nb, int p)
{
    if (p == 0) {
        return (1);
    } else {
        return (nb * multi(nb, p - 1));
    }
}

int my_compute_power_rec(int nb , int p)
{
    if (p < 0) {
        return (0);
    } else {
        return (multi(nb, p));
    }
}
