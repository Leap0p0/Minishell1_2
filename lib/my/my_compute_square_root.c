/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

int my_compute_square_root(int nb)
{
    int temp = 0;
    int result;

    while (result != nb) {
        temp++;
        result = temp * temp;
        if (result > nb) {
            return (0);
        }
    }
    return (temp);
}
