/*
** my_strlen.c for mr_strlen in /home/lopez_i/rendu/Piscine_C_J04
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Thu Oct  1 18:41:40 2015 loic lopez
** Last update Wed May 25 14:01:46 2016 Eric DESCHODT
*/

#include "include/my_printf.h"

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
