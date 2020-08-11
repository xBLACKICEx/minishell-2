/*
** EPITECH PROJECT, 2020
** PSU_minishell1
** File description:
** tools0
*/

#include <my_tools.h>
#include <my_printf.h>
#include <minishell.h>

int remve_space_(const char *c)
{
    int i = 0;

    for (; (c[i] == ' ' || c[i] == '\t') && c[i] != '\0'; i++);
    return i;
}

int cat_cmds(const char *c)
{
    static int t1 = 0, t2 = 0;

    if (t1 != 0) {
        t1--;
        return 0;
    }
    if (c[t1] == '"') for (t1++; c[++t1 - 1] != '"' && c[t1 - 1] != '\0';);
    if (c[t2] == '\'') for (t2++; c[++t2 - 1] != '\'' && c[t2 - 1] != '\0';);
    if (*c == ';') return 1;
    if (my_strncmp(c, "&&", 2) == 0) return 2;
    return 0;
}

bool cmp_node(node_t *node, void *data)
{
    int len = my_strlen(data);

    if (my_strncmp(node->data, data, len) == 0)
        return true;
    else
        return false;
}

void list_to_char_tab(dlist_t *dlist, char ***env)
{
    if (dlist == NULL || dlist->len == 0)
        return;
    int i = 0;

    if ((*env) != NULL)
        free((*env));
    (*env) = NULL;
    (*env) = malloc(sizeof(char *) * (dlist->len + 1));
    for (node_t *tmp = dlist->begin; tmp != NULL; tmp = tmp->next, i++)
        (*env)[i] = tmp->data;
    (*env)[i] = NULL;
}

char **list_to_char_tab2(dlist_t *dlist)
{
    if (dlist == NULL || dlist->len == 0)
        return NULL;
    int i = 0;

    char **tab = malloc(sizeof(char *) * (dlist->len + 1));
    for (node_t *tmp = dlist->begin; tmp != NULL; tmp = tmp->next, i++)
        tab[i] = my_strdup(tmp->data);
    tab[i] = NULL;
    return tab;
}