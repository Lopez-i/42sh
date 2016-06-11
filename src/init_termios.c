/*
** init_termios.c for init_termios.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:47:28 2016 loic lopez
** Last update Sun Jun  5 18:47:49 2016 loic lopez
*/

#include "42sh.h"

int		init_termios(struct termios *newtio,
			     struct termios *oldtio,
			     char **cmd,
			     int *i)
{
  if (ioctl(0, TCGETS, oldtio) == -1
      || ioctl(0, TCGETS, newtio) == -1)
    return (-1);
  newtio->c_lflag &= ~ICANON;
  newtio->c_lflag &= ~ECHO;
  if (ioctl(0, TCSETS, newtio) == -1)
    return (-1);
  *cmd = NULL;
  *i = 0;
  return (0);
}
