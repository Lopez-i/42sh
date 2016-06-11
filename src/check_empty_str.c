/*
** check_empty_str.c for check empty str in /home/deneub_s/PSU_2015_42sh
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Sun Jun  5 16:05:41 2016 stanislas deneubourg
** Last update Mon Jun  6 15:23:24 2016 Eric DESCHODT
*/

#include "42sh.h"

int	check_empty_str(char *str)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  if (str == NULL)
    return (-1);
  if (str[0] == '!')
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	cpt++;
      i++;
    }
  if (cpt == my_strlen(str))
    return (-1);
  return (0);
}
