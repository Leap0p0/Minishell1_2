/*
** EPITECH PROJECT, 2021
** find next prime
** File description:
** pow
*/

int my_is_prime2(int nb)
{
    int i;
    int p = 0;

    for (i = 1; i <= nb; i++) {
        if (nb % i == 0) {
            p++;
        }
    }
    if (p == 2) {
        return (1);
    } else {
        return (0);
    }
}

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (my_is_prime2(i) != 1) {
        i++;
    }
    return (i);
}
