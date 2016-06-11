/*
** sigInt.c for main.c in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 17:47:51 2016 loic lopez
** Last update Sun Jun  5 17:48:09 2016 loic lopez
*/

#include "42sh.h"

void		sigInt(int sig)
{
  (void)sig;
  write(0, "\n", 1);
  my_putstr(user);
  my_putstr("> ");
}
