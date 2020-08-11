/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe_utils
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

void free_pipe_tmp(char **c, char ***cmd, data_t *data, int i)
{
    for (i++; cmd[i] != NULL; i++) free_array(cmd[i]);
    free(cmd);
    free_array(c);
    free_minishell_data(data);
}