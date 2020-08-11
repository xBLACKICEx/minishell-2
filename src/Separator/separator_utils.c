/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** separator_utils
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

void get_cmds(char *cmds, data_t *data)
{
    cmds = cmd_add_spaces2(cmds, (char *[]){";", "&&", "||",
                                "|", "<<", ">>", NULL}, false);
    cmds = cmd_add_spaces1(cmds, "<", "<<", true);
    cmds = cmd_add_spaces1(cmds, ">", ">>", true);
    data->usr = my_str_to_word_array3(cmds, remve_space_);
    free(cmds), cmds = NULL;
}

unsigned int cmplenstr(char **cmd, char **c)
{
    unsigned int i = 0;

    for (; cmd[i] != NULL; i++)
        for (int j = 0; c[j] != NULL; j++)
            if (my_strcmp2(cmd[i], c[j]) == 0) return i;
    return i;
}

char **cat_cms(char **cmd, char **c, int *i)
{
    if (cmd == NULL || cmd[*i] == NULL || c == NULL || c[0] == NULL)
        return NULL;
    if (my_strcmptab(c, cmd[*i])) return NULL;

    char **t = malloc(sizeof(char *) * (cmplenstr(&cmd[*i], c) + 1)), j = 0;
    for (; cmd[*i] != NULL && !my_strcmptab(c, cmd[*i]); (*i)++, t[++j] = NULL)
        t[j] = my_strdup(cmd[*i]);
    return t;
}