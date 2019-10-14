/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 22:15:59 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H

#include <libft.h>
#include "op.h"

#define MALLOC_ERROR_MSG "{Red}Error: \nMemory allocation failed{eof}\n"

#define MAX_OP_TIME 1000

typedef enum 	e_exit_codes
{
	SUCCESS,
	MALLOC_ERROR,
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
	int			*code;
	int			id;
}				t_chmp;

typedef struct	s_mngr
{
	t_list		*timeline[MAX_OP_TIME + 1];
	t_vector	*flags; //TODO make flags
	t_chmp		*chmps;
	t_vector	*cars;  //TODO chose storage structure for carriges
	char 		*arena;
	int			chmp_num;
	int 		cycle;
	int			live_num;
	int			cycles_to_die;
	int			num_checks;
}				t_mngr;

void			validate_input(t_mngr *mngr, int argc, char **argv);
void			game_main(t_mngr *mngr);
void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
void			init_arena(t_mngr *mngr);
/*
** ----------------------Working with timeline------------------------------- **
*/
void			tl_put(t_mngr *mngr, short time, t_car *car);

#endif //COREWAR_COREWAR_H
