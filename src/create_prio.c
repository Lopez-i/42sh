/*
** create_prio.c for create_prio.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:15:43 2016 loic lopez
** Last update Sun Jun  5 20:10:41 2016 loic lopez
*/

#include "42sh.h"

char		get_tag(int *i, char *tmp)
{
  int		tag;

  tag = 0;
  while (tmp[*i] != '\0' && tmp[*i + 1] != '\0')
    {
      if (tmp[*i] == '&' && tmp[*i + 1] == '&')
	{
	  tag = 1;
	  break ;
	}
      else if (tmp[*i] == '|' && tmp[*i + 1] == '|')
	{
	  tag = 2;
	  break ;
	}
      (*i)++;
    }
  return (tag);
}

void		create_prio(t_listdata *all_prio, char *cmd)
{
  char		*tmp;
  char		*onecmd;
  char		tag;
  int		i;

  tmp = cmd;
  while (*tmp != '\0')
    {
      i = 0;
      while (*tmp == ' ')
	tmp++;
      tag = get_tag(&i, tmp);
      if (tag == 0)
	i++;
      if ((onecmd = malloc(sizeof(char) * (i + 1))) == NULL)
	return ;
      tmp = copy_arg(tmp, i, onecmd);
      my_put_in_list(all_prio, onecmd);
      all_prio->end->tag = tag;
      free(onecmd);
      if (*tmp != 0)
  	tmp++;
      if (*tmp != 0)
  	tmp++;
    }
}
