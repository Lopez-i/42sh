/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Sun Jun  5 17:51:10 2016 loic lopez
*/

#include "42sh.h"

int		main(int ac, char **av, char **env)
{
  t_listdata	list_env;
  int		fd;

  (void)ac;
  (void)av;
  signal(SIGINT, sigInt);
  init_listdata(&list_env);
  get_env(&list_env, env);
  if ((list_env.alias = malloc(sizeof(t_listdata))) == NULL)
    return (-1);
  if ((list_env.history = malloc(sizeof(t_listdata))) == NULL)
    return (-1);
  init_listdata(list_env.alias);
  init_listdata(list_env.history);
  list_env.echo_cmd = NULL;
  source(NULL, &list_env);
  if ((fd = open(".42sh_history", O_RDONLY)) != -1)
    get_history_from_file(fd, &list_env);
  return (sh(&list_env));
}
