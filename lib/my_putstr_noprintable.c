/*
** my_putstr_noprintable.c for my_putstr_noprintable.c in /home/lopez_i/traitements/PSU_2015_my_printf
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Nov  9 17:17:14 2015 loic lopez
** Last update Wed May  4 12:27:23 2016 Loic Lopez
*/

#include "lib.h"

int	call_noprintable(va_list list)
{
  my_putstr_noprintable(va_arg(list, char *));
  return (0);
}

int	my_putstr_noprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  if (str[i] > 0 && str[i] <= 7)
	    {
	      my_putchar(92);
	      my_putstr("00");
	      my_putnbr_base(str[i], "01234567");
	    }
	  else if (str[i] >= 8 && str[i] <= 32)
	    {
	      my_putchar(92);
	      my_putchar('0');
	      my_putnbr_base(str[i], "01234567");
	    }
	}
       else
	 my_putchar(str[i]);
      i++;
    }
  return (0);
}
