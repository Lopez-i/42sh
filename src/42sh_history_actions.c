/*
** 42sh_history_actions.c for 42sh hist actions in /home/deneub_s/PSU_2015_42sh
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Sun Jun  5 16:48:09 2016 stanislas deneubourg
** Last update Sun Jun  5 17:28:31 2016 Eric DESCHODT
*/

#include "42sh.h"

void    overwrite_just_do_it(int fd, t_listdata *list_env)
{
  t_list	*tmp;

  tmp = list_env->list;
  while (tmp != NULL)
    {
      write(fd, tmp->str, my_strlen(tmp->str));
      write(fd, "\n", 1);
      tmp = tmp->next;
    }
}

void    overwrite_42shhistory(t_listdata *list_env)
{
  int   fd;

  if ((fd = open(".42sh_history", O_WRONLY | O_TRUNC | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    write(2, "Failed to create .42sh_history.\n", 32);
  if (fd != -1)
    overwrite_just_do_it(fd, list_env);
  close(fd);
}

void	get_history_from_file(int fd, t_listdata *list_env)
{
  char	*s;

  while ((s = get_next_line(fd)))
    {
      add_to_history(s, list_env);
      free(s);
    }
  close(fd);
}
