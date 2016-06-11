/*
** my_putnbr_base.c for my_putnbr_base.c in /home/lopez_i/traitements/PSU_2015_my_printf
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed Nov 11 12:01:04 2015 loic lopez
** Last update Wed May  4 12:22:33 2016 Loic Lopez
*/

#include "lib.h"

int	call_binary(va_list list)
{
  my_putnbr_base(va_arg(list, int), "01");
  return (0);
}

int	call_base_octal(va_list list)
{
  my_putnbr_base(va_arg(list, int), "01234567");
  return (0);
}

int	call_base_x(va_list list)
{
  my_putnbr_base(va_arg(list, int), "0123456789abcdef");
  return (0);
}

int	call_base_X(va_list list)
{
  my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
  return (0);
}

int     my_putnbr_base(int nbr, char *base)
{
  int	start;
  int	taille;
  int	nombre;
  int	mod;

  nombre = 0;
  taille = my_strlen(base);
  if (nbr < 0)
    {
      nombre = nombre + my_putchar('-');
      nombre = nombre + my_putnbr_base(-nbr, base);
    }
  else
    {
      mod = nbr % taille;
      start = (nbr - mod) / taille;
      if (start != 0)
	my_putnbr_base(start, base);
      nombre = my_putchar(base[mod]);
    }
  return (nombre);
}
