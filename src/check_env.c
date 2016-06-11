/*
** minishell1.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed Jan  6 10:29:04 2016 Eric DESCHODT
** Last update Sun Jun  5 18:25:26 2016 loic lopez
*/

#include "42sh.h"

int		check_ignore(char *test)
{
  if ((my_strcmp(test, "-i") == 0)
      || (my_strcmp(test, "--ignore-environment") == 0)
      || (my_strcmp(test, "-") == 0))
    return (1);
  return (-1);
}

int		check_unset(char **argv, int *i, t_listdata *listenv)
{
  if ((my_strcmp(argv[(*i)], "-u") == 0 && argv[(*i) + 1] != NULL))
    {
      unsetenvsh_append(argv[(*i)++ + 1], listenv);
      return (1);
    }
  else if (check_ignore(argv[(*i)]) == 1)
    {
      unsetall(listenv);
      return (1);
    }
  else if ((my_strncmp(argv[(*i)], "--unset=", 8)) == 0)
    {
      unsetenvsh_append(&argv[(*i)][8], listenv);
      return (1);
    }
  return (-1);
}
