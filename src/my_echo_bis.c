/*
** my_echo_bis.c for echo bis in /home/piazza_p/rendu/PSU/PSU_2015_42sh/new
**
** Made by pierre piazza
** Login   <piazza_p@epitech.net>
**
** Started on  Wed May 25 18:16:06 2016 pierre piazza
** Last update Fri Jun  3 15:40:16 2016 pierre piazza
*/

#include "42sh.h"

void	init_flags(char *flags[8], char *flags_ret[8])
{
  flags[0] = "\\a";
  flags[1] = "\\b";
  flags[2] = "\\t";
  flags[3] = "\\n";
  flags[4] = "\\v";
  flags[5] = "\\f";
  flags[6] = "\\r";
  flags[7] = NULL;
  flags_ret[0] = "\a";
  flags_ret[1] = "\b";
  flags_ret[2] = "\t";
  flags_ret[3] = "\n";
  flags_ret[4] = "\v";
  flags_ret[5] = "\f";
  flags_ret[6] = "\r";
  flags_ret[7] = NULL;
}

void	print_echo_version(void)
{
  my_putstr("My echo \033[1;36;5;31mv2.0\033[00m\n");
}

void	print_echo_help(void)
{
  my_putstr("\033[38;5;214m+------My Echo Help------+\n");
  my_putstr("|                        |\n");
  my_putstr("|  -n  -> Disable '\\n'   |\n");
  my_putstr("|                        |\n");
  my_putstr("|  --version -> print    |\n");
  my_putstr("|                version |\n");
  my_putstr("|  --help    -> print    |\n");
  my_putstr("|                help    |\n");
  my_putstr("|                        |\n");
  my_putstr("+------------------------+\n\033[00m");
}

int	check_status(int status, char c)
{
  if (status == 0 && c == '\"')
    status += 1;
  else if (status == 1 && c == '\"')
    status -= 1;
  return (status);
}

int	parse_quotes(char *str)
{
  int	i;
  int	c;

  i = -1;
  c = 0;
  while (str[++i] != 0)
    {
      if (str[i] == '"')
	c++;
    }
  if (c % 2 != 0)
    {
      my_perror("Unmatched \".\n");
      return (1);
    }
  return (0);
}
