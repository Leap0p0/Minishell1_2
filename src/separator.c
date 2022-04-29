/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void reassemble(global_t *global, char *str)
{
    int i = global->current_separator;
    int k = 0;

    while (global->buffer[i] != '\0') {
        if (global->buffer[i] == ';')
            break;
        str[k] = global->buffer[i];
        i++;
        k++;
    }
    str[k] = '\0';
    global->count_separator++;
    global->current_separator = i + 1;
}

int do_separator(global_t *global)
{
    char *str = NULL;
    str = my_malloc(str, my_strlen(global->buffer));

    reassemble(global, str);
    if (check_null(str) == 1)
        return (84);
    if (my_strlen(str) < 1)
        return (84);
    start(global, str);
    free(str);
    return (0);
}

void separator(global_t *global)
{
    global->separator = 0;
    global->count_separator = 0;
    global->current_separator = 0;
    count_sperator(global->buffer, global);
    while (global->separator + 1 != global->count_separator) {
        do_separator(global);
    }
    write(1, "$> ", 3);
}
