/*
** EPITECH PROJECT, 2019
** new
** File description:
** tools
*/

#include <my_printf_tools.h>
#include <my_printf.h>

void put_witdh_zero(long long nb, flags_t *flag, int len)
{
    if (flag->width > 0)
        for (int i = 0; i < ABS(len - flag->width); i++)
            write(MYSTDOUT, " ", 1);
    if (flag->zero > 0 && flag->n == 0)
        for (int i = 0; i < ABS(len - flag->zero); i++)
            write(MYSTDOUT, "0", 1);
    if (flag->zero > 0 && flag->n > 0)
        for (int i = 0; i < ABS(len - flag->zero); i++)
            write(MYSTDOUT, " ", 1);
}