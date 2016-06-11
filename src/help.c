/*
** help.c for help in /home/deneub_s/PSU_2015_42sh/src/buildins
**
** Made by stanislas deneubourg
** Login   <deneub_s@epitech.net>
**
** Started on  Tue May 24 11:01:55 2016 stanislas deneubourg
** Last update Mon May 30 09:14:32 2016 stanislas deneubourg
*/

#include	"42sh.h"

void		credits()
{
  my_putstr("+-------------------------------------+\n");
  my_putstr("|        | 101010sh, made by: |       |\n");
  my_putstr("|        +--------------------+       |\n");
  my_putstr("|                                     |\n");
  my_putstr("|    descho_e, lopez_i, deneub_s,     |\n");
  my_putstr("|          piazza_p, dupil_l.         |\n");
  my_putstr("+-------------------------------------+\n\033[00m");
}

void            init_help_possibilities(char *func_help[7],
                            void (*parsing[7])(char *str))
{
  func_help[0] = "--exit";
  func_help[1] = "--cd";
  func_help[2] = "--env";
  func_help[3] = "--unsetenv";
  func_help[4] = "--setenv";
  func_help[5] = "--echo";
  func_help[6] = NULL;
  parsing[0] = &help_exit;
  parsing[1] = &help_cd;
  parsing[2] = &help_env;
  parsing[3] = &help_unsetenv;
  parsing[4] = &help_setenv;
  parsing[5] = &help_echo;
  parsing[6] = NULL;
}

void		my_help(char **argv, t_listdata *list_env)
{
  char          *func_help[7];
  void          (*parsing[7])(char *);
  int           i;

  (void)list_env;
  init_help_possibilities(func_help, parsing);
  i = -1;
  if (argv[1] == NULL)
    {
      launch_vanilla_help();
      return ;
    }
  while (++i < 7)
    {
      if (my_strcmp(func_help[i], argv[1]) == 0 && parsing[i] != NULL)
        {
          parsing[i](argv[1]);
          return ;
        }
    }
}
