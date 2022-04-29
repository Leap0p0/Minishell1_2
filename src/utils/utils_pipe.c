/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

int check_parsing(char **cmd, char *path)
{
    if (cmd[0] == NULL) {
        my_putstr(path);
        my_putstr(": Command not found.\n");
        return (-1);
    }
    return (0);
}

int check_pipe(char *path)
{
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == '|')
            return (0);
        i++;
    }
    return (1);
}

void count_pipe(char *path, global_t *global)
{
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == '|')
            global->pipe += 1;
        i++;
    }
}

void exec_cmd_pipe(char **cmd)
{
    if (execve(cmd[0], cmd, NULL) == -1) {
        perror("shell");
        exit(84);
    }
}

void cdm_bin_pipe(char **cmd)
{
    if (my_strcmp(cmd[0], "cd") != 0
        && my_strcmp(cmd[0], "exit") != 0
        && my_strcmp(cmd[0], "setenv") != 0
        && my_strcmp(cmd[0], "unsetenv") != 0
        && my_strcmp(cmd[0], "env") != 0)
        exec_cmd_pipe(cmd);
}
