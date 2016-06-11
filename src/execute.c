/*
** simple_execution.c for simple_execution.c in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new/src
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 15:13:59 2016 Eric DESCHODT
** Last update Mon Jun  6 15:05:22 2016 Eric DESCHODT
*/

#include "42sh.h"

int	execute_one(char **argv, t_listdata *list_env)
{
  pid_t	pid;

  if ((pid = vfork()) == -1)
    {
      my_perror("ERROR on fork\n");
      return (-1);
    }
  if (pid == 0 && execve(argv[0], argv, list_env->environ) == -1)
    {
      my_perror(strerror(errno));
      my_perror("\n");
      list_env->valret = 1;
      exit(0);
    }
  else if (pid > 0)
    {
      setenv_path_cmd(argv[0], list_env);
      wait_and_print_status(pid);
    }
  return (1);
}

int		res_dup_ret(int fd[2][2], int value)
{
  if (fd[1][0] > 0 && res_dup(&fd[1][1], &fd[1][0], 1) == -1)
    return (-1);
  if (fd[0][0] > 0 && res_dup(&fd[0][1], &fd[0][0], 0) == -1)
    return (-1);
  return (value);
}

int             execute(t_listdata *list_env,
                        char *cmd)
{
  char          **argv;
  int           fd[2][2];

  fd[1][0] = (fd[0][0] = -1);
  list_env->echo_cmd = NULL;
  if (init_fd_right(&fd[1][0], cmd, &fd[1][1]) == -1
      || init_redirection_left(&fd[0][0], cmd, &fd[0][1]) == -1)
    return (-1);
  free(list_env->echo_cmd);
  list_env->echo_cmd = my_strdup(cmd);
  if (((argv = create_tab_and_epur(cmd, ' ')) == NULL)
      || (modifyargv(argv, list_env) == -1))
    return (res_dup_ret(fd, -1));
  argv = check(argv, list_env);
  argv = globbing(argv);
  if (buildin(argv, list_env) == 1)
    {
      free_tab(argv);
      return (res_dup_ret(fd, 0));
    }
  if (simple_execution(argv, list_env) == -1)
    return (res_dup_ret(fd, -1));
  free_tab(argv);
  return (res_dup_ret(fd, 0));
}
