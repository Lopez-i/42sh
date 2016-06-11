/*
** my_echo_ter.c for echo_ter in /home/piazza_p/rendu/PSU/PSU_2015_42sh
**
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
**
** Started on  Fri Jun  3 14:15:29 2016 pierre piazza
** Last update Fri Jun  3 15:37:17 2016 pierre piazza
*/

#include "42sh.h"

int	aff_non_printable(char *str, int j,
			  char *flags[8], char *flags_ret[8])
{
  int	i;

  if (str[j] == '\\' && str[j + 1])
    {
      i = -1;
      while (flags[++i])
	if (my_strncmp(&str[j], flags[i], 2) == 0)
	  {
	    my_putstr(flags_ret[i]);
	    j = j + 2;
	  }
    }
  return (j);
}
