/*
** simple_execution.c for simple_execution.c in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new/src
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 15:13:59 2016 Eric DESCHODT
** Last update Fri May 27 13:08:26 2016 Eric DESCHODT
*/

#include "42sh.h"

t_list		*find_pathern(t_listdata *list_env)
{
  t_list	*tmp;

  tmp = list_env->list;
  while (tmp != NULL)
    {
      if (my_strncmp(tmp->str, "PATH=", 5) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
