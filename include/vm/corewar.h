/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/15 21:43:35 by ehugh-be         ###   ########.fr       */
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

#define MALLOC_ERROR_MSG "{Red}Error: \nMemory allocation failed{eof}\n"

#define MAX_OP_TIME 1000
#define DUMP ((unsigned int)1 << (unsigned int)4)

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
    TOO_MANY_CHMPS
}				t_eexcode;

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
	t_list		*timeline[MAX_OP_TIME + 1];
	t_chmp		*chmps[MAX_PLAYERS];
	t_vector	*cars;  //TODO chose storage structure for carriges
	unsigned char 		*arena;
	unsigned	flags; //TODO make flags
	int			chmp_num;
	int 		cycle;
	int			live_num;
	int			cycles_to_die;
	int			num_checks;
	int 		num_cars;
}				t_mngr;

void			validate_input(t_mngr *mngr, int argc, char **argv);
void			game_main(t_mngr *mngr);
void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
void			init_arena(t_mngr *mngr);
void		    parse_file(char *str, t_mngr *mngr, int nbr);
void			make_one_turn(t_mngr *mngr);
/*
** ----------------------Working with timeline------------------------------- **
*/
void			tl_put(t_mngr *mngr, short time, t_car *car);
void			tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*));

/*
** -----------------------------Operations----------------------------------- **
*/


#endif //COREWAR_COREWAR_H
