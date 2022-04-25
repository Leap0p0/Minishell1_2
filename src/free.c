/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void general_free(global_t *global)
{
    free(global->buffer);
    free_array(global->env);
    free(global);
}