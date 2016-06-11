/*
** minishell1.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed Jan  6 10:29:04 2016 Eric DESCHODT
** Last update Sat Jun  4 17:48:17 2016 Eric DESCHODT
*/

#include "42sh.h"

int		check_no_valid_characters(char c)
{
  char		*test;
  int		i;

  test = "̣·”“¢»¬ħđ¶«←↓→$¤¨^£%*€=,:/+-°.^`|[#~¹@#}{]\\§";
  i = -1;
  while (test[++i])
    if (test[i] == c)
      {
	my_perror
	  ("setenv: Variable name must contain alphanumeric characters.\n");
	return (-1);
      }
  return (0);
}

int		check_validate(char *str)
{
  int		i;

  if ((str[0] < 'A' || str[0] > 'Z') && (str[0] < 'a' || str[0] > 'z'))
    {
      my_perror("setenv: Variable name must begin with a letter.\n");
      return (-1);
    }
  i = -1;
  while (str[++i])
    if (check_no_valid_characters(str[i]) == -1)
      return (-1);
  return (0);
}

void		get_new_set(char *var, char **argv)
{
  my_strcpy(var, argv[1]);
  my_strcpy(&var[my_strlen(var)], "=");
  my_strcpy(&var[my_strlen(var)], argv[2]);
}

char		*get_var(char **argv)
{
  char		*var;

  if ((var = malloc(sizeof(char) * (my_strlen(argv[1])
				    + my_strlen(argv[2]) + 2))) != NULL)
    get_new_set(var, argv);
  return (var);
}

void            setenvsh(char **argv, t_listdata *listenv)
{
  t_list	*tmp;
  char		*var;

  var = NULL;
  if (argv[1] != NULL)
    {
      if ((check_validate(argv[1])) == -1)
	return ;
      tmp = listenv->list;
      while (tmp != NULL &&
	     (my_strncmp(argv[1], tmp->str, my_strlen(argv[1])) != 0))
	tmp = tmp->next;
      var = get_var(argv);
      if (var != NULL && tmp == NULL)
	my_put_in_list(listenv, var);
      else if (var != NULL && tmp != NULL)
	{
	  free((tmp->str != NULL) ? tmp->str : NULL);
	  tmp->str = my_strdup(var);
	}
      stockenv(listenv);
    }
  else
    my_show_list(listenv->list);
  free(var);
}
