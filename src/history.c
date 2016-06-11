/*
** history.c for history in /home/deneub_s/PSU_2015_42sh
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Fri Jun  3 14:06:25 2016 stanislas deneubourg
** Last update Mon Jun  6 15:16:58 2016 stanislas deneubourg
*/

#include "42sh.h"

int		history_point(char **argv, t_listdata *list_env)
{
  char		*tmp;

  if (argv[0] == NULL && argv[1] == NULL)
    return (0);
  else if (argv[0][0] == '!')
    {
      if (argv[0][1] == '!')
	exec_found_cmd_from_history(argv, NULL, NULL);
      tmp = &argv[0][1];
      if (my_str_is_num(tmp) == 1 || tmp[0] == '\0')
	find_cmd_with_nbr(argv, tmp, list_env);
      else
	find_cmd_with_command(argv, tmp, list_env);
      return (1);
    }
  return (0);
}

char            *history_tty(char *cmd, t_list **history)
{
  int           j;

  j = 0;
  while (j < my_strlen(cmd))
    {
      write(2, "\b", 1);
      write(2, " ", 1);
      write(2, "\b", 1);
      j++;
    }
  free(cmd);
  if (history == NULL)
    return (NULL);
  cmd = my_strdup((*history)->str);
  write(2, cmd, my_strlen(cmd));
  return (cmd);
}

void		remove_first_elem(t_listdata *list_env)
{
  t_list	*tmp;

  tmp = list_env->list;
  if (tmp == NULL)
    return ;
  list_env->list = list_env->list->next;
  if (list_env->list != NULL)
    list_env->list->prev = NULL;
  list_env->size--;
  free(tmp->str);
  free(tmp);
}

void		add_to_history(char *str, t_listdata *list_env)
{
  if (list_env->size < 100)
    my_put_in_list(list_env->history, str);
  else
    {
      remove_first_elem(list_env->history);
      my_put_in_list(list_env->history, str);
    }
}
