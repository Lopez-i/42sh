/*
** list.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Tue Jan  5 09:11:09 2016 Eric DESCHODT
** Last update Thu Jun  2 14:51:52 2016 Eric DESCHODT
*/

#include "42sh.h"

void            free_tab(char **argv)
{
  int           i;

  i = 0;
  if (argv == NULL)
    return ;
  while (argv[i] != NULL)
    {
      free(argv[i]);
      i++;
    }
  free(argv);
}

void	        init_listdata(t_listdata *list_env)
{
  list_env->exit = 0;
  list_env->valret = 0;
  list_env->check_cmd = false;
  list_env->size = 0;
  list_env->list = NULL;
  list_env->end = NULL;
}

void            free_list(t_listdata *list_cmd)
{
  t_list        *tmp;

  if (list_cmd->list == NULL)
    return ;
  tmp = list_cmd->list;
  while (tmp != NULL && tmp->next != NULL)
    {
      tmp = tmp->next;
      (tmp->prev->str != NULL) ? free(tmp->prev->str) : free(NULL);
      (tmp->prev != NULL) ? free(tmp->prev) : free(NULL);
    }
  (tmp->str != NULL) ? free(tmp->str) : free(NULL);
  (tmp != NULL) ? free(tmp) : free(NULL);
}

void            my_put_in_list(t_listdata *lista,
			       char *text)

{
  t_list        *new_elem;

  new_elem = malloc(sizeof(t_list) * 1);
  if (new_elem != NULL)
    {
      new_elem->str = my_strdup(text);
      lista->size++;
      if (lista->list == NULL && lista->end == NULL)
        {
          lista->list = new_elem;
          lista->end = new_elem;
          new_elem->next = NULL;
          new_elem->prev = NULL;
        }
      else
        {
          new_elem->prev = lista->end;
          new_elem->next = NULL;
          lista->end->next = new_elem;
          lista->end = lista->end->next;
        }
    }
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  if (list == NULL)
    return ;
  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
