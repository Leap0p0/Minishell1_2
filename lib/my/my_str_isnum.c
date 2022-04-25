/*
** EPITECH PROJECT, 2021
** str is number or not
** File description:
** lea_pollet
*/

int my_str_isnum(char *s)
{
    for (int j = 0; s[j] != '\0'; j++) {
        if ((s[j] > '9' || s[j] < '0') && (s[j] != '-' && s[j] != '+')) {
            return (84);
        }
    }
    return (0);
}
