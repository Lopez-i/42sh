/*
** my_echo.c for echo in /home/piazza_p/rendu/PSU/PSU_2015_42sh
**
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
**
** Started on  Tue May 24 15:37:17 2016 pierre piazza
** Last update Mon Jun  6 19:21:47 2016 Eric DESCHODT
*/

#include "42sh.h"

int		check_double(char **av, int i)
{
  if (my_strcmp(av[i], "--version") == 0)
    {
      print_echo_version();
      return (1);
    }
  else if (my_strcmp(av[i], "--help") == 0)
    {
      print_echo_help();
      return (1);
    }
  else
    return (0);
}

int		check_flags(char **av, t_listdata *listenv)
{
  int		i;
  int		j;

  i = 0;
  while (av[++i])
    {
      j = 0;
      if ((check_double(av, i)) == 1)
	return (2);
      if (av[i][j] != '-')
	return (0);
      else
	while (av[i][++j] != 0)
	  {
	    if (av[i][j] == 'n')
	      listenv->echo_flag.n = 1;
	    else
	      return (1);
	  }
    }
  return (0);
}

char		*parse_str(char *av, int status)
{
  char		*flags[8];
  char		*flags_ret[8];
  int		j;

  j = -1;
  init_flags(flags, flags_ret);
  while (av != NULL && av[++j])
    {
      status = check_status(status, av[j]);
      if (av[j] == '"')
	j++;
      if (status == 1)
	j = aff_non_printable(av, j, flags, flags_ret);
      else
	if (av[j] == '\\' && av[j + 1])
	  j++;
      status = check_status(status, av[j]);
      if (av[j] == '"')
	j++;
      my_putchar(av[j]);
    }
  return ("\0");
}

void		my_aff_echo(char **av, t_listdata *listenv, int status)
{
  int		i;

  i = 0;
  if (check_flags(av, listenv) == 2)
    return ;
  else if (check_flags(av, listenv) == 1)
    listenv->echo_flag.n = 0;
  (listenv->echo_flag.n == 1) ? i++ : 0;
  while (av[++i])
    {
      my_putstr(parse_str(av[i], status));
      if (av[i + 1])
	my_putchar(' ');
    }
  if (listenv->echo_flag.n == 0)
    my_putchar('\n');
}

void		my_echo(char **av, t_listdata *listenv)
{
  char		**echo_tab;
  int		status;

  echo_tab = create_tab_and_epur(listenv->echo_cmd, ' ');
  if (echo_tab == NULL || modifyargv(echo_tab, listenv) == -1)
    return ;
  if ((status = parse_quotes(listenv->echo_cmd)) != 0)
    return ;
  listenv->echo_flag.n = 0;
  if (av[1] == NULL)
    my_putchar('\n');
  else
    my_aff_echo(echo_tab, listenv, status);
}
