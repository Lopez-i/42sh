/*
** alias.c for alias in /home/dupil_l/Semestre2/Systeme_unix/PSU_2015_42sh/src/buildins
**
** Made by loic dupil
** Login   <dupil_l@epitech.net>
**
** Started on  Tue May 24 15:53:56 2016 loic dupil
** Last update Mon Jun  6 12:50:52 2016 Eric DESCHODT
*/

#include "42sh.h"

char    *get_command(char *str, t_list *tmp)
{
  char  *save;
  int   i;
  int   j;

  i = 0;
  while (str[i] != '\0' && str[i] != '\'')
    i++;
  if (str[i] == '\0')
    return (NULL);
  i++;
  j = i;
  while (str[j] != '\0' && str[j] != '\'')
    j++;
  if (str[j] == '\0')
    return (NULL);
  save = my_strdup(&str[i]);
  save[my_strlen(save) - 1] = ' ';
  if (tmp != NULL)
    save = recurs_alias(save, tmp);
  return (save);
}

char            **check(char **argv,
			t_listdata *list_env)
{
  char          *new_argv;
  char          **ret_argv;
  int           i;
  t_listdata    *alias;
  t_list	*tmp;

  alias = list_env->alias;
  new_argv = NULL;
  i = -1;
  while (argv[++i] != NULL)
    {
      tmp = alias->end;
      new_argv = find_alias(argv[i], new_argv, tmp);
    }
  if (new_argv == NULL)
    return (argv);
  else
    {
      free_tab(argv);
      ret_argv = (create_tab_and_epur(new_argv, ' '));
      free(new_argv);
      return (ret_argv);
    }
}
