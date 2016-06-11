/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Tue May 24 13:06:50 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*get_prompt(t_listdata *list_env)
{
  t_list	*tmp;

  tmp = list_env->list;
  while (tmp != NULL)
    {
      if (my_strncmp("USER=", tmp->str, 5) == 0)
      	return (&tmp->str[5]);
      tmp = tmp->next;
    }
  return ("$");
}
