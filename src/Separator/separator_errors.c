/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** separator_error
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool quet_is_error(char *s, char q)
{
    if (s == NULL) return true;

    if (s[0] == q && s[my_strlen(s) - 1] != q) {
        my_printf("Unmatched '%c'.\n", q);
        return true;
    }
    return false;
}

bool brakets_is_error(char *s)
{
    if (s == NULL) return true;

    if (s[0] == '(' && s[my_strlen(s) - 1] != ')') {
        my_printerr("Too many ('s.\n");
        return true;
    } else if (my_strcmp2(s, ")") == 0) {
        my_printerr("Too many )'s.\n");
        return true;
    }
    return false;
}

bool mache_brakes_is_error(char *s)
{
    if (s == NULL) return NULL;
    if (quet_is_error(s, '"'))
        return true;
    if (quet_is_error(s, '\''))
        return true;
    if (brakets_is_error(s))
        return true;
    return false;
}

bool separator_is_error(char ***cmds)
{
    char *tab[] = {"&&", "||", "|", "<", "<<", ">", ">>", ">", NULL};

    if (my_strcmp2((*cmds)[0], "||") == 0) {
        my_printerr("Invalid null command.\n");
        return true;
    }
    for (int i = 0; (*cmds)[i] != NULL; i++) {
        if (my_strcmptab((char *[]){"&&", "||", NULL}, (*cmds)[i]))
            if (my_strcmptab(tab, (*cmds)[i + 1])) {
                if ((*cmds) != NULL) free_array((*cmds)), (*cmds) = NULL;
                my_printerr("Invalid null command.\n");
                return true;
            }
        if (mache_brakes_is_error((*cmds)[i])) {
            if ((*cmds) != NULL) free_array((*cmds)), (*cmds) = NULL;
            return true;
        }
    }
    return false;
}