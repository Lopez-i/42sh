/*
** redir_left.c for redir_left.c in /home/lopez_i/traitements/PSU_2015_42sh/src
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon May 30 18:03:19 2016 Loic Lopez
** Last update Wed Jun  1 17:43:07 2016 Eric DESCHODT
*/

#include "42sh.h"

t_list		*write_and_pipe(t_list *tmp,
				int pipefd[2])
{
  write(pipefd[1], tmp->str, my_strlen(tmp->str));
  write(pipefd[1], "\n", 1);
  tmp = tmp->next;
  return (tmp);
}

int		read_and_pipe(char **wordtab, char *str, int i)
{
  int		pipefd[2];
  t_listdata	buffer;
  char		*line;
  t_list	*tmp;

  init_listdata(&buffer);
  my_putstr("> ");
  while ((line = get_next_line(0)) != NULL
	 && my_strcmp(line, wordtab[0]) != 0)
    {
      my_putstr("> ");
      my_put_in_list(&buffer, line);
      free(line);
    }
  free_tab(wordtab);
  clear_redir(str, i, '<');
  if ((pipe(pipefd)) == -1)
    return (-1);
  tmp = buffer.list;
  while (tmp != NULL)
    tmp = write_and_pipe(tmp, pipefd);
  if (close(pipefd[1]) == -1
      || dup2(pipefd[0], 0) == -1)
    return (-1);
  return (0);
}

int		double_left(char *str, int i)
{
  int           j;
  char           **wordtab;

  j = i + 1;
  while (str[++j])
    if (str[j] == '<')
      {
	my_perror("Ambiguous input redirect.\n");
	return (-1);
      }
  if ((wordtab = create_tab_and_epur(&str[i + 2], ' ')) == NULL)
    {
      my_perror("Missing name for redirect.\n");
      return (-1);
    }
  if (wordtab[0] == NULL)
    return (-2);
  if (read_and_pipe(wordtab, str, i) == -1)
    return (-1);
  return (-3);
}
