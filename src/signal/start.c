/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

void exec_cmd_bis(char **cmd)
{
    if (execve(cmd[0], cmd, NULL) == -1) {
        perror("shell");
        exit(84);
    }
}

void exec_cmd(char **cmd)
{
    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == -1) {
        perror("fork");
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGKILL);
    } else {
        exec_cmd_bis(cmd);
    }
}

int start(global_t *global, char *buffer)
{
    char **cmd = NULL;

    if (my_strlen(buffer) != 1) {
        if (search_in_env("PATH", global) == 0) {
            cmd = split_path(buffer, " \n\t");
            cmd = search_bin(cmd, global->env);
        } else
            return (84);
        if (cmd[0] == NULL) {
            my_putstr(buffer);
            my_putstr(": Command not found.\n");
            free_array(cmd);
            return (-1);
        } else {
            my_cmd(cmd, global->env, global);
            cdm_bin(cmd);
        }
    }
    free_array(cmd);
    return (0);
}
