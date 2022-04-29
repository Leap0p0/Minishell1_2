/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

void do_pipe(global_t *global, char **cmd, char **cmd_two)
{
    int pipefd[2];
    int pid;
    int pid2;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        do_fork(global, cmd, pipefd);
    }
    pid2 = fork();
    if (pid2 == 0) {
        do_reverse_fork(global, cmd_two, pipefd);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid2, NULL, 0);
    waitpid(pid, NULL, 0);
}

void cmd_pipe(global_t *global, char *str)
{
    int i = global->current_pipe;
    int k = 0;

    while (global->buffer[i] != '\0') {
        if (global->buffer[i] == '|' || global->buffer[i] == '>')
            break;
        str[k] = global->buffer[i];
        i++;
        k++;
    }
    str[k] = '\0';
    global->current_pipe = i + 1;
}

char **my_split(char **cmd, char *path, global_t *global)
{
    cmd = split_path(path, " \n\t");
    cmd = search_bin(cmd, global->env);
    return (cmd);
}

int parse_pipe(global_t *global)
{
    char *first =  NULL;
    char *second = NULL;
    char **cmd = NULL;
    char **cmd_two = NULL;

    first = my_malloc(first, my_strlen(global->buffer));
    second = my_malloc(first, my_strlen(global->buffer));
    cmd_pipe(global, first);
    cmd_pipe(global, second);
    if (check_of_pipe(first, second) == 84)
        return (84);
    cmd = my_split(cmd, first, global);
    cmd_two = my_split(cmd_two, second, global);
    if (check_pars_of_pipe(first, second, cmd, cmd_two) == 84)
        return (84);
    if (check_redirection(global->buffer) == 0)
        start_redi_pipe(global, cmd, cmd_two);
    else
        do_pipe(global, cmd, cmd_two);
    do_free_pipe(cmd, cmd_two, first, second);
    return (0);
}

int go_pipe(global_t *global)
{
    global->pipe = 0;
    global->current_pipe = 0;
    count_pipe(global->buffer, global);
    if (global->pipe > 1)
        return (84);
    else
        parse_pipe(global);
    return (0);
}
