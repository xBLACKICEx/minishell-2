/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** luanch
*/

#include <get_next_line.h>
#include <minishell.h>
#include <my_printf.h>
#include <my_printf_tools.h>
#include <my_tools.h>

int luanch(char ***cmd, data_t *data)
{
    int e = 0, pid = 0, status = 0;

    if (open((*cmd[0]), O_RDONLY) != -1 && check_permisstion((*cmd[0]))) {
        free_array((*cmd)), (*cmd) = NULL;
        return 84;
    }
    if (data->in_pipe)
        e = exect_binary((*cmd), data, no_fork);
    else if ((pid = fork() == 0)) {
        e = exect_binary((*cmd), data, no_fork);
        free_array((*cmd)), (*cmd) = NULL;
        free_minishell_data(data);
        exit(e);
    } else {
        waitpid(pid, &status, 0);
        check_segfout(status);
        free_array((*cmd)), (*cmd) = NULL;
        return WEXITSTATUS(status);
    }
    free_array((*cmd)), (*cmd) = NULL;
    return e;
}

int luanch_cmd(char ***cmd, data_t *data, int (*excut)())
{
    remove_cmds_quotes((*cmd));
    if ((*cmd) == NULL) return 0;
    int i = 0, pid = 0, status = 0, e = 0;
    char *cd[] = {"cd", "cd-", "setenv", "unsetenv", "exit", NULL};
    FPR_t fptr[] = {my_cd, my_cd, my_setenv, my_unsetenv, shell_exit};

    for (; cd[i] != NULL && my_strcmp((*cmd)[0], cd[i]) != 0; i++);
    if (i < 5) {
        e = fptr[i]((*cmd), data);
        free_array((*cmd)), (*cmd) = NULL;
        return e;
    } else
        return luanch(cmd, data);
}

int select_lauch_type(char ***cmds, data_t *data, int (*excut)())
{
    int e = 0;

    if ((*cmds) != NULL) e = my_pipe(cmds, data);
    if ((*cmds) != NULL) e = redirection(cmds, data, excut);
    if ((*cmds) != NULL) e = luanch_cmd(cmds, data, excut);
    return e;
}