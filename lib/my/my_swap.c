/*
** EPITECH PROJECT, 2021
** My_swap
** File description:
** switch 2 number by pointer
*/

void my_swap(int *a, int *b)
{
    int temporary = *a;

    *a = *b;
    *b = temporary;
}
