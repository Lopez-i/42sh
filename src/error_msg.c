/*
** simple_execution.c for simple_execution.c in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new/src
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 15:13:59 2016 Eric DESCHODT
** Last update Fri May 27 13:06:26 2016 Eric DESCHODT
*/

#include "42sh.h"

int		error_msg(char *name, char *str)
{
  my_perror(name);
  my_perror(str);
  return (-1);
}
