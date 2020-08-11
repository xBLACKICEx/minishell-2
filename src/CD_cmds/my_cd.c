/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_datas
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

int my_cd(char **cmd, data_t *data)
{
    if (cd_is_error(cmd, data)) return 84;
    if (my_strlentab(cmd) == 1 && my_strcmp(cmd[0], "cd") == 0 ||
        my_strlentab(cmd) == 2 && my_strcmp(cmd[1], "~") == 0)
        return luanch_chdir_home(data);
    if (my_strlentab(cmd) == 1 && my_strcmp(cmd[0], "cd-") == 0)
        return luanch_chdir_back(data);
    if (my_strlentab(cmd) == 2 && cmd[1][0] == '~' && cmd[1][1] != '\0')
        return luanch_chdir_home_2(cmd, data, &cmd[1][1]);
    if (my_strlentab(cmd) == 2 && my_strcmp(cmd[1], "-") == 0)
        return luanch_chdir_oldpwd(data);
    if (my_strlentab(cmd) == 2 && cmd[1][0] != '~' &&
        my_strcmp(cmd[1], "-") != 0 && my_strcmp(cmd[0], "cd-") != 0)
        return luanch_chdir_pwd(cmd, data, cmd[1]);
}

int update_pwd(data_t *data, node_t *node, char *old_pwd, int i)
{
    char buf[256], path[256];

    if (node != NULL) {
        free(node->data), node->data = NULL;
        node->data = my_strncdup(
            node->data,
            my_strcat(my_strcpy(buf, "PWD="), getcwd(path, sizeof(path))),
            __INT_MAX__);
        data->env[i] = node->data;
    } else {
        my_strcpy(path, "PWD=");
        my_strcat(path, getcwd(buf, sizeof(buf)));
        push_back(&data->list, my_strdup(path), 0);
        list_to_char_tab(data->list, &data->env);
    }
}

int update_oldpwd(data_t *data, node_t *node, char *old_pwd, int i)
{
    char buf[256];

    if (node != NULL) {
        free(node->data), node->data = NULL;
        node->data = my_strncdup(node->data,
                                my_strcat(my_strcpy(buf, "OLDPWD="), old_pwd),
                                __INT_MAX__);
        data->env[i] = node->data;
        if (data->oldpwd != NULL) free(data->oldpwd);
        data->oldpwd = my_strdup(data->env[i]);
    } else {
        push_back(&data->list,
                my_strdup(my_strcat(my_strcpy(buf, "OLDPWD="), old_pwd)), 0);
        if (data->oldpwd != NULL) free(data->oldpwd);
        data->oldpwd = my_strdup(data->list->end->data);
        list_to_char_tab(data->list, &data->env);
    }
}

int change_oldpwd(data_t *data, char *old_pwd)
{
    int i = 0;
    char buf[256], pwd[256];
    node_t *tmp = data->list->begin;

    for (i = 0; tmp != NULL && my_strncmp(tmp->data, "OLDPWD", 6) != 0;
        tmp = tmp->next, i++);
    update_oldpwd(data, tmp, old_pwd, i);
    tmp = data->list->begin;
    for (i = 0; tmp != NULL && my_strncmp(tmp->data, "PWD", 3) != 0;
        tmp = tmp->next, i++);
    update_pwd(data, tmp, old_pwd, i);
}