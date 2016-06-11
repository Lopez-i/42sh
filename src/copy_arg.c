/*
** copy_arg.c for create_multi.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:17:28 2016 loic lopez
** Last update Sun Jun  5 18:17:36 2016 loic lopez
*/

#include "42sh.h"

char            *copy_arg(char *tmp, int i, char *cmd)
{
  int            j;

  j = 0;
  while (j != i)
    {
      cmd[j] = *tmp;
      tmp++;
      j++;
    }
  cmd[j] = '\0';
  return (tmp);
}
