/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

char **search_bin(char **cmd, char **env)
{
    if (my_strcmp(cmd[0], "cd") != 0
        && my_strcmp(cmd[0], "exit") != 0
        && my_strcmp(cmd[0], "setenv") != 0
        && my_strcmp(cmd[0], "unsetenv") != 0
        && my_strcmp(cmd[0], "env") != 0)
        get_absolute_path(cmd, env);
    return (cmd);
}

void my_cmd(char **cmd, char **env, global_t *global)
{
    if (my_strcmp(cmd[0], "cd") == 0)
        do_cd(cmd[1], env, global);
    if (my_strcmp(cmd[0], "exit") == 0)
        do_exit(cmd, global);
    if (my_strcmp(cmd[0], "env") == 0
    && count_line(cmd) == 1)
        look_env(env, cmd);
    if (my_strcmp(cmd[0], "setenv") == 0)
        set_env(global, cmd);
    if (my_strcmp(cmd[0], "unsetenv") == 0)
        unset_env(global, cmd);
}

void cdm_bin(char **cmd)
{
    if (my_strcmp(cmd[0], "cd") != 0
        && my_strcmp(cmd[0], "exit") != 0
        && my_strcmp(cmd[0], "setenv") != 0
        && my_strcmp(cmd[0], "unsetenv") != 0
        && my_strcmp(cmd[0], "env") != 0)
        exec_cmd(cmd);
}
