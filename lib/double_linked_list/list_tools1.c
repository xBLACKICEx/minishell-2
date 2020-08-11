/*
** EPITECH PROJECT, 2020
** sort double linkde list
** File description:
** list_tools1
*/

#include <my_tools.h>
#include <linked_list.h>

bool list_small_to_big_num(node_t *n1, node_t *n2)
{
    if ((long)n1->data > (long)n2->data)
        return true;
    return false;
}

bool list_big_to_small_num(node_t *n1, node_t *n2)
{
    if ((long)n1->data < (long)n2->data)
        return true;
    return false;
}

bool list_small_to_big_charptr(node_t *n1, node_t *n2)
{
    if (my_strcmp(n1->data, n2->data) > 0)
        return true;
    return false;
}

bool list_big_to_small_charptr(node_t *n1, node_t *n2)
{
    if (my_strcmp(n1->data, n2->data) < 0)
        return true;
    return false;
}

void sort_list(dlist_t *list, bool (*cmd)(node_t *n1, node_t *n2))
{
    node_t *tmp;

    for (int i = 0; i < list->len; i++) {
        tmp = list->begin;
        for (int j = 0; j < list->len - i - 1; j++)
            if (cmd(tmp, tmp->next))
                swap_nodes(&list, tmp, tmp->next);
            else
                tmp = tmp->next;
    }
}