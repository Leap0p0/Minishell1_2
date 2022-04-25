/*
** EPITECH PROJECT, 2021
** alpha is printablle
** File description:
** lea_pollet
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 0 && str[i] <= 127) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
