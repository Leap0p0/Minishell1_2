/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

int double_redirection(char *path, global_t *global)
{
    int pid;
    char **cmd = NULL;

    cmd = split_path(global->cmd_redi, " \n\t");
    cmd = search_bin(cmd, global->env);
    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0) {
        int file = open(path, O_WRONLY | O_CREAT | O_APPEND , 0644);
        if (file == -1)
            return (-1);
        dup2(file, STDOUT_FILENO);
        my_cmd(cmd, global->env, global);
        cdm_bin_pipe(cmd);
        close(file);
    }
    free_array(cmd);
    return (0);
}

int redirection(char *path, global_t *global)
{
    int pid;
    char **cmd = NULL;

    cmd = split_path(global->cmd_redi, " \n\t");
    cmd = search_bin(cmd, global->env);
    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0) {
        int file = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (file == -1)
            return (-1);
        dup2(file, STDOUT_FILENO);
        my_cmd(cmd, global->env, global);
        cdm_bin_pipe(cmd);
        close(file);
    }
    free_array(cmd);
    return (0);
}

int start_redirection(global_t *global)
{
    global->redi = 0;
    global->db_redi = 0;
    global->current_redi = 0;
    parse_redirection(global);
    if (global->redi == 1)
        redirection(global->path_redi, global);
    else if (global->db_redi == 1)
        double_redirection(global->path_redi, global);
    else {
        free(global->cmd_redi);
        free(global->path_redi);
        return (84);
    }
    free(global->cmd_redi);
    free(global->path_redi);
    return (0);
}
