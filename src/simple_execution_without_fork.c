/*
** simple_execution.c for simple_execution.c in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new/src
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 15:13:59 2016 Eric DESCHODT
** Last update Mon Jun  6 14:56:23 2016 Eric DESCHODT
*/

#include "42sh.h"

int		execute_one_without_fork(char **argv, t_listdata *list_env)
{
  if ((execve(argv[0], argv, list_env->environ)) == -1)
    {
      list_env->valret = 1;
      my_perror(strerror(errno));
      my_perror("\n");
      return (-1);
    }
  return (1);
}

int		modify_path_exec_without_fork(char **path,
					 char **argv,
					 int i,
					 t_listdata *list_env)
{
  free(argv[0]);
  argv[0] = my_strdup(path[i]);
  setenv_path_cmd(argv[0], list_env);
  if (execute_one_without_fork(argv, list_env) == -1)
    return (-1);
  return (1);
}

int     path_test_without_fork(char **path,
			       char **argv,
			       t_listdata *list_env)
{
  int    i;
  char   flag;
  DIR    *dir;

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
	return (modify_path_exec_without_fork(path, argv, i, list_env));
    }
  return (0);
}

int		simple_execution_without_fork(char **argv, t_listdata *list_env)
{
  char		**path;
  t_list	*tmp;
  int		val;

  if (access(argv[0], X_OK) != -1)
    return (execute_one_without_fork(argv, list_env));
  else
    {
      if ((tmp = find_pathern(list_env)) == NULL)
	set_default_env(&path, list_env);
      else
	path = str_to_wordtab(&tmp->str[5], ':');
      val = path_test_without_fork(path, argv, list_env);
      if (val == 0 || val == -1)
	{
	  error_msg(argv[0], ": Command not found.\n");
	  list_env->check_cmd = 1;
	  list_env->valret = 1;
	  free_tab(path);
	  return (-1);
	}
      else
	free_tab(path);
    }
  return (0);
}

int             execute_without_fork(t_listdata *list_env,
				     char *cmd)
{
  char          **argv;
  int           fd[2][2];

  if (cmd == NULL || list_env == NULL)
    return (-1);
  fd[1][0] = -1;
  fd[0][0] = -1;
  if (init_fd_right(&fd[1][0], cmd, &fd[1][1]) == -1
      || init_redirection_left(&fd[0][0], cmd, &fd[0][1]) == -1)
    return (-1);
  list_env->echo_cmd = my_strdup(cmd);
  if (((argv = create_tab_and_epur(cmd, ' ')) == NULL)
      || (modifyargv(argv, list_env) == -1))
    return (res_dup_ret(fd, -1));
  argv = check(argv, list_env);
  argv = globbing(argv);
  if (buildin(argv, list_env) == 1)
    {
      free_tab(argv);
      exit(0);
    }
  if (simple_execution_without_fork(argv, list_env) == -1)
    return (res_dup_ret(fd, -1));
  free_tab(argv);
  return (res_dup_ret(fd, 0));
}
