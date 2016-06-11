/*
** my_strdup.c for my_strdup in /home/lopez_i/rendu/Piscine_C_J08/ex_01
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Thu Oct  8 09:43:49 2015 loic lopez
** Last update Sat Jun  4 23:22:27 2016 Eric DESCHODT
*/

#include "lib.h"

char	*my_strdup(char *src)
{
  char	*dest;

  if (src == NULL)
    return (NULL);
  if ((dest = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  return (my_strcpy(dest, src));
}
