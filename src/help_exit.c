/*
** help_exit.c for help exit in /home/deneub_s/PSU_2015_42sh/new
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Thu May 26 15:14:47 2016 stanislas deneubourg
** Last update Thu May 26 16:53:03 2016 stanislas deneubourg
*/

#include        "42sh.h"

void		exit_example()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|      | Example of 'exit' use |      |\n");
  my_putstr("|      +-----------------------+      |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> exit 42         |\n");
  my_putstr("| <Your Prompt> echo $?               |\n");
  my_putstr("| 42                                  |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> exit            |\n");
  my_putstr("| <Your Prompt> echo $?               |\n");
  my_putstr("| 0                                   |\n");
  my_putstr("|                                     |\n");
  credits();
}

void		help_exit(char *str)
{
  my_putstr("\033[38;5;214mYou chose to be helped out with the builtin ");
  my_putstr(&str[2]);
  my_putstr("\n");
  my_putstr("+-------------------------------------+\n");
  my_putstr("|     | 101010sh's man to 'exit' |    |\n");
  my_putstr("|     +--------------------------+    |\n");
  my_putstr("|                                     |\n");
  my_putstr("|        exit is a builtin that       |\n");
  my_putstr("|       allows the user to quit       |\n");
  my_putstr("|      the 101010sh at any moment     |\n");
  my_putstr("|  to get back on his default shell.  |\n");
  my_putstr("|       If a number is passed as      |\n");
  my_putstr("|         a parameter to exit,        |\n");
  my_putstr("|      the 101010sh will exit with    |\n");
  my_putstr("|              that value.            |\n");
  my_putstr("|        Otherwise the 101010sh       |\n");
  my_putstr("|      will exit with the value 0.    |\n");
  my_putstr("|                                     |\n");
  exit_example();
}
