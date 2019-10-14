/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 20:58:04 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H

#include <libstd.h>
#include "t_list.h"
#include "t_vec.h"
#include "op.h"

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
	t_vector	timeline[MAX_OP_TIME + 1];
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

#endif //COREWAR_COREWAR_H
