/*
** alias_find.c for alias_find.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:02:58 2016 loic lopez
** Last update Mon Jun  6 13:16:50 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*find_alias(char *argv,
			    char *new_argv,
			    t_list *tmp)
{
  int		i;
  char		*to_free;

  i = 0;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->str[i] != '\0' && tmp->str[i] != '=')
	i++;
      if (tmp->str[i] != '\0' && my_strlen(argv) == i
	  && (my_strncmp(tmp->str, argv, i)) == 0)
        {
	  if ( get_command(tmp->str, tmp) == NULL)
	    return (NULL);
	  to_free = new_argv;
          new_argv = my_strcat(new_argv, get_command(tmp->str, tmp));
	  free(to_free);
          return (new_argv);
        }
      tmp = tmp->prev;
    }
  new_argv = strcat_cmd(new_argv, argv);
  return (new_argv);
}
