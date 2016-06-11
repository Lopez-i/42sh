/*
** my_printf.h for my_printf.h in /home/lopez_i/.lib/lib
**
** Made by Loic Lopez
** Login   <lopez_i@epitech.net>
**
** Started on  Wed May  4 12:13:22 2016 Loic Lopez
** Last update Wed May  4 12:14:11 2016 Loic Lopez
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdlib.h>
# include <stdarg.h>

int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_put_nbr_unsigned(unsigned int nb);
int	my_putstr_noprintable(char *str);
int	my_putnbr_base_size(size_t nbr, char *base);
int	my_printf(const char *format, ...);
int	my_printf_p(size_t pointeur);
int	my_putnbr_base(int nbr, char *base);
char	*my_strcpy(char *dest, char *src);
int	call_number(va_list list);
int	call_base_octal(va_list list);
int	call_base_x(va_list list);
int	call_base_X(va_list list);
int	call_unsigned(va_list list);
int	call_char(va_list list);
int	call_string(va_list list);
int	call_adress(va_list list);
int	call_binary(va_list list);
int	call_noprintable(va_list list);

#endif /* !MY_PRINTF_H_ */
