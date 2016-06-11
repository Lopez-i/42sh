/*
** read_non_canon.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Sat Jun  4 21:29:00 2016 Eric DESCHODT
** Last update Mon Jun  6 17:13:15 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*read_non_canon(int fd, t_listdata *list_env)
{
  char		*cmd;
  char		str_to_cat[2];
  struct termios newtio;
  struct termios oldtio;
  t_list	*history;
  int		i;

  history = list_env->history->end;
  if ((init_termios(&newtio, &oldtio, &cmd, &i)) == -1)
    return (NULL);
  while (42)
    {
      str_to_cat[0] = '\0';
      str_to_cat[1] = '\0';
      read(fd, str_to_cat, 1);
      if (str_to_cat[0] == 4)
	return (close_termios(NULL, str_to_cat, &oldtio));
      if (str_to_cat[0] == 5 || str_to_cat[0] == '\n' || str_to_cat[0] == '\0')
	break ;
      cmd = (str_to_cat[0] == 9) ? auto_complete(&i, fd, cmd)
	: (str_to_cat[0] == 27) ? arrowsing(&i, fd, cmd, &history)
	: (str_to_cat[0] == 127) ? erasing(cmd, &i, 0)
	: appending(cmd, i++, str_to_cat);
    }
  return (close_termios(cmd, str_to_cat, &oldtio));
}
