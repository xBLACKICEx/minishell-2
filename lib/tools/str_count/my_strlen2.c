/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strlen2
*/

#include <my_tools.h>
#include <stddef.h>

unsigned int my_tab_num_s(char **tab, char *s)
{
    int i = 0, j = 0;

    if (tab == NULL || s == NULL) return 0;
    for (; tab[i] != NULL; i++)
        if (my_strcmp(tab[i], s) == 0) j++;
    return j;
}