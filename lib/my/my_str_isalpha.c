/*
** EPITECH PROJECT, 2021
** str is alpha or not
** File description:
** lea_pollet
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
