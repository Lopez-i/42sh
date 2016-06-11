/*
** str_to_wordtab.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Wed Jan  6 14:38:40 2016 Eric DESCHODT
** Last update Tue May 24 10:42:47 2016 Eric DESCHODT
*/

#include "lib.h"

int		get_size_tab(char *str,
			     char sep)
{
  int		i;
  int		size;
  char		quote;

  size = 1;
  quote = 0;
  i = 0;
  while (str[i + 1] != '\0')
    {
      if (str[i] == '"')
	quote = (quote == 0) ? 1 : 0;
      if ((quote == 0) && (str[i] == sep  && str[i + 1] != sep))
	size++;
      i++;
    }
  if (str[i] == '"')
    quote = (quote == 0) ? 1 : 0;
  if (quote == 1)
    {
      my_putstr("Unmatched \".\n");
      return (-2);
    }
  return (size);
}

char		*get_word(int i,
			  char *str,
			  char **tab,
			  char sep)
{
  int		j;
  char		quote;

  quote = 0;
  j = 0;
  while (*str == sep)
    str++;
  if (*str == '"')
    {
      quote = 1;
      str++;
    }
    while (((quote == 0 && *str != sep)
	    || (quote == 1 && *str != '"'))  && (*str != 0))
      {
	tab[i][j] = str[0];
	j++;
	str++;
      }
  if (quote == 1)
    str++;
  tab[i][j] = '\0';
  return (str);
}

int		init_word(int i,
			  char *str,
			  char **tab,
			  char sep)
{
  int           j;
  char		quote;

  quote = 0;
  j = 0;
  while (*str == sep)
    str++;
  if (*str == '"')
    {
      quote = 1;
      str++;
    }
  while (((quote == 0 && *str != sep)
	  || (quote == 1 && *str != '"'))  && (*str != 0))
      {
	str++;
	j++;
      }
  if (quote == 1)
    str++;
  tab[i] = malloc(sizeof(char) * (j + 1));
  if (tab[i] == NULL)
    return (-1);
  else
    return (0);
}

char		**str_to_wordtab(char *str, char sep)
{
  int		i;
  int		size;
  char		**tab;

  if (str != NULL)
    {
      while ((*str == sep) && (*str != 0))
	str++;
      if (*str == 0)
	return (NULL);
      i = -1;
      if ((size = get_size_tab(str, sep)) == -2)
	  return (NULL);
      if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
	return (NULL);
      while (++i < size)
	{
	  if (init_word(i, str, tab, sep) == -1)
	    return (NULL);
	  str = get_word(i, str, tab, sep);
	}
      tab[i] = NULL;
      return (tab);
    }
  return (NULL);
}
