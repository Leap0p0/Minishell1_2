/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** lea_pollet
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i]) {
        i = i + 1;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        return (0);
    } else {
        return (s1[i] - s2[i]);
    }
}
