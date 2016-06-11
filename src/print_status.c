/*
** print_status.c for print_status. in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Fri Jun  3 17:28:31 2016 loic lopez
** Last update Fri Jun  3 17:32:08 2016 loic lopez
*/

#include "42sh.h"

void	print_status(int status)
{
  int	i;

  i = -1;
  while (sig_error[++i].status)
    if (sig_error[i].status == status)
      my_perror(sig_error[i].message);
}
