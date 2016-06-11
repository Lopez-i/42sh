/*
** my_str_to_word_tab.c for my_str_to_word_tab.c in /home/lopez_i/test
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Tue Oct 27 23:46:22 2015 loic lopez
** Last update Mon Jun  6 19:17:23 2016 Eric DESCHODT
*/

#include <unistd.h>
#include <stdlib.h>

int	countword(char *str, char c)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      while (str[i] == c)
	i++;
      if (str[i])
	n++;
      while (str[i] != c && str[i] != 0)
	i++;
    }
  return (n);
}

int	current(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != c && str[i] != '\0')
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	l;
  int	t;
  char	**tab;

  i = 0;
  l = 0;
  if (str == NULL)
    return (NULL);
  if ((tab = malloc((countword(str, c) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      if ((tab[l] = malloc((current(&str[i], c) + 1) * sizeof(char))) == NULL)
	return (NULL);
      t = 0;
      while (str[i] != c && str[i] != '\0')
	tab[l][t++] = str[i++];
      tab[l++][t] = '\0';
      while (str[i] == c)
	i++;
    }
  tab[l] = NULL;
  return (tab);
}
