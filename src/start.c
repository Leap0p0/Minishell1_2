/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void exec_cmd_bis(char **cmd)
{
    if (execve(cmd[0], cmd, NULL) == -1) {
        perror("shell");
        exit(84);
    }
}

void exec_cmd(char **cmd)
{
    int pipefd[2];
    pid_t pid = 0;
    int status = 0;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
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

int check_redirection(char **cmd, char *dir, global_t *global)
{
    int i = 0;

    while (cmd[i]) {
        if (my_strcmp(cmd[i], dir) == 0) {
            global->line_redi = i;
            return (0);
        }
        i++;
    }
    return (1);
}

void start(global_t *global, char *buffer)
{
    char **cmd = NULL;

    if (my_strlen(buffer) != 1) {
        cmd = split_path(buffer, " \n\t");
        cmd = search_bin(cmd, global->env);
        if (cmd[0] == NULL) {
            my_putstr(buffer);
            my_putstr(": Command not found.\n");
        } else {
            my_cmd(cmd, global->env, global);
            cdm_bin(cmd);
        }
    }
    free_array(cmd);
}
