/*
**xmalloc.c for xmalloc in /home/lopez_i/traitements/PSU_2015_minishell2/src
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Apr  4 13:31:58 2016 Loic Lopez
** Last update Wed May  4 12:01:22 2016 Loic Lopez
*/

#include "lib.h"

void	*xmalloc(size_t	size)
{
  void	*ptr;

  if ((ptr = (void *)malloc(size)) == NULL)
    {
      my_perror("Malloc failed\n");
      return (0);
    }
  return (ptr);
}
