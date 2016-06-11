/*
** help_echo.c for help echo in /home/deneub_s/PSU_2015_42sh/new/src
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon May 30 08:37:42 2016 stanislas deneubourg
** Last update Mon May 30 08:56:41 2016 stanislas deneubourg
*/

#include        "42sh.h"

void		echo_example()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|      | Example of 'echo' use |      |\n");
  my_putstr("|      +-----------------------+      |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> echo 'test123'  |\n");
  my_putstr("| test123                             |\n");
  my_putstr("|                                     |\n");
  credits();
}

void		help_echo(char *str)
{
  my_putstr("\033[38;5;214mYou chose to be helped out with the builtin ");
  my_putstr(&str[2]);
  my_putstr("\n");
  my_putstr("+-------------------------------------+\n");
  my_putstr("|     | 101010sh's man to 'echo' |    |\n");
  my_putstr("|     +--------------------------+    |\n");
  my_putstr("|                                     |\n");
  my_putstr("|        echo is a builtin that       |\n");
  my_putstr("|  allows the user to print on the    |\n");
  my_putstr("|screen the character string he wants.|\n");

  my_putstr("|                                     |\n");
  echo_example();
}
