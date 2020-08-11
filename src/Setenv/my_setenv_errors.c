/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** errors
*/

#include <my_tools.h>
#include <my_printf.h>
#include <minishell.h>

static int my_setenv_error_case2(char **cmd);

int my_setenv_error_case(char **cmd, bool is_setenv)
{
    if (!is_setenv) {
        if (my_strlentab(cmd) == 1) {
            my_printf("unsetenv: Too few arguments.\n");
            return -1;
        }
    } else if (my_setenv_error_case2(cmd) == -1)
        return -1;
    return 0;
}

int my_setenv_error_case2(char **cmd)
{
    if (my_strlentab(cmd) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return -1;
    }
    if (my_strlentab(cmd) >= 2 && !my_char_isalpha(cmd[1][0]) &&
        cmd[1][0] != '_') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    if (my_strlentab(cmd) >= 2 && !my_str_isalphanumerics(cmd[1])) {
        my_printf("setenv: Variable name must contain alphanumeric "
                "characters.\n");
        return -1;
    }
    return 0;
}