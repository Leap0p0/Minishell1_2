/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** lea_pollet
*/

#ifndef PUS_
    #define PUS_

    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/wait.h>

typedef struct global {
    char *buffer;
    char **env;
    int current_line;
    int current_separator;
    int line_of_search;
    int separator;
    int count_separator;
    int current_len;
    int line_redi;
    int current_lent;
    char *name;
} global_t;
//array.c
void free_array(char **array);
char **split_path(char *raw_cmd, char *limit);
char *search_path(char *bin, char **path_split, char **cmd);
char *my_getenv(char *searched_var, char **env);
void get_absolute_path(char **cmd, char **env);
//build_cd.c
int my_puterrorcd(char *str, char *path);
int error_of_cd(char *path);
int last_cd(global_t *global);
int do_cd(char *path, char **env, global_t *global);
//build_cd.c
char **search_bin(char **cmd, char **env);
void my_cmd(char **cmd, char **env, global_t *global);
void cdm_bin(char **cmd);
//main.c
void init_struct(global_t *global);
void loop(int ac, char **av, global_t *global);
int main(int ac, char **av, char **env);
//pwd.c
void new_oldpwd(global_t *global);
int replace_pwd(global_t *global);
//search_env.c
char *take_path(global_t *global, char *path);
char *path_env(char *cmp, global_t *global, int j, int i);
int search_in_env(char *path, global_t *global);
//set_env.c
void copy_env(char **env, global_t *global);
void copy_name(global_t *global, char **cmd);
int set_env(global_t *global, char **cmd);
int unset_env(global_t *global, char **cmd);
//special.c
void do_exit(char **cmd, global_t *global);
int look_env(char **env, char **cmd);
int cd_home(char **env);
//start.c
void exec_cmd_bis(char **cmd);
void exec_cmd(char **cmd);
void start(global_t *global, char *buffer);
//utils.c
int count_line(char **tab);
void change_env(global_t *global);
void new_env(global_t *global, char **cmd);
void modif_env(global_t *global, char **cmd);
int check_path(char *path);
//separator.c
void reassemble(global_t *global, char *str);
int do_separator(global_t *global);
void separator(global_t *global);
//utils_separator.c
int check_sperator(char *path);
void count_sperator(char *path, global_t *global);
int check_null(char *path);
//free.c
void general_free(global_t *global);
//pipe.c
void do_pipe(global_t *global, char *str, char *str_bis);
#endif/* PUS */
