/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Sun Jun  5 18:17:42 2016 loic lopez
*/

#include "42sh.h"

void		create_multi(t_listdata *all_cmd, char *cmd, char sep)
{
  char		*tmp;
  char		*onecmd;
  int		i;

  tmp = cmd;
  while (*tmp != '\0')
    {
      i = 0;
      while (*tmp == ' ')
	tmp++;
      while (tmp[i] != '\0' && tmp[i] != sep)
  	i++;
      if ((onecmd = malloc(sizeof(char) * (i + 1))) == NULL)
	return ;
      tmp = copy_arg(tmp, i, onecmd);
      my_put_in_list(all_cmd, onecmd);
      free(onecmd);
      if (*tmp != 0)
  	tmp++;
    }
}
