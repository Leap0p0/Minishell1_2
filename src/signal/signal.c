/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

void do_reverse_fork(global_t *global, char **cmd_two, int pipefd[2])
{
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    my_cmd(cmd_two, global->env, global);
    cdm_bin_pipe(cmd_two);
}

void do_fork(global_t *global, char **cmd, int pipefd[2])
{
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    my_cmd(cmd, global->env, global);
    cdm_bin_pipe(cmd);
}
