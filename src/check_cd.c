/*
** check_cd.c for check_cd.c in /home/lopez_i/traitements/PSU_2015_minishell2
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Apr  4 18:41:30 2016 Loic Lopez
** Last update Wed May 25 14:24:59 2016 Eric DESCHODT
*/

#include "42sh.h"

int		check_cd(t_listdata *list_env, char **argv)
{
  t_list	*tmp;

  tmp = list_env->list;
  if ((argv[0] != NULL && argv[1] == NULL) ||
      (argv[0] != NULL && argv[1][0] == '~'))
    {
      while (tmp != NULL)
	{
	  if (my_strncmp(tmp->str, "HOME", 4) == 0)
	    {
	      argv[1] = NULL;
	      argv[1] = my_strdup(&tmp->str[5]);
	      my_cd(argv[1], list_env);
	      return (1);
	    }
	  tmp = tmp->next;
	}
      my_perror("No Home directory\n");
      return (1);
    }
  return (0);
}

int	check_cd_minus(t_listdata *list_env, char **argv)
{
  t_list	*tmp;

  tmp = list_env->list;
  if ((my_strncmp(argv[0], "cd", my_strlen("cd"))) == 0
      && (my_strncmp(argv[1], "-", 1)) == 0)
    {
      while (tmp != NULL)
	{
	  if (tmp->str != NULL && my_strncmp(tmp->str, "OLDPWD", 6) == 0)
	    {
	      my_cd(&tmp->str[7], list_env);
	      return (1);
	    }
	  tmp = tmp->next;
	}
      my_perror("OLDPWD not found\n");
      return (1);
    }
  return (0);
}
