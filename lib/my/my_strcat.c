/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** lea_pollet
*/

int my_strlen_strcat(char const *str)
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

char *my_strcat(char *dest , char const *src)
{
    int length = my_strlen_strcat(dest);
    int i = 0;

    while (src[i]) {
        dest[length + i] = src[i];
        i++;
    }
    dest[length + i] = '\0';
    return (dest);
}
