/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

int check_pars_of_pipe(char *first, char *second, char **cmd, char **cmd_two)
{
    if (check_parsing(cmd, first) == -1 ||
    check_parsing(cmd_two, second) == -1) {
        do_free_pipe(cmd, cmd_two, first, second);
        return (84);
    }
    return (0);
}

int check_of_pipe(char *first, char *second)
{
    if (check_null(first) == 1 || check_null(second) == 1 ||
    my_strlen(first) < 1 || my_strlen(second) < 1) {
        my_putstr("Invalid null command.\n");
        return (84);
    }
    return (0);
}

void *my_malloc(void *var, int size)
{
    var = malloc(size);

    if (var == NULL)
        exit(84);
    return var;
}
