/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** free
*/

#include <minishell.h>
#include <my_printf.h>

void free_array(void *array)
{
    if (array != NULL) {
        void **tmp = (void **)array;
        for (int i = 0; tmp[i] != NULL; i++)
            free(tmp[i]);
        free(tmp);
    }
    array = NULL;
}

void free_tmp(data_t *data)
{
    if (data->get) free(data->get), data->get = NULL;
    if (data->usr != NULL) free_array(data->usr), data->usr = NULL;
}

void free_charptr_node(node_t *node)
{
    if (node->data != NULL) free(node->data), node->data = NULL;
    if (node != NULL) free(node), node = NULL;
}

void free_minishell_data(data_t *data)
{
    if (data->get != NULL) free (data->get), data->get == NULL;
    if (data->home != NULL) free (data->home), data->home = NULL;
    if (data->oldpwd != NULL) free(data->oldpwd), data->oldpwd = NULL;
    if (data->list != NULL) clear_dlist(&data->list, free_charptr_node);
    if (data->env != NULL) free(data->env), data->env = NULL;
    if (data->denv != NULL) free_array(data->denv), data->denv = NULL;
    if (data->cmds != NULL) free_array(data->cmds), data->cmds = NULL;
    if (data->path != NULL) free_array(data->path), data->path = NULL;
    if (data->usr != NULL) free_array(data->usr), data->usr = NULL;
    if (data != NULL) free(data), data = NULL;
}
