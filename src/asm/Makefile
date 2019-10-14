# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/10/14 18:22:33 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "\$(PATH_O)$x.o: $x.c\n\t\$(CC) \$(CFLAGS) $x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" | tr '\n' ' '
#

NAME=asm
CC=gcc
FLAGS= -Wall -Wextra -Werror -g
CFLAGS= -c $(FLAGS)

PATH_H=../../include/asm
PATH_B=./build/
PATH_O=./obj/
PATH_LIB=../../libft
PATH_LIB_H=$(PATH_LIB)/includes
PATH_LIB_A=$(PATH_LIB)/lib
#PATH_LIB=../../wgorold_libft
#PATH_LIB_H=$(PATH_LIB)
#PATH_LIB_A=$(PATH_LIB)/build
FULL_NAME=$(PATH_B)$(NAME)

FLAG_PATH_OBJ= -o $@ -I$(PATH_LIB_H) -I$(PATH_H)

SRC= 	lexer.o main_test_lexer.o

PATH_SRC= $(patsubst %.o, $(PATH_O)%.o, $(SRC))

all: $(FULL_NAME)
	
$(FULL_NAME): $(PATH_SRC)
	$(CC) $(FLAGS) -o $(FULL_NAME) $(PATH_O)*.o -L$(PATH_LIB_A) -lft -L$(PATH_LIB_A) -llist -I$(PATH_H) -I$(PATH_LIB_H) $(PATH_LIB_A)/liblist.a
	@echo "for_test run:"
	@echo "./build/asm ../../data/champs/zork.s"

$(PATH_O)lexer.o: lexer.c
	$(CC) $(CFLAGS) lexer.c $(FLAG_PATH_OBJ)
$(PATH_O)main_test_lexer.o: main_test_lexer.c
	$(CC) $(CFLAGS) main_test_lexer.c $(FLAG_PATH_OBJ)


mlibft:
	make -C $(PATH_LIB)

clean:
	find $(PATH_O) -type f -not -name '.gitkeep' -delete
	make clean -C $(PATH_LIB)

fclean: clean
	find $(PATH_B) -type f -not -name '.gitkeep' -delete
	rm -f $(NAME)
	make fclean -C $(PATH_LIB)

re: fclean all

rep: clean all