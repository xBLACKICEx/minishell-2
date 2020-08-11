/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** separator
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

int luach_sp(data_t *data, int *i, int *e, char ***cmds)
{
    char *s[] = {"&&", ";", "||", NULL}, **t = NULL;
    for (; (*cmds) && my_strcmp2(";", (*cmds)[*i]) == 0;) {
        for (; my_strcmp2((*cmds)[*i + 1], ";") == 0; (*i)++);
        (*i)++, t = cat_cms((*cmds), s, i);
        *e = select_lauch_type(&t, data, no_fork), free_array(t), t = NULL;
        if ((*cmds) != NULL && (*cmds)[*i] == NULL) {
            free_array((*cmds)), (*cmds) = NULL;
        }
    }
}

void separator(char *cmds, data_t *data)
{
    if (cmds == NULL || cmds[0] == '\0') return;
    get_cmds(cmds, data);
    int i = 0, e = -1;
    char *s[] = {"&&", ";", "||", NULL};

    if (data->get != NULL) free(data->get), data->get = NULL;
    if (separator_is_error(&data->usr)) return;
    char **t = cat_cms(data->usr, s, &i);
    e = select_lauch_type(&t, data, no_fork);
    for (; data->usr != NULL && data->usr[i] != NULL; i++)
        if (data->usr) luach_sp(data, &i, &e, &data->usr);
    if (data->usr != NULL) free_array(data->usr), data->usr = NULL;
}