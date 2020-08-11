/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils3
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool loop_cpy(char *s, char **t, int **k, char q);

bool cpy_quets(char *s, char **t, int **k, char **cmd)
{
    int i = *k[0], j = *k[1];

    if (s == NULL || t == NULL) return false;
    if (s[i] == '"') {
        if (loop_cpy(s, t, k, '"')) return true;
        i = *k[0], j = *k[1];
        (*t)[j++] = s[i++];
        if (s[i] != '\0' && s[i] != ' ' && cmpstrtab(cmd, &s[i]) == false) {
            (*t)[j] = '\0';
            j++, (*t) = my_strncdup2((*t), " ", my_strlen(s) + 3);
        }
        *k[0] = i - 1, *k[1] = j - 1;
        return true;
    }
    return false;
}

bool cpy_quet(char *s, char **t, int **k, char **cmd)
{
    int i = *k[0], j = *k[1];

    if (s == NULL || t == NULL) return false;
    if (s[i] == '\'') {
        if (loop_cpy(s, t, k, '\'')) return true;
        i = *k[0], j = *k[1];
        (*t)[j++] = s[i++];
        if (s[i] != '\0' && s[i] != ' ' && cmpstrtab(cmd, &s[i]) == false) {
            (*t)[j] = '\0';
            j++, (*t) = my_strncdup2((*t), " ", my_strlen(s) + 3);
        }
        *k[0] = i - 1, *k[1] = j - 1;
        return true;
    }
    return false;
}

bool cmpsp(char *s1, char *s2, int l_c, int i)
{
    if (i < l_c) return true;
    if (my_strncmp(&s1[i - l_c], s2, l_c) != 0) return true;
    return false;
}

bool cpy_cmd(char *s, char *t, char *cmd, int **k)
{
    int l_c = my_strlen(cmd), i = *k[0], j = *k[1];

    if (my_strncmp(&s[i], cmd, l_c) == 0) {
        for (int y = 0; y < l_c; y++) t[j++] = s[i++];
        if (s[i] != ' ' && s[i] != '\0') {
            t[j] = ' ', t[j + 1] = '\0', i--;
            *k[0] = i, *k[1] = j;
            return true;
        }
    }
    *k[0] = i, *k[1] = j;
    return false;
}

char *cmd_add_spaces(char *s, char *cmd, bool f)
{
    if (s == NULL || cmd == NULL) return NULL;
    char *t = malloc(sizeof(char) * (my_strlen(s) + 2));
    int j = 0, l_c = my_strlen(cmd);

    for (int i = 0; s[i] != '\0'; i++, t[++j] = '\0') {
        cpy_quets(s, &t, (int *[]){&i, &j}, (char *[]){cmd, NULL});
        cpy_quet(s, &t, (int *[]){&i, &j}, (char *[]){cmd, NULL});
        if (s[i] == '\0') return t;
        if (my_strncmp(&s[i], cmd, l_c) == 0 && i != 0 &&
            cmpsp(s, cmd, l_c, i) && s[i - 1] != ' ')
            j++, t = my_strncdup2(t, " ", my_strlen(s) + 3);
        if (cpy_cmd(s, t, cmd, (int *[]){&i, &j})) continue;
        t[j] = s[i];
    }
    if (f) free(s), s = NULL;
    return t;
}
