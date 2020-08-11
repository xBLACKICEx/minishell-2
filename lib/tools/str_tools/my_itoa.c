/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_itoa
*/

#include <my_tools.h>
#include <my_printf_tools.h>
#include <stddef.h>

char *my_itoa(int nbr)
{
    unsigned int i = 1u;
    char *n = NULL, s;

    if (nbr < 0) {
        nbr *= -1;
        n = my_strncdup(n, "-", 1);
    }
    for (int tmp = nbr; (tmp /= 10) != 0; i *= 10);
    for (; i != 0; i /= 10) {
        s = (nbr / i % 10) + 48;
        n = my_strncdup(n, &s, 1);
    }
    return n;
}

double my_atof(const char *s)
{
    long double value = 0.L, factor = 1.L;
    int sign = 0, i = 0;

    if (s[i] == '-' || s[i] == '+') sign = s[i++];
    for (; (unsigned int)(s[i] - '0') < 10u; i++)
        value = value * 10 + (s[i] - '0');
    if (s[i] == '.') {
        i++;
        for (; (unsigned int)(s[i] - '0') < 10u; i++) {
            factor *= 0.1;
            value += (s[i] - '0') * factor;
        }
    }
    return (sign == '-' ? -value : value);
}

char *my_ftoa(double nbr, int size)
{
    long long d = nbr, i = 0;
    int len = base_len(d, "0123456789"), t = 0, s = 1;
    char *num = malloc(sizeof(char *) * (len + size + 2));
    nbr = nbr - (long long)nbr;

    for (int i = 1; i < len; i++, s *= 10);
    for (t = 0; s != 0; d %= s, s /= 10) num[t++] = d / s + 48;
    num[t++] = '.';
    for (int i = 0; i < size; i++) {
        nbr = dmod(nbr, 1) * 10;
        num[t++] = nbr + 48;
    }
    num[t] = '\0';
    return num;
}