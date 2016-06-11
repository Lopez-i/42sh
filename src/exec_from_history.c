/*
** exec_from_history.c for exec from history in /home/deneub_s/PSU_2015_42sh
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon Jun  6 14:20:55 2016 stanislas deneubourg
** Last update Mon Jun  6 15:28:55 2016 stanislas deneubourg
*/

#include "42sh.h"

void            exec_found_cmd_from_history(char **argv, t_list *tmp2,
                                            t_listdata *list_env)
{
  if (tmp2 == NULL)
    {
      my_perror("42sh: ");
      my_perror(argv[0]);
      my_perror(": event not found\n");
    }
  else
    interpret_cmd(tmp2->str, list_env);
}

void		find_cmd_with_nbr(char **argv, char *tmp,
				  t_listdata *list_env)
{
  int		nb;
  int		i;
  t_list	*tmp2;

  nb = my_getnbr(tmp);
  if (nb == 0)
    nb = 1;
  i = -1;
  tmp2 = list_env->history->end;
  while (tmp2 != NULL && tmp2->prev != NULL && ++i < nb)
    tmp2 = tmp2->prev;
  exec_found_cmd_from_history(argv, tmp2, list_env);
}

void            find_cmd_with_command(char **argv, char *tmp,
				      t_listdata *list_env)
{
  t_list	*tmp2;

  tmp2 = list_env->history->end;
  while (tmp2 != NULL && tmp2->prev != NULL && my_strcmp(tmp, tmp2->str) == 0)
    tmp2 = tmp2->prev;
  exec_found_cmd_from_history(argv, tmp2, list_env);
}
