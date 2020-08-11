/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirection_left
*/

#include <fcntl.h>
#include <get_next_line.h>
#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

int get_delimiter(char *cmd, int fd)
{
    char *delimiter = cmd;
    my_printf("? ");
    char *s = get_next_line(0, '\n', false);

    dlist_t *lst = NULL;
    while (s && my_strcmp(s, delimiter) != 0) {
        push_back(&lst, my_strdup(s), 0);
        my_printf("? ");
        s = get_next_line(0, '\n', false);
    }
    int o = dup(1);
    int n = dup2(fd, 1);
    print_dlist_begin(lst);
    close(n);
    dup(o);
    clear_dlist(&lst, free_charptr_node);
    return 0;
}

void redirection_left(char ***cmd, data_t *data, int (*excut)())
{
    remove_cmds_quotes((*cmd));
    char **t = NULL, *file = NULL, std[2];

    if ((t = rm_redir((*cmd), "<")) == NULL) return;
    file = get_redir_file((*cmd), "<");
    if ((std[0] = open(file, O_RDWR)) >= 0) {
        std[1] = STDIN_FILENO;
        luanch_cmd_by_redir(&t, data, std, excut);
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        free_array(t), t = NULL;
        close(std[0]);
    } else {
        my_printf("%s: %s.\n", file, strerror(errno));
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        free_array(t), t = NULL;
    }
}

void redirection_double_left(char ***cmd, data_t *data, int (*excut)())
{
    remove_cmds_quotes((*cmd));
    char **t = NULL, *d = NULL, std[2];
    dlist_t *lst = NULL;

    if ((t = rm_redir((*cmd), "<<")) == NULL) return;
    d = get_redir_file((*cmd), "<<");
    int fd = open("/tmp/tmplr", O_CREAT | O_RDWR | O_TRUNC, 0644);
    get_delimiter(d, fd);
    for (int i = 0; t[i] != NULL; i++) push_back(&lst, my_strdup(t[i]), 0);
    push_back(&lst, my_strdup("<"), 0);
    push_back(&lst, my_strdup("/tmp/tmplr"), 0);
    free_array((*cmd)), (*cmd) = NULL;
    free_array(t), t = NULL;
    t = list_to_char_tab2(lst);
    clear_dlist(&lst, free_charptr_node);
    redirection_left(&t, data, excut);
}