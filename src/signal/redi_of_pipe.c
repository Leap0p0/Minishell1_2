/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

int double_redi_pipe(char *path, global_t *global, char **cmd, char **cmd_two)
{
    int pid;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0) {
        int file = open(path, O_WRONLY | O_CREAT | O_APPEND , 0644);
        if (file == -1)
            return (-1);
        dup2(file, STDOUT_FILENO);
        do_pipe(global, cmd, cmd_two);
        close(file);
    }
    return (0);
}

int redi_pipe(char *path, global_t *global, char **cmd, char **cmd_two)
{
    int pid;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0) {
        int file = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (file == -1)
            return (-1);
        dup2(file, STDOUT_FILENO);
        do_pipe(global, cmd, cmd_two);
        close(file);
    }
    return (0);
}

int start_redi_pipe(global_t *global, char **cmd, char **cmd_two)
{
    global->redi = 0;
    global->db_redi = 0;
    global->current_redi = 0;
    parse_redirection(global);
    if (global->redi == 1)
        redi_pipe(global->path_redi, global, cmd, cmd_two);
    else if (global->db_redi == 1)
        double_redi_pipe(global->path_redi, global, cmd, cmd_two);
    else {
        free(global->cmd_redi);
        free(global->path_redi);
        return (84);
    }
    free(global->cmd_redi);
    free(global->path_redi);
    return (0);
}
