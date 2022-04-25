/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void new_oldpwd(global_t *global)
{
    char **cmd = malloc(sizeof(char *) * 4);
    cmd[0] = malloc(sizeof(char) * (my_strlen("setenv") + 1));
    cmd[0] = "setenv";
    cmd[1] = malloc(sizeof(char) * (my_strlen("OLDPWD") + 1));
    cmd[1] = "OLDPWD";
    search_in_env("PWD", global);
    cmd[2] = malloc(sizeof(char) * 200);
    cmd[2] = take_path(global, cmd[2]);
    cmd[3] = NULL;
    set_env(global, cmd);
}

char **copy_path(char *path, char **cmd)
{
    int i = 0;
    while (path[i] != '\0') {
        cmd[2][i] = path[i];
        i++;
    }
    cmd[2][i] = '\0';
    return (cmd);
}

int replace_pwd(global_t *global)
{
    char **cmd = malloc(sizeof(char *) * 4);
    cmd[0] = malloc(sizeof(char) * (my_strlen("setenv") + 1));
    cmd[0] = "setenv";
    cmd[1] = malloc(sizeof(char) * (my_strlen("PWD") + 1));
    cmd[1] = "PWD";
    char path[256];
    if (getcwd(path, sizeof(path)) == NULL)
        return (84);
    cmd[2] = malloc(sizeof(char) * (my_strlen(path) + 1));
    cmd = copy_path(path, cmd);
    cmd[3] = NULL;
    set_env(global, cmd);
    return (0);
}
