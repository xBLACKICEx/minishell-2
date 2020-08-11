/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** minishell_functions
*/

#ifndef MINISHELL_FUNCTIONS_H_
#define MINISHELL_FUNCTIONS_H_

// minishell.c
void minishell(data_t *data);
int luanch_cmd(char ***cmd, data_t *data, int (*excut)());
int select_lauch_type(char ***cmds, data_t *data, int (*excut)());
int with_fork(char *path, char **cmd, char **env);
int no_fork(char *path, char **cmd, char **env);
int exect_binary(char **cmd, data_t *data, int (*excut)());
int shell_exit(char **cmds, data_t *data);
int remve_space_(const char *c);
// minishell errors
bool check_permisstion(char *str);
int check_segfout(int status);


//In utils0.c
void free_tmp(data_t *data);
int cat_cmds(const char *c);
char ***cat_cmd(char **cmd, char *c);
char *remove_cmd_quotes(char *cmd);
bool cmp_node(node_t *node, void *data);
void list_to_char_tab(dlist_t *dlist, char ***env);
char **list_to_char_tab2(dlist_t *dlist);
char *cmd_add_spaces(char *s, char *cmd, bool f);
unsigned int getlenstrtab(char **tab, char *s);
bool cmpstrtab(char **tab, char *s);
unsigned int get_tab_smllen(char **tab);
char *cmd_add_spaces2(char *s, char **cmd, bool f);
unsigned int get_tab_str_num(char **tab, char *s);
bool cpy_quets(char *s, char **t, int **k, char **cmd);
bool cpy_quet(char *s, char **t, int **k, char **cmd);
char *cmd_add_spaces1(char *s, char *cmd, char *jp, bool f);
char **reload_alias_cmd(char ***cmd, data_t *data);

bool is_char_conver(char *s);
char esc_char_conver(char *s);
char *remove_cmd_sig_quot(char *cmd);
char *remove_cmd_dul_quot(char *cmd);
char *remove_cmd_brackets(char *cmd);
char **remove_cmds_quotes(char **cmds);
char **remove_cmdsn_quotes(char **cmds, int size);

// destroy.c
void free_charptr_node(node_t *node);
void free_minishell_data(data_t *data);


// In my_cd.c
int my_cd(char **cmd, data_t *data);
int luanch_chdir_home(data_t *data);
int luanch_chdir_home_2(char **cmd, data_t *data, char *dir);
int luanch_chdir_pwd(char **cmd, data_t *data, char *dir);
int luanch_chdir_oldpwd(data_t *data);
int luanch_chdir_back(data_t *data);
int change_oldpwd(data_t *data, char *old_pwd);
int cd_is_error(char **cmd, data_t *data);

// setenv
int my_setenv(char **cmd, data_t *data);
int my_unsetenv(char **cmd, data_t *data);
// setenv erros
int my_setenv_error_case(char **cmd, bool is_setenv);


// redriction
int redirection(char ***cmd, data_t *data, int (*excut)());
void redirection_left(char ***cmd, data_t *data, int (*excut)());
void redirection_double_left(char ***cmd, data_t *data, int (*excut)());
void redirection_right(char ***cmd, data_t *data, int (*excut)());
char *get_redir_file(char **cmd, char *r);
void redirection_double_right(char ***cmd, data_t *data, int (*excut)());
void luanch_cmd_by_redir(char ***cmd, data_t *data, char *std, int (*excut)());
// rm_redirection_form_cmd
char **rm_redir(char **cmd, char *r);

// pipe
int my_pipe(char ***cmd, data_t *data);
bool pipe_is_error(char ***cmd);
void free_pipe_tmp(char **c, char ***cmd, data_t *data, int i);

// separator
void separator(char *cmds, data_t *data);
bool separator_is_error(char ***cmds);
void get_cmds(char *cmds, data_t *data);
unsigned int cmplenstr(char **cmd, char **c);
char **cat_cms(char **cmd, char **c, int *i);
char **cat_separator(char *cmds);


/*alias*/
int alias(char ***cmd, data_t *data);
int delete_alias(char ***cmd, dlist_t **l_als);

int print_alias_list(char ***cmd, dlist_t *l_als);
alias_t *serch_alais(dlist_t **l_als, char *name);

int creat_new_alias(char ***cmd, dlist_t **l_als, bool breakt);
void creat_with_bracket(alias_t **als, char **cmd);
void creat_no_bracket(alias_t **als, char **cmd);
bool sort_small_to_big_als(node_t *n1, node_t *n2);
bool unalias_is_error(char ***cmd);

// repeat
int repeat(char ***cmd, data_t *data);
bool repeat_is_error(char ***cmd);

// which & where
int which(char **cmd, data_t *data);
int where(char **cmd, data_t *data);

#endif /* !MINISHELL_FUNCTIONS_H_ */