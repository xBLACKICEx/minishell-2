##
## EPITECH PROJECT, 2020
## PSU_minishell2_2019
## File description:
## Makefile
##

NAME	=	mysh

# ========================================================================== #
MAIN_PATH	=	./src/Main/
MAIN	=	main.c\
			minishell.c\
			luanch.c\
			exit.c\
			errors.c

# ========================================================================== #
UTILS_PATH	=	./src/Utils/
UTILS	=	utils0.c\
			utils1.c\
			utils2.c\
			utils3.c\
			utils4.c\
			utils5.c\
			utils6.c\
			utils7.c

# ========================================================================== #
DESTROY_PATH	=	./src/Destroy/
DESTROY		=		destroy0.c

# ========================================================================== #
CD_CMDS_PATH	=	./src/CD_cmds/
CD_CMDS		=		my_cd.c\
					cd_error.c\
					my_cd_laucher.c

# ========================================================================== #
SETENV_PATH		=	./src/Setenv/
SETENV		=		my_setenv.c\
					my_setenv_errors.c

# ========================================================================== #
REDIRECTION_PATH=	./src/Redirection/
REDIRECTION	=		redirection.c\
					redirection_right.c\
					redirection_left.c

# ========================================================================== #
PIPES_PATH		=	./src/Pipes/
PIPES		=		pipes.c\
					pipe_errors.c\
					pipe_utils.c

# ========================================================================== #
SEPARATOR_PATH	=	./src/Separator/
SEPARATOR	=		separator.c\
					separator_utils.c\
					separator_errors.c

# ========================================================================== #
SRC =	$(addprefix $(MAIN_PATH), $(MAIN))\
		$(addprefix $(UTILS_PATH), $(UTILS))\
		$(addprefix $(DESTROY_PATH), $(DESTROY))\
		$(addprefix $(CD_CMDS_PATH), $(CD_CMDS))\
		$(addprefix $(SETENV_PATH), $(SETENV))\
		$(addprefix $(REDIRECTION_PATH), $(REDIRECTION))\
		$(addprefix $(PIPES_PATH), $(PIPES))\
		$(addprefix $(SEPARATOR_PATH), $(SEPARATOR))\

# ========================================================================== #
CC	=	gcc -o

OBJ	= 	$(SRC:.c=.o)

LIB	=	-L./lib/ -l my_tools

CFLAGS	=	-g -g3 -I./include -I./include/lib_inc

# ========================================================================== #
REDDARK	=	\033[31;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

# ========================================================================== ##
all:	$(NAME)
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)MINISHELL$(GREEN)] → "
	@printf "$(WHITE)Compile completed. "
	@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/
	$(CC)	$(NAME)	$(OBJ)	$(LIB)	$(CFLAGS)

clean:
	make -C	./lib/ clean
	rm -rf	$(OBJ)
	rm -f	*~
	rm -f	*#
	rm -f	#*
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)MINISHELL$(GREEN)] → "
	@printf "$(WHITE)Deletion complete\n\n"

fclean:	clean
	make -C ./lib/ fclean
	rm -rf  $(NAME)

re:	fclean all

# ========================================================================== ##
%.o:	%.c
	@printf "$(GREEN)[$(WHITE)MINISHELL$(GREEN)] — $(WHITE)%-45s\n" $<
	@printf "$(GREEN) → $(RES) %-70s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n\n"
	@gcc $(CFLAGS) -o $@ -c $<