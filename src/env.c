/*
** env.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Tue May 24 09:47:48 2016 Eric DESCHODT
** Last update Sun Jun  5 18:22:30 2016 loic lopez
*/

#include "42sh.h"

void		env(char **argv,
		    t_listdata *listenvorigin)
{
  int		i;
  int		space;
  int		flag;
  t_listdata	listenv;
  int		unset;

  copy_env(&listenv, listenvorigin);
  space = 0;
  i = 1;
  flag = 0;
  while (argv[i] != NULL && flag == 0)
    {
      unset = check_unset(argv, &i, &listenv);
      if ((unset == -1) && ((my_strcmp(argv[i], "-0") == 0)
			   || (my_strcmp(argv[i], "--null") == 0)))
	space = 1;
      else if (unset == -1)
	flag = modifyenv(argv[i], &listenv);
      i = (flag == 0) ? i + 1 : i;
    }
  stockenv(&listenv);
  listenvorigin->valret = 0;
  exec_with_env(&argv[i], &listenv, space);
  free_list(&listenv);
  free_tab(listenv.environ);
}
