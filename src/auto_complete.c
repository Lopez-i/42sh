/*
** read_non_canon.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Sat Jun  4 21:29:00 2016 Eric DESCHODT
** Last update Mon Jun  6 19:00:11 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*show_possibility(t_listdata *possib, char *cmd, int *i)
{
  t_list	*tmp;
  int		j;

  j = 0;
  tmp = possib->list;
  while (tmp != NULL && j < 20)
    {
      write(0, "\n", 1);
      write(0, tmp->str, my_strlen(tmp->str));
      tmp = tmp->next;
      j++;
    }
  if (j == 20)
    write(0, "\n--- more ---\n", 14);
  write(0, "\n", 1);
  write(0, user, my_strlen(user));
  write(0, "> ", 2);
  write(0, cmd, my_strlen(cmd));
  (*i) = my_strlen(cmd);
  return (NULL);
}

char		*open_and_display(char *folder, char *word, char *cmd, int *i)
{
  t_listdata	possib;
  DIR		*dirp;
  struct dirent	*direntp;
  char		*new;

  new = NULL;
  init_listdata(&possib);
  dirp = opendir(folder != NULL ? folder : ".");
  if (dirp != NULL)
    {
      while ((direntp = readdir(dirp)) != NULL)
	{
	  if (word == NULL ||
	      my_strncmp(direntp->d_name, word, my_strlen(word)) == 0)
	    my_put_in_list(&possib, direntp->d_name);
	}
      closedir(dirp);
    }
  if (possib.size == 1)
    new = my_strdup(possib.list->str);
  else
    new = show_possibility(&possib, cmd, i);
  free_list(&possib);
  return (new);
}

char		*new_auto_cmd(char *tab[6], int *i, int fd)
{
  char		*cmd;
  char		*to_free;

  cmd = NULL;
  cmd = my_strdup(tab[0]);
  to_free = cmd;
  cmd = my_strcat(cmd, tab[3]);
  free(to_free);
  to_free = cmd;
  cmd = my_strcat(cmd, tab[4]);
  free(to_free);
  to_free = cmd;
  cmd = my_strcat(cmd, tab[1]);
  free(to_free);
  if (cmd == NULL)
    return (NULL);
  while (*i > 0)
    {
      write(0, "\b \b", 3);
      (*i)--;
    }
  write(fd, cmd, my_strlen(cmd));
  (*i) = my_strlen(cmd);
  return (cmd);
}

char		*auto_complete(int *i, int fd, char *cmd)
{
  char		*tab[6];

  tab[0] = NULL;
  tab[1] = NULL;
  tab[2] = NULL;
  tab[3] = NULL;
  if (cmd != NULL)
    {
      tab[0] = get_prev(cmd, i);
      tab[1] = my_strdup(&cmd[*i]);
      tab[2] = get_auto_word(i, cmd, &tab[3]);
    }
  tab[4] = open_and_display(tab[3], tab[2], cmd, i);
  if (tab[4] != NULL)
    {
      free(cmd);
      cmd = new_auto_cmd(tab, i, fd);
    }
  free(tab[0]);
  free(tab[1]);
  free(tab[2]);
  free(tab[3]);
  free(tab[4]);
  return (cmd);
}
