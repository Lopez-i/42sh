/*
** env.c for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_42sh/new
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Tue May 24 09:47:48 2016 Eric DESCHODT
** Last update Sun Jun  5 18:27:57 2016 loic lopez
*/

#include "42sh.h"

void            stockenv(t_listdata *listdata)
{
  t_list        *tmp;
  int           i;

  i = 0;
  if (listdata->list != NULL && listdata->environ != NULL)
    free_tab(listdata->environ);
  tmp = listdata->list;
  if ((listdata->environ
       = malloc(sizeof(char *) * (listdata->size + 1))) != NULL)
    {
      while (tmp != NULL)
        {
          listdata->environ[i]
            = malloc(sizeof(char) * (my_strlen(tmp->str) + 1));
          if (listdata->environ[i] != NULL)
            {
              my_strcpy(listdata->environ[i], tmp->str);
              i++;
            }
          tmp = tmp->next;
        }
      listdata->environ[i] = NULL;
    }
}
