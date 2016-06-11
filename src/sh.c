/*
** sh.c for sh.c in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 17:50:01 2016 loic lopez
** Last update Mon Jun  6 15:26:41 2016 Eric DESCHODT
*/

#include "42sh.h"

void		free_sh(t_listdata *list_env)
{
  free_list(list_env->alias);
  free_list(list_env->history);
  free_list(list_env);
  free(list_env->echo_cmd);
  free_tab(list_env->environ);
  free(list_env->alias);
  free(list_env->history);
}

void		print_prompt(t_listdata *list_env)
{
  if (isatty(0) == 1)
    {
      my_putstr((user = get_prompt(list_env)));
      my_putstr("> ");
    }
}

void		interpret_cmd(char *cmd,
			      t_listdata *list_env)
{
  t_listdata	all_cmd;

  cmd = replace_t(cmd);
  init_listdata(&all_cmd);
  create_multi(&all_cmd, cmd, ';');
  all_execute(list_env, &all_cmd);
  free_list(&all_cmd);
}

int		sh(t_listdata *list_env)
{
  char		*cmd;

  while (list_env->exit == 0)
    {
      print_prompt(list_env);
      if ((isatty(0) == 1 && (cmd = read_non_canon(0, list_env)) == NULL)
	  || (isatty(0) == 0 && (cmd = get_next_line(0)) == NULL))
	break ;
      else
	{
	  interpret_cmd(cmd, list_env);
	  if ((check_empty_str(cmd)) != -1)
	    add_to_history(cmd, list_env);
	  free(cmd);
	}
    }
  my_putstr(list_env->exit != 0 ? "exit\n" : "");
  overwrite_42shhistory(list_env->history);
  free_sh(list_env);
  return (list_env->valret);
}
