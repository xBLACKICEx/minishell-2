/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils6
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_tools.h>

char *remove_cmd_dul_quot(char *cmd)
{
    int j = 0;
    if (cmd != NULL && cmd[0] == '"') {
        for (int i = 1; cmd[i] != '\0' &&  cmd[i] != '"'; i++) {
            if (cmd[i] == '\\' && is_char_conver(&cmd[i + 1])) {
                cmd[j++] = esc_char_conver(&cmd[i + 1]), i++;
                continue;
            }
            cmd[j++] = cmd[i];
        }
        cmd[j] = '\0';
    }
    return cmd;
}

char *remove_cmd_sig_quot(char *cmd)
{
    int j = 0;
    if (cmd != NULL && cmd[0] == '\'') {
        for (int i = 1; cmd[i] != '\0' &&  cmd[i] != '\''; i++) {
            if (cmd[i] == '\\' && is_char_conver(&cmd[i + 1])) {
                cmd[j++] = esc_char_conver(&cmd[i + 1]), i++;
                continue;
            }
            cmd[j++] = cmd[i];
        }
        cmd[j] = '\0';
    }
    return cmd;
}

char *remove_cmd_brackets(char *cmd)
{
    int j = 0;
    if (cmd != NULL && cmd[0] == '(') {
        for (int i = 1; cmd[i] != '\0' &&  cmd[i] != ')'; i++)
            cmd[j++] = cmd[i];
        cmd[j] = '\0';
    }
}

char **remove_cmds_quotes(char **cmds)
{
    for (int i = 0; cmds[i] != NULL; i++) {
        if (cmds[i][0] == '\'')
            remove_cmd_sig_quot(cmds[i]);
        else if (cmds[i][0] == '"')
            remove_cmd_dul_quot(cmds[i]);
    }
}

char **remove_cmdsn_quotes(char **cmds, int size)
{
    for (int i = 0; cmds[i] != NULL && i < size; i++) {
        if (cmds[i][0] == '\'')
            remove_cmd_sig_quot(cmds[i]);
        else if (cmds[i][0] == '"')
            remove_cmd_dul_quot(cmds[i]);
    }
}