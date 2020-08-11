/*
** EPITECH PROJECT, 2019
** my_str
** File description:
** my_str
*/

#include <my_printf_tools.h>

void pchar_i(int c)
{
    write(MYSTDOUT, &c, 1);
}

void pchar_w(wint_t c)
{
    write(MYSTDOUT, &c, 1);
}

void pstr_c(char *str)
{
    int i = 0;

    if (str == NULL) {
        write(MYSTDOUT, "(null)", 6);
        return;
    }
    for (; str[i] != '\0'; i++);
    write(MYSTDOUT, str, i);
}

void pstr_w(wchar_t *str)
{
    int i = 0;

    if (str == NULL) {
        write(MYSTDOUT, "(null)", 6);
        return;
    }
    for (; str[i] != '\0'; i++);
    write(MYSTDOUT, str, i);
}