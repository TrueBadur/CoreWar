/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/30 14:37:38 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H

#include <libft.h>
#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#define MAX_OP_TIME 1000
#define FLAG_DUMP ((unsigned int)1 << (unsigned int)4)
#define FLAG_V ((unsigned int)1 << (unsigned int)5)
#define FLAG_S ((unsigned int)1 << (unsigned int)6)
#define ARG_REG_S 1

#define PLAYER_SHIFT 1
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define PU 5
#define DEF 6
#define BLOOD 7
#define BRUTAL 8
#define RIP 9
#define DOOM 10

#define IMG_NUM 4

typedef enum	e_operation_codes
{
	OP_live = 1,
	OP_ld,
	OP_st,
	OP_add,
	OP_sub,
	OP_and,
	OP_or,
	OP_xor,
	OP_zjmp,
	OP_ldi,
	OP_sti,
	OP_fork,
	OP_lld,
	OP_lldi,
	OP_lfork,
	OP_aff
}				t_eop;

typedef enum 	e_exit_codes
{
	SUCCESS,
	MALLOC_ERROR,
    FEW_ARGUMENTS,
    INVALID_N,
    TOO_MANY_CHMPS,
    FEW_BYTE,
    READ_ERROR,
    OPEN_ERROR,
    INVALID_EXEC_MAGIC,
    NO_ZERO_BYTE,
    INVALID_SIZE_BYTE_CHAMPION,
    INVALID_FILE_EXTENSION,
    INVALID_ARRAY_CHAMPION,
    INVALID_ARGUMENT_NAME,
    CALL_DUMP
}				t_eexcode;

typedef struct	s_stats
{
	unsigned int	death_wave;
	unsigned int	cars[MAX_PLAYERS + 1];
	unsigned int	dies[MAX_PLAYERS + 1];
	int				cycles_to_die;
	int				cycles_to_die_new;
	int 			cycle;
	int 			total;
	int 			total_die;
	void			(*images[IMG_NUM])(void);
}				t_stats;

typedef struct	s_register
{
	char 		reg[REG_SIZE];
}				t_reg;

typedef	struct	s_car
{
	t_reg 		regs[REG_NUMBER];
	size_t		id;
	int			live_cycle;
	int 		pos;
	short		byte_next_op;
	short		eval_in;
	char		carry;
	char		op_code;
	char        just_forked;
}				t_car;

typedef struct	s_chmp
{
	size_t 		size;
	char		*name;
	char 		*moto;
	char        *code;
	int			id;
}				t_chmp;

typedef struct	s_mngr
{
	t_list		*timeline[MAX_OP_TIME + 1]; //TODO replace with array of t_list
	t_chmp		*chmps[MAX_PLAYERS];
	t_vector	*cars;  //TODO chose storage structure for carriges
	t_vector	*dead_cars;
	unsigned char 		*arena;
	unsigned	flags; //TODO make flags
	int         dump_nbr;
	int			chmp_num;
	int 		cycle;
	int			live_num;
	int			cycles_to_die;
	int			cycles_delta;
	int			num_checks;
	int 		num_cars;
	int         winner;
	unsigned	next_id;
}				t_mngr;

void			validate_input(t_mngr *mngr, int argc, char **argv);
void			game_main(t_mngr *mngr);

void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
void			init_arena(t_mngr *mngr);
void		    parse_file(char *str, t_mngr *mngr, int nbr);
void			make_one_turn(t_mngr *mngr);
void			proceed_cars(t_mngr *mngr, short cur_time);
/*
** ----------------------Working with timeline------------------------------- **
*/
void tl_put(t_mngr *mngr, short time, t_list_node *lst, int addlast);
void			tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*));

/*
** -----------------------------Operations----------------------------------- **
*/

/*
** -----------------------------Statistic------------------------------------ **
*/
void 	add_dies_stats(int reg);
void 	add_cars_stats(int reg);
void	refresh_stats();
t_stats	*get_stats(void);
void	show_stats();
void	set_cycles_die(int to_set);
void	set_cycles_die_new(int to_set);
void	set_cycle(int to_set);
void	recalc_total();
void	show_nuke();
void	show_time_to_die();
void	init_visu();
void	show_skull_one();
void	show_skull_two();
void	show_skull_three();

#endif //COREWAR_COREWAR_H
