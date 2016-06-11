/*
** copy_env.c for copy_env.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:25:16 2016 loic lopez
** Last update Sun Jun  5 18:25:23 2016 loic lopez
*/

#include "42sh.h"

void		copy_env(t_listdata *new, t_listdata *origin)
{
  t_list	*tmp;

  new->list = NULL;
  new->end = NULL;
  new->environ = NULL;
  new->size = 0;
  tmp = origin->list;
  while (tmp != NULL)
    {
      my_put_in_list(new, tmp->str);
      tmp = tmp->next;
    }
}
