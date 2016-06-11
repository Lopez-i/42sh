/*
** my_putstr.c for my_putstr in /home/lopez_i/rendu/Piscine_C_J04
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Thu Oct  1 16:41:05 2015 loic lopez
** Last update Wed May  4 12:21:59 2016 Loic Lopez
*/

#include "lib.h"

int	call_string(va_list list)
{
  my_putstr(va_arg(list, char *));
  return (0);
}

int	my_putstr(char *str)
{
  int c;

  c = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c = c + 1;
    }
  return (0);
}
