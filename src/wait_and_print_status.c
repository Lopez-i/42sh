/*
** wait_and_print_status.c for wait_and_print_status.c in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Fri Jun  3 17:31:47 2016 loic lopez
** Last update Fri Jun  3 17:32:06 2016 loic lopez
*/

#include "42sh.h"

void	wait_and_print_status(pid_t pid)
{
  int	status;

  waitpid(pid, &status, 0);
  if (WIFSIGNALED(status))
    print_status(WTERMSIG(status));
}
