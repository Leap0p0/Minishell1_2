/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

int check_redirection(char *path)
{
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == '>')
            return (0);
        i++;
    }
    return (1);
}

int search_redi(global_t *global, int i)
{
    if (global->buffer[i] == '>') {
        if (global->buffer[i + 1] != '>') {
            global->current_redi = i + 1;
            global->redi = 1;
            return (1);
        } else {
            global->current_redi = i + 2;
            global->db_redi = 1;
            return (1);
        }
    }
    return (0);
}

void check_nbr_redi(global_t *global)
{
    int i = global->current_redi;

    while (global->buffer[i] != '\0') {
        if (search_redi(global, i) == 1)
            break;
        i++;
    }
}

int parse_redirection(global_t *global)
{
    check_nbr_redi(global);
    check_file(global);
    take_cmd(global);
    if (check_redirection(global->path_redi) == 0 ||
    check_null(global->path_redi) == 1) {
        my_putstr("Missing name for redirect.\n");
        global->redi = 0;
        global->db_redi = 0;
        return (84);
    }
    return (0);
}
