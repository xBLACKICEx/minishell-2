/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** uyils5
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool cmpsp(char *s1, char *s2, int l_c, int i);
bool cpy_cmd(char *s, char *t, char *cmd, int **k);

bool cpy_jp(char *s, char *t, char *jp, int **k)
{
    int l_c = my_strlen(jp), i = *k[0], j = *k[1];

    if (my_strncmp(&s[i], jp, l_c) == 0) {
        for (int y = 0; y < l_c; y++) t[j++] = s[i++];
        i--, j--;
        *k[0] = i, *k[1] = j;
        return true;
    }
    *k[0] = i, *k[1] = j;
    return false;
}

char *cmd_add_spaces1(char *s, char *cmd, char *jp, bool f)
{
    if (s == NULL || cmd == NULL) return NULL;
    char *t = malloc(sizeof(char) * (my_strlen(s) + 2));
    int j = 0, l_c = my_strlen(cmd), l_j = my_strlen(jp);

    for (int i = 0; s[i] != '\0'; i++, t[++j] = '\0') {
        if (cpy_quets(s, &t, (int *[]){&i, &j}, (char *[]){cmd, NULL}))
            continue;
        if (cpy_quet(s, &t, (int *[]){&i, &j}, (char *[]){cmd, NULL})) continue;
        if (cpy_jp(s, t, jp, (int *[]){&i, &j})) continue;
        if (my_strncmp(&s[i], cmd, l_c) == 0 && i != 0 &&
            cmpsp(s, cmd, l_c, i) && s[i - 1] != ' ')
            j++, t = my_strncdup2(t, " ", my_strlen(s) + 3);
        if (cpy_cmd(s, t, cmd, (int *[]){&i, &j})) continue;
        t[j] = s[i];
    }
    if (f) free(s), s = NULL;
    return t;
}