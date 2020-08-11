##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## makefile
##

NAME	=	libmy_tools.a

# ========================================================================== #
LINKED_LIST_PATH=	./double_linked_list/
LINKED_LIST	=	list_tools0.c\
				list_tools1.c\
				pop_list.c\
				push_list.c\
				swap_list0.c\
				swap_list1.c


# ========================================================================== #
MY_PRINTF_LIB_PATH=	./my_printf/lib/
MY_PRINTF_LIB	=	digital/put_num0.c\
					digital/put_num1.c\
					digital/u_put_num0.c\
					digital/u_put_num1.c\
					digital/u_put_num2.c\
					digital/u_put_num3.c\
					digital/u_put_num4.c\
					digital/put_float.c\
					particular/particular0.c\
					particular/flag_option0.c\
					particular/flag_option1.c\
					particular/flag_option2.c\
					string/put_str0.c\
					string/put_str1.c\
					type/type0.c\
					type/type1.c\
					type/type2.c


# ========================================================================== #
MY_PRINTF_PATH=	./my_printf/src/
MY_PRINTF	=	error0.c\
				flag_operation.c\
				my_getnbr.c\
				my_printf.c\
				tools0.c\
				tools1.c\
				tools2.c


# ========================================================================== #
LIB_STR_CMP_PATH=	./tools/str_cmp/
LIB_STR_CMP	=		my_str_isnum.c\
					my_str_isalpha.c\
					my_str_islower.c\
					my_str_isupper.c\
					my_str_isprintable.c\
					my_str_isalphanumeric.c\
					my_strcmp.c


# ========================================================================== #
LIB_STR_COUNT_PATH=	./tools/str_count/
LIB_STR_COUNT	=	my_strlen.c\
					my_strlen2.c

# ========================================================================== #
LIB_STR_MODIF_PATH=	./tools/str_modif/
LIB_STR_MODIF	=	my_revstr.c\
					my_strcapitalize.c\
					my_strcat.c\
					my_strcpy.c\
					my_strlowcase.c\
					my_strstr.c\
					my_swap.c\


# ========================================================================== #
LIB_STR_TOOLS_PATH=	./tools/str_tools/
LIB_STR_TOOLS	=	my_getnbr_base.c\
					my_getenv.c\
					my_itoa.c\
					my_getnbr.c\
					clean_str.c\
					my_puterror.c\
					my_putnbr_base.c\
					my_str_to_word_array.c\
					my_str_to_word_array3.c\
					my_strdup.c\
					my_show_word_array.c\
					get_next_line.c\


# ========================================================================== #
SRC =	$(addprefix $(LINKED_LIST_PATH), $(LINKED_LIST))\
		$(addprefix $(MY_PRINTF_LIB_PATH), $(MY_PRINTF_LIB))\
		$(addprefix $(MY_PRINTF_PATH), $(MY_PRINTF))\
		$(addprefix $(LIB_STR_CMP_PATH), $(LIB_STR_CMP))\
		$(addprefix $(LIB_STR_COUNT_PATH), $(LIB_STR_COUNT))\
		$(addprefix $(LIB_STR_MODIF_PATH), $(LIB_STR_MODIF))\
		$(addprefix $(LIB_STR_TOOLS_PATH), $(LIB_STR_TOOLS))\


# ========================================================================== #
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

CFLAGS	=	-g -g3 -I../include/lib_inc/


# ========================================================================== #
REDDARK	=	\033[31;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m


## ========================================================================== ##
all:	$(NAME)
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)LIB$(GREEN)] → "
	@printf "$(WHITE)Compile completed. "
	@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf  $(OBJ)
	rm -f	*~
	rm -f	*#
	rm -f	#*
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)LIB$(GREEN)] → "
	@printf "$(WHITE)Deletion complete\n\n"

fclean:	clean
	rm -rf  $(NAME)

re:	fclean all


## ========================================================================== ##
%.o:	%.c
	@printf "$(GREEN)[$(WHITE)LIB$(GREEN)] — $(WHITE)%-45s\n" $<
	@printf "$(GREEN) → $(RES) %-70s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n\n"
	@gcc $(CFLAGS) -o $@ -c $<