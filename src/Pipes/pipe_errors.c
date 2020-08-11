/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe_error
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool pipe_is_error(char ***cmd)
{
    if (my_strcmp((*cmd)[my_strlentab((*cmd)) - 1], "|") == 0) {
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        my_printerr("Invalid null command.\n");
        return true;
    }
    return false;
}