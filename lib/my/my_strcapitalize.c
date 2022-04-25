/*
** EPITECH PROJECT, 2021
** capitalize
** File description:
** lea_pollet
*/

void str_zero(char *str)
{
    if (str[0] >= 97 && str[0] <= 122) {
        str[0] = str[0] - 32;
    }
}

char *conditionnal_ascii(char *str, int i)
{
    if (str[i] <= 122 && str[i] >= 97) {
        str[i] = str[i] - 32;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    str_zero(str);
    while (str[i] != '\0') {
        if ((str[i - 1] >= 23 && str[i - 1] <= 47) || str[i - 1] <= ';') {
            str = conditionnal_ascii(str, i);
        }
        i++;
    }
    return (str);
}
