/*
** read_non_canon.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Jun  4 21:29:00 2016 Eric DESCHODT
** Last update Sun Jun  5 17:13:23 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*appending(char *cmd, int i, char *new)
{
  char		*save;
  char		*tmp;
  int		j;

  save = NULL;
  if (cmd != NULL)
    {
      save = my_strdup(&cmd[i]);
      cmd[i] = '\0';
    }
  tmp = cmd;
  cmd = my_strcat(cmd, new);
  free(tmp);
  tmp = cmd;
  cmd = my_strcat(cmd, save);
  free(tmp);
  write(0, new, 1);
  write(0, save, my_strlen(save));
  j = -1;
  while (++j < my_strlen(save))
    write(0, "\b", 1);
  free(save);
  return (cmd);
}
