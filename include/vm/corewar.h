/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/14 20:56:19 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

# include <libft.h>
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# define MAX_OP_TIME 1000
# define FLAG_DUMP ((unsigned int)1 << (unsigned int)4)
# define FLAG_V ((unsigned int)1 << (unsigned int)5)
# define FLAG_A ((unsigned int)1 << (unsigned int)6)
# define FLAG_S ((unsigned int)1 << (unsigned int)7)
# define ARG_REG_S 1
# define VEC_ST_S 8

typedef enum		e_operation_codes
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
}					t_eop;

typedef enum		e_exit_codes
{
	SUCCESS,
	MALLOC_ERROR,
	FEW_ARGUMENTS,
	INVALID_FLAG,
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
	CALL_DUMP,
	HELP
}					t_eexcode;

typedef struct		s_register
{
	char			reg[REG_SIZE];
}					t_reg;

typedef	struct		s_car
{
	t_reg			regs[REG_NUMBER];
	size_t			id;
	int				live_cycle;
	int				pos;
	short			eval_in;
	char			carry;
	char			op_code;
}					t_car;

typedef struct		s_chmp
{
	size_t			size;
	char			*name;
	char			*moto;
	unsigned char	*code;
	int				id;
}					t_chmp;

typedef struct		s_mngr
{
	t_vector		*timeline[MAX_OP_TIME + 1];
	t_chmp			*chmps[MAX_PLAYERS];
	t_vector		*cars;
	t_vector		*dead_cars;
	t_vector		*rxsort_out;
	unsigned char	*arena;
	unsigned		flags;
	int				dump_nbr;
	int				chmp_num;
	int				cycle;
	int				live_num;
	int				cycles_to_die;
	int				cycles_delta;
	int				num_checks;
	int				num_cars;
	int				winner;
	unsigned		next_id;
}					t_mngr;

void				validate_input(t_mngr *mngr, int argc, char **argv);
void				game_main(t_mngr *mngr);
void				safe_exit(t_mngr *mngr, t_eexcode exit_code,
					const char *err_arg);
void				init_arena(t_mngr *mngr);
void				parse_file(char *str, t_mngr *mngr, int nbr);
void				parse_dump(t_mngr *mngr, char **argv, int i);
void				parse_v(t_mngr *mngr, char **argv, int i);
void				parse_a(t_mngr *mngr, char **argv, int i);
void				parse_s(t_mngr *mngr, char **argv, int i);
void				make_one_turn(t_mngr *mngr);
void				proceed_car(t_mngr *mngr, t_car *car, short cur_time,
					int offset);
void				dump_arena(t_mngr *mngr);
void				check_cars(t_mngr *mngr);

void				tl_put(t_mngr *mngr, short time, t_car *car);
void				tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*,
					t_car*, short));
t_vector			*vm_radixsort(t_vector *vec, size_t size, t_mngr *mngr);
void				print_help(void);


#endif
