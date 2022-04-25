/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void copy_env(char **env, global_t *global)
{
    int nb = count_line(env);
    int i = 0;
    int j = 0;
    global->env = malloc(sizeof(char *) * (nb + 2));
    while (env[i]) {
        global->env[i] = malloc(sizeof(char) * my_strlen(env[i]) + 300);
        j = 0;
        while (env[i][j] != '\0') {
            global->env[i][j] = env[i][j];
            j++;
        }
        global->env[i][j] = '\0';
        i++;
    }
    global->env[i] = NULL;
    global->current_line = i;
}

void copy_name(global_t *global, char **cmd)
{
    int i = 0;
    global->name = malloc(sizeof(char) * (my_strlen(cmd[1]) + 1));
    while (cmd[1][i] != '\0') {
        global->name[i] = cmd[1][i];
        i++;
    }
    global->name[i] = '\0';
}

int check_first_char(char **cmd)
{
    if (cmd[1][0] < 'a' || cmd[1][0] > 'z') {
        if (cmd[1][0] < 'A' || cmd[1][0] > 'Z'){
            my_putstr(cmd[0]);
            my_putstr(": Variable name must begin with a letter.\n");
            return (84);
        } else
            return (0);
    }
}

int set_env(global_t *global, char **cmd)
{
    int nb = count_line(cmd);
    if (nb < 2 || nb > 3)
        return (84);
    if (check_first_char(cmd) == 84)
        return (84);
    if (search_in_env(cmd[1], global) == 0)
        modif_env(global, cmd);
    else
        new_env(global, cmd);
    return (0);
}

int unset_env(global_t *global, char **cmd)
{
    int nb = count_line(cmd);
    if (nb != 2)
        return (84);
    if (check_path(cmd[1]) == 1)
        return (84);
    if (search_in_env(cmd[1], global) == 0) {
        change_env(global);
        global->current_line--;
    } else
        return (84);
    return (0);
}
