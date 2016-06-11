/*
** modifyenv.c for modifyenv.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:23:43 2016 loic lopez
** Last update Sun Jun  5 18:24:11 2016 loic lopez
*/

#include "42sh.h"

int		modifyenv(char *var, t_listdata *listenv)
{
  t_list	*tmp;
  int		i;
  char		*new;

  i = 0;
  while (var[i] != '=' && var[i] != '\0')
    i++;
  if (var[i] == '\0')
    return (1);
  tmp = listenv->list;
  while (tmp != NULL)
    {
      if ((my_strncmp(tmp->str, var, i) == 0)
	  && ((new = malloc(sizeof(char) * (my_strlen(var) + 1))) != NULL))
	{
	  my_strcpy(new, var);
	  free((tmp->str != NULL) ? tmp->str : NULL);
	  tmp->str = new;
	}
      tmp = tmp->next;
    }
  return (0);
}
