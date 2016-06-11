/*
** list.h for  in /home/descho_e/year_2015_2016/System_Unix/PSU_2015_minishell1
**
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
**
** Started on  Tue Jan  5 09:08:09 2016 Eric DESCHODT
** Last update Sun Jun  5 14:59:55 2016 Eric DESCHODT
*/

#ifndef			LIST_H_
# define		LIST_H_

#include		<stdbool.h>

typedef struct		s_list
{
  char			*str;
  char			tag;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_echo
{
  int			n;
  int			bslash;
}			t_echo;

typedef struct		s_sig_error
{
  int			status;
  char			*message;
}			t_sig_error;

extern t_sig_error	sig_error[11];

typedef struct		s_listdata
{
  struct s_listdata	*alias;
  struct s_listdata	*history;
  t_list		*list;
  t_list		*end;
  t_echo		echo_flag;
  char			*echo_cmd;
  char			**environ;
  int			size;
  int			valret;
  char			check_cmd;
  char			exit;
}			t_listdata;

void			init_listdata(t_listdata *);
void			my_show_list(t_list *);
void			my_put_in_list(t_listdata *, char *);
void			free_list(t_listdata *);

#endif			/* !LIST_H_ */
