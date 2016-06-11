/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Sat Jun  4 14:57:10 2016 loic lopez
*/

#include "42sh.h"

char            *environvari(t_listdata *listenv, char *av)
{
  char          *new;
  t_list        *tmp;

  new = NULL;
  tmp = listenv->list;
  while (tmp != NULL)
    {
      if ((my_strncmp(tmp->str, av, my_strlen(av)) == 0)
          && ((new = malloc(sizeof(char)
                            * (my_strlen(tmp->str) + 1))) != NULL))
        {
          my_strcpy(new, &tmp->str[my_strlen(av) + 1]);
          return (new);
        }
      tmp = tmp->next;
    }
  return (NULL);
}

int            modifyargv(char **argv, t_listdata *list_env)
{
  int           i;
  char          *new;

  i = -1;
  while (argv != NULL && argv[++i] != NULL)
    {
      if (argv[i][0] == '$')
        {
          new = environvari(list_env, &argv[i][1]);
          if (new != NULL)
            free(argv[i]);
	  else if (my_strncmp(argv[i], "$term", 5) == 0)
	    {
	      argv[i][0] = 'x';
	      return (0);
	    }
	  else
	    {
	      my_printf("%s: Undefined variable\n", &argv[i][1]);
	      return (-1);
	    }
          argv[i] = new;
        }
    }
  return (0);
}
