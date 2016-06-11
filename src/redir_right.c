/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Mon Jun  6 16:48:43 2016 loic lopez
*/

#include "42sh.h"

int		open_create(char *str, int i, int flags, int plus)
{
 int		fd;
 char		**wordtab;
 int		j;

 j = i + 1 + plus - 1;
 while (str[++j] != '\0')
   if (str[j] == '>')
     return (-2);
 if ((wordtab = create_tab_and_epur(&str[i + 1 + plus], ' ')) == NULL)
   {
     while (str[i + 1 + plus] == ' ')
       i++;
     if (str[i + 1 + plus] == 0)
       return (-3);
     return (-1);
   }
 fd = open(wordtab[0], flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
 free_tab(wordtab);
 clear_redir(str, i, '>');
 return (fd);
}

int		redir_right(char *str)
{
  int		i;

  i = 0;
  while (str != NULL && str[i] != '\0' && str[i] != '>')
    i++;
  if (str != NULL && i == 0)
    return (-6);
  else if (str[i] == '>' && str[i + 1] != '>')
    return (open_create(str, i, O_CREAT | O_TRUNC | O_RDWR, 0));
  else if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] != '>')
    return (open_create(str, i, O_CREAT | O_APPEND | O_RDWR, 1));
  return (0);
}

int		init_fd_right(int *fd,
			      char *str,
			      int *oldstdout)
{
  *fd = redir_right(str);
  if (*fd == -1)
    return (-1);
  if (*fd > 0)
    {
      *oldstdout = dup(1);
      dup2(*fd, 1);
    }
  else if (*fd < -1)
    {
      if (*fd == -2)
	my_perror("Ambiguous output redirect.\n");
      else if (*fd == -3)
	my_perror("Missing name for redirect.\n");
      else if (*fd == -6)
	my_perror("Invalid null command\n.");
      return (-1);
    }
  return (0);
}
