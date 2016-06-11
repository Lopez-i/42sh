/*
** help_vanilla.c for help vanilla in /home/deneub_s/PSU_2015_42sh/new/src
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Mon May 30 09:02:30 2016 stanislas deneubourg
** Last update Mon Jun  6 13:27:43 2016 stanislas deneubourg
*/

#include "42sh.h"

void	launch_vanilla_help()
{
  my_putstr("\033[38;5;214m+-------------------------------------+\n");
  my_putstr("|          | 101010sh's man |         |\n");
  my_putstr("|          +----------------+         |\n");
  my_putstr("|                                     |\n");
  my_putstr("| Here is a list of the our avalaible |\n");
  my_putstr("|         mans ! Try it out !         |\n");
  my_putstr("|                                     |\n");
  my_putstr("|              help --cd              |\n");
  my_putstr("|              help --echo            |\n");
  my_putstr("|              help --env             |\n");
  my_putstr("|              help --exit            |\n");
  my_putstr("|              help --setenv          |\n");
  my_putstr("|              help --unsetenv        |\n");
  my_putstr("|                                     |\n");
  credits();
}
