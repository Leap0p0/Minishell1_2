/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

void do_free_pipe(char **cmd, char **cmd_two, char *first, char *second)
{
    free(first);
    free(second);
    free_array(cmd);
    free_array(cmd_two);
}

void my_free(char *path)
{
    if (path != NULL)
        free(path);
}

void general_free(global_t *global)
{
    my_free(global->buffer);
    free_array(global->env);
    free(global);
}
