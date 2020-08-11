/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cd_error
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

int cd_is_error(char **cmd, data_t *data)
{
    if (my_strlentab(cmd) > 2) {
        write(1, "cd: Too many arguments.\n", 25);
        return true;
    }
    if (data->home == NULL) {
        if (my_strlentab(cmd) == 1)
            my_printf("cd: No home directory.\n");
        if (my_strlentab(cmd) == 2 && cmd[1][0] == '~')
            my_printf("No $home variable set.\n");
        return true;
    }
    return false;
}