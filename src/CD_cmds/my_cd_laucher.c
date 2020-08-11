/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** minishell_cd_laucher
*/

#include <my_printf.h>
#include <my_tools.h>
#include <minishell.h>

int luanch_chdir_home(data_t *data)
{
    if (data->home == NULL) {
        my_printf("cd: No home directory.\n");
        return 84;
    }
    char *buf = getcwd(NULL, 0);

    if (chdir(data->home) != 0) {
        my_printf("%s: %s.\n", data->home, strerror(errno));
        free(buf);
        return 84;
    }
    change_oldpwd(data, buf);
    free(buf);
    return 0;
}

int luanch_chdir_back(data_t *data)
{
    char *path = NULL, *buf = getcwd(NULL, 0);
    path = my_strdup(buf);
    path = my_strncdup(path, "/..", 3);

    if (chdir("..") != 0) {
        my_printf("%s: %s.\n", path, strerror(errno));
        free(path);
        free(buf);
        return 84;
    }
    change_oldpwd(data, buf);
    free(path);
    free(buf);
    return 0;
}

int luanch_chdir_oldpwd(data_t *data)
{
    char *path = NULL, *buf = getcwd(NULL, 0);

    if ((path = my_strdup(my_getenv("OLDPWD", data->env))), path == NULL)
        path = my_strdup(data->oldpwd);
    if (chdir(path) != 0) {
        my_printf("%s: %s.\n", path, strerror(errno));
        free(path);
        free(buf);
        return 84;
    }
    change_oldpwd(data, buf);
    free(path);
    free(buf);
    return 0;
}

int luanch_chdir_pwd(char **cmd, data_t *data, char *dir)
{
    char *buf = getcwd(NULL, 0);

    if (chdir(cmd[1]) != 0) {
        my_printf("%s: %s.\n", cmd[1], strerror(errno));
        free(buf);
        return 84;
    }
    change_oldpwd(data, buf);
    free(buf);
    return 0;
}

int luanch_chdir_home_2(char **cmd, data_t *data, char *dir)
{
    char *buf = getcwd(NULL, 0);
    char *path = my_strncdup(my_strdup(data->home), &cmd[1][1],
        __INT_MAX__);

    if (chdir(path) != 0) {
        my_printf("%s: %s.\n", path, strerror(errno));
        free(path);
        free(buf);
        return 84;
    }
    change_oldpwd(data, buf);
    free(buf);
    free(path);
    return 0;
}