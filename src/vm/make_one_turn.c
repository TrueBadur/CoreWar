/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                     +               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:06:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/06 18:38:08 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

#define BYTE_OP (unsigned char)(mngr->arena[car->pos])
#define BYTE_CODE (unsigned char)(mngr->arena[(car->pos + 1) % MEM_SIZE])

void	handle_op(t_mngr *mngr, t_car *car)
{
	short ret;
	t_t_op	op;

	op = (t_t_op){car->op_code, ARG1(BYTE_CODE), ARG2(BYTE_CODE), ARG3(BYTE_CODE)};
	if ((ret = check_op(&op)) > 0)
		get_op_func(op.op)(mngr, car, &op);
	if (ft_abs(ret) > 1 && mngr->flags & FLAG_V && car->op_code != OP_zjmp)
		print_addr(mngr, car->pos, FT_ABS(ret));
	car->pos = (car->pos + FT_ABS(ret)) % MEM_SIZE;
}

static void set_max_id(t_vector *vec, int id)
{
	if (vec->offset < 0)
		vec->offset = id > -vec->offset ? -id : vec->offset;
	else if (id < vec->offset)
		vec->offset *= -1;
	else
		vec->offset = id;
}

#define TL_TO_PUT (mngr->timeline[time_to_put])
void proceed_cars(t_mngr *mngr, short cur_time)
{
	t_car		**cars;
	char		op;
	short		time_to_put;
	int			i;

	i = -1;
	while (++i < mngr->timeline[cur_time]->len / sizeof(void*))
	{
		cars = (t_car**)mngr->timeline[cur_time]->data;
		if (cars[i]->eval_in != cur_time)
			continue ;
		op = (char)mngr->arena[cars[i]->pos];
		if (OP_live <= op && OP_aff >= op)
			time_to_put = (short)((cur_time + get_op_info(op)->num_of_ticks) %
					(MAX_OP_TIME + 1));
		else
			time_to_put = (short)((cur_time + 1) % (MAX_OP_TIME + 1));
		cars[i]->op_code = op;
		cars[i]->eval_in = time_to_put;
		tl_put(mngr, cars[i]->eval_in, cars[i]);
		set_max_id(mngr->timeline[time_to_put], cars[i]->id);
	}
	mngr->timeline[cur_time]->len = 0;
	mngr->timeline[cur_time]->offset = 0;
}

int		car_comp(void *a, void *b)
{
	return ((int)((*(t_car**)b)->id - (*(t_car**)a)->id));
}

void	make_one_turn(t_mngr *mngr)
{
	short	cur_time;

	cur_time = (short)(mngr->cycle % (MAX_OP_TIME + 1));
	if (!mngr->timeline[cur_time] || !mngr->timeline[cur_time]->len)
		return ;
	t_car **tmp = mngr->timeline[cur_time]->data;
	t_vector *tmp1 = mngr->timeline[cur_time];
	if ((int)mngr->timeline[cur_time]->offset < 0)
		mngr->timeline[cur_time] = vm_radixsort(mngr->timeline[cur_time], mngr->timeline[cur_time]->len /
			sizeof(void*), mngr);
	tl_car_iter(mngr, handle_op);
	proceed_cars(mngr, cur_time);
}

