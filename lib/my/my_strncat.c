/*
** EPITECH PROJECT, 2021
** str_ncat
** File description:
** lea_pollet
*/

int my_strlen_strncat(char const *str)
{
    int i = 0;
    int caract = 0;

    do {
        caract = str[i];
        i++;
    } while (caract != '\0');
    i--;
    return (i);
}

char *my_strncat(char *dest , char const *src , int nb)
{
    int length = my_strlen_strncat(dest);
    int i = 0;

    while (src[i] && i < nb) {
        dest[length + i] = src[i];
        i++;
    }
    dest[length + i] = '\0';
    return (dest);
}
