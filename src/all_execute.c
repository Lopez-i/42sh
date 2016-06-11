/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Mon Jun  6 14:43:46 2016 Eric DESCHODT
*/

#include "42sh.h"

int		res_dup(int *oldstdout,
			int *fd,
			int channel)
{
  if (dup2(*oldstdout, channel) == -1)
    return (-1);
  if (close(*fd) == -1)
    return (-1);
  if (close(*oldstdout) == -1)
    return (-1);
  return (0);
}

int		multi_pipe(char *str,
			   t_listdata *list_env)
{
  t_list	*tmp2;
  t_listdata	all_pipe;
  int		result;

  result = 0;
  init_listdata(&all_pipe);
  create_multi(&all_pipe, str, '|');
  tmp2 = all_pipe.end;
  if (all_pipe.size == 1 && (execute(list_env, tmp2->str)) == -1)
    {
      free_list(&all_pipe);
      return (-1);
    }
  else if (all_pipe.size > 1)
    result = piping(list_env, tmp2);
  free_list(&all_pipe);
  return (result);
}

int		all_execute(t_listdata *list_env,
			    t_listdata *all_cmd)
{
  t_list	*tmp;
  t_list	*tmp2;
  t_listdata	all_prio;

  tmp = all_cmd->list;
  while (tmp != NULL)
    {
      init_listdata(&all_prio);
      create_prio(&all_prio, tmp->str);
      tmp2 = all_prio.list;
      while (tmp2 != NULL)
	{
	  list_env->valret = 0;
	  multi_pipe(tmp2->str, list_env);
	  if ((tmp2->tag == 1 && list_env->valret == 1)
	      || (tmp2->tag == 2 && list_env->valret != 1))
	    break ;
	  if (tmp2 != NULL)
	    tmp2 = tmp2->next;
	}
      free_list(&all_prio);
      tmp = tmp->next;
    }
  return (0);
}
