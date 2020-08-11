/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** is_empty_list
*/

#include <linked_list.h>
#include <my_printf_tools.h>

void free_node(node_t *node);

void print_dlist_begin(dlist_t *list)
{
    if (list == NULL || list->len == 0)
        return;

    for (node_t *tmp = list->begin; tmp != NULL; tmp = tmp->next) {
        pstr_c(tmp->data);
        write(1, "\n", 1);
    }
}

void print_dlist_end(dlist_t *list)
{
    if (list == NULL || list->len == 0)
        return;

    for (node_t *tmp = list->end; tmp != NULL; tmp = tmp->prev) {
        pstr_c(tmp->data);
        write(1, "\n", 1);
    }
}

void clear_dlist(dlist_t **dlist, void (*free_node)(node_t *))
{
    node_t *tmp;

    if (is_empty_dlist(*dlist))
        return;
    for (((*dlist)->begin); (*dlist)->begin != NULL && (*dlist)->len != 0; ) {
        tmp = (*dlist)->begin;
        (*dlist)->begin = (*dlist)->begin->next;
        free_node(tmp);
        (*dlist)->len -= 1;
    }
    if ((*dlist) != NULL)
        free((*dlist));
}

bool is_empty_dlist(dlist_t * cheak_list_is_null)
{
    if (cheak_list_is_null == NULL)
        return (true);
    else
        return (false);
}