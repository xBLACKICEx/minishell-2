/*
** EPITECH PROJECT, 2019
** my_str
** File description:
** my_str
*/

#include <my_tools.h>
#include <my_printf_tools.h>

void sp_pstr_c(char *str)
{
    if (str == NULL) {
        write(MYSTDOUT, "(null)", 7);
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            char *octal = bnm_l(str[i], "01234567");
            int len = my_strlen(octal);

            write(MYSTDOUT, "\\", 1);
            if (len == 1)
                write(MYSTDOUT, "00", 2);
            if (len == 2)
                write(MYSTDOUT, "0", 1);
            write(MYSTDOUT, octal, len);
            free (octal);
    } else
        write(MYSTDOUT, &str[i], 1);
    }
}

void sp_pstr_w(wchar_t *str)
{
    if (str == NULL) {
        write(MYSTDOUT, "(null)", 7);
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            char *octal = bnm_l(str[i], "01234567");
            int len = my_strlen(octal);

            write(MYSTDOUT, "\\", 1);
            if (len == 1)
                write(MYSTDOUT, "00", 2);
            if (len == 2)
                write(MYSTDOUT, "0", 1);
            write(MYSTDOUT, octal, len);
            free (octal);
    } else
        write(MYSTDOUT, &str[i], 1);
    }
}