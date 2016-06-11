/*
** 42sh.h for 42sh.h in /home/lopez_i/traitements/PSU_2015_42sh/new
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed May 25 22:06:14 2016 Loic Lopez
** Last update Mon Jun  6 17:44:27 2016 Eric DESCHODT
*/

#ifndef		SH_H_
# define	SH_H_

# include	<glob.h>
# include	<curses.h>
# include	<sys/ioctl.h>
# include	<termios.h>
# include	<errno.h>
# include	<dirent.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<stdbool.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<string.h>
# include	"get_next_line.h"
# include	"lib.h"
# include	"list.h"

char		*user;

void            free_tab(char **argv);
void            stockenv(t_listdata *listdata);
void            get_env(t_listdata *list_env, char **env);
char            *get_prompt(t_listdata *list_env);
int             buildin(char **argv, t_listdata *list_env);
void            create_multi(t_listdata *all_cmd, char *cmd, char sep);
void            show_tab(char **tab);
int             modifyargv(char **argv, t_listdata *list_env);
int		check_cd_minus(t_listdata *list_env, char **argv);
int             check_cd(t_listdata *list_env, char **argv);
int		my_cd(const char *path, t_listdata *list_env);
void            unsetenvsh(char **argv, t_listdata *listenv);
void            unsetall(t_listdata *listenv);
void            setenvsh(char **argv, t_listdata *listenv);
void            unsetenvsh_append(char *variable, t_listdata *listenv);
void            env(char **argv, t_listdata *listenvorigin);
void		cd_parsing(char **argv, t_listdata *list_env);
void            my_exit(char **argv, t_listdata *list_env);
void		my_help(char **argv, t_listdata *list_env);
int		simple_execution(char **argv, t_listdata *listenv);
void		my_echo(char **argv, t_listdata *listenv);
void		print_echo_help(void);
void		print_echo_version(void);
void		init_flags(char *flags[8], char *flags_ret[8]);
int		parse_quotes(char *str);
int		check_status(int status, char c);
int		aff_non_printable(char *str, int j, char *flags[8], char *flags_ret[8]);
char		**ls_colors(char **argv);
void            credits();
void            init_help();
void            init_help_possibilities(char *func_help[7],
					void (*parsing[7])(char *str));
void            help_cd(char *str);
void            help_echo(char *str);
void            help_env(char *str);
void            help_exit(char *str);
void            help_setenv(char *str);
void            help_unsetenv(char *str);
void            cd_example();
void            echo_example();
void            env_example();
void            exit_example();
void            setenv_example();
void            unsetenv_example();
void            launch_vanilla_help();
int		execute_one(char **argv, t_listdata *list_env);
int             error_msg(char *name, char *str);
t_list          *find_pathern(t_listdata *list_env);
void            exec_with_env(char **argv,
                              t_listdata *list_env,
                              int space);
int             all_execute(t_listdata *list_env,
                            t_listdata *all_cmd);
int             execute_without_fork(t_listdata *list_env,
                             char *cmd);
int		execute_one_without_fork(char **argv, t_listdata *list_env);
int             simple_execution_without_fork(char **argv,
					      t_listdata *list_env);
void            set_default_env(char ***path,
                                t_listdata *list_env);
int		path_test(char **path,
			  char **argv,
			  t_listdata *list_env);
void		create_new_path(char **path,
				int i,
				char **argv);
int             piping(t_listdata *list_env,
                       t_list *tmp);
char		**check(char **argv, t_listdata *list_env);
int             execute(t_listdata *list_env, char *cmd);
char            *clear_redir(char *str, int i, char c);
int             init_redirection_left(int *, char *, int *);
int             init_fd_right(int *fd, char *str, int *oldstdout);
int             res_dup(int *oldstdout,int *fd, int channel);
int             res_dup_ret(int fd[2][2], int value);
int             double_left(char *str, int i);
void            source(char **argv, t_listdata *list_env);
void            export(char *str, t_listdata *list_env);
int             open_create(char *str, int i, int flags, int plus);
int             redir_right(char *str);
int             init_fd_right(int *fd, char *str, int *oldstdout);
void            create_prio(t_listdata *all_prio, char *cmd);
void		wait_and_print_status(pid_t pid);
void		print_status(int status);
char            *strcat_cmd(char *cmd, char *str);
char            **globbing(char **argv);
void		setenv_path_cmd(char *path_cmd, t_listdata *list_env);
char            *strcat_cmd(char *cmd, char *str);
char            *find_alias(char *argv,
                            char *new_argv,
                            t_list *tmp);
char            *read_non_canon(int fd, t_listdata *list_env);
char            *erasing(char *cmd, int *i, char flag);
char            *appending(char *cmd, int i, char *new);
void		remove_first_elem(t_listdata *list_env);
void		add_to_history(char *str, t_listdata *list_env);
char            *arrowsing(int *i, int fd, char *cmd, t_list **history);
char            *history_tty(char *cmd, t_list **history);
void		overwrite_just_do_it(int fd, t_listdata *list_env);
void		overwrite_42shhistory(t_listdata *list_env);
void		get_history_from_file(int fd, t_listdata *list_env);
int		check_empty_str(char *str);
void		sigInt(int sig);
void		free_sh(t_listdata *list_env);
void		print_prompt(t_listdata *list_env);
int		sh(t_listdata *list_env);
char		*find_alias(char *argv, char *new_argv, t_list *tmp);
char		*get_command(char *str, t_list *tmp);
char		*recurs_alias(char *save, t_list *tmp);
char		*copy_arg(char *tmp, int i, char *cmd);
void		copy_env(t_listdata *new, t_listdata *origin);
int             check_unset(char **argv, int *i, t_listdata *listenv);
int             modifyenv(char *var, t_listdata *listenv);
int		init_termios(struct termios *newtio,
			     struct termios *oldtio,
			     char **cmd,
			     int *i);
char		*close_termios(char *cmd,
			       char str_to_cat[2],
			       struct termios *oldtio);
void            interpret_cmd(char *cmd,
                              t_listdata *list_env);
int             history_point(char **argv, t_listdata *list_env);
char            *auto_complete(int *i, int fd, char *cmd);
char            *get_auto_folder(int i, char *cmd);
char            *get_auto_word(int *i, char *cmd, char **folder);
char            *get_prev(char *cmd, int *i);
void            exec_found_cmd_from_history(char **argv, t_list *tmp2,
                                            t_listdata *list_env);
void            find_cmd_with_nbr(char **argv, char *tmp,
                                  t_listdata *list_env);
void            find_cmd_with_command(char **argv, char *tmp,
				      t_listdata *list_env);

#endif /* !SH_H_ */
