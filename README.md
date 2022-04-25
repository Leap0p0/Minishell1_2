# Minishell 1 + 2

L'objectif de Minishell est de créer un shell.

Plusieurs built-in ont été demandés :  

* ## Setenv & Unsetenv
Ajouter ou enlever des *variables d'environnements*
* ## Cd
Coder la fonction cd 
* ## env
Afficher l'env
* ## exit
Quitter le shell en tapant "exit" ou en effectuant CTRL + D

# Structure utilisé

```C
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
```

Pour lancer le programme : 

```bash
make
./mysh
```