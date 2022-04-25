/*
** EPITECH PROJECT, 2021
** alpha is upper
** File description:
** lea_pollet
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
