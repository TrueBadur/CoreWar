/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:06:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/15 23:30:07 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "corewar.h"
#define	ARG_CODE_SIZE (sizeof(char) / MAX_ARGS_NUMBER)
#define	ARG1(x) (x >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 1) & 3)
#define ARG2(x) (x >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 2) & 3)
#define ARG3(x) (x >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 3) & 3)
#define LIVE_VAL (OP_live << sizeof(char) & ARG1(DIR_CODE))
#define LD_VAL (OP_ld << sizeof(char) & ARG1(DIR_CODE) & ARG2(REG_CODE))
#define ST_VAL (OP_st << sizeof(char) & ARG1(REG_CODE) & ARG2(REG_CODE))
#define OP_TEST(val, op) (x & op == op)
typedef union	u_op
{
	short	full;
	char 	sep[2];
}				t_op;

short		check_op(t_op op)
{
	short ret;

	if (!(op.sep[0] >= OP_live && op.sep[0] <= OP_aff))
	{
		if (is_live(op, &ret) || is_ld(op, &ret) || is_st(op, &ret) ||
		is_add_sub(op, &ret) || is_and_or_xor(op, &ret) ||
		is_fork_zjmp(op, &ret) || is_ldi(op, &ret) || is_sti(op, &ret) ||
		is_aff(op, &ret))
			return (ret);
		else
			return (get_args_size());
	}
	else
		return (-1);
}

void handle_op(t_mngr *mngr, t_car *car)
{
	if ((car->byte_next_op = check_op(mngr->arena[car->pos])) > 0)
	{
		if (car->op_code == OP_live)
			op_live();
	}
}

void	proceed_cars(t_mngr *mngr, t_car *car)
{

}



void	make_one_turn(t_mngr *mngr)
{
	tl_car_iter(mngr, handle_op);
	tl_car_iter(mngr, proceed_cars);
	//for every car in cur time
	//	if op under car is valid and args for op is valid
	//			execute op
	//for every car in cur time
	//	move car to new pos
	//	read op and move car on timeline
}

