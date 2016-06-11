/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Mon Jun  6 13:16:23 2016 Eric DESCHODT
*/

#include "42sh.h"

int		close_exec(int pipefd[2],
			   t_listdata *list_env,
			   t_list *tmp)
{
  if (close(pipefd[1]) == -1 || dup2(pipefd[0], 0) == -1)
    return (1);
  if ((execute_without_fork(list_env, tmp->str)) == -1)
    {
      list_env->valret = 1;
      exit(0);
      return (1);
    }
  return (0);
}

int		simple_pipe(t_listdata *list_env,
			    t_list *tmp,
			    int i)
{
  pid_t		pid;
  int		pipefd[2];

  if (list_env->valret == 1 || pipe(pipefd) == -1)
      return (1);
  if (tmp != NULL)
    {
      pid = vfork();
      if (pid == 0)
	{
	  if (tmp->prev == NULL)
	    exit(0);
	  if (close(pipefd[0]) == -1 || dup2(pipefd[1], 1) == -1)
	    return (1);
	  list_env->valret = simple_pipe(list_env, tmp->prev, i + 1);
	  return (list_env->valret);
	}
      else if (pid > 0)
	return (close_exec(pipefd, list_env, tmp));
      else
	return (1);
    }
  return (0);
}

int		piping(t_listdata *list_env,
		       t_list *tmp)
{
  pid_t		pid2;

  pid2 = vfork();
  if ((pid2 == 0) && (simple_pipe(list_env, tmp, 0)) == 1)
    {
      list_env->valret = 1;
      return (-1);
    }
  else if (pid2 > 0)
    wait_and_print_status(pid2);
  else
    {
      list_env->valret = 1;
      return (-1);
    }
  return (0);
}
