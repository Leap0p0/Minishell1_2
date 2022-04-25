/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

int check_sperator(char *path)
{
    int i = 0;
    while (path[i] != '\0') {
        if (path[i] == ';')
            return (0);
        i++;
    }
    return (1);
}

void count_sperator(char *path, global_t *global)
{
    int i = 0;
    while (path[i] != '\0') {
        if (path[i] == ';')
            global->separator += 1;
        i++;
    }
}

int check_null(char *path)
{
    int i = 0;
    while (path[i] != '\0') {
        if (path[i] == '\t' || path[i] == '\n' || path[i] == ' ')
            i++;
        else {
            return (0);
        }
    }
    return (1);
}
