/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils7
*/

#include <minishell.h>

char esc_char_conver(char *s)
{
    if (s == NULL) return '\0';
    char c = *s;

    if (c == '"') c = '"';
    if (c == 'a') c = '\a';
    if (c == 'b') c = '\b';
    if (c == 't') c = '\t';
    if (c == 'n') c = '\n';
    if (c == 'v') c = '\v';
    if (c == 'f') c = '\f';
    if (c == 'r') c = '\r';
    if (c == '\'') c = '\'';
    if (c == '\0') c = '\0';
    if (c == '\\') c = '\\';
    *s = c;
    return c;
}

bool is_char_conver(char *s)
{
    if (s == NULL) return false;
    char c = *s;

    if (c == '"') return true;
    if (c == 'a') return true;
    if (c == 'b') return true;
    if (c == 't') return true;
    if (c == 'n') return true;
    if (c == 'v') return true;
    if (c == 'f') return true;
    if (c == 'r') return true;
    if (c == '\'') return true;
    if (c == '\0') return true;
    if (c == '\\') return true;
    return false;
}