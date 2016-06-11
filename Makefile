##
## Makefile for Makefile in /home/lopez_i/traitements/PSU_2015_42sh
##
## Made by Loic Lopez
## Login   <lopez_i@epitech.net>
##
## Started on  Thu May 19 12:35:25 2016 Loic Lopez
## Last update Thu May 19 13:26:09 2016 Loic Lopez
##

all:
	@make --no-print-directory -C lib
	@make --no-print-directory -C src

clean:
	@make clean --no-print-directory  -C lib
	@make clean --no-print-directory  -C src

fclean:
	@make fclean  --no-print-directory -C lib
	@make fclean  --no-print-directory -C src

re:
	@make re  --no-print-directory -C lib
	@make re  --no-print-directory -C src
