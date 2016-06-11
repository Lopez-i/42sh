/*
** simple_execution.c for simple_execution.c in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new/src
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Wed May 25 15:13:59 2016 Eric DESCHODT
** Last update Mon Jun  6 17:43:47 2016 Eric DESCHODT
*/

#include "42sh.h"

char		*strcat_cmd(char *cmd, char *str)
{
  char		*tmp;
  char		*tmp2;

  tmp = NULL;
  tmp = my_strcat(cmd, str);
  free(cmd);
  tmp2 = my_strdup(tmp);
  free(tmp);
  tmp = my_strcat(tmp2, " ");
  free(tmp2);
  return (tmp);
}

char		*new_glob(char *cmd, glob_t *globbuf)
{
 int		j;

 j = -1;
 while (globbuf->gl_pathv[++j] != NULL)
   {
     cmd = strcat_cmd(cmd, globbuf->gl_pathv[j]);
   }
 globfree(globbuf);
 return (cmd);
}

char		**glob_error(char **argv, glob_t *globbuf)
{
  globfree(globbuf);
  my_perror("Globbing error\n");
  return (argv);
}

char		**globbing(char **argv)
{
  glob_t        globbuf;
  int		i;
  char		*cmd;
  int		glob_ret;

  cmd = NULL;
  i = -1;
  while (argv != NULL && argv[++i] != NULL)
    {
      globbuf.gl_offs = 0;
      glob_ret = glob(argv[i], GLOB_DOOFFS, NULL, &globbuf);
      if (glob_ret != GLOB_NOMATCH)
	cmd = new_glob(cmd, &globbuf);
      else if (glob_ret == GLOB_NOSPACE || glob_ret == GLOB_ABORTED)
	return (glob_error(argv, &globbuf));
      else
	cmd = strcat_cmd(cmd, argv[i]);
      globfree(&globbuf);
    }
  free_tab(argv);
  argv = NULL;
  argv = create_tab_and_epur(cmd, ' ');
  free(cmd);
  return (argv);
}
