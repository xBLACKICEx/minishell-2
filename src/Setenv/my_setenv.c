/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** setenv
*/

#include <my_tools.h>
#include <minishell.h>

int my_setenv(char **cmd, data_t *data)
{
    if (my_setenv_error_case(cmd, true) == -1) return 84;
    if (my_strlentab(cmd) == 1) print_dlist_begin(data->list);
    if (my_strlentab(cmd) == 2) {
        char tmp[my_strlen(cmd[1]) + 1];
        my_strcpy(tmp, cmd[1]);
        tmp[my_strlen(cmd[1])] = '=';
        tmp[my_strlen(cmd[1]) + 1] = '\0';
        pop_list(&data->list, tmp, &cmp_node, free_charptr_node);
        push_back(&data->list, my_strdup(tmp), 0);
    } else if (my_strlentab(cmd) == 3) {
        char tmp[my_strlen(cmd[1]) + my_strlen(cmd[2]) + 1];
        my_strcpy(tmp, cmd[1]);
        tmp[my_strlen(cmd[1])] = '=';
        tmp[my_strlen(cmd[1]) + 1] = '\0';
        pop_list(&data->list, tmp, &cmp_node, free_charptr_node);
        push_back(&data->list, my_strdup(my_strcat(tmp, cmd[2])), 0);
    }
    list_to_char_tab(data->list, &data->env);
    return 0;
}

int my_unsetenv(char **cmd, data_t *data)
{
    if (my_setenv_error_case(cmd, false) == -1) return 84;
    for (int i = 1; cmd[i] != NULL; i++) {
        char tmp[my_strlen(cmd[i]) + 1];
        pop_list(&data->list, my_strcat(my_strcpy(tmp, cmd[i]), "="),
                &cmp_node, free_charptr_node);
    }
    list_to_char_tab(data->list, &data->env);
    return 0;
}