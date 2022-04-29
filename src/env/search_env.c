/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

char *take_path(global_t *global, char *path)
{
    int i = 0;
    int k = 0;

    while (global->env[global->line_of_search][i] != '=')
        i++;
    i++;
    while (global->env[global->line_of_search][i] != '\0') {
        path[k] = global->env[global->line_of_search][i];
        k++;
        i++;
    }
    path[k] = '\0';
    global->current_len = my_strlen(path);
    return (path);
}

char *path_env(char *cmp, global_t *global, int j, int i)
{
    while (global->env[i][j] != '\0') {
        if (global->env[i][j] == '=')
            break;
        else
            cmp[j] = global->env[i][j];
        j++;
    }
    cmp[j] = '\0';
    return (cmp);
}

int search_in_env(char *path, global_t *global)
{
    char *cmp = NULL;
    int j;
    int i = 0;

    while (global->env[i]) {
        cmp = my_malloc(cmp, my_strlen(global->env[i]) + 1);
        j = 0;
        cmp = path_env(cmp, global, j, i);
        if (my_strcmp(cmp, path) == 0) {
            free(cmp);
            global->line_of_search = i;
            return (0);
        }
        free(cmp);
        i++;
    }
    return (1);
}
