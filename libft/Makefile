# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 15:05:00 by ehugh-be          #+#    #+#              #
#    Updated: 2019/10/14 19:00:58 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAINLIB = libft.a
OCL_NAME = libocl.a
SL_L_N = libstd.n libmtrx.n libvector.n libavl.n lib2list.n  libprintf.n #liblist.n #libhtable.n
SL_L_C = $(SL_L_N:.n=.clean)
SL_L_F = $(SL_L_N:.n=.fclean)
SL_L_R = $(SL_L_N:.n=.re)
STD_LIB_PATH = std_lib/
OCL_SRC = $(wildcard ft_ocl/*.c)
OCL_OBJ = $(OCL_SRC:.c=.o)
AFILES = libstd.a libavl.a liblist.a libmtrx.a libprintf.a libvec.a
AF_PATH = $(subst lib,lib/lib, $(AFILES))
CC = clang
LIBSPATH = -I ./includes
CFLAGS = -Wall -Wextra -Werror

export MAINLIB

.c.a:
	@$(CC) $(CFLAGS) $(LIBSPATH) -c $< -o $*.o
	@ar r $@ $*.o
	@rm $*.o

all: $(SL_L_N)
	@mkdir -p lib
#	ar r lib/$(MAINLIB) $(AF_PATH)

fclean: $(SL_L_F)
	@/bin/rm -f lib/$(MAINLIB)

clean: $(SL_L_C)

re: fclean all

lib%.n:
	@mkdir -p lib
	make -C $(STD_LIB_PATH)$(basename $@)

lib%.clean:
	@mkdir -p lib
	make -C $(STD_LIB_PATH)$(basename $@) clean

lib%.fclean:
	@mkdir -p lib
	make -C $(STD_LIB_PATH)$(basename $@) fclean

