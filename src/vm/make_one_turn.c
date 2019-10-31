/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:06:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/31 12:02:52 by ehugh-be         ###   ########.fr       */
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
		get_op_func(op.op)(mngr, car, &op);
	if (ret)
		print_addr(mngr, car->pos, FT_ABS(ret));
	car->pos = (car->pos + FT_ABS(ret)) % MEM_SIZE;
}

void proceed_cars(t_mngr *mngr, short cur_time)
{
	t_list_node *lst;
	t_car		*car;
	char		op;
	int			time_to_put;

	t_list *tmp = mngr->timeline[cur_time];
	while ((lst = ft_lsttake(mngr->timeline[cur_time])))
	{
		car = (t_car*)lst->content;
		op = (char)mngr->arena[car->pos];
		if (OP_live <= op && OP_aff >= op)
			time_to_put = cur_time + get_op_info(op)->num_of_ticks;
		else
			time_to_put = cur_time + 1;
		car->eval_in = (short) (time_to_put % (MAX_OP_TIME + 1));
        tl_put(mngr, car->eval_in, lst, 1);
	}
}

void	make_one_turn(t_mngr *mngr)
{
	short	cur_time;

	cur_time = (short)(mngr->cycle % (MAX_OP_TIME + 1));
	if (!mngr->timeline[cur_time] || !mngr->timeline[cur_time]->len)
		return ;
	tl_car_iter(mngr, handle_op);
	proceed_cars(mngr, cur_time);
}

