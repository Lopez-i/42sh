/*
** my_strncmp.c for my_strncmp.c in /home/lopez_i/rendu/Piscine_C_J06/ex_07
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Tue Oct  6 18:31:53 2015 loic lopez
** Last update Tue May 24 10:18:21 2016 Eric DESCHODT
*/

#include "lib.h"

int             my_strncmp(char *s1, char *s2, int n)
{
  int           i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != 0 && s2[i] != 0 && i < n - 1)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}
