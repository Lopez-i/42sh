/*
** alias.c for alias in /home/dupil_l/Semestre2/Systeme_unix/PSU_2015_42sh/src/buildins
** 
** Made by loic dupil
** Login   <dupil_l@epitech.net>
** 
** Started on  Tue May 24 15:53:56 2016 loic dupil
** Last update Sat Jun  4 17:51:31 2016 Eric DESCHODT
*/

#include "42sh.h"

void		export(char *str, t_listdata *list_env)
{
  char		**wordtab;
  char		*argv[4];

  if ((wordtab = (str_to_wordtab(str, '='))) == NULL)
    return ;
  if (wordtab[1] != NULL)
    {
      argv[0] = "setenv";
      argv[1] = wordtab[0];
      argv[2] = wordtab[1];
      argv[3] = NULL;
      setenvsh(argv, list_env);
      free_tab(wordtab);
    }
}

int		check_fd(char **argv)
{
  int		fd;

  if (argv != NULL && argv[1] == NULL)
    {
      my_perror("file needed to be sourced\n");
      return (-1);
    }
  if (argv == NULL)
    {
      if ((fd = open(".42shrc", O_RDONLY)) == -1)
	{
	  my_perror(strerror(errno));
	  return (-1);
	}
    }
  else if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
      my_perror(strerror(errno));
      my_perror("\n");
      return (-1);
    }
  return (fd);
}

void		source(char **argv, t_listdata *list_env)
{
  char		*s;
  int		fd;

  if ((fd = check_fd(argv)) == -1)
    return ;
  free_list(list_env->alias);
  init_listdata(list_env->alias);
  while ((s = get_next_line(fd)) != NULL)
    {
      if (my_strncmp(s, "export ", 7) == 0)
	export(&s[7], list_env);
      if ((my_strncmp(s, "alias ", 6)) == 0)
	my_put_in_list(list_env->alias, (&s[6]));
      free(s);
    }
  stockenv(list_env);
  close(fd);
}
