/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Mon Jun  6 14:01:53 2016 Eric DESCHODT
*/

#include "42sh.h"

void		init_builds(char *name[9],
			    void (*builtin[9])(char **, t_listdata *))
{
  name[0] = "exit";
  name[1] = "cd";
  name[2] = "env";
  name[3] = "unsetenv";
  name[4] = "setenv";
  name[5] = "help";
  name[6] = "echo";
  name[7] = "source";
  name[8] = NULL;
  builtin[0] = &my_exit;
  builtin[1] = &cd_parsing;
  builtin[2] = &env;
  builtin[3] = &unsetenvsh;
  builtin[4] = &setenvsh;
  builtin[5] = &my_help;
  builtin[6] = &my_echo;
  builtin[7] = &source;
  builtin[8] = NULL;
}

int		check_format_scripting(char *src, char *fmt)
{
  int		i;
  int		j;

  i = my_strlen(src) - 1;
  j = my_strlen(fmt) - 1;
  while (j >= 0)
    {
      if (src[i] != fmt[j])
	return (-1);
      i--;
      j--;
    }
  return (0);
}

int		execute_basic_scripting(int fd, t_listdata *list_env)
{
  char		*script;

  script = get_next_line(fd);
  if (my_strcmp(script, "#42sh") == 0)
    {
      list_env->echo_cmd = NULL;
      free(script);
      while ((script = get_next_line(fd)) != NULL)
	{
	  interpret_cmd(script, list_env);
	  free(script);
	}
      close(fd);
      return (1);
    }
  else
    {
      close(fd);
      free(script);
    }
  return (0);
}

int		basic_scripting(char **argv, t_listdata *list_env)
{
  int		fd;

  if (check_format_scripting(argv[0], ".sh") == 0)
    {
      if ((fd = open(argv[0], O_RDONLY)) == -1)
	{
	  my_perror("file script doesn't exist.\n");
	  return (1);
	}
      else if (my_strncmp(argv[0], "./", 2) == 0)
	if ((execute_basic_scripting(fd, list_env)) == 1)
	  return (1);
    }
  return (0);
}

int		buildin(char **argv, t_listdata *list_env)
{
  char		*name[9];
  void		(*builtin[9])(char **, t_listdata *);
  int		i;

  if (argv == NULL || history_point(argv, list_env) == 1 ||
      basic_scripting(argv, list_env) == 1)
    return (1);
  init_builds(name, builtin);
  i = -1;
  while (++i < 9)
    {
      if (my_strcmp(name[i], argv[0]) == 0 && builtin[i] != NULL)
	{
	  builtin[i](argv, list_env);
	  return (1);
	}
    }
  return (list_env->valret);
}
