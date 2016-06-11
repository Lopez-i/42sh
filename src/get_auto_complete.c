/*
** read_non_canon.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Sat Jun  4 21:29:00 2016 Eric DESCHODT
** Last update Mon Jun  6 18:23:25 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*get_auto_folder(int i, char *cmd)
{
  char          *word;
  int           j;
  int		k;
  int		l;

  k = 0;
  j = i;
  word = NULL;
  while (j >= 0 && cmd[j] != ' ')
    {
      j--;
      k++;
    }
  j++;
  if (k > 0 && (word = malloc(sizeof(char) * k + 1)) == NULL)
    return (NULL);
  l = 0;
  while (l < k)
    word[l++] = cmd[j++];
  word[l] = '\0';
  return (word);
}

char		*get_auto_word(int *i, char *cmd, char **folder)
{
  char          *word;
  int           j;
  int		k;
  int		l;

  k = 0;
  j = *i;
  word = NULL;
  if (cmd[j] == ' ')
    j--;
  while (j >= 0 && cmd[j] != ' ' && cmd[j] != '/')
    {
      j--;
      k++;
    }
  if (j >= 0 && cmd[j] == '/')
    *folder = get_auto_folder(j, cmd);
  j++;
  if (k > 0 && (word = malloc(sizeof(char) * k + 1)) == NULL)
    return (NULL);
  l = 0;
  while (l < k)
    word[l++] = cmd[j++];
  word[l] = '\0';
  return (word);
}

char		*get_prev(char *cmd, int *i)
{
  int		j;
  char		*prev;

  if ((prev = my_strdup(cmd)) == NULL)
    return (NULL);
  j = *i;
  if (prev[j] == ' ')
    j--;
  while (j >= 0 && prev[j] != ' ')
    j--;
  j++;
  prev[j] = '\0';
  return (prev);
}
