/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../../include/my.h"
#include "./../../include/pus.h"

int my_puterrorcd(char *str, char *path)
{
    my_putstr(path);
    my_putstr(":");
    my_putstr(" ");
    my_putstr(str);
    my_putstr("\n");
    return (84);
}

int error_of_cd(char *path)
{
    if (access(path, F_OK) == -1)
        return (my_puterrorcd("No such file or directory.", path));
    if (access(path, F_OK) == 0)
        return (my_puterrorcd("Not a directory.", path));
    if (access(path, R_OK) == -1)
        return (my_puterrorcd("Permission denied.", path));
    return (84);
}

int last_cd(global_t *global)
{
    search_in_env("OLDPWD", global);
    char *path = NULL;
    path = my_malloc(path, my_strlen(global->env[global->line_of_search]));

    path = take_path(global, path);
    if (chdir(path) == -1) {
        error_of_cd(path);
        return (-1);
    }
    free(path);
    new_oldpwd(global);
    replace_pwd(global);
    return (0);
}

int do_cd(char *path, char **env, global_t *global)
{
    if (path == NULL)
        return (cd_home(env));
    if (my_strcmp(path, "-") == 0) {
        last_cd(global);
        return (0);
    }
    if (chdir(path) == -1) {
        error_of_cd(path);
        return (-1);
    }
    new_oldpwd(global);
    replace_pwd(global);
    return (0);
}
