/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell
*/

#include <get_next_line.h>
#include <minishell.h>
#include <my_printf.h>
#include <my_printf_tools.h>
#include <my_tools.h>

int no_fork(char *path, char **cmd, char **env)
{
    execve(path, cmd, env);
}

int exect_binary(char **cmd, data_t *data, int (*excut)())
{
    int i = 0;
    char path_dire[256];
    if (execve(cmd[0], cmd, data->env) == -1)
        for (int i = 0; data->path[i] != NULL; i++) {
            my_strcat(my_strcpy(path_dire, data->path[i]), cmd[0]);
            if (access(path_dire, F_OK) != -1) {
                data->error = execve(path_dire, cmd, data->env);
                data->error = execve(path_dire, cmd, data->denv);
            }
        }
    my_printf("%s: Command not found.\n", cmd[0]);
    return 84;
}

void get_ctrl_c_sig(int sig)
{
    (void)sig;
    pstr_c("mysh->\n");
}

void minishell(data_t *data)
{
    signal(SIGINT, get_ctrl_c_sig);
    pstr_c("mysh->");
    data->get = get_next_line(0, '\n', false);
    while (data && data->get) {
        if (data) separator(data->get, data);
        if (data) pstr_c("mysh->");
        if (data) free_array(data->cmds), data->cmds = NULL;
        if (data) data->get = get_next_line(0, '\n', false);
    }
    pstr_c("exit\n");
}