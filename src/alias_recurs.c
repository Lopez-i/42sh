/*
** alias_recurs.c for alias_recurs in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Jun  5 18:10:06 2016 loic lopez
** Last update Sun Jun  5 18:10:50 2016 loic lopez
*/

#include "42sh.h"

char		*recurs_alias(char *save, t_list *tmp)
{
  char		**argv;
  int		i;

  argv = create_tab_and_epur(save, ' ');
  free(save);
  save = NULL;
  i = -1;
  while (argv[++i] != NULL)
    save = find_alias(argv[i], save, tmp->prev);
  free_tab(argv);
  return (save);
}
