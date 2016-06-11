##
## Makefile<test> for Makefile in /home/lopez_i/traitements/PSU_2015_minishell1
##
## Made by Loic Lopez
## Login   <lopez_i@epitech.net>
##
## Started on  Thu Jan 21 19:22:39 2016 Loic Lopez
## Last update Mon Jun  6 19:26:41 2016 Eric DESCHODT
##

CC	=	gcc

NAME    =	../42sh

ECHO	=	/bin/echo -e \

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I../include/ -I../lib/include
CFLAGS	+=	-lmy -L../lib/ -lncurses
CFLAGS	+=	-D_BSD_SOURCE -D_XOPEN_SOURCE

SRC	=	main.c				\
		list.c				\
		alias.c				\
		alias_find.c			\
		alias_recurs.c			\
		env.c				\
		prompt.c			\
		buildin.c			\
		create_multi.c			\
		create_prio.c			\
		show_tab.c			\
		modifyargv.c			\
		check_cd.c			\
		help_exit.c             	\
                help_cd.c               	\
                help_setenv.c           	\
                help_unsetenv.c         	\
                help_echo.c             	\
                help_env.c              	\
                help_vanilla.c          	\
		my_cd.c				\
		unsetenv.c			\
		setenv.c			\
		help.c				\
		simple_execution.c		\
		simple_execution_without_fork.c	\
		pipe.c				\
		my_exit.c			\
		my_echo.c			\
		my_echo_bis.c			\
		my_echo_ter.c			\
		execute.c			\
		error_msg.c			\
		find_pathern.c			\
		exec_in_env.c			\
		all_execute.c			\
		clear_redir.c			\
		redir_left.c			\
		redir_right.c			\
		double_left.c			\
		source.c			\
		init_sig_error.c		\
		print_status.c			\
		wait_and_print_status.c		\
		glob.c				\
		setenv_path_cmd.c		\
		read_non_canon.c		\
		erasing.c			\
		appending.c			\
		history.c			\
		arrowsing.c			\
		check_empty_str.c		\
		42sh_history_actions.c		\
		sigInt.c			\
		sh.c				\
		copy_arg.c			\
		copy_env.c			\
		check_env.c			\
		free_env.c			\
		get_env.c			\
		modifyenv.c			\
		stockenv.c			\
		init_termios.c			\
		close_termios.c			\
		auto_complete.c			\
		get_auto_complete.c		\
		exec_from_history.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $ $(CFLAGS) -o $(NAME) && \
		$(ECHO) $(GREEN) "[OK]" $(TEAL) $(OBJ) $(DEFAULT) || \
		paplay sounds/je_code.ogg
clean:
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) && \
		$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(OBJ) $(DEFAULT)

re:		fclean all

.c.o:
		 @$(CC) $(CFLAGS) -c -o $@ $< && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $^ $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)

.PHONY:   all clean fclean re
