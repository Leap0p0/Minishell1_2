/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void take_cmd(global_t *global)
{
    int i = 0;
    int k = 0;

    global->cmd_redi = my_malloc(global->cmd_redi, my_strlen(global->buffer));
    while (global->buffer[i] != '\0') {
        if (global->buffer[i] == '>')
            break;
        else {
            global->cmd_redi[k] = global->buffer[i];
            k++;
            i++;
        }
    }
    global->cmd_redi[k] = '\0';
}

void check_file(global_t *global)
{
    int i = global->current_redi;
    int k = 0;

    global->path_redi =
    my_malloc(global->path_redi, my_strlen(global->buffer));
    while (global->buffer[i] != '\0') {
        if (global->buffer[i] == '\n')
            break;
        if (global->buffer[i] == ' ')
            i++;
        else {
            global->path_redi[k] = global->buffer[i];
            i++;
            k++;
        }

    }
    global->path_redi[k] = '\0';
}
