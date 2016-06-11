/*
** my_getnbr.c for my_getnbr.c in /home/lopez_i/traitements/PSU_2015_minishell2/src
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed Apr  6 13:01:34 2016 Loic Lopez
** Last update Wed May  4 12:26:15 2016 Loic Lopez
*/

#include "lib.h"

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  int	nb;

  if (str == NULL)
    return (-1);
  s = 1;
  i = 0;
  nb = 0;
  while (str[i] && (str[i] == '+' || str[i] == '-'))
    if (str[i++] == '-')
      s *= -1;
  while (str[i] >= '0' && str[i] <= '9')
    nb = nb * 10 + (str[i++] - '0');
  return (nb * s);
}
