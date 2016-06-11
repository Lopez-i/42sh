/*
** help_env.c for help env in /home/deneub_s/PSU_2015_42sh/new/src
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon May 30 08:32:59 2016 stanislas deneubourg
** Last update Mon May 30 08:36:53 2016 stanislas deneubourg
*/

#include        "42sh.h"

void		env_example()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|       | Example of 'env' use |      |\n");
  my_putstr("|       +----------------------+      |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> env             |\n");
  my_putstr("|  XDG_VTNR=7                         |\n");
  my_putstr("|  LESSKEY=/etc/lesskey.bin           |\n");
  my_putstr("|  ...                                |\n");
  my_putstr("|                                     |\n");
  credits();
}

void		help_env(char *str)
{
  my_putstr("\033[38;5;214mYou chose to be helped out with the builtin ");
  my_putstr(&str[2]);
  my_putstr("\n");
  my_putstr("+-------------------------------------+\n");
  my_putstr("|     | 101010sh's man to 'env' |     |\n");
  my_putstr("|     +-------------------------+     |\n");
  my_putstr("|                                     |\n");
  my_putstr("|        env is a builtin that        |\n");
  my_putstr("|      allows the user to see his     |\n");
  my_putstr("|        environnment's content.      |\n");
  my_putstr("|                                     |\n");
  env_example();
}
