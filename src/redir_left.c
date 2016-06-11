/*
** redir_left.c for redir_left.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon May 30 18:03:19 2016 Loic Lopez
** Last update Mon Jun  6 16:48:28 2016 loic lopez
*/

#include "42sh.h"

int		open_create_for_left(char *str, int i)
{
  int		fd;
  int		j;
  char          **wordtab;

  j = i;
  while (str[++j])
    if (str[j] == '<')
	{
	  my_perror("Ambiguous input redirect.\n");
	  return (-1);
	}
  if ((wordtab = create_tab_and_epur(&str[i + 1], ' ')) == NULL)
    {
      my_perror("Missing name for redirect.\n");
      return (-1);
    }
  if (wordtab[0] == NULL)
    return (-2);
  fd = open(wordtab[0], O_RDONLY);
  free_tab(wordtab);
  clear_redir(str, i, '<');
  return (fd);
}

int		redir_left(char *str)
{
  int           i;

  i = 0;
  while (str != NULL && str[i] != '\0' && str[i] != '<')
    i++;
  if (str != NULL && i == 0)
    {
      my_perror("Invalid null command.\n");
      return (-1);
    }
  if (str[i] == 0)
    return (-2);
  else if (str[i] == '<' && str[i + 1] != '<')
    return (open_create_for_left(str, i));
  else if (str[i] == '<' && str[i + 1] == '<')
    return (double_left(str, i));
  return (-2);
}

int		init_redirection_left(int *fd, char *str, int *oldstdin)
{
  *oldstdin = dup(0);
  if ((*fd = redir_left(str)) == -1)
    return (-1);
  if (*fd != -3 && *fd != -2 && *fd != -1)
    {
      if ((dup2(*fd, 0)) == -1)
	return (-1);
    }
  return (0);
}
