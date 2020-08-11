/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell_main
*/

#include <minishell.h>
#include <my_printf.h>
#include <my_printf_tools.h>
#include <my_tools.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>

int remve_path_(const char *c)
{
    if (my_strncmp(":", c, 1) == 0) return 1;
    return 0;
}

void init_data(data_t *data)
{
    data->pid = data->error = 0;
    data->size = 0;
    data->ssize = 0;
    data->home = data->oldpwd = data->get = NULL;
    data->env = data->usr = data->cmds = data->path = NULL;
    data->list = data->l_als = NULL;
    data->in_pipe = false;
}

void init_env_defaut(data_t *data)
{
    char buf[1000];
    data->path = malloc(sizeof(char *) * (4 + 1));
    data->path[0] = my_strdup("/usr/bin/");
    data->path[1] = my_strdup("/usr/sbin/");
    data->path[2] = my_strdup("/bin/");
    data->path[3] = my_strdup("/sbin/");
    data->path[4] = NULL;
    data->oldpwd = getcwd(NULL, 0);
    data->env = malloc(sizeof(char *) * 1);
    data->env[0] = NULL;
}

void get_env_and_path(data_t *data, char *env[])
{
    if ((data->oldpwd = my_strdup(my_getenv("OLDPWD", env))),
        data->oldpwd == NULL)
        data->oldpwd = getcwd(NULL, 0);
    data->home = my_strdup(my_getenv("HOME", env));
    data->path = my_str_to_word_array(my_getenv("PATH", env), &remve_path_);
    for (int i = 0; data->path[i] != NULL; i++)
        data->path[i] = my_strncdup(data->path[i], "/", 1);
    for (int i = 0; env[i] != NULL; i++)
        push_back(&data->list, my_strdup(env[i]), 0);
    list_to_char_tab(data->list, &data->env);
}

int main(int ac, char const *av[], char *env[])
{
    data_t *data = malloc(sizeof(data_t));
    if (ac == 1) {
        init_data(data);
        if (env[0] != NULL)
            get_env_and_path(data, env);
        else init_env_defaut(data);
        data->denv = my_strtabdup(data->env, my_strlentab(data->env));
        minishell(data);
        free_minishell_data(data);
        return 0;
    }
}