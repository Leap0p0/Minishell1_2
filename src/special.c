/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void do_exit(char **cmd, global_t *global)
{
    if (cmd[1] == NULL) {
        free_array(cmd);
        general_free(global);
        exit(0);
    } else {
        if (cmd[2] == NULL) {
            free_array(cmd);
            general_free(global);
            my_putstr("exit");
            exit(strtoi(cmd[1]));
        } else {
            my_putstr("mysh: exit: ");
            my_putstr(cmd[2]);
            my_putstr(": Expression syntax.\n");
        }
    }
}

int look_env(char **env, char **cmd)
{
    int i = 0;
    if (count_line(cmd) > 1)
        return 84;
    while (env[i]) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}

int cd_home(char **env)
{
    char *path = my_getenv("HOME", env);

    if (chdir(path) == -1) {
        perror("cd");
        return (-1);
    }
    return (0);
}
