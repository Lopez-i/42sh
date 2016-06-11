/*
** read_non_canon.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Jun  4 21:29:00 2016 Eric DESCHODT
** Last update Mon Jun  6 10:38:58 2016 Eric DESCHODT
*/

#include "42sh.h"

char            *erasing(char *cmd, int *i, char flag)
{
  char          *save;
  int           j;

  if (cmd == NULL || *i == 0 || my_strlen(cmd) == 0)
    return (NULL);
  if (flag == 0)
    (*i)--;
  save = my_strdup(&cmd[(*i) + 1]);
  cmd[*i] = '\0';
  cmd = my_strcat(cmd, save);
  if (flag == 0)
    write(0, "\b", 1);
  write(0, save, my_strlen(save));
  write(0, " ", 1);
  j = -1;
  while (++j < my_strlen(save))
    write(0, "\b", 1);
  write(0, "\b", 1);
  if (my_strlen(cmd) == 0)
    return (NULL);
  return (cmd);
}
