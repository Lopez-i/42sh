/*
** my_strcmp.c for my_strcmp in /home/lopez_i/rendu/Piscine_C_J06/ex_06
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Tue Oct  6 18:05:54 2015 loic lopez
** Last update Wed May  4 12:25:33 2016 Loic Lopez
*/

#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}
