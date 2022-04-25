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
    global->current_separator = 0;
    global->line_of_search = -1;
}

void loop(int ac, char **av, global_t *global)
{
    size_t size = 2000;

    write(1, "$> ", 3);
    while (getline(&global->buffer, &size, stdin) > 0) {
        if (check_sperator(global->buffer) == 0)
            separator(global);
        else {
            start(global, global->buffer);
            write(1, "$> ", 3);
        }
    }
}

int main(int ac, char **av, char **env)
{
    size_t size = 2000;
    global_t *global = malloc(sizeof(global_t));

    init_struct(global);
    global->buffer = malloc(sizeof(char) * size);
    if (global->buffer == NULL) {
        perror("Malloc");
        return (84);
    }
    copy_env(env, global);
    loop(ac, av, global);
    my_putstr("\nexit");
    my_putchar('\n');
    general_free(global);
    return (0);
}
