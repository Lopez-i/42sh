/*
** close_termios.c for close_termios.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:51:48 2016 loic lopez
** Last update Sun Jun  5 18:52:08 2016 loic lopez
*/

#include "42sh.h"

char		*close_termios(char *cmd,
			       char str_to_cat[2],
			       struct termios *oldtio)
{
 if (cmd == NULL && str_to_cat[0] == '\n')
   cmd = my_strcat(cmd, "");
 if (cmd != NULL)
   write(0, "\n", 1);
 if ((ioctl(0, TCSETS, oldtio)) == -1)
   return (NULL);
  return (cmd);
}
