/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** lea_pollet
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int length = my_strlen(str) + 1;
    char *result = malloc(length);

    if (result == NULL) {
        return (NULL);
    }
    my_strcpy(result, str);
    result[length - 1] = '\0';
    return (result);
    free(result);
}
