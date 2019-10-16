/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:06:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/16 14:03:30 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

void handle_op(t_mngr *mngr, t_car *car)
{
	short ret;

	if (!(op.sep[0] >= OP_live && op.sep[0] <= OP_aff))
	{
		if (is_live(op, &ret) || is_ld(op, &ret) || is_st(op, &ret) ||
			is_add_sub(op, &ret) || is_and_or_xor(op, &ret) ||
			is_fork_zjmp(op, &ret) || is_ldi(op, &ret) || is_sti(op, &ret) ||
			is_aff(op, &ret))
			;
		else
			ret = get_args_size();
	}
	else
		ret = 1;
	car->byte_next_op = ret;
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

