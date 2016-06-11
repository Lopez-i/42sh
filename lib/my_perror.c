/*
** my_perror.c for my_perror.c in /home/lopez_i/traitements/PSU_2015_minishell2
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Apr  4 13:42:15 2016 Loic Lopez
** Last update Wed May  4 12:24:03 2016 Loic Lopez
*/

#include "lib.h"

void	my_cperror(char c)
{
  write(2, &c, 1);
}

void	my_perror(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_cperror(str[i++]);
}
