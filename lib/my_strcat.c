/*
** complete_str.c for complete_str.c in /home/lopez_i/traitements/PSU_2015_42sh/lib
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Thu May 19 15:02:44 2016 Loic Lopez
** Last update Sat Jun  4 23:07:20 2016 Eric DESCHODT
*/

#include "lib.h"

char    *my_strcat(char *src, char *src2)
{
  char  *str;
  int   i;
  int   n;

  i = -1;
  if ((str = malloc(sizeof(char) * my_strlen(src)
                    + my_strlen(src2) + 1)) == NULL)
    return (NULL);
  if (src != NULL)
    {
      while (src[++i] != 0)
	str[i] = src[i];
    }
  else
    i = 0;
  n = -1;
  if (src2 != NULL)
    {
      while (src2[++n] != 0)
	str[i++] = src2[n];
    }
  str[i] = '\0';
  return (str);
}
