/*
** minishell1.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed Jan  6 10:29:04 2016 Eric DESCHODT
** Last update Wed May 25 14:53:39 2016 Eric DESCHODT
*/

#include "42sh.h"

void		delete_node(t_list *tmp, t_listdata *listenv)
{
  t_list	*prev;
  t_list	*next;

  prev = tmp->prev;
  next = tmp->next;
  if (prev == NULL)
    listenv->list = next;
  else
    prev->next = next;
  if (next == NULL)
    listenv->end = prev;
  else
    next->prev = prev;
  free(tmp->str);
  free(tmp);
}

void		unsetenvsh_append(char *variable, t_listdata *listenv)
{
  t_list	*tmp;

  tmp = listenv->list;
  while (tmp != NULL)
    {
      if (my_strncmp(variable, tmp->str, my_strlen(variable)) == 0
	  && tmp->str[my_strlen(variable)] == '=')
	{
	  delete_node(tmp, listenv);
	  tmp = listenv->list;
	}
      else
	tmp = tmp->next;
    }
}

void            unsetall(t_listdata *listenv)
{
  while (listenv->list != NULL)
    delete_node(listenv->list, listenv);
}

void            unsetenvsh(char **argv, t_listdata *listenv)
{
  int		i;

  i = 1;
  while (argv[i] != NULL)
    unsetenvsh_append(argv[i++], listenv);
  stockenv(listenv);
}
