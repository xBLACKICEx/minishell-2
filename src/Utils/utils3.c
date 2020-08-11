/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils3
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool loop_cpy(char *s, char **t, int **k, char q)
{
    int i = *k[0], j = *k[1];

    if (j > 0 && (*t)[j - 1] != ' ')
        j++, (*t) = my_strncdup2((*t), " ", my_strlen(s) + 3);
    (*t)[j++] = s[i++];
    for (; s[i] != '\0' && s[i] != q; i++) (*t)[j++] = s[i];
    if (s[i] == '\0') {
        *k[0] = i - 1, *k[1] = j - 1;
        return true;
    }
    *k[0] = i, *k[1] = j;
    return false;
}

bool cpy_brackets(char *s, char **t, int **k, char **cmd)
{
    int i = *k[0], j = *k[1];

    if (s == NULL || t == NULL) return false;
    if (s[i] == '(') {
        if (loop_cpy(s, t, k, ')')) return true;
        i = *k[0], j = *k[1];
        (*t)[j++] = s[i++];
        if (s[i] != '\0' && s[i] != ' ' && cmpstrtab(cmd, &s[i]) == false) {
            (*t)[j] = '\0';
            j++, (*t) = my_strncdup2((*t), " ", my_strlen(s) + 3);
        }
        *k[0] = i - 1, *k[1] = j - 1;
        if (s[i] == '\0') *k[0] = i - 1;
        return true;
    }
    return false;
}

bool cmpsp2(char *s1, char **s2, int i, int ln)
{
    if (ln < 0) return false;
    int li = my_strlen(s2[ln]);
    if (li < 0) return false;
    if (i < li) return true;
    if (my_strncmp(&s1[i - li], s2[ln], li) != 0) return true;
    return false;
}

bool cpy_cmd2(char *s, char *t, char **cmd, int **k)
{

    int i = *k[0], j = *k[1];
    int l_c = getlenstrtab(cmd, &s[i]);

    if (cmpstrtab(cmd, &s[i])) {
        *k[2] = get_tab_str_num(cmd, &s[i]);
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

char *cmd_add_spaces2(char *s, char **cmd, bool f)
{
    if (s == NULL || cmd == NULL) return NULL;
    char *t = malloc(sizeof(char) * (my_strlen(s) + 2));
    int j = 0, ln = -1;

    for (int i = 0; s[i] != '\0'; i++, t[++j] = '\0') {
        if (cpy_quets(s, &t, (int *[]){&i, &j}, cmd)) continue;
        if (cpy_quet(s, &t, (int *[]){&i, &j}, cmd)) continue;
        if (cpy_brackets(s, &t, (int *[]){&i, &j}, cmd)) continue;
        if (cmpstrtab(cmd, &s[i]) && i != 0 &&
            (cmpsp2(s, cmd, i, ln) && s[i - 1] != ' ' || ln == -1))
            j++, t = my_strncdup2(t, " ", my_strlen(s) + 3);
        if (cpy_cmd2(s, t, cmd, (int *[]){&i, &j, &ln})) continue;
        t[j] = s[i];
    }
    if (f) free(s), s = NULL;
    return t;
}