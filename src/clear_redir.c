/*
** main.c for main.c in /home/lopez_i/traitements/PSU_2015_minishell1
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Mon Jan 18 09:58:01 2016 Loic Lopez
** Last update Mon May 30 17:13:39 2016 Loic Lopez
*/

#include "42sh.h"

char		*clear_redir(char *str, int i, char c)
{
  while (str[i] == c)
    str[i++] = ' ';
  while (str[i] == ' ')
    i++;
  while (str[i] != '\0' && str[i] != ' ')
    str[i++] = ' ';
  return (str);
}
