/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clean_str
*/

void scip_comma(char **str, int *y, int *i)
{
    if ((*str)[(*i)] == '"') {
        (*str)[(*y)++] = (*str)[(*i)++];
        for (; (*str)[(*i)] != '"' && (*str)[(*i)] != '\0'; (*i)++)
            (*str)[(*y)++] = (*str)[(*i)];
        (*str)[(*y)++] = (*str)[(*i)++];
    }
}

void clean_str2(char *str, int i, int y)
{
    for (; str[i] != '\0'; i++) {
        if (str[i] == '"') {
            scip_comma(&str, &y, &i);
            if (str[y] == '\0') return;
        }
        for (; str[i] != '\0' && str[i] == ' ' && str[i] != '"'; i++);
        if (str[i] == '"') {
            i--;
            continue;
        } else if (str[i] == '\0') {
            str[y] = '\0';
            return;
        } else str[y++] = str[i];
    }
    str[y] = '\0';
}

void clean_str(char *str)
{
    int i = 0, y = 0, j = 0;

    for (; str[i] != '\0' && (str[i] == '\t' || str[i] == ' '); i++);
    scip_comma(&str, &y, &i);
    if (str[y] == '\0') return;
    for (j = i; str[j] != '\0' && (str[j] == '\t' || str[j] == ' ');
        j++, i = j) {
        if (str[j] == '"')
            for (; str[j] != '\0' && str[j] != '"'; j++) {
                if (str[j] == '\0') return;
                continue;
            }
        if (str[j] == '\t') str[j] = ' ';
    }
    clean_str2(str, i, y);
}