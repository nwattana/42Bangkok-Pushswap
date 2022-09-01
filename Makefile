# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwattana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 03:36:49 by nwattana          #+#    #+#              #
#    Updated: 2022/09/02 04:24:14 by nwattana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC = clang
CFLAG = -Wall -Wextra -Werror
CLIB = -iquote ./printf/includes\
	   -iquote ./printf/libft

LIB = ./printf/libftprintf.a

RED=\033[31m
GREEN=\033[32m
MAGENTA=\033[1;35m
ENDC=\033[39m

all: greeting

greeting:
	@clear
	@printf "====================================================\n"
	@printf "====================================================\n"
	@printf "\t$(RED)HELLO!!$(ENDC) Welcome To $(MAGENTA)$(NAME)$(ENDC)\n"
	@printf "====================================================\n"
	@printf "====================================================\n"
	@git log --oneline --graph --all
	@printf "====================================================\n"

testlib:
	@printf "====================================================\n"
	@make -C ./printf
	@$(CC) $(CFLAG) $(CLIB) testlib.c $(LIB) -o out
	@printf "$(RED)=======================RESULT=======================$(ENDC)\n"
	@./out
	@printf "====================================================\n"
	@-rm out
