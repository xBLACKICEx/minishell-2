/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** minishell_structre
*/

#ifndef MINISHELL_STRUCTRE_H_
#define MINISHELL_STRUCTRE_H_

typedef struct minishell_structre data_t;
typedef int (*FPR_t)(char **cmd, data_t *);

typedef struct s_alis
{
    char *name;
    char *cmd;
}alias_t;

struct minishell_structre
{
    char *home;
    char *oldpwd;
    char *get;
    pid_t pid;
    size_t size;
    ssize_t ssize;
    int error;
    char **env;
    char **denv;
    char **path;
    char **usr;
    char **cmds;
    bool in_pipe;
    dlist_t *list;
    dlist_t *l_als;
};

#endif /* !MINISHELL_STRUCTRE_H_ */
