/*
** help_unsetenv.c for help unsetenv in /home/deneub_s/PSU_2015_42sh/new/src
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon May 30 08:57:24 2016 stanislas deneubourg
** Last update Mon May 30 08:59:23 2016 stanislas deneubourg
*/

#include        "42sh.h"

void		unsetenv_example()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|    | Example of 'unsetenv' use |    |\n");
  my_putstr("|    +---------------------------+    |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> unsetenv HOME   |\n");
  my_putstr("| Removes HOME variable...            |\n");
  my_putstr("|                                     |\n");
  credits();
}

void		help_unsetenv(char *str)
{
  my_putstr("\033[38;5;214mYou chose to be helped out with the builtin ");
  my_putstr(&str[2]);
  my_putstr("\n");
  my_putstr("+-------------------------------------+\n");
  my_putstr("|   | 101010sh's man to 'unsetenv' |  |\n");
  my_putstr("|   +------------------------------+  |\n");
  my_putstr("|                                     |\n");
  my_putstr("|      unsetenv is a builtin that     |\n");
  my_putstr("|      allows the user to remove      |\n");
  my_putstr("|       an environnment variable.     |\n");
  my_putstr("|                                     |\n");
  unsetenv_example();
}
