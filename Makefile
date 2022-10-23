# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwattana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 03:36:49 by nwattana          #+#    #+#              #
#    Updated: 2022/10/23 12:07:39 by nwattana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

NSRC= ./src/push_swap.c

ACT= ./src/act/action.c ./src/act/action2.c \
	 ./src/act/l_action.c ./src/act/action3.c
PROG= ./src/prog/program.c

DEB= ./src/prog/d_prog.c ./src/put_aint.c
CONT = ./src/content/content.c \
	   ./src/content/content2.c

INPUT=	./src/input/input.c ./src/input/input2.c
SORT = ./src/main_sort.c ./src/issort.c

SMALL= ./src/small/dosort_small.c \
		./src/small/dosort_small2.c \
	   	./src/small/small.c \
	   	./src/small/small2.c

MED = ./src/med/medium.c \
	  ./src/med/assign_ch.c\
	  ./src/med/ms_init.c\
	  ./src/med/chunk.c\
	  ./src/med/a_to_b.c\
	  ./src/med/move_top.c\
	  ./src/med/b_to_a.c\
	  ./src/sort_3.c

SRC=$(PROG)	$(INPUT) $(DEB) $(CONT) \
	$(ACT) $(SORT) $(SMALL) \
	$(MED) 

CC = clang
CFLAG = -Wall -Wextra -Werror
ILIB = -iquote ./printf/includes\
	   -iquote ./printf/libft\
	   -iquote ./includes

LIB = ./printf/libftprintf.a

RED=\033[31m
GREEN=\033[32m
MAGENTA=\033[1;35m
ENDC=\033[39m

all: $(NAME)

$(NAME): ps

ps: lib
	$(CC) $(CFLAG) $(ILIB) $(SRC) $(NSRC) $(LIB) -o $(NAME)

lib:
	make -C ./printf

clean:
	make -C ./printf clean

fclean: clean
	make -C ./printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all ps clean re fclean lib
