##
## Makefile<test> for Makefile in /home/lopez_i/traitements/PSU_2015_minishell1
## 
## Made by Loic Lopez
## Login   <lopez_i@epitech.net>
## 
## Started on  Thu Jan 21 19:22:39 2016 Loic Lopez
## Last update Mon Jun  6 19:26:35 2016 Eric DESCHODT
##

CC	=	gcc

NAME    =	libmy.a

ARRC	=	ar rc

ECHO	=	/bin/echo -e \

DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"

CFLAGS +=	-Wextra -Wall -Werror
CFLAGS +=	-pedantic -ansi
CFLAGS +=	-I./include/

SRC	=	my_printf_p.c			\
		my_printf.c			\
		my_put_nbr_unsigned.c		\
		my_putstr.c			\
		my_putchar.c			\
		my_putnbr_base.c		\
		my_put_nbr.c			\
		my_strlen.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_putstr_noprintable.c		\
		my_getnbr.c			\
		str_to_wordtab.c		\
		my_str_to_wordtab.c		\
		my_strcmp.c			\
		my_strncmp.c			\
		my_putnbr_base_size.c		\
		my_perror.c			\
		my_str_is_num.c			\
		xmalloc.c			\
		epur_str.c			\
		my_strcat.c			\
		replace_t.c			\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(ARRC) $(NAME) $(OBJ) && \
		$(ECHO) $(GREEN) "[AR]" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $(OBJ) $(DEFAULT)
		@ranlib $(NAME) && \
		$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $(OBJ) $(DEFAULT)

clean:
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) && \
		$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $(OBJ) $(DEFAULT)

re:		fclean all

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK]" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR]" $(TEAL) $^ $(DEFAULT)

.PHONY:		all clean fclean re
