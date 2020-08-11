/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils4
*/

#include <minishell.h>
#include <my_tools.h>

unsigned int get_tab_smllen(char **tab)
{
    if (tab == NULL) return 0;
    unsigned int i = 0, j = my_strlen(tab[0]), t = 0;

    for (; tab[i] != NULL; i++) {
        t = my_strlen(tab[i]);
        if (t <= j) j = t;
    }
    return j;
}

unsigned int get_tab_str_num(char **tab, char *s)
{
    if (tab == NULL) return 0;
    unsigned int i = 0;

    for (; tab[i] != NULL &&
        my_strncmp(tab[i], s, my_strlen(tab[i])) != 0; i++);
    return i;
}

unsigned int getlenstrtab(char **tab, char *s)
{
    if (tab == NULL || s == NULL) return 0;
    int i = 0;

    for (; tab[i] != NULL &&
        my_strncmp(tab[i], s, my_strlen(tab[i])) != 0; i++);
    return my_strlen(tab[i]);
}

bool cmpstrtab(char **tab, char *s)
{
    if (tab == NULL || s == NULL) return 0;
    int i = 0;

    for (; tab[i] != NULL &&
        my_strncmp(tab[i], s, my_strlen(tab[i])) != 0; i++);
    if (tab[i] == NULL)
        return false;
    else
        return true;
}
