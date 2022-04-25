/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** lea_pollet
*/

#include <stdlib.h>

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[k] != '\0') {
        i = k;
        while (str[i] != '\0' && str[i] == to_find[j]) {
            i++;
            j++;
        }
        if (to_find[j] == '\0') {
            return (str);
        }
        j = 0;
        k++;
    }
    return NULL;
}
