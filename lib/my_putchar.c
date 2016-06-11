/*
** my_putchar.c for my_putchar in /home/lopez_i/rendu/library
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Oct 12 09:58:34 2015 loic lopez
** Last update Wed May  4 12:23:20 2016 Loic Lopez
*/

#include "lib.h"

int	call_char(va_list list)
{
  my_putchar(va_arg(list, int));
  return (0);
}

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
