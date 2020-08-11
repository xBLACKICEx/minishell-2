/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utile1
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool jmp_single_quote(char const *c, int *i)
{
    if (c[*i] == '\'') {
        for ((*i)++; c[*i] != '\0' && c[*i] != '\''; (*i)++)
            if (c[*i] == '\\' && (c[*i + 1] == '\'')) ++*i;
        if (c[*i] == '\0') (*i)--;
        return true;
    }
    return false;
}

bool jmp_double_quote(char const *c, int *i)
{
    if (c[*i] == '"') {
        for ((*i)++; c[*i] != '\0' && c[*i] != '"'; (*i)++)
            if (c[*i] == '\\' && (c[*i + 1] == '"')) ++*i;
        if (c[*i] == '\0') (*i)--;
        return true;
    }
    return false;
}

bool jmp_brackets(char const *c, int *i)
{
    if (c[*i] == '(') {
        for ((*i)++; c[*i] != '\0' && c[*i] != ')'; (*i)++);
        if (c[*i] == '\0') (*i)--;
        return true;
    }
    return false;
}

bool jmp_quotes(char const *c, int *i)
{
    if (c[*i] == '"' || c[*i] == '\'' || c[*i] == '(') {
        if (jmp_double_quote(c, i)) return true;
        if (jmp_single_quote(c, i)) return true;
        if (jmp_brackets(c, i)) return true;
        return true;
    }
    return false;
}
