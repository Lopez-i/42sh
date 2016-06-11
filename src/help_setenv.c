/*
** help_setenv.c for help setenv in /home/deneub_s/PSU_2015_42sh/new/src
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon May 30 08:21:49 2016 stanislas deneubourg
** Last update Mon May 30 08:32:09 2016 stanislas deneubourg
*/

#include        "42sh.h"

void		setenv_example()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|     | Example of 'setenv' use |     |\n");
  my_putstr("|     +-------------------------+     |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> setenv test un  |\n");
  my_putstr("| test=un                             |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> setenv test     |\n");
  my_putstr("| test=                               |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> setenv          |\n");
  my_putstr("| Shows the environnment...           |\n");
  my_putstr("|                                     |\n");
  credits();
}

void		help_setenv(char *str)
{
  my_putstr("\033[38;5;214mYou chose to be helped out with the builtin ");
  my_putstr(&str[2]);
  my_putstr("\n");
  my_putstr("+-------------------------------------+\n");
  my_putstr("|    | 101010sh's man to 'setenv' |   |\n");
  my_putstr("|    +----------------------------+   |\n");
  my_putstr("|                                     |\n");
  my_putstr("|       setenv is a builtin that      |\n");
  my_putstr("|  allows the user to create/modify   |\n");
  my_putstr("|       an environnment variable.     |\n");
  my_putstr("|    If a variable name with a value  |\n");
  my_putstr("| is passed as a parameter to setenv, |\n");
  my_putstr("| the variable with will initialized  |\n");
  my_putstr("|           at that value.            |\n");
  my_putstr("|   If a no value is precised for a   |\n");
  my_putstr("|    variable name, an empty value    |\n");
  my_putstr("|    will be assigned to that value.  |\n");
  my_putstr("|     If no parameters are entered,   |\n");
  my_putstr("|   it will show your environnment.   |\n");
  my_putstr("|                                     |\n");
  setenv_example();
}
