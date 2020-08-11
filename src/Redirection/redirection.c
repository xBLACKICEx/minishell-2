/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirection
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

char *get_redir_file(char **cmd, char *r)
{
    for (size_t i = 0; cmd[i] != NULL; i++)
        if (my_strcmp(cmd[i], r) == 0) return cmd[i + 1];
    return NULL;
}

char **rm_redir(char **cmd, char *r)
{
    char **tmp = malloc(sizeof(char *) * (my_strlentab(cmd)));

    for (int i = 0, j = 0; cmd[i] != NULL; i++, tmp[++j] = NULL) {
        if (my_strcmp(cmd[i], r) == 0)
            if (cmd[i + 1] != NULL)
                i += 2;
            else if (cmd[i + 1] == NULL) {
                free_array(tmp);
                return NULL;
            }
        if (cmd[i] == NULL) return tmp;
        if (cmd[i] != NULL) tmp[j] = my_strdup(cmd[i]);
    }
    return tmp;
}

void luanch_cmd_by_redir(char ***cmd, data_t *data, char *std, int (*excut)())
{
    int i = 0, w = 0, o = dup(std[1]), status = 0, n = -1;
    n = dup2(std[0], std[1]);

    data->error = select_lauch_type(cmd, data, excut);
    close(n);
    dup(o);
}

int redirection(char ***cmd, data_t *data, int (*excut)())
{
    remove_cmdsn_quotes(&(*cmd)[0], 1);
    if (my_strcmptab((*cmd), ">")) redirection_right(cmd, data, excut);
    if (my_strcmptab((*cmd), ">>")) redirection_double_right(cmd, data, excut);
    if (my_strcmptab((*cmd), "<")) redirection_left(cmd, data, excut);
    if (my_strcmptab((*cmd), "<<")) redirection_double_left(cmd, data, excut);
    return data->error;
}