/*
** lib.h for lib.h in /home/lopez_i/.lib
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed May  4 11:28:02 2016 Loic Lopez
** Last update Thu Jun  2 13:55:38 2016 pierre piazza
*/

#ifndef LIB_H_
# define LIB_H_

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

void	*xmalloc(size_t	size);
char	*my_strdup(char *str);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
int	my_getnbr(char *str);
char	*delete_specific_char(char *str, char c);
char	*epur_str(char *line);
char	**str_to_wordtab(char *str, char c);
char	**my_str_to_wordtab(char *str, char c);
char	**create_tab_and_epur(char *line, char c);
void	my_cperror(char c);
void	my_perror(char *str);
int	my_str_is_num(char *str);
char    *my_strcat(char *src, char *src2);
char	*replace_t(char *);

#endif /* !LIB_ */
