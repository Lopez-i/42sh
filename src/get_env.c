/*
** get_env.c for get_env.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:26:18 2016 loic lopez
** Last update Sun Jun  5 18:26:41 2016 loic lopez
*/

#include "42sh.h"

void		get_env(t_listdata *list_env, char **env)
{
  int		i;

  i = 0;
  list_env->environ = NULL;
  while (env[i] != NULL)
    {
      my_put_in_list(list_env, env[i]);
      i++;
    }
  stockenv(list_env);
}
