/*
** simple_execution.c for simple_execution.c in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new/src
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 15:13:59 2016 Eric DESCHODT
** Last update Mon Jun  6 19:24:53 2016 Eric DESCHODT
*/

#include "42sh.h"

void	create_new_path(char **path,
			int i,
			char **argv)
{
  char	*tmp;

  tmp = path[i];
  path[i] = my_strcat(path[i], "/");
  free(tmp);
  tmp = path[i];
  path[i] = my_strcat(path[i], argv[0]);
  free(tmp);
}

int	modify_path_exec(char **path,
			 char **argv,
			 int i,
			 t_listdata *list_env)
{
  free(argv[0]);
  argv[0] = my_strdup(path[i]);
  execute_one(argv, list_env);
  return (1);
}

int	path_test(char **path,
		  char **argv,
		  t_listdata *list_env)
{
 int	i;
 char	flag;
 DIR	*dir;

 flag = 0;
 i = -1;
 while (path != NULL && path[++i] != NULL && flag == 0)
   {
     dir = opendir(path[i]);
     flag = (dir == NULL && errno != 2) ? 1 : 0;
     if (dir != NULL)
       closedir(dir);
     create_new_path(path, i, argv);
     if (flag == 1 && path[i] != NULL)
       {
	 list_env->valret = 1;
	 return (error_msg(path[i], ": Not a directory.\n"));
       }
     else if (flag == 0 && access(path[i], X_OK) != -1)
       return (modify_path_exec(path, argv, i, list_env));
   }
 return (0);
}

void		set_default_env(char ***path,
				t_listdata *list_env)
{
  char		*av[4];
  t_list	*tmp;

  av[0] = "setenv";
  av[1] = "PATH";
  av[2] = "/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:/usr/heimdal/sbin";
  av[3] = NULL;
  setenvsh(av, list_env);
  tmp = find_pathern(list_env);
  *path = str_to_wordtab(&tmp->str[5], ':');
}

int		simple_execution(char **argv, t_listdata *list_env)
{
  char		**path;
  t_list	*tmp;

  if (access(argv[0], X_OK) != -1)
    return (execute_one(argv, list_env));
  else
    {
      if ((tmp = find_pathern(list_env)) == NULL)
	set_default_env(&path, list_env);
      else
	path = str_to_wordtab(&tmp->str[5], ':');
      if ((path_test(path, argv, list_env) == 0))
	{
	  error_msg(argv[0], ": Command not found.\n");
	  list_env->valret = 1;
	  free_tab(path);
	  return (-1);
	}
      else
	free_tab(path);
    }
  return (0);
}
