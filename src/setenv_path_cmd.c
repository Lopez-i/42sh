/*
** setenv_path_cmd.c for setenv_path_cmd.c in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Sat Jun  4 13:41:32 2016 loic lopez
** Last update Sat Jun  4 13:53:27 2016 loic lopez
*/

#include "42sh.h"

void	setenv_path_cmd(char *path_cmd, t_listdata *list_env)
{
  char	*argv[4];

  argv[0] = "setenv";
  argv[1] = "PWDCMD";
  argv[2] = path_cmd;
  argv[3] = NULL;
  setenvsh(argv, list_env);
}
