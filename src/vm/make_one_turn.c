/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:06:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/16 23:40:40 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

#define BYTE_OP (unsigned char)(mngr->arena[car->pos])
#define BYTE_CODE (unsigned char)(mngr->arena[car->pos + 1])

void	handle_op(t_mngr *mngr, t_car *car)
{
	short ret;
	t_t_op	op;

	op = (t_t_op){BYTE_OP, ARG1(BYTE_CODE), ARG2(BYTE_CODE), ARG3(BYTE_CODE)};
	if ((ret = check_op(&op)) > 0)
		get_op_func(op.op)(mngr, car);
	car->byte_next_op = FT_ABS(ret);
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

