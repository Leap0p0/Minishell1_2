/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** lea_pollet
*/

int my_strlen_rev(char const *str)
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

char *my_revstr(char *str)
{
    char temp;
    int i = 0;
    int length = my_strlen_rev(str) - 1;

    while ( i <= length / 2) {
        temp = str[i];
        str[i] = str[length - i];
        str[length - i] = temp;
        i += 1;
    }
    return (str);
}
