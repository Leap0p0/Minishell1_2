/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void init_struct(global_t *global)
{
    global->current_lent = 0;
    global->current_line = 0;
    global->count_separator = 0;
    global->separator = 0;
    global->pipe = 0;
    global->current_separator = 0;
    global->redi = 0;
    global->db_redi = 0;
    global->current_redi = 0;
    global->current_pipe = 0;
    global->line_of_search = -1;
}

void check_possibilities(global_t *global)
{
    if (check_sperator(global->buffer) == 0)
        separator(global);
    else {
        if (check_pipe(global->buffer) == 0)
            go_pipe(global);
        else if (check_redirection(global->buffer) == 0)
            start_redirection(global);
        if (check_null(global->buffer) == 0 &&
        check_redirection(global->buffer) != 0 &&
        check_pipe(global->buffer) != 0)
            start(global, global->buffer);
        write(1, "$> ", 3);
    }
}

void loop(int ac, char **av, global_t *global)
{
    size_t size = 2000;

    write(1, "$> ", 3);
    while (getline(&global->buffer, &size, stdin) > 0) {
        check_possibilities(global);
    }
}

int main(int ac, char **av, char **env)
{
    size_t size = 2000;
    global_t *global = malloc(sizeof(global_t));

    if (global == NULL) {
        perror("Malloc");
        return (84);
    }
    init_struct(global);
    global->buffer = my_malloc(global->buffer, size);
    copy_env(env, global);
    loop(ac, av, global);
    general_free(global);
    my_putstr("\nexit");
    my_putchar('\n');
    return (0);
}
