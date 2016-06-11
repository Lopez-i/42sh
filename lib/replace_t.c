/*
** replace_t.c for replace_t.c in /home/lopez_i/traitements/PSU_2015_minishell2
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Thu Apr  7 16:37:20 2016 Loic Lopez
** Last update Wed May 25 11:37:08 2016 Loic Lopez
*/

#include "lib.h"

char	*replace_t(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}
