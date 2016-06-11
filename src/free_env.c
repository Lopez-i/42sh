/*
** free_env.c for free_env.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:27:44 2016 loic lopez
** Last update Sun Jun  5 18:27:52 2016 loic lopez
*/

#include "42sh.h"

void            free_environ(t_listdata *listenv)
{
  int           i;

  i = 0;
  while (listenv->environ[i] != NULL)
    free(listenv->environ[i++]);
  free(listenv->environ);
  listenv->environ = NULL;
}
