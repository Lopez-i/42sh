/*
** my_str_is_num.c for my_str_is_num.c in /home/lopez_i/traitements/PSU_2015_minishell2
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed Apr  6 20:14:02 2016 Loic Lopez
** Last update Wed May  4 12:28:09 2016 Loic Lopez
*/

#include "lib.h"

int	my_str_is_num(char *str)
{
  int	i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (-1);
    }
  return (1);
}
