/*
** read_non_canon.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Sat Jun  4 21:29:00 2016 Eric DESCHODT
** Last update Mon Jun  6 10:38:21 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*move_left(char *cmd, t_list **history, int *i)
{
  (void)history;
  if ((*i) > 0)
    {
      (*i)--;
      write(2, "\b", 1);
    }
  return (cmd);
}

char		*move_right(char *cmd, t_list **history, int *i)
{
  (void)history;
  if (*i < my_strlen(cmd))
    write(2, &cmd[(*i)++], 1);
  return (cmd);
}

char		*move_up(char *cmd, t_list **history, int *i)
{
  cmd = history_tty(cmd, history);
  *i = my_strlen(cmd);
  if ((*history)->prev != NULL)
    (*history) = (*history)->prev;
  return (cmd);
}

char		*move_down(char *cmd, t_list **history, int *i)
{
  if ((*history)->next != NULL)
    {
      *i = my_strlen(cmd);
      cmd = history_tty(cmd, history);
      (*history) = (*history)->next;
    }
  else
    {
      *i = 0;
      cmd = history_tty(cmd, NULL);
    }
  return (cmd);
}

char		*arrowsing(int *i,
			  int fd,
			  char *cmd,
			  t_list **history)
{
  char		str_to_cat[2];
  char		*(*funct[4])(char *cmd, t_list **history, int *i);
  int		cas;

  funct[0] = &move_up;
  funct[1] = &move_down;
  funct[2] = &move_right;
  funct[3] = &move_left;
  str_to_cat[0] = '\0';
  str_to_cat[1] = '\0';
  read(fd, str_to_cat, 1);
  if (str_to_cat[0] == 91)
    {
      read(fd, str_to_cat, 1);
      cas = str_to_cat[0];
      if (cas >= 65 && cas <= 68 && *history != NULL)
	cmd = funct[cas - 65](cmd, history, i);
      else
	{
	  read(fd, str_to_cat, 1);
	  if (str_to_cat[0] == 126)
	    cmd = erasing(cmd, i, 1);
	}
    }
  return (cmd);
}
