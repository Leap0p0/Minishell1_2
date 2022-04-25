/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** lenght of a string
*/

int my_strlen(char const *str)
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
