/*
** init_sig_error.c for init_sig_error.c in /home/lopez_i/traitements/PSU_2015_42sh
**
** Made by loic lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Fri Jun  3 17:03:45 2016 loic lopez
** Last update Fri Jun  3 17:08:25 2016 loic lopez
*/

#include "42sh.h"

t_sig_error	sig_error[11] =
  {
    {SIGHUP, "Hangup\n"},
    {SIGQUIT, "Quit (core dumped)\n"},
    {SIGABRT, "Abort (core dumped)\n"},
    {SIGBUS, "Bus error (core dumped)\n"},
    {SIGFPE, "Floating exception\n"},
    {SIGKILL, "Killed\n"},
    {SIGUSR1, "User signal 1\n"},
    {SIGSEGV, "Segmentation fault.\n"},
    {SIGUSR2, "User signal 2\n"},
    {SIGPIPE, "Broken pipe\n"},
    {SIGTERM, "Terminated\n"},
  };
