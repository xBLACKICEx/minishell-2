/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipes
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

bool get_pipe_fd(int *__pipedes, data_t *data)
{
    if (pipe(__pipedes) <= -1) {
        my_printerr("%s\n", strerror(errno));
        data->error = 1;
        return false;
    }
    return true;
}

char ***cat_cmd(char **cmd, char *c)
{
    if (cmd == NULL || cmd[0] == NULL || c == NULL) return NULL;
    int i = 0, z = 0, y = 0;
    char ***t = malloc(sizeof(char **) * (my_tab_num_s(cmd, c) + 2));

    for (int i = 0; cmd[i] != NULL; i++, t[z][++y] = NULL) {
        if (z == 0 && y == 0)
            t[0] = malloc(sizeof(char *) * (my_strnlentab(&cmd[i], c) + 1));
        if (my_strcmp(cmd[i], c) == 0) {
            i++, t[++z] = NULL, y = 0;
            if (cmd[i] != NULL) {
                t[z] = malloc(sizeof(char *) * (my_strnlentab(&cmd[i], c) + 1));
                t[z + 1] = NULL;
            } else return t;
        }
        if (cmd[i] != NULL) t[z][y] = my_strdup(cmd[i]);
    }
    return t;
}

void excut_pipe_loop(char **c, char ***cmd, data_t *data)
{
    int pipefd[2], fd_in = 0, pid, status, e = 0;

    for (int i = 0; cmd[i] != NULL;) {
        if (!get_pipe_fd(pipefd, data)) return;
        if ((pid = fork()) == 0) {
            dup2(fd_in, STDIN_FILENO);
            if (cmd[i + 1] != NULL) dup2(pipefd[1], 1);
            close(pipefd[0]);
            e = select_lauch_type(&cmd[i], data, no_fork);
            free_pipe_tmp(c, cmd, data, i);
            exit(e);
        } else {
            waitpid(pid, &status, 0);
            check_segfout(status);
            data->error = WEXITSTATUS(status);
            close(pipefd[1]);
            fd_in = pipefd[0];
            i++;
        }
    }
}

int my_pipe(char ***cmd, data_t *data)
{
    int status = 0;

    remove_cmdsn_quotes(&(*cmd)[0], 1);
    if (my_strcmptab((*cmd), "|") == true) {
        remove_cmds_quotes((*cmd));
        if (pipe_is_error(cmd)) return -1;
        char ***t = cat_cmd((*cmd), "|");
        if (t != NULL)
        data->in_pipe = true;
        excut_pipe_loop((*cmd), t, data);
        data->in_pipe = false;
        for (int i = 0; t[i] != NULL;) free_array(t[i++]);
        free(t);
        if ((*cmd) != NULL) free_array((*cmd)), (*cmd) = NULL;
        return data->error;
    }
    return 0;
}