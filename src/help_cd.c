/*
** help_exit.c for help exit in /home/deneub_s/PSU_2015_42sh/new
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Thu May 26 15:14:47 2016 stanislas deneubourg
** Last update Thu May 26 16:52:50 2016 stanislas deneubourg
*/

#include        "42sh.h"

void		cd_example()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|       | Example of 'cd' use |       |\n");
  my_putstr("|       +---------------------+       |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> cd hello_world  |\n");
  my_putstr("| <101010sh's Prompt> pwd             |\n");
  my_putstr("| ~/home/user_x/hello_world           |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> cd              |\n");
  my_putstr("| <101010sh's Prompt> pwd             |\n");
  my_putstr("| ~/home/user_x                       |\n");
  my_putstr("|                                     |\n");
  my_putstr("|                                     |\n");
  my_putstr("| <101010sh's Prompt> cd ../salt      |\n");
  my_putstr("| ../salt : No such file or directory.|\n");
  my_putstr("|                                     |\n");
  credits();
}

void		help_cd(char *str)
{
  my_putstr("\033[38;5;214mYou chose to be helped out with the builtin ");
  my_putstr(&str[2]);
  my_putstr("\n");
  my_putstr("+-------------------------------------+\n");
  my_putstr("|      | 101010sh's man to 'cd' |     |\n");
  my_putstr("|      +------------------------+     |\n");
  my_putstr("|                                     |\n");
  my_putstr("|          cd is a builtin that       |\n");
  my_putstr("|      allows the user to navigate    |\n");
  my_putstr("|     into the computer's folders.    |\n");
  my_putstr("|  If a valid directory is passed as  |\n");
  my_putstr("|           a parameter to cd,        |\n");
  my_putstr("|         you will go into the        |\n");
  my_putstr("|            desired folder.          |\n");
  my_putstr("|       Otherwise cd will return      |\n");
  my_putstr("|           an error message.         |\n");
  my_putstr("|    If no parameter is passed or     |\n");
  my_putstr("|    if ""~"" is passed as parameter  |\n");
  my_putstr("|   will go into your ~/home/user_x   |\n");
  my_putstr("| directory, or any directory defined |\n");
  my_putstr("|         as the variable HOME        |\n");
  my_putstr("|         in your environnment.       |\n");
  my_putstr("|                                     |\n");
  cd_example();
}
