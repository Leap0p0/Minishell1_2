/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

int check_path(char *path)
{
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == '*')
            return (1);
        i++;
    }
    return (0);
}

int count_line(char **tab)
{
    int i = 0;
    int nb = 0;
    while (tab[i]) {
        nb++;
        i++;
    }
    return (nb);
}

void change_env(global_t *global)
{
    int i = 0;
    int k;
    for (; i < global->line_of_search; i++);
    k = i;
    i++;
    while (global->env[i]) {
        global->env[k] = global->env[i];
        k++;
        i++;
    }
    global->env[k] = NULL;
}

void new_env(global_t *global, char **cmd)
{
    int len;
    if (count_line(cmd) >= 3)
        len = my_strlen(cmd[1]) + my_strlen(cmd[2]) + 1;
    else
        len = my_strlen(cmd[1]) + 2;
    global->current_lent = my_strlen(cmd[1]);
    global->env[global->current_line] = malloc(sizeof(char) * (len + 1));
    copy_name(global, cmd);
    global->env[global->current_line] =
    my_strcpy(global->env[global->current_line], cmd[1]);
    my_strcat(global->env[global->current_line], "=");
    if (cmd[2] != NULL)
        my_strcat(global->env[global->current_line], cmd[2]);
    global->current_line++;
    global->env[global->current_line] = NULL;
    free(global->name);
}

void modif_env(global_t *global, char **cmd)
{
    int j = 0;
    int k = 0;

    while (global->env[global->line_of_search][j] != '=')
        j++;
    if (cmd[2] != NULL) {
        j++;
        while (k != my_strlen(cmd[2])) {
            global->env[global->line_of_search][j] = cmd[2][k];
            k++;
            j++;
        }
    }
    global->env[global->line_of_search][j] = '\0';
}
