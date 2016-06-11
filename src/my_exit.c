/*
** my_exit.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 10:01:15 2016 Eric DESCHODT
** Last update Thu May 26 13:42:41 2016 Loic Lopez
*/

#include "42sh.h"

void		my_exit(char **argv, t_listdata *list_env)
{
  list_env->exit = 1;
  if (argv[0] != NULL && argv[1] == NULL)
    list_env->valret = 0;
  else if (argv[0] != NULL && argv[1] != NULL)
    {
      if (my_str_is_num(argv[1]) != -1)
	list_env->valret = my_getnbr(argv[1]);
      else
	{
	  my_putstr("exit: Expression Syntax.\n");
	  list_env->exit = 0;
	}
    }
}
