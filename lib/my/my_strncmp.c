/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** lea_pollet
*/

int boucle(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n) {
        i++;
    }
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    i = boucle(s1, s2, n);
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n) {
        return (0);
    } else if (s1[i] > s2[i]) {
        return (1);
    } else {
        return (-1);
    }
}
