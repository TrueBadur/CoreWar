/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:09:28 by blomo             #+#    #+#             */
/*   Updated: 2019/11/13 18:14:17 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

#define BYTE_CODE (unsigned char)(mngr->arena[(car->pos + 1) % MEM_SIZE])

void			handle_op(t_mngr *mngr, t_car *car, short cur_time)
{
	short		ret;
	t_t_op		op;

	op = (t_t_op){car->op_code, ARG1(BYTE_CODE), ARG2(BYTE_CODE),
	ARG3(BYTE_CODE)};
	if ((ret = check_op(&op)) > 0)
	{
		get_op_func(op.op)(mngr, car, &op);
	}
	if (ret != -1 && mngr->flags & FLAG_V && (car->op_code != OP_zjmp ||
	car->carry != 1))
		print_addr(mngr, car->pos, FT_ABS(ret));
	proceed_car(mngr, car, cur_time, ret);
}

static void		set_max_id(t_vector *vec, int id)
{
	if (vec->offset < 0)
		vec->offset = id > -vec->offset ? -id : vec->offset;
	else if (id < vec->offset)
		vec->offset *= -1;
	else
		vec->offset = id;
}

void			proceed_car(t_mngr *mngr, t_car *car, short cur_time,
		int offset)
{
	short		time_to_put;

	time_to_put = (short)((cur_time + 1) % (MAX_OP_TIME + 1));
	if (offset == -1)
	{
		car->op_code = (char)mngr->arena[car->pos];
		if (car->op_code <= OP_aff && car->op_code >= OP_live)
			time_to_put = (short)((cur_time +
				get_op_info(car->op_code)->num_of_ticks - 1) %
				(MAX_OP_TIME + 1));
		else
			car->pos = (car->pos + 1) % MEM_SIZE;
	}
	else
	{
		car->op_code = 0;
		car->pos = (car->pos + ft_abs(offset)) % MEM_SIZE;
	}
	car->eval_in = time_to_put;
	tl_put(mngr, time_to_put, car);
	set_max_id(mngr->timeline[time_to_put], car->id);
}

void			make_one_turn(t_mngr *mngr)
{
	short		cur_time;
	t_car		**tmp;
	t_vector	*tmp1;

	cur_time = (short)(mngr->cycle % (MAX_OP_TIME + 1));
	if (!mngr->timeline[cur_time] || !mngr->timeline[cur_time]->len)
		return ;
	tmp = mngr->timeline[cur_time]->data;
	tmp1 = mngr->timeline[cur_time];
	if ((int)mngr->timeline[cur_time]->offset < 0)
		mngr->timeline[cur_time] = vm_radixsort(mngr->timeline[cur_time],
		mngr->timeline[cur_time]->len / sizeof(void*), mngr);
	tl_car_iter(mngr, handle_op);
}
