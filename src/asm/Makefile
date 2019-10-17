# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/10/17 10:41:01 by PhilippNox       ###   ########.fr        #
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

SRC= 	L00_lexer.o L01_lexer_init.o L10_lexer_helper.o \
		L02_lexer_preinit.o \
		L20_lexer_cmd.o main_test_lexer.o \
		L21_lexer_cmd_short.o L22_lexer_cmd_long.o \
		L30_lexer_token.o \
		L40_lexer_label.o L50_lexer_inst.o \
		get_op_data.o L11_lexer_debug_token.o \
		L60_lexer_parm.o

PATH_SRC= $(patsubst %.o, $(PATH_O)%.o, $(SRC))

all: $(FULL_NAME)
	
$(FULL_NAME): $(PATH_SRC)
	$(CC) $(FLAGS) -o $(FULL_NAME) $(PATH_O)*.o -L$(PATH_LIB_A) -lft -L$(PATH_LIB_A) -llist -I$(PATH_H) -I$(PATH_LIB_H) $(PATH_LIB_A)/liblist.a
	@echo "for_test run:"
	@echo "./build/asm ../../test_data/test_data_name/n10_g_name_one_line.s"

$(PATH_O)get_op_data.o: ../get_op_data.c
	$(CC) $(CFLAGS) ../get_op_data.c $(FLAG_PATH_OBJ)
$(PATH_O)main_test_lexer.o: main_test_lexer.c
	$(CC) $(CFLAGS) main_test_lexer.c $(FLAG_PATH_OBJ)
$(PATH_O)L00_lexer.o: L00_lexer.c
	$(CC) $(CFLAGS) L00_lexer.c $(FLAG_PATH_OBJ)
$(PATH_O)L01_lexer_init.o: L01_lexer_init.c
	$(CC) $(CFLAGS) L01_lexer_init.c $(FLAG_PATH_OBJ)
$(PATH_O)L02_lexer_preinit.o: L02_lexer_preinit.c
	$(CC) $(CFLAGS) L02_lexer_preinit.c $(FLAG_PATH_OBJ)
$(PATH_O)L10_lexer_helper.o: L10_lexer_helper.c
	$(CC) $(CFLAGS) L10_lexer_helper.c $(FLAG_PATH_OBJ)
$(PATH_O)L11_lexer_debug_token.o: L11_lexer_debug_token.c
	$(CC) $(CFLAGS) L11_lexer_debug_token.c $(FLAG_PATH_OBJ)
$(PATH_O)L20_lexer_cmd.o: L20_lexer_cmd.c
	$(CC) $(CFLAGS) L20_lexer_cmd.c $(FLAG_PATH_OBJ)
$(PATH_O)L21_lexer_cmd_short.o: L21_lexer_cmd_short.c
	$(CC) $(CFLAGS) L21_lexer_cmd_short.c $(FLAG_PATH_OBJ)
$(PATH_O)L22_lexer_cmd_long.o: L22_lexer_cmd_long.c
	$(CC) $(CFLAGS) L22_lexer_cmd_long.c $(FLAG_PATH_OBJ)
$(PATH_O)L30_lexer_token.o: L30_lexer_token.c
	$(CC) $(CFLAGS) L30_lexer_token.c $(FLAG_PATH_OBJ)
$(PATH_O)L40_lexer_label.o: L40_lexer_label.c
	$(CC) $(CFLAGS) L40_lexer_label.c $(FLAG_PATH_OBJ)
$(PATH_O)L50_lexer_inst.o: L50_lexer_inst.c
	$(CC) $(CFLAGS) L50_lexer_inst.c $(FLAG_PATH_OBJ)
$(PATH_O)L60_lexer_parm.o: L60_lexer_parm.c
	$(CC) $(CFLAGS) L60_lexer_parm.c $(FLAG_PATH_OBJ)


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