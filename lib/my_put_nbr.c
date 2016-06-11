/*
** my_put_nbr.c for my_put_nbr in /home/lopez_i/my_put_nbr
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Fri Oct 16 15:39:01 2015 loic lopez
** Last update Wed May  4 12:26:34 2016 Loic Lopez
*/

#include "lib.h"

int	call_number(va_list list)
{
  my_put_nbr(va_arg(list, int));
  return (0);
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb < 10)
    my_putchar(nb + '0');
  else if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
    }
  else
    my_putstr("Entrée Invalide");
  return (0);
}
