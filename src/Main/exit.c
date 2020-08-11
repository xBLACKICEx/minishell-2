/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** exit
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

int shell_exit(char **cmds, data_t *data)
{
    if ((*cmds) != NULL && my_strcmp(cmds[0], "exit") == 0) {
        if (my_strlentab(cmds) > 1) {
            my_printerr("exit: Expression Syntax.\n");
            return -1;
        } else {
            free_array(cmds), (cmds) = NULL;
            free_minishell_data(data), data = NULL;
            exit(0);
        }
    }
    return 0;
}