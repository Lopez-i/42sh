/*
** minishell1.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed Jan  6 10:29:04 2016 Eric DESCHODT
** Last update Fri May 27 13:25:56 2016 Eric DESCHODT
*/

#include "42sh.h"
void		exec_with_env(char **argv,
			      t_listdata *list_env,
			      int space)
{
  t_list	*tmp;

  if (argv != NULL && argv[0] == NULL)
    {
      tmp = list_env->list;
      while (tmp != NULL)
	{
	  my_putstr(tmp->str);
	  if (space != 1)
	    my_putchar('\n');
	  tmp = tmp->next;
	}
    }
  else if (argv != NULL)
    simple_execution(argv, list_env);
}
