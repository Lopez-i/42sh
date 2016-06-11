/*
** my_putnbr_base.c for my_putnbr_base.c in /home/lopez_i/traitements/PSU_2015_my_printf
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Nov  9 16:31:03 2015 loic lopez
** Last update Wed May  4 12:22:48 2016 Loic Lopez
*/

#include "lib.h"

int	my_putnbr_base_size(size_t nbr, char *base)
{
  size_t	start;
  size_t	taille;
  size_t	nombre;
  size_t	mod;

  nombre = 0;
  taille = my_strlen(base);
  mod = nbr % taille;
  start = (nbr - mod) / taille;
  if (start != 0)
    my_putnbr_base_size(start, base);
  nombre = my_putchar(base[mod]);
  return (nombre);
}
