/*
** EPITECH PROJECT, 2021
** square
** File description:
** root
*/

#include "./../include/my.h"
#include "./../include/pus.h"

void free_array(char **array)
{
    int i = 0;

    while (array[i]) {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    free(array);
    array = NULL;
}

char **split_path(char *raw_cmd, char *limit)
{
    char *ptr = NULL;
    char **cmd = malloc(sizeof(char *) * (50));
    size_t idx = 0;

    ptr = strtok(raw_cmd, limit);
    while (ptr) {
        cmd[idx] = my_strdup(ptr);
        ptr = strtok(NULL, limit);
        idx++;
    }
    cmd[idx] = NULL;
    free(ptr);
    return (cmd);
}

char *search_path(char *bin, char **path_split, char **cmd)
{
    int size;
    for (int i = 0; path_split[i]; i++) {
        size = my_strlen(path_split[i]) + my_strlen(cmd[0]) + 2;
        bin = malloc(sizeof(char) * (size));
        if (bin == NULL)
            break;
        my_strcpy(bin, path_split[i]);
        my_strcat(bin, "/");
        my_strcat(bin, cmd[0]);
        if (access(bin, F_OK) == 0) {
            return (bin);
        }
        free(bin);
        bin = NULL;
    }
    return (bin);
}

char *my_getenv(char *searched_var, char **env)
{
    int i;
    int size_var;

    if (env == NULL || env[0] == NULL)
        return (NULL);
    i = 0;
    size_var = my_strlen(searched_var) - 1;
    while (env[i] != NULL) {
        if (my_strncmp(env[i], searched_var, size_var) == 0)
            return (&env[i][size_var + 2]);
        i++;
    }
    return (NULL);
}

void get_absolute_path(char **cmd, char **env)
{
    char *path = my_strdup(my_getenv("PATH", env));
    char *bin = NULL;
    char **path_split = NULL;

    if (path == NULL)
        path = my_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
    if (cmd[0][0] != '/' && my_strncmp(cmd[0], "./", 2) != 0) {
        path_split = split_path(path, ":");
        free(path);
        path = NULL;
        bin = search_path(bin, path_split, cmd);
        free_array(path_split);
        free(cmd[0]);
        cmd[0] = bin;
    } else {
        free(path);
        path = NULL;
    }
}
