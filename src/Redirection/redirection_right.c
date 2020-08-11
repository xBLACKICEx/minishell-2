/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirection_right
*/

#include <fcntl.h>
#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

void redirection_right(char ***cmd, data_t *data, int (*excut)())
{
    remove_cmds_quotes((*cmd));
    char **t = NULL, *file = NULL, std[2];

    if ((t = rm_redir((*cmd), ">")) == NULL) return;
    file = get_redir_file((*cmd), ">");
    if ((std[0] = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644)) >= 0) {
        std[1] = STDOUT_FILENO;
        luanch_cmd_by_redir(&t, data, std, excut);
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        free_array(t), t = NULL;
        close(std[0]);
    } else {
        my_printf("%s: %s.\n", file, strerror(errno));
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        free_array(t), t = NULL;
    }
}

void redirection_double_right(char ***cmd, data_t *data, int (*excut)())
{
    remove_cmds_quotes((*cmd));
    char **t = NULL, *file = NULL, std[2];

    if ((t = rm_redir((*cmd), ">>")) == NULL) return;
    file = get_redir_file((*cmd), ">>");
    if ((std[0] = open(file, O_CREAT | O_RDWR | O_APPEND, 0644)) >= 0) {
        std[1] = STDOUT_FILENO;
        luanch_cmd_by_redir(&t, data, std, excut);
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        free_array(t), t = NULL;
        close(std[0]);
    } else {
        my_printf("%s: %s.\n", file, strerror(errno));
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        free_array(t), t = NULL;
    }
}