/*
** my_printf_bis.c for my_printf_bis.c in /home/lopez_i/traitements/PSU_2015_my_printf/Sources
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed Nov 11 15:22:12 2015 loic lopez
** Last update Wed May  4 12:20:04 2016 Loic Lopez
*/

#include "lib.h"

int	*flag_error(char f)
{
  int	i;
  char	*flag;

  i = 0;
  flag = "dioxXucspbS";
  if (f == '%')
    {
      my_putchar('%');
      return (0);
    }
  while (flag[i] != f)
    {
      if (flag[i] == '\0')
	{
	  my_putchar('%');
	  my_putchar(f);
	}
      i++;
    }
  return (0);
}

int	*flags_func(char f, va_list list)
{
  int	(*tab[11])(va_list list);
  int	i;
  char *flag;

  i = -1;
  flag = "dioxXucspbS";
  flag_error(f);
  tab[0] = call_number;
  tab[1] = call_number;
  tab[2] = call_base_octal;
  tab[3] = call_base_x;
  tab[4] = call_base_X;
  tab[5] = call_unsigned;
  tab[6] = call_char;
  tab[7] = call_string;
  tab[8] = call_adress;
  tab[9] = call_binary;
  tab[10] = call_noprintable;
  while (flag[++i] != '\0')
    {
      if (flag[i] == f)
      	tab[i](list);
    }
  return (0);
}

int	my_printf(const char *format, ...)
{
  int	i;
  va_list	list;

  i = 0;
  va_start	(list, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  flags_func(format[i + 1], list);
	  i++;
	  while (format[i] == ' ')
	    {
	      flags_func(format[i + 1], list);
	      i++;
	    }
	}
      else
	my_putchar(format[i]);
      i++;
    }
   va_end	(list);
  return (0);
}
