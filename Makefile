# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwattana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 03:36:49 by nwattana          #+#    #+#              #
#    Updated: 2022/09/03 17:39:14 by nwattana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

NSRC= ./src/push_swap.c

PROG= ./src/prog/program.c
DEB= ./src/prog/d_prog.c
CONT = ./src/content.c
INPUT=./src/input.c ./src/input2.c
SRC=$(PROG)	$(INPUT) $(DEB) $(CONT)

CC = clang
CFLAG = -Wall -Wextra -Werror -g
ILIB = -iquote ./printf/includes\
	   -iquote ./printf/libft\
	   -iquote ./includes

LIB = ./printf/libftprintf.a

RED=\033[31m
GREEN=\033[32m
MAGENTA=\033[1;35m
ENDC=\033[39m

all: greeting

pushswap: lib
	$(CC) $(CFLAG) $(ILIB) $(SRC) $(NSRC) $(LIB) -o push_swap_test

maintest:
	@printf "$(RED)=======================MAINTEST=======================$(ENDC)\n"
	@make -C ./printf
	@$(CC) $(CFLAG) $(ILIB) main_test.c $(LIB) -o test_main

greeting: 
	@clear
	@printf "====================================================\n"
	@printf "====================================================\n"
	@printf "\t$(RED)HELLO!!$(ENDC) Welcome To $(MAGENTA)$(NAME)$(ENDC)\n"
	@printf "====================================================\n"
	@printf "====================================================\n"
	@git log --oneline --graph --all -n10
	@printf "====================================================\n"
	@printf "You are on\n" 
	@git branch

testlib: lib
	@printf "====================================================\n"
	@make -C ./printf
	@$(CC) $(CFLAG) $(CLIB) testlib.c $(LIB) -o test_lib
	@printf "$(RED)=======================RESULT=======================$(ENDC)\n"
	@./out
	@printf "====================================================\n"
	@-rm out

lib:
	make -C ./printf

.PHONY: all maintest greeting testlib
