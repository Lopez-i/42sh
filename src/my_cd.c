/*
** my_cd.c for my_cd.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 10:05:46 2016 Loic Lopez
** Last update Mon Jun  6 17:50:01 2016 loic lopez
*/

#include "42sh.h"

int		contribute_cd(char *my_get_pwd,
			      char *my_get_wd,
			      t_listdata *list_env)
{
  char		*argv[4];

  argv[0] = "setenv";
  argv[1] = "OLDPWD";
  argv[2] = my_get_pwd;
  argv[3] = NULL;
  setenvsh(argv, list_env);
  argv[0] = "setenv";
  argv[1] = "PWD";
  argv[2] = my_get_wd;
  argv[3] = NULL;
  setenvsh(argv, list_env);
  return (1);
}

int		my_cd(const char *path, t_listdata *list_env)
{
  char		my_get_wd[4096];
  char		my_get_pwd[4096];
  int		i;

  i = -1;
  while ((getcwd(my_get_pwd, ++i)) == NULL)
    if (i == 4096)
      return (-1);
  if (chdir(path) != -1)
    {
      i = -1;
      while ((getcwd(my_get_wd, ++i)) == NULL)
	if (i == 4096)
	  return (-1);
      return (contribute_cd(my_get_pwd, my_get_wd, list_env));
    }
  else
    {
      list_env->valret = 1;
      my_perror((char *)path);
      my_perror(": ");
      my_perror(strerror(errno));
      my_perror(".\n");
    }
  return (0);
}

void	cd_parsing(char **argv, t_listdata *list_env)
{
  if ((check_cd(list_env, argv)) == 1)
    return ;
  else if ((check_cd_minus(list_env, argv)) == 1)
    return ;
  else
    my_cd(argv[1], list_env);
  return ;
}
