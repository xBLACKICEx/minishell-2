/*
** EPITECH PROJECT, 2020
** PSU_minishell1 (工作区)
** File description:
** minishell_error
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_printf_tools.h>
#include <my_tools.h>

bool check_permisstion(char *str)
{
    struct stat cheak;

    lstat(str, &cheak);
    if (S_ISDIR(cheak.st_mode) != 0) {
        my_printf("%s: Permission denied.\n", str);
        return (true);
    }
    return (false);
}

int check_segfout(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8 && WCOREDUMP(status))
            my_printf("Floating exception (core dumped)\n");
        if (WTERMSIG(status) == 4 && (WCOREDUMP(status)))
            my_printf("Illegal instruction (core dumped)\n");
        if (WTERMSIG(status) == 11 && WCOREDUMP(status))
            my_printf("Segmentation fault (core dumped)\n");
        if (WTERMSIG(status) == 6 && (WCOREDUMP(status)))
            my_printf("Aborted (core dumped)\n");
        if (WTERMSIG(status) == 8 && !(WCOREDUMP(status)))
            my_printf("Floating exception\n");
        if (WTERMSIG(status) == 4 && !(WCOREDUMP(status)))
            my_printf("Illegal instruction\n");
        if (WTERMSIG(status) == 11 && !(WCOREDUMP(status)))
            my_printf("Segmentation fault\n");
        if (WTERMSIG(status) == 6 && !(WCOREDUMP(status)))
            my_printf("Aborted\n");
        return (1);
    } else return 0;
}