# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 15:05:00 by ehugh-be          #+#    #+#              #
#    Updated: 2019/09/04 19:36:18 by ehugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libhtable.a

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = clang
LIBROOT = ../../
LIBHPATH = -I $(LIBROOT)includes/
STOREPATH = $(LIBROOT)lib/
CFLAGS = -Wall -Wextra -Werror
ifndef MAINLIB
	ADD_TO_MAIN_LIB =
else
	ADD_TO_MAIN_LIB = $(STOREPATH)$(MAINLIB)($(OBJ))
endif

all: $(STOREPATH)$(NAME)($(OBJ)) $(ADD_TO_MAIN_LIB)
	@cp $(STOREPATH)/liblist.a $(STOREPATH)/libstd.a $(STOREPATH)/libvec.a ./
	@ar x liblist.a
	@ar x libstd.a
	@ar x libvec.a
	@ar r $(NAME) *.o
	@rm *.o __.* liblist.a libstd.a libvec.a
	@mv $(NAME) $(STOREPATH)

.c.a:
	@$(CC) $(CFLAGS) $(LIBHPATH) -c $< -o $*.o
	@ar r $@ $*.o
	@rm $*.o

fclean: clean
	@/bin/rm -f $(STOREPATH)$(NAME)

clean:
	@/bin/rm -f $(OBJ)

re: fclean all