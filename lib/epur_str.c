/*
** epur_str.c for epur_str.c in /home/lopez_i/traitements/PSU_2015_minishell2
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sun Apr 10 13:32:45 2016 Loic Lopez
** Last update Mon Jun  6 17:36:27 2016 pierre piazza
*/

#include "lib.h"

char	*delete_specific_char(char *str, char c)
{
  char	*ret;
  int	i;
  int	n;

  i = 0;
  n = 0;
  if (str == NULL)
    return (NULL);
  ret = xmalloc(sizeof(char) * my_strlen(str) + 1);
  while (str[i])
    {
      if (str[i] == c)
	i++;
      else
	ret[n++] = str[i++];
    }
  ret[n] = '\0';
  free(str);
  return (ret);
}

char	*epur_str(char *line)
{
  char	*str;
  char	*str2;
  int	i;
  int	j;

  str = line;
  while (*str == ' ' && *str != 0)
    str++;
  if (*str == '\0')
    return (NULL);
  str2 = xmalloc(sizeof(char) * my_strlen(str) + 1);
  i = 0;
  j = 0;
  while (str[i + 1] != '\0')
    {
      if (str[i] != ' ')
	  str2[j++] = str[i];
      else if (str[i] == ' ' && str[i + 1] != ' ')
	str2[j++] = str[i];
      i++;
    }
  if (str[i] != ' ')
    str2[j++] = str[i];
  str2[j] = 0;
  return (str2);
}

char	**create_tab_and_epur(char *line, char c)
{
  char	**tab;
  char	*str;

  if (line == NULL)
    return (NULL);
  if ((str = epur_str(line)) == NULL)
    return (NULL);
  if ((tab = str_to_wordtab(str, c)) == NULL)
    return (NULL);
  free(str);
  return (tab);
}
