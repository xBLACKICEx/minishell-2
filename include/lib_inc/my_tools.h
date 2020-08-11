/*
** EPITECH PROJECT, 2020
** PSU_matchstick1_2019
** File description:
** my_tools
*/

#ifndef MY_TOOLS_H_
#define MY_TOOLS_H_
#include <stdbool.h>

/*list fonction to compation with string and charaters*/

bool my_char_isnum(char c);
bool my_char_isalpha(char c);
bool my_char_islower(char c);
bool my_char_isuppler(char c);
bool my_char_isprintable(char c);
bool my_char_isalphanumeric(char c);
bool my_char_isalphanumerics(char c);

bool my_str_isnum(char const *str);
bool my_str_isalpha(char const *str);
bool my_str_isalower(char const *str);
bool my_str_isuppler(char const *str);
bool my_str_isprintable(char const *str);
bool my_str_isalphanumeric(char const *str);
bool my_str_isalphanumerics(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp2(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
bool my_strcmptab(char **top, char const *src);
char *strtouper(char *str);
bool my_strstr_bool(char const *str, char const *to_find, bool with_space);


/*count strings*/
unsigned int my_strlen(char const *str);
unsigned int my_strlentab(char **tab);
unsigned int my_strnlen(char const *str, char *the_end, bool is_words);
unsigned int my_tab_num_s(char **tab, char *s);
unsigned int my_strnlentab(char **tab, char *s);
/*toos*/
int my_getnbr_to_int(char const *str);
int my_getnbr_to_char(char const *str);
int my_getnbr_base(char const *str, char const *base);
int my_putnbr_base(int nbr, char const *base);
char *my_getenv(char const *path, char **env);
void my_show_word_array(char * const *top);
char *my_ftoa(double nbr, int size);
int my_getnbr(char const *str);

// output by fd 2
void putserr(char const *str);

int my_compute_power_rec(int nb, int p);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str, int (*to_remove)(char const *c));
char **my_str_to_word_array2(char const *str, int (*to_remove)(char const *c));
char **my_str_to_word_array3(char const *str, int (*to_remove)(char const *c));
void my_swap(int *a, int *b);
char *my_strcat(char *dest, char const *str);
char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *str, int n);
char *my_strncat(char *dest, char const *str, int n);
void clean_str(char *str);

char *my_strdup(char const *src);
char **my_strtabdup(char **tab, int size);
char *my_strndup(char const *src, int size);
char *my_strncdup(char *dest, char const *src, int n);
char *my_strncdup2(char *dest, char const *str, int n);
void free_array(void *array);
int remov_bracket(char const *c);
int remov_colon(char const *c);
int remov_comma(char const *c);
int remov_jcomma(char const *c);
int remov_enter(char const *c);
double my_atof(const char *s);

// int number type be comme char * type
char *my_itoa(int nbr);
int _remve_space(const char *c, int *i);
bool jmp_quotes(char const *c, int *i);
#endif /* !MY_TOOLS_H_ */